function K = assemble(Kloc, mesh, disc, varargin)
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
    %% Assemble matrix
    K = spalloc(ndofs, ndofs, 16*ndofs);
    for e = 1:n_elms
        % Element nodes ids
        el_ids  = elms(e, :);
        el_dofs = mapper(el_ids, nx, nt);
        % Pivot offset
        Koffset = pp(pivots(e)) * KlocVar;
        % Combine Kloc and variable local matrix
        K(el_dofs, el_dofs) = K(el_dofs, el_dofs) + Kloc + Koffset;
    end
end
