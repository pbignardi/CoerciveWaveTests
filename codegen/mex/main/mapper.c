/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mapper.c
 *
 * Code generation for function 'mapper'
 *
 */

/* Include files */
#include "mapper.h"
#include "main_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void mapper(const real_T el_ids[4], real_T nx, real_T nt, real_T dofs[16])
{
  real_T b_dv[16];
  real_T b_el_ids[16];
  real_T n_nodes;
  int32_T i;
  int8_T i1;
  covrtLogFcn(&emlrtCoverageInstance, 9U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 0U);
  /*  map nodes_ids to degrees of freedom */
  /*  The order is: */
  /*  v(1) v(2) dxv(1) dxv(2) */
  /*  v(3) v(4) dxv(3) dxv(4) */
  /*  dyv(1) dyv(2) dxyv(1) dxvy(2) */
  /*  dyv(3) dyv(4) dxyv(3) dxyv(4) */
  n_nodes = (nx + 1.0) * (nt + 1.0);
  /*  dofs = kron(el_ids, [1,1,1,1]) + n_nodes * kron([1,1,1,1], 0:3); */
  /*  Shuffle the elements to get dofs [v(i), dxv(i), dyv(i), dxyv(i)] */
  b_el_ids[0] = el_ids[0];
  b_el_ids[1] = el_ids[0];
  b_el_ids[2] = el_ids[0];
  b_el_ids[3] = el_ids[0];
  b_el_ids[4] = el_ids[1];
  b_el_ids[5] = el_ids[1];
  b_el_ids[6] = el_ids[1];
  b_el_ids[7] = el_ids[1];
  b_el_ids[8] = el_ids[2];
  b_el_ids[9] = el_ids[2];
  b_el_ids[10] = el_ids[2];
  b_el_ids[11] = el_ids[2];
  b_el_ids[12] = el_ids[3];
  b_el_ids[13] = el_ids[3];
  b_el_ids[14] = el_ids[3];
  b_el_ids[15] = el_ids[3];
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
  for (i = 0; i < 16; i++) {
    i1 = iv[i];
    dofs[i] = b_el_ids[i1] + b_dv[i1];
  }
}

/* End of code generation (mapper.c) */
