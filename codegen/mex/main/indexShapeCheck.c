/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * indexShapeCheck.c
 *
 * Code generation for function 'indexShapeCheck'
 *
 */

/* Include files */
#include "indexShapeCheck.h"
#include "main_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo nh_emlrtRSI = {
    42,                /* lineNo */
    "indexShapeCheck", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\indexShapeCheck.m" /* pathName */
};

static emlrtRTEInfo v_emlrtRTEI = {
    122,           /* lineNo */
    5,             /* colNo */
    "errOrWarnIf", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\indexShapeCheck.m" /* pName */
};

/* Function Definitions */
void b_indexShapeCheck(const emlrtStack *sp, int32_T matrixSize,
                       const int32_T indexSize[2])
{
  emlrtStack st;
  boolean_T c;
  st.prev = sp;
  st.tls = sp->tls;
  if ((matrixSize != 1) || (indexSize[1] == 1)) {
    c = false;
  } else {
    c = true;
  }
  st.site = &nh_emlrtRSI;
  if (c) {
    emlrtErrorWithMessageIdR2018a(&st, &v_emlrtRTEI,
                                  "Coder:FE:PotentialVectorVector",
                                  "Coder:FE:PotentialVectorVector", 0);
  }
}

void indexShapeCheck(const emlrtStack *sp, int32_T matrixSize)
{
  emlrtStack st;
  boolean_T c;
  st.prev = sp;
  st.tls = sp->tls;
  c = (matrixSize == 1);
  st.site = &nh_emlrtRSI;
  if (c) {
    emlrtErrorWithMessageIdR2018a(&st, &v_emlrtRTEI,
                                  "Coder:FE:PotentialVectorVector",
                                  "Coder:FE:PotentialVectorVector", 0);
  }
}

/* End of code generation (indexShapeCheck.c) */
