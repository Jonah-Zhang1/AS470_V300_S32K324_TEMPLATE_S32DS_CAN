/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : I2S
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

#ifndef FLEXIO_I2S_IP_H
#define FLEXIO_I2S_IP_H

/**
*   @file
*
*   @addtogroup flexio_i2s_ip FLEXIO_I2S IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Flexio_I2s_Ip_Types.h"
#include "Flexio_I2s_Ip_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_I2S_IP_VENDOR_ID                    43
#define FLEXIO_I2S_IP_MODULE_ID                    255
#define FLEXIO_I2S_IP_AR_RELEASE_MAJOR_VERSION     4
#define FLEXIO_I2S_IP_AR_RELEASE_MINOR_VERSION     7
#define FLEXIO_I2S_IP_AR_RELEASE_REVISION_VERSION  0
#define FLEXIO_I2S_IP_SW_MAJOR_VERSION             3
#define FLEXIO_I2S_IP_SW_MINOR_VERSION             0
#define FLEXIO_I2S_IP_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#if (STD_ON == FLEXIO_I2S_IP_ENABLE)

#define I2S_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2s_MemMap.h"

#if (FLEXIO_I2S_IP_NUMBER_OF_CHANNEL != 0U)
extern Flexio_I2s_Ip_StateType Flexio_I2s_Ip_MasterSlaveState[FLEXIO_I2S_IP_NUMBER_OF_CHANNEL];
#endif

extern Flexio_I2s_Ip_StateType * Flexio_I2s_Ip_pxState[FLEXIO_I2S_IP_INSTANCE_COUNT][FLEXIO_I2S_IP_NUMBER_OF_CHANNEL];

#define I2S_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2s_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#define I2S_START_SEC_CODE
#include "I2s_MemMap.h"

/*!
 * @brief Initialize the FLEXIO_I2S master mode driver
 *
 * This function initializes the FLEXIO_I2S driver in master mode.
 *
 * @param[in] Instance FLEXIO peripheral instance number
 * @param[in] Channel FLEXIO_I2S logical channel number
 * @param[in] ConfigPtr Pointer to the FLEXIO_I2S master user configuration structure. The function
 *                      reads configuration data from this structure and initializes the
 *                      driver accordingly. The application may free this structure after
 *                      the function returns.
 * @return void.
 */
void Flexio_I2s_Ip_MasterInit(uint8 Instance,
                              uint8 Channel,
                              const Flexio_I2s_Ip_MasterConfigType * ConfigPtr);


/*!
 * @brief De-initialize the FLEXIO_I2S master mode driver
 *
 * This function de-initializes the FLEXIO_I2S driver in master mode. The driver can't be used
 * again until reinitialized.
 *
 * @param[in] Instance FLEXIO peripheral instance number
 * @param[in] Channel FLEXIO_I2S logical channel number
 * @return void.
 */
void Flexio_I2s_Ip_MasterDeinit(uint8 Instance,
                                uint8 Channel);


/*!
 * @brief Perform a non-blocking send transaction on the I2S bus
 *
 * This function starts the transmission of a block of data and returns immediately.
 * The rest of the transmission is handled by the interrupt service routine (if the driver
 * is initialized in interrupt mode) or by the Flexio_I2s_Ip_MasterGetStatus function (if
 * the driver is initialized in polling mode).
 * Use Flexio_I2s_Ip_MasterGetStatus() to check the progress of the transmission.
 *
 * @param[in] Instance FLEXIO peripheral instance number
 * @param[in] Channel FLEXIO_I2S logical channel number
 * @param[in] TxBuff Pointer to the data to be transferred
 * @param[in] TxSize Length in words of the data to be transferred.
 *                   Word length is configured via byteWidth parameter in the init config structure.
 * @return Error or success status returned by API
 */
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_MasterSendData(uint8 Instance,
                                                      uint8 Channel,
                                                      const uint8 * TxBuff,
                                                      uint32 TxSize);


/*!
 * @brief Perform a blocking send transaction on the I2S bus
 *
 * This function sends a block of data, and
 * only returns when the transmission is complete.
 *
 * @param[in] Instance FLEXIO peripheral instance number
 * @param[in] Channel FLEXIO_I2S logical channel number
 * @param[in] TxBuff Pointer to the data to be transferred
 * @param[in] TxSize Length in words of the data to be transferred.
 *                   Word length is configured via byteWidth parameter in the init config structure.
 * @param[in] Timeout  Timeout for the transfer in milliseconds
 * @return Error or success status returned by API
 */
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_MasterSendDataBlocking(uint8 Instance,
                                                              uint8 Channel,
                                                              const uint8 * TxBuff,
                                                              uint32 TxSize,
                                                              uint32 Timeout);


