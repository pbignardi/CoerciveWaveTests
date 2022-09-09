/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SolverWaves.c
 *
 * Code generation for function 'SolverWaves'
 *
 */

/* Include files */
#include "SolverWaves.h"
#include "HermiteBasis.h"
#include "HermiteEvaluation.h"
#include "assemble.h"
#include "assemble_boundary.h"
#include "compute_rhs.h"
#include "eml_setop.h"
#include "kron.h"
#include "main_data.h"
#include "main_emxutil.h"
#include "main_internal_types.h"
#include "main_mexutil.h"
#include "main_types.h"
#include "rt_nonfinite.h"
#include "sparse1.h"
#include "tic.h"
#include "toc.h"
#include "unique.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo ab_emlrtRSI = {
    34,            /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo bb_emlrtRSI = {
    69,            /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo cb_emlrtRSI = {
    70,            /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo db_emlrtRSI = {
    73,            /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo eb_emlrtRSI = {
    74,            /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo fb_emlrtRSI = {
    75,            /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo gb_emlrtRSI = {
    79,            /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo hb_emlrtRSI = {
    83,            /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo ib_emlrtRSI = {
    85,            /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo jb_emlrtRSI = {
    87,            /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo kb_emlrtRSI = {
    89,            /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo lb_emlrtRSI = {
    93,            /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo mb_emlrtRSI = {
    100,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo nb_emlrtRSI = {
    101,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo ob_emlrtRSI = {
    106,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo pb_emlrtRSI = {
    107,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo qb_emlrtRSI = {
    114,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo rb_emlrtRSI = {
    127,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo sb_emlrtRSI = {
    137,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo tb_emlrtRSI = {
    138,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo ub_emlrtRSI = {
    146,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo vb_emlrtRSI = {
    156,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo wb_emlrtRSI = {
    157,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo xb_emlrtRSI = {
    192,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo yb_emlrtRSI = {
    196,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo ac_emlrtRSI = {
    199,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo bc_emlrtRSI = {
    202,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo cc_emlrtRSI = {
    205,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo dc_emlrtRSI = {
    206,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo ec_emlrtRSI = {
    208,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo fc_emlrtRSI = {
    211,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo gc_emlrtRSI = {
    214,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo hc_emlrtRSI = {
    219,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo ic_emlrtRSI = {
    225,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo jc_emlrtRSI = {
    226,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo kc_emlrtRSI = {
    228,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo lc_emlrtRSI = {
    230,           /* lineNo */
    "SolverWaves", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pathName */
};

static emlrtRSInfo sh_emlrtRSI = {
    44,       /* lineNo */
    "unique", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\unique.m" /* pathName
                                                                       */
};

static emlrtRSInfo hi_emlrtRSI = {
    19,        /* lineNo */
    "setdiff", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\setdiff.m" /* pathName
                                                                        */
};

static emlrtRSInfo ii_emlrtRSI = {
    70,          /* lineNo */
    "eml_setop", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" /* pathName */
};

static emlrtDCInfo y_emlrtDCI = {
    222,           /* lineNo */
    15,            /* colNo */
    "SolverWaves", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m", /* pName */
    1                                               /* checkKind */
};

static emlrtDCInfo ab_emlrtDCI = {
    222,           /* lineNo */
    15,            /* colNo */
    "SolverWaves", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m", /* pName */
    4                                               /* checkKind */
};

static emlrtRTEInfo gd_emlrtRTEI = {
    63,            /* lineNo */
    5,             /* colNo */
    "SolverWaves", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pName */
};

static emlrtRTEInfo hd_emlrtRTEI = {
    206,           /* lineNo */
    9,             /* colNo */
    "SolverWaves", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pName */
};

static emlrtRTEInfo id_emlrtRTEI = {
    211,           /* lineNo */
    27,            /* colNo */
    "SolverWaves", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pName */
};

static emlrtRTEInfo jd_emlrtRTEI = {
    219,           /* lineNo */
    24,            /* colNo */
    "SolverWaves", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pName */
};

static emlrtRTEInfo kd_emlrtRTEI = {
    196,           /* lineNo */
    5,             /* colNo */
    "SolverWaves", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pName */
};

static emlrtRTEInfo ld_emlrtRTEI = {
    199,           /* lineNo */
    5,             /* colNo */
    "SolverWaves", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pName */
};

static emlrtRTEInfo md_emlrtRTEI = {
    202,           /* lineNo */
    5,             /* colNo */
    "SolverWaves", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pName */
};

static emlrtRTEInfo nd_emlrtRTEI = {
    208,           /* lineNo */
    5,             /* colNo */
    "SolverWaves", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pName */
};

static emlrtRTEInfo od_emlrtRTEI = {
    211,           /* lineNo */
    5,             /* colNo */
    "SolverWaves", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pName */
};

static emlrtRTEInfo pd_emlrtRTEI = {
    204,           /* lineNo */
    5,             /* colNo */
    "SolverWaves", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pName */
};

static emlrtRTEInfo qd_emlrtRTEI = {
    192,           /* lineNo */
    5,             /* colNo */
    "SolverWaves", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\SolverWaves.m" /* pName */
};

static emlrtRSInfo en_emlrtRSI = {
    68,        /* lineNo */
    "fprintf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m" /* pathName
                                                                          */
};

/* Function Declarations */
static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[7]);

static const mxArray *e_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[44]);

/* Function Definitions */
static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[7])
{
  static const int32_T b_iv[2] = {1, 7};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateCharArray(2, &b_iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 7, m, &u[0]);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *e_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[44])
{
  static const int32_T b_iv[2] = {1, 44};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateCharArray(2, &b_iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 44, m, &u[0]);
  emlrtAssign(&y, m);
  return y;
}

void SolverWaves(const emlrtStack *sp, real_T problem_c, real_T problem_theta,
                 real_T problem_u0_workspace_phi, real_T problem_u1_workspace_c,
                 real_T problem_u1_workspace_phi, real_T domain_T,
                 const emxArray_real_T *mesh_pivots,
                 const emxArray_real_T *mesh_elms,
                 const emxArray_real_T *mesh_bot,
                 const emxArray_real_T *mesh_bot_elms,
                 const emxArray_real_T *mesh_top_elms,
                 const emxArray_real_T *mesh_left_elms,
                 const emxArray_real_T *mesh_right_elms, const e_struct_T disc,
                 emxArray_real_T *u)
{
  static const char_T cv1[44] = {'L',  'i', 'n', 'e', 'a', 'r', ' ',  's', 'y',
                                 's',  't', 'e', 'm', ' ', 's', 'o',  'l', 'v',
                                 'i',  'n', 'g', ' ', 't', 'i', 'm',  'e', ':',
                                 '\\', 't', ' ', '%', '.', '4', 'f',  ' ', 's',
                                 'e',  'c', 'o', 'n', 'd', 's', '\\', 'n'};
  static const char_T b_cv[7] = {'f', 'p', 'r', 'i', 'n', 't', 'f'};
  b_sparse K;
  b_sparse e_expl_temp;
  b_sparse f_expl_temp;
  b_struct_T g_expl_temp;
  d_struct_T b_expl_temp;
  d_struct_T expl_temp;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_int32_T *KT_colidx;
  emxArray_int32_T *KT_rowidx;
  emxArray_int32_T *Ka_colidx;
  emxArray_int32_T *Ka_rowidx;
  emxArray_int32_T *Kb_colidx;
  emxArray_int32_T *Kb_rowidx;
  emxArray_real_T *F;
  emxArray_real_T *Ka_d;
  emxArray_real_T *Kb_d;
  emxArray_real_T *b_mesh_bot;
  emxArray_real_T *dofs;
  emxArray_real_T *initial_dofs;
  real_T KlocQ_op[256];
  real_T KlocQ_opt[256];
  real_T KlocQ_optVar[256];
  real_T KlocQ_opx[256];
  real_T KlocQ_opxVar[256];
  real_T KlocSa_op[256];
  real_T KlocSa_opx[256];
  real_T KlocSa_opxVar[256];
  real_T KlocSb_opx[256];
  real_T KlocT_op[256];
  real_T KlocT_opx[256];
  real_T KlocT_opxVar[256];
  real_T b_dv[256];
  real_T b_opQ_tmp[256];
  real_T opQ_tmp[256];
  real_T opSa_tmp[256];
  real_T ET_d1d0[16];
  real_T ET_d1d1[16];
  real_T Ea_d0d0[16];
  real_T Ea_d0d1[16];
  real_T Eb_d0d0[16];
  real_T Eb_d0d1[16];
  real_T c_expl_temp[16];
  real_T d_expl_temp[16];
  const real_T *mesh_bot_data;
  real_T Tstar;
  real_T b_tmp;
  real_T beta;
  real_T c_tmp;
  real_T d;
  real_T n_nodes;
  real_T ndofs;
  real_T varargin_1_idx_0_tmp;
  real_T *dofs_data;
  int32_T KT_n;
  int32_T Ka_m;
  int32_T Ka_n;
  int32_T Kb_m;
  int32_T Kb_n;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &b_st;
  d_st.tls = b_st.tls;
  mesh_bot_data = mesh_bot->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 4U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 0U);
  /*     %% Unpacking parameters */
  /*  Problem unpacking */
  /*  Domain unpacking */
  /*  Elements unpacking */
  /*  Boundary unpacking */
  /*  Boundary elms unpacking */
  /*  Formulation unpacking */
  covrtLogIf(&emlrtCoverageInstance, 4U, 0U, 0, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 1U);
  st.site = &ab_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  varargin_1_idx_0_tmp = 2.0 / (problem_c * domain_T);
  beta = varargin_1_idx_0_tmp *
         (0.5 * problem_theta + 1.0 / (0.5 * problem_theta));
  if ((!(varargin_1_idx_0_tmp + 1.0 > beta)) &&
      ((!muDoubleScalarIsNaN(varargin_1_idx_0_tmp + 1.0)) ||
       muDoubleScalarIsNaN(beta))) {
    beta = varargin_1_idx_0_tmp + 1.0;
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 3U);
  Tstar = 2.0 * domain_T;
  /*  - Controllare ordini laplaciano -> OK */
  /*  - provare a perturbare la matrice con termini (modificare anche */
  /*  termine noto) */
  /*  Pack formulation parameters */
  /*  Other parameters */
  n_nodes = (disc.nx + 1.0) * (disc.nt + 1.0);
  ndofs = 4.0 * n_nodes;
  emxInit_real_T(sp, &dofs, 2, &gd_emlrtRTEI);
  if (muDoubleScalarIsNaN(ndofs)) {
    KT_n = dofs->size[0] * dofs->size[1];
    dofs->size[0] = 1;
    dofs->size[1] = 1;
    emxEnsureCapacity_real_T(sp, dofs, KT_n, &gd_emlrtRTEI);
    dofs_data = dofs->data;
    dofs_data[0] = rtNaN;
  } else if (ndofs < 1.0) {
    dofs->size[0] = 1;
    dofs->size[1] = 0;
  } else if (muDoubleScalarIsInf(ndofs) && (1.0 == ndofs)) {
    KT_n = dofs->size[0] * dofs->size[1];
    dofs->size[0] = 1;
    dofs->size[1] = 1;
    emxEnsureCapacity_real_T(sp, dofs, KT_n, &gd_emlrtRTEI);
    dofs_data = dofs->data;
    dofs_data[0] = rtNaN;
  } else {
    KT_n = dofs->size[0] * dofs->size[1];
    dofs->size[0] = 1;
    loop_ub = (int32_T)muDoubleScalarFloor(ndofs - 1.0);
    dofs->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(sp, dofs, KT_n, &gd_emlrtRTEI);
    dofs_data = dofs->data;
    for (KT_n = 0; KT_n <= loop_ub; KT_n++) {
      dofs_data[KT_n] = (real_T)KT_n + 1.0;
    }
  }
  /*     %% Local operator structs */
  st.site = &bb_emlrtRSI;
  HermiteBasis(disc.hx, &expl_temp);
  st.site = &cb_emlrtRSI;
  HermiteBasis(disc.ht, &b_expl_temp);
  /*     %% Local evaluation structs */
  st.site = &db_emlrtRSI;
  HermiteEvaluation(disc.hx, Ea_d0d0, Ea_d0d1, c_expl_temp, d_expl_temp);
  st.site = &eb_emlrtRSI;
  b_HermiteEvaluation(disc.hx, Eb_d0d0, Eb_d0d1, c_expl_temp, d_expl_temp);
  st.site = &fb_emlrtRSI;
  b_HermiteEvaluation(disc.ht, c_expl_temp, d_expl_temp, ET_d1d0, ET_d1d1);
  /*     %% (Fixed) Local operator over Q */
  /*  gradu * gradv * c^2 * (beta - xi) */
  st.site = &gb_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  b_tmp = problem_c * problem_c;
  /*  ut * vt * (beta + xi) */
  /*  Lap u * Lap v */
  st.site = &hb_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  varargin_1_idx_0_tmp = muDoubleScalarPower(problem_c, 4.0);
  st.site = &hb_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  c_tmp = domain_T * domain_T;
  /*  - Lap u * vtt */
  st.site = &ib_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  st.site = &ib_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  /*  - utt * Lap v * c^2 * A / T^2 */
  st.site = &jb_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  st.site = &jb_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  /*  utt * vtt * A / T^2 */
  st.site = &kb_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  /*  -beta * Tstar * ut * vtt */
  b_kron(b_expl_temp.d1d2, expl_temp.d0d0, opQ_tmp);
  /*  c^2 * beta * Tstar * ut * Lap v */
  b_kron(b_expl_temp.d1d0, expl_temp.d0d2, b_opQ_tmp);
  st.site = &lb_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  b_kron(b_expl_temp.d0d0, expl_temp.d1d1, KlocSb_opx);
  b_kron(b_expl_temp.d1d1, expl_temp.d0d0, b_dv);
  b_kron(b_expl_temp.d0d0, expl_temp.d2d2, opSa_tmp);
  b_kron(b_expl_temp.d0d2, expl_temp.d2d0, KlocQ_op);
  b_kron(b_expl_temp.d2d0, expl_temp.d0d2, KlocQ_opx);
  b_kron(b_expl_temp.d2d2, expl_temp.d0d0, KlocQ_opxVar);
  for (KT_n = 0; KT_n < 256; KT_n++) {
    KlocQ_op[KT_n] = ((((((KlocSb_opx[KT_n] * b_tmp * (beta + 1.0) +
                           b_dv[KT_n] * (beta + 1.0)) +
                          opSa_tmp[KT_n] * varargin_1_idx_0_tmp / c_tmp) -
                         KlocQ_op[KT_n] * b_tmp / c_tmp) -
                        KlocQ_opx[KT_n] * b_tmp / c_tmp) +
                       KlocQ_opxVar[KT_n] / c_tmp) -
                      opQ_tmp[KT_n] * beta * Tstar) +
                     b_opQ_tmp[KT_n] * b_tmp * beta * Tstar;
  }
  /*     %% (Variable) Local operator over Q */
  /*  - xi * x * grad u * vtt */
  /*  c^2 * xi * x * grad u * Lap v */
  st.site = &mb_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  b_kron(b_expl_temp.d0d2, expl_temp.d1d0x, KlocSb_opx);
  b_kron(b_expl_temp.d0d0, expl_temp.d1d2x, b_dv);
  for (KT_n = 0; KT_n < 256; KT_n++) {
    KlocQ_opx[KT_n] = -KlocSb_opx[KT_n] + b_dv[KT_n] * b_tmp;
  }
  st.site = &nb_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  b_kron(b_expl_temp.d0d2, expl_temp.d1d0, KlocSb_opx);
  b_kron(b_expl_temp.d0d0, expl_temp.d1d2, b_dv);
  for (KT_n = 0; KT_n < 256; KT_n++) {
    KlocQ_opxVar[KT_n] = -KlocSb_opx[KT_n] + b_dv[KT_n] * b_tmp;
  }
  /*  beta * t * ut * vtt */
  /*  - beta * c^2 * t * ut * Lap v */
  st.site = &ob_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  b_kron(b_expl_temp.d1d2x, expl_temp.d0d0, KlocSb_opx);
  b_kron(b_expl_temp.d1d0x, expl_temp.d0d2, b_dv);
  for (KT_n = 0; KT_n < 256; KT_n++) {
    KlocQ_opt[KT_n] = KlocSb_opx[KT_n] * beta - b_dv[KT_n] * beta * b_tmp;
  }
  st.site = &pb_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  for (KT_n = 0; KT_n < 256; KT_n++) {
    KlocQ_optVar[KT_n] = opQ_tmp[KT_n] * beta - b_opQ_tmp[KT_n] * beta * b_tmp;
  }
  /*     %% (Fixed) Local operator over Omega_T */
  /*  beta (Tstar - T ) * vt * ut */
  varargin_1_idx_0_tmp = Tstar - domain_T;
  /*  beta (Tstar - T ) * grad u * grad v */
  st.site = &qb_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  b_kron(ET_d1d1, expl_temp.d0d0, KlocSb_opx);
  b_kron(c_expl_temp, expl_temp.d1d1, b_dv);
  for (KT_n = 0; KT_n < 256; KT_n++) {
    KlocT_op[KT_n] = KlocSb_opx[KT_n] * beta * varargin_1_idx_0_tmp +
                     b_dv[KT_n] * beta * varargin_1_idx_0_tmp * b_tmp;
  }
  /*     %% (Variable) Local operator over Omega_T */
  /*  xi * x * grad v * ut */
  /*  xi * x * grad u * vt  */
  b_kron(ET_d1d0, expl_temp.d0d1x, KlocSb_opx);
  b_kron(d_expl_temp, expl_temp.d1d0x, b_dv);
  for (KT_n = 0; KT_n < 256; KT_n++) {
    KlocT_opx[KT_n] = KlocSb_opx[KT_n] + b_dv[KT_n];
  }
  b_kron(ET_d1d0, expl_temp.d0d1, KlocSb_opx);
  b_kron(d_expl_temp, expl_temp.d1d0, b_dv);
  for (KT_n = 0; KT_n < 256; KT_n++) {
    KlocT_opxVar[KT_n] = KlocSb_opx[KT_n] + b_dv[KT_n];
  }
  /*     %% (Fixed) Local operator over Sigma=a */
  /*  - c^2 * beta * Tstar * ut * vx * n */
  b_kron(b_expl_temp.d1d0, Ea_d0d1, b_opQ_tmp);
  st.site = &rb_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  /*  c/theta * xi * a * vx * ut */
  /*  c/theta * beta * Tstar * ut * vt */
  b_kron(b_expl_temp.d1d1, Ea_d0d0, opQ_tmp);
  /*  - xi * a * n * ut * vt  */
  for (KT_n = 0; KT_n < 256; KT_n++) {
    varargin_1_idx_0_tmp = opQ_tmp[KT_n];
    c_tmp = varargin_1_idx_0_tmp * problem_c / problem_theta;
    opSa_tmp[KT_n] = c_tmp;
    d = b_opQ_tmp[KT_n];
    KlocSa_op[KT_n] =
        ((-(-d * b_tmp * beta * Tstar) + -(d * problem_c / problem_theta)) +
         c_tmp * beta * Tstar) -
        varargin_1_idx_0_tmp;
  }
  /*     %% (Variable) Local operator over Sigma=a */
  /*  c^2 * beta * t * ut * vx * n */
  st.site = &sb_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  st.site = &tb_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  /*  - c/theta * beta * t * ut * vt */
  b_kron(b_expl_temp.d1d0x, Ea_d0d1, KlocSb_opx);
  b_kron(b_expl_temp.d1d1x, Ea_d0d0, b_dv);
  for (KT_n = 0; KT_n < 256; KT_n++) {
    KlocSa_opx[KT_n] = -(KlocSb_opx[KT_n] * b_tmp * beta) -
                       b_dv[KT_n] * problem_c / problem_theta * beta;
    KlocSa_opxVar[KT_n] =
        -(b_opQ_tmp[KT_n] * b_tmp * beta) - opSa_tmp[KT_n] * beta;
  }
  /*     %% (Fixed) Local operator over Sigma=b */
  /*  - c^2 * beta * Tstar * ut * vx * n */
  b_kron(b_expl_temp.d1d0, Eb_d0d1, b_opQ_tmp);
  st.site = &ub_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  /*  c/theta * xi * x * vx * ut */
  /*  c/theta * beta * Tstar * ut * vt */
  b_kron(b_expl_temp.d1d1, Eb_d0d0, opQ_tmp);
  /*  - xi * x * n * ut * vt  */
  for (KT_n = 0; KT_n < 256; KT_n++) {
    varargin_1_idx_0_tmp = opQ_tmp[KT_n];
    c_tmp = varargin_1_idx_0_tmp * problem_c / problem_theta;
    opSa_tmp[KT_n] = c_tmp;
    d = b_opQ_tmp[KT_n];
    varargin_1_idx_0_tmp =
        ((-d * b_tmp * beta * Tstar + d * problem_c / problem_theta) +
         c_tmp * beta * Tstar) -
        varargin_1_idx_0_tmp;
    opQ_tmp[KT_n] = varargin_1_idx_0_tmp;
  }
  /*     %% (Variable) Local operator over Sigma=b */
  /*  c^2 * beta * t * ut * vx * n */
  st.site = &vb_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  st.site = &wb_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  /*  - c/theta * beta * t * ut * vt */
  b_kron(b_expl_temp.d1d0x, Eb_d0d1, KlocSb_opx);
  b_kron(b_expl_temp.d1d1x, Eb_d0d0, b_dv);
  for (KT_n = 0; KT_n < 256; KT_n++) {
    KlocSb_opx[KT_n] = KlocSb_opx[KT_n] * b_tmp * beta -
                       b_dv[KT_n] * problem_c / problem_theta * beta;
    b_opQ_tmp[KT_n] = b_opQ_tmp[KT_n] * b_tmp * beta - opSa_tmp[KT_n] * beta;
  }
  emxInit_int32_T(sp, &KT_colidx, 1, &kd_emlrtRTEI);
  emxInit_int32_T(sp, &KT_rowidx, 1, &kd_emlrtRTEI);
  emxInit_real_T(sp, &Ka_d, 1, &ld_emlrtRTEI);
  emxInit_int32_T(sp, &Ka_colidx, 1, &ld_emlrtRTEI);
  emxInit_int32_T(sp, &Ka_rowidx, 1, &ld_emlrtRTEI);
  emxInit_real_T(sp, &Kb_d, 1, &md_emlrtRTEI);
  emxInit_int32_T(sp, &Kb_colidx, 1, &md_emlrtRTEI);
  emxInit_int32_T(sp, &Kb_rowidx, 1, &md_emlrtRTEI);
  emxInit_real_T(sp, &F, 1, &nd_emlrtRTEI);
  emxInitStruct_sparse(sp, &K, &pd_emlrtRTEI);
  emxInitStruct_sparse(sp, &e_expl_temp, &qd_emlrtRTEI);
  emxInitStruct_sparse(sp, &f_expl_temp, &hd_emlrtRTEI);
  /*  --- Formulation above is correct --- */
  /*     %% Pack-up local matrix */
  /*  Q domain */
  /*  OmegaT domain */
  /*  Sigma=a domain */
  /*  Sigma=b domain */
  /*     %% Internal matrix assembly */
  /*  Poisson testing */
  st.site = &xb_emlrtRSI;
  assemble(&st, KlocQ_op, KlocQ_opx, KlocQ_opt, KlocQ_opxVar, KlocQ_optVar,
           mesh_pivots, mesh_elms, disc.nx, disc.nt, disc.xx, disc.tt,
           &e_expl_temp);
  /*     %% Boundary matrix assembly */
  /*  Omega T boundary */
  st.site = &yb_emlrtRSI;
  assemble_boundary(&st, KlocT_op, KlocT_opx, KlocT_opxVar, mesh_pivots,
                    mesh_elms, disc.nx, disc.nt, disc.xx, mesh_top_elms, F,
                    KT_colidx, KT_rowidx, &loop_ub, &KT_n);
  /*  Sigma=a boundary */
  st.site = &ac_emlrtRSI;
  b_assemble_boundary(&st, KlocSa_op, KlocSa_opx, KlocSa_opxVar, mesh_pivots,
                      mesh_elms, disc.nx, disc.nt, disc.tt, mesh_left_elms,
                      Ka_d, Ka_colidx, Ka_rowidx, &Ka_m, &Ka_n);
  /*  Sigma=b boundary */
  st.site = &bc_emlrtRSI;
  b_assemble_boundary(&st, opQ_tmp, KlocSb_opx, b_opQ_tmp, mesh_pivots,
                      mesh_elms, disc.nx, disc.nt, disc.tt, mesh_right_elms,
                      Kb_d, Kb_colidx, Kb_rowidx, &Kb_m, &Kb_n);
  /*     %% Global matrix computation */
  st.site = &cc_emlrtRSI;
  sparse_plus(&st, e_expl_temp.d, e_expl_temp.colidx, e_expl_temp.rowidx,
              e_expl_temp.m, e_expl_temp.n, F, KT_colidx, KT_rowidx, loop_ub,
              KT_n, &K);
  st.site = &dc_emlrtRSI;
  sparse_plus(&st, K.d, K.colidx, K.rowidx, K.m, K.n, Ka_d, Ka_colidx,
              Ka_rowidx, Ka_m, Ka_n, &f_expl_temp);
  KT_n = e_expl_temp.d->size[0];
  e_expl_temp.d->size[0] = f_expl_temp.d->size[0];
  emxEnsureCapacity_real_T(sp, e_expl_temp.d, KT_n, &hd_emlrtRTEI);
  loop_ub = f_expl_temp.d->size[0];
  emxFree_int32_T(sp, &Ka_rowidx);
  emxFree_int32_T(sp, &Ka_colidx);
  emxFree_real_T(sp, &Ka_d);
  emxFree_int32_T(sp, &KT_rowidx);
  for (KT_n = 0; KT_n < loop_ub; KT_n++) {
    e_expl_temp.d->data[KT_n] = f_expl_temp.d->data[KT_n];
  }
  KT_n = e_expl_temp.colidx->size[0];
  e_expl_temp.colidx->size[0] = f_expl_temp.colidx->size[0];
  emxEnsureCapacity_int32_T(sp, e_expl_temp.colidx, KT_n, &hd_emlrtRTEI);
  loop_ub = f_expl_temp.colidx->size[0];
  for (KT_n = 0; KT_n < loop_ub; KT_n++) {
    e_expl_temp.colidx->data[KT_n] = f_expl_temp.colidx->data[KT_n];
  }
  KT_n = e_expl_temp.rowidx->size[0];
  e_expl_temp.rowidx->size[0] = f_expl_temp.rowidx->size[0];
  emxEnsureCapacity_int32_T(sp, e_expl_temp.rowidx, KT_n, &hd_emlrtRTEI);
  loop_ub = f_expl_temp.rowidx->size[0];
  for (KT_n = 0; KT_n < loop_ub; KT_n++) {
    e_expl_temp.rowidx->data[KT_n] = f_expl_temp.rowidx->data[KT_n];
  }
  emxInit_real_T(sp, &b_mesh_bot, 2, &id_emlrtRTEI);
  st.site = &dc_emlrtRSI;
  sparse_plus(&st, e_expl_temp.d, e_expl_temp.colidx, e_expl_temp.rowidx,
              f_expl_temp.m, f_expl_temp.n, Kb_d, Kb_colidx, Kb_rowidx, Kb_m,
              Kb_n, &K);
  /*     %% Load vector assembly */
  g_expl_temp.b = 1.0;
  g_expl_temp.a = -1.0;
  g_expl_temp.T = domain_T;
  g_expl_temp.c = problem_c;
  g_expl_temp.xi = 1.0;
  g_expl_temp.nu = 2.0;
  g_expl_temp.Tstar = Tstar;
  g_expl_temp.beta = beta;
  g_expl_temp.A = 1.0;
  st.site = &ec_emlrtRSI;
  compute_rhs(&st, problem_u0_workspace_phi, problem_u1_workspace_c,
              problem_u1_workspace_phi, mesh_pivots, mesh_elms, mesh_bot_elms,
              mesh_left_elms, mesh_right_elms, disc.nx, disc.nt, disc.hx,
              disc.ht, disc.x, disc.t, &g_expl_temp, F);
  /*     %% Imposing boundary conditions */
  st.site = &fc_emlrtRSI;
  varargin_1_idx_0_tmp = 2.0 * n_nodes;
  c_tmp = 3.0 * n_nodes;
  KT_n = b_mesh_bot->size[0] * b_mesh_bot->size[1];
  b_mesh_bot->size[0] = 1;
  b_mesh_bot->size[1] =
      ((mesh_bot->size[1] + mesh_bot->size[1]) + mesh_bot->size[1]) +
      mesh_bot->size[1];
  emxEnsureCapacity_real_T(&st, b_mesh_bot, KT_n, &id_emlrtRTEI);
  dofs_data = b_mesh_bot->data;
  loop_ub = mesh_bot->size[1];
  emxFreeStruct_sparse(&st, &f_expl_temp);
  emxFreeStruct_sparse(&st, &e_expl_temp);
  emxFree_int32_T(&st, &Kb_rowidx);
  emxFree_int32_T(&st, &Kb_colidx);
  emxFree_real_T(&st, &Kb_d);
  for (KT_n = 0; KT_n < loop_ub; KT_n++) {
    dofs_data[KT_n] = mesh_bot_data[KT_n];
  }
  loop_ub = mesh_bot->size[1];
  for (KT_n = 0; KT_n < loop_ub; KT_n++) {
    dofs_data[KT_n + mesh_bot->size[1]] = n_nodes + mesh_bot_data[KT_n];
  }
  loop_ub = mesh_bot->size[1];
  for (KT_n = 0; KT_n < loop_ub; KT_n++) {
    dofs_data[(KT_n + mesh_bot->size[1]) + mesh_bot->size[1]] =
        varargin_1_idx_0_tmp + mesh_bot_data[KT_n];
  }
  loop_ub = mesh_bot->size[1];
  for (KT_n = 0; KT_n < loop_ub; KT_n++) {
    dofs_data[((KT_n + mesh_bot->size[1]) + mesh_bot->size[1]) +
              mesh_bot->size[1]] = c_tmp + mesh_bot_data[KT_n];
  }
  emxInit_real_T(&st, &initial_dofs, 2, &od_emlrtRTEI);
  b_st.site = &sh_emlrtRSI;
  unique_vector(&b_st, b_mesh_bot, initial_dofs);
  /*  Internal DOFs. Remove initial condition dofs */
  st.site = &gc_emlrtRSI;
  b_st.site = &hi_emlrtRSI;
  c_st.site = &ii_emlrtRSI;
  do_vectors(&c_st, dofs, initial_dofs, b_mesh_bot, KT_colidx, &loop_ub);
  /*     %% Imposive null mean initial condition */
  /*  Problema: il sistema lineare non è più quadrato... È un problema? */
  /*  Proposta: Risolvere il problema senza il vincolo della media nulla, */
  /*  calcolare la media e aggiungerla alla soluzione? */
  KT_n = b_mesh_bot->size[0] * b_mesh_bot->size[1];
  b_mesh_bot->size[0] = 1;
  b_mesh_bot->size[1] = mesh_bot->size[1];
  emxEnsureCapacity_real_T(sp, b_mesh_bot, KT_n, &jd_emlrtRTEI);
  dofs_data = b_mesh_bot->data;
  loop_ub = mesh_bot->size[1];
  emxFree_real_T(sp, &initial_dofs);
  emxFree_int32_T(sp, &KT_colidx);
  emxFree_real_T(sp, &dofs);
  for (KT_n = 0; KT_n < loop_ub; KT_n++) {
    dofs_data[KT_n] = disc.hx;
  }
  st.site = &hc_emlrtRSI;
  sparse_parenAssign(&st, &K, b_mesh_bot, K.m, mesh_bot);
  /*     %% Solving */
  emxFree_real_T(sp, &b_mesh_bot);
  if (!(ndofs + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(ndofs + 1.0, &ab_emlrtDCI, (emlrtCTX)sp);
  }
  if (ndofs + 1.0 != (int32_T)muDoubleScalarFloor(ndofs + 1.0)) {
    emlrtIntegerCheckR2012b(ndofs + 1.0, &y_emlrtDCI, (emlrtCTX)sp);
  }
  /*  Start timer */
  st.site = &ic_emlrtRSI;
  tic(&st);
  st.site = &jc_emlrtRSI;
  sparse_mldivide(&st, K.d, K.colidx, K.rowidx, K.m, K.n, F, u);
  st.site = &kc_emlrtRSI;
  varargin_1_idx_0_tmp = toc(&st);
  /*  Log time result */
  st.site = &lc_emlrtRSI;
  b_st.site = &ff_emlrtRSI;
  c_st.site = &dn_emlrtRSI;
  d_st.site = &en_emlrtRSI;
  emlrt_marshallIn(
      &c_st,
      feval(&c_st, c_emlrt_marshallOut(&c_st, b_cv), d_emlrt_marshallOut(1.0),
            e_emlrt_marshallOut(&d_st, cv1),
            d_emlrt_marshallOut(varargin_1_idx_0_tmp), &e_emlrtMCI),
      "<output of feval>");
  /*     %% Post-processing solution */
  /*  Compute condest of matrix K :TODO */
  /* Kcond = condest(K(internal,internal)); */
  /* Kcond = condest(K); */
  /*     %% Internal stiffness conditioning */
  /* fprintf("Condition number is: %e \n", condest(K(internal, internal))) */
  emxFreeStruct_sparse(sp, &K);
  emxFree_real_T(sp, &F);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (SolverWaves.c) */
