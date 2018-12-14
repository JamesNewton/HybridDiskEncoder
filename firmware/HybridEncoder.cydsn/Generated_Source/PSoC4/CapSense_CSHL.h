/*******************************************************************************
* File Name: CapSense_CSHL.h
* Version 2.60
*
* Description:
*  This file provides constants and parameter values for the High Level APIs
*  for CapSense CSD component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CAPSENSE_CSD_CSHL_CapSense_H)
#define CY_CAPSENSE_CSD_CSHL_CapSense_H

#include "CapSense.h"


/***************************************
*   Condition compilation parameters
***************************************/

#define CapSense_SIGNAL_SIZE                    (8u)
#define CapSense_AUTO_RESET                     (0u)
#define CapSense_RAW_FILTER_MASK                (8u)

/* Signal size definition */
#define CapSense_SIGNAL_SIZE_UINT8              (8u)
#define CapSense_SIGNAL_SIZE_UINT16             (16u)

/* Auto reset definition */
#define CapSense_AUTO_RESET_DISABLE             (0u)
#define CapSense_AUTO_RESET_ENABLE              (1u)

/* Mask for RAW and POS filters */
#define CapSense_MEDIAN_FILTER                  (0x01u)
#define CapSense_AVERAGING_FILTER               (0x02u)
#define CapSense_IIR2_FILTER                    (0x04u)
#define CapSense_IIR4_FILTER                    (0x08u)
#define CapSense_JITTER_FILTER                  (0x10u)
#define CapSense_IIR8_FILTER                    (0x20u)
#define CapSense_IIR16_FILTER                   (0x40u)
#define CapSense_RAW_FILTERS_ENABLED            (0x01u)
#define CapSense_RAW_FILTERS_DISABLED           (0x00u)

/***************************************
*           API Constants
***************************************/

/* Widgets constants definition */
#define CapSense_BUTTON0__BTN        (0u)
#define CapSense_BUTTON1__BTN        (1u)

#define CapSense_TOTAL_DIPLEXED_SLIDERS_COUNT        (0u)
#define CapSense_TOTAL_LINEAR_SLIDERS_COUNT          (0u)
#define CapSense_TOTAL_RADIAL_SLIDERS_COUNT          (0u)
#define CapSense_TOTAL_TOUCH_PADS_COUNT              (0u)
#define CapSense_TOTAL_TOUCH_PADS_BASIC_COUNT        (0u)
#define CapSense_TOTAL_TRACKPAD_GESTURES_COUNT       (0u)
#define CapSense_TOTAL_BUTTONS_COUNT                 (2u)
#define CapSense_TOTAL_MATRIX_BUTTONS_COUNT          (0u)
#define CapSense_TOTAL_GENERICS_COUNT                (0u)

#define CapSense_POS_FILTERS_MASK                    (0x0u)
#define CapSense_LINEAR_SLIDERS_POS_FILTERS_MASK     (0x0u)
#define CapSense_RADIAL_SLIDERS_POS_FILTERS_MASK     (0x0u)
#define CapSense_TOUCH_PADS_POS_FILTERS_MASK         (0x0u)
#define CapSense_TRACKPAD_GEST_POS_FILTERS_MASK      (0x0u)

#define CapSense_UNUSED_DEBOUNCE_COUNTER_INDEX       (2u)

#define CapSense_TOTAL_PROX_SENSORS_COUNT            (0u)

#define CapSense_END_OF_SLIDERS_INDEX                (0u)
#define CapSense_END_OF_TOUCH_PAD_INDEX              (0u)
#define CapSense_END_OF_BUTTONS_INDEX                (1u)
#define CapSense_END_OF_MATRIX_BUTTONS_INDEX         (1u)
#define CapSense_END_OF_WIDGETS_INDEX                (2u)



#define CapSense_TOTAL_SLIDERS_COUNT            ( CapSense_TOTAL_LINEAR_SLIDERS_COUNT + \
                                                          CapSense_TOTAL_RADIAL_SLIDERS_COUNT )

#define CapSense_TOTAL_CENTROIDS_COUNT          ( CapSense_TOTAL_SLIDERS_COUNT + \
                                                         (CapSense_TOTAL_TOUCH_PADS_BASIC_COUNT * 2u) +\
                                                         (CapSense_TOTAL_TRACKPAD_GESTURES_COUNT * 4u))

