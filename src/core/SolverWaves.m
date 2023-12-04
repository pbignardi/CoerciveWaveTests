% Paolo Bignardi - Dec 2023
function varargout = SolverWaves(problem, mesh, disc, form)
% Solve the interior impedance problem using BFS element.
%
% INPUT:
%   problem: (struct) problem description
%   mesh: (struct) mesh structure of the problem 
%   disc: (struct) struct of discretisation parameters 
%   form: (struct) struct with parameters of the formulation
%
% OUTPUT:
%   u: (float[]) dof vector of solution
%   Kcond: (float) condition number of the stiffness matrix

% Parse variable input arguments
arguments
    problem
    mesh
    disc
    form
end

%% Unpacking parameters
% Problem unpacking
c       = problem.c;
theta   = problem.theta;

% Domain unpacking
T       = problem.Q.T;
a       = problem.Q.xmin;
b       = problem.Q.xmax;

% Elements unpacking
nx = disc.nx;
nt = disc.nt;
hx = disc.hx;
ht = disc.ht;

% Boundary elms unpacking
top_elms    = mesh.top_elms;
right_elms  = mesh.right_elms;
left_elms   = mesh.left_elms;
bot_elms    = mesh.bot_elms;

% Formulation unpacking
BETA = form.BETA;
NU = form.NU;
XI = form.XI;
A = form.A;
A0 = form.A0;
Tstar   = NU*T;

% Other parameters
d = 1;
x_var = 1;
t_var = 2;

%% Local operator structs
Xb = HermiteBasis(hx);
Tb = HermiteBasis(ht);

%% Local evaluation structs
Ea = HermiteEvaluation(hx, 0);
Eb = HermiteEvaluation(hx, 1);
ET = HermiteEvaluation(ht, 1);
E0 = HermiteEvaluation(ht, 0);

%% (Fixed) Local operator over Q
% gradu * gradv * c^2 * (BETA - XI)
opQ = kron(Tb.d0d0, Xb.d1d1) * c^2 * (BETA + (2 - d) * XI);
% ut * vt * (BETA + XI)
opQ = opQ + kron(Tb.d1d1, Xb.d0d0) * (BETA + d * XI);
% Lap u * Lap v
opQ = opQ + kron(Tb.d0d0, Xb.d2d2) * c^4 * A / (T^2);
% - Lap u * vtt
opQ = opQ - kron(Tb.d0d2, Xb.d2d0) * c^2 * A / (T^2);
% - utt * Lap v * c^2 * A / T^2
opQ = opQ - kron(Tb.d2d0, Xb.d0d2) * c^2 * A / (T^2);
% utt * vtt * A / T^2
opQ = opQ + kron(Tb.d2d2, Xb.d0d0) * A / (T^2);
% -BETA * Tstar * ut * vtt
opQ = opQ - kron(Tb.d1d2, Xb.d0d0) * BETA * Tstar;
% c^2 * BETA * Tstar * ut * Lap v
opQ = opQ + kron(Tb.d1d0, Xb.d0d2) * c^2 * BETA * Tstar;

%% (Variable) Local operator over Q
% - XI * x * grad u * vtt
opQx    = - kron(Tb.d0d2, Xb.d1d0x) * XI;
opQxVar = - kron(Tb.d0d2, Xb.d1d0) * XI;
% c^2 * XI * x * grad u * Lap v
opQx    = opQx + kron(Tb.d0d0, Xb.d1d2x) * c^2 * XI;
opQxVar = opQxVar + kron(Tb.d0d0, Xb.d1d2) * c^2 * XI;
% BETA * t * ut * vtt
opQt    = kron(Tb.d1d2x, Xb.d0d0) * BETA;
opQtVar = kron(Tb.d1d2, Xb.d0d0) * BETA;
% - BETA * c^2 * t * ut * Lap v
opQt    = opQt - kron(Tb.d1d0x, Xb.d0d2) * BETA * c^2;
opQtVar = opQtVar - kron(Tb.d1d0, Xb.d0d2) * BETA * c^2;


%% (Fixed) Local operator over Omega_T
% BETA (Tstar - T ) * vt * ut
opO = kron(ET.d1d1, Xb.d0d0) * BETA * (Tstar - T);
% BETA (Tstar - T ) * grad u * grad v
opO = opO + kron(ET.d0d0, Xb.d1d1) * BETA * (Tstar - T) * c^2;

%% (Variable) Local operator over Omega_T
% XI * x * grad v * ut
opOx    = kron(ET.d1d0, Xb.d0d1x) * XI;
opOxVar = kron(ET.d1d0, Xb.d0d1) * XI;
% XI * x * grad u * vt 
opOx    = opOx + kron(ET.d0d1, Xb.d1d0x) * XI;
opOxVar = opOxVar + kron(ET.d0d1, Xb.d1d0) * XI;

