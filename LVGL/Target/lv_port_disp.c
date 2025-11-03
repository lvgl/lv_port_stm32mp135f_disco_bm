/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : Target/lv_port_disp.c
  * Description        : This file provides display port for LVGL library using
  *                      the X-CUBE-DISPLAY LCD APIs
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_disp.h"
#include "main.h"

extern LTDC_HandleTypeDef hltdc;

/*********************
 *      DEFINES
 *********************/
#define DISP_WIDTH                        480
#define DISP_HEIGHT                       272

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  GLOBAL PROTOTYPES
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void disp_init(void)
{
  __attribute__ ((aligned (32))) static uint8_t buf1[DISP_WIDTH * DISP_HEIGHT * 2];

  BSP_LCD_Init(0, 0);
  HAL_LTDC_SetAddress(&hltdc, (uint32_t)buf1, 0);
  BSP_LCD_DisplayOn(0);

#if 1
  __attribute__ ((aligned (32))) static uint8_t buf2[DISP_WIDTH * DISP_HEIGHT * 2];
  lv_st_ltdc_create_direct(buf1, buf2, 0);
#else
  static uint16_t parbuf1[DISP_WIDTH * 40];
  static uint16_t parbuf2[DISP_WIDTH * 40];
  lv_display_t * disp = lv_st_ltdc_create_partial(parbuf1, parbuf2, sizeof(parbuf1), 0);
#endif
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
