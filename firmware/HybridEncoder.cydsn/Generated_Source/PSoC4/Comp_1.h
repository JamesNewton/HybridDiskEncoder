<<<<<<< HEAD
/*******************************************************************************
* File Name: Comp_1.h
* Version 2.20
*
* Description:
*  This file contains the function prototypes and constants used in
*  the Low Power Comparator component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_COMPARATOR_Comp_1_H)
#define CY_COMPARATOR_Comp_1_H

#include "cytypes.h"
#include "cyfitter.h"


extern uint8  Comp_1_initVar;


/***************************************
*  Conditional Compilation Parameters
****************************************/

#define Comp_1_CY_LPCOMP_V0 (CYIPBLOCK_m0s8lpcomp_VERSION == 0u) 
#define Comp_1_CY_LPCOMP_V2 (CYIPBLOCK_m0s8lpcomp_VERSION >= 2u) 


/**************************************
*        Function Prototypes
**************************************/

void    Comp_1_Start(void);
void    Comp_1_Init(void);
void    Comp_1_Enable(void);
void    Comp_1_Stop(void);
void    Comp_1_SetSpeed(uint32 speed);
void    Comp_1_SetInterruptMode(uint32 mode);
uint32  Comp_1_GetInterruptSource(void);
void    Comp_1_ClearInterrupt(uint32 interruptMask);
void    Comp_1_SetInterrupt(uint32 interruptMask);
void    Comp_1_SetHysteresis(uint32 hysteresis);
uint32  Comp_1_GetCompare(void);
uint32  Comp_1_ZeroCal(void);
void    Comp_1_LoadTrim(uint32 trimVal);
void    Comp_1_Sleep(void);
void    Comp_1_Wakeup(void);
void    Comp_1_SaveConfig(void);
void    Comp_1_RestoreConfig(void);
#if(Comp_1_CY_LPCOMP_V2)
    void    Comp_1_SetOutputMode(uint32 mode);
    void    Comp_1_SetInterruptMask(uint32 interruptMask);
    uint32  Comp_1_GetInterruptMask(void);
    uint32  Comp_1_GetInterruptSourceMasked(void);
#endif /* (Comp_1_CY_LPCOMP_V2) */


/**************************************
*           API Constants
**************************************/

#if(Comp_1_CY_LPCOMP_V2)
    /* Constants for Comp_1_SetOutputMode(), mode parameter */
    #define Comp_1_OUT_PULSE      (0x00u)
    #define Comp_1_OUT_SYNC       (0x01u)
    #define Comp_1_OUT_DIRECT     (0x02u)
#endif /* (Comp_1_CY_LPCOMP_V2) */

#define Comp_1_INTR_PARAM_MASK    (0x03u)
#define Comp_1_SPEED_PARAM_MASK   (0x03u)

/* Constants for Comp_1_SetSpeed(), speed parameter */
#define Comp_1_MED_SPEED          (0x00u)
#define Comp_1_HIGH_SPEED         (0x01u)
#define Comp_1_LOW_SPEED          (0x02u)

/* Constants for Comp_1_SetInterruptMode(), mode parameter */
#define Comp_1_INTR_DISABLE       (0x00u)
#define Comp_1_INTR_RISING        (0x01u)
#define Comp_1_INTR_FALLING       (0x02u)
#define Comp_1_INTR_BOTH          (0x03u)

/* Constants for Comp_1_SetHysteresis(), hysteresis parameter */
#define Comp_1_HYST_ENABLE        (0x00u)
#define Comp_1_HYST_DISABLE       (0x01u)

/* Constants for Comp_1_ZeroCal() */
#define Comp_1_TRIMA_MASK         (0x1Fu)
#define Comp_1_TRIMA_SIGNBIT      (4u)
#define Comp_1_TRIMA_MAX_VALUE    (15u)
#define Comp_1_TRIMB_MASK         (0x1Fu)
#define Comp_1_TRIMB_SHIFT        (8u)
#define Comp_1_TRIMB_SIGNBIT      (4u)
#define Comp_1_TRIMB_MAX_VALUE    (15u)

