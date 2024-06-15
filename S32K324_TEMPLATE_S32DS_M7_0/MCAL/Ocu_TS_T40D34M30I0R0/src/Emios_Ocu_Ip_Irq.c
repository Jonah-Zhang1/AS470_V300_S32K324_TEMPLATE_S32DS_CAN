/*==================================================================================================
*     Project             : RTD AUTOSAR 4.7
*     Platform            : CORTEXM
*     Peripheral          : eMios
*     Dependencies        : none
*
*     Autosar Version     : 4.7.0
*     Autosar Revision    : ASR_REL_4_7_REV_0000
*     Autosar ConfVariant :
*     SWVersion           : 3.0.0
*     BuildVersion        : S32K3_RTD_3_0_0_P10_D2307_ASR_REL_4_7_REV_0000_20230726
*
*     Copyright 2020 - 2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/**
*   @file        Emios_Ocu_Ip_Irq.c
*
*   @addtogroup  ocu_ip Ocu IPL
*   @brief       Ocu eMIOS source file support for OCU driver.
*   @details     eMios source file support for OCU driver.
*
*   @{
*/
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/

#include "Emios_Ocu_Ip_Irq.h"
#include "Emios_Ocu_Ip_HwAccess.h"
#include "SchM_Ocu.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_OCU_IP_IRQ_VENDOR_ID_C                       43
#define EMIOS_OCU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C        4
#define EMIOS_OCU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C        7
#define EMIOS_OCU_IP_IRQ_AR_RELEASE_REVISION_VERSION_C     0
#define EMIOS_OCU_IP_IRQ_SW_MAJOR_VERSION_C                3
#define EMIOS_OCU_IP_IRQ_SW_MINOR_VERSION_C                0
#define EMIOS_OCU_IP_IRQ_SW_PATCH_VERSION_C                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (EMIOS_OCU_IP_IRQ_VENDOR_ID_C != EMIOS_OCU_IP_IRQ_VENDOR_ID)
    #error "Emios_Ocu_Ip_Irq.c and Emios_Ocu_Ip_Irq.h have different vendor ids"
#endif

/* Check if  source file and Emios_Ocu_Ip_Irq.h file are of the same Autosar version */
#if ((EMIOS_OCU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != EMIOS_OCU_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_OCU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != EMIOS_OCU_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_OCU_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != EMIOS_OCU_IP_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Ocu_Ip_Irq.c and Emios_Ocu_Ip_Irq.h are different"
#endif

/* Check if source file and Emios_Ocu_Ip_Irq.h file are of the same Software version */
#if ((EMIOS_OCU_IP_IRQ_SW_MAJOR_VERSION_C != EMIOS_OCU_IP_IRQ_SW_MAJOR_VERSION) || \
     (EMIOS_OCU_IP_IRQ_SW_MINOR_VERSION_C != EMIOS_OCU_IP_IRQ_SW_MINOR_VERSION) || \
     (EMIOS_OCU_IP_IRQ_SW_PATCH_VERSION_C != EMIOS_OCU_IP_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Ocu_Ip_Irq.c and Emios_Ocu_Ip_Irq.h are different"
#endif

#if (EMIOS_OCU_IP_IRQ_VENDOR_ID_C != EMIOS_OCU_IP_HWACCESS_VENDOR_ID)
    #error "Emios_Ocu_Ip_Irq.c and Emios_Ocu_Ip_HwAccess.h have different vendor ids"
#endif

/* Check if  source file and Emios_Ocu_Ip_HwAccess.h file are of the same Autosar version */
#if ((EMIOS_OCU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != EMIOS_OCU_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_OCU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != EMIOS_OCU_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_OCU_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != EMIOS_OCU_IP_HWACCESS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Ocu_Ip_Irq.c and Emios_Ocu_Ip_HwAccess.h are different"
#endif

/* Check if source file and Emios_Ocu_Ip_HwAccess.h file are of the same Software version */
#if ((EMIOS_OCU_IP_IRQ_SW_MAJOR_VERSION_C != EMIOS_OCU_IP_HWACCESS_SW_MAJOR_VERSION) || \
     (EMIOS_OCU_IP_IRQ_SW_MINOR_VERSION_C != EMIOS_OCU_IP_HWACCESS_SW_MINOR_VERSION) || \
     (EMIOS_OCU_IP_IRQ_SW_PATCH_VERSION_C != EMIOS_OCU_IP_HWACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Ocu_Ip_Irq.c and Emios_Ocu_Ip_HwAccess.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if this source file and SchM_Ocu.h file are of the same Autosar version */
    #if ((EMIOS_OCU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != SCHM_OCU_AR_RELEASE_MAJOR_VERSION) || \
        (EMIOS_OCU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != SCHM_OCU_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Emios_Ocu_Ip_Irq.c and SchM_Ocu.h are different"
    #endif
#endif

#if (STD_ON == OCU_EMIOS_USED)

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
extern void Emios_Ocu_Ip_ClearPendingInterrupts(uint8 InstNum, uint8 ChNum);

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

#define OCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Ocu_MemMap.h"

#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)
/** @brief Global array variable used to channel state for process common interrupt */
extern Emios_Ocu_Ip_ChStateType Emios_Ocu_Ip_gaxChState[OCU_EMIOS_INSTANCE_COUNT][OCU_EMIOS_CHANNEL_COUNT];
#endif

#define OCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Ocu_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/

#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)

void Emios_Ocu_Ip_IrqHandler(uint8 InstNum, uint8 ChIdx)
{
    boolean lboIsMatchEventEnabled;
    boolean lboHasMatchEventOccurred;
    const Emios_Ocu_Ip_ChStateType * const pChannelState = &Emios_Ocu_Ip_gaxChState[InstNum][ChIdx];

    /* enter critical section */
    SchM_Enter_Ocu_OCU_EXCLUSIVE_AREA_07();

    lboIsMatchEventEnabled   = Emios_Ocu_Ip_IsMatchEventEnabled(Emios_Ocu_Ip_gapcxBase[InstNum], ChIdx);
    lboHasMatchEventOccurred = Emios_Ocu_Ip_HasMatchEventOccurred(Emios_Ocu_Ip_gapcxBase[InstNum], ChIdx);

    if (lboIsMatchEventEnabled && lboHasMatchEventOccurred)
    {
        /* Clear interrupt flags */
        Emios_Ocu_Ip_ClearPendingInterrupts(InstNum, ChIdx);
    }

    /* exit critical section */
    SchM_Exit_Ocu_OCU_EXCLUSIVE_AREA_07();

    /* Check for spurious interrupts */
    if (lboIsMatchEventEnabled && lboHasMatchEventOccurred)
    {
        /* Call upper layer handler */
        if ((TRUE == pChannelState->mChannelInit) && (TRUE == pChannelState->mNotifEnabled) && (NULL_PTR != pChannelState->mCallbackFunc))
        {
            pChannelState->mCallbackFunc(pChannelState->mCallbackParam);
        }
    }
}

#endif

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/


#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"

#endif /* OCU_EMIOS_USED */


#ifdef __cplusplus
}
#endif
/** @} */
