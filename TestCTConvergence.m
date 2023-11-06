% Apr 2023 - Paolo Bignardi
% Convergence test for combination technique with coercive wave formulation
%% Define problem
p = WaveProblem(6);
Q = Domain(-1, 1, 1);
err_type = "relative";

% Define parameters
% Maximum number of spaces in t- and x- direction
Nt_max = 12;
Nx_max = 12;
% Sequences of number of elements in t- and x- direction
nxs = 2.^(1:Nx_max);
nts = 2.^(1:Nt_max);

% Define sigma, and choose cols true or false. Pick JMax
sigma = 1;
cols = true;
JMax = 9;

% Initialize error vector
L2error = zeros(JMax, 1);

%% Construct common mesh
% Construct ultra-fine mesh for evaluation
d_fine = Discretization(nxs(JMax), nts(JMax), Q);
mesh_fine = CartesianMesh(d_fine);

% Quadrature points over ultra-fine mesh
[Xq, Wq] = QuadratureGrid(d_fine, 5);
% Compute X, T
[X, T] = meshgrid(Xq(:, 1), Xq(:, 2));
% Unpack weights
QW_x = Wq(:, 1);    QW_t = Wq(:, 2);
% Tensorize space-time weights
Wqxt = kron(QW_t.', QW_x);
% Evaluate exact solution over ultra-fine mesh

Uex = p.u(X, T);

%% Iterate over J
for J = 1:JMax
    % Compute CT solution
    [X, T, U] = CTSolve(J, sigma, p, Q, [nxs.', nts.'], Xq);
    % Compute L2 error
    err = Uex - U;
    L2error(J) = sqrt(sum(err(:) .* err(:) .* Wqxt(:)));
    if err_type == "relative"
        L2error(J) = L2error(J)/sqrt(sum(Uex(:) .* Uex(:) .* Wqxt(:)));
    end
end

%% Convergence plot
figure("Name","Convergence Plot")
set(gca, "YScale", "log");
hold on
semilogy(1:JMax, L2error, '-x');
semilogy(1:JMax, 4.^(-(1:JMax)), '--o');
semilogy(1:JMax, 4.^(-(1:JMax)).*sqrt(1:JMax), '--s');
hold off
grid on
legend("$L_2$ error", "$4^{-J}$", "$4^{-J}\sqrt{J}$", "Interpreter", "latex");