/* Constants for Comp_1_GetInterruptSource() and 
* Comp_1_ClearInterrupt(), interruptMask parameter 
*/
#define Comp_1_INTR_SHIFT         (Comp_1_cy_psoc4_lpcomp_1__LPCOMP_INTR_SHIFT)
#define Comp_1_INTR               ((uint32)0x01u << Comp_1_INTR_SHIFT)

/* Constants for Comp_1_SetInterrupt(), interruptMask parameter */
#define Comp_1_INTR_SET_SHIFT     (Comp_1_cy_psoc4_lpcomp_1__LPCOMP_INTR_SET_SHIFT)
#define Comp_1_INTR_SET           ((uint32)0x01u << Comp_1_INTR_SHIFT)

#if(Comp_1_CY_LPCOMP_V2)
    /* Constants for Comp_1_GetInterruptMask() and 
    * Comp_1_SetInterruptMask(), interruptMask parameter 
    */
    #define Comp_1_INTR_MASK_SHIFT    (Comp_1_cy_psoc4_lpcomp_1__LPCOMP_INTR_MASK_SHIFT)
    #define Comp_1_INTR_MASK          ((uint32)0x01u << Comp_1_INTR_MASK_SHIFT)

    /* Constants for Comp_1_GetInterruptSourceMasked() */ 
    #define Comp_1_INTR_MASKED_SHIFT  (Comp_1_cy_psoc4_lpcomp_1__LPCOMP_INTR_MASKED_SHIFT)
    #define Comp_1_INTR_MASKED        ((uint32)0x01u << Comp_1_INTR_MASKED_SHIFT)
#endif /* (Comp_1_CY_LPCOMP_V2) */


/***************************************
* Enumerated Types and Parameters 
***************************************/

/* Enumerated Types LPCompSpeedType, Used in parameter Speed */
#define Comp_1__LPC_LOW_SPEED 2
#define Comp_1__LPC_MED_SPEED 0
#define Comp_1__LPC_HIGH_SPEED 1


/* Enumerated Types LPCompInterruptType, Used in parameter Interrupt */
#define Comp_1__LPC_INT_DISABLE 0
#define Comp_1__LPC_INT_RISING 1
#define Comp_1__LPC_INT_FALLING 2
#define Comp_1__LPC_INT_BOTH 3


/* Enumerated Types LPCompHysteresisType, Used in parameter Hysteresis */
#define Comp_1__LPC_DISABLE_HYST 1
#define Comp_1__LPC_ENABLE_HYST 0


/* Enumerated Types OutputModeType, Used in parameter OutputMode */
#define Comp_1__OUT_MODE_SYNC 1
#define Comp_1__OUT_MODE_DIRECT 2
#define Comp_1__OUT_MODE_PULSE 0



/***************************************
*   Initial Parameter Constants
****************************************/

#define Comp_1_INTERRUPT    (3u)
#define Comp_1_SPEED        (1u)
#define Comp_1_HYSTERESIS   (1u)
#if (Comp_1_CY_LPCOMP_V2)
    #define Comp_1_OUT_MODE       (2u)
    #define Comp_1_INTERRUPT_EN   (0u)
#endif /* (Comp_1_CY_LPCOMP_V2) */


/**************************************
*             Registers
**************************************/

#define Comp_1_CONFIG_REG     (*(reg32 *)Comp_1_cy_psoc4_lpcomp_1__LPCOMP_CONFIG)
#define Comp_1_CONFIG_PTR     ( (reg32 *)Comp_1_cy_psoc4_lpcomp_1__LPCOMP_CONFIG)

#define Comp_1_DFT_REG        (*(reg32 *)CYREG_LPCOMP_DFT)
#define Comp_1_DFT_PTR        ( (reg32 *)CYREG_LPCOMP_DFT)

#define Comp_1_INTR_REG       (*(reg32 *)Comp_1_cy_psoc4_lpcomp_1__LPCOMP_INTR)
#define Comp_1_INTR_PTR       ( (reg32 *)Comp_1_cy_psoc4_lpcomp_1__LPCOMP_INTR)

#define Comp_1_INTR_SET_REG   (*(reg32 *)Comp_1_cy_psoc4_lpcomp_1__LPCOMP_INTR_SET)
#define Comp_1_INTR_SET_PTR   ( (reg32 *)Comp_1_cy_psoc4_lpcomp_1__LPCOMP_INTR_SET)

