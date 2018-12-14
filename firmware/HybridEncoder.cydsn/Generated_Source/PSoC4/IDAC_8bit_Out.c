/*******************************************************************************
* File Name: IDAC_8bit_Out.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "IDAC_8bit_Out.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        IDAC_8bit_Out_PC =   (IDAC_8bit_Out_PC & \
                                (uint32)(~(uint32)(IDAC_8bit_Out_DRIVE_MODE_IND_MASK << (IDAC_8bit_Out_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (IDAC_8bit_Out_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: IDAC_8bit_Out_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void IDAC_8bit_Out_Write(uint8 value) 
{
    uint8 drVal = (uint8)(IDAC_8bit_Out_DR & (uint8)(~IDAC_8bit_Out_MASK));
    drVal = (drVal | ((uint8)(value << IDAC_8bit_Out_SHIFT) & IDAC_8bit_Out_MASK));
    IDAC_8bit_Out_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: IDAC_8bit_Out_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  IDAC_8bit_Out_DM_STRONG     Strong Drive 
*  IDAC_8bit_Out_DM_OD_HI      Open Drain, Drives High 
*  IDAC_8bit_Out_DM_OD_LO      Open Drain, Drives Low 
*  IDAC_8bit_Out_DM_RES_UP     Resistive Pull Up 
*  IDAC_8bit_Out_DM_RES_DWN    Resistive Pull Down 
*  IDAC_8bit_Out_DM_RES_UPDWN  Resistive Pull Up/Down 
*  IDAC_8bit_Out_DM_DIG_HIZ    High Impedance Digital 
*  IDAC_8bit_Out_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void IDAC_8bit_Out_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(IDAC_8bit_Out__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: IDAC_8bit_Out_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro IDAC_8bit_Out_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 IDAC_8bit_Out_Read(void) 
{
    return (uint8)((IDAC_8bit_Out_PS & IDAC_8bit_Out_MASK) >> IDAC_8bit_Out_SHIFT);
}


/*******************************************************************************
* Function Name: IDAC_8bit_Out_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 IDAC_8bit_Out_ReadDataReg(void) 
{
    return (uint8)((IDAC_8bit_Out_DR & IDAC_8bit_Out_MASK) >> IDAC_8bit_Out_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(IDAC_8bit_Out_INTSTAT) 

    /*******************************************************************************
    * Function Name: IDAC_8bit_Out_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 IDAC_8bit_Out_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(IDAC_8bit_Out_INTSTAT & IDAC_8bit_Out_MASK);
		IDAC_8bit_Out_INTSTAT = maskedStatus;
        return maskedStatus >> IDAC_8bit_Out_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
