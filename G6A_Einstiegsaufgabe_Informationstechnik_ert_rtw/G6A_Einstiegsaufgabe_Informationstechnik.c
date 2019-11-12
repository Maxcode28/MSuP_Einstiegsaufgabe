/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: G6A_Einstiegsaufgabe_Informationstechnik.c
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
#define G6A_Ein_IN_Zusatndgrosserreicht (8U)
#define G6A_Ein_IN_Zustandkleinerreicht (12U)
#define G6A_Einstieg_IN_NO_ACTIVE_CHILD (0U)
#define G6A_Einstiegsa_IN_Zwischenstop2 (14U)
#define G6A_Einstiegsau_IN_Zustandgross (10U)
#define G6A_Einstiegsau_IN_Zustandklein (11U)
#define G6A_Einstiegsau_IN_Zwischenstop (13U)
#define G6A_Einstiegsauf_IN_Beginreset1 (2U)
#define G6A_Einstiegsaufg_IN_Beginreset (1U)
#define G6A_Einstiegsaufg_IN_Nullsetzen (3U)
#define G6A_Einstiegsaufgab_IN_Schritt1 (6U)
#define G6A_Einstiegsaufgab_IN_Schritt2 (7U)
#define G6A_Einstiegsaufgabe_IN_Schritt (5U)
#define G6A_Einstiegsaufgabe_IN_Zustand (9U)
#define G6A_Einstiegsaufgabe__IN_Reset1 (4U)

/* user code (top of source file) */
#include "i2c_reset.c"

/* Block signals (default storage) */
BlockIO_G6A_Einstiegsaufgabe_In G6A_Einstiegsaufgabe_Informat_B;

/* Block states (default storage) */
D_Work_G6A_Einstiegsaufgabe_Inf G6A_Einstiegsaufgabe_Info_DWork;

/* Real-time model */
RT_MODEL_G6A_Einstiegsaufgabe_I G6A_Einstiegsaufgabe_Informa_M_;
RT_MODEL_G6A_Einstiegsaufgabe_I *const G6A_Einstiegsaufgabe_Informa_M =
  &G6A_Einstiegsaufgabe_Informa_M_;
static void rate_monotonic_scheduler(void);
static uint16_T adcInitFlag = 0;

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void G6A_Einstiegsaufgabe_Informationstechnik_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(G6A_Einstiegsaufgabe_Informa_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(G6A_Einstiegsaufgabe_Informa_M, 2));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  G6A_Einstiegsaufgabe_Informa_M->Timing.RateInteraction.TID0_1 =
    (G6A_Einstiegsaufgabe_Informa_M->Timing.TaskCounters.TID[1] == 0);

  /* tid 1 shares data with slower tid rate: 2 */
  if (G6A_Einstiegsaufgabe_Informa_M->Timing.TaskCounters.TID[1] == 0) {
    G6A_Einstiegsaufgabe_Informa_M->Timing.RateInteraction.TID1_2 =
      (G6A_Einstiegsaufgabe_Informa_M->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (G6A_Einstiegsaufgabe_Informa_M->Timing.TaskCounters.TID[1])++;
  if ((G6A_Einstiegsaufgabe_Informa_M->Timing.TaskCounters.TID[1]) > 499) {/* Sample time: [0.01s, 0.0s] */
    G6A_Einstiegsaufgabe_Informa_M->Timing.TaskCounters.TID[1] = 0;
  }

  (G6A_Einstiegsaufgabe_Informa_M->Timing.TaskCounters.TID[2])++;
  if ((G6A_Einstiegsaufgabe_Informa_M->Timing.TaskCounters.TID[2]) > 4999) {/* Sample time: [0.1s, 0.0s] */
    G6A_Einstiegsaufgabe_Informa_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * Output and update for enable system:
 *    '<S6>/NEGATIVE Edge'
 *    '<S7>/NEGATIVE Edge'
 */
void G6A_Einstiegsa_NEGATIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T
  rtu_INprevious, rtB_NEGATIVEEdge_G6A_Einstiegsa *localB)
{
  /* Outputs for Enabled SubSystem: '<S6>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S11>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* RelationalOperator: '<S11>/Relational Operator1' */
    localB->RelationalOperator1 = ((int16_T)rtu_INprevious > (int16_T)rtu_IN);
  }

  /* End of Outputs for SubSystem: '<S6>/NEGATIVE Edge' */
}

/*
 * Output and update for enable system:
 *    '<S6>/POSITIVE Edge'
 *    '<S7>/POSITIVE Edge'
 */
void G6A_Einstiegsa_POSITIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T
  rtu_INprevious, rtB_POSITIVEEdge_G6A_Einstiegsa *localB)
{
  /* Outputs for Enabled SubSystem: '<S6>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* RelationalOperator: '<S12>/Relational Operator1' */
    localB->RelationalOperator1 = ((int16_T)rtu_IN > (int16_T)rtu_INprevious);
  }

  /* End of Outputs for SubSystem: '<S6>/POSITIVE Edge' */
}

/*
 * Output and update for atomic system:
 *    '<S3>/MATLAB Function1'
 *    '<S3>/MATLAB Function3'
 */
void G6A_Einstie_MATLABFunction1(real_T rtu_u, real32_T rtu_yalt,
  rtB_MATLABFunction1_G6A_Einstie *localB)
{
  /* MATLAB Function 'Messung des absoluten Winkels -  Auswertung der Encodersignale/MATLAB Function1': '<S8>:1' */
  /* '<S8>:1:3' */
  localB->y = rtu_yalt + (real32_T)rtu_u;
}

