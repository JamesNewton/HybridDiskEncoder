<<<<<<< HEAD
/*******************************************************************************
* File Name: ADC_3_Buffer.h
* Version 1.20
*
* Description:
*  This file contains the function prototypes and constants used in
*  the Opamp (Analog Buffer) Component.
*
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#if !defined(CY_OPAMP_ADC_3_Buffer_H)
#define CY_OPAMP_ADC_3_Buffer_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*       Type Definitions
***************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} ADC_3_Buffer_BACKUP_STRUCT;


/**************************************
*        Function Prototypes
**************************************/
void ADC_3_Buffer_Init(void);
void ADC_3_Buffer_Enable(void);
void ADC_3_Buffer_Start(void);
void ADC_3_Buffer_Stop(void);
void ADC_3_Buffer_SetPower(uint32 power);
void ADC_3_Buffer_PumpControl(uint32 onOff);
void ADC_3_Buffer_Sleep(void);
void ADC_3_Buffer_Wakeup(void);
void ADC_3_Buffer_SaveConfig(void);
void ADC_3_Buffer_RestoreConfig(void);


/**************************************
*           API Constants
**************************************/

/* Parameters for SetPower() function */
#define ADC_3_Buffer_LOW_POWER      (1u)
#define ADC_3_Buffer_MED_POWER      (2u)
#define ADC_3_Buffer_HIGH_POWER     (3u)


/* Parameters for PumpControl() function */
#define ADC_3_Buffer_PUMP_ON        (1u)
#define ADC_3_Buffer_PUMP_OFF       (0u)


/***************************************
*   Initial Parameter Constants
****************************************/

#define ADC_3_Buffer_OUTPUT_CURRENT         (0u)
#define ADC_3_Buffer_POWER                  (3u)
#define ADC_3_Buffer_MODE                   (1u)
#define ADC_3_Buffer_OA_COMP_TRIM_VALUE     (3u)
#define ADC_3_Buffer_DEEPSLEEP_SUPPORT      (0u)


/***************************************
*    Variables with External Linkage
***************************************/

extern uint8  ADC_3_Buffer_initVar;


/**************************************
*             Registers
**************************************/

#ifdef CYIPBLOCK_m0s8pass4b_VERSION
    #define ADC_3_Buffer_CTB_CTRL_REG       (*(reg32 *) ADC_3_Buffer_cy_psoc4_abuf__CTB_CTB_CTRL)
    #define ADC_3_Buffer_CTB_CTRL_PTR       ( (reg32 *) ADC_3_Buffer_cy_psoc4_abuf__CTB_CTB_CTRL)
#else
    #define ADC_3_Buffer_CTB_CTRL_REG       (*(reg32 *) ADC_3_Buffer_cy_psoc4_abuf__CTBM_CTB_CTRL)
    #define ADC_3_Buffer_CTB_CTRL_PTR       ( (reg32 *) ADC_3_Buffer_cy_psoc4_abuf__CTBM_CTB_CTRL)
#endif /* CYIPBLOCK_m0s8pass4b_VERSION */

#define ADC_3_Buffer_OA_RES_CTRL_REG    (*(reg32 *) ADC_3_Buffer_cy_psoc4_abuf__OA_RES_CTRL)
#define ADC_3_Buffer_OA_RES_CTRL_PTR    ( (reg32 *) ADC_3_Buffer_cy_psoc4_abuf__OA_RES_CTRL)
#define ADC_3_Buffer_OA_COMP_TRIM_REG   (*(reg32 *) ADC_3_Buffer_cy_psoc4_abuf__OA_COMP_TRIM)
#define ADC_3_Buffer_OA_COMP_TRIM_PTR   ( (reg32 *) ADC_3_Buffer_cy_psoc4_abuf__OA_COMP_TRIM)


/***************************************
*        Registers Constants
***************************************/

