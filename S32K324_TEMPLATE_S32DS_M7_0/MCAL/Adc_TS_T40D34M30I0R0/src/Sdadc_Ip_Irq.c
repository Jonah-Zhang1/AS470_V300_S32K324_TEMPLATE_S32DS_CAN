/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : ADC_SAR
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
*   @file Sdadc_Ip_Irq.c
*
*   @addtogroup IP_SDADC
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
#include "Sdadc_Ip_Irq.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SDADC_IP_VENDOR_ID_IRQ_C                      43
#define SDADC_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C       4
#define SDADC_IP_AR_RELEASE_MINOR_VERSION_IRQ_C       7
#define SDADC_IP_AR_RELEASE_REVISION_VERSION_IRQ_C    0
#define SDADC_IP_SW_MAJOR_VERSION_IRQ_C               3
#define SDADC_IP_SW_MINOR_VERSION_IRQ_C               0
#define SDADC_IP_SW_PATCH_VERSION_IRQ_C               0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if SDADC_Ip_Irq.c file and SDADC_Ip_Irq.h file are of the same vendor */
#if (SDADC_IP_VENDOR_ID_IRQ_C != SDADC_IP_VENDOR_ID_IRQ)
    #error "SDADC_Ip_Irq.c and SDADC_Ip_Irq.h have different vendor ids"
#endif

/* Check if SDADC_Ip_Irq.c file and SDADC_Ip_Irq.h file are of the same Autosar version */
#if ((SDADC_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C != SDADC_IP_AR_RELEASE_MAJOR_VERSION_IRQ) || \
     (SDADC_IP_AR_RELEASE_MINOR_VERSION_IRQ_C != SDADC_IP_AR_RELEASE_MINOR_VERSION_IRQ) || \
     (SDADC_IP_AR_RELEASE_REVISION_VERSION_IRQ_C != SDADC_IP_AR_RELEASE_REVISION_VERSION_IRQ) \
    )
    #error "AutoSar Version Numbers of SDADC_Ip_Irq.c and SDADC_Ip_Irq.h are different"
#endif

/* Check if SDADC_Ip_Irq.c file and SDADC_Ip_Irq.h file are of the same Software version */
#if ((SDADC_IP_SW_MAJOR_VERSION_IRQ_C != SDADC_IP_SW_MAJOR_VERSION_IRQ) || \
     (SDADC_IP_SW_MINOR_VERSION_IRQ_C != SDADC_IP_SW_MINOR_VERSION_IRQ) || \
     (SDADC_IP_SW_PATCH_VERSION_IRQ_C != SDADC_IP_SW_PATCH_VERSION_IRQ) \
    )
  #error "Software Version Numbers of SDADC_Ip_Irq.c and SDADC_Ip_Irq.h are different"
#endif

#ifdef FEATURE_ADC_HAS_SDADC


/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

/*FUNCTION**********************************************************************
*
* Function Name : Sdadc_Isr
* Note that: depending on platform, there might be multiple SDADC instances which use the same IRQ number.
*
* END**************************************************************************/
ISR(Sdadc_Isr)
{
    /* Call IRQ handler */
    Sdadc_Ip_IRQHandler();
}

#if (SDADC_IP_DSPSS_ENABLED == STD_ON)
/*FUNCTION**********************************************************************
*
* Function Name : Dspss_Thread_X_Isr
* Brief: Interrupt for FIFO full
*
* END**************************************************************************/
ISR(Dspss_Thread_0_Isr)
{
    /* Call IRQ handler for thread 0 */
    Dspss_IRQHandler(0UL);
}
ISR(Dspss_Thread_1_Isr)
{
    /* Call IRQ handler for thread 1 */
    Dspss_IRQHandler(1UL);
}
ISR(Dspss_Thread_2_Isr)
{
    /* Call IRQ handler for thread 2 */
    Dspss_IRQHandler(2UL);
}
ISR(Dspss_Thread_3_Isr)
{
    /* Call IRQ handler for thread 3 */
    Dspss_IRQHandler(3UL);
}
#endif /* (SDADC_IP_DSPSS_ENABLED == STD_ON) */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"


/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/


#endif /* FEATURE_ADC_HAS_SDADC */


#ifdef __cplusplus
}
#endif

/** @} */
