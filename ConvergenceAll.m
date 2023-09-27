function [] = ConvergenceAll(pnum, varargin)
%ConvergenceALL - compute convergence plot for the specified problem
%comparing both LS and CO formulations.
%   INPUT:
%   pnum:   Number of the problem to solve
%   A_CO:   Vector of [A, A0] for the coercive formulation (optional)
%   A_LS:   Coefficient of the volume term of the bilinear form in the LS
%           formulation (optional)

addpath(genpath('local_stiffness'));

if nargin == 3
    A_CO = varargin{1};
    A_LS = varargin{2};
else
    if nargin > 1
        warning("Should not pass only one parameter of the formulation. " + ...
            "IGNORING BOTH");
    end
    A_CO = [1, 1];
    A_LS = 1;
end

%% Define problem, discretisation and mesh
% create problem structure
p = WaveProblem(pnum);
% set error norms
errs = ["l2", "h1", "linf", "cond"];
errtype = "relative";

%% Iterate for different number of elements
N = 2.^(2:7);
CO_L2errors = zeros(length(N), 1);
CO_H1errors = zeros(length(N), 1);
CO_GRerrors = zeros(length(N), 1);
CO_OPerrors = zeros(length(N), 1);
CO_SUPerrors = zeros(length(N), 1);
CO_Kconds = zeros(length(N), 1);

LS_L2errors = zeros(length(N), 1);
LS_H1errors = zeros(length(N), 1);
LS_GRerrors = zeros(length(N), 1);
LS_OPerrors = zeros(length(N), 1);
LS_SUPerrors = zeros(length(N), 1);
LS_Kconds = zeros(length(N), 1);

for i = 1:numel(N)
    nx = N(i); nt = N(i);
    d = Discretization(nx, nt, p.Q);
    % Build mesh
    mesh = CartesianMesh(d);

    % Solve Coercive problem
    [u, Kcond] = SolverWaves(p, p.Q, mesh, d, A_CO(1), A_CO(2));
    % Compute projections
    [u_L2proj, u_H1proj, u_Vproj] = ProjectionBFS(p, d, A_CO);

    % Compute Coercive errors
    errors = ComputeErrors(u, p, mesh, d, errtype);
    CO_L2errors(i) = errors.L2E;
    CO_H1errors(i) = errors.H1E;
    CO_GRerrors(i) = errors.GRE;
    CO_OPerrors(i) = errors.OPE;
    CO_SUPerrors(i) = errors.SUPE;
    CO_Kconds(i) = Kcond;

    % Compute best approximation errors (projections)
    errors = ComputeErrors(u_L2proj, p, mesh, d, errtype);
    Proj_L2errors(i) = errors.L2E;

    %

    % Solve Least square problem
    [u, Kcond] = SolverLeastSquares(p, p.Q, mesh, d, A_LS);

    % Compute least square errors
    errors = ComputeErrors(u, p, mesh, d, errtype);
    LS_L2errors(i) = errors.L2E;
    LS_H1errors(i) = errors.H1E;
    LS_GRerrors(i) = errors.GRE;
    LS_OPerrors(i) = errors.OPE;
    LS_SUPerrors(i) = errors.SUPE;
    LS_Kconds(i) = Kcond;
end
%% Colorscale
BLUE    = "#0072BD";
RED     = "#D95319";
YELLOW  = "#EDB120";
GREEN   = "#77AC30";
PURPLE  = "#7E2F8E";
colors = [BLUE, RED, YELLOW, GREEN, PURPLE];

%% Convergence plot
linewidth = 2;
legend_cols = numel(errs);
markersize = 9;

Hx = (p.Q.xmax - p.Q.xmin) ./ N;
Ht = p.Q.T ./ N;
H = sqrt(Hx .^2 + Ht .^ 2);

lgd_entries = {};
figure
conv_ax = gca;
fs = 18;
fontsize(fs, 'points');
hold on
i = 1;
for err = errs
    switch err
        case "l2"
            co_errs = CO_L2errors;
            ls_errs = LS_L2errors;
            lgd_entries{end + 1} = strcat("L2 error - CO");
            lgd_entries{end + 1} = strcat("L2 error - LS");
        case "h1"
            co_errs = CO_H1errors;
            ls_errs = LS_H1errors;
            lgd_entries{end + 1} = strcat("H1 error - CO");
            lgd_entries{end + 1} = strcat("H1 error - LS");
        case "linf"
            co_errs = CO_SUPerrors;
            ls_errs = LS_SUPerrors;
            lgd_entries{end + 1} = strcat("Linf error - CO");
            lgd_entries{end + 1} = strcat("Linf error - LS");
        otherwise
            continue
    end
    loglog(H, co_errs, "-o", "LineWidth", linewidth, "MarkerSize", ...
        markersize, 'Color', colors(i));
    loglog(H, ls_errs, "--", "LineWidth", linewidth, "MarkerSize", ...
        markersize, 'Color', colors(i));
    i = i + 1;
    co_rates = diff(log(co_errs))./diff(log(H.'));
    ls_rates = diff(log(ls_errs))./diff(log(H.'));

    for k = length(co_errs):-1:2
        text(H(k) +0.1*H(k), co_errs(k), "r=" + string(co_rates(k-1)), Margin=10, FontSize=fs-2);
    end
    for k = length(ls_errs):-1:2
        text(H(k) +0.1*H(k), ls_errs(k), "r=" + string(ls_rates(k-1)), Margin=10, FontSize=fs-2);
    end

    
end
set(conv_ax, 'XScale', 'log');
set(conv_ax, 'YScale', 'log');
set(gcf, 'Position', [1,1, 960, 720]);
axis padded

legend(lgd_entries, "Location", "southeast", "NumColumns", legend_cols);
xlabel("h");
ylabel(errtype + " error");
grid on
hold off

if ismember('cond', errs)
    co_rates = diff(log(CO_Kconds))./diff(log(H.'));
    ls_rates = diff(log(LS_Kconds))./diff(log(H.'));

    figure;
    

    condest_ax = gca;
    set(condest_ax, 'XScale', 'log');
    set(condest_ax, 'YScale', 'log');


    loglog(H, CO_Kconds, '-o', 'LineWidth', linewidth, 'MarkerSize',...
        markersize);
    hold on
    loglog(H, LS_Kconds, '--', 'LineWidth', linewidth, 'MarkerSize',...
        markersize);
    
    for k = length(CO_Kconds):-1:2
        text(H(k) +0.1*H(k), CO_Kconds(k), "r=" + string(co_rates(k-1)), Margin=10, FontSize=fs-2);
    end
    for k = length(LS_Kconds):-1:2
        text(H(k) +0.1*H(k), LS_Kconds(k), "r=" + string(ls_rates(k-1)), Margin=10, FontSize=fs-2);
    end



    axis padded
    xlabel('h');
    ylabel('Condition number');
    fontsize(fs, 'points');
    grid on
    legend('condest(K) -- CO', 'condest(K) -- LS', 'Location','southeast');
    set(gcf, 'Position', [1,1,960,720]);
end

end



