% Coercive wave equation numerical tests
% Paolo Bignardi 2022
clc
clear
close all
addpath(genpath("local_stiffness"));

%% Define problem, discretization and mesh
% Create simple problem
p = WaveProblem(3);
% Define domain
Q = Domain(-1, 1, 1);
% Discretise the domain
nx = 8; nt = 8;
d = Discretization(nx, nt, Q);
% Build mesh
mesh = CartesianMesh(d);

%% Custom form parameters
form = struct();
form.A  = 1;
form.nu = 2;
form.xi = 1;
form.beta = 10;

%% Solve problem
u = SolverWaves(p, Q, mesh, d, form);

%% Plot solution
[U, X, T] = SolutionEval(u, mesh, d);
surf(X, T, U);
xlabel("X"); ylabel("T");

%% Compute errors
errors = ComputeErrors(u, p, mesh, d);
errors.L2E

%% Animate
[U, X, T] = SolutionEval(u, mesh, d, linspace(0,1,10).');
animate(X, T, U);