%% (Fixed) Local operator over Omega_0
opZ     = kron(E0.d0d0, Xb.d0d0) * A0 * T^(-1);
opZx    = zeros(size(opZ));
opZxVar = zeros(size(opZ));

%% (Fixed) Local operator over Sigma=a
n = -1; x = a;
% - c^2 * BETA * Tstar * ut * vx * n
opSa = - kron(Tb.d1d0, Ea.d0d1) * c^2 * BETA * Tstar * n;
% c/theta * XI * a * vx * ut
opSa = opSa + kron(Tb.d1d0, Ea.d0d1) * c / theta * x * XI;
% c/theta * BETA * Tstar * ut * vt
opSa = opSa + kron(Tb.d1d1, Ea.d0d0) * c / theta * BETA * Tstar;
% - XI * a * n * ut * vt 
opSa = opSa - kron(Tb.d1d1, Ea.d0d0) * XI * x * n;

%% (Variable) Local operator over Sigma=a
% c^2 * BETA * t * ut * vx * n
opSat = kron(Tb.d1d0x, Ea.d0d1) * c^2 * BETA * n;
opSatVar = kron(Tb.d1d0, Ea.d0d1) * c^2 * BETA * n;
% - c/theta * BETA * t * ut * vt
opSat = opSat - kron(Tb.d1d1x, Ea.d0d0) * c / theta * BETA;
opSatVar = opSatVar - kron(Tb.d1d1, Ea.d0d0) * c / theta * BETA;

%% (Fixed) Local operator over Sigma=b
n = 1; x = b;
% - c^2 * BETA * Tstar * ut * vx * n
opSb = - kron(Tb.d1d0, Eb.d0d1) * c^2 * BETA * Tstar * n;
% c/theta * XI * x * vx * ut
opSb = opSb + kron(Tb.d1d0, Eb.d0d1) * c / theta * x * XI;
% c/theta * BETA * Tstar * ut * vt
opSb = opSb + kron(Tb.d1d1, Eb.d0d0) * c / theta * BETA * Tstar;
% - XI * x * n * ut * vt 
opSb = opSb - kron(Tb.d1d1, Eb.d0d0) * XI * x * n;

%% (Variable) Local operator over Sigma=b
% c^2 * BETA * t * ut * vx * n
opSbt = kron(Tb.d1d0x, Eb.d0d1) * c^2 * BETA * n;
opSbtVar = kron(Tb.d1d0, Eb.d0d1) * c^2 * BETA * n;
% - c/theta * BETA * t * ut * vt
opSbt = opSbt - kron(Tb.d1d1x, Eb.d0d0) * c / theta * BETA;
opSbtVar = opSbtVar - kron(Tb.d1d1, Eb.d0d0) * c / theta * BETA;

%% Pack-up local matrix for assembly
% Q domain
KlocQ = struct();
KlocQ.op        = opQ;
KlocQ.opx       = opQx;
KlocQ.opt       = opQt;
KlocQ.opxVar    = opQxVar;
KlocQ.optVar    = opQtVar;

% OmegaT domain
KlocT           = struct();
KlocT.op        = opO;
KlocT.opx       = opOx;
KlocT.opxVar    = opOxVar;

% Omega0 domain
KlocZ           = struct();
KlocZ.op        = opZ;
KlocZ.opx       = opZx;
KlocZ.opxVar    = opZxVar;

% Sigma=a domain
KlocSa          = struct();
KlocSa.op       = opSa;
KlocSa.opx      = opSat;
KlocSa.opxVar   = opSatVar;

% Sigma=b domain
KlocSb          = struct();
KlocSb.op       = opSb;
KlocSb.opx      = opSbt;
KlocSb.opxVar   = opSbtVar;

%% Internal matrix assembly
KQ = assemble(KlocQ, mesh, disc);

%% Boundary matrix assembly
% Omega T boundary
KT = assemble_boundary(KlocT, mesh, disc, top_elms, x_var); 

% Omega 0 boundary
K0 = assemble_boundary(KlocZ, mesh, disc, bot_elms, x_var);

% Sigma=a boundary
Ka = assemble_boundary(KlocSa, mesh, disc, left_elms, t_var);

% Sigma=b boundary
Kb = assemble_boundary(KlocSb, mesh, disc, right_elms, t_var);

%% Global matrix computation
K = KQ + KT + K0 + Ka + Kb;

%% Load vector assembly
F = compute_rhs(problem, mesh, disc, form);

%% Solving
u = K \ F;

varargout{1} = u;
if nargout == 2
    varargout{2} = condest(K);
end

end
