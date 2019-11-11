/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TestMitKali.h
 *
 * Code generated for Simulink model 'TestMitKali'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Nov 11 17:03:40 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TestMitKali_h_
#define RTW_HEADER_TestMitKali_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef TestMitKali_COMMON_INCLUDES_
# define TestMitKali_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "DSP2833x_Gpio.h"
#include "IQmathLib.h"
#endif                                 /* TestMitKali_COMMON_INCLUDES_ */

#include "TestMitKali_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

extern void config_ePWM_GPIO (void);

/* user code (top of header file) */
#include "i2c_reset.h"

/* Block signals for system '<S6>/NEGATIVE Edge' */
typedef struct {
  boolean_T RelationalOperator1;       /* '<S11>/Relational Operator1' */
} rtB_NEGATIVEEdge_TestMitKali;

/* Block signals for system '<S6>/POSITIVE Edge' */
typedef struct {
  boolean_T RelationalOperator1;       /* '<S12>/Relational Operator1' */
} rtB_POSITIVEEdge_TestMitKali;

/* Block signals for system '<S3>/MATLAB Function1' */
typedef struct {
  real32_T y;                          /* '<S3>/MATLAB Function1' */
} rtB_MATLABFunction1_TestMitKali;

/* Block signals (default storage) */
typedef struct {
  real_T AnalogDigitalWandlungSampletime;/* '<Root>/Analog-Digital-Wandlung Sampletime = 0.00002 s Wichtig! F&#xFC;r korrekte Winkelmessung nicht die Sampletime vergr&#xF6;&#xDF;ern Weitere Ports k&#xF6;nnen hinzugef&#xFC;gt werden (Farbsensor, Sharp-Sensoren) Wichtig! Dieser Block ist sehr Rechenintensiv' */
  real_T AnalogDigitalWandlungSampleti_k;/* '<Root>/Analog-Digital-Wandlung Sampletime = 0.00002 s Wichtig! F&#xFC;r korrekte Winkelmessung nicht die Sampletime vergr&#xF6;&#xDF;ern Weitere Ports k&#xF6;nnen hinzugef&#xFC;gt werden (Farbsensor, Sharp-Sensoren) Wichtig! Dieser Block ist sehr Rechenintensiv' */
  real_T RateTransition4;              /* '<Root>/Rate Transition4' */
  real_T y;                            /* '<S5>/Richtung' */
  real_T RL;                           /* '<S3>/MATLAB Function2' */
  real_T degree_out;                   /* '<Root>/Chart' */
  real32_T DigitalInput;               /* '<Root>/Digital Input' */
  rtB_MATLABFunction1_TestMitKali sf_MATLABFunction3;/* '<S3>/MATLAB Function3' */
  rtB_MATLABFunction1_TestMitKali sf_MATLABFunction1;/* '<S3>/MATLAB Function1' */
  rtB_POSITIVEEdge_TestMitKali POSITIVEEdge_e;/* '<S7>/POSITIVE Edge' */
  rtB_NEGATIVEEdge_TestMitKali NEGATIVEEdge_h;/* '<S7>/NEGATIVE Edge' */
  rtB_POSITIVEEdge_TestMitKali POSITIVEEdge;/* '<S6>/POSITIVE Edge' */
  rtB_NEGATIVEEdge_TestMitKali NEGATIVEEdge;/* '<S6>/NEGATIVE Edge' */
} BlockIO_TestMitKali;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay5_DSTATE;            /* '<S3>/Unit Delay5' */
  real_T offset;                       /* '<Root>/Chart' */
  real32_T UnitDelay1_DSTATE;          /* '<S3>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE;          /* '<S3>/Unit Delay2' */
  uint16_T temporalCounter_i1;         /* '<Root>/Chart' */
  boolean_T UnitDelay3_DSTATE;         /* '<S3>/Unit Delay3' */
  boolean_T UnitDelay4_DSTATE;         /* '<S3>/Unit Delay4' */
  uint16_T is_active_c3_TestMitKali;   /* '<Root>/Chart' */
  uint16_T is_c3_TestMitKali;          /* '<Root>/Chart' */
  boolean_T Memory_PreviousInput;      /* '<S6>/Memory' */
  boolean_T Memory_PreviousInput_e;    /* '<S7>/Memory' */
} D_Work_TestMitKali;

