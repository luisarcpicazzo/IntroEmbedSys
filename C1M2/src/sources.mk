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
 
COMMON_DIR = ../include/common
MSP432_DIR = ../include/msp432
CMSIS_DIR = ../include/CMSIS

# Add your Source files to this variable
SOURCES = main.c \
	  memory.c \
	  startup_msp432p401r_gcc.c \
	  system_msp432p401r.c \
	  interrupts_msp432p401r_gcc.c

# Add your include paths to this variable

COMMON_INCLUDES = $(COMMON_DIR)/memory.h \
	          $(COMMON_DIR)/platform.h

TARGET_INCLUDES = $(MSP432_DIR)/mspr432p401r.h \
	          $(MSP432_DIR)/msp_compatibility.h \
	          $(MSP432_DIR)/system_msp432p401r.h \
	          $(CMSIS_DIR)/cmsis_gcc.h \
                  $(CMSIS_DIR)/core_cm4.h \
                  $(CMSIS_DIR)/core_cmFunc.h \
                  $(CMSIS_DIR)/core_cmdInstr.h \
                  $(CMSIS_DIR)/core_cmSimd.h \
		  $(COMMON_INCLUDES)
