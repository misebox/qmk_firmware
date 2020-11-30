#include QMK_KEYBOARD_H

#include "muse.h"

enum planck_layers { _QWERTY, _FULL, _MOVE, _SYMBOL, _TENFUNC, _SPECIAL, _KEYBOARD };

enum custom_keycodes {  // Make sure have the awesome keycode ready
    L4_STAB = SAFE_RANGE,
    L5_TAB,
    ESC_EISU,
};

// result of process_record_user
#define PROCESS_OVERRIDE_BEHAVIOR (false)
#define PROCESS_USUAL_BEHAVIOR (true)

// shortened expression for readability
#define L1_TAB  LT(1, KC_TAB)
#define L2_ENT  LT(2, KC_ENT)
#define L3_BSPC LT(3, KC_BSPC)
#define CT_EISU LCTL_T(KC_LANG2)
#define ST_SPC  LSFT_T(KC_SPC)

#define ST_SCLN LSFT_T(KC_SCLN)
#define S_TAB   LSFT(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_planck_grid(
        // Qwerty
        //  ,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
               KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_MINS,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, ST_SCLN, KC_QUOT,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              L4_STAB, KC_LGUI, KC_LALT, CT_EISU,  L1_TAB,  ST_SPC, L3_BSPC,  L2_ENT, KC_RCTL, KC_RALT, KC_RGUI,  L5_TAB
        //  `--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),
    [_FULL] = LAYOUT_planck_grid(
        // Full key
        //  ,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
              KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
               KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_EQL,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              _______, _______, _______, _______, _______, _______, _______, _______,KC_LANG1, _______, _______, _______
        //  `--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),
    [_MOVE] = LAYOUT_planck_grid(
        // Cursor and page transition
        //  ,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
               KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP,   S_TAB,  KC_TAB, KC_PGDN, KC_RCTL, KC_BSPC,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,ESC_EISU, KC_RALT,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL, KC_HOME,  KC_END, KC_BSPC, KC_RSFT, XXXXXXX,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        //  `--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),
    [_SYMBOL] = LAYOUT_planck_grid(
        // Structural symbols
        //  ,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
              KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX, KC_MINS,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, KC_COLN, _______,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DLR, KC_QUOT, KC_DQUO,  KC_GRV, _______, _______,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        //  `--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),
    [_TENFUNC] = LAYOUT_planck_grid(
        // Ten key and functions
        //  ,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
              _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_PSLS,   KC_P7,   KC_P8,   KC_P9, KC_PAST, KC_BSPC,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_PMNS,   KC_P4,   KC_P5,   KC_P6, KC_PPLS, XXXXXXX,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              _______,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15, KC_NLCK,   KC_P1,   KC_P2,   KC_P3, KC_PEQL, XXXXXXX,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              _______, _______, _______, _______, _______, _______, _______,   KC_P0, KC_COMM, KC_PDOT, KC_PENT,   MO(6)
        //  `--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),
    [_SPECIAL] = LAYOUT_planck_grid(
        // Special controls
        //  ,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
              XXXXXXX, RGB_SAD, RGB_HUD, RGB_HUI, RGB_SAI, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
             RGB_RMOD, RGB_SPD, RGB_VAD, RGB_VAI, RGB_SPI, RGB_MOD, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              _______, BL_STEP,  BL_OFF,  BL_DEC,  BL_INC,   BL_ON, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
                MO(6), XXXXXXX, XXXXXXX, BL_TOGG, BL_BRTG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______
        //  `--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),
    [_KEYBOARD] = LAYOUT_planck_grid(
        // Keyboard reset and music mode
        //  ,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
                RESET,   DEBUG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NLCK,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //  |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
              _______, XXXXXXX, LCG_SWP,  MU_MOD,  MUV_DE, MU_OFF,    MU_ON,  MUV_IN,  MU_MOD, LCG_NRM, XXXXXXX, _______
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
        case L4_STAB: {
            if (record->event.pressed) {
                layer_on(_TENFUNC);
            } else {
                layer_off(_TENFUNC);
                if (is_tapped) {
                    register_code(KC_LSFT);
                    register_code(KC_TAB);
                    unregister_code(KC_TAB);
                    unregister_code(KC_LSFT);
                }
            }
            result = PROCESS_OVERRIDE_BEHAVIOR;
        } break;
        case L5_TAB: {
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
                register_code(KC_ESC);
                unregister_code(KC_ESC);
            }
            result = PROCESS_OVERRIDE_BEHAVIOR;
        } break;
        default: {
        } break;
            return result;
    }

    return PROCESS_USUAL_BEHAVIOR;
}
