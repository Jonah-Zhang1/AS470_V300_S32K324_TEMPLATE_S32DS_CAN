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

/**
*   @file
*
*   @addtogroup I2C_DRIVER_CONFIGURATION I2c Driver Configurations
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif


/**
* @page misra_violations MISRA-C:2012 violations
*
* @section CDD_I2c_PBcfg_c_REF_1
* Violates MISRA 2012 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a violation
* since all header files are protected against multiple inclusions
*
* @section CDD_I2c_PBcfg_c_REF_2
* Violates MISRA 2012 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section CDD_I2c_PBcfg_c_REF_3
* Violates MISRA 2012 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is required.
*
* @section CDD_I2c_PBcfg_c_REF_4
* Violates MISRA 2012 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/

/**
* @implements CDD_I2c_PBcfg.c_Artifact
*/
/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_I2c.h"
#include "I2c_Ipw_PBcfg.h"

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif /* (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_PBCFG_VENDOR_ID_C                     43   
#define I2C_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define I2C_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define I2C_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define I2C_PBCFG_SW_MAJOR_VERSION_C              3
#define I2C_PBCFG_SW_MINOR_VERSION_C              0
#define I2C_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I2c header file are of the same vendor */
#if (I2C_PBCFG_VENDOR_ID_C != I2C_VENDOR_ID)
    #error "I2c_PBcfg.c and CDD_I2c.h have different vendor ids"
#endif
/* Check if current file and I2c header file are of the same Autosar version */
#if ((I2C_PBCFG_AR_RELEASE_MAJOR_VERSION_C != I2C_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_PBCFG_AR_RELEASE_MINOR_VERSION_C != I2C_AR_RELEASE_MINOR_VERSION) || \
     (I2C_PBCFG_AR_RELEASE_REVISION_VERSION_C != I2C_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of I2c_PBcfg.c and CDD_I2c.h are different"
#endif
/* Check if current file and I2c header file are of the same Software version */
#if ((I2C_PBCFG_SW_MAJOR_VERSION_C != I2C_SW_MAJOR_VERSION) || \
     (I2C_PBCFG_SW_MINOR_VERSION_C != I2C_SW_MINOR_VERSION) || \
     (I2C_PBCFG_SW_PATCH_VERSION_C != I2C_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of I2c_PBcfg.c and CDD_I2c.h are different"
#endif

/* Check if current file and DEM header file are of the same version */
#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((I2C_PBCFG_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (I2C_PBCFG_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of I2c_PBcfg.c and Dem.h are different"
    #endif
#endif
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/


/**
* @brief          Paritition IDs.
* @details        Paritition IDs.
*
* @api
*/



#define I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref I2c_PBcfg_c_REF_2 Precautions shall be taken
* in order to prevent the contents of a header file being included more than once.
*/
#include "I2c_MemMap.h"


/**
* @brief        Definition of I2c hardware channel structure.
* @details      Configures the hardware peripheral of an I2c channel.
*               Configuration set by calling I2c_Init() API.
*/
static const I2c_HwUnitConfigType I2c_ChannelConfigPB[1] =
{

    /* Start of I2c_ChannelConfig[0]*/
    {
        /* The hardware channel ID. */
        (I2c_HwUnitType) I2C_LPI2C_0,

        /* The Partition Id */
        (I2c_PartCoreType)I2C_SPURIOUS_CORE_ID,

        /* The master/slave mode of the channel. */
        I2C_MASTER_MODE,

        /* The hardware channel type */        
        I2C_LPI2C_CHANNEL,
        
        {            
                
            &I2c_Ipw_ChannelConfig0                
            
        }
    }/* End of I2c_ChannelConfigPB[0]. */

};




/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

    
/**
* @brief          Initialization data for the I2c driver.
* @details        A structure is provided to the I2c initialization routines for configuration.
*                 The configuration structure for spurious_core.
*
*/

/**
* @violates @ref I2c_PBcfg_c_REF_3 Functions and objects should not be defined with external
* linkage if they are referenced in only one translation unit.
*/
/**
* @violates @ref I2c_PBcfg_c_REF_5 Function with external linkage is not visible.
*/

const I2c_ConfigType I2c_Config =
{
    /* The Partition Core Id */
    (I2c_PartCoreType)I2C_SPURIOUS_CORE_ID,

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /* Pointer to DEM error reporting configurations. */
    &I2c_DemConfig,
#endif

    /* Pointer to I2C Hardware Unit configuration. */
    &I2c_ChannelConfigPB
};


    


#define I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref CDD_I2c_PBcfg_c_REF_1 MISRA 2012 Required Rule 19.15, Repeated include file
* @violates @ref CDD_I2c_PBcfg_c_REF_2 MISRA 2012 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "I2c_MemMap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