#define Comp_1_TRIMA_REG      (*(reg32 *)Comp_1_cy_psoc4_lpcomp_1__TRIM_A)
#define Comp_1_TRIMA_PTR      ( (reg32 *)Comp_1_cy_psoc4_lpcomp_1__TRIM_A)

#define Comp_1_TRIMB_REG      (*(reg32 *)Comp_1_cy_psoc4_lpcomp_1__TRIM_B)
#define Comp_1_TRIMB_PTR      ( (reg32 *)Comp_1_cy_psoc4_lpcomp_1__TRIM_B)

#if(Comp_1_CY_LPCOMP_V2)
    #define Comp_1_INTR_MASK_REG    (*(reg32 *)Comp_1_cy_psoc4_lpcomp_1__LPCOMP_INTR_MASK) 
    #define Comp_1_INTR_MASK_PTR    ( (reg32 *)Comp_1_cy_psoc4_lpcomp_1__LPCOMP_INTR_MASK) 

    #define Comp_1_INTR_MASKED_REG  (*(reg32 *)Comp_1_cy_psoc4_lpcomp_1__LPCOMP_INTR_MASKED) 
    #define Comp_1_INTR_MASKED_PTR  ( (reg32 *)Comp_1_cy_psoc4_lpcomp_1__LPCOMP_INTR_MASKED) 
#endif /* (Comp_1_CY_LPCOMP_V2) */


/***************************************
*        Registers Constants
***************************************/

#define Comp_1_CONFIG_REG_SHIFT           (Comp_1_cy_psoc4_lpcomp_1__LPCOMP_CONFIG_SHIFT)

/* Comp_1Comp_1_CONFIG_REG */
#define Comp_1_CONFIG_SPEED_MODE_SHIFT    (0u)    /* [1:0]    Operating mode for the comparator      */
#define Comp_1_CONFIG_HYST_SHIFT          (2u)    /* [2]      Add 10mV hysteresis to the comparator: 0-enable, 1-disable */
#define Comp_1_CONFIG_INTR_SHIFT          (4u)    /* [5:4]    Sets Pulse/Interrupt mode              */
#define Comp_1_CONFIG_OUT_SHIFT           (6u)    /* [6]      Current output value of the comparator    */
#define Comp_1_CONFIG_EN_SHIFT            (7u)    /* [7]      Enable comparator */
#if(Comp_1_CY_LPCOMP_V2)
    #define Comp_1_CONFIG_DSI_BYPASS_SHIFT    (16u)   /* [16]   Bypass comparator output synchronization for DSI output  */
    #define Comp_1_CONFIG_DSI_LEVEL_SHIFT     (17u)   /* [17]   Comparator DSI (trigger) out level: 0-pulse, 1-level  */
#endif /* (Comp_1_CY_LPCOMP_V2) */

#define Comp_1_CONFIG_SPEED_MODE_MASK     (((uint32) 0x03u << Comp_1_CONFIG_SPEED_MODE_SHIFT) << \
                                                    Comp_1_CONFIG_REG_SHIFT)

#define Comp_1_CONFIG_HYST                (((uint32) 0x01u << Comp_1_CONFIG_HYST_SHIFT) << \
                                                    Comp_1_CONFIG_REG_SHIFT)

#define Comp_1_CONFIG_INTR_MASK           (((uint32) 0x03u << Comp_1_CONFIG_INTR_SHIFT) << \
                                                    Comp_1_CONFIG_REG_SHIFT)

#define Comp_1_CONFIG_OUT                 (((uint32) 0x01u << Comp_1_CONFIG_OUT_SHIFT) << \
                                                    Comp_1_CONFIG_REG_SHIFT)

#define Comp_1_CONFIG_EN                  (((uint32) 0x01u << Comp_1_CONFIG_EN_SHIFT) << \
                                                    Comp_1_CONFIG_REG_SHIFT)
#if(Comp_1_CY_LPCOMP_V2)
    #define Comp_1_CONFIG_DSI_BYPASS          (((uint32) 0x01u << Comp_1_CONFIG_DSI_BYPASS_SHIFT) << \
                                                        (Comp_1_CONFIG_REG_SHIFT/2))

    #define Comp_1_CONFIG_DSI_LEVEL           (((uint32) 0x01u << Comp_1_CONFIG_DSI_LEVEL_SHIFT) << \
                                                        (Comp_1_CONFIG_REG_SHIFT/2))
