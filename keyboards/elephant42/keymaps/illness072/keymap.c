
/* Copyright 2020 illness072
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H


#ifdef OLED_DRIVER_ENABLE
#include <stdio.h>
#define STEP 32
uint8_t kp = 0;
#endif

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    KC_LRST
};

#define KC_LOW LOWER
#define KC_RAI RAISE
#define KC_ KC_NO
#define KC_____ KC_TRNS
#define KC_XXXX KC_NO

#define KC_LSPC LT(_LOWER, KC_SPC)
#define KC_RSPC LT(_RAISE, KC_SPC)

#define KC_MDEL CMD_T(KC_DEL)
#define KC_CTAB CTL_T(KC_TAB)
#define KC_SENT SFT_T(KC_ENT)
#define KC_STAB SFT_T(KC_TAB)
#define KC_ABSP ALT_T(KC_BSPC)

#define KC_CDEL CTL_T(KC_DEL)


#define KC_VU KC__VOLUP
#define KC_VD KC__VOLDOWN
#define KC_MU KC__MUTE

#define KC_LTOG RGB_TOG
#define KC_LMOF RGB_MOD
#define KC_LMOP RGB_RMOD
#define KC_LHUI RGB_HUI
#define KC_LHUD RGB_HUD
#define KC_LVAI RGB_VAI
#define KC_LVAD RGB_VAD
#define KC_LSAI RGB_SAI
#define KC_LSAD RGB_SAD


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc( \
  //,----+----+----+----+----+----.                        ,----+----+----+----+----+----.
     TAB , Q  , W  , E  , R  , T  ,                          Y  , U  , I  , O  , P  ,MINS,
  //|----+----+----+----+----+----|                        |----+----+----+----+----+----|
     LCTL, A  , S  , D  , F  , G  ,                          H  , J  , K  , L  ,SCLN,QUOT,
  //`----+----+----+----+----+----|                        |----+----+----+----+----+----'
           Z  , X  , C  , V  , B  ,                          N  , M  ,COMM,DOT ,SLSH,
  //     `----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----'
                         LALT,LCMD,LSPC,LSFT,     CDEL,RSPC,SENT,ABSP
  //                    `----+----+----+----'    `----+----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.                        ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                          6  , 7  , 8  , 9  , 0  ,EQL ,
  //|----+----+----+----+----+----|                        |----+----+----+----+----+----|
     LCTL,EXLM,AT  ,HASH,DLR ,PERC,                         CIRC,AMPR,ASTR,TILD,PLUS,GRV ,
  //`----+----+----+----+----+----|                        |----+----+----+----+----+----'
          PIPE,LABK,LCBR,LBRC,LPRN,                         RPRN,RBRC,RCBR,RABK,BSLS,
  //     `----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----'
                         LALT,LCMD,    ,LSFT,     CDEL,    ,SENT,ABSP
  //                    `----+----+----+----'    `----+----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.                        ,----+----+----+----+----+----.
         , F1 , F2 , F3 , F4 , F5 ,                          F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|                        |----+----+----+----+----+----|
         ,LTOG,LMOF,LVAI,LHUI,LSAI,                         LEFT,DOWN, UP ,RGHT,    ,F12 ,
  //`----+----+----+----+----+----|                        |----+----+----+----+----+----'
          LRST,LMOP,LVAD,LHUD,LSAD,                         HOME,PGDN,PGUP,END ,    ,
  //     `----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----+----'
                         LALT,LCMD,    ,LSFT,     CDEL,    ,SENT,ABSP
  //                    `----+----+----+----'    `----+----+----+----'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_LRST:
      if (record->event.pressed) {
#ifdef RGBLED_ENABLE
        eeconfig_update_rgbled_default();
        rgbled_enable();
#endif
      }
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    }
#ifdef OLED_DRIVER_ENABLE
    if (record->event.pressed) {
      kp = (kp + 1) % STEP;
    }
#endif
    return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

#ifdef OLED_DRIVER_ENABLE

const char *read_logo(void) {
  static char logo[] = {



     };
  return logo;
}

void oled_task_user(void) {
  static char layer_names[_NUM_OF_LAYERS][10] = {
    "Default",
    "Lower",
    "Raise",
    "Adjust"
  };
  if (!is_keyboard_master()) {
    static char logo[84] = { 0 };
    static char l1[] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0 };
    static char l2[] = { 0x95, 0x96, 0x97, 0x98, 0x99, 0 };
    static char l3[] = { 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0 };
    static char l4[] = { 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0 };
    snprintf(logo, 84,
             "Layer: %-8s%5s\n"
             "%-15s%s\n"
             "%-15s%s\n"
             "%-15d%s",
             layer_names[get_highest_layer(layer_state)], l1,
             "", l2,
             "", l3,
             kp, l4
             );
    oled_write(logo, false);
    //oled_write_P(layerStr, false);
  } else {
    static char logo[84] = { 0 };
    static char l1[] = { 0xa0, 0xa1, 0xa2, 0xa3, '\0' };
    static char l2[] = { 0xc0, 0xc1, 0xc2, 0xc3, '\0' };
    static char l3[] = { 0xaf, 0xb0, 0xb1, 0xb2, '\0' };
    static char l4[] = { 0xcf, 0xd0, 0xd1, 0xd2, '\0' };
    char *a, *b;
    if (kp < STEP/2) {
      a = l1;
      b = l2;
    } else {
      a = l3;
      b = l4;
    }
    int space = kp % STEP;
    if (space > STEP/2) space = STEP - space;
    switch (space) {
    case 0:
      snprintf(logo, 84,
               "Layer: %s\n\n"
               "                %s\n"
               "                %s",
               layer_names[get_highest_layer(layer_state)], a, b);
      break;
    case 1:
      snprintf(logo, 84,
               "Layer: %s\n\n"
               "               %s\n"
               "               %s\n",
               layer_names[get_highest_layer(layer_state)], a, b);
      break;
    case 2:
      snprintf(logo, 84,
               "Layer: %s\n\n"
               "              %s\n"
               "              %s\n",
               layer_names[get_highest_layer(layer_state)], a, b);
      break;
    case 3:
      snprintf(logo, 84,
               "Layer: %s\n\n"
               "             %s\n"
               "             %s\n",
               layer_names[get_highest_layer(layer_state)], a, b);
      break;
    case 4:
      snprintf(logo, 84,
               "Layer: %s\n\n"
               "            %s\n"
               "            %s\n",
               layer_names[get_highest_layer(layer_state)], a, b);
      break;
    case 5:
      snprintf(logo, 84,
               "Layer: %s\n\n"
               "           %s\n"
               "           %s\n",
               layer_names[get_highest_layer(layer_state)], a, b);
      break;
    case 6:
      snprintf(logo, 84,
               "Layer: %s\n\n"
               "          %s\n"
               "          %s\n",
               layer_names[get_highest_layer(layer_state)], a, b);
      break;
    case 7:
      snprintf(logo, 84,
               "Layer: %s\n\n"
               "         %s\n"
               "         %s\n",
               layer_names[get_highest_layer(layer_state)], a, b);
      break;
    case 8:
      snprintf(logo, 84,
               "Layer: %s\n\n"
               "        %s\n"
               "        %s\n",
               layer_names[get_highest_layer(layer_state)], a, b);
      break;
    case 9:
      snprintf(logo, 84,
               "Layer: %s\n\n"
               "       %s\n"
               "       %s\n",
               layer_names[get_highest_layer(layer_state)], a, b);
      break;
    case 10:
      snprintf(logo, 84,
               "Layer: %s\n\n"
               "      %s\n"
               "      %s\n",
               layer_names[get_highest_layer(layer_state)], a, b);
      break;
    case 11:
      snprintf(logo, 84,
               "Layer: %s\n\n"
               "     %s\n"
               "     %s\n",
               layer_names[get_highest_layer(layer_state)], a, b);
      break;
    case 12:
      snprintf(logo, 84,
               "Layer: %s\n\n"
               "    %s\n"
               "    %s\n",
               layer_names[get_highest_layer(layer_state)], a, b);
      break;
    case 13:
      snprintf(logo, 84,
               "Layer: %s\n\n"
               "   %s\n"
               "   %s\n",
               layer_names[get_highest_layer(layer_state)], a, b);
      break;
    case 14:
      snprintf(logo, 84,
               "Layer: %s\n\n"
               "  %s\n"
               "  %s\n",
               layer_names[get_highest_layer(layer_state)], a, b);
      break;
    case 15:
      snprintf(logo, 84,
               "Layer: %s\n\n"
               " %s\n"
               " %s\n",
               layer_names[get_highest_layer(layer_state)], a, b);
      break;
    case 16:
      snprintf(logo, 84,
               "Layer: %s\n\n"
               "%s\n"
               "%s\n",
               layer_names[get_highest_layer(layer_state)], a, b);
      break;
    }
    oled_write(logo, false);
  }
}
#endif
