/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main_data.c
 *
 * Code generation for function 'main_data'
 *
 */

/* Include files */
#include "main_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131611U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "main",                                               /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

emlrtRSInfo k_emlrtRSI = {
    42,         /* lineNo */
    "linspace", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\elmat\\linspace.m" /* pathName
                                                                           */
};

emlrtRSInfo m_emlrtRSI = {
    21,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_"
    "overflow_check.m" /* pathName */
};

emlrtRSInfo v_emlrtRSI =
    {
        117,     /* lineNo */
        "colon", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" /* pathName
                                                                          */
};

emlrtRSInfo y_emlrtRSI =
    {
        28,      /* lineNo */
        "colon", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" /* pathName
                                                                          */
};

emlrtRSInfo mc_emlrtRSI = {
    44,       /* lineNo */
    "mpower", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m" /* pathName
                                                                          */
};

emlrtRSInfo nc_emlrtRSI =
    {
        71,      /* lineNo */
        "power", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\power.m" /* pathName
                                                                          */
};

emlrtRSInfo pd_emlrtRSI = {
    7,         /* lineNo */
    "getTime", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\+time\\getTime.m" /* pathName */
};

emlrtRSInfo qd_emlrtRSI = {
    21,                     /* lineNo */
    "CoderTimeAPI/getTime", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\+time\\CoderTimeAPI.m" /* pathName */
};

emlrtRSInfo rd_emlrtRSI = {
    148,                                  /* lineNo */
    "CoderTimeAPI/callEMLRTClockGettime", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\+time\\CoderTimeAPI.m" /* pathName */
};

