/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * HermiteEvaluation.h
 *
 * Code generation for function 'HermiteEvaluation'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void HermiteEvaluation(real_T h, real_T E_d0d0[16], real_T E_d0d1[16],
                       real_T E_d1d0[16], real_T E_d1d1[16]);

void b_HermiteEvaluation(real_T h, real_T E_d0d0[16], real_T E_d0d1[16],
                         real_T E_d1d0[16], real_T E_d1d1[16]);

/* End of code generation (HermiteEvaluation.h) */
