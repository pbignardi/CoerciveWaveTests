clc
close all
clear
addpath(genpath("local_stiffness"));

%% Define problem, discretization and mesh
p_num = 7;
% Create simple problem
p = WaveProblem(p_num);
% Define domain
Q = Domain(-1, 1, 1);

%% Grid of the parameter $A$
N = 10;
As = logspace(-15, log10(1), N);
%As = logspace(log10(0.0000000001), log10(1), 2);
L2errors = zeros(length(As), 1);
Kconds = zeros(length(As), 1);

%% Iterate over A
i = 1;
for A = As
    % Define number of elements
    nx = 256; nt = 256;
    % Define discretisation
    d = Discretization(nx, nt, Q);
    % Build mesh
    mesh = CartesianMesh(d);
    
    form = struct();
    form.A = A;
    form.nu = 2;
    form.xi = 1;
    form.beta = 20;

    % Solve problem
    [u, Kcond] = SolverLeastSquares(p, Q, mesh, d, A);
    %omega0_mean = ComputeMean(u, 0, mesh, d);
    %u = MeanShift(u, omega0_mean, mesh);
    
    % Compute errors
    errors = ComputeErrors(u, p, mesh, d, "absolute");
    L2errors(i) = errors.L2E;
    Kconds(i) = Kcond;
    i = i + 1;
end
A = As.';
results = table(A, L2errors, Kconds);
writetable(results, ...
    strcat("test_results/p",string(p_num), "LS_par_A_N", string(N),".dat"));
