#
# Makefile for ppc64-diag/opal_errd/opal_elog_parse
#

include ../rules.mk

Q = @

ifeq ($(V),1)
Q = 
endif

CMDS = libelogparse.a

LDFLAGS += -static

CXXFLAGS += -I. -I../include -I../include/util

ELOG_PARSE_OBJS = errlmtms.o errlbase.o errlplugins.o  errlsrc.o \
                 errlsysmtms.o  errlud_tool.o    srciascstr.o \
                 srcimru.o      srcisrc.o      utilheap.o \
                 errlED.o      errlparse.o         errlprvt.o     errlsrc_tool.o  \
                 errlsysmtms_tool.o  errluh.o         srcicallout.o      srcimrusst.o  \
                 srcisubst.o    utilmem.o errlentry.o   errlparser.o  \
                 errlsctn.o     errlswerr.o     errltoolutils.o  \
                 errlusrparser.o  srcicalloutsctn.o  srcioptsctn.o \
                 srciutility.o  utilstream.o errlextduh.o  errlplugincenter.o  \
                 errlsctnhdr.o  errlswv2.o  errlud.o  errlxmlparser.o  \
                 srcifruidentity.o  srcipce.o      utilfile.o

all: $(CMDS)

libelogparse.a: $(ELOG_PARSE_OBJS)
	@echo "LD $(WORK_DIR)/$@"
	ar rvs $@ $(ELOG_PARSE_OBJS)

$(ELOG_PARSE_OBJS): %.o: %.C 
	$(Q)@echo "$(CC) $(CXXFLAGS) $(WORK_DIR)/$@"
	$(Q)$(CC) $(CXXFLAGS) -c -o $@ $<

clean:
	@echo "Cleaning up $(WORK_DIR) files..."
	$(Q)rm -rf $(CMDS) $(ELOG_PARSE_OBJS)
