/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/* Include files */
#include "main.h"
#include "CartesianMesh.h"
#include "ComputeErrors.h"
#include "SolverWaves.h"
#include "colon.h"
#include "eml_mtimes_helper.h"
#include "exp.h"
#include "function_handle.h"
#include "indexShapeCheck.h"
#include "kron.h"
#include "linspace.h"
#include "main_data.h"
#include "main_emxutil.h"
#include "main_internal_types.h"
#include "main_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Type Definitions */
#ifndef typedef_rtString
#define typedef_rtString
typedef struct {
  char_T Value;
} rtString;
#endif /* typedef_rtString */

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    32,     /* lineNo */
    "main", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    34,     /* lineNo */
    "main", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    36,     /* lineNo */
    "main", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    39,     /* lineNo */
    "main", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    42,     /* lineNo */
    "main", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    48,     /* lineNo */
    "main", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    14,               /* lineNo */
    "Discretization", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\Discretization.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    15,               /* lineNo */
    "Discretization", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\Discretization.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    19,               /* lineNo */
    "Discretization", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\Discretization.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    20,               /* lineNo */
    "Discretization", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\Discretization.m" /* pathName */
};

static emlrtRSInfo qh_emlrtRSI = {
    12,                         /* lineNo */
    "@(x)dn(x,0.1)-dn(x,-0.1)", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pathName */
};

static emlrtRSInfo am_emlrtRSI = {
    21,                              /* lineNo */
    "@(x,t)w(x-c*t)+phi*w(2-x-c*t)", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pathName */
};

static emlrtRSInfo bm_emlrtRSI = {
    11,                       /* lineNo */
    "@(x)n(x,0.1)-n(x,-0.1)", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pathName */
};

static emlrtRSInfo cm_emlrtRSI = {
    6,                        /* lineNo */
    "@(x,c)exp(-a*(x-c).^2)", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pathName */
};

static emlrtRSInfo fm_emlrtRSI = {
    22,                                /* lineNo */
    "@(x,t)dw(x-c*t)-phi*dw(2-x-c*t)", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pathName */
};

static emlrtRSInfo gm_emlrtRSI = {
    7,                                     /* lineNo */
    "@(x,c)a*exp(-a*(c-x).^2).*(2*c-2*x)", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pathName */
};

static emlrtRSInfo hm_emlrtRSI = {
    23,                                     /* lineNo */
    "@(x,t)-c*dw(x-c*t)-c*phi*dw(2-x-c*t)", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pathName */
};

static emlrtRSInfo im_emlrtRSI = {
    24,                                  /* lineNo */
    "@(x,t)ddw(x-c*t)+phi*ddw(2-x-c*t)", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pathName */
};

static emlrtRSInfo jm_emlrtRSI = {
    13,                           /* lineNo */
    "@(x)ddn(x,0.1)-ddn(x,-0.1)", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pathName */
};

static emlrtRSInfo km_emlrtRSI = {
    8, /* lineNo */
    "@(x,c)a^2*exp(-a*(c-x).^2).*(2*c-2*x).^2-2*a*exp(-a*(c-x).^2)", /* fcnName
                                                                      */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pathName */
};

static emlrtRSInfo lm_emlrtRSI = {
    9, /* lineNo */
    "@(x,c)a^2*exp(-a*(c-x).^2).*(2*c-2*x).^2-2*a*exp(-a*(c-x).^2)", /* fcnName
                                                                      */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pathName */
};

static emlrtRSInfo mm_emlrtRSI = {
    25,                                        /* lineNo */
    "@(x,t)c^2*(ddw(x-c*t)+phi*ddw(2-x-c*t))", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pathName */
};

