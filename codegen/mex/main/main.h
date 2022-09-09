/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main.h
 *
 * Code generation for function 'main'
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
void b_main_anonFcn5(const emlrtStack *sp, const emxArray_real_T *x,
                     emxArray_real_T *varargout_1);

real_T main(const emlrtStack *sp, real_T c, real_T theta, real_T T, real_T nx,
            real_T nt);

void main_anonFcn11(const emlrtStack *sp, real_T c, real_T phi,
                    const emxArray_real_T *x, const emxArray_real_T *t,
                    emxArray_real_T *varargout_1);

void main_anonFcn12(const emlrtStack *sp, real_T c, real_T phi,
                    const emxArray_real_T *x, const emxArray_real_T *t,
                    emxArray_real_T *varargout_1);

void main_anonFcn13(const emlrtStack *sp, real_T c, real_T phi,
                    const emxArray_real_T *x, const emxArray_real_T *t,
                    emxArray_real_T *varargout_1);

void main_anonFcn14(const emlrtStack *sp, real_T c, real_T phi,
                    const emxArray_real_T *x, const emxArray_real_T *t,
                    emxArray_real_T *varargout_1);

void main_anonFcn15(const emlrtStack *sp, real_T c, real_T phi,
                    const emxArray_real_T *x, const emxArray_real_T *t,
                    emxArray_real_T *varargout_1);

void main_anonFcn4(const emlrtStack *sp, const emxArray_real_T *x,
                   emxArray_real_T *varargout_1);

void main_anonFcn5(const real_T x[8], real_T varargout_1[8]);

/* End of code generation (main.h) */
