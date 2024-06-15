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
#include "Eth_43_GMAC.h"
#include "Eth_43_GMAC_Internal.h"
#include "Eth_43_GMAC_Ipw.h"

#include "EthIf_Cbk.h"

#include "Det.h"
#if (STD_ON == ETH_43_GMAC_DEM_EVENT_DETECT)
#include "Dem.h"
#endif

#include "SchM_Eth_43_GMAC.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_43_GMAC_VENDOR_ID_C                      43
#define ETH_43_GMAC_AR_RELEASE_MAJOR_VERSION_C       4
#define ETH_43_GMAC_AR_RELEASE_MINOR_VERSION_C       7
#define ETH_43_GMAC_AR_RELEASE_REVISION_VERSION_C    0
#define ETH_43_GMAC_SW_MAJOR_VERSION_C               3
#define ETH_43_GMAC_SW_MINOR_VERSION_C               0
#define ETH_43_GMAC_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Eth_43_GMAC.h */
#if (ETH_43_GMAC_VENDOR_ID_C != ETH_43_GMAC_VENDOR_ID)
    #error "Eth_43_GMAC.c and Eth_43_GMAC.h have different vendor ids"
#endif
#if ((ETH_43_GMAC_AR_RELEASE_MAJOR_VERSION_C    != ETH_43_GMAC_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_43_GMAC_AR_RELEASE_MINOR_VERSION_C    != ETH_43_GMAC_AR_RELEASE_MINOR_VERSION) || \
     (ETH_43_GMAC_AR_RELEASE_REVISION_VERSION_C != ETH_43_GMAC_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Eth_43_GMAC.c and Eth_43_GMAC.h are different"
#endif
#if ((ETH_43_GMAC_SW_MAJOR_VERSION_C != ETH_43_GMAC_SW_MAJOR_VERSION) || \
     (ETH_43_GMAC_SW_MINOR_VERSION_C != ETH_43_GMAC_SW_MINOR_VERSION) || \
     (ETH_43_GMAC_SW_PATCH_VERSION_C != ETH_43_GMAC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eth_43_GMAC.c and Eth_43_GMAC.h are different"
#endif

/* Checks against Eth_43_GMAC_Internal.h */
#if (ETH_43_GMAC_VENDOR_ID_C != ETH_43_GMAC_INTERNAL_VENDOR_ID)
    #error "Eth_43_GMAC.c and Eth_43_GMAC_Internal.h have different vendor ids"
#endif
#if ((ETH_43_GMAC_AR_RELEASE_MAJOR_VERSION_C    != ETH_43_GMAC_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_43_GMAC_AR_RELEASE_MINOR_VERSION_C    != ETH_43_GMAC_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
     (ETH_43_GMAC_AR_RELEASE_REVISION_VERSION_C != ETH_43_GMAC_INTERNAL_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Eth_43_GMAC.c and Eth_43_GMAC_Internal.h are different"
#endif
#if ((ETH_43_GMAC_SW_MAJOR_VERSION_C != ETH_43_GMAC_INTERNAL_SW_MAJOR_VERSION) || \
     (ETH_43_GMAC_SW_MINOR_VERSION_C != ETH_43_GMAC_INTERNAL_SW_MINOR_VERSION) || \
     (ETH_43_GMAC_SW_PATCH_VERSION_C != ETH_43_GMAC_INTERNAL_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eth_43_GMAC.c and Eth_43_GMAC_Internal.h are different"
#endif

/* Checks against Eth_43_GMAC_Ipw.h */
#if (ETH_43_GMAC_VENDOR_ID_C != ETH_43_GMAC_IPW_VENDOR_ID)
    #error "Eth_43_GMAC.c and Eth_43_GMAC_Ipw.h have different vendor ids"
#endif
#if ((ETH_43_GMAC_AR_RELEASE_MAJOR_VERSION_C    != ETH_43_GMAC_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_43_GMAC_AR_RELEASE_MINOR_VERSION_C    != ETH_43_GMAC_IPW_AR_RELEASE_MINOR_VERSION) || \
     (ETH_43_GMAC_AR_RELEASE_REVISION_VERSION_C != ETH_43_GMAC_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Eth_43_GMAC.c and Eth_43_GMAC_Ipw.h are different"
#endif
#if ((ETH_43_GMAC_SW_MAJOR_VERSION_C != ETH_43_GMAC_IPW_SW_MAJOR_VERSION) || \
     (ETH_43_GMAC_SW_MINOR_VERSION_C != ETH_43_GMAC_IPW_SW_MINOR_VERSION) || \
     (ETH_43_GMAC_SW_PATCH_VERSION_C != ETH_43_GMAC_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eth_43_GMAC.c and Eth_43_GMAC_Ipw.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against EthIf_Cbk.h */
    #if ((ETH_43_GMAC_AR_RELEASE_MAJOR_VERSION_C != ETHIF_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_43_GMAC_AR_RELEASE_MINOR_VERSION_C != ETHIF_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Eth_43_GMAC.c and EthIf_Cbk.h are different"
    #endif

    /* Checks against Det.h */
    #if ((ETH_43_GMAC_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_43_GMAC_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Eth_43_GMAC.c and Det.h are different"
    #endif
#if (STD_ON == ETH_43_GMAC_DEM_EVENT_DETECT)
    /* Checks against Dem.h */
    #if ((ETH_43_GMAC_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_43_GMAC_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Eth_43_GMAC.c and Dem.h are different"
    #endif
#endif

    /* Checks against SchM_Eth.h */
    #if ((ETH_43_GMAC_AR_RELEASE_MAJOR_VERSION_C != SCHM_ETH_43_GMAC_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_43_GMAC_AR_RELEASE_MINOR_VERSION_C != SCHM_ETH_43_GMAC_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Eth_43_GMAC.c and SchM_Eth_43_GMAC.h are different"
    #endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define ETH_43_GMAC_FRAME_MACDST_OFFSET     (0U)
#define ETH_43_GMAC_FRAME_MACSRC_OFFSET     (6U)
#define ETH_43_GMAC_FRAME_ETHTYPE_OFFSET    (12U)
#define ETH_43_GMAC_FRAME_PAYLOAD_OFFSET    (14U)

#define ETH_43_GMAC_FRAME_MACDST_LENGTH     (6U)
#define ETH_43_GMAC_FRAME_MACSRC_LENGTH     (6U)
#define ETH_43_GMAC_FRAME_ETHTYPE_LENGTH    (2U)   
#define ETH_43_GMAC_FRAME_HEADER_LENGTH     (ETH_43_GMAC_FRAME_MACDST_LENGTH + ETH_43_GMAC_FRAME_MACSRC_LENGTH + ETH_43_GMAC_FRAME_ETHTYPE_LENGTH)

#define ETH_43_GMAC_BUFFER_INDEX_UNUSED     (0U)


#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
    /* Little Endian - Convert to network order (Big Endian) */
    #define Eth_43_GMAC_Local_Macro_Htons(u16Value)       (((((uint16)(u16Value) & 0xFFU)) << 8U) | (((uint16)(u16Value) & 0xFF00U) >> 8U))
#else
    /* Big Endian - Already in network order - Nothing to be done */
    #define Eth_43_GMAC_Local_Macro_Htons(u16Value)       ((u16Value))
#endif


#if STD_ON == ETH_43_GMAC_MULTICORE_SUPPORT
    #define Eth_43_GMAC_GetCoreID()        (OsIf_GetCoreID())
#else
    #define Eth_43_GMAC_GetCoreID()        (0U)
#endif

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ETH_43_GMAC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"


/**
* @brief          Pointers to the configuration structures.
* @details        Used to store the configuration pointers for later use.
*/
static const Eth_43_GMAC_ConfigType *Eth_43_GMAC_apxInternalCfg[ETH_43_GMAC_MAX_COREIDX_SUPPORTED];

/**
* @brief         Map between buffer indices and transmission-specific information.
* @details       Used to realize the map function f(BufIdx) = (FifoIdx, Buffer, TxConfirmation)
*/
Eth_43_GMAC_axTxBufferIdxMapType Eth_43_GMAC_axTxBufferIdxMap[ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED][ETH_43_GMAC_MAX_TXFIFO_SUPPORTED * ETH_43_GMAC_MAX_TXBUFF_SUPPORTED];

/**
* @brief         Queues of transmission requests for each Tx FIFO
* @details       Keeps track of the transmission requests enqueued by "Eth_43_GMAC_Transmit".
*/
Eth_43_GMAC_QueueInfo Eth_43_GMAC_axTransmissionRequests[ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED][ETH_43_GMAC_MAX_TXFIFO_SUPPORTED];

/**
 * @brief        Last queue tail updated in the transmission requests
 * @details      Keeps track of the last queue tail updated in the "Eth_43_GMAC_axTransmissionRequests"
 *               in its state before the update.
*/
Eth_43_GMAC_axTxBufferIdxMapType *Eth_43_GMAC_pLastTransmissionRequestQueueTail;
/**
* @brief         Mode of the ETH controllers
* @details       Stores the last known mode of the ETH controller.
*                Used in "Eth_43_GMAC_MainFunction" to track mode changes and report them back to EthIf.
*                Only "Eth_43_GMAC_SetControllerMode" can trigger mode changes.
*/
static Eth_ModeType Eth_43_GMAC_axCtrlMode[ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED];

#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
/**
* @brief         State of the ETH controllers
* @details       Used to store state of the Ethernet controller driver i.e Eth
*                module. It is initialized to ETH_STATE_UNINIT
*/
static Eth_StateType Eth_43_GMAC_axCtrlState[ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED];
#endif

#define ETH_43_GMAC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
#if (ETH_43_GMAC_PRECOMPILE_SUPPORT == STD_ON)

#define ETH_43_GMAC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"


#if STD_ON == ETH_43_GMAC_MULTICORE_SUPPORT
    extern const Eth_43_GMAC_ConfigType * const Eth_43_GMAC_apxPredefinedConfig[ETH_43_GMAC_MAX_COREIDX_SUPPORTED];
#else
    extern const Eth_43_GMAC_ConfigType Eth_43_GMAC_xPredefinedConfig;
#endif


#define ETH_43_GMAC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"

#endif /* #if (ETH_43_GMAC_PRECOMPILE_SUPPORT == STD_ON) */

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ETH_43_GMAC_START_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"

static inline boolean Eth_43_GMAC_Local_IsBroadcastFrame(const uint8 *PhyAddr);
static inline void Eth_43_GMAC_Local_Memcpy(uint8 *Dst, const uint8 *Src, uint8 BytesNum);
#if (STD_ON == ETH_43_GMAC_DEM_EVENT_DETECT)
static void Eth_43_GMAC_Local_CheckDemStatus( \
                            const uint8 CtrlIdx, \
                            const uint32 DemConfig, \
                            const Eth_43_GMAC_DemErrorIdType DemErrorId, \
                            const Dem_EventIdType DemId
                            );
#endif
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
static Std_ReturnType Eth_43_GMAC_Local_CheckEthHLDEntry( \
                               uint32 CoreId, \
                               const uint8 CtrlIdx, \
                               uint8 EthServiceID \
                                );
#endif
static void Eth_43_GMAC_Local_InitController( \
                                const uint8 CtrlIdx, \
                                const Eth_43_GMAC_CtrlCfgType *Eth_43_GMAC_Controller \
                                );
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
static inline boolean Eth_43_GMAC_Local_IsBroadcastFrame(const uint8 *PhyAddr)
{
    return ((PhyAddr[0U] == 0xFFU) && (PhyAddr[1U] == 0xFFU) && (PhyAddr[2U] == 0xFFU) && (PhyAddr[3U] == 0xFFU) && (PhyAddr[4U] == 0xFFU) && (PhyAddr[5U] == 0xFFU));
}

static inline void Eth_43_GMAC_Local_Memcpy(uint8 *Dst, const uint8 *Src, uint8 BytesNum)
{
    uint8 TempVar = BytesNum;
    
    /* Start copy data*/
    while (TempVar > 0U)
    {
        TempVar--;
        Dst[TempVar] = Src[TempVar];
    }
}
#if (STD_ON == ETH_43_GMAC_DEM_EVENT_DETECT)
static void Eth_43_GMAC_Local_CheckDemStatus( \
                            const uint8 CtrlIdx, \
                            const uint32 DemConfig, \
                            const Eth_43_GMAC_DemErrorIdType DemErrorId, \
                            const Dem_EventIdType DemId
                            )
{
    /* Check Dem event ON or OFF */
    if ((uint32)STD_ON == DemConfig)
    {
        if (Eth_43_GMAC_Ipw_ErrorDetected(CtrlIdx, DemErrorId))
        {
            (void)Dem_SetEventStatus(DemId, DEM_EVENT_STATUS_PREFAILED);
        }
        else
        {
            (void)Dem_SetEventStatus(DemId, DEM_EVENT_STATUS_PREPASSED);
        }
    }        
}
#endif
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
static Std_ReturnType Eth_43_GMAC_Local_CheckEthHLDEntry( \
                                           uint32 CoreId, \
                                           const uint8 CtrlIdx, \
                                           uint8 EthServiceID \
                                            )
{
    Std_ReturnType CheckStatus = (Std_ReturnType)E_OK;
    
  #if STD_ON == ETH_43_GMAC_MULTICORE_SUPPORT
    if ((CoreId >= ETH_43_GMAC_MAX_COREIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]))
  #else
    if (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId])
  #endif
    {
        CheckStatus = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, EthServiceID, ETH_43_GMAC_E_UNINIT);
        
    }
    else if ((CtrlIdx >= ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx]))
    {
        CheckStatus = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, EthServiceID, ETH_43_GMAC_E_INV_CTRL_IDX);
    }
    else if (ETH_STATE_INIT != Eth_43_GMAC_axCtrlState[CtrlIdx])
    {
        CheckStatus = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, EthServiceID, ETH_43_GMAC_E_UNINIT);
    }
    else
    {
        /* Prevent misra */
    }
    
    return CheckStatus;
} 
#endif

