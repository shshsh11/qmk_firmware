/*
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
    _MAIN2,
    _MPLSTRY,
    _PLOVER,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FN,
};

// #define _DEFAULT 0
// #define _MPLSTRY 1
// #define _PLOVER 10
// #define _LOWER 11
// #define _RAISE 12
// #define _ADJUST 20

// #define _FN 30

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
  PLOVER,
  EXT_PLV,
};

enum combo_events {
  GRVCOMBO,
  EQLCOMBO,
  BRIEFAND,
  // BRIEFFUNCTION,
  RHNUMPADLAYERCOMBO,
  LHCTRL,
  LHSHFT,
  LHALT,
  LHGUI,
  LHALTSHFT,
  RHCTRL,
  RHSHFT,
  RHALT,
  RHGUI,
  RHALTSHFT,
  NEXTSENTDOT,
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


#ifdef TAP_DANCE_ENABLE
    enum {
        DOT_TD = 0,
    };
    #define TD_DOT TD(DOT_TD)
#else
    #define TD_DOT KC_DOT
#endif

uint16_t last_keycode;
uint16_t last_keycode = KC_NO;

// #define COMBO_ONLY_FROM_LAYER _DEFAULT

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

// #define _______ KC_TRNS
// #define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* FUNCTION
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */

// maybe try tap dance for caps lock
// [_DEFAULT] = LAYOUT_ortho_5x14(
//    KC_GRV,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,      KC_5,       KC_6,     KC_7,    KC_8,    KC_9,    KC_0,      KC_EQL , 
//    KC_TAB,          KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,       KC_EQL,    KC_MINS,    KC_F,     KC_G,    KC_C,    KC_R,    KC_L,      KC_SLSH , 
//    KC_LCTL,         KC_A,    KC_O,    KC_E,    KC_U,    KC_I,       KC_EQL,    KC_MINS,    KC_D,     KC_H,    KC_T,    KC_N,    KC_S,      KC_ENT , 
//    // KC_LSFT,         GUI_SC,  ALT_Q,   SHFT_J,  CTRL_K,  KC_X,       KC_SLSH,   KC_BSLS,    KC_B,     CTRL_M,  SHFT_W,  ALT_V,   GUI_Z,     KC_RSFT,
//    KC_LSFT,         KC_SCLN,  KC_Q,   KC_J,  KC_K,  KC_X,       KC_SLSH,   KC_BSLS,    KC_B,     KC_M,  KC_W,  KC_V,   KC_Z,     KC_RSFT, 
//    _______,         KC_CAPS, KC_LGUI, KC_LALT, LOWER,   KC_SPC,     _______,   _______,    KC_BSPC,  RAISE,   KC_RALT, KC_RGUI, _______,    _______ 
// ),

[_MAIN] = LAYOUT_ortho_5x14(
   KC_GRV,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,      KC_5,       KC_6,     KC_7,    KC_8,    KC_9,    KC_0,      KC_EQL , \
   KC_TAB,          KC_QUOT, KC_COMM, KC_DOT,  CTRL_P,  KC_Y,       KC_EQL,    KC_MINS,    KC_F,     CTRL_G,    KC_C,    KC_R,    KC_L,      KC_SLSH , \
   KC_LCTL,         KC_A,    KC_O,    KC_E,    KC_U,    KC_I,       KC_EQL,    KC_MINS,    KC_D,     KC_H,    KC_T,    KC_N,    KC_S,      KC_ENT , \
   KC_LSFT,         GUI_SC,  KC_Q,   KC_J,  KC_K,  KC_X,       KC_SLSH,   KC_BSLS,    KC_B,     KC_M,  KC_W,  KC_V,   GUI_Z,     KC_RSFT, \
   _______,         KC_CAPS, KC_LGUI, KC_LALT, LOWER,   KC_SPC,     _______,   _______,    KC_BSPC,  RAISE,   KC_RALT, KC_RGUI, _______,    _______ 
),

