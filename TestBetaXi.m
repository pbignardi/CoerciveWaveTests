%% Fix xi or not?
pnum = 2;
xi_list = logspace(-3, 3, 100);
% ratio_list = logspace(0, 4, numel(xi_list)); % beta / xi
beta_list = logspace(-5, 5, numel(xi_list));

pdata = WaveProblem(pnum);
ddata = Discretization(32, 32, pdata.Q);
mesh = CartesianMesh(ddata);

R_min = @(nu) max([1./(nu-1)*(pdata.Q.L/pdata.c/pdata.Q.T + 1), ...
    1./(nu - 1)*pdata.Q.L/pdata.c/pdata.Q.T * ...
    (pdata.theta + 1 / (pdata.theta * pdata.Q.delta))]);


%% 2d surf plot

l2err_beta_xi_comb = nan(numel(beta_list), numel(xi_list));
kcond_beta_xi_comb = nan(numel(beta_list), numel(xi_list));
wp_idx = zeros(numel(beta_list), numel(xi_list));
for i = 1:numel(beta_list)
    beta = beta_list(i);
    parfor j = 1:numel(xi_list)
        xi = xi_list(j);
        % [err_table, ~] = Convergence(pnum, 'PAR_TYPE', 'CUSTOM', ...
        %     'BETA', beta, 'XI', xi, 'N', 2.^(1:6), ...
        %     'PLOT', false, 'VERBOSE', false);
        fdata = initializeForm(pdata, pdata.Q, 'CUSTOM', ...
            'BETA', beta, 'xi', xi);
        [u, Kcond] = SolverWaves(pdata, pdata.Q, mesh, ddata, fdata);
        err = ComputeErrors(u, pdata, mesh, ddata, 'relative');
        % l2err_beta_xi_comb(j, i) = err_table.L2errors(end-1);
        l2err_beta_xi_comb(i, j) = err.L2E;
        kcond_beta_xi_comb(i, j) = Kcond;
        % if CheckConvergence(err_table, 3, 4, 3, 2, 1e-1)
        %     wp_idx(j, i) = 1;
        % end
    end
    fprintf('-> i = [%d / %d]\n', i, numel(beta_list));
end

%% Make plot
set(groot,'defaultAxesTickLabelInterpreter','latex'); 
set(groot,'defaulttextinterpreter','latex');
set(groot,'defaultLegendInterpreter','latex');
set(0,'DefaultTextInterpreter','latex')
set(0,'DefaultLegendInterpreter','latex')

% create dotted area
[xi_area, beta_area] = meshgrid(xi_list(2:6:end), beta_list(2:6:end));
wp_idx = zeros(size(xi_area));
BetaMin = @(xi) max(xi.*(pdata.Q.L/pdata.c/pdata.Q.T + 1), xi.*pdata.Q.L/pdata.c/pdata.Q.T*(pdata.theta+1/(pdata.theta*pdata.Q.delta)));
for i = 1:size(xi_area, 1)
    for j = 1:size(beta_area, 2)
        xi = xi_area(i, j);
        beta = beta_area(i, j);
        if beta >= BetaMin(xi)
            wp_idx(i, j) = true;
        end
    end
end

[Xi, Beta] = meshgrid(xi_list, beta_list);
l2err_comb = figure;
fs = 20;                                                       
surf(Xi, Beta, min(l2err_beta_xi_comb, 1));
h = gca;
set(h, 'xscale', 'log');
set(h, 'yscale', 'log');
set(h,'ColorScale','log');
set(h, 'xlim', [min(xi_list) max(xi_list)]);
set(h, 'ylim', [min(beta_list) max(beta_list)]);
% set(gcf, 'Position', [1,1, 960, 720]);
fontsize(fs, 'points');
xlabel('$\xi$',Interpreter='latex');
ylabel('$\beta$',Interpreter='latex');
xticks([1e-3, 1e-1, 1e1, 1e3]);
yticks([1e-5 1e-3 1e-1 1e1 1e3 1e5]);
clim([min(l2err_beta_xi_comb(:)) 1]);
c = colorbar;
set(c,'TickLabelInterpreter','latex');
shading flat
colormap turbo
h.BoxStyle = 'full';
view(2)
hold on
% area(xi_list, BetaMin(xi_list), 'LineWidth', 2, 'FaceColor', 'w', 'FaceAlpha', 0, 'EdgeColor', 'white')
plot(xi_list, BetaMin(xi_list), 'w', 'LineWidth', 2)
scatter(xi_area(wp_idx==0),beta_area(wp_idx==0), 24, 'white', 'filled')
hold off

