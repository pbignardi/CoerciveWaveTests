/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sparse1.c
 *
 * Code generation for function 'sparse1'
 *
 */

/* Include files */
#include "sparse1.h"
#include "bigProduct.h"
#include "binOp.h"
#include "eml_int_forloop_overflow_check.h"
#include "fillIn.h"
#include "indexShapeCheck.h"
#include "main_data.h"
#include "main_emxutil.h"
#include "main_mexutil.h"
#include "main_types.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "cs.h"
#include "makeCXSparseMatrix.h"
#include "mwmathutil.h"
#include "solve_from_lu.h"
#include "solve_from_qr.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo fe_emlrtRSI = {
    1639,                  /* lineNo */
    "assertValidIndexArg", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo te_emlrtRSI = {
    1666,            /* lineNo */
    "permuteVector", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo if_emlrtRSI = {
    292,           /* lineNo */
    "sparse/plus", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo jf_emlrtRSI = {
    125,            /* lineNo */
    "sparse/binOp", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" /* pathName */
};

static emlrtRSInfo kf_emlrtRSI = {
    130,            /* lineNo */
    "sparse/binOp", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" /* pathName */
};

static emlrtRSInfo lf_emlrtRSI = {
    133,            /* lineNo */
    "sparse/binOp", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" /* pathName */
};

static emlrtRSInfo mf_emlrtRSI = {
    135,            /* lineNo */
    "sparse/binOp", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" /* pathName */
};

static emlrtRSInfo nf_emlrtRSI = {
    139,            /* lineNo */
    "sparse/binOp", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" /* pathName */
};

static emlrtRSInfo of_emlrtRSI = {
    142,            /* lineNo */
    "sparse/binOp", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" /* pathName */
};

static emlrtRSInfo pf_emlrtRSI = {
    146,            /* lineNo */
    "sparse/binOp", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" /* pathName */
};

static emlrtRSInfo qf_emlrtRSI = {
    149,            /* lineNo */
    "sparse/binOp", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" /* pathName */
};

static emlrtRSInfo si_emlrtRSI = {
    264,                  /* lineNo */
    "sparse/parenAssign", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo ti_emlrtRSI = {
    66,                     /* lineNo */
    "sparse/parenAssign2D", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" /* pathName */
};

static emlrtRSInfo ui_emlrtRSI = {
    77,                     /* lineNo */
    "parenAssign2DNumeric", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" /* pathName */
};

static emlrtRSInfo vi_emlrtRSI = {
    78,                     /* lineNo */
    "parenAssign2DNumeric", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" /* pathName */
};

static emlrtRSInfo wi_emlrtRSI = {
    81,                     /* lineNo */
    "parenAssign2DNumeric", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" /* pathName */
};

static emlrtRSInfo xi_emlrtRSI = {
    87,                         /* lineNo */
    "parenAssign2DNumericImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" /* pathName */
};

static emlrtRSInfo yi_emlrtRSI = {
    110,                        /* lineNo */
    "parenAssign2DNumericImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" /* pathName */
};

static emlrtRSInfo aj_emlrtRSI = {
    115,                        /* lineNo */
    "parenAssign2DNumericImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" /* pathName */
};

static emlrtRSInfo bj_emlrtRSI = {
    119,                        /* lineNo */
    "parenAssign2DNumericImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" /* pathName */
};

static emlrtRSInfo cj_emlrtRSI = {
    123,                        /* lineNo */
    "parenAssign2DNumericImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" /* pathName */
};

static emlrtRSInfo dj_emlrtRSI = {
    124,                        /* lineNo */
    "parenAssign2DNumericImpl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" /* pathName */
};

static emlrtRSInfo ej_emlrtRSI = {
    329,       /* lineNo */
    "realloc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" /* pathName */
};

static emlrtRSInfo fj_emlrtRSI = {
    337,       /* lineNo */
    "realloc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" /* pathName */
};

static emlrtRSInfo gj_emlrtRSI = {
    342,       /* lineNo */
    "realloc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" /* pathName */
};

static emlrtRSInfo hj_emlrtRSI = {
    245,                  /* lineNo */
    "shiftRowidxAndData", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" /* pathName */
};

static emlrtRSInfo ij_emlrtRSI = {
    246,                  /* lineNo */
    "shiftRowidxAndData", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" /* pathName */
};

static emlrtRSInfo jj_emlrtRSI = {
    264,          /* lineNo */
    "incrColIdx", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" /* pathName */
};

static emlrtRSInfo kj_emlrtRSI = {
    271,          /* lineNo */
    "decrColIdx", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" /* pathName */
};

static emlrtRSInfo lj_emlrtRSI = {
    1456,              /* lineNo */
    "sparse/mldivide", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo mj_emlrtRSI =
    {
        158,                         /* lineNo */
        "CXSparseAPI/iteratedSolve", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pathName */
};

static emlrtRSInfo nj_emlrtRSI =
    {
        160,                         /* lineNo */
        "CXSparseAPI/iteratedSolve", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pathName */
};

static emlrtRSInfo oj_emlrtRSI =
    {
        289,                      /* lineNo */
        "CXSparseAPI/iteratedLU", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pathName */
};

static emlrtRSInfo pj_emlrtRSI =
    {
        309,                      /* lineNo */
        "CXSparseAPI/iteratedLU", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pathName */
};

static emlrtRSInfo qj_emlrtRSI =
    {
        312,                      /* lineNo */
        "CXSparseAPI/iteratedLU", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pathName */
};

static emlrtRSInfo rj_emlrtRSI =
    {
        453,                  /* lineNo */
        "CXSparseAPI/makeCX", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pathName */
};

static emlrtRSInfo sj_emlrtRSI =
    {
        455,                  /* lineNo */
        "CXSparseAPI/makeCX", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pathName */
};

static emlrtRSInfo tj_emlrtRSI = {
    395,                 /* lineNo */
    "sparse/ctranspose", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo uj_emlrtRSI = {
    24,                    /* lineNo */
    "sparse/locTranspose", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\locTranspose.m" /* pathName */
};

static emlrtRSInfo vj_emlrtRSI = {
    29,                    /* lineNo */
    "sparse/locTranspose", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\locTranspose.m" /* pathName */
};

static emlrtRSInfo wj_emlrtRSI = {
    33,                    /* lineNo */
    "sparse/locTranspose", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\locTranspose.m" /* pathName */
};

static emlrtRSInfo xj_emlrtRSI = {
    17,                    /* lineNo */
    "sparse/locTranspose", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\locTranspose.m" /* pathName */
};

static emlrtRSInfo yj_emlrtRSI =
    {
        419,                      /* lineNo */
        "CXSparseAPI/iteratedQR", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pathName */
};

static emlrtRSInfo ak_emlrtRSI =
    {
        353,                      /* lineNo */
        "CXSparseAPI/iteratedQR", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pathName */
};

static emlrtRSInfo bk_emlrtRSI =
    {
        375,                      /* lineNo */
        "CXSparseAPI/iteratedQR", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pathName */
};

static emlrtRSInfo ck_emlrtRSI =
    {
        376,                      /* lineNo */
        "CXSparseAPI/iteratedQR", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pathName */
};

static emlrtMCInfo
    h_emlrtMCI =
        {
            53,        /* lineNo */
            19,        /* colNo */
            "flt2str", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\flt2str.m" /* pName */
};

static emlrtRTEInfo n_emlrtRTEI = {
    1641,                  /* lineNo */
    31,                    /* colNo */
    "assertValidIndexArg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = {
    1643,                  /* lineNo */
    31,                    /* colNo */
    "assertValidIndexArg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    1645,                  /* lineNo */
    31,                    /* colNo */
    "assertValidIndexArg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pName */
};

static emlrtRTEInfo t_emlrtRTEI = {
    59,             /* lineNo */
    27,             /* colNo */
    "sparse/binOp", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" /* pName */
};

static emlrtRTEInfo cb_emlrtRTEI =
    {
        137,                         /* lineNo */
        35,                          /* colNo */
        "CXSparseAPI/iteratedSolve", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pName */
};

static emlrtDCInfo yb_emlrtDCI = {
    1456,              /* lineNo */
    13,                /* colNo */
    "sparse/mldivide", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m", /* pName */
    4                   /* checkKind */
};

static emlrtDCInfo ac_emlrtDCI = {
    384,                      /* lineNo */
    44,                       /* colNo */
    "CXSparseAPI/iteratedQR", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI."
    "m", /* pName */
    4    /* checkKind */
};

static emlrtRTEInfo db_emlrtRTEI = {
    178,             /* lineNo */
    39,              /* colNo */
    "sparse/sparse", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pName */
};

static emlrtDCInfo bc_emlrtDCI = {
    395,                 /* lineNo */
    13,                  /* colNo */
    "sparse/ctranspose", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m", /* pName */
    4                   /* checkKind */
};

static emlrtRTEInfo ob_emlrtRTEI = {
    36,                     /* lineNo */
    23,                     /* colNo */
    "sparse/parenAssign2D", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" /* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = {
    11,                                   /* lineNo */
    27,                                   /* colNo */
    "sparse/sparse_validateNumericIndex", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\private\\validateNumericIndex.m" /* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = {
    12,                                   /* lineNo */
    27,                                   /* colNo */
    "sparse/sparse_validateNumericIndex", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\private\\validateNumericIndex.m" /* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = {
    237,            /* lineNo */
    13,             /* colNo */
    "sparse/numel", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pName */
};

static emlrtRTEInfo ge_emlrtRTEI = {
    1636,     /* lineNo */
    27,       /* colNo */
    "sparse", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pName */
};

static emlrtRTEInfo gf_emlrtRTEI = {
    1456,     /* lineNo */
    13,       /* colNo */
    "sparse", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pName */
};

static emlrtRTEInfo hf_emlrtRTEI =
    {
        453,           /* lineNo */
        63,            /* colNo */
        "CXSparseAPI", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pName */
};

static emlrtRTEInfo if_emlrtRTEI =
    {
        384,           /* lineNo */
        38,            /* colNo */
        "CXSparseAPI", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pName */
};

static emlrtRTEInfo jf_emlrtRTEI =
    {
        401,           /* lineNo */
        46,            /* colNo */
        "CXSparseAPI", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pName */
};

static emlrtRTEInfo kf_emlrtRTEI =
    {
        395,           /* lineNo */
        46,            /* colNo */
        "CXSparseAPI", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pName */
};

static emlrtRTEInfo lf_emlrtRTEI =
    {
        390,           /* lineNo */
        25,            /* colNo */
        "CXSparseAPI", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pName */
};

static emlrtRTEInfo mf_emlrtRTEI = {
    395,      /* lineNo */
    13,       /* colNo */
    "sparse", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pName */
};

static emlrtRTEInfo nf_emlrtRTEI = {
    32,             /* lineNo */
    1,              /* colNo */
    "locTranspose", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\locTranspose.m" /* pName */
};

static emlrtRTEInfo wh_emlrtRTEI = {
    1665,     /* lineNo */
    5,        /* colNo */
    "sparse", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pName */
};

static emlrtRTEInfo xh_emlrtRTEI = {
    91,              /* lineNo */
    35,              /* colNo */
    "parenAssign2D", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" /* pName */
};

static emlrtRTEInfo yh_emlrtRTEI = {
    326,             /* lineNo */
    1,               /* colNo */
    "parenAssign2D", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" /* pName */
};

static emlrtRTEInfo ai_emlrtRTEI = {
    264,      /* lineNo */
    17,       /* colNo */
    "sparse", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pName */
};

static emlrtRSInfo
    in_emlrtRSI =
        {
            53,        /* lineNo */
            "flt2str", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\flt2str.m" /* pathName */
};

/* Function Declarations */
static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *m1,
                                const mxArray *m2, emlrtMCInfo *location);

static void c_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *a__output_of_sprintf_,
                               const char_T *identifier, char_T y[14]);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               char_T y[14]);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[14]);

static void sparse_ctranspose(const emlrtStack *sp,
                              const emxArray_real_T *this_d,
                              const emxArray_int32_T *this_colidx,
                              const emxArray_int32_T *this_rowidx,
                              int32_T this_m, int32_T this_n, b_sparse *y);

/* Function Definitions */
static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *m1,
                                const mxArray *m2, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  return emlrtCallMATLABR2012b((emlrtCTX)sp, 1, &m, 2, &pArrays[0],
                               (const char_T *)"sprintf", true, location);
}

