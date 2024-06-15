/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : eMios
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_P10_D2307_ASR_REL_4_7_REV_0000_20230726
*
*   Copyright 2020 - 2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef OCU_IRQ_H
#define OCU_IRQ_H

/**
*   @file           Ocu_Irq.h
*
*   @addtogroup     ocu_driver Ocu Driver
*   @brief          Ocu HLD notifications API header.
*   @details        Ocu notifications API header.
*
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/

#include "Ocu_Types.h"

/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define OCU_IRQ_VENDOR_ID                       43
#define OCU_IRQ_AR_RELEASE_MAJOR_VERSION        4
#define OCU_IRQ_AR_RELEASE_MINOR_VERSION        7
#define OCU_IRQ_AR_RELEASE_REVISION_VERSION     0
#define OCU_IRQ_SW_MAJOR_VERSION                3
#define OCU_IRQ_SW_MINOR_VERSION                0
#define OCU_IRQ_SW_PATCH_VERSION                0
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and OCU header file are of the same vendor */
#if (OCU_IRQ_VENDOR_ID != OCU_TYPES_VENDOR_ID)
    #error "Ocu_Irq.h and Ocu_Types.h have different vendor IDs"
#endif
/* Check if source file and OCU header file are of the same AutoSar version */
#if ((OCU_IRQ_AR_RELEASE_MAJOR_VERSION != OCU_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_IRQ_AR_RELEASE_MINOR_VERSION != OCU_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (OCU_IRQ_AR_RELEASE_REVISION_VERSION != OCU_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu_Irq.h and Ocu_Types.h are different"
#endif
/* Check if source file and OCU header file are of the same Software version */
#if ((OCU_IRQ_SW_MAJOR_VERSION != OCU_TYPES_SW_MAJOR_VERSION) || \
     (OCU_IRQ_SW_MINOR_VERSION != OCU_TYPES_SW_MINOR_VERSION) || \
     (OCU_IRQ_SW_PATCH_VERSION != OCU_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Ocu_Irq.h and Ocu_Types.h are different"
#endif


/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

/*===============================================================================================
*                                             ENUMS
===============================================================================================*/

/*===============================================================================================
*                                   STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/*===============================================================================================
*                                   GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
                                        FUNCTION PROTOTYPES
===============================================================================================*/
#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"

#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)
/**
 * @brief   Ocu common handler to implements generic part of the ISR.
 * @details Generic function used by all interrupt service routines to call notification
 *
 * @param[in]   Channel - logic channel number
 * @implements  Ocu_ProcessChannelNotification_Activity
 *
 */
void Ocu_ProcessChannelNotification(uint16 Channel);
#endif

#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* OCU_IRQ_H */
