/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : eMios
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

#ifndef EMIOS_OCU_IP_H
#define EMIOS_OCU_IP_H

/**
*   @file         Emios_Ocu_Ip.h
*
*   @addtogroup   ocu_ip Ocu IPL
*   @brief        Ocu eMIOS driver header file.
*   @details      eMios driver interface.
*
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
#include "Emios_Ocu_Ip_Types.h"
#include "Emios_Ocu_Ip_Cfg.h"

#if defined(MCAL_ENABLE_USER_MODE_SUPPORT)
    #include "Reg_eSys.h"
#endif
/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_OCU_IP_VENDOR_ID                       43
#define EMIOS_OCU_IP_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_OCU_IP_AR_RELEASE_MINOR_VERSION        7
#define EMIOS_OCU_IP_AR_RELEASE_REVISION_VERSION     0
#define EMIOS_OCU_IP_SW_MAJOR_VERSION                3
#define EMIOS_OCU_IP_SW_MINOR_VERSION                0
#define EMIOS_OCU_IP_SW_PATCH_VERSION                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (EMIOS_OCU_IP_VENDOR_ID != EMIOS_OCU_IP_TYPES_VENDOR_ID)
    #error "Emios_Ocu_Ip.h and Emios_Ocu_Ip_Types.h have different vendor ids"
#endif

/* Check if  header file and Emios_Ocu_Ip_Types.h file are of the same Autosar version */
#if ((EMIOS_OCU_IP_AR_RELEASE_MAJOR_VERSION != EMIOS_OCU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_OCU_IP_AR_RELEASE_MINOR_VERSION != EMIOS_OCU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_OCU_IP_AR_RELEASE_REVISION_VERSION != EMIOS_OCU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Ocu_Ip.h and Emios_Ocu_Ip_Types.h are different"
#endif

