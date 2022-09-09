function mesh = CartesianMesh(disc)
    % Enumerate the nodes and construct the elements by their indices.
    % Nodes are ordered according to Kronecker product of T and X.
    %% Unpacking parameters
    nx = disc.nx;
    nt = disc.nt;
    n_nodes = (nx + 1) * (nt + 1);
    n_elms = nx * nt;
    %% Enumerate nodes and pivots
    ids = 1:n_nodes;
    pivots = ids(and(...
        mod(ids, nx + 1), ...
        ids <= (nx + 1) * nt));
    %% Build and enumerate elements
    elms = zeros(nx * nt, 4);
    for e = 1:n_elms
        p = pivots(e);
        elms(e, :) = [p, p + 1, p + nx + 1, p + nx + 2];
    end
    %% Boundary definition
    bot    = 1:(nx + 1);
    top    = ids(end - nx:end);
    left   = 1:(nx + 1):n_nodes;
    right  = (nx+1):(nx + 1):n_nodes;

    %% Boundary elments
    bot_elms   = 1:nx;
    top_elms   = ((nx - 1) * nt + 1):n_elms;
    left_elms  = 1:nt:n_elms;
    right_elms = nx:nt:n_elms;

    mesh = struct("ids", ids, ...
        "pivots", pivots, ...
        "elms", elms, ...
        "bot", bot, ...
        "top", top, ...
        "left", left, ...
        "right", right, ...
        "bot_elms", bot_elms, ...
        "top_elms", top_elms, ...
        "left_elms", left_elms, ...
        "right_elms", right_elms);
end