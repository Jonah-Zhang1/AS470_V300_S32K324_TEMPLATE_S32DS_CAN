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
#include "Eth_43_GMAC.h"
#include "Eth_43_GMAC_Internal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_43_GMAC_IRQ_VENDOR_ID_C                      43
#define ETH_43_GMAC_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define ETH_43_GMAC_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define ETH_43_GMAC_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define ETH_43_GMAC_IRQ_SW_MAJOR_VERSION_C               3
#define ETH_43_GMAC_IRQ_SW_MINOR_VERSION_C               0
#define ETH_43_GMAC_IRQ_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Eth_43_GMAC.h */
#if (ETH_43_GMAC_IRQ_VENDOR_ID_C != ETH_43_GMAC_VENDOR_ID)
    #error "Eth_43_GMAC_Irq.c and Eth_43_GMAC.h have different vendor ids"
#endif
#if ((ETH_43_GMAC_IRQ_AR_RELEASE_MAJOR_VERSION_C    != ETH_43_GMAC_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_43_GMAC_IRQ_AR_RELEASE_MINOR_VERSION_C    != ETH_43_GMAC_AR_RELEASE_MINOR_VERSION) || \
     (ETH_43_GMAC_IRQ_AR_RELEASE_REVISION_VERSION_C != ETH_43_GMAC_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Eth_43_GMAC_Irq.c and Eth_43_GMAC.h are different"
#endif
#if ((ETH_43_GMAC_IRQ_SW_MAJOR_VERSION_C != ETH_43_GMAC_SW_MAJOR_VERSION) || \
     (ETH_43_GMAC_IRQ_SW_MINOR_VERSION_C != ETH_43_GMAC_SW_MINOR_VERSION) || \
     (ETH_43_GMAC_IRQ_SW_PATCH_VERSION_C != ETH_43_GMAC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eth_43_GMAC_Irq.c and Eth_43_GMAC.h are different"
#endif

/* Checks against Eth_43_GMAC_Internal.h */
#if (ETH_43_GMAC_IRQ_VENDOR_ID_C != ETH_43_GMAC_INTERNAL_VENDOR_ID)
    #error "Eth_43_GMAC_Irq.c and Eth_43_GMAC_Internal.h have different vendor ids"
#endif
#if ((ETH_43_GMAC_IRQ_AR_RELEASE_MAJOR_VERSION_C    != ETH_43_GMAC_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_43_GMAC_IRQ_AR_RELEASE_MINOR_VERSION_C    != ETH_43_GMAC_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
     (ETH_43_GMAC_IRQ_AR_RELEASE_REVISION_VERSION_C != ETH_43_GMAC_INTERNAL_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Eth_43_GMAC_Irq.c and Eth_43_GMAC_Internal.h are different"
#endif
#if ((ETH_43_GMAC_IRQ_SW_MAJOR_VERSION_C != ETH_43_GMAC_INTERNAL_SW_MAJOR_VERSION) || \
     (ETH_43_GMAC_IRQ_SW_MINOR_VERSION_C != ETH_43_GMAC_INTERNAL_SW_MINOR_VERSION) || \
     (ETH_43_GMAC_IRQ_SW_PATCH_VERSION_C != ETH_43_GMAC_INTERNAL_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eth_43_GMAC_Irq.c and Eth_43_GMAC_Internal.h are different"
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


#if (STD_ON == ETH_43_GMAC_RX_IRQ_ENABLED)
void Eth_43_GMAC_RxIrqCallback(const uint8 CtrlIdx, const uint8 DMAChannel);
void Eth_43_GMAC_RxIrqCallback(const uint8 CtrlIdx, const uint8 DMAChannel)
{
    Eth_RxStatusType RxStatus = ETH_NOT_RECEIVED;

    /* Driver initialization and spurious IRQ verification is done at the IP level */

    do
    {
        /* Assume there's a 1:1 mapping between Rx Queues and Rx DMA Channels */
        Eth_43_GMAC_Receive(CtrlIdx, DMAChannel, &RxStatus);
    } while (ETH_NOT_RECEIVED != RxStatus);

    /* Do we need a timeout mechanism here? */
}
#endif


#if (STD_ON == ETH_43_GMAC_TX_IRQ_ENABLED)
void Eth_43_GMAC_TxIrqCallback(const uint8 CtrlIdx, const uint8 DMAChannel);
void Eth_43_GMAC_TxIrqCallback(const uint8 CtrlIdx, const uint8 DMAChannel)
{
    /* Driver initialization and spurious IRQ verification is done at the IP level */

    /* Assume there's a 1:1 mapping between Tx Queues and Tx DMA Channels */
    Eth_43_GMAC_ReportTransmission(CtrlIdx, DMAChannel);
}
#endif


#define ETH_43_GMAC_STOP_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
