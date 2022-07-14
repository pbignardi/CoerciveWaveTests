% Convergence tests
clc
clear
close all
addpath(genpath("local_stiffness"));

%% Define problem, discretization and mesh
% Create simple problem
p = WaveProblem(3);
% Define domain
Q = Domain(-1, 1, 1);

%% Iterate for different number of elements
N = [4, 8, 16, 32, 64, 128];
L2errors = zeros(length(N), 1);
H1errors = zeros(length(N), 1);
GRerrors = zeros(length(N), 1);
OPerrors = zeros(length(N), 1);
SUPerrors = zeros(length(N), 1);

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
    H1errors(i) = errors.H1E;
    GRerrors(i) = errors.GRE;
    OPerrors(i) = errors.OPE;
    SUPerrors(i) = errors.SUPE;
    i = i + 1;
end

%% Convergence plot
% Plot settings
linewidth = 2;
legend_cols = 1;
markersize = 9;
BLUE    = "#0072BD";
RED     = "#D95319";
YELLOW  = "#EDB120";
GREEN   = "#77AC30";
PURPLE  = "#7E2F8E";

Hx = (Q.xmax - Q.xmin) ./ N;
Ht = Q.T ./ N;
H = sqrt(Hx .^ 2 + Ht .^ 2);

loglog_plot(H, L2errors, "-d", linewidth, BLUE, markersize);
hold on, grid on
loglog_plot(H, H1errors, "-s", linewidth, RED, markersize);
loglog_plot(H, GRerrors, "-^", linewidth, GREEN, markersize);
loglog_plot(H, SUPerrors, "-o", linewidth, YELLOW, markersize);

p_l2 = polyfit(log(H), log(L2errors), 1);
p_h1 = polyfit(log(H), log(H1errors), 1);
p_op = polyfit(log(H), log(OPerrors), 1);
p_gr = polyfit(log(H), log(GRerrors), 1);
p_sup = polyfit(log(H), log(SUPerrors), 1);

legend_entries = {strcat("L2 error - order: ", string(p_l2(1))),...
                  strcat("H1 error - order: ", string(p_h1(1))),...
                  strcat("LeastSq error - order: ", string(p_op(1))),...
                  strcat("Linf error - order: ", string(p_sup(1)))};%,...
                  %strcat("Graph error - order: ", string(p_gr(1)))};

legend(legend_entries, ...
    "Location", "southeast", "NumColumns", legend_cols);

function loglog_plot(x, y, line_style, linewidth, color, markersize)
    loglog(x, y, line_style, ...
        "LineWidth", linewidth, ...
        "Color", color, ...
        "MarkerFaceColor", color, ...
        "MarkerSize", markersize)
end

%% PRove
%{
- soluzione esatta nello spazio discreto.
- 
%}




