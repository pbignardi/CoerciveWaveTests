% Paolo Bignardi - Dec 2023
function U = OperatorBoundaryEval(u, mesh, disc, xq, operator, boundary)
% Evaluate operator over the gauss quadrature nodes over the boundary given

%% Unpacking structs 
elms = mesh.elms;

% Discretisation parameters
nx = disc.nx;
nt = disc.nt;

nq = max(size(xq));

%% Element-wise assembly
U = zeros(nq * numel(boundary), 1);

for i = 1:numel(boundary)
    e = boundary(i);
    el_ids = elms(e, :);
    el_dofs = mapper(el_ids, nx, nt);

    el_u = operator * u(el_dofs);
    I = ((i-1) * nq + 1):(i * nq);
    U(I) = reshape(el_u, [], 1);
end
end