#define CapSense_TOTAL_CENTROIDS_BASIC_COUNT    ( CapSense_TOTAL_SLIDERS_COUNT + \
                                                         (CapSense_TOTAL_TOUCH_PADS_BASIC_COUNT * 2u))

#define CapSense_TOTAL_CENTROID_AXES_COUNT      ( CapSense_TOTAL_SLIDERS_COUNT + \
                                                         (CapSense_TOTAL_TOUCH_PADS_BASIC_COUNT * 2u) +\
                                                         (CapSense_TOTAL_TRACKPAD_GESTURES_COUNT * 2u))

#define CapSense_TOTAL_WIDGET_COUNT             ( CapSense_TOTAL_LINEAR_SLIDERS_COUNT + \
                                                          CapSense_TOTAL_RADIAL_SLIDERS_COUNT + \
                                                          CapSense_TOTAL_TOUCH_PADS_COUNT + \
                                                          CapSense_TOTAL_BUTTONS_COUNT + \
                                                          CapSense_TOTAL_MATRIX_BUTTONS_COUNT )

#define CapSense_ANY_POS_FILTER                 ( CapSense_MEDIAN_FILTER | \
                                                          CapSense_AVERAGING_FILTER | \
                                                          CapSense_IIR2_FILTER | \
                                                          CapSense_IIR4_FILTER | \
                                                          CapSense_JITTER_FILTER )

#define CapSense_IS_DIPLEX_SLIDER               ( CapSense_TOTAL_DIPLEXED_SLIDERS_COUNT > 0u)

#define CapSense_IS_NON_DIPLEX_SLIDER           ( (CapSense_TOTAL_LINEAR_SLIDERS_COUNT - \
                                                           CapSense_TOTAL_DIPLEXED_SLIDERS_COUNT) > 0u)
#define CapSense_ADD_SLIDER_TYPE                ((CapSense_TOTAL_RADIAL_SLIDERS_COUNT > 0u) ? \
                                                        ((CapSense_TOTAL_TOUCH_PADS_COUNT > 0u) || \
                                                         (CapSense_TOTAL_LINEAR_SLIDERS_COUNT > 0u)) : 0u)

#define CapSense_TOTAL_PROX_SENSOR_COUNT        (CapSense_TOTAL_PROX_SENSORS_COUNT)

#define CapSense_WIDGETS_TBL_SIZE               ( CapSense_TOTAL_WIDGET_COUNT + \
                                                          CapSense_TOTAL_GENERICS_COUNT)

#define CapSense_WIDGET_PARAM_TBL_SIZE          (CapSense_TOTAL_BUTTONS_COUNT + \
                                                         CapSense_TOTAL_SLIDERS_COUNT +\
                                                         CapSense_TOTAL_TOUCH_PADS_BASIC_COUNT * 2u + \
                                                         CapSense_TOTAL_TRACKPAD_GESTURES_COUNT * 2u +\
                                                         CapSense_TOTAL_MATRIX_BUTTONS_COUNT * 2u)

#define CapSense_THRESHOLD_TBL_SIZE         (CapSense_WIDGET_PARAM_TBL_SIZE)
#define CapSense_DEBOUNCE_CNT_TBL_SIZE      (CapSense_WIDGET_PARAM_TBL_SIZE)
#define CapSense_RAW_DATA_INDEX_TBL_SIZE    (CapSense_WIDGET_PARAM_TBL_SIZE +\
                                                     CapSense_TOTAL_GENERICS_COUNT)

#define CapSense_RES_MULT                   (256u)


#define CapSense_NOT_WIDGET                     (0xFFFFFFFFu)

/*Types of centroids */
#define CapSense_TYPE_RADIAL_SLIDER             (0x01u)
#define CapSense_TYPE_LINEAR_SLIDER             (0x02u)
#define CapSense_TYPE_GENERIC                   (0xFFu)

/* Defines if sensors or widgets are active */
#define CapSense_SENSOR_IS_ACTIVE               (0x01u)
#define CapSense_SENSOR_1_IS_ACTIVE             (0x01u)
#define CapSense_SENSOR_2_IS_ACTIVE             (0x02u)
#define CapSense_WIDGET_IS_ACTIVE               (0x01u)

