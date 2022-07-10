function K = assemble(Kloc_struct, mesh, disc)
    %% Unpack parameters
    % Discretisation parameters
    nx = disc.nx;
    nt = disc.nt;
    xx = disc.xx.';
    tt = disc.tt.';
    % Mesh parameters
    elms    = mesh.elms;
    pivots  = mesh.pivots;
    n_elms  = size(elms,1);
    % Other parameters
    n_nodes = (nx + 1) * (nt + 1);
    ndofs = 4*n_nodes;
    % Extract opQ* matrix
    opQ     = Kloc_struct.op;
    opQx    = Kloc_struct.opx;
    opQt    = Kloc_struct.opt;
    opQxVar = Kloc_struct.opxVar;
    opQtVar = Kloc_struct.optVar;

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
        Kg(:, e) = opQ(:) + ...
            opQx(:) + opQxVar(:) * xx(pivots(e)) + ...
            opQt(:) + opQtVar(:) * tt(pivots(e));
    end
    K = sparse(Ig, Jg, Kg, ndofs, ndofs);
    toc
end
