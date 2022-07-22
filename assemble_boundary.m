function K = assemble_boundary(Kloc, mesh, disc, bound_elms, component)
    %% Unpack parameters
    % Discretisation parameters
    nx = disc.nx;
    nt = disc.nt;
    xx = disc.xx.';
    tt = disc.tt.';
    % Mesh parameters
    pivots  = mesh.pivots;
    elms    = mesh.elms;
    nb_elms = length(bound_elms);
    % Other parameters
    n_nodes = (nx + 1) * (nt + 1);
    ndofs = 4*n_nodes;
    
    % Extract Kloc matrices
    opB     = Kloc.op;
    opBx    = Kloc.opx;
    opBxVar = Kloc.opxVar;

    % Select the component along which to integrate variable terms
    if component == 1
        pp = xx;
    else 
        pp = tt;
    end
   
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
        Kg(:, e) = opB(:) + opBx(:) + ... 
            pp(pivots(el)) * opBxVar(:);
    end
    K = sparse(Ig, Jg, Kg, ndofs + 1, ndofs);   
end
