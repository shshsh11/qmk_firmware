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

enum layers {
    _MAIN,
    _LOWER,
    _RAISE,
    _RAISE2,
};


#define CTRLC LCTL(KC_C)
#define CTRLV LCTL(KC_V)
#define CTRLX LCTL(KC_X)
#define CTRLS LCTL(KC_S)
#define CTRLZ LCTL(KC_Z)
#define OSSFT OSM(MOD_LSFT)
#define OSCTL OSM(MOD_LCTL)


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
   KC_O,        KC_N,    KC_SPC,  KC_T,    KC_U,    KC_Y,       KC_PSLS, KC_PAST,   KC_PMNS,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,      QK_BOOT,
   KC_TAB,      KC_I,    KC_N,    KC_T,    KC_H,   KC_G,        KC_KP_1, KC_KP_2,   KC_KP_3,    KC_F,     KC_G,  KC_C,    KC_R,    KC_L,      KC_SLSH,
   OSCTL,       KC_A,    KC_SPC,  KC_E,    OSL(_LOWER),  KC_R,  KC_KP_4, KC_KP_5,   KC_KP_6,    KC_D,     KC_H,    KC_T,    KC_N,    KC_S,      KC_ENT,
   KC_Q,        KC_M,    KC_L,    KC_O,    KC_F,    OSL(_RAISE),  KC_KP_7, KC_KP_8,   KC_KP_9,    KC_B,     KC_M,    KC_W,    KC_V,    KC_Z,     KC_RSFT,
   _______,     KC_CAPS, KC_LGUI, KC_LALT, KC_BSPC,   KC_S,      KC_PDOT, KC_KP_0,   KC_PPLS,    KC_BSPC,  MO(3),   KC_RALT, KC_RGUI, QK_BOOT,   _______ 
  ),

 [_LOWER] = LAYOUT_ortho_5x15(
    KC_ESC,   KC_D,   KC_K,    KC_SCLN,  KC_A,       KC_GRV,    _______, _______, _______, _______,  _______,  _______,  _______, _______, _______,
    KC_TAB,   KC_C,   OSSFT,   KC_W,     KC_V,       _______,    _______, _______, _______,  _______,    _______,  _______,  _______, _______, _______,
    _______,  KC_COMM,KC_ENT,  KC_D,     _______,    KC_Z,       _______, _______, _______,  _______,    _______,  _______,  _______, _______, _______, 
    KC_BSLS,  KC_DOT, KC_QUOT, KC_L,     KC_J,       KC_B,        _______, _______, _______,  _______,    _______,  _______,  _______, _______, _______, 
    _______, _______, _______, _______,  MO(_RAISE2),KC_P,    _______, _______, _______,  _______,    _______,  _______,  _______, _______, _______ 
  ),  

  [_RAISE] = LAYOUT_ortho_5x15(
    KC_LPRN,  KC_RPRN,        KC_EQL,   KC_SLSH,  KC_ASTR,   KC_MINS, _______,  _______, _______,  _______, _______, _______, _______,   _______,   _______, 
    KC_LBRC,  KC_RBRC,        KC_1,     KC_2,     KC_3,      KC_PLUS, _______, _______, _______, _______,  _______, _______,  _______, KC_PSCR,  KC_INS, 
    KC_LCBR,  KC_RCBR,        KC_4,     KC_5,     KC_6,      KC_ENT,  _______, _______, _______, _______,  KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, KC_DEL, 
    KC_MINS,  OSSFT,        KC_7,     KC_8,     KC_9,      _______, _______, _______, _______, _______,  KC_HOME, KC_PGDN,  KC_PGUP, KC_END,   _______, 
    _______,_______,          KC_COLN,  KC_0,     KC_DOT,    KC_X,    _______, _______, _______, KC_SPC,   _______, _______,  _______,  _______, _______ 
  ), 

  [_RAISE2] = LAYOUT_ortho_5x15(
    _______,  CTRLC,     CTRLV,    CTRLX,    CTRLS,    CTRLZ,     RGB_TOG,  _______, _______, _______,    _______, _______, _______,   _______,   QK_BOOT, 
    _______,  KC_F1,     KC_F2,    KC_F3,    KC_F4,    KC_F5,     _______,  _______, _______, _______,  _______, _______,    OS_OFF,  OS_ON,  DEBUG, 
    _______,  KC_LEFT,   KC_UP,    KC_DOWN,  KC_RIGHT, KC_DEL,   _______,  _______, _______, _______,  _______, _______,  _______, _______,   _______, 
    OSSFT,    KC_HOME,   KC_PGUP,  KC_PGDN,  KC_END,   KC_PSCR,    _______,  _______, _______, _______,  _______, _______,  _______,  _______,  _______, 
    _______,  KC_F6,     KC_F7,    KC_F8,    KC_F9,    KC_F10, _______,   KC_NUM,  _______, _______,   _______, _______,  _______,  _______,  _______ 
  ), 

};




void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock || is_caps_word_on()) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, 25, 25, 255);
            }
        }
    }
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}
