% Paolo Bignardi - Dec 2023
function E = HermiteEvaluation(h, pos)
% HermiteEvaluation: compute matrix for the 1d Hermite element at the boundary
% of a local element of size h. Right or left side of the element is specified
% using pos: pos=0 is left side, pos=1 is right side.
%
% INPUT:
%   h: (float) size of the local element
%   pos: (0 or 1) position where to evaluate local matrices
% OUTPUT:
%   E: (struct) local matrices for the 1d hermite element evaluated at 0 or 1 in
%               the reference element

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
    else
        error('Provided pos argument is invalid. Only 0 or 1 are allowed');
    end

    E = struct();
    E.d0d0 = eval_matrix(v, v);
    E.d0d1 = h^(-1) * eval_matrix(dv, v);
    E.d1d0 = h^(-1) * eval_matrix(v, dv);
    E.d1d1 = h^(-2) * eval_matrix(dv, dv);
end
function M = eval_matrix(i,j)
    M = zeros(4,4);
    M(i,j) = 1;
end
