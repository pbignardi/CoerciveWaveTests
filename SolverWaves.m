function u = SolverWaves(problem, domain, mesh, disc, varargin)
    testing = 0;
    %% Unpacking parameters
    % Problem unpacking
    f       = problem.f;
    g       = problem.g;
    u0      = problem.u0;
    u1      = problem.u1;
    c       = problem.c;
    theta   = problem.theta;

    % Domain unpacking
    T       = domain.T;
    a       = domain.xmin;
    b       = domain.xmax;
    delta   = domain.delta;
    L       = domain.L;

    % Elements unpacking
    nx = disc.nx;
    nt = disc.nt;
    hx = disc.hx;
    ht = disc.ht;
    
    % Boundary unpacking
    top     = mesh.top;
    bot     = mesh.bot;
    left    = mesh.left;
    right   = mesh.right;

    % Boundary elms unpacking
    top_elms    = mesh.top_elms;
    bot_elms    = mesh.bot_elms;
    right_elms  = mesh.right_elms;
    left_elms   = mesh.left_elms;
    
    % Formulation unpacking
    if isempty(varargin)
        A       = 1;
        nu      = 2;
        xi      = 1;
        beta    = xi / (nu - 1) * min([L/(c*T) + 1, ...
                L/(c*T) * (delta * theta + (delta * theta)^(-1))]);
    elseif length(varargin) == 1
        form = varargin{1};
        A   = form.A;
        nu  = form.nu;
        xi  = form.xi;
        beta = form.beta;
    end
    Tstar   = nu*T;

    % - Controllare ordini laplaciano -> OK
    % - provare a perturbare la matrice con termini (modificare anche
    % termine noto)

    % Pack formulation parameters
    parameters = struct();
    parameters.A = A;
    parameters.beta = beta;
    parameters.Tstar = Tstar;
    parameters.nu = nu;
    parameters.xi = xi;
    parameters.c = c;
    parameters.T = T;
    
    % Other parameters
    n_nodes = (nx + 1) * (nt + 1);
    ndofs = 4*n_nodes;
    dofs = 1:ndofs;
    d = 1;
    
    %% Local operator structs
    Xb = HermiteBasis(hx);
    Tb = HermiteBasis(ht);

    %% Local evaluation structs
    Ea = HermiteEvaluation(hx, 0);
    Eb = HermiteEvaluation(hx, 1);
    ET = HermiteEvaluation(ht, 1);
    
    %% (Fixed) Local operator over Q
    % gradu * gradv * c^2 * (beta - xi)
    opQ = kron(Tb.d0d0, Xb.d1d1) * c^2 * (beta + (2 - d) * xi);
    % ut * vt * (beta + xi)
    opQ = opQ + kron(Tb.d1d1, Xb.d0d0) * (beta + d * xi);
    % Lap u * Lap v
    opQ = opQ + kron(Tb.d0d0, Xb.d2d2) * c^4 * A / (T^2);
    % - Lap u * vtt
    opQ = opQ - kron(Tb.d0d2, Xb.d2d0) * c^2 * A / (T^2);
    % - utt * Lap v * c^2 * A / T^2
    opQ = opQ - kron(Tb.d2d0, Xb.d0d2) * c^2 * A / (T^2);
    % utt * vtt * A / T^2
    opQ = opQ + kron(Tb.d2d2, Xb.d0d0) * A / (T^2);
    % -beta * Tstar * ut * vtt
    opQ = opQ - kron(Tb.d1d2, Xb.d0d0) * beta * Tstar;
    % c^2 * beta * Tstar * ut * Lap v
    opQ = opQ + kron(Tb.d1d0, Xb.d0d2) * c^2 * beta * Tstar;

    %% (Variable) Local operator over Q
    % - xi * x * grad u * vtt
    opQx    = - kron(Tb.d0d2, Xb.d1d0x) * xi;
    opQxVar = - kron(Tb.d0d2, Xb.d1d0) * xi;
    % c^2 * xi * x * grad u * Lap v
    opQx    = opQx + kron(Tb.d0d0, Xb.d1d2x) * c^2 * xi;
    opQxVar = opQxVar + kron(Tb.d0d0, Xb.d1d2) * c^2 * xi;
    % beta * t * ut * vtt
    opQt    = kron(Tb.d1d2x, Xb.d0d0) * beta;
    opQtVar = kron(Tb.d1d2, Xb.d0d0) * beta;
    % - beta * c^2 * t * ut * Lap v
    opQt    = opQt - kron(Tb.d1d0x, Xb.d0d2) * beta * c^2;
    opQtVar = opQtVar - kron(Tb.d1d0, Xb.d0d2) * beta * c^2;

    
    %% (Fixed) Local operator over Omega_T
    % beta (Tstar - T ) * vt * ut
    opO = kron(ET.d1d1, Xb.d0d0) * beta * (Tstar - T);
    % beta (Tstar - T ) * grad u * grad v
    opO = opO + kron(ET.d0d0, Xb.d1d1) * beta * (Tstar - T) * c^2;

    %% (Variable) Local operator over Omega_T
    % xi * x * grad v * ut
    opOx    = kron(ET.d1d0, Xb.d0d1x) * xi;
    opOxVar = kron(ET.d1d0, Xb.d0d1) * xi;
    % xi * x * grad u * vt 
    opOx    = opOx + kron(ET.d0d1, Xb.d1d0x) * xi;
    opOxVar = opOxVar + kron(ET.d0d1, Xb.d1d0) * xi;
    
    %% (Fixed) Local operator over Sigma=a
    n = -1; x = a;
    % - c^2 * beta * Tstar * ut * vx * n
    opSa = - kron(Tb.d1d0, Ea.d0d1) * c^2 * beta * Tstar * n;
    % c/theta * xi * a * vx * ut
    opSa = opSa + kron(Tb.d1d0, Ea.d0d1) * c / theta * x * xi;
    % c/theta * beta * Tstar * ut * vt
    opSa = opSa + kron(Tb.d1d1, Ea.d0d0) * c / theta * beta * Tstar;
    % - xi * a * n * ut * vt 
    opSa = opSa - kron(Tb.d1d1, Ea.d0d0) * xi * x * n;

    %% (Variable) Local operator over Sigma=a
    % c^2 * beta * t * ut * vx * n
    opSat = kron(Tb.d1d0x, Ea.d0d1) * c^2 * beta * n;
    opSatVar = kron(Tb.d1d0, Ea.d0d1) * c^2 * beta * n;
    % - c/theta * beta * t * ut * vt
    opSat = opSat - kron(Tb.d1d1x, Ea.d0d0) * c / theta * beta;
    opSatVar = opSatVar - kron(Tb.d1d1, Ea.d0d0) * c / theta * beta;

    %% (Fixed) Local operator over Sigma=b
    n = 1; x = b;
    % - c^2 * beta * Tstar * ut * vx * n
    opSb = - kron(Tb.d1d0, Eb.d0d1) * c^2 * beta * Tstar * n;
    % c/theta * xi * x * vx * ut
    opSb = opSb + kron(Tb.d1d0, Eb.d0d1) * c / theta * x * xi;
    % c/theta * beta * Tstar * ut * vt
    opSb = opSb + kron(Tb.d1d1, Eb.d0d0) * c / theta * beta * Tstar;
    % - xi * x * n * ut * vt 
    opSb = opSb - kron(Tb.d1d1, Eb.d0d0) * xi * x * n;

    %% (Variable) Local operator over Sigma=b
    % c^2 * beta * t * ut * vx * n
    opSbt = kron(Tb.d1d0x, Eb.d0d1) * c^2 * beta * n;
    opSbtVar = kron(Tb.d1d0, Eb.d0d1) * c^2 * beta * n;
    % - c/theta * beta * t * ut * vt
    opSbt = opSbt - kron(Tb.d1d1x, Eb.d0d0) * c / theta * beta;
    opSbtVar = opSbtVar - kron(Tb.d1d1, Eb.d0d0) * c / theta * beta;
    % --- Formulation above is correct ---

    %% Internal matrix assembly
    % Poisson testing
    KQ = assemble(opQ, mesh, disc);
    
    % Wave equation
    KQ = assemble(opQ, mesh, disc) + ...
        assemble(opQx, mesh, disc, opQxVar, 1) + ...
        assemble(opQt, mesh, disc, opQtVar, 2);

    %% Boundary matrix assembly
    % Omega T boundary
    KT = assemble_boundary(opO, mesh, disc, top_elms) + ...
        assemble_boundary(opOx, mesh, disc, top_elms, opOxVar, 1);
    
    % Sigma=a boundary
    Ka = assemble_boundary(opSa, mesh, disc, left_elms) + ...
        assemble_boundary(opSat, mesh, disc, left_elms, opSatVar, 2);

    % Sigma=b boundary
    Kb = assemble_boundary(opSb, mesh, disc, right_elms) + ...
        assemble_boundary(opSbt, mesh, disc, right_elms, opSbtVar, 2);

    %% Global matrix computation
    if testing 
        K = assemble(kron(Tb.d1d1, Xb.d0d0) + kron(Tb.d0d0, Xb.d1d1), ...
            mesh,disc);
    else
        K = KQ;
        K = K + KT;
        K = K + Ka + Kb; 
    end
    %% Load vector assembly
    if testing
        F = compute_rhs_poisson(f, mesh, disc);
    else
        F = compute_rhs(problem, mesh, disc, parameters);
    end
    
    %% Imposing boundary conditions
    initial_dofs = unique([bot n_nodes+bot 2*n_nodes+bot 3*n_nodes+bot]);
    
    left_dofs       = unique([left+n_nodes left+2*n_nodes]);
    right_dofs      = unique([right+n_nodes right+2*n_nodes]);
    dirichlet_dofs  = unique([bot top left right ...
        n_nodes+bot n_nodes+top 2*n_nodes+left 2*n_nodes+right]);
    
    %internal = setdiff(dofs, unique([initial_dofs, left_dofs, right_dofs]));
    if testing
        internal = setdiff(dofs, dirichlet_dofs);
    else
        internal = setdiff(dofs, initial_dofs);
    end
    %internal = setdiff(internal,left_dofs);
    %internal = setdiff(internal, right_dofs);
    
    %% Solving
    u = zeros(ndofs, 1);
    u(internal) = K(internal, internal) \ F(internal);
    %u(internal) = gmres(K(internal, internal), F(internal), 15, 1e-6, 200);
    

    %% Internal stiffness conditioning
    %fprintf("Condition number is: %e \n", condest(K(internal, internal)))
end
