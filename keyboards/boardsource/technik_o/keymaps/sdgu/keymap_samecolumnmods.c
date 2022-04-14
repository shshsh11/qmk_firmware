/* Copyright 2020 Boardsource
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


/* things to do
  -look into decreasing combo term since "e a" rolls can sometimes trigger "7"
  -"s t" rolls also sometimes trigger "7" on the right hand
  -similarly, explore what combos to use for numbers for reason as above 
  -look into why KC_NO behaves like LOWER
  -light indicator for CAPS LOCK
  -keep another LALT as a thumb key since it is easier for alt tab that way
  -control (k and m) often hit the modded versions, while shift (j and w) often sends the non-mod plus the key
  -column combo (home and top) mods
  -try shift on index fingers
*/



#include QMK_KEYBOARD_H
#include "keymap_steno.h"

enum layers {
    _MAIN,
    _LOWER,
    _RAISE,
    _PLOVER,
    _NUMPAD,
    _ADJUST,
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST,
  PLOVER,
  // EXT_PLV,
};

enum combo_events {
  GRVCOMBO,
  EQLCOMBO,
  BRIEFAND,
  BRIEFFUNCTION,
  RHNUMPADLAYERCOMBO,
  LCTRL_UP,
  LSHFT_EDOT,
  LALT_OCOMM,
  LGUI_AQUOT,
  RCTRL_HG,
  RSHFT_TC,
  RALT_NR,
  RGUI_SL,
  // LH1,
  // LH2,
  // LH3,
  // LH4,
  // LH5,
  // LH6,
  // LH7,
  // LH8,
  // LH9,
  // LH0,
  // RH1,
  // RH2,
  // RH3,
  // RH4,
  // RH5,
  // RH6,
  // RH7,
  // RH8,
  // RH9,
  // RH0,
  
  COMBOLENGTH,
};

uint16_t COMBO_LEN = COMBOLENGTH;


#define ST_BOLT QK_STENO_BOLT
#define ST_GEM  QK_STENO_GEMINI

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define GUI_SC LGUI_T(KC_SCLN)
#define ALT_Q  LALT_T(KC_Q)
#define SHFT_J LSFT_T(KC_J)
#define CTRL_K LCTL_T(KC_K)

#define GUI_Z  RGUI_T(KC_Z)
#define ALT_V  RALT_T(KC_V)
#define SHFT_W RSFT_T(KC_W)
#define CTRL_M RCTL_T(KC_M)

