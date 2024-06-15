/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : FLEXIO
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_P07_D2306_ASR_REL_4_7_REV_0000_20230629
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

#ifndef FLEXIO_UART_IP_PBCFG_H
#define FLEXIO_UART_IP_PBCFG_H

/**
*   @file
*   @defgroup flexio_uart_ip Flexio UART IPL
*   @addtogroup  flexio_uart_ip Flexio UART IPL
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Flexio_Uart_Ip_Types.h"

/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FLEXIO_UART_IP_PBCFG_VENDOR_ID                     43
#define FLEXIO_UART_IP_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define FLEXIO_UART_IP_PBCFG_AR_RELEASE_MINOR_VERSION      7
#define FLEXIO_UART_IP_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define FLEXIO_UART_IP_PBCFG_SW_MAJOR_VERSION              3
#define FLEXIO_UART_IP_PBCFG_SW_MINOR_VERSION              0
#define FLEXIO_UART_IP_PBCFG_SW_PATCH_VERSION              0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Flexio_Uart_Ip_Types.h */
#if (FLEXIO_UART_IP_PBCFG_VENDOR_ID != FLEXIO_UART_IP_TYPES_VENDOR_ID)
    #error "Flexio_Uart_Ip_PBcfg.h and Flexio_Uart_Ip_Types.h have different vendor ids"
#endif
#if ((FLEXIO_UART_IP_PBCFG_AR_RELEASE_MAJOR_VERSION   != FLEXIO_UART_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_UART_IP_PBCFG_AR_RELEASE_MINOR_VERSION   != FLEXIO_UART_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_UART_IP_PBCFG_AR_RELEASE_REVISION_VERSION!= FLEXIO_UART_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Flexio_Uart_Ip_PBcfg.h and Flexio_Uart_Ip_Types.h are different"
#endif
#if ((FLEXIO_UART_IP_PBCFG_SW_MAJOR_VERSION!= FLEXIO_UART_IP_TYPES_SW_MAJOR_VERSION) || \
     (FLEXIO_UART_IP_PBCFG_SW_MINOR_VERSION!= FLEXIO_UART_IP_TYPES_SW_MINOR_VERSION) || \
     (FLEXIO_UART_IP_PBCFG_SW_PATCH_VERSION!= FLEXIO_UART_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexio_Uart_Ip_PBcfg.h and Flexio_Uart_Ip_Types.h are different"
#endif


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define FLEXIO_UART_IP_CONFIG_PB \

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_UART_IP_PBCFG_H */