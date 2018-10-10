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

PRDF_PLUGIN_OBJS = prdfBitString.o        prdrErrlPluginsSupt.o p9_capp.prf.err.o \
                   p9_eq.prf.err.o   p9_mca.prf.err.o      p9_mcs.prf.err.o \
                   p9_obus.prf.err.o   p9_phb.prf.err.o    prdfLogParse.o \
                   p9_capp.prf.reg.o   p9_eq.prf.reg.o   p9_mca.prf.reg.o \
                   p9_mcs.prf.reg.o      p9_obus.prf.reg.o   p9_phb.prf.reg.o \
                   prdfLogParse_common.o prdfMemLogParse.o p9_ec.prf.err.o \
                   p9_ex.prf.err.o   p9_mcbist.prf.err.o   p9_nimbus.prf.err.o \
                   p9_pec.prf.err.o    p9_xbus.prf.err.o   prdfParserUtils.o \
                   p9_ec.prf.reg.o     p9_ex.prf.reg.o   p9_mcbist.prf.reg.o \
                   p9_nimbus.prf.reg.o   p9_pec.prf.reg.o    p9_xbus.prf.reg.o   prdfProcLogParse.o


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
