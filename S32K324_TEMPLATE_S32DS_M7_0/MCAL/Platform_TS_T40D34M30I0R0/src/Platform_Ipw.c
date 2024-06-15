/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_P10_D2307_ASR_REL_4_7_REV_0000_20230726
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
*   @internal
*   @addtogroup Platform_Ipw
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#include "Platform_TypesDef.h"
#include "Platform_Ipw.h"
#include "Mcal.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_IPW_VENDOR_ID_C                         43
#define CDD_PLATFORM_IPW_AR_RELEASE_MAJOR_VERSION_C          4
#define CDD_PLATFORM_IPW_AR_RELEASE_MINOR_VERSION_C          7
#define CDD_PLATFORM_IPW_AR_RELEASE_REVISION_VERSION_C       0
#define CDD_PLATFORM_IPW_SW_MAJOR_VERSION_C                  3
#define CDD_PLATFORM_IPW_SW_MINOR_VERSION_C                  0
#define CDD_PLATFORM_IPW_SW_PATCH_VERSION_C                  0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Platform_TypesDef header file are of the same vendor */
#if (CDD_PLATFORM_IPW_VENDOR_ID_C != CDD_PLATFORM_TYPESDEF_VENDOR_ID)
    #error "Platform_Ipw.c and Platform_TypesDef.h have different vendor ids"
#endif
/* Check if current file and Platform_TypesDef header file are of the same Autosar version */
#if ((CDD_PLATFORM_IPW_AR_RELEASE_MAJOR_VERSION_C    != CDD_PLATFORM_TYPESDEF_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_AR_RELEASE_MINOR_VERSION_C    != CDD_PLATFORM_TYPESDEF_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_AR_RELEASE_REVISION_VERSION_C != CDD_PLATFORM_TYPESDEF_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Ipw.c and Platform_TypesDef.h are different"
#endif
/* Check if current file and Platform_Ipw_Cfg header file are of the same Software version */
#if ((CDD_PLATFORM_IPW_SW_MAJOR_VERSION_C != CDD_PLATFORM_TYPESDEF_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_SW_MINOR_VERSION_C != CDD_PLATFORM_TYPESDEF_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_SW_PATCH_VERSION_C != CDD_PLATFORM_TYPESDEF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Ipw.c and Platform_TypesDef.h are different"
#endif

/* Check if current file and Platform_Ipw header file are of the same vendor */
#if (CDD_PLATFORM_IPW_VENDOR_ID_C != CDD_PLATFORM_IPW_VENDOR_ID)
    #error "Platform_Ipw.c and Platform_Ipw.h have different vendor ids"
#endif
/* Check if current file and Platform_Ipw header file are of the same Autosar version */
#if ((CDD_PLATFORM_IPW_AR_RELEASE_MAJOR_VERSION_C    != CDD_PLATFORM_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_AR_RELEASE_MINOR_VERSION_C    != CDD_PLATFORM_IPW_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_AR_RELEASE_REVISION_VERSION_C != CDD_PLATFORM_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Ipw.c and Platform_Ipw.h are different"
#endif
/* Check if current file and Platform_Ipw header file are of the same Software version */
#if ((CDD_PLATFORM_IPW_SW_MAJOR_VERSION_C != CDD_PLATFORM_IPW_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_SW_MINOR_VERSION_C != CDD_PLATFORM_IPW_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_SW_PATCH_VERSION_C != CDD_PLATFORM_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Ipw.c and Platform_Ipw.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Platform_Ipw.c header file are of the same Autosar version */
    #if ((CDD_PLATFORM_IPW_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_PLATFORM_IPW_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Platform_Ipw.c and Mcal.h are different"
    #endif   
#endif

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

#if ((STD_ON == PLATFORM_ENABLE_USER_MODE_SUPPORT) && (defined (MCAL_ENABLE_USER_MODE_SUPPORT)))
    #define Call_System_Ip_ConfigIrq(eIrq,bEnable)          OsIf_Trusted_Call2params(System_Ip_ConfigIrq,(eIrq),(bEnable))
    #define Call_System_Ip_SetAhbSlavePriority(bPriority)   OsIf_Trusted_Call1param(System_Ip_SetAhbSlavePriority,(bPriority))
#else
    #define Call_System_Ip_ConfigIrq(eIrq,bEnable)          System_Ip_ConfigIrq((eIrq),(bEnable))
    #define Call_System_Ip_SetAhbSlavePriority(bPriority)   System_Ip_SetAhbSlavePriority((bPriority))
#endif

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief         Initializes the platform settings based on user configuration.
 */
