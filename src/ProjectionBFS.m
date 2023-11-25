function [L2proj, H1proj, Vproj] = ProjectionBFS(p, disc, varargin)
% Compute orthogonal projection of function on BFS space
%% Values unpacking
% domain
T = p.Q.T;
a = p.Q.xmin;
b = p.Q.xmax;
L = p.Q.L;
% discretisation
nx = disc.nx;
nt = disc.nt;
hx = disc.hx;
ht = disc.ht;
xx = kron(ones(1, (nt + 1)), disc.x);
tt = kron(disc.t, ones((nx + 1), 1));
ndofs = 4 * (nx + 1) * (nt + 1);
n_elms = nx * nt;
% problem parameters
c = p.c;
%% Create mesh
mesh = CartesianMesh(disc);
pivots = mesh.pivots;

% unpack boundary elements
top_elms    = mesh.top_elms;
right_elms  = mesh.right_elms;
left_elms   = mesh.left_elms;
bot_elms    = mesh.bot_elms;

%% Local operator structs
Xb = HermiteBasis(hx);
Tb = HermiteBasis(ht);

%% Local evaluation structs
Ea = HermiteEvaluation(hx, 0);
Eb = HermiteEvaluation(hx, 1);
ET = HermiteEvaluation(ht, 1);
E0 = HermiteEvaluation(ht, 0);

%% Compute L2 projection matrix
L2projLoc = struct();
L2projLoc.op    = kron(Tb.d0d0, Xb.d0d0);
L2projLoc.opx   = zeros(size(L2projLoc.op));
L2projLoc.opt   = zeros(size(L2projLoc.op));
L2projLoc.opxVar    = zeros(size(L2projLoc.op));
L2projLoc.optVar    = zeros(size(L2projLoc.op));

L2projMat = assemble(L2projLoc, mesh, disc);

%% Compute H1 semiproduct projection matrix (scaled with wavespeed c)
H1projLoc = struct();
H1projLoc.op    = kron(Tb.d1d1, Xb.d0d0) + c^2*kron(Tb.d0d0, Xb.d1d1);
H1projLoc.opx   = zeros(size(H1projLoc.op));
H1projLoc.opt   = zeros(size(H1projLoc.op));
H1projLoc.opxVar    = zeros(size(H1projLoc.op));
H1projLoc.optVar    = zeros(size(H1projLoc.op));

H1projMat = assemble(H1projLoc, mesh, disc) + L2projMat;
VprojMat = H1projMat;

%% Compute V norm projection matrix
% Wave operator norm
OPprojLoc = struct();
OPprojLoc.op = T^2 * (kron(Tb.d2d2, Xb.d0d0) + c^4 * kron(Tb.d0d0, Xb.d2d2) - ...
	c^2 * kron(Tb.d0d2, Xb.d2d0) - c^2 * kron(Tb.d2d0, Xb.d0d2));
OPprojLoc.opx   = zeros(size(OPprojLoc.op));
OPprojLoc.opt   = zeros(size(OPprojLoc.op));
OPprojLoc.opxVar    = zeros(size(OPprojLoc.op));
OPprojLoc.optVar    = zeros(size(OPprojLoc.op));

VprojMat = VprojMat + assemble(OPprojLoc, mesh, disc);

% H1 norm on \OT
H1OTprojLoc = struct();
H1OTprojLoc.op = T * (kron(ET.d1d1, Xb.d0d0) + c^2 * kron(ET.d0d0, Xb.d1d1));
H1OTprojLoc.opx   = zeros(size(H1OTprojLoc.op));
H1OTprojLoc.opt   = zeros(size(H1OTprojLoc.op));
H1OTprojLoc.opxVar    = zeros(size(H1OTprojLoc.op));
H1OTprojLoc.optVar    = zeros(size(H1OTprojLoc.op));

VprojMat = VprojMat + ...
    assemble_boundary(H1OTprojLoc, mesh, disc, top_elms, 1);

% H1 norm on \OZ
H1OZprojLoc = struct();
H1OZprojLoc.op = T * (kron(E0.d1d1, Xb.d0d0) + c^2 * kron(E0.d0d0, Xb.d1d1)) + ...
	T^(-1) * kron(E0.d0d0, Xb.d0d0);
