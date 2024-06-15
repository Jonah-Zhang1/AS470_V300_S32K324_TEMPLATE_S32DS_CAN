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

#ifndef SENT_IPW_TYPES_H
#define SENT_IPW_TYPES_H

/**
*   @file    Sent_Ipw_Types.h
*   @version 1.0.3
*
*   @brief   AUTOSAR Sent - Sent driver header file.
*   @details Sent driver header file, containing variables, functions prototypes, data types and/or
*            defines and macros that:
*            - are Autosar independent.
*            - are platform dependent.
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

#include "Flexio_Sent_Ip_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @file          Sent_IPW_Types.h
*/
#define SENT_IPW_TYPES_VENDOR_ID                      43
#define SENT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define SENT_IPW_TYPES_AR_RELEASE_MINOR_VERSION       7
#define SENT_IPW_TYPES_AR_RELEASE_REVISION_VERSION    0
#define SENT_IPW_TYPES_SW_MAJOR_VERSION               3
#define SENT_IPW_TYPES_SW_MINOR_VERSION               0
#define SENT_IPW_TYPES_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Sent_Ipw_Types header file are of the same vendor */
#if (SENT_IPW_TYPES_VENDOR_ID != FLEXIO_SENT_IP_TYPES_VENDOR_ID)
    #error "Sent_Ipw_Types.h and Flexio_Sent_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Sent_Ipw_Types header file are of the same Autosar version */
#if ((SENT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != FLEXIO_SENT_IP_TYPES_AR_RELEASE_MAJOR_VERSION) ||    \
     (SENT_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != FLEXIO_SENT_IP_TYPES_AR_RELEASE_MINOR_VERSION) ||    \
     (SENT_IPW_TYPES_AR_RELEASE_REVISION_VERSION != FLEXIO_SENT_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Sent_Ipw_Types.h and Flexio_Sent_Ip_Types.h are different"
#endif
/* Check if current file and Sent_Ipw_Types header file are of the same Software version */
#if ((SENT_IPW_TYPES_SW_MAJOR_VERSION != FLEXIO_SENT_IP_TYPES_SW_MAJOR_VERSION) || \
     (SENT_IPW_TYPES_SW_MINOR_VERSION != FLEXIO_SENT_IP_TYPES_SW_MINOR_VERSION) || \
     (SENT_IPW_TYPES_SW_PATCH_VERSION != FLEXIO_SENT_IP_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Sent_Ipw_Types.h and Flexio_Sent_Ip_Types.h are different"
#endif
/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief   The structure contains the hardware channel configuration type.
*/
typedef struct
{
    const Flexio_CtrlConfigType * CtrlConfig;
} Sent_Ipw_CtrlConfigType;

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /*SENT_IPW_TYPES_H*/
