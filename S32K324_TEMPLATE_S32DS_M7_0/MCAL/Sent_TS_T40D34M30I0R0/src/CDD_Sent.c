/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : FLEXIO_SENT_IP
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_P10_D2307_ASR_REL_4_7_REV_0000_20230726
*
*   Copyright 2020 - 2023 NXP Semiconductors NXP.
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
*   @file    CDD_Sent.c
*   @version 3.0.0
*
*   @brief   AUTOSAR Sent - High level part of Sent driver.
*   @details This file contains the functions defined by AutoSAR.
*
*   @addtogroup SENT_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Sent.h"
#include "Sent_Ipw.h"
#if (SENT_DEV_ERROR_DETECT == STD_ON)
  #include "Det.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           CDD_Sent.c
*/
#define SENT_VENDOR_ID_C                      43
#define SENT_AR_RELEASE_MAJOR_VERSION_C       4
#define SENT_AR_RELEASE_MINOR_VERSION_C       7
#define SENT_AR_RELEASE_REVISION_VERSION_C    0
#define SENT_SW_MAJOR_VERSION_C               3
#define SENT_SW_MINOR_VERSION_C               0
#define SENT_SW_PATCH_VERSION_C               0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and SENT header file are of the same vendor */
#if (SENT_VENDOR_ID_C != SENT_VENDOR_ID)
    #error "Sent.c and Sent.h have different vendor ids"
