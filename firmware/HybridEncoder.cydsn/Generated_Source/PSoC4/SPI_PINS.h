/***************************************************************************//**
* \file SPI_PINS.h
* \version 3.20
*
* \brief
*  This file provides constants and parameter values for the pin components
*  buried into SCB Component.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PINS_SPI_H)
#define CY_SCB_PINS_SPI_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* Unconfigured pins */
#define SPI_REMOVE_RX_WAKE_SCL_MOSI_PIN  (1u)
#define SPI_REMOVE_RX_SCL_MOSI_PIN      (1u)
#define SPI_REMOVE_TX_SDA_MISO_PIN      (1u)
#define SPI_REMOVE_CTS_SCLK_PIN      (1u)
#define SPI_REMOVE_RTS_SS0_PIN      (1u)
#define SPI_REMOVE_SS1_PIN                 (1u)
#define SPI_REMOVE_SS2_PIN                 (1u)
#define SPI_REMOVE_SS3_PIN                 (1u)

/* Mode defined pins */
#define SPI_REMOVE_I2C_PINS                (1u)
#define SPI_REMOVE_SPI_MASTER_PINS         (1u)
#define SPI_REMOVE_SPI_MASTER_SCLK_PIN     (1u)
#define SPI_REMOVE_SPI_MASTER_MOSI_PIN     (1u)
#define SPI_REMOVE_SPI_MASTER_MISO_PIN     (1u)
#define SPI_REMOVE_SPI_MASTER_SS0_PIN      (1u)
#define SPI_REMOVE_SPI_MASTER_SS1_PIN      (1u)
#define SPI_REMOVE_SPI_MASTER_SS2_PIN      (1u)
#define SPI_REMOVE_SPI_MASTER_SS3_PIN      (1u)
#define SPI_REMOVE_SPI_SLAVE_PINS          (0u)
#define SPI_REMOVE_SPI_SLAVE_MOSI_PIN      (0u)
#define SPI_REMOVE_SPI_SLAVE_MISO_PIN      (0u)
#define SPI_REMOVE_UART_TX_PIN             (1u)
#define SPI_REMOVE_UART_RX_TX_PIN          (1u)
#define SPI_REMOVE_UART_RX_PIN             (1u)
#define SPI_REMOVE_UART_RX_WAKE_PIN        (1u)
#define SPI_REMOVE_UART_RTS_PIN            (1u)
#define SPI_REMOVE_UART_CTS_PIN            (1u)

/* Unconfigured pins */
#define SPI_RX_WAKE_SCL_MOSI_PIN (0u == SPI_REMOVE_RX_WAKE_SCL_MOSI_PIN)
#define SPI_RX_SCL_MOSI_PIN     (0u == SPI_REMOVE_RX_SCL_MOSI_PIN)
#define SPI_TX_SDA_MISO_PIN     (0u == SPI_REMOVE_TX_SDA_MISO_PIN)
#define SPI_CTS_SCLK_PIN     (0u == SPI_REMOVE_CTS_SCLK_PIN)
#define SPI_RTS_SS0_PIN     (0u == SPI_REMOVE_RTS_SS0_PIN)
#define SPI_SS1_PIN                (0u == SPI_REMOVE_SS1_PIN)
#define SPI_SS2_PIN                (0u == SPI_REMOVE_SS2_PIN)
#define SPI_SS3_PIN                (0u == SPI_REMOVE_SS3_PIN)

/* Mode defined pins */
#define SPI_I2C_PINS               (0u == SPI_REMOVE_I2C_PINS)
#define SPI_SPI_MASTER_PINS        (0u == SPI_REMOVE_SPI_MASTER_PINS)
#define SPI_SPI_MASTER_SCLK_PIN    (0u == SPI_REMOVE_SPI_MASTER_SCLK_PIN)
#define SPI_SPI_MASTER_MOSI_PIN    (0u == SPI_REMOVE_SPI_MASTER_MOSI_PIN)
#define SPI_SPI_MASTER_MISO_PIN    (0u == SPI_REMOVE_SPI_MASTER_MISO_PIN)
#define SPI_SPI_MASTER_SS0_PIN     (0u == SPI_REMOVE_SPI_MASTER_SS0_PIN)
#define SPI_SPI_MASTER_SS1_PIN     (0u == SPI_REMOVE_SPI_MASTER_SS1_PIN)
#define SPI_SPI_MASTER_SS2_PIN     (0u == SPI_REMOVE_SPI_MASTER_SS2_PIN)
#define SPI_SPI_MASTER_SS3_PIN     (0u == SPI_REMOVE_SPI_MASTER_SS3_PIN)
#define SPI_SPI_SLAVE_PINS         (0u == SPI_REMOVE_SPI_SLAVE_PINS)
#define SPI_SPI_SLAVE_MOSI_PIN     (0u == SPI_REMOVE_SPI_SLAVE_MOSI_PIN)
#define SPI_SPI_SLAVE_MISO_PIN     (0u == SPI_REMOVE_SPI_SLAVE_MISO_PIN)
#define SPI_UART_TX_PIN            (0u == SPI_REMOVE_UART_TX_PIN)
#define SPI_UART_RX_TX_PIN         (0u == SPI_REMOVE_UART_RX_TX_PIN)
#define SPI_UART_RX_PIN            (0u == SPI_REMOVE_UART_RX_PIN)
#define SPI_UART_RX_WAKE_PIN       (0u == SPI_REMOVE_UART_RX_WAKE_PIN)
#define SPI_UART_RTS_PIN           (0u == SPI_REMOVE_UART_RTS_PIN)
#define SPI_UART_CTS_PIN           (0u == SPI_REMOVE_UART_CTS_PIN)


/***************************************
*             Includes
****************************************/

#if (SPI_RX_WAKE_SCL_MOSI_PIN)
    #include "SPI_uart_rx_wake_i2c_scl_spi_mosi.h"
#endif /* (SPI_RX_SCL_MOSI) */

#if (SPI_RX_SCL_MOSI_PIN)
    #include "SPI_uart_rx_i2c_scl_spi_mosi.h"
#endif /* (SPI_RX_SCL_MOSI) */

#if (SPI_TX_SDA_MISO_PIN)
    #include "SPI_uart_tx_i2c_sda_spi_miso.h"
#endif /* (SPI_TX_SDA_MISO) */

#if (SPI_CTS_SCLK_PIN)
    #include "SPI_uart_cts_spi_sclk.h"
#endif /* (SPI_CTS_SCLK) */

