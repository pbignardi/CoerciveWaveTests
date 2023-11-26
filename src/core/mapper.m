function dofs = mapper(el_ids, nx, nt)
    % map nodes_to degrees of freedom
    % The order is:
    % v(1) v(2) dxv(1) dxv(2)
    % v(3) v(4) dxv(3) dxv(4)
    % dyv(1) dyv(2) dxyv(1) dxvy(2)
    % dyv(3) dyv(4) dxyv(3) dxyv(4)
    n_nodes = (nx + 1) * (nt + 1);
    el_base = repmat(el_ids, 4, 1);
    dofs_shift = repmat([0;n_nodes;2*n_nodes;3*n_nodes], 1, 4);
    dofs = reshape(el_base + dofs_shift, 1, []);
    % Shuffle the elements to get dofs ordered [v(i), dxv(i), dyv(i), dxyv(i)]
    v_dofs = [1, 5, 2, 6];
    dxv_dofs = [9, 13, 10, 14];
    dyv_dofs = [3, 7, 4, 8];
    dxyv_dofs = [11, 15, 12, 16];
    shuffle = [v_dofs, dxv_dofs, dyv_dofs, dxyv_dofs];
    dofs = dofs(shuffle);
end
