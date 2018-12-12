/*******************************************************************************
* File Name: ADC_3.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_ADC_3_ALIASES_H) /* Pins ADC_3_ALIASES_H */
#define CY_PINS_ADC_3_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define ADC_3_0			(ADC_3__0__PC)
#define ADC_3_0_PS		(ADC_3__0__PS)
#define ADC_3_0_PC		(ADC_3__0__PC)
#define ADC_3_0_DR		(ADC_3__0__DR)
#define ADC_3_0_SHIFT	(ADC_3__0__SHIFT)
#define ADC_3_0_INTR	((uint16)((uint16)0x0003u << (ADC_3__0__SHIFT*2u)))

#define ADC_3_INTR_ALL	 ((uint16)(ADC_3_0_INTR))


#endif /* End Pins ADC_3_ALIASES_H */


/* [] END OF FILE */
