function disc = Discretization(n_elms_x, n_elms_t, domain)
    %% Unpack domain values
    xmin = domain.xmin;
    xmax = domain.xmax;
    T = domain.T;
    %% Build struct 
    disc = struct();
    disc.nx = n_elms_x;                                                     
    disc.nt = n_elms_t;                                                      
    % Mesh lengths in x and t
    disc.hx = (xmax - xmin) / n_elms_x;
    disc.ht = T / n_elms_t;
    % Nodes vectors in x and t
    x_nodes = linspace(xmin, xmax, nx + 1);
    t_nodes = linspace(0, T, nt + 1).';
    disc.x = x_nodes;
    disc.t = t_nodes;
    % Nodes matrices in x and t
    disc.XX = kron(ones(nt + 1, 1), x_nodes);
    disc.TT = kron(t_nodes, ones(1, nx + 1));
end


