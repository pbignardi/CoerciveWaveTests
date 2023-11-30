function ShowConvergencePlot(conv_table, options)
% Helper function to show h-convergence plot. 
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
%   options.ShowRates; (bool) show computed convergence rates
arguments
    conv_table
    options.Form
    options.Problem
    options.Title = ''
    options.Subtitle = ''
    options.ShowRates = true
end
if isfield(options, 'Problem')
    p_id = options.Problem.pnum;
    options.Title = sprintf('Convergence plot - Problem %d', p_id);
end
if isfield(options, 'Form')
    separators = {'=', ' ', '=', ' ', '=', ' ', '=', ' ', '='};
    options.Subtitle = join(string(namedargs2cell(options.Form)), separators);
end

% define dashed lines for best approximation errors
dashed = [4, 5, 6];
% construct legend text
legend_text = {'$L^2$ error', '$H^1$ error', '$V$-norm error', ...
    '$L^2$ best-approx error', '$H^1$ best-approx error', ...
    '$V$-norm best-approx error'};
to_plot_table = conv_table(:, [1, 4:9])
LogLogPlotter(to_plot_table, LegendText=legend_text, DashedIds=dashed, ...
    Title=options.Title, Subtitle=options.Subtitle, xLabel='h', ...
    ShowRates=options.ShowRates)
end
