/*******************************************************************************
* File Name: CapSense_IP.h
* Version 2.60
*
* Description:
*  This file defined information about hardware IP blocks, available in silicone.
*
* Note:
*
********************************************************************************
* Copyright 2014-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#if !defined(CY_CAPSENSE_CSD_IP_CapSense_H)
#define CY_CAPSENSE_CSD_IP_CapSense_H

#include "cyfitter.h"

#if defined(CYIPBLOCK_m0s8gpio2_VERSION)
    #define CapSense_IS_M0S8GPIO2_BLOCK     (1u)
    #define CapSense_M0S8GPIO2_BLOCK_VER    (CYIPBLOCK_m0s8gpio2_VERSION)
#else
    #define CapSense_IS_M0S8GPIO2_BLOCK     (0u)
    #define CapSense_M0S8GPIO2_BLOCK_VER    (0u)
#endif /* (CYIPBLOCK_m0s8gpio2_VERSION) */


#if defined(CYIPBLOCK_m0s8hsiom4a_VERSION)
    #define CapSense_IS_M0S8HSIOM4A_BLOCK   (1u)
    #define CapSense_M0S8HSIOM4A_BLOCK_VER  (CYIPBLOCK_m0s8hsiom4a_VERSION)
#else
    #define CapSense_IS_M0S8HSIOM4A_BLOCK   (0u)
    #define CapSense_M0S8HSIOM4A_BLOCK_VER  (0u)
#endif /* (CYIPBLOCK_m0s8hsiom4a_VERSION) */


#if defined(CYIPBLOCK_m0s8ioss_VERSION)
    #define CapSense_IS_M0S8IOSS_BLOCK      (1u)
    #define CapSense_M0S8IOSS_BLOCK_VER     (CYIPBLOCK_m0s8ioss_VERSION)
#else
    #define CapSense_IS_M0S8IOSS_BLOCK      (0u)
    #define CapSense_M0S8IOSS_BLOCK_VER     (0u)
#endif /* (CYIPBLOCK_m0s8ioss_VERSION) */


#if defined(CYIPBLOCK_m0s8pclk_VERSION)
    #define CapSense_IS_M0S8PCLK_BLOCK      (1u)
    #define CapSense_M0S8PCLK_BLOCK_VER     (CYIPBLOCK_m0s8pclk_VERSION)
#else
    #define CapSense_IS_M0S8PCLK_BLOCK      (0u)
    #define CapSense_M0S8PCLK_BLOCK_VER     (0u)
#endif /* (CYIPBLOCK_m0s8pclk_VERSION) */


#if defined(CYIPBLOCK_m0s8peri_VERSION)
    #define CapSense_IS_M0S8PERI_BLOCK      (1u)
    #define CapSense_M0S8PERI_BLOCK_VER     ((CYIPBLOCK_m0s8peri_VERSION))
#else
    #define CapSense_IS_M0S8PERI_BLOCK      (0u)
    #define CapSense_M0S8PERI_BLOCK_VER     (0u)
#endif /* (CYIPBLOCK_m0s8peri_VERSION) */


#if defined(CYIPBLOCK_m0s8csd_VERSION)
    #define CapSense_IS_M0S8CSD_BLOCK       (1u)
    #define CapSense_M0S8CSD_BLOCK_VER      (CYIPBLOCK_m0s8csd_VERSION)
    #define CapSense_M0S8CSD_BLOCK_CNT      (2u)
#else
    #define CapSense_IS_M0S8CSD_BLOCK       (0u)
    #define CapSense_M0S8CSD_BLOCK_VER      (0u)
    #define CapSense_M0S8CSD_BLOCK_CNT      (0u)
#endif /* (CYIPBLOCK_m0s8csd_VERSION) */


#endif /* CY_CAPSENSE_CSD_IP_CapSense_H */

/* [] END OF FILE */
