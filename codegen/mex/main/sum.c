/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "sum.h"
#include "main_data.h"
#include "main_types.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"

/* Variable Definitions */
static emlrtRSInfo fh_emlrtRSI = {
    20,    /* lineNo */
    "sum", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" /* pathName
                                                                        */
};

static emlrtRSInfo gh_emlrtRSI = {
    99,        /* lineNo */
    "sumprod", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumpro"
    "d.m" /* pathName */
};

static emlrtRSInfo hh_emlrtRSI = {
    74,                      /* lineNo */
    "combineVectorElements", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" /* pathName */
};

static emlrtRSInfo ih_emlrtRSI = {
    107,                /* lineNo */
    "blockedSummation", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" /* pathName */
};

static emlrtRSInfo jh_emlrtRSI = {
    22,                    /* lineNo */
    "sumMatrixIncludeNaN", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo kh_emlrtRSI = {
    42,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo om_emlrtRSI = {
    57,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" /* pathName */
};

/* Function Definitions */
void b_sum(const real_T x[128], real_T y[16])
{
  int32_T col;
  for (col = 0; col < 16; col++) {
    y[col] = b_sumColumnB(x, col + 1);
  }
}

real_T c_sum(const emlrtStack *sp, const emxArray_real_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T y;
  int32_T ib;
  int32_T inb;
  int32_T nfb;
  int32_T nleft;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fh_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  b_st.site = &gh_emlrtRSI;
  c_st.site = &hh_emlrtRSI;
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    d_st.site = &ih_emlrtRSI;
    e_st.site = &jh_emlrtRSI;
    if (x->size[0] < 4096) {
      f_st.site = &kh_emlrtRSI;
      y = c_sumColumnB(&f_st, x, x->size[0]);
    } else {
      nfb = x->size[0] / 4096;
      inb = nfb << 12;
      nleft = x->size[0] - inb;
      y = sumColumnB4(x, 1);
      for (ib = 2; ib <= nfb; ib++) {
        y += sumColumnB4(x, ((ib - 1) << 12) + 1);
      }
      if (nleft > 0) {
        f_st.site = &om_emlrtRSI;
        y += d_sumColumnB(&f_st, x, nleft, inb + 1);
      }
    }
  }
  return y;
}

void sum(const real_T x[1024], real_T y[16])
{
  int32_T col;
  for (col = 0; col < 16; col++) {
    y[col] = sumColumnB(x, col + 1);
  }
}

/* End of code generation (sum.c) */