#endif
/* Check if current file and SENT header file are of the same Autosar version */
#if ((SENT_AR_RELEASE_MAJOR_VERSION_C    != SENT_AR_RELEASE_MAJOR_VERSION) || \
     (SENT_AR_RELEASE_MINOR_VERSION_C    != SENT_AR_RELEASE_MINOR_VERSION) || \
     (SENT_AR_RELEASE_REVISION_VERSION_C != SENT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Sent.c and Sent.h are different"
#endif
/* Check if current file and SENT header file are of the same Software version */
#if ((SENT_SW_MAJOR_VERSION_C != SENT_SW_MAJOR_VERSION) || \
     (SENT_SW_MINOR_VERSION_C != SENT_SW_MINOR_VERSION) || \
     (SENT_SW_PATCH_VERSION_C != SENT_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Sent.c and Sent.h are different"
#endif

/* Check if current file and SENT_IPW header file are of the same vendor */
#if (SENT_VENDOR_ID_C != SENT_IPW_VENDOR_ID)
    #error "SENT.c and SENT_IPW.h have different vendor ids"
#endif
/* Check if current file and SENT_IPW header file are of the same Autosar version */
#if ((SENT_AR_RELEASE_MAJOR_VERSION_C    != SENT_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (SENT_AR_RELEASE_MINOR_VERSION_C    != SENT_IPW_AR_RELEASE_MINOR_VERSION) || \
     (SENT_AR_RELEASE_REVISION_VERSION_C != SENT_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Sent.c and SENT_IPW.h are different"
#endif
/* Check if current file and SENT_IPW header file are of the same Software version */
#if ((SENT_SW_MAJOR_VERSION_C != SENT_IPW_SW_MAJOR_VERSION) || \
     (SENT_SW_MINOR_VERSION_C != SENT_IPW_SW_MINOR_VERSION) || \
     (SENT_SW_PATCH_VERSION_C != SENT_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Sent.c and SENT_IPW.h are different"
#endif

/* Check if current file and DET header file are of the same version */
#if (SENT_DEV_ERROR_DETECT == STD_ON)
  #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((SENT_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (SENT_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Sent.c and Det.h are different"
    #endif
  #endif
#endif


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#if (STD_ON == SENT_MULTICORE_SUPPORT)
    #define Sent_GetCoreID()        ((uint32)OsIf_GetCoreID())
#else
    #define Sent_GetCoreID()        ((uint32)0U)
#endif

#define CHANNEL_UNUSED                  ((uint8) 0xFFU)

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

#define SENT_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sent_MemMap.h"

/**
* @brief          Sent channel hardware map variable.
* @details        Sent channel hardware map.
*/
#if (SENT_DEV_ERROR_DETECT == STD_ON)
static Sent_DriverStatusType Sent_au8ControllerInitStatus[SENT_NUMBER_CONFIGURED_CONTROLLER];
#endif

#define SENT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sent_MemMap.h"

#if (SENT_DEV_ERROR_DETECT == STD_ON)
#define SENT_START_SEC_VAR_INIT_8
#include "Sent_MemMap.h"

static uint8 Sent_au8NumberChannel[SENT_NUMBER_CONFIGURED_CONTROLLER] = SENT_NUMBER_CONFIGURED_CHANNELS;

#define SENT_STOP_SEC_VAR_INIT_8
#include "Sent_MemMap.h"
#endif
/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#if (SENT_PRECOMPILE_SUPPORT == STD_ON)
    #define SENT_START_SEC_CONFIG_DATA_UNSPECIFIED

    #include "Sent_MemMap.h"
    #if (STD_ON == SENT_MULTICORE_SUPPORT)
        extern const Sent_ConfigType * const Sent_Config[SENT_MAX_PARTITIONS];
    #else
        extern const Sent_ConfigType Sent_Config;
    #endif
    #define SENT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    
    #include "Sent_MemMap.h"
#endif /* #if (SENT_PRECOMPILE_SUPPORT == STD_ON) */

#define SENT_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sent_MemMap.h"
#if (SENT_DEV_ERROR_DETECT == STD_ON)
/**
* @brief          Sent driver status variable.
* @details        Sent driver state machine.
*/
static Sent_DriverStatusType Sent_au8DriverStatus[SENT_MAX_PARTITIONS];
#endif
/**
* @brief          Global configuration pointer.
* @details        Pointer to the configuration structure.
*/
static const Sent_ConfigType * Sent_apxConfig[SENT_MAX_PARTITIONS];

#define SENT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sent_MemMap.h"


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define SENT_START_SEC_CODE

#include "Sent_MemMap.h"

/* Initializes the Sent module. This function performs software initialization of Sent driver:
*          - Maps logical channels to hardware channels
*          - Initializes all channels
*          - Sets driver state machine to SENT_INIT.
*/

/* @implements Sent_Init_Activity */
void Sent_Init(const Sent_ConfigType * Config)
{
    uint8   ControllerId;
    uint32  CoreId = 0;
    const Sent_ControllerConfigType *SentController;

    CoreId = Sent_GetCoreID();
#if (SENT_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the Sent driver is in Sent_UNINIT state */
    if (SENT_UNINIT != Sent_au8DriverStatus[CoreId])
    {
        /* Sent driver has been already initialized */
        (void)Det_ReportError((uint16)SENT_MODULE_ID, (uint8)0, (uint8)SENT_SID_INIT, (uint8)SENT_E_ALREADY_INITIALIZED);
    }
    else
    {
#if (SENT_PRECOMPILE_SUPPORT == STD_ON)
        if (NULL_PTR != Config)
 #else
        if (NULL_PTR == Config)
#endif /* SENT_PRECOMPILE_SUPPORT */
        {
            (void)Det_ReportError((uint16)SENT_MODULE_ID, (uint8)0, (uint8)SENT_SID_INIT, (uint8)SENT_E_INIT_FAILED);
        }
        else
#if (SENT_PRECOMPILE_SUPPORT == STD_ON)
    #if (SENT_MULTICORE_SUPPORT == STD_ON)
            if (NULL_PTR == Sent_Config[CoreId])
    #endif /* (SENT_MULTICORE_SUPPORT == STD_ON) */
#else
            if (CoreId != Config->CoreIDConfigured)
#endif /* SENT_PRECOMPILE_SUPPORT == STD_ON */
#if (SENT_PRECOMPILE_SUPPORT == STD_ON)
    #if (SENT_MULTICORE_SUPPORT == STD_ON)
            {
                (void)Det_ReportError((uint16)SENT_MODULE_ID, (uint8)0, (uint8)SENT_SID_INIT, (uint8)SENT_E_INIT_FAILED);
            }
            else
            {
    #else
            {
    #endif
#else
            {
                (void)Det_ReportError((uint16)SENT_MODULE_ID, (uint8)0, (uint8)SENT_SID_INIT, (uint8)SENT_E_INIT_FAILED);
            }
            else
            {
#endif
#endif /* SENT_DEV_ERROR_DETECT == STD_ON */

#if (SENT_PRECOMPILE_SUPPORT == STD_ON)
    #if (SENT_MULTICORE_SUPPORT == STD_ON)
                Sent_apxConfig[CoreId] = Sent_Config[CoreId];
    #else
                Sent_apxConfig[CoreId] = &Sent_Config;
    #endif /* (SENT_MULTICORE_SUPPORT == STD_ON) */
                (void)Config; /* Prevent Compiler warning */
#else
                Sent_apxConfig[CoreId] = Config;
#endif /* SENT_PRECOMPILE_SUPPORT == STD_ON */

                for(ControllerId=(uint8)0U; ControllerId < SENT_NUMBER_CONFIGURED_CONTROLLER; ControllerId++)
                {
                    SentController = Sent_apxConfig[CoreId]->ControllerConfig[ControllerId];
                    
                    if (NULL_PTR != SentController)
                    {
                        Sent_Ipw_ControllerInit(ControllerId, SentController->CtrlConfig);
#if (SENT_DEV_ERROR_DETECT == STD_ON)
                        Sent_au8ControllerInitStatus[ControllerId] = SENT_INIT;
#endif
                    }
                }
#if (SENT_DEV_ERROR_DETECT == STD_ON)
                /* Update Sent driver Status to Sent_INIT */
                Sent_au8DriverStatus[CoreId] = SENT_INIT;
            }
    }
#endif /* (SENT_DEV_ERROR_DETECT == STD_ON) */
}

/* DeInitializes the Sent module. */
/* @implements Sent_DeInit_Activity */
void Sent_DeInit(void)
{
    uint8 ControllerId;
    uint32 CoreId;
    const Sent_ControllerConfigType *SentController;

    CoreId = Sent_GetCoreID();

    /* Check whether the Sent driver is in SENT_UNINIT state */
#if (SENT_DEV_ERROR_DETECT == STD_ON)
    if (SENT_INIT != Sent_au8DriverStatus[CoreId])
    {
        /* Sent driver has been already uninitialized */
        (void)Det_ReportError((uint16)SENT_MODULE_ID, (uint8)0, (uint8)SENT_SID_DEINIT, (uint8)SENT_E_UNINIT);
    }
    else
    {
#endif /* (SENT_DEV_ERROR_DETECT == STD_ON) */
        for (ControllerId = 0; ControllerId < SENT_NUMBER_CONFIGURED_CONTROLLER; ControllerId++)
        {
            SentController = Sent_apxConfig[CoreId]->ControllerConfig[ControllerId];
            if (NULL_PTR != SentController)
            {
                Sent_Ipw_ControllerDeInit(ControllerId);
#if (SENT_DEV_ERROR_DETECT == STD_ON)
                Sent_au8ControllerInitStatus[ControllerId] = SENT_UNINIT;
#endif                
            }
        }
#if (SENT_DEV_ERROR_DETECT == STD_ON)
    /* Update Sent driver status to Sent_UNINIT */
    Sent_au8DriverStatus[CoreId] = SENT_UNINIT;
    }
#endif /* (SENT_DEV_ERROR_DETECT == STD_ON) */
}

/* This function processing polling of Fast notification. */
/* @implements Sent_GetFastChannelMsgData_Activity */
Std_ReturnType Sent_GetFastChannelMsgData(uint8 ControllerId, uint8 ChannelId)
{
#if (SENT_DEV_ERROR_DETECT == STD_ON)
    uint32  CoreId = 0;
#endif
    Std_ReturnType  RelVal = E_NOT_OK;
    
#if (SENT_DEV_ERROR_DETECT == STD_ON)
    CoreId = Sent_GetCoreID();

    /* Check whether the Sent driver is in Sent_INIT state */
    if (SENT_INIT != Sent_au8DriverStatus[CoreId])
    {
        /* Sent driver has not been initialized yet */
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)SENT_MODULE_ID, (uint8)ControllerId, (uint8)SENT_SID_GETFASTCHANNELMSGDATA, (uint8)SENT_E_UNINIT);
    }
    else
    {
        /* Check for invalid channel */
        if (ControllerId >= SENT_NUMBER_CONFIGURED_CONTROLLER)
        {
            /* Invalid channel */
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)SENT_MODULE_ID,(uint8)ControllerId,(uint8)SENT_SID_GETFASTCHANNELMSGDATA, (uint8)SENT_E_INVALID_CTRL);
        }
        else
        {
            if(Sent_au8ControllerInitStatus[ControllerId] == SENT_UNINIT)
            {
                (void)Det_ReportError((uint16)SENT_MODULE_ID, (uint8)ControllerId, (uint8)SENT_SID_GETFASTCHANNELMSGDATA, (uint8)SENT_E_CTRL_UNINIT);
            }
            else
            {
                /* Check for invalid channel */
                if (ChannelId >= Sent_au8NumberChannel[ControllerId])
                {
                    /* Invalid channel */
                    /* Report error to development error tracer */
                    (void)Det_ReportError((uint16)SENT_MODULE_ID,(uint8)ControllerId, (uint8)SENT_SID_GETFASTCHANNELMSGDATA, (uint8)SENT_E_INVALID_CHANNEL);
                }
                else
                {
#endif
                RelVal = Sent_Ipw_GetFastChannelMsgData(ControllerId, ChannelId);
#if (SENT_DEV_ERROR_DETECT == STD_ON)
                }
            }
        }
    }
#endif /* (SENT_DEV_ERROR_DETECT == STD_ON) */
    return RelVal;
}

/* This function processing polling of Fast notification. */
/* @implements Sent_GetFastMsgData_Activity */
Std_ReturnType Sent_GetFastMsgData(uint8 ControllerId)
{
#if (SENT_DEV_ERROR_DETECT == STD_ON)
    uint32  CoreId = 0;
#endif
    Std_ReturnType  RelVal = E_NOT_OK;

#if (SENT_DEV_ERROR_DETECT == STD_ON)
    CoreId = Sent_GetCoreID();

    /* Check whether the Sent driver is in Sent_INIT state */
    if (SENT_INIT != Sent_au8DriverStatus[CoreId])
    {
        /* Sent driver has not been initialized yet */
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)SENT_MODULE_ID, (uint8)ControllerId, (uint8)SENT_SID_GETFASTMSGDATA, (uint8)SENT_E_UNINIT);
    }
    else
    {
        /* Check for invalid channel */
        if (ControllerId >= SENT_NUMBER_CONFIGURED_CONTROLLER)
        {
            /* Invalid channel */
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)SENT_MODULE_ID,(uint8)ControllerId,(uint8)SENT_SID_GETFASTMSGDATA, (uint8)SENT_E_INVALID_CTRL);
        }
        else
        {
            if(Sent_au8ControllerInitStatus[ControllerId] == SENT_UNINIT)
            {
                (void)Det_ReportError((uint16)SENT_MODULE_ID, (uint8)ControllerId, (uint8)SENT_SID_GETFASTMSGDATA, (uint8)SENT_E_CTRL_UNINIT);
            }
            else
            {
#endif
        RelVal = Sent_Ipw_GetFastMsgData(ControllerId);
#if (SENT_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
#endif /* (SENT_DEV_ERROR_DETECT == STD_ON) */
    return RelVal;
}

/* This function processing polling of Serial notification. */
/* @implements  Sent_GetSerialChannelMsgData_Activity */
Std_ReturnType Sent_GetSerialChannelMsgData(uint8 ControllerId, uint8 ChannelId)
{
#if (SENT_DEV_ERROR_DETECT == STD_ON)
    uint32  CoreId = 0;
#endif
    Std_ReturnType  RelVal = E_NOT_OK;
    
#if (SENT_DEV_ERROR_DETECT == STD_ON)
    CoreId = Sent_GetCoreID();

    /* Check whether the Sent driver is in Sent_INIT state */
    if (SENT_INIT != Sent_au8DriverStatus[CoreId])
    {
        /* Sent driver has not been initialized yet */
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)SENT_MODULE_ID, (uint8)ControllerId, (uint8)SENT_SID_GETSERIALCHANNELMSGDATA, (uint8)SENT_E_UNINIT);
    }
    else
    {
        /* Check for invalid channel */
        if (ControllerId >= SENT_NUMBER_CONFIGURED_CONTROLLER)
        {
            /* Invalid channel */
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)SENT_MODULE_ID,(uint8)ControllerId,(uint8)SENT_SID_GETSERIALCHANNELMSGDATA, (uint8)SENT_E_INVALID_CTRL);
        }
        else
        {
            if(Sent_au8ControllerInitStatus[ControllerId] == SENT_UNINIT)
            {
                (void)Det_ReportError((uint16)SENT_MODULE_ID, (uint8)ControllerId, (uint8)SENT_SID_GETSERIALCHANNELMSGDATA, (uint8)SENT_E_CTRL_UNINIT);
            }
            else
            {
                /* Check for invalid channel */
                if (ChannelId >= Sent_au8NumberChannel[ControllerId])
                {
                    /* Invalid channel */
                    /* Report error to development error tracer */
                    (void)Det_ReportError((uint16)SENT_MODULE_ID,(uint8)ControllerId,(uint8)SENT_SID_GETSERIALCHANNELMSGDATA, (uint8)SENT_E_INVALID_CHANNEL);
                }
                else
                {
#endif
            RelVal = Sent_Ipw_GetSerialChannelMsgData(ControllerId, ChannelId);
#if (SENT_DEV_ERROR_DETECT == STD_ON)
                }
            }
        }
    }
