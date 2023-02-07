#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Tap Dance Declarations
enum {
    TD_LGUI_LALT = 0,
    TD_RGUI_RALT,
    TD_RALT_RGUI,
    TD_HOME_END
};

#define KC_ KC_TRNS

#define KC_BL_S BL_STEP
#define KC_CTSC LCTL_T(KC_ESC)
#define KC_DVRK DVORAK
#define KC_GMNG GAMING
#define KC_GRAV KC_GRAVE
#define KC_HOND TD(TD_HOME_END)
#define KC_LGA TD(TD_LGUI_LALT)
#define KC_LOWR LOWER
#define KC_QWRT QWERTY
#define KC_RASE RAISE
#define KC_RGA TD(TD_RALT_RGUI)
#define KC_RHUD RGB_HUD
#define KC_RHUI RGB_HUI
#define KC_RMD RGB_MOD
#define KC_RRMD RGB_RMOD
#define KC_RSAD RGB_SAD
#define KC_RSAI RGB_SAI
#define KC_RTOG RGB_TOG
#define KC_RVAD RGB_VAD
#define KC_RVAI RGB_VAI
#define KC_SENT RSFT_T(KC_ENT)
#define KC_CME CMD_T(KC_E)
#define KC_CMT CMD_T(KC_T)
#define KC_SHU LSFT_T(KC_U)
#define KC_SHH RSFT_T(KC_H)
#define KC_ALO ALT_T(KC_O)
#define KC_ALN ALT_T(KC_N)
#define KC_CTA CTL_T(KC_A)
#define KC_CTS CTL_T(KC_S)

#define _DVORAK 0
#define _QWERTY 1
#define _GAMING 2
#define _LOWER  3
#define _RAISE  4

