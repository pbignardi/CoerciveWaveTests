% Paolo Bignardi - Dec 2023
function [psi, dpsi, ddpsi] = BasisEvaluation(xq)
% BasisEvaluation: evaluate Hermite 1D basis functions and its derivatives
%
% INPUT:
%   xq: (float[]) evaluation points in the reference element
%
% OUTPUT:
%   psi: (float[]) evaluation of hermite 1d basis functions
%   dpsi: (float[]) evaluation of hermite 1d basis functions 1st derivative
%   ddpsi: (float[]) evaluation of hermite 1d basis functions 2nd derivative

    %% Psi evaluation
    psiB = (-2*xq.^3+3*xq.^2);
    psiA = 2*xq.^3-3*xq.^2+1;
    psiD = xq.^3-xq.^2;
    psiC = xq.^3-2*xq.^2+xq;
    psi = [psiA, psiB, psiC, psiD];
    %% Derivative evaluation
    dpsiB = -6*xq.^2+6*xq;
    dpsiA = 6*xq.^2-6*xq;
    dpsiD = 3*xq.^2-2*xq;
    dpsiC = 3*xq.^2-4*xq+1;
    dpsi = [dpsiA, dpsiB, dpsiC, dpsiD];
    %% Second derivative evaluation
    ddpsiB = -12*xq+6;
    ddpsiA = 12*xq-6;
    ddpsiD = 6*xq-2;
    ddpsiC = 6*xq-4;
    ddpsi = [ddpsiA, ddpsiB, ddpsiC, ddpsiD];
end
