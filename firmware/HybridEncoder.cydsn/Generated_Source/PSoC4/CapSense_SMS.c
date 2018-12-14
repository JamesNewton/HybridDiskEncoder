<<<<<<< HEAD
/*******************************************************************************
* File Name: CapSense_SMS.c
* Version 2.60
*
* Description:
*  This file provides the source code of wrapper between CapSense CSD component
*  and Auto Tuning library.
*
* Note:
*
********************************************************************************
* Copyright 2013-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CapSense_SMS.h"
#include "CapSense_PVT.h"

#include "cytypes.h"

#if (CapSense_TUNING_METHOD == CapSense__TUNING_AUTO)


/*  Real Charge Divider values */
#if ((0u != CapSense_IS_M0S8PERI_BLOCK) && (0u == CY_PSOC4_4000))
    /*  Dividers are not chained */
    #if (CYDEV_BCLK__HFCLK__MHZ > 24u)
        const uint8 CapSense_prescalerTable[CapSense_PRESCALERS_TBL_SIZE] = {
            4u,     4u,     4u,    8u,    8u,    8u,    8u,    16u,    16u,    16u,    16u,    16u,    16u,    16u,    16u,    16u
        };
    #elif (CYDEV_BCLK__HFCLK__MHZ >12u)
        const uint8 CapSense_prescalerTable[CapSense_PRESCALERS_TBL_SIZE] = {
            2u,     2u,     2u,    4u,    4u,    4u,    4u,    8u,    8u,    8u,    8u,    8u,    8u,    8u,    8u,    8u
        };
    #else   /* (CYDEV_BCLK__HFCLK__MHZ > 12u) */
        const uint8 CapSense_prescalerTable[CapSense_PRESCALERS_TBL_SIZE] = {
            1u,     1u,     1u,    2u,    2u,    2u,    2u,    4u,    4u,    4u,    4u,    4u,    4u,    4u,    4u,    4u
        };
    #endif /* (CYDEV_BCLK__HFCLK__MHZ > 24u) */

#elif (0u != CapSense_IS_M0S8PERI_BLOCK)
    /*  Dividers are not chained (PSoC 4000) */
    #if (CYDEV_BCLK__HFCLK__MHZ >= 12u)
        const uint8 CapSense_prescalerTable[CapSense_PRESCALERS_TBL_SIZE] = {
            1u,     1u,     1u,    2u,    2u,    2u,    2u,    4u,    4u,    4u,    4u,    4u,    4u,    4u,    4u,    4u
        };

    #elif (CYDEV_BCLK__HFCLK__MHZ >= 6u)
        const uint8 CapSense_prescalerTable[CapSense_PRESCALERS_TBL_SIZE] = {
            1u,     1u,     1u,    1u,    1u,    1u,    1u,    2u,    2u,    2u,    2u,    2u,    2u,    2u,    2u,    2u
        };
    #else
        const uint8 CapSense_prescalerTable[CapSense_PRESCALERS_TBL_SIZE] = {
            1u,     1u,     1u,    1u,    1u,    1u,    1u,    1u,    1u,    1u,    1u,    1u,    1u,    1u,    1u,    1u
        };
    #endif /* (CYDEV_BCLK__HFCLK__MHZ > 12u) */

#else
    /*  Dividers are chained (PSoC 4100, PSoC 4200) */
    #if (CYDEV_BCLK__HFCLK__MHZ > 24u)
        const uint8 CapSense_prescalerTable[CapSense_PRESCALERS_TBL_SIZE] = {
            2u,     2u,     2u,    4u,    4u,    4u,    4u,    8u,    8u,    8u,    8u,    8u,    8u,    8u,    8u,    8u
        };

    #elif (CYDEV_BCLK__HFCLK__MHZ >12u)
        const uint8 CapSense_prescalerTable[CapSense_PRESCALERS_TBL_SIZE] = {
            1u,     1u,     1u,    2u,    2u,    2u,    2u,    4u,    4u,    4u,    4u,    4u,    4u,    4u,    4u,    4u
        };
    #else   /* (CYDEV_BCLK__HFCLK__MHZ > 12u) */
        const uint8 CapSense_prescalerTable[CapSense_PRESCALERS_TBL_SIZE] = {
            1u,     1u,     1u,    1u,    1u,    1u,    1u,    2u,    2u,    2u,    2u,    2u,    2u,    2u,    2u,    2u
        };
    #endif /* (CYDEV_BCLK__HFCLK__MHZ > 24u) */
#endif /* ((0u != CapSense_IS_M0S8PERI_BLOCK) && (0u == CY_PSOC4_4000)) */


