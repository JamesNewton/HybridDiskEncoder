/***************************************************************************//**
* \file SPI_SPI.c
* \version 3.20
*
* \brief
*  This file provides the source code to the API for the SCB Component in
*  SPI mode.
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

#include "SPI_PVT.h"
#include "SPI_SPI_UART_PVT.h"

#if(SPI_SCB_MODE_UNCONFIG_CONST_CFG)

    /***************************************
    *  Configuration Structure Initialization
    ***************************************/

    const SPI_SPI_INIT_STRUCT SPI_configSpi =
    {
        SPI_SPI_MODE,
        SPI_SPI_SUB_MODE,
        SPI_SPI_CLOCK_MODE,
        SPI_SPI_OVS_FACTOR,
        SPI_SPI_MEDIAN_FILTER_ENABLE,
        SPI_SPI_LATE_MISO_SAMPLE_ENABLE,
        SPI_SPI_WAKE_ENABLE,
        SPI_SPI_RX_DATA_BITS_NUM,
        SPI_SPI_TX_DATA_BITS_NUM,
        SPI_SPI_BITS_ORDER,
        SPI_SPI_TRANSFER_SEPARATION,
        0u,
        NULL,
        0u,
        NULL,
        (uint32) SPI_SCB_IRQ_INTERNAL,
        SPI_SPI_INTR_RX_MASK,
        SPI_SPI_RX_TRIGGER_LEVEL,
        SPI_SPI_INTR_TX_MASK,
        SPI_SPI_TX_TRIGGER_LEVEL,
        (uint8) SPI_SPI_BYTE_MODE_ENABLE,
        (uint8) SPI_SPI_FREE_RUN_SCLK_ENABLE,
        (uint8) SPI_SPI_SS_POLARITY
    };


    /*******************************************************************************
    * Function Name: SPI_SpiInit
    ****************************************************************************//**
    *
    *  Configures the SPI for SPI operation.
    *
    *  This function is intended specifically to be used when the SPI 
    *  configuration is set to “Unconfigured SPI” in the customizer. 
    *  After initializing the SPI in SPI mode using this function, 
    *  the component can be enabled using the SPI_Start() or 
    * SPI_Enable() function.
    *  This function uses a pointer to a structure that provides the configuration 
    *  settings. This structure contains the same information that would otherwise 
    *  be provided by the customizer settings.
    *
    *  \param config: pointer to a structure that contains the following list of 
    *   fields. These fields match the selections available in the customizer. 
    *   Refer to the customizer for further description of the settings.
    *
    *******************************************************************************/
    void SPI_SpiInit(const SPI_SPI_INIT_STRUCT *config)
    {
        if(NULL == config)
        {
            CYASSERT(0u != 0u); /* Halt execution due to bad function parameter */
        }
        else
        {
            /* Configure pins */
            SPI_SetPins(SPI_SCB_MODE_SPI, config->mode, SPI_DUMMY_PARAM);

            /* Store internal configuration */
            SPI_scbMode       = (uint8) SPI_SCB_MODE_SPI;
            SPI_scbEnableWake = (uint8) config->enableWake;
            SPI_scbEnableIntr = (uint8) config->enableInterrupt;

            /* Set RX direction internal variables */
            SPI_rxBuffer      =         config->rxBuffer;
            SPI_rxDataBits    = (uint8) config->rxDataBits;
            SPI_rxBufferSize  = (uint8) config->rxBufferSize;

            /* Set TX direction internal variables */
            SPI_txBuffer      =         config->txBuffer;
            SPI_txDataBits    = (uint8) config->txDataBits;
            SPI_txBufferSize  = (uint8) config->txBufferSize;

            /* Configure SPI interface */
            SPI_CTRL_REG     = SPI_GET_CTRL_OVS(config->oversample)           |
                                            SPI_GET_CTRL_BYTE_MODE(config->enableByteMode) |
                                            SPI_GET_CTRL_EC_AM_MODE(config->enableWake)    |
                                            SPI_CTRL_SPI;

            SPI_SPI_CTRL_REG = SPI_GET_SPI_CTRL_CONTINUOUS    (config->transferSeperation)  |
                                            SPI_GET_SPI_CTRL_SELECT_PRECEDE(config->submode &
                                                                          SPI_SPI_MODE_TI_PRECEDES_MASK) |
                                            SPI_GET_SPI_CTRL_SCLK_MODE     (config->sclkMode)            |
                                            SPI_GET_SPI_CTRL_LATE_MISO_SAMPLE(config->enableLateSampling)|
                                            SPI_GET_SPI_CTRL_SCLK_CONTINUOUS(config->enableFreeRunSclk)  |
                                            SPI_GET_SPI_CTRL_SSEL_POLARITY (config->polaritySs)          |
                                            SPI_GET_SPI_CTRL_SUB_MODE      (config->submode)             |
                                            SPI_GET_SPI_CTRL_MASTER_MODE   (config->mode);

            /* Configure RX direction */
            SPI_RX_CTRL_REG     =  SPI_GET_RX_CTRL_DATA_WIDTH(config->rxDataBits)         |
                                                SPI_GET_RX_CTRL_BIT_ORDER (config->bitOrder)           |
                                                SPI_GET_RX_CTRL_MEDIAN    (config->enableMedianFilter) |
                                                SPI_SPI_RX_CTRL;

            SPI_RX_FIFO_CTRL_REG = SPI_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(config->rxTriggerLevel);

            /* Configure TX direction */
            SPI_TX_CTRL_REG      = SPI_GET_TX_CTRL_DATA_WIDTH(config->txDataBits) |
                                                SPI_GET_TX_CTRL_BIT_ORDER (config->bitOrder)   |
                                                SPI_SPI_TX_CTRL;

            SPI_TX_FIFO_CTRL_REG = SPI_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(config->txTriggerLevel);

            /* Configure interrupt with SPI handler but do not enable it */
            CyIntDisable    (SPI_ISR_NUMBER);
            CyIntSetPriority(SPI_ISR_NUMBER, SPI_ISR_PRIORITY);
            (void) CyIntSetVector(SPI_ISR_NUMBER, &SPI_SPI_UART_ISR);

            /* Configure interrupt sources */
            SPI_INTR_I2C_EC_MASK_REG = SPI_NO_INTR_SOURCES;
            SPI_INTR_SPI_EC_MASK_REG = SPI_NO_INTR_SOURCES;
            SPI_INTR_SLAVE_MASK_REG  = SPI_GET_SPI_INTR_SLAVE_MASK(config->rxInterruptMask);
            SPI_INTR_MASTER_MASK_REG = SPI_GET_SPI_INTR_MASTER_MASK(config->txInterruptMask);
            SPI_INTR_RX_MASK_REG     = SPI_GET_SPI_INTR_RX_MASK(config->rxInterruptMask);
            SPI_INTR_TX_MASK_REG     = SPI_GET_SPI_INTR_TX_MASK(config->txInterruptMask);
            
            /* Configure TX interrupt sources to restore. */
            SPI_IntrTxMask = LO16(SPI_INTR_TX_MASK_REG);

            /* Set active SS0 */
            SPI_SpiSetActiveSlaveSelect(SPI_SPI_SLAVE_SELECT0);

            /* Clear RX buffer indexes */
            SPI_rxBufferHead     = 0u;
            SPI_rxBufferTail     = 0u;
            SPI_rxBufferOverflow = 0u;

            /* Clear TX buffer indexes */
            SPI_txBufferHead = 0u;
            SPI_txBufferTail = 0u;
        }
    }

