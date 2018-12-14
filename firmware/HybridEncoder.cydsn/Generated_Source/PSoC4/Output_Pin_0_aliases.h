/*******************************************************************************
* File Name: Output_Pin_0.h  
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

#if !defined(CY_PINS_Output_Pin_0_ALIASES_H) /* Pins Output_Pin_0_ALIASES_H */
#define CY_PINS_Output_Pin_0_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Output_Pin_0_0			(Output_Pin_0__0__PC)
#define Output_Pin_0_0_PS		(Output_Pin_0__0__PS)
#define Output_Pin_0_0_PC		(Output_Pin_0__0__PC)
#define Output_Pin_0_0_DR		(Output_Pin_0__0__DR)
#define Output_Pin_0_0_SHIFT	(Output_Pin_0__0__SHIFT)
#define Output_Pin_0_0_INTR	((uint16)((uint16)0x0003u << (Output_Pin_0__0__SHIFT*2u)))

#define Output_Pin_0_INTR_ALL	 ((uint16)(Output_Pin_0_0_INTR))


#endif /* End Pins Output_Pin_0_ALIASES_H */


/* [] END OF FILE */
