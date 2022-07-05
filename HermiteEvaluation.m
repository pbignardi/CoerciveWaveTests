function E = HermiteEvaluation(h, pos)
    % Check if is an evaluation at the start or the end of the interval
    if pos == 0
        % If at start of interval:
        % v_eval dof is at 1
        v = 1;
        % dv_eval dof is at 3
        dv = 3;
    elseif pos == 1
        % If at end of interval
        % v_eval dof is at 2
        v = 2;
        % dv_eval dof is at 4
        dv = 4;
    end

    E = struct();
    E.d0d0 = eval_matrix(v,v);
    E.d0d1 = h^(-1) * eval_matrix(v, dv);
    E.d1d0 = h^(-1) * eval_matrix(dv, v);
    E.d1d1 = h^(-2) * eval_matrix(dv,dv);
end
function M = eval_matrix(i,j)
    M = zeros(4,4);
    M(i,j) = 1;
end