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

// sdgudev branch
/* @@@@@ maybe implement @@@@@
  - similarly, explore what combos to use for numbers for reason as above 
  - how does chording work for combos? any time you press multiple keys, it check if it's a combo? look into how layer independent combos work 
  - maybe leader key on outer columns, maybe leader key for selecting words/lines
  - maybe only have shift for combo and use modtaps for the other three
  - make more use of keyboard shortcuts for navigation
  - look into vim more
  - block out tab on raise layers and such
  - maybe have the enter slot be trns on all layers, so that all layers can access enter. would need to move delete on raise 
  - consider numpad number layout
  - macro for control+/
  - < and > in symbol layer? 
  - oneshot setup for some things
  - tap dance on num layer for parens and braces (instead of having another layer)
  - combo for underscore on main layer FOR_TYPING_THESE_THINGS
  - double shift to deactivate cap word, or block double shift while in caps word (currently can cause issues if trying to double shift during caps word)
  - shift combo custom key release to type one of the letters (type the letter that you let go or the letter still held?)
  - combos for parens/brackets with key release (or key still held) determining which to send
  - move gui combo since it gets accidentally double hit a lot
  - macro for "w" and "r" 
  - TD_DOT: Double tap the dot key to produce . space One-Shot Shift to quickly flow from one sentence to another. (from precondition)
    - or, steno period. ,.cr for period with space and next letter cap
    - need a fix for typing .., like going up one directory
  - control + + and control + - macros (zooming)
  - clean up organization of other files
  - indicator if oneshot shift (or other oneshot mods?) is on
  - multi-shot key (activate one-shot after using it, can string keypresses on another layer together, like if numbers are on a different layer) https://discord.com/channels/440868230475677696/869812721552601088/918251721791258686
  - one key alt tab? https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_macros#super-alt-tab
  - backspace on raise layer that does not require lifting thumb
  - holding space while typing something automatically surrounds with space https://discord.com/channels/440868230475677696/869812721552601088/920066139806138409
  - delete for left hand (so can use mouse and delete easier)
  - shift + hrm quickly results in unshifted hrm key to be sent, don't want this 
  - one handed experimental mirror layout, but automatically switch to a normal one if rhside of keyboard is used
  - misc
  - redefine all single letter keys to be KC_AAAA or something so that line lengths are easier to deal with
  - some combos can have a longer term, like l/ for =, since those sequences are unlikely to be bigrams
  - control + / macro
  
  
  @@@@@ addressed @@@@@
  - look into decreasing combo term since "e a" rolls can sometimes trigger "7" --- not relevant anymore since not using combos for numbers
  - "s t" rolls also sometimes trigger "7" on the right hand --- not relevant anymore (see above)
  - look into why KC_NO behaves like LOWER --- seems fixed
  - light indicator for CAPS LOCK --- done as a part of implementing caps word
  - keep another LALT as a thumb key since it is easier for alt tab that way --- done
  - control (k and m) often hit the modded versions, while shift (j and w) often sends the non-mod plus the key --- this has been explored with PERMISSIVE_HOLD and HOLD_ON_OTHER_KEY_PRESS, no longer relevant because not using mod taps
  - column combo (home and top row) mods --- does not work well for shift
  - try shift on index fingers -- not relevant anymore since not using hrm
  - symbol layer (combo?) --- just a MO from raise layer
  - colon on numbers layer (for i in 1:10) --- done
  - combos on raise layer for control and shift, so i don't have to mod first before changing layers --- done with using #define COMBO_ONLY_FROM_LAYER 0
  - braces and parens on raise (number) layer, or a layer accessible from raise (symbolv2 or something) --- done
  - add toggles on outer columns (or combos) to number layer and such for one handed usage (layer tap toggle TT) --- done with TT on regular positions
  - page up and page down --- done, along with home and end
  - layer for nav, printscreen, etc --- moved printscreen, nav is on raise layer
  - combo from layer 0, except when on steno layer --- disable combos when in steno layer, as any in alphas would interfere
  - fix: if I type _ while in caps word mode and don't intend to type any more, I can't get out of it --- fixed, by using caps lock in caps word implementation, I can just designate those keys to not exit caps word and not worry about having to not shift them
    - potentially disable permissive_hold as I can unintentionally trigger that
  - macro for macos screenshotting
*/



