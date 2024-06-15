/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : I2S
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_P10_D2307_ASR_REL_4_7_REV_0000_20230726
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
*   @addtogroup sai_ip SAI IPL
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
#include "Mcal.h"
#include "OsIf.h"
#include "Sai_Ip_DeviceRegisters.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SAI_IP_ISR_VENDOR_ID_C                      43
#define SAI_IP_ISR_AR_RELEASE_MAJOR_VERSION_C       4
#define SAI_IP_ISR_AR_RELEASE_MINOR_VERSION_C       7
#define SAI_IP_ISR_AR_RELEASE_REVISION_VERSION_C    0
#define SAI_IP_ISR_SW_MAJOR_VERSION_C               3
#define SAI_IP_ISR_SW_MINOR_VERSION_C               0
#define SAI_IP_ISR_SW_PATCH_VERSION_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and Mcal header file are of the same Autosar version */
#if ((SAI_IP_ISR_AR_RELEASE_MAJOR_VERSION_C     != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (SAI_IP_ISR_AR_RELEASE_MINOR_VERSION_C     != MCAL_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Sai_Ip_Isr.c and Mcal.h are different"
#endif

/* Check if current file and OsIf header file are of the same Autosar version */
#if ((SAI_IP_ISR_AR_RELEASE_MAJOR_VERSION_C     != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (SAI_IP_ISR_AR_RELEASE_MINOR_VERSION_C     != OSIF_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Sai_Ip_Isr.c and OsIf.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if current file and Sai_Ip_DeviceRegisters header file are of the same vendor */
#if (SAI_IP_ISR_VENDOR_ID_C != SAI_IP_DEVICEREGISTERS_VENDOR_ID)
#error "Sai_Ip_Isr.c and Sai_Ip_DeviceRegisters.h have different vendor ids"
#endif

/* Check if current file and Sai_Ip_DeviceRegisters header file are of the same Autosar version */
#if ((SAI_IP_ISR_AR_RELEASE_MAJOR_VERSION_C     != SAI_IP_DEVICEREGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (SAI_IP_ISR_AR_RELEASE_MINOR_VERSION_C     != SAI_IP_DEVICEREGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (SAI_IP_ISR_AR_RELEASE_REVISION_VERSION_C  != SAI_IP_DEVICEREGISTERS_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Sai_Ip_Isr.c and Sai_Ip_DeviceRegisters.h are different"
#endif

/* Check if current file and Sai_Ip_DeviceRegisters header file are of the same software version */
#if ((SAI_IP_ISR_SW_MAJOR_VERSION_C != SAI_IP_DEVICEREGISTERS_SW_MAJOR_VERSION) || \
     (SAI_IP_ISR_SW_MINOR_VERSION_C != SAI_IP_DEVICEREGISTERS_SW_MINOR_VERSION) || \
     (SAI_IP_ISR_SW_PATCH_VERSION_C != SAI_IP_DEVICEREGISTERS_SW_PATCH_VERSION))
#error "Software Version Numbers of Sai_Ip_Isr.c and Sai_Ip_DeviceRegisters.h are different"
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

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#if (STD_ON == SAI_IP_ENABLE)

#define I2S_START_SEC_CODE
#include "I2s_MemMap.h"

extern void Sai_Ip_IRQHandler(const uint8 u8Instance);

#if (defined(SAI_IP_TX_ISR0_USED) || defined(SAI_IP_RX_ISR0_USED))
/* Implementation of SAI0 handler named in startup code. */
ISR(SAI0_IRQHandler); /* IAR requires prototypes. */

ISR(SAI0_IRQHandler)
{
    Sai_Ip_IRQHandler((uint8)0U);
    EXIT_INTERRUPT();
}
#endif /* (defined(SAI_IP_TX_ISR0_USED) || defined(SAI_IP_RX_ISR0_USED)) */
#if (defined(SAI_IP_TX_ISR1_USED) || defined(SAI_IP_RX_ISR1_USED))
/* Implementation of SAI1 handler named in startup code. */
ISR(SAI1_IRQHandler); /* IAR requires prototypes. */

ISR(SAI1_IRQHandler)
{
    Sai_Ip_IRQHandler((uint8)1U);
    EXIT_INTERRUPT();
}
#endif /* (defined(SAI_IP_TX_ISR1_USED) || defined(SAI_IP_RX_ISR1_USED)) */


