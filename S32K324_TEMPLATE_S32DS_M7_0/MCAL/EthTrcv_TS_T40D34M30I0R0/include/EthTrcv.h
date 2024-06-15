/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : M4_SRC_ETHTRCV_FAMILY
*   Peripheral           : STUB
*   Dependencies         : 
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
/*   @implements EthTrcv.h_Artifact */

#ifndef ETHTRCV_H
#define ETHTRCV_H

/**
*   @file             EthTrcv.h
*
*   @addtogroup       ETHTRCV_DRIVER Ethernet Transceiver Driver
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
#include "Eth_GeneralTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ETHTRCV_VENDOR_ID                    43
#define ETHTRCV_MODULE_ID                    73
#define ETHTRCV_AR_RELEASE_MAJOR_VERSION     4
#define ETHTRCV_AR_RELEASE_MINOR_VERSION     7
#define ETHTRCV_AR_RELEASE_REVISION_VERSION  0
#define ETHTRCV_SW_MAJOR_VERSION             3
#define ETHTRCV_SW_MINOR_VERSION             0
#define ETHTRCV_SW_PATCH_VERSION             0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
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

extern void EthTrcv_ReadMiiIndication(uint8 CtrlIdx,
                                                      uint8 TrcvIdx,
                                                      uint8 RegIdx,
                                                      uint16 RegVal
                                                     );

extern void EthTrcv_WriteMiiIndication(uint8 CtrlIdx,
                                                       uint8 TrcvIdx,
                                                       uint8 RegIdx
                                                      );

Std_ReturnType EthTrcv_SetTransceiverMode(uint8 TrcvIdx,
                                                          Eth_ModeType CtrlMode
                                                         );

Std_ReturnType EthTrcv_GetTransceiverMode(uint8 TrcvIdx,
                                                          Eth_ModeType * TrcvModePtr
                                                         );

Std_ReturnType EthTrcv_SetTransceiverWakeupMode(uint8 TrcvIdx,
                                                                EthTrcv_WakeupModeType TrcvWakeupMode
                                                               );

Std_ReturnType EthTrcv_GetTransceiverWakeupMode(uint8 TrcvIdx,
                                                                EthTrcv_WakeupModeType * TrcvWakeupModePtr
                                                               );

Std_ReturnType EthTrcv_CheckWakeup(uint8 TrcvIdx);

Std_ReturnType EthTrcv_StartAutoNegotiation(uint8 TrcvIdx);

Std_ReturnType EthTrcv_GetLinkState(uint8 TrcvIdx,
                                                    EthTrcv_LinkStateType * LinkStatePtr
                                                   );

Std_ReturnType EthTrcv_TransceiverLinkStateRequest(uint8 TrcvIdx,
                                                                   EthTrcv_LinkStateType LinkState
                                                                  );

Std_ReturnType EthTrcv_GetBaudRate(uint8 TrcvIdx,
                                                   EthTrcv_BaudRateType * BaudRatePtr
                                                  );

Std_ReturnType EthTrcv_GetDuplexMode(uint8 TrcvIdx,
                                                     EthTrcv_DuplexModeType * DuplexModePtr
                                                    );

Std_ReturnType EthTrcv_SetPhyTxMode(uint8 TrcvIdx,
                                                    EthTrcv_PhyTxModeType Mode
                                                   );

Std_ReturnType EthTrcv_SetPhyLoopbackMode(uint8 TrcvIdx,
                                                          EthTrcv_PhyLoopbackModeType Mode
                                                         );

Std_ReturnType EthTrcv_GetPhySignalQuality(uint8 TrcvIdx,
                                                           uint32 * SignalQualityPtr
                                                          );

Std_ReturnType EthTrcv_GetCableDiagnosticsResult(uint8 TrcvIdx,
                                                                 EthTrcv_CableDiagResultType * ResultPtr
                                                                );
Std_ReturnType EthTrcv_RunCableDiagnostic(uint8 TrcvIdx);

Std_ReturnType EthTrcv_GetPhyIdentifier(uint8 TrcvIdx,
                                                        uint32 * OrgUniqueIdPtr,
                                                        uint8 * ModelNrPtr,
                                                        uint8 * RevisionNrPtr
                                                       );

Std_ReturnType EthTrcv_SetPhyTestMode(uint8 TrcvIdx,
                                                      EthTrcv_PhyTestModeType Mode
                                                     );

void EthTrcv_GetVersionInfo(Std_VersionInfoType * VersionInfoPtr);

Std_ReturnType EthTrcv_SetPhyLoopbackMode(uint8 TrcvIdx,
                                                 EthTrcv_PhyLoopbackModeType Mode
                                                );

Std_ReturnType EthTrcv_GetBusWuReason ( uint8 TrcvIdx,
                                        EthTrcv_WakeupReasonType* WakeupReasonPtr
                                        );

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ETHTRCV_H */
