/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * kron.c
 *
 * Code generation for function 'kron'
 *
 */

/* Include files */
#include "kron.h"
#include "eml_int_forloop_overflow_check.h"
#include "main_data.h"
#include "main_emxutil.h"
#include "main_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo n_emlrtRSI =
    {
        33,     /* lineNo */
        "kron", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\kron.m" /* pathName
                                                                         */
};

static emlrtRSInfo o_emlrtRSI =
    {
        34,     /* lineNo */
        "kron", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\kron.m" /* pathName
                                                                         */
};

static emlrtRSInfo dh_emlrtRSI =
    {
        32,     /* lineNo */
        "kron", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\kron.m" /* pathName
                                                                         */
};

static emlrtRSInfo eh_emlrtRSI =
    {
        35,     /* lineNo */
        "kron", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\kron.m" /* pathName
                                                                         */
};

static emlrtRTEInfo pc_emlrtRTEI =
    {
        30,     /* lineNo */
        20,     /* colNo */
        "kron", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\kron.m" /* pName
                                                                         */
};

/* Function Definitions */
void b_kron(const real_T A[16], const real_T B[16], real_T K[256])
{
  real_T b_K_tmp;
  int32_T K_tmp;
  int32_T b_j1;
  int32_T i1;
  int32_T j2;
  int32_T kidx;
  kidx = -1;
  for (b_j1 = 0; b_j1 < 4; b_j1++) {
    for (j2 = 0; j2 < 4; j2++) {
      K_tmp = j2 << 2;
      for (i1 = 0; i1 < 4; i1++) {
        b_K_tmp = A[i1 + (b_j1 << 2)];
        K[kidx + 1] = b_K_tmp * B[K_tmp];
        K[kidx + 2] = b_K_tmp * B[K_tmp + 1];
        K[kidx + 3] = b_K_tmp * B[K_tmp + 2];
        K[kidx + 4] = b_K_tmp * B[K_tmp + 3];
        kidx += 4;
      }
    }
  }
}

