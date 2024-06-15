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

#ifndef FLEXIO_I2S_IP_TYPES_H
#define FLEXIO_I2S_IP_TYPES_H

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

#include "StandardTypes.h"
#include "Flexio_I2s_Ip_CfgDefines.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_I2S_IP_TYPES_VENDOR_ID                    43
#define FLEXIO_I2S_IP_TYPES_MODULE_ID                    255
#define FLEXIO_I2S_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define FLEXIO_I2S_IP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define FLEXIO_I2S_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define FLEXIO_I2S_IP_TYPES_SW_MAJOR_VERSION             3
#define FLEXIO_I2S_IP_TYPES_SW_MINOR_VERSION             0
#define FLEXIO_I2S_IP_TYPES_SW_PATCH_VERSION             0

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
#if (STD_ON == FLEXIO_I2S_IP_ENABLE)

/*! @brief Status type
 * Implements : Flexio_I2s_Ip_StatusType_Class
 */
typedef enum
{
    FLEXIO_I2S_IP_STATUS_UNINIT                     = 0x00U,
    FLEXIO_I2S_IP_STATUS_SUCCESS                    = 0x01U,
    FLEXIO_I2S_IP_STATUS_ERROR                      = 0x02U,
    FLEXIO_I2S_IP_STATUS_BUSY                       = 0x03U,
    FLEXIO_I2S_IP_STATUS_TIMEOUT                    = 0x04U,
    FLEXIO_I2S_IP_STATUS_TX_UNDERRUN                = 0x05U,  /*!< TX underrun error */
    FLEXIO_I2S_IP_STATUS_RX_OVERRUN                 = 0x06U,  /*!< RX overrun error */
    FLEXIO_I2S_IP_STATUS_ABORTED                    = 0x07U   /*!< A transfer was aborted */
} Flexio_I2s_Ip_StatusType;

/*! @brief Driver type: INTERRUPT/POLLING/DMA
 * Implements : Flexio_I2s_Ip_DriverType_Class
 */
typedef enum
{
    FLEXIO_I2S_IP_DRIVER_TYPE_INTERRUPT     = 0U,  /*!< Driver uses INTERRUPT for data transfers */
    FLEXIO_I2S_IP_DRIVER_TYPE_POLLING       = 1U,  /*!< Driver is based on POLLING */
#if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
    FLEXIO_I2S_IP_DRIVER_TYPE_DMA           = 2U   /*!< Driver uses DMA for data transfers */
#endif /* (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE) */
} Flexio_I2s_Ip_DriverType;

/* Events for all peripherals which support flexio_i2s
 *
 * Implements : Flexio_I2s_Ip_EventType_Class
 */
typedef enum
{
    FLEXIO_I2S_IP_EVENT_RX_FULL      = 0x00U,    /*!< Rx buffer is full */
    FLEXIO_I2S_IP_EVENT_TX_EMPTY     = 0x01U,    /*!< Tx buffer is empty */
    FLEXIO_I2S_IP_EVENT_END_TRANSFER = 0x02U,    /*!< The current transfer is ending. Only FLEXIO instance uses this event. The difference between this and event TX_EMPTY is:
                                                 TX_EMPTY is generated when all data has been pushed to hardware fifo, users should not call DeInit here or some last data will be lost;
                                                 END_TRANSFER is generated when all data has been pushed to line, the transmission will be stopped before users can start transmit again, user can call DeInit here.
                                                 For receiving case, this event is the same as RX_FULL. */
    FLEXIO_I2S_IP_EVENT_ERROR        = 0x03U     /*!< An error occurred during transfer */
} Flexio_I2s_Ip_EventType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/* Callback for all peripherals which support flexio_i2s
 *
 * Implements : Flexio_I2s_CallbackType_Class
 */
typedef void (*Flexio_I2s_CallbackType)(Flexio_I2s_Ip_EventType Event, void *UserData);

/**
 * FlexIO common context structure
 * This is a common structure used by all FlexIO drivers as a part of their context structure.
 * It is needed for common operations such as interrupt handling.
 */
typedef struct
{
    uint8 Instance;           /**< FlexIO device instance number */
    uint8 ResourceCount;      /**< Count of internal resources used (shifters and timers) */
    uint8 ResourceIndex;      /**< Index of first used internal resource instance (shifter and timer) */
} Flexio_I2s_Ip_CommonStateType;

/*!
 * @brief Master internal context structure
 *
 * This structure is used by the driver for its internal logic. It must
 * be provided by the application through the FLEXIO_I2S_DRV_MasterInit() function, then
 * it cannot be freed until the driver is de-initialized using FLEXIO_I2S_DRV_MasterDeinit().
 * The application should make no assumptions about the content of this structure.
 */
