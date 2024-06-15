/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : SIUL2
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_P07_D2306_ASR_REL_4_7_REV_0000_20230629
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

#ifndef DIO_CFG_H
#define DIO_CFG_H

/**
*   @file Dio_Cfg.h
*   @implements Dio_Cfg.h_Artifact
*
*   @defgroup DIO_CFG Dio Cfg
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Std_Types.h"
#include "Siul2_Dio_Ip_Cfg.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
#define DIO_VENDOR_ID_CFG_H                   43
#define DIO_AR_RELEASE_MAJOR_VERSION_CFG_H    4
#define DIO_AR_RELEASE_MINOR_VERSION_CFG_H    7
#define DIO_AR_RELEASE_REVISION_VERSION_CFG_H 0
#define DIO_SW_MAJOR_VERSION_CFG_H            3
#define DIO_SW_MINOR_VERSION_CFG_H            0
#define DIO_SW_PATCH_VERSION_CFG_H            0

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Dio_Cfg.h and StandardTypes.h file are of the same Autosar version */
    #if ((DIO_AR_RELEASE_MAJOR_VERSION_CFG_H != STD_AR_RELEASE_MAJOR_VERSION) ||   \
        (DIO_AR_RELEASE_MINOR_VERSION_CFG_H != STD_AR_RELEASE_MINOR_VERSION)       \
        )
        #error "AUTOSAR Version Numbers of Dio_Cfg.h and StandardTypes.h are different"
    #endif
#endif

/* Check if Dio_Cfg.h and Siul2_Dio_Ip_Cfg.h files are of the same vendor.*/
#if (DIO_VENDOR_ID_CFG_H != SIUL2_DIO_IP_VENDOR_ID_CFG_H)
    #error "Dio_Cfg.h and Siul2_Dio_Ip_Cfg.h have different vendor ids"
#endif
/* Check if Dio_Cfg.h and Siul2_Dio_Ip_Cfg.h files are of the same Autosar version.*/
#if ((DIO_AR_RELEASE_MAJOR_VERSION_CFG_H    != SIUL2_DIO_IP_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (DIO_AR_RELEASE_MINOR_VERSION_CFG_H    != SIUL2_DIO_IP_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (DIO_AR_RELEASE_REVISION_VERSION_CFG_H != SIUL2_DIO_IP_AR_RELEASE_REVISION_VERSION_CFG_H) \
    )
    #error "AutoSar Version Numbers of Dio_Cfg.h and Siul2_Dio_Ip_Cfg.h are different"
#endif
/* Check if Dio_Cfg.h and Siul2_Dio_Ip_Cfg.h files are of the same Software version.*/
#if ((DIO_SW_MAJOR_VERSION_CFG_H != SIUL2_DIO_IP_SW_MAJOR_VERSION_CFG_H) || \
     (DIO_SW_MINOR_VERSION_CFG_H != SIUL2_DIO_IP_SW_MINOR_VERSION_CFG_H) || \
     (DIO_SW_PATCH_VERSION_CFG_H != SIUL2_DIO_IP_SW_PATCH_VERSION_CFG_H)    \
    )
    #error "Software Version Numbers of Dio_Cfg.h and Siul2_Dio_Ip_Cfg.h are different"
#endif
       
/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/
/**
* @brief      Dio driver Channel Groups configuration switch.
*
*/
#define DIO_CHANNEL_GROUPS_AVAILABLE
/**
* @brief          Enable or Disable Development Error Detection.
*
* @implements     DIO_DEV_ERROR_DETECT_define
*/
#define DIO_DEV_ERROR_DETECT    (STD_ON)

/**
* @brief          Function @p Dio_GetVersionInfo() enable switch.
*
* @implements     DIO_VERSION_INFO_API_define
*/
#define DIO_VERSION_INFO_API    (STD_OFF)

/**
* @brief          Function @p Dio_FlipChannel() enable switch.
*/
#define DIO_FLIP_CHANNEL_API    (STD_ON)

