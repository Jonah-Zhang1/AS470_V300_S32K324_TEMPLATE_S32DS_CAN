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

/**
*   @file
*   @implements Eth_Ipw_PBcfg.c_Artifact
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
#include "Eth_43_GMAC_Ipw.h"
#include "Gmac_Ip.h"
#include "Eth_43_GMAC_Ipw_TrustedFunctions.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_43_GMAC_IPW_VENDOR_ID_C                      43
#define ETH_43_GMAC_IPW_AR_RELEASE_MAJOR_VERSION_C       4
#define ETH_43_GMAC_IPW_AR_RELEASE_MINOR_VERSION_C       7
#define ETH_43_GMAC_IPW_AR_RELEASE_REVISION_VERSION_C    0
#define ETH_43_GMAC_IPW_SW_MAJOR_VERSION_C               3
#define ETH_43_GMAC_IPW_SW_MINOR_VERSION_C               0
#define ETH_43_GMAC_IPW_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Eth_43_GMAC_Ipw.h */
#if (ETH_43_GMAC_IPW_VENDOR_ID_C != ETH_43_GMAC_IPW_VENDOR_ID)
    #error "Eth_43_GMAC_Ipw.c and Eth_43_GMAC_Ipw.h have different vendor ids"
#endif
#if ((ETH_43_GMAC_IPW_AR_RELEASE_MAJOR_VERSION_C    != ETH_43_GMAC_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_43_GMAC_IPW_AR_RELEASE_MINOR_VERSION_C    != ETH_43_GMAC_IPW_AR_RELEASE_MINOR_VERSION) || \
     (ETH_43_GMAC_IPW_AR_RELEASE_REVISION_VERSION_C != ETH_43_GMAC_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Eth_43_GMAC_Ipw.c and Eth_43_GMAC_Ipw.h are different"
#endif
#if ((ETH_43_GMAC_IPW_SW_MAJOR_VERSION_C != ETH_43_GMAC_IPW_SW_MAJOR_VERSION) || \
     (ETH_43_GMAC_IPW_SW_MINOR_VERSION_C != ETH_43_GMAC_IPW_SW_MINOR_VERSION) || \
     (ETH_43_GMAC_IPW_SW_PATCH_VERSION_C != ETH_43_GMAC_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eth_43_GMAC_Ipw.c and Eth_43_GMAC_Ipw.h are different"
#endif

/* Checks against Gmac_Ip.h */
#if (ETH_43_GMAC_IPW_VENDOR_ID_C != GMAC_IP_VENDOR_ID)
    #error "Eth_43_GMAC_Ipw.c and Gmac_Ip.h have different vendor ids"
#endif
#if ((ETH_43_GMAC_IPW_AR_RELEASE_MAJOR_VERSION_C    != GMAC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_43_GMAC_IPW_AR_RELEASE_MINOR_VERSION_C    != GMAC_IP_AR_RELEASE_MINOR_VERSION) || \
     (ETH_43_GMAC_IPW_AR_RELEASE_REVISION_VERSION_C != GMAC_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Eth_43_GMAC_Ipw.c and Gmac_Ip.h are different"
#endif
#if ((ETH_43_GMAC_IPW_SW_MAJOR_VERSION_C != GMAC_IP_SW_MAJOR_VERSION) || \
     (ETH_43_GMAC_IPW_SW_MINOR_VERSION_C != GMAC_IP_SW_MINOR_VERSION) || \
     (ETH_43_GMAC_IPW_SW_PATCH_VERSION_C != GMAC_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eth_43_GMAC_Ipw.c and Gmac_Ip.h are different"
#endif

/* Checks against Eth_43_GMAC_Ipw_TrustedFunctions.h */
#if (ETH_43_GMAC_IPW_VENDOR_ID_C != ETH_43_GMAC_IPW_TRUSTEDFUNCTIONS_VENDOR_ID)
    #error "Eth_43_GMAC_Ipw.c and Eth_43_GMAC_Ipw_TrustedFunctions.h have different vendor ids"
#endif
#if ((ETH_43_GMAC_IPW_AR_RELEASE_MAJOR_VERSION_C    != ETH_43_GMAC_IPW_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_43_GMAC_IPW_AR_RELEASE_MINOR_VERSION_C    != ETH_43_GMAC_IPW_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION) || \
     (ETH_43_GMAC_IPW_AR_RELEASE_REVISION_VERSION_C != ETH_43_GMAC_IPW_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Eth_43_GMAC_Ipw.c and Eth_43_GMAC_Ipw_TrustedFunctions.h are different"
#endif
#if ((ETH_43_GMAC_IPW_SW_MAJOR_VERSION_C != ETH_43_GMAC_IPW_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION) || \
     (ETH_43_GMAC_IPW_SW_MINOR_VERSION_C != ETH_43_GMAC_IPW_TRUSTEDFUNCTIONS_SW_MINOR_VERSION) || \
     (ETH_43_GMAC_IPW_SW_PATCH_VERSION_C != ETH_43_GMAC_IPW_TRUSTEDFUNCTIONS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eth_43_GMAC_Ipw.c and Eth_43_GMAC_Ipw_TrustedFunctions.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define ETH_43_GMAC_IPW_TIMEOUT_1MS_U16                 ((uint16)1U)
#define ETH_43_GMAC_IPW_MAX_DEM_ERRORS_U32              ((uint32)ETH_NUMBER_OF_DEM_IDS)
#define ETH_43_GMAC_IPW_DEM_ERROR_UNUSED_U32            ((uint32)GMAC_CTR_NUMBER_OF_COUNTERS)

#define ETH_43_GMAC_IPW_STONS_U64(Seconds)           ((uint64)((uint64)(Seconds) * (uint64)1000000000UL))

#define ETH_IPW_IP_EMAC                         (0U)
#define ETH_IPW_IP_GMAC                         (1U)

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ETH_43_GMAC_START_SEC_VAR_CLEARED_32
#include "Eth_43_GMAC_MemMap.h"

#if (STD_ON == ETH_43_GMAC_DEM_EVENT_DETECT)
    static uint32 Eth_43_GMAC_Ipw_au32DemErrorCounters[ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED][ETH_43_GMAC_IPW_MAX_DEM_ERRORS_U32];
#endif

static Eth_BufIdxType Eth_43_GMAC_Ipw_axFirstTxBufferIdxInFifo[ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED][ETH_43_GMAC_MAX_TXFIFO_SUPPORTED];

extern Eth_43_GMAC_axTxBufferIdxMapType Eth_43_GMAC_axTxBufferIdxMap[ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED][ETH_43_GMAC_MAX_TXFIFO_SUPPORTED * ETH_43_GMAC_MAX_TXBUFF_SUPPORTED];

#define ETH_43_GMAC_STOP_SEC_VAR_CLEARED_32
#include "Eth_43_GMAC_MemMap.h"


#define ETH_43_GMAC_START_SEC_CONST_32
#include "Eth_43_GMAC_MemMap.h"

#if (STD_ON == ETH_43_GMAC_DEM_EVENT_DETECT)
    /* Map between Eth_43_GMAC_DemErrorIdType and Gmac_Ip_CounterType */
    static const Gmac_Ip_CounterType Eth_43_GMAC_Ipw_axDemErrIdToMmcCnt[ETH_43_GMAC_IPW_MAX_DEM_ERRORS_U32] =
    {
        (Gmac_Ip_CounterType)ETH_43_GMAC_IPW_DEM_ERROR_UNUSED_U32,
        GMAC_CTR_RX_FIFO_OVERFLOW_PACKETS,
        GMAC_CTR_RX_CRC_ERROR_PACKETS,
        GMAC_CTR_RX_UNDERSIZE_PACKETS_GOOD,
        GMAC_CTR_RX_OVERSIZE_PACKETS_GOOD,
        GMAC_CTR_RX_ALIGNMENT_ERROR_PACKETS,
        GMAC_CTR_TX_SINGLE_COLLISION_GOOD_PACKETS,
        GMAC_CTR_TX_MULTIPLE_COLLISION_GOOD_PACKETS,
        GMAC_CTR_TX_LATE_COLLISION_PACKETS
    };
#endif

#define ETH_43_GMAC_STOP_SEC_CONST_32
#include "Eth_43_GMAC_MemMap.h"


#define ETH_43_GMAC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"

/* Eth_43_GMAC_Receive is reentrant for different FIFOs so we need a pair of (Gmac_Ip_BufferType, Gmac_Ip_RxInfoType) for each FIFO */
static Gmac_Ip_BufferType Eth_43_GMAC_Ipw_axRxFrameBuffer[ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED][ETH_43_GMAC_MAX_RXFIFO_SUPPORTED];
static Gmac_Ip_RxInfoType Eth_43_GMAC_Ipw_axRxFrameInfo[ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED][ETH_43_GMAC_MAX_RXFIFO_SUPPORTED];

/* We cannot guarantee reentrancy in Eth_43_GMAC_Transmit for different buffer indexes */
/* Make Eth_43_GMAC_Transmit reentrant for different FIFOs so we need (Gmac_Ip_TxInfoType) for each FIFO */
static Gmac_Ip_TxInfoType Eth_43_GMAC_Ipw_axTxFrameInfo[ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED][ETH_43_GMAC_MAX_TXFIFO_SUPPORTED];

#define ETH_43_GMAC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"

#if (STD_ON == ETH_43_GMAC_HAS_EXTERNAL_TX_BUFFERS)
#define ETH_43_GMAC_START_SEC_CONST_BOOLEAN
#include "Eth_43_GMAC_MemMap.h"

/** @brief Table storing information related to the method of Tx Data Buffers Management.*/
static const boolean Eth_43_GMAC_Ipw_InstHasExternalBufferManagement[FEATURE_GMAC_NUM_INSTANCES] = GMAC_IP_INST_HAS_EXTERNAL_TX_BUFFERS;

#define ETH_43_GMAC_STOP_SEC_CONST_BOOLEAN
#include "Eth_43_GMAC_MemMap.h"
#endif

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define ETH_43_GMAC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"

/* Pointers to IPW configuration structures stored for later use */
const Eth_43_GMAC_Ipw_CtrlConfigType *Eth_43_GMAC_Ipw_apxInternalCfg[ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED];
extern Eth_43_GMAC_QueueInfo Eth_43_GMAC_axTransmissionRequests[ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED][ETH_43_GMAC_MAX_TXFIFO_SUPPORTED];

#define ETH_43_GMAC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#if (STD_ON == ETH_43_GMAC_SEND_MULTI_BUFFER_FRAME_API)

#define ETH_43_GMAC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"

static Gmac_Ip_BufferType Eth_43_GMAC_Ipw_MultiBufferFrame[ETH_43_GMAC_MAX_BUFFS_IN_MULTI_BUFFER_FRAME];

#define ETH_43_GMAC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"

#endif

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ETH_43_GMAC_START_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"

#if (STD_ON == ETH_43_GMAC_UPDATE_PHYS_ADDR_FILTER_API)
static inline boolean Eth_43_GMAC_Ipw_Local_IsOpenFilterPattern(const uint8 *PhyAddr);
static inline boolean Eth_43_GMAC_Ipw_Local_IsCloseFilterPattern(const uint8 *PhyAddr);
static inline boolean Eth_43_GMAC_Ipw_Local_IsMulticastAddress(const uint8 *PhyAddr);
#endif
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if (STD_ON == ETH_43_GMAC_ENABLE_USER_MODE_SUPPORT)
    #define Eth_43_GMAC_Ipw_Local_Macro_SelectPhyInterface(ModeSelect)   OsIf_Trusted_Call1param(Eth_43_GMAC_Ipw_SelectPhyInterface,(ModeSelect))
#else
    #define Eth_43_GMAC_Ipw_Local_Macro_SelectPhyInterface(ModeSelect)   Eth_43_GMAC_Ipw_SelectPhyInterface((ModeSelect))
#endif

#if (STD_ON == ETH_43_GMAC_UPDATE_PHYS_ADDR_FILTER_API)
    /* Check whether address filtering is totally open or not */
static inline boolean Eth_43_GMAC_Ipw_Local_IsOpenFilterPattern(const uint8 *PhyAddr)
{
    return ((PhyAddr[0U] == 0xFFU) && (PhyAddr[1U] == 0xFFU) && (PhyAddr[2U] == 0xFFU) && (PhyAddr[3U] == 0xFFU) && (PhyAddr[4U] == 0xFFU) && (PhyAddr[5U] == 0xFFU));
}

/* Check whether address filtering is totally close or not */
static inline boolean Eth_43_GMAC_Ipw_Local_IsCloseFilterPattern(const uint8 *PhyAddr)
{
    return ((PhyAddr[0U] == 0U) && (PhyAddr[1U] == 0U) && (PhyAddr[2U] == 0U) && (PhyAddr[3U] == 0U) && (PhyAddr[4U] == 0U) && (PhyAddr[5U] == 0U)); 
}

static inline boolean Eth_43_GMAC_Ipw_Local_IsMulticastAddress(const uint8 *PhyAddr)
{
    /* Check if I/G bit is set (indicates a multicast address) */
    return (1U == (PhyAddr[0] & 1U));
}
#endif
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief         Set RMII/MII interface mode
*
* @param[in]     ModeSelect       RMII/MII select bit.
*
* @return        void
*/
void Eth_43_GMAC_Ipw_SelectPhyInterface(Gmac_Ip_MiiModeType ModeSelect)
{
   #if (ETH_IPW_IP_EMAC == GMAC_IP_FEATURE_ORIGIN)
    if (GMAC_MII_MODE == ModeSelect)
    {
        IP_DCM_GPR->DCMRWF1 = (IP_DCM_GPR->DCMRWF1 & ~DCM_GPR_DCMRWF1_EMAC_CONF_SEL_MASK) | DCM_GPR_DCMRWF1_EMAC_CONF_SEL(0U);
    }
    else if  (GMAC_RMII_MODE == ModeSelect)
    {
    #if defined(S32K396) || defined(S32K394)
        IP_DCM_GPR->DCMRWF1 = (IP_DCM_GPR->DCMRWF1 & ~DCM_GPR_DCMRWF1_EMAC_CONF_SEL_MASK) | DCM_GPR_DCMRWF1_EMAC_CONF_SEL(1U);
    #else
        IP_DCM_GPR->DCMRWF1 = (IP_DCM_GPR->DCMRWF1 & ~DCM_GPR_DCMRWF1_EMAC_CONF_SEL_MASK) | DCM_GPR_DCMRWF1_EMAC_CONF_SEL(2U);
    #endif
    }
   #endif
   #if (ETH_IPW_IP_GMAC == GMAC_IP_FEATURE_ORIGIN)
    if (GMAC_MII_MODE == ModeSelect)
    {
        IP_DCM_GPR->DCMRWF1 = (IP_DCM_GPR->DCMRWF1 & ~DCM_GPR_DCMRWF1_EMAC_CONF_SEL_MASK) | DCM_GPR_DCMRWF1_EMAC_CONF_SEL(0U);
    }
    else if  (GMAC_RMII_MODE == ModeSelect)
    {
        IP_DCM_GPR->DCMRWF1 = (IP_DCM_GPR->DCMRWF1 & ~DCM_GPR_DCMRWF1_EMAC_CONF_SEL_MASK) | DCM_GPR_DCMRWF1_EMAC_CONF_SEL(2U);
    }
    #if FEATURE_GMAC_RGMII_EN
    else
    {
        IP_DCM_GPR->DCMRWF1 = (IP_DCM_GPR->DCMRWF1 & ~DCM_GPR_DCMRWF1_EMAC_CONF_SEL_MASK) | DCM_GPR_DCMRWF1_EMAC_CONF_SEL(1U);
    }
    #endif
   #endif
}

/*================================================================================================*/
/**
* @brief         Reads a frame from the given FIFO of the given controller
*
* @param[in]     CtrlIdx       Index of the controller
* @param[in]     FifoIdx       Index of the FIFO from which the frame should be read
* @param[out]    FrameData   Pointer to the frame data
* @param[out]    FrameLength Pointer to the length of the frame
* @param[out]    FrameHasError Pointer to flag signaling if the frame is erroneous
*
* @return        Eth_RxStatusType
* @retval        ETH_NOT_RECEIVED No frame received
* @retval        ETH_RECEIVED     Frame received, no more frames available
* @retval        ETH_RECEIVED_MORE_DATA_AVAILABLE Frame received, more frames are available
*/
Eth_RxStatusType Eth_43_GMAC_Ipw_ReceiveFrame ( \
                                           const uint8 CtrlIdx, \
                                           const uint8 FifoIdx, \
                                           uint8 **FrameData, \
                                           uint16 *FrameLength, \
                                           boolean *FrameHasError
                                      )
{
    Eth_RxStatusType RxStatus = ETH_NOT_RECEIVED;

    if (GMAC_STATUS_RX_QUEUE_EMPTY != Gmac_Ip_ReadFrame(CtrlIdx, FifoIdx, &Eth_43_GMAC_Ipw_axRxFrameBuffer[CtrlIdx][FifoIdx], &Eth_43_GMAC_Ipw_axRxFrameInfo[CtrlIdx][FifoIdx]))
    {
        *FrameData   = Eth_43_GMAC_Ipw_axRxFrameBuffer[CtrlIdx][FifoIdx].Data;
        *FrameLength = Eth_43_GMAC_Ipw_axRxFrameInfo[CtrlIdx][FifoIdx].PktLen;
        *FrameHasError = ((0U != Eth_43_GMAC_Ipw_axRxFrameInfo[CtrlIdx][FifoIdx].ErrMask)? ((boolean)TRUE) : ((boolean)FALSE));

        RxStatus = ETH_RECEIVED;

        if (Gmac_Ip_IsFrameAvailable(CtrlIdx, FifoIdx))
        {
            RxStatus = ETH_RECEIVED_MORE_DATA_AVAILABLE;
        }
    }

    return RxStatus;
}

/*================================================================================================*/
/**
* @brief         Releases the resources locked by the previous call to function Eth_43_GMAC_Ipw_ReceiveFrame
*
* @param[in]     CtrlIdx      Index of the controller
* @param[in]     FifoIdx      Index of the FIFO from which the frame was read
*
* @return        void
*/
void Eth_43_GMAC_Ipw_ReleaseResources ( \
                                const uint8 CtrlIdx, \
                                const uint8 FifoIdx  \
                              )
{
    Gmac_Ip_ProvideRxBuff(CtrlIdx, FifoIdx, &Eth_43_GMAC_Ipw_axRxFrameBuffer[CtrlIdx][FifoIdx]);

    /* Mark the buffer as released */
    Eth_43_GMAC_Ipw_axRxFrameBuffer[CtrlIdx][FifoIdx].Data = NULL_PTR;
}

#if STD_ON == ETH_43_GMAC_GET_RXSTATS_API
/*================================================================================================*/
/**
* @brief         Return the list of Receive Statistics.
* @param[in]     CtrlIdx Index of controller within the context of the Ethernet Driver.
* @param[out]    RxStats List of values according to IETF RFC 2819.
* @details       RxStats List of values according to IETF RFC 2819, where the maximal possible value shall
*                denote an invalid value.
*                e.g. if this counter is not available.
*/
Std_ReturnType Eth_43_GMAC_Ipw_GetRxStats ( \
                       uint8 CtrlIdx, \
                       Eth_RxStatsType *RxStatsPtr \
                                  )
{
    /* Maximal possible value shall denote an invalid value (e.g. counter not available) */
    /* Warning: All this fumbling on the call stack might have a negative impact on performance.
     *          Execution times shall be measured and compared. */

    RxStatsPtr->RxStatsDropEvents           = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_RX_FIFO_OVERFLOW_PACKETS);
    RxStatsPtr->RxStatsOctets               = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_RX_OCTET_COUNT_GOOD_BAD);
    RxStatsPtr->RxStatsPkts                 = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_RX_PACKETS_COUNT_GOOD_BAD);
    RxStatsPtr->RxStatsBroadcastPkts        = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_RX_BROADCAST_PACKETS_GOOD);
    RxStatsPtr->RxStatsMulticastPkts        = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_RX_MULTICAST_PACKETS_GOOD);
    RxStatsPtr->RxStatsCrcAlignErrors       = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_RX_CRC_ERROR_PACKETS);
    RxStatsPtr->RxStatsCrcAlignErrors      += Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_RX_ALIGNMENT_ERROR_PACKETS); 
    RxStatsPtr->RxStatsUndersizePkts        = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_RX_UNDERSIZE_PACKETS_GOOD);
    RxStatsPtr->RxStatsOversizePkts         = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_RX_OVERSIZE_PACKETS_GOOD);
    RxStatsPtr->RxStatsFragments            = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_RX_RUNT_ERROR_PACKETS);
    RxStatsPtr->RxStatsJabbers              = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_RX_JABBER_ERROR_PACKETS);
    RxStatsPtr->RxStatsCollisions           = (uint32)-1;
    RxStatsPtr->RxStatsPkts64Octets         = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_RX_64OCTETS_PACKETS_GOOD_BAD);
    RxStatsPtr->RxStatsPkts65to127Octets    = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_RX_65TO127OCTETS_PACKETS_GOOD_BAD);
    RxStatsPtr->RxStatsPkts128to255Octets   = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_RX_128TO255OCTETS_PACKETS_GOOD_BAD);
    RxStatsPtr->RxStatsPkts256to511Octets   = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_RX_256TO511OCTETS_PACKETS_GOOD_BAD);
    RxStatsPtr->RxStatsPkts512to1023Octets  = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_RX_512TO1023OCTETS_PACKETS_GOOD_BAD);
    RxStatsPtr->RxStatsPkts1024to1518Octets = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD);
    RxStatsPtr->RxUnicastFrames             = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_RX_UNICAST_PACKETS_GOOD);

    return (Std_ReturnType)E_OK;
}
#endif

