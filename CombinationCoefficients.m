function [j1, j2] = CombinationCoefficients(J, sigma, varargin)
%Compute the coefficients for 2d combination technique
%
% Arguments (optional arguments marked with (*)):
%   J           : (Int) Index of maximum regularity in each space direction
%   sigma       : (Float) Anisotropy paremeter
%   cols (*)    : (Bool) decide if taking space-sum by cols or rows
%
% Returns:
%   j1          : (Int[]) Vector of indices for first component
%   j2          : (Int[]) Vector of indices for second component

%   Reference: On the convergence of the combination technique - Griebel
%   and Harbrecht -- Link:
%   https://edoc.unibas.ch/32936/1/20140415001525_534c5dfdc9cfe.pdf
    jfree = 0:ceil(J*sigma);
    
    if isempty(varargin)
        cols = true;
    else
        cols = varargin{1};
    end

    if cols
        % Equation (17)
        j2 = jfree;
        j1 = ceil(J*sigma^(-1) - j2*sigma^(-2));
    else
        % Equation (16)
        j1 = jfree;
        j2 = ceil(J*sigma - j1*sigma^2);
    end
end