static void Eth_43_GMAC_Local_InitController( \
                                    const uint8 CtrlIdx, \
                                    const Eth_43_GMAC_CtrlCfgType *Eth_43_GMAC_Controller \
                                    )
{
    if (NULL_PTR != Eth_43_GMAC_Controller) 
    {
    #if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
        Eth_43_GMAC_axCtrlState[CtrlIdx] = ETH_STATE_UNINIT;
    #endif
        Eth_43_GMAC_axCtrlMode[CtrlIdx]  = ETH_MODE_DOWN;

        /*  Check whether the controller is available */
        if (TRUE == Eth_43_GMAC_Ipw_CheckAccessToController(CtrlIdx))
        {
            if ((Std_ReturnType)E_OK == Eth_43_GMAC_Ipw_ConfigureController(CtrlIdx, Eth_43_GMAC_Controller->Eth_43_GMAC_pIpwCtrlConfig, Eth_43_GMAC_Controller->Eth_43_GMAC_pClockConfig))
            {
                #if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
                    Eth_43_GMAC_axCtrlState[CtrlIdx] = ETH_STATE_INIT; 
                #endif
                
                #if(STD_ON == ETH_43_GMAC_DEM_EVENT_DETECT)
                    if((uint32)STD_ON == (uint32)(Eth_43_GMAC_Controller->Eth_43_GMAC_DemEventsList.ETH_E_ACCESS_Cfg.state))
                    {
                        (void)Dem_SetEventStatus((Dem_EventIdType)(Eth_43_GMAC_Controller->Eth_43_GMAC_DemEventsList.ETH_E_ACCESS_Cfg.id), DEM_EVENT_STATUS_PREPASSED);
                    }
                #endif
            }
       
        }
        else
        {
        #if(STD_ON == ETH_43_GMAC_DEM_EVENT_DETECT)
            if((uint32)STD_ON == (uint32)(Eth_43_GMAC_Controller->Eth_43_GMAC_DemEventsList.ETH_E_ACCESS_Cfg.state))
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)(Eth_43_GMAC_Controller->Eth_43_GMAC_DemEventsList.ETH_E_ACCESS_Cfg.id), DEM_EVENT_STATUS_PREFAILED);
            }
        #endif
        }
    }
}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
void Eth_43_GMAC_Init(const Eth_43_GMAC_ConfigType *CfgPtr)
{
    const Eth_43_GMAC_CtrlCfgType *Eth_43_GMAC_Controller;
    uint32 CoreId = Eth_43_GMAC_GetCoreID();
    uint8 CtrlIdx;

#if (STD_OFF == ETH_43_GMAC_PRECOMPILE_SUPPORT)
  #if (STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT)
    if (NULL_PTR == CfgPtr)
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_INIT, ETH_43_GMAC_E_INIT_FAILED);
    }
    #if (STD_ON == ETH_43_GMAC_MULTICORE_SUPPORT)
    else if (CoreId != CfgPtr->PartitionCoreId)
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_INIT, ETH_43_GMAC_E_PARAM_CONFIG);
    }
    #endif
    else
    {
  #endif
        Eth_43_GMAC_apxInternalCfg[CoreId] = CfgPtr;
#else /* ETH_43_GMAC_PRECOMPILE_SUPPORT == STD_ON */
  #if (STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT)
    if (NULL_PTR != CfgPtr)
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_INIT, ETH_43_GMAC_E_INIT_FAILED);
    }
    #if (STD_ON == ETH_43_GMAC_MULTICORE_SUPPORT)
    else if ((NULL_PTR == Eth_43_GMAC_apxPredefinedConfig[CoreId]) || (CoreId != Eth_43_GMAC_apxPredefinedConfig[CoreId]->PartitionCoreId))
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_INIT, ETH_43_GMAC_E_PARAM_CONFIG);
    }
    #endif
    else
    {
  #endif
      #if (STD_ON == ETH_43_GMAC_MULTICORE_SUPPORT)
        Eth_43_GMAC_apxInternalCfg[CoreId] = Eth_43_GMAC_apxPredefinedConfig[CoreId];
      #else
        Eth_43_GMAC_apxInternalCfg[CoreId] = &Eth_43_GMAC_xPredefinedConfig;
      #endif
        (void)CfgPtr;
#endif /* (STD_ON != ETH_43_GMAC_PRECOMPILE_SUPPORT) */

        for (CtrlIdx = 0U; CtrlIdx < ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED; ++CtrlIdx)
        { 
            Eth_43_GMAC_Controller = Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx];
            
            Eth_43_GMAC_Local_InitController(CtrlIdx, Eth_43_GMAC_Controller);

        }
        #ifdef MCAL_ENABLE_FAULT_INJECTION
            MCAL_FAULT_INJECTION_POINT(ETH_43_GMAC_CHANGE_STATE_FIP_1);
        #endif
#if (STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT)
    }
#endif
}

/*================================================================================================*/
Std_ReturnType Eth_43_GMAC_SetControllerMode(uint8 CtrlIdx, Eth_ModeType CtrlMode)
{
    Eth_43_GMAC_axTxBufferIdxMapType *Iter;
    Std_ReturnType FunctionSuccess = (Std_ReturnType)E_NOT_OK;
    const Eth_43_GMAC_CtrlCfgType *Eth_43_GMAC_Controller;
    uint32 CoreId = Eth_43_GMAC_GetCoreID();
    uint8 FifoIdx;

#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    if ((Std_ReturnType)E_OK == Eth_43_GMAC_Local_CheckEthHLDEntry(CoreId, CtrlIdx, ETH_43_GMAC_SID_SETCONTROLLERMODE))
    {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
        Eth_43_GMAC_Controller = Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx];

        /*  Check whether the controller is available */
        if(TRUE == Eth_43_GMAC_Ipw_CheckAccessToController(CtrlIdx))
        {
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
            if( (ETH_MODE_ACTIVE == CtrlMode) || (ETH_MODE_DOWN == CtrlMode)  )
            {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */ 
                if(ETH_MODE_ACTIVE == CtrlMode)
                {
                    FunctionSuccess = Eth_43_GMAC_Ipw_EnableController(CtrlIdx);
                }
                else
                {
                    /* Clear pending transmission requests */
                    for (FifoIdx = 0U; FifoIdx < Eth_43_GMAC_Controller->Eth_43_GMAC_pEgressConfig->FifoCount; ++FifoIdx)
                    {
                        for (Iter = Eth_43_GMAC_axTransmissionRequests[CtrlIdx][FifoIdx].pQueueHead; Iter != NULL_PTR; Iter = Iter->pNextBuffer)
                        {
                            /* Clear buffer allocation */
                            Iter->pu8BufferData = NULL_PTR;
                        }

                        /* Mark queue as empty */
                        Eth_43_GMAC_axTransmissionRequests[CtrlIdx][FifoIdx].pQueueHead = NULL_PTR;
                    }
                    
                    FunctionSuccess = Eth_43_GMAC_Ipw_DisableController(CtrlIdx);
                }

                /* Yes, the controller is available, report as passed */
                #if(STD_ON == ETH_43_GMAC_DEM_EVENT_DETECT)
                if((uint32)STD_ON == (uint32)(Eth_43_GMAC_Controller->Eth_43_GMAC_DemEventsList.ETH_E_ACCESS_Cfg.state))
                {
                
                    (void)Dem_SetEventStatus((Dem_EventIdType)(Eth_43_GMAC_Controller->Eth_43_GMAC_DemEventsList.ETH_E_ACCESS_Cfg.id), DEM_EVENT_STATUS_PREPASSED);
                }
                #endif
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
            }
            else
            {
                (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_SETCONTROLLERMODE, ETH_43_GMAC_E_INV_MODE);
            }          
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */  
        }
        else
        {
            /* No, the controller is not available, report an error */
            #if(STD_ON == ETH_43_GMAC_DEM_EVENT_DETECT)
            if((uint32)STD_ON == (uint32)(Eth_43_GMAC_Controller->Eth_43_GMAC_DemEventsList.ETH_E_ACCESS_Cfg.state))
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)(Eth_43_GMAC_Controller->Eth_43_GMAC_DemEventsList.ETH_E_ACCESS_Cfg.id), DEM_EVENT_STATUS_PREFAILED);
            }
            #endif
        }
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */

    return FunctionSuccess;
}