// Readability keycodes
// #define LOWER   MO(_LOWER)
// #define RAISE   MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // [_MAIN] = LAYOUT_ortho_4x12(
  //   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //   KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
  //   RGB_TOG, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  // ),

 //  [_RAISE] = LAYOUT_ortho_4x12(
 //  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
 //  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
 //  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
 //  RESET,   _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
 //  ),

 //  [_LOWER] = LAYOUT_ortho_4x12(
 // KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
 // KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
 // _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
 // RGB_MOD, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
 //  )


    /* [_MAIN] = LAYOUT_ortho_4x12(
    KC_TAB,     KC_QUOT,          KC_COMM,  KC_DOT,   KC_P,   KC_Y,     KC_F,     KC_G,   KC_C,     KC_R,     KC_L,     KC_SLSH,  \
    KC_LCTL,    KC_A,             KC_O,     KC_E,     KC_U,   KC_I,     KC_D,     KC_H,   KC_T,     KC_N,     KC_S,     KC_ENT,   \
    KC_LSFT,    KC_SCLN,          KC_Q,     KC_J,     KC_K,   KC_X,     KC_B,     KC_M,   KC_W,     KC_V,     KC_Z,     KC_RSFT,  \
    _______,    KC_CAPS,          KC_LGUI,  KC_LALT,  LOWER,  KC_SPC,   KC_BSPC,  RAISE,  KC_RALT,  KC_RGUI,  _______,  _______
    ), */

    /* [_MAIN] = LAYOUT_ortho_4x12(
    KC_TAB,     KC_QUOT,          KC_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_F,     KC_G,   KC_C,     KC_R,     KC_L,     KC_SLSH,  \
    KC_LCTL,    KC_A,             KC_O,     KC_E,     KC_U,     KC_I,     KC_D,     KC_H,   KC_T,     KC_N,     KC_S,     KC_ENT,   \
    KC_LSFT,    GUI_SC,           ALT_Q,    SHFT_J,   CTRL_K,   KC_X,     KC_B,     CTRL_M, SHFT_W,   ALT_V,    GUI_Z,    KC_RSFT,  \
    _______,    KC_CAPS,          KC_LGUI,  KC_LALT,  LOWER,    KC_SPC,   KC_BSPC,  RAISE,  KC_RALT,  KC_RGUI,  _______,  _______
    ), */

    // disabling other mods to get used to bottom row mods
    [_MAIN] = LAYOUT_ortho_4x12(
    KC_TAB,     KC_QUOT,          KC_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_F,     KC_G,   KC_C,     KC_R,     KC_L,     KC_SLSH,  \
    XXXXXXX,    KC_A,             KC_O,     KC_E,     KC_U,     KC_I,     KC_D,     KC_H,   KC_T,     KC_N,     KC_S,     KC_ENT,   \
    // XXXXXXX,    GUI_SC,           ALT_Q,    SHFT_J,   CTRL_K,   KC_X,     KC_B,     CTRL_M, SHFT_W,   ALT_V,    GUI_Z,    XXXXXXX,  
    XXXXXXX,    KC_SCLN,          KC_Q,    KC_J,   KC_K,   KC_X,     KC_B,     KC_M, KC_W,   KC_V,    KC_Z,    XXXXXXX,  \
    XXXXXXX,    KC_CAPS,          XXXXXXX,  KC_LALT,  LOWER,    KC_SPC,   KC_BSPC,  RAISE,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
    ),


    [_LOWER] = LAYOUT_ortho_4x12(
    KC_ESC,     LCTL(KC_C),   LCTL(KC_V),     LCTL(KC_X),   LCTL(KC_S),   LCTL(KC_Z), LCTL(KC_Y),  _______,  _______,   _______,  _______,  KC_BSLS,   \
    _______,    _______,      KC_LBRC,        KC_LCBR,      KC_LPRN,      KC_MINS,    _______,     KC_RPRN,  KC_RCBR,   KC_RBRC,  _______,  _______,   \
    _______,    _______,      _______,        _______,      _______,      _______,    _______,     _______,  _______,   _______,  _______,  _______,   \
    _______,    _______,      _______,        _______,      _______,      _______,    _______,     _______,  _______,   _______,  _______,  _______    
    ),  

    // try out page-up and page-down above up and down?
    // home and end somewhere?
    [_RAISE] = LAYOUT_ortho_4x12(
    _______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       _______,    _______,    _______,  _______,  KC_PSCR,  KC_INS,  \
    _______,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,    KC_LEFT,    KC_DOWN,  KC_UP,    KC_RIGHT, KC_DEL,   \
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______,  _______,  _______,  \
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______,  _______,  _______  
    ),  

    [_NUMPAD] = LAYOUT_ortho_4x12(
    _______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      _______,    _______,    _______,  _______,  _______, _______,  \
    _______,    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     _______,    _______,    _______,  _______,  _______, _______,   \
    _______,    KC_F11,     KC_F12,     _______,    _______,    _______,    _______,    _______,    _______,  _______,  _______, _______,  \
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______,  _______, _______  
    ),  

    [_ADJUST] = LAYOUT_ortho_4x12(
    TO(_MAIN),  PLOVER,     KC_MPRV,    KC_MNXT,    KC_MPLY,    _______,    _______,    _______,    _______,    ST_GEM,     ST_BOLT,    RESET,    \
    _______,    _______,    KC_VOLD,    KC_VOLU,    KC_MUTE,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    \
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    \
    RGB_TOG,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    STN_PWR,    STN_RE1,    STN_RE2 
    ),

    [_PLOVER] = LAYOUT_ortho_4x12(
    KC_TAB,   STN_S1,     STN_TL,     STN_PL,     STN_HL,  STN_ST1,   STN_ST3, STN_FR,  STN_PR,    STN_LR,   STN_TR,    STN_DR,  \
    KC_LCTL,  STN_S2,     STN_KL,     STN_WL,     STN_RL,  STN_ST2,   STN_ST4, STN_RR,  STN_BR,    STN_GR,   STN_SR,    STN_ZR,  \
    KC_LSFT,  STN_N1,     STN_N2,     STN_N3,     STN_N4,  STN_N5,    STN_N6,  STN_N7,  STN_N8,    STN_N9,   STN_NA,    STN_NB, \
    LOWER,    KC_LSFT,    KC_LGUI,    KC_LALT,    STN_A,   STN_O,     STN_E,   STN_U,   KC_BSPC,   XXXXXXX,  STN_NC,    RAISE 
    ),

};

