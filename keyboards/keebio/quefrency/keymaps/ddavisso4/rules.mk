# DEBUG
CONSOLE_ENABLE = no

# BACKLIGHT_ENABLE managed by keyboard rev
COMBO_ENABLE = yes
COMMAND_ENABLE = no
DEBOUNCE_TYPE = sym_eager_pk
DYNAMIC_TAPPING_TERM_ENABLE = yes
EXTRAKEY_ENABLE = yes
GRAVE_ESC_ENABLE = no
KEY_OVERRIDE_ENABLE = yes
LEADER_ENABLE = no
MAGIC_ENABLE = no
MOUSEKEY_ENABLE = no
MUSIC_ENABLE = no
QUANTUM_PAINTER_ENABLE = no
RAW_ENABLE = no
SEND_STRING_ENABLE = yes
SPACE_CADET_ENABLE = no
TAP_DANCE_ENABLE = no

ifeq ($(PLATFORM_KEY),avr)
# only relevant for AVR
	AVR_USE_MINIMAL_PRINTF = yes
	LTO_ENABLE = yes

# I want this disabled for rev2/3 to save space and enabled for rev6
# NOTE: this really isn't a function of CPU architecture
# but I couldn't find something better that was available
# when this file is evaluated to differentiate rev2/3 and rev6
	ENCODER_ENABLE = no

# technically could move this to global since I want it disabled for both rev2/3 and rev6 has it disabled by default
# but took a bit to understand and this is a nice little clue
	RGBLIGHT_ENABLE = no
endif

ifeq ($(PLATFORM_KEY),chibios)
# could leave this out since it is the default but the contrast verus avr section is useful
	ENCODER_ENABLE = yes
endif
