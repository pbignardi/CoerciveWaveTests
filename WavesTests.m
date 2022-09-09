% Coercive wave equation numerical tests
% Paolo Bignardi 2022
clc
clear
close all
addpath(genpath("local_stiffness"));

%% Define problem, discretization and mesh
% Create simple problem
p = WaveProblem(7);
% Define domain
Q = Domain(-1, 1, 1);
% Discretise the domain
nx = 64; nt = 64;
d = Discretization(nx, nt, Q);
% Build mesh
mesh = CartesianMesh(d);

%% Custom form parameters
form = struct();

form.A       = 1;
form.nu      = 2;
form.xi      = 1;
form.beta    = form.xi / (form.nu - 1) * min([Q.L/(p.c*Q.T) + 1, ...
                Q.L/(p.c*Q.T) * (Q.delta * p.theta + (Q.delta * p.theta)^(-1))]);

C = min(form.A/Q.T^2, form.xi * Q.delta / 4);

%% Solve problem
u = SolverWaves(p, Q, mesh, d);

%% Plot solution
[U, X, T] = SolutionEval(u, mesh, d);
pcolor(X, T, U);
shading flat;
xlabel("X"); ylabel("T");

%% Compute errors
errors = ComputeErrors(u, p, mesh, d, "relative");
errors.L2E

%% Animate
[U, X, T] = SolutionEval(u, mesh, d, linspace(0,1,10).');
%animate(X, T, U);
