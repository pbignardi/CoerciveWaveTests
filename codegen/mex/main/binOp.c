/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * binOp.c
 *
 * Code generation for function 'binOp'
 *
 */

/* Include files */
#include "binOp.h"
#include "bigProduct.h"
#include "eml_int_forloop_overflow_check.h"
#include "main_data.h"
#include "main_emxutil.h"
#include "main_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo rf_emlrtRSI = {
    495,                /* lineNo */
    "allocEqsizeBinop", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" /* pathName */
};

static emlrtRSInfo sf_emlrtRSI = {
    1482,                 /* lineNo */
    "sparse/spallocLike", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo vf_emlrtRSI = {
    327,                          /* lineNo */
    "sparseSparseRowExpandBinOp", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" /* pathName */
};

static emlrtRSInfo wf_emlrtRSI = {
    317,                          /* lineNo */
    "sparseSparseRowExpandBinOp", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" /* pathName */
};

static emlrtRSInfo xf_emlrtRSI = {
    312,                          /* lineNo */
    "sparseSparseRowExpandBinOp", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" /* pathName */
};

static emlrtRSInfo yf_emlrtRSI = {
    284,                          /* lineNo */
    "sparseSparseRowExpandBinOp", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" /* pathName */
};

static emlrtRTEInfo u_emlrtRTEI = {
    489,                /* lineNo */
    9,                  /* colNo */
    "allocEqsizeBinop", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" /* pName */
};

static emlrtRTEInfo qe_emlrtRTEI = {
    495,     /* lineNo */
    1,       /* colNo */
    "binOp", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" /* pName */
};

/* Function Definitions */
void allocEqsizeBinop(const emlrtStack *sp, const emxArray_int32_T *a_colidx,
                      int32_T a_m, int32_T a_n,
                      const emxArray_int32_T *b_colidx, int32_T b_m,
                      int32_T b_n, int32_T sn, int32_T sm, emxArray_real_T *s_d,
                      emxArray_int32_T *s_colidx, emxArray_int32_T *s_rowidx,
                      int32_T *s_m, int32_T *s_n, int32_T *s_maxnz)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T *s_d_data;
  const int32_T *a_colidx_data;
  const int32_T *b_colidx_data;
  int32_T a__3;
  int32_T nza;
  int32_T nzb;
  int32_T overflow;
  int32_T *s_colidx_data;
  int32_T *s_rowidx_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_colidx_data = b_colidx->data;
  a_colidx_data = a_colidx->data;
  nza = a_colidx_data[a_colidx->size[0] - 1] - 1;
  nzb = b_colidx_data[b_colidx->size[0] - 1] - 1;
  if ((a_m != b_m) || (a_n != b_n)) {
    if (a_n == 1) {
      nza = (a_colidx_data[a_colidx->size[0] - 1] - 1) * b_n;
    } else if (a_m == 1) {
      nza = (a_colidx_data[a_colidx->size[0] - 1] - 1) * b_m;
    }
    if (b_n == 1) {
      nzb = (b_colidx_data[b_colidx->size[0] - 1] - 1) * a_n;
    } else if (a_m == 1) {
      nzb = b_colidx_data[b_colidx->size[0] - 1] - 1;
    }
  }
  if (nza > MAX_int32_T - nzb) {
    bigProduct(sn, sm, &a__3, &overflow);
    if (overflow != 0) {
      emlrtErrorWithMessageIdR2018a(sp, &u_emlrtRTEI,
                                    "Coder:toolbox:SparseFuncAlmostFull",
                                    "Coder:toolbox:SparseFuncAlmostFull", 0);
    }
  }
  nza += nzb;
  nzb = sn * sm;
  nzb = muIntScalarMin_sint32(nza, nzb);
  if (nzb < 1) {
    nzb = 1;
  }
  st.site = &rf_emlrtRSI;
  b_st.site = &sf_emlrtRSI;
  c_st.site = &yd_emlrtRSI;
  if (sm < 0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &l_emlrtRTEI,
                                  "Coder:toolbox:SparseNegativeSize",
                                  "Coder:toolbox:SparseNegativeSize", 0);
  }
  if (sm >= MAX_int32_T) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &m_emlrtRTEI, "Coder:toolbox:SparseMaxSize",
        "Coder:toolbox:SparseMaxSize", 2, 12, MAX_int32_T);
  }
  c_st.site = &ae_emlrtRSI;
  if (sn < 0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &l_emlrtRTEI,
                                  "Coder:toolbox:SparseNegativeSize",
                                  "Coder:toolbox:SparseNegativeSize", 0);
  }
  if (sn >= MAX_int32_T) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &m_emlrtRTEI, "Coder:toolbox:SparseMaxSize",
        "Coder:toolbox:SparseMaxSize", 2, 12, MAX_int32_T);
  }
  c_st.site = &tf_emlrtRSI;
  if (nzb >= MAX_int32_T) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &m_emlrtRTEI, "Coder:toolbox:SparseMaxSize",
        "Coder:toolbox:SparseMaxSize", 2, 12, MAX_int32_T);
  }
  nza = s_d->size[0];
  s_d->size[0] = nzb;
  emxEnsureCapacity_real_T(&b_st, s_d, nza, &qe_emlrtRTEI);
  s_d_data = s_d->data;
  for (nza = 0; nza < nzb; nza++) {
    s_d_data[nza] = 0.0;
  }
  nza = s_colidx->size[0];
  s_colidx->size[0] = sn + 1;
  emxEnsureCapacity_int32_T(&b_st, s_colidx, nza, &ce_emlrtRTEI);
  s_colidx_data = s_colidx->data;
  s_colidx_data[0] = 1;
  nza = s_rowidx->size[0];
  s_rowidx->size[0] = nzb;
  emxEnsureCapacity_int32_T(&b_st, s_rowidx, nza, &qe_emlrtRTEI);
  s_rowidx_data = s_rowidx->data;
  for (nza = 0; nza < nzb; nza++) {
    s_rowidx_data[nza] = 0;
  }
  for (a__3 = 0; a__3 < sn; a__3++) {
    s_colidx_data[a__3 + 1] = 1;
  }
  nza = s_colidx->size[0];
  for (a__3 = 0; a__3 <= nza - 2; a__3++) {
    s_colidx_data[a__3] = 1;
  }
  s_colidx_data[s_colidx->size[0] - 1] = 1;
  *s_m = sm;
  *s_n = sn;
  *s_maxnz = nzb;
}