/**
* @brief          Function @p Dio_MaskedWritePort() enable switch.
*/
#define DIO_MASKEDWRITEPORT_API (STD_ON)

/**
* @brief          Platform specific define stating if mapping of port bits over port pins is reversed.
*/
#define DIO_REVERSED_MAPPING_OF_PORT_BITS_OVER_PORT_PINS    (STD_ON)

/**
* @brief          Reversed port functionality enable switch.
*
* @implements DIO_REVERSEPORTBITS_define
*/
#define DIO_REVERSEPORTBITS     (STD_ON)


/**
* @brief          Undefined pins masking enable switch.
*/
#define DIO_READZERO_UNDEFINEDPORTS (STD_OFF)



/**
* @brief Enable/Disable multiocre function from the driver
*/
#define DIO_MULTICORE_ENABLED          (STD_OFF)

/**
* @brief          Number of implemented ports.
*
* @note           Used for channel, port and channel group validation.
*/
#define DIO_NUM_PORTS_U16               ((uint16)0xe)

/**
* @brief          The number of partition on the port
*
* @note           Used for port validation.
*/
#define DIO_PORT_PARTITION_U16          ((uint16)14U)

/**
* @brief          Number of channels in a port.
*
* @note           Used for channel, port and channel group validation.
*/
#define DIO_NUM_CHANNELS_PER_PORT_U16   ((uint16)((uint16)sizeof(Dio_PortLevelType) * 0x8U))

/**
* @brief          Number of channels available on the implemented ports.
*
* @note           Used for channel validation.
*/
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    #define DIO_NUM_CHANNELS_U16            ((uint16)154U)
#endif


/**
* @brief The number of partition on the channel.
*
* @note           Used for channel validation.
*/
#define DIO_CHANNEL_PARTITION_U16           ((uint16)224U)

/**
* @brief          Mask representing no available channels on a port.
*
* @note           Used for channel validation.
*/
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    #define DIO_NO_AVAILABLE_CHANNELS_U16   ((Dio_PortLevelType)0x0U)
#endif

/**
* @brief          Mask representing the maximum valid offset for a channel group.
*
* @note           Used for channel group validation.
*/
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    #define DIO_MAX_VALID_OFFSET_U8         ((uint8)0xFU)
#endif

/**
*   @brief   Enables or disables the access to a hardware register from user mode
*            USER_MODE_SOFT_LOCKING:        All reads to hw registers will be done via REG_PROT, user mode access
*            SUPERVISOR_MODE_SOFT_LOCKING:  Locks the access to the registers only for supervisor mode
*
*   @note    Currently, no register protection mechanism is used for Dio driver.
*/
#define DIO_USER_MODE_SOFT_LOCKING      (STD_OFF)

/**
* @brief          Dio driver Pre-Compile configuration switch.
*/
#define DIO_PRECOMPILE_SUPPORT


/**
* @brief Support for User mode.
*        If this parameter has been configured to 'STD_ON', the Dio driver code can be executed from both supervisor and user mode.
*
*/

#define DIO_ENABLE_USER_MODE_SUPPORT   (STD_OFF)


#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #ifdef DIO_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == DIO_ENABLE_USER_MODE_SUPPORT)
    #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Dio in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
  #endif /* (STD_ON == DIO_ENABLE_USER_MODE_SUPPORT) */
 #endif /* ifdef DIO_ENABLE_USER_MODE_SUPPORT*/
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/**
* @brief Number of SIUL2 instances on the platform.
*/
#define DIO_NUM_SIUL2_INSTANCES_U8      ((uint8)1)

/**
* @brief List of identifiers for each of the SIUL2 instances on the platform
*/
#define DIO_SIUL2_0_U8        ((uint8)0)

/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/

/**
* @brief          Symbolic name for the configuration Dio_ConfigPC.
*
*/
#define Dio_ConfigPC    (Dio_Config)

/* ========== DioConfig ========== */

/* ---------- DioPort_AL ---------- */