kcond_comb = figure;
fs = 20;                                                       
h = gca;
pcolor(Xi, Beta, max(kcond_beta_xi_comb, 1));
set(h, 'xscale', 'log');
set(h, 'yscale', 'log');
set(h,'ColorScale','log');
set(h, 'xlim', [min(xi_list) max(xi_list)]);
set(h, 'ylim', [min(beta_list) max(beta_list)]);
% set(gcf, 'Position', [1,1, 960, 720]);
fontsize(fs, 'points');
xlabel('$\xi$',Interpreter='latex');
ylabel('$\beta$',Interpreter='latex');
xticks([1e-3, 1e-1, 1e1, 1e3]);
yticks([1e-5 1e-3 1e-1 1e1 1e3 1e5]);
clim([min(kcond_beta_xi_comb(:)) 1e15]);
c = colorbar;
set(c,'TickLabelInterpreter','latex');
shading flat
colormap turbo
hold on
% area(xi_list, BetaMin(xi_list), 'LineWidth', 2, 'FaceColor', 'w', 'FaceAlpha', 0, 'EdgeColor', 'white')
plot(xi_list, BetaMin(xi_list), 'w', 'LineWidth', 2)
scatter(xi_area(wp_idx==0),beta_area(wp_idx==0), 24, 'white', 'filled')
hold off

% DO NOT USE MATLAB2TIKZ, LATEX DOESN'T LIKE THIS PLOT. TOO MUCH MEMORY
% REQUIRED

% this shows that taking beta \ xi > R_min is necessary to achieve good
% accuracy, otherwise the method is not well posed. To set ourselves in the
% well posed case, we can plot l2error as function of (k * Rmin * xi, xi),
% where k is the markup. A multiplier on the ratio R. This is given by the
% plots below

%% Different plot. Fix the ratio beta/xi and look at the l2error
% So I should take all the values of beta and xi that yields the same ratio
% and then look at their respective L2errors, right?

% Compute the right ratio to allow every pars to give coercivity
R = 1;
for i = 1:N
    xi = xi_list(N);
    fdata_opt = initializeForm(pdata, pdata.Q, 'CUSTOM', 'XI', xi);
    R = max(R, fdata_opt.BETA / fdata_opt.XI);
end

markups = 0.2:0.2:3;
L2err_xi = zeros(numel(xi_list), numel(markups));
for j = 1:numel(markups)
    R = R * markups(j);
    parfor i = 1:numel(xi_list)
        xi = xi_list(i);
        fdata = initializeForm(pdata, pdata.Q, 'CUSTOM', 'BETA', xi * R, 'XI', xi);
        [u, ~] = SolverWaves(pdata, pdata.Q, mesh, ddata, fdata);
        err = ComputeErrors(u, pdata, mesh, ddata, 'relative'); 
        L2err_xi(i, j) = err.L2E;
    end
end

l2err_xi_plot = figure;
h = gca;
xi_one_idx = find(xi_list == 1);
legend_entries = cell(numel(markups), 1);
for j = 1:numel(markups)
    loglog(h, xi_list, L2err_xi(:, j));
    legend_entries{j} = sprintf('R=%.2f', markups(j));
    hold on
end
legend(legend_entries);
% scatter(h, xi_list(xi_one_idx), L2err_xi(xi_one_idx, end));
fontsize(fs, 'points');
axis padded
hold off
% This shows two things: 1) when xi goes to 0 accuracy deteriorates. If the
% ratio is large enough though, accuracy can be bounded
% 2) regardless of the ratio, picking xi=1 gives optimal accuracy.

