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

    %% Evaluate u_ex and u
    [U, X, T] = SolutionEval(u, mesh, disc, xq);

    X = reshape(X.', [], 1);
    T = reshape(T.', [], 1);
    U = OperatorEval(u, mesh, disc, {xq, xq}, 'u');
    U = reshape(U, [], 1);
    Ux = OperatorEval(u, mesh, disc, {xq, xq}, 'ux');
    Ux = reshape(Ux, [], 1);
    Ut = OperatorEval(u, mesh, disc, {xq, xq}, 'ut');
    Ut = reshape(Ut, [], 1);
    Uxx = OperatorEval(u, mesh, disc, {xq, xq}, 'uxx');
    Uxx = reshape(Uxx, [], 1);
    Utt = OperatorEval(u, mesh, disc, {xq, xq}, 'utt');
    Utt = reshape(Utt, [], 1);
    UxOT = OperatorEval(u, mesh, disc, {xq, 1}, 'ut', reshape(top_elms, 1, []));
    UxOT = reshape(UxOT, [], 1);
    UtOT = OperatorEval(u, mesh, disc, {xq, 1}, 'ux', reshape(top_elms, 1, []));
    UtOT = reshape(UtOT, [], 1);
    UxOZ = OperatorEval(u, mesh, disc, {xq, 0}, 'ut', reshape(bot_elms, 1, []));
    UxOZ = reshape(UxOZ, [], 1);
    UtOZ = OperatorEval(u, mesh, disc, {xq, 0}, 'ux', reshape(bot_elms, 1, []));
    UtOZ = reshape(UtOZ, [], 1);
    UOZ = OperatorEval(u, mesh, disc, {xq, 0}, 'u', reshape(bot_elms, 1, []));
    UOZ = reshape(UOZ, [], 1);
    UxSIa = OperatorEval(u, mesh, disc, {xq, 0}, 'ux', reshape(left_elms, [], 1));
    UxSIa = reshape(UxSIa, [], 1);
    UtSIa = OperatorEval(u, mesh, disc, {xq, 0}, 'ut', reshape(left_elms, [], 1));
    UtSIa = reshape(UtSIa, [], 1);
    UxSIb = OperatorEval(u, mesh, disc, {xq, 1}, 'ux', reshape(right_elms, [], 1));
    UxSIb = reshape(UxSIb, [], 1);
    UtSIb = OperatorEval(u, mesh, disc, {xq, 1}, 'ut', reshape(right_elms, [], 1));
    UtSIb = reshape(UtSIb, [], 1);

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