#if (SPI_RTS_SS0_PIN)
    #include "SPI_uart_rts_spi_ss0.h"
#endif /* (SPI_RTS_SS0_PIN) */

#if (SPI_SS1_PIN)
    #include "SPI_spi_ss1.h"
#endif /* (SPI_SS1_PIN) */

#if (SPI_SS2_PIN)
    #include "SPI_spi_ss2.h"
#endif /* (SPI_SS2_PIN) */

#if (SPI_SS3_PIN)
    #include "SPI_spi_ss3.h"
#endif /* (SPI_SS3_PIN) */

#if (SPI_I2C_PINS)
    #include "SPI_scl.h"
    #include "SPI_sda.h"
#endif /* (SPI_I2C_PINS) */

#if (SPI_SPI_MASTER_PINS)
#if (SPI_SPI_MASTER_SCLK_PIN)
    #include "SPI_sclk_m.h"
#endif /* (SPI_SPI_MASTER_SCLK_PIN) */

#if (SPI_SPI_MASTER_MOSI_PIN)
    #include "SPI_mosi_m.h"
#endif /* (SPI_SPI_MASTER_MOSI_PIN) */

#if (SPI_SPI_MASTER_MISO_PIN)
    #include "SPI_miso_m.h"
#endif /*(SPI_SPI_MASTER_MISO_PIN) */
#endif /* (SPI_SPI_MASTER_PINS) */

#if (SPI_SPI_SLAVE_PINS)
    #include "SPI_sclk_s.h"
    #include "SPI_ss_s.h"

#if (SPI_SPI_SLAVE_MOSI_PIN)
    #include "SPI_mosi_s.h"
#endif /* (SPI_SPI_SLAVE_MOSI_PIN) */

#if (SPI_SPI_SLAVE_MISO_PIN)
    #include "SPI_miso_s.h"
#endif /*(SPI_SPI_SLAVE_MISO_PIN) */
#endif /* (SPI_SPI_SLAVE_PINS) */

#if (SPI_SPI_MASTER_SS0_PIN)
    #include "SPI_ss0_m.h"
#endif /* (SPI_SPI_MASTER_SS0_PIN) */

#if (SPI_SPI_MASTER_SS1_PIN)
    #include "SPI_ss1_m.h"
#endif /* (SPI_SPI_MASTER_SS1_PIN) */

#if (SPI_SPI_MASTER_SS2_PIN)
    #include "SPI_ss2_m.h"
#endif /* (SPI_SPI_MASTER_SS2_PIN) */

#if (SPI_SPI_MASTER_SS3_PIN)
    #include "SPI_ss3_m.h"
#endif /* (SPI_SPI_MASTER_SS3_PIN) */

#if (SPI_UART_TX_PIN)
    #include "SPI_tx.h"
#endif /* (SPI_UART_TX_PIN) */

#if (SPI_UART_RX_TX_PIN)
    #include "SPI_rx_tx.h"
#endif /* (SPI_UART_RX_TX_PIN) */

#if (SPI_UART_RX_PIN)
    #include "SPI_rx.h"
#endif /* (SPI_UART_RX_PIN) */

#if (SPI_UART_RX_WAKE_PIN)
    #include "SPI_rx_wake.h"
#endif /* (SPI_UART_RX_WAKE_PIN) */

#if (SPI_UART_RTS_PIN)
    #include "SPI_rts.h"
#endif /* (SPI_UART_RTS_PIN) */

#if (SPI_UART_CTS_PIN)
    #include "SPI_cts.h"
#endif /* (SPI_UART_CTS_PIN) */


/***************************************
*              Registers
***************************************/

#if (SPI_RX_SCL_MOSI_PIN)
    #define SPI_RX_SCL_MOSI_HSIOM_REG   (*(reg32 *) SPI_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    #define SPI_RX_SCL_MOSI_HSIOM_PTR   ( (reg32 *) SPI_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    
    #define SPI_RX_SCL_MOSI_HSIOM_MASK      (SPI_uart_rx_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define SPI_RX_SCL_MOSI_HSIOM_POS       (SPI_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
    #define SPI_RX_SCL_MOSI_HSIOM_SEL_GPIO  (SPI_uart_rx_i2c_scl_spi_mosi__0__HSIOM_GPIO)
    #define SPI_RX_SCL_MOSI_HSIOM_SEL_I2C   (SPI_uart_rx_i2c_scl_spi_mosi__0__HSIOM_I2C)
    #define SPI_RX_SCL_MOSI_HSIOM_SEL_SPI   (SPI_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SPI)
    #define SPI_RX_SCL_MOSI_HSIOM_SEL_UART  (SPI_uart_rx_i2c_scl_spi_mosi__0__HSIOM_UART)
    
#elif (SPI_RX_WAKE_SCL_MOSI_PIN)
    #define SPI_RX_WAKE_SCL_MOSI_HSIOM_REG   (*(reg32 *) SPI_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    #define SPI_RX_WAKE_SCL_MOSI_HSIOM_PTR   ( (reg32 *) SPI_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    
    #define SPI_RX_WAKE_SCL_MOSI_HSIOM_MASK      (SPI_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define SPI_RX_WAKE_SCL_MOSI_HSIOM_POS       (SPI_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
    #define SPI_RX_WAKE_SCL_MOSI_HSIOM_SEL_GPIO  (SPI_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_GPIO)
    #define SPI_RX_WAKE_SCL_MOSI_HSIOM_SEL_I2C   (SPI_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_I2C)
    #define SPI_RX_WAKE_SCL_MOSI_HSIOM_SEL_SPI   (SPI_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SPI)
    #define SPI_RX_WAKE_SCL_MOSI_HSIOM_SEL_UART  (SPI_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_UART)    
   
    #define SPI_RX_WAKE_SCL_MOSI_INTCFG_REG (*(reg32 *) SPI_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define SPI_RX_WAKE_SCL_MOSI_INTCFG_PTR ( (reg32 *) SPI_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define SPI_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS  (SPI_uart_rx_wake_i2c_scl_spi_mosi__SHIFT)
    #define SPI_RX_WAKE_SCL_MOSI_INTCFG_TYPE_MASK ((uint32) SPI_INTCFG_TYPE_MASK << \
                                                                           SPI_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS)
#else
    /* None of pins SPI_RX_SCL_MOSI_PIN or SPI_RX_WAKE_SCL_MOSI_PIN present.*/
#endif /* (SPI_RX_SCL_MOSI_PIN) */