#endif /* (Comp_1_CY_LPCOMP_V2) */


/* Comp_1Comp_1_DFT_REG */
#define Comp_1_DFT_CAL_EN_SHIFT    (0u)    /* [0] Calibration enable */

#define Comp_1_DFT_CAL_EN          ((uint32) 0x01u << Comp_1_DFT_CAL_EN_SHIFT)


/***************************************
*       Init Macros Definitions
***************************************/

#define Comp_1_GET_CONFIG_SPEED_MODE(mode)    ((uint32) ((((uint32) (mode) << Comp_1_CONFIG_SPEED_MODE_SHIFT) << \
                                                            Comp_1_CONFIG_REG_SHIFT) & \
                                                            Comp_1_CONFIG_SPEED_MODE_MASK))

#define Comp_1_GET_CONFIG_HYST(hysteresis)    ((0u != (hysteresis)) ? (Comp_1_CONFIG_HYST) : (0u))

#define Comp_1_GET_CONFIG_INTR(intType)   ((uint32) ((((uint32)(intType) << Comp_1_CONFIG_INTR_SHIFT) << \
                                                    Comp_1_CONFIG_REG_SHIFT) & \
                                                    Comp_1_CONFIG_INTR_MASK))
#if(Comp_1_CY_LPCOMP_V2)
    #define Comp_1_GET_CONFIG_DSI_BYPASS(bypass)  ((0u != ((bypass) & Comp_1_OUT_DIRECT)) ? \
                                                                    (Comp_1_CONFIG_DSI_BYPASS) : (0u))
   
    #define Comp_1_GET_CONFIG_DSI_LEVEL(level)    ((0u != ((level) & Comp_1_OUT_SYNC)) ? \
                                                                    (Comp_1_CONFIG_DSI_LEVEL) : (0u))
    
    #define Comp_1_GET_INTR_MASK(mask)            ((0u != (mask)) ? (Comp_1_INTR_MASK) : (0u))
#endif /* (Comp_1_CY_LPCOMP_V2) */

#if(Comp_1_CY_LPCOMP_V0)
    #define Comp_1_CONFIG_REG_DEFAULT (Comp_1_GET_CONFIG_SPEED_MODE(Comp_1_SPEED) |\
                                                 Comp_1_GET_CONFIG_HYST(Comp_1_HYSTERESIS))
#else
    #define Comp_1_CONFIG_REG_DEFAULT (Comp_1_GET_CONFIG_SPEED_MODE(Comp_1_SPEED) |\
                                                 Comp_1_GET_CONFIG_HYST(Comp_1_HYSTERESIS)  |\
                                                 Comp_1_GET_CONFIG_DSI_BYPASS(Comp_1_OUT_MODE) |\
                                                 Comp_1_GET_CONFIG_DSI_LEVEL(Comp_1_OUT_MODE))
#endif /* (Comp_1_CY_LPCOMP_V0) */

#if(Comp_1_CY_LPCOMP_V2)
    #define Comp_1_INTR_MASK_REG_DEFAULT  (Comp_1_GET_INTR_MASK(Comp_1_INTERRUPT_EN))
#endif /* (Comp_1_CY_LPCOMP_V2) */


/***************************************
* The following code is DEPRECATED and 
* should not be used in new projects.
***************************************/

#define Comp_1_CONFIG_FILT_SHIFT          (3u)    
#define Comp_1_CONFIG_FILT                ((uint32)((uint32)((uint32)0x01u << \
                                                    Comp_1_CONFIG_FILT_SHIFT) << Comp_1_CONFIG_REG_SHIFT))

#define Comp_1_DIGITAL_FILTER             (0u)

/* Comp_1_SetFilter() parameters */
#define Comp_1_FILT_DISABLE               (0x00u)
#define Comp_1_FILT_ENABLE                (0x01u)

/* Comp_1_SetSpeed() parameters */
#define Comp_1_MEDSPEED                   (Comp_1_MED_SPEED)
#define Comp_1_HIGHSPEED                  (Comp_1_HIGH_SPEED)
#define Comp_1_LOWSPEED                   (Comp_1_LOW_SPEED)

void    Comp_1_SetFilter(uint32 filter);

