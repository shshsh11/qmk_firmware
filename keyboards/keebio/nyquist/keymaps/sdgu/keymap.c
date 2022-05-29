#include "nyquist.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_steno.h"
extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0
#define _COLEMAK 1
#define _QWERTY 2
#define _LOWER 11
#define _RAISE 12

#define _DVORAK_OH 5
#define _DVORAK_OHM 6

#define _DVORAK_OHL 7
#define _DVORAK_OHR 8

#define _FUSION 9
#define _PLOVER 10
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  DVORAK_OH,
  DVORAK_OHM, //M for mirror
  DVORAK_OHR, //R for raise
  DVORAK_OHL, //L for lower
  LOWER,
  RAISE,
  ADJUST,
  FUSION,
  PLOVER,
  EXT_PLV,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define ST_BOLT QK_STENO_BOLT
#define ST_GEM  QK_STENO_GEMINI
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL, \
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |   /  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS |      | Win  | Alt  |Lower |Space |bkspc |Raise | Alt  |  Win |      |ADJUST|
 * `-----------------------------------------------------------------------------------'
 */
[_DEFAULT] = KEYMAP( \
  KC_GRV,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,      KC_EQL, \
  KC_TAB,          KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,     KC_G,    KC_C,    KC_R,    KC_L,      KC_SLSH, \
  KC_LCTL,         KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,     KC_H,    KC_T,    KC_N,    KC_S,      KC_ENT, \
  KC_LSFT,         KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,     KC_M,    KC_W,    KC_V,    KC_Z,      KC_RSFT , \
  ADJUST,         ADJUST,  KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_BSPC,  RAISE,   KC_RALT, KC_RGUI, ADJUST,    ADJUST \
),

/* Lower       
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |CtrlC |CtrlV |CtrlX |CtrlS |CtrlZ |CtrlY |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |LALT' |LALT, |LALT. |LALTp |LALTy |      |      |      |      |      |   \  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |  [   |   {  |   (  |  -   |      |   )  |   }  |   ]  |      |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  up  |  ]   |   }  |   )  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | left | down |right |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_ESC,  LCTL(KC_C),    LCTL(KC_V),       LCTL(KC_X),      LCTL(KC_S),   LCTL(KC_Z),   LCTL(KC_Y),    _______,    _______,    _______, _______, _______, \
  _______, LALT(KC_QUOT), LALT(KC_COMM),    LALT(KC_DOT),    LALT(KC_P),   LALT(KC_Y),   _______,    _______,    _______,    _______, _______, KC_BSLS, \
  _______, _______,       KC_LBRC,          KC_LCBR,         KC_LPRN,      KC_MINS,      _______,    KC_RPRN,    KC_RCBR,    KC_RBRC, _______, XXXXXXX, \
  _______, KC_UP,         KC_RBRC,          KC_RCBR,         KC_RPRN,      _______,    _______,    _______,    _______,    _______, _______, _______, \
  KC_LEFT, KC_DOWN,       KC_RIGHT,          _______,     _______,         KC_BSPC,    _______,    _______,    _______,    _______, _______, _______ \
), 

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9 |  F10  | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | prev | pause| next |      |      |      |      |  up  |      |prntsc|  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | vol- | vol+ | mute |      |      | left | down |right |  Ins | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_F11,   KC_F1,      KC_F2,      KC_F3,      KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,    KC_F9,   KC_F10,   KC_F12, \
  _______,  KC_MPRV,    KC_MPLY,    KC_MNXT,    _______, _______, _______,  _______, KC_UP,    _______,  KC_PSCR,  KC_BSLS, \
  _______,  _______,    KC_VOLD,    KC_VOLU,    KC_MUTE, _______, _______,  KC_LEFT, KC_DOWN,  KC_RIGHT, KC_INS,   KC_DEL, \
  _______,  _______,    _______,    _______,    _______, _______, _______,  _______, _______,  _______,  _______,  _______, \
  _______,  _______,    _______,    _______,    _______, _______, KC_SPC,   _______, _______,  _______,  _______,  _______ \
), 

/* Fusion 360 
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |   f  |   c  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   l  |      |   e  |      |   d  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |   t  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUSION] = KEYMAP( \
  _______,   _______,   _______,    _______,    _______,   _______,     _______,    _______,   _______,    _______,   _______,   _______, \
  _______,  KC_L,       KC_R,       KC_C,       XXXXXXX, XXXXXXX,       _______,    KC_4,      KC_5,       KC_6,  _______,  _______, \
  _______,  XXXXXXX,    XXXXXXX,    KC_E,       KC_F,    KC_D,          _______,    KC_1,      KC_2,       KC_3, _______,   _______, \
  _______,  XXXXXXX,    XXXXXXX,    KC_T,       XXXXXXX, XXXXXXX,       _______,    _______,   KC_0,       _______,  _______,  _______, \
  _______,  _______,    _______,    _______,    _______, _______,       _______,    _______,   _______,    _______,  _______,  _______ \
), 

/* Dvorak one handed base layer experimental
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   l  |   r  |   c  |   g  |   f  |   y  |   p  |   .  |   ,  |   '  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   '  |   ,  |   .  |   p  |   y  |   d  |   h  |   t  |   n  |   s  |   /  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ent  |   A  |   O  |   E  |   U  |   I  |   i  |   u  |   e  |   o  |   a  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   s  |   n  |   t  |   h  |   d  |   f  |   g  |   c  |   r  |   l  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |OH LOW|OH RAI| BCSP |Space |bkspc |Raise | Alt  |  Win |      |ADJUST|
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK_OH] = KEYMAP( \
  KC_GRV,    KC_L,    KC_R,       KC_C,       KC_G,       KC_F,            KC_6,            KC_7,    KC_8,    KC_9,    KC_0,      KC_EQL, \
  KC_TAB,    KC_QUOT, KC_COMM,    KC_DOT,     KC_P,       KC_Y,            KC_F,            KC_G,    KC_C,    KC_R,    KC_L,      KC_SLSH, \
  KC_ENT,    KC_A,    KC_O,       KC_E,       KC_U,       KC_I,            KC_D,            KC_H,    KC_T,    KC_N,    KC_S,      KC_ENT, \
  KC_LSFT,   KC_S,    KC_N,       KC_T,       KC_H,       KC_D,            KC_B,            KC_M,    KC_W,    KC_V,    KC_Z,      KC_RSFT , \
  KC_LCTL,   ADJUST,  DVORAK_OHL, DVORAK_OHR, KC_BSPC,    LT(6, KC_SPC),   LT(6, KC_SPC),   KC_BSPC,   KC_RALT, KC_RGUI, KC_RCTL,   ADJUST \
),

/* Dvorak one handed "mirrored" layer
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   ;  |   q  |   j  |   k  |   x  |   x  |   k  |   j  |   q  |   ;  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   z  |   v  |   w  |   m  |   b  |   d  |   h  |   t  |   n  |   s  |   /  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | space|   A  |   O  |   E  |   U  |   I  |   i  |   u  |   e  |   o  |   a  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   s  |   n  |   t  |   h  |   d  |   B  |   M  |   W  |   V  |   Z  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS |      | Win  | Alt  |Lower |Space |bkspc |Raise | Alt  |  Win |      |ADJUST|
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK_OHM] = KEYMAP( \
  _______,   KC_SCLN, KC_Q,    KC_J,    KC_K,      KC_X,      KC_6,     KC_7,    KC_8,    KC_9,    KC_0,      KC_EQL, \
  _______,   KC_Z,    KC_V,    KC_W,    KC_M,      KC_B,      KC_F,     KC_G,    KC_C,    KC_R,    KC_L,      KC_SLSH, \
  KC_SPC,    KC_A,    KC_O,    KC_E,    KC_U,      KC_I,      KC_D,     KC_H,    KC_T,    KC_N,    KC_S,      KC_ENT, \
  _______,   KC_S,    KC_N,    KC_T,    KC_H,      KC_D,      KC_B,     KC_M,    KC_W,    KC_V,    KC_Z,      KC_RSFT , \
  _______,   _______, _______, _______, _______,   _______,   _______,  _______,   KC_RALT, KC_RGUI, KC_RCTL,   ADJUST \
),

/* Dvorak one handed raise, numbers and some symbols i guess
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   x  |   k  |   j  |   q  |   ;  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   6  |   7  |   8  |   9  |   0  |   d  |   h  |   t  |   n  |   s  |   /  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   [  |   ]  |   +  |   -  |   /  |   i  |   u  |   e  |   o  |   a  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |   t  |   h  |   \  |   B  |   M  |   W  |   V  |   Z  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS |      | Win  | Alt  |Lower |Space |bkspc |Raise | Alt  |  Win |      |ADJUST|
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK_OHR] = KEYMAP( \
  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,      KC_5,      KC_6,     KC_7,    KC_8,    KC_9,    KC_0,      KC_EQL, \
  KC_TAB,    KC_6,    KC_7,    KC_8,    KC_9,      KC_0,      KC_F,     KC_G,    KC_C,    KC_R,    KC_L,      KC_SLSH, \
  KC_LCTL,   KC_LBRC, KC_RBRC, KC_EQL,  KC_MINS,   KC_SLSH,   KC_D,     KC_H,    KC_T,    KC_N,    KC_S,      KC_ENT, \
  KC_LSFT,   KC_S,    KC_N,    KC_T,    KC_H,      KC_BSLS,      KC_B,     KC_M,    KC_W,    KC_V,    KC_Z,      KC_RSFT , \
  _______,   _______, _______, _______, _______,   _______,   _______,  _______,   KC_RALT, KC_RGUI, KC_RCTL,   ADJUST \
),

/* Dvorak one handed lower, idk shortcuts or something
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   ;  |   q  |   j  |   k  |   x  |   x  |   k  |   j  |   q  |   ;  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   z  |   v  |   w  |   m  |   b  |   d  |   h  |   t  |   n  |   s  |   /  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   O  |   E  |   U  |   I  |   i  |   u  |   e  |   o  |   a  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   s  |   n  |   t  |   h  |   d  |   B  |   M  |   W  |   V  |   Z  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS |      | Win  | Alt  |Lower |Space |bkspc |Raise | Alt  |  Win |      |ADJUST|
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK_OHL] = KEYMAP( \
  KC_GRV,    KC_SCLN, KC_2,    KC_J,    KC_K,      KC_X,      KC_6,     KC_7,    KC_8,    KC_9,    KC_0,      KC_EQL, \
  KC_TAB,    KC_Z,    KC_V,    KC_W,    KC_M,      KC_B,      KC_F,     KC_G,    KC_C,    KC_R,    KC_L,      KC_SLSH, \
  KC_LCTL,   KC_A,    KC_O,    KC_E,    KC_U,      KC_I,      KC_D,     KC_H,    KC_T,    KC_N,    KC_S,      KC_ENT, \
  KC_LSFT,   KC_S,    KC_N,    KC_T,    KC_H,      KC_D,      KC_B,     KC_M,    KC_W,    KC_V,    KC_Z,      KC_RSFT , \
  _______,   _______, _______, _______, _______,   _______,   _______,  _______,   KC_RALT, KC_RGUI, KC_RCTL,   ADJUST \
),


[_PLOVER] = KEYMAP( \
  STN_N1,   STN_N2,     STN_N3,     STN_N4,     STN_N5,  STN_N6,    STN_N7,  STN_N8,    STN_N9,    STN_NA,    STN_NB,    STN_NC, \
  STN_FN,   STN_S1,     STN_TL,     STN_PL,     STN_HL,  STN_ST1,   STN_ST3, STN_FR,    STN_PR,    STN_LR,    STN_TR,    STN_DR, \
  XXXXXXX,  STN_S2,     STN_KL,     STN_WL,     STN_RL,  STN_ST2,   STN_ST4, STN_RR,   STN_BR,     STN_GR,   STN_SR,    STN_ZR, \
  XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, LOWER,     RAISE,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
  ADJUST,  XXXXXXX,    XXXXXXX,    XXXXXXX,    STN_A,   STN_O,         STN_E,    STN_U, XXXXXXX,   STN_PWR,  STN_RE1,  STN_RE2 \
), 

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|RGB Tg|RGB Md|Hue Up|Hue Dn|Sat Up|Sat Dn|Val Up|Val Dn|      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  KEYMAP( \
  RGB_TOG,   RGB_MOD,   RGB_M_P,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______, \
  _______,   DVORAK,    DVORAK_OH, FUSION, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, PLOVER, EXT_PLV, _______,   _______,  _______, _______, _______,  _______, _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

int defRGB[3] = {0x41, 0x9b, 0x9b};
int curRGB[3] = {0x41, 0x9b, 0x9b};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        
        layer_on(_DEFAULT);
        
        rgblight_setrgb(defRGB[0], defRGB[1], defRGB[2]);
        curRGB[0] = defRGB[0];
        curRGB[1] = defRGB[1];
        curRGB[2] = defRGB[2];
      }
      else
      {
        layer_off(_DEFAULT);
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
    case FUSION:
      if (record->event.pressed) {
        // persistent_default_layer_set(1UL<<_DVORAK);
        layer_off(_ADJUST);

        default_layer_set(1UL<<_FUSION);
        rgblight_setrgb(0x93, 0x70, 0xDB);
        curRGB[0] = 0x93;
        curRGB[1] = 0x70;
        curRGB[2] = 0xDB;
      }
      return false;
      break;
    case DVORAK_OH:
      if (record->event.pressed)
      {
        layer_off(_ADJUST);

        default_layer_set(1UL<<_DVORAK_OH);
        rgblight_setrgb(0x00,0xff,0x00);
        curRGB[0] = 0x00;
        curRGB[1] = 0xff;
        curRGB[2] = 0x00;
      }
      return false;
      break;

    case DVORAK_OHR:
      if (record->event.pressed)
      {
        layer_on(_DVORAK_OHR);
        // update_tri_layer(_DVORAK_OHR, _DVORAK_OHL, _ADJUST);
      }
      else
      {
        layer_off(_DVORAK_OHR);
        // update_tri_layer(_DVORAK_OHR, _DVORAK_OHL, _ADJUST);
      }
      return false;
      break;
    case DVORAK_OHL:
      if (record->event.pressed)
      {
        layer_on(_DVORAK_OHL);
        // update_tri_layer(_DVORAK_OHR, _DVORAK_OHL, _ADJUST);
      }
      else
      {
        layer_off(_DVORAK_OHL);
        // update_tri_layer(_DVORAK_OHR, _DVORAK_OHL, _ADJUST);
      }
      return false;
      break;

    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        // rgblight_setrgb(0x1e, 0x48, 0x48);
    	update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        // rgblight_setrgb(curRGB[0], curRGB[1], curRGB[2]);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        
        // rgblight_setrgb(0x81, 0xca, 0xca);
        // update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        // rgblight_setrgb(curRGB[0], curRGB[1], curRGB[2]);
        // update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        rgblight_setrgb(0xff, 0x00, 0x00);
        layer_on(_ADJUST);
      } else {
        rgblight_setrgb(curRGB[0], curRGB[1], curRGB[2]);
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void)
{
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
    rgblight_mode(1);
    rgblight_setrgb(0x55, 0x1A, 0x8B);
    
}