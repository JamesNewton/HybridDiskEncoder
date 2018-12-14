/*******************************************************************************
* File Name: SPI_SCBCLK.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_SPI_SCBCLK_H)
#define CY_CLOCK_SPI_SCBCLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void SPI_SCBCLK_StartEx(uint32 alignClkDiv);
#define SPI_SCBCLK_Start() \
    SPI_SCBCLK_StartEx(SPI_SCBCLK__PA_DIV_ID)

#else

void SPI_SCBCLK_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void SPI_SCBCLK_Stop(void);

void SPI_SCBCLK_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 SPI_SCBCLK_GetDividerRegister(void);
uint8  SPI_SCBCLK_GetFractionalDividerRegister(void);

#define SPI_SCBCLK_Enable()                         SPI_SCBCLK_Start()
#define SPI_SCBCLK_Disable()                        SPI_SCBCLK_Stop()
#define SPI_SCBCLK_SetDividerRegister(clkDivider, reset)  \
    SPI_SCBCLK_SetFractionalDividerRegister((clkDivider), 0u)
#define SPI_SCBCLK_SetDivider(clkDivider)           SPI_SCBCLK_SetDividerRegister((clkDivider), 1u)
#define SPI_SCBCLK_SetDividerValue(clkDivider)      SPI_SCBCLK_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define SPI_SCBCLK_DIV_ID     SPI_SCBCLK__DIV_ID

#define SPI_SCBCLK_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define SPI_SCBCLK_CTRL_REG   (*(reg32 *)SPI_SCBCLK__CTRL_REGISTER)
#define SPI_SCBCLK_DIV_REG    (*(reg32 *)SPI_SCBCLK__DIV_REGISTER)

#define SPI_SCBCLK_CMD_DIV_SHIFT          (0u)
#define SPI_SCBCLK_CMD_PA_DIV_SHIFT       (8u)
#define SPI_SCBCLK_CMD_DISABLE_SHIFT      (30u)
#define SPI_SCBCLK_CMD_ENABLE_SHIFT       (31u)

#define SPI_SCBCLK_CMD_DISABLE_MASK       ((uint32)((uint32)1u << SPI_SCBCLK_CMD_DISABLE_SHIFT))
#define SPI_SCBCLK_CMD_ENABLE_MASK        ((uint32)((uint32)1u << SPI_SCBCLK_CMD_ENABLE_SHIFT))

#define SPI_SCBCLK_DIV_FRAC_MASK  (0x000000F8u)
#define SPI_SCBCLK_DIV_FRAC_SHIFT (3u)
#define SPI_SCBCLK_DIV_INT_MASK   (0xFFFFFF00u)
#define SPI_SCBCLK_DIV_INT_SHIFT  (8u)

#else 

#define SPI_SCBCLK_DIV_REG        (*(reg32 *)SPI_SCBCLK__REGISTER)
#define SPI_SCBCLK_ENABLE_REG     SPI_SCBCLK_DIV_REG
#define SPI_SCBCLK_DIV_FRAC_MASK  SPI_SCBCLK__FRAC_MASK
#define SPI_SCBCLK_DIV_FRAC_SHIFT (16u)
#define SPI_SCBCLK_DIV_INT_MASK   SPI_SCBCLK__DIVIDER_MASK
#define SPI_SCBCLK_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_SPI_SCBCLK_H) */

/* [] END OF FILE */
