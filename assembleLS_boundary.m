function K = assembleLS_boundary(Kloc, mesh, disc, bound_elms)
    %% Unpack parameters
    % Discretisation parameters
    nx = disc.nx;
    nt = disc.nt;
    % Mesh parameters
    elms    = mesh.elms;
    nb_elms = length(bound_elms);
    % Other parameters
    n_nodes = (nx + 1) * (nt + 1);
    ndofs = 4*n_nodes;
   
    %% Assemble matrix
    Kg = zeros(16*16, nb_elms);
    Ig = zeros(16*16, nb_elms); 
    Jg = zeros(16*16, nb_elms);
    
    for e = 1:nb_elms
        el = bound_elms(e);
        % Element nodes ids
        el_ids  = elms(el, :);
        el_dofs = mapper(el_ids, nx, nt);
        
        % Compute index matrices
        Jg(:, e) = reshape(kron(el_dofs, ones(16,1)), [], 1);
        Ig(:, e) = reshape(kron(ones(1,16), el_dofs.'), [], 1);

        % Combine Kloc and variable local matrix
        Kg(:, e) = Kloc(:);
    end
    K = sparse(Ig, Jg, Kg, ndofs, ndofs);   
end
