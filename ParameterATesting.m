clc
close all
clear
addpath(genpath("local_stiffness"));

%% Define problem, discretization and mesh
% Create simple problem
p = WaveProblem(7);
% Define domain
Q = Domain(-1, 1, 1);

%% Grid of the parameter $A$
As = logspace(log10(0.00000001), log10(1), 100);
L2errors = zeros(length(As), 1);

%% Iterate over A
i = 1;
for A = As
    % Define number of elements
    nx = 128; nt = 128;
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
    L2errors(i) = Kcond;
    i = i + 1;
end

loglog(As, L2errors);
