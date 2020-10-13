#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM=HOST

#Platform Specific Flags
LINKER_FILE=msp432p401r.lds

ARM_FLAGS = -mcpu=cortex-m4 \
            -mthumb \
            -march=armv7e-m \
            -mfloat-abi=hard \
	    -mfpu=fpv4-sp-d16 \

# Compiler Flags and Defines 
COMMONFLAGS=-Wall -Werror -g -O0 -std=c99
CPPFLAGS=-MM
TARGET=c1m2

ifeq ($(PLATFORM),HOST)
  CC=gcc
  LD=
  PLATFORM_TARGET=HOST
  INCLUDES=-I$(INCLUDE_PATHS)
  CFLAGS=$(COMMONFLAGS) -v
  LDFLAGS=-Wl,-Map=$(TARGET).map
else
  CC =arm-none-eabi-gcc
  LD =arm-none-eabi-ld
  #LD=arm-none-eabi-ld
  INCLUDES=$(TARGET_INCLUDES)
  CFLAGS=$(ARM_FLAGS) -v
  LDFLAGS=-Wl,-Map=$(TARGET).map -T$(LINKER_FILE)
endif

OBJS:=$(SOURCES:.c=.o)
DEPS:=$(OBJS:.o=.d)

.PHONY: build
build: compile-link

.PHONY: compile-link
compile-link : $(TARGET).out

# MISSING---------------> size tool, hdwre
$(TARGET).out: $(OBJS)
	$(CC) $(INCLUDES) $(LD) -D$(PLATFORM_TARGET) $(CFLAGS) $(LDFLAGS) -o $@ $^

# MISSING -------------->  hdwre
.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(INCLUDES) -D$(PLATFORM_TARGET) $(CFLAGS) -c $^


%.i: %.c
	$(CC) $(INCLUDES) $(CFLAGS) -D$(PLATFORM_TARGET) -E $^ -o $@

# MISSING --------------> objdumpUtil
%.asm: %.c
	$(CC) $(INCLUDES) $(CFLAGS) -D$(PLATFORM_TARGET) -S $< -o $@

-include $(DEPS)
%.o: %.c
	$(CC) $(INCLUDES) $(CFLAGS) -D$(PLATFORM_TARGET) -c $^ -o $@
	$(CC) $(INCLUDES) $(CPPFLAGS) $(CFLAGS) -D$(PLATFORM_TARGET) $*.c > $*.d

.PHONY: clean
clean:
	rm -f *.map *.out *.o *.asm *.d *.i c1m2

