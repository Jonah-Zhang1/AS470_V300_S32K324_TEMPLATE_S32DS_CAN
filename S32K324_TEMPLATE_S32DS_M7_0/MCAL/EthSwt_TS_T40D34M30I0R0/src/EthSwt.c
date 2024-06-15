/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
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

/**
*   @file
*
*   @addtogroup ETHSWT Ethernet Switch
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif


/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "EthSwt.h"

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
#define ETHSWT_VENDOR_ID_C                     43
#define ETHSWT_MODULE_ID_C                     89
#define ETHSWT_AR_RELEASE_MAJOR_VERSION_C      4
#define ETHSWT_AR_RELEASE_MINOR_VERSION_C      7
#define ETHSWT_AR_RELEASE_REVISION_VERSION_C   0
#define ETHSWT_SW_MAJOR_VERSION_C              3
#define ETHSWT_SW_MINOR_VERSION_C              0
#define ETHSWT_SW_PATCH_VERSION_C              0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and ETH header file are of the same vendor */
#if(ETHSWT_VENDOR_ID_C != ETHSWT_VENDOR_ID)
    #error "EthSwt.c and EthSwt.h have different vendor ids"
#endif
/* Check if current file and ETH header file are of the same module ID */
#if(ETHSWT_MODULE_ID_C != ETHSWT_MODULE_ID)
    #error "EthSwt.c and EthSwt.h have different module id"
#endif
#if ((ETHSWT_AR_RELEASE_MAJOR_VERSION_C    != ETHSWT_AR_RELEASE_MAJOR_VERSION) || \
     (ETHSWT_AR_RELEASE_MINOR_VERSION_C    != ETHSWT_AR_RELEASE_MINOR_VERSION) || \
     (ETHSWT_AR_RELEASE_REVISION_VERSION_C != ETHSWT_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of EthSwt.c and EthSwt.h are different"
#endif

#if ((ETHSWT_SW_MAJOR_VERSION_C != ETHSWT_SW_MAJOR_VERSION) || \
     (ETHSWT_SW_MINOR_VERSION_C != ETHSWT_SW_MINOR_VERSION) || \
     (ETHSWT_SW_PATCH_VERSION_C != ETHSWT_SW_PATCH_VERSION))
#error "Software Version Numbers of EthSwt.c and EthSwt.h are different"
#endif

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/



/*==================================================================================================
                                        LOCAL FUNCTION
==================================================================================================*/



/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/



/*======================================================================================================*/
/**
* @brief EthSwt_EthRxProcessFrame - Function inspects the Ethernet frame passed by the data pointer for
                                    management information and stores it for later use in
                                    EthSwt_EthRxFinishedIndication().Function which inserts management information
                                    into the Ethernet frame.

* @details This is a function stub only. 
*     
* @param[in]      CtrlIdx        Ethernet Controller index
*                 BufIdx         Ethernet Rx Buffer index 
*
* @param[inout]   DataPtr        IN: Pointer to the position of the EtherType of a common Ethernet frame
*                                OUT: Pointer to the position of the EtherType in the management frame
*                 LengthPtr      IN: Pointer to the length of the frame rececived
*                                OUT: Pointer to the length decreased by the management information length
*
* @param[out]     IsMgmtFrameOnlyPtr    Information about the kind of frame
*                                       FALSE: Frame is not only for management purpose, but
*                                              also for normal communication.
*                                       TRUE: Frame is only for management purpose and must
*                                              not be processed in common receive process
*
* @return         E_OK/E_NOT_OK  Result of the operation
*
* @Requirements SWS_Eth_00120, SWS_EthSwt_91004
*/
/*======================================================================================================*/

Std_ReturnType EthSwt_EthRxProcessFrame(uint8 CtrlIdx, 
                                                        Eth_BufIdxType BufIdx, 
                                                        uint8** DataPtr, 
                                                        uint16* LengthPtr, 
                                                        boolean* IsMgmtFrameOnlyPtr
                                                       )
{
    /* This is an empty stub function */
    (void)CtrlIdx;
    (void)BufIdx;
    (void)DataPtr;
    (void)LengthPtr;
    *IsMgmtFrameOnlyPtr = FALSE;

    return (Std_ReturnType)E_OK;
}



/*======================================================================================================*/
/**
* @brief EthSwt_EthRxFinishedIndication - Indication for a finished receive process for a specific Ethernet frame,
*                                  which results in providing the management information retrieved
*                                  during EthSwt_EthRxProcessFrame().
*
* @details This is a function stub only. 
*     
* @param[in]      CtrlIdx        Ethernet Controller index
*                 BufIdx         Ethernet Rx Buffer index 
*
* @param[inout]   NONE
*
* @param[out]     NONE
*
* @return         E_OK/E_NOT_OK  Result of the operation
*
* @Requirements SWS_Eth_00120, SWS_EthSwt_91005
*/
/*======================================================================================================*/

