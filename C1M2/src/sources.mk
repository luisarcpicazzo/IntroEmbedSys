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

#Include Paths:
INC_DFLT=../include/common
INC_MSP432=../include/msp432
INC_CMSIS=../include/CMSIS

# Source files and headers (swtch compile)
ifeq ($(PLATFORM),HOST)
  SOURCES = main.c \
	    memory.c
  INCLUDE_PATHS=$(INC_DFLT)
else
  SOURCES = main.c \
	    memory.c \
	    startup_msp432p401r_gcc.c \
	    system_msp432p401r.c \
	    interrupts_msp432p401r_gcc.c
  INCLUDE_PATHS=$(INC_DFLT) \
		$(INC_MSP432) \
		$(INC_CMSIS) \
endif


