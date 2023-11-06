function form = initializeForm(problem, domain, par_type, varargin)
% Initialize formulation struct with all the parameters. Allows for choice
% of optimal parameters, generic and custom.
% Optimal parameters are given by smallest BETA for coercivity, XI = 1,
% NU = 2, and A = 1e-2, A0 = 1e3; generic pars are given for A = A0 = 1.
% For custom pars, starting from optimal specify the pars to change using
% key-value pairs. Unspecified pars are kept as default.
% ACHTUNG: changing XI and NU, will also change the value of BETA.
%
% INPUT:
%   problem: (struct) struct of the problem
%   domain: (struct) struct of the domain
%   par_type: (string) possible values: 
%           - 'opt' for optimal pars, 
%           - 'gen' for generic pars, 
%           - 'custom' for specifying key-value pairs of pars to change.
%
% KWARGS (optional):  
%   BETA: (float) change value of \BETA from its optimal value
%   XI: (float) change value of \XI from its optimal value
%   NU: (float) change value of \NU from its optimal value 
%   A: (float) change value of A_Q from its optimal value (1e-2)
%   A0: (float) chagne value of A_\OZ from its optimal value
%
% OUTPUT:
%   form: (struct) structure of parameters of the formulation

%% Construct optimal values formulation parameters
form = struct('XI', 1, 'NU', 2, 'A', 1e-2, 'A0', 1e3);
if strcmpi(par_type, 'GEN')
    form.A = 1; form.A0 = 1;
end

optionNames = {'BETA', 'XI', 'NU', 'A', 'A0'};
if ~isempty(varargin)
    inputNames = varargin(1:2:end);
end
for pair = reshape(varargin, 2, [])
    pName = upper(pair{1});
    if any(strcmpi(pName, optionNames))
        form.(pName) = pair{2};
    end
end

% compute BETA at the end if no BETA has been provided
if isempty(varargin) || ~any(strcmpi('BETA', inputNames)) 
    form.BETA = form.XI / (form.NU - 1) * max([
        domain.L/(problem.c*domain.T) + 1, ...
        domain.L/(problem.c*domain.T) * ...
        (problem.theta + (domain.delta * problem.theta)^(-1))]);
end