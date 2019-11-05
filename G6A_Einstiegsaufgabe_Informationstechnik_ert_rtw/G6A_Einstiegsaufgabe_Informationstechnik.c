/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: G6A_Einstiegsaufgabe_Informationstechnik.c
 *
 * Code generated for Simulink model 'G6A_Einstiegsaufgabe_Informationstechnik'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Nov  4 14:39:35 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "G6A_Einstiegsaufgabe_Informationstechnik.h"
#include "G6A_Einstiegsaufgabe_Informationstechnik_private.h"

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

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (G6A_Einstiegsaufgabe_Informa_M->Timing.TaskCounters.TID[1])++;
  if ((G6A_Einstiegsaufgabe_Informa_M->Timing.TaskCounters.TID[1]) > 499) {/* Sample time: [0.01s, 0.0s] */
    G6A_Einstiegsaufgabe_Informa_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for enable system:
 *    '<S8>/NEGATIVE Edge'
 *    '<S9>/NEGATIVE Edge'
 */
void G6A_Einstiegsa_NEGATIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T
  rtu_INprevious, rtB_NEGATIVEEdge_G6A_Einstiegsa *localB)
{
  /* Outputs for Enabled SubSystem: '<S8>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S13>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* RelationalOperator: '<S13>/Relational Operator1' */
    localB->RelationalOperator1 = ((int16_T)rtu_INprevious > (int16_T)rtu_IN);
  }

  /* End of Outputs for SubSystem: '<S8>/NEGATIVE Edge' */
}

/*
 * Output and update for enable system:
 *    '<S8>/POSITIVE Edge'
 *    '<S9>/POSITIVE Edge'
 */
void G6A_Einstiegsa_POSITIVEEdge(real_T rtu_Enable, boolean_T rtu_IN, boolean_T
  rtu_INprevious, rtB_POSITIVEEdge_G6A_Einstiegsa *localB)
{
  /* Outputs for Enabled SubSystem: '<S8>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S14>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* RelationalOperator: '<S14>/Relational Operator1' */
    localB->RelationalOperator1 = ((int16_T)rtu_IN > (int16_T)rtu_INprevious);
  }

  /* End of Outputs for SubSystem: '<S8>/POSITIVE Edge' */
}

/*
 * Output and update for atomic system:
 *    '<S4>/MATLAB Function1'
 *    '<S4>/MATLAB Function3'
 */
