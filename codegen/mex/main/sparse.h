/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sparse.h
 *
 * Code generation for function 'sparse'
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
void sparse(const emlrtStack *sp, const emxArray_real_T *varargin_1,
            const emxArray_real_T *varargin_2,
            const emxArray_real_T *varargin_3, real_T varargin_4,
            real_T varargin_5, b_sparse *y);

/* End of code generation (sparse.h) */
