% Paolo Bignardi - Dec 2023
function error_table = Convergence(problem, form, nElms, options)
%Convergence - compute convergence table and condition for the specified problem
% Optionally show the plot
%
%   INPUT:
%   problem: (struct) problem to solve (see WaveProblem.m)
%   form: (struct) parameters of the formulation (see FormParameters.m)
%   nElms: (int[]) number of elements in each direction
%   options.Nt:     (int) fix the number of elements in time direction
%   options.ShowPlot: (bool) show plot
%   options.ErrType:(string) either 'relative' or 'absolute'
%   options.Verbose:(bool) display additional information
%
%   OUTPUT:
%   error_table: table with columns
%       - H: mesh size
%       - Hx: x-component mesh size
%       - Ht: t-component mesh size
%       - nDOFs: number of degrees of freedom
%       - L2errors: numerical solution L2 error
%       - H1errors:  numerical solution H1 error
%       - Verrors: numerical solution V-norm error
%       - L2projErrors:  error of the L2 projection
%       - H1projErrors: error of the H1 projection
%       - VprojErrors: error of the V-norm projection
%       - QOconstEst: quasi optimality constant (see eq. (46))
%       - Kcond: condition number of B (see eq. (56))
arguments
    problem
    form
    nElms = 2.^(1:7)
    options.Nt { mustBeInteger }
    options.Verbose logical = true
    options.ShowPlot logical = true
    options.ErrType { mustBeText } = 'relative'
end

if isfield(options, 'Nt')
    options.TestCfl = true;
else
    options.TestCfl = false;
end

%% Display informations
% TODO: output something readable

%% Iterate for different number of elements
% Initialize the errors vectors
nDOFs = zeros(length(nElms), 1);
L2errors = zeros(length(nElms), 1);
H1errors = zeros(length(nElms), 1);
Verrors = zeros(length(nElms), 1);
% initialize the condition number vector
Kconds = zeros(length(nElms), 1);
% initialize the projection error vectors
L2projErrors = zeros(length(nElms), 1);
H1projErrors = zeros(length(nElms), 1);
VprojErrors = zeros(length(nElms), 1);
% populate the quasi-optimality for all discrete spaces
QOconstEst = ones(length(nElms), 1) * QuasiOptConstant(problem, form);

for i = 1:numel(nElms)
    nx = nElms(i);
    if ( options.TestCfl ); nt = options.Nt; else; nt = nElms(i); end
    disc = Discretization(nx, nt, problem.Q);
    mesh = CartesianMesh(disc);

    % Solve problem
    [u, Kcond] = SolverWaves(problem, mesh, disc, form);

    % Compute errors of solution
    errors = ComputeErrors(u, problem, mesh, disc, options.ErrType);
    L2errors(i) = errors.L2E;
    H1errors(i) = errors.H1E;
    Verrors(i) = errors.VnE;
    Kconds(i) = Kcond;

    % Compute errors of the projections
    [uL2proj, uH1proj, uVproj] = ProjectionBFS(problem, disc);
    % Compute error of L2 projection
    errors = ComputeErrors(uL2proj, problem, mesh, disc, options.ErrType);
    L2projErrors(i) = errors.L2E;
    % Compute error of H1 projection
    errors = ComputeErrors(uH1proj, problem, mesh, disc, options.ErrType);
    H1projErrors(i) = errors.H1E;
    % Compute error of V-norm projection
    errors = ComputeErrors(uVproj, problem, mesh, disc, options.ErrType);
    VprojErrors(i) = errors.VnE;

    % fill in the number of degrees of freedom
    nDOFs(i) = numel(u);
end

Hx = (problem.Q.xmax - problem.Q.xmin) ./ nElms.';
if options.TestCfl
    Ht = problem.Q.T ./ repmat(options.Nt, size(Hx));
else
    Ht = problem.Q.T ./ nElms.';
end
H = sqrt(Hx .^ 2 + Ht .^ 2);

%% Build table
error_table = table(H, Ht, Hx, L2errors, H1errors, Verrors, L2projErrors, ...
    H1projErrors, VprojErrors, QOconstEst, nDOFs, Kconds);

end
