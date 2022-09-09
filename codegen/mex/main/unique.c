/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * unique.c
 *
 * Code generation for function 'unique'
 *
 */

/* Include files */
#include "unique.h"
#include "eml_int_forloop_overflow_check.h"
#include "main_data.h"
#include "main_emxutil.h"
#include "main_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <math.h>

/* Variable Definitions */
static emlrtRSInfo th_emlrtRSI = {
    161,             /* lineNo */
    "unique_vector", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\unique.m" /* pathName
                                                                       */
};

static emlrtRSInfo uh_emlrtRSI = {
    163,             /* lineNo */
    "unique_vector", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\unique.m" /* pathName
                                                                       */
};

static emlrtRSInfo vh_emlrtRSI = {
    180,             /* lineNo */
    "unique_vector", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\unique.m" /* pathName
                                                                       */
};

static emlrtRSInfo wh_emlrtRSI = {
    198,             /* lineNo */
    "unique_vector", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\unique.m" /* pathName
                                                                       */
};

static emlrtRSInfo xh_emlrtRSI = {
    205,             /* lineNo */
    "unique_vector", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\unique.m" /* pathName
                                                                       */
};

static emlrtRSInfo yh_emlrtRSI = {
    218,             /* lineNo */
    "unique_vector", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\unique.m" /* pathName
                                                                       */
};

static emlrtRSInfo ai_emlrtRSI = {
    229,             /* lineNo */
    "unique_vector", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\unique.m" /* pathName
                                                                       */
};

static emlrtRSInfo bi_emlrtRSI = {
    243,             /* lineNo */
    "unique_vector", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\unique.m" /* pathName
                                                                       */
};

static emlrtRSInfo
    ci_emlrtRSI =
        {
            145,       /* lineNo */
            "sortIdx", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\sortIdx.m" /* pathName */
};

static emlrtRSInfo di_emlrtRSI =
    {
        57,          /* lineNo */
        "mergesort", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\mergesort.m" /* pathName */
};

static emlrtRSInfo ei_emlrtRSI =
    {
        113,         /* lineNo */
        "mergesort", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\mergesort.m" /* pathName */
};

static emlrtRSInfo
    fi_emlrtRSI =
        {
            40,       /* lineNo */
            "safeEq", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\safeEq.m" /* pathName */
};

static emlrtRSInfo gi_emlrtRSI =
    {
        46,    /* lineNo */
        "eps", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\elmat\\eps.m" /* pathName
                                                                          */
};

static emlrtRTEInfo w_emlrtRTEI = {
    236,             /* lineNo */
    1,               /* colNo */
    "unique_vector", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\unique.m" /* pName
                                                                       */
};

static emlrtRTEInfo we_emlrtRTEI = {
    161,      /* lineNo */
    1,        /* colNo */
    "unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\unique.m" /* pName
                                                                       */
};

static emlrtRTEInfo xe_emlrtRTEI =
    {
        52,          /* lineNo */
        9,           /* colNo */
        "mergesort", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\mergesort.m" /* pName */
};

static emlrtRTEInfo ye_emlrtRTEI = {
    162,      /* lineNo */
    20,       /* colNo */
    "unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\unique.m" /* pName
                                                                       */
};

static emlrtRTEInfo af_emlrtRTEI = {
    237,      /* lineNo */
    1,        /* colNo */
    "unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\unique.m" /* pName
                                                                       */
};

static emlrtRTEInfo bf_emlrtRTEI =
    {
        52,          /* lineNo */
        1,           /* colNo */
        "mergesort", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\mergesort.m" /* pName */
};