#include QMK_KEYBOARD_H
#include "keymap_steno.h"
#include "keymap.h"

enum layers {
    _MAIN,
    _MAIN2,
    _LOWER,
    _RAISE,
    _SYMBOL,
    _SYMBOL2,
    _MISCFUNCS,
    _PLOVER,
    _ADJUST,
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  SYMBOL,
  SYMBOL2,
  PLOVER,
  ADJUST,
  EXT_PLV,
  MAC_PSCRR,
  MAC_PSCR,
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

#define ST_BOLT QK_STENO_BOLT
#define ST_GEM  QK_STENO_GEMINI

#define GUI_SC LGUI_T(KC_SCLN)
#define ALT_Q  LALT_T(KC_Q)
#define SHFT_J LSFT_T(KC_J)
#define CTRL_P LCTL_T(KC_P)

#define GUI_Z  RGUI_T(KC_Z)
#define ALT_V  RALT_T(KC_V)
#define SHFT_W RSFT_T(KC_W)
#define CTRL_G RCTL_T(KC_G)

// this is for other stuff in precondition's keymap
uint16_t last_keycode = KC_NO;
// ',.p lrcg
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    [_MAIN] = LAYOUT_ortho_4x12(
    KC_TAB,     KC_QUOT,          KC_COMM,  KC_DOT,   CTRL_P,   KC_Y,     KC_F,     CTRL_G, KC_C,     KC_R,     KC_L,     KC_SLSH,  
    XXXXXXX,    KC_A,             KC_O,     KC_E,     KC_U,     KC_I,     KC_D,     KC_H,   KC_T,     KC_N,     KC_S,     KC_ENT, 
    XXXXXXX,    GUI_SC,           KC_Q,     KC_J,     KC_K,     KC_X,     KC_B,     KC_M,   KC_W,     KC_V,     GUI_Z,    XXXXXXX,  \
    XXXXXXX,    KC_CAPS,          XXXXXXX,  KC_LALT,  TT(_LOWER),    KC_SPC,   KC_BSPC,  TT(_RAISE),  KC_RALT,  XXXXXXX,  XXXXXXX,  XXXXXXX
    ),

    [_MAIN2] = LAYOUT_ortho_4x12(
    KC_TAB,     KC_Y,        KC_P,     KC_O,     KC_U,     KC_J,     KC_K,     KC_D,   KC_L,     KC_C,     KC_W,     KC_QUOT,  
    KC_LCTL,    KC_I,        KC_N,     KC_E,     KC_A,     KC_COMM,  KC_M,     KC_H,   KC_T,     KC_S,     KC_R,     KC_ENT, 
    XXXXXXX,    KC_Q,        KC_Z,     KC_SLSH,  KC_DOT,   KC_SCLN,  KC_B,     KC_F,   KC_G,     KC_V,     KC_X,    XXXXXXX,  \
    XXXXXXX,    KC_CAPS,     KC_LGUI,  KC_LALT,  TT(_LOWER),    KC_SPC,   KC_BSPC,  TT(_RAISE),  KC_RALT,  XXXXXXX,  XXXXXXX,  XXXXXXX
    ),


    [_LOWER] = LAYOUT_ortho_4x12(
    KC_ESC,           LCTL(KC_C),   LCTL(KC_V),     LCTL(KC_X),   LCTL(KC_S),   LCTL(KC_Z), LCTL(KC_Y),  _______,  _______,   _______,  _______,  KC_BSLS,   \
    LCTL(KC_SLSH),    LCTL(KC_A),   KC_LBRC,        KC_LCBR,      KC_LPRN,      KC_MINS,    _______,     KC_RPRN,  KC_RCBR,   KC_RBRC,  _______,  _______,   \
    _______,    _______,      _______,        _______,      _______,      _______,    _______,     _______,  _______,   _______,  _______,  _______,   \
    _______,    _______,      _______,        _______,      _______,      _______,    _______,     _______,  _______,   _______,  _______,  _______    
    ),  

