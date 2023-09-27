% Apr 2023 - Paolo Bignardi
% Test 2D sparse grids using combination technique
% Steps:
%   * Create a sequence of spaces (more realisticly of nx and nt)
%   * Define a J and sigma and compute combination coefficients
%   * Define a common grid to evaluate the solution (nx[N] \times nt[N])
%   * iterate over combination coefficients j1,j2
%       - Solve problem for (nx[j1], nt[j2]) and (nx[j1], nt[j2 - 1]).
%       Change accordingly if summing over rows
%       - Evaluate the solution over the common grid and store it somewhere
%       - Do the combination of (nx[j1], nt[j2]) and (nx[j1], nt[j2 - 1]).
%   *% Update the combined \hat{u}_J

%% Define problem
p = WaveProblem(7);
Q = Domain(-1, 1, 1);

%% Define parameters
% Maximum number of spaces in t- and x- direction
Nt_max = 12;
Nx_max = 12;
% Sequences of number of elements in t- and x- direction
nxs = 2.^(1:Nx_max);
nts = 2.^(1:Nt_max);

% Define J and sigma (and check if J <= min(Nt_max, Nx_max))
J = 5; 
sigma = 1;

if J > min(Nt_max, Nx_max)
    warning("J > Nt_max, Nx_max. Fallback to J = min(Nt_max, Nx_max)");
    J = min(Nt_max, Nx_max);
end

cols = true;

% Compute the combination coefficients
[c1, c2] = CombinationCoefficients(J - 1, sigma, cols);

%% Construct common mesh
% Construct ultra-fine mesh for evaluation
d_fine = Discretization(nxs(J), nts(J), Q);
mesh_fine = CartesianMesh(d_fine);

% Quadrature points over ultra-fine mesh
[Xq, Wq] = QuadratureGrid(d_fine, 7);
QP_x = Xq(:, 1); QP_t = Xq(:, 2);
QW_x = Wq(:, 1); QW_t = Wq(:, 2);
Wqxt = kron(QW_t.', QW_x);

%% Compute CT solution
[X, T, u_ct] = CTSolve(J, sigma, p, Q, [nxs.', nts.'], Xq);

% Plot solution
pcolor(QP_x, QP_t, u_ct);
shading flat

%% Compute L2 error

Uex_eval = p.u(X, T);
err = Uex_eval - u_ct;
l2error = sqrt(sum(err(:) .* err(:) .* Wqxt(:)))

%% TODO
% - Compute the condition number and check the max condition number for
% each problem solved for J fixed
%
% Q: Test convergence order as J increases
% A: Convergence order looks good. But the error is not well aligned
%
% - Understand how to choose on (16) or (17) depending on sigma
%
% Q: Can we achieve the same error with
% either one of the problems solved?
% A: It does make a difference. All the erros we obtain are at most 1e-7
% (just in one case, other cases are well below) and the combination one
% gives you 1e-8 l2error.

% Q: Test computational cost (FLOPS, time elapsed, memory used)
% A: 
