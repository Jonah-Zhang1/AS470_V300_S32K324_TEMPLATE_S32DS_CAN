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

/**
*   @file
*   @defgroup lpuart_uart_ip Lpuart UART IPL
*   @addtogroup  lpuart_uart_ip Lpuart UART IPL
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

#include "Lpuart_Uart_Ip_Types.h"
#include "Lpuart_Uart_Ip_Cfg.h"
#include "StandardTypes.h"
#if (LPUART_UART_IP_HAS_DMA_ENABLED == STD_ON)
#include "Dma_Ip.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LPUART_UART_IP_PBCFG_VENDOR_ID_C                     43
#define LPUART_UART_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define LPUART_UART_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define LPUART_UART_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define LPUART_UART_IP_PBCFG_SW_MAJOR_VERSION_C              3
#define LPUART_UART_IP_PBCFG_SW_MINOR_VERSION_C              0
#define LPUART_UART_IP_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Checks against Lpuart_Uart_Ip_Types.h */
#if (LPUART_UART_IP_PBCFG_VENDOR_ID_C != LPUART_UART_IP_TYPES_VENDOR_ID)
    #error "Lpuart_Uart_Ip_PBcfg.c and Lpuart_Uart_Ip_Types.h have different vendor ids"
#endif
#if ((LPUART_UART_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != LPUART_UART_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LPUART_UART_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C    != LPUART_UART_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LPUART_UART_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != LPUART_UART_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Lpuart_Uart_Ip_PBcfg.c and Lpuart_Uart_Ip_Types.h are different"
#endif
#if ((LPUART_UART_IP_PBCFG_SW_MAJOR_VERSION_C != LPUART_UART_IP_TYPES_SW_MAJOR_VERSION) || \
     (LPUART_UART_IP_PBCFG_SW_MINOR_VERSION_C != LPUART_UART_IP_TYPES_SW_MINOR_VERSION) || \
     (LPUART_UART_IP_PBCFG_SW_PATCH_VERSION_C != LPUART_UART_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lpuart_Uart_Ip_PBcfg.c and Lpuart_Uart_Ip_Types.h are different"
#endif

/* Checks against Lpuart_Uart_Ip_Cfg.h */
#if (LPUART_UART_IP_PBCFG_VENDOR_ID_C != LPUART_UART_IP_CFG_VENDOR_ID)
    #error "Lpuart_Uart_Ip_PBcfg.c and Lpuart_Uart_Ip_Cfg.h have different vendor ids"
#endif
#if ((LPUART_UART_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != LPUART_UART_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LPUART_UART_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C    != LPUART_UART_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LPUART_UART_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != LPUART_UART_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Lpuart_Uart_Ip_PBcfg.c and Lpuart_Uart_Ip_Cfg.h are different"
#endif
#if ((LPUART_UART_IP_PBCFG_SW_MAJOR_VERSION_C != LPUART_UART_IP_CFG_SW_MAJOR_VERSION) || \
     (LPUART_UART_IP_PBCFG_SW_MINOR_VERSION_C != LPUART_UART_IP_CFG_SW_MINOR_VERSION) || \
     (LPUART_UART_IP_PBCFG_SW_PATCH_VERSION_C != LPUART_UART_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lpuart_Uart_Ip_PBcfg.c and Lpuart_Uart_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes.h header file are of the same Autosar version */
    #if ((LPUART_UART_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (LPUART_UART_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Lpuart_Uart_Ip_PBcfg.c and StandardTypes.h are different"
    #endif
    /* Checks against Dma_Ip.h */
    #if (LPUART_UART_IP_HAS_DMA_ENABLED == STD_ON)
        #if ((LPUART_UART_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
             (LPUART_UART_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != DMA_IP_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Lpuart_Uart_Ip_PBcfg.c and Dma_Ip.h are different"
        #endif
    #endif
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                   STATE STRUCTURE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define UART_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Uart_MemMap.h"
extern Lpuart_Uart_Ip_StateStructureType Lpuart_Uart_Ip_apStateStructure[LPUART_UART_IP_NUMBER_OF_INSTANCES];
#define UART_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Uart_MemMap.h"

#define UART_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Uart_MemMap.h"




/**
* @brief          Hardware configuration for Uart Hardware - Configuration:
*
* @api
*/
const Lpuart_Uart_Ip_UserConfigType Lpuart_Uart_Ip_xHwConfigPB_0 =
{

    /*!< Baud rate in hertz */
    19212U,
    /* Baud clock divisor*/
    347U,
    /* Over sampling ratio*/
    6U,
    /* Parity type */
    LPUART_UART_IP_PARITY_DISABLED,
    /* Number of stop bits, 1 stop bit (default) or 2 stop bits */
    LPUART_UART_IP_ONE_STOP_BIT,
    /* Number of bits per transmitted/received word */
    LPUART_UART_IP_8_BITS_PER_CHAR,
    /* Type of UART transfer (interrupt/dma based) */
    LPUART_UART_IP_USING_INTERRUPTS,
    /* Callback to invoke for Uart event.*/
    (Lpuart_Uart_Ip_CallbackType)Uart_Ipw_LpuartCallback,
    /* User callback parameter pointer.*/
    NULL_PTR,
#if (LPUART_UART_IP_HAS_DMA_ENABLED == STD_ON)
    /* DMA channel number for DMA-based rx. */
    255,
    /* DMA channel number for DMA-based tx. */
    255,
#endif
    /* Runtime state structure refference */
    &Lpuart_Uart_Ip_apStateStructure[0]

};

#define UART_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Uart_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}

/** @} */

#endif
