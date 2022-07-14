function errors = ComputeErrors(u, problem, mesh, disc)
    %% Unpack structs
    u_ex    = problem.u;
    ux_ex   = problem.dx_u;
    ut_ex   = problem.dt_u;
    uxx_ex  = problem.ddx_u;
    utt_ex  = problem.ddt_u;
    c       = problem.c;

    nx = disc.nx;
    nt = disc.nt;
    hx = disc.hx;
    ht = disc.ht;


    errors = struct();
    %% Gauss quadrature
    nq = 8;
    
    % Total number of quadrature points
    TotNQ = nx * nt * nq * nq;
    
    % Quadrature weights
    [xq, wq] = gaussquad(nq);
    wqt = wq * ht;
    wqx = wq * hx;
    wqxt = kron(wqt, wqx);
    global_wq = reshape(kron(wqxt, ones(1, nx * nt)), TotNQ, 1);
    %% Basis evaluation
    [psi, dpsi, ddpsi] = BasisEvaluation(xq);
    grad_eval   = kron(psi, dpsi * hx^(-1));
    dt_eval     = kron(dpsi * ht^(-1), psi);
    lap_eval    = kron(psi, ddpsi * hx^(-2));
    ddt_eval    = kron(ddpsi * ht^(-2), psi);

    %% Evaluate u_ex and u
    [U, X, T] = SolutionEval(u, mesh, disc, xq);
    U = reshape(U.', [], 1);
    X = reshape(X.', [], 1);
    T = reshape(T.', [], 1);
    Ux = reshape(OperatorEval(u, mesh, disc, xq, grad_eval).', [], 1);
    Ut = reshape(OperatorEval(u, mesh, disc, xq, dt_eval).', [], 1);
    Uxx = reshape(OperatorEval(u, mesh, disc, xq, lap_eval).', [], 1);
    Utt = reshape(OperatorEval(u, mesh, disc, xq, ddt_eval).', [], 1);
    
    % Exact solution evaluations
    U_ex    = u_ex(X, T);
    Ux_ex   = ux_ex(X, T);
    Ut_ex   = ut_ex(X, T);
    Uxx_ex  = uxx_ex(X, T);
    Utt_ex  = utt_ex(X, T);
    %% Compute norms
    % L2 norm
    L2Nsq = sum(U_ex .* U_ex .* global_wq);
    % H1 grad norm
    H1Nsq = sum(((Ux_ex .* Ux_ex) + (Ut_ex .* Ut_ex)) .* global_wq);
    % Operator norm
    OPNsq = sum((- c^2 * Uxx_ex + Utt_ex) .^2 .* global_wq);
    %% Compute errors
    % L2 error
    L2Esq = sum((U - U_ex) .* (U - U_ex) .* global_wq);
    % H1 error
    H1Esq = sum(((Ux_ex - Ux).^2 + (Ut_ex - Ut).^2).* global_wq);
    % Operator error
    OPEsq = sum((-c^2 * (Uxx_ex - Uxx) + (Utt_ex - Utt)) .^2 .* global_wq);
    %% Populate struct
    errors.L2N = sqrt(L2Nsq);
    errors.H1N = sqrt(H1Nsq);
    errors.OPN = sqrt(OPNsq);
    errors.GRN = sqrt(OPNsq + L2Nsq);   % Graph norm
    errors.SUPN = max(abs(U_ex));

    errors.L2E = sqrt(L2Esq / L2Nsq);
    errors.H1E = sqrt(H1Esq / H1Nsq);
    errors.OPE = sqrt(OPEsq / OPNsq);
    errors.GRE = sqrt((OPEsq + L2Esq)/ (OPNsq + L2Nsq));
    errors.SUPE = max(abs(U_ex - U));
   

end