/* ADC_3_Buffer_CTB_CTRL_REG */
#define ADC_3_Buffer_CTB_CTRL_DEEPSLEEP_ON_SHIFT    (30u)   /* [30] Selects behavior CTB IP in the DeepSleep power mode */
#define ADC_3_Buffer_CTB_CTRL_ENABLED_SHIFT         (31u)   /* [31] Enable of the CTB IP */


#define ADC_3_Buffer_CTB_CTRL_DEEPSLEEP_ON          ((uint32) 0x01u << ADC_3_Buffer_CTB_CTRL_DEEPSLEEP_ON_SHIFT)
#define ADC_3_Buffer_CTB_CTRL_ENABLED               ((uint32) 0x01u << ADC_3_Buffer_CTB_CTRL_ENABLED_SHIFT)


/* ADC_3_Buffer_OA_RES_CTRL_REG */
#define ADC_3_Buffer_OA_PWR_MODE_SHIFT          (0u)    /* [1:0]    Power level */
#define ADC_3_Buffer_OA_DRIVE_STR_SEL_SHIFT     (2u)    /* [2]      Opamp output strenght select: 0 - 1x, 1 - 10x */
#define ADC_3_Buffer_OA_COMP_EN_SHIFT           (4u)    /* [4]      CTB IP mode: 0 - Opamp, 1 - Comparator  */
#define ADC_3_Buffer_OA_PUMP_EN_SHIFT           (11u)   /* [11]     Pump enable */


#define ADC_3_Buffer_OA_PWR_MODE                ((uint32) 0x02u << ADC_3_Buffer_OA_PWR_MODE_SHIFT)
#define ADC_3_Buffer_OA_PWR_MODE_MASK           ((uint32) 0x03u << ADC_3_Buffer_OA_PWR_MODE_SHIFT)
#define ADC_3_Buffer_OA_DRIVE_STR_SEL_1X        ((uint32) 0x00u << ADC_3_Buffer_OA_DRIVE_STR_SEL_SHIFT)
#define ADC_3_Buffer_OA_DRIVE_STR_SEL_10X       ((uint32) 0x01u << ADC_3_Buffer_OA_DRIVE_STR_SEL_SHIFT)
#define ADC_3_Buffer_OA_DRIVE_STR_SEL_MASK      ((uint32) 0x01u << ADC_3_Buffer_OA_DRIVE_STR_SEL_SHIFT)
#define ADC_3_Buffer_OA_COMP_EN                 ((uint32) 0x00u << ADC_3_Buffer_OA_COMP_EN_SHIFT)
#define ADC_3_Buffer_OA_PUMP_EN                 ((uint32) 0x01u << ADC_3_Buffer_OA_PUMP_EN_SHIFT)


/***************************************
*       Init Macros Definitions
***************************************/

#define ADC_3_Buffer_GET_DEEPSLEEP_ON(deepSleep)    ((0u != (deepSleep)) ? (ADC_3_Buffer_CTB_CTRL_DEEPSLEEP_ON) : (0u))
#define ADC_3_Buffer_GET_OA_DRIVE_STR(current)      ((0u != (current)) ? (ADC_3_Buffer_OA_DRIVE_STR_SEL_10X) : \
                                                                             (ADC_3_Buffer_OA_DRIVE_STR_SEL_1X))
#define ADC_3_Buffer_GET_OA_PWR_MODE(mode)          ((mode) & ADC_3_Buffer_OA_PWR_MODE_MASK)
#define ADC_3_Buffer_CHECK_PWR_MODE_OFF             (0u != (ADC_3_Buffer_OA_RES_CTRL_REG & \
                                                                ADC_3_Buffer_OA_PWR_MODE_MASK))

/* Returns true if component available in Deep Sleep power mode*/ 
#define ADC_3_Buffer_CHECK_DEEPSLEEP_SUPPORT        (0u != ADC_3_Buffer_DEEPSLEEP_SUPPORT) 

#define ADC_3_Buffer_DEFAULT_CTB_CTRL (ADC_3_Buffer_GET_DEEPSLEEP_ON(ADC_3_Buffer_DEEPSLEEP_SUPPORT) | \
                                           ADC_3_Buffer_CTB_CTRL_ENABLED)

