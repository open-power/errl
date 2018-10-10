#ifndef ERRLHASHTABLES_H
#define ERRLHASHTABLES_H

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlutility.H>
#include <errllang.H>
#include <srci.H>
#include <epub_service_codes.H>

/*****************************************************************************/
// Constants
/*****************************************************************************/
#define ERRL_INT_ACTION_SOFTWARE_ERROR 0x0080
#define ERRL_INT_ACTION_HARDWARE_ERROR 0x0040

/*****************************************************************************/
// Static Tables
/*****************************************************************************/
HASH_ITEM_TABLE( EventType )
    {   0,				    ERRL_MSG_EVENT_TYPE },
    {   ERRL_ETYPE_NOT_APPLICABLE,	    ERRL_MSG_ETYPE_NOT_APPLICABLE },
    {   ERRL_ETYPE_MISCELLANEOUS,	    ERRL_MSG_ETYPE_MISCELLANEOUS },
    {   ERRL_ETYPE_TRACING,		    ERRL_MSG_ETYPE_TRACING},
    {   ERRL_ETYPE_DUMP_NOTIFICATION,	    ERRL_MSG_ETYPE_DUMP_NOTIFICATION },
    {   ERRL_ETYPE_ERROR_CORRECTED,	    ERRL_MSG_ETYPE_PREVIOUS_ERROR },
    {   ERRL_ETYPE_USER_DECONFIG,	    ERRL_MSG_ETYPE_SYSTEM_RESOURCES },
    {   ERRL_ETYPE_SYS_DECONFIG,	    ERRL_MSG_ETYPE_SYS_DECONFIG },
    {   ERRL_ETYPE_DECONFIG_NOTE,	    ERRL_MSG_ETYPE_DECONFIG_NOTE },
    {   ERRL_ETYPE_ENVIRONMENT_NORMAL,	    ERRL_MSG_ETYPE_CUSTOMER_ENV },
    {   ERRL_ETYPE_CONCURRENT_MAINTENANCE,  ERRL_MSG_ETYPE_CONCURRENT_MAIN },
    {   ERRL_ETYPE_CAPACITY_UPGRADE,	    ERRL_MSG_ETYPE_CAPACITY_UP },
    {   ERRL_ETYPE_RESOURCE_SPARING,	    ERRL_MSG_ETYPE_RESOURCES_SPAR },
    {   ERRL_ETYPE_DYNAMIC_RECONFIG,	    ERRL_MSG_ETYPE_RUNTIME_DECON },
    {   ERRL_ETYPE_NORMAL_SHUTDOWN,	    ERRL_MSG_ETYPE_NORMAL_PO },
    {   ERRL_ETYPE_DIRTY_SHUTDOWN,	    ERRL_MSG_ETYPE_PLATFORM_PO }
HASH_TABLE_END( EventType )


HASH_ITEM_TABLE( SrciPriority )
    {   0,			ERRL_MSG_PRIORITY },
    {   SRCI_PRIORITY_HIGH,	ERRL_MSG_PRIORITY_MANDATORY },
    {   SRCI_PRIORITY_MED,	ERRL_MSG_PRIORITY_MEDIUM },
    {   SRCI_PRIORITY_MEDA,	ERRL_MSG_PRIORITY_MEDIUM_A },
    {   SRCI_PRIORITY_MEDB,	ERRL_MSG_PRIORITY_MEDIUM_B },
    {   SRCI_PRIORITY_MEDC,	ERRL_MSG_PRIORITY_MEDIUM_C },
    {   SRCI_PRIORITY_LOW,	ERRL_MSG_PRIORITY_LOWEST }
HASH_TABLE_END( SrciPriority )


HASH_FLAG_TABLE( ErrlAction )
    {	0,				ERRL_MSG_ACTION_FLAGS	    },
    {	ERRL_ACTION_REPORT,		ERRL_MSG_ACTION_REPORT	    },
    {	ERRL_ACTION_SA,			ERRL_MSG_ACTION_SA	    },
    {	ERRL_ACTION_HIDDEN,		ERRL_MSG_ACTION_HIDDEN	    },
    {	ERRL_ACTION_REPORT_HMC_ONLY,	ERRL_MSG_ACTION_HMC_ONLY    },
    {	ERRL_ACTION_CALL_HOME,		ERRL_MSG_ACTION_CALLHOME    },
    {	ERRL_ACTION_SP_CALL_HOME,	ERRL_MSG_ACTION_SPCALLHOME  },
    {	ERRL_ACTION_FNM_REQ,		ERRL_MSG_ACTION_ERROR_ISO   },
    {	ERRL_INT_ACTION_SOFTWARE_ERROR,	ERRL_MSG_ACTION_SOFT_OS400  },
    {	ERRL_INT_ACTION_HARDWARE_ERROR,	ERRL_MSG_ACTION_HARD_OS400  }
