% Coercive wave equation numerical tests
% Paolo Bignardi 2022
clc
%clear
close all
addpath(genpath("local_stiffness"));

%% Define problem, discretization and mesh
% Create simple problem
p = WaveProblem(4, 'k', 50);
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
[U, X, T] = SolutionGridEval(u, mesh, d, linspace(p.Q.xmin, p.Q.xmax, 201), ...
    linspace(0, p.Q.T, 201));
[Uproj, ~, ~] = SolutionGridEval(uproj, mesh, d, linspace(p.Q.xmin, p.Q.xmax, 201),...
    linspace(0, p.Q.T, 201));
% pcolor(X, T, (p.u(X, T) - U));
pcolor(X, T, U);
colorbar
% surf(X, T, U);
shading flat; 
xlabel("X"); ylabel("T");

%% Compute errors
errors = ComputeErrors(u, p, mesh, d, "relative");
errors.L2E

%% Animate
%[U, X, T] = SolutionEval(u, mesh, d, linspace(0,1,10).');
%animate(X, T, U);