#if (SPI_TX_SDA_MISO_PIN)
    #define SPI_TX_SDA_MISO_HSIOM_REG   (*(reg32 *) SPI_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    #define SPI_TX_SDA_MISO_HSIOM_PTR   ( (reg32 *) SPI_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    
    #define SPI_TX_SDA_MISO_HSIOM_MASK      (SPI_uart_tx_i2c_sda_spi_miso__0__HSIOM_MASK)
    #define SPI_TX_SDA_MISO_HSIOM_POS       (SPI_uart_tx_i2c_sda_spi_miso__0__HSIOM_SHIFT)
    #define SPI_TX_SDA_MISO_HSIOM_SEL_GPIO  (SPI_uart_tx_i2c_sda_spi_miso__0__HSIOM_GPIO)
    #define SPI_TX_SDA_MISO_HSIOM_SEL_I2C   (SPI_uart_tx_i2c_sda_spi_miso__0__HSIOM_I2C)
    #define SPI_TX_SDA_MISO_HSIOM_SEL_SPI   (SPI_uart_tx_i2c_sda_spi_miso__0__HSIOM_SPI)
    #define SPI_TX_SDA_MISO_HSIOM_SEL_UART  (SPI_uart_tx_i2c_sda_spi_miso__0__HSIOM_UART)
#endif /* (SPI_TX_SDA_MISO_PIN) */

#if (SPI_CTS_SCLK_PIN)
    #define SPI_CTS_SCLK_HSIOM_REG   (*(reg32 *) SPI_uart_cts_spi_sclk__0__HSIOM)
    #define SPI_CTS_SCLK_HSIOM_PTR   ( (reg32 *) SPI_uart_cts_spi_sclk__0__HSIOM)
    
    #define SPI_CTS_SCLK_HSIOM_MASK      (SPI_uart_cts_spi_sclk__0__HSIOM_MASK)
    #define SPI_CTS_SCLK_HSIOM_POS       (SPI_uart_cts_spi_sclk__0__HSIOM_SHIFT)
    #define SPI_CTS_SCLK_HSIOM_SEL_GPIO  (SPI_uart_cts_spi_sclk__0__HSIOM_GPIO)
    #define SPI_CTS_SCLK_HSIOM_SEL_I2C   (SPI_uart_cts_spi_sclk__0__HSIOM_I2C)
    #define SPI_CTS_SCLK_HSIOM_SEL_SPI   (SPI_uart_cts_spi_sclk__0__HSIOM_SPI)
    #define SPI_CTS_SCLK_HSIOM_SEL_UART  (SPI_uart_cts_spi_sclk__0__HSIOM_UART)
#endif /* (SPI_CTS_SCLK_PIN) */

#if (SPI_RTS_SS0_PIN)
    #define SPI_RTS_SS0_HSIOM_REG   (*(reg32 *) SPI_uart_rts_spi_ss0__0__HSIOM)
    #define SPI_RTS_SS0_HSIOM_PTR   ( (reg32 *) SPI_uart_rts_spi_ss0__0__HSIOM)
    
    #define SPI_RTS_SS0_HSIOM_MASK      (SPI_uart_rts_spi_ss0__0__HSIOM_MASK)
    #define SPI_RTS_SS0_HSIOM_POS       (SPI_uart_rts_spi_ss0__0__HSIOM_SHIFT)
    #define SPI_RTS_SS0_HSIOM_SEL_GPIO  (SPI_uart_rts_spi_ss0__0__HSIOM_GPIO)
    #define SPI_RTS_SS0_HSIOM_SEL_I2C   (SPI_uart_rts_spi_ss0__0__HSIOM_I2C)
    #define SPI_RTS_SS0_HSIOM_SEL_SPI   (SPI_uart_rts_spi_ss0__0__HSIOM_SPI)
#if !(SPI_CY_SCBIP_V0 || SPI_CY_SCBIP_V1)
    #define SPI_RTS_SS0_HSIOM_SEL_UART  (SPI_uart_rts_spi_ss0__0__HSIOM_UART)
#endif /* !(SPI_CY_SCBIP_V0 || SPI_CY_SCBIP_V1) */
#endif /* (SPI_RTS_SS0_PIN) */

#if (SPI_SS1_PIN)
    #define SPI_SS1_HSIOM_REG  (*(reg32 *) SPI_spi_ss1__0__HSIOM)
    #define SPI_SS1_HSIOM_PTR  ( (reg32 *) SPI_spi_ss1__0__HSIOM)
    
    #define SPI_SS1_HSIOM_MASK     (SPI_spi_ss1__0__HSIOM_MASK)
    #define SPI_SS1_HSIOM_POS      (SPI_spi_ss1__0__HSIOM_SHIFT)
    #define SPI_SS1_HSIOM_SEL_GPIO (SPI_spi_ss1__0__HSIOM_GPIO)
    #define SPI_SS1_HSIOM_SEL_I2C  (SPI_spi_ss1__0__HSIOM_I2C)
    #define SPI_SS1_HSIOM_SEL_SPI  (SPI_spi_ss1__0__HSIOM_SPI)
#endif /* (SPI_SS1_PIN) */

#if (SPI_SS2_PIN)
    #define SPI_SS2_HSIOM_REG     (*(reg32 *) SPI_spi_ss2__0__HSIOM)
    #define SPI_SS2_HSIOM_PTR     ( (reg32 *) SPI_spi_ss2__0__HSIOM)
    
    #define SPI_SS2_HSIOM_MASK     (SPI_spi_ss2__0__HSIOM_MASK)
    #define SPI_SS2_HSIOM_POS      (SPI_spi_ss2__0__HSIOM_SHIFT)
    #define SPI_SS2_HSIOM_SEL_GPIO (SPI_spi_ss2__0__HSIOM_GPIO)
    #define SPI_SS2_HSIOM_SEL_I2C  (SPI_spi_ss2__0__HSIOM_I2C)
    #define SPI_SS2_HSIOM_SEL_SPI  (SPI_spi_ss2__0__HSIOM_SPI)
#endif /* (SPI_SS2_PIN) */

#if (SPI_SS3_PIN)
    #define SPI_SS3_HSIOM_REG     (*(reg32 *) SPI_spi_ss3__0__HSIOM)
    #define SPI_SS3_HSIOM_PTR     ( (reg32 *) SPI_spi_ss3__0__HSIOM)
    
    #define SPI_SS3_HSIOM_MASK     (SPI_spi_ss3__0__HSIOM_MASK)
    #define SPI_SS3_HSIOM_POS      (SPI_spi_ss3__0__HSIOM_SHIFT)
    #define SPI_SS3_HSIOM_SEL_GPIO (SPI_spi_ss3__0__HSIOM_GPIO)
    #define SPI_SS3_HSIOM_SEL_I2C  (SPI_spi_ss3__0__HSIOM_I2C)
    #define SPI_SS3_HSIOM_SEL_SPI  (SPI_spi_ss3__0__HSIOM_SPI)
