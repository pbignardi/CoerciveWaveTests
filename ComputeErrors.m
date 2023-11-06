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
    
    % Quadrature weights
    [xq, wq] = gaussquad(nq);
    wqt = reshape(wq, [], 1) * ht;
    wqx = reshape(wq, 1, []) * hx;
    wqxt = kron(wqt, wqx); % local quadrature weights 
    wqxt = repmat(wqxt, nt, nx);
    wqx = repmat(wqx, 1, nx);
    wqt = repmat(wqt, nt, 1);


    %% Evaluate u_ex and u
    [U, X, T] = OperatorEval(u, mesh, disc, {xq, xq}, 'u');
    Ux = OperatorEval(u, mesh, disc, {xq, xq}, 'ux');
    Ut = OperatorEval(u, mesh, disc, {xq, xq}, 'ut');
    Uxx = OperatorEval(u, mesh, disc, {xq, xq}, 'uxx');
    Utt = OperatorEval(u, mesh, disc, {xq, xq}, 'utt');
    
    top_elms = reshape(top_elms, 1, []);
    [UxOT, XOT, TOT] = OperatorEval(u, mesh, disc, {xq, 1}, 'ux', top_elms);
    UtOT = OperatorEval(u, mesh, disc, {xq, 1}, 'ut', top_elms);
    
    bot_elms = reshape(bot_elms, 1, []);
    [UxOZ, XOZ, TOZ] = OperatorEval(u, mesh, disc, {xq, 0}, 'ux', bot_elms);
    UtOZ = OperatorEval(u, mesh, disc, {xq, 0}, 'ut', bot_elms);
    UOZ = OperatorEval(u, mesh, disc, {xq, 0}, 'u', bot_elms);

    left_elms = reshape(left_elms, [], 1);
    [UxSIa, XSIa, TSIa] = OperatorEval(u, mesh, disc, {0, xq}, 'ux', left_elms);
    UtSIa = OperatorEval(u, mesh, disc, {0, xq}, 'ut', left_elms);

    right_elms = reshape(right_elms, [], 1);
    [UxSIb, XSIb, TSIb] = OperatorEval(u, mesh, disc, {1, xq}, 'ux', right_elms);
    UtSIb = OperatorEval(u, mesh, disc, {1, xq}, 'ut', right_elms);

    % Exact solution evaluations
    U_ex    = u_ex(X, T);
    Ux_ex   = ux_ex(X, T);
    Ut_ex   = ut_ex(X, T);
    Uxx_ex  = uxx_ex(X, T);
    Utt_ex  = utt_ex(X, T);

    UxOT_ex = ux_ex(XOT, TOT);
    UtOT_ex = ut_ex(XOT, TOT);
    UxOZ_ex = ux_ex(XOZ, TOZ);
    UtOZ_ex = ut_ex(XOZ, TOZ);
    UOZ_ex = u_ex(XOZ, TOZ);

    UxSIa_ex = ux_ex(XSIa, TSIa);
    UtSIa_ex = ut_ex(XSIa, TSIa);
    UxSIb_ex = ux_ex(XSIb, TSIb);
    UtSIb_ex = ut_ex(XSIb, TSIb);

    %% Compute norms
    % L2 norm
    L2Nsq = sum(U_ex .* U_ex .* wqxt, 'all');
    % H1 grad norm - seminorm
    H1SNsq = sum((c^2 * (Ux_ex .* Ux_ex) + (Ut_ex .* Ut_ex)) .* wqxt, 'all');
    H1Nsq = H1SNsq + problem.Q.T^(-2) * L2Nsq;
    % V-norm
    VnNsq = H1Nsq + Q.T^2 * sum((Utt_ex - c^2 * Uxx_ex) .^2 .* wqxt, 'all') + ...
        Q.T * sum((UtOT_ex.^2 + c^2 * UxOT_ex.^2).* wqx, 'all') + ...
        Q.T * sum((UtOZ_ex.^2 + c^2 * UxOZ_ex.^2).* wqx, 'all') + ...
        Q.T ^ (-1) * sum((UOZ_ex.^2) .* wqx, 'all') + ...
        Q.L * sum((UtSIa_ex.^2 + c^2 * UxSIa_ex.^2).* wqt, 'all') + ...
        Q.L * sum((UtSIb_ex.^2 + c^2 * UxSIb_ex.^2).* wqt, 'all');
    %% Compute errors
    % L2 error
    L2Esq = sum((U - U_ex) .* (U - U_ex) .* wqxt, 'all');
    % H1 error
    H1SEsq = sum((c^2 * (Ux_ex - Ux).^2 + (Ut_ex - Ut).^2).* wqxt, 'all');
    H1Esq = H1SEsq + problem.Q.T^(-2)*L2Esq;
    % Operator error
    VnEsq = sum((c^2 * (Ux_ex - Ux).^2 + (Ut_ex - Ut).^2).* wqxt, 'all') + ...
        Q.T^2 * sum((Utt - Utt_ex - c^2 * (Uxx - Uxx_ex)) .^2 .* wqxt, 'all') + ...
        Q.T * sum(((UtOT_ex-UtOT).^2 + c^2 * (UxOT_ex-UxOT).^2).* wqx, 'all') + ...
        Q.T * sum(((UtOZ_ex-UtOZ).^2 + c^2 * (UxOZ_ex-UxOZ).^2).* wqx, 'all') + ...
        Q.T ^ (-1) * sum((UOZ_ex-UOZ).^2 .* wqx, 'all') + ...
        Q.L * sum(((UtSIa_ex-UtSIa).^2 + c^2 * (UxSIa_ex-UxSIa).^2).* wqt, 'all') + ...
        Q.L * sum(((UtSIb_ex-UtSIb).^2 + c^2 * (UxSIb_ex-UxSIb).^2).* wqt, 'all');
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