    [_RAISE] = LAYOUT_ortho_4x12(
    _______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_PLUS,    SYMBOL,    SYMBOL2,  _______,  _______,  _______,  \
    _______,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_LEFT,    KC_DOWN,  KC_UP,    KC_RIGHT, KC_DEL,   \
    _______,    KC_COLN,    KC_COMM,    KC_DOT,    _______,     KC_ENT,     KC_SLSH,    KC_HOME,    KC_PGDN,  KC_PGUP,  KC_END,  _______,  \
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______,  _______,  _______  
    ),  

    [_SYMBOL] = LAYOUT_ortho_4x12(
    _______,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,      _______,    _______,    _______,  _______,  _______, KC_PIPE,  \
    _______,    KC_CIRC,    KC_AMPR,    KC_ASTR,    _______,    KC_UNDS,     _______,    _______,    _______,  _______,  _______, _______,   \
    _______,    KC_COLN,    KC_COMM,     KC_DOT,    _______,    _______,    _______,    _______,    _______,  _______,  _______, _______,  \
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______,  _______, _______  
    ),

    [_SYMBOL2] = LAYOUT_ortho_4x12(
    _______,    _______,    KC_RBRC,    KC_RCBR,    KC_RPRN,     _______,      _______,    _______,    _______,  _______,  _______, _______,  \
    _______,    _______,    KC_LBRC,    KC_LCBR,    KC_LPRN,    _______,     _______,    _______,    _______,  _______,  _______, _______,   \
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______,  _______, _______,  \
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______,  _______, _______  
    ),  

    [_MISCFUNCS] = LAYOUT_ortho_4x12(
    _______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      _______,    MAC_PSCRR,    MAC_PSCR,  _______,  KC_PSCR, KC_INS,  \
    _______,    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     _______,    _______,    _______,  _______,  _______, _______,   \
    _______,    KC_F11,     KC_F12,     _______,    _______,    _______,    _______,    _______,    _______,  _______,  _______, _______,  \
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______,  _______, _______  
    ),  

    [_ADJUST] = LAYOUT_ortho_4x12(
    _______,    PLOVER,     KC_MPRV,    KC_MNXT,    KC_MPLY,    _______,    DF(_MAIN),    _______,    _______,    ST_GEM,     ST_BOLT,    RESET,    \
    _______,    EXT_PLV,    KC_VOLD,    KC_VOLU,    KC_MUTE,    _______,    DF(_MAIN2),   _______,    _______,    _______,    _______,    _______,    \
    _______,    CMB_TOG,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    \
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
    case SYMBOL:
      if (record->event.pressed) {
        layer_on(_SYMBOL);
        
      } else {
        layer_off(_SYMBOL);
        
      }
      return false;
      break;
    case SYMBOL2:
      if (record->event.pressed) {
        layer_on(_SYMBOL2);
        
      } else {
        layer_off(_SYMBOL2);
        
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
          combo_disable();
        }
        return false;
        break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
        combo_enable();
      }
      return false;
      break;
    case MAC_PSCRR:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI("4"))));
      } else {

      }
      return false;
      break;
    case MAC_PSCR:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LSFT("4")));
      } else {

      }
      return false;
      break;

  }
  return true;
}


// bool gl_isadjuston = false; 

// void matrix_scan_user(void) {
    
//     if (!gl_isadjuston && IS_LAYER_ON(_LOWER) && IS_LAYER_ON(_RAISE))
//     {
//       layer_on(_ADJUST);
//       gl_isadjuston = true;
//     }
//     if (gl_isadjuston && !(IS_LAYER_ON(_LOWER) && IS_LAYER_ON(_RAISE)))
//     {
//       layer_off(_ADJUST);
//       gl_isadjuston = false;
//     }  
// }