#endif /* (SPI_SS3_PIN) */

#if (SPI_I2C_PINS)
    #define SPI_SCL_HSIOM_REG  (*(reg32 *) SPI_scl__0__HSIOM)
    #define SPI_SCL_HSIOM_PTR  ( (reg32 *) SPI_scl__0__HSIOM)
    
    #define SPI_SCL_HSIOM_MASK     (SPI_scl__0__HSIOM_MASK)
    #define SPI_SCL_HSIOM_POS      (SPI_scl__0__HSIOM_SHIFT)
    #define SPI_SCL_HSIOM_SEL_GPIO (SPI_sda__0__HSIOM_GPIO)
    #define SPI_SCL_HSIOM_SEL_I2C  (SPI_sda__0__HSIOM_I2C)
    
    #define SPI_SDA_HSIOM_REG  (*(reg32 *) SPI_sda__0__HSIOM)
    #define SPI_SDA_HSIOM_PTR  ( (reg32 *) SPI_sda__0__HSIOM)
    
    #define SPI_SDA_HSIOM_MASK     (SPI_sda__0__HSIOM_MASK)
    #define SPI_SDA_HSIOM_POS      (SPI_sda__0__HSIOM_SHIFT)
    #define SPI_SDA_HSIOM_SEL_GPIO (SPI_sda__0__HSIOM_GPIO)
    #define SPI_SDA_HSIOM_SEL_I2C  (SPI_sda__0__HSIOM_I2C)
#endif /* (SPI_I2C_PINS) */

#if (SPI_SPI_SLAVE_PINS)
    #define SPI_SCLK_S_HSIOM_REG   (*(reg32 *) SPI_sclk_s__0__HSIOM)
    #define SPI_SCLK_S_HSIOM_PTR   ( (reg32 *) SPI_sclk_s__0__HSIOM)
    
    #define SPI_SCLK_S_HSIOM_MASK      (SPI_sclk_s__0__HSIOM_MASK)
    #define SPI_SCLK_S_HSIOM_POS       (SPI_sclk_s__0__HSIOM_SHIFT)
    #define SPI_SCLK_S_HSIOM_SEL_GPIO  (SPI_sclk_s__0__HSIOM_GPIO)
    #define SPI_SCLK_S_HSIOM_SEL_SPI   (SPI_sclk_s__0__HSIOM_SPI)
    
    #define SPI_SS0_S_HSIOM_REG    (*(reg32 *) SPI_ss0_s__0__HSIOM)
    #define SPI_SS0_S_HSIOM_PTR    ( (reg32 *) SPI_ss0_s__0__HSIOM)
    
    #define SPI_SS0_S_HSIOM_MASK       (SPI_ss0_s__0__HSIOM_MASK)
    #define SPI_SS0_S_HSIOM_POS        (SPI_ss0_s__0__HSIOM_SHIFT)
    #define SPI_SS0_S_HSIOM_SEL_GPIO   (SPI_ss0_s__0__HSIOM_GPIO)  
    #define SPI_SS0_S_HSIOM_SEL_SPI    (SPI_ss0_s__0__HSIOM_SPI)
#endif /* (SPI_SPI_SLAVE_PINS) */

#if (SPI_SPI_SLAVE_MOSI_PIN)
    #define SPI_MOSI_S_HSIOM_REG   (*(reg32 *) SPI_mosi_s__0__HSIOM)
    #define SPI_MOSI_S_HSIOM_PTR   ( (reg32 *) SPI_mosi_s__0__HSIOM)
    
    #define SPI_MOSI_S_HSIOM_MASK      (SPI_mosi_s__0__HSIOM_MASK)
    #define SPI_MOSI_S_HSIOM_POS       (SPI_mosi_s__0__HSIOM_SHIFT)
    #define SPI_MOSI_S_HSIOM_SEL_GPIO  (SPI_mosi_s__0__HSIOM_GPIO)
    #define SPI_MOSI_S_HSIOM_SEL_SPI   (SPI_mosi_s__0__HSIOM_SPI)
#endif /* (SPI_SPI_SLAVE_MOSI_PIN) */

#if (SPI_SPI_SLAVE_MISO_PIN)
    #define SPI_MISO_S_HSIOM_REG   (*(reg32 *) SPI_miso_s__0__HSIOM)
    #define SPI_MISO_S_HSIOM_PTR   ( (reg32 *) SPI_miso_s__0__HSIOM)
    
    #define SPI_MISO_S_HSIOM_MASK      (SPI_miso_s__0__HSIOM_MASK)
    #define SPI_MISO_S_HSIOM_POS       (SPI_miso_s__0__HSIOM_SHIFT)
    #define SPI_MISO_S_HSIOM_SEL_GPIO  (SPI_miso_s__0__HSIOM_GPIO)
    #define SPI_MISO_S_HSIOM_SEL_SPI   (SPI_miso_s__0__HSIOM_SPI)
#endif /* (SPI_SPI_SLAVE_MISO_PIN) */

#if (SPI_SPI_MASTER_MISO_PIN)
    #define SPI_MISO_M_HSIOM_REG   (*(reg32 *) SPI_miso_m__0__HSIOM)
    #define SPI_MISO_M_HSIOM_PTR   ( (reg32 *) SPI_miso_m__0__HSIOM)
    
    #define SPI_MISO_M_HSIOM_MASK      (SPI_miso_m__0__HSIOM_MASK)
    #define SPI_MISO_M_HSIOM_POS       (SPI_miso_m__0__HSIOM_SHIFT)
    #define SPI_MISO_M_HSIOM_SEL_GPIO  (SPI_miso_m__0__HSIOM_GPIO)
    #define SPI_MISO_M_HSIOM_SEL_SPI   (SPI_miso_m__0__HSIOM_SPI)
#endif /* (SPI_SPI_MASTER_MISO_PIN) */

