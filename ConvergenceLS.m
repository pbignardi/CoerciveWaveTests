function [] = ConvergenceLS(pnum, varargin)
%ConvergenceLS - compute convergence plot for the specified problem using
%the least square formulation.
%   INPUT:
%   pnum:   Number of the problem to solve
%   A:      (Optional) coefficient for the volume term of the bilinear form
addpath(genpath("local_stiffness"));

if ~isempty(varargin)
    A = varargin{1};
else
    A = 1;
end

%% Define problem, discretization and mesh
% Create simple problem
p = WaveProblem(pnum);
% Define domain
Q = p.Q;
% Choose error norms
errs = ["l2", "h1", "cond"];
%% Iterate for different number of elements
N = [4, 8, 16, 32, 64, 128, 256, 512];
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
    [u, Kcond] = SolverLeastSquares(p, Q, mesh, d, A);
    %omega0_mean = ComputeMean(u, 0, mesh, d);
    %u = MeanShift(u, omega0_mean, mesh);

    
    
    % Compute errors
    errors = ComputeErrors(u, p, mesh, d, "relative");
    L2errors(i) = errors.L2E;
    H1errors(i) = errors.H1E;
    GRerrors(i) = errors.GRE;
    OPerrors(i) = errors.OPE;
    SUPerrors(i) = errors.SUPE;
    Kconds(i) = Kcond;
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

lgd_entries = {};
for err = errs
    if err == "l2"
        loglog_plot(H, L2errors, "-d", linewidth, BLUE, markersize);
        p_l2 = polyfit(log(H(end-2:end)), log(L2errors(end-2:end)), 1);
        lgd_entries{end + 1} = strcat("L2 error - order: ", string(p_l2(1)));
        rates = diff(log(L2errors))./diff(log(H.'));
        for k = length(L2errors):-1:2
            text(H(k)+0.1*H(k), L2errors(k), strcat("r=",string(rates(k-1))), ...
                Interpreter="latex", Margin=10);
        end
        hold on, grid on
    elseif err == "h1"
        loglog_plot(H, H1errors, "-s", linewidth, RED, markersize);
        p_h1 = polyfit(log(H(end-2:end)), log(H1errors(end-2:end)), 1);
        lgd_entries{end + 1} = strcat("H1 error - order: ", string(p_h1(1)));
        rates = diff(log(H1errors))./diff(log(H.'));
        for k = length(H1errors):-1:2
            text(H(k)+0.1*H(k), H1errors(k), strcat("r=",string(rates(k-1))), ...
                Interpreter="latex", Margin=10);
        end
        hold on, grid on
    elseif err == "linf"
        loglog_plot(H, SUPerrors, "-o", linewidth, YELLOW, markersize);
        p_sup = polyfit(log(H(end-2:end)), log(SUPerrors(end-2:end)), 1);
        lgd_entries{end + 1} = strcat("Linf error - order: ", string(p_sup(1)));
        rates = diff(log(SUPerrors))./diff(log(H.'));
        for k = length(SUPerrors):-1:2
            text(H(k)+0.1*H(k), SUPerrors(k), strcat("r=",string(rates(k-1))), ...
                Interpreter="latex", Margin=10);
        end
        hold on, grid on
    elseif err == "graph"
        loglog_plot(H, GRerrors, "-^", linewidth, GREEN, markersize);
        p_gr = polyfit(log(H(end-2:end)), log(GRerrors(end-2:end)), 1);
        lgd_entries{end + 1} = strcat("Graph error - order: ", string(p_gr(1)));
        rates = diff(log(GRerrors))./diff(log(H.'));
        for k = length(GRerrors):-1:2
            text(H(k)+0.1*H(k), GRerrors(k), strcat("r=",string(rates(k-1))), ...
                Interpreter="latex", Margin=10);
        end
        hold on, grid on
    elseif err == "op"
        loglog_plot(H, OPerrors, "-+", linewidth, PURPLE, markersize);
        p_op = polyfit(log(H(end-2:end)), log(OPerrors(end-2:end)), 1);
        lgd_entries{end + 1} = strcat("LSQ error - order: ", string(p_op(1)));
        rates = diff(log(OPerrors))./diff(log(H.'));
        for k = length(OPerrors):-1:2
            text(H(k)+0.1*H(k), OPerrors(k), strcat("r=",string(rates(k-1))), ...
                Interpreter="latex", Margin=10);
        end
        hold on, grid on
    elseif err == "cond"
        loglog(H,  1 ./ Kconds, "--", "Color", [0.3 0.3 0.3]);
        p_cond = polyfit(log(H(end-1:end)), - log(Kconds(end-1:end)),1);
        lgd_entries{end + 1} = strcat("1/cond(K) - order: ", string(p_cond(1)));
        hold on, grid on
    end
end


legend(lgd_entries, ...
    "Location", "southeast", "NumColumns", legend_cols);
xlabel('$h$', Interpreter='latex');
ylabel('Relative error', Interpreter='latex');

function loglog_plot(x, y, line_style, linewidth, color, markersize)
    loglog(x, y, line_style, ...
        "LineWidth", linewidth, ...
        "Color", color, ...
        "MarkerFaceColor", color, ...
        "MarkerSize", markersize)
end
end



