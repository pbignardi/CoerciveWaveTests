function F = computeLS_rhs(p, mesh, disc, domain, A)
    %% Unpacking parameters
    % Mesh parameters
    elms    = mesh.elms;
    pivots  = mesh.pivots;
    n_elms  = size(elms, 1);

    % Boundary elms
    bot_elms    = mesh.bot_elms;
    left_elms   = mesh.left_elms;
    right_elms  = mesh.right_elms;

    % Problem parameters
    f       = p.f;
    g       = p.g;
    u0      = p.u0;
    u1      = p.u1;
    c       = p.c;
    theta   = p.theta; 

    % Formulation parameters
    a = domain.xmin;
    b = domain.xmax;

    % Discretisation parameters
    hx = disc.hx;
    ht = disc.ht;
    nx = disc.nx;
    nt = disc.nt;
    xx = kron(ones(1, (nt + 1)), disc.x);
    tt = kron(disc.t, ones((nx + 1), 1));
    ndofs = 4 * (nx + 1) * (nt + 1);
    
    % Quadrature variables
    nq = 8;
    [xq, wq] = gaussquad(nq);

    % Local quadrature nodes and weights
    xqh = hx * xq;
    tqh = ht * xq;
    wqx = hx * wq;
    wqt = ht * wq;
    wqxt = kron(wqt, wqx);
    xxqh = kron(ones(nq, 1), xqh);
    ttqh = kron(tqh, ones(nq, 1));
    %% Component basis functions evaluation
    % Component basis evaluations
    % When using dpsi and ddpsi, remember to divide by hx and ht to account
    % for derivation chain rule scaling.
    [psi, dpsi, ddpsi] = BasisEvaluation(xq);
    
    % Basis function evaluation over grid
    psi_T   = psi;
    dpsi_T  = ht^(-1) * dpsi; 
    ddpsi_T = ht^(-2) * ddpsi;

    psi_X   = psi;
    ddpsi_X = hx^(-2) * ddpsi;
    
    % Basis function evaluation at boundary
    Estart_d0 = [1, 0, 0, 0];
    Estart_d1 = [0, 0, 1, 0];
    Eend_d0 = [0, 1, 0, 0];
    Eend_d1 = [0, 0, 0, 1];
    
    Ea_d0 = Estart_d0;
    Ea_d1 = Estart_d1 * hx^(-1);
    Eb_d0 = Eend_d0;
    Eb_d1 = Eend_d1 * hx^(-1);
    E0_d0 = Estart_d0;
    E0_d1 = Estart_d1 * ht^(-1);
    
    %% Operator evaluations
    % Q local terms
    vtt_Q   = kron(ddpsi_T, psi_X);
    Lapv_Q  = kron(psi_T, ddpsi_X);
    
    % Omega0 local terms
    vt0     = kron(E0_d1, psi_X);
    v0      = kron(E0_d0, psi_X);

    % Sigma=a local terms
    vta     = kron(dpsi_T, Ea_d0);
    vxa     = kron(psi_T, Ea_d1);
   
    % Sigma=b local terms
    vtb     = kron(dpsi_T, Eb_d0);
    vxb     = kron(psi_T, Eb_d1);

    %% Q- Element-wise assembly
    F = zeros(ndofs, 1);
    for e = 1:n_elms
        % Get element nodes and DOFs
        el_ids  = elms(e, :);
        el_dofs = mapper(el_ids, nx, nt);
        % Move quadrature nodes
        el_xq = xxqh + xx(pivots(e));
        el_tq = ttqh + tt(pivots(e));
        % Function f local evaluation
        f_eval = f(el_xq, el_tq);
        
        %% Q domain integral
        % Compute Wv
        Wv = vtt_Q - Lapv_Q * c^2;
        % Integrate using Gauss quadrature
        local_rhs_Q = A * sum( f_eval .* Wv .* wqxt ).';
        
        F(el_dofs) = F(el_dofs) + local_rhs_Q;
    end

    %% Omega0- Element-wise assembly
    for e = bot_elms
        % Get element nodes and DOFs
        el_ids  = elms(e, :);
        el_dofs = mapper(el_ids, nx, nt);
        
        % Move quadrature nodes
        el_xq = xxqh(1:nq) + xx(pivots(e));
    
        % u1 and u0x evaluation 
        U0 = u0(el_xq);
        U1 = u1(el_xq);

        % Integrand evaluation
        integrand = U1 .* vt0 + U0 .* v0;
        local_rhs_0 = sum( integrand .* wqx ).';  
        F(el_dofs) = F(el_dofs) + local_rhs_0;
    end

    %% Sigma=a- Element-wise assembly
    for e = left_elms
        % Get element nodes and DOFs
        el_ids  = elms(e, :);
        el_dofs = mapper(el_ids, nx, nt);

        % Move quadrature nodes
        el_tq = ttqh(nq * (1:nq)) + tt(pivots(e));

        % g evaluation
        G = g(a, el_tq);

        % Impedance boundary evaluation
        test_impedance = - vxa + vta / (theta * c);
        local_rhs_a = sum(test_impedance .* G .* wqt).';
        F(el_dofs) = F(el_dofs) - c^2 * local_rhs_a;
    end

    %% Sigma=b- Element-wise assembly
    for e = right_elms
        % Get element nodes and DOFs
        el_ids  = elms(e, :);
        el_dofs = mapper(el_ids, nx, nt);

        % Move quadrature nodes
        el_tq = ttqh(nq*(1:nq)) + tt(pivots(e));

        % g evaluation
        G = g(b, el_tq);

        % Zv boundary evaluation
        test_impedance = vxb + vtb / (theta * c);
        local_rhs_b = sum(test_impedance .* G .* wqt).';
        F(el_dofs) = F(el_dofs) + local_rhs_b;
    end
end