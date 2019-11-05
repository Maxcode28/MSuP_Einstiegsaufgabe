/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: G6A_Einstiegsaufgabe_Informationstechnik1_private.h
 *
 * Code generated for Simulink model 'G6A_Einstiegsaufgabe_Informationstechnik1'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Nov  5 10:14:52 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_G6A_Einstiegsaufgabe_Informationstechnik1_private_h_
#define RTW_HEADER_G6A_Einstiegsaufgabe_Informationstechnik1_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "G6A_Einstiegsaufgabe_Informationstechnik1.h"

void config_ADC_A(uint16_T maxconvReg , uint16_T adcChselSEQ1Reg, uint16_T
                  adcChselSEQ2Reg, uint16_T adcChselSEQ3Reg, uint16_T
                  adcChselSEQ4Reg);
extern void G6A_Einstiegsa_NEGATIVEEdge(real_T rtu_Enable, boolean_T rtu_IN,
  boolean_T rtu_INprevious, rtB_NEGATIVEEdge_G6A_Einstiegsa *localB);
extern void G6A_Einstiegsa_POSITIVEEdge(real_T rtu_Enable, boolean_T rtu_IN,
  boolean_T rtu_INprevious, rtB_POSITIVEEdge_G6A_Einstiegsa *localB);
extern void G6A_Einstie_MATLABFunction1(real_T rtu_u, real32_T rtu_yalt,
  rtB_MATLABFunction1_G6A_Einstie *localB);

#endif                                 /* RTW_HEADER_G6A_Einstiegsaufgabe_Informationstechnik1_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
