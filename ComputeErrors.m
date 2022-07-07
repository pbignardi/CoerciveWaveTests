function errors = ComputeErrors(u, problem, mesh, disc)
    %% Unpack structs
    u_ex    = problem.u;

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

    %% Evaluate u_ex and u
    [U, X, T] = SolutionEval(u, mesh, disc, xq);
    U = reshape(U.', [], 1);
    X = reshape(X.', [], 1);
    T = reshape(T.', [], 1);
    U_ex = u_ex(X,T);
    %% Compute norms
    L2Nsq = sum(U_ex .* U_ex .* global_wq);
    %% Compute errors
    L2Esq = sum((U - U_ex) .* (U - U_ex) .* global_wq);
    %% Populate struct
    errors.L2E = sqrt(L2Esq / L2Nsq);
    errors.L2N = sqrt(L2Nsq);
end