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

#ifndef CDD_SENT_H
#define CDD_SENT_H

/**
*   @file    CDD_Sent.h
*   @version 3.0.0
*
*   @brief   AUTOSAR Sent - High level header of Sent driver.
*   @details This file contains declarations of the functions defined by AutoSAR.
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

#include "Mcal.h"
#include "Sent_Types.h"
#include "Sent_Cfg.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SENT_MODULE_ID                      125
#define SENT_VENDOR_ID                      43
#define SENT_AR_RELEASE_MAJOR_VERSION       4
#define SENT_AR_RELEASE_MINOR_VERSION       7
#define SENT_AR_RELEASE_REVISION_VERSION    0
#define SENT_SW_MAJOR_VERSION               3
#define SENT_SW_MINOR_VERSION               0
#define SENT_SW_PATCH_VERSION               0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Sent_Cfg header file are of the same vendor */
#if (SENT_VENDOR_ID != SENT_CFG_VENDOR_ID)
#endif
/* Check if current file and Sent_Cfg header file are of the same Autosar version */
#if ((SENT_AR_RELEASE_MAJOR_VERSION    != SENT_CFG_AR_RELEASE_MAJOR_VERSION) || \
       (SENT_AR_RELEASE_MINOR_VERSION    != SENT_CFG_AR_RELEASE_MINOR_VERSION) || \
       (SENT_AR_RELEASE_REVISION_VERSION != SENT_CFG_AR_RELEASE_REVISION_VERSION) \
    )
#endif
/* Check if current file and Sent_Cfg header file are of the same Software version */
#if ((SENT_SW_MAJOR_VERSION != SENT_CFG_SW_MAJOR_VERSION) || \
      (SENT_SW_MINOR_VERSION != SENT_CFG_SW_MINOR_VERSION) || \
      (SENT_SW_PATCH_VERSION != SENT_CFG_SW_PATCH_VERSION)    \
    )
#endif