#if STD_ON == ETH_43_GMAC_GET_TXSTATS_API
/*================================================================================================*/
/**
* @brief         Return the list of Transmission Statistics.
* @param[in]     CtrlIdx Index of controller within the context of the Ethernet Driver.
* @param[out]     TxStats List of the controller within the context of the Ethernet Driver.
* @details       Return the list of Transmission Sratistics out of IETF RFC1213
*                defined with Eth_TxStatsType, where the maximal possible value shall
*                denote an invalid value.
*                e.g. this counter is not available..
*/
Std_ReturnType Eth_43_GMAC_Ipw_GetTxStats ( \
                       uint8 CtrlIdx, \
                       Eth_TxStatsType * TxStatsPtr \
                                  )
{
    /* Maximal possible value shall denote an invalid value (e.g. counter not available) */
    /* Warning: All this fumbling on the call stack might have a negative impact on performance.
     *          Execution times shall be measured and compared. */

    TxStatsPtr->TxNumberOfOctets  = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_TX_OCTET_COUNT_GOOD_BAD);
    TxStatsPtr->TxNUcastPkts      = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_TX_MULTICAST_PACKETS_GOOD_BAD);
    TxStatsPtr->TxNUcastPkts     += Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_TX_BROADCAST_PACKETS_GOOD_BAD);                               
    TxStatsPtr->TxUniCastPkts     = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_TX_UNICAST_PACKETS_GOOD_BAD);

    return (Std_ReturnType)E_OK;
}
#endif

