/***************************************************************************//**
* \file .h
* \version 3.20
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PVT_SPI_H)
#define CY_SCB_PVT_SPI_H

#include "SPI.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define SPI_SetI2CExtClkInterruptMode(interruptMask) SPI_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define SPI_ClearI2CExtClkInterruptSource(interruptMask) SPI_CLEAR_INTR_I2C_EC(interruptMask)
#define SPI_GetI2CExtClkInterruptSource()                (SPI_INTR_I2C_EC_REG)
#define SPI_GetI2CExtClkInterruptMode()                  (SPI_INTR_I2C_EC_MASK_REG)
#define SPI_GetI2CExtClkInterruptSourceMasked()          (SPI_INTR_I2C_EC_MASKED_REG)

#if (!SPI_CY_SCBIP_V1)
    /* APIs to service INTR_SPI_EC register */
    #define SPI_SetSpiExtClkInterruptMode(interruptMask) \
                                                                SPI_WRITE_INTR_SPI_EC_MASK(interruptMask)
    #define SPI_ClearSpiExtClkInterruptSource(interruptMask) \
                                                                SPI_CLEAR_INTR_SPI_EC(interruptMask)
    #define SPI_GetExtSpiClkInterruptSource()                 (SPI_INTR_SPI_EC_REG)
    #define SPI_GetExtSpiClkInterruptMode()                   (SPI_INTR_SPI_EC_MASK_REG)
    #define SPI_GetExtSpiClkInterruptSourceMasked()           (SPI_INTR_SPI_EC_MASKED_REG)
#endif /* (!SPI_CY_SCBIP_V1) */

#if(SPI_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void SPI_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask);
#endif /* (SPI_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if (SPI_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_SPI_CUSTOM_INTR_HANDLER)
    extern cyisraddress SPI_customIntrHandler;
#endif /* !defined (CY_REMOVE_SPI_CUSTOM_INTR_HANDLER) */
#endif /* (SPI_SCB_IRQ_INTERNAL) */

extern SPI_BACKUP_STRUCT SPI_backup;

#if(SPI_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    extern uint8 SPI_scbMode;
    extern uint8 SPI_scbEnableWake;
    extern uint8 SPI_scbEnableIntr;

    /* I2C configuration variables */
    extern uint8 SPI_mode;
    extern uint8 SPI_acceptAddr;

    /* SPI/UART configuration variables */
    extern volatile uint8 * SPI_rxBuffer;
    extern uint8   SPI_rxDataBits;
    extern uint32  SPI_rxBufferSize;

    extern volatile uint8 * SPI_txBuffer;
    extern uint8   SPI_txDataBits;
    extern uint32  SPI_txBufferSize;

    /* EZI2C configuration variables */
    extern uint8 SPI_numberOfAddr;
    extern uint8 SPI_subAddrSize;
#endif /* (SPI_SCB_MODE_UNCONFIG_CONST_CFG) */

#if (! (SPI_SCB_MODE_I2C_CONST_CFG || \
        SPI_SCB_MODE_EZI2C_CONST_CFG))
    extern uint16 SPI_IntrTxMask;
#endif /* (! (SPI_SCB_MODE_I2C_CONST_CFG || \
              SPI_SCB_MODE_EZI2C_CONST_CFG)) */


/***************************************
*        Conditional Macro
****************************************/

#if(SPI_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Defines run time operation mode */
    #define SPI_SCB_MODE_I2C_RUNTM_CFG     (SPI_SCB_MODE_I2C      == SPI_scbMode)
    #define SPI_SCB_MODE_SPI_RUNTM_CFG     (SPI_SCB_MODE_SPI      == SPI_scbMode)
    #define SPI_SCB_MODE_UART_RUNTM_CFG    (SPI_SCB_MODE_UART     == SPI_scbMode)
    #define SPI_SCB_MODE_EZI2C_RUNTM_CFG   (SPI_SCB_MODE_EZI2C    == SPI_scbMode)
    #define SPI_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (SPI_SCB_MODE_UNCONFIG == SPI_scbMode)

    /* Defines wakeup enable */
    #define SPI_SCB_WAKE_ENABLE_CHECK       (0u != SPI_scbEnableWake)
#endif /* (SPI_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Defines maximum number of SCB pins */
#if (!SPI_CY_SCBIP_V1)
    #define SPI_SCB_PINS_NUMBER    (7u)
#else
    #define SPI_SCB_PINS_NUMBER    (2u)
#endif /* (!SPI_CY_SCBIP_V1) */

#endif /* (CY_SCB_PVT_SPI_H) */


/* [] END OF FILE */
