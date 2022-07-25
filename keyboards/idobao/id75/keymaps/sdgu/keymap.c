/* Copyright 2018 MechMerlin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_steno.h"

enum layers {
    _MAIN,
    _LOWER,
    _RAISE,
    _ADJUST,
};


enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST,
  PLOVER,
  EXT_PLV,
};

enum combo_events {
  NEXTSENTDOT,
  LHSHFT,
  RHSHFT,
  COMBOLENGTH,
};
uint16_t COMBO_LEN = COMBOLENGTH;


#define GUI_SC LGUI_T(KC_SCLN)
#define ALT_Q  LALT_T(KC_Q)
#define SHFT_J LSFT_T(KC_J)
#define CTRL_P LCTL_T(KC_P)

#define GUI_Z  RGUI_T(KC_Z)
#define ALT_V  RALT_T(KC_V)
#define SHFT_W RSFT_T(KC_W)
#define CTRL_G RCTL_T(KC_G)

#define ST_BOLT QK_STENO_BOLT
#define ST_GEM  QK_STENO_GEMINI

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  /* 
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_MAIN] = LAYOUT_ortho_5x15(
   KC_GRV,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_PSLS, KC_PAST,   KC_PMNS,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,      KC_EQL,
   KC_TAB,          KC_QUOT, KC_COMM, KC_DOT,  CTRL_P,  KC_Y,       KC_KP_1, KC_KP_2,   KC_KP_3,    KC_F,     CTRL_G,  KC_C,    KC_R,    KC_L,      KC_SLSH,
   KC_LCTL,         KC_A,    KC_O,    KC_E,    KC_U,    KC_I,       KC_KP_4, KC_KP_5,   KC_KP_6,    KC_D,     KC_H,    KC_T,    KC_N,    KC_S,      KC_ENT,
   KC_LSFT,         GUI_SC,  KC_Q,    KC_J,    KC_K,    KC_X,       KC_KP_7, KC_KP_8,   KC_KP_9,    KC_B,     KC_M,    KC_W,    KC_V,    GUI_Z,     KC_RSFT,
   _______,         KC_CAPS, KC_LGUI, KC_LALT, LOWER,   KC_SPC,     KC_PDOT, KC_KP_0,   KC_PPLS,    KC_BSPC,  RAISE,   KC_RALT, KC_RGUI, QK_BOOT,   _______ 
  ),

 [_LOWER] = LAYOUT_ortho_5x15(
    KC_ESC,         LCTL(KC_C),    LCTL(KC_V),     LCTL(KC_X),   LCTL(KC_S), LCTL(KC_Z), _______, _______, _______, LCTL(KC_Y),  _______,  _______,  _______, _______, _______,
    KC_ESC,         LALT(KC_QUOT), LALT(KC_COMM),  LALT(KC_DOT), LALT(KC_P), LALT(KC_Y), _______, _______, _______,  _______,    _______,  _______,  _______, _______, KC_BSLS,
    LCTL(KC_SLSH), _______,       KC_LBRC,        KC_LCBR,      KC_LPRN,    KC_MINS,    _______, _______, _______,  _______,    KC_RPRN,  KC_RCBR,  KC_RBRC, _______, XXXXXXX, 
    _______, _______,       _______,        _______,      _______,    _______,    _______, _______, _______,  _______,    _______,  _______,  _______, _______, _______, 
    _______, _______,       _______,        _______,      _______,    _______,    _______, _______, _______,  _______,    _______,  _______,  _______, _______, _______ 
  ),  

  [_RAISE] = LAYOUT_ortho_5x15(
    _______,  KC_F1,      KC_F2,      KC_F3,      KC_F4,   KC_F5,   KC_F11,  _______, KC_F12,  KC_F6,    KC_F7,   KC_F8,    KC_F9,   KC_F10,   _______, 
    _______,  _______,    _______,    _______,    _______, _______, _______, _______, _______, _______,  _______, _______,  _______, KC_PSCR,  KC_INS, 
    _______,  _______,    _______,    _______,    _______, _______, _______, _______, _______, _______,  KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, KC_DEL, 
    _______,  _______,    _______,    _______,    _______, _______, _______, _______, _______, _______,  KC_HOME, KC_PGDN,  KC_PGUP, KC_END,   _______, 
    _______,  _______,    _______,    _______,    _______, _______, _______, _______, _______, KC_SPC,   _______, _______,  _______,  _______, _______ 
  ), 

  [_ADJUST] = LAYOUT_ortho_5x15(
    _______,  PLOVER,     TO(_MAIN), _______,  _______,   _______,  RGB_TOG,  _______, _______, _______,    _______, _______, ST_GEM,   ST_BOLT,   QK_BOOT, 
    _______,  _______,    KC_MPRV,    KC_MPLY,    KC_MNXT, _______, _______,  _______, _______, DF(_MAIN),  _______, _______,    OS_OFF,  OS_ON,  DEBUG, 
    _______,  _______,    KC_VOLD,    KC_VOLU,    KC_MUTE, _______, _______,  _______, _______, DF(_MAIN),  _______, _______,  _______, _______,   _______, 
    _______,  _______,    _______,    _______,    _______, _______, _______,  _______, _______, _______,  _______, _______,  _______,  _______,  _______, 
    _______,  _______,    _______,    _______,    _______, _______, _______,  KC_NUM,  _______, _______,   _______, _______,  STN_PWR,  STN_RE1,  STN_RE2 
  ), 
};


const uint16_t PROGMEM lhshft[] = {KC_O, KC_DOT, COMBO_END};
const uint16_t PROGMEM rhshft[] = {KC_N, KC_C, COMBO_END};
const uint16_t PROGMEM nextsentdot[] = {KC_COMM, KC_DOT, KC_C, KC_R, COMBO_END}; 

combo_t key_combos[] = {
    [LHSHFT] = COMBO(lhshft, OSM(MOD_LSFT)),
    [RHSHFT] = COMBO(rhshft, OSM(MOD_RSFT)),
    [NEXTSENTDOT] = COMBO_ACTION(nextsentdot),

};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case NEXTSENTDOT:
      if (pressed) {
        if (!(get_mods() & MOD_MASK_SHIFT)) {
            tap_code(KC_DOT);
            tap_code(KC_SPC);
            /* Internal code of OSM(MOD_LSFT) */
            add_oneshot_mods(MOD_BIT(KC_LSHIFT));

        } else {
            // send ">" (KC_DOT + shift → ">")
            tap_code(KC_DOT);
        }
      }
      break;    
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock || is_caps_word_on()) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, 25, 25, 255);
            }
        }
    }
}

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}
