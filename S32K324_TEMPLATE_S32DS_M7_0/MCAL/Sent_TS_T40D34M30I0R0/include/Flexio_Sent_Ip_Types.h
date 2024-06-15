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

#ifndef FLEXIO_SENT_IP_TYPES_H
#define FLEXIO_SENT_IP_TYPES_H

/**
*   @file       Flexio_Sent_Ip_Types.h
*
*   @version    3.0.0
*
*   @brief      AUTOSAR Sent - Sent and Flexio generic types file.
*   @details    Contains generic Sent and Flexio types and structures.
*
*   @addtogroup FLEXIO_SENT_DRIVER
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

#include "Mcal.h"
#include "Flexio_Sent_Ip_Defines.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FLEXIO_SENT_IP_TYPES_VENDOR_ID                      43
#define FLEXIO_SENT_IP_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define FLEXIO_SENT_IP_TYPES_AR_RELEASE_MINOR_VERSION       7
#define FLEXIO_SENT_IP_TYPES_AR_RELEASE_REVISION_VERSION    0
#define FLEXIO_SENT_IP_TYPES_SW_MAJOR_VERSION               3
#define FLEXIO_SENT_IP_TYPES_SW_MINOR_VERSION               0
#define FLEXIO_SENT_IP_TYPES_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Flexio_Sent_Ip_Defines header file are of the same vendor */
#if (FLEXIO_SENT_IP_DEFINES_VENDOR_ID != FLEXIO_SENT_IP_TYPES_VENDOR_ID)
    #error "Flexio_Sent_Ip_Defines.h and Flexio_Sent_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Flexio_Sent_Ip_Defines header file are of the same Autosar version */
