/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#undef RGB_MATRIX_TIMEOUT
#define RGB_MATRIX_TIMEOUT 600000

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 25

#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 5

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 125

#define SERIAL_NUMBER "MqNV4/LvvJ7M"
#define LAYER_STATE_8BIT

#define RGB_MATRIX_STARTUP_SPD 60

#define TAPPING_TERM 225
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM_PER_KEY

// Unfortunately, some applications drop or misorder fast key events. This is a
// partial fix to slow down the rate at which macros are sent.
#define TAP_CODE_DELAY 5

// Enable Chordal Hold (https://github.com/qmk/qmk_firmware/pull/24560)
#define CHORDAL_HOLD
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
