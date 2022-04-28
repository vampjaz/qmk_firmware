// Copyright 2022 Kat (@Kat)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"
/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT



#define SPLIT_HAND_PIN C2

#define SOFT_SERIAL_PIN D3

#define SPLIT_LAYER_STATE_ENABLE



#define SPLIT_USB_DETECT



#define RGB_DI_PIN C5
#define DRIVER_LED_TOTAL 58
#define RGB_MATRIX_SPLIT { 29, 29 }

#define RGB_DISABLE_WHEN_USB_SUSPENDED

#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_RAINDROPS

#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#define ENABLE_RGB_MATRIX_PIXEL_FLOW
#define ENABLE_RGB_MATRIX_PIXEL_RAIN