/*!
 * @brief Perform a non-blocking receive transaction on the I2S bus
 *
 * This function starts the reception of a block of data and returns immediately.
 * The rest of the reception is handled by the interrupt service routine (if the driver
 * is initialized in interrupt mode) or by the Flexio_I2s_Ip_MasterGetStatus function (if
 * the driver is initialized in polling mode).
 * Use Flexio_I2s_Ip_MasterGetStatus() to check the progress of the reception.
 *
 * @param[in] Instance FLEXIO peripheral instance number
 * @param[in] Channel FLEXIO_I2S logical channel number
 * @param[out] RxBuff Pointer to the buffer where to store received data
 * @param[in] RxSize Length in words of the data to be transferred.
 *                   Word length is configured via byteWidth parameter in the init config structure.
 * @return Error or success status returned by API
 */
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_MasterReceiveData(uint8 Instance,
                                                         uint8 Channel,
                                                         uint8 * RxBuff,
                                                         uint32 RxSize);


/*!
 * @brief Perform a blocking receive transaction on the I2S bus
 *
 * This function receives a block of data and only returns when the reception is complete.
 *
 * @param[in] Instance FLEXIO peripheral instance number
 * @param[in] Channel FLEXIO_I2S logical channel number
 * @param[out] RxBuff Pointer to the buffer where to store received data
 * @param[in] RxSize Length in words of the data to be transferred.
 *                   Word length is configured via byteWidth parameter in the init config structure.
 * @param[in] Timeout Timeout for the transfer in milliseconds
 * @return Error or success status returned by API
 */
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_MasterReceiveDataBlocking(uint8 Instance,
                                                                 uint8 Channel,
                                                                 uint8 * RxBuff,
                                                                 uint32 RxSize,
                                                                 uint32 Timeout);


/*!
 * @brief Aborts a non-blocking I2S master transaction
 *
 * This function aborts a non-blocking I2S transfer.
 *
 * @param[in] Instance FLEXIO peripheral instance number
 * @param[in] Channel FLEXIO_I2S logical channel number
 * @return Error or success status returned by API
 */
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_MasterTransferAbort(uint8 Instance,
                                                           uint8 Channel);


/*!
 * @brief Get the status of the current non-blocking I2S master transaction
 *
 * This function returns the current status of a non-blocking I2S master transaction.
 * A return code of FLEXIO_I2S_IP_STATUS_BUSY means the transfer is still in progress.
 * Otherwise the function returns a status reflecting the outcome of the last transfer.
 * When the driver is initialized in polling mode this function also advances the transfer
 * by checking and handling the transmit and receive events, so it must be called
 * frequently to avoid overflows or underflows.
 *
 * @param[in] Instance FLEXIO peripheral instance number
 * @param[in] Channel FLEXIO_I2S logical channel number
 * @param[out] BytesRemaining Remaining number of bytes to be transferred
 * @return Error or success status returned by API
 */
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_MasterGetStatus(uint8 Instance,
                                                       uint8 Channel,
                                                       uint32 * BytesRemaining);


/*!
 * @brief Initialize the FLEXIO_I2S slave mode driver
 *
 * This function initializes the FLEXIO_I2S driver in slave mode.
 *
 * @param[in] Instance FLEXIO peripheral instance number
 * @param[in] Channel FLEXIO_I2S logical channel number
 * @param[in] ConfigPtr Pointer to the FLEXIO_I2S slave user configuration structure. The function
 *                     reads configuration data from this structure and initializes the
 *                     driver accordingly. The application may free this structure after
 *                     the function returns.
 * @return void.
 */
void Flexio_I2s_Ip_SlaveInit(uint8 Instance,
                             uint8 Channel,
                             const Flexio_I2s_Ip_SlaveConfigType * ConfigPtr);


/*!
 * @brief De-initialize the FLEXIO_I2S slave mode driver
 *
 * This function de-initializes the FLEXIO_I2S driver in slave mode. The driver can't be used
 * again until reinitialized.
 *
 * @param[in] Instance FLEXIO peripheral instance number
 * @param[in] Channel FLEXIO_I2S logical channel number
 * @return void.
 */
void Flexio_I2s_Ip_SlaveDeinit(uint8 Instance,
                               uint8 Channel);


/*!
 * @brief Perform a non-blocking send transaction on the I2S bus
 *
 * This function starts the transmission of a block of data and returns immediately.
 * The rest of the transmission is handled by the interrupt service routine (if the driver
 * is initialized in interrupt mode) or by the Flexio_I2s_Ip_SlaveGetStatus function (if
 * the driver is initialized in polling mode).
 * Use Flexio_I2s_Ip_SlaveGetStatus() to check the progress of the transmission.
 *
 * @param[in] Instance FLEXIO peripheral instance number
 * @param[in] Channel FLEXIO_I2S logical channel number
 * @param[in] TxBuff Pointer to the data to be transferred
 * @param[in] TxSize Length in words of the data to be transferred.
 *                   Word length is configured via byteWidth parameter in the init config structure.
 * @return Error or success status returned by API
 */
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_SlaveSendData(uint8 Instance,
                                                     uint8 Channel,
                                                     const uint8 * TxBuff,
                                                     uint32 TxSize);


