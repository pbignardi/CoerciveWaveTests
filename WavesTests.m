% Coercive wave equation numerical tests
% Paolo Bignardi 2022
clear all
close all
%% Define problem, discretization and mesh
% Create simple problem
p = WaveProblem();
% Define domain
Q = Domain(0, 1, 1);
% Discretise the domain
nx = 3; nt = 2;
d = Discretization(nx, nt, Q);
% Build mesh
mesh = CartesianMesh(d);

%% Solve problem
u = SolverWaves(p, Q, mesh, d);

%% Plot solution
[U, X, T] = SolutionEval(u, mesh, d);
surf(X, T, U);