// void matrix_init_user() {
//   steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
// }

// qk_tap_dance_action_t tap_dance_actions[] = {
//     [TD_QUOT_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_GRV),
// };


// void dance_quot_finished(qk_tap_dance_state_t *state, void *user_data)
// {
//   if (state->count == 1)
//   {
//     register_code16(KC_QUOT)
//   }
//   else
//   {
//     register_code(KC_GRV)
//   }
// }
// void dance_quot_reset(qk_tap_dance_state_t *state, void *user_data)
// {
//   if (state->count == 1)
//   {
//     unregister_code16(KC_QUOT)
//   }
//   else
//   {
//     unregister_code(KC_GRV)
//   }
// }

// qk_tap_dance_action_t tap_dance_actions[] = 
// {
//   [QUOT_GRV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_quot_finished, dance_quot_reset),
// };

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
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);

      } else {
        layer_off(_ADJUST);

      }
      return false;
      break;
    case PLOVER:
        if (!record->event.pressed) {
          #ifdef AUDIO_ENABLE
            stop_all_notes();
            PLAY_SONG(plover_song);
          #endif
          layer_on(_PLOVER);
        }
        return false;
        break;
  //   case EXT_PLV:
  //     if (record->event.pressed) {
  //       #ifdef AUDIO_ENABLE
  //         PLAY_SONG(plover_gb_song);
  //       #endif
  //       layer_off(_PLOVER);
  //     }
  //     return false;
  //     break;

  }
  return true;
}

// // MT down, key down, key up, MT up with this on will give the mod
// // I don't think permissive hold does much for me but we'll see
// bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case SHFT_J:
//             // Immediately select the hold action when another key is tapped.
//             return true;
//         // case CTRL_K:
//         //   return true;
//         case SHFT_W:
//             // Immediately select the hold action when another key is tapped.
//             return true;
//         // case CTRL_M:
//         //   return true;
//         default:
//             // Do not select the hold action when another key is tapped.
//             return false;
//     }
// }


// If I turn this on, then shift captializes, but causes problems for rolls with 'w' and 'j'
// MT down, key down, MT up, key up with this on gives the mod
// bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case SHFT_J:
//             // Immediately select the hold action when another key is pressed.
//             return true;
//         case SHFT_W:
//             // Immediately select the hold action when another key is tapped.
//             return true;
//         default:
//             // Do not select the hold action when another key is pressed.
//             return false;
//     }
// }



