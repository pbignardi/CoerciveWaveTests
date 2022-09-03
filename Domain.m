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
    domain.L = norm([domain.xmax domain.ymax] - [domain.xmin domain.ymin]);
    vertices = [domain.xmin    domain.ymin;
                domain.xmax    domain.ymin;
                domain.xmax    domain.ymax;
                domain.xmin    domain.ymax].';
    delta = 1;
    % 
    for v = vertices
        % Ignore component with a null component
        if v(1) ~= 0
            v1 = v(1);
        else
            v1 = v(2);
        end
        if v(2) ~= 0
            v2 = v(2);
        else
            v2 = v(1);
        end
        % (x . n) is picking one of the two component, ignore the ones with
        % a null component
        delta = min(delta, min(abs(v1), abs(v2)));
    end
    domain.delta = delta / domain.L;
end