%% Testing different nu
% letting nu varies, and taking optimal other values
nu_list = logspace(0.001, 2, 7);
L2err_nu = zeros(numel(nu_list), 1);
for i = 1:numel(nu_list)
    fdata = initializeForm(pdata, pdata.Q, 'CUSTOM', 'NU', nu_list(i));
    [u, ~] = SolverWaves(pdata, pdata.Q, mesh, ddata, fdata);
    err = ComputeErrors(u, pdata, mesh, ddata, 'relative');
    L2err_nu(i) = err.L2E;
end
l2err_nu_plot = figure;
h = gca;
loglog(nu_list, L2err_nu);
axis padded

% Apparently no difference between different nu's. Cool

%% Test all three parameters together
l2err_pars = zeros(numel(beta_list), numel(xi_list), numel(nu_list));
wp_idx = zeros(numel(beta_list), numel(xi_list), numel(nu_list));
for i = 1:numel(beta_list)
    beta = beta_list(i);
    for j = 1:numel(xi_list)
        xi = xi_list(j);
        parfor k = 1:numel(nu_list)
            fdata = initializeForm(pdata, pdata.Q, 'CUSTOM', ...
                'BETA', beta, 'XI', xi, 'NU', nu_list(k));
            [u, ~] = SolverWaves(pdata, pdata.Q, mesh, ddata, fdata);
            err = ComputeErrors(u, pdata, mesh, ddata, 'relative');
            l2err_pars(i, j, k) = err.L2E;
            R = max([1./(nu_list(k)-1)*(pdata.Q.L/pdata.c/pdata.Q.T + 1), ...
                1./(nu_list(k) - 1)*pdata.Q.L/pdata.c/pdata.Q.T * ...
                (pdata.theta + 1 / (pdata.theta * pdata.Q.delta))]);
            if beta / xi >= R
                wp_idx(i, j, k) = 1;
            end
        end
    end
    fprintf('-> i = [%d / %d]\n', i, numel(beta_list));
end

%% check what difference does nu make.
% compute the diff of each l2error when nu changes, compute the max, if it
% relevant then ok, else we can claim this and ignore the parameter
nu_variance = nan(size(l2err_pars, [1, 2]));
nu_mean = nan(size(l2err_pars, [1,2]));
nu_min = nan(size(l2err_pars, [1, 2]));
nu_max = nan(size(l2err_pars, [1, 2]));

for i = 1:numel(beta_list)
    beta = beta_list(i);
    for j = 1:numel(xi_list)
        ids = wp_idx(i, j, :) == 1;
        ids = ids(:);
        good_errors = l2err_pars(i, j, ids);
        tmp = var(good_errors);
        nu_mean(i, j) = mean(good_errors); 
        if numel(good_errors) > 0
            nu_min(i, j) = min(good_errors);
            nu_max(i, j) = max(good_errors);
        end
        if isnan(tmp)
        else
            nu_variance(i, j) = tmp;
        end
    end
end
% plot everything
pcolor(nu_variance)
set(gca, 'ColorScale', 'log');
title('variance')
colorbar
figure
pcolor(nu_mean)
set(gca, 'ColorScale', 'log');
title('mean')
colorbar
figure
pcolor(nu_min)
set(gca, 'ColorScale', 'log');
title('min')
colorbar
figure
pcolor(nu_max)
set(gca, 'ColorScale', 'log');
title('max')
colorbar
%% plot in sequence of nu
figure
h = gca;
% Compute r_min as a function of nu
R_min = @(nu) max([1./(nu-1)*(pdata.Q.L/pdata.c/pdata.Q.T + 1), ...
    1./(nu - 1)*pdata.Q.L/pdata.c/pdata.Q.T * ...
    (pdata.theta + 1 / (pdata.theta * pdata.Q.delta))]);

for i = 1:numel(nu_list)
    surf(Xi, Beta, min(1,l2err_pars(:, :, i)));
    hold on
    scatter3(Xi, Beta, wp_idx(:, :, i), 'xw')
    hold off
    set(h, 'xscale', 'log');
    set(h, 'yscale', 'log');
    set(h, 'zscale', 'log');
    set(h,'ColorScale','log');
    set(h, 'ylim', [min(beta_list) max(beta_list)]);
    set(h, 'xlim', [min(xi_list) max(xi_list)]);
    colorbar
    view(2)
    pause
end

% compute ranges as a function of $nu$
minl2err = min(l2err_pars, [], [1,2]);
