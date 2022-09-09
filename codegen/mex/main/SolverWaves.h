/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SolverWaves.h
 *
 * Code generation for function 'SolverWaves'
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
                 emxArray_real_T *u);

/* End of code generation (SolverWaves.h) */