#else

    /*******************************************************************************
    * Function Name: SPI_SpiInit
    ****************************************************************************//**
    *
    *  Configures the SCB for the SPI operation.
    *
    *******************************************************************************/
    void SPI_SpiInit(void)
    {
        /* Configure SPI interface */
        SPI_CTRL_REG     = SPI_SPI_DEFAULT_CTRL;
        SPI_SPI_CTRL_REG = SPI_SPI_DEFAULT_SPI_CTRL;

        /* Configure TX and RX direction */
        SPI_RX_CTRL_REG      = SPI_SPI_DEFAULT_RX_CTRL;
        SPI_RX_FIFO_CTRL_REG = SPI_SPI_DEFAULT_RX_FIFO_CTRL;

        /* Configure TX and RX direction */
        SPI_TX_CTRL_REG      = SPI_SPI_DEFAULT_TX_CTRL;
        SPI_TX_FIFO_CTRL_REG = SPI_SPI_DEFAULT_TX_FIFO_CTRL;

        /* Configure interrupt with SPI handler but do not enable it */
    #if(SPI_SCB_IRQ_INTERNAL)
            CyIntDisable    (SPI_ISR_NUMBER);
            CyIntSetPriority(SPI_ISR_NUMBER, SPI_ISR_PRIORITY);
            (void) CyIntSetVector(SPI_ISR_NUMBER, &SPI_SPI_UART_ISR);
    #endif /* (SPI_SCB_IRQ_INTERNAL) */

        /* Configure interrupt sources */
        SPI_INTR_I2C_EC_MASK_REG = SPI_SPI_DEFAULT_INTR_I2C_EC_MASK;
        SPI_INTR_SPI_EC_MASK_REG = SPI_SPI_DEFAULT_INTR_SPI_EC_MASK;
        SPI_INTR_SLAVE_MASK_REG  = SPI_SPI_DEFAULT_INTR_SLAVE_MASK;
        SPI_INTR_MASTER_MASK_REG = SPI_SPI_DEFAULT_INTR_MASTER_MASK;
        SPI_INTR_RX_MASK_REG     = SPI_SPI_DEFAULT_INTR_RX_MASK;
        SPI_INTR_TX_MASK_REG     = SPI_SPI_DEFAULT_INTR_TX_MASK;

        /* Configure TX interrupt sources to restore. */
        SPI_IntrTxMask = LO16(SPI_INTR_TX_MASK_REG);
            
        /* Set active SS0 for master */
    #if (SPI_SPI_MASTER_CONST)
        SPI_SpiSetActiveSlaveSelect(SPI_SPI_SLAVE_SELECT0);
    #endif /* (SPI_SPI_MASTER_CONST) */

    #if(SPI_INTERNAL_RX_SW_BUFFER_CONST)
        SPI_rxBufferHead     = 0u;
        SPI_rxBufferTail     = 0u;
        SPI_rxBufferOverflow = 0u;
    #endif /* (SPI_INTERNAL_RX_SW_BUFFER_CONST) */

    #if(SPI_INTERNAL_TX_SW_BUFFER_CONST)
        SPI_txBufferHead = 0u;
        SPI_txBufferTail = 0u;
    #endif /* (SPI_INTERNAL_TX_SW_BUFFER_CONST) */
    }
