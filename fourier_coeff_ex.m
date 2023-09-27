% Compute Fourier coefficients for weird example
phi0 = @(x) x.*0 + 1/sqrt(pi);
phi2k = @(x, k) 1/sqrt(pi) * cos(k*x);
phi2km1 = @(x, k) 1/sqrt(pi) * sin(k*x);

u0 = @(x) x .* (cos(x) + 1);
u = @(x, t) u0(x - t).*(x - t + pi >= 0);

KMAX = 10;
N = 10;
NT = 100;
Ts = linspace(0, 2*pi, NT);
[xq, wq] = gaussquad(7);
fourier_coeff = zeros(2*KMAX+1, NT);
for i = 1:numel(Ts)
    fourier_coeff(1, i) = sum(u(xq*2*pi-pi, Ts(i)) .* phi0(xq*2*pi-pi) .* wq);
    for k = 1:KMAX 
        xps = linspace(-pi, pi, N + 1);
        h = xps(2) - xps(1);
        I2k = 0; I2km1 = 0;
        for xp = xps(1:end-1)
            xqh = xq * h + xp;
            wqh = wq * h;
            I2k = I2k + sum(u(xqh, Ts(i)) .* phi2k(xqh, k) .* wqh);
            I2km1 = I2km1 + sum(u(xqh, Ts(i)) .* phi2km1(xqh, k) .* wqh);
        end
        fourier_coeff(2*k,i) = I2km1;
        fourier_coeff(2*k+1,i) = I2k;
    end
end

TOPLOT = 1;
plot(Ts,fourier_coeff(TOPLOT, :))
