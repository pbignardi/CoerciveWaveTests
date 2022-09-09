/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_mtimes_helper.h
 *
 * Code generation for function 'eml_mtimes_helper'
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
void f_binary_expand_op(const emlrtStack *sp, emxArray_real_T *Uxx_ex, real_T c,
                        const emxArray_real_T *r1, int32_T nx);

void p_binary_expand_op(const emlrtStack *sp, emxArray_real_T *r1, real_T phi,
                        const emxArray_real_T *varargin_1);

void r_binary_expand_op(const emlrtStack *sp, emxArray_real_T *varargout_1,
                        real_T a, const emxArray_real_T *r1);

/* End of code generation (eml_mtimes_helper.h) */
