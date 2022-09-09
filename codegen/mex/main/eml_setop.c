/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_setop.c
 *
 * Code generation for function 'eml_setop'
 *
 */

/* Include files */
#include "eml_setop.h"
#include "issorted.h"
#include "main_data.h"
#include "main_emxutil.h"
#include "main_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <math.h>

/* Variable Definitions */
static emlrtRTEInfo x_emlrtRTEI = {
    216,          /* lineNo */
    13,           /* colNo */
    "do_vectors", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" /* pName */
};

static emlrtRTEInfo y_emlrtRTEI = {
    219,          /* lineNo */
    13,           /* colNo */
    "do_vectors", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" /* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    383,          /* lineNo */
    5,            /* colNo */
    "do_vectors", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" /* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    421,          /* lineNo */
    5,            /* colNo */
    "do_vectors", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" /* pName */
};

static emlrtRTEInfo cf_emlrtRTEI = {
    185,         /* lineNo */
    24,          /* colNo */
    "eml_setop", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" /* pName */
};

static emlrtRTEInfo df_emlrtRTEI = {
    192,         /* lineNo */
    29,          /* colNo */
    "eml_setop", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" /* pName */
};

static emlrtRTEInfo ef_emlrtRTEI = {
    389,         /* lineNo */
    9,           /* colNo */
    "eml_setop", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" /* pName */
};

static emlrtRTEInfo ff_emlrtRTEI = {
    423,         /* lineNo */
    9,           /* colNo */
    "eml_setop", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" /* pName */
};

/* Function Declarations */
static real_T skip_to_last_equal_value(int32_T *k, const emxArray_real_T *x);

/* Function Definitions */
static real_T skip_to_last_equal_value(int32_T *k, const emxArray_real_T *x)
{
  const real_T *x_data;
  real_T absx;
  real_T xk;
  int32_T exponent;
  boolean_T exitg1;
  boolean_T p;
  x_data = x->data;
  xk = x_data[*k - 1];
  exitg1 = false;
  while ((!exitg1) && (*k < x->size[1])) {
    absx = muDoubleScalarAbs(xk / 2.0);
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
    if ((muDoubleScalarAbs(xk - x_data[*k]) < absx) ||
        (muDoubleScalarIsInf(x_data[*k]) && muDoubleScalarIsInf(xk) &&
         ((x_data[*k] > 0.0) == (xk > 0.0)))) {
      p = true;
    } else {
      p = false;
    }
    if (p) {
      (*k)++;
    } else {
      exitg1 = true;
    }
  }
  return xk;
}

void do_vectors(const emlrtStack *sp, const emxArray_real_T *a,
                const emxArray_real_T *b, emxArray_real_T *c,
                emxArray_int32_T *ia, int32_T *ib_size)
{
  real_T absx;
  real_T ak;
  real_T bk;
  real_T *c_data;
  int32_T b_ialast;
  int32_T exponent;
  int32_T iafirst;
  int32_T ialast;
  int32_T iblast;
  int32_T na;
  int32_T nc;
  int32_T nia;
  int32_T *ia_data;
  boolean_T p;
  na = a->size[1];
  iblast = c->size[0] * c->size[1];
  c->size[0] = 1;
  c->size[1] = a->size[1];
  emxEnsureCapacity_real_T(sp, c, iblast, &cf_emlrtRTEI);
  c_data = c->data;
  iblast = ia->size[0];
  ia->size[0] = a->size[1];
  emxEnsureCapacity_int32_T(sp, ia, iblast, &df_emlrtRTEI);
  ia_data = ia->data;
  *ib_size = 0;
  if (!issorted(a)) {
    emlrtErrorWithMessageIdR2018a(sp, &x_emlrtRTEI,
                                  "Coder:toolbox:eml_setop_unsortedA",
                                  "Coder:toolbox:eml_setop_unsortedA", 0);
  }
  if (!issorted(b)) {
    emlrtErrorWithMessageIdR2018a(sp, &y_emlrtRTEI,
                                  "Coder:toolbox:eml_setop_unsortedB",
                                  "Coder:toolbox:eml_setop_unsortedB", 0);
  }
  nc = 0;
  nia = 0;
  iafirst = 0;
  ialast = 1;
  iblast = 1;
  while ((ialast <= na) && (iblast <= b->size[1])) {
    b_ialast = ialast;
    ak = skip_to_last_equal_value(&b_ialast, a);
    ialast = b_ialast;
    bk = skip_to_last_equal_value(&iblast, b);
    absx = muDoubleScalarAbs(bk / 2.0);
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
    if ((muDoubleScalarAbs(bk - ak) < absx) ||
        (muDoubleScalarIsInf(ak) && muDoubleScalarIsInf(bk) &&
         ((ak > 0.0) == (bk > 0.0)))) {
      p = true;
    } else {
      p = false;
    }
    if (p) {
      ialast = b_ialast + 1;
      iafirst = b_ialast;
      iblast++;
    } else {
      if (muDoubleScalarIsNaN(bk)) {
        p = !muDoubleScalarIsNaN(ak);
      } else if (muDoubleScalarIsNaN(ak)) {
        p = false;
      } else {
        p = (ak < bk);
      }
      if (p) {
        nc++;
        nia++;
        c_data[nc - 1] = ak;
        ia_data[nia - 1] = iafirst + 1;
        ialast = b_ialast + 1;
        iafirst = b_ialast;
      } else {
        iblast++;
      }
    }
  }
  while (ialast <= na) {
    iblast = ialast;
    ak = skip_to_last_equal_value(&iblast, a);
    nc++;
    nia++;
    c_data[nc - 1] = ak;
    ia_data[nia - 1] = iafirst + 1;
    ialast = iblast + 1;
    iafirst = iblast;
  }
  if (a->size[1] > 0) {
    if (nia > a->size[1]) {
      emlrtErrorWithMessageIdR2018a(sp, &ab_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (1 > nia) {
      ia->size[0] = 0;
    } else {
      iblast = ia->size[0];
      ia->size[0] = nia;
      emxEnsureCapacity_int32_T(sp, ia, iblast, &ef_emlrtRTEI);
    }
    if (nc > a->size[1]) {
      emlrtErrorWithMessageIdR2018a(sp, &bb_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (1 > nc) {
      c->size[1] = 0;
    } else {
      iblast = c->size[0] * c->size[1];
      c->size[1] = nc;
      emxEnsureCapacity_real_T(sp, c, iblast, &ff_emlrtRTEI);
    }
  }
}

/* End of code generation (eml_setop.c) */