/**
* @brief          Symbolic name for the port DioPort_AL.
*
*/
#define DioConf_DioPort_DioPort_AL  ((uint8)0x00U)

/* ---------- DioPort_AH ---------- */

/**
* @brief          Symbolic name for the port DioPort_AH.
*
*/
#define DioConf_DioPort_DioPort_AH  ((uint8)0x01U)



/**
* @brief          Symbolic name for the channel DioChannel_PTA29_LED1_BLUE.
*
*/
#define  DioConf_DioChannel_DioChannel_PTA29_LED1_BLUE ((uint16)0x001dU)



/**
* @brief          Symbolic name for the channel DioChannel_PTA30_LED2_GREEN.
*
*/
#define  DioConf_DioChannel_DioChannel_PTA30_LED2_GREEN ((uint16)0x001eU)



/**
* @brief          Symbolic name for the channel DioChannel_PTA31_LED3_RED.
*
*/
#define  DioConf_DioChannel_DioChannel_PTA31_LED3_RED ((uint16)0x001fU)

/**
* @brief        Symbolic name for the channel group DioChannelGroup_LED1_LED2_LED3.
*
*/

#define DioConf_DioChannelGroup_DioChannelGroup_LED1_LED2_LED3    \
(&DioConfig_aChannelGroupList[0])
/* ---------- DioPort_BL ---------- */

/**
* @brief          Symbolic name for the port DioPort_BL.
*
*/
#define DioConf_DioPort_DioPort_BL  ((uint8)0x02U)

/* ---------- DioPort_BH ---------- */

/**
* @brief          Symbolic name for the port DioPort_BH.
*
*/
#define DioConf_DioPort_DioPort_BH  ((uint8)0x03U)



/**
* @brief          Symbolic name for the channel DioChannel_PTB18_LED4_YELLOW.
*
*/
#define  DioConf_DioChannel_DioChannel_PTB18_LED4_YELLOW ((uint16)0x0032U)



/**
* @brief          Symbolic name for the channel DioChannel_PTB26_KEY1.
*
*/
#define  DioConf_DioChannel_DioChannel_PTB26_KEY1 ((uint16)0x003aU)



/**
* @brief          Symbolic name for the channel DioChannel_PTB19_KEY2.
*
*/
#define  DioConf_DioChannel_DioChannel_PTB19_KEY2 ((uint16)0x0033U)



/**
* @brief          Symbolic name for the channel DioChannel_PTB20_KEY3.
*
*/
#define  DioConf_DioChannel_DioChannel_PTB20_KEY3 ((uint16)0x0034U)

/**
* @brief        Symbolic name for the channel group DioChannelGroup_KEY2_KEY3.
*
*/

#define DioConf_DioChannelGroup_DioChannelGroup_KEY2_KEY3    \
(&DioConfig_aChannelGroupList[1])
/* ---------- DioPort_CL ---------- */

/**
* @brief          Symbolic name for the port DioPort_CL.
*
*/
#define DioConf_DioPort_DioPort_CL  ((uint8)0x04U)

/* ---------- DioPort_CH ---------- */

/**
* @brief          Symbolic name for the port DioPort_CH.
*
*/
#define DioConf_DioPort_DioPort_CH  ((uint8)0x05U)

/* ---------- DioPort_DL ---------- */

/**
* @brief          Symbolic name for the port DioPort_DL.
*
*/
#define DioConf_DioPort_DioPort_DL  ((uint8)0x06U)

/* ---------- DioPort_DH ---------- */

/**
* @brief          Symbolic name for the port DioPort_DH.
*
*/
#define DioConf_DioPort_DioPort_DH  ((uint8)0x07U)

/* ---------- DioPort_EL ---------- */

/**
* @brief          Symbolic name for the port DioPort_EL.
*
*/
#define DioConf_DioPort_DioPort_EL  ((uint8)0x08U)

/* ---------- DioPort_EH ---------- */

/**
* @brief          Symbolic name for the port DioPort_EH.
*
*/
#define DioConf_DioPort_DioPort_EH  ((uint8)0x09U)