/* Parameters (default storage) */
struct Parameters_TestMitKali_ {
  real_T EdgeDetector1_model;          /* Mask Parameter: EdgeDetector1_model
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T EdgeDetector2_model;          /* Mask Parameter: EdgeDetector2_model
                                        * Referenced by: '<S7>/Constant1'
                                        */
  boolean_T EdgeDetector1_ic;          /* Mask Parameter: EdgeDetector1_ic
                                        * Referenced by: '<S6>/Memory'
                                        */
  boolean_T EdgeDetector2_ic;          /* Mask Parameter: EdgeDetector2_ic
                                        * Referenced by: '<S7>/Memory'
                                        */
  real_T Constant_Value;               /* Expression: 3.3
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T eitheredge_Value[2];          /* Expression: [1 1]
                                        * Referenced by: '<S6>/either edge'
                                        */
  real_T negedge_Value[2];             /* Expression: [0 1]
                                        * Referenced by: '<S6>/neg. edge'
                                        */
  real_T posedge_Value[2];             /* Expression: [1 0]
                                        * Referenced by: '<S6>/pos. edge'
                                        */
  real_T eitheredge_Value_a[2];        /* Expression: [1 1]
                                        * Referenced by: '<S7>/either edge'
                                        */
  real_T negedge_Value_b[2];           /* Expression: [0 1]
                                        * Referenced by: '<S7>/neg. edge'
                                        */
  real_T posedge_Value_e[2];           /* Expression: [1 0]
                                        * Referenced by: '<S7>/pos. edge'
                                        */
  real_T WinkelFlankePolulo3416V022Polul;/* Expression: 0.076
                                          * Referenced by: '<S3>/Winkel // Flanke Polulo 34:1 6V | 0,22 Polulo 74:1 6V | 0,1 Polulo 98:1 6V | 0,076 Polulo 171:1 6V | 0,043'
                                          */
  real_T Constant_Value_i;             /* Expression: 2000
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T HeuristischermittelterSchwellwe;/* Expression: 2000
                                          * Referenced by: '<S3>/Heuristisch ermittelter Schwellwert'
                                          */
  real_T UnitDelay5_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S3>/Unit Delay5'
                                        */
  real_T WinkelFlankePolulo3416V022Pol_f;/* Expression: 0.076
                                          * Referenced by: '<S3>/Winkel // Flanke Polulo 34:1 6V | 0,22 Polulo 74:1 6V | 0,1 Polulo 98:1 6V | 0,076 Polulo 171:1 6V | 0,1'
                                          */
  real_T Gain_Gain;                    /* Expression: 1/1.05
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T DeadZone_Start;               /* Expression: -5
                                        * Referenced by: '<S5>/Dead Zone'
                                        */
  real_T DeadZone_End;                 /* Expression: 5
                                        * Referenced by: '<S5>/Dead Zone'
                                        */
  real_T Verstaerkung_Gain;            /* Expression: 0.5
                                        * Referenced by: '<S5>/Verstaerkung'
                                        */
  real32_T UnitDelay1_InitialCondition;/* Computed Parameter: UnitDelay1_InitialCondition
                                        * Referenced by: '<S3>/Unit Delay1'
                                        */
  real32_T UnitDelay2_InitialCondition;/* Computed Parameter: UnitDelay2_InitialCondition
                                        * Referenced by: '<S3>/Unit Delay2'
                                        */
  real32_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<Root>/Switch'
                                        */
  boolean_T UnitDelay3_InitialCondition;/* Computed Parameter: UnitDelay3_InitialCondition
                                         * Referenced by: '<S3>/Unit Delay3'
                                         */
  boolean_T UnitDelay4_InitialCondition;/* Computed Parameter: UnitDelay4_InitialCondition
                                         * Referenced by: '<S3>/Unit Delay4'
                                         */
};

/* Real-time Model Data Structure */
struct tag_RTM_TestMitKali {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;
  } Timing;
};

/* Block parameters (default storage) */
extern Parameters_TestMitKali TestMitKali_P;

/* Block signals (default storage) */
extern BlockIO_TestMitKali TestMitKali_B;

/* Block states (default storage) */
extern D_Work_TestMitKali TestMitKali_DWork;