#if (SPI_SPI_MASTER_MOSI_PIN)
    #define SPI_MOSI_M_HSIOM_REG   (*(reg32 *) SPI_mosi_m__0__HSIOM)
    #define SPI_MOSI_M_HSIOM_PTR   ( (reg32 *) SPI_mosi_m__0__HSIOM)
    
    #define SPI_MOSI_M_HSIOM_MASK      (SPI_mosi_m__0__HSIOM_MASK)
    #define SPI_MOSI_M_HSIOM_POS       (SPI_mosi_m__0__HSIOM_SHIFT)
    #define SPI_MOSI_M_HSIOM_SEL_GPIO  (SPI_mosi_m__0__HSIOM_GPIO)
    #define SPI_MOSI_M_HSIOM_SEL_SPI   (SPI_mosi_m__0__HSIOM_SPI)
#endif /* (SPI_SPI_MASTER_MOSI_PIN) */

#if (SPI_SPI_MASTER_SCLK_PIN)
    #define SPI_SCLK_M_HSIOM_REG   (*(reg32 *) SPI_sclk_m__0__HSIOM)
    #define SPI_SCLK_M_HSIOM_PTR   ( (reg32 *) SPI_sclk_m__0__HSIOM)
    
    #define SPI_SCLK_M_HSIOM_MASK      (SPI_sclk_m__0__HSIOM_MASK)
    #define SPI_SCLK_M_HSIOM_POS       (SPI_sclk_m__0__HSIOM_SHIFT)
    #define SPI_SCLK_M_HSIOM_SEL_GPIO  (SPI_sclk_m__0__HSIOM_GPIO)
    #define SPI_SCLK_M_HSIOM_SEL_SPI   (SPI_sclk_m__0__HSIOM_SPI)
#endif /* (SPI_SPI_MASTER_SCLK_PIN) */

#if (SPI_SPI_MASTER_SS0_PIN)
    #define SPI_SS0_M_HSIOM_REG    (*(reg32 *) SPI_ss0_m__0__HSIOM)
    #define SPI_SS0_M_HSIOM_PTR    ( (reg32 *) SPI_ss0_m__0__HSIOM)
    
    #define SPI_SS0_M_HSIOM_MASK       (SPI_ss0_m__0__HSIOM_MASK)
    #define SPI_SS0_M_HSIOM_POS        (SPI_ss0_m__0__HSIOM_SHIFT)
    #define SPI_SS0_M_HSIOM_SEL_GPIO   (SPI_ss0_m__0__HSIOM_GPIO)
    #define SPI_SS0_M_HSIOM_SEL_SPI    (SPI_ss0_m__0__HSIOM_SPI)
#endif /* (SPI_SPI_MASTER_SS0_PIN) */

#if (SPI_SPI_MASTER_SS1_PIN)
    #define SPI_SS1_M_HSIOM_REG    (*(reg32 *) SPI_ss1_m__0__HSIOM)
    #define SPI_SS1_M_HSIOM_PTR    ( (reg32 *) SPI_ss1_m__0__HSIOM)
    
    #define SPI_SS1_M_HSIOM_MASK       (SPI_ss1_m__0__HSIOM_MASK)
    #define SPI_SS1_M_HSIOM_POS        (SPI_ss1_m__0__HSIOM_SHIFT)
    #define SPI_SS1_M_HSIOM_SEL_GPIO   (SPI_ss1_m__0__HSIOM_GPIO)
    #define SPI_SS1_M_HSIOM_SEL_SPI    (SPI_ss1_m__0__HSIOM_SPI)
#endif /* (SPI_SPI_MASTER_SS1_PIN) */

#if (SPI_SPI_MASTER_SS2_PIN)
    #define SPI_SS2_M_HSIOM_REG    (*(reg32 *) SPI_ss2_m__0__HSIOM)
    #define SPI_SS2_M_HSIOM_PTR    ( (reg32 *) SPI_ss2_m__0__HSIOM)
    
    #define SPI_SS2_M_HSIOM_MASK       (SPI_ss2_m__0__HSIOM_MASK)
    #define SPI_SS2_M_HSIOM_POS        (SPI_ss2_m__0__HSIOM_SHIFT)
    #define SPI_SS2_M_HSIOM_SEL_GPIO   (SPI_ss2_m__0__HSIOM_GPIO)
    #define SPI_SS2_M_HSIOM_SEL_SPI    (SPI_ss2_m__0__HSIOM_SPI)
#endif /* (SPI_SPI_MASTER_SS2_PIN) */

#if (SPI_SPI_MASTER_SS3_PIN)
    #define SPI_SS3_M_HSIOM_REG    (*(reg32 *) SPI_ss3_m__0__HSIOM)
    #define SPI_SS3_M_HSIOM_PTR    ( (reg32 *) SPI_ss3_m__0__HSIOM)
    
    #define SPI_SS3_M_HSIOM_MASK      (SPI_ss3_m__0__HSIOM_MASK)
    #define SPI_SS3_M_HSIOM_POS       (SPI_ss3_m__0__HSIOM_SHIFT)
    #define SPI_SS3_M_HSIOM_SEL_GPIO  (SPI_ss3_m__0__HSIOM_GPIO)
    #define SPI_SS3_M_HSIOM_SEL_SPI   (SPI_ss3_m__0__HSIOM_SPI)
#endif /* (SPI_SPI_MASTER_SS3_PIN) */

#if (SPI_UART_RX_PIN)
    #define SPI_RX_HSIOM_REG   (*(reg32 *) SPI_rx__0__HSIOM)
    #define SPI_RX_HSIOM_PTR   ( (reg32 *) SPI_rx__0__HSIOM)
    
    #define SPI_RX_HSIOM_MASK      (SPI_rx__0__HSIOM_MASK)
    #define SPI_RX_HSIOM_POS       (SPI_rx__0__HSIOM_SHIFT)
    #define SPI_RX_HSIOM_SEL_GPIO  (SPI_rx__0__HSIOM_GPIO)
    #define SPI_RX_HSIOM_SEL_UART  (SPI_rx__0__HSIOM_UART)
#endif /* (SPI_UART_RX_PIN) */

#if (SPI_UART_RX_WAKE_PIN)
    #define SPI_RX_WAKE_HSIOM_REG   (*(reg32 *) SPI_rx_wake__0__HSIOM)
    #define SPI_RX_WAKE_HSIOM_PTR   ( (reg32 *) SPI_rx_wake__0__HSIOM)
    
    #define SPI_RX_WAKE_HSIOM_MASK      (SPI_rx_wake__0__HSIOM_MASK)
    #define SPI_RX_WAKE_HSIOM_POS       (SPI_rx_wake__0__HSIOM_SHIFT)
    #define SPI_RX_WAKE_HSIOM_SEL_GPIO  (SPI_rx_wake__0__HSIOM_GPIO)
    #define SPI_RX_WAKE_HSIOM_SEL_UART  (SPI_rx_wake__0__HSIOM_UART)
