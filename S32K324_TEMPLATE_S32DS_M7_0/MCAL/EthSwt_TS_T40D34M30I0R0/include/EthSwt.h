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


#ifndef ETHSWT_H
#define ETHSWT_H

/**
*   @file
*
*   @addtogroup ETHSWT Ethernet Switch
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Eth_GeneralTypes.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETHSWT_VENDOR_ID                    43
#define ETHSWT_MODULE_ID                    89
#define ETHSWT_AR_RELEASE_MAJOR_VERSION     4
#define ETHSWT_AR_RELEASE_MINOR_VERSION     7
#define ETHSWT_AR_RELEASE_REVISION_VERSION  0
#define ETHSWT_SW_MAJOR_VERSION             3
#define ETHSWT_SW_MINOR_VERSION             0
#define ETHSWT_SW_PATCH_VERSION             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Eth.h header file are of the same Autosar version */
    #if ((ETHSWT_AR_RELEASE_MAJOR_VERSION != ETH_GENERALTYPES_AR_RELEASE_MAJOR_VERSION) || \
         (ETHSWT_AR_RELEASE_MINOR_VERSION != ETH_GENERALTYPES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of EthSwt.h and Eth_GeneralTypes.h are different"
    #endif
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
extern Std_ReturnType EthSwt_EthRxProcessFrame(uint8 CtrlIdx, 
                                                               Eth_BufIdxType BufIdx, 
                                                               uint8** DataPtr, 
                                                               uint16* LengthPtr, 
                                                               boolean* IsMgmtFrameOnlyPtr
                                                              );

extern Std_ReturnType EthSwt_EthRxFinishedIndication(uint8 CtrlIdx, Eth_BufIdxType BufIdx);

extern Std_ReturnType EthSwt_EthTxPrepareFrame(uint8 CtrlIdx, 
                                                               Eth_BufIdxType BufIdx,
                                                               uint8** DataPtr, 
                                                               uint16* LengthPtr
                                                              );

extern void EthSwt_EthTxAdaptBufferLength(uint16* LengthPtr);

extern Std_ReturnType EthSwt_EthTxProcessFrame(uint8 CtrlIdx, 
                                               Eth_BufIdxType BufIdx, 
                                               uint8** DataPtr, 
                                               uint16* LengthPtr
                                              );

extern Std_ReturnType EthSwt_EthTxFinishedIndication(uint8 CtrlIdx, 
                                                                     Eth_BufIdxType BufIdx
                                                                    );

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ETHSWT_H */

