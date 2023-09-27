function quasi_opt_const = QuasiOptConstant(problem, form)
% Compute quasi-optimality constant of the interior impedance problem
%% Unpack parameters
c       = problem.c;
theta   = problem.theta;
T       = problem.Q.T;
L       = problem.Q.L;
BETA    = form.BETA;
NU      = form.NU;
XI      = form.XI;
delta   = problem.Q.delta;

%% Continuity constant of $b$
continuity_const = sqrt(3) * max([BETA + XI + BETA * NU, ...
    BETA + XI + XI*L/(c*T), ...
    BETA*(NU-1) + XI*L/(c*T), ...
    (1/theta+1)*(BETA*NU*c*T/L + XI), ...
    2*XI, ...
    form.A, ...
    form.A0]);
%% Coercivity constant of $b$
coercivity_const = min([delta*XI/4, form.A, form.A0]); 

%% Quasi optimality constant
quasi_opt_const = continuity_const / coercivity_const;
end