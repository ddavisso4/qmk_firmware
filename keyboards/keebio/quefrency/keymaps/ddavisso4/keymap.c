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
    MC_TMS_CMP,
    MC_00,
    LAYER_LOCK_NAV,
    LAYER_LOCK_FN1,
    LAYER_LOCK_FN2,
    RESET_LAYER_LOCK,
    ENABLE_CONSOLE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_all(
            KC_NO, KC_NO,
KC_GRV   ,KC_1                 ,KC_2      ,KC_3    ,KC_4    ,KC_5    ,KC_6       ,         KC_7     ,KC_8     ,KC_9     ,KC_0     ,KC_MINS              ,KC_EQL     ,KC_BSPC   ,KC_BSPC  ,
            KC_NO, KC_NO, KC_NO,
KC_TAB   ,KC_Q                 ,KC_W      ,KC_E    ,KC_R    ,KC_T                ,         KC_Y     ,KC_U     ,KC_I     ,KC_O     ,KC_P                 ,KC_LBRC    ,KC_RBRC   ,KC_BSLS  ,
            KC_NO, KC_NO, KC_NO,
KC_CAPS  ,KC_A                 ,KC_S      ,KC_D    ,KC_F    ,KC_G                ,         KC_H     ,KC_J     ,KC_K     ,KC_L     ,KC_SCLN              ,KC_QUOT    ,KC_ENTER  ,KC_ENTER ,
            KC_NO, KC_NO, KC_NO,
KC_LSFT  ,MT(MOD_LSFT,KC_BSLS) ,KC_Z      ,KC_X    ,KC_C    ,KC_V    ,KC_B       ,         KC_N     ,KC_M     ,KC_COMM  ,KC_DOT   ,MT(MOD_RSFT,KC_SLSH) ,KC_RSFT    ,MO(UTIL)  ,
            KC_NO, KC_NO, KC_NO,
KC_LCTL  ,KC_LGUI              ,KC_LALT   ,MO(FN2) ,MO(FN1) ,MO(NAV)             ,         KC_SPC   ,KC_SPC   ,KC_RALT  ,KC_RGUI  ,KC_RCTL              ,RCS(KC_M)  ,G(KC_L)   ,
            KC_NO),

	[NAV] = LAYOUT_all(
            KC_NO, KC_NO,
LT(0,MC_ADMIN)  ,LT(0,C(KC_F4))   ,LT(0,A(KC_TAB))  ,LT(-1,C(KC_TAB))  ,LT(0,C(KC_T))   ,LT(0,G(C(KC_LEFT)))   ,LT(0,G(C(KC_RIGHT)))       ,       KC_PGUP         ,LT(1, MC_NAV_S_UP) ,S(KC_LBRC)          ,S(KC_RBRC)     ,S(KC_GRV)      ,KC_NO      ,KC_NO          ,KC_NO          ,
            KC_NO, KC_NO, KC_NO,
RCS(KC_L)       ,LT(-2,KC_DEL)    ,LT(-1,KC_DEL)    ,LT(0,KC_UP)       ,LT(0,KC_BSPC)   ,C(KC_BSPC)                                        ,       A(KC_UP)        ,KC_PGDN            ,S(KC_UP)            ,C(KC_A)        ,C(KC_W)        ,LT(1,KC_7) ,KC_NO          ,KC_NO          ,
            KC_NO, KC_NO, KC_NO,
KC_ESC          ,C(KC_LEFT)       ,LT(-1,KC_LEFT)   ,LT(0,KC_DOWN)     ,LT(-1,KC_RGHT)  ,C(KC_RGHT)                                        ,       RCS(KC_LEFT)    ,S(KC_LEFT)         ,S(KC_DOWN)          ,S(KC_RGHT)     ,RCS(KC_RGHT)   ,KC_GRV     ,C(KC_ENTER)    ,C(KC_ENTER)    ,
            KC_NO, KC_NO, KC_NO,
KC_ENTER        ,KC_NO            ,LT(0, KC_HOME)   ,LT(0,C(KC_X))     ,LT(0,C(KC_C))  ,LT(0,C(KC_V))          ,LT(0, KC_END)              ,       A(KC_DOWN)      ,LT(-1,KC_HOME)     ,LT(0, MC_NAV_S_DWN) ,LT(-1,KC_END)  ,S(KC_MINS)     ,KC_TRNS    ,KC_NO          ,
            KC_NO, KC_NO, KC_NO,
KC_SPACE        ,KC_APPLICATION   ,LT(0,KC_PSCR)    ,C(KC_R)           ,KC_F5          ,MO(NAV)                                            ,       C(KC_SPACE)     ,C(KC_SPACE)        ,KC_TRNS             ,KC_TRNS        ,KC_TRNS        ,KC_TRNS    ,KC_TRNS        ,
        KC_NO),


	[FN1] = LAYOUT_all(
            KC_NO, KC_NO,
LSA(KC_D)           ,LT(1,KC_1)     ,LT(1,KC_2)   ,LT(1,KC_3)    ,LT(1,KC_4)    ,RCS(KC_MINS)    ,C(KC_MINS)        ,         RCS(KC_X)    ,LT(1,MC_TMS_CMP)  ,KC_LBRC     ,KC_RBRC    ,KC_NO        ,KC_NO         ,KC_NO   ,KC_NO   ,
            KC_NO, KC_NO, KC_NO,
LT(-1,KC_F9)        ,C(KC_F10)      ,KC_F10       ,LT(0,KC_F11)  ,LT(0, KC_F5)  ,LT(0, MC_TEST)                     ,         C(KC_Y)      ,C(KC_U)           ,C(KC_I)     ,KC_NO      ,LT(1,KC_P)   ,LT(2,KC_MINS) ,KC_NO   ,KC_NO   ,
            KC_NO, KC_NO, KC_NO,
KC_F3               ,LT(0,S(KC_F2)) ,LT(0,KC_S)   ,LT(0,KC_D)    ,LT(0,KC_F)    ,LT(0,C(KC_G))                      ,         LT(1,KC_H)   ,LT(1,KC_EQL)      ,C(KC_K)     ,C(KC_L)    ,LT(2,KC_1)   ,LT(2,KC_EQL)  ,KC_NO   ,KC_NO   ,
            KC_NO, KC_NO, KC_NO,
LT(0, MC_NAV_BKMK)  ,KC_NO          ,LT(0,KC_Z)   ,LT(-1,MC_DEF) ,LT(1,KC_C)    ,LT(1,KC_V)      ,LT(0,KC_B)        ,        C(KC_N)       ,MC_COMMENT        ,C(KC_COMM)  ,C(KC_DOT)  ,MC_UNCMNT    ,KC_NO         ,KC_NO   ,
            KC_NO, KC_NO, KC_NO,
MC_TG_BKMK          ,KC_TRNS        ,KC_TRNS      ,KC_NO         ,KC_TRNS       ,RESET_LAYER_LOCK                   ,         KC_NO        ,KC_NO             ,KC_NO       ,KC_NO      ,KC_NO        ,KC_NO         ,KC_NO   ,
            KC_NO),


	[FN2] = LAYOUT_all(
            KC_NO, KC_NO,
KC_MNXT         ,KC_MUTE         ,KC_VOLD        ,KC_VOLU   ,KC_MPLY    ,KC_MPRV   ,KC_MNXT           ,        KC_TAB  ,KC_SLSH ,S(KC_8) ,KC_BSPC  ,KC_NO     ,KC_NO   ,KC_NO   ,KC_NO   ,
            KC_NO, KC_NO, KC_NO,
KC_MPRV         ,RCS(KC_I)       ,C(KC_2)        ,C(KC_E)   ,LT(2,KC_R) ,KC_NO                        ,        KC_NO   ,KC_7    ,KC_8    ,KC_9     ,KC_MINS   ,KC_NO   ,KC_NO   ,KC_NO   ,
            KC_NO, KC_NO, KC_NO,
RCS(KC_1)       ,RCS(KC_5)       ,A(KC_S)        ,C(KC_Q)   ,C(KC_F)    ,KC_NO                        ,        KC_NO   ,KC_4    ,KC_5    ,KC_6     ,S(KC_EQL) ,KC_NO   ,KC_NO   ,KC_NO   ,
            KC_NO, KC_NO, KC_NO,
RCS(KC_2)       ,KC_NO           ,RCS(KC_3)      ,RCS(KC_4) ,KC_NO      ,KC_NO      ,KC_NO            ,        KC_NO   ,KC_1    ,KC_2    ,KC_3     ,KC_ENT    ,KC_NO   ,KC_NO   ,
            KC_NO, KC_NO, KC_NO,
LAYER_LOCK_NAV  ,LAYER_LOCK_FN1  ,LAYER_LOCK_FN2 ,KC_TRNS   ,KC_NO      ,RESET_LAYER_LOCK             ,        KC_0    ,KC_0    ,MC_00   ,KC_DOT   ,KC_ENT    ,KC_NO   ,KC_NO   ,
            KC_NO),


	[UTIL] = LAYOUT_all(
            KC_NO, KC_NO,
KC_NO   ,KC_F1     ,KC_F2     ,KC_F3    ,KC_F4     ,KC_F5   ,KC_F6                    ,        KC_F7   ,KC_F8                         ,KC_F9                         ,KC_F10                     ,KC_F11   ,KC_F12    ,KC_NO   ,KC_NO           ,
            KC_NO, KC_NO, KC_NO,
KC_NO   ,KC_INS    ,KC_PAUS   ,KC_SCRL  ,KC_NUM    ,KC_NO                             ,        KC_NO   ,QK_DYNAMIC_TAPPING_TERM_PRINT , QK_DYNAMIC_TAPPING_TERM_DOWN ,QK_DYNAMIC_TAPPING_TERM_UP ,KC_NO    ,KC_NO     ,KC_NO   ,KC_NO           ,
            KC_NO, KC_NO, KC_NO,
KC_NO   ,BL_TOGG   ,BL_DOWN   ,BL_UP    ,KC_NO     ,KC_NO                             ,        KC_NO   ,KC_NO                         ,KC_NO                         ,KC_NO                      ,KC_NO    ,KC_NO     ,KC_NO   ,ENABLE_CONSOLE  ,
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

static bool console_enabled = false;
static bool layer_locked = false;

const int double_tap_timeout_ms = 100;
static bool double_tap_repeat_pending;
static bool double_tap_repeat_active;
static uint16_t double_tap_timer;
static uint16_t double_tap_key;

void win_switch_app(uint16_t num) {
    if(layer_locked) {
        return;
    }

    register_code(KC_LGUI);
    layer_move(WIN_TAB_SWITCH);
    tap_code16_delay(num, 30);
}

void reset_to_base(void) {
    layer_locked = false;
    clear_keyboard();
    layer_move(BASE);
}

void keyboard_pre_init_user(void) {
    double_tap_repeat_pending = false;
    double_tap_repeat_active = false;
    double_tap_timer = double_tap_timeout_ms;
}

bool general_tap_hold(keyrecord_t *record, uint16_t tap, uint16_t hold, bool enable_repeat, bool as_win_tab) {
    // Hold
    if(record->tap.count == 0) {
        if(record->event.pressed) {
            if(as_win_tab) {
                win_switch_app(hold);
            }
            else {
                tap_code16(hold);
            }
        }
    }
    // Tap
    else {
        if(record->event.pressed) {
            tap_code16(tap);
            if(enable_repeat && record->tap.count > 1) {
                double_tap_timer = timer_read();
                double_tap_key = tap;
                double_tap_repeat_pending = true;
            }
        }
        else {
            if(double_tap_repeat_pending) {
                double_tap_repeat_pending = false;
            }

            if(double_tap_repeat_active) {
                unregister_code16(tap);
            }
        }
    }
    return false;
}

bool simple_tap_hold(keyrecord_t *record, uint16_t tap, uint16_t hold) {
    return general_tap_hold(record, tap, hold, false, false);
}

bool hold_override(keyrecord_t *record, uint16_t hold) {
    if (!record->tap.count && record->event.pressed) {
        tap_code16(hold);
        return false;
    }
    return true;
}

bool repeat_tap_hold(keyrecord_t *record, uint16_t tap, uint16_t hold) {
    return general_tap_hold(record, tap, hold, true, false);
}

bool win_tab_tap_hold(keyrecord_t *record, uint16_t tap, uint16_t hold, bool enable_repeat) {
    return general_tap_hold(record, tap, hold, enable_repeat, true);
}

void matrix_scan_user(void) {
  if (double_tap_repeat_pending) {
    if (timer_elapsed(double_tap_timer) > double_tap_timeout_ms) {
        double_tap_repeat_pending = false;
        double_tap_repeat_active = true;
        register_code16(double_tap_key);
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Use this to print details for every keystrike
    if(console_enabled) {
        uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    }

    switch (keycode) {
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
        case MC_00:
            if (record->event.pressed) {
                SEND_STRING_DELAY("00", 20);
                return false;
            }
            return true;
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
            if (IS_LAYER_ON(WIN_TAB_SWITCH) && !record->event.pressed) {
                unregister_code(KC_LGUI);
                reset_to_base();
                return false;
            }
            // If in layer_locked mode, we want to reset on release
            else if (layer_locked) {
                if (!record->event.pressed) {
                    reset_to_base();
                }
                return false;
            }
            return true;
        case MO(FN2):
            if (layer_locked) {
                return false;
            }
            return true;
        case RESET_LAYER_LOCK:
            if (layer_locked && !record->event.pressed) {
                reset_to_base();
            }
            return false;
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
            layer_locked = true;
            layer_move(NAV);
            return false;
        case LAYER_LOCK_FN1:
            layer_locked = true;
            layer_move(FN1);
            return false;
        case LAYER_LOCK_FN2:
            layer_locked = true;
            layer_move(FN2);
            return false;
        case ENABLE_CONSOLE:
            console_enabled = !console_enabled;

        // Tap-Hold Overrides
        case LT(0, KC_HOME):
            return hold_override(record, C(KC_HOME));
        case LT(0, KC_END):
            return hold_override(record, C(KC_END));
        case LT(0, C(KC_F4)):
            return simple_tap_hold(record, C(KC_F4), A(KC_F4));
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
            return simple_tap_hold(record, C(KC_TAB), RCS(KC_TAB));
        case LT(0, C(KC_T)):
            return simple_tap_hold(record, C(KC_T), RCS(KC_T));
        case LT(0, MC_NAV_BKMK):
            if (record->tap.count && record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL("kn"), 20); // Tap
            } else if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL("kp"), 20); // Hold
            }
            return false;
        case LT(0, KC_F5):
            return hold_override(record, KC_F8);
        case LT(0, MC_TEST):
            if (record->tap.count && record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL("r") "t", 20); // Tap
            } else if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL("rt"), 20); // Hold
            }
            return false;
        case LT(0,G(C(KC_LEFT))):
            return simple_tap_hold(record, G(C(KC_LEFT)), A(KC_LEFT));
        case LT(0,G(C(KC_RIGHT))):
            return simple_tap_hold(record, G(C(KC_RIGHT)), A(KC_RGHT));
        case LT(-1,KC_DEL):
            return win_tab_tap_hold(record, KC_DEL, KC_1, true);
        case LT(0,KC_UP):
            return win_tab_tap_hold(record, KC_UP, KC_2, true);
        case LT(0,KC_BSPC):
            return win_tab_tap_hold(record, KC_BSPC, KC_3, true);
        case LT(-1,KC_LEFT):
            return win_tab_tap_hold(record, KC_LEFT, KC_4, true);
        case LT(0,KC_DOWN):
            return win_tab_tap_hold(record, KC_DOWN, KC_5, true);
        case LT(-1,KC_RGHT):
            return win_tab_tap_hold(record, KC_RGHT, KC_6, true);
        case LT(0,C(KC_X)):
            return win_tab_tap_hold(record, C(KC_X), KC_7, false);
        case LT(0,C(KC_C)):
            return win_tab_tap_hold(record, C(KC_C), KC_8, false);
        case LT(0,C(KC_V)):
            return win_tab_tap_hold(record, C(KC_V), KC_9, false);
        case LT(0,KC_S):
            return simple_tap_hold(record, C(KC_S), RCS(KC_S));
        case LT(0,KC_F):
            return simple_tap_hold(record, C(KC_F), RCS(KC_F));
        case LT(0,KC_B):
            return simple_tap_hold(record, C(KC_B), RCS(KC_B));
        case LT(-1,KC_HOME):
            return simple_tap_hold(record, S(KC_HOME), RCS(KC_HOME));
        case LT(-1,KC_END):
            return simple_tap_hold(record, S(KC_END), RCS(KC_END));
        case LT(0,KC_F11):
            return simple_tap_hold(record, KC_F11, C(KC_E));
        case LT(-2,KC_DEL):
            return win_tab_tap_hold(record, C(KC_DEL), KC_0, false);
        case LT(-1,MC_DEF):
            return simple_tap_hold(record, RCS(KC_GRV), C(KC_GRV));
        case LT(0,KC_Z):
            return simple_tap_hold(record, C(KC_Z), C(KC_Y));
        case LT(0,C(KC_G)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_G)); // Tap
            } else if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL("kd"), 20);
            }
            return false;
        case LT(1, MC_NAV_S_UP):
            return simple_tap_hold(record, LSA(KC_UP), RCS(KC_UP));
        case LT(0, MC_NAV_S_DWN):
            return simple_tap_hold(record, LSA(KC_DOWN), RCS(KC_DOWN));
        case LT(0,S(KC_F2)):
            return simple_tap_hold(record, S(KC_F2), S(KC_F1));
        case LT(0,KC_D):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_D));                  // Tap, Duplicate Line
            } else if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL("[") "s", 20); // Press, Sync Solution
            }
            return false;
        case LT(-1, KC_F9):
            return simple_tap_hold(record, KC_F9, LCA(KC_P));
        case LT(1, KC_1):
            return simple_tap_hold(record, C(KC_1), RCS(KC_1));
        case LT(1, KC_2):
            return simple_tap_hold(record, MEH(KC_H), RCS(KC_2));
        case LT(1, KC_3):
            return simple_tap_hold(record, MEH(KC_A), RCS(KC_3));
        case LT(1, KC_4):
            return simple_tap_hold(record, MEH(KC_D), RCS(KC_4));
        case LT(2, KC_R):
            return simple_tap_hold(record, RCS(KC_R), C(KC_R));
        case LT(1, KC_C):
            return simple_tap_hold(record, C(KC_C), LCA(KC_GRV));
        case LT(1, KC_V):
            return simple_tap_hold(record, C(KC_V), KC_F2);
        case LT(1, KC_H):
            return simple_tap_hold(record, C(KC_H), A(KC_A));
        case LT(0, KC_PSCR):
            return simple_tap_hold(record, KC_PSCR, RCS(KC_B));
        case LT(1, KC_P):
            return simple_tap_hold(record, C(KC_P), RCS(KC_P));
        case LT(1,MC_TMS_CMP):
            return simple_tap_hold(record, LSA(KC_C), LSA(KC_R));
        case LT(1, KC_EQL):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_EQL);
            } else if (record->event.pressed) {
                SEND_STRING_DELAY("==", 20);
            }
            return false;
        case LT(2,KC_1):
            if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_1));
            } else if (record->event.pressed) {
                SEND_STRING_DELAY("!!", 20);
            }
            return false;
        case LT(2,KC_EQL):
            if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_EQL));
            } else if (record->event.pressed) {
                SEND_STRING_DELAY("++", 20);
            }
            return false;
        case LT(1,KC_7):
            if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_7));
            } else if (record->event.pressed) {
                SEND_STRING_DELAY("&&", 20);
            }
            return false;
        case LT(2,KC_MINS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_MINS);
            } else if (record->event.pressed) {
                SEND_STRING_DELAY("--", 20);
            }
            return false;
    }

    return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    if(get_highest_layer(state) > BASE) {
        backlight_enable();
    }
    else {
        backlight_disable();
    }

    return state;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(-2,KC_DEL):
        case LT(-1,KC_DEL):
        case LT(0,KC_UP):
        case LT(0,KC_BSPC):
        case LT(-1,KC_LEFT):
        case LT(0,KC_DOWN):
        case LT(-1,KC_RGHT):
        case LT(0,C(KC_X)):
        case LT(0,C(KC_C)):
        case LT(0,C(KC_V)):
            return TAPPING_TERM_LONG;
        default:
            return TAPPING_TERM;
    }
}
