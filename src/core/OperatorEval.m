% Paolo Bignardi - Dec 2023
function [U, X, T] = OperatorEval(u, mesh, disc, xq, opname, varargin)
    % Evaluate operator over the gauss quadrature nodes
    % at the specified elements or over the whole mesh
    % NOTE: elements need to be specified in a grid (vertical array for side elms,
    % horizontal array for top and bot elms, matrix for all elements)
    %
    % INPUT
    %   u       : solution of the linear system
    %   mesh    : mesh of the problem
    %   disc    : discretization struct
    %   xq 	: cell array of eval points in x and t respectively
    %	opname 	: name of the operator to evaluate (see LocalOperatorEval for opts)
    % 	eval_elms: elements over which to evaluate the solution (optional)
    %
    % OUTPUT
    %	U 	: evaluation of opname over all the elements
    %   X   : x points of evaluation
    %   T   : t points of evaluation

    %% Unpacking structs
    % Mesh parameters
    elms = mesh.elms;
    pivots = mesh.pivots;
    xx = disc.xx.';
    tt = disc.tt.';
 
    % Discretisation paramters
    if isempty(varargin)
	    nelms = size(elms, 1);
	    eval_elms = reshape(1:nelms, [disc.nx, disc.nt]).';
    else
	    eval_elms = varargin{1};
    end

    nx = size(eval_elms, 2);
    nt = size(eval_elms, 1);
    [x, t] = xq{:};

    % create xt-element evaluation grid
    [xxqh, ttqh] = meshgrid(disc.hx * x, disc.ht * t);
 
    nqx = max(size(x));
    nqt = max(size(t));

    operator = LocalOperatorEval(xq, disc, opname);
	 
    %% Element-wise assembly
    U = zeros(nqt * nt, nqx * nx);
    X = zeros(nqt * nt, nqx * nx);
    T = zeros(nqt * nt, nqx * nx);
    for j = 1:nx
        for i = 1:nt
            e = eval_elms(i, j);
            % Get elms dofs
            el_pivot = pivots(e);
            el_ids      = elms(e, :);
            el_dofs     = mapper(el_ids, disc.nx, disc.nt);

	        % create evaluation meshgrid
	        el_x = xxqh + xx(el_pivot);
	        el_t = ttqh + tt(el_pivot);

            % Evaluate u locally
            el_u = operator * u(el_dofs);
            % Populate evaluation
            J = ((j - 1) * nqx + 1):(j * nqx);
            I = ((i - 1) * nqt + 1):(i * nqt);
            U(I, J) = reshape(el_u, nqx, nqt).'; % this is to reshape el_u by rows and not by columns
	        X(I, J) = el_x;
	        T(I, J) = el_t;
        end
    end
end

function OP = LocalOperatorEval(xq, disc, opname)
	% Evaluate local basis at points xq, operator opname
	%
	% INPUT:
	% 	xq: (cell array) eval points in x and t direction, respectively
	% 	opname: (string) name of the operator to evaluate. Possible values:
	% 		- "u": function value
	%		- "ux": space derivative
	% 		- "ut": time derivative
	% 		- "uxx": space second derivative
	% 		- "utt": time second derivative
	
	% Unpack space and time evaluation points
	[x, t] = xq{:};
	x = x(:);
	t = t(:);
	hx = disc.hx;
	ht = disc.ht;
	% Cases of operators
	switch opname
		case "u"
			[psix, ~, ~] = BasisEvaluation(x);
			[psit, ~, ~] = BasisEvaluation(t);
			OP = kron(psit, psix);
		case "ux"
			[~, dpsix, ~] = BasisEvaluation(x);
			[psit, ~, ~] = BasisEvaluation(t);
			OP = kron(psit, dpsix * hx ^ (-1));
		case "ut"
			[~, dpsit, ~] = BasisEvaluation(t);
			[psix, ~, ~] = BasisEvaluation(x);
			OP = kron(dpsit * ht ^ (-1), psix);
		case "uxx"
			[~, ~, ddpsix] = BasisEvaluation(x);
			[psit, ~, ~] = BasisEvaluation(t);
			OP = kron(psit, ddpsix * hx ^ (-2));
		case "utt"
			[psix, ~, ~] = BasisEvaluation(x);
			[~, ~, ddpsit] = BasisEvaluation(t);
			OP = kron(ddpsit * ht ^ (-2), psix);
		otherwise
			error("operator name %s is unknown", opname);
	end
end