void G6A_Einstie_MATLABFunction1(real_T rtu_u, real32_T rtu_yalt,
  rtB_MATLABFunction1_G6A_Einstie *localB)
{
  /* MATLAB Function 'Messung des absoluten Winkels -  Auswertung der Encodersignale/MATLAB Function1': '<S10>:1' */
  /* '<S10>:1:3' */
  localB->y = rtu_yalt + (real32_T)rtu_u;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model step function for TID0 */
void G6A_Einstiegsaufgabe_Informationstechnik_step0(void) /* Sample time: [2.0E-5s, 0.0s] */
{
  real_T y;
  boolean_T rtb_VergleichmitSchwellwert;
  boolean_T rtb_VergleichmitSchwellwert_g;
  real_T rtb_Sum_p;
  int16_T rtb_RL;
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

  /* RelationalOperator: '<S4>/Vergleich mit  Schwellwert' incorporates:
   *  Constant: '<S4>/Constant'
   */
  rtb_VergleichmitSchwellwert = (G6A_Einstiegsaufgabe_Informat_P.Constant_Value <=
    G6A_Einstiegsaufgabe_Informat_B.AnalogDigitalWandlungSampletime);

  /* MultiPortSwitch: '<S8>/Multiport Switch' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/either edge'
   *  Constant: '<S8>/neg. edge'
   *  Constant: '<S8>/pos. edge'
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

  /* End of MultiPortSwitch: '<S8>/Multiport Switch' */

  /* Outputs for Enabled SubSystem: '<S8>/POSITIVE Edge' */
  /* Memory: '<S8>/Memory' */
  G6A_Einstiegsa_POSITIVEEdge(rtb_MultiportSwitch_idx_0,
    rtb_VergleichmitSchwellwert,
    G6A_Einstiegsaufgabe_Info_DWork.Memory_PreviousInput,
    &G6A_Einstiegsaufgabe_Informat_B.POSITIVEEdge);

  /* End of Outputs for SubSystem: '<S8>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S8>/NEGATIVE Edge' */
  G6A_Einstiegsa_NEGATIVEEdge(rtb_MultiportSwitch_idx_1,
    rtb_VergleichmitSchwellwert,
    G6A_Einstiegsaufgabe_Info_DWork.Memory_PreviousInput,
    &G6A_Einstiegsaufgabe_Informat_B.NEGATIVEEdge);

  /* End of Outputs for SubSystem: '<S8>/NEGATIVE Edge' */

  /* RelationalOperator: '<S4>/Vergleich mit Schwellwert' incorporates:
   *  Constant: '<S4>/Heuristisch ermittelter Schwellwert'
   */
  rtb_VergleichmitSchwellwert_g =
    (G6A_Einstiegsaufgabe_Informat_B.AnalogDigitalWandlungSampleti_k <=
     G6A_Einstiegsaufgabe_Informat_P.HeuristischermittelterSchwellwe);

  /* MATLAB Function: '<S4>/MATLAB Function2' incorporates:
   *  UnitDelay: '<S4>/Unit Delay3'
   *  UnitDelay: '<S4>/Unit Delay4'
   *  UnitDelay: '<S4>/Unit Delay5'
   */
  /* MATLAB Function 'Messung des absoluten Winkels -  Auswertung der Encodersignale/MATLAB Function2': '<S11>:1' */
  /* '<S11>:1:3' */
  y = 1.0;
  tmp_0 = !G6A_Einstiegsaufgabe_Info_DWork.UnitDelay3_DSTATE;
  tmp_1 = !G6A_Einstiegsaufgabe_Info_DWork.UnitDelay4_DSTATE;
  tmp = (tmp_0 && tmp_1);
  if (tmp && (!rtb_VergleichmitSchwellwert) && (!rtb_VergleichmitSchwellwert_g))
  {
    /* '<S11>:1:7' */
    y = G6A_Einstiegsaufgabe_Info_DWork.UnitDelay5_DSTATE;
  }

  if (tmp && (!rtb_VergleichmitSchwellwert) && rtb_VergleichmitSchwellwert_g) {
    /* '<S11>:1:10' */
    /* '<S11>:1:11' */
    y = 1.0;
  }

  if (tmp && rtb_VergleichmitSchwellwert && (!rtb_VergleichmitSchwellwert_g)) {
    /* '<S11>:1:14' */
    /* '<S11>:1:15' */
    y = -1.0;
  }

  tmp_0 = (tmp_0 && G6A_Einstiegsaufgabe_Info_DWork.UnitDelay4_DSTATE);
  if (tmp_0 && (!rtb_VergleichmitSchwellwert) && (!rtb_VergleichmitSchwellwert_g))
  {
    /* '<S11>:1:22' */
    /* '<S11>:1:23' */
    y = -1.0;
  }

  if (tmp_0 && (!rtb_VergleichmitSchwellwert) && rtb_VergleichmitSchwellwert_g)
  {
    /* '<S11>:1:26' */
    /* '<S11>:1:27' */
    y = G6A_Einstiegsaufgabe_Info_DWork.UnitDelay5_DSTATE;
  }

  if (tmp_0 && rtb_VergleichmitSchwellwert && rtb_VergleichmitSchwellwert_g) {
    /* '<S11>:1:34' */
    /* '<S11>:1:35' */
    y = 1.0;
  }

  tmp_0 = (G6A_Einstiegsaufgabe_Info_DWork.UnitDelay3_DSTATE && tmp_1);
  if (tmp_0 && (!rtb_VergleichmitSchwellwert) && (!rtb_VergleichmitSchwellwert_g))
  {
    /* '<S11>:1:38' */
    /* '<S11>:1:39' */
    y = 1.0;
  }

  if (tmp_0 && rtb_VergleichmitSchwellwert && (!rtb_VergleichmitSchwellwert_g))
  {
    /* '<S11>:1:46' */
    /* '<S11>:1:47' */
    y = G6A_Einstiegsaufgabe_Info_DWork.UnitDelay5_DSTATE;
  }

  if (tmp_0 && rtb_VergleichmitSchwellwert && rtb_VergleichmitSchwellwert_g) {
    /* '<S11>:1:50' */
    /* '<S11>:1:51' */
    y = -1.0;
  }

  tmp_0 = (G6A_Einstiegsaufgabe_Info_DWork.UnitDelay3_DSTATE &&
           G6A_Einstiegsaufgabe_Info_DWork.UnitDelay4_DSTATE);
  if (tmp_0 && (!rtb_VergleichmitSchwellwert) && rtb_VergleichmitSchwellwert_g)
  {
    /* '<S11>:1:58' */
    /* '<S11>:1:59' */
    y = -1.0;
  }

  if (tmp_0 && rtb_VergleichmitSchwellwert && (!rtb_VergleichmitSchwellwert_g))
  {
    /* '<S11>:1:62' */
    /* '<S11>:1:63' */
    y = 1.0;
  }

  if (tmp_0 && rtb_VergleichmitSchwellwert && rtb_VergleichmitSchwellwert_g) {
    /* '<S11>:1:66' */
    /* '<S11>:1:67' */
    y = G6A_Einstiegsaufgabe_Info_DWork.UnitDelay5_DSTATE;
  }

  if (y == 1.0) {
    /* '<S11>:1:70' */
    /* '<S11>:1:71' */
    rtb_RL = 1;
  } else {
    /* '<S11>:1:73' */
    rtb_RL = 0;
  }

  /* MATLAB Function: '<S4>/MATLAB Function1' incorporates:
   *  Logic: '<S8>/Logical Operator1'
   *  MATLAB Function: '<S4>/MATLAB Function2'
   *  Product: '<S4>/Product3'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  G6A_Einstie_MATLABFunction1((real_T)
    (G6A_Einstiegsaufgabe_Informat_B.POSITIVEEdge.RelationalOperator1 ||
     G6A_Einstiegsaufgabe_Informat_B.NEGATIVEEdge.RelationalOperator1) * y,
    G6A_Einstiegsaufgabe_Info_DWork.UnitDelay1_DSTATE,
    &G6A_Einstiegsaufgabe_Informat_B.sf_MATLABFunction1);

  /* Product: '<S4>/Product1' incorporates:
   *  Constant: '<S4>/Winkel // Flanke Polulo 34:1 6V | 0,22 Polulo 74:1 6V | 0,1 Polulo 98:1 6V | 0,076 Polulo 171:1 6V | 0,043'
   */
  rtb_Sum_p = G6A_Einstiegsaufgabe_Informat_P.WinkelFlankePolulo3416V022Polul *
    G6A_Einstiegsaufgabe_Informat_B.sf_MATLABFunction1.y;

  /* MultiPortSwitch: '<S9>/Multiport Switch' incorporates:
   *  Constant: '<S9>/Constant1'
   *  Constant: '<S9>/either edge'
   *  Constant: '<S9>/neg. edge'
   *  Constant: '<S9>/pos. edge'
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

  /* End of MultiPortSwitch: '<S9>/Multiport Switch' */

  /* Outputs for Enabled SubSystem: '<S9>/POSITIVE Edge' */
  /* Memory: '<S9>/Memory' */
  G6A_Einstiegsa_POSITIVEEdge(rtb_MultiportSwitch_idx_0,
    rtb_VergleichmitSchwellwert_g,
    G6A_Einstiegsaufgabe_Info_DWork.Memory_PreviousInput_e,
    &G6A_Einstiegsaufgabe_Informat_B.POSITIVEEdge_e);

  /* End of Outputs for SubSystem: '<S9>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S9>/NEGATIVE Edge' */
  G6A_Einstiegsa_NEGATIVEEdge(rtb_MultiportSwitch_idx_1,
    rtb_VergleichmitSchwellwert_g,
    G6A_Einstiegsaufgabe_Info_DWork.Memory_PreviousInput_e,
    &G6A_Einstiegsaufgabe_Informat_B.NEGATIVEEdge_h);

  /* End of Outputs for SubSystem: '<S9>/NEGATIVE Edge' */

  /* MATLAB Function: '<S4>/MATLAB Function3' incorporates:
   *  Logic: '<S9>/Logical Operator1'
   *  MATLAB Function: '<S4>/MATLAB Function2'
   *  Product: '<S4>/Product'
   *  UnitDelay: '<S4>/Unit Delay2'
   */
  G6A_Einstie_MATLABFunction1(y * (real_T)
    (G6A_Einstiegsaufgabe_Informat_B.POSITIVEEdge_e.RelationalOperator1 ||
     G6A_Einstiegsaufgabe_Informat_B.NEGATIVEEdge_h.RelationalOperator1),
    G6A_Einstiegsaufgabe_Info_DWork.UnitDelay2_DSTATE,
    &G6A_Einstiegsaufgabe_Informat_B.sf_MATLABFunction3);

  /* Sum: '<S4>/Sum' incorporates:
   *  Constant: '<S4>/Winkel // Flanke Polulo 34:1 6V | 0,22 Polulo 74:1 6V | 0,1 Polulo 98:1 6V | 0,076 Polulo 171:1 6V | 0,1'
   *  Product: '<S4>/Product2'
   */
  rtb_Sum_p += G6A_Einstiegsaufgabe_Informat_B.sf_MATLABFunction3.y *
    G6A_Einstiegsaufgabe_Informat_P.WinkelFlankePolulo3416V022Pol_f;

  /* RateTransition: '<Root>/Rate Transition4' */
  if (G6A_Einstiegsaufgabe_Informa_M->Timing.RateInteraction.TID0_1) {
    G6A_Einstiegsaufgabe_Informat_B.RateTransition4 = rtb_Sum_p;

    /* RateTransition: '<Root>/RT' */
    G6A_Einstiegsaufgabe_Informat_B.RT_a = rtb_RL;
  }

  /* End of RateTransition: '<Root>/Rate Transition4' */

  /* Update for Memory: '<S8>/Memory' */
  G6A_Einstiegsaufgabe_Info_DWork.Memory_PreviousInput =
    rtb_VergleichmitSchwellwert;

  /* Update for UnitDelay: '<S4>/Unit Delay3' */
  G6A_Einstiegsaufgabe_Info_DWork.UnitDelay3_DSTATE =
    rtb_VergleichmitSchwellwert;

  /* Update for UnitDelay: '<S4>/Unit Delay4' */
  G6A_Einstiegsaufgabe_Info_DWork.UnitDelay4_DSTATE =
    rtb_VergleichmitSchwellwert_g;

  /* Update for UnitDelay: '<S4>/Unit Delay5' incorporates:
   *  MATLAB Function: '<S4>/MATLAB Function2'
   */
  G6A_Einstiegsaufgabe_Info_DWork.UnitDelay5_DSTATE = y;

  /* Update for UnitDelay: '<S4>/Unit Delay1' */
  G6A_Einstiegsaufgabe_Info_DWork.UnitDelay1_DSTATE =
    G6A_Einstiegsaufgabe_Informat_B.sf_MATLABFunction1.y;

  /* Update for Memory: '<S9>/Memory' */
  G6A_Einstiegsaufgabe_Info_DWork.Memory_PreviousInput_e =
    rtb_VergleichmitSchwellwert_g;

  /* Update for UnitDelay: '<S4>/Unit Delay2' */
  G6A_Einstiegsaufgabe_Info_DWork.UnitDelay2_DSTATE =
    G6A_Einstiegsaufgabe_Informat_B.sf_MATLABFunction3.y;
}

/* Model step function for TID1 */
void G6A_Einstiegsaufgabe_Informationstechnik_step1(void) /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_y;
  int16_T n;
  real_T rtb_Verstaerkung;
  real_T rtb_Sum;

  /* If: '<Root>/If' incorporates:
   *  Delay: '<Root>/Delay One Step'
   */
  if (G6A_Einstiegsaufgabe_Info_DWork.DelayOneStep_DSTATE[0U]) {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* MATLAB Function: '<S2>/MATLAB Function' */
    /* MATLAB Function 'If Action Subsystem/MATLAB Function': '<S7>:1' */
    if (G6A_Einstiegsaufgabe_Informat_B.RT_a == 1.0) {
      /* '<S7>:1:2' */
      /* '<S7>:1:3' */
      n = 2;
    } else {
      /* '<S7>:1:5' */
      n = 1;
    }

    /* '<S7>:1:7' */
    G6A_Einstiegsaufgabe_Informat_B.y_f = n;

    /* End of MATLAB Function: '<S2>/MATLAB Function' */
    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */
  }

  /* End of If: '<Root>/If' */

  /* Sum: '<S6>/Sum' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  /* MATLAB Function 'MATLAB Function': '<S3>:1' */
  /* '<S3>:1:3' */
  rtb_Sum = (160.0 - 130.0 * rt_powd_snf(-1.0,
              G6A_Einstiegsaufgabe_Informat_B.y_f)) * 2.0 / 3.0 -
    G6A_Einstiegsaufgabe_Informat_B.RateTransition4;

  /* DeadZone: '<S6>/Dead Zone' */
  if (rtb_Sum > G6A_Einstiegsaufgabe_Informat_P.DeadZone_End) {
    rtb_Verstaerkung = rtb_Sum - G6A_Einstiegsaufgabe_Informat_P.DeadZone_End;
  } else if (rtb_Sum >= G6A_Einstiegsaufgabe_Informat_P.DeadZone_Start) {
    rtb_Verstaerkung = 0.0;
  } else {
    rtb_Verstaerkung = rtb_Sum - G6A_Einstiegsaufgabe_Informat_P.DeadZone_Start;
  }

  /* End of DeadZone: '<S6>/Dead Zone' */

  /* Gain: '<S6>/Verstaerkung' */
  rtb_Verstaerkung *= G6A_Einstiegsaufgabe_Informat_P.Verstaerkung_Gain;

  /* MATLAB Function: '<S6>/Richtung' */
  /* MATLAB Function 'P-Regler mit Regelfehler Begrenzung Initial: k = 0.1, limiit = +//- 100 Sampletime 0.01/Richtung': '<S29>:1' */
  if (rtb_Verstaerkung > 0.0) {
    /* '<S29>:1:3' */
    /* '<S29>:1:4' */
    G6A_Einstiegsaufgabe_Informat_B.y = 1.0;
  } else {
    /* '<S29>:1:6' */
    G6A_Einstiegsaufgabe_Informat_B.y = 0.0;
  }

  /* End of MATLAB Function: '<S6>/Richtung' */

  /* S-Function (c280xgpio_do): '<Root>/Drehrichtungsvorgabe f&#xFC;r einen Motor' */
  {
    if (G6A_Einstiegsaufgabe_Informat_B.y)
      GpioDataRegs.GPASET.bit.GPIO21 = 1;
    else
      GpioDataRegs.GPACLEAR.bit.GPIO21 = 1;
  }

  /* Abs: '<S6>/Abs' */
  rtb_Verstaerkung = fabs(rtb_Verstaerkung);

  /* MATLAB Function: '<S6>/Betrag' */
  /* MATLAB Function 'P-Regler mit Regelfehler Begrenzung Initial: k = 0.1, limiit = +//- 100 Sampletime 0.01/Betrag': '<S28>:1' */
  if ((0.5 < rtb_Verstaerkung) && (rtb_Verstaerkung < 60.0)) {
    /* '<S28>:1:3' */
    /* '<S28>:1:4' */
    rtb_y = 60.0;
  } else if (rtb_Verstaerkung <= 0.5) {
    /* '<S28>:1:5' */
    /* '<S28>:1:6' */
    rtb_y = 0.0;
  } else if (rtb_Verstaerkung >= 60.0) {
    /* '<S28>:1:7' */
    /* '<S28>:1:8' */
    rtb_y = 100.0;
  } else {
    /* '<S28>:1:10' */
    rtb_y = rtb_Verstaerkung;
  }

  /* End of MATLAB Function: '<S6>/Betrag' */

  /* S-Function (c280xpwm): '<Root>/PWM Vorgabe f&#xFC;r einen Motor ' */

  /*-- Update CMPB value for ePWM2 --*/
  {
    EPwm2Regs.CMPB = (uint16_T)((uint32_T)EPwm2Regs.TBPRD * rtb_y * 0.01);
  }

  /* Update for Delay: '<Root>/Delay One Step' incorporates:
   *  Constant: '<S6>/Constant'
   *  RelationalOperator: '<S6>/Equal'
   */
  G6A_Einstiegsaufgabe_Info_DWork.DelayOneStep_DSTATE[0] =
    G6A_Einstiegsaufgabe_Info_DWork.DelayOneStep_DSTATE[1];
  G6A_Einstiegsaufgabe_Info_DWork.DelayOneStep_DSTATE[1] =
    G6A_Einstiegsaufgabe_Info_DWork.DelayOneStep_DSTATE[2];
  G6A_Einstiegsaufgabe_Info_DWork.DelayOneStep_DSTATE[2] =
    G6A_Einstiegsaufgabe_Info_DWork.DelayOneStep_DSTATE[3];
  G6A_Einstiegsaufgabe_Info_DWork.DelayOneStep_DSTATE[3] =
    G6A_Einstiegsaufgabe_Info_DWork.DelayOneStep_DSTATE[4];
  G6A_Einstiegsaufgabe_Info_DWork.DelayOneStep_DSTATE[4] = (rtb_Sum ==
    G6A_Einstiegsaufgabe_Informat_P.Constant_Value_f);
}