#endif /* (SPI_UART_WAKE_RX_PIN) */

#if (SPI_UART_CTS_PIN)
    #define SPI_CTS_HSIOM_REG   (*(reg32 *) SPI_cts__0__HSIOM)
    #define SPI_CTS_HSIOM_PTR   ( (reg32 *) SPI_cts__0__HSIOM)
    
    #define SPI_CTS_HSIOM_MASK      (SPI_cts__0__HSIOM_MASK)
    #define SPI_CTS_HSIOM_POS       (SPI_cts__0__HSIOM_SHIFT)
    #define SPI_CTS_HSIOM_SEL_GPIO  (SPI_cts__0__HSIOM_GPIO)
    #define SPI_CTS_HSIOM_SEL_UART  (SPI_cts__0__HSIOM_UART)
#endif /* (SPI_UART_CTS_PIN) */

#if (SPI_UART_TX_PIN)
    #define SPI_TX_HSIOM_REG   (*(reg32 *) SPI_tx__0__HSIOM)
    #define SPI_TX_HSIOM_PTR   ( (reg32 *) SPI_tx__0__HSIOM)
    
    #define SPI_TX_HSIOM_MASK      (SPI_tx__0__HSIOM_MASK)
    #define SPI_TX_HSIOM_POS       (SPI_tx__0__HSIOM_SHIFT)
    #define SPI_TX_HSIOM_SEL_GPIO  (SPI_tx__0__HSIOM_GPIO)
    #define SPI_TX_HSIOM_SEL_UART  (SPI_tx__0__HSIOM_UART)
#endif /* (SPI_UART_TX_PIN) */

#if (SPI_UART_RX_TX_PIN)
    #define SPI_RX_TX_HSIOM_REG   (*(reg32 *) SPI_rx_tx__0__HSIOM)
    #define SPI_RX_TX_HSIOM_PTR   ( (reg32 *) SPI_rx_tx__0__HSIOM)
    
    #define SPI_RX_TX_HSIOM_MASK      (SPI_rx_tx__0__HSIOM_MASK)
    #define SPI_RX_TX_HSIOM_POS       (SPI_rx_tx__0__HSIOM_SHIFT)
    #define SPI_RX_TX_HSIOM_SEL_GPIO  (SPI_rx_tx__0__HSIOM_GPIO)
    #define SPI_RX_TX_HSIOM_SEL_UART  (SPI_rx_tx__0__HSIOM_UART)
#endif /* (SPI_UART_RX_TX_PIN) */

#if (SPI_UART_RTS_PIN)
    #define SPI_RTS_HSIOM_REG      (*(reg32 *) SPI_rts__0__HSIOM)
    #define SPI_RTS_HSIOM_PTR      ( (reg32 *) SPI_rts__0__HSIOM)
    
    #define SPI_RTS_HSIOM_MASK     (SPI_rts__0__HSIOM_MASK)
    #define SPI_RTS_HSIOM_POS      (SPI_rts__0__HSIOM_SHIFT)    
    #define SPI_RTS_HSIOM_SEL_GPIO (SPI_rts__0__HSIOM_GPIO)
    #define SPI_RTS_HSIOM_SEL_UART (SPI_rts__0__HSIOM_UART)    
#endif /* (SPI_UART_RTS_PIN) */


/***************************************
*        Registers Constants
***************************************/

/* HSIOM switch values. */ 
#define SPI_HSIOM_DEF_SEL      (0x00u)
#define SPI_HSIOM_GPIO_SEL     (0x00u)
/* The HSIOM values provided below are valid only for SPI_CY_SCBIP_V0 
* and SPI_CY_SCBIP_V1. It is not recommended to use them for 
* SPI_CY_SCBIP_V2. Use pin name specific HSIOM constants provided 
* above instead for any SCB IP block version.
*/
#define SPI_HSIOM_UART_SEL     (0x09u)
#define SPI_HSIOM_I2C_SEL      (0x0Eu)
#define SPI_HSIOM_SPI_SEL      (0x0Fu)

/* Pins settings index. */
#define SPI_RX_WAKE_SCL_MOSI_PIN_INDEX   (0u)
#define SPI_RX_SCL_MOSI_PIN_INDEX       (0u)
#define SPI_TX_SDA_MISO_PIN_INDEX       (1u)
#define SPI_CTS_SCLK_PIN_INDEX       (2u)
#define SPI_RTS_SS0_PIN_INDEX       (3u)
#define SPI_SS1_PIN_INDEX                  (4u)
#define SPI_SS2_PIN_INDEX                  (5u)
#define SPI_SS3_PIN_INDEX                  (6u)

/* Pins settings mask. */
#define SPI_RX_WAKE_SCL_MOSI_PIN_MASK ((uint32) 0x01u << SPI_RX_WAKE_SCL_MOSI_PIN_INDEX)
#define SPI_RX_SCL_MOSI_PIN_MASK     ((uint32) 0x01u << SPI_RX_SCL_MOSI_PIN_INDEX)
#define SPI_TX_SDA_MISO_PIN_MASK     ((uint32) 0x01u << SPI_TX_SDA_MISO_PIN_INDEX)
#define SPI_CTS_SCLK_PIN_MASK     ((uint32) 0x01u << SPI_CTS_SCLK_PIN_INDEX)
#define SPI_RTS_SS0_PIN_MASK     ((uint32) 0x01u << SPI_RTS_SS0_PIN_INDEX)
#define SPI_SS1_PIN_MASK                ((uint32) 0x01u << SPI_SS1_PIN_INDEX)
#define SPI_SS2_PIN_MASK                ((uint32) 0x01u << SPI_SS2_PIN_INDEX)
#define SPI_SS3_PIN_MASK                ((uint32) 0x01u << SPI_SS3_PIN_INDEX)

/* Pin interrupt constants. */
#define SPI_INTCFG_TYPE_MASK           (0x03u)
#define SPI_INTCFG_TYPE_FALLING_EDGE   (0x02u)

/* Pin Drive Mode constants. */
#define SPI_PIN_DM_ALG_HIZ  (0u)
#define SPI_PIN_DM_DIG_HIZ  (1u)
#define SPI_PIN_DM_OD_LO    (4u)
#define SPI_PIN_DM_STRONG   (6u)


/***************************************
*          Macro Definitions
***************************************/