#endif /* (SPI_SCB_MODE_UNCONFIG_CONST_CFG) */


/*******************************************************************************
* Function Name: SPI_SpiPostEnable
****************************************************************************//**
*
*  Restores HSIOM settings for the SPI master output pins (SCLK and/or SS0-SS3) 
*  to be controlled by the SCB SPI.
*
*******************************************************************************/
void SPI_SpiPostEnable(void)
{
#if(SPI_SCB_MODE_UNCONFIG_CONST_CFG)

    if (SPI_CHECK_SPI_MASTER)
    {
    #if (SPI_CTS_SCLK_PIN)
        /* Set SCB SPI to drive output pin */
        SPI_SET_HSIOM_SEL(SPI_CTS_SCLK_HSIOM_REG, SPI_CTS_SCLK_HSIOM_MASK,
                                       SPI_CTS_SCLK_HSIOM_POS, SPI_CTS_SCLK_HSIOM_SEL_SPI);
    #endif /* (SPI_CTS_SCLK_PIN) */

    #if (SPI_RTS_SS0_PIN)
        /* Set SCB SPI to drive output pin */
        SPI_SET_HSIOM_SEL(SPI_RTS_SS0_HSIOM_REG, SPI_RTS_SS0_HSIOM_MASK,
                                       SPI_RTS_SS0_HSIOM_POS, SPI_RTS_SS0_HSIOM_SEL_SPI);
    #endif /* (SPI_RTS_SS0_PIN) */

    #if (SPI_SS1_PIN)
        /* Set SCB SPI to drive output pin */
        SPI_SET_HSIOM_SEL(SPI_SS1_HSIOM_REG, SPI_SS1_HSIOM_MASK,
                                       SPI_SS1_HSIOM_POS, SPI_SS1_HSIOM_SEL_SPI);
    #endif /* (SPI_SS1_PIN) */

    #if (SPI_SS2_PIN)
        /* Set SCB SPI to drive output pin */
        SPI_SET_HSIOM_SEL(SPI_SS2_HSIOM_REG, SPI_SS2_HSIOM_MASK,
                                       SPI_SS2_HSIOM_POS, SPI_SS2_HSIOM_SEL_SPI);
    #endif /* (SPI_SS2_PIN) */

    #if (SPI_SS3_PIN)
        /* Set SCB SPI to drive output pin */
        SPI_SET_HSIOM_SEL(SPI_SS3_HSIOM_REG, SPI_SS3_HSIOM_MASK,
                                       SPI_SS3_HSIOM_POS, SPI_SS3_HSIOM_SEL_SPI);
    #endif /* (SPI_SS3_PIN) */
    }

#else

    #if (SPI_SPI_MASTER_SCLK_PIN)
        /* Set SCB SPI to drive output pin */
        SPI_SET_HSIOM_SEL(SPI_SCLK_M_HSIOM_REG, SPI_SCLK_M_HSIOM_MASK,
                                       SPI_SCLK_M_HSIOM_POS, SPI_SCLK_M_HSIOM_SEL_SPI);
    #endif /* (SPI_MISO_SDA_TX_PIN_PIN) */

    #if (SPI_SPI_MASTER_SS0_PIN)
        /* Set SCB SPI to drive output pin */
        SPI_SET_HSIOM_SEL(SPI_SS0_M_HSIOM_REG, SPI_SS0_M_HSIOM_MASK,
                                       SPI_SS0_M_HSIOM_POS, SPI_SS0_M_HSIOM_SEL_SPI);
    #endif /* (SPI_SPI_MASTER_SS0_PIN) */

    #if (SPI_SPI_MASTER_SS1_PIN)
        /* Set SCB SPI to drive output pin */
        SPI_SET_HSIOM_SEL(SPI_SS1_M_HSIOM_REG, SPI_SS1_M_HSIOM_MASK,
                                       SPI_SS1_M_HSIOM_POS, SPI_SS1_M_HSIOM_SEL_SPI);
    #endif /* (SPI_SPI_MASTER_SS1_PIN) */

    #if (SPI_SPI_MASTER_SS2_PIN)
        /* Set SCB SPI to drive output pin */
        SPI_SET_HSIOM_SEL(SPI_SS2_M_HSIOM_REG, SPI_SS2_M_HSIOM_MASK,
                                       SPI_SS2_M_HSIOM_POS, SPI_SS2_M_HSIOM_SEL_SPI);
    #endif /* (SPI_SPI_MASTER_SS2_PIN) */

    #if (SPI_SPI_MASTER_SS3_PIN)
        /* Set SCB SPI to drive output pin */
        SPI_SET_HSIOM_SEL(SPI_SS3_M_HSIOM_REG, SPI_SS3_M_HSIOM_MASK,
                                       SPI_SS3_M_HSIOM_POS, SPI_SS3_M_HSIOM_SEL_SPI);
    #endif /* (SPI_SPI_MASTER_SS3_PIN) */

#endif /* (SPI_SCB_MODE_UNCONFIG_CONST_CFG) */

    /* Restore TX interrupt sources. */
    SPI_SetTxInterruptMode(SPI_IntrTxMask);
}


