/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : FLEXIO_SENT_IP
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_P10_D2307_ASR_REL_4_7_REV_0000_20230726
*
*   Copyright 2020 - 2023 NXP Semiconductors NXP.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef FLEXIO_SENT_IP_HWACCESS_H
#define FLEXIO_SENT_IP_HWACCESS_H

/**
*   @file    Flexio_Sent_Ip_HwAccess.h
*   @version 3.0.0
*
*   @brief   AUTOSAR Sent - Low level header of Sent driver.
*   @details This file contains declarations of the functions defined by AutoSAR.
*
*   @addtogroup SENT_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Flexio_Mcl_Ip_HwAccess.h"
#include "Flexio_Sent_Ip_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FLEXIO_SENT_IP_HWACCESS_VENDOR_ID                      43
#define FLEXIO_SENT_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION       4
#define FLEXIO_SENT_IP_HWACCESS_AR_RELEASE_MINOR_VERSION       7
#define FLEXIO_SENT_IP_HWACCESS_AR_RELEASE_REVISION_VERSION    0
#define FLEXIO_SENT_IP_HWACCESS_SW_MAJOR_VERSION               3
#define FLEXIO_SENT_IP_HWACCESS_SW_MINOR_VERSION               0
#define FLEXIO_SENT_IP_HWACCESS_SW_PATCH_VERSION               0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Flexio_Sent_Ip_Cfg header file are of the same vendor */
#if (FLEXIO_SENT_IP_HWACCESS_VENDOR_ID != FLEXIO_SENT_IP_CFG_VENDOR_ID)
    #error "Flexio_Sent_Ip_HwAccess.h and Flexio_Sent_Ip_Cfg.h have different vendor ids" 
