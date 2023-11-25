function form = FormParameters(problem, options)
% Initialize struct with all formulation parameters. Allows for choice
% of optimal parameters, generic and custom.
% Default values of BETA, XI and NU are given by (43).
%
% 'opt' ParType: A = 1e-2, A0 = 1; (default)
% 'gen' ParType: A = 1, A0 = 1;
%
% ACHTUNG: changing XI and NU, will also change the value of BETA.
%
% INPUTS:
%   problem: (struct) struct of the problem
%
% NAME-VALUE INPUTS: (optional)
%   ParType: (string) either 'opt', 'gen' or 'custom'
%   BETA: (float) Multiplier coefficient \beta in (28)
%   XI: (float) Multiplier coefficient \xi in (28)
%   NU: (float) Multiplier coefficient \nu in (28)
%   A: (float) Least squares coefficient A_Q in (28)
%   A0: (float) Least squares coefficient A_\OZ in (28)
%
% OUTPUT:
%   form: (struct) structure of parameters of the formulation

arguments
    problem
    options.ParType = 'opt'
    options.XI (1, 1) double { mustBeNumeric } = 1
    options.NU (1, 1) double { mustBeNumeric } = 2
    options.A (1, 1) double { mustBeNumeric } = 1e-2
    options.A0 (1, 1) double { mustBeNumeric } = 1
    options.BETA (1, 1) double { mustBeNumeric }
end

form = struct('XI', options.XI, 'NU', options.NU);

if strcmpi(options.ParType, 'opt')
    form.A = 1e-2;
    form.A0 = 1;
elseif strcmpi(options.ParType, 'gen')
    form.A = 1;
    form.A0 = 1;
else
    form.A = options.A;
    form.A0 = options.A0;
end

if isfield(options, 'BETA')
    form.BETA = options.BETA;
else
    form.BETA = form.XI / (form.NU - 1) * max([
        problem.Q.L/(problem.c*problem.Q.T) + 1, ...
        problem.Q.L/(problem.c*problem.Q.T) * ...
        (problem.theta + (problem.Q.delta * problem.theta)^(-1))]);
end
end