/* Check if header file and Emios_Ocu_Ip_Types.h file are of the same Software version */
#if ((EMIOS_OCU_IP_SW_MAJOR_VERSION != EMIOS_OCU_IP_TYPES_SW_MAJOR_VERSION) || \
     (EMIOS_OCU_IP_SW_MINOR_VERSION != EMIOS_OCU_IP_TYPES_SW_MINOR_VERSION) || \
     (EMIOS_OCU_IP_SW_PATCH_VERSION != EMIOS_OCU_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Ocu_Ip.h and Emios_Ocu_Ip_Types.h are different"
#endif

#if (EMIOS_OCU_IP_VENDOR_ID != EMIOS_OCU_IP_CFG_VENDOR_ID)
    #error "Emios_Ocu_Ip.h and Emios_Ocu_Ip_Cfg.h have different vendor ids"
#endif

/* Check if  header file and Emios_Ocu_Ip_Cfg.h file are of the same Autosar version */
#if ((EMIOS_OCU_IP_AR_RELEASE_MAJOR_VERSION != EMIOS_OCU_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_OCU_IP_AR_RELEASE_MINOR_VERSION != EMIOS_OCU_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_OCU_IP_AR_RELEASE_REVISION_VERSION != EMIOS_OCU_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Ocu_Ip.h and Emios_Ocu_Ip_Cfg.h are different"
#endif

/* Check if header file and Emios_Ocu_Ip_Cfg.h file are of the same Software version */
#if ((EMIOS_OCU_IP_SW_MAJOR_VERSION != EMIOS_OCU_IP_CFG_SW_MAJOR_VERSION) || \
     (EMIOS_OCU_IP_SW_MINOR_VERSION != EMIOS_OCU_IP_CFG_SW_MINOR_VERSION) || \
     (EMIOS_OCU_IP_SW_PATCH_VERSION != EMIOS_OCU_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Ocu_Ip.h and Emios_Ocu_Ip_Cfg.h are different"
#endif

#if defined(MCAL_ENABLE_USER_MODE_SUPPORT)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if this header file and Reg_eSys.h file are of the same Autosar version */
        #if ((EMIOS_OCU_IP_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
            (EMIOS_OCU_IP_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Emios_Ocu_Ip.h and Reg_eSys.h are different"
        #endif
    #endif
#endif

#if (STD_ON == OCU_EMIOS_USED)

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"

/**
 * @brief   Ocu driver initialization function for eMios module.
 * @details This function is called once for all eMios hw channels corresponding to the configured timer channels, and:
 *          - initializes the global data-stores
 *          - disables the timer channel
 *          - disables the timer compare interrupts corresponding to eMios channel
 *          - clears the timer compare interrupt flags corresponding to eMios channel
 *          - Select the clock divider value for the internal prescaler of Unified Channel
 *          - select counter Bus (A, B, C, D, E or INTERNAL Bus)
 *          - set the compare register A to configured default threshold value to eMios channel.
 *          - set the compare register A of Counter Bus to configured max counter value.
 *          - if output pin is enable, set the mode for SAOC and the output pin operates normally.
 *          - clear pending interrupt serviced.
 *          - enables the prescaler for counter bus (start run counter).
 *          - configures UC Control n (C0 - C23) registers to expected values.
 *
 * @param[in] pEmiosIpConfig - Pointer to configuration structure of emios channels
 * @implements   Emios_Ocu_Ip_Init_Activity
 */
void Emios_Ocu_Ip_Init(const Emios_Ocu_Ip_ConfigType * const pEmiosIpConfig);

/*=================================================================================================================*/
#if (STD_ON == OCU_DEINIT_API)
/**
 * @brief   Ocu driver de-initialization function for eMios module.
 * @details This function is called separately for each eMios hw channel corresponding to the configured
 *          timer channels, and:
 *          - disables the timer compare interrupts corresponding to eMios channel
 *          - clears the timer compare interrupt flags corresponding to eMios channel
 *          - resets eMIOS UC Control register.
 *          - resets the compare register eMIOS UC A register .
 *          - resets eMIOS UC Control register of Master Bus.
 *          - resets the compare register eMIOS UC A register of Master Bus.
 *
 * @param[in]   InstNum - eMIOS instance number
 * @return void
 * @implements   Emios_Ocu_Ip_DeInit_Activity
 */
void Emios_Ocu_Ip_DeInit(uint8 InstNum);

#endif /* OCU_DEINIT_API */

/*=================================================================================================================*/
/**
 * @brief       Ocu driver function for starting the eMios timer channel.
 * @details     This function enables the channel timer.
 *
 * @param[in]   InstNum - eMIOS instance number
 * @param[in]   ChNum - Channel number in the eMIOS instance
 *
 * @implements   Emios_Ocu_Ip_StartChannel_Activity
 */
void Emios_Ocu_Ip_StartChannel(uint8 InstNum, uint8 ChNum);

/**
 * @brief       Ocu driver function for stopping the eMios timer channel.
 * @details     This function stops the timer channel
 *
 * @param[in]   InstNum - eMIOS instance number
 * @param[in]   ChNum - Channel number in the eMIOS instance
 *
 * @implements   Emios_Ocu_Ip_StopChannel_Activity
 */
void Emios_Ocu_Ip_StopChannel(uint8 InstNum, uint8 ChNum);

/*=================================================================================================================*/
#if (STD_ON == OCU_GET_COUNTER_API)
/**
 * @brief       Ocu driver function for getting the current counter value for a eMIOS timer channel.
 * @details     This function is called for reading the eMIOS channel counter register.
 *
 * @param[in]   InstNum - eMIOS instance number
 * @param[in]   ChNum - Channel number in the eMIOS instance
 *
 * return       current value of the eMIOS channel counter register
 *
 * @implements   Emios_Ocu_Ip_GetCounter_Activity
 */
Emios_Ocu_Ip_ValueType Emios_Ocu_Ip_GetCounter(uint8 InstNum, uint8 ChNum);
#endif /* OCU_GET_COUNTER_API */

/*=================================================================================================================*/
#if (STD_ON == OCU_SET_PIN_STATE_API)
/**
 * @brief   Ocu driver function for setting the Pin State for the current eMIOS channel
 *
 * @param[in]   InstNum - eMIOS instance number
 * @param[in]   ChNum - Channel number in the eMIOS instance
 *              PinState - Expectation state of pin: OCU_EMIOS_HIGH, OCU_EMIOS_LOW
 *
 * @implements  Emios_Ocu_Ip_SetPinState_Activity
 */
void Emios_Ocu_Ip_SetPinState(uint8 InstNum, uint8 ChNum, Emios_Ocu_Ip_PinStateType PinState);
#endif /* OCU_SET_PIN_STATE_API */

/*=================================================================================================================*/
#if (STD_ON == OCU_SET_PIN_ACTION_API)
/**
 * @brief   Ocu driver function for setting the Pin Action for the current eMIOS channel
 *
 * @param[in]   InstNum - eMIOS instance number
 * @param[in]   ChNum - Channel number in the eMIOS instance
 *              PinAction - Type of action: OCU_EMIOS_SET_LOW, OCU_EMIOS_SET_HIGH, OCU_EMIOS_SET_TOGGLE
 *
 * @implements  Emios_Ocu_Ip_SetPinAction_Activity
 */
void Emios_Ocu_Ip_SetPinAction(uint8 InstNum, uint8 ChNum, Emios_Ocu_Ip_PinActionType PinAction);

#endif /* OCU_SET_PIN_ACTION_API */

/*=================================================================================================================*/
#if (STD_ON == OCU_SET_ABSOLUTE_THRESHOLD_API)
/**
 * @brief      The function changes the eMios compare register value.
 * @details This function:
 *          - Clears the compare load register 1.
 *          - sets the compare load register 2 to the new timeout value.
 * @param[in]   InstNum - eMIOS instance number
 * @param[in]   ChNum - Channel number in the eMIOS instance
 * @param[in]   ReferenceVal - Value given by the upper layer and used as a base to determine
 * @param[in]   AbsoluteVal - channel timeout value
 *
 * return       Tells the caller whether the compare match will occur (or has already occured) during the current Refence Interval,
 *              as a result of setting the new threshold value.
 *
 * @implements  Emios_Ocu_Ip_SetAbsoluteThreshold_Activity
 */
Emios_Ocu_Ip_ReturnType Emios_Ocu_Ip_SetAbsoluteThreshold(uint8 InstNum, uint8 ChNum, Emios_Ocu_Ip_ValueType ReferenceVal, Emios_Ocu_Ip_ValueType AbsoluteVal);

#endif /* OCU_SET_ABSOLUTE_THRESHOLD_API */

#if (STD_ON == OCU_SET_RELATIVE_THRESHOLD_API)
/**
 * @brief       The function changes the eMios compare register value.
 * @details     This function:
 *                  - Clears the compare load register 1.
 *                  - sets the compare load register 2 to the new timeout value.
 *
 * @param[in]   InstNum - eMIOS instance number
 * @param[in]   ChNum - Channel number in the eMIOS instance
 *              RelativeValue - Channel timeout value
 *
 * return   Tells the caller whether the compare match will occur (or has already occured) during the current Refence Interval,
 *          as a result of setting the new threshold value.
 *
 * @implements    Emios_Ocu_Ip_SetRelativeThreshold_Activity
 */
Emios_Ocu_Ip_ReturnType Emios_Ocu_Ip_SetRelativeThreshold(uint8 InstNum, uint8 ChNum, Emios_Ocu_Ip_ValueType RelativeValue);

#endif /* OCU_SET_RELATIVE_THRESHOLD_API */

/*=================================================================================================================*/
#if (STD_ON == OCU_SET_CLOCK_MODE_API)
/**
 * @brief       The function changes the prescaler of eMIOS channel.
 * @details     This function changes the clock divider value for the UC internal prescaler
 *
 * @param[in]   InstNum - eMIOS instance number
 * @param[in]   Prescaler - Prescaler type: normal or alternative
 *
 *
 */
void Emios_Ocu_Ip_SetClockMode(uint8 InstNum, Emios_Ocu_Ip_SelectPrescalerType Prescaler);

#endif

/*===============================================================================================*/
#if ((STD_ON == OCU_SET_RELATIVE_THRESHOLD_API) || (STD_ON == OCU_SET_ABSOLUTE_THRESHOLD_API))
/**
 * @brief        Emios_Ocu_Ip_GetMaxCounterValue
 * @details      This function will return max counter value for given channel
 *
 * @param[in]   InstNum - eMIOS instance number
 * @param[in]   ChNum - Channel number in the eMIOS instance
 * @return      uint32 - Max counter value for given channel
 *
 *
 */
uint32 Emios_Ocu_Ip_GetMaxCounterValue(uint8 InstNum, uint8 ChNum);
#endif

#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)
/**
 * @brief   This function is used to disable the OCU compare match notification.
 *
 * @param[in]   InstNum - eMIOS instance number
 * @param[in]   ChNum - Channel number in the eMIOS instance
 *
 * @return none
 *
 * @implements   Emios_Ocu_Ip_DisableNotification_Activity
 */
void  Emios_Ocu_Ip_DisableNotification(uint8 InstNum, uint8 ChNum);

/**
 * @brief   This function is used to enable the OCU compare match notification of the indexed channel.
 *
 * @param[in]   InstNum - eMIOS instance number
 * @param[in]   ChNum - Channel number in the eMIOS instance
 *
 * @return none
 *
 * @implements   Emios_Ocu_Ip_EnableNotification_Activity
 */
void Emios_Ocu_Ip_EnableNotification(uint8 InstNum, uint8 ChNum);
#endif

#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"

#endif /* OCU_EMIOS_USED */


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* EMIOS_OCU_IP_H */
