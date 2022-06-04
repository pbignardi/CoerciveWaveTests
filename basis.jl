using Symbolics

struct AbstractBasis
    local_dof::Int
    regularity::Int
    D::Differential
end

struct Basis <: AbstractBasis
    variable::Num
    f::Vector{Num}
end