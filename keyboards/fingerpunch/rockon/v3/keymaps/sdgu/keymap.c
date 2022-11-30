#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _MAIN,
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};


enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST,
  SNIPEHOLD,
};

enum combo_events {
  LHSHFT,
  RHSHFT,
  COMBOLENGTH,
};
uint16_t COMBO_LEN = COMBOLENGTH;


#define _CTRLZ LCTL(KC_Z)
#define _CTRLC LCTL(KC_C)
#define _CTRLV LCTL(KC_V)
#define _CTRLX LCTL(KC_X)

#define GUI_SC LGUI_T(KC_SCLN)
#define ALT_Q  LALT_T(KC_Q)
#define SHFT_J LSFT_T(KC_J)
#define CTRL_P LCTL_T(KC_P)

#define GUI_Z  RGUI_T(KC_Z)
#define ALT_V  RALT_T(KC_V)
#define SHFT_W RSFT_T(KC_W)
#define CTRL_G RCTL_T(KC_G)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 

[_MAIN] = LAYOUT_rockon(
    KC_GRV,    KC_1,         KC_2,      KC_3,      KC_4,      KC_5,      KC_LPRN,                                          _CTRLX,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_EQL,
    KC_TAB,    KC_QUOT,      KC_COMM,   KC_DOT,    CTRL_P,    KC_Y,      KC_LBRC,                                          _CTRLV,      KC_F,      CTRL_G,    KC_C,      KC_R,      KC_L,      KC_SLSH,
    KC_LCTL,   KC_A,         KC_O,      KC_E,      KC_U,      KC_I,      KC_LCBR,                                          _CTRLC,      KC_D,      KC_H,      KC_T,      KC_N,      KC_S,      KC_ENT,
    KC_LSFT,   GUI_SC,       KC_Q,      KC_J,      KC_K,      KC_X,      QK_BOOT,                                          _CTRLZ,      KC_B,      KC_M,      KC_W,      KC_V,      GUI_Z,     KC_RSFT,
               KC_MUTE,      _______,   KC_LALT,   LOWER,     KC_SPC,    KC_LGUI,   KC_MS_BTN2, KC_MS_BTN3, KC_MS_BTN1,    SNIPEHOLD,        KC_BSPC,   RAISE,     KC_RALT,   _______,   KC_MUTE,
                                                                                                KC_MS_BTN3
),


[_QWERTY] = LAYOUT_rockon(
    KC_ESC,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_LPRN,                                          KC_RPRN,   KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_BSPC,
    KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_LBRC,                                          KC_RBRC,   KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSLS,
    KC_CAPS,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_LCBR,                                          KC_RCBR,   KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT,
    KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      ADJUST,                                           ADJUST,    KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_ENT,
               KC_MUTE,   KC_LCTL,   KC_LGUI,   LOWER,     KC_SPC,    KC_LALT,   KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2,    KC_RALT,   KC_SPC,    RAISE,     KC_RGUI,   KC_RCTL,   KC_MUTE,
                                                                                              KC_MS_BTN3
),


[_LOWER] = LAYOUT_rockon(
    KC_ESC,         LCTL(KC_C),    LCTL(KC_V),     LCTL(KC_X),   LCTL(KC_S), LCTL(KC_Z), LCTL(KC_Y),                         _______,  _______,    _______,  _______,  _______,  _______, _______,
    KC_ESC,         LALT(KC_QUOT), LALT(KC_COMM),  LALT(KC_DOT), LALT(KC_P), LALT(KC_Y), _______,                            _______,  _______,    _______,  _______,  _______,  _______, KC_BSLS,
    LCTL(KC_SLSH),  LCTL(KC_A),    KC_LBRC,        KC_LCBR,      KC_LPRN,    KC_MINS,    _______,                            _______,  _______,    KC_RPRN,  KC_RCBR,  KC_RBRC,  _______, XXXXXXX, 
    _______,        _______,       _______,        _______,      _______,    KC_UNDS,    _______,                            _______,  _______,    _______,  _______,  _______, _______, _______,
                    _______,       _______,        _______,      _______,    _______,    _______, _______, _______, _______, _______,  _______,    _______,  _______,  _______, _______, 
                                                                                                           _______
),

[_RAISE] = LAYOUT_rockon(
    _______,  KC_F1,      KC_F2,      KC_F3,      KC_F4,   KC_F5,   KC_F11,                             KC_F12,  KC_F6,    KC_F7,   KC_F8,    KC_F9,   KC_F10,   _______,
    _______,  _______,    _______,    _______,    _______, _______, _______,                            _______, _______,  _______, _______,  _______, KC_PSCR,  KC_INS, 
    _______,  _______,    _______,    _______,    _______, _______, _______,                            _______, _______,  KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, KC_DEL, 
    _______,  _______,    _______,    _______,    _______, _______, _______,                            _______, _______,  KC_HOME, KC_PGDN,  KC_PGUP, KC_END,   _______, 
              _______,    _______,    _______,    _______, _______, _______, _______, _______, _______, _______, KC_SPC,   _______, _______,  _______,  _______, 
                                                                                      _______
),



[_ADJUST] =  LAYOUT_rockon(
    _______,  _______,    TO(_MAIN), _______,  _______,   _______,  RGB_TOG,                            _______, _______,      _______, _______,  _______,  _______,  QK_BOOT, 
    _______,  _______,    KC_MPRV,    KC_MPLY,    KC_MNXT, _______, _______,                            _______, DF(_MAIN),    _______, _______,  OS_OFF,  OS_ON,     DEBUG,
    _______,  _______,    KC_VOLD,    KC_VOLU,    KC_MUTE, _______, _______,                            _______, DF(_QWERTY),  _______, _______,  _______, _______,   _______, 
    _______,  _______,    _______,    _______,    _______, _______, _______,                            _______, _______,      _______, _______,  _______,  _______,  _______, 
              _______,    _______,    _______,    _______, _______, KC_NUM,  _______, _______, _______, _______, _______,      _______, _______,   _______,  _______,   
                                                                                      _______
)
};


const uint16_t PROGMEM lhshft[] = {KC_O, KC_DOT, COMBO_END};
const uint16_t PROGMEM rhshft[] = {KC_N, KC_C, COMBO_END};

combo_t key_combos[] = {
    [LHSHFT] = COMBO(lhshft, OSM(MOD_LSFT)),
    [RHSHFT] = COMBO(rhshft, OSM(MOD_RSFT)),
};

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
        case SNIPEHOLD:
            if (record->event.pressed) {
                fp_snipe_keycode_set(true);
            } else {
                fp_snipe_keycode_set(false);
            }
            return false;
            break;
        default:
            break;
    }

    return true;
}



#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    // default behavior if undefined
    if (index == 1) {
        #ifdef ENCODERS_B_REVERSE
        if (!clockwise) {
        #else
        if (clockwise) {
        #endif
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 0) {
        #ifdef ENCODERS_A_REVERSE
        if (!clockwise) {
        #else
        if (clockwise) {
        #endif
            tap_code16(KC_WH_D);
        }
        else{
            tap_code16(KC_WH_U);
        }
    }
    else if (index == 2) { // middle encoder
        #ifdef ENCODERS_C_REVERSE
        if (!clockwise) {
        #else
        if (clockwise) {
        #endif
            tap_code16(KC_WH_D);
        }
        else{
            tap_code16(KC_WH_U);
        }
    }

    return true;
}
#endif
