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

%% Print info
% TODO
%% Solve problem
u = SolverWaves(p, Q, mesh, d, form);
[~, uproj, ~] = ProjectionBFS(p, d);

%% Compute energy at each time step
Ts = linspace(0, 1, 400);
Eu = ComputeEnergy(u, Ts, mesh, d, p);

figure(1)
Eu_ex = zeros(size(Eu));
for i = 1:numel(Ts)
    Eu_ex(i) = ComputeExactEnergy(Ts(i), p);
end
plot(Ts, Eu);
hold on
plot(Ts, Eu_ex);
hold off
title('Energy computed using time-slices');

figure(2)
error = abs(Eu - Eu_ex);
err_type = 'Absolute';
if all(Eu_ex ~= 0)
    error = error ./ Eu_ex;
    err_type = 'Relative';
end
plot(Ts, error);
title([err_type, ' error of energy using time-slices']);

%% Compute energy using time quadrature points as evaluation
figure(3)
[Eu_qp, Ts_qp] = ComputeEnergyOnGrid(u, mesh, d, p);
Eu_ex_qp = zeros(size(Eu_qp));
for i = 1:numel(Eu_ex_qp)
    Eu_ex_qp(i) = ComputeExactEnergy(Ts_qp(i), p);
end
plot(Ts_qp, Eu_qp);
hold on
plot(Ts_qp, Eu_ex_qp);
hold off
title('Energy evaluated at time quadrature points');

figure(4)
error = abs(Eu_qp - Eu_ex_qp);
err_type = 'Absolute';
if all(Eu_ex_qp ~= 0)
    error = error ./ Eu_ex_qp;
    err_type = 'Relative';
end
plot(Ts_qp, error);
title([err_type, ' error of energy using time quadrature points']);


