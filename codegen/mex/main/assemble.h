/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * assemble.h
 *
 * Code generation for function 'assemble'
 *
 */

#pragma once

/* Include files */
#include "main_types.h"
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void assemble(const emlrtStack *sp, const real_T Kloc_struct_op[256],
              const real_T Kloc_struct_opx[256],
              const real_T Kloc_struct_opt[256],
              const real_T Kloc_struct_opxVar[256],
              const real_T Kloc_struct_optVar[256],
              const emxArray_real_T *mesh_pivots,
              const emxArray_real_T *mesh_elms, real_T disc_nx, real_T disc_nt,
              const emxArray_real_T *disc_xx, const emxArray_real_T *disc_tt,
              b_sparse *K);

/* End of code generation (assemble.h) */
