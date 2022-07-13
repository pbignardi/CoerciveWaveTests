function problem = WaveProblem(prob_num)
    problem = struct();
    switch prob_num
        %% Null problem
        case 0
            % Data functions
            problem.f   = @(x,t) x.* 0;
            problem.g   = @(x,t) x.*0;
            problem.u0  = @(x) x.*0;
            problem.u1  = @(x) x.*0;
            
            % Parameters
            problem.c       = 1;
            problem.theta   = 1;
            
            % Exact solution
            problem.u       = @(x,t) 0;
            problem.dx_u    = @(x,t) t.^2 .* (-pi*sin(pi*x));
            problem.dt_u    = @(x,t) 2 * t .* (cos(pi * x) + 1);
        %% Dirichlet Poisson problem
        case 1
            % Data functions
            problem.f   = @(x,t) - 2 * (x.^2 + t.^2 - t - 1);
            problem.g   = @(x,t) x.*0;
            problem.u0  = @(x) x.*0;
            problem.u1  = @(x) x.*0;
            
            % Parameters
            problem.c       = 1;
            problem.theta   = 1;
            
            % Exact solution
            problem.u       = @(x,t) (x.^2 - 1) .* (t.^2 - t);
            problem.dx_u    = @(x,t) t.^2 .* (-pi*sin(pi*x));
            problem.dt_u    = @(x,t) 2 * t .* (cos(pi * x) + 1);
        %% Plane wave problem
        case 2
            % Data functions
            problem.f   = @(x,t) x.*0;
            problem.g   = @(x,t) x.*0 + t.*0;
            problem.u0  = @(x) -5*sin(5*x);
            problem.u1  = @(x) sin(5*x);
            
            % Parameters
            problem.c       = 5;
            problem.theta   = 0.01;
            
            % Exact solution
            problem.u       = @(x,t) (sin(pi*x).*sin(pi*t));
            problem.dx_u    = @(x,t) t.^2 .* (-pi*sin(pi*x));
            problem.dt_u    = @(x,t) 2 * t .* (cos(pi * x) + 1);
        %% Homogeneous boundary wave problem 1
        case 3
            % Data functions
            problem.f   = @(x,t) 2 * (cos(pi * x) + 1) + ...
                                t.^2 .* (pi^2 * cos(pi*x));
            problem.g   = @(x,t) x.*0;
            problem.u0  = @(x) x.*0;
            problem.u1  = @(x) x.*0;
            
            % Parameters
            problem.c       = 1;
            problem.theta   = 1;
            
            % Exact solution
            problem.u       = @(x,t) t.^2 .* (cos(pi * x) + 1);
            problem.dx_u    = @(x,t) t.^2 .* (-pi*sin(pi*x));
            problem.dt_u    = @(x,t) 2 * t .* (cos(pi * x) + 1);
            problem.ddt_u   = @(x,t) 2*cos(pi*x) + 2;
            problem.ddx_u   = @(x,t) -t.^2 .* cos(pi*x) * pi^2;
        %% Homogeneous boundary wave problem 2
        case 4
            % Data functions
            problem.f   = @(x,t) 2 * (cos(pi * x) + 1) .* cos(2*t) + ...
                        pi^2 * cos(pi * x) .* sin(t).^2;
            problem.g   = @(x,t) x.*0;
            problem.u0  = @(x) x.*0;
            problem.u1  = @(x) x.*0;
            
            % Parameters
            problem.c       = 1;
            problem.theta   = 1;
            
            % Exact solution
            problem.u       = @(x,t) sin(t).^2 .* (cos(pi*x) + 1);
            problem.dx_u    = @(x,t) -pi*sin(pi*x).*sin(t).^2;
            problem.dt_u    = @(x,t) 2*cos(t).*sin(t).*(cos(pi*x) + 1);
            problem.ddt_u   = @(x,t) 2*cos(t).^2.*(cos(pi*x) + 1) - ...
                2*sin(t).^2 .* (cos(pi*x) + 1);
            problem.ddx_u   = @(x,t) -pi^2 * cos(pi*x) .* sin(t).^2;
        %% Non-homogeneous boundary
        case 5
            % Data functions
            problem.f   = @(x,t) x.*0;
            problem.g   = @(x,t) x.*0;
            problem.u0  = @(x) -sin(x);
            problem.u1  = @(x) x.*0;
            
            % Parameters
            problem.c       = 1;
            problem.theta   = 1;
            
            % Exact solution
            problem.u    = @(x,t) sin(t).^2 .* (cos(pi*x) + 1);
            problem.dx_u = @(x,t) t.^2 .* (-pi*sin(pi*x));
            problem.dt_u = @(x,t) 2 * t .* (cos(pi * x) + 1);
        otherwise
            %warning("No matching problem number");
    end
end