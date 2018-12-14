/***************************************************************************//**
* \file I2C_I2C.c
* \version 3.20
*
* \brief
*  This file provides the source code to the API for the SCB Component in
*  I2C mode.
*
* Note:
*
*******************************************************************************
* \copyright
* Copyright 2013-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "I2C_PVT.h"
#include "I2C_I2C_PVT.h"


/***************************************
*      I2C Private Vars
***************************************/

volatile uint8 I2C_state;  /* Current state of I2C FSM */

#if(I2C_SCB_MODE_UNCONFIG_CONST_CFG)

    /***************************************
    *  Configuration Structure Initialization
    ***************************************/

    /* Constant configuration of I2C */
    const I2C_I2C_INIT_STRUCT I2C_configI2C =
    {
        I2C_I2C_MODE,
        I2C_I2C_OVS_FACTOR_LOW,
        I2C_I2C_OVS_FACTOR_HIGH,
        I2C_I2C_MEDIAN_FILTER_ENABLE,
        I2C_I2C_SLAVE_ADDRESS,
        I2C_I2C_SLAVE_ADDRESS_MASK,
        I2C_I2C_ACCEPT_ADDRESS,
        I2C_I2C_WAKE_ENABLE,
        I2C_I2C_BYTE_MODE_ENABLE,
        I2C_I2C_DATA_RATE,
        I2C_I2C_ACCEPT_GENERAL_CALL,
    };

    /*******************************************************************************
    * Function Name: I2C_I2CInit
    ****************************************************************************//**
    *
    *
    *  Configures the I2C for I2C operation.
    *
    *  This function is intended specifically to be used when the I2C 
    *  configuration is set to “Unconfigured I2C” in the customizer. 
    *  After initializing the I2C in I2C mode using this function, 
    *  the component can be enabled using the I2C_Start() or 
    * I2C_Enable() function.
    *  This function uses a pointer to a structure that provides the configuration 
    *  settings. This structure contains the same information that would otherwise 
    *  be provided by the customizer settings.
    *
    *  \param config: pointer to a structure that contains the following list of 
    *   fields. These fields match the selections available in the customizer. 
    *   Refer to the customizer for further description of the settings.
    *
    *******************************************************************************/
    void I2C_I2CInit(const I2C_I2C_INIT_STRUCT *config)
    {
        uint32 medianFilter;
        uint32 locEnableWake;

        if(NULL == config)
        {
            CYASSERT(0u != 0u); /* Halt execution due to bad function parameter */
        }
        else
        {
            /* Configure pins */
            I2C_SetPins(I2C_SCB_MODE_I2C, I2C_DUMMY_PARAM,
                                     I2C_DUMMY_PARAM);

            /* Store internal configuration */
            I2C_scbMode       = (uint8) I2C_SCB_MODE_I2C;
            I2C_scbEnableWake = (uint8) config->enableWake;
            I2C_scbEnableIntr = (uint8) I2C_SCB_IRQ_INTERNAL;

            I2C_mode          = (uint8) config->mode;
            I2C_acceptAddr    = (uint8) config->acceptAddr;

        #if (I2C_CY_SCBIP_V0)
            /* Adjust SDA filter settings. Ticket ID#150521 */
            I2C_SET_I2C_CFG_SDA_FILT_TRIM(I2C_EC_AM_I2C_CFG_SDA_FILT_TRIM);
        #endif /* (I2C_CY_SCBIP_V0) */

            /* Adjust AF and DF filter settings. Ticket ID#176179 */
            if (((I2C_I2C_MODE_SLAVE != config->mode) &&
                 (config->dataRate <= I2C_I2C_DATA_RATE_FS_MODE_MAX)) ||
                 (I2C_I2C_MODE_SLAVE == config->mode))
            {
                /* AF = 1, DF = 0 */
                I2C_I2C_CFG_ANALOG_FITER_ENABLE;
                medianFilter = I2C_DIGITAL_FILTER_DISABLE;
            }
            else
            {
                /* AF = 0, DF = 1 */
                I2C_I2C_CFG_ANALOG_FITER_DISABLE;
                medianFilter = I2C_DIGITAL_FILTER_ENABLE;
            }

        #if (!I2C_CY_SCBIP_V0)
            locEnableWake = (I2C_I2C_MULTI_MASTER_SLAVE) ? (0u) : (config->enableWake);
        #else
            locEnableWake = config->enableWake;
        #endif /* (!I2C_CY_SCBIP_V0) */

            /* Configure I2C interface */
            I2C_CTRL_REG     = I2C_GET_CTRL_BYTE_MODE  (config->enableByteMode) |
                                            I2C_GET_CTRL_ADDR_ACCEPT(config->acceptAddr)     |
                                            I2C_GET_CTRL_EC_AM_MODE (locEnableWake);

            I2C_I2C_CTRL_REG = I2C_GET_I2C_CTRL_HIGH_PHASE_OVS(config->oversampleHigh) |
                    I2C_GET_I2C_CTRL_LOW_PHASE_OVS (config->oversampleLow)                          |
                    I2C_GET_I2C_CTRL_S_GENERAL_IGNORE((uint32)(0u == config->acceptGeneralAddr))    |
                    I2C_GET_I2C_CTRL_SL_MSTR_MODE  (config->mode);

            /* Configure RX direction */
            I2C_RX_CTRL_REG      = I2C_GET_RX_CTRL_MEDIAN(medianFilter) |
                                                I2C_I2C_RX_CTRL;
            I2C_RX_FIFO_CTRL_REG = I2C_CLEAR_REG;

            /* Set default address and mask */
            I2C_RX_MATCH_REG    = ((I2C_I2C_SLAVE) ?
                                                (I2C_GET_I2C_8BIT_ADDRESS(config->slaveAddr) |
                                                 I2C_GET_RX_MATCH_MASK(config->slaveAddrMask)) :
                                                (I2C_CLEAR_REG));


            /* Configure TX direction */
            I2C_TX_CTRL_REG      = I2C_I2C_TX_CTRL;
            I2C_TX_FIFO_CTRL_REG = I2C_CLEAR_REG;

            /* Configure interrupt with I2C handler but do not enable it */
            CyIntDisable    (I2C_ISR_NUMBER);
            CyIntSetPriority(I2C_ISR_NUMBER, I2C_ISR_PRIORITY);
            (void) CyIntSetVector(I2C_ISR_NUMBER, &I2C_I2C_ISR);

            /* Configure interrupt sources */
        #if(!I2C_CY_SCBIP_V1)
            I2C_INTR_SPI_EC_MASK_REG = I2C_NO_INTR_SOURCES;
        #endif /* (!I2C_CY_SCBIP_V1) */

            I2C_INTR_I2C_EC_MASK_REG = I2C_NO_INTR_SOURCES;
            I2C_INTR_RX_MASK_REG     = I2C_NO_INTR_SOURCES;
            I2C_INTR_TX_MASK_REG     = I2C_NO_INTR_SOURCES;

            I2C_INTR_SLAVE_MASK_REG  = ((I2C_I2C_SLAVE) ?
                            (I2C_GET_INTR_SLAVE_I2C_GENERAL(config->acceptGeneralAddr) |
                             I2C_I2C_INTR_SLAVE_MASK) : (I2C_CLEAR_REG));

            I2C_INTR_MASTER_MASK_REG = ((I2C_I2C_MASTER) ?
                                                     (I2C_I2C_INTR_MASTER_MASK) :
                                                     (I2C_CLEAR_REG));

            /* Configure global variables */
            I2C_state = I2C_I2C_FSM_IDLE;

            /* Internal slave variables */
            I2C_slStatus        = 0u;
            I2C_slRdBufIndex    = 0u;
            I2C_slWrBufIndex    = 0u;
            I2C_slOverFlowCount = 0u;

            /* Internal master variables */
            I2C_mstrStatus     = 0u;
            I2C_mstrRdBufIndex = 0u;
            I2C_mstrWrBufIndex = 0u;
        }
    }

