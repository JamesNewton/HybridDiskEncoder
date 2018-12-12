/*******************************************************************************
* File Name: CapSense_TunerHelper.h
* Version 2.60
*
* Description:
*  This file provides constants and structure declarations for the tuner helper
*  APIs for the CapSense CSD component.
*
********************************************************************************
* Copyright 2013-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CAPSENSE_CSD_TUNERHELPER_CapSense_H)
#define CY_CAPSENSE_CSD_TUNERHELPER_CapSense_H

#include "CapSense.h"

#if(0u != CapSense_CSHL_API_GENERATE)
    #include "CapSense_CSHL.h"
#endif /* (0u != CapSense_CSHL_API_GENERATE) */

#if (CapSense_TUNER_API_GENERATE)
    #include "CapSense_MBX.h"
#endif /* (CapSense_TUNER_API_GENERATE) */


/***************************************
*     Constants for mailboxes
***************************************/

#define CapSense_DEFAULT_MAILBOXES_NUMBER       (1u)

#define CapSense_CENTROID_POSITION_BUFFER_SIZE  (2u)
#define CapSense_MB_POSITION_BUFFER_SIZE        (2u)

#define CapSense_DEFAULT_TRACKPAD_INDEX         (0u)

#define CapSense_FIRST_FINGER_INDEX             (0u)
#define CapSense_SECOND_FINGER_INDEX            (1u)

#define CapSense_FIRST_FINGER_X_INDEX           (0u)
#define CapSense_FIRST_FINGER_Y_INDEX           (1u)

#define CapSense_SECOND_FINGER_X_INDEX          (2u)
#define CapSense_SECOND_FINGER_Y_INDEX          (3u)

#define CapSense_GESTURE_TYPE_MASK              (0xF0u)
#define CapSense_INERTIAL_SCROLL                (0xB0u)
#define CapSense_NON_INERTIAL_SCROLL            (0xC0u)


/***************************************
*        Function Prototypes
***************************************/

void CapSense_TunerStart(void);
void CapSense_TunerComm(void);

#if (CapSense_TUNER_API_GENERATE)
   CapSense_NO_STRICT_VOLATILE void CapSense_ProcessAllWidgets(volatile CapSense_OUTBOX *outbox);
#endif /* (CapSense_TUNER_API_GENERATE) */


/***************************************
*     Vars with External Linkage
***************************************/
#if (CapSense_TUNER_API_GENERATE)
    extern volatile CapSense_MAILBOXES CapSense_mailboxesComm;
#endif /* (CapSense_TUNER_API_GENERATE) */

#endif  /* (CY_CAPSENSE_CSD_TUNERHELPER_CapSense_H)*/


/* [] END OF FILE */
