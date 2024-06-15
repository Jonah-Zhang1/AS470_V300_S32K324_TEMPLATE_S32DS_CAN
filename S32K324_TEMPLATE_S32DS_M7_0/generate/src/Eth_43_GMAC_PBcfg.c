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
*   @implements Eth_PBcfg.c_Artifact
*   @addtogroup ETH_43_GMAC_DRIVER_CONFIGURATION Ethernet Driver Configuration
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
#include "Eth_43_GMAC_Cfg.h"
#include "Eth_43_GMAC_Ipw_Cfg.h"

#if STD_ON == ETH_43_GMAC_DEM_EVENT_DETECT
    #include "Dem.h"
#endif

#if (STD_ON == ETH_43_GMAC_MDIO_CLAUSE22_API) || (STD_ON == ETH_43_GMAC_MDIO_CLAUSE45_API)
    #include "EthTrcv.h"
#endif

#if STD_ON == ETH_43_GMAC_SWT_MANAGEMENT_SUPPORT_API
    #include "EthSwt.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_43_GMAC_PBCFG_VENDOR_ID_C                     43
#define ETH_43_GMAC_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define ETH_43_GMAC_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define ETH_43_GMAC_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define ETH_43_GMAC_PBCFG_SW_MAJOR_VERSION_C              3
#define ETH_43_GMAC_PBCFG_SW_MINOR_VERSION_C              0
#define ETH_43_GMAC_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Eth_43_GMAC_Cfg.h */
#if (ETH_43_GMAC_PBCFG_VENDOR_ID_C != ETH_43_GMAC_CFG_VENDOR_ID)
    #error "Eth_PBcfg.c and Eth_43_GMAC_Cfg.h have different vendor ids"
