using Kronecker, Meshes, Pipe, SparseArrays

function assemble(Kloc::Matrix, local_dofs::Int, mesh::SimpleMesh)
    # Kloc: the local stiffness matrix
    # local_dofs: the number of DOF for each node of the mesh
    # mesh: mesh of the problem, in SimpleMesh type
    
    n_global_nodes = length(mesh.points)
    global_dofs = local_dofs * n_global_nodes
    
    # Initialize the global matrix
    K = spzeros(global_dofs, global_dofs)
    
    # local stencil to pick the functions from the basis
    local_stencil = 1:local_dofs

    for e in mesh.topology.elms
        el_nodes = mesh.topology.connec[e].indices |> collect
        n_local_nodes = el_nodes |> length
        stencil =  (local_dofs*(el_nodes .- 1)) ⊗ ones(Int, local_dofs) + ones(Int, n_local_nodes) ⊗ local_stencil |> vec
        K[stencil,stencil] = K[stencil, stencil] + Kloc
    end
    
    return K
end

function assemble(f::Function, local_dofs::Int, mesh::SimpleMesh)
    # f: function to integrate over the domain (w/o boundary terms)
    # local_dofs: number of DOF for each node of the mesh
    # mesh: mesh of the problem in SimpleMesh type

    n_global_nodes = length(mesh.points)
    global_dofs = local_dofs * n_global_nodes

    # initialize the rhs vector
    rhs = zeros(global_dofs)

    # local stencil to pick the functions from the basis
    local_stencil = 1:local_dofs

end