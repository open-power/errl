#
# Makefile for ppc64-diag/opal_errd/opal_elog_parse
#

include ../../rules.mk

Q = @

ifeq ($(V),1)
Q = @
endif

SUBDIRS = prdf

CMDS = libhbplugins.a

LDFLAGS += -static

CXXFLAGS += -D__HOSTBOOT_MODULE -DLOGPARSER -I. -I../ -I../targeting -I../../include -I../../include/util -I../../include/extras -I../../include/genfiles

HB_PLUGIN_OBJS = EEPROM_COMP_ID_Parse.o hbfwSrcParse19.o hbfwSrcParse25.o  \
                 hbfwSrcParse7.o I2C_COMP_ID_Parse.o ERRL_COMP_ID_Parse.o \
                 hbfwSrcParse1A.o  hbfwSrcParse26.o  hbfwSrcParse8.o \
                 INITSVC_COMP_ID_Parse.o  RUNTIME_COMP_ID_Parse.o FSI_COMP_ID_Parse.o  hbfwSrcParse1B.o  \
                 hbfwSrcParse27.o   MBOX_COMP_ID_Parse.o  \
                 hbfwSrcParse10.o hbfwSrcParse1C.o hbfwSrcParse9.o \
                 hbfwSrcParse11.o hbfwSrcParse1D.o  \
                 hbfwSrcParse2.o hbfwSrcParseA.o symbols.o hbfwSrcParse12.o  hbfwSrcParse1E.o   \
                 hbfwSrcParseB.o  VPD_COMP_ID_Parse.o hbfwSrcParse13.o \
                 hbfwSrcParse1F.o  hbfwSrcParseC.o \
                 hbfwSrcParse14.o hbfwSrcParse1.o hbfwSrcParse3.o  \
                 hbfwSrcParseD.o hbfwSrcParse16.o  hbfwSrcParse22.o  \
                 hbfwSrcParse4.o   hbfwSrcParseE.o \
                 hbfwSrcParse17.o  hbfwSrcParse23.o  hbfwSrcParse5.o   hbfwSrcParseF.o \
                 hbfwSrcParse18.o  hbfwSrcParse24.o  hbfwSrcParse6.o   HWPF_COMP_ID_Parse.o 

all: $(CMDS)
	@$(MAKE) -C prdf

libhbplugins.a: $(HB_PLUGIN_OBJS) 
	@echo "LD $(WORK_DIR)/$@"
	ar rvs $@ $(HB_PLUGIN_OBJS)

$(HB_PLUGIN_OBJS):%.o: %.C 
	$(Q)@echo "$(CC) $(CXXFLAGS) $(WORK_DIR)/$@"
	$(Q)$(CC) $(CXXFLAGS) -c $<

clean:
	@echo "Cleaning up $(WORK_DIR) files..."
	$(Q)rm -rf $(CMDS) $(HB_PLUGIN_OBJS) 
	@$(foreach d,$(SUBDIRS), $(MAKE) -C $d clean;)
