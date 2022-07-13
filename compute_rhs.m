function F = compute_rhs(p, mesh, disc, parameters)
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
    f   = p.f;
    g   = p.g;
    u0x = p.u0;
    u1  = p.u1;

    % Formulation parameters
    A       = parameters.A;
    beta    = parameters.beta;
    xi      = parameters.xi;
    Tstar   = parameters.Tstar;
    T       = parameters.T;
    c       = parameters.c;

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
    dpsi_X  = hx^(-1) * dpsi;
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
    gradv_Q = kron(psi_T, dpsi_X);
    vt_Q    = kron(dpsi_T, psi_X);
    vtt_Q   = kron(ddpsi_T, psi_X);
    Lapv_Q  = kron(psi_T, ddpsi_X);
    
    % Omega0 local terms
    vt_0    = kron(E0_d1, psi_X);
    vx_0    = kron(E0_d0, dpsi_X);

    % Sigma=a local terms
    vt_a    = kron(dpsi_T, Ea_d0);
    vx_a    = kron(psi_T, Ea_d1);
   
    % Sigma=b local terms
    vt_b    = kron(dpsi_T, Eb_d0);
    vx_b    = kron(psi_T, Eb_d1);

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
        % Compute Zv
        Zv = - el_xq .* gradv_Q * xi + (el_tq - Tstar) .* vt_Q * beta;
        % Compute Wv
        Wv = vtt_Q - Lapv_Q * c^2;
        % Integrate using Gauss quadrature
        local_rhs_Q = sum( f_eval .* (- Zv + Wv * A / (T^2)) .* wqxt).';
        
        %% Sigma=a domain integral
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
        U0x     = u0x(el_xq);
        U1      = u1(el_xq);

        % Integrand
        integrand = beta * Tstar * (U1 .* vt_0 + c^2 * U0x .* vx_0) + ...;
                    xi * el_xq .* (vx_0 .* U1 + U0x .* vt_0);
        local_rhs_0 = sum( integrand .* wqx ).';  
        F(el_dofs) = F(el_dofs) + local_rhs_0;
    end

    %% Sigma=a- Element-wise assembly
    for e = left_elms
        % Get element nodes and DOFs
        el_ids  = elms(e, :);
        el_dofs = mapper(el_ids, nx, nt);

        % Move quadrature nodes
        el_tq = ttqh(nq*(1:nq)) + tt(pivots(e));

        % g evaluation
        

    end
end