uint8 CapSense_noiseEnvelopeTbl[CapSense_TOTAL_SENSOR_COUNT];
uint8 CapSense_runningDifferenceTbl[CapSense_TOTAL_SENSOR_COUNT];
uint8 CapSense_signRegisterTbl[CapSense_TOTAL_SENSOR_COUNT];
uint16 CapSense_sampleMinTbl[CapSense_TOTAL_SENSOR_COUNT];
uint16 CapSense_sampleMaxTbl[CapSense_TOTAL_SENSOR_COUNT];
uint16 CapSense_previousSampleTbl[CapSense_TOTAL_SENSOR_COUNT];
uint8 CapSense_kValueTbl[CapSense_TOTAL_SENSOR_COUNT];

uint8 CapSense_sensorSensitivity[] = {
    2u, 2u, 
};

CapSense_CONFIG_TYPE_P4_v2_60 CapSense_config;
CapSense_CONFIG_TYPE_POINTERS_P4_v2_60 const CapSense_configPointers = {
    CapSense_modulationIDAC,
    CapSense_compensationIDAC,
    CapSense_sensorSensitivity,
    CapSense_senseClkDividerVal,
    CapSense_sampleClkDividerVal,
    CapSense_widgetNumber,
    CapSense_widgetResolution,
    CapSense_noiseEnvelopeTbl,
    CapSense_runningDifferenceTbl,
    CapSense_signRegisterTbl,
    CapSense_sampleMinTbl,
    CapSense_sampleMaxTbl,
    CapSense_previousSampleTbl,
    CapSense_kValueTbl,
    CapSense_scanSpeedTbl,
    CapSense_prescalerTable,
    (const uint8  *)CapSense_rawDataIndex,
    (const uint8  *)CapSense_numberOfSensors,
    &CapSense_GetSensorRaw,
    &CapSense_PreScan,
    &CapSense_ReadSensorRaw,
    &CapSense_GetBitValue,
    &CapSense_SetBitValue
};


/*******************************************************************************
* Function Name: CapSense_AutoTune
********************************************************************************
*
* Summary:
*  Provides the tuning procedure for all sensors.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*   CapSense_config: the structure which contains configuration parameters
*   CapSense_senseClkDividerVal[]: used to store the Analog Switch
*   dividers for each sensor.
*   CapSense_senseClkDividerVal[]: used to store the
*    Analog Switch divider for all sensors.
*   CapSense_prescalersTuningDone - used to notify the Tuner GUI that
*   the pre-scalers tuning  is done.
*
* Side Effects:
*  None
*
*******************************************************************************/
void CapSense_AutoTune(void)
{
    uint32 curSensor;
    uint32 widget;

    CapSense_config.totalScanslotsNum = CapSense_TOTAL_SCANSLOT_COUNT;
    CapSense_config.totalWidgetsNum = CapSense_END_OF_WIDGETS_INDEX;
    CapSense_config.totalSensorsNum = CapSense_TOTAL_SENSOR_COUNT;

    CapSense_config.hfclkFreq_MHz = CYDEV_BCLK__HFCLK__MHZ;
    CapSense_config.sensetivitySeed = CapSense_SENSETIVITY_FACTOR;

    CapSense_config.pointers = &CapSense_configPointers;

    CapSense_SetAnalogSwitchesSrcDirect();

    for(widget = 0u; widget < CapSense_config.totalWidgetsNum; widget++)
    {
        CapSense_widgetResolution[widget] = CapSense_CALIBRATION_RESOLUTION;
    }


    for(curSensor = 0u; curSensor < CapSense_TOTAL_SCANSLOT_COUNT; curSensor++)
    {
        CapSense_senseClkDividerVal[curSensor] = CapSense_CALIBRATION_ASD;
        CapSense_sampleClkDividerVal[curSensor] = CapSense_CALIBRATION_MD;
    }

    CapSense_DisableBaselineIDAC();

    CalibrateSensors_P4_v2_60(&CapSense_config, CapSense_CAL_RAW_COUNT);

    #if(0u != CapSense_TOTAL_CENTROIDS_COUNT)
        CapSense_NormalizeWidgets(CapSense_END_OF_WIDGETS_INDEX, CapSense_modulationIDAC);
    #endif /* (0u != CapSense_TOTAL_CENTROIDS_COUNT)  */

    TunePrescalers_P4_v2_60(&CapSense_config);

    #if(CapSense_PRS_OPTIONS != CapSense__PRS_NONE)
        CapSense_prescalersTuningDone = 1u;
    #endif /* (CapSense_PRS_OPTIONS == CapSense__PRS_NONE) */

    CalibrateSensors_P4_v2_60(&CapSense_config, CapSense_CAL_RAW_COUNT);
    #if(0u != CapSense_TOTAL_CENTROIDS_COUNT)
        CapSense_NormalizeWidgets(CapSense_END_OF_WIDGETS_INDEX, CapSense_modulationIDAC);
    #endif /* (0u != CapSense_TOTAL_CENTROIDS_COUNT)  */
    TuneSensitivity_P4_v2_60(&CapSense_config);

    CapSense_EnableBaselineIDAC(&CapSense_config);

    for(curSensor = 0u; curSensor < CapSense_TOTAL_SCANSLOT_COUNT; curSensor++)
    {
        CapSense_UpdateThresholds(curSensor);
    }
}