/* Defines diplex type of Slider */
#define CapSense_IS_DIPLEX                      (0x80u)

/* Defines fingers positions on Slider  */
#define CapSense_POS_PREV                       (0u)
#define CapSense_POS                            (1u)
#define CapSense_POS_NEXT                       (2u)
#define CapSense_CENTROID_ROUND_VALUE           (0x7F00u)
#define CapSense_MAXIMUM_CENTROID               (0xFFu)

#define CapSense_NEGATIVE_NOISE_THRESHOLD       (20u)
#define CapSense_LOW_BASELINE_RESET             (5u)


/***************************************
*        Function Prototypes
***************************************/

void CapSense_InitializeSensorBaseline(uint32 sensor);
void CapSense_InitializeAllBaselines(void);
void CapSense_InitializeEnabledBaselines(void);
void CapSense_UpdateSensorBaseline(uint32 sensor);
void CapSense_UpdateBaselineNoThreshold(uint32 sensor);
void CapSense_UpdateEnabledBaselines(void);
void CapSense_UpdateWidgetBaseline(uint32 widget);
uint16 CapSense_GetBaselineData(uint32 sensor);
void CapSense_SetBaselineData(uint32 sensor, uint16 data);
void CapSense_BaseInit(uint32 sensor);

#if (CapSense_IS_DIPLEX_SLIDER)
    uint8 CapSense_FindMaximum(uint8 offset, uint8 count, uint8 fingerThreshold, const uint8 *diplex);
#else
    uint8 CapSense_FindMaximum(uint8 offset, uint8 count, uint8 fingerThreshold);
#endif /* (CapSense_IS_DIPLEX_SLIDER) */

#if (CapSense_TOTAL_TRACKPAD_GESTURES_COUNT > 0u)
    uint8 CapSense_CalcCentroid(uint8 maximum, uint8 offset, \
                                    uint8 count, uint32 resolution, uint8 noiseThreshold);
#else
    uint8 CapSense_CalcCentroid(uint8 maximum, uint8 offset, \
                                    uint8 count, uint16 resolution, uint8 noiseThreshold);
#endif /* (CapSense_TOTAL_TRACKPAD_GESTURES_COUNT > 0u) */


uint8 CapSense_GetFingerThreshold(uint32 widget);
uint8 CapSense_GetNoiseThreshold(uint32 widget);
uint8 CapSense_GetFingerHysteresis(uint32 widget);
uint8 CapSense_GetNegativeNoiseThreshold(uint32 widget);

#if(CapSense_TUNING_METHOD != CapSense__TUNING_NONE)
    void CapSense_SetFingerThreshold(uint32 widget, uint8 value);
    void CapSense_SetNoiseThreshold(uint32 widget, uint8 value);
    void CapSense_SetFingerHysteresis(uint32 widget, uint8 value);
    void CapSense_SetNegativeNoiseThreshold(uint32 widget, uint8 value);
    void CapSense_SetDebounce(uint32 widget, uint8 value);
    void CapSense_SetLowBaselineReset(uint32 sensor, uint8 value);
#endif /* (CapSense_TUNING_METHOD != CapSense__TUNING_NONE) */

uint8 CapSense_GetDiffCountData(uint32 sensor);
void CapSense_SetDiffCountData(uint32 sensor, uint8 value);

uint32 CapSense_CheckIsSensorActive(uint32 sensor);
uint32 CapSense_CheckIsWidgetActive(uint32 widget);
uint32 CapSense_CheckIsAnyWidgetActive(void);
void CapSense_EnableWidget(uint32 widget);
void CapSense_DisableWidget(uint32 widget);
void CapSense_EnableRawDataFilters(void);
void CapSense_DisableRawDataFilters(void);

#if (CapSense_TOTAL_MATRIX_BUTTONS_COUNT)
    uint32 CapSense_GetMatrixButtonPos(uint32 widget, uint8* pos);
#endif /* (CapSense_TOTAL_MATRIX_BUTTONS_COUNT) */

#if((CapSense_TOTAL_RADIAL_SLIDERS_COUNT > 0u) || (CapSense_TOTAL_LINEAR_SLIDERS_COUNT > 0u))
    uint16 CapSense_GetCentroidPos(uint32 widget);
