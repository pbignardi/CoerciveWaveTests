function u = SolverWaves(problem, domain, mesh, disc, varargin)
    %% Unpacking parameters
    % Problem unpacking
    f       = problem.f;
    g       = problem.g;
    u0      = problem.u0;
    u1      = problem.u1;
    c       = problem.c;
    theta   = problem.theta;

    % Domain unpacking
    T       = domain.T;
    xmin    = domain.xmin;
    xmax    = domain.xmax;
    delta   = domain.delta;
    L       = domain.L;

    % Elements unpacking
    nx = disc.nx;
    nt = disc.nt;
    hx = disc.hx;
    ht = disc.ht;
    elms    = mesh.elms;
    pivots  = mesh.pivots;
    
    % Boundary unpacking
    top     = mesh.top;
    bot     = mesh.bot;
    left    = mesh.left;
    right   = mesh.right;
    
    % Formulation unpacking
    if isempty(varargin)
        A   = 1;
        nu  = 2;
        xi  = 1;
    elseif length(varargin) == 1
        form = varargin{1};
        A   = form.A;
        nu  = form.nu;
        xi  = form.xi;
    end
    Tstar   = nu*T;
    beta    = xi / (nu - 1) * min([L/(c*T) + 1, ...
                L/(c*T) * (delta * theta + (delta * theta)^(-1))]);
    % Pack formulation parameters
    parameters = struct();
    parameters.A = A;
    parameters.beta = beta;
    parameters.Tstar = Tstar;
    parameters.nu = nu;
    parameters.xi = xi;
    parameters.c = c;
    
    % Other parameters
    n_nodes = (nx + 1) * (nt + 1);
    ndofs = 4*n_nodes;
    dofs = 1:ndofs;
    
    %% Local operator structs
    Xb = HermiteBasis(hx);
    Tb = HermiteBasis(ht);
    
    %% (Fixed) Local operator over Q
    % gradu * gradv
    opQ = kron(Tb.d0d0, Xb.d1d1) * c^2 * (beta - xi);
    % ut * vt
    opQ = opQ + kron(Tb.d1d1, Xb.d0d0) * (beta + xi);
    % Lap u * Lap v
    opQ = opQ + kron(Tb.d0d0, Xb.d2d2) * c^4 * A / (T^2);
    % Lap u * vtt
    opQ = opQ - kron(Tb.d0d2, Xb.d2d0) * c^2 * A / (T^2);
    % utt * Lap v
    opQ = opQ - kron(Tb.d2d0, Xb.d0d2) * c^2 * A / (T^2);
    % utt * vtt
    opQ = opQ + kron(Tb.d2d2, Xb.d0d0) * A / (T^2);
    % -beta * Tstar * ut * vtt
    opQ = opQ - kron(Tb.d1d2, Xb.d0d0) * beta * Tstar;
    % c^2 * beta * Tstar * ut * Lap v
    opQ = opQ + kron(Tb.d1d0, Xb.d0d2) * c^2 * beta * Tstar;
    
    %% (Variable) Local operator over Q
    % - xi * x * grad u * vtt
    opQx    = - kron(Tb.d0d2, Xb.d1d0x) * xi;
    opQxVar = - kron(Tb.d0d2, Xb.d1d0) * xi;
    % c^2 * xi * x * grad u * Lap v
    opQx    = opQx + kron(Tb.d0d0, Xb.d1d2x) * c^2 * xi;
    opQxVar = opQxVar + kron(Tb.d0d0, Xb.d1d2) * c^2 * xi;
    % beta * t * ut * vtt
    opQt    = kron(Tb.d1d2x, Xb.d0d0) * beta;
    opQtVar = kron(Tb.d1d2, Xb.d0d0) * beta;
    % - beta * c^2 * t * ut * Lap v
    opQt    = opQt - kron(Tb.d1d0x, Xb.d0d2) * beta * c^2;
    opQtVar = opQtVar - kron(Tb.d1d0, Xb.d0d2) * beta * c^2;

    
    %% (Fixed) Local operator over Omega_T
    opO = 
    
    %% Global matrix assembly
    K = assemble(opQ, mesh, disc) + ...
        assemble(opQx, mesh, disc, opQxVar, 1) + ...
        assemble(opQt, mesh, disc, opQtVar, 2);
    
    %% Load vector assembly
    F = compute_rhs(f, mesh, disc, parameters);
    
    
    %% Imposing boundary conditions
    initial_dofs = unique([bot n_nodes+bot 2*n_nodes+bot 3*n_nodes+bot]);
    dirichlet_dofs = unique([bot top left right ...
        n_nodes+bot n_nodes+top 2*n_nodes+left 2*n_nodes+right]);
    internal = setdiff(dofs, initial_dofs);
    
    %% Solving
    u = zeros(ndofs, 1);
    u(internal) = K(internal, internal) \ F(internal);

    %% Internal stiffness conditioning
    fprintf("Condition number is: %e \n", condest(K(internal, internal)))
end
