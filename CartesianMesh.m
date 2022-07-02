function mesh = CartesianMesh(disc)
    % Enumerate the nodes and construct the elements by their indices.
    % Nodes are ordered according to Kronecker product of T and X.
    mesh = struct();
    %% Unpacking parameters
    nx = disc.nx;
    nt = disc.nt;
    n_nodes = (nx + 1) * (nt + 1);
    n_elms = nx * nt;
    %% Enumerate nodes and pivots
    mesh.ids = 1:n_nodes;
    mesh.pivots = mesh.ids(and(...
        mod(mesh.ids, nx + 1), ...
        mesh.ids <= (nx + 1) * nt));
    %% Build and enumerate elements
    mesh.elms = zeros(nx * nt, 4);
    for e = 1:n_elms
        p = mesh.pivots(e);
        mesh.elms(e, :) = [p, p + 1, p + nx + 1, p + nx + 2];
    end
    %% Boundary definition
    mesh.bot    = 1:(nx + 1);
    mesh.top    = mesh.ids(end - nx:end);
    mesh.left   = 1:(nx + 1):n_nodes;
    mesh.right  = nx:(nx + 1):n_nodes;
end