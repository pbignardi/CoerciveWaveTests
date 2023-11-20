function B = HermiteBasis(h)
% HermiteBasis: compute 1D local matrices for hermite element
%
% INPUT:
%   h: (float) local element size
% OUTPUT:
%   B: (struct) local matrices of the hermite element

    B = struct();
    %% Fixed terms
    B.d0d0 = stiffness(0,0,0) * h;
    B.d1d1 = stiffness(1,1,0) / h;
    B.d2d2 = stiffness(2,2,0) / (h^3);
    B.d1d2 = stiffness(1,2,0) / (h^2);
    B.d0d1 = stiffness(0,1,0);
    B.d0d2 = stiffness(0,2,0) / h;
    
    % Swap test and trial functions
    B.d2d1 = stiffness(2,1,0) / (h^2);
    B.d1d0 = stiffness(1,0,0);
    B.d2d0 = stiffness(2,0,0) / h;
    
    %% Variable terms
    B.d1d1x = stiffness(1,1,1);
    B.d0d1x = stiffness(0,1,1) * h;
    B.d1d2x = stiffness(1,2,1) / h;
    B.d2d0x = stiffness(2,0,1);
    
    % Swap test and trial functions
    B.d1d0x = stiffness(1,0,1) * h;
    B.d0d2x = stiffness(0,2,1);
    B.d2d1x = stiffness(2,1,1) / h; 
end
