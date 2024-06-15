/*==================================================================================================
*    Project               : RTD AUTOSAR 4.7
*    Platform              : CORTEXM
*    Peripheral            : eMios
*    Dependencies          : none
*
*    Autosar Version       : 4.7.0
*    Autosar Revision      : ASR_REL_4_7_REV_0000
*    Autosar Conf.Variant  :
*    SWVersion             : 3.0.0
*    BuildVersion          : S32K3_RTD_3_0_0_P10_D2307_ASR_REL_4_7_REV_0000_20230726
*
*    Copyright 2020 - 2023 NXP Semiconductors
*
*    NXP Confidential. This software is owned or controlled by NXP and may only be
*    used strictly in accordance with the applicable license terms. By expressly
*    accepting such terms or by downloading, installing, activating and/or otherwise
*    using the software, you are agreeing that you have read, and that you agree to
*    comply with and are bound by, such license terms. If you do not agree to be
*    bound by the applicable license terms, then you may not retain, install,
*    activate or otherwise use the software.
=====================================================================================================*/

#ifndef EMIOS_OCU_IP_IRQ_H
#define EMIOS_OCU_IP_IRQ_H

/**
*   @file         Emios_Ocu_Ip_Irq.h
*
*   @addtogroup   ocu_ip Ocu IPL
*   @brief        Ocu eMIOS - header file support for OCU driver.
*   @details      eMios header file, containing the variables and functions that are exported by the IP driver.
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

#include "Emios_Ocu_Ip_Types.h"
#include "OsIf.h"
/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_OCU_IP_IRQ_VENDOR_ID                       43
#define EMIOS_OCU_IP_IRQ_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_OCU_IP_IRQ_AR_RELEASE_MINOR_VERSION        7
#define EMIOS_OCU_IP_IRQ_AR_RELEASE_REVISION_VERSION     0
#define EMIOS_OCU_IP_IRQ_SW_MAJOR_VERSION                3
#define EMIOS_OCU_IP_IRQ_SW_MINOR_VERSION                0
#define EMIOS_OCU_IP_IRQ_SW_PATCH_VERSION                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (EMIOS_OCU_IP_IRQ_VENDOR_ID != EMIOS_OCU_IP_TYPES_VENDOR_ID)
    #error "Emios_Ocu_Ip_Irq.h and Emios_Ocu_Ip_Types.h have different vendor ids"
#endif

/* Check if  header file and Emios_Ocu_Ip_Types.h file are of the same Autosar version */
#if ((EMIOS_OCU_IP_IRQ_AR_RELEASE_MAJOR_VERSION != EMIOS_OCU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_OCU_IP_IRQ_AR_RELEASE_MINOR_VERSION != EMIOS_OCU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_OCU_IP_IRQ_AR_RELEASE_REVISION_VERSION != EMIOS_OCU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Ocu_Ip_Irq.h and Emios_Ocu_Ip_Types.h are different"
#endif

/* Check if header file and Emios_Ocu_Ip_Types.h file are of the same Software version */
#if ((EMIOS_OCU_IP_IRQ_SW_MAJOR_VERSION != EMIOS_OCU_IP_TYPES_SW_MAJOR_VERSION) || \
     (EMIOS_OCU_IP_IRQ_SW_MINOR_VERSION != EMIOS_OCU_IP_TYPES_SW_MINOR_VERSION) || \
     (EMIOS_OCU_IP_IRQ_SW_PATCH_VERSION != EMIOS_OCU_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Ocu_Ip_Irq.h and Emios_Ocu_Ip_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if this header file and OsIf.h file are of the same Autosar version */
    #if ((EMIOS_OCU_IP_IRQ_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (EMIOS_OCU_IP_IRQ_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Emios_Ocu_Ip_Irq.h and OsIf.h are different"
    #endif
#endif

#if (STD_ON == OCU_EMIOS_USED)

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"

#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
/**
 * @brief   Driver routine to process all the interrupts of eMios.
 * @details Support function used by interrupt service routines to implement eMios specific operations
 *          and call the EMIOS_OCU_IP upper layer handler to implement non-hardware specific operations.
 *
 *
 * @param[in] InstNum Instance number of eMIOS module
 * @param[in] ChIdx The channel in the instance
 *
 * @implements   Emios_Ocu_Ip_IrqHandler_Activity
 */
void Emios_Ocu_Ip_IrqHandler(uint8 InstNum, uint8 ChIdx);
#endif

#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"

#endif /* OCU_EMIOS_USED */


#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* EMIOS_OCU_IP_IRQ_H */
