% Paolo Bignardi - August 2023
% Energy conservation and convergence

clc
clear
close all

%% Initialization
addpath(genpath('src'));
% define problem
pnum = 2;
% number of elements
nElms = 16;
% compute 'relative' or 'absolute' error
err_type = 'relative';
% save table to file
save_table = false;
% show plot
show_plot = true;
% number of elements for convergence
nElConv = 2.^(1:8);

% set font size for plot
font_size = 20;
% base dir location
basedir = 'Results/Energy/';

% Define problem, disc and mesh
problem = WaveProblem(pnum);
disc = Discretization(nElms, nElms, problem.Q);
% Build mesh
mesh = CartesianMesh(disc);

% Custom form parameters
form = FormParameters(problem);

% Print info
fprintf('** Error conservation test\n');
fprintf('=>> SOLVER PARAMETERS\n');
fprintf('problem_id: %d\n', pnum);
fprintf('Nt: %d\n', nElms);
fprintf('Nx: %d\n', nElms);
fprintf('err_type: %s\n', err_type);
fprintf('\n');

fprintf('=>> FORMULATION PARAMETERS\n');
fprintf('A: %.2f\n', form.A);
fprintf('A0: %.2f\n', form.A0);
fprintf('Xi: %.2f\n', form.XI);
fprintf('Beta: %.2f\n', form.BETA);
fprintf('Nu: %.2f\n', form.NU);
fprintf('\n');

fprintf('=>> OPTIONS\n');
fprintf('font_size: %d\n', font_size);
fprintf('show_plot: %s\n', string(show_plot));
fprintf('save table: %s\n', string(save_table));


%% Solve problem
u = SolverWaves(problem, mesh, disc, form);
[~, uproj, ~] = ProjectionBFS(problem, disc);

%% Compute energy at each time step
t = linspace(0, 1, 6*128).';
energy_table = ComputeEnergy(u, t, mesh, disc, problem, ErrType=err_type);

% show plot
if show_plot == true
    % plot energies
    figure
    hold on
    plot(t, energy_table.UhEnergy, '-b', LineWidth=1);
    plot(t, energy_table.UEnergy, '-r', LineWidth=1);
    hold off
    title('Energy of discrete and exact solution');
    xlabel('$t$');
    ylabel('Energy');
    fontsize(font_size, 'points'); legend('Energy of $u_h$', 'Energy of $u$',...
        Interpreter='latex');
    grid on

    % plot error of the energy
    figure
    semilogy(t, energy_table.NumericalEnergyError, '-k', LineWidth=1);
    title(sprintf('Error (%s) of the numerical energy', err_type));
    xlabel('$t$', Interpreter='latex');
    ylabel('Error of energy', Interpreter='latex');
    fontsize(font_size, 'points');
    legend('Error of the numerical energy');
    grid on
end

if save_table == true
    filename = sprintf('EnergyTable-p%d-N%d.dat', string(pnum), string(nElms));
    writetable(energy_table, basedir + filename);
end

%% Energy convergence 
% Print info
fprintf('** Energy convergence test');
fprintf('=>> SOLVER PARAMETERS\n');
fprintf('problem_id: %d\n', pnum);
fprintf('Nx: %s\n', join(string(nElConv), ','));
fprintf('Nt: %s\n', join(string(nElConv), ','));
fprintf('err_type: %s\n', err_type);
fprintf('\n');

% Compute energy convergence using EnergyConvergence
conv_table = EnergyConvergence(problem, form,nElConv, ErrType=err_type);
% save to file
if save_table == true
    filename = sprintf('EnergyConvTable-p%d.dat', string(pnum));
    writetable(conv_table, basedir + filename);
end
% show plot if required
if show_plot == true
    dashed = [4];
    fig_title = sprintf('Energy convergence - problem %d', pnum);
    fig_subtitle = '';
    legend_text = {'$sup_t E(t; u-u_h)$', '$sup_t |E(t;u)-E(t;u_h)|$', ...
        'V-norm best approximation error'};
    LogLogPlotter(conv_table, DashedIds=[4], Title=fig_title, ShowRates=true,...
        Subtitle=fig_subtitle, xLabel='h', LegendText=legend_text);
end