/*================================================================================================*/
Std_ReturnType Eth_43_GMAC_GetControllerMode( \
                            uint8 CtrlIdx, \
                            Eth_ModeType *CtrlModePtr \
                                    )
{
    Std_ReturnType FunctionSuccess = (Std_ReturnType)E_NOT_OK;

#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    uint32 CoreId = Eth_43_GMAC_GetCoreID();

#if STD_ON == ETH_43_GMAC_MULTICORE_SUPPORT
    if ((CoreId >= ETH_43_GMAC_MAX_COREIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]))
#else
    if (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId])
#endif
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETCONTROLLERMODE, ETH_43_GMAC_E_UNINIT);
    }
    else if ((CtrlIdx >= ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx]))
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETCONTROLLERMODE, ETH_43_GMAC_E_INV_CTRL_IDX);
    }
    else if (NULL_PTR == CtrlModePtr)
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETCONTROLLERMODE, ETH_43_GMAC_E_PARAM_POINTER);
    }
    else if (ETH_STATE_INIT != Eth_43_GMAC_axCtrlState[CtrlIdx])
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETCONTROLLERMODE, ETH_43_GMAC_E_UNINIT);
    }
    else
    {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
        *CtrlModePtr = Eth_43_GMAC_Ipw_GetControllerMode(CtrlIdx);
        FunctionSuccess = (Std_ReturnType)E_OK;             
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */

    return FunctionSuccess;
}
  
/*================================================================================================*/
void Eth_43_GMAC_GetPhysAddr(uint8 CtrlIdx, uint8 *PhysAddrPtr)
{
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    uint32 CoreId = Eth_43_GMAC_GetCoreID();

  #if (STD_ON == ETH_43_GMAC_MULTICORE_SUPPORT)
    if ((CoreId >= ETH_43_GMAC_MAX_COREIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]))
  #else
    if (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId])
  #endif
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETPHYSADDR, ETH_43_GMAC_E_UNINIT);
    }
    else if ((CtrlIdx >= ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx]))
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETPHYSADDR, ETH_43_GMAC_E_INV_CTRL_IDX);
    }
    else if (NULL_PTR == PhysAddrPtr)
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETPHYSADDR, ETH_43_GMAC_E_PARAM_POINTER);

    }
    else if (ETH_STATE_INIT != Eth_43_GMAC_axCtrlState[CtrlIdx])
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETPHYSADDR, ETH_43_GMAC_E_UNINIT);
    }
    else
    {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
        Eth_43_GMAC_Ipw_GetPhysicalAddress(CtrlIdx, PhysAddrPtr);
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
}

/*================================================================================================*/
void Eth_43_GMAC_SetPhysAddr(uint8 CtrlIdx, const uint8 *PhysAddrPtr)
{   
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    uint32 CoreId = Eth_43_GMAC_GetCoreID();

  #if (STD_ON == ETH_43_GMAC_MULTICORE_SUPPORT)
    if ((CoreId >= ETH_43_GMAC_MAX_COREIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]))
  #else
    if (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId])
  #endif
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_SETPHYSADDR, ETH_43_GMAC_E_UNINIT);
    }
    else if ((CtrlIdx >= ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx]))
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_SETPHYSADDR, ETH_43_GMAC_E_INV_CTRL_IDX);
    }
    else if (NULL_PTR == PhysAddrPtr)
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_SETPHYSADDR, ETH_43_GMAC_E_PARAM_POINTER);

    }
    else if (ETH_STATE_INIT != Eth_43_GMAC_axCtrlState[CtrlIdx])
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_SETPHYSADDR, ETH_43_GMAC_E_UNINIT);
    }
    else
    {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
        Eth_43_GMAC_Ipw_SetPhysicalAddress(CtrlIdx, PhysAddrPtr);               
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
}


#if STD_ON == ETH_43_GMAC_UPDATE_PHYS_ADDR_FILTER_API
/*================================================================================================*/
Std_ReturnType Eth_43_GMAC_UpdatePhysAddrFilter ( \
                                uint8 CtrlIdx, \
                                const uint8 *PhysAddrPtr, \
                                Eth_FilterActionType Action \
                                        )
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;

#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    uint32 CoreId = Eth_43_GMAC_GetCoreID();

  #if (STD_ON == ETH_43_GMAC_MULTICORE_SUPPORT)
    if ((CoreId >= ETH_43_GMAC_MAX_COREIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]))
  #else
    if (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId])
  #endif
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_UPDATEADDRFILTER, ETH_43_GMAC_E_UNINIT);
    }
    else if ((CtrlIdx >= ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx]))
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_UPDATEADDRFILTER, ETH_43_GMAC_E_INV_CTRL_IDX);
    }
    else if (NULL_PTR == PhysAddrPtr)
    {           
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_UPDATEADDRFILTER, ETH_43_GMAC_E_PARAM_POINTER);

    }
    else if (ETH_STATE_INIT != Eth_43_GMAC_axCtrlState[CtrlIdx])
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_UPDATEADDRFILTER, ETH_43_GMAC_E_UNINIT);
    }
    else
    {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */

        ReturnStatus = Eth_43_GMAC_Ipw_UpdatePhysAddrFilter(CtrlIdx, PhysAddrPtr, Action);
       
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */

    return ReturnStatus;
}

#endif /* STD_ON == ETH_43_GMAC_UPDATE_PHYS_ADDR_FILTER_API */


#if STD_ON == ETH_43_GMAC_MDIO_CLAUSE22_API
/*================================================================================================*/
Std_ReturnType Eth_43_GMAC_WriteMii ( \
                               uint8 CtrlIdx, \
                               uint8 TrcvIdx, \
                               uint8 RegIdx, \
                               uint16 RegVal \
                            )
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;
    const Eth_43_GMAC_CtrlCfgType *Eth_43_GMAC_Controller;
    uint32 CoreId = Eth_43_GMAC_GetCoreID();

#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
  #if (STD_ON == ETH_43_GMAC_MULTICORE_SUPPORT)
    if ((CoreId >= ETH_43_GMAC_MAX_COREIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]))
  #else
    if (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId])
  #endif
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_WRITEMII, ETH_43_GMAC_E_UNINIT);
    }
    else if ((CtrlIdx >= ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx]))
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_WRITEMII, ETH_43_GMAC_E_INV_CTRL_IDX);
    }
    else if (ETH_STATE_INIT != Eth_43_GMAC_axCtrlState[CtrlIdx])
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_WRITEMII, ETH_43_GMAC_E_UNINIT);
    }
    else
    {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */

        if ((boolean)TRUE == Eth_43_GMAC_Ipw_WriteMii(CtrlIdx, TrcvIdx, RegIdx, RegVal))
        {
            Eth_43_GMAC_Controller = Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx];
            Eth_43_GMAC_Controller->Eth_43_GMAC_EthTrcvDriverFunctionList.writeMiiIndicationFunction(CtrlIdx, TrcvIdx, RegIdx);
            ReturnStatus = (Std_ReturnType)E_OK;
        }
        else
        {
            (void)Det_ReportRuntimeError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_WRITEMII, ETH_43_GMAC_E_COMMUNICATION);
        }
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */

    return ReturnStatus;
}

/*================================================================================================*/
Std_ReturnType Eth_43_GMAC_ReadMii  ( \
                            uint8 CtrlIdx, \
                            uint8 TrcvIdx, \
                            uint8 RegIdx, \
                            uint16 *RegValPtr \
                            )
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;
    const Eth_43_GMAC_CtrlCfgType *Eth_43_GMAC_Controller;
    uint32 CoreId = Eth_43_GMAC_GetCoreID();

#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    if ((Std_ReturnType)E_OK == Eth_43_GMAC_Local_CheckEthHLDEntry(CoreId, CtrlIdx, ETH_43_GMAC_SID_READMII))
    {
        if (NULL_PTR == RegValPtr)
        {
            (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_READMII, ETH_43_GMAC_E_PARAM_POINTER);
        }
        else
        {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
            if ((boolean)TRUE == Eth_43_GMAC_Ipw_ReadMii(CtrlIdx, TrcvIdx, RegIdx, RegValPtr))
            {
                Eth_43_GMAC_Controller = Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx];
                Eth_43_GMAC_Controller->Eth_43_GMAC_EthTrcvDriverFunctionList.readMiiIndicationFunction(CtrlIdx, TrcvIdx, RegIdx, *RegValPtr);
                ReturnStatus = (Std_ReturnType)E_OK;
            }
            else
            {
                (void)Det_ReportRuntimeError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_READMII, ETH_43_GMAC_E_COMMUNICATION);
            }
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
        }
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */

    return ReturnStatus;
}
#endif /* ETH_43_GMAC_MDIO_CLAUSE22_API */

/*================================================================================================*/
#if STD_ON == ETH_43_GMAC_MDIO_CLAUSE45_API
Std_ReturnType Eth_43_GMAC_ReadMmd ( \
                              uint8 CtrlIdx,\
                              uint8 TrcvIdx, \
                              uint8 Mmd, \
                              uint16 RegAddress,\
                              uint16 *RegValPtr
                           )
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;

#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT   
    uint32 CoreId = Eth_43_GMAC_GetCoreID();

  #if (STD_ON == ETH_43_GMAC_MULTICORE_SUPPORT)
    if ((CoreId >= ETH_43_GMAC_MAX_COREIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]))
  #else
    if (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId])
  #endif
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_READMMD, ETH_43_GMAC_E_UNINIT);
    }
    else if ((CtrlIdx >= ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx]))
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_READMMD, ETH_43_GMAC_E_INV_CTRL_IDX);
    }
    else if (ETH_STATE_INIT != Eth_43_GMAC_axCtrlState[CtrlIdx])
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_READMMD, ETH_43_GMAC_E_UNINIT);
    }
    else if (NULL_PTR == RegValPtr)
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_READMMD, ETH_43_GMAC_E_PARAM_POINTER);
    }    
    else
    {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
        if ((boolean)TRUE == Eth_43_GMAC_Ipw_ReadMmd(CtrlIdx, TrcvIdx, Mmd, RegAddress, RegValPtr))
        {
            ReturnStatus = E_OK;
        }
        else
        {
            (void)Det_ReportRuntimeError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_READMMD, ETH_43_GMAC_E_COMMUNICATION);
        }
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */  

    return ReturnStatus;
}

