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

#ifndef SAI_IP_H
#define SAI_IP_H

/**
*   @file
*
*   @addtogroup sai_ip SAI IPL
*   @{
*/

#if defined(__cplusplus)
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Sai_Ip_Types.h"
#include "Sai_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SAI_IP_VENDOR_ID                      43
#define SAI_IP_AR_RELEASE_MAJOR_VERSION       4
#define SAI_IP_AR_RELEASE_MINOR_VERSION       7
#define SAI_IP_AR_RELEASE_REVISION_VERSION    0
#define SAI_IP_SW_MAJOR_VERSION               3
#define SAI_IP_SW_MINOR_VERSION               0
#define SAI_IP_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Sai_Ip_Types header file are of the same vendor */
#if (SAI_IP_VENDOR_ID != SAI_IP_TYPES_VENDOR_ID)
#error "Sai_Ip.h and Sai_Ip_Types.h have different vendor ids"
#endif

/* Check if current file and Sai_Ip_Types header file are of the same Autosar version */
#if ((SAI_IP_AR_RELEASE_MAJOR_VERSION     != SAI_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SAI_IP_AR_RELEASE_MINOR_VERSION     != SAI_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SAI_IP_AR_RELEASE_REVISION_VERSION  != SAI_IP_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Sai_Ip.h and Sai_Ip_Types.h are different"
#endif

