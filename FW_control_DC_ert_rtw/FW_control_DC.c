/*
 * File: FW_control_DC.c
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
#include <math.h>
#include "rtwtypes.h"
#include "FW_control_DC_private.h"
#include <string.h>

/* Block signals (default storage) */
BlockIO_FW_control_DC FW_control_DC_B;

/* Block states (default storage) */
D_Work_FW_control_DC FW_control_DC_DWork;

/* Real-time model */
static RT_MODEL_FW_control_DC FW_control_DC_M_;
RT_MODEL_FW_control_DC *const FW_control_DC_M = &FW_control_DC_M_;
static void rate_scheduler(void);

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcInitFlag = 0;

#endif

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
#pragma CODE_SECTION (rate_scheduler, "ramfuncs")

static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (FW_control_DC_M->Timing.TaskCounters.TID[1])++;
  if ((FW_control_DC_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [2.5E-5s, 0.0s] */
    FW_control_DC_M->Timing.TaskCounters.TID[1] = 0;
  }

  (FW_control_DC_M->Timing.TaskCounters.TID[2])++;
  if ((FW_control_DC_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.000125s, 0.0s] */
    FW_control_DC_M->Timing.TaskCounters.TID[2] = 0;
  }

  (FW_control_DC_M->Timing.TaskCounters.TID[3])++;
  if ((FW_control_DC_M->Timing.TaskCounters.TID[3]) > 79) {/* Sample time: [0.001s, 0.0s] */
    FW_control_DC_M->Timing.TaskCounters.TID[3] = 0;
  }
}

/* Model step function */
#pragma CODE_SECTION (FW_control_DC_step, "ramfuncs")

