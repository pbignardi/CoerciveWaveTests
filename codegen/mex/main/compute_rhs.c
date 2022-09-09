/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * compute_rhs.c
 *
 * Code generation for function 'compute_rhs'
 *
 */

/* Include files */
#include "compute_rhs.h"
#include "indexShapeCheck.h"
#include "kron.h"
#include "main.h"
#include "main_data.h"
#include "main_emxutil.h"
#include "main_internal_types.h"
#include "main_types.h"
#include "mapper.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo ag_emlrtRSI = {
    34,            /* lineNo */
    "compute_rhs", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m" /* pathName */
};

static emlrtRSInfo bg_emlrtRSI = {
    35,            /* lineNo */
    "compute_rhs", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m" /* pathName */
};

static emlrtRSInfo ng_emlrtRSI = {
    118,           /* lineNo */
    "compute_rhs", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m" /* pathName */
};

static emlrtRSInfo tg_emlrtRSI = {
    140,           /* lineNo */
    "compute_rhs", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m" /* pathName */
};

static emlrtRSInfo xg_emlrtRSI = {
    160,           /* lineNo */
    "compute_rhs", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m" /* pathName */
};

static emlrtRSInfo ch_emlrtRSI = {
    180,           /* lineNo */
    "compute_rhs", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m" /* pathName */
};