/*******************************************************************************
* Function Name: CapSense_UpdateThresholds
********************************************************************************
*
* Summary:
*  The API updates the Finger Threshold, Hysteresis, Noise Threshold, and
*  Negative Noise Threshold in the AutoTuning (Smartsense) Mode.
*
* Parameters:
*  sensor: sensor number.
*
* Return:
*  None
*
* Global Variables:
*  CapSense_widgetNumber[] - contains widget Number for given sensor.
*  0 through 7 (sensor 0 is bit 0, sensor 1 is bit 1).
*  For other sensors the array element equals to 255.
*  CapSense_numberOfSensors[widget] - Number of sensors in the widget.
*   CapSense_fingerThreshold[] - contains the level of signal for each sensor
*   that determines if a finger present on the sensor.
*   CapSense_negativeNoiseThreshold[] - negative Noise Threshold
*   CapSense_hysteresis[] - the array with hysteresis values.
*
* Side Effects:
*  None
*
*******************************************************************************/
void CapSense_UpdateThresholds(uint32 sensor)
{
    uint8 fingerThreshold;
    uint32 widget;

    widget = CapSense_widgetNumber[sensor];

    #if(0u != CapSense_FLEXIBLE_THRESHOLDS_EN)
        fingerThreshold = CapSense_fingerThreshold[widget];
        /* Update Threshold manually (flexible) */
        CapSense_noiseThreshold[widget] = (uint8)(fingerThreshold >> 1u);
        CapSense_negativeNoiseThreshold[widget] = (uint8)(fingerThreshold >> 1u);
        CapSense_hysteresis[widget] = (uint8)(fingerThreshold >> 3u);
    #else
        /* Calculate Finger Threshold and Noise Threshold with Smartsense (automatic) */
        CalculateThresholds_P4_v2_60(&CapSense_config, (uint8)sensor, (uint8)widget, CapSense_fingerThreshold, CapSense_noiseThreshold);

        fingerThreshold = CapSense_fingerThreshold[widget];

        /* Update Threshold based on calculated with Smartsense (automatic) */
        CapSense_negativeNoiseThreshold[widget] = CapSense_noiseThreshold[widget];

        if(fingerThreshold < CapSense_THRESHOLD_1)
        {
            CapSense_hysteresis[widget] = (uint8)(fingerThreshold >> 3u);
        }
        else if(fingerThreshold <  CapSense_THRESHOLD_2)
        {
            CapSense_hysteresis[widget] = (uint8)(fingerThreshold >> 4u);
        }
        else if(fingerThreshold <  CapSense_THRESHOLD_3)
        {
            CapSense_hysteresis[widget] = (uint8)(fingerThreshold >> 5u);
        }
        else if(fingerThreshold <  CapSense_THRESHOLD_4)
        {
            CapSense_hysteresis[widget] = (uint8)(fingerThreshold >> 6u);
        }
        else
        {
            CapSense_hysteresis[widget] = 0u;
        }
    #endif /* (0u != CapSense_FLEXIBLE_THRESHOLDS_EN)  */
}

/*******************************************************************************
* Function Name: CapSense_SetAnalogSwitchesSrcDirect
********************************************************************************
*
* Summary:
*  This API switches the charge clock source to prescaler.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  None
*
* Side Effects:
*  None
*
*******************************************************************************/
void CapSense_SetAnalogSwitchesSrcDirect(void)
{
    CapSense_CSD_CFG_REG &= ~(CapSense_CSD_CFG_PRS_SELECT);
}


/*******************************************************************************
* Function Name: CapSense_DisableBaselineIDAC
********************************************************************************
*
* Summary:
*  The API disables the Compensation IDAC.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  None
*
* Side Effects:
*  None
*
*******************************************************************************/
void CapSense_DisableBaselineIDAC(void)
{
    uint32 newRegValue;

    newRegValue = CapSense_CSD_IDAC_REG;

    newRegValue &= ~(CapSense_CSD_IDAC1_MODE_MASK | CapSense_CSD_IDAC2_MODE_MASK);
    newRegValue |= CapSense_CSD_IDAC1_MODE_VARIABLE;

    CapSense_CSD_IDAC_REG = newRegValue;
}


