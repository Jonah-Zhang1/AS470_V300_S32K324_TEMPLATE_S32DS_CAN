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

#ifndef SAI_IP_TYPES_H
#define SAI_IP_TYPES_H

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
#include "StandardTypes.h"
#include "Sai_Ip_DeviceRegisters.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SAI_IP_TYPES_VENDOR_ID                      43
#define SAI_IP_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define SAI_IP_TYPES_AR_RELEASE_MINOR_VERSION       7
#define SAI_IP_TYPES_AR_RELEASE_REVISION_VERSION    0
#define SAI_IP_TYPES_SW_MAJOR_VERSION               3
#define SAI_IP_TYPES_SW_MINOR_VERSION               0
#define SAI_IP_TYPES_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and StandardTypes header file are of the same Autosar version */
#if ((SAI_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (SAI_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Sai_Ip_Types.h and StandardTypes.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if current file and Sai_Ip_DeviceRegisters header file are of the same vendor */
#if (SAI_IP_TYPES_VENDOR_ID != SAI_IP_DEVICEREGISTERS_VENDOR_ID)
#error "Sai_Ip_Types.h and Sai_Ip_DeviceRegisters.h have different vendor ids"
#endif

/* Check if current file and Sai_Ip_DeviceRegisters header file are of the same Autosar version */
#if ((SAI_IP_TYPES_AR_RELEASE_MAJOR_VERSION     != SAI_IP_DEVICEREGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (SAI_IP_TYPES_AR_RELEASE_MINOR_VERSION     != SAI_IP_DEVICEREGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (SAI_IP_TYPES_AR_RELEASE_REVISION_VERSION  != SAI_IP_DEVICEREGISTERS_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Sai_Ip_Types.h and Sai_Ip_DeviceRegisters.h are different"
#endif

/* Check if current file and Sai_Ip_DeviceRegisters header file are of the same software version */
#if ((SAI_IP_TYPES_SW_MAJOR_VERSION != SAI_IP_DEVICEREGISTERS_SW_MAJOR_VERSION) || \
     (SAI_IP_TYPES_SW_MINOR_VERSION != SAI_IP_DEVICEREGISTERS_SW_MINOR_VERSION) || \
     (SAI_IP_TYPES_SW_PATCH_VERSION != SAI_IP_DEVICEREGISTERS_SW_PATCH_VERSION))
#error "Software Version Numbers of Sai_Ip_Types.h and Sai_Ip_DeviceRegisters.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#if (STD_ON == SAI_IP_ENABLE)

/* Bit values to use with ChannelEnable param in user config struct */
#define SAI_IP_CHANNEL_0 0x1
#define SAI_IP_CHANNEL_1 0x2
#define SAI_IP_CHANNEL_2 0x4
#define SAI_IP_CHANNEL_3 0x8

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/*! @brief Define the enum of the events which can trigger SAI callback
 *
 * This enum should include the events for all platforms
 */
typedef enum
{
    SAI_IP_RX_COMPLETE         = 0x00U, /*!< Rx transfer complete, user can start another transfer */
    SAI_IP_TX_COMPLETE         = 0x01U, /*!< Tx transfer complete, user can start another transfer */
    SAI_IP_ERROR               = 0x03U, /*!< DMA error while transfer */
    SAI_IP_FRAME_START         = 0x05U, /*!< Indicate a frame start */
    SAI_IP_RUN_ERROR           = 0x06U, /*!< Overrun/underrun error. This event is useful for tx when user want to know whether all data
                                          in tx fifo has been pushed out to line and tx deinit can be called, since tx complete event
                                          only indicates all data from buffer has been pushed to hardware fifo */
    SAI_IP_SYNC_ERROR          = 0x07U  /*!< Frame sync error */
} Sai_Ip_ReportType;

/*!
 * @brief SAI status return type
 *
 * This structure is used as return type
 */