H1OZprojLoc.opx   = zeros(size(H1OTprojLoc.op));
H1OZprojLoc.opt   = zeros(size(H1OTprojLoc.op));
H1OZprojLoc.opxVar    = zeros(size(H1OTprojLoc.op));
H1OZprojLoc.optVar    = zeros(size(H1OTprojLoc.op));

VprojMat = VprojMat + assemble_boundary(H1OZprojLoc, mesh, disc, bot_elms, 1);

% H1 norm on \SI=a
H1SIprojLoc = struct();
H1SIprojLoc.op = L * (kron(Tb.d1d1, Ea.d0d0) + c^2 * kron(Tb.d0d0, Ea.d1d1));
H1SIprojLoc.opx   = zeros(size(H1SIprojLoc.op));
H1SIprojLoc.opt   = zeros(size(H1SIprojLoc.op));
H1SIprojLoc.opxVar    = zeros(size(H1SIprojLoc.op));
H1SIprojLoc.optVar    = zeros(size(H1SIprojLoc.op));

VprojMat = VprojMat + assemble_boundary(H1SIprojLoc, mesh, disc, left_elms, 2);

% H1 norm on \SI=b
H1SIprojLoc = struct();
H1SIprojLoc.op = L * (kron(Tb.d1d1, Eb.d0d0) + c^2 * kron(Tb.d0d0, Eb.d1d1));
H1SIprojLoc.opx   = zeros(size(H1SIprojLoc.op));
H1SIprojLoc.opt   = zeros(size(H1SIprojLoc.op));
H1SIprojLoc.opxVar    = zeros(size(H1SIprojLoc.op));
H1SIprojLoc.optVar    = zeros(size(H1SIprojLoc.op));

VprojMat = VprojMat + assemble_boundary(H1SIprojLoc, mesh, disc, right_elms, 2);

%% Compute projection RHS
% Initialise RHS vectors
L2projRHS = zeros(ndofs, 1);
H1projRHS = zeros(ndofs, 1);
VprojRHS = zeros(ndofs, 1);

% Initialise local quadrature nodes and weights
nq = 8;
[xq, wq] = gaussquad(nq);
xqh = hx * xq;
tqh = ht * xq;
wqx = hx * wq;
wqt = ht * wq;
wqxt = kron(wqt, wqx);
xxqh = kron(ones(nq, 1), xqh);
ttqh = kron(tqh, ones(nq, 1));

[psi, dpsi, ddpsi] = BasisEvaluation(xq);

% Basis function evaluation over grid
psi_T   = psi;
dpsi_T  = ht^(-1) * dpsi; 
ddpsi_T = ht^(-2) * ddpsi;

psi_X   = psi;
dpsi_X  = hx^(-1) * dpsi;
ddpsi_X = hx^(-2) * ddpsi;

% Basis function evaluation at boundary
Estart_d0 = [1, 0, 0, 0];
Estart_d1 = [0, 0, 1, 0];
Eend_d0 = [0, 1, 0, 0];
Eend_d1 = [0, 0, 0, 1];

Ea_d0 = Estart_d0;
Ea_d1 = Estart_d1 * hx^(-1);
Eb_d0 = Eend_d0;
Eb_d1 = Eend_d1 * hx^(-1);
E0_d0 = Estart_d0;
E0_d1 = Estart_d1 * ht^(-1);
ET_d0 = Eend_d0;
ET_d1 = Eend_d1 * ht^(-1);

%% Operator evaluations
% Q local terms
v_Q	= kron(psi_T, psi_X);
gradv_Q = kron(psi_T, dpsi_X);
vt_Q    = kron(dpsi_T, psi_X);
W_Q   = kron(ddpsi_T, psi_X) - c^2 * kron(psi_T, ddpsi_X);

% Omega0 local terms
vt_0    = kron(E0_d1, psi_X);
vx_0    = kron(E0_d0, dpsi_X);
v_0     = kron(E0_d0, psi_X);

% OmegaT local terms
vt_T    = kron(ET_d1, psi_X);
vx_T    = kron(ET_d0, dpsi_X);

