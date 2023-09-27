% Coercive wave equation numerical tests
% Paolo Bignardi 2022
% Energy conservation
clc
clear
close all
addpath(genpath("local_stiffness"));

%% Define problem, discretization and mesh
% Create simple problem
p = WaveProblem(3);
Q = p.Q;
% Discretise the domain
nx = 64; nt = 64;
d = Discretization(nx, nt, Q);
% Build mesh
mesh = CartesianMesh(d);

%% Custom form parameters
form = initializeForm(p, Q, 'OPT');
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

%% Compute energy at each time step
[u_energy, T] = ComputeEnergy(u, mesh, d, p);

figure
u_ex_energy = zeros(size(u_energy));
for i = 1:numel(T)
    u_ex_energy(i) = ComputeExactEnergy(T(i), p);
end
plot(T, u_energy - u_ex_energy);

%% Compute energy error
