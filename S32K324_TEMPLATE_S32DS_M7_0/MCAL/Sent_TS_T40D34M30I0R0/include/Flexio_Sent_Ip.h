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

#ifndef FLEXIO_SENT_IP_H
#define FLEXIO_SENT_IP_H

/**
*   @file    Flexio_Sent_Ip.h
*   @version 3.0.0
*
*   @brief   AUTOSAR Sent - Low level header of Sent driver.
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
#include "Flexio_Sent_Ip_Types.h"
#include "Flexio_Sent_Ip_HwAccess.h"
#include "OsIf.h"
#ifdef FEATURE_FLEXIO_DMA_ENABLE
#if (FEATURE_FLEXIO_DMA_ENABLE == STD_ON)
    #include "Dma_Ip.h"
#endif
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FLEXIO_SENT_IP_VENDOR_ID                      43
#define FLEXIO_SENT_IP_AR_RELEASE_MAJOR_VERSION       4
#define FLEXIO_SENT_IP_AR_RELEASE_MINOR_VERSION       7
#define FLEXIO_SENT_IP_AR_RELEASE_REVISION_VERSION    0
#define FLEXIO_SENT_IP_SW_MAJOR_VERSION               3
#define FLEXIO_SENT_IP_SW_MINOR_VERSION               0
#define FLEXIO_SENT_IP_SW_PATCH_VERSION               0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Flexio_Sent_Ip_Types header file are of the same vendor */
#if (FLEXIO_SENT_IP_VENDOR_ID != FLEXIO_SENT_IP_TYPES_VENDOR_ID)
#endif
/* Check if current file and Flexio_Sent_Ip_Types header file are of the same Autosar version */
#if ((FLEXIO_SENT_IP_AR_RELEASE_MAJOR_VERSION    != FLEXIO_SENT_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
       (FLEXIO_SENT_IP_AR_RELEASE_MINOR_VERSION    != FLEXIO_SENT_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
       (FLEXIO_SENT_IP_AR_RELEASE_REVISION_VERSION != FLEXIO_SENT_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
#endif
/* Check if current file and Flexio_Sent_Ip_Types header file are of the same Software version */
#if ((FLEXIO_SENT_IP_SW_MAJOR_VERSION != FLEXIO_SENT_IP_TYPES_SW_MAJOR_VERSION) || \
      (FLEXIO_SENT_IP_SW_MINOR_VERSION != FLEXIO_SENT_IP_TYPES_SW_MINOR_VERSION) || \
      (FLEXIO_SENT_IP_SW_PATCH_VERSION != FLEXIO_SENT_IP_TYPES_SW_PATCH_VERSION)    \
    )
#endif

/* Check if current file and Flexio_Ip_hw_access header file are of the same vendor */
#if (FLEXIO_SENT_IP_VENDOR_ID != FLEXIO_SENT_IP_HWACCESS_VENDOR_ID)
#endif
/* Check if current file and Flexio_Ip_hw_access header file are of the same Autosar version */
#if ((FLEXIO_SENT_IP_AR_RELEASE_MAJOR_VERSION    != FLEXIO_SENT_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
       (FLEXIO_SENT_IP_AR_RELEASE_MINOR_VERSION    != FLEXIO_SENT_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
       (FLEXIO_SENT_IP_AR_RELEASE_REVISION_VERSION != FLEXIO_SENT_IP_HWACCESS_AR_RELEASE_REVISION_VERSION) \
    )
#endif
/* Check if current file and Flexio_Ip_hw_access header file are of the same Software version */
#if ((FLEXIO_SENT_IP_SW_MAJOR_VERSION != FLEXIO_SENT_IP_HWACCESS_SW_MAJOR_VERSION) || \
      (FLEXIO_SENT_IP_SW_MINOR_VERSION != FLEXIO_SENT_IP_HWACCESS_SW_MINOR_VERSION) || \
      (FLEXIO_SENT_IP_SW_PATCH_VERSION != FLEXIO_SENT_IP_HWACCESS_SW_PATCH_VERSION)    \
    )
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ((FLEXIO_SENT_IP_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
            (FLEXIO_SENT_IP_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Flexio_Sent_Ip.h and OsIf.h are different"
    #endif
   
    #ifdef FEATURE_FLEXIO_DMA_ENABLE
        #if (FEATURE_FLEXIO_DMA_ENABLE == STD_ON)
            /* Check if current file and OsIf.h header file are of the same Autosar version */
            #if ((FLEXIO_SENT_IP_AR_RELEASE_MAJOR_VERSION !=  DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
                    (FLEXIO_SENT_IP_AR_RELEASE_MINOR_VERSION != DMA_IP_AR_RELEASE_MINOR_VERSION))
                #error "AutoSar Version Numbers of Flexio_Sent_Ip.h and Dma_Ip.h are different"
            #endif
        #endif
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#define SYNC_CAL_TICK           ((uint32)56U)
/* SYNC_CAL_TICK * 0.75 */
#define SYNC_CAL_TICK_MIN       ((uint32)42U)
/* SYNC_CAL_TICK * 1.25 */
#define SYNC_CAL_TICK_MAX       ((uint32)70U)

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**  
*   Timer of FLEXIO IP used for the simulation of the SENT protocol
*/
#define SENT_TIMER(x)     (x)

/**  
*   SENT SHORT DATA
*/
#define SENT_SHORT_MSGID_MASK               (0x0000F000U)
#define SENT_SHORT_MSGID_SHIFT              12U
#define SENT_SHORT_MSGID(x)                 (((uint32)(((uint32)x) & SENT_SHORT_MSGID_MASK)) >> SENT_SHORT_MSGID_SHIFT)

#define SENT_SHORT_DATA_MASK                (0x00000FF0U)
#define SENT_SHORT_DATA_SHIFT               4U
#define SENT_SHORT_DATA(x)                  (((uint32)(((uint32)x) & SENT_SHORT_DATA_MASK)) >> SENT_SHORT_DATA_SHIFT)

#define SENT_SHORT_CRC_MASK                 (0x0000000FU)
#define SENT_SHORT_CRC_SHIFT                0U
#define SENT_SHORT_CRC(x)                   (((uint32)(((uint32)x) & SENT_SHORT_CRC_MASK)) >> SENT_SHORT_CRC_SHIFT)

/**  
*   SENT ENHANCED 12 BIT DATA + 8 BIT ID
*/
#define SENT_ENHANCED8_MSGID74_MASK         (0x000003C0U)
#define SENT_ENHANCED8_MSGID30_MASK         (0x0000001EU)
#define SENT_ENHANCED8_MSGID(bit3)          ((((bit3) & SENT_ENHANCED8_MSGID74_MASK) >> 2U) | (((bit3) & SENT_ENHANCED8_MSGID30_MASK) >> 1U))
    
#define SENT_ENHANCED8_DATA_MASK            (0x00000FFFU)
#define SENT_ENHANCED8_DATA_SHIFT           0U
#define SENT_ENHANCED8_DATA(bit2)           (((uint32)(((uint32)(bit2)) & SENT_ENHANCED8_DATA_MASK)) >> SENT_ENHANCED8_DATA_SHIFT)
    
#define SENT_ENHANCED8_CRC_MASK             (0x0003F000U)
#define SENT_ENHANCED8_CRC_SHIFT            12U
#define SENT_ENHANCED8_CRC(bit2)            (((uint32)(((uint32)(bit2)) & SENT_ENHANCED8_CRC_MASK)) >> SENT_ENHANCED8_CRC_SHIFT)

/**  
*   SENT ENHANCED 16 BIT DATA + 4 BIT ID
*/
#define SENT_ENHANCED4_MSGID_MASK           (0x000003C0U)
#define SENT_ENHANCED4_MSGID_SHIFT          6U
#define SENT_ENHANCED4_MSGID(bit3)          (((uint32)(((uint32)bit3) & SENT_ENHANCED4_MSGID_MASK)) >> SENT_ENHANCED4_MSGID_SHIFT)

/* Get 4 bit high from Serial Data #BIT3 */
#define SENT_ENHANCED4_DATA4_MASK           (0x0000001EU)
#define SENT_ENHANCED4_DATA4_SHIFT          1U
#define SENT_ENHANCED4_DATA4(bit3)          (((uint32)(((uint32)bit3) & SENT_ENHANCED4_DATA4_MASK)) >> SENT_ENHANCED4_DATA4_SHIFT)
/* Get 12 bit low from Serial Data #BIT2 */
#define SENT_ENHANCED4_DATA12_MASK          (0x00000FFFU)
#define SENT_ENHANCED4_DATA12_SHIFT         0U
#define SENT_ENHANCED4_DATA12(bit2)         (((uint32)(((uint32)bit2) & SENT_ENHANCED4_DATA12_MASK)) >> SENT_ENHANCED4_DATA12_SHIFT)
/* Get complete 16 bit data */
#define SENT_ENHANCED4_DATA(bit3, bit2)     ((SENT_ENHANCED4_DATA4(bit3) << 12) | SENT_ENHANCED4_DATA12(bit2))

#define SENT_ENHANCED4_CRC_MASK             (0x0003F000U)
#define SENT_ENHANCED4_CRC_SHIFT            12U
#define SENT_ENHANCED4_CRC(bit2)            (((uint32)(((uint32)bit2) & SENT_ENHANCED4_CRC_MASK)) >> SENT_ENHANCED4_CRC_SHIFT)

/**  
*   Get configuration bit for enhanced data
*/
#define SENT_ENHANCED_BIT_CONF_MASK         (0x00000400U)     
#define SENT_ENHANCED_BIT_CONF_SHIFT        10U
#define SENT_ENHANCED_BIT_CONF(bit3)        (((uint32)(((uint32)bit3) & SENT_ENHANCED_BIT_CONF_MASK)) >> SENT_ENHANCED_BIT_CONF_SHIFT)

/** 
*   Get all #BIT2 from status nibble
*/
#define SENT_GET_BIT2(x, y)         (((y) << 1) | (((x) & 0x4U) >> 2))
/** 
*   Get all #BIT3 from status nibble
*/
#define SENT_GET_BIT3(x, y)         (((y) << 1) | (((x) & 0x8U) >> 3))
/**
*   bit XOR for CRC calculation
*/
#define SENT_BITXOR(x, y)           (((uint8)(x)) ^ ((uint8)(y)))
/** 
*   Get bit from enhanced serial message to create 24 bit sequence for CRC checking
*   x: BIT serial data
*   y: bit order
*/
#define SET_GET_BIT24(x, y)         ((((x) & (uint32)0xFFF) & ((uint32)0x800 >> (uint32)(y))) >> ((uint8)11-(y)))

#if (FEATURE_FLEXIO_DMA_ENABLE == STD_ON)
    #define SENT_DMA_CHANNEL_CONFIG_LIST_SIZE (12U)
#endif
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/*!
 * @brief Initialize the FLEXIO_Sent driver
 *
 * This function initializes the FLEXIO_Sent driver.
 *
 * @param instance  FLEXIO peripheral instance number
 * @param config    Pointer to the FLEXIO_Sent controller configuration structure. The function
 *                  reads configuration data from this structure and initializes the
 *                  driver accordingly. The application may free this structure after
 *                  the function returns.
 * @return          Error or success status returned by API
 * @implements      Flexio_Sent_Ip_Init_Activity
*/
Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_Init(uint8 Instance,
                                              const Flexio_CtrlConfigType *Config);

/*!
 * @brief De-Initialize the FLEXIO_Sent driver
 *
 * This function de-initializes the FLEXIO_Sent driver.
 *
 * @param instance  FLEXIO peripheral instance number
 * @return          Error or success status returned by API
 * @implements      Flexio_Sent_Ip_Deinit_Activity
*/
void Flexio_Sent_Ip_DeInit(uint8 Instance);

/*!
 * @brief Get Fast message data for a channel
 *
 * This function gets Fast message data for a channel.
 *
 * @param instance  FLEXIO peripheral instance number
 * @param channelID ID of FLEXIO TIMER channel
 * @return          Error or success status returned by API
*/
Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_GetFastChannelMsgData(const uint8 Instance,
                                                               const uint8 ChannelId);

/*!
 * @brief Get Fast message data for all channel
 *
 * This function gets Fast message data for all channel.
 *
 * @param instance  FLEXIO peripheral instance number
 * @return          Error or success status returned by API
*/
Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_GetFastMsgData(const uint8 Instance);

/*!
 * @brief Get Serial message data for a channel
 *
 * This function gets Serial message data for a channel.
 *
 * @param instance  FLEXIO peripheral instance number
 * @param channelID ID of FLEXIO TIMER channel
 * @return          Error or success status returned by API
*/
Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_GetSerialChannelMsgData(const uint8 Instance,
                                                                 const uint8 ChannelId);

/*!
 * @brief Get Serial message data for all channel.
 *
 * This function gets Serial message data for all channel.
 *
 * @param instance  FLEXIO peripheral instance number
 * @return          Error or success status returned by API
*/
Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_GetSerialMsgData(const uint8 Instance);

/*!
 * @brief Start receiving SENT data from bus on specific channel.
 *
 * Start receiving SENT data from bus on specific channel.
 *
 * @param instance  FLEXIO peripheral instance number
 * @param channelID ID of FLEXIO TIMER channel
 *
 * @return          Error or success status returned by API
*/
Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_StartChannelReceiving
(
    const uint8  Instance,
    const uint8  ChannelId
);

/*!
 * @brief Stop receiving SENT data from bus on specific channel.
 *
 * Start receiving SENT data from bus on specific channel.
 *
 * @param instance  FLEXIO peripheral instance number
 * @param channelID ID of FLEXIO TIMER channel
 *
 * @return          Error or success status returned by API
*/
Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_StopChannelReceiving
(
    const uint8  Instance,
    const uint8  ChannelId
);

#ifdef FEATURE_FLEXIO_DMA_ENABLE
#if (FEATURE_FLEXIO_DMA_ENABLE == STD_ON)
/*!
 * @brief Flexio_Sent_Ip_DmaHandler
 *
 * Implementation of FLEXIO DMA handler for all fast and serial messages
 *
 * @param instance  FLEXIO peripheral instance number
 * @param channelID ID of FLEXIO TIMER channel
 * @return          Error or success status returned by API
*/
void Flexio_Sent_Ip_DmaHandler(const uint8 Instance, const uint8 ChannelId);

#endif
#endif

#ifdef FXIO_ISR_PROCESS_MESSAGE_HANDLER_CTRL0_COMBINED

/*!
 * @brief Flexio_Sent_Ip_IRQMsgDataHandler
 *
 * Implementation of FLEXIO interrupt handler for all fast and serial message
 *
 * @param instance  FLEXIO peripheral instance number
 * @param channelID ID of FLEXIO TIMER channel
 * @return          Error or success status returned by API
*/
void Flexio_Sent_Ip_IRQMsgDataHandler(const uint8 Instance, const uint8 ChannelId, uint32 TimerVal);

#endif /* (FEATURE_FLEXIO_INSTANCE_COUNT > 0U) */

#ifdef FXIO_ISR_PROCESS_TIMER_CTRL0

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Sent_Ip_IRQTimerHandler
 * Description   : Collect timer values
 *
 *END**************************************************************************/
void Flexio_Sent_Ip_IRQTimerHandler(const uint8 Instance, const uint8 HwChannel, uint32 TimerVal);
#endif

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FLEXIO_SENT_IP_H */
