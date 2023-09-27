function [] = TestA_LS(p_num, N, varargin)
%TestA - Compute L2 errors of LS formulation for wide range of A,
% then saves plots.
%   INPUTS:
%       p_num:  Problem number (see WaveProblem.m)
%       N:      Number of sample per each parameter
%       M:      (Optional) Number of element in each direction (default 32)

addpath(genpath("local_stiffness"));

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
Q = p.Q;

%% Grid of the parameter $A$
As = logspace(-15, 3, N);

L2errors = zeros(N, 1);
Kconds = zeros(N, 1);

%% Iterate over A
parfor i = 1:N    
    % Discretise the domain
    nx = M; nt = M;
    d = Discretization(nx, nt, Q);
    % Build mesh
    mesh = CartesianMesh(d);
    
    % Solve problem
    [u, Kcond] = SolverLeastSquares(p, Q, mesh, d, As(i));

    % Compute errors
    errors = ComputeErrors(u, p, mesh, d, "relative");
    L2errors(i) = errors.L2E;
    Kconds(i) = Kcond;
end
 
%% L2 error plot
l2err_fig = figure;
loglog(As, L2errors, 'LineWidth', 2);
xlabel('$A$',Interpreter='latex');
ylabel('$L^2$ relative error',Interpreter='latex');
title("L2 error")
grid on

% Find the minimum error
best_error = min(L2errors(:));
i = find(L2errors==best_error);
xline(As(i), 'Color', 'r', 'LineWidth', 1);
textLabel = sprintf("Optimal A = %e", As(i));
text(As(i), L2errors(i)*1e4, textLabel, 'fontSize', 13, ...
    'VerticalAlignment', 'bottom');

%% Condition number plot
cond_fig = figure;
loglog(As, Kconds, 'LineWidth', 2);
xlabel('$A$', Interpreter='latex');
ylabel('Condition number', Interpreter='latex');
title("Condition number of the matrix");
grid on



%% Saving figures
root_dir = "Results/ParsTestFigures/";
base_filename = "testA-p" + string(p_num) + "-slvLS" + ...
    "-numEl" + M;
saveas(l2err_fig, root_dir + base_filename + "-l2err", 'epsc');
saveas(cond_fig, root_dir + base_filename + "-cond", 'epsc');

