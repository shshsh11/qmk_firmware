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
    _ALPHA2,
    _NUM,
    _UTILS,
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


L1------------------------------------------------
       Q    SCLN     SFT    QUOT     ENT     DOT
     TAB       E       H       T       I    COMM
    LCTL       W       E      LS       A       N
      LS       S       I       V       F       K
     GUI    CAPS     ALT      LS    BSPC     SPC

L2------------------------------------------------
   ESC       Z    MINS       X       L     GRV
   SFT       Y       B     ENT       U       S
  LCTL       G       O      LS       R       C
     U       M       N       J       D       P
   GUI      __     ALT      __      __       L

L3------------------------------------------------
  LPRN  RPRN   EQL  SLSH  ASTR  MINS
  LBRC  RBRC     1     2     3  PLUS
  LCBR  RCBR     4     5     6   ENT
    LS  COMM     7     8     9  UNDS
    __    __  COLN     0   DOT   SFT

L4------------------------------------
    __    __    __    __    __    __
    F1    F2    F3    F4    F5    F6
    __  LEFT    UP  DOWN  RGHT   DEL
   SFT  HOME  PGUP  PGDN   END  PSCR
    __    __    __    LS    __    __

*/

 [_MAIN] = LAYOUT(
   KC_Q,     KC_SLSH, OSSFT,   KC_ENT,      KC_DOT,   KC_QUOT,   
   KC_TAB,   KC_E,    KC_H,    KC_T,        KC_I,     KC_COMM,    
   OSCTL,    KC_S,    KC_E,    OSL(_ALPHA2), KC_A,     KC_W,   
   OSL(_NUM), KC_N, KC_I,    KC_V,        KC_F,     KC_K, 
   KC_LGUI,  KC_CAPS, KC_LALT, OSL(_UTILS), KC_BSPC, KC_SPC
  ),

 [_ALPHA2] = LAYOUT(
    KC_ESC,   KC_Z,   KC_MINS, KC_X,        KC_L,     KC_GRV,   
    KC_SCLN,  KC_Y,   KC_B,    KC_ENT,      KC_G,     KC_T,   
    _______,  KC_U,   KC_O,    OSL(_ALPHA2), KC_R,     KC_C,   
    KC_S,     KC_M,   KC_N,    KC_J,        KC_D,     KC_P,      
    KC_LGUI, _______, KC_LALT, _______,     _______,  KC_L
  ),  

  [_NUM] = LAYOUT(
    KC_LPRN,  KC_RPRN,    KC_EQL,   KC_SLSH,  KC_ASTR,   KC_MINS, 
    KC_LBRC,  KC_RBRC,    KC_1,     KC_2,     KC_3,      KC_PLUS, 
    KC_LCBR,  KC_RCBR,    KC_4,     KC_5,     KC_6,      KC_ENT,  
    _______,  KC_COMM,    KC_7,     KC_8,     KC_9,      KC_UNDS, 
    _______,_______,      KC_COLN,  KC_0,     KC_DOT,    OSSFT
  ), 

  [_UTILS] = LAYOUT(
    QK_BOOT,  CTRLC,     CTRLV,    CTRLX,    CTRLS,    CTRLZ,
    KC_F1,  KC_F2,     KC_F3,    KC_F4,    KC_F5,    KC_F6,     
    _______,  KC_LEFT,   KC_UP,    KC_DOWN,  KC_RIGHT, KC_DEL,   
    OSSFT,    KC_HOME,   KC_PGUP,  KC_PGDN,  KC_END,   KC_PSCR,    
    KC_F7,  KC_F8,     KC_F9,    _______,    KC_F10,    _______
  ), 

};



bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) { //|| is_caps_word_on()) {
        // for (uint8_t i = led_min; i <= led_max; i++) {
        //     if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
        //         rgb_matrix_set_color(i, 250, 20, 70);
        //     }
        // }
        // rgb_matrix_set_color_all(255, 70, 70);
        RGB_MATRIX_INDICATOR_SET_COLOR(31, 255, 70, 70);
    }

    if (get_oneshot_mods() & MOD_MASK_SHIFT) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case _MAIN:
                RGB_MATRIX_INDICATOR_SET_COLOR(2, 102, 0, 204);
                break;
            case _NUM:
                RGB_MATRIX_INDICATOR_SET_COLOR(35, 102, 0, 204);
                break;
            default:
                rgb_matrix_sethsv_noeeprom(HSV_OFF);
                break;
        }

    }

    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _ALPHA2:
            RGB_MATRIX_INDICATOR_SET_COLOR(18, 255, 100, 0);
            break;
        case _NUM:
            RGB_MATRIX_INDICATOR_SET_COLOR(29, 153, 255, 51);
            break;
        case _UTILS:
            RGB_MATRIX_INDICATOR_SET_COLOR(33, 51, 153, 255);
            break;
        default:
            rgb_matrix_sethsv_noeeprom(HSV_OFF);
            break;
    }



    return false;
}


// void oneshot_layer_changed_user(uint8_t layer) {
//   if (layer == _ALPHA2) {
//     // println("secondary alphas");
//     // rgb_matrix_set_color_all(255, 153, 51);
//     rgb_matrix_sethsv_noeeprom(21, 204, 255);
//   } 
//   if (layer == _NUM) {
//     // println("numbers");
//     // rgb_matrix_set_color_all(153, 255, 51);
//     rgb_matrix_sethsv_noeeprom(64, 204, 255);
//   } 
//   if (layer == _UTILS) {
//     // println("navigation etc.");
//     // rgb_matrix_set_color_all(51, 153, 255);
//     rgb_matrix_sethsv_noeeprom(149, 204, 255);
//   }
//   if (!layer) {
//     // println("Oneshot layer off");
//     rgb_matrix_sethsv_noeeprom(HSV_OFF);
//   }
// }


void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}