Std_ReturnType EthSwt_EthRxFinishedIndication(uint8 CtrlIdx, Eth_BufIdxType BufIdx)
{
    /* This is an empty stub function */
    (void)CtrlIdx;
    (void)BufIdx;

    return (Std_ReturnType)E_OK;
}



/*======================================================================================================*/
/**
* @brief EthSwt_EthTxPrepareFrame - Prepares the Ethernet frame for common Ethernet communication
*                                    (frame shall be handled by switch according to the common address
*                                    resolution behavior) and stores the information for processing of
*                                    EthSwt_EthTxFinishedIndication()
*
* @details This is a function stub only. 
*     
* @param[in]      CtrlIdx        Ethernet Controller index
*                 BufIdx         Ethernet Rx Buffer index 
*
* @param[inout]   DataPtr        IN: Pointer to the position of the EtherType of a common Ethernet frame
*                                OUT: Pointer to the position of the EtherType in the management frame
*                 LengthPtr      IN: Pointer to the length of the buffer without management information
*                                OUT: Pointer to the modified length needed for buffer and management information
* @param[out]     NONE
*
* @return         E_OK/E_NOT_OK  Result of the operation
*
* @Requirements SWS_Eth_00120, SWS_EthSwt_91006
*/
/*======================================================================================================*/

Std_ReturnType EthSwt_EthTxPrepareFrame(uint8 CtrlIdx, 
                                                        Eth_BufIdxType BufIdx,
                                                        uint8** DataPtr, 
                                                        uint16* LengthPtr
                                                       )
{
    /* This is an empty stub function */
    (void)CtrlIdx;
    (void)BufIdx;
    (void)DataPtr;
    (void)LengthPtr;

    return (Std_ReturnType)E_OK;
}



/*======================================================================================================*/
/**
* @brief EthSwt_EthTxAdaptBufferLength - Modifies the buffer length to be able to insert management
*                                        information
*
* @details This is a function stub only. 
*     
* @param[in]      NONE
*
* @param[inout]   LengthPtr      IN: Pointer to the length of the buffer without management information
*                                OUT: Pointer to the modified length needed for buffer and management information
* @param[out]     NONE
*
* @return         NONE
*
* @Requirements SWS_Eth_00120, SWS_EthSwt_91007
*/
/*======================================================================================================*/

void EthSwt_EthTxAdaptBufferLength(uint16* LengthPtr)
{
    /* This is an empty stub function */
    (void)LengthPtr;
}



/*======================================================================================================*/
/**
* @brief EthSwt_EthTxProcessFrame - Function which inserts management information into the Ethernet frame.

* @details This is a function stub only. 
*     
* @param[in]      CtrlIdx        Ethernet Controller index
*                 BufIdx         Ethernet Rx Buffer index 
*
* @param[inout]   DataPtr        IN: Pointer to the position of the EtherType of a common Ethernet frame
*                                OUT: Pointer to the position of the EtherType in the management frame
*                 LengthPtr      IN: Pointer to the length of the received frame
*                                OUT: Pointer to the length decreased by the management information length
* @param[out]     NONE
*
* @return         E_OK/E_NOT_OK  Result of the operation
*
* @Requirements SWS_Eth_00120, SWS_EthSwt_91009
*/
/*======================================================================================================*/

Std_ReturnType EthSwt_EthTxProcessFrame(uint8 CtrlIdx, 
                                        Eth_BufIdxType BufIdx, 
                                        uint8** DataPtr, 
                                        uint16* LengthPtr
                                       )
{
    /* This is an empty stub function */
    (void)CtrlIdx;
    (void)BufIdx;
    (void)DataPtr;
    (void)LengthPtr;

    return (Std_ReturnType)E_OK;
}

/*======================================================================================================*/
/**
* @brief EthSwt_EthTxFinishedIndication - Indication for a finished transmit process for a specific Ethernet
*                                         frame
*
* @details This is a function stub only. 
*     
* @param[in]      CtrlIdx        Ethernet Controller index
*                 BufIdx         Ethernet Rx Buffer index 
*
* @param[inout]   NONE

* @param[out]     NONE
*
* @return         E_OK/E_NOT_OK  Result of the operation
*
* @Requirements SWS_Eth_00120, SWS_EthSwt_91010
*/
/*======================================================================================================*/

Std_ReturnType EthSwt_EthTxFinishedIndication(uint8 CtrlIdx, 
                                                              Eth_BufIdxType BufIdx
                                                             )
{
    /* This is an empty stub function */
    (void)CtrlIdx;
    (void)BufIdx;

    return (Std_ReturnType)E_OK;
}

#ifdef __cplusplus
}
#endif

/** @} */
