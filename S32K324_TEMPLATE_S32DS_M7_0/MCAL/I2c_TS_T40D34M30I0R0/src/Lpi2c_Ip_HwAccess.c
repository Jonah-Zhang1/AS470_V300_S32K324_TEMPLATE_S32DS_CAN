/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPI2C
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
*     @file
*
*     @addtogroup LPI2C_DRIVER Lpi2c Driver
*     @{
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
#include "Lpi2c_Ip_HwAccess.h"
#include "OsIf.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPI2C_IP_HWACCESS_VENDOR_ID_C                      43
#define LPI2C_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_C       4
#define LPI2C_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_C       7
#define LPI2C_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_C    0
#define LPI2C_IP_HWACCESS_SW_MAJOR_VERSION_C               3
#define LPI2C_IP_HWACCESS_SW_MINOR_VERSION_C               0
#define LPI2C_IP_HWACCESS_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Checks against Lpi2c_Ip_HwAccess.h */
#if ( LPI2C_IP_HWACCESS_VENDOR_ID_C != LPI2C_IP_HWACCESS_VENDOR_ID)
    #error "Lpi2c_Ip_HwAccess.c and Lpi2c_Ip_HwAccess.h have different vendor ids"
#endif
#if (( LPI2C_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_C    != LPI2C_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
     ( LPI2C_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_C    != LPI2C_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
     ( LPI2C_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_C != LPI2C_IP_HWACCESS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Lpi2c_Ip_HwAccess.c and Lpi2c_Ip_HwAccess.h are different"
#endif
#if (( LPI2C_IP_HWACCESS_SW_MAJOR_VERSION_C != LPI2C_IP_HWACCESS_SW_MAJOR_VERSION) || \
     ( LPI2C_IP_HWACCESS_SW_MINOR_VERSION_C != LPI2C_IP_HWACCESS_SW_MINOR_VERSION) || \
     ( LPI2C_IP_HWACCESS_SW_PATCH_VERSION_C != LPI2C_IP_HWACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lpi2c_Ip_HwAccess.c and Lpi2c_Ip_HwAccess.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ( (LPI2C_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
          (LPI2C_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Lpi2c_Ip_HwAccess.c and OsIf.h are different"
    #endif
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Wrap-around value for timeout */
#define I2C_TIMEOUT_WRAP     (0xFFFFFFFFU)

#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"
/*******************************************************************************
 * Code
 ******************************************************************************/
/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Timeout
 * Description   : Checks for timeout condition
 *
 *END**************************************************************************/

/*FUNCTION**********************************************************************
 *
 * Function Name : Lpi2c_Ip_Init
 * Description   : This function initializes the LPI2C module to a known
 * state (use software reset bit to reset the module).
 *
 * Implements : Lpi2c_Ip_Init_Activity
 *END**************************************************************************/
void Lpi2c_Ip_Init(LPI2C_Type *BaseAddr)
{
    /*
     * The MCR[RST] will reset all master logic and registers to their default state,
     * except for the MCR itself. The SCR[RST] will reset all slave logic and registers
     * to their default state, except for the SCR itself. So we must reset the control
     * registers manually;
     */
    LPI2C_Set_MasterSoftwareReset(BaseAddr, TRUE);
    LPI2C_Set_SlaveSoftwareReset(BaseAddr, TRUE);

    BaseAddr->MCR = 0x0U;
    BaseAddr->SCR = 0x0U;
}

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

