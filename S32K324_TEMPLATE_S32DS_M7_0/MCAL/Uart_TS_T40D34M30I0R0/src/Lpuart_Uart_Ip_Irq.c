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
*   @defgroup lpuart_uart_ip Lpuart UART IPL
*   @addtogroup  lpuart_uart_ip Lpuart UART IPL
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Lpuart_Uart_Ip.h"
#include "Lpuart_Uart_Ip_Irq.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPUART_UART_IP_IRQ_VENDOR_ID_C                      43
#define LPUART_UART_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define LPUART_UART_IP_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define LPUART_UART_IP_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define LPUART_UART_IP_IRQ_SW_MAJOR_VERSION_C               3
#define LPUART_UART_IP_IRQ_SW_MINOR_VERSION_C               0
#define LPUART_UART_IP_IRQ_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Lpuart_Uart_Ip.h */
#if (LPUART_UART_IP_IRQ_VENDOR_ID_C != LPUART_UART_IP_VENDOR_ID)
    #error "Lpuart_Uart_Ip_Irq.c and Lpuart_Uart_Ip.h have different vendor ids"
#endif
#if ((LPUART_UART_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != LPUART_UART_IP_AR_RELEASE_MAJOR_VERSION) || \
     (LPUART_UART_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != LPUART_UART_IP_AR_RELEASE_MINOR_VERSION) || \
     (LPUART_UART_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != LPUART_UART_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Lpuart_Uart_Ip_Irq.c and Lpuart_Uart_Ip.h are different"
#endif
#if ((LPUART_UART_IP_IRQ_SW_MAJOR_VERSION_C != LPUART_UART_IP_SW_MAJOR_VERSION) || \
     (LPUART_UART_IP_IRQ_SW_MINOR_VERSION_C != LPUART_UART_IP_SW_MINOR_VERSION) || \
     (LPUART_UART_IP_IRQ_SW_PATCH_VERSION_C != LPUART_UART_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lpuart_Uart_Ip_Irq.c and Lpuart_Uart_Ip.h are different"
#endif
/* Checks against Lpuart_Uart_Ip_Irq.h */
#if (LPUART_UART_IP_IRQ_VENDOR_ID_C != LPUART_UART_IP_IRQ_VENDOR_ID)
    #error "Lpuart_Uart_Ip_Irq.c and Lpuart_Uart_Ip_Irq.h have different vendor ids"
#endif
#if ((LPUART_UART_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != LPUART_UART_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (LPUART_UART_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != LPUART_UART_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (LPUART_UART_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != LPUART_UART_IP_IRQ_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Lpuart_Uart_Ip_Irq.c and Lpuart_Uart_Ip_Irq.h are different"
#endif
#if ((LPUART_UART_IP_IRQ_SW_MAJOR_VERSION_C != LPUART_UART_IP_IRQ_SW_MAJOR_VERSION) || \
     (LPUART_UART_IP_IRQ_SW_MINOR_VERSION_C != LPUART_UART_IP_IRQ_SW_MINOR_VERSION) || \
     (LPUART_UART_IP_IRQ_SW_PATCH_VERSION_C != LPUART_UART_IP_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lpuart_Uart_Ip_Irq.c and Lpuart_Uart_Ip_Irq.h are different"
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

#define UART_START_SEC_CODE
#include "Uart_MemMap.h"

#if (LPUART_INSTANCE_COUNT > 0U)
#ifdef LPUART_UART_IP_INSTANCE_USING_0
/* Implementation of Lpuart0 handler named in startup code. */
ISR(LPUART_UART_IP_0_IRQHandler)
{
    Lpuart_Uart_Ip_IrqHandler(0U);
    EXIT_INTERRUPT();
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 1U)
#ifdef LPUART_UART_IP_INSTANCE_USING_1
/* Implementation of Lpuart1 handler named in startup code. */
ISR(LPUART_UART_IP_1_IRQHandler)
{
    Lpuart_Uart_Ip_IrqHandler(1U);
    EXIT_INTERRUPT();
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 2U)
#ifdef LPUART_UART_IP_INSTANCE_USING_2
/* Implementation of Lpuart2 handler named in startup code. */
ISR(LPUART_UART_IP_2_IRQHandler)
{
    Lpuart_Uart_Ip_IrqHandler(2U);
    EXIT_INTERRUPT();
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 3U)
#ifdef LPUART_UART_IP_INSTANCE_USING_3
/* Implementation of Lpuart3 handler named in startup code. */
ISR(LPUART_UART_IP_3_IRQHandler)
{
    Lpuart_Uart_Ip_IrqHandler(3U);
    EXIT_INTERRUPT();
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 4U)
#ifdef LPUART_UART_IP_INSTANCE_USING_4
/* Implementation of Lpuart4 handler named in startup code. */
ISR(LPUART_UART_IP_4_IRQHandler)
{
    Lpuart_Uart_Ip_IrqHandler(4U);
    EXIT_INTERRUPT();
}
#endif
#ifdef LPUART_UART_IP_INSTANCE_USING_MSC
/* Implementation of Lpuart_Msc handler named in startup code. */
ISR(LPUART_UART_IP_MSC_IRQHandler)
{
    Lpuart_Uart_Ip_IrqHandler(4U);
    EXIT_INTERRUPT();
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 5U)
#ifdef LPUART_UART_IP_INSTANCE_USING_5
/* Implementation of Lpuart5 handler named in startup code. */
ISR(LPUART_UART_IP_5_IRQHandler)
{
    Lpuart_Uart_Ip_IrqHandler(5U);
    EXIT_INTERRUPT();
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 6U)
#ifdef LPUART_UART_IP_INSTANCE_USING_6
/* Implementation of Lpuart6 handler named in startup code. */
ISR(LPUART_UART_IP_6_IRQHandler)
{
    Lpuart_Uart_Ip_IrqHandler(6U);
    EXIT_INTERRUPT();
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 7U)
#ifdef LPUART_UART_IP_INSTANCE_USING_7
/* Implementation of Lpuart7 handler named in startup code. */
ISR(LPUART_UART_IP_7_IRQHandler)
{
    Lpuart_Uart_Ip_IrqHandler(7U);
    EXIT_INTERRUPT();
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 8U)
#ifdef LPUART_UART_IP_INSTANCE_USING_8
/* Implementation of Lpuart8 handler named in startup code. */
ISR(LPUART_UART_IP_8_IRQHandler)
{
    Lpuart_Uart_Ip_IrqHandler(8U);
    EXIT_INTERRUPT();
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 9U)
#ifdef LPUART_UART_IP_INSTANCE_USING_9
/* Implementation of Lpuart9 handler named in startup code. */
ISR(LPUART_UART_IP_9_IRQHandler)
{
    Lpuart_Uart_Ip_IrqHandler(9U);
    EXIT_INTERRUPT();
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 10U)
#ifdef LPUART_UART_IP_INSTANCE_USING_10
/* Implementation of Lpuart10 handler named in startup code. */
ISR(LPUART_UART_IP_10_IRQHandler)
{
    Lpuart_Uart_Ip_IrqHandler(10U);
    EXIT_INTERRUPT();
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 11U)
#ifdef LPUART_UART_IP_INSTANCE_USING_11
/* Implementation of Lpuart11 handler named in startup code. */
ISR(LPUART_UART_IP_11_IRQHandler)
{
    Lpuart_Uart_Ip_IrqHandler(11U);
    EXIT_INTERRUPT();
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 12U)
#ifdef LPUART_UART_IP_INSTANCE_USING_12
/* Implementation of Lpuart12 handler named in startup code. */
ISR(LPUART_UART_IP_12_IRQHandler)
{
    Lpuart_Uart_Ip_IrqHandler(12U);
    EXIT_INTERRUPT();
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 13U)
#ifdef LPUART_UART_IP_INSTANCE_USING_13
/* Implementation of Lpuart13 handler named in startup code. */
ISR(LPUART_UART_IP_13_IRQHandler)
{
    Lpuart_Uart_Ip_IrqHandler(13U);
    EXIT_INTERRUPT();
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 14U)
#ifdef LPUART_UART_IP_INSTANCE_USING_14
/* Implementation of Lpuart14 handler named in startup code. */
ISR(LPUART_UART_IP_14_IRQHandler)
{
    Lpuart_Uart_Ip_IrqHandler(14U);
    EXIT_INTERRUPT();
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 15U)
#ifdef LPUART_UART_IP_INSTANCE_USING_15
/* Implementation of Lpuart15 handler named in startup code. */
ISR(LPUART_UART_IP_15_IRQHandler)
{
    Lpuart_Uart_Ip_IrqHandler(15U);
    EXIT_INTERRUPT();
}
#endif
#endif

#if (LPUART_UART_IP_HAS_DMA_ENABLED == STD_ON)
#if (LPUART_INSTANCE_COUNT > 0U)
#ifdef LPUART_UART_IP_INSTANCE_USING_0
void Lpuart_0_Uart_Ip_DmaRxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteReceiveUsingDma(0);
}
void Lpuart_0_Uart_Ip_DmaTxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteSendUsingDma(0);
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 1U)
#ifdef LPUART_UART_IP_INSTANCE_USING_1
void Lpuart_1_Uart_Ip_DmaRxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteReceiveUsingDma(1);
}
void Lpuart_1_Uart_Ip_DmaTxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteSendUsingDma(1);
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 2U)
#ifdef LPUART_UART_IP_INSTANCE_USING_2
void Lpuart_2_Uart_Ip_DmaRxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteReceiveUsingDma(2);
}
void Lpuart_2_Uart_Ip_DmaTxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteSendUsingDma(2);
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 3U)
#ifdef LPUART_UART_IP_INSTANCE_USING_3
void Lpuart_3_Uart_Ip_DmaRxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteReceiveUsingDma(3);
}
void Lpuart_3_Uart_Ip_DmaTxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteSendUsingDma(3);
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 4U)
#ifdef LPUART_UART_IP_INSTANCE_USING_4
void Lpuart_4_Uart_Ip_DmaRxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteReceiveUsingDma(4);
}
void Lpuart_4_Uart_Ip_DmaTxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteSendUsingDma(4);
}
#endif
#ifdef LPUART_UART_IP_INSTANCE_USING_MSC
/* Implementation of Lpuart MSC Tx callback function for Dma interrupt. */
void Lpuart_MSC_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(4U);
}
/* Implementation of Lpuart MSC Rx callback function for Dma interrupt. */
void Lpuart_MSC_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(4U);
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 5U)
#ifdef LPUART_UART_IP_INSTANCE_USING_5
void Lpuart_5_Uart_Ip_DmaRxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteReceiveUsingDma(5);
}
void Lpuart_5_Uart_Ip_DmaTxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteSendUsingDma(5);
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 6U)
#ifdef LPUART_UART_IP_INSTANCE_USING_6
void Lpuart_6_Uart_Ip_DmaRxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteReceiveUsingDma(6);
}
void Lpuart_6_Uart_Ip_DmaTxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteSendUsingDma(6);
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 7U)
#ifdef LPUART_UART_IP_INSTANCE_USING_7
void Lpuart_7_Uart_Ip_DmaRxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteReceiveUsingDma(7);
}
void Lpuart_7_Uart_Ip_DmaTxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteSendUsingDma(7);
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 8U)
#ifdef LPUART_UART_IP_INSTANCE_USING_8
void Lpuart_8_Uart_Ip_DmaRxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteReceiveUsingDma(8);
}
void Lpuart_8_Uart_Ip_DmaTxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteSendUsingDma(8);
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 9U)
#ifdef LPUART_UART_IP_INSTANCE_USING_9
void Lpuart_9_Uart_Ip_DmaRxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteReceiveUsingDma(9);
}
void Lpuart_9_Uart_Ip_DmaTxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteSendUsingDma(9);
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 10U)
#ifdef LPUART_UART_IP_INSTANCE_USING_10
void Lpuart_10_Uart_Ip_DmaRxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteReceiveUsingDma(10);
}
void Lpuart_10_Uart_Ip_DmaTxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteSendUsingDma(10);
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 11U)
#ifdef LPUART_UART_IP_INSTANCE_USING_11
void Lpuart_11_Uart_Ip_DmaRxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteReceiveUsingDma(11);
}
void Lpuart_11_Uart_Ip_DmaTxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteSendUsingDma(11);
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 12U)
#ifdef LPUART_UART_IP_INSTANCE_USING_12
void Lpuart_12_Uart_Ip_DmaRxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteReceiveUsingDma(12);
}
void Lpuart_12_Uart_Ip_DmaTxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteSendUsingDma(12);
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 13U)
#ifdef LPUART_UART_IP_INSTANCE_USING_13
void Lpuart_13_Uart_Ip_DmaRxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteReceiveUsingDma(13);
}
void Lpuart_13_Uart_Ip_DmaTxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteSendUsingDma(13);
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 14U)
#ifdef LPUART_UART_IP_INSTANCE_USING_14
void Lpuart_14_Uart_Ip_DmaRxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteReceiveUsingDma(14);
}
void Lpuart_14_Uart_Ip_DmaTxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteSendUsingDma(14);
}
#endif
#endif

#if (LPUART_INSTANCE_COUNT > 15U)
#ifdef LPUART_UART_IP_INSTANCE_USING_15
void Lpuart_15_Uart_Ip_DmaRxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteReceiveUsingDma(15);
}
void Lpuart_15_Uart_Ip_DmaTxCompleteCallback(void)
{
    Lpuart_Uart_Ip_CompleteSendUsingDma(15);
}
#endif
#endif
#endif /*(LPUART_UART_IP_HAS_DMA_ENABLED == STD_ON)*/

#define UART_STOP_SEC_CODE
#include "Uart_MemMap.h"

#ifdef __cplusplus
}

/** @} */

#endif