#else

    /*******************************************************************************
    * Function Name: I2C_I2CInit
    ****************************************************************************//**
    *
    *  Configures the SCB for the I2C operation.
    *
    *******************************************************************************/
    void I2C_I2CInit(void)
    {
    #if(I2C_CY_SCBIP_V0)
        /* Adjust SDA filter settings. Ticket ID#150521 */
        I2C_SET_I2C_CFG_SDA_FILT_TRIM(I2C_EC_AM_I2C_CFG_SDA_FILT_TRIM);
    #endif /* (I2C_CY_SCBIP_V0) */

        /* Adjust AF and DF filter settings. Ticket ID#176179 */
        I2C_I2C_CFG_ANALOG_FITER_ENABLE_ADJ;

        /* Configure I2C interface */
        I2C_CTRL_REG     = I2C_I2C_DEFAULT_CTRL;
        I2C_I2C_CTRL_REG = I2C_I2C_DEFAULT_I2C_CTRL;

        /* Configure RX direction */
        I2C_RX_CTRL_REG      = I2C_I2C_DEFAULT_RX_CTRL;
        I2C_RX_FIFO_CTRL_REG = I2C_I2C_DEFAULT_RX_FIFO_CTRL;

        /* Set default address and mask */
        I2C_RX_MATCH_REG     = I2C_I2C_DEFAULT_RX_MATCH;

        /* Configure TX direction */
        I2C_TX_CTRL_REG      = I2C_I2C_DEFAULT_TX_CTRL;
        I2C_TX_FIFO_CTRL_REG = I2C_I2C_DEFAULT_TX_FIFO_CTRL;

        /* Configure interrupt with I2C handler but do not enable it */
        CyIntDisable    (I2C_ISR_NUMBER);
        CyIntSetPriority(I2C_ISR_NUMBER, I2C_ISR_PRIORITY);
    #if(!I2C_I2C_EXTERN_INTR_HANDLER)
        (void) CyIntSetVector(I2C_ISR_NUMBER, &I2C_I2C_ISR);
    #endif /* (I2C_I2C_EXTERN_INTR_HANDLER) */

        /* Configure interrupt sources */
    #if(!I2C_CY_SCBIP_V1)
        I2C_INTR_SPI_EC_MASK_REG = I2C_I2C_DEFAULT_INTR_SPI_EC_MASK;
    #endif /* (!I2C_CY_SCBIP_V1) */

        I2C_INTR_I2C_EC_MASK_REG = I2C_I2C_DEFAULT_INTR_I2C_EC_MASK;
        I2C_INTR_SLAVE_MASK_REG  = I2C_I2C_DEFAULT_INTR_SLAVE_MASK;
        I2C_INTR_MASTER_MASK_REG = I2C_I2C_DEFAULT_INTR_MASTER_MASK;
        I2C_INTR_RX_MASK_REG     = I2C_I2C_DEFAULT_INTR_RX_MASK;
        I2C_INTR_TX_MASK_REG     = I2C_I2C_DEFAULT_INTR_TX_MASK;

        /* Configure global variables */
        I2C_state = I2C_I2C_FSM_IDLE;

    #if(I2C_I2C_SLAVE)
        /* Internal slave variable */
        I2C_slStatus        = 0u;
        I2C_slRdBufIndex    = 0u;
        I2C_slWrBufIndex    = 0u;
        I2C_slOverFlowCount = 0u;
    #endif /* (I2C_I2C_SLAVE) */

    #if(I2C_I2C_MASTER)
    /* Internal master variable */
        I2C_mstrStatus     = 0u;
        I2C_mstrRdBufIndex = 0u;
        I2C_mstrWrBufIndex = 0u;
    #endif /* (I2C_I2C_MASTER) */
    }
