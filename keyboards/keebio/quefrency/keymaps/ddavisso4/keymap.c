#include QMK_KEYBOARD_H

enum layer_names {
    BASE,
    NAV,
    FN1,
    FN2,
    FN3
};

enum custom_keycodes {
    MC_CMNT = SAFE_RANGE,
    MC_UNCMNT,
    MC_FRMT,
    MC_ADMIN,
    MC_TG_BKMK,
    MC_NAV_BKMK,
    MC_TEST,
    MC_RENAME
};

enum {
    TD_CTL_HOME,
    TD_CTL_END
};

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_CTL_HOME] = ACTION_TAP_DANCE_DOUBLE(S(KC_HOME), RCS(KC_HOME)),
    [TD_CTL_END] = ACTION_TAP_DANCE_DOUBLE(S(KC_END), RCS(KC_END)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_all(
        KC_NO, KC_NO,
   KC_GRV   ,    KC_1    ,   KC_2    ,    KC_3    ,    KC_4    ,    KC_5    ,    KC_6       ,       KC_7    ,    KC_8    ,    KC_9    ,    KC_0    ,   KC_MINS  ,   KC_EQL   ,   KC_BSPC  ,   KC_BSPC  ,
        KC_NO, KC_NO, KC_NO,
   KC_TAB   ,    KC_Q    ,   KC_W    ,    KC_E    ,    KC_R    ,    KC_T    ,    KC_Y       ,       KC_U    ,    KC_I    ,    KC_O    ,    KC_P    ,   KC_LBRC  ,   KC_RBRC  ,   KC_BSLS  ,
        KC_NO, KC_NO, KC_NO,
   KC_CAPS  ,    KC_A    ,   KC_S    ,    KC_D    ,    KC_F    ,    KC_G    ,    KC_H       ,       KC_J    ,    KC_K    ,    KC_L    ,   KC_SCLN  ,   KC_QUOT  ,  KC_ENTER  ,   KC_ENTER ,
        KC_NO, KC_NO, KC_NO,
  KC_LSFT   ,   KC_BSLS  ,   KC_Z    ,    KC_X    ,    KC_C    ,    KC_V    ,    KC_B       ,       KC_N    ,    KC_M    ,  KC_COMM   ,    KC_DOT  ,   KC_SLSH  ,  KC_RSFT   ,     MO(4)  ,
        KC_NO, KC_NO, KC_NO,
  KC_LCTL   ,  KC_LGUI   ,  KC_LALT  ,    TG(3)   ,    TT(2)   ,    TT(1)   ,   KC_SPC      ,      KC_SPC   ,   KC_RALT  ,  KC_RGUI   ,   KC_RCTL  ,  RCS(KC_M) ,   G(KC_L)  ,
        KC_NO),


	[NAV] = LAYOUT_all(
        KC_NO, KC_NO,
     KC_NO      , LT(0,C(KC_F4)) ,LT(0,A(KC_TAB)) ,LT(-1,C(KC_TAB)), LT(0,C(KC_T))  , G(C(KC_LEFT))  , G(C(KC_RIGHT))     ,      KC_PGUP   ,  LSA(KC_UP)   ,   KC_NO   ,    KC_NO    ,   KC_NO   ,   KC_NO   ,    KC_NO    ,   KC_NO   ,
        KC_NO, KC_NO, KC_NO,
   RCS(KC_L)    ,    C(KC_DEL)   ,     KC_DEL     ,      KC_UP     ,     KC_BSPC    ,   C(KC_BSPC)   ,   A(KC_UP)         ,      KC_PGDN   ,   S(KC_UP)    ,  C(KC_A)  ,   C(KC_W)   ,   KC_NO   ,   KC_NO   ,    KC_NO    ,
        KC_NO, KC_NO, KC_NO,
     KC_ESC     ,   C(KC_LEFT)   ,     KC_LEFT    ,      KC_DOWN   ,     KC_RGHT    ,   C(KC_RGHT)   ,   RCS(KC_LEFT)     ,    S(KC_LEFT)  ,  S(KC_DOWN)   , S(KC_RGHT),  RCS(KC_RGHT) ,   KC_NO   ,C(KC_ENTER),C(KC_ENTER),
        KC_NO, KC_NO, KC_NO,
    KC_ENTER    , LT(0, KC_HOME) ,     C(KC_Z)    ,      C(KC_X)   ,     C(KC_C)    ,   C(KC_V)      ,  LT(0, KC_END)     ,    A(KC_DOWN)  ,TD(TD_CTL_HOME),LSA(KC_DOWN),TD(TD_CTL_END),   KC_NO   ,   KC_NO   ,   KC_NO   ,
        KC_NO, KC_NO, KC_NO,
    KC_TRNS     ,     KC_TRNS    ,     KC_TRNS    ,KC_PRINT_SCREEN ,      KC_F5     ,   KC_TRNS      ,      KC_TRNS       ,      KC_TRNS   ,     KC_TRNS   ,   KC_TRNS  ,    KC_TRNS   ,  KC_TRNS  ,  KC_TRNS  ,
        KC_NO),


	[FN1] = LAYOUT_all(
        KC_NO, KC_NO,
    KC_NO    ,  MC_TG_BKMK  ,LT(0, MC_NAV_BKMK),   MEH(KC_H)   ,   MEH(KC_A)   ,   MEH(KC_D)   ,    KC_F9         ,         KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,
        KC_NO, KC_NO, KC_NO,
    KC_NO    ,  C(KC_F10)   ,      KC_F10      ,    KC_F11     ,  LT(0, KC_F5) , LT(0, MC_TEST)                   ,         KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,
        KC_NO, KC_NO, KC_NO,
    KC_NO    ,  S(KC_F2)    ,      C(KC_S)     ,   LCA(KC_P)   ,     C(KC_F)   ,     KC_F3                        ,      C(KC_1)    ,  MC_CMNT  , MC_UNCMNT ,  MC_FRMT  ,   KC_NO   ,   KC_NO   ,    KC_NO  ,   KC_NO   ,
        KC_NO, KC_NO, KC_NO,
 C(KC_MINS)  , RCS(KC_MINS) ,     C(KC_GRV)    ,  RCS(KC_GRV)  ,  LCA(KC_GRV)  ,   MC_RENAME   , RCS(KC_B)        ,     LSA(KC_D)   ,   KC_NO   , C(KC_COMM), C(KC_DOT) ,   KC_NO   ,   KC_NO   ,    KC_NO  ,
        KC_NO, KC_NO, KC_NO,
    KC_NO    ,     KC_NO    ,     KC_NO        ,     KC_NO     ,    KC_TRNS    ,     KC_NO     ,   KC_NO          ,        KC_NO    ,   KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,
        KC_NO),


	[FN2] = LAYOUT_all(
        KC_NO, KC_NO,
   KC_NO   ,   KC_MUTE   ,   KC_VOLD   ,   KC_VOLU   ,   KC_MPLY   ,   KC_MPRV   ,   KC_MNXT       ,       KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,
        KC_NO, KC_NO, KC_NO,
  MC_ADMIN ,  RCS(KC_I)  ,   C(KC_2)   ,   G(KC_1)   ,   G(KC_2)   ,   G(KC_3)   ,  LSA(KC_C)      ,       KC_1    ,   KC_2    ,   KC_3    ,   KC_NO   ,   KC_NO   ,    KC_NO  ,   KC_NO   ,
        KC_NO, KC_NO, KC_NO,
 RCS(KC_1) ,  RCS(KC_5)  ,   C(KC_Q)   ,   G(KC_4)   ,   G(KC_5)   ,   G(KC_6)   ,LT(0, C(KC_E))   ,       KC_4    ,   KC_5    ,   KC_6    ,   KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,
        KC_NO, KC_NO, KC_NO,
A(KC_LEFT) ,  A(KC_RGHT) ,  RCS(KC_R)  ,   C(KC_R)   ,   G(KC_7)   ,   G(KC_8)   , G(KC_9)         ,       C(KC_N) ,   KC_7    ,   KC_8    ,   KC_9    ,   KC_NO   ,   KC_NO   ,   KC_NO   ,
        KC_NO, KC_NO, KC_NO,
   KC_NO   ,    KC_NO    ,   KC_NO     ,   KC_TRNS   ,    KC_NO    ,    KC_NO                      ,        KC_NO  ,   KC_0    ,    KC_NO  ,   KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,
        KC_NO),


	[FN3] = LAYOUT_all(
        KC_NO, KC_NO,
   KC_NO   ,   KC_F1   ,   KC_F2   ,   KC_F3   ,   KC_F4   ,   KC_F5   ,   KC_F6        ,        KC_F7   ,          KC_F8                ,               KC_F9          ,          KC_F10            ,   KC_F11  ,  KC_F12  ,   KC_NO   ,   KC_NO   ,
        KC_NO, KC_NO, KC_NO,
   KC_NO   ,   KC_INS  ,  KC_PAUS  ,  KC_SCRL  ,   KC_NUM  ,   KC_NO                    ,        KC_NO   , QK_DYNAMIC_TAPPING_TERM_PRINT , QK_DYNAMIC_TAPPING_TERM_DOWN , QK_DYNAMIC_TAPPING_TERM_UP ,   KC_NO   ,  KC_NO   ,   KC_NO   ,   KC_NO   ,
        KC_NO, KC_NO, KC_NO,
   KC_NO   ,  BL_TOGG  ,  BL_DOWN  ,   BL_UP   ,   KC_NO   ,   KC_NO                    ,        KC_NO   ,          KC_NO                ,               KC_NO          ,          KC_NO             ,   KC_NO   ,  KC_NO   ,   KC_NO   ,    KC_NO   ,
        KC_NO, KC_NO, KC_NO,
   KC_NO   ,   KC_NO   ,  RGB_TOG  ,  RGB_VAD  ,  RGB_VAI  ,   KC_NO   , KC_NO          ,        KC_NO   ,          KC_NO                ,               KC_NO          ,          KC_NO             ,   KC_NO   ,  KC_NO   ,   KC_NO   ,
        KC_NO, KC_NO, KC_NO,
   KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,  KC_NO                     ,        KC_NO   ,          KC_NO                ,               KC_NO          ,          KC_NO             ,   KC_NO   , KC_TRNS  ,   KC_NO   ,
        KC_NO)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Send string macros
        case MC_CMNT:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL("kc"), 20);
                return false;
            }
            return true;
        case MC_UNCMNT:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL("ku"), 20);
                return false;
            }
            return true;
        case MC_FRMT:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL("kd"), 20);
                return false;
            }
            return true;
        case MC_ADMIN:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_ENTER) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_ENTER), 100);
                return false;
            }
            return true;
        case MC_RENAME:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL("rr"), 20);
                return false;
            }
            return true;
        case MC_TG_BKMK:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL("kk"), 20);
                return false;
            }
            return true;

        // Tap-Hold Hold Overrides
        case LT(0, KC_HOME):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_HOME));
                return false;
            }
            return true;
        case LT(0, KC_END):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_END));
                return false;
            }
            return true;
        case LT(0, C(KC_F4)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_F4)); // Tap
            } else if (record->event.pressed) {
                tap_code16(A(KC_F4)); // Hold
            }
            return false;
        case LT(0, A(KC_TAB)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(A(KC_TAB)); // Tap
            } else if (record->event.pressed) {
                tap_code16(G(KC_TAB)); // Hold
            }
            return false;
        case LT(-1, C(KC_TAB)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_TAB)); // Tap
            } else if (record->event.pressed) {
                tap_code16(RCS(KC_TAB)); // Hold
            }
            return false;
        case LT(0, C(KC_T)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_T)); // Tap
            } else if (record->event.pressed) {
                tap_code16(RCS(KC_T)); // Hold
            }
            return false;
        case LT(0, MC_NAV_BKMK):
            if (record->tap.count && record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL("kn"), 20); // Tap
            } else if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL("kp"), 20); // Hold
            }
            return false;
        case LT(0, KC_F5):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_F8);
                return false;
            }
            return true;
        case LT(0, MC_TEST):
            if (record->tap.count && record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL("r") "t", 20); // Tap
            } else if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL("rt"), 20); // Hold
            }
            return false;
        case LT(0, C(KC_E)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_E)); // Tap
            } else if (record->event.pressed) {
                tap_code16(C(KC_G)); // Hold
            }
            return false;
    }

    return true;
};