/*================================================================================================*/
Std_ReturnType Eth_43_GMAC_WriteMmd ( \
                                uint8 CtrlIdx,\
                                uint8 TrcvIdx, \
                                uint8 Mmd, \
                                uint16 RegAddress,\
                                uint16 RegVal
                            )
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;
    
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT    
    uint32 CoreId = Eth_43_GMAC_GetCoreID();

  #if (STD_ON == ETH_43_GMAC_MULTICORE_SUPPORT)
    if ((CoreId >= ETH_43_GMAC_MAX_COREIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]))
  #else
    if (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId])
  #endif
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_WRITEMMD, ETH_43_GMAC_E_UNINIT);
    }
    else if ((CtrlIdx >= ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx]))
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_WRITEMMD, ETH_43_GMAC_E_INV_CTRL_IDX);
    }
    else if (ETH_STATE_INIT != Eth_43_GMAC_axCtrlState[CtrlIdx])
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_WRITEMMD, ETH_43_GMAC_E_UNINIT);
    }
    else
    {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
        if ((boolean)TRUE == Eth_43_GMAC_Ipw_WriteMmd(CtrlIdx, TrcvIdx, Mmd, RegAddress, RegVal))
        {   
            ReturnStatus = E_OK;
        }
        else
        {
            (void)Det_ReportRuntimeError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_WRITEMMD, ETH_43_GMAC_E_COMMUNICATION);
        }
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */  

    return ReturnStatus;
}
#endif /* ETH_43_GMAC_MDIO_CLAUSE45_API */

#if STD_ON == ETH_43_GMAC_GET_COUNTER_API
/*================================================================================================*/
Std_ReturnType Eth_43_GMAC_GetCounterValues ( \
                                        uint8 CtrlIdx, \
                                        Eth_CounterType *CounterPtr \
                                    )
{
    Std_ReturnType ReturnStatus = (Std_ReturnType) E_NOT_OK;
 
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    uint32 CoreId = Eth_43_GMAC_GetCoreID();

  #if (STD_ON == ETH_43_GMAC_MULTICORE_SUPPORT)
    if ((CoreId >= ETH_43_GMAC_MAX_COREIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]))
  #else
    if (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId])
  #endif
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETCOUNTERVALUE, ETH_43_GMAC_E_UNINIT);
    }
    else if ((CtrlIdx >= ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx]))
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETCOUNTERVALUE, ETH_43_GMAC_E_INV_CTRL_IDX);
    }
    else if (ETH_STATE_INIT != Eth_43_GMAC_axCtrlState[CtrlIdx])
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETCOUNTERVALUE, ETH_43_GMAC_E_UNINIT);
    }
    else if (NULL_PTR == CounterPtr)
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETCOUNTERVALUE, ETH_43_GMAC_E_PARAM_POINTER);
    }
    else
    {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
        ReturnStatus = Eth_43_GMAC_Ipw_GetCounterValues(CtrlIdx, CounterPtr);
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */

    return ReturnStatus;
}
#endif /* ETH_43_GMAC_GET_COUNTER_API */

#if STD_ON == ETH_43_GMAC_GET_RXSTATS_API
/*================================================================================================*/
Std_ReturnType Eth_43_GMAC_GetRxStats ( \
                                uint8 CtrlIdx, \
                                Eth_RxStatsType *RxStats \
                              )
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;
 
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    uint32 CoreId = Eth_43_GMAC_GetCoreID();

  #if (STD_ON == ETH_43_GMAC_MULTICORE_SUPPORT)
    if ((CoreId >= ETH_43_GMAC_MAX_COREIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]))
  #else
    if (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId])
  #endif
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETRXSTATS, ETH_43_GMAC_E_UNINIT);
    }
    else if ((CtrlIdx >= ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx]))
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETRXSTATS, ETH_43_GMAC_E_INV_CTRL_IDX);
    }
    else if (ETH_STATE_INIT != Eth_43_GMAC_axCtrlState[CtrlIdx])
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETRXSTATS, ETH_43_GMAC_E_UNINIT);
    }
    else if(NULL_PTR == RxStats)
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETRXSTATS, ETH_43_GMAC_E_PARAM_POINTER);
    }
    else
    {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
        ReturnStatus = Eth_43_GMAC_Ipw_GetRxStats(CtrlIdx, RxStats);
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */

    return ReturnStatus;
}
#endif /*ETH_43_GMAC_GET_RXSTATS_API*/

#if STD_ON == ETH_43_GMAC_GET_TXSTATS_API
/*================================================================================================*/
Std_ReturnType Eth_43_GMAC_GetTxStats ( \
                                uint8 CtrlIdx, \
                                Eth_TxStatsType *TxStats \
                              )
{
    Std_ReturnType ReturnStatus = (Std_ReturnType) E_NOT_OK;

#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    uint32 CoreId = Eth_43_GMAC_GetCoreID();

  #if (STD_ON == ETH_43_GMAC_MULTICORE_SUPPORT)
    if ((CoreId >= ETH_43_GMAC_MAX_COREIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]))
  #else
    if (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId])
  #endif
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETTXSTATS, ETH_43_GMAC_E_UNINIT);
    }
    else if ((CtrlIdx >= ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx]))
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETTXSTATS, ETH_43_GMAC_E_INV_CTRL_IDX);
    }
    else if (ETH_STATE_INIT != Eth_43_GMAC_axCtrlState[CtrlIdx])
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETTXSTATS, ETH_43_GMAC_E_UNINIT);
    }
    else if(NULL_PTR == TxStats)
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETTXSTATS, ETH_43_GMAC_E_PARAM_POINTER);
    }
    else
    {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
        ReturnStatus = Eth_43_GMAC_Ipw_GetTxStats(CtrlIdx, TxStats);
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */

    return ReturnStatus;
}
#endif /*ETH_43_GMAC_GET_TXSTATS_API*/

#if STD_ON == ETH_43_GMAC_GET_TXERROR_COUNTER_API
/*================================================================================================*/
Std_ReturnType Eth_43_GMAC_GetTxErrorCounterValues ( \
                                uint8 CtrlIdx, \
                                Eth_TxErrorCounterValuesType *TxErrorCounterValues \
                                           )
{
    Std_ReturnType ReturnStatus = (Std_ReturnType) E_NOT_OK;

#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    uint32 CoreId = Eth_43_GMAC_GetCoreID();

  #if (STD_ON == ETH_43_GMAC_MULTICORE_SUPPORT)
    if ((CoreId >= ETH_43_GMAC_MAX_COREIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]))
  #else
    if (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId])
  #endif
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETTXERRORCOUNTERVALUE, ETH_43_GMAC_E_UNINIT);
    }
    else if ((CtrlIdx >= ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx]))
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETTXERRORCOUNTERVALUE, ETH_43_GMAC_E_INV_CTRL_IDX);
    }
    else if (ETH_STATE_INIT != Eth_43_GMAC_axCtrlState[CtrlIdx])
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETTXERRORCOUNTERVALUE, ETH_43_GMAC_E_UNINIT);
    }
    else if (NULL_PTR == TxErrorCounterValues)
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETTXERRORCOUNTERVALUE, ETH_43_GMAC_E_PARAM_POINTER);
    }
    else
    {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
        ReturnStatus = Eth_43_GMAC_Ipw_GetTxErrorCounterValues(CtrlIdx, TxErrorCounterValues);
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */

    return ReturnStatus;
}
#endif /*ETH_43_GMAC_GET_TXERROR_COUNTER_API*/

#if STD_ON == ETH_43_GMAC_GLOBAL_TIME_API
/*================================================================================================*/
Std_ReturnType Eth_43_GMAC_SetGlobalTime ( \
                    uint8 CtrlIdx, \
                    const Eth_TimeStampType * TimeStampPtr \
                        )
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;
    const Eth_43_GMAC_CtrlCfgType *Eth_43_GMAC_Controller;
    uint32 CoreId = Eth_43_GMAC_GetCoreID();
    
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
  #if (STD_ON == ETH_43_GMAC_MULTICORE_SUPPORT)
    if ((CoreId >= ETH_43_GMAC_MAX_COREIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]))
  #else
    if (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId])
  #endif
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_SETGLOBALTIME, ETH_43_GMAC_E_UNINIT);
    }
    else if ((CtrlIdx >= ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx]))
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_SETGLOBALTIME, ETH_43_GMAC_E_INV_CTRL_IDX);
    }
    else if (ETH_STATE_INIT != Eth_43_GMAC_axCtrlState[CtrlIdx])
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_SETGLOBALTIME, ETH_43_GMAC_E_UNINIT);
    }
    else if (NULL_PTR == TimeStampPtr)
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_SETGLOBALTIME, ETH_43_GMAC_E_PARAM_POINTER);
    }
    else
    {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */ 
        Eth_43_GMAC_Controller = Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx];
        
        Eth_43_GMAC_Ipw_SetGlobalTime(CtrlIdx, Eth_43_GMAC_Controller->Eth_43_GMAC_pClockConfig, TimeStampPtr);
        ReturnStatus = (Std_ReturnType)E_OK;
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
    
    return ReturnStatus;
}
/*================================================================================================*/
Std_ReturnType Eth_43_GMAC_SetCorrectionTime ( \
                            uint8 CtrlIdx, \
                            const Eth_TimeIntDiffType *TimeOffsetPtr, \
                            const Eth_RateRatioType *RateRatioPtr \
                                )
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;
    const Eth_43_GMAC_CtrlCfgType *Eth_43_GMAC_Controller;
    uint32 CoreId = Eth_43_GMAC_GetCoreID();
    
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
  #if (STD_ON == ETH_43_GMAC_MULTICORE_SUPPORT)
    if ((CoreId >= ETH_43_GMAC_MAX_COREIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]))
  #else
    if (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId])
  #endif
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_SETCORRECTIONTIME, ETH_43_GMAC_E_UNINIT);
    }
    else if ((CtrlIdx >= ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx]))
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_SETCORRECTIONTIME, ETH_43_GMAC_E_INV_CTRL_IDX);
    }
    else if (ETH_STATE_INIT != Eth_43_GMAC_axCtrlState[CtrlIdx])
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_SETCORRECTIONTIME, ETH_43_GMAC_E_UNINIT);
    }
    else if ((NULL_PTR == TimeOffsetPtr) || (NULL_PTR == RateRatioPtr))
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_SETCORRECTIONTIME, ETH_43_GMAC_E_PARAM_POINTER);
    }
    else
    {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
        Eth_43_GMAC_Controller = Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx];

        ReturnStatus = Eth_43_GMAC_Ipw_SetCorrectionTime(CtrlIdx, Eth_43_GMAC_Controller->Eth_43_GMAC_pClockConfig, TimeOffsetPtr, RateRatioPtr);
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */

    return ReturnStatus;
}

