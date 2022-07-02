function domain = Domain(xmin, xmax, T)
    domain = struct();
    domain.xmin = xmin;
    domain.xmax = xmax;
    domain.T = T;
    domain.L = abs(xmin-xmax);
    domain.delta = min(-1*xmin, xmax) / domain.L;
end