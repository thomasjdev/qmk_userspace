#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

#ifdef CHORDAL_HOLD
// Handedness for Chordal Hold (https://github.com/qmk/qmk_firmware/pull/24560)
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
  LAYOUT_voyager(
  '*', '*', '*', '*', '*', '*'    , '*', '*', '*', '*', '*', '*',
  '*', 'L', 'L', 'L', 'L', 'L'    , 'R', 'R', 'R', 'R', 'R', '*',
  '*', 'L', 'L', 'L', 'L', 'L'    , 'R', 'R', 'R', 'R', 'R', '*',
  '*', 'L', 'L', 'L', 'L', 'L'    , 'R', 'R', 'R', 'R', 'R', '*',
                      '*', '*'    ,'*', '*'
);
#endif  // CHORDAL_HOLD

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_74_255_255,
  HSV_169_255_255,
  UPDIR,
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
#define MEH_TAB MEH_T(KC_TAB)

#define NAV LT(1,KC_SPACE)
#define SYM LT(2,KC_BSPC)
#define FN  LT(3,KC_ENTER)
#define NUM LT(4,KC_DELETE)
#define MEDIA LT(5,KC_M)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    MEH_TAB,  KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
    HYPR_ESC, HOME_A,           HOME_S,          HOME_D,           HOME_F,           KC_G,                                           KC_H,           HOME_J,           HOME_K,           HOME_L,           HOME_SCLN,        KC_QUOTE,
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           MEDIA,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RIGHT_SHIFT,
                                                    SYM,  NUM,                                FN, NAV
  ),
  [1] = LAYOUT_voyager(
    _______, _______, _______, LGUI(LSFT(KC_3)),LGUI(LSFT(KC_4)),_______,                                 _______, _______, _______, _______, _______, _______,
    _______, _______, LSFT(LCTL(KC_TAB)),LCTL(KC_TAB),   _______, _______,                                 KC_PAGE_UP,      KC_HOME,         KC_END, _______, _______, _______,
    _______, KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    KC_LEFT_SHIFT,  _______,                                 KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       _______, _______,
    _______, LGUI(LSFT(KC_SPACE)),LGUI(LCTL(KC_EQUAL)),LCTL(KC_SPACE), LGUI(KC_SPACE), _______,                                 KC_PGDN, KC_BSPC,   KC_DELETE,  _______, _______, _______,
                                                   _______, _______,                                 _______, _______
  ),
  [2] = LAYOUT_voyager(
    _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______,
    _______, KC_QUOTE,       KC_LABK,        KC_RABK,        KC_DQUO,        KC_DOT,                                         KC_AMPR,        KC_UNDS,        KC_LBRC,        KC_RBRC,        KC_PERC,        _______,
    _______, KC_EXLM,        KC_MINUS,       KC_PLUS,        KC_EQUAL,       KC_HASH,                                        KC_PIPE,        KC_COLN,        KC_LPRN,        KC_RPRN,        KC_QUES,        _______,
    _______, KC_CIRC,        KC_SLASH,       KC_ASTR,        KC_BSLS,        UPDIR,                                     KC_TILD,        KC_DLR,         KC_LCBR,        KC_RCBR,        KC_AT,          _______,
                                                    _______, _______,                                 _______, _______
  ),
  [3] = LAYOUT_voyager(
    _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, QK_BOOT,
    _______, KC_F12,         KC_F9,          KC_F8,          KC_F7,          _______,                                 _______, _______, _______, _______, _______, _______,
    _______, KC_F10,         KC_F3,          KC_F2,          KC_F1,          _______,                                 _______, KC_LEFT_SHIFT,  KC_LEFT_GUI,    KC_LEFT_ALT,    KC_LEFT_CTRL,   _______,
    _______, KC_F11,         KC_F6,          KC_F5,          KC_F4,          _______,                                 _______, _______, _______, _______, _______, TO(5),
                                                    _______, _______,                                 _______, _______
  ),
  [4] = LAYOUT_voyager(
    _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                                 KC_SLASH,       KC_7,           KC_8,           KC_9,           KC_ASTR,        _______,
    _______, KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    KC_LEFT_SHIFT,  _______,                                 KC_MINUS,       KC_1,           KC_2,           KC_3,           KC_PLUS,        KC_EQUAL,
    _______, _______, _______, _______, _______, _______,                                 KC_DOT,         KC_4,           KC_5,           KC_6,           KC_PERC,        _______,
                                                    _______, _______,                                 _______, KC_0
  ),
  [5] = LAYOUT_voyager(
    RGB_TOG,        TOGGLE_LAYER_COLOR,RGB_MODE_FORWARD,RGB_SLD,        RGB_VAD,        RGB_VAI,                                        _______, _______, QK_DYNAMIC_TAPPING_TERM_DOWN,QK_DYNAMIC_TAPPING_TERM_UP,QK_DYNAMIC_TAPPING_TERM_PRINT,_______,
    _______, _______, KC_MS_WH_DOWN,  KC_MS_UP,       KC_MS_WH_UP,    _______,                                 _______, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  _______, _______,
    _______, _______, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    _______,                                 _______, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,_______,
    _______, _______, _______, HSV_0_255_255,  HSV_74_255_255, HSV_169_255_255,                                _______, _______, _______, _______, _______, TO(0),
                                                    KC_MS_BTN1,     _______,                                 _______, _______
  ),
};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {74,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {131,255,255}, {41,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {41,255,255}, {188,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {41,255,255}, {188,255,255}, {41,255,255} },

    [1] = { {74,255,255}, {74,255,255}, {74,255,255}, {131,255,255}, {131,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {40,255,255}, {40,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {74,255,255}, {74,255,255}, {40,255,255}, {30,255,255}, {169,255,255}, {169,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {131,255,255}, {41,255,255}, {41,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {74,255,255}, {74,255,255}, {131,255,255}, {0,255,255}, {0,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255} },

    [2] = { {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {40,255,255}, {0,255,255}, {0,255,255}, {40,255,255}, {40,255,255}, {152,255,255}, {0,255,255}, {74,255,255}, {74,255,255}, {0,255,255}, {40,255,255}, {152,255,255}, {40,255,255}, {74,255,255}, {74,255,255}, {40,255,255}, {40,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {74,255,255}, {40,255,255}, {30,255,255}, {30,255,255}, {40,255,255}, {152,255,255}, {74,255,255}, {40,255,255}, {30,255,255}, {30,255,255}, {40,255,255}, {152,255,255}, {74,255,255}, {40,255,255}, {30,255,255}, {30,255,255}, {40,255,255}, {152,255,255}, {131,255,255}, {131,255,255} },

    [3] = { {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,245,245}, {131,255,255}, {131,255,255}, {131,255,255}, {188,255,255}, {188,255,255}, {131,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {188,255,255}, {188,255,255}, {0,245,245}, {131,255,255}, {131,255,255}, {131,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255} },

    [4] = { {156,235,255}, {156,235,255}, {156,235,255}, {156,235,255}, {156,235,255}, {156,235,255}, {156,235,255}, {156,235,255}, {156,235,255}, {156,235,255}, {156,235,255}, {156,235,255}, {156,235,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {156,235,255}, {156,235,255}, {156,235,255}, {156,235,255}, {156,235,255}, {156,235,255}, {156,235,255}, {156,235,255}, {156,235,255}, {156,235,255}, {156,235,255}, {156,235,255}, {156,235,255}, {156,235,255}, {156,235,255}, {40,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {40,255,255}, {156,235,255}, {30,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {30,255,255}, {30,255,255}, {40,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {40,255,255}, {156,235,255}, {156,235,255}, {131,255,255} },

    [5] = { {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {131,255,255}, {74,255,255}, {131,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {131,255,255}, {131,255,255}, {188,255,255}, {188,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {188,255,255}, {188,255,255}, {152,255,255}, {74,255,255}, {0,245,245}, {188,255,255}, {188,255,255}, {188,255,255}, {169,255,255}, {169,255,255}, {0,245,245}, {74,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {74,255,255}, {188,255,255}, {188,255,255} },

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
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
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
    case UPDIR:
    if (record->event.pressed) {
      SEND_STRING_DELAY("../", TAP_CODE_DELAY);
    }
    break;

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_74_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(74,255,255);
      }
      return false;
    case HSV_169_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(169,255,255);
      }
      return false;
  }
  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case NAV:
    case SYM:
    case FN:
    case NUM:
        return TAPPING_TERM - 45;
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
    case NAV:
    case SYM:
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
