/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main_initialize.c
 *
 * Code generation for function 'main_initialize'
 *
 */

/* Include files */
#include "main_initialize.h"
#include "_coder_main_mex.h"
#include "main_data.h"
#include "rt_nonfinite.h"
#include "timeKeeper.h"

/* Function Declarations */
static void main_once(void);

/* Function Definitions */
static void main_once(void)
{
  const int32_T postfix_exprs_5_0[2] = {0, -1};
  const int32_T cond_ends_5_0 = 61;
  const int32_T cond_starts_5_0 = 44;
  mex_InitInfAndNan();
  savedTime_not_empty_init();
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\paolo\\Documents\\Coercive Wave "
                  "Equation\\CoerciveWaves_tests\\main.m",
                  0U, 16U, 16U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "main", 0, -1, 1638);
  covrtFcnInit(&emlrtCoverageInstance, 0U, 1U, "main_anonFcn1", 171, -1, 197);
  covrtFcnInit(&emlrtCoverageInstance, 0U, 2U, "main_anonFcn2", 209, -1, 250);
  covrtFcnInit(&emlrtCoverageInstance, 0U, 3U, "main_anonFcn3", 262, -1, 358);
  covrtFcnInit(&emlrtCoverageInstance, 0U, 4U, "main_anonFcn4", 396, -1, 423);
  covrtFcnInit(&emlrtCoverageInstance, 0U, 5U, "main_anonFcn5", 435, -1, 464);
  covrtFcnInit(&emlrtCoverageInstance, 0U, 6U, "main_anonFcn6", 477, -1, 508);
  covrtFcnInit(&emlrtCoverageInstance, 0U, 7U, "main_anonFcn7", 585, -1, 603);
  covrtFcnInit(&emlrtCoverageInstance, 0U, 8U, "main_anonFcn8", 622, -1, 640);
  covrtFcnInit(&emlrtCoverageInstance, 0U, 9U, "main_anonFcn9", 660, -1, 688);
  covrtFcnInit(&emlrtCoverageInstance, 0U, 10U, "main_anonFcn10", 708, -1, 746);
  covrtFcnInit(&emlrtCoverageInstance, 0U, 11U, "main_anonFcn11", 765, -1, 805);
  covrtFcnInit(&emlrtCoverageInstance, 0U, 12U, "main_anonFcn12", 827, -1, 869);
  covrtFcnInit(&emlrtCoverageInstance, 0U, 13U, "main_anonFcn13", 891, -1, 942);
  covrtFcnInit(&emlrtCoverageInstance, 0U, 14U, "main_anonFcn14", 965, -1,
               1009);
  covrtFcnInit(&emlrtCoverageInstance, 0U, 15U, "main_anonFcn15", 1032, -1,
               1082);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 76, -1, 1634);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 171, -1, 197);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 209, -1, 250);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 262, -1, 358);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 4U, 396, -1, 423);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 5U, 435, -1, 464);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 6U, 477, -1, 508);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 7U, 585, -1, 603);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 8U, 622, -1, 640);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 9U, 660, -1, 688);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 10U, 708, -1, 746);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 11U, 765, -1, 805);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 12U, 827, -1, 869);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 13U, 891, -1, 942);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 14U, 965, -1, 1009);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 15U, 1032, -1, 1082);
  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\paolo\\Documents\\Coercive Wave "
                  "Equation\\CoerciveWaves_tests\\Domain.m",
                  1U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 1U, 0U, "Domain", 0, -1, 226);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 0U, 44, -1, 222);
  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 1U);
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\paolo\\Documents\\Coercive Wave "
                  "Equation\\CoerciveWaves_tests\\Discretization.m",
                  2U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 2U, 0U, "Discretization", 0, -1, 758);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 0U, 91, -1, 754);
  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 2U);
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\paolo\\Documents\\Coercive Wave "
                  "Equation\\CoerciveWaves_tests\\CartesianMesh.m",
                  3U, 1U, 3U, 0U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 3U, 0U, "CartesianMesh", 0, -1, 1256);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 2U, 643, -1, 1252);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 1U, 532, -1, 603);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 0U, 206, -1, 502);
  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 3U, 0U, 507, 523, 611);
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 3U);
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\paolo\\Documents\\Coercive Wave "
                  "Equation\\CoerciveWaves_tests\\SolverWaves.m",
                  4U, 1U, 4U, 2U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 4U, 0U, "SolverWaves", 0, -1, 7614);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 3U, 1030, -1, 7349);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 2U, 904, -1, 1017);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 1U, 684, -1, 862);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 0U, 129, -1, 617);
  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 4U, 0U, 655, 675, 867, 1018);
  covrtIfInit(&emlrtCoverageInstance, 4U, 1U, 867, 895, -1, 1018);
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 4U);
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\paolo\\Documents\\Coercive Wave "
                  "Equation\\CoerciveWaves_tests\\HermiteBasis.m",
                  5U, 1U, 3U, 1U, 0U, 0U, 0U, 0U, 0U, 1U, 1U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 5U, 0U, "HermiteBasis", 0, -1, 977);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 2U, 128, -1, 972);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 1U, 104, -1, 110);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 0U, 70, -1, 86);
  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 5U, 0U, 40, 61, 91, 118);
  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 5U, 0U, 43, 61, 1, 0, &cond_starts_5_0,
                &cond_ends_5_0, 2, postfix_exprs_5_0);
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 5U);
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\paolo\\Documents\\Coercive Wave "
                  "Equation\\CoerciveWaves_tests\\stiffness_buffered.m",
                  6U, 1U, 18U, 26U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 6U, 0U, "stiffness_buffered", 0, -1,
               7141);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 17U, 6910, -1, 7101);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 16U, 6521, -1, 6840);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 15U, 6111, -1, 6450);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 14U, 5679, -1, 6002);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 13U, 5285, -1, 5608);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 12U, 4895, -1, 5214);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 11U, 4463, -1, 4786);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 10U, 4069, -1, 4392);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 9U, 3674, -1, 3995);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 8U, 3213, -1, 3535);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 7U, 2824, -1, 3143);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 6U, 2445, -1, 2754);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 5U, 2030, -1, 2337);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 4U, 1664, -1, 1960);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 3U, 1298, -1, 1594);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 2U, 914, -1, 1190);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 1U, 545, -1, 844);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 0U, 158, -1, 472);
  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 6U, 0U, 57, 70, 3568, 7130);
  covrtIfInit(&emlrtCoverageInstance, 6U, 1U, 79, 92, 1215, 2354);
  covrtIfInit(&emlrtCoverageInstance, 6U, 2U, 105, 118, 488, 845);
  covrtIfInit(&emlrtCoverageInstance, 6U, 3U, 488, 505, 857, 1206);
  covrtIfInit(&emlrtCoverageInstance, 6U, 4U, 857, 874, -1, 1191);
  covrtIfInit(&emlrtCoverageInstance, 6U, 5U, 1215, 1232, 2362, 3563);
  covrtIfInit(&emlrtCoverageInstance, 6U, 6U, 1245, 1258, 1607, 1961);
  covrtIfInit(&emlrtCoverageInstance, 6U, 7U, 1607, 1624, 1973, 2353);
  covrtIfInit(&emlrtCoverageInstance, 6U, 8U, 1973, 1990, -1, 2338);
  covrtIfInit(&emlrtCoverageInstance, 6U, 9U, 2362, 2379, -1, 3552);
  covrtIfInit(&emlrtCoverageInstance, 6U, 10U, 2392, 2405, 2767, 3144);
  covrtIfInit(&emlrtCoverageInstance, 6U, 11U, 2767, 2784, 3156, 3551);
  covrtIfInit(&emlrtCoverageInstance, 6U, 12U, 3156, 3173, -1, 3536);
  covrtIfInit(&emlrtCoverageInstance, 6U, 13U, 3568, 3585, -1, 7130);
  covrtIfInit(&emlrtCoverageInstance, 6U, 14U, 3594, 3607, 4811, 6019);
  covrtIfInit(&emlrtCoverageInstance, 6U, 15U, 3620, 3633, 4011, 4393);
  covrtIfInit(&emlrtCoverageInstance, 6U, 16U, 4011, 4028, 4405, 4802);
  covrtIfInit(&emlrtCoverageInstance, 6U, 17U, 4405, 4422, -1, 4787);
  covrtIfInit(&emlrtCoverageInstance, 6U, 18U, 4811, 4828, 6027, 7129);
  covrtIfInit(&emlrtCoverageInstance, 6U, 19U, 4841, 4854, 5227, 5609);
  covrtIfInit(&emlrtCoverageInstance, 6U, 20U, 5227, 5244, 5621, 6018);
  covrtIfInit(&emlrtCoverageInstance, 6U, 21U, 5621, 5638, -1, 6003);
  covrtIfInit(&emlrtCoverageInstance, 6U, 22U, 6027, 6044, -1, 7118);
  covrtIfInit(&emlrtCoverageInstance, 6U, 23U, 6057, 6070, 6463, 6841);
  covrtIfInit(&emlrtCoverageInstance, 6U, 24U, 6463, 6480, 6853, 7117);
  covrtIfInit(&emlrtCoverageInstance, 6U, 25U, 6853, 6870, -1, 7102);
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 6U);
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\paolo\\Documents\\Coercive Wave "
                  "Equation\\CoerciveWaves_tests\\HermiteEvaluation.m",
                  7U, 2U, 4U, 2U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 7U, 0U, "HermiteEvaluation", 0, -1, 583);
  covrtFcnInit(&emlrtCoverageInstance, 7U, 1U, "eval_matrix", 584, -1, 653);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 2U, 407, -1, 579);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 1U, 341, -1, 393);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 0U, 199, -1, 251);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 3U, 618, -1, 649);
  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 7U, 0U, 115, 126, 256, 394);
  covrtIfInit(&emlrtCoverageInstance, 7U, 1U, 256, 271, -1, 394);
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 7U);
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\paolo\\Documents\\Coercive Wave "
                  "Equation\\CoerciveWaves_tests\\assemble.m",
                  8U, 1U, 3U, 0U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 8U, 0U, "assemble", 0, -1, 1366);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 2U, 1219, -1, 1362);
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 1U, 731, -1, 1206);
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 0U, 108, -1, 665);
  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 8U, 0U, 678, 694, 1214);
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 8U);
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\paolo\\Documents\\Coercive Wave "
                  "Equation\\CoerciveWaves_tests\\mapper.m",
                  9U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 9U, 0U, "mapper", 0, -1, 950);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 9U, 0U, 237, -1, 946);
  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 9U);
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\paolo\\Documents\\Coercive Wave "
                  "Equation\\CoerciveWaves_tests\\assemble_boundary.m",
                  10U, 1U, 6U, 1U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 10U, 0U, "assemble_boundary", 0, -1,
               1285);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 5U, 1237, -1, 1278);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 4U, 802, -1, 1224);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 3U, 674, -1, 766);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 2U, 626, -1, 634);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 1U, 599, -1, 607);
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 0U, 133, -1, 500);
  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 10U, 0U, 573, 590, 612, 642);
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 10U, 0U, 776, 793, 1232);
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 10U);
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\paolo\\Documents\\Coercive Wave "
                  "Equation\\CoerciveWaves_tests\\compute_rhs.m",
                  11U, 1U, 8U, 0U, 0U, 0U, 0U, 4U, 0U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 11U, 0U, "compute_rhs", 0, -1, 5085);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 7U, 4644, -1, 5073);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 6U, 4536, -1, 4570);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 5U, 4056, -1, 4484);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 4U, 3951, -1, 3983);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 3U, 3362, -1, 3899);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 2U, 3260, -1, 3290);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 1U, 2573, -1, 3209);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 0U, 106, -1, 2506);
  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 11U, 0U, 2511, 2527, 3217);
  covrtForInit(&emlrtCoverageInstance, 11U, 1U, 3295, 3316, 3907);
  covrtForInit(&emlrtCoverageInstance, 11U, 2U, 3988, 4010, 4492);
  covrtForInit(&emlrtCoverageInstance, 11U, 3U, 4575, 4598, 5081);
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 11U);
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\paolo\\Documents\\Coercive Wave "
                  "Equation\\CoerciveWaves_tests\\gaussquad.m",
                  12U, 1U, 7U, 0U, 0U, 0U, 0U, 2U, 1U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 12U, 0U, "gaussquad", 0, -1, 1099);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 4U, 721, -1, 816);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 3U, 523, -1, 650);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 2U, 454, -1, 481);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 5U, 871, -1, 1055);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 1U, 327, -1, 413);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 6U, 1068, -1, 1095);
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 0U, 189, -1, 275);
  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 12U, 0U, 280, 290, 1063);
  covrtForInit(&emlrtCoverageInstance, 12U, 1U, 494, 506, 673);
  /* Initialize While Information */
  covrtWhileInit(&emlrtCoverageInstance, 12U, 0U, 422, 441, 828);
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 12U);
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\paolo\\Documents\\Coercive Wave "
                  "Equation\\CoerciveWaves_tests\\BasisEvaluation.m",
                  13U, 1U, 3U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 13U, 0U, "BasisEvaluation", 0, -1, 686);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 2U, 189, -1, 682);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 1U, 112, -1, 154);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 0U, 85, -1, 94);
  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 13U, 0U, 55, 76, 99, 162);
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 13U);
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\paolo\\Documents\\Coercive Wave "
                  "Equation\\CoerciveWaves_tests\\SolutionEval.m",
                  14U, 1U, 5U, 1U, 0U, 0U, 0U, 2U, 0U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 14U, 0U, "SolutionEval", 0, -1, 1912);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 4U, 1296, -1, 1888);
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 3U, 818, -1, 1245);
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 2U, 763, -1, 805);
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 1U, 705, -1, 745);
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 0U, 448, -1, 635);
  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 14U, 0U, 676, 696, 750, 813);
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 14U, 0U, 1250, 1262, 1908);
  covrtForInit(&emlrtCoverageInstance, 14U, 1U, 1271, 1283, 1900);
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 14U);
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\paolo\\Documents\\Coercive Wave "
                  "Equation\\CoerciveWaves_tests\\ComputeErrors.m",
                  15U, 1U, 4U, 2U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 15U, 0U, "ComputeErrors", 0, -1, 2692);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 3U, 2654, -1, 2687);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 2U, 2503, -1, 2640);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 1U, 2282, -1, 2460);
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 0U, 92, -1, 2242);
  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 15U, 0U, 2248, 2273, 2465, 2641);
  covrtIfInit(&emlrtCoverageInstance, 15U, 1U, 2465, 2494, -1, 2641);
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 15U);
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\paolo\\Documents\\Coercive Wave "
                  "Equation\\CoerciveWaves_tests\\OperatorEval.m",
                  16U, 1U, 2U, 0U, 0U, 0U, 0U, 2U, 0U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 16U, 0U, "OperatorEval", 0, -1, 995);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 16U, 1U, 587, -1, 971);
  covrtBasicBlockInit(&emlrtCoverageInstance, 16U, 0U, 360, -1, 536);
  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 16U, 0U, 541, 553, 991);
  covrtForInit(&emlrtCoverageInstance, 16U, 1U, 562, 574, 983);
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 16U);
}

void main_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    main_once();
  }
}

/* End of code generation (main_initialize.c) */
