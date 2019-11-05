/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: G6A_Einstiegsaufgabe_Informationstechnik.h
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

#ifndef RTW_HEADER_G6A_Einstiegsaufgabe_Informationstechnik_h_
#define RTW_HEADER_G6A_Einstiegsaufgabe_Informationstechnik_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef G6A_Einstiegsaufgabe_Informationstechnik_COMMON_INCLUDES_
# define G6A_Einstiegsaufgabe_Informationstechnik_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "DSP2833x_Gpio.h"
#include "IQmathLib.h"
#endif                                 /* G6A_Einstiegsaufgabe_Informationstechnik_COMMON_INCLUDES_ */

#include "G6A_Einstiegsaufgabe_Informationstechnik_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

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

#define G6A_Einstiegsaufgabe_Informationstechnik_M (G6A_Einstiegsaufgabe_Informa_M)

extern void config_ePWM_GPIO (void);

/* user code (top of header file) */
#include "i2c_reset.h"

/* Block signals for system '<S8>/NEGATIVE Edge' */
typedef struct {
  boolean_T RelationalOperator1;       /* '<S13>/Relational Operator1' */
} rtB_NEGATIVEEdge_G6A_Einstiegsa;

/* Block signals for system '<S8>/POSITIVE Edge' */
typedef struct {
  boolean_T RelationalOperator1;       /* '<S14>/Relational Operator1' */
} rtB_POSITIVEEdge_G6A_Einstiegsa;

/* Block signals for system '<S4>/MATLAB Function1' */
typedef struct {
  real32_T y;                          /* '<S4>/MATLAB Function1' */
} rtB_MATLABFunction1_G6A_Einstie;

/* Block signals (default storage) */
typedef struct {
  real_T AnalogDigitalWandlungSampletime;/* '<Root>/Analog-Digital-Wandlung Sampletime = 0.00002 s Wichtig! F&#xFC;r korrekte Winkelmessung nicht die Sampletime vergr&#xF6;&#xDF;ern Weitere Ports k&#xF6;nnen hinzugef&#xFC;gt werden (Farbsensor, Sharp-Sensoren) Wichtig! Dieser Block ist sehr Rechenintensiv' */
  real_T AnalogDigitalWandlungSampleti_k;/* '<Root>/Analog-Digital-Wandlung Sampletime = 0.00002 s Wichtig! F&#xFC;r korrekte Winkelmessung nicht die Sampletime vergr&#xF6;&#xDF;ern Weitere Ports k&#xF6;nnen hinzugef&#xFC;gt werden (Farbsensor, Sharp-Sensoren) Wichtig! Dieser Block ist sehr Rechenintensiv' */
  real_T RateTransition4;              /* '<Root>/Rate Transition4' */
  real_T RT_a;                         /* '<Root>/RT' */
  real_T y;                            /* '<S6>/Richtung' */
  real_T y_f;                          /* '<S2>/MATLAB Function' */
  rtB_MATLABFunction1_G6A_Einstie sf_MATLABFunction3;/* '<S4>/MATLAB Function3' */
  rtB_MATLABFunction1_G6A_Einstie sf_MATLABFunction1;/* '<S4>/MATLAB Function1' */
  rtB_POSITIVEEdge_G6A_Einstiegsa POSITIVEEdge_e;/* '<S9>/POSITIVE Edge' */
  rtB_NEGATIVEEdge_G6A_Einstiegsa NEGATIVEEdge_h;/* '<S9>/NEGATIVE Edge' */
  rtB_POSITIVEEdge_G6A_Einstiegsa POSITIVEEdge;/* '<S8>/POSITIVE Edge' */
  rtB_NEGATIVEEdge_G6A_Einstiegsa NEGATIVEEdge;/* '<S8>/NEGATIVE Edge' */
} BlockIO_G6A_Einstiegsaufgabe_In;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay5_DSTATE;            /* '<S4>/Unit Delay5' */
  real32_T UnitDelay1_DSTATE;          /* '<S4>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE;          /* '<S4>/Unit Delay2' */
  boolean_T UnitDelay3_DSTATE;         /* '<S4>/Unit Delay3' */
  boolean_T UnitDelay4_DSTATE;         /* '<S4>/Unit Delay4' */
  boolean_T DelayOneStep_DSTATE[5];    /* '<Root>/Delay One Step' */
  boolean_T Memory_PreviousInput;      /* '<S8>/Memory' */
  boolean_T Memory_PreviousInput_e;    /* '<S9>/Memory' */
} D_Work_G6A_Einstiegsaufgabe_Inf;

