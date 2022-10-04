function problem = WaveProblem(prob_num)
    problem = struct();
    switch prob_num
        %% Null problem
        case 0
            % Data functions
            problem.f   = @(x,t) 2 * pi^2 * sin(pi * x) .* sin(pi * t);
            problem.g   = @(x,t) x.*0;
            problem.du0 = @(x) x.*0;
            problem.u1  = @(x) x.*0;
            
            % Parameters
            problem.c       = 1;
            problem.theta   = 1;
            
            % Exact solution
            problem.u       = @(x,t) sin(pi * x) .* sin(pi * t);
            problem.dx_u    = @(x,t) pi * cos(pi * x) .* sin(pi * t);
            problem.dt_u    = @(x,t) pi * cos(pi * t) .* sin(pi * x);
            problem.ddt_u   = @(x,t) -pi^2 * sin(pi * x) .* sin(pi * t);
            problem.ddx_u   = @(x,t) -pi^2 * sin(pi * x) .* sin(pi * t);
        %% Dirichlet Poisson problem
        case 1
            % Data functions
            a = 1000;
            % Define gaussian and derivatives
            n   = @(x, c) exp(-a*(x - c).^2);

            problem.f   = @(x,t) n(x, 0) .* sin(pi * 4 * t);
            problem.g   = @(x,t) x.*0;
            problem.du0 = @(x) x.*0;
            problem.u0  = @(x) x.*0;
            problem.u1  = @(x) x.*0;
            
            % Parameters
            problem.c       = 1;
            problem.theta   = 4;
            
            % Exact solution
            problem.u       = @(x,t) (x.^2 - 1) .* (t.^2 - t);
            problem.dx_u    = @(x,t) t.^2 .* (-pi*sin(pi*x));
            problem.dt_u    = @(x,t) 2 * t .* (cos(pi * x) + 1);
        %% Plane wave problem
        case 2
            % Data functions
            problem.f   = @(x,t) x.*0;
            problem.g   = @(x,t) x.*0 + t.*0;
            problem.du0  = @(x) -5*sin(5*x);
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
            problem.du0 = @(x) x.*0;
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
            problem.du0 = @(x) x.*0;
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
            problem.du0  = @(x) -sin(x);
            problem.u1  = @(x) x.*0;
            
            % Parameters
            problem.c       = 1;
            problem.theta   = 1;
            
            % Exact solution
            problem.u    = @(x,t) sin(t).^2 .* (cos(pi*x) + 1);
            problem.dx_u = @(x,t) t.^2 .* (-pi*sin(pi*x));
            problem.dt_u = @(x,t) 2 * t .* (cos(pi * x) + 1);
        %% Exact solution is in discrete space
        case 6
            % Data functions
            problem.f   = @(x,t) 2*x.^2 - 2*t.^2;
            problem.g   = @(x,t) 2 * abs(x) .* t.^2 + 2 * x.^2 .* t;
            %problem.g   = @(x,t) x.*0 + t.*0;
            problem.du0 = @(x) x.*0;
            problem.u1  = @(x) x.*0;

            %Parameters
            problem.c       = 1;
            problem.theta   = 1;

            % Exact solution
            problem.u       = @(x,t) x.^2 .* t.^2;
            problem.dx_u    = @(x,t) 2*x.*t.^2;
            problem.dt_u    = @(x,t) 2*t.*x.^2;
            problem.ddx_u   = @(x,t) 2*t.^2;
            problem.ddt_u   = @(x,t) 2*x.^2;
        %% Bouncing wave (variable theta)
        case 7
            c = 2;
            problem.c       = c;
            problem.theta   = 4;
            phi = (1 - 1/problem.theta)/(1 + 1/problem.theta);

            problem.f   = @(x,t) x.*0 + t.*0;
            problem.g   = @(x,t) x.*0 + t.*0;
            a = 20;
            % Define gaussian and derivatives
            n   = @(x, c) exp(-a*(x - c).^2);
            dn  = @(x, c) a*exp(-a*(c - x).^2).*(2*c - 2*x);
            ddn = @(x, c) a^2*exp(-a*(c - x).^2).*(2*c - 2*x).^2 - ... 
                            2*a*exp(-a*(c - x).^2);
            % Define initial wave
            w   = @(x) n(x, 0.1) - n(x, -0.1);
            dw  = @(x) dn(x, 0.1) - dn(x, -0.1); 
            ddw = @(x) ddn(x, 0.1) - ddn(x, -0.1);

            problem.du0 = @(x) dw(x) - phi * dw(2 - x);
            problem.u0  = @(x) w(x) + phi * w(2 - x);
            problem.u1  = @(x) - c * dw(x) - c * phi * dw(2 - x);

            problem.u       = @(x,t) w(x - c*t) + phi * w(2 - x - c*t);
            problem.dx_u    = @(x,t) dw(x - c*t) - phi * dw(2 - x - c*t);
            problem.dt_u    = @(x,t) -c * dw(x - c*t) - ...
                                     c * phi * dw(2 - x - c*t);
            problem.ddx_u   = @(x,t) ddw(x - c*t) + phi * ddw(2 - x - c*t);
            problem.ddt_u   = @(x,t) c^2*(ddw(x - c*t) + phi * ddw(2 - x - c*t));
        case 8
            c = 2;
            problem.c       = c;
            problem.theta   = 100;
            phi = (1 - 1/problem.theta)/(1 + 1/problem.theta);

            problem.f   = @(x,t) x.*0 + t.*0;
            problem.g   = @(x,t) x.*0 + t.*0;
            a = 20;
            % Define gaussian and derivatives
            n   = @(x, c) exp(-a*(x - c).^2);
            dn  = @(x, c) a*exp(-a*(c - x).^2).*(2*c - 2*x);
            ddn = @(x, c) a^2*exp(-a*(c - x).^2).*(2*c - 2*x).^2 - ... 
                            2*a*exp(-a*(c - x).^2);
            % Define initial wave
            w   = @(x) n(x, 0.1) - n(x, -0.1);
            dw  = @(x) dn(x, 0.1) - dn(x, -0.1); 
            ddw = @(x) ddn(x, 0.1) - ddn(x, -0.1);

            problem.du0  = @(x) dw(x) - phi * dw(2 - x);
            problem.u1  = @(x) - c * dw(x) - c * phi * dw(2 - x);

            problem.u       = @(x,t) w(x - c*t) + phi * w(2 - x - c*t);
            problem.dx_u    = @(x,t) dw(x - c*t) - phi * dw(2 - x - c*t);
            problem.dt_u    = @(x,t) -c * dw(x - c*t) - ...
                                     c * phi * dw(2 - x - c*t);
            problem.ddx_u   = @(x,t) ddw(x - c*t) + phi * ddw(2 - x - c*t);
            problem.ddt_u   = @(x,t) c^2*(ddw(x - c*t) + phi * ddw(2 - x - c*t));
        case 9
            c = 2;
            problem.c       = c;
            problem.theta   = 1;
            phi = (1 - 1/problem.theta)/(1 + 1/problem.theta);

            problem.f   = @(x,t) x.*0 + t.*0;
            problem.g   = @(x,t) x.*0 + t.*0;
            a = 20;
            % Define gaussian and derivatives
            n   = @(x, c) exp(-a*(x - c).^2);
            dn  = @(x, c) a*exp(-a*(c - x).^2).*(2*c - 2*x);
            ddn = @(x, c) a^2*exp(-a*(c - x).^2).*(2*c - 2*x).^2 - ... 
                            2*a*exp(-a*(c - x).^2);
            % Define initial wave
            w   = @(x) n(x, 0.1) - n(x, -0.1);
            dw  = @(x) dn(x, 0.1) - dn(x, -0.1); 
            ddw = @(x) ddn(x, 0.1) - ddn(x, -0.1);

            problem.du0  = @(x) dw(x) - phi * dw(2 - x);
            problem.u1  = @(x) - c * dw(x) - c * phi * dw(2 - x);

            problem.u       = @(x,t) w(x - c*t) + phi * w(2 - x - c*t);
            problem.dx_u    = @(x,t) dw(x - c*t) - phi * dw(2 - x - c*t);
            problem.dt_u    = @(x,t) -c * dw(x - c*t) - ...
                                     c * phi * dw(2 - x - c*t);
            problem.ddx_u   = @(x,t) ddw(x - c*t) + phi * ddw(2 - x - c*t);
            problem.ddt_u   = @(x,t) c^2*(ddw(x - c*t) + phi * ddw(2 - x - c*t));
        case 10
            c = 2;
            problem.c       = c;
            problem.theta   = 1;
            phi = (1 - 1/problem.theta)/(1 + 1/problem.theta);

            problem.f   = @(x,t) x.*0 + t.*0;
            problem.g   = @(x,t) x.*0 + t.*0;
            a = 20;
            % Define gaussian and derivatives
            n   = @(x, c) exp(-a*(x - c).^2);
            dn  = @(x, c) a*exp(-a*(c - x).^2).*(2*c - 2*x);
            ddn = @(x, c) a^2*exp(-a*(c - x).^2).*(2*c - 2*x).^2 - ... 
                            2*a*exp(-a*(c - x).^2);
            % Define initial wave
            w   = @(x) n(x, 0.1) - n(x, -0.1);
            dw  = @(x) dn(x, 0.1) - dn(x, -0.1); 
            ddw = @(x) ddn(x, 0.1) - ddn(x, -0.1);

            problem.du0  = @(x) dn(x, 0);
            problem.u1  = @(x) x.*0;

            problem.u       = @(x,t) w(x - c*t) + phi * w(2 - x - c*t);
            problem.dx_u    = @(x,t) dw(x - c*t) - phi * dw(2 - x - c*t);
            problem.dt_u    = @(x,t) -c * dw(x - c*t) - ...
                                     c * phi * dw(2 - x - c*t);
            problem.ddx_u   = @(x,t) ddw(x - c*t) + phi * ddw(2 - x - c*t);
            problem.ddt_u   = @(x,t) c^2*(ddw(x - c*t) + phi * ddw(2 - x - c*t));
        otherwise
            %warning("No matching problem number");
    end
end