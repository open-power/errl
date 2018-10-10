#
# Makefile for ppc64-diag/opal_errd/opal_elog_parse
#

include ../../rules.mk

Q = @

ifeq ($(V),1)
Q = 
endif

SUBDIRS =

CMDS = libfspplugins.a

LDFLAGS += -static

CXXFLAGS += -D_X86NFP -DPARSER -I. -I../ -I../targeting -I../../include -I../../include/util -I../../include/extras -I../../include/genfiles

FSP_PLUGIN_OBJS = occcDataParse.o  occcSrcParse.o   tmgtLogParse.o   tmgtSrcParse.o   tmgtutility.o powrVrmTelemetryParser.o powrLogParse.o  powrProcParse.o  powrSrcParse.o

all: $(CMDS)

libfspplugins.a: $(FSP_PLUGIN_OBJS)
	@echo "LD $(WORK_DIR)/$@"
	ar rvs $@ $(FSP_PLUGIN_OBJS)

$(FSP_PLUGIN_OBJS):%.o: %.C 
	$(Q)@echo "$(CC) $(CXXFLAGS) $(WORK_DIR)/$@"
	$(Q)$(CC) $(CXXFLAGS) -c $<

clean:
	@echo "Cleaning up $(WORK_DIR) files..."
	$(Q)rm -rf $(CMDS) $(FSP_PLUGIN_OBJS)
	@$(foreach d,$(SUBDIRS), $(MAKE) -C $d clean;)