void Platform_Ipw_Init(const Platform_Ipw_ConfigType *pConfig)
{
#if (PLATFORM_SYS_CFG == STD_ON)
    uint8 irqIdx;
#endif
#if (PLATFORM_INT_MONITOR == STD_ON)
    uint8 idx = 0u;
#endif

    /* Initialize interrupts at interrupt controller level */
    if (NULL_PTR != pConfig->pIntCtrlConfig)
    {
        (void)IntCtrl_Ip_Init(pConfig->pIntCtrlConfig);
    }

#if (PLATFORM_SYS_CFG == STD_ON)
    /* Configure core-related interrupt requests */
    if (pConfig->aSystemConfig != NULL_PTR)
    {
        for (irqIdx = 0u; irqIdx < (pConfig->aSystemConfig)->u8SysIrqsCount; irqIdx++)
        {
            Call_System_Ip_ConfigIrq((pConfig->aSystemConfig)->aSystemIrqs[irqIdx].eIrq, (pConfig->aSystemConfig)->aSystemIrqs[irqIdx].bEnable);
        }
        Call_System_Ip_SetAhbSlavePriority((pConfig->aSystemConfig)->bAhbSlavePriority);
    }
#endif

#if (PLATFORM_INT_MONITOR == STD_ON)
    /* Configure interrupt monitors */
    for (idx = 0u; idx < (pConfig->pIntMonitor)->u8NumChannel; idx++)
    {
        Intm_Ip_SelectMonitoredIrq(pConfig->pIntMonitor->aIntmChannelConfig[idx].eMonitor, pConfig->pIntMonitor->aIntmChannelConfig[idx].eMonitoredIrq);
        Intm_Ip_SetLatency(pConfig->pIntMonitor->aIntmChannelConfig[idx].eMonitor, pConfig->pIntMonitor->aIntmChannelConfig[idx].u32AcceptedLatency);
    }
    if (pConfig->pIntMonitor->pIntmGenericConfig != NULL_PTR)
    {
        if (pConfig->pIntMonitor->pIntmGenericConfig->bEnableIntMonitor)
        {
            Intm_Ip_EnableMonitor();
        }
        else
        {
            Intm_Ip_DisableMonitor();
        }
    }
#endif
}

#if (PLATFORM_MSCM_CFG == STD_ON)
/**
 * @brief         Initializes the platform settings for non-core elements  based on user configuration.
 */

void Platform_Ipw_InitNonCore(const Platform_Ipw_NonCoreConfigType *pConfig)
{
    uint32 irqIdx;
    if (pConfig -> pIntRouteConfig != NULL_PTR)
    {
        for (irqIdx = 0; irqIdx < (pConfig -> pIntRouteConfig) -> u32ConfigIrqCount ; irqIdx++)
        {           
            IntCtrl_Ip_SetTargetCores(pConfig -> pIntRouteConfig->aIrqConfig[irqIdx].eIrqNumber,
                                    pConfig -> pIntRouteConfig->aIrqConfig[irqIdx].u8TargetCores);
            IntCtrl_Ip_InstallHandler(pConfig -> pIntRouteConfig->aIrqConfig[irqIdx].eIrqNumber,
                                  pConfig -> pIntRouteConfig->aIrqConfig[irqIdx].pfHandler,
                                  NULL_PTR);
        }
    }
}
#endif
#if (PLATFORM_INT_MONITOR == STD_ON)
/**
 * @internal
 * @brief         Enables/disables interrupt monitoring feature by calling the Interrupt Monitor IP layer.
 */
void Platform_Ipw_SetIrqMonitor(boolean bEnable)
{    
    if (bEnable == TRUE)
    {
        Intm_Ip_EnableMonitor();
    }
    else
    {
        Intm_Ip_DisableMonitor();
    }
}


/**
 * @internal
 * @brief         Selects an interrupt to be monitored by calling the Interrupt Monitor IP layer.
 */
void Platform_Ipw_SelectMonitoredIrq(const Platform_Ipw_ConfigType *pConfig,
                                                uint8 u8Channel,
                                                IRQn_Type eIrqNumber)
{
    uint8 u8ChannelIdxInPartition;
    Intm_Ip_MonitorType eHwChannel;
    
    u8ChannelIdxInPartition = (*((pConfig->pIntMonitor)->Platform_IndexChannelMap))[u8Channel];
    eHwChannel = pConfig->pIntMonitor->aIntmChannelConfig[u8ChannelIdxInPartition].eMonitor;
    Intm_Ip_SelectMonitoredIrq(eHwChannel, eIrqNumber);
}                                                

/**
 * @internal
 * @brief         Selects an accepted latency for a monitored interrupt
 *                by calling the Interrupt Monitor IP layer.
 */
void Platform_Ipw_SetMonitoredIrqLatency(const Platform_Ipw_ConfigType *pConfig,
                                                    uint8 u8Channel,
                                                    uint32 u32Latency)
{
    uint8 u8ChannelIdxInPartition;
    Intm_Ip_MonitorType eHwChannel;
    
    u8ChannelIdxInPartition = (*((pConfig->pIntMonitor)->Platform_IndexChannelMap))[u8Channel];
    eHwChannel = pConfig->pIntMonitor->aIntmChannelConfig[u8ChannelIdxInPartition].eMonitor;
    Intm_Ip_SetLatency(eHwChannel, u32Latency);
}


