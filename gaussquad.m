function [x, w] = gaussquad(n)
% Generates the abscissa and weights for a Gauss-Legendre quadrature.
% Reference:  Numerical Recipes in Fortran 77, Cornell press.
    % Preallocations.
    x = zeros(n,1);                                           
    w = x;
    m = (n+1)/2;
    for ii=1:m
        % Initial estimate.
        z = cos(pi*(ii-.25)/(n+.5));                        
        z1 = z+1;
        pp = 0;
        while abs(z-z1)>eps
            p1 = 1;
            p2 = 0;
            for jj = 1:n
                p3 = p2;
                p2 = p1;
                % The Legendre polynomial.
                p1 = ((2*jj-1)*z*p2-(jj-1)*p3)/jj;       
            end
            % The L.P. derivative.
            pp = n*(z*p1-p2)/(z^2-1);                        
            z1 = z;
            z = z1-p1/pp;
        end
        % Build up the abscissas.
        x(ii) = -z;                                  
        x(n+1-ii) = z;
        % Build up the weights.
        w(ii) = 2/((1-z^2)*(pp^2));                     
        w(n+1-ii) = w(ii);
    end
    w = w/2;
    x = x/2 + 1/2;
end