// #include "sadekbaroudi.h"
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _MAIN,
    _QWERTY,
    _LOWER,
    _RAISE,
    _SYMBOL,
    _MOUSE,
    _MISCFUNCS,
    _ADJUST
    
};

enum combo_events {
  GRVCOMBO,
  EQLCOMBO,
  RHNUMPADLAYERCOMBO,
  LHSHFT,
  RHSHFT,
  NEXTSENTDOT,
  COMBOLENGTH,
};

enum custom_keycodes {
  MAC_PSCRR = SAFE_RANGE,
  MAC_PSCR,
  
};

uint16_t COMBO_LEN = COMBOLENGTH;


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define GUI_SC LGUI_T(KC_SCLN)
#define ALT_Q  LALT_T(KC_Q)
#define SHFT_J LSFT_T(KC_J)
#define CTRL_P LCTL_T(KC_P)

#define GUI_Z  RGUI_T(KC_Z)
#define ALT_V  RALT_T(KC_V)
#define SHFT_W RSFT_T(KC_W)
#define CTRL_G RCTL_T(KC_G)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_MAIN] = LAYOUT_fflx(
    KC_TAB,     KC_QUOT,    KC_COMM,  KC_DOT,     CTRL_P,   KC_Y,     KC_F,       CTRL_G,   KC_C,       KC_R,     KC_L,     KC_SLSH,  
    XXXXXXX,    KC_A,       KC_O,     KC_E,       KC_U,     KC_I,     KC_D,       KC_H,     KC_T,       KC_N,     KC_S,     KC_ENT, 
    KC_CAPS,    GUI_SC,     KC_Q,     KC_J,       KC_K,     KC_X,     KC_B,       KC_M,     KC_W,       KC_V,     GUI_Z,    KC_RGUI,  \
                            KC_MUTE,  TT(_LOWER), KC_SPC,   KC_LALT,  TT(_MOUSE), KC_BSPC,  TT(_RAISE), XXXXXXX
    ),

/* Lower
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |  Caps|      |      |      |      |             |      |      |      |   |  |   "  |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */
[_LOWER] = LAYOUT_fflx(
    KC_ESC,           LCTL(KC_C),   LCTL(KC_V),     LCTL(KC_X),   LCTL(KC_S),   LCTL(KC_Z), LCTL(KC_Y),  _______,  _______,   _______,  _______,  KC_BSLS,   \
    LCTL(KC_SLSH),    LCTL(KC_A),   KC_LBRC,        KC_LCBR,      KC_LPRN,      KC_MINS,    _______,     KC_RPRN,  KC_RCBR,   KC_RBRC,  _______,  _______,   \
    _______,          _______,      _______,        _______,      _______,      _______,    _______,     _______,  _______,   _______,  _______,  _______,   \
                                    _______,        _______,      _______,      _______,    _______,     _______,  _______,   _______ 
),  


/* Raise
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |  Caps|      |      |      |      |             |      |      |      |   |  |   "  |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */

[_RAISE] = LAYOUT_fflx(
    _______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_PLUS,    MO(_SYMBOL), MO(_MOUSE),  _______,  _______,  _______,  \
    _______,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_LEFT,     KC_DOWN,  KC_UP,    KC_RIGHT, KC_DEL,   \
    _______,    KC_COLN,    KC_COMM,    KC_DOT,    _______,     KC_ENT,     KC_SLSH,    KC_HOME,     KC_PGDN,  KC_PGUP,  KC_END,  _______,  \
                            _______,    _______,    _______,    _______,    _______,    _______,     _______,  _______
),  


[_SYMBOL] = LAYOUT_fflx(
    _______,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,      _______,    _______,    _______,  _______,  _______, KC_PIPE,  \
    _______,    KC_CIRC,    KC_AMPR,    KC_ASTR,    _______,    KC_UNDS,     _______,    _______,    _______,  _______,  _______, _______,   \
    _______,    KC_COLN,    KC_COMM,     KC_DOT,    _______,    _______,    _______,    _______,    _______,  _______,  _______, _______,  \
                            _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______
),

[_MOUSE] = LAYOUT_fflx(
    _______,    _______,    KC_RBRC,    KC_RCBR,    KC_RPRN,    _______,    _______,    _______,    _______,  _______,  _______, _______,  \
    _______,    _______,    KC_LBRC,    KC_LCBR,    KC_LPRN,    _______,    KC_BTN1,    KC_BTN3,    KC_BTN2,  _______,  _______, _______,   \
    _______,    _______,    _______,    _______,    _______,    _______,    KC_BTN4,    _______,    KC_BTN5,  _______,  _______, _______,  \
                            _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______
),  

