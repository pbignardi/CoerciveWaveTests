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
    
    % Other parameters
    n_nodes = (nx + 1) * (nt + 1);
    ndofs = 4*n_nodes;
    dofs = 1:ndofs;
    
    %% Local operators construction
    Xb = HermiteBasis(hx);
    Tb = HermiteBasis(ht);
    Kloc = kron(Tb.d0d0, Xb.d1d1) + kron(Tb.d1d1, Xb.d0d0);
    
    %% Global matrix assembly
    K = assemble(Kloc, mesh, disc);
    
    %% Load vector assembly
    F = compute_rhs(f, mesh, disc);
    
    
    %% Imposing boundary conditions
    initial_dofs = unique([bot n_nodes+bot 2*n_nodes+bot 3*n_nodes+bot]);
    dirichlet_dofs = unique([bot top left right ...
        n_nodes+bot n_nodes+top 2*n_nodes+left 2*n_nodes+right]);
    internal = setdiff(dofs, dirichlet_dofs);
    
    %% Solving
    u = zeros(ndofs, 1);
    u(internal) = K(internal, internal) \ F(internal);
end
