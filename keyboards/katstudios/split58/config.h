// Copyright 2022 Kat (@Kat)
// SPDX-License-Identifier: GPL-2.0-or-later


#pragma once

#include "config_common.h"

// optimization options
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE
#define LAYER_STATE_8BIT


// change this between d2 and d3 for split firmwares for now 
#define SOFT_SERIAL_PIN D2

#define SPLIT_HAND_PIN C2 // left side is high
#define SPLIT_USB_DETECT


// rgb options
#ifdef RGB_MATRIX_ENABLE
    #define RGB_DI_PIN C5
    #define DRIVER_LED_TOTAL 58
    #define RGB_MATRIX_SPLIT { 29, 29 }
    #define RGBLED_SPLIT { 29, 29 }  // not sure if needed atm

    #define RGB_DISABLE_WHEN_USB_SUSPENDED

    #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_BREATHING
    #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
    #define ENABLE_RGB_MATRIX_CYCLE_ALL
    #define ENABLE_RGB_MATRIX_RAINDROPS
#endif