/* Function Definitions */
void unique_vector(const emlrtStack *sp, const emxArray_real_T *a,
                   emxArray_real_T *b)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_int32_T *idx;
  emxArray_int32_T *iwork;
  const real_T *a_data;
  real_T absx;
  real_T x;
  real_T *b_data;
  int32_T b_i;
  int32_T exitg2;
  int32_T exponent;
  int32_T i;
  int32_T i2;
  int32_T j;
  int32_T k;
  int32_T kEnd;
  int32_T n;
  int32_T na;
  int32_T nb;
  int32_T p;
  int32_T pEnd;
  int32_T qEnd;
  int32_T *idx_data;
  int32_T *iwork_data;
  boolean_T exitg1;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  a_data = a->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_int32_T(sp, &idx, 2, &we_emlrtRTEI);
  na = a->size[1];
  st.site = &th_emlrtRSI;
  n = a->size[1] + 1;
  i = idx->size[0] * idx->size[1];
  idx->size[0] = 1;
  idx->size[1] = a->size[1];
  emxEnsureCapacity_int32_T(&st, idx, i, &we_emlrtRTEI);
  idx_data = idx->data;
  b_i = a->size[1];
  for (i = 0; i < b_i; i++) {
    idx_data[i] = 0;
  }
  if (a->size[1] != 0) {
    emxInit_int32_T(&st, &iwork, 1, &bf_emlrtRTEI);
    b_st.site = &ci_emlrtRSI;
    i = iwork->size[0];
    iwork->size[0] = a->size[1];
    emxEnsureCapacity_int32_T(&b_st, iwork, i, &xe_emlrtRTEI);
    iwork_data = iwork->data;
    b_i = a->size[1] - 1;
    c_st.site = &di_emlrtRSI;
    overflow = ((1 <= a->size[1] - 1) && (a->size[1] - 1 > 2147483645));
    if (overflow) {
      d_st.site = &m_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (k = 1; k <= b_i; k += 2) {
      absx = a_data[k];
      if ((a_data[k - 1] <= absx) || muDoubleScalarIsNaN(absx)) {
        idx_data[k - 1] = k;
        idx_data[k] = k + 1;
      } else {
        idx_data[k - 1] = k + 1;
        idx_data[k] = k;
      }
    }
    if ((a->size[1] & 1) != 0) {
      idx_data[a->size[1] - 1] = a->size[1];
    }
    b_i = 2;
    while (b_i < n - 1) {
      i2 = b_i << 1;
      j = 1;
      for (pEnd = b_i + 1; pEnd < n; pEnd = qEnd + b_i) {
        p = j;
        nb = pEnd - 1;
        qEnd = j + i2;
        if (qEnd > n) {
          qEnd = n;
        }
        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          absx = a_data[idx_data[nb] - 1];
          i = idx_data[p - 1];
          if ((a_data[i - 1] <= absx) || muDoubleScalarIsNaN(absx)) {
            iwork_data[k] = i;
            p++;
            if (p == pEnd) {
              while (nb + 1 < qEnd) {
                k++;
                iwork_data[k] = idx_data[nb];
                nb++;
              }
            }
          } else {
            iwork_data[k] = idx_data[nb];
            nb++;
            if (nb + 1 == qEnd) {
              while (p < pEnd) {
                k++;
                iwork_data[k] = idx_data[p - 1];
                p++;
              }
            }
          }
          k++;
        }
        c_st.site = &ei_emlrtRSI;
        for (k = 0; k < kEnd; k++) {
          idx_data[(j + k) - 1] = iwork_data[k];
        }
        j = qEnd;
      }
      b_i = i2;
    }
    emxFree_int32_T(&b_st, &iwork);
  }
  i = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = a->size[1];
  emxEnsureCapacity_real_T(sp, b, i, &ye_emlrtRTEI);
  b_data = b->data;
  st.site = &uh_emlrtRSI;
  overflow = ((1 <= a->size[1]) && (a->size[1] > 2147483646));
  if (overflow) {
    b_st.site = &m_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (k = 0; k < na; k++) {
    b_data[k] = a_data[idx_data[k] - 1];
  }
  emxFree_int32_T(sp, &idx);
  k = 0;
  while ((k + 1 <= na) && muDoubleScalarIsInf(b_data[k]) && (b_data[k] < 0.0)) {
    k++;
  }
  pEnd = k;
  k = a->size[1];
  while ((k >= 1) && muDoubleScalarIsNaN(b_data[k - 1])) {
    k--;
  }
  p = a->size[1] - k;
  exitg1 = false;
  while ((!exitg1) && (k >= 1)) {
    absx = b_data[k - 1];
    if (muDoubleScalarIsInf(absx) && (absx > 0.0)) {
      k--;
    } else {
      exitg1 = true;
    }
  }
  b_i = (a->size[1] - k) - p;
  nb = 0;
  if (pEnd > 0) {
    nb = 1;
    st.site = &vh_emlrtRSI;
    if (pEnd > 2147483646) {
      b_st.site = &m_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
  }
  while (pEnd + 1 <= k) {
    x = b_data[pEnd];
    i2 = pEnd;
    do {
      exitg2 = 0;
      pEnd++;
      if (pEnd + 1 > k) {
        exitg2 = 1;
      } else {
        st.site = &wh_emlrtRSI;
        b_st.site = &fi_emlrtRSI;
        c_st.site = &gi_emlrtRSI;
        absx = muDoubleScalarAbs(x / 2.0);
        if ((!muDoubleScalarIsInf(absx)) && (!muDoubleScalarIsNaN(absx))) {
          if (absx <= 2.2250738585072014E-308) {
            absx = 4.94065645841247E-324;
          } else {
            frexp(absx, &exponent);
            absx = ldexp(1.0, exponent - 53);
          }
        } else {
          absx = rtNaN;
        }
        if ((muDoubleScalarAbs(x - b_data[pEnd]) < absx) ||
            (muDoubleScalarIsInf(b_data[pEnd]) && muDoubleScalarIsInf(x) &&
             ((b_data[pEnd] > 0.0) == (x > 0.0)))) {
          overflow = true;
        } else {
          overflow = false;
        }
        if (!overflow) {
          exitg2 = 1;
        }
      }
    } while (exitg2 == 0);
    nb++;
    b_data[nb - 1] = x;
    st.site = &xh_emlrtRSI;
    overflow = ((i2 + 1 <= pEnd) && (pEnd > 2147483646));
    if (overflow) {
      b_st.site = &m_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
  }
  if (b_i > 0) {
    nb++;
    b_data[nb - 1] = b_data[k];
    st.site = &yh_emlrtRSI;
    if (b_i > 2147483646) {
      b_st.site = &m_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
  }
  pEnd = k + b_i;
  st.site = &ai_emlrtRSI;
  overflow = ((1 <= p) && (p > 2147483646));
  if (overflow) {
    b_st.site = &m_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (j = 0; j < p; j++) {
    b_data[nb + j] = b_data[pEnd + j];
  }
  nb += p;
  if (nb > a->size[1]) {
    emlrtErrorWithMessageIdR2018a(sp, &w_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (1 > nb) {
    b->size[1] = 0;
  } else {
    i = b->size[0] * b->size[1];
    b->size[1] = nb;
    emxEnsureCapacity_real_T(sp, b, i, &af_emlrtRTEI);
  }
  st.site = &bi_emlrtRSI;
  overflow = ((1 <= nb) && (nb > 2147483646));
  if (overflow) {
    b_st.site = &m_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (unique.c) */
