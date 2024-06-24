/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,LCU,EMIOS,FLEXIO
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
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

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
#include "Flexio_Mcl_Ip_Cfg.h"

/*==================================================================================================
*                                    SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_MCL_IP_PBCFG_VENDOR_ID_C                        43
#define FLEXIO_MCL_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C         4
#define FLEXIO_MCL_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C         7
#define FLEXIO_MCL_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C      0
#define FLEXIO_MCL_IP_PBCFG_SW_MAJOR_VERSION_C                 3
#define FLEXIO_MCL_IP_PBCFG_SW_MINOR_VERSION_C                 0
#define FLEXIO_MCL_IP_PBCFG_SW_PATCH_VERSION_C                 0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Flexio_Mcl_Ip_PBcfg.c file and Flexio_Mcl_Ip_Cfg.h file are of the same vendor */
#if (FLEXIO_MCL_IP_PBCFG_VENDOR_ID_C != FLEXIO_MCL_IP_CFG_VENDOR_ID)
    #error "Flexio_Mcl_Ip_PBcfg.c and Flexio_Mcl_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Flexio_Mcl_Ip_PBcfg.c file and Flexio_Mcl_Ip_Cfg.h file are of the same Autosar version */
#if ((FLEXIO_MCL_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != FLEXIO_MCL_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != FLEXIO_MCL_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_MCL_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != FLEXIO_MCL_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip_PBcfg.c and Flexio_Mcl_Ip_Cfg.h are different"
#endif

/* Check if Flexio_Mcl_Ip_PBcfg.c file and Flexio_Mcl_Ip_Cfg.h file are of the same Software version */
#if ((FLEXIO_MCL_IP_PBCFG_SW_MAJOR_VERSION_C != FLEXIO_MCL_IP_CFG_SW_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_PBCFG_SW_MINOR_VERSION_C != FLEXIO_MCL_IP_CFG_SW_MINOR_VERSION) || \
     (FLEXIO_MCL_IP_PBCFG_SW_PATCH_VERSION_C != FLEXIO_MCL_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Flexio_Mcl_Ip_PBcfg.c and Flexio_Mcl_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Mcl_Dma_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"






/**
* @brief   Configuration for Flexio instance
* @details This structure should contains data about the Flexio common
*          part configurated using Mcl driver
* @implements Mcl_FlexioInstanceConfigType
*/
const Flexio_Ip_InstanceConfigType Flexio_Ip_xFlexioInit =
{
        /** @brief  Hardware Flexio instance number */
        (uint8) 0U,
        (boolean)TRUE,
};


#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Mcl_Dma_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

