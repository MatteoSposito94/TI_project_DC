/*
 * File: FW_control_DC_data.c
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

/* Block parameters (default storage) */
Parameters_FW_control_DC FW_control_DC_P = {
  /* Variable: PWM_CounterPeriod
   * Referenced by:
   *   '<Root>/Gain1'
   *   '<Root>/Gain5'
   */
  1125.0F,

  /* Variable: g_adc
   * Referenced by: '<Root>/Gain11'
   */
  0.008F,

  /* Variable: imax
   * Referenced by: '<Root>/Saturation4'
   */
  10.0F,

  /* Variable: kiI
   * Referenced by: '<S32>/Integral Gain'
   */
  3234.89429F,

  /* Variable: kiW
   * Referenced by: '<S80>/Integral Gain'
   */
  0.00275577535F,

  /* Variable: kpI
   * Referenced by: '<S40>/Proportional Gain'
   */
  5.29F,

  /* Variable: kpW
   * Referenced by: '<S88>/Proportional Gain'
   */
  0.000217636843F,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S1>/Constant'
   */
  33554432,

  /* Mask Parameter: PIDController4_InitialCondition
   * Referenced by: '<S83>/Integrator'
   */
  0.0F,

  /* Mask Parameter: PIDController2_InitialCondition
   * Referenced by: '<S35>/Integrator'
   */
  0.0F,

  /* Mask Parameter: PIDController2_Kb
   * Referenced by: '<S28>/Kb'
   */
  611.51123F,

  /* Mask Parameter: PIDController4_Kb
   * Referenced by: '<S76>/Kb'
   */
  12.6622648F,

  /* Mask Parameter: PIDController4_LowerSaturationL
   * Referenced by: '<S90>/Saturation'
   */
  -0.232F,

  /* Mask Parameter: PIDController2_LowerSaturationL
   * Referenced by: '<S42>/Saturation'
   */
  0.0F,

  /* Mask Parameter: PIDController4_UpperSaturationL
   * Referenced by: '<S90>/Saturation'
   */
  0.232F,

  /* Mask Parameter: PIDController2_UpperSaturationL
   * Referenced by: '<S42>/Saturation'
   */
  9.8F,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 1/(Vdc)
   * Referenced by: '<Root>/Gain2'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<Root>/Constant4'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<Root>/Delay'
   */
  0,

  /* Computed Parameter: RateTransition6_InitialConditio
   * Referenced by: '<Root>/Rate Transition6'
   */
  0.0F,

  /* Computed Parameter: RateTransition9_InitialConditio
   * Referenced by: '<Root>/Rate Transition9'
   */
  0.0F,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S83>/Integrator'
   */
  2.5E-5F,

  /* Computed Parameter: Gain12_Gain
   * Referenced by: '<Root>/Gain12'
   */
  43.103447F,

  /* Computed Parameter: Saturation4_LowerSat
   * Referenced by: '<Root>/Saturation4'
   */
  -10.0F,

  /* Computed Parameter: Integrator_gainval_n
   * Referenced by: '<S35>/Integrator'
   */
  2.5E-5F,

  /* Expression: Vdc
   * Referenced by: '<Root>/Saturation'
   */
  10.0F,

  /* Computed Parameter: Saturation_LowerSat
   * Referenced by: '<Root>/Saturation'
   */
  0.0F,

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<Root>/Constant2'
   */
  1.0F,

  /* Computed Parameter: Gain6_Gain
   * Referenced by: '<Root>/Gain6'
   */
  200.0F,

  /* Computed Parameter: Gain8_Gain
   * Referenced by: '<Root>/Gain8'
   */
  0.104719758F,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<Root>/Constant3'
   */
  2048,

  /* Computed Parameter: Gain4_Gain
   * Referenced by: '<Root>/Gain4'
   */
  25600,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<Root>/Gain3'
   */
  16384,

  /* Computed Parameter: RateTransition1_InitialConditio
   * Referenced by: '<Root>/Rate Transition1'
   */
  false
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
