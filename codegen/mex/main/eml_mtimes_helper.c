/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_mtimes_helper.c
 *
 * Code generation for function 'eml_mtimes_helper'
 *
 */

/* Include files */
#include "eml_mtimes_helper.h"
#include "main_data.h"
#include "main_emxutil.h"
#include "main_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void f_binary_expand_op(const emlrtStack *sp, emxArray_real_T *Uxx_ex, real_T c,
                        const emxArray_real_T *r1, int32_T nx)
{
  emxArray_real_T *b_c;
  const real_T *r;
  real_T *Uxx_ex_data;
  real_T *c_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  r = r1->data;
  Uxx_ex_data = Uxx_ex->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_c, 1, &fh_emlrtRTEI);
  i = b_c->size[0];
  if (nx == 1) {
    b_c->size[0] = Uxx_ex->size[0];
  } else {
    b_c->size[0] = nx;
  }
  emxEnsureCapacity_real_T(sp, b_c, i, &fh_emlrtRTEI);
  c_data = b_c->data;
  stride_0_0 = (Uxx_ex->size[0] != 1);
  stride_1_0 = (nx != 1);
  if (nx == 1) {
    loop_ub = Uxx_ex->size[0];
  } else {
    loop_ub = nx;
  }
  for (i = 0; i < loop_ub; i++) {
    c_data[i] = -c * (Uxx_ex_data[i * stride_0_0] - r[i * stride_1_0]);
  }
  i = Uxx_ex->size[0];
  Uxx_ex->size[0] = b_c->size[0];
  emxEnsureCapacity_real_T(sp, Uxx_ex, i, &fh_emlrtRTEI);
  Uxx_ex_data = Uxx_ex->data;
  loop_ub = b_c->size[0];
  for (i = 0; i < loop_ub; i++) {
    Uxx_ex_data[i] = c_data[i];
  }
  emxFree_real_T(sp, &b_c);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void p_binary_expand_op(const emlrtStack *sp, emxArray_real_T *r1, real_T phi,
                        const emxArray_real_T *varargin_1)
{
  emxArray_real_T *b_phi;
  const real_T *varargin_1_data;
  real_T *phi_data;
  real_T *r;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  varargin_1_data = varargin_1->data;
  r = r1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_phi, 1, &fh_emlrtRTEI);
  i = b_phi->size[0];
  if (varargin_1->size[0] == 1) {
    b_phi->size[0] = r1->size[0];
  } else {
    b_phi->size[0] = varargin_1->size[0];
  }
  emxEnsureCapacity_real_T(sp, b_phi, i, &fh_emlrtRTEI);
  phi_data = b_phi->data;
  stride_0_0 = (r1->size[0] != 1);
  stride_1_0 = (varargin_1->size[0] != 1);
  if (varargin_1->size[0] == 1) {
    loop_ub = r1->size[0];
  } else {
    loop_ub = varargin_1->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    phi_data[i] = phi * (r[i * stride_0_0] - varargin_1_data[i * stride_1_0]);
  }
  i = r1->size[0];
  r1->size[0] = b_phi->size[0];
  emxEnsureCapacity_real_T(sp, r1, i, &fh_emlrtRTEI);
  r = r1->data;
  loop_ub = b_phi->size[0];
  for (i = 0; i < loop_ub; i++) {
    r[i] = phi_data[i];
  }
  emxFree_real_T(sp, &b_phi);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void r_binary_expand_op(const emlrtStack *sp, emxArray_real_T *varargout_1,
                        real_T a, const emxArray_real_T *r1)
{
  emxArray_real_T *b_a;
  const real_T *r;
  real_T *a_data;
  real_T *varargout_1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  r = r1->data;
  varargout_1_data = varargout_1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_a, 1, &fh_emlrtRTEI);
  i = b_a->size[0];
  if (r1->size[0] == 1) {
    b_a->size[0] = varargout_1->size[0];
  } else {
    b_a->size[0] = r1->size[0];
  }
  emxEnsureCapacity_real_T(sp, b_a, i, &fh_emlrtRTEI);
  a_data = b_a->data;
  stride_0_0 = (varargout_1->size[0] != 1);
  stride_1_0 = (r1->size[0] != 1);
  if (r1->size[0] == 1) {
    loop_ub = varargout_1->size[0];
  } else {
    loop_ub = r1->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    a_data[i] = a * (varargout_1_data[i * stride_0_0] + r[i * stride_1_0]);
  }
  i = varargout_1->size[0];
  varargout_1->size[0] = b_a->size[0];
  emxEnsureCapacity_real_T(sp, varargout_1, i, &fh_emlrtRTEI);
  varargout_1_data = varargout_1->data;
  loop_ub = b_a->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargout_1_data[i] = a_data[i];
  }
  emxFree_real_T(sp, &b_a);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (eml_mtimes_helper.c) */
