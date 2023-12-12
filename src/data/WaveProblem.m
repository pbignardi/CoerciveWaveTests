% Paolo Bignardi - Dec 2023
function problem = WaveProblem(prob_num)
    problem = struct();
    problem.pnum = prob_num;
    switch prob_num
        %% Homogeneous boundary wave problem 2
        case 1
            % Problem domain
            problem.Q   = Domain(-1, 1, 1);
            % Data functions
            problem.f   = @(x,t) 2*cos(t).^2.*(cos(pi*x) + 1) - ...
                2*sin(t).^2.*(cos(pi*x) + 1) + pi^2*cos(pi*x).*sin(t).^2;
            problem.gI  = @(x,t) x.*0 + t.*0;
            problem.gD  = @(x,t) x.*0 + t.*0;
            problem.du0 = @(x) x.*0;
            problem.u0  = @(x) x.*0;
            problem.u1  = @(x) x.*0;
            
            % Parameters
            problem.c       = 1;
            problem.theta   = 1;
            
            % Exact solution
            problem.u       = @(x,t) sin(t).^2.*(cos(pi*x) + 1);
            problem.dx_u    = @(x,t) -pi*sin(pi*x).*sin(t).^2;
            problem.dt_u    = @(x,t) 2*cos(t).*sin(t).*(cos(pi*x) + 1);
            problem.ddt_u   = @(x,t) 2*cos(t).^2.*(cos(pi*x) + 1) - ...
                2*sin(t).^2.*(cos(pi*x) + 1);
            problem.ddx_u   = @(x,t) -pi^2*cos(pi*x).*sin(t).^2;

        %% Impedance interior problem
        case 2
            % Problem domain
            problem.Q   = Domain(-1, 1, 1);
            % Problem data
            c = 2;
            problem.c       = c;
            problem.theta   = 10;
            phi = (1 - 1/problem.theta)/(1 + 1/problem.theta);

            problem.f   = @(x,t) x.*0 + t.*0;
            problem.gI  = @(x,t) x.*0 + t.*0;
            problem.gD  = @(x,t) x.*0 + t.*0;

            a = 30;
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

        %% Corner singularity travelling through the domain.
        % In this case the solution should be in H1 but not in H2, as there
        % is a sharp angle in the corner at t=0.
        case 3
            c = 1;
            problem.Q       = Domain(-1, 1, 1);
            problem.c       = c;
            problem.theta   = 1;
            problem.f       = @(x, t) x.*0 + t .* 0;
            problem.gI      = @(x, t) x.*0 + t .* 0;
            problem.gD      = @(x, t) x.*0 + t .* 0;
            
            phi = (1 - 1/problem.theta)/(1 + 1/problem.theta);

            a = 20;
            % Define gaussian and derivatives
            n   = @(x, c) exp(-a*(x - c).^2);
            dn  = @(x, c) a*exp(-a*(c - x).^2).*(2*c - 2*x);
            ddn = @(x, c) a^2*exp(-a*(c - x).^2).*(2*c - 2*x).^2 - ... 
                            2*a*exp(-a*(c - x).^2);
            % Define initial wave
            w   = @(x) n(x, 0.1 - 1) - n(x, -0.1 - 1);
            dw  = @(x) dn(x, 0.1 - 1) - dn(x, -0.1 - 1); 
            ddw = @(x) ddn(x, 0.1 - 1) - ddn(x, -0.1 - 1);

            problem.du0 = @(x) dw(x) - phi * dw(2 - x);
            problem.u0  = @(x) w(x) + phi * w(2 - x);
            problem.u1  = @(x) - problem.c * dw(x) - ...
                problem.c * phi * dw(2 - x);

            problem.u   = @(x, t) w(x - c*t).*(x - c*t + 1 > 0);
            problem.dx_u = @(x, t) dw(x - c*t).*(x - c*t + 1 > 0);
            problem.dt_u = @(x, t) -c*dw(x - c*t).*(x - c*t + 1 > 0);

            problem.ddx_u   = @(x, t) 0.*x + 0.*t;
            problem.ddt_u   = @(x, t) 0.*x + 0.*t;
        %% Smooth single bump
        case 4
            % Problem domain
            problem.Q   = Domain(-1, 1, 1);
            % Problem data
            c = 2;
            problem.c       = c;
            problem.theta   = 1;
            phi = (1 - 1/problem.theta)/(1 + 1/problem.theta);

            problem.f   = @(x,t) x.*0 + t.*0;
            problem.gI  = @(x,t) x.*0 + t.*0;
            problem.gD  = @(x,t) x.*0 + t.*0;

            a = 30;
            % Define gaussian and derivatives
            n   = @(x, c) exp(-a*(x - c).^2);
            dn  = @(x, c) a*exp(-a*(c - x).^2).*(2*c - 2*x);
            ddn = @(x, c) a^2*exp(-a*(c - x).^2).*(2*c - 2*x).^2 - ... 
                            2*a*exp(-a*(c - x).^2);
            % Define initial wave
            w   = @(x) n(x, 0);
            dw  = @(x) dn(x, 0);
            ddw = @(x) ddn(x, 0);

            problem.du0 = @(x) dw(x) - phi * dw(2 - x);
            problem.u0  = @(x) w(x) + phi * w(2 - x);
            problem.u1  = @(x) - c * dw(x) - c * phi * dw(2 - x);

            problem.u       = @(x,t) w(x - c*t) + phi * w(2 - x - c*t);
            problem.dx_u    = @(x,t) dw(x - c*t) - phi * dw(2 - x - c*t);
            problem.dt_u    = @(x,t) -c * dw(x - c*t) - ...
                                     c * phi * dw(2 - x - c*t);
            problem.ddx_u   = @(x,t) ddw(x - c*t) + phi * ddw(2 - x - c*t);
            problem.ddt_u   = @(x,t) c^2*(ddw(x - c*t) + phi * ddw(2 - x - c*t));

        %% Scattering problem (Dirichlet on Left boundary)
        % TODO: fix the code for scattering problem
        case 11
            %Problem domain
            problem.Q   = Domain(1, 3, 4);
            %Problem data
            problem.c       = 1;
            problem.theta   = 5;
            phi = (1-1/problem.theta)/(1+1/problem.theta);
            problem.f       = @(x, t) x.*0 + t.*0;
            problem.gI      = @(x, t) x.*0 + t.*0;
            problem.dt_gD   = @(x,t) x.*0 + t.*0;
            
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

            problem.u0  = @(x) w(x - 2) + w(x) - phi * w(x - 6);
            problem.du0 = @(x) dw(x - 2) + dw(x) - phi * dw(x - 6);
            problem.u1  = @(x) dw(x - 2) - dw(x) - phi * dw(x - 6);

            problem.u       = @(x, t) w(x - 2 + t) + w(x - t) - ...
                phi * w(x - 6 + t);
            problem.dx_u    = @(x, t) dw(x - 2 + t) + dw(x - t) - ...
                phi * dw(x - 6 + t);
            problem.dt_u    = @(x, t) dw(x - 2 + t) - dw(x - t) - ...
                phi * dw(x - 6 + t);

            problem.ddx_u   = @(x, t) ddw(x - 2 + t) + ddw(x - t) - ...
                phi * ddw(x - 6 + t);
            problem.ddt_u   = @(x, t) ddw(x - 2 + t) + ddw(x - t) - ...
                phi * ddw(x - 6 + t);
        
        % Exact solution is in discrete space
        case 10
            % Problem domain
            problem.Q   = Domain(-1, 1, 1);
            % Data functions
            problem.f   = @(x,t) 2*x.^2 - 2*t.^2;
            problem.gI  = @(x,t) 2 * abs(x) .* t.^2 + 2 * x.^2 .* t;
            problem.gD  = @(x,t) x.*0 + t.*0;
            %problem.g   = @(x,t) x.*0 + t.*0;
            problem.du0 = @(x) x.*0;
            problem.u0  = @(x) x.*0;
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
        otherwise
            error("No matching problem number");
    end
    % TODO: 1/(r^\alpha), where $r = |(x,t)|$ -> convergence rate should
    % brake down as singularity get closer to the boundary of Q.
end