emlrtRSInfo yd_emlrtRSI = {
    142,             /* lineNo */
    "sparse/sparse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

emlrtRSInfo ae_emlrtRSI = {
    143,             /* lineNo */
    "sparse/sparse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

emlrtRSInfo ee_emlrtRSI = {
    219,             /* lineNo */
    "sparse/sparse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

emlrtRSInfo ve_emlrtRSI = {
    15,    /* lineNo */
    "max", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" /* pathName
                                                                        */
};

emlrtRSInfo we_emlrtRSI =
    {
        44,         /* lineNo */
        "minOrMax", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

emlrtRSInfo xe_emlrtRSI =
    {
        79,        /* lineNo */
        "maximum", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

emlrtRSInfo ff_emlrtRSI = {
    38,        /* lineNo */
    "fprintf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m" /* pathName
                                                                          */
};

emlrtRSInfo tf_emlrtRSI = {
    176,             /* lineNo */
    "sparse/sparse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

emlrtRSInfo uf_emlrtRSI = {
    227,                         /* lineNo */
    "sparseSparseEqHeightBinOp", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" /* pathName */
};

emlrtRSInfo oh_emlrtRSI = {
    63,                               /* lineNo */
    "function_handle/parenReference", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\function_"
    "handle.m" /* pathName */
};

emlrtRSInfo dk_emlrtRSI = {
    53,             /* lineNo */
    "SolutionEval", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m" /* pathName */
};

emlrtRSInfo ek_emlrtRSI = {
    58,             /* lineNo */
    "SolutionEval", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m" /* pathName */
};

emlrtRSInfo fk_emlrtRSI = {
    60,             /* lineNo */
    "SolutionEval", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m" /* pathName */
};

emlrtRSInfo gk_emlrtRSI = {
    61,             /* lineNo */
    "SolutionEval", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m" /* pathName */
};

emlrtRSInfo hk_emlrtRSI =
    {
        90,                  /* lineNo */
        "eml_mtimes_helper", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" /* pathName */
};

emlrtMCInfo e_emlrtMCI = {
    66,        /* lineNo */
    18,        /* colNo */
    "fprintf", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m" /* pName
                                                                          */
};

emlrtRTEInfo emlrtRTEI = {
    33,         /* lineNo */
    37,         /* colNo */
    "linspace", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\elmat\\linspace.m" /* pName
                                                                           */
};

emlrtECInfo emlrtECI = {
    -1,             /* nDims */
    64,             /* lineNo */
    13,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m" /* pName */
};

emlrtECInfo b_emlrtECI = {
    -1,             /* nDims */
    63,             /* lineNo */
    13,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m" /* pName */
};

emlrtECInfo c_emlrtECI = {
    -1,             /* nDims */
    62,             /* lineNo */
    13,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m" /* pName */
};

emlrtBCInfo emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    56,             /* lineNo */
    30,             /* colNo */
    "tt",           /* aName */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    0                                                /* checkKind */
};

emlrtBCInfo b_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    55,             /* lineNo */
    30,             /* colNo */
    "xx",           /* aName */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    0                                                /* checkKind */
};

emlrtDCInfo emlrtDCI = {
    55,             /* lineNo */
    30,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    1                                                /* checkKind */
};

emlrtBCInfo c_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    52,             /* lineNo */
    32,             /* colNo */
    "elms",         /* aName */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    0                                                /* checkKind */
};

emlrtBCInfo d_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    51,             /* lineNo */
    34,             /* colNo */
    "pivots",       /* aName */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    0                                                /* checkKind */
};

emlrtDCInfo b_emlrtDCI = {
    51,             /* lineNo */
    34,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    1                                                /* checkKind */
};

emlrtRTEInfo b_emlrtRTEI = {
    48,             /* lineNo */
    17,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m" /* pName */
};

emlrtRTEInfo c_emlrtRTEI = {
    47,             /* lineNo */
    13,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m" /* pName */
};

emlrtDCInfo c_emlrtDCI = {
    44,             /* lineNo */
    15,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    1                                                /* checkKind */
};

emlrtDCInfo d_emlrtDCI = {
    44,             /* lineNo */
    15,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    4                                                /* checkKind */
};

emlrtDCInfo e_emlrtDCI = {
    44,             /* lineNo */
    24,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    1                                                /* checkKind */
};

emlrtDCInfo f_emlrtDCI = {
    44,             /* lineNo */
    24,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    4                                                /* checkKind */
};

emlrtDCInfo g_emlrtDCI = {
    45,             /* lineNo */
    15,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    1                                                /* checkKind */
};

emlrtDCInfo h_emlrtDCI = {
    45,             /* lineNo */
    24,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    1                                                /* checkKind */
};

emlrtDCInfo i_emlrtDCI = {
    46,             /* lineNo */
    15,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    1                                                /* checkKind */
};

emlrtDCInfo j_emlrtDCI = {
    46,             /* lineNo */
    24,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    1                                                /* checkKind */
};

emlrtDCInfo o_emlrtDCI = {
    44,             /* lineNo */
    5,              /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    1                                                /* checkKind */
};

emlrtDCInfo p_emlrtDCI = {
    45,             /* lineNo */
    5,              /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    1                                                /* checkKind */
};

emlrtDCInfo q_emlrtDCI = {
    46,             /* lineNo */
    5,              /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    1                                                /* checkKind */
};

emlrtBCInfo e_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    58,             /* lineNo */
    33,             /* colNo */
    "u",            /* aName */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    0                                                /* checkKind */
};

emlrtDCInfo r_emlrtDCI = {
    58,             /* lineNo */
    33,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    1                                                /* checkKind */
};

emlrtDCInfo s_emlrtDCI = {
    62,             /* lineNo */
    15,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    1                                                /* checkKind */
};

emlrtBCInfo f_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    62,             /* lineNo */
    15,             /* colNo */
    "U",            /* aName */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    0                                                /* checkKind */
};

emlrtDCInfo t_emlrtDCI = {
    62,             /* lineNo */
    18,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    1                                                /* checkKind */
};

emlrtBCInfo g_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    62,             /* lineNo */
    18,             /* colNo */
    "U",            /* aName */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    0                                                /* checkKind */
};

