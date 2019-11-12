/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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
#include "rtwtypes.h"

volatile int IsrOverrun = 0;
boolean_T isRateRunning[3] = { 0, 0, 0 };

boolean_T need2runFlags[3] = { 0, 0, 0 };

void rt_OneStep(void)
{
  boolean_T eventFlags[3];
  int_T i;

  /* Check base rate for overrun */
  if (isRateRunning[0]++) {
    IsrOverrun = 1;
    isRateRunning[0]--;                /* allow future iterations to succeed*/
    return;
  }

  /*
   * For a bare-board target (i.e., no operating system), the rates
   * that execute this base step are buffered locally to allow for
   * overlapping preemption.  The generated code includes function
   * writeCodeInfoFcn() which sets the rates
   * that need to run this time step.  The return values are 1 and 0
   * for true and false, respectively.
   */
  G6A_Einstiegsaufgabe_Informationstechnik_SetEventsForThisBaseStep(eventFlags);
  enableTimer0Interrupt();
  G6A_Einstiegsaufgabe_Informationstechnik_step0();

  /* Get model outputs here */
  disableTimer0Interrupt();
  isRateRunning[0]--;
  for (i = 1; i < 3; i++) {
    if (eventFlags[i]) {
      if (need2runFlags[i]++) {
        IsrOverrun = 1;
        need2runFlags[i]--;            /* allow future iterations to succeed*/
        break;
      }
    }
  }

  for (i = 1; i < 3; i++) {
    if (isRateRunning[i]) {
      /* Yield to higher priority*/
      return;
    }

    if (need2runFlags[i]) {
      isRateRunning[i]++;
      enableTimer0Interrupt();

      /* Step the model for subrate "i" */
      switch (i)
      {
       case 1 :
        G6A_Einstiegsaufgabe_Informationstechnik_step1();

        /* Get model outputs here */
        break;

       case 2 :
        G6A_Einstiegsaufgabe_Informationstechnik_step2();

        /* Get model outputs here */
        break;

       default :
        break;
      }

      disableTimer0Interrupt();
      need2runFlags[i]--;
      isRateRunning[i]--;
    }
  }
}

volatile boolean_T stopRequested = false;
int main(void)
{
  volatile boolean_T runModel = true;
  float modelBaseRate = 2.0E-5;
  float systemClock = 150;
  c2000_flash_init();
  init_board();

#ifdef MW_EXEC_PROFILER_ON

  config_profilerTimer();

#endif

  ;
  rtmSetErrorStatus(G6A_Einstiegsaufgabe_Informa_M, 0);
  G6A_Einstiegsaufgabe_Informationstechnik_initialize();
  configureTimer0(modelBaseRate, systemClock);
  runModel =
    rtmGetErrorStatus(G6A_Einstiegsaufgabe_Informa_M) == (NULL);
  enableTimer0Interrupt();
  globalInterruptEnable();
  while (runModel) {
    stopRequested = !(
                      rtmGetErrorStatus(G6A_Einstiegsaufgabe_Informa_M) == (NULL));
    runModel = !(stopRequested);
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  G6A_Einstiegsaufgabe_Informationstechnik_terminate();
  globalInterruptDisable();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
