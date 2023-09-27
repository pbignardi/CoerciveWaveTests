% Paolo Bignardi - July 2023
% Convergence tests for Section 7

% In each section run the tests for Problem 1 and 3, with regular and
% smooth solution
%% Testing CFL condition - OPT parameters
fprintf('====> Running CFL condition test: OPTIMAL PARAMETERS\n');
N = 2.^(1:11);
fprintf('[INFO]: N = %s\n', join(string(N), ','));
Nts = [4, 8, 32];
for Nt = Nts
    fprintf('-- [Nt=%d]\n', Nt);
    Convergence(2, 'VERBOSE', false, 'PAR_TYPE', 'OPT', ...
        'WRITE_TO_FILE', true, 'TEST_CFL', true, 'NT', Nt, 'PLOT', false, 'N', N);
    Convergence(3, 'VERBOSE', false, 'PAR_TYPE', 'OPT', ...
        'WRITE_TO_FILE', true, 'TEST_CFL', true, 'NT', Nt, 'PLOT', false, 'N', N);
end

%% Testing CFL condition - GEN parameters
fprintf('====> Running CFL condition test: GENERIC PARAMETERS\n');
N = 2.^(1:11);
fprintf('[INFO]: N = %s\n', join(string(N), ','));
Nts = [4, 8, 32];
for Nt = Nts
    fprintf('-- [Nt=%d]\n', Nt);
    Convergence(2, 'VERBOSE', false, 'PAR_TYPE', 'GEN', ...
        'WRITE_TO_FILE', true, 'TEST_CFL', true, 'NT', Nt, 'PLOT', false, 'N', N);
    Convergence(3, 'VERBOSE', false, 'PAR_TYPE', 'GEN', ...
        'WRITE_TO_FILE', true, 'TEST_CFL', true, 'NT', Nt, 'PLOT', false, 'N', N);
end

%% Full convergence tests - OPT parameters
N = [2, 4, 8, 16, 32, 64, 128];
fprintf('====> Running full convergence test: OPTIMAL PARAMETERS\n');
Convergence(2, 'PAR_TYPE', 'OPT', 'WRITE_TO_FILE', true, 'N', N, 'PLOT', false, 'QO_CONST', true);
Convergence(3, 'PAR_TYPE', 'OPT', 'WRITE_TO_FILE', true, 'N', N, 'PLOT', false, 'QO_CONST', true);
Convergence(6, 'PAR_TYPE', 'OPT', 'WRITE_TO_FILE', true, 'N', N, 'PLOT', false, 'QO_CONST', true);

%% Full convergence tests - OPT parameters
N = [2, 4, 8, 16, 32, 64, 128];
fprintf('====> Running full convergence test: GENERIC PARAMETERS\n');
Convergence(2, 'PAR_TYPE', 'GEN', 'WRITE_TO_FILE', true, 'N', N, 'PLOT', false, 'QO_CONST', true);
Convergence(3, 'PAR_TYPE', 'GEN', 'WRITE_TO_FILE', true, 'N', N, 'PLOT', false, 'QO_CONST', true);