static emlrtMCInfo emlrtMCI = {
    43,     /* lineNo */
    5,      /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtMCInfo b_emlrtMCI = {
    44,     /* lineNo */
    5,      /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtMCInfo c_emlrtMCI = {
    45,     /* lineNo */
    5,      /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtMCInfo d_emlrtMCI = {
    45,     /* lineNo */
    18,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtDCInfo k_emlrtDCI = {
    19,               /* lineNo */
    25,               /* colNo */
    "Discretization", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\Discretization.m", /* pName */
    1                                                  /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = {
    19,               /* lineNo */
    25,               /* colNo */
    "Discretization", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\Discretization.m", /* pName */
    4                                                  /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = {
    20,               /* lineNo */
    37,               /* colNo */
    "Discretization", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\Discretization.m", /* pName */
    1                                                  /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = {
    20,               /* lineNo */
    37,               /* colNo */
    "Discretization", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\Discretization.m", /* pName */
    4                                                  /* checkKind */
};

static emlrtECInfo v_emlrtECI = {
    1,                               /* nDims */
    21,                              /* lineNo */
    23,                              /* colNo */
    "@(x,t)w(x-c*t)+phi*w(2-x-c*t)", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtECInfo w_emlrtECI = {
    1,                               /* nDims */
    21,                              /* lineNo */
    21,                              /* colNo */
    "@(x,t)w(x-c*t)+phi*w(2-x-c*t)", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtECInfo x_emlrtECI = {
    1,                        /* nDims */
    11,                       /* lineNo */
    16,                       /* colNo */
    "@(x)n(x,0.1)-n(x,-0.1)", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtECInfo y_emlrtECI = {
    1,                                 /* nDims */
    22,                                /* lineNo */
    27,                                /* colNo */
    "@(x,t)dw(x-c*t)-phi*dw(2-x-c*t)", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtECInfo ab_emlrtECI = {
    1,                                 /* nDims */
    22,                                /* lineNo */
    24,                                /* colNo */
    "@(x,t)dw(x-c*t)-phi*dw(2-x-c*t)", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtECInfo bb_emlrtECI = {
    1,                                     /* nDims */
    7,                                     /* lineNo */
    19,                                    /* colNo */
    "@(x,c)a*exp(-a*(c-x).^2).*(2*c-2*x)", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtECInfo cb_emlrtECI = {
    1,                          /* nDims */
    12,                         /* lineNo */
    16,                         /* colNo */
    "@(x)dn(x,0.1)-dn(x,-0.1)", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtECInfo db_emlrtECI = {
    1,                                      /* nDims */
    23,                                     /* lineNo */
    32,                                     /* colNo */
    "@(x,t)-c*dw(x-c*t)-c*phi*dw(2-x-c*t)", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtECInfo eb_emlrtECI = {
    1,                                      /* nDims */
    23,                                     /* lineNo */
    24,                                     /* colNo */
    "@(x,t)-c*dw(x-c*t)-c*phi*dw(2-x-c*t)", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtECInfo fb_emlrtECI = {
    1,                                   /* nDims */
    24,                                  /* lineNo */
    29,                                  /* colNo */
    "@(x,t)ddw(x-c*t)+phi*ddw(2-x-c*t)", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtECInfo gb_emlrtECI = {
    1,                                   /* nDims */
    24,                                  /* lineNo */
    25,                                  /* colNo */
    "@(x,t)ddw(x-c*t)+phi*ddw(2-x-c*t)", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtECInfo hb_emlrtECI = {
    1,                            /* nDims */
    13,                           /* lineNo */
    16,                           /* colNo */
    "@(x)ddn(x,0.1)-ddn(x,-0.1)", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtECInfo ib_emlrtECI = {
    1,                                         /* nDims */
    25,                                        /* lineNo */
    30,                                        /* colNo */
    "@(x,t)c^2*(ddw(x-c*t)+phi*ddw(2-x-c*t))", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtECInfo jb_emlrtECI = {
    1,                                         /* nDims */
    25,                                        /* lineNo */
    34,                                        /* colNo */
    "@(x,t)c^2*(ddw(x-c*t)+phi*ddw(2-x-c*t))", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtECInfo kb_emlrtECI = {
    1,  /* nDims */
    8,  /* lineNo */
    19, /* colNo */
    "@(x,c)a^2*exp(-a*(c-x).^2).*(2*c-2*x).^2-2*a*exp(-a*(c-x).^2)", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = {
    15,               /* lineNo */
    5,                /* colNo */
    "Discretization", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\Discretization.m" /* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = {
    19,               /* lineNo */
    20,               /* colNo */
    "Discretization", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\Discretization.m" /* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = {
    20,               /* lineNo */
    29,               /* colNo */
    "Discretization", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\Discretization.m" /* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = {
    39,     /* lineNo */
    9,      /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo mc_emlrtRTEI = {
    36,     /* lineNo */
    5,      /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo nc_emlrtRTEI = {
    1,      /* lineNo */
    16,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo oc_emlrtRTEI = {
    36,     /* lineNo */
    12,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo sg_emlrtRTEI = {
    21,     /* lineNo */
    27,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo vg_emlrtRTEI = {
    21,     /* lineNo */
    40,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo wg_emlrtRTEI = {
    6,      /* lineNo */
    27,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo xg_emlrtRTEI =
    {
        31,            /* lineNo */
        30,            /* colNo */
        "unsafeSxfun", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\unsafeSxfun.m" /* pName */
};

static emlrtRTEInfo ah_emlrtRTEI = {
    22,     /* lineNo */
    31,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo dh_emlrtRTEI = {
    22,     /* lineNo */
    44,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo eh_emlrtRTEI = {
    7,      /* lineNo */
    29,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo gh_emlrtRTEI = {
    23,     /* lineNo */
    36,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo hh_emlrtRTEI = {
    23,     /* lineNo */
    32,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo ih_emlrtRTEI = {
    23,     /* lineNo */
    56,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo jh_emlrtRTEI = {
    23,     /* lineNo */
    53,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo kh_emlrtRTEI = {
    24,     /* lineNo */
    33,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo lh_emlrtRTEI = {
    24,     /* lineNo */
    29,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo mh_emlrtRTEI = {
    24,     /* lineNo */
    50,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo nh_emlrtRTEI = {
    24,     /* lineNo */
    18,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo oh_emlrtRTEI = {
    25,     /* lineNo */
    38,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo ph_emlrtRTEI = {
    25,     /* lineNo */
    34,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo qh_emlrtRTEI = {
    25,     /* lineNo */
    55,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo rh_emlrtRTEI = {
    25,     /* lineNo */
    18,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo th_emlrtRTEI = {
    8,      /* lineNo */
    31,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo uh_emlrtRTEI = {
    8,      /* lineNo */
    44,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo vh_emlrtRTEI = {
    9,      /* lineNo */
    33,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo hi_emlrtRTEI = {
    11,     /* lineNo */
    16,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo ii_emlrtRTEI = {
    7,      /* lineNo */
    19,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRTEInfo ji_emlrtRTEI = {
    8,      /* lineNo */
    19,     /* colNo */
    "main", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pName */
};

static emlrtRSInfo cn_emlrtRSI = {
    45,     /* lineNo */
    "main", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pathName */
};

static emlrtRSInfo fn_emlrtRSI = {
    43,     /* lineNo */
    "main", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pathName */
};

static emlrtRSInfo gn_emlrtRSI = {
    44,     /* lineNo */
    "main", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\main.m" /* pathName */
};

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp,
                                          const rtString u);

static void b_minus(const emlrtStack *sp, emxArray_real_T *varargin_1,
                    const emxArray_real_T *x,
                    const emxArray_real_T *b_varargin_1);

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);

static void main_anonFcn3(const emlrtStack *sp, const emxArray_real_T *x,
                          real_T c, emxArray_real_T *varargout_1);

static void minus(const emlrtStack *sp, emxArray_real_T *varargout_1,
                  const emxArray_real_T *a);

static void n_binary_expand_op(const emlrtStack *sp, emxArray_real_T *a,
                               const emxArray_real_T *r1);

static void o_binary_expand_op(const emlrtStack *sp,
                               emxArray_real_T *varargout_1,
                               const emxArray_real_T *r1);

static void q_binary_expand_op(const emlrtStack *sp,
                               emxArray_real_T *varargin_1,
                               const emxArray_real_T *x);

static void shading(const emlrtStack *sp, const mxArray *m,
                    emlrtMCInfo *location);

static void surf(const emlrtStack *sp, const mxArray *m, const mxArray *m1,
                 const mxArray *m2, emlrtMCInfo *location);

static void times(const emlrtStack *sp, emxArray_real_T *varargout_1,
                  const emxArray_real_T *a);

static void xlabel(const emlrtStack *sp, const mxArray *m,
                   emlrtMCInfo *location);

static void ylabel(const emlrtStack *sp, const mxArray *m,
                   emlrtMCInfo *location);

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp,
                                          const rtString u)
{
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *propValues;
  const mxArray *y;
  const char_T *propClasses = "coder.internal.string";
  const char_T *propNames = "Value";
  y = NULL;
  m = NULL;
  emlrtAssign(
      &y, emlrtCreateClassInstance((const char_T *)"coder.internal.string"));
  m = NULL;
  b_y = NULL;
  propValues = emlrtCreateString1(u.Value);
  emlrtAssign(&b_y, propValues);
  emlrtAssign(&m, b_y);
  propValues = m;
  emlrtSetAllProperties((emlrtCTX)sp, &y, 0, 1, (const char_T **)&propNames,
                        (const char_T **)&propClasses, &propValues);
  emlrtAssign(&y,
              emlrtConvertInstanceToRedirectSource(
                  (emlrtCTX)sp, y, 0, (const char_T *)"coder.internal.string"));
  return y;
}

static void b_minus(const emlrtStack *sp, emxArray_real_T *varargin_1,
                    const emxArray_real_T *x,
                    const emxArray_real_T *b_varargin_1)
{
  const real_T *varargin_1_data;
  const real_T *x_data;
  real_T *b_varargin_1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  varargin_1_data = b_varargin_1->data;
  x_data = x->data;
  i = varargin_1->size[0];
  if (b_varargin_1->size[0] == 1) {
    varargin_1->size[0] = x->size[0];
  } else {
    varargin_1->size[0] = b_varargin_1->size[0];
  }
  emxEnsureCapacity_real_T(sp, varargin_1, i, &lh_emlrtRTEI);
  b_varargin_1_data = varargin_1->data;
  stride_0_0 = (x->size[0] != 1);
  stride_1_0 = (b_varargin_1->size[0] != 1);
  if (b_varargin_1->size[0] == 1) {
    loop_ub = x->size[0];
  } else {
    loop_ub = b_varargin_1->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    b_varargin_1_data[i] =
        x_data[i * stride_0_0] - varargin_1_data[i * stride_1_0];
  }
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *m;
  const mxArray *y;
  const real_T *u_data;
  real_T *pData;
  int32_T b_iv[2];
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  u_data = u->data;
  y = NULL;
  b_iv[0] = u->size[0];
  b_iv[1] = u->size[1];
  m = emlrtCreateNumericArray(2, &b_iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < u->size[1]; b_i++) {
    for (c_i = 0; c_i < u->size[0]; c_i++) {
      pData[i] = u_data[c_i + u->size[0] * b_i];
      i++;
    }
  }
  emlrtAssign(&y, m);
  return y;
}

static void main_anonFcn3(const emlrtStack *sp, const emxArray_real_T *x,
                          real_T c, emxArray_real_T *varargout_1)
{
  emlrtStack st;
  emxArray_real_T *a;
  const real_T *x_data;
  real_T varargin_1;
  real_T *a_data;
  real_T *varargout_1_data;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &a, 1, &th_emlrtRTEI);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 3U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 3U);
  st.site = &km_emlrtRSI;
  i = a->size[0];
  a->size[0] = x->size[0];
  emxEnsureCapacity_real_T(&st, a, i, &th_emlrtRTEI);
  a_data = a->data;
  loop_ub = x->size[0];
  for (i = 0; i < loop_ub; i++) {
    a_data[i] = c - x_data[i];
  }
  i = varargout_1->size[0];
  varargout_1->size[0] = a->size[0];
  emxEnsureCapacity_real_T(sp, varargout_1, i, &xg_emlrtRTEI);
  varargout_1_data = varargout_1->data;
  loop_ub = a->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargin_1 = a_data[i];
    varargout_1_data[i] = varargin_1 * varargin_1;
  }
  loop_ub = varargout_1->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargout_1_data[i] *= -20.0;
  }
  st.site = &km_emlrtRSI;
  b_exp(&st, varargout_1);
  varargout_1_data = varargout_1->data;
  loop_ub = varargout_1->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargout_1_data[i] *= 400.0;
  }
  st.site = &km_emlrtRSI;
  varargin_1 = 2.0 * c;
  i = a->size[0];
  a->size[0] = x->size[0];
  emxEnsureCapacity_real_T(&st, a, i, &uh_emlrtRTEI);
  a_data = a->data;
  loop_ub = x->size[0];
  for (i = 0; i < loop_ub; i++) {
    a_data[i] = varargin_1 - 2.0 * x_data[i];
  }
  loop_ub = a->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargin_1 = a_data[i];
    a_data[i] = varargin_1 * varargin_1;
  }
  if ((varargout_1->size[0] != a->size[0]) &&
      ((varargout_1->size[0] != 1) && (a->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(varargout_1->size[0], a->size[0], &kb_emlrtECI,
                                (emlrtCTX)sp);
  }
  if (varargout_1->size[0] == a->size[0]) {
    loop_ub = varargout_1->size[0];
    for (i = 0; i < loop_ub; i++) {
      varargout_1_data[i] *= a_data[i];
    }
  } else {
    st.site = &km_emlrtRSI;
    times(&st, varargout_1, a);
    varargout_1_data = varargout_1->data;
  }
  st.site = &lm_emlrtRSI;
  i = a->size[0];
  a->size[0] = x->size[0];
  emxEnsureCapacity_real_T(&st, a, i, &vh_emlrtRTEI);
  a_data = a->data;
  loop_ub = x->size[0];
  for (i = 0; i < loop_ub; i++) {
    a_data[i] = c - x_data[i];
  }
  loop_ub = a->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargin_1 = a_data[i];
    a_data[i] = varargin_1 * varargin_1;
  }
  loop_ub = a->size[0];
  for (i = 0; i < loop_ub; i++) {
    a_data[i] *= -20.0;
  }
  st.site = &lm_emlrtRSI;
  b_exp(&st, a);
  a_data = a->data;
  loop_ub = a->size[0];
  for (i = 0; i < loop_ub; i++) {
    a_data[i] *= 40.0;
  }
  if ((varargout_1->size[0] != a->size[0]) &&
      ((varargout_1->size[0] != 1) && (a->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(varargout_1->size[0], a->size[0], &kb_emlrtECI,
                                (emlrtCTX)sp);
  }
  if (varargout_1->size[0] == a->size[0]) {
    loop_ub = varargout_1->size[0];
    for (i = 0; i < loop_ub; i++) {
      varargout_1_data[i] -= a_data[i];
    }
  } else {
    st.site = &km_emlrtRSI;
    minus(&st, varargout_1, a);
  }
  emxFree_real_T(sp, &a);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void minus(const emlrtStack *sp, emxArray_real_T *varargout_1,
                  const emxArray_real_T *a)
{
  emxArray_real_T *b_varargout_1;
  const real_T *a_data;
  real_T *b_varargout_1_data;
  real_T *varargout_1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  a_data = a->data;
  varargout_1_data = varargout_1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_varargout_1, 1, &hi_emlrtRTEI);
  i = b_varargout_1->size[0];
  if (a->size[0] == 1) {
    b_varargout_1->size[0] = varargout_1->size[0];
  } else {
    b_varargout_1->size[0] = a->size[0];
  }
  emxEnsureCapacity_real_T(sp, b_varargout_1, i, &hi_emlrtRTEI);
  b_varargout_1_data = b_varargout_1->data;
  stride_0_0 = (varargout_1->size[0] != 1);
  stride_1_0 = (a->size[0] != 1);
  if (a->size[0] == 1) {
    loop_ub = varargout_1->size[0];
  } else {
    loop_ub = a->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    b_varargout_1_data[i] =
        varargout_1_data[i * stride_0_0] - a_data[i * stride_1_0];
  }
  i = varargout_1->size[0];
  varargout_1->size[0] = b_varargout_1->size[0];
  emxEnsureCapacity_real_T(sp, varargout_1, i, &hi_emlrtRTEI);
  varargout_1_data = varargout_1->data;
  loop_ub = b_varargout_1->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargout_1_data[i] = b_varargout_1_data[i];
  }
  emxFree_real_T(sp, &b_varargout_1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void n_binary_expand_op(const emlrtStack *sp, emxArray_real_T *a,
                               const emxArray_real_T *r1)
{
  emxArray_real_T *b_a;
  const real_T *r;
  real_T *a_data;
  real_T *b_a_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  r = r1->data;
  a_data = a->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_a, 1, &ii_emlrtRTEI);
  i = b_a->size[0];
  if (r1->size[0] == 1) {
    b_a->size[0] = a->size[0];
  } else {
    b_a->size[0] = r1->size[0];
  }
  emxEnsureCapacity_real_T(sp, b_a, i, &ii_emlrtRTEI);
  b_a_data = b_a->data;
  stride_0_0 = (a->size[0] != 1);
  stride_1_0 = (r1->size[0] != 1);
  if (r1->size[0] == 1) {
    loop_ub = a->size[0];
  } else {
    loop_ub = r1->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    b_a_data[i] = a_data[i * stride_0_0] * (-0.2 - r[i * stride_1_0]);
  }
  i = a->size[0];
  a->size[0] = b_a->size[0];
  emxEnsureCapacity_real_T(sp, a, i, &ii_emlrtRTEI);
  a_data = a->data;
  loop_ub = b_a->size[0];
  for (i = 0; i < loop_ub; i++) {
    a_data[i] = b_a_data[i];
  }
  emxFree_real_T(sp, &b_a);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void o_binary_expand_op(const emlrtStack *sp,
                               emxArray_real_T *varargout_1,
                               const emxArray_real_T *r1)
{
  emxArray_real_T *b_varargout_1;
  const real_T *r;
  real_T *b_varargout_1_data;
  real_T *varargout_1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  r = r1->data;
  varargout_1_data = varargout_1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_varargout_1, 1, &ii_emlrtRTEI);
  i = b_varargout_1->size[0];
  if (r1->size[0] == 1) {
    b_varargout_1->size[0] = varargout_1->size[0];
  } else {
    b_varargout_1->size[0] = r1->size[0];
  }
  emxEnsureCapacity_real_T(sp, b_varargout_1, i, &ii_emlrtRTEI);
  b_varargout_1_data = b_varargout_1->data;
  stride_0_0 = (varargout_1->size[0] != 1);
  stride_1_0 = (r1->size[0] != 1);
  if (r1->size[0] == 1) {
    loop_ub = varargout_1->size[0];
  } else {
    loop_ub = r1->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    b_varargout_1_data[i] =
        varargout_1_data[i * stride_0_0] * (0.2 - r[i * stride_1_0]);
  }
  i = varargout_1->size[0];
  varargout_1->size[0] = b_varargout_1->size[0];
  emxEnsureCapacity_real_T(sp, varargout_1, i, &ii_emlrtRTEI);
  varargout_1_data = varargout_1->data;
  loop_ub = b_varargout_1->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargout_1_data[i] = b_varargout_1_data[i];
  }
  emxFree_real_T(sp, &b_varargout_1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void q_binary_expand_op(const emlrtStack *sp,
                               emxArray_real_T *varargin_1,
                               const emxArray_real_T *x)
{
  emxArray_real_T *r;
  const real_T *x_data;
  real_T *r1;
  real_T *varargin_1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  x_data = x->data;
  varargin_1_data = varargin_1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &r, 1, &mh_emlrtRTEI);
  i = r->size[0];
  if (varargin_1->size[0] == 1) {
    r->size[0] = x->size[0];
  } else {
    r->size[0] = varargin_1->size[0];
  }
  emxEnsureCapacity_real_T(sp, r, i, &mh_emlrtRTEI);
  r1 = r->data;
  stride_0_0 = (x->size[0] != 1);
  stride_1_0 = (varargin_1->size[0] != 1);
  if (varargin_1->size[0] == 1) {
    loop_ub = x->size[0];
  } else {
    loop_ub = varargin_1->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    r1[i] = (2.0 - x_data[i * stride_0_0]) - varargin_1_data[i * stride_1_0];
  }
  i = varargin_1->size[0];
  varargin_1->size[0] = r->size[0];
  emxEnsureCapacity_real_T(sp, varargin_1, i, &mh_emlrtRTEI);
  varargin_1_data = varargin_1->data;
  loop_ub = r->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargin_1_data[i] = r1[i];
  }
  emxFree_real_T(sp, &r);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void shading(const emlrtStack *sp, const mxArray *m,
                    emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = m;
  emlrtCallMATLABR2012b((emlrtCTX)sp, 0, NULL, 1, &pArray,
                        (const char_T *)"shading", true, location);
}

static void surf(const emlrtStack *sp, const mxArray *m, const mxArray *m1,
                 const mxArray *m2, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  pArrays[0] = m;
  pArrays[1] = m1;
  pArrays[2] = m2;
  emlrtCallMATLABR2012b((emlrtCTX)sp, 0, NULL, 3, &pArrays[0],
                        (const char_T *)"surf", true, location);
}

static void times(const emlrtStack *sp, emxArray_real_T *varargout_1,
                  const emxArray_real_T *a)
{
  emxArray_real_T *b_varargout_1;
  const real_T *a_data;
  real_T *b_varargout_1_data;
  real_T *varargout_1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  a_data = a->data;
  varargout_1_data = varargout_1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_varargout_1, 1, &ji_emlrtRTEI);
  i = b_varargout_1->size[0];
  if (a->size[0] == 1) {
    b_varargout_1->size[0] = varargout_1->size[0];
  } else {
    b_varargout_1->size[0] = a->size[0];
  }
  emxEnsureCapacity_real_T(sp, b_varargout_1, i, &ji_emlrtRTEI);
  b_varargout_1_data = b_varargout_1->data;
  stride_0_0 = (varargout_1->size[0] != 1);
  stride_1_0 = (a->size[0] != 1);
  if (a->size[0] == 1) {
    loop_ub = varargout_1->size[0];
  } else {
    loop_ub = a->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    b_varargout_1_data[i] =
        varargout_1_data[i * stride_0_0] * a_data[i * stride_1_0];
  }
  i = varargout_1->size[0];
  varargout_1->size[0] = b_varargout_1->size[0];
  emxEnsureCapacity_real_T(sp, varargout_1, i, &ji_emlrtRTEI);
  varargout_1_data = varargout_1->data;
  loop_ub = b_varargout_1->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargout_1_data[i] = b_varargout_1_data[i];
  }
  emxFree_real_T(sp, &b_varargout_1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void xlabel(const emlrtStack *sp, const mxArray *m,
                   emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = m;
  emlrtCallMATLABR2012b((emlrtCTX)sp, 0, NULL, 1, &pArray,
                        (const char_T *)"xlabel", true, location);
}

static void ylabel(const emlrtStack *sp, const mxArray *m,
                   emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = m;
  emlrtCallMATLABR2012b((emlrtCTX)sp, 0, NULL, 1, &pArray,
                        (const char_T *)"ylabel", true, location);
}

void b_main_anonFcn5(const emlrtStack *sp, const emxArray_real_T *x,
                     emxArray_real_T *varargout_1)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_real_T *a;
  emxArray_real_T *r;
  const real_T *x_data;
  real_T varargin_1;
  real_T *a_data;
  real_T *r1;
  real_T *varargout_1_data;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &a, 1, &eh_emlrtRTEI);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 5U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 5U);
  st.site = &qh_emlrtRSI;
  b_st.site = &oh_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 0U, 2U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 2U);
  c_st.site = &gm_emlrtRSI;
  i = a->size[0];
  a->size[0] = x->size[0];
  emxEnsureCapacity_real_T(&c_st, a, i, &eh_emlrtRTEI);
  a_data = a->data;
  loop_ub = x->size[0];
  for (i = 0; i < loop_ub; i++) {
    a_data[i] = 0.1 - x_data[i];
  }
  i = varargout_1->size[0];
  varargout_1->size[0] = a->size[0];
  emxEnsureCapacity_real_T(&b_st, varargout_1, i, &xg_emlrtRTEI);
  varargout_1_data = varargout_1->data;
  loop_ub = a->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargin_1 = a_data[i];
    varargout_1_data[i] = varargin_1 * varargin_1;
  }
  loop_ub = varargout_1->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargout_1_data[i] *= -20.0;
  }
  c_st.site = &gm_emlrtRSI;
  b_exp(&c_st, varargout_1);
  varargout_1_data = varargout_1->data;
  loop_ub = varargout_1->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargout_1_data[i] *= 20.0;
  }
  emxInit_real_T(&b_st, &r, 1, &fh_emlrtRTEI);
  i = r->size[0];
  r->size[0] = x->size[0];
  emxEnsureCapacity_real_T(&b_st, r, i, &fh_emlrtRTEI);
  r1 = r->data;
  loop_ub = x->size[0];
  for (i = 0; i < loop_ub; i++) {
    r1[i] = 2.0 * x_data[i];
  }
  if ((varargout_1->size[0] != r->size[0]) &&
      ((varargout_1->size[0] != 1) && (r->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(varargout_1->size[0], r->size[0], &bb_emlrtECI,
                                &b_st);
  }
  if (varargout_1->size[0] == r->size[0]) {
    loop_ub = varargout_1->size[0];
    for (i = 0; i < loop_ub; i++) {
      varargout_1_data[i] *= 0.2 - r1[i];
    }
  } else {
    c_st.site = &gm_emlrtRSI;
    o_binary_expand_op(&c_st, varargout_1, r);
    varargout_1_data = varargout_1->data;
  }
  st.site = &qh_emlrtRSI;
  b_st.site = &oh_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 0U, 2U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 2U);
  c_st.site = &gm_emlrtRSI;
  i = a->size[0];
  a->size[0] = x->size[0];
  emxEnsureCapacity_real_T(&c_st, a, i, &eh_emlrtRTEI);
  a_data = a->data;
  loop_ub = x->size[0];
  for (i = 0; i < loop_ub; i++) {
    a_data[i] = -0.1 - x_data[i];
  }
  loop_ub = a->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargin_1 = a_data[i];
    a_data[i] = varargin_1 * varargin_1;
  }
  loop_ub = a->size[0];
  for (i = 0; i < loop_ub; i++) {
    a_data[i] *= -20.0;
  }
  c_st.site = &gm_emlrtRSI;
  b_exp(&c_st, a);
  a_data = a->data;
  loop_ub = a->size[0];
  for (i = 0; i < loop_ub; i++) {
    a_data[i] *= 20.0;
  }
  if ((a->size[0] != r->size[0]) && ((a->size[0] != 1) && (r->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(a->size[0], r->size[0], &bb_emlrtECI, &b_st);
  }
  if (a->size[0] == r->size[0]) {
    loop_ub = a->size[0];
    for (i = 0; i < loop_ub; i++) {
      a_data[i] *= -0.2 - r1[i];
    }
  } else {
    c_st.site = &gm_emlrtRSI;
    n_binary_expand_op(&c_st, a, r);
    a_data = a->data;
  }
  emxFree_real_T(&b_st, &r);
  if ((varargout_1->size[0] != a->size[0]) &&
      ((varargout_1->size[0] != 1) && (a->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(varargout_1->size[0], a->size[0], &cb_emlrtECI,
                                (emlrtCTX)sp);
  }
  if (varargout_1->size[0] == a->size[0]) {
    loop_ub = varargout_1->size[0];
    for (i = 0; i < loop_ub; i++) {
      varargout_1_data[i] -= a_data[i];
    }
  } else {
    st.site = &qh_emlrtRSI;
    minus(&st, varargout_1, a);
  }
  emxFree_real_T(sp, &a);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

real_T main(const emlrtStack *sp, real_T c, real_T theta, real_T T, real_T nx,
            real_T nt)
{
  static const real_T b_a[1296] = {0.99849604947263748,
                                   0.98019984181505138,
                                   0.90165844157265274,
                                   0.73411438409612717,
                                   0.49962387089505578,
                                   0.26513335769398422,
                                   0.097589300217458846,
                                   0.019047899975059998,
                                   0.0007516923174738792,
                                   0.98019984181505138,
                                   0.96223888957968373,
                                   0.88513666355265785,
                                   0.72066264412886571,
                                   0.49046888014931278,
                                   0.26027511616975957,
                                   0.095801096745967734,
                                   0.018698870718941565,
                                   0.00073791848357400739,
                                   0.90165844157265274,
                                   0.88513666355265785,
                                   0.81421248054873119,
                                   0.66291742651338437,
                                   0.45116861608181791,
                                   0.2394198056502512,
                                   0.088124751614904615,
                                   0.017200568610977782,
                                   0.000678790590982911,
                                   0.73411438409612717,
                                   0.72066264412886571,
                                   0.66291742651338437,
                                   0.53973566467435952,
                                   0.36733352170553379,
                                   0.19493137873670796,
                                   0.07174961689768318,
                                   0.014004399282201669,
                                   0.00055265931494028354,
                                   0.49962387089505578,
                                   0.49046888014931278,
                                   0.45116861608181791,
                                   0.36733352170553379,
                                   0.25,
                                   0.13266647829446609,
                                   0.048831383918182092,
                                   0.0095311198506871087,
                                   0.00037612910494411178,
                                   0.26513335769398422,
                                   0.26027511616975957,
                                   0.2394198056502512,
                                   0.19493137873670796,
                                   0.13266647829446609,
                                   0.070401577852224173,
                                   0.02591315093868098,
                                   0.0050578404191725448,
                                   0.00019959889494793986,
                                   0.097589300217458846,
                                   0.095801096745967734,
                                   0.088124751614904615,
                                   0.07174961689768318,
                                   0.048831383918182092,
                                   0.02591315093868098,
                                   0.009538016221459571,
                                   0.0018616710903964343,
                                   7.34676189053125E-5,
                                   0.019047899975059998,
                                   0.018698870718941565,
                                   0.017200568610977782,
                                   0.014004399282201669,
                                   0.0095311198506871087,
                                   0.0050578404191725448,
                                   0.0018616710903964343,
                                   0.00036336898243264742,
                                   1.4339726314215995E-5,
                                   0.0007516923174738792,
                                   0.00073791848357400739,
                                   0.000678790590982911,
                                   0.00055265931494028354,
                                   0.00037612910494411178,
                                   0.00019959889494793986,
                                   7.34676189053125E-5,
                                   1.4339726314215995E-5,
                                   5.6589241434423458E-7,
                                   0.00075169231747412347,
                                   0.019047899975060217,
                                   0.0975893002174588,
                                   0.26513335769398438,
                                   0.49962387089505578,
                                   0.73411438409612739,
                                   0.90165844157265274,
                                   0.9801998418150516,
                                   0.9984960494726377,
                                   0.00073791848357424722,
                                   0.01869887071894178,
                                   0.095801096745967693,
                                   0.26027511616975973,
                                   0.49046888014931278,
                                   0.72066264412886594,
                                   0.88513666355265785,
                                   0.962238889579684,
                                   0.9801998418150516,
                                   0.00067879059098313165,
                                   0.017200568610977979,
                                   0.088124751614904573,
                                   0.23941980565025137,
                                   0.45116861608181791,
                                   0.66291742651338459,
                                   0.81421248054873119,
                                   0.88513666355265808,
                                   0.901658441572653,
                                   0.00055265931494046319,
                                   0.014004399282201829,
                                   0.071749616897683152,
                                   0.19493137873670807,
                                   0.36733352170553379,
                                   0.53973566467435963,
                                   0.66291742651338437,
                                   0.72066264412886594,
                                   0.73411438409612728,
                                   0.000376129104944234,
                                   0.0095311198506872179,
                                   0.048831383918182071,
                                   0.13266647829446618,
                                   0.25,
                                   0.36733352170553391,
                                   0.45116861608181791,
                                   0.49046888014931289,
                                   0.49962387089505589,
                                   0.00019959889494800472,
                                   0.005057840419172603,
                                   0.025913150938680969,
                                   0.070401577852224215,
                                   0.13266647829446609,
                                   0.19493137873670802,
                                   0.2394198056502512,
                                   0.26027511616975962,
                                   0.26513335769398427,
                                   7.346761890533637E-5,
                                   0.0018616710903964556,
                                   0.0095380162214595658,
                                   0.025913150938680997,
                                   0.048831383918182092,
                                   0.071749616897683208,
                                   0.088124751614904615,
                                   0.095801096745967748,
                                   0.097589300217458874,
                                   1.4339726314220655E-5,
                                   0.0003633689824326516,
                                   0.0018616710903964335,
                                   0.0050578404191725483,
                                   0.0095311198506871087,
                                   0.014004399282201672,
                                   0.017200568610977782,
                                   0.018698870718941569,
                                   0.01904789997506,
                                   5.6589241434441849E-7,
                                   1.4339726314216159E-5,
                                   7.3467618905312463E-5,
                                   0.00019959889494794,
                                   0.00037612910494411178,
                                   0.00055265931494028365,
                                   0.000678790590982911,
                                   0.00073791848357400761,
                                   0.00075169231747387931,
                                   0.015405432260441217,
                                   0.0690406262885081,
                                   0.12570306125222783,
                                   0.14801620030476714,
                                   0.12490596772376394,
                                   0.0755304376556802,
                                   0.030123500076946037,
                                   0.0061657533997261866,
                                   0.00024922019234394083,
                                   0.015123146729275845,
                                   0.06777554202898449,
                                   0.12339970781073976,
                                   0.14530398613136786,
                                   0.1226172200373282,
                                   0.074146435613261938,
                                   0.02957152411963283,
                                   0.0060527735790985139,
                                   0.00024465353993305091,
                                   0.013911360040972447,
                                   0.062344827040001265,
                                   0.11351194265561429,
                                   0.13366107614025094,
                                   0.11279215402045448,
                                   0.068205234005572574,
                                   0.027202018624348262,
                                   0.0055677772630694294,
                                   0.00022504995423462852,
                                   0.011326383736401885,
                                   0.05076005746058581,
                                   0.092419419625060617,
                                   0.10882448836965664,
                                   0.091833380426383449,
                                   0.055531497344827575,
                                   0.022147403304686675,
                                   0.0045331859469241,
                                   0.00018323169941785949,
                                   0.0077085149238581285,
                                   0.034546300882714348,
                                   0.062898846800011732,
                                   0.074063815265472691,
                                   0.0625,
                                   0.037793649410891084,
                                   0.015073088893341413,
                                   0.0030851975650605379,
                                   0.00012470390570884504,
                                   0.004090646111314369,
                                   0.018332544304842872,
                                   0.033378273974962819,
                                   0.039303142161288718,
                                   0.033166619573616524,
                                   0.020055801476954575,
                                   0.0079987744819961463,
                                   0.001637209183196974,
                                   6.617611199983055E-5,
                                   0.0015056698067438098,
                                   0.0067477747254274289,
                                   0.012285750944409169,
                                   0.01446655439069445,
                                   0.012207845979545523,
                                   0.0073820648162095954,
                                   0.0029441591623345638,
                                   0.0006026178670516468,
                                   2.4357857183061565E-5,
                                   0.00029388311844040813,
                                   0.0013170597364441932,
                                   0.0023979857892836767,
                                   0.0028236443995774785,
                                   0.0023827799626717772,
                                   0.0014408632085202127,
                                   0.00057465366704999093,
                                   0.0001176215510225601,
                                   4.7542714846391455E-6,
                                   1.1597587275036343E-5,
                                   5.1975476920581304E-5,
                                   9.4632347795620887E-5,
                                   0.00011143022617819314,
                                   9.4032276236027945E-5,
                                   5.6861166101960084E-5,
                                   2.2677709736782152E-5,
                                   4.6417303948878929E-6,
                                   1.8761907374921118E-7,
                                   -0.00024922019234401786,
                                   -0.0061657533997261788,
                                   -0.030123500076946023,
                                   -0.075530437655680224,
                                   -0.12490596772376394,
                                   -0.14801620030476711,
                                   -0.12570306125222783,
                                   -0.069040626288508156,
                                   -0.015405432260441273,
                                   -0.00024465353993312648,
                                   -0.006052773579098507,
                                   -0.029571524119632816,
                                   -0.074146435613261966,
                                   -0.1226172200373282,
                                   -0.14530398613136783,
                                   -0.12339970781073976,
                                   -0.067775542028984545,
                                   -0.0151231467292759,
                                   -0.00022504995423469807,
                                   -0.0055677772630694216,
                                   -0.027202018624348248,
                                   -0.0682052340055726,
                                   -0.11279215402045448,
                                   -0.13366107614025091,
                                   -0.11351194265561429,
                                   -0.06234482704000132,
                                   -0.013911360040972497,
                                   -0.00018323169941791612,
                                   -0.004533185946924095,
                                   -0.022147403304686664,
                                   -0.055531497344827596,
                                   -0.091833380426383449,
                                   -0.10882448836965661,
                                   -0.092419419625060617,
                                   -0.050760057460585851,
                                   -0.011326383736401924,
                                   -0.00012470390570888359,
                                   -0.003085197565060534,
                                   -0.015073088893341406,
                                   -0.0377936494108911,
                                   -0.0625,
                                   -0.074063815265472677,
                                   -0.062898846800011732,
                                   -0.034546300882714376,
                                   -0.0077085149238581563,
                                   -6.6176111999851E-5,
                                   -0.0016372091831969718,
                                   -0.0079987744819961428,
                                   -0.020055801476954582,
                                   -0.033166619573616524,
                                   -0.039303142161288711,
                                   -0.033378273974962819,
                                   -0.018332544304842886,
                                   -0.0040906461113143838,
                                   -2.4357857183069097E-5,
                                   -0.000602617867051646,
                                   -0.0029441591623345625,
                                   -0.0073820648162095989,
                                   -0.012207845979545523,
                                   -0.014466554390694447,
                                   -0.012285750944409169,
                                   -0.0067477747254274341,
                                   -0.0015056698067438153,
                                   -4.7542714846406151E-6,
                                   -0.00011762155102255995,
                                   -0.0005746536670499906,
                                   -0.0014408632085202132,
                                   -0.0023827799626717772,
                                   -0.002823644399577478,
                                   -0.0023979857892836767,
                                   -0.0013170597364441942,
                                   -0.00029388311844040922,
                                   -1.8761907374926918E-7,
                                   -4.6417303948878869E-6,
                                   -2.2677709736782142E-5,
                                   -5.6861166101960104E-5,
                                   -9.4032276236027945E-5,
                                   -0.00011143022617819313,
                                   -9.4632347795620887E-5,
                                   -5.1975476920581345E-5,
                                   -1.1597587275036385E-5,
                                   0.00075169231747412347,
                                   0.00073791848357424722,
                                   0.00067879059098313165,
                                   0.00055265931494046319,
                                   0.000376129104944234,
                                   0.00019959889494800472,
                                   7.346761890533637E-5,
                                   1.4339726314220655E-5,
                                   5.6589241434441849E-7,
                                   0.019047899975060217,
                                   0.01869887071894178,
                                   0.017200568610977979,
                                   0.014004399282201829,
                                   0.0095311198506872179,
                                   0.005057840419172603,
                                   0.0018616710903964556,
                                   0.0003633689824326516,
                                   1.4339726314216159E-5,
                                   0.0975893002174588,
                                   0.095801096745967693,
                                   0.088124751614904573,
                                   0.071749616897683152,
                                   0.048831383918182071,
                                   0.025913150938680969,
                                   0.0095380162214595658,
                                   0.0018616710903964335,
                                   7.3467618905312463E-5,
                                   0.26513335769398438,
                                   0.26027511616975973,
                                   0.23941980565025137,
                                   0.19493137873670807,
                                   0.13266647829446618,
                                   0.070401577852224215,
                                   0.025913150938680997,
                                   0.0050578404191725483,
                                   0.00019959889494794,
                                   0.49962387089505578,
                                   0.49046888014931278,
                                   0.45116861608181791,
                                   0.36733352170553379,
                                   0.25,
                                   0.13266647829446609,
                                   0.048831383918182092,
                                   0.0095311198506871087,
                                   0.00037612910494411178,
                                   0.73411438409612739,
                                   0.72066264412886594,
                                   0.66291742651338459,
                                   0.53973566467435963,
                                   0.36733352170553391,
                                   0.19493137873670802,
                                   0.071749616897683208,
                                   0.014004399282201672,
                                   0.00055265931494028365,
                                   0.90165844157265274,
                                   0.88513666355265785,
                                   0.81421248054873119,
                                   0.66291742651338437,
                                   0.45116861608181791,
                                   0.2394198056502512,
                                   0.088124751614904615,
                                   0.017200568610977782,
                                   0.000678790590982911,
                                   0.9801998418150516,
                                   0.962238889579684,
                                   0.88513666355265808,
                                   0.72066264412886594,
                                   0.49046888014931289,
                                   0.26027511616975962,
                                   0.095801096745967748,
                                   0.018698870718941569,
                                   0.00073791848357400761,
                                   0.9984960494726377,
                                   0.9801998418150516,
                                   0.901658441572653,
                                   0.73411438409612728,
                                   0.49962387089505589,
                                   0.26513335769398427,
                                   0.097589300217458874,
                                   0.01904789997506,
                                   0.00075169231747387931,
                                   5.658924143446024E-7,
                                   1.4339726314220819E-5,
                                   7.3467618905336343E-5,
                                   0.00019959889494800486,
                                   0.000376129104944234,
                                   0.0005526593149404633,
                                   0.00067879059098313165,
                                   0.00073791848357424744,
                                   0.00075169231747412358,
                                   1.4339726314220819E-5,
                                   0.00036336898243265572,
                                   0.0018616710903964549,
                                   0.0050578404191726064,
                                   0.0095311198506872179,
                                   0.014004399282201834,
                                   0.017200568610977979,
                                   0.018698870718941784,
                                   0.01904789997506022,
                                   7.3467618905336343E-5,
                                   0.0018616710903964549,
                                   0.0095380162214595623,
                                   0.025913150938680986,
                                   0.048831383918182071,
                                   0.071749616897683166,
                                   0.088124751614904573,
                                   0.0958010967459677,
                                   0.097589300217458833,
                                   0.00019959889494800486,
                                   0.0050578404191726064,
                                   0.025913150938680986,
                                   0.070401577852224256,
                                   0.13266647829446618,
                                   0.19493137873670813,
                                   0.23941980565025137,
                                   0.26027511616975979,
                                   0.26513335769398444,
                                   0.000376129104944234,
                                   0.0095311198506872179,
                                   0.048831383918182071,
                                   0.13266647829446618,
                                   0.25,
                                   0.36733352170553391,
                                   0.45116861608181791,
                                   0.49046888014931289,
                                   0.49962387089505589,
                                   0.0005526593149404633,
                                   0.014004399282201834,
                                   0.071749616897683166,
                                   0.19493137873670813,
                                   0.36733352170553391,
                                   0.53973566467435985,
                                   0.66291742651338459,
                                   0.72066264412886616,
                                   0.7341143840961275,
                                   0.00067879059098313165,
                                   0.017200568610977979,
                                   0.088124751614904573,
                                   0.23941980565025137,
                                   0.45116861608181791,
                                   0.66291742651338459,
                                   0.81421248054873119,
                                   0.88513666355265808,
                                   0.901658441572653,
                                   0.00073791848357424744,
                                   0.018698870718941784,
                                   0.0958010967459677,
                                   0.26027511616975979,
                                   0.49046888014931289,
                                   0.72066264412886616,
                                   0.88513666355265808,
                                   0.96223888957968418,
                                   0.98019984181505182,
                                   0.00075169231747412358,
                                   0.01904789997506022,
                                   0.097589300217458833,
                                   0.26513335769398444,
                                   0.49962387089505589,
                                   0.7341143840961275,
                                   0.901658441572653,
                                   0.98019984181505182,
                                   0.99849604947263793,
                                   1.1597587275040112E-5,
                                   5.19754769205982E-5,
                                   9.4632347795651638E-5,
                                   0.00011143022617822935,
                                   9.40322762360585E-5,
                                   5.6861166101978563E-5,
                                   2.2677709736789521E-5,
                                   4.6417303948894014E-6,
                                   1.8761907374927217E-7,
                                   0.0002938831184404115,
                                   0.0013170597364442083,
                                   0.002397985789283704,
                                   0.002823644399577511,
                                   0.0023827799626718045,
                                   0.0014408632085202292,
                                   0.00057465366704999754,
                                   0.00011762155102256145,
                                   4.7542714846392006E-6,
                                   0.0015056698067438092,
                                   0.0067477747254274262,
                                   0.012285750944409164,
                                   0.014466554390694443,
                                   0.012207845979545518,
                                   0.0073820648162095928,
                                   0.0029441591623345625,
                                   0.00060261786705164658,
                                   2.4357857183061555E-5,
                                   0.0040906461113143716,
                                   0.018332544304842883,
                                   0.03337827397496284,
                                   0.039303142161288739,
                                   0.033166619573616545,
                                   0.020055801476954585,
                                   0.0079987744819961515,
                                   0.0016372091831969751,
                                   6.6176111999830591E-5,
                                   0.0077085149238581285,
                                   0.034546300882714348,
                                   0.062898846800011732,
                                   0.074063815265472691,
                                   0.0625,
                                   0.037793649410891084,
                                   0.015073088893341413,
                                   0.0030851975650605379,
                                   0.00012470390570884504,
                                   0.011326383736401888,
                                   0.050760057460585824,
                                   0.092419419625060645,
                                   0.10882448836965666,
                                   0.091833380426383476,
                                   0.055531497344827596,
                                   0.022147403304686682,
                                   0.004533185946924102,
                                   0.00018323169941785955,
                                   0.013911360040972447,
                                   0.062344827040001265,
                                   0.11351194265561429,
                                   0.13366107614025094,
                                   0.11279215402045448,
                                   0.068205234005572574,
                                   0.027202018624348262,
                                   0.0055677772630694294,
                                   0.00022504995423462852,
                                   0.015123146729275849,
                                   0.0677755420289845,
                                   0.12339970781073979,
                                   0.14530398613136791,
                                   0.12261722003732822,
                                   0.074146435613261952,
                                   0.029571524119632837,
                                   0.0060527735790985157,
                                   0.00024465353993305096,
                                   0.015405432260441221,
                                   0.069040626288508114,
                                   0.12570306125222785,
                                   0.1480162003047672,
                                   0.12490596772376397,
                                   0.07553043765568021,
                                   0.030123500076946044,
                                   0.0061657533997261883,
                                   0.00024922019234394088,
                                   -1.8761907374933017E-7,
                                   -4.6417303948893955E-6,
                                   -2.2677709736789511E-5,
                                   -5.6861166101978583E-5,
                                   -9.40322762360585E-5,
                                   -0.00011143022617822934,
                                   -9.4632347795651638E-5,
                                   -5.1975476920598238E-5,
                                   -1.1597587275040155E-5,
                                   -4.7542714846406693E-6,
                                   -0.0001176215510225613,
                                   -0.00057465366704999722,
                                   -0.0014408632085202296,
                                   -0.0023827799626718045,
                                   -0.0028236443995775106,
                                   -0.002397985789283704,
                                   -0.0013170597364442094,
                                   -0.00029388311844041258,
                                   -2.4357857183069084E-5,
                                   -0.00060261786705164582,
                                   -0.0029441591623345612,
                                   -0.0073820648162095954,
                                   -0.012207845979545518,
                                   -0.014466554390694442,
                                   -0.012285750944409164,
                                   -0.0067477747254274315,
                                   -0.0015056698067438146,
                                   -6.6176111999851042E-5,
                                   -0.0016372091831969729,
                                   -0.007998774481996148,
                                   -0.020055801476954592,
                                   -0.033166619573616545,
                                   -0.039303142161288732,
                                   -0.03337827397496284,
                                   -0.018332544304842897,
                                   -0.0040906461113143864,
                                   -0.00012470390570888359,
                                   -0.003085197565060534,
                                   -0.015073088893341406,
                                   -0.0377936494108911,
                                   -0.0625,
                                   -0.074063815265472677,
                                   -0.062898846800011732,
                                   -0.034546300882714376,
                                   -0.0077085149238581563,
                                   -0.00018323169941791617,
                                   -0.0045331859469240959,
                                   -0.022147403304686671,
                                   -0.055531497344827617,
                                   -0.091833380426383476,
                                   -0.10882448836965665,
                                   -0.092419419625060645,
                                   -0.050760057460585865,
                                   -0.011326383736401928,
                                   -0.00022504995423469807,
                                   -0.0055677772630694216,
                                   -0.027202018624348248,
                                   -0.0682052340055726,
                                   -0.11279215402045448,
                                   -0.13366107614025091,
                                   -0.11351194265561429,
                                   -0.06234482704000132,
                                   -0.013911360040972497,
                                   -0.00024465353993312653,
                                   -0.0060527735790985079,
                                   -0.029571524119632823,
                                   -0.07414643561326198,
                                   -0.12261722003732822,
                                   -0.14530398613136788,
                                   -0.12339970781073979,
                                   -0.067775542028984559,
                                   -0.015123146729275904,
                                   -0.00024922019234401791,
                                   -0.0061657533997261805,
                                   -0.03012350007694603,
                                   -0.075530437655680238,
                                   -0.12490596772376397,
                                   -0.14801620030476717,
                                   -0.12570306125222785,
                                   -0.06904062628850817,
                                   -0.015405432260441276,
                                   0.015405432260441217,
                                   0.015123146729275845,
                                   0.013911360040972447,
                                   0.011326383736401885,
                                   0.0077085149238581285,
                                   0.004090646111314369,
                                   0.0015056698067438098,
                                   0.00029388311844040813,
                                   1.1597587275036343E-5,
                                   0.0690406262885081,
                                   0.06777554202898449,
                                   0.062344827040001265,
                                   0.05076005746058581,
                                   0.034546300882714348,
                                   0.018332544304842872,
                                   0.0067477747254274289,
                                   0.0013170597364441932,
                                   5.1975476920581304E-5,
                                   0.12570306125222783,
                                   0.12339970781073976,
                                   0.11351194265561429,
                                   0.092419419625060617,
                                   0.062898846800011732,
                                   0.033378273974962819,
                                   0.012285750944409169,
                                   0.0023979857892836767,
                                   9.4632347795620887E-5,
                                   0.14801620030476714,
                                   0.14530398613136786,
                                   0.13366107614025094,
                                   0.10882448836965664,
                                   0.074063815265472691,
                                   0.039303142161288718,
                                   0.01446655439069445,
                                   0.0028236443995774785,
                                   0.00011143022617819314,
                                   0.12490596772376394,
                                   0.1226172200373282,
                                   0.11279215402045448,
                                   0.091833380426383449,
                                   0.0625,
                                   0.033166619573616524,
                                   0.012207845979545523,
                                   0.0023827799626717772,
                                   9.4032276236027945E-5,
                                   0.0755304376556802,
                                   0.074146435613261938,
                                   0.068205234005572574,
                                   0.055531497344827575,
                                   0.037793649410891084,
                                   0.020055801476954575,
                                   0.0073820648162095954,
                                   0.0014408632085202127,
                                   5.6861166101960084E-5,
                                   0.030123500076946037,
                                   0.02957152411963283,
                                   0.027202018624348262,
                                   0.022147403304686675,
                                   0.015073088893341413,
                                   0.0079987744819961463,
                                   0.0029441591623345638,
                                   0.00057465366704999093,
                                   2.2677709736782152E-5,
                                   0.0061657533997261866,
                                   0.0060527735790985139,
                                   0.0055677772630694294,
                                   0.0045331859469241,
                                   0.0030851975650605379,
                                   0.001637209183196974,
                                   0.0006026178670516468,
                                   0.0001176215510225601,
                                   4.6417303948878929E-6,
                                   0.00024922019234394083,
                                   0.00024465353993305091,
                                   0.00022504995423462852,
                                   0.00018323169941785949,
                                   0.00012470390570884504,
                                   6.617611199983055E-5,
                                   2.4357857183061565E-5,
                                   4.7542714846391455E-6,
                                   1.8761907374921118E-7,
                                   1.1597587275040112E-5,
                                   0.0002938831184404115,
                                   0.0015056698067438092,
                                   0.0040906461113143716,
                                   0.0077085149238581285,
                                   0.011326383736401888,
                                   0.013911360040972447,
                                   0.015123146729275849,
                                   0.015405432260441221,
                                   5.19754769205982E-5,
                                   0.0013170597364442083,
                                   0.0067477747254274262,
                                   0.018332544304842883,
                                   0.034546300882714348,
                                   0.050760057460585824,
                                   0.062344827040001265,
                                   0.0677755420289845,
                                   0.069040626288508114,
                                   9.4632347795651638E-5,
                                   0.002397985789283704,
                                   0.012285750944409164,
                                   0.03337827397496284,
                                   0.062898846800011732,
                                   0.092419419625060645,
                                   0.11351194265561429,
                                   0.12339970781073979,
                                   0.12570306125222785,
                                   0.00011143022617822935,
                                   0.002823644399577511,
                                   0.014466554390694443,
                                   0.039303142161288739,
                                   0.074063815265472691,
                                   0.10882448836965666,
                                   0.13366107614025094,
                                   0.14530398613136791,
                                   0.1480162003047672,
                                   9.40322762360585E-5,
                                   0.0023827799626718045,
                                   0.012207845979545518,
                                   0.033166619573616545,
                                   0.0625,
                                   0.091833380426383476,
                                   0.11279215402045448,
                                   0.12261722003732822,
                                   0.12490596772376397,
                                   5.6861166101978563E-5,
                                   0.0014408632085202292,
                                   0.0073820648162095928,
                                   0.020055801476954585,
                                   0.037793649410891084,
                                   0.055531497344827596,
                                   0.068205234005572574,
                                   0.074146435613261952,
                                   0.07553043765568021,
                                   2.2677709736789521E-5,
                                   0.00057465366704999754,
                                   0.0029441591623345625,
                                   0.0079987744819961515,
                                   0.015073088893341413,
                                   0.022147403304686682,
                                   0.027202018624348262,
                                   0.029571524119632837,
                                   0.030123500076946044,
                                   4.6417303948894014E-6,
                                   0.00011762155102256145,
                                   0.00060261786705164658,
                                   0.0016372091831969751,
                                   0.0030851975650605379,
                                   0.004533185946924102,
                                   0.0055677772630694294,
                                   0.0060527735790985157,
                                   0.0061657533997261883,
                                   1.8761907374927217E-7,
                                   4.7542714846392006E-6,
                                   2.4357857183061555E-5,
                                   6.6176111999830591E-5,
                                   0.00012470390570884504,
                                   0.00018323169941785955,
                                   0.00022504995423462852,
                                   0.00024465353993305096,
                                   0.00024922019234394088,
                                   0.00023768480932537397,
                                   0.0010652027036739873,
                                   0.001939426797005426,
                                   0.0022836881011670707,
                                   0.0019271287309645321,
                                   0.0011653316420436636,
                                   0.00046476452273184994,
                                   9.5129165893279667E-5,
                                   3.8451276728801158E-6,
                                   0.0010652027036739873,
                                   0.0047737876187161207,
                                   0.00869168994691584,
                                   0.010234523386731167,
                                   0.008636575220678587,
                                   0.005222523136017853,
                                   0.0020828778565650892,
                                   0.00042632865346079607,
                                   1.7232234591469602E-5,
                                   0.001939426797005426,
                                   0.00869168994691584,
                                   0.015825059715085386,
                                   0.018634114279229348,
                                   0.015724711700002933,
                                   0.0095087078572359679,
                                   0.0037923196364209595,
                                   0.000776221475970048,
                                   3.1374927442175007E-5,
                                   0.0022836881011670707,
                                   0.010234523386731167,
                                   0.018634114279229348,
                                   0.021941794926712263,
                                   0.018515953816368173,
                                   0.011196567472705112,
                                   0.0044654818851059463,
                                   0.0009140060100645194,
                                   3.69441881412113E-5,
                                   0.0019271287309645321,
                                   0.008636575220678587,
                                   0.015724711700002933,
                                   0.018515953816368173,
                                   0.015625,
                                   0.0094484123527227709,
                                   0.0037682722233353533,
                                   0.00077129939126513447,
                                   3.117597642721126E-5,
                                   0.0011653316420436636,
                                   0.005222523136017853,
                                   0.0095087078572359679,
                                   0.011196567472705112,
                                   0.0094484123527227709,
                                   0.0057134397431733916,
                                   0.0022786681486965665,
                                   0.00046640350054893119,
                                   1.8852062770115635E-5,
                                   0.00046476452273184994,
                                   0.0020828778565650892,
                                   0.0037923196364209595,
                                   0.0044654818851059463,
                                   0.0037682722233353533,
                                   0.0022786681486965665,
                                   0.000908792035146289,
                                   0.00018601382860671187,
                                   7.5186922243851479E-6,
                                   9.5129165893279667E-5,
                                   0.00042632865346079607,
                                   0.000776221475970048,
                                   0.0009140060100645194,
                                   0.00077129939126513447,
                                   0.00046640350054893119,
                                   0.00018601382860671187,
                                   3.8073776061821888E-5,
                                   1.5389447449858704E-6,
                                   3.8451276728801158E-6,
                                   1.7232234591469602E-5,
                                   3.1374927442175007E-5,
                                   3.69441881412113E-5,
                                   3.117597642721126E-5,
                                   1.8852062770115635E-5,
                                   7.5186922243851479E-6,
                                   1.5389447449858704E-6,
                                   6.2204256396162055E-8,
                                   -3.8451276728813042E-6,
                                   -9.5129165893279545E-5,
                                   -0.00046476452273184972,
                                   -0.001165331642043664,
                                   -0.0019271287309645321,
                                   -0.0022836881011670702,
                                   -0.001939426797005426,
                                   -0.0010652027036739881,
                                   -0.00023768480932537481,
                                   -1.7232234591474929E-5,
                                   -0.00042632865346079553,
                                   -0.0020828778565650883,
                                   -0.0052225231360178547,
                                   -0.008636575220678587,
                                   -0.010234523386731165,
                                   -0.00869168994691584,
                                   -0.0047737876187161242,
                                   -0.0010652027036739909,
                                   -3.1374927442184711E-5,
                                   -0.000776221475970047,
                                   -0.0037923196364209578,
                                   -0.0095087078572359714,
                                   -0.015724711700002933,
                                   -0.018634114279229345,
                                   -0.015825059715085386,
                                   -0.0086916899469158468,
                                   -0.0019394267970054332,
                                   -3.6944188141222718E-5,
                                   -0.00091400601006451821,
                                   -0.0044654818851059446,
                                   -0.011196567472705116,
                                   -0.018515953816368173,
                                   -0.02194179492671226,
                                   -0.018634114279229348,
                                   -0.010234523386731175,
                                   -0.0022836881011670789,
                                   -3.1175976427220896E-5,
                                   -0.0007712993912651335,
                                   -0.0037682722233353515,
                                   -0.0094484123527227744,
                                   -0.015625,
                                   -0.018515953816368169,
                                   -0.015724711700002933,
                                   -0.008636575220678594,
                                   -0.0019271287309645391,
                                   -1.8852062770121463E-5,
                                   -0.00046640350054893065,
                                   -0.0022786681486965657,
                                   -0.0057134397431733942,
                                   -0.0094484123527227709,
                                   -0.01119656747270511,
                                   -0.0095087078572359679,
                                   -0.0052225231360178573,
                                   -0.0011653316420436677,
                                   -7.5186922243874721E-6,
                                   -0.00018601382860671163,
                                   -0.00090879203514628861,
                                   -0.0022786681486965674,
                                   -0.0037682722233353533,
                                   -0.0044654818851059454,
                                   -0.0037923196364209595,
                                   -0.0020828778565650909,
                                   -0.00046476452273185162,
                                   -1.5389447449863462E-6,
                                   -3.807377606182184E-5,
                                   -0.00018601382860671176,
                                   -0.00046640350054893141,
                                   -0.00077129939126513447,
                                   -0.00091400601006451918,
                                   -0.000776221475970048,
                                   -0.00042632865346079639,
                                   -9.512916589328E-5,
                                   -6.2204256396181286E-8,
                                   -1.5389447449858685E-6,
                                   -7.5186922243851445E-6,
                                   -1.8852062770115642E-5,
                                   -3.117597642721126E-5,
                                   -3.6944188141211294E-5,
                                   -3.1374927442175007E-5,
                                   -1.7232234591469616E-5,
                                   -3.8451276728801293E-6,
                                   -0.00024922019234401786,
                                   -0.00024465353993312648,
                                   -0.00022504995423469807,
                                   -0.00018323169941791612,
                                   -0.00012470390570888359,
                                   -6.6176111999851E-5,
                                   -2.4357857183069097E-5,
                                   -4.7542714846406151E-6,
                                   -1.8761907374926918E-7,
                                   -0.0061657533997261788,
                                   -0.006052773579098507,
                                   -0.0055677772630694216,
                                   -0.004533185946924095,
                                   -0.003085197565060534,
                                   -0.0016372091831969718,
                                   -0.000602617867051646,
                                   -0.00011762155102255995,
                                   -4.6417303948878869E-6,
                                   -0.030123500076946023,
                                   -0.029571524119632816,
                                   -0.027202018624348248,
                                   -0.022147403304686664,
                                   -0.015073088893341406,
                                   -0.0079987744819961428,
                                   -0.0029441591623345625,
                                   -0.0005746536670499906,
                                   -2.2677709736782142E-5,
                                   -0.075530437655680224,
                                   -0.074146435613261966,
                                   -0.0682052340055726,
                                   -0.055531497344827596,
                                   -0.0377936494108911,
                                   -0.020055801476954582,
                                   -0.0073820648162095989,
                                   -0.0014408632085202132,
                                   -5.6861166101960104E-5,
                                   -0.12490596772376394,
                                   -0.1226172200373282,
                                   -0.11279215402045448,
                                   -0.091833380426383449,
                                   -0.0625,
                                   -0.033166619573616524,
                                   -0.012207845979545523,
                                   -0.0023827799626717772,
                                   -9.4032276236027945E-5,
                                   -0.14801620030476711,
                                   -0.14530398613136783,
                                   -0.13366107614025091,
                                   -0.10882448836965661,
                                   -0.074063815265472677,
                                   -0.039303142161288711,
                                   -0.014466554390694447,
                                   -0.002823644399577478,
                                   -0.00011143022617819313,
                                   -0.12570306125222783,
                                   -0.12339970781073976,
                                   -0.11351194265561429,
                                   -0.092419419625060617,
                                   -0.062898846800011732,
                                   -0.033378273974962819,
                                   -0.012285750944409169,
                                   -0.0023979857892836767,
                                   -9.4632347795620887E-5,
                                   -0.069040626288508156,
                                   -0.067775542028984545,
                                   -0.06234482704000132,
                                   -0.050760057460585851,
                                   -0.034546300882714376,
                                   -0.018332544304842886,
                                   -0.0067477747254274341,
                                   -0.0013170597364441942,
                                   -5.1975476920581345E-5,
                                   -0.015405432260441273,
                                   -0.0151231467292759,
                                   -0.013911360040972497,
                                   -0.011326383736401924,
                                   -0.0077085149238581563,
                                   -0.0040906461113143838,
                                   -0.0015056698067438153,
                                   -0.00029388311844040922,
                                   -1.1597587275036385E-5,
                                   -1.8761907374933017E-7,
                                   -4.7542714846406693E-6,
                                   -2.4357857183069084E-5,
                                   -6.6176111999851042E-5,
                                   -0.00012470390570888359,
                                   -0.00018323169941791617,
                                   -0.00022504995423469807,
                                   -0.00024465353993312653,
                                   -0.00024922019234401791,
                                   -4.6417303948893955E-6,
                                   -0.0001176215510225613,
                                   -0.00060261786705164582,
                                   -0.0016372091831969729,
                                   -0.003085197565060534,
                                   -0.0045331859469240959,
                                   -0.0055677772630694216,
                                   -0.0060527735790985079,
                                   -0.0061657533997261805,
                                   -2.2677709736789511E-5,
                                   -0.00057465366704999722,
                                   -0.0029441591623345612,
                                   -0.007998774481996148,
                                   -0.015073088893341406,
                                   -0.022147403304686671,
                                   -0.027202018624348248,
                                   -0.029571524119632823,
                                   -0.03012350007694603,
                                   -5.6861166101978583E-5,
                                   -0.0014408632085202296,
                                   -0.0073820648162095954,
                                   -0.020055801476954592,
                                   -0.0377936494108911,
                                   -0.055531497344827617,
                                   -0.0682052340055726,
                                   -0.07414643561326198,
                                   -0.075530437655680238,
                                   -9.40322762360585E-5,
                                   -0.0023827799626718045,
                                   -0.012207845979545518,
                                   -0.033166619573616545,
                                   -0.0625,
                                   -0.091833380426383476,
                                   -0.11279215402045448,
                                   -0.12261722003732822,
                                   -0.12490596772376397,
                                   -0.00011143022617822934,
                                   -0.0028236443995775106,
                                   -0.014466554390694442,
                                   -0.039303142161288732,
                                   -0.074063815265472677,
                                   -0.10882448836965665,
                                   -0.13366107614025091,
                                   -0.14530398613136788,
                                   -0.14801620030476717,
                                   -9.4632347795651638E-5,
                                   -0.002397985789283704,
                                   -0.012285750944409164,
                                   -0.03337827397496284,
                                   -0.062898846800011732,
                                   -0.092419419625060645,
                                   -0.11351194265561429,
                                   -0.12339970781073979,
                                   -0.12570306125222785,
                                   -5.1975476920598238E-5,
                                   -0.0013170597364442094,
                                   -0.0067477747254274315,
                                   -0.018332544304842897,
                                   -0.034546300882714376,
                                   -0.050760057460585865,
                                   -0.06234482704000132,
                                   -0.067775542028984559,
                                   -0.06904062628850817,
                                   -1.1597587275040155E-5,
                                   -0.00029388311844041258,
                                   -0.0015056698067438146,
                                   -0.0040906461113143864,
                                   -0.0077085149238581563,
                                   -0.011326383736401928,
                                   -0.013911360040972497,
                                   -0.015123146729275904,
                                   -0.015405432260441276,
                                   -3.8451276728813042E-6,
                                   -1.7232234591474929E-5,
                                   -3.1374927442184711E-5,
                                   -3.6944188141222718E-5,
                                   -3.1175976427220896E-5,
                                   -1.8852062770121463E-5,
                                   -7.5186922243874721E-6,
                                   -1.5389447449863462E-6,
                                   -6.2204256396181286E-8,
                                   -9.5129165893279545E-5,
                                   -0.00042632865346079553,
                                   -0.000776221475970047,
                                   -0.00091400601006451821,
                                   -0.0007712993912651335,
                                   -0.00046640350054893065,
                                   -0.00018601382860671163,
                                   -3.807377606182184E-5,
                                   -1.5389447449858685E-6,
                                   -0.00046476452273184972,
                                   -0.0020828778565650883,
                                   -0.0037923196364209578,
                                   -0.0044654818851059446,
                                   -0.0037682722233353515,
                                   -0.0022786681486965657,
                                   -0.00090879203514628861,
                                   -0.00018601382860671176,
                                   -7.5186922243851445E-6,
                                   -0.001165331642043664,
                                   -0.0052225231360178547,
                                   -0.0095087078572359714,
                                   -0.011196567472705116,
                                   -0.0094484123527227744,
                                   -0.0057134397431733942,
                                   -0.0022786681486965674,
                                   -0.00046640350054893141,
                                   -1.8852062770115642E-5,
                                   -0.0019271287309645321,
                                   -0.008636575220678587,
                                   -0.015724711700002933,
                                   -0.018515953816368173,
                                   -0.015625,
                                   -0.0094484123527227709,
                                   -0.0037682722233353533,
                                   -0.00077129939126513447,
                                   -3.117597642721126E-5,
                                   -0.0022836881011670702,
                                   -0.010234523386731165,
                                   -0.018634114279229345,
                                   -0.02194179492671226,
                                   -0.018515953816368169,
                                   -0.01119656747270511,
                                   -0.0044654818851059454,
                                   -0.00091400601006451918,
                                   -3.6944188141211294E-5,
                                   -0.001939426797005426,
                                   -0.00869168994691584,
                                   -0.015825059715085386,
                                   -0.018634114279229348,
                                   -0.015724711700002933,
                                   -0.0095087078572359679,
                                   -0.0037923196364209595,
                                   -0.000776221475970048,
                                   -3.1374927442175007E-5,
                                   -0.0010652027036739881,
                                   -0.0047737876187161242,
                                   -0.0086916899469158468,
                                   -0.010234523386731175,
                                   -0.008636575220678594,
                                   -0.0052225231360178573,
                                   -0.0020828778565650909,
                                   -0.00042632865346079639,
                                   -1.7232234591469616E-5,
                                   -0.00023768480932537481,
                                   -0.0010652027036739909,
                                   -0.0019394267970054332,
                                   -0.0022836881011670789,
                                   -0.0019271287309645391,
                                   -0.0011653316420436677,
                                   -0.00046476452273185162,
                                   -9.512916589328E-5,
                                   -3.8451276728801293E-6,
                                   6.2204256396200516E-8,
                                   1.5389447449863443E-6,
                                   7.5186922243874687E-6,
                                   1.8852062770121469E-5,
                                   3.1175976427220896E-5,
                                   3.6944188141222712E-5,
                                   3.1374927442184711E-5,
                                   1.7232234591474942E-5,
                                   3.8451276728813177E-6,
                                   1.5389447449863443E-6,
                                   3.8073776061821793E-5,
                                   0.00018601382860671155,
                                   0.00046640350054893081,
                                   0.0007712993912651335,
                                   0.000914006010064518,
                                   0.000776221475970047,
                                   0.00042632865346079585,
                                   9.5129165893279884E-5,
                                   7.5186922243874687E-6,
                                   0.00018601382860671155,
                                   0.00090879203514628818,
                                   0.0022786681486965665,
                                   0.0037682722233353515,
                                   0.0044654818851059437,
                                   0.0037923196364209578,
                                   0.00208287785656509,
                                   0.0004647645227318514,
                                   1.8852062770121469E-5,
                                   0.00046640350054893081,
                                   0.0022786681486965665,
                                   0.0057134397431733959,
                                   0.0094484123527227744,
                                   0.011196567472705114,
                                   0.0095087078572359714,
                                   0.0052225231360178591,
                                   0.0011653316420436681,
                                   3.1175976427220896E-5,
                                   0.0007712993912651335,
                                   0.0037682722233353515,
                                   0.0094484123527227744,
                                   0.015625,
                                   0.018515953816368169,
                                   0.015724711700002933,
                                   0.008636575220678594,
                                   0.0019271287309645391,
                                   3.6944188141222712E-5,
                                   0.000914006010064518,
                                   0.0044654818851059437,
                                   0.011196567472705114,
                                   0.018515953816368169,
                                   0.021941794926712253,
                                   0.018634114279229345,
                                   0.010234523386731172,
                                   0.0022836881011670785,
                                   3.1374927442184711E-5,
                                   0.000776221475970047,
                                   0.0037923196364209578,
                                   0.0095087078572359714,
                                   0.015724711700002933,
                                   0.018634114279229345,
                                   0.015825059715085386,
                                   0.0086916899469158468,
                                   0.0019394267970054332,
                                   1.7232234591474942E-5,
                                   0.00042632865346079585,
                                   0.00208287785656509,
                                   0.0052225231360178591,
                                   0.008636575220678594,
                                   0.010234523386731172,
                                   0.0086916899469158468,
                                   0.0047737876187161285,
                                   0.0010652027036739918,
                                   3.8451276728813177E-6,
                                   9.5129165893279884E-5,
                                   0.0004647645227318514,
                                   0.0011653316420436681,
                                   0.0019271287309645391,
                                   0.0022836881011670785,
                                   0.0019394267970054332,
                                   0.0010652027036739918,
                                   0.00023768480932537567};
  static const real_T b[9] = {0.015919880246186957,
                              0.08198444633668206,
                              0.19331428364970477,
                              0.33787328829809554,
                              0.5,
                              0.66212671170190451,
                              0.80668571635029518,
                              0.91801555366331788,
                              0.984080119753813};
  static const int32_T b_iv[2] = {1, 4};
  static const char_T u[4] = {'f', 'l', 'a', 't'};
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  c_struct_T f_expl_temp;
  e_struct_T e_expl_temp;
  e_struct_T expl_temp;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_real_T *U;
  emxArray_real_T *X;
  emxArray_real_T *b_I;
  emxArray_real_T *b_T;
  emxArray_real_T *b_expl_temp;
  emxArray_real_T *c_expl_temp;
  emxArray_real_T *d_expl_temp;
  emxArray_real_T *mesh_bot;
  emxArray_real_T *mesh_bot_elms;
  emxArray_real_T *mesh_elms;
  emxArray_real_T *mesh_left_elms;
  emxArray_real_T *mesh_pivots;
  emxArray_real_T *mesh_right_elms;
  emxArray_real_T *mesh_top_elms;
  emxArray_real_T *r;
  emxArray_real_T *r4;
  emxArray_real_T *tt;
  emxArray_real_T *xx;
  const mxArray *m;
  const mxArray *y;
  rtString obj;
  real_T b_el_u[81];
  real_T el_u[81];
  real_T ttqh[81];
  real_T xxqh[81];
  real_T b_dv[16];
  real_T b_dv1[16];
  real_T b_mesh_elms[16];
  real_T tqh[9];
  real_T xqh[9];
  real_T a;
  real_T alpha1;
  real_T b_b;
  real_T beta1;
  real_T d;
  real_T d1;
  real_T d_ht;
  real_T d_hx;
  real_T delta1;
  real_T err;
  real_T mesh_elms_tmp;
  real_T phi;
  real_T *I_data;
  real_T *T_data;
  real_T *U_data;
  real_T *X_data;
  real_T *mesh_elms_data;
  real_T *mesh_pivots_data;
  real_T *r1;
  real_T *r6;
  real_T *tt_data;
  real_T *xx_data;
  int32_T iv1[2];
  int32_T iv2[2];
  int32_T b_i;
  int32_T b_i1;
  int32_T g_expl_temp;
  int32_T i;
  int32_T i1;
  int32_T i3;
  int32_T j;
  int32_T j2;
  int32_T kidx;
  int32_T *r5;
  int32_T *r7;
  char_T TRANSA1;
  char_T TRANSB1;
  int8_T i2;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);
  /*  Main C callable function */
  phi = (1.0 - 1.0 / theta) / (1.0 / theta + 1.0);
  /*  Define gaussian and derivatives */
  /*  Define initial wave */
  /*     %% Define problem, discretization and mesh */
  /*  Create simple problem */
  /*  Define domain */
  st.site = &emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 1U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 0U);
  /*  Discretise the domain */
  st.site = &b_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 2U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 0U);
  /*     %% Unpack domain values */
  /*     %% Build struct  */
  /*  Mesh lengths in x and t */
  d_hx = 2.0 / nx;
  d_ht = T / nt;
  /*  Nodes vectors in x and t */
  b_st.site = &g_emlrtRSI;
  emxInitStruct_struct_T(&b_st, &expl_temp, &xb_emlrtRTEI);
  if (!(nx + 1.0 >= 0.0)) {
    if (muDoubleScalarIsNaN(nx + 1.0)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
                                    "Coder:toolbox:MustNotBeNaN",
                                    "Coder:toolbox:MustNotBeNaN", 3, 4, 1, "N");
    }
    expl_temp.x->size[0] = 1;
    expl_temp.x->size[1] = 0;
  } else {
    c_st.site = &k_emlrtRSI;
    d = muDoubleScalarFloor(nx + 1.0);
    i = expl_temp.x->size[0] * expl_temp.x->size[1];
    expl_temp.x->size[0] = 1;
    expl_temp.x->size[1] = (int32_T)d;
    emxEnsureCapacity_real_T(&c_st, expl_temp.x, i, &tb_emlrtRTEI);
    if ((int32_T)d >= 1) {
      kidx = (int32_T)d - 1;
      expl_temp.x->data[(int32_T)muDoubleScalarFloor(nx + 1.0) - 1] = 1.0;
      if (expl_temp.x->size[1] >= 2) {
        expl_temp.x->data[0] = -1.0;
        if (expl_temp.x->size[1] >= 3) {
          if ((int32_T)d > 2) {
            delta1 = 1.0 / ((real_T)(int32_T)d - 1.0);
            for (j2 = 2; j2 <= kidx; j2++) {
              expl_temp.x->data[j2 - 1] =
                  (real_T)(((j2 << 1) - (int32_T)d) - 1) * delta1;
            }
            if (((int32_T)d & 1) == 1) {
              expl_temp.x->data[(int32_T)d >> 1] = 0.0;
            }
          } else {
            delta1 = 2.0 / ((real_T)expl_temp.x->size[1] - 1.0);
            i = expl_temp.x->size[1];
            for (j2 = 0; j2 <= i - 3; j2++) {
              expl_temp.x->data[j2 + 1] = ((real_T)j2 + 1.0) * delta1 + -1.0;
            }
          }
        }
      }
    }
  }
  emxInit_real_T(&b_st, &b_I, 2, &fc_emlrtRTEI);
  b_st.site = &h_emlrtRSI;
  linspace(&b_st, T, nt + 1.0, b_I);
  I_data = b_I->data;
  i = expl_temp.t->size[0];
  expl_temp.t->size[0] = b_I->size[1];
  emxEnsureCapacity_real_T(&st, expl_temp.t, i, &ub_emlrtRTEI);
  kidx = b_I->size[1];
  for (i = 0; i < kidx; i++) {
    expl_temp.t->data[i] = I_data[i];
  }
  /*  Nodes matrices in x and t */
  if (!(nt + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(nt + 1.0, &l_emlrtDCI, &st);
  }
  if (nt + 1.0 != (int32_T)muDoubleScalarFloor(nt + 1.0)) {
    emlrtIntegerCheckR2012b(nt + 1.0, &k_emlrtDCI, &st);
  }
  emxInit_real_T(&st, &r, 1, &vb_emlrtRTEI);
  kidx = (int32_T)(nt + 1.0);
  i = r->size[0];
  r->size[0] = (int32_T)(nt + 1.0);
  emxEnsureCapacity_real_T(&st, r, i, &vb_emlrtRTEI);
  r1 = r->data;
  for (i = 0; i < kidx; i++) {
    r1[i] = 1.0;
  }
  b_st.site = &i_emlrtRSI;
  kron(&b_st, r, expl_temp.x, expl_temp.xx);
  if (!(nx + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(nx + 1.0, &n_emlrtDCI, &st);
  }
  if (nx + 1.0 != (int32_T)muDoubleScalarFloor(nx + 1.0)) {
    emlrtIntegerCheckR2012b(nx + 1.0, &m_emlrtDCI, &st);
  }
  i = b_I->size[0] * b_I->size[1];
  b_I->size[0] = 1;
  kidx = (int32_T)(nx + 1.0);
  b_I->size[1] = (int32_T)(nx + 1.0);
  emxEnsureCapacity_real_T(&st, b_I, i, &wb_emlrtRTEI);
  I_data = b_I->data;
  for (i = 0; i < kidx; i++) {
    I_data[i] = 1.0;
  }
  emxInit_real_T(&st, &mesh_pivots, 2, &mc_emlrtRTEI);
  emxInit_real_T(&st, &mesh_elms, 2, &mc_emlrtRTEI);
  emxInit_real_T(&st, &mesh_bot, 2, &mc_emlrtRTEI);
  emxInit_real_T(&st, &mesh_bot_elms, 2, &mc_emlrtRTEI);
  emxInit_real_T(&st, &mesh_top_elms, 2, &mc_emlrtRTEI);
  emxInit_real_T(&st, &mesh_left_elms, 2, &mc_emlrtRTEI);
  emxInit_real_T(&st, &mesh_right_elms, 2, &mc_emlrtRTEI);
  emxInit_real_T(&st, &xx, 2, &yb_emlrtRTEI);
  emxInit_real_T(&st, &b_expl_temp, 2, &oc_emlrtRTEI);
  emxInit_real_T(&st, &c_expl_temp, 2, &oc_emlrtRTEI);
  emxInit_real_T(&st, &d_expl_temp, 2, &oc_emlrtRTEI);
  emxInitStruct_struct_T(&st, &e_expl_temp, &xb_emlrtRTEI);
  b_st.site = &j_emlrtRSI;
  kron(&b_st, expl_temp.t, b_I, expl_temp.tt);
  /*  Build mesh */
  st.site = &c_emlrtRSI;
  CartesianMesh(&st, nx, nt, b_I, mesh_pivots, mesh_elms, mesh_bot, b_expl_temp,
                c_expl_temp, d_expl_temp, mesh_bot_elms, mesh_top_elms,
                mesh_left_elms, mesh_right_elms);
  mesh_elms_data = mesh_elms->data;
  mesh_pivots_data = mesh_pivots->data;
  I_data = b_I->data;
  /*     %% Solve problem */
  expl_temp.ht = d_ht;
  expl_temp.hx = d_hx;
  expl_temp.nt = nt;
  expl_temp.nx = nx;
  emxCopyStruct_struct_T(sp, &e_expl_temp, &expl_temp, &xb_emlrtRTEI);
  st.site = &d_emlrtRSI;
  SolverWaves(&st, c, theta, phi, c, phi, T, mesh_pivots, mesh_elms, mesh_bot,
              mesh_bot_elms, mesh_top_elms, mesh_left_elms, mesh_right_elms,
              e_expl_temp, expl_temp.t);
  /*     %% Plot solution */
  st.site = &e_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 14U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 14U, 0U);
  /*  Evaluate solution over the gauss quadrature nodes */
  /*  Parameters */
  /*    u       : solution of the linear system */
  /*    mesh    : mesh of the problem */
  /*    disc    : discretization struct */
  /*  Optional parameters */
  /*    nq      : number of quadrature nodes in each direction */
  /*    xq      : specific evaluation points */
  /*     %% Unpacking structs */
  /*  Mesh parameters */
  /*  Discretisation paramters */
  i = xx->size[0] * xx->size[1];
  xx->size[0] = expl_temp.xx->size[1];
  xx->size[1] = expl_temp.xx->size[0];
  emxEnsureCapacity_real_T(&st, xx, i, &yb_emlrtRTEI);
  xx_data = xx->data;
  kidx = expl_temp.xx->size[0];
  emxFreeStruct_struct_T(&st, &e_expl_temp);
  emxFree_real_T(&st, &d_expl_temp);
  emxFree_real_T(&st, &c_expl_temp);
  emxFree_real_T(&st, &b_expl_temp);
  emxFree_real_T(&st, &mesh_right_elms);
  emxFree_real_T(&st, &mesh_left_elms);
  emxFree_real_T(&st, &mesh_top_elms);
  emxFree_real_T(&st, &mesh_bot_elms);
  emxFree_real_T(&st, &mesh_bot);
  for (i = 0; i < kidx; i++) {
    j2 = expl_temp.xx->size[1];
    for (i1 = 0; i1 < j2; i1++) {
      xx_data[i1 + xx->size[0] * i] =
          expl_temp.xx->data[i + expl_temp.xx->size[0] * i1];
    }
  }
  emxInit_real_T(&st, &tt, 2, &ac_emlrtRTEI);
  i = tt->size[0] * tt->size[1];
  tt->size[0] = expl_temp.tt->size[1];
  tt->size[1] = expl_temp.tt->size[0];
  emxEnsureCapacity_real_T(&st, tt, i, &ac_emlrtRTEI);
  tt_data = tt->data;
  kidx = expl_temp.tt->size[0];
  for (i = 0; i < kidx; i++) {
    j2 = expl_temp.tt->size[1];
    for (i1 = 0; i1 < j2; i1++) {
      tt_data[i1 + tt->size[0] * i] =
          expl_temp.tt->data[i + expl_temp.tt->size[0] * i1];
    }
  }
  /*  Unpack varargin xq parameter */
  covrtLogIf(&emlrtCoverageInstance, 14U, 0U, 0, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 14U, 1U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 14U, 3U);
  kidx = -1;
  for (j2 = 0; j2 < 9; j2++) {
    d = b[j2];
    xqh[j2] = d_hx * d;
    tqh[j2] = d_ht * d;
    for (i1 = 0; i1 < 9; i1++) {
      xxqh[(kidx + i1) + 1] = xqh[j2];
    }
    kidx += 9;
  }
  kidx = -1;
  for (j2 = 0; j2 < 9; j2++) {
    memcpy(&ttqh[kidx + 1], &tqh[0], 9U * sizeof(real_T));
    kidx += 9;
  }
  emxInit_real_T(&st, &U, 2, &nc_emlrtRTEI);
  /*     %%  Basis functions evaluation */
  /*  Component basis evaluations */
  /*  Tensor product of X and T component kron(T,X) */
  /*     %% Element-wise assembly */
  d = 9.0 * nt;
  if (!(d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d, &d_emlrtDCI, &st);
  }
  delta1 = (int32_T)muDoubleScalarFloor(d);
  if (d != delta1) {
    emlrtIntegerCheckR2012b(d, &c_emlrtDCI, &st);
  }
  i = U->size[0] * U->size[1];
  U->size[0] = (int32_T)d;
  emxEnsureCapacity_real_T(&st, U, i, &bc_emlrtRTEI);
  mesh_elms_tmp = 9.0 * nx;
  if (!(mesh_elms_tmp >= 0.0)) {
    emlrtNonNegativeCheckR2012b(mesh_elms_tmp, &f_emlrtDCI, &st);
  }
  d1 = (int32_T)muDoubleScalarFloor(mesh_elms_tmp);
  if (mesh_elms_tmp != d1) {
    emlrtIntegerCheckR2012b(mesh_elms_tmp, &e_emlrtDCI, &st);
  }
  i = U->size[0] * U->size[1];
  U->size[1] = (int32_T)mesh_elms_tmp;
  emxEnsureCapacity_real_T(&st, U, i, &bc_emlrtRTEI);
  U_data = U->data;
  if (d != delta1) {
    emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
  }
  if (mesh_elms_tmp != d1) {
    emlrtIntegerCheckR2012b(mesh_elms_tmp, &o_emlrtDCI, &st);
  }
  kidx = (int32_T)d * (int32_T)mesh_elms_tmp;
  for (i = 0; i < kidx; i++) {
    U_data[i] = 0.0;
  }
  emxInit_real_T(&st, &X, 2, &nc_emlrtRTEI);
  if (d != delta1) {
    emlrtIntegerCheckR2012b(d, &g_emlrtDCI, &st);
  }
  i = X->size[0] * X->size[1];
  X->size[0] = (int32_T)d;
  emxEnsureCapacity_real_T(&st, X, i, &cc_emlrtRTEI);
  if (mesh_elms_tmp != d1) {
    emlrtIntegerCheckR2012b(mesh_elms_tmp, &h_emlrtDCI, &st);
  }
  i = X->size[0] * X->size[1];
  X->size[1] = (int32_T)mesh_elms_tmp;
  emxEnsureCapacity_real_T(&st, X, i, &cc_emlrtRTEI);
  X_data = X->data;
  if (d != delta1) {
    emlrtIntegerCheckR2012b(d, &p_emlrtDCI, &st);
  }
  if (mesh_elms_tmp != d1) {
    emlrtIntegerCheckR2012b(mesh_elms_tmp, &p_emlrtDCI, &st);
  }
  for (i = 0; i < kidx; i++) {
    X_data[i] = 0.0;
  }
  emxInit_real_T(&st, &b_T, 2, &nc_emlrtRTEI);
  if (d != delta1) {
    emlrtIntegerCheckR2012b(d, &i_emlrtDCI, &st);
  }
  i = b_T->size[0] * b_T->size[1];
  b_T->size[0] = (int32_T)d;
  emxEnsureCapacity_real_T(&st, b_T, i, &dc_emlrtRTEI);
  if (mesh_elms_tmp != d1) {
    emlrtIntegerCheckR2012b(mesh_elms_tmp, &j_emlrtDCI, &st);
  }
  i = b_T->size[0] * b_T->size[1];
  b_T->size[1] = (int32_T)mesh_elms_tmp;
  emxEnsureCapacity_real_T(&st, b_T, i, &dc_emlrtRTEI);
  T_data = b_T->data;
  if (d != delta1) {
    emlrtIntegerCheckR2012b(d, &q_emlrtDCI, &st);
  }
  if (mesh_elms_tmp != d1) {
    emlrtIntegerCheckR2012b(mesh_elms_tmp, &q_emlrtDCI, &st);
  }
  for (i = 0; i < kidx; i++) {
    T_data[i] = 0.0;
  }
  i = (int32_T)nx;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, nx, mxDOUBLE_CLASS, (int32_T)nx,
                                &c_emlrtRTEI, &st);
  emxInit_int32_T(&st, &r2, 1, &nc_emlrtRTEI);
  emxInit_int32_T(&st, &r3, 1, &nc_emlrtRTEI);
  emxInit_real_T(&st, &r4, 1, &hc_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 14U, 0U, 0, 1);
    i1 = (int32_T)nt;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, nt, mxDOUBLE_CLASS, (int32_T)nt,
                                  &b_emlrtRTEI, &st);
    if (0 <= (int32_T)nt - 1) {
      delta1 = (nx + 1.0) * (nt + 1.0);
      b_dv[0] = 0.0;
      b_dv[1] = delta1;
      b_dv[2] = 2.0 * delta1;
      b_dv[3] = 3.0 * delta1;
      b_dv[4] = 0.0;
      b_dv[5] = delta1;
      b_dv[6] = 2.0 * delta1;
      b_dv[7] = 3.0 * delta1;
      b_dv[8] = 0.0;
      b_dv[9] = delta1;
      b_dv[10] = 2.0 * delta1;
      b_dv[11] = 3.0 * delta1;
      b_dv[12] = 0.0;
      b_dv[13] = delta1;
      b_dv[14] = 2.0 * delta1;
      b_dv[15] = 3.0 * delta1;
      g_expl_temp = expl_temp.t->size[0];
      TRANSB1 = 'T';
      TRANSA1 = 'N';
      alpha1 = 1.0;
      beta1 = 0.0;
      m_t = (ptrdiff_t)81;
      n_t = (ptrdiff_t)1;
      k_t = (ptrdiff_t)16;
      lda_t = (ptrdiff_t)81;
      ldb_t = (ptrdiff_t)1;
      ldc_t = (ptrdiff_t)81;
      a = (((real_T)b_i + 1.0) - 1.0) * 9.0 + 1.0;
      b_b = ((real_T)b_i + 1.0) * 9.0;
    }
    for (j = 0; j < i1; j++) {
      covrtLogFor(&emlrtCoverageInstance, 14U, 0U, 1, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 14U, 4U);
      delta1 = ((real_T)b_i + 1.0) + (((real_T)j + 1.0) - 1.0) * nx;
      /*  Get elms dofs */
      if (delta1 != (int32_T)muDoubleScalarFloor(delta1)) {
        emlrtIntegerCheckR2012b(delta1, &b_emlrtDCI, &st);
      }
      if (((int32_T)delta1 < 1) || ((int32_T)delta1 > mesh_pivots->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)delta1, 1, mesh_pivots->size[1],
                                      &d_emlrtBCI, &st);
      }
      if (((int32_T)delta1 < 1) || ((int32_T)delta1 > mesh_elms->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)delta1, 1, mesh_elms->size[0],
                                      &c_emlrtBCI, &st);
      }
      b_st.site = &dk_emlrtRSI;
      covrtLogFcn(&emlrtCoverageInstance, 9U, 0U);
      covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 0U);
      /*  map nodes_ids to degrees of freedom */
      /*  The order is: */
      /*  v(1) v(2) dxv(1) dxv(2) */
      /*  v(3) v(4) dxv(3) dxv(4) */
      /*  dyv(1) dyv(2) dxyv(1) dxvy(2) */
      /*  dyv(3) dyv(4) dxyv(3) dxyv(4) */
      /*  dofs = kron(el_ids, [1,1,1,1]) + n_nodes * kron([1,1,1,1], 0:3); */
      /*  Shuffle the elements to get dofs [v(i), dxv(i), dyv(i), dxyv(i)] */
      /*  Local evaluation grid */
      b_i1 = xx->size[0] * xx->size[1];
      d = mesh_pivots_data[(int32_T)delta1 - 1];
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(mesh_pivots_data[(int32_T)delta1 - 1],
                                &emlrtDCI, &st);
      }
      if (((int32_T)d < 1) || ((int32_T)d > b_i1)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, b_i1, &b_emlrtBCI, &st);
      }
      b_i1 = tt->size[0] * tt->size[1];
      if (((int32_T)d < 1) || ((int32_T)d > b_i1)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, b_i1, &emlrtBCI, &st);
      }
      /*  Evaluate u locally */
      b_st.site = &ek_emlrtRSI;
      indexShapeCheck(&b_st, expl_temp.t->size[0]);
      mesh_elms_tmp = mesh_elms_data[(int32_T)delta1 - 1];
      b_mesh_elms[0] = mesh_elms_tmp;
      b_mesh_elms[1] = mesh_elms_tmp;
      b_mesh_elms[2] = mesh_elms_tmp;
      b_mesh_elms[3] = mesh_elms_tmp;
      mesh_elms_tmp =
          mesh_elms_data[((int32_T)delta1 + mesh_elms->size[0]) - 1];
      b_mesh_elms[4] = mesh_elms_tmp;
      b_mesh_elms[5] = mesh_elms_tmp;
      b_mesh_elms[6] = mesh_elms_tmp;
      b_mesh_elms[7] = mesh_elms_tmp;
      mesh_elms_tmp =
          mesh_elms_data[((int32_T)delta1 + mesh_elms->size[0] * 2) - 1];
      b_mesh_elms[8] = mesh_elms_tmp;
      b_mesh_elms[9] = mesh_elms_tmp;
      b_mesh_elms[10] = mesh_elms_tmp;
      b_mesh_elms[11] = mesh_elms_tmp;
      mesh_elms_tmp =
          mesh_elms_data[((int32_T)delta1 + mesh_elms->size[0] * 3) - 1];
      b_mesh_elms[12] = mesh_elms_tmp;
      b_mesh_elms[13] = mesh_elms_tmp;
      b_mesh_elms[14] = mesh_elms_tmp;
      b_mesh_elms[15] = mesh_elms_tmp;
      for (b_i1 = 0; b_i1 < 16; b_i1++) {
        i2 = iv[b_i1];
        delta1 = b_mesh_elms[i2] + b_dv[i2];
        if (delta1 != (int32_T)muDoubleScalarFloor(delta1)) {
          emlrtIntegerCheckR2012b(delta1, &r_emlrtDCI, &st);
        }
        if (((int32_T)delta1 < 1) || ((int32_T)delta1 > g_expl_temp)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)delta1, 1, g_expl_temp,
                                        &e_emlrtBCI, &st);
        }
        b_dv1[b_i1] = expl_temp.t->data[(int32_T)delta1 - 1];
      }
      b_st.site = &ek_emlrtRSI;
      c_st.site = &hk_emlrtRSI;
      dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &b_a[0], &lda_t,
            &b_dv1[0], &ldb_t, &beta1, &el_u[0], &ldc_t);
      /*  Populate evaluation */
      b_st.site = &fk_emlrtRSI;
      delta1 = (((real_T)j + 1.0) - 1.0) * 9.0 + 1.0;
      mesh_elms_tmp = ((real_T)j + 1.0) * 9.0;
      c_st.site = &y_emlrtRSI;
      if (mesh_elms_tmp < delta1) {
        expl_temp.x->size[0] = 1;
        expl_temp.x->size[1] = 0;
      } else if (delta1 == delta1) {
        b_i1 = expl_temp.x->size[0] * expl_temp.x->size[1];
        expl_temp.x->size[0] = 1;
        kidx = (int32_T)(mesh_elms_tmp - delta1);
        expl_temp.x->size[1] = kidx + 1;
        emxEnsureCapacity_real_T(&c_st, expl_temp.x, b_i1, &ec_emlrtRTEI);
        for (b_i1 = 0; b_i1 <= kidx; b_i1++) {
          expl_temp.x->data[b_i1] = delta1 + (real_T)b_i1;
        }
      } else {
        d_st.site = &v_emlrtRSI;
        c_eml_float_colon(&d_st, delta1, mesh_elms_tmp, expl_temp.x);
      }
      b_st.site = &gk_emlrtRSI;
      c_st.site = &y_emlrtRSI;
      if (b_b < a) {
        b_I->size[0] = 1;
        b_I->size[1] = 0;
      } else if (a == a) {
        b_i1 = b_I->size[0] * b_I->size[1];
        b_I->size[0] = 1;
        kidx = (int32_T)(b_b - a);
        b_I->size[1] = kidx + 1;
        emxEnsureCapacity_real_T(&c_st, b_I, b_i1, &fc_emlrtRTEI);
        I_data = b_I->data;
        for (b_i1 = 0; b_i1 <= kidx; b_i1++) {
          I_data[b_i1] = a + (real_T)b_i1;
        }
      } else {
        d_st.site = &v_emlrtRSI;
        c_eml_float_colon(&d_st, a, b_b, b_I);
        I_data = b_I->data;
      }
      b_i1 = r->size[0];
      r->size[0] = expl_temp.x->size[1];
      emxEnsureCapacity_real_T(&st, r, b_i1, &gc_emlrtRTEI);
      r1 = r->data;
      kidx = expl_temp.x->size[1];
      for (b_i1 = 0; b_i1 < kidx; b_i1++) {
        r1[b_i1] = expl_temp.x->data[b_i1];
      }
      b_i1 = r2->size[0];
      r2->size[0] = r->size[0];
      emxEnsureCapacity_int32_T(&st, r2, b_i1, &gc_emlrtRTEI);
      r5 = r2->data;
      kidx = r->size[0];
      for (b_i1 = 0; b_i1 < kidx; b_i1++) {
        if (r1[b_i1] != (int32_T)muDoubleScalarFloor(r1[b_i1])) {
          emlrtIntegerCheckR2012b(r1[b_i1], &s_emlrtDCI, &st);
        }
        i3 = (int32_T)r1[b_i1];
        if ((i3 < 1) || (i3 > U->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)r1[b_i1], 1, U->size[0],
                                        &f_emlrtBCI, &st);
        }
        r5[b_i1] = i3 - 1;
      }
      b_i1 = r4->size[0];
      r4->size[0] = b_I->size[1];
      emxEnsureCapacity_real_T(&st, r4, b_i1, &hc_emlrtRTEI);
      r6 = r4->data;
      kidx = b_I->size[1];
      for (b_i1 = 0; b_i1 < kidx; b_i1++) {
        r6[b_i1] = I_data[b_i1];
      }
      b_i1 = r3->size[0];
      r3->size[0] = r4->size[0];
      emxEnsureCapacity_int32_T(&st, r3, b_i1, &hc_emlrtRTEI);
      r7 = r3->data;
      kidx = r4->size[0];
      for (b_i1 = 0; b_i1 < kidx; b_i1++) {
        if (r6[b_i1] != (int32_T)muDoubleScalarFloor(r6[b_i1])) {
          emlrtIntegerCheckR2012b(r6[b_i1], &t_emlrtDCI, &st);
        }
        i3 = (int32_T)r6[b_i1];
        if ((i3 < 1) || (i3 > U->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)r6[b_i1], 1, U->size[1],
                                        &g_emlrtBCI, &st);
        }
        r7[b_i1] = i3 - 1;
      }
      iv1[0] = r2->size[0];
      iv1[1] = r3->size[0];
      iv2[0] = 9;
      iv2[1] = 9;
      emlrtSubAssignSizeCheckR2012b(&iv1[0], 2, &iv2[0], 2, &c_emlrtECI, &st);
      for (b_i1 = 0; b_i1 < 9; b_i1++) {
        for (i3 = 0; i3 < 9; i3++) {
          b_el_u[i3 + 9 * b_i1] = el_u[b_i1 + 9 * i3];
        }
      }
      iv1[0] = r2->size[0];
      kidx = r3->size[0];
      for (b_i1 = 0; b_i1 < kidx; b_i1++) {
        j2 = iv1[0];
        for (i3 = 0; i3 < j2; i3++) {
          U_data[r5[i3] + U->size[0] * r7[b_i1]] = b_el_u[i3 + iv1[0] * b_i1];
        }
      }
      b_i1 = r2->size[0];
      r2->size[0] = r->size[0];
      emxEnsureCapacity_int32_T(&st, r2, b_i1, &ic_emlrtRTEI);
      r5 = r2->data;
      kidx = r->size[0];
      for (b_i1 = 0; b_i1 < kidx; b_i1++) {
        i3 = (int32_T)r1[b_i1];
        if ((i3 < 1) || (i3 > X->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)r1[b_i1], 1, X->size[0],
                                        &h_emlrtBCI, &st);
        }
        r5[b_i1] = i3 - 1;
      }
      b_i1 = r3->size[0];
      r3->size[0] = r4->size[0];
      emxEnsureCapacity_int32_T(&st, r3, b_i1, &jc_emlrtRTEI);
      r7 = r3->data;
      kidx = r4->size[0];
      for (b_i1 = 0; b_i1 < kidx; b_i1++) {
        i3 = (int32_T)r6[b_i1];
        if ((i3 < 1) || (i3 > X->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)r6[b_i1], 1, X->size[1],
                                        &i_emlrtBCI, &st);
        }
        r7[b_i1] = i3 - 1;
      }
      iv1[0] = r2->size[0];
      iv1[1] = r3->size[0];
      iv2[0] = 9;
      iv2[1] = 9;
      emlrtSubAssignSizeCheckR2012b(&iv1[0], 2, &iv2[0], 2, &b_emlrtECI, &st);
      delta1 = xx_data[(int32_T)d - 1];
      for (b_i1 = 0; b_i1 < 81; b_i1++) {
        b_el_u[b_i1] = xxqh[b_i1] + delta1;
      }
      iv1[0] = r2->size[0];
      kidx = r3->size[0];
      for (b_i1 = 0; b_i1 < kidx; b_i1++) {
        j2 = iv1[0];
        for (i3 = 0; i3 < j2; i3++) {
          X_data[r5[i3] + X->size[0] * r7[b_i1]] = b_el_u[i3 + iv1[0] * b_i1];
        }
      }
      b_i1 = r2->size[0];
      r2->size[0] = r->size[0];
      emxEnsureCapacity_int32_T(&st, r2, b_i1, &kc_emlrtRTEI);
      r5 = r2->data;
      kidx = r->size[0];
      for (b_i1 = 0; b_i1 < kidx; b_i1++) {
        i3 = (int32_T)r1[b_i1];
        if ((i3 < 1) || (i3 > b_T->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)r1[b_i1], 1, b_T->size[0],
                                        &j_emlrtBCI, &st);
        }
        r5[b_i1] = i3 - 1;
      }
      b_i1 = r3->size[0];
      r3->size[0] = r4->size[0];
      emxEnsureCapacity_int32_T(&st, r3, b_i1, &lc_emlrtRTEI);
      r7 = r3->data;
      kidx = r4->size[0];
      for (b_i1 = 0; b_i1 < kidx; b_i1++) {
        i3 = (int32_T)r6[b_i1];
        if ((i3 < 1) || (i3 > b_T->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)r6[b_i1], 1, b_T->size[1],
                                        &k_emlrtBCI, &st);
        }
        r7[b_i1] = i3 - 1;
      }
      iv1[0] = r2->size[0];
      iv1[1] = r3->size[0];
      iv2[0] = 9;
      iv2[1] = 9;
      emlrtSubAssignSizeCheckR2012b(&iv1[0], 2, &iv2[0], 2, &emlrtECI, &st);
      delta1 = tt_data[(int32_T)d - 1];
      for (b_i1 = 0; b_i1 < 81; b_i1++) {
        b_el_u[b_i1] = ttqh[b_i1] + delta1;
      }
      iv1[0] = r2->size[0];
      kidx = r3->size[0];
      for (b_i1 = 0; b_i1 < kidx; b_i1++) {
        j2 = iv1[0];
        for (i3 = 0; i3 < j2; i3++) {
          T_data[r5[i3] + b_T->size[0] * r7[b_i1]] = b_el_u[i3 + iv1[0] * b_i1];
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    covrtLogFor(&emlrtCoverageInstance, 14U, 0U, 1, 0);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  emxFree_real_T(&st, &r);
  emxFree_real_T(&st, &r4);
  emxFree_int32_T(&st, &r3);
  emxFree_int32_T(&st, &r2);
  emxFree_real_T(&st, &b_I);
  emxFree_real_T(&st, &tt);
  emxFree_real_T(&st, &xx);
  covrtLogFor(&emlrtCoverageInstance, 14U, 0U, 0, 0);
  st.site = &fn_emlrtRSI;
  surf(&st, emlrt_marshallOut(X), emlrt_marshallOut(b_T), emlrt_marshallOut(U),
       &emlrtMCI);
  y = NULL;
  m = emlrtCreateCharArray(2, &b_iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 4, m, &u[0]);
  emlrtAssign(&y, m);
  st.site = &gn_emlrtRSI;
  shading(&st, y, &b_emlrtMCI);
  obj.Value = 'X';
  st.site = &cn_emlrtRSI;
  xlabel(&st, b_emlrt_marshallOut(&st, obj), &c_emlrtMCI);
  obj.Value = 'T';
  st.site = &cn_emlrtRSI;
  ylabel(&st, b_emlrt_marshallOut(&st, obj), &d_emlrtMCI);
  /*     %% Compute errors */
  st.site = &f_emlrtRSI;
  ComputeErrors(&st, expl_temp.t, c, c, phi, c, phi, c, phi, c, phi, c, phi,
                mesh_pivots, mesh_elms, nx, nt, d_hx, d_ht, expl_temp.xx,
                expl_temp.tt, &f_expl_temp);
  err = f_expl_temp.L2E;
  emxFreeStruct_struct_T(sp, &expl_temp);
  emxFree_real_T(sp, &b_T);
  emxFree_real_T(sp, &X);
  emxFree_real_T(sp, &U);
  emxFree_real_T(sp, &mesh_elms);
  emxFree_real_T(sp, &mesh_pivots);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return err;
}

void main_anonFcn11(const emlrtStack *sp, real_T c, real_T phi,
                    const emxArray_real_T *x, const emxArray_real_T *t,
                    emxArray_real_T *varargout_1)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real_T *b_varargout_1;
  emxArray_real_T *b_x;
  const real_T *t_data;
  const real_T *x_data;
  real_T *b_varargout_1_data;
  real_T *b_x_data;
  real_T *varargout_1_data;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  t_data = t->data;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_varargout_1, 1, &vg_emlrtRTEI);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 11U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 11U);
  i = b_varargout_1->size[0];
  b_varargout_1->size[0] = t->size[0];
  emxEnsureCapacity_real_T(sp, b_varargout_1, i, &sg_emlrtRTEI);
  varargout_1_data = b_varargout_1->data;
  loop_ub = t->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargout_1_data[i] = c * t_data[i];
  }
  if ((x->size[0] != b_varargout_1->size[0]) &&
      ((x->size[0] != 1) && (b_varargout_1->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(x->size[0], b_varargout_1->size[0], &v_emlrtECI,
                                (emlrtCTX)sp);
  }
  st.site = &am_emlrtRSI;
  emxInit_real_T(&st, &b_x, 1, &tg_emlrtRTEI);
  if (x->size[0] == b_varargout_1->size[0]) {
    i = b_x->size[0];
    b_x->size[0] = x->size[0];
    emxEnsureCapacity_real_T(&st, b_x, i, &tg_emlrtRTEI);
    b_x_data = b_x->data;
    loop_ub = x->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_x_data[i] = x_data[i] - varargout_1_data[i];
    }
    b_st.site = &oh_emlrtRSI;
    main_anonFcn4(&b_st, b_x, varargout_1);
    b_varargout_1_data = varargout_1->data;
  } else {
    b_st.site = &oh_emlrtRSI;
    k_binary_expand_op(&b_st, varargout_1, oh_emlrtRSI, x, b_varargout_1);
    b_varargout_1_data = varargout_1->data;
  }
  st.site = &am_emlrtRSI;
  if (x->size[0] == b_varargout_1->size[0]) {
    i = b_x->size[0];
    b_x->size[0] = x->size[0];
    emxEnsureCapacity_real_T(&st, b_x, i, &ug_emlrtRTEI);
    b_x_data = b_x->data;
    loop_ub = x->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_x_data[i] = (2.0 - x_data[i]) - varargout_1_data[i];
    }
    b_st.site = &oh_emlrtRSI;
    main_anonFcn4(&b_st, b_x, b_varargout_1);
    varargout_1_data = b_varargout_1->data;
  } else {
    b_st.site = &oh_emlrtRSI;
    j_binary_expand_op(&b_st, b_varargout_1, oh_emlrtRSI, x);
    varargout_1_data = b_varargout_1->data;
  }
  emxFree_real_T(&st, &b_x);
  loop_ub = b_varargout_1->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargout_1_data[i] *= phi;
  }
  if ((varargout_1->size[0] != b_varargout_1->size[0]) &&
      ((varargout_1->size[0] != 1) && (b_varargout_1->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(varargout_1->size[0], b_varargout_1->size[0],
                                &w_emlrtECI, (emlrtCTX)sp);
  }
  if (varargout_1->size[0] == b_varargout_1->size[0]) {
    loop_ub = varargout_1->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_varargout_1_data[i] += varargout_1_data[i];
    }
  } else {
    st.site = &am_emlrtRSI;
    plus(&st, varargout_1, b_varargout_1);
  }
  emxFree_real_T(sp, &b_varargout_1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void main_anonFcn12(const emlrtStack *sp, real_T c, real_T phi,
                    const emxArray_real_T *x, const emxArray_real_T *t,
                    emxArray_real_T *varargout_1)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real_T *b_varargout_1;
  emxArray_real_T *b_x;
  const real_T *t_data;
  const real_T *x_data;
  real_T *b_varargout_1_data;
  real_T *b_x_data;
  real_T *varargout_1_data;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  t_data = t->data;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_varargout_1, 1, &dh_emlrtRTEI);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 12U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 12U);
  i = b_varargout_1->size[0];
  b_varargout_1->size[0] = t->size[0];
  emxEnsureCapacity_real_T(sp, b_varargout_1, i, &ah_emlrtRTEI);
  varargout_1_data = b_varargout_1->data;
  loop_ub = t->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargout_1_data[i] = c * t_data[i];
  }
  if ((x->size[0] != b_varargout_1->size[0]) &&
      ((x->size[0] != 1) && (b_varargout_1->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(x->size[0], b_varargout_1->size[0], &y_emlrtECI,
                                (emlrtCTX)sp);
  }
  st.site = &fm_emlrtRSI;
  emxInit_real_T(&st, &b_x, 1, &bh_emlrtRTEI);
  if (x->size[0] == b_varargout_1->size[0]) {
    i = b_x->size[0];
    b_x->size[0] = x->size[0];
    emxEnsureCapacity_real_T(&st, b_x, i, &bh_emlrtRTEI);
    b_x_data = b_x->data;
    loop_ub = x->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_x_data[i] = x_data[i] - varargout_1_data[i];
    }
    b_st.site = &oh_emlrtRSI;
    b_main_anonFcn5(&b_st, b_x, varargout_1);
    b_varargout_1_data = varargout_1->data;
  } else {
    b_st.site = &oh_emlrtRSI;
    m_binary_expand_op(&b_st, varargout_1, oh_emlrtRSI, x, b_varargout_1);
    b_varargout_1_data = varargout_1->data;
  }
  st.site = &fm_emlrtRSI;
  if (x->size[0] == b_varargout_1->size[0]) {
    i = b_x->size[0];
    b_x->size[0] = x->size[0];
    emxEnsureCapacity_real_T(&st, b_x, i, &ch_emlrtRTEI);
    b_x_data = b_x->data;
    loop_ub = x->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_x_data[i] = (2.0 - x_data[i]) - varargout_1_data[i];
    }
    b_st.site = &oh_emlrtRSI;
    b_main_anonFcn5(&b_st, b_x, b_varargout_1);
    varargout_1_data = b_varargout_1->data;
  } else {
    b_st.site = &oh_emlrtRSI;
    l_binary_expand_op(&b_st, b_varargout_1, oh_emlrtRSI, x);
    varargout_1_data = b_varargout_1->data;
  }
  emxFree_real_T(&st, &b_x);
  loop_ub = b_varargout_1->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargout_1_data[i] *= phi;
  }
  if ((varargout_1->size[0] != b_varargout_1->size[0]) &&
      ((varargout_1->size[0] != 1) && (b_varargout_1->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(varargout_1->size[0], b_varargout_1->size[0],
                                &ab_emlrtECI, (emlrtCTX)sp);
  }
  if (varargout_1->size[0] == b_varargout_1->size[0]) {
    loop_ub = varargout_1->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_varargout_1_data[i] -= varargout_1_data[i];
    }
  } else {
    st.site = &fm_emlrtRSI;
    minus(&st, varargout_1, b_varargout_1);
  }
  emxFree_real_T(sp, &b_varargout_1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void main_anonFcn13(const emlrtStack *sp, real_T c, real_T phi,
                    const emxArray_real_T *x, const emxArray_real_T *t,
                    emxArray_real_T *varargout_1)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real_T *b_varargout_1;
  emxArray_real_T *b_x;
  const real_T *t_data;
  const real_T *x_data;
  real_T a;
  real_T *b_varargout_1_data;
  real_T *b_x_data;
  real_T *varargout_1_data;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  t_data = t->data;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_varargout_1, 1, &jh_emlrtRTEI);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 13U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 13U);
  i = b_varargout_1->size[0];
  b_varargout_1->size[0] = t->size[0];
  emxEnsureCapacity_real_T(sp, b_varargout_1, i, &gh_emlrtRTEI);
  varargout_1_data = b_varargout_1->data;
  loop_ub = t->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargout_1_data[i] = c * t_data[i];
  }
  if ((x->size[0] != b_varargout_1->size[0]) &&
      ((x->size[0] != 1) && (b_varargout_1->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(x->size[0], b_varargout_1->size[0],
                                &db_emlrtECI, (emlrtCTX)sp);
  }
  st.site = &hm_emlrtRSI;
  emxInit_real_T(&st, &b_x, 1, &hh_emlrtRTEI);
  if (x->size[0] == b_varargout_1->size[0]) {
    i = b_x->size[0];
    b_x->size[0] = x->size[0];
    emxEnsureCapacity_real_T(&st, b_x, i, &hh_emlrtRTEI);
    b_x_data = b_x->data;
    loop_ub = x->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_x_data[i] = x_data[i] - varargout_1_data[i];
    }
    b_st.site = &oh_emlrtRSI;
    b_main_anonFcn5(&b_st, b_x, varargout_1);
    b_varargout_1_data = varargout_1->data;
  } else {
    b_st.site = &oh_emlrtRSI;
    m_binary_expand_op(&b_st, varargout_1, oh_emlrtRSI, x, b_varargout_1);
    b_varargout_1_data = varargout_1->data;
  }
  loop_ub = varargout_1->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_varargout_1_data[i] *= -c;
  }
  st.site = &hm_emlrtRSI;
  if (x->size[0] == b_varargout_1->size[0]) {
    i = b_x->size[0];
    b_x->size[0] = x->size[0];
    emxEnsureCapacity_real_T(&st, b_x, i, &ih_emlrtRTEI);
    b_x_data = b_x->data;
    loop_ub = x->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_x_data[i] = (2.0 - x_data[i]) - varargout_1_data[i];
    }
    b_st.site = &oh_emlrtRSI;
    b_main_anonFcn5(&b_st, b_x, b_varargout_1);
    varargout_1_data = b_varargout_1->data;
  } else {
    b_st.site = &oh_emlrtRSI;
    l_binary_expand_op(&b_st, b_varargout_1, oh_emlrtRSI, x);
    varargout_1_data = b_varargout_1->data;
  }
  emxFree_real_T(&st, &b_x);
  a = c * phi;
  loop_ub = b_varargout_1->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargout_1_data[i] *= a;
  }
  if ((varargout_1->size[0] != b_varargout_1->size[0]) &&
      ((varargout_1->size[0] != 1) && (b_varargout_1->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(varargout_1->size[0], b_varargout_1->size[0],
                                &eb_emlrtECI, (emlrtCTX)sp);
  }
  if (varargout_1->size[0] == b_varargout_1->size[0]) {
    loop_ub = varargout_1->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_varargout_1_data[i] -= varargout_1_data[i];
    }
  } else {
    st.site = &hm_emlrtRSI;
    minus(&st, varargout_1, b_varargout_1);
  }
  emxFree_real_T(sp, &b_varargout_1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void main_anonFcn14(const emlrtStack *sp, real_T c, real_T phi,
                    const emxArray_real_T *x, const emxArray_real_T *t,
                    emxArray_real_T *varargout_1)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_real_T *b_varargin_1;
  emxArray_real_T *r;
  emxArray_real_T *varargin_1;
  const real_T *t_data;
  const real_T *x_data;
  real_T *b_varargin_1_data;
  real_T *varargin_1_data;
  real_T *varargout_1_data;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  t_data = t->data;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &varargin_1, 1, &mh_emlrtRTEI);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 14U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 14U);
  i = varargin_1->size[0];
  varargin_1->size[0] = t->size[0];
  emxEnsureCapacity_real_T(sp, varargin_1, i, &kh_emlrtRTEI);
  varargin_1_data = varargin_1->data;
  loop_ub = t->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargin_1_data[i] = c * t_data[i];
  }
  if ((x->size[0] != varargin_1->size[0]) &&
      ((x->size[0] != 1) && (varargin_1->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(x->size[0], varargin_1->size[0], &fb_emlrtECI,
                                (emlrtCTX)sp);
  }
  st.site = &im_emlrtRSI;
  emxInit_real_T(&st, &b_varargin_1, 1, &lh_emlrtRTEI);
  if (x->size[0] == varargin_1->size[0]) {
    i = b_varargin_1->size[0];
    b_varargin_1->size[0] = x->size[0];
    emxEnsureCapacity_real_T(&st, b_varargin_1, i, &lh_emlrtRTEI);
    b_varargin_1_data = b_varargin_1->data;
    loop_ub = x->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_varargin_1_data[i] = x_data[i] - varargin_1_data[i];
    }
  } else {
    b_st.site = &im_emlrtRSI;
    b_minus(&b_st, b_varargin_1, x, varargin_1);
  }
  emxInit_real_T(&st, &r, 1, &nh_emlrtRTEI);
  b_st.site = &oh_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 0U, 6U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 6U);
  c_st.site = &jm_emlrtRSI;
  d_st.site = &oh_emlrtRSI;
  main_anonFcn3(&d_st, b_varargin_1, 0.1, varargout_1);
  varargout_1_data = varargout_1->data;
  c_st.site = &jm_emlrtRSI;
  d_st.site = &oh_emlrtRSI;
  main_anonFcn3(&d_st, b_varargin_1, -0.1, r);
  varargin_1_data = r->data;
  if ((varargout_1->size[0] != r->size[0]) &&
      ((varargout_1->size[0] != 1) && (r->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(varargout_1->size[0], r->size[0], &hb_emlrtECI,
                                &b_st);
  }
  if (varargout_1->size[0] == r->size[0]) {
    loop_ub = varargout_1->size[0];
    for (i = 0; i < loop_ub; i++) {
      varargout_1_data[i] -= varargin_1_data[i];
    }
  } else {
    c_st.site = &jm_emlrtRSI;
    minus(&c_st, varargout_1, r);
    varargout_1_data = varargout_1->data;
  }
  st.site = &im_emlrtRSI;
  if (x->size[0] == varargin_1->size[0]) {
    i = varargin_1->size[0];
    varargin_1->size[0] = x->size[0];
    emxEnsureCapacity_real_T(&st, varargin_1, i, &mh_emlrtRTEI);
    varargin_1_data = varargin_1->data;
    loop_ub = x->size[0];
    for (i = 0; i < loop_ub; i++) {
      varargin_1_data[i] = (2.0 - x_data[i]) - varargin_1_data[i];
    }
  } else {
    b_st.site = &im_emlrtRSI;
    q_binary_expand_op(&b_st, varargin_1, x);
  }
  b_st.site = &oh_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 0U, 6U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 6U);
  c_st.site = &jm_emlrtRSI;
  d_st.site = &oh_emlrtRSI;
  main_anonFcn3(&d_st, varargin_1, 0.1, r);
  varargin_1_data = r->data;
  c_st.site = &jm_emlrtRSI;
  d_st.site = &oh_emlrtRSI;
  main_anonFcn3(&d_st, varargin_1, -0.1, b_varargin_1);
  b_varargin_1_data = b_varargin_1->data;
  emxFree_real_T(&b_st, &varargin_1);
  if ((r->size[0] != b_varargin_1->size[0]) &&
      ((r->size[0] != 1) && (b_varargin_1->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(r->size[0], b_varargin_1->size[0], &hb_emlrtECI,
                                &b_st);
  }
  if (r->size[0] == b_varargin_1->size[0]) {
    loop_ub = r->size[0];
    for (i = 0; i < loop_ub; i++) {
      varargin_1_data[i] = phi * (varargin_1_data[i] - b_varargin_1_data[i]);
    }
  } else {
    st.site = &kn_emlrtRSI;
    p_binary_expand_op(&st, r, phi, b_varargin_1);
    varargin_1_data = r->data;
  }
  emxFree_real_T(sp, &b_varargin_1);
  if ((varargout_1->size[0] != r->size[0]) &&
      ((varargout_1->size[0] != 1) && (r->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(varargout_1->size[0], r->size[0], &gb_emlrtECI,
                                (emlrtCTX)sp);
  }
  if (varargout_1->size[0] == r->size[0]) {
    loop_ub = varargout_1->size[0];
    for (i = 0; i < loop_ub; i++) {
      varargout_1_data[i] += varargin_1_data[i];
    }
  } else {
    st.site = &im_emlrtRSI;
    plus(&st, varargout_1, r);
  }
  emxFree_real_T(sp, &r);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void main_anonFcn15(const emlrtStack *sp, real_T c, real_T phi,
                    const emxArray_real_T *x, const emxArray_real_T *t,
                    emxArray_real_T *varargout_1)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_real_T *b_varargin_1;
  emxArray_real_T *r;
  emxArray_real_T *varargin_1;
  const real_T *t_data;
  const real_T *x_data;
  real_T a;
  real_T *b_varargin_1_data;
  real_T *varargin_1_data;
  real_T *varargout_1_data;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  t_data = t->data;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &varargin_1, 1, &qh_emlrtRTEI);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 15U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 15U);
  i = varargin_1->size[0];
  varargin_1->size[0] = t->size[0];
  emxEnsureCapacity_real_T(sp, varargin_1, i, &oh_emlrtRTEI);
  varargin_1_data = varargin_1->data;
  loop_ub = t->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargin_1_data[i] = c * t_data[i];
  }
  if ((x->size[0] != varargin_1->size[0]) &&
      ((x->size[0] != 1) && (varargin_1->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(x->size[0], varargin_1->size[0], &jb_emlrtECI,
                                (emlrtCTX)sp);
  }
  st.site = &mm_emlrtRSI;
  emxInit_real_T(&st, &b_varargin_1, 1, &ph_emlrtRTEI);
  if (x->size[0] == varargin_1->size[0]) {
    i = b_varargin_1->size[0];
    b_varargin_1->size[0] = x->size[0];
    emxEnsureCapacity_real_T(&st, b_varargin_1, i, &ph_emlrtRTEI);
    b_varargin_1_data = b_varargin_1->data;
    loop_ub = x->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_varargin_1_data[i] = x_data[i] - varargin_1_data[i];
    }
  } else {
    b_st.site = &mm_emlrtRSI;
    b_minus(&b_st, b_varargin_1, x, varargin_1);
  }
  emxInit_real_T(&st, &r, 1, &rh_emlrtRTEI);
  b_st.site = &oh_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 0U, 6U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 6U);
  c_st.site = &jm_emlrtRSI;
  d_st.site = &oh_emlrtRSI;
  main_anonFcn3(&d_st, b_varargin_1, 0.1, varargout_1);
  varargout_1_data = varargout_1->data;
  c_st.site = &jm_emlrtRSI;
  d_st.site = &oh_emlrtRSI;
  main_anonFcn3(&d_st, b_varargin_1, -0.1, r);
  varargin_1_data = r->data;
  if ((varargout_1->size[0] != r->size[0]) &&
      ((varargout_1->size[0] != 1) && (r->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(varargout_1->size[0], r->size[0], &hb_emlrtECI,
                                &b_st);
  }
  if (varargout_1->size[0] == r->size[0]) {
    loop_ub = varargout_1->size[0];
    for (i = 0; i < loop_ub; i++) {
      varargout_1_data[i] -= varargin_1_data[i];
    }
  } else {
    c_st.site = &jm_emlrtRSI;
    minus(&c_st, varargout_1, r);
    varargout_1_data = varargout_1->data;
  }
  st.site = &mm_emlrtRSI;
  if (x->size[0] == varargin_1->size[0]) {
    i = varargin_1->size[0];
    varargin_1->size[0] = x->size[0];
    emxEnsureCapacity_real_T(&st, varargin_1, i, &qh_emlrtRTEI);
    varargin_1_data = varargin_1->data;
    loop_ub = x->size[0];
    for (i = 0; i < loop_ub; i++) {
      varargin_1_data[i] = (2.0 - x_data[i]) - varargin_1_data[i];
    }
  } else {
    b_st.site = &mm_emlrtRSI;
    q_binary_expand_op(&b_st, varargin_1, x);
  }
  b_st.site = &oh_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 0U, 6U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 6U);
  c_st.site = &jm_emlrtRSI;
  d_st.site = &oh_emlrtRSI;
  main_anonFcn3(&d_st, varargin_1, 0.1, r);
  varargin_1_data = r->data;
  c_st.site = &jm_emlrtRSI;
  d_st.site = &oh_emlrtRSI;
  main_anonFcn3(&d_st, varargin_1, -0.1, b_varargin_1);
  b_varargin_1_data = b_varargin_1->data;
  emxFree_real_T(&b_st, &varargin_1);
  if ((r->size[0] != b_varargin_1->size[0]) &&
      ((r->size[0] != 1) && (b_varargin_1->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(r->size[0], b_varargin_1->size[0], &hb_emlrtECI,
                                &b_st);
  }
  if (r->size[0] == b_varargin_1->size[0]) {
    loop_ub = r->size[0];
    for (i = 0; i < loop_ub; i++) {
      varargin_1_data[i] = phi * (varargin_1_data[i] - b_varargin_1_data[i]);
    }
  } else {
    st.site = &kn_emlrtRSI;
    p_binary_expand_op(&st, r, phi, b_varargin_1);
    varargin_1_data = r->data;
  }
  emxFree_real_T(sp, &b_varargin_1);
  if ((varargout_1->size[0] != r->size[0]) &&
      ((varargout_1->size[0] != 1) && (r->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(varargout_1->size[0], r->size[0], &ib_emlrtECI,
                                (emlrtCTX)sp);
  }
  st.site = &mm_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  a = c * c;
  if (varargout_1->size[0] == r->size[0]) {
    loop_ub = varargout_1->size[0];
    for (i = 0; i < loop_ub; i++) {
      varargout_1_data[i] = a * (varargout_1_data[i] + varargin_1_data[i]);
    }
  } else {
    st.site = &kn_emlrtRSI;
    r_binary_expand_op(&st, varargout_1, a, r);
  }
  emxFree_real_T(sp, &r);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void main_anonFcn4(const emlrtStack *sp, const emxArray_real_T *x,
                   emxArray_real_T *varargout_1)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_real_T *a;
  const real_T *x_data;
  real_T varargin_1;
  real_T *a_data;
  real_T *varargout_1_data;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &a, 1, &wg_emlrtRTEI);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 4U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 4U);
  st.site = &bm_emlrtRSI;
  b_st.site = &oh_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 0U, 1U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 1U);
  c_st.site = &cm_emlrtRSI;
  i = a->size[0];
  a->size[0] = x->size[0];
  emxEnsureCapacity_real_T(&c_st, a, i, &wg_emlrtRTEI);
  a_data = a->data;
  loop_ub = x->size[0];
  for (i = 0; i < loop_ub; i++) {
    a_data[i] = x_data[i] - 0.1;
  }
  i = varargout_1->size[0];
  varargout_1->size[0] = a->size[0];
  emxEnsureCapacity_real_T(&b_st, varargout_1, i, &xg_emlrtRTEI);
  varargout_1_data = varargout_1->data;
  loop_ub = a->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargin_1 = a_data[i];
    varargout_1_data[i] = varargin_1 * varargin_1;
  }
  loop_ub = varargout_1->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargout_1_data[i] *= -20.0;
  }
  c_st.site = &cm_emlrtRSI;
  b_exp(&c_st, varargout_1);
  varargout_1_data = varargout_1->data;
  st.site = &bm_emlrtRSI;
  b_st.site = &oh_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 0U, 1U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 1U);
  c_st.site = &cm_emlrtRSI;
  i = a->size[0];
  a->size[0] = x->size[0];
  emxEnsureCapacity_real_T(&c_st, a, i, &wg_emlrtRTEI);
  a_data = a->data;
  loop_ub = x->size[0];
  for (i = 0; i < loop_ub; i++) {
    a_data[i] = x_data[i] - -0.1;
  }
  loop_ub = a->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargin_1 = a_data[i];
    a_data[i] = varargin_1 * varargin_1;
  }
  loop_ub = a->size[0];
  for (i = 0; i < loop_ub; i++) {
    a_data[i] *= -20.0;
  }
  c_st.site = &cm_emlrtRSI;
  b_exp(&c_st, a);
  a_data = a->data;
  if ((varargout_1->size[0] != a->size[0]) &&
      ((varargout_1->size[0] != 1) && (a->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(varargout_1->size[0], a->size[0], &x_emlrtECI,
                                (emlrtCTX)sp);
  }
  if (varargout_1->size[0] == a->size[0]) {
    loop_ub = varargout_1->size[0];
    for (i = 0; i < loop_ub; i++) {
      varargout_1_data[i] -= a_data[i];
    }
  } else {
    st.site = &bm_emlrtRSI;
    minus(&st, varargout_1, a);
  }
  emxFree_real_T(sp, &a);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void main_anonFcn5(const real_T x[8], real_T varargout_1[8])
{
  real_T b[8];
  real_T y_tmp[8];
  real_T d;
  int32_T k;
  covrtLogFcn(&emlrtCoverageInstance, 0U, 5U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 5U);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 2U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 2U);
  for (k = 0; k < 8; k++) {
    d = x[k];
    varargout_1[k] = muDoubleScalarExp(-20.0 * ((0.1 - d) * (0.1 - d)));
    y_tmp[k] = 2.0 * d;
  }
  covrtLogFcn(&emlrtCoverageInstance, 0U, 2U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 2U);
  for (k = 0; k < 8; k++) {
    d = x[k];
    b[k] = muDoubleScalarExp(-20.0 * ((-0.1 - d) * (-0.1 - d)));
  }
  for (k = 0; k < 8; k++) {
    d = y_tmp[k];
    varargout_1[k] =
        20.0 * varargout_1[k] * (0.2 - d) - 20.0 * b[k] * (-0.2 - d);
  }
}

/* End of code generation (main.c) */