/*******************************************************************************
* Function Name: SPI_SpiStop
****************************************************************************//**
*
*  Changes the HSIOM settings for the SPI master output pins 
*  (SCLK and/or SS0-SS3) to keep them inactive after the block is disabled. 
*  The output pins are controlled by the GPIO data register.
*
*******************************************************************************/
void SPI_SpiStop(void)
{
#if(SPI_SCB_MODE_UNCONFIG_CONST_CFG)

    if (SPI_CHECK_SPI_MASTER)
    {
    #if (SPI_CTS_SCLK_PIN)
        /* Set output pin state after block is disabled */
        SPI_uart_cts_spi_sclk_Write(SPI_GET_SPI_SCLK_INACTIVE);

        /* Set GPIO to drive output pin */
        SPI_SET_HSIOM_SEL(SPI_CTS_SCLK_HSIOM_REG, SPI_CTS_SCLK_HSIOM_MASK,
                                       SPI_CTS_SCLK_HSIOM_POS, SPI_CTS_SCLK_HSIOM_SEL_GPIO);
    #endif /* (SPI_uart_cts_spi_sclk_PIN) */

    #if (SPI_RTS_SS0_PIN)
        /* Set output pin state after block is disabled */
        SPI_uart_rts_spi_ss0_Write(SPI_GET_SPI_SS0_INACTIVE);

        /* Set GPIO to drive output pin */
        SPI_SET_HSIOM_SEL(SPI_RTS_SS0_HSIOM_REG, SPI_RTS_SS0_HSIOM_MASK,
                                       SPI_RTS_SS0_HSIOM_POS, SPI_RTS_SS0_HSIOM_SEL_GPIO);
    #endif /* (SPI_uart_rts_spi_ss0_PIN) */

    #if (SPI_SS1_PIN)
        /* Set output pin state after block is disabled */
        SPI_spi_ss1_Write(SPI_GET_SPI_SS1_INACTIVE);

        /* Set GPIO to drive output pin */
        SPI_SET_HSIOM_SEL(SPI_SS1_HSIOM_REG, SPI_SS1_HSIOM_MASK,
                                       SPI_SS1_HSIOM_POS, SPI_SS1_HSIOM_SEL_GPIO);
    #endif /* (SPI_SS1_PIN) */

    #if (SPI_SS2_PIN)
        /* Set output pin state after block is disabled */
        SPI_spi_ss2_Write(SPI_GET_SPI_SS2_INACTIVE);

        /* Set GPIO to drive output pin */
        SPI_SET_HSIOM_SEL(SPI_SS2_HSIOM_REG, SPI_SS2_HSIOM_MASK,
                                       SPI_SS2_HSIOM_POS, SPI_SS2_HSIOM_SEL_GPIO);
    #endif /* (SPI_SS2_PIN) */

    #if (SPI_SS3_PIN)
        /* Set output pin state after block is disabled */
        SPI_spi_ss3_Write(SPI_GET_SPI_SS3_INACTIVE);

        /* Set GPIO to drive output pin */
        SPI_SET_HSIOM_SEL(SPI_SS3_HSIOM_REG, SPI_SS3_HSIOM_MASK,
                                       SPI_SS3_HSIOM_POS, SPI_SS3_HSIOM_SEL_GPIO);
    #endif /* (SPI_SS3_PIN) */
    
        /* Store TX interrupt sources (exclude level triggered) for master. */
        SPI_IntrTxMask = LO16(SPI_GetTxInterruptMode() & SPI_INTR_SPIM_TX_RESTORE);
    }
    else
    {
        /* Store TX interrupt sources (exclude level triggered) for slave. */
        SPI_IntrTxMask = LO16(SPI_GetTxInterruptMode() & SPI_INTR_SPIS_TX_RESTORE);
    }

#else

#if (SPI_SPI_MASTER_SCLK_PIN)
    /* Set output pin state after block is disabled */
    SPI_sclk_m_Write(SPI_GET_SPI_SCLK_INACTIVE);

    /* Set GPIO to drive output pin */
    SPI_SET_HSIOM_SEL(SPI_SCLK_M_HSIOM_REG, SPI_SCLK_M_HSIOM_MASK,
                                   SPI_SCLK_M_HSIOM_POS, SPI_SCLK_M_HSIOM_SEL_GPIO);
#endif /* (SPI_MISO_SDA_TX_PIN_PIN) */

#if (SPI_SPI_MASTER_SS0_PIN)
    /* Set output pin state after block is disabled */
    SPI_ss0_m_Write(SPI_GET_SPI_SS0_INACTIVE);

    /* Set GPIO to drive output pin */
    SPI_SET_HSIOM_SEL(SPI_SS0_M_HSIOM_REG, SPI_SS0_M_HSIOM_MASK,
                                   SPI_SS0_M_HSIOM_POS, SPI_SS0_M_HSIOM_SEL_GPIO);
#endif /* (SPI_SPI_MASTER_SS0_PIN) */

#if (SPI_SPI_MASTER_SS1_PIN)
    /* Set output pin state after block is disabled */
    SPI_ss1_m_Write(SPI_GET_SPI_SS1_INACTIVE);

    /* Set GPIO to drive output pin */
    SPI_SET_HSIOM_SEL(SPI_SS1_M_HSIOM_REG, SPI_SS1_M_HSIOM_MASK,
                                   SPI_SS1_M_HSIOM_POS, SPI_SS1_M_HSIOM_SEL_GPIO);
#endif /* (SPI_SPI_MASTER_SS1_PIN) */

#if (SPI_SPI_MASTER_SS2_PIN)
    /* Set output pin state after block is disabled */
    SPI_ss2_m_Write(SPI_GET_SPI_SS2_INACTIVE);

    /* Set GPIO to drive output pin */
    SPI_SET_HSIOM_SEL(SPI_SS2_M_HSIOM_REG, SPI_SS2_M_HSIOM_MASK,
                                   SPI_SS2_M_HSIOM_POS, SPI_SS2_M_HSIOM_SEL_GPIO);
#endif /* (SPI_SPI_MASTER_SS2_PIN) */

#if (SPI_SPI_MASTER_SS3_PIN)
    /* Set output pin state after block is disabled */
    SPI_ss3_m_Write(SPI_GET_SPI_SS3_INACTIVE);

    /* Set GPIO to drive output pin */
    SPI_SET_HSIOM_SEL(SPI_SS3_M_HSIOM_REG, SPI_SS3_M_HSIOM_MASK,
                                   SPI_SS3_M_HSIOM_POS, SPI_SS3_M_HSIOM_SEL_GPIO);
#endif /* (SPI_SPI_MASTER_SS3_PIN) */

    #if (SPI_SPI_MASTER_CONST)
        /* Store TX interrupt sources (exclude level triggered). */
        SPI_IntrTxMask = LO16(SPI_GetTxInterruptMode() & SPI_INTR_SPIM_TX_RESTORE);
    #else
        /* Store TX interrupt sources (exclude level triggered). */
        SPI_IntrTxMask = LO16(SPI_GetTxInterruptMode() & SPI_INTR_SPIS_TX_RESTORE);
    #endif /* (SPI_SPI_MASTER_CONST) */

#endif /* (SPI_SCB_MODE_UNCONFIG_CONST_CFG) */
}