typedef enum
{
    SAI_IP_STATUS_UNINITIALIZED = 0x00U, /*!< Function unsupported */
    SAI_IP_STATUS_COMPLETED     = 0x01U, /*!< Function completed successfully */
    SAI_IP_STATUS_ERROR         = 0x02U, /*!< Function didn't complete successfully */
    SAI_IP_STATUS_TIMEOUT       = 0x03U, /*!< Function timed out */
    SAI_IP_STATUS_BUSY          = 0x04U, /*!< Function busy */
    SAI_IP_STATUS_ABORTED       = 0x05U  /*!< Function aborted */
} Sai_Ip_StatusType;

/*! @brief Transfer type.
 */
typedef enum
{
    SAI_IP_INTERRUPT = 0U,     /*!< Transfer type is interrupt */
#if (STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE)
    SAI_IP_DMA                 /*!< Transfer type is DMA */
#endif
} Sai_Ip_TransferType;

/*! @brief Data mux line or mux memory.
 */
typedef enum
{
    SAI_IP_MUX_DISABLED = 0U,  /*!< Each data line is a channel, uses a seperate memory block */
    SAI_IP_MUX_LINE     = 1U,  /*!< Only one data line (data line 0 for DMA mode) is used. Words on data line is alternated between channels, each channel data is a seperate memory block */
    SAI_IP_MUX_MEM      = 2U   /*!< Words in memory block is alternated between channels, each channel data is on a seperate data line.*/
} Sai_Ip_MuxType;

/*! @brief SAI run in sync or async mode.
 * \n <b>Note</b>: entries in this enum are affected by ::FEATURE_SAI_IP_SYNC_WITH_OTHER_INST, which is device dependent
 * and controlled from feature header file of the used device.
 */
typedef enum
{
    SAI_IP_ASYNC        = 0U,         /*!< Independent clock */
    SAI_IP_SYNC_WITH_OTHER = 1U,      /*!< Bit clock and frame sync signal is taken from transmitter/receiver */
#ifdef FEATURE_SAI_IP_SYNC_WITH_OTHER_INST
    SAI_IP_SYNC_WITH_SAI2_SAME = 2U,  /*!< Bit clock and frame sync is taken from SAI 2's transmitter
                                       (if this is used for transmitter) or SAI 2's
                                       receiver (if this is used for receiver) */
    SAI_IP_SYNC_WITH_SAI2_OTHER = 3U  /*!< Bit clock and frame sync is taken from SAI 2's receiver
                                       (if this is used for transmitter) or SAI 2's
                                       transmitter (if this is used for receiver) */
#endif /* FEATURE_SAI_IP_SYNC_WITH_OTHER_INST */
} Sai_Ip_SyncType;

/*! @brief Select master clock.
 */
typedef enum
{
#ifdef FEATURE_SAI_IP_MSEL_AIPS_SLOW_CLK
    SAI_IP_AIPS_SLOW_CLK = 0U,        /*!< Master clock is module AIPS slow clock */
#endif
#ifdef FEATURE_SAI_IP_MSEL_BUS_CLK
    SAI_IP_BUS_CLK = 0U,        /*!< Master clock is module Bus clock */
#endif
#ifdef FEATURE_SAI_IP_MSEL_MCLK_PIN
    SAI_IP_EXTERNAL_CLK = 1U,   /*!< Master clock is from external */
#endif
#ifdef FEATURE_SAI_IP_MSEL_FXOSC_CLK
    SAI_IP_FXOSC_CLK = 2U,       /*!< Master clock is from external oscillator/crystal */
#endif
#ifdef FEATURE_SAI_IP_MSEL_SOSC_DIV1_CLK
    SAI_IP_SOSC_DIV1_CLK = 2U,       /*!< Master clock is from external oscillator/crystal */
#endif
#ifdef FEATURE_SAI_IP_MSEL_OTHER_MCLK_PIN
    SAI_IP_EXTERNAL_OTHER_CLK = 3U,   /*!< Master clock is from external other sai instance*/
#endif
} Sai_Ip_MasterClkSelType;

#ifdef FEATURE_SAI_IP_HAS_CHMOD
/*! @brief Data line state for masked word, or if data line is disabled.
 */
typedef enum
{
    SAI_IP_MASK_TRISTATE = 0U,     /*!< Line is in high z state */
    SAI_IP_MASK_ZERO = 1U          /*!< Line is output zero */
} Sai_Ip_MaskType;
#endif /* FEATURE_SAI_IP_HAS_CHMOD */

