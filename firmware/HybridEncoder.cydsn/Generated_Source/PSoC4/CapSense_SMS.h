<<<<<<< HEAD
/*******************************************************************************
* File Name: CapSense_SMS.h
* Version 2.60
*
* Description:
*  This file provides the declarations of the wrapper between the CapSense CSD component
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
#if !defined(CY_CAPSENSE_CSD_SMS_CapSense_H)
#define CY_CAPSENSE_CSD_SMS_CapSense_H

#include "CapSense.h"
#include "CapSense_PVT.h"

#if(0u != CapSense_CSHL_API_GENERATE)
    #include "CapSense_CSHL.h"
#endif /* (0u != CapSense_CSHL_API_GENERATE) */

#define CapSense_PRESCALERS_TBL_SIZE        (16u)

#define CapSense_CALIBRATION_FREQ_KHZ       (3000u)
#define CapSense_CALIBRATION_MD             (4u)

#define CapSense_MAX_RESOLUTION         (65535u)
#define CapSense_CALIBRATION_RESOLUTION (0x0FFF0000u)

#define CapSense_PRS_CORRECTION_DIVIDER (4u)
#define CapSense_SENSITIVITY_DIVIDER    (10u)

#define CapSense_SENSITIVITY_MASK           (0x0Fu)
#define CapSense_FLEXIBLE_THRESHOLDS_EN     (0u)
#define CapSense_CAL_RAW_COUNT              (3482u)

#define CapSense_THRESHOLD_1                (220u)
#define CapSense_THRESHOLD_2                (237u)
#define CapSense_THRESHOLD_3                (245u)
#define CapSense_THRESHOLD_4                (250u)


#if (0u != CapSense_IS_M0S8PERI_BLOCK)
    #define CapSense_CALIBRATION_ASD        (CYDEV_BCLK__HFCLK__KHZ /\
                                                     CapSense_CALIBRATION_FREQ_KHZ)
#else
    #define CapSense_MIN_IMO_FREQ_KHZ       (6000u)
    #if(CYDEV_BCLK__HFCLK__KHZ < CapSense_MIN_IMO_FREQ_KHZ)
        #define CapSense_CALIBRATION_ASD            (1u)
    #else
        #define CapSense_CALIBRATION_ASD    (CYDEV_BCLK__HFCLK__KHZ / CapSense_CALIBRATION_MD /\
                                                     CapSense_CALIBRATION_FREQ_KHZ)
    #endif /* (CYDEV_BCLK__HFCLK__KHZ < CapSense_MIN_IMO_FREQ_KHZ) */
#endif /* (0u != CapSense_IS_M0S8PERI_BLOCK) */

#if (0u != CapSense_IS_M0S8PERI_BLOCK)
    /*  Dividers are not chained */
    #if(CapSense_PRS_OPTIONS != CapSense__PRS_NONE)
        #define CapSense_SENSETIVITY_FACTOR (1228u)
    #else
        #define CapSense_SENSETIVITY_FACTOR (2456u)
    #endif /* (CapSense_PRS_OPTIONS == CapSense__PRS_NONE) */
#else
    /*  Dividers are chained */
    #if(CapSense_PRS_OPTIONS != CapSense__PRS_NONE)
        #define CapSense_SENSETIVITY_FACTOR (1228u/CapSense_CALIBRATION_MD)
    #else
        #define CapSense_SENSETIVITY_FACTOR (2456u/CapSense_CALIBRATION_MD)
    #endif /* (CapSense_PRS_OPTIONS == CapSense__PRS_NONE) */
#endif /* (0u != CapSense_IS_M0S8PERI_BLOCK) */


/***************************************
*        Function Prototypes
***************************************/
void CapSense_AutoTune(void);
void CapSense_UpdateThresholds(uint32 sensor);
void CapSense_SetSensitivity(uint32 sensor, uint32 value);
void CapSense_SetAnalogSwitchesSrcDirect(void);
uint16 CapSense_GetNoiseEnvelope(uint32 sensor);
uint8 CapSense_GetSensitivityCoefficient(uint32 sensor);
uint16 CapSense_GetNormalizedDiffCountData(uint32 sensor);


/***************************************
*     Vars with External Linkage
***************************************/

