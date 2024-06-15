/** @} */
/*==================================================================================================
*   Project            : RTD AUTOSAR 4.7
*   Platform           : M4_SRC_ETHTRCV_FAMILY
*   Peripheral         : STUB
*   Dependencies       : 
*
*   AutosarVersion     : 4.7.0
*   AutosarRevision    : ASR_REL_4_7_REV_0000
*   AutosarConfVariant :
*   SW Version         : 3.0.0
*   BuildVersion       : S32K3_RTD_3_0_0_P07_D2306_ASR_REL_4_7_REV_0000_20230629
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

/**
*   @file             EthTrcv.c
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
#include "EthTrcv.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ETHTRCV_VENDOR_ID_C                      43
#define ETHTRCV_AR_RELEASE_MAJOR_VERSION_C       4
#define ETHTRCV_AR_RELEASE_MINOR_VERSION_C       7
#define ETHTRCV_AR_RELEASE_REVISION_VERSION_C    0
#define ETHTRCV_SW_MAJOR_VERSION_C               3
#define ETHTRCV_SW_MINOR_VERSION_C               0
#define ETHTRCV_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

uint8 EthTrcv_FunctionCalled = 0;

uint8 StartAutoNegotiation_FunctionCalled = 0;
uint8 GetLinkState_FunctionCalled = 0;
uint8 GetBaudRate_FunctionCalled = 0;
uint8 GetDuplexMode_FunctionCalled = 0;
uint8 CheckWakeup_FunctionCalled = 0;
uint8 GetSwitchPortWakeupReason_FunctionCalled = 0;


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/



/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief          This function handles the received Ethernet frame.
* @details        Function should parse the received frame and pass the gathered
*                 information to the appropriate upper layer module.
* @param[in]      CtrlIdx Index of the controller which read Mii.
* @param[in]      TrcvIdx The Id of transceiver was read Mii
* @param[in]      RegIdx The Id or Address of Register was read
* @param[in]      RegVal The value of register.
*
* @implements EthTrcv_ReadMiiIndication_Activity
*
* @violates @ref EthTrcv_c_REF_3 Violates MISRA 2004 Required Rule 8.10 This is an interrupt handler
*/
void EthTrcv_ReadMiiIndication  (
                                        uint8 CtrlIdx, \
                                        uint8 TrcvIdx, \
                                        uint8 RegIdx, \
                                        uint16 RegVal \
                                    )
{
    /* This is an empty stub function */
    (void)CtrlIdx;
    (void)TrcvIdx;
    (void)RegIdx;
    (void)RegVal;
}

/*================================================================================================*/
/**
* @brief          This function handles the received Ethernet frame.
* @details        Function should parse the received frame and pass the gathered
*                 information to the appropriate upper layer module.
* @param[in]      CtrlIdx Index of the controller which write Mii.
* @param[in]      TrcvIdx The Id of transceiver was write Mii
* @param[in]      RegIdx The Id or Address of Register was write
*
* @implements EthTrcv_WriteMiiIndication_Activity
*
* @violates @ref EthTrcv_c_REF_3 Violates MISRA 2004 Required Rule 8.10 This is an interrupt handler
*/
void EthTrcv_WriteMiiIndication (
                                        uint8 CtrlIdx, \
                                        uint8 TrcvIdx, \
                                        uint8 RegIdx \
                                    )
{
    /* This is an empty stub function */
    (void)CtrlIdx;
    (void)TrcvIdx;
    (void)RegIdx;
}


Std_ReturnType EthTrcv_SetTransceiverMode(uint8 TrcvIdx,
                                                          Eth_ModeType CtrlMode
                                                         )
{
    (void)TrcvIdx;
    (void)CtrlMode;
    Std_ReturnType checkStatus = (Std_ReturnType)E_OK;

    EthTrcv_FunctionCalled++;

    return checkStatus;
}


Std_ReturnType EthTrcv_SetPhyTxMode(uint8 TrcvIdx,
                                                    EthTrcv_PhyTxModeType Mode
                                                   )
{
    (void)TrcvIdx;
    (void)Mode;
    Std_ReturnType checkStatus = (Std_ReturnType)E_OK;

    EthTrcv_FunctionCalled++;

    return checkStatus;
}


Std_ReturnType EthTrcv_GetPhySignalQuality(uint8 TrcvIdx,
                                                           uint32 * SignalQualityPtr
                                                          )
{
    (void)TrcvIdx;
    (void)SignalQualityPtr;
    Std_ReturnType checkStatus = (Std_ReturnType)E_OK;

    EthTrcv_FunctionCalled++;

    return checkStatus;
}

