/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : C40
*   Dependencies         : None
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
 * @file       C40_Ip_Ac.c
 *
 * @addtogroup C40_IP
 * implement   C40_Ip_Ac.c_Artifact
 *
 * @{
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
#include "C40_Ip.h"
#include "C40_Ip_Ac.h"
#include "C40_Ip_Cfg.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define C40_IP_AC_VENDOR_ID_C                      43
#define C40_IP_AC_AR_RELEASE_MAJOR_VERSION_C       4
#define C40_IP_AC_AR_RELEASE_MINOR_VERSION_C       7
#define C40_IP_AC_AR_RELEASE_REVISION_VERSION_C    0
#define C40_IP_AC_SW_MAJOR_VERSION_C               3
#define C40_IP_AC_SW_MINOR_VERSION_C               0
#define C40_IP_AC_SW_PATCH_VERSION_C               0

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and C40_Ip header file are of the same vendor */
#if (C40_IP_AC_VENDOR_ID_C != C40_IP_VENDOR_ID_H)
    #error "C40_Ip_Ac.c and C40_Ip.h have different vendor ids"
#endif
/* Check if current file and C40_Ip header file are of the same Autosar version */
#if ((C40_IP_AC_AR_RELEASE_MAJOR_VERSION_C    != C40_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (C40_IP_AC_AR_RELEASE_MINOR_VERSION_C    != C40_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (C40_IP_AC_AR_RELEASE_REVISION_VERSION_C != C40_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of C40_Ip_Ac.c and C40_Ip.h are different"
#endif
/* Check if current file and C40_Ip header file are of the same Software version */
#if ((C40_IP_AC_SW_MAJOR_VERSION_C != C40_IP_SW_MAJOR_VERSION_H) || \
     (C40_IP_AC_SW_MINOR_VERSION_C != C40_IP_SW_MINOR_VERSION_H) || \
     (C40_IP_AC_SW_PATCH_VERSION_C != C40_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of C40_Ip_Ac.c and C40_Ip.h are different"
#endif

/* Check if current file and C40_Ip_Ac.h header file have the same Vendor ID */
#if (C40_IP_AC_VENDOR_ID_C != C40_IP_AC_VENDOR_ID_H)
    #error "C40_Ip_Ac.c and C40_Ip_Ac.h have different vendor ids"
#endif
/* Check if current file and C40_Ip_Ac.h  header file are of the same Autosar version */
#if ((C40_IP_AC_AR_RELEASE_MAJOR_VERSION_C    != C40_IP_AC_AR_RELEASE_MAJOR_VERSION_H) || \
     (C40_IP_AC_AR_RELEASE_MINOR_VERSION_C    != C40_IP_AC_AR_RELEASE_MINOR_VERSION_H) || \
     (C40_IP_AC_AR_RELEASE_REVISION_VERSION_C != C40_IP_AC_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of C40_Ip_Ac.c and C40_Ip_Ac.h are different"
#endif
/* Check if current file and C40_Ip_Ac.h  header file are of the same Software version */
#if ((C40_IP_AC_SW_MAJOR_VERSION_C != C40_IP_AC_SW_MAJOR_VERSION_H) || \
     (C40_IP_AC_SW_MINOR_VERSION_C != C40_IP_AC_SW_MINOR_VERSION_H) || \
     (C40_IP_AC_SW_PATCH_VERSION_C != C40_IP_AC_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of C40_Ip_Ac.c and C40_Ip_Ac.h are different"
#endif

/* Check if current file and C40_Ip_Cfg header file have the same Vendor ID */
#if (C40_IP_AC_VENDOR_ID_C != C40_IP_VENDOR_ID_CFG)
    #error "C40_Ip_Ac.c and C40_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and C40_Ip_Cfg.h  header file are of the same Autosar version */
#if ((C40_IP_AC_AR_RELEASE_MAJOR_VERSION_C    != C40_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (C40_IP_AC_AR_RELEASE_MINOR_VERSION_C    != C40_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (C40_IP_AC_AR_RELEASE_REVISION_VERSION_C != C40_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of C40_Ip_Ac.c and C40_Ip_Cfg.h are different"
#endif
/* Check if current file and C40_Ip_Cfg.h  header file are of the same Software version */
#if ((C40_IP_AC_SW_MAJOR_VERSION_C != C40_IP_SW_MAJOR_VERSION_CFG) || \
     (C40_IP_AC_SW_MINOR_VERSION_C != C40_IP_SW_MINOR_VERSION_CFG) || \
     (C40_IP_AC_SW_PATCH_VERSION_C != C40_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of C40_Ip_Ac.c and C40_Ip_Cfg.h are different"
#endif

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                      GLOBAL FUNCTIONS
==================================================================================================*/
#define MEM_43_INFLS_START_SEC_CODE_AC
#include "Mem_43_INFLS_MemMap.h"

/**
 * @brief Position independent erase/write access code
 *
 * @param CallBack      Callback notification configured by "Mem Access Code Callback"
 */
#if (C40_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
void C40_Ip_AccessCode(void (*CallBack)( void ) )
{
    uint32 ValueTimeOut = C40_Ip_u32TimeoutTicks;
    uint32 WaitedTicks;

    /* start internal erase/program sequence */
    C40_Ip_pFlashBaseAddress->MCR |= FLASH_MCR_EHV_MASK;

    /* wait until operation finishes or write/erase timeout is reached */
    while ((0U == (C40_Ip_pFlashBaseAddress->MCRS & FLASH_MCRS_DONE_MASK)) && (0U < ValueTimeOut))
    {
        ValueTimeOut--;
        if (NULL_PTR != CallBack)
        {
            CallBack();
        }
    }

    /* disable HV to finalize/abort the operation */
    C40_Ip_pFlashBaseAddress->MCR &= ~FLASH_MCR_EHV_MASK;

    /* wait until done or abort timeout is reached */
    while ((0U == (C40_Ip_pFlashBaseAddress->MCRS & FLASH_MCRS_DONE_MASK)) && (0U < ValueTimeOut))
    {
        ValueTimeOut--;
        if (NULL_PTR != CallBack)
        {
            CallBack();
        }
    }

    /* Update the timeout counter */
    WaitedTicks = C40_Ip_u32TimeoutTicks - ValueTimeOut;
    C40_Ip_u32ElapsedTicks += WaitedTicks;
    C40_Ip_u32CurrentTicks += WaitedTicks;
}
#else

void C40_Ip_AccessCode(void (*CallBack)( void ) )
{
    /* start internal erase/program sequence */
    C40_Ip_pFlashBaseAddress->MCR |= FLASH_MCR_EHV_MASK;
    /* wait until operation finishes or write/erase timeout is reached */
    while (0U == (C40_Ip_pFlashBaseAddress->MCRS & FLASH_MCRS_DONE_MASK))
    {
        if (NULL_PTR != CallBack)
        {
            CallBack();
        }
    }
    /* disable HV to finalize/abort the operation */
    C40_Ip_pFlashBaseAddress->MCR &= ~FLASH_MCR_EHV_MASK;
}
#endif /* C40_TIMEOUT_SUPERVISION_ENABLED == STD_ON */


#define MEM_43_INFLS_STOP_SEC_CODE_AC
#include "Mem_43_INFLS_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
