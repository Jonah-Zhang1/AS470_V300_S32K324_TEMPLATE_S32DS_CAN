/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_P07_D2306_ASR_REL_4_7_REV_0000_20230629
*
*   (c) Copyright 2020 - 2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef INTCTRL_IP_CFG_DEFINES_H_
#define INTCTRL_IP_CFG_DEFINES_H_

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "StandardTypes.h"
#ifdef SJA1110
#include "SJA1110.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_INTCTRL_IP_CFG_DEFINES_VENDOR_ID                          43
#define CDD_PLATFORM_INTCTRL_IP_CFG_DEFINES_SW_MAJOR_VERSION                   3
#define CDD_PLATFORM_INTCTRL_IP_CFG_DEFINES_SW_MINOR_VERSION                   0
#define CDD_PLATFORM_INTCTRL_IP_CFG_DEFINES_SW_PATCH_VERSION                   0
#define CDD_PLATFORM_INTCTRL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION           4
#define CDD_PLATFORM_INTCTRL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION           7
#define CDD_PLATFORM_INTCTRL_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION        0
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* CPU to CPU interrupt (MSI) routing through MSCM */
#define INT_CTRL_IP_MSI_AVAILABLE                 (STD_ON)

#ifdef S32K344
        #include "S32K344_NVIC.h"
        #include "S32K344_MSCM.h"
        #include "S32K344_SCB.h"
#endif

#ifdef S32K342
        #include "S32K342_NVIC.h"
        #include "S32K342_MSCM.h"
        #include "S32K342_SCB.h"
#endif

#ifdef S32K341
        #include "S32K341_NVIC.h"
        #include "S32K341_MSCM.h"
        #include "S32K341_SCB.h"
#endif

#ifdef S32K324
        #include "S32K324_NVIC.h"
        #include "S32K324_MSCM.h"
        #include "S32K324_SCB.h"
#endif

#ifdef S32K314
        #include "S32K314_NVIC.h"
        #include "S32K314_MSCM.h"
        #include "S32K314_SCB.h"
#endif

#ifdef S32K312
        #include "S32K312_NVIC.h"
        #include "S32K312_MSCM.h"
        #include "S32K312_SCB.h"
#endif

#ifdef S32K322
        #include "S32K322_NVIC.h"
        #include "S32K322_MSCM.h"
        #include "S32K322_SCB.h"
#endif

#if defined(S32K396) || defined(S32K394)
        #include "S32K39_NVIC.h"
        #include "S32K39_MSCM.h"
        #include "S32K39_SCB.h"
#endif

#if defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358)
        #include "S32K358_NVIC.h"
        #include "S32K358_MSCM.h"
        #include "S32K358_SCB.h"
#endif

#ifdef S32K388
        #include "S32K388_NVIC.h"
        #include "S32K388_MSCM.h"
        #include "S32K388_SCB.h"
#endif

#if defined(S32K311) || defined(S32K310)
        #include "S32K311_NVIC.h"
        #include "S32K311_MSCM.h"
        #include "S32K311_SCB.h"
#endif

#if defined(S32M276) || defined(S32M274)
        #include "S32M27x_NVIC.h"
        #include "S32M27x_MSCM.h"
        #include "S32M27x_SCB.h"
#endif

#ifdef S32N2RT
        #include "S32N2RT_NVIC.h"
        #include "S32N2RT_MSCM.h"
        #include "S32N2RT_SCB.h"
#endif

#if (INT_CTRL_IP_MSI_AVAILABLE == STD_ON)
        typedef struct {
            __IO uint32_t IntStatusR;  /**< Interrupt Router CPn Interruptx Status Register, array offset: 0x200, index*0x20, index2*0x8 */
            __O  uint32_t IGR;  /**< Interrupt Router CPn Interruptx Generation Register, array offset: 0x204, index*0x20, index2*0x8 */
        } MSCM_IRCP_IR_Type;

        typedef struct {
            MSCM_IRCP_IR_Type IRCPnIRx[4][4];
        } MSCM_IRCPnIRx_Type;
        
        #define MSCM_IRCPnIRx ((volatile MSCM_IRCPnIRx_Type*)&IP_MSCM->IRCP0ISR0)
#endif 
       
        


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* Development error detection */
#define INT_CTRL_IP_DEV_ERROR_DETECT  (STD_ON)

#if (INT_CTRL_IP_MSI_AVAILABLE == STD_ON)
/* MSI target core count */
#define INT_CTRL_IP_MSI_CORE_CNT                   (2U)
/* MSI vector min */
#define INT_CTRL_IP_DIRECTED_CPU_INT_MIN           (INT0_IRQn)

/* MSI vector max */
#define INT_CTRL_IP_DIRECTED_CPU_INT_MAX           (INT3_IRQn)
#endif

/* VTOR address configuration enable */
#define INT_CTRL_IP_ENABLE_VTOR_CONFIG             (STD_OFF)

/* System interrupt routing through MSCM */
#define INT_CTRL_IP_MSCM_SYSTEM_INTERRUPT_ROUTER  (STD_OFF)

/* INCT CTRL IP standalone APIs */
#define INT_CTRL_IP_STANDALONE_APIS               (STD_OFF)
    /* First implemented interrupt vector */
    #define INT_CTRL_IP_IRQ_MIN                       (INT0_IRQn)
    
    /* Last implemented interrupt vector */
    #define INT_CTRL_IP_IRQ_MAX                       (SoC_PLL_IRQn)  
    /* The interrupt counter value*/
    #define INT_CTRL_IP_IRQ_COUNT                     (154U)
    /* Arm Cortex M4 */
    #define INT_CTRL_IP_CORTEXM                      (STD_ON)
    #define INT_CTRL_IP_CORTEXR              STD_OFF
    #define INT_CTRL_IP_CORTEXA              STD_OFF   
    #define INT_CTRL_MCAL_ARM_MARCH_SMU      STD_OFF   

 

/* Number of nvic priority bits implemented */
#define INT_CTRL_IP_NVIC_PRIO_BITS                (4U)

/*Interrupt Router Shared Peripheral Routing Control Register*/
#define INT_CTRL_IP_ROUTING_CONTROL_REGISTER      (STD_ON)

/* This instruction invalidates the entire instruction cache or caches */
#define INT_CTRL_IP_INVALIDATE_CACHE              (STD_OFF)


/**
* @brief Support for User mode.
*        If this parameter has been configured to 'STD_ON', the Int Ctrl PLATFORM driver code can be executed from both supervisor and user mode.
*/

#define INTCTRL_PLATFORM_ENABLE_USER_MODE_SUPPORT   (STD_OFF)


#endif /* INTCTRL_IP_CFG_DEFINES_H_ */

