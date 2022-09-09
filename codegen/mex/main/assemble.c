/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * assemble.c
 *
 * Code generation for function 'assemble'
 *
 */

/* Include files */
#include "assemble.h"
#include "main_data.h"
#include "main_emxutil.h"
#include "main_mexutil.h"
#include "main_types.h"
#include "rt_nonfinite.h"
#include "sparse.h"
#include "tic.h"
#include "toc.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo jd_emlrtRSI = {
    26,         /* lineNo */
    "assemble", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble.m" /* pathName */
};

static emlrtRSInfo kd_emlrtRSI = {
    30,         /* lineNo */
    "assemble", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble.m" /* pathName */
};

static emlrtRSInfo ld_emlrtRSI = {
    42,         /* lineNo */
    "assemble", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble.m" /* pathName */
};

static emlrtRSInfo md_emlrtRSI = {
    43,         /* lineNo */
    "assemble", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble.m" /* pathName */
};

static emlrtRSInfo nd_emlrtRSI = {
    44,         /* lineNo */
    "assemble", /* fcnName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble.m" /* pathName */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    29,         /* lineNo */
    24,         /* colNo */
    "elms",     /* aName */
    "assemble", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble.m", /* pName */
    0                                            /* checkKind */
};

static emlrtDCInfo bb_emlrtDCI = {
    39,         /* lineNo */
    39,         /* colNo */
    "assemble", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble.m", /* pName */
    1                                            /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    39,         /* lineNo */
    39,         /* colNo */
    "xx",       /* aName */
    "assemble", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble.m", /* pName */
    0                                            /* checkKind */
};

static emlrtDCInfo cb_emlrtDCI = {
    40,         /* lineNo */
    39,         /* colNo */
    "assemble", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble.m", /* pName */
    1                                            /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    40,         /* lineNo */
    39,         /* colNo */
    "tt",       /* aName */
    "assemble", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble.m", /* pName */
    0                                            /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    34,         /* lineNo */
    15,         /* colNo */
    "Ig",       /* aName */
    "assemble", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble.m", /* pName */
    0                                            /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    33,         /* lineNo */
    15,         /* colNo */
    "Jg",       /* aName */
    "assemble", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble.m", /* pName */
    0                                            /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    38,         /* lineNo */
    15,         /* colNo */
    "Kg",       /* aName */
    "assemble", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble.m", /* pName */
    0                                            /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    39,         /* lineNo */
    46,         /* colNo */
    "pivots",   /* aName */
    "assemble", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble.m", /* pName */
    0                                            /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    40,         /* lineNo */
    46,         /* colNo */
    "pivots",   /* aName */
    "assemble", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble.m", /* pName */
    0                                            /* checkKind */
};

static emlrtRTEInfo rd_emlrtRTEI = {
    6,          /* lineNo */
    5,          /* colNo */
    "assemble", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble.m" /* pName */
};

static emlrtRTEInfo sd_emlrtRTEI = {
    7,          /* lineNo */
    5,          /* colNo */
    "assemble", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble.m" /* pName */
};

static emlrtRTEInfo td_emlrtRTEI = {
    23,         /* lineNo */
    10,         /* colNo */
    "assemble", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble.m" /* pName */
};

static emlrtRTEInfo ud_emlrtRTEI = {
    24,         /* lineNo */
    10,         /* colNo */
    "assemble", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble.m" /* pName */
};

static emlrtRTEInfo vd_emlrtRTEI = {
    25,         /* lineNo */
    10,         /* colNo */
    "assemble", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble.m" /* pName */
};

static emlrtRTEInfo wd_emlrtRTEI = {
    23,         /* lineNo */
    5,          /* colNo */
    "assemble", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble.m" /* pName */
};

static emlrtRTEInfo xd_emlrtRTEI = {
    24,         /* lineNo */
    5,          /* colNo */
    "assemble", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble.m" /* pName */
};