#if STD_ON == ETH_43_GMAC_GET_TXERROR_COUNTER_API
/*================================================================================================*/
/**
* @brief         Return the list of Transmission Statistics.
* @param[in]     CtrlIdx Index of controller within the context of the Ethernet Driver.
* @param[out]    Eth_TxErrorCounterValuesType List of values to read statistic error values for transmiision.
* @details       Return the list of Transmission Error Counters out of IETF RFC1213 and RFC1643
*                defined with Eth_TxErrorCounterValuesType, where the maximal possible value shall
*                denote an invalid value.
*                e.g. this counter is not available..
*/
Std_ReturnType Eth_43_GMAC_Ipw_GetTxErrorCounterValues ( \
                       uint8 CtrlIdx, \
                       Eth_TxErrorCounterValuesType *TxErrorCounterValuesPtr \
                                               )
{
    /* Maximal possible value shall denote an invalid value (e.g. counter not available) */
    /* Warning: All this fumbling on the call stack might have a negative impact on performance.
     *          Execution times shall be measured and compared. */

    TxErrorCounterValuesPtr->TxDroppedNoErrorPkts = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_TX_UNDERFLOW_ERROR_PACKETS);
    TxErrorCounterValuesPtr->TxDroppedErrorPkts   = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_TX_PACKET_COUNT_GOOD_BAD);
    TxErrorCounterValuesPtr->TxDroppedErrorPkts  -= Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_TX_PACKET_COUNT_GOOD);                                              
    TxErrorCounterValuesPtr->TxDeferredTrans      = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_TX_DEFERRED_PACKETS);
    TxErrorCounterValuesPtr->TxSingleCollision    = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_TX_SINGLE_COLLISION_GOOD_PACKETS);
    TxErrorCounterValuesPtr->TxMultipleCollision  = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_TX_MULTIPLE_COLLISION_GOOD_PACKETS);
    TxErrorCounterValuesPtr->TxLateCollision      = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_TX_LATE_COLLISION_PACKETS);
    TxErrorCounterValuesPtr->TxExcessiveCollison  = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_TX_EXCESSIVE_COLLISION_PACKETS);

    return (Std_ReturnType)E_OK;
}
#endif

#if STD_ON == ETH_43_GMAC_GLOBAL_TIME_API
/*================================================================================================*/
/**
* @brief        Allows the Time Master to adjust the global ETH Reference clock in HW.
* @details      We can use this method to set a global time base on ETH in general or to
*               synchronize the global ETH time base with another time base, e.g. FlexRay.
* @param[in]    CtrlIdx Index of the TM controller which time shall be adjusted.
* @param[in]    ClkCfg Clock for timestamp
* @param[in]    timeStampPtr Pointer to new time stamp.
*/
void Eth_43_GMAC_Ipw_SetGlobalTime ( \
                      uint8 CtrlIdx, \
                      const Eth_43_GMAC_ClockCfgType *ClkCfg, \
                      const Eth_TimeStampType * TimeStampPtr \
                        )
{
    Gmac_Ip_TimestampType TimeStamp = {0U, 0U, 0U};
    Gmac_Ip_SysTimeConfigType SysTimeConfig = {0U, 0U, &TimeStamp};
    
    SysTimeConfig.SubSecondInc                   = (uint8)(ClkCfg->TimeStampClockPeriodPs / 1000U);
    SysTimeConfig.SubNanoSecondsInc              = (uint8)(((ClkCfg->TimeStampClockPeriodPs - ((uint32)SysTimeConfig.SubSecondInc * 1000U)) * 256U) / 1000U);
    SysTimeConfig.InitialTimestamp->nanoseconds  = TimeStampPtr->nanoseconds;
    SysTimeConfig.InitialTimestamp->seconds      = TimeStampPtr->seconds;
    SysTimeConfig.InitialTimestamp->secondsHi    = TimeStampPtr->secondsHi;
    
    Gmac_Ip_InitSysTime(CtrlIdx, &SysTimeConfig);
}