/*!
 * @brief Perform a blocking send transaction on the I2S bus
 *
 * This function sends a block of data, and
 * only returns when the transmission is complete.
 *
 * @param[in] Instance FLEXIO peripheral instance number
 * @param[in] Channel FLEXIO_I2S logical channel number
 * @param[in] TxBuff Pointer to the data to be transferred
 * @param[in] TxSize Length in words of the data to be transferred.
 *                   Word length is configured via byteWidth parameter in the init config structure.
 * @param[in] Timeout Timeout for the transfer in milliseconds
 * @return Error or success status returned by API
 */
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_SlaveSendDataBlocking(uint8 Instance,
                                                             uint8 Channel,
                                                             const uint8 * TxBuff,
                                                             uint32 TxSize,
                                                             uint32 Timeout);

/*!
 * @brief Perform a non-blocking receive transaction on the I2S bus
 *
 * This function starts the reception of a block of data and returns immediately.
 * The rest of the reception is handled by the interrupt service routine (if the driver
 * is initialized in interrupt mode) or by the Flexio_I2s_Ip_SlaveGetStatus function (if
 * the driver is initialized in polling mode).
 * Use Flexio_I2s_Ip_SlaveGetStatus() to check the progress of the reception.
 *
 * @param[in] Instance FLEXIO peripheral instance number
 * @param[in] Channel FLEXIO_I2S logical channel number
 * @param[out] RxBuff Pointer to the buffer where to store received data
 * @param[in] RxSize Length in words of the data to be transferred.
 *                   Word length is configured via byteWidth parameter in the init config structure.
 * @return Error or success status returned by API
 */
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_SlaveReceiveData(uint8 Instance,
                                                        uint8 Channel,
                                                        uint8 * RxBuff,
                                                        uint32 RxSize);


/*!
 * @brief Perform a blocking receive transaction on the I2S bus
 *
 * This function receives a block of data and only returns when the reception is complete.
 *
 * @param[in] Instance FLEXIO peripheral instance number
 * @param[in] Channel FLEXIO_I2S logical channel number
 * @param[out] RxBuff Pointer to the buffer where to store received data
 * @param[in] RxSize Length in words of the data to be transferred.
 *                   Word length is configured via byteWidth parameter in the init config structure.
 * @param[in] Timeout Timeout for the transfer in milliseconds
 * @return Error or success status returned by API
 */
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_SlaveReceiveDataBlocking(uint8 Instance,
                                                                uint8 Channel,
                                                                uint8 * RxBuff,
                                                                uint32 RxSize,
                                                                uint32 Timeout);


/*!
 * @brief Aborts a non-blocking I2S slave transaction
 *
 * This function aborts a non-blocking I2S transfer.
 *
 * @param[in] Instance FLEXIO peripheral instance number
 * @param[in] Channel FLEXIO_I2S logical channel number
 * @return Error or success status returned by API
 */
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_SlaveTransferAbort(uint8 Instance,
                                                          uint8 Channel);


/*!
 * @brief Get the status of the current non-blocking I2S slave transaction
 *
 * This function returns the current status of a non-blocking I2S slave transaction.
 * A return code of FLEXIO_I2S_IP_STATUS_BUSY means the transfer is still in progress.
 * Otherwise the function returns a status reflecting the outcome of the last transfer.
 * When the driver is initialized in polling mode this function also advances the transfer
 * by checking and handling the transmit and receive events, so it must be called
 * frequently to avoid overflows or underflows.
 *
 * @param[in] Instance FLEXIO peripheral instance number
 * @param[in] Channel FLEXIO_I2S logical channel number
 * @param[out] BytesRemaining Remaining number of bytes to be transferred
 * @return Error or success status returned by API
 */
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_SlaveGetStatus(uint8 Instance,
                                                      uint8 Channel,
                                                      uint32 * BytesRemaining);


/**
* @brief   Interrupt handler for FlexIO.
* @details This function shall manage all the interrupts of a FlexIO module
*
* @param[in] FlexIOChannel FlexIO channel to be addressed.
* @param[in] ShifterMaskFlag shifters status
* @param[in] ShifterErrMaskFlag shifters error status
* @param[in] TimerMaskFlag FlexIO timers status
* @return void.
*
* @note         Internal driver function.
*/
void Flexio_I2s_Ip_IrqHandler(uint8 FlexIOChannel,
                              uint8 ShifterMaskFlag,
                              uint8 ShifterErrMaskFlag,
                              uint8 TimerMaskFlag);

#define I2S_STOP_SEC_CODE
#include "I2s_MemMap.h"

#endif /* (STD_ON == FLEXIO_I2S_IP_ENABLE) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_I2S_IP_H */
