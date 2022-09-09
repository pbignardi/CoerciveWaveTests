/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ComputeErrors.h
 *
 * Code generation for function 'ComputeErrors'
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
void ComputeErrors(
    const emlrtStack *sp, const emxArray_real_T *u, real_T problem_c,
    real_T problem_u_workspace_c, real_T problem_u_workspace_phi,
    real_T problem_dx_u_workspace_c, real_T problem_dx_u_workspace_phi,
    real_T problem_dt_u_workspace_c, real_T problem_dt_u_workspace_phi,
    real_T problem_ddx_u_workspace_c, real_T problem_ddx_u_workspace_phi,
    real_T problem_ddt_u_workspace_c, real_T problem_ddt_u_workspace_phi,
    const emxArray_real_T *mesh_pivots, const emxArray_real_T *mesh_elms,
    real_T disc_nx, real_T disc_nt, real_T disc_hx, real_T disc_ht,
    const emxArray_real_T *disc_xx, const emxArray_real_T *disc_tt,
    c_struct_T *errors);

void plus(const emlrtStack *sp, emxArray_real_T *r4, const emxArray_real_T *r5);

/* End of code generation (ComputeErrors.h) */