/*================================================================================================*/
/**
* @brief        Allows the Time Slave to adjust the local ETH Reference clock in HW.
* @details      Only use this function when this controller used as Time Slave.
*              
* @param[in]    CtrlIdx        Index of the controller which time shall be corrected
* @param[in]    timeOffsetPtr  Offset between time stamp grandmaster and time stamp by local 
*               clock.
* @param[in]    RateRatioPtr  Time elements to calculate and to modify the ratio of the frequency of 
*                              the grandmaster in relation to the frequency of the Local Clock
*/
Std_ReturnType Eth_43_GMAC_Ipw_SetCorrectionTime ( \
                        uint8 CtrlIdx, \
                        const Eth_43_GMAC_ClockCfgType *ClkCfg, \
                        const Eth_TimeIntDiffType *TimeOffsetPtr, \
                        const Eth_RateRatioType* RateRatioPtr \
                            )
{
    /* Function could be used only for rate ratio correction.
     * To ensure that system time correction is not required beforehand,
     * this status must be initialzied to GMAC_STATUS_SUCCESS */
    Gmac_Ip_StatusType Status = GMAC_STATUS_SUCCESS;
    uint64 RemoteTime;
    uint64 LocalTime;
    float64 AddendTime;
    float64 AddendTimeUpdate;
    Std_ReturnType RetVal = E_NOT_OK;

    if ((TimeOffsetPtr->diff.seconds != 0U) || (TimeOffsetPtr->diff.nanoseconds != 0U))
    {
        Status = Gmac_Ip_SetSysTimeCorr(CtrlIdx, ((TimeOffsetPtr->sign == (boolean)TRUE) ? (Gmac_Ip_SysTimeCorrOffsetType)GMAC_SYS_TIME_CORR_POSITIVE : (Gmac_Ip_SysTimeCorrOffsetType)GMAC_SYS_TIME_CORR_NEGATIVE), TimeOffsetPtr->diff.seconds, TimeOffsetPtr->diff.nanoseconds); 
    }

    if (GMAC_STATUS_SUCCESS == Status)
    {
        RemoteTime = ETH_43_GMAC_IPW_STONS_U64(
                           ((uint64)RateRatioPtr->OriginTimeStampDelta.diff.secondsHi << 32U) +
                            (uint64)RateRatioPtr->OriginTimeStampDelta.diff.seconds
                        ) + (uint64)RateRatioPtr->OriginTimeStampDelta.diff.nanoseconds;

        LocalTime  = ETH_43_GMAC_IPW_STONS_U64(
                           ((uint64)RateRatioPtr->IngressTimeStampDelta.diff.secondsHi << 32U) +
                            (uint64)RateRatioPtr->IngressTimeStampDelta.diff.seconds
                        ) + (uint64)RateRatioPtr->IngressTimeStampDelta.diff.nanoseconds;

        if (RemoteTime != 0U)
        {
            AddendTime = (float64)ClkCfg->TimeStampReqClockPeriodNs / (float64)((float64)ClkCfg->TimeStampClockPeriodPs / (float64)1000U);
            AddendTimeUpdate = ((float64)LocalTime / (float64)RemoteTime) * AddendTime;
            Status = Gmac_Ip_SetRateRatioCorr(CtrlIdx, AddendTimeUpdate);
        }
    }

    if(GMAC_STATUS_SUCCESS == Status)
    {
        RetVal = E_OK;
    }
    return RetVal;
}

/*================================================================================================*/
/**
* @brief        Get values of timer at this time.
* @details      Returns a time value out of the HW registers according to the capability of the HW.
*               Is the HW resolution is lower than the Eth_TimeStampType resolution resp.
*               Range, than an the remaining bits will be filled with 0.
* @param[in]    CtrlIdx Index of controller to be update the filter
* @param[out]   TimeQualPtr Quality of HW time stamp, e.g. based on current drift.
* @param[out]   TimeStampPtr current time stamp.
*/
Std_ReturnType Eth_43_GMAC_Ipw_GetCurrentTime    ( \
                      uint8 CtrlIdx, \
                      Eth_TimeStampQualType *TimeQualPtr, \
                      Eth_TimeStampType *TimeStampPtr \
                               )
{
    Gmac_Ip_TimestampType TimeStamp;

    Gmac_Ip_GetSysTime(CtrlIdx, &TimeStamp);
    
    TimeStampPtr->nanoseconds = TimeStamp.nanoseconds;
    TimeStampPtr->seconds = TimeStamp.seconds;
    TimeStampPtr->secondsHi = TimeStamp.secondsHi;
    
    *TimeQualPtr = ETH_VALID;
    
    return (Std_ReturnType)E_OK;
}

/*================================================================================================*/
/**
* @brief        Enable egress time stamping on a trsnsmission message.
* @details      Activates egress time stamping on a dedicated message object.
*               Some HW does store once the egress time stamp merker and some HW needs it always before transmission.
*               There will be no "disable" functionality, due to the fact, that the message type is always "time stamped" by network design.
* @param[in]    CtrlIdx Index of controller to be update the filter
* @param[in]    BufIdx Index of the message buffer, where Application expects egress time stamping.
*/
void Eth_43_GMAC_Ipw_EnableEgressTimeStamp   ( \
                                uint8 CtrlIdx, \
                                Eth_BufIdxType BufIdx \
                                     )
{
    /* Prevent misra, compiler warnings */
    (void)CtrlIdx;
    (void)BufIdx;
}

/*================================================================================================*/
/**
* @brief        Get values of timer at the time transmit a message.
* @details      Reads back the egress time stamp on a dedicated message object.
*               It must be called within the TxConfirmation() function.
* @param[in]    CtrlIdx Index of controller to be update the filter
* @param[out]   TimeQual Quality of HW time stamp, e.g. based on current drift.
* @param[out]   TimeStamp current time stamp.
*/
void Eth_43_GMAC_Ipw_GetEgressTimeStamp  ( \
                                    const uint8 CtrlIdx, \
                                    const uint8 FifoIdx, \
                                    Eth_TimeStampQualType *TimeQual, \
                                    Eth_TimeStampType *TimeStamp \
                                 )
{
    if ((0U == Eth_43_GMAC_Ipw_axTxFrameInfo[CtrlIdx][FifoIdx].Timestamp.seconds) &&
        (0U == Eth_43_GMAC_Ipw_axTxFrameInfo[CtrlIdx][FifoIdx].Timestamp.nanoseconds))
    {
        *TimeQual= ETH_INVALID;
    }
    else
    {
        TimeStamp->nanoseconds = Eth_43_GMAC_Ipw_axTxFrameInfo[CtrlIdx][FifoIdx].Timestamp.nanoseconds;
        TimeStamp->seconds     = Eth_43_GMAC_Ipw_axTxFrameInfo[CtrlIdx][FifoIdx].Timestamp.seconds;
        TimeStamp->secondsHi   = Eth_43_GMAC_Ipw_axTxFrameInfo[CtrlIdx][FifoIdx].Timestamp.secondsHi;

        *TimeQual = ETH_VALID;
    }
}

/*================================================================================================*/
/**
* @brief        Get values of timer at the time receive a message.
* @details      Reads back the ingress time stamp on a dedicated message object.
*               It must be called within the RxIndication() function.
* @param[in]    CtrlIdx Index of controller to be update the filter
* @param[out]   TimeQualPtr Quality of HW time stamp, e.g. based on current drift.
* @param[out]   TimeStampPtr current time stamp.
*/
void Eth_43_GMAC_Ipw_GetIngressTimeStamp ( \
                                    const uint8 CtrlIdx, \
                                    const uint8 FifoIdx, \
                                    const uint8 *FrameData, \
                                    Eth_TimeStampQualType *TimeQual, \
                                    Eth_TimeStampType *TimeStamp \
                                 )
{
    if (FrameData == Eth_43_GMAC_Ipw_axRxFrameBuffer[CtrlIdx][FifoIdx].Data)
    {
        if ((0U == Eth_43_GMAC_Ipw_axRxFrameInfo[CtrlIdx][FifoIdx].Timestamp.seconds) &&
            (0U == Eth_43_GMAC_Ipw_axRxFrameInfo[CtrlIdx][FifoIdx].Timestamp.nanoseconds))
        {
            *TimeQual = ETH_INVALID;
        }
        else
        {
            TimeStamp->nanoseconds = Eth_43_GMAC_Ipw_axRxFrameInfo[CtrlIdx][FifoIdx].Timestamp.nanoseconds;
            TimeStamp->seconds     = Eth_43_GMAC_Ipw_axRxFrameInfo[CtrlIdx][FifoIdx].Timestamp.seconds;
            TimeStamp->secondsHi   = Eth_43_GMAC_Ipw_axRxFrameInfo[CtrlIdx][FifoIdx].Timestamp.secondsHi;

            *TimeQual = ETH_VALID;
        }
    }
}
#endif

