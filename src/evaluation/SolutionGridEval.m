% Paolo Bignardi - Dec 2023
function [U, X, T] = SolutionGridEval(u, mesh, disc, xps, tps)
    % Evaluate solution u over meshgrid(px, pt)
    % Parameters
    %   u       : solution vector
    %   mesh    : mesh of the problem where u is obtained
    %   disc    : discretisation struct
    %   px      : x-coordinate of evaluation
    %   pt      : t-coordinate of evaluation
    % 

    %% Unpacking structs
    % mesh parameters
    elms = mesh.elms;

    % discretisation parameters
    nx = disc.nx;
    nt = disc.nt;

    x = disc.x;
    t = disc.t;
    U = zeros(length(tps), length(xps));
    X = zeros(length(tps), length(xps));
    T = zeros(length(tps), length(xps));
    %% Placing points in elements
    past_nxp = 0;
    for i = 1:nx
        past_ntp = 0;
        for j = 1:nt
            e = i + (j - 1) * nx;
            % Get elms dofs
            el_ids      = elms(e, :);
            el_dofs     = mapper(el_ids, nx, nt);
            % get element corner points
            x1 = x(i); x2 = x(i + 1);
            t1 = t(j); t2 = t(j + 1);
            % get x- and t-coordinates of points in element e
            el_px = xps(1>=(xps - x1)/(x2-x1) & (xps-x1)/(x2-x1)>=0);
            el_pt = tps(1>=(tps - t1)/(t2-t1) & (tps-t1)/(t2-t1)>=0);
            % transform points to reference element
            ref_px = reshape((el_px - x1)/(x2 - x1), [], 1);
            ref_pt = reshape((el_pt - t1)/(t2 - t1), [], 1);
            % evaluate basis function over the reference points
            [psiX, ~, ~] = BasisEvaluation(ref_px);
            [psiT, ~, ~] = BasisEvaluation(ref_pt);
            % tensor product of basis functions
            ref_eval = kron(psiT, psiX);
            % compute evaluation of u over the element e
            el_u_eval = reshape(ref_eval * u(el_dofs), ...
                length(el_px), length(el_pt));
            [x_grid, t_grid] = meshgrid(el_px, el_pt);
            I = (past_ntp + 1):(past_ntp + length(el_pt));
            J = (past_nxp + 1):(past_nxp + length(el_px));
            U(I, J) = el_u_eval.';
            X(I, J) = x_grid;
            T(I, J) = t_grid;
            past_ntp = past_ntp + length(el_pt);
        end
        past_nxp = past_nxp + length(el_px);
    end
end
