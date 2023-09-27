function [] = main()
    % Main C callable function
    p_num = input("Select problem number (1-7): ")
    T = input("Select end time T: ")
    nx = input("Number of X-elements: ")
    nt = input("NUmber of t-elements: ")
    %% Define problem, discretization and mesh
    % Create simple problem
    p = WaveProblem(p_num);
    % Define domain
    Q = Domain(-1, 1, T);
    % Discretise the domain
    d = Discretization(nx, nt, Q);
    % Build mesh
    mesh = CartesianMesh(d);
    
    %% Custom form parameters
    form = struct();
    
    form.A       = 1;
    form.NU      = 2;
    form.XI      = 1;
    form.BETA    = form.XI / (form.NU - 1) * min([Q.L/(p.c*Q.T) + 1, ...
                    Q.L/(p.c*Q.T) * (Q.delta * p.theta + (Q.delta * p.theta)^(-1))]);
    
    C = min(form.A/Q.T^2, form.XI * Q.delta / 4);
    
    %% Solve problem
    u = SolverWaves(p, Q, mesh, d);
    
    %% Plot solution
    [U, X, T] = SolutionEval(u, mesh, d);
    pcolor(X, T, U);
    shading flat;
    xlabel("X"); ylabel("T");
    
    %% Compute errors
    errors = ComputeErrors(u, p, mesh, d, "relative");
    errors.L2E
end