/*******************************************************************************
* Function Name: CapSense_EnableBaselineIDAC
********************************************************************************
*
* Summary:
*  The API enables the Compensation IDAC.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  CapSense_compensationIDAC[] - used to store a 7-bit idac value for all the sensors.
*
* Side Effects:
*  None
*
*******************************************************************************/
void  CapSense_EnableBaselineIDAC(const CapSense_CONFIG_TYPE_P4_v2_60 *config)
{
    uint32 curSensor;
    uint32 newRegValue;

    for(curSensor = 0u; curSensor < config->totalScanslotsNum; curSensor++)
    {
        CapSense_compensationIDAC[curSensor] = CapSense_modulationIDAC[curSensor] / 2u;
        CapSense_modulationIDAC[curSensor] = (CapSense_modulationIDAC[curSensor] + 1u) / 2u;
    }

    CyIntDisable(CapSense_ISR_NUMBER);

    newRegValue = CapSense_CSD_IDAC_REG;
    newRegValue &= ~(CapSense_CSD_IDAC1_MODE_MASK | CapSense_CSD_IDAC2_MODE_MASK);
    newRegValue |= (CapSense_CSD_IDAC1_MODE_VARIABLE | CapSense_CSD_IDAC2_MODE_FIXED);
    CapSense_CSD_IDAC_REG = newRegValue;

    CyIntEnable(CapSense_ISR_NUMBER);
}


/*******************************************************************************
* Function Name: CapSense_SetSensitivity
********************************************************************************
*
* Summary:
*  This API sets the sensitivity value for the sensor. The sensitivity
*  value is used during the auto-tuning algorithm executed as part of the CapSense_Start API.
*  This API is called by the application layer prior to calling the CapSense_Start API.
*  Calling this API after execution of CapSense_Start API has no effect.
*
* Parameters:
*  sensor  Sensor index
*  data    Sensitivity of the sensor. Possible values are below
*  1 - 0.1pf sensitivity
*  2 - 0.2pf sensitivity
*  3 - 0.3pf sensitivity
*  4 - 0.4pf sensitivity
*  5 - 0.5pf sensitivity
*  6 - 0.6pf sensitivity
*  7 - 0.7pf sensitivity
*  8 - 0.8pf sensitivity
*  9 - 0.9pf sensitivity
*  10 - 1.0pf sensitivity
*  All other values, set sensitivity to 1.0pf
*
*  Return Value:
*   None
*
* Global Variables:
* CapSense_sensorSensitivity[] - This 8-bits array contains Sensitivity in the LSB nibble
*                                and Noise Reset Counter value in the MSB nibble.
*
* Side Effects:
*  None
*
*******************************************************************************/
void CapSense_SetSensitivity(uint32 sensor, uint32 value)
{
    if(value > 10u)
    {
        value = 10u;
    }

    /* Clear SensorSensitivity value in LSB nibble */
    CapSense_sensorSensitivity[sensor] &= (uint8)~CapSense_SENSITIVITY_MASK;
    /* Set SensorSensitivity value in LSB nibble */
    CapSense_sensorSensitivity[sensor] |= (uint8)value;
}


/*******************************************************************************
* Function Name: CapSense_GetSensitivityCoefficient
********************************************************************************
*
* Summary:
*  This API returns the K coefficient for the appropriate sensor.
*
* Parameters:
*  sensor:  Sensor index
*
*  Return Value:
*   K - value for the appropriate sensor.
*
* Global Variables:
*  CapSense_kValueTbl[] - This 8-bits array contains the K value for each sensor.
*
* Side Effects:
*  None
*
*******************************************************************************/
uint8 CapSense_GetSensitivityCoefficient(uint32 sensor)
{
    return (CapSense_kValueTbl[sensor]);
}


/*******************************************************************************
* Function Name: CapSense_GetNoiseEnvelope
********************************************************************************
*
* Summary:
*  This function returns the noise value of a
*  component.
*
* Parameters:
*  sensor - Sensor number.
*
* Return:
*  The noise envelope value of the sensor
*  indicated by argument.
*
* Global Variables:
*  CapSense_noiseEnvelopeTbl[] - array with Noise Envelope.
*
* Side Effects:
*  None
*
*******************************************************************************/
uint16 CapSense_GetNoiseEnvelope(uint32 sensor)
{
    return((uint16)((uint16)CapSense_noiseEnvelopeTbl[sensor] << 1u) + 1u);
}


/*******************************************************************************
* Function Name: CapSense_GetNormalizedDiffCountData
********************************************************************************
*
* Summary:
*  This API returns normalized difference count data.
*
* Parameters:
*  sensor:  Sensor number.
*
* Return:
*  This API returns a normalized count value of the sensor indicated by the
*  argument.
*
* Global Variables:
*  CapSense_sensorSignal[] - array with difference counts for sensors
*
* Side Effects:
*  None
*
*******************************************************************************/
uint16 CapSense_GetNormalizedDiffCountData(uint32 sensor)
{
    return (uint16)(((uint32)CapSense_sensorSignal[sensor] << 7u) / CapSense_kValueTbl[sensor]);
}

