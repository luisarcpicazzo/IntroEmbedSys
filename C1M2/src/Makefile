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
            -mthumb \
            -march=armv7e-m \
            -mfloat-abi=hard \
            -mfpu=fpv4-sp-d16 \ 
            --specs=nosys.specs

# Compiler Flags and Defines 
COMMONFLAGS = -Wall -Werror -g -O0 -std=c99
CPPFLAGS  = -MMD -MF
TARGET = c1m2

ifeq ($(PLATFORM),HOST)
  CC = gcc
  PLATFORM_TARGET = HOST 
  INCLUDES = $(COMMON_INCLUDES)
  CFLAGS = $(COMMONFLAGS)
  LDFLAGS =-Wl,-Map=$(TARGET).map
else
  CC = arm-none-eabi-gcc
  LD = arm-none-eabi-ld
  PLATFORM_TARGET = MSP432
  INCLUDES = -I$(TARGET_INCLUDES)
  CFLAGS = $(COMMONFLAGS) $(ARM_FLAGS)
  LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
endif

#OBJS = $(SOURCES:.c=.o)

.PHONY: build
build: compile-link

.PHONY: compile-link
compile-link : $(TARGET).out

# Compile all object files and link into a final executable.
# MISSING size tool
#$(TARGET).out :       # $(OBJS)
#	$(CC) -D $(PLATFORM_TARGET) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -Map$(TARGET).map $^ -o $@

$(TARGET).out: $(SOURCES)
	$(CC) -D$(PLATFORM_TARGET) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(SOURCES) $(INCLUDES) 

# Compile all object files, but DO NOT link.  
# $make compile-all
#.PHONY: compile-all
#compile-all : $(SOURCES) $(INCLUDES)  
#	$(CC) -D $(PLATFORM_TARGET) $(CFLAGS) -c


#%.i : %.c $(INCLUDES)
#	$(CC) $(CFLAGS) $(CPPFLAGS) -E $^ -o $@


#%.asm : %.o
#	$(CC) $(CFLAGS) $(CPPFLAGS) objdump -S $< -o $@



#%.o : %.c %.d $(INCLUDES)
#	$(CC) $(CFLAGS) -c $^ -o $@ 


#%.d : %.c $(INCLUDES)
#	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^ -o $@



.PHONY: clean
clean:
	rm -f *.map *.out *.o *.asm *.d *.i c1m2

