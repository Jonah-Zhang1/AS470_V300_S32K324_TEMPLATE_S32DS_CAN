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

#ifndef ETH_43_GMAC_IPW_CFG_H
#define ETH_43_GMAC_IPW_CFG_H

/**
*   @file
*
*   @addtogroup ETH_43_GMAC_DRIVER_CONFIGURATION Ethernet Driver Configurations
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
#include "Eth_43_GMAC_Ipw_PBcfg.h"

#include "Eth_43_GMAC_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_43_GMAC_IPW_CFG_VENDOR_ID                    43
#define ETH_43_GMAC_IPW_CFG_AR_RELEASE_MAJOR_VERSION     4
#define ETH_43_GMAC_IPW_CFG_AR_RELEASE_MINOR_VERSION     7
#define ETH_43_GMAC_IPW_CFG_AR_RELEASE_REVISION_VERSION  0
#define ETH_43_GMAC_IPW_CFG_SW_MAJOR_VERSION             3
#define ETH_43_GMAC_IPW_CFG_SW_MINOR_VERSION             0
#define ETH_43_GMAC_IPW_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Eth_43_GMAC_Ipw_PBcfg.h */
#if (ETH_43_GMAC_IPW_CFG_VENDOR_ID != ETH_43_GMAC_IPW_PBCFG_VENDOR_ID)
    #error "Eth_43_GMAC_Ipw_Cfg.h and Eth_43_GMAC_Ipw_PBcfg.h have different vendor ids"
#endif
#if ((ETH_43_GMAC_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != ETH_43_GMAC_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_43_GMAC_IPW_CFG_AR_RELEASE_MINOR_VERSION    != ETH_43_GMAC_IPW_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (ETH_43_GMAC_IPW_CFG_AR_RELEASE_REVISION_VERSION != ETH_43_GMAC_IPW_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Eth_43_GMAC_Ipw_Cfg.h and Eth_43_GMAC_Ipw_PBcfg.h are different"
#endif
#if ((ETH_43_GMAC_IPW_CFG_SW_MAJOR_VERSION != ETH_43_GMAC_IPW_PBCFG_SW_MAJOR_VERSION) || \
     (ETH_43_GMAC_IPW_CFG_SW_MINOR_VERSION != ETH_43_GMAC_IPW_PBCFG_SW_MINOR_VERSION) || \
     (ETH_43_GMAC_IPW_CFG_SW_PATCH_VERSION != ETH_43_GMAC_IPW_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Eth_43_GMAC_Ipw_Cfg.h and Eth_43_GMAC_Ipw_PBcfg.h are different"
#endif


/* Checks against Eth_43_GMAC_Cfg.h */
#if (ETH_43_GMAC_IPW_CFG_VENDOR_ID != ETH_43_GMAC_CFG_VENDOR_ID)
    #error "Eth_43_GMAC_Ipw_Cfg.h and Eth_43_GMAC_Cfg.h have different vendor ids"
#endif
#if ((ETH_43_GMAC_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != ETH_43_GMAC_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_43_GMAC_IPW_CFG_AR_RELEASE_MINOR_VERSION    != ETH_43_GMAC_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ETH_43_GMAC_IPW_CFG_AR_RELEASE_REVISION_VERSION != ETH_43_GMAC_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Eth_43_GMAC_Ipw_Cfg.h and Eth_43_GMAC_Cfg.h are different"
#endif
#if ((ETH_43_GMAC_IPW_CFG_SW_MAJOR_VERSION != ETH_43_GMAC_CFG_SW_MAJOR_VERSION) || \
     (ETH_43_GMAC_IPW_CFG_SW_MINOR_VERSION != ETH_43_GMAC_CFG_SW_MINOR_VERSION) || \
     (ETH_43_GMAC_IPW_CFG_SW_PATCH_VERSION != ETH_43_GMAC_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eth_43_GMAC_Ipw_Cfg.h and Eth_43_GMAC_Cfg.h are different"
#endif
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define ETH_43_GMAC_IPW_CONFIG_EXT \
    ETH_43_GMAC_IPW_CONFIG_PB

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if STD_ON == ETH_43_GMAC_DEM_EVENT_DETECT
/**
 * @brief    Type for holding DEM events
 * @details  It contains the necessary events to report to the DEM module
 */
typedef struct
{
    Mcal_DemErrorType ETH_43_GMAC_IPW_E_SAFETY_Cfg;

} Eth_43_GMAC_Ipw_DemEventsType;
#endif

/* Forward IPW structure declarations */
struct sGmac_CtrlConfigType;

/**
* @brief   The structure contains the hardware controller configuration type.
*/
typedef struct sEth_43_GMAC_Ipw_CtrlConfigType
{
    const struct sGmac_CtrlConfigType *Eth_43_GMAC_Ipw_pGmacCtrlConfig;
#if (STD_ON == ETH_43_GMAC_DEM_EVENT_DETECT)
    const Eth_43_GMAC_Ipw_DemEventsType Eth_43_GMAC_Ipw_DemEventsList;
#endif

} Eth_43_GMAC_Ipw_CtrlConfigType;

typedef struct Eth_43_GMAC_axTxBufferIdxMapType
{
    uint8 FifoIdx;
    uint8* pu8BufferData;
    boolean bTxConfirmation;
    struct Eth_43_GMAC_axTxBufferIdxMapType *pNextBuffer;

} Eth_43_GMAC_axTxBufferIdxMapType;


typedef struct
{
    Eth_43_GMAC_axTxBufferIdxMapType *pQueueHead;
    Eth_43_GMAC_axTxBufferIdxMapType *pQueueTail;

} Eth_43_GMAC_QueueInfo;

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

#endif /* ETH_43_GMAC_IPW_CFG_H */
