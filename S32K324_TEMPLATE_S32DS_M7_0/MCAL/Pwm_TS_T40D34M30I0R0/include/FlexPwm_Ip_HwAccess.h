/*==================================================================================================
* Project              : RTD AUTOSAR 4.7
* Platform             : CORTEXM
* Peripheral           : Emios Flexio FlexPwm
* Dependencies         : none
*
* Autosar Version      : 4.7.0
* Autosar Revision     : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version           : 3.0.0
* Build Version        : S32K3_RTD_3_0_0_P10_D2307_ASR_REL_4_7_REV_0000_20230726
*
* Copyright 2020 - 2023 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef FLEXPWM_IP_HWACCESS_H
#define FLEXPWM_IP_HWACCESS_H

/**
*   @file       FlexPwm_Ip_HwAccess.h
*
*   @addtogroup flexpwm_ip FlexPwm IPL
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/

#include "Std_Types.h"
#include "FlexPwm_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXPWM_IP_HWACCESS_VENDOR_ID                    43
#define FLEXPWM_IP_HWACCESS_MODULE_ID                    121
#define FLEXPWM_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION     4
#define FLEXPWM_IP_HWACCESS_AR_RELEASE_MINOR_VERSION     7
#define FLEXPWM_IP_HWACCESS_AR_RELEASE_REVISION_VERSION  0
#define FLEXPWM_IP_HWACCESS_SW_MAJOR_VERSION             3
#define FLEXPWM_IP_HWACCESS_SW_MINOR_VERSION             0
#define FLEXPWM_IP_HWACCESS_SW_PATCH_VERSION             0


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Std_Types.h are of the same AUTOSAR version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FLEXPWM_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXPWM_IP_HWACCESS_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of FlexPwm_Ip_HwAccess.h and Std_Types.h are different."
    #endif
#endif

/* Check if header file and FlexPwm_Ip_Cfg header file are of the same vendor */
#if (FLEXPWM_IP_HWACCESS_VENDOR_ID != FLEXPWM_IP_CFG_VENDOR_ID)
    #error "Vendor IDs of FlexPwm_Ip_Cfg_HwAccess.h and FlexPwm_Ip_Cfg.h are different."
#endif

/* Check if header file and FlexPwm_Ip_Cfg header file are of the same AUTOSAR version */
#if ((FLEXPWM_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION    != FLEXPWM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXPWM_IP_HWACCESS_AR_RELEASE_MINOR_VERSION    != FLEXPWM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXPWM_IP_HWACCESS_AR_RELEASE_REVISION_VERSION != FLEXPWM_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of FlexPwm_Ip_Cfg_HwAccess.h and FlexPwm_Ip_Cfg.h are different."
#endif

