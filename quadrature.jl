using FastGaussQuadrature

function gaussquad(nq::Int; a::Float64=0.0, b::Float64=1.0)
    if a > b
        a, b = b, a;
    end
    x, w = gausslegendre(nq);
    w = (b - a) / 2 .* w;
    x = (b - a) / 2 .* x .+ (a + b) / 2;
    return x, w
end

