#
# Test Makefile for Mizar32
#

# Change this to 0 show compiler invocation lines by default:
QUIET ?= 0

# Comment this out to disable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
#~ DEVELHELP ?= 1

APPLICATION = mizar32_test
BOARD ?= mizar32
RIOTBASE ?= /home/marcus/avr32/code/RIOT
FLASHFILE = $(APPLICATION).bin

PART = uc3a0512
AVR32_ARCH = ucr2
LDFLAGS = --gc-sections --direct-data -nostartfiles -mpart=$(PART) -T$(LDSCRIPT)
#-nodefaultlibs -nostartfiles
LDSCRIPT = $(RIOTBASE)/cpu/avr32/ldscripts/link_uc3a0512.lds

PATH_AVR32_INCLUDE = /home/marcus/avr32/as4e-ide/plugins/com.atmel.avr.toolchains.linux.x86_3.0.0.201009140852/os/linux/x86/avr32/include/

#~ CC ?= avr32-gcc
#~ CXX ?= avr32-g++
#~ LD = avr32-ld
#~ CCAS = avr32-as
#~ OBJCOPY = avr32-objcopy

#CFLAGS += -D__STDC_NO_ATOMICS__

CFLAGS += -Wl,-nodefaultlibs
CFLAGS += -Os
CFLAGS += -ggdb
CFLAGS += -std=c99
CFLAGS += -mpart=$(PART)
CFLAGS += -march=$(AVR32_ARCH)
CFLAGS += -msoft-float
CFLAGS += -muse-rodata-section
CFLAGS += -fdata-sections
CFLAGS += -ffunction-sections
#~ #CFLAGS +=
CFLAGS += -I$(PATH_AVR32_INCLUDE)
CFLAGS += -I/home/marcus/avr32/code/mizar32_riot/src

#~ #CFLAGS += -I/usr/include/x86_64-linux-gnu/

OPTIONAL_CFLAGS_BLACKLIST += -fdiagnostics-color
OPTIONAL_CFLAGS_BLACKLIST += -Wformat-overflow
OPTIONAL_CFLAGS_BLACKLIST += -Wformat-truncation
OPTIONAL_CFLAGS_BLACKLIST += -gz

dump:
	avr32-objdump -x -d -g bin/$(BOARD)/$(APPLICATION).elf | less

include $(RIOTBASE)/Makefile.include
