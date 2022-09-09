/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sumMatrixIncludeNaN.h
 *
 * Code generation for function 'sumMatrixIncludeNaN'
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
real_T b_sumColumnB(const real_T x[128], int32_T col);

real_T c_sumColumnB(const emlrtStack *sp, const emxArray_real_T *x,
                    int32_T vlen);

real_T d_sumColumnB(const emlrtStack *sp, const emxArray_real_T *x,
                    int32_T vlen, int32_T vstart);

real_T sumColumnB(const real_T x[1024], int32_T col);

real_T sumColumnB4(const emxArray_real_T *x, int32_T vstart);

/* End of code generation (sumMatrixIncludeNaN.h) */
