function F = compute_rhs(f, mesh, disc, parameters)
    %% Unpacking parameters
    % Mesh parameters
    elms    = mesh.elms;
    pivots  = mesh.pivots;
    n_elms  = size(elms, 1);

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
    %% Evaluation of basis functions
    % Component basis evaluations
    % When using dpsi and ddpsi, remember to divide by hx and ht to account
    % for derivation chain rule scaling.
    [psi, dpsi, ddpsi] = BasisEvaluation(xq);
    
    psi_T   = psi;
    dpsi_T  = ht^(-1) * dpsi; 
    ddpsi_T = ht^(-2) * ddpsi;

    psi_X   = psi;
    dpsi_X  = hx^(-1) * dpsi;
    ddpsi_X = hx^(-2) * ddpsi;
    
    %% Element-wise assembly
    F = zeros(ndofs, 1);
    for e = 1:n_elms
        % Get element nodes and DOFs
        el_ids  = elms(e, :);
        el_dofs = mapper(el_ids, nx, nt);
        % Move quadrature nodes
        el_xq = xxqh + xx(pivots(e));
        el_tq = ttqh + tt(pivots(e));
        % Function local evaluation
        f_eval = f(el_xq, el_tq);
        % Evaluate Zv
        Zv = - el_xq .* kron(psi_T, dpsi_X) * xi + ...
            el_tq .* kron(dpsi_T, psi_X) * beta - ...
            kron(dpsi_T, psi_X) * beta * Tstar;
        % Evaluate Wv
        Wv = kron(ddpsi_T, psi_X) - kron(psi_T, ddpsi_X) * c^2;
        % Integrate using Gauss quadrature
        F(el_dofs) = F(el_dofs) + ...
            sum( f_eval .* (- Zv + Wv * A / (T^2)) .* wqxt).';
    end
end