/* Check if header file and FlexPwm_Ip_Cfg header file are of the same software version */
#if ((FLEXPWM_IP_HWACCESS_SW_MAJOR_VERSION != FLEXPWM_IP_CFG_SW_MAJOR_VERSION) || \
     (FLEXPWM_IP_HWACCESS_SW_MINOR_VERSION != FLEXPWM_IP_CFG_SW_MINOR_VERSION) || \
     (FLEXPWM_IP_HWACCESS_SW_PATCH_VERSION != FLEXPWM_IP_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of FlexPwm_Ip_Cfg_HwAccess.h and FlexPwm_Ip_Cfg.h are different."
#endif

#if (FLEXPWM_IP_AVAILABLE == STD_ON)
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
#define FLEXPWM_OUTEN_MASK              0xFFFU
#define FLEXPWM_IP_SUBMOD_0             0x00U
#define FLEXPWM_IP_SUBMOD_1             0x01U
#define FLEXPWM_IP_SUBMOD_2             0x02U
#define FLEXPWM_IP_SUBMOD_3             0x03U

#ifdef  FLEXPWM_AE_IP_HW
    #define FLEXPWM_IP_INS_1            0x00U
    #define FLEXPWM_IP_INS_2            0x01U	
#else
    #define FLEXPWM_IP_INS_0            0x00U	
    #define FLEXPWM_IP_INS_1            0x01U
#endif

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define PWM_START_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"

/*! @brief Arrays of Base addresses for FlexPwm instances. */
extern FlexPwm_Ip_HwAddrType * const FlexPwm_Ip_aBasePtr[FLEXPWM_IP_INSTANCE_COUNT];

#define PWM_STOP_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"
/*==================================================================================================
*                                       LOCAL FUNCTION
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetDeadTimeHw
 * Description   : Updates the value used for the dead time logic in terms of clock cycles.
 *
 * Implements    : FlexPwm_Ip_SetDeadTimeHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetDeadTimeHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, FlexPwm_Ip_DeadTimeCountTypes DeadCntType, uint16 DeadCntVal)
{
    #ifdef FLEXPWM_AE_IP_HW
    switch(DeadCntType)
    {
        case FLEXPWM_IP_DEADTIME_COUNT_0:
            Base->SUB[SubModule].DTCNT0 = (Base->SUB[SubModule].DTCNT0 & ~(FLEXPWM_DTCNT0_DTCNT0_MASK)) | FLEXPWM_DTCNT0_DTCNT0(DeadCntVal);
            break;
        case FLEXPWM_IP_DEADTIME_COUNT_1:
            Base->SUB[SubModule].DTCNT1 = (Base->SUB[SubModule].DTCNT1 & ~(FLEXPWM_DTCNT1_DTCNT1_MASK)) | FLEXPWM_DTCNT1_DTCNT1(DeadCntVal);
            break;
        default:
            /* Do nothing */
            break;
    }
    #else
    switch(DeadCntType)
    {
        case FLEXPWM_IP_DEADTIME_COUNT_0:
            Base->SM[SubModule].SMDTCNT0 = (Base->SM[SubModule].SMDTCNT0 & ~(FLEXPWM_SMDTCNT0_DTCNT0_MASK)) | FLEXPWM_SMDTCNT0_DTCNT0(DeadCntVal);
            break;
        case FLEXPWM_IP_DEADTIME_COUNT_1:
            Base->SM[SubModule].SMDTCNT1 = (Base->SM[SubModule].SMDTCNT1 & ~(FLEXPWM_SMDTCNT1_DTCNT1_MASK)) | FLEXPWM_SMDTCNT1_DTCNT1(DeadCntVal);
            break;
        default:
            /* Do nothing */
            break;
    }
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetClockSrcHw
 * Description   : Updates Clock source select. (CTRL2 register)
 *
 * Implements    : FlexPwm_Ip_SetClockSrcHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetClockSrcHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, FlexPwm_Ip_ClockSourceTypes ClkSrc)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->SUB[SubModule].CTRL2 = (Base->SUB[SubModule].CTRL2 & ~(FLEXPWM_CTRL2_CLK_SEL_MASK)) | FLEXPWM_CTRL2_CLK_SEL(ClkSrc);
    #else
    Base->SM[SubModule].SMCTRL2 = (Base->SM[SubModule].SMCTRL2 & ~(FLEXPWM_SMCTRL2_CLK_SEL_MASK)) | FLEXPWM_SMCTRL2_CLK_SEL(ClkSrc);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetInitSrcHw
 * Description   : Update the source of the INIT signal which goes to the counter. (CTRL2 register)
 *
 * Implements    : FlexPwm_Ip_SetInitSrcHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetInitSrcHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, FlexPwm_Ip_InitControlSelTypes InitCtrl)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->SUB[SubModule].CTRL2 = (Base->SUB[SubModule].CTRL2 & ~(FLEXPWM_CTRL2_INIT_SEL_MASK)) | FLEXPWM_CTRL2_INIT_SEL(InitCtrl);
    #else
    Base->SM[SubModule].SMCTRL2 = (Base->SM[SubModule].SMCTRL2 & ~(FLEXPWM_SMCTRL2_INIT_SEL_MASK)) | FLEXPWM_SMCTRL2_INIT_SEL(InitCtrl);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetReloadSrcHw
 * Description   : Updates the source of the RELOAD signal. (CTRL2 register)
 *
 * Implements    : FlexPwm_Ip_SetReloadSrcHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetReloadSrcHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, FlexPwm_Ip_ReloadSourceSelTypes ReloadSrc)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->SUB[SubModule].CTRL2 = (Base->SUB[SubModule].CTRL2 & ~(FLEXPWM_CTRL2_RELOAD_SEL_MASK)) | FLEXPWM_CTRL2_RELOAD_SEL(ReloadSrc);
    #else
    Base->SM[SubModule].SMCTRL2 = (Base->SM[SubModule].SMCTRL2 & ~(FLEXPWM_SMCTRL2_RELOAD_SEL_MASK)) | FLEXPWM_SMCTRL2_RELOAD_SEL(ReloadSrc);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetForceSrcHw
 * Description   : Update the source of the FORCE OUTPUT signal. (CTRL2 register)
 *
 * Implements    : FlexPwm_Ip_SetForceSrcHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetForceSrcHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, FlexPwm_Ip_ForceSourceSelTypes ForceSrc)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->SUB[SubModule].CTRL2 = (Base->SUB[SubModule].CTRL2 & ~(FLEXPWM_CTRL2_FORCE_SEL_MASK)) | FLEXPWM_CTRL2_FORCE_SEL(ForceSrc);
    #else
    Base->SM[SubModule].SMCTRL2 = (Base->SM[SubModule].SMCTRL2 & ~(FLEXPWM_SMCTRL2_FORCE_SEL_MASK)) | FLEXPWM_SMCTRL2_FORCE_SEL(ForceSrc);        
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetPairHw
 * Description   : The PWMA and PWMB channels will be independent PWMs or a complementary PWM pair. (CTRL2 register)
 *
 * Implements    : FlexPwm_Ip_SetPairHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetPairHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, FlexPwm_Ip_ChannelPairTypes PairEn)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->SUB[SubModule].CTRL2 = (Base->SUB[SubModule].CTRL2 & ~(FLEXPWM_CTRL2_INDEP_MASK)) | FLEXPWM_CTRL2_INDEP(PairEn);
    #else
    Base->SM[SubModule].SMCTRL2 = (Base->SM[SubModule].SMCTRL2 & ~(FLEXPWM_SMCTRL2_INDEP_MASK)) | FLEXPWM_SMCTRL2_INDEP(PairEn);       
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetDebugModeHw
 * Description   : Set Debug mode. (CTRL2 register)
 *
 * Implements    : FlexPwm_Ip_SetDebugModeHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetDebugModeHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, uint8 DebugMode)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->SUB[SubModule].CTRL2 = (Base->SUB[SubModule].CTRL2 & ~(FLEXPWM_CTRL2_DBGEN_MASK)) | FLEXPWM_CTRL2_DBGEN(DebugMode);
    #else
    Base->SM[SubModule].SMCTRL2 = (Base->SM[SubModule].SMCTRL2 & ~(FLEXPWM_SMCTRL2_DBGEN_MASK)) | FLEXPWM_SMCTRL2_DBGEN(DebugMode);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetForceInitEnHw
 * Description   : Force Initialization Enable (CTRL2 register)
 *
 * Implements    : FlexPwm_Ip_SetForceInitEnHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetForceInitEnHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, uint8 Val)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->SUB[SubModule].CTRL2 = (Base->SUB[SubModule].CTRL2 & ~(FLEXPWM_CTRL2_FRCEN_MASK)) | FLEXPWM_CTRL2_FRCEN(Val);
    #else
    Base->SM[SubModule].SMCTRL2 = (Base->SM[SubModule].SMCTRL2 & ~(FLEXPWM_SMCTRL2_FRCEN_MASK)) | FLEXPWM_SMCTRL2_FRCEN(Val);        
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetInitialValHw
 * Description   : Determines the initial value for PWMX/A/B (CTRL2 register)
 *
 * Implements    : FlexPwm_Ip_SetInitialValHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetInitialValHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, FlexPwm_Ip_ChannelTypes Channel, uint8 Val)
{
    #ifdef FLEXPWM_AE_IP_HW
    switch(Channel)
    {
        case FLEXPWM_IP_PWMX:
            Base->SUB[SubModule].CTRL2 = (Base->SUB[SubModule].CTRL2 & ~(FLEXPWM_CTRL2_PWMX_INIT_MASK)) | FLEXPWM_CTRL2_PWMX_INIT(Val);
            break;
        case FLEXPWM_IP_PWMA:
            Base->SUB[SubModule].CTRL2 = (Base->SUB[SubModule].CTRL2 & ~(FLEXPWM_CTRL2_PWM23_INIT_MASK)) | FLEXPWM_CTRL2_PWM23_INIT(Val);
            break;
        case FLEXPWM_IP_PWMB:
            Base->SUB[SubModule].CTRL2 = (Base->SUB[SubModule].CTRL2 & ~(FLEXPWM_CTRL2_PWM45_INIT_MASK)) | FLEXPWM_CTRL2_PWM45_INIT(Val);
            break;
        default:
            /* Do nothing */
            break;
    }
    #else
    switch(Channel)
    {
        case FLEXPWM_IP_PWMX:
            Base->SM[SubModule].SMCTRL2 = (Base->SM[SubModule].SMCTRL2 & ~(FLEXPWM_SMCTRL2_PWMX_INIT_MASK)) | FLEXPWM_SMCTRL2_PWMX_INIT(Val);
            break;
        case FLEXPWM_IP_PWMA:
            Base->SM[SubModule].SMCTRL2 = (Base->SM[SubModule].SMCTRL2 & ~(FLEXPWM_SMCTRL2_PWM23_INIT_MASK)) | FLEXPWM_SMCTRL2_PWM23_INIT(Val);
            break;
        case FLEXPWM_IP_PWMB:
            Base->SM[SubModule].SMCTRL2 = (Base->SM[SubModule].SMCTRL2 & ~(FLEXPWM_SMCTRL2_PWM45_INIT_MASK)) | FLEXPWM_SMCTRL2_PWM45_INIT(Val);
            break;
        default:
            /* Do nothing */
            break;
    }
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetForceInitHw
 * Description   : Force Initialization (CTRL2 register)
 *
 * Implements    : FlexPwm_Ip_SetForceInitHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetForceInitHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, uint8 Val)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->SUB[SubModule].CTRL2 = (Base->SUB[SubModule].CTRL2 & ~(FLEXPWM_CTRL2_FORCE_MASK)) | FLEXPWM_CTRL2_FORCE(Val);
    #else
    Base->SM[SubModule].SMCTRL2 = (Base->SM[SubModule].SMCTRL2 & ~(FLEXPWM_SMCTRL2_FORCE_MASK)) | FLEXPWM_SMCTRL2_FORCE(Val);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetPrescalerHw
 * Description   : Selects the divide ratio of the PWM clock frequency. (CTRL1 register)
 *
 * Implements    : FlexPwm_Ip_SetPrescalerHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetPrescalerHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, FlexPwm_Ip_PrescalerTypes Prescaler)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->SUB[SubModule].CTRL1 = (Base->SUB[SubModule].CTRL1 & ~(FLEXPWM_CTRL1_PRSC_MASK)) | FLEXPWM_CTRL1_PRSC(Prescaler);
    #else
    Base->SM[SubModule].SMCTRL = (Base->SM[SubModule].SMCTRL & ~(FLEXPWM_SMCTRL_PRSC_MASK)) | FLEXPWM_SMCTRL_PRSC(Prescaler);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetLoadModeHw
 * Description   : Selects the timing of loading the buffered registers for this submodule. (CTRL1 register)
 *
 * Implements    : FlexPwm_Ip_SetLoadModeHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetLoadModeHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, uint8 Val)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->SUB[SubModule].CTRL1 = (Base->SUB[SubModule].CTRL1 & ~(FLEXPWM_CTRL1_LDMOD_MASK)) | FLEXPWM_CTRL1_LDMOD(Val);
    #else
    Base->SM[SubModule].SMCTRL = (Base->SM[SubModule].SMCTRL & ~(FLEXPWM_SMCTRL_LDMOD_MASK)) | FLEXPWM_SMCTRL_LDMOD(Val);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetReloadTypesHw
 * Description   : Select the options how to load the buffered-registers with new values. (CTRL1 register)
 *
 * Implements    : FlexPwm_Ip_SetReloadTypesHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetReloadTypesHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, FlexPwm_Ip_ReloadTypes Reload)
{
    #ifdef FLEXPWM_AE_IP_HW
    switch(Reload)
    {
        case FLEXPWM_IP_RELOAD_IMMEDIATE:
            Base->SUB[SubModule].CTRL1 = (Base->SUB[SubModule].CTRL1 & ~(FLEXPWM_CTRL1_FULL_MASK)) | FLEXPWM_CTRL1_FULL(0U);
            Base->SUB[SubModule].CTRL1 = (Base->SUB[SubModule].CTRL1 & ~(FLEXPWM_CTRL1_HALF_MASK)) | FLEXPWM_CTRL1_HALF(0U);
            break;
        case FLEXPWM_IP_RELOAD_FULL:
            Base->SUB[SubModule].CTRL1 = (Base->SUB[SubModule].CTRL1 & ~(FLEXPWM_CTRL1_FULL_MASK)) | FLEXPWM_CTRL1_FULL(1U);
            Base->SUB[SubModule].CTRL1 = (Base->SUB[SubModule].CTRL1 & ~(FLEXPWM_CTRL1_HALF_MASK)) | FLEXPWM_CTRL1_HALF(0U);
            break;
        case FLEXPWM_IP_RELOAD_HALF:
            Base->SUB[SubModule].CTRL1 = (Base->SUB[SubModule].CTRL1 & ~(FLEXPWM_CTRL1_FULL_MASK)) | FLEXPWM_CTRL1_FULL(0U);
            Base->SUB[SubModule].CTRL1 = (Base->SUB[SubModule].CTRL1 & ~(FLEXPWM_CTRL1_HALF_MASK)) | FLEXPWM_CTRL1_HALF(1U);
            break;
        case FLEXPWM_IP_RELOAD_FULL_HALF:
            Base->SUB[SubModule].CTRL1 = (Base->SUB[SubModule].CTRL1 & ~(FLEXPWM_CTRL1_FULL_MASK)) | FLEXPWM_CTRL1_FULL(1U);
            Base->SUB[SubModule].CTRL1 = (Base->SUB[SubModule].CTRL1 & ~(FLEXPWM_CTRL1_HALF_MASK)) | FLEXPWM_CTRL1_HALF(1U);
            break;
        default:
            /* Do nothing */
            break;
    }
    #else
    switch(Reload)
    {
        case FLEXPWM_IP_RELOAD_IMMEDIATE:
            Base->SM[SubModule].SMCTRL = (Base->SM[SubModule].SMCTRL & ~(FLEXPWM_SMCTRL_FULL_MASK)) | FLEXPWM_SMCTRL_FULL(0U);
            Base->SM[SubModule].SMCTRL = (Base->SM[SubModule].SMCTRL & ~(FLEXPWM_SMCTRL_HALF_MASK)) | FLEXPWM_SMCTRL_HALF(0U);
            break;
        case FLEXPWM_IP_RELOAD_FULL:
            Base->SM[SubModule].SMCTRL = (Base->SM[SubModule].SMCTRL & ~(FLEXPWM_SMCTRL_FULL_MASK)) | FLEXPWM_SMCTRL_FULL(1U);
            Base->SM[SubModule].SMCTRL = (Base->SM[SubModule].SMCTRL & ~(FLEXPWM_SMCTRL_HALF_MASK)) | FLEXPWM_SMCTRL_HALF(0U);
            break;
        case FLEXPWM_IP_RELOAD_HALF:
            Base->SM[SubModule].SMCTRL = (Base->SM[SubModule].SMCTRL & ~(FLEXPWM_SMCTRL_FULL_MASK)) | FLEXPWM_SMCTRL_FULL(0U);
            Base->SM[SubModule].SMCTRL = (Base->SM[SubModule].SMCTRL & ~(FLEXPWM_SMCTRL_HALF_MASK)) | FLEXPWM_SMCTRL_HALF(1U);
            break;
        case FLEXPWM_IP_RELOAD_FULL_HALF:
            Base->SM[SubModule].SMCTRL = (Base->SM[SubModule].SMCTRL & ~(FLEXPWM_SMCTRL_FULL_MASK)) | FLEXPWM_SMCTRL_FULL(1U);
            Base->SM[SubModule].SMCTRL = (Base->SM[SubModule].SMCTRL & ~(FLEXPWM_SMCTRL_HALF_MASK)) | FLEXPWM_SMCTRL_HALF(1U);
            break;
        default:
            /* Do nothing */
            break;
    }
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetLoadFrqHw
 * Description   : Selects the PWM load frequency. (CTRL1 register)
 *
 * Implements    : FlexPwm_Ip_SetLoadFrqHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetLoadFrqHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, FlexPwm_Ip_LoadFrequencyTypes LoadFrq)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->SUB[SubModule].CTRL1 = (Base->SUB[SubModule].CTRL1 & ~(FLEXPWM_CTRL1_LDFQ_MASK)) | FLEXPWM_CTRL1_LDFQ(LoadFrq);
    #else
    Base->SM[SubModule].SMCTRL = (Base->SM[SubModule].SMCTRL & ~(FLEXPWM_SMCTRL_LDFQ_MASK)) | FLEXPWM_SMCTRL_LDFQ(LoadFrq);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetFaultLevelHw
 * Description   : Select the active logic level of the individual fault inputs (FCTRL register)
 *
 * Implements    : FlexPwm_Ip_SetFaultLevelHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetFaultLevelHw(FlexPwm_Ip_HwAddrType *const Base, uint8 Value)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->FCTRL = (Base->FCTRL & ~(FLEXPWM_FCTRL_FLVL_MASK)) | FLEXPWM_FCTRL_FLVL(Value);
    #else
    Base->FAULT[0].FCTRL = (Base->FAULT[0].FCTRL & ~(FLEXPWM_FCTRL_FLVL_MASK)) | FLEXPWM_FCTRL_FLVL(Value);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetAutoFltClrHw
 * Description   : Select automatic or manual clearing of faults. (FCTRL register)
 *
 * Implements    : FlexPwm_Ip_SetAutoFltClrHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetAutoFltClrHw(FlexPwm_Ip_HwAddrType *const Base, uint8 Value)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->FCTRL = (Base->FCTRL & ~(FLEXPWM_FCTRL_FAUTO_MASK)) | FLEXPWM_FCTRL_FAUTO(Value);
    #else
    Base->FAULT[0].FCTRL = (Base->FAULT[0].FCTRL & ~(FLEXPWM_FCTRL_FAUTO_MASK)) | FLEXPWM_FCTRL_FAUTO(Value);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetFltSafeModeHw
 * Description   : Select the safety mode during manual fault clearing. (FCTRL register)
 *
 * Implements    : FlexPwm_Ip_SetFltSafeModeHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetFltSafeModeHw(FlexPwm_Ip_HwAddrType *const Base, uint8 Value)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->FCTRL = (Base->FCTRL & ~(FLEXPWM_FCTRL_FSAFE_MASK)) | FLEXPWM_FCTRL_FSAFE(Value);
    #else
    Base->FAULT[0].FCTRL = (Base->FAULT[0].FCTRL & ~(FLEXPWM_FCTRL_FSAFE_MASK)) | FLEXPWM_FCTRL_FSAFE(Value);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetFltInterruptHw
 * Description   : Enables/Disables CPU interrupt requests generated by the FAULTx pins. (FCTRL register)
 *
 * Implements    : FlexPwm_Ip_SetFltInterruptHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetFltInterruptHw(FlexPwm_Ip_HwAddrType *const Base, uint8 Value)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->FCTRL = (Base->FCTRL & ~(FLEXPWM_FCTRL_FIE_MASK)) | FLEXPWM_FCTRL_FIE(Value);
    #else
    Base->FAULT[0].FCTRL = (Base->FAULT[0].FCTRL & ~(FLEXPWM_FCTRL_FIE_MASK)) | FLEXPWM_FCTRL_FIE(Value);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_GetFltIntEnHw
 * Description   : Get the Fault Interrupt Enable. (FCTRL register)
 *
 * Implements    : FlexPwm_Ip_GetFltIntEnHw
 *END**************************************************************************/
