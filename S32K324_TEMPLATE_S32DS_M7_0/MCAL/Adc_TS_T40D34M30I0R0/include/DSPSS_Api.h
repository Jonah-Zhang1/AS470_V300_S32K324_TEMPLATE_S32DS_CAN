/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : ADC_SAR
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

#ifndef DSPSS_API_H
#define DSPSS_API_H

/**
*   @file DSPSS_Api.h
*
*   @addtogroup IP_SDADC
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "DSPSS_Types.h"





/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define DSPSS_VENDOR_ID_API                      43
#define DSPSS_AR_RELEASE_MAJOR_VERSION_API       4
#define DSPSS_AR_RELEASE_MINOR_VERSION_API       7
#define DSPSS_AR_RELEASE_REVISION_VERSION_API    0
#define DSPSS_SW_MAJOR_VERSION_API               3
#define DSPSS_SW_MINOR_VERSION_API               0
#define DSPSS_SW_PATCH_VERSION_API               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if DSPSS_Api.h file and DSPSS_Types.h file are of the same vendor */
#if (DSPSS_VENDOR_ID_API != DSPSS_VENDOR_ID_TYPES)
    #error "DSPSS_Api.h and DSPSS_Types.h have different vendor ids"
#endif

/* Check if DSPSS_Api.h file and DSPSS_Types.h file are of the same Autosar version */
#if ((DSPSS_AR_RELEASE_MAJOR_VERSION_API != DSPSS_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (DSPSS_AR_RELEASE_MINOR_VERSION_API != DSPSS_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (DSPSS_AR_RELEASE_REVISION_VERSION_API != DSPSS_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of DSPSS_Api.h and DSPSS_Types.h are different"
#endif