#define ADC_3_Buffer_DEFAULT_OA_RES_CTRL (ADC_3_Buffer_OA_COMP_EN | \
                                              ADC_3_Buffer_GET_OA_DRIVE_STR(ADC_3_Buffer_OUTPUT_CURRENT))

#define ADC_3_Buffer_DEFAULT_OA_COMP_TRIM_REG (ADC_3_Buffer_OA_COMP_TRIM_VALUE)


/***************************************
* The following code is DEPRECATED and 
* should not be used in new projects.
***************************************/

#define ADC_3_Buffer_LOWPOWER                   (ADC_3_Buffer_LOW_POWER)
#define ADC_3_Buffer_MEDPOWER                   (ADC_3_Buffer_MED_POWER)
#define ADC_3_Buffer_HIGHPOWER                  (ADC_3_Buffer_HIGH_POWER)

/* PUMP ON/OFF defines */
#define ADC_3_Buffer_PUMPON                     (ADC_3_Buffer_PUMP_ON)
#define ADC_3_Buffer_PUMPOFF                    (ADC_3_Buffer_PUMP_OFF)

#define ADC_3_Buffer_OA_CTRL                    (ADC_3_Buffer_CTB_CTRL_REG)
#define ADC_3_Buffer_OA_RES_CTRL                (ADC_3_Buffer_OA_RES_CTRL_REG)

/* Bit Field  OA_CTRL */
#define ADC_3_Buffer_OA_CTB_EN_SHIFT            (ADC_3_Buffer_CTB_CTRL_ENABLED_SHIFT)
#define ADC_3_Buffer_OA_PUMP_CTRL_SHIFT         (ADC_3_Buffer_OA_PUMP_EN_SHIFT)
#define ADC_3_Buffer_OA_PUMP_EN_MASK            (0x800u)
#define ADC_3_Buffer_PUMP_PROTECT_MASK          (1u)


#endif    /* CY_OPAMP_ADC_3_Buffer_H */


/* [] END OF FILE */
=======
/*******************************************************************************
* File Name: ADC_3_Buffer.h
* Version 1.20
*
* Description:
*  This file contains the function prototypes and constants used in
*  the Opamp (Analog Buffer) Component.
*
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#if !defined(CY_OPAMP_ADC_3_Buffer_H)
#define CY_OPAMP_ADC_3_Buffer_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*       Type Definitions
***************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} ADC_3_Buffer_BACKUP_STRUCT;


/**************************************
*        Function Prototypes
**************************************/
void ADC_3_Buffer_Init(void);
void ADC_3_Buffer_Enable(void);
void ADC_3_Buffer_Start(void);
void ADC_3_Buffer_Stop(void);
void ADC_3_Buffer_SetPower(uint32 power);
void ADC_3_Buffer_PumpControl(uint32 onOff);
void ADC_3_Buffer_Sleep(void);
void ADC_3_Buffer_Wakeup(void);
void ADC_3_Buffer_SaveConfig(void);
void ADC_3_Buffer_RestoreConfig(void);


/**************************************
*           API Constants
**************************************/

/* Parameters for SetPower() function */
#define ADC_3_Buffer_LOW_POWER      (1u)
#define ADC_3_Buffer_MED_POWER      (2u)
#define ADC_3_Buffer_HIGH_POWER     (3u)


/* Parameters for PumpControl() function */
#define ADC_3_Buffer_PUMP_ON        (1u)
#define ADC_3_Buffer_PUMP_OFF       (0u)


/***************************************
*   Initial Parameter Constants
****************************************/

#define ADC_3_Buffer_OUTPUT_CURRENT         (0u)
#define ADC_3_Buffer_POWER                  (3u)
#define ADC_3_Buffer_MODE                   (1u)
#define ADC_3_Buffer_OA_COMP_TRIM_VALUE     (3u)
#define ADC_3_Buffer_DEEPSLEEP_SUPPORT      (0u)


/***************************************
*    Variables with External Linkage
***************************************/

