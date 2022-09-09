/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CartesianMesh.c
 *
 * Code generation for function 'CartesianMesh'
 *
 */

/* Include files */
#include "CartesianMesh.h"
#include "colon.h"
#include "main_data.h"
#include "main_emxutil.h"
#include "main_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo p_emlrtRSI = {
    12,              /* lineNo */
    "CartesianMesh", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m" /* pathName */
};

static emlrtRSInfo q_emlrtRSI = {
    23,              /* lineNo */
    "CartesianMesh", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m" /* pathName */
};

static emlrtRSInfo r_emlrtRSI = {
    24,              /* lineNo */
    "CartesianMesh", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m" /* pathName */
};

static emlrtRSInfo s_emlrtRSI = {
    28,              /* lineNo */
    "CartesianMesh", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m" /* pathName */
};

static emlrtRSInfo t_emlrtRSI = {
    29,              /* lineNo */
    "CartesianMesh", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m" /* pathName */
};

static emlrtRSInfo u_emlrtRSI = {
    30,              /* lineNo */
    "CartesianMesh", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m" /* pathName */
};

static emlrtECInfo d_emlrtECI = {
    2,               /* nDims */
    11,              /* lineNo */
    18,              /* colNo */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    16,              /* lineNo */
    13,              /* colNo */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m" /* pName */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,              /* iFirst */
    -1,              /* iLast */
    17,              /* lineNo */
    20,              /* colNo */
    "pivots",        /* aName */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtDCInfo u_emlrtDCI = {
    22,              /* lineNo */
    18,              /* colNo */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m", /* pName */
    1                                                 /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,              /* iFirst */
    -1,              /* iLast */
    22,              /* lineNo */
    18,              /* colNo */
    "ids",           /* aName */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,              /* iFirst */
    -1,              /* iLast */
    22,              /* lineNo */
    27,              /* colNo */
    "ids",           /* aName */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,              /* iFirst */
    -1,              /* iLast */
    18,              /* lineNo */
    14,              /* colNo */
    "elms",          /* aName */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtRTEInfo e_emlrtRTEI = {
    13,               /* lineNo */
    13,               /* colNo */
    "toLogicalCheck", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\toLogicalCheck.m" /* pName */
};

static emlrtDCInfo v_emlrtDCI = {
    15,              /* lineNo */
    18,              /* colNo */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m", /* pName */
    1                                                 /* checkKind */
};

static emlrtDCInfo w_emlrtDCI = {
    15,              /* lineNo */
    18,              /* colNo */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m", /* pName */
    4                                                 /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,              /* iFirst */
    -1,              /* iLast */
    11,              /* lineNo */
    18,              /* colNo */
    "ids",           /* aName */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtDCInfo x_emlrtDCI = {
    15,              /* lineNo */
    5,               /* colNo */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m", /* pName */
    1                                                 /* checkKind */
};

static emlrtRTEInfo qc_emlrtRTEI = {
    10,              /* lineNo */
    5,               /* colNo */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m" /* pName */
};

static emlrtRTEInfo rc_emlrtRTEI = {
    12,              /* lineNo */
    9,               /* colNo */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m" /* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = {
    13,              /* lineNo */
    9,               /* colNo */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m" /* pName */
};

static emlrtRTEInfo tc_emlrtRTEI = {
    11,              /* lineNo */
    18,              /* colNo */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m" /* pName */
};

static emlrtRTEInfo uc_emlrtRTEI = {
    1,               /* lineNo */
    17,              /* colNo */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m" /* pName */
};

static emlrtRTEInfo vc_emlrtRTEI = {
    15,              /* lineNo */
    5,               /* colNo */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m" /* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = {
    35,              /* lineNo */
    16,              /* colNo */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m" /* pName */
};

static emlrtRTEInfo xc_emlrtRTEI = {
    36,              /* lineNo */
    16,              /* colNo */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m" /* pName */
};

static emlrtRTEInfo yc_emlrtRTEI = {
    37,              /* lineNo */
    17,              /* colNo */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m" /* pName */
};

static emlrtRTEInfo ad_emlrtRTEI = {
    38,              /* lineNo */
    18,              /* colNo */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m" /* pName */
};

static emlrtRTEInfo bd_emlrtRTEI = {
    39,              /* lineNo */
    21,              /* colNo */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m" /* pName */
};

static emlrtRTEInfo cd_emlrtRTEI = {
    40,              /* lineNo */
    21,              /* colNo */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m" /* pName */
};

static emlrtRTEInfo dd_emlrtRTEI = {
    41,              /* lineNo */
    22,              /* colNo */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m" /* pName */
};

static emlrtRTEInfo ed_emlrtRTEI = {
    42,              /* lineNo */
    23,              /* colNo */
    "CartesianMesh", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m" /* pName */
};

static emlrtRSInfo jn_emlrtRSI = {
    11,              /* lineNo */
    "CartesianMesh", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\CartesianMesh.m" /* pathName */
};

/* Function Declarations */
static void binary_expand_op(const emlrtStack *sp, emxArray_boolean_T *r4,
                             const emxArray_real_T *r5);

/* Function Definitions */
static void binary_expand_op(const emlrtStack *sp, emxArray_boolean_T *r4,
                             const emxArray_real_T *r5)
{
  emxArray_boolean_T *r2;
  const real_T *r;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  boolean_T *r1;
  boolean_T *r3;
  r = r5->data;
  r1 = r4->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_boolean_T(sp, &r2, &tc_emlrtRTEI);
  i = r2->size[0] * r2->size[1];
  r2->size[0] = 1;
  if (r4->size[1] == 1) {
    r2->size[1] = r5->size[1];
  } else {
    r2->size[1] = r4->size[1];
  }
  emxEnsureCapacity_boolean_T(sp, r2, i, &tc_emlrtRTEI);
  r3 = r2->data;
  stride_0_1 = (r5->size[1] != 1);
  stride_1_1 = (r4->size[1] != 1);
  if (r4->size[1] == 1) {
    loop_ub = r5->size[1];
  } else {
    loop_ub = r4->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    r3[i] = ((r[i * stride_0_1] != 0.0) && r1[i * stride_1_1]);
  }
  i = r4->size[0] * r4->size[1];
  r4->size[0] = 1;
  r4->size[1] = r2->size[1];
  emxEnsureCapacity_boolean_T(sp, r4, i, &tc_emlrtRTEI);
  r1 = r4->data;
  loop_ub = r2->size[1];
  for (i = 0; i < loop_ub; i++) {
    r1[i] = r3[i];
  }
  emxFree_boolean_T(sp, &r2);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void CartesianMesh(const emlrtStack *sp, real_T disc_nx, real_T disc_nt,
                   emxArray_real_T *mesh_ids, emxArray_real_T *mesh_pivots,
                   emxArray_real_T *mesh_elms, emxArray_real_T *mesh_bot,
                   emxArray_real_T *mesh_top, emxArray_real_T *mesh_left,
                   emxArray_real_T *mesh_right, emxArray_real_T *mesh_bot_elms,
                   emxArray_real_T *mesh_top_elms,
                   emxArray_real_T *mesh_left_elms,
                   emxArray_real_T *mesh_right_elms)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_boolean_T *r1;
  emxArray_real_T *r;
  real_T n_elms_tmp;
  real_T n_nodes;
  real_T q;
  real_T varargout_1;
  real_T *mesh_elms_data;
  real_T *mesh_ids_data;
  real_T *mesh_pivots_data;
  int32_T b_i;
  int32_T end;
  int32_T i;
  int32_T loop_ub;
  boolean_T rEQ0;
  boolean_T *r2;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  mesh_ids_data = mesh_ids->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 3U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 0U);
  /*  Enumerate the nodes and construct the elements by their indices. */
  /*  Nodes are ordered according to Kronecker product of T and X. */
  /*     %% Unpacking parameters */
  n_nodes = (disc_nx + 1.0) * (disc_nt + 1.0);
  n_elms_tmp = disc_nx * disc_nt;
  /*     %% Enumerate nodes and pivots */
  if (muDoubleScalarIsNaN(n_nodes)) {
    i = mesh_ids->size[0] * mesh_ids->size[1];
    mesh_ids->size[0] = 1;
    mesh_ids->size[1] = 1;
    emxEnsureCapacity_real_T(sp, mesh_ids, i, &qc_emlrtRTEI);
    mesh_ids_data = mesh_ids->data;
    mesh_ids_data[0] = rtNaN;
  } else if (n_nodes < 1.0) {
    mesh_ids->size[0] = 1;
    mesh_ids->size[1] = 0;
  } else if (muDoubleScalarIsInf(n_nodes) && (1.0 == n_nodes)) {
    i = mesh_ids->size[0] * mesh_ids->size[1];
    mesh_ids->size[0] = 1;
    mesh_ids->size[1] = 1;
    emxEnsureCapacity_real_T(sp, mesh_ids, i, &qc_emlrtRTEI);
    mesh_ids_data = mesh_ids->data;
    mesh_ids_data[0] = rtNaN;
  } else {
    i = mesh_ids->size[0] * mesh_ids->size[1];
    mesh_ids->size[0] = 1;
    loop_ub = (int32_T)muDoubleScalarFloor(n_nodes - 1.0);
    mesh_ids->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(sp, mesh_ids, i, &qc_emlrtRTEI);
    mesh_ids_data = mesh_ids->data;
    for (i = 0; i <= loop_ub; i++) {
      mesh_ids_data[i] = (real_T)i + 1.0;
    }
  }
  emxInit_real_T(sp, &r, 2, &uc_emlrtRTEI);
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = mesh_ids->size[1];
  emxEnsureCapacity_real_T(sp, r, i, &rc_emlrtRTEI);
  mesh_pivots_data = r->data;
  loop_ub = mesh_ids->size[1];
  for (i = 0; i < loop_ub; i++) {
    q = mesh_ids_data[i];
    varargout_1 = q;
    if (!(disc_nx + 1.0 == 0.0)) {
      if (muDoubleScalarIsNaN(q) || muDoubleScalarIsNaN(disc_nx + 1.0) ||
          muDoubleScalarIsInf(q)) {
        varargout_1 = rtNaN;
      } else if (muDoubleScalarIsInf(disc_nx + 1.0)) {
        if (disc_nx + 1.0 < 0.0) {
          varargout_1 = disc_nx + 1.0;
        }
      } else {
        varargout_1 = muDoubleScalarRem(q, disc_nx + 1.0);
        rEQ0 = (varargout_1 == 0.0);
        if ((!rEQ0) && (disc_nx + 1.0 > muDoubleScalarFloor(disc_nx + 1.0))) {
          q = muDoubleScalarAbs(q / (disc_nx + 1.0));
          rEQ0 = !(muDoubleScalarAbs(q - muDoubleScalarFloor(q + 0.5)) >
                   2.2204460492503131E-16 * q);
        }
        if (rEQ0) {
          varargout_1 = (disc_nx + 1.0) * 0.0;
        } else if (disc_nx + 1.0 < 0.0) {
          varargout_1 += disc_nx + 1.0;
        }
      }
    }
    mesh_pivots_data[i] = varargout_1;
  }
  emxInit_boolean_T(sp, &r1, &tc_emlrtRTEI);
  i = r1->size[0] * r1->size[1];
  r1->size[0] = 1;
  r1->size[1] = mesh_ids->size[1];
  emxEnsureCapacity_boolean_T(sp, r1, i, &sc_emlrtRTEI);
  r2 = r1->data;
  q = (disc_nx + 1.0) * disc_nt;
  loop_ub = mesh_ids->size[1];
  for (i = 0; i < loop_ub; i++) {
    r2[i] = (mesh_ids_data[i] <= q);
  }
  if ((r->size[1] != r1->size[1]) &&
      ((r->size[1] != 1) && (r1->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(r->size[1], r1->size[1], &d_emlrtECI,
                                (emlrtCTX)sp);
  }
  st.site = &p_emlrtRSI;
  i = r->size[1];
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    if (muDoubleScalarIsNaN(mesh_pivots_data[loop_ub])) {
      emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI, "MATLAB:nologicalnan",
                                    "MATLAB:nologicalnan", 0);
    }
  }
  if (r->size[1] == r1->size[1]) {
    loop_ub = r->size[1] - 1;
    i = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    r1->size[1] = r->size[1];
    emxEnsureCapacity_boolean_T(sp, r1, i, &tc_emlrtRTEI);
    r2 = r1->data;
    for (i = 0; i <= loop_ub; i++) {
      r2[i] = ((mesh_pivots_data[i] != 0.0) && r2[i]);
    }
  } else {
    st.site = &jn_emlrtRSI;
    binary_expand_op(&st, r1, r);
    r2 = r1->data;
  }
  emxFree_real_T(sp, &r);
  end = r1->size[1] - 1;
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if (r2[b_i]) {
      loop_ub++;
    }
  }
  i = mesh_pivots->size[0] * mesh_pivots->size[1];
  mesh_pivots->size[0] = 1;
  mesh_pivots->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, mesh_pivots, i, &uc_emlrtRTEI);
  mesh_pivots_data = mesh_pivots->data;
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if (r2[b_i]) {
      if ((b_i + 1 < 1) || (b_i + 1 > mesh_ids->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, mesh_ids->size[1],
                                      &p_emlrtBCI, (emlrtCTX)sp);
      }
      mesh_pivots_data[loop_ub] = mesh_ids_data[b_i];
      loop_ub++;
    }
  }
  emxFree_boolean_T(sp, &r1);
  /*     %% Build and enumerate elements */
  if (!(n_elms_tmp >= 0.0)) {
    emlrtNonNegativeCheckR2012b(n_elms_tmp, &w_emlrtDCI, (emlrtCTX)sp);
  }
  q = (int32_T)muDoubleScalarFloor(n_elms_tmp);
  if (n_elms_tmp != q) {
    emlrtIntegerCheckR2012b(n_elms_tmp, &v_emlrtDCI, (emlrtCTX)sp);
  }
  i = mesh_elms->size[0] * mesh_elms->size[1];
  b_i = (int32_T)n_elms_tmp;
  mesh_elms->size[0] = (int32_T)n_elms_tmp;
  mesh_elms->size[1] = 4;
  emxEnsureCapacity_real_T(sp, mesh_elms, i, &vc_emlrtRTEI);
  mesh_elms_data = mesh_elms->data;
  if (n_elms_tmp != q) {
    emlrtIntegerCheckR2012b(n_elms_tmp, &x_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub = (int32_T)n_elms_tmp << 2;
  for (i = 0; i < loop_ub; i++) {
    mesh_elms_data[i] = 0.0;
  }
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, n_elms_tmp, mxDOUBLE_CLASS,
                                (int32_T)n_elms_tmp, &d_emlrtRTEI,
                                (emlrtCTX)sp);
  for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
    covrtLogFor(&emlrtCoverageInstance, 3U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 1U);
    if ((loop_ub + 1 < 1) || (loop_ub + 1 > mesh_pivots->size[1])) {
      emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, mesh_pivots->size[1],
                                    &l_emlrtBCI, (emlrtCTX)sp);
    }
    if (((int32_T)(loop_ub + 1U) < 1) ||
        ((int32_T)(loop_ub + 1U) > mesh_elms->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(loop_ub + 1U), 1,
                                    mesh_elms->size[0], &o_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    mesh_elms_data[loop_ub] = mesh_pivots_data[loop_ub];
    mesh_elms_data[loop_ub + mesh_elms->size[0]] =
        mesh_pivots_data[loop_ub] + 1.0;
    q = mesh_pivots_data[loop_ub] + disc_nx;
    mesh_elms_data[loop_ub + mesh_elms->size[0] * 2] = q + 1.0;
    mesh_elms_data[loop_ub + mesh_elms->size[0] * 3] = q + 2.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 3U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 2U);
  /*     %% Boundary definition */
  if (muDoubleScalarIsNaN(disc_nx + 1.0)) {
    i = mesh_bot->size[0] * mesh_bot->size[1];
    mesh_bot->size[0] = 1;
    mesh_bot->size[1] = 1;
    emxEnsureCapacity_real_T(sp, mesh_bot, i, &wc_emlrtRTEI);
    mesh_pivots_data = mesh_bot->data;
    mesh_pivots_data[0] = rtNaN;
  } else if (disc_nx + 1.0 < 1.0) {
    mesh_bot->size[0] = 1;
    mesh_bot->size[1] = 0;
  } else if (muDoubleScalarIsInf(disc_nx + 1.0) && (1.0 == disc_nx + 1.0)) {
    i = mesh_bot->size[0] * mesh_bot->size[1];
    mesh_bot->size[0] = 1;
    mesh_bot->size[1] = 1;
    emxEnsureCapacity_real_T(sp, mesh_bot, i, &wc_emlrtRTEI);
    mesh_pivots_data = mesh_bot->data;
    mesh_pivots_data[0] = rtNaN;
  } else {
    i = mesh_bot->size[0] * mesh_bot->size[1];
    mesh_bot->size[0] = 1;
    loop_ub = (int32_T)muDoubleScalarFloor((disc_nx + 1.0) - 1.0);
    mesh_bot->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(sp, mesh_bot, i, &wc_emlrtRTEI);
    mesh_pivots_data = mesh_bot->data;
    for (i = 0; i <= loop_ub; i++) {
      mesh_pivots_data[i] = (real_T)i + 1.0;
    }
  }
  q = (real_T)mesh_ids->size[1] - disc_nx;
  if (q > mesh_ids->size[1]) {
    i = 0;
    b_i = 0;
  } else {
    if (q != (int32_T)muDoubleScalarFloor(q)) {
      emlrtIntegerCheckR2012b(q, &u_emlrtDCI, (emlrtCTX)sp);
    }
    if (((int32_T)q < 1) || ((int32_T)q > mesh_ids->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)q, 1, mesh_ids->size[1],
                                    &m_emlrtBCI, (emlrtCTX)sp);
    }
    i = (int32_T)q - 1;
    if (mesh_ids->size[1] < 1) {
      emlrtDynamicBoundsCheckR2012b(mesh_ids->size[1], 1, mesh_ids->size[1],
                                    &n_emlrtBCI, (emlrtCTX)sp);
    }
    b_i = mesh_ids->size[1];
  }
  end = mesh_top->size[0] * mesh_top->size[1];
  mesh_top->size[0] = 1;
  loop_ub = b_i - i;
  mesh_top->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, mesh_top, end, &xc_emlrtRTEI);
  mesh_pivots_data = mesh_top->data;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    mesh_pivots_data[b_i] = mesh_ids_data[i + b_i];
  }
  st.site = &q_emlrtRSI;
  if (muDoubleScalarIsNaN(disc_nx + 1.0) || muDoubleScalarIsNaN(n_nodes)) {
    i = mesh_left->size[0] * mesh_left->size[1];
    mesh_left->size[0] = 1;
    mesh_left->size[1] = 1;
    emxEnsureCapacity_real_T(&st, mesh_left, i, &yc_emlrtRTEI);
    mesh_pivots_data = mesh_left->data;
    mesh_pivots_data[0] = rtNaN;
  } else if ((disc_nx + 1.0 == 0.0) ||
             ((1.0 < n_nodes) && (disc_nx + 1.0 < 0.0)) ||
             ((n_nodes < 1.0) && (disc_nx + 1.0 > 0.0))) {
    mesh_left->size[0] = 1;
    mesh_left->size[1] = 0;
  } else if (muDoubleScalarIsInf(n_nodes) &&
             (muDoubleScalarIsInf(disc_nx + 1.0) || (1.0 == n_nodes))) {
    i = mesh_left->size[0] * mesh_left->size[1];
    mesh_left->size[0] = 1;
    mesh_left->size[1] = 1;
    emxEnsureCapacity_real_T(&st, mesh_left, i, &yc_emlrtRTEI);
    mesh_pivots_data = mesh_left->data;
    mesh_pivots_data[0] = rtNaN;
  } else if (muDoubleScalarIsInf(disc_nx + 1.0)) {
    i = mesh_left->size[0] * mesh_left->size[1];
    mesh_left->size[0] = 1;
    mesh_left->size[1] = 1;
    emxEnsureCapacity_real_T(&st, mesh_left, i, &yc_emlrtRTEI);
    mesh_pivots_data = mesh_left->data;
    mesh_pivots_data[0] = 1.0;
  } else if (muDoubleScalarFloor(disc_nx + 1.0) == disc_nx + 1.0) {
    i = mesh_left->size[0] * mesh_left->size[1];
    mesh_left->size[0] = 1;
    loop_ub = (int32_T)muDoubleScalarFloor((n_nodes - 1.0) / (disc_nx + 1.0));
    mesh_left->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(&st, mesh_left, i, &yc_emlrtRTEI);
    mesh_pivots_data = mesh_left->data;
    for (i = 0; i <= loop_ub; i++) {
      mesh_pivots_data[i] = (disc_nx + 1.0) * (real_T)i + 1.0;
    }
  } else {
    b_st.site = &v_emlrtRSI;
    eml_float_colon(&b_st, disc_nx + 1.0, n_nodes, mesh_left);
  }
  st.site = &r_emlrtRSI;
  if (muDoubleScalarIsNaN(disc_nx + 1.0) ||
      muDoubleScalarIsNaN(disc_nx + 1.0) || muDoubleScalarIsNaN(n_nodes)) {
    i = mesh_right->size[0] * mesh_right->size[1];
    mesh_right->size[0] = 1;
    mesh_right->size[1] = 1;
    emxEnsureCapacity_real_T(&st, mesh_right, i, &ad_emlrtRTEI);
    mesh_pivots_data = mesh_right->data;
    mesh_pivots_data[0] = rtNaN;
  } else if ((disc_nx + 1.0 == 0.0) ||
             ((disc_nx + 1.0 < n_nodes) && (disc_nx + 1.0 < 0.0)) ||
             ((n_nodes < disc_nx + 1.0) && (disc_nx + 1.0 > 0.0))) {
    mesh_right->size[0] = 1;
    mesh_right->size[1] = 0;
  } else if ((muDoubleScalarIsInf(disc_nx + 1.0) ||
              muDoubleScalarIsInf(n_nodes)) &&
             (muDoubleScalarIsInf(disc_nx + 1.0) ||
              (disc_nx + 1.0 == n_nodes))) {
    i = mesh_right->size[0] * mesh_right->size[1];
    mesh_right->size[0] = 1;
    mesh_right->size[1] = 1;
    emxEnsureCapacity_real_T(&st, mesh_right, i, &ad_emlrtRTEI);
    mesh_pivots_data = mesh_right->data;
    mesh_pivots_data[0] = rtNaN;
  } else if (muDoubleScalarIsInf(disc_nx + 1.0)) {
    i = mesh_right->size[0] * mesh_right->size[1];
    mesh_right->size[0] = 1;
    mesh_right->size[1] = 1;
    emxEnsureCapacity_real_T(&st, mesh_right, i, &ad_emlrtRTEI);
    mesh_pivots_data = mesh_right->data;
    mesh_pivots_data[0] = disc_nx + 1.0;
  } else {
    q = muDoubleScalarFloor(disc_nx + 1.0);
    if (q == disc_nx + 1.0) {
      i = mesh_right->size[0] * mesh_right->size[1];
      mesh_right->size[0] = 1;
      loop_ub = (int32_T)muDoubleScalarFloor((n_nodes - (disc_nx + 1.0)) /
                                             (disc_nx + 1.0));
      mesh_right->size[1] = loop_ub + 1;
      emxEnsureCapacity_real_T(&st, mesh_right, i, &ad_emlrtRTEI);
      mesh_pivots_data = mesh_right->data;
      for (i = 0; i <= loop_ub; i++) {
        mesh_pivots_data[i] = (disc_nx + 1.0) + (disc_nx + 1.0) * (real_T)i;
      }
    } else {
      b_st.site = &v_emlrtRSI;
      b_eml_float_colon(&b_st, disc_nx + 1.0, disc_nx + 1.0, n_nodes,
                        mesh_right);
    }
  }
  /*     %% Boundary elments */
  if (muDoubleScalarIsNaN(disc_nx)) {
    i = mesh_bot_elms->size[0] * mesh_bot_elms->size[1];
    mesh_bot_elms->size[0] = 1;
    mesh_bot_elms->size[1] = 1;
    emxEnsureCapacity_real_T(sp, mesh_bot_elms, i, &bd_emlrtRTEI);
    mesh_pivots_data = mesh_bot_elms->data;
    mesh_pivots_data[0] = rtNaN;
  } else if (disc_nx < 1.0) {
    mesh_bot_elms->size[0] = 1;
    mesh_bot_elms->size[1] = 0;
  } else if (muDoubleScalarIsInf(disc_nx) && (1.0 == disc_nx)) {
    i = mesh_bot_elms->size[0] * mesh_bot_elms->size[1];
    mesh_bot_elms->size[0] = 1;
    mesh_bot_elms->size[1] = 1;
    emxEnsureCapacity_real_T(sp, mesh_bot_elms, i, &bd_emlrtRTEI);
    mesh_pivots_data = mesh_bot_elms->data;
    mesh_pivots_data[0] = rtNaN;
  } else {
    i = mesh_bot_elms->size[0] * mesh_bot_elms->size[1];
    mesh_bot_elms->size[0] = 1;
    loop_ub = (int32_T)muDoubleScalarFloor(disc_nx - 1.0);
    mesh_bot_elms->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(sp, mesh_bot_elms, i, &bd_emlrtRTEI);
    mesh_pivots_data = mesh_bot_elms->data;
    for (i = 0; i <= loop_ub; i++) {
      mesh_pivots_data[i] = (real_T)i + 1.0;
    }
  }
  st.site = &s_emlrtRSI;
  q = (disc_nx - 1.0) * disc_nt + 1.0;
  b_st.site = &y_emlrtRSI;
  if (muDoubleScalarIsNaN(q)) {
    i = mesh_top_elms->size[0] * mesh_top_elms->size[1];
    mesh_top_elms->size[0] = 1;
    mesh_top_elms->size[1] = 1;
    emxEnsureCapacity_real_T(&b_st, mesh_top_elms, i, &cd_emlrtRTEI);
    mesh_pivots_data = mesh_top_elms->data;
    mesh_pivots_data[0] = rtNaN;
  } else if (n_elms_tmp < q) {
    mesh_top_elms->size[0] = 1;
    mesh_top_elms->size[1] = 0;
  } else if ((muDoubleScalarIsInf(q) || muDoubleScalarIsInf(n_elms_tmp)) &&
             (q == n_elms_tmp)) {
    i = mesh_top_elms->size[0] * mesh_top_elms->size[1];
    mesh_top_elms->size[0] = 1;
    mesh_top_elms->size[1] = 1;
    emxEnsureCapacity_real_T(&b_st, mesh_top_elms, i, &cd_emlrtRTEI);
    mesh_pivots_data = mesh_top_elms->data;
    mesh_pivots_data[0] = rtNaN;
  } else if (muDoubleScalarFloor(q) == q) {
    i = mesh_top_elms->size[0] * mesh_top_elms->size[1];
    mesh_top_elms->size[0] = 1;
    loop_ub = (int32_T)muDoubleScalarFloor(n_elms_tmp - q);
    mesh_top_elms->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(&b_st, mesh_top_elms, i, &cd_emlrtRTEI);
    mesh_pivots_data = mesh_top_elms->data;
    for (i = 0; i <= loop_ub; i++) {
      mesh_pivots_data[i] = q + (real_T)i;
    }
  } else {
    c_st.site = &v_emlrtRSI;
    c_eml_float_colon(&c_st, q, n_elms_tmp, mesh_top_elms);
  }
  st.site = &t_emlrtRSI;
  if (muDoubleScalarIsNaN(disc_nt)) {
    i = mesh_left_elms->size[0] * mesh_left_elms->size[1];
    mesh_left_elms->size[0] = 1;
    mesh_left_elms->size[1] = 1;
    emxEnsureCapacity_real_T(&st, mesh_left_elms, i, &dd_emlrtRTEI);
    mesh_pivots_data = mesh_left_elms->data;
    mesh_pivots_data[0] = rtNaN;
  } else if ((disc_nt == 0.0) || ((1.0 < n_elms_tmp) && (disc_nt < 0.0)) ||
             ((n_elms_tmp < 1.0) && (disc_nt > 0.0))) {
    mesh_left_elms->size[0] = 1;
    mesh_left_elms->size[1] = 0;
  } else if (muDoubleScalarIsInf(n_elms_tmp) &&
             (muDoubleScalarIsInf(disc_nt) || (1.0 == n_elms_tmp))) {
    i = mesh_left_elms->size[0] * mesh_left_elms->size[1];
    mesh_left_elms->size[0] = 1;
    mesh_left_elms->size[1] = 1;
    emxEnsureCapacity_real_T(&st, mesh_left_elms, i, &dd_emlrtRTEI);
    mesh_pivots_data = mesh_left_elms->data;
    mesh_pivots_data[0] = rtNaN;
  } else if (muDoubleScalarIsInf(disc_nt)) {
    i = mesh_left_elms->size[0] * mesh_left_elms->size[1];
    mesh_left_elms->size[0] = 1;
    mesh_left_elms->size[1] = 1;
    emxEnsureCapacity_real_T(&st, mesh_left_elms, i, &dd_emlrtRTEI);
    mesh_pivots_data = mesh_left_elms->data;
    mesh_pivots_data[0] = 1.0;
  } else if (muDoubleScalarFloor(disc_nt) == disc_nt) {
    i = mesh_left_elms->size[0] * mesh_left_elms->size[1];
    mesh_left_elms->size[0] = 1;
    loop_ub = (int32_T)muDoubleScalarFloor((n_elms_tmp - 1.0) / disc_nt);
    mesh_left_elms->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(&st, mesh_left_elms, i, &dd_emlrtRTEI);
    mesh_pivots_data = mesh_left_elms->data;
    for (i = 0; i <= loop_ub; i++) {
      mesh_pivots_data[i] = disc_nt * (real_T)i + 1.0;
    }
  } else {
    b_st.site = &v_emlrtRSI;
    eml_float_colon(&b_st, disc_nt, n_elms_tmp, mesh_left_elms);
  }
  st.site = &u_emlrtRSI;
  if (muDoubleScalarIsNaN(disc_nx) || muDoubleScalarIsNaN(disc_nt)) {
    i = mesh_right_elms->size[0] * mesh_right_elms->size[1];
    mesh_right_elms->size[0] = 1;
    mesh_right_elms->size[1] = 1;
    emxEnsureCapacity_real_T(&st, mesh_right_elms, i, &ed_emlrtRTEI);
    mesh_pivots_data = mesh_right_elms->data;
    mesh_pivots_data[0] = rtNaN;
  } else if ((disc_nt == 0.0) || ((disc_nx < n_elms_tmp) && (disc_nt < 0.0)) ||
             ((n_elms_tmp < disc_nx) && (disc_nt > 0.0))) {
    mesh_right_elms->size[0] = 1;
    mesh_right_elms->size[1] = 0;
  } else if ((muDoubleScalarIsInf(disc_nx) ||
              muDoubleScalarIsInf(n_elms_tmp)) &&
             (muDoubleScalarIsInf(disc_nt) || (disc_nx == n_elms_tmp))) {
    i = mesh_right_elms->size[0] * mesh_right_elms->size[1];
    mesh_right_elms->size[0] = 1;
    mesh_right_elms->size[1] = 1;
    emxEnsureCapacity_real_T(&st, mesh_right_elms, i, &ed_emlrtRTEI);
    mesh_pivots_data = mesh_right_elms->data;
    mesh_pivots_data[0] = rtNaN;
  } else if (muDoubleScalarIsInf(disc_nt)) {
    i = mesh_right_elms->size[0] * mesh_right_elms->size[1];
    mesh_right_elms->size[0] = 1;
    mesh_right_elms->size[1] = 1;
    emxEnsureCapacity_real_T(&st, mesh_right_elms, i, &ed_emlrtRTEI);
    mesh_pivots_data = mesh_right_elms->data;
    mesh_pivots_data[0] = disc_nx;
  } else if ((muDoubleScalarFloor(disc_nx) == disc_nx) &&
             (muDoubleScalarFloor(disc_nt) == disc_nt)) {
    i = mesh_right_elms->size[0] * mesh_right_elms->size[1];
    mesh_right_elms->size[0] = 1;
    loop_ub = (int32_T)muDoubleScalarFloor((n_elms_tmp - disc_nx) / disc_nt);
    mesh_right_elms->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(&st, mesh_right_elms, i, &ed_emlrtRTEI);
    mesh_pivots_data = mesh_right_elms->data;
    for (i = 0; i <= loop_ub; i++) {
      mesh_pivots_data[i] = disc_nx + disc_nt * (real_T)i;
    }
  } else {
    b_st.site = &v_emlrtRSI;
    b_eml_float_colon(&b_st, disc_nx, disc_nt, n_elms_tmp, mesh_right_elms);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (CartesianMesh.c) */
