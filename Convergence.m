function [error_table, conds_table] = Convergence(pstruct, varargin)
%Convergence - compute convergence plot for the specified problem
%   INPUT:
%   pstruct:  Struct of the problem to solve
%
%   KWARGS: 
%   verbose: (bool) print log of problem solved
%   test_cfl: (bool) test cfl condition or not
%   nt:     (int) use when test_cfl is true and pick number of time elms
%   plot:   (bool) show plot
%   write_to_file: (bool) write table to appropriately named file
%   err_type: (string/char vect) pick between absolute and relative error
%   n:      (int[]) number of elements in the space components
%   qo_const: (bool) add the theoretical quasiopt constant in table
%   par_type: (string) specify form pars to use (see initializeForm.m)
%   BETA:   (float) value of \BETA
%   XI:     (float) value of \XI
%   NU:     (float) value of \NU
%   A:      (float) value of A_Q
%   A0:     (float) value of A_\OZ
%
%   OUTPUT:
%   error_table:    table with L2, H1, V errors and projections, and H col.
%   conds_table:    table with condition number of Galerkin matrix, and H.

%% Set options
% create default option struct
options = struct('PAR_TYPE', 'opt', 'TEST_CFL', false, 'WRITE_TO_FILE', false, ...
    'VERBOSE', true, 'PLOT', true, 'ERR_TYPE', 'relative', ...
    'H1SEMINORM', true, 'N', [2, 4, 8, 16, 32, 64, 128], 'NT', 8, ...
    'QO_CONST', false, 'BETA', 1, 'XI', 1, 'NU', 1, 'A', 1, 'A0', 1); % not really set

optionNames = fieldnames(options);
for pair = reshape(varargin,2,[])
    pName = upper(pair{1});
    if any(strcmpi(pName, optionNames))
        options.(pName) = pair{2};
    else
        error('%s is not a recognized parameter name', pName);
    end
end

%% Initialisation
if ~isempty(gcp("nocreate"))
    addpath(genpath('local_stiffness'));
end
PROJ_PLOT = true;
ERRS = {'l2', 'h1', 'cond', 'V'};
%% Define problem, discretization and mesh
% Create simple problem
Q = pstruct.Q;

% Set the formulation parameters
if strcmpi(options.PAR_TYPE, 'CUSTOM')
    form = initializeForm(pstruct, Q, options.PAR_TYPE, varargin{:});
else
    form = initializeForm(pstruct, Q, options.PAR_TYPE);
end

%% Display informations
if options.VERBOSE
    fprintf('\n### 1+1D CONVERGENCE TESTS ###\n'); 
    fprintf(['BVP ID:\t%d\n' ...
        '---- domain ----\n' ...
        'xmin:\t%.2e,\txmax:\t%.2e,\nT:\t%.2e\n' ...
        '---- problem ----\n' ...
        'c:\t%.2e,' ...
        '\ttheta:\t%.2e\n'], pstruct.pnum, Q.xmin, Q.xmax, Q.T, pstruct.c, pstruct.theta);
    fprintf([ '---- parameters ----\n' ...
        'A_Q:\t%.2e,\tA_0:\t%.2e\n' ...
        'beta:\t%.2e,\txi:\t%.2e\n' ...
        'nu:\t%.2e\n' ...
        '---- QO constant ----\n'], form.A, form.A0, form.BETA, form.XI, form.NU);
    fprintf('Theoretical quasi-optimality constant: %.2e\n', QuasiOptConstant(pstruct, form));
end
%% Iterate for different number of elements
L2errors = zeros(length(options.N), 1);
H1errors = zeros(length(options.N), 1);
Verrors = zeros(length(options.N), 1);
SUPerrors = zeros(length(options.N), 1);
Kconds = zeros(length(options.N), 1);

QOconstEst = ones(length(options.N), 1) * QuasiOptConstant(pstruct, form);

L2projErrors = zeros(length(options.N), 1);
H1projErrors = zeros(length(options.N), 1);
VprojErrors = zeros(length(options.N), 1);

