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
SUBDIRS = elog-parse plugins
SUBDIRS_WP = elog-parse

CMDS = errl_p8 errl errl_wp

#LIBPATHS += -L./elog-parse -L./plugins/fspplugins -L./plugins/hbplugins -L./plugins/hbplugins/prdf
#LIBPATHS_P8 += -L./elog-parse -L./plugins/fspplugins -L./plugins_p8/hbplugins -L./plugins_p8/hbplugins/prdf
LIBPATHS += -L./elog-parse -L./plugins/hbplugins -L./plugins/hbplugins/prdf
LIBPATHS_P8 += -L./elog-parse
LIBPATHS_WP += -L./elog-parse

#LDLIBS += -lfspplugins -lhbplugins -lhbprdfplugins -lelogparse
LDLIBS += -lhbplugins -lelogparse
LDLIBS_WP += -lelogparse

ifeq ($(ARCH),AIX)
	LDLIBS += -lpopt
	LDLIBS_WP += -lpopt
	LDRULE += $(LDLIBS)
	LDRULE_WP += $(LDLIBS_WP)
else
	LDRULE += -Wl,-whole-archive $(LDLIBS) -Wl,-no-whole-archive
	LDRULE_WP += -Wl,-whole-archive $(LDLIBS_WP) -Wl,-no-whole-archive
endif

CXXFLAGS += -I. -I./include -I./include/util 

ERRL_OBJS = errl.o

#all: deps errl errl_p8
all: deps errl

without_plugins: deps_wp errl_wp

deps:	
	@echo "Building elog-parse..."
	@$(MAKE) -C elog-parse
#	@echo "Building p8 plugins..."
#	@$(MAKE) -C plugins_p8
	@echo "Building p9 plugins..."
	@$(MAKE) -C plugins

deps_wp:
	@echo "Building elog-parse..."
	@$(MAKE) -C elog-parse


errl_p8:errl.C
	$(Q)@echo "Building $(WORK_DIR)/$@"
	$(CC) $(CXXFLAGS) $< $(LIBPATHS_P8) $(LDRULE) -o $@

errl:errl.C
	$(Q)@echo "Building $(WORK_DIR)/$@"
	$(CC) $(CXXFLAGS) $< $(LIBPATHS) $(LDRULE) -o $@

errl_wp:errl.C
	$(Q)@echo "Building $(WORK_DIR)/$@"
	$(CC) $(CXXFLAGS) $< $(LIBPATHS_WP) $(LDRULE_WP) -o $@

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

clobber_all_wp:
	$(Q)@echo "Cleaning up $(WORK_DIR) files..."
	@$(foreach d,$(SUBDIRS_WP), $(MAKE) -C $d clean;)
	$(Q)rm -rf $(CMDS) $(ERRL_OBJS)
