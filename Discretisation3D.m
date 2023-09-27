function disc = Discretisation3D(n_elms_x, n_elms_y, n_elms_t, domain)
%% Unpack domain values
xmin = domain.xmin;
xmax = domain.xmax;
ymin = domain.ymin;
ymax = domain.ymax;
T = domain.T;
%% Build struct
disc = struct();
disc.nx = n_elms_x;
disc.ny = n_elms_y;
disc.ny = n_elms_t;
% Mesh lengths in x, y and t
disc.hx = (xmax - xmin) / n_elms_x;
disc.hy = (ymax - ymin) / n_elms_y;
disc.ht = T / n_elms_t;
% Nodes vectors in x, y and t
x_nodes = linspace(xmin, xmax, n_elms_x + 1);
y_nodes = linspace(ymin, ymax, n_elms_y + 1);
t_nodes = linspace(0, T, n_elms_t + 1);
disc.x = x_nodes;
disc.y = y_nodes;
disc.t = t_nodes;
% Nodes matrices in x, y, t;
[disc.xx, disc.yy, disc.tt] = meshgrid(x_nodes, y_nodes, t_nodes);
end