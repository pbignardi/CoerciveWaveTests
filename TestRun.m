% Coercive wave equation numerical tests
% Paolo Bignardi 2022
clc
clear
close all
addpath(genpath('src'));

%% Define problem, discretization and mesh
% Create simple problem
problem = WaveProblem(1);
% Discretise the domain
nx = 128; nt = 128;
d = Discretization(nx, nt, problem.Q);
% Build mesh
mesh = CartesianMesh(d);

%% Custom form parameters
form = FormParameters(problem);
form.NU = 1.0001;
%% Solve problem
u = SolverWaves(problem, mesh, d, form);
%% Plot solution
xq_eval = {linspace(0, 1, 5), linspace(0, 1,  5)}
[U, X, T] = OperatorEval(u, mesh, d, xq_eval, 'u');

pcolor(X, T, U);
colorbar
shading flat; 
xlabel("X"); ylabel("T");

%% Compute errors
errors = ComputeErrors(u, problem, mesh, d, "relative");
disp(errors.L2E)
