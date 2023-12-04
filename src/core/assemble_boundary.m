% Paolo Bignardi - Dec 2023
function K = assemble_boundary(Kloc, mesh, disc, bound_elms, component)
% Assemble global boundary matrix given the local matrix struct over the volume.
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

% Select the component along which to integrate variable coefficient terms
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
K = sparse(Ig, Jg, Kg, ndofs, ndofs);   
end
