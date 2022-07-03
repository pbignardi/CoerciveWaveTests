function K = assemble(Kloc, mesh, disc)
    %% Unpack parameters
    % Discretisation parameters
    nx = disc.nx;
    nt = disc.nt;
    % Mesh parameters
    elms = mesh.elms;
    n_elms = size(elms,1);
    % Other parameters
    n_nodes = (nx + 1) * (nt + 1);
    ndofs = 4*n_nodes;
    %% Assemble matrix
    K = spalloc(ndofs, ndofs, 16*ndofs);
    for e = 1:n_elms
        el_ids  = elms(e, :);
        el_dofs = mapper(el_ids, nx, nt);
        K(el_dofs, el_dofs) = K(el_dofs, el_dofs) + Kloc;
    end
end