[_MAIN2] = LAYOUT_ortho_5x14(
    KC_GRV,     KC_1,        KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_5,   KC_6,     KC_7,     KC_8,     KC_9,    KC_0,      KC_EQL,
    KC_TAB,     KC_Y,        KC_P,     KC_O,     KC_U,     KC_J,     KC_EQL,   KC_MINS,KC_K,     KC_D,   KC_L,     KC_C,     KC_W,     KC_QUOT,  
    KC_LCTL,    KC_I,        KC_N,     KC_E,     KC_A,     KC_COMM,  KC_EQL,   KC_MINS,KC_M,     KC_H,   KC_T,     KC_S,     KC_R,     KC_ENT, 
    KC_LSFT,    KC_Q,        KC_Z,     KC_SLSH,  KC_DOT,   KC_SCLN,  KC_EQL,   KC_MINS,KC_B,     KC_F,   KC_G,     KC_V,     KC_X,    KC_RSFT,  \
    XXXXXXX,    KC_CAPS,     KC_LGUI,  KC_LALT,  LOWER,    KC_SPC, _______,   _______,   KC_BSPC,  RAISE,  KC_RALT,  XXXXXXX,  XXXXXXX,  XXXXXXX
    ),

 [_MPLSTRY] = LAYOUT_ortho_5x14(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,      KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC,  KC_Y,    KC_U,    KC_I,    KC_O,      KC_P,    KC_QUOT, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______,  KC_H,    KC_J,    KC_K,    KC_L,      KC_SCLN, KC_ENT,  \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SLSH,  KC_BSLS, KC_N,    KC_M,    KC_COMM, KC_DOT,    KC_UP,   KC_RSFT, \
  _______, _______, _______,   _______, KC_SPC,  KC_LALT,  LOWER,   RAISE,    KC_SPC,  KC_LEFT, KC_DOWN, KC_LEFT,   KC_DOWN, KC_RGHT  \
 ),


[_LOWER] = LAYOUT_ortho_5x14(
  KC_ESC,  LCTL(KC_C), LCTL(KC_V), LCTL(KC_X), LCTL(KC_S), LCTL(KC_Z), _______, _______, LCTL(KC_Y), _______,  _______,  _______, _______, _______, \
  KC_ESC, LALT(KC_QUOT), LALT(KC_COMM), LALT(KC_DOT), LALT(KC_P), LALT(KC_Y), _______, _______,  _______, _______, _______, _______, _______, KC_BSLS, \
  _______, _______,  KC_LBRC,    KC_LCBR,    KC_LPRN,    KC_MINS, _______, _______,    _______,    KC_RPRN,    KC_RCBR,    KC_RBRC, _______, XXXXXXX, \
  _______, _______,  _______,    _______,    _______,    _______, _______, _______,    _______,    _______,    _______,    _______, _______, _______, \
  _______, _______,  _______,    _______,    _______,    _______, _______, _______,    _______,    _______,    _______,    _______, _______, _______ 
), 

[_RAISE] = LAYOUT_ortho_5x14(
  _______,   KC_F1,      KC_F2,      KC_F3,      KC_F4,   KC_F5,  KC_F11, KC_F12, KC_F6,    KC_F7,   KC_F8,    KC_F9,   KC_F10,   _______, \
  _______,  _______,    _______,    _______,    _______, _______, _______, _______, _______,  _______, _______,    _______,  KC_PSCR,  KC_INS, \
  _______,  _______,    _______,    _______,    _______, _______, _______, _______, _______,  KC_LEFT, KC_DOWN,  KC_UP,    KC_RIGHT,   KC_DEL, \
  _______,  _______,    _______,    _______,    _______, _______, _______, _______, _______,  KC_HOME,    KC_PGDN,  KC_PGUP,  KC_END,  _______, \
  _______,  _______,    _______,    _______,    _______, _______, _______, _______, KC_SPC,   _______, _______,  _______,  _______,  _______ 
), 

[_ADJUST] = LAYOUT_ortho_5x14(
  _______,   PLOVER, TO(_MPLSTRY), _______,  _______,   _______,  RGB_TOG, _______, _______,    _______, _______, ST_GEM,   ST_BOLT,   RESET, \
  _______,  _______,    KC_MPRV,    KC_MPLY,    KC_MNXT, _______, _______, _______, DF(_MAIN),  _______, _______,    OS_OFF,  OS_ON,  DEBUG, \
  _______,  _______,    KC_VOLD,    KC_VOLU,    KC_MUTE, _______, _______, _______, DF(_MAIN2),  _______, _______,  _______, _______,   _______, \
  _______,  _______,    _______,    _______,    _______, _______, _______, _______, _______,  _______, _______,  _______,  _______,  _______, \
  _______,  _______,    _______,    _______,    _______, _______, _______, _______, _______,   _______, _______,  STN_PWR,  STN_RE1,  STN_RE2 
), 



