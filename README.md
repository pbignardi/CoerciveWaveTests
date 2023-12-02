# Wave equation XT formulation tests
Numerical tests for the manuscript "Space-time continuous and coercive
formulation for the wave equation" - P. Bignardi, A. Moiola.

For context, refer to the preprint [here](link-to-somewhere).

## Project structure
The top level folder contains scripts that produces plots and data used in the 
manuscript.
In the `src` there are functions that perform the main computations (computing
numerical solutions, errors, energy, etc). Docstrings are provided with each 
one of such functions.

## TODO
- Plotting function for the CFL condition test
- Reorganize the test A and test beta xi scripts
- Run all the test of the paper to see if everything works
