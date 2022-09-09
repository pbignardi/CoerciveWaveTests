/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main_emxutil.h
 *
 * Code generation for function 'main_emxutil'
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
void emxCopyStruct_struct_T(const emlrtStack *sp, e_struct_T *dst,
                            const e_struct_T *src,
                            const emlrtRTEInfo *srcLocation);

void emxCopy_real_T(const emlrtStack *sp, emxArray_real_T **dst,
                    emxArray_real_T *const *src,
                    const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_boolean_T(const emlrtStack *sp,
                                 emxArray_boolean_T *emxArray, int32_T oldNumel,
                                 const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_int32_T(const emlrtStack *sp, emxArray_int32_T *emxArray,
                               int32_T oldNumel,
                               const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T *emxArray,
                              int32_T oldNumel,
                              const emlrtRTEInfo *srcLocation);

void emxFreeStruct_sparse(const emlrtStack *sp, b_sparse *pStruct);

void emxFreeStruct_struct_T(const emlrtStack *sp, e_struct_T *pStruct);

void emxFree_boolean_T(const emlrtStack *sp, emxArray_boolean_T **pEmxArray);

void emxFree_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray);

void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);

void emxInitStruct_sparse(const emlrtStack *sp, b_sparse *pStruct,
                          const emlrtRTEInfo *srcLocation);

void emxInitStruct_struct_T(const emlrtStack *sp, e_struct_T *pStruct,
                            const emlrtRTEInfo *srcLocation);

void emxInit_boolean_T(const emlrtStack *sp, emxArray_boolean_T **pEmxArray,
                       const emlrtRTEInfo *srcLocation);

void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
                     int32_T numDimensions, const emlrtRTEInfo *srcLocation);

void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                    int32_T numDimensions, const emlrtRTEInfo *srcLocation);

/* End of code generation (main_emxutil.h) */