[_MISCFUNCS] = LAYOUT_fflx(
    _______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      _______,    MAC_PSCRR,    MAC_PSCR,  _______,  KC_PSCR, KC_INS,  \
    _______,    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     _______,    _______,    _______,  _______,  _______, _______,   \
    _______,    KC_F11,     KC_F12,     _______,    _______,    _______,    _______,    _______,    _______,  _______,  _______, _______,  \
                            _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______ 
),  

[_ADJUST] = LAYOUT_fflx(
    RGB_TOG,    _______,    KC_MPRV,    KC_MNXT,    KC_MPLY,    _______,    DF(_MAIN),    _______,    _______,  _______,    _______,    RESET,    \
    _______,    _______,    KC_VOLD,    KC_VOLU,    KC_MUTE,    _______,    DF(_QWERTY),   _______,    _______,  _______,    _______,    _______,    \
    _______,    CMB_TOG,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    \
                            _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
),

// [_MOUSE] =  LAYOUT_fflx(
//   _______, _______, KC_WH_U, _______, KC_WH_D, _______,          _______, _______, _______, _______, _______, _______,
//   _______, KC_WH_L, KC_BTN3, KC_BTN2, KC_BTN1, KC_WH_R,          _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
//                     _______, _______, _______, _______,          _______, _______, _______, _______
// )

/* Qwerty
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  ESC |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |BckSpc|
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |  TAB |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |  SFT |   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  | SFT  |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */
// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_QWERTY] = LAYOUT_fflx(
  KC_ESC,  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,             KC_BSPC,
  KC_TAB,  LCTL_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F), KC_I,         KC_D,    RSFT_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), RCTL_T(KC_SCLN),  KC_QUOT,
  KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,          KC_RSFT,
                         KC_MUTE,      KC_BSLS,      KC_ENT,       LOWER,        RAISE,   KC_SPC,       KC_DEL,       LCTL(KC_BSPC)
)
};


const uint16_t PROGMEM lhshft[] = {KC_O, KC_DOT, COMBO_END};
const uint16_t PROGMEM rhshft[] = {KC_N, KC_C, COMBO_END};
const uint16_t PROGMEM nextsentdot[] = {KC_COMM, KC_DOT, KC_C, KC_R, COMBO_END}; 
const uint16_t PROGMEM grvcombo[] = {KC_TAB, KC_QUOT, COMBO_END};
const uint16_t PROGMEM eqlcombo[] = {KC_L, KC_SLSH, COMBO_END};
const uint16_t PROGMEM rhnumpadlayercombo[] = {KC_BSPC, TT(_RAISE), COMBO_END};

combo_t key_combos[] = {

    [LHSHFT] = COMBO(lhshft, OSM(MOD_LSFT)),
    [RHSHFT] = COMBO(rhshft, OSM(MOD_RSFT)),
    [NEXTSENTDOT] = COMBO_ACTION(nextsentdot),
    [GRVCOMBO] = COMBO(grvcombo, KC_GRV),
    [EQLCOMBO] = COMBO(eqlcombo, KC_EQL),
    [RHNUMPADLAYERCOMBO] = COMBO(rhnumpadlayercombo, MO(_MISCFUNCS)),

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




layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}



bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  // if (!process_caps_word(keycode, record)) { return false; }

  switch (keycode) {
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


void caps_word_set_user(bool active) {
    if (active) {
        rgblight_sethsv_noeeprom(HSV_AZURE);
    } else {
        rgblight_sethsv_noeeprom(HSV_OFF);
    }
}


#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    // default behavior if undefined
    if (index == 0) {
        // Conditional to reverse the direction of encoder number 1
        // The reason I have this is that for some of my boards, it supports two different types of encoders, and they may differ in direction
        #ifdef ENCODERS_A_REVERSE
        if (!clockwise) {
        #else
        if (clockwise) {
        #endif
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
      // Conditional to reverse the direction of encoder number 1
      // The reason I have this is that for some of my boards, it supports two different types of encoders, and they may differ in direction
      #ifdef ENCODERS_B_REVERSE
      if (!clockwise) {
      #else
      if (clockwise) {
      #endif
        tap_code16(KC_DOWN);
      }
      else{
        tap_code16(KC_UP);
      }
    }
    else if (index == 2) {
      #ifdef ENCODERS_C_REVERSE
      if (!clockwise) {
      #else
      if (clockwise) {
      #endif
        press_super_tab(true);
      } else {
        press_super_tab(false);
      }
    }

    return true;
}
#endif


const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 4, HSV_AZURE}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer
);

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}


void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom(HSV_OFF);
}