#if (SPI_SPI_MASTER_CONST)
    /*******************************************************************************
    * Function Name: SPI_SetActiveSlaveSelect
    ****************************************************************************//**
    *
    *  Selects one of the four slave select lines to be active during the transfer.
    *  After initialization the active slave select line is 0.
    *  The component should be in one of the following states to change the active
    *  slave select signal source correctly:
    *   - The component is disabled.
    *   - The component has completed transfer (TX FIFO is empty and the
    *     SCB_INTR_MASTER_SPI_DONE status is set).
    *
    *  This function does not check that these conditions are met.
    *  This function is only applicable to SPI Master mode of operation.
    *
    *  \param slaveSelect: slave select line which will be active while the following
    *   transfer.
    *   - SPI_SPI_SLAVE_SELECT0 - Slave select 0.
    *   - SPI_SPI_SLAVE_SELECT1 - Slave select 1.
    *   - SPI_SPI_SLAVE_SELECT2 - Slave select 2.
    *   - SPI_SPI_SLAVE_SELECT3 - Slave select 3.
    *
    *******************************************************************************/
    void SPI_SpiSetActiveSlaveSelect(uint32 slaveSelect)
    {
        uint32 spiCtrl;

        spiCtrl = SPI_SPI_CTRL_REG;

        spiCtrl &= (uint32) ~SPI_SPI_CTRL_SLAVE_SELECT_MASK;
        spiCtrl |= (uint32)  SPI_GET_SPI_CTRL_SS(slaveSelect);

        SPI_SPI_CTRL_REG = spiCtrl;
    }
