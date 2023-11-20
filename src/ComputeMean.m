function m = ComputeMean(u, t, mesh, disc)
    %% Parameters unpacking
    % Mesh parameters
    elms = mesh.elms;
    
    % Discretisation parameters
    nx = disc.nx;
    nt = disc.nt;
    hx = disc.hx;
    xx = disc.xx.';

    nq = 9;
    [xq, wq] = gaussquad(nq);
    
    %% Basis function evaluation
    % Component basis evaluations
    [x_basis, ~, ~] = BasisEvaluation(xq);
    
    % Time basis evaluation at time t
    [t_basis, ~, ~] = BasisEvaluation(t);
    
    % Spacetime basis
    ref_basis = kron(t_basis, x_basis);

    %% Iterate over the elements
    % Locate in which elements time $t$ lies in
    ub = find(disc.t >= t, 1);
    % ub is the index of the element that contains t, except when t is the
    % last element of disc.t, in that case j is nt;
    j = min(ub, nt);
    local_mean = zeros(nx, 1);
    for i = 1:nx
        e = i + (j - 1) * nx;
        % Get elms dofs
        el_ids      = elms(e, :);
        el_dofs     = mapper(el_ids, nx, nt);
        u_el = ref_basis * u(el_dofs);
        local_mean(i, 1) = sum(u_el .* wq) * hx;
    end
    omega_measure = abs(disc.x(1) - disc.x(end));
    m = sum(local_mean) / omega_measure;
end