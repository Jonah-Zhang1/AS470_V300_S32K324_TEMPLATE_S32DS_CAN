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
*   @file    Sent_Ipw.c
*   @version 3.0.0
*
*   @brief   AUTOSAR Sent - Isolation level file for Sent driver.
*   @details Implementation file for function definition on isolation level between high and low level driver.
*
*   @addtogroup SENT_DRIVER
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
#include "Sent_Ipw.h"
#include "Flexio_Sent_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/


#define SENT_IPW_VENDOR_ID_C                    43
#define SENT_IPW_AR_RELEASE_MAJOR_VERSION_C     4
#define SENT_IPW_AR_RELEASE_MINOR_VERSION_C     7
#define SENT_IPW_AR_RELEASE_REVISION_VERSION_C  0
#define SENT_IPW_SW_MAJOR_VERSION_C             3
#define SENT_IPW_SW_MINOR_VERSION_C             0
#define SENT_IPW_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Sent_Ipw header file are of the same vendor */
#if (SENT_IPW_VENDOR_ID_C != SENT_IPW_VENDOR_ID)
    #error "Sent_Ipw.h and Sent_Ipw.c have different vendor ids"
#endif
/* Check if current file and Sent_Ipw header file are of the same Autosar version */
#if ((SENT_IPW_AR_RELEASE_MAJOR_VERSION_C    != SENT_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (SENT_IPW_AR_RELEASE_MINOR_VERSION_C    != SENT_IPW_AR_RELEASE_MINOR_VERSION) || \
     (SENT_IPW_AR_RELEASE_REVISION_VERSION_C != SENT_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Sent_Ipw.h and Sent_Ipw.c are different"
#endif
/* Check if current file and Sent_Ipw header file are of the same Software version */
#if ((SENT_IPW_SW_MAJOR_VERSION_C != SENT_IPW_SW_MAJOR_VERSION) || \
     (SENT_IPW_SW_MINOR_VERSION_C != SENT_IPW_SW_MINOR_VERSION) || \
     (SENT_IPW_SW_PATCH_VERSION_C != SENT_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Sent_Ipw.h and Sent_Ipw.c are different"
#endif

/* Check if current file and Flexio_Sent_Ip header file are of the same vendor */
#if (SENT_IPW_VENDOR_ID_C != FLEXIO_SENT_IP_VENDOR_ID)
   #error "Flexio_Sent_Ip.h and Sent_Ipw.c have different vendor ids"
#endif
/* Check if current file and Flexio_Sent_Ip header file are of the same Autosar version */
#if ((SENT_IPW_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_SENT_IP_AR_RELEASE_MAJOR_VERSION) || \
     (SENT_IPW_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_SENT_IP_AR_RELEASE_MINOR_VERSION) || \
     (SENT_IPW_AR_RELEASE_REVISION_VERSION_C != FLEXIO_SENT_IP_AR_RELEASE_REVISION_VERSION) \
    )
   #error "AutoSar Version Numbers of Flexio_Sent_Ip.h and Sent_Ipw.c are different"
#endif
/* Check if current file and Flexio_Sent_Ip header file are of the same Software version */
#if ((SENT_IPW_SW_MAJOR_VERSION_C != FLEXIO_SENT_IP_SW_MAJOR_VERSION) || \
     (SENT_IPW_SW_MINOR_VERSION_C != FLEXIO_SENT_IP_SW_MINOR_VERSION) || \
     (SENT_IPW_SW_PATCH_VERSION_C != FLEXIO_SENT_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Flexio_Sent_Ip.h and Sent_Ipw.c are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
const Flexio_CtrlConfigType * Flexio_Sent_Ip_apControllerConfig[FEATURE_FLEXIO_INSTANCE_COUNT];
/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
===================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#define SENT_START_SEC_CODE

#include "Sent_MemMap.h"

/**
* @brief   Initialize a Sent channel.
* @details This function initializes all hardware registers needed to
*          start the Sent functionality on the selected channel.
*
* @param[in]        ControllerId: The Id of controller
*                   pConfigPtr Configuration pointer containing hardware specific settings.
*
* @return            void.
* @am: OK
*  
*/
void Sent_Ipw_ControllerInit(uint8 ControllerId, const Sent_Ipw_CtrlConfigType *IpwController)
{
    (void)Flexio_Sent_Ip_Init(IpwController->CtrlConfig->CtrHwOffset, IpwController->CtrlConfig);
    Flexio_Sent_Ip_apControllerConfig[ControllerId] = IpwController->CtrlConfig;
}

/**
* @brief   De initialize a Sent channel.
* @details This function de initializes the hardware registers of an Sent channel
*
* @param[in]        ControllerId: The Id of controller
*            pConfigPtr    Configuration pointer containing hardware specific settings.
*
* @return            void.
* @am:  OK
*/
void Sent_Ipw_ControllerDeInit(uint8 ControllerId)
{
    Flexio_Sent_Ip_DeInit(Flexio_Sent_Ip_apControllerConfig[ControllerId]->CtrHwOffset);
    Flexio_Sent_Ip_apControllerConfig[ControllerId] = NULL_PTR;
}

/**
* @brief            This function processing polling of Fast notification.
* @details 
*
* @param[in]        ControllerId: The Id of controller
* @param[in]        ChannelId: The Id of channel
* @return           E_OK:   Channel request has been accepted.
*                   E_NOT_OK:   Channel request has not been accepted.
*
*/
Std_ReturnType Sent_Ipw_GetFastChannelMsgData(uint8 ControllerId, uint8 ChannelId)
{
    Std_ReturnType RelVal;

    if(STATUS_FLEXIO_SENT_IP_SUCCESS == (Flexio_Sent_Ip_StatusType)Flexio_Sent_Ip_GetFastChannelMsgData(Flexio_Sent_Ip_apControllerConfig[ControllerId]->CtrHwOffset, ChannelId))
    {
        RelVal = E_OK;
    }
    else
    {
        RelVal = E_NOT_OK;
    }

    return (Std_ReturnType)RelVal;
}

/**
* @brief            This function processing polling of Fast notification.
* @details 
*
* @param[in]        ControllerId: The Id of controller
* @return           E_OK:   Channel request has been accepted.
*                   E_NOT_OK:   Channel request has not been accepted.
*
*/
Std_ReturnType Sent_Ipw_GetFastMsgData(uint8 ControllerId)
{
    Std_ReturnType RelVal;

    if(STATUS_FLEXIO_SENT_IP_SUCCESS == (Flexio_Sent_Ip_StatusType)Flexio_Sent_Ip_GetFastMsgData(ControllerId))
    {
        RelVal = E_OK;
    }
    else
    {
        RelVal = E_NOT_OK;
    }
    
    return (Std_ReturnType)RelVal;
}

/**
* @brief            This function processing polling of Fast notification.
* @details 
*
* @param[in]        ControllerId: The Id of controller
* @param[in]        ChannelId: The Id of channel
* @return           E_OK:   Channel request has been accepted.
*                   E_NOT_OK:   Channel request has not been accepted.
*
*/
Std_ReturnType Sent_Ipw_GetSerialChannelMsgData(uint8 ControllerId, uint8 ChannelId)
{
    Std_ReturnType RelVal;

    if(STATUS_FLEXIO_SENT_IP_SUCCESS == (Flexio_Sent_Ip_StatusType)Flexio_Sent_Ip_GetSerialChannelMsgData(Flexio_Sent_Ip_apControllerConfig[ControllerId]->CtrHwOffset, ChannelId))
    {
        RelVal = E_OK;
    }
    else
    {
        RelVal = E_NOT_OK;
    }

    return (Std_ReturnType)RelVal;
}

/**
* @brief            This function processing polling of Fast notification.
* @details 
*
* @param[in]        ControllerId: The Id of controller
* @return           E_OK:   Channel request has been accepted.
*                   E_NOT_OK:   Channel request has not been accepted.
*
*/
Std_ReturnType Sent_Ipw_GetSerialMsgData(uint8 ControllerId)
{
    Std_ReturnType RelVal;

    if(STATUS_FLEXIO_SENT_IP_SUCCESS == (Flexio_Sent_Ip_StatusType)Flexio_Sent_Ip_GetSerialMsgData(ControllerId))
    {
        RelVal = E_OK;
    }
    else
    {
        RelVal = E_NOT_OK;
    }
    
    return (Std_ReturnType)RelVal;
}
/**
* @brief            This is a dummy function to start receiving data from SENT bus.
* @details
*
* @param[in]        ControllerId: The Id of controller
* @param[in]        ChannelId: The Id of channel
* @return           E_OK:   Channel request has been accepted.
*                   E_NOT_OK:   Channel request has not been accepted.
*
*/
Std_ReturnType Sent_Ipw_StartChannelReceiving(uint8 ControllerId, uint8 ChannelId)
{
    Std_ReturnType RelVal;

    if(STATUS_FLEXIO_SENT_IP_SUCCESS == (Flexio_Sent_Ip_StatusType)Flexio_Sent_Ip_StartChannelReceiving(ControllerId, ChannelId))
    {
        RelVal = E_OK;
    }
    else
    {
        RelVal = E_NOT_OK;
    }
    return RelVal;
}
/**
* @brief            This is a dummy function to stop receiving data from SENT bus.
* @details
*
* @param[in]        ControllerId: The Id of controller
* @param[in]        ChannelId: The Id of channel
* @return           E_OK:   Channel request has been accepted.
*                   E_NOT_OK:   Channel request has not been accepted.
*
*/
Std_ReturnType Sent_Ipw_StopChannelReceiving(uint8 ControllerId, uint8 ChannelId)
{
    Std_ReturnType RelVal;

    if(STATUS_FLEXIO_SENT_IP_SUCCESS == (Flexio_Sent_Ip_StatusType)Flexio_Sent_Ip_StopChannelReceiving(ControllerId, ChannelId))
    {
        RelVal = E_OK;
    }
    else
    {
        RelVal = E_NOT_OK;
    }
    return RelVal;
}
#define SENT_STOP_SEC_CODE

#include "Sent_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
