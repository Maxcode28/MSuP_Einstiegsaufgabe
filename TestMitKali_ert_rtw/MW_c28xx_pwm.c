#include "c2000BoardSupport.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "DSP2833x_GlobalPrototypes.h"
#include "rtwtypes.h"
#include "TestMitKali.h"
#include "TestMitKali_private.h"

void config_ePWM_GPIO (void)
{
  EALLOW;

  /*-- Configure pin assignments for ePWM2 --*/
  GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;  /* Configure GPIOGPIO3 as EPWM2B*/

  /*--- Configure pin assignments for TZn ---*/
  EDIS;
}
