/*******************************************************************************
* File Name: PWM_2_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_2.h"

static PWM_2_BACKUP_STRUCT PWM_2_backup;


/*******************************************************************************
* Function Name: PWM_2_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_2_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM_2_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_2_Sleep(void)
{
    if(0u != (PWM_2_BLOCK_CONTROL_REG & PWM_2_MASK))
    {
        PWM_2_backup.enableState = 1u;
    }
    else
    {
        PWM_2_backup.enableState = 0u;
    }

    PWM_2_Stop();
    PWM_2_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_2_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_2_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM_2_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_2_Wakeup(void)
{
    PWM_2_RestoreConfig();

    if(0u != PWM_2_backup.enableState)
    {
        PWM_2_Enable();
    }
}


/* [] END OF FILE */
