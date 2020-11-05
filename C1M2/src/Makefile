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
# Makefile for cross compilation host(linux) & target(cortex-M4 msp432)
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

# Platform Specific Flags
LINKER_FILE=../msp432p401r.lds

ARM_FLAGS=-mcpu=cortex-m4\
          -mthumb\
		  -march=armv7e-m\
		  -mfloat-abi=hard\
		  -mfpu=fpv4-sp-d16\
		  --specs=nosys.specs

# Compiler Flags and Defines 
COMMONFLAGS=-Wall -Werror -g -O0 -std=c99
CPPFLAGS=-MM
TARGET=c1m2

ifneq ($(PLATFORM),MSP432)  # Default to HOST if no MSP432 passed
  CC=gcc
  SZTUL_SZFGS=size --format=gnu
  LD=
  PLATFORM_TARGET=HOST
  INCLUDES=-I$(INCLUDE_PATHS)
  CFLAGS=$(COMMONFLAGS) -v
  LDFLAGS=-Wl,-Map=$(TARGET).map
  OBJ_DUMP=objdump
else                        # Build for target MSP432
  CC=arm-none-eabi-gcc
  LD=arm-none-eabi-ld
  SZTUL_SZFGS=arm-none-eabi-size --format=gnu
  PLATFORM_TARGET=MSP432
  INCLUDES=-I$(INCLUDE_PATHS)
  CFLAGS=$(COMMONFLAGS) $(ARM_FLAGS) -v
  LDFLAGS=-Wl,-Map=$(TARGET).map -T$(LINKER_FILE)
  OBJ_DUMP=arm-none-eabi-objdump
endif

OBJS:=$(SOURCES:.c=.o)
DEPS:=$(OBJS:.o=.d)

.PHONY: build
build: compile-link

.PHONY: compile-link
compile-link : $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(INCLUDES) -D$(PLATFORM_TARGET) $(CFLAGS) $(LDFLAGS) -o $@ $^
	$(SZTUL_SZFGS) $^                  # Print report to shell.
	$(SZTUL_SZFGS) $^ > $*.size        # Output size report.


.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(INCLUDES) -D$(PLATFORM_TARGET) $(CFLAGS) -c $^

%.i: %.c
	$(CC) $(INCLUDES) $(CFLAGS) -D$(PLATFORM_TARGET) -E $^ -o $@


%.asm: %.c %.o
	$(CC) $(INCLUDES) $(CFLAGS) -D$(PLATFORM_TARGET) -S $< -o $@
	$(OBJ_DUMP) --disassemble $*.o > $*.dump  # Output disassembly to "myfile".dump


-include $(DEPS)
%.o: %.c
	$(CC) $(INCLUDES) $(CFLAGS) -D$(PLATFORM_TARGET) -c $^ -o $@
	$(CC) $(INCLUDES) $(CPPFLAGS) $(CFLAGS) -D$(PLATFORM_TARGET) $*.c > $*.d


.PHONY: clean
clean:
	rm -r -f *.map *.out *.o *.asm *.d *.i *.txt *.dump *.size

