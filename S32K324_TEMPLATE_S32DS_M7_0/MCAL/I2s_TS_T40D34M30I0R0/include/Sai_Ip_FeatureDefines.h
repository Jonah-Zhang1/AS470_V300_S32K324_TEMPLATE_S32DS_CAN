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

#ifndef SAI_IP_FEATUREDEFINES_H
#define SAI_IP_FEATUREDEFINES_H


/**
*   @file
*
*   @addtogroup i2s_ip SAI IPL
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
#include "StandardTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SAI_IP_FEATUREDEFINES_VENDOR_ID                       43
#define SAI_IP_FEATUREDEFINES_AR_RELEASE_MAJOR_VERSION        4
#define SAI_IP_FEATUREDEFINES_AR_RELEASE_MINOR_VERSION        7
#define SAI_IP_FEATUREDEFINES_AR_RELEASE_REVISION_VERSION     0
#define SAI_IP_FEATUREDEFINES_SW_MAJOR_VERSION                3
#define SAI_IP_FEATUREDEFINES_SW_MINOR_VERSION                0
#define SAI_IP_FEATUREDEFINES_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and StandardTypes.h header file are of the same Autosar version */
#if ((SAI_IP_FEATUREDEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (SAI_IP_FEATUREDEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Sai_Ip_FeatureDefines.h and StandardTypes.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* FIFO */
#define FIFO_SIZE 8U
#define SAI_IP_FIFO_SIZE 4U
#define SAI_IP_FPACK_8_BIT  ((uint8)2U) /*!< 8-bit FIFO packing is enabled */
#define SAI_IP_FPACK_16_BIT ((uint8)3U) /*!< 16-bit FIFO packing is enabled */
/*! @brief Channel mode tristate or output zero */
#define FEATURE_SAI_IP_HAS_CHMOD
/*! @brief Master clock from AIPS slow clock */
#define FEATURE_SAI_IP_MSEL_AIPS_SLOW_CLK
/*! @brief Master clock from FXOSC clock */
#define FEATURE_SAI_IP_MSEL_FXOSC_CLK
/*! @brief Master clock from MCLK pin */
#define FEATURE_SAI_IP_MSEL_MCLK_PIN
/*! @brief Master clock from MCLK pin from other SAI instance */
#define FEATURE_SAI_IP_MSEL_OTHER_MCLK_PIN
/*! @brief SAI has PARAM register */
#define FEATURE_SAI_IP_HAS_PARAM
/*! @brief SAI channel count */
#define SAI0_IP_CHANNEL_COUNT 4U
#define SAI1_IP_CHANNEL_COUNT 1U
#define SAI_IP_MAX_CHANNEL_COUNT 4U
#define SAI_IP_MAX_CHANNEL_VALUE {0U, 0U, 0U, 0U}
#define SAI_IP_CHANNEL_COUNT_DEFINITION    {SAI0_IP_CHANNEL_COUNT, SAI1_IP_CHANNEL_COUNT}
/*! @brief SAI NULL PTRs */
#define SAI_IP_NULL_PTRS {NULL_PTR, NULL_PTR}
/*! @brief Endianess */
#ifdef FEATURE_SAI_IP_BIG_ENDIAN
#define DATA_REG_SIZE 4U
#endif

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SAI_IP_FEATUREDEFINES_H */
