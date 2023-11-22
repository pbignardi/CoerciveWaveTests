function [error_table, conds_table] = Convergence(problem, options)
%Convergence - compute convergence plot for the specified problem
%   INPUT:
%   problem:  Struct of the problem to solve
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

arguments
    problem
    options.ParType { mustBeText } = 'opt'
    options.WriteFile logical = false
    options.Verbose logical = true
    options.ShowPlot logical = true
    options.ErrorType { mustBeText } = 'relative'
    options.QOConst logical = false
    options.N integer = 2.^(1:7)
    options.NT integer 
    % Formulation parameters
    options.A double
    options.A0 double
    options.BETA double
    options.NU double
    options.XI double
end

if isfield(options, 'NT')
    options.TestCfl = true
end

%% Initialisation
PROJ_ShowPlot = true;
ERRS = {'l2', 'h1', 'cond', 'V'};

%% Define problem, discretization and mesh
% Create simple problem
Q = problem.Q;

% Set the formulation parameters
opts = namedargs2cell(options);
form = FormParameters(problem, opts{:});

%% Display informations
% TODO: change output to something readable
if options.Verbose
    fprintf('\n### 1+1D CONVERGENCE TESTS ###\n'); 
    fprintf(['BVP ID:\t%d\n' ...
        '---- domain ----\n' ...
        'xmin:\t%.2e,\txmax:\t%.2e,\nT:\t%.2e\n' ...
        '---- problem ----\n' ...
        'c:\t%.2e,' ...
        '\ttheta:\t%.2e\n'], problem.pnum, Q.xmin, Q.xmax, Q.T, problem.c, problem.theta);
    fprintf([ '---- parameters ----\n' ...
        'A_Q:\t%.2e,\tA_0:\t%.2e\n' ...
        'beta:\t%.2e,\txi:\t%.2e\n' ...
        'nu:\t%.2e\n' ...
        '---- QO constant ----\n'], form.A, form.A0, form.BETA, form.XI, form.NU);
    fprintf('Theoretical quasi-optimality constant: %.2e\n', QuasiOptConstant(problem, form));
end
%% Iterate for different number of elements
L2errors = zeros(length(options.N), 1);
H1errors = zeros(length(options.N), 1);
Verrors = zeros(length(options.N), 1);
SUPerrors = zeros(length(options.N), 1);
Kconds = zeros(length(options.N), 1);

QOconstEst = ones(length(options.N), 1) * QuasiOptConstant(problem, form);

L2projErrors = zeros(length(options.N), 1);
H1projErrors = zeros(length(options.N), 1);
VprojErrors = zeros(length(options.N), 1);

i = 1;
for n = options.N 
    % Discretise the domain
    nx = n;
    if options.TestCfl
        nt = options.NT;
    else
        nt = n;
    end
    d = Discretization(nx, nt, Q);
    % Build mesh
    mesh = CartesianMesh(d);

    % Solve problem
    [u, Kcond] = SolverWaves(problem, Q, mesh, d, form);

    % Compute projection of solution
    [uL2proj, uH1proj, uVproj] = ProjectionBFS(problem, d);
    
    % Compute errors of solution
    errors = ComputeErrors(u, problem, mesh, d, options.ERR_TYPE);
    L2errors(i) = errors.L2E;
    H1errors(i) = errors.H1E;
    Verrors(i) = errors.VnE;

    Kconds(i) = Kcond;
    % Compute error of L2 projection
    errors = ComputeErrors(uL2proj, problem, mesh, d, options.ERR_TYPE);
    L2projErrors(i) = errors.L2E;
    % Compute error of H1 projection
    errors = ComputeErrors(uH1proj, problem, mesh, d, options.ERR_TYPE);
    H1projErrors(i) = errors.H1E;

    % Compute error of V-norm projection
    errors = ComputeErrors(uVproj, problem, mesh, d, options.ERR_TYPE);
    VprojErrors(i) = errors.VnE;

    i = i + 1;
end

Hx = (Q.xmax - Q.xmin) ./ options.N.';
if options.TestCfl
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
if options.QOConst
    error_table.QOconstEst = QOconstEst;
end

if options.WriteFile
    filename = strcat('Results/ConvPlots/p', string(problem.pnum), '-', ...
        'ptype', upper(options.ParType), '-', ...
        'etype', upper(options.ERR_TYPE), '-');
    if options.TestCfl 
        filename = strcat(filename, ...
            'testcfl', '-', ...
            'nt', string(options.NT), '-');
    end
    filename = strcat(filename, '-convTable.dat');
    writetable(error_table, filename);
    % Add comments to the file with parameters used
    fid = fopen(filename,'a');
    file_info = {'# --- Parameter summary ---', ...
        sprintf('# PROBLEM ID: %d', problem.pnum), ...
        sprintf('# TestCfl: %s', string(options.TestCfl)), ...
        sprintf('# NT: %d', options.NT), ...
        sprintf('# N: %s', join(string(options.N),',')), ...
        sprintf('# ERR_TYPE: %s', options.ERR_TYPE), ...
        sprintf('# ParType: %s', options.ParType), ...
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


if options.ShowPlot
    if options.TestCfl
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
        if PROJ_ShowPlot
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
        if PROJ_ShowPlot
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
        if PROJ_ShowPlot
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
if options.WriteFile
    filename = strcat('Results/ConvPlots/p', string(problem.pnum), '-', ...
        'ptype', upper(options.ParType), '-', ...
        'etype', upper(options.ERR_TYPE), '-');
    if options.TestCfl 
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
        sprintf('# PROBLEM ID: %d\n', problem.pnum), ...
        sprintf('# TestCfl: %s\n', string(options.TestCfl)), ...
        sprintf('# NT: %d\n', options.NT), ...
        sprintf('# N: %s\n', join(string(options.N),',')), ...
        sprintf('# ParType: %s\n', options.ParType), ...
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