/**
 * @internal
 * @brief         Resets an interrupt monitor timer by calling the Interrupt Monitor IP layer.
 */
void Platform_Ipw_ResetIrqMonitorTimer(const Platform_Ipw_ConfigType *pConfig,
                                                    uint8 u8Channel)
{
    uint8 u8ChannelIdxInPartition;
    Intm_Ip_MonitorType eHwChannel;
    
    u8ChannelIdxInPartition = (*((pConfig->pIntMonitor)->Platform_IndexChannelMap))[u8Channel];
    eHwChannel = pConfig->pIntMonitor->aIntmChannelConfig[u8ChannelIdxInPartition].eMonitor;
    Intm_Ip_ResetTimer(eHwChannel);
}


/**
 * @internal
 * @brief         Returns the status of an interrupt monitor by calling the Interrupt Monitor IP layer.
 */
boolean Platform_Ipw_GetIrqMonitorStatus(const Platform_Ipw_ConfigType *pConfig,
                                                        uint8 u8Channel)
{
    boolean RetVal = TRUE;
    uint8 u8ChannelIdxInPartition;
    Intm_Ip_MonitorType eHwChannel;
    
    u8ChannelIdxInPartition = (*((pConfig->pIntMonitor)->Platform_IndexChannelMap))[u8Channel];
    eHwChannel = pConfig->pIntMonitor->aIntmChannelConfig[u8ChannelIdxInPartition].eMonitor;
    if (Intm_Ip_GetStatus(eHwChannel) == 0U)
    {
        RetVal = FALSE;
    }
    return RetVal;
}

/**
 * @internal
 * @brief         Returns the validation result for given logical channel.
 */
Std_ReturnType Platform_Ipw_ValidateChannelIntm(const Platform_Ipw_ConfigType *pConfig,
                                                    uint8 u8Channel)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 u8ChannelIdxInPartition;
    if(((pConfig->pIntMonitor)->Platform_IndexChannelMap) != NULL_PTR)
    {
        u8ChannelIdxInPartition = (*((pConfig->pIntMonitor)->Platform_IndexChannelMap))[u8Channel];
        if (u8ChannelIdxInPartition <= (pConfig->pIntMonitor->u8NumChannel))
        {
            RetVal = E_OK;
        }
    }   
    return RetVal;
}

/**
 * @internal
 * @brief         Returns the the possibility of setting interrupt monitor enabling.
 */
Std_ReturnType Platform_Ipw_ValidateSetIrqMonitor(const Platform_Ipw_ConfigType *pConfig)
{
    Std_ReturnType RetVal = E_NOT_OK;
    
    if (pConfig->pIntMonitor->pIntmGenericConfig != NULL_PTR)
    {
        RetVal = E_OK;
    }
    return RetVal;
}
#endif

#if (PLATFORM_ENABLE_MPU_M7 == STD_ON)
/**
* @brief        Platform_Ipw_Mpu_M7_Init
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Platform_Ipw_Mpu_M7_Init(const Platform_Ipw_ConfigType * pIpwConfig)
{
    Mpu_M7_Ip_Init(pIpwConfig->Platform_Ipw_pMpuConfig);
}


/**
* @brief        Platform_Ipw_Mpu_M7_SetRegionConfig
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Platform_Ipw_Mpu_M7_SetRegionConfig(uint8 u8RegionNum, const Platform_Mpu_M7_RegionConfigType * const pUserConfigPtr)
{
    Mpu_M7_Ip_SetRegionConfig(u8RegionNum, pUserConfigPtr);
}



/**
* @brief        Platform_Ipw_Mpu_M7_EnableRegion
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Platform_Ipw_Mpu_M7_EnableRegion(uint8 u8RegionNum, boolean bEnable)
{
    Mpu_M7_Ip_EnableRegion(u8RegionNum, bEnable);
}

/**
* @brief        Platform_Ipw_Mpu_M7_SetAccessRight
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Platform_Ipw_Mpu_M7_SetAccessRight(uint8 u8RegionNum, Platform_Mpu_M7_AccessRightsType eRights)
{
    Mpu_M7_Ip_SetAccessRight(u8RegionNum, eRights);
}

/**
* @brief        Platform_Ipw_Mpu_M7_GetErrorDetails
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
boolean Platform_Ipw_Mpu_M7_GetErrorDetails(Platform_Mpu_M7_ErrorDetailsType * pErrorDetails)
{
    return Mpu_M7_Ip_GetErrorDetails(pErrorDetails);
}

#endif /* #if (STD_ON == PLATFORM_ENABLE_MPU_M7)  */

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"
