#
# Makefile for ppc64-diag/opal_errd/opal_elog_parse
#

include ../../../rules.mk

Q =

ifndef V
Q = @
else
ifeq ($(V),0)
Q = @
endif
endif

CMDS = libhbprdfplugins.a

LDFLAGS += -static

CXXFLAGS += -DPRDF_HOSTBOOT_ERRL_PLUGIN -D__HOSTBOOT_MODULE -DLOGPARSER -DPRDPARSER -I. -I../.. -I../../targeting -I../../../include -I../../../include/util -I../../../include/extras -I../../../include/genfiles

PRDF_PLUGIN_OBJS = prdrErrlPluginsSupt.o  \
                   Ex.prf.err.o  Mba.prf.err.o  Mcs.prf.err.o  Membuf.prf.err.o  MuranoVeniceProc.prf.err.o \
                   NaplesProc.prf.err.o  prdfCenLogParse.o  prdfLogParse_common.o  prdfProcLogParse.o \
                   Ex.prf.reg.o  Mba.prf.reg.o  Mcs.prf.reg.o  Membuf.prf.reg.o  MuranoVeniceProc.prf.reg.o  NaplesProc.prf.reg.o \
                   prdfLogParse.o     prdfParserUtils.o     

all: $(CMDS)

libhbprdfplugins.a: $(PRDF_PLUGIN_OBJS)
	@echo "LD $(WORK_DIR)/$@"
	ar rvs $@ $(PRDF_PLUGIN_OBJS)

$(PRDF_PLUGIN_OBJS):%.o: %.C
	@echo "$(CC) $(CXXFLAGS) $(WORK_DIR)/$@"
	$(Q)$(CC) $(CXXFLAGS) -c $<

clean:
	@echo "Cleaning up $(WORK_DIR) files..."
	$(Q)rm -rf $(CMDS) $(PRDF_PLUGIN_OBJS)