#endif /* (CapSense_TUNING_METHOD == CapSense__TUNING_AUTO) */

/* [] END OF FILE */
=======
/*******************************************************************************
* File Name: CapSense_SMS.c
* Version 2.60
*
* Description:
*  This file provides the source code of wrapper between CapSense CSD component
*  and Auto Tuning library.
*
* Note:
*
********************************************************************************
* Copyright 2013-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CapSense_SMS.h"
#include "CapSense_PVT.h"

#include "cytypes.h"

#if (CapSense_TUNING_METHOD == CapSense__TUNING_AUTO)


/*  Real Charge Divider values */
#if ((0u != CapSense_IS_M0S8PERI_BLOCK) && (0u == CY_PSOC4_4000))
    /*  Dividers are not chained */
    #if (CYDEV_BCLK__HFCLK__MHZ > 24u)
        const uint8 CapSense_prescalerTable[CapSense_PRESCALERS_TBL_SIZE] = {
            4u,     4u,     4u,    8u,    8u,    8u,    8u,    16u,    16u,    16u,    16u,    16u,    16u,    16u,    16u,    16u
        };
    #elif (CYDEV_BCLK__HFCLK__MHZ >12u)
        const uint8 CapSense_prescalerTable[CapSense_PRESCALERS_TBL_SIZE] = {
            2u,     2u,     2u,    4u,    4u,    4u,    4u,    8u,    8u,    8u,    8u,    8u,    8u,    8u,    8u,    8u
        };
    #else   /* (CYDEV_BCLK__HFCLK__MHZ > 12u) */
        const uint8 CapSense_prescalerTable[CapSense_PRESCALERS_TBL_SIZE] = {
            1u,     1u,     1u,    2u,    2u,    2u,    2u,    4u,    4u,    4u,    4u,    4u,    4u,    4u,    4u,    4u
        };
    #endif /* (CYDEV_BCLK__HFCLK__MHZ > 24u) */

#elif (0u != CapSense_IS_M0S8PERI_BLOCK)
    /*  Dividers are not chained (PSoC 4000) */
    #if (CYDEV_BCLK__HFCLK__MHZ >= 12u)
        const uint8 CapSense_prescalerTable[CapSense_PRESCALERS_TBL_SIZE] = {
            1u,     1u,     1u,    2u,    2u,    2u,    2u,    4u,    4u,    4u,    4u,    4u,    4u,    4u,    4u,    4u
        };

    #elif (CYDEV_BCLK__HFCLK__MHZ >= 6u)
        const uint8 CapSense_prescalerTable[CapSense_PRESCALERS_TBL_SIZE] = {
            1u,     1u,     1u,    1u,    1u,    1u,    1u,    2u,    2u,    2u,    2u,    2u,    2u,    2u,    2u,    2u
        };
    #else
        const uint8 CapSense_prescalerTable[CapSense_PRESCALERS_TBL_SIZE] = {
            1u,     1u,     1u,    1u,    1u,    1u,    1u,    1u,    1u,    1u,    1u,    1u,    1u,    1u,    1u,    1u
        };
    #endif /* (CYDEV_BCLK__HFCLK__MHZ > 12u) */

#else
    /*  Dividers are chained (PSoC 4100, PSoC 4200) */
    #if (CYDEV_BCLK__HFCLK__MHZ > 24u)
        const uint8 CapSense_prescalerTable[CapSense_PRESCALERS_TBL_SIZE] = {
            2u,     2u,     2u,    4u,    4u,    4u,    4u,    8u,    8u,    8u,    8u,    8u,    8u,    8u,    8u,    8u
        };

    #elif (CYDEV_BCLK__HFCLK__MHZ >12u)
        const uint8 CapSense_prescalerTable[CapSense_PRESCALERS_TBL_SIZE] = {
            1u,     1u,     1u,    2u,    2u,    2u,    2u,    4u,    4u,    4u,    4u,    4u,    4u,    4u,    4u,    4u
        };
    #else   /* (CYDEV_BCLK__HFCLK__MHZ > 12u) */
        const uint8 CapSense_prescalerTable[CapSense_PRESCALERS_TBL_SIZE] = {
            1u,     1u,     1u,    1u,    1u,    1u,    1u,    2u,    2u,    2u,    2u,    2u,    2u,    2u,    2u,    2u
        };
    #endif /* (CYDEV_BCLK__HFCLK__MHZ > 24u) */
#endif /* ((0u != CapSense_IS_M0S8PERI_BLOCK) && (0u == CY_PSOC4_4000)) */


