/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * introsort.c
 *
 * Code generation for function 'introsort'
 *
 */

/* Include files */
#include "introsort.h"
#include "heapsort.h"
#include "insertionsort.h"
#include "main_data.h"
#include "main_types.h"
#include "rt_nonfinite.h"

/* Type Definitions */
#ifndef typedef_struct_T
#define typedef_struct_T
typedef struct {
  int32_T xstart;
  int32_T xend;
  int32_T depth;
} struct_T;
#endif /* typedef_struct_T */

/* Variable Definitions */
static emlrtRSInfo ke_emlrtRSI = {
    34,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo le_emlrtRSI = {
    42,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo ne_emlrtRSI = {
    47,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo oe_emlrtRSI = {
    49,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo pe_emlrtRSI = {
    55,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo qe_emlrtRSI = {
    58,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo re_emlrtRSI = {
    41,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRTEInfo nb_emlrtRTEI = {
    62,           /* lineNo */
    39,           /* colNo */
    "stack/push", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\stack.m" /* pName */
};

static emlrtDCInfo nc_emlrtDCI = {
    48,            /* lineNo */
    48,            /* colNo */
    "stack/stack", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\stack.m", /* pName */
    4                    /* checkKind */
};

/* Function Definitions */
void introsort(const emlrtStack *sp, emxArray_int32_T *x, int32_T xend,
               const emxArray_int32_T *cmp_workspace_a,
               const emxArray_int32_T *cmp_workspace_b)
{
  emlrtStack st;
  struct_T st_d_data[120];
  struct_T frame;
  const int32_T *cmp_workspace_a_data;
  const int32_T *cmp_workspace_b_data;
  int32_T MAXDEPTH;
  int32_T exitg2;
  int32_T exitg3;
  int32_T i;
  int32_T j;
  int32_T pivot;
  int32_T pmax;
  int32_T pmin;
  int32_T pow2p;
  int32_T st_n;
  int32_T unnamed_idx_0;
  int32_T *x_data;
  boolean_T exitg1;
  boolean_T varargout_1;
  st.prev = sp;
  st.tls = sp->tls;
  cmp_workspace_b_data = cmp_workspace_b->data;
  cmp_workspace_a_data = cmp_workspace_a->data;
  x_data = x->data;
  if (1 < xend) {
    if (xend <= 32) {
      st.site = &ke_emlrtRSI;
      insertionsort(&st, x, 1, xend, cmp_workspace_a, cmp_workspace_b);
    } else {
      pmax = 31;
      pmin = 0;
      exitg1 = false;
      while ((!exitg1) && (pmax - pmin > 1)) {
        j = (pmin + pmax) >> 1;
        pow2p = 1 << j;
        if (pow2p == xend) {
          pmax = j;
          exitg1 = true;
        } else if (pow2p > xend) {
          pmax = j;
        } else {
          pmin = j;
        }
      }
      MAXDEPTH = (pmax - 1) << 1;
      frame.xstart = 1;
      frame.xend = xend;
      frame.depth = 0;
      st.site = &re_emlrtRSI;
      unnamed_idx_0 = MAXDEPTH << 1;
      if (unnamed_idx_0 < 0) {
        emlrtNonNegativeCheckR2012b(unnamed_idx_0, &nc_emlrtDCI, &st);
      }
      for (i = 0; i < unnamed_idx_0; i++) {
        st_d_data[i] = frame;
      }
      st.site = &le_emlrtRSI;
      if (0 >= unnamed_idx_0) {
        emlrtErrorWithMessageIdR2018a(&st, &nb_emlrtRTEI,
                                      "Coder:toolbox:StackPushLimit",
                                      "Coder:toolbox:StackPushLimit", 0);
      }
      st_d_data[0] = frame;
      st_n = 1;
      while (st_n > 0) {
        frame = st_d_data[st_n - 1];
        st_n--;
        i = frame.xend - frame.xstart;
        if (i + 1 <= 32) {
          st.site = &ne_emlrtRSI;
          insertionsort(&st, x, frame.xstart, frame.xend, cmp_workspace_a,
                        cmp_workspace_b);
          x_data = x->data;
        } else if (frame.depth == MAXDEPTH) {
          st.site = &oe_emlrtRSI;
          b_heapsort(&st, x, frame.xstart, frame.xend, cmp_workspace_a,
                     cmp_workspace_b);
          x_data = x->data;
        } else {
          pow2p = (frame.xstart + i / 2) - 1;
          i = x_data[frame.xstart - 1];
          pmax = cmp_workspace_a_data[x_data[pow2p] - 1];
          pmin = cmp_workspace_a_data[i - 1];
          if (pmax < pmin) {
            varargout_1 = true;
          } else if (pmax == pmin) {
            varargout_1 = (cmp_workspace_b_data[x_data[pow2p] - 1] <
                           cmp_workspace_b_data[i - 1]);
          } else {
            varargout_1 = false;
          }
          if (varargout_1) {
            x_data[frame.xstart - 1] = x_data[pow2p];
            x_data[pow2p] = i;
          }
          if (cmp_workspace_a_data[x_data[frame.xend - 1] - 1] <
              cmp_workspace_a_data[x_data[frame.xstart - 1] - 1]) {
            varargout_1 = true;
          } else {
            i = x_data[frame.xend - 1] - 1;
            pmax = x_data[frame.xstart - 1] - 1;
            if (cmp_workspace_a_data[i] == cmp_workspace_a_data[pmax]) {
              varargout_1 =
                  (cmp_workspace_b_data[i] < cmp_workspace_b_data[pmax]);
            } else {
              varargout_1 = false;
            }
          }
          if (varargout_1) {
            pmax = x_data[frame.xstart - 1];
            x_data[frame.xstart - 1] = x_data[frame.xend - 1];
            x_data[frame.xend - 1] = pmax;
          }
          if (cmp_workspace_a_data[x_data[frame.xend - 1] - 1] <
              cmp_workspace_a_data[x_data[pow2p] - 1]) {
            varargout_1 = true;
          } else {
            i = x_data[frame.xend - 1] - 1;
            if (cmp_workspace_a_data[i] ==
                cmp_workspace_a_data[x_data[pow2p] - 1]) {
              varargout_1 = (cmp_workspace_b_data[i] <
                             cmp_workspace_b_data[x_data[pow2p] - 1]);
            } else {
              varargout_1 = false;
            }
          }
          if (varargout_1) {
            pmax = x_data[pow2p];
            x_data[pow2p] = x_data[frame.xend - 1];
            x_data[frame.xend - 1] = pmax;
          }
          pivot = x_data[pow2p] - 1;
          x_data[pow2p] = x_data[frame.xend - 2];
          x_data[frame.xend - 2] = pivot + 1;
          pmin = frame.xstart - 1;
          j = frame.xend - 2;
          do {
            exitg2 = 0;
            pmin++;
            do {
              exitg3 = 0;
              i = cmp_workspace_a_data[x_data[pmin] - 1];
              if (i < cmp_workspace_a_data[pivot]) {
                varargout_1 = true;
              } else if (i == cmp_workspace_a_data[pivot]) {
                varargout_1 = (cmp_workspace_b_data[x_data[pmin] - 1] <
                               cmp_workspace_b_data[pivot]);
              } else {
                varargout_1 = false;
              }
              if (varargout_1) {
                pmin++;
              } else {
                exitg3 = 1;
              }
            } while (exitg3 == 0);
            j--;
            do {
              exitg3 = 0;
              i = cmp_workspace_a_data[x_data[j] - 1];
              if (cmp_workspace_a_data[pivot] < i) {
                varargout_1 = true;
              } else if (cmp_workspace_a_data[pivot] == i) {
                varargout_1 = (cmp_workspace_b_data[pivot] <
                               cmp_workspace_b_data[x_data[j] - 1]);
              } else {
                varargout_1 = false;
              }
              if (varargout_1) {
                j--;
              } else {
                exitg3 = 1;
              }
            } while (exitg3 == 0);
            if (pmin + 1 >= j + 1) {
              exitg2 = 1;
            } else {
              pmax = x_data[pmin];
              x_data[pmin] = x_data[j];
              x_data[j] = pmax;
            }
          } while (exitg2 == 0);
          x_data[frame.xend - 2] = x_data[pmin];
          x_data[pmin] = pivot + 1;
          if (pmin + 2 < frame.xend) {
            st.site = &pe_emlrtRSI;
            if (st_n >= unnamed_idx_0) {
              emlrtErrorWithMessageIdR2018a(&st, &nb_emlrtRTEI,
                                            "Coder:toolbox:StackPushLimit",
                                            "Coder:toolbox:StackPushLimit", 0);
            }
            st_d_data[st_n].xstart = pmin + 2;
            st_d_data[st_n].xend = frame.xend;
            st_d_data[st_n].depth = frame.depth + 1;
            st_n++;
          }
          if (frame.xstart < pmin + 1) {
            st.site = &qe_emlrtRSI;
            if (st_n >= unnamed_idx_0) {
              emlrtErrorWithMessageIdR2018a(&st, &nb_emlrtRTEI,
                                            "Coder:toolbox:StackPushLimit",
                                            "Coder:toolbox:StackPushLimit", 0);
            }
            st_d_data[st_n].xstart = frame.xstart;
            st_d_data[st_n].xend = pmin + 1;
            st_d_data[st_n].depth = frame.depth + 1;
            st_n++;
          }
        }
      }
    }
  }
}

/* End of code generation (introsort.c) */
