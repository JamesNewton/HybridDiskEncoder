/*******************************************************************************
* File Name: IDAC_7bit_PM.c
* Version 1.10
*
* Description:
*  This file provides Low power mode APIs for IDAC_P4 component.
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "IDAC_7bit.h"


static IDAC_7bit_BACKUP_STRUCT IDAC_7bit_backup;


/*******************************************************************************
* Function Name: IDAC_7bit_SaveConfig
********************************************************************************
*
* Summary:
*  Saves component state before sleep
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  None
*
*******************************************************************************/
void IDAC_7bit_SaveConfig(void)
{
    /* All registers are retention - nothing to save */
}


/*******************************************************************************
* Function Name: IDAC_7bit_Sleep
********************************************************************************
*
* Summary:
*  Calls _SaveConfig() function
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void IDAC_7bit_Sleep(void)
{
        if(0u != (IDAC_7bit_IDAC_CONTROL_REG & ((uint32)IDAC_7bit_IDAC_MODE_MASK <<
        IDAC_7bit_IDAC_MODE_POSITION)))
        {
            IDAC_7bit_backup.enableState = 1u;
        }
        else
        {
            IDAC_7bit_backup.enableState = 0u;
        }

    IDAC_7bit_Stop();
    IDAC_7bit_SaveConfig();
}


/*******************************************************************************
* Function Name: IDAC_7bit_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores component state after wakeup
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  None
*
*******************************************************************************/
void IDAC_7bit_RestoreConfig(void)
{
    /* All registers are retention - nothing to save */
}


/*******************************************************************************
* Function Name: IDAC_7bit_Wakeup
********************************************************************************
*
* Summary:
*  Calls _RestoreConfig() function
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void IDAC_7bit_Wakeup(void)
{
    /* Restore IDAC register settings */
    IDAC_7bit_RestoreConfig();
    if(IDAC_7bit_backup.enableState == 1u)
    {
        /* Enable operation */
        IDAC_7bit_Enable();
    } /* Do nothing if the component was disabled before */

}


/* [] END OF FILE */
