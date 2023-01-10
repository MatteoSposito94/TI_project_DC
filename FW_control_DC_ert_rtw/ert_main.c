/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'FW_control_DC'.
 *
 * Model version                  : 9.36
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Dec 23 12:16:43 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FW_control_DC.h"
#include "rtwtypes.h"
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  enableTimer0Interrupt();
  FW_control_DC_step();

  /* Get model outputs here */
  disableTimer0Interrupt();
  OverrunFlag--;
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 1.25E-5;
  float systemClock = 90;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;
  c2000_flash_init();
  init_board();

#if defined(MW_EXEC_PROFILER_ON) || (defined(MW_EXTMODE_RUNNING) && !defined(XCP_TIMESTAMP_BASED_ON_SIMULATION_TIME))

  hardwareTimer1Init();

#endif

  ;
  bootloaderInit();
  rtmSetErrorStatus(FW_control_DC_M, 0);
  FW_control_DC_initialize();
  globalInterruptDisable();
  configureTimer0(modelBaseRate, systemClock);
  runModel = rtmGetErrorStatus(FW_control_DC_M) == (NULL);
  enableTimer0Interrupt();
  config_ePWM_TBSync();
  globalInterruptEnable();
  while (runModel) {
    stopRequested = !(rtmGetErrorStatus(FW_control_DC_M) == (NULL));
  }

  /* Terminate model */
  FW_control_DC_terminate();
  globalInterruptDisable();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
