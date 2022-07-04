function problem = WaveProblem(prob_num)
    problem = struct();
    switch prob_num
        case 1
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
        case 2
            %% Data functions
            problem.f   = @(x,t) t.^2 * (cos(pi*x) + 1);
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
        otherwise
            warning("No matching problem number");
    end
end