/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CartesianMesh.h
 *
 * Code generation for function 'CartesianMesh'
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
void CartesianMesh(const emlrtStack *sp, real_T disc_nx, real_T disc_nt,
                   emxArray_real_T *mesh_ids, emxArray_real_T *mesh_pivots,
                   emxArray_real_T *mesh_elms, emxArray_real_T *mesh_bot,
                   emxArray_real_T *mesh_top, emxArray_real_T *mesh_left,
                   emxArray_real_T *mesh_right, emxArray_real_T *mesh_bot_elms,
                   emxArray_real_T *mesh_top_elms,
                   emxArray_real_T *mesh_left_elms,
                   emxArray_real_T *mesh_right_elms);

/* End of code generation (CartesianMesh.h) */
