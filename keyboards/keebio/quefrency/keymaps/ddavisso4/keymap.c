#include QMK_KEYBOARD_H
#include <data.h>

enum layer_names {
    BASE,
    NAV,
    FN1,
    FN2,
    UTIL,
    ALT_TAB_SWITCH,
    WIN_TAB_SWITCH
};

enum custom_keycodes {
    MC_ADMIN = SAFE_RANGE,
    MC_TG_BKMK,
    MC_NAV_BKMK,
    MC_TEST,
    MC_CLR_ALT_TAB,
    MC_CLR_WIN_TAB,
    MC_DEF,
    MC_COMMENT,
    MC_UNCMNT,
    MC_GO_BASE,
    MC_NAV_S_UP,
    MC_NAV_S_DWN,
    LAYER_LOCK_NAV,
    LAYER_LOCK_FN1,
    LAYER_LOCK_FN2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_all(
            KC_NO, KC_NO,
KC_GRV   ,KC_1      ,KC_2      ,KC_3    ,KC_4    ,KC_5    ,KC_6       ,         KC_7     ,KC_8     ,KC_9     ,KC_0     ,KC_MINS  ,KC_EQL     ,KC_BSPC   ,KC_BSPC  ,
            KC_NO, KC_NO, KC_NO,
KC_TAB   ,KC_Q      ,KC_W      ,KC_E    ,KC_R    ,KC_T                ,         KC_Y     ,KC_U     ,KC_I     ,KC_O     ,KC_P     ,KC_LBRC    ,KC_RBRC   ,KC_BSLS  ,
            KC_NO, KC_NO, KC_NO,
KC_CAPS  ,KC_A      ,KC_S      ,KC_D    ,KC_F    ,KC_G                ,         KC_H     ,KC_J     ,KC_K     ,KC_L     ,KC_SCLN  ,KC_QUOT    ,KC_ENTER  ,KC_ENTER ,
            KC_NO, KC_NO, KC_NO,
KC_LSFT  ,KC_BSLS   ,KC_Z      ,KC_X    ,KC_C    ,KC_V    ,KC_B       ,         KC_N     ,KC_M     ,KC_COMM  ,KC_DOT   ,KC_SLSH  ,KC_RSFT    ,MO(UTIL)  ,
            KC_NO, KC_NO, KC_NO,
KC_LCTL  ,KC_LGUI   ,KC_LALT   ,MO(FN2) ,MO(FN1) ,MO(NAV)             ,         KC_SPC   ,KC_SPC   ,KC_RALT  ,KC_RGUI  ,KC_RCTL  ,RCS(KC_M)  ,G(KC_L)   ,
            KC_NO),


	[NAV] = LAYOUT_all(
            KC_NO, KC_NO,
LT(0,MC_ADMIN)  ,LT(0,C(KC_F4))   ,LT(0,A(KC_TAB))  ,LT(-1,C(KC_TAB))  ,LT(0,C(KC_T))   ,LT(0,G(C(KC_LEFT)))   ,LT(0,G(C(KC_RIGHT)))       ,       KC_PGUP         ,LT(1, MC_NAV_S_UP) ,KC_NO               ,KC_NO          ,KC_NO          ,KC_NO      ,KC_NO          ,KC_NO          ,
            KC_NO, KC_NO, KC_NO,
RCS(KC_L)       ,LT(-2,KC_DEL)    ,LT(-1,KC_DEL)    ,LT(0,KC_UP)       ,LT(0,KC_BSPC)   ,C(KC_BSPC)                                        ,       A(KC_UP)        ,KC_PGDN            ,S(KC_UP)            ,C(KC_A)        ,C(KC_W)        ,KC_NO      ,KC_NO          ,KC_NO          ,
            KC_NO, KC_NO, KC_NO,
KC_ESC          ,C(KC_LEFT)       ,LT(-1,KC_LEFT)   ,LT(0,KC_DOWN)     ,LT(-1,KC_RGHT)  ,C(KC_RGHT)                                        ,       RCS(KC_LEFT)    ,S(KC_LEFT)         ,S(KC_DOWN)          ,S(KC_RGHT)     ,RCS(KC_RGHT)   ,KC_NO      ,C(KC_ENTER)    ,C(KC_ENTER)    ,
            KC_NO, KC_NO, KC_NO,
KC_ENTER        ,KC_NO            ,LT(0, KC_HOME)   ,LT(0,C(KC_X))     ,LT(0,C(KC_C))  ,LT(0,C(KC_V))          ,LT(0, KC_END)              ,       A(KC_DOWN)      ,LT(-1,KC_HOME)     ,LT(0, MC_NAV_S_DWN) ,LT(-1,KC_END)  ,KC_NO          ,KC_NO      ,KC_NO          ,
            KC_NO, KC_NO, KC_NO,
KC_SPACE        ,KC_APPLICATION   ,KC_PRINT_SCREEN  ,C(KC_R)           ,KC_F5          ,KC_TRNS                                            ,       C(KC_SPACE)     ,C(KC_SPACE)        ,KC_TRNS             ,KC_TRNS        ,KC_TRNS        ,KC_TRNS    ,KC_TRNS        ,
        KC_NO),


