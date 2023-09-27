% problem parameters
xmin = -1; xmax = 1;
ymin = -1; ymax = 1;
T = 1; d = 2;
c = 1;
theta = 1;
% domain parameters
L = sqrt((xmax - xmin)^2 + (ymax - ymin)^2);
delta = 0.5; %HARD CODED
% discretisation parameters
% number of elements
nx = 10;
ny = 10;
nt = 5;
Q = CartesianCubeMesh()
disc = Discretisation3D(nx, ny, nt, Q);
% direction mesh size
hx = (xmax - xmin) / nx;
hy = (ymax - ymin) / ny;
ht = T / nt;
% formulation parameters
A = 1;
A0 = 1;
BETA = 20;
NU = 2;
XI = 1;
Tstar = NU * T;

%% Mesh construction
% NEED TO COMPUTE THE MESH

%% Local operators
Xb = HermiteBasis(hx);
Yb = HermiteBasis(hy);
Tb = HermiteBasis(ht);

% boundary evaluation basis
Exmin = HermiteEvaluation(hx, 0);
Exmax = HermiteEvaluation(hx, 1);
Eymin = HermiteEvaluation(hy, 0);
Eymax = HermiteEvaluation(hy, 1);
Etmin = HermiteEvaluation(ht, 0);
Etmax = HermiteEvaluation(ht, 1);

% space_stiffness matrix
XYb = struct();
XYb.d0d0 = kron(Yb.d0d0, Xb.d0d0);
XYb.d1d1 = kron(Yb.d1d1, Xb.d0d0) + kron(Yb.d0d0, Xb.d1d1);
XYb.d2d2 = kron(Yb.d2d2, Xb.d0d0) + kron(Yb.d0d0, Xb.d2d2);
XYb.d0d2 = kron(Yb.d0d2, Xb.d0d0) + kron(Yb.d0d0, Xb.d0d2);
XYb.d2d0 = kron(Yb.d2d0, Xb.d0d0) + kron(Yb.d0d0, Xb.d2d0);

XYb.d1d2x = kron(Yb.d0d0, Xb.d1d2x) + kron(Yb.d0d2, Xb.d1d0x);
XYb.d1d2y = kron(Yb.d1d0x, Xb.d0d2) + kron(Yb.d1d2x, Xb.d0d0);
XYb.d1d2varx = kron(Yb.d0d0, Xb.d1d2) + kron(Yb.d0d2, Xb.d1d0);
XYb.d1d2vary = kron(Yb.d1d0, Xb.d0d2) + kron(Yb.d1d2, Xb.d0d0);

XYb.d1d0x = kron(Yb.d0d0, Xb.d1d0x);
XYb.d0d1x = kron(Yb.d0d0, Xb.d0d1x);
XYb.d1d0y = kron(Yb.d1d0x, Xb.d0d0);
XYb.d0d1y = kron(Yb.d0d1x, Xb.d0d0);
XYb.d1d0varx = kron(Yb.d0d0, Xb.d1d0);
XYb.d0d1varx = kron(Yb.d0d0, Xb.d0d1);
XYb.d1d0vary = kron(Yb.d1d0, Xb.d0d0);
XYb.d0d1vary = kron(Yb.d0d1, Xb.d0d0);

%% (FIXED) Local operator over Q
opQ = kron(Tb.d0d0, XYb.d1d1) * c^2 * (BETA + (2 - d) * XI);
opQ = opQ + kron(Tb.d1d1, XYb.d0d0) * (BETA + d * XI);
opQ = opQ + kron(Tb.d0d0, XYb.d2d2) * c^4 * A / (T^2);
opQ = opQ - kron(Tb.d0d2, XYb.d2d0) * c^2 * A / (T^2);
opQ = opQ - kron(Tb.d2d0, XYb.d0d2) * c^2 * A / (T^2);
opQ = opQ + kron(Tb.d2d2, XYb.d0d0) * c^4 * A / (T^2);

opQ = opQ - kron(Tb.d1d2, XYb.d0d0) * BETA * Tstar;
opQ = opQ + kron(Tb.d1d0, XYb.d0d2) * c^2 * BETA * Tstar;


%% (VARIABLE) Local operator over Q
% - XI * x * grad u * vtt
opQx = - kron(Tb.d0d2, XYb.d1d0x) * XI;
opQy = - kron(Tb.d0d2, XYb.d1d0y) * XI;
opQxVar = - kron(Tb.d0d2, XYb.d1d0varx) * XI;
opQyVar = - kron(Tb.d0d2, XYb.d1d0vary) * XI;

% c^2 * XI * x * grad u * Lap v
opQx    = opQx + kron(Tb.d0d0, XYb.d1d2x) * c^2 * XI;
opQy    = opQy + kron(Tb.d0d0, XYb.d1d2y) * c^2 * XI;
opQxVar = opQxVar + kron(Tb.d0d0, XYb.d1d2varx) * c^2 * XI;
opQyVar = opQyVar + kron(Tb.d0d0, XYb.d1d2vary) * c^2 * XI;

