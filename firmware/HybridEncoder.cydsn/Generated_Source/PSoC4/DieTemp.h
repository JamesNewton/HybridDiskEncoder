<<<<<<< HEAD
/*******************************************************************************
* File Name: DieTemp.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the DieTemp_P4
*  component.
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_DIE_TEMP_DieTemp_H)
#define CY_DIE_TEMP_DieTemp_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h"
#include "cydevice_trm.h"


/***************************************
*        API constants
***************************************/

#define DieTemp_SAR_TEMP_MULTIPLIER_REG    (*(reg16 *) CYREG_SFLASH_SAR_TEMP_MULTIPLIER)
#define DieTemp_SAR_TEMP_MULTIPLIER_PTR    ( (reg16 *) CYREG_SFLASH_SAR_TEMP_MULTIPLIER)
#define DieTemp_SAR_TEMP_OFFSET_REG        (*(reg16 *) CYREG_SFLASH_SAR_TEMP_OFFSET)
#define DieTemp_SAR_TEMP_OFFSET_PTR        ( (reg16 *) CYREG_SFLASH_SAR_TEMP_OFFSET)

#define DieTemp_SAR_TEMP_OFFSET_SHIFT      (10u)
#define DieTemp_SAR_TEMP_OFFSET_MULT       (0x400)
#define DieTemp_SAR_TEMP_OFFSET_DIVIDER    (0x10000)
#define DieTemp_SAR_TEMP_SHIFT             (16u)
#define DieTemp_SAR_TEMP_DIVIDER           (0x10000)
#define DieTemp_SCALE_ADJUSTMENT_DIVIDER   (16u)
#define DieTemp_HALF_OF_ONE                ((int32)1u << (DieTemp_SAR_TEMP_SHIFT - 1u))

/* (effectively 0.5 << 4u) 0.5 in Q28.4 format */
#define DieTemp_SCALE_ADJUSTMENT           (8)
/* 15 in Q16.16 format */
#define DieTemp_DUAL_SLOPE_CORRECTION      (0xF0000)
/* 100 in Q16.16 format */
#define DieTemp_HIGH_TEMPERATURE           (0x640000)
/* 40 in Q16.16 format */
#define DieTemp_LOW_TEMPERATURE            (0x280000)


/***************************************
*        Function Prototypes
***************************************/

int32 DieTemp_CountsTo_Celsius(int32 adcCounts);


#endif /* CY_DIE_TEMP_DieTemp_H */

/* [] END OF FILE */
=======
/*******************************************************************************
* File Name: DieTemp.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the DieTemp_P4
*  component.
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_DIE_TEMP_DieTemp_H)
#define CY_DIE_TEMP_DieTemp_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h"
#include "cydevice_trm.h"


/***************************************
*        API constants
***************************************/

#define DieTemp_SAR_TEMP_MULTIPLIER_REG    (*(reg16 *) CYREG_SFLASH_SAR_TEMP_MULTIPLIER)
#define DieTemp_SAR_TEMP_MULTIPLIER_PTR    ( (reg16 *) CYREG_SFLASH_SAR_TEMP_MULTIPLIER)
#define DieTemp_SAR_TEMP_OFFSET_REG        (*(reg16 *) CYREG_SFLASH_SAR_TEMP_OFFSET)
#define DieTemp_SAR_TEMP_OFFSET_PTR        ( (reg16 *) CYREG_SFLASH_SAR_TEMP_OFFSET)

#define DieTemp_SAR_TEMP_OFFSET_SHIFT      (10u)
#define DieTemp_SAR_TEMP_OFFSET_MULT       (0x400)
#define DieTemp_SAR_TEMP_OFFSET_DIVIDER    (0x10000)
#define DieTemp_SAR_TEMP_SHIFT             (16u)
#define DieTemp_SAR_TEMP_DIVIDER           (0x10000)
#define DieTemp_SCALE_ADJUSTMENT_DIVIDER   (16u)
#define DieTemp_HALF_OF_ONE                ((int32)1u << (DieTemp_SAR_TEMP_SHIFT - 1u))

/* (effectively 0.5 << 4u) 0.5 in Q28.4 format */
#define DieTemp_SCALE_ADJUSTMENT           (8)
/* 15 in Q16.16 format */
#define DieTemp_DUAL_SLOPE_CORRECTION      (0xF0000)
/* 100 in Q16.16 format */
#define DieTemp_HIGH_TEMPERATURE           (0x640000)
/* 40 in Q16.16 format */
#define DieTemp_LOW_TEMPERATURE            (0x280000)


/***************************************
*        Function Prototypes
***************************************/

int32 DieTemp_CountsTo_Celsius(int32 adcCounts);


#endif /* CY_DIE_TEMP_DieTemp_H */

/* [] END OF FILE */
>>>>>>> remotes/origin/master
