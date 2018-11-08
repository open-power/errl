#
# Makefile for ppc64-diag/opal_errd/opal_elog_parse
#

include ../rules.mk

Q =

ifndef V
Q = @
else
ifeq ($(V),0)
Q = @
endif
endif

#SUBDIRS = hbplugins fspplugins
SUBDIRS = hbplugins

all: 
	@echo "Building hbplugins..."
	@$(MAKE) -C hbplugins
#	@$(MAKE) -C fspplugins

clean:
	@echo "Cleaning up $(WORK_DIR) files..."
	@$(foreach d,$(SUBDIRS), $(MAKE) -C $d clean;)