static emlrtRTEInfo yd_emlrtRTEI = {
    25,         /* lineNo */
    5,          /* colNo */
    "assemble", /* fName */
    "C:\\Users\\paolo\\Documents\\Coercive Wave "
    "Equation\\CoerciveWaves_tests\\assemble.m" /* pName */
};

/* Function Definitions */
void assemble(const emlrtStack *sp, const real_T Kloc_struct_op[256],
              const real_T Kloc_struct_opx[256],
              const real_T Kloc_struct_opt[256],
              const real_T Kloc_struct_opxVar[256],
              const real_T Kloc_struct_optVar[256],
              const emxArray_real_T *mesh_pivots,
              const emxArray_real_T *mesh_elms, real_T disc_nx, real_T disc_nt,
              const emxArray_real_T *disc_xx, const emxArray_real_T *disc_tt,
              b_sparse *K)
{
  static const int32_T b_iv[2] = {1, 7};
  static const int32_T iv1[2] = {1, 45};
  static const char_T b_u[45] = {'G', 'l',  'o', 'b', 'a', 'l', ' ', 'm',  'a',
                                 't', 'r',  'i', 'x', ' ', 'a', 's', 's',  'e',
                                 'm', 'b',  'l', 'y', ' ', 't', 'i', 'm',  'e',
                                 ':', '\\', 't', ' ', '%', '.', '4', 'f',  ' ',
                                 's', 'e',  'c', 'o', 'n', 'd', 's', '\\', 'n'};
  static const char_T u[7] = {'f', 'p', 'r', 'i', 'n', 't', 'f'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_real_T *Ig;
  emxArray_real_T *Jg;
  emxArray_real_T *Kg;
  emxArray_real_T *tt;
  emxArray_real_T *xx;
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  real_T b_dv1[256];
  real_T b_dv[16];
  real_T b_mesh_elms[16];
  real_T el_dofs[16];
  const real_T *disc_tt_data;
  const real_T *disc_xx_data;
  const real_T *mesh_elms_data;
  const real_T *mesh_pivots_data;
  real_T ndofs;
  real_T ndofs_tmp;
  real_T *Ig_data;
  real_T *Jg_data;
  real_T *Kg_data;
  real_T *tt_data;
  real_T *xx_data;
  int32_T e;
  int32_T i;
  int32_T i2;
  int32_T kidx;
  int32_T loop_ub;
  int8_T i1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  disc_tt_data = disc_tt->data;
  disc_xx_data = disc_xx->data;
  mesh_elms_data = mesh_elms->data;
  mesh_pivots_data = mesh_pivots->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &xx, 2, &rd_emlrtRTEI);
  covrtLogFcn(&emlrtCoverageInstance, 8U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 0U);
  /*     %% Unpack parameters */
  /*  Discretisation parameters */
  i = xx->size[0] * xx->size[1];
  xx->size[0] = disc_xx->size[1];
  xx->size[1] = disc_xx->size[0];
  emxEnsureCapacity_real_T(sp, xx, i, &rd_emlrtRTEI);
  xx_data = xx->data;
  kidx = disc_xx->size[0];
  for (i = 0; i < kidx; i++) {
    loop_ub = disc_xx->size[1];
    for (i2 = 0; i2 < loop_ub; i2++) {
      xx_data[i2 + xx->size[0] * i] = disc_xx_data[i + disc_xx->size[0] * i2];
    }
  }
  emxInit_real_T(sp, &tt, 2, &sd_emlrtRTEI);
  i = tt->size[0] * tt->size[1];
  tt->size[0] = disc_tt->size[1];
  tt->size[1] = disc_tt->size[0];
  emxEnsureCapacity_real_T(sp, tt, i, &sd_emlrtRTEI);
  tt_data = tt->data;
  kidx = disc_tt->size[0];
  for (i = 0; i < kidx; i++) {
    loop_ub = disc_tt->size[1];
    for (i2 = 0; i2 < loop_ub; i2++) {
      tt_data[i2 + tt->size[0] * i] = disc_tt_data[i + disc_tt->size[0] * i2];
    }
  }
  emxInit_real_T(sp, &Kg, 2, &wd_emlrtRTEI);
  emxInit_real_T(sp, &Ig, 2, &xd_emlrtRTEI);
  emxInit_real_T(sp, &Jg, 2, &yd_emlrtRTEI);
  /*  Mesh parameters */
  /*  Other parameters */
  ndofs_tmp = (disc_nx + 1.0) * (disc_nt + 1.0);
  ndofs = 4.0 * ndofs_tmp;
  /*  Extract opQ* matrix */
  /*     %% Assemble matrix */
  i = Kg->size[0] * Kg->size[1];
  Kg->size[0] = 256;
  Kg->size[1] = mesh_elms->size[0];
  emxEnsureCapacity_real_T(sp, Kg, i, &td_emlrtRTEI);
  Kg_data = Kg->data;
  i = Ig->size[0] * Ig->size[1];
  Ig->size[0] = 256;
  Ig->size[1] = mesh_elms->size[0];
  emxEnsureCapacity_real_T(sp, Ig, i, &ud_emlrtRTEI);
  Ig_data = Ig->data;
  i = Jg->size[0] * Jg->size[1];
  Jg->size[0] = 256;
  Jg->size[1] = mesh_elms->size[0];
  emxEnsureCapacity_real_T(sp, Jg, i, &vd_emlrtRTEI);
  Jg_data = Jg->data;
  st.site = &jd_emlrtRSI;
  tic(&st);
  i = mesh_elms->size[0];
  if (0 <= mesh_elms->size[0] - 1) {
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
    covrtLogFor(&emlrtCoverageInstance, 8U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 1U);
    /*  Element nodes ids */
    if (e + 1 > mesh_elms->size[0]) {
      emlrtDynamicBoundsCheckR2012b(e + 1, 1, mesh_elms->size[0], &q_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    st.site = &kd_emlrtRSI;
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
    b_mesh_elms[0] = mesh_elms_data[e];
    b_mesh_elms[1] = mesh_elms_data[e];
    b_mesh_elms[2] = mesh_elms_data[e];
    b_mesh_elms[3] = mesh_elms_data[e];
    b_mesh_elms[4] = mesh_elms_data[e + mesh_elms->size[0]];
    b_mesh_elms[5] = mesh_elms_data[e + mesh_elms->size[0]];
    b_mesh_elms[6] = mesh_elms_data[e + mesh_elms->size[0]];
    b_mesh_elms[7] = mesh_elms_data[e + mesh_elms->size[0]];
    b_mesh_elms[8] = mesh_elms_data[e + mesh_elms->size[0] * 2];
    b_mesh_elms[9] = mesh_elms_data[e + mesh_elms->size[0] * 2];
    b_mesh_elms[10] = mesh_elms_data[e + mesh_elms->size[0] * 2];
    b_mesh_elms[11] = mesh_elms_data[e + mesh_elms->size[0] * 2];
    b_mesh_elms[12] = mesh_elms_data[e + mesh_elms->size[0] * 3];
    b_mesh_elms[13] = mesh_elms_data[e + mesh_elms->size[0] * 3];
    b_mesh_elms[14] = mesh_elms_data[e + mesh_elms->size[0] * 3];
    b_mesh_elms[15] = mesh_elms_data[e + mesh_elms->size[0] * 3];
    for (i2 = 0; i2 < 16; i2++) {
      i1 = iv[i2];
      el_dofs[i2] = b_mesh_elms[i1] + b_dv[i1];
    }
    /*  Compute index matrices */
    kidx = -1;
    for (loop_ub = 0; loop_ub < 16; loop_ub++) {
      for (i2 = 0; i2 < 16; i2++) {
        b_dv1[(kidx + i2) + 1] = el_dofs[loop_ub];
      }
      kidx += 16;
    }
    if (e + 1 > Jg->size[1]) {
      emlrtDynamicBoundsCheckR2012b(e + 1, 1, Jg->size[1], &u_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    for (i2 = 0; i2 < 256; i2++) {
      Jg_data[i2 + 256 * e] = b_dv1[i2];
    }
    kidx = -1;
    for (loop_ub = 0; loop_ub < 16; loop_ub++) {
      memcpy(&b_dv1[kidx + 1], &el_dofs[0], 16U * sizeof(real_T));
      kidx += 16;
    }
    if (e + 1 > Ig->size[1]) {
      emlrtDynamicBoundsCheckR2012b(e + 1, 1, Ig->size[1], &t_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    for (i2 = 0; i2 < 256; i2++) {
      Ig_data[i2 + 256 * e] = b_dv1[i2];
    }
    /*  Combine Kloc and variable local matrix */
    /*  So only one assemble call is necessary */
    if (e + 1 > mesh_pivots->size[1]) {
      emlrtDynamicBoundsCheckR2012b(e + 1, 1, mesh_pivots->size[1], &w_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    ndofs_tmp = mesh_pivots_data[e];
    if (ndofs_tmp != (int32_T)muDoubleScalarFloor(ndofs_tmp)) {
      emlrtIntegerCheckR2012b(ndofs_tmp, &bb_emlrtDCI, (emlrtCTX)sp);
    }
    i2 = xx->size[0] * xx->size[1];
    if (((int32_T)ndofs_tmp < 1) || ((int32_T)ndofs_tmp > i2)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)ndofs_tmp, 1, i2, &r_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (e + 1 > mesh_pivots->size[1]) {
      emlrtDynamicBoundsCheckR2012b(e + 1, 1, mesh_pivots->size[1], &x_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    ndofs_tmp = mesh_pivots_data[e];
    if (ndofs_tmp != (int32_T)muDoubleScalarFloor(ndofs_tmp)) {
      emlrtIntegerCheckR2012b(ndofs_tmp, &cb_emlrtDCI, (emlrtCTX)sp);
    }
    i2 = tt->size[0] * tt->size[1];
    if (((int32_T)ndofs_tmp < 1) || ((int32_T)ndofs_tmp > i2)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)ndofs_tmp, 1, i2, &s_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    ndofs_tmp = mesh_pivots_data[e];
    if (e + 1 > Kg->size[1]) {
      emlrtDynamicBoundsCheckR2012b(e + 1, 1, Kg->size[1], &v_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    for (i2 = 0; i2 < 256; i2++) {
      Kg_data[i2 + 256 * e] =
          (((Kloc_struct_op[i2] + Kloc_struct_opx[i2]) +
            Kloc_struct_opxVar[i2] * xx_data[(int32_T)ndofs_tmp - 1]) +
           Kloc_struct_opt[i2]) +
          Kloc_struct_optVar[i2] * tt_data[(int32_T)ndofs_tmp - 1];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_real_T(sp, &tt);
  emxFree_real_T(sp, &xx);
  covrtLogFor(&emlrtCoverageInstance, 8U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 2U);
  st.site = &ld_emlrtRSI;
  sparse(&st, Ig, Jg, Kg, ndofs + 1.0, ndofs, K);
  st.site = &md_emlrtRSI;
  ndofs_tmp = toc(&st);
  st.site = &nd_emlrtRSI;
  b_st.site = &ff_emlrtRSI;
  y = NULL;
  m = emlrtCreateCharArray(2, &b_iv[0]);
  emlrtInitCharArrayR2013a(&b_st, 7, m, &u[0]);
  emlrtAssign(&y, m);
  b_y = NULL;
  m = emlrtCreateCharArray(2, &iv1[0]);
  emlrtInitCharArrayR2013a(&b_st, 45, m, &b_u[0]);
  emlrtAssign(&b_y, m);
  c_st.site = &dn_emlrtRSI;
  emlrt_marshallIn(&c_st,
                   feval(&c_st, y, d_emlrt_marshallOut(1.0), b_y,
                         d_emlrt_marshallOut(ndofs_tmp), &e_emlrtMCI),
                   "<output of feval>");
  emxFree_real_T(sp, &Jg);
  emxFree_real_T(sp, &Ig);
  emxFree_real_T(sp, &Kg);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (assemble.c) */