#endif /* (SENT_DEV_ERROR_DETECT == STD_ON) */
    return RelVal;
}

/*  This function processing polling of Serial notification. */
/* @implements       Sent_GetSerialMsgData_Activity */
Std_ReturnType Sent_GetSerialMsgData(uint8 ControllerId)
{
#if (SENT_DEV_ERROR_DETECT == STD_ON)
    uint32  CoreId = 0;
#endif
    Std_ReturnType  RelVal = E_NOT_OK;

#if (SENT_DEV_ERROR_DETECT == STD_ON)
    CoreId = Sent_GetCoreID();

    /* Check whether the Sent driver is in Sent_INIT state */
    if (SENT_INIT != Sent_au8DriverStatus[CoreId])
    {
        /* Sent driver has not been initialized yet */
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)SENT_MODULE_ID, (uint8)ControllerId, (uint8)SENT_SID_GETSERIALMSGDATA, (uint8)SENT_E_UNINIT);
    }
    else
    {
        /* Check for invalid channel */
        if (ControllerId >= SENT_NUMBER_CONFIGURED_CONTROLLER)
        {
            /* Invalid channel */
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)SENT_MODULE_ID,(uint8)ControllerId,(uint8)SENT_SID_GETSERIALMSGDATA, (uint8)SENT_E_INVALID_CTRL);
        }
        else
        {
            if(Sent_au8ControllerInitStatus[ControllerId] == SENT_UNINIT)
            {
                (void)Det_ReportError((uint16)SENT_MODULE_ID, (uint8)ControllerId, (uint8)SENT_SID_GETSERIALMSGDATA, (uint8)SENT_E_CTRL_UNINIT);
            }
            else
            {
#endif
        RelVal = Sent_Ipw_GetSerialMsgData(ControllerId);
#if (SENT_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
#endif /* (SENT_DEV_ERROR_DETECT == STD_ON) */
    return RelVal;
}
/* @implements       Sent_StartChannelReceiving_Activity */
Std_ReturnType Sent_StartChannelReceiving(uint8 ControllerId, uint8 ChannelId)
{
#if (SENT_DEV_ERROR_DETECT == STD_ON)
    uint32  CoreId = 0;
#endif
    Std_ReturnType  RelVal = E_NOT_OK;
    
#if (SENT_DEV_ERROR_DETECT == STD_ON)
    CoreId = Sent_GetCoreID();

    /* Check whether the Sent driver is in Sent_INIT state */
    if (SENT_INIT != Sent_au8DriverStatus[CoreId])
    {
        /* Sent driver has not been initialized yet */
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)SENT_MODULE_ID, (uint8)ControllerId, (uint8)SENT_SID_STARTCHANNELRECEIVING, (uint8)SENT_E_UNINIT);
    }
    else
    {
        /* Check for invalid channel */
        if (ControllerId >= SENT_NUMBER_CONFIGURED_CONTROLLER)
        {
            /* Invalid channel */
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)SENT_MODULE_ID,(uint8)ControllerId,(uint8)SENT_SID_STARTCHANNELRECEIVING, (uint8)SENT_E_INVALID_CTRL);
        }
        else
        {
            if(Sent_au8ControllerInitStatus[ControllerId] == SENT_UNINIT)
            {
                (void)Det_ReportError((uint16)SENT_MODULE_ID, (uint8)ControllerId, (uint8)SENT_SID_STARTCHANNELRECEIVING, (uint8)SENT_E_CTRL_UNINIT);
            }
            else
            {
                /* Check for invalid channel */
                if (ChannelId >= Sent_au8NumberChannel[ControllerId])
                {
                    /* Invalid channel */
                    /* Report error to development error tracer */
                    (void)Det_ReportError((uint16)SENT_MODULE_ID,(uint8)ControllerId, (uint8)SENT_SID_STARTCHANNELRECEIVING, (uint8)SENT_E_INVALID_CHANNEL);
                }
                else
                {
#endif
                RelVal = Sent_Ipw_StartChannelReceiving(ControllerId, ChannelId);
#if (SENT_DEV_ERROR_DETECT == STD_ON)
                }
            }
        }
    }