	[FN1] = LAYOUT_all(
            KC_NO, KC_NO,
LSA(KC_D)           ,C(KC_1)        ,MEH(KC_H)    ,MEH(KC_A)     ,MEH(KC_D)     ,RCS(KC_MINS)    ,C(KC_MINS)        ,         RCS(KC_X)    ,C(KC_R)      ,KC_NO      ,KC_NO      ,KC_NO     ,KC_NO   ,KC_NO   ,KC_NO   ,
            KC_NO, KC_NO, KC_NO,
LT(-1,KC_F9)         ,C(KC_F10)      ,KC_F10       ,LT(0,KC_F11)  ,LT(0, KC_F5)  ,LT(0, MC_TEST)                     ,         C(KC_Y)      ,C(KC_U)     ,C(KC_I)     ,KC_NO      ,KC_NO     ,KC_NO   ,KC_NO   ,KC_NO   ,
            KC_NO, KC_NO, KC_NO,
KC_F3               ,LT(0,S(KC_F2)) ,LT(0,KC_S)   ,LT(0,KC_D)    ,LT(0,KC_F)    ,LT(0,C(KC_G))                      ,         C(KC_H)      ,KC_NO       ,C(KC_K)     ,C(KC_L)    ,KC_NO     ,KC_NO   ,KC_NO   ,KC_NO   ,
            KC_NO, KC_NO, KC_NO,
LT(0, MC_NAV_BKMK)  ,KC_NO          ,LT(0,KC_Z)   ,LT(-1,MC_DEF) ,LCA(KC_GRV)   ,KC_F2           ,LT(0,KC_B)        ,        C(KC_N)       ,MC_COMMENT  ,C(KC_COMM)  ,C(KC_DOT)  ,MC_UNCMNT ,KC_NO   ,KC_NO   ,
            KC_NO, KC_NO, KC_NO,
MC_TG_BKMK          ,KC_TRNS        ,KC_TRNS      ,KC_NO         ,KC_TRNS       ,KC_NO                              ,         KC_NO        ,KC_NO       ,KC_NO       ,KC_NO      ,KC_NO     ,KC_NO   ,KC_NO   ,
            KC_NO),


	[FN2] = LAYOUT_all(
            KC_NO, KC_NO,
KC_MNXT         ,KC_MUTE        ,KC_VOLD    ,KC_VOLU   ,KC_MPLY   ,KC_MPRV   ,KC_MNXT           ,        KC_NO            ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
            KC_NO, KC_NO, KC_NO,
KC_MPRV         ,RCS(KC_I)      ,C(KC_2)    ,C(KC_E)   ,KC_NO     ,KC_NO                        ,        LSA(KC_C)        ,KC_1    ,KC_2    ,KC_3    ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
            KC_NO, KC_NO, KC_NO,
RCS(KC_1)       ,RCS(KC_5)      ,C(KC_Q)    ,KC_NO     ,C(KC_F)   ,KC_NO                        ,        LT(0, C(KC_E))   ,KC_4    ,KC_5    ,KC_6    ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
            KC_NO, KC_NO, KC_NO,
LAYER_LOCK_NAV  ,KC_NO          ,RCS(KC_R)  ,C(KC_R)   ,KC_NO     ,KC_NO      ,KC_NO            ,        C(KC_N)          ,KC_7    ,KC_8    ,KC_9    ,KC_NO   ,KC_NO   ,KC_NO   ,
            KC_NO, KC_NO, KC_NO,
LAYER_LOCK_FN1  ,LAYER_LOCK_FN2 ,KC_NO      ,KC_TRNS   ,KC_NO     ,KC_NO                        ,        KC_NO            ,KC_0    ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
            KC_NO),