HASH_TABLE_END( ErrlAction )

HASH_ITEM_TABLE( ErrlSev )
    {	0,				    ERRL_MSG_EVENT_SEVERITY },
    {	ERRL_SEV_INFORMATIONAL,		    ERRL_MSG_SEV_INFO	    },
    {	ERRL_SEV_RECOVERED,		    ERRL_MSG_SEV_RECOV	    },
    {	ERRL_SEV_PREDICTIVE,		    ERRL_MSG_SEV_PRED	    },
    {	ERRL_SEV_PREDICTIVE_DEGRADED,	    ERRL_MSG_SEV_PRED_DEG   },
    {	ERRL_SEV_PREDICTIVE_CORRECTABLE,    ERRL_MSG_SEV_PRED_CORR  },
    {	ERRL_SEV_PREDICTIVE_CORRECTABLE2,   ERRL_MSG_SEV_PRED_CORR2 },
    {	ERRL_SEV_PREDICTIVE_REDUNDANCY_LOST,ERRL_MSG_SEV_REDUN	    },
    {	ERRL_SEV_UNRECOVERABLE,		    ERRL_MSG_SEV_UNREC	    },
    {	ERRL_SEV_UNRECOVERABLE1,	    ERRL_MSG_SEV_UNREC1	    },
    {	ERRL_SEV_UNRECOVERABLE2,	    ERRL_MSG_SEV_UNREC2	    },
    {	ERRL_SEV_UNRECOVERABLE3,	    ERRL_MSG_SEV_UNREC3	    },
    {	ERRL_SEV_UNRECOVERABLE4,	    ERRL_MSG_SEV_UNREC4	    },
    {   ERRL_SEV_CRITICAL_FAIL_UNKNOWN,     ERRL_MSG_SEV_CRIT_FUKNWN},
    {	ERRL_SEV_CRITICAL_SYS_TERM,	    ERRL_MSG_SEV_CRIT_STERM },
    {	ERRL_SEV_CRITICAL_SYS_FAIL,	    ERRL_MSG_SEV_CRIT_SFAIL },
    {	ERRL_SEV_CRITICAL_PART_TERM,	    ERRL_MSG_SEV_CRIT_PTERM },
    {	ERRL_SEV_CRITICAL_PART_FAIL,	    ERRL_MSG_SEV_CRIT_PFAIL },
    {	ERRL_SEV_DIAGNOSTIC_ERROR1,	    ERRL_MSG_SEV_DIAG_ERR1  },
    {	ERRL_SEV_DIAGNOSTIC_ERROR2,	    ERRL_MSG_SEV_DIAG_ERR2  },
    {   ERRL_SEV_SYMPTOM_RECOVERED,         ERRL_MSG_SEV_SYMP_RECOV },
    {   ERRL_SEV_SYMPTOM_PREDICTIVE,        ERRL_MSG_SEV_SYMP_PRED  },
    {   ERRL_SEV_SYMPTOM_UNRECOV,           ERRL_MSG_SEV_SYMP_UNREC },	
    {   ERRL_SEV_SYMPTOM_DIAGERR,           ERRL_MSG_SEV_SYMP_DGERR }
HASH_TABLE_END( ErrlSev )