/*================================================================================================*/
Std_ReturnType Eth_43_GMAC_GetCurrentTime  ( \
                                uint8 CtrlIdx, \
                                Eth_TimeStampQualType *TimeQualPtr, \
                                Eth_TimeStampType *TimeStampPtr \
                                   )
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;
    
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    uint32 CoreId = Eth_43_GMAC_GetCoreID();

  #if (STD_ON == ETH_43_GMAC_MULTICORE_SUPPORT)
    if ((CoreId >= ETH_43_GMAC_MAX_COREIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]))
  #else
    if (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId])
  #endif
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETCURRENTTIME, ETH_43_GMAC_E_UNINIT);
    }
    else if ((CtrlIdx >= ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx]))
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETCURRENTTIME, ETH_43_GMAC_E_INV_CTRL_IDX);
    }
    else if (ETH_STATE_INIT != Eth_43_GMAC_axCtrlState[CtrlIdx])
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETCURRENTTIME, ETH_43_GMAC_E_UNINIT);
    }
    else if ((NULL_PTR == TimeQualPtr) || (NULL_PTR == TimeStampPtr))
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETCURRENTTIME, ETH_43_GMAC_E_PARAM_POINTER);
    }
    else
    {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */

        *TimeQualPtr = ETH_UNCERTAIN;
        ReturnStatus = Eth_43_GMAC_Ipw_GetCurrentTime(CtrlIdx, TimeQualPtr, TimeStampPtr);
        
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */

    return ReturnStatus;
}

/*================================================================================================*/
void Eth_43_GMAC_EnableEgressTimeStamp  ( \
                                uint8 CtrlIdx, \
                                Eth_BufIdxType BufIdx \
                                )
{
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    uint32 CoreId = Eth_43_GMAC_GetCoreID();
    
  #if (STD_ON == ETH_43_GMAC_MULTICORE_SUPPORT)
    if ((CoreId >= ETH_43_GMAC_MAX_COREIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]))
  #else
    if (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId])
  #endif
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_ENABLEEGRESSTIMESTAMP, ETH_43_GMAC_E_UNINIT);
    }
    else if ((CtrlIdx >= ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx]))
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_ENABLEEGRESSTIMESTAMP, ETH_43_GMAC_E_INV_CTRL_IDX);
    }
    else if (ETH_STATE_INIT != Eth_43_GMAC_axCtrlState[CtrlIdx])
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_ENABLEEGRESSTIMESTAMP, ETH_43_GMAC_E_UNINIT);
    }
    else
    {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */    
        Eth_43_GMAC_Ipw_EnableEgressTimeStamp(CtrlIdx, BufIdx);
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
}

/*================================================================================================*/
Std_ReturnType Eth_43_GMAC_GetEgressTimeStamp ( \
                                uint8 CtrlIdx, \
                                Eth_BufIdxType BufIdx, \
                                Eth_TimeStampQualType *TimeQualPtr, \
                                Eth_TimeStampType *TimeStampPtr \
                                      )
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;
    uint8 FifoIdx;
    
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    uint32 CoreId = Eth_43_GMAC_GetCoreID();
    
    if ((Std_ReturnType)E_OK == Eth_43_GMAC_Local_CheckEthHLDEntry(CoreId, CtrlIdx, ETH_43_GMAC_SID_GETEGRESSTIMESTAMP))
    {
        if ((NULL_PTR == TimeQualPtr) || (NULL_PTR == TimeStampPtr))
        {
            (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETEGRESSTIMESTAMP, ETH_43_GMAC_E_PARAM_POINTER);
        }
        else
        {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */      
            *TimeQualPtr = ETH_UNCERTAIN;
            FifoIdx    = Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][BufIdx].FifoIdx;
            Eth_43_GMAC_Ipw_GetEgressTimeStamp(CtrlIdx, FifoIdx, TimeQualPtr, TimeStampPtr);

            if (ETH_VALID == *TimeQualPtr)
            {
                ReturnStatus = (Std_ReturnType)E_OK;
            }
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
        }
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */

    return ReturnStatus;

}

/*================================================================================================*/
Std_ReturnType Eth_43_GMAC_GetIngressTimeStamp ( \
                                uint8 CtrlIdx, \
                                const Eth_DataType *DataPtr, \
                                Eth_TimeStampQualType* TimeQualPtr, \
                                Eth_TimeStampType* TimeStampPtr \
                                       )

{
    const Eth_43_GMAC_CtrlCfgType *Eth_43_GMAC_Controller = NULL_PTR;
    const uint8 *FrameData;
    uint8 FifoIdx;
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;
    uint32 CoreId = Eth_43_GMAC_GetCoreID();
    
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    if ((Std_ReturnType)E_OK == Eth_43_GMAC_Local_CheckEthHLDEntry(CoreId, CtrlIdx, ETH_43_GMAC_SID_GETINGRESSTIMESTAMP))
    {
        if ((NULL_PTR == DataPtr) || (NULL_PTR == TimeQualPtr) || (NULL_PTR == TimeStampPtr))
        {
            (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETINGRESSTIMESTAMP, ETH_43_GMAC_E_PARAM_POINTER);
        }
        else
        {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
            /* First perform conversion from Eth_DataType to uint8 */
            FrameData = (const uint8 *)DataPtr;
            /* Move the pointer back to the position of the frame header (note the index sign) */
            FrameData = (const uint8 *)(FrameData - (const uint8 *)ETH_43_GMAC_FRAME_PAYLOAD_OFFSET);
            
            Eth_43_GMAC_Controller = Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx];
            
            *TimeQualPtr = ETH_UNCERTAIN;
            
            for ( \
                 FifoIdx = 0U; \
                 (FifoIdx < Eth_43_GMAC_Controller->Eth_43_GMAC_pIngressConfig->FifoCount) && (*TimeQualPtr == ETH_UNCERTAIN); \
                 ++FifoIdx \
                )
            {
                Eth_43_GMAC_Ipw_GetIngressTimeStamp(CtrlIdx, FifoIdx, FrameData, TimeQualPtr, TimeStampPtr);
            }

            if (ETH_VALID == *TimeQualPtr)
            {
                ReturnStatus = (Std_ReturnType)E_OK;
            }
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
        }
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */

    return ReturnStatus;
}
#endif /* ETH_43_GMAC_GLOBAL_TIME_API */

/*================================================================================================*/
BufReq_ReturnType Eth_43_GMAC_ProvideTxBuffer( \
                            uint8 CtrlIdx, \
                            uint8 Priority, \
                            Eth_BufIdxType *BufIdxPtr, \
                            uint8 **BufPtr, \
                            uint16 *LenBytePtr \
                                     )
{
    BufReq_ReturnType FunctionSuccess = BUFREQ_E_NOT_OK;
    const Eth_43_GMAC_CtrlCfgType *Eth_43_GMAC_Controller = NULL_PTR;
    uint32 CoreId = Eth_43_GMAC_GetCoreID();
    uint8 FifoIdx;

    uint8 *FrameBuffer;
    uint16 FrameLength;

#if (STD_ON == ETH_43_GMAC_SWT_MANAGEMENT_SUPPORT_API)
    uint8 *DataMgmt;
    uint16 ManagementInfoLength;
    uint16 DummyLength;
#endif

#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    if ((Std_ReturnType)E_OK == Eth_43_GMAC_Local_CheckEthHLDEntry(CoreId, CtrlIdx, ETH_43_GMAC_SID_PROVIDETXBUFFER))
    {
        if ((NULL_PTR == BufIdxPtr) || (NULL_PTR == BufPtr) || (NULL_PTR == LenBytePtr))
        {
            (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_PROVIDETXBUFFER, ETH_43_GMAC_E_PARAM_POINTER);
        }
        else
        {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
    /* Check value of variable which pointed by LenBytePtr before using it to add */
    if (*LenBytePtr > (65535U - ETH_43_GMAC_FRAME_HEADER_LENGTH))
    {
        FunctionSuccess = BUFREQ_E_OVFL;
    }
    else
    {
            Eth_43_GMAC_Controller = Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx];

            /* Convert VLAN PCP to Tx FIFO index */
            FifoIdx = Eth_43_GMAC_Controller->Eth_43_GMAC_pEgressConfig->VlanPcpToFifoIdx[Priority];

        #if (STD_ON == ETH_43_GMAC_SWT_MANAGEMENT_SUPPORT_API)
            ManagementInfoLength = *LenBytePtr;
            Eth_43_GMAC_Controller->Eth_43_GMAC_EthSwtDriverFunctionList.TxAdaptBufferLengthFunction(LenBytePtr);
            ManagementInfoLength = *LenBytePtr - ManagementInfoLength;
        #endif

            /* Request the desired length */
            FrameLength     = *LenBytePtr + ETH_43_GMAC_FRAME_HEADER_LENGTH;
            /* Warning: Function "Eth_43_GMAC_Ipw_ProvideTxBuffer" is not reentrant */
            FunctionSuccess   = Eth_43_GMAC_Ipw_ProvideTxBuffer(CtrlIdx, FifoIdx, BufIdxPtr, &FrameBuffer, &FrameLength);
            /* Report back the granted length */
            *LenBytePtr = FrameLength - ETH_43_GMAC_FRAME_HEADER_LENGTH;

            if (BUFREQ_OK == FunctionSuccess)
            {
                Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][*BufIdxPtr].FifoIdx     = FifoIdx;
                Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][*BufIdxPtr].pu8BufferData = FrameBuffer;

            #if (STD_ON == ETH_43_GMAC_SWT_MANAGEMENT_SUPPORT_API)
                DataMgmt    = &FrameBuffer[ETH_43_GMAC_FRAME_ETHTYPE_OFFSET];
                DummyLength = *LenBytePtr - ManagementInfoLength;
                (void) Eth_43_GMAC_Controller->Eth_43_GMAC_EthSwtDriverFunctionList.TxPrepareFrameFunction(CtrlIdx, *BufIdxPtr, &DataMgmt, &DummyLength);
                *BufPtr = &DataMgmt[ETH_43_GMAC_FRAME_ETHTYPE_LENGTH];
            #else
                *BufPtr = &FrameBuffer[ETH_43_GMAC_FRAME_PAYLOAD_OFFSET];
            #endif
            }
    }
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
        }
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */

    return FunctionSuccess;
}