// void led_set_user(uint8_t usb_led) {
//     if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
//         DDRB |= (1 << 2); PORTB &= ~(1 << 2);
//         rgblight_sethsv_noeeprom(240, 90, 100);
//     } else {
//         DDRB &= ~(1 << 2); PORTB &= ~(1 << 2);
//         rgblight_sethsv_noeeprom(0, 0, 0);
//     }
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//     case _MAIN:
//         rgblight_sethsv_noeeprom(188, 255, 196); // 0, 170, 196
//         break;
//     case _RAISE:
//         rgblight_sethsv_noeeprom(12, 171, 238); // 0, 255, 0 -> 238, 108, 77
//         break;
//     case _LOWER:
//         rgblight_sethsv_noeeprom(155, 74, 83); // 255, 0, 0 -> 59, 82, 73
//         break;
//     case _ADJUST:
//         rgblight_sethsv_noeeprom(36, 43, 255); // 255, 238, 212
//         break;
//     case _PLOVER:
//         rgblight_sethsv_noeeprom(290, 82, 143); // 135, 97, 143
//         break;
//     default: //  for any other layers, or the default layer
//         rgblight_sethsv_noeeprom(0, 0, 0);
//         break;
//     }
//   return state;
// }

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _MAIN:
        rgb_matrix_sethsv_noeeprom(188, 255, 196); // 0, 170, 196
        break;
    case _RAISE:
        rgb_matrix_sethsv_noeeprom(12, 171, 238); // 0, 255, 0 -> 238, 108, 77
        break;
    case _LOWER:
        rgb_matrix_sethsv_noeeprom(155, 74, 83); // 255, 0, 0 -> 59, 82, 73
        break;
    case _ADJUST:
        rgb_matrix_sethsv_noeeprom(36, 43, 255); // 255, 238, 212
        break;
    case _PLOVER:
        rgb_matrix_sethsv_noeeprom(290, 82, 143); // 135, 97, 143
        break;
    default: //  for any other layers, or the default layer
        rgb_matrix_sethsv_noeeprom(0, 0, 0);
        break;
    }
  return state;
}





// add briefs. 'for', 'that', 'this' etc.
// add some programming briefs like 'function'?
const uint16_t PROGMEM grvcombo[] = {KC_TAB, KC_QUOT, COMBO_END};
const uint16_t PROGMEM eqlcombo[] = {KC_L, KC_SLSH, COMBO_END};
const uint16_t PROGMEM rhnumpadlayercombo[] = {KC_BSPC, RAISE, COMBO_END};
// const uint16_t PROGMEM lh1[] = {KC_QUOT, KC_COMM, COMBO_END};
// const uint16_t PROGMEM lh2[] = {KC_QUOT, KC_DOT, COMBO_END};
// const uint16_t PROGMEM lh3[] = {KC_QUOT, KC_P, COMBO_END};
// const uint16_t PROGMEM lh4[] = {KC_COMM, KC_DOT, COMBO_END};
// const uint16_t PROGMEM lh5[] = {KC_COMM, KC_P, COMBO_END};
// const uint16_t PROGMEM lh6[] = {KC_A, KC_O, COMBO_END};
// const uint16_t PROGMEM lh7[] = {KC_A, KC_E, COMBO_END};
// const uint16_t PROGMEM lh8[] = {KC_A, KC_U, COMBO_END};
// const uint16_t PROGMEM lh9[] = {KC_O, KC_E, COMBO_END};
// const uint16_t PROGMEM lh0[] = {KC_O, KC_U, COMBO_END};

// const uint16_t PROGMEM rh1[] = {KC_L, KC_R, COMBO_END};
// const uint16_t PROGMEM rh2[] = {KC_L, KC_C, COMBO_END};
// const uint16_t PROGMEM rh3[] = {KC_L, KC_G, COMBO_END};
// const uint16_t PROGMEM rh4[] = {KC_C, KC_R, COMBO_END};
// const uint16_t PROGMEM rh5[] = {KC_G, KC_R, COMBO_END};
// const uint16_t PROGMEM rh6[] = {KC_S, KC_N, COMBO_END};
// const uint16_t PROGMEM rh7[] = {KC_S, KC_T, COMBO_END};
// const uint16_t PROGMEM rh8[] = {KC_S, KC_H, COMBO_END};
// const uint16_t PROGMEM rh9[] = {KC_T, KC_N, COMBO_END};
// const uint16_t PROGMEM rh0[] = {KC_N, KC_H, COMBO_END};

const uint16_t PROGMEM lctrl_up[] = {KC_U, KC_P, COMBO_END};
const uint16_t PROGMEM lshft_edot[] = {KC_E, KC_DOT, COMBO_END};
const uint16_t PROGMEM lalt_ocomm[] = {KC_O, KC_COMM, COMBO_END};
const uint16_t PROGMEM lgui_aquot[] = {KC_A, KC_QUOT, COMBO_END};

