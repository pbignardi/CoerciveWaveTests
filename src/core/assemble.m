function K = assemble(Kloc, mesh, disc)
% Assemble global matrix given the local matrix struct over the volume.
% Construct global matrix using the sparse function included in MATLAB for fast
% assembly.
%
% INPUT:
%   Kloc: (struct) local matrices struct (const coeff, x- and t- variable coeff)
%   mesh: (struct) mesh data for the domain (see CartesianMesh.m)
%   disc: (struct) discretization data for the domain (see Discretization.m)
%
% OUTPUT:
%   K: (float[][]) assemble global matrix
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
% Extract opQ* matrix
opQ     = Kloc.op;
opQx    = Kloc.opx;
opQt    = Kloc.opt;
opQxVar = Kloc.opxVar;
opQtVar = Kloc.optVar;

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

    % Combine Kloc and variable local matrix
    % So only one assemble call is necessary
    Kg(:, e) = opQ(:) + ...
    opQx(:) + opQxVar(:) * xx(pivots(e)) + ...
    opQt(:) + opQtVar(:) * tt(pivots(e));
end
K = sparse(Ig, Jg, Kg, ndofs, ndofs);
end