#if (STD_ON == ETH_43_GMAC_DEM_EVENT_DETECT)
/*================================================================================================*/
/**
* @brief        Get errors and lost frames.
* @details      This function is only called by "Eth_MainFunction"
*/
boolean Eth_43_GMAC_Ipw_ErrorDetected( \
                            const uint8 CtrlIdx, \
                            const Eth_43_GMAC_DemErrorIdType DemErrorId \
                             )
{
    uint32 OldValue;
    Gmac_Ip_CounterType MmcCounter;

    OldValue = Eth_43_GMAC_Ipw_au32DemErrorCounters[CtrlIdx][(uint32)DemErrorId];
    MmcCounter  = Eth_43_GMAC_Ipw_axDemErrIdToMmcCnt[(uint32)DemErrorId];
    Eth_43_GMAC_Ipw_au32DemErrorCounters[CtrlIdx][(uint32)DemErrorId] = Gmac_Ip_GetCounter(CtrlIdx, MmcCounter);

    return ((Eth_43_GMAC_Ipw_au32DemErrorCounters[CtrlIdx][(uint32)DemErrorId] > OldValue)? ((boolean)TRUE) : ((boolean)FALSE));
}
#endif

/*================================================================================================*/
/**
* @brief         Checks the access to the controller
* @details       Function is intended to be used only after the Ethernet
*                controller reset. It checks the reset value of one register
*                and checks whether it agrees with the datasheet value.
*                Controller is claimed as accessible if the value agrees.
* @param[in]     CtrlIdx Index of controller which will be checked the access
* @return        Controller accessibility
* @retval        TRUE Controller is accessible, value in register agrees.
* @retval        FALSE Controller access failed, different value read.
*/
boolean Eth_43_GMAC_Ipw_CheckAccessToController(const uint8 CtrlIdx)
{
    /* This check only makes sense for Ethernet controllers that are not accessed directly
     * through a bus interface (e.g. AXI/AHB/APB), but through a communication interface
     * (e.g. SPI) */

    (void)CtrlIdx;

    return (boolean)TRUE;
}
/*================================================================================================*/
/**
* @brief         Control frame transmitted in a duration time.
* @details       Function will initialize duration time with open or close to enable
*                frame can be transmitted or not in that duration time.               
* @param[in]     CtrlIdx Index of controller which will be checked the access
* @param[in]     IpwCtrlCfg parameters of controller will be used.
* @return        Std_ReturnType
*/
Std_ReturnType Eth_43_GMAC_Ipw_TxTimeAwareShaperInit ( \
                                    uint8 CtrlIdx, \
                                    const Eth_43_GMAC_Ipw_CtrlConfigType *IpwCtrlCfg \
                                    )
{    
    return ((GMAC_STATUS_SUCCESS == Gmac_Ip_TxTimeAwareShaperInit(CtrlIdx, IpwCtrlCfg->Eth_43_GMAC_Ipw_pGmacCtrlConfig))? ((Std_ReturnType)E_OK) : ((Std_ReturnType)E_NOT_OK));
}

/*================================================================================================*/
/**
* @brief         Configures the controller
* @details       Function
*                -# enables/disables Received frame interrupts
*                -# enables/disables Transmitted frame interrupts
*                -# clears MAC addresses hash tables
*                -# configures the controller MAC address
*                -# configures the MII
*                -# configures RCR and TCR registers
*                -# configures the maximal received frame length
*                -# configures all other registers including unused ones
*                   to prevent corrupted values staying there forever
* @param[in]     CtrlIdx Index of controller which will be configured
*/
Std_ReturnType Eth_43_GMAC_Ipw_ConfigureController  ( \
                                    const uint8 CtrlIdx, \
                                    const Eth_43_GMAC_Ipw_CtrlConfigType *IpwCtrlCfg, \
                                    const Eth_43_GMAC_ClockCfgType *ClkCfg \
                                         )
{
    uint32 Counter;
    Std_ReturnType FunctionSuccess;
#if (STD_ON == ETH_43_GMAC_GLOBAL_TIME_API)
    Gmac_Ip_TimestampType InitialTimestamp  = {0U, 0U, 0U};
    Gmac_Ip_SysTimeConfigType SysTimeConfig = {0U, 0U, NULL_PTR};
#endif

    Eth_43_GMAC_Ipw_apxInternalCfg[CtrlIdx] = IpwCtrlCfg;

#if (STD_ON == ETH_43_GMAC_DEM_EVENT_DETECT)
    for (Counter = 0U; Counter < ETH_43_GMAC_IPW_MAX_DEM_ERRORS_U32; ++Counter)
    {
        Eth_43_GMAC_Ipw_au32DemErrorCounters[CtrlIdx][Counter] = 0U;
    }
#endif

    for (Counter = 0U; Counter < ETH_43_GMAC_MAX_RXFIFO_SUPPORTED; ++Counter)
    {
        Eth_43_GMAC_Ipw_axRxFrameBuffer[CtrlIdx][Counter].Data = NULL_PTR;
    }

    Eth_43_GMAC_Ipw_axFirstTxBufferIdxInFifo[CtrlIdx][0U] = 0U;
#if (ETH_43_GMAC_MAX_TXFIFO_SUPPORTED > 1U)
    for (Counter = 1U; Counter < IpwCtrlCfg->Eth_43_GMAC_Ipw_pGmacCtrlConfig->Gmac_pCtrlConfig->TxRingCount; ++Counter)
    {
        Eth_43_GMAC_Ipw_axFirstTxBufferIdxInFifo[CtrlIdx][Counter] = Eth_43_GMAC_Ipw_axFirstTxBufferIdxInFifo[CtrlIdx][Counter - 1U] +
                                                                   IpwCtrlCfg->Eth_43_GMAC_Ipw_pGmacCtrlConfig->Gmac_paCtrlTxRingConfig[Counter - 1U].RingSize;
    }
#endif  
    /* Select PHY interface (MII mode) */
    /* This PHY interface selection should be somehow generalized to N controllers */
    /* Should be done before the controller is reset, because the interface type is latched at (controller's) reset */
    Eth_43_GMAC_Ipw_Local_Macro_SelectPhyInterface(IpwCtrlCfg->Eth_43_GMAC_Ipw_pGmacCtrlConfig->Gmac_pCtrlConfig->MiiMode);
    FunctionSuccess = ((GMAC_STATUS_SUCCESS == Gmac_Ip_Init(CtrlIdx, IpwCtrlCfg->Eth_43_GMAC_Ipw_pGmacCtrlConfig))? ((Std_ReturnType)E_OK) : ((Std_ReturnType)E_NOT_OK));
    
    if ((Std_ReturnType)E_OK == FunctionSuccess)
    {
#if (STD_ON == ETH_43_GMAC_GLOBAL_TIME_API)
        SysTimeConfig.SubSecondInc      = (uint8)(ClkCfg->TimeStampClockPeriodPs / 1000U);
        SysTimeConfig.SubNanoSecondsInc = (uint8)(((ClkCfg->TimeStampClockPeriodPs - ((uint32)SysTimeConfig.SubSecondInc * 1000U)) * 256U) / 1000U);
        SysTimeConfig.InitialTimestamp  = &InitialTimestamp;
        Gmac_Ip_InitSysTime(CtrlIdx, &SysTimeConfig);
#endif

        Gmac_Ip_EnableMDIO(CtrlIdx, FALSE, ClkCfg->ModuleClock);
    }
    
    return FunctionSuccess;
}

/*================================================================================================*/
/**
* @brief         Starts the controller
* @param[in]     CtrlIdx Index of controller which will be enabled
* @details       Function enables the controller after that it activates receive
*                and transmit buffer descriptors rings.
*/
Std_ReturnType Eth_43_GMAC_Ipw_EnableController(const uint8 CtrlIdx)
{
    Gmac_Ip_EnableController(CtrlIdx);

    return (Std_ReturnType)E_OK;
}

/*================================================================================================*/
/**
*//*!
* @brief         Safely disables the controller
* @param[in]     u8Ctrl Index of the controller to disable
* @details       Function disables the Ethernet controller and clears all
*                buffers to ensure safe start in the future i.e. no buffer is
*                retransmitted and all received frames are discarded - nothing
*                is received after the controller is disabled.
* @warning       Transmission which is in progress is terminated and frame
*                being transmitted is appended by bad CRC when the
*                Eth_43_GMAC_Ipw_DisableController function is called.
*/
Std_ReturnType Eth_43_GMAC_Ipw_DisableController(const uint8 CtrlIdx)
{
    return ((GMAC_STATUS_SUCCESS == Gmac_Ip_DisableController(CtrlIdx))? ((Std_ReturnType)E_OK) : ((Std_ReturnType)E_NOT_OK));
}

/*================================================================================================*/
/**
* @brief         Check whether the controller is running
* @details       Function checks the ECR[ETHER_EN] bit to determine whether
*                the controller has been stopped or whether it is running.
* @param[in]     CtrlIdx Index of controller which will be checked active status
* @return        The current controller mode.
* @retval        ETH_MODE_ACTIVE The controller is running.
* @retval        ETH_MODE_DOWN The controller is stopped.
*/
Eth_ModeType Eth_43_GMAC_Ipw_GetControllerMode(const uint8 CtrlIdx)
{
    return ((GMAC_PSTATE_ACTIVE == Gmac_Ip_GetPowerState(CtrlIdx))? (ETH_MODE_ACTIVE) : (ETH_MODE_DOWN));
}

