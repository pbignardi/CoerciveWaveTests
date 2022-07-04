% Coercive wave equation numerical tests
% Paolo Bignardi 2022
clear
close all
addpath(genpath("local_stiffness"));

%% Define problem, discretization and mesh
% Create simple problem
p = WaveProblem(2);
% Define domain
Q = Domain(-1, 1, 1);
% Discretise the domain
nx = 10; nt = 3;
d = Discretization(nx, nt, Q);
% Build mesh
mesh = CartesianMesh(d);

%% Solve problem
u = SolverWaves(p, Q, mesh, d);

%% Plot solution
[U, X, T] = SolutionEval(u, mesh, d);
surf(X, T, U);
xlabel("X"); ylabel("T");