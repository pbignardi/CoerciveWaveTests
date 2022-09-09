/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * assemble_boundary.h
 *
 * Code generation for function 'assemble_boundary'
 *
 */

#pragma once

/* Include files */
#include "main_types.h"
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void assemble_boundary(const emlrtStack *sp, const real_T Kloc_op[256],
                       const real_T Kloc_opx[256],
                       const real_T Kloc_opxVar[256],
                       const emxArray_real_T *mesh_pivots,
                       const emxArray_real_T *mesh_elms, real_T disc_nx,
                       real_T disc_nt, const emxArray_real_T *disc_xx,
                       const emxArray_real_T *bound_elms, emxArray_real_T *K_d,
                       emxArray_int32_T *K_colidx, emxArray_int32_T *K_rowidx,
                       int32_T *K_m, int32_T *K_n);

void b_assemble_boundary(
    const emlrtStack *sp, const real_T Kloc_op[256], const real_T Kloc_opx[256],
    const real_T Kloc_opxVar[256], const emxArray_real_T *mesh_pivots,
    const emxArray_real_T *mesh_elms, real_T disc_nx, real_T disc_nt,
    const emxArray_real_T *disc_tt, const emxArray_real_T *bound_elms,
    emxArray_real_T *K_d, emxArray_int32_T *K_colidx,
    emxArray_int32_T *K_rowidx, int32_T *K_m, int32_T *K_n);

/* End of code generation (assemble_boundary.h) */
