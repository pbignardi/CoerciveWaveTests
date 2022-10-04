% Convergence tests
clc
clear
close all
addpath(genpath("local_stiffness"));
to_file = 0;
%% Define problem, discretization and mesh
% Create simple problem
p = WaveProblem(7);
% Define domain
Q = Domain(-1, 1, 1);
% Choose error norms
errs = ["l2", "h1", "op", "cond"];
%% Iterate for different number of elements
N = [2, 4, 8, 16, 32, 64, 128, 256];
L2errors = zeros(length(N), 1);
H1errors = zeros(length(N), 1);
GRerrors = zeros(length(N), 1);
OPerrors = zeros(length(N), 1);
SUPerrors = zeros(length(N), 1);
Kconds = zeros(length(N), 1);

i = 1;
for n = N 
    % Discretise the domain
    nx = n; nt = n;
    d = Discretization(nx, nt, Q);
    % Build mesh
    mesh = CartesianMesh(d);
    
    % Solve problem
    [u, Kcond] = SolverLeastSquares(p, Q, mesh, d);
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
    results = [H, ...
        L2errors, H1errors, GRerrors, OPerrors, SUPerrors, Kconds];
    writematrix(results, "ls_convergence.csv");
else
    PlotConvergenceGraph(H,L2errors, H1errors, OPerrors, Kconds);
end


