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

# Compiler Flags and Defines 
COMMONFLAGS = -Wall -Werror -g -O0 -std=99
TARGET = c1m2

ifeq($(PLATFORM), HOST)
  CC = gcc
  PLATFORM_TARGET = HOST
  INCLUDE_FILES = -I $(COMMON_INCLUDES)
  CPPFLAGS = -D$(PLATFORM_TARGET)
  CFLAGS = $(COMMONFLAGS)
  LDFLAGS = -Wl
else
  CC = arm-none-eabi-gcc
  LD = arm-none-eabi-ld
  PLATFORM_TARGET = MSP432
  INCLUDE_FILES = -I $(COMMON_INCLUDES) $(TARGET_INCLUDES)
  CPPFLAGS = -D$(PLATFORM_TARGET)
  CFLAGS = -mcpu=cortex-m4 -mthumb -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs
  LDFLAGS = -Wl -T$(LINKER_FILE)
endif

OBJS = $(SOURCES:.c=.o)


### TO DO: Dependency Files .d files
### TO DO: Indvidual Object files .o files

.PHONY: build
build: compile-link

.PHONY: compile-link
compile-link : $(TARGET).out

$(TARGET).out : $(SOURCES)
	#Compile all object files and link into a final executable.
	  # MISSING size tool
	$(CC) $(CPPFLAGS) $(CFLAGS) -Map$(TARGET).map -o $@


.PHONY: compile-all
compile-all : $(SOURCES) 
	#Compile all object files, but DO NOT link.  
	  # $ make compile-all
	$(CC)-c


%.i : %.c
	#Generate preprocessed output of all c-program implementation files (use -E flag).
	  #You can do this by providing a single target name:
	  # $ make main.i
	$(CC) -E $< $(CFLAGS) $(INCLUDE_FILES) $(CPPFLAGS) -o $@


%.asm : %.c
	#Generate assembly output of c-program implementation files and the final output exectuatable
	  #(use the -S flag and the objdump utility).
	  #You can do this by providing a single target name:
	  # $ make main.asm
	$(CC) -S $< -o $@ $(CFLAGS) #apply obj_dump_util


%.o : %.c
        #Generate the object fiel for all c-source files (but do not link) by specifying the object file
	  #you want to compile
	  # $ make main.o
	$(CC) -c $< $(CFLAGS) -o $@
	

.PHONY: clean
clean:
	#This should remove all compiled objects, preprocessed outputs, assembly outputs, executable files
	  #and build output files.
	#Needs to have .PHONY protection.
	#This includes but is not limited to .map, .out, .o, .asm, .i etc.
	  # $ make clean