static emlrtBCInfo gb_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    168,           /* lineNo */
    24,            /* colNo */
    "elms",        /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtDCInfo gb_emlrtDCI = {
    168,           /* lineNo */
    24,            /* colNo */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    1                                               /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    167,           /* lineNo */
    24,            /* colNo */
    "right_elms",  /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    148,           /* lineNo */
    24,            /* colNo */
    "elms",        /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtDCInfo hb_emlrtDCI = {
    148,           /* lineNo */
    24,            /* colNo */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    1                                               /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    147,           /* lineNo */
    23,            /* colNo */
    "left_elms",   /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    126,           /* lineNo */
    24,            /* colNo */
    "elms",        /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtDCInfo ib_emlrtDCI = {
    126,           /* lineNo */
    24,            /* colNo */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    1                                               /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    125,           /* lineNo */
    22,            /* colNo */
    "bot_elms",    /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    101,           /* lineNo */
    24,            /* colNo */
    "elms",        /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtDCInfo jb_emlrtDCI = {
    34,            /* lineNo */
    24,            /* colNo */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    1                                               /* checkKind */
};

static emlrtDCInfo kb_emlrtDCI = {
    34,            /* lineNo */
    24,            /* colNo */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    4                                               /* checkKind */
};

static emlrtDCInfo lb_emlrtDCI = {
    35,            /* lineNo */
    29,            /* colNo */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    1                                               /* checkKind */
};

static emlrtDCInfo mb_emlrtDCI = {
    35,            /* lineNo */
    29,            /* colNo */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    4                                               /* checkKind */
};

static emlrtDCInfo nb_emlrtDCI = {
    98,            /* lineNo */
    5,             /* colNo */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    1                                               /* checkKind */
};

static emlrtDCInfo ob_emlrtDCI = {
    98,            /* lineNo */
    5,             /* colNo */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    4                                               /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    104,           /* lineNo */
    27,            /* colNo */
    "xx",          /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtDCInfo pb_emlrtDCI = {
    104,           /* lineNo */
    27,            /* colNo */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    1                                               /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    104,           /* lineNo */
    34,            /* colNo */
    "pivots",      /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    105,           /* lineNo */
    27,            /* colNo */
    "tt",          /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtDCInfo qb_emlrtDCI = {
    105,           /* lineNo */
    27,            /* colNo */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    1                                               /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    105,           /* lineNo */
    34,            /* colNo */
    "pivots",      /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    130,           /* lineNo */
    33,            /* colNo */
    "xx",          /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtDCInfo rb_emlrtDCI = {
    130,           /* lineNo */
    33,            /* colNo */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    1                                               /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    130,           /* lineNo */
    40,            /* colNo */
    "pivots",      /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    152,           /* lineNo */
    38,            /* colNo */
    "tt",          /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtDCInfo sb_emlrtDCI = {
    152,           /* lineNo */
    38,            /* colNo */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    1                                               /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    152,           /* lineNo */
    45,            /* colNo */
    "pivots",      /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    172,           /* lineNo */
    38,            /* colNo */
    "tt",          /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtDCInfo tb_emlrtDCI = {
    172,           /* lineNo */
    38,            /* colNo */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    1                                               /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    172,           /* lineNo */
    45,            /* colNo */
    "pivots",      /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    118,           /* lineNo */
    24,            /* colNo */
    "F",           /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    160,           /* lineNo */
    24,            /* colNo */
    "F",           /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    118,           /* lineNo */
    9,             /* colNo */
    "F",           /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtDCInfo ub_emlrtDCI = {
    118,           /* lineNo */
    9,             /* colNo */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    1                                               /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    160,           /* lineNo */
    9,             /* colNo */
    "F",           /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtDCInfo vb_emlrtDCI = {
    160,           /* lineNo */
    9,             /* colNo */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    1                                               /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    180,           /* lineNo */
    24,            /* colNo */
    "F",           /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    180,           /* lineNo */
    9,             /* colNo */
    "F",           /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtDCInfo wb_emlrtDCI = {
    180,           /* lineNo */
    9,             /* colNo */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    1                                               /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    140,           /* lineNo */
    24,            /* colNo */
    "F",           /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    140,           /* lineNo */
    9,             /* colNo */
    "F",           /* aName */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    0                                               /* checkKind */
};

static emlrtDCInfo xb_emlrtDCI = {
    140,           /* lineNo */
    9,             /* colNo */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m", /* pName */
    1                                               /* checkKind */
};

static emlrtRTEInfo re_emlrtRTEI = {
    34,            /* lineNo */
    15,            /* colNo */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m" /* pName */
};

static emlrtRTEInfo se_emlrtRTEI = {
    35,            /* lineNo */
    23,            /* colNo */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m" /* pName */
};

static emlrtRTEInfo te_emlrtRTEI = {
    98,            /* lineNo */
    5,             /* colNo */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m" /* pName */
};

static emlrtRTEInfo ue_emlrtRTEI = {
    34,            /* lineNo */
    5,             /* colNo */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m" /* pName */
};

static emlrtRTEInfo ve_emlrtRTEI = {
    35,            /* lineNo */
    5,             /* colNo */
    "compute_rhs", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\compute_rhs.m" /* pName */
};

/* Function Definitions */
void compute_rhs(const emlrtStack *sp, real_T p_u0_workspace_phi,
                 real_T p_u1_workspace_c, real_T p_u1_workspace_phi,
                 const emxArray_real_T *mesh_pivots,
                 const emxArray_real_T *mesh_elms,
                 const emxArray_real_T *mesh_bot_elms,
                 const emxArray_real_T *mesh_left_elms,
                 const emxArray_real_T *mesh_right_elms, real_T disc_nx,
                 real_T disc_nt, real_T disc_hx, real_T disc_ht,
                 const emxArray_real_T *disc_x, const emxArray_real_T *disc_t,
                 const b_struct_T *parameters, emxArray_real_T *F)
{
  static const real_T b_dv[4] = {1.0, 0.0, 0.0, 0.0};
  static const real_T b_dv1[4] = {0.0, 1.0, 0.0, 0.0};
  emlrtStack st;
  emxArray_real_T *r;
  emxArray_real_T *r1;
  emxArray_real_T *tt;
  emxArray_real_T *xx;
  real_T Lapv_Q[1024];
  real_T b_f_eval[1024];
  real_T gradv_Q[1024];
  real_T vt_Q[1024];
  real_T vtt_Q[1024];
  real_T h_a[128];
  real_T vt_0[128];
  real_T vt_a[128];
  real_T vt_b[128];
  real_T vx_0[128];
  real_T vx_a[128];
  real_T vx_b[128];
  real_T b_el_xq[64];
  real_T el_tq[64];
  real_T f_eval[64];
  real_T ttqh[64];
  real_T wqxt[64];
  real_T xxqh[64];
  real_T c_a[32];
  real_T dpsi_T[32];
  real_T dpsi_X[32];
  real_T b_F[16];
  real_T el_dofs[16];
  real_T local_rhs_Q[16];
  real_T G[8];
  real_T U0x[8];
  real_T U1[8];
  real_T b_el_tq[8];
  real_T el_xq[8];
  real_T wqt[8];
  real_T wqx[8];
  real_T d_a[4];
  const real_T *mesh_bot_elms_data;
  const real_T *mesh_elms_data;
  const real_T *mesh_left_elms_data;
  const real_T *mesh_pivots_data;
  const real_T *mesh_right_elms_data;
  real_T Tstar;
  real_T a;
  real_T a_tmp;
  real_T b;
  real_T b_a;
  real_T b_a_tmp;
  real_T b_p_u1_workspace_c;
  real_T b_y;
  real_T beta;
  real_T c;
  real_T e_a;
  real_T f_a;
  real_T g_a;
  real_T ndofs;
  real_T y;
  real_T *F_data;
  real_T *tt_data;
  real_T *xx_data;
  int32_T b_i;
  int32_T e;
  int32_T i;
  int32_T i1;
  int32_T i2;
  st.prev = sp;
  st.tls = sp->tls;
  mesh_right_elms_data = mesh_right_elms->data;
  mesh_left_elms_data = mesh_left_elms->data;
  mesh_bot_elms_data = mesh_bot_elms->data;
  mesh_elms_data = mesh_elms->data;
  mesh_pivots_data = mesh_pivots->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 11U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 0U);
  /*     %% Unpacking parameters */
  /*  Mesh parameters */
  /*  Boundary elms */
  /*  Problem parameters */
  /*  Formulation parameters */
  beta = parameters->beta;
  Tstar = parameters->Tstar;
  /*  Discretisation parameters */
  if (!(disc_nt + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(disc_nt + 1.0, &kb_emlrtDCI, (emlrtCTX)sp);
  }
  if (disc_nt + 1.0 != (int32_T)muDoubleScalarFloor(disc_nt + 1.0)) {
    emlrtIntegerCheckR2012b(disc_nt + 1.0, &jb_emlrtDCI, (emlrtCTX)sp);
  }
  emxInit_real_T(sp, &r, 2, &re_emlrtRTEI);
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  b_i = (int32_T)(disc_nt + 1.0);
  r->size[1] = (int32_T)(disc_nt + 1.0);
  emxEnsureCapacity_real_T(sp, r, i, &re_emlrtRTEI);
  tt_data = r->data;
  for (i = 0; i < b_i; i++) {
    tt_data[i] = 1.0;
  }
  emxInit_real_T(sp, &xx, 2, &ue_emlrtRTEI);
  st.site = &ag_emlrtRSI;
  c_kron(&st, r, disc_x, xx);
  xx_data = xx->data;
  emxFree_real_T(sp, &r);
  if (!(disc_nx + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(disc_nx + 1.0, &mb_emlrtDCI, (emlrtCTX)sp);
  }
  if (disc_nx + 1.0 != (int32_T)muDoubleScalarFloor(disc_nx + 1.0)) {
    emlrtIntegerCheckR2012b(disc_nx + 1.0, &lb_emlrtDCI, (emlrtCTX)sp);
  }
  emxInit_real_T(sp, &r1, 1, &se_emlrtRTEI);
  b_i = (int32_T)(disc_nx + 1.0);
  i = r1->size[0];
  r1->size[0] = (int32_T)(disc_nx + 1.0);
  emxEnsureCapacity_real_T(sp, r1, i, &se_emlrtRTEI);
  tt_data = r1->data;
  for (i = 0; i < b_i; i++) {
    tt_data[i] = 1.0;
  }
  emxInit_real_T(sp, &tt, 1, &ve_emlrtRTEI);
  st.site = &bg_emlrtRSI;
  d_kron(&st, disc_t, r1, tt);
  tt_data = tt->data;
  ndofs = 4.0 * (disc_nx + 1.0) * (disc_nt + 1.0);
  /*  Quadrature variables */
  /*  Local quadrature nodes and weights */
  emxFree_real_T(sp, &r1);
  for (b_i = 0; b_i < 8; b_i++) {
    a_tmp = dv[b_i];
    wqx[b_i] = disc_hx * a_tmp;
    wqt[b_i] = disc_ht * a_tmp;
    U0x[b_i] = 1.0;
    el_xq[b_i] = disc_hx * dv1[b_i];
  }
  e_kron(wqt, wqx, wqxt);
  e_kron(U0x, el_xq, xxqh);
  for (i = 0; i < 8; i++) {
    el_xq[i] = disc_ht * dv1[i];
    U0x[i] = 1.0;
  }
  e_kron(el_xq, U0x, ttqh);
  /*     %% Component basis functions evaluation */
  /*  Component basis evaluations */
  /*  When using dpsi and ddpsi, remember to divide by hx and ht to account */
  /*  for derivation chain rule scaling. */
  /*  Basis function evaluation over grid */
  b_a_tmp = 1.0 / disc_ht;
  for (i = 0; i < 32; i++) {
    dpsi_T[i] = b_a_tmp * dv2[i];
  }
  a = muDoubleScalarPower(disc_ht, -2.0);
  a_tmp = 1.0 / disc_hx;
  for (i = 0; i < 32; i++) {
    dpsi_X[i] = a_tmp * dv2[i];
  }
  b_a = muDoubleScalarPower(disc_hx, -2.0);
  /*  Basis function evaluation at boundary */
  /*     %% Operator evaluations */
  /*  Q local terms */
  f_kron(dv3, dpsi_X, gradv_Q);
  f_kron(dpsi_T, dv3, vt_Q);
  for (i = 0; i < 32; i++) {
    c_a[i] = a * dv4[i];
  }
  f_kron(c_a, dv3, vtt_Q);
  for (i = 0; i < 32; i++) {
    c_a[i] = b_a * dv4[i];
  }
  f_kron(dv3, c_a, Lapv_Q);
  /*  Omega0 local terms */
  d_a[0] = 0.0 * b_a_tmp;
  d_a[1] = 0.0 * b_a_tmp;
  d_a[2] = b_a_tmp;
  d_a[3] = 0.0 * b_a_tmp;
  g_kron(d_a, dv3, vt_0);
  g_kron(b_dv, dpsi_X, vx_0);
  /*  Sigma=a local terms */
  h_kron(dpsi_T, b_dv, vt_a);
  d_a[0] = 0.0 * a_tmp;
  d_a[1] = 0.0 * a_tmp;
  d_a[2] = a_tmp;
  d_a[3] = 0.0 * a_tmp;
  h_kron(dv3, d_a, vx_a);
  /*  Sigma=b local terms */
  h_kron(dpsi_T, b_dv1, vt_b);
  d_a[0] = 0.0 * a_tmp;
  d_a[1] = 0.0 * a_tmp;
  d_a[2] = 0.0 * a_tmp;
  d_a[3] = a_tmp;
  h_kron(dv3, d_a, vx_b);
  /*     %% Q- Element-wise assembly */
  if (!(ndofs + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(ndofs + 1.0, &ob_emlrtDCI, (emlrtCTX)sp);
  }
  a_tmp = (int32_T)muDoubleScalarFloor(ndofs + 1.0);
  if (ndofs + 1.0 != a_tmp) {
    emlrtIntegerCheckR2012b(ndofs + 1.0, &nb_emlrtDCI, (emlrtCTX)sp);
  }
  i = F->size[0];
  b_i = (int32_T)(ndofs + 1.0);
  F->size[0] = (int32_T)(ndofs + 1.0);
  emxEnsureCapacity_real_T(sp, F, i, &te_emlrtRTEI);
  F_data = F->data;
  if (!(ndofs + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(ndofs + 1.0, &ob_emlrtDCI, (emlrtCTX)sp);
  }
  if (ndofs + 1.0 != a_tmp) {
    emlrtIntegerCheckR2012b(ndofs + 1.0, &nb_emlrtDCI, (emlrtCTX)sp);
  }
  for (i = 0; i < b_i; i++) {
    F_data[i] = 0.0;
  }
  i = mesh_elms->size[0];
  if (0 <= mesh_elms->size[0] - 1) {
    b = parameters->c * parameters->c;
    c = parameters->T * parameters->T;
  }
  for (e = 0; e < i; e++) {
    covrtLogFor(&emlrtCoverageInstance, 11U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 1U);
    /*  Get element nodes and DOFs */
    if (e + 1 > mesh_elms->size[0]) {
      emlrtDynamicBoundsCheckR2012b(e + 1, 1, mesh_elms->size[0], &mb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    d_a[0] = mesh_elms_data[e];
    d_a[1] = mesh_elms_data[e + mesh_elms->size[0]];
    d_a[2] = mesh_elms_data[e + mesh_elms->size[0] * 2];
    d_a[3] = mesh_elms_data[e + mesh_elms->size[0] * 3];
    mapper(d_a, disc_nx, disc_nt, el_dofs);
    /*  Move quadrature nodes */
    if (e + 1 > mesh_pivots->size[1]) {
      emlrtDynamicBoundsCheckR2012b(e + 1, 1, mesh_pivots->size[1],
                                    &ob_emlrtBCI, (emlrtCTX)sp);
    }
    a_tmp = mesh_pivots_data[e];
    if (a_tmp != (int32_T)muDoubleScalarFloor(a_tmp)) {
      emlrtIntegerCheckR2012b(a_tmp, &pb_emlrtDCI, (emlrtCTX)sp);
    }
    if (((int32_T)a_tmp < 1) || ((int32_T)a_tmp > xx->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)a_tmp, 1, xx->size[1],
                                    &nb_emlrtBCI, (emlrtCTX)sp);
    }
    b_a_tmp = xx_data[(int32_T)a_tmp - 1];
    for (i1 = 0; i1 < 64; i1++) {
      b_el_xq[i1] = xxqh[i1] + b_a_tmp;
    }
    if (e + 1 > mesh_pivots->size[1]) {
      emlrtDynamicBoundsCheckR2012b(e + 1, 1, mesh_pivots->size[1],
                                    &qb_emlrtBCI, (emlrtCTX)sp);
    }
    a_tmp = mesh_pivots_data[e];
    if (a_tmp != (int32_T)muDoubleScalarFloor(a_tmp)) {
      emlrtIntegerCheckR2012b(a_tmp, &qb_emlrtDCI, (emlrtCTX)sp);
    }
    if (((int32_T)a_tmp < 1) || ((int32_T)a_tmp > tt->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)a_tmp, 1, tt->size[0],
                                    &pb_emlrtBCI, (emlrtCTX)sp);
    }
    b_a_tmp = tt_data[(int32_T)a_tmp - 1];
    for (i1 = 0; i1 < 64; i1++) {
      el_tq[i1] = ttqh[i1] + b_a_tmp;
    }
    /*  Function f local evaluation */
    covrtLogFcn(&emlrtCoverageInstance, 0U, 7U);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 7U);
    for (b_i = 0; b_i < 64; b_i++) {
      f_eval[b_i] = b_el_xq[b_i] * 0.0 + el_tq[b_i] * 0.0;
    }
    /*         %% Q domain integral */
    /*  Compute Zv */
    /*  Compute Wv */
    /*  Integrate using Gauss quadrature */
    for (i1 = 0; i1 < 16; i1++) {
      for (i2 = 0; i2 < 64; i2++) {
        b_i = i2 + (i1 << 6);
        b_f_eval[b_i] = f_eval[i2] *
                        (-(-b_el_xq[i2] * gradv_Q[b_i] +
                           (el_tq[i2] - Tstar) * vt_Q[b_i] * beta) +
                         (vtt_Q[b_i] - Lapv_Q[b_i] * b) / c) *
                        wqxt[i2];
      }
    }
    sum(b_f_eval, local_rhs_Q);
    /*         %% Sigma=a domain integral */
    b_i = F->size[0];
    st.site = &ng_emlrtRSI;
    indexShapeCheck(&st, F->size[0]);
    for (i1 = 0; i1 < 16; i1++) {
      a_tmp = el_dofs[i1];
      if (((int32_T)a_tmp < 1) || ((int32_T)a_tmp > b_i)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)a_tmp, 1, b_i, &xb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_F[i1] = F_data[(int32_T)a_tmp - 1] + local_rhs_Q[i1];
    }
    for (i1 = 0; i1 < 16; i1++) {
      a_tmp = el_dofs[i1];
      if (a_tmp != (int32_T)muDoubleScalarFloor(a_tmp)) {
        emlrtIntegerCheckR2012b(a_tmp, &ub_emlrtDCI, (emlrtCTX)sp);
      }
      if (((int32_T)a_tmp < 1) || ((int32_T)a_tmp > b_i)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)a_tmp, 1, b_i, &ac_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      F_data[(int32_T)a_tmp - 1] = b_F[i1];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 11U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 2U);
  /*     %% Omega0- Element-wise assembly */
  i = mesh_bot_elms->size[1];
  if (0 <= mesh_bot_elms->size[1] - 1) {
    e_a = p_u1_workspace_c * p_u1_workspace_phi;
    b_p_u1_workspace_c = -p_u1_workspace_c;
    f_a = parameters->c * parameters->c;
    g_a = parameters->beta * parameters->Tstar;
  }
  for (e = 0; e < i; e++) {
    covrtLogFor(&emlrtCoverageInstance, 11U, 0U, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 3U);
    /*  Get element nodes and DOFs */
    if (e + 1 > mesh_bot_elms->size[1]) {
      emlrtDynamicBoundsCheckR2012b(e + 1, 1, mesh_bot_elms->size[1],
                                    &lb_emlrtBCI, (emlrtCTX)sp);
    }
    if (mesh_bot_elms_data[e] !=
        (int32_T)muDoubleScalarFloor(mesh_bot_elms_data[e])) {
      emlrtIntegerCheckR2012b(mesh_bot_elms_data[e], &ib_emlrtDCI,
                              (emlrtCTX)sp);
    }
    b_i = (int32_T)mesh_bot_elms_data[e];
    if ((b_i < 1) || (b_i > mesh_elms->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, mesh_elms->size[0], &kb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    d_a[0] = mesh_elms_data[b_i - 1];
    d_a[1] = mesh_elms_data[(b_i + mesh_elms->size[0]) - 1];
    d_a[2] = mesh_elms_data[(b_i + mesh_elms->size[0] * 2) - 1];
    d_a[3] = mesh_elms_data[(b_i + mesh_elms->size[0] * 3) - 1];
    mapper(d_a, disc_nx, disc_nt, el_dofs);
    /*  Move quadrature nodes */
    if (b_i > mesh_pivots->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, mesh_pivots->size[1], &sb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    a_tmp = mesh_pivots_data[b_i - 1];
    if (a_tmp != (int32_T)muDoubleScalarFloor(a_tmp)) {
      emlrtIntegerCheckR2012b(a_tmp, &rb_emlrtDCI, (emlrtCTX)sp);
    }
    if (((int32_T)a_tmp < 1) || ((int32_T)a_tmp > xx->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)a_tmp, 1, xx->size[1],
                                    &rb_emlrtBCI, (emlrtCTX)sp);
    }
    b_a_tmp = xx_data[(int32_T)a_tmp - 1];
    for (i1 = 0; i1 < 8; i1++) {
      el_xq[i1] = xxqh[i1] + b_a_tmp;
    }
    /*  u1 and u0x evaluation  */
    covrtLogFcn(&emlrtCoverageInstance, 0U, 9U);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 9U);
    main_anonFcn5(el_xq, U0x);
    for (b_i = 0; b_i < 8; b_i++) {
      G[b_i] = 2.0 - el_xq[b_i];
    }
    main_anonFcn5(G, b_el_tq);
    for (i1 = 0; i1 < 8; i1++) {
      U0x[i1] -= p_u0_workspace_phi * b_el_tq[i1];
    }
    covrtLogFcn(&emlrtCoverageInstance, 0U, 10U);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 10U);
    main_anonFcn5(el_xq, U1);
    main_anonFcn5(G, b_el_tq);
    for (i1 = 0; i1 < 8; i1++) {
      U1[i1] = b_p_u1_workspace_c * U1[i1] - e_a * b_el_tq[i1];
    }
    /*  Integrand evaluation */
    for (b_i = 0; b_i < 8; b_i++) {
      b_el_tq[b_i] = f_a * U0x[b_i];
    }
    for (i1 = 0; i1 < 16; i1++) {
      for (i2 = 0; i2 < 8; i2++) {
        b_i = i2 + (i1 << 3);
        a_tmp = vt_0[b_i];
        b_a_tmp = vx_0[b_i];
        a = U1[i2];
        h_a[b_i] = (g_a * (a * a_tmp + b_el_tq[i2] * b_a_tmp) +
                    el_xq[i2] * (b_a_tmp * a + U0x[i2] * a_tmp)) *
                   wqx[i2];
      }
    }
    b_sum(h_a, local_rhs_Q);
    b_i = F->size[0];
    st.site = &tg_emlrtRSI;
    indexShapeCheck(&st, F->size[0]);
    for (i1 = 0; i1 < 16; i1++) {
      a_tmp = el_dofs[i1];
      if (((int32_T)a_tmp < 1) || ((int32_T)a_tmp > b_i)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)a_tmp, 1, b_i, &ec_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_F[i1] = F_data[(int32_T)a_tmp - 1] + local_rhs_Q[i1];
    }
    for (i1 = 0; i1 < 16; i1++) {
      a_tmp = el_dofs[i1];
      if (a_tmp != (int32_T)muDoubleScalarFloor(a_tmp)) {
        emlrtIntegerCheckR2012b(a_tmp, &xb_emlrtDCI, (emlrtCTX)sp);
      }
      if (((int32_T)a_tmp < 1) || ((int32_T)a_tmp > b_i)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)a_tmp, 1, b_i, &fc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      F_data[(int32_T)a_tmp - 1] = b_F[i1];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_real_T(sp, &xx);
  covrtLogFor(&emlrtCoverageInstance, 11U, 0U, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 4U);
  /*     %% Sigma=a- Element-wise assembly */
  i = mesh_left_elms->size[1];
  if (0 <= mesh_left_elms->size[1] - 1) {
    y = parameters->c * parameters->c;
  }
  for (e = 0; e < i; e++) {
    covrtLogFor(&emlrtCoverageInstance, 11U, 0U, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 5U);
    /*  Get element nodes and DOFs */
    if (e + 1 > mesh_left_elms->size[1]) {
      emlrtDynamicBoundsCheckR2012b(e + 1, 1, mesh_left_elms->size[1],
                                    &jb_emlrtBCI, (emlrtCTX)sp);
    }
    if (mesh_left_elms_data[e] !=
        (int32_T)muDoubleScalarFloor(mesh_left_elms_data[e])) {
      emlrtIntegerCheckR2012b(mesh_left_elms_data[e], &hb_emlrtDCI,
                              (emlrtCTX)sp);
    }
    b_i = (int32_T)mesh_left_elms_data[e];
    if ((b_i < 1) || (b_i > mesh_elms->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, mesh_elms->size[0], &ib_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    d_a[0] = mesh_elms_data[b_i - 1];
    d_a[1] = mesh_elms_data[(b_i + mesh_elms->size[0]) - 1];
    d_a[2] = mesh_elms_data[(b_i + mesh_elms->size[0] * 2) - 1];
    d_a[3] = mesh_elms_data[(b_i + mesh_elms->size[0] * 3) - 1];
    mapper(d_a, disc_nx, disc_nt, el_dofs);
    /*  Move quadrature nodes */
    if (b_i > mesh_pivots->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, mesh_pivots->size[1], &ub_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    a_tmp = mesh_pivots_data[b_i - 1];
    if (a_tmp != (int32_T)muDoubleScalarFloor(a_tmp)) {
      emlrtIntegerCheckR2012b(a_tmp, &sb_emlrtDCI, (emlrtCTX)sp);
    }
    if (((int32_T)a_tmp < 1) || ((int32_T)a_tmp > tt->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)a_tmp, 1, tt->size[0],
                                    &tb_emlrtBCI, (emlrtCTX)sp);
    }
    b_a_tmp = tt_data[(int32_T)a_tmp - 1];
    for (i1 = 0; i1 < 8; i1++) {
      b_el_tq[i1] = ttqh[(i1 << 3) + 7] + b_a_tmp;
    }
    /*  g evaluation */
    covrtLogFcn(&emlrtCoverageInstance, 0U, 8U);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 8U);
    for (b_i = 0; b_i < 8; b_i++) {
      G[b_i] = b_el_tq[b_i] * 0.0;
    }
    /*  Zv boundary evaluation */
    for (i1 = 0; i1 < 16; i1++) {
      for (i2 = 0; i2 < 8; i2++) {
        b_i = i2 + (i1 << 3);
        vt_0[b_i] = (vx_a[b_i] + (b_el_tq[i2] - Tstar) * vt_a[b_i] * beta) *
                    G[i2] * wqt[i2];
      }
    }
    b_sum(vt_0, local_rhs_Q);
    b_i = F->size[0];
    st.site = &xg_emlrtRSI;
    indexShapeCheck(&st, F->size[0]);
    for (i1 = 0; i1 < 16; i1++) {
      a_tmp = el_dofs[i1];
      if (((int32_T)a_tmp < 1) || ((int32_T)a_tmp > b_i)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)a_tmp, 1, b_i, &yb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_F[i1] = F_data[(int32_T)a_tmp - 1] - y * local_rhs_Q[i1];
    }
    for (i1 = 0; i1 < 16; i1++) {
      a_tmp = el_dofs[i1];
      if (a_tmp != (int32_T)muDoubleScalarFloor(a_tmp)) {
        emlrtIntegerCheckR2012b(a_tmp, &vb_emlrtDCI, (emlrtCTX)sp);
      }
      if (((int32_T)a_tmp < 1) || ((int32_T)a_tmp > b_i)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)a_tmp, 1, b_i, &bc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      F_data[(int32_T)a_tmp - 1] = b_F[i1];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 11U, 0U, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 6U);
  /*     %% Sigma=b- Element-wise assembly */
  i = mesh_right_elms->size[1];
  if (0 <= mesh_right_elms->size[1] - 1) {
    b_y = parameters->c * parameters->c;
  }
  for (e = 0; e < i; e++) {
    covrtLogFor(&emlrtCoverageInstance, 11U, 0U, 3, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 7U);
    /*  Get element nodes and DOFs */
    if (e + 1 > mesh_right_elms->size[1]) {
      emlrtDynamicBoundsCheckR2012b(e + 1, 1, mesh_right_elms->size[1],
                                    &hb_emlrtBCI, (emlrtCTX)sp);
    }
    if (mesh_right_elms_data[e] !=
        (int32_T)muDoubleScalarFloor(mesh_right_elms_data[e])) {
      emlrtIntegerCheckR2012b(mesh_right_elms_data[e], &gb_emlrtDCI,
                              (emlrtCTX)sp);
    }
    b_i = (int32_T)mesh_right_elms_data[e];
    if ((b_i < 1) || (b_i > mesh_elms->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, mesh_elms->size[0], &gb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    d_a[0] = mesh_elms_data[b_i - 1];
    d_a[1] = mesh_elms_data[(b_i + mesh_elms->size[0]) - 1];
    d_a[2] = mesh_elms_data[(b_i + mesh_elms->size[0] * 2) - 1];
    d_a[3] = mesh_elms_data[(b_i + mesh_elms->size[0] * 3) - 1];
    mapper(d_a, disc_nx, disc_nt, el_dofs);
    /*  Move quadrature nodes */
    if (b_i > mesh_pivots->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, mesh_pivots->size[1], &wb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    a_tmp = mesh_pivots_data[b_i - 1];
    if (a_tmp != (int32_T)muDoubleScalarFloor(a_tmp)) {
      emlrtIntegerCheckR2012b(a_tmp, &tb_emlrtDCI, (emlrtCTX)sp);
    }
    if (((int32_T)a_tmp < 1) || ((int32_T)a_tmp > tt->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)a_tmp, 1, tt->size[0],
                                    &vb_emlrtBCI, (emlrtCTX)sp);
    }
    b_a_tmp = tt_data[(int32_T)a_tmp - 1];
    for (i1 = 0; i1 < 8; i1++) {
      b_el_tq[i1] = ttqh[(i1 << 3) + 7] + b_a_tmp;
    }
    /*  g evaluation */
    covrtLogFcn(&emlrtCoverageInstance, 0U, 8U);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 8U);
    for (b_i = 0; b_i < 8; b_i++) {
      G[b_i] = b_el_tq[b_i] * 0.0;
    }
    /*  Zv boundary evaluation */
    for (i1 = 0; i1 < 16; i1++) {
      for (i2 = 0; i2 < 8; i2++) {
        b_i = i2 + (i1 << 3);
        vt_0[b_i] = (-vx_b[b_i] + (b_el_tq[i2] - Tstar) * vt_b[b_i] * beta) *
                    G[i2] * wqt[i2];
      }
    }
    b_sum(vt_0, local_rhs_Q);
    b_i = F->size[0];
    st.site = &ch_emlrtRSI;
    indexShapeCheck(&st, F->size[0]);
    for (i1 = 0; i1 < 16; i1++) {
      a_tmp = el_dofs[i1];
      if (((int32_T)a_tmp < 1) || ((int32_T)a_tmp > b_i)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)a_tmp, 1, b_i, &cc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_F[i1] = F_data[(int32_T)a_tmp - 1] - b_y * local_rhs_Q[i1];
    }
    for (i1 = 0; i1 < 16; i1++) {
      a_tmp = el_dofs[i1];
      if (a_tmp != (int32_T)muDoubleScalarFloor(a_tmp)) {
        emlrtIntegerCheckR2012b(a_tmp, &wb_emlrtDCI, (emlrtCTX)sp);
      }
      if (((int32_T)a_tmp < 1) || ((int32_T)a_tmp > b_i)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)a_tmp, 1, b_i, &dc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      F_data[(int32_T)a_tmp - 1] = b_F[i1];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_real_T(sp, &tt);
  covrtLogFor(&emlrtCoverageInstance, 11U, 0U, 3, 0);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (compute_rhs.c) */
