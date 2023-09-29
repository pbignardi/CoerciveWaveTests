function E = ComputeEnergy(u, t, mesh, disc, problem)
    %% Parameters unpacking
    % Discretisation parameters
    nx = disc.nx;
    nt = disc.nt;
    hx = disc.hx;

    % Problem parameters
    c = problem.c;

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
       
        
        % evaluate operators
        tloc = (t(k) - disc.t(i))/disc.ht;
        eval_points = {xq, tloc};
        Ux = OperatorEval(u, mesh, disc, eval_points, 'ux', Omegat_elms);
        Ut = OperatorEval(u, mesh, disc, eval_points, 'ut', Omegat_elms);
        E(k) = 1/2 * (c^2 * Ux .* Ux + Ut .* Ut) * wqx.';
    end
end
