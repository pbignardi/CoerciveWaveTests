function F = compute_rhs(f, mesh, disc)
    %% Unpacking parameters
    % Mesh parameters
    elms    = mesh.elms;
    pivots  = mesh.pivots;
    n_elms  = size(elms, 1);
    
    % Discretisation parameters
    xx = disc.xx.';
    tt = disc.tt.';
    hx = disc.hx;
    ht = disc.ht;
    nx = disc.nx;
    nt = disc.nt;
    ndofs = 4 * (nx + 1) * (nt + 1);
    
    % Quadrature variables
    nq = 4;
    [xq, wq] = gaussquad(nq);

    % Local quadrature nodes and weights
    xqh = hx * xq;
    tqh = ht * xq;
    wqx = hx * wq;
    wqt = ht * wq;
    wqxt = kron(wqt, wqx);
    xxqh = kron(ones(nq,1), xqh.');
    ttqh = kron(tqh, ones(1,nq));
    %% Quadrature of basis functions
    % Component basis evaluations
    psiB = (-2*xq.^3+3*xq.^2);
    psiA = 2*xq.^3-3*xq.^2+1;
    psiD = xq.^3-xq.^2;
    psiC = xq.^3-2*xq.^2+xq;
    % Tensor product of X and T component kron(T,X)
    xb_eval = [psiA, psiB, psiC, psiD];
    tb_eval = [psiA, psiB, psiC, psiD];
    ref_eval = kron(tb_eval, xb_eval);  
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
        % Need to transpose f(el_xq, el_tq) because reshape stacks columns
        % as the x varies first and varies across cols.
        f_eval = reshape(f(el_xq, el_tq).', [], 1);
        % Integrate over local element
        F(el_dofs) = F(el_dofs) + sum(f_eval .* ref_eval .* wqxt).';
    end
end