/* External function called from main */
extern void TestMitKali_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void TestMitKali_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void TestMitKali_initialize(void);
extern void TestMitKali_step0(void);
extern void TestMitKali_step1(void);
extern void TestMitKali_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TestMitKali *const TestMitKali_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TestMitKali'
 * '<S1>'   : 'TestMitKali/ADC - Messwerte - Vorverarbeitung (Kennlinien-Steigung und Offset-Kompensation) U_digital = (ADC_in - Offset) * 3.546 V // 4096 mit  U_digital_max = 3.546 V U_digital_min = 0 V'
 * '<S2>'   : 'TestMitKali/Chart'
 * '<S3>'   : 'TestMitKali/Messung des absoluten Winkels -  Auswertung der Encodersignale'
 * '<S4>'   : 'TestMitKali/Modul Positionswerte Sampletime = 0.01 s'
 * '<S5>'   : 'TestMitKali/P-Regler mit Regelfehler Begrenzung Initial: k = 0.1, limiit = +//- 100 Sampletime 0.01'
 * '<S6>'   : 'TestMitKali/Messung des absoluten Winkels -  Auswertung der Encodersignale/Edge Detector1'
 * '<S7>'   : 'TestMitKali/Messung des absoluten Winkels -  Auswertung der Encodersignale/Edge Detector2'
 * '<S8>'   : 'TestMitKali/Messung des absoluten Winkels -  Auswertung der Encodersignale/MATLAB Function1'
 * '<S9>'   : 'TestMitKali/Messung des absoluten Winkels -  Auswertung der Encodersignale/MATLAB Function2'
 * '<S10>'  : 'TestMitKali/Messung des absoluten Winkels -  Auswertung der Encodersignale/MATLAB Function3'
 * '<S11>'  : 'TestMitKali/Messung des absoluten Winkels -  Auswertung der Encodersignale/Edge Detector1/NEGATIVE Edge'
 * '<S12>'  : 'TestMitKali/Messung des absoluten Winkels -  Auswertung der Encodersignale/Edge Detector1/POSITIVE Edge'
 * '<S13>'  : 'TestMitKali/Messung des absoluten Winkels -  Auswertung der Encodersignale/Edge Detector2/NEGATIVE Edge'
 * '<S14>'  : 'TestMitKali/Messung des absoluten Winkels -  Auswertung der Encodersignale/Edge Detector2/POSITIVE Edge'
 * '<S15>'  : 'TestMitKali/Modul Positionswerte Sampletime = 0.01 s/Chart1'
 * '<S16>'  : 'TestMitKali/Modul Positionswerte Sampletime = 0.01 s/Chart2'
 * '<S17>'  : 'TestMitKali/Modul Positionswerte Sampletime = 0.01 s/Chart4'
 * '<S18>'  : 'TestMitKali/Modul Positionswerte Sampletime = 0.01 s/Chart6'
 * '<S19>'  : 'TestMitKali/Modul Positionswerte Sampletime = 0.01 s/Chart8'
 * '<S20>'  : 'TestMitKali/Modul Positionswerte Sampletime = 0.01 s/I2C Reset (behebt Stabilit&#xE4;tsprobleme der I2C-Verbindung)'
 * '<S21>'  : 'TestMitKali/Modul Positionswerte Sampletime = 0.01 s/Triggered Subsystem'
 * '<S22>'  : 'TestMitKali/Modul Positionswerte Sampletime = 0.01 s/I2C Reset (behebt Stabilit&#xE4;tsprobleme der I2C-Verbindung)/I2C Reinitialisierung'
 * '<S23>'  : 'TestMitKali/Modul Positionswerte Sampletime = 0.01 s/I2C Reset (behebt Stabilit&#xE4;tsprobleme der I2C-Verbindung)/I2C Reset'
 * '<S24>'  : 'TestMitKali/Modul Positionswerte Sampletime = 0.01 s/I2C Reset (behebt Stabilit&#xE4;tsprobleme der I2C-Verbindung)/I2C Reinitialisierung/I2C Reinitialisierung'
 * '<S25>'  : 'TestMitKali/Modul Positionswerte Sampletime = 0.01 s/I2C Reset (behebt Stabilit&#xE4;tsprobleme der I2C-Verbindung)/I2C Reset/I2C Reset'
 * '<S26>'  : 'TestMitKali/P-Regler mit Regelfehler Begrenzung Initial: k = 0.1, limiit = +//- 100 Sampletime 0.01/Betrag'
 * '<S27>'  : 'TestMitKali/P-Regler mit Regelfehler Begrenzung Initial: k = 0.1, limiit = +//- 100 Sampletime 0.01/Richtung'
 */
#endif                                 /* RTW_HEADER_TestMitKali_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
