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
PLATFORM = HOST

#Platform Specific Flags
LINKER_FILE = msp432p401r.lds
ARM_FLAGS = -mcpu=cortex-m4 \ 
            -mthumb -march=armv7e-m \
	    -mfloat-abi=hard \
	    -mfpu=fpv4-sp-d16 \ 
	    --specs=nosys.specs

# Compiler Flags and Defines 
COMMONFLAGS = -Wall -Werror -g -O0 -std=99
CPPFLAGS  = -MMD -MF
TARGET = c1m2

ifeq($(PLATFORM), HOST)
  CC = gcc
  PLATFORM_TARGET = HOST
  INCLUDE_FILES = -I $(COMMON_INCLUDES)
  CFLAGS = $(COMMONFLAGS)
  LDFLAGS = -Wl
else
  CC = arm-none-eabi-gcc
  LD = arm-none-eabi-ld
  PLATFORM_TARGET = MSP432
  INCLUDE_FILES = -I $(COMMON_INCLUDES) $(TARGET_INCLUDES)
  CFLAGS = $(COMMONFLAGS) $(ARM_FLAGS)
  LDFLAGS = -Wl -T$(LINKER_FILE)
endif

OBJS = $(SOURCES:.c=.o)

.PHONY: build
build: compile-link

.PHONY: compile-link
compile-link : $(TARGET).out

$(TARGET).out : $(OBJS)
	#Compile all object files and link into a final executable.
	  # MISSING size tool
	$(CC) -D $(PLATFORM_TARGET) $(CFLAGS) $(LDFLAGS) -Map$(TARGET).map $^ -o $@


.PHONY: compile-all
compile-all : $(SOURCES) $(INCLUDE_FILES)  
	#Compile all object files, but DO NOT link.  
	  # $ make compile-all
	$(CC) -D $(PLATFORM_TARGET) $(CFLAGS) -c $^


%.i : %.c $(INCLUDE_FILES)
	$(CC) $(CFLAGS) -E $^ -o $@



%.asm : %.o
	$(CC) objdump -S $< $(CFLAGS) $(CPPFLAGS) -o $@



$(OBJS) : %.o

%.o : %.c $(INCLUDE_FILES) %.d
	$(CC) $(CFLAGS) -c $^ -o $@ 




%.d : %.c $(INCLUDE_FILES)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^ -o $@



.PHONY: clean
clean:
	#This should remove all compiled objects, preprocessed outputs, assembly outputs, executable files
	  #and build output files.
	#Needs to have .PHONY protection.
	#This includes but is not limited to .map, .out, .o, .asm, .i etc.
	  # $ make clean



