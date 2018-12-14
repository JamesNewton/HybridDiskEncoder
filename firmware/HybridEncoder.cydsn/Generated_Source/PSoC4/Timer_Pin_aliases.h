/*******************************************************************************
* File Name: Timer_Pin.h  
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

#if !defined(CY_PINS_Timer_Pin_ALIASES_H) /* Pins Timer_Pin_ALIASES_H */
#define CY_PINS_Timer_Pin_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Timer_Pin_0			(Timer_Pin__0__PC)
#define Timer_Pin_0_PS		(Timer_Pin__0__PS)
#define Timer_Pin_0_PC		(Timer_Pin__0__PC)
#define Timer_Pin_0_DR		(Timer_Pin__0__DR)
#define Timer_Pin_0_SHIFT	(Timer_Pin__0__SHIFT)
#define Timer_Pin_0_INTR	((uint16)((uint16)0x0003u << (Timer_Pin__0__SHIFT*2u)))

#define Timer_Pin_INTR_ALL	 ((uint16)(Timer_Pin_0_INTR))


#endif /* End Pins Timer_Pin_ALIASES_H */


/* [] END OF FILE */
