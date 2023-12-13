# Wave equation XT formulation tests
Numerical tests for the manuscript "Space-time continuous and coercive
formulation for the wave equation" - P. Bignardi, A. Moiola.

For context, refer to the preprint [here](https://arxiv.org/abs/2312.07268){:target="_blank"}

## Project structure
The top level folder contains scripts that produces plots and data used in the 
manuscript.
In the `src` there are functions that perform the main computations (computing
numerical solutions, errors, energy, etc). Docstrings are provided with each 
one of such functions. The scripts provided generate plots, and the data is used to generate figures in the manuscript.
- `ConvergenceTestRunner`: test CFL condition and h-convergence.
- `EnergyTestRunner`: compute energy of numerical solution. Also test the convergence of the energy of the error $u-u_{ h }$ and of the error of the energy $E(u_{h})-E(u)$.
- `TestA`: compute the $L^2$, $H^1$ error for $A_{ Q }$ and $A_{\Omega_0}$ varying in their set. 
- `TestMultiplierPars`: compute the $L^2$ error varying the coefficients of the multiplier.
- `TestRun`: solve single problem.
