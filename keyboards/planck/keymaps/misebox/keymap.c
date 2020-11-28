#include QMK_KEYBOARD_H

#include "muse.h"

enum planck_layers { _QWERTY, _FUNCFULL, _MOVE, _SYMBOL, _TENKEY, _SPECIAL, _KEYBOARD };

enum custom_keycodes {  // Make sure have the awesome keycode ready
    LT_TENKEY_SFT_TAB = SAFE_RANGE,
    LT_SPECIAL_TAB,
    ESC_EISU,
};

// result of process_record_user
#define PROCESS_OVERRIDE_BEHAVIOR (false)
#define PROCESS_USUAL_BEHAVIOR (true)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_planck_grid(
        // Qwerty
        //  ,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
               KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_MINS,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,RSFT_T(KC_SCLN), KC_QUOT,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
        //  |L4/SFTAB|  LGUI  |  LALT  |CTL/Eisu|L1 / TAB|L3 / SPC|GUI_T/BS|L2/ENTER|CTL/Kana|  RALT  |  RGUI  |L5 / TAB|
        LT_TENKEY_SFT_TAB, KC_LGUI, KC_LALT, LCTL_T(KC_LANG2), LT(1, KC_TAB), LSFT_T(KC_SPC), LT(3, KC_BSPC), LT(2, KC_ENT), RCTL_T(KC_LANG1), KC_RALT, KC_RGUI, LT_SPECIAL_TAB
        //  `--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),
    [_FUNCFULL] = LAYOUT_planck_grid(
        // Functions and Full key
        //  ,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
              KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
               KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_EQL,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
                KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        //  `--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),
    [_MOVE] = LAYOUT_planck_grid(
        // Cursor and page transition
        //  ,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
               KC_ESC,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,KC_PGUP,RSFT(KC_TAB),KC_TAB, KC_PGDN, KC_RCTL, KC_BSPC,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,ESC_EISU, KC_RALT,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_DEL, KC_HOME,  KC_END, KC_BSPC, KC_RSFT,   KC_NO,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        //  `--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),
    [_SYMBOL] = LAYOUT_planck_grid(
        // Structural symbols
        //  ,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
               KC_ESC,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_GRV, KC_QUOT, KC_DQUO, KC_LPRN, KC_RPRN, KC_BSPC,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC,   KC_NO,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LT,   KC_GT,   KC_NO,   KC_NO,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        //  `--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),
    [_TENKEY] = LAYOUT_planck_grid(
        // Ten key
        //  ,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
              KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_PSLS,   KC_P7,   KC_P8,   KC_P9, KC_PAST, KC_BSPC,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_PMNS,   KC_P4,   KC_P5,   KC_P6, KC_PPLS,   KC_NO,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NLCK,   KC_P1,   KC_P2,   KC_P3, KC_PEQL,   KC_NO,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_P0, KC_COMM, KC_PDOT, KC_PENT,   MO(6)
        //  `--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),
    [_SPECIAL] = LAYOUT_planck_grid(
        // Special controls
        //  ,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
                KC_NO, RGB_SAD, RGB_HUD, RGB_HUI, RGB_SAI, RGB_TOG,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
             RGB_RMOD, RGB_SPD, RGB_VAD, RGB_VAI, RGB_SPI, RGB_MOD,   KC_NO,   KC_NO, KC_BRID, KC_BRIU,   KC_NO,   KC_NO,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              KC_TRNS, BL_STEP,  BL_OFF,  BL_DEC,  BL_INC,   BL_ON,   KC_NO, KC_MUTE, KC_VOLD, KC_VOLU,   KC_NO,   KC_NO,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
                MO(6),   KC_NO,   KC_NO, BL_TOGG, BL_BRTG,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS
        //  `--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),
    [_KEYBOARD] = LAYOUT_planck_grid(
        // Keyboard reset and music mode
        //  ,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
                RESET,   DEBUG,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              KC_CAPS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NLCK,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              KC_TRNS,   KC_NO, LCG_SWP,  MU_MOD,  MUV_DE, MU_OFF,    MU_ON,  MUV_IN,  MU_MOD, LCG_NRM,   KC_NO, KC_TRNS
        //  `--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t mem_keycode;
    uint16_t        prev_keycode = mem_keycode;
    bool            is_tapped    = ((!record->event.pressed) && (keycode == prev_keycode));
    mem_keycode                  = keycode;

    bool result = PROCESS_USUAL_BEHAVIOR;
    switch (keycode) {
        case LT_TENKEY_SFT_TAB: {
            if (record->event.pressed) {
                layer_on(_TENKEY);
            } else {
                layer_off(_TENKEY);
                if (is_tapped) {
                    register_code(KC_LSFT);
                    register_code(KC_TAB);
                    unregister_code(KC_TAB);
                    unregister_code(KC_LSFT);
                }
            }
            result = PROCESS_OVERRIDE_BEHAVIOR;
        } break;
        case LT_SPECIAL_TAB: {
            if (record->event.pressed) {
                layer_on(_SPECIAL);
            } else {
                layer_off(_SPECIAL);
                if (is_tapped) {
                    register_code(KC_TAB);
                    unregister_code(KC_TAB);
                }
            }
            result = PROCESS_OVERRIDE_BEHAVIOR;
        } break;
        case ESC_EISU: {
            if (record->event.pressed) {
                register_code(KC_LANG2);
                unregister_code(KC_LANG2);
            }
        } break;
        default: {
        } break;
            return result;
    }

    return PROCESS_USUAL_BEHAVIOR;
}