uint8 CapSense_noiseEnvelopeTbl[CapSense_TOTAL_SENSOR_COUNT];
uint8 CapSense_runningDifferenceTbl[CapSense_TOTAL_SENSOR_COUNT];
uint8 CapSense_signRegisterTbl[CapSense_TOTAL_SENSOR_COUNT];
uint16 CapSense_sampleMinTbl[CapSense_TOTAL_SENSOR_COUNT];
uint16 CapSense_sampleMaxTbl[CapSense_TOTAL_SENSOR_COUNT];
uint16 CapSense_previousSampleTbl[CapSense_TOTAL_SENSOR_COUNT];
uint8 CapSense_kValueTbl[CapSense_TOTAL_SENSOR_COUNT];

uint8 CapSense_sensorSensitivity[] = {
    2u, 2u, 
};

CapSense_CONFIG_TYPE_P4_v2_60 CapSense_config;
CapSense_CONFIG_TYPE_POINTERS_P4_v2_60 const CapSense_configPointers = {
    CapSense_modulationIDAC,
    CapSense_compensationIDAC,
    CapSense_sensorSensitivity,
    CapSense_senseClkDividerVal,
    CapSense_sampleClkDividerVal,
    CapSense_widgetNumber,
    CapSense_widgetResolution,
    CapSense_noiseEnvelopeTbl,
    CapSense_runningDifferenceTbl,
    CapSense_signRegisterTbl,
    CapSense_sampleMinTbl,
    CapSense_sampleMaxTbl,
    CapSense_previousSampleTbl,
    CapSense_kValueTbl,
    CapSense_scanSpeedTbl,
    CapSense_prescalerTable,
    (const uint8  *)CapSense_rawDataIndex,
    (const uint8  *)CapSense_numberOfSensors,
    &CapSense_GetSensorRaw,
    &CapSense_PreScan,
    &CapSense_ReadSensorRaw,
    &CapSense_GetBitValue,
    &CapSense_SetBitValue
};


/*******************************************************************************
* Function Name: CapSense_AutoTune
********************************************************************************
*
* Summary:
*  Provides the tuning procedure for all sensors.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*   CapSense_config: the structure which contains configuration parameters
*   CapSense_senseClkDividerVal[]: used to store the Analog Switch
*   dividers for each sensor.
*   CapSense_senseClkDividerVal[]: used to store the
*    Analog Switch divider for all sensors.
*   CapSense_prescalersTuningDone - used to notify the Tuner GUI that
*   the pre-scalers tuning  is done.
*
* Side Effects:
*  None
*
*******************************************************************************/
void CapSense_AutoTune(void)
{
    uint32 curSensor;
    uint32 widget;

    CapSense_config.totalScanslotsNum = CapSense_TOTAL_SCANSLOT_COUNT;
    CapSense_config.totalWidgetsNum = CapSense_END_OF_WIDGETS_INDEX;
    CapSense_config.totalSensorsNum = CapSense_TOTAL_SENSOR_COUNT;

    CapSense_config.hfclkFreq_MHz = CYDEV_BCLK__HFCLK__MHZ;
    CapSense_config.sensetivitySeed = CapSense_SENSETIVITY_FACTOR;

    CapSense_config.pointers = &CapSense_configPointers;

    CapSense_SetAnalogSwitchesSrcDirect();

    for(widget = 0u; widget < CapSense_config.totalWidgetsNum; widget++)
    {
        CapSense_widgetResolution[widget] = CapSense_CALIBRATION_RESOLUTION;
    }


    for(curSensor = 0u; curSensor < CapSense_TOTAL_SCANSLOT_COUNT; curSensor++)
    {
        CapSense_senseClkDividerVal[curSensor] = CapSense_CALIBRATION_ASD;
        CapSense_sampleClkDividerVal[curSensor] = CapSense_CALIBRATION_MD;
    }

    CapSense_DisableBaselineIDAC();

    CalibrateSensors_P4_v2_60(&CapSense_config, CapSense_CAL_RAW_COUNT);

    #if(0u != CapSense_TOTAL_CENTROIDS_COUNT)
        CapSense_NormalizeWidgets(CapSense_END_OF_WIDGETS_INDEX, CapSense_modulationIDAC);
    #endif /* (0u != CapSense_TOTAL_CENTROIDS_COUNT)  */

    TunePrescalers_P4_v2_60(&CapSense_config);

    #if(CapSense_PRS_OPTIONS != CapSense__PRS_NONE)
        CapSense_prescalersTuningDone = 1u;
    #endif /* (CapSense_PRS_OPTIONS == CapSense__PRS_NONE) */

    CalibrateSensors_P4_v2_60(&CapSense_config, CapSense_CAL_RAW_COUNT);
    #if(0u != CapSense_TOTAL_CENTROIDS_COUNT)
        CapSense_NormalizeWidgets(CapSense_END_OF_WIDGETS_INDEX, CapSense_modulationIDAC);
    #endif /* (0u != CapSense_TOTAL_CENTROIDS_COUNT)  */
    TuneSensitivity_P4_v2_60(&CapSense_config);

    CapSense_EnableBaselineIDAC(&CapSense_config);

    for(curSensor = 0u; curSensor < CapSense_TOTAL_SCANSLOT_COUNT; curSensor++)
    {
        CapSense_UpdateThresholds(curSensor);
    }
}