HASH_ITEM_TABLE( ErrlSubSys )
    {   0,                                          ERRL_MSG_FAILING_SUBSYSTEM      },
    {   EPUB_RESERVED_0,                            ERRL_MSG_EPUB_RESERVED_0        },
    {   EPUB_PROCESSOR_SUBSYS,                      ERRL_MSG_EPUB_PROCESSOR_SUBSYS  },
    {   EPUB_PROCESSOR_FRU,                         ERRL_MSG_EPUB_PROCESSOR_FRU     },
    {   EPUB_PROCESSOR_CHIP_CACHE,                  ERRL_MSG_EPUB_PROCESSOR_CHIP_CACHE  },
    {   EPUB_PROCESSOR_UNIT,                        ERRL_MSG_EPUB_PROCESSOR_UNIT    },
    {   EPUB_PROCESSOR_BUS_CTL,                     ERRL_MSG_EPUB_PROCESSOR_BUS_CTL },
    {   EPUB_MEMORY_SUBSYS,                         ERRL_MSG_EPUB_MEMORY_SUBSYS     },
    {   EPUB_MEMORY_CONTROLLER,                     ERRL_MSG_EPUB_MEMORY_CONTROLLER },
    {   EPUB_MEMORY_BUS,                            ERRL_MSG_EPUB_MEMORY_BUS        },
    {   EPUB_MEMORY_DIMM,                           ERRL_MSG_EPUB_MEMORY_DIMM       },
    {   EPUB_MEMORY_FRU,                            ERRL_MSG_EPUB_MEMORY_FRU        },
    {   EPUB_EXTERNAL_CACHE,                        ERRL_MSG_EPUB_EXTERNAL_CACHE    },
    {   EPUB_IO_SUBSYS,                             ERRL_MSG_EPUB_IO_SUBSYS         },
    {   EPUB_IO_HUB,                                ERRL_MSG_EPUB_IO_HUB            },
    {   EPUB_IO_BRIDGE,                             ERRL_MSG_EPUB_IO_BRIDGE         },
    {   EPUB_IO_BUS_INTF,                           ERRL_MSG_EPUB_IO_BUS_INTF       },
    {   EPUB_IO_PROCESSOR,                          ERRL_MSG_EPUB_IO_PROCESSOR      },
    {   EPUB_IO_SMA_HUB,                            ERRL_MSG_EPUB_IO_SMA_HUB        },
    {   EPUB_IO_RIO_LOOP_WITH_HUB,                  ERRL_MSG_EPUB_IO_RIO_LOOP_HUB   },
    {   EPUB_IO_RIO_LOOP_WITH_BRIDGE,               ERRL_MSG_EPUB_IO_RIO_LOOP_BRG   },
    {   EPUB_IO_PHB,                                ERRL_MSG_EPUB_IO_PHB            },
    {   EPUB_IO_EADS_SUBSYS,                        ERRL_MSG_EPUB_IO_EADS_SUBSYS    },
    {   EPUB_IO_EADS_SLOT,                          ERRL_MSG_EPUB_IO_EADS_SLOT      },
    {   EPUB_IO_INFINIBAND_HUB,                     ERRL_MSG_EPUB_IO_INFI_HUB       },
    {   EPUB_IO_INFINIBAND_BRIDGE,                  ERRL_MSG_EPUB_IO_INFI_BRG       },
    {   EPUB_IO_ADAPTER_SUBSYS,                     ERRL_MSG_EPUB_IO_ADAPTER_SUBSYS },
    {   EPUB_IO_ADAPTER_COMM,                       ERRL_MSG_EPUB_IO_ADAPTER_COMM   },
    {   EPUB_IO_DEVICE_SUBSYS,                      ERRL_MSG_EPUB_IO_DEVICE_SUBSYS      },
    {   EPUB_IO_DEVICE_DASD,                        ERRL_MSG_EPUB_IO_DEVICE_DASD            },
    {   EPUB_IO_EXT_PERIPH_SUBSYS,                  ERRL_MSG_EPUB_IO_EXT_PERIPH_SUBSYS  },
    {   EPUB_IO_EXT_PERIPH_LCLWKST,                 ERRL_MSG_EPUB_IO_EXT_PERIPH_LCLWKST },
    {   EPUB_CEC_HDW_SUBSYS,                        ERRL_MSG_EPUB_CEC_HDW_SUBSYS            },
    {   EPUB_CEC_HDW_SRV_PROC_A,                    ERRL_MSG_EPUB_CEC_HDW_SRV_PROC_A        },
    {   EPUB_CEC_HDW_SRV_PROC_B,                    ERRL_MSG_EPUB_CEC_HDW_SRV_PROC_B        },
    {   EPUB_CEC_HDW_NODE_CTLR,                     ERRL_MSG_EPUB_CEC_HDW_NODE_CTLR        },
    {   EPUB_CEC_HDW_VPD_INTF,                      ERRL_MSG_EPUB_CEC_HDW_VPD_INTF      },
    {   EPUB_CEC_HDW_I2C_DEVS,                      ERRL_MSG_EPUB_CEC_HDW_I2C_DEVS      },
    {   EPUB_CEC_HDW_CHIP_INTF,                     ERRL_MSG_EPUB_CEC_HDW_CHIP_INTF     },           //ri02
    {   EPUB_CEC_HDW_JTAG,                          ERRL_MSG_EPUB_CEC_HDW_JTAG  },                   //ri02
    {   EPUB_CEC_HDW_CLK_CTL,                       ERRL_MSG_EPUB_CEC_HDW_CLK_CTL       },
    {   EPUB_CEC_HDW_OP_PANEL,                      ERRL_MSG_EPUB_CEC_HDW_OP_PANEL      },
    {   EPUB_CEC_HDW_TOD_HDW,                       ERRL_MSG_EPUB_CEC_HDW_TOD_HDW       },
    {   EPUB_CEC_HDW_SRV_PROC_MEM,                  ERRL_MSG_EPUB_CEC_HDW_SRV_PROC_MEM  },
    {   EPUB_CEC_HDW_SP_PHYP_INTF,                  ERRL_MSG_EPUB_CEC_HDW_SP_PHYP_INTF  },
    {   EPUB_CEC_HDW_SERV_NETWORK,                  ERRL_MSG_EPUB_CEC_HDW_SERV_NETWORK },
    {   EPUB_CEC_HDW_RFSP,                          ERRL_MSG_EPUB_CEC_HDW_RFSP          },
    {   EPUB_POWER_SUBSYS,                          ERRL_MSG_EPUB_POWER_SUBSYS  },
    {   EPUB_POWER_SUPPLY,                          ERRL_MSG_EPUB_POWER_SUPPLY  },
    {   EPUB_POWER_CTL_HDW,                         ERRL_MSG_EPUB_POWER_CTL_HDW },
    {   EPUB_POWER_FAN,                             ERRL_MSG_EPUB_POWER_FAN     },
    {   EPUB_MISC_SUBSYS,                           ERRL_MSG_EPUB_MISC_SUBSYS   },
    {   EPUB_MISC_HMC_HDW,                          ERRL_MSG_EPUB_MISC_HMC_HDW  },
    {   EPUB_MISC_TEST_TOOL,                        ERRL_MSG_EPUB_MISC_TEST_TOOL            },
    {   EPUB_MISC_REM_MEDIA,                        ERRL_MSG_EPUB_MISC_REM_MEDIA            },
    {   EPUB_MISC_MULTIPLE_SUBSYS,                  ERRL_MSG_EPUB_MISC_MULTIPLE_SUBSYS  },
    {   EPUB_MISC_UNKNOWN,                          ERRL_MSG_EPUB_MISC_UNKNOWN  },
    {   EPUB_MISC_INFORMATIONAL,                    ERRL_MSG_EPUB_MISC_INFORMATIONAL        },
    {   EPUB_MISC_SURV_ERR_PHYP_LOST_COMM_SP,       ERRL_MSG_EPUB_SURV_PHYP_SP      },
    {   EPUB_MISC_SURV_ERR_SP_LOST_COMM_PHYP,       ERRL_MSG_EPUB_SURV_SP_PHYP      },
    {   EPUB_MISC_SURV_ERR_SP_LOST_COMM_HMC,        ERRL_MSG_EPUB_SURV_SP_HMC       },
    {   EPUB_MISC_SURV_ERR_HMC_LOST_COMM_PARTITION, ERRL_MSG_EPUB_SURV_HMC_PART },
    {   EPUB_MISC_SURV_ERR_HMC_LOST_COMM_BPA,       ERRL_MSG_EPUB_SURV_HMC_BPA      },
    {   EPUB_MISC_SURV_ERR_HMC_LOST_COMM_OTHER_HMC, ERRL_MSG_EPUB_SURV_HMC_HMC  },
    {   EPUB_FIRMWARE_SUBSYS,                       ERRL_MSG_EPUB_FIRMWARE_SUBSYS       },
    {   EPUB_FIRMWARE_SP,                           ERRL_MSG_EPUB_FIRMWARE_SP   },
    {   EPUB_FIRMWARE_PHYP,                         ERRL_MSG_EPUB_FIRMWARE_PHYP },
    {   EPUB_FIRMWARE_PARTITION,                    ERRL_MSG_EPUB_FIRMWARE_PARTITION        },
    {   EPUB_FIRMWARE_SLIC,                         ERRL_MSG_EPUB_FIRMWARE_SLIC },
    {   EPUB_FIRMWARE_SPCN,                         ERRL_MSG_EPUB_FIRMWARE_SPCN },
    {   EPUB_FIRMWARE_BULK_PWR,                     ERRL_MSG_EPUB_FIRMWARE_BULK_PWR     },
    {   EPUB_FIRMWARE_HMC,                          ERRL_MSG_EPUB_FIRMWARE_HMC  },
    {   EPUB_FIRMWARE_HOSTBOOT,                     ERRL_MSG_EPUB_FIRMWARE_HOSTBOOT        },                   
    {   EPUB_FIRMWARE_OCC,                          ERRL_MSG_EPUB_FIRMWARE_OCC        },                        
    {   EPUB_SOFTWARE_SUBSYS,                       ERRL_MSG_EPUB_SOFTWARE_SUBSYS       },
    {   EPUB_SOFTWARE_OS,                           ERRL_MSG_EPUB_SOFTWARE_OS   },
    {   EPUB_SOFTWARE_XPF,                          ERRL_MSG_EPUB_SOFTWARE_XPF  },
    {   EPUB_SOFTWARE_APPS,                         ERRL_MSG_EPUB_SOFTWARE_APPS },
    {   EPUB_EXT_ENVIRO_SUBSYS,                     ERRL_MSG_EPUB_EXT_ENVIRO_SUBSYS     },
    {   EPUB_EXT_ENVIRO_AC_PWR,                     ERRL_MSG_EPUB_EXT_ENVIRO_AC_PWR     },
    {   EPUB_EXT_ENVIRO_TEMP,                       ERRL_MSG_EPUB_EXT_ENVIRO_TEMP       },
    {   EPUB_EXT_ENVIRO_USER,                       ERRL_MSG_EPUB_EXT_ENVIRO_USER       },
    {   EPUB_IO_MEZZA_EXP_SUBSYS,                   ERRL_MSG_EPUB_IO_MEZZA_EXP_SUBSYS  },                     
    {   EPUB_FIRMWARE_DPSS,                         ERRL_MSG_EPUB_FIRMWARE_DPSS }                              
