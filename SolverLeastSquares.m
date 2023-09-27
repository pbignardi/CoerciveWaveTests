function [u, Kcond] = SolverLeastSquares(problem, domain, mesh, disc, varargin)
    %% Unpacking parameters
    % Problem unpacking
    c       = problem.c;
    theta   = problem.theta;

    % Elements unpacking
    hx = disc.hx;
    ht = disc.ht;

    % Boundary elms unpacking
    right_elms  = mesh.right_elms;
    left_elms   = mesh.left_elms;
    bot_elms    = mesh.bot_elms;

    % varargin unpacking
    if isempty(varargin)
        A = 1;
    else
        A = varargin{1};
    end
    
    %% Local operator structs
    Xb = HermiteBasis(hx);
    Tb = HermiteBasis(ht);

    %% Local evaluation structs
    Ea = HermiteEvaluation(hx, 0);
    Eb = HermiteEvaluation(hx, 1);
    E0 = HermiteEvaluation(ht, 0);

    %% Local operator over Q
    % Lap u * Lap v
    opQ = kron(Tb.d0d0, Xb.d2d2) * c^4;
    % utt * vtt
    opQ = opQ + kron(Tb.d2d2, Xb.d0d0);
    % - c^2 Lap u * vtt
    opQ = opQ - c^2 * kron(Tb.d0d2, Xb.d2d0);
    % - c^2 Lap v * utt
    opQ = opQ - c^2 * kron(Tb.d2d0, Xb.d0d2);


    %% Local operator over Omega_0
    % u(0) v(0)
    opO = kron(E0.d0d0, Xb.d0d0);
    % ut(0) vt(0)
    opO = opO + kron(E0.d1d1, Xb.d0d0);

    %% Local operator over Sigma_a
    n = -1;
    % dn u * dn v
    opSa = kron(Tb.d0d0, Ea.d1d1);
    % 1/(theta * c)^2 * ut * vt
    opSa = opSa + kron(Tb.d1d1, Ea.d0d0) * (theta * c)^(-2);
    % 1/(theta * c) dn u * vt
    opSa = opSa + kron(Tb.d0d1, Ea.d1d0) * (theta * c)^(-1) * n;
    % 1/(theta * c) dn v * ut
    opSa = opSa + kron(Tb.d1d0, Ea.d0d1) * (theta * c)^(-1) * n;
    
    %% Local operator over Sigma_b
    n = 1;
    % dn u * dn v
    opSb = kron(Tb.d0d0, Eb.d1d1);
    % 1/(theta * c)^2 * ut * vt
    opSb = opSb + kron(Tb.d1d1, Eb.d0d0) * (theta * c)^(-2);
    % 1/(theta * c) dn u * vt
    opSb = opSb + kron(Tb.d0d1, Eb.d1d0) * (theta * c)^(-1) * n;
    % 1/(theta * c) dn v * ut
    opSb = opSb + kron(Tb.d1d0, Eb.d0d1) * (theta * c)^(-1) * n;
    

    %% Internal matrix assembly
    KQ = assembleLS(opQ, mesh, disc);

    %% Boundary matrix assembly
    % Omega0 boundary
    K0 = assembleLS_boundary(opO, mesh, disc, bot_elms);
    % Sigma = a boundary
    Ka = assembleLS_boundary(opSa, mesh, disc, left_elms);
    % Sigma = b boundary
    Kb = assembleLS_boundary(opSb, mesh, disc, right_elms);
    

    %% Global matrix computation
    K = A * KQ + K0 + Ka + Kb;

    %% Load vector assembly
    F = computeLS_rhs(problem, mesh, disc, domain, A);

    %% Solving
    % Start timer
    tic
    %u = gmres(K, F);
    u = K \ F;
    %u = lsqr(K, F);
    Kcond = condest(K);
    solving_time = toc;
    
    %% Post-processing solution
    % Compute condest of matrix K :TODO
    %Kcond = condest(K(internal,internal));
    %Kcond = condest(K);

    % Compute mean
    % Remove computed mean
    %u = u - omega0_mean;
end