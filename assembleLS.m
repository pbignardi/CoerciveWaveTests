function K = assembleLS(Kloc, mesh, disc)
    %% Unpack parameters
    % Discretisation parameters
    nx = disc.nx;
    nt = disc.nt;
    % Mesh parameters
    elms    = mesh.elms;
    n_elms  = size(elms,1);
    % Other parameters
    n_nodes = (nx + 1) * (nt + 1);
    ndofs = 4*n_nodes;
    % Extract opQ* matrix

    %% Assemble matrix
    Kg = zeros(16*16, n_elms);
    Ig = zeros(16*16, n_elms);
    Jg = zeros(16*16, n_elms);
    tic
    for e = 1:n_elms
        % Element nodes ids
        el_ids  = elms(e, :);
        el_dofs = mapper(el_ids, nx, nt);
        
        % Compute index matrices
        Jg(:, e) = reshape(kron(el_dofs, ones(16,1)), [], 1);
        Ig(:, e) = reshape(kron(ones(1,16), el_dofs.'), [], 1);
        
        % Combine Kloc and variable local matrix
        % So only one assemble call is necessary
        Kg(:, e) = Kloc(:);
    end
    K = sparse(Ig, Jg, Kg, ndofs, ndofs);
    assembly_time = toc;
    % fprintf("Global matrix assembly time:\t %.4f seconds\n", assembly_time);
end
