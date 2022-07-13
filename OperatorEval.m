function U = OperatorEval(u, mesh, disc, xq, operator)
    % Evaluate operator over the gauss quadrature nodes
    % Parameters
    %   u       : solution of the linear system
    %   mesh    : mesh of the problem
    %   disc    : discretization struct
    %   operator: matrix of local operator evaluation

    %% Unpacking structs
    % Mesh parameters
    elms = mesh.elms;
 
    % Discretisation paramters
    nx = disc.nx;
    nt = disc.nt;
 
    nq = max(size(xq));
 
    %% Element-wise assembly
    U = zeros(nq * nt, nq * nx);
    for i = 1:nx
        for j = 1:nt
            e = i + (j - 1) * nx;
            % Get elms dofs
            el_ids      = elms(e, :);
            el_dofs     = mapper(el_ids, nx, nt);

            % Evaluate u locally
            el_u = operator * u(el_dofs);
            % Populate evaluation
            J = ((j - 1) * nq + 1):(j * nq);
            I = ((i - 1) * nq + 1):(i * nq);
            U(J, I) = reshape(el_u, nq, nq).';
        end
    end
end