#endif
#if ((ETH_43_GMAC_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != ETH_43_GMAC_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_43_GMAC_PBCFG_AR_RELEASE_MINOR_VERSION_C    != ETH_43_GMAC_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ETH_43_GMAC_PBCFG_AR_RELEASE_REVISION_VERSION_C != ETH_43_GMAC_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Eth_PBcfg.c and Eth_43_GMAC_Cfg.h are different"
#endif
#if ((ETH_43_GMAC_PBCFG_SW_MAJOR_VERSION_C != ETH_43_GMAC_CFG_SW_MAJOR_VERSION) || \
     (ETH_43_GMAC_PBCFG_SW_MINOR_VERSION_C != ETH_43_GMAC_CFG_SW_MINOR_VERSION) || \
     (ETH_43_GMAC_PBCFG_SW_PATCH_VERSION_C != ETH_43_GMAC_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eth_PBcfg.c and Eth_43_GMAC_Cfg.h are different"
#endif

/* Checks against Eth_43_GMAC_Ipw_Cfg.h */
#if (ETH_43_GMAC_PBCFG_VENDOR_ID_C != ETH_43_GMAC_IPW_CFG_VENDOR_ID)
    #error "Eth_PBcfg.c and Eth_43_GMAC_Ipw_Cfg.h have different vendor ids"
#endif
#if ((ETH_43_GMAC_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != ETH_43_GMAC_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_43_GMAC_PBCFG_AR_RELEASE_MINOR_VERSION_C    != ETH_43_GMAC_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ETH_43_GMAC_PBCFG_AR_RELEASE_REVISION_VERSION_C != ETH_43_GMAC_IPW_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Eth_PBcfg.c and Eth_43_GMAC_Ipw_Cfg.h are different"
#endif
#if ((ETH_43_GMAC_PBCFG_SW_MAJOR_VERSION_C != ETH_43_GMAC_IPW_CFG_SW_MAJOR_VERSION) || \
     (ETH_43_GMAC_PBCFG_SW_MINOR_VERSION_C != ETH_43_GMAC_IPW_CFG_SW_MINOR_VERSION) || \
     (ETH_43_GMAC_PBCFG_SW_PATCH_VERSION_C != ETH_43_GMAC_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eth_PBcfg.c and Eth_43_GMAC_Ipw_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  #if STD_ON == ETH_43_GMAC_DEM_EVENT_DETECT
    /* Checks against Dem.h */
    #if ((ETH_43_GMAC_PBCFG_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_43_GMAC_PBCFG_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Eth_PBcfg.c and Dem.h are different"
    #endif
  #endif

  #if (STD_ON == ETH_43_GMAC_MDIO_CLAUSE22_API) || (STD_ON == ETH_43_GMAC_MDIO_CLAUSE45_API)

    /* Checks against EthTrcv.h */
    #if ((ETH_43_GMAC_PBCFG_AR_RELEASE_MAJOR_VERSION_C != ETHTRCV_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_43_GMAC_PBCFG_AR_RELEASE_MINOR_VERSION_C != ETHTRCV_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Eth_PBcfg.c and EthTrcv.h are different"
    #endif

  #endif

  #if STD_ON == ETH_43_GMAC_SWT_MANAGEMENT_SUPPORT_API

    /* Checks against EthSwt.h */
    #if ((ETH_43_GMAC_PBCFG_AR_RELEASE_MAJOR_VERSION_C != ETHSWT_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_43_GMAC_PBCFG_AR_RELEASE_MINOR_VERSION_C != ETHSWT_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Eth_PBcfg.c and EthSwt.h are different"
    #endif

  #endif
#endif

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define ETH_43_GMAC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"

/**
* @brief   Export IPW configurations.
*/
ETH_43_GMAC_IPW_CONFIG_EXT

#define ETH_43_GMAC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/



/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ETH_43_GMAC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"


static const Eth_43_GMAC_EgressCfgType Eth_43_GMAC_aEgressConfigPB[1U] =
{
    
    /* The configuration structure for Eth_43_GMAC_aEgressConfigPB[0U] - IP_0 */
    {
        4U, /* Total number of buffers across all Tx FIFOs */
        1U, /* Total number of configured Tx FIFOs */
        { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } /* Map between VLAN PCPs and Tx FIFOs */
    }

};



static const Eth_43_GMAC_IngressCfgType Eth_43_GMAC_aIngressConfigPB[1U] =
{
    
    /* The configuration structure for Eth_43_GMAC_aIngressConfigPB[0U] - IP_0 */
    {
        4U, /* Total number of buffers across all Rx FIFOs */
        1U /* Total number of configured Rx FIFOs */
    }

};



static const Eth_43_GMAC_ClockCfgType Eth_43_GMAC_aClockConfigPB[1U] =
{
    
    /* The configuration structure for Eth_43_GMAC_aClockConfigPB[0U] - IP_0 */
    {
        25000000U, /* Frequency of the application interface (in Hz) */
        0U, /* Number of picoseconds in a PTP clock period */
        0U  /* Number of nanoseconds in a PTP clock period for the required accuracy */
    }

};



static const Eth_43_GMAC_CtrlCfgType Eth_43_GMAC_aCtrlConfigPB[1U] =
{
    
    /* The configuration structure for Eth_43_GMAC_aCtrlConfigPB[0U] - IP_0 */
    {
        &Eth_43_GMAC_Ipw_aCtrlConfigPB[0U],
        &Eth_43_GMAC_aEgressConfigPB[0U],
        &Eth_43_GMAC_aIngressConfigPB[0U],
        &Eth_43_GMAC_aClockConfigPB[0U],
        (uint8)0U,
        (uint8)0U
#if (STD_ON == ETH_43_GMAC_DEM_EVENT_DETECT)
       ,{
            { (uint32)STD_OFF, 0 },
            { (uint32)STD_OFF, 0 },
            { (uint32)STD_OFF, 0 },
            { (uint32)STD_OFF, 0 },
            { (uint32)STD_OFF, 0 },
            { (uint32)STD_OFF, 0 },
            { (uint32)STD_OFF, 0 },
            { (uint32)STD_OFF, 0 },
            { (uint32)STD_OFF, 0 }
        }
#endif
#if (STD_ON == ETH_43_GMAC_MDIO_CLAUSE22_API) || (STD_ON == ETH_43_GMAC_MDIO_CLAUSE45_API)
       ,{
            &EthTrcv_ReadMiiIndication,
            &EthTrcv_WriteMiiIndication
        }
#endif
#if STD_ON == ETH_43_GMAC_SWT_MANAGEMENT_SUPPORT_API
       ,{
            &EthSwt_EthTxAdaptBufferLength,
            &EthSwt_EthTxPrepareFrame,
            &EthSwt_EthTxProcessFrame,
            &EthSwt_EthTxFinishedIndication,
            &EthSwt_EthRxProcessFrame,
            &EthSwt_EthRxFinishedIndication
        }
#endif
    }

};


#define ETH_43_GMAC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/










/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define ETH_43_GMAC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"


    
const Eth_43_GMAC_ConfigType Eth_43_GMAC_xPredefinedConfig =
{
    {

        &Eth_43_GMAC_aCtrlConfigPB[0U] /* IP_0 */
    }
};



#define ETH_43_GMAC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"

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
