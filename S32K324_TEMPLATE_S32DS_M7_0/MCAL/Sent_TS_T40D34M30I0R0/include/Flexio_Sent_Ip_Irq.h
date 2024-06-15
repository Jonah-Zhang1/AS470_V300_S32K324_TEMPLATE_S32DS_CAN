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

#ifndef FLEXIO_SENT_IP_IRQ_H
#define FLEXIO_SENT_IP_IRQ_H

/**
*   @file    Flexio_Sent_Ip_Irq.h
*   @version 3.0.0
*
*   @brief   AUTOSAR Sent - Low level header of Sent driver.
*   @details This file contains declarations of the ISR functions.
*
*   @addtogroup SENT_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Flexio_Sent_Ip_Cfg.h"
#include "Flexio_Sent_Ip_HwAccess.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FLEXIO_SENT_IP_IRQ_VENDOR_ID                      43
#define FLEXIO_SENT_IP_IRQ_AR_RELEASE_MAJOR_VERSION       4
#define FLEXIO_SENT_IP_IRQ_AR_RELEASE_MINOR_VERSION       7
#define FLEXIO_SENT_IP_IRQ_AR_RELEASE_REVISION_VERSION    0
#define FLEXIO_SENT_IP_IRQ_SW_MAJOR_VERSION               3
#define FLEXIO_SENT_IP_IRQ_SW_MINOR_VERSION               0
#define FLEXIO_SENT_IP_IRQ_SW_PATCH_VERSION               0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Flexio_Sent_Ip_Cfg header file are of the same vendor */
#if (FLEXIO_SENT_IP_IRQ_VENDOR_ID != FLEXIO_SENT_IP_CFG_VENDOR_ID)
    #error "Flexio_Sent_Ip_Irq.h and Flexio_Sent_Ip_Cfg.h have different vendor IDs"
#endif
/* Check if current file and Flexio_Sent_Ip_Cfg header file are of the same Autosar version */
#if ((FLEXIO_SENT_IP_IRQ_AR_RELEASE_MAJOR_VERSION    != FLEXIO_SENT_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
       (FLEXIO_SENT_IP_IRQ_AR_RELEASE_MINOR_VERSION    != FLEXIO_SENT_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
       (FLEXIO_SENT_IP_IRQ_AR_RELEASE_REVISION_VERSION != FLEXIO_SENT_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Flexio_Sent_Ip_Irq.h and Flexio_Sent_Ip_Cfg.h have different vendor IDs"
#endif
/* Check if current file and Flexio_Sent_Ip_Cfg header file are of the same Software version */
#if ((FLEXIO_SENT_IP_IRQ_SW_MAJOR_VERSION != FLEXIO_SENT_IP_CFG_SW_MAJOR_VERSION) || \
      (FLEXIO_SENT_IP_IRQ_SW_MINOR_VERSION != FLEXIO_SENT_IP_CFG_SW_MINOR_VERSION) || \
      (FLEXIO_SENT_IP_IRQ_SW_PATCH_VERSION != FLEXIO_SENT_IP_CFG_SW_PATCH_VERSION)    \
    )
    #error "Flexio_Sent_Ip_Irq.h and Flexio_Sent_Ip_Cfg.h have different vendor IDs"
#endif

/* Check if current file and Flexio_Sent_Ip_hw_access header file are of the same vendor */
#if (FLEXIO_SENT_IP_IRQ_VENDOR_ID != FLEXIO_SENT_IP_HWACCESS_VENDOR_ID)
    #error "Flexio_Sent_Ip_Irq.h and Flexio_Sent_Ip_hw_access.h have different vendor IDs"
#endif
/* Check if current file and Flexio_Sent_Ip_hw_access header file are of the same Autosar version */
#if ((FLEXIO_SENT_IP_IRQ_AR_RELEASE_MAJOR_VERSION    != FLEXIO_SENT_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
       (FLEXIO_SENT_IP_IRQ_AR_RELEASE_MINOR_VERSION    != FLEXIO_SENT_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
       (FLEXIO_SENT_IP_IRQ_AR_RELEASE_REVISION_VERSION != FLEXIO_SENT_IP_HWACCESS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Flexio_Sent_Ip_Irq.h and Flexio_Sent_Ip_hw_access.h have different vendor IDs"
#endif
/* Check if current file and Flexio_Sent_Ip_hw_access header file are of the same Software version */
#if ((FLEXIO_SENT_IP_IRQ_SW_MAJOR_VERSION != FLEXIO_SENT_IP_HWACCESS_SW_MAJOR_VERSION) || \
      (FLEXIO_SENT_IP_IRQ_SW_MINOR_VERSION != FLEXIO_SENT_IP_HWACCESS_SW_MINOR_VERSION) || \
      (FLEXIO_SENT_IP_IRQ_SW_PATCH_VERSION != FLEXIO_SENT_IP_HWACCESS_SW_PATCH_VERSION)    \
    )
    #error "Flexio_Sent_Ip_Irq.h and Flexio_Sent_Ip_hw_access.h have different vendor IDs"
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

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Sent_Ip_IrqHandler
 * Description   : Implementation of Flexio interrupt handler
 *
 ******************************************************************************/
void Flexio_Sent_Ip_IrqHandler(uint8 HwChannel, uint8 TimerMaskFlag);

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FLEXIO_SENT_IP_IRQ_H */
