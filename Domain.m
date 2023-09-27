function domain = Domain(xmin, xmax, T)
    domain = struct();
    domain.xmin = xmin;
    domain.xmax = xmax;
    domain.T = T;
    domain.L = abs(xmin-xmax);
    domain.delta = min(abs(xmin), xmax) / domain.L;
end