/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/

/**
* @brief          Type of a DIO port representation.
*
* @implements     Dio_PortType_typedef
*/
typedef uint8 Dio_PortType;

/**
* @brief          Type of a DIO channel representation.
*
* @implements     Dio_ChannelType_typedef
*/
typedef uint16 Dio_ChannelType;

/**
* @brief          Type of a DIO port levels representation.
*
* @implements     Dio_PortLevelType_typedef
*/
typedef uint16 Dio_PortLevelType;

/**
* @brief          Type of a DIO channel levels representation.
*
* @implements     Dio_LevelType_typedef
*/
typedef uint8 Dio_LevelType;

/**
* @brief          Type of a DIO channel group representation.
*
* @implements     Dio_ChannelGroupType_struct
*/
typedef struct
{
    Dio_PortType      port;      /**< @brief Port identifier.  */
    uint8             u8offset;    /**< @brief Bit offset within the port. */
    Dio_PortLevelType mask;      /**< @brief Group mask. */
} Dio_ChannelGroupType;

/**
* @brief          Type of a DIO configuration structure.
*
* @note           In this implementation there is no need for a configuration
*                 structure there is only a dummy field, it is recommended
*                 to initialize this field to zero.
*
* @implements     Dio_ConfigType_struct
*/
typedef struct
{
    uint8 u8NumChannelGroups; /**< @brief Number of channel groups in configuration */
    const Dio_ChannelGroupType * pChannelGroupList;     /**< @brief
                                               Pointer to list of channel groups in configuration */
    const uint32 * pau32Dio_ChannelToPartitionMap;      /**< @brief Pointer to channel to partition mapping */
    const uint32 * pau32Dio_PortToPartitionMap;         /**< @brief Pointer to port to partition mapping */
} Dio_ConfigType;

/*=================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/
#define DIO_START_SEC_CONST_8
#include "Dio_MemMap.h"

/**
* @brief Array of values storing the SIUL2 instance each port on the platform belongs to
*/
extern const uint8 Dio_au8PortSiul2Instance[DIO_NUM_PORTS_U16];

/**
* @brief Array of values storing the offset PORT0 has inside the SIUL2 instance it
*        belongs to
*/
extern const uint8 Dio_au8Port0OffsetInSiul2Instance[DIO_NUM_SIUL2_INSTANCES_U8];


#define DIO_STOP_SEC_CONST_8
#include "Dio_MemMap.h"

#define DIO_START_SEC_CONST_32
#include "Dio_MemMap.h"

/**
* @brief Array containing list of mapping channel for partition
*/
extern const uint32 Dio_au32ChannelToPartitionMap[DIO_CHANNEL_PARTITION_U16];

/**
* @brief Array containing list of mapping port for partition
*/
extern const uint32 Dio_au32PortToPartitionMap[DIO_PORT_PARTITION_U16];

#define DIO_STOP_SEC_CONST_32
#include "Dio_MemMap.h"

#define DIO_START_SEC_CONST_16
#include "Dio_MemMap.h"
/**
* @brief Array of bitmaps of output pins available per port
*/
extern const Dio_PortLevelType Dio_aAvailablePinsForWrite[DIO_NUM_PORTS_U16];

/**
* @brief Array of bitmaps of input pins available per port
*/
extern const Dio_PortLevelType Dio_aAvailablePinsForRead[DIO_NUM_PORTS_U16];

#define DIO_STOP_SEC_CONST_16
#include "Dio_MemMap.h"
#define DIO_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dio_MemMap.h"
/**
* @brief          List of channel groups in configuration DioConfig.
*/
extern const Dio_ChannelGroupType DioConfig_aChannelGroupList[2];

/**
* @brief          List of channel groups mapping with partition in configuration DioConfig.
*/
extern const Dio_ChannelGroupType * const Dio_pxChannelGroupsListForEachPartition[1][2];

#define DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dio_MemMap.h"

/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif  /* DIO_CFG_H */

/** @} */
