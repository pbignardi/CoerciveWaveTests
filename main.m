function err = main(c, theta, T, nx, nt)
    % Main C callable function
    phi = (1 - 1/theta)/(1 + 1/theta);
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

    problem = struct('c', c, ...
        "theta", theta, ...
        "f", @(x,t) x.*0 + t.*0, ...
        "g", @(x,t) x.*0 + t.*0, ...
        "u0", @(x) dw(x) - phi * dw(2 - x), ...
        "u1", @(x) - c * dw(x) - c * phi * dw(2 - x), ...
        "u", @(x,t) w(x - c*t) + phi * w(2 - x - c*t), ...
        "dx_u", @(x,t) dw(x - c*t) - phi * dw(2 - x - c*t), ...
        "dt_u", @(x,t) -c * dw(x - c*t) - c * phi * dw(2 - x - c*t), ...
        "ddx_u", @(x,t) ddw(x - c*t) + phi * ddw(2 - x - c*t), ...
        "ddt_u", @(x,t) c^2*(ddw(x - c*t) + phi * ddw(2 - x - c*t)));


    %% Define problem, discretization and mesh
    % Create simple problem
    p = problem;
    % Define domain
    Q = Domain(-1, 1, T);
    % Discretise the domain
    d = Discretization(nx, nt, Q);
    % Build mesh
    mesh = CartesianMesh(d);
    
    %% Solve problem
    u = SolverWaves(p, Q, mesh, d);
    
    %% Plot solution
    [U, X, T] = SolutionEval(u, mesh, d);
    surf(X, T, U);
    shading flat;
    xlabel("X"); ylabel("T");
    
    %% Compute errors
    errors = ComputeErrors(u, p, mesh, d, "relative");
    err = errors.L2E;
end