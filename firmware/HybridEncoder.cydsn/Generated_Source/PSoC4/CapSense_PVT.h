/*******************************************************************************
* File Name: CapSense_PVT.h
* Version 2.60
*
* Description:
*  This file provides constants and structure declarations for the
*  CapSense CSD component.
*
* Note:
*
********************************************************************************
* Copyright 2014-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#if !defined(CY_CAPSENSE_CSD_PVT_CapSense_H)
#define CY_CAPSENSE_CSD_PVT_CapSense_H

#include "CapSense.h"

#if(0u != CapSense_CSHL_API_GENERATE)
    #include "CapSense_CSHL.h"
#endif /* (0u != CapSense_CSHL_API_GENERATE) */

#if(CapSense_TOTAL_TRACKPAD_GESTURES_COUNT > 0u)
    #include "CapSense_GESTURE.h"
#endif /* (CapSense_TOTAL_TRACKPAD_GESTURES_COUNT > 0u) */

typedef struct
{
    #if (CapSense_IS_COMPLEX_SCANSLOTS)
    uint8 sensor;
    #endif  /* CapSense_IS_COMPLEX_SCANSLOTS */
    uint8 pinNumber;
    uint8 portNumber;
    uint8 idacValue;
    uint16 senseClkDiv;
    uint16 sampleClkDiv;
    uint8 avgSamplesNum;
    uint16 calibrationCount;
    uint32 scanResolution;
}CapSense_CP_MEASURE_CONFIG;

typedef struct
{
    uint8 *idac1LevelsTbl;
    uint8 *idac2LevelsTbl;
    uint8 *sensetivityTbl;
    uint8 *chargeDivTbl;
    uint8 *modDivTbl;
    const uint8 *widgetNubmersTbl;
    uint32 *resolutionsTbl;
    uint8 *noiseEnvelopeTbl;
    uint8 *runningDifferenceTbl;
    uint8 *signRegisterTbl;
    uint16 *sampleMinTbl;
    uint16 *sampleMaxTbl;
    uint16 *previousSampleTbl;
    uint8 *kValueTbl;
    uint8 *scanSpeedTbl;
    const uint8 *prescalerTable;
    uint8 const *rawDataIndex;
    uint8 const *numberOfSensors;
    uint16 (*ptrGetRaw)(uint32 sensor);
    void (*ptrPreScan)(uint32 sensor);
    uint16 (*ptrReadSensorRaw)(uint32 sensor);
    uint32 (*ptrGetBitValue)(const uint8 table[], uint32 position);
    void (*ptrSetBitValue)(uint8 table[], uint32 position, uint32 value);
}CapSense_CONFIG_TYPE_POINTERS_P4_v2_60;

typedef struct
{
    uint8 totalScanslotsNum;
    uint8 totalWidgetsNum;
    uint8 totalSensorsNum;
    uint16 sensetivitySeed;
    uint16 hfclkFreq_MHz;
    CapSense_CONFIG_TYPE_POINTERS_P4_v2_60 const * pointers;
}CapSense_CONFIG_TYPE_P4_v2_60;

#define CapSense_AVG_SAMPLES_NUM        (1u)


/***************************************
*        Function Prototypes
***************************************/
void CapSense_PreScan(uint32 sensor);
void CapSense_PostScan(uint32 sensor);

void CapSense_EnableSensor(uint32 sensor);
void CapSense_DisableSensor(uint32 sensor);

#if (CapSense_IS_COMPLEX_SCANSLOTS)
    void CapSense_EnableScanSlot(uint32 slot);
    void CapSense_DisableScanSlot(uint32 slot);
#else
    #define CapSense_EnableScanSlot(slot)   CapSense_EnableSensor(slot)
    #define CapSense_DisableScanSlot(slot)  CapSense_DisableSensor(slot)
#endif  /* End CapSense_IS_COMPLEX_SCANSLOTS */

void CapSense_EnableShieldElectrode(uint32 pinNumber, uint32 portNumber);

uint32 CapSense_GetBitValue(const uint8 table[], uint32 position);
void CapSense_SetBitValue(uint8 table[], uint32 position, uint32 value);

/* Find next sensor for One Channel design */
uint8 CapSense_FindNextSensor(uint8 snsIndex);

void CapSense_SetPinDriveMode(uint32 driveMode, uint32 pinNumber, uint32 portNumber);
void CapSense_CalibrateSensor(uint32 sensor, uint32 rawLevel, uint8 idacLevelsTbl[]);
uint16  CapSense_GetSensorRaw(uint32 sensor);

void CapSense_DisableBaselineIDAC(void);
void CapSense_EnableBaselineIDAC(const CapSense_CONFIG_TYPE_P4_v2_60 *config);

uint32 CapSense_GetLowCp(CapSense_CP_MEASURE_CONFIG *config);
uint32 CapSense_GetHighCp(const CapSense_CP_MEASURE_CONFIG *config);
uint32 CapSense_CalibrateIDAC(CapSense_CP_MEASURE_CONFIG *config);
uint16 CapSense_ScanSensorCp(const CapSense_CP_MEASURE_CONFIG *config);

void CapSense_ConnectElectrode(uint32 pinNumber, uint32 portNumber);
void CapSense_DisconnectElectrode(uint32 pinNumber, uint32 portNumber);

void TunePrescalers_P4_v2_60(void *config);
void TuneSensitivity_P4_v2_60(void *config);
void MeasureNoiseEnvelope_P4_v2_60(void *config, const uint8 sensorNumber, const uint16 *rawData);
void CalculateThresholds_P4_v2_60(void *config, const uint8 sensorNumber, const uint8 widget, uint8 *fingerThres, uint8 *noiseThres);
void CalibrateSensors_P4_v2_60(void *config, uint16 rawLevel);
void CalibrateOneDAC_P4_v2_60(void *config, uint16 rawLevel, uint32 curSensor, uint8 *idacLevelsTbl);


#endif /* CY_CAPSENSE_CSD_PVT_CapSense_H */