#endif /* (SENT_DEV_ERROR_DETECT == STD_ON) */
    return RelVal;
}
/* @implements       Sent_StopChannelReceiving_Activity */
Std_ReturnType Sent_StopChannelReceiving(uint8 ControllerId, uint8 ChannelId)
{
#if (SENT_DEV_ERROR_DETECT == STD_ON)
    uint32  CoreId = 0;
#endif
    Std_ReturnType  RelVal = E_NOT_OK;
    
#if (SENT_DEV_ERROR_DETECT == STD_ON)
    CoreId = Sent_GetCoreID();

    /* Check whether the Sent driver is in Sent_INIT state */
    if (SENT_INIT != Sent_au8DriverStatus[CoreId])
    {
        /* Sent driver has not been initialized yet */
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)SENT_MODULE_ID, (uint8)ControllerId, (uint8)SENT_SID_STOPCHANNELRECEIVING, (uint8)SENT_E_UNINIT);
    }
    else
    {
        /* Check for invalid channel */
        if (ControllerId >= SENT_NUMBER_CONFIGURED_CONTROLLER)
        {
            /* Invalid channel */
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)SENT_MODULE_ID,(uint8)ControllerId,(uint8)SENT_SID_STOPCHANNELRECEIVING, (uint8)SENT_E_INVALID_CTRL);
        }
        else
        {
            if(Sent_au8ControllerInitStatus[ControllerId] == SENT_UNINIT)
            {
                (void)Det_ReportError((uint16)SENT_MODULE_ID, (uint8)ControllerId, (uint8)SENT_SID_STOPCHANNELRECEIVING, (uint8)SENT_E_CTRL_UNINIT);
            }
            else
            {
                /* Check for invalid channel */
                if (ChannelId >= Sent_au8NumberChannel[ControllerId])
                {
                    /* Invalid channel */
                    /* Report error to development error tracer */
                    (void)Det_ReportError((uint16)SENT_MODULE_ID,(uint8)ControllerId, (uint8)SENT_SID_STOPCHANNELRECEIVING, (uint8)SENT_E_INVALID_CHANNEL);
                }
                else
                {
#endif
                RelVal = Sent_Ipw_StopChannelReceiving(ControllerId, ChannelId);
#if (SENT_DEV_ERROR_DETECT == STD_ON)
                }
            }
        }
    }
