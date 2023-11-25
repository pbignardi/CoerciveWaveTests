function varargout = ComputeEnergy(u, t, mesh, disc, problem)
% Compute the energy of the discrete solution, of the exact solution and of the
% numerical error E(t; u-u_h)
%
% INPUTS:
%   u: (float[]) dofs of the discrete solution
%   t: (float[]) vector of time evaluations where to compute energy
%   mesh: (struct) mesh of the domain (see CartesianMesh.m)
%   disc: (struct) discretization of the domain (see Discretization.m)
%   problem: (struct) wave problem struct (see WaveProblem.m)
%
% OUTPUT:
%   E_h: (float[])_energy of the discrete solution
%   E: (float[])_energy of the exact solution
%   error_energy: (float[]) energy of the error at each timestep t

    % Discretisation parameters
    nx = disc.nx;
    nt = disc.nt;
    hx = disc.hx;

    % Problem parameters
    c = problem.c;
    dx_u = @problem.dx_u;
    dt_u = @problem.dt_u;

    % Quadrature data
    nq = 9;
    [xq, wq] = gaussquad(nq);
    wqx = reshape(wq, 1, []) * hx;
    wqx = repmat(wqx, 1, nx);

    E = zeros(size(t));
    % map time into each reference element
    i = 1;
    Omegat_elms = reshape(mesh.bot_elms, 1, []);
    for k = 1:numel(t)
        while i < nt && ~(disc.t(i) <= t(k) && disc.t(i + 1) > t(k))
        i = i + 1;
        Omegat_elms = Omegat_elms + nx;
        end

        % map point t(k) into reference element
        tloc = (t(k) - disc.t(i))/disc.ht;
        % construct xt-evaluation points
        eval_nodes = {xq, tloc};

        [Ux, X, T] = OperatorEval(u, mesh, disc, eval_nodes, 'ux', Omegat_elms);
        [Ut, ~, ~] = OperatorEval(u, mesh, disc, eval_nodes, 'ut', Omegat_elms);
        Ux_ex = dx_u(X, T);
        Ut_ex = dt_u(X, T);

        discrete_energy(k) = 1/2 * (c^2 * (Ux).^2 + (Ut).^2) * wqx.';
        exact_energy(k) = 1/2 * (c^2 * (Ux_ex).^2 + (Ut_ex).^2) * wqx.';
        error_energy(k) = 1/2 * (c^2*(Ux - Ux_ex).^2 + (Ut - Ut_ex).^2) * wqx.';
    end

    varargout{1} = discrete_energy;
    varargout{2} = exact_energy;
    varargout{3} = error_energy;
end