/* Model step function for TID0 */
void G6A_Einstiegsaufgabe_Informationstechnik_step0(void) /* Sample time: [2.0E-5s, 0.0s] */
{
  real_T y;
  boolean_T rtb_VergleichmitSchwellwert;
  boolean_T rtb_VergleichmitSchwellwert_g;
  real_T rtb_Sum;
  real_T rtb_MultiportSwitch_idx_0;
  real_T rtb_MultiportSwitch_idx_1;
  boolean_T tmp;
  boolean_T tmp_0;
  boolean_T tmp_1;

  {                                    /* Sample time: [2.0E-5s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function (c280xadc): '<Root>/Analog-Digital-Wandlung Sampletime = 0.00002 s Wichtig! F&#xFC;r korrekte Winkelmessung nicht die Sampletime vergr&#xF6;&#xDF;ern Weitere Ports k&#xF6;nnen hinzugef&#xFC;gt werden (Farbsensor, Sharp-Sensoren) Wichtig! Dieser Block ist sehr Rechenintensiv' */
  {
    AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1;  /* Reset SEQ1 module*/
    AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;/*clear INT sequencer*/
    AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 1;  /* Software Trigger*/
    while (AdcRegs.ADCST.bit.INT_SEQ1 == 0) {
    }                                  /*Wait for Sequencer INT bit to clear */

    asm(" RPT #11 || NOP");
    G6A_Einstiegsaufgabe_Informat_B.AnalogDigitalWandlungSampletime =
      (AdcRegs.ADCRESULT0) >> 4;
    G6A_Einstiegsaufgabe_Informat_B.AnalogDigitalWandlungSampleti_k =
      (AdcRegs.ADCRESULT1) >> 4;
  }

  /* RelationalOperator: '<S3>/Vergleich mit  Schwellwert' incorporates:
   *  Constant: '<S3>/Constant'
   */
  rtb_VergleichmitSchwellwert =
    (G6A_Einstiegsaufgabe_Informat_P.Constant_Value_i <=
     G6A_Einstiegsaufgabe_Informat_B.AnalogDigitalWandlungSampletime);

  /* MultiPortSwitch: '<S6>/Multiport Switch' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/either edge'
   *  Constant: '<S6>/neg. edge'
   *  Constant: '<S6>/pos. edge'
   */
  switch ((int16_T)G6A_Einstiegsaufgabe_Informat_P.EdgeDetector1_model) {
   case 1:
    rtb_MultiportSwitch_idx_0 = G6A_Einstiegsaufgabe_Informat_P.posedge_Value[0];
    rtb_MultiportSwitch_idx_1 = G6A_Einstiegsaufgabe_Informat_P.posedge_Value[1];
    break;

   case 2:
    rtb_MultiportSwitch_idx_0 = G6A_Einstiegsaufgabe_Informat_P.negedge_Value[0];
    rtb_MultiportSwitch_idx_1 = G6A_Einstiegsaufgabe_Informat_P.negedge_Value[1];
    break;

   default:
    rtb_MultiportSwitch_idx_0 =
      G6A_Einstiegsaufgabe_Informat_P.eitheredge_Value[0];
    rtb_MultiportSwitch_idx_1 =
      G6A_Einstiegsaufgabe_Informat_P.eitheredge_Value[1];
    break;
  }

  /* End of MultiPortSwitch: '<S6>/Multiport Switch' */

  /* Outputs for Enabled SubSystem: '<S6>/POSITIVE Edge' */
  /* Memory: '<S6>/Memory' */
  G6A_Einstiegsa_POSITIVEEdge(rtb_MultiportSwitch_idx_0,
    rtb_VergleichmitSchwellwert,
    G6A_Einstiegsaufgabe_Info_DWork.Memory_PreviousInput,
    &G6A_Einstiegsaufgabe_Informat_B.POSITIVEEdge);

  /* End of Outputs for SubSystem: '<S6>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S6>/NEGATIVE Edge' */
  G6A_Einstiegsa_NEGATIVEEdge(rtb_MultiportSwitch_idx_1,
    rtb_VergleichmitSchwellwert,
    G6A_Einstiegsaufgabe_Info_DWork.Memory_PreviousInput,
    &G6A_Einstiegsaufgabe_Informat_B.NEGATIVEEdge);

  /* End of Outputs for SubSystem: '<S6>/NEGATIVE Edge' */

  /* RelationalOperator: '<S3>/Vergleich mit Schwellwert' incorporates:
   *  Constant: '<S3>/Heuristisch ermittelter Schwellwert'
   */
  rtb_VergleichmitSchwellwert_g =
    (G6A_Einstiegsaufgabe_Informat_B.AnalogDigitalWandlungSampleti_k <=
     G6A_Einstiegsaufgabe_Informat_P.HeuristischermittelterSchwellwe);

  /* MATLAB Function: '<S3>/MATLAB Function2' incorporates:
   *  UnitDelay: '<S3>/Unit Delay3'
   *  UnitDelay: '<S3>/Unit Delay4'
   *  UnitDelay: '<S3>/Unit Delay5'
   */
  /* MATLAB Function 'Messung des absoluten Winkels -  Auswertung der Encodersignale/MATLAB Function2': '<S9>:1' */
  /* '<S9>:1:3' */
  y = 1.0;
  tmp_0 = !G6A_Einstiegsaufgabe_Info_DWork.UnitDelay3_DSTATE;
  tmp_1 = !G6A_Einstiegsaufgabe_Info_DWork.UnitDelay4_DSTATE;
  tmp = (tmp_0 && tmp_1);
  if (tmp && (!rtb_VergleichmitSchwellwert) && (!rtb_VergleichmitSchwellwert_g))
  {
    /* '<S9>:1:7' */
    y = G6A_Einstiegsaufgabe_Info_DWork.UnitDelay5_DSTATE;
  }

  if (tmp && (!rtb_VergleichmitSchwellwert) && rtb_VergleichmitSchwellwert_g) {
    /* '<S9>:1:10' */
    /* '<S9>:1:11' */
    y = 1.0;
  }

  if (tmp && rtb_VergleichmitSchwellwert && (!rtb_VergleichmitSchwellwert_g)) {
    /* '<S9>:1:14' */
    /* '<S9>:1:15' */
    y = -1.0;
  }

  tmp_0 = (tmp_0 && G6A_Einstiegsaufgabe_Info_DWork.UnitDelay4_DSTATE);
  if (tmp_0 && (!rtb_VergleichmitSchwellwert) && (!rtb_VergleichmitSchwellwert_g))
  {
    /* '<S9>:1:22' */
    /* '<S9>:1:23' */
    y = -1.0;
  }

  if (tmp_0 && (!rtb_VergleichmitSchwellwert) && rtb_VergleichmitSchwellwert_g)
  {
    /* '<S9>:1:26' */
    /* '<S9>:1:27' */
    y = G6A_Einstiegsaufgabe_Info_DWork.UnitDelay5_DSTATE;
  }

  if (tmp_0 && rtb_VergleichmitSchwellwert && rtb_VergleichmitSchwellwert_g) {
    /* '<S9>:1:34' */
    /* '<S9>:1:35' */
    y = 1.0;
  }

  tmp_0 = (G6A_Einstiegsaufgabe_Info_DWork.UnitDelay3_DSTATE && tmp_1);
  if (tmp_0 && (!rtb_VergleichmitSchwellwert) && (!rtb_VergleichmitSchwellwert_g))
  {
    /* '<S9>:1:38' */
    /* '<S9>:1:39' */
    y = 1.0;
  }

  if (tmp_0 && rtb_VergleichmitSchwellwert && (!rtb_VergleichmitSchwellwert_g))
  {
    /* '<S9>:1:46' */
    /* '<S9>:1:47' */
    y = G6A_Einstiegsaufgabe_Info_DWork.UnitDelay5_DSTATE;
  }

  if (tmp_0 && rtb_VergleichmitSchwellwert && rtb_VergleichmitSchwellwert_g) {
    /* '<S9>:1:50' */
    /* '<S9>:1:51' */
    y = -1.0;
  }

  tmp_0 = (G6A_Einstiegsaufgabe_Info_DWork.UnitDelay3_DSTATE &&
           G6A_Einstiegsaufgabe_Info_DWork.UnitDelay4_DSTATE);
  if (tmp_0 && (!rtb_VergleichmitSchwellwert) && rtb_VergleichmitSchwellwert_g)
  {
    /* '<S9>:1:58' */
    /* '<S9>:1:59' */
    y = -1.0;
  }

  if (tmp_0 && rtb_VergleichmitSchwellwert && (!rtb_VergleichmitSchwellwert_g))
  {
    /* '<S9>:1:62' */
    /* '<S9>:1:63' */
    y = 1.0;
  }

  if (tmp_0 && rtb_VergleichmitSchwellwert && rtb_VergleichmitSchwellwert_g) {
    /* '<S9>:1:66' */
    /* '<S9>:1:67' */
    y = G6A_Einstiegsaufgabe_Info_DWork.UnitDelay5_DSTATE;
  }

  if (y == 1.0) {
    /* '<S9>:1:70' */
    /* '<S9>:1:71' */
    G6A_Einstiegsaufgabe_Informat_B.RL = 1.0;
  } else {
    /* '<S9>:1:73' */
    G6A_Einstiegsaufgabe_Informat_B.RL = 0.0;
  }

  /* MATLAB Function: '<S3>/MATLAB Function1' incorporates:
   *  Logic: '<S6>/Logical Operator1'
   *  MATLAB Function: '<S3>/MATLAB Function2'
   *  Product: '<S3>/Product3'
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  G6A_Einstie_MATLABFunction1((real_T)
    (G6A_Einstiegsaufgabe_Informat_B.POSITIVEEdge.RelationalOperator1 ||
     G6A_Einstiegsaufgabe_Informat_B.NEGATIVEEdge.RelationalOperator1) * y,
    G6A_Einstiegsaufgabe_Info_DWork.UnitDelay1_DSTATE,
    &G6A_Einstiegsaufgabe_Informat_B.sf_MATLABFunction1);

  /* Product: '<S3>/Product1' incorporates:
   *  Constant: '<S3>/Winkel // Flanke Polulo 34:1 6V | 0,22 Polulo 74:1 6V | 0,1 Polulo 98:1 6V | 0,076 Polulo 171:1 6V | 0,043'
   */
  rtb_Sum = G6A_Einstiegsaufgabe_Informat_P.WinkelFlankePolulo3416V022Polul *
    G6A_Einstiegsaufgabe_Informat_B.sf_MATLABFunction1.y;

  /* MultiPortSwitch: '<S7>/Multiport Switch' incorporates:
   *  Constant: '<S7>/Constant1'
   *  Constant: '<S7>/either edge'
   *  Constant: '<S7>/neg. edge'
   *  Constant: '<S7>/pos. edge'
   */
  switch ((int16_T)G6A_Einstiegsaufgabe_Informat_P.EdgeDetector2_model) {
   case 1:
    rtb_MultiportSwitch_idx_0 = G6A_Einstiegsaufgabe_Informat_P.posedge_Value_e
      [0];
    rtb_MultiportSwitch_idx_1 = G6A_Einstiegsaufgabe_Informat_P.posedge_Value_e
      [1];
    break;

   case 2:
    rtb_MultiportSwitch_idx_0 = G6A_Einstiegsaufgabe_Informat_P.negedge_Value_b
      [0];
    rtb_MultiportSwitch_idx_1 = G6A_Einstiegsaufgabe_Informat_P.negedge_Value_b
      [1];
    break;

   default:
    rtb_MultiportSwitch_idx_0 =
      G6A_Einstiegsaufgabe_Informat_P.eitheredge_Value_a[0];
    rtb_MultiportSwitch_idx_1 =
      G6A_Einstiegsaufgabe_Informat_P.eitheredge_Value_a[1];
    break;
  }

  /* End of MultiPortSwitch: '<S7>/Multiport Switch' */

  /* Outputs for Enabled SubSystem: '<S7>/POSITIVE Edge' */
  /* Memory: '<S7>/Memory' */
  G6A_Einstiegsa_POSITIVEEdge(rtb_MultiportSwitch_idx_0,
    rtb_VergleichmitSchwellwert_g,
    G6A_Einstiegsaufgabe_Info_DWork.Memory_PreviousInput_e,
    &G6A_Einstiegsaufgabe_Informat_B.POSITIVEEdge_e);

  /* End of Outputs for SubSystem: '<S7>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S7>/NEGATIVE Edge' */
  G6A_Einstiegsa_NEGATIVEEdge(rtb_MultiportSwitch_idx_1,
    rtb_VergleichmitSchwellwert_g,
    G6A_Einstiegsaufgabe_Info_DWork.Memory_PreviousInput_e,
    &G6A_Einstiegsaufgabe_Informat_B.NEGATIVEEdge_h);

  /* End of Outputs for SubSystem: '<S7>/NEGATIVE Edge' */

  /* MATLAB Function: '<S3>/MATLAB Function3' incorporates:
   *  Logic: '<S7>/Logical Operator1'
   *  MATLAB Function: '<S3>/MATLAB Function2'
   *  Product: '<S3>/Product'
   *  UnitDelay: '<S3>/Unit Delay2'
   */
  G6A_Einstie_MATLABFunction1(y * (real_T)
    (G6A_Einstiegsaufgabe_Informat_B.POSITIVEEdge_e.RelationalOperator1 ||
     G6A_Einstiegsaufgabe_Informat_B.NEGATIVEEdge_h.RelationalOperator1),
    G6A_Einstiegsaufgabe_Info_DWork.UnitDelay2_DSTATE,
    &G6A_Einstiegsaufgabe_Informat_B.sf_MATLABFunction3);

  /* Sum: '<S3>/Sum' incorporates:
   *  Constant: '<S3>/Winkel // Flanke Polulo 34:1 6V | 0,22 Polulo 74:1 6V | 0,1 Polulo 98:1 6V | 0,076 Polulo 171:1 6V | 0,1'
   *  Product: '<S3>/Product2'
   */
  rtb_Sum += G6A_Einstiegsaufgabe_Informat_B.sf_MATLABFunction3.y *
    G6A_Einstiegsaufgabe_Informat_P.WinkelFlankePolulo3416V022Pol_f;

  /* RateTransition: '<Root>/Rate Transition4' */
  if (G6A_Einstiegsaufgabe_Informa_M->Timing.RateInteraction.TID0_1) {
    G6A_Einstiegsaufgabe_Informat_B.RateTransition4 = rtb_Sum;
  }

  /* End of RateTransition: '<Root>/Rate Transition4' */

  /* S-Function (c280xgpio_do): '<Root>/gr&#xFC;ne LED3 auf dem &#xB5;C gibt 1//0 codiert die Drehrichtung an' */
  {
    if (G6A_Einstiegsaufgabe_Informat_B.RL)
      GpioDataRegs.GPBSET.bit.GPIO34 = 1;
    else
      GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;
  }

  /* Update for Memory: '<S6>/Memory' */
  G6A_Einstiegsaufgabe_Info_DWork.Memory_PreviousInput =
    rtb_VergleichmitSchwellwert;

  /* Update for UnitDelay: '<S3>/Unit Delay3' */
  G6A_Einstiegsaufgabe_Info_DWork.UnitDelay3_DSTATE =
    rtb_VergleichmitSchwellwert;

  /* Update for UnitDelay: '<S3>/Unit Delay4' */
  G6A_Einstiegsaufgabe_Info_DWork.UnitDelay4_DSTATE =
    rtb_VergleichmitSchwellwert_g;

  /* Update for UnitDelay: '<S3>/Unit Delay5' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function2'
   */
  G6A_Einstiegsaufgabe_Info_DWork.UnitDelay5_DSTATE = y;

  /* Update for UnitDelay: '<S3>/Unit Delay1' */
  G6A_Einstiegsaufgabe_Info_DWork.UnitDelay1_DSTATE =
    G6A_Einstiegsaufgabe_Informat_B.sf_MATLABFunction1.y;

  /* Update for Memory: '<S7>/Memory' */
  G6A_Einstiegsaufgabe_Info_DWork.Memory_PreviousInput_e =
    rtb_VergleichmitSchwellwert_g;

  /* Update for UnitDelay: '<S3>/Unit Delay2' */
  G6A_Einstiegsaufgabe_Info_DWork.UnitDelay2_DSTATE =
    G6A_Einstiegsaufgabe_Informat_B.sf_MATLABFunction3.y;
}

/* Model step function for TID1 */
void G6A_Einstiegsaufgabe_Informationstechnik_step1(void) /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_y;
  real_T rtb_Gain;

  /* Gain: '<Root>/Gain' */
  rtb_Gain = G6A_Einstiegsaufgabe_Informat_P.Gain_Gain *
    G6A_Einstiegsaufgabe_Informat_B.RateTransition4;

  /* RateTransition: '<Root>/TmpRTBAtChartInport2' */
  if (G6A_Einstiegsaufgabe_Informa_M->Timing.RateInteraction.TID1_2) {
    G6A_Einstiegsaufgabe_Informat_B.TmpRTBAtChartInport2 =
      G6A_Einstiegsaufgabe_Info_DWork.TmpRTBAtChartInport2_Buffer0;
  }

  /* End of RateTransition: '<Root>/TmpRTBAtChartInport2' */

  /* Chart: '<Root>/Chart' */
  if (G6A_Einstiegsaufgabe_Info_DWork.temporalCounter_i1 < 511U) {
    G6A_Einstiegsaufgabe_Info_DWork.temporalCounter_i1++;
  }

  /* Gateway: Chart */
  /* During: Chart */
  if (G6A_Einstiegsaufgabe_Info_DWork.is_active_c3_G6A_Einstiegsaufga == 0U) {
    /* Entry: Chart */
    G6A_Einstiegsaufgabe_Info_DWork.is_active_c3_G6A_Einstiegsaufga = 1U;

    /* Entry Internal: Chart */
    /* Transition: '<S2>:2' */
    G6A_Einstiegsaufgabe_Info_DWork.is_c3_G6A_Einstiegsaufgabe_Info =
      G6A_Einstiegsaufg_IN_Nullsetzen;
    G6A_Einstiegsaufgabe_Info_DWork.temporalCounter_i1 = 0U;

    /* Entry 'Nullsetzen': '<S2>:1' */
    G6A_Einstiegsaufgabe_Informat_B.output = 0.0;
  } else {
    switch (G6A_Einstiegsaufgabe_Info_DWork.is_c3_G6A_Einstiegsaufgabe_Info) {
     case G6A_Einstiegsaufg_IN_Beginreset:
      /* During 'Beginreset': '<S2>:49' */
      if (G6A_Einstiegsaufgabe_Informat_B.TmpRTBAtChartInport2 > 0.1) {
        /* Transition: '<S2>:56' */
        G6A_Einstiegsaufgabe_Info_DWork.is_c3_G6A_Einstiegsaufgabe_Info =
          G6A_Einstiegsauf_IN_Beginreset1;
        G6A_Einstiegsaufgabe_Info_DWork.temporalCounter_i1 = 0U;

        /* Entry 'Beginreset1': '<S2>:55' */
        G6A_Einstiegsaufgabe_Informat_B.output =
          G6A_Einstiegsaufgabe_Info_DWork.offset;
      }
      break;

     case G6A_Einstiegsauf_IN_Beginreset1:
      /* During 'Beginreset1': '<S2>:55' */
      if (G6A_Einstiegsaufgabe_Info_DWork.temporalCounter_i1 >= 100U) {
        /* Transition: '<S2>:57' */
        G6A_Einstiegsaufgabe_Info_DWork.is_c3_G6A_Einstiegsaufgabe_Info =
          G6A_Einstiegsau_IN_Zustandgross;

        /* Entry 'Zustandgross': '<S2>:21' */
        G6A_Einstiegsaufgabe_Informat_B.output = 290.0 +
          G6A_Einstiegsaufgabe_Info_DWork.offset;
      }
      break;

     case G6A_Einstiegsaufg_IN_Nullsetzen:
      /* During 'Nullsetzen': '<S2>:1' */
      if (G6A_Einstiegsaufgabe_Info_DWork.temporalCounter_i1 >= 100U) {
        /* Transition: '<S2>:5' */
        G6A_Einstiegsaufgabe_Info_DWork.is_c3_G6A_Einstiegsaufgabe_Info =
          G6A_Einstiegsaufgabe_IN_Schritt;

        /* Entry 'Schritt': '<S2>:4' */
        G6A_Einstiegsaufgabe_Informat_B.output += 3.0;
      }
      break;

     case G6A_Einstiegsaufgabe__IN_Reset1:
      /* During 'Reset1': '<S2>:41' */
      if ((rtb_Gain < 1.0 + G6A_Einstiegsaufgabe_Info_DWork.offset) && (rtb_Gain
           > -1.0 + G6A_Einstiegsaufgabe_Info_DWork.offset)) {
        /* Transition: '<S2>:50' */
        G6A_Einstiegsaufgabe_Info_DWork.is_c3_G6A_Einstiegsaufgabe_Info =
          G6A_Einstiegsaufg_IN_Beginreset;

        /* Entry 'Beginreset': '<S2>:49' */
        G6A_Einstiegsaufgabe_Informat_B.output =
          G6A_Einstiegsaufgabe_Info_DWork.offset;
      }
      break;

     case G6A_Einstiegsaufgabe_IN_Schritt:
      /* During 'Schritt': '<S2>:4' */
      /* Transition: '<S2>:9' */
      if (G6A_Einstiegsaufgabe_Informat_B.TmpRTBAtChartInport2 < 0.1) {
        /* Transition: '<S2>:14' */
        G6A_Einstiegsaufgabe_Info_DWork.is_c3_G6A_Einstiegsaufgabe_Info =
          G6A_Einstiegsaufgab_IN_Schritt1;
        G6A_Einstiegsaufgabe_Info_DWork.temporalCounter_i1 = 0U;

        /* Entry 'Schritt1': '<S2>:11' */
        G6A_Einstiegsaufgabe_Informat_B.output += 4.0;
      } else {
        if (G6A_Einstiegsaufgabe_Informat_B.TmpRTBAtChartInport2 > 0.1) {
          /* Transition: '<S2>:16' */
          G6A_Einstiegsaufgabe_Info_DWork.is_c3_G6A_Einstiegsaufgabe_Info =
            G6A_Einstiegsaufgab_IN_Schritt2;

          /* Entry 'Schritt2': '<S2>:15' */
          G6A_Einstiegsaufgabe_Info_DWork.offset = rtb_Gain;
        }
      }
      break;

     case G6A_Einstiegsaufgab_IN_Schritt1:
      /* During 'Schritt1': '<S2>:11' */
      if (G6A_Einstiegsaufgabe_Info_DWork.temporalCounter_i1 >= 100U) {
        /* Transition: '<S2>:13' */
        G6A_Einstiegsaufgabe_Info_DWork.is_c3_G6A_Einstiegsaufgabe_Info =
          G6A_Einstiegsaufgabe_IN_Schritt;

        /* Entry 'Schritt': '<S2>:4' */
        G6A_Einstiegsaufgabe_Informat_B.output += 3.0;
      }
      break;

     case G6A_Einstiegsaufgab_IN_Schritt2:
      /* During 'Schritt2': '<S2>:15' */
      if (rtb_Gain > -361.0) {
        /* Transition: '<S2>:20' */
        G6A_Einstiegsaufgabe_Info_DWork.is_c3_G6A_Einstiegsaufgabe_Info =
          G6A_Einstiegsaufgabe_IN_Zustand;
        G6A_Einstiegsaufgabe_Info_DWork.temporalCounter_i1 = 0U;

        /* Entry 'Zustand': '<S2>:19' */
        G6A_Einstiegsaufgabe_Informat_B.output =
          G6A_Einstiegsaufgabe_Info_DWork.offset;
      }
      break;

     case G6A_Ein_IN_Zusatndgrosserreicht:
      /* During 'Zusatndgrosserreicht': '<S2>:23' */
      if (G6A_Einstiegsaufgabe_Info_DWork.temporalCounter_i1 >= 500U) {
        /* Transition: '<S2>:26' */
        G6A_Einstiegsaufgabe_Info_DWork.is_c3_G6A_Einstiegsaufgabe_Info =
          G6A_Einstiegsau_IN_Zwischenstop;

        /* Entry 'Zwischenstop': '<S2>:25' */
        G6A_Einstiegsaufgabe_Informat_B.output = 180.0 +
          G6A_Einstiegsaufgabe_Info_DWork.offset;
      }
      break;

     case G6A_Einstiegsaufgabe_IN_Zustand:
      /* During 'Zustand': '<S2>:19' */
      if (G6A_Einstiegsaufgabe_Info_DWork.temporalCounter_i1 >= 200U) {
        /* Transition: '<S2>:22' */
        G6A_Einstiegsaufgabe_Info_DWork.is_c3_G6A_Einstiegsaufgabe_Info =
          G6A_Einstiegsau_IN_Zustandgross;

        /* Entry 'Zustandgross': '<S2>:21' */
        G6A_Einstiegsaufgabe_Informat_B.output = 290.0 +
          G6A_Einstiegsaufgabe_Info_DWork.offset;
      }
      break;

     case G6A_Einstiegsau_IN_Zustandgross:
      /* During 'Zustandgross': '<S2>:21' */
      if ((rtb_Gain < 291.0 + G6A_Einstiegsaufgabe_Info_DWork.offset) &&
          (rtb_Gain > 289.0 + G6A_Einstiegsaufgabe_Info_DWork.offset)) {
        /* Transition: '<S2>:24' */
        G6A_Einstiegsaufgabe_Info_DWork.is_c3_G6A_Einstiegsaufgabe_Info =
          G6A_Ein_IN_Zusatndgrosserreicht;
        G6A_Einstiegsaufgabe_Info_DWork.temporalCounter_i1 = 0U;

        /* Entry 'Zusatndgrosserreicht': '<S2>:23' */
        G6A_Einstiegsaufgabe_Informat_B.output = 290.0 +
          G6A_Einstiegsaufgabe_Info_DWork.offset;
      } else {
        if (G6A_Einstiegsaufgabe_Informat_B.TmpRTBAtChartInport2 > 0.1) {
          /* Transition: '<S2>:47' */
          G6A_Einstiegsaufgabe_Info_DWork.is_c3_G6A_Einstiegsaufgabe_Info =
            G6A_Einstiegsaufgabe__IN_Reset1;

          /* Entry 'Reset1': '<S2>:41' */
          G6A_Einstiegsaufgabe_Informat_B.output =
            G6A_Einstiegsaufgabe_Info_DWork.offset;
        }
      }
      break;

     case G6A_Einstiegsau_IN_Zustandklein:
      /* During 'Zustandklein': '<S2>:28' */
      if ((rtb_Gain < 31.0 + G6A_Einstiegsaufgabe_Info_DWork.offset) &&
          (rtb_Gain > 29.0 + G6A_Einstiegsaufgabe_Info_DWork.offset)) {
        /* Transition: '<S2>:32' */
        G6A_Einstiegsaufgabe_Info_DWork.is_c3_G6A_Einstiegsaufgabe_Info =
          G6A_Ein_IN_Zustandkleinerreicht;
        G6A_Einstiegsaufgabe_Info_DWork.temporalCounter_i1 = 0U;

        /* Entry 'Zustandkleinerreicht': '<S2>:31' */
        G6A_Einstiegsaufgabe_Informat_B.output = 30.0 +
          G6A_Einstiegsaufgabe_Info_DWork.offset;
      } else {
        if (G6A_Einstiegsaufgabe_Informat_B.TmpRTBAtChartInport2 > 0.1) {
          /* Transition: '<S2>:44' */
          G6A_Einstiegsaufgabe_Info_DWork.is_c3_G6A_Einstiegsaufgabe_Info =
            G6A_Einstiegsaufgabe__IN_Reset1;

          /* Entry 'Reset1': '<S2>:41' */
          G6A_Einstiegsaufgabe_Informat_B.output =
            G6A_Einstiegsaufgabe_Info_DWork.offset;
        }
      }
      break;

     case G6A_Ein_IN_Zustandkleinerreicht:
      /* During 'Zustandkleinerreicht': '<S2>:31' */
      if (G6A_Einstiegsaufgabe_Info_DWork.temporalCounter_i1 >= 500U) {
        /* Transition: '<S2>:39' */
        G6A_Einstiegsaufgabe_Info_DWork.is_c3_G6A_Einstiegsaufgabe_Info =
          G6A_Einstiegsa_IN_Zwischenstop2;

        /* Entry 'Zwischenstop2': '<S2>:35' */
        G6A_Einstiegsaufgabe_Informat_B.output = 180.0 +
          G6A_Einstiegsaufgabe_Info_DWork.offset;
      }
      break;

     case G6A_Einstiegsau_IN_Zwischenstop:
      /* During 'Zwischenstop': '<S2>:25' */
      if ((rtb_Gain < 181.0 + G6A_Einstiegsaufgabe_Info_DWork.offset) &&
          (rtb_Gain > 179.0 + G6A_Einstiegsaufgabe_Info_DWork.offset)) {
        /* Transition: '<S2>:29' */
        G6A_Einstiegsaufgabe_Info_DWork.is_c3_G6A_Einstiegsaufgabe_Info =
          G6A_Einstiegsau_IN_Zustandklein;

        /* Entry 'Zustandklein': '<S2>:28' */
        G6A_Einstiegsaufgabe_Informat_B.output = 30.0 +
          G6A_Einstiegsaufgabe_Info_DWork.offset;
      } else {
        if (G6A_Einstiegsaufgabe_Informat_B.TmpRTBAtChartInport2 > 0.1) {
          /* Transition: '<S2>:43' */
          G6A_Einstiegsaufgabe_Info_DWork.is_c3_G6A_Einstiegsaufgabe_Info =
            G6A_Einstiegsaufgabe__IN_Reset1;

          /* Entry 'Reset1': '<S2>:41' */
          G6A_Einstiegsaufgabe_Informat_B.output =
            G6A_Einstiegsaufgabe_Info_DWork.offset;
        }
      }
      break;

     default:
      /* During 'Zwischenstop2': '<S2>:35' */
      if ((rtb_Gain < 181.0 + G6A_Einstiegsaufgabe_Info_DWork.offset) &&
          (rtb_Gain > 179.0 + G6A_Einstiegsaufgabe_Info_DWork.offset)) {
        /* Transition: '<S2>:40' */
        G6A_Einstiegsaufgabe_Info_DWork.is_c3_G6A_Einstiegsaufgabe_Info =
          G6A_Einstiegsau_IN_Zustandgross;

        /* Entry 'Zustandgross': '<S2>:21' */
        G6A_Einstiegsaufgabe_Informat_B.output = 290.0 +
          G6A_Einstiegsaufgabe_Info_DWork.offset;
      } else {
        if (G6A_Einstiegsaufgabe_Informat_B.TmpRTBAtChartInport2 > 0.1) {
          /* Transition: '<S2>:46' */
          G6A_Einstiegsaufgabe_Info_DWork.is_c3_G6A_Einstiegsaufgabe_Info =
            G6A_Einstiegsaufgabe__IN_Reset1;

          /* Entry 'Reset1': '<S2>:41' */
          G6A_Einstiegsaufgabe_Informat_B.output =
            G6A_Einstiegsaufgabe_Info_DWork.offset;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* Sum: '<S5>/Sum' */
  rtb_Gain = G6A_Einstiegsaufgabe_Informat_B.output - rtb_Gain;

  /* DeadZone: '<S5>/Dead Zone' */
  if (rtb_Gain > G6A_Einstiegsaufgabe_Informat_P.DeadZone_End) {
    rtb_Gain -= G6A_Einstiegsaufgabe_Informat_P.DeadZone_End;
  } else if (rtb_Gain >= G6A_Einstiegsaufgabe_Informat_P.DeadZone_Start) {
    rtb_Gain = 0.0;
  } else {
    rtb_Gain -= G6A_Einstiegsaufgabe_Informat_P.DeadZone_Start;
  }

  /* End of DeadZone: '<S5>/Dead Zone' */

  /* Gain: '<S5>/Verstaerkung' */
  rtb_Gain *= G6A_Einstiegsaufgabe_Informat_P.Verstaerkung_Gain;

  /* MATLAB Function: '<S5>/Richtung' */
  /* MATLAB Function 'P-Regler mit Regelfehler Begrenzung Initial: k = 0.1, limiit = +//- 100 Sampletime 0.01/Richtung': '<S27>:1' */
  if (rtb_Gain > 0.0) {
    /* '<S27>:1:3' */
    /* '<S27>:1:4' */
    G6A_Einstiegsaufgabe_Informat_B.y = 1.0;
  } else {
    /* '<S27>:1:6' */
    G6A_Einstiegsaufgabe_Informat_B.y = 0.0;
  }

  /* End of MATLAB Function: '<S5>/Richtung' */

  /* S-Function (c280xgpio_do): '<Root>/Drehrichtungsvorgabe f&#xFC;r einen Motor' */
  {
    if (G6A_Einstiegsaufgabe_Informat_B.y)
      GpioDataRegs.GPASET.bit.GPIO21 = 1;
    else
      GpioDataRegs.GPACLEAR.bit.GPIO21 = 1;
  }

  /* Abs: '<S5>/Abs' */
  rtb_Gain = fabs(rtb_Gain);

  /* MATLAB Function: '<S5>/Betrag' */
  /* MATLAB Function 'P-Regler mit Regelfehler Begrenzung Initial: k = 0.1, limiit = +//- 100 Sampletime 0.01/Betrag': '<S26>:1' */
  if ((0.5 < rtb_Gain) && (rtb_Gain < 60.0)) {
    /* '<S26>:1:3' */
    /* '<S26>:1:4' */
    rtb_y = 60.0;
  } else if (rtb_Gain <= 0.5) {
    /* '<S26>:1:5' */
    /* '<S26>:1:6' */
    rtb_y = 0.0;
  } else if (rtb_Gain >= 60.0) {
    /* '<S26>:1:7' */
    /* '<S26>:1:8' */
    rtb_y = 100.0;
  } else {
    /* '<S26>:1:10' */
    rtb_y = rtb_Gain;
  }

  /* End of MATLAB Function: '<S5>/Betrag' */

  /* S-Function (c280xpwm): '<Root>/PWM Vorgabe f&#xFC;r einen Motor ' */

  /*-- Update CMPB value for ePWM2 --*/
  {
    EPwm2Regs.CMPB = (uint16_T)((uint32_T)EPwm2Regs.TBPRD * rtb_y * 0.01);
  }
}

/* Model step function for TID2 */
void G6A_Einstiegsaufgabe_Informationstechnik_step2(void) /* Sample time: [0.1s, 0.0s] */
{
  real_T rtb_Switch;

  /* S-Function (c280xgpio_di): '<Root>/Digital Input' */
  {
    G6A_Einstiegsaufgabe_Informat_B.DigitalInput =
      GpioDataRegs.GPADAT.bit.GPIO24;
  }

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   */
  if (G6A_Einstiegsaufgabe_Informat_B.DigitalInput >
      G6A_Einstiegsaufgabe_Informat_P.Switch_Threshold) {
    rtb_Switch = G6A_Einstiegsaufgabe_Informat_P.Constant_Value;
  } else {
    rtb_Switch = G6A_Einstiegsaufgabe_Informat_P.Constant1_Value;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Update for RateTransition: '<Root>/TmpRTBAtChartInport2' */
  G6A_Einstiegsaufgabe_Info_DWork.TmpRTBAtChartInport2_Buffer0 = rtb_Switch;
}

/* Model initialize function */
void G6A_Einstiegsaufgabe_Informationstechnik_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)G6A_Einstiegsaufgabe_Informa_M, 0,
                sizeof(RT_MODEL_G6A_Einstiegsaufgabe_I));

  /* block I/O */
  (void) memset(((void *) &G6A_Einstiegsaufgabe_Informat_B), 0,
                sizeof(BlockIO_G6A_Einstiegsaufgabe_In));

  /* states (dwork) */
  (void) memset((void *)&G6A_Einstiegsaufgabe_Info_DWork, 0,
                sizeof(D_Work_G6A_Einstiegsaufgabe_Inf));

  /* Start for S-Function (c280xadc): '<Root>/Analog-Digital-Wandlung Sampletime = 0.00002 s Wichtig! F&#xFC;r korrekte Winkelmessung nicht die Sampletime vergr&#xF6;&#xDF;ern Weitere Ports k&#xF6;nnen hinzugef&#xFC;gt werden (Farbsensor, Sharp-Sensoren) Wichtig! Dieser Block ist sehr Rechenintensiv' */
  if (adcInitFlag == 0) {
    InitAdc();
    adcInitFlag = 1;
  }

  config_ADC_A (1U, 16U, 0U, 0U, 0U);

  /* Start for RateTransition: '<Root>/TmpRTBAtChartInport2' */
  G6A_Einstiegsaufgabe_Informat_B.TmpRTBAtChartInport2 =
    G6A_Einstiegsaufgabe_Informat_P.TmpRTBAtChartInport2_InitialCon;

  /* Start for S-Function (c280xgpio_do): '<Root>/Drehrichtungsvorgabe f&#xFC;r einen Motor' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0xFFFFF3FF;
  GpioCtrlRegs.GPADIR.all |= 0x200000;
  EDIS;

  /* Start for S-Function (c280xpwm): '<Root>/PWM Vorgabe f&#xFC;r einen Motor ' */

  /*** Initialize ePWM2 modules ***/
  {
    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm2Regs.TBPRD = 64000;

    /* // Time-Base Control Register
       EPwm2Regs.TBCTL.bit.CTRMODE    = 0;          // Counter Mode
       EPwm2Regs.TBCTL.bit.SYNCOSEL   = 3;          // Sync output select
       EPwm2Regs.TBCTL.bit.PRDLD      = 0;          // Shadow select
       EPwm2Regs.TBCTL.bit.PHSEN      = 0;          // Phase load enable
       EPwm2Regs.TBCTL.bit.PHSDIR     = 0;          // Phase Direction
       EPwm2Regs.TBCTL.bit.HSPCLKDIV  = 0;          // High speed time pre-scale
       EPwm2Regs.TBCTL.bit.CLKDIV     = 0;          // Timebase clock pre-scale
     */
    EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FBF) | 0x30;

    /* // Time-Base Phase Register
       EPwm2Regs.TBPHS.half.TBPHS     = 0;          // Phase offset register
     */
    EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000) | 0x0;
    EPwm2Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /* // Counter-Compare Control Register
       EPwm2Regs.CMPCTL.bit.SHDWAMODE = 0;  // Compare A block operating mode.
       EPwm2Regs.CMPCTL.bit.SHDWBMODE = 0;  // Compare B block operating mode.
       EPwm2Regs.CMPCTL.bit.LOADAMODE = 0;          // Active compare A
       EPwm2Regs.CMPCTL.bit.LOADBMODE = 0;          // Active compare A
     */
    EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x5F) | 0x0;
    EPwm2Regs.CMPA.half.CMPA = 32000;
    EPwm2Regs.CMPB = 0;

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm2Regs.AQCTLA.all = 36;
    EPwm2Regs.AQCTLB.all = 264;

    /* // Action-Qualifier Software Force Register
       EPwm2Regs.AQSFRC.bit.RLDCSF    = 0;          // Reload from Shadow options
     */
    EPwm2Regs.AQSFRC.all = (EPwm2Regs.AQSFRC.all & ~0xC0) | 0x0;

    /* // Action-Qualifier Continuous S/W Force Register Set
       EPwm2Regs.AQCSFRC.bit.CSFA     = 0;          // Continuous Software Force on output A
       EPwm2Regs.AQCSFRC.bit.CSFB     = 0;          // Continuous Software Force on output B
     */
    EPwm2Regs.AQCSFRC.all = (EPwm2Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /* // Dead-Band Generator Control Register
       EPwm2Regs.DBCTL.bit.OUT_MODE   = 0;          // Dead Band Output Mode Control
       EPwm2Regs.DBCTL.bit.IN_MODE    = 0;          // Dead Band Input Select Mode Control
       EPwm2Regs.DBCTL.bit.POLSEL     = 0;          // Polarity Select Control
     */
    EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x3F) | 0x0;
    EPwm2Regs.DBRED = 0;
    EPwm2Regs.DBFED = 0;

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /* // Event-Trigger Selection and Event-Trigger Pre-Scale Register
       EPwm2Regs.ETSEL.bit.SOCAEN     = 0;          // Start of conversion A Enable
       EPwm2Regs.ETSEL.bit.SOCASEL    = 1;          // Start of conversion A Select
       EPwm2Regs.ETPS.bit.SOCAPRD     = 1;          // EPWM2SOCA Period Select
       EPwm2Regs.ETSEL.bit.SOCBEN     = 0;          // Start of conversion B Enable
       EPwm2Regs.ETSEL.bit.SOCBSEL    = 1;          // Start of conversion B Select
       EPwm2Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM2SOCB Period Select
       EPwm2Regs.ETSEL.bit.INTEN      = 0;          // EPWM2INTn Enable
       EPwm2Regs.ETSEL.bit.INTSEL     = 1;          // EPWM2INTn Select
       EPwm2Regs.ETPS.bit.INTPRD      = 1;          // EPWM2INTn Period Select
     */
    EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF0F) | 0x1101;
    EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x3303) | 0x1101;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /* // PWM-Chopper Control Register
       EPwm2Regs.PCCTL.bit.CHPEN      = 0;          // PWM chopping enable
       EPwm2Regs.PCCTL.bit.CHPFREQ    = 0;          // Chopping clock frequency
       EPwm2Regs.PCCTL.bit.OSHTWTH    = 0;          // One-shot pulse width
       EPwm2Regs.PCCTL.bit.CHPDUTY    = 0;          // Chopping clock Duty cycle
     */
    EPwm2Regs.PCCTL.all = (EPwm2Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm2Regs.TZSEL.all = 0;

    /* // Trip-Zone Control Register
       EPwm2Regs.TZCTL.bit.TZA        = 3;          // TZ1 to TZ6 Trip Action On EPWM2A
       EPwm2Regs.TZCTL.bit.TZB        = 3;          // TZ1 to TZ6 Trip Action On EPWM2B
     */
    EPwm2Regs.TZCTL.all = (EPwm2Regs.TZCTL.all & ~0xF) | 0xF;

    /* // Trip-Zone Enable Interrupt Register
       EPwm2Regs.TZEINT.bit.OST       = 0;          // Trip Zones One Shot Int Enable
       EPwm2Regs.TZEINT.bit.CBC       = 0;          // Trip Zones Cycle By Cycle Int Enable
     */
    EPwm2Regs.TZEINT.all = (EPwm2Regs.TZEINT.all & ~0x6) | 0x0;
    EDIS;
  }

  /* Start for S-Function (c280xgpio_do): '<Root>/gr&#xFC;ne LED3 auf dem &#xB5;C gibt 1//0 codiert die Drehrichtung an' */
  EALLOW;
  GpioCtrlRegs.GPBMUX1.all &= 0xFFFFFFCF;
  GpioCtrlRegs.GPBDIR.all |= 0x4;
  EDIS;

  /* Start for S-Function (c280xgpio_di): '<Root>/Digital Input' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0xFFFCFFFF;
  GpioCtrlRegs.GPADIR.all &= 0xFEFFFFFF;
  EDIS;

  /* InitializeConditions for Memory: '<S6>/Memory' */
  G6A_Einstiegsaufgabe_Info_DWork.Memory_PreviousInput =
    G6A_Einstiegsaufgabe_Informat_P.EdgeDetector1_ic;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay3' */
  G6A_Einstiegsaufgabe_Info_DWork.UnitDelay3_DSTATE =
    G6A_Einstiegsaufgabe_Informat_P.UnitDelay3_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay4' */
  G6A_Einstiegsaufgabe_Info_DWork.UnitDelay4_DSTATE =
    G6A_Einstiegsaufgabe_Informat_P.UnitDelay4_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay5' */
  G6A_Einstiegsaufgabe_Info_DWork.UnitDelay5_DSTATE =
    G6A_Einstiegsaufgabe_Informat_P.UnitDelay5_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay1' */
  G6A_Einstiegsaufgabe_Info_DWork.UnitDelay1_DSTATE =
    G6A_Einstiegsaufgabe_Informat_P.UnitDelay1_InitialCondition;

  /* InitializeConditions for Memory: '<S7>/Memory' */
  G6A_Einstiegsaufgabe_Info_DWork.Memory_PreviousInput_e =
    G6A_Einstiegsaufgabe_Informat_P.EdgeDetector2_ic;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay2' */
  G6A_Einstiegsaufgabe_Info_DWork.UnitDelay2_DSTATE =
    G6A_Einstiegsaufgabe_Informat_P.UnitDelay2_InitialCondition;

  /* InitializeConditions for RateTransition: '<Root>/TmpRTBAtChartInport2' */
  G6A_Einstiegsaufgabe_Info_DWork.TmpRTBAtChartInport2_Buffer0 =
    G6A_Einstiegsaufgabe_Informat_P.TmpRTBAtChartInport2_InitialCon;

  /* SystemInitialize for Chart: '<Root>/Chart' */
  G6A_Einstiegsaufgabe_Info_DWork.temporalCounter_i1 = 0U;
  G6A_Einstiegsaufgabe_Info_DWork.is_active_c3_G6A_Einstiegsaufga = 0U;
  G6A_Einstiegsaufgabe_Info_DWork.is_c3_G6A_Einstiegsaufgabe_Info =
    G6A_Einstieg_IN_NO_ACTIVE_CHILD;
  G6A_Einstiegsaufgabe_Info_DWork.offset = 0.0;
  G6A_Einstiegsaufgabe_Informat_B.output = 0.0;
}

/* Model terminate function */
void G6A_Einstiegsaufgabe_Informationstechnik_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