#endif    /* CY_COMPARATOR_Comp_1_H */


/* [] END OF FILE */
=======
/*******************************************************************************
* File Name: Comp_1.h
* Version 2.20
*
* Description:
*  This file contains the function prototypes and constants used in
*  the Low Power Comparator component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_COMPARATOR_Comp_1_H)
#define CY_COMPARATOR_Comp_1_H

#include "cytypes.h"
#include "cyfitter.h"


extern uint8  Comp_1_initVar;


/***************************************
*  Conditional Compilation Parameters
****************************************/

#define Comp_1_CY_LPCOMP_V0 (CYIPBLOCK_m0s8lpcomp_VERSION == 0u) 
#define Comp_1_CY_LPCOMP_V2 (CYIPBLOCK_m0s8lpcomp_VERSION >= 2u) 


/**************************************
*        Function Prototypes
**************************************/

void    Comp_1_Start(void);
void    Comp_1_Init(void);
void    Comp_1_Enable(void);
void    Comp_1_Stop(void);
void    Comp_1_SetSpeed(uint32 speed);
void    Comp_1_SetInterruptMode(uint32 mode);
uint32  Comp_1_GetInterruptSource(void);
void    Comp_1_ClearInterrupt(uint32 interruptMask);
void    Comp_1_SetInterrupt(uint32 interruptMask);
void    Comp_1_SetHysteresis(uint32 hysteresis);
uint32  Comp_1_GetCompare(void);
uint32  Comp_1_ZeroCal(void);
void    Comp_1_LoadTrim(uint32 trimVal);
void    Comp_1_Sleep(void);
void    Comp_1_Wakeup(void);
void    Comp_1_SaveConfig(void);
void    Comp_1_RestoreConfig(void);
#if(Comp_1_CY_LPCOMP_V2)
    void    Comp_1_SetOutputMode(uint32 mode);
    void    Comp_1_SetInterruptMask(uint32 interruptMask);
    uint32  Comp_1_GetInterruptMask(void);
    uint32  Comp_1_GetInterruptSourceMasked(void);
#endif /* (Comp_1_CY_LPCOMP_V2) */


/**************************************
*           API Constants
**************************************/

#if(Comp_1_CY_LPCOMP_V2)
    /* Constants for Comp_1_SetOutputMode(), mode parameter */
    #define Comp_1_OUT_PULSE      (0x00u)
    #define Comp_1_OUT_SYNC       (0x01u)
    #define Comp_1_OUT_DIRECT     (0x02u)
#endif /* (Comp_1_CY_LPCOMP_V2) */

#define Comp_1_INTR_PARAM_MASK    (0x03u)
#define Comp_1_SPEED_PARAM_MASK   (0x03u)

/* Constants for Comp_1_SetSpeed(), speed parameter */
#define Comp_1_MED_SPEED          (0x00u)
#define Comp_1_HIGH_SPEED         (0x01u)
#define Comp_1_LOW_SPEED          (0x02u)

/* Constants for Comp_1_SetInterruptMode(), mode parameter */
#define Comp_1_INTR_DISABLE       (0x00u)
#define Comp_1_INTR_RISING        (0x01u)
#define Comp_1_INTR_FALLING       (0x02u)
#define Comp_1_INTR_BOTH          (0x03u)

/* Constants for Comp_1_SetHysteresis(), hysteresis parameter */
#define Comp_1_HYST_ENABLE        (0x00u)
#define Comp_1_HYST_DISABLE       (0x01u)

/* Constants for Comp_1_ZeroCal() */
#define Comp_1_TRIMA_MASK         (0x1Fu)
#define Comp_1_TRIMA_SIGNBIT      (4u)
#define Comp_1_TRIMA_MAX_VALUE    (15u)
#define Comp_1_TRIMB_MASK         (0x1Fu)
#define Comp_1_TRIMB_SHIFT        (8u)
#define Comp_1_TRIMB_SIGNBIT      (4u)
#define Comp_1_TRIMB_MAX_VALUE    (15u)

/* Constants for Comp_1_GetInterruptSource() and 
* Comp_1_ClearInterrupt(), interruptMask parameter 
*/
#define Comp_1_INTR_SHIFT         (Comp_1_cy_psoc4_lpcomp_1__LPCOMP_INTR_SHIFT)
#define Comp_1_INTR               ((uint32)0x01u << Comp_1_INTR_SHIFT)