/*================================================================================================*/
/**
* @brief         Returns the indexed controller's MAC address in network byte order.
* @param[in]     CtrlIdx Index of controller to get the PhysAddr
* @return        First four bytes of the MAC address.
*/
void Eth_43_GMAC_Ipw_GetPhysicalAddress  ( \
                const uint8 CtrlIdx, \
                uint8 *PhysAddrPtr \
                                 )
{
    Gmac_Ip_GetMacAddr(CtrlIdx, PhysAddrPtr);
}

/*================================================================================================*/
/**
* @brief         Update physical address of the controller.
* @param[in]     PhysAddrPtr Pointer to MAC address which should set to
*                controller. The address in network byte order stored into 6
*                bytes of memory.
* @param[in]     CtrlIdx Index of controller to set the PhysAddr
*/
void Eth_43_GMAC_Ipw_SetPhysicalAddress ( \
                    const uint8 CtrlIdx, \
                    const uint8 *PhysAddrPtr \
                                )
{
    Gmac_Ip_SetMacAddr(CtrlIdx, PhysAddrPtr);
}

/*================================================================================================*/
/**
* @brief         Finds empty Tx buffer and prepares it for loading with data
* @param[in]     CtrlIdx Index of controller to be borrowed buffer
* @param[out]    pBufIdx Granted buffer DA index
* @param[out]    Data Pointer to data area beginning is stored here (not data
*                area beginning but the pointer)
* @param[in/out] FrameLength Granted buffer length
* @return        The search status
* @retval        TRUE An empty buffer was found and granted.
* @retval        FALSE There is not empty buffer available at the moment.
*/
BufReq_ReturnType Eth_43_GMAC_Ipw_ProvideTxBuffer (  \
                                    const uint8 CtrlIdx, \
                                    const uint8 FifoIdx, \
                                    Eth_BufIdxType * const BufferIdx, \
                                    uint8 **FrameBuffer, \
                                    uint16 * const FrameLength \
                                          )
{
    Gmac_Ip_BufferType TxFrameBuffer;
    uint16 BufferIdxWithinFifo;
    Gmac_Ip_StatusType Status;
    BufReq_ReturnType BufReqStatus;

    /* Populate buffer information */
    TxFrameBuffer.Data   = NULL_PTR;
    TxFrameBuffer.Length = *FrameLength;

    /* Warning: Function "Gmac_Ip_GetTxBuff" is not reentrant */
    Status = Gmac_Ip_GetTxBuff(CtrlIdx, FifoIdx, &TxFrameBuffer, &BufferIdxWithinFifo);
    if (GMAC_STATUS_SUCCESS == Status)
    {
        *BufferIdx = Eth_43_GMAC_Ipw_axFirstTxBufferIdxInFifo[CtrlIdx][FifoIdx] + BufferIdxWithinFifo;

        /* In case internal buffers are enabled on all controllers, assign the data buffer address returned from the driver.*/
        #if (STD_OFF == ETH_43_GMAC_HAS_EXTERNAL_TX_BUFFERS)
            *FrameBuffer = TxFrameBuffer.Data;
        #else
                /* In case at least one controllers uses External Buffers, then check which one should update the address return from the driver. 
                For controllers which have the External Buffers option enabled the cast is done to avoid a compiler warning.*/
                if (Eth_43_GMAC_Ipw_InstHasExternalBufferManagement[CtrlIdx])
                {
                    (void)FrameBuffer;
                }
                else
                {
                    *FrameBuffer = TxFrameBuffer.Data;
                }
        #endif
    }

    /* Return available buffer length even in case of BUSY or OVERFLOW for both external and internal buffer usage */
    *FrameLength = TxFrameBuffer.Length;

    switch (Status)
    {
        case GMAC_STATUS_SUCCESS:
        {
            BufReqStatus = BUFREQ_OK;
            break;
        }

        case GMAC_STATUS_TX_BUFF_BUSY:
        {
            BufReqStatus = BUFREQ_E_BUSY;
            break;
        }

        case GMAC_STATUS_TX_BUFF_OVERFLOW:
        {
            BufReqStatus = BUFREQ_E_OVFL;
            break;
        }

        default:
        {
            BufReqStatus = BUFREQ_E_NOT_OK;
            break;
        }
    }
    
    return BufReqStatus;
}

#if (STD_ON == ETH_43_GMAC_SEND_MULTI_BUFFER_FRAME_API)
/*================================================================================================*/
/**
* @brief        Finds empty Tx buffer and prepares it for loading with data
* @param[in]    u8CtrlIdx    Index of controller
* @param[in]    u8FifoIdx    The fifo index
* @param[in]    NumBuffers   Number of buffers
* @param[in]    BufferLength The list of buffer lengths for all the chunks of the multi buffer frame
* @param[out]   pBufferIdx   The first descriptor index from which the multi buffer frame can be written
* @return       The search status
* @retval       BUFREQ_OK       There are enough buffers of the right size to be used
* @retval       BUFREQ_E_BUSY   There are not enough buffers 
* @retval       BUFREQ_E_OVFL   The buffers are not big enough for the frame
* @retval       BUFREQ_E_NOT_OK A buffer index could not be returned due to a different error
*/
BufReq_ReturnType Eth_43_GMAC_Ipw_ProvideTxMultiBuffer( const uint8 u8CtrlIdx, \
                                                                const uint8 u8FifoIdx, \
                                                                Eth_BufIdxType * const pBufferIdx, \
                                                                uint16 NumBuffers,
                                                                const uint16 BufferLength[] )
{
    uint16 u16BufferIdxWithinFifo = 0U;
    Gmac_Ip_StatusType status;
    BufReq_ReturnType bufReqStatus;

    status = Gmac_Ip_GetTxMultiBuff(u8CtrlIdx, u8FifoIdx, NumBuffers, BufferLength, &u16BufferIdxWithinFifo);
    if (GMAC_STATUS_SUCCESS == status)
    {
        /* Generate a unique buffer id */
        *pBufferIdx = Eth_43_GMAC_Ipw_axFirstTxBufferIdxInFifo[u8CtrlIdx][u8FifoIdx] + u16BufferIdxWithinFifo;
    }

    switch (status)
    {
        case GMAC_STATUS_SUCCESS:
        {
            bufReqStatus = BUFREQ_OK;
            break;
        }
        case GMAC_STATUS_TX_BUFF_BUSY:
        {
            bufReqStatus = BUFREQ_E_BUSY;
            break;
        }
        case GMAC_STATUS_TX_BUFF_OVERFLOW:
        {
            bufReqStatus = BUFREQ_E_OVFL;
            break;
        }
        default:
        {
            bufReqStatus = BUFREQ_E_NOT_OK;
            break;
        }
    }

    return bufReqStatus;
}
/*================================================================================================*/
/**
* @brief        Finds empty Tx buffer and prepares it for loading with data
* @param[in]    CtrlIdx    Index of controller
* @param[in]    u8FifoIdx    The fifo index
* @param[in]    NumBuffers   Number of buffers
* @param[in]    BufferData   The list of buffer data pointers that represent the frame
* @param[in]    BufferLength The list of buffer lengths for all the chunks of the multi buffer frame
* @return       The operation status
* @retval       BUFREQ_OK       There are enough buffers of the right size to be used and the frame
*                               was enqueued to be send
* @retval       BUFREQ_E_BUSY   There are not enough buffers 
* @retval       BUFREQ_E_OVFL   The buffers are not big enough for the frame
* @retval       BUFREQ_E_NOT_OK A buffer index could not be returned due to a different error
*/
BufReq_ReturnType Eth_43_GMAC_Ipw_SendMultiBufferFrame(uint8 CtrlIdx,
                                                               uint8 u8FifoIdx,
                                                               uint16 NumBuffers,
                                                               uint8* BufferData[],
                                                               uint16 BufferLength[])
{
    Gmac_Ip_StatusType status;
    BufReq_ReturnType bufReqStatus;
    Gmac_Ip_TxOptionsType TxOptions = {FALSE, GMAC_CRC_AND_PAD_INSERTION, GMAC_CHECKSUM_INSERTION_DISABLE};
    uint16 FrameIndex = 0;

    for (FrameIndex = 0U; FrameIndex < NumBuffers; FrameIndex++)
    {
        Eth_43_GMAC_Ipw_MultiBufferFrame[FrameIndex].Data = BufferData[FrameIndex];
        Eth_43_GMAC_Ipw_MultiBufferFrame[FrameIndex].Length = BufferLength[FrameIndex];
    }

    status = Gmac_Ip_SendMultiBufferFrame(CtrlIdx, u8FifoIdx, Eth_43_GMAC_Ipw_MultiBufferFrame, &TxOptions, NumBuffers);

    switch (status)
    {
        case GMAC_STATUS_SUCCESS:
        {
            bufReqStatus = BUFREQ_OK;
            break;
        }
        case GMAC_STATUS_TX_BUFF_BUSY:
        {
            bufReqStatus = BUFREQ_E_BUSY;
            break;
        }
        case GMAC_STATUS_TX_BUFF_OVERFLOW:
        {
            bufReqStatus = BUFREQ_E_OVFL;
            break;
        }
        default:
        {
            bufReqStatus = BUFREQ_E_NOT_OK;
            break;
        }
    }

    return bufReqStatus;
}
/*================================================================================================*/
/**
* @brief         Gets the next buffer by making sure it wraps around at the end of the ring
* @param[in]     CtrlIdx      Index of controller
* @param[in]     u8FifoIdx    The fifo index
* @param[in]     u16BufferIdx Current buffer index 
* @retval        The next buffer index
*/
uint16 Eth_43_GMAC_Ipw_GetNextBuffer(uint8 CtrlIdx, uint8 u8FifoIdx, uint16 u16BufferIdx)
{
    uint16 nextBufferIndex;

    nextBufferIndex = u16BufferIdx + 1U;
    if (nextBufferIndex >= (uint16)(Eth_43_GMAC_Ipw_axFirstTxBufferIdxInFifo[CtrlIdx][u8FifoIdx] + \
                            (Eth_43_GMAC_Ipw_apxInternalCfg[CtrlIdx]->Eth_43_GMAC_Ipw_pGmacCtrlConfig->Gmac_paCtrlTxRingConfig)[u8FifoIdx].RingSize))
    {
        nextBufferIndex = (uint16)Eth_43_GMAC_Ipw_axFirstTxBufferIdxInFifo[CtrlIdx][u8FifoIdx];
    }

    return nextBufferIndex;
}

