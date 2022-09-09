/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sparse.c
 *
 * Code generation for function 'sparse'
 *
 */

/* Include files */
#include "sparse.h"
#include "assertValidSizeArg.h"
#include "eml_int_forloop_overflow_check.h"
#include "fillIn.h"
#include "introsort.h"
#include "main_data.h"
#include "main_emxutil.h"
#include "main_types.h"
#include "rt_nonfinite.h"
#include "sparse1.h"

/* Variable Definitions */
static emlrtRSInfo td_emlrtRSI = {
    13,       /* lineNo */
    "sparse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m" /* pathName
                                                                           */
};

static emlrtRSInfo ud_emlrtRSI = {
    119,             /* lineNo */
    "sparse/sparse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo vd_emlrtRSI = {
    120,             /* lineNo */
    "sparse/sparse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo wd_emlrtRSI = {
    126,             /* lineNo */
    "sparse/sparse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo xd_emlrtRSI = {
    138,             /* lineNo */
    "sparse/sparse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo be_emlrtRSI = {
    147,             /* lineNo */
    "sparse/sparse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo ce_emlrtRSI = {
    197,             /* lineNo */
    "sparse/sparse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo de_emlrtRSI = {
    209,             /* lineNo */
    "sparse/sparse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo ge_emlrtRSI = {
    1655,          /* lineNo */
    "locSortrows", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo he_emlrtRSI = {
    1657,          /* lineNo */
    "locSortrows", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo ie_emlrtRSI = {
    1658,          /* lineNo */
    "locSortrows", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo ue_emlrtRSI = {
    1610,              /* lineNo */
    "assertValidSize", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo ye_emlrtRSI = {
    221,             /* lineNo */
    "unaryMinOrMax", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo af_emlrtRSI = {
    308,                     /* lineNo */
    "unaryMinOrMaxDispatch", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo bf_emlrtRSI = {
    349,          /* lineNo */
    "minOrMax1D", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    111,             /* lineNo */
    35,              /* colNo */
    "sparse/sparse", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    116,             /* lineNo */
    35,              /* colNo */
    "sparse/sparse", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pName */
};

static emlrtRTEInfo j_emlrtRTEI = {
    148,             /* lineNo */
    43,              /* colNo */
    "sparse/sparse", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pName */
};

static emlrtRTEInfo k_emlrtRTEI = {
    153,             /* lineNo */
    43,              /* colNo */
    "sparse/sparse", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pName */
};

static emlrtDCInfo db_emlrtDCI = {
    193,             /* lineNo */
    48,              /* colNo */
    "sparse/sparse", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m", /* pName */
    4                   /* checkKind */
};

static emlrtRTEInfo ae_emlrtRTEI = {
    125,      /* lineNo */
    44,       /* colNo */
    "sparse", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pName */
};

static emlrtRTEInfo be_emlrtRTEI = {
    13,       /* lineNo */
    1,        /* colNo */
    "sparse", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m" /* pName
                                                                           */
};

static emlrtRTEInfo de_emlrtRTEI = {
    119,      /* lineNo */
    13,       /* colNo */
    "sparse", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pName */
};

static emlrtRTEInfo ee_emlrtRTEI = {
    120,      /* lineNo */
    13,       /* colNo */
    "sparse", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pName */
};

static emlrtRTEInfo fe_emlrtRTEI = {
    125,      /* lineNo */
    13,       /* colNo */
    "sparse", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pName */
};

/* Function Definitions */
void sparse(const emlrtStack *sp, const emxArray_real_T *varargin_1,
            const emxArray_real_T *varargin_2,
            const emxArray_real_T *varargin_3, real_T varargin_4,
            real_T varargin_5, b_sparse *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  emxArray_int32_T *cidxInt;
  emxArray_int32_T *ridxInt;
  emxArray_int32_T *sortedIndices;
  const real_T *varargin_3_data;
  int32_T i;
  int32_T k;
  int32_T nc;
  int32_T nr;
  int32_T ny;
  int32_T y_tmp_tmp;
  int32_T *cidxInt_data;
  int32_T *ridxInt_data;
  int32_T *sortedIndices_data;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  varargin_3_data = varargin_3->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &td_emlrtRSI;
  nc = varargin_2->size[1] << 8;
  nr = varargin_1->size[1] << 8;
  ny = varargin_3->size[1] << 8;
  if ((nr != nc) || (ny != nc)) {
    emlrtErrorWithMessageIdR2018a(&st, &h_emlrtRTEI, "MATLAB:samelen",
                                  "MATLAB:samelen", 0);
  }
  if ((ny != nc) && (ny != nr)) {
    emlrtErrorWithMessageIdR2018a(&st, &i_emlrtRTEI, "MATLAB:samelen",
                                  "MATLAB:samelen", 0);
  }
  emxInit_int32_T(&st, &ridxInt, 1, &de_emlrtRTEI);
  emxInit_int32_T(&st, &cidxInt, 1, &ee_emlrtRTEI);
  emxInit_int32_T(&st, &sortedIndices, 1, &fe_emlrtRTEI);
  b_st.site = &ud_emlrtRSI;
  assertValidIndexArg(&b_st, varargin_1, ridxInt);
  b_st.site = &vd_emlrtRSI;
  assertValidIndexArg(&b_st, varargin_2, cidxInt);
  i = sortedIndices->size[0];
  sortedIndices->size[0] = nc;
  emxEnsureCapacity_int32_T(&st, sortedIndices, i, &ae_emlrtRTEI);
  sortedIndices_data = sortedIndices->data;
  b_st.site = &wd_emlrtRSI;
  overflow = ((1 <= nc) && (nc > 2147483646));
  if (overflow) {
    c_st.site = &m_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (k = 0; k < nc; k++) {
    sortedIndices_data[k] = k + 1;
  }
  b_st.site = &xd_emlrtRSI;
  c_st.site = &ge_emlrtRSI;
  introsort(&c_st, sortedIndices, cidxInt->size[0], cidxInt, ridxInt);
  sortedIndices_data = sortedIndices->data;
  c_st.site = &he_emlrtRSI;
  permuteVector(&c_st, sortedIndices, cidxInt);
  cidxInt_data = cidxInt->data;
  c_st.site = &ie_emlrtRSI;
  permuteVector(&c_st, sortedIndices, ridxInt);
  ridxInt_data = ridxInt->data;
  b_st.site = &yd_emlrtRSI;
  c_st.site = &ue_emlrtRSI;
  assertValidSizeArg(&c_st, varargin_4);
  if (varargin_4 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &l_emlrtRTEI,
                                  "Coder:toolbox:SparseNegativeSize",
                                  "Coder:toolbox:SparseNegativeSize", 0);
  }
  if (!(varargin_4 < 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &m_emlrtRTEI, "Coder:toolbox:SparseMaxSize",
        "Coder:toolbox:SparseMaxSize", 2, 12, MAX_int32_T);
  }
  b_st.site = &ae_emlrtRSI;
  c_st.site = &ue_emlrtRSI;
  assertValidSizeArg(&c_st, varargin_5);
  if (varargin_5 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &l_emlrtRTEI,
                                  "Coder:toolbox:SparseNegativeSize",
                                  "Coder:toolbox:SparseNegativeSize", 0);
  }
  if (!(varargin_5 < 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &m_emlrtRTEI, "Coder:toolbox:SparseMaxSize",
        "Coder:toolbox:SparseMaxSize", 2, 12, MAX_int32_T);
  }
  y->m = (int32_T)varargin_4;
  y_tmp_tmp = (int32_T)varargin_5;
  y->n = (int32_T)varargin_5;
  if (ridxInt->size[0] != 0) {
    b_st.site = &be_emlrtRSI;
    c_st.site = &ve_emlrtRSI;
    d_st.site = &we_emlrtRSI;
    e_st.site = &xe_emlrtRSI;
    f_st.site = &ye_emlrtRSI;
    nr = ridxInt->size[0];
    g_st.site = &af_emlrtRSI;
    ny = ridxInt_data[0];
    h_st.site = &bf_emlrtRSI;
    overflow = ((2 <= ridxInt->size[0]) && (ridxInt->size[0] > 2147483646));
    if (overflow) {
      i_st.site = &m_emlrtRSI;
      check_forloop_overflow_error(&i_st);
    }
    for (k = 2; k <= nr; k++) {
      i = ridxInt_data[k - 1];
      if (ny < i) {
        ny = i;
      }
    }
    if (ny > (int32_T)varargin_4) {
      emlrtErrorWithMessageIdR2018a(&st, &j_emlrtRTEI,
                                    "Coder:builtins:IndexOutOfBounds",
                                    "Coder:builtins:IndexOutOfBounds", 6, 12,
                                    ny, 12, 1, 12, (int32_T)varargin_4);
    }
  }
  if ((cidxInt->size[0] != 0) &&
      (cidxInt_data[cidxInt->size[0] - 1] > (int32_T)varargin_5)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &k_emlrtRTEI, "Coder:builtins:IndexOutOfBounds",
        "Coder:builtins:IndexOutOfBounds", 6, 12,
        cidxInt_data[cidxInt->size[0] - 1], 12, 1, 12, (int32_T)varargin_5);
  }
  if (nc >= 1) {
    nr = nc;
  } else {
    nr = 1;
  }
  i = y->d->size[0];
  y->d->size[0] = nr;
  emxEnsureCapacity_real_T(&st, y->d, i, &be_emlrtRTEI);
  for (i = 0; i < nr; i++) {
    y->d->data[i] = 0.0;
  }
  y->maxnz = nr;
  if ((int32_T)varargin_5 + 1 < 0) {
    emlrtNonNegativeCheckR2012b((int32_T)varargin_5 + 1, &db_emlrtDCI, &st);
  }
  i = y->colidx->size[0];
  y->colidx->size[0] = (int32_T)varargin_5 + 1;
  emxEnsureCapacity_int32_T(&st, y->colidx, i, &ce_emlrtRTEI);
  y->colidx->data[0] = 1;
  i = y->rowidx->size[0];
  y->rowidx->size[0] = nr;
  emxEnsureCapacity_int32_T(&st, y->rowidx, i, &be_emlrtRTEI);
  for (i = 0; i < nr; i++) {
    y->rowidx->data[i] = 0;
  }
  nr = 0;
  b_st.site = &ce_emlrtRSI;
  overflow = ((1 <= (int32_T)varargin_5) && ((int32_T)varargin_5 > 2147483646));
  if (overflow) {
    c_st.site = &m_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (ny = 0; ny < y_tmp_tmp; ny++) {
    while ((nr + 1 <= nc) && (cidxInt_data[nr] == ny + 1)) {
      y->rowidx->data[nr] = ridxInt_data[nr];
      nr++;
    }
    y->colidx->data[ny + 1] = nr + 1;
  }
  emxFree_int32_T(&st, &cidxInt);
  emxFree_int32_T(&st, &ridxInt);
  b_st.site = &de_emlrtRSI;
  overflow = ((1 <= nc) && (nc > 2147483646));
  if (overflow) {
    c_st.site = &m_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (k = 0; k < nc; k++) {
    y->d->data[k] = varargin_3_data[sortedIndices_data[k] - 1];
  }
  emxFree_int32_T(&st, &sortedIndices);
  b_st.site = &ee_emlrtRSI;
  sparse_fillIn(&b_st, y);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (sparse.c) */
