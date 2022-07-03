function dofs = mapper(el_ids, nx, nt)
    % map nodes_ids to degrees of freedom
    % The order is:
    % v(1) v(2) dxv(1) dxv(2)
    % v(3) v(4) dxv(3) dxv(4)
    % dyv(1) dyv(2) dxyv(1) dxvy(2)
    % dyv(3) dyv(4) dxyv(3) dxyv(4)
    n_nodes = (nx + 1) * (nt + 1);
    dofs = kron(el_ids, [1,1,1,1]) + n_nodes * kron([1,1,1,1], 0:3);
    % Shuffle the elements to get dofs [v(i), dxv(i), dyv(i), dxyv(i)]
    shuffle = [1, 5, 2, 6, 9, 13, 10, 14, 3, 7, 4, 8, 11, 15, 12, 16];
    dofs = dofs(shuffle);
end