const uint16_t PROGMEM rctrl_hg[] = {KC_H, KC_G, COMBO_END};
const uint16_t PROGMEM rshft_tc[] = {KC_T, KC_C, COMBO_END};
const uint16_t PROGMEM ralt_nr[] = {KC_N, KC_R, COMBO_END};
const uint16_t PROGMEM rgui_sl[] = {KC_S, KC_L, COMBO_END};

const uint16_t PROGMEM briefand[] = {KC_A, KC_O, KC_DOT, COMBO_END};
const uint16_t PROGMEM brieffunction[] = {KC_COMM, KC_DOT, KC_M, KC_T, KC_N, KC_S, COMBO_END};

// const uint16_t PROGMEM lhnumpadlayer[] = {KC_SPC, LOWER, COMBO_END};
combo_t key_combos[] = {
    [GRVCOMBO] = COMBO(grvcombo, KC_GRV),
    [EQLCOMBO] = COMBO(eqlcombo, KC_EQL),
    [RHNUMPADLAYERCOMBO] = COMBO(rhnumpadlayercombo, MO(_NUMPAD)),

    [LCTRL_UP] = COMBO(lctrl_up, KC_LCTL),
    [LSHFT_EDOT] = COMBO(lshft_edot, KC_LSFT),
    [LALT_OCOMM] = COMBO(lalt_ocomm, KC_LALT),
    [LGUI_AQUOT] = COMBO(lgui_aquot, KC_LGUI),
    [RCTRL_HG] = COMBO(rctrl_hg, KC_RCTL),
    [RSHFT_TC] = COMBO(rshft_tc, KC_RSFT),
    [RALT_NR] = COMBO(ralt_nr, KC_RALT),
    [RGUI_SL] = COMBO(rgui_sl, KC_RGUI),
    // [LH1] = COMBO(lh1, KC_1),
    // [LH2] = COMBO(lh2, KC_2),
    // [LH3] = COMBO(lh3, KC_3),
    // [LH4] = COMBO(lh4, KC_4),
    // [LH5] = COMBO(lh5, KC_5),
    // [LH6] = COMBO(lh6, KC_6),
    // [LH7] = COMBO(lh7, KC_7),
    // [LH8] = COMBO(lh8, KC_8),
    // [LH9] = COMBO(lh9, KC_9),
    // [LH0] = COMBO(lh0, KC_0),
    // [RH1] = COMBO(rh1, KC_1),
    // [RH2] = COMBO(rh2, KC_2),
    // [RH3] = COMBO(rh3, KC_3),
    // [RH4] = COMBO(rh4, KC_4),
    // [RH5] = COMBO(rh5, KC_5),
    // [RH6] = COMBO(rh6, KC_6),
    // [RH7] = COMBO(rh7, KC_7),
    // [RH8] = COMBO(rh8, KC_8),
    // [RH9] = COMBO(rh9, KC_9),
    // [RH0] = COMBO(rh0, KC_0),

    [BRIEFAND] = COMBO_ACTION(briefand),
    // [BRIEFFUNCTION] = COMBO_ACTION(brieffunction),
    // COMBO(lhnumpadlayer, MO(_NUMPAD)),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    // case GRVCOMBO:
    //   if (pressed) {
    //     tap_code(KC_GRV);
    //   }
    //   break;
    // case EQLCOMBO:
    //   if (pressed) {
    //     tap_code(KC_EQL);
    //   }
    //   break;
    case BRIEFAND:
      if (pressed) {
        SEND_STRING(" and");
      }
      break;
    case BRIEFFUNCTION:
      if (pressed) {
        SEND_STRING("function");
      }
      break;
    
  }
}

void keyboard_post_init_user(void) {
  // Call the post init code.
  rgb_matrix_disable_noeeprom(); // disables Rgb, without saving settings
  // rgb_matrix_mode_noeeprom(RGB_MODE_PLAIN);
}
