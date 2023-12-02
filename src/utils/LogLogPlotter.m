function LogLogPlotter(data, options)
% Base function to plot in loglog with consistent styling
% 
% INPUT
%   data: (table) with any columns. First column is the x's. Everything
%       else is take as y's. 
%   options.DashedIds: (int[]) id of cols with dashed line (none by default)
%   options.LegendText: (string[]) Text for each entry
%   options.Title: (string) title of the figure
%   options.Subtitle: (string) subtitle of the figure
%   options.xLabel: (string)
%   options.yLabel: (string)
%   options.ShowRates: (bool) show computed convergence rates
%   options.Pairs: (cell) pairs of columns with same color.

arguments
    data
    options.LegendText = []
    options.DashedIds {mustBeInteger} = []
    options.Title = ''
    options.Subtitle = ''
    options.xLabel = ''
    options.yLabel = ''
    options.ShowRates = false
end

% internals parameters
font_size = 18;
title_font_size = 20;
figure_width = 960;
figure_height  = 720;
marker_styles = ['x', 's', '^', 'd'];
color_scheme = colororder;

% get number of columns
nColumns = size(data, 2);
% first column is x's
xData = data.(1);

% initialize figure
figure
title(options.Title, FontSize=title_font_size);
subtitle(options.Subtitle, FontSize=font_size);
fontsize(gcf, font_size, 'points');
set(gcf, 'Position', [1, 1, figure_width, figure_height]);
set(gca, 'xscale', 'log');
set(gca, 'yscale', 'log');
axis padded
xlabel(options.xLabel, FontSize=font_size, Interpreter='latex');
ylabel(options.yLabel, FontSize=font_size, Interpreter='latex');

hold on
icolor = 1;
for idata = 2:nColumns
    if ismember(idata, options.DashedIds)
        continue
    end
    c = color_scheme(icolor, :);
    marker = marker_styles(icolor);
    if options.ShowRates == true
        rates = diff(log(data.(idata)))./diff(log(xData));
        xpos = xData(2:end)+ 0.1*xData(2:end);
        ypos = data.(idata)(2:end);
        rate_text = string(round(rates, 2));
        text(xpos, ypos, rate_text, Margin=10, FontSize=font_size);
    end
    loglog(xData, data.(idata), Color=c, LineWidth=2, MarkerSize=9, ...
        Marker=marker);
    icolor = icolor + 1;
end
% draw dashed lines
icolor = 1;
for idata = 2:nColumns
    if ~ismember(idata, options.DashedIds)
        continue
    end
    c = color_scheme(icolor, :);
    loglog(xData, data.(idata), '--', Color=c, LineWidth=2, MarkerSize=9);
    icolor = icolor + 1;
end
hold off
grid on

% add legend
legend(options.LegendText{:}, Location='southeast', FontSize=font_size, ...
    Interpreter='latex');
end
