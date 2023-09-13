#include QMK_KEYBOARD_H
#include "keymap_german.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define RAISE OSL(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x6(
        KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_PGUP,
        KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         DE_Z  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_PGDN,
        KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
        KC_LCTL, DE_Y  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,DE_SLSH,
                         KC_UP,KC_DOWN,                                                       KC_LEFT, KC_RIGHT,
                                         KC_SPC,RAISE,                           KC_ENT, KC_BSPC,
                                         KC_INS,KC_LWIN,                         KC_NO,  KC_RALT,
                                         KC_DEL, KC_LALT,                        KC_LGUI, KC_RALT
    ),
    [_RAISE] = LAYOUT_5x6(
          DE_CIRC , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                       KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
          DE_AT,DE_EXLM,DE_QUES,DE_LCBR,DE_RCBR,DE_PIPE,                         DE_ASTR,DE_PERC,DE_QUOT,DE_SS,DE_UDIA,KC_F12,
          _______,DE_LABK,DE_RABK,DE_LPRN,DE_RPRN,DE_EQL,                        DE_PLUS,DE_DLR,DE_AT,DE_ODIA,DE_ADIA,KC_NO,
          _______,DE_SLSH,DE_BSLS,DE_LBRC,DE_RBRC,DE_HASH,                       DE_AMPR,DE_EURO,DE_GRV,DE_ACUT,DE_TILD,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______
    )
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("WPM: "), false);
    oled_write_P(get_u8_str(get_current_wpm(), '0'), false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
    return false;
}
#endif
