function errors = ComputeErrors(u, problem, mesh, disc, err_type)
    %% Unpack structs
    u_ex    = problem.u;
    ux_ex   = problem.dx_u;
    ut_ex   = problem.dt_u;
    uxx_ex  = problem.ddx_u;
    utt_ex  = problem.ddt_u;
    c       = problem.c;
    Q       = problem.Q;

    nx = disc.nx;
    nt = disc.nt;
    hx = disc.hx;
    ht = disc.ht;

    % mesh unpack
    top_elms = mesh.top_elms;
    bot_elms = mesh.bot_elms;
    right_elms = mesh.right_elms;
    left_elms = mesh.left_elms;


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
    wqt = reshape(kron(wqt, ones(1, nt)), [], 1);
    wqx = reshape(kron(wqx, ones(1, nx)), [], 1);
    %% Basis evaluation
    [psi, dpsi, ddpsi] = BasisEvaluation(xq);
    % boundary evaluations
    Estart_d0 = [1, 0, 0, 0];   Estart_d1 = [0, 0, 1, 0];
    Eend_d0 = [0, 1, 0, 0];     Eend_d1 = [0, 0, 0, 1];
    
    % volume local terms 
    grad_eval   = kron(psi, dpsi * hx^(-1));
    dt_eval     = kron(dpsi * ht^(-1), psi);
    lap_eval    = kron(psi, ddpsi * hx^(-2));
    ddt_eval    = kron(ddpsi * ht^(-2), psi);

    % Omega0 local terms
    vt_0    = kron(Estart_d1 * ht^(-1), psi);
    vx_0    = kron(Estart_d0, dpsi * hx ^ (-1));
    v_0     = kron(Estart_d0, psi);

    % OmegaT local terms
    vt_T    = kron(Eend_d1 * ht^(-1), psi);
    vx_T    = kron(Eend_d0, dpsi * hx ^ (-1));

    % Sigma=a local terms
    vt_a    = kron(dpsi * ht^(-1), Estart_d0);
    vx_a    = kron(psi, Estart_d1 * hx^(-1));
   
    % Sigma=b local terms
    vt_b    = kron(dpsi * ht^(-1), Eend_d0);
    vx_b    = kron(psi, Eend_d1 * hx^(-1));

    %% Evaluate u_ex and u
    [U, X, T] = SolutionEval(u, mesh, disc, xq);
    U = reshape(U.', [], 1);
    X = reshape(X.', [], 1);
    T = reshape(T.', [], 1);
    Ux = reshape(OperatorEval(u, mesh, disc, xq, grad_eval).', [], 1);
    Ut = reshape(OperatorEval(u, mesh, disc, xq, dt_eval).', [], 1);
    Uxx = reshape(OperatorEval(u, mesh, disc, xq, lap_eval).', [], 1);
    Utt = reshape(OperatorEval(u, mesh, disc, xq, ddt_eval).', [], 1);
    UxOT = reshape(OperatorBoundaryEval(u, mesh, disc, xq, vx_T, top_elms).', [], 1);
    UtOT = reshape(OperatorBoundaryEval(u, mesh, disc, xq, vt_T, top_elms).', [], 1);
    UxOZ = reshape(OperatorBoundaryEval(u, mesh, disc, xq, vx_0, bot_elms).', [], 1);
    UtOZ = reshape(OperatorBoundaryEval(u, mesh, disc, xq, vt_0, bot_elms).', [], 1);
    UOZ = reshape(OperatorBoundaryEval(u, mesh, disc, xq, v_0, bot_elms).', [], 1);
    UxSIa = reshape(OperatorBoundaryEval(u, mesh, disc, xq, vx_a, left_elms).', [], 1);
    UtSIa = reshape(OperatorBoundaryEval(u, mesh, disc, xq, vt_a, left_elms).', [], 1);
    UxSIb = reshape(OperatorBoundaryEval(u, mesh, disc, xq, vx_b, right_elms).', [], 1);
    UtSIb = reshape(OperatorBoundaryEval(u, mesh, disc, xq, vt_b, right_elms).', [], 1);

    % Exact solution evaluations
    U_ex    = u_ex(X, T);
    Ux_ex   = ux_ex(X, T);
    Ut_ex   = ut_ex(X, T);
    Uxx_ex  = uxx_ex(X, T);
    Utt_ex  = utt_ex(X, T);
    UxOT_ex = reshape(ux_ex(X(1:(nq*nx)), Q.T), [], 1);
    UtOT_ex = reshape(ut_ex(X(1:(nq*nx)), Q.T), [], 1);
    UxOZ_ex = reshape(ux_ex(X(1:(nq*nx)), 0), [], 1);
    UtOZ_ex = reshape(ut_ex(X(1:(nq*nx)), 0), [], 1);
    UOZ_ex = reshape(u_ex(X(1:(nq*nx)), 0), [], 1);
    UxSIa_ex = reshape(ux_ex(Q.xmin, T(1:(nq*nx):end)), [], 1);
    UtSIa_ex = reshape(ut_ex(Q.xmin, T(1:(nq*nx):end)), [], 1);
    UxSIb_ex = reshape(ux_ex(Q.xmax, T(1:(nq*nx):end)), [], 1);
    UtSIb_ex = reshape(ut_ex(Q.xmax, T(1:(nq*nx):end)), [], 1);

    %% Compute norms
    % L2 norm
    L2Nsq = sum(U_ex .* U_ex .* global_wq);
    % H1 grad norm - seminorm
    H1SNsq = sum((c^2 * (Ux_ex .* Ux_ex) + (Ut_ex .* Ut_ex)) .* global_wq);
    H1Nsq = H1SNsq + problem.Q.T^(-2) * L2Nsq;
    % V-norm
    VnNsq = H1Nsq + Q.T^2 * sum((Utt_ex - c^2 * Uxx_ex) .^2 .* global_wq) + ...
        Q.T * sum((UtOT_ex.^2 + c^2 * UxOT_ex.^2).* wqx) + ...
        Q.T * sum((UtOZ_ex.^2 + c^2 * UxOZ_ex.^2).* wqx) + ...
        Q.T ^ (-1) * sum((UOZ_ex.^2) .* wqx) + ...
        Q.L * sum((UtSIa_ex.^2 + c^2 * UxSIa_ex.^2).* wqt) + ...
        Q.L * sum((UtSIb_ex.^2 + c^2 * UxSIb_ex.^2).* wqt);
    %% Compute errors
    % L2 error
    L2Esq = sum((U - U_ex) .* (U - U_ex) .* global_wq);
    % H1 error
    H1SEsq = sum((c^2 * (Ux_ex - Ux).^2 + (Ut_ex - Ut).^2).* global_wq);
    H1Esq = H1SEsq + problem.Q.T^(-2)*L2Esq;
    % Operator error
    VnEsq = sum((c^2 * (Ux_ex - Ux).^2 + (Ut_ex - Ut).^2).* global_wq) + ...
        Q.T^2 * sum((Utt - Utt_ex - c^2 * (Uxx - Uxx_ex)) .^2 .* global_wq) + ...
        Q.T * sum(((UtOT_ex-UtOT).^2 + c^2 * (UxOT_ex-UxOT).^2).* wqx) + ...
        Q.T * sum(((UtOZ_ex-UtOZ).^2 + c^2 * (UxOZ_ex-UxOZ).^2).* wqx) + ...
        Q.T ^ (-1) * sum((UOZ_ex-UOZ).^2 .* wqx) + ...
        Q.L * sum(((UtSIa_ex-UtSIa).^2 + c^2 * (UxSIa_ex-UxSIa).^2).* wqt) + ...
        Q.L * sum(((UtSIb_ex-UtSIb).^2 + c^2 * (UxSIb_ex-UxSIb).^2).* wqt);
    %% Populate struct
    errors.L2N = sqrt(L2Nsq);
    errors.H1N = sqrt(H1Nsq);
    errors.H1SN = sqrt(H1SNsq);
    errors.SUPN = max(abs(U_ex));
    errors.VnN = sqrt(VnNsq);

    if strcmpi(err_type, "relative")
        errors.L2E = sqrt(L2Esq / L2Nsq);
        errors.H1E = sqrt(H1Esq / H1Nsq);
        errors.H1SE = sqrt(H1SEsq / H1SNsq);
        errors.VnE = sqrt(VnEsq / VnNsq);
    elseif strcmpi(err_type, "absolute")
        errors.L2E = sqrt(L2Esq);
        errors.H1E = sqrt(H1Esq);
        errors.H1SE = sqrt(H1SEsq);
        errors.VnE = sqrt(VnEsq);
    end

    errors.SUPE = max(abs(U_ex - U));

end