	[UTIL] = LAYOUT_all(
            KC_NO, KC_NO,
KC_NO   ,KC_F1     ,KC_F2     ,KC_F3    ,KC_F4     ,KC_F5   ,KC_F6                    ,        KC_F7   ,KC_F8                         ,KC_F9                         ,KC_F10                     ,KC_F11   ,KC_F12    ,KC_NO   ,KC_NO   ,
            KC_NO, KC_NO, KC_NO,
KC_NO   ,KC_INS    ,KC_PAUS   ,KC_SCRL  ,KC_NUM    ,KC_NO                             ,        KC_NO   ,QK_DYNAMIC_TAPPING_TERM_PRINT , QK_DYNAMIC_TAPPING_TERM_DOWN ,QK_DYNAMIC_TAPPING_TERM_UP ,KC_NO    ,KC_NO     ,KC_NO   ,KC_NO   ,
            KC_NO, KC_NO, KC_NO,
KC_NO   ,BL_TOGG   ,BL_DOWN   ,BL_UP    ,KC_NO     ,KC_NO                             ,        KC_NO   ,KC_NO                         ,KC_NO                         ,KC_NO                      ,KC_NO    ,KC_NO     ,KC_NO   ,KC_NO   ,
            KC_NO, KC_NO, KC_NO,
KC_NO   ,KC_NO     ,RGB_TOG   ,RGB_VAD        ,RGB_VAI        ,KC_NO   ,KC_NO         ,        KC_NO   ,KC_NO                         ,KC_NO                         ,KC_NO                      ,KC_NO    ,KC_NO     ,KC_NO   ,
            KC_NO, KC_NO, KC_NO,
KC_NO   ,KC_NO     ,KC_NO     ,LAYER_LOCK_FN2 ,LAYER_LOCK_FN1 ,LAYER_LOCK_NAV         ,        KC_NO   ,KC_NO                         ,KC_NO                         ,KC_NO                      ,KC_NO    ,KC_TRNS   ,KC_NO   ,
            KC_NO),


    [ALT_TAB_SWITCH] = LAYOUT_all(
            KC_NO, KC_NO,
KC_NO   ,S(KC_TAB) ,MC_CLR_ALT_TAB  ,KC_TAB  ,KC_NO   ,KC_NO   ,KC_NO         ,        KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,MC_GO_BASE ,
            KC_NO, KC_NO, KC_NO,
KC_NO   ,KC_NO     ,KC_NO           ,KC_NO   ,KC_NO   ,KC_NO                  ,        KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO      ,
            KC_NO, KC_NO, KC_NO,
KC_NO   ,KC_NO     ,KC_NO           ,KC_NO   ,KC_NO   ,KC_NO                  ,        KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO      ,
            KC_NO, KC_NO, KC_NO,
KC_NO   ,KC_NO     ,KC_NO           ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO         ,        KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
            KC_NO, KC_NO, KC_NO,
KC_NO   ,KC_NO     ,KC_NO           ,KC_NO   ,KC_NO   ,MC_CLR_ALT_TAB         ,        KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
            KC_NO),

    [WIN_TAB_SWITCH] = LAYOUT_all(
            KC_NO, KC_NO,
KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO         ,        KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,MC_GO_BASE ,
            KC_NO, KC_NO, KC_NO,
KC_NO   ,KC_NO   ,KC_1    ,KC_2    ,KC_3    ,KC_NO                  ,        KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO      ,
            KC_NO, KC_NO, KC_NO,
KC_NO   ,KC_NO   ,KC_4    ,KC_5    ,KC_6    ,KC_NO                  ,        KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO      ,
            KC_NO, KC_NO, KC_NO,
KC_NO   ,KC_NO   ,KC_NO   ,KC_7    ,KC_8    ,KC_9    ,KC_NO         ,        KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
            KC_NO, KC_NO, KC_NO,
KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO                  ,        KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
            KC_NO)
};

// Blank layer
// [NEW_LAYER_NAME] = LAYOUT_all(
//             KC_NO, KC_NO,
// KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO         ,        KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
//             KC_NO, KC_NO, KC_NO,
// KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO                  ,        KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
//             KC_NO, KC_NO, KC_NO,
// KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO                  ,        KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
//             KC_NO, KC_NO, KC_NO,
// KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO         ,        KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
//             KC_NO, KC_NO, KC_NO,
// KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO                  ,        KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
//             KC_NO)