#endif /* STD_ON == ETH_43_GMAC_SEND_MULTI_BUFFER_FRAME_API */

/*================================================================================================*/
/**
* @brief         Provide the data buffers for reception.
* @param[in]     CtrlIdx Index of controller which will be triggered the transmission
* @param[in]     FifoIdx Fifo Index of the fifo to be transmitted
* @param[in]     BufferData Pointer to start of the data buffers.
*/

void Eth_43_GMAC_Ipw_ProvideRxBuffer(uint8 CtrlIdx, uint8 FifoIdx, uint8 *BufferData)
{
    Gmac_Ip_BufferType BuffInfo;
#if (ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED > 1)
    uint16 Eth_Gmac_RxBufflen[2] = {GMAC_0_MAX_RXBUFFLEN_SUPPORTED, GMAC_1_MAX_RXBUFFLEN_SUPPORTED};
#else
    uint16 Eth_Gmac_RxBufflen[1] = {GMAC_0_MAX_RXBUFFLEN_SUPPORTED};
#endif
        BuffInfo.Length = Eth_Gmac_RxBufflen[CtrlIdx];
        BuffInfo.Data = BufferData;

    Gmac_Ip_SetRxExternalBuffer( CtrlIdx, FifoIdx, &BuffInfo);
}

/*================================================================================================*/
/**
* @brief         Triggers the transmission of the given buffer
* @param[in]     CtrlIdx Index of controller which will be triggered the transmission
* @param[in]     FifoIdx Fifo Index of the fifo to be transmitted
* @param[in]     Length Payload length
*                be confirmed or not
*/
Std_ReturnType Eth_43_GMAC_Ipw_Transmit ( \
                                const uint8 CtrlIdx, \
                                const uint8 FifoIdx,  \
                                uint8 *Buffer, \
                                const uint16 Length \
                                )
{
    /* This is only reentrant for different FIFOs, not for different buffer indexes */
    Gmac_Ip_BufferType TxFrameBuffer;
    Gmac_Ip_StatusType Status;
    Gmac_Ip_TxOptionsType TxOptions = {FALSE, GMAC_CRC_AND_PAD_INSERTION, GMAC_CHECKSUM_INSERTION_DISABLE};

    TxFrameBuffer.Data   = Buffer;
    TxFrameBuffer.Length = Length;

#if (STD_ON == ETH_43_GMAC_ENABLE_OFFLOAD_CRC)
    TxOptions.ChecksumIns = GMAC_CHECKSUM_INSERTION_PROTO_PSEUDOH;
    Status = Gmac_Ip_SendFrame(CtrlIdx, FifoIdx, &TxFrameBuffer, &TxOptions);
#else
    Status = Gmac_Ip_SendFrame(CtrlIdx, FifoIdx, &TxFrameBuffer, &TxOptions);
#endif

    return ((GMAC_STATUS_SUCCESS == Status)? ((Std_ReturnType)E_OK) : ((Std_ReturnType)E_NOT_OK));
}


#if STD_ON == ETH_43_GMAC_GET_COUNTER_API 
/*================================================================================================*/
/**
* @brief         Reads a list with drop counter values of the corresponding controller.
* @param[in]     CtrlIdx Index of controller within the context of the Ethernet Driver.
* @param[out]    CounterPtr Counter values according to IETF RFC 1757, RFC 1643 and RFC 2233.
* @details       Reads a list with drop counter values of the corresponding controller.
*                The meaning of these values is described at Eth_CounterType.
*/
Std_ReturnType Eth_43_GMAC_Ipw_GetCounterValues  ( \
                               uint8 CtrlIdx, \
                               Eth_CounterType *CounterPtr \
                                         )
{
    /* Maximal possible value shall denote an invalid value (e.g. counter not available) */
    /* Warning: All this fumbling on the call stack might have a negative impact on performance.
     *          Execution times shall be measured and compared. */

    CounterPtr->DropPktBufOverrun = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_RX_FIFO_OVERFLOW_PACKETS);
    CounterPtr->DropPktCrc        = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_RX_CRC_ERROR_PACKETS);
    CounterPtr->UndersizePkt      = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_RX_UNDERSIZE_PACKETS_GOOD);
    CounterPtr->OversizePkt       = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_RX_OVERSIZE_PACKETS_GOOD);
    CounterPtr->AlgnmtErr         = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_RX_ALIGNMENT_ERROR_PACKETS);
    CounterPtr->SqeTestErr        = (uint32)-1;
    CounterPtr->DiscInbdPkt       = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_RX_FIFO_OVERFLOW_PACKETS);
    CounterPtr->ErrInbdPkt        = (uint32)-1;
    CounterPtr->DiscOtbdPkt       = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_TX_UNDERFLOW_ERROR_PACKETS);
    CounterPtr->ErrOtbdPkt        = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_TX_PACKET_COUNT_GOOD_BAD);
    CounterPtr->ErrOtbdPkt       -= Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_TX_PACKET_COUNT_GOOD);                               
    CounterPtr->SnglCollPkt       = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_TX_SINGLE_COLLISION_GOOD_PACKETS);
    CounterPtr->MultCollPkt       = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_TX_MULTIPLE_COLLISION_GOOD_PACKETS);
    CounterPtr->DfrdPkt           = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_TX_DEFERRED_PACKETS);
    CounterPtr->LatCollPkt        = Gmac_Ip_GetCounter(CtrlIdx, GMAC_CTR_TX_LATE_COLLISION_PACKETS);
    CounterPtr->HwDepCtr0         = (uint32)-1;
    CounterPtr->HwDepCtr1         = (uint32)-1;
    CounterPtr->HwDepCtr2         = (uint32)-1;
    CounterPtr->HwDepCtr3         = (uint32)-1;

    return (Std_ReturnType)E_OK;
}
#endif

#if STD_ON == ETH_43_GMAC_MDIO_CLAUSE22_API
/*================================================================================================*/
/**
* @brief         Transfers management data over the MII
* @param[in]     CtrlIdx Index of controller to be transferred
* @param[in]     Trcv Transceiver to communicate with
* @param[in]     Reg Register which shall be accessed
* @param[in,out] Data Written data
* @return        Failure status
* @retval        TRUE Success, no error has occurred.
* @retval        FALSE Failure, no response from the hardware within a timeout.
*/
boolean Eth_43_GMAC_Ipw_WriteMii    ( \
                    const uint8 CtrlIdx, \
                    const uint8 Trcv, \
                    const uint8 Reg, \
                    const uint16 Data
                            )
{
    /* 1 millisecond is enough to transfer about 16 MDIO frames at an MDC frequency of 1MHz. */
    return ((GMAC_STATUS_SUCCESS == Gmac_Ip_MDIOWrite(CtrlIdx, Trcv, Reg, Data, ETH_43_GMAC_IPW_TIMEOUT_1MS_U16))? (TRUE) : (FALSE));
}

/*================================================================================================*/
/**
* @brief         Transfers management data over the MII
* @param[in]     CtrlIdx Index of controller to be transferred
* @param[in]     Trcv Transceiver to communicate with
* @param[in]     Reg Register which shall be accessed
* @param[in,out] Data Read data
* @return        Failure status
* @retval        TRUE Success, no error has occurred.
* @retval        FALSE Failure, no response from the hardware within a timeout.
*/
boolean Eth_43_GMAC_Ipw_ReadMii ( \
                        const uint8 CtrlIdx, \
                        const uint8 Trcv, \
                        const uint8 Reg, \
                        uint16 * const Data
                        )
{ 
    /* 1 millisecond is enough to transfer about 16 MDIO frames at an MDC frequency of 1MHz. */
    return ((GMAC_STATUS_SUCCESS == Gmac_Ip_MDIORead(CtrlIdx, Trcv, Reg, Data, ETH_43_GMAC_IPW_TIMEOUT_1MS_U16))? (TRUE) : (FALSE));
}
#endif