/* Constants for Comp_1_SetInterrupt(), interruptMask parameter */
#define Comp_1_INTR_SET_SHIFT     (Comp_1_cy_psoc4_lpcomp_1__LPCOMP_INTR_SET_SHIFT)
#define Comp_1_INTR_SET           ((uint32)0x01u << Comp_1_INTR_SHIFT)

#if(Comp_1_CY_LPCOMP_V2)
    /* Constants for Comp_1_GetInterruptMask() and 
    * Comp_1_SetInterruptMask(), interruptMask parameter 
    */
    #define Comp_1_INTR_MASK_SHIFT    (Comp_1_cy_psoc4_lpcomp_1__LPCOMP_INTR_MASK_SHIFT)
    #define Comp_1_INTR_MASK          ((uint32)0x01u << Comp_1_INTR_MASK_SHIFT)

    /* Constants for Comp_1_GetInterruptSourceMasked() */ 
    #define Comp_1_INTR_MASKED_SHIFT  (Comp_1_cy_psoc4_lpcomp_1__LPCOMP_INTR_MASKED_SHIFT)
    #define Comp_1_INTR_MASKED        ((uint32)0x01u << Comp_1_INTR_MASKED_SHIFT)
#endif /* (Comp_1_CY_LPCOMP_V2) */


/***************************************
* Enumerated Types and Parameters 
***************************************/

/* Enumerated Types LPCompSpeedType, Used in parameter Speed */
#define Comp_1__LPC_LOW_SPEED 2
#define Comp_1__LPC_MED_SPEED 0
#define Comp_1__LPC_HIGH_SPEED 1


/* Enumerated Types LPCompInterruptType, Used in parameter Interrupt */
#define Comp_1__LPC_INT_DISABLE 0
#define Comp_1__LPC_INT_RISING 1
#define Comp_1__LPC_INT_FALLING 2
#define Comp_1__LPC_INT_BOTH 3


/* Enumerated Types LPCompHysteresisType, Used in parameter Hysteresis */
#define Comp_1__LPC_DISABLE_HYST 1
#define Comp_1__LPC_ENABLE_HYST 0


/* Enumerated Types OutputModeType, Used in parameter OutputMode */
#define Comp_1__OUT_MODE_SYNC 1
#define Comp_1__OUT_MODE_DIRECT 2
#define Comp_1__OUT_MODE_PULSE 0



/***************************************
*   Initial Parameter Constants
****************************************/

#define Comp_1_INTERRUPT    (3u)
#define Comp_1_SPEED        (1u)
#define Comp_1_HYSTERESIS   (1u)
#if (Comp_1_CY_LPCOMP_V2)
    #define Comp_1_OUT_MODE       (2u)
    #define Comp_1_INTERRUPT_EN   (0u)
#endif /* (Comp_1_CY_LPCOMP_V2) */


/**************************************
*             Registers
**************************************/

#define Comp_1_CONFIG_REG     (*(reg32 *)Comp_1_cy_psoc4_lpcomp_1__LPCOMP_CONFIG)
#define Comp_1_CONFIG_PTR     ( (reg32 *)Comp_1_cy_psoc4_lpcomp_1__LPCOMP_CONFIG)

#define Comp_1_DFT_REG        (*(reg32 *)CYREG_LPCOMP_DFT)
#define Comp_1_DFT_PTR        ( (reg32 *)CYREG_LPCOMP_DFT)

#define Comp_1_INTR_REG       (*(reg32 *)Comp_1_cy_psoc4_lpcomp_1__LPCOMP_INTR)
#define Comp_1_INTR_PTR       ( (reg32 *)Comp_1_cy_psoc4_lpcomp_1__LPCOMP_INTR)

#define Comp_1_INTR_SET_REG   (*(reg32 *)Comp_1_cy_psoc4_lpcomp_1__LPCOMP_INTR_SET)
#define Comp_1_INTR_SET_PTR   ( (reg32 *)Comp_1_cy_psoc4_lpcomp_1__LPCOMP_INTR_SET)

#define Comp_1_TRIMA_REG      (*(reg32 *)Comp_1_cy_psoc4_lpcomp_1__TRIM_A)
#define Comp_1_TRIMA_PTR      ( (reg32 *)Comp_1_cy_psoc4_lpcomp_1__TRIM_A)