extern uint8  ADC_3_Buffer_initVar;


/**************************************
*             Registers
**************************************/

#ifdef CYIPBLOCK_m0s8pass4b_VERSION
    #define ADC_3_Buffer_CTB_CTRL_REG       (*(reg32 *) ADC_3_Buffer_cy_psoc4_abuf__CTB_CTB_CTRL)
    #define ADC_3_Buffer_CTB_CTRL_PTR       ( (reg32 *) ADC_3_Buffer_cy_psoc4_abuf__CTB_CTB_CTRL)
#else
    #define ADC_3_Buffer_CTB_CTRL_REG       (*(reg32 *) ADC_3_Buffer_cy_psoc4_abuf__CTBM_CTB_CTRL)
    #define ADC_3_Buffer_CTB_CTRL_PTR       ( (reg32 *) ADC_3_Buffer_cy_psoc4_abuf__CTBM_CTB_CTRL)
#endif /* CYIPBLOCK_m0s8pass4b_VERSION */

#define ADC_3_Buffer_OA_RES_CTRL_REG    (*(reg32 *) ADC_3_Buffer_cy_psoc4_abuf__OA_RES_CTRL)
#define ADC_3_Buffer_OA_RES_CTRL_PTR    ( (reg32 *) ADC_3_Buffer_cy_psoc4_abuf__OA_RES_CTRL)
#define ADC_3_Buffer_OA_COMP_TRIM_REG   (*(reg32 *) ADC_3_Buffer_cy_psoc4_abuf__OA_COMP_TRIM)
#define ADC_3_Buffer_OA_COMP_TRIM_PTR   ( (reg32 *) ADC_3_Buffer_cy_psoc4_abuf__OA_COMP_TRIM)


/***************************************
*        Registers Constants
***************************************/

/* ADC_3_Buffer_CTB_CTRL_REG */
#define ADC_3_Buffer_CTB_CTRL_DEEPSLEEP_ON_SHIFT    (30u)   /* [30] Selects behavior CTB IP in the DeepSleep power mode */
#define ADC_3_Buffer_CTB_CTRL_ENABLED_SHIFT         (31u)   /* [31] Enable of the CTB IP */


#define ADC_3_Buffer_CTB_CTRL_DEEPSLEEP_ON          ((uint32) 0x01u << ADC_3_Buffer_CTB_CTRL_DEEPSLEEP_ON_SHIFT)
#define ADC_3_Buffer_CTB_CTRL_ENABLED               ((uint32) 0x01u << ADC_3_Buffer_CTB_CTRL_ENABLED_SHIFT)


/* ADC_3_Buffer_OA_RES_CTRL_REG */
#define ADC_3_Buffer_OA_PWR_MODE_SHIFT          (0u)    /* [1:0]    Power level */
#define ADC_3_Buffer_OA_DRIVE_STR_SEL_SHIFT     (2u)    /* [2]      Opamp output strenght select: 0 - 1x, 1 - 10x */
#define ADC_3_Buffer_OA_COMP_EN_SHIFT           (4u)    /* [4]      CTB IP mode: 0 - Opamp, 1 - Comparator  */
#define ADC_3_Buffer_OA_PUMP_EN_SHIFT           (11u)   /* [11]     Pump enable */


#define ADC_3_Buffer_OA_PWR_MODE                ((uint32) 0x02u << ADC_3_Buffer_OA_PWR_MODE_SHIFT)
#define ADC_3_Buffer_OA_PWR_MODE_MASK           ((uint32) 0x03u << ADC_3_Buffer_OA_PWR_MODE_SHIFT)
#define ADC_3_Buffer_OA_DRIVE_STR_SEL_1X        ((uint32) 0x00u << ADC_3_Buffer_OA_DRIVE_STR_SEL_SHIFT)
#define ADC_3_Buffer_OA_DRIVE_STR_SEL_10X       ((uint32) 0x01u << ADC_3_Buffer_OA_DRIVE_STR_SEL_SHIFT)
#define ADC_3_Buffer_OA_DRIVE_STR_SEL_MASK      ((uint32) 0x01u << ADC_3_Buffer_OA_DRIVE_STR_SEL_SHIFT)
#define ADC_3_Buffer_OA_COMP_EN                 ((uint32) 0x00u << ADC_3_Buffer_OA_COMP_EN_SHIFT)
#define ADC_3_Buffer_OA_PUMP_EN                 ((uint32) 0x01u << ADC_3_Buffer_OA_PUMP_EN_SHIFT)


