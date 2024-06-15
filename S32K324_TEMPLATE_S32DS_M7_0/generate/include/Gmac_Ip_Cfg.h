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

#ifndef GMAC_IP_CFG_H
#define GMAC_IP_CFG_H

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
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Gmac_Ip_PBcfg.h"

#include "StandardTypes.h"
#include "Reg_eSys.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GMAC_IP_CFG_VENDOR_ID                     43
#define GMAC_IP_CFG_AR_RELEASE_MAJOR_VERSION      4
#define GMAC_IP_CFG_AR_RELEASE_MINOR_VERSION      7
#define GMAC_IP_CFG_AR_RELEASE_REVISION_VERSION   0
#define GMAC_IP_CFG_SW_MAJOR_VERSION              3
#define GMAC_IP_CFG_SW_MINOR_VERSION              0
#define GMAC_IP_CFG_SW_PATCH_VERSION              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Gmac_Ip_PBcfg.h */
#if (GMAC_IP_CFG_VENDOR_ID != GMAC_IP_PBCFG_VENDOR_ID)
    #error "Gmac_Ip_Cfg.h and Gmac_Ip_PBcfg.h have different vendor ids"
#endif
#if ((GMAC_IP_CFG_AR_RELEASE_MAJOR_VERSION    != GMAC_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (GMAC_IP_CFG_AR_RELEASE_MINOR_VERSION    != GMAC_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (GMAC_IP_CFG_AR_RELEASE_REVISION_VERSION != GMAC_IP_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Gmac_Ip.h and Gmac_Ip_PBcfg.h are different"
#endif
#if ((GMAC_IP_CFG_SW_MAJOR_VERSION != GMAC_IP_PBCFG_SW_MAJOR_VERSION) || \
     (GMAC_IP_CFG_SW_MINOR_VERSION != GMAC_IP_PBCFG_SW_MINOR_VERSION) || \
     (GMAC_IP_CFG_SW_PATCH_VERSION != GMAC_IP_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gmac_Ip_Cfg.h and Gmac_Ip_PBcfg.h are different"
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against StandardTypes.h */
    #if ((GMAC_IP_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (GMAC_IP_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Gmac_Ip_Cfg.h and StandardTypes.h are different"
    #endif
    /* Checks against Reg_eSys.h */
    #if ((GMAC_IP_CFG_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (GMAC_IP_CFG_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Gmac_Ip_Cfg.h and Reg_eSys.h are different"
    #endif
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define GMAC_CONFIG_EXT \
    GMAC_CONFIG_PB

#define GMAC_IP_DEV_ERROR_DETECT            (STD_ON)

#define GMAC_TIMEOUT_TYPE                (OSIF_COUNTER_DUMMY)

#define GMAC_TIMEOUT_VALUE_US            (1000U)

/*! @brief Enables / Disables user mode support */
#define GMAC_ENABLE_USER_MODE_SUPPORT    (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == GMAC_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running GMAC in user mode, MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined.
    #endif /* (STD_ON == GMAC_ENABLE_USER_MODE_SUPPORT */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

#if ((STD_ON == GMAC_ENABLE_USER_MODE_SUPPORT) && defined(MCAL_GMAC_REG_PROT_AVAILABLE))
    #if (STD_ON == MCAL_GMAC_REG_PROT_AVAILABLE)
        #define GMAC_SET_USER_ACCESS_ALLOWED_AVAILABLE      (STD_ON)  
    #else
        #define GMAC_SET_USER_ACCESS_ALLOWED_AVAILABLE      (STD_OFF)
    #endif
#else
    #define GMAC_SET_USER_ACCESS_ALLOWED_AVAILABLE      (STD_OFF)    
#endif



/*! @brief Enables / Disables the allocation of the TX data buffers */
#define GMAC_IP_HAS_EXTERNAL_TX_BUFFERS  (STD_ON)

#if (STD_ON == GMAC_IP_HAS_EXTERNAL_TX_BUFFERS)
/*! @brief Array of the feature of external buffers support indexed at controller level */
    #define GMAC_IP_INST_HAS_EXTERNAL_TX_BUFFERS  {(boolean) TRUE}
#endif

/*! @brief Enables/Disables internal cache management */
#define  GMAC_HAS_CACHE_MANAGEMENT  (STD_OFF)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/* Forward GMAC structure declarations */
struct sGmac_Ip_StateType;
struct sGmac_Ip_ConfigType;
struct sGmac_Ip_RxRingConfigType;
struct sGmac_Ip_TxRingConfigType;
struct sGmac_Ip_TxTimeAwareShaper;

/**
* @brief   The structure contains the hardware controller configuration type.
*/
typedef struct sGmac_CtrlConfigType
{
    struct sGmac_Ip_StateType                 *Gmac_pCtrlState;
    const struct sGmac_Ip_ConfigType          *Gmac_pCtrlConfig;
    const struct sGmac_Ip_RxRingConfigType    *Gmac_paCtrlRxRingConfig;
    const struct sGmac_Ip_TxRingConfigType    *Gmac_paCtrlTxRingConfig;
    const uint8                               *Gmac_pau8CtrlPhysAddr;
    const struct sGmac_Ip_TxTimeAwareShaper   *Gmac_pCtrlTxTimeAwareShaper;
} Gmac_CtrlConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* GMAC_IP_CFG_H */
