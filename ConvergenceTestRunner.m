% Paolo Bignardi - July 2023
% Convergence tests for Section 7

% Run CFL and convergence tests for a given problem.

addpath(genpath('src'));

% define problem id
p_id = 2;
% number of elements in t direction for cfl
NtElms = 8;
% number of elements in x direction for cfl
NxElms = 2.^(1:11);
% number of elements for convergence test
nElms = 2.^(1:7);
% compute 'relative' or 'absolute' error
err_type = 'relative';
% save table to file
save_table = false;
% show plot
show_plot = true;
% save dir location
basedir = 'Results/ConvTables/';

% define problem
problem = WaveProblem(p_id);

%% Testing CFL condition
fprintf('** Test CFL condition\n');
fprintf('=>> SOLVER PARAMETERS\n');
fprintf('<strong>problem_id: %d</strong>\n', p_id);
fprintf('Nx: %s\n', join(string(NxElms), ','));
fprintf('Nt: %d\n', NtElms);
fprintf('\n');

% Testing CFL condition - with A_Q = 1e-2, A_\OZ = 1
form = FormParameters(problem, A = 1e-2, A0 = 1);
% Print info
fprintf('=>> FORMULATION PARAMETERS\n');
fprintf('<strong>A</strong>: %.2f\n', form.A);
fprintf('<strong>A0</strong>: %.2f\n', form.A0);
fprintf('Xi: %.2f\n', form.XI);
fprintf('Beta: %.2f\n', form.BETA);
fprintf('Nu: %.2f\n', form.NU);
fprintf('\n');
% do convergence table
cfl_table = Convergence(problem, form, NxElms, Nt=NtElms, ErrType=err_type);
% save to file
if save_table == true
    pstring = string(p_id);
    ntstring = string(NtElms);
    filename = sprintf('cfltable-p%d-Nt%d-Aopt.dat', pstring, ntstring);
    writetable(cfl_table, basedir + filename);
end
% show plot
if show_plot == true
    ShowCFLTestPlot(cfl_table, Form=form, Problem=problem);
end

% Testing CFL condition - with A_Q = 1, A_\OZ = 1
form = FormParameters(problem, A = 1, A0 = 1);
% Print info
fprintf('=>> FORMULATION PARAMETERS\n');
fprintf('<strong>A</strong>: %.2f\n', form.A);
fprintf('<strong>A0</strong>: %.2f\n', form.A0);
fprintf('Xi: %.2f\n', form.XI);
fprintf('Beta: %.2f\n', form.BETA);
fprintf('Nu: %.2f\n', form.NU);
fprintf('\n');
% do convergence table
cfl_table = Convergence(problem, form, NxElms, Nt=NtElms, ErrType=err_type);
% save to file
if save_table == true
    pstring = string(p_id);
    ntstring = string(NtElms);
    filename = sprintf('cfltable-p%d-Nt%d-Agen.dat', pstring, ntstring);
    writetable(cfl_table, basedir + filename);
end
% show plot
if show_plot == true
    ShowCFLTestPlot(cfl_table, Form=form, Problem=problem);
end

%% Full convergence tests
% Print info
fprintf('** Convergence test\n');
fprintf('=>> SOLVER PARAMETERS\n');
fprintf('<strong>problem_id: %d</strong>\n', p_id);
fprintf('Nx: %s\n', join(string(nElms), ','));
fprintf('Nt: %s\n', join(string(nElms), ','));
fprintf('\n');

% Convergence test - with A_Q = 1e-2, A_\OZ = 1
form = FormParameters(problem, A = 1e-2, A0 = 1);
% Print info
fprintf('=>> FORMULATION PARAMETERS\n');
fprintf('<strong>A</strong>: %.2f\n', form.A);
fprintf('<strong>A0</strong>: %.2f\n', form.A0);
fprintf('Xi: %.2f\n', form.XI);
fprintf('Beta: %.2f\n', form.BETA);
fprintf('Nu: %.2f\n', form.NU);
fprintf('\n');
% do convergence table
conv_table = Convergence(problem, form, nElms, ErrType=err_type);
% save to file
if save_table == true
    filename = sprintf('convtable-p%d-Aopt.dat', string(p_id));
    writetable(conv_table, basedir + filename);
end
% show plot
if show_plot == true
    ShowConvergencePlot(conv_table, Form=form, Problem=problem);
end

% Convergence test - with A_Q = 1, A_\OZ = 1
form = FormParameters(problem, A = 1, A0 = 1);
% Print info
fprintf('=>> FORMULATION PARAMETERS\n');
fprintf('<strong>A</strong>: %.2f\n', form.A);
fprintf('<strong>A0</strong>: %.2f\n', form.A0);
fprintf('Xi: %.2f\n', form.XI);
fprintf('Beta: %.2f\n', form.BETA);
fprintf('Nu: %.2f\n', form.NU);
fprintf('\n');
% do convergence table
conv_table = Convergence(problem, form, nElms, ErrType=err_type);
% save to file
if save_table == true
    filename = sprintf('convtable-p%d-Agen.dat', string(p_id));
    writetable(conv_table, basedir + filename);
end
% show plot
if show_plot == true
    ShowConvergencePlot(conv_table, Form=form, Problem=problem);
end
