/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * OperatorEval.h
 *
 * Code generation for function 'OperatorEval'
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
void OperatorEval(const emlrtStack *sp, const emxArray_real_T *u,
                  const emxArray_real_T *mesh_elms, real_T disc_nx,
                  real_T disc_nt, const real_T operator[1024],
                  emxArray_real_T * U);

/* End of code generation (OperatorEval.h) */