/* Check if DSPSS_Api.h file and DSPSS_Types.h file are of the same Software version */
#if ((DSPSS_SW_MAJOR_VERSION_API != DSPSS_SW_MAJOR_VERSION_TYPES) || \
     (DSPSS_SW_MINOR_VERSION_API != DSPSS_SW_MINOR_VERSION_TYPES) || \
     (DSPSS_SW_PATCH_VERSION_API != DSPSS_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of DSPSS_Api.h and DSPSS_Types.h are different"
#endif

#if (SDADC_IP_DSPSS_ENABLED == STD_ON)
/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"


/**
 * Initializes the DSPSS by loading the FW init PMEM and default configuration into XMEM.
 * @return Return error code
 */
DSPSS_StatusType DSPSS_Init(void);


/**
 * DSP initialization
 */
void DSPSS_DspInit(void);


/**
 * This function allows the user to de-initialize the DSPSS
 * @return Return error code
 */
DSPSS_StatusType DSPSS_Deinit(void);


/**
 * This function get the information about CFSDADC firmware
 * @param FirmwareVersion The pointer to the address that will contain the CFSDADC firmware build tag
 * @param Length The length of the string that will contain the CFSDADC firmware build tag
 * @return Return error code
 */
DSPSS_StatusType DSPSS_FirmwareVersionGet(uint16 * const FirmwareVersion,
                                          const uint32 Length);


/**
 * Configure the DSPSS thread
 * @param Id Thread id
 * @param Thread Thread configuration information
 * @param SchedMode Scheduling mode
 * @return Return error code
 */
DSPSS_StatusType DSPSS_ThreadConfigure(const DSPSS_ThreadIdType Id,
                                       const DSPSS_ThreadConfigType * const Config);


/**
 * Initialize the threads
 * @return Return error code
 */
DSPSS_StatusType DSPSS_ThreadsInitialize(void);


/**
 * Start running threads on DSPSSS
 * @return Return error code
 */
DSPSS_StatusType DSPSS_Start(void);


/**
 * Stop running threads on DSPSS
 * @return Return error code
 */
DSPSS_StatusType DSPSS_Stop(void);


/**
 * Set calibration parameters
 * @param Id Thread id
 * @param Calibration Calibration information
 * @return Return error code
 */
DSPSS_StatusType DSPSS_ThreadsCalibrationSet(const DSPSS_ThreadIdType Id,
                                             const DSPSS_CFSDADC_CalibParamsType CalibrationParams);


/**
 * Get thread running status
 * @param[in] Id Thread id
 * @return thread running status
 */
DSPSS_CFSDADC_ThreadStatusType DSPSS_ThreadsStatusGet(const DSPSS_ThreadIdType Id);


/**
 * Read from DSP-Core buffer
 * @param[in] Id Thread id
 * @param[in] Length The length of data array
 * @param[in] Value Pointer to the values read from DSP-Core buffer
 * @return The actual number of values read from the buffer
 */
uint32 DSPSS_CoreBufferRead(const DSPSS_ThreadIdType Id,
                            const uint32 Length,
                            sint16 * const Data);


/**
 * Flush output buffer to discard all the previous processed data.
 * @param[in] Id Thread id
 * @param[in] TransferMethod The transfer type on output buffer (DMA or Core buffer)
 * @return void
 */
void DSPSS_FlushOutputBuffer(const DSPSS_ThreadIdType Id,
                             const DSPSS_TransferMethodType TransferMethod);


/*==================================================================================================
*                                       DSPSS threads
==================================================================================================*/

/**
 * Start reset routine
 */
void DSPSS_DspStartResetRoutine(void);


/**
 * Assert reset
 */
void DSPSS_DspAssertReset(void);



/**
 * Program the scheduling sequence. Change of scheduling modes is possible only after the DSPSS reset.
 * @param SchedMode Scheduling mode
 */
void DSPSS_ThreadSchedulingConfigure(DSPSS_SchedulingModeType SchedMode);


/**
 * Program the scheduling to Sample Threshold mode. Change of scheduling modes is possible only after the DSPSS reset.
 * @param ContrlMode Controlling mode of thread scheduling.
 */
void DSPSS_ThreadSchedulingSampleThresholdMode(const DSPSS_NextReqHaltAckWaitModeType ContrlMode);


/**
 * Program the scheduling to Clock Threshold mode. Change of scheduling modes is possible only after the DSPSS reset.
 * @param ContrlMode Controlling mode of thread scheduling.
 * @param SchdSeq1 First thread that will be scheduled in clock threshold mode.
 * @param SchdSeq2 Second thread that will be scheduled in clock threshold mode.
 * @param SchdSeq3 Third thread that will be scheduled in clock threshold mode.
 * @param SchdSeq4 Fourth thread that will be scheduled in clock threshold mode.
 */
void DSPSS_ThreadSchedulingClockThresholdMode(const DSPSS_NextReqHaltAckWaitModeType ContrlMode,
                                              const DSPSS_ThreadIdType SchdSeq1,
                                              const DSPSS_ThreadIdType SchdSeq2,
                                              const DSPSS_ThreadIdType SchdSeq3,
                                              const DSPSS_ThreadIdType SchdSeq4);

/**
 * Program the PC_INIT values for every thread in Hardware scheduler of DSP sub-system.
 * The PCINIT value for each of the thread should be in multiples of 8 PMEM locations.
 * @param Id Thread id
 * @param PCInit PC initial value for the threads of DSP-0
 */
void DSPSS_ThreadPCInitSet(const DSPSS_ThreadIdType Id,
                           const uint16 PCInit);


/**
 * Program the start and end address memory location for respective threads in memory.
 * Specifies the start and end addresses of the SDADC input buffer to write the SDADC data in the XMEM.
 * @param Id Thread id that will be configured.
 * @param StartAddress Start address for the thread in data memory.
 * @param EndAddress End address (byte address aligned) location for the thread in data memory.
 */
void DSPSS_ThreadInputBufferConfigure(const DSPSS_ThreadIdType Id,
                                      const uint16 StartAddress,
                                      const uint16 EndAddress);


/**
 * Set thread threshold
 * @param Id Thread id that will be configured.
 * @param Threshold The number of ADC samples in sample mode, after which the corresponding DSP thread is scheduled for operation or
 *                  number of clock cycles for which a thread stays in operation in Clock-Cycle mode after which a new thread is scheduled.
 */
void DSPSS_ThreadThresholdSet(const DSPSS_ThreadIdType Id,
                              const uint16 Threshold);


/**
 * Enable the thread.
 * @param Id Thread id.
 */
void DSPSS_ThreadEnable(const DSPSS_ThreadIdType Id);


/**
 * Suspend the thread.
 * @param Id Thread id.
 */
void DSPSS_ThreadSuspend(const DSPSS_ThreadIdType Id);


/**
 * Get the start address of output buffer.
 * @param Id Identifier of the thread.
 * @return Current start address of output buffer space inside XMEM.
 */
uint32 DSPSS_ThreadGetOutputBufferStart(const DSPSS_ThreadIdType Id);


/**
 * Get the length in byte of output buffer.
 * @param Id Identifier of the thread.
 * @return length of the output buffer for the specific thread.
 */
uint32 DSPSS_ThreadGetOutputBufferLength(const DSPSS_ThreadIdType Id);


/*==================================================================================================
*                                       DSPSS_dsp_core_buffer
==================================================================================================*/

/**
 * Configure the buffer address in XMEM by programming the start and end address
 * and the read and write owners
 * @param Id Identifier of the thread.
 * @param StartAddr Start address of the DSP_CORE circular buffer.
 * @param EndAddr End address of the DSP_CORE circular buffer.
 * @param Owner Read and write owners of the buffers.
 */
void DSPSS_DspCoreBufferConfigure(const DSPSS_ThreadIdType Id,
                                  const uint16 StartAddr,
                                  const uint16 EndAddr,
                                  const DSPSS_DspCoreBufferOwnerType Owner);


/**
 * Enable the DSP-Core buffer.
 * @param Id Identifier of the thread.
 */
void DSPSS_DspCoreBufferEnable(const DSPSS_ThreadIdType Id);


/**
 * Disable the DSP-Core buffer.
 * @param Id Identifier of the thread.
 */
void DSPSS_DspCoreBufferDisable(const DSPSS_ThreadIdType Id);


/**
 * Get the current read pointer
 * @param Id Identifier of the thread.
 * @return Current read pointer value of DSP_CORE buffer space inside XMEM.
 */
uint16 DSPSS_DspCoreBufferCurrReadPtrGet(const DSPSS_ThreadIdType Id);


/**
 * Check overflow of write pointer inside DSP-CORE buffer
 * @param Id Identifier of the thread.
 * @return Overflow bit check.
 */
uint32 DSPSS_DspCoreBufferOverflowCheck(const DSPSS_ThreadIdType Id);


/**
 * Clear overrflow bit
 * @param Id Identifier of the thread.
 */
void DSPSS_DspCoreBufferOverflowClear(const DSPSS_ThreadIdType Id);


/*==================================================================================================
*                                       DSPSS_interrupts
==================================================================================================*/

/**
 * Enable an interrupt
 * @param Id Thread or dma id
 * @param InterruptMask Type of the interrupt
 */
void DSPSS_InterruptEnable(const uint32 Id,
                           const DSPSS_InterruptTypeType InterruptMask);


/**
 * Disable an interrupt
 * @param Id Thread or dma id
 * @param InterruptMask Type of the interrupt
 */
void DSPSS_InterruptDisable(const uint32 Id,
                            const DSPSS_InterruptTypeType InterruptMask);


/*==================================================================================================
*                                       DSPSS_dma
==================================================================================================*/

/**
 * Configure the dma read buffer
 * @param DmaChannel Dma channel id
 * @param StartAddr Start address of the DMA_READ circular buffer.
 * @param EndAddr End address of the DMA_READ circular buffer.
 */
void DSPSS_DmaReadBufferConfigure(const DSPSS_CFSDADC_DmaChannelType DmaChannel,
                                  const uint16 StartAddr,
                                  const uint16 EndAddr);


/**
 * Enable the dma read buffer
 * @param DmaChannel Dma channel id
 */
void DSPSS_DmaReadBufferEnable(const DSPSS_CFSDADC_DmaChannelType DmaChannel);


/**
 * Disable the dma read buffer
 * @param DmaChannel Dma channel id
 */
void DSPSS_DmaReadBufferDisable(const DSPSS_CFSDADC_DmaChannelType DmaChannel);


/**
 * Check wrap status of the read pointer
 * @param DmaChannel Identifier of the DMA channel.
 * @return DMA-READ buffer wrap status check.
 */
boolean DSPSS_DmaReadBufferWrapPtrCheck(const DSPSS_CFSDADC_DmaChannelType DmaChannel);


#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"


#endif /* (SDADC_IP_DSPSS_ENABLED == STD_ON) */


#ifdef __cplusplus
}
#endif


#endif  /* DSPSS_API_H */