Std_ReturnType EthTrcv_GetPhyIdentifier(uint8 TrcvIdx,
                                                        uint32 * OrgUniqueIdPtr,
                                                        uint8 * ModelNrPtr,
                                                        uint8 * RevisionNrPtr
                                                       )
{
    (void)TrcvIdx;
    (void)OrgUniqueIdPtr;
    (void)ModelNrPtr;
    (void)RevisionNrPtr;
    Std_ReturnType checkStatus = (Std_ReturnType)E_OK;

    EthTrcv_FunctionCalled++;

    return checkStatus;
}

Std_ReturnType EthTrcv_SetPhyTestMode(uint8 TrcvIdx,
                                                      EthTrcv_PhyTestModeType Mode
                                                     )
{
    (void)TrcvIdx;
    (void)Mode;
    Std_ReturnType checkStatus = (Std_ReturnType)E_OK;

    EthTrcv_FunctionCalled++;

    return checkStatus;
}

Std_ReturnType EthTrcv_SetPhyLoopbackMode(uint8 TrcvIdx,
                                                          EthTrcv_PhyLoopbackModeType Mode
                                                         )
{
    (void)TrcvIdx;
    (void)Mode;
    Std_ReturnType checkStatus = (Std_ReturnType)E_OK;

    EthTrcv_FunctionCalled++;

    return checkStatus;
}


Std_ReturnType EthTrcv_RunCableDiagnostic(uint8 TrcvIdx)
{
    (void)TrcvIdx;
    Std_ReturnType checkStatus = (Std_ReturnType)E_OK;

    EthTrcv_FunctionCalled++;

    return checkStatus;
}

Std_ReturnType EthTrcv_GetCableDiagnosticsResult(uint8 TrcvIdx,
                                                                 EthTrcv_CableDiagResultType * ResultPtr
                                                                )
{
    (void)TrcvIdx;
    (void)ResultPtr;
    Std_ReturnType checkStatus = (Std_ReturnType)E_OK;

    EthTrcv_FunctionCalled++;

    return checkStatus;
}

Std_ReturnType EthTrcv_TransceiverLinkStateRequest(uint8 TrcvIdx,
                                                                   EthTrcv_LinkStateType LinkState
                                                                  )
{
    (void)TrcvIdx;
    (void)LinkState;
    Std_ReturnType checkStatus = (Std_ReturnType)E_OK;

    EthTrcv_FunctionCalled++;

    return checkStatus;
}

Std_ReturnType EthTrcv_GetTransceiverMode(uint8 TrcvIdx,
                                                          Eth_ModeType * TrcvModePtr
                                                         )
{
    (void)TrcvIdx;
    (void)TrcvModePtr;
    Std_ReturnType checkStatus = (Std_ReturnType)E_OK;

    EthTrcv_FunctionCalled++;

    return checkStatus;
}

Std_ReturnType EthTrcv_StartAutoNegotiation(uint8 TrcvIdx)
{
    (void)TrcvIdx;
    Std_ReturnType checkStatus = (Std_ReturnType)E_OK;

    StartAutoNegotiation_FunctionCalled++;

    return checkStatus;
}

Std_ReturnType EthTrcv_GetLinkState (uint8 TrcvIdx, EthTrcv_LinkStateType * LinkStatePtr)
{
    (void)TrcvIdx;
    (void)LinkStatePtr;
    Std_ReturnType checkStatus = (Std_ReturnType)E_OK;

    GetLinkState_FunctionCalled++;

    return checkStatus;
}

Std_ReturnType EthTrcv_GetBaudRate (uint8 TrcvIdx, EthTrcv_BaudRateType * BaudRatePtr)
{
    (void)TrcvIdx;
    (void)BaudRatePtr;
    Std_ReturnType checkStatus = (Std_ReturnType)E_OK;

    GetBaudRate_FunctionCalled++;

    return checkStatus;
}

Std_ReturnType EthTrcv_GetDuplexMode (uint8 TrcvIdx, EthTrcv_DuplexModeType* DuplexModePtr)
{
    (void)TrcvIdx;
    (void)DuplexModePtr;
    Std_ReturnType checkStatus = (Std_ReturnType)E_OK;

    GetDuplexMode_FunctionCalled++;

    return checkStatus;
}

Std_ReturnType EthTrcv_CheckWakeup(uint8 TrcvIdx)
{
    (void)TrcvIdx;
    Std_ReturnType checkStatus = (Std_ReturnType)E_OK;

    CheckWakeup_FunctionCalled++;

    return checkStatus;
}

Std_ReturnType EthTrcv_GetBusWuReason ( uint8 TrcvIdx,
                                                        EthTrcv_WakeupReasonType* WakeupReasonPtr
                                                      )
{
    (void)TrcvIdx;
    (void)WakeupReasonPtr;
    Std_ReturnType checkStatus = (Std_ReturnType)E_OK;

    GetSwitchPortWakeupReason_FunctionCalled++;

    return checkStatus;
}

/** @} */

#ifdef __cplusplus
}
#endif
