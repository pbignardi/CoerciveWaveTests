/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * OperatorEval.c
 *
 * Code generation for function 'OperatorEval'
 *
 */

/* Include files */
#include "OperatorEval.h"
#include "colon.h"
#include "indexShapeCheck.h"
#include "main_data.h"
#include "main_emxutil.h"
#include "main_types.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo vl_emlrtRSI = {
    26,             /* lineNo */
    "OperatorEval", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m" /* pathName */
};

static emlrtRSInfo wl_emlrtRSI = {
    29,             /* lineNo */
    "OperatorEval", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m" /* pathName */
};

static emlrtRSInfo xl_emlrtRSI = {
    31,             /* lineNo */
    "OperatorEval", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m" /* pathName */
};

static emlrtRSInfo yl_emlrtRSI = {
    32,             /* lineNo */
    "OperatorEval", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m" /* pathName */
};

static emlrtECInfo u_emlrtECI = {
    -1,             /* nDims */
    33,             /* lineNo */
    13,             /* colNo */
    "OperatorEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m" /* pName */
};

static emlrtBCInfo gc_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    25,             /* lineNo */
    32,             /* colNo */
    "elms",         /* aName */
    "OperatorEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m", /* pName */
    0                                                /* checkKind */
};

static emlrtDCInfo ec_emlrtDCI = {
    25,             /* lineNo */
    32,             /* colNo */
    "OperatorEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m", /* pName */
    1                                                /* checkKind */
};

static emlrtRTEInfo jb_emlrtRTEI = {
    22,             /* lineNo */
    17,             /* colNo */
    "OperatorEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m" /* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = {
    21,             /* lineNo */
    13,             /* colNo */
    "OperatorEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m" /* pName */
};

static emlrtDCInfo fc_emlrtDCI = {
    20,             /* lineNo */
    15,             /* colNo */
    "OperatorEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m", /* pName */
    1                                                /* checkKind */
};

static emlrtDCInfo gc_emlrtDCI = {
    20,             /* lineNo */
    15,             /* colNo */
    "OperatorEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m", /* pName */
    4                                                /* checkKind */
};

static emlrtDCInfo hc_emlrtDCI = {
    20,             /* lineNo */
    24,             /* colNo */
    "OperatorEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m", /* pName */
    1                                                /* checkKind */
};

static emlrtDCInfo ic_emlrtDCI = {
    20,             /* lineNo */
    24,             /* colNo */
    "OperatorEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m", /* pName */
    4                                                /* checkKind */
};

static emlrtDCInfo jc_emlrtDCI = {
    20,             /* lineNo */
    5,              /* colNo */
    "OperatorEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m", /* pName */
    1                                                /* checkKind */
};

static emlrtDCInfo kc_emlrtDCI = {
    29,             /* lineNo */
    33,             /* colNo */
    "OperatorEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m", /* pName */
    1                                                /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    29,             /* lineNo */
    33,             /* colNo */
    "u",            /* aName */
    "OperatorEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m", /* pName */
    0                                                /* checkKind */
};

static emlrtDCInfo lc_emlrtDCI = {
    33,             /* lineNo */
    15,             /* colNo */
    "OperatorEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m", /* pName */
    1                                                /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    33,             /* lineNo */
    15,             /* colNo */
    "U",            /* aName */
    "OperatorEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m", /* pName */
    0                                                /* checkKind */
};

static emlrtDCInfo mc_emlrtDCI = {
    33,             /* lineNo */
    18,             /* colNo */
    "OperatorEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m", /* pName */
    1                                                /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    33,             /* lineNo */
    18,             /* colNo */
    "U",            /* aName */
    "OperatorEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m", /* pName */
    0                                                /* checkKind */
};

static emlrtRTEInfo mg_emlrtRTEI = {
    20,             /* lineNo */
    5,              /* colNo */
    "OperatorEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m" /* pName */
};

static emlrtRTEInfo ng_emlrtRTEI = {
    31,             /* lineNo */
    13,             /* colNo */
    "OperatorEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m" /* pName */
};

static emlrtRTEInfo og_emlrtRTEI = {
    32,             /* lineNo */
    13,             /* colNo */
    "OperatorEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m" /* pName */
};

static emlrtRTEInfo pg_emlrtRTEI = {
    33,             /* lineNo */
    15,             /* colNo */
    "OperatorEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m" /* pName */
};

