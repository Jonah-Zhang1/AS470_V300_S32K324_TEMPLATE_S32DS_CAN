/**
*   @file    Mcl_PBcfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR Mcl - Data structures for the Mcl driver.
*   @details Postbuild structure configurations for the driver initalization.
*
*   @addtogroup MCL
*   @{
*/
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

#ifndef MCL_PBCFG_H_
#define MCL_PBCFG_H_

#ifdef __cplusplus
extern "C"
{
#endif


/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, Macro identifiers shall be distinct.
* This violation is due to the AUTOSAR requirement [SWS_BSW_00036] (perform inter module checks).
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, External identifiers shall be distinct.
* This rule does not apply if either identifier is a macro identifier, because this case is covered
* by Rule 5.4 and Rule 5.5.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, Identifiers declared in the same scope and name space shall be distinct.
* This rule does not apply if either identifier is a macro identifier, because this case is covered
* by Rule 5.4 and Rule 5.5.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, Identifiers shall be distinct from macro names.
* The identifier clash is between macro identifiers. Therefore, this rule is incorrectly reported by the tool.
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_MCL_PBCFG_VENDOR_ID                     43
#define CDD_MCL_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define CDD_MCL_PBCFG_AR_RELEASE_MINOR_VERSION      7
#define CDD_MCL_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define CDD_MCL_PBCFG_SW_MAJOR_VERSION              3
#define CDD_MCL_PBCFG_SW_MINOR_VERSION              0
#define CDD_MCL_PBCFG_SW_PATCH_VERSION              0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

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
#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Mcl_Dma_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"


extern const Mcl_ConfigType Mcl_Config;






#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Mcl_Dma_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

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

#endif /* #ifndef MCL_PBCFG_H */

/** @} */

