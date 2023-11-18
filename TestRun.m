% Coercive wave equation numerical tests
% Paolo Bignardi 2022
clc
%clear
close all
addpath(genpath("local_stiffness"));
addpath(genpath("matlab2tikz"));

%% Define problem, discretization and mesh
% Create simple problem
problem = WaveProblem(1);
% Discretise the domain
nx = 128; nt = 128;
d = Discretization(nx, nt, problem.Q);
% Build mesh
mesh = CartesianMesh(d);

%% Custom form parameters
form = initializeForm(problem, Q, 'OPT');
form.NU = 1.0001;
%% Solve problem
u = SolverWaves(problem, Q, mesh, d, form);
[~, uproj, ~] = ProjectionBFS(problem, d);
%% Plot solution
[U, X, T] = OperatorEval(u, mesh, d, {linspace(0, 1, 5), linspace(0, 1,  5)}, 'u');
[Uproj, ~, ~] = OperatorEval(uproj, mesh, d, {linspace(0, 1, 5), linspace(0, 1, 5)}, 'u');

pcolor(X, T, U);
colorbar
shading flat; 
xlabel("X"); ylabel("T");

%% Compute errors
errors = ComputeErrors(u, problem, mesh, d, "relative");
errors.L2E
