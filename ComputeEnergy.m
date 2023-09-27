function E = ComputeEnergy(u, ts, mesh, disc, problem)
    nx = disc.nx;
    nt = disc.nt;
    hx = disc.hx;
    ht = disc.ht;

    nq = 8;
    
    % Total number of quadrature points
    TotNQ = nx * nt * nq * nq;
    
    % Quadrature weights
    [xq, wq] = gaussquad(nq);
    wqt = wq * ht;
    wqx = wq * hx;
    wqxt = kron(wqt, wqx);
    global_wq = reshape(kron(wqxt, ones(1, nx * nt)), TotNQ, 1);
    wqt = reshape(kron(wqt, ones(1, nt)), [], 1);
    wqx = reshape(kron(wqx, ones(1, nx)), [], 1);
    %% Basis evaluation
    [psi, dpsi, ~] = BasisEvaluation(xq);
    []
    % volume local terms 
    grad_eval   = kron(psi, dpsi * hx^(-1));
    dt_eval     = kron(dpsi * ht^(-1), psi);
    
    %% Evaluate gradu and timeder u
    [~, X, T, W] = SolutionEval(u, mesh, disc);
    X = reshape(X(1, 1:end), [], 1);
    T = reshape(T(1:end, 1), [], 1);
    Ux = OperatorEval(u, mesh, disc, xq, grad_eval);
    Ut = OperatorEval(u, mesh, disc, xq, dt_eval);
    E = (problem.c ^ 2 * Ux .* Ux) * wqx;
    E = E + (Ut .* Ut) * wqx;
end
