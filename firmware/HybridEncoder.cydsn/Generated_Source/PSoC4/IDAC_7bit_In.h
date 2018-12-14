/*******************************************************************************
* File Name: IDAC_7bit_In.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_IDAC_7bit_In_H) /* Pins IDAC_7bit_In_H */
#define CY_PINS_IDAC_7bit_In_H

#include "cytypes.h"
#include "cyfitter.h"
#include "IDAC_7bit_In_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    IDAC_7bit_In_Write(uint8 value) ;
void    IDAC_7bit_In_SetDriveMode(uint8 mode) ;
uint8   IDAC_7bit_In_ReadDataReg(void) ;
uint8   IDAC_7bit_In_Read(void) ;
uint8   IDAC_7bit_In_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define IDAC_7bit_In_DRIVE_MODE_BITS        (3)
#define IDAC_7bit_In_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - IDAC_7bit_In_DRIVE_MODE_BITS))

#define IDAC_7bit_In_DM_ALG_HIZ         (0x00u)
#define IDAC_7bit_In_DM_DIG_HIZ         (0x01u)
#define IDAC_7bit_In_DM_RES_UP          (0x02u)
#define IDAC_7bit_In_DM_RES_DWN         (0x03u)
#define IDAC_7bit_In_DM_OD_LO           (0x04u)
#define IDAC_7bit_In_DM_OD_HI           (0x05u)
#define IDAC_7bit_In_DM_STRONG          (0x06u)
#define IDAC_7bit_In_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define IDAC_7bit_In_MASK               IDAC_7bit_In__MASK
#define IDAC_7bit_In_SHIFT              IDAC_7bit_In__SHIFT
#define IDAC_7bit_In_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define IDAC_7bit_In_PS                     (* (reg32 *) IDAC_7bit_In__PS)
/* Port Configuration */
#define IDAC_7bit_In_PC                     (* (reg32 *) IDAC_7bit_In__PC)
/* Data Register */
#define IDAC_7bit_In_DR                     (* (reg32 *) IDAC_7bit_In__DR)
/* Input Buffer Disable Override */
#define IDAC_7bit_In_INP_DIS                (* (reg32 *) IDAC_7bit_In__PC2)


#if defined(IDAC_7bit_In__INTSTAT)  /* Interrupt Registers */

    #define IDAC_7bit_In_INTSTAT                (* (reg32 *) IDAC_7bit_In__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define IDAC_7bit_In_DRIVE_MODE_SHIFT       (0x00u)
#define IDAC_7bit_In_DRIVE_MODE_MASK        (0x07u << IDAC_7bit_In_DRIVE_MODE_SHIFT)


#endif /* End Pins IDAC_7bit_In_H */


/* [] END OF FILE */