#endif /* (SPI_SPI_MASTER_CONST) */


#if !(SPI_CY_SCBIP_V0 || SPI_CY_SCBIP_V1)
    /*******************************************************************************
    * Function Name: SPI_SpiSetSlaveSelectPolarity
    ****************************************************************************//**
    *
    *  Sets active polarity for slave select line.
    *  The component should be in one of the following states to change the active
    *  slave select signal source correctly:
    *   - The component is disabled.
    *   - The component has completed transfer.
    *  
    *  This function does not check that these conditions are met.
    *
    *  \param slaveSelect: slave select line to change active polarity.
    *   - SPI_SPI_SLAVE_SELECT0 - Slave select 0.
    *   - SPI_SPI_SLAVE_SELECT1 - Slave select 1.
    *   - SPI_SPI_SLAVE_SELECT2 - Slave select 2.
    *   - SPI_SPI_SLAVE_SELECT3 - Slave select 3.
    *
    *  \param polarity: active polarity of slave select line.
    *   - SPI_SPI_SS_ACTIVE_LOW  - Slave select is active low.
    *   - SPI_SPI_SS_ACTIVE_HIGH - Slave select is active high.
    *
    *******************************************************************************/
    void SPI_SpiSetSlaveSelectPolarity(uint32 slaveSelect, uint32 polarity)
    {
        uint32 ssPolarity;

        /* Get position of the polarity bit associated with slave select line */
        ssPolarity = SPI_GET_SPI_CTRL_SSEL_POLARITY((uint32) 1u << slaveSelect);

        if (0u != polarity)
        {
            SPI_SPI_CTRL_REG |= (uint32)  ssPolarity;
        }
        else
        {
            SPI_SPI_CTRL_REG &= (uint32) ~ssPolarity;
        }
    }