void FW_control_DC_step(void)
{
  real32_T u0;
  real32_T u1;
  real32_T u2;

  /* RateTransition: '<Root>/Rate Transition6' */
  if (FW_control_DC_M->Timing.TaskCounters.TID[1] == 0) {
    /* RateTransition: '<Root>/Rate Transition6' */
    FW_control_DC_B.RateTransition6 =
      FW_control_DC_DWork.RateTransition6_Buffer[FW_control_DC_DWork.RateTransition6_ActiveBufIdx];

    /* RateTransition: '<Root>/Rate Transition9' */
    FW_control_DC_B.RateTransition9 =
      FW_control_DC_DWork.RateTransition9_Buffer[FW_control_DC_DWork.RateTransition9_ActiveBufIdx];

    /* Sum: '<Root>/Add7' */
    FW_control_DC_B.Add7 = FW_control_DC_B.RateTransition6 -
      FW_control_DC_B.RateTransition9;

    /* Gain: '<S88>/Proportional Gain' */
    FW_control_DC_B.ProportionalGain = FW_control_DC_P.kpW *
      FW_control_DC_B.Add7;

    /* RateTransition: '<Root>/Rate Transition1' */
    FW_control_DC_B.en = FW_control_DC_DWork.RateTransition1_Buffer0;

    /* DiscreteIntegrator: '<S83>/Integrator' */
    if (FW_control_DC_B.en && (FW_control_DC_DWork.Integrator_PrevResetState <=
         0)) {
      FW_control_DC_DWork.Integrator_DSTATE =
        FW_control_DC_P.PIDController4_InitialCondition;
    }

    /* DiscreteIntegrator: '<S83>/Integrator' */
    FW_control_DC_B.Integrator = FW_control_DC_DWork.Integrator_DSTATE;

    /* Sum: '<S92>/Sum' */
    FW_control_DC_B.Sum = FW_control_DC_B.ProportionalGain +
      FW_control_DC_B.Integrator;

    /* Saturate: '<S90>/Saturation' */
    u0 = FW_control_DC_B.Sum;
    u1 = FW_control_DC_P.PIDController4_LowerSaturationL;
    u2 = FW_control_DC_P.PIDController4_UpperSaturationL;
    if (u0 > u2) {
      /* Saturate: '<S90>/Saturation' */
      FW_control_DC_B.Saturation = u2;
    } else if (u0 < u1) {
      /* Saturate: '<S90>/Saturation' */
      FW_control_DC_B.Saturation = u1;
    } else {
      /* Saturate: '<S90>/Saturation' */
      FW_control_DC_B.Saturation = u0;
    }

    /* End of Saturate: '<S90>/Saturation' */

    /* Gain: '<Root>/Gain12' */
    FW_control_DC_B.i = FW_control_DC_P.Gain12_Gain * FW_control_DC_B.Saturation;

    /* Saturate: '<Root>/Saturation4' */
    u0 = FW_control_DC_B.i;
    u1 = FW_control_DC_P.Saturation4_LowerSat;
    u2 = FW_control_DC_P.imax;
    if (u0 > u2) {
      /* Saturate: '<Root>/Saturation4' */
      FW_control_DC_B.Saturation4 = u2;
    } else if (u0 < u1) {
      /* Saturate: '<Root>/Saturation4' */
      FW_control_DC_B.Saturation4 = u1;
    } else {
      /* Saturate: '<Root>/Saturation4' */
      FW_control_DC_B.Saturation4 = u0;
    }

    /* End of Saturate: '<Root>/Saturation4' */
  }

  /* End of RateTransition: '<Root>/Rate Transition6' */
  if (FW_control_DC_M->Timing.TaskCounters.TID[3] == 0) {
    /* S-Function (c2802xadc): '<Root>/shunt A' */
    {
      /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
      /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
      FW_control_DC_B.shuntA = (AdcResult.ADCRESULT0);
    }

    /* DataTypeConversion: '<Root>/Data Type Conversion' */
    FW_control_DC_B.DataTypeConversion = (int16_T)FW_control_DC_B.shuntA;
  }

  if (FW_control_DC_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<Root>/Add4' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    FW_control_DC_B.Add4 = FW_control_DC_B.DataTypeConversion -
      FW_control_DC_P.Constant3_Value;

    /* DataTypeConversion: '<Root>/Data Type Conversion19' */
    FW_control_DC_B.DataTypeConversion19 = FW_control_DC_B.Add4;

    /* Gain: '<Root>/Gain11' */
    FW_control_DC_B.Gain11 = FW_control_DC_P.g_adc *
      FW_control_DC_B.DataTypeConversion19;

    /* Sum: '<Root>/Add' */
    FW_control_DC_B.Add = FW_control_DC_B.Saturation4 - FW_control_DC_B.Gain11;

    /* Gain: '<S40>/Proportional Gain' */
    FW_control_DC_B.ProportionalGain_n = FW_control_DC_P.kpI *
      FW_control_DC_B.Add;

    /* DiscreteIntegrator: '<S35>/Integrator' */
    if (FW_control_DC_B.en && (FW_control_DC_DWork.Integrator_PrevResetState_c <=
         0)) {
      FW_control_DC_DWork.Integrator_DSTATE_k =
        FW_control_DC_P.PIDController2_InitialCondition;
    }

    /* DiscreteIntegrator: '<S35>/Integrator' */
    FW_control_DC_B.Integrator_a = FW_control_DC_DWork.Integrator_DSTATE_k;

    /* Sum: '<S44>/Sum' */
    FW_control_DC_B.Sum_k = FW_control_DC_B.ProportionalGain_n +
      FW_control_DC_B.Integrator_a;

    /* Saturate: '<S42>/Saturation' */
    u0 = FW_control_DC_B.Sum_k;
    u1 = FW_control_DC_P.PIDController2_LowerSaturationL;
    u2 = FW_control_DC_P.PIDController2_UpperSaturationL;
    if (u0 > u2) {
      /* Saturate: '<S42>/Saturation' */
      FW_control_DC_B.Saturation_a = u2;
    } else if (u0 < u1) {
      /* Saturate: '<S42>/Saturation' */
      FW_control_DC_B.Saturation_a = u1;
    } else {
      /* Saturate: '<S42>/Saturation' */
      FW_control_DC_B.Saturation_a = u0;
    }

    /* End of Saturate: '<S42>/Saturation' */

    /* Saturate: '<Root>/Saturation' */
    u0 = FW_control_DC_B.Saturation_a;
    u1 = FW_control_DC_P.Saturation_LowerSat;
    u2 = FW_control_DC_P.Saturation_UpperSat;
    if (u0 > u2) {
      /* Saturate: '<Root>/Saturation' */
      FW_control_DC_B.Saturation_g = u2;
    } else if (u0 < u1) {
      /* Saturate: '<Root>/Saturation' */
      FW_control_DC_B.Saturation_g = u1;
    } else {
      /* Saturate: '<Root>/Saturation' */
      FW_control_DC_B.Saturation_g = u0;
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* Sum: '<Root>/Add8' incorporates:
     *  Constant: '<Root>/Constant'
     */
    FW_control_DC_B.Add8 = FW_control_DC_B.Saturation_g +
      FW_control_DC_P.Constant_Value;

    /* Gain: '<Root>/Gain2' */
    FW_control_DC_B.da = (real32_T)(FW_control_DC_P.Gain2_Gain *
      FW_control_DC_B.Add8);

    /* Product: '<Root>/Product' */
    FW_control_DC_B.Product = FW_control_DC_B.da * (real32_T)FW_control_DC_B.en;

    /* Gain: '<Root>/Gain5' */
    FW_control_DC_B.Gain5 = FW_control_DC_P.PWM_CounterPeriod *
      FW_control_DC_B.Product;

    /* DataTypeConversion: '<Root>/Data Type Conversion2' */
    FW_control_DC_B.DataTypeConversion2 = (int16_T)(real32_T)floor
      (FW_control_DC_B.Gain5);

    /* S-Function (c2802xpwm): '<Root>/A' */

    /*-- Update CMPA value for ePWM1 --*/
    {
      EPwm1Regs.CMPA.half.CMPA = (uint16_T)(FW_control_DC_B.DataTypeConversion2);
    }

    /* Sum: '<Root>/Add2' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    FW_control_DC_B.db = FW_control_DC_P.Constant2_Value - FW_control_DC_B.da;

    /* Product: '<Root>/Product3' */
    FW_control_DC_B.Product3 = FW_control_DC_B.db * (real32_T)FW_control_DC_B.en;

    /* Gain: '<Root>/Gain1' */
    FW_control_DC_B.Gain1 = FW_control_DC_P.PWM_CounterPeriod *
      FW_control_DC_B.Product3;

    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    FW_control_DC_B.DataTypeConversion1 = (int16_T)(real32_T)floor
      (FW_control_DC_B.Gain1);

    /* S-Function (c2802xpwm): '<Root>/B' */

    /*-- Update CMPA value for ePWM2 --*/
    {
      EPwm2Regs.CMPA.half.CMPA = (uint16_T)(FW_control_DC_B.DataTypeConversion1);
    }
  }

  if (FW_control_DC_M->Timing.TaskCounters.TID[3] == 0) {
    /* S-Function (c2802xadc): '<Root>/traction' */
    {
      /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
      /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
      FW_control_DC_B.traction = (AdcResult.ADCRESULT2);
    }

    /* DataTypeConversion: '<Root>/Data Type Conversion11' */
    FW_control_DC_B.DataTypeConversion11 = (int16_T)FW_control_DC_B.traction;

    /* Gain: '<Root>/Gain4' */
    FW_control_DC_B.Gain4 = (int32_T)FW_control_DC_P.Gain4_Gain *
      FW_control_DC_B.DataTypeConversion11;

    /* Sum: '<Root>/Add1' incorporates:
     *  Constant: '<Root>/Constant4'
     *  Gain: '<Root>/Gain4'
     */
    FW_control_DC_B.Add1 = (real_T)FW_control_DC_B.Gain4 * 1.9073486328125E-6 -
      FW_control_DC_P.Constant4_Value;

    /* S-Function (c2802xadc): '<Root>/enable' */
    {
      /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
      /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
      FW_control_DC_B.enable = (AdcResult.ADCRESULT4);
    }

    /* DataTypeConversion: '<Root>/Data Type Conversion8' */
    FW_control_DC_B.DataTypeConversion8 = (int16_T)FW_control_DC_B.enable;

    /* Gain: '<Root>/Gain3' */
    FW_control_DC_B.Gain3 = (int32_T)FW_control_DC_P.Gain3_Gain *
      FW_control_DC_B.DataTypeConversion8;

    /* RelationalOperator: '<S1>/Compare' incorporates:
     *  Constant: '<S1>/Constant'
     *  Gain: '<Root>/Gain3'
     */
    FW_control_DC_B.Compare = (FW_control_DC_B.Gain3 >=
      FW_control_DC_P.CompareToConstant_const);

    /* DataTypeConversion: '<Root>/Data Type Conversion12' */
    FW_control_DC_B.DataTypeConversion12 = (real32_T)FW_control_DC_B.Add1;
  }

  if (FW_control_DC_M->Timing.TaskCounters.TID[2] == 0) {
    /* S-Function (c280xqep): '<Root>/encoder' */
    {
      FW_control_DC_B.encoder = EQep2Regs.QPOSCNT;/*eQEP Position Counter*/
    }

    /* Delay: '<Root>/Delay' */
    FW_control_DC_B.Delay = FW_control_DC_DWork.Delay_DSTATE;

    /* Sum: '<Root>/Subtract' */
    FW_control_DC_B.Subtract = FW_control_DC_B.encoder - FW_control_DC_B.Delay;

    /* DataTypeConversion: '<Root>/Data Type Conversion7' */
    FW_control_DC_B.DataTypeConversion7 = (real32_T)FW_control_DC_B.Subtract;

    /* Gain: '<Root>/Gain6' */
    FW_control_DC_B.Gain6 = FW_control_DC_P.Gain6_Gain *
      FW_control_DC_B.DataTypeConversion7;

    /* Gain: '<Root>/Gain8' */
    FW_control_DC_B.w = FW_control_DC_P.Gain8_Gain * FW_control_DC_B.Gain6;
  }

  if (FW_control_DC_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S28>/SumI2' */
    FW_control_DC_B.SumI2 = FW_control_DC_B.Saturation_a - FW_control_DC_B.Sum_k;

    /* Gain: '<S28>/Kb' */
    FW_control_DC_B.Kb = FW_control_DC_P.PIDController2_Kb *
      FW_control_DC_B.SumI2;

    /* Gain: '<S32>/Integral Gain' */
    FW_control_DC_B.IntegralGain = FW_control_DC_P.kiI * FW_control_DC_B.Add;

    /* Sum: '<S28>/SumI4' */
    FW_control_DC_B.SumI4 = FW_control_DC_B.Kb + FW_control_DC_B.IntegralGain;

    /* Sum: '<S76>/SumI2' */
    FW_control_DC_B.SumI2_g = FW_control_DC_B.Saturation - FW_control_DC_B.Sum;

    /* Gain: '<S76>/Kb' */
    FW_control_DC_B.Kb_c = FW_control_DC_P.PIDController4_Kb *
      FW_control_DC_B.SumI2_g;

    /* Gain: '<S80>/Integral Gain' */
    FW_control_DC_B.IntegralGain_l = FW_control_DC_P.kiW * FW_control_DC_B.Add7;

    /* Sum: '<S76>/SumI4' */
    FW_control_DC_B.SumI4_c = FW_control_DC_B.Kb_c +
      FW_control_DC_B.IntegralGain_l;

    /* S-Function (c280xgpio_do): '<Root>/DRV8301 enable' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    {
      if (FW_control_DC_P.Constant1_Value) {
        GpioDataRegs.GPBSET.bit.GPIO50 = 1U;
      } else {
        GpioDataRegs.GPBCLEAR.bit.GPIO50 = 1U;
      }
    }
  }

  /* Update for RateTransition: '<Root>/Rate Transition6' incorporates:
   *  RateTransition: '<Root>/Rate Transition1'
   */
  if (FW_control_DC_M->Timing.TaskCounters.TID[3] == 0) {
    FW_control_DC_DWork.RateTransition6_Buffer[FW_control_DC_DWork.RateTransition6_ActiveBufIdx
      == 0] = FW_control_DC_B.DataTypeConversion12;
    FW_control_DC_DWork.RateTransition6_ActiveBufIdx =
      (FW_control_DC_DWork.RateTransition6_ActiveBufIdx == 0);
    FW_control_DC_DWork.RateTransition1_Buffer0 = FW_control_DC_B.Compare;
  }

  /* End of Update for RateTransition: '<Root>/Rate Transition6' */

  /* Update for RateTransition: '<Root>/Rate Transition9' */
  if (FW_control_DC_M->Timing.TaskCounters.TID[2] == 0) {
    FW_control_DC_DWork.RateTransition9_Buffer[FW_control_DC_DWork.RateTransition9_ActiveBufIdx
      == 0] = FW_control_DC_B.w;
    FW_control_DC_DWork.RateTransition9_ActiveBufIdx =
      (FW_control_DC_DWork.RateTransition9_ActiveBufIdx == 0);

    /* Update for Delay: '<Root>/Delay' */
    FW_control_DC_DWork.Delay_DSTATE = FW_control_DC_B.encoder;
  }

  /* End of Update for RateTransition: '<Root>/Rate Transition9' */
  if (FW_control_DC_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for DiscreteIntegrator: '<S83>/Integrator' */
    FW_control_DC_DWork.Integrator_DSTATE += FW_control_DC_P.Integrator_gainval *
      FW_control_DC_B.SumI4_c;
    FW_control_DC_DWork.Integrator_PrevResetState = (int16_T)FW_control_DC_B.en;

    /* Update for DiscreteIntegrator: '<S35>/Integrator' */
    FW_control_DC_DWork.Integrator_DSTATE_k +=
      FW_control_DC_P.Integrator_gainval_n * FW_control_DC_B.SumI4;
    FW_control_DC_DWork.Integrator_PrevResetState_c = (int16_T)
      FW_control_DC_B.en;
  }

  rate_scheduler();
}

/* Model initialize function */
void FW_control_DC_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)FW_control_DC_M, 0,
                sizeof(RT_MODEL_FW_control_DC));

  /* block I/O */
  (void) memset(((void *) &FW_control_DC_B), 0,
                sizeof(BlockIO_FW_control_DC));

  {
    FW_control_DC_B.Add8 = 0.0;
    FW_control_DC_B.Add1 = 0.0;
    FW_control_DC_B.RateTransition6 = 0.0F;
    FW_control_DC_B.RateTransition9 = 0.0F;
    FW_control_DC_B.Add7 = 0.0F;
    FW_control_DC_B.ProportionalGain = 0.0F;
    FW_control_DC_B.Integrator = 0.0F;
    FW_control_DC_B.Sum = 0.0F;
    FW_control_DC_B.Saturation = 0.0F;
    FW_control_DC_B.i = 0.0F;
    FW_control_DC_B.Saturation4 = 0.0F;
    FW_control_DC_B.DataTypeConversion19 = 0.0F;
    FW_control_DC_B.Gain11 = 0.0F;
    FW_control_DC_B.Add = 0.0F;
    FW_control_DC_B.ProportionalGain_n = 0.0F;
    FW_control_DC_B.Integrator_a = 0.0F;
    FW_control_DC_B.Sum_k = 0.0F;
    FW_control_DC_B.Saturation_a = 0.0F;
    FW_control_DC_B.Saturation_g = 0.0F;
    FW_control_DC_B.da = 0.0F;
    FW_control_DC_B.Product = 0.0F;
    FW_control_DC_B.Gain5 = 0.0F;
    FW_control_DC_B.db = 0.0F;
    FW_control_DC_B.Product3 = 0.0F;
    FW_control_DC_B.Gain1 = 0.0F;
    FW_control_DC_B.DataTypeConversion12 = 0.0F;
    FW_control_DC_B.DataTypeConversion7 = 0.0F;
    FW_control_DC_B.Gain6 = 0.0F;
    FW_control_DC_B.w = 0.0F;
    FW_control_DC_B.SumI2 = 0.0F;
    FW_control_DC_B.Kb = 0.0F;
    FW_control_DC_B.IntegralGain = 0.0F;
    FW_control_DC_B.SumI4 = 0.0F;
    FW_control_DC_B.SumI2_g = 0.0F;
    FW_control_DC_B.Kb_c = 0.0F;
    FW_control_DC_B.IntegralGain_l = 0.0F;
    FW_control_DC_B.SumI4_c = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&FW_control_DC_DWork, 0,
                sizeof(D_Work_FW_control_DC));
  FW_control_DC_DWork.Add8_DWORK1 = 0.0;
  FW_control_DC_DWork.Add1_DWORK1 = 0.0;
  FW_control_DC_DWork.Integrator_DSTATE = 0.0F;
  FW_control_DC_DWork.Integrator_DSTATE_k = 0.0F;
  FW_control_DC_DWork.RateTransition6_Buffer[0] = 0.0F;
  FW_control_DC_DWork.RateTransition6_Buffer[1] = 0.0F;
  FW_control_DC_DWork.RateTransition9_Buffer[0] = 0.0F;
  FW_control_DC_DWork.RateTransition9_Buffer[1] = 0.0F;

  /* Start for S-Function (c2802xadc): '<Root>/shunt A' */
  if (MW_adcInitFlag == 0U) {
    InitAdc();
    MW_adcInitFlag = 1U;
  }

  config_ADC_SOC0 ();

  /* Start for S-Function (c2802xpwm): '<Root>/A' */

  /*** Initialize ePWM1 modules ***/
  {
    /*  // Time Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL             = 3U;          // Sync Output Select

       EPwm1Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

       EPwm1Regs.TBCTL.bit.PHSEN                = 0U;          // Phase Load Enable
       EPwm1Regs.TBCTL.bit.PHSDIR               = 1U;          // Phase Direction Bit
       EPwm1Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
       EPwm1Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
       EPwm1Regs.TBCTL.bit.SWFSYNC              = 0U;          // Software Force Sync Pulse
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FFFU) | 0x2032U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 1125U;           // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm1Regs.TBPHS.half.TBPHS               = 0U;         // Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm1Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm1Regs.CMPCTL.bit.LOADAMODE           = 2U;          // Active Compare A Load
       EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x5FU) | 0x2U;
    EPwm1Regs.CMPA.half.CMPA = 0U;     // Counter Compare A Register
    EPwm1Regs.CMPB = 0U;               // Counter Compare B Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm1Regs.AQCTLB.all = 264U;
                               // Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm1Regs.AQSFRC.bit.RLDCSF              = 0U;          // Reload from Shadow Options
     */
    EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm1Regs.AQCSFRC.bit.CSFA               = 0U;          // Continuous Software Force on output A
       EPwm1Regs.AQCSFRC.bit.CSFB               = 0U;          // Continuous Software Force on output B
     */
    EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm1Regs.DBCTL.bit.OUT_MODE             = 3U;          // Dead Band Output Mode Control
       EPwm1Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
       EPwm1Regs.DBCTL.bit.POLSEL               = 2U;          // Polarity Select Control
       EPwm1Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x803FU) | 0xBU;
    EPwm1Regs.DBRED = 0U;// Dead-Band Generator Rising Edge Delay Count Register
    EPwm1Regs.DBFED = 0U;
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN               = 1U;          // Start of Conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASEL              = 2U;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCAPRD               = 1U;          // EPWM1SOCA Period Select
       EPwm1Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion B Select
       EPwm1Regs.ETPS.bit.SOCBPRD               = 1U;          // EPWM1SOCB Period Select
       EPwm1Regs.ETSEL.bit.INTEN                = 0U;          // EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSEL               = 1U;          // EPWM1INTn Select
       EPwm1Regs.ETPS.bit.INTPRD                = 1U;          // EPWM1INTn Period Select
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF0FU) | 0x1A01U;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x3303U) | 0x1101U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm1Regs.PCCTL.bit.CHPEN                = 0U;          // PWM chopping enable
       EPwm1Regs.PCCTL.bit.CHPFREQ              = 0U;          // Chopping clock frequency
       EPwm1Regs.PCCTL.bit.OSHTWTH              = 0U;          // One-shot pulse width
       EPwm1Regs.PCCTL.bit.CHPDUTY              = 0U;          // Chopping clock Duty cycle
     */
    EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm1Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm1Regs.TZCTL.bit.TZA                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM1A
       EPwm1Regs.TZCTL.bit.TZB                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM1B
       EPwm1Regs.TZCTL.bit.DCAEVT1              = 3U;          // EPWM1A action on DCAEVT1
       EPwm1Regs.TZCTL.bit.DCAEVT2              = 3U;          // EPWM1A action on DCAEVT2
       EPwm1Regs.TZCTL.bit.DCBEVT1              = 3U;          // EPWM1B action on DCBEVT1
       EPwm1Regs.TZCTL.bit.DCBEVT2              = 3U;          // EPWM1B action on DCBEVT2
     */
    EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	// Trip Zone Enable Interrupt Register
       EPwm1Regs.TZEINT.bit.OST                 = 0U;          // Trip Zones One Shot Int Enable
       EPwm1Regs.TZEINT.bit.CBC                 = 0U;          // Trip Zones Cycle By Cycle Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT1             = 0U;          // Digital Compare A Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT2             = 0U;          // Digital Compare A Event 2 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT1             = 0U;          // Digital Compare B Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT2             = 0U;          // Digital Compare B Event 2 Int Enable
     */
    EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	// Digital Compare A Control Register
       EPwm1Regs.DCACTL.bit.EVT1SYNCE           = 0U;          // DCAEVT1 SYNC Enable
       EPwm1Regs.DCACTL.bit.EVT1SOCE            = 0U;          // DCAEVT1 SOC Enable
       EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
       EPwm1Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
     */
    EPwm1Regs.DCACTL.all = (EPwm1Regs.DCACTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare B Control Register
       EPwm1Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          // DCBEVT1 SYNC Enable
       EPwm1Regs.DCBCTL.bit.EVT1SOCE            = 0U;          // DCBEVT1 SOC Enable
       EPwm1Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCBEVT1 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          // DCBEVT1 Source Signal
       EPwm1Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCBEVT2 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          // DCBEVT2 Source Signal
     */
    EPwm1Regs.DCBCTL.all = (EPwm1Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare Trip Select Register
       EPwm1Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          // Digital Compare A High COMP Input Select

       EPwm1Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          // Digital Compare A Low COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          // Digital Compare B High COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          // Digital Compare B Low COMP Input Select
     */
    EPwm1Regs.DCTRIPSEL.all = (EPwm1Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm1Regs.TZDCSEL.bit.DCAEVT1            = 0U;          // Digital Compare Output A Event 1
       EPwm1Regs.TZDCSEL.bit.DCAEVT2            = 0U;          // Digital Compare Output A Event 2
       EPwm1Regs.TZDCSEL.bit.DCBEVT1            = 0U;          // Digital Compare Output B Event 1
       EPwm1Regs.TZDCSEL.bit.DCBEVT2            = 0U;          // Digital Compare Output B Event 2
     */
    EPwm1Regs.TZDCSEL.all = (EPwm1Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	// Digital Compare Filter Control Register
       EPwm1Regs.DCFCTL.bit.BLANKE              = 0U;          // Blanking Enable/Disable
       EPwm1Regs.DCFCTL.bit.PULSESEL            = 1U;          // Pulse Select for Blanking & Capture Alignment
       EPwm1Regs.DCFCTL.bit.BLANKINV            = 0U;          // Blanking Window Inversion
       EPwm1Regs.DCFCTL.bit.SRCSEL              = 0U;          // Filter Block Signal Source Select
     */
    EPwm1Regs.DCFCTL.all = (EPwm1Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm1Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm1Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm1Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
     */
    EPwm1Regs.DCCAPCTL.all = (EPwm1Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	// HRPWM Configuration Register
       EPwm1Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm1Regs.HRCNFG.bit.SELOUTB             = 1U;          // EPWMB Output Selection Bit
     */
    EPwm1Regs.HRCNFG.all = (EPwm1Regs.HRCNFG.all & ~0xA0U) | 0x20U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<Root>/B' */

  /*** Initialize ePWM2 modules ***/
  {
    /*  // Time Base Control Register
       EPwm2Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
       EPwm2Regs.TBCTL.bit.SYNCOSEL             = 3U;          // Sync Output Select

       EPwm2Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

       EPwm2Regs.TBCTL.bit.PHSEN                = 0U;          // Phase Load Enable
       EPwm2Regs.TBCTL.bit.PHSDIR               = 1U;          // Phase Direction Bit
       EPwm2Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
       EPwm2Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
       EPwm2Regs.TBCTL.bit.SWFSYNC              = 0U;          // Software Force Sync Pulse
     */
    EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FFFU) | 0x2032U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm2Regs.TBPRD = 1125U;           // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm2Regs.TBPHS.half.TBPHS               = 0U;         // Phase offset register
     */
    EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm2Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm2Regs.CMPCTL.bit.LOADAMODE           = 2U;          // Active Compare A Load
       EPwm2Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm2Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm2Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x5FU) | 0x2U;
    EPwm2Regs.CMPA.half.CMPA = 0U;     // Counter Compare A Register
    EPwm2Regs.CMPB = 0U;               // Counter Compare B Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm2Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm2Regs.AQCTLB.all = 264U;
                               // Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm2Regs.AQSFRC.bit.RLDCSF              = 0U;          // Reload from Shadow Options
     */
    EPwm2Regs.AQSFRC.all = (EPwm2Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm2Regs.AQCSFRC.bit.CSFA               = 0U;          // Continuous Software Force on output A
       EPwm2Regs.AQCSFRC.bit.CSFB               = 0U;          // Continuous Software Force on output B
     */
    EPwm2Regs.AQCSFRC.all = (EPwm2Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm2Regs.DBCTL.bit.OUT_MODE             = 3U;          // Dead Band Output Mode Control
       EPwm2Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
       EPwm2Regs.DBCTL.bit.POLSEL               = 2U;          // Polarity Select Control
       EPwm2Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
     */
    EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x803FU) | 0xBU;
    EPwm2Regs.DBRED = 0U;// Dead-Band Generator Rising Edge Delay Count Register
    EPwm2Regs.DBFED = 0U;
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm2Regs.ETSEL.bit.SOCAEN               = 0U;          // Start of Conversion A Enable
       EPwm2Regs.ETSEL.bit.SOCASEL              = 2U;          // Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCAPRD               = 1U;          // EPWM2SOCA Period Select
       EPwm2Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
       EPwm2Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion B Select
       EPwm2Regs.ETPS.bit.SOCBPRD               = 1U;          // EPWM2SOCB Period Select
       EPwm2Regs.ETSEL.bit.INTEN                = 0U;          // EPWM2INTn Enable
       EPwm2Regs.ETSEL.bit.INTSEL               = 1U;          // EPWM2INTn Select
       EPwm2Regs.ETPS.bit.INTPRD                = 1U;          // EPWM2INTn Period Select
     */
    EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF0FU) | 0x1201U;
    EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x3303U) | 0x1101U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm2Regs.PCCTL.bit.CHPEN                = 0U;          // PWM chopping enable
       EPwm2Regs.PCCTL.bit.CHPFREQ              = 0U;          // Chopping clock frequency
       EPwm2Regs.PCCTL.bit.OSHTWTH              = 0U;          // One-shot pulse width
       EPwm2Regs.PCCTL.bit.CHPDUTY              = 0U;          // Chopping clock Duty cycle
     */
    EPwm2Regs.PCCTL.all = (EPwm2Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm2Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm2Regs.TZCTL.bit.TZA                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM2A
       EPwm2Regs.TZCTL.bit.TZB                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM2B
       EPwm2Regs.TZCTL.bit.DCAEVT1              = 3U;          // EPWM2A action on DCAEVT1
       EPwm2Regs.TZCTL.bit.DCAEVT2              = 3U;          // EPWM2A action on DCAEVT2
       EPwm2Regs.TZCTL.bit.DCBEVT1              = 3U;          // EPWM2B action on DCBEVT1
       EPwm2Regs.TZCTL.bit.DCBEVT2              = 3U;          // EPWM2B action on DCBEVT2
     */
    EPwm2Regs.TZCTL.all = (EPwm2Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	// Trip Zone Enable Interrupt Register
       EPwm2Regs.TZEINT.bit.OST                 = 0U;          // Trip Zones One Shot Int Enable
       EPwm2Regs.TZEINT.bit.CBC                 = 0U;          // Trip Zones Cycle By Cycle Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT1             = 0U;          // Digital Compare A Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT2             = 0U;          // Digital Compare A Event 2 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT1             = 0U;          // Digital Compare B Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT2             = 0U;          // Digital Compare B Event 2 Int Enable
     */
    EPwm2Regs.TZEINT.all = (EPwm2Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	// Digital Compare A Control Register
       EPwm2Regs.DCACTL.bit.EVT1SYNCE           = 0U;          // DCAEVT1 SYNC Enable
       EPwm2Regs.DCACTL.bit.EVT1SOCE            = 0U;          // DCAEVT1 SOC Enable
       EPwm2Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
       EPwm2Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
     */
    EPwm2Regs.DCACTL.all = (EPwm2Regs.DCACTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare B Control Register
       EPwm2Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          // DCBEVT1 SYNC Enable
       EPwm2Regs.DCBCTL.bit.EVT1SOCE            = 0U;          // DCBEVT1 SOC Enable
       EPwm2Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCBEVT1 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          // DCBEVT1 Source Signal
       EPwm2Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCBEVT2 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          // DCBEVT2 Source Signal
     */
    EPwm2Regs.DCBCTL.all = (EPwm2Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare Trip Select Register
       EPwm2Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          // Digital Compare A High COMP Input Select

       EPwm2Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          // Digital Compare A Low COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          // Digital Compare B High COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          // Digital Compare B Low COMP Input Select
     */
    EPwm2Regs.DCTRIPSEL.all = (EPwm2Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm2Regs.TZDCSEL.bit.DCAEVT1            = 0U;          // Digital Compare Output A Event 1
       EPwm2Regs.TZDCSEL.bit.DCAEVT2            = 0U;          // Digital Compare Output A Event 2
       EPwm2Regs.TZDCSEL.bit.DCBEVT1            = 0U;          // Digital Compare Output B Event 1
       EPwm2Regs.TZDCSEL.bit.DCBEVT2            = 0U;          // Digital Compare Output B Event 2
     */
    EPwm2Regs.TZDCSEL.all = (EPwm2Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	// Digital Compare Filter Control Register
       EPwm2Regs.DCFCTL.bit.BLANKE              = 0U;          // Blanking Enable/Disable
       EPwm2Regs.DCFCTL.bit.PULSESEL            = 1U;          // Pulse Select for Blanking & Capture Alignment
       EPwm2Regs.DCFCTL.bit.BLANKINV            = 0U;          // Blanking Window Inversion
       EPwm2Regs.DCFCTL.bit.SRCSEL              = 0U;          // Filter Block Signal Source Select
     */
    EPwm2Regs.DCFCTL.all = (EPwm2Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm2Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm2Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm2Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
     */
    EPwm2Regs.DCCAPCTL.all = (EPwm2Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	// HRPWM Configuration Register
       EPwm2Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm2Regs.HRCNFG.bit.SELOUTB             = 1U;          // EPWMB Output Selection Bit
     */
    EPwm2Regs.HRCNFG.all = (EPwm2Regs.HRCNFG.all & ~0xA0U) | 0x20U;
    EDIS;
  }

  /* Start for S-Function (c2802xadc): '<Root>/traction' */
  if (MW_adcInitFlag == 0U) {
    InitAdc();
    MW_adcInitFlag = 1U;
  }

  config_ADC_SOC2 ();

  /* Start for S-Function (c2802xadc): '<Root>/enable' */
  if (MW_adcInitFlag == 0U) {
    InitAdc();
    MW_adcInitFlag = 1U;
  }

  config_ADC_SOC4 ();

  /* Start for S-Function (c280xqep): '<Root>/encoder' */
  config_QEP_eQEP2((uint32_T)4294967295U,(uint32_T)0U, (uint32_T)0, (uint32_T)0,
                   (uint16_T)0, (uint16_T)0, (uint16_T)4232, (uint16_T)32768,
                   (uint16_T)0,(uint16_T)0);

  /* Start for S-Function (c280xgpio_do): '<Root>/DRV8301 enable' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  EALLOW;
  GpioCtrlRegs.GPBMUX2.all &= 0xFFFFFFCFU;
  GpioCtrlRegs.GPBDIR.all |= 0x40000U;
  EDIS;

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition6' */
  FW_control_DC_DWork.RateTransition6_Buffer[0] =
    FW_control_DC_P.RateTransition6_InitialConditio;

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition9' */
  FW_control_DC_DWork.RateTransition9_Buffer[0] =
    FW_control_DC_P.RateTransition9_InitialConditio;

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition1' */
  FW_control_DC_DWork.RateTransition1_Buffer0 =
    FW_control_DC_P.RateTransition1_InitialConditio;

  /* InitializeConditions for DiscreteIntegrator: '<S83>/Integrator' */
  FW_control_DC_DWork.Integrator_DSTATE =
    FW_control_DC_P.PIDController4_InitialCondition;
  FW_control_DC_DWork.Integrator_PrevResetState = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S35>/Integrator' */
  FW_control_DC_DWork.Integrator_DSTATE_k =
    FW_control_DC_P.PIDController2_InitialCondition;
  FW_control_DC_DWork.Integrator_PrevResetState_c = 2;

  /* InitializeConditions for Delay: '<Root>/Delay' */
  FW_control_DC_DWork.Delay_DSTATE = FW_control_DC_P.Delay_InitialCondition;
}

/* Model terminate function */
void FW_control_DC_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