void b_sparseSparseRowExpandBinOp(const emlrtStack *sp,
                                  const emxArray_real_T *rowA_d,
                                  const emxArray_int32_T *rowA_colidx,
                                  const emxArray_real_T *b_d,
                                  const emxArray_int32_T *b_colidx,
                                  const emxArray_int32_T *b_rowidx, b_sparse *s)
{
  emlrtStack b_st;
  emlrtStack st;
  const real_T *b_d_data;
  const real_T *rowA_d_data;
  real_T av;
  real_T val;
  const int32_T *b_colidx_data;
  const int32_T *b_rowidx_data;
  const int32_T *rowA_colidx_data;
  int32_T c;
  int32_T didx;
  int32_T firstNonZeroRow_tmp;
  int32_T i;
  int32_T lastNonZeroRow_tmp;
  int32_T n;
  int32_T offset;
  int32_T r;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_rowidx_data = b_rowidx->data;
  b_colidx_data = b_colidx->data;
  b_d_data = b_d->data;
  rowA_colidx_data = rowA_colidx->data;
  rowA_d_data = rowA_d->data;
  didx = 1;
  s->colidx->data[0] = 1;
  n = s->n;
  st.site = &yf_emlrtRSI;
  overflow = ((1 <= s->n) && (s->n > 2147483646));
  if (overflow) {
    b_st.site = &m_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (c = 0; c < n; c++) {
    if (rowA_colidx_data[c] == rowA_colidx_data[c + 1]) {
      av = 0.0;
    } else {
      av = rowA_d_data[rowA_colidx_data[c] - 1];
    }
    if (b_colidx_data[0] == b_colidx_data[1]) {
      if (av != 0.0) {
        i = s->m;
        for (r = 0; r < i; r++) {
          if (av != 0.0) {
            s->d->data[didx - 1] = av;
            s->rowidx->data[didx - 1] = r + 1;
            didx++;
          }
        }
      }
      s->colidx->data[c + 1] = didx;
    } else {
      firstNonZeroRow_tmp = b_rowidx_data[b_colidx_data[0] - 1];
      lastNonZeroRow_tmp = b_rowidx_data[b_colidx_data[1] - 2];
      if (av != 0.0) {
        st.site = &xf_emlrtRSI;
        if (1 > firstNonZeroRow_tmp - 1) {
          overflow = false;
        } else {
          overflow = (b_rowidx_data[b_colidx_data[0] - 1] - 1 > 2147483646);
        }
        if (overflow) {
          b_st.site = &m_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        for (r = 0; r <= firstNonZeroRow_tmp - 2; r++) {
          if (av != 0.0) {
            s->d->data[didx - 1] = av;
            s->rowidx->data[didx - 1] = r + 1;
            didx++;
          }
        }
      }
      offset = -1;
      st.site = &wf_emlrtRSI;
      overflow = ((firstNonZeroRow_tmp <= lastNonZeroRow_tmp) &&
                  (lastNonZeroRow_tmp > 2147483646));
      if (overflow) {
        b_st.site = &m_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (r = firstNonZeroRow_tmp; r <= lastNonZeroRow_tmp; r++) {
        i = b_colidx_data[0] + offset;
        if (b_rowidx_data[i] == r) {
          val = b_d_data[i] + av;
          if (val != 0.0) {
            s->d->data[didx - 1] = val;
            s->rowidx->data[didx - 1] = r;
            didx++;
          }
          offset++;
        } else if (av != 0.0) {
          s->d->data[didx - 1] = av;
          s->rowidx->data[didx - 1] = r;
          didx++;
        }
      }
      if (av != 0.0) {
        firstNonZeroRow_tmp = lastNonZeroRow_tmp + 1;
        offset = s->m;
        st.site = &vf_emlrtRSI;
        overflow = ((lastNonZeroRow_tmp + 1 <= s->m) && (s->m > 2147483646));
        if (overflow) {
          b_st.site = &m_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        for (r = firstNonZeroRow_tmp; r <= offset; r++) {
          if (av != 0.0) {
            s->d->data[didx - 1] = av;
            s->rowidx->data[didx - 1] = r;
            didx++;
          }
        }
      }
      s->colidx->data[c + 1] = didx;
    }
  }
}

void c_sparseSparseRowExpandBinOp(const emlrtStack *sp,
                                  const emxArray_real_T *rowA_d,
                                  const emxArray_int32_T *rowA_colidx,
                                  const emxArray_real_T *b_d,
                                  const emxArray_int32_T *b_colidx,
                                  const emxArray_int32_T *b_rowidx, b_sparse *s)
{
  emlrtStack b_st;
  emlrtStack st;
  const real_T *b_d_data;
  const real_T *rowA_d_data;
  real_T av;
  real_T val;
  const int32_T *b_colidx_data;
  const int32_T *b_rowidx_data;
  const int32_T *rowA_colidx_data;
  int32_T a_tmp;
  int32_T bc;
  int32_T c;
  int32_T didx;
  int32_T firstNonZeroRow_tmp;
  int32_T lastNonZeroRow_tmp;
  int32_T n;
  int32_T offset;
  int32_T r;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_rowidx_data = b_rowidx->data;
  b_colidx_data = b_colidx->data;
  b_d_data = b_d->data;
  rowA_colidx_data = rowA_colidx->data;
  rowA_d_data = rowA_d->data;
  didx = 1;
  s->colidx->data[0] = 1;
  n = s->n;
  bc = 0;
  st.site = &yf_emlrtRSI;
  overflow = ((1 <= s->n) && (s->n > 2147483646));
  if (overflow) {
    b_st.site = &m_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (c = 0; c < n; c++) {
    if (rowA_colidx_data[c] == rowA_colidx_data[c + 1]) {
      av = 0.0;
    } else {
      av = rowA_d_data[rowA_colidx_data[c] - 1];
    }
    a_tmp = b_colidx_data[bc + 1];
    if (b_colidx_data[bc] == a_tmp) {
      if (av != 0.0) {
        a_tmp = s->m;
        for (r = 0; r < a_tmp; r++) {
          if (av != 0.0) {
            s->d->data[didx - 1] = av;
            s->rowidx->data[didx - 1] = r + 1;
            didx++;
          }
        }
      }
      s->colidx->data[c + 1] = didx;
      bc++;
    } else {
      firstNonZeroRow_tmp = b_rowidx_data[b_colidx_data[bc] - 1];
      lastNonZeroRow_tmp = b_rowidx_data[a_tmp - 2];
      if (av != 0.0) {
        st.site = &xf_emlrtRSI;
        if (1 > firstNonZeroRow_tmp - 1) {
          overflow = false;
        } else {
          overflow = (b_rowidx_data[b_colidx_data[bc] - 1] - 1 > 2147483646);
        }
        if (overflow) {
          b_st.site = &m_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        for (r = 0; r <= firstNonZeroRow_tmp - 2; r++) {
          if (av != 0.0) {
            s->d->data[didx - 1] = av;
            s->rowidx->data[didx - 1] = r + 1;
            didx++;
          }
        }
      }
      offset = -1;
      st.site = &wf_emlrtRSI;
      overflow = ((firstNonZeroRow_tmp <= lastNonZeroRow_tmp) &&
                  (lastNonZeroRow_tmp > 2147483646));
      if (overflow) {
        b_st.site = &m_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (r = firstNonZeroRow_tmp; r <= lastNonZeroRow_tmp; r++) {
        a_tmp = b_colidx_data[bc] + offset;
        if (b_rowidx_data[a_tmp] == r) {
          val = b_d_data[a_tmp] + av;
          if (val != 0.0) {
            s->d->data[didx - 1] = val;
            s->rowidx->data[didx - 1] = r;
            didx++;
          }
          offset++;
        } else if (av != 0.0) {
          s->d->data[didx - 1] = av;
          s->rowidx->data[didx - 1] = r;
          didx++;
        }
      }
      if (av != 0.0) {
        a_tmp = lastNonZeroRow_tmp + 1;
        firstNonZeroRow_tmp = s->m;
        st.site = &vf_emlrtRSI;
        overflow = ((lastNonZeroRow_tmp + 1 <= s->m) && (s->m > 2147483646));
        if (overflow) {
          b_st.site = &m_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        for (r = a_tmp; r <= firstNonZeroRow_tmp; r++) {
          if (av != 0.0) {
            s->d->data[didx - 1] = av;
            s->rowidx->data[didx - 1] = r;
            didx++;
          }
        }
      }
      s->colidx->data[c + 1] = didx;
      bc++;
    }
  }
}

void sparseSparseEqHeightBinOp(const emlrtStack *sp, const emxArray_real_T *a_d,
                               const emxArray_int32_T *a_colidx,
                               const emxArray_int32_T *a_rowidx,
                               const emxArray_real_T *b_d,
                               const emxArray_int32_T *b_colidx,
                               const emxArray_int32_T *b_rowidx, b_sparse *s)
{
  emlrtStack b_st;
  emlrtStack st;
  const real_T *a_d_data;
  const real_T *b_d_data;
  real_T val;
  const int32_T *a_colidx_data;
  const int32_T *a_rowidx_data;
  const int32_T *b_colidx_data;
  const int32_T *b_rowidx_data;
  int32_T aidx;
  int32_T bidx;
  int32_T bidx_tmp;
  int32_T c;
  int32_T didx;
  int32_T moreAToDo_tmp;
  int32_T n;
  boolean_T moreBToDo;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_rowidx_data = b_rowidx->data;
  b_colidx_data = b_colidx->data;
  b_d_data = b_d->data;
  a_rowidx_data = a_rowidx->data;
  a_colidx_data = a_colidx->data;
  a_d_data = a_d->data;
  didx = 1;
  s->colidx->data[0] = 1;
  n = s->n;
  st.site = &uf_emlrtRSI;
  overflow = ((1 <= s->n) && (s->n > 2147483646));
  if (overflow) {
    b_st.site = &m_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (c = 0; c < n; c++) {
    aidx = a_colidx_data[c] - 1;
    bidx_tmp = b_colidx_data[c];
    bidx = bidx_tmp - 1;
    moreAToDo_tmp = a_colidx_data[c + 1];
    overflow = (a_colidx_data[c] < moreAToDo_tmp);
    moreBToDo = (bidx_tmp < b_colidx_data[c + 1]);
    while (overflow || moreBToDo) {
      while ((aidx + 1 < moreAToDo_tmp) &&
             ((!moreBToDo) || (a_rowidx_data[aidx] < b_rowidx_data[bidx]))) {
        if (a_d_data[aidx] != 0.0) {
          s->d->data[didx - 1] = a_d_data[aidx];
          s->rowidx->data[didx - 1] = a_rowidx_data[aidx];
          didx++;
        }
        aidx++;
      }
      overflow = (aidx + 1 < moreAToDo_tmp);
      while ((bidx + 1 < b_colidx_data[c + 1]) &&
             ((!overflow) || (b_rowidx_data[bidx] < a_rowidx_data[aidx]))) {
        if (b_d_data[bidx] != 0.0) {
          s->d->data[didx - 1] = b_d_data[bidx];
          s->rowidx->data[didx - 1] = b_rowidx_data[bidx];
          didx++;
        }
        bidx++;
      }
      while ((aidx + 1 < moreAToDo_tmp) && (bidx + 1 < b_colidx_data[c + 1]) &&
             (a_rowidx_data[aidx] == b_rowidx_data[bidx])) {
        val = a_d_data[aidx] + b_d_data[bidx];
        if (val != 0.0) {
          s->d->data[didx - 1] = val;
          s->rowidx->data[didx - 1] = b_rowidx_data[bidx];
          didx++;
        }
        bidx++;
        aidx++;
      }
      overflow = (aidx + 1 < moreAToDo_tmp);
      moreBToDo = (bidx + 1 < b_colidx_data[c + 1]);
    }
    s->colidx->data[c + 1] = didx;
  }
}

void sparseSparseRowExpandBinOp(const emlrtStack *sp,
                                const emxArray_real_T *rowA_d,
                                const emxArray_int32_T *rowA_colidx,
                                const emxArray_real_T *b_d,
                                const emxArray_int32_T *b_colidx,
                                const emxArray_int32_T *b_rowidx, b_sparse *s,
                                boolean_T expandB)
{
  emlrtStack b_st;
  emlrtStack st;
  const real_T *b_d_data;
  const real_T *rowA_d_data;
  real_T av;
  real_T val;
  const int32_T *b_colidx_data;
  const int32_T *b_rowidx_data;
  const int32_T *rowA_colidx_data;
  int32_T a_tmp;
  int32_T bc;
  int32_T bcInc;
  int32_T c;
  int32_T didx;
  int32_T firstNonZeroRow_tmp;
  int32_T lastNonZeroRow_tmp;
  int32_T n;
  int32_T offset;
  int32_T r;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_rowidx_data = b_rowidx->data;
  b_colidx_data = b_colidx->data;
  b_d_data = b_d->data;
  rowA_colidx_data = rowA_colidx->data;
  rowA_d_data = rowA_d->data;
  didx = 1;
  s->colidx->data[0] = 1;
  n = s->n;
  bc = 0;
  bcInc = !expandB;
  st.site = &yf_emlrtRSI;
  overflow = ((1 <= s->n) && (s->n > 2147483646));
  if (overflow) {
    b_st.site = &m_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (c = 0; c < n; c++) {
    if (rowA_colidx_data[c] == rowA_colidx_data[c + 1]) {
      av = 0.0;
    } else {
      av = rowA_d_data[rowA_colidx_data[c] - 1];
    }
    a_tmp = b_colidx_data[bc + 1];
    if (b_colidx_data[bc] == a_tmp) {
      if (av != 0.0) {
        a_tmp = s->m;
        for (r = 0; r < a_tmp; r++) {
          if (av != 0.0) {
            s->d->data[didx - 1] = av;
            s->rowidx->data[didx - 1] = r + 1;
            didx++;
          }
        }
      }
      s->colidx->data[c + 1] = didx;
      bc += bcInc;
    } else {
      firstNonZeroRow_tmp = b_rowidx_data[b_colidx_data[bc] - 1];
      lastNonZeroRow_tmp = b_rowidx_data[a_tmp - 2];
      if (av != 0.0) {
        st.site = &xf_emlrtRSI;
        if (1 > firstNonZeroRow_tmp - 1) {
          overflow = false;
        } else {
          overflow = (b_rowidx_data[b_colidx_data[bc] - 1] - 1 > 2147483646);
        }
        if (overflow) {
          b_st.site = &m_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        for (r = 0; r <= firstNonZeroRow_tmp - 2; r++) {
          if (av != 0.0) {
            s->d->data[didx - 1] = av;
            s->rowidx->data[didx - 1] = r + 1;
            didx++;
          }
        }
      }
      offset = -1;
      st.site = &wf_emlrtRSI;
      overflow = ((firstNonZeroRow_tmp <= lastNonZeroRow_tmp) &&
                  (lastNonZeroRow_tmp > 2147483646));
      if (overflow) {
        b_st.site = &m_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (r = firstNonZeroRow_tmp; r <= lastNonZeroRow_tmp; r++) {
        a_tmp = b_colidx_data[bc] + offset;
        if (b_rowidx_data[a_tmp] == r) {
          val = av + b_d_data[a_tmp];
          if (val != 0.0) {
            s->d->data[didx - 1] = val;
            s->rowidx->data[didx - 1] = r;
            didx++;
          }
          offset++;
        } else if (av != 0.0) {
          s->d->data[didx - 1] = av;
          s->rowidx->data[didx - 1] = r;
          didx++;
        }
      }
      if (av != 0.0) {
        a_tmp = lastNonZeroRow_tmp + 1;
        firstNonZeroRow_tmp = s->m;
        st.site = &vf_emlrtRSI;
        overflow = ((lastNonZeroRow_tmp + 1 <= s->m) && (s->m > 2147483646));
        if (overflow) {
          b_st.site = &m_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        for (r = a_tmp; r <= firstNonZeroRow_tmp; r++) {
          if (av != 0.0) {
            s->d->data[didx - 1] = av;
            s->rowidx->data[didx - 1] = r;
            didx++;
          }
        }
      }
      s->colidx->data[c + 1] = didx;
      bc += bcInc;
    }
  }
}

/* End of code generation (binOp.c) */