#endif /* !(SPI_CY_SCBIP_V0 || SPI_CY_SCBIP_V1) */


#if(SPI_SPI_WAKE_ENABLE_CONST)
    /*******************************************************************************
    * Function Name: SPI_SpiSaveConfig
    ****************************************************************************//**
    *
    *  Clears INTR_SPI_EC.WAKE_UP and enables it. This interrupt
    *  source triggers when the master assigns the SS line and wakes up the device.
    *
    *******************************************************************************/
    void SPI_SpiSaveConfig(void)
    {
        /* Clear and enable SPI wakeup interrupt source */
        SPI_ClearSpiExtClkInterruptSource(SPI_INTR_SPI_EC_WAKE_UP);
        SPI_SetSpiExtClkInterruptMode(SPI_INTR_SPI_EC_WAKE_UP);
    }


    /*******************************************************************************
    * Function Name: SPI_SpiRestoreConfig
    ****************************************************************************//**
    *
    *  Disables the INTR_SPI_EC.WAKE_UP interrupt source. After wakeup
    *  slave does not drive the MISO line and the master receives 0xFF.
    *
    *******************************************************************************/
    void SPI_SpiRestoreConfig(void)
    {
        /* Disable SPI wakeup interrupt source */
        SPI_SetSpiExtClkInterruptMode(SPI_NO_INTR_SOURCES);
    }
#endif /* (SPI_SPI_WAKE_ENABLE_CONST) */


/* [] END OF FILE */