/*******************************************************************************
* Function Name: CapSense_UpdateThresholds
********************************************************************************
*
* Summary:
*  The API updates the Finger Threshold, Hysteresis, Noise Threshold, and
*  Negative Noise Threshold in the AutoTuning (Smartsense) Mode.
*
* Parameters:
*  sensor: sensor number.
*
* Return:
*  None
*
* Global Variables:
*  CapSense_widgetNumber[] - contains widget Number for given sensor.
*  0 through 7 (sensor 0 is bit 0, sensor 1 is bit 1).
*  For other sensors the array element equals to 255.
*  CapSense_numberOfSensors[widget] - Number of sensors in the widget.
*   CapSense_fingerThreshold[] - contains the level of signal for each sensor
*   that determines if a finger present on the sensor.
*   CapSense_negativeNoiseThreshold[] - negative Noise Threshold
*   CapSense_hysteresis[] - the array with hysteresis values.
*
* Side Effects:
*  None
*
*******************************************************************************/
void CapSense_UpdateThresholds(uint32 sensor)
{
    uint8 fingerThreshold;
    uint32 widget;

    widget = CapSense_widgetNumber[sensor];

    #if(0u != CapSense_FLEXIBLE_THRESHOLDS_EN)
        fingerThreshold = CapSense_fingerThreshold[widget];
        /* Update Threshold manually (flexible) */
        CapSense_noiseThreshold[widget] = (uint8)(fingerThreshold >> 1u);
        CapSense_negativeNoiseThreshold[widget] = (uint8)(fingerThreshold >> 1u);
        CapSense_hysteresis[widget] = (uint8)(fingerThreshold >> 3u);
    #else
        /* Calculate Finger Threshold and Noise Threshold with Smartsense (automatic) */
        CalculateThresholds_P4_v2_60(&CapSense_config, (uint8)sensor, (uint8)widget, CapSense_fingerThreshold, CapSense_noiseThreshold);

        fingerThreshold = CapSense_fingerThreshold[widget];

        /* Update Threshold based on calculated with Smartsense (automatic) */
        CapSense_negativeNoiseThreshold[widget] = CapSense_noiseThreshold[widget];

        if(fingerThreshold < CapSense_THRESHOLD_1)
        {
            CapSense_hysteresis[widget] = (uint8)(fingerThreshold >> 3u);
        }
        else if(fingerThreshold <  CapSense_THRESHOLD_2)
        {
            CapSense_hysteresis[widget] = (uint8)(fingerThreshold >> 4u);
        }
        else if(fingerThreshold <  CapSense_THRESHOLD_3)
        {
            CapSense_hysteresis[widget] = (uint8)(fingerThreshold >> 5u);
        }
        else if(fingerThreshold <  CapSense_THRESHOLD_4)
        {
            CapSense_hysteresis[widget] = (uint8)(fingerThreshold >> 6u);
        }
        else
        {
            CapSense_hysteresis[widget] = 0u;
        }
    #endif /* (0u != CapSense_FLEXIBLE_THRESHOLDS_EN)  */
}

/*******************************************************************************
* Function Name: CapSense_SetAnalogSwitchesSrcDirect
********************************************************************************
*
* Summary:
*  This API switches the charge clock source to prescaler.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  None
*
* Side Effects:
*  None
*
*******************************************************************************/
void CapSense_SetAnalogSwitchesSrcDirect(void)
{
    CapSense_CSD_CFG_REG &= ~(CapSense_CSD_CFG_PRS_SELECT);
}


/*******************************************************************************
* Function Name: CapSense_DisableBaselineIDAC
********************************************************************************
*
* Summary:
*  The API disables the Compensation IDAC.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  None
*
* Side Effects:
*  None
*
*******************************************************************************/
void CapSense_DisableBaselineIDAC(void)
{
    uint32 newRegValue;

    newRegValue = CapSense_CSD_IDAC_REG;

    newRegValue &= ~(CapSense_CSD_IDAC1_MODE_MASK | CapSense_CSD_IDAC2_MODE_MASK);
    newRegValue |= CapSense_CSD_IDAC1_MODE_VARIABLE;

    CapSense_CSD_IDAC_REG = newRegValue;
}


