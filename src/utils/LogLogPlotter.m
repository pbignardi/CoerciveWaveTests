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
solid_line_style = ['-x'; '-s'; '-^'; '-d'];
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
xlabel(options.xLabel, FontSize=font_size);
ylabel(options.yLabel, FontSize=font_size);

hold on
ic = 1;
for i = 2:nColumns
    if i == min(options.DashedIds)
        ic = 1;
    end
    c = color_scheme(ic, :);
    if any(options.DashedIds(:) == i)
        style = '--';
    else
        style = solid_line_style(i, :);
        if options.ShowRates == true
            rates = diff(log(data.(i)))./diff(log(xData));
            xpos = xData(2:end)+ 0.1*xData(2:end);
            ypos = data.(i)(2:end);
            rate_text = string(round(rates, 2));
            text(xpos, ypos, rate_text, Margin=10, FontSize=font_size);
        end
    end
    loglog(xData, data.(i), style, Color=c, LineWidth=2, MarkerSize=9);
    ic = ic + 1;
end
hold off
grid on

% add legend
legend(options.LegendText, Location='southeast', FontSize=font_size);
end