#define Comp_1_TRIMB_REG      (*(reg32 *)Comp_1_cy_psoc4_lpcomp_1__TRIM_B)
#define Comp_1_TRIMB_PTR      ( (reg32 *)Comp_1_cy_psoc4_lpcomp_1__TRIM_B)

#if(Comp_1_CY_LPCOMP_V2)
    #define Comp_1_INTR_MASK_REG    (*(reg32 *)Comp_1_cy_psoc4_lpcomp_1__LPCOMP_INTR_MASK) 
    #define Comp_1_INTR_MASK_PTR    ( (reg32 *)Comp_1_cy_psoc4_lpcomp_1__LPCOMP_INTR_MASK) 

    #define Comp_1_INTR_MASKED_REG  (*(reg32 *)Comp_1_cy_psoc4_lpcomp_1__LPCOMP_INTR_MASKED) 
    #define Comp_1_INTR_MASKED_PTR  ( (reg32 *)Comp_1_cy_psoc4_lpcomp_1__LPCOMP_INTR_MASKED) 
#endif /* (Comp_1_CY_LPCOMP_V2) */


/***************************************
*        Registers Constants
***************************************/

#define Comp_1_CONFIG_REG_SHIFT           (Comp_1_cy_psoc4_lpcomp_1__LPCOMP_CONFIG_SHIFT)

/* Comp_1Comp_1_CONFIG_REG */
#define Comp_1_CONFIG_SPEED_MODE_SHIFT    (0u)    /* [1:0]    Operating mode for the comparator      */
#define Comp_1_CONFIG_HYST_SHIFT          (2u)    /* [2]      Add 10mV hysteresis to the comparator: 0-enable, 1-disable */
#define Comp_1_CONFIG_INTR_SHIFT          (4u)    /* [5:4]    Sets Pulse/Interrupt mode              */
#define Comp_1_CONFIG_OUT_SHIFT           (6u)    /* [6]      Current output value of the comparator    */
#define Comp_1_CONFIG_EN_SHIFT            (7u)    /* [7]      Enable comparator */
#if(Comp_1_CY_LPCOMP_V2)
    #define Comp_1_CONFIG_DSI_BYPASS_SHIFT    (16u)   /* [16]   Bypass comparator output synchronization for DSI output  */
    #define Comp_1_CONFIG_DSI_LEVEL_SHIFT     (17u)   /* [17]   Comparator DSI (trigger) out level: 0-pulse, 1-level  */
#endif /* (Comp_1_CY_LPCOMP_V2) */

#define Comp_1_CONFIG_SPEED_MODE_MASK     (((uint32) 0x03u << Comp_1_CONFIG_SPEED_MODE_SHIFT) << \
                                                    Comp_1_CONFIG_REG_SHIFT)

#define Comp_1_CONFIG_HYST                (((uint32) 0x01u << Comp_1_CONFIG_HYST_SHIFT) << \
                                                    Comp_1_CONFIG_REG_SHIFT)

#define Comp_1_CONFIG_INTR_MASK           (((uint32) 0x03u << Comp_1_CONFIG_INTR_SHIFT) << \
                                                    Comp_1_CONFIG_REG_SHIFT)

#define Comp_1_CONFIG_OUT                 (((uint32) 0x01u << Comp_1_CONFIG_OUT_SHIFT) << \
                                                    Comp_1_CONFIG_REG_SHIFT)

#define Comp_1_CONFIG_EN                  (((uint32) 0x01u << Comp_1_CONFIG_EN_SHIFT) << \
                                                    Comp_1_CONFIG_REG_SHIFT)
#if(Comp_1_CY_LPCOMP_V2)
    #define Comp_1_CONFIG_DSI_BYPASS          (((uint32) 0x01u << Comp_1_CONFIG_DSI_BYPASS_SHIFT) << \
                                                        (Comp_1_CONFIG_REG_SHIFT/2))

    #define Comp_1_CONFIG_DSI_LEVEL           (((uint32) 0x01u << Comp_1_CONFIG_DSI_LEVEL_SHIFT) << \
                                                        (Comp_1_CONFIG_REG_SHIFT/2))
#endif /* (Comp_1_CY_LPCOMP_V2) */