emlrtBCInfo h_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    63,             /* lineNo */
    15,             /* colNo */
    "X",            /* aName */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    0                                                /* checkKind */
};

emlrtBCInfo i_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    63,             /* lineNo */
    18,             /* colNo */
    "X",            /* aName */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    0                                                /* checkKind */
};

emlrtBCInfo j_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    64,             /* lineNo */
    15,             /* colNo */
    "T",            /* aName */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    0                                                /* checkKind */
};

emlrtBCInfo k_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    64,             /* lineNo */
    18,             /* colNo */
    "T",            /* aName */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m", /* pName */
    0                                                /* checkKind */
};

emlrtRTEInfo g_emlrtRTEI = {
    159,                    /* lineNo */
    13,                     /* colNo */
    "coderTimeCheckStatus", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\+time\\CoderTimeAPI.m" /* pName */
};

emlrtRTEInfo l_emlrtRTEI = {
    1612,              /* lineNo */
    9,                 /* colNo */
    "assertValidSize", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pName */
};

emlrtRTEInfo m_emlrtRTEI = {
    1615,              /* lineNo */
    31,                /* colNo */
    "assertValidSize", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pName */
};

emlrtRTEInfo tb_emlrtRTEI = {
    49,         /* lineNo */
    20,         /* colNo */
    "linspace", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\elmat\\linspace.m" /* pName
                                                                           */
};

emlrtRTEInfo yb_emlrtRTEI = {
    21,             /* lineNo */
    5,              /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m" /* pName */
};

emlrtRTEInfo ac_emlrtRTEI = {
    22,             /* lineNo */
    5,              /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m" /* pName */
};

emlrtRTEInfo bc_emlrtRTEI = {
    44,             /* lineNo */
    5,              /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m" /* pName */
};

emlrtRTEInfo cc_emlrtRTEI = {
    45,             /* lineNo */
    5,              /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m" /* pName */
};

emlrtRTEInfo dc_emlrtRTEI = {
    46,             /* lineNo */
    5,              /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m" /* pName */
};

emlrtRTEInfo ec_emlrtRTEI = {
    60,             /* lineNo */
    13,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m" /* pName */
};

emlrtRTEInfo fc_emlrtRTEI = {
    61,             /* lineNo */
    13,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m" /* pName */
};

emlrtRTEInfo gc_emlrtRTEI = {
    62,             /* lineNo */
    15,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m" /* pName */
};

emlrtRTEInfo hc_emlrtRTEI = {
    62,             /* lineNo */
    18,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m" /* pName */
};

emlrtRTEInfo ic_emlrtRTEI = {
    63,             /* lineNo */
    15,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m" /* pName */
};

emlrtRTEInfo jc_emlrtRTEI = {
    63,             /* lineNo */
    18,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m" /* pName */
};

emlrtRTEInfo kc_emlrtRTEI = {
    64,             /* lineNo */
    15,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m" /* pName */
};

emlrtRTEInfo lc_emlrtRTEI = {
    64,             /* lineNo */
    18,             /* colNo */
    "SolutionEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolutionEval.m" /* pName */
};

emlrtRTEInfo ce_emlrtRTEI = {
    193,      /* lineNo */
    42,       /* colNo */
    "sparse", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pName */
};