/*! @brief Sai write data handler.
 */
typedef void (*Sai_Ip_WriteHandlerType)(uint32 * const u32Data, const uint8 u8Instance, const uint8 u8Pack, const uint8 u8ChnIdx);

/*! @brief Sai read data handler.
 */
typedef void (*Sai_Ip_ReadHandlerType)(uint32 * const u32Data, const uint8 u8Instance, const uint8 u8ChnIdx);

/*! @brief Sai callback function type for nonblock transfer, also called to report events (Sai_Ip_ReportType).
 */
typedef void (*Sai_Ip_TransferCallbackType)(Sai_Ip_ReportType event);

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*! @brief Transmit or receive state.
 */
typedef struct
{
/*! @cond DRIVER_INTERNAL_USE_ONLY */
    uint32 u32Count;        /* The number of words for reading or writing of each channel */
    const uint8 * pTxData;  /* Tx data pointer */
    uint8 * pRxData;        /* Rx data pointer */
/*! @endcond */
} Sai_Ip_XferState;

/*! @brief Structure for internal use.
 *  This structure is used by the driver for its internal logic.
 *  It must be provided by the application through the initialize functions,
 *  then it cannot be freed until the driver is de-initialized using Deinit functions.
 *  The application should make no assumptions about the content of this structure.
 */
typedef struct
{
/*! @cond DRIVER_INTERNAL_USE_ONLY */
    Sai_Ip_XferState aChnState[SAI_IP_MAX_CHANNEL_COUNT];   /* store data pointer and data count of each channel transfer*/
    volatile Sai_Ip_StatusType eStatus;                     /* Status.*/
    Sai_Ip_TransferType eTransferType;
    Sai_Ip_TransferCallbackType pCallback;                  /* Callback function */
    Sai_Ip_MuxType eMux;                                    /* mux mode using */
    boolean bMaster;                                        /* Master or Slave */
    boolean bBlocking;                                      /* Blocking or non-blocking.*/
#if (STD_ON == SAI_IP_AUTO_DISABLE_CLOCK)
    boolean bAutoDisableClock;                                   /* Disable clock after transmission completed */
#endif /* STD_ON == SAI_IP_AUTO_DISABLE_CLOCK */
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
    boolean bFPack;                                         /* FIFO packing enable.*/
    uint8 u8PackCnt;                                        /* Number of packs in FIFO */
    uint8 u8AccessNum[SAI_IP_MAX_CHANNEL_COUNT];            /* Store the current index of frame pack for each channel */
    uint8 u8FrameSize;                                      /* Frame size in number of words */
#endif
    uint8 u8ElementSize;                                    /* word size used for each read/write buffer*/
    uint8 u8ChannelCount;                                   /* only used for interrupt mux line */
    uint8 u8NextChn;                                        /* emulate hw combine mode, work around for asdk 4634 */
    uint8 u8BufferAccessSize;                               /* Number of words each time read from/write to buffer */
#if (STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE)
    uint8 aDmaChannel[SAI_IP_MAX_CHANNEL_COUNT];            /* dma channel for each sai channel */
#endif
    uint32 u32PBuffCnt;                                     /* Number of packs in buffer */
    Sai_Ip_WriteHandlerType pWriteHandler;                   /* Sai IP write data handler*/
    Sai_Ip_ReadHandlerType pReadHandler;                    /* Sai IP read data handler*/
    uint32 u32Cr4;                                          /* temporary var to save tcr4/rcr4 in SetMaster function */

/*! @endcond */
} Sai_Ip_StateStructType;