#if (STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE)
extern void Sai_Ip_CompleteSendDataUsingDma(const uint8 u8Instance,
                                            boolean error);
extern void Sai_Ip_CompleteReceiveDataUsingDma(const uint8 u8Instance,
                                               boolean error);

#ifdef SAI_IP_TX_DMA0_USED
/* Implementation of Sai0 Tx callback function for Dma interrupt.
 * @implements    Sai_0_Ip_DmaTxCompleteCallback_Activity
 */
void Sai_0_Ip_DmaTxCompleteCallback(void);
void Sai_0_Ip_DmaTxCompleteCallback(void)
{
    Sai_Ip_CompleteSendDataUsingDma(0U, FALSE);
}
/* Implementation of Sai0 Tx callback function for Dma Error interrupt.
 * @implements    Sai_0_Ip_DmaTxErrorCallback_Activity
 */
void Sai_0_Ip_DmaTxErrorCallback(void);
void Sai_0_Ip_DmaTxErrorCallback(void)
{
    Sai_Ip_CompleteSendDataUsingDma(0U, TRUE);
}
#endif /* SAI_IP_TX_DMA0_USED */
#ifdef SAI_IP_RX_DMA0_USED
/* Implementation of Sai0 Rx callback function for Dma interrupt.
 * @implements    Sai_0_Ip_DmaRxCompleteCallback_Activity
 */
void Sai_0_Ip_DmaRxCompleteCallback(void);
void Sai_0_Ip_DmaRxCompleteCallback(void)
{
    Sai_Ip_CompleteReceiveDataUsingDma(0U, FALSE);
}
/* Implementation of Sai0 Rx callback function for Dma Error interrupt.
 * @implements    Sai_0_Ip_DmaRxErrorCallback_Activity
 */
void Sai_0_Ip_DmaRxErrorCallback(void);
void Sai_0_Ip_DmaRxErrorCallback(void)
{
    Sai_Ip_CompleteReceiveDataUsingDma(0U, TRUE);
}
#endif /* SAI_IP_RX_DMA0_USED */
#ifdef SAI_IP_TX_DMA1_USED
/* Implementation of Sai1 Tx callback function for Dma interrupt.
 * @implements    Sai_1_Ip_DmaTxCompleteCallback_Activity
 */
void Sai_1_Ip_DmaTxCompleteCallback(void);
void Sai_1_Ip_DmaTxCompleteCallback(void)
{
    Sai_Ip_CompleteSendDataUsingDma(1U, FALSE);
}
/* Implementation of Sai1 Tx callback function for Dma Error interrupt.
 * @implements    Sai_1_Ip_DmaTxErrorCallback_Activity
 */
void Sai_1_Ip_DmaTxErrorCallback(void);
void Sai_1_Ip_DmaTxErrorCallback(void)
{
    Sai_Ip_CompleteSendDataUsingDma(1U, TRUE);
}
#endif /* SAI_IP_TX_DMA1_USED */
#ifdef SAI_IP_RX_DMA1_USED
/* Implementation of Sai1 Rx callback function for Dma interrupt.
 * @implements    Sai_1_Ip_DmaRxCompleteCallback_Activity
 */
void Sai_1_Ip_DmaRxCompleteCallback(void);
void Sai_1_Ip_DmaRxCompleteCallback(void)
{
    Sai_Ip_CompleteReceiveDataUsingDma(1U, FALSE);
}
/* Implementation of Sai1 Rx callback function for Dma Error interrupt.
 * @implements    Sai_1_Ip_DmaRxErrorCallback_Activity
 */
void Sai_1_Ip_DmaRxErrorCallback(void);
void Sai_1_Ip_DmaRxErrorCallback(void)
{
    Sai_Ip_CompleteReceiveDataUsingDma(1U, TRUE);
}
#endif /* SAI_IP_RX_DMA1_USED */
#endif /* (STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE) */

#define I2S_STOP_SEC_CODE
#include "I2s_MemMap.h"

#endif /* (STD_ON == SAI_IP_ENABLE) */

#ifdef __cplusplus
}
#endif

/** @} */
