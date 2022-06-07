// Copyright 2021 Google LLC.
// SPDX-License-Identifier: Apache-2.0

#include "caps_word.h"

bool process_caps_word(uint16_t keycode, keyrecord_t* record) {
  static bool caps_word_enabled = false;
  static bool shifted = false;


  if (!caps_word_enabled) {
    // Pressing both shift keys at the same time enables caps word.
    if (((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT)
        == MOD_MASK_SHIFT) {
      clear_mods();
      clear_oneshot_mods();
      shifted = false;
      caps_word_enabled = true;
      tap_code(KC_CAPS);
      return false;
    }
    return true;
  }



  if (!record->event.pressed) { return true; }

  if (!((get_mods() | get_oneshot_mods()) & ~MOD_MASK_SHIFT)) {
    switch (keycode) {
      case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        // Earlier return if this has not been considered tapped yet.
        if (record->tap.count == 0) { return true; }
        // Get the base tapping keycode of a mod- or layer-tap key.
        keycode &= 0xff;
    }

    switch (keycode) {
      // keys that should be sent under caps lock.
      // different than shift method of caps lock 
      case KC_1 ... KC_0:
      case KC_BSPC:
      case KC_MINS:
      case KC_UNDS:
      case KC_A ... KC_Z:
        // if (!shifted) { register_code(KC_LSFT); }
        // if (!shifted) { tap_code(KC_CAPS); }
        shifted = true;
        return true;

      // // Keycodes that continue caps word but shouldn't get shifted.
      // case KC_1 ... KC_0:
      // case KC_BSPC:
      // case KC_MINS:
      // case KC_UNDS:
      //   // if (shifted) { unregister_code(KC_LSFT); }
      //   // if (shifted) { tap_code(KC_CAPS); }
      //   shifted = false;
      //   return true;

      // Any other keycode disables caps word.
      
      case KC_LSFT:
        // if (((get_mods() | get_oneshot_mods()) & MOD_BIT(KC_RSFT)) == MOD_BIT(KC_RSFT)) {
        //   if (shifted) { tap_code(KC_CAPS); }
        //   shifted = false;
        //   caps_word_enabled = false;
          
        //   return true;
        // }
      // case KC_RSFT:
        // if (((get_mods() | get_oneshot_mods()) & MOD_BIT(KC_LSFT)) == MOD_BIT(KC_LSFT)) {
        //   if (shifted) { tap_code(KC_CAPS); }
        //   shifted = false;
        //   caps_word_enabled = false;
          
        //   return true;
        // }
      case KC_SPC:
      case KC_ESC:
        
        // if (shifted) { unregister_code(KC_LSFT); }
        if (shifted) { tap_code(KC_CAPS); }
        caps_word_enabled = false;
        shifted = false;
        return true;
      
    }
  }


  

  // // Disable caps word.
  // caps_word_enabled = false;
  // if (shifted) { unregister_code(KC_LSFT); }
  // shifted = false;
  // return true;
  return true;
}