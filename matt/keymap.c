/*
	Created by Matt Hartley on 06/11/2025.
	Copyright 2025 GiantJelly. All rights reserved.
*/

/*
	Keyboard mappings for MacOS keybindings
	on Linux and Windows
*/

#include QMK_KEYBOARD_H
#include "os_detection.h"


#ifdef CONSOLE_ENABLE
#	define debugf(...) uprintf(__VA_ARGS__)
#else
#	define debugf(...) 
#endif

// enum {
// 	OS_UNSURE,
// 	OS_LINUX,
// 	OS_WINDOWS,
// 	OS_MACOS,
// 	OS_IOS,
// } os_variant_t;

enum led_indices {
	LED_ESC = 0,
	LED_MODE = 13,
};

enum custom_keycodes {
	KC_MODE = NEW_SAFE_RANGE,
	KC_FAKEALT,
	KC_FAKESUPER,
};


enum layers{
	MAC_BASE,
	MAC_FN,
	WIN_BASE,
	WIN_FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAC_BASE] = LAYOUT_tkl_iso(
	KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,           /*KC_SNAP*/KC_MODE,   KC_SIRI,  RGB_MOD,
	KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, KC_INS,    KC_HOME,  KC_PGUP,
	KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,           KC_DEL,    KC_END,   KC_PGDN,
	KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,
	KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,            KC_UP,
	KC_LCTL,  KC_FAKEALT, KC_FAKESUPER,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN, MO(MAC_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[MAC_FN] = LAYOUT_tkl_iso(
	KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,             KC_TRNS,  KC_TRNS,  RGB_TOG,
	KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
	RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
	KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
	KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
	KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[WIN_BASE] = LAYOUT_tkl_iso(
	KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,             KC_PSCR,   KC_CTANA, RGB_MOD,
	KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,    KC_HOME,  KC_PGUP,
	KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,            KC_DEL,    KC_END,   KC_PGDN,
	KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,
	KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,             KC_UP,
	KC_LCTL,  KC_LALT,  KC_LGUI,                                KC_SPC,                                 KC_LGUI,  KC_RALT, MO(WIN_FN),KC_RGUI,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[WIN_FN] = LAYOUT_tkl_iso(
	KC_TRNS,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,            KC_TRNS,  KC_TRNS,  RGB_TOG,
	KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
	RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
	KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
	KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
	KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS)
};


bool remapMode = false;
uint8_t currentMods;

char* GetKeycodeString(uint16_t keycode)
{
	switch (keycode) {
		case KC_LCTL: return "KC_LCTL";
		case KC_LGUI: return "KC_LGUI";
		case KC_LALT: return "KC_LALT";
		case KC_LOPTN: return "KC_LOPTN";
		case KC_LCMMD: return "KC_LCMMD";
		case KC_SPACE: return "KC_SPACE";
		case KC_BACKSPACE: return "KC_BACKSPACE";
		case KC_ESC: return "KC_ESC";
		case KC_LEFT: return "KC_LEFT";
		case KC_RIGHT: return "KC_RIGHT";
		case KC_UP: return "KC_UP";
		case KC_DOWN: return "KC_DOWN";
		default: return "UNKNOWN";
	}
}

void AltShortcut(uint16_t mod, uint16_t keycode)
{
	set_mods((currentMods & MOD_BIT(KC_LSFT)) | MOD_BIT(mod));
	tap_code(keycode);
	set_mods(currentMods);
	send_keyboard_report();
	// toggle ctrl so OS doesn't think alt was pressed alone
	register_code(KC_LCTL);
	unregister_code(KC_LCTL);
}

void AltNumberShortcut(uint16_t keycode)
{
	clear_mods();
	register_mods(MOD_BIT(KC_RALT));
	tap_code(keycode);
	unregister_mods(MOD_BIT(KC_RALT));
	set_mods(currentMods);
	send_keyboard_report();
	// toggle ctrl so OS doesn't think alt was pressed alone
	register_code(KC_LCTL);
	unregister_code(KC_LCTL);
}

bool fakeAltIsDown = false;
bool superIsDown = false;

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
	currentMods = get_mods();
	// bool superDown = get_mods() & MOD_BIT(KC_LCTL);
	// bool altDown = get_mods() & MOD_BIT(KC_LALT);
	// os_variant_t os = detected_host_os();
	bool pressed = record->event.pressed;

	debugf("%s\t%s\n", GetKeycodeString(keycode), record->event.pressed ? "pressed" : "released");

	if (keycode == KC_MODE && record->event.pressed) {
		remapMode = !remapMode;
		return false;
	}
	
	if (/*os != OS_MACOS*/ remapMode) {
		// Swap super and ctrl
		if (keycode == KC_FAKESUPER) {
			superIsDown = pressed;
			if (pressed) {
				register_code(KC_LCTL);
			} else {
				unregister_code(KC_LCTL);
				unregister_code(KC_HOME);
				unregister_code(KC_END);
			}
			return false;
		}

		if (keycode == KC_LCTL) {
			if (record->event.pressed) {
				register_code(KC_LGUI);
			} else {
				unregister_code(KC_LGUI);
			}
			return false;
		}

		if (keycode == KC_FAKEALT) {
			fakeAltIsDown = record->event.pressed;
			// if (!pressed) {
			// 	unregister_code(KC_LCTL);
			// }
			if (pressed) {
				register_code(KC_LALT);
			} else {
				unregister_code(KC_LALT);
				if (!superIsDown) {
					unregister_code(KC_LCTL);
				}
			}
			return false;
		}

		if (keycode == KC_ROPTN) {
			if (pressed) {
				register_code(KC_LALT);
			} else {
				unregister_code(KC_LALT);
			}
			return false;
		}

		switch (keycode) {
			case KC_LEFT:
				if (superIsDown) {
					if (pressed) {
						del_mods(MOD_BIT(KC_LCTL));
						register_code(KC_HOME);
					} else {
						unregister_code(KC_HOME);
						add_mods(MOD_BIT(KC_LCTL));
					}
					return false;
				}
				if (fakeAltIsDown) {
					if (pressed) {
						del_mods(MOD_BIT(KC_LALT));
						add_mods(MOD_BIT(KC_LCTL));
					} else {
						del_mods(MOD_BIT(KC_LCTL));
						add_mods(MOD_BIT(KC_LALT));
					}
					return true; // continue normal key event
				}
				break;

			case KC_RIGHT:
				if (superIsDown) {
					if (pressed) {
						del_mods(MOD_BIT(KC_LCTL));
						register_code(KC_END);
					} else {
						unregister_code(KC_END);
						add_mods(MOD_BIT(KC_LCTL));
					}
					return false;
				}
				if (fakeAltIsDown) {
					if (pressed) {
						del_mods(MOD_BIT(KC_LALT));
                        add_mods(MOD_BIT(KC_LCTL));
					} else {
						del_mods(MOD_BIT(KC_LCTL));
						add_mods(MOD_BIT(KC_LALT));
					}
					return true; // continue normal key event
				}
				break;

			case KC_UP:
				if (superIsDown && !fakeAltIsDown && pressed) {
					tap_code(KC_HOME);
					return false;
				}
				break;

			case KC_DOWN:
				if (superIsDown && !fakeAltIsDown && pressed) {
					// if (fakeAltIsDown) {
					// 	tap_code16(A(KC_DOWN));
					// } else {
					// 	tap_code(KC_END);
					// }
					tap_code(KC_END);
					return false;
				}
				break;

			case KC_BACKSPACE:
				if (fakeAltIsDown) {
					if (pressed) {
						register_code(KC_LCTL);
						register_code(KC_BACKSPACE);
					} else {
						unregister_code(KC_BACKSPACE);
						unregister_code(KC_LCTL);
					}
					return false;
				}
				break;

			case KC_DEL:
				if (fakeAltIsDown) {
					if (pressed) {
						register_code(KC_LCTL);
						register_code(KC_DEL);
					} else {
						unregister_code(KC_DEL);
						unregister_code(KC_LCTL);
					}
					return false;
				}
				break;

			case KC_2:
				if (fakeAltIsDown) {
					if (pressed) {
						register_code(KC_RALT);
						register_code(KC_2);
					} else {
						unregister_code(KC_2);
						unregister_code(KC_RALT);
					}
					return false;
				}
				break;

			case KC_3:
				if (fakeAltIsDown) {
					if (pressed) {
						register_code(KC_RALT);
						register_code(KC_3);
					} else {
						unregister_code(KC_3);
						unregister_code(KC_RALT);
					}
					return false;
				}
				break;

            default:
		}

		if (superIsDown && record->event.pressed) {
			// if (superDown) {
				switch (keycode) {
					// Home/End shortcuts
					// case KC_LEFT:
					// 	if (superDown) {
					// 		// unregister_mods(MOD_BIT(KC_LCTL));
					// 		// unregister_code(KC_LCTL);
					// 		uint8_t mods = get_mods();
					// 		del_mods(mods);
					// 		register_code(KC_HOME);
					// 		set_mods(mods);
					// 		// register_code(KC_LCTL);
					// 		// register_mods(MOD_BIT(KC_LCTL));
					// 		return false;
					// 	}
					// 	break;
					// case KC_RIGHT:
					// 	if (superDown && !fakeAltIsDown) {
					// 		// unregister_mods(MOD_BIT(KC_LCTL));
					// 		unregister_code(KC_LCTL);
					// 		tap_code(KC_END);
					// 		register_code(KC_LCTL);
					// 		// register_mods(MOD_BIT(KC_LCTL));
					// 		return false;
					// 	}
					// 	break;

					// Jump Top/Bottom shortcuts
					// case KC_UP:
					// 	if (superDown && !fakeAltIsDown) {
					// 		tap_code(KC_HOME);
					// 		return false;
					// 	}
					// case KC_DOWN:
					// 	// unregister_mods(MOD_BIT(KC_LCMD));
					// 	// register_mods(MOD_BIT(KC_LCTL));
					// 	// unregister_mods(MOD_BIT(KC_LCTL));
					// 	// register_mods(MOD_BIT(KC_LCMD));
					// 	if (superDown) {
					// 		tap_code(KC_END);
					// 		return false;
					// 	}

					// Alt-Tab shortcut
					case KC_TAB:
						// if (superDown) {
							unregister_mods(MOD_BIT(KC_LCTL));
							register_mods(MOD_BIT(KC_LALT));
							tap_code(KC_TAB);
							unregister_mods(MOD_BIT(KC_LALT));
							register_mods(MOD_BIT(KC_LCTL));
							return false;
						// }
						break;

					// Delete line shortcuts
					case KC_BACKSPACE:
						// unregister_mods(MOD_BIT(KC_LCMD));
						// register_mods(MOD_BIT(KC_LCTL));
						// tap_code(KC_U);
						// unregister_mods(MOD_BIT(KC_LCTL));
						// register_mods(MOD_BIT(KC_LCMD));

						// if (superDown) {
							set_mods(MOD_BIT(KC_LSFT));
							tap_code(KC_HOME);
							tap_code(KC_HOME);
							tap_code(KC_BACKSPACE);
							set_mods(currentMods);
							send_keyboard_report();
							return false;
						// }
						break;

					case KC_DEL:
						// if (superDown) {
							set_mods(MOD_BIT(KC_LSFT));
							tap_code(KC_END);
							tap_code(KC_END);
							tap_code(KC_DEL);
							set_mods(currentMods);
							send_keyboard_report();
							return false;
						// }
						break;
				}
			// }

			// Word move shortcuts
			// if (altDown) {
			// 	switch (keycode) {
			// 		case KC_LEFT:
			// 			AltShortcut(KC_LCTL, KC_LEFT);
			// 			return false;

			// 		case KC_RIGHT:
			// 			AltShortcut(KC_LCTL, KC_RIGHT);
			// 			return false;

			// 		// Delete word shortcuts
			// 		case KC_BACKSPACE:
			// 			AltShortcut(KC_LCTL, KC_BACKSPACE);
			// 			return false;

			// 		case KC_DEL:
			// 			AltShortcut(KC_LCTL, KC_DEL);
			// 			return false;

			// 		// Number shortcuts
			// 		case KC_1:
			// 			AltNumberShortcut(KC_1);
			// 			return false;
			// 		case KC_2:
			// 			AltNumberShortcut(KC_2);
			// 			return false;
			// 		case KC_3:
			// 			AltNumberShortcut(KC_3);
			// 			return false;
			// 		case KC_4:
			// 			AltNumberShortcut(KC_4);
			// 			return false;
			// 		case KC_5:
			// 			AltNumberShortcut(KC_5);
			// 			return false;
			// 		case KC_6:
			// 			AltNumberShortcut(KC_6);
			// 			return false;
			// 		case KC_7:
			// 			AltNumberShortcut(KC_7);
			// 			return false;
			// 		case KC_8:
			// 			AltNumberShortcut(KC_8);
			// 			return false;
			// 		case KC_9:
			// 			AltNumberShortcut(KC_9);
			// 			return false;
			// 		case KC_0:
			// 			AltNumberShortcut(KC_0);
			// 			return false;
			// 	}
			// }
		}
	} else {
		// Normal Mac mode
		if (keycode == KC_FAKESUPER) {
			if (pressed) {
				register_code(KC_LGUI);
			} else {
				unregister_code(KC_LGUI);
			}
			return false;
		}

		if (keycode == KC_FAKEALT) {
			if (record->event.pressed) {
				register_code(KC_LALT);
			} else {
				unregister_code(KC_LALT);
			}
			return false;
		}
	}

	return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t* record)
{
	debugf("\t%s\t%s\n", GetKeycodeString(keycode), record->event.pressed ? "pressed" : "released");
}

bool rgb_matrix_indicators_advanced_user(uint8_t ledMin, uint8_t ledMax)
{
	os_variant_t os = detected_host_os();

	if (os == OS_MACOS) {
		rgb_matrix_set_color(LED_ESC, 0, 0, 255);
	} else {
		rgb_matrix_set_color(LED_ESC, 0, 255, 0);
	}

	if (remapMode) {
		rgb_matrix_set_color(LED_MODE, 0, 255, 0);
	} else {
		rgb_matrix_set_color(LED_MODE, 255, 0, 0);
	}

	return false;
}
