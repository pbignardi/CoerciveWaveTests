%Plot the exact solutions of each problem \in [1, 2, 4, 5]
% Number of points in X-direction
Nx = 200;
% Number of points in T-direction
Nt = 200;

set(groot,'defaultAxesTickLabelInterpreter','latex'); 
set(groot,'defaulttextinterpreter','latex');
set(groot,'defaultLegendInterpreter','latex');
set(0,'DefaultTextInterpreter','latex')
set(0,'DefaultLegendInterpreter','latex')

for p_num = [1, 2, 3, 6]
    p = WaveProblem(p_num);
    Q = p.Q;
    [XX, TT] = meshgrid(linspace(Q.xmin, Q.xmax, Nx), linspace(0, Q.T, Nt));
    UU = p.u(XX, TT);
    
    sol_plot = figure;
    pcolor(XX, TT, UU);
    ax = gca;
    fontsize(ax, 24, 'points');
    colormap turbo;
    c = colorbar;
    fontsize(c, 24, 'points');
    set(c,'TickLabelInterpreter','latex')
    if ismember(p_num, [1, 2])
        clim([-1.7 1.7]);
    else
        clim([-1 1]);
    end
    xlabel(ax, '$x$');
    ylabel(ax, '$t$');
    shading flat

    % Save to file the figure
    root_dir = "Results/SolutionPlots/";
    base_filename = "solPlot-p" + string(p_num);
    
    exportgraphics(sol_plot, root_dir + base_filename + '.png', 'Resolution', 300);
end