i = 1;
for n = options.N 
    % Discretise the domain
    nx = n;
    if options.TEST_CFL
        nt = options.NT;
    else
        nt = n;
    end
    d = Discretization(nx, nt, Q);
    % Build mesh
    mesh = CartesianMesh(d);

    % Solve problem
    [u, Kcond] = SolverWaves(pstruct, Q, mesh, d, form);

    % Compute projection of solution
    [uL2proj, uH1proj, uVproj] = ProjectionBFS(pstruct, d);
    
    % Compute errors of solution
    errors = ComputeErrors(u, pstruct, mesh, d, options.ERR_TYPE);
    L2errors(i) = errors.L2E;
    if options.H1SEMINORM
        H1errors(i) = errors.H1SE;
    else
        H1errors(i) = errors.H1E;
    end
    Verrors(i) = errors.VnE;
    SUPerrors(i) = errors.SUPE;
    Kconds(i) = Kcond;
    % Compute error of L2 projection
    errors = ComputeErrors(uL2proj, pstruct, mesh, d, options.ERR_TYPE);
    L2projErrors(i) = errors.L2E;
    % Compute error of H1 projection
    errors = ComputeErrors(uH1proj, pstruct, mesh, d, options.ERR_TYPE);
    if options.H1SEMINORM
        H1projErrors(i) = errors.H1SE;
    else
        H1projErrors(i) = errors.H1E;
    end
    % Compute error of V-norm projection
    errors = ComputeErrors(uVproj, pstruct, mesh, d, options.ERR_TYPE);
    VprojErrors(i) = errors.VnE;

    i = i + 1;
end

Hx = (Q.xmax - Q.xmin) ./ options.N.';
if options.TEST_CFL
    Ht = Q.T ./ options.NT * ones(1, numel(options.N)).';
else
    Ht = Q.T ./ options.N.';
end
H = sqrt(Hx .^ 2 + Ht .^ 2);

%% Compute orders of convergence orders
L2order = H.^4*L2errors(end)/(H(end))^4;
H1order = H.^3*H1errors(end)/(H(end))^3;
Vorder = H.^2*Verrors(end)/(H(end))^2;

%% Build table and write to file
error_table = table(H, Hx, Ht, L2errors, H1errors, Verrors, ...
    L2projErrors, H1projErrors, VprojErrors, ...
    L2order, H1order, Vorder);
if options.QO_CONST
    error_table.QOconstEst = QOconstEst;
end

if options.WRITE_TO_FILE
    filename = strcat('Results/ConvPlots/p', string(pstruct.pnum), '-', ...
        'ptype', upper(options.PAR_TYPE), '-', ...
        'etype', upper(options.ERR_TYPE), '-');
    if options.TEST_CFL 
        filename = strcat(filename, ...
            'testcfl', '-', ...
            'nt', string(options.NT), '-');
    end
    filename = strcat(filename, '-convTable.dat');
    writetable(error_table, filename);
    % Add comments to the file with parameters used
    fid = fopen(filename,'a');
    file_info = {'# --- Parameter summary ---', ...
        sprintf('# PROBLEM ID: %d', pstruct.pnum), ...
        sprintf('# TEST_CFL: %s', string(options.TEST_CFL)), ...
        sprintf('# NT: %d', options.NT), ...
        sprintf('# N: %s', join(string(options.N),',')), ...
        sprintf('# ERR_TYPE: %s', options.ERR_TYPE), ...
        sprintf('# PAR_TYPE: %s', options.PAR_TYPE), ...
        sprintf('# BETA: %f', options.BETA), ...
        sprintf('# XI: %f', options.XI), ...
        sprintf('# NU: %f', options.NU), ...
        sprintf('# A: %f', options.A), ...
        sprintf('# A0: %f', options.A0)};
    fprintf(fid, string(join(file_info, '\n')));
    fclose(fid);
end

%% Convergence plot
% Plot settings
linewidth = 2;
legend_cols = 1;
markersize = 9;
BLUE    = '#0072BD';
RED     = '#D95319';
YELLOW  = '#EDB120';
GREEN   = '#77AC30';
PURPLE  = '#7E2F8E';


if options.PLOT
    if options.TEST_CFL
        HPlot = Ht ./ Hx;
    else
        HPlot = H;
    end
% Create figure and set properties
figure
conv_ax = gca;
fs = 18;
fontsize(fs, 'points');
hold on, grid on
set(conv_ax, 'XScale', 'log');
set(conv_ax, 'YScale', 'log');
set(gcf, 'Position', [1,1, 960, 720]);
axis padded
xlabel('h');
ylabel(sprintf('%s error', options.ERR_TYPE));

