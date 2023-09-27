% Batch test run for parameter testing
% Test problem 1, 2, 4, change number of elements 32 and 64 (could do 128,
% but it takes forever).

problems = [2, 3];
M_els = [32];
N = 100;

for p_num = problems
    for M = M_els
        disp('Problem: ' + string(p_num) + ...
            ' - Num. elements: ' + string(M) + ...
            ' - Coercive formulation');
        TestA(p_num, N, M);
        close all
    end
end
