/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main_internal_types.h
 *
 * Code generation for function 'main'
 *
 */

#pragma once

/* Include files */
#include "main_types.h"
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_b_struct_T
#define typedef_b_struct_T
typedef struct {
  real_T A;
  real_T beta;
  real_T Tstar;
  real_T nu;
  real_T xi;
  real_T c;
  real_T T;
  real_T a;
  real_T b;
} b_struct_T;
#endif /* typedef_b_struct_T */

#ifndef typedef_c_struct_T
#define typedef_c_struct_T
typedef struct {
  real_T L2N;
  real_T H1N;
  real_T OPN;
  real_T GRN;
  real_T SUPN;
  real_T L2E;
  real_T H1E;
  real_T OPE;
  real_T GRE;
  real_T SUPE;
} c_struct_T;
#endif /* typedef_c_struct_T */

#ifndef typedef_d_struct_T
#define typedef_d_struct_T
typedef struct {
  real_T d0d0[16];
  real_T d1d1[16];
  real_T d2d2[16];
  real_T d1d2[16];
  real_T d0d1[16];
  real_T d0d2[16];
  real_T d2d1[16];
  real_T d1d0[16];
  real_T d2d0[16];
  real_T d1d1x[16];
  real_T d0d1x[16];
  real_T d1d2x[16];
  real_T d2d0x[16];
  real_T d1d0x[16];
  real_T d0d2x[16];
  real_T d2d1x[16];
} d_struct_T;
#endif /* typedef_d_struct_T */

#ifndef typedef_rtDesignRangeCheckInfo
#define typedef_rtDesignRangeCheckInfo
typedef struct {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
} rtDesignRangeCheckInfo;
#endif /* typedef_rtDesignRangeCheckInfo */

#ifndef typedef_rtRunTimeErrorInfo
#define typedef_rtRunTimeErrorInfo
typedef struct {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
} rtRunTimeErrorInfo;
#endif /* typedef_rtRunTimeErrorInfo */

/* End of code generation (main_internal_types.h) */