void c_kron(const emlrtStack *sp, const emxArray_real_T *A,
            const emxArray_real_T *B, emxArray_real_T *K)
{
  emlrtStack b_st;
  emlrtStack st;
  const real_T *B_data;
  real_T *K_data;
  int32_T b_j1;
  int32_T j2;
  int32_T kidx;
  int32_T na;
  int32_T nb;
  boolean_T b_overflow;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  B_data = B->data;
  na = A->size[1];
  nb = B->size[1];
  kidx = K->size[0] * K->size[1];
  K->size[0] = 1;
  K->size[1] = A->size[1] * B->size[1];
  emxEnsureCapacity_real_T(sp, K, kidx, &pc_emlrtRTEI);
  K_data = K->data;
  kidx = -1;
  st.site = &dh_emlrtRSI;
  overflow = ((1 <= A->size[1]) && (A->size[1] > 2147483646));
  if (overflow) {
    b_st.site = &m_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  if (0 <= A->size[1] - 1) {
    b_overflow = ((1 <= B->size[1]) && (B->size[1] > 2147483646));
  }
  for (b_j1 = 0; b_j1 < na; b_j1++) {
    st.site = &n_emlrtRSI;
    if (b_overflow) {
      b_st.site = &m_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (j2 = 0; j2 < nb; j2++) {
      K_data[(kidx + j2) + 1] = B_data[j2];
    }
    kidx += nb;
  }
}

void d_kron(const emlrtStack *sp, const emxArray_real_T *A,
            const emxArray_real_T *B, emxArray_real_T *K)
{
  emlrtStack b_st;
  emlrtStack st;
  const real_T *A_data;
  real_T *K_data;
  int32_T i1;
  int32_T i2;
  int32_T kidx;
  int32_T ma;
  int32_T mb;
  boolean_T b_overflow;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  A_data = A->data;
  ma = A->size[0];
  mb = B->size[0];
  kidx = K->size[0];
  K->size[0] = A->size[0] * B->size[0];
  emxEnsureCapacity_real_T(sp, K, kidx, &pc_emlrtRTEI);
  K_data = K->data;
  kidx = -1;
  st.site = &o_emlrtRSI;
  overflow = ((1 <= A->size[0]) && (A->size[0] > 2147483646));
  if (overflow) {
    b_st.site = &m_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  if (0 <= A->size[0] - 1) {
    b_overflow = ((1 <= B->size[0]) && (B->size[0] > 2147483646));
  }
  for (i1 = 0; i1 < ma; i1++) {
    st.site = &eh_emlrtRSI;
    if (b_overflow) {
      b_st.site = &m_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (i2 = 0; i2 < mb; i2++) {
      K_data[(kidx + i2) + 1] = A_data[i1];
    }
    kidx += mb;
  }
}

void e_kron(const real_T A[8], const real_T B[8], real_T K[64])
{
  int32_T i1;
  int32_T i2;
  int32_T kidx;
  kidx = -1;
  for (i1 = 0; i1 < 8; i1++) {
    for (i2 = 0; i2 < 8; i2++) {
      K[(kidx + i2) + 1] = A[i1] * B[i2];
    }
    kidx += 8;
  }
}

void f_kron(const real_T A[32], const real_T B[32], real_T K[1024])
{
  int32_T b_j1;
  int32_T i1;
  int32_T i2;
  int32_T j2;
  int32_T kidx;
  kidx = -1;
  for (b_j1 = 0; b_j1 < 4; b_j1++) {
    for (j2 = 0; j2 < 4; j2++) {
      for (i1 = 0; i1 < 8; i1++) {
        for (i2 = 0; i2 < 8; i2++) {
          K[(kidx + i2) + 1] = A[i1 + (b_j1 << 3)] * B[i2 + (j2 << 3)];
        }
        kidx += 8;
      }
    }
  }
}

void g_kron(const real_T A[4], const real_T B[32], real_T K[128])
{
  int32_T b_j1;
  int32_T i2;
  int32_T j2;
  int32_T kidx;
  kidx = -1;
  for (b_j1 = 0; b_j1 < 4; b_j1++) {
    for (j2 = 0; j2 < 4; j2++) {
      for (i2 = 0; i2 < 8; i2++) {
        K[(kidx + i2) + 1] = A[b_j1] * B[i2 + (j2 << 3)];
      }
      kidx += 8;
    }
  }
}

void h_kron(const real_T A[32], const real_T B[4], real_T K[128])
{
  int32_T b_j1;
  int32_T i1;
  int32_T j2;
  int32_T kidx;
  kidx = -1;
  for (b_j1 = 0; b_j1 < 4; b_j1++) {
    for (j2 = 0; j2 < 4; j2++) {
      for (i1 = 0; i1 < 8; i1++) {
        K[(kidx + i1) + 1] = A[i1 + (b_j1 << 3)] * B[j2];
      }
      kidx += 8;
    }
  }
}

void i_kron(const emlrtStack *sp, const real_T A[64], const emxArray_real_T *B,
            emxArray_real_T *K)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T *K_data;
  int32_T i1;
  int32_T j2;
  int32_T kidx;
  int32_T nb;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nb = B->size[1];
  kidx = K->size[0] * K->size[1];
  K->size[0] = 64;
  K->size[1] = B->size[1];
  emxEnsureCapacity_real_T(sp, K, kidx, &pc_emlrtRTEI);
  K_data = K->data;
  kidx = -1;
  st.site = &n_emlrtRSI;
  overflow = ((1 <= B->size[1]) && (B->size[1] > 2147483646));
  if (overflow) {
    b_st.site = &m_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (j2 = 0; j2 < nb; j2++) {
    for (i1 = 0; i1 < 64; i1++) {
      K_data[(kidx + i1) + 1] = A[i1];
    }
    kidx += 64;
  }
}

void kron(const emlrtStack *sp, const emxArray_real_T *A,
          const emxArray_real_T *B, emxArray_real_T *K)
{
  emlrtStack b_st;
  emlrtStack st;
  const real_T *A_data;
  const real_T *B_data;
  real_T *K_data;
  int32_T i1;
  int32_T j2;
  int32_T kidx;
  int32_T ma;
  int32_T nb;
  boolean_T b_overflow;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  B_data = B->data;
  A_data = A->data;
  ma = A->size[0];
  nb = B->size[1];
  kidx = K->size[0] * K->size[1];
  K->size[0] = A->size[0];
  K->size[1] = B->size[1];
  emxEnsureCapacity_real_T(sp, K, kidx, &pc_emlrtRTEI);
  K_data = K->data;
  kidx = -1;
  st.site = &n_emlrtRSI;
  overflow = ((1 <= B->size[1]) && (B->size[1] > 2147483646));
  if (overflow) {
    b_st.site = &m_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  if (0 <= B->size[1] - 1) {
    b_overflow = ((1 <= A->size[0]) && (A->size[0] > 2147483646));
  }
  for (j2 = 0; j2 < nb; j2++) {
    st.site = &o_emlrtRSI;
    if (b_overflow) {
      b_st.site = &m_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (i1 = 0; i1 < ma; i1++) {
      K_data[(kidx + i1) + 1] = A_data[i1] * B_data[j2];
    }
    kidx += ma;
  }
}

/* End of code generation (kron.c) */
