/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * HermiteEvaluation.c
 *
 * Code generation for function 'HermiteEvaluation'
 *
 */

/* Include files */
#include "HermiteEvaluation.h"
#include "main_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
void HermiteEvaluation(real_T h, real_T E_d0d0[16], real_T E_d0d1[16],
                       real_T E_d1d0[16], real_T E_d1d1[16])
{
  static const int8_T b[16] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  static const int8_T b_b[16] = {0, 0, 0, 0, 0, 0, 0, 0,
                                 1, 0, 0, 0, 0, 0, 0, 0};
  static const int8_T c_b[16] = {0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 1, 0, 0, 0, 0, 0};
  real_T a_tmp;
  int32_T i;
  covrtLogFcn(&emlrtCoverageInstance, 7U, 0U);
  /*  Check if is an evaluation at the start or the end of the interval */
  covrtLogIf(&emlrtCoverageInstance, 7U, 0U, 0, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 7U, 0U);
  /*  If at start of interval: */
  /*  v_eval dof is at 1 */
  /*  dv_eval dof is at 3 */
  covrtLogBasicBlock(&emlrtCoverageInstance, 7U, 2U);
  covrtLogFcn(&emlrtCoverageInstance, 7U, 1U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 7U, 3U);
  memset(&E_d0d0[0], 0, 16U * sizeof(real_T));
  E_d0d0[0] = 1.0;
  a_tmp = 1.0 / h;
  for (i = 0; i < 16; i++) {
    E_d0d1[i] = a_tmp * (real_T)b[i];
  }
  for (i = 0; i < 16; i++) {
    E_d1d0[i] = a_tmp * (real_T)b_b[i];
  }
  a_tmp = muDoubleScalarPower(h, -2.0);
  for (i = 0; i < 16; i++) {
    E_d1d1[i] = a_tmp * (real_T)c_b[i];
  }
}

void b_HermiteEvaluation(real_T h, real_T E_d0d0[16], real_T E_d0d1[16],
                         real_T E_d1d0[16], real_T E_d1d1[16])
{
  static const int8_T b[16] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
  static const int8_T b_b[16] = {0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 1, 0, 0};
  static const int8_T c_b[16] = {0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 1};
  real_T a_tmp;
  int32_T i;
  covrtLogFcn(&emlrtCoverageInstance, 7U, 0U);
  /*  Check if is an evaluation at the start or the end of the interval */
  covrtLogIf(&emlrtCoverageInstance, 7U, 0U, 0, false);
  covrtLogIf(&emlrtCoverageInstance, 7U, 0U, 1, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 7U, 1U);
  /*  If at end of interval */
  /*  v_eval dof is at 2 */
  /*  dv_eval dof is at 4 */
  covrtLogBasicBlock(&emlrtCoverageInstance, 7U, 2U);
  covrtLogFcn(&emlrtCoverageInstance, 7U, 1U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 7U, 3U);
  memset(&E_d0d0[0], 0, 16U * sizeof(real_T));
  E_d0d0[5] = 1.0;
  a_tmp = 1.0 / h;
  for (i = 0; i < 16; i++) {
    E_d0d1[i] = a_tmp * (real_T)b[i];
  }
  for (i = 0; i < 16; i++) {
    E_d1d0[i] = a_tmp * (real_T)b_b[i];
  }
  a_tmp = muDoubleScalarPower(h, -2.0);
  for (i = 0; i < 16; i++) {
    E_d1d1[i] = a_tmp * (real_T)c_b[i];
  }
}

/* End of code generation (HermiteEvaluation.c) */
