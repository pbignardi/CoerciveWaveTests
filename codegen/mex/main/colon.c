/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * colon.c
 *
 * Code generation for function 'colon'
 *
 */

/* Include files */
#include "colon.h"
#include "main_data.h"
#include "main_emxutil.h"
#include "main_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo w_emlrtRSI =
    {
        311,               /* lineNo */
        "eml_float_colon", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" /* pathName
                                                                          */
};

static emlrtRTEInfo f_emlrtRTEI =
    {
        411,               /* lineNo */
        15,                /* colNo */
        "assert_pmaxsize", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" /* pName
                                                                          */
};

static emlrtRTEInfo fd_emlrtRTEI =
    {
        312,     /* lineNo */
        20,      /* colNo */
        "colon", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" /* pName
                                                                          */
};

/* Function Definitions */
void b_eml_float_colon(const emlrtStack *sp, real_T a, real_T d, real_T b,
                       emxArray_real_T *y)
{
  emlrtStack st;
  real_T apnd;
  real_T cdiff;
  real_T ndbl;
  real_T *y_data;
  int32_T k;
  int32_T n;
  int32_T nm1d2;
  st.prev = sp;
  st.tls = sp->tls;
  ndbl = muDoubleScalarFloor((b - a) / d + 0.5);
  apnd = a + ndbl * d;
  if (d > 0.0) {
    cdiff = apnd - b;
  } else {
    cdiff = b - apnd;
  }
  if (muDoubleScalarAbs(cdiff) <
      4.4408920985006262E-16 *
          muDoubleScalarMax(muDoubleScalarAbs(a), muDoubleScalarAbs(b))) {
    ndbl++;
    apnd = b;
  } else if (cdiff > 0.0) {
    apnd = a + (ndbl - 1.0) * d;
  } else {
    ndbl++;
  }
  if (ndbl >= 0.0) {
    n = (int32_T)ndbl;
  } else {
    n = 0;
  }
  st.site = &w_emlrtRSI;
  if (ndbl > 2.147483647E+9) {
    emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
  nm1d2 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity_real_T(sp, y, nm1d2, &fd_emlrtRTEI);
  y_data = y->data;
  if (n > 0) {
    y_data[0] = a;
    if (n > 1) {
      y_data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (k = 0; k <= nm1d2 - 2; k++) {
        ndbl = ((real_T)k + 1.0) * d;
        y_data[k + 1] = a + ndbl;
        y_data[(n - k) - 2] = apnd - ndbl;
      }
      if (nm1d2 << 1 == n - 1) {
        y_data[nm1d2] = (a + apnd) / 2.0;
      } else {
        ndbl = (real_T)nm1d2 * d;
        y_data[nm1d2] = a + ndbl;
        y_data[nm1d2 + 1] = apnd - ndbl;
      }
    }
  }
}

void c_eml_float_colon(const emlrtStack *sp, real_T a, real_T b,
                       emxArray_real_T *y)
{
  emlrtStack st;
  real_T apnd;
  real_T cdiff;
  real_T ndbl;
  real_T *y_data;
  int32_T k;
  int32_T n;
  int32_T nm1d2;
  st.prev = sp;
  st.tls = sp->tls;
  ndbl = muDoubleScalarFloor((b - a) + 0.5);
  apnd = a + ndbl;
  cdiff = apnd - b;
  if (muDoubleScalarAbs(cdiff) <
      4.4408920985006262E-16 *
          muDoubleScalarMax(muDoubleScalarAbs(a), muDoubleScalarAbs(b))) {
    ndbl++;
    apnd = b;
  } else if (cdiff > 0.0) {
    apnd = a + (ndbl - 1.0);
  } else {
    ndbl++;
  }
  if (ndbl >= 0.0) {
    n = (int32_T)ndbl;
  } else {
    n = 0;
  }
  st.site = &w_emlrtRSI;
  if (ndbl > 2.147483647E+9) {
    emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
  nm1d2 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity_real_T(sp, y, nm1d2, &fd_emlrtRTEI);
  y_data = y->data;
  if (n > 0) {
    y_data[0] = a;
    if (n > 1) {
      y_data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (k = 0; k <= nm1d2 - 2; k++) {
        y_data[k + 1] = a + ((real_T)k + 1.0);
        y_data[(n - k) - 2] = apnd - ((real_T)k + 1.0);
      }
      if (nm1d2 << 1 == n - 1) {
        y_data[nm1d2] = (a + apnd) / 2.0;
      } else {
        y_data[nm1d2] = a + (real_T)nm1d2;
        y_data[nm1d2 + 1] = apnd - (real_T)nm1d2;
      }
    }
  }
}

void eml_float_colon(const emlrtStack *sp, real_T d, real_T b,
                     emxArray_real_T *y)
{
  emlrtStack st;
  real_T apnd;
  real_T cdiff;
  real_T ndbl;
  real_T *y_data;
  int32_T k;
  int32_T n;
  int32_T nm1d2;
  st.prev = sp;
  st.tls = sp->tls;
  ndbl = muDoubleScalarFloor((b - 1.0) / d + 0.5);
  apnd = ndbl * d + 1.0;
  if (d > 0.0) {
    cdiff = apnd - b;
  } else {
    cdiff = b - apnd;
  }
  if (muDoubleScalarAbs(cdiff) <
      4.4408920985006262E-16 * muDoubleScalarMax(1.0, muDoubleScalarAbs(b))) {
    ndbl++;
    apnd = b;
  } else if (cdiff > 0.0) {
    apnd = (ndbl - 1.0) * d + 1.0;
  } else {
    ndbl++;
  }
  if (ndbl >= 0.0) {
    n = (int32_T)ndbl;
  } else {
    n = 0;
  }
  st.site = &w_emlrtRSI;
  if (ndbl > 2.147483647E+9) {
    emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
  nm1d2 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity_real_T(sp, y, nm1d2, &fd_emlrtRTEI);
  y_data = y->data;
  if (n > 0) {
    y_data[0] = 1.0;
    if (n > 1) {
      y_data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (k = 0; k <= nm1d2 - 2; k++) {
        ndbl = ((real_T)k + 1.0) * d;
        y_data[k + 1] = ndbl + 1.0;
        y_data[(n - k) - 2] = apnd - ndbl;
      }
      if (nm1d2 << 1 == n - 1) {
        y_data[nm1d2] = (apnd + 1.0) / 2.0;
      } else {
        ndbl = (real_T)nm1d2 * d;
        y_data[nm1d2] = ndbl + 1.0;
        y_data[nm1d2 + 1] = apnd - ndbl;
      }
    }
  }
}

/* End of code generation (colon.c) */
