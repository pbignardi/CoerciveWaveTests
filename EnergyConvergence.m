function error_table = EnergyConvergence(problem, t, varargin)
%Energy Convergence - compute convergence of the energy as h\rightarrow 0
% for the problem given, at time  t.
%   INPUT:
%   problem: struct of the problem to solve
%   t: (float) time at which energy should be computed
%   
%   KWARGS:
%   par_type: (string) specify form pars to use (see initializeForm.m)
%   BETA:   (float) value of \BETA
%   XI:     (float) value of \XI
%   NU:     (float) value of \NU
%   A:      (float) value of A_Q
%   A0:     (float) value of A_\OZ
%
%   OUTPUT:
%   error_table: table with energy-norm error and H col
%
options = struct('PAR_TYPE', 'opt', 'WRITE_TO_FILE', false, 'PLOT', true, ...
    'N', [2, 4, 8, 16, 32, 64, 128], 'BETA', 1, 'XI', 1, 'NU', 1, 'A', 1, ...
    'A0', 1);

optionNames = fieldnames(options);
for pair = reshape(varargin, 2, [])
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

% Set the formulation parameters
if strcmpi(options.PAR_TYPE, 'CUSTOM')
    form = initializeForm(problem, problem.Q, options.PAR_TYPE, varargin{:});
else
    form = initializeForm(problem, problem.Q, options.PAR_TYPE);
end

%% Display information
%TODO

%% Iterate for different number of elements
EnergyNormErrors = zeros(length(options.N), 1);
VprojErrors = zeros(length(options.N), 1);

i = 1;
for n = options.N
    nx = n; 
    nt = n;
    d = Discretization(nx, nt, problem.Q);
    mesh = CartesianMesh(d);
    [u, ~] = SolverWaves(problem, problem.Q, mesh, d, form);
    [~, ~, uVproj] = ProjectionBFS(problem, d);
    EnergyNormErrors(i) = ComputeEnergyNormError(u, t, mesh, d, problem);
    errors = ComputeErrors(uVproj, problem, mesh, d, 'absolute');
    VprojErrors(i) = errors.VnE;
    i = i + 1;
end

Hx = (problem.Q.xmax - problem.Q.xmin) ./ options.N.';
Ht = problem.Q.T ./ options.N.';
H = sqrt(Hx .^2 + Ht .^ 2);

%% Build table and write to file
error_table = table(H, Hx, Ht, EnergyNormErrors, VprojErrors);

if options.WRITE_TO_FILE
    filename = strcat('Results/ConvPlots/p', string(problem.pnum), '-', ...
        'ptype', upper(options.PAR_TYPE), '-', ...
        'etype', upper(options.ERR_TYPE), '-');
    filename = strcat(filename, '-energyConvTable.dat');
    writetable(error_table, filename);
    % Add comments to the file with parameters used
    fid = fopen(filename,'a');
    file_info = {'# --- Parameter summary ---', ...
        sprintf('# PROBLEM ID: %d', problem.pnum), ...
        sprintf('# TIME t: %f', t), ...
        sprintf('# N: %s', join(string(options.N),',')), ...
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
HPlot = H;
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
ylabel('absolute error');
title(sprintf('convergence of energy-norm error at t=%.2f', t));

loglog_plot(HPlot, EnergyNormErrors, '-d', linewidth, BLUE, markersize);
p_En = polyfit(log(HPlot(end-2:end)), log(EnergyNormErrors(end-2:end)), 1);
EnergyNormLegend = strcat('Energy-norm error - order: ', string(p_En(1)));
rates = diff(log(EnergyNormErrors))./diff(log(HPlot.'));
for k = length(EnergyNormErrors):-1:2
    text(HPlot(k)+0.1*HPlot(k), EnergyNormErrors(k), strcat('r=', ...
        sprintf('%.2f',rates(k-1))), ...
        Margin=10, FontSize=fs-2);
end
loglog_plot(HPlot, VprojErrors, '--', linewidth, BLUE, markersize-1);
BestApproxLegend = strcat('Best approximation error');


% create legend
legend(EnergyNormLegend, BestApproxLegend, ...
    "Location", "southeast");
end
end



function loglog_plot(x, y, line_style, linewidth, color, markersize)
    loglog(x, y, line_style, ...
        'LineWidth', linewidth, ...
        'Color', color, ...
        'MarkerFaceColor', color, ...
        'MarkerSize', markersize)
end