/*  Real Charge Divider values */
#if (0u != CapSense_IS_M0S8PERI_BLOCK)
    /*  Dividers are not chained */
    #if (CYDEV_BCLK__HFCLK__MHZ >= 12u)
        extern const uint8 prescalerTable[CapSense_PRESCALERS_TBL_SIZE];
    #elif (CYDEV_BCLK__HFCLK__MHZ >= 6u)
        extern const uint8 prescalerTable[CapSense_PRESCALERS_TBL_SIZE];
    #else
        extern const uint8 prescalerTable[CapSense_PRESCALERS_TBL_SIZE];
    #endif /* (CYDEV_BCLK__HFCLK__MHZ > 12u) */
#else
    /*  Dividers are chained */
    #if (CYDEV_BCLK__HFCLK__MHZ > 24u)
        extern const uint8 prescalerTable[CapSense_PRESCALERS_TBL_SIZE];
    #elif (CYDEV_BCLK__HFCLK__MHZ >12u)
        extern const uint8 prescalerTable[CapSense_PRESCALERS_TBL_SIZE];
    #else   /* (CYDEV_BCLK__HFCLK__MHZ > 12u) */
        extern const uint8 prescalerTable[CapSense_PRESCALERS_TBL_SIZE];
    #endif /* (CYDEV_BCLK__HFCLK__MHZ > 24u) */
#endif /* (0u != CapSense_IS_M0S8PERI_BLOCK) */


extern uint8 CapSense_noiseEnvelopeTbl[CapSense_TOTAL_SENSOR_COUNT];
extern uint8 CapSense_runningDifferenceTbl[CapSense_TOTAL_SENSOR_COUNT];
extern uint8 CapSense_signRegisterTbl[CapSense_TOTAL_SENSOR_COUNT];
extern uint16 CapSense_sampleMinTbl[CapSense_TOTAL_SENSOR_COUNT];
extern uint16 CapSense_sampleMaxTbl[CapSense_TOTAL_SENSOR_COUNT];
extern uint16 CapSense_previousSampleTbl[CapSense_TOTAL_SENSOR_COUNT];
extern uint8 CapSense_kValueTbl[CapSense_TOTAL_SENSOR_COUNT];


#endif  /* (CY_CAPSENSE_CSD_SMS_CapSense_H) */

/* [] END OF FILE */
=======
/*******************************************************************************
* File Name: CapSense_SMS.h
* Version 2.60
*
* Description:
*  This file provides the declarations of the wrapper between the CapSense CSD component
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
#if !defined(CY_CAPSENSE_CSD_SMS_CapSense_H)
#define CY_CAPSENSE_CSD_SMS_CapSense_H

#include "CapSense.h"
#include "CapSense_PVT.h"

#if(0u != CapSense_CSHL_API_GENERATE)
    #include "CapSense_CSHL.h"
#endif /* (0u != CapSense_CSHL_API_GENERATE) */

#define CapSense_PRESCALERS_TBL_SIZE        (16u)

#define CapSense_CALIBRATION_FREQ_KHZ       (3000u)
#define CapSense_CALIBRATION_MD             (4u)

#define CapSense_MAX_RESOLUTION         (65535u)
#define CapSense_CALIBRATION_RESOLUTION (0x0FFF0000u)

#define CapSense_PRS_CORRECTION_DIVIDER (4u)
#define CapSense_SENSITIVITY_DIVIDER    (10u)

#define CapSense_SENSITIVITY_MASK           (0x0Fu)
#define CapSense_FLEXIBLE_THRESHOLDS_EN     (0u)
#define CapSense_CAL_RAW_COUNT              (3482u)

#define CapSense_THRESHOLD_1                (220u)
#define CapSense_THRESHOLD_2                (237u)
#define CapSense_THRESHOLD_3                (245u)
#define CapSense_THRESHOLD_4                (250u)


#if (0u != CapSense_IS_M0S8PERI_BLOCK)
    #define CapSense_CALIBRATION_ASD        (CYDEV_BCLK__HFCLK__KHZ /\
                                                     CapSense_CALIBRATION_FREQ_KHZ)
#else
    #define CapSense_MIN_IMO_FREQ_KHZ       (6000u)
    #if(CYDEV_BCLK__HFCLK__KHZ < CapSense_MIN_IMO_FREQ_KHZ)
        #define CapSense_CALIBRATION_ASD            (1u)
    #else
        #define CapSense_CALIBRATION_ASD    (CYDEV_BCLK__HFCLK__KHZ / CapSense_CALIBRATION_MD /\
                                                     CapSense_CALIBRATION_FREQ_KHZ)
    #endif /* (CYDEV_BCLK__HFCLK__KHZ < CapSense_MIN_IMO_FREQ_KHZ) */