% BETA * t * ut * vtt
opQt    = kron(Tb.d1d2x, XYb.d0d0) * BETA;
opQtVar = kron(Tb.d1d2, XYb.d0d0) * BETA;
% - BETA * c^2 * t * ut * lap v
opQt    = opQt - kron(Tb.d1d0x, XYb.d0d2) * BETA * c^2;
opQtVar = opQtVar - kron(Tb.d1d0, XYb.d0d2) * BETA * c^2;

%% (FIXED) Local operator over Omega_T
% BETA (Tstar - T) * vt * ut
opO = kron(Etmax.d1d1, XYb.d0d0) * BETA * (Tstar - T);
% BETA (Tstar - T) * gradu * gradv
opO = opO + kron(Etmax.d0d0, XYb.d1d1) * BETA * (Tstar - T) * c^2;

%% (VARIABLE) Local operator over Omega_T
% XI * x * gradv * ut
opOx = kron(Etmax.d1d0, XYb.d0d1x) * XI;
opOy = kron(Etmax.d1d0, XYb.d0d1y) * XI;
opOxVar = kron(Etmax.d1d0, XYb.d0d1varx) * XI;
opOyVar = kron(Etmax.d1d0, XYb.d0d1vary) * XI;
% XI * x * gradu * vt
opOx = opOx + kron(Etmax.d0d1, XYb.d1d0x) * XI;
opOy = opOy + kron(Etmax.d0d1, XYb.d1d0y) * XI;
opOxVar = opOxVar + kron(Etmax.d0d1, XYb.d1d0varx) * XI;
opOyVar = opOyVar + kron(Etmax.d0d1, XYb.d1d0vary) * XI;


%% (FIXED) Local operator over Omega_0
opZ = kron(Etmin.d0d0, XYb.d0d0) * A0 * T^(-1);
opZx = zeros(size(opZ));
opZy = zeros(size(opZ));
opZxVar = zeros(size(opZ));
opZyVar = zeros(size(opZ));

%% (FIXED) Local operator over boundary (x = xmin)
XYbound = struct();
Xcomp = Xb;
Ycomp = Yb;
XYbound.d0d0 = kron(Ycomp.d0d0, Xcomp.d0d0);
XYbound.d1d0x = kron(Ycomp.d0d0, Xcomp.d1d0x);
XYbound.d1d0y = kron(Ycomp.d1d0x, Xcomp.d0d0);
XYbound.d1d1x = kron(Ycomp.d0d0, Xcomp.d1d1x);
n = -1; x = xmin;
% -c^2*XI*( x * grad u ) * dn v
opSx1 = - c^2 * XI * (x * kron(Tb.d0d0, kron(Yb.d0d1, Exmin.d1d0))) * n;
% - BETA * Tstar * dtu * dnu 
opSx1 = opSx1 - n * c^2 * BETA * NU * tmax * kron(Tb.d1d0, kron(Yb.d0d1, Exmin.d0d0));
% -c/theta * XI * xmin * 
opSx1 = opSx1 - c / theta * XI * x * kron(Tb.d1d0, kron(Yb.d0d0, Exmin.d0d1));
% - c / theta Tstar dtu dtv
opSx1 = opSx1 - tmax * NU * c / theta * kron(Tb.d1d1, kron(Yb.d0d0, Exmin.d0d0));

%% (VARIABLE) Local operator over boundary (x = xmin)
opSx1y = - n * c^2 * XI * kron(Tb.d0d0, kron(Yb.d1d1x, Exmin.d0d0));
opSx1y = opSx1y - c / theta * XI * kron(Tb.d1d0, kron(Yb.d1d0x, Exmin.d0d0));
opSx1y = opSx1y + c^2 * XI * kron(Tb.d0d0, kron(Yb.d1d1x, Xb.d0d0));
opSx1t = c^2 * BETA * n * kron(Tb.d1d0x, kron(Yb.d0d1, Exmin.d0d0));
opSx1t = opSx1t + c / theta * BETA * kron(Tb.d1d1x, kron(Yb.d0d0, Exmin.d0d0));
opSx1vary = - n * c^2 * XI * kron(Tb.d0d0, kron(Yb.d1d1, Exmin.d0d0));
opSx1vary = opSx1vary - c / theta * XI * kron(Tb.d1d0, kron(Yb.d1d0, Exmin.d0d0));
opSx1vart = c^2 * BETA * n * kron(Tb.d1d0, kron(Yb.d0d1, Exmin.d0d0));
opSx1vart = opSx1vart + c / theta * BETA * kron(Tb.d1d1, kron(Yb.d0d0, Exmin.d0d0));


%% Pack-up local matrix
KlocQ = struct();
KlocQ.op    = opQ;
KlocQ.opx   = opQx;
KlocQ.opy   = opQy;
KlocQ.opt   = opQt;
KlocQ.opxVar = opQxVar;
KlocQ.opyVar = opQyVar;

KQ = assemble2D(KlocQ, mesh, disc);

















