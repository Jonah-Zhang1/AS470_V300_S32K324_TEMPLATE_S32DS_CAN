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
*   @addtogroup ETH_43_GMAC_DRIVER Ethernet Driver
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
#include "Eth_43_GMAC_Ipw.h"

#include "Gmac_Ip_Types.h"

#if (STD_ON == ETH_43_GMAC_DEM_EVENT_DETECT)
#include "Dem.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_43_GMAC_IPW_IRQ_VENDOR_ID_C                      43
#define ETH_43_GMAC_IPW_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define ETH_43_GMAC_IPW_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define ETH_43_GMAC_IPW_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define ETH_43_GMAC_IPW_IRQ_SW_MAJOR_VERSION_C               3
#define ETH_43_GMAC_IPW_IRQ_SW_MINOR_VERSION_C               0
#define ETH_43_GMAC_IPW_IRQ_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Eth_43_GMAC_Ipw.h */
#if (ETH_43_GMAC_IPW_IRQ_VENDOR_ID_C != ETH_43_GMAC_IPW_VENDOR_ID)
    #error "Eth_43_GMAC_Ipw_Irq.c and Eth_43_GMAC_Ipw.h have different vendor ids"
#endif
#if ((ETH_43_GMAC_IPW_IRQ_AR_RELEASE_MAJOR_VERSION_C    != ETH_43_GMAC_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_43_GMAC_IPW_IRQ_AR_RELEASE_MINOR_VERSION_C    != ETH_43_GMAC_IPW_AR_RELEASE_MINOR_VERSION) || \
     (ETH_43_GMAC_IPW_IRQ_AR_RELEASE_REVISION_VERSION_C != ETH_43_GMAC_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Eth_43_GMAC_Ipw_Irq.c and Eth_43_GMAC_Ipw.h are different"
#endif
#if ((ETH_43_GMAC_IPW_IRQ_SW_MAJOR_VERSION_C != ETH_43_GMAC_IPW_SW_MAJOR_VERSION) || \
     (ETH_43_GMAC_IPW_IRQ_SW_MINOR_VERSION_C != ETH_43_GMAC_IPW_SW_MINOR_VERSION) || \
     (ETH_43_GMAC_IPW_IRQ_SW_PATCH_VERSION_C != ETH_43_GMAC_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eth_43_GMAC_Ipw_Irq.c and Eth_43_GMAC_Ipw.h are different"
#endif

/* Checks against Gmac_Ip_Types.h */
#if (ETH_43_GMAC_IPW_IRQ_VENDOR_ID_C != GMAC_IP_TYPES_VENDOR_ID)
    #error "Eth_43_GMAC_Ipw_Irq.c and Gmac_Ip_Types.h have different vendor ids"
#endif
#if ((ETH_43_GMAC_IPW_IRQ_AR_RELEASE_MAJOR_VERSION_C    != GMAC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_43_GMAC_IPW_IRQ_AR_RELEASE_MINOR_VERSION_C    != GMAC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ETH_43_GMAC_IPW_IRQ_AR_RELEASE_REVISION_VERSION_C != GMAC_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Eth_43_GMAC_Ipw_Irq.c and Gmac_Ip_Types.h are different"
#endif
#if ((ETH_43_GMAC_IPW_IRQ_SW_MAJOR_VERSION_C != GMAC_IP_TYPES_SW_MAJOR_VERSION) || \
     (ETH_43_GMAC_IPW_IRQ_SW_MINOR_VERSION_C != GMAC_IP_TYPES_SW_MINOR_VERSION) || \
     (ETH_43_GMAC_IPW_IRQ_SW_PATCH_VERSION_C != GMAC_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Eth_43_GMAC_Ipw_Irq.c and Gmac_Ip_Types.h are different"
#endif

#if (STD_ON == ETH_43_GMAC_DEM_EVENT_DETECT)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Dem.h */
    #if ((ETH_43_GMAC_IPW_IRQ_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_43_GMAC_IPW_IRQ_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Eth_43_GMAC_Ipw_Irq.c and Dem.h are different"
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
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define ETH_43_GMAC_START_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"


void Eth_43_GMAC_Ipw_SafetyIrqCallback(const uint8 CtrlIdx, const Gmac_Ip_SafetyErrorType Error);
void Eth_43_GMAC_Ipw_SafetyIrqCallback(const uint8 CtrlIdx, const Gmac_Ip_SafetyErrorType Error)
{
    /* If Dem event enabled for safety */
#if (STD_ON == ETH_43_GMAC_DEM_EVENT_DETECT)
    if ((uint32)STD_ON == (uint32)(Eth_43_GMAC_Ipw_apxInternalCfg[CtrlIdx]->Eth_43_GMAC_Ipw_DemEventsList.ETH_43_GMAC_IPW_E_SAFETY_Cfg.state))
    {
        (void)Dem_SetEventStatus((Dem_EventIdType)(Eth_43_GMAC_Ipw_apxInternalCfg[CtrlIdx]->Eth_43_GMAC_Ipw_DemEventsList.ETH_43_GMAC_IPW_E_SAFETY_Cfg.id), DEM_EVENT_STATUS_FAILED);
    }
#endif
    (void)CtrlIdx;
    (void)Error;
}


#define ETH_43_GMAC_STOP_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