/* Return drive mode of the pin */
#define SPI_DM_MASK    (0x7u)
#define SPI_DM_SIZE    (3u)
#define SPI_GET_P4_PIN_DM(reg, pos) \
    ( ((reg) & (uint32) ((uint32) SPI_DM_MASK << (SPI_DM_SIZE * (pos)))) >> \
                                                              (SPI_DM_SIZE * (pos)) )

#if (SPI_TX_SDA_MISO_PIN)
    #define SPI_CHECK_TX_SDA_MISO_PIN_USED \
                (SPI_PIN_DM_ALG_HIZ != \
                    SPI_GET_P4_PIN_DM(SPI_uart_tx_i2c_sda_spi_miso_PC, \
                                                   SPI_uart_tx_i2c_sda_spi_miso_SHIFT))
#endif /* (SPI_TX_SDA_MISO_PIN) */

#if (SPI_RTS_SS0_PIN)
    #define SPI_CHECK_RTS_SS0_PIN_USED \
                (SPI_PIN_DM_ALG_HIZ != \
                    SPI_GET_P4_PIN_DM(SPI_uart_rts_spi_ss0_PC, \
                                                   SPI_uart_rts_spi_ss0_SHIFT))
#endif /* (SPI_RTS_SS0_PIN) */

/* Set bits-mask in register */
#define SPI_SET_REGISTER_BITS(reg, mask, pos, mode) \
                    do                                           \
                    {                                            \
                        (reg) = (((reg) & ((uint32) ~(uint32) (mask))) | ((uint32) ((uint32) (mode) << (pos)))); \
                    }while(0)

/* Set bit in the register */
#define SPI_SET_REGISTER_BIT(reg, mask, val) \
                    ((val) ? ((reg) |= (mask)) : ((reg) &= ((uint32) ~((uint32) (mask)))))

#define SPI_SET_HSIOM_SEL(reg, mask, pos, sel) SPI_SET_REGISTER_BITS(reg, mask, pos, sel)
#define SPI_SET_INCFG_TYPE(reg, mask, pos, intType) \
                                                        SPI_SET_REGISTER_BITS(reg, mask, pos, intType)
#define SPI_SET_INP_DIS(reg, mask, val) SPI_SET_REGISTER_BIT(reg, mask, val)

/* SPI_SET_I2C_SCL_DR(val) - Sets I2C SCL DR register.
*  SPI_SET_I2C_SCL_HSIOM_SEL(sel) - Sets I2C SCL HSIOM settings.
*/
/* SCB I2C: scl signal */
#if (SPI_CY_SCBIP_V0)
#if (SPI_I2C_PINS)
    #define SPI_SET_I2C_SCL_DR(val) SPI_scl_Write(val)

    #define SPI_SET_I2C_SCL_HSIOM_SEL(sel) \
                          SPI_SET_HSIOM_SEL(SPI_SCL_HSIOM_REG,  \
                                                         SPI_SCL_HSIOM_MASK, \
                                                         SPI_SCL_HSIOM_POS,  \
                                                         (sel))
    #define SPI_WAIT_SCL_SET_HIGH  (0u == SPI_scl_Read())

/* Unconfigured SCB: scl signal */
#elif (SPI_RX_WAKE_SCL_MOSI_PIN)
    #define SPI_SET_I2C_SCL_DR(val) \
                            SPI_uart_rx_wake_i2c_scl_spi_mosi_Write(val)

    #define SPI_SET_I2C_SCL_HSIOM_SEL(sel) \
                    SPI_SET_HSIOM_SEL(SPI_RX_WAKE_SCL_MOSI_HSIOM_REG,  \
                                                   SPI_RX_WAKE_SCL_MOSI_HSIOM_MASK, \
                                                   SPI_RX_WAKE_SCL_MOSI_HSIOM_POS,  \
                                                   (sel))

    #define SPI_WAIT_SCL_SET_HIGH  (0u == SPI_uart_rx_wake_i2c_scl_spi_mosi_Read())

#elif (SPI_RX_SCL_MOSI_PIN)
    #define SPI_SET_I2C_SCL_DR(val) \
                            SPI_uart_rx_i2c_scl_spi_mosi_Write(val)


    #define SPI_SET_I2C_SCL_HSIOM_SEL(sel) \
                            SPI_SET_HSIOM_SEL(SPI_RX_SCL_MOSI_HSIOM_REG,  \
                                                           SPI_RX_SCL_MOSI_HSIOM_MASK, \
                                                           SPI_RX_SCL_MOSI_HSIOM_POS,  \
                                                           (sel))

    #define SPI_WAIT_SCL_SET_HIGH  (0u == SPI_uart_rx_i2c_scl_spi_mosi_Read())

#else
    #define SPI_SET_I2C_SCL_DR(val)        do{ /* Does nothing */ }while(0)
    #define SPI_SET_I2C_SCL_HSIOM_SEL(sel) do{ /* Does nothing */ }while(0)

    #define SPI_WAIT_SCL_SET_HIGH  (0u)
#endif /* (SPI_I2C_PINS) */

/* SCB I2C: sda signal */
#if (SPI_I2C_PINS)
    #define SPI_WAIT_SDA_SET_HIGH  (0u == SPI_sda_Read())
/* Unconfigured SCB: sda signal */
#elif (SPI_TX_SDA_MISO_PIN)
    #define SPI_WAIT_SDA_SET_HIGH  (0u == SPI_uart_tx_i2c_sda_spi_miso_Read())
#else
    #define SPI_WAIT_SDA_SET_HIGH  (0u)
#endif /* (SPI_MOSI_SCL_RX_PIN) */
#endif /* (SPI_CY_SCBIP_V0) */

/* Clear UART wakeup source */
#if (SPI_RX_SCL_MOSI_PIN)
    #define SPI_CLEAR_UART_RX_WAKE_INTR        do{ /* Does nothing */ }while(0)
    
#elif (SPI_RX_WAKE_SCL_MOSI_PIN)
    #define SPI_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) SPI_uart_rx_wake_i2c_scl_spi_mosi_ClearInterrupt(); \
            }while(0)

#elif(SPI_UART_RX_WAKE_PIN)
    #define SPI_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) SPI_rx_wake_ClearInterrupt(); \
            }while(0)