#endif /* ((CapSense_TOTAL_RADIAL_SLIDERS_COUNT > 0u) || (CapSense_TOTAL_LINEAR_SLIDERS_COUNT > 0u)) */
#if((CapSense_TOTAL_RADIAL_SLIDERS_COUNT > 0u) || (CapSense_TOTAL_LINEAR_SLIDERS_COUNT > 0u))
    uint16 CapSense_GetRadialCentroidPos(uint32 widget);
#endif /* #if((CapSense_TOTAL_RADIAL_SLIDERS_COUNT > 0u) || (CapSense_TOTAL_LINEAR_SLIDERS_COUNT > 0u)) */
#if (CapSense_TOTAL_TOUCH_PADS_COUNT)
    uint32 CapSense_GetTouchCentroidPos(uint32 widget, uint16* pos);
#endif /* (CapSense_TOTAL_TOUCH_PADS_COUNT) */

uint32 CapSense_GetWidgetNumber(uint32 sensor);
uint8 CapSense_GetLowBaselineReset(uint32 sensor);
uint8 CapSense_GetDebounce(uint32 widget);

/* Filter function prototypes for High level APIs */

/* Median filter function prototype */
#if ( (0u != (CapSense_RAW_FILTER_MASK & CapSense_MEDIAN_FILTER)) || \
      (0u != (CapSense_POS_FILTERS_MASK & CapSense_MEDIAN_FILTER)) || \
      ((CapSense_TUNING_METHOD == CapSense__TUNING_AUTO)) )
    uint16 CapSense_MedianFilter(uint16 x1, uint16 x2, uint16 x3);
#endif /* ( (0u != (CapSense_RAW_FILTER_MASK & CapSense_MEDIAN_FILTER)) || \
      (0u != (CapSense_POS_FILTERS_MASK & CapSense_MEDIAN_FILTER)) || \
      ((CapSense_TUNING_METHOD == CapSense__TUNING_AUTO)) ) */

/* Averaging filter function prototype */
#if ( (0u != (CapSense_RAW_FILTER_MASK & CapSense_AVERAGING_FILTER)) || \
      (0u != (CapSense_POS_FILTERS_MASK & CapSense_AVERAGING_FILTER)) )
    uint16 CapSense_AveragingFilter(uint16 x1, uint16 x2, uint16 x3);
#endif /* CapSense_RAW_FILTER_MASK && CapSense_POS_FILTERS_MASK */

/* IIR2Filter(1/2prev + 1/2cur) filter function prototype */
#if ( (0u != (CapSense_RAW_FILTER_MASK & CapSense_IIR2_FILTER)) || \
      (0u != (CapSense_POS_FILTERS_MASK & CapSense_IIR2_FILTER)) )
    uint16 CapSense_IIR2Filter(uint16 x1, uint16 x2);
#endif /* CapSense_RAW_FILTER_MASK && CapSense_POS_FILTERS_MASK */

/* IIR4Filter(3/4prev + 1/4cur) filter function prototype */
#if ( (0u != (CapSense_RAW_FILTER_MASK & CapSense_IIR4_FILTER)) || \
      (0u != (CapSense_POS_FILTERS_MASK & CapSense_IIR4_FILTER)) )
    uint16 CapSense_IIR4Filter(uint16 x1, uint16 x2);
#endif /* CapSense_RAW_FILTER_MASK && CapSense_POS_FILTERS_MASK */

/* IIR8Filter(7/8prev + 1/8cur) filter function prototype - RawCounts only */
#if (0u != (CapSense_RAW_FILTER_MASK & CapSense_IIR8_FILTER))
    uint16 CapSense_IIR8Filter(uint16 x1, uint16 x2);
#endif /* CapSense_RAW_FILTER_MASK */

/* IIR16Filter(15/16prev + 1/16cur) filter function prototype - RawCounts only */
#if (0u != (CapSense_RAW_FILTER_MASK & CapSense_IIR16_FILTER))
    uint16 CapSense_IIR16Filter(uint16 x1, uint16 x2);
#endif /* CapSense_RAW_FILTER_MASK */