layer_state_t layer_state_set_user(layer_state_t state) {
    // switch (get_highest_layer(state)) {
    // case _MAIN:
    //     rgb_matrix_sethsv_noeeprom(188, 255, 196); // 0, 170, 196
    //     break;
    // case _RAISE:
    //     rgb_matrix_sethsv_noeeprom(12, 171, 238); // 0, 255, 0 -> 238, 108, 77
    //     break;
    // case _LOWER:
    //     rgb_matrix_sethsv_noeeprom(155, 74, 83); // 255, 0, 0 -> 59, 82, 73
    //     break;
    // case _ADJUST:
    //     rgb_matrix_sethsv_noeeprom(36, 43, 255); // 255, 238, 212
    //     break;
    // case _PLOVER:
    //     rgb_matrix_sethsv_noeeprom(290, 82, 143); // 135, 97, 143
    //     break;
    // default: //  for any other layers, or the default layer
    //     rgb_matrix_sethsv_noeeprom(0, 0, 0);
    //     break;
    // }
  // return state;
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // if (host_keyboard_led_state().caps_lock) {
    if (host_keyboard_led_state().caps_lock || is_caps_word_on()) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            // if the led position has the flag for keylight
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, 0, 170, 196);
            }
        }
    }
}

// void caps_word_set_user(bool active) {
//   if (active) {
//       for (uint8_t i = led_min; i <= led_max; i++) {
//           // if the led position has the flag for keylight
//           if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
//               rgb_matrix_set_color(i, 0, 170, 196);
//           }
//       }
//   } else {
//     rgb_matrix_sethsv_noeeprom(0, 0, 0);
//   }
// }





// add briefs. 'for', 'that', 'this' etc.
// add some programming briefs like 'function'?
const uint16_t PROGMEM grvcombo[] = {KC_TAB, KC_QUOT, COMBO_END};
const uint16_t PROGMEM eqlcombo[] = {KC_L, KC_SLSH, COMBO_END};
const uint16_t PROGMEM rhnumpadlayercombo[] = {KC_BSPC, TT(_RAISE), COMBO_END};

// const uint16_t PROGMEM lhnumpadlayer[] = {KC_SPC, LOWER, COMBO_END};
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


combo_t key_combos[] = {
    [GRVCOMBO] = COMBO(grvcombo, KC_GRV),
    [EQLCOMBO] = COMBO(eqlcombo, KC_EQL),
    [RHNUMPADLAYERCOMBO] = COMBO(rhnumpadlayercombo, MO(_MISCFUNCS)),

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
    [NEXTSENTDOT] = COMBO_ACTION(nextsentdot),
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

    // [BRIEFAND] = COMBO_ACTION(briefand),
    // [BRIEFFUNCTION] = COMBO_ACTION(brieffunction),
    // COMBO(lhnumpadlayer, MO(_MISCFUNCS)),
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
    case LHALTSHFT:
      if (pressed) {
        register_code(KC_LSFT);
        register_code(KC_LALT);
      } else {
        unregister_code(KC_LALT);
        unregister_code(KC_LSFT);
      }
      break;
    case RHALTSHFT:
      if (pressed) {
        register_code(KC_RSFT);
        register_code(KC_RALT);
      } else {
        unregister_code(KC_RALT);
        unregister_code(KC_RSFT);
      }
      break;
    case BRIEFAND:
      if (pressed) {
        SEND_STRING(" and");
      }
      break;
    // case BRIEFFUNCTION:
    //   if (pressed) {
    //     SEND_STRING("function");
    //   }
    //   break;
    
  }
}

void keyboard_post_init_user(void) {

  // rgb_matrix_disable_noeeprom(); // disables Rgb, without saving settings
  rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
  rgb_matrix_sethsv_noeeprom(0, 0, 0);
  
}
