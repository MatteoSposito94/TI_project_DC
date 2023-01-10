/*
 * File: FW_control_DC.h
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

#ifndef RTW_HEADER_FW_control_DC_h_
#define RTW_HEADER_FW_control_DC_h_
#ifndef FW_control_DC_COMMON_INCLUDES_
#define FW_control_DC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "c2000BoardSupport.h"
#include "F2806x_Device.h"
#include "F2806x_Examples.h"
#include "IQmathLib.h"
#include "F2806x_Gpio.h"
#endif                                 /* FW_control_DC_COMMON_INCLUDES_ */

#include "FW_control_DC_types.h"
#include <string.h>
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_XBAR(void);
extern void config_ePWM_TBSync(void);

/* Block signals (default storage) */
typedef struct {
  real_T Add8;                         /* '<Root>/Add8' */
  real_T Add1;                         /* '<Root>/Add1' */
  real32_T RateTransition6;            /* '<Root>/Rate Transition6' */
  real32_T RateTransition9;            /* '<Root>/Rate Transition9' */
  real32_T Add7;                       /* '<Root>/Add7' */
  real32_T ProportionalGain;           /* '<S88>/Proportional Gain' */
  real32_T Integrator;                 /* '<S83>/Integrator' */
  real32_T Sum;                        /* '<S92>/Sum' */
  real32_T Saturation;                 /* '<S90>/Saturation' */
  real32_T i;                          /* '<Root>/Gain12' */
  real32_T Saturation4;                /* '<Root>/Saturation4' */
  real32_T DataTypeConversion19;       /* '<Root>/Data Type Conversion19' */
  real32_T Gain11;                     /* '<Root>/Gain11' */
  real32_T Add;                        /* '<Root>/Add' */
  real32_T ProportionalGain_n;         /* '<S40>/Proportional Gain' */
  real32_T Integrator_a;               /* '<S35>/Integrator' */
  real32_T Sum_k;                      /* '<S44>/Sum' */
  real32_T Saturation_a;               /* '<S42>/Saturation' */
  real32_T Saturation_g;               /* '<Root>/Saturation' */
  real32_T da;                         /* '<Root>/Gain2' */
  real32_T Product;                    /* '<Root>/Product' */
  real32_T Gain5;                      /* '<Root>/Gain5' */
  real32_T db;                         /* '<Root>/Add2' */
  real32_T Product3;                   /* '<Root>/Product3' */
  real32_T Gain1;                      /* '<Root>/Gain1' */
  real32_T DataTypeConversion12;       /* '<Root>/Data Type Conversion12' */
  real32_T DataTypeConversion7;        /* '<Root>/Data Type Conversion7' */
  real32_T Gain6;                      /* '<Root>/Gain6' */
  real32_T w;                          /* '<Root>/Gain8' */
  real32_T SumI2;                      /* '<S28>/SumI2' */
  real32_T Kb;                         /* '<S28>/Kb' */
  real32_T IntegralGain;               /* '<S32>/Integral Gain' */
  real32_T SumI4;                      /* '<S28>/SumI4' */
  real32_T SumI2_g;                    /* '<S76>/SumI2' */
  real32_T Kb_c;                       /* '<S76>/Kb' */
  real32_T IntegralGain_l;             /* '<S80>/Integral Gain' */
  real32_T SumI4_c;                    /* '<S76>/SumI4' */
  int32_T Gain3;                       /* '<Root>/Gain3' */
  int32_T Gain4;                       /* '<Root>/Gain4' */
  int32_T encoder;                     /* '<Root>/encoder' */
  int32_T Delay;                       /* '<Root>/Delay' */
  int32_T Subtract;                    /* '<Root>/Subtract' */
  uint16_T shuntA;                     /* '<Root>/shunt A' */
  uint16_T traction;                   /* '<Root>/traction' */
  uint16_T enable;                     /* '<Root>/enable' */
  int16_T DataTypeConversion;          /* '<Root>/Data Type Conversion' */
  int16_T Add4;                        /* '<Root>/Add4' */
  int16_T DataTypeConversion2;         /* '<Root>/Data Type Conversion2' */
  int16_T DataTypeConversion1;         /* '<Root>/Data Type Conversion1' */
  int16_T DataTypeConversion11;        /* '<Root>/Data Type Conversion11' */
  int16_T DataTypeConversion8;         /* '<Root>/Data Type Conversion8' */
  boolean_T en;                        /* '<Root>/Rate Transition1' */
  boolean_T Compare;                   /* '<S1>/Compare' */
} BlockIO_FW_control_DC;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Add8_DWORK1;                  /* '<Root>/Add8' */
  real_T Add1_DWORK1;                  /* '<Root>/Add1' */
  real32_T Integrator_DSTATE;          /* '<S83>/Integrator' */
  real32_T Integrator_DSTATE_k;        /* '<S35>/Integrator' */
  int32_T Delay_DSTATE;                /* '<Root>/Delay' */
  volatile real32_T RateTransition6_Buffer[2];/* '<Root>/Rate Transition6' */
  volatile real32_T RateTransition9_Buffer[2];/* '<Root>/Rate Transition9' */
  volatile int16_T RateTransition6_ActiveBufIdx;/* '<Root>/Rate Transition6' */
  volatile int16_T RateTransition9_ActiveBufIdx;/* '<Root>/Rate Transition9' */
  int16_T Integrator_PrevResetState;   /* '<S83>/Integrator' */
  int16_T Integrator_PrevResetState_c; /* '<S35>/Integrator' */
  volatile boolean_T RateTransition1_Buffer0;/* '<Root>/Rate Transition1' */
} D_Work_FW_control_DC;