#endif
/* Check if current file and Flexio_Sent_Ip_Cfg header file are of the same Autosar version */
#if ((FLEXIO_SENT_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION    != FLEXIO_SENT_IP_CFG_AR_RELEASE_MAJOR_VERSION) ||    \
     (FLEXIO_SENT_IP_HWACCESS_AR_RELEASE_MINOR_VERSION    != FLEXIO_SENT_IP_CFG_AR_RELEASE_MINOR_VERSION) ||    \
     (FLEXIO_SENT_IP_HWACCESS_AR_RELEASE_REVISION_VERSION != FLEXIO_SENT_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Flexio_Sent_Ip_HwAccess.h and Flexio_Sent_Ip_Cfg.h are different" 
#endif
/* Check if current file and Flexio_Sent_Ip_Cfg header file are of the same Software version */
#if ((FLEXIO_SENT_IP_HWACCESS_SW_MAJOR_VERSION != FLEXIO_SENT_IP_CFG_SW_MAJOR_VERSION) || \
     (FLEXIO_SENT_IP_HWACCESS_SW_MINOR_VERSION != FLEXIO_SENT_IP_CFG_SW_MINOR_VERSION) || \
     (FLEXIO_SENT_IP_HWACCESS_SW_PATCH_VERSION != FLEXIO_SENT_IP_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Flexio_Sent_Ip_HwAccess.h and Flexio_Sent_Ip_Cfg.h are different" 
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Flexio_Sent_Ip_HwAccess.h file and Flexio_Mcl_Ip_HwAccess.h header file are of the same Autosar version */
    #if ((FLEXIO_SENT_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION    != FLEXIO_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_SENT_IP_HWACCESS_AR_RELEASE_MINOR_VERSION    != FLEXIO_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Flexio_Sent_Ip_HwAccess.h and Flexio_Mcl_Ip_HwAccess.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
 * FlexIO timer config register
 * This is a structure used by all FlexIO drivers as timer config value.
 * It is needed for parameter of set timer config register value.
 */
typedef struct
{
    Flexio_Mcl_Ip_TimerStartType Start;
    Flexio_Mcl_Ip_TimerStopType Stop;
    Flexio_Mcl_Ip_TimerEnableType Enable;
    Flexio_Mcl_Ip_TimerDisableType Disable;
    Flexio_Mcl_Ip_TimerResetType Reset;
    Flexio_Mcl_Ip_TimerDecrementType Decrement;
    Flexio_Mcl_Ip_TimerOutputType Output;
} Flexio_Sent_Ip_TimerConfig;

/**
 * FlexIO timer control register
 * This is a structure used by all FlexIO drivers as timer control value.
 * It is needed for parameter of set timer control register value.
 */
typedef struct
{
    uint8 Trigger;
    Flexio_Mcl_Ip_TriggerPolarityType TriggerPolarity;
    Flexio_Mcl_Ip_TriggerSourceType TriggerSource;
    uint8 Pin;
    Flexio_Mcl_Ip_PinPolarityType PinPolarity;
    Flexio_Mcl_Ip_PinConfigType PinConfig;
    Flexio_Mcl_Ip_TimerModeType Mode;
} Flexio_Sent_Ip_TimerControl;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/*
 * This function returns the number of TIMER of the FlexIO module
 */
static inline uint8 Flexio_Sent_Ip_GetTimerNum(const FLEXIO_Type *BaseAddr)
{
    uint32 Tmp = BaseAddr->PARAM;
    Tmp = (Tmp & FLEXIO_PARAM_TIMER_MASK) >> FLEXIO_PARAM_TIMER_SHIFT;
    return (uint8)Tmp;
}


/*
 * This function configures the mode for the specified timer.
 * In 8-bit counter mode, the lower 8-bits of the counter and compare register are used to
 * configure the baud rate of the timer shift clock and the upper 8-bits are used to configure
 * the shifter bit count.
 * In 8-bit PWM mode, the lower 8-bits of the counter and compare
 * register are used to configure the high period of the timer shift clock and the upper
 * 8-bits are used to configure the low period of the timer shift clock. The shifter bit count
 * is configured using another timer or external signal.
 * In 16-bit counter mode, the full 16-bits of the counter and compare register are used to
 * configure either the baud rate of the shift clock or the shifter bit count.
 */
static inline void Flexio_Sent_Ip_SetTimerMode(FLEXIO_Type *BaseAddr,
                                               uint8 Timer,
                                               Flexio_Mcl_Ip_TimerModeType Mode)
{
    uint32 Tmp = BaseAddr->TIMCTL[Timer];
    Tmp &= ~(FLEXIO_TIMCTL_TIMOD_MASK);
    Tmp |= FLEXIO_TIMCTL_TIMOD(Mode);
    BaseAddr->TIMCTL[Timer] = Tmp;
}

/*
 * This function get value of the mode for the specified timer.
 * In 8-bit counter mode, the lower 8-bits of the counter and compare register are used to
 * configure the baud rate of the timer shift clock and the upper 8-bits are used to configure
 * the shifter bit count.
 * In 8-bit PWM mode, the lower 8-bits of the counter and compare
 * register are used to configure the high period of the timer shift clock and the upper
 * 8-bits are used to configure the low period of the timer shift clock. The shifter bit count
 * is configured using another timer or external signal.
 * In 16-bit counter mode, the full 16-bits of the counter and compare register are used to
 * configure either the baud rate of the shift clock or the shifter bit count.
 */
static inline Flexio_Mcl_Ip_TimerModeType Flexio_Sent_Ip_GetTimerMode(const FLEXIO_Type *BaseAddr,
                                               uint8 Timer)
{
    uint32 Tmp = BaseAddr->TIMCTL[Timer];
    Tmp = ((Tmp & FLEXIO_TIMCTL_TIMOD_MASK) >> FLEXIO_TIMCTL_TIMOD_SHIFT);
    
    return (Flexio_Mcl_Ip_TimerModeType)Tmp;
}


/*
 * This function configures the control settings for the specified timer: mode settings, 
 * pin settings and trigger settings.
 */
static inline void Flexio_Sent_Ip_SetTimerControl(FLEXIO_Type *BaseAddr,
                                                  uint8 Timer,
                                                  const Flexio_Sent_Ip_TimerControl *TimerControl)
{
    BaseAddr->TIMCTL[Timer] = FLEXIO_TIMCTL_TIMOD(TimerControl->Mode)
                            | FLEXIO_TIMCTL_PINSEL(TimerControl->Pin)
                            | FLEXIO_TIMCTL_PINPOL(TimerControl->PinPolarity)
                            | FLEXIO_TIMCTL_PINCFG(TimerControl->PinConfig)
                            | FLEXIO_TIMCTL_TRGSRC(TimerControl->TriggerSource)
                            | FLEXIO_TIMCTL_TRGPOL(TimerControl->TriggerPolarity)
                            | FLEXIO_TIMCTL_TRGSEL(TimerControl->Trigger);
}
/*
 * This function returns the compare value currently set for the specified timer.
 */
static inline uint16 Flexio_Sent_Ip_GetTimerCompare(const FLEXIO_Type *BaseAddr, uint8 Timer)
{
    return (uint16)(BaseAddr->TIMCMP[Timer]);
}

/*
 * This function sets the following configurations for the specified timer:
 * start bit, stop bit, enable condition, disable condition, reset condition, 
 * decrement condition, initial output
 */
static inline void Flexio_Sent_Ip_SetTimerConfig(FLEXIO_Type *BaseAddr,
                                                 uint8 Timer,
                                                 const Flexio_Sent_Ip_TimerConfig *TimerConfig)
{

    BaseAddr->TIMCFG[Timer] = FLEXIO_TIMCFG_TSTART(TimerConfig->Start)
                            | FLEXIO_TIMCFG_TSTOP(TimerConfig->Stop)
                            | FLEXIO_TIMCFG_TIMENA(TimerConfig->Enable)
                            | FLEXIO_TIMCFG_TIMDIS(TimerConfig->Disable)
                            | FLEXIO_TIMCFG_TIMRST(TimerConfig->Reset)
                            | FLEXIO_TIMCFG_TIMDEC(TimerConfig->Decrement)
                            | FLEXIO_TIMCFG_TIMOUT(TimerConfig->Output);
}

/*
 * Enable or disable specified timer DMA requests. The request mask must contain a
 * bit of 1 for each timer who's DMA requests must be enabled or disabled.
 */
static inline void Flexio_Sent_Ip_SetTimerDMARequest(FLEXIO_Type *BaseAddr, uint8 requestMask, boolean enable)
{
    uint32 Tmp;

    Tmp = BaseAddr->TIMERSDEN;

    if (enable == TRUE)
    {
        Tmp |= requestMask;
    }
    else
    {
        Tmp &= ~(uint32)requestMask;
    }
    BaseAddr->TIMERSDEN = Tmp;
}

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_SENT_IP_HWACCESS_H */
