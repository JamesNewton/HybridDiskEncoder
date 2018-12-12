/***************************************************************************//**
* \file SPI_BOOT.h
* \version 3.20
*
* \brief
*  This file provides constants and parameter values of the bootloader
*  communication APIs for the SCB Component.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2014-2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_BOOT_SPI_H)
#define CY_SCB_BOOT_SPI_H

#include "SPI_PVT.h"

#if (SPI_SCB_MODE_I2C_INC)
    #include "SPI_I2C.h"
#endif /* (SPI_SCB_MODE_I2C_INC) */

#if (SPI_SCB_MODE_EZI2C_INC)
    #include "SPI_EZI2C.h"
#endif /* (SPI_SCB_MODE_EZI2C_INC) */

#if (SPI_SCB_MODE_SPI_INC || SPI_SCB_MODE_UART_INC)
    #include "SPI_SPI_UART.h"
#endif /* (SPI_SCB_MODE_SPI_INC || SPI_SCB_MODE_UART_INC) */


/***************************************
*  Conditional Compilation Parameters
****************************************/

/* Bootloader communication interface enable */
#define SPI_BTLDR_COMM_ENABLED ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SPI) || \
                                             (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

/* Enable I2C bootloader communication */
#if (SPI_SCB_MODE_I2C_INC)
    #define SPI_I2C_BTLDR_COMM_ENABLED     (SPI_BTLDR_COMM_ENABLED && \
                                                            (SPI_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             SPI_I2C_SLAVE_CONST))
#else
     #define SPI_I2C_BTLDR_COMM_ENABLED    (0u)
#endif /* (SPI_SCB_MODE_I2C_INC) */

/* EZI2C does not support bootloader communication. Provide empty APIs */
#if (SPI_SCB_MODE_EZI2C_INC)
    #define SPI_EZI2C_BTLDR_COMM_ENABLED   (SPI_BTLDR_COMM_ENABLED && \
                                                         SPI_SCB_MODE_UNCONFIG_CONST_CFG)
#else
    #define SPI_EZI2C_BTLDR_COMM_ENABLED   (0u)
#endif /* (SPI_EZI2C_BTLDR_COMM_ENABLED) */

/* Enable SPI bootloader communication */
#if (SPI_SCB_MODE_SPI_INC)
    #define SPI_SPI_BTLDR_COMM_ENABLED     (SPI_BTLDR_COMM_ENABLED && \
                                                            (SPI_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             SPI_SPI_SLAVE_CONST))
#else
        #define SPI_SPI_BTLDR_COMM_ENABLED (0u)
#endif /* (SPI_SPI_BTLDR_COMM_ENABLED) */

/* Enable UART bootloader communication */
#if (SPI_SCB_MODE_UART_INC)
       #define SPI_UART_BTLDR_COMM_ENABLED    (SPI_BTLDR_COMM_ENABLED && \
                                                            (SPI_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             (SPI_UART_RX_DIRECTION && \
                                                              SPI_UART_TX_DIRECTION)))
#else
     #define SPI_UART_BTLDR_COMM_ENABLED   (0u)
#endif /* (SPI_UART_BTLDR_COMM_ENABLED) */

/* Enable bootloader communication */
#define SPI_BTLDR_COMM_MODE_ENABLED    (SPI_I2C_BTLDR_COMM_ENABLED   || \
                                                     SPI_SPI_BTLDR_COMM_ENABLED   || \
                                                     SPI_EZI2C_BTLDR_COMM_ENABLED || \
                                                     SPI_UART_BTLDR_COMM_ENABLED)


/***************************************
*        Function Prototypes
***************************************/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_I2C_BTLDR_COMM_ENABLED)
    /* I2C Bootloader physical layer functions */
    void SPI_I2CCyBtldrCommStart(void);
    void SPI_I2CCyBtldrCommStop (void);
    void SPI_I2CCyBtldrCommReset(void);
    cystatus SPI_I2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus SPI_I2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map I2C specific bootloader communication APIs to SCB specific APIs */
    #if (SPI_SCB_MODE_I2C_CONST_CFG)
        #define SPI_CyBtldrCommStart   SPI_I2CCyBtldrCommStart
        #define SPI_CyBtldrCommStop    SPI_I2CCyBtldrCommStop
        #define SPI_CyBtldrCommReset   SPI_I2CCyBtldrCommReset
        #define SPI_CyBtldrCommRead    SPI_I2CCyBtldrCommRead
        #define SPI_CyBtldrCommWrite   SPI_I2CCyBtldrCommWrite
    #endif /* (SPI_SCB_MODE_I2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_I2C_BTLDR_COMM_ENABLED) */