static emlrtRTEInfo qg_emlrtRTEI = {
    33,             /* lineNo */
    18,             /* colNo */
    "OperatorEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m" /* pName */
};

static emlrtRTEInfo rg_emlrtRTEI = {
    1,              /* lineNo */
    14,             /* colNo */
    "OperatorEval", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\OperatorEval.m" /* pName */
};

/* Function Definitions */
void OperatorEval(const emlrtStack *sp, const emxArray_real_T *u,
                  const emxArray_real_T *mesh_elms, real_T disc_nx,
                  real_T disc_nt, const real_T operator[1024],
                  emxArray_real_T * U)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *J;
  emxArray_real_T *b_I;
  real_T b_el_u[64];
  real_T el_u[64];
  real_T b_dv[16];
  real_T b_mesh_elms[16];
  real_T el_dofs[16];
  const real_T *mesh_elms_data;
  const real_T *u_data;
  real_T a;
  real_T b;
  real_T b_b;
  real_T d;
  real_T d1;
  real_T n_nodes;
  real_T *I_data;
  real_T *J_data;
  real_T *U_data;
  int32_T b_iv[2];
  int32_T iv1[2];
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T b_u;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i4;
  int32_T j;
  int32_T loop_ub;
  int32_T *r2;
  int32_T *r3;
  int8_T i3;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  mesh_elms_data = mesh_elms->data;
  u_data = u->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 16U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 0U);
  /*  Evaluate operator over the gauss quadrature nodes */
  /*  Parameters */
  /*    u       : solution of the linear system */
  /*    mesh    : mesh of the problem */
  /*    disc    : discretization struct */
  /*    operator: matrix of local operator evaluation */
  /*     %% Unpacking structs */
  /*  Mesh parameters */
  /*  Discretisation paramters */
  /*     %% Element-wise assembly */
  n_nodes = 8.0 * disc_nt;
  if (!(n_nodes >= 0.0)) {
    emlrtNonNegativeCheckR2012b(n_nodes, &gc_emlrtDCI, (emlrtCTX)sp);
  }
  b = (int32_T)muDoubleScalarFloor(n_nodes);
  if (n_nodes != b) {
    emlrtIntegerCheckR2012b(n_nodes, &fc_emlrtDCI, (emlrtCTX)sp);
  }
  i = U->size[0] * U->size[1];
  U->size[0] = (int32_T)n_nodes;
  emxEnsureCapacity_real_T(sp, U, i, &mg_emlrtRTEI);
  d = 8.0 * disc_nx;
  if (!(d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d, &ic_emlrtDCI, (emlrtCTX)sp);
  }
  d1 = (int32_T)muDoubleScalarFloor(d);
  if (d != d1) {
    emlrtIntegerCheckR2012b(d, &hc_emlrtDCI, (emlrtCTX)sp);
  }
  i = U->size[0] * U->size[1];
  U->size[1] = (int32_T)d;
  emxEnsureCapacity_real_T(sp, U, i, &mg_emlrtRTEI);
  U_data = U->data;
  if (n_nodes != b) {
    emlrtIntegerCheckR2012b(n_nodes, &jc_emlrtDCI, (emlrtCTX)sp);
  }
  if (d != d1) {
    emlrtIntegerCheckR2012b(d, &jc_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub = (int32_T)n_nodes * (int32_T)d;
  for (i = 0; i < loop_ub; i++) {
    U_data[i] = 0.0;
  }
  i = (int32_T)disc_nx;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, disc_nx, mxDOUBLE_CLASS,
                                (int32_T)disc_nx, &kb_emlrtRTEI, (emlrtCTX)sp);
  emxInit_real_T(sp, &J, 2, &ng_emlrtRTEI);
  J_data = J->data;
  emxInit_real_T(sp, &b_I, 2, &og_emlrtRTEI);
  I_data = b_I->data;
  emxInit_int32_T(sp, &r, 1, &rg_emlrtRTEI);
  emxInit_int32_T(sp, &r1, 1, &rg_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 16U, 0U, 0, 1);
    i1 = (int32_T)disc_nt;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, disc_nt, mxDOUBLE_CLASS,
                                  (int32_T)disc_nt, &jb_emlrtRTEI,
                                  (emlrtCTX)sp);
    if (0 <= (int32_T)disc_nt - 1) {
      n_nodes = (disc_nx + 1.0) * (disc_nt + 1.0);
      b_dv[0] = 0.0;
      b_dv[1] = n_nodes;
      b_dv[2] = 2.0 * n_nodes;
      b_dv[3] = 3.0 * n_nodes;
      b_dv[4] = 0.0;
      b_dv[5] = n_nodes;
      b_dv[6] = 2.0 * n_nodes;
      b_dv[7] = 3.0 * n_nodes;
      b_dv[8] = 0.0;
      b_dv[9] = n_nodes;
      b_dv[10] = 2.0 * n_nodes;
      b_dv[11] = 3.0 * n_nodes;
      b_dv[12] = 0.0;
      b_dv[13] = n_nodes;
      b_dv[14] = 2.0 * n_nodes;
      b_dv[15] = 3.0 * n_nodes;
      b_u = u->size[0];
      a = (((real_T)b_i + 1.0) - 1.0) * 8.0 + 1.0;
      b_b = ((real_T)b_i + 1.0) * 8.0;
      b_iv[0] = 8;
      b_iv[1] = 8;
    }
    for (j = 0; j < i1; j++) {
      covrtLogFor(&emlrtCoverageInstance, 16U, 0U, 1, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 1U);
      /*  Get elms dofs */
      n_nodes = ((real_T)b_i + 1.0) + (((real_T)j + 1.0) - 1.0) * disc_nx;
      if (n_nodes != (int32_T)muDoubleScalarFloor(n_nodes)) {
        emlrtIntegerCheckR2012b(n_nodes, &ec_emlrtDCI, (emlrtCTX)sp);
      }
      if (((int32_T)n_nodes < 1) || ((int32_T)n_nodes > mesh_elms->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)n_nodes, 1, mesh_elms->size[0],
                                      &gc_emlrtBCI, (emlrtCTX)sp);
      }
      st.site = &vl_emlrtRSI;
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
      loop_ub =
          (int32_T)(((real_T)b_i + 1.0) + (((real_T)j + 1.0) - 1.0) * disc_nx) -
          1;
      n_nodes = mesh_elms_data[loop_ub];
      b_mesh_elms[0] = n_nodes;
      b_mesh_elms[1] = n_nodes;
      b_mesh_elms[2] = n_nodes;
      b_mesh_elms[3] = n_nodes;
      n_nodes = mesh_elms_data[loop_ub + mesh_elms->size[0]];
      b_mesh_elms[4] = n_nodes;
      b_mesh_elms[5] = n_nodes;
      b_mesh_elms[6] = n_nodes;
      b_mesh_elms[7] = n_nodes;
      n_nodes = mesh_elms_data[loop_ub + mesh_elms->size[0] * 2];
      b_mesh_elms[8] = n_nodes;
      b_mesh_elms[9] = n_nodes;
      b_mesh_elms[10] = n_nodes;
      b_mesh_elms[11] = n_nodes;
      n_nodes = mesh_elms_data[loop_ub + mesh_elms->size[0] * 3];
      b_mesh_elms[12] = n_nodes;
      b_mesh_elms[13] = n_nodes;
      b_mesh_elms[14] = n_nodes;
      b_mesh_elms[15] = n_nodes;
      for (i2 = 0; i2 < 16; i2++) {
        i3 = iv[i2];
        el_dofs[i2] = b_mesh_elms[i3] + b_dv[i3];
      }
      /*  Evaluate u locally */
      st.site = &wl_emlrtRSI;
      indexShapeCheck(&st, u->size[0]);
      for (i2 = 0; i2 < 16; i2++) {
        n_nodes = el_dofs[i2];
        if (n_nodes != (int32_T)muDoubleScalarFloor(n_nodes)) {
          emlrtIntegerCheckR2012b(n_nodes, &kc_emlrtDCI, (emlrtCTX)sp);
        }
        if (((int32_T)n_nodes < 1) || ((int32_T)n_nodes > b_u)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)n_nodes, 1, b_u, &hc_emlrtBCI,
                                        (emlrtCTX)sp);
        }
      }
      st.site = &wl_emlrtRSI;
      for (i2 = 0; i2 < 16; i2++) {
        b_mesh_elms[i2] = u_data[(int32_T)el_dofs[i2] - 1];
      }
      b_st.site = &hk_emlrtRSI;
      mtimes(operator, b_mesh_elms, el_u);
      /*  Populate evaluation */
      st.site = &xl_emlrtRSI;
      n_nodes = (((real_T)j + 1.0) - 1.0) * 8.0 + 1.0;
      b = ((real_T)j + 1.0) * 8.0;
      b_st.site = &y_emlrtRSI;
      if (b < n_nodes) {
        J->size[0] = 1;
        J->size[1] = 0;
      } else if (n_nodes == n_nodes) {
        i2 = J->size[0] * J->size[1];
        J->size[0] = 1;
        loop_ub = (int32_T)(b - n_nodes);
        J->size[1] = loop_ub + 1;
        emxEnsureCapacity_real_T(&b_st, J, i2, &ng_emlrtRTEI);
        J_data = J->data;
        for (i2 = 0; i2 <= loop_ub; i2++) {
          J_data[i2] = n_nodes + (real_T)i2;
        }
      } else {
        c_st.site = &v_emlrtRSI;
        c_eml_float_colon(&c_st, n_nodes, b, J);
        J_data = J->data;
      }
      st.site = &yl_emlrtRSI;
      b_st.site = &y_emlrtRSI;
      if (b_b < a) {
        b_I->size[0] = 1;
        b_I->size[1] = 0;
      } else if (a == a) {
        i2 = b_I->size[0] * b_I->size[1];
        b_I->size[0] = 1;
        loop_ub = (int32_T)(b_b - a);
        b_I->size[1] = loop_ub + 1;
        emxEnsureCapacity_real_T(&b_st, b_I, i2, &og_emlrtRTEI);
        I_data = b_I->data;
        for (i2 = 0; i2 <= loop_ub; i2++) {
          I_data[i2] = a + (real_T)i2;
        }
      } else {
        c_st.site = &v_emlrtRSI;
        c_eml_float_colon(&c_st, a, b_b, b_I);
        I_data = b_I->data;
      }
      i2 = r->size[0];
      r->size[0] = J->size[1];
      emxEnsureCapacity_int32_T(sp, r, i2, &pg_emlrtRTEI);
      r2 = r->data;
      loop_ub = J->size[1];
      for (i2 = 0; i2 < loop_ub; i2++) {
        if (J_data[i2] != (int32_T)muDoubleScalarFloor(J_data[i2])) {
          emlrtIntegerCheckR2012b(J_data[i2], &lc_emlrtDCI, (emlrtCTX)sp);
        }
        i4 = (int32_T)J_data[i2];
        if ((i4 < 1) || (i4 > U->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)J_data[i2], 1, U->size[0],
                                        &ic_emlrtBCI, (emlrtCTX)sp);
        }
        r2[i2] = i4 - 1;
      }
      i2 = r1->size[0];
      r1->size[0] = b_I->size[1];
      emxEnsureCapacity_int32_T(sp, r1, i2, &qg_emlrtRTEI);
      r3 = r1->data;
      loop_ub = b_I->size[1];
      for (i2 = 0; i2 < loop_ub; i2++) {
        if (I_data[i2] != (int32_T)muDoubleScalarFloor(I_data[i2])) {
          emlrtIntegerCheckR2012b(I_data[i2], &mc_emlrtDCI, (emlrtCTX)sp);
        }
        i4 = (int32_T)I_data[i2];
        if ((i4 < 1) || (i4 > U->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)I_data[i2], 1, U->size[1],
                                        &jc_emlrtBCI, (emlrtCTX)sp);
        }
        r3[i2] = i4 - 1;
      }
      iv1[0] = r->size[0];
      iv1[1] = r1->size[0];
      emlrtSubAssignSizeCheckR2012b(&iv1[0], 2, &b_iv[0], 2, &u_emlrtECI,
                                    (emlrtCTX)sp);
      for (i2 = 0; i2 < 8; i2++) {
        for (i4 = 0; i4 < 8; i4++) {
          b_el_u[i4 + (i2 << 3)] = el_u[i2 + (i4 << 3)];
        }
      }
      iv1[0] = r->size[0];
      loop_ub = r1->size[0];
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_loop_ub = iv1[0];
        for (i4 = 0; i4 < b_loop_ub; i4++) {
          U_data[r2[i4] + U->size[0] * r3[i2]] = b_el_u[i4 + iv1[0] * i2];
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    covrtLogFor(&emlrtCoverageInstance, 16U, 0U, 1, 0);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_int32_T(sp, &r1);
  emxFree_int32_T(sp, &r);
  emxFree_real_T(sp, &b_I);
  emxFree_real_T(sp, &J);
  covrtLogFor(&emlrtCoverageInstance, 16U, 0U, 0, 0);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (OperatorEval.c) */
