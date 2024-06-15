/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : eMios
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

#ifndef OCU_ENV_CFG_H
#define OCU_ENV_CFG_H

/**
*   @file          Ocu_EnvCfg.h
*
*   @addtogroup    ocu_driver Ocu Driver
*   @brief         Ocu HLD Environment configuration header file.
*   @details       Ocu environment configuration header.
*
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif


/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/

/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define OCU_ENVCFG_VENDOR_ID                        43

#define OCU_ENVCFG_AR_RELEASE_MAJOR_VERSION         4
#define OCU_ENVCFG_AR_RELEASE_MINOR_VERSION         7
#define OCU_ENVCFG_AR_RELEASE_REVISION_VERSION      0

#define OCU_ENVCFG_SW_MAJOR_VERSION                 3
#define OCU_ENVCFG_SW_MINOR_VERSION                 0
#define OCU_ENVCFG_SW_PATCH_VERSION                 0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

/* External environment the Ocu driver currently supports */

#define OCU_ENV_FTE   (STD_ON)

#if (OCU_ENV_FTE == STD_ON)
    /* FTE environment */
    #define OCU_PARAM_CHECK                  (OCU_DEV_ERROR_DETECT)
    #define OCU_USER_MODE_SOFT_LOCKING       (STD_OFF)

    #define OCU_VALIDATE_GLOBAL_CONFIG_CALL  (OCU_DEV_ERROR_DETECT)
    #define OCU_VALIDATE_CHANNEL_CONFIG_CALL (OCU_DEV_ERROR_DETECT)
#else
    #define OCU_PARAM_CHECK                  (STD_OFF)
    #define OCU_USER_MODE_SOFT_LOCKING       (STD_OFF)

    #define OCU_VALIDATE_GLOBAL_CONFIG_CALL  (STD_OFF)
    #define OCU_VALIDATE_CHANNEL_CONFIG_CALL (STD_OFF)
#endif

/*===============================================================================================
*                                             ENUMS
===============================================================================================*/

/*===============================================================================================
*                            STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/*===============================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
                                     FUNCTION PROTOTYPES
===============================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* OCU_ENV_CFG_H */
