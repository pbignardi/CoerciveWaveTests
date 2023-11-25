% TestMultiplierPars - Compute L2 errors for a range of Beta, Xi and Nu.
%% Initialize
% specify problem to solve
pnum = 2;
% min order of magnitude for Xi
logXiMin = -3;
% max order of magnitude for Xi
logXiMax = 3;
% min order of magnitude for Beta
logBetaMin = -5;
% max order of magnitude for Beta
logBetaMax = 5;
% min order of magnitude for Nu
logNuMin = 0.001;
% max order of magnitude for Nu
logNuMax = 2;
% number of nodes in Xi search space
nXi = 100;
% number of nodes in Beta search space
nBeta = 100;
% number of nodes in Nu search space
nNu = 7;
% number of elements in each direction
nElms = 32;

% figure size
figure_width = 920;
figure_height = 720;
% output figures font size
font_size = 20;                                                       
% resolution of output figures
output_dpi = 450;
% save to file
save_plot = true;

% is debugging?
DEBUG = true;

% Print log
fprintf('Test parameters <strong>BETA, XI, NU</strong>\n');
fprintf('=>> SEARCH SPACE\n');
fprintf('logXiMin: %d\n', logXiMin);
fprintf('logXiMax: %d\n', logXiMax);
fprintf('logBetaMin: %d\n', logBetaMin);
fprintf('logBetaMax: %d\n', logBetaMax);
fprintf('logNuMin: %d\n', logNuMin);
fprintf('logNuMax: %d\n', logNuMax);
fprintf('nXi: %d\n', nXi);
fprintf('nBeta: %d\n', nBeta);
fprintf('nNu: %d\n', nNu);
fprintf('\n');

fprintf('=>> SOLVER PARAMETERS\n');
fprintf('problem_id: %d\n', pnum);
fprintf('Nt: %d\n', nElms);
fprintf('Nx: %d\n', nElms);
fprintf('\n');

fprintf('=>> OPTIONS\n');
fprintf('figure width: %d\n', figure_width);
fprintf('figure height: %d\n', figure_height);
fprintf('font_size: %d\n', font_size);
fprintf('output_dpi: %d\n', output_dpi);
fprintf('save plots: %d\n', save_plot);
% define search space
Xi = logspace(logXiMin, logXiMax, nXi);
Beta = logspace(logBetaMin, logBetaMax, nBeta);
Nu = logspace(logNuMin, logNuMax, nNu);

problem = WaveProblem(pnum);
discretization = Discretization(nElms, nElms, problem.Q);
mesh = CartesianMesh(discretization);

% setup Latex ticks interpreter
set(groot,'defaultAxesTickLabelInterpreter','latex'); 
set(groot,'defaulttextinterpreter','latex');
set(groot,'defaultLegendInterpreter','latex');
set(0,'DefaultTextInterpreter','latex')
set(0,'DefaultLegendInterpreter','latex')

%% Compute errors for varying parameters
fprintf('** Compute L2errors varying <strong>BETA, XI, NU</strong>\n')

if DEBUG
load('Results/l2error_beta_xi_nu.mat');
L2errors = l2err_pars;
end

% L2errors = nan(nBeta, nXi, nNu);
ConditionNumbers = nan(nBeta, nXi, nNu);
IsWellPosed = false(nBeta, nXi, nNu);

for i = 1:nBeta
    beta_i = Beta(i);
    for j = 1:nXi
        xi_j = Xi(j);
        for k = 1:nNu
            if ~DEBUG
            form = FormParameters(problem, ParType='CUSTOM', BETA=beta_i, ...
                 XI=xi_j, NU=Nu(k));
            u = SolverWaves(problem, problem.Q, mesh, discretization, form);
            err = ComputeErrors(u, problem, mesh, discretization, 'relative');
            L2errors(i, j, k) = err.L2E;
            end
            beta_lb = BetaLowerBound(xi_j, Nu(k), problem.c, problem.Q.T, ...
                problem.Q.L, problem.theta, problem.Q.delta);
            IsWellPosed(i, j, k) = beta_i >= beta_lb;
        end
        progress = ((i - 1) * nXi + j) / (nXi * nBeta);
    end
end
%% Check ratio of errors for varying Nu. Beta and Xi fixed.
fprintf('** Importance of parameter <strong>NU</strong> (see 7.1.2)\n')
% Error ratio for well posed parameters
NuErrorRatioWP = nan(nBeta, nXi);
% Error ratio fo all parameters
NuErrorRatioGlobal = max(L2errors, [], 3) ./ min(L2errors, [], 3);

