/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "power.h"
#include "main_data.h"
#include "main_emxutil.h"
#include "main_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo yg_emlrtRTEI =
    {
        71,      /* lineNo */
        5,       /* colNo */
        "power", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\power.m" /* pName
                                                                          */
};

/* Function Definitions */
void power(const emlrtStack *sp, const emxArray_real_T *a, emxArray_real_T *y)
{
  emlrtStack st;
  const real_T *a_data;
  real_T varargin_1;
  real_T *y_data;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  a_data = a->data;
  st.site = &nc_emlrtRSI;
  i = y->size[0];
  y->size[0] = a->size[0];
  emxEnsureCapacity_real_T(&st, y, i, &yg_emlrtRTEI);
  y_data = y->data;
  loop_ub = a->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargin_1 = a_data[i];
    y_data[i] = varargin_1 * varargin_1;
  }
}

/* End of code generation (power.c) */
