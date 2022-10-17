% Convergence tests
clc
clear
close all
addpath(genpath("local_stiffness"));
to_file = 1;
%% Define problem, discretization and mesh
p_num = 4;
% Create simple problem
p = WaveProblem(p_num);
% Define domain
Q = Domain(-1, 1, 1);
% Choose error norms
errs = ["l2", "h1", "op", "cond"];
%% Iterate for different number of elements
N = [4, 8, 16, 32, 64, 128];
L2errors = zeros(length(N), 1);
H1errors = zeros(length(N), 1);
GRerrors = zeros(length(N), 1);
OPerrors = zeros(length(N), 1);
SUPerrors = zeros(length(N), 1);
Kconds = zeros(length(N), 1);
A = 1;

i = 1;
for n = N 
    % Discretise the domain
    nx = n; nt = n;
    d = Discretization(nx, nt, Q);
    % Build mesh
    mesh = CartesianMesh(d);
    
    % Solve problem
    [u, Kcond] = SolverLeastSquares(p, Q, mesh, d, A);
    %omega0_mean = ComputeMean(u, 0, mesh, d);
    %u = MeanShift(u, omega0_mean, mesh);

    
    
    % Compute errors
    errors = ComputeErrors(u, p, mesh, d, "absolute");
    L2errors(i) = errors.L2E;
    H1errors(i) = errors.H1E;
    GRerrors(i) = errors.GRE;
    OPerrors(i) = errors.OPE;
    SUPerrors(i) = errors.SUPE;
    Kconds(i) = Kcond;
    i = i + 1;
end

Hx = (Q.xmax - Q.xmin) ./ N;
Ht = Q.T ./ N;
H = sqrt(Hx .^ 2 + Ht .^ 2).';

if to_file
    results = table(H, L2errors, H1errors, OPerrors, Kconds);
    writetable(results, ...
        strcat("test_results/p", string(p_num), "_ls_conv.dat"));
else
    PlotConvergenceGraph(H,L2errors, H1errors, OPerrors, Kconds);
end


