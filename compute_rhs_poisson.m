function F = compute_rhs_poisson(f, mesh, disc)
    %% Unpacking parameters
    % Mesh parameters
    elms    = mesh.elms;
    pivots  = mesh.pivots;
    n_elms  = size(elms, 1);

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
    [psi, dpsi, ddpsi] = BasisEvaluation(nq);
    ref_eval = kron(psi, psi);
    
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
        % Integrate using Gauss quadrature
        F(el_dofs) = F(el_dofs) + sum( f_eval .* ref_eval .* wqxt).';
    end
end