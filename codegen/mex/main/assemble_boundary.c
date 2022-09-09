/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * assemble_boundary.c
 *
 * Code generation for function 'assemble_boundary'
 *
 */

/* Include files */
#include "assemble_boundary.h"
#include "main_data.h"
#include "main_emxutil.h"
#include "main_types.h"
#include "rt_nonfinite.h"
#include "sparse.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo hf_emlrtRSI = {
    47,                  /* lineNo */
    "assemble_boundary", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble_boundary.m" /* pathName */
};

static emlrtBCInfo y_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    34,                  /* lineNo */
    25,                  /* colNo */
    "bound_elms",        /* aName */
    "assemble_boundary", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble_boundary.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtDCInfo eb_emlrtDCI = {
    36,                  /* lineNo */
    24,                  /* colNo */
    "assemble_boundary", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble_boundary.m", /* pName */
    1                                                     /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    36,                  /* lineNo */
    24,                  /* colNo */
    "elms",              /* aName */
    "assemble_boundary", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble_boundary.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtDCInfo fb_emlrtDCI = {
    45,                  /* lineNo */
    16,                  /* colNo */
    "assemble_boundary", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble_boundary.m", /* pName */
    1                                                     /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    45,                  /* lineNo */
    16,                  /* colNo */
    "pp",                /* aName */
    "assemble_boundary", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble_boundary.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    41,                  /* lineNo */
    15,                  /* colNo */
    "Ig",                /* aName */
    "assemble_boundary", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble_boundary.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    40,                  /* lineNo */
    15,                  /* colNo */
    "Jg",                /* aName */
    "assemble_boundary", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble_boundary.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    44,                  /* lineNo */
    15,                  /* colNo */
    "Kg",                /* aName */
    "assemble_boundary", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble_boundary.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    45,                  /* lineNo */
    23,                  /* colNo */
    "pivots",            /* aName */
    "assemble_boundary", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble_boundary.m", /* pName */
    0                                                     /* checkKind */
};

static emlrtRTEInfo he_emlrtRTEI = {
    6,                   /* lineNo */
    5,                   /* colNo */
    "assemble_boundary", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble_boundary.m" /* pName */
};

static emlrtRTEInfo ie_emlrtRTEI = {
    29,                  /* lineNo */
    10,                  /* colNo */
    "assemble_boundary", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble_boundary.m" /* pName */
};

static emlrtRTEInfo je_emlrtRTEI = {
    30,                  /* lineNo */
    10,                  /* colNo */
    "assemble_boundary", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble_boundary.m" /* pName */
};

static emlrtRTEInfo ke_emlrtRTEI = {
    31,                  /* lineNo */
    10,                  /* colNo */
    "assemble_boundary", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble_boundary.m" /* pName */
};

static emlrtRTEInfo le_emlrtRTEI = {
    47,                  /* lineNo */
    5,                   /* colNo */
    "assemble_boundary", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble_boundary.m" /* pName */
};

static emlrtRTEInfo me_emlrtRTEI = {
    29,                  /* lineNo */
    5,                   /* colNo */
    "assemble_boundary", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble_boundary.m" /* pName */
};

static emlrtRTEInfo ne_emlrtRTEI = {
    30,                  /* lineNo */
    5,                   /* colNo */
    "assemble_boundary", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble_boundary.m" /* pName */
};

static emlrtRTEInfo oe_emlrtRTEI = {
    31,                  /* lineNo */
    5,                   /* colNo */
    "assemble_boundary", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble_boundary.m" /* pName */
};

static emlrtRTEInfo pe_emlrtRTEI = {
    7,                   /* lineNo */
    5,                   /* colNo */
    "assemble_boundary", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble_boundary.m" /* pName */
};

/* Function Definitions */
void assemble_boundary(const emlrtStack *sp, const real_T Kloc_op[256],
                       const real_T Kloc_opx[256],
                       const real_T Kloc_opxVar[256],
                       const emxArray_real_T *mesh_pivots,
                       const emxArray_real_T *mesh_elms, real_T disc_nx,
                       real_T disc_nt, const emxArray_real_T *disc_xx,
                       const emxArray_real_T *bound_elms, emxArray_real_T *K_d,
                       emxArray_int32_T *K_colidx, emxArray_int32_T *K_rowidx,
                       int32_T *K_m, int32_T *K_n)
{
  b_sparse expl_temp;
  emlrtStack st;
  emxArray_real_T *Ig;
  emxArray_real_T *Jg;
  emxArray_real_T *Kg;
  emxArray_real_T *xx;
  real_T b_dv1[256];
  real_T b_dv[16];
  real_T b_mesh_elms[16];
  real_T el_dofs[16];
  const real_T *bound_elms_data;
  const real_T *disc_xx_data;
  const real_T *mesh_elms_data;
  const real_T *mesh_pivots_data;
  real_T ndofs;
  real_T ndofs_tmp;
  real_T *Ig_data;
  real_T *Jg_data;
  real_T *Kg_data;
  real_T *xx_data;
  int32_T b_i2;
  int32_T e;
  int32_T i;
  int32_T i1;
  int32_T kidx;
  int32_T loop_ub;
  int32_T *K_colidx_data;
  int8_T i2;
  st.prev = sp;
  st.tls = sp->tls;
  bound_elms_data = bound_elms->data;
  disc_xx_data = disc_xx->data;
  mesh_elms_data = mesh_elms->data;
  mesh_pivots_data = mesh_pivots->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &xx, 2, &he_emlrtRTEI);
  covrtLogFcn(&emlrtCoverageInstance, 10U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 0U);
  /*     %% Unpack parameters */
  /*  Discretisation parameters */
  i = xx->size[0] * xx->size[1];
  xx->size[0] = disc_xx->size[1];
  xx->size[1] = disc_xx->size[0];
  emxEnsureCapacity_real_T(sp, xx, i, &he_emlrtRTEI);
  xx_data = xx->data;
  kidx = disc_xx->size[0];
  for (i = 0; i < kidx; i++) {
    loop_ub = disc_xx->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      xx_data[i1 + xx->size[0] * i] = disc_xx_data[i + disc_xx->size[0] * i1];
    }
  }
  emxInit_real_T(sp, &Kg, 2, &me_emlrtRTEI);
  emxInit_real_T(sp, &Ig, 2, &ne_emlrtRTEI);
  emxInit_real_T(sp, &Jg, 2, &oe_emlrtRTEI);
  /*  Mesh parameters */
  /*  Other parameters */
  ndofs_tmp = (disc_nx + 1.0) * (disc_nt + 1.0);
  ndofs = 4.0 * ndofs_tmp;
  /*  Extract Kloc matrices */
  /*  Select the component along which to integrate variable terms */
  covrtLogIf(&emlrtCoverageInstance, 10U, 0U, 0, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 1U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 3U);
  /*     %% Assemble matrix */
  i = Kg->size[0] * Kg->size[1];
  Kg->size[0] = 256;
  Kg->size[1] = bound_elms->size[1];
  emxEnsureCapacity_real_T(sp, Kg, i, &ie_emlrtRTEI);
  Kg_data = Kg->data;
  i = Ig->size[0] * Ig->size[1];
  Ig->size[0] = 256;
  Ig->size[1] = bound_elms->size[1];
  emxEnsureCapacity_real_T(sp, Ig, i, &je_emlrtRTEI);
  Ig_data = Ig->data;
  i = Jg->size[0] * Jg->size[1];
  Jg->size[0] = 256;
  Jg->size[1] = bound_elms->size[1];
  emxEnsureCapacity_real_T(sp, Jg, i, &ke_emlrtRTEI);
  Jg_data = Jg->data;
  i = bound_elms->size[1];
  if (0 <= bound_elms->size[1] - 1) {
    b_dv[0] = 0.0;
    b_dv[1] = ndofs_tmp;
    b_dv[2] = 2.0 * ndofs_tmp;
    b_dv[3] = 3.0 * ndofs_tmp;
    b_dv[4] = 0.0;
    b_dv[5] = ndofs_tmp;
    b_dv[6] = 2.0 * ndofs_tmp;
    b_dv[7] = 3.0 * ndofs_tmp;
    b_dv[8] = 0.0;
    b_dv[9] = ndofs_tmp;
    b_dv[10] = 2.0 * ndofs_tmp;
    b_dv[11] = 3.0 * ndofs_tmp;
    b_dv[12] = 0.0;
    b_dv[13] = ndofs_tmp;
    b_dv[14] = 2.0 * ndofs_tmp;
    b_dv[15] = 3.0 * ndofs_tmp;
  }
  for (e = 0; e < i; e++) {
    covrtLogFor(&emlrtCoverageInstance, 10U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 4U);
    if (e + 1 > bound_elms->size[1]) {
      emlrtDynamicBoundsCheckR2012b(e + 1, 1, bound_elms->size[1], &y_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    /*  Element nodes ids */
    if (bound_elms_data[e] !=
        (int32_T)muDoubleScalarFloor(bound_elms_data[e])) {
      emlrtIntegerCheckR2012b(bound_elms_data[e], &eb_emlrtDCI, (emlrtCTX)sp);
    }
    i1 = (int32_T)bound_elms_data[e];
    if ((i1 < 1) || (i1 > mesh_elms->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, mesh_elms->size[0], &ab_emlrtBCI,
                                    (emlrtCTX)sp);
    }
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
    ndofs_tmp = mesh_elms_data[i1 - 1];
    b_mesh_elms[0] = ndofs_tmp;
    b_mesh_elms[1] = ndofs_tmp;
    b_mesh_elms[2] = ndofs_tmp;
    b_mesh_elms[3] = ndofs_tmp;
    ndofs_tmp = mesh_elms_data[(i1 + mesh_elms->size[0]) - 1];
    b_mesh_elms[4] = ndofs_tmp;
    b_mesh_elms[5] = ndofs_tmp;
    b_mesh_elms[6] = ndofs_tmp;
    b_mesh_elms[7] = ndofs_tmp;
    ndofs_tmp = mesh_elms_data[(i1 + mesh_elms->size[0] * 2) - 1];
    b_mesh_elms[8] = ndofs_tmp;
    b_mesh_elms[9] = ndofs_tmp;
    b_mesh_elms[10] = ndofs_tmp;
    b_mesh_elms[11] = ndofs_tmp;
    ndofs_tmp = mesh_elms_data[(i1 + mesh_elms->size[0] * 3) - 1];
    b_mesh_elms[12] = ndofs_tmp;
    b_mesh_elms[13] = ndofs_tmp;
    b_mesh_elms[14] = ndofs_tmp;
    b_mesh_elms[15] = ndofs_tmp;
    for (loop_ub = 0; loop_ub < 16; loop_ub++) {
      i2 = iv[loop_ub];
      el_dofs[loop_ub] = b_mesh_elms[i2] + b_dv[i2];
    }
    /*  Compute index matrices */
    kidx = -1;
    for (loop_ub = 0; loop_ub < 16; loop_ub++) {
      for (b_i2 = 0; b_i2 < 16; b_i2++) {
        b_dv1[(kidx + b_i2) + 1] = el_dofs[loop_ub];
      }
      kidx += 16;
    }
    if (e + 1 > Jg->size[1]) {
      emlrtDynamicBoundsCheckR2012b(e + 1, 1, Jg->size[1], &db_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    for (loop_ub = 0; loop_ub < 256; loop_ub++) {
      Jg_data[loop_ub + 256 * e] = b_dv1[loop_ub];
    }
    kidx = -1;
    for (loop_ub = 0; loop_ub < 16; loop_ub++) {
      memcpy(&b_dv1[kidx + 1], &el_dofs[0], 16U * sizeof(real_T));
      kidx += 16;
    }
    if (e + 1 > Ig->size[1]) {
      emlrtDynamicBoundsCheckR2012b(e + 1, 1, Ig->size[1], &cb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    for (loop_ub = 0; loop_ub < 256; loop_ub++) {
      Ig_data[loop_ub + 256 * e] = b_dv1[loop_ub];
    }
    /*  Combine Kloc and variable local matrix */
    if (i1 > mesh_pivots->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, mesh_pivots->size[1], &fb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    ndofs_tmp = mesh_pivots_data[i1 - 1];
    if (ndofs_tmp != (int32_T)muDoubleScalarFloor(ndofs_tmp)) {
      emlrtIntegerCheckR2012b(ndofs_tmp, &fb_emlrtDCI, (emlrtCTX)sp);
    }
    loop_ub = xx->size[0] * xx->size[1];
    if (((int32_T)ndofs_tmp < 1) || ((int32_T)ndofs_tmp > loop_ub)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)ndofs_tmp, 1, loop_ub,
                                    &bb_emlrtBCI, (emlrtCTX)sp);
    }
    ndofs_tmp = xx_data[(int32_T)mesh_pivots_data[i1 - 1] - 1];
    if (e + 1 > Kg->size[1]) {
      emlrtDynamicBoundsCheckR2012b(e + 1, 1, Kg->size[1], &eb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < 256; i1++) {
      Kg_data[i1 + 256 * e] =
          (Kloc_op[i1] + Kloc_opx[i1]) + ndofs_tmp * Kloc_opxVar[i1];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_real_T(sp, &xx);
  emxInitStruct_sparse(sp, &expl_temp, &le_emlrtRTEI);
  covrtLogFor(&emlrtCoverageInstance, 10U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 5U);
  st.site = &hf_emlrtRSI;
  sparse(&st, Ig, Jg, Kg, ndofs + 1.0, ndofs, &expl_temp);
  i = K_d->size[0];
  K_d->size[0] = expl_temp.d->size[0];
  emxEnsureCapacity_real_T(sp, K_d, i, &le_emlrtRTEI);
  Kg_data = K_d->data;
  kidx = expl_temp.d->size[0];
  emxFree_real_T(sp, &Jg);
  emxFree_real_T(sp, &Ig);
  emxFree_real_T(sp, &Kg);
  for (i = 0; i < kidx; i++) {
    Kg_data[i] = expl_temp.d->data[i];
  }
  i = K_colidx->size[0];
  K_colidx->size[0] = expl_temp.colidx->size[0];
  emxEnsureCapacity_int32_T(sp, K_colidx, i, &le_emlrtRTEI);
  K_colidx_data = K_colidx->data;
  kidx = expl_temp.colidx->size[0];
  for (i = 0; i < kidx; i++) {
    K_colidx_data[i] = expl_temp.colidx->data[i];
  }
  i = K_rowidx->size[0];
  K_rowidx->size[0] = expl_temp.rowidx->size[0];
  emxEnsureCapacity_int32_T(sp, K_rowidx, i, &le_emlrtRTEI);
  K_colidx_data = K_rowidx->data;
  kidx = expl_temp.rowidx->size[0];
  for (i = 0; i < kidx; i++) {
    K_colidx_data[i] = expl_temp.rowidx->data[i];
  }
  *K_m = expl_temp.m;
  *K_n = expl_temp.n;
  emxFreeStruct_sparse(sp, &expl_temp);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void b_assemble_boundary(const emlrtStack *sp, const real_T Kloc_op[256],
                         const real_T Kloc_opx[256],
                         const real_T Kloc_opxVar[256],
                         const emxArray_real_T *mesh_pivots,
                         const emxArray_real_T *mesh_elms, real_T disc_nx,
                         real_T disc_nt, const emxArray_real_T *disc_tt,
                         const emxArray_real_T *bound_elms,
                         emxArray_real_T *K_d, emxArray_int32_T *K_colidx,
                         emxArray_int32_T *K_rowidx, int32_T *K_m, int32_T *K_n)
{
  b_sparse expl_temp;
  emlrtStack st;
  emxArray_real_T *Ig;
  emxArray_real_T *Jg;
  emxArray_real_T *Kg;
  emxArray_real_T *tt;
  real_T b_dv1[256];
  real_T b_dv[16];
  real_T b_mesh_elms[16];
  real_T el_dofs[16];
  const real_T *bound_elms_data;
  const real_T *disc_tt_data;
  const real_T *mesh_elms_data;
  const real_T *mesh_pivots_data;
  real_T ndofs;
  real_T ndofs_tmp;
  real_T *Ig_data;
  real_T *Jg_data;
  real_T *Kg_data;
  real_T *tt_data;
  int32_T b_i2;
  int32_T e;
  int32_T i;
  int32_T i1;
  int32_T kidx;
  int32_T loop_ub;
  int32_T *K_colidx_data;
  int8_T i2;
  st.prev = sp;
  st.tls = sp->tls;
  bound_elms_data = bound_elms->data;
  disc_tt_data = disc_tt->data;
  mesh_elms_data = mesh_elms->data;
  mesh_pivots_data = mesh_pivots->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &tt, 2, &pe_emlrtRTEI);
  covrtLogFcn(&emlrtCoverageInstance, 10U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 0U);
  /*     %% Unpack parameters */
  /*  Discretisation parameters */
  i = tt->size[0] * tt->size[1];
  tt->size[0] = disc_tt->size[1];
  tt->size[1] = disc_tt->size[0];
  emxEnsureCapacity_real_T(sp, tt, i, &pe_emlrtRTEI);
  tt_data = tt->data;
  kidx = disc_tt->size[0];
  for (i = 0; i < kidx; i++) {
    loop_ub = disc_tt->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      tt_data[i1 + tt->size[0] * i] = disc_tt_data[i + disc_tt->size[0] * i1];
    }
  }
  emxInit_real_T(sp, &Kg, 2, &me_emlrtRTEI);
  emxInit_real_T(sp, &Ig, 2, &ne_emlrtRTEI);
  emxInit_real_T(sp, &Jg, 2, &oe_emlrtRTEI);
  /*  Mesh parameters */
  /*  Other parameters */
  ndofs_tmp = (disc_nx + 1.0) * (disc_nt + 1.0);
  ndofs = 4.0 * ndofs_tmp;
  /*  Extract Kloc matrices */
  /*  Select the component along which to integrate variable terms */
  covrtLogIf(&emlrtCoverageInstance, 10U, 0U, 0, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 2U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 3U);
  /*     %% Assemble matrix */
  i = Kg->size[0] * Kg->size[1];
  Kg->size[0] = 256;
  Kg->size[1] = bound_elms->size[1];
  emxEnsureCapacity_real_T(sp, Kg, i, &ie_emlrtRTEI);
  Kg_data = Kg->data;
  i = Ig->size[0] * Ig->size[1];
  Ig->size[0] = 256;
  Ig->size[1] = bound_elms->size[1];
  emxEnsureCapacity_real_T(sp, Ig, i, &je_emlrtRTEI);
  Ig_data = Ig->data;
  i = Jg->size[0] * Jg->size[1];
  Jg->size[0] = 256;
  Jg->size[1] = bound_elms->size[1];
  emxEnsureCapacity_real_T(sp, Jg, i, &ke_emlrtRTEI);
  Jg_data = Jg->data;
  i = bound_elms->size[1];
  if (0 <= bound_elms->size[1] - 1) {
    b_dv[0] = 0.0;
    b_dv[1] = ndofs_tmp;
    b_dv[2] = 2.0 * ndofs_tmp;
    b_dv[3] = 3.0 * ndofs_tmp;
    b_dv[4] = 0.0;
    b_dv[5] = ndofs_tmp;
    b_dv[6] = 2.0 * ndofs_tmp;
    b_dv[7] = 3.0 * ndofs_tmp;
    b_dv[8] = 0.0;
    b_dv[9] = ndofs_tmp;
    b_dv[10] = 2.0 * ndofs_tmp;
    b_dv[11] = 3.0 * ndofs_tmp;
    b_dv[12] = 0.0;
    b_dv[13] = ndofs_tmp;
    b_dv[14] = 2.0 * ndofs_tmp;
    b_dv[15] = 3.0 * ndofs_tmp;
  }
  for (e = 0; e < i; e++) {
    covrtLogFor(&emlrtCoverageInstance, 10U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 4U);
    if (e + 1 > bound_elms->size[1]) {
      emlrtDynamicBoundsCheckR2012b(e + 1, 1, bound_elms->size[1], &y_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    /*  Element nodes ids */
    if (bound_elms_data[e] !=
        (int32_T)muDoubleScalarFloor(bound_elms_data[e])) {
      emlrtIntegerCheckR2012b(bound_elms_data[e], &eb_emlrtDCI, (emlrtCTX)sp);
    }
    i1 = (int32_T)bound_elms_data[e];
    if ((i1 < 1) || (i1 > mesh_elms->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, mesh_elms->size[0], &ab_emlrtBCI,
                                    (emlrtCTX)sp);
    }
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
    ndofs_tmp = mesh_elms_data[i1 - 1];
    b_mesh_elms[0] = ndofs_tmp;
    b_mesh_elms[1] = ndofs_tmp;
    b_mesh_elms[2] = ndofs_tmp;
    b_mesh_elms[3] = ndofs_tmp;
    ndofs_tmp = mesh_elms_data[(i1 + mesh_elms->size[0]) - 1];
    b_mesh_elms[4] = ndofs_tmp;
    b_mesh_elms[5] = ndofs_tmp;
    b_mesh_elms[6] = ndofs_tmp;
    b_mesh_elms[7] = ndofs_tmp;
    ndofs_tmp = mesh_elms_data[(i1 + mesh_elms->size[0] * 2) - 1];
    b_mesh_elms[8] = ndofs_tmp;
    b_mesh_elms[9] = ndofs_tmp;
    b_mesh_elms[10] = ndofs_tmp;
    b_mesh_elms[11] = ndofs_tmp;
    ndofs_tmp = mesh_elms_data[(i1 + mesh_elms->size[0] * 3) - 1];
    b_mesh_elms[12] = ndofs_tmp;
    b_mesh_elms[13] = ndofs_tmp;
    b_mesh_elms[14] = ndofs_tmp;
    b_mesh_elms[15] = ndofs_tmp;
    for (loop_ub = 0; loop_ub < 16; loop_ub++) {
      i2 = iv[loop_ub];
      el_dofs[loop_ub] = b_mesh_elms[i2] + b_dv[i2];
    }
    /*  Compute index matrices */
    kidx = -1;
    for (loop_ub = 0; loop_ub < 16; loop_ub++) {
      for (b_i2 = 0; b_i2 < 16; b_i2++) {
        b_dv1[(kidx + b_i2) + 1] = el_dofs[loop_ub];
      }
      kidx += 16;
    }
    if (e + 1 > Jg->size[1]) {
      emlrtDynamicBoundsCheckR2012b(e + 1, 1, Jg->size[1], &db_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    for (loop_ub = 0; loop_ub < 256; loop_ub++) {
      Jg_data[loop_ub + 256 * e] = b_dv1[loop_ub];
    }
    kidx = -1;
    for (loop_ub = 0; loop_ub < 16; loop_ub++) {
      memcpy(&b_dv1[kidx + 1], &el_dofs[0], 16U * sizeof(real_T));
      kidx += 16;
    }
    if (e + 1 > Ig->size[1]) {
      emlrtDynamicBoundsCheckR2012b(e + 1, 1, Ig->size[1], &cb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    for (loop_ub = 0; loop_ub < 256; loop_ub++) {
      Ig_data[loop_ub + 256 * e] = b_dv1[loop_ub];
    }
    /*  Combine Kloc and variable local matrix */
    if (i1 > mesh_pivots->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, mesh_pivots->size[1], &fb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    ndofs_tmp = mesh_pivots_data[i1 - 1];
    if (ndofs_tmp != (int32_T)muDoubleScalarFloor(ndofs_tmp)) {
      emlrtIntegerCheckR2012b(ndofs_tmp, &fb_emlrtDCI, (emlrtCTX)sp);
    }
    loop_ub = tt->size[0] * tt->size[1];
    if (((int32_T)ndofs_tmp < 1) || ((int32_T)ndofs_tmp > loop_ub)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)ndofs_tmp, 1, loop_ub,
                                    &bb_emlrtBCI, (emlrtCTX)sp);
    }
    ndofs_tmp = tt_data[(int32_T)mesh_pivots_data[i1 - 1] - 1];
    if (e + 1 > Kg->size[1]) {
      emlrtDynamicBoundsCheckR2012b(e + 1, 1, Kg->size[1], &eb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < 256; i1++) {
      Kg_data[i1 + 256 * e] =
          (Kloc_op[i1] + Kloc_opx[i1]) + ndofs_tmp * Kloc_opxVar[i1];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_real_T(sp, &tt);
  emxInitStruct_sparse(sp, &expl_temp, &le_emlrtRTEI);
  covrtLogFor(&emlrtCoverageInstance, 10U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 5U);
  st.site = &hf_emlrtRSI;
  sparse(&st, Ig, Jg, Kg, ndofs + 1.0, ndofs, &expl_temp);
  i = K_d->size[0];
  K_d->size[0] = expl_temp.d->size[0];
  emxEnsureCapacity_real_T(sp, K_d, i, &le_emlrtRTEI);
  Kg_data = K_d->data;
  kidx = expl_temp.d->size[0];
  emxFree_real_T(sp, &Jg);
  emxFree_real_T(sp, &Ig);
  emxFree_real_T(sp, &Kg);
  for (i = 0; i < kidx; i++) {
    Kg_data[i] = expl_temp.d->data[i];
  }
  i = K_colidx->size[0];
  K_colidx->size[0] = expl_temp.colidx->size[0];
  emxEnsureCapacity_int32_T(sp, K_colidx, i, &le_emlrtRTEI);
  K_colidx_data = K_colidx->data;
  kidx = expl_temp.colidx->size[0];
  for (i = 0; i < kidx; i++) {
    K_colidx_data[i] = expl_temp.colidx->data[i];
  }
  i = K_rowidx->size[0];
  K_rowidx->size[0] = expl_temp.rowidx->size[0];
  emxEnsureCapacity_int32_T(sp, K_rowidx, i, &le_emlrtRTEI);
  K_colidx_data = K_rowidx->data;
  kidx = expl_temp.rowidx->size[0];
  for (i = 0; i < kidx; i++) {
    K_colidx_data[i] = expl_temp.rowidx->data[i];
  }
  *K_m = expl_temp.m;
  *K_n = expl_temp.n;
  emxFreeStruct_sparse(sp, &expl_temp);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (assemble_boundary.c) */