#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_EZI2C_BTLDR_COMM_ENABLED)
    /* Bootloader physical layer functions */
    void SPI_EzI2CCyBtldrCommStart(void);
    void SPI_EzI2CCyBtldrCommStop (void);
    void SPI_EzI2CCyBtldrCommReset(void);
    cystatus SPI_EzI2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus SPI_EzI2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map EZI2C specific bootloader communication APIs to SCB specific APIs */
    #if (SPI_SCB_MODE_EZI2C_CONST_CFG)
        #define SPI_CyBtldrCommStart   SPI_EzI2CCyBtldrCommStart
        #define SPI_CyBtldrCommStop    SPI_EzI2CCyBtldrCommStop
        #define SPI_CyBtldrCommReset   SPI_EzI2CCyBtldrCommReset
        #define SPI_CyBtldrCommRead    SPI_EzI2CCyBtldrCommRead
        #define SPI_CyBtldrCommWrite   SPI_EzI2CCyBtldrCommWrite
    #endif /* (SPI_SCB_MODE_EZI2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_EZI2C_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_SPI_BTLDR_COMM_ENABLED)
    /* SPI Bootloader physical layer functions */
    void SPI_SpiCyBtldrCommStart(void);
    void SPI_SpiCyBtldrCommStop (void);
    void SPI_SpiCyBtldrCommReset(void);
    cystatus SPI_SpiCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus SPI_SpiCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map SPI specific bootloader communication APIs to SCB specific APIs */
    #if (SPI_SCB_MODE_SPI_CONST_CFG)
        #define SPI_CyBtldrCommStart   SPI_SpiCyBtldrCommStart
        #define SPI_CyBtldrCommStop    SPI_SpiCyBtldrCommStop
        #define SPI_CyBtldrCommReset   SPI_SpiCyBtldrCommReset
        #define SPI_CyBtldrCommRead    SPI_SpiCyBtldrCommRead
        #define SPI_CyBtldrCommWrite   SPI_SpiCyBtldrCommWrite
    #endif /* (SPI_SCB_MODE_SPI_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_SPI_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_UART_BTLDR_COMM_ENABLED)
    /* UART Bootloader physical layer functions */
    void SPI_UartCyBtldrCommStart(void);
    void SPI_UartCyBtldrCommStop (void);
    void SPI_UartCyBtldrCommReset(void);
    cystatus SPI_UartCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus SPI_UartCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map UART specific bootloader communication APIs to SCB specific APIs */
    #if (SPI_SCB_MODE_UART_CONST_CFG)
        #define SPI_CyBtldrCommStart   SPI_UartCyBtldrCommStart
        #define SPI_CyBtldrCommStop    SPI_UartCyBtldrCommStop
        #define SPI_CyBtldrCommReset   SPI_UartCyBtldrCommReset
        #define SPI_CyBtldrCommRead    SPI_UartCyBtldrCommRead
        #define SPI_CyBtldrCommWrite   SPI_UartCyBtldrCommWrite
    #endif /* (SPI_SCB_MODE_UART_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_UART_BTLDR_COMM_ENABLED) */

/**
* \addtogroup group_bootloader
* @{
*/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_BTLDR_COMM_ENABLED)
    #if (SPI_SCB_MODE_UNCONFIG_CONST_CFG)
        /* Bootloader physical layer functions */
        void SPI_CyBtldrCommStart(void);
        void SPI_CyBtldrCommStop (void);
        void SPI_CyBtldrCommReset(void);
        cystatus SPI_CyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
        cystatus SPI_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    #endif /* (SPI_SCB_MODE_UNCONFIG_CONST_CFG) */

    /* Map SCB specific bootloader communication APIs to common APIs */
    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SPI)
        #define CyBtldrCommStart    SPI_CyBtldrCommStart
        #define CyBtldrCommStop     SPI_CyBtldrCommStop
        #define CyBtldrCommReset    SPI_CyBtldrCommReset
        #define CyBtldrCommWrite    SPI_CyBtldrCommWrite
        #define CyBtldrCommRead     SPI_CyBtldrCommRead
    #endif /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SPI) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_BTLDR_COMM_ENABLED) */

/** @} group_bootloader */

/***************************************
*           API Constants
***************************************/

/* Timeout unit in milliseconds */
#define SPI_WAIT_1_MS  (1u)

/* Return number of bytes to copy into bootloader buffer */
#define SPI_BYTES_TO_COPY(actBufSize, bufSize) \
                            ( ((uint32)(actBufSize) < (uint32)(bufSize)) ? \
                                ((uint32) (actBufSize)) : ((uint32) (bufSize)) )

/* Size of Read/Write buffers for I2C bootloader  */
#define SPI_I2C_BTLDR_SIZEOF_READ_BUFFER   (64u)
#define SPI_I2C_BTLDR_SIZEOF_WRITE_BUFFER  (64u)

/* Byte to byte time interval: calculated basing on current component
* data rate configuration, can be defined in project if required.
*/
#ifndef SPI_SPI_BYTE_TO_BYTE
    #define SPI_SPI_BYTE_TO_BYTE   (16u)
#endif

/* Byte to byte time interval: calculated basing on current component
* baud rate configuration, can be defined in the project if required.
*/
#ifndef SPI_UART_BYTE_TO_BYTE
    #define SPI_UART_BYTE_TO_BYTE  (2500u)
#endif /* SPI_UART_BYTE_TO_BYTE */

#endif /* (CY_SCB_BOOT_SPI_H) */


/* [] END OF FILE */