[_PLOVER] = LAYOUT_ortho_5x14(
  STN_N1,   STN_N2,     STN_N3,     STN_N4,     STN_N5,  STN_N6,   XXXXXXX, XXXXXXX,  STN_N7,  STN_N8,    STN_N9,    STN_NA,    STN_NB,    STN_NC, 
  KC_TAB,   STN_S1,     STN_TL,     STN_PL,     STN_HL,  STN_ST1,  XXXXXXX, XXXXXXX,  STN_ST3, STN_FR,    STN_PR,    STN_LR,    STN_TR,    STN_DR, 
  KC_LCTL,  STN_S2,     STN_KL,     STN_WL,     STN_RL,  STN_ST2,  XXXXXXX, XXXXXXX,  STN_ST4, STN_RR,   STN_BR,     STN_GR,   STN_SR,    STN_ZR, 
  KC_LSFT,  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, LOWER,    XXXXXXX, XXXXXXX,    RAISE,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, 
  XXXXXXX,  XXXXXXX,    KC_LGUI,    KC_LALT,    STN_A,   STN_O,   XXXXXXX, XXXXXXX,    STN_E,   STN_U, KC_BSPC,   XXXXXXX,  XXXXXXX,  XXXXXXX 
), 

/* FUNCTION
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */


 [_FN] = LAYOUT_ortho_5x14(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 )
};


const uint16_t PROGMEM fn_actions[] = {

};

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}



void sentence_end(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {

        // Double tapping TD_DOT produces
        // ". <one-shot-shift>" i.e. dot, space and capitalize next letter.
        // This helps to quickly end a sentence and begin another one
        // without having to hit shift.
        case 2:
            /* Check that Shift is inactive */
            if (!(get_mods() & MOD_MASK_SHIFT)) {
                tap_code(KC_SPC);
                /* Internal code of OSM(MOD_LSFT) */
                add_oneshot_mods(MOD_BIT(KC_LSHIFT));

            } else {
                // send ">" (KC_DOT + shift → ">")
                tap_code(KC_DOT);
            }
            break;

        // Since `sentence_end` is called on each tap
        // and not at the end of the tapping term,
        // the third tap needs to cancel the effects
        // of the double tap in order to get the expected
        // three dots ellipsis.
        case 3:
            // remove the added space of the double tap case
            tap_code(KC_BSPC);
            // replace the space with a second dot
            tap_code(KC_DOT);
            // tap the third dot
            tap_code(KC_DOT);
            break;

        // send KC_DOT on every normal tap of TD_DOT
        default:
            tap_code(KC_DOT);
    }
};

void sentence_end_finished (qk_tap_dance_state_t *state, void *user_data) {
    last_keycode = KC_DOT;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [DOT_TD] = ACTION_TAP_DANCE_FN_ADVANCED(sentence_end, sentence_end_finished, NULL),
};


// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
// {
//   // MACRODOWN only works in this function
//   switch (id) {
//   case 0:
//     if (record->event.pressed) {
//       register_code(KC_RSFT);
//     }
//     else {
//       unregister_code(KC_RSFT);
//     }
//     break;
//   }
//   return MACRO_NONE;
// };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  // if (!process_caps_word(keycode, record)) { return false; }

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
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;

  }
  return true;
}

// void led_set_user(uint8_t usb_led) {

//     if (is_caps_word_on()) {
//       DDRB |= (1 << 2); PORTB &= ~(1 << 2);
//       rgblight_setrgb(25, 25, 255);
//     } else {
//       layer_state_set_user(layer_state);
//       // rgblight_setrgb(0, 0, 0);
//     }

//     // if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
//     //     DDRB |= (1 << 2); PORTB &= ~(1 << 2);
        
//     // } else {
//     //     DDRB &= ~(1 << 2); PORTB &= ~(1 << 2);
        
//     // }
// }


void matrix_scan_user(void) {
  if (is_caps_word_on()) {
      rgblight_setrgb(25, 25, 255);
    } 
    else {
      layer_state_set_user(layer_state);
    }
}


uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    // case _RAISE:
    //   rgblight_setrgb(0xFF, 0x00, 0x00);
    //   break;
    default: //_DEFLT
      rgblight_setrgb(0,0,0);
      break;

  }

  return state;

//   // if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
//   //   rgblight_setrgb(0, 170, 196);
//   // }
//     switch (get_highest_layer(state)) {
//     // case _MAIN:
//     //     rgblight_setrgb(0, 171, 197);
//     //     if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
//     //       rgblight_setrgb(255, 0, 0);
//     //     }
        
//     //     break;
//     // case _MAIN2:
//     //     rgblight_setrgb(255, 239, 213);
//     //     if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
//     //       rgblight_setrgb(255, 0, 0);
//     //     }
//     //     break;
// //     case _RAISE:
// //         rgblight_setrgb(0xFF, 0x00, 0x00);
// //         break;
// //     case _LOWER:
// //         rgblight_setrgb(0x00, 0xFF, 0x00);
// //         break;
// //     case _ADJUST:
// //         rgblight_setrgb(255, 239, 213);
// //         break;
// //     case _PLOVER:
// //         rgblight_setrgb(134, 96, 142);
// //         break;
//     default: //  for any other layers, or the default layer

