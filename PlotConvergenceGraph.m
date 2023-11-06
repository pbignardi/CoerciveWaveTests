function [] = PlotConvergenceGraph(H, L2, H1, Op, Kconds)
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

    lgd_entries = {}; 
    for err = ["l2", "h1", "op", "cond"]
        if err == "l2"
            loglog_plot(H, L2, "-d", linewidth, BLUE, markersize);
            p_l2 = polyfit(log(H(end-2:end)), log(L2(end-2:end)), 1);
            lgd_entries{end + 1} = strcat("L2 error - order: ", string(p_l2(1)));
            hold on, grid on
        elseif err == "h1"
            loglog_plot(H, H1, "-s", linewidth, RED, markersize);
            p_h1 = polyfit(log(H(end-2:end)), log(H1(end-2:end)), 1);
            lgd_entries{end + 1} = strcat("H1 error - order: ", string(p_h1(1)));
            hold on, grid on
        elseif err == "op"
            loglog_plot(H, Op, "-+", linewidth, PURPLE, markersize);
            p_op = polyfit(log(H(end-2:end)), log(Op(end-2:end)), 1);
            lgd_entries{end + 1} = strcat("LSQ error - order: ", string(p_op(1)));
            hold on, grid on
        elseif err == "cond"
            loglog(H,  1 ./ Kconds, "--", "Color", [0.3 0.3 0.3]);
            p_cond = polyfit(log(H(end-2:end)), - log(Kconds(end-2:end)),1);
            lgd_entries{end + 1} = strcat("1/cond(K) - order: ", string(p_cond(1)));
            hold on, grid on
        end
    end

    legend(lgd_entries, ...
        "Location", "southeast", "NumColumns", legend_cols);

    function loglog_plot(x, y, line_style, linewidth, color, markersize)
        loglog(x, y, line_style, ...
            "LineWidth", linewidth, ...
            "Color", color, ...
            "MarkerFaceColor", color, ...
            "MarkerSize", markersize)
    end

end