/* Comp_1Comp_1_DFT_REG */
#define Comp_1_DFT_CAL_EN_SHIFT    (0u)    /* [0] Calibration enable */

#define Comp_1_DFT_CAL_EN          ((uint32) 0x01u << Comp_1_DFT_CAL_EN_SHIFT)


/***************************************
*       Init Macros Definitions
***************************************/

#define Comp_1_GET_CONFIG_SPEED_MODE(mode)    ((uint32) ((((uint32) (mode) << Comp_1_CONFIG_SPEED_MODE_SHIFT) << \
                                                            Comp_1_CONFIG_REG_SHIFT) & \
                                                            Comp_1_CONFIG_SPEED_MODE_MASK))

#define Comp_1_GET_CONFIG_HYST(hysteresis)    ((0u != (hysteresis)) ? (Comp_1_CONFIG_HYST) : (0u))

#define Comp_1_GET_CONFIG_INTR(intType)   ((uint32) ((((uint32)(intType) << Comp_1_CONFIG_INTR_SHIFT) << \
                                                    Comp_1_CONFIG_REG_SHIFT) & \
                                                    Comp_1_CONFIG_INTR_MASK))
#if(Comp_1_CY_LPCOMP_V2)
    #define Comp_1_GET_CONFIG_DSI_BYPASS(bypass)  ((0u != ((bypass) & Comp_1_OUT_DIRECT)) ? \
                                                                    (Comp_1_CONFIG_DSI_BYPASS) : (0u))
   
    #define Comp_1_GET_CONFIG_DSI_LEVEL(level)    ((0u != ((level) & Comp_1_OUT_SYNC)) ? \
                                                                    (Comp_1_CONFIG_DSI_LEVEL) : (0u))
    
    #define Comp_1_GET_INTR_MASK(mask)            ((0u != (mask)) ? (Comp_1_INTR_MASK) : (0u))
#endif /* (Comp_1_CY_LPCOMP_V2) */

#if(Comp_1_CY_LPCOMP_V0)
    #define Comp_1_CONFIG_REG_DEFAULT (Comp_1_GET_CONFIG_SPEED_MODE(Comp_1_SPEED) |\
                                                 Comp_1_GET_CONFIG_HYST(Comp_1_HYSTERESIS))
#else
    #define Comp_1_CONFIG_REG_DEFAULT (Comp_1_GET_CONFIG_SPEED_MODE(Comp_1_SPEED) |\
                                                 Comp_1_GET_CONFIG_HYST(Comp_1_HYSTERESIS)  |\
                                                 Comp_1_GET_CONFIG_DSI_BYPASS(Comp_1_OUT_MODE) |\
                                                 Comp_1_GET_CONFIG_DSI_LEVEL(Comp_1_OUT_MODE))
#endif /* (Comp_1_CY_LPCOMP_V0) */

#if(Comp_1_CY_LPCOMP_V2)
    #define Comp_1_INTR_MASK_REG_DEFAULT  (Comp_1_GET_INTR_MASK(Comp_1_INTERRUPT_EN))
#endif /* (Comp_1_CY_LPCOMP_V2) */


/***************************************
* The following code is DEPRECATED and 
* should not be used in new projects.
***************************************/

#define Comp_1_CONFIG_FILT_SHIFT          (3u)    
#define Comp_1_CONFIG_FILT                ((uint32)((uint32)((uint32)0x01u << \
                                                    Comp_1_CONFIG_FILT_SHIFT) << Comp_1_CONFIG_REG_SHIFT))

#define Comp_1_DIGITAL_FILTER             (0u)

/* Comp_1_SetFilter() parameters */
#define Comp_1_FILT_DISABLE               (0x00u)
#define Comp_1_FILT_ENABLE                (0x01u)

/* Comp_1_SetSpeed() parameters */
#define Comp_1_MEDSPEED                   (Comp_1_MED_SPEED)
#define Comp_1_HIGHSPEED                  (Comp_1_HIGH_SPEED)
#define Comp_1_LOWSPEED                   (Comp_1_LOW_SPEED)

void    Comp_1_SetFilter(uint32 filter);

#endif    /* CY_COMPARATOR_Comp_1_H */


/* [] END OF FILE */
>>>>>>> remotes/origin/master
