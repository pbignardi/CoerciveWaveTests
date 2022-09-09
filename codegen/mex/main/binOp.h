/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * binOp.h
 *
 * Code generation for function 'binOp'
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
void allocEqsizeBinop(const emlrtStack *sp, const emxArray_int32_T *a_colidx,
                      int32_T a_m, int32_T a_n,
                      const emxArray_int32_T *b_colidx, int32_T b_m,
                      int32_T b_n, int32_T sn, int32_T sm, emxArray_real_T *s_d,
                      emxArray_int32_T *s_colidx, emxArray_int32_T *s_rowidx,
                      int32_T *s_m, int32_T *s_n, int32_T *s_maxnz);

void b_sparseSparseRowExpandBinOp(const emlrtStack *sp,
                                  const emxArray_real_T *rowA_d,
                                  const emxArray_int32_T *rowA_colidx,
                                  const emxArray_real_T *b_d,
                                  const emxArray_int32_T *b_colidx,
                                  const emxArray_int32_T *b_rowidx,
                                  b_sparse *s);

void c_sparseSparseRowExpandBinOp(const emlrtStack *sp,
                                  const emxArray_real_T *rowA_d,
                                  const emxArray_int32_T *rowA_colidx,
                                  const emxArray_real_T *b_d,
                                  const emxArray_int32_T *b_colidx,
                                  const emxArray_int32_T *b_rowidx,
                                  b_sparse *s);

void sparseSparseEqHeightBinOp(const emlrtStack *sp, const emxArray_real_T *a_d,
                               const emxArray_int32_T *a_colidx,
                               const emxArray_int32_T *a_rowidx,
                               const emxArray_real_T *b_d,
                               const emxArray_int32_T *b_colidx,
                               const emxArray_int32_T *b_rowidx, b_sparse *s);

void sparseSparseRowExpandBinOp(const emlrtStack *sp,
                                const emxArray_real_T *rowA_d,
                                const emxArray_int32_T *rowA_colidx,
                                const emxArray_real_T *b_d,
                                const emxArray_int32_T *b_colidx,
                                const emxArray_int32_T *b_rowidx, b_sparse *s,
                                boolean_T expandB);

/* End of code generation (binOp.h) */
