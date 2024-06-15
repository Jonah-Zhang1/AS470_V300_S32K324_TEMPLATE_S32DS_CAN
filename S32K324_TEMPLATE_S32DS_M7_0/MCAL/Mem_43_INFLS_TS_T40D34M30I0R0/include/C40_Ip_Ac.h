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

#ifndef C40_IP_AC_H
#define C40_IP_AC_H

/**
 * @file       C40_Ip_Ac.h
 *
 * @addtogroup C40_IP
 * implement   C40_Ip_Ac.h_Artifact
 *
 * @{
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


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define C40_IP_AC_VENDOR_ID_H                      43
#define C40_IP_AC_AR_RELEASE_MAJOR_VERSION_H       4
#define C40_IP_AC_AR_RELEASE_MINOR_VERSION_H       7
#define C40_IP_AC_AR_RELEASE_REVISION_VERSION_H    0
#define C40_IP_AC_SW_MAJOR_VERSION_H               3
#define C40_IP_AC_SW_MINOR_VERSION_H               0
#define C40_IP_AC_SW_PATCH_VERSION_H               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define MEM_43_INFLS_START_SEC_CODE_AC
#include "Mem_43_INFLS_MemMap.h"

#ifdef _LINARO_C_S32K3XX_
    void C40_Ip_AccessCode(void (*CallBack)( void ) ) __attribute__ ((section (".acfls_code_rom")));
#else
    void C40_Ip_AccessCode(void (*CallBack)( void ) );
#endif

#define MEM_43_INFLS_STOP_SEC_CODE_AC
#include "Mem_43_INFLS_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* C40_IP_AC_H */