#if STD_ON == ETH_43_GMAC_MDIO_CLAUSE45_API
/*================================================================================================*/
/**
* @brief         Transfers management data over the MII
* @param[in]     CtrlIdx Index of controller to be transferred
* @param[in]     TrcvIdx Transceiver/Port to communicate with
* @param[in]     Mmd Device which shall be accessed
* @param[in]     RegAddress Register address which shall be accessed
* @param[in,out] RegValPtr Readed data from register
* @return        Failure status
* @retval        TRUE Success, no error has occurred.
* @retval        FALSE Failure, no response from the hardware within a timeout.
*/
boolean Eth_43_GMAC_Ipw_ReadMmd ( \
                             const uint8 CtrlIdx,\
                             const uint8 TrcvIdx, \
                             const uint8 Mmd, \
                             const uint16 RegAddress,\
                             uint16 * RegValPtr
                        )
{
    /* 1 millisecond is enough to transfer about 8 MMD frames at an MDC frequency of 1MHz. */
    return ((GMAC_STATUS_SUCCESS == Gmac_Ip_MDIOReadMMD(CtrlIdx, TrcvIdx, Mmd, RegAddress, RegValPtr, ETH_43_GMAC_IPW_TIMEOUT_1MS_U16))? (TRUE) : (FALSE));
}

/*================================================================================================*/
/**
* @brief         Transfers management data over the MII
* @param[in]     CtrlIdx Index of controller to be transferred
* @param[in]     TrcvIdx Transceiver/Port to communicate with
* @param[in]     Mmd Device which shall be accessed
* @param[in]     RegAddress Register address which shall be accessed
* @param[in,out] RegVal Data to be written to register
* @return        Failure status
* @retval        TRUE Success, no error has occurred.
* @retval        FALSE Failure, no response from the hardware within a timeout.
*/
boolean Eth_43_GMAC_Ipw_WriteMmd ( \
                              const uint8 CtrlIdx,\
                              const uint8 TrcvIdx, \
                              const uint8 Mmd, \
                              const uint16 RegAddress,\
                              const uint16 RegVal
                         )
{
    /* 1 millisecond is enough to transfer about 8 MMD frames at an MDC frequency of 1MHz. */
    return ((GMAC_STATUS_SUCCESS == Gmac_Ip_MDIOWriteMMD(CtrlIdx, TrcvIdx, Mmd, RegAddress, RegVal, ETH_43_GMAC_IPW_TIMEOUT_1MS_U16))? (TRUE) : (FALSE));
}
#endif

/*================================================================================================*/
/**
* @brief         Adds or removes the specified PhysAddr address to or from
*                a multicast address pool in the controller specified by CtrlIdx.
* @param[in]     CtrlIdx Index of controller to be transferred
* @param[in]     PhysAddr Pointer to PHY address which shall be added
*                or removed to or from multicast pool.
*                The address in network byte order stored into 6 bytes of
*                memory.
*/
#if STD_ON == ETH_43_GMAC_UPDATE_PHYS_ADDR_FILTER_API

Std_ReturnType Eth_43_GMAC_Ipw_UpdatePhysAddrFilter ( \
                                    uint8 CtrlIdx, \
                                    const uint8 *PhysAddr, \
                                    Eth_FilterActionType Action \
                                    )
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;
    
    if (Eth_43_GMAC_Ipw_Local_IsOpenFilterPattern(PhysAddr))
    {
        /* Completely opens the physical address filter. */
        if (ETH_ADD_TO_FILTER == Action)
        {
            Gmac_Ip_SetMulticastForwardAll(CtrlIdx, TRUE);
        }
        else    /* Don't allow pass all multicast addresses. Recover the filtering. */
        {
            Gmac_Ip_SetMulticastForwardAll(CtrlIdx, FALSE);
            Gmac_Ip_SetMulticastHashFilter(CtrlIdx, TRUE);
        }
        ReturnStatus = (Std_ReturnType)E_OK;
    }
    else if (Eth_43_GMAC_Ipw_Local_IsCloseFilterPattern(PhysAddr))
    {
        /* Completely closes the physical address filter. */
        if (ETH_ADD_TO_FILTER == Action)
        {
            Gmac_Ip_SetMulticastForwardAll(CtrlIdx, FALSE);
            /* This won't be sufficient if the perfect filters are populated with 
             * additional physical addresses besides the controller's address */
            Gmac_Ip_SetMulticastHashFilter(CtrlIdx, FALSE);
        }
        else /* Allow the multicast filtering by hash table. */
        {
            Gmac_Ip_SetMulticastHashFilter(CtrlIdx, TRUE);
        }
        ReturnStatus = (Std_ReturnType)E_OK;
    }
    else
    {
        if (Eth_43_GMAC_Ipw_Local_IsMulticastAddress(PhysAddr))
        {
            /* Adds a destination address to the physical address filter. */
            if (ETH_ADD_TO_FILTER == Action)
            {
                Gmac_Ip_SetMulticastForwardAll(CtrlIdx, FALSE);
                Gmac_Ip_SetMulticastHashFilter(CtrlIdx, TRUE);
                Gmac_Ip_AddDstAddrToHashFilter(CtrlIdx, PhysAddr);
                ReturnStatus = (Std_ReturnType)E_OK;
            }
            else  /* Removes a destination address from the physical address filter. */
            {
                Gmac_Ip_SetMulticastForwardAll(CtrlIdx, FALSE);
                Gmac_Ip_SetMulticastHashFilter(CtrlIdx, TRUE);
                Gmac_Ip_RemoveDstAddrFromHashFilter(CtrlIdx, PhysAddr);
                ReturnStatus = (Std_ReturnType)E_OK;
            }
        }
    }
    
    return ReturnStatus;
}
#endif

/*================================================================================================*/
/**
* @brief         Releases Tx resources after a frame is transmitted and calls upper layer Tx confirmation
* @param[in]     EthControllerConfig pointer to get information of controller to be transferred
* @param[in]     FifoIdx Fifo Index in use for the current transmission.
*/
void Eth_43_GMAC_Ipw_ReportTransmission(
                                const Eth_43_GMAC_CtrlCfgType *EthControllerConfig, \
                                const uint8 FifoIdx \
                           )
{
    Eth_43_GMAC_axTxBufferIdxMapType *Iter;
    Eth_BufIdxType BufIdx;
    Std_ReturnType TxResult;
    Gmac_Ip_BufferType TxFrameBuffer;
    Gmac_Ip_StatusType GmacStatus;
    boolean FrameHasError;
    uint8 CtrlIdx;
    uint8 EthCtrlEthIfIdx;

    CtrlIdx = EthControllerConfig->EthCtrlIdx;
    EthCtrlEthIfIdx = EthControllerConfig->EthCtrlEthIfIdx;

    if (FifoIdx < ETH_43_GMAC_MAX_TXFIFO_SUPPORTED)
    {
        /*Get the pointer to the first frame*/
        Iter = Eth_43_GMAC_axTransmissionRequests[CtrlIdx][FifoIdx].pQueueHead;
    
        /* Check all buffers previously queued for transmission */
        while ((Iter != NULL_PTR))
        {
            /*Get the current frame data buffer to double check that the current data buffer in queue is the 
              same as the hardware buffer descriptor indicates*/
            TxFrameBuffer.Data   = Iter->pu8BufferData;
            /* Checks if the transmission of a Buffer is completed and release resources in this case.*/
            GmacStatus = Gmac_Ip_GetTransmitStatus(CtrlIdx, FifoIdx, &TxFrameBuffer, &Eth_43_GMAC_Ipw_axTxFrameInfo[CtrlIdx][FifoIdx]);

            if (GMAC_STATUS_SUCCESS == GmacStatus)
            {
                /*If the frame was successfully transmitted call the TxConfirmation in case this option is enabled for it*/
                if (Iter->bTxConfirmation)
                {
                    BufIdx   = (Eth_BufIdxType)((sint32)(Iter - Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx]));
                    FrameHasError = ((0U == Eth_43_GMAC_Ipw_axTxFrameInfo[CtrlIdx][FifoIdx].ErrMask)? ((boolean)FALSE) : ((boolean)TRUE));
                    TxResult = ((FALSE == FrameHasError)? ((Std_ReturnType)E_OK) : ((Std_ReturnType)E_NOT_OK));

                    EthIf_TxConfirmation(EthCtrlEthIfIdx, BufIdx, TxResult);
                }
            
                /* If the frame was successfully transmitted, clear buffer allocation and dequeue transmission request */
                Iter->pu8BufferData = NULL_PTR;
                Eth_43_GMAC_axTransmissionRequests[CtrlIdx][FifoIdx].pQueueHead = Iter->pNextBuffer;
                Iter = Iter->pNextBuffer;
            }
            /*In case of returning GMAC_STATUS_BUSY, the hardware buffer descriptor is still in use, therefore the transmission is not completely done*/
            else
            {
                break;
            }
        }
    }
}

#define ETH_43_GMAC_STOP_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