% Sigma=a local terms
vt_a    = kron(dpsi_T, Ea_d0);
vx_a    = kron(psi_T, Ea_d1);

% Sigma=b local terms
vt_b    = kron(dpsi_T, Eb_d0);
vx_b    = kron(psi_T, Eb_d1);

%% RHS assembly 
% Volume Q
for e = 1:n_elms
    el_ids = mesh.elms(e, :);
    dofs = mapper(el_ids, nx, nt);
    el_xq = xxqh + xx(mesh.pivots(e));
    el_tq = ttqh + tt(mesh.pivots(e));
    
    Uex 	= p.u(el_xq, el_tq);
    dx_Uex 	= p.dx_u(el_xq, el_tq);
    dt_Uex 	= p.dt_u(el_xq, el_tq);
    W_Uex 	= p.f(el_xq, el_tq);
    
    L2norm = Uex .* v_Q;
    H1seminorm = c^2 * dx_Uex .* gradv_Q + dt_Uex .* vt_Q;
    OPnorm = T^2 .* W_Uex .* W_Q;
    
    L2projRHS(dofs) = L2projRHS(dofs) + sum(L2norm .* wqxt).';
    H1projRHS(dofs) = H1projRHS(dofs) + sum((L2norm + H1seminorm).* wqxt).';
    VprojRHS(dofs) = VprojRHS(dofs) + sum((L2norm + H1seminorm + OPnorm) .* wqxt).';
end

% Boundary \OZ
for e = bot_elms
	el_ids = mesh.elms(e, :);
	dofs = mapper(el_ids, nx, nt);
	el_xq = xxqh(1:nq) + xx(pivots(e));
    % solution evaluation
    dt_Uex = p.dt_u(el_xq, 0);
    dx_Uex = p.dx_u(el_xq, 0);
    Uex = p.u(el_xq, 0);
    H1OZseminorm = (dt_Uex .* vt_0 + c^2 * dx_Uex .* vx_0) * T;
    L2norm = T^(-1) * Uex .* v_0;
    % rhs construction
    VprojRHS(dofs) = VprojRHS(dofs) + sum((L2norm + H1OZseminorm) .* wqx).';
end

% Boundary \OT
for e = top_elms
	el_ids = mesh.elms(e, :);
	dofs = mapper(el_ids, nx, nt);
	el_xq = xxqh(1:nq) + xx(pivots(e));
    % solution evaluation
    dt_Uex = p.dt_u(el_xq, T);
    dx_Uex = p.dx_u(el_xq, T);
    H1OZseminorm = (dt_Uex .* vt_T + c^2 * dx_Uex .* vx_T) * T;

    % rhs construction
    VprojRHS(dofs) = VprojRHS(dofs) + sum(H1OZseminorm .* wqx).';
end

% Boundary \SI=a
for e = left_elms
	el_ids = mesh.elms(e, :);
	dofs = mapper(el_ids, nx, nt);
	el_tq = ttqh(nq*(1:nq)) + tt(pivots(e));
    % solution evaluation
    dt_Uex = p.dt_u(a, el_tq);
    dx_Uex = p.dx_u(a, el_tq);
    H1SIseminorm = L * (dt_Uex .* vt_a + c^2 * dx_Uex .* vx_a);

    % rhs construction
    VprojRHS(dofs) = VprojRHS(dofs) + sum(H1SIseminorm .* wqt).';
end

% Boundary \SI=b
for e = right_elms
	el_ids = mesh.elms(e, :);
	dofs = mapper(el_ids, nx, nt);
	el_tq = ttqh(nq*(1:nq)) + tt(pivots(e));
    % solution evaluation
    dt_Uex = p.dt_u(b, el_tq);
    dx_Uex = p.dx_u(b, el_tq);
    H1SIseminorm = L * (dt_Uex .* vt_b + c^2 * dx_Uex .* vx_b);

    % rhs construction
    VprojRHS(dofs) = VprojRHS(dofs) + sum(H1SIseminorm .* wqt).';
end

%% Computing the projection
L2proj = L2projMat \ L2projRHS;
H1proj = H1projMat \ H1projRHS;
Vproj = VprojMat \ VprojRHS;

end
