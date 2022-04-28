#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┐     ┌───┬───┬───┬───┬───┬───┐
     * │esc│ 1 │ 2 │ 3 │ 4 │ 5 │     │ 6 │ 7 │ 8 │ 9 │ 0 │del│
     * ├───┼───┼───┼───┼───┼───┤     ├───┼───┼───┼───┼───┼───┤
     * │tab│ q │ w │ e │ r │ t │     │ y │ u │ i │ o │ p │bsp│
     * ├───┼───┼───┼───┼───┼───┤     ├───┼───┼───┼───┼───┼───┤
     * │f9 │ a │ s │ d │ f │ g │     │ h │ j │ k │ l │ ' │ent│
     * ├───┼───┼───┼───┼───┼───┤     ├───┼───┼───┼───┼───┼───┤
     * │sft│ z │ x │ c │ v │ b │     │ n │ m │ , │ . │up │sft│
     * ├───┼───┼───┼───┼───┴───┤     ├───┴───┼───┼───┼───┼───┤
     * │ctl│win│alt│fn │ space │     │ space │fn │lft│dn │rt │
     * └───┴───┴───┴───┴───────┘     └───────┴───┴───┴───┴───┘
     */
    [0] = LAYOUT_split58_6x5(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,   KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_F9,  KC_A, KC_S, KC_D, KC_F, KC_G,   KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_ENT,
        KC_LSFT,KC_Z, KC_X, KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, MO(1), KC_SPC,   KC_SPC, MO(1), KC_LEFT, KC_DOWN, KC_RGHT
    ), 

    [1] = LAYOUT_split58_6x5(
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,         KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS,
        KC_TRNS, KC_F11, KC_F12, KC_GRV, MO(2), RGB_TOG,    KC_NO, MO(2), KC_MINS, KC_EQL, KC_BSLS, KC_TRNS,
      KC_TRNS, KC_NO, KC_VOLD, KC_VOLU, RGB_MOD, RGB_VAI,   KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_SCLN, KC_TRNS,
    KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, RGB_HUI, RGB_VAD,   KC_NO, KC_QUES, KC_COLN, KC_SLSH, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [2] = LAYOUT_split58_6x5(
        RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET, 
     NK_TOGG, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO,   KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, NK_TOGG,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_TRNS,    KC_NO,          KC_NO,     KC_TRNS, KC_NO, KC_NO, KC_NO
    )
};
