/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : GMAC
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

#ifndef ETH_43_GMAC_IPW_H
#define ETH_43_GMAC_IPW_H

/**
*   @file
*
*   @addtogroup ETH_43_GMAC_DRIVER Ethernet Driver
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
#include "Eth_43_GMAC_Ipw_Cfg.h"
#include "EthIf_Cbk.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_43_GMAC_IPW_VENDOR_ID                    43
#define ETH_43_GMAC_IPW_AR_RELEASE_MAJOR_VERSION     4
#define ETH_43_GMAC_IPW_AR_RELEASE_MINOR_VERSION     7
#define ETH_43_GMAC_IPW_AR_RELEASE_REVISION_VERSION  0
#define ETH_43_GMAC_IPW_SW_MAJOR_VERSION             3
#define ETH_43_GMAC_IPW_SW_MINOR_VERSION             0
#define ETH_43_GMAC_IPW_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Eth_43_GMAC_Ipw_Cfg.h */
#if (ETH_43_GMAC_IPW_VENDOR_ID != ETH_43_GMAC_IPW_CFG_VENDOR_ID)
    #error "Eth_43_GMAC_Ipw.h and Eth_43_GMAC_Ipw_Cfg.h have different vendor ids"
#endif
#if ((ETH_43_GMAC_IPW_AR_RELEASE_MAJOR_VERSION    != ETH_43_GMAC_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_43_GMAC_IPW_AR_RELEASE_MINOR_VERSION    != ETH_43_GMAC_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ETH_43_GMAC_IPW_AR_RELEASE_REVISION_VERSION != ETH_43_GMAC_IPW_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Eth_43_GMAC_Ipw.h and Eth_43_GMAC_Ipw_Cfg.h are different"
#endif
#if ((ETH_43_GMAC_IPW_SW_MAJOR_VERSION != ETH_43_GMAC_IPW_CFG_SW_MAJOR_VERSION) || \
     (ETH_43_GMAC_IPW_SW_MINOR_VERSION != ETH_43_GMAC_IPW_CFG_SW_MINOR_VERSION) || \
     (ETH_43_GMAC_IPW_SW_PATCH_VERSION != ETH_43_GMAC_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eth_43_GMAC_Ipw.h and Eth_43_GMAC_Ipw_Cfg.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
   /* Checks against EthIf_Cbk.h */
    #if ((ETH_43_GMAC_IPW_AR_RELEASE_MAJOR_VERSION != ETHIF_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_43_GMAC_IPW_AR_RELEASE_MINOR_VERSION != ETHIF_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Eth_43_GMAC_Ipw.h and EthIf_Cbk.h are different"
    #endif
#endif
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/
#define ETH_43_GMAC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"

/* Pointers to IPW configuration structures stored for later use */
extern const Eth_43_GMAC_Ipw_CtrlConfigType *Eth_43_GMAC_Ipw_apxInternalCfg[ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED];


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


#define ETH_43_GMAC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"
/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define ETH_43_GMAC_START_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"


extern boolean Eth_43_GMAC_Ipw_CheckAccessToController(const uint8 CtrlIdx);
extern Std_ReturnType Eth_43_GMAC_Ipw_TxTimeAwareShaperInit ( \
                                    uint8 CtrlIdx, \
                                    const Eth_43_GMAC_Ipw_CtrlConfigType *IpwCtrlCfg \
                                    );
extern Eth_ModeType Eth_43_GMAC_Ipw_GetControllerMode(const uint8 CtrlIdx);
extern Std_ReturnType Eth_43_GMAC_Ipw_ConfigureController  ( \
                                    const uint8 CtrlIdx, \
                                    const Eth_43_GMAC_Ipw_CtrlConfigType *IpwCtrlCfg, \
                                    const Eth_43_GMAC_ClockCfgType *ClkCfg \
                                         );
extern Std_ReturnType Eth_43_GMAC_Ipw_EnableController(const uint8 CtrlIdx);
extern Std_ReturnType Eth_43_GMAC_Ipw_DisableController(const uint8 CtrlIdx);
extern void Eth_43_GMAC_Ipw_GetPhysicalAddress  ( \
                                        const uint8 CtrlIdx, \
                                        uint8 *PhysAddrPtr \
                                         );
                                        
extern void Eth_43_GMAC_Ipw_SetPhysicalAddress ( \
                                        const uint8 CtrlIdx, \
                                        const uint8 *PhysAddrPtr \
                                        );                                     

#if STD_ON == ETH_43_GMAC_GET_COUNTER_API                                                    
extern Std_ReturnType Eth_43_GMAC_Ipw_GetCounterValues  ( \
                               uint8 CtrlIdx, \
                               Eth_CounterType *CounterPtr \
                                           );
#endif
#if STD_ON == ETH_43_GMAC_GET_RXSTATS_API                                         
extern Std_ReturnType Eth_43_GMAC_Ipw_GetRxStats ( \
                       uint8 CtrlIdx, \
                       Eth_RxStatsType *RxStatsPtr \
                                         );
#endif

#if STD_ON == ETH_43_GMAC_UPDATE_PHYS_ADDR_FILTER_API
extern Std_ReturnType Eth_43_GMAC_Ipw_UpdatePhysAddrFilter ( \
                                    uint8 CtrlIdx, \
                                    const uint8 *PhysAddr, \
                                    Eth_FilterActionType Action \
                                    );
#endif

extern BufReq_ReturnType Eth_43_GMAC_Ipw_ProvideTxBuffer (  \
                                    const uint8 CtrlIdx, \
                                    const uint8 FifoIdx, \
                                    Eth_BufIdxType * const BufferIdx, \
                                    uint8 **FrameBuffer, \
                                    uint16 * const FrameLength \
                                          );

extern void Eth_43_GMAC_Ipw_ProvideRxBuffer(uint8 CtrlIdx, \
          uint8 FifoIdx, \
          uint8 *BufferData);

extern Std_ReturnType Eth_43_GMAC_Ipw_Transmit ( \
                                        const uint8 CtrlIdx, \
                                        const uint8 FifoIdx, \
                                        uint8 *Buffer, \
                                        const uint16 Length \
                                       );
#if (STD_ON == ETH_43_GMAC_SEND_MULTI_BUFFER_FRAME_API)
BufReq_ReturnType Eth_43_GMAC_Ipw_ProvideTxMultiBuffer( const uint8 u8CtrlIdx, \
                                           const uint8 u8FifoIdx, \
                                           Eth_BufIdxType * const pBufferIdx, \
                                           uint16 NumBuffers,
                                           const uint16 BufferLength[] );

uint16 Eth_43_GMAC_Ipw_GetNextBuffer(uint8 CtrlIdx, uint8 u8FifoIdx, uint16 u16BufferIdx);

BufReq_ReturnType Eth_43_GMAC_Ipw_SendMultiBufferFrame(uint8 CtrlIdx,
                                                uint8 u8FifoIdx,
                                                uint16 NumBuffers,
                                                uint8* BufferData[],
                                                uint16 BufferLength[]);
#endif
extern Eth_RxStatusType Eth_43_GMAC_Ipw_ReceiveFrame ( \
                                                const uint8 CtrlIdx, \
                                                const uint8 FifoIdx, \
                                                uint8 **FrameData, \
                                                uint16 *FrameLength, \
                                                boolean *FrameHasError
                                             );

extern void Eth_43_GMAC_Ipw_ReleaseResources ( \
                                const uint8 CtrlIdx, \
                                const uint8 FifoIdx  \
                                     );

#if STD_ON == ETH_43_GMAC_MDIO_CLAUSE22_API
extern boolean Eth_43_GMAC_Ipw_WriteMii    ( \
                    const uint8 CtrlIdx, \
                    const uint8 Trcv, \
                    const uint8 Reg, \
                    const uint16 Data
                                   );
extern boolean Eth_43_GMAC_Ipw_ReadMii ( \
                        const uint8 CtrlIdx, \
                        const uint8 Trcv, \
                        const uint8 Reg, \
                        uint16 * const Data
                               );
#endif /* ETH_43_GMAC_MDIO_CLAUSE22_API */

#if STD_ON == ETH_43_GMAC_MDIO_CLAUSE45_API 
extern boolean Eth_43_GMAC_Ipw_ReadMmd ( \
                             const uint8 CtrlIdx,\
                             const uint8 TrcvIdx, \
                             const uint8 Mmd, \
                             const uint16 RegAddress,\
                             uint16 * RegValPtr
                        );                                          
extern boolean Eth_43_GMAC_Ipw_WriteMmd ( \
                                    const uint8 CtrlIdx,\
                                    const uint8 TrcvIdx, \
                                    const uint8 Mmd, \
                                    const uint16 RegAddress,\
                                    const uint16 RegVal
                                );                                            
#endif

#if STD_ON == ETH_43_GMAC_GET_TXSTATS_API
extern Std_ReturnType Eth_43_GMAC_Ipw_GetTxStats ( \
                       uint8 CtrlIdx, \
                       Eth_TxStatsType *TxStatsPtr \
                                         );
#endif

#if STD_ON == ETH_43_GMAC_GET_TXERROR_COUNTER_API
extern Std_ReturnType Eth_43_GMAC_Ipw_GetTxErrorCounterValues ( \
                       uint8 CtrlIdx, \
                       Eth_TxErrorCounterValuesType *TxErrorCounterValuesPtr \
                                               );
#endif

#if STD_ON == ETH_43_GMAC_GLOBAL_TIME_API
extern void Eth_43_GMAC_Ipw_SetGlobalTime ( \
                      uint8 CtrlIdx, \
                      const Eth_43_GMAC_ClockCfgType *ClkCfg, \
                      const Eth_TimeStampType * TimeStampPtr \
                        );
extern Std_ReturnType Eth_43_GMAC_Ipw_SetCorrectionTime ( \
                        uint8 CtrlIdx, \
                        const Eth_43_GMAC_ClockCfgType *ClkCfg, \
                        const Eth_TimeIntDiffType *TimeOffsetPtr, \
                        const Eth_RateRatioType* RateRatioPtr \
                            );
extern Std_ReturnType Eth_43_GMAC_Ipw_GetCurrentTime    ( \
                                uint8 CtrlIdx, \
                                Eth_TimeStampQualType *TimeQualPtr, \
                                Eth_TimeStampType *TimeStampPtr \
                                      );

extern void Eth_43_GMAC_Ipw_EnableEgressTimeStamp   ( \
                                uint8 CtrlIdx, \
                                Eth_BufIdxType BufIdx \
                                            );

extern void Eth_43_GMAC_Ipw_GetEgressTimeStamp  ( \
                                        const uint8 CtrlIdx, \
                                        const uint8 FifoIdx, \
                                        Eth_TimeStampQualType *TimeQual, \
                                        Eth_TimeStampType *TimeStamp \
                                        );

extern void Eth_43_GMAC_Ipw_GetIngressTimeStamp ( \
                                        const uint8 CtrlIdx, \
                                        const uint8 FifoIdx, \
                                        const uint8 *FrameData, \
                                        Eth_TimeStampQualType *TimeQual, \
                                        Eth_TimeStampType *TimeStamp \
                                        );
#endif

#if (STD_ON == ETH_43_GMAC_DEM_EVENT_DETECT)
extern boolean Eth_43_GMAC_Ipw_ErrorDetected( \
                                    const uint8 CtrlIdx, \
                                    const Eth_43_GMAC_DemErrorIdType DemErrorId \
                                    );
#endif

extern void Eth_43_GMAC_Ipw_ReportTransmission(
                                const Eth_43_GMAC_CtrlCfgType *EthControllerConfig, \
                                const uint8 FifoIdx \
                           );

#define ETH_43_GMAC_STOP_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ETH_43_GMAC_IPW_H */
