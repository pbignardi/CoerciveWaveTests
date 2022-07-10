function K = assemble_boundary(Kloc, mesh, disc, bound_elms, varargin)
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
    % Extract varargin parameters
    if length(varargin) == 2
        % Variable term integration parameters
        KlocVar     = varargin{1};
        component   = varargin{2};
        % Select the component along which to integrate variable terms
        if component == 1
            pp = xx;
        else 
            pp = tt;
        end
    elseif isempty(varargin)
        % Fixed term integration parameters
        KlocVar     = zeros(size(Kloc));
        pp          = zeros(size(xx));
    else
        error("Must specify KlocVar and component to integrate");
    end
   
    %% Assemble matrix
    Kg = zeros(16*16, nb_elms);
    Ig = zeros(16*16, nb_elms); 
    Jg = zeros(16*16, nb_elms);
    
    for e = 1:length(bound_elms)
        % Element nodes ids
        el_ids  = elms(bound_elms(e), :);
        el_dofs = mapper(el_ids, nx, nt);
        
        % Compute index matrices
        Jg(:, e) = reshape(kron(el_dofs, ones(16,1)), [], 1);
        Ig(:, e) = reshape(kron(ones(1,16), el_dofs.'), [], 1);

        % Pivot offset
        Koffset = pp(pivots(e)) * KlocVar;
        % Combine Kloc and variable local matrix
        Kg(:, e) = Kloc(:) + Koffset(:);
    end
    K = sparse(Ig, Jg, Kg, ndofs, ndofs);   
end
