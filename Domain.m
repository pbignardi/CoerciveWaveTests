function domain = Domain(T, xmin, xmax, varargin)
    domain = struct();
    
    if length(varargin) == 2
        domain.ymin = varargin{1};
        domain.ymax = varargin{2};
    elseif isempty(varargin)
        domain.ymin = 0;
        domain.ymax = 0;
    else
        warning("Check domain of y variable!");
    end
    domain.xmin = xmin;
    domain.xmax = xmax;
    domain.T = T;
    domain.L = abs(xmin-xmax);
    domain.delta = min(abs(xmin), xmax) / domain.L;
end