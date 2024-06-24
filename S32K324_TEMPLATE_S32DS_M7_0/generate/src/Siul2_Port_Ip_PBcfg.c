/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : SIUL2
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
*   @file    Siul2_Port_Ip_PBcfg.c
*
*   @addtogroup Port_CFG
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
#include "Siul2_Port_Ip.h"


/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_PORT_IP_VENDOR_ID_PBCFG_C                       43
#define SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_C        4
#define SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_PBCFG_C        7
#define SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_PBCFG_C     0
#define SIUL2_PORT_IP_SW_MAJOR_VERSION_PBCFG_C                3
#define SIUL2_PORT_IP_SW_MINOR_VERSION_PBCFG_C                0
#define SIUL2_PORT_IP_SW_PATCH_VERSION_PBCFG_C                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Siul2_Port_Ip_PBcfg.c and Siul2_Port_Ip.h are of the same vendor */
#if (SIUL2_PORT_IP_VENDOR_ID_PBCFG_C != SIUL2_PORT_IP_VENDOR_ID_H)
    #error "Siul2_Port_Ip_PBcfg.c and Siul2_Port_Ip.h have different vendor ids"
#endif
/* Check if Siul2_Port_Ip_PBcfg.c and Siul2_Port_Ip.h are of the same Autosar version */
#if ((SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_PBCFG_C    != SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_PBCFG_C != SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Siul2_Port_Ip_PBcfg.c and Siul2_Port_Ip.h are different"
#endif
/* Check if Siul2_Port_Ip_PBcfg.c and Siul2_Port_Ip.h are of the same software version */
#if ((SIUL2_PORT_IP_SW_MAJOR_VERSION_PBCFG_C != SIUL2_PORT_IP_SW_MAJOR_VERSION_H) || \
     (SIUL2_PORT_IP_SW_MINOR_VERSION_PBCFG_C != SIUL2_PORT_IP_SW_MINOR_VERSION_H) || \
     (SIUL2_PORT_IP_SW_PATCH_VERSION_PBCFG_C != SIUL2_PORT_IP_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Siul2_Port_Ip_PBcfg.c and Siul2_Port_Ip.h are different"
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
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

const Siul2_Port_Ip_PinSettingsConfig g_pin_mux_InitConfigArr[NUM_OF_CONFIGURED_PINS] =
{
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 29,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         0
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 30,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         0
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 31,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         0
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 50,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         0
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 58,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_DOWN_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         0
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 51,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_DOWN_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         0
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 52,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_DOWN_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         0
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 6,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         0
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_ALT2,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 7,
        .mux                         = PORT_MUX_ALT4,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         0
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 72,
        .mux                         = PORT_MUX_ALT3,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         0
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 73,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_FASTEST,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         1
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_ALT1,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 37,
        .mux                         = PORT_MUX_ALT7,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         0
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 36,
        .mux                         = PORT_MUX_ALT5,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         291
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_ALT1,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 65,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         294
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_ALT1,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 64,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         295
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_ALT1,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 66,
        .mux                         = PORT_MUX_ALT5,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         0
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 103,
        .mux                         = PORT_MUX_ALT5,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         0
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 81,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         292
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_ALT1,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 80,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         293
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_ALT1,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 106,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         300
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_ALT1,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 108,
        .mux                         = PORT_MUX_ALT5,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         0
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 107,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         296
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_ALT1,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 105,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         301
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_ALT1,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 104,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         302
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_ALT1,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 102,
        .mux                         = PORT_MUX_ALT5,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         0
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 101,
        .mux                         = PORT_MUX_ALT5,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         0
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 16,
        .mux                         = PORT_MUX_ALT5,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         0
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 15,
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         193
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_ALT2,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 109,
        .mux                         = PORT_MUX_ALT4,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         214
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_ALT2,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 110,
        .mux                         = PORT_MUX_ALT4,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         212
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_ALT2,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 70,
        .mux                         = PORT_MUX_ALT2,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         163
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_ALT3,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    },
    {
        .base                        = IP_SIUL2,
        .pinPortIdx                  = 71,
        .mux                         = PORT_MUX_ALT1,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter                 = PORT_INPUT_FILTER_DISABLED,
        .pullKeep                    = PORT_PULL_KEEP_DISABLED,
        .invert                      = PORT_INVERT_DISABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves              = {
                                         MUX_MODE_NOT_AVAILABLE,
                                         MUX_MODE_NOT_AVAILABLE
                                       },
        .initValue                   = 0,
        .inputMuxReg                 = {
                                         162
                                       },
        .inputMux                    = {
                                         PORT_INPUT_MUX_ALT3,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT,
                                         PORT_INPUT_MUX_NO_INIT
                                       },
    }
};

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

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

#ifdef __cplusplus
}
#endif

/** @} */
