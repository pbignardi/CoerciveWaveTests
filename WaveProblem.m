function problem = WaveProblem()
    problem = struct();
    %% Data functions
    problem.f   = @(x,t) x.*0 + 1;
    problem.g   = @(x,t) x.*0;
    problem.u0  = @(x) x.*0;
    problem.u1  = @(x) x.*0;
    
    %% Parameters
    problem.c       = 1;
    problem.theta   = 1;
    
    %% Exact solution
    problem.u       = @(x,t) t.^2 .* (cos(pi * x) + 1);
    problem.dx_u    = @(x,t) t.^2 .* (-pi*sin(pi*x));
    problem.dt_u    = @(x,t) 2 * t .* (cos(pi * x) + 1);
end