#endif /* (I2C_SCB_MODE_UNCONFIG_CONST_CFG) */


/*******************************************************************************
* Function Name: I2C_I2CStop
****************************************************************************//**
*
*  Resets the I2C FSM into the default state.
*
*******************************************************************************/
void I2C_I2CStop(void)
{
    I2C_state = I2C_I2C_FSM_IDLE;
}


#if(I2C_I2C_WAKE_ENABLE_CONST)
    /*******************************************************************************
    * Function Name: I2C_I2CSaveConfig
    ****************************************************************************//**
    *
    *  Enables I2C_INTR_I2C_EC_WAKE_UP interrupt source. This interrupt
    *  triggers on address match and wakes up device.
    *
    *******************************************************************************/
    void I2C_I2CSaveConfig(void)
    {
    #if (!I2C_CY_SCBIP_V0)
        #if (I2C_I2C_MULTI_MASTER_SLAVE_CONST && I2C_I2C_WAKE_ENABLE_CONST)
            /* Enable externally clocked address match if it was not enabled before.
            * This applicable only for Multi-Master-Slave. Ticket ID#192742 */
            if (0u == (I2C_CTRL_REG & I2C_CTRL_EC_AM_MODE))
            {
                /* Enable external address match logic */
                I2C_Stop();
                I2C_CTRL_REG |= I2C_CTRL_EC_AM_MODE;
                I2C_Enable();
            }
        #endif /* (I2C_I2C_MULTI_MASTER_SLAVE_CONST) */

        #if (I2C_SCB_CLK_INTERNAL)
            /* Disable clock to internal address match logic. Ticket ID#187931 */
            I2C_SCBCLK_Stop();
        #endif /* (I2C_SCB_CLK_INTERNAL) */
    #endif /* (!I2C_CY_SCBIP_V0) */

        I2C_SetI2CExtClkInterruptMode(I2C_INTR_I2C_EC_WAKE_UP);
    }


    /*******************************************************************************
    * Function Name: I2C_I2CRestoreConfig
    ****************************************************************************//**
    *
    *  Disables I2C_INTR_I2C_EC_WAKE_UP interrupt source. This interrupt
    *  triggers on address match and wakes up device.
    *
    *******************************************************************************/
    void I2C_I2CRestoreConfig(void)
    {
        /* Disable wakeup interrupt on address match */
        I2C_SetI2CExtClkInterruptMode(I2C_NO_INTR_SOURCES);

    #if (!I2C_CY_SCBIP_V0)
        #if (I2C_SCB_CLK_INTERNAL)
            /* Enable clock to internal address match logic. Ticket ID#187931 */
            I2C_SCBCLK_Start();
        #endif /* (I2C_SCB_CLK_INTERNAL) */
    #endif /* (!I2C_CY_SCBIP_V0) */
    }
#endif /* (I2C_I2C_WAKE_ENABLE_CONST) */


/* [] END OF FILE */
