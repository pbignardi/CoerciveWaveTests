/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ComputeErrors.c
 *
 * Code generation for function 'ComputeErrors'
 *
 */

/* Include files */
#include "ComputeErrors.h"
#include "OperatorEval.h"
#include "SolutionEval.h"
#include "abs.h"
#include "assertValidSizeArg.h"
#include "eml_int_forloop_overflow_check.h"
#include "eml_mtimes_helper.h"
#include "kron.h"
#include "main.h"
#include "main_data.h"
#include "main_emxutil.h"
#include "main_internal_types.h"
#include "main_types.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo kk_emlrtRSI = {
    28,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo lk_emlrtRSI = {
    31,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo mk_emlrtRSI = {
    32,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo nk_emlrtRSI = {
    33,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo ok_emlrtRSI = {
    34,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo pk_emlrtRSI = {
    37,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo qk_emlrtRSI = {
    38,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo rk_emlrtRSI = {
    39,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo sk_emlrtRSI = {
    40,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo tk_emlrtRSI = {
    41,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo uk_emlrtRSI = {
    42,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo vk_emlrtRSI = {
    43,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo wk_emlrtRSI = {
    44,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo xk_emlrtRSI = {
    47,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo yk_emlrtRSI = {
    48,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo al_emlrtRSI = {
    49,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo bl_emlrtRSI = {
    50,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo cl_emlrtRSI = {
    51,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo dl_emlrtRSI = {
    54,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo el_emlrtRSI = {
    56,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo fl_emlrtRSI = {
    58,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo gl_emlrtRSI = {
    61,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo hl_emlrtRSI = {
    63,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo il_emlrtRSI = {
    65,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo jl_emlrtRSI = {
    67,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo kl_emlrtRSI = {
    68,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo ll_emlrtRSI = {
    69,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo ml_emlrtRSI = {
    70,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo nl_emlrtRSI = {
    71,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo ol_emlrtRSI = {
    74,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo pl_emlrtRSI = {
    75,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo ql_emlrtRSI = {
    76,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo rl_emlrtRSI = {
    77,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo sl_emlrtRSI = {
    85,              /* lineNo */
    "ComputeErrors", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pathName */
};

static emlrtRSInfo tl_emlrtRSI = {
    109,               /* lineNo */
    "computeDimsData", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pathName */
};

static emlrtRSInfo ul_emlrtRSI = {
    29,                  /* lineNo */
    "reshapeSizeChecks", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pathName */
};

static emlrtRSInfo vm_emlrtRSI = {
    186,             /* lineNo */
    "unaryMinOrMax", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo wm_emlrtRSI = {
    897,                    /* lineNo */
    "maxRealVectorOmitNaN", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo xm_emlrtRSI = {
    62,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo ym_emlrtRSI = {
    54,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo an_emlrtRSI = {
    103,         /* lineNo */
    "findFirst", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo bn_emlrtRSI = {
    120,                        /* lineNo */
    "minOrMaxRealVectorKernel", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRTEInfo eb_emlrtRTEI = {
    130,             /* lineNo */
    27,              /* colNo */
    "unaryMinOrMax", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = {
    57,                  /* lineNo */
    23,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = {
    52,                  /* lineNo */
    13,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = {
    59,                  /* lineNo */
    23,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pName */
};

static emlrtECInfo e_emlrtECI = {
    1,               /* nDims */
    85,              /* lineNo */
    27,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtECInfo f_emlrtECI = {
    1,               /* nDims */
    65,              /* lineNo */
    17,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtECInfo g_emlrtECI = {
    1,               /* nDims */
    65,              /* lineNo */
    18,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtECInfo h_emlrtECI = {
    1,               /* nDims */
    65,              /* lineNo */
    43,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtECInfo i_emlrtECI = {
    1,               /* nDims */
    65,              /* lineNo */
    26,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtECInfo j_emlrtECI = {
    1,               /* nDims */
    63,              /* lineNo */
    17,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtECInfo k_emlrtECI = {
    1,               /* nDims */
    63,              /* lineNo */
    18,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtECInfo l_emlrtECI = {
    1,               /* nDims */
    63,              /* lineNo */
    37,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtECInfo m_emlrtECI = {
    1,               /* nDims */
    63,              /* lineNo */
    19,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtECInfo n_emlrtECI = {
    1,               /* nDims */
    61,              /* lineNo */
    17,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtECInfo o_emlrtECI = {
    1,               /* nDims */
    61,              /* lineNo */
    18,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtECInfo p_emlrtECI = {
    1,               /* nDims */
    58,              /* lineNo */
    17,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtECInfo q_emlrtECI = {
    1,               /* nDims */
    58,              /* lineNo */
    18,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtECInfo r_emlrtECI = {
    1,               /* nDims */
    56,              /* lineNo */
    17,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtECInfo s_emlrtECI = {
    1,               /* nDims */
    56,              /* lineNo */
    18,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtECInfo t_emlrtECI = {
    1,               /* nDims */
    54,              /* lineNo */
    17,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtDCInfo cc_emlrtDCI = {
    28,              /* lineNo */
    44,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m", /* pName */
    1                                                 /* checkKind */
};

static emlrtDCInfo dc_emlrtDCI = {
    28,              /* lineNo */
    44,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m", /* pName */
    4                                                 /* checkKind */
};

static emlrtRTEInfo sb_emlrtRTEI = {
    13,     /* lineNo */
    9,      /* colNo */
    "sqrt", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" /* pName
                                                                       */
};

static emlrtRTEInfo of_emlrtRTEI = {
    28,              /* lineNo */
    36,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo pf_emlrtRTEI = {
    38,              /* lineNo */
    17,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo qf_emlrtRTEI = {
    39,              /* lineNo */
    17,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo rf_emlrtRTEI = {
    40,              /* lineNo */
    17,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo sf_emlrtRTEI = {
    41,              /* lineNo */
    18,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo tf_emlrtRTEI = {
    42,              /* lineNo */
    18,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo uf_emlrtRTEI = {
    43,              /* lineNo */
    19,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo vf_emlrtRTEI = {
    44,              /* lineNo */
    19,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo wf_emlrtRTEI = {
    54,              /* lineNo */
    17,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo xf_emlrtRTEI = {
    56,              /* lineNo */
    19,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo yf_emlrtRTEI = {
    56,              /* lineNo */
    38,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo ag_emlrtRTEI = {
    58,              /* lineNo */
    18,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo bg_emlrtRTEI = {
    58,              /* lineNo */
    17,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo cg_emlrtRTEI = {
    61,              /* lineNo */
    18,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo dg_emlrtRTEI = {
    61,              /* lineNo */
    17,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo eg_emlrtRTEI = {
    63,              /* lineNo */
    17,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo fg_emlrtRTEI = {
    47,              /* lineNo */
    5,               /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo gg_emlrtRTEI = {
    48,              /* lineNo */
    5,               /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo hg_emlrtRTEI = {
    49,              /* lineNo */
    5,               /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo ig_emlrtRTEI = {
    50,              /* lineNo */
    5,               /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo jg_emlrtRTEI = {
    51,              /* lineNo */
    5,               /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo kg_emlrtRTEI = {
    1,               /* lineNo */
    19,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo bi_emlrtRTEI = {
    85,              /* lineNo */
    27,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo ci_emlrtRTEI = {
    65,              /* lineNo */
    17,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo di_emlrtRTEI = {
    65,              /* lineNo */
    18,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo ei_emlrtRTEI = {
    65,              /* lineNo */
    43,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo fi_emlrtRTEI = {
    63,              /* lineNo */
    18,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

static emlrtRTEInfo gi_emlrtRTEI = {
    63,              /* lineNo */
    37,              /* colNo */
    "ComputeErrors", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\ComputeErrors.m" /* pName */
};

/* Function Declarations */
static void b_binary_expand_op(const emlrtStack *sp, emxArray_real_T *Ux_ex,
                               emlrtRSInfo ln_emlrtRSI,
                               const emxArray_real_T *U_ex,
                               const emxArray_real_T *r1, int32_T nx);

static real_T c_binary_expand_op(const emlrtStack *sp, emlrtRSInfo ln_emlrtRSI,
                                 const emxArray_real_T *r4,
                                 const emxArray_real_T *r5, real_T varargin_1);

static void d_binary_expand_op(const emlrtStack *sp, emxArray_real_T *r,
                               emlrtRSInfo ln_emlrtRSI,
                               const emxArray_real_T *Uxx_ex,
                               const emxArray_real_T *Utt_ex);

static void e_binary_expand_op(const emlrtStack *sp, emxArray_real_T *Utt_ex,
                               const emxArray_real_T *r1, int32_T nx);

static void g_binary_expand_op(const emlrtStack *sp, emxArray_real_T *r,
                               emlrtRSInfo ln_emlrtRSI,
                               const emxArray_real_T *Ut_ex,
                               const emxArray_real_T *T, int32_T nx);

static void h_binary_expand_op(const emlrtStack *sp, emxArray_real_T *r2,
                               const emxArray_real_T *r3, int32_T nx,
                               const emxArray_real_T *U_ex);

static void i_binary_expand_op(const emlrtStack *sp, emxArray_real_T *r3,
                               emlrtRSInfo ln_emlrtRSI,
                               const emxArray_real_T *Utt_ex);

/* Function Definitions */
static void b_binary_expand_op(const emlrtStack *sp, emxArray_real_T *Ux_ex,
                               emlrtRSInfo ln_emlrtRSI,
                               const emxArray_real_T *U_ex,
                               const emxArray_real_T *r1, int32_T nx)
{
  emlrtStack st;
  emxArray_real_T *b_U_ex;
  const real_T *U_ex_data;
  const real_T *r;
  real_T *b_U_ex_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  st.prev = sp;
  st.tls = sp->tls;
  r = r1->data;
  U_ex_data = U_ex->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_U_ex, 1, &bi_emlrtRTEI);
  i = b_U_ex->size[0];
  if (nx == 1) {
    b_U_ex->size[0] = U_ex->size[0];
  } else {
    b_U_ex->size[0] = nx;
  }
  emxEnsureCapacity_real_T(sp, b_U_ex, i, &bi_emlrtRTEI);
  b_U_ex_data = b_U_ex->data;
  stride_0_0 = (U_ex->size[0] != 1);
  stride_1_0 = (nx != 1);
  if (nx == 1) {
    loop_ub = U_ex->size[0];
  } else {
    loop_ub = nx;
  }
  for (i = 0; i < loop_ub; i++) {
    b_U_ex_data[i] = U_ex_data[i * stride_0_0] - r[i * stride_1_0];
  }
  st.site = &ln_emlrtRSI;
  b_abs(&st, b_U_ex, Ux_ex);
  emxFree_real_T(sp, &b_U_ex);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static real_T c_binary_expand_op(const emlrtStack *sp, emlrtRSInfo ln_emlrtRSI,
                                 const emxArray_real_T *r4,
                                 const emxArray_real_T *r5, real_T varargin_1)
{
  emlrtStack st;
  emxArray_real_T *r2;
  const real_T *r;
  const real_T *r1;
  real_T OPEsq;
  real_T *r3;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  st.prev = sp;
  st.tls = sp->tls;
  r = r5->data;
  r1 = r4->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &r2, 1, &ci_emlrtRTEI);
  i = r2->size[0];
  if ((int32_T)varargin_1 == 1) {
    r2->size[0] = r4->size[0];
  } else {
    r2->size[0] = (int32_T)varargin_1;
  }
  emxEnsureCapacity_real_T(sp, r2, i, &ci_emlrtRTEI);
  r3 = r2->data;
  stride_0_0 = (r4->size[0] != 1);
  stride_1_0 = ((int32_T)varargin_1 != 1);
  if ((int32_T)varargin_1 == 1) {
    loop_ub = r4->size[0];
  } else {
    loop_ub = (int32_T)varargin_1;
  }
  for (i = 0; i < loop_ub; i++) {
    r3[i] = r1[i * stride_0_0] * r[i * stride_1_0];
  }
  st.site = &ln_emlrtRSI;
  OPEsq = c_sum(&st, r2);
  emxFree_real_T(sp, &r2);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return OPEsq;
}

static void d_binary_expand_op(const emlrtStack *sp, emxArray_real_T *r,
                               emlrtRSInfo ln_emlrtRSI,
                               const emxArray_real_T *Uxx_ex,
                               const emxArray_real_T *Utt_ex)
{
  emlrtStack st;
  emxArray_real_T *b_Uxx_ex;
  const real_T *Utt_ex_data;
  const real_T *Uxx_ex_data;
  real_T *b_Uxx_ex_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  st.prev = sp;
  st.tls = sp->tls;
  Utt_ex_data = Utt_ex->data;
  Uxx_ex_data = Uxx_ex->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_Uxx_ex, 1, &di_emlrtRTEI);
  i = b_Uxx_ex->size[0];
  if (Utt_ex->size[0] == 1) {
    b_Uxx_ex->size[0] = Uxx_ex->size[0];
  } else {
    b_Uxx_ex->size[0] = Utt_ex->size[0];
  }
  emxEnsureCapacity_real_T(sp, b_Uxx_ex, i, &di_emlrtRTEI);
  b_Uxx_ex_data = b_Uxx_ex->data;
  stride_0_0 = (Uxx_ex->size[0] != 1);
  stride_1_0 = (Utt_ex->size[0] != 1);
  if (Utt_ex->size[0] == 1) {
    loop_ub = Uxx_ex->size[0];
  } else {
    loop_ub = Utt_ex->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    b_Uxx_ex_data[i] =
        Uxx_ex_data[i * stride_0_0] + Utt_ex_data[i * stride_1_0];
  }
  st.site = &ln_emlrtRSI;
  power(&st, b_Uxx_ex, r);
  emxFree_real_T(sp, &b_Uxx_ex);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void e_binary_expand_op(const emlrtStack *sp, emxArray_real_T *Utt_ex,
                               const emxArray_real_T *r1, int32_T nx)
{
  emxArray_real_T *b_Utt_ex;
  const real_T *r;
  real_T *Utt_ex_data;
  real_T *b_Utt_ex_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  r = r1->data;
  Utt_ex_data = Utt_ex->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_Utt_ex, 1, &ei_emlrtRTEI);
  i = b_Utt_ex->size[0];
  if (nx == 1) {
    b_Utt_ex->size[0] = Utt_ex->size[0];
  } else {
    b_Utt_ex->size[0] = nx;
  }
  emxEnsureCapacity_real_T(sp, b_Utt_ex, i, &ei_emlrtRTEI);
  b_Utt_ex_data = b_Utt_ex->data;
  stride_0_0 = (Utt_ex->size[0] != 1);
  stride_1_0 = (nx != 1);
  if (nx == 1) {
    loop_ub = Utt_ex->size[0];
  } else {
    loop_ub = nx;
  }
  for (i = 0; i < loop_ub; i++) {
    b_Utt_ex_data[i] = Utt_ex_data[i * stride_0_0] - r[i * stride_1_0];
  }
  i = Utt_ex->size[0];
  Utt_ex->size[0] = b_Utt_ex->size[0];
  emxEnsureCapacity_real_T(sp, Utt_ex, i, &ei_emlrtRTEI);
  Utt_ex_data = Utt_ex->data;
  loop_ub = b_Utt_ex->size[0];
  for (i = 0; i < loop_ub; i++) {
    Utt_ex_data[i] = b_Utt_ex_data[i];
  }
  emxFree_real_T(sp, &b_Utt_ex);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void g_binary_expand_op(const emlrtStack *sp, emxArray_real_T *r,
                               emlrtRSInfo ln_emlrtRSI,
                               const emxArray_real_T *Ut_ex,
                               const emxArray_real_T *T, int32_T nx)
{
  emlrtStack st;
  emxArray_real_T *b_Ut_ex;
  const real_T *T_data;
  const real_T *Ut_ex_data;
  real_T *b_Ut_ex_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  st.prev = sp;
  st.tls = sp->tls;
  T_data = T->data;
  Ut_ex_data = Ut_ex->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_Ut_ex, 1, &gi_emlrtRTEI);
  i = b_Ut_ex->size[0];
  if (nx == 1) {
    b_Ut_ex->size[0] = Ut_ex->size[0];
  } else {
    b_Ut_ex->size[0] = nx;
  }
  emxEnsureCapacity_real_T(sp, b_Ut_ex, i, &gi_emlrtRTEI);
  b_Ut_ex_data = b_Ut_ex->data;
  stride_0_0 = (Ut_ex->size[0] != 1);
  stride_1_0 = (nx != 1);
  if (nx == 1) {
    loop_ub = Ut_ex->size[0];
  } else {
    loop_ub = nx;
  }
  for (i = 0; i < loop_ub; i++) {
    b_Ut_ex_data[i] = Ut_ex_data[i * stride_0_0] - T_data[i * stride_1_0];
  }
  st.site = &ln_emlrtRSI;
  power(&st, b_Ut_ex, r);
  emxFree_real_T(sp, &b_Ut_ex);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void h_binary_expand_op(const emlrtStack *sp, emxArray_real_T *r2,
                               const emxArray_real_T *r3, int32_T nx,
                               const emxArray_real_T *U_ex)
{
  const real_T *U_ex_data;
  const real_T *r;
  real_T *r1;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  U_ex_data = U_ex->data;
  r = r3->data;
  i = r2->size[0];
  if (U_ex->size[0] == 1) {
    r2->size[0] = nx;
  } else {
    r2->size[0] = U_ex->size[0];
  }
  emxEnsureCapacity_real_T(sp, r2, i, &cg_emlrtRTEI);
  r1 = r2->data;
  stride_0_0 = (nx != 1);
  stride_1_0 = (U_ex->size[0] != 1);
  if (U_ex->size[0] == 1) {
    loop_ub = nx;
  } else {
    loop_ub = U_ex->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    r1[i] = r[i * stride_0_0] - U_ex_data[i * stride_1_0];
  }
}

static void i_binary_expand_op(const emlrtStack *sp, emxArray_real_T *r3,
                               emlrtRSInfo ln_emlrtRSI,
                               const emxArray_real_T *Utt_ex)
{
  emlrtStack st;
  emxArray_real_T *r1;
  const real_T *Utt_ex_data;
  real_T *r;
  real_T *r2;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  st.prev = sp;
  st.tls = sp->tls;
  Utt_ex_data = Utt_ex->data;
  r = r3->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &r1, 1, &ag_emlrtRTEI);
  i = r1->size[0];
  if (Utt_ex->size[0] == 1) {
    r1->size[0] = r3->size[0];
  } else {
    r1->size[0] = Utt_ex->size[0];
  }
  emxEnsureCapacity_real_T(sp, r1, i, &ag_emlrtRTEI);
  r2 = r1->data;
  stride_0_0 = (r3->size[0] != 1);
  stride_1_0 = (Utt_ex->size[0] != 1);
  if (Utt_ex->size[0] == 1) {
    loop_ub = r3->size[0];
  } else {
    loop_ub = Utt_ex->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    r2[i] = r[i * stride_0_0] + Utt_ex_data[i * stride_1_0];
  }
  st.site = &ln_emlrtRSI;
  power(&st, r1, r3);
  emxFree_real_T(sp, &r1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void ComputeErrors(
    const emlrtStack *sp, const emxArray_real_T *u, real_T problem_c,
    real_T problem_u_workspace_c, real_T problem_u_workspace_phi,
    real_T problem_dx_u_workspace_c, real_T problem_dx_u_workspace_phi,
    real_T problem_dt_u_workspace_c, real_T problem_dt_u_workspace_phi,
    real_T problem_ddx_u_workspace_c, real_T problem_ddx_u_workspace_phi,
    real_T problem_ddt_u_workspace_c, real_T problem_ddt_u_workspace_phi,
    const emxArray_real_T *mesh_pivots, const emxArray_real_T *mesh_elms,
    real_T disc_nx, real_T disc_nt, real_T disc_hx, real_T disc_ht,
    const emxArray_real_T *disc_xx, const emxArray_real_T *disc_tt,
    c_struct_T *errors)
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
  emxArray_real_T r12;
  emxArray_real_T r13;
  emxArray_real_T *T;
  emxArray_real_T *U;
  emxArray_real_T *U_ex;
  emxArray_real_T *Ut_ex;
  emxArray_real_T *Utt_ex;
  emxArray_real_T *Ux_ex;
  emxArray_real_T *Uxx_ex;
  emxArray_real_T *X;
  emxArray_real_T *r;
  emxArray_real_T *r11;
  emxArray_real_T *r15;
  emxArray_real_T *r2;
  emxArray_real_T *r3;
  emxArray_real_T *r5;
  emxArray_real_T *r7;
  emxArray_real_T *r8;
  emxArray_real_T *r9;
  real_T b_dv1[1024];
  real_T b_dv[64];
  real_T c_a[32];
  real_T a[8];
  real_T b_a[8];
  real_T H1Esq;
  real_T H1Nsq;
  real_T L2Esq;
  real_T L2Nsq;
  real_T OPEsq;
  real_T OPNsq;
  real_T b;
  real_T b_b;
  real_T c_b;
  real_T varargin_1;
  real_T *T_data;
  real_T *U_ex_data;
  real_T *Ut_ex_data;
  real_T *Utt_ex_data;
  real_T *Ux_ex_data;
  real_T *Uxx_ex_data;
  real_T *X_data;
  real_T *r1;
  real_T *r10;
  real_T *r14;
  real_T *r16;
  real_T *r4;
  real_T *r6;
  int32_T b_nx;
  int32_T c_nx;
  int32_T d_nx;
  int32_T e_nx;
  int32_T f_nx;
  int32_T g_nx;
  int32_T h_nx;
  int32_T i;
  int32_T i_nx;
  int32_T j_nx;
  int32_T k_nx;
  int32_T l_nx;
  int32_T loop_ub;
  int32_T m_nx;
  int32_T maxdimlen;
  int32_T n_nx;
  int32_T nx;
  int32_T o_nx;
  int32_T p_nx;
  int32_T q_nx;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 15U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 0U);
  /*     %% Unpack structs */
  /*     %% Gauss quadrature */
  /*  Total number of quadrature points */
  OPEsq = disc_nx * disc_nt;
  varargin_1 = OPEsq * 8.0 * 8.0;
  /*  Quadrature weights */
  for (i = 0; i < 8; i++) {
    b = dv[i];
    a[i] = b * disc_ht;
    b_a[i] = b * disc_hx;
  }
  if (!(OPEsq >= 0.0)) {
    emlrtNonNegativeCheckR2012b(OPEsq, &dc_emlrtDCI, (emlrtCTX)sp);
  }
  if (OPEsq != (int32_T)muDoubleScalarFloor(OPEsq)) {
    emlrtIntegerCheckR2012b(OPEsq, &cc_emlrtDCI, (emlrtCTX)sp);
  }
  emxInit_real_T(sp, &r, 2, &of_emlrtRTEI);
  maxdimlen = (int32_T)OPEsq;
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = (int32_T)OPEsq;
  emxEnsureCapacity_real_T(sp, r, i, &of_emlrtRTEI);
  r1 = r->data;
  for (i = 0; i < maxdimlen; i++) {
    r1[i] = 1.0;
  }
  emxInit_real_T(sp, &r2, 2, &kg_emlrtRTEI);
  e_kron(a, b_a, b_dv);
  st.site = &kk_emlrtRSI;
  i_kron(&st, b_dv, r, r2);
  r1 = r2->data;
  st.site = &kk_emlrtRSI;
  nx = r2->size[1] << 6;
  b_st.site = &ul_emlrtRSI;
  c_st.site = &tl_emlrtRSI;
  assertValidSizeArg(&c_st, varargin_1);
  maxdimlen = 64;
  emxFree_real_T(&st, &r);
  if (r2->size[1] > 64) {
    maxdimlen = r2->size[1];
  }
  if ((int32_T)varargin_1 > muIntScalarMax_sint32(nx, maxdimlen)) {
    emlrtErrorWithMessageIdR2018a(&st, &hb_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if ((int32_T)varargin_1 < 0) {
    emlrtErrorWithMessageIdR2018a(&st, &gb_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  if ((int32_T)varargin_1 != nx) {
    emlrtErrorWithMessageIdR2018a(
        &st, &ib_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  emxInit_real_T(&st, &U, 2, &sf_emlrtRTEI);
  emxInit_real_T(&st, &X, 2, &kg_emlrtRTEI);
  emxInit_real_T(&st, &T, 2, &kg_emlrtRTEI);
  emxInit_real_T(&st, &r3, 2, &kg_emlrtRTEI);
  /*     %% Basis evaluation */
  st.site = &lk_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  OPEsq = 1.0 / disc_hx;
  st.site = &mk_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  b_b = 1.0 / disc_ht;
  st.site = &nk_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  c_b = muDoubleScalarPower(disc_hx, -2.0);
  st.site = &ok_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  b = muDoubleScalarPower(disc_ht, -2.0);
  /*     %% Evaluate u_ex and u */
  st.site = &pk_emlrtRSI;
  SolutionEval(&st, u, mesh_pivots, mesh_elms, disc_nx, disc_nt, disc_hx,
               disc_ht, disc_xx, disc_tt, U, X, T);
  T_data = T->data;
  X_data = X->data;
  Ux_ex_data = U->data;
  i = r3->size[0] * r3->size[1];
  r3->size[0] = U->size[1];
  r3->size[1] = U->size[0];
  emxEnsureCapacity_real_T(sp, r3, i, &pf_emlrtRTEI);
  r4 = r3->data;
  loop_ub = U->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_nx = U->size[1];
    for (maxdimlen = 0; maxdimlen < b_nx; maxdimlen++) {
      r4[maxdimlen + r3->size[0] * i] = Ux_ex_data[i + U->size[0] * maxdimlen];
    }
  }
  st.site = &qk_emlrtRSI;
  nx = r3->size[0] * r3->size[1];
  b_st.site = &ul_emlrtRSI;
  maxdimlen = r3->size[0];
  if (r3->size[1] > r3->size[0]) {
    maxdimlen = r3->size[1];
  }
  maxdimlen = muIntScalarMax_sint32(nx, maxdimlen);
  if (nx > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &hb_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (1 > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &hb_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (nx < 0) {
    emlrtErrorWithMessageIdR2018a(&st, &gb_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  emxInit_real_T(&st, &r5, 2, &kg_emlrtRTEI);
  i = r5->size[0] * r5->size[1];
  r5->size[0] = X->size[1];
  r5->size[1] = X->size[0];
  emxEnsureCapacity_real_T(sp, r5, i, &qf_emlrtRTEI);
  r6 = r5->data;
  loop_ub = X->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_nx = X->size[1];
    for (maxdimlen = 0; maxdimlen < b_nx; maxdimlen++) {
      r6[maxdimlen + r5->size[0] * i] = X_data[i + X->size[0] * maxdimlen];
    }
  }
  st.site = &rk_emlrtRSI;
  c_nx = r5->size[0] * r5->size[1];
  b_st.site = &ul_emlrtRSI;
  maxdimlen = r5->size[0];
  if (r5->size[1] > r5->size[0]) {
    maxdimlen = r5->size[1];
  }
  maxdimlen = muIntScalarMax_sint32(c_nx, maxdimlen);
  if (c_nx > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &hb_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (1 > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &hb_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (c_nx < 0) {
    emlrtErrorWithMessageIdR2018a(&st, &gb_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  emxInit_real_T(&st, &r7, 2, &kg_emlrtRTEI);
  i = r7->size[0] * r7->size[1];
  r7->size[0] = T->size[1];
  r7->size[1] = T->size[0];
  emxEnsureCapacity_real_T(sp, r7, i, &rf_emlrtRTEI);
  r6 = r7->data;
  loop_ub = T->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_nx = T->size[1];
    for (maxdimlen = 0; maxdimlen < b_nx; maxdimlen++) {
      r6[maxdimlen + r7->size[0] * i] = T_data[i + T->size[0] * maxdimlen];
    }
  }
  st.site = &sk_emlrtRSI;
  d_nx = r7->size[0] * r7->size[1];
  b_st.site = &ul_emlrtRSI;
  maxdimlen = r7->size[0];
  if (r7->size[1] > r7->size[0]) {
    maxdimlen = r7->size[1];
  }
  maxdimlen = muIntScalarMax_sint32(d_nx, maxdimlen);
  if (d_nx > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &hb_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (1 > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &hb_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (d_nx < 0) {
    emlrtErrorWithMessageIdR2018a(&st, &gb_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  for (i = 0; i < 32; i++) {
    c_a[i] = dv2[i] * OPEsq;
  }
  f_kron(dv3, c_a, b_dv1);
  st.site = &tk_emlrtRSI;
  OperatorEval(&st, u, mesh_elms, disc_nx, disc_nt, b_dv1, U);
  Ux_ex_data = U->data;
  i = X->size[0] * X->size[1];
  X->size[0] = U->size[1];
  X->size[1] = U->size[0];
  emxEnsureCapacity_real_T(sp, X, i, &sf_emlrtRTEI);
  X_data = X->data;
  loop_ub = U->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_nx = U->size[1];
    for (maxdimlen = 0; maxdimlen < b_nx; maxdimlen++) {
      X_data[maxdimlen + X->size[0] * i] =
          Ux_ex_data[i + U->size[0] * maxdimlen];
    }
  }
  st.site = &tk_emlrtRSI;
  e_nx = X->size[0] * X->size[1];
  b_st.site = &ul_emlrtRSI;
  maxdimlen = X->size[0];
  if (X->size[1] > X->size[0]) {
    maxdimlen = X->size[1];
  }
  maxdimlen = muIntScalarMax_sint32(e_nx, maxdimlen);
  if (e_nx > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &hb_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (1 > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &hb_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (e_nx < 0) {
    emlrtErrorWithMessageIdR2018a(&st, &gb_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  for (i = 0; i < 32; i++) {
    c_a[i] = dv2[i] * b_b;
  }
  f_kron(c_a, dv3, b_dv1);
  st.site = &uk_emlrtRSI;
  OperatorEval(&st, u, mesh_elms, disc_nx, disc_nt, b_dv1, U);
  Ux_ex_data = U->data;
  i = T->size[0] * T->size[1];
  T->size[0] = U->size[1];
  T->size[1] = U->size[0];
  emxEnsureCapacity_real_T(sp, T, i, &tf_emlrtRTEI);
  T_data = T->data;
  loop_ub = U->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_nx = U->size[1];
    for (maxdimlen = 0; maxdimlen < b_nx; maxdimlen++) {
      T_data[maxdimlen + T->size[0] * i] =
          Ux_ex_data[i + U->size[0] * maxdimlen];
    }
  }
  st.site = &uk_emlrtRSI;
  f_nx = T->size[0] * T->size[1];
  b_st.site = &ul_emlrtRSI;
  maxdimlen = T->size[0];
  if (T->size[1] > T->size[0]) {
    maxdimlen = T->size[1];
  }
  maxdimlen = muIntScalarMax_sint32(f_nx, maxdimlen);
  if (f_nx > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &hb_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (1 > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &hb_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (f_nx < 0) {
    emlrtErrorWithMessageIdR2018a(&st, &gb_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  for (i = 0; i < 32; i++) {
    c_a[i] = dv4[i] * c_b;
  }
  emxInit_real_T(sp, &r8, 2, &kg_emlrtRTEI);
  f_kron(dv3, c_a, b_dv1);
  st.site = &vk_emlrtRSI;
  OperatorEval(&st, u, mesh_elms, disc_nx, disc_nt, b_dv1, U);
  Ux_ex_data = U->data;
  i = r8->size[0] * r8->size[1];
  r8->size[0] = U->size[1];
  r8->size[1] = U->size[0];
  emxEnsureCapacity_real_T(sp, r8, i, &uf_emlrtRTEI);
  r6 = r8->data;
  loop_ub = U->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_nx = U->size[1];
    for (maxdimlen = 0; maxdimlen < b_nx; maxdimlen++) {
      r6[maxdimlen + r8->size[0] * i] = Ux_ex_data[i + U->size[0] * maxdimlen];
    }
  }
  st.site = &vk_emlrtRSI;
  g_nx = r8->size[0] * r8->size[1];
  b_st.site = &ul_emlrtRSI;
  maxdimlen = r8->size[0];
  if (r8->size[1] > r8->size[0]) {
    maxdimlen = r8->size[1];
  }
  maxdimlen = muIntScalarMax_sint32(g_nx, maxdimlen);
  if (g_nx > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &hb_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (1 > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &hb_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (g_nx < 0) {
    emlrtErrorWithMessageIdR2018a(&st, &gb_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  for (i = 0; i < 32; i++) {
    c_a[i] = dv4[i] * b;
  }
  emxInit_real_T(sp, &r9, 2, &kg_emlrtRTEI);
  f_kron(c_a, dv3, b_dv1);
  st.site = &wk_emlrtRSI;
  OperatorEval(&st, u, mesh_elms, disc_nx, disc_nt, b_dv1, U);
  Ux_ex_data = U->data;
  i = r9->size[0] * r9->size[1];
  r9->size[0] = U->size[1];
  r9->size[1] = U->size[0];
  emxEnsureCapacity_real_T(sp, r9, i, &vf_emlrtRTEI);
  r10 = r9->data;
  loop_ub = U->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_nx = U->size[1];
    for (maxdimlen = 0; maxdimlen < b_nx; maxdimlen++) {
      r10[maxdimlen + r9->size[0] * i] = Ux_ex_data[i + U->size[0] * maxdimlen];
    }
  }
  emxFree_real_T(sp, &U);
  st.site = &wk_emlrtRSI;
  b_nx = r9->size[0] * r9->size[1];
  b_st.site = &ul_emlrtRSI;
  maxdimlen = r9->size[0];
  if (r9->size[1] > r9->size[0]) {
    maxdimlen = r9->size[1];
  }
  maxdimlen = muIntScalarMax_sint32(b_nx, maxdimlen);
  if (b_nx > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &hb_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (1 > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &hb_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (b_nx < 0) {
    emlrtErrorWithMessageIdR2018a(&st, &gb_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  emxInit_real_T(&st, &U_ex, 1, &fg_emlrtRTEI);
  emxInit_real_T(&st, &Ux_ex, 1, &gg_emlrtRTEI);
  emxInit_real_T(&st, &Ut_ex, 1, &hg_emlrtRTEI);
  emxInit_real_T(&st, &Uxx_ex, 1, &ig_emlrtRTEI);
  emxInit_real_T(&st, &Utt_ex, 1, &jg_emlrtRTEI);
  emxInit_real_T(&st, &r11, 1, &cg_emlrtRTEI);
  /*  Exact solution evaluations */
  st.site = &xk_emlrtRSI;
  r12 = *r5;
  h_nx = c_nx;
  r12.size = &h_nx;
  r12.numDimensions = 1;
  r13 = *r7;
  i_nx = d_nx;
  r13.size = &i_nx;
  r13.numDimensions = 1;
  b_st.site = &oh_emlrtRSI;
  main_anonFcn11(&b_st, problem_u_workspace_c, problem_u_workspace_phi, &r12,
                 &r13, U_ex);
  U_ex_data = U_ex->data;
  st.site = &yk_emlrtRSI;
  r12 = *r5;
  j_nx = c_nx;
  r12.size = &j_nx;
  r12.numDimensions = 1;
  r13 = *r7;
  k_nx = d_nx;
  r13.size = &k_nx;
  r13.numDimensions = 1;
  b_st.site = &oh_emlrtRSI;
  main_anonFcn12(&b_st, problem_dx_u_workspace_c, problem_dx_u_workspace_phi,
                 &r12, &r13, Ux_ex);
  Ux_ex_data = Ux_ex->data;
  st.site = &al_emlrtRSI;
  r12 = *r5;
  l_nx = c_nx;
  r12.size = &l_nx;
  r12.numDimensions = 1;
  r13 = *r7;
  m_nx = d_nx;
  r13.size = &m_nx;
  r13.numDimensions = 1;
  b_st.site = &oh_emlrtRSI;
  main_anonFcn13(&b_st, problem_dt_u_workspace_c, problem_dt_u_workspace_phi,
                 &r12, &r13, Ut_ex);
  Ut_ex_data = Ut_ex->data;
  st.site = &bl_emlrtRSI;
  r12 = *r5;
  n_nx = c_nx;
  r12.size = &n_nx;
  r12.numDimensions = 1;
  r13 = *r7;
  o_nx = d_nx;
  r13.size = &o_nx;
  r13.numDimensions = 1;
  b_st.site = &oh_emlrtRSI;
  main_anonFcn14(&b_st, problem_ddx_u_workspace_c, problem_ddx_u_workspace_phi,
                 &r12, &r13, Uxx_ex);
  Uxx_ex_data = Uxx_ex->data;
  st.site = &cl_emlrtRSI;
  r12 = *r5;
  p_nx = c_nx;
  r12.size = &p_nx;
  r12.numDimensions = 1;
  r13 = *r7;
  q_nx = d_nx;
  r13.size = &q_nx;
  r13.numDimensions = 1;
  b_st.site = &oh_emlrtRSI;
  main_anonFcn15(&b_st, problem_ddt_u_workspace_c, problem_ddt_u_workspace_phi,
                 &r12, &r13, Utt_ex);
  Utt_ex_data = Utt_ex->data;
  /*     %% Compute norms */
  /*  L2 norm */
  i = r11->size[0];
  r11->size[0] = U_ex->size[0];
  emxEnsureCapacity_real_T(sp, r11, i, &wf_emlrtRTEI);
  r14 = r11->data;
  loop_ub = U_ex->size[0];
  emxFree_real_T(sp, &r7);
  emxFree_real_T(sp, &r5);
  for (i = 0; i < loop_ub; i++) {
    r14[i] = U_ex_data[i] * U_ex_data[i];
  }
  if ((r11->size[0] != (int32_T)varargin_1) &&
      ((r11->size[0] != 1) && ((int32_T)varargin_1 != 1))) {
    emlrtDimSizeImpxCheckR2021b(r11->size[0], (int32_T)varargin_1, &t_emlrtECI,
                                (emlrtCTX)sp);
  }
  if (r11->size[0] == (int32_T)varargin_1) {
    loop_ub = r11->size[0];
    for (i = 0; i < loop_ub; i++) {
      r14[i] *= r1[i];
    }
    st.site = &dl_emlrtRSI;
    L2Nsq = c_sum(&st, r11);
  } else {
    st.site = &dl_emlrtRSI;
    L2Nsq = c_binary_expand_op(&st, dl_emlrtRSI, r11, r2, varargin_1);
  }
  /*  H1 grad norm */
  i = r11->size[0];
  r11->size[0] = Ux_ex->size[0];
  emxEnsureCapacity_real_T(sp, r11, i, &xf_emlrtRTEI);
  r14 = r11->data;
  loop_ub = Ux_ex->size[0];
  for (i = 0; i < loop_ub; i++) {
    r14[i] = Ux_ex_data[i] * Ux_ex_data[i];
  }
  emxInit_real_T(sp, &r15, 1, &eg_emlrtRTEI);
  i = r15->size[0];
  r15->size[0] = Ut_ex->size[0];
  emxEnsureCapacity_real_T(sp, r15, i, &yf_emlrtRTEI);
  r16 = r15->data;
  loop_ub = Ut_ex->size[0];
  for (i = 0; i < loop_ub; i++) {
    r16[i] = Ut_ex_data[i] * Ut_ex_data[i];
  }
  if ((r11->size[0] != r15->size[0]) &&
      ((r11->size[0] != 1) && (r15->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(r11->size[0], r15->size[0], &s_emlrtECI,
                                (emlrtCTX)sp);
  }
  if (r11->size[0] == r15->size[0]) {
    loop_ub = r11->size[0];
    for (i = 0; i < loop_ub; i++) {
      r14[i] += r16[i];
    }
  } else {
    st.site = &el_emlrtRSI;
    plus(&st, r11, r15);
    r14 = r11->data;
  }
  if ((r11->size[0] != (int32_T)varargin_1) &&
      ((r11->size[0] != 1) && ((int32_T)varargin_1 != 1))) {
    emlrtDimSizeImpxCheckR2021b(r11->size[0], (int32_T)varargin_1, &r_emlrtECI,
                                (emlrtCTX)sp);
  }
  if (r11->size[0] == (int32_T)varargin_1) {
    loop_ub = r11->size[0];
    for (i = 0; i < loop_ub; i++) {
      r14[i] *= r1[i];
    }
    st.site = &el_emlrtRSI;
    H1Nsq = c_sum(&st, r11);
  } else {
    st.site = &el_emlrtRSI;
    H1Nsq = c_binary_expand_op(&st, el_emlrtRSI, r11, r2, varargin_1);
  }
  /*  Operator norm */
  st.site = &fl_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  OPEsq = problem_c * problem_c;
  i = r11->size[0];
  r11->size[0] = Uxx_ex->size[0];
  emxEnsureCapacity_real_T(sp, r11, i, &ag_emlrtRTEI);
  r14 = r11->data;
  loop_ub = Uxx_ex->size[0];
  for (i = 0; i < loop_ub; i++) {
    r14[i] = -OPEsq * Uxx_ex_data[i];
  }
  if ((r11->size[0] != Utt_ex->size[0]) &&
      ((r11->size[0] != 1) && (Utt_ex->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(r11->size[0], Utt_ex->size[0], &q_emlrtECI,
                                (emlrtCTX)sp);
  }
  if (r11->size[0] == Utt_ex->size[0]) {
    i = r15->size[0];
    r15->size[0] = r11->size[0];
    emxEnsureCapacity_real_T(sp, r15, i, &ag_emlrtRTEI);
    r16 = r15->data;
    loop_ub = r11->size[0];
    for (i = 0; i < loop_ub; i++) {
      r16[i] = r14[i] + Utt_ex_data[i];
    }
    st.site = &fl_emlrtRSI;
    power(&st, r15, r11);
    r14 = r11->data;
  } else {
    st.site = &fl_emlrtRSI;
    i_binary_expand_op(&st, r11, fl_emlrtRSI, Utt_ex);
    r14 = r11->data;
  }
  if ((r11->size[0] != (int32_T)varargin_1) &&
      ((r11->size[0] != 1) && ((int32_T)varargin_1 != 1))) {
    emlrtDimSizeImpxCheckR2021b(r11->size[0], (int32_T)varargin_1, &p_emlrtECI,
                                (emlrtCTX)sp);
  }
  if (r11->size[0] == (int32_T)varargin_1) {
    i = r15->size[0];
    r15->size[0] = r11->size[0];
    emxEnsureCapacity_real_T(sp, r15, i, &bg_emlrtRTEI);
    r16 = r15->data;
    loop_ub = r11->size[0];
    for (i = 0; i < loop_ub; i++) {
      r16[i] = r14[i] * r1[i];
    }
    st.site = &fl_emlrtRSI;
    OPNsq = c_sum(&st, r15);
  } else {
    st.site = &fl_emlrtRSI;
    OPNsq = c_binary_expand_op(&st, fl_emlrtRSI, r11, r2, varargin_1);
  }
  /*     %% Compute errors */
  /*  L2 error */
  if ((nx != U_ex->size[0]) && ((nx != 1) && (U_ex->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(nx, U_ex->size[0], &o_emlrtECI, (emlrtCTX)sp);
  }
  if (nx == U_ex->size[0]) {
    i = r11->size[0];
    r11->size[0] = nx;
    emxEnsureCapacity_real_T(sp, r11, i, &cg_emlrtRTEI);
    r14 = r11->data;
    for (i = 0; i < nx; i++) {
      r14[i] = r4[i] - U_ex_data[i];
    }
  } else {
    st.site = &gl_emlrtRSI;
    h_binary_expand_op(&st, r11, r3, nx, U_ex);
    r14 = r11->data;
  }
  loop_ub = r11->size[0];
  for (i = 0; i < loop_ub; i++) {
    r14[i] *= r14[i];
  }
  if ((r11->size[0] != (int32_T)varargin_1) &&
      ((r11->size[0] != 1) && ((int32_T)varargin_1 != 1))) {
    emlrtDimSizeImpxCheckR2021b(r11->size[0], (int32_T)varargin_1, &n_emlrtECI,
                                (emlrtCTX)sp);
  }
  if (r11->size[0] == (int32_T)varargin_1) {
    i = r15->size[0];
    r15->size[0] = r11->size[0];
    emxEnsureCapacity_real_T(sp, r15, i, &dg_emlrtRTEI);
    r16 = r15->data;
    loop_ub = r11->size[0];
    for (i = 0; i < loop_ub; i++) {
      r16[i] = r14[i] * r1[i];
    }
    st.site = &gl_emlrtRSI;
    L2Esq = c_sum(&st, r15);
  } else {
    st.site = &gl_emlrtRSI;
    L2Esq = c_binary_expand_op(&st, gl_emlrtRSI, r11, r2, varargin_1);
  }
  /*  H1 error */
  if ((Ux_ex->size[0] != e_nx) && ((Ux_ex->size[0] != 1) && (e_nx != 1))) {
    emlrtDimSizeImpxCheckR2021b(Ux_ex->size[0], e_nx, &m_emlrtECI,
                                (emlrtCTX)sp);
  }
  if ((Ut_ex->size[0] != f_nx) && ((Ut_ex->size[0] != 1) && (f_nx != 1))) {
    emlrtDimSizeImpxCheckR2021b(Ut_ex->size[0], f_nx, &l_emlrtECI,
                                (emlrtCTX)sp);
  }
  if (Ux_ex->size[0] == e_nx) {
    loop_ub = Ux_ex->size[0];
    for (i = 0; i < loop_ub; i++) {
      Ux_ex_data[i] -= X_data[i];
    }
    st.site = &hl_emlrtRSI;
    power(&st, Ux_ex, r11);
    r14 = r11->data;
  } else {
    st.site = &hl_emlrtRSI;
    g_binary_expand_op(&st, r11, hl_emlrtRSI, Ux_ex, X, e_nx);
    r14 = r11->data;
  }
  emxFree_real_T(sp, &X);
  if (Ut_ex->size[0] == f_nx) {
    loop_ub = Ut_ex->size[0];
    for (i = 0; i < loop_ub; i++) {
      Ut_ex_data[i] -= T_data[i];
    }
    st.site = &hl_emlrtRSI;
    power(&st, Ut_ex, r15);
    r16 = r15->data;
  } else {
    st.site = &hl_emlrtRSI;
    g_binary_expand_op(&st, r15, hl_emlrtRSI, Ut_ex, T, f_nx);
    r16 = r15->data;
  }
  emxFree_real_T(sp, &T);
  emxFree_real_T(sp, &Ut_ex);
  if ((r11->size[0] != r15->size[0]) &&
      ((r11->size[0] != 1) && (r15->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(r11->size[0], r15->size[0], &k_emlrtECI,
                                (emlrtCTX)sp);
  }
  if (r11->size[0] == r15->size[0]) {
    loop_ub = r11->size[0];
    for (i = 0; i < loop_ub; i++) {
      r14[i] += r16[i];
    }
  } else {
    st.site = &hl_emlrtRSI;
    plus(&st, r11, r15);
    r14 = r11->data;
  }
  if ((r11->size[0] != (int32_T)varargin_1) &&
      ((r11->size[0] != 1) && ((int32_T)varargin_1 != 1))) {
    emlrtDimSizeImpxCheckR2021b(r11->size[0], (int32_T)varargin_1, &j_emlrtECI,
                                (emlrtCTX)sp);
  }
  if (r11->size[0] == (int32_T)varargin_1) {
    i = r15->size[0];
    r15->size[0] = r11->size[0];
    emxEnsureCapacity_real_T(sp, r15, i, &eg_emlrtRTEI);
    r16 = r15->data;
    loop_ub = r11->size[0];
    for (i = 0; i < loop_ub; i++) {
      r16[i] = r14[i] * r1[i];
    }
    st.site = &hl_emlrtRSI;
    H1Esq = c_sum(&st, r15);
  } else {
    st.site = &hl_emlrtRSI;
    H1Esq = c_binary_expand_op(&st, hl_emlrtRSI, r11, r2, varargin_1);
  }
  emxFree_real_T(sp, &r15);
  /*  Operator error */
  if ((Uxx_ex->size[0] != g_nx) && ((Uxx_ex->size[0] != 1) && (g_nx != 1))) {
    emlrtDimSizeImpxCheckR2021b(Uxx_ex->size[0], g_nx, &i_emlrtECI,
                                (emlrtCTX)sp);
  }
  if ((Utt_ex->size[0] != b_nx) && ((Utt_ex->size[0] != 1) && (b_nx != 1))) {
    emlrtDimSizeImpxCheckR2021b(Utt_ex->size[0], b_nx, &h_emlrtECI,
                                (emlrtCTX)sp);
  }
  st.site = &il_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  if (Uxx_ex->size[0] == g_nx) {
    loop_ub = Uxx_ex->size[0];
    for (i = 0; i < loop_ub; i++) {
      Uxx_ex_data[i] = -OPEsq * (Uxx_ex_data[i] - r6[i]);
    }
  } else {
    st.site = &kn_emlrtRSI;
    f_binary_expand_op(&st, Uxx_ex, OPEsq, r8, g_nx);
    Uxx_ex_data = Uxx_ex->data;
  }
  emxFree_real_T(sp, &r8);
  if (Utt_ex->size[0] == b_nx) {
    loop_ub = Utt_ex->size[0];
    for (i = 0; i < loop_ub; i++) {
      Utt_ex_data[i] -= r10[i];
    }
  } else {
    st.site = &il_emlrtRSI;
    e_binary_expand_op(&st, Utt_ex, r9, b_nx);
    Utt_ex_data = Utt_ex->data;
  }
  emxFree_real_T(sp, &r9);
  if ((Uxx_ex->size[0] != Utt_ex->size[0]) &&
      ((Uxx_ex->size[0] != 1) && (Utt_ex->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(Uxx_ex->size[0], Utt_ex->size[0], &g_emlrtECI,
                                (emlrtCTX)sp);
  }
  if (Uxx_ex->size[0] == Utt_ex->size[0]) {
    loop_ub = Uxx_ex->size[0];
    for (i = 0; i < loop_ub; i++) {
      Uxx_ex_data[i] += Utt_ex_data[i];
    }
    st.site = &il_emlrtRSI;
    power(&st, Uxx_ex, r11);
    r14 = r11->data;
  } else {
    st.site = &il_emlrtRSI;
    d_binary_expand_op(&st, r11, il_emlrtRSI, Uxx_ex, Utt_ex);
    r14 = r11->data;
  }
  emxFree_real_T(sp, &Utt_ex);
  emxFree_real_T(sp, &Uxx_ex);
  if ((r11->size[0] != (int32_T)varargin_1) &&
      ((r11->size[0] != 1) && ((int32_T)varargin_1 != 1))) {
    emlrtDimSizeImpxCheckR2021b(r11->size[0], (int32_T)varargin_1, &f_emlrtECI,
                                (emlrtCTX)sp);
  }
  if (r11->size[0] == (int32_T)varargin_1) {
    loop_ub = r11->size[0];
    for (i = 0; i < loop_ub; i++) {
      r14[i] *= r1[i];
    }
    st.site = &il_emlrtRSI;
    OPEsq = c_sum(&st, r11);
  } else {
    st.site = &il_emlrtRSI;
    OPEsq = c_binary_expand_op(&st, il_emlrtRSI, r11, r2, varargin_1);
  }
  emxFree_real_T(sp, &r11);
  emxFree_real_T(sp, &r2);
  /*     %% Populate struct */
  errors->L2N = L2Nsq;
  st.site = &jl_emlrtRSI;
  Ux_ex_data = &errors->L2N;
  if (*Ux_ex_data < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &sb_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  *Ux_ex_data = muDoubleScalarSqrt(*Ux_ex_data);
  errors->H1N = H1Nsq;
  st.site = &kl_emlrtRSI;
  Ux_ex_data = &errors->H1N;
  if (*Ux_ex_data < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &sb_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  *Ux_ex_data = muDoubleScalarSqrt(*Ux_ex_data);
  errors->OPN = OPNsq;
  st.site = &ll_emlrtRSI;
  Ux_ex_data = &errors->OPN;
  if (*Ux_ex_data < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &sb_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  *Ux_ex_data = muDoubleScalarSqrt(*Ux_ex_data);
  b_b = OPNsq + L2Nsq;
  errors->GRN = b_b;
  st.site = &ml_emlrtRSI;
  Ux_ex_data = &errors->GRN;
  if (*Ux_ex_data < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &sb_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  *Ux_ex_data = muDoubleScalarSqrt(*Ux_ex_data);
  /*  Graph norm */
  st.site = &nl_emlrtRSI;
  b_st.site = &nl_emlrtRSI;
  b_abs(&b_st, U_ex, Ux_ex);
  Ux_ex_data = Ux_ex->data;
  b_st.site = &ve_emlrtRSI;
  c_st.site = &we_emlrtRSI;
  d_st.site = &xe_emlrtRSI;
  if (Ux_ex->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &eb_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &vm_emlrtRSI;
  f_st.site = &wm_emlrtRSI;
  maxdimlen = Ux_ex->size[0];
  if (Ux_ex->size[0] <= 2) {
    if (Ux_ex->size[0] == 1) {
      errors->SUPN = Ux_ex_data[0];
    } else if ((Ux_ex_data[0] < Ux_ex_data[1]) ||
               (muDoubleScalarIsNaN(Ux_ex_data[0]) &&
                (!muDoubleScalarIsNaN(Ux_ex_data[1])))) {
      errors->SUPN = Ux_ex_data[1];
    } else {
      errors->SUPN = Ux_ex_data[0];
    }
  } else {
    g_st.site = &ym_emlrtRSI;
    if (!muDoubleScalarIsNaN(Ux_ex_data[0])) {
      b_nx = 1;
    } else {
      b_nx = 0;
      h_st.site = &an_emlrtRSI;
      if (Ux_ex->size[0] > 2147483646) {
        i_st.site = &m_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      c_nx = 2;
      exitg1 = false;
      while ((!exitg1) && (c_nx <= maxdimlen)) {
        if (!muDoubleScalarIsNaN(Ux_ex_data[c_nx - 1])) {
          b_nx = c_nx;
          exitg1 = true;
        } else {
          c_nx++;
        }
      }
    }
    if (b_nx == 0) {
      errors->SUPN = Ux_ex_data[0];
    } else {
      g_st.site = &xm_emlrtRSI;
      c_b = Ux_ex_data[b_nx - 1];
      loop_ub = b_nx + 1;
      h_st.site = &bn_emlrtRSI;
      overflow =
          ((b_nx + 1 <= Ux_ex->size[0]) && (Ux_ex->size[0] > 2147483646));
      if (overflow) {
        i_st.site = &m_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      for (c_nx = loop_ub; c_nx <= maxdimlen; c_nx++) {
        b = Ux_ex_data[c_nx - 1];
        if (c_b < b) {
          c_b = b;
        }
      }
      errors->SUPN = c_b;
    }
  }
  covrtLogIf(&emlrtCoverageInstance, 15U, 0U, 0, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 1U);
  errors->L2E = L2Esq / L2Nsq;
  st.site = &ol_emlrtRSI;
  Ux_ex_data = &errors->L2E;
  if (*Ux_ex_data < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &sb_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  *Ux_ex_data = muDoubleScalarSqrt(*Ux_ex_data);
  errors->H1E = H1Esq / H1Nsq;
  st.site = &pl_emlrtRSI;
  Ux_ex_data = &errors->H1E;
  if (*Ux_ex_data < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &sb_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  *Ux_ex_data = muDoubleScalarSqrt(*Ux_ex_data);
  errors->OPE = OPEsq / OPNsq;
  st.site = &ql_emlrtRSI;
  Ux_ex_data = &errors->OPE;
  if (*Ux_ex_data < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &sb_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  *Ux_ex_data = muDoubleScalarSqrt(*Ux_ex_data);
  errors->GRE = (OPEsq + L2Esq) / b_b;
  st.site = &rl_emlrtRSI;
  Ux_ex_data = &errors->GRE;
  if (*Ux_ex_data < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &sb_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  *Ux_ex_data = muDoubleScalarSqrt(*Ux_ex_data);
  covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 3U);
  if ((U_ex->size[0] != nx) && ((U_ex->size[0] != 1) && (nx != 1))) {
    emlrtDimSizeImpxCheckR2021b(U_ex->size[0], nx, &e_emlrtECI, (emlrtCTX)sp);
  }
  st.site = &sl_emlrtRSI;
  if (U_ex->size[0] == nx) {
    loop_ub = U_ex->size[0];
    for (i = 0; i < loop_ub; i++) {
      U_ex_data[i] -= r4[i];
    }
    b_st.site = &sl_emlrtRSI;
    b_abs(&b_st, U_ex, Ux_ex);
    Ux_ex_data = Ux_ex->data;
  } else {
    b_st.site = &sl_emlrtRSI;
    b_binary_expand_op(&b_st, Ux_ex, sl_emlrtRSI, U_ex, r3, nx);
    Ux_ex_data = Ux_ex->data;
  }
  emxFree_real_T(&st, &r3);
  emxFree_real_T(&st, &U_ex);
  b_st.site = &ve_emlrtRSI;
  c_st.site = &we_emlrtRSI;
  d_st.site = &xe_emlrtRSI;
  if (Ux_ex->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &eb_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &vm_emlrtRSI;
  f_st.site = &wm_emlrtRSI;
  maxdimlen = Ux_ex->size[0];
  if (Ux_ex->size[0] <= 2) {
    if (Ux_ex->size[0] == 1) {
      errors->SUPE = Ux_ex_data[0];
    } else if ((Ux_ex_data[0] < Ux_ex_data[1]) ||
               (muDoubleScalarIsNaN(Ux_ex_data[0]) &&
                (!muDoubleScalarIsNaN(Ux_ex_data[1])))) {
      errors->SUPE = Ux_ex_data[1];
    } else {
      errors->SUPE = Ux_ex_data[0];
    }
  } else {
    g_st.site = &ym_emlrtRSI;
    if (!muDoubleScalarIsNaN(Ux_ex_data[0])) {
      b_nx = 1;
    } else {
      b_nx = 0;
      h_st.site = &an_emlrtRSI;
      if (Ux_ex->size[0] > 2147483646) {
        i_st.site = &m_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      c_nx = 2;
      exitg1 = false;
      while ((!exitg1) && (c_nx <= maxdimlen)) {
        if (!muDoubleScalarIsNaN(Ux_ex_data[c_nx - 1])) {
          b_nx = c_nx;
          exitg1 = true;
        } else {
          c_nx++;
        }
      }
    }
    if (b_nx == 0) {
      errors->SUPE = Ux_ex_data[0];
    } else {
      g_st.site = &xm_emlrtRSI;
      c_b = Ux_ex_data[b_nx - 1];
      loop_ub = b_nx + 1;
      h_st.site = &bn_emlrtRSI;
      overflow =
          ((b_nx + 1 <= Ux_ex->size[0]) && (Ux_ex->size[0] > 2147483646));
      if (overflow) {
        i_st.site = &m_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      for (c_nx = loop_ub; c_nx <= maxdimlen; c_nx++) {
        b = Ux_ex_data[c_nx - 1];
        if (c_b < b) {
          c_b = b;
        }
      }
      errors->SUPE = c_b;
    }
  }
  emxFree_real_T(&f_st, &Ux_ex);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void plus(const emlrtStack *sp, emxArray_real_T *r4, const emxArray_real_T *r5)
{
  emxArray_real_T *r2;
  const real_T *r;
  real_T *r1;
  real_T *r3;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  r = r5->data;
  r1 = r4->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &r2, 1, &fi_emlrtRTEI);
  i = r2->size[0];
  if (r5->size[0] == 1) {
    r2->size[0] = r4->size[0];
  } else {
    r2->size[0] = r5->size[0];
  }
  emxEnsureCapacity_real_T(sp, r2, i, &fi_emlrtRTEI);
  r3 = r2->data;
  stride_0_0 = (r4->size[0] != 1);
  stride_1_0 = (r5->size[0] != 1);
  if (r5->size[0] == 1) {
    loop_ub = r4->size[0];
  } else {
    loop_ub = r5->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    r3[i] = r1[i * stride_0_0] + r[i * stride_1_0];
  }
  i = r4->size[0];
  r4->size[0] = r2->size[0];
  emxEnsureCapacity_real_T(sp, r4, i, &fi_emlrtRTEI);
  r1 = r4->data;
  loop_ub = r2->size[0];
  for (i = 0; i < loop_ub; i++) {
    r1[i] = r3[i];
  }
  emxFree_real_T(sp, &r2);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (ComputeErrors.c) */
