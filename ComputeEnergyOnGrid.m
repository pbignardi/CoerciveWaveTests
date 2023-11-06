function [E, T] = ComputeEnergyOnGrid(u, mesh, disc, problem)
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
    tq = linspace(0, 1, 10);
    
    [Ux, ~, T] = OperatorEval(u, mesh, disc, {xq, tq}, 'ux');
    Ut = OperatorEval(u, mesh, disc, {xq, tq}, 'ut');
    T = T(:, 1);
    E = 1/2 * reshape((c^2 * Ux .* Ux + Ut .* Ut) * wqx.', [], 1);
end
