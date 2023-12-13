% Paolo Bignardi - April 2023
%TestA - Compute L2 and H1 errors for a range of AQ and A0 and saves plots
% Can be run in parallel or not; can also specify the number of elements to
% solve the problem.

% Problem to solve
p_num = 1;
% min order of magnitude for AQ search space
logAQmin = -15;  
% max order of magnitude for AQ search space
logAQmax = 2; 
% min order of magnitude for A0 search space
logA0min = -7; 
% max order of magnitude for A0 search space
logA0max = 3; 
% number of nodes in AQ search space
nAQ = 10; 
% number of nodes in A0 search space
nA0 = 10; 

% number of elements to use to solve the problem
nElms = 32;
% compute parallel
parallel_solve = false;

% figure size
figure_width = 920;
figure_height = 720;
% output figures font size
font_size = 20;                                                       
% resolution of output figures
output_dpi = 450;
% set verbose flag for called functions
verbose = true;
% save to file
save_file = false;
% output directory
basedir = 'Results/ParsTestFigures/';
% check if savedir exists, else create it
if ~isfolder(basedir) && save_file; mkdir(basedir); end

%% Display informations
fprintf('Test of parameters <strong>AQ</strong> and <strong>A0</strong>\n');

fprintf('=>> SEARCH SPACE\n');
fprintf('logAQmin: %d\n', logAQmin);
fprintf('logAQmax: %d\n', logAQmax);
fprintf('logA0min: %d\n', logA0min);
fprintf('logA0max: %d\n', logA0max);
fprintf('nAQ: %d\n', nAQ);
fprintf('nA0: %d\n', nA0);
fprintf('\n');

fprintf('=>> SOLVER PARAMETERS\n');
fprintf('problem_id: %d\n', p_num);
fprintf('Nt: %d\n', nElms);
fprintf('Nx: %d\n', nElms);
fprintf('\n');

fprintf('=>> OPTIONS\n');
fprintf('parallel solve: %s\n', parallel_solve);
fprintf('figure width: %d\n', figure_width);
fprintf('figure height: %d\n', figure_height);
fprintf('font_size: %d\n', font_size);
fprintf('output_dpi: %d\n', output_dpi);
fprintf('verbose: %s\n', verbose);
fprintf('save_file: %s\n', save_file);
fprintf('\n');

addpath(genpath("src"));

%% Define problem, discretization and mesh
% Create simple problem
p = WaveProblem(p_num);
% Define domain
Q = p.Q;
% Define number of elements
nx = nElms; nt = nElms;
% Define discretisation
d = Discretization(nx, nt, Q);
% Build mesh
mesh = CartesianMesh(d);

%% Grid of the parameter $A$
AQs = logspace(logAQmin, logAQmax, nAQ);
A0s = logspace(logA0min, logA0max, nA0);
AQ = AQs;
A0 = A0s;

%% Initialize errors
L2errors = zeros(nAQ, nA0);
H1errors = zeros(nAQ, nA0);
Kconds = zeros(nAQ, nA0);

%% Iterate over A
statusbar = waitbar(0, 'Computing...');
% Loop for AQ (fixed AQ on each row)
for i = 1:nAQ
    % Loop for A0 (fixed A0 on each column)
    AQ_slice = AQs(i);
    if parallel_solve == true
    parfor j = 1:nA0
        form = FormParameters(p, ParType='custom', A=AQ_slice, A0=A0s(j));
        % Solve problem
        [u, Kcond] = SolverWaves(p, mesh, d, form);
        Kconds(i, j) = Kcond;

        % Compute errors
        errors = ComputeErrors(u, p, mesh, d, 'relative');
        L2errors(i, j) = errors.L2E;
        H1errors(i, j) = errors.H1E;        
    end
    else
        for j = 1:numel(A0s)
        form = FormParameters(p, ParType='custom', A=AQ_slice, A0=A0s(j));
        % Solve problem
        [u, Kcond] = SolverWaves(p, mesh, d, form);
        Kconds(i, j) = Kcond;

        % Compute errors
        errors = ComputeErrors(u, p, mesh, d, 'relative');
        L2errors(i, j) = errors.L2E;
        H1errors(i, j) = errors.H1E;
        end
    end
    progress = i / nAQ;
    waitbar(progress, statusbar);