HASH_TABLE_END( ErrlSubSys )

HASH_FLAG_TABLE( TermState )
    { 0,			    ERRL_MSG_ERR_STS_FLAGS	},
    { SRCI_TERM_HW_CHECKSTOP,	    ERRL_MSG_HW_CHECKSTOP	},
    { SRCI_TERM_STATE_SOFT,	    ERRL_MSG_FIRMWARE_TERM	},
    { SRCI_ESF_FLAG_MFG,	    ERRL_MSG_MANUFACTURING_POL  },
    { SRCI_TERM_STATE_LOWRES,	    ERRL_MSG_IPL_TERM		},
    { SRCI_ESF_FLAG_DECON,	    ERRL_MSG_RES_DECONFIG	},
    { SRCI_ESF_FLAG_GARD,	    ERRL_MSG_RES_GARDED		}
HASH_TABLE_END( TermState )


HASH_FLAG_TABLE( ClockState )
    {	0,			    ERRL_MSG_CLK_STATE		    },
    {	SRCI_CS_IO_BRIDGE_DOMAIN,   ERRL_MSG_IO_BRG_CLK		    },
    {	SRCI_CS_PROCESSOR_CLOCK,    ERRL_MSG_PROC_CLKS_START	    },
    {	SRCI_CS_IO_CLOCKS,	    ERRL_MSG_IO_CLKS_START	    },
    {	SRCI_CS_MAINSTORE_CLOCK,    ERRL_MSG_MAINSTORE_CLKS_START   }
