using Meshes

# extend the SimpleMesh struct to include also the boundary
struct SpaceTimeMesh
    space_mesh::SimpleMesh
    space_boundary::Vector{Int}
    t0_boundary::Vector{Int}
    tend_boundary::Vector{Int}
end
