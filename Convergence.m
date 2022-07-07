% Convergence tests
clc
clear
close all
addpath(genpath("local_stiffness"));

%% Define problem, discretization and mesh
% Create simple problem
p = WaveProblem(4);
% Define domain
Q = Domain(-1, 1, 10);

%% Iterate for different number of elements
N = [4, 8, 16, 32, 64, 128];
L2errors = zeros(length(N), 1);
i = 1;
for n = N 
    % Discretise the domain
    nx = n; nt = n;
    d = Discretization(nx, nt, Q);
    % Build mesh
    mesh = CartesianMesh(d);
    
    form = struct();
    form.A = 1000;
    form.nu = 2;
    form.xi = 1;
    form.beta = 20;

    % Solve problem
    u = SolverWaves(p, Q, mesh, d);
    
    
    % Compute errors
    errors = ComputeErrors(u, p, mesh, d);
    L2errors(i) = errors.L2E;
    i = i + 1;
end

%% Convergence plot
Hx = (Q.xmax - Q.xmin) ./ N;
Ht = Q.T ./ N;
H = sqrt(Hx .^ 2 + Ht .^ 2);

loglog(H, L2errors, "-d", "LineWidth", 3);

hold on, grid on
p_l2 = polyfit(log(H), log(L2errors), 1);

legend(strcat("L2 error - order: ", string(p_l2(1))));


%% PRove
%{
- soluzione esatta nello spazio discreto.
- 
%}




