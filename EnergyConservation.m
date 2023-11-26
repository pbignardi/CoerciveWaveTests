% Coercive wave equation numerical tests
% Paolo Bignardi 2022
% Energy conservation
clc
clear
close all

% define problem
pnum = 3;
% number of elements
nElms = 16;
% save plot to file
save_plot = false;
% show plot
show_plot = false;

%% Define problem, discretization and mesh
problem = WaveProblem(pnum);
Q = problem.Q;
discretization = Discretization(nElms, nElms, problem.Q);
% Build mesh
mesh = CartesianMesh(discretization);

%% Custom form parameters
form = initializeForm(problem, Q, 'OPT');

%% Print info
% TODO
%% Solve problem
u = SolverWaves(problem, Q, mesh, discretization, form);
[~, uproj, ~] = ProjectionBFS(problem, discretization);

%% Compute energy at each time step
Ts = linspace(0, 1, 6*128).';
[disc_sol_energy, exact_energy, ~] = ComputeEnergy(u, 
if show_plot
    figure(1)
    plot(Ts, Eu);
    hold on
    plot(Ts, Eu_ex);
    hold off
    title('Energy computed using time-slices');
end

figure(2)
error = abs(Eu - Eu_ex);
err_type = 'Absolute';
if all(Eu_ex ~= 0)
    error = error ./ Eu_ex;
    err_type = 'Relative';
end

energy_ts_table = table(Ts, Eu, Eu_ex, error);

if WRITE_TO_FILE
    writetable(energy_ts_table, 'Results/Energy/EnergyTableTS-p' + string(pnum) + '-N' + string(nx) + '.dat');
end

semilogy(Ts, error);
title([err_type, ' error of energy using time-slices']);
end
%% Compute energy using time quadrature points as evaluation
if QUADPOINTS
[Eu_qp, Ts_qp] = ComputeEnergyOnGrid(u, mesh, d, p);
Eu_ex_qp = zeros(size(Eu_qp));
for i = 1:numel(Eu_ex_qp)
    Eu_ex_qp(i) = ComputeExactEnergy(Ts_qp(i), p);
end

if PLOTS
figure(3)
plot(Ts_qp, Eu_qp);
hold on
plot(Ts_qp, Eu_ex_qp);
hold off
title('Energy evaluated at time quadrature points');
end

figure(4)
error = abs(Eu_qp - Eu_ex_qp);
err_type = 'Absolute';
if all(Eu_ex_qp ~= 0)
    error = error ./ Eu_ex_qp;
    err_type = 'Relative';
end

energy_qp_table = table(Ts_qp, Eu_qp, Eu_ex_qp, error);

if WRITE_TO_FILE
    writetable(energy_qp_table, 'Results/Energy/EnergyTableQP-p' + string(pnum) + '-N' + string(nx) + '.dat');
end


semilogy(Ts_qp, error);
title([err_type, ' error of energy using time quadrature points']);
end