#if (STD_ON == ETH_43_GMAC_HAS_EXTERNAL_RX_BUFFERS)

/*================================================================================================*/
void Eth_43_GMAC_ProvideRxBuffer(uint8 CtrlIdx, uint8 FifoIdx, uint8* BufferDataAddress)
{
    uint32 CoreId = Eth_43_GMAC_GetCoreID();

#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    if ((Std_ReturnType)E_OK == Eth_43_GMAC_Local_CheckEthHLDEntry(CoreId, CtrlIdx, ETH_43_GMAC_SID_PROVIDERXBUFFER))
    {
        if (NULL_PTR == BufferDataAddress)
        {
            (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_PROVIDERXBUFFER, ETH_43_GMAC_E_PARAM_POINTER);
        }
        else
        {
#endif /* ETH_DEV_ERROR_DETECT  */
            Eth_43_GMAC_Ipw_ProvideRxBuffer(CtrlIdx, FifoIdx, BufferDataAddress);
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
        }
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
}
#endif

#if (STD_ON == ETH_43_GMAC_HAS_EXTERNAL_TX_BUFFERS)

/*================================================================================================*/
BufReq_ReturnType Eth_43_GMAC_SendFrame (\
                                uint8   CtrlIdx,\
                                uint8   Priority,\
                                uint8*  BufferData,\
                                uint16* BufferLength,\
                                boolean TxConfirmation\
                                )
{
    uint8 FifoIdx = 0U;
    const Eth_43_GMAC_CtrlCfgType *Eth_Controller = NULL_PTR;
    BufReq_ReturnType FunctionStatus = BUFREQ_E_NOT_OK;
    Std_ReturnType ReturnValue = E_NOT_OK;
    uint32 CoreId = Eth_43_GMAC_GetCoreID();
    Eth_BufIdxType BuffIdx = 0U;
    Eth_Controller = Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx];

#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    if ((Std_ReturnType)E_OK == Eth_43_GMAC_Local_CheckEthHLDEntry(CoreId, CtrlIdx, ETH_43_GMAC_SID_SENDFRAME))
    {
        if (ETH_MODE_ACTIVE != Eth_43_GMAC_Ipw_GetControllerMode(CtrlIdx))
        {
            (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_SENDFRAME, ETH_43_GMAC_E_INV_MODE);
        }
        else if (NULL_PTR == BufferData)
        {
            (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_SENDFRAME, ETH_43_GMAC_E_PARAM_POINTER);
        }
        else if (NULL_PTR == BufferLength)
        {
            (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_SENDFRAME, ETH_43_GMAC_E_PARAM_POINTER);
        }
        else
        {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
            /* Convert VLAN PCP to Tx FIFO index */
            FifoIdx = Eth_Controller->Eth_43_GMAC_pEgressConfig->VlanPcpToFifoIdx[Priority];

            /* Request an available Buffer Descriptor*/
            FunctionStatus   = Eth_43_GMAC_Ipw_ProvideTxBuffer(CtrlIdx, FifoIdx,  &BuffIdx, NULL_PTR, BufferLength);

            if (BUFREQ_OK == FunctionStatus)
            {
                Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][BuffIdx].FifoIdx     = FifoIdx;
                Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][BuffIdx].pu8BufferData = BufferData;
                /* Configure Tx confirmation status */
                Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][BuffIdx].bTxConfirmation = TxConfirmation;

                /* Enqueue transmission request in the given Tx FIFO */
                Eth_43_GMAC_pLastTransmissionRequestQueueTail = Eth_43_GMAC_axTransmissionRequests[CtrlIdx][FifoIdx].pQueueTail;
                if (NULL_PTR == Eth_43_GMAC_axTransmissionRequests[CtrlIdx][FifoIdx].pQueueHead)
                {
                    Eth_43_GMAC_axTransmissionRequests[CtrlIdx][FifoIdx].pQueueHead = &Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][BuffIdx];
                    Eth_43_GMAC_axTransmissionRequests[CtrlIdx][FifoIdx].pQueueTail = &Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][BuffIdx];
                }
                else
                {
                    Eth_43_GMAC_axTransmissionRequests[CtrlIdx][FifoIdx].pQueueTail->pNextBuffer = &Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][BuffIdx];
                    Eth_43_GMAC_axTransmissionRequests[CtrlIdx][FifoIdx].pQueueTail = &Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][BuffIdx];
                }

                Eth_43_GMAC_axTransmissionRequests[CtrlIdx][FifoIdx].pQueueTail->pNextBuffer = NULL_PTR;

                /* Trigger the tranmission */
                ReturnValue = Eth_43_GMAC_Ipw_Transmit(CtrlIdx, FifoIdx, BufferData, *BufferLength);

                FunctionStatus  = (ReturnValue == E_OK) ? BUFREQ_OK : BUFREQ_E_BUSY;

            }
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
        }
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */

    return FunctionStatus; 
}
#endif

#if (STD_ON == ETH_43_GMAC_SEND_MULTI_BUFFER_FRAME_API)
/*================================================================================================*/
BufReq_ReturnType Eth_43_GMAC_SendMultiBufferFrame(uint8 CtrlIdx,
                                                uint8 Priority,
                                                uint16 NumBuffers,
                                                uint8* BufferData[],
                                                uint16 BufferLength[],
                                                boolean TxConfirmation)
{
    BufReq_ReturnType FunctionStatus = BUFREQ_E_NOT_OK;
    const Eth_43_GMAC_CtrlCfgType *Eth_Controller = NULL_PTR;
    uint8 FifoIdx = 0U;
    uint32 CoreId = Eth_43_GMAC_GetCoreID();
    Eth_Controller = Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx];
    Eth_BufIdxType BuffIdx = 0U;
    uint16 FrameIndex = 0U;
    Std_ReturnType ReturnValue = E_NOT_OK;

#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    if ((Std_ReturnType)E_OK == Eth_43_GMAC_Local_CheckEthHLDEntry(CoreId, CtrlIdx, ETH_43_GMAC_SID_SENDMULTIBUFFERFRAME))
    {
        if (ETH_MODE_ACTIVE != Eth_43_GMAC_Ipw_GetControllerMode(CtrlIdx))
        {
            (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_SENDMULTIBUFFERFRAME, ETH_43_GMAC_E_INV_MODE);
        }
        else
        {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */

            /* Convert VLAN PCP to Tx FIFO index */
            FifoIdx = Eth_Controller->Eth_43_GMAC_pEgressConfig->VlanPcpToFifoIdx[Priority];

            /* Request an available Buffer Descriptor*/
            FunctionStatus   = Eth_43_GMAC_Ipw_ProvideTxMultiBuffer(CtrlIdx, FifoIdx,  &BuffIdx, NumBuffers, BufferLength);

            if (BUFREQ_OK == FunctionStatus)
            {
                while (FrameIndex < NumBuffers)
                {
                    Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][BuffIdx].FifoIdx     = FifoIdx;
                    Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][BuffIdx].pu8BufferData = BufferData[FrameIndex];
                    /* Configure Tx confirmation status */
                    if (0U == FrameIndex)
                    {
                        Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][BuffIdx].bTxConfirmation = TxConfirmation;
                    }
                    else
                    {
                        Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][BuffIdx].bTxConfirmation = FALSE;
                    }

                    /* Enqueue transmission request in the given Tx FIFO */
                    if (NULL_PTR == Eth_43_GMAC_axTransmissionRequests[CtrlIdx][FifoIdx].pQueueHead)
                    {
                        Eth_43_GMAC_axTransmissionRequests[CtrlIdx][FifoIdx].pQueueHead = &Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][BuffIdx];
                        Eth_43_GMAC_axTransmissionRequests[CtrlIdx][FifoIdx].pQueueTail = &Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][BuffIdx];
                    }
                    else
                    {
                        Eth_43_GMAC_axTransmissionRequests[CtrlIdx][FifoIdx].pQueueTail->pNextBuffer = &Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][BuffIdx];
                        Eth_43_GMAC_axTransmissionRequests[CtrlIdx][FifoIdx].pQueueTail = &Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][BuffIdx];
                    }

                    Eth_43_GMAC_axTransmissionRequests[CtrlIdx][FifoIdx].pQueueTail->pNextBuffer = NULL_PTR;

                    /* need to wrap around */
                    BuffIdx = Eth_43_GMAC_Ipw_GetNextBuffer(CtrlIdx, FifoIdx, BuffIdx);
                    FrameIndex++;
                }


                /* Trigger the tranmission */
                ReturnValue = Eth_43_GMAC_Ipw_SendMultiBufferFrame(CtrlIdx, FifoIdx, NumBuffers, BufferData, BufferLength);

                FunctionStatus  = (ReturnValue == E_OK) ? BUFREQ_OK : BUFREQ_E_BUSY;
            }

#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
        }
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
    return FunctionStatus; 
}
#endif

/*================================================================================================*/
Std_ReturnType Eth_43_GMAC_TxTimeAwareShaperInit(uint8 CtrlIdx)
{
    const Eth_43_GMAC_CtrlCfgType *Eth_43_GMAC_Controller;
    uint32 CoreId = Eth_43_GMAC_GetCoreID();
    Std_ReturnType FunctionSuccess = (Std_ReturnType)E_NOT_OK;
    
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
  #if (STD_ON == ETH_43_GMAC_MULTICORE_SUPPORT)
    if ((CoreId >= ETH_43_GMAC_MAX_COREIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]))
  #else
    if (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId])
  #endif
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_TXTIMEAWARESHAPER, ETH_43_GMAC_E_UNINIT);
    }
    else if ((CtrlIdx >= ETH_43_GMAC_MAX_CTRLIDX_SUPPORTED) || (NULL_PTR == Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx]))
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_TXTIMEAWARESHAPER, ETH_43_GMAC_E_INV_CTRL_IDX);
    }
    else if (ETH_STATE_INIT != Eth_43_GMAC_axCtrlState[CtrlIdx])
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_TXTIMEAWARESHAPER, ETH_43_GMAC_E_UNINIT);
    }
    else
    {
#endif
        Eth_43_GMAC_Controller = Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx];
        FunctionSuccess = Eth_43_GMAC_Ipw_TxTimeAwareShaperInit(CtrlIdx, Eth_43_GMAC_Controller->Eth_43_GMAC_pIpwCtrlConfig);
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    }
#endif
    
    return FunctionSuccess;
}

