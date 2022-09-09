/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fillIn.c
 *
 * Code generation for function 'fillIn'
 *
 */

/* Include files */
#include "fillIn.h"
#include "eml_int_forloop_overflow_check.h"
#include "main_data.h"
#include "main_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo cf_emlrtRSI = {
    14,              /* lineNo */
    "sparse/fillIn", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\fillIn.m" /* pathName */
};

/* Function Definitions */
void sparse_fillIn(const emlrtStack *sp, b_sparse *this)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T val;
  int32_T b;
  int32_T c;
  int32_T currRowIdx;
  int32_T exitg1;
  int32_T i;
  int32_T idx;
  int32_T ridx;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  idx = 1;
  b = this->colidx->size[0];
  st.site = &cf_emlrtRSI;
  overflow = ((1 <= this->colidx->size[0] - 1) &&
              (this->colidx->size[0] - 1 > 2147483646));
  if (overflow) {
    b_st.site = &m_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (c = 0; c <= b - 2; c++) {
    ridx = this->colidx->data[c];
    this->colidx->data[c] = idx;
    do {
      exitg1 = 0;
      i = this->colidx->data[c + 1];
      if (ridx < i) {
        val = 0.0;
        currRowIdx = this->rowidx->data[ridx - 1];
        while ((ridx < i) && (this->rowidx->data[ridx - 1] == currRowIdx)) {
          val += this->d->data[ridx - 1];
          ridx++;
        }
        if (val != 0.0) {
          this->d->data[idx - 1] = val;
          this->rowidx->data[idx - 1] = currRowIdx;
          idx++;
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  this->colidx->data[this->colidx->size[0] - 1] = idx;
}

/* End of code generation (fillIn.c) */