#endif /* (0u != CapSense_IS_M0S8PERI_BLOCK) */

#if (0u != CapSense_IS_M0S8PERI_BLOCK)
    /*  Dividers are not chained */
    #if(CapSense_PRS_OPTIONS != CapSense__PRS_NONE)
        #define CapSense_SENSETIVITY_FACTOR (1228u)
    #else
        #define CapSense_SENSETIVITY_FACTOR (2456u)
    #endif /* (CapSense_PRS_OPTIONS == CapSense__PRS_NONE) */
#else
    /*  Dividers are chained */
    #if(CapSense_PRS_OPTIONS != CapSense__PRS_NONE)
        #define CapSense_SENSETIVITY_FACTOR (1228u/CapSense_CALIBRATION_MD)
    #else
        #define CapSense_SENSETIVITY_FACTOR (2456u/CapSense_CALIBRATION_MD)
    #endif /* (CapSense_PRS_OPTIONS == CapSense__PRS_NONE) */
#endif /* (0u != CapSense_IS_M0S8PERI_BLOCK) */


/***************************************
*        Function Prototypes
***************************************/
void CapSense_AutoTune(void);
void CapSense_UpdateThresholds(uint32 sensor);
void CapSense_SetSensitivity(uint32 sensor, uint32 value);
void CapSense_SetAnalogSwitchesSrcDirect(void);
uint16 CapSense_GetNoiseEnvelope(uint32 sensor);
uint8 CapSense_GetSensitivityCoefficient(uint32 sensor);
uint16 CapSense_GetNormalizedDiffCountData(uint32 sensor);


/***************************************
*     Vars with External Linkage
***************************************/

/*  Real Charge Divider values */
#if (0u != CapSense_IS_M0S8PERI_BLOCK)
    /*  Dividers are not chained */
    #if (CYDEV_BCLK__HFCLK__MHZ >= 12u)
        extern const uint8 prescalerTable[CapSense_PRESCALERS_TBL_SIZE];
    #elif (CYDEV_BCLK__HFCLK__MHZ >= 6u)
        extern const uint8 prescalerTable[CapSense_PRESCALERS_TBL_SIZE];
    #else
        extern const uint8 prescalerTable[CapSense_PRESCALERS_TBL_SIZE];
    #endif /* (CYDEV_BCLK__HFCLK__MHZ > 12u) */
#else
    /*  Dividers are chained */
    #if (CYDEV_BCLK__HFCLK__MHZ > 24u)
        extern const uint8 prescalerTable[CapSense_PRESCALERS_TBL_SIZE];
    #elif (CYDEV_BCLK__HFCLK__MHZ >12u)
        extern const uint8 prescalerTable[CapSense_PRESCALERS_TBL_SIZE];
    #else   /* (CYDEV_BCLK__HFCLK__MHZ > 12u) */
        extern const uint8 prescalerTable[CapSense_PRESCALERS_TBL_SIZE];
    #endif /* (CYDEV_BCLK__HFCLK__MHZ > 24u) */
#endif /* (0u != CapSense_IS_M0S8PERI_BLOCK) */


extern uint8 CapSense_noiseEnvelopeTbl[CapSense_TOTAL_SENSOR_COUNT];
extern uint8 CapSense_runningDifferenceTbl[CapSense_TOTAL_SENSOR_COUNT];
extern uint8 CapSense_signRegisterTbl[CapSense_TOTAL_SENSOR_COUNT];
extern uint16 CapSense_sampleMinTbl[CapSense_TOTAL_SENSOR_COUNT];
extern uint16 CapSense_sampleMaxTbl[CapSense_TOTAL_SENSOR_COUNT];
extern uint16 CapSense_previousSampleTbl[CapSense_TOTAL_SENSOR_COUNT];
extern uint8 CapSense_kValueTbl[CapSense_TOTAL_SENSOR_COUNT];


#endif  /* (CY_CAPSENSE_CSD_SMS_CapSense_H) */

/* [] END OF FILE */
>>>>>>> remotes/origin/master
