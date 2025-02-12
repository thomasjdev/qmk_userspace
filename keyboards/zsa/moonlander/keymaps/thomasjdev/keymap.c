#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RCTL_T(KC_SCLN)

// Shortcuts for other mod keys
#define HYPR_ESC ALL_T(KC_ESCAPE)
#define HYPR_QUOT ALL_T(KC_QUOT)

#ifdef CHORDAL_HOLD
// Handedness for Chordal Hold (https://github.com/qmk/qmk_firmware/pull/24560)
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
  LAYOUT(
  '*', '*', '*', '*', '*', '*', '*'    ,'*', '*', '*', '*', '*', '*', '*',
  '*', 'L', 'L', 'L', 'L', 'L', '*'    ,'*', 'R', 'R', 'R', 'R', 'R', '*',
  '*', 'L', 'L', 'L', 'L', 'L', '*'    ,'*', 'R', 'R', 'R', 'R', 'R', '*',
  '*', 'L', 'L', 'L', 'L', 'L'              ,'R', 'R', 'R', 'R', 'R', '*',
  '*', 'L', 'L', 'L', 'L',                        'R', 'R', 'R', 'R', '*',
                               '*',    '*' ,
                       '*','*','*',    '*', '*', '*'
);
#endif  // CHORDAL_HOLD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_EQUAL,                                       KC_EQUAL,       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_LBRC,                                        KC_RBRC,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
    HYPR_ESC, HOME_A,HOME_S,HOME_D,HOME_F,KC_G,           KC_LPRN,                                                                        KC_RPRN,        KC_H,           HOME_J,HOME_K,HOME_L,HOME_SCLN, HYPR_QUOT,
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RIGHT_SHIFT,
    MO(3),          LGUI(LSFT(KC_4)),KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    LGUI(KC_SPACE),                                                                                                 LCTL(KC_SPACE), MO(1),          KC_LEFT_GUI,    KC_LEFT_ALT,    CW_TOGG,   MO(3),
    KC_BSPC,        KC_DELETE,      MO(2),                          MO(2),          KC_ENTER,       KC_SPACE
  ),
  [1] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, LGUI(KC_LBRC),  LGUI(KC_RBRC),  _______, _______, KC_PAGE_UP,                                     KC_HOME,        _______, _______, LGUI(LSFT(KC_LBRC)),LGUI(LSFT(KC_RBRC)),_______, _______,
    _______, KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    KC_LEFT_SHIFT,  _______, KC_PGDN,                                                                        KC_END,         KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       _______, _______,
    _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______, _______,
    LGUI(LCTL(KC_EQUAL)),LGUI(LSFT(KC_SPACE)),_______,                 _______, _______, _______
  ),
  [2] = LAYOUT_moonlander(
    _______, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          _______,                                 _______, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    _______, KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        _______,                                 _______, KC_UP,          KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_F12,
    _______, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,       _______,                                                                 _______, KC_DOWN,        KC_4,           KC_5,           KC_6,           KC_KP_PLUS,     _______,
    KC_COMMA,       KC_PERC,        KC_CIRC,        KC_LBRC,        KC_RBRC,        KC_TILD,                                        KC_AMPR,        KC_1,           KC_2,           KC_3,           KC_BSLS,        _______,
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, KC_DOT,         KC_0,           KC_EQUAL,       _______,
    _______, _______, _______,                 _______, _______, _______
  ),
  [3] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, QK_BOOT,
    _______, _______, KC_MS_UP,       _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    _______, _______, _______,                                                                 _______, _______, _______, _______, _______, _______, KC_MEDIA_PLAY_PAUSE,
    _______, _______, _______, KC_MS_BTN1,     KC_MS_BTN2,     _______,                                 _______, _______, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,_______, _______,
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  _______, _______,
    _______, _______, _______,                 _______, _______, _______
  ),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {131,255,255}, {41,255,255}, {219,255,255}, {41,255,255}, {188,255,255}, {131,255,255}, {131,255,255}, {0,195,239}, {131,255,255}, {32,122,245}, {131,255,255}, {131,255,255}, {0,195,239}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,195,239}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,195,239}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {197,211,233}, {131,255,255}, {0,195,239}, {0,195,239}, {219,255,255}, {131,255,255}, {219,255,255}, {74,255,255}, {131,255,255}, {131,255,255}, {41,255,255}, {197,211,233}, {131,255,255}, {131,255,255}, {0,195,239}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,195,239}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,195,239}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,195,239}, {131,255,255}, {197,211,233}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {197,211,233}, {131,255,255}, {0,195,239}, {0,195,239}, {219,255,255}, {131,255,255}, {219,255,255} },

    [1] = { {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {117,212,232}, {234,255,255}, {219,255,255}, {234,255,255}, {169,120,255}, {117,212,232}, {234,255,255}, {234,255,255}, {234,255,255}, {169,120,255}, {117,212,232}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {117,212,232}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {0,245,245}, {0,245,245}, {117,212,232}, {117,212,232}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {41,255,255}, {146,224,255}, {234,255,255}, {234,255,255}, {234,255,255}, {41,255,255}, {146,224,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {146,224,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {146,224,255}, {234,255,255}, {234,255,255}, {0,245,245}, {0,245,245}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255} },

    [2] = { {252,255,232}, {252,255,232}, {252,255,232}, {214,157,233}, {252,255,232}, {74,255,255}, {214,157,233}, {214,157,233}, {214,157,233}, {252,255,232}, {74,255,255}, {214,157,233}, {214,157,233}, {214,157,233}, {0,245,245}, {74,255,255}, {152,255,255}, {197,214,239}, {152,255,255}, {252,255,232}, {74,255,255}, {152,255,255}, {197,214,239}, {152,255,255}, {252,255,232}, {74,255,255}, {252,255,232}, {252,255,232}, {252,255,232}, {252,255,232}, {252,255,232}, {252,255,232}, {252,255,232}, {252,255,232}, {252,255,232}, {252,255,232}, {74,255,255}, {74,255,255}, {252,255,232}, {252,255,232}, {252,255,232}, {74,255,255}, {214,157,233}, {214,157,233}, {214,157,233}, {214,157,233}, {74,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {74,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {214,157,233}, {74,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {252,255,232}, {74,255,255}, {252,255,232}, {252,255,232}, {214,157,233}, {252,255,232}, {252,255,232}, {252,255,232}, {252,255,232}, {252,255,232}, {252,255,232}, {252,255,232} },

    [3] = { {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {117,212,232}, {32,122,245}, {32,122,245}, {32,122,245}, {117,212,232}, {117,212,232}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {117,212,232}, {214,157,233}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {214,157,233}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {252,255,232}, {32,122,245}, {234,255,255}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {234,255,255}, {0,245,245}, {32,122,245}, {32,122,245}, {32,122,245}, {234,255,255}, {152,255,255}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {152,255,255}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245}, {32,122,245} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
  }
  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case HOME_F:
    case HOME_J:
    case HOME_K:
      return TAPPING_TERM + 60;
    default:
      return TAPPING_TERM;
  }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
  // If you quickly hold a tap-hold key after tapping it, the tap action is
  // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
  // lead to missed triggers in fast typing. Here, returning 0 means we
  // instead want to "force hold" and disable key repeating.
  switch (keycode) {
    case HOME_L:
      return QUICK_TAP_TERM;  // Enable key repeating.
    default:
      return 0;  // Otherwise, force hold and disable key repeating.
  }
}

#ifdef CHORDAL_HOLD
// Callback for Chordal Hold (https://github.com/qmk/qmk_firmware/pull/24560)
bool get_chordal_hold(
        uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
        uint16_t other_keycode, keyrecord_t* other_record) {
  switch (tap_hold_keycode) {
//    case NAV_SLS:
//      return true;

    case HOME_D:
      if (other_keycode == KC_TAB ||
          other_keycode == KC_BSPC ) { return true; }
      break;

    case HOME_K:
      if (other_keycode == KC_SPACE) { return true; }
  }
  return get_chordal_hold_default(tap_hold_record, other_record);
}
#endif  // CHORDAL_HOLD

#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
      add_weak_mods(MOD_BIT_LSHIFT);  // Apply shift to the next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_UNDS:
    case KC_COLN:
      return true;

    default:
      return false;  // Deactivate Caps Word.
  }
}
#endif  // CAPS_WORD_ENABLE
