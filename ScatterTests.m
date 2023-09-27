% Coercive wave equation numerical tests
% Paolo Bignardi 2022
clc
%clear
close all
addpath(genpath("local_stiffness"));

%% Define problem, discretization and mesh
% Create simple problem
p = WaveProblem(6);
% Define domain
Q = Domain(1, 3, 4);
% Discretise the domain

nx = 100; nt = 150;
d = Discretization(nx, nt, Q);
% Build mesh
mesh = CartesianMesh(d);

%% Custom form parameters
form = struct();
form.A  = 1;
form.NU = 2;
form.XI = 1;
form.BETA = 20;

%% Solve problem
u = SolverScatter(p, Q, mesh, d);

%% Plot solution
[U, X, T] = SolutionEval(u, mesh, d);
pcolor(X, T, U);
colorbar
%surf(X, T, U);
shading flat; 
xlabel("X"); ylabel("T");

%% Compute errors
errors = ComputeErrors(u, p, mesh, d, "relative");
errors.L2E

%% Animate
%[U, X, T] = SolutionEval(u, mesh, d, linspace(0,1,10).');
%animate(X, T, U);