/*================================================================================================*/
Std_ReturnType Eth_43_GMAC_Transmit(
                           uint8 CtrlIdx,
                           Eth_BufIdxType BufIdx,
                           Eth_FrameType FrameType,
                           boolean TxConfirmation,
                           uint16 LenByte,
                           const uint8 *PhysAddrPtr
                            )
{
    Std_ReturnType FunctionSuccess = (Std_ReturnType)E_NOT_OK;
    uint8 FifoIdx;
    uint8 PhysSrcAddr[ETH_43_GMAC_FRAME_MACSRC_LENGTH];
    uint8 *FrameBuffer;
    uint16 FrameLength;
    uint16 ChFrameType;

#if (STD_ON == ETH_43_GMAC_SWT_MANAGEMENT_SUPPORT_API)
    uint8 *DataMgmt;
    const Eth_43_GMAC_CtrlCfgType *Eth_43_GMAC_Controller;
#endif

#if (STD_ON == ETH_43_GMAC_SWT_MANAGEMENT_SUPPORT_API) || (STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT)
    uint32 CoreId = Eth_43_GMAC_GetCoreID();
#endif

#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT   
    if ((Std_ReturnType)E_OK == Eth_43_GMAC_Local_CheckEthHLDEntry(CoreId, CtrlIdx, ETH_43_GMAC_SID_TRANSMIT))
    {
        if (ETH_MODE_ACTIVE != Eth_43_GMAC_Ipw_GetControllerMode(CtrlIdx))
        {
            FunctionSuccess  = (Std_ReturnType)E_NOT_OK;
            (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_TRANSMIT, ETH_43_GMAC_E_INV_MODE);
        }
        else if (NULL_PTR == PhysAddrPtr)
        {
            FunctionSuccess  = (Std_ReturnType)E_NOT_OK;
            (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_TRANSMIT, ETH_43_GMAC_E_PARAM_POINTER);
        }
        else if
            (
                (BufIdx >= Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx]->Eth_43_GMAC_pEgressConfig->BufferCount) ||
                (NULL_PTR == Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][BufIdx].pu8BufferData)
            )
        {
            FunctionSuccess  = (Std_ReturnType)E_NOT_OK;
            (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_TRANSMIT, ETH_43_GMAC_E_INV_PARAM);
        }
        else
        {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
            /* Convert buffer index to Tx FIFO index */
            FifoIdx = Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][BufIdx].FifoIdx;

            /* Convert buffer index to buffer address pointer */
            FrameBuffer = Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][BufIdx].pu8BufferData;

            /* Configure Tx confirmation status */
            Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][BufIdx].bTxConfirmation = TxConfirmation;

            /* Insert ethernet header (DST + SRC + TYPE) into the buffer */
            Eth_43_GMAC_Local_Memcpy(&FrameBuffer[ETH_43_GMAC_FRAME_MACDST_OFFSET], PhysAddrPtr, ETH_43_GMAC_FRAME_MACDST_LENGTH);

            Eth_43_GMAC_Ipw_GetPhysicalAddress(CtrlIdx, PhysSrcAddr);
            Eth_43_GMAC_Local_Memcpy(&FrameBuffer[ETH_43_GMAC_FRAME_MACSRC_OFFSET], PhysSrcAddr, ETH_43_GMAC_FRAME_MACSRC_LENGTH);

            ChFrameType = Eth_43_GMAC_Local_Macro_Htons(FrameType);
            Eth_43_GMAC_Local_Memcpy(&FrameBuffer[ETH_43_GMAC_FRAME_ETHTYPE_OFFSET], (uint8*) &ChFrameType, ETH_43_GMAC_FRAME_ETHTYPE_LENGTH);

            /* Enqueue transmission request in the given Tx FIFO */
            Eth_43_GMAC_pLastTransmissionRequestQueueTail = Eth_43_GMAC_axTransmissionRequests[CtrlIdx][FifoIdx].pQueueTail;
            if (NULL_PTR == Eth_43_GMAC_axTransmissionRequests[CtrlIdx][FifoIdx].pQueueHead)
            {
                Eth_43_GMAC_axTransmissionRequests[CtrlIdx][FifoIdx].pQueueHead = &Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][BufIdx];
                Eth_43_GMAC_axTransmissionRequests[CtrlIdx][FifoIdx].pQueueTail = &Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][BufIdx];
            }
            else
            {
                Eth_43_GMAC_axTransmissionRequests[CtrlIdx][FifoIdx].pQueueTail->pNextBuffer = &Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][BufIdx];
                Eth_43_GMAC_axTransmissionRequests[CtrlIdx][FifoIdx].pQueueTail = &Eth_43_GMAC_axTxBufferIdxMap[CtrlIdx][BufIdx];
            }
            Eth_43_GMAC_axTransmissionRequests[CtrlIdx][FifoIdx].pQueueTail->pNextBuffer = NULL_PTR;
#if (STD_ON == ETH_43_GMAC_SWT_MANAGEMENT_SUPPORT_API)
            DataMgmt = &FrameBuffer[ETH_43_GMAC_FRAME_ETHTYPE_OFFSET];
            Eth_43_GMAC_Controller = Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx];
            if ((Std_ReturnType)E_OK == Eth_43_GMAC_Controller->Eth_43_GMAC_EthSwtDriverFunctionList.TxProcessFrameFunction(CtrlIdx, BufIdx, &DataMgmt, &LenByte))
            {
                if ((Std_ReturnType)E_OK == Eth_43_GMAC_Controller->Eth_43_GMAC_EthSwtDriverFunctionList.TxFinishedIndicationFunction(CtrlIdx, BufIdx))
                {
#endif
                    FrameLength = LenByte + ETH_43_GMAC_FRAME_HEADER_LENGTH;
                    FunctionSuccess = Eth_43_GMAC_Ipw_Transmit(CtrlIdx, FifoIdx, FrameBuffer, FrameLength);
#if (STD_ON == ETH_43_GMAC_SWT_MANAGEMENT_SUPPORT_API)
                }
            }
#endif
        
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
        }
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
    
    return FunctionSuccess; 
}


/*================================================================================================*/
void Eth_43_GMAC_ReportTransmission(
                                const uint8 CtrlIdx, \
                                const uint8 FifoIdx \
                           )
{
    const Eth_43_GMAC_CtrlCfgType *Eth_43_GMAC_Controller = NULL_PTR;
    uint32 CoreId = Eth_43_GMAC_GetCoreID();

    Eth_43_GMAC_Controller = Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx];

    Eth_43_GMAC_Ipw_ReportTransmission(Eth_43_GMAC_Controller, FifoIdx);

}

/*================================================================================================*/
void Eth_43_GMAC_Receive(uint8 CtrlIdx, \
                 uint8 FifoIdx,  \
                 Eth_RxStatusType *RxStatusPtr   \
                )   
{
    uint8 *FrameData;
    uint16 FrameLength;
    boolean FrameHasError;

    Eth_FrameType FrameType;
    boolean IsBroadcast;
    const uint8 *MacSrcAddr;
    const Eth_DataType *Payload;
    uint16 PayloadLength;

#if (STD_ON == ETH_43_GMAC_SWT_MANAGEMENT_SUPPORT_API)
    boolean IsMgmtFrameOnly;
    uint8 *DataMgmt;
    const Eth_43_GMAC_CtrlCfgType *Eth_43_GMAC_Controller;
#endif

    uint32 CoreId = Eth_43_GMAC_GetCoreID();

#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    if ((Std_ReturnType)E_OK == Eth_43_GMAC_Local_CheckEthHLDEntry(CoreId, CtrlIdx, ETH_43_GMAC_SID_RECEIVE))
    {
        if(ETH_MODE_ACTIVE != Eth_43_GMAC_Ipw_GetControllerMode(CtrlIdx))
        {
            (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_RECEIVE, ETH_43_GMAC_E_INV_MODE);
        }
        else
        {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
            *RxStatusPtr = Eth_43_GMAC_Ipw_ReceiveFrame(CtrlIdx, FifoIdx, &FrameData, &FrameLength, &FrameHasError);

            if ((ETH_NOT_RECEIVED != *RxStatusPtr) && (FALSE == FrameHasError))
            {
            #if (STD_ON == ETH_43_GMAC_SWT_MANAGEMENT_SUPPORT_API)
                DataMgmt = &FrameData[ETH_43_GMAC_FRAME_ETHTYPE_OFFSET];
                Eth_43_GMAC_Controller = Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx];
                /* There shouldn't be a buffer index concept for RX side */
                (void)Eth_43_GMAC_Controller->Eth_43_GMAC_EthSwtDriverFunctionList.RxProcessFrameFunction(CtrlIdx, ETH_43_GMAC_BUFFER_INDEX_UNUSED, &DataMgmt, &FrameLength, &IsMgmtFrameOnly);
                if ((boolean)FALSE == IsMgmtFrameOnly)
                {
            #endif
                /* Get Frame Type */
                FrameType  = FrameData[ETH_43_GMAC_FRAME_ETHTYPE_OFFSET + 1U];
                FrameType |= ((uint16)FrameData[ETH_43_GMAC_FRAME_ETHTYPE_OFFSET] << 8U);

                /* Check Broadcast */
                IsBroadcast = Eth_43_GMAC_Local_IsBroadcastFrame(&FrameData[ETH_43_GMAC_FRAME_MACDST_OFFSET]);

                /* Get MAC Source Address */
                MacSrcAddr = &FrameData[ETH_43_GMAC_FRAME_MACSRC_OFFSET];

                /* Get Payload */
                Payload = (Eth_DataType*)&FrameData[ETH_43_GMAC_FRAME_PAYLOAD_OFFSET];

                    /* Get Payload Length */
                    /* We assume CRC and padding have been stripped so that FrameLength = DST + SRC + (VLAN_TAG) + ETHTYPE + PAYLOAD */    
                    PayloadLength = FrameLength - ETH_43_GMAC_FRAME_HEADER_LENGTH;

                    EthIf_RxIndication(Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx]->EthCtrlEthIfIdx, FrameType, IsBroadcast, MacSrcAddr, Payload, PayloadLength);
            #if (STD_ON == ETH_43_GMAC_SWT_MANAGEMENT_SUPPORT_API)
                }

                (void)Eth_43_GMAC_Controller->Eth_43_GMAC_EthSwtDriverFunctionList.RxFinishedIndicationFunction(CtrlIdx, ETH_43_GMAC_BUFFER_INDEX_UNUSED);
            #endif

                Eth_43_GMAC_Ipw_ReleaseResources(CtrlIdx, FifoIdx);
            }
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
        }
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
}