/*******************************************************************************
* Function Name: CapSense_EnableBaselineIDAC
********************************************************************************
*
* Summary:
*  The API enables the Compensation IDAC.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  CapSense_compensationIDAC[] - used to store a 7-bit idac value for all the sensors.
*
* Side Effects:
*  None
*
*******************************************************************************/
void  CapSense_EnableBaselineIDAC(const CapSense_CONFIG_TYPE_P4_v2_60 *config)
{
    uint32 curSensor;
    uint32 newRegValue;

    for(curSensor = 0u; curSensor < config->totalScanslotsNum; curSensor++)
    {
        CapSense_compensationIDAC[curSensor] = CapSense_modulationIDAC[curSensor] / 2u;
        CapSense_modulationIDAC[curSensor] = (CapSense_modulationIDAC[curSensor] + 1u) / 2u;
    }

    CyIntDisable(CapSense_ISR_NUMBER);

    newRegValue = CapSense_CSD_IDAC_REG;
    newRegValue &= ~(CapSense_CSD_IDAC1_MODE_MASK | CapSense_CSD_IDAC2_MODE_MASK);
    newRegValue |= (CapSense_CSD_IDAC1_MODE_VARIABLE | CapSense_CSD_IDAC2_MODE_FIXED);
    CapSense_CSD_IDAC_REG = newRegValue;

    CyIntEnable(CapSense_ISR_NUMBER);
}


/*******************************************************************************
* Function Name: CapSense_SetSensitivity
********************************************************************************
*
* Summary:
*  This API sets the sensitivity value for the sensor. The sensitivity
*  value is used during the auto-tuning algorithm executed as part of the CapSense_Start API.
*  This API is called by the application layer prior to calling the CapSense_Start API.
*  Calling this API after execution of CapSense_Start API has no effect.
*
* Parameters:
*  sensor  Sensor index
*  data    Sensitivity of the sensor. Possible values are below
*  1 - 0.1pf sensitivity
*  2 - 0.2pf sensitivity
*  3 - 0.3pf sensitivity
*  4 - 0.4pf sensitivity
*  5 - 0.5pf sensitivity
*  6 - 0.6pf sensitivity
*  7 - 0.7pf sensitivity
*  8 - 0.8pf sensitivity
*  9 - 0.9pf sensitivity
*  10 - 1.0pf sensitivity
*  All other values, set sensitivity to 1.0pf
*
*  Return Value:
*   None
*
* Global Variables:
* CapSense_sensorSensitivity[] - This 8-bits array contains Sensitivity in the LSB nibble
*                                and Noise Reset Counter value in the MSB nibble.
*
* Side Effects:
*  None
*
*******************************************************************************/
void CapSense_SetSensitivity(uint32 sensor, uint32 value)
{
    if(value > 10u)
    {
        value = 10u;
    }

    /* Clear SensorSensitivity value in LSB nibble */
    CapSense_sensorSensitivity[sensor] &= (uint8)~CapSense_SENSITIVITY_MASK;
    /* Set SensorSensitivity value in LSB nibble */
    CapSense_sensorSensitivity[sensor] |= (uint8)value;
}


/*******************************************************************************
* Function Name: CapSense_GetSensitivityCoefficient
********************************************************************************
*
* Summary:
*  This API returns the K coefficient for the appropriate sensor.
*
* Parameters:
*  sensor:  Sensor index
*
*  Return Value:
*   K - value for the appropriate sensor.
*
* Global Variables:
*  CapSense_kValueTbl[] - This 8-bits array contains the K value for each sensor.
*
* Side Effects:
*  None
*
*******************************************************************************/
uint8 CapSense_GetSensitivityCoefficient(uint32 sensor)
{
    return (CapSense_kValueTbl[sensor]);
}


/*******************************************************************************
* Function Name: CapSense_GetNoiseEnvelope
********************************************************************************
*
* Summary:
*  This function returns the noise value of a
*  component.
*
* Parameters:
*  sensor - Sensor number.
*
* Return:
*  The noise envelope value of the sensor
*  indicated by argument.
*
* Global Variables:
*  CapSense_noiseEnvelopeTbl[] - array with Noise Envelope.
*
* Side Effects:
*  None
*
*******************************************************************************/
uint16 CapSense_GetNoiseEnvelope(uint32 sensor)
{
    return((uint16)((uint16)CapSense_noiseEnvelopeTbl[sensor] << 1u) + 1u);
}


/*******************************************************************************
* Function Name: CapSense_GetNormalizedDiffCountData
********************************************************************************
*
* Summary:
*  This API returns normalized difference count data.
*
* Parameters:
*  sensor:  Sensor number.
*
* Return:
*  This API returns a normalized count value of the sensor indicated by the
*  argument.
*
* Global Variables:
*  CapSense_sensorSignal[] - array with difference counts for sensors
*
* Side Effects:
*  None
*
*******************************************************************************/
uint16 CapSense_GetNormalizedDiffCountData(uint32 sensor)
{
    return (uint16)(((uint32)CapSense_sensorSignal[sensor] << 7u) / CapSense_kValueTbl[sensor]);
}

#endif /* (CapSense_TUNING_METHOD == CapSense__TUNING_AUTO) */

/* [] END OF FILE */
>>>>>>> remotes/origin/master
