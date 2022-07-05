function [U, X, T] = SolutionEval(u, mesh, disc, varargin)
    %% Unpacking structs
    % Mesh parameters
    elms = mesh.elms;
    pivots = mesh.pivots;

    % Discretisation paramters
    nx = disc.nx;
    nt = disc.nt;
    hx = disc.hx;
    ht = disc.ht;
    xx = disc.xx.';
    tt = disc.tt.';

    % Unpack varargin xq parameter
    if isempty(varargin)
        nq = 9;
        [xq, ~] = gaussquad(nq);
    else
        xq = varargin{1};
        nq = length(xq);
    end
    xqh = hx * xq;
    tqh = ht * xq;
    xxqh = kron(ones(nq, 1), xqh.');
    ttqh = kron(tqh, ones(1, nq));

    %%  Basis functions evaluation
    % Component basis evaluations
    [psi, ~, ~] = BasisEvaluation(xq);
    % Tensor product of X and T component kron(T,X)
    ref_eval = kron(psi, psi); 

    %% Element-wise assembly
    U = zeros(nq * nt, nq * nx);
    X = zeros(nq * nt, nq * nx);
    T = zeros(nq * nt, nq * nx);
    for i = 1:nx
        for j = 1:nt
            e = i + (j - 1) * nx;
            % Get elms dofs
            el_pivot    = pivots(e);
            el_ids      = elms(e, :);
            el_dofs     = mapper(el_ids, nx, nt);
            % Local evaluation grid
            el_x = xxqh + xx(el_pivot);
            el_t = ttqh + tt(el_pivot);
            % Evaluate u locally
            el_u = ref_eval * u(el_dofs);
            % Populate evaluation
            J = ((j - 1) * nq + 1):(j * nq);
            I = ((i - 1) * nq + 1):(i * nq);
            U(J, I) = reshape(el_u, nq, nq).';
            X(J, I) = el_x;
            T(J, I) = el_t;
        end
    end
end