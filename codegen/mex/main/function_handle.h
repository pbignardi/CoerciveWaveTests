/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * function_handle.h
 *
 * Code generation for function 'function_handle'
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
void j_binary_expand_op(const emlrtStack *sp, emxArray_real_T *varargout_1,
                        emlrtRSInfo ln_emlrtRSI, const emxArray_real_T *x);

void k_binary_expand_op(const emlrtStack *sp, emxArray_real_T *varargout_1,
                        emlrtRSInfo ln_emlrtRSI, const emxArray_real_T *x,
                        const emxArray_real_T *b_varargout_1);

void l_binary_expand_op(const emlrtStack *sp, emxArray_real_T *varargout_1,
                        emlrtRSInfo ln_emlrtRSI, const emxArray_real_T *x);

void m_binary_expand_op(const emlrtStack *sp, emxArray_real_T *varargout_1,
                        emlrtRSInfo ln_emlrtRSI, const emxArray_real_T *x,
                        const emxArray_real_T *b_varargout_1);

/* End of code generation (function_handle.h) */