#define _ADJUST 16

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  GAMING,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_DVORAK] = LAYOUT(
  //┌───────┬────────┬──────┬────────┬──────┬───────┐                      ┌───────┬───────┬───────┬───────┬───────┬───────┐
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                        KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
  //├───────┼────────┼──────┼────────┼──────┼───────┤                      ├───────┼───────┼───────┼───────┼───────┼───────┤
     KC_TAB ,KC_QUOT,KC_COMM,KC_DOT , KC_P  , KC_Y  ,                        KC_F  , KC_G  , KC_C  , KC_R  , KC_L  ,KC_SLSH,
  //├───────┼────────┼──────┼────────┼──────┼───────┤                      ├───────┼───────┼───────┼───────┼───────┼───────┤
     KC_CTSC,KC_CTA ,KC_ALO ,KC_CME ,KC_SHU , KC_I  ,                        KC_D  ,KC_SHH ,KC_CMT ,KC_ALN ,KC_CTS ,KC_MINS,
  //├───────┼────────┼──────┼────────┼──────┼───────┼──────┐       ┌──────┼────────┼───────┼───────┼───────┼───────┼───────┤
     KC_LSFT,KC_SCLN, KC_Q  , KC_J  , KC_K  , KC_X  ,_______,        KC_HOND, KC_B  , KC_M  , KC_W  , KC_V  , KC_Z  ,KC_SENT,
  //└───────┴────────┴──────┴───┬────┴───┬──┴────┬──┴────┬─┘       └─┬────┴──┬ ────┴─┬─────┴┬──────┴───────┴───────┴───────┘
                                   KC_LGA,KC_LOWR,KC_ENT ,            KC_SPC ,KC_RASE,KC_RGA
                             // └────────┴───────┴───────┘           └───────┴───────┴──────┘
  ),

  [_QWERTY] = LAYOUT(
  //┌───────┬────────┬──────┬────────┬──────┬───────┐                      ┌───────┬───────┬───────┬───────┬───────┬───────┐
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                        KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
  //├───────┼────────┼──────┼────────┼──────┼───────┤                      ├───────┼───────┼───────┼───────┼───────┼───────┤
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                        KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSLS,
  //├───────┼────────┼──────┼────────┼──────┼───────┤                      ├───────┼───────┼───────┼───────┼───────┼───────┤
     KC_CTSC, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                        KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
  //├───────┼────────┼──────┼────────┼──────┼───────┼──────┐       ┌───────┼────────┼───────┼───────┼───────┼───────┼──────┤
     KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,_______,        KC_HOND, KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_SENT,
  //└───────┴────────┴──────┴───┬────┴───┬──┴────┬──┴────┬─┘       └─┬─────┴─┬─────┴─┬─────┴┬──────┴───────┴───────┴───────┘
                                   KC_LGA,KC_LOWR,KC_ENT ,            KC_SPC ,KC_RASE,KC_RGA
                             // └────────┴───────┴───────┘           └───────┴───────┴──────┘
  ),

  [_GAMING] = LAYOUT(
  //┌───────┬────────┬──────┬────────┬──────┬───────┐                      ┌───────┬───────┬───────┬───────┬───────┬───────┐
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                        KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_ESC ,
  //├───────┼────────┼──────┼────────┼──────┼───────┤                      ├───────┼───────┼───────┼───────┼───────┼───────┤
      KC_T  ,KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  ,                        KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_DEL ,
  //├───────┼────────┼──────┼────────┼──────┼───────┤                      ├───────┼───────┼───────┼───────┼───────┼───────┤
      KC_G  ,KC_LCTL, KC_A  , KC_S  , KC_D  , KC_F  ,                        KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_RCTL,
  //├───────┼────────┼──────┼────────┼──────┼───────┼──────┐       ┌───────┼────────┼───────┼───────┼───────┼───────┼──────┤
      KC_B  ,KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  ,_______,        KC_LOWR, KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_SENT,
  //└───────┴────────┴──────┴───┬────┴───┬──┴────┬──┴────┬─┘       └─┬──── ┴─┬─────┴─┬─────┴┬──────┴───────┴───────┴───────┘
                                  KC_LOWR,KC_SPC ,KC_SPC ,            KC_SPC ,KC_RASE,KC_RGA
                             // └────────┴───────┴───────┘           └───────┴───────┴──────┘
  ),

  [_LOWER] = LAYOUT(
  //┌───────┬────────┬──────┬────────┬──────┬───────┐                      ┌───────┬───────┬───────┬───────┬───────┬───────┐
     KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                       KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_BSPC,
  //├───────┼────────┼──────┼────────┼──────┼───────┤                      ├───────┼───────┼───────┼───────┼───────┼───────┤
     KC_TILD,KC_GRAV,_______, KC_UP ,KC_EQL ,KC_LBRC,                       KC_RBRC, KC_P7 , KC_P8 , KC_P9 , KC_0  ,KC_BSLS,
  //├───────┼────────┼──────┼────────┼──────┼───────┤                      ├───────┼───────┼───────┼───────┼───────┼───────┤
     _______,KC_DEL ,KC_LEFT,KC_DOWN,KC_RGHT,KC_LPRN,                       KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_PLUS,KC_PIPE,
  //├───────┼────────┼──────┼────────┼──────┼───────┼──────┐       ┌───────┼────────┼───────┼───────┼───────┼───────┼──────┤
     _______,KC_BL_S,_______,_______,_______,KC_LCBR,_______,       _______,KC_RCBR, KC_P1 , KC_P2 , KC_P3 ,KC_MINS,_______,
  //└───────┴────────┴──────┴───┬────┴───┬──┴────┬──┴────┬─┘       └─┬─────┴──┬─────┴─┬─────┴┬──────┴───────┴───────┴──────┘
                                  _______,_______,KC_DEL ,            _______,_______, KC_P0
                             // └────────┴───────┴───────┘           └───────┴───────┴──────┘
  ),

  [_RAISE] = LAYOUT(
  //┌───────┬────────┬──────┬────────┬──────┬───────┐                      ┌───────┬───────┬───────┬───────┬───────┬───────┐
     KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6 , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
  //├───────┼────────┼──────┼────────┼──────┼───────┤                      ├───────┼───────┼───────┼───────┼───────┼───────┤
     _______,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                       KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_BSLS,
  //├───────┼────────┼──────┼────────┼──────┼───────┤                      ├───────┼───────┼───────┼───────┼───────┼───────┤
     KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6 , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
  //├───────┼────────┼──────┼────────┼──────┼───────┼──────┐       ┌──────┼────────┼───────┼───────┼───────┼───────┼───────┤
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,_______,      _______,  KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_ESC ,
  //└───────┴────────┴──────┴───┬────┴───┬──┴────┬──┴────┬─┘       └─┬────┴──┬ ────┴─┬─────┴┬──────┴───────┴───────┴───────┘
                                  _______,_______,_______,            _______,_______,_______
                             // └────────┴───────┴───────┘           └───────┴───────┴──────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌───────┬────────┬──────┬────────┬──────┬───────┐                      ┌───────┬───────┬───────┬───────┬───────┬───────┐
     _______,KC_RMD ,KC_RHUI,KC_RSAI,KC_RVAI,KC_RTOG,                       _______,_______,_______,_______,_______,_______,
  //├───────┼────────┼──────┼────────┼──────┼───────┤                      ├───────┼───────┼───────┼───────┼───────┼───────┤
     _______,KC_RRMD,KC_RHUD,KC_RSAD,KC_RVAD,KC_BL_S,                       _______,_______,_______,_______,_______,_______,
  //├───────┼────────┼──────┼────────┼──────┼───────┤                      ├───────┼───────┼───────┼───────┼───────┼───────┤
     _______,_______,_______,KC_DVRK,KC_QWRT,_______,                       _______,KC_GMNG,_______,_______,_______,_______,
  //├───────┼────────┼──────┼────────┼──────┼───────┼──────┐       ┌──────┼────────┼───────┼───────┼───────┼───────┼───────┤
     _______,_______,_______,_______,_______,_______,_______,       _______,_______,_______,_______,_______,_______,_______,
  //└───────┴────────┴──────┴───┬────┴───┬──┴────┬──┴────┬─┘       └─┬────┴──┬ ────┴─┬─────┴┬──────┴───────┴───────┴───────┘
                                  _______,_______,_______,            _______,_______,_______
                             // └────────┴───────┴───────┘           └───────┴───────┴──────┘
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case GAMING:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_GAMING);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
  }
  else if (index == 1) {
    if (clockwise) {
        tap_code(KC_PGDN);
    } else {
        tap_code(KC_PGUP);
    }
  }
  return clockwise;
}

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for L-GUI, twice for L-Alt
    [TD_LGUI_LALT] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_LALT),
    // Tap once for R-GUI, twice for R-Alt
    [TD_RALT_RGUI] = ACTION_TAP_DANCE_DOUBLE(KC_RALT, KC_RGUI),
    // Tap once for HOME, twice for END
    [TD_HOME_END] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END),
};
