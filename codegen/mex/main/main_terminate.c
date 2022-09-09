/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main_terminate.c
 *
 * Code generation for function 'main_terminate'
 *
 */

/* Include files */
#include "main_terminate.h"
#include "_coder_main_mex.h"
#include "main_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void main_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void main_terminate(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (main_terminate.c) */
