function [] = TestA(p_num, N, varargin)
%TestA - Compute L2 errors for wide range of AQ and A0, then saves plots
%   INPUTS:
%       p_num:  Problem number (see WaveProblem.m)
%       N:      Number of sample per each parameter
%       M:      (Optional) Number of element in each direction (default 32)

set(groot,'defaultAxesTickLabelInterpreter','latex'); 
set(groot,'defaulttextinterpreter','latex');
set(groot,'defaultLegendInterpreter','latex');
set(0,'DefaultTextInterpreter','latex')
set(0,'DefaultLegendInterpreter','latex')

addpath(genpath("local_stiffness"));
SAVE_TO_FILE = true;

if ischar(p_num)
    p_num = str2double(p_num);
end
if ischar(N)
    N = str2double(N);
end

if ~isempty(varargin)
    M = varargin{1};
else
    M = 32;
end

%% Define problem, discretization and mesh
% Create simple problem
p = WaveProblem(p_num);
% Define domain
Q = p.Q;
% Define number of elements
nx = M; nt = M;
% Define discretisation
d = Discretization(nx, nt, Q);
% Build mesh
mesh = CartesianMesh(d);

%% Grid of the parameter $A$
AQs = logspace(-15, 2, N);
A0s = logspace(-9, 3, N);
AQ = AQs;
A0 = A0s;
%As = logspace(log10(0.0000000001), log10(1), 2);
L2errors = zeros(length(AQs), length(A0s));
Kconds = zeros(length(AQs), length(A0s));
%% Initiate progress bar
progress_head = "[Progress]: ";
fprintf(progress_head);
max_width_progress = 75;

%% Iterate over A

char_line_count = strlength(progress_head);
% Loop for AQ (fixed AQ on each row)
for i = 1:numel(AQs)
    % Loop for A0 (fixed A0 on each column)
    AQ_slice = AQs(i);
    parfor j = 1:numel(A0s)
        form = initializeForm(p, Q, 'custom', 'A', AQ_slice, 'A0', A0s(j));
        % Solve problem
        [u, Kcond] = SolverWaves( ...
            p, Q, mesh, d, form);

        % Compute errors
        errors = ComputeErrors(u, p, mesh, d, "relative");
        L2errors(i, j) = errors.L2E;
        Kconds(i, j) = Kcond;
    end
    to_disp = "..." + string(round(100*i/numel(AQs))) + "%%";
    char_line_count = char_line_count + strlength(to_disp) - 1;
    if char_line_count > max_width_progress
        fprintf("\n");
        char_line_count = strlength(progress_head);
        fprintf(repmat(' ', 1, char_line_count));
    end
    fprintf(to_disp);
end
fprintf(" -- Done\n");



[A0s, AQs] = meshgrid(A0s, AQs);
fs = 20;                                                       
l2err_fig = figure;
h = gca;
surf(A0s, AQs, L2errors);
set(h, 'xscale', 'log');
set(h, 'yscale', 'log');
set(h, 'zscale', 'log');
set(h,'ColorScale','log');
set(h, 'xlim', [min(A0) max(A0)]);
set(h, 'ylim', [min(AQ) max(AQ)]);
fontsize(fs, 'points');
xlabel('$A_{\Omega_0}$',Interpreter='latex');
ylabel('$A_Q$',Interpreter='latex');
clim([min(L2errors(:)) 1]);
c = colorbar;
set(c,'TickLabelInterpreter','latex');
view(2)
shading flat
colormap turbo
% title("L2 error")


cond_fig = figure;
h = gca;
surf(A0s, AQs, Kconds);
set(h, 'xscale', 'log');
set(h, 'yscale', 'log');
set(h, 'zscale', 'log');
set(h,'ColorScale','log');
set(h, 'xlim', [min(A0) max(A0)]);
set(h, 'ylim', [min(AQ) max(AQ)]);
fontsize(fs, 'points');
xlabel('$A_{\Omega_0}$',Interpreter='latex');
ylabel('$A_Q$',Interpreter='latex');
clim([min(Kconds(:)) max(Kconds(:))]);
c = colorbar;
set(c,'TickLabelInterpreter','latex');
view(2)
shading flat
colormap turbo
% title("Condition number of the matrix");

%% Find the minimum error
best_error = min(L2errors(:));
[i, j] = find(L2errors==best_error);

%% Plot the error fixing the best A0
A0_err_fig = figure;
loglog(AQ, L2errors(:, j),'LineWidth',2);
grid on
title("L2 error for best A0")
xlabel("$A_Q$", Interpreter='latex');
ylabel("$L^2(Q)$ error", Interpreter='latex');
% Mark the optimal value of AQ
xline(AQs(i, j), 'Color', 'r', 'LineWidth', 1);
textLabel = sprintf("Optimal AQ = %e", AQs(i, j));
text(AQs(i, j), L2errors(i, j)*1e2, textLabel, 'fontSize', 13, ...
    'VerticalAlignment', 'bottom');
AQ = AQ.';
L2err = L2errors(:, j);
best_A0_table = table(AQ, L2err);

%% Plot the error fixing the best AQ
AQ_err_fig = figure;
loglog(A0, L2errors(i, :),'LineWidth',2);
grid on 
title("L2 error for best AQ")
xlabel("$A_0$", Interpreter='latex');
ylabel("$L^2(Q)$ error", Interpreter='latex');
% % Mark the optimal value of A0
% xline(A0s(i, j), 'Color', 'r', 'LineWidth', 1);
% textLabel = sprintf("Optimal A0 = %f", A0s(i, j));
% text(A0s(i, j), L2errors(i, j), textLabel, 'fontSize', 13, ...
%     'VerticalAlignment', 'bottom');
A0 = A0.';
L2err = L2errors(i, :).';
best_AQ_table = table(A0, L2err);

%% Saving figures
if SAVE_TO_FILE
root_dir = "Results/ParsTestFigures/";
base_filename = "testA-p" + string(p_num) + "-" + ...
    "-numEl" + M;
exportgraphics(l2err_fig, root_dir + base_filename + "-l2err.png", 'Resolution', 300);
exportgraphics(cond_fig, root_dir + base_filename + "-cond.png", 'Resolution', 300);
writetable(best_AQ_table, root_dir + base_filename + "bestAQerrslice.dat");
writetable(best_A0_table, root_dir + base_filename + "bestA0errslice.dat");
end

