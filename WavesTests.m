% Coercive wave equation numerical tests
% Paolo Bignardi 2022
clc
%clear
close all
addpath(genpath("local_stiffness"));
global poisson;
poisson = 1;
%% Define problem, discretization and mesh
% Create simple problem
p = WaveProblem(0);
% Define domain
Q = Domain(-1, 1, 1);
% Discretise the domain
nx = 10; nt = 10;
d = Discretization(nx, nt, Q);
% Build mesh
mesh = CartesianMesh(d);

%% Custom form parameters
form = struct();
form.A  = 1;
form.nu = 2;
form.xi = 1;
form.beta = 20;

%% Solve problem
u = SolverWaves(p, Q, mesh, d);
%omega0_mean = ComputeMean(u, 0, mesh, d);
%u = MeanShift(u, omega0_mean, mesh);

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
