function mesh = CartesianCubeMesh(disc)
% Enumerate the nodes and construct the elements by their indices.
% Nodes are ordered according to Kronecker product of T, Y, X
mesh = struct();
%% Unpacking parameters
nx = disc.nx;
ny = disc.ny;
nt = disc.nt;
n_nodes = (nx + 1) * (ny + 1) * (nt + 1);
n_elms = nx * ny * nt;
%% Enumerate nodes and pivots
mesh.ids = reshape(1:n_nodes, nx + 1, ny + 1, nt + 1);
mesh.pivots = reshape(mesh.ids(1:end-1, 1:end-1, 1:end-1), [], 1);
%% Build and enumerate elements
mesh.elms = zeros(nx * ny * nt, 8);
for e = 1:n_elms
    p = mesh.pivots(e);
    bot_level = [p, p + 1, p + 1 + nx, p + 2 + nx];
    top_level = bot_level + (nx + 1) * (ny + 1);
    mesh.elms(e, :) = [bot_level, top_level];
end
%% Boundary definition
mesh.bot    = reshape(mesh.ids(:, :, 1), [], 1);
mesh.top    = reshape(mesh.ids(:, :, end), [], 1);
mesh.left   = reshape(mesh.ids(1, :, :), [], 1);
mesh.right  = reshape(mesh.ids(end, :, :), [], 1);
mesh.front  = reshape(mesh.ids(:, 1, :), [], 1);
mesh.back   = reshape(mesh.ids(:, end, :), [], 1);

%% Boundary elements
elm_ids = reshape(1:n_elms, nx, ny, nt);
mesh.bot_elms   = reshape(elm_ids(:, :, 1), [], 1);
mesh.top_elms   = reshape(elm_ids(:, :, end), [], 1);
mesh.left_elms  = reshape(elm_ids(1, :, :), [], 1);
mesh.right_elms = reshape(elm_ids(end, :, :), [], 1);
mesh.front_elms = reshape(elm_ids(:, 1, :), [], 1);
mesh.back_elms  = reshape(mesh.ids(:, end, :), [], 1);

end