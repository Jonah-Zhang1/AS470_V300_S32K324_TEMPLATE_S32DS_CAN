/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : I2S
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 3.0.0
* Build Version : S32K3_RTD_3_0_0_P10_D2307_ASR_REL_4_7_REV_0000_20230726
*
* Copyright 2020 - 2023 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef I2S_IPW_H
#define I2S_IPW_H

/**
*   @file
*
*   @internal
*   @addtogroup i2s_ipw I2s Ipw
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
#include "I2s_Ipw_CfgDefines.h"
#include "I2s_Ipw_Types.h"
#include "CDD_I2s_Types.h"
#include "I2s_Ipw_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2S_IPW_VENDOR_ID                       43
#define I2S_IPW_AR_RELEASE_MAJOR_VERSION        4
#define I2S_IPW_AR_RELEASE_MINOR_VERSION        7
#define I2S_IPW_AR_RELEASE_REVISION_VERSION     0
#define I2S_IPW_SW_MAJOR_VERSION                3
#define I2S_IPW_SW_MINOR_VERSION                0
#define I2S_IPW_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I2s_Ipw_CfgDefines header file are of the same vendor */
#if (I2S_IPW_VENDOR_ID != I2S_IPW_CFGDEFINES_VENDOR_ID)
#error "I2s_Ipw.h and I2s_Ipw_CfgDefines.h have different vendor ids"
#endif

/* Check if current file and I2s_Ipw_CfgDefines header file are of the same Autosar version */
#if ((I2S_IPW_AR_RELEASE_MAJOR_VERSION     != I2S_IPW_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_IPW_AR_RELEASE_MINOR_VERSION     != I2S_IPW_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (I2S_IPW_AR_RELEASE_REVISION_VERSION  != I2S_IPW_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of I2s_Ipw.h and I2s_Ipw_CfgDefines.h are different"
#endif

/* Check if current file and I2s_Ipw_CfgDefines header file are of the same software version */
#if ((I2S_IPW_SW_MAJOR_VERSION != I2S_IPW_CFGDEFINES_SW_MAJOR_VERSION) || \
     (I2S_IPW_SW_MINOR_VERSION != I2S_IPW_CFGDEFINES_SW_MINOR_VERSION) || \
     (I2S_IPW_SW_PATCH_VERSION != I2S_IPW_CFGDEFINES_SW_PATCH_VERSION))
#error "Software Version Numbers of I2s_Ipw.h and I2s_Ipw_CfgDefines.h are different"
#endif

/* Check if current file and I2s_Ipw_Types header file are of the same vendor */
#if (I2S_IPW_VENDOR_ID != I2S_IPW_TYPES_VENDOR_ID)
#error "I2s_Ipw.h and I2s_Ipw_Types.h have different vendor ids"
#endif

/* Check if current file and I2s_Ipw_Types header file are of the same Autosar version */
#if ((I2S_IPW_AR_RELEASE_MAJOR_VERSION     != I2S_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_IPW_AR_RELEASE_MINOR_VERSION     != I2S_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (I2S_IPW_AR_RELEASE_REVISION_VERSION  != I2S_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of I2s_Ipw.h and I2s_Ipw_Types.h are different"
#endif

