/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * kron.h
 *
 * Code generation for function 'kron'
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
void b_kron(const real_T A[16], const real_T B[16], real_T K[256]);

void c_kron(const emlrtStack *sp, const emxArray_real_T *A,
            const emxArray_real_T *B, emxArray_real_T *K);

void d_kron(const emlrtStack *sp, const emxArray_real_T *A,
            const emxArray_real_T *B, emxArray_real_T *K);

void e_kron(const real_T A[8], const real_T B[8], real_T K[64]);

void f_kron(const real_T A[32], const real_T B[32], real_T K[1024]);

void g_kron(const real_T A[4], const real_T B[32], real_T K[128]);

void h_kron(const real_T A[32], const real_T B[4], real_T K[128]);

void i_kron(const emlrtStack *sp, const real_T A[64], const emxArray_real_T *B,
            emxArray_real_T *K);

void kron(const emlrtStack *sp, const emxArray_real_T *A,
          const emxArray_real_T *B, emxArray_real_T *K);

/* End of code generation (kron.h) */
