% Paolo Bignardi - Dec 2023
function quasi_opt_const = QuasiOptConstant(problem, form)
% QuasiOptConstant: Compute the quasi optimality constant for given problem and 
% formulation parameters
%
% INPUT:
%   problem: (struct) output of WaveProblem.m
%   form: (struct) formulation parameters. output of FormParameters.m 
%
% OUTPUT:
%   quasi_opt_const: (float) Quasi optimality constant (see eq (36) and (41))

%% Unpack parameters
c       = problem.c;
THETA   = problem.theta;
T       = problem.Q.T;
L       = problem.Q.L;
BETA    = form.BETA;
NU      = form.NU;
XI      = form.XI;
delta   = problem.Q.delta;

%% Continuity constant of $b$
continuity_const = sqrt(3) * max([BETA + XI + BETA * NU, ...
    XI*L/(c*T) + BETA + 2*XI - XI, ...
    BETA * (NU - 1) + XI * L / (c*T), ...
    (1/THETA + 1)*(BETA*NU*c*T/L + XI), ...
    2*XI, ...
    form.A, ...
    form.A0]);
%% Coercivity constant of $b$
coercivity_const = min([delta*XI/4, form.A, form.A0]); 

%% Quasi optimality constant
quasi_opt_const = continuity_const / coercivity_const;
end