/* Check if current file and I2s_Ipw_Types header file are of the same software version */
#if ((I2S_IPW_SW_MAJOR_VERSION != I2S_IPW_TYPES_SW_MAJOR_VERSION) || \
     (I2S_IPW_SW_MINOR_VERSION != I2S_IPW_TYPES_SW_MINOR_VERSION) || \
     (I2S_IPW_SW_PATCH_VERSION != I2S_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of I2s_Ipw.h and I2s_Ipw_Types.h are different"
#endif

/* Check if current file and CDD_I2s_Types header file are of the same vendor */
#if (I2S_IPW_VENDOR_ID != I2S_TYPES_VENDOR_ID)
#error "I2s_Ipw.h and CDD_I2s_Types.h have different vendor ids"
#endif

/* Check if current file and CDD_I2s_Types header file are of the same Autosar version */
#if ((I2S_IPW_AR_RELEASE_MAJOR_VERSION     != I2S_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_IPW_AR_RELEASE_MINOR_VERSION     != I2S_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (I2S_IPW_AR_RELEASE_REVISION_VERSION  != I2S_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of I2s_Ipw.h and CDD_I2s_Types.h are different"
#endif

/* Check if current file and CDD_I2s_Types header file are of the same software version */
#if ((I2S_IPW_SW_MAJOR_VERSION != I2S_TYPES_SW_MAJOR_VERSION) || \
     (I2S_IPW_SW_MINOR_VERSION != I2S_TYPES_SW_MINOR_VERSION) || \
     (I2S_IPW_SW_PATCH_VERSION != I2S_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of I2s_Ipw.h and CDD_I2s_Types.h are different"
#endif

/* Check if current file and I2s_Ipw_Cfg header file are of the same vendor */
#if (I2S_IPW_VENDOR_ID != I2S_IPW_CFG_VENDOR_ID)
#error "I2s_Ipw.h and I2s_Ipw_Cfg.h have different vendor ids"
#endif

/* Check if current file and I2s_Ipw_Cfg header file are of the same Autosar version */
#if ((I2S_IPW_AR_RELEASE_MAJOR_VERSION     != I2S_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_IPW_AR_RELEASE_MINOR_VERSION     != I2S_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (I2S_IPW_AR_RELEASE_REVISION_VERSION  != I2S_IPW_CFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of I2s_Ipw.h and I2s_Ipw_Cfg.h are different"
#endif

/* Check if current file and I2s_Ipw_Cfg header file are of the same software version */
#if ((I2S_IPW_SW_MAJOR_VERSION != I2S_IPW_CFG_SW_MAJOR_VERSION) || \
     (I2S_IPW_SW_MINOR_VERSION != I2S_IPW_CFG_SW_MINOR_VERSION) || \
     (I2S_IPW_SW_PATCH_VERSION != I2S_IPW_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of I2s_Ipw.h and I2s_Ipw_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define I2S_START_SEC_CODE
#include "I2s_MemMap.h"

/*!
 * @brief Initialize I2s module
 */
void I2s_Ipw_Init(const I2s_ConfigType * const pConfigPtr);

#if (I2S_IPW_MULTICORE_ENABLED == STD_OFF)
/*!
 * @brief De-initialize I2s module
 */
void I2s_Ipw_DeInit(void);

#else
/*!
 * @brief De-initialize I2s logical channel
 *
 * @param[in] LogicChn I2s logical channel
 */
void I2s_Ipw_DeInitLogicalChannel(I2s_LogicalChannel LogicChn);
#endif /* (I2S_IPW_MULTICORE_ENABLED == STD_OFF) */

/*!
 * @brief Request to send or receive data in synchronous or asynchronous mode
 *
 * @param[in] LogicChn I2s logical channel
 * @param[in] pRequest Pointer to the transfer request
 * @param[in] bSync Synchronous or asynchronous
 * @return Status of the transfer.
 */
Std_ReturnType I2s_Ipw_Transmit(I2s_LogicalChannel LogicChn,
                                  const I2s_RequestType * const pRequest,
                                  boolean bSync);

/*!
 * @brief Get status of the given logical channel and data line direction
 *
 * @param[in] LogicChn I2s logical channel
 * @param[in] direction Data direction
 * @param[out] pStatus Pointer to status structure
 * @return Status of function.
 */
Std_ReturnType I2s_Ipw_GetStatus(I2s_LogicalChannel LogicChn,
                                   I2s_StatusStructType * const pStatus);

/*!
 * @brief Abort all ongoing transferring data
 *
 * @param[in] LogicChn I2s logical channel
 */
void I2s_Ipw_AbortTrasmit(I2s_LogicalChannel LogicChn);

#define I2S_STOP_SEC_CODE
#include "I2s_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* I2S_IPW_H */