/* JitterFilter filter function prototype */
#if ( (0u != (CapSense_RAW_FILTER_MASK & CapSense_JITTER_FILTER)) || \
      (0u != (CapSense_POS_FILTERS_MASK & CapSense_JITTER_FILTER)) || \
      (0u != (CapSense_TRACKPAD_GEST_POS_FILTERS_MASK & CapSense_JITTER_FILTER)))
    uint16 CapSense_JitterFilter(uint16 x1, uint16 x2);
#endif /* ( (0u != (CapSense_RAW_FILTER_MASK & CapSense_JITTER_FILTER)) || \
       *    (0u != (CapSense_POS_FILTERS_MASK & CapSense_JITTER_FILTER)) )
       *    (0u != (CapSense_TRACKPAD_GEST_POS_FILTERS_MASK & CapSense_JITTER_FILTER)) )
       */


/***************************************
*     Vars with External Linkage
***************************************/
extern uint16 CapSense_sensorBaseline[CapSense_TOTAL_SENSOR_COUNT];
extern uint8  CapSense_sensorBaselineLow[CapSense_TOTAL_SENSOR_COUNT];
extern uint8 CapSense_sensorSignal[CapSense_TOTAL_SENSOR_COUNT];
extern uint8  CapSense_sensorOnMask[CapSense_TOTAL_SENSOR_MASK];

extern uint8 CapSense_lowBaselineResetCnt[CapSense_TOTAL_SENSOR_COUNT];
extern uint8 CapSense_lowBaselineReset[CapSense_TOTAL_SENSOR_COUNT];

/* Generated by Customizer */
#if (CapSense_TUNING_METHOD != CapSense__TUNING_NONE)
    extern uint8 CapSense_fingerThreshold[CapSense_WIDGET_PARAM_TBL_SIZE];
    extern uint8 CapSense_noiseThreshold[CapSense_WIDGET_PARAM_TBL_SIZE];
    extern uint8 CapSense_negativeNoiseThreshold[CapSense_WIDGET_PARAM_TBL_SIZE];
    extern uint8 CapSense_hysteresis[CapSense_WIDGET_PARAM_TBL_SIZE];
    extern uint8  CapSense_debounce[CapSense_WIDGET_PARAM_TBL_SIZE];
#else
    extern const uint8 CapSense_fingerThreshold[CapSense_WIDGET_PARAM_TBL_SIZE];
    extern const uint8 CapSense_noiseThreshold[CapSense_WIDGET_PARAM_TBL_SIZE];
    extern const uint8 CapSense_hysteresis[CapSense_WIDGET_PARAM_TBL_SIZE];
    extern const uint8  CapSense_debounce[CapSense_WIDGET_PARAM_TBL_SIZE];
#endif /* (CapSense_TUNING_METHOD != CapSense__TUNING_NONE) */

extern const uint8 CapSense_rawDataIndex[CapSense_RAW_DATA_INDEX_TBL_SIZE];
extern const uint8 CapSense_numberOfSensors[CapSense_RAW_DATA_INDEX_TBL_SIZE];

#if (0u != CapSense_TOTAL_TRACKPAD_GESTURES_COUNT)
    #if (CapSense_TUNING_METHOD != CapSense__TUNING_NONE)
        extern uint8 CapSense_posFiltersMask[CapSense_TOTAL_CENTROID_AXES_COUNT];
    #else
        extern const uint8 CapSense_posFiltersMask[CapSense_TOTAL_CENTROID_AXES_COUNT];
    #endif /* (CapSense_TUNING_METHOD != CapSense__TUNING_NONE) */

    extern uint32 CapSense_centroidMult[CapSense_TOTAL_CENTROID_AXES_COUNT];
#endif /* (0u != CapSense_TOTAL_TRACKPAD_GESTURES_COUNT) */

/***************************************
*        Obsolete Names
***************************************/
#define CapSense_SensorRaw              CapSense_sensorRaw
#define CapSense_SensorEnableMask       CapSense_sensorEnableMask
#define CapSense_SensorBaseline         CapSense_sensorBaseline
#define CapSense_SensorBaselineLow      CapSense_sensorBaselineLow
#define CapSense_SensorSignal           CapSense_sensorSignal
#define CapSense_SensorOnMask           CapSense_sensorOnMask
#define CapSense_LowBaselineResetCnt    CapSense_lowBaselineResetCnt

#endif /* CY_CAPSENSE_CSD_CSHL_CapSense_H */

/* [] END OF FILE */
