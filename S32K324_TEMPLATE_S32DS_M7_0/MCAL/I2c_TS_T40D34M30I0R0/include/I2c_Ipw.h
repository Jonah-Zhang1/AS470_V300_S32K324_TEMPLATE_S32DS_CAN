/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPI2C
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

#ifndef I2C_IPW_H
#define I2C_IPW_H

/**
*     @file
*
*     @addtogroup I2C_DRIVER I2c Driver
*     @{
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
#include "I2c_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_IPW_VENDOR_ID                    43
#define I2C_IPW_AR_RELEASE_MAJOR_VERSION     4
#define I2C_IPW_AR_RELEASE_MINOR_VERSION     7
#define I2C_IPW_AR_RELEASE_REVISION_VERSION  0
#define I2C_IPW_SW_MAJOR_VERSION             3
#define I2C_IPW_SW_MINOR_VERSION             0
#define I2C_IPW_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and I2c_Types header file are of the same vendor */
#if (I2C_TYPES_VENDOR_ID != I2C_IPW_VENDOR_ID)
     #error "I2c_Ipw.h and I2c_Types.h have different vendor ids"
#endif
/* Check if current file and I2c_Types header file are of the same Autosar version */
#if ((I2C_TYPES_AR_RELEASE_MAJOR_VERSION != I2C_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_TYPES_AR_RELEASE_MINOR_VERSION != I2C_IPW_AR_RELEASE_MINOR_VERSION) || \
     (I2C_TYPES_AR_RELEASE_REVISION_VERSION != I2C_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of I2c_Ipw.h and I2c_Types.h are different"
#endif
/* Check if current file and I2c_Types header file are of the same Software version */
#if ((I2C_TYPES_SW_MAJOR_VERSION != I2C_IPW_SW_MAJOR_VERSION) || \
     (I2C_TYPES_SW_MINOR_VERSION != I2C_IPW_SW_MINOR_VERSION) || \
     (I2C_TYPES_SW_PATCH_VERSION != I2C_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of I2c_Ipw.h and I2c_Types.h are different"
#endif
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
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define I2C_START_SEC_CODE

#include "I2c_MemMap.h"
/**
* @brief   Initialize a I2c channel.
* @details This function initializes all hardware registers needed to
*          start the I2c functionality on the selected channel.
*
* @param[in] Channel  I2c channel to be initialized.
*            ConfigPtr Configuration pointer containing hardware specific settings.
*
* @return            void.
*
*/
void I2c_Ipw_InitChannel(const uint8 Channel, const I2c_HwUnitConfigType * ConfigPtr);

/**
* @brief   De initialize a I2c channel.
* @details This function de initializes the hardware registers of an I2c channel
*
* @param[in] Channel      I2c channel to be de initialized.
*            eChannelType   The type of the channel (LPI2C or FlexIO).
*
* @return            void.
*
*/
void I2c_Ipw_DeInitChannel(const uint8 Channel, const I2c_HwUnitConfigType * ConfigPtr);

/**
* @brief   Sends or receives an I2c message from the slave.
* @details Generate (repeated) START and send the address of the slave to initiate a transmission.
*
* @param[in]   Channel        I2c channel to be addressed.
* @param[in]   Request      Pointer to the structure that contains the information necessary to begin the
*                               transmission: the address of the slave, high speed mode, expect NACK, number of bytes
*                               and the data buffer
*              eChannelType     The type of the channel (LPI2C or FlexIO).
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time out situation only.
* @retval E_OK       Otherwise.
*
*/
Std_ReturnType I2c_Ipw_SyncTransmit(uint8 Channel, const I2c_RequestType * Request, const I2c_HwUnitConfigType * HwConfigType);
/**
* @brief   Starts sending or receiving an I2c message from the slave.
* @details Generate (repeated) START and send the address of the slave to initiate a transmission.
*
* @param[in]   Channel        I2c channel to be addressed.
* @param[in]   Request      Pointer to the structure that contains the information necessary to begin the
*                               transmission: the address of the slave, high speed mode, expect NACK, number of bytes
*                               and the data buffer
*              HwConfigType    Pointer to the configuration structure
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time out situation only.
* @retval E_OK       Otherwise.
*
*/
Std_ReturnType I2c_Ipw_AsyncTransmit(uint8 Channel, const I2c_RequestType * Request, const I2c_HwUnitConfigType * HwConfigType);

/**
* @brief   Prepare the RX or TX buffer for a slave channel.
* @details Prepares a RX or TX buffer that will be used to receive data or send data when requested by the master.
*
* @param[in] Channel       I2c channel to be addressed.
* @param[in] NumberOfBytes Maximum number of bytes.
* @param[in] DataBuffer     Pointer to data buffer
*
* @return                  void
*/
void I2c_Ipw_PrepareSlaveBuffer(uint8 Channel, uint8 NumberOfBytes, I2c_DataType * DataBuffer);

/**
* @brief   Gets the status of an I2c channel.
* @details The function will check for error flags and return the status of a channel.
*
* @param[in]   Channel        I2c channel to be addressed.
*              eChannelType     The type of the channel (LPI2C or FlexIO).
*
* @return   I2c_StatusType.
* @retval I2C_CH_IDLE           In case the channel was just initialized and not request is pending.
* @retval I2C_CH_SEND           In case the channel is busy sending data.
* @retval I2C_CH_RECEIVE        In case the channel is busy receiving data.
* @retval I2C_CH_FINISHED       In case a transmission or reception of bytes has finished.
* @retval I2C_CH_ERROR_PRESENT  In case an error is present.
*
*/
I2c_StatusType I2c_Ipw_GetStatus(const uint8 Channel, const I2c_HwUnitConfigType * HwConfigType);

void I2c_Ipw_StartListening(uint8 Channel);

#define I2C_STOP_SEC_CODE

#include "I2c_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* I2C_IPW_H */