typedef struct
{
/*! @cond DRIVER_INTERNAL_USE_ONLY */
    Flexio_I2s_Ip_CommonStateType FlexioCommon;     /* Common flexio drivers structure */
    const uint8 *txData;                            /* Transmit buffer. */
    uint8 *rxData;                                  /* Receive buffer. */
    uint32 txRemainingWords;                        /* Number of remaining words to be transmitted. */
    uint32 rxRemainingWords;                        /* Number of remaining words to be received. */
#if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
    uint32 dummyDmaData;                            /* Dummy location for DMA transfers. */
    uint8 rxDMAChannel;                             /* Rx DMA channel number */
    uint8 txDMAChannel;                             /* Tx DMA channel number */
#endif /* (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE) */
    uint8 byteWidth;                                /* Number of bytes in a word */
    boolean Master;                                 /* Current instance is in master mode */
    Flexio_I2s_Ip_DriverType driverType;            /* Driver type: interrupts/polling/DMA */
    Flexio_I2s_Ip_StatusType status;                /* Current status of the driver */
    boolean driverIdle;                             /* Idle/busy state of the driver */
    boolean blocking;                               /* Specifies if the current transfer is blocking */
    Flexio_I2s_CallbackType callback;               /* User callback function */
    void *callbackParam;                            /* Parameter for the callback function */
/*! @endcond */
} Flexio_I2s_Ip_StateType;

/*!
 * @brief Master configuration structure
 *
 * This structure is used to provide configuration parameters for the flexio_i2s master at initialization time.
 * Implements : Flexio_I2s_Ip_MasterConfigType_Class
 */
typedef struct
{
    Flexio_I2s_Ip_DriverType driverType;      /*!< Driver type: interrupts/polling/DMA */
    uint8 ResourceIndex;                      /*!< Index of first used internal resource instance (shifter and timer) */
    uint16 DividerValue;                      /*!< Calculated divider value */
    uint8 byteWidth;                          /* Number of bytes in a word - support 1/2/4 bytes*/
    uint8 txPin;                              /*!< Flexio pin to use for transmit */
    uint8 rxPin;                              /*!< Flexio pin to use for receive */
    uint8 sckPin;                             /*!< Flexio pin to use for serial clock */
    uint8 wsPin;                              /*!< Flexio pin to use for word select */
    Flexio_I2s_CallbackType callback;         /*!< User callback function. Note that this function will be
                                                  called from the interrupt service routine, so its
                                                  execution time should be as small as possible. It can be
                                                  NULL if it is not needed */
    void *callbackParam;                      /*!< Parameter for the callback function */
#if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
    uint8 rxDMAChannel;                       /*!< Rx DMA channel number. Only used in DMA mode */
    uint8 txDMAChannel;                       /*!< Tx DMA channel number. Only used in DMA mode */
#endif /* (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE) */
    Flexio_I2s_Ip_StateType * MasterState;    /*!< Pointer to master state */
} Flexio_I2s_Ip_MasterConfigType;


/*!
 * @brief Slave configuration structure
 *
 * This structure is used to provide configuration parameters for the flexio_i2s slave at initialization time.
 * Implements : Flexio_I2s_Ip_SlaveConfigType_Class
 */
typedef struct
{
    Flexio_I2s_Ip_DriverType driverType;      /*!< Driver type: interrupts/polling/DMA */
    uint8 ResourceIndex;                      /*!< Index of first used internal resource instance (shifter and timer) */
    uint8 byteWidth;                          /* Number of bytes in a word - support 1/2/4 bytes */
    uint8 txPin;                              /*!< Flexio pin to use for transmit */
    uint8 rxPin;                              /*!< Flexio pin to use for receive */
    uint8 sckPin;                             /*!< Flexio pin to use for serial clock */
    uint8 wsPin;                              /*!< Flexio pin to use for word select */
    Flexio_I2s_CallbackType callback;         /*!< User callback function. Note that this function will be
                                                  called from the interrupt service routine, so its
                                                  execution time should be as small as possible. It can be
                                                  NULL if it is not needed */
    void *callbackParam;                      /*!< Parameter for the callback function */
#if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
    uint8 rxDMAChannel;                       /*!< Rx DMA channel number. Only used in DMA mode */
    uint8 txDMAChannel;                       /*!< Tx DMA channel number. Only used in DMA mode */
#endif /* (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE) */
    Flexio_I2s_Ip_StateType * SlaveState;     /**< Pointer to master state */
} Flexio_I2s_Ip_SlaveConfigType;


/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#endif /* (STD_ON == FLEXIO_I2S_IP_ENABLE) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_I2S_IP_TYPES_H */
