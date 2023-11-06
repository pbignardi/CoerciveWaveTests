function E = ComputeExactEnergy(t, problem)
gradu_fun = @(x) problem.dx_u(x, t) .^2;
dtu_fun = @(x) problem.dt_u(x, t) .^2;
dnu_fun = @(x) problem.dx_u(x, t).^2.*(x==problem.Q.xmax) + ...
    problem.dx_u(x, t).^2.*(x==problem.Q.xmin);
E = problem.c.^2*integral(gradu_fun, problem.Q.xmin, problem.Q.xmax) + ...
    integral(dtu_fun, problem.Q.xmin, problem.Q.xmax);
E = E / 2;
end