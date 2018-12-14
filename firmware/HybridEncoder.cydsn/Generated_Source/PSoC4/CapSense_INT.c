<<<<<<< HEAD
/*******************************************************************************
* File Name: CapSense_INT.c
* Version 2.60
*
* Description:
*  This file provides the source code of the  Interrupt Service Routine (ISR)
*  for the CapSense CSD component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CapSense.h"
#include "CapSense_PVT.h"
#include "cyapicallbacks.h"


/*******************************************************************************
*  Place your includes, defines and code here
********************************************************************************/
/* `#START CapSense_ISR_INTC` */

/* `#END` */


/*******************************************************************************
* Function Name: CapSense_ISR
********************************************************************************
*
* Summary:
*  This ISR is executed when the measure window is closed. The measure window
*  depends on the sensor scan resolution parameter.
*  The ISR has two modes:
*   1. Scans a single sensor and stores the measure result.
*   2. Stores the result of the current measure and starts the next scan till all
*      the enabled sensors are scanned.
*  This interrupt handler is only used in one channel designs.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  CapSense_csv - used to provide the status and mode of the scanning process.
*   Mode - a single scan or scan of all the enabled sensors.
*   Status - scan is in progress or ready for new scan.
*  CapSense_sensorIndex - used to store a sensor scanning sensor number.
*
* Reentrant:
*  No
*
*******************************************************************************/
CY_ISR(CapSense_ISR)
{
    static uint8 CapSense_snsIndexTmp;

    #ifdef CapSense_ISR_ENTRY_CALLBACK
        CapSense_ISR_EntryCallback();
    #endif /* CapSense_ISR_ENTRY_CALLBACK */

    /*  Place your Interrupt code here. */
    /* `#START CapSense_ISR_ENTER` */

    /* `#END` */

    CyIntDisable(CapSense_ISR_NUMBER);

    CapSense_CSD_INTR_REG = 1u;

    CapSense_PostScan((uint32)CapSense_sensorIndex);

    if ((CapSense_csdStatusVar & CapSense_SW_CTRL_SINGLE_SCAN) != 0u)
    {
        CapSense_csdStatusVar &= (uint8)~CapSense_SW_STS_BUSY;
    }
    else
    {
        /* Proceed scanning */
        CapSense_sensorIndex = CapSense_FindNextSensor(CapSense_sensorIndex);

        /* Check end of scan */
        if(CapSense_sensorIndex < CapSense_TOTAL_SENSOR_COUNT)
        {
            CapSense_PreScan((uint32)CapSense_sensorIndex);
        }
        else
        {
            CapSense_csdStatusVar &= (uint8)~CapSense_SW_STS_BUSY;

             /* Check if widget has been scanned */
            if((CapSense_csdStatusVar & CapSense_SW_CTRL_WIDGET_SCAN) != 0u)
            {
                /* Restore sensorEnableMask array */
                for(CapSense_snsIndexTmp = 0u;
                    CapSense_snsIndexTmp < CapSense_TOTAL_SENSOR_MASK;
                    CapSense_snsIndexTmp++)
                {
                    /* Backup sensorEnableMask array */
                    CapSense_sensorEnableMask[CapSense_snsIndexTmp] = CapSense_sensorEnableMaskBackup[CapSense_snsIndexTmp];
                }
            }
        }
    }
    CyIntEnable(CapSense_ISR_NUMBER);

    /*  Place your Interrupt code here. */
    /* `#START CapSense_ISR_EXIT` */

    /* `#END` */

    #ifdef CapSense_ISR_EXIT_CALLBACK
        CapSense_ISR_ExitCallback();
    #endif /* CapSense_ISR_EXIT_CALLBACK */
}

/* [] END OF FILE */
=======
/*******************************************************************************
* File Name: CapSense_INT.c
* Version 2.60
*
* Description:
*  This file provides the source code of the  Interrupt Service Routine (ISR)
*  for the CapSense CSD component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CapSense.h"
#include "CapSense_PVT.h"
#include "cyapicallbacks.h"


/*******************************************************************************
*  Place your includes, defines and code here
********************************************************************************/
/* `#START CapSense_ISR_INTC` */

/* `#END` */


/*******************************************************************************
* Function Name: CapSense_ISR
********************************************************************************
*
* Summary:
*  This ISR is executed when the measure window is closed. The measure window
*  depends on the sensor scan resolution parameter.
*  The ISR has two modes:
*   1. Scans a single sensor and stores the measure result.
*   2. Stores the result of the current measure and starts the next scan till all
*      the enabled sensors are scanned.
*  This interrupt handler is only used in one channel designs.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  CapSense_csv - used to provide the status and mode of the scanning process.
*   Mode - a single scan or scan of all the enabled sensors.
*   Status - scan is in progress or ready for new scan.
*  CapSense_sensorIndex - used to store a sensor scanning sensor number.
*
* Reentrant:
*  No
*
*******************************************************************************/
CY_ISR(CapSense_ISR)
{
    static uint8 CapSense_snsIndexTmp;

    #ifdef CapSense_ISR_ENTRY_CALLBACK
        CapSense_ISR_EntryCallback();
    #endif /* CapSense_ISR_ENTRY_CALLBACK */

    /*  Place your Interrupt code here. */
    /* `#START CapSense_ISR_ENTER` */

    /* `#END` */

    CyIntDisable(CapSense_ISR_NUMBER);

    CapSense_CSD_INTR_REG = 1u;

    CapSense_PostScan((uint32)CapSense_sensorIndex);

    if ((CapSense_csdStatusVar & CapSense_SW_CTRL_SINGLE_SCAN) != 0u)
    {
        CapSense_csdStatusVar &= (uint8)~CapSense_SW_STS_BUSY;
    }
    else
    {
        /* Proceed scanning */
        CapSense_sensorIndex = CapSense_FindNextSensor(CapSense_sensorIndex);

        /* Check end of scan */
        if(CapSense_sensorIndex < CapSense_TOTAL_SENSOR_COUNT)
        {
            CapSense_PreScan((uint32)CapSense_sensorIndex);
        }
        else
        {
            CapSense_csdStatusVar &= (uint8)~CapSense_SW_STS_BUSY;

             /* Check if widget has been scanned */
            if((CapSense_csdStatusVar & CapSense_SW_CTRL_WIDGET_SCAN) != 0u)
            {
                /* Restore sensorEnableMask array */
                for(CapSense_snsIndexTmp = 0u;
                    CapSense_snsIndexTmp < CapSense_TOTAL_SENSOR_MASK;
                    CapSense_snsIndexTmp++)
                {
                    /* Backup sensorEnableMask array */
                    CapSense_sensorEnableMask[CapSense_snsIndexTmp] = CapSense_sensorEnableMaskBackup[CapSense_snsIndexTmp];
                }
            }
        }
    }
    CyIntEnable(CapSense_ISR_NUMBER);

    /*  Place your Interrupt code here. */
    /* `#START CapSense_ISR_EXIT` */

    /* `#END` */

    #ifdef CapSense_ISR_EXIT_CALLBACK
        CapSense_ISR_ExitCallback();
    #endif /* CapSense_ISR_EXIT_CALLBACK */
}

/* [] END OF FILE */
>>>>>>> remotes/origin/master
