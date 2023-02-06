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
#define KC_DBUG DEBUG
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
#define KC_RST RESET
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

 [_DVORAK] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB ,QUOT,COMM,DOT , P  , Y  ,                F  , G  , C  , R  , L  ,SLSH,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     CTSC,CTA ,ALO ,CME ,SHU , I  ,                D  ,SHH ,CMT ,ALN ,CTS ,MINS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT,SCLN, Q  , J  , K  , X  ,    ,     HOND, B  , M  , W  , V  , Z  ,SENT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                        LGA,LOWR,ENT ,         SPC ,RASE,RGA
  //                  `----+----+----'        `----+----+----'
  ),

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     CTSC, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,    ,     LOWR, N  , M  ,COMM,DOT ,SLSH,SENT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                        LGA,LOWR,ENT ,         SPC ,RASE,RGA
  //                  `----+----+----'        `----+----+----'
  ),

  [_GAMING] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,ESC ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      T  ,TAB , Q  , W  , E  , R  ,                Y  , U  , I  , O  , P  ,DEL,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      G  ,LCTL, A  , S  , D  , F  ,                H  , J  , K  , L  ,SCLN,RCTL,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      B  ,LSFT, Z  , X  , C  , V  ,    ,     ENT , N  , M  ,COMM,DOT ,SLSH,SENT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                        SPC ,LOWR,SPC ,         SPC ,RASE,RGA
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     TILD,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TILD,GRAV,    , UP ,EQL ,LBRC,               RBRC, P7 , P8 , P9 , 0  ,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,DEL ,LEFT,DOWN,RGHT,LPRN,               RPRN, P4 , P5 , P6 ,PLUS,PIPE,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,BL_S,    ,    ,    ,LCBR,    ,         ,RCBR, P1 , P2 , P3 ,MINS,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,DEL ,             ,    , P0
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     ESC , 1  , 2  , 3  , 4  , 5  ,    ,         , 6  , 7  , 8  , 9  , 0  ,ESC ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,RMD ,RHUI,RSAI,RVAI,RTOG,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,RRMD,RHUD,RSAD,RVAD,BL_S,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,DVRK,QWRT,    ,                   ,GMNG,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,DBUG,    ,    ,    ,RST ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
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

void encoder_update_user(uint8_t index, bool clockwise) {
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