void win_switch_app(uint8_t num) {
    register_code(KC_LGUI);
    layer_move(WIN_TAB_SWITCH);
    tap_code_delay(num, 30);
}

void reset_to_base(void) {
    clear_keyboard();
    layer_move(BASE);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Use this to print details for every keystrike
    // uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);

    switch (keycode) {

        // Send string macros
        case LT(0,MC_ADMIN):
            if (record->tap.count && record->event.pressed) {
                SEND_STRING(
                    SS_TAP(X_TAB)
                    SS_DELAY(25)
                    SS_TAP(X_TAB)
                    SS_DELAY(25)
                    SS_TAP(X_ENTER)
                    SS_DELAY(100)
                    SS_TAP(X_TAB)
                    SS_DELAY(25)
                    SS_TAP(X_TAB)
                    SS_DELAY(25)
                    SS_TAP(X_ENTER)
                    SS_DELAY(50)
                    SS_TAP(X_TAB)
                    SS_DELAY(25)
                    LOCAL_ADMIN_ACCOUNT
                    SS_DELAY(25)
                    SS_DOWN(X_LSFT) SS_TAP(X_TAB) SS_UP(X_LSFT));
            } else if (record->event.pressed) {
                SEND_STRING(
                    SS_TAP(X_TAB)
                    SS_DELAY(25)
                    SS_TAP(X_TAB)
                    SS_DELAY(25)
                    SS_TAP(X_ENTER)
                    SS_DELAY(100)
                    SS_TAP(X_TAB)
                    SS_DELAY(25)
                    SS_TAP(X_TAB)
                    SS_DELAY(25)
                    SS_TAP(X_ENTER)
                    SS_DELAY(50)
                    SS_TAP(X_TAB)
                    SS_DELAY(25)
                    ADMIN_ACCOUNT
                    SS_DELAY(25)
                    SS_DOWN(X_LSFT) SS_TAP(X_TAB) SS_UP(X_LSFT));
            }
            return false;
        case MC_TG_BKMK:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL("kk"), 20);
                return false;
            }
            return true;
        case MC_CLR_ALT_TAB:
            if (record->event.pressed) {
                reset_to_base();
                return false;
            }
            return true;
        case MC_CLR_WIN_TAB:
            unregister_code(KC_LGUI);
            reset_to_base();
            return false;
        case MO(NAV):
            // Special case where pressed on base layer and released on win tab layer
            if(IS_LAYER_ON(WIN_TAB_SWITCH) && !record->event.pressed) {
                unregister_code(KC_LGUI);
                reset_to_base();
                return false;
            }
            // Already on NAV and pressed means we are in lock mode and want to return to BASE
            else if(IS_LAYER_ON(NAV) && record->event.pressed) {
                reset_to_base();
                return false;
            }
            return true;
        case MO(FN1):
            if(IS_LAYER_ON(FN1) && record->event.pressed) {
                reset_to_base();
                return false;
            }
            return true;
        case MO(FN2):
            if(IS_LAYER_ON(FN2) && record->event.pressed) {
                reset_to_base();
                return false;
            }
            return true;
        case MC_COMMENT:
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
        case MC_GO_BASE:
            if (record->event.pressed) {
                reset_to_base();
                return false;
            }
            return true;
        case LAYER_LOCK_NAV:
            layer_move(NAV);
            return false;
        case LAYER_LOCK_FN1:
            layer_move(FN1);
            return false;
        case LAYER_LOCK_FN2:
            layer_move(FN2);
            return false;

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
                layer_move(ALT_TAB_SWITCH);
                register_code(KC_LALT);
                tap_code_delay(KC_TAB, 50);
            } else if (record->event.pressed) {
                tap_code16(G(KC_TAB));
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
        case LT(0,G(C(KC_LEFT))):
            if (record->tap.count && record->event.pressed) {
                tap_code16(G(C(KC_LEFT))); // Tap
            } else if (record->event.pressed) {
                tap_code16(A(KC_LEFT)); // Hold
            }
            return false;
        case LT(0,G(C(KC_RIGHT))):
            if (record->tap.count && record->event.pressed) {
                tap_code16(G(C(KC_RIGHT))); // Tap
            } else if (record->event.pressed) {
                tap_code16(A(KC_RGHT)); // Hold
            }
            return false;
        case LT(-1,KC_DEL):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_DEL); // Tap
            } else if (record->event.pressed) {
                win_switch_app(KC_1);
            }
            return false;
        case LT(0,KC_UP):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_UP); // Tap
            } else if (record->event.pressed) {
                win_switch_app(KC_2);
            }
            return false;
        case LT(0,KC_BSPC):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_BSPC); // Tap
            } else if (record->event.pressed) {
                win_switch_app(KC_3);
            }
            return false;
        case LT(-1,KC_LEFT):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LEFT); // Tap
            } else if (record->event.pressed) {
                win_switch_app(KC_4);
            }
            return false;
        case LT(0,KC_DOWN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_DOWN); // Tap
            } else if (record->event.pressed) {
                win_switch_app(KC_5);
            }
            return false;
        case LT(-1,KC_RGHT):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RGHT); // Tap
            } else if (record->event.pressed) {
                win_switch_app(KC_6);
            }
            return false;
        case LT(0,C(KC_X)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_X)); // Tap
            } else if (record->event.pressed) {
                win_switch_app(KC_7);
            }
            return false;
        case LT(0,C(KC_C)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_C)); // Tap
            } else if (record->event.pressed) {
                win_switch_app(KC_8);
            }
            return false;
        case LT(0,C(KC_V)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_V)); // Tap
            } else if (record->event.pressed) {
                win_switch_app(KC_9);
            }
            return false;
        case LT(0,KC_S):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_S)); // Tap
            } else if (record->event.pressed) {
                tap_code16(RCS(KC_S));
            }
            return false;
        case LT(0,KC_F):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_F)); // Tap
            } else if (record->event.pressed) {
                tap_code16(RCS(KC_F));
            }
            return false;
        case LT(0,KC_B):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_B)); // Tap
            } else if (record->event.pressed) {
                tap_code16(RCS(KC_B));
            }
            return false;
        case LT(-1,KC_HOME):
            if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_HOME)); // Tap
            } else if (record->event.pressed) {
                tap_code16(RCS(KC_HOME));
            }
            return false;
        case LT(-1,KC_END):
            if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_END)); // Tap
            } else if (record->event.pressed) {
                tap_code16(RCS(KC_END));
            }
            return false;
        case LT(0,KC_F11):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_F11); // Tap
            } else if (record->event.pressed) {
                tap_code16(C(KC_E));
            }
            return false;
        case LT(-2,KC_DEL):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_DEL)); // Tap
            } else if (record->event.pressed) {
                win_switch_app(KC_0);
            }
            return false;
        case LT(-1,MC_DEF):
            if (record->tap.count && record->event.pressed) {
                tap_code16(RCS(KC_GRV)); // Tap
            } else if (record->event.pressed) {
                tap_code16(C(KC_GRV));
            }
            return false;
        case LT(0,KC_Z):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_Z)); // Tap
            } else if (record->event.pressed) {
                tap_code16(C(KC_Y));
            }
            return false;
        case LT(0,C(KC_G)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_G)); // Tap
            } else if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL("kd"), 20);
            }
            return false;
        case LT(1, MC_NAV_S_UP):
            if (record->tap.count && record->event.pressed) {
                tap_code16(LSA(KC_UP)); // Tap
            } else if (record->event.pressed) {
                tap_code16(RCS(KC_UP));
            }
            return false;
        case LT(0, MC_NAV_S_DWN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(LSA(KC_DOWN)); // Tap
            } else if (record->event.pressed) {
                tap_code16(RCS(KC_DOWN));
            }
            return false;
        case LT(0,S(KC_F2)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_F2)); // Tap, Add file
            } else if (record->event.pressed) {
                tap_code16(S(KC_F1)); // Press, Add folder
            }
            return false;
        case LT(0,KC_D):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_D));                  // Tap, Duplicate Line
            } else if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL("[") "s", 20); // Press, Sync Solution
            }
            return false;
        case LT(-1,KC_F9):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_F9);               // Tap, Breakpoint
            } else if (record->event.pressed) {
                tap_code16(LCA(KC_P));           // Press, Debug
            }
            return false;
    }

    return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    if(get_highest_layer(state) > 0) {
        backlight_enable();
    }
    else {
        backlight_disable();
    }

    return state;
}
