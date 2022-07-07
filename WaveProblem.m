function problem = WaveProblem(prob_num)
    problem = struct();
    switch prob_num
        case 0
            %% Data functions
            problem.f   = @(x,t) x.* 0;
            problem.g   = @(x,t) x.*0;
            problem.u0  = @(x) x.*0;
            problem.u1  = @(x) x.*0;
            
            %% Parameters
            problem.c       = 1;
            problem.theta   = 1;
            
            %% Exact solution
            problem.u       = @(x,t) 0;
            problem.dx_u    = @(x,t) t.^2 .* (-pi*sin(pi*x));
            problem.dt_u    = @(x,t) 2 * t .* (cos(pi * x) + 1);
        case 1
            %% Data functions
            problem.f   = @(x,t) - 2 * (x.^2 + t.^2 - t - 1);
            problem.g   = @(x,t) x.*0;
            problem.u0  = @(x) x.*0;
            problem.u1  = @(x) x.*0;
            
            %% Parameters
            problem.c       = 1;
            problem.theta   = 1;
            
            %% Exact solution
            problem.u       = @(x,t) (x.^2 - 1) .* (t.^2 - t);
            problem.dx_u    = @(x,t) t.^2 .* (-pi*sin(pi*x));
            problem.dt_u    = @(x,t) 2 * t .* (cos(pi * x) + 1);
        case 3
            %% Data functions
            problem.f   = @(x,t) 2 * (cos(pi * x) + 1) + ...
                                t.^2 .* (pi^2 * cos(pi*x));
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
        case 4
            %% Data functions
            problem.f   = @(x,t) 2 * (cos(pi * x) + 1) .* cos(2*t) + ...
                        pi^2 * cos(pi * x) .* sin(t).^2;
            problem.g   = @(x,t) x.*0;
            problem.u0  = @(x) x.*0;
            problem.u1  = @(x) x.*0;
            
            %% Parameters
            problem.c       = 1;
            problem.theta   = 1;
            
            %% Exact solution
            problem.u    = @(x,t) sin(t).^2 .* (cos(pi*x) + 1);
            problem.dx_u = @(x,t) t.^2 .* (-pi*sin(pi*x));
            problem.dt_u = @(x,t) 2 * t .* (cos(pi * x) + 1);
        case 5
            %% Data functions
            problem.f   = @(x,t) x.*0 + 1;
            problem.g   = @(x,t) x.*0;
            problem.u0  = @(x) x.*0;
            problem.u1  = @(x) x.*0;
            
            %% Parameters
            problem.c       = 1;
            problem.theta   = 1;
            
            %% Exact solution
            problem.u    = @(x,t) sin(t).^2 .* (cos(pi*x) + 1);
            problem.dx_u = @(x,t) t.^2 .* (-pi*sin(pi*x));
            problem.dt_u = @(x,t) 2 * t .* (cos(pi * x) + 1);
        case 2
            %% Data functions
            problem.f   = @(x,t) 2*pi^2 * (sin(pi*x).*sin(pi*t));
            problem.g   = @(x,t) x.*0;
            problem.u0  = @(x) x.*0;
            problem.u1  = @(x) x.*0;
            
            %% Parameters
            problem.c       = 1;
            problem.theta   = 1;
            
            %% Exact solution
            problem.u       = @(x,t) (sin(pi*x).*sin(pi*t));
            problem.dx_u    = @(x,t) t.^2 .* (-pi*sin(pi*x));
            problem.dt_u    = @(x,t) 2 * t .* (cos(pi * x) + 1);
        otherwise
            %warning("No matching problem number");
    end
end