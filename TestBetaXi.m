%% Test with beta = xi = 1
[err3, ~] = Convergence(3, 'PAR_TYPE', 'CUSTOM', 'BETA', 1, 'XI', 1);
[err2, ~] = Convergence(2, 'PAR_TYPE', 'CUSTOM', 'BETA', 1, 'XI', 1);

%% Compute quasi optimality constant in that case (theoretical and numerical)
qo_3 = {err3.L2errors ./ err3.L2projErrors, ...
    err3.H1errors ./ err3.H1projErrors, ... 
    err3.Verrors ./ err3.VprojErrors};
qo_2 = {err2.L2errors ./ err2.L2projErrors, ...
    err2.H1errors ./ err2.H1projErrors, ... 
    err2.Verrors ./ err2.VprojErrors};
qo_table_3 = table(qo_3{:});
qo_table_2 = table(qo_2{:});


%% Fix xi or not?
pnum = 3;
N = 1;
xi_list = logspace(-3, 3, 7*(2*N+1));
% ratio_list = logspace(0, 4, numel(xi_list)); % beta / xi
beta_list = logspace(-5, 5, numel(xi_list));
pdata = WaveProblem(pnum);
ddata = Discretization(32, 32, pdata.Q);
mesh = CartesianMesh(ddata);

R_min = @(nu) max([1./(nu-1)*(pdata.Q.L/pdata.c/pdata.Q.T + 1), ...
    1./(nu - 1)*pdata.Q.L/pdata.c/pdata.Q.T * ...
    (pdata.theta + 1 / (pdata.theta * pdata.Q.delta))]);


%% 2d surf plot

l2err_beta_xi_comb = zeros(numel(xi_list), numel(beta_list));
wp_idx = zeros(numel(xi_list), numel(beta_list));
for i = 1:numel(beta_list)
    beta = beta_list(i);
    parfor j = 1:numel(xi_list)
        xi = xi_list(j);
        % [err_table, ~] = Convergence(pnum, 'PAR_TYPE', 'CUSTOM', ...
        %     'BETA', beta, 'XI', xi, 'N', 2.^(1:6), ...
        %     'PLOT', false, 'VERBOSE', false);
        fdata = initializeForm(pdata, pdata.Q, 'CUSTOM', ...
            'BETA', beta, 'xi', xi);
        [u, ~] = SolverWaves(pdata, pdata.Q, mesh, ddata, fdata);
        err = ComputeErrors(u, pdata, mesh, ddata, 'relative');
        % l2err_beta_xi_comb(j, i) = err_table.L2errors(end-1);
        l2err_beta_xi_comb(j, i) = err.L2E;
        % if CheckConvergence(err_table, 3, 4, 3, 2, 1e-1)
        %     wp_idx(j, i) = 1;
        % end
    end
    fprintf('-> i = [%d / %d]\n', i, numel(beta_list));
end

%% Make plot
[Beta, Xi] = meshgrid(beta_list, xi_list);
l2err_comb = figure;
fs = 20;                                                       
h = gca;
surf(Beta, Xi, min(l2err_beta_xi_comb, 1));
hold on
scatter3(Beta, Xi, 2 * (Beta ./ Xi < R_min(2)), 'xw', 'LineWidth', 1);
scatter3(Beta, Xi, wp_idx, 'og', 'LineWidth', 1);
set(h, 'xscale', 'log');
set(h, 'yscale', 'log');
set(h, 'zscale', 'log');
set(h,'ColorScale','log');
set(h, 'xlim', [min(beta_list) max(beta_list)]);
set(h, 'ylim', [min(xi_list) max(xi_list)]);
fontsize(fs, 'points');
xlabel('$\beta$',Interpreter='latex');
ylabel('$\xi$',Interpreter='latex');
clim([min(l2err_beta_xi_comb(:)) 1]);
c = colorbar;
set(c,'TickLabelInterpreter','latex');
view(2)
shading flat
colormap turbo

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
nu_list = logspace(0.1, 2, 4);
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