#endif /* (SENT_DEV_ERROR_DETECT == STD_ON) */
    return RelVal;
}

/* @implements       Sent_GetVersionInfo_Activity */
#if (SENT_VERSION_INFO_API == STD_ON)
/*  Returns the version information of this module. */
void Sent_GetVersionInfo (Std_VersionInfoType * VersionInfo)
{
#if(SENT_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == VersionInfo)
    {
        (void)Det_ReportError((uint16)SENT_MODULE_ID, (uint8)0, (uint8)SENT_SID_GETVERSIONINFO, (uint8) SENT_E_INVALID_POINTER);
    }
    else
    {
#endif /* SENT_DEV_ERROR_DETECT == STD_ON */
        (VersionInfo)->vendorID = (uint16) SENT_VENDOR_ID;
        (VersionInfo)->moduleID = (uint16) SENT_MODULE_ID;
        (VersionInfo)->sw_major_version = (uint8) SENT_SW_MAJOR_VERSION;
        (VersionInfo)->sw_minor_version = (uint8) SENT_SW_MINOR_VERSION;
        (VersionInfo)->sw_patch_version = (uint8) SENT_SW_PATCH_VERSION;
#if(SENT_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* SENT_DEV_ERROR_DETECT == STD_ON */
}
#endif /* SENT_VERSION_INFO_API == STD_ON */

#define SENT_STOP_SEC_CODE

#include "Sent_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