lgd_entries = {}; 
for err = ERRS
    if strcmpi(err, 'l2')
        loglog_plot(HPlot, L2errors, '-d', linewidth, BLUE, markersize);
        p_l2 = polyfit(log(HPlot(end-2:end)), log(L2errors(end-2:end)), 1);
        lgd_entries{end + 1} = strcat('L2 error - order: ', string(p_l2(1)));
        rates = diff(log(L2errors))./diff(log(HPlot.'));
        for k = length(L2errors):-1:2
            text(HPlot(k)+0.1*HPlot(k), L2errors(k), strcat('r=', ...
                sprintf('%.2f',rates(k-1))), ...
                Margin=10, FontSize=fs-2);
        end
        % Projection plot
        if PROJ_PLOT
            loglog_plot(HPlot, L2projErrors, '--', linewidth, BLUE, markersize-1);
            lgd_entries{end + 1} = strcat('L2 projection');
        end
    elseif strcmpi(err, 'h1')
        loglog_plot(HPlot, H1errors, '-s', linewidth, RED, markersize);
        p_h1 = polyfit(log(HPlot(end-2:end)), log(H1errors(end-2:end)), 1);
        lgd_entries{end + 1} = strcat('H1 error - order: ', string(p_h1(1)));
        rates = diff(log(H1errors))./diff(log(HPlot.'));
        for k = length(H1errors):-1:2
            text(HPlot(k)+0.1*HPlot(k), H1errors(k), strcat('r=', ...
                sprintf('%.2f',rates(k-1))), ...
                Margin=10, FontSize=fs-2);
        end
        % Projection plot
        if PROJ_PLOT
            loglog_plot(HPlot, H1projErrors, '--', linewidth, RED, markersize-1);
            lgd_entries{end + 1} = strcat('H1 projection');
        end
    elseif strcmpi(err, 'linf')
        loglog_plot(HPlot, SUPerrors, '-o', linewidth, YELLOW, markersize);
        p_sup = polyfit(log(HPlot(end-2:end)), log(SUPerrors(end-2:end)), 1);
        lgd_entries{end + 1} = strcat('Linf error - order: ', string(p_sup(1)));
        rates = diff(log(SUPerrors))./diff(log(HPlot.'));
        for k = length(SUPerrors):-1:2
            text(HPlot(k)+0.1*HPlot(k), SUPerrors(k), strcat('r=', ...
                sprintf('%.2f',rates(k-1))), ...
                Margin=10, FontSize=fs-2);
        end
        hold on, grid on
    elseif strcmpi(err, 'V')
        loglog_plot(HPlot, Verrors, '-^', linewidth, GREEN, markersize);
        p_gr = polyfit(log(HPlot(end-2:end)), log(Verrors(end-2:end)), 1);
        lgd_entries{end + 1} = strcat('V-norm error - order: ', string(p_gr(1)));
        rates = diff(log(Verrors))./diff(log(HPlot.'));
        for k = length(Verrors):-1:2
            text(HPlot(k)+0.1*HPlot(k), Verrors(k), strcat('r=', ...
                sprintf('%.2f',rates(k-1))), ...
                Margin=10, FontSize=fs-2);
        end
        % Projection plot
        if PROJ_PLOT
            loglog_plot(HPlot, VprojErrors, '--', linewidth, GREEN, markersize-1);
            lgd_entries{end + 1} = strcat('V projection');
        end
    end
end


legend(lgd_entries, ...
    'Location', 'southeast', 'NumColumns', legend_cols);

hold off
end
%% Condition table
% compute rates
p_cond = polyfit(log(H(end-1:end)), - log(Kconds(end-1:end)),1);
rates = diff(log(Kconds))./diff(log(H.'));

% create condition number table
conds_table = table(H, Hx, Ht, Kconds);
if options.WRITE_TO_FILE
    filename = strcat('Results/ConvPlots/p', string(pstruct.pnum), '-', ...
        'ptype', upper(options.PAR_TYPE), '-', ...
        'etype', upper(options.ERR_TYPE), '-');
    if options.TEST_CFL 
        filename = strcat(filename, ...
            'testcfl', '-', ...
            'nt', string(options.NT), '-');
    end
    filename = strcat(filename, '-conditionTable.dat');
    writetable(conds_table, filename);
    % Add comments to the file with parameters used
    fid = fopen(filename,'a');
    file_info = '# --- Parameter summary ---\n';
    file_info = strcat(file_info, ...
        sprintf('# PROBLEM ID: %d\n', pstruct.pnum), ...
        sprintf('# TEST_CFL: %s\n', string(options.TEST_CFL)), ...
        sprintf('# NT: %d\n', options.NT), ...
        sprintf('# N: %s\n', join(string(options.N),',')), ...
        sprintf('# PAR_TYPE: %s\n', options.PAR_TYPE), ...
        sprintf('# ERR_TYPE: %s\n', options.ERR_TYPE), ...
        sprintf('# BETA: %f\n', options.BETA), ...
        sprintf('# XI: %f\n', options.XI), ...
        sprintf('# NU: %f\n', options.NU), ...
        sprintf('# A: %f\n', options.A), ...
        sprintf('# A0: %f\n', options.A0));
    fprintf(fid, file_info);
    fclose(fid);
end


function loglog_plot(x, y, line_style, linewidth, color, markersize)
    loglog(x, y, line_style, ...
        'LineWidth', linewidth, ...
        'Color', color, ...
        'MarkerFaceColor', color, ...
        'MarkerSize', markersize)
end
end




