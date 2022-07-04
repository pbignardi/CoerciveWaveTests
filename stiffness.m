function S = stiffness(ord_u, ord_v, force)
    % Function to compute integrals of stiffness matrices
    %% Load existing matrix
    if force
        string_force = "x";
    else
        string_force = "";
    end
    f = strcat("K_", string(ord_u), string(ord_v), string_force, ".mat");
    if exist(f, "file") == 2
        %disp(strcat("Loading stiffness matrix from file ", f));
        load(f, "S");
        return
    end
    
    %% Defining basis functions
    syms x

    psiB = (-2*x.^3+3*x.^2);
    psiA = 2*x.^3-3*x.^2+1;
    psiD = x.^3-x.^2;
    psiC = x.^3-2*x.^2+x;
    psi = {psiA, psiB, psiC, psiD};

    % first derivatives (used only for CO)
    dpsiB = -6*x.^2+6*x;
    dpsiA = 6*x.^2-6*x;
    dpsiD = 3*x.^2-2*x;
    dpsiC = 3*x.^2-4*x+1; 
    dpsi = {dpsiA, dpsiB, dpsiC, dpsiD};

    % second derivatives (used only for LS and CO)
    ddpsiB = -12*x+6;
    ddpsiA = 12*x-6;
    ddpsiD = 6*x-2;
    ddpsiC = 6*x-4; 
    ddpsi = {ddpsiA, ddpsiB, ddpsiC, ddpsiD};
    
    switch ord_u
        case 0
            U = psi;
        case 1
            U = dpsi;
        case 2
            U = ddpsi;
    end
    switch ord_v
        case 0
            V = psi;
        case 1
            V = dpsi;
        case 2
            V = ddpsi;
    end
    %% Computing reference stiffness matrix
    S = zeros(4,4);

    for i = 1:4
        u = U{i};
        for j = 1:4
            v = V{j};
            if force == 0
                S(i,j) = int(u*v, [0,1]);
            else
                S(i,j) = int(x*u*v, [0,1]);
            end
        end
    end
    %% Save to file
    save(strcat("local_stiffness/", f), "S");
end