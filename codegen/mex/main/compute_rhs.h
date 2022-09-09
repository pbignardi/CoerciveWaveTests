/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * compute_rhs.h
 *
 * Code generation for function 'compute_rhs'
 *
 */

#pragma once

/* Include files */
#include "main_internal_types.h"
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
void compute_rhs(const emlrtStack *sp, real_T p_u0_workspace_phi,
                 real_T p_u1_workspace_c, real_T p_u1_workspace_phi,
                 const emxArray_real_T *mesh_pivots,
                 const emxArray_real_T *mesh_elms,
                 const emxArray_real_T *mesh_bot_elms,
                 const emxArray_real_T *mesh_left_elms,
                 const emxArray_real_T *mesh_right_elms, real_T disc_nx,
                 real_T disc_nt, real_T disc_hx, real_T disc_ht,
                 const emxArray_real_T *disc_x, const emxArray_real_T *disc_t,
                 const b_struct_T *parameters, emxArray_real_T *F);

/* End of code generation (compute_rhs.h) */
