/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_main_api.c
 *
 * Code generation for function '_coder_main_api'
 *
 */

/* Include files */
#include "_coder_main_api.h"
#include "main.h"
#include "main_data.h"
#include "main_mexutil.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void main_api(const mxArray *const prhs[5], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T T;
  real_T c;
  real_T nt;
  real_T nx;
  real_T theta;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  c = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "c");
  theta = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "theta");
  T = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "T");
  nx = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "nx");
  nt = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "nt");
  /* Invoke the target function */
  c = main(&st, c, theta, T, nx, nt);
  /* Marshall function outputs */
  *plhs = d_emlrt_marshallOut(c);
}

/* End of code generation (_coder_main_api.c) */
