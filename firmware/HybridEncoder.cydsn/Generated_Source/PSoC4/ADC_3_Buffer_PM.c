/*******************************************************************************
* File Name: ADC_3_Buffer_PM.c
* Version 1.20
*
* Description:
*  This file provides the power management source code to the API for the
*  Opamp (Analog Buffer) component.
*
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC_3_Buffer.h"

#if(!ADC_3_Buffer_CHECK_DEEPSLEEP_SUPPORT)
    static ADC_3_Buffer_BACKUP_STRUCT ADC_3_Buffer_backup =
    {
        0u, /* enableState */
    };
#endif /* (ADC_3_Buffer_CHECK_DEEPSLEEP_SUPPORT) */


/*******************************************************************************
* Function Name: ADC_3_Buffer_SaveConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ADC_3_Buffer_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: ADC_3_Buffer_RestoreConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ADC_3_Buffer_RestoreConfig(void)
{
    
}


/*******************************************************************************
* Function Name: ADC_3_Buffer_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred API to prepare the component for sleep. The Sleep() API 
*  saves the current component state. Call the Sleep() function before calling the 
*  CySysPmDeepSleep() or the CySysPmHibernate() functions. The "Deep sleep operation" 
*  option has an influence on this function implementation.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  ADC_3_Buffer_backup: The structure field 'enableState' is modified
*  depending on the enable state of the block before entering the sleep mode.
*
*******************************************************************************/
void ADC_3_Buffer_Sleep(void)
{
#if(!ADC_3_Buffer_CHECK_DEEPSLEEP_SUPPORT)
    if(ADC_3_Buffer_CHECK_PWR_MODE_OFF)
    {
        ADC_3_Buffer_backup.enableState = 1u;
        ADC_3_Buffer_Stop();
    }
    else /* The component is disabled */
    {
        ADC_3_Buffer_backup.enableState = 0u;
    }
#endif /* (ADC_3_Buffer_CHECK_DEEPSLEEP_SUPPORT) */
}


/*******************************************************************************
* Function Name: ADC_3_Buffer_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred API to restore the component to the state when Sleep() 
*  is called. If the component has been enabled before the Sleep() function is 
*  called, the Wakeup() function will also re-enable the component.
*  The "Deep sleep operation" option has an influence on this function
*  implementation.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  ADC_3_Buffer_backup: The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void ADC_3_Buffer_Wakeup(void)
{
#if(!ADC_3_Buffer_CHECK_DEEPSLEEP_SUPPORT)
    if(0u != ADC_3_Buffer_backup.enableState)
    {
        /* Enable Opamp's operation */
        ADC_3_Buffer_Enable();
    } /* Do nothing if Opamp was disabled before */
#endif /* (ADC_3_Buffer_CHECK_DEEPSLEEP_SUPPORT) */
}


/* [] END OF FILE */