#if ((FLEXIO_SENT_IP_DEFINES_AR_RELEASE_MAJOR_VERSION    != FLEXIO_SENT_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_SENT_IP_DEFINES_AR_RELEASE_MINOR_VERSION    != FLEXIO_SENT_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_SENT_IP_DEFINES_AR_RELEASE_REVISION_VERSION != FLEXIO_SENT_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Flexio_Sent_Ip_Defines.h and Flexio_Sent_Ip_Types.h are different"
#endif
/* Check if current file and Flexio_Sent_Ip_Defines header file are of the same Software version */
#if ((FLEXIO_SENT_IP_DEFINES_SW_MAJOR_VERSION != FLEXIO_SENT_IP_TYPES_SW_MAJOR_VERSION) || \
     (FLEXIO_SENT_IP_DEFINES_SW_MINOR_VERSION != FLEXIO_SENT_IP_TYPES_SW_MINOR_VERSION) || \
     (FLEXIO_SENT_IP_DEFINES_SW_PATCH_VERSION != FLEXIO_SENT_IP_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Flexio_Sent_Ip_Defines.h and Flexio_Sent_Ip_Types.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((FLEXIO_SENT_IP_TYPES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
            (FLEXIO_SENT_IP_TYPES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Flexio_Sent_Ip_Types.h and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define     SENT_MAX_NIBBLE_DATA            ((uint8) 0x06U)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Sent_SyncAsyncType
* @details        Used for value received by TRESOS interface configuration.
*                 Describe the channel type.
*
*/
/* @implements Flexio_Sent_Ip_SyncAsyncType_enum */
typedef enum
{
    SENT_PAUSE_PULSE_DISABLED = 0U,
    SENT_PAUSE_PULSE_ENABLED = 1U
} Flexio_Sent_Ip_SyncAsyncType;
/**
* @brief          Flexio_Sent_Ip_DriverType
* @details        This to present the way to handle Fast/Serial message
*
*/
typedef enum
{
    FLEXIO_DRIVER_TYPE_INTERRUPTS    = 0U,  /*!< Driver uses interrupts for data transfers */
    FLEXIO_DRIVER_TYPE_POLLING       = 1U,  /*!< Driver is based on polling */
    FLEXIO_DRIVER_TYPE_DMA           = 2U,  /*!< Driver uses DMA for data transfers */
} Flexio_Sent_Ip_DriverType;

typedef enum
{
    STATUS_FLEXIO_SENT_IP_ERROR_CRC                     = 0x000U,
    STATUS_FLEXIO_SENT_IP_ERROR_CALIBRATION_LENGTH      = 0x001U,
    STATUS_FLEXIO_SENT_IP_ERROR_NIBBLE_VALUE            = 0x002U,
    STATUS_FLEXIO_SENT_IP_ERROR_FALLING_EDGES_NUMBER    = 0X003U,
    STATUS_FLEXIO_SENT_IP_ERROR_SUCCESSIVE_CALIBRATION  = 0X004U,
    STATUS_FLEXIO_SENT_IP_ERROR_TIMEOUT                 = 0X005U
} Flexio_Sent_Ip_ErrorStatusType;    

typedef enum
{
    STATUS_FLEXIO_SENT_IP_SUCCESS                   = 0x000U,
    STATUS_FLEXIO_SENT_IP_ERROR                     = 0x001U,
    STATUS_FLEXIO_SENT_IP_BUSY                      = 0x002U,
    STATUS_FLEXIO_SENT_IP_BUS_BUSY                  = 0x003U,
    STATUS_FLEXIO_SENT_IP_CRCFAILED                 = 0x004U,
    STATUS_FLEXIO_SENT_IP_CRCPASSED                 = 0x005U,
    STATUS_FLEXIO_SENT_IP_TIMEOUT                   = 0X006U
} Flexio_Sent_Ip_StatusType;                

/**
* @brief          Sent_StatusFastProcessType
* @details        To check data processing when convert timer data to SENT's nibble value 
*
*/
/* @implements Sent_StatusFastProcessType_enum */
typedef enum
{
    STATUS_SENT_FAST_IDLE               = 0U,   /*!< Status before receiving sync/calibration pulse */
    STATUS_SENT_FAST_SYNC_CALIB         = 1U,   /*!< sync/calibration pulse is checked done */
    STATUS_SENT_FAST_CHECKED            = 2U,   /*!< Frame receiving is done */
    STATUS_SENT_FAST_RE_SYNC_CALIB      = 3U,   /*!< CRC checking is done */
    STATUS_SENT_FAST_PAUSE_PULSE        = 4U    /*!< CRC checking is done in case using pause pulse*/
} Sent_StatusFastProcessType;

/**
* @brief          Sent_StatusCRCImplementType
* @details        To chose the way to Fast/Slow message implement CRC
*
*/
/* @implements Sent_StatusCRCImplementType_enum */
typedef enum
{
    SENT_RECOMMENDED_IMPLEMENTATION_16_ELEMENT     = 0U,   /*!< CRC Recommended Implementation: Implementation using 16 Element Array */
    SENT_LEGACY_IMPLEMENTATION_16_ELEMENT          = 1U,   /*!< CRC Legacy Implementation: Implementation using 16 Element Array  */
#if(STD_ON == FLEXIO_SENT_IP_CRC_256_ELEMENT_ARRAY_SUPPORTING)
    SENT_RECOMMENDED_IMPLEMENTATION_256_ELEMENT    = 2U,   /*!< CRC Recommended Implementation: Implementation using 256 Element Array */
    SENT_LEGACY_IMPLEMENTATION_256_ELEMENT         = 3U,   /*!< CRC Legacy Implementation: Implementation using 256 Element Array  */
#endif
} Sent_StatusCRCImplementType;

/**
* @brief          Sent_StatusSerialProcessType
* @details        To check data processing when covert timer data to SENT's nibble value 
*
*/
typedef enum
{
    STATUS_SENT_SERIAL_IDLE             = 0U,   /*!< Status of serial message before processing */
    STATUS_SENT_SERIAL_SHORT            = 1U,   /*!< Serial message is SHORT SERIAL type */
    STATUS_SENT_SERIAL_ENHANCED         = 2U,   /*!< Serial message is ENHANCED SERIAL type */
} Sent_StatusSerialProcessType;

/**
* @brief          Flexio_Sent_IP_SlowSerialType
* @details        
*
*/
/* @implements Flexio_Sent_IP_SlowSerialType_enum */
typedef enum
{
    SENT_SHORT_SERIAL = 0,      /*!< Serial message is SHORT SERIAL type */
    SENT_ENHANCED_SERIAL_4_ID,  /*!< Serial message is ENHANCED SERIAL type */
    SENT_ENHANCED_SERIAL_8_ID   /*!< Serial message is ENHANCED SERIAL type */
} Flexio_Sent_IP_SlowSerialType;

/**
* @brief          Flexio_Sent_SerialMsgType
* @details        Used for received Serial data. It contains the data received, after being processed
*
*/
/* @implements Flexio_Sent_SerialMsgType_struct */
typedef struct
{
    Flexio_Sent_IP_SlowSerialType   MsgType;    /*!< Type of serial message (SHORT OR ENHANCED 4BIT/8BIT) */
    uint8               ChannelId;            /*!< The channel number on which the data was received */
    uint8               Instance;               /*!< The Instance number on which the data was received */
    uint8               MessageId;            /*!< Serial Message ID */
    uint16              MessageData;         /*!< Data contained in the Serial Message */
    uint8               SerialCrc;            /*!< Serial Message CRC */
} Flexio_Sent_SerialMsgType;


/**
* @brief          Flexio_Sent_FastMsgType
* @details        Used for received Fast data. It contains the data received, after being processed
*
*/
/* @implements Flexio_Sent_FastMsgType_struct */
typedef struct 
{
    uint8           Instance;                           /*!< The Instance number on which the data was received */
    uint8           ChannelId;                        /*!< The channel number on which the data was received */
    uint8           Length;                           /*!< Lenght of the fast message */
    uint8           DataNibble[SENT_MAX_NIBBLE_DATA];   /*!< Content of each nibble in the fast message */
    uint8           StatusCommunication;                /*!< The Status Communication Nibble */
    uint8           FastCrc;                          /*!< Fast Message CRC */
} Flexio_Sent_FastMsgType;

/**
 * @brief Callback for all peripherals which supports SENT features
 */
typedef void (*Sent_CallbackType)(Flexio_Sent_Ip_ErrorStatusType ErrorEvent);

/**
 * @brief Callback for all peripherals which supports SENT features
 */
typedef void (*Sent_FastNotificationType)(Flexio_Sent_Ip_StatusType Event, Flexio_Sent_FastMsgType *SentFastMsg);

/**
 * @brief Callback for all peripherals which supports SENT features
 */
typedef void (*Sent_SlowNotificationType)(Flexio_Sent_Ip_StatusType Event, Flexio_Sent_SerialMsgType *SentSerialMsg);

/**
 * @brief Flexio Channel configuration structure
 * @details Used for configuring each channel of the Flexio Controller
 * 
 */
typedef struct
{
    uint8       Timer;                          /*!< Which FLEXIO Timer is used for SENT channel */
    uint8       Pin;                            /*!< Which FLEXIO Pin is input for SENT channel */
    uint8       NibbleCnt;                      /*!< Data Nibbles supported in this Channel */
    uint32       TickLengthUs;                   /*!< Tick length is Us */
#if(STD_ON == FEATURE_FLEXIO_DMA_ENABLE)
    uint8       SentDmaChannel;                 /*!< Reference to the DMA Channel configure for the Request */
    uint8       DmaBufferDepth;           /*!< Number of received frame before handle data */
    uint32*     DmaTimerBuffer;           /*!< Number of received frame before handle data */
#endif
    Sent_StatusCRCImplementType     FastCrc;        /*!< CRC implementation type */
    Sent_StatusCRCImplementType     SlowCrc;        /*!< CRC implementation type */
    boolean                         StatusNibbleCrcCalIncluding;        /*!< Status Nibble Crc Calculate Including */
    Flexio_Sent_Ip_SyncAsyncType    PausePulse; /*!< pause pulse configuration*/
} Flexio_ChnlConfig;


/**
 * @brief Flexio data processing structure
 * @details    * n8NibbleVal[DataIndx = 0]=Status & Communication
               * n8NibbleVal[DataIndx = 1]=1st nibble, ... 
               * n8NibbleVal[DataIndx = NIBBLE]=NIBBLEth nibble
               * n8NibbleVal[DataIndx = NIBBLE+1]=CRC 
*/
/* @implements Flexio_DataProcessType_struct */
typedef struct
{
    uint8                           NibbleVal[SENT_MAX_NIBBLE_DATA + 2];  
    uint8                           SerialData[18]; 
    uint8                           DataIndx; 
    uint8                           FastMsgCount;
    uint8                           TimerbufferIndx;
    uint32                          TimerVal;
    Sent_StatusFastProcessType      FastState;
    Sent_StatusSerialProcessType    SerialState;
} Flexio_DataProcessType;

/*!
 * @brief Receiver internal context structure
 *
 * @details This structure is used by the driver for its internal logic. It must
 * be provided by the application through the Flexio_Sent_Ip_Init() function, then
 * it cannot be freed until the driver is de-initialized using Flexio_Sent_Ip_DeInit().
 * The application should make no assumptions about the content of this structure.
 */
/* @implements Flexio_Sent_Ip_StateType_struct */
typedef struct 
{
    uint8                       Instance;
    uint8                       ResourceAllocation;                                      /*!< Count the number of Flexio Timer which is used for SENT */
    Flexio_Sent_Ip_StatusType   Status;                                                  /*!< Current Status of the driver */
    Flexio_Sent_Ip_DriverType   DriverType;                                              /*!< The way to handle Fast/Serial message */
    Sent_CallbackType           SentFastErrorNotif[FEATURE_FLEXIO_MAX_TIMER_COUNT];        /*!< Fast CRC callback function */
    Sent_CallbackType           SentSerialErrorNotif[FEATURE_FLEXIO_MAX_TIMER_COUNT];      /*!< Slow CRC callback function */
    Sent_FastNotificationType   SentFastNotif[FEATURE_FLEXIO_MAX_TIMER_COUNT];           /*!< Fast callback function */
    Sent_SlowNotificationType   SentSerialNotif[FEATURE_FLEXIO_MAX_TIMER_COUNT];         /*!< Serial message callback function */
    Flexio_ChnlConfig           ChnlCfg[FEATURE_FLEXIO_MAX_TIMER_COUNT];                 /*!< Index of first used internal resource Instance (Timer) */
    boolean                     TransferErrorDetect[FEATURE_FLEXIO_MAX_TIMER_COUNT];
} Flexio_Sent_Ip_StateType;


 /*!
 * @brief Sent configuration structure
 *
 * @details This structure is used to provide configuration parameters for the Flexio based SENT at initialization time.
 */
/* @implements Flexio_Sent_Ip_UserConfigType_struct */
typedef struct
{
    const uint8                           ControllerId;           /*!< Id of Controller contain channel*/
    const uint8                           ControllerHwOffset;     /*!< HWOffet of Controller contain channel*/
    const uint8                           ChannelId;              /*!< Id of channel*/
    const uint8                           ChannelHwOffset;        /*!< HWOffet of channel*/
    const uint8                           SentPin;                /*!< Pin is used for trigger */
    const Flexio_Sent_Ip_SyncAsyncType    PausePulse;           /*!< pause pulse configuration*/
    const uint8                           NumberOfNibbles;        /*!< Configure number of nibbles */
    const uint32                           TickTime;               /*!< Configure Tick time in Us */
#if(STD_ON == FEATURE_FLEXIO_DMA_ENABLE)
    const uint8                           SentDmaChannel;         /*!< Reference to the DMA Channel configure for the Request */
    const uint8                           DmaBufferDepth;           /*!< Number of received frame before handle data */
    uint32*                               DmaTimerBuffer;           /*!< Number of received frame before handle data */
#endif
    const boolean                         StatusNibbleCrcCalIncluding;        /*!< Status Nibble Crc Calculate Including */
    const Sent_StatusCRCImplementType     SentFastCrcImpelement;  /*!< CRC implementation for Fast message */
    const Sent_StatusCRCImplementType     SentSlowCrcImpelement;  /*!< CRC implementation for Serial message */
    const Sent_CallbackType               SentFastErrorNotif;       /*!< Fast callback function */
    const Sent_CallbackType               SentSerialErrorNotif;     /*!< Serial message callback function */
    const Sent_FastNotificationType       SentFastNotif;          /*!< Fast callback function */
    const Sent_SlowNotificationType       SentSerialNotif;        /*!< Serial message callback function */
} Flexio_Sent_Ip_UserConfigType;

 /*!
 * @brief Sent configuration structure
 *
 * @details This structure is used to provide configuration parameters for a controller.
 */
typedef struct 
{
    const uint8     CtrHwOffset;          /*!< HWoffet of configured controller */
    const uint8     CtrHwID;              /*!< HWID of configured controller */
    const uint8     ChnlConfigured;       /*!< Summary of configured channels in a controller. */
    const Flexio_Sent_Ip_DriverType     DriverType;
    const Flexio_Sent_Ip_UserConfigType * const * const ChnlConfig;
    Flexio_Sent_Ip_StateType            *CtrlState;
} Flexio_CtrlConfigType;

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_SENT_IP_TYPES_H */