/* Parameters (default storage) */
struct Parameters_G6A_Einstiegsaufgabe_ {
  real_T EdgeDetector1_model;          /* Mask Parameter: EdgeDetector1_model
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T EdgeDetector2_model;          /* Mask Parameter: EdgeDetector2_model
                                        * Referenced by: '<S9>/Constant1'
                                        */
  boolean_T EdgeDetector1_ic;          /* Mask Parameter: EdgeDetector1_ic
                                        * Referenced by: '<S8>/Memory'
                                        */
  boolean_T EdgeDetector2_ic;          /* Mask Parameter: EdgeDetector2_ic
                                        * Referenced by: '<S9>/Memory'
                                        */
  real_T eitheredge_Value[2];          /* Expression: [1 1]
                                        * Referenced by: '<S8>/either edge'
                                        */
  real_T negedge_Value[2];             /* Expression: [0 1]
                                        * Referenced by: '<S8>/neg. edge'
                                        */
  real_T posedge_Value[2];             /* Expression: [1 0]
                                        * Referenced by: '<S8>/pos. edge'
                                        */
  real_T eitheredge_Value_a[2];        /* Expression: [1 1]
                                        * Referenced by: '<S9>/either edge'
                                        */
  real_T negedge_Value_b[2];           /* Expression: [0 1]
                                        * Referenced by: '<S9>/neg. edge'
                                        */
  real_T posedge_Value_e[2];           /* Expression: [1 0]
                                        * Referenced by: '<S9>/pos. edge'
                                        */
  real_T WinkelFlankePolulo3416V022Polul;/* Expression: 0.076
                                          * Referenced by: '<S4>/Winkel // Flanke Polulo 34:1 6V | 0,22 Polulo 74:1 6V | 0,1 Polulo 98:1 6V | 0,076 Polulo 171:1 6V | 0,043'
                                          */
  real_T Constant_Value;               /* Expression: 2000
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T HeuristischermittelterSchwellwe;/* Expression: 2000
                                          * Referenced by: '<S4>/Heuristisch ermittelter Schwellwert'
                                          */
  real_T UnitDelay5_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S4>/Unit Delay5'
                                        */
  real_T WinkelFlankePolulo3416V022Pol_f;/* Expression: 0.076
                                          * Referenced by: '<S4>/Winkel // Flanke Polulo 34:1 6V | 0,22 Polulo 74:1 6V | 0,1 Polulo 98:1 6V | 0,076 Polulo 171:1 6V | 0,1'
                                          */
  real_T DeadZone_Start;               /* Expression: -100
                                        * Referenced by: '<S6>/Dead Zone'
                                        */
  real_T DeadZone_End;                 /* Expression: 100
                                        * Referenced by: '<S6>/Dead Zone'
                                        */
  real_T Verstaerkung_Gain;            /* Expression: 0.1
                                        * Referenced by: '<S6>/Verstaerkung'
                                        */
  real_T Constant_Value_f;             /* Expression: 0
                                        * Referenced by: '<S6>/Constant'
                                        */
  real32_T UnitDelay1_InitialCondition;/* Computed Parameter: UnitDelay1_InitialCondition
                                        * Referenced by: '<S4>/Unit Delay1'
                                        */
  real32_T UnitDelay2_InitialCondition;/* Computed Parameter: UnitDelay2_InitialCondition
                                        * Referenced by: '<S4>/Unit Delay2'
                                        */
  uint16_T DelayOneStep_DelayLength;   /* Computed Parameter: DelayOneStep_DelayLength
                                        * Referenced by: '<Root>/Delay One Step'
                                        */
  boolean_T UnitDelay3_InitialCondition;/* Computed Parameter: UnitDelay3_InitialCondition
                                         * Referenced by: '<S4>/Unit Delay3'
                                         */
  boolean_T UnitDelay4_InitialCondition;/* Computed Parameter: UnitDelay4_InitialCondition
                                         * Referenced by: '<S4>/Unit Delay4'
                                         */
  boolean_T DelayOneStep_InitialCondition;/* Computed Parameter: DelayOneStep_InitialCondition
                                           * Referenced by: '<Root>/Delay One Step'
                                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_G6A_Einstiegsaufgabe_In {
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
extern Parameters_G6A_Einstiegsaufgabe G6A_Einstiegsaufgabe_Informat_P;

/* Block signals (default storage) */
extern BlockIO_G6A_Einstiegsaufgabe_In G6A_Einstiegsaufgabe_Informat_B;

/* Block states (default storage) */
extern D_Work_G6A_Einstiegsaufgabe_Inf G6A_Einstiegsaufgabe_Info_DWork;

/* External function called from main */
extern void G6A_Einstiegsaufgabe_Informationstechnik_SetEventsForThisBaseStep
  (boolean_T *eventFlags);

/* Model entry point functions */
extern void G6A_Einstiegsaufgabe_Informationstechnik_SetEventsForThisBaseStep
  (boolean_T *eventFlags);
extern void G6A_Einstiegsaufgabe_Informationstechnik_initialize(void);
extern void G6A_Einstiegsaufgabe_Informationstechnik_step0(void);
extern void G6A_Einstiegsaufgabe_Informationstechnik_step1(void);
extern void G6A_Einstiegsaufgabe_Informationstechnik_terminate(void);

/* Real-time Model object */
extern RT_MODEL_G6A_Einstiegsaufgabe_I *const G6A_Einstiegsaufgabe_Informa_M;

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
 * '<Root>' : 'G6A_Einstiegsaufgabe_Informationstechnik'
 * '<S1>'   : 'G6A_Einstiegsaufgabe_Informationstechnik/ADC - Messwerte - Vorverarbeitung (Kennlinien-Steigung und Offset-Kompensation) U_digital = (ADC_in - Offset) * 3.546 V // 4096 mit  U_digital_max = 3.546 V U_digital_min = 0 V'
 * '<S2>'   : 'G6A_Einstiegsaufgabe_Informationstechnik/If Action Subsystem'
 * '<S3>'   : 'G6A_Einstiegsaufgabe_Informationstechnik/MATLAB Function'
 * '<S4>'   : 'G6A_Einstiegsaufgabe_Informationstechnik/Messung des absoluten Winkels -  Auswertung der Encodersignale'
 * '<S5>'   : 'G6A_Einstiegsaufgabe_Informationstechnik/Modul Positionswerte Sampletime = 0.01 s'
 * '<S6>'   : 'G6A_Einstiegsaufgabe_Informationstechnik/P-Regler mit Regelfehler Begrenzung Initial: k = 0.1, limiit = +//- 100 Sampletime 0.01'
 * '<S7>'   : 'G6A_Einstiegsaufgabe_Informationstechnik/If Action Subsystem/MATLAB Function'
 * '<S8>'   : 'G6A_Einstiegsaufgabe_Informationstechnik/Messung des absoluten Winkels -  Auswertung der Encodersignale/Edge Detector1'
 * '<S9>'   : 'G6A_Einstiegsaufgabe_Informationstechnik/Messung des absoluten Winkels -  Auswertung der Encodersignale/Edge Detector2'
 * '<S10>'  : 'G6A_Einstiegsaufgabe_Informationstechnik/Messung des absoluten Winkels -  Auswertung der Encodersignale/MATLAB Function1'
 * '<S11>'  : 'G6A_Einstiegsaufgabe_Informationstechnik/Messung des absoluten Winkels -  Auswertung der Encodersignale/MATLAB Function2'
 * '<S12>'  : 'G6A_Einstiegsaufgabe_Informationstechnik/Messung des absoluten Winkels -  Auswertung der Encodersignale/MATLAB Function3'
 * '<S13>'  : 'G6A_Einstiegsaufgabe_Informationstechnik/Messung des absoluten Winkels -  Auswertung der Encodersignale/Edge Detector1/NEGATIVE Edge'
 * '<S14>'  : 'G6A_Einstiegsaufgabe_Informationstechnik/Messung des absoluten Winkels -  Auswertung der Encodersignale/Edge Detector1/POSITIVE Edge'
 * '<S15>'  : 'G6A_Einstiegsaufgabe_Informationstechnik/Messung des absoluten Winkels -  Auswertung der Encodersignale/Edge Detector2/NEGATIVE Edge'
 * '<S16>'  : 'G6A_Einstiegsaufgabe_Informationstechnik/Messung des absoluten Winkels -  Auswertung der Encodersignale/Edge Detector2/POSITIVE Edge'
 * '<S17>'  : 'G6A_Einstiegsaufgabe_Informationstechnik/Modul Positionswerte Sampletime = 0.01 s/Chart1'
 * '<S18>'  : 'G6A_Einstiegsaufgabe_Informationstechnik/Modul Positionswerte Sampletime = 0.01 s/Chart2'
 * '<S19>'  : 'G6A_Einstiegsaufgabe_Informationstechnik/Modul Positionswerte Sampletime = 0.01 s/Chart4'
 * '<S20>'  : 'G6A_Einstiegsaufgabe_Informationstechnik/Modul Positionswerte Sampletime = 0.01 s/Chart6'
 * '<S21>'  : 'G6A_Einstiegsaufgabe_Informationstechnik/Modul Positionswerte Sampletime = 0.01 s/Chart8'
 * '<S22>'  : 'G6A_Einstiegsaufgabe_Informationstechnik/Modul Positionswerte Sampletime = 0.01 s/I2C Reset (behebt Stabilit&#xE4;tsprobleme der I2C-Verbindung)'
 * '<S23>'  : 'G6A_Einstiegsaufgabe_Informationstechnik/Modul Positionswerte Sampletime = 0.01 s/Triggered Subsystem'
 * '<S24>'  : 'G6A_Einstiegsaufgabe_Informationstechnik/Modul Positionswerte Sampletime = 0.01 s/I2C Reset (behebt Stabilit&#xE4;tsprobleme der I2C-Verbindung)/I2C Reinitialisierung'
 * '<S25>'  : 'G6A_Einstiegsaufgabe_Informationstechnik/Modul Positionswerte Sampletime = 0.01 s/I2C Reset (behebt Stabilit&#xE4;tsprobleme der I2C-Verbindung)/I2C Reset'
 * '<S26>'  : 'G6A_Einstiegsaufgabe_Informationstechnik/Modul Positionswerte Sampletime = 0.01 s/I2C Reset (behebt Stabilit&#xE4;tsprobleme der I2C-Verbindung)/I2C Reinitialisierung/I2C Reinitialisierung'
 * '<S27>'  : 'G6A_Einstiegsaufgabe_Informationstechnik/Modul Positionswerte Sampletime = 0.01 s/I2C Reset (behebt Stabilit&#xE4;tsprobleme der I2C-Verbindung)/I2C Reset/I2C Reset'
 * '<S28>'  : 'G6A_Einstiegsaufgabe_Informationstechnik/P-Regler mit Regelfehler Begrenzung Initial: k = 0.1, limiit = +//- 100 Sampletime 0.01/Betrag'
 * '<S29>'  : 'G6A_Einstiegsaufgabe_Informationstechnik/P-Regler mit Regelfehler Begrenzung Initial: k = 0.1, limiit = +//- 100 Sampletime 0.01/Richtung'
 */
#endif                                 /* RTW_HEADER_G6A_Einstiegsaufgabe_Informationstechnik_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
