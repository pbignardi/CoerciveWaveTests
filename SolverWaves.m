function u = SolverWaves(problem, domain, mesh, disc, varargin)

    %% Unpacking parameters
    
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
    if varargin == 0
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
    
    %% Local operators construction
    Xb = HermiteBasis(hx);
    Tb = HermiteBasis(ht);
    
    Kloc = kron(Tb.d0d0, Xb.d0d0);
    
    %% Global matrix assembly
    K = spalloc(ndofs, ndofs, 16 * ndofs);
    
    %% Load vector assembly
    F = zeros(ndofs, 1);
    
    
    %% Imposing boundary conditions
    
    
    %% Solving
    u = zeros(ndofs, 1);
    u(internal) = K(internal, internal) \ F(internal);
end