/*================================================================================================*/
void Eth_43_GMAC_TxConfirmation(uint8 CtrlIdx)
{
    const Eth_43_GMAC_CtrlCfgType *Eth_43_GMAC_Controller = NULL_PTR;
    uint32 CoreId = Eth_43_GMAC_GetCoreID();
    uint8 FifoIdx;

#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    if ((Std_ReturnType)E_OK == Eth_43_GMAC_Local_CheckEthHLDEntry(CoreId, CtrlIdx, ETH_43_GMAC_SID_TXCONFIRMATION))
    {
        if (ETH_MODE_ACTIVE != Eth_43_GMAC_Ipw_GetControllerMode(CtrlIdx))
        {
            (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_TXCONFIRMATION, ETH_43_GMAC_E_INV_MODE);
        }
        else
        {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
            Eth_43_GMAC_Controller = Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx];

            for (FifoIdx = 0U; FifoIdx < Eth_43_GMAC_Controller->Eth_43_GMAC_pEgressConfig->FifoCount; ++FifoIdx)
            {
                Eth_43_GMAC_Ipw_ReportTransmission(Eth_43_GMAC_Controller, FifoIdx);
            }         
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
        }
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
}

#if STD_ON == ETH_43_GMAC_VERSION_INFO_API
/*================================================================================================*/
void Eth_43_GMAC_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr) 
{
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    if (NULL_PTR == VersionInfoPtr)
    {
        (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_GETVERSIONINFO, ETH_43_GMAC_E_PARAM_POINTER);
    }
    else
    {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT */
        VersionInfoPtr->moduleID = (uint16)ETH_43_GMAC_MODULE_ID;
        VersionInfoPtr->vendorID = (uint16)ETH_43_GMAC_VENDOR_ID;
        VersionInfoPtr->sw_major_version = (uint8)ETH_43_GMAC_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8)ETH_43_GMAC_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8)ETH_43_GMAC_SW_PATCH_VERSION;
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT */
}
#endif /* ETH_43_GMAC_VERSION_INFO_API */

/*================================================================================================*/
/**
* @brief         The function checks for controller errors and lost frames. Used for polling state changes.
* @api
* implements    Eth_MainFunction_Activity
*/
void Eth_43_GMAC_MainFunction(void)
{
    Eth_ModeType CurrentMode;
    uint8 CtrlIdx;
    uint32 CoreId = Eth_43_GMAC_GetCoreID();
#if (STD_ON == ETH_43_GMAC_DEM_EVENT_DETECT)
    const Eth_43_GMAC_DemEventsType *Eth_43_GMAC_CtrlDemEvents;
#endif
   
#if (STD_ON == ETH_43_GMAC_MULTICORE_SUPPORT)
    if ((CoreId < ETH_43_GMAC_MAX_COREIDX_SUPPORTED) && (NULL_PTR != Eth_43_GMAC_apxInternalCfg[CoreId]))
#else
    if (NULL_PTR != Eth_43_GMAC_apxInternalCfg[CoreId])
#endif
    {
        for (CtrlIdx = 0U; CtrlIdx < ETH_43_GMAC_MAX_COREIDX_SUPPORTED; ++CtrlIdx)
        {
            if (NULL_PTR != Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx])
            {
                CurrentMode = Eth_43_GMAC_Ipw_GetControllerMode(CtrlIdx);
                if (CurrentMode != Eth_43_GMAC_axCtrlMode[CtrlIdx])
                {
                    Eth_43_GMAC_axCtrlMode[CtrlIdx] = CurrentMode;
                    EthIf_CtrlModeIndication(Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx]->EthCtrlEthIfIdx, CurrentMode);
                }

#if (STD_ON == ETH_43_GMAC_DEM_EVENT_DETECT)
                Eth_43_GMAC_CtrlDemEvents = &(Eth_43_GMAC_apxInternalCfg[CoreId]->Eth_43_GMAC_apCtrlConfig[CtrlIdx]->Eth_43_GMAC_DemEventsList);

                if ((boolean)FALSE == Eth_43_GMAC_Ipw_CheckAccessToController(CtrlIdx))
                {
                    if ((uint32)STD_ON == (uint32)(Eth_43_GMAC_CtrlDemEvents->ETH_E_ACCESS_Cfg.state))
                    {
                        (void)Dem_SetEventStatus((Dem_EventIdType)(Eth_43_GMAC_CtrlDemEvents->ETH_E_ACCESS_Cfg.id), DEM_EVENT_STATUS_PREFAILED);
                    }
                }
                else
                {
                    if ((uint32)STD_ON == (uint32)(Eth_43_GMAC_CtrlDemEvents->ETH_E_ACCESS_Cfg.state))
                    {
                       (void)Dem_SetEventStatus((Dem_EventIdType)(Eth_43_GMAC_CtrlDemEvents->ETH_E_ACCESS_Cfg.id), DEM_EVENT_STATUS_PREPASSED);
                    }
                    
                    Eth_43_GMAC_Local_CheckDemStatus(CtrlIdx, (uint32)Eth_43_GMAC_CtrlDemEvents->ETH_E_RX_FRAMES_LOST_Cfg.state, ETH_E_RX_FRAMES_LOST, (Dem_EventIdType)(Eth_43_GMAC_CtrlDemEvents->ETH_E_RX_FRAMES_LOST_Cfg.id));
                    
                    Eth_43_GMAC_Local_CheckDemStatus(CtrlIdx, (uint32)Eth_43_GMAC_CtrlDemEvents->ETH_E_CRC_Cfg.state, ETH_E_CRC, (Dem_EventIdType)(Eth_43_GMAC_CtrlDemEvents->ETH_E_CRC_Cfg.id));
                    
                    Eth_43_GMAC_Local_CheckDemStatus(CtrlIdx, (uint32)Eth_43_GMAC_CtrlDemEvents->ETH_E_UNDERSIZEFRAME_Cfg.state, ETH_E_UNDERSIZEFRAME, (Dem_EventIdType)(Eth_43_GMAC_CtrlDemEvents->ETH_E_UNDERSIZEFRAME_Cfg.id));
                    
                    Eth_43_GMAC_Local_CheckDemStatus(CtrlIdx, (uint32)Eth_43_GMAC_CtrlDemEvents->ETH_E_OVERSIZEFRAME_Cfg.state, ETH_E_OVERSIZEFRAME, (Dem_EventIdType)(Eth_43_GMAC_CtrlDemEvents->ETH_E_OVERSIZEFRAME_Cfg.id));
                    
                    Eth_43_GMAC_Local_CheckDemStatus(CtrlIdx, (uint32)Eth_43_GMAC_CtrlDemEvents->ETH_E_ALIGNMENT_Cfg.state, ETH_E_ALIGNMENT, (Dem_EventIdType)(Eth_43_GMAC_CtrlDemEvents->ETH_E_ALIGNMENT_Cfg.id));
                    
                    Eth_43_GMAC_Local_CheckDemStatus(CtrlIdx, (uint32)Eth_43_GMAC_CtrlDemEvents->ETH_E_SINGLECOLLISION_Cfg.state, ETH_E_SINGLECOLLISION, (Dem_EventIdType)(Eth_43_GMAC_CtrlDemEvents->ETH_E_SINGLECOLLISION_Cfg.id));
                    
                    Eth_43_GMAC_Local_CheckDemStatus(CtrlIdx, (uint32)Eth_43_GMAC_CtrlDemEvents->ETH_E_MULTIPLECOLLISION_Cfg.state, ETH_E_MULTIPLECOLLISION, (Dem_EventIdType)(Eth_43_GMAC_CtrlDemEvents->ETH_E_MULTIPLECOLLISION_Cfg.id));
                    
                    Eth_43_GMAC_Local_CheckDemStatus(CtrlIdx, (uint32)Eth_43_GMAC_CtrlDemEvents->ETH_E_LATECOLLISION_Cfg.state, ETH_E_LATECOLLISION, (Dem_EventIdType)(Eth_43_GMAC_CtrlDemEvents->ETH_E_LATECOLLISION_Cfg.id));
                }
#endif /* ETH_43_GMAC_DEM_EVENT_DETECT */
            }
        }
    }
}

#if (STD_ON == ETH_43_GMAC_COALESCING_INTERRUPT)
/*================================================================================================*/
Std_ReturnType Eth_43_GMAC_ConfigureTxIntCoalescing(uint8 CtrlIdx, uint8 FifoIdx, Eth_IntCoalescingConfigType TxIntCoalescingConfig) 
{
    uint32 CoreId = Eth_43_GMAC_GetCoreID();
    Std_ReturnType FunctionSuccess = (Std_ReturnType)E_NOT_OK;
#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    if ((Std_ReturnType)E_OK == Eth_43_GMAC_Local_CheckEthHLDEntry(CoreId, CtrlIdx, ETH_43_GMAC_SID_CONFIGURETXCOALESCING))
    {
        /* The controller must have been enabled previosly */
        if(ETH_MODE_ACTIVE != Eth_43_GMAC_Ipw_GetControllerMode(CtrlIdx))
        {
            (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_RECEIVE, ETH_43_GMAC_E_INV_MODE);
        }
        else
        {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */

        FunctionSuccess = Eth_43_GMAC_Ipw_ConfigureTxIntCoalescing( CtrlIdx, 
                                                                            FifoIdx, 
                                                                            TxIntCoalescingConfig.Threshold,
                                                                            TxIntCoalescingConfig.TimeoutInTicks);

#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
        }
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */

    return FunctionSuccess;
}

/*================================================================================================*/
Std_ReturnType Eth_43_GMAC_ConfigureRxIntCoalescing(uint8 CtrlIdx, uint8 FifoIdx, Eth_IntCoalescingConfigType RxIntCoalescingConfig) 
{
    uint32 CoreId = Eth_43_GMAC_GetCoreID();
    Std_ReturnType FunctionSuccess = (Std_ReturnType)E_NOT_OK;

#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
    if ((Std_ReturnType)E_OK == Eth_43_GMAC_Local_CheckEthHLDEntry(CoreId, CtrlIdx, ETH_43_GMAC_SID_CONFIGURERXCOALESCING))
    {
        /* The controller must have been enabled previosly */
        if(ETH_MODE_ACTIVE != Eth_43_GMAC_Ipw_GetControllerMode(CtrlIdx))
        {
            (void)Det_ReportError(ETH_43_GMAC_MODULE_ID, ETH_43_GMAC_DRIVER_INSTANCE, ETH_43_GMAC_SID_RECEIVE, ETH_43_GMAC_E_INV_MODE);
        }
        else
        {
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
        FunctionSuccess = Eth_43_GMAC_Ipw_ConfigureRxIntCoalescing(CtrlIdx, 
                                                                            FifoIdx, 
                                                                            RxIntCoalescingConfig.Threshold,  
                                                                            RxIntCoalescingConfig.TimeoutInTicks);

#if STD_ON == ETH_43_GMAC_DEV_ERROR_DETECT
        }
    }
#endif /* ETH_43_GMAC_DEV_ERROR_DETECT  */
    return FunctionSuccess;
}
#endif

#define ETH_43_GMAC_STOP_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
