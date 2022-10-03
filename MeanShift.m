function u = MeanShift(u, mean, mesh)
    %% Parameters unpacking
    % Mesh parameters
    elms = mesh.elms;
    n_nodes = max(max(elms));
    
    %% Shift
    % 1:n_nodes DOFS are related to function evaluation
    u(1:n_nodes) = u(1:n_nodes) - mean;

end