#else
#endif /* (SPI_RX_SCL_MOSI_PIN) */


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Unconfigured pins */
#define SPI_REMOVE_MOSI_SCL_RX_WAKE_PIN    SPI_REMOVE_RX_WAKE_SCL_MOSI_PIN
#define SPI_REMOVE_MOSI_SCL_RX_PIN         SPI_REMOVE_RX_SCL_MOSI_PIN
#define SPI_REMOVE_MISO_SDA_TX_PIN         SPI_REMOVE_TX_SDA_MISO_PIN
#ifndef SPI_REMOVE_SCLK_PIN
#define SPI_REMOVE_SCLK_PIN                SPI_REMOVE_CTS_SCLK_PIN
#endif /* SPI_REMOVE_SCLK_PIN */
#ifndef SPI_REMOVE_SS0_PIN
#define SPI_REMOVE_SS0_PIN                 SPI_REMOVE_RTS_SS0_PIN
#endif /* SPI_REMOVE_SS0_PIN */

/* Unconfigured pins */
#define SPI_MOSI_SCL_RX_WAKE_PIN   SPI_RX_WAKE_SCL_MOSI_PIN
#define SPI_MOSI_SCL_RX_PIN        SPI_RX_SCL_MOSI_PIN
#define SPI_MISO_SDA_TX_PIN        SPI_TX_SDA_MISO_PIN
#ifndef SPI_SCLK_PIN
#define SPI_SCLK_PIN               SPI_CTS_SCLK_PIN
#endif /* SPI_SCLK_PIN */
#ifndef SPI_SS0_PIN
#define SPI_SS0_PIN                SPI_RTS_SS0_PIN
#endif /* SPI_SS0_PIN */

#if (SPI_MOSI_SCL_RX_WAKE_PIN)
    #define SPI_MOSI_SCL_RX_WAKE_HSIOM_REG     SPI_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define SPI_MOSI_SCL_RX_WAKE_HSIOM_PTR     SPI_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define SPI_MOSI_SCL_RX_WAKE_HSIOM_MASK    SPI_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define SPI_MOSI_SCL_RX_WAKE_HSIOM_POS     SPI_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define SPI_MOSI_SCL_RX_WAKE_INTCFG_REG    SPI_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define SPI_MOSI_SCL_RX_WAKE_INTCFG_PTR    SPI_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define SPI_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS   SPI_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define SPI_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK  SPI_RX_WAKE_SCL_MOSI_HSIOM_REG
#endif /* (SPI_RX_WAKE_SCL_MOSI_PIN) */

#if (SPI_MOSI_SCL_RX_PIN)
    #define SPI_MOSI_SCL_RX_HSIOM_REG      SPI_RX_SCL_MOSI_HSIOM_REG
    #define SPI_MOSI_SCL_RX_HSIOM_PTR      SPI_RX_SCL_MOSI_HSIOM_PTR
    #define SPI_MOSI_SCL_RX_HSIOM_MASK     SPI_RX_SCL_MOSI_HSIOM_MASK
    #define SPI_MOSI_SCL_RX_HSIOM_POS      SPI_RX_SCL_MOSI_HSIOM_POS
#endif /* (SPI_MOSI_SCL_RX_PIN) */

#if (SPI_MISO_SDA_TX_PIN)
    #define SPI_MISO_SDA_TX_HSIOM_REG      SPI_TX_SDA_MISO_HSIOM_REG
    #define SPI_MISO_SDA_TX_HSIOM_PTR      SPI_TX_SDA_MISO_HSIOM_REG
    #define SPI_MISO_SDA_TX_HSIOM_MASK     SPI_TX_SDA_MISO_HSIOM_REG
    #define SPI_MISO_SDA_TX_HSIOM_POS      SPI_TX_SDA_MISO_HSIOM_REG
#endif /* (SPI_MISO_SDA_TX_PIN_PIN) */

#if (SPI_SCLK_PIN)
    #ifndef SPI_SCLK_HSIOM_REG
    #define SPI_SCLK_HSIOM_REG     SPI_CTS_SCLK_HSIOM_REG
    #define SPI_SCLK_HSIOM_PTR     SPI_CTS_SCLK_HSIOM_PTR
    #define SPI_SCLK_HSIOM_MASK    SPI_CTS_SCLK_HSIOM_MASK
    #define SPI_SCLK_HSIOM_POS     SPI_CTS_SCLK_HSIOM_POS
    #endif /* SPI_SCLK_HSIOM_REG */
#endif /* (SPI_SCLK_PIN) */

#if (SPI_SS0_PIN)
    #ifndef SPI_SS0_HSIOM_REG
    #define SPI_SS0_HSIOM_REG      SPI_RTS_SS0_HSIOM_REG
    #define SPI_SS0_HSIOM_PTR      SPI_RTS_SS0_HSIOM_PTR
    #define SPI_SS0_HSIOM_MASK     SPI_RTS_SS0_HSIOM_MASK
    #define SPI_SS0_HSIOM_POS      SPI_RTS_SS0_HSIOM_POS
    #endif /* SPI_SS0_HSIOM_REG */
#endif /* (SPI_SS0_PIN) */

#define SPI_MOSI_SCL_RX_WAKE_PIN_INDEX SPI_RX_WAKE_SCL_MOSI_PIN_INDEX
#define SPI_MOSI_SCL_RX_PIN_INDEX      SPI_RX_SCL_MOSI_PIN_INDEX
#define SPI_MISO_SDA_TX_PIN_INDEX      SPI_TX_SDA_MISO_PIN_INDEX
#ifndef SPI_SCLK_PIN_INDEX
#define SPI_SCLK_PIN_INDEX             SPI_CTS_SCLK_PIN_INDEX
#endif /* SPI_SCLK_PIN_INDEX */
#ifndef SPI_SS0_PIN_INDEX
#define SPI_SS0_PIN_INDEX              SPI_RTS_SS0_PIN_INDEX
#endif /* SPI_SS0_PIN_INDEX */

#define SPI_MOSI_SCL_RX_WAKE_PIN_MASK SPI_RX_WAKE_SCL_MOSI_PIN_MASK
#define SPI_MOSI_SCL_RX_PIN_MASK      SPI_RX_SCL_MOSI_PIN_MASK
#define SPI_MISO_SDA_TX_PIN_MASK      SPI_TX_SDA_MISO_PIN_MASK
#ifndef SPI_SCLK_PIN_MASK
#define SPI_SCLK_PIN_MASK             SPI_CTS_SCLK_PIN_MASK
#endif /* SPI_SCLK_PIN_MASK */
#ifndef SPI_SS0_PIN_MASK
#define SPI_SS0_PIN_MASK              SPI_RTS_SS0_PIN_MASK
#endif /* SPI_SS0_PIN_MASK */

#endif /* (CY_SCB_PINS_SPI_H) */


/* [] END OF FILE */
