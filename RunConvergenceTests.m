% Paolo Bignardi June 2023
% Compute convergence plot for different problems and different parameter
% values
function RunConvergenceTests
%% INITIAL SETUP
root = 'Results/ConvPlots/';
optimal_pars = [1e-2, 1e4];

%% Solving problem 1 - Homogeneous boundary
pnum = 1;
% Optimal parameters
% - compute error table and condition number table
[err_table, cond_table] = Convergence(pnum, optimal_pars);
% - write to file
err_filename = sprintf('%sp%d-err-table-opt.dat', root, pnum);
cond_filename = sprintf('%sp%d-cond-table-opt.dat', root, pnum);
fprintf('[i] Saving error table to: %s\n', err_filename);
fprintf('[i] Saving condition number table to: %s\n', cond_filename);
writetable(err_table, err_filename);
writetable(cond_table, cond_filename);

% Non-optimal parameters
% - compute error table and condition number table
[err_table, cond_table] = Convergence(pnum);
% - write to file
err_filename = sprintf('%sp%d-err-table-std.dat', root, pnum);
cond_filename = sprintf('%sp%d-cond-table-std.dat', root, pnum);
fprintf('[i] Saving error table to: %s\n', err_filename);
fprintf('[i] Saving condition number table to: %s\n', cond_filename);
writetable(err_table, err_filename);
writetable(cond_table, cond_filename);

%% Solving problem 3 - Smooth bouncing wave
pnum = 3;
% Optimal parameters
% - compute error table and condition number table
[err_table, cond_table] = Convergence(pnum, optimal_pars);
% - write to file
err_filename = sprintf('%sp%d-err-table-opt.dat', root, pnum);
cond_filename = sprintf('%sp%d-cond-table-opt.dat', root, pnum);
fprintf('[i] Saving error table to: %s\n', err_filename);
fprintf('[i] Saving condition number table to: %s\n', cond_filename);
writetable(err_table, err_filename);
writetable(cond_table, cond_filename);

% Non-optimal parameters
% - compute error table and condition number table
[err_table, cond_table] = Convergence(pnum);
% - write to file
err_filename = sprintf('%sp%d-err-table-std.dat', root, pnum);
cond_filename = sprintf('%sp%d-cond-table-std.dat', root, pnum);
fprintf('[i] Saving error table to: %s\n', err_filename);
fprintf('[i] Saving condition number table to: %s\n', cond_filename);
writetable(err_table, err_filename);
writetable(cond_table, cond_filename);


%% Solving problem 6 - Minimal regularity wave
pnum = 6;
% Optimal parameters
% - compute error table and condition number table
[err_table, cond_table] = Convergence(pnum, optimal_pars);
% - write to file
err_filename = sprintf('%sp%d-err-table-opt.dat', root, pnum);
cond_filename = sprintf('%sp%d-cond-table-opt.dat', root, pnum);
fprintf('[i] Saving error table to: %s\n', err_filename);
fprintf('[i] Saving condition number table to: %s\n', cond_filename);
writetable(err_table, err_filename);
writetable(cond_table, cond_filename);

% Non-optimal parameters
% - compute error table and condition number table
[err_table, cond_table] = Convergence(pnum);
% - write to file
err_filename = sprintf('%sp%d-err-table-std.dat', root, pnum);
cond_filename = sprintf('%sp%d-cond-table-std.dat', root, pnum);
fprintf('[i] Saving error table to: %s\n', err_filename);
fprintf('[i] Saving condition number table to: %s\n', cond_filename);
writetable(err_table, err_filename);
writetable(cond_table, cond_filename);
end




