/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * function_handle.c
 *
 * Code generation for function 'function_handle'
 *
 */

/* Include files */
#include "function_handle.h"
#include "main.h"
#include "main_data.h"
#include "main_emxutil.h"
#include "main_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void j_binary_expand_op(const emlrtStack *sp, emxArray_real_T *varargout_1,
                        emlrtRSInfo ln_emlrtRSI, const emxArray_real_T *x)
{
  emlrtStack st;
  emxArray_real_T *r;
  const real_T *x_data;
  real_T *r1;
  real_T *varargout_1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  st.prev = sp;
  st.tls = sp->tls;
  x_data = x->data;
  varargout_1_data = varargout_1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &r, 1, &ug_emlrtRTEI);
  i = r->size[0];
  if (varargout_1->size[0] == 1) {
    r->size[0] = x->size[0];
  } else {
    r->size[0] = varargout_1->size[0];
  }
  emxEnsureCapacity_real_T(sp, r, i, &ug_emlrtRTEI);
  r1 = r->data;
  stride_0_0 = (x->size[0] != 1);
  stride_1_0 = (varargout_1->size[0] != 1);
  if (varargout_1->size[0] == 1) {
    loop_ub = x->size[0];
  } else {
    loop_ub = varargout_1->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    r1[i] = (2.0 - x_data[i * stride_0_0]) - varargout_1_data[i * stride_1_0];
  }
  st.site = &ln_emlrtRSI;
  main_anonFcn4(&st, r, varargout_1);
  emxFree_real_T(sp, &r);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void k_binary_expand_op(const emlrtStack *sp, emxArray_real_T *varargout_1,
                        emlrtRSInfo ln_emlrtRSI, const emxArray_real_T *x,
                        const emxArray_real_T *b_varargout_1)
{
  emlrtStack st;
  emxArray_real_T *b_x;
  const real_T *varargout_1_data;
  const real_T *x_data;
  real_T *b_x_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  st.prev = sp;
  st.tls = sp->tls;
  varargout_1_data = b_varargout_1->data;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_x, 1, &tg_emlrtRTEI);
  i = b_x->size[0];
  if (b_varargout_1->size[0] == 1) {
    b_x->size[0] = x->size[0];
  } else {
    b_x->size[0] = b_varargout_1->size[0];
  }
  emxEnsureCapacity_real_T(sp, b_x, i, &tg_emlrtRTEI);
  b_x_data = b_x->data;
  stride_0_0 = (x->size[0] != 1);
  stride_1_0 = (b_varargout_1->size[0] != 1);
  if (b_varargout_1->size[0] == 1) {
    loop_ub = x->size[0];
  } else {
    loop_ub = b_varargout_1->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    b_x_data[i] = x_data[i * stride_0_0] - varargout_1_data[i * stride_1_0];
  }
  st.site = &ln_emlrtRSI;
  main_anonFcn4(&st, b_x, varargout_1);
  emxFree_real_T(sp, &b_x);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void l_binary_expand_op(const emlrtStack *sp, emxArray_real_T *varargout_1,
                        emlrtRSInfo ln_emlrtRSI, const emxArray_real_T *x)
{
  emlrtStack st;
  emxArray_real_T *r;
  const real_T *x_data;
  real_T *r1;
  real_T *varargout_1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  st.prev = sp;
  st.tls = sp->tls;
  x_data = x->data;
  varargout_1_data = varargout_1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &r, 1, &ch_emlrtRTEI);
  i = r->size[0];
  if (varargout_1->size[0] == 1) {
    r->size[0] = x->size[0];
  } else {
    r->size[0] = varargout_1->size[0];
  }
  emxEnsureCapacity_real_T(sp, r, i, &ch_emlrtRTEI);
  r1 = r->data;
  stride_0_0 = (x->size[0] != 1);
  stride_1_0 = (varargout_1->size[0] != 1);
  if (varargout_1->size[0] == 1) {
    loop_ub = x->size[0];
  } else {
    loop_ub = varargout_1->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    r1[i] = (2.0 - x_data[i * stride_0_0]) - varargout_1_data[i * stride_1_0];
  }
  st.site = &ln_emlrtRSI;
  b_main_anonFcn5(&st, r, varargout_1);
  emxFree_real_T(sp, &r);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void m_binary_expand_op(const emlrtStack *sp, emxArray_real_T *varargout_1,
                        emlrtRSInfo ln_emlrtRSI, const emxArray_real_T *x,
                        const emxArray_real_T *b_varargout_1)
{
  emlrtStack st;
  emxArray_real_T *b_x;
  const real_T *varargout_1_data;
  const real_T *x_data;
  real_T *b_x_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  st.prev = sp;
  st.tls = sp->tls;
  varargout_1_data = b_varargout_1->data;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_x, 1, &bh_emlrtRTEI);
  i = b_x->size[0];
  if (b_varargout_1->size[0] == 1) {
    b_x->size[0] = x->size[0];
  } else {
    b_x->size[0] = b_varargout_1->size[0];
  }
  emxEnsureCapacity_real_T(sp, b_x, i, &bh_emlrtRTEI);
  b_x_data = b_x->data;
  stride_0_0 = (x->size[0] != 1);
  stride_1_0 = (b_varargout_1->size[0] != 1);
  if (b_varargout_1->size[0] == 1) {
    loop_ub = x->size[0];
  } else {
    loop_ub = b_varargout_1->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    b_x_data[i] = x_data[i * stride_0_0] - varargout_1_data[i * stride_1_0];
  }
  st.site = &ln_emlrtRSI;
  b_main_anonFcn5(&st, b_x, varargout_1);
  emxFree_real_T(sp, &b_x);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (function_handle.c) */
