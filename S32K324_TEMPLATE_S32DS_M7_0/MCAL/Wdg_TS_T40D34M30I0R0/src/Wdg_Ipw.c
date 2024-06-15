/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Swt
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

/**
*   @file
*
*   @addtogroup Wdg
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Wdg_Ipw.h"


/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_IPW_VENDOR_ID_C                      43
#define WDG_IPW_AR_RELEASE_MAJOR_VERSION_C       4
#define WDG_IPW_AR_RELEASE_MINOR_VERSION_C       7
#define WDG_IPW_AR_RELEASE_REVISION_VERSION_C    0
#define WDG_IPW_SW_MAJOR_VERSION_C               3
#define WDG_IPW_SW_MINOR_VERSION_C               0
#define WDG_IPW_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Wdg_Ipw header file are of the same vendor */
#if (WDG_IPW_VENDOR_ID_C != WDG_IPW_VENDOR_ID)
    #error "Wdg_Ipw.c and Wdg_Ipw.h have different vendor ids"
#endif

#if ((WDG_IPW_AR_RELEASE_MAJOR_VERSION_C     != WDG_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_IPW_AR_RELEASE_MINOR_VERSION_C     != WDG_IPW_AR_RELEASE_MINOR_VERSION) || \
     (WDG_IPW_AR_RELEASE_REVISION_VERSION_C  != WDG_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg_Ipw.c and Wdg_Ipw.h are different"
#endif

#if ((WDG_IPW_SW_MAJOR_VERSION_C != WDG_IPW_SW_MAJOR_VERSION) || \
     (WDG_IPW_SW_MINOR_VERSION_C != WDG_IPW_SW_MINOR_VERSION) || \
     (WDG_IPW_SW_PATCH_VERSION_C != WDG_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_Ipw.c and Wdg_Ipw.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
static Wdg_Ipw_IpType Wdg_Ipw_aeIp[WDG_IPW_NO_OF_INSTANCES] = WDG_IPW_INIT_ARRAY;

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef WDG_ROM
    #if (WDG_ROM == 1U)
        #define WDG_START_SEC_CODE
    #endif
#else
    #if (WDG_RAM == 0U)
        #define WDG_START_SEC_RAMCODE
    #endif
#endif

#include "Wdg_MemMap.h"

Std_ReturnType Wdg_Ipw_Init(Wdg_Ipw_InstanceType Instance, const Wdg_Ipw_ConfigType * const IpwConfig)
{
    Std_ReturnType Ret = (Std_ReturnType) E_OK;

    Wdg_Ipw_aeIp[Instance] = IpwConfig->eWdgIp;
    switch (IpwConfig->eWdgIp)
    {
#if (SWT_IP_USED == STD_ON)
        case WDG_IPW_SWT_IP:

            /* Initialize Wdg module */
            if (Swt_Ip_Init((uint32)Instance, IpwConfig->aSwtConfig) != SWT_IP_STATUS_SUCCESS)
            {
                Ret = (Std_ReturnType) E_NOT_OK;
            }
            break;
#endif /*(SWT_IP_USED == STD_ON)*/
#if (AEWDOG_IP_USED == STD_ON)
        case WDG_IPW_AEWDOG_IP:

            (void)Instance;
            if (AeWdog_Ip_Init((uint8)0, IpwConfig->pAeWdogConfig) != AEWDOG_IP_STATUS_SUCCESS)
            {
                Ret = (Std_ReturnType) E_NOT_OK;
            }
            break;
#endif /*(AEWDOG_IP_USED == STD_ON)*/
        default:

            Ret = (Std_ReturnType) E_NOT_OK;
            break;
    }

    return Ret;
}

Std_ReturnType Wdg_Ipw_SetMode(Wdg_Ipw_InstanceType Instance, const Wdg_Ipw_ConfigType * const IpwConfig)
{
    Std_ReturnType Ret = (Std_ReturnType) E_OK;

    Wdg_Ipw_aeIp[Instance] = IpwConfig->eWdgIp;
    
    switch (Wdg_Ipw_aeIp[Instance])
    {
#if (SWT_IP_USED == STD_ON)
        case WDG_IPW_SWT_IP:

            /* Reconfigure Wdg module */
            if (Swt_Ip_Config((uint32)Instance, IpwConfig->aSwtConfig) != SWT_IP_STATUS_SUCCESS)
            {
                Ret = (Std_ReturnType) E_NOT_OK;
            }
            break;
#endif /*(SWT_IP_USED == STD_ON)*/
#if (AEWDOG_IP_USED == STD_ON)
        case WDG_IPW_AEWDOG_IP:

            (void)IpwConfig;
            Ret = (Std_ReturnType) E_NOT_OK;
            break;
#endif /*(AEWDOG_IP_USED == STD_ON)*/
        default:

            Ret = (Std_ReturnType) E_NOT_OK;
            break;
    }

    return Ret;
}

Std_ReturnType Wdg_Ipw_StartTimer(Wdg_Ipw_InstanceType Instance)
{
    Std_ReturnType Ret = (Std_ReturnType) E_OK;

    switch (Wdg_Ipw_aeIp[Instance])
    {
#if (SWT_IP_USED == STD_ON)
        case WDG_IPW_SWT_IP:

            /* Starts the timer for the Wdg module */
            if (Swt_Ip_StartTimer((uint32)Instance) != SWT_IP_STATUS_SUCCESS)
            {
                Ret = (Std_ReturnType) E_NOT_OK;
            }
            break;
#endif /*(SWT_IP_USED == STD_ON)*/
#if (AEWDOG_IP_USED == STD_ON)
        case WDG_IPW_AEWDOG_IP:

            Ret = (Std_ReturnType) E_NOT_OK;

            break;
#endif /*(AEWDOG_IP_USED == STD_ON)*/
        default:

            Ret = (Std_ReturnType) E_NOT_OK;
            break;
    }

    return Ret;
}

#if (WDG_IPW_DEINIT == STD_ON)
    Std_ReturnType Wdg_Ipw_StopTimer(Wdg_Ipw_InstanceType Instance)
    {
        Std_ReturnType Ret = (Std_ReturnType) E_OK;

        /* Stops the timer for the Wdg module */
        if (Swt_Ip_StopTimer((uint32)Instance) != SWT_IP_STATUS_SUCCESS)
        {
            Ret = (Std_ReturnType) E_NOT_OK;
        }

        return Ret;
    }

    Std_ReturnType Wdg_Ipw_Deinit(Wdg_Ipw_InstanceType Instance)
    {
        Std_ReturnType Ret = (Std_ReturnType) E_OK;

        /* De-initializes Wdg module */
        if (Swt_Ip_Deinit((uint32)Instance) != SWT_IP_STATUS_SUCCESS)
        {
            Ret = (Std_ReturnType) E_NOT_OK;
        }

        return Ret;
    }
#endif

void Wdg_Ipw_Service(Wdg_Ipw_InstanceType Instance)
{
    switch (Wdg_Ipw_aeIp[Instance])
    {
#if (SWT_IP_USED == STD_ON)
        case WDG_IPW_SWT_IP:

            /* Services Wdg module */
            Swt_Ip_Service((uint32)Instance);
            break;
#endif /*(SWT_IP_USED == STD_ON)*/
#if (AEWDOG_IP_USED == STD_ON)
        case WDG_IPW_AEWDOG_IP:

            AeWdog_Ip_Service((uint8)0);
            break;
#endif /*(AEWDOG_IP_USED == STD_ON)*/
        default:
            /* do nothing*/
            break;
    }
}

#if (WDG_IPW_DEINIT == STD_ON)
#if (WDG_IPW_CLEAR_RESET_REQUEST == STD_ON)
    Wdg_Ipw_StatusType Wdg_Ipw_ClearResetRequest(Wdg_Ipw_InstanceType Instance)
    {
        Wdg_Ipw_StatusType Ret      = WDG_IPW_STATUS_SUCCESS;
        Swt_Ip_StatusType RetClrReq = SWT_IP_STATUS_SUCCESS;

        /* Clears reset request */
        RetClrReq =  Swt_Ip_ClearResetRequest((uint32)Instance);

        if (SWT_IP_STATUS_SUCCESS == RetClrReq)
        {
            Ret = WDG_IPW_STATUS_SUCCESS;
        }
        else 
        {
            if (SWT_IP_STATUS_TIMEOUT == RetClrReq)
            {
                Ret = WDG_IPW_STATUS_TIMEOUT;
            }
            else
            {
                Ret = WDG_IPW_STATUS_ERROR;
            }
        }

        return Ret;
    }
#endif
#endif

#ifdef WDG_ROM
    #if (WDG_ROM == 1U)
        #define WDG_STOP_SEC_CODE
    #endif
#else
    #if (WDG_RAM == 0U)
        #define WDG_STOP_SEC_RAMCODE
    #endif
#endif


#include "Wdg_MemMap.h"

/** @} */
