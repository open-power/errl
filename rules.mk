#
# Common Makefile definitions
#
PWD = $(shell echo `pwd`)

# Current build directory
WORK_DIR = $(patsubst /%,%,$(subst $(ROOT_DIR),,$(PWD)))
LIB_DIR = /usr/lib
INC_DIR = /usr/include

ARCH = $(shell uname)

ifeq ($(ARCH),AIX)
        CXXFLAGS += -qhalt=e -qrtti -qro -D_AIX
        CC = xlC
else
	CXXFLAGS += -Wall -Wno-write-strings
        CC = g++
endif

# You should always build with -Wall
CFLAGS += -Wall

# Uncomment this for debug builds
CFLAGS += -g -DDEBUG 

# Build with common directory included
CFLAGS += -I$(COMMON_DIR)

# Include ncurses directory
CFLAGS += -I $(INC_DIR)/ncurses

# Build with version string
AM_CFLAGS = -DVERSION='"$(VERSION)"'

# Uncomment this for debug builds
CXXFLAGS += -g -DDEBUG

# Build with version string
AM_CXXFLAGS = -DVERSION='"$(VERSION)"'


# Define "CLEAN" as rm plus any files defined in this file that
# the actual Makefile may not (or have to) know about
CLEAN = @echo "" 

# Default target for building object files
%.o: %.c
	@echo "CC $(WORK_DIR)/$@"
	@$(CC) -c $(AM_CFLAGS) $(CFLAGS) $(CPPFLAGS) $<