static inline uint8 FlexPwm_Ip_GetFltIntEnHw(const FlexPwm_Ip_HwAddrType *const Base)
{
    #ifdef FLEXPWM_AE_IP_HW
    return ((Base->FCTRL & FLEXPWM_FCTRL_FIE_MASK) >> FLEXPWM_FCTRL_FIE_SHIFT);
    #else
    return ((Base->FAULT[0].FCTRL & FLEXPWM_FCTRL_FIE_MASK) >> FLEXPWM_FCTRL_FIE_SHIFT);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetFltFullCycleHw
 * Description   : Control the timing for re-enabling the PWM outputs after a fault condition. (FSTS register)
 *
 * Implements    : FlexPwm_Ip_SetFltFullCycleHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetFltFullCycleHw(FlexPwm_Ip_HwAddrType *const Base, uint8 Value)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->FSTS = (Base->FSTS & ~(FLEXPWM_FSTS_FFULL_MASK)) | FLEXPWM_FSTS_FFULL(Value);
    #else
    Base->FAULT[0].FSTS = (Base->FAULT[0].FSTS & ~(FLEXPWM_FSTS_FFULL_MASK)) | FLEXPWM_FSTS_FFULL(Value);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_GetFltIntFlagHw
 * Description   : Get the Fault Flags. (FSTS register)
 *
 * Implements    : FlexPwm_Ip_GetFltIntFlagHw
 *END**************************************************************************/
static inline uint8 FlexPwm_Ip_GetFltIntFlagHw(const FlexPwm_Ip_HwAddrType *const Base)
{
    #ifdef FLEXPWM_AE_IP_HW
    return ((Base->FSTS & FLEXPWM_FSTS_FFLAG_MASK) >> FLEXPWM_FSTS_FFLAG_SHIFT);
    #else
    return ((Base->FAULT[0].FSTS & FLEXPWM_FSTS_FFLAG_MASK) >> FLEXPWM_FSTS_FFLAG_SHIFT);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_ClearFaultFlagHw
 * Description   : Clears the fault interrupt flags based on the mask provided. (FSTS register)
 *
 * Implements    : FlexPwm_Ip_ClearFaultFlagHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_ClearFaultFlagHw(FlexPwm_Ip_HwAddrType *const Base, uint8 FltFlag)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->FSTS |= FLEXPWM_FSTS_FFLAG(FltFlag);
    #else
    Base->FAULT[0].FSTS |= FLEXPWM_FSTS_FFLAG(FltFlag);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetCombPathHw
 * Description   : Control the combinational path from the fault inputs to the PWM outputs. (FCTRL2 register)
 *
 * Implements    : FlexPwm_Ip_SetCombPathHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetCombPathHw(FlexPwm_Ip_HwAddrType *const Base, uint8 Value)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->FCTRL2 = (Base->FCTRL2 & ~(FLEXPWM_FCTRL2_NOCOMB_MASK)) | FLEXPWM_FCTRL2_NOCOMB(Value);
    #else
    Base->FAULT[0].FCTRL2 = (Base->FAULT[0].FCTRL2 & ~(FLEXPWM_FCTRL2_NOCOMB_MASK)) | FLEXPWM_FCTRL2_NOCOMB(Value);
    #endif  
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetFltGlitHw
 * Description   : Enable the fault glitch stretching logic (FFILT register)
 *
 * Implements    : FlexPwm_Ip_SetFltGlitHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetFltGlitHw(FlexPwm_Ip_HwAddrType *const Base, uint8 Value)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->FFILT = (Base->FFILT & ~(FLEXPWM_FFILT_GSTR_MASK)) | FLEXPWM_FFILT_GSTR(Value);
    #else
    Base->FAULT[0].FFILT = (Base->FAULT[0].FFILT & ~(FLEXPWM_FFILT_GSTR_MASK)) | FLEXPWM_FFILT_GSTR(Value);
    #endif 
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetFltFilterCntHw
 * Description   : Represents the number of consecutive samples (FFILT register)
 *
 * Implements    : FlexPwm_Ip_SetFltFilterCntHw 
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetFltFilterCntHw(FlexPwm_Ip_HwAddrType *const Base, uint8 Value)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->FFILT = (Base->FFILT & ~(FLEXPWM_FFILT_FILT_CNT_MASK)) | FLEXPWM_FFILT_FILT_CNT(Value);
    #else
    Base->FAULT[0].FFILT = (Base->FAULT[0].FFILT & ~(FLEXPWM_FFILT_FILT_CNT_MASK )) | FLEXPWM_FFILT_FILT_CNT(Value);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetFltFilterPerHw
 * Description   : Represent the sampling period (FFILT register)
 *
 * Implements    : FlexPwm_Ip_SetFltFilterPerHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetFltFilterPerHw(FlexPwm_Ip_HwAddrType *const Base, uint8 Value)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->FFILT = (Base->FFILT & ~(FLEXPWM_FFILT_FILT_PER_MASK)) | FLEXPWM_FFILT_FILT_PER(Value);
    #else
    Base->FAULT[0].FFILT = (Base->FAULT[0].FFILT & ~(FLEXPWM_FFILT_FILT_PER_MASK)) | FLEXPWM_FFILT_FILT_PER(Value);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetChFltStateHw
 * Description   : The fault state for the channels output during fault conditions. (OCTRL register)
 *
 * Implements    : FlexPwm_Ip_SetChFltStateHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetChFltStateHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, FlexPwm_Ip_ChannelTypes Channel, FlexPwm_Ip_FaultStateChTypes FltState)
{
    #ifdef FLEXPWM_AE_IP_HW
    switch(Channel)
    {
        case FLEXPWM_IP_PWMX:
            Base->SUB[SubModule].OCTRL = (Base->SUB[SubModule].OCTRL & ~(FLEXPWM_OCTRL_PWMXFS_MASK)) | FLEXPWM_OCTRL_PWMXFS(FltState);
            break;
        case FLEXPWM_IP_PWMA:
            Base->SUB[SubModule].OCTRL = (Base->SUB[SubModule].OCTRL & ~(FLEXPWM_OCTRL_PWMAFS_MASK)) | FLEXPWM_OCTRL_PWMAFS(FltState);
            break;
        case FLEXPWM_IP_PWMB:
            Base->SUB[SubModule].OCTRL = (Base->SUB[SubModule].OCTRL & ~(FLEXPWM_OCTRL_PWMBFS_MASK)) | FLEXPWM_OCTRL_PWMBFS(FltState);
            break;
        default:
            /* Do nothing */
            break;
    }
    #else
    switch(Channel)
    {
        case FLEXPWM_IP_PWMX:
            Base->SM[SubModule].SMOCTRL = (Base->SM[SubModule].SMOCTRL & ~(FLEXPWM_SMOCTRL_PWMXFS_MASK)) | FLEXPWM_SMOCTRL_PWMXFS(FltState);
            break;
        case FLEXPWM_IP_PWMA:
            Base->SM[SubModule].SMOCTRL = (Base->SM[SubModule].SMOCTRL & ~(FLEXPWM_SMOCTRL_PWMAFS_MASK)) | FLEXPWM_SMOCTRL_PWMAFS(FltState);
            break;
        case FLEXPWM_IP_PWMB:
            Base->SM[SubModule].SMOCTRL = (Base->SM[SubModule].SMOCTRL & ~(FLEXPWM_SMOCTRL_PWMBFS_MASK)) | FLEXPWM_SMOCTRL_PWMBFS(FltState);
            break;
        default:
            /* Do nothing */
            break;
    }
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetChFltDisableHw
 * Description   : Determines which PWM pins are disabled by the fault protection inputs (DISMAP register)
 *
 * Implements    : FlexPwm_Ip_SetChFltDisableHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetChFltDisableHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, FlexPwm_Ip_ChannelTypes Channel, uint8 FltChDis)
{
    #ifdef FLEXPWM_AE_IP_HW
    switch(Channel)
    {
        case FLEXPWM_IP_PWMX:
            Base->SUB[SubModule].DISMAP = (Base->SUB[SubModule].DISMAP & ~(FLEXPWM_DISMAP_DISX_MASK)) | FLEXPWM_DISMAP_DISX(FltChDis);
            break;
        case FLEXPWM_IP_PWMA:
            Base->SUB[SubModule].DISMAP = (Base->SUB[SubModule].DISMAP & ~(FLEXPWM_DISMAP_DISA_MASK)) | FLEXPWM_DISMAP_DISA(FltChDis);
            break;
        case FLEXPWM_IP_PWMB:
            Base->SUB[SubModule].DISMAP = (Base->SUB[SubModule].DISMAP & ~(FLEXPWM_DISMAP_DISB_MASK)) | FLEXPWM_DISMAP_DISB(FltChDis);
            break;
        default:
            /* Do nothing */
            break;
    }
    #else
    switch(Channel)
    {
        case FLEXPWM_IP_PWMX:
            Base->SM[SubModule].SMDISMAP0 = (Base->SM[SubModule].SMDISMAP0 & ~(FLEXPWM_SMDISMAP0_DIS0X_MASK)) | FLEXPWM_SMDISMAP0_DIS0X(FltChDis);
            break;
        case FLEXPWM_IP_PWMA:
            Base->SM[SubModule].SMDISMAP0 = (Base->SM[SubModule].SMDISMAP0 & ~(FLEXPWM_SMDISMAP0_DIS0A_MASK)) | FLEXPWM_SMDISMAP0_DIS0A(FltChDis);
            break;
        case FLEXPWM_IP_PWMB:
            Base->SM[SubModule].SMDISMAP0 = (Base->SM[SubModule].SMDISMAP0 & ~(FLEXPWM_SMDISMAP0_DIS0B_MASK)) | FLEXPWM_SMDISMAP0_DIS0B(FltChDis);
            break;
        default:
            /* Do nothing */
            break;
    }
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetInitialCountHw
 * Description   : Initial count value for the PWM in clock periods. (INIT register)
 *
 * Implements    : FlexPwm_Ip_SetInitialCountHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetInitialCountHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, uint16 Value)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->SUB[SubModule].INIT = (Base->SUB[SubModule].INIT & ~(FLEXPWM_INIT_INIT_MASK)) | FLEXPWM_INIT_INIT(Value);
    #else
    Base->SM[SubModule].SMINIT = (Base->SM[SubModule].SMINIT & ~(FLEXPWM_SMINIT_INIT_MASK)) | FLEXPWM_SMINIT_INIT(Value);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetVal0Hw
 * Description   : Set VAL0 (VAL0 register)
 *
 * Implements    : FlexPwm_Ip_SetVal0Hw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetVal0Hw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, uint16 Value)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->SUB[SubModule].VAL0 = (Base->SUB[SubModule].VAL0 & ~(FLEXPWM_VAL0_VAL0_MASK)) | FLEXPWM_VAL0_VAL0(Value);
    #else
    Base->SM[SubModule].SMVAL0 = (Base->SM[SubModule].SMVAL0 & ~(FLEXPWM_SMVAL0_VAL0_MASK)) | FLEXPWM_SMVAL0_VAL0(Value);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetVal1Hw
 * Description   : Set VAL1 (VAL1 register)
 *
 * Implements    : FlexPwm_Ip_SetVal1Hw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetVal1Hw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, uint16 Value)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->SUB[SubModule].VAL1 = (Base->SUB[SubModule].VAL1 & ~(FLEXPWM_VAL1_VAL1_MASK)) | FLEXPWM_VAL1_VAL1(Value);
    #else
    Base->SM[SubModule].SMVAL1 = (Base->SM[SubModule].SMVAL1 & ~(FLEXPWM_SMVAL1_VAL1_MASK)) | FLEXPWM_SMVAL1_VAL1(Value);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetVal2Hw
 * Description   : Set VAL2 (VAL2 register)
 *
 * Implements    : FlexPwm_Ip_SetVal2Hw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetVal2Hw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, uint16 Value)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->SUB[SubModule].VAL2 = (Base->SUB[SubModule].VAL2 & ~(FLEXPWM_VAL2_VAL2_MASK)) | FLEXPWM_VAL2_VAL2(Value);
    #else
    Base->SM[SubModule].SMVAL2 = (Base->SM[SubModule].SMVAL2 & ~(FLEXPWM_SMVAL2_VAL2_MASK)) | FLEXPWM_SMVAL2_VAL2(Value);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetVal3Hw
 * Description   : Set VAL3 (VAL3 register)
 *
 * Implements    : FlexPwm_Ip_SetVal3Hw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetVal3Hw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, uint16 Value)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->SUB[SubModule].VAL3 = (Base->SUB[SubModule].VAL3 & ~(FLEXPWM_VAL3_VAL3_MASK)) | FLEXPWM_VAL3_VAL3(Value);
    #else
    Base->SM[SubModule].SMVAL3 = (Base->SM[SubModule].SMVAL3 & ~(FLEXPWM_SMVAL3_VAL3_MASK)) | FLEXPWM_SMVAL3_VAL3(Value);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetVal4Hw
 * Description   : Set VAL4 (VAL4 register)
 *
 * Implements    : FlexPwm_Ip_SetVal4Hw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetVal4Hw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, uint16 Value)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->SUB[SubModule].VAL4 = (Base->SUB[SubModule].VAL4 & ~(FLEXPWM_VAL4_VAL4_MASK)) | FLEXPWM_VAL4_VAL4(Value);
    #else
    Base->SM[SubModule].SMVAL4 = (Base->SM[SubModule].SMVAL4 & ~(FLEXPWM_SMVAL4_VAL4_MASK)) | FLEXPWM_SMVAL4_VAL4(Value);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetVal5Hw
 * Description   : Set VAL5 (VAL5 register)
 *
 * Implements    : FlexPwm_Ip_SetVal5Hw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetVal5Hw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, uint16 Value)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->SUB[SubModule].VAL5 = (Base->SUB[SubModule].VAL5 & ~(FLEXPWM_VAL5_VAL5_MASK)) | FLEXPWM_VAL5_VAL5(Value);
    #else
    Base->SM[SubModule].SMVAL5 = (Base->SM[SubModule].SMVAL5 & ~(FLEXPWM_SMVAL5_VAL5_MASK)) | FLEXPWM_SMVAL5_VAL5(Value);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetPolarityHw
 * Description   : Set Polarity (OCTRL register)
 *
 * Implements    : FlexPwm_Ip_SetPolarityHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetPolarityHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, FlexPwm_Ip_ChannelTypes Channel, FlexPwm_Ip_PolarityTypes Pol)
{
    #ifdef FLEXPWM_AE_IP_HW
    switch(Channel)
    {
        case FLEXPWM_IP_PWMX:
            Base->SUB[SubModule].OCTRL = (Base->SUB[SubModule].OCTRL & ~(FLEXPWM_OCTRL_POLX_MASK)) | FLEXPWM_OCTRL_POLX(Pol);
            break;
        case FLEXPWM_IP_PWMA:
            Base->SUB[SubModule].OCTRL = (Base->SUB[SubModule].OCTRL & ~(FLEXPWM_OCTRL_POLA_MASK)) | FLEXPWM_OCTRL_POLA(Pol);
            break;
        case FLEXPWM_IP_PWMB:
            Base->SUB[SubModule].OCTRL = (Base->SUB[SubModule].OCTRL & ~(FLEXPWM_OCTRL_POLB_MASK)) | FLEXPWM_OCTRL_POLB(Pol);
            break;
        default:
            /* Do nothing */
            break;
    }
    #else
    switch(Channel)
    {
        case FLEXPWM_IP_PWMX:
            Base->SM[SubModule].SMOCTRL = (Base->SM[SubModule].SMOCTRL & ~(FLEXPWM_SMOCTRL_POLX_MASK)) | FLEXPWM_SMOCTRL_POLX(Pol);
            break;
        case FLEXPWM_IP_PWMA:
            Base->SM[SubModule].SMOCTRL = (Base->SM[SubModule].SMOCTRL & ~(FLEXPWM_SMOCTRL_POLA_MASK)) | FLEXPWM_SMOCTRL_POLA(Pol);
            break;
        case FLEXPWM_IP_PWMB:
            Base->SM[SubModule].SMOCTRL = (Base->SM[SubModule].SMOCTRL & ~(FLEXPWM_SMOCTRL_POLB_MASK)) | FLEXPWM_SMOCTRL_POLB(Pol);
            break;
        default:
            /* Do nothing */
            break;
    }
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetOutputTrigHw
 * Description   : Set Output trigger control (TCTRL register)
 *
 * Implements    : FlexPwm_Ip_SetOutputTrigHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetOutputTrigHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, FlexPwm_Ip_OuputTriggerTypes OutputTrig)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->SUB[SubModule].TCTRL = (Base->SUB[SubModule].TCTRL & ~((uint16)OutputTrig)) | FLEXPWM_TCTRL_OUT_TRIG_EN(OutputTrig);
    #else
    Base->SM[SubModule].SMTCTRL = (Base->SM[SubModule].SMTCTRL & ~((uint16)OutputTrig)) | FLEXPWM_SMTCTRL_OUT_TRIG_EN(OutputTrig);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetOutputEnHw
 * Description   : Enable/Disable the channel outputs of each instance. (OUTEN register)
 *
 * Implements    : FlexPwm_Ip_SetOutputEnHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetOutputEnHw(FlexPwm_Ip_HwAddrType *const Base, uint16 OutputEn)
{
    Base->OUTEN = (Base->OUTEN & ~(FLEXPWM_OUTEN_MASK)) | OutputEn;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_StartCounterHw
 * Description   : Enables the clocks to the PWM generator (MCTRL register)
 *
 * Implements    : FlexPwm_Ip_StartCounterHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_StartCounterHw(FlexPwm_Ip_HwAddrType *const Base, uint8 RunVal)
{
    Base->MCTRL |= FLEXPWM_MCTRL_RUN(RunVal);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_StopCounterHw
 * Description   : Disables the clocks to the PWM generator (MCTRL register)
 *
 * Implements    : FlexPwm_Ip_StopCounterHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_StopCounterHw(FlexPwm_Ip_HwAddrType *const Base, uint8 RunVal)
{
    Base->MCTRL &= ~FLEXPWM_MCTRL_RUN(RunVal);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetLoadOkayHw
 * Description   : Allow to load pre-scaler, modulus, and PWM values (MCTRL register)
 *
 * Implements    : FlexPwm_Ip_SetLoadOkayHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetLoadOkayHw(FlexPwm_Ip_HwAddrType *const Base, uint8 Val)
{
     Base->MCTRL |=  FLEXPWM_MCTRL_LDOK(Val);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_ClearLoadOkayHw
 * Description   : Clear load pre-scaler, modulus, and PWM values (MCTRL register)
 *
 * Implements    : FlexPwm_Ip_ClearLoadOkayHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_ClearLoadOkayHw(FlexPwm_Ip_HwAddrType *const Base, uint8 Val)
{
     Base->MCTRL |=  FLEXPWM_MCTRL_CLDOK(Val);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetSrcCompHw
 * Description   : Source selection for the generation of complementary PWM pair output. (MCTRL register)
 *
 * Implements    : FlexPwm_Ip_SetSrcCompHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetSrcCompHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, FlexPwm_Ip_SrcCompSelTypes SrcComp)
{
    switch(SrcComp)
    {
        case FLEXPWM_IP_COMP_SOURCE23:
            Base->MCTRL = (Base->MCTRL & ~(uint16)((1U << FLEXPWM_MCTRL_IPOL_SHIFT) << SubModule)) | (uint16)((0U << FLEXPWM_MCTRL_IPOL_SHIFT) << SubModule);
            break;
        case FLEXPWM_IP_COMP_SOURCE45:
            Base->MCTRL = (Base->MCTRL & ~(uint16)((1U << FLEXPWM_MCTRL_IPOL_SHIFT) << SubModule)) | (uint16)((1U << FLEXPWM_MCTRL_IPOL_SHIFT) << SubModule);
            break;
        default:
            /* Do Nothing */
            break;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetReloadIntHw
 * Description   : Enable/Disable Reload Interrupt (INTEN register)
 *
 * Implements    : FlexPwm_Ip_SetReloadIntHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetReloadIntHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, uint8 Val)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->SUB[SubModule].INTEN = (Base->SUB[SubModule].INTEN & ~(FLEXPWM_INTEN_RIE_MASK)) | FLEXPWM_INTEN_RIE(Val);
    #else
    Base->SM[SubModule].SMINTEN = (Base->SM[SubModule].SMINTEN & ~(FLEXPWM_SMINTEN_RIE_MASK)) | FLEXPWM_SMINTEN_RIE(Val);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetCompareIntHw
 * Description   : Enable Compare Interrupt (INTEN register)
 *
 * Implements    : FlexPwm_Ip_SetCompareIntHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetCompareIntHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, uint8 Val)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->SUB[SubModule].INTEN = (Base->SUB[SubModule].INTEN & ~(Val)) | FLEXPWM_INTEN_CMPIE(Val);
    #else
    Base->SM[SubModule].SMINTEN = (Base->SM[SubModule].SMINTEN & ~(FLEXPWM_SMINTEN_CMPIE_MASK)) | FLEXPWM_SMINTEN_CMPIE(Val);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_ClearCompareIntHw
 * Description   : Disable Compare Interrupt (INTEN register)
 *
 * Implements    : FlexPwm_Ip_ClearCompareIntHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_ClearCompareIntHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, uint8 Val)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->SUB[SubModule].INTEN &= ~FLEXPWM_INTEN_CMPIE(Val);
    #else
    Base->SM[SubModule].SMINTEN &= ~FLEXPWM_SMINTEN_CMPIE(Val);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_GetInterrupteCmpEnHw
 * Description   : Get the compare interrupt enable. (INTEN register)
 *
 * Implements    : FlexPwm_Ip_GetInterrupteCmpEnHw
 *END**************************************************************************/
static inline uint8 FlexPwm_Ip_GetInterrupteCmpEnHw(const FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule)
{
    #ifdef FLEXPWM_AE_IP_HW
    return ((Base->SUB[SubModule].INTEN & FLEXPWM_INTEN_CMPIE_MASK) >> FLEXPWM_INTEN_CMPIE_SHIFT);
    #else
    return ((Base->SM[SubModule].SMINTEN & FLEXPWM_SMINTEN_CMPIE_MASK) >> FLEXPWM_SMINTEN_CMPIE_SHIFT);
    #endif
}
/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_ClearInterruptReloadFlagHw
 * Description   : Clears the reload interrupt flags. (STS register)
 *
 * Implements    : FlexPwm_Ip_ClearInterruptReloadFlagHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_ClearInterruptReloadFlagHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->SUB[SubModule].STS |= FLEXPWM_STS_RF(1U);
    #else
    Base->SM[SubModule].SMSTS |= FLEXPWM_SMSTS_RF(1U);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_ClearInterruptCmpFlagHw
 * Description   : Clears the compare interrupt flags based on the mask provided. (STS register)
 *
 * Implements    : FlexPwm_Ip_ClearInterruptCmpFlagHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_ClearInterruptCmpFlagHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule, uint8 IntFlag)
{
    #ifdef FLEXPWM_AE_IP_HW
    Base->SUB[SubModule].STS = FLEXPWM_STS_CMPF(IntFlag);
    #else
    Base->SM[SubModule].SMSTS = FLEXPWM_SMSTS_CMPF(IntFlag);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_GetInterruptCmpFlagHw
 * Description   : Get the compare interrupt flags. (STS register)
 *
 * Implements    : FlexPwm_Ip_GetInterruptCmpFlagHw
 *END**************************************************************************/
static inline uint8 FlexPwm_Ip_GetInterruptCmpFlagHw(const FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule)
{
    #ifdef FLEXPWM_AE_IP_HW
    return ((Base->SUB[SubModule].STS & FLEXPWM_STS_CMPF_MASK) >> FLEXPWM_STS_CMPF_SHIFT);
    #else
    return ((Base->SM[SubModule].SMSTS & FLEXPWM_SMSTS_CMPF_MASK) >> FLEXPWM_SMSTS_CMPF_SHIFT);
    #endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexPwm_Ip_SetResetSubHw
 * Description   : Reset the submodule
 *
 * Implements    : FlexPwm_Ip_SetResetSubHw
 *END**************************************************************************/
static inline void FlexPwm_Ip_SetResetSubHw(FlexPwm_Ip_HwAddrType *const Base, uint8 SubModule)
{
    #ifdef FLEXPWM_AE_IP_HW
    #if (defined(PWM_FLEXPWM_AUTOSAR_MODE_IS_USED) && (STD_OFF == PWM_FLEXPWM_AUTOSAR_MODE_IS_USED))
    Base->MCTRL     = FLEXPWM_MCTRL_CLDOK_MASK;
    #endif

    Base->DTSRCSEL  = 0x0U;

    /* Clear the SubModule specific settings*/
    Base->SUB[SubModule].INIT       = 0x0U;
    /* Make sure that FLEXPWM_DTSRCSEL register is reset to its default value 0x0U. */
    Base->SUB[SubModule].CTRL2 &= (uint16)(~(FLEXPWM_CTRL2_FRCEN_MASK | FLEXPWM_CTRL2_FORCE_SEL_MASK));
    Base->SUB[SubModule].CTRL2 |= (uint16)FLEXPWM_CTRL2_FORCE_SEL(FLEXPWM_IP_LOCAL_FORCE);
    Base->SUB[SubModule].CTRL2 |= (uint16)FLEXPWM_CTRL2_FORCE(1U);

    Base->SUB[SubModule].CTRL1      = (uint16)(FLEXPWM_CTRL1_FULL_MASK | FLEXPWM_CTRL1_LDMOD_MASK);
    Base->SUB[SubModule].STS        = (uint16)FLEXPWM_STS_CMPF_MASK;
    Base->SUB[SubModule].INTEN      = 0x0U;
    Base->SUB[SubModule].TCTRL      = 0x0U;
    Base->SUB[SubModule].DISMAP     = (uint16)(FLEXPWM_DISMAP_DISA_MASK | FLEXPWM_DISMAP_DISB_MASK | FLEXPWM_DISMAP_DISX_MASK);
    Base->SUB[SubModule].DTCNT0     = FLEXPWM_DTCNT0_DTCNT0_MASK;
    Base->SUB[SubModule].DTCNT1     = FLEXPWM_DTCNT1_DTCNT1_MASK;

    Base->SUB[SubModule].CTRL1      = FLEXPWM_CTRL1_FULL_MASK;

    Base->MASK      = 0x0U;
    Base->SWCOUT    = 0x0U;
    Base->FSTS      = FLEXPWM_FSTS_FFLAG_MASK;
    Base->FFILT     = 0x0U;
    Base->FCTRL2    = 0x0U;

    #if (defined(PWM_FLEXPWM_AUTOSAR_MODE_IS_USED) && (STD_OFF == PWM_FLEXPWM_AUTOSAR_MODE_IS_USED))
    Base->SUB[SubModule].CTRL2      = 0x0U;
    Base->SUB[SubModule].VAL0       = 0x0U;
    Base->SUB[SubModule].VAL1       = 0x0U;
    Base->SUB[SubModule].VAL2       = 0x0U;
    Base->SUB[SubModule].VAL3       = 0x0U;
    Base->SUB[SubModule].VAL4       = 0x0U;
    Base->SUB[SubModule].VAL5       = 0x0U;
    Base->SUB[SubModule].OCTRL      = 0x0U;
    /* Set LDOK bits in order to load the buffered registers */
    Base->MCTRL                     = FLEXPWM_MCTRL_LDOK(1UL << SubModule);
    Base->OUTEN     = 0x0U;
    Base->FCTRL     = 0x0U;
    #endif /* PWM_FLEXPWM_AUTOSAR_MODE_IS_USED */

    #else /* FLEXPWM_AE_IP_HW */

    #if (defined(PWM_FLEXPWM_AUTOSAR_MODE_IS_USED) && (STD_OFF == PWM_FLEXPWM_AUTOSAR_MODE_IS_USED))
    Base->MCTRL     = FLEXPWM_MCTRL_CLDOK_MASK;
    #endif

    Base->DTSRCSEL  = 0x0U;

    /* Clear the SubModule specific settings*/
    Base->SM[SubModule].SMINIT       = 0x0U;
    /* Make sure that FLEXPWM_DTSRCSEL register is reset to its default value 0x0U. */
    Base->SM[SubModule].SMCTRL2 &= (uint16)(~(FLEXPWM_SMCTRL2_FRCEN_MASK | FLEXPWM_SMCTRL2_FORCE_SEL_MASK));
    Base->SM[SubModule].SMCTRL2 |= (uint16)FLEXPWM_SMCTRL2_FORCE_SEL(FLEXPWM_IP_LOCAL_FORCE);
    Base->SM[SubModule].SMCTRL2 |= (uint16)FLEXPWM_SMCTRL2_FORCE(1U);

    Base->SM[SubModule].SMCTRL       = (uint16)(FLEXPWM_SMCTRL_FULL_MASK | FLEXPWM_SMCTRL_LDMOD_MASK);

    Base->SM[SubModule].SMSTS        = (uint16)FLEXPWM_SMSTS_CMPF_MASK;
    Base->SM[SubModule].SMINTEN      = 0x0U;
    Base->SM[SubModule].SMTCTRL      = 0x0U;
    Base->SM[SubModule].SMDISMAP0    = (uint16)(FLEXPWM_SMDISMAP0_DIS0A_MASK | FLEXPWM_SMDISMAP0_DIS0B_MASK | FLEXPWM_SMDISMAP0_DIS0X_MASK);
    Base->SM[SubModule].SMDTCNT0     = FLEXPWM_SMDTCNT0_DTCNT0_MASK;
    Base->SM[SubModule].SMDTCNT1     = FLEXPWM_SMDTCNT1_DTCNT1_MASK;
    Base->SM[SubModule].SMCTRL       = FLEXPWM_SMCTRL_FULL_MASK;

    Base->MASK      = 0x0U;
    Base->SWCOUT    = 0x0U;
    Base->FAULT[0].FSTS      = FLEXPWM_FSTS_FFLAG_MASK;
    Base->FAULT[0].FFILT     = 0x0U;
    Base->FAULT[0].FCTRL2    = 0x0U;

    #if (defined(PWM_FLEXPWM_AUTOSAR_MODE_IS_USED) && (STD_OFF == PWM_FLEXPWM_AUTOSAR_MODE_IS_USED))
    Base->SM[SubModule].SMCTRL2      = 0x0U;
    Base->SM[SubModule].SMVAL0       = 0x0U;
    Base->SM[SubModule].SMVAL1       = 0x0U;
    Base->SM[SubModule].SMVAL2       = 0x0U;
    Base->SM[SubModule].SMVAL3       = 0x0U;
    Base->SM[SubModule].SMVAL4       = 0x0U;
    Base->SM[SubModule].SMVAL5       = 0x0U;
    Base->SM[SubModule].SMOCTRL      = 0x0U;
    Base->MCTRL                      = FLEXPWM_MCTRL_LDOK(1UL << SubModule);
    Base->OUTEN     = 0x0U;
    Base->FAULT[0].FCTRL     = 0x0U;
    #endif /* PWM_FLEXPWM_AUTOSAR_MODE_IS_USED */
    #endif /* FLEXPWM_AE_IP_HW */
}

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#endif /* (FLEXPWM_IP_AVAILABLE == STD_ON) */

#ifdef __cplusplus
}
#endif

/*! @}*/

#endif /* FLEXPWM_IP_HWACCESS_H */
