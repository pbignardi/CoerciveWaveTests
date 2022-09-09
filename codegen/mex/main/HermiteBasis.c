/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * HermiteBasis.c
 *
 * Code generation for function 'HermiteBasis'
 *
 */

/* Include files */
#include "HermiteBasis.h"
#include "main_data.h"
#include "main_internal_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
void HermiteBasis(real_T varargin_1, d_struct_T *B)
{
  static const real_T a[16] = {
      0.37142857142857144,   0.12857142857142856,   0.052380952380952382,
      -0.030952380952380953, 0.12857142857142856,   0.37142857142857144,
      0.030952380952380953,  -0.052380952380952382, 0.052380952380952382,
      0.030952380952380953,  0.0095238095238095247, -0.0071428571428571426,
      -0.030952380952380953, -0.052380952380952382, -0.0071428571428571426,
      0.0095238095238095247};
  static const real_T b_a[16] = {
      -0.18571428571428572,  0.18571428571428572,    -0.0095238095238095247,
      -0.026190476190476191, -0.31428571428571428,   0.31428571428571428,
      -0.073809523809523811, 0.10952380952380952,    -0.042857142857142858,
      0.042857142857142858,  -0.0047619047619047623, -0.0047619047619047623,
      0.057142857142857141,  -0.057142857142857141,  0.011904761904761904,
      -0.0047619047619047623};
  static const real_T b_dv[16] = {1.2,
                                  -1.2,
                                  0.1,
                                  0.1,
                                  -1.2,
                                  1.2,
                                  -0.1,
                                  -0.1,
                                  0.1,
                                  -0.1,
                                  0.13333333333333333,
                                  -0.033333333333333333,
                                  0.1,
                                  -0.1,
                                  -0.033333333333333333,
                                  0.13333333333333333};
  static const real_T b_dv1[16] = {0.0,  0.0, 1.0,  -1.0, 0.0, 0.0,  -1.0, 1.0,
                                   -1.0, 1.0, -0.5, -0.5, 1.0, -1.0, 0.5,  0.5};
  static const real_T b_dv2[16] = {-0.5, 0.5,  0.1,
                                   -0.1, -0.5, 0.5,
                                   -0.1, 0.1,  -0.1,
                                   0.1,  0.0,  -0.016666666666666666,
                                   0.1,  -0.1, 0.016666666666666666,
                                   0.0};
  static const real_T b_dv3[16] = {-1.2,
                                   1.2,
                                   -1.1,
                                   -0.1,
                                   1.2,
                                   -1.2,
                                   0.1,
                                   1.1,
                                   -0.1,
                                   0.1,
                                   -0.13333333333333333,
                                   0.033333333333333333,
                                   -0.1,
                                   0.1,
                                   0.033333333333333333,
                                   -0.13333333333333333};
  static const real_T b_dv4[16] = {0.0, 0.0,  -1.0, 1.0, 0.0,  0.0, 1.0,  -1.0,
                                   1.0, -1.0, -0.5, 0.5, -1.0, 1.0, -0.5, 0.5};
  static const real_T c_a[16] = {
      -0.18571428571428572,  -0.31428571428571428,   -0.042857142857142858,
      0.057142857142857141,  0.18571428571428572,    0.31428571428571428,
      0.042857142857142858,  -0.057142857142857141,  -0.0095238095238095247,
      -0.073809523809523811, -0.0047619047619047623, 0.011904761904761904,
      -0.026190476190476191, 0.10952380952380952,    -0.0047619047619047623,
      -0.0047619047619047623};
  static const real_T dv10[16] = {-0.1,
                                  0.1,
                                  -0.2,
                                  0.1,
                                  1.1,
                                  -1.1,
                                  0.2,
                                  0.9,
                                  0.0,
                                  0.0,
                                  -0.033333333333333333,
                                  0.033333333333333333,
                                  -0.1,
                                  0.1,
                                  0.0,
                                  -0.1};
  static const real_T dv11[16] = {-0.6,
                                  0.6,
                                  -0.3,
                                  0.7,
                                  0.6,
                                  -0.6,
                                  0.3,
                                  -0.7,
                                  0.2,
                                  -0.2,
                                  -0.066666666666666666,
                                  0.26666666666666666,
                                  -0.8,
                                  0.8,
                                  -0.23333333333333334,
                                  0.43333333333333335};
  static const real_T dv5[16] = {-0.5, -0.5, -0.1,
                                 0.1,  0.5,  0.5,
                                 0.1,  -0.1, 0.1,
                                 -0.1, 0.0,  0.016666666666666666,
                                 -0.1, 0.1,  -0.016666666666666666,
                                 0.0};
  static const real_T dv6[16] = {-1.2,
                                 1.2,
                                 -0.1,
                                 -0.1,
                                 1.2,
                                 -1.2,
                                 0.1,
                                 0.1,
                                 -1.1,
                                 0.1,
                                 -0.13333333333333333,
                                 0.033333333333333333,
                                 -0.1,
                                 1.1,
                                 0.033333333333333333,
                                 -0.13333333333333333};
  static const real_T dv7[16] = {0.6,
                                 -0.6,
                                 0.1,
                                 0.0,
                                 -0.6,
                                 0.6,
                                 -0.1,
                                 0.0,
                                 0.1,
                                 -0.1,
                                 0.033333333333333333,
                                 -0.016666666666666666,
                                 0.0,
                                 0.0,
                                 -0.016666666666666666,
                                 0.1};
  static const real_T dv8[16] = {-0.6,
                                 0.6,
                                 0.2,
                                 -0.8,
                                 0.6,
                                 -0.6,
                                 -0.2,
                                 0.8,
                                 -0.3,
                                 0.3,
                                 -0.066666666666666666,
                                 -0.23333333333333334,
                                 0.7,
                                 -0.7,
                                 0.26666666666666666,
                                 0.43333333333333335};
  static const real_T dv9[16] = {-0.1,
                                 1.1,
                                 0.0,
                                 -0.1,
                                 0.1,
                                 -1.1,
                                 0.0,
                                 0.1,
                                 -0.2,
                                 0.2,
                                 -0.033333333333333333,
                                 0.0,
                                 0.1,
                                 0.9,
                                 0.033333333333333333,
                                 -0.1};
  static const int8_T b_iv[16] = {12, -12, 6, 6, -12, 12, -6, -6,
                                  6,  -6,  4, 2, 6,   -6, 2,  4};
  real_T c;
  int32_T i;
  covrtLogFcn(&emlrtCoverageInstance, 5U, 0U);
  covrtLogCond(&emlrtCoverageInstance, 5U, 0U, 0, false);
  covrtLogMcdc(&emlrtCoverageInstance, 5U, 0U, 0, true);
  covrtLogIf(&emlrtCoverageInstance, 5U, 0U, 0, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 2U);
  /*     %% Fixed terms */
  covrtLogFcn(&emlrtCoverageInstance, 6U, 0U);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 0, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 1, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 2, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 0U);
  /*  K_00 */
  for (i = 0; i < 16; i++) {
    B->d0d0[i] = a[i] * varargin_1;
  }
  covrtLogFcn(&emlrtCoverageInstance, 6U, 0U);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 0, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 1, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 5, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 6, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 7, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 4U);
  /*  K_11 */
  for (i = 0; i < 16; i++) {
    B->d1d1[i] = b_dv[i] / varargin_1;
  }
  covrtLogFcn(&emlrtCoverageInstance, 6U, 0U);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 0, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 1, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 5, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 9, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 10, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 11, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 12, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 8U);
  /*  K_22 */
  c = muDoubleScalarPower(varargin_1, 3.0);
  for (i = 0; i < 16; i++) {
    B->d2d2[i] = (real_T)b_iv[i] / c;
  }
  covrtLogFcn(&emlrtCoverageInstance, 6U, 0U);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 0, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 1, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 5, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 6, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 7, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 8, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 5U);
  /*  K_12 */
  c = varargin_1 * varargin_1;
  for (i = 0; i < 16; i++) {
    B->d1d2[i] = b_dv1[i] / c;
  }
  covrtLogFcn(&emlrtCoverageInstance, 6U, 0U);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 0, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 1, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 2, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 3, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 1U);
  /*  K_01 */
  memcpy(&B->d0d1[0], &b_dv2[0], 16U * sizeof(real_T));
  covrtLogFcn(&emlrtCoverageInstance, 6U, 0U);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 0, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 1, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 2, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 3, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 4, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 2U);
  /*  K_02 */
  for (i = 0; i < 16; i++) {
    B->d0d2[i] = b_dv3[i] / varargin_1;
  }
  /*  Swap test and trial functions */
  covrtLogFcn(&emlrtCoverageInstance, 6U, 0U);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 0, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 1, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 5, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 9, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 10, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 11, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 7U);
  /*  K_21 */
  for (i = 0; i < 16; i++) {
    B->d2d1[i] = b_dv4[i] / c;
  }
  covrtLogFcn(&emlrtCoverageInstance, 6U, 0U);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 0, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 1, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 5, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 6, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 3U);
  /*  K_10 */
  memcpy(&B->d1d0[0], &dv5[0], 16U * sizeof(real_T));
  covrtLogFcn(&emlrtCoverageInstance, 6U, 0U);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 0, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 1, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 5, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 9, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 10, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 6U);
  /*  K_20 */
  for (i = 0; i < 16; i++) {
    B->d2d0[i] = dv6[i] / varargin_1;
  }
  /*     %% Variable terms */
  covrtLogFcn(&emlrtCoverageInstance, 6U, 0U);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 0, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 13, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 14, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 18, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 19, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 20, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 13U);
  /*  K_11x */
  memcpy(&B->d1d1x[0], &dv7[0], 16U * sizeof(real_T));
  covrtLogFcn(&emlrtCoverageInstance, 6U, 0U);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 0, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 13, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 14, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 15, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 16, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 10U);
  /*  K_01x */
  for (i = 0; i < 16; i++) {
    B->d0d1x[i] = b_a[i] * varargin_1;
  }
  covrtLogFcn(&emlrtCoverageInstance, 6U, 0U);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 0, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 13, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 14, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 18, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 19, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 20, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 21, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 14U);
  /*  K_12x */
  for (i = 0; i < 16; i++) {
    B->d1d2x[i] = dv8[i] / varargin_1;
  }
  covrtLogFcn(&emlrtCoverageInstance, 6U, 0U);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 0, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 13, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 14, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 18, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 22, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 23, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 15U);
  /*  K_20x */
  memcpy(&B->d2d0x[0], &dv9[0], 16U * sizeof(real_T));
  /*  Swap test and trial functions */
  covrtLogFcn(&emlrtCoverageInstance, 6U, 0U);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 0, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 13, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 14, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 18, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 19, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 12U);
  /*  K_10x */
  for (i = 0; i < 16; i++) {
    B->d1d0x[i] = c_a[i] * varargin_1;
  }
  covrtLogFcn(&emlrtCoverageInstance, 6U, 0U);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 0, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 13, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 14, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 15, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 16, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 17, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 11U);
  /*  K_02x */
  memcpy(&B->d0d2x[0], &dv10[0], 16U * sizeof(real_T));
  covrtLogFcn(&emlrtCoverageInstance, 6U, 0U);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 0, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 13, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 14, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 18, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 22, true);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 23, false);
  covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 24, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 16U);
  /*  K_21x */
  for (i = 0; i < 16; i++) {
    B->d2d1x[i] = dv11[i] / varargin_1;
  }
}

/* End of code generation (HermiteBasis.c) */