end
waitbar(1, statusbar, 'Done!');
close(statusbar);

%% Plot the result
[A0s, AQs] = meshgrid(A0, AQ);
l2err_fig = figure('Name','L2 error');
h = gca;
surf(A0s, AQs, L2errors);
set(h, 'xscale', 'log');
set(h, 'yscale', 'log');
set(h, 'zscale', 'log');
set(h,'ColorScale','log');
set(h, 'xlim', [min(A0) max(A0)]);
set(h, 'ylim', [min(AQ) max(AQ)]);
fontsize(font_size, 'points');
xticks(10.^(logA0min:2:logA0max));
yticks(10.^(logAQmin:2:logAQmax));
xlabel('$A_{\Omega_0}$',Interpreter='latex');
ylabel('$A_Q$',Interpreter='latex');
clim([min(L2errors(:)) 1]);
c = colorbar;
set(c,'TickLabelInterpreter','latex');
view(2)
shading flat
colormap turbo
% title("L2 error")

h1err_fig = figure('Name','H1 error');
h = gca;
surf(A0s, AQs, H1errors);
set(h, 'xscale', 'log');
set(h, 'yscale', 'log');
set(h, 'zscale', 'log');
set(h,'ColorScale','log');
set(h, 'xlim', [min(A0) max(A0)]);
set(h, 'ylim', [min(AQ) max(AQ)]);
fontsize(font_size, 'points');
xlabel('$A_{\Omega_0}$',Interpreter='latex');
ylabel('$A_Q$',Interpreter='latex');
clim([min(H1errors(:)) 1]);
c = colorbar;
set(c,'TickLabelInterpreter','latex');
view(2)
shading flat
colormap turbo
% title("L2 error")

cond_fig = figure('Name', 'Matix condition number');
h = gca;
surf(A0s, AQs, Kconds);
set(h, 'xscale', 'log');
set(h, 'yscale', 'log');
set(h, 'zscale', 'log');
set(h,'ColorScale','log');
set(h, 'xlim', [min(A0) max(A0)]);
set(h, 'ylim', [min(AQ) max(AQ)]);
fontsize(font_size, 'points');
xlabel('$A_{\Omega_0}$',Interpreter='latex');
ylabel('$A_Q$',Interpreter='latex');
clim([min(Kconds(:)) max(Kconds(:))]);
c = colorbar;
set(c,'TickLabelInterpreter','latex');
view(2)
shading flat
colormap turbo
% title("Condition number of the matrix");

hold off
%% Find the minimum error
best_error = min(L2errors(:));
[i, j] = find(L2errors==best_error);

%% Plot the error fixing the best A0
figure
loglog(AQ, L2errors(:, j),'LineWidth',2);
grid on
title('L2 error for best A0')
xlabel('$A_Q$', Interpreter='latex');
ylabel('$L^2(Q)$ error', Interpreter='latex');
% Mark the optimal value of AQ
xline(AQs(i, j), 'Color', 'r', 'LineWidth', 1);
textLabel = sprintf("Optimal AQ = %e", AQs(i, j));
text(AQs(i, j), L2errors(i, j)*1e2, textLabel, 'fontSize', 13, ...
    'VerticalAlignment', 'bottom');
L2err = L2errors(:, j);

% create table for A0 error
best_A0_table = table;
best_A0_table.AQ = AQ.';
best_AQ_table.L2err = L2err;

%% Saving figures and tables
if save_file
    basename = sprintf('%stestA-p%d-numEl%d', basedir, pnum, nElms);
    l2err_name = [basename, '-l2err.png'];
    h1err_name = [basename, '-h1err.png'];
    cond_name = [basename, '-cond.png'];
    bestAQ_name = [basename, '-bestAQerrslice.dat'];
    bestA0_name = [basename, '-bestA0errslice.dat'];

    exportgraphics(l2err_fig, l2err_name, 'Resolution', output_dpi);
    exportgraphics(h1err_fig, h1err_name, 'Resolution', output_dpi);
    exportgraphics(cond_fig, cond_name, 'Resolution', output_dpi);
    writetable(best_AQ_table, bestAQ_name);
    writetable(best_A0_table, bestA0_name);
end