static void c_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *a__output_of_sprintf_,
                               const char_T *identifier, char_T y[14])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(a__output_of_sprintf_), &thisId, y);
  emlrtDestroyArray(&a__output_of_sprintf_);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[14])
{
  f_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[14])
{
  static const int32_T dims[2] = {1, 14};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 14);
  emlrtDestroyArray(&src);
}

static void sparse_ctranspose(const emlrtStack *sp,
                              const emxArray_real_T *this_d,
                              const emxArray_int32_T *this_colidx,
                              const emxArray_int32_T *this_rowidx,
                              int32_T this_m, int32_T this_n, b_sparse *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_int32_T *counts;
  const real_T *this_d_data;
  const int32_T *this_colidx_data;
  const int32_T *this_rowidx_data;
  int32_T c;
  int32_T k;
  int32_T numalloc;
  int32_T outridx;
  int32_T *counts_data;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  this_rowidx_data = this_rowidx->data;
  this_colidx_data = this_colidx->data;
  this_d_data = this_d->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &tj_emlrtRSI;
  b_st.site = &xj_emlrtRSI;
  c_st.site = &yd_emlrtRSI;
  if (this_n < 0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &l_emlrtRTEI,
                                  "Coder:toolbox:SparseNegativeSize",
                                  "Coder:toolbox:SparseNegativeSize", 0);
  }
  if (this_n >= MAX_int32_T) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &m_emlrtRTEI, "Coder:toolbox:SparseMaxSize",
        "Coder:toolbox:SparseMaxSize", 2, 12, MAX_int32_T);
  }
  c_st.site = &ae_emlrtRSI;
  if (this_m < 0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &l_emlrtRTEI,
                                  "Coder:toolbox:SparseNegativeSize",
                                  "Coder:toolbox:SparseNegativeSize", 0);
  }
  if (this_m >= MAX_int32_T) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &m_emlrtRTEI, "Coder:toolbox:SparseMaxSize",
        "Coder:toolbox:SparseMaxSize", 2, 12, MAX_int32_T);
  }
  y->m = this_n;
  y->n = this_m;
  c_st.site = &tf_emlrtRSI;
  if (this_colidx_data[this_colidx->size[0] - 1] - 1 < 0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &l_emlrtRTEI,
                                  "Coder:toolbox:SparseNegativeSize",
                                  "Coder:toolbox:SparseNegativeSize", 0);
  }
  if (this_colidx_data[this_colidx->size[0] - 1] - 1 >= MAX_int32_T) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &m_emlrtRTEI, "Coder:toolbox:SparseMaxSize",
        "Coder:toolbox:SparseMaxSize", 2, 12, MAX_int32_T);
  }
  if (0 > this_colidx_data[this_colidx->size[0] - 1] - 1) {
    emlrtErrorWithMessageIdR2018a(&b_st, &db_emlrtRTEI,
                                  "Coder:toolbox:SparseNzmaxTooSmall",
                                  "Coder:toolbox:SparseNzmaxTooSmall", 0);
  }
  if (this_colidx_data[this_colidx->size[0] - 1] - 1 >= 1) {
    numalloc = this_colidx_data[this_colidx->size[0] - 1] - 1;
  } else {
    numalloc = 1;
  }
  if (numalloc < 0) {
    emlrtNonNegativeCheckR2012b(numalloc, &bc_emlrtDCI, &b_st);
  }
  outridx = y->d->size[0];
  y->d->size[0] = numalloc;
  emxEnsureCapacity_real_T(&b_st, y->d, outridx, &mf_emlrtRTEI);
  for (outridx = 0; outridx < numalloc; outridx++) {
    y->d->data[outridx] = 0.0;
  }
  y->maxnz = numalloc;
  outridx = y->colidx->size[0];
  y->colidx->size[0] = this_m + 1;
  emxEnsureCapacity_int32_T(&b_st, y->colidx, outridx, &ce_emlrtRTEI);
  y->colidx->data[0] = 1;
  outridx = y->rowidx->size[0];
  y->rowidx->size[0] = numalloc;
  emxEnsureCapacity_int32_T(&b_st, y->rowidx, outridx, &mf_emlrtRTEI);
  for (outridx = 0; outridx < numalloc; outridx++) {
    y->rowidx->data[outridx] = 0;
  }
  for (c = 0; c < this_m; c++) {
    y->colidx->data[c + 1] = 1;
  }
  c_st.site = &ee_emlrtRSI;
  sparse_fillIn(&c_st, y);
  emxInit_int32_T(&st, &counts, 1, &nf_emlrtRTEI);
  if ((this_m != 0) && (this_n != 0)) {
    numalloc = y->colidx->size[0];
    for (outridx = 0; outridx < numalloc; outridx++) {
      y->colidx->data[outridx] = 0;
    }
    numalloc = this_colidx_data[this_colidx->size[0] - 1];
    b_st.site = &uj_emlrtRSI;
    overflow = ((1 <= this_colidx_data[this_colidx->size[0] - 1] - 1) &&
                (this_colidx_data[this_colidx->size[0] - 1] - 1 > 2147483646));
    if (overflow) {
      c_st.site = &m_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (k = 0; k <= numalloc - 2; k++) {
      y->colidx->data[this_rowidx_data[k]]++;
    }
    y->colidx->data[0] = 1;
    numalloc = this_m + 1;
    b_st.site = &vj_emlrtRSI;
    if (this_m + 1 > 2147483646) {
      c_st.site = &m_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (k = 2; k <= numalloc; k++) {
      y->colidx->data[k - 1] += y->colidx->data[k - 2];
    }
    outridx = counts->size[0];
    counts->size[0] = this_m;
    emxEnsureCapacity_int32_T(&st, counts, outridx, &nf_emlrtRTEI);
    counts_data = counts->data;
    for (outridx = 0; outridx < this_m; outridx++) {
      counts_data[outridx] = 0;
    }
    b_st.site = &wj_emlrtRSI;
    for (c = 0; c < this_n; c++) {
      for (numalloc = this_colidx_data[c] - 1;
           numalloc + 1 < this_colidx_data[c + 1]; numalloc++) {
        k = counts_data[this_rowidx_data[numalloc] - 1];
        outridx = (k + y->colidx->data[this_rowidx_data[numalloc] - 1]) - 1;
        y->d->data[outridx] = this_d_data[numalloc];
        y->rowidx->data[outridx] = c + 1;
        counts_data[this_rowidx_data[numalloc] - 1] = k + 1;
      }
    }
  }
  emxFree_int32_T(&st, &counts);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void assertValidIndexArg(const emlrtStack *sp, const emxArray_real_T *s,
                         emxArray_int32_T *sint)
{
  emlrtStack b_st;
  emlrtStack st;
  const real_T *s_data;
  int32_T k;
  int32_T ns;
  int32_T *sint_data;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  s_data = s->data;
  ns = s->size[1] << 8;
  k = sint->size[0];
  sint->size[0] = ns;
  emxEnsureCapacity_int32_T(sp, sint, k, &ge_emlrtRTEI);
  sint_data = sint->data;
  st.site = &fe_emlrtRSI;
  overflow = ((1 <= ns) && (ns > 2147483646));
  if (overflow) {
    b_st.site = &m_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (k = 0; k < ns; k++) {
    if (!(muDoubleScalarFloor(s_data[k]) == s_data[k])) {
      emlrtErrorWithMessageIdR2018a(sp, &n_emlrtRTEI,
                                    "MATLAB:sparsfcn:nonIntegerIndex",
                                    "MATLAB:sparsfcn:nonIntegerIndex", 0);
    }
    if (!(s_data[k] < 2.147483647E+9)) {
      emlrtErrorWithMessageIdR2018a(sp, &o_emlrtRTEI,
                                    "MATLAB:sparsfcn:largeIndex",
                                    "MATLAB:sparsfcn:largeIndex", 0);
    }
    if (!(0.0 < s_data[k])) {
      emlrtErrorWithMessageIdR2018a(sp, &p_emlrtRTEI,
                                    "MATLAB:sparsfcn:nonPosIndex",
                                    "MATLAB:sparsfcn:nonPosIndex", 0);
    }
    sint_data[k] = (int32_T)s_data[k];
  }
}

void permuteVector(const emlrtStack *sp, const emxArray_int32_T *idx,
                   emxArray_int32_T *y)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_int32_T *t;
  const int32_T *idx_data;
  int32_T i;
  int32_T loop_ub;
  int32_T ny;
  int32_T *t_data;
  int32_T *y_data;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  y_data = y->data;
  idx_data = idx->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_int32_T(sp, &t, 1, &wh_emlrtRTEI);
  ny = y->size[0];
  i = t->size[0];
  t->size[0] = y->size[0];
  emxEnsureCapacity_int32_T(sp, t, i, &wh_emlrtRTEI);
  t_data = t->data;
  loop_ub = y->size[0];
  for (i = 0; i < loop_ub; i++) {
    t_data[i] = y_data[i];
  }
  st.site = &te_emlrtRSI;
  overflow = ((1 <= y->size[0]) && (y->size[0] > 2147483646));
  if (overflow) {
    b_st.site = &m_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (loop_ub = 0; loop_ub < ny; loop_ub++) {
    y_data[loop_ub] = t_data[idx_data[loop_ub] - 1];
  }
  emxFree_int32_T(sp, &t);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void sparse_mldivide(const emlrtStack *sp, const emxArray_real_T *A_d,
                     const emxArray_int32_T *A_colidx,
                     const emxArray_int32_T *A_rowidx, int32_T A_m, int32_T A_n,
                     const emxArray_real_T *b, emxArray_real_T *y)
{
  static const int32_T b_iv[2] = {1, 6};
  static const char_T rfmt[6] = {'%', '1', '4', '.', '6', 'e'};
  cs_di *b_cxA;
  cs_di *c_cxA;
  cs_di *cxA;
  cs_din *N;
  cs_din *b_N;
  cs_din *c_N;
  cs_dis *S;
  cs_dis *b_S;
  cs_dis *c_S;
  b_sparse b_expl_temp;
  b_sparse expl_temp;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_real_T *outBuff;
  const mxArray *b_y;
  const mxArray *m;
  const real_T *A_d_data;
  const real_T *b_data;
  real_T tol;
  real_T *outBuff_data;
  real_T *y_data;
  int32_T c_y[2];
  const int32_T *A_colidx_data;
  const int32_T *A_rowidx_data;
  int32_T minval;
  int32_T rank;
  char_T str[14];
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
  b_data = b->data;
  A_rowidx_data = A_rowidx->data;
  A_colidx_data = A_colidx->data;
  A_d_data = A_d->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &lj_emlrtRSI;
  emxInit_real_T(&st, &outBuff, 1, &lf_emlrtRTEI);
  emxInitStruct_sparse(&st, &expl_temp, &hf_emlrtRTEI);
  emxInitStruct_sparse(&st, &b_expl_temp, &hf_emlrtRTEI);
  if ((A_m == 0) || (A_n == 0) || (b->size[0] == 0)) {
    if (A_n < 0) {
      emlrtNonNegativeCheckR2012b(A_n, &yb_emlrtDCI, &st);
    }
    minval = y->size[0];
    y->size[0] = A_n;
    emxEnsureCapacity_real_T(&st, y, minval, &gf_emlrtRTEI);
    y_data = y->data;
    for (minval = 0; minval < A_n; minval++) {
      y_data[minval] = 0.0;
    }
  } else {
    if (A_m != b->size[0]) {
      emlrtErrorWithMessageIdR2018a(&st, &cb_emlrtRTEI, "MATLAB:dimagree",
                                    "MATLAB:dimagree", 0);
    }
    if (b->size[0] == A_n) {
      b_st.site = &mj_emlrtRSI;
      c_st.site = &oj_emlrtRSI;
      if (A_m < A_n) {
        d_st.site = &rj_emlrtRSI;
        e_st.site = &rj_emlrtRSI;
        sparse_ctranspose(&e_st, A_d, A_colidx, A_rowidx, A_m, A_n,
                          &b_expl_temp);
        minval = expl_temp.d->size[0];
        expl_temp.d->size[0] = b_expl_temp.d->size[0];
        emxEnsureCapacity_real_T(&d_st, expl_temp.d, minval, &hf_emlrtRTEI);
        rank = b_expl_temp.d->size[0];
        for (minval = 0; minval < rank; minval++) {
          expl_temp.d->data[minval] = b_expl_temp.d->data[minval];
        }
        minval = expl_temp.colidx->size[0];
        expl_temp.colidx->size[0] = b_expl_temp.colidx->size[0];
        emxEnsureCapacity_int32_T(&d_st, expl_temp.colidx, minval,
                                  &hf_emlrtRTEI);
        rank = b_expl_temp.colidx->size[0];
        for (minval = 0; minval < rank; minval++) {
          expl_temp.colidx->data[minval] = b_expl_temp.colidx->data[minval];
        }
        minval = expl_temp.rowidx->size[0];
        expl_temp.rowidx->size[0] = b_expl_temp.rowidx->size[0];
        emxEnsureCapacity_int32_T(&d_st, expl_temp.rowidx, minval,
                                  &hf_emlrtRTEI);
        rank = b_expl_temp.rowidx->size[0];
        for (minval = 0; minval < rank; minval++) {
          expl_temp.rowidx->data[minval] = b_expl_temp.rowidx->data[minval];
        }
        b_cxA = makeCXSparseMatrix(
            expl_temp.colidx->data[expl_temp.colidx->size[0] - 1] - 1,
            b_expl_temp.n, b_expl_temp.m, &expl_temp.colidx->data[0],
            &expl_temp.rowidx->data[0], &expl_temp.d->data[0]);
      } else {
        d_st.site = &sj_emlrtRSI;
        b_cxA = makeCXSparseMatrix(A_colidx_data[A_colidx->size[0] - 1] - 1,
                                   A_n, A_m, &A_colidx_data[0],
                                   &A_rowidx_data[0], &A_d_data[0]);
      }
      b_S = cs_di_sqr(2, b_cxA, 0);
      b_N = cs_di_lu(b_cxA, b_S, 1);
      cs_di_spfree(b_cxA);
      if (b_N == NULL) {
        c_st.site = &pj_emlrtRSI;
        warning(&c_st);
        cs_di_sfree(b_S);
        cs_di_nfree(b_N);
        c_st.site = &qj_emlrtRSI;
        d_st.site = &ak_emlrtRSI;
        if (A_m < A_n) {
          e_st.site = &rj_emlrtRSI;
          f_st.site = &rj_emlrtRSI;
          sparse_ctranspose(&f_st, A_d, A_colidx, A_rowidx, A_m, A_n,
                            &b_expl_temp);
          minval = expl_temp.d->size[0];
          expl_temp.d->size[0] = b_expl_temp.d->size[0];
          emxEnsureCapacity_real_T(&e_st, expl_temp.d, minval, &hf_emlrtRTEI);
          rank = b_expl_temp.d->size[0];
          for (minval = 0; minval < rank; minval++) {
            expl_temp.d->data[minval] = b_expl_temp.d->data[minval];
          }
          minval = expl_temp.colidx->size[0];
          expl_temp.colidx->size[0] = b_expl_temp.colidx->size[0];
          emxEnsureCapacity_int32_T(&e_st, expl_temp.colidx, minval,
                                    &hf_emlrtRTEI);
          rank = b_expl_temp.colidx->size[0];
          for (minval = 0; minval < rank; minval++) {
            expl_temp.colidx->data[minval] = b_expl_temp.colidx->data[minval];
          }
          minval = expl_temp.rowidx->size[0];
          expl_temp.rowidx->size[0] = b_expl_temp.rowidx->size[0];
          emxEnsureCapacity_int32_T(&e_st, expl_temp.rowidx, minval,
                                    &hf_emlrtRTEI);
          rank = b_expl_temp.rowidx->size[0];
          for (minval = 0; minval < rank; minval++) {
            expl_temp.rowidx->data[minval] = b_expl_temp.rowidx->data[minval];
          }
          c_cxA = makeCXSparseMatrix(
              expl_temp.colidx->data[expl_temp.colidx->size[0] - 1] - 1,
              b_expl_temp.n, b_expl_temp.m, &expl_temp.colidx->data[0],
              &expl_temp.rowidx->data[0], &expl_temp.d->data[0]);
        } else {
          e_st.site = &sj_emlrtRSI;
          c_cxA = makeCXSparseMatrix(A_colidx_data[A_colidx->size[0] - 1] - 1,
                                     A_n, A_m, &A_colidx_data[0],
                                     &A_rowidx_data[0], &A_d_data[0]);
        }
        c_S = cs_di_sqr(2, c_cxA, 1);
        c_N = cs_di_qr(c_cxA, c_S);
        cs_di_spfree(c_cxA);
        qr_rank_di(c_N, &tol);
        minval = y->size[0];
        y->size[0] = A_n;
        emxEnsureCapacity_real_T(&c_st, y, minval, &if_emlrtRTEI);
        y_data = y->data;
        if (b->size[0] < A_n) {
          minval = outBuff->size[0];
          outBuff->size[0] = A_n;
          emxEnsureCapacity_real_T(&c_st, outBuff, minval, &kf_emlrtRTEI);
          outBuff_data = outBuff->data;
        } else {
          minval = outBuff->size[0];
          outBuff->size[0] = b->size[0];
          emxEnsureCapacity_real_T(&c_st, outBuff, minval, &jf_emlrtRTEI);
          outBuff_data = outBuff->data;
        }
        rank = b->size[0];
        for (minval = 0; minval < rank; minval++) {
          outBuff_data[minval] = b_data[minval];
        }
        solve_from_qr_di(c_N, c_S, (double *)&outBuff_data[0], b->size[0], A_n);
        c_y[0] = 1;
        c_y[1] = A_n;
        d_st.site = &yj_emlrtRSI;
        b_indexShapeCheck(&d_st, outBuff->size[0], c_y);
        for (minval = 0; minval < A_n; minval++) {
          y_data[minval] = outBuff_data[minval];
        }
        cs_di_sfree(c_S);
        cs_di_nfree(c_N);
      } else {
        minval = y->size[0];
        y->size[0] = b->size[0];
        emxEnsureCapacity_real_T(&b_st, y, minval, &gf_emlrtRTEI);
        y_data = y->data;
        rank = b->size[0];
        for (minval = 0; minval < rank; minval++) {
          y_data[minval] = b_data[minval];
        }
        solve_from_lu_di(b_N, b_S, (double *)&y_data[0], b->size[0]);
        cs_di_sfree(b_S);
        cs_di_nfree(b_N);
      }
    } else {
      b_st.site = &nj_emlrtRSI;
      c_st.site = &ak_emlrtRSI;
      if (A_m < A_n) {
        d_st.site = &rj_emlrtRSI;
        e_st.site = &rj_emlrtRSI;
        sparse_ctranspose(&e_st, A_d, A_colidx, A_rowidx, A_m, A_n, &expl_temp);
        cxA = makeCXSparseMatrix(
            expl_temp.colidx->data[expl_temp.colidx->size[0] - 1] - 1,
            expl_temp.n, expl_temp.m, &expl_temp.colidx->data[0],
            &expl_temp.rowidx->data[0], &expl_temp.d->data[0]);
      } else {
        d_st.site = &sj_emlrtRSI;
        cxA = makeCXSparseMatrix(A_colidx_data[A_colidx->size[0] - 1] - 1, A_n,
                                 A_m, &A_colidx_data[0], &A_rowidx_data[0],
                                 &A_d_data[0]);
      }
      S = cs_di_sqr(2, cxA, 1);
      N = cs_di_qr(cxA, S);
      cs_di_spfree(cxA);
      rank = qr_rank_di(N, &tol);
      if (A_m > A_n) {
        minval = A_n;
      } else {
        minval = A_m;
      }
      if (rank < minval) {
        c_st.site = &ck_emlrtRSI;
        b_y = NULL;
        m = emlrtCreateCharArray(2, &b_iv[0]);
        emlrtInitCharArrayR2013a(&c_st, 6, m, &rfmt[0]);
        emlrtAssign(&b_y, m);
        d_st.site = &in_emlrtRSI;
        c_emlrt_marshallIn(
            &d_st, b_sprintf(&d_st, b_y, d_emlrt_marshallOut(tol), &h_emlrtMCI),
            "<output of sprintf>", str);
        c_st.site = &bk_emlrtRSI;
        b_warning(&c_st, rank, str);
      }
      if (A_n < 0) {
        emlrtNonNegativeCheckR2012b(A_n, &ac_emlrtDCI, &b_st);
      }
      minval = y->size[0];
      y->size[0] = A_n;
      emxEnsureCapacity_real_T(&b_st, y, minval, &if_emlrtRTEI);
      y_data = y->data;
      if (b->size[0] < A_n) {
        minval = outBuff->size[0];
        outBuff->size[0] = A_n;
        emxEnsureCapacity_real_T(&b_st, outBuff, minval, &kf_emlrtRTEI);
        outBuff_data = outBuff->data;
      } else {
        minval = outBuff->size[0];
        outBuff->size[0] = b->size[0];
        emxEnsureCapacity_real_T(&b_st, outBuff, minval, &jf_emlrtRTEI);
        outBuff_data = outBuff->data;
      }
      rank = b->size[0];
      for (minval = 0; minval < rank; minval++) {
        outBuff_data[minval] = b_data[minval];
      }
      solve_from_qr_di(N, S, (double *)&outBuff_data[0], b->size[0], A_n);
      if (1 > A_n) {
        rank = 0;
      } else {
        rank = A_n;
      }
      c_y[0] = 1;
      c_y[1] = rank;
      c_st.site = &yj_emlrtRSI;
      b_indexShapeCheck(&c_st, outBuff->size[0], c_y);
      for (minval = 0; minval < rank; minval++) {
        y_data[minval] = outBuff_data[minval];
      }
      cs_di_sfree(S);
      cs_di_nfree(N);
    }
  }
  emxFreeStruct_sparse(&st, &b_expl_temp);
  emxFreeStruct_sparse(&st, &expl_temp);
  emxFree_real_T(&st, &outBuff);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void sparse_parenAssign(const emlrtStack *sp, b_sparse *this,
                        const emxArray_real_T *rhs, real_T varargin_1,
                        const emxArray_real_T *varargin_2)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_int32_T *x_tmp;
  emxArray_real_T *dt;
  const real_T *rhs_data;
  const real_T *varargin_2_data;
  real_T nt;
  real_T rhsv;
  real_T thisv;
  real_T *dt_data;
  int32_T cidx;
  int32_T high_i;
  int32_T i;
  int32_T idx;
  int32_T k;
  int32_T low_i;
  int32_T low_ip1;
  int32_T mid_i;
  int32_T nz;
  int32_T sn;
  int32_T *x_tmp_data;
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
  varargin_2_data = varargin_2->data;
  rhs_data = rhs->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &si_emlrtRSI;
  if (((rhs->size[1] & 65535) + ((rhs->size[1] >> 16) << 16) !=
       varargin_2->size[1]) &&
      (varargin_2->size[1] != rhs->size[1])) {
    emlrtErrorWithMessageIdR2018a(&st, &ob_emlrtRTEI,
                                  "MATLAB:subsassigndimmismatch",
                                  "MATLAB:subsassigndimmismatch", 0);
  }
  b_st.site = &ti_emlrtRSI;
  c_st.site = &ui_emlrtRSI;
  if ((!(muDoubleScalarFloor(varargin_1) == varargin_1)) ||
      muDoubleScalarIsInf(varargin_1) || (!(varargin_1 > 0.0))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &pb_emlrtRTEI,
                                  "Coder:MATLAB:badsubscript",
                                  "Coder:MATLAB:badsubscript", 0);
  }
  if (!(varargin_1 <= this->m)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &qb_emlrtRTEI,
                                  "Coder:builtins:IndexOutOfBounds",
                                  "Coder:builtins:IndexOutOfBounds", 6, 6,
                                  varargin_1, 12, 1, 12, this->m);
  }
  c_st.site = &vi_emlrtRSI;
  high_i = this->n;
  i = varargin_2->size[1];
  for (k = 0; k < i; k++) {
    thisv = varargin_2_data[k];
    if ((!(muDoubleScalarFloor(thisv) == thisv)) ||
        muDoubleScalarIsInf(thisv)) {
      emlrtErrorWithMessageIdR2018a(&c_st, &pb_emlrtRTEI,
                                    "Coder:MATLAB:badsubscript",
                                    "Coder:MATLAB:badsubscript", 0);
    }
    if (!(thisv <= high_i)) {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &qb_emlrtRTEI, "Coder:builtins:IndexOutOfBounds",
          "Coder:builtins:IndexOutOfBounds", 6, 6, thisv, 12, 1, 12, high_i);
    }
  }
  sn = varargin_2->size[1];
  c_st.site = &wi_emlrtRSI;
  d_st.site = &xi_emlrtRSI;
  overflow = ((1 <= varargin_2->size[1]) && (varargin_2->size[1] > 2147483646));
  if (overflow) {
    e_st.site = &m_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  emxInit_real_T(&c_st, &dt, 1, &yh_emlrtRTEI);
  emxInit_int32_T(&c_st, &x_tmp, 1, &xh_emlrtRTEI);
  for (cidx = 0; cidx < sn; cidx++) {
    nt = varargin_2_data[cidx];
    i = x_tmp->size[0];
    x_tmp->size[0] = this->rowidx->size[0];
    emxEnsureCapacity_int32_T(&c_st, x_tmp, i, &xh_emlrtRTEI);
    x_tmp_data = x_tmp->data;
    high_i = this->rowidx->size[0];
    for (i = 0; i < high_i; i++) {
      x_tmp_data[i] = this->rowidx->data[i];
    }
    thisv = varargin_2_data[cidx];
    low_i = this->colidx->data[(int32_T)thisv - 1];
    high_i = this->colidx->data[(int32_T)thisv];
    if (low_i < high_i) {
      i = (int32_T)varargin_1;
      if (i < this->rowidx->data[low_i - 1]) {
        low_i--;
        overflow = false;
      } else {
        low_ip1 = this->colidx->data[(int32_T)thisv - 1];
        while (high_i > low_ip1 + 1) {
          mid_i = (low_i >> 1) + (high_i >> 1);
          if (((low_i & 1) == 1) && ((high_i & 1) == 1)) {
            mid_i++;
          }
          if (i >= this->rowidx->data[mid_i - 1]) {
            low_i = mid_i;
            low_ip1 = mid_i;
          } else {
            high_i = mid_i;
          }
        }
        overflow = (this->rowidx->data[low_i - 1] == i);
      }
    } else if (low_i == high_i) {
      low_i = this->colidx->data[(int32_T)thisv - 1] - 1;
      overflow = false;
    } else {
      low_i = 0;
      overflow = false;
    }
    if (overflow) {
      thisv = this->d->data[low_i - 1];
    } else {
      thisv = 0.0;
    }
    rhsv = rhs_data[cidx];
    if ((!(thisv == 0.0)) || (!(rhsv == 0.0))) {
      mid_i = this->colidx->data[this->colidx->size[0] - 1] - 1;
      nz = this->colidx->data[this->colidx->size[0] - 1] - 1;
      if ((thisv != 0.0) && (rhsv != 0.0)) {
        this->d->data[low_i - 1] = rhsv;
      } else if (thisv == 0.0) {
        idx = low_i + 1;
        if (this->colidx->data[this->colidx->size[0] - 1] - 1 == this->maxnz) {
          d_st.site = &yi_emlrtRSI;
          i = dt->size[0];
          dt->size[0] = this->d->size[0];
          emxEnsureCapacity_real_T(&d_st, dt, i, &yh_emlrtRTEI);
          dt_data = dt->data;
          high_i = this->d->size[0];
          for (i = 0; i < high_i; i++) {
            dt_data[i] = this->d->data[i];
          }
          bigProduct(this->m, this->n, &high_i, &low_ip1);
          if (low_ip1 == 0) {
            e_st.site = &ej_emlrtRSI;
            bigProduct(this->m, this->n, &high_i, &low_ip1);
            if (low_ip1 != 0) {
              emlrtErrorWithMessageIdR2018a(
                  &e_st, &rb_emlrtRTEI, "Coder:toolbox:SparseNumelTooBig",
                  "Coder:toolbox:SparseNumelTooBig", 0);
            }
            high_i = this->m * this->n;
            if (this->colidx->data[this->colidx->size[0] - 1] + 9 <= high_i) {
              high_i = this->colidx->data[this->colidx->size[0] - 1] + 9;
            }
            if (1 >= high_i) {
              high_i = 1;
            }
          } else if (1 >= this->colidx->data[this->colidx->size[0] - 1] + 9) {
            high_i = 1;
          } else {
            high_i = this->colidx->data[this->colidx->size[0] - 1] + 9;
          }
          i = this->rowidx->size[0];
          this->rowidx->size[0] = high_i;
          emxEnsureCapacity_int32_T(&d_st, this->rowidx, i, &ai_emlrtRTEI);
          for (i = 0; i < high_i; i++) {
            this->rowidx->data[i] = 0;
          }
          i = this->d->size[0];
          this->d->size[0] = high_i;
          emxEnsureCapacity_real_T(&d_st, this->d, i, &ai_emlrtRTEI);
          for (i = 0; i < high_i; i++) {
            this->d->data[i] = 0.0;
          }
          this->maxnz = high_i;
          e_st.site = &fj_emlrtRSI;
          overflow = ((1 <= low_i) && (low_i > 2147483646));
          if (overflow) {
            f_st.site = &m_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }
          for (k = 0; k < low_i; k++) {
            this->rowidx->data[k] = x_tmp_data[k];
            this->d->data[k] = dt_data[k];
          }
          e_st.site = &gj_emlrtRSI;
          overflow = ((low_i + 1 <= mid_i) && (mid_i > 2147483646));
          if (overflow) {
            f_st.site = &m_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }
          for (k = idx; k <= nz; k++) {
            this->rowidx->data[k] = x_tmp_data[k - 1];
            this->d->data[k] = dt_data[k - 1];
          }
          this->rowidx->data[low_i] = (int32_T)varargin_1;
          this->d->data[low_i] = rhsv;
        } else {
          d_st.site = &aj_emlrtRSI;
          high_i = (this->colidx->data[this->colidx->size[0] - 1] - low_i) - 1;
          if (high_i > 0) {
            e_st.site = &hj_emlrtRSI;
            memmove((void *)&this->rowidx->data[low_i + 1],
                    (void *)&this->rowidx->data[low_i],
                    (uint32_T)((size_t)high_i * sizeof(int32_T)));
            e_st.site = &ij_emlrtRSI;
            memmove((void *)&this->d->data[low_i + 1],
                    (void *)&this->d->data[low_i],
                    (uint32_T)((size_t)high_i * sizeof(real_T)));
          }
          this->d->data[low_i] = rhsv;
          this->rowidx->data[low_i] = (int32_T)varargin_1;
        }
        d_st.site = &bj_emlrtRSI;
        high_i = (int32_T)nt + 1;
        low_ip1 = this->n + 1;
        e_st.site = &jj_emlrtRSI;
        overflow = (((int32_T)varargin_2_data[cidx] + 1 <= low_ip1) &&
                    (low_ip1 > 2147483646));
        if (overflow) {
          f_st.site = &m_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }
        for (k = high_i; k <= low_ip1; k++) {
          this->colidx->data[k - 1]++;
        }
      } else {
        d_st.site = &cj_emlrtRSI;
        high_i = (this->colidx->data[this->colidx->size[0] - 1] - low_i) - 1;
        if (high_i > 0) {
          e_st.site = &hj_emlrtRSI;
          memmove((void *)&this->rowidx->data[low_i - 1],
                  (void *)&this->rowidx->data[low_i],
                  (uint32_T)((size_t)high_i * sizeof(int32_T)));
          e_st.site = &ij_emlrtRSI;
          memmove((void *)&this->d->data[low_i - 1],
                  (void *)&this->d->data[low_i],
                  (uint32_T)((size_t)high_i * sizeof(real_T)));
        }
        d_st.site = &dj_emlrtRSI;
        high_i = (int32_T)nt + 1;
        low_ip1 = this->n + 1;
        e_st.site = &kj_emlrtRSI;
        overflow = (((int32_T)varargin_2_data[cidx] + 1 <= low_ip1) &&
                    (low_ip1 > 2147483646));
        if (overflow) {
          f_st.site = &m_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }
        for (k = high_i; k <= low_ip1; k++) {
          this->colidx->data[k - 1]--;
        }
      }
    }
  }
  emxFree_int32_T(&c_st, &x_tmp);
  emxFree_real_T(&c_st, &dt);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void sparse_plus(const emlrtStack *sp, const emxArray_real_T *a_d,
                 const emxArray_int32_T *a_colidx,
                 const emxArray_int32_T *a_rowidx, int32_T a_m, int32_T a_n,
                 const emxArray_real_T *b_d, const emxArray_int32_T *b_colidx,
                 const emxArray_int32_T *b_rowidx, int32_T b_m, int32_T b_n,
                 b_sparse *s)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
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
  int32_T n;
  boolean_T x[2];
  boolean_T exitg1;
  boolean_T moreBToDo;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_rowidx_data = b_rowidx->data;
  b_colidx_data = b_colidx->data;
  b_d_data = b_d->data;
  a_rowidx_data = a_rowidx->data;
  a_colidx_data = a_colidx->data;
  a_d_data = a_d->data;
  st.site = &if_emlrtRSI;
  if (((a_m != 1) && (b_m != 1) && (a_m != b_m)) ||
      ((a_n != 1) && (b_n != 1) && (a_n != b_n))) {
    emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI, "MATLAB:dimagree",
                                  "MATLAB:dimagree", 0);
  }
  if (a_m >= b_m) {
    didx = a_m;
  } else {
    didx = b_m;
  }
  if (a_n >= b_n) {
    n = a_n;
  } else {
    n = b_n;
  }
  b_st.site = &jf_emlrtRSI;
  allocEqsizeBinop(&b_st, a_colidx, a_m, a_n, b_colidx, b_m, b_n, n, didx, s->d,
                   s->colidx, s->rowidx, &s->m, &s->n, &s->maxnz);
  x[0] = (a_m == b_m);
  x[1] = (a_n == b_n);
  overflow = true;
  didx = 0;
  exitg1 = false;
  while ((!exitg1) && (didx < 2)) {
    if (!x[didx]) {
      overflow = false;
      exitg1 = true;
    } else {
      didx++;
    }
  }
  if (overflow) {
    b_st.site = &kf_emlrtRSI;
    sparseSparseEqHeightBinOp(&b_st, a_d, a_colidx, a_rowidx, b_d, b_colidx,
                              b_rowidx, s);
  } else if (a_n == 1) {
    if (b_m == 1) {
      b_st.site = &lf_emlrtRSI;
      b_sparseSparseRowExpandBinOp(&b_st, b_d, b_colidx, a_d, a_colidx,
                                   a_rowidx, s);
    } else {
      b_st.site = &mf_emlrtRSI;
      didx = 1;
      s->colidx->data[0] = 1;
      n = s->n;
      c_st.site = &uf_emlrtRSI;
      overflow = ((1 <= s->n) && (s->n > 2147483646));
      if (overflow) {
        d_st.site = &m_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (c = 0; c < n; c++) {
        aidx = a_colidx_data[0] - 1;
        bidx_tmp = b_colidx_data[c];
        bidx = bidx_tmp - 1;
        overflow = (a_colidx_data[0] < a_colidx_data[1]);
        moreBToDo = (bidx_tmp < b_colidx_data[c + 1]);
        while (overflow || moreBToDo) {
          while (
              (aidx + 1 < a_colidx_data[1]) &&
              ((!moreBToDo) || (a_rowidx_data[aidx] < b_rowidx_data[bidx]))) {
            if (a_d_data[aidx] != 0.0) {
              s->d->data[didx - 1] = a_d_data[aidx];
              s->rowidx->data[didx - 1] = a_rowidx_data[aidx];
              didx++;
            }
            aidx++;
          }
          overflow = (aidx + 1 < a_colidx_data[1]);
          while ((bidx + 1 < b_colidx_data[c + 1]) &&
                 ((!overflow) || (b_rowidx_data[bidx] < a_rowidx_data[aidx]))) {
            if (b_d_data[bidx] != 0.0) {
              s->d->data[didx - 1] = b_d_data[bidx];
              s->rowidx->data[didx - 1] = b_rowidx_data[bidx];
              didx++;
            }
            bidx++;
          }
          while ((aidx + 1 < a_colidx_data[1]) &&
                 (bidx + 1 < b_colidx_data[c + 1]) &&
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
          overflow = (aidx + 1 < a_colidx_data[1]);
          moreBToDo = (bidx + 1 < b_colidx_data[c + 1]);
        }
        s->colidx->data[c + 1] = didx;
      }
    }
  } else if (b_n == 1) {
    if (a_m == 1) {
      b_st.site = &nf_emlrtRSI;
      sparseSparseRowExpandBinOp(&b_st, a_d, a_colidx, b_d, b_colidx, b_rowidx,
                                 s, true);
    } else {
      b_st.site = &of_emlrtRSI;
      didx = 1;
      s->colidx->data[0] = 1;
      n = s->n;
      c_st.site = &uf_emlrtRSI;
      overflow = ((1 <= s->n) && (s->n > 2147483646));
      if (overflow) {
        d_st.site = &m_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (c = 0; c < n; c++) {
        aidx = b_colidx_data[0] - 1;
        bidx_tmp = a_colidx_data[c];
        bidx = bidx_tmp - 1;
        overflow = (b_colidx_data[0] < b_colidx_data[1]);
        moreBToDo = (bidx_tmp < a_colidx_data[c + 1]);
        while (overflow || moreBToDo) {
          while (
              (aidx + 1 < b_colidx_data[1]) &&
              ((!moreBToDo) || (b_rowidx_data[aidx] < a_rowidx_data[bidx]))) {
            if (b_d_data[aidx] != 0.0) {
              s->d->data[didx - 1] = b_d_data[aidx];
              s->rowidx->data[didx - 1] = b_rowidx_data[aidx];
              didx++;
            }
            aidx++;
          }
          overflow = (aidx + 1 < b_colidx_data[1]);
          while ((bidx + 1 < a_colidx_data[c + 1]) &&
                 ((!overflow) || (a_rowidx_data[bidx] < b_rowidx_data[aidx]))) {
            if (a_d_data[bidx] != 0.0) {
              s->d->data[didx - 1] = a_d_data[bidx];
              s->rowidx->data[didx - 1] = a_rowidx_data[bidx];
              didx++;
            }
            bidx++;
          }
          while ((aidx + 1 < b_colidx_data[1]) &&
                 (bidx + 1 < a_colidx_data[c + 1]) &&
                 (b_rowidx_data[aidx] == a_rowidx_data[bidx])) {
            val = a_d_data[bidx] + b_d_data[aidx];
            if (val != 0.0) {
              s->d->data[didx - 1] = val;
              s->rowidx->data[didx - 1] = a_rowidx_data[bidx];
              didx++;
            }
            bidx++;
            aidx++;
          }
          overflow = (aidx + 1 < b_colidx_data[1]);
          moreBToDo = (bidx + 1 < a_colidx_data[c + 1]);
        }
        s->colidx->data[c + 1] = didx;
      }
    }
  } else if (a_m == 1) {
    b_st.site = &pf_emlrtRSI;
    sparseSparseRowExpandBinOp(&b_st, a_d, a_colidx, b_d, b_colidx, b_rowidx, s,
                               false);
  } else if (b_m == 1) {
    b_st.site = &qf_emlrtRSI;
    c_sparseSparseRowExpandBinOp(&b_st, b_d, b_colidx, a_d, a_colidx, a_rowidx,
                                 s);
  }
}

/* End of code generation (sparse1.c) */
