function K = assemble_boundary(Kloc, mesh, disc, boundary, varargin)
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
    %% Boundary elements
    

     %% Assemble matrix
    Kg = zeros(16*16, n_elms);
    Ig = zeros(16*16, n_elms);
    Jg = zeros(16*16, n_elms);
    
    for e = 1:n_elms
        % Element nodes ids
        el_ids  = elms(e, :);
        el_dofs = mapper(el_ids, nx, nt);
        
        % Compute index matrices
        Jg(:, e) = reshape(kron(el_dofs, ones(16,1)), [], 1);
        Ig(:, e) = reshape(kron(ones(1,16), el_dofs.'), [], 1);
        if any(ismember(boundary, el_ids))
            % Pivot offset
            Koffset = pp(pivots(e)) * KlocVar;
            % Combine Kloc and variable local matrix
            Kg(:, e) = Kloc(:) + Koffset(:);
        end
    end
    K = sparse(Ig, Jg, Kg, ndofs, ndofs);   
end