/***************************************
*       Init Macros Definitions
***************************************/

#define ADC_3_Buffer_GET_DEEPSLEEP_ON(deepSleep)    ((0u != (deepSleep)) ? (ADC_3_Buffer_CTB_CTRL_DEEPSLEEP_ON) : (0u))
#define ADC_3_Buffer_GET_OA_DRIVE_STR(current)      ((0u != (current)) ? (ADC_3_Buffer_OA_DRIVE_STR_SEL_10X) : \
                                                                             (ADC_3_Buffer_OA_DRIVE_STR_SEL_1X))
#define ADC_3_Buffer_GET_OA_PWR_MODE(mode)          ((mode) & ADC_3_Buffer_OA_PWR_MODE_MASK)
#define ADC_3_Buffer_CHECK_PWR_MODE_OFF             (0u != (ADC_3_Buffer_OA_RES_CTRL_REG & \
                                                                ADC_3_Buffer_OA_PWR_MODE_MASK))

/* Returns true if component available in Deep Sleep power mode*/ 
#define ADC_3_Buffer_CHECK_DEEPSLEEP_SUPPORT        (0u != ADC_3_Buffer_DEEPSLEEP_SUPPORT) 

#define ADC_3_Buffer_DEFAULT_CTB_CTRL (ADC_3_Buffer_GET_DEEPSLEEP_ON(ADC_3_Buffer_DEEPSLEEP_SUPPORT) | \
                                           ADC_3_Buffer_CTB_CTRL_ENABLED)

#define ADC_3_Buffer_DEFAULT_OA_RES_CTRL (ADC_3_Buffer_OA_COMP_EN | \
                                              ADC_3_Buffer_GET_OA_DRIVE_STR(ADC_3_Buffer_OUTPUT_CURRENT))

#define ADC_3_Buffer_DEFAULT_OA_COMP_TRIM_REG (ADC_3_Buffer_OA_COMP_TRIM_VALUE)


/***************************************
* The following code is DEPRECATED and 
* should not be used in new projects.
***************************************/

#define ADC_3_Buffer_LOWPOWER                   (ADC_3_Buffer_LOW_POWER)
#define ADC_3_Buffer_MEDPOWER                   (ADC_3_Buffer_MED_POWER)
#define ADC_3_Buffer_HIGHPOWER                  (ADC_3_Buffer_HIGH_POWER)

/* PUMP ON/OFF defines */
#define ADC_3_Buffer_PUMPON                     (ADC_3_Buffer_PUMP_ON)
#define ADC_3_Buffer_PUMPOFF                    (ADC_3_Buffer_PUMP_OFF)

#define ADC_3_Buffer_OA_CTRL                    (ADC_3_Buffer_CTB_CTRL_REG)
#define ADC_3_Buffer_OA_RES_CTRL                (ADC_3_Buffer_OA_RES_CTRL_REG)

/* Bit Field  OA_CTRL */
#define ADC_3_Buffer_OA_CTB_EN_SHIFT            (ADC_3_Buffer_CTB_CTRL_ENABLED_SHIFT)
#define ADC_3_Buffer_OA_PUMP_CTRL_SHIFT         (ADC_3_Buffer_OA_PUMP_EN_SHIFT)
#define ADC_3_Buffer_OA_PUMP_EN_MASK            (0x800u)
#define ADC_3_Buffer_PUMP_PROTECT_MASK          (1u)


#endif    /* CY_OPAMP_ADC_3_Buffer_H */


/* [] END OF FILE */
>>>>>>> remotes/origin/master