/* Parameters (default storage) */
struct Parameters_FW_control_DC_ {
  real32_T PWM_CounterPeriod;          /* Variable: PWM_CounterPeriod
                                        * Referenced by:
                                        *   '<Root>/Gain1'
                                        *   '<Root>/Gain5'
                                        */
  real32_T g_adc;                      /* Variable: g_adc
                                        * Referenced by: '<Root>/Gain11'
                                        */
  real32_T imax;                       /* Variable: imax
                                        * Referenced by: '<Root>/Saturation4'
                                        */
  real32_T kiI;                        /* Variable: kiI
                                        * Referenced by: '<S32>/Integral Gain'
                                        */
  real32_T kiW;                        /* Variable: kiW
                                        * Referenced by: '<S80>/Integral Gain'
                                        */
  real32_T kpI;                        /* Variable: kpI
                                        * Referenced by: '<S40>/Proportional Gain'
                                        */
  real32_T kpW;                        /* Variable: kpW
                                        * Referenced by: '<S88>/Proportional Gain'
                                        */
  int32_T CompareToConstant_const;    /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S1>/Constant'
                                       */
  real32_T PIDController4_InitialCondition;
                              /* Mask Parameter: PIDController4_InitialCondition
                               * Referenced by: '<S83>/Integrator'
                               */
  real32_T PIDController2_InitialCondition;
                              /* Mask Parameter: PIDController2_InitialCondition
                               * Referenced by: '<S35>/Integrator'
                               */
  real32_T PIDController2_Kb;          /* Mask Parameter: PIDController2_Kb
                                        * Referenced by: '<S28>/Kb'
                                        */
  real32_T PIDController4_Kb;          /* Mask Parameter: PIDController4_Kb
                                        * Referenced by: '<S76>/Kb'
                                        */
  real32_T PIDController4_LowerSaturationL;
                              /* Mask Parameter: PIDController4_LowerSaturationL
                               * Referenced by: '<S90>/Saturation'
                               */
  real32_T PIDController2_LowerSaturationL;
                              /* Mask Parameter: PIDController2_LowerSaturationL
                               * Referenced by: '<S42>/Saturation'
                               */
  real32_T PIDController4_UpperSaturationL;
                              /* Mask Parameter: PIDController4_UpperSaturationL
                               * Referenced by: '<S90>/Saturation'
                               */
  real32_T PIDController2_UpperSaturationL;
                              /* Mask Parameter: PIDController2_UpperSaturationL
                               * Referenced by: '<S42>/Saturation'
                               */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/(Vdc)
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  int32_T Delay_InitialCondition;  /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<Root>/Delay'
                                    */
  real32_T RateTransition6_InitialConditio;
                          /* Computed Parameter: RateTransition6_InitialConditio
                           * Referenced by: '<Root>/Rate Transition6'
                           */
  real32_T RateTransition9_InitialConditio;
                          /* Computed Parameter: RateTransition9_InitialConditio
                           * Referenced by: '<Root>/Rate Transition9'
                           */
  real32_T Integrator_gainval;         /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S83>/Integrator'
                                        */
  real32_T Gain12_Gain;                /* Computed Parameter: Gain12_Gain
                                        * Referenced by: '<Root>/Gain12'
                                        */
  real32_T Saturation4_LowerSat;     /* Computed Parameter: Saturation4_LowerSat
                                      * Referenced by: '<Root>/Saturation4'
                                      */
  real32_T Integrator_gainval_n;     /* Computed Parameter: Integrator_gainval_n
                                      * Referenced by: '<S35>/Integrator'
                                      */
  real32_T Saturation_UpperSat;        /* Expression: Vdc
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real32_T Saturation_LowerSat;       /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<Root>/Saturation'
                                       */
  real32_T Constant2_Value;            /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real32_T Gain6_Gain;                 /* Computed Parameter: Gain6_Gain
                                        * Referenced by: '<Root>/Gain6'
                                        */
  real32_T Gain8_Gain;                 /* Computed Parameter: Gain8_Gain
                                        * Referenced by: '<Root>/Gain8'
                                        */
  int16_T Constant3_Value;             /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<Root>/Constant3'
                                        */
  int16_T Gain4_Gain;                  /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<Root>/Gain4'
                                        */
  int16_T Gain3_Gain;                  /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<Root>/Gain3'
                                        */
  boolean_T RateTransition1_InitialConditio;
                          /* Computed Parameter: RateTransition1_InitialConditio
                           * Referenced by: '<Root>/Rate Transition1'
                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_FW_control_DC {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[4];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern Parameters_FW_control_DC FW_control_DC_P;

/* Block signals (default storage) */
extern BlockIO_FW_control_DC FW_control_DC_B;

/* Block states (default storage) */
extern D_Work_FW_control_DC FW_control_DC_DWork;

/* Model entry point functions */
extern void FW_control_DC_initialize(void);

#pragma CODE_SECTION (FW_control_DC_step, "ramfuncs")

extern void FW_control_DC_step(void);
extern void FW_control_DC_terminate(void);

/* Real-time Model object */
extern RT_MODEL_FW_control_DC *const FW_control_DC_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'FW_control_DC'
 * '<S1>'   : 'FW_control_DC/Compare To Constant'
 * '<S2>'   : 'FW_control_DC/PID Controller2'
 * '<S3>'   : 'FW_control_DC/PID Controller4'
 * '<S4>'   : 'FW_control_DC/PID Controller2/Anti-windup'
 * '<S5>'   : 'FW_control_DC/PID Controller2/D Gain'
 * '<S6>'   : 'FW_control_DC/PID Controller2/Filter'
 * '<S7>'   : 'FW_control_DC/PID Controller2/Filter ICs'
 * '<S8>'   : 'FW_control_DC/PID Controller2/I Gain'
 * '<S9>'   : 'FW_control_DC/PID Controller2/Ideal P Gain'
 * '<S10>'  : 'FW_control_DC/PID Controller2/Ideal P Gain Fdbk'
 * '<S11>'  : 'FW_control_DC/PID Controller2/Integrator'
 * '<S12>'  : 'FW_control_DC/PID Controller2/Integrator ICs'
 * '<S13>'  : 'FW_control_DC/PID Controller2/N Copy'
 * '<S14>'  : 'FW_control_DC/PID Controller2/N Gain'
 * '<S15>'  : 'FW_control_DC/PID Controller2/P Copy'
 * '<S16>'  : 'FW_control_DC/PID Controller2/Parallel P Gain'
 * '<S17>'  : 'FW_control_DC/PID Controller2/Reset Signal'
 * '<S18>'  : 'FW_control_DC/PID Controller2/Saturation'
 * '<S19>'  : 'FW_control_DC/PID Controller2/Saturation Fdbk'
 * '<S20>'  : 'FW_control_DC/PID Controller2/Sum'
 * '<S21>'  : 'FW_control_DC/PID Controller2/Sum Fdbk'
 * '<S22>'  : 'FW_control_DC/PID Controller2/Tracking Mode'
 * '<S23>'  : 'FW_control_DC/PID Controller2/Tracking Mode Sum'
 * '<S24>'  : 'FW_control_DC/PID Controller2/Tsamp - Integral'
 * '<S25>'  : 'FW_control_DC/PID Controller2/Tsamp - Ngain'
 * '<S26>'  : 'FW_control_DC/PID Controller2/postSat Signal'
 * '<S27>'  : 'FW_control_DC/PID Controller2/preSat Signal'
 * '<S28>'  : 'FW_control_DC/PID Controller2/Anti-windup/Back Calculation'
 * '<S29>'  : 'FW_control_DC/PID Controller2/D Gain/Disabled'
 * '<S30>'  : 'FW_control_DC/PID Controller2/Filter/Disabled'
 * '<S31>'  : 'FW_control_DC/PID Controller2/Filter ICs/Disabled'
 * '<S32>'  : 'FW_control_DC/PID Controller2/I Gain/Internal Parameters'
 * '<S33>'  : 'FW_control_DC/PID Controller2/Ideal P Gain/Passthrough'
 * '<S34>'  : 'FW_control_DC/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S35>'  : 'FW_control_DC/PID Controller2/Integrator/Discrete'
 * '<S36>'  : 'FW_control_DC/PID Controller2/Integrator ICs/Internal IC'
 * '<S37>'  : 'FW_control_DC/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S38>'  : 'FW_control_DC/PID Controller2/N Gain/Disabled'
 * '<S39>'  : 'FW_control_DC/PID Controller2/P Copy/Disabled'
 * '<S40>'  : 'FW_control_DC/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S41>'  : 'FW_control_DC/PID Controller2/Reset Signal/External Reset'
 * '<S42>'  : 'FW_control_DC/PID Controller2/Saturation/Enabled'
 * '<S43>'  : 'FW_control_DC/PID Controller2/Saturation Fdbk/Disabled'
 * '<S44>'  : 'FW_control_DC/PID Controller2/Sum/Sum_PI'
 * '<S45>'  : 'FW_control_DC/PID Controller2/Sum Fdbk/Disabled'
 * '<S46>'  : 'FW_control_DC/PID Controller2/Tracking Mode/Disabled'
 * '<S47>'  : 'FW_control_DC/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S48>'  : 'FW_control_DC/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S49>'  : 'FW_control_DC/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S50>'  : 'FW_control_DC/PID Controller2/postSat Signal/Forward_Path'
 * '<S51>'  : 'FW_control_DC/PID Controller2/preSat Signal/Forward_Path'
 * '<S52>'  : 'FW_control_DC/PID Controller4/Anti-windup'
 * '<S53>'  : 'FW_control_DC/PID Controller4/D Gain'
 * '<S54>'  : 'FW_control_DC/PID Controller4/Filter'
 * '<S55>'  : 'FW_control_DC/PID Controller4/Filter ICs'
 * '<S56>'  : 'FW_control_DC/PID Controller4/I Gain'
 * '<S57>'  : 'FW_control_DC/PID Controller4/Ideal P Gain'
 * '<S58>'  : 'FW_control_DC/PID Controller4/Ideal P Gain Fdbk'
 * '<S59>'  : 'FW_control_DC/PID Controller4/Integrator'
 * '<S60>'  : 'FW_control_DC/PID Controller4/Integrator ICs'
 * '<S61>'  : 'FW_control_DC/PID Controller4/N Copy'
 * '<S62>'  : 'FW_control_DC/PID Controller4/N Gain'
 * '<S63>'  : 'FW_control_DC/PID Controller4/P Copy'
 * '<S64>'  : 'FW_control_DC/PID Controller4/Parallel P Gain'
 * '<S65>'  : 'FW_control_DC/PID Controller4/Reset Signal'
 * '<S66>'  : 'FW_control_DC/PID Controller4/Saturation'
 * '<S67>'  : 'FW_control_DC/PID Controller4/Saturation Fdbk'
 * '<S68>'  : 'FW_control_DC/PID Controller4/Sum'
 * '<S69>'  : 'FW_control_DC/PID Controller4/Sum Fdbk'
 * '<S70>'  : 'FW_control_DC/PID Controller4/Tracking Mode'
 * '<S71>'  : 'FW_control_DC/PID Controller4/Tracking Mode Sum'
 * '<S72>'  : 'FW_control_DC/PID Controller4/Tsamp - Integral'
 * '<S73>'  : 'FW_control_DC/PID Controller4/Tsamp - Ngain'
 * '<S74>'  : 'FW_control_DC/PID Controller4/postSat Signal'
 * '<S75>'  : 'FW_control_DC/PID Controller4/preSat Signal'
 * '<S76>'  : 'FW_control_DC/PID Controller4/Anti-windup/Back Calculation'
 * '<S77>'  : 'FW_control_DC/PID Controller4/D Gain/Disabled'
 * '<S78>'  : 'FW_control_DC/PID Controller4/Filter/Disabled'
 * '<S79>'  : 'FW_control_DC/PID Controller4/Filter ICs/Disabled'
 * '<S80>'  : 'FW_control_DC/PID Controller4/I Gain/Internal Parameters'
 * '<S81>'  : 'FW_control_DC/PID Controller4/Ideal P Gain/Passthrough'
 * '<S82>'  : 'FW_control_DC/PID Controller4/Ideal P Gain Fdbk/Disabled'
 * '<S83>'  : 'FW_control_DC/PID Controller4/Integrator/Discrete'
 * '<S84>'  : 'FW_control_DC/PID Controller4/Integrator ICs/Internal IC'
 * '<S85>'  : 'FW_control_DC/PID Controller4/N Copy/Disabled wSignal Specification'
 * '<S86>'  : 'FW_control_DC/PID Controller4/N Gain/Disabled'
 * '<S87>'  : 'FW_control_DC/PID Controller4/P Copy/Disabled'
 * '<S88>'  : 'FW_control_DC/PID Controller4/Parallel P Gain/Internal Parameters'
 * '<S89>'  : 'FW_control_DC/PID Controller4/Reset Signal/External Reset'
 * '<S90>'  : 'FW_control_DC/PID Controller4/Saturation/Enabled'
 * '<S91>'  : 'FW_control_DC/PID Controller4/Saturation Fdbk/Disabled'
 * '<S92>'  : 'FW_control_DC/PID Controller4/Sum/Sum_PI'
 * '<S93>'  : 'FW_control_DC/PID Controller4/Sum Fdbk/Disabled'
 * '<S94>'  : 'FW_control_DC/PID Controller4/Tracking Mode/Disabled'
 * '<S95>'  : 'FW_control_DC/PID Controller4/Tracking Mode Sum/Passthrough'
 * '<S96>'  : 'FW_control_DC/PID Controller4/Tsamp - Integral/Passthrough'
 * '<S97>'  : 'FW_control_DC/PID Controller4/Tsamp - Ngain/Passthrough'
 * '<S98>'  : 'FW_control_DC/PID Controller4/postSat Signal/Forward_Path'
 * '<S99>'  : 'FW_control_DC/PID Controller4/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_FW_control_DC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