//       // rgblight_setrgb(255, 0, 0);

//       // if (host_keyboard_led_state().caps_lock) {
//       if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
//           rgblight_setrgb(255, 0, 0);
//         } else {
//           rgblight_setrgb(0, 0, 255);
//         }
//         break;
//     }
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

const uint16_t PROGMEM lhctrl[] = {KC_U, KC_P, COMBO_END};
const uint16_t PROGMEM lhshft[] = {KC_O, KC_DOT, COMBO_END};
const uint16_t PROGMEM lhalt[] = {KC_O, KC_COMM, COMBO_END};
const uint16_t PROGMEM lhgui[] = {KC_A, KC_QUOT, COMBO_END};
const uint16_t PROGMEM lhaltshft[] = {KC_O, KC_COMM, KC_DOT, COMBO_END};


const uint16_t PROGMEM rhctrl[] = {KC_H, KC_G, COMBO_END};
const uint16_t PROGMEM rhshft[] = {KC_N, KC_C, COMBO_END};
const uint16_t PROGMEM rhalt[] = {KC_N, KC_R, COMBO_END};
const uint16_t PROGMEM rhgui[] = {KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM rhaltshft[] = {KC_N, KC_R, KC_C, COMBO_END};

const uint16_t PROGMEM briefand[] = {KC_A, KC_O, KC_DOT, COMBO_END};


const uint16_t PROGMEM nextsentdot[] = {KC_COMM, KC_DOT, KC_C, KC_R, COMBO_END}; 
// const uint16_t PROGMEM brieffunction[] = {KC_COMM, KC_DOT, KC_M, KC_T, KC_N, KC_S, COMBO_END};

// const uint16_t PROGMEM lhnumpadlayer[] = {KC_SPC, LOWER, COMBO_END};
combo_t key_combos[] = {
    [GRVCOMBO] = COMBO(grvcombo, KC_GRV),
    [EQLCOMBO] = COMBO(eqlcombo, KC_EQL),
    // [LHCTRL] = COMBO(lhctrl, KC_LCTL),
    [LHSHFT] = COMBO(lhshft, OSM(MOD_LSFT)),
    // [LHALT] = COMBO(lhalt, KC_LALT),
    // [LHGUI] = COMBO(lhgui, KC_LGUI),
    // [LHALTSHFT] = COMBO_ACTION(lhaltshft),
    // [RHCTRL] = COMBO(rhctrl, KC_RCTL),
    [RHSHFT] = COMBO(rhshft, OSM(MOD_RSFT)),
    // [RHALT] = COMBO(rhalt, KC_RALT),
    // [RHGUI] = COMBO(rhgui, KC_RGUI),
    // [RHALTSHFT] = COMBO_ACTION(rhaltshft),
    // [BRIEFAND] = COMBO_ACTION(briefand),
    // [BRIEFFUNCTION] = COMBO_ACTION(brieffunction),
    [NEXTSENTDOT] = COMBO_ACTION(nextsentdot),
    // [RHNUMPADLAYERCOMBO] = COMBO(rhnumpadlayercombo, MO(_NUMPAD)),
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
    // case LHALTSHFT:
    //   if (pressed) {
    //     register_code(KC_LSFT);
    //     register_code(KC_LALT);
    //   } else {
    //     unregister_code(KC_LALT);
    //     unregister_code(KC_LSFT);
    //   }
    //   break;
    // case RHALTSHFT:
    //   if (pressed) {
    //     register_code(KC_RSFT);
    //     register_code(KC_RALT);
    //   } else {
    //     unregister_code(KC_RALT);
    //     unregister_code(KC_RSFT);
    //   }
    //   break;
    // case BRIEFAND:
    //   if (pressed) {
    //     SEND_STRING(" and");
    //   }
    //   break;
    // case BRIEFFUNCTION:
    //   if (pressed) {
    //     SEND_STRING("function");
    //   }
    //   break;
    
  }
}



// void keyboard_post_init_user(void) {
//   // Customise these values to desired behaviour
//   debug_enable=true;
//   debug_matrix=true;
//   debug_keyboard=true;
//   //debug_mouse=true;
// }


void keyboard_post_init_user(void) {

  // rgb_matrix_disable_noeeprom(); // disables Rgb, without saving settings
  // rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
  rgblight_setrgb(0, 0, 0);
  // rgblight_setrgb(50, 50, 50);
}