/*******************************************************************************
* File Name: CompM_1.h  
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

#if !defined(CY_PINS_CompM_1_ALIASES_H) /* Pins CompM_1_ALIASES_H */
#define CY_PINS_CompM_1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define CompM_1_0			(CompM_1__0__PC)
#define CompM_1_0_PS		(CompM_1__0__PS)
#define CompM_1_0_PC		(CompM_1__0__PC)
#define CompM_1_0_DR		(CompM_1__0__DR)
#define CompM_1_0_SHIFT	(CompM_1__0__SHIFT)
#define CompM_1_0_INTR	((uint16)((uint16)0x0003u << (CompM_1__0__SHIFT*2u)))

#define CompM_1_INTR_ALL	 ((uint16)(CompM_1_0_INTR))


#endif /* End Pins CompM_1_ALIASES_H */


/* [] END OF FILE */
