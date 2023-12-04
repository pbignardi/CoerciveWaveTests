% Paolo Bignardi - Dec 2023
function ShowCFLTestPlot(conv_table, options)
% Helper function to show CFL test plot
% Optionally you can provide Form: the Subtitle now shows the parameters used
% Optionally you can provide Form: the Title now shows the problem solved
% 
% INPUT
%   data: (table) convergence table (see Convergence.m )
%   problem: (struct) description of the problem
%   form: (struct) parameters of the formulation 
%   options.Form: (struct) formulation parameters
%   options.Problem (struct) problem to solve 
%   options.Title: (string) title of the figure
%   options.Subtitle; (string) subtitle of the figure
arguments
    conv_table
    options.Form
    options.Problem
    options.Title = ''
    options.Subtitle = ''
end
if isfield(options, 'Problem')
    p_id = options.Problem.pnum;
    options.Title = sprintf('Unconditional stability plot - Problem %d', p_id);
end
if isfield(options, 'Form')
    separators = {'=', ' ', '=', ' ', '=', ' ', '=', ' ', '='};
    options.Subtitle = join(string(namedargs2cell(options.Form)), separators);
end

% construct legend text
legend_text = {'$L^2$ error', '$H^1$ error'}
conv_table.HtHxRatio = conv_table.Ht./conv_table.Hx;
to_plot_table = [conv_table(:, end) conv_table(:, 4) conv_table(:, 5)]
LogLogPlotter(to_plot_table, LegendText=legend_text, Title=options.Title, ... 
    Subtitle=options.Subtitle, xLabel='$h_t/h_x$')
end
