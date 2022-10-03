% Coercive wave equation numerical tests
% Paolo Bignardi 2022
clc
%clear
close all
addpath(genpath("local_stiffness"));

%% Define problem, discretization and mesh
% Create simple problem
p = WaveProblem(7);
% Define domain
Q = Domain(-1, 1, 1);
% Discretise the domain
nx = 80; nt = 128;
d = Discretization(nx, nt, Q);
% Build mesh
mesh = CartesianMesh(d);

%% Solve problem
u = SolverLeastSquares(p, Q, mesh, d);
omega0_mean = ComputeMean(u, 0, mesh, d);
u = MeanShift(u, omega0_mean, mesh);

%% Plot solution
[U, X, T] = SolutionEval(u, mesh, d);
pcolor(X, T, U);
%surf(X, T, U);
shading flat;
xlabel("X"); ylabel("T");

%% Compute errors
errors = ComputeErrors(u, p, mesh, d, "relative");
errors.L2E

%% Animate
[U, X, T] = SolutionEval(u, mesh, d, linspace(0,1,10).');
%animate(X, T, U);
