#
# Makefile for ppc64-diag/opal_errd/opal_elog_parse
#

include rules.mk

Q = @

ifeq ($(V),1)
Q = 
endif

ARCH = $(shell uname)

#SUBDIRS = elog-parse plugins plugins_p8
SUBDIRS = elog-parse

CMDS = errl_p8 errl

#LIBPATHS += -L./elog-parse -L./plugins/fspplugins -L./plugins/hbplugins -L./plugins/hbplugins/prdf
#LIBPATHS_P8 += -L./elog-parse -L./plugins/fspplugins -L./plugins_p8/hbplugins -L./plugins_p8/hbplugins/prdf
LIBPATHS += -L./elog-parse
LIBPATHS_P8 += -L./elog-parse

LDLIBS += -lelogparse

ifeq ($(ARCH),AIX)
	LDLIBS += -lpopt
	LDRULE += $(LDLIBS)
else
	LDRULE += -Wl,-whole-archive $(LDLIBS) -Wl,-no-whole-archive
endif

CXXFLAGS += -I. -I./include -I./include/util 

ERRL_OBJS = errl.o

all: deps errl errl_p8

deps:	
	@echo "Building elog-parse..."
	@$(MAKE) -C elog-parse
	@echo "Building p8 plugins..."
#	@$(MAKE) -C plugins_p8
	@echo "Building p9 plugins..."
#	@$(MAKE) -C plugins

errl_p8:errl.C
	$(Q)@echo "Building $(WORK_DIR)/$@"
	$(CC) $(CXXFLAGS) $< $(LIBPATHS_P8) $(LDRULE) -o $@

errl:errl.C
	$(Q)@echo "Building $(WORK_DIR)/$@"
	$(CC) $(CXXFLAGS) $< $(LIBPATHS) $(LDRULE) -o $@

$(ERRL_OBJS):%.o: %.c %.h
	$(Q)@echo "CC $(WORK_DIR)/$@"
	$(Q)$(CC) $(CFLAGS) -c $<

clean:
	$(Q)@echo "Cleaning up errl executable files..."
	$(Q)rm -rf $(CMDS) $(ERRL_OBJS)

clobber_all:
	$(Q)@echo "Cleaning up $(WORK_DIR) files..."
	@$(foreach d,$(SUBDIRS), $(MAKE) -C $d clean;)
	$(Q)rm -rf $(CMDS) $(ERRL_OBJS)