HASH_TABLE_END( ClockState )


HASH_ITEM_TABLE( LogState )
    {   0,			    ERRL_MSG_STATE		    },
    {   ERRL_STATE_READY,	    ERRL_MSG_STATE_READY	    },
    {   ERRL_STATE_NONE,	    ERRL_MSG_STATE_NONE		    },
    {   ERRL_STATE_COMMITTED,	    ERRL_MSG_STATE_COMMITTED	    },
    {   ERRL_STATE_PROCESSED,	    ERRL_MSG_STATE_PROCESSED	    },
    {   ERRL_STATE_DONE,	    ERRL_MSG_STATE_DONE		    },
    {   ERRL_STATE_SENT,	    ERRL_MSG_STATE_SENT		    },
    {   ERRL_STATE_RECEIVED,	    ERRL_MSG_STATE_RECEIVED	    },
    {   ERRL_STATE_PHYP_NOTIFIED,   ERRL_MSG_STATE_PHYP_NOTIFIED    },
    {   ERRL_STATE_REPORTED,	    ERRL_MSG_STATE_REPORTED	    },
    {   ERRL_STATE_NO_OS_REPORTED,  ERRL_MSG_STATE_NO_OS_REPORTED   }
HASH_TABLE_END( LogState )



#endif //ERRLHASHTABLES_H