% Ratio between max error and min error, for fixed beta and xi
for i = 1:nBeta
    for j = 1:nXi
        % keep only parameters when \beta, \xi and \nu are well posed
        if any(IsWellPosed(i, j, :))
            max_value = max(L2errors(i, j, IsWellPosed(i, j, :)));
            min_value = min(L2errors(i, j, IsWellPosed(i, j, :)));
            NuErrorRatioWP(i, j) = max_value / min_value;
        end
    end
end

fprintf('max of error ratio (overall): %f\n', max(NuErrorRatio, [], 'all'));
ratio_ub = max(NuErrorRatio(Xis >= 1), [], 'all');
fprintf('max of error ratio (when Xi >= 1): %f\n', ratio_ub);

%% Make plot
% Assume as in Section 7.1.2 that \nu=2, fixed.
NuFixed = 2;

% Display dotted area
[XiArea, BetaArea] = meshgrid(Xi(2:6:end), Beta(2:6:end));
IsWellPosedArea = zeros(size(XiArea));
for i = 1:size(XiArea, 1)
    for j = 1:size(BetaArea, 2)
        xi = XiArea(i, j);
        beta_lb = BetaLowerBound(XiArea(i, j), NuFixed, problem.c, ...
            problem.Q.T, problem.Q.L, problem.theta, problem.Q.delta);
        if BetaArea(i, j) >= beta_lb
            IsWellPosedArea(i, j) = true;
        end
    end
end

%% L2 error figure
[Xis, Betas] = meshgrid(Xi, Beta);
l2err_comb = figure;
surf(Xis, Betas, min(L2errors, 1));
set(gca, 'xscale', 'log');
set(gca, 'yscale', 'log');
set(gca,'ColorScale','log');
set(gca, 'xlim', [min(Xi) max(Xi)]);
set(gca, 'ylim', [min(Beta) max(Beta)]);
set(gcf, 'Position', [1,1, figure_width, figure_height]);
fontsize(font_size, 'points');
xlabel('$\xi$',Interpreter='latex');
ylabel('$\beta$',Interpreter='latex');
xticks(10.^(logXiMin:2:logXiMax));
yticks(10.^(logBetaMin:2:logBetaMax));
clim([min(L2errors(:)) 1]);
c = colorbar;
set(c,'TickLabelInterpreter','latex');
shading flat
colormap turbo
h.BoxStyle = 'full';
view(2)
hold on

% Dotted area
plot(Xi, BetaMin(Xi), 'w', 'LineWidth', 2)
scatter(XiArea(IsWellPosedArea==0),BetaArea(IsWellPosedArea==0), 24, ...
    'white', 'filled')
hold off

%% Condition number figure
kcond_comb = figure;
pcolor(Xis, Betas, max(kcond_beta_xi_comb, 1));
set(gca, 'xscale', 'log');
set(gca, 'yscale', 'log');
set(gca,'ColorScale','log');
set(gca, 'xlim', [min(Xi) max(Xi)]);
set(gca, 'ylim', [min(Beta) max(Beta)]);
set(gcf, 'Position', [1,1, figure_width, figure_height]);
fontsize(font_size, 'points');
xlabel('$\xi$',Interpreter='latex');
ylabel('$\beta$',Interpreter='latex');
xticks(10.^(logXiMin:2:logXiMax));
yticks(10.^(logBetaMin:2:logBetaMax));
clim([min(kcond_beta_xi_comb(:)) 1e15]);
c = colorbar;
set(c,'TickLabelInterpreter','latex');
shading flat
colormap turbo
hold on

% Dotted area
plot(Xi, BetaMin(Xi), 'w', 'LineWidth', 2)
scatter(XiArea(IsWellPosedArea==0),BetaArea(IsWellPosedArea==0), 24, ...
    'white', 'filled')
hold off

%% Save to file
if save_plot
    root = 'Results/ParsTestFigures/';
    basename = sprintf('%stestBetaXiNu-p%d-numEl%d', root, ...
        string(pnum), string(nElms));
    l2err_name = basename + '-l2err.png';
    cond_name = basename + '-cond.png';
    exportgraphics(l2err_comb, l2err_name, 'Resolution', output_dpi);
    exportgraphics(kcond_comb, cond_name , 'Resolution', output_dpi);
end

function beta_lb = BetaLowerBound(xi, nu, c, T, L, theta, delta)
% Computes the lower bound for Beta to ensure coercivity as in (35). 
% Assumes that d = 1.
beta_lb = xi/(nu - 1) * max([L/(c*T) + 1, L/(c*T)*(theta + 1/(theta*delta))]);
end
