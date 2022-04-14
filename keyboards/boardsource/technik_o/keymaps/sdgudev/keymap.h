#pragma once

#include QMK_KEYBOARD_H

#ifdef TAP_DANCE_ENABLE
    enum {
        DOT_TD = 0,
    };
    #define TD_DOT TD(DOT_TD)
#else
    #define TD_DOT KC_DOT
#endif

uint16_t last_keycode;