/* Check if current file and Sai_Ip_Types header file are of the same software version */
#if ((SAI_IP_SW_MAJOR_VERSION != SAI_IP_TYPES_SW_MAJOR_VERSION) || \
     (SAI_IP_SW_MINOR_VERSION != SAI_IP_TYPES_SW_MINOR_VERSION) || \
     (SAI_IP_SW_PATCH_VERSION != SAI_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Sai_Ip.h and Sai_Ip_Types.h are different"
#endif

/* Check if current file and Sai_Ip_Cfg header file are of the same vendor */
#if (SAI_IP_VENDOR_ID != SAI_IP_CFG_VENDOR_ID)
#error "Sai_Ip.h and Sai_Ip_Cfg.h have different vendor ids"
#endif

/* Check if current file and Sai_Ip_Cfg header file are of the same Autosar version */
#if ((SAI_IP_AR_RELEASE_MAJOR_VERSION     != SAI_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (SAI_IP_AR_RELEASE_MINOR_VERSION     != SAI_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (SAI_IP_AR_RELEASE_REVISION_VERSION  != SAI_IP_CFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Sai_Ip.h and Sai_Ip_Cfg.h are different"
#endif

/* Check if current file and Sai_Ip_Cfg header file are of the same software version */
#if ((SAI_IP_SW_MAJOR_VERSION != SAI_IP_CFG_SW_MAJOR_VERSION) || \
     (SAI_IP_SW_MINOR_VERSION != SAI_IP_CFG_SW_MINOR_VERSION) || \
     (SAI_IP_SW_PATCH_VERSION != SAI_IP_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Sai_Ip.h and Sai_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#if (STD_ON == SAI_IP_ENABLE)

#define I2S_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2s_MemMap.h"

extern Sai_Ip_StateStructType * Sai_Ip_apxTxState[SAI_INSTANCE_COUNT];
extern Sai_Ip_StateStructType * Sai_Ip_apxRxState[SAI_INSTANCE_COUNT];

#define I2S_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2s_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define I2S_START_SEC_CODE
#include "I2s_MemMap.h"

/*!
 * @brief Set active for either transmitter or receiver.
 *
 * When both of transmitter and receiver are configured as master and async mode,
 * at the specific time only one master can be active.
 * This function must be called to alternate between sending and receiving operation:
 *     - Before calling the first tx/rx transfer
 *     - After a tx/rx transfer end and before start another rx/tx transfer.
 *
 * @param[in] u8Instance Peripheral instance number
 * @param[in] bTx True if next operation is tx, false otherwise
 */
void Sai_Ip_SetMaster(const uint8 u8Instance,
                      const boolean bTx);

/*!
 * @brief Initialize the transmitter of driver
 *
 * @param[in] u8Instance  Peripheral instance number
 * @param[in] pConfig    Pointer to the user configuration structure. The function
 *                         reads configuration data from this structure and initializes the
 *                         driver accordingly. The application may free this structure after
 *                         the function returns.
 */

void Sai_Ip_TxInit(const uint8 u8Instance,
                   const Sai_Ip_ConfigType * pConfig);

/*!
 * @brief Initialize the receiver of driver
 *
 * @param[in] u8Instance  Peripheral instance number
 * @param[in] pConfig    Pointer to the user configuration structure. The function
 *                         reads configuration data from this structure and initializes the
 *                         driver accordingly. The application may free this structure after
 *                         the function returns.
 */
void Sai_Ip_RxInit(const uint8 u8Instance,
                   const Sai_Ip_ConfigType * pConfig);

/*!
 * @brief De-initialize transmitter
 *
 * This function de-initializes driver. The driver can't be used
 * again until reinitialized. The context structure is no longer needed by the driver and
 * can be freed after calling this function.
 *
 * @param[in] u8Instance    Peripheral instance number
 */
void Sai_Ip_TxDeInit(const uint8 u8Instance);

/*!
 * @brief De-initialize receiver
 *
 * This function de-initializes driver. The driver can't be used
 * again until reinitialized. The context structure is no longer needed by the driver and
 * can be freed after calling this function.
 *
 * @param[in] u8Instance    Peripheral instance number
 */
void Sai_Ip_RxDeInit(const uint8 u8Instance);

#if (SAI_IP_ENABLE_DATA_MASKING == STD_ON)
/*!
* @brief Set masked word index of subsequent frames for transmitter or receiver
*
* Each bit is a masked word.
* Should be called in frame start event callback or
* in four bit clock cycles after Tx init.
*
* @param[in] u8Instance Peripheral instance number
* @param[in] bTx True if the masked word is in Tx frame, false otherwise
* @param[in] u16Words Word index to mask
* @return Divisor factor
*/
void Sai_Ip_SetNextMaskWords(const uint8 u8Instance,
                         const boolean bTx,
                         const uint16 u16Words);
#endif /* (SAI_IP_ENABLE_DATA_MASKING == STD_ON) */

/*!
 * @brief Send a block of data, return when transfer complete.
 *
 * Should be called immediately after a transfer complete to avoid data underrun error.
 *
 * @param[in] u8Instance Peripheral instance number
 * @param[in] aData Array of pointer to each data block to transfer, each data block corresponds to an enabled channels
 * If mux memory is selected, only first data block is used
 * @param[in] u32Count Number of words to transfer for each channel. The size of each buffer word element is "Sai Buffer Element Size" selected in configurator.
 * In DMA mode, count number upper limit is limited by DMA BITER/CITER register length.
 * @param[in] u32Timeout Timeout to return when transfer take too long.
 * @return Success, error or timeout status.
 */
Sai_Ip_StatusType Sai_Ip_SendBlocking(const uint8 u8Instance,
                                      const uint8 * const aData[],
                                      const uint32 u32Count,
                                      const uint32 u32Timeout);

/*!
 * @brief Send a block of data, return immidiately.
 *
 * When transfer completed, the callback function will be executed.
 * User should use this callback function to immidiately start an other transfer to avoid data underrun error.
 *
 * @param[in] u8Instance Peripheral instance number
 * @param[in] aData Array of pointer to each data block to transfer, each data block corresponds to an enabled channels
 * If mux memory is selected, only first data block is used
 * @param[in] u32Count Number of words to transfer for each channel. The size of each buffer word element is "Sai Buffer Element Size" selected in configurator.
 * In DMA mode, count number upper limit is limited by DMA BITER/CITER register length.
 */
void Sai_Ip_Send(const uint8 u8Instance,
                 const uint8 * const aData[],
                 const uint32 u32Count);

/*!
 * @brief Get status of a non-blocking transfer.
 *
 * @param[in] u8Instance Peripheral instance number
 * @param[out] pCountRemain Number of words remain for each channel.
 * This parameter can be NULL
 * @return Status of the transfer, can be success, aborted, timeout or busy. Note that for tx, success status imply that all data has
 * been pushed to hardware fifo and another transfer can be started.
 */
Sai_Ip_StatusType Sai_Ip_GetSendingStatus(const uint8 u8Instance,
                                          uint32 * pCountRemain);

/*!
 * @brief Receive a block of data, return when transfer complete.
 *
 * Should be called immidiately after a transfer complete to avoid data overrun error.
 *
 * @param[in] u8Instance Peripheral instance number
 * @param[out] aData Array of pointer to each data block to transfer, each data block corresponds to an enabled channels
 * If mux memory is selected, only first data block is used
 * @param[in] u32Count Number of words to transfer for each channel. The size of each buffer word element is "Sai Buffer Element Size" selected in configurator.
 * In DMA mode, count number upper limit is limited by DMA BITER/CITER register length.
 * @param[in] u32Timeout Timeout to return when transfer take too long.
 * @return Success, error or timeout status.
 */
Sai_Ip_StatusType Sai_Ip_ReceiveBlocking(const uint8 u8Instance,
                                         uint8 * const aData[],
                                         const uint32 u32Count,
                                         const uint32 u32Timeout);

/*!
 * @brief Receive a block of data, return immidiately.
 *
 * When transfer completed, the callback function will be executed.
 * User should use this callback function to immidiately start another transfer to avoid data overrun error.
 *
 * @param[in] u8Instance Peripheral instance number
 * @param[out] aData Array of pointer to each data block to transfer, each data block corresponds to an enabled channels
 * If mux memory is selected, only first data block is used
 * @param[in] u32Count Number of words to transfer for each channel. The size of each buffer word element is "Sai Buffer Element Size" selected in configurator.
 * In DMA mode, count number upper limit is limited by DMA BITER/CITER register length.
 */
void Sai_Ip_Receive(const uint8 u8Instance,
                    uint8 * const aData[],
                    const uint32 u32Count);

/*!
 * @brief Get status of a non-blocking transfer.
 *
 * @param[in] u8Instance Peripheral instance number
 * @param[out] pCountRemain Number of words remain for each channel.
 * This parameter can be NULL
 * @return Status of the transfer, can be success, aborted, timeout or busy.
 */
Sai_Ip_StatusType Sai_Ip_GetReceivingStatus(const uint8 u8Instance,
                                            uint32 * pCountRemain);

/*!
 * @brief Abort all ongoing transferring data (both sending and receiving)
 *
 * @param[in] u8Instance Peripheral instance number
 */
void Sai_Ip_AbortTransfer(const uint8 u8Instance);

#if (STD_ON == SAI_IP_AUTO_DISABLE_CLOCK)
/*!
 * @brief Disable transmitter clock after the transmission completed.
 * This function has effect only for first call to Send function.
 * Without calling this function, the clock will remain active after transmission has ended.
 *
 * @param[in] u8Instance Peripheral instance number
 */
void Sai_Ip_TxAutoDisableClock(const uint8 u8Instance);

/*!
 * @brief Disable receiver clock after the transmission completed.
 * This function has effect only for first call to Receive function.
 * Without calling this function, the clock will remain active after transmission has ended.
 *
 * @param[in] u8Instance Peripheral instance number
 */
void Sai_Ip_RxAutoDisableClock(const uint8 u8Instance);
#endif /* STD_ON == SAI_IP_AUTO_DISABLE_CLOCK */

#define I2S_STOP_SEC_CODE
#include "I2s_MemMap.h"

#endif /* (STD_ON == SAI_IP_ENABLE) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SAI_IP_H */
