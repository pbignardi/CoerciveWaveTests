% Coercive wave equation numerical tests
% Paolo Bignardi 2022
clc
%clear
close all
addpath(genpath("local_stiffness"));

%% Define problem, discretization and mesh
% Create simple problem
p = WaveProblem(3, 'k', 50);
% Define domain
Q = p.Q;
% Discretise the domain
nx = 64; nt = 64;
d = Discretization(nx, nt, Q);
% Build mesh
mesh = CartesianMesh(d);

%% Custom form parameters
form = initializeForm(p, Q, 'GEN');
%% Solve problem
u = SolverWaves(p, Q, mesh, d, form);
[~, uproj, ~] = ProjectionBFS(p, d);
%% Plot solution
[U, X, T] = OperatorEval(u, mesh, d, {linspace(0, 1, 5), linspace(0, 1,  5)}, 'u');
[Uproj, ~, ~] = OperatorEval(uproj, mesh, d, {linspace(0, 1, 5), linspace(0, 1, 5)}, 'u');

pcolor(X, T, U);
colorbar
shading flat; 
xlabel("X"); ylabel("T");

%% Compute errors
errors = ComputeErrors(u, p, mesh, d, "relative");
errors.L2E

%% Animate
%[U, X, T] = SolutionEval(u, mesh, d, linspace(0,1,10).');
%animate(X, T, U);
