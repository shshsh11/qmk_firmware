// #define ENCODERS_A_REVERSE // corresponds to right
// #define ENCODERS_B_REVERSE // corresponds to middle
// #define ENCODERS_C_REVERSE
#define ENCODER_RESOLUTIONS {4, 4, 2}


#define FORCE_NKRO

#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT
#define COMBO_TERM 35
#define COMBO_ONLY_FROM_LAYER 0
#define EXTRA_SHORT_COMBOS
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define MK_3_SPEED

#undef FP_POINTING_DEFAULT_DPI 
#define FP_POINTING_DEFAULT_DPI 12
#define FP_POINTING_SNIPING_DPI 2

#define FP_ENC_0_LAYER_SCROLL_WHEEL 0
#define FP_ENC_0_LAYER_VOLUME 16 // need to set this to whatever layer this to get rid of conflict
#define FP_ENC_1_LAYER_VOLUME 0
#define FP_ENC_1_LAYER_SUPER_TAB 16 // need to set this to whatever layer to get rid of conflict
#define FP_ENC_2_LAYER_SCROLL_WHEEL 0