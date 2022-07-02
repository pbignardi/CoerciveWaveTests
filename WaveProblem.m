function problem = WaveProblem()
    problem = struct();
    
    problem.f = @(x,t) x.*0 + 1;
    problem.g = @(x,t) x.*0;
    problem.u0 = @(x) x.*0;
    problem.u1 = @(x) x.*0;
    
    problem.u_ex = @(x,t) t.^2 .* (cos(pi * x) + 1);
    problem.dx_u_ex = @(x,t) t.^2 .* (-pi*sin(pi*x));
    problem.dt_u_ex = @(x,t) 2 * t .* (cos(pi * x) + 1);
end