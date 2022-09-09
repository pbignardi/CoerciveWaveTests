/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SolutionEval.h
 *
 * Code generation for function 'SolutionEval'
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
void SolutionEval(const emlrtStack *sp, const emxArray_real_T *u,
                  const emxArray_real_T *mesh_pivots,
                  const emxArray_real_T *mesh_elms, real_T disc_nx,
                  real_T disc_nt, real_T disc_hx, real_T disc_ht,
                  const emxArray_real_T *disc_xx,
                  const emxArray_real_T *disc_tt, emxArray_real_T *U,
                  emxArray_real_T *X, emxArray_real_T *T);

/* End of code generation (SolutionEval.h) */
