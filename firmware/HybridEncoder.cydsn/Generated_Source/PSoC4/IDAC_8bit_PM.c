/*******************************************************************************
* File Name: IDAC_8bit_PM.c
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

#include "IDAC_8bit.h"


static IDAC_8bit_BACKUP_STRUCT IDAC_8bit_backup;


/*******************************************************************************
* Function Name: IDAC_8bit_SaveConfig
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
void IDAC_8bit_SaveConfig(void)
{
    /* All registers are retention - nothing to save */
}


/*******************************************************************************
* Function Name: IDAC_8bit_Sleep
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
void IDAC_8bit_Sleep(void)
{
        if(0u != (IDAC_8bit_IDAC_CONTROL_REG & ((uint32)IDAC_8bit_IDAC_MODE_MASK <<
        IDAC_8bit_IDAC_MODE_POSITION)))
        {
            IDAC_8bit_backup.enableState = 1u;
        }
        else
        {
            IDAC_8bit_backup.enableState = 0u;
        }

    IDAC_8bit_Stop();
    IDAC_8bit_SaveConfig();
}


/*******************************************************************************
* Function Name: IDAC_8bit_RestoreConfig
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
void IDAC_8bit_RestoreConfig(void)
{
    /* All registers are retention - nothing to save */
}


/*******************************************************************************
* Function Name: IDAC_8bit_Wakeup
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
void IDAC_8bit_Wakeup(void)
{
    /* Restore IDAC register settings */
    IDAC_8bit_RestoreConfig();
    if(IDAC_8bit_backup.enableState == 1u)
    {
        /* Enable operation */
        IDAC_8bit_Enable();
    } /* Do nothing if the component was disabled before */

}


/* [] END OF FILE */
