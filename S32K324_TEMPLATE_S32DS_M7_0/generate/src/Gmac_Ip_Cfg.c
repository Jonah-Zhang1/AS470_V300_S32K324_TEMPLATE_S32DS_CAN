/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : GMAC
*   Dependencies         : none
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
*
*   @addtogroup GMAC_DRIVER_CONFIGURATION GMAC Driver Configuration
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
#include "Gmac_Ip_Types.h"
#include "Gmac_Ip_Cfg.h"
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GMAC_IP_CFG_VENDOR_ID_C                     43
#define GMAC_IP_CFG_AR_RELEASE_MAJOR_VERSION_C      4
#define GMAC_IP_CFG_AR_RELEASE_MINOR_VERSION_C      7
#define GMAC_IP_CFG_AR_RELEASE_REVISION_VERSION_C   0
#define GMAC_IP_CFG_SW_MAJOR_VERSION_C              3
#define GMAC_IP_CFG_SW_MINOR_VERSION_C              0
#define GMAC_IP_CFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Gmac_Ip_Types.h */
#if (GMAC_IP_CFG_VENDOR_ID_C != GMAC_IP_TYPES_VENDOR_ID)
    #error "Gmac_Ip_Cfg.c and Gmac_Ip_Types.h have different vendor ids"
#endif
#if ((GMAC_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != GMAC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (GMAC_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != GMAC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (GMAC_IP_CFG_AR_RELEASE_REVISION_VERSION_C != GMAC_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Gmac_Ip_Cfg.h and Gmac_Ip_Types.h are different"
#endif
#if ((GMAC_IP_CFG_SW_MAJOR_VERSION_C != GMAC_IP_TYPES_SW_MAJOR_VERSION) || \
     (GMAC_IP_CFG_SW_MINOR_VERSION_C != GMAC_IP_TYPES_SW_MINOR_VERSION) || \
     (GMAC_IP_CFG_SW_PATCH_VERSION_C != GMAC_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gmac_Ip_Cfg.c and Gmac_Ip_Types.h are different"
#endif

/* Checks against Gmac_Ip_Cfg.h */
#if (GMAC_IP_CFG_VENDOR_ID_C != GMAC_IP_CFG_VENDOR_ID)
    #error "Gmac_Ip_Cfg.c and Gmac_Ip_Cfg.h have different vendor ids"
#endif
#if ((GMAC_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != GMAC_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (GMAC_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != GMAC_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (GMAC_IP_CFG_AR_RELEASE_REVISION_VERSION_C != GMAC_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Gmac_Ip_Cfg.h and Gmac_Ip_Cfg.h are different"
#endif
#if ((GMAC_IP_CFG_SW_MAJOR_VERSION_C != GMAC_IP_CFG_SW_MAJOR_VERSION) || \
     (GMAC_IP_CFG_SW_MINOR_VERSION_C != GMAC_IP_CFG_SW_MINOR_VERSION) || \
     (GMAC_IP_CFG_SW_PATCH_VERSION_C != GMAC_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gmac_Ip_Cfg.c and Gmac_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((GMAC_IP_CFG_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (GMAC_IP_CFG_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Gmac_Ip_Cfg.h and Mcal.h are different"
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
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#if (STD_OFF == GMAC_HAS_CACHE_MANAGEMENT)
#define ETH_43_GMAC_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Eth_43_GMAC_MemMap.h"
#else
#define ETH_43_GMAC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"
#endif

#ifdef GMAC_0_RXRING_0_DATA
    /*! @brief Reception data buffers for Rx Ring 0 */
    VAR_ALIGN(uint8 GMAC_0_RxRing_0_DataBuffer[(GMAC_0_MAX_RXBUFF_SUPPORTED * GMAC_0_MAX_RXBUFFLEN_SUPPORTED)], FEATURE_GMAC_BUFF_ALIGNMENT_BYTES)
#endif

#ifdef GMAC_0_RXRING_1_DATA
    /*! @brief Reception data buffers for Rx Ring 1 */
    VAR_ALIGN(uint8 GMAC_0_RxRing_1_DataBuffer[(GMAC_0_MAX_RXBUFF_SUPPORTED * GMAC_0_MAX_RXBUFFLEN_SUPPORTED)], FEATURE_GMAC_BUFF_ALIGNMENT_BYTES)
#endif


#ifdef GMAC_0_TXRING_0_DATA
    /*! @brief Transmission data buffers for Tx Ring 0 */
    VAR_ALIGN(uint8 GMAC_0_TxRing_0_DataBuffer[(GMAC_0_MAX_TXBUFF_SUPPORTED * GMAC_0_MAX_TXBUFFLEN_SUPPORTED)], FEATURE_GMAC_BUFF_ALIGNMENT_BYTES)
#endif


#ifdef GMAC_0_TXRING_1_DATA
    /*! @brief Transmission data buffers for Tx Ring 1 */
    VAR_ALIGN(uint8 GMAC_0_TxRing_1_DataBuffer[(GMAC_0_MAX_TXBUFF_SUPPORTED * GMAC_0_MAX_TXBUFFLEN_SUPPORTED)], FEATURE_GMAC_BUFF_ALIGNMENT_BYTES)
#endif


#if (STD_OFF == GMAC_HAS_CACHE_MANAGEMENT)
#define ETH_43_GMAC_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Eth_43_GMAC_MemMap.h"
#else
#define ETH_43_GMAC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"
#endif

#define ETH_43_GMAC_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Eth_43_GMAC_MemMap.h"

#ifdef GMAC_0_RXRING_0_DESCR
    /*! @brief Reception buffer descriptors for Rx Ring 0 */
    VAR_ALIGN(Gmac_Ip_BufferDescriptorType GMAC_0_RxRing_0_DescBuffer[GMAC_0_MAX_RXBUFF_SUPPORTED], FEATURE_GMAC_BUFFDESCR_ALIGNMENT_BYTES)
#endif

#ifdef GMAC_0_RXRING_1_DESCR
    /*! @brief Reception buffer descriptors for Rx Ring 1 */
    VAR_ALIGN(Gmac_Ip_BufferDescriptorType GMAC_0_RxRing_1_DescBuffer[GMAC_0_MAX_RXBUFF_SUPPORTED], FEATURE_GMAC_BUFFDESCR_ALIGNMENT_BYTES)
#endif

#ifdef GMAC_0_TXRING_0_DESCR
    /*! @brief Transmission buffer descriptors for Tx Ring 0 */
    VAR_ALIGN(Gmac_Ip_BufferDescriptorType GMAC_0_TxRing_0_DescBuffer[GMAC_0_MAX_TXBUFF_SUPPORTED], FEATURE_GMAC_BUFFDESCR_ALIGNMENT_BYTES)
#endif

#ifdef GMAC_0_TXRING_1_DESCR
    /*! @brief Transmission buffer descriptors for Tx Ring 1 */
    VAR_ALIGN(Gmac_Ip_BufferDescriptorType GMAC_0_TxRing_1_DescBuffer[GMAC_0_MAX_TXBUFF_SUPPORTED], FEATURE_GMAC_BUFFDESCR_ALIGNMENT_BYTES)
#endif


#define ETH_43_GMAC_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Eth_43_GMAC_MemMap.h"



#define ETH_43_GMAC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"

/* Instance state structures used to hold driver runtime data */

#ifdef INST_GMAC_0
    Gmac_Ip_StateType GMAC_0_StateStructure;
#endif

#define ETH_43_GMAC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"

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
#endif

/** @} */