emlrtRTEInfo tg_emlrtRTEI = {
    21,     /* lineNo */
    23,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

emlrtRTEInfo ug_emlrtRTEI = {
    21,     /* lineNo */
    42,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

emlrtRTEInfo bh_emlrtRTEI = {
    22,     /* lineNo */
    27,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

emlrtRTEInfo ch_emlrtRTEI = {
    22,     /* lineNo */
    47,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

emlrtRTEInfo fh_emlrtRTEI =
    {
        76,                  /* lineNo */
        13,                  /* colNo */
        "eml_mtimes_helper", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" /* pName */
};

const int8_T iv[16] = {0, 4, 1, 5, 8, 12, 9, 13, 2, 6, 3, 7, 10, 14, 11, 15};

const char_T cv[26] = {'e', 'm', 'l', 'r', 't', 'C', 'l', 'o', 'c',
                       'k', 'G', 'e', 't', 't', 'i', 'm', 'e', 'M',
                       'o', 'n', 'o', 't', 'o', 'n', 'i', 'c'};

const real_T dv[8] = {0.050614268145188393, 0.11119051722668723,
                      0.15685332293894372,  0.18134189168918097,
                      0.18134189168918097,  0.15685332293894372,
                      0.11119051722668723,  0.050614268145188393};

const real_T dv1[8] = {0.019855071751231856, 0.10166676129318658,
                       0.2372337950418355,   0.40828267875217511,
                       0.59171732124782483,  0.7627662049581645,
                       0.89833323870681348,  0.9801449282487682};

const real_T dv2[32] = {
    -0.11676508726191175,  -0.54798378564804484, -1.0857235291913034,
    -1.4495275978987396,   -1.44952759789874,    -1.0857235291913039,
    -0.54798378564804473,  -0.11676508726191148, 0.11676508726191175,
    0.54798378564804484,   1.0857235291913034,   1.4495275978987396,
    1.44952759789874,      1.0857235291913039,   0.54798378564804473,
    0.11676508726191148,   0.92176238461781224,  0.624341345882791,
    0.21990444036251278,   -0.13304647770154499, -0.31648112019719488,
    -0.30562796955381621,  -0.17232513153083584, -0.03852747187972394,
    -0.038527471879724016, -0.17232513153083581, -0.30562796955381616,
    -0.31648112019719477,  -0.13304647770154521, 0.21990444036251278,
    0.62434134588279111,   0.92176238461781246};

const real_T dv3[32] = {
    0.99883298306387869,     0.97109329073881534,    0.85786335542462577,
    0.63603291736584711,     0.36396708263415312,    0.14213664457537434,
    0.028906709261184549,    0.0011670169361213123,  0.0011670169361212674,
    0.028906709261184611,    0.14213664457537428,    0.36396708263415289,
    0.63603291736584688,     0.85786335542462566,    0.97109329073881545,
    0.99883298306387869,     0.01907445134604794,    0.082045341486671391,
    0.13802553599917256,     0.14295176455057274,    0.098636168432550575,
    0.042928385532711388,    0.0092852894546693321,  0.00038639653093730519,
    -0.00038639653093735111, -0.0092852894546694154, -0.042928385532711326,
    -0.098636168432550547,   -0.14295176455057274,   -0.1380255359991725,
    -0.082045341486671419,   -0.019074451346047905};

const real_T dv4[32] = {
    -5.7617391389852175, -4.7799988644817608, -3.1531944594979739,
    -1.1006078549738989, 1.100607854973898,   3.1531944594979748,
    4.7799988644817617,  5.7617391389852184,  5.7617391389852175,
    4.7799988644817608,  3.1531944594979739,  1.1006078549738989,
    -1.100607854973898,  -3.1531944594979748, -4.7799988644817617,
    -5.7617391389852184, -3.8808695694926088, -3.3899994322408804,
    -2.576597229748987,  -1.5503039274869495, -0.449696072513051,
    0.57659722974898742, 1.3899994322408809,  1.8808695694926092,
    -1.8808695694926088, -1.3899994322408804, -0.576597229748987,
    0.44969607251305055, 1.550303927486949,   2.5765972297489874,
    3.3899994322408809,  3.8808695694926092};

emlrtRSInfo dn_emlrtRSI = {
    66,        /* lineNo */
    "fprintf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m" /* pathName
                                                                          */
};

emlrtRSInfo kn_emlrtRSI =
    {
        76,                  /* lineNo */
        "eml_mtimes_helper", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" /* pathName */
};

covrtInstance emlrtCoverageInstance;

/* End of code generation (main_data.c) */
