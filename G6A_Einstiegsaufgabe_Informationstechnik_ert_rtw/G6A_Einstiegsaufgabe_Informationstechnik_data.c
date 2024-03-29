/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: G6A_Einstiegsaufgabe_Informationstechnik_data.c
 *
 * Code generated for Simulink model 'G6A_Einstiegsaufgabe_Informationstechnik'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Nov 11 17:44:35 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "G6A_Einstiegsaufgabe_Informationstechnik.h"
#include "G6A_Einstiegsaufgabe_Informationstechnik_private.h"

/* Block parameters (default storage) */
Parameters_G6A_Einstiegsaufgabe G6A_Einstiegsaufgabe_Informat_P = {
  /* Mask Parameter: EdgeDetector1_model
   * Referenced by: '<S6>/Constant1'
   */
  3.0,

  /* Mask Parameter: EdgeDetector2_model
   * Referenced by: '<S7>/Constant1'
   */
  3.0,

  /* Mask Parameter: EdgeDetector1_ic
   * Referenced by: '<S6>/Memory'
   */
  0,

  /* Mask Parameter: EdgeDetector2_ic
   * Referenced by: '<S7>/Memory'
   */
  0,

  /* Expression: 3.3
   * Referenced by: '<Root>/Constant1'
   */
  3.3,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: [1 1]
   * Referenced by: '<S6>/either edge'
   */
  { 1.0, 1.0 },

  /* Expression: [0 1]
   * Referenced by: '<S6>/neg. edge'
   */
  { 0.0, 1.0 },

  /* Expression: [1 0]
   * Referenced by: '<S6>/pos. edge'
   */
  { 1.0, 0.0 },

  /* Expression: [1 1]
   * Referenced by: '<S7>/either edge'
   */
  { 1.0, 1.0 },

  /* Expression: [0 1]
   * Referenced by: '<S7>/neg. edge'
   */
  { 0.0, 1.0 },

  /* Expression: [1 0]
   * Referenced by: '<S7>/pos. edge'
   */
  { 1.0, 0.0 },

  /* Expression: 0.076
   * Referenced by: '<S3>/Winkel // Flanke Polulo 34:1 6V | 0,22 Polulo 74:1 6V | 0,1 Polulo 98:1 6V | 0,076 Polulo 171:1 6V | 0,043'
   */
  0.076,

  /* Expression: 2000
   * Referenced by: '<S3>/Constant'
   */
  2000.0,

  /* Expression: 2000
   * Referenced by: '<S3>/Heuristisch ermittelter Schwellwert'
   */
  2000.0,

  /* Expression: 0
   * Referenced by: '<S3>/Unit Delay5'
   */
  0.0,

  /* Expression: 0.076
   * Referenced by: '<S3>/Winkel // Flanke Polulo 34:1 6V | 0,22 Polulo 74:1 6V | 0,1 Polulo 98:1 6V | 0,076 Polulo 171:1 6V | 0,1'
   */
  0.076,

  /* Expression: 1/1.5
   * Referenced by: '<Root>/Gain'
   */
  0.66666666666666663,

  /* Expression: 0
   * Referenced by: synthesized block
   */
  0.0,

  /* Expression: -5
   * Referenced by: '<S5>/Dead Zone'
   */
  -5.0,

  /* Expression: 5
   * Referenced by: '<S5>/Dead Zone'
   */
  5.0,

  /* Expression: 0.5
   * Referenced by: '<S5>/Verstaerkung'
   */
  0.5,

  /* Computed Parameter: UnitDelay1_InitialCondition
   * Referenced by: '<S3>/Unit Delay1'
   */
  0.0F,

  /* Computed Parameter: UnitDelay2_InitialCondition
   * Referenced by: '<S3>/Unit Delay2'
   */
  0.0F,

  /* Computed Parameter: Switch_Threshold
   * Referenced by: '<Root>/Switch'
   */
  0.0F,

  /* Computed Parameter: UnitDelay3_InitialCondition
   * Referenced by: '<S3>/Unit Delay3'
   */
  0,

  /* Computed Parameter: UnitDelay4_InitialCondition
   * Referenced by: '<S3>/Unit Delay4'
   */
  0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
