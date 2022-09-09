/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sparse1.h
 *
 * Code generation for function 'sparse1'
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
void assertValidIndexArg(const emlrtStack *sp, const emxArray_real_T *s,
                         emxArray_int32_T *sint);

void permuteVector(const emlrtStack *sp, const emxArray_int32_T *idx,
                   emxArray_int32_T *y);

void sparse_mldivide(const emlrtStack *sp, const emxArray_real_T *A_d,
                     const emxArray_int32_T *A_colidx,
                     const emxArray_int32_T *A_rowidx, int32_T A_m, int32_T A_n,
                     const emxArray_real_T *b, emxArray_real_T *y);

void sparse_parenAssign(const emlrtStack *sp, b_sparse *this,
                        const emxArray_real_T *rhs, real_T varargin_1,
                        const emxArray_real_T *varargin_2);

void sparse_plus(const emlrtStack *sp, const emxArray_real_T *a_d,
                 const emxArray_int32_T *a_colidx,
                 const emxArray_int32_T *a_rowidx, int32_T a_m, int32_T a_n,
                 const emxArray_real_T *b_d, const emxArray_int32_T *b_colidx,
                 const emxArray_int32_T *b_rowidx, int32_T b_m, int32_T b_n,
                 b_sparse *s);

/* End of code generation (sparse1.h) */