/*! @brief User config structure.
* \n <b>Note</b>: entries in this structure are affected by ::FEATURE_SAI_IP_HAS_CHMOD, which is device dependent
* and controlled from feature header file of the used device.
*
* Implements  Sai_Ip_ConfigType_struct
*/
typedef struct
{
    Sai_Ip_SyncType eSyncMode;               /*!< Sync mode.*/
    Sai_Ip_MasterClkSelType eMasterClkSrc;   /*!< Select master clock source.*/
    boolean bBitClkNegPolar;                 /*!< True if bit clock is negative polar (active low with drive outputs on falling edge and sample inputs on rising edge), false otherwise.*/
    boolean bBitClkInternal;                 /*!< True if bit clock is generated internally.*/
    uint32 u32MasterClkFreq;                 /*!< Clock frequency from selected master clock source, only for internally generated master clock */
    uint32 u32BitClkFreq;                    /*!< Desired bit clock frequency in hertz,
                                                 only for internally generated master clock and bit clock.
                                                 Real divisor is derived by: floor(floor(MasterClockFreq / BitClkFreq) / 2)) * 2,
                                                 value range is from 2 to 512. If out of range value is assigned, maximum or minimum value is used.
                                                 Real closest BitClockFreq is derived by: MasterClockFreq / real_divisor */
    uint8 u8ChannelEnable;                   /*!< Turn on each bit to enable each channel. 4 bit for 4 channels.*/
    uint8 u8FrameSize;                       /*!< Frame size in number of words. When in mux line mode, the number of unmasked word in a frame must be divisible by number of channels */
    uint8 u8SyncWidth;                       /*!< Active sync width in number of bit clocks (must not longer than first word width).*/
#ifdef FEATURE_SAI_IP_HAS_CHMOD
    Sai_Ip_MaskType eMaskMode;               /*!< Data line state for mask word or when data line is disabled (apply only for transmitter).*/
#endif
#if (STD_ON == SAI_IP_BCS_FEATURE_AVAILABLE)
    boolean bBitClkSwap;                     /*!< Swap bit clock between transmitter and receiver depend on sync mode.*/
#endif
    boolean bDebugEnable;                    /*!< True if transfer is enabled in debug mode after completing the current frame, false if transfer is disabled in debug mode.*/
    boolean bMsbFirst;                       /*!< True if data is MSB first, false if LSB first.*/
    boolean bSyncEarly;                      /*!< True if frame sync is one bit clock early.*/
    boolean bSyncNegPolar;                   /*!< True if frame sync is negative polar (active low), false otherwise.*/
    boolean bSyncInternal;                   /*!< True if frame sync is generated internally*/
    uint8 u8Word0Width;                      /*!< First word width in number of bit clocks.*/
    uint8 u8WordNWidth;                      /*!< Other words width in number of bit clocks.*/
    uint8 u8FirstBitIndex;                   /*!< Index from LSB of first bit to be transmitted/received, valid range
                                                 from 0-31.*/
    boolean bRunErrorReport;                 /*!< Underrun/overrun error report. */
    boolean bSyncErrorReport;                /*!< Enable sync error report.*/
    boolean bFrameStartReport;               /*!< Enable frame start report.*/
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
    boolean bFPack;                          /*!< FIFO packing enable.*/
#endif
    Sai_Ip_MuxType eMuxMode;                 /*!< Enable line mux, memory mux or mux is disabled. */
    Sai_Ip_TransferType eTransferType;       /*!< Transfer using dma or interrupt.*/
#if (STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE)
    uint8 aDmaChannel[SAI_IP_MAX_CHANNEL_COUNT];   /*!< DMA channels to be used.*/
#endif
    uint8 u8ElementSize;                     /*!< Size in bytes of each read/write from/to buffer.*/
    uint8 u8ChannelCount;                    /*!< Number of channels to enable, only used when both line mux mode and interrupt mode is selected.*/
    uint8 u8BufferAccessSize;                /*!< Number of words each time read from/write to buffer */
    uint8 u8WordFlagIndex;                   /*!< Configure which word sets the start of word flag, should less than frame size */
    boolean bBitClkInput;                    /*!< Use slave mode timing in datasheet for master mode */
    boolean bContOnErr;                      /*!< True continue transfering the same work that caused FIFO eror, False start the next frame */
    boolean bSyncOnDemand;                   /*!< True frame sync is generated only when fifo is not empty (transmit) or not full (receive), False otherwise */
    Sai_Ip_TransferCallbackType pCallback;   /*!< User callback function, called when transfer complete or selected events occurred.*/
    Sai_Ip_StateStructType * pState;         /*!< Sai IP internal state.*/
} Sai_Ip_ConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#endif /* (STD_ON == SAI_IP_ENABLE) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SAI_IP_TYPES_H */
