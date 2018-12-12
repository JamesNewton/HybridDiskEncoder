/*******************************************************************************
* File Name: Wakeup_Pin.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Wakeup_Pin.h"

static Wakeup_Pin_BACKUP_STRUCT  Wakeup_Pin_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Wakeup_Pin_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet Wakeup_Pin_SUT.c usage_Wakeup_Pin_Sleep_Wakeup
*******************************************************************************/
void Wakeup_Pin_Sleep(void)
{
    #if defined(Wakeup_Pin__PC)
        Wakeup_Pin_backup.pcState = Wakeup_Pin_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Wakeup_Pin_backup.usbState = Wakeup_Pin_CR1_REG;
            Wakeup_Pin_USB_POWER_REG |= Wakeup_Pin_USBIO_ENTER_SLEEP;
            Wakeup_Pin_CR1_REG &= Wakeup_Pin_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Wakeup_Pin__SIO)
        Wakeup_Pin_backup.sioState = Wakeup_Pin_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Wakeup_Pin_SIO_REG &= (uint32)(~Wakeup_Pin_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Wakeup_Pin_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to Wakeup_Pin_Sleep() for an example usage.
*******************************************************************************/
void Wakeup_Pin_Wakeup(void)
{
    #if defined(Wakeup_Pin__PC)
        Wakeup_Pin_PC = Wakeup_Pin_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Wakeup_Pin_USB_POWER_REG &= Wakeup_Pin_USBIO_EXIT_SLEEP_PH1;
            Wakeup_Pin_CR1_REG = Wakeup_Pin_backup.usbState;
            Wakeup_Pin_USB_POWER_REG &= Wakeup_Pin_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Wakeup_Pin__SIO)
        Wakeup_Pin_SIO_REG = Wakeup_Pin_backup.sioState;
    #endif
}


/* [] END OF FILE */
