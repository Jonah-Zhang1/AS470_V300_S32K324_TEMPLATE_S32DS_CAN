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

#ifndef SENT_IPW_H
#define SENT_IPW_H

/**
*   @file    Sent_Ipw.h
*   @version 1.0.3
*
*   @brief   AUTOSAR Sent - Isolation level header file for Sent driver.
*   @details Header file for function definition on isolation level between high and low level driver.
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
#include "Sent_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SENT_IPW_VENDOR_ID                    43
#define SENT_IPW_AR_RELEASE_MAJOR_VERSION     4
#define SENT_IPW_AR_RELEASE_MINOR_VERSION     7
#define SENT_IPW_AR_RELEASE_REVISION_VERSION  0
#define SENT_IPW_SW_MAJOR_VERSION             3
#define SENT_IPW_SW_MINOR_VERSION             0
#define SENT_IPW_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Sent_Types header file are of the same vendor */
#if (SENT_TYPES_VENDOR_ID != SENT_IPW_VENDOR_ID)
    #error "Sent_Ipw.h and Sent_Types.h have different vendor ids"
#endif
/* Check if current file and Sent_Types header file are of the same Autosar version */
#if ((SENT_TYPES_AR_RELEASE_MAJOR_VERSION       != SENT_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (SENT_TYPES_AR_RELEASE_MINOR_VERSION       != SENT_IPW_AR_RELEASE_MINOR_VERSION) || \
     (SENT_TYPES_AR_RELEASE_REVISION_VERSION    != SENT_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Sent_Ipw.h and Sent_Types.h are different"  
#endif
/* Check if current file and Sent_Types header file are of the same Software version */
#if ((SENT_TYPES_SW_MAJOR_VERSION != SENT_IPW_SW_MAJOR_VERSION) || \
     (SENT_TYPES_SW_MINOR_VERSION != SENT_IPW_SW_MINOR_VERSION) || \
     (SENT_TYPES_SW_PATCH_VERSION != SENT_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Sent_Ipw.h and Sent_Types.h are different" 
#endif
/*==================================================================================================
*                                          CONSTANTS
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
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
/**
 * @brief Initialize the Sent driver
 */
void Sent_Ipw_ControllerInit(uint8 ControllerId, const Sent_Ipw_CtrlConfigType *IpwController);
/**
 * @brief DeInitializes the Sent module.
 */
void Sent_Ipw_ControllerDeInit(uint8 ControllerId);
/**
 * @brief This function processing polling of Fast notification
 */
Std_ReturnType Sent_Ipw_GetFastChannelMsgData(uint8 ControllerId, uint8 ChannelId);
/**
 * @brief This function gets Fast message data for all channel.
 */
Std_ReturnType Sent_Ipw_GetFastMsgData(uint8 ControllerId);
/**
* @brief            This function processing polling of Serial notification.
*/
Std_ReturnType Sent_Ipw_GetSerialChannelMsgData(uint8 ControllerId, uint8 ChannelId);
/**
* @brief            This function gets Serial message data for all channel.
*/
Std_ReturnType Sent_Ipw_GetSerialMsgData(uint8 ControllerId);
/**
* @brief            This function starts to receive data from SENT bus.
*/
Std_ReturnType Sent_Ipw_StartChannelReceiving(uint8 ControllerId, uint8 ChannelId);

/**
* @brief            This function stops to receive data from SENT bus.
*/
Std_ReturnType Sent_Ipw_StopChannelReceiving(uint8 ControllerId, uint8 ChannelId);
#define SENT_STOP_SEC_CODE

#include "Sent_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SENT_IPW_H */