/* Check if current file and Sent_Types header file are of the same vendor */
#if (SENT_VENDOR_ID != SENT_TYPES_VENDOR_ID)
#endif
/* Check if current file and Sent_Types header file are of the same Autosar version */
#if ((SENT_AR_RELEASE_MAJOR_VERSION    != SENT_TYPES_AR_RELEASE_MAJOR_VERSION) || \
       (SENT_AR_RELEASE_MINOR_VERSION    != SENT_TYPES_AR_RELEASE_MINOR_VERSION) || \
       (SENT_AR_RELEASE_REVISION_VERSION != SENT_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
#endif
/* Check if current file and Sent_Types header file are of the same Software version */
#if ((SENT_SW_MAJOR_VERSION != SENT_TYPES_SW_MAJOR_VERSION) || \
      (SENT_SW_MINOR_VERSION != SENT_TYPES_SW_MINOR_VERSION) || \
      (SENT_SW_PATCH_VERSION != SENT_TYPES_SW_PATCH_VERSION)    \
    )
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((SENT_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
          (SENT_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION)    \
        )
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#if (SENT_DEV_ERROR_DETECT == STD_ON)

/**
* @brief            API service used without module initialization
* @details          The Sent Driver module shall report the development error "Sent_E_UNINIT (0x01)", 
*                   when the API Service is used without module initialization.
*/
#define SENT_E_UNINIT            ((uint8)0x01U)

/**
* @brief            API service used with an invalid or inactive channel parameter
* @details          The Sent Driver module shall report the development error 
*                   "Sent_E_INVALID_CHANNEL (0x02)", when API Service used with 
*                   an invalid or inactive channel parameter.
*/

#define SENT_E_INVALID_CHANNEL   ((uint8)0x02U)

/**
* @brief            API service called with invalid configuration pointer
* @details          The Sent Driver module shall report the development error 
*                   "Sent_E_INVALID_POINTER (0x03)", when API Service is called 
*                   with invalid configuration pointer.
* 
* @api
*/
#define SENT_E_INVALID_POINTER   ((uint8)0x03U)

/**
* @brief            Initialization called when already initialized
* @details          The Sent Driver module shall report the development error 
*                   "Sent_E_ALREADY_INITIALIZED (0x04)", when initialization is called 
*                   when the driver is already initialized.
* 
* @api
*/
#define SENT_E_ALREADY_INITIALIZED  ((uint8)0x04U)

/**
* @brief            API service called with Invalid configuration set selection
* @details          The Sent Driver module shall report the development error 
*                   "SENT_E_INIT_FAILED (0x05)", when API Service is called 
*                   with invalid configuration set selection.
* 
* @api
*/
#define SENT_E_INIT_FAILED  ((uint8)0x05U)

/**
* @brief            API service used without controller initialization
* @details          The Sent Driver module shall report the development error "SENT_E_CTRL_UNINIT (0x06)", 
*                   when the API Service is used without controller initialization.
*/
#define SENT_E_CTRL_UNINIT            ((uint8)0x06U)
#endif

/**
* @brief            API service used with an invalid or inactive channel parameter
* @details          The Sent Driver module shall report the development error 
*                   "SENT_E_INVALID_CTRL (0x07)", when API Service used with 
*                   an invalid or inactive channel parameter.
*/

#define SENT_E_INVALID_CTRL   ((uint8)0x07U)
/**
* @brief          Service ID (APIs) for Det reporting
* @details        Service ID (APIs) for Det reporting
*
*/
#define SENT_SID_DEINIT                         ((uint8)0x01U)
/**
* @brief          Service ID (APIs) for Det reporting
* @details        Service ID (APIs) for Det reporting
*
*/
#define SENT_SID_INIT                           ((uint8)0x02U)
/**
* @brief          Service ID (APIs) for Det reporting
* @details        Service ID (APIs) for Det reporting
*
*/
#define SENT_SID_GETFASTCHANNELMSGDATA          ((uint8)0x03U)
/**
* @brief          Service ID (APIs) for Det reporting
* @details        Service ID (APIs) for Det reporting
*
*/
#define SENT_SID_GETSERIALCHANNELMSGDATA        ((uint8)0x04U)
/**
* @brief          Service ID (APIs) for Det reporting
* @details        Service ID (APIs) for Det reporting
*
*/
#define SENT_SID_GETFASTMSGDATA                 ((uint8)0x05U)
#define SENT_SID_GETSERIALMSGDATA               ((uint8)0x06U)
#define SENT_SID_STARTCHANNELRECEIVING          ((uint8)0x07U)
#define SENT_SID_STOPCHANNELRECEIVING           ((uint8)0x08U)
#define SENT_SID_GETVERSIONINFO                 ((uint8)0x09U)

/**
* @brief Maximum number of nibbles configurable by user according user manual
*/
#define     SENT_MAX_NIBBLE_DATA            ((uint8) 0x06U)
/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define SENT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sent_MemMap.h"

#if STD_OFF == SENT_PRECOMPILE_SUPPORT
SENT_CONFIG_EXT
#endif

#define SENT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sent_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define SENT_START_SEC_CODE

#include "Sent_MemMap.h"

/* to be completed after .c file */
/**
 * @brief Initialize the Sent driver
 *
 * @details This function performs software initialization of Sent driver:
 *          - Maps logical channels to hardware channels
 *          - Initializes all channels
 *          - Sets driver state machine to SENT_INIT.
 *
 * @param Config Pointer to the Sent configuration structure. The function
 *                  reads configuration data from this structure and initializes the
 *                  driver accordingly. The application may free this structure after
 *                  the function returns
 * @return          Error or success Status returned by API
 * 
 * @api
 *
 *
 * @note    Service ID: 0x02.
 * @note    Synchronous, non re-entrant function.
 *
*/
void            Sent_Init(const Sent_ConfigType *Config);

/**
* @brief   DeInitializes the Sent module.
* @details This function performs software de initialization of Sent modules to reset values.
*          The service influences only the peripherals, which are allocated by static
*          configuration and the runtime configuration set passed by the previous call of Sent_Init()
*          The driver needs to be initialized before calling Sent_DeInit(). Otherwise, the
*          function Sent_DeInit shall raise the development error SENT_UNINIT and leave the desired
*          de initialization functionality without any action.
*
* @param[in] void
*
* @return  void
*
* @api
*
*
* @note    Service ID: 0x01.
* @note    Synchronous, non re-entrant function.
*
*/
void            Sent_DeInit(void);

/**
* @brief            This function processing polling of Fast notification.
* @details          This function gets Fast message data for a channel.
*
* @param[in]        ControllerId: The Id of controller
* @param[in]        ChannelId: The Id of channel
* @return           E_OK:   Channel request has been accepted.
*                   E_NOT_OK:   Channel request has not been accepted.
*
*
* @note             Service ID: 0x03.
* @note             Synchronous, non reentrant function.
*/
Std_ReturnType Sent_GetFastChannelMsgData(uint8 ControllerId, uint8 ChannelId);


/**
* @brief            This function processing polling of Fast notification.
* @details          This function gets Fast message data for all channel.
*
* @param[in]        ControllerId: The Id of controller
* @return           E_OK:   Channel request has been accepted.
*                   E_NOT_OK:   Channel request has not been accepted.
*
*
* @note             Service ID: 0x05.
* @note             Synchronous, non reentrant function.
*/
Std_ReturnType Sent_GetFastMsgData(uint8 ControllerId);

/**
* @brief            This function processing polling of Serial notification.
* @details          This function gets Serial message data for a channel.
*
* @param[in]        ControllerId: The Id of controller
* @param[in]        ChannelId: The Id of channel
* @return           E_OK:   Channel request has been accepted.
*                   E_NOT_OK:   Channel request has not been accepted.
*
*
* @note             Service ID: 0x04.
* @note             Synchronous, non reentrant function.
*/
Std_ReturnType Sent_GetSerialChannelMsgData(uint8 ControllerId, uint8 ChannelId);

/**
* @brief            This function processing polling of Serial notification.
* @details          This function gets Serial message data for all channel.
*
* @param[in]        ControllerId: The Id of controller
* @return           E_OK:   Channel request has been accepted.
*                   E_NOT_OK:   Channel request has not been accepted.
*
*
* @note             Service ID: 0x06.
* @note             Synchronous, non reentrant function.
*/
Std_ReturnType Sent_GetSerialMsgData(uint8 ControllerId);

/**
* @brief            This function starts to receive data from SENT bus.
* @details          This function starts to receive data from SENT bus.
*
* @param[in]        ControllerId: The Id of controller
* @param[in]        ChannelId: The Id of channel
* @return           E_OK:   Channel request has been accepted.
*                   E_NOT_OK:   Channel request has not been accepted.
*
*
* @note             Service ID: 0x07.
* @note             Synchronous, non reentrant function.
*/
Std_ReturnType Sent_StartChannelReceiving(uint8 ControllerId, uint8 ChannelId);

/**
* @brief            This function stops to receive data from SENT bus.
* @details          This function stops to receive data from SENT bus.
*
* @param[in]        ControllerId: The Id of controller
* @param[in]        ChannelId: The Id of channel
* @return           E_OK:   Channel request has been accepted.
*                   E_NOT_OK:   Channel request has not been accepted.
*
* @note             Service ID: 0x08.
* @note             Synchronous, non reentrant function.
*/
Std_ReturnType Sent_StopChannelReceiving(uint8 ControllerId, uint8 ChannelId);

#if (SENT_VERSION_INFO_API == STD_ON)
/**
* @brief   Returns the version information of this module.
* @details The version information includes:
*
*          - Two bytes for the Vendor ID
*          - Two bytes for the Module ID
*          - One byte  for the Instance ID
*          - Three bytes version number. The numbering shall be vendor
*            specific: it consists of:
*
*             - The major, the minor and the patch version number of
*               the module;
*             - The AUTOSAR specification version number shall not
*               be included. The AUTOSAR specification version number is
*               checked during compile time and therefore not required
*               in this API.
*
* @param[in,out] VersionInfo   Pointer for storing the version information
*                               of this module.
*
* @return                  void.
*
* @api
*
*
* @pre            Preconditions as text description. Optional tag.
*
* @note    Service ID: 0x09.
* @note    Synchronous, re-entrant function.
*
*/
void Sent_GetVersionInfo (Std_VersionInfoType * VersionInfo);

#endif /* SENT_VERSION_INFO_API == STD_ON */

#define SENT_STOP_SEC_CODE

#include "Sent_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDD_SENT_H */