/* Model initialize function */
void G6A_Einstiegsaufgabe_Informationstechnik_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)G6A_Einstiegsaufgabe_Informa_M, 0,
                sizeof(RT_MODEL_G6A_Einstiegsaufgabe_I));

  /* block I/O */
  (void) memset(((void *) &G6A_Einstiegsaufgabe_Informat_B), 0,
                sizeof(BlockIO_G6A_Einstiegsaufgabe_In));

  /* states (dwork) */
  (void) memset((void *)&G6A_Einstiegsaufgabe_Info_DWork, 0,
                sizeof(D_Work_G6A_Einstiegsaufgabe_Inf));

  {
    int16_T i;

    /* Start for S-Function (c280xadc): '<Root>/Analog-Digital-Wandlung Sampletime = 0.00002 s Wichtig! F&#xFC;r korrekte Winkelmessung nicht die Sampletime vergr&#xF6;&#xDF;ern Weitere Ports k&#xF6;nnen hinzugef&#xFC;gt werden (Farbsensor, Sharp-Sensoren) Wichtig! Dieser Block ist sehr Rechenintensiv' */
    if (adcInitFlag == 0) {
      InitAdc();
      adcInitFlag = 1;
    }

    config_ADC_A (1U, 16U, 0U, 0U, 0U);

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
      EPwm2Regs.TBCTR = 0x0000;        /* Clear counter*/

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

    /* InitializeConditions for Memory: '<S8>/Memory' */
    G6A_Einstiegsaufgabe_Info_DWork.Memory_PreviousInput =
      G6A_Einstiegsaufgabe_Informat_P.EdgeDetector1_ic;

    /* InitializeConditions for UnitDelay: '<S4>/Unit Delay3' */
    G6A_Einstiegsaufgabe_Info_DWork.UnitDelay3_DSTATE =
      G6A_Einstiegsaufgabe_Informat_P.UnitDelay3_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S4>/Unit Delay4' */
    G6A_Einstiegsaufgabe_Info_DWork.UnitDelay4_DSTATE =
      G6A_Einstiegsaufgabe_Informat_P.UnitDelay4_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S4>/Unit Delay5' */
    G6A_Einstiegsaufgabe_Info_DWork.UnitDelay5_DSTATE =
      G6A_Einstiegsaufgabe_Informat_P.UnitDelay5_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S4>/Unit Delay1' */
    G6A_Einstiegsaufgabe_Info_DWork.UnitDelay1_DSTATE =
      G6A_Einstiegsaufgabe_Informat_P.UnitDelay1_InitialCondition;

    /* InitializeConditions for Memory: '<S9>/Memory' */
    G6A_Einstiegsaufgabe_Info_DWork.Memory_PreviousInput_e =
      G6A_Einstiegsaufgabe_Informat_P.EdgeDetector2_ic;

    /* InitializeConditions for UnitDelay: '<S4>/Unit Delay2' */
    G6A_Einstiegsaufgabe_Info_DWork.UnitDelay2_DSTATE =
      G6A_Einstiegsaufgabe_Informat_P.UnitDelay2_InitialCondition;

    /* InitializeConditions for Delay: '<Root>/Delay One Step' */
    for (i = 0; i < 5; i++) {
      G6A_Einstiegsaufgabe_Info_DWork.DelayOneStep_DSTATE[i] =
        G6A_Einstiegsaufgabe_Informat_P.DelayOneStep_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<Root>/Delay One Step' */
  }
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
