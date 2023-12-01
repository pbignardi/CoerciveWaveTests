function conv_table = EnergyConvergence(problem, form, nElms,  options)
%Energy Convergence - convergence of sup_t of the energy as h\rightarrow 0
% for t \in [0,T]
%   INPUT:
%   problem: (struct) problem to solve (see WaveProblem.m)
%   form: (struct) parameters of the formulation (see FormParameters.m)
%   nElms: (int[]) number of elements in each direction
%   options.Verbose:(bool) display additional information
%   options.ErrType:(string) either 'relative' or 'absolute'
%
%   OUTPUT:
%   conv_table: table with errors as h\rightarrow0. Columns are
%       - H: mesh size 
%       - ErrorEnergy: energy of the error E(t; u-u_h)
%       - NumericalEnergyError: error |E(t; u) - E(t;u_h)|
%       - VprojErrorSq: squared V-norm projection error
%
arguments
    problem
    form
    nElms = 2.^(1:7)
    options.Verbose logical = true
    options.ErrType {mustBeText} = 'relative'
end

t = linspace(0, problem.Q.T, 6 * 128);

%% Display information
%TODO

%% Iterate for different number of elements
ErrorEnergy = zeros(numel(nElms), 1);
VprojErrorSq = zeros(numel(nElms), 1);
NumericalEnergyError = zeros(numel(nElms), 1);

for i = 1:numel(nElms)
    disc = Discretization(nElms(i), nElms(i), problem.Q);
    mesh = CartesianMesh(disc);
    u = SolverWaves(problem, mesh, disc, form);

    [~, ~, uVproj] = ProjectionBFS(problem, disc);
    sup_energy = max(ComputeEnergy(u, t, mesh, d, problem));
    ErrorEnergy(i) = sup_energy.ErrorEnergy / sup_energy.UEnergy;
    NumericalEnergyError(i) = sup_energy.NumericalEnergyError / ...
        sup_enegy.UEnergy;
    errors = ComputeErrors(uVproj, problem, mesh, d, options.ERR_TYPE);
    VprojErrorsSq(i) = errors.VnE^2;
    i = i + 1;
end

Hx = (problem.Q.xmax - problem.Q.xmin) ./ options.N.';
Ht = problem.Q.T ./ options.N.';
H = sqrt(Hx .^2 + Ht .^ 2);

%% Build table and write to file
conv_table = table(H, ErrorEnergy, NumericalEnergyError, VprojErrorSq);

end
