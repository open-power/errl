const AttributeData g_FapiAttrs[] = {
	{
		"ATTR_ALL_MCS_IN_INTERLEAVING_GROUP",
		0x1f8d4c1,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_A_EREPAIR_THRESHOLD_FIELD",
		0xadbe8c6,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_A_EREPAIR_THRESHOLD_MNFG",
		0x7e45e1e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_BAD_DQ_BITMAP",
		0x6bd2a93,
		sizeof(uint8_t),
		{ 4, 10, 1, 1 }
	},
	{
		"ATTR_BOOT_FREQ_MHZ",
		0x7c49cfc,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_BOOT_VOLTAGE",
		0xf651d57,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_BRAZOS_RX_FIFO_OVERRIDE",
		0xce3dcbe,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CDIMM_VPD_MASTER_POWER_INTERCEPT",
		0xf09cb2a,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CDIMM_VPD_MASTER_POWER_SLOPE",
		0x2aec555,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CDIMM_VPD_MASTER_TOTAL_POWER_INTERCEPT",
		0xe2a2a2d,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CDIMM_VPD_MASTER_TOTAL_POWER_SLOPE",
		0x29bc8e6,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CDIMM_VPD_SUPPLIER_POWER_INTERCEPT",
		0x40e3f4d,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CDIMM_VPD_SUPPLIER_POWER_SLOPE",
		0x3dc3a5d,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CDIMM_VPD_SUPPLIER_TOTAL_POWER_INTERCEPT",
		0x5f490e4,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CDIMM_VPD_SUPPLIER_TOTAL_POWER_SLOPE",
		0x469b058,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CENTAUR_BLUEWATERFALL_NWELL_BROKEN_CHECK_FLAG",
		0xafe6981,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CENTAUR_EC_CHECK_L4_CACHE_ENABLE_UNKNOWN",
		0x99e4b59,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CENTAUR_EC_DD2_ENABLE_EXIT_POINT_1",
		0x2fc3789,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CENTAUR_EC_DD2_FIR_BIT_DEFN_CHANGES",
		0xf5499dd,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CENTAUR_EC_DISABLE_VDDR_DYNAMIC_VID",
		0xa14167f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CENTAUR_EC_ECID_CONTAINS_PORT_LOGIC_BAD_INDICATION",
		0x3e86f6e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CENTAUR_EC_ENABLE_NM_CHANGE_AFTER_SYNC",
		0x6955c94,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CENTAUR_EC_ENABLE_PAGE_MODE_FOR_RRQ",
		0x1a02c07,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CENTAUR_EC_ENABLE_RCE_WITH_OTHER_ERRORS_HW246685",
		0x126cd5b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CENTAUR_EC_ENABLE_ROW_HAMMER_FEATURE",
		0xa2ab603,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CENTAUR_EC_ENABLE_SAFEMODE_THROTTLE",
		0xb6b9e15,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CENTAUR_EC_ENABLE_SAFE_MODE_THROTTLE",
		0x3e97aaf,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CENTAUR_EC_ENABLE_TRACE_ARRAY_CLKSTOP_ON_XSTOP_FW624741",
		0x2b7b05d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CENTAUR_EC_ENABLE_TRACE_LCL_CLK_GATE_CTRL",
		0x588819f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CENTAUR_EC_HW217608_MBSPA_0_CMD_COMPLETE_ATTN_FIXED",
		0x6907ca9,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CENTAUR_EC_MCBIST_RANDOM_ADDRESS",
		0xc45344b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CENTAUR_EC_MCBIST_RANDOM_DATA_GEN",
		0x548e8dc,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CENTAUR_EC_MCBIST_TRAP_RESET",
		0xa1a6cc9,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CENTAUR_EC_MSS_CONTINUE_ON_DP18_PLL_LOCK_FAIL",
		0xb46400c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CENTAUR_EC_MSS_READ_PHASE_SELECT_RESET",
		0xd184539,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CENTAUR_EC_RDCLK_PR_UPDATE_HW236658_FIXED",
		0x36d9be3,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CENTAUR_EC_SCOM_PARITY_ERROR_HW244827_FIXED",
		0x382f724,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CENTAUR_EC_USE_FIRST_SUPPLIER_FOR_INVALID_MODULE_ID",
		0xfc02ad8,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CENTAUR_EC_WRITE_FIR_MASK_FEATURE",
		0x7ef345b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CEN_DQ_TO_DIMM_CONN_DQ",
		0x7814503,
		sizeof(uint8_t),
		{ 80, 1, 1, 1 }
	},
	{
		"ATTR_CEN_EC_THROTTLE_SYNC_POSSIBLE",
		0xf528d13,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_ADU_PBINIT_LAUNCH_BUG",
		0x01580be,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_AISS_SPECIAL_WAKEUP",
		0xa43b7af,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_BOOT_FREQ_LESS_PSAVE",
		0x1e3b28a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_CAPP_HANG_CONTROL_ON_SCOM",
		0x2296f72,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_CAPP_PROD",
		0x9023dd2,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_DUAL_CAPP_PRESENT",
		0x90c54af,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_ENABLE_IVE_PERFORMANCE_ORDERING",
		0x280f292,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_ENABLE_PCI_DMAR_OOO",
		0xd3f353e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_FBC_SERIAL_SCOM_C10_VER2",
		0x28aa220,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_FBC_SERIAL_SCOM_C8_VER2",
		0x007b199,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_FBC_SERIAL_SCOM_C8_VER3",
		0x1d243ef,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_FBC_SERIAL_SCOM_WE5_VER2",
		0x0e39485,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_FBC_UX_LOCAL_ARB_RR",
		0xa36f008,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_FBC_UX_SCOPE_ARB_LFSR_ON_STARVATION_ELSE_RR",
		0x7113edb,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_FBC_UX_SCOPE_ARB_RR",
		0x37acf31,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_HCA_BAR_SCOM_BUG",
		0x7f49515,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_HCA_SPLIT_HANG_CONTROL",
		0x28f3f1a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_HW_BUG_PBASLVRESET",
		0xc525231,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_HW_BUG_PIBSLVRESET",
		0x4187a39,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_HW_BUG_PLLINIT",
		0x3c46b63,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_HW_BUG_TOD_ERROR_MASK_NOT_WRITABLE",
		0xa76f828,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_IVRM_WINKLE_BUG",
		0xedb6964,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_LCTANK_PLL_VCO_BUG",
		0xe520884,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_MCD_HANG_RECOVERY_BUG",
		0x4fc54fa,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_MCS_ECC_BYPASS_DISABLE",
		0x7f7201f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_MCS_MURDD1_FIR_CONTROL",
		0xf07bf0c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_MCS_P8_DD2_FIR_CONTROL",
		0x58393d2,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_MCS_VENDD1_FIR_CONTROL",
		0xabb7347,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_MPIPL_AISS_WINKLE_ENTRY",
		0x3136bcb,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_NOT_SUPPORT_SBE_AUTO_START",
		0x72ac551,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_NOT_SUPPORT_SBE_CFAM_START",
		0x791c3c5,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_NV_PRESENT",
		0x6874897,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_NX_HANG_CONTROL_ON_SCOM",
		0xafc61b7,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_OCC_CE_FIR_DISABLE",
		0x6a24f74,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_OCC_DISABLE",
		0x2d82afe,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_PCBS_ERR_RESET",
		0xf4b51ec,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_PCI_NEST_FIR_ACTION2_PRESENT",
		0xfa92c05,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_RECAL_CTLE_ENABLE",
		0x59af544,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_RECAL_DDC_ENABLE",
		0xfa2018d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_RECAL_DFE_ENABLE",
		0x210b737,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_RESONANT_CLK_VALID",
		0x2851aa5,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_SECURE_IOVALID_PRESENT",
		0xcfeb598,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_SET_ABUS_PRBS_TAP_ID",
		0x178ca87,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_SET_LEGACY_NODE_ID_VALID_MBOX_BIT",
		0xcd2cff5,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_SINGLE_XBUS_PRESENT",
		0x3cd67a7,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_TA_A_T1_PRESENT",
		0x8354673,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_TA_PB_T1_PRESENT",
		0x834aa3d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_TEST1",
		0x17874c2,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_TEST2",
		0x45c55e0,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_TRACE_CONTROL_ON_SCOM",
		0x138c59c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_USE_POLLING_PROT",
		0x0b6d169,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_XBUS_DLL_SLOW_MURANO",
		0x0ccf93a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_XBUS_RESONANT_CLK_VALID",
		0x6d6ad8f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_FEATURE_ZCAL_OVERRIDE",
		0x17f27af,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_EC_PFET_POWEROFF_BUG",
		0x88523de,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_HAS_SBE",
		0x520b948,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_ID",
		0xca771ad,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_REGIONS_TO_ENABLE",
		0x94a3736,
		sizeof(uint64_t),
		{ 32, 1, 1, 1 }
	},
	{
		"ATTR_CHIP_UNIT_POS",
		0x07f067a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_CPM_INFLECTION_POINTS",
		0xa4ddd48,
		sizeof(uint32_t),
		{ 16, 1, 1, 1 }
	},
	{
		"ATTR_CPM_TURBO_BOOST_PERCENT",
		0xf509a3a,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_DCCAL_PLL_WORKAROUND",
		0x644b68b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_DISABLE_I2C_ACCESS",
		0x1ba20f5,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_DMI_DFE_OVERRIDE",
		0x1790e9f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_DMI_EREPAIR_THRESHOLD_FIELD",
		0xd60ce9a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_DMI_EREPAIR_THRESHOLD_MNFG",
		0xe4cf80f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_DMI_REFCLOCK_SWIZZLE",
		0xf52d45e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_DUMMY_SCRATCH_PLAT_INIT_UINT8",
		0x2588335,
		sizeof(uint8_t),
		{ 1, 3, 5, 1 }
	},
	{
		"ATTR_EC",
		0x76cb47d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_ECID",
		0xd52cc6a,
		sizeof(uint64_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_BUFFER_LATENCY",
		0x54f357a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_CA_PARITY",
		0x276668f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_CA_PARITY_ERROR_STATUS",
		0x6c58297,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_CA_PARITY_LATENCY",
		0x5fda47c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_CEN_DRV_IMP_CLK_SCHMOO",
		0x024ed24,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_CEN_DRV_IMP_CNTL_SCHMOO",
		0xd6610af,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_CEN_DRV_IMP_DQ_DQS",
		0x7277132,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_CEN_DRV_IMP_DQ_DQS_SCHMOO",
		0x4a0727d,
		sizeof(uint32_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_CEN_DRV_IMP_SPCKE_SCHMOO",
		0x7315179,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_CEN_RCV_IMP_DQ_DQS",
		0x5bd7acb,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_CEN_RCV_IMP_DQ_DQS_SCHMOO",
		0x31c47b1,
		sizeof(uint32_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_CEN_RD_VREF",
		0x4a4c635,
		sizeof(uint32_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_CEN_RD_VREF_SCHMOO",
		0xce62e73,
		sizeof(uint32_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_CEN_SLEW_RATE_ADDR_SCHMOO",
		0xddeb83f,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_CEN_SLEW_RATE_CLK_SCHMOO",
		0x1b8096c,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_CEN_SLEW_RATE_CNTL_SCHMOO",
		0x197c27f,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_CEN_SLEW_RATE_DQ_DQS",
		0x870766e,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_CEN_SLEW_RATE_DQ_DQS_SCHMOO",
		0x07d2234,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_CEN_SLEW_RATE_SPCKE_SCHMOO",
		0xbc96dcb,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_CRC_ERROR_CLEAR",
		0x11b8b55,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_CRC_WR_LATENCY",
		0xaede177,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_CS_CMD_LATENCY",
		0x336e081,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_CUSTOM_DIMM",
		0x0e7aead,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DATA_MASK",
		0x8ee11e8,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC00",
		0x0426577,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC01",
		0x7ad2734,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC02",
		0x6d9003b,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC03",
		0x46933df,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC04",
		0x39bb9ff,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC05",
		0x69bf91d,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC06_07",
		0x2f0fbd4,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC08",
		0xc2ab560,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC09",
		0xd883c41,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC10",
		0x23d0f2c,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC11",
		0x0494cda,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC12",
		0xf3d14cf,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC13",
		0xbbca7c1,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC14",
		0x429ee1f,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC15",
		0x60ebaef,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC_1x",
		0xe54ebbf,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC_2x",
		0x6409304,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC_3x",
		0x5250949,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC_4x",
		0x57316b4,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC_5x",
		0xab87656,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC_6x",
		0xeda2fed,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC_7x",
		0xd437a3d,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC_8x",
		0x7e52703,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC_9x",
		0x246db38,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC_Ax",
		0x1bc4976,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC_Bx",
		0x0246dcc,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_RANKS_CONFIGED",
		0x92db64b,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_RCD_CNTL_WORD_0_15",
		0xb86780f,
		sizeof(uint64_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_RCD_CNTL_WORD_X",
		0xc96b7a6,
		sizeof(uint64_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_RCD_IBT",
		0x6f1259f,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_RCD_MIRROR_MODE",
		0xd612805,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_SIZE",
		0x29d7669,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_DIMM_SPARE",
		0x5471c19,
		sizeof(uint8_t),
		{ 2, 2, 4, 1 }
	},
	{
		"ATTR_EFF_DIMM_TYPE",
		0xd9a7095,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_AL",
		0xc6c7925,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_ASR",
		0xee66445,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_BANKS",
		0x1a8aed4,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_BL",
		0xbc9fd3b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_CL",
		0x67723cd,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_COLS",
		0xf08e379,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_CWL",
		0x4711851,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_DENSITY",
		0x2fa4637,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_DLL_ENABLE",
		0x23d2b47,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_DLL_PPD",
		0x808fa81,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_DLL_RESET",
		0x5e9f75e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_GEN",
		0x7a9dc85,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_LPASR",
		0x1c53acd,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_OUTPUT_BUFFER",
		0x8992cb0,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_PASR",
		0x6fdecdf,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_RBT",
		0x3d9e0ec,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_ROWS",
		0xc1652e4,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_SRT",
		0xd1918af,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_TCCD_L",
		0x82e0f01,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_TDQS",
		0x0d25691,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_TFAW",
		0xd3f7bba,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_TM",
		0x93c13a6,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_TRAS",
		0x3e1f395,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_TRC",
		0x95eca66,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_TRCD",
		0xce88510,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_TRFC",
		0xce92930,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_TRFI",
		0x9a04d90,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_TRP",
		0xfcd1269,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_TRRD",
		0x8817f94,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_TRTP",
		0xa59764c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_TWTR",
		0x53ad0e8,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_WIDTH",
		0xe0d4e79,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_WR",
		0x24becd1,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_WRDDR4_VREF_SCHMOO",
		0x6452c9e,
		sizeof(uint32_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_WR_LVL_ENABLE",
		0x77322df,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_WR_VREF",
		0xe55b07b,
		sizeof(uint32_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_DRAM_WR_VREF_SCHMOO",
		0xccd93c0,
		sizeof(uint32_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_FINE_REFRESH_MODE",
		0x2b936b1,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_GEARDOWN_MODE",
		0x08212fe,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_IBM_TYPE",
		0x9618454,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_INT_VREF_MON",
		0xf51cdb9,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_LRDIMM_ADDITIONAL_CNTL_WORDS",
		0x36ec2c6,
		sizeof(uint64_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_LRDIMM_WORD_X",
		0x4463dc0,
		sizeof(uint64_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_MAX_POWERDOWN_MODE",
		0xe4d075d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_MEMCAL_INTERVAL",
		0x9a89c30,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_MPR_LOC",
		0x1247eb7,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_MPR_MODE",
		0xd541f48,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_MPR_PAGE",
		0xc9114ed,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_MPR_RD_FORMAT",
		0xdfbb6bc,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_NUM_DIES_PER_PACKAGE",
		0xf19b41c,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_NUM_DROPS_PER_PORT",
		0x8d89d40,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM",
		0xa0ffe42,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_NUM_PACKAGES_PER_RANK",
		0x8305498,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_NUM_RANKS_PER_DIMM",
		0x3d83337,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_ODT_INPUT_BUFF",
		0x7f1499b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_PER_DRAM_ACCESS",
		0x8564fa8,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_PRIMARY_RANK_GROUP0",
		0x89a0ee8,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_PRIMARY_RANK_GROUP1",
		0x8548560,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_PRIMARY_RANK_GROUP2",
		0xa256fc3,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_PRIMARY_RANK_GROUP3",
		0xda4a70c,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_QUATERNARY_RANK_GROUP0",
		0xb2f4d0e,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_QUATERNARY_RANK_GROUP1",
		0xa8d19de,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_QUATERNARY_RANK_GROUP2",
		0x72f1de7,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_QUATERNARY_RANK_GROUP3",
		0xdf5311f,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_RD_PREAMBLE",
		0x7380b3a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_RD_PREAMBLE_TRAIN",
		0x9437808,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_READ_DBI",
		0x2603112,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_RTT_PARK",
		0x81e407c,
		sizeof(uint8_t),
		{ 2, 2, 4, 1 }
	},
	{
		"ATTR_EFF_SCHMOO_ADDR_CMD_MIN_MARGIN",
		0xe1d2a90,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_SCHMOO_ADDR_MODE",
		0xfbda0fe,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_SCHMOO_DQS_CLK_MIN_MARGIN",
		0xa76dd9d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_SCHMOO_MODE",
		0x91d7136,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_SCHMOO_PARAM_VALID",
		0x384985b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_SCHMOO_RD_EYE_MIN_MARGIN",
		0x3a69cd0,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_SCHMOO_RD_GATE_MIN_MARGIN",
		0x7953864,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_SCHMOO_TEST_VALID",
		0x116cac3,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_SCHMOO_WR_EYE_MIN_MARGIN",
		0x1002327,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_SECONDARY_RANK_GROUP0",
		0x7b6886f,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_SECONDARY_RANK_GROUP1",
		0xe9225e8,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_SECONDARY_RANK_GROUP2",
		0x4c40d75,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_SECONDARY_RANK_GROUP3",
		0x68337ad,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_SELF_REF_ABORT",
		0x1f60d7f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_STACK_TYPE",
		0x28196da,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_EFF_TEMP_READOUT",
		0x8fa5111,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_TEMP_REF_MODE",
		0xe026042,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_TEMP_REF_RANGE",
		0x9b26500,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_TERTIARY_RANK_GROUP0",
		0x29290fb,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_TERTIARY_RANK_GROUP1",
		0x4534ff7,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_TERTIARY_RANK_GROUP2",
		0x00741a6,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_TERTIARY_RANK_GROUP3",
		0x3d67c81,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_EFF_WRITE_CRC",
		0x8082409,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_WRITE_DBI",
		0x4ddea38,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_WR_PREAMBLE",
		0x14b80a1,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EFF_ZQCAL_INTERVAL",
		0x6cb09a8,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EI_BUS_TX_LANE_INVERT",
		0x1ac193e,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EI_BUS_TX_MSBSWAP",
		0x926b407,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EXECUTION_PLATFORM",
		0x8aa85d5,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EX_GARD_BITS",
		0x7fe3369,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_EX_L2_SINGLE_MEMBER_ENABLE",
		0xd9c3cf7,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_FABRIC_CHIP_ID",
		0xa631e7e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_FABRIC_NODE_ID",
		0xe75987b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_FORCE_SKIP_SBE_MASTER_INTR_SERVICE",
		0xcf87615,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_FORCE_USE_SBE_SLAVE_SCAN_SERVICE",
		0xe4acb83,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_FREQ_A",
		0x244778d,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_FREQ_CORE",
		0xcd23d9e,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_FREQ_CORE_FLOOR",
		0x932ad70,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_FREQ_CORE_MAX",
		0xf3a2378,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_FREQ_CORE_NOMINAL",
		0xd042df2,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_FREQ_EXT_BIAS_DOWN",
		0xbfa070e,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_FREQ_EXT_BIAS_UP",
		0xafb3458,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_FREQ_MEM_REFCLOCK",
		0x24d5979,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_FREQ_PB",
		0x76c06c3,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_FREQ_PCIE",
		0x1d63d98,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_FREQ_PROC_REFCLOCK",
		0x9d1850e,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_FREQ_PROC_REFCLOCK_KHZ",
		0x137afe3,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_FREQ_X",
		0x3908b77,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_FSI_GP_REG_SCOM_ACCESS",
		0x2171f23,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_FUNCTIONAL",
		0xcaa52ad,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_I2C_SLAVE_ADDRESS",
		0x4e9285d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_IO_TRAINING_DLL_WORKAROUND",
		0x831feab,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_IO_TRAINING_SLS_WORKAROUND",
		0xb36896a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_ISDIMM_MBVPD_INDEX",
		0xb242e90,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_ISDIMM_POWER_CURVE_ALGORITHM_VERSION",
		0x5560289,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_IS_MPIPL",
		0x32ab761,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_IS_SIMULATION",
		0x5e8e617,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_L2_FORCE_R_T2_EPS",
		0xa14bbb4,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_L2_R_T0_EPS",
		0x04fbe20,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_L2_R_T1_EPS",
		0x5e93be1,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_L2_R_T2_EPS",
		0x4b97680,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_L2_W_EPS",
		0x250d7d8,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_L3_FORCE_R_T2_EPS",
		0x518c8ed,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_L3_R_T0_EPS",
		0x1867bfc,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_L3_R_T1_EPS",
		0x397b2f6,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_L3_R_T2_EPS",
		0x421f4dc,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_L3_W_EPS",
		0xaa22424,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_L4_BANK_DELETE_VPD",
		0xf34b9c5,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_LRDIMM_ADDITIONAL_CNTL_WORDS",
		0xaee7485,
		sizeof(uint64_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_LRDIMM_MR12_REG",
		0xa89cc6c,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_LRDIMM_RANK_MULT_MODE",
		0xb42c68a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MBA_DIMM",
		0x4f5f0b0,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MBA_PORT",
		0xe91fb12,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_ADDR_BANK",
		0x1fa2bfa,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_ADDR_INTER",
		0x4b2946b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_ADDR_MODES",
		0x31b6605,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_ADDR_NUM_COLS",
		0x139841b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_ADDR_NUM_ROWS",
		0x4080908,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_ADDR_RAND",
		0x59e95ec,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_ADDR_RANK",
		0x685360c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_ADDR_SLAVE_RANK_ON",
		0x33821d8,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_ADDR_STR_MAP",
		0x99cb354,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_DATA_ENABLE",
		0x2cfbdb7,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_DATA_SEED",
		0x56bd70c,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_DDR4_PDA_ENABLE",
		0xfd972bc,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_END_ADDR",
		0xbbcc82a,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_ERROR_CAPTURE",
		0x233b6a3,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_MAX_TIMEOUT",
		0x6e0ef67,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_PATTERN",
		0x99c8bd7,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_PRINTING_DISABLE",
		0x46ced5d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_PRINT_PORT",
		0xb368c3e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_RANDOM_SEED_TYPE",
		0x2f58cdf,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_RANDOM_SEED_VALUE",
		0x1fad2d0,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_RANK",
		0x90daf25,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_START_ADDR",
		0x2ec6437,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_STOP_ON_ERROR",
		0xd7f7b0c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_TEST_TYPE",
		0xe5d6eed,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_USER_BANK",
		0x6773585,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCBIST_USER_RANK",
		0x8903f08,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MCS_INBAND_BASE_ADDRESS",
		0x2420c51,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_DDR_REFCLOCK_RCVR_TERM",
		0xaf4f6a6,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_DMI_CUPLL_PFD360_OFFSET",
		0x0c910ea,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_DMI_CUPLL_REFCLKSEL_OFFSET",
		0xdb4870d,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_DMI_REFCLOCK_RCVR_TERM",
		0x4cf88f9,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_MEM_PLL_CFG_UPDATE_OFFSET",
		0x698851c,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_TP_BNDY_PLL_DATA",
		0x4e18af0,
		sizeof(uint8_t),
		{ 80, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_TP_BNDY_PLL_FLUSH",
		0x2efdcfc,
		sizeof(uint8_t),
		{ 80, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_TP_BNDY_PLL_LENGTH",
		0x236ee88,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_DATA",
		0xcb28efd,
		sizeof(uint8_t),
		{ 80, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_LENGTH",
		0x37498c4,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_DATA",
		0x5608876,
		sizeof(uint8_t),
		{ 80, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_LENGTH",
		0x59fc982,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_DATA",
		0x14cd64e,
		sizeof(uint8_t),
		{ 80, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_LENGTH",
		0x9d38ff0,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_DATA",
		0x31359a0,
		sizeof(uint8_t),
		{ 80, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_LENGTH",
		0xbbe3bcd,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_DATA",
		0xde405e2,
		sizeof(uint8_t),
		{ 80, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_LENGTH",
		0x99b182a,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_DATA",
		0x56c14b6,
		sizeof(uint8_t),
		{ 80, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_LENGTH",
		0x07b7b8f,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_DATA",
		0x25de3fd,
		sizeof(uint8_t),
		{ 80, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_LENGTH",
		0x598270f,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_DATA",
		0xd17f879,
		sizeof(uint8_t),
		{ 80, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_LENGTH",
		0x4bd8788,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MEMB_TP_BNDY_PLL_SCAN_SELECT",
		0xf79436a,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MEM_FILTER_PLL_SOURCE",
		0x292e834,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MEM_MIRROR_PLACEMENT_POLICY",
		0xb543ea7,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MFG_TRACE_ENABLE",
		0xbad56c6,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MIRROR_BASE_ADDRESS",
		0x61788d6,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MNFG_ABUS_MIN_EYE_HEIGHT",
		0x1de4aa4,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MNFG_ABUS_MIN_EYE_WIDTH",
		0xf560265,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MNFG_DMI_MIN_EYE_HEIGHT",
		0x9fb7790,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MNFG_DMI_MIN_EYE_WIDTH",
		0x3a4e80e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MNFG_FLAGS",
		0x22cdd45,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MNFG_XBUS_MIN_EYE_WIDTH",
		0x19c7850,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MRW_CDIMM_MASTER_I2C_TEMP_SENSOR_ENABLE",
		0x091c61f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MRW_CDIMM_SPARE_I2C_TEMP_SENSOR_ENABLE",
		0x146f883,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MRW_DDR3_VDDR_MAX_LIMIT",
		0x4c9b6a0,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MRW_DDR4_VDDR_MAX_LIMIT",
		0xe815a80,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MRW_DIMM_POWER_CURVE_PERCENT_UPLIFT",
		0x74de6fe,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MRW_DIMM_POWER_CURVE_PERCENT_UPLIFT_IDLE",
		0x1f96350,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MRW_ENHANCED_GROUPING_NO_MIRRORING",
		0xbd2ad29,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MRW_MAX_DRAM_DATABUS_UTIL",
		0x8b18512,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MRW_MAX_NUMBER_DIMMS_POSSIBLE_PER_VMEM_REGULATOR",
		0x1068aeb,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MRW_MBA_CACHELINE_INTERLEAVE_MODE_CONTROL",
		0xc406062,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MRW_MCS_PREFETCH_RETRY_THRESHOLD",
		0x2d14d55,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MRW_MEM_SENSOR_CACHE_ADDR_MAP",
		0xf27fb39,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MRW_MEM_THROTTLE_DENOMINATOR",
		0xf1db5be,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MRW_POWER_CONTROL_REQUESTED",
		0x1ec075d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_CHIP",
		0x3c6655d,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_MBA",
		0x0185106,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MRW_STRICT_MBA_PLUG_RULE_CHECKING",
		0x96d07ec,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MRW_THERMAL_MEMORY_POWER_LIMIT",
		0x1e9fec7,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MRW_VMEM_REGULATOR_MEMORY_POWER_LIMIT_PER_DIMM",
		0x7f51d49,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MRW_VMEM_REGULATOR_POWER_LIMIT_PER_DIMM_ADJ_ENABLE",
		0x1c79f2a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_ALLOW_SINGLE_PORT",
		0x68d34ab,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_AVDD_OFFSET",
		0x33871a3,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_AVDD_OFFSET_DISABLE",
		0x3aa2e0b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_AVDD_SLOPE_ACTIVE",
		0xca5bef7,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_AVDD_SLOPE_INACTIVE",
		0xa9b123c,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_AVDD_SLOPE_INTERCEPT",
		0x8ba1f56,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_BLUEWATERFALL_BROKEN",
		0x130ae0e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_CACHE_ENABLE",
		0x0d02bbb,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_CAL_STEP_ENABLE",
		0xf2e501b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_CHANNEL_PAIR_MAXBANDWIDTH_GBS",
		0x89a7ae0,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_CHANNEL_PAIR_MAXBANDWIDTH_MRS",
		0x0c824dc,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_CHANNEL_PAIR_MAXPOWER",
		0xdc2d9bd,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_CLEANER_ENABLE",
		0x6097329,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_DATABUS_UTIL_PER_MBA",
		0x4c1579b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_DDR3_VDDR_INTERCEPT",
		0x18c3d89,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_DDR3_VDDR_SLOPE",
		0xc824cb8,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_DDR4_VDDR_INTERCEPT",
		0x3639a52,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_DDR4_VDDR_SLOPE",
		0x83a41e0,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_DERIVED_MBA_ADDR_INTERLEAVE_BIT",
		0xc5a9d28,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE",
		0x7696f71,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_DIMM_MAXBANDWIDTH_GBS",
		0x060e6f7,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_MSS_DIMM_MAXBANDWIDTH_MRS",
		0xc38809c,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_MSS_DIMM_MAXPOWER",
		0x59be4e0,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_MSS_DIMM_MFG_ID_CODE",
		0xa9d4450,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_MSS_DISABLE1_RDCLK_REG_FIXED",
		0x0e35941,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_DISABLE1_REG_FIXED",
		0x2c7cff4,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_DQS_SWIZZLE_TYPE",
		0x4e01270,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_DRAMINIT_RESET_DISABLE",
		0xb6862fe,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_EFF_DIMM_FUNCTIONAL_VECTOR",
		0x55ca724,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_EFF_VPD_VERSION",
		0x05dbe38,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_FREQ",
		0x5409a94,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_FREQ_BIAS_PERCENTAGE",
		0x9bcc1fe,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_FREQ_OVERRIDE",
		0xccb2200,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_INIT_STATE",
		0x7b0ee1b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_INTERLEAVE_ENABLE",
		0xf6b86e3,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_MBA_ADDR_INTERLEAVE_BIT",
		0x8a49e20,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_MBA_CACHELINE_INTERLEAVE_MODE",
		0x9cc041f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_MCS_GROUP_32",
		0x80d2291,
		sizeof(uint32_t),
		{ 16, 16, 1, 1 }
	},
	{
		"ATTR_MSS_MEM_IPL_COMPLETE",
		0xbf464ef,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_MEM_MC_IN_GROUP",
		0x95abe21,
		sizeof(uint8_t),
		{ 8, 1, 1, 1 }
	},
	{
		"ATTR_MSS_MEM_THROTTLE_DENOMINATOR",
		0xb20b5d7,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_MEM_THROTTLE_NUMERATOR_PER_CHIP",
		0xb189654,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA",
		0x0b4c742,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_MEM_WATT_TARGET",
		0x2ea7b8a,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_NEST_CAPABLE_FREQUENCIES",
		0xae3dcbd,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_NWELL_MISPLACEMENT",
		0xa354b98,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_POWER_INT",
		0xb0a1086,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_MSS_POWER_INT2",
		0x6ef7290,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_MSS_POWER_SLOPE",
		0x99ce405,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_MSS_POWER_SLOPE2",
		0xdaac238,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_MSS_PREFETCH_ENABLE",
		0x799cb05,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_PSRO",
		0x9aab087,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_RUNTIME_MEM_THROTTLE_DENOMINATOR",
		0x970c911,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_CHIP",
		0x7c68e7c,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_MBA",
		0xf28a6ec,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_SLEW_RATE_ADR",
		0x459ac09,
		sizeof(uint8_t),
		{ 2, 4, 4, 1 }
	},
	{
		"ATTR_MSS_SLEW_RATE_DATA",
		0xe6e1ed0,
		sizeof(uint8_t),
		{ 2, 4, 4, 1 }
	},
	{
		"ATTR_MSS_THROTTLE_CONTROL_CAS_WEIGHT",
		0xce9eb42,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_THROTTLE_CONTROL_RAS_WEIGHT",
		0xf8c1994,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_TOTAL_POWER_INT",
		0xd9dc907,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_MSS_TOTAL_POWER_INT2",
		0x840a27a,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_MSS_TOTAL_POWER_SLOPE",
		0x9d80798,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_MSS_TOTAL_POWER_SLOPE2",
		0xd2e1f42,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_MSS_UTIL_N_PER_MBA",
		0x883346a,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_VCS_OFFSET",
		0xbebd823,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_VCS_OFFSET_DISABLE",
		0x774500c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_VCS_SLOPE_ACTIVE",
		0xa38db82,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_VCS_SLOPE_INACTIVE",
		0x973e604,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_VCS_SLOPE_INTERCEPT",
		0x058b89e,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_VDDR_OFFSET",
		0x36dd0ed,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_VDDR_OFFSET_DISABLE",
		0xd6eaa96,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_VDDR_OVERIDE_SPD",
		0x1f013ef,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_VDD_OFFSET",
		0x7afbf7f,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_VDD_OFFSET_DISABLE",
		0xc79c9b7,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_VDD_SLOPE_ACTIVE",
		0xed54551,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_VDD_SLOPE_INACTIVE",
		0x3558863,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_VDD_SLOPE_INTERCEPT",
		0xf0a736a,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_VMEM_REGULATOR_MAX_DIMM_COUNT",
		0x7563123,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_VOLT",
		0xca0aeab,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_VOLT_COMPLIANT_DIMMS",
		0x46b2878,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_VOLT_OVERRIDE",
		0x6c80b74,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_VOLT_VPP",
		0x82f8467,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_VPP_OFFSET",
		0x6b9647d,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_VPP_OFFSET_DISABLE",
		0x10bd6fb,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_VPP_SLOPE",
		0x5d94ec1,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_VPP_SLOPE_INTERCEPT",
		0x4ff0fde,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MSS_VREF_CAL_CNTL",
		0xd95104b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_MULTI_SCOM_BUFFER_MAX_SIZE",
		0x3a1cbd8,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_NAME",
		0xb91b1b8,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_NEST_FREQ_MHZ",
		0x403f570,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OPT_MEMMAP_GROUP_POLICY",
		0xc7641e0,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OSCSWITCH_CTL0",
		0x2647699,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OSCSWITCH_CTL1",
		0xa3aa8c5,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OSCSWITCH_CTL2",
		0x1c5b238,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_FVMIN_FREQ_MHZ",
		0xee63140,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_I_CS_FVMIN_CURRENT",
		0x479b93f,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_I_CS_LAB_CURRENT",
		0x213c598,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_I_CS_NOM_CURRENT",
		0xa5b9edc,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_I_CS_PS_CURRENT",
		0x573682d,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_I_CS_TURBO_CURRENT",
		0xbbd2a6f,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_I_NEST_FVMIN_CURRENT",
		0xfe7411b,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_I_NEST_LAB_CURRENT",
		0xa8cb474,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_I_NEST_NOM_CURRENT",
		0x2ef5495,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_I_NEST_PS_CURRENT",
		0x4c51922,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_I_NEST_TURBO_CURRENT",
		0x7497d40,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_LAB_FREQ_MHZ",
		0x8a53ba8,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_NOM_FREQ_MHZ",
		0x7df251d,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_PS_FREQ_MHZ",
		0xfae1a2e,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_TURBO_FREQ_MHZ",
		0x1f5a0a2,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_V_CS_FVMIN_VOLTAGE",
		0xfe1b974,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_V_CS_LAB_VOLTAGE",
		0x1ec1aca,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_V_CS_NOM_VOLTAGE",
		0x63cc0de,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_V_CS_PS_VOLTAGE",
		0xbcdf40c,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_V_CS_TURBO_VOLTAGE",
		0x29151e2,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_V_NEST_FVMIN_VOLTAGE",
		0x5860b85,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_V_NEST_LAB_VOLTAGE",
		0x1811804,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_V_NEST_NOM_VOLTAGE",
		0xfb1769f,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_V_NEST_PS_VOLTAGE",
		0x3b46ba9,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_OVERRIDE_MVPD_V_NEST_TURBO_VOLTAGE",
		0x146f985,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PCI_OSCSWITCH_CONFIG",
		0xa85e131,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PCI_REFCLOCK_RCVR_TERM",
		0xd6b0bb7,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PIB_I2C_NEST_PLL",
		0x2ea0b98,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PIB_I2C_REFCLOCK",
		0xbc375a8,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_AISS_TIMEOUT",
		0xfb08279,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_APSS_CHIP_SELECT",
		0x13fd1b6,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_EXTERNAL_VRM_STEPDELAY",
		0x842449e,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_EXTERNAL_VRM_STEPDELAY_RANGE",
		0x62d0b43,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_EXTERNAL_VRM_STEPDELAY_VALUE",
		0x9f45c20,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_EXTERNAL_VRM_STEPSIZE",
		0x912a82e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_FIRINIT_DONE_ONCE_FLAG",
		0xe0b140f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_GLOBAL_FIR_TRACE_EN",
		0x98fd917,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_HWP_ATTR_VERSION",
		0x2c5d134,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_IVRMS_ENABLED",
		0xf78935d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_OCC_HEARTBEAT_TIME",
		0x8798284,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_OCC_LFIR_MASK",
		0xc78f47f,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PBAX_BRDCST_ID_VECTOR",
		0x1de28ed,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PBAX_CHIPID",
		0x83d6f07,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PBAX_NODEID",
		0xcef178c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PBAX_RCV_RESERV_TIMEOUT",
		0x603d1f5,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PBAX_SND_RESERV_TIMEOUT",
		0x6908d32,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PBAX_SND_RETRY_COUNT_OVERCOMMIT_ENABLE",
		0x6348b8d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PBAX_SND_RETRY_THRESHOLD",
		0x534ec4c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PBA_FIR_MASK",
		0x946b77a,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PCBS_FSM_TRACE_EN",
		0x16033a1,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PFET_POWERDOWN_CORE_DELAY0",
		0x37f1308,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PFET_POWERDOWN_CORE_DELAY0_VALUE",
		0xe58b1a8,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PFET_POWERDOWN_CORE_DELAY1",
		0xb2fd6b6,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PFET_POWERDOWN_CORE_DELAY1_VALUE",
		0x0a5e1e6,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PFET_POWERDOWN_CORE_SEQUENCE_DELAY_SELECT",
		0xd29c3a0,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PFET_POWERDOWN_ECO_DELAY0",
		0xf9b7b7f,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PFET_POWERDOWN_ECO_DELAY0_VALUE",
		0xd441e4d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PFET_POWERDOWN_ECO_DELAY1",
		0xbabe6fb,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PFET_POWERDOWN_ECO_DELAY1_VALUE",
		0xe9c0d5e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PFET_POWERDOWN_ECO_SEQUENCE_DELAY_SELECT",
		0x2bfb3d4,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PFET_POWERUP_CORE_DELAY0",
		0x76b51f4,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PFET_POWERUP_CORE_DELAY0_VALUE",
		0x47ecf0d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PFET_POWERUP_CORE_DELAY1",
		0x6e20290,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PFET_POWERUP_CORE_DELAY1_VALUE",
		0x8f922bf,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PFET_POWERUP_CORE_SEQUENCE_DELAY_SELECT",
		0x372ba4c,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PFET_POWERUP_ECO_DELAY0",
		0x2d642da,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PFET_POWERUP_ECO_DELAY0_VALUE",
		0x150659a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PFET_POWERUP_ECO_DELAY1",
		0x659f781,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PFET_POWERUP_ECO_DELAY1_VALUE",
		0xa4cd70d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PFET_POWERUP_ECO_SEQUENCE_DELAY_SELECT",
		0x86f288f,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PFET_WORKAROUND_RUN_FLAG",
		0xb3c555d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PMC_HANGPULSE_DIVIDER",
		0xe990f9e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PMC_LFIR_MASK",
		0xabe4bae,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_POWER_PROXY_TRACE_TIMER",
		0x4afbe91,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PPT_TIMER_MATCH_VALUE",
		0xe6115ed,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PPT_TIMER_TICK",
		0x1abf241,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PSTATE0_FREQUENCY",
		0xec1474c,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PSTATE_STEPSIZE",
		0x067383f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_PVSAFE_PSTATE",
		0x88bb957,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_RESONANT_CLOCK_ENABLE",
		0x95f176b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_RESONANT_CLOCK_FULL_CLOCK_SECTOR_BUFFER_FREQUENCY",
		0x328d622,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_RESONANT_CLOCK_FULL_CSB_PSTATE",
		0x08ab787,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_RESONANT_CLOCK_HFRHIGH_PSTATE",
		0xd25870a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_RESONANT_CLOCK_HFRLOW_PSTATE",
		0xe4e4353,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_RESONANT_CLOCK_HIGH_BAND_LOWER_FREQUENCY",
		0xd4c48bf,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_RESONANT_CLOCK_HIGH_BAND_UPPER_FREQUENCY",
		0xf850a54,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_RESONANT_CLOCK_LFRLOW_PSTATE",
		0x060a42d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_RESONANT_CLOCK_LFRUPPER_PSTATE",
		0xf9bf608,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_RESONANT_CLOCK_LOW_BAND_LOWER_FREQUENCY",
		0xcd2a836,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_RESONANT_CLOCK_LOW_BAND_UPPER_FREQUENCY",
		0xd933142,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SAFE_FREQUENCY",
		0x87bf0e4,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SAFE_PSTATE",
		0xb9d303a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SLEEP_ENABLE",
		0x8d30758,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SLEEP_ENTRY",
		0xddda241,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SLEEP_EXIT",
		0x8afeedb,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SLEEP_TYPE",
		0x893f5f8,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SLEEP_WINKLE_REQUEST_TIMEOUT",
		0x4a4a339,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SLW_CONTROL_VECTOR_OFFSET",
		0xc211b1e,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SLW_DEEP_SLEEP_EXIT_GOOD_HALT_ADDR",
		0xa9c9091,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SLW_DEEP_WINKLE_EXIT_GOOD_HALT_ADDR",
		0xa7f0d3f,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIPSS_CLOCK_DIVIDER",
		0xd2fed1a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIPSS_CLOCK_PHASE",
		0x5e21a9f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIPSS_CLOCK_POLARITY",
		0x3f0a8e0,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIPSS_FRAME_SIZE",
		0x097f45d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIPSS_FREQUENCY",
		0xe82d64a,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIPSS_INTER_FRAME_DELAY",
		0x8dfc09e,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIPSS_INTER_FRAME_DELAY_SETTING",
		0xf684924,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIPSS_IN_COUNT",
		0x895b645,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIPSS_IN_DELAY",
		0x7da6bbe,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIPSS_OUT_COUNT",
		0x77c1636,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIVID_CLOCK_DIVIDER",
		0xd98ec14,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIVID_CLOCK_PHASE",
		0x4d446f0,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIVID_CLOCK_POLARITY",
		0x8c1049e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIVID_CRC_CHECK_ENABLE",
		0x5aeedf6,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIVID_CRC_GEN_ENABLE",
		0x03a0b7c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIVID_CRC_POLYNOMIAL_ENABLES",
		0xacd7bfc,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIVID_FRAME_SIZE",
		0x9664cfa,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIVID_FREQUENCY",
		0xd987528,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS",
		0xec24d74,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS_VALUE",
		0xe2d10c2,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIVID_INTER_RETRY_DELAY",
		0x205484c,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIVID_INTER_RETRY_DELAY_VALUE",
		0xd26494a,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIVID_IN_DELAY_FRAME1",
		0xbf66b13,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIVID_IN_DELAY_FRAME2",
		0xe33f64d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIVID_MAJORITY_VOTE_ENABLE",
		0xcd05499,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIVID_MAX_RETRIES",
		0xc66fa35,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPIVID_PORT_ENABLE",
		0xec163bf,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPWUP_FSP",
		0x8ece29b,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPWUP_IGNORE_XSTOP_FLAG",
		0x4686755,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPWUP_OCC",
		0xba10908,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPWUP_OHA_FLAG",
		0x9738d8f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SPWUP_PHYP",
		0xdf86041,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SYSTEM_IVRMS_ENABLED",
		0xc33316b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_SYSTEM_IVRM_VPD_MIN_LEVEL",
		0x47fbc66,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_UNDERVOLTING_FREQ_MAXIMUM",
		0xafafda9,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_UNDERVOLTING_FRQ_MINIMUM",
		0x2fc2857,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_WINKLE_ENTRY",
		0x20d8f35,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_WINKLE_EXIT",
		0x8d9fdb8,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PM_WINKLE_TYPE",
		0xb5692a7,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PNOR_I2C_ADDRESS_BYTES",
		0x6029076,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_POS",
		0x0962a16,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_ABUS_CUPLL_PFD360_OFFSET",
		0x75708b3,
		sizeof(uint32_t),
		{ 3, 1, 1, 1 }
	},
	{
		"ATTR_PROC_ABUS_CUPLL_REFCLKSEL_OFFSET",
		0xa9b950c,
		sizeof(uint32_t),
		{ 3, 1, 1, 1 }
	},
	{
		"ATTR_PROC_AB_BNDY_PLL_CHIPLET_ID",
		0x99be4e4,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_AB_BNDY_PLL_DATA",
		0xa632bff,
		sizeof(uint8_t),
		{ 110, 1, 1, 1 }
	},
	{
		"ATTR_PROC_AB_BNDY_PLL_FLUSH",
		0xceac964,
		sizeof(uint8_t),
		{ 110, 1, 1, 1 }
	},
	{
		"ATTR_PROC_AB_BNDY_PLL_LENGTH",
		0xcffd528,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_AB_BNDY_PLL_SCAN_SELECT",
		0x5ccc488,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_ADU_UNTRUSTED_BAR_BASE_ADDR",
		0x3ec0777,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_ADU_UNTRUSTED_BAR_SIZE",
		0x622f4b1,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_AS_MMIO_BAR_BASE_ADDR",
		0x597f3a2,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_AS_MMIO_BAR_ENABLE",
		0x4cad8a0,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_AS_MMIO_BAR_SIZE",
		0xadb27a6,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_A_ENABLE",
		0x4f12515,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_BOOT_VOLTAGE_VID",
		0xe34b343,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_DCM_INSTALLED",
		0xce9d606,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_DMI_CUPLL_PFD360_OFFSET",
		0x68c73d0,
		sizeof(uint32_t),
		{ 8, 1, 1, 1 }
	},
	{
		"ATTR_PROC_DMI_CUPLL_REFCLKSEL_OFFSET",
		0x81c373a,
		sizeof(uint32_t),
		{ 8, 1, 1, 1 }
	},
	{
		"ATTR_PROC_DPLL_DIVIDER",
		0xe568250,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_EC_CORE_HANG_PULSE_BUG",
		0x9f2f682,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_EC_MSS_RECONFIG_POSSIBLE",
		0xe6a8fbc,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_EC_OHA_L3_PURGE_ABORT_ENABLE",
		0x9a1d182,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_EC_PBA_PREFETCH_ENABLE",
		0xd836f46,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_EPS_GB_DIRECTION",
		0xf22fe2c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_EPS_GB_PERCENTAGE",
		0x0a991b8,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_EPS_TABLE_TYPE",
		0x132602b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_EX_FUNC_L3_DELTA_DATA",
		0xee745b1,
		sizeof(uint32_t),
		{ 64, 1, 1, 1 }
	},
	{
		"ATTR_PROC_EX_FUNC_L3_LENGTH",
		0x559bc81,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_FABRIC_ASYNC_SAFE_MODE",
		0x8ec3a1c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_FABRIC_PUMP_MODE",
		0x138ee84,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_FOREIGN_FAR_BASE",
		0xd385149,
		sizeof(uint64_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_PROC_FOREIGN_FAR_SIZE",
		0x76c0a28,
		sizeof(uint64_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_PROC_FOREIGN_NEAR_BASE",
		0xbb3e484,
		sizeof(uint64_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_PROC_FOREIGN_NEAR_SIZE",
		0x8026c5b,
		sizeof(uint64_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_PROC_FSP_BAR_BASE_ADDR",
		0xd0dc091,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_FSP_BAR_ENABLE",
		0x5eb7cea,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_FSP_BAR_SIZE",
		0x7e86af0,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_FSP_MMIO_MASK_SIZE",
		0x136e087,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_HA_BASE",
		0x3e5876b,
		sizeof(uint64_t),
		{ 8, 1, 1, 1 }
	},
	{
		"ATTR_PROC_HA_SIZE",
		0xc9a7ddb,
		sizeof(uint64_t),
		{ 8, 1, 1, 1 }
	},
	{
		"ATTR_PROC_HTM_BAR_BASE_ADDR",
		0x349ab37,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_HTM_BAR_SIZE",
		0x4b6309e,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_INTP_BAR_BASE_ADDR",
		0x4bd196e,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_INTP_BAR_ENABLE",
		0x59a51d1,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_L3_BAR1_REG",
		0x6aa8527,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_L3_BAR2_REG",
		0x5afe609,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_L3_BAR_GROUP_MASK_REG",
		0xcb93257,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_L3_ENABLE",
		0xe5574e5,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_MEM_BASE",
		0x2855dd7,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_MEM_BASES",
		0x610bccf,
		sizeof(uint64_t),
		{ 8, 1, 1, 1 }
	},
	{
		"ATTR_PROC_MEM_BASES_ACK",
		0xd703199,
		sizeof(uint64_t),
		{ 8, 1, 1, 1 }
	},
	{
		"ATTR_PROC_MEM_SIZES",
		0x928afa6,
		sizeof(uint64_t),
		{ 8, 1, 1, 1 }
	},
	{
		"ATTR_PROC_MEM_SIZES_ACK",
		0x91475c7,
		sizeof(uint64_t),
		{ 8, 1, 1, 1 }
	},
	{
		"ATTR_PROC_MIRROR_BASE",
		0x317938b,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_MIRROR_BASES",
		0xdedd8c2,
		sizeof(uint64_t),
		{ 4, 1, 1, 1 }
	},
	{
		"ATTR_PROC_MIRROR_BASES_ACK",
		0x286213a,
		sizeof(uint64_t),
		{ 4, 1, 1, 1 }
	},
	{
		"ATTR_PROC_MIRROR_SIZES",
		0xb3f43f2,
		sizeof(uint64_t),
		{ 4, 1, 1, 1 }
	},
	{
		"ATTR_PROC_MIRROR_SIZES_ACK",
		0x3e968cc,
		sizeof(uint64_t),
		{ 4, 1, 1, 1 }
	},
	{
		"ATTR_PROC_NPU_MMIO_BAR_BASE_ADDR",
		0xdeddca3,
		sizeof(uint64_t),
		{ 4, 2, 1, 1 }
	},
	{
		"ATTR_PROC_NPU_MMIO_BAR_ENABLE",
		0xf8bad7c,
		sizeof(uint8_t),
		{ 4, 2, 1, 1 }
	},
	{
		"ATTR_PROC_NPU_MMIO_BAR_SIZE",
		0x5ee1299,
		sizeof(uint64_t),
		{ 4, 2, 1, 1 }
	},
	{
		"ATTR_PROC_NX_ENABLE",
		0x7d03d8c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_NX_MMIO_BAR_BASE_ADDR",
		0x5befa2b,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_NX_MMIO_BAR_ENABLE",
		0xae63781,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_NX_MMIO_BAR_SIZE",
		0xca6ff4b,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_OCC_SANDBOX_BASE_ADDR",
		0x0c66212,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_OCC_SANDBOX_SIZE",
		0x4ef368d,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PBA_UNTRUSTED_BAR_BASE_ADDR",
		0x1b2f722,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PBA_UNTRUSTED_BAR_SIZE",
		0xe21c89c,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PBIEX_ASYNC_SEL",
		0x0116509,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PB_BNDY_DMIPLL_CHIPLET_ID",
		0xfb9c77b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PB_BNDY_DMIPLL_DATA",
		0x6f7369b,
		sizeof(uint8_t),
		{ 240, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PB_BNDY_DMIPLL_FLUSH",
		0x5bde086,
		sizeof(uint8_t),
		{ 240, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PB_BNDY_DMIPLL_LENGTH",
		0x36bc48b,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PB_BNDY_DMIPLL_SCAN_SELECT",
		0xdb34f5b,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_BAR_BASE_ADDR",
		0x63218eb,
		sizeof(uint64_t),
		{ 4, 3, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_BAR_ENABLE",
		0xdeb75ec,
		sizeof(uint8_t),
		{ 4, 3, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_BAR_SIZE",
		0x6f31ceb,
		sizeof(uint64_t),
		{ 4, 3, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_ENABLE",
		0xe671b84,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_IOP_CONFIG",
		0x1179bee,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_IOP_G2_PLL_CONTROL0",
		0xfee2c5d,
		sizeof(uint32_t),
		{ 3, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_IOP_G3_PLL_CONTROL0",
		0xac4f4c4,
		sizeof(uint32_t),
		{ 3, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_IOP_PCS_CONTROL0",
		0xe1c2cd0,
		sizeof(uint32_t),
		{ 3, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_IOP_PCS_CONTROL1",
		0xe3f9203,
		sizeof(uint32_t),
		{ 3, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_IOP_PLL_GLOBAL_CONTROL0",
		0x6a97de2,
		sizeof(uint32_t),
		{ 3, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_IOP_PLL_GLOBAL_CONTROL1",
		0x37fbcab,
		sizeof(uint32_t),
		{ 3, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_IOP_RX_PEAK",
		0x37789d9,
		sizeof(uint32_t),
		{ 3, 16, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_IOP_RX_SDL",
		0x9b18f7f,
		sizeof(uint32_t),
		{ 3, 16, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_IOP_RX_VGA_CONTROL2",
		0x2171144,
		sizeof(uint32_t),
		{ 3, 16, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_IOP_SWAP",
		0x5692bf0,
		sizeof(uint8_t),
		{ 3, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_IOP_TX_BWLOSS1",
		0xad76da6,
		sizeof(uint32_t),
		{ 3, 16, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_IOP_TX_FFE_GEN1",
		0x542d66a,
		sizeof(uint32_t),
		{ 3, 16, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_IOP_TX_FFE_GEN2",
		0x86e0f92,
		sizeof(uint32_t),
		{ 3, 16, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_IOP_TX_FIFO_OFFSET",
		0x0c3b0a9,
		sizeof(uint32_t),
		{ 3, 16, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_IOP_TX_RCVRDETCNTL",
		0xbe95011,
		sizeof(uint32_t),
		{ 3, 16, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_IOP_ZCAL_CONTROL",
		0xf4fa143,
		sizeof(uint32_t),
		{ 3, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_NOT_F_LINK",
		0x5bfae6d,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_NUM_IOP",
		0x1f0e94c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_NUM_LANES",
		0x4da44eb,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_NUM_PHB",
		0x7137f89,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_PHB_ACTIVE",
		0xf8da522,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PCIE_REFCLOCK_ENABLE",
		0x603d529,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PCI_BNDY_PLL_CHIPLET_ID",
		0x830da01,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PCI_BNDY_PLL_DATA",
		0xde50967,
		sizeof(uint8_t),
		{ 110, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PCI_BNDY_PLL_FLUSH",
		0xeec581e,
		sizeof(uint8_t),
		{ 110, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PCI_BNDY_PLL_LENGTH",
		0x59dfbff,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PCI_BNDY_PLL_SCAN_SELECT",
		0xfc34561,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PERV_BNDY_PLL_CHIPLET_ID",
		0x2b358c9,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PERV_BNDY_PLL_DATA",
		0xd24694b,
		sizeof(uint8_t),
		{ 128, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PERV_BNDY_PLL_FLUSH",
		0x7956533,
		sizeof(uint8_t),
		{ 128, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PERV_BNDY_PLL_LENGTH",
		0xfe61a20,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PERV_BNDY_PLL_SCAN_SELECT",
		0xf39f50c,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PERV_VITL_LENGTH",
		0x6f9410c,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PSI_BRIDGE_BAR_BASE_ADDR",
		0xd636a2c,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PSI_BRIDGE_BAR_ENABLE",
		0x36f669b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PSI_UNTRUSTED_BAR0_BASE_ADDR",
		0x52c5728,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PSI_UNTRUSTED_BAR0_SIZE",
		0x0780333,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PSI_UNTRUSTED_BAR1_BASE_ADDR",
		0xb1cf068,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_PSI_UNTRUSTED_BAR1_SIZE",
		0x49a04de,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_REFCLOCK_RCVR_TERM",
		0x4252e3d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_R_DISTLOSS_VCS",
		0x6aca66f,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_R_DISTLOSS_VDD",
		0x2e4aa10,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_R_LOADLINE_VCS",
		0x9b6d3fd,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_R_LOADLINE_VDD",
		0x4cc6c8a,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_SECURITY_SETUP_VECTOR",
		0x6ccaf9a,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_TP_VITL_SPY_LENGTH",
		0x071520d,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_TP_VITL_SPY_OFFSETS",
		0x9a4e381,
		sizeof(uint32_t),
		{ 24, 1, 1, 1 }
	},
	{
		"ATTR_PROC_VRM_VOFFSET_VCS",
		0xaffbf23,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_VRM_VOFFSET_VDD",
		0x000593f,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_X_BUS_WIDTH",
		0x7a48d6f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_PROC_X_ENABLE",
		0xbe299c0,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_RECONFIGURE_LOOP",
		0xb04d39a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_REDUNDANT_CLOCKS",
		0x36784e2,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_RISK_LEVEL",
		0x6c6a7b8,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SBE_IMAGE_MINIMUM_VALID_EXS",
		0x8f9b648,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SBE_IMAGE_OFFSET",
		0xc6122e2,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SBE_MASTER_INTR_SERVICE_DELAY_CYCLES",
		0x6e93d6f,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SBE_MASTER_INTR_SERVICE_DELAY_US",
		0xf9fdd3d,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SBE_SEEPROM_I2C_ADDRESS_BYTES",
		0x3c6066b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SBE_SEEPROM_I2C_DEVICE_ADDRESS",
		0x3042fd3,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_SBE_SEEPROM_I2C_PORT",
		0x4bf2261,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_SCHMOO_MULTIPLE_SETUP_CALL",
		0x0397e7d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SCRATCH_UINT32_1",
		0x6e35711,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SCRATCH_UINT32_2",
		0xb6b04cf,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SCRATCH_UINT32_ARRAY_1",
		0x330cac1,
		sizeof(uint32_t),
		{ 8, 1, 1, 1 }
	},
	{
		"ATTR_SCRATCH_UINT32_ARRAY_2",
		0x9c880f8,
		sizeof(uint32_t),
		{ 2, 3, 1, 1 }
	},
	{
		"ATTR_SCRATCH_UINT64_1",
		0x97c0c12,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SCRATCH_UINT64_2",
		0xa09fac0,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SCRATCH_UINT64_ARRAY_1",
		0x14d36df,
		sizeof(uint64_t),
		{ 4, 1, 1, 1 }
	},
	{
		"ATTR_SCRATCH_UINT64_ARRAY_2",
		0x065e855,
		sizeof(uint64_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_SCRATCH_UINT8_1",
		0xd16a035,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SCRATCH_UINT8_2",
		0xd53bc45,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SCRATCH_UINT8_ARRAY_1",
		0x4b2b986,
		sizeof(uint8_t),
		{ 32, 1, 1, 1 }
	},
	{
		"ATTR_SCRATCH_UINT8_ARRAY_2",
		0x466dcc2,
		sizeof(uint8_t),
		{ 2, 3, 4, 1 }
	},
	{
		"ATTR_SPD_BAD_DQ_DATA",
		0x64cb9e3,
		sizeof(uint8_t),
		{ 80, 1, 1, 1 }
	},
	{
		"ATTR_SPD_CAS_LATENCIES_SUPPORTED",
		0x88189b9,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR3",
		0xc8ac0b9,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR4",
		0xc5c6a54,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_CRC_BASE_CONFIG_DDR4",
		0x865951b,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_CRC_MNFG_SEC_DDR4",
		0xda9cb9c,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_CUSTOM",
		0x3fc59f1,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_CYCLICAL_REDUNDANCY_CODE",
		0x467287b,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_DIMM_MODULE_LR_ATTRIBUTES",
		0x8405b09,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_DIMM_RCD_CNTL_WORD_0_15",
		0x8851f6d,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_DRAM_DEVICE_TYPE",
		0xdbe36bd,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_DRAM_MANUFACTURER_JEDEC_ID_CODE",
		0x44a6f7c,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_DRAM_STEPPING_DDR4",
		0xe590676,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_DRAM_WIDTH",
		0x18080bc,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_FINE_OFFSET_TAAMIN",
		0xdfcb8b0,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_FINE_OFFSET_TCCDLMIN_DDR4",
		0x8d1fbcd,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_FINE_OFFSET_TCKMAX_DDR4",
		0xfb07c31,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_FINE_OFFSET_TCKMIN",
		0xc53b45a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_FINE_OFFSET_TRCDMIN",
		0xf5ac3d6,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_FINE_OFFSET_TRCMIN",
		0xd06543f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_FINE_OFFSET_TRPMIN",
		0x8c09870,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_FINE_OFFSET_TRRDLMIN_DDR4",
		0x2a11048,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_FINE_OFFSET_TRRDSMIN_DDR4",
		0x212779e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_FTB_DIVIDEND",
		0xa130eef,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_FTB_DIVISOR",
		0x9fb7509,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_ADDR_MAP_REG_TO_DRAM",
		0x8b8b8cc,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_ADDR_MIRRORING",
		0x8316350,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_BUF_MDQ_DRV_1866_2400",
		0x8f3ae97,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_BUF_MDQ_DRV_2400_3200",
		0x9768180,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_BUF_MDQ_DRV_LESS_THAN_1866",
		0x9c2c051,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_BUF_VREF_DQ_FOR_DRAM",
		0x3bcbda8,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_DRAM_DRV_STRENGTH",
		0x1766c11,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_DRAM_ODT_RTT_NOM_1866_2400",
		0x5a040bf,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_DRAM_ODT_RTT_NOM_2400_3200",
		0xd66631e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_DRAM_ODT_RTT_NOM_LESS_THAN_1866",
		0x32711d9,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_DRAM_ODT_RTT_PARK_1866_2400",
		0xd6b4a45,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_DRAM_ODT_RTT_PARK_2400_3200",
		0x168b7d2,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_DRAM_ODT_RTT_PARK_LESS_THAN_1866",
		0xbcec073,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_DRAM_ODT_RTT_WR_1866_2400",
		0x424c1ed,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_DRAM_ODT_RTT_WR_2400_3200",
		0xcd3212b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_DRAM_ODT_RTT_WR_LESS_THAN_1866",
		0xdfb65c6,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_DRAM_VREF_DQ_RANK0",
		0xb7fbeb9,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_DRAM_VREF_DQ_RANK1",
		0x561854a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_DRAM_VREF_DQ_RANK2",
		0x35f9764,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_DRAM_VREF_DQ_RANK3",
		0x4db7f5d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_F0RC3_F0RC2",
		0x917d241,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_F0RC5_F0RC4",
		0x98b444f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_F1RC11_F1RC8",
		0xd1cc41c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_F1RC13_F1RC12",
		0xd7c70c5,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_F1RC15_F1RC14",
		0xd35d125,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_F34RC11_F34RC10_FOR_1333_1600",
		0x2434662,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_F34RC11_F34RC10_FOR_1866_2133",
		0x1f243ee,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_F34RC11_F34RC10_FOR_800_1066",
		0x5afa219,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_F3RC9_F3RC8_FOR_1333_1600",
		0xa8c3b32,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_F3RC9_F3RC8_FOR_1866_2133",
		0x86d92fa,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_F3RC9_F3RC8_FOR_800_1066",
		0x24eae82,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_F56RC11_F56RC10_FOR_1333_1600",
		0xfaa12a8,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_F56RC11_F56RC10_FOR_1866_2133",
		0xfabb0d8,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_F56RC11_F56RC10_FOR_800_1066",
		0x4824106,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_F78RC11_F78RC10_FOR_1333_1600",
		0x8637d49,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_F78RC11_F78RC10_FOR_1866_2133",
		0x26eacbc,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_F78RC11_F78RC10_FOR_800_1066",
		0x52f6585,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_F910RC11_F910RC10_FOR_1333_1600",
		0x40738a4,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_F910RC11_F910RC10_FOR_1866_2133",
		0x88ff0ea,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_F910RC11_F910RC10_FOR_800_1066",
		0x699fa87,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_MR12_FOR_1333_1600",
		0x5673fc6,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_MR12_FOR_1866_2133",
		0xb3d940f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_MR12_FOR_800_1066",
		0xbd9453f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_REGISTER_MANF_ID",
		0x236f99c,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_LR_REG_OUTPUT_DRV_STRENGTH_CK",
		0xc63cd0e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_MODSPEC_COM_REF_RAW_CARD",
		0xf2d2c90,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_MODSPEC_COM_REF_RAW_CARD_REV",
		0x5b9cbf8,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE",
		0x3398112,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_MODULE_ID_MODULE_MANUFACTURING_DATE",
		0x343bbe2,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_MODULE_ID_MODULE_MANUFACTURING_LOCATION",
		0xa5f3615,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_MODULE_ID_MODULE_SERIAL_NUMBER",
		0x82f1f13,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_MODULE_MEMORY_BUS_WIDTH",
		0x0e50e1e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_MODULE_NOMINAL_VOLTAGE",
		0x73f1064,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_MODULE_NOMINAL_VOLTAGE_DDR3",
		0x741659a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_MODULE_NOMINAL_VOLTAGE_DDR4",
		0xa5c1f65,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_MODULE_PART_NUMBER",
		0x552cdb1,
		sizeof(uint8_t),
		{ 18, 1, 1, 1 }
	},
	{
		"ATTR_SPD_MODULE_REVISION_CODE",
		0x1d93652,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_MODULE_REVISION_CODE_DDR3",
		0x17e28db,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_MODULE_REVISION_CODE_DDR4",
		0x8fd86ca,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_MODULE_SPECIFIC_SECTION",
		0x5eb47a9,
		sizeof(uint8_t),
		{ 57, 1, 1, 1 }
	},
	{
		"ATTR_SPD_MODULE_THERMAL_SENSOR",
		0x1b699f8,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_MODULE_TYPE",
		0xd4e4240,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_MTB_DIVIDEND",
		0xc20ff51,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_MTB_DIVISOR",
		0x9e26625,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_NUM_OF_REGISTERS_USED_ON_RDIMM",
		0x39fa001,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_NUM_RANKS",
		0x7dbc67a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_SDRAM_BANKGROUPS_DDR4",
		0x0901bef,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_SDRAM_BANKS",
		0x7ffe67a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_SDRAM_BANKS_DDR3",
		0x1df6a25,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_SDRAM_BANKS_DDR4",
		0xe7b42c1,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_SDRAM_COLUMNS",
		0x74faa45,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_SDRAM_DENSITY",
		0x37a6e4c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_SDRAM_DEVICE_TYPE",
		0xb60bcfe,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_SDRAM_DEVICE_TYPE_SIGNAL_LOADING",
		0x335c15a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_SDRAM_DIE_COUNT",
		0x1fbf83f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_SDRAM_OPTIONAL_FEATURES",
		0x431c54b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_SDRAM_ROWS",
		0x12caefe,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_SDRAM_THERMAL_AND_REFRESH_OPTIONS",
		0x4f8a5c4,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_TAAMIN",
		0x0e03b4b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_TCCDLMIN_DDR4",
		0x1581f0d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_TCKMAX_DDR4",
		0x33621fc,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_TCKMIN",
		0x896919f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_TFAWMIN",
		0x5e01ec7,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_TIMEBASE_FTB_DDR4",
		0xe65d5a9,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_TIMEBASE_MTB_DDR4",
		0x6e09a77,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_TRASMIN",
		0x2ce2f7c,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_TRCDMIN",
		0x34144b7,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_TRCMIN",
		0x830e82e,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_TRFC1MIN_DDR4",
		0xf08ca1d,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_TRFC2MIN_DDR4",
		0x7236022,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_TRFC4MIN_DDR4",
		0xfb7dd2b,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_TRFCMIN",
		0x4114c71,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_TRPMIN",
		0x1884230,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_TRRDLMIN_DDR4",
		0x6e1bcbb,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_TRRDMIN",
		0xd0aa657,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_TRRDSMIN_DDR4",
		0xdc2f623,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_TRTPMIN",
		0xde22d98,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_TWRMIN",
		0x56daf14,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SPD_TWTRMIN",
		0x67f96e5,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_SYNC_BETWEEN_STEPS",
		0x6e0ab98,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_TARGET_SCOMABLE",
		0x2b33d5a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_TCCD_L",
		0x7b0ae8c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_TDP_RDP_CURRENT_FACTOR",
		0x2d45b65,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_TRUSTED_SLAVE_SCAN_PATH_ACTIVE",
		0x945659b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_VOLTAGE_EXT_VCS_BIAS_DOWN",
		0x1761a09,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_VOLTAGE_EXT_VCS_BIAS_UP",
		0xab31151,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_VOLTAGE_EXT_VDD_BIAS_DOWN",
		0x4236a1c,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_VOLTAGE_EXT_VDD_BIAS_UP",
		0x246ac62,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_VOLTAGE_INT_VCS_BIAS_DOWN",
		0xbd9357e,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_VOLTAGE_INT_VCS_BIAS_UP",
		0x77ef4d6,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_VOLTAGE_INT_VDD_BIAS_DOWN",
		0x0aa0d33,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_VOLTAGE_INT_VDD_BIAS_UP",
		0x71c8418,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CDIMM_SENSOR_MAP_PRIMARY",
		0xffc273f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CDIMM_SENSOR_MAP_SECONDARY",
		0x8b07ee9,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_DRV_IMP_ADDR",
		0xb4e2583,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_DRV_IMP_CLK",
		0xa417f56,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_DRV_IMP_CNTL",
		0xbc24a3e,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_DRV_IMP_DQ_DQS",
		0xf15067e,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_DRV_IMP_SPCKE",
		0x70b0209,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M0_CLK_P0",
		0xfff28c5,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M0_CLK_P1",
		0xba1d85b,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE0",
		0x21f2459,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE1",
		0xd80a132,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE2",
		0x2a98438,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE3",
		0xf8e4024,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN0",
		0x9801dbb,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN1",
		0x63dfc1a,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN2",
		0x97af9b3,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN3",
		0xd9df1cc,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_ODT0",
		0xea6ddd4,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_ODT1",
		0x842f688,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M1_CLK_P0",
		0xd12b8f5,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M1_CLK_P1",
		0xa3a3e69,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE0",
		0x483bb6b,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE1",
		0x6054b24,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE2",
		0xa5e90b4,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE3",
		0x7575df4,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN0",
		0x9f07725,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN1",
		0xace580e,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN2",
		0x305be81,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN3",
		0x532eef7,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_ODT0",
		0xfb3b2ab,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_ODT1",
		0xedc6d29,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M_ACTN",
		0x2be6384,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M_CMD_A0",
		0x79bb2f3,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M_CMD_A1",
		0x676adb3,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M_CMD_A10",
		0x722f829,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M_CMD_A11",
		0x2e3f0c0,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M_CMD_A12",
		0x5bee7a7,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M_CMD_A13",
		0xd6619f2,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M_CMD_A14",
		0xbf0a0a2,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M_CMD_A15",
		0xd1ff97b,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M_CMD_A2",
		0x24c98c9,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M_CMD_A3",
		0x762c8ea,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M_CMD_A4",
		0x72dda21,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M_CMD_A5",
		0xf600fd9,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M_CMD_A6",
		0x74ee1c6,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M_CMD_A7",
		0x7be097f,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M_CMD_A8",
		0xf7863e5,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M_CMD_A9",
		0x7379cac,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA0",
		0xaf92d9f,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA1",
		0x35696fe,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA2",
		0x96f8caf,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M_CMD_CASN",
		0xb59e3b9,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M_CMD_RASN",
		0x9ed5400,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M_CMD_WEN",
		0xd484124,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_PHASE_ROT_M_PAR",
		0x17c483d,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_RCV_IMP_DQ_DQS",
		0x31e6a5e,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_RD_VREF",
		0xa50073c,
		sizeof(uint32_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_SLEW_RATE_ADDR",
		0xb87d944,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_SLEW_RATE_CLK",
		0xa609134,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_SLEW_RATE_CNTL",
		0x7c8c7a3,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_SLEW_RATE_DQ_DQS",
		0x134d418,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CEN_SLEW_RATE_SPCKE",
		0x85f0673,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CKE_PRI_MAP",
		0xa068494,
		sizeof(uint32_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_CKE_PWR_MAP",
		0x6bf1222,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_VPD_DIMM_RCD_CNTL_WORD_0_15",
		0xb2a8aa3,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_VPD_DIMM_RCD_IBT",
		0xd498676,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_VPD_DIMM_RCD_OUTPUT_TIMING",
		0x7af23a4,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_VPD_DIMM_SPARE",
		0x266e3eb,
		sizeof(uint8_t),
		{ 2, 2, 4, 1 }
	},
	{
		"ATTR_VPD_DRAM_2N_MODE_ENABLED",
		0xa7ee517,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_VPD_DRAM_ADDRESS_MIRRORING",
		0x1e12d3c,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_VPD_DRAM_RON",
		0x61e9543,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 }
	},
	{
		"ATTR_VPD_DRAM_RTT_NOM",
		0xc0f8c6b,
		sizeof(uint8_t),
		{ 2, 2, 4, 1 }
	},
	{
		"ATTR_VPD_DRAM_RTT_PARK",
		0x0a5e309,
		sizeof(uint8_t),
		{ 2, 2, 4, 1 }
	},
	{
		"ATTR_VPD_DRAM_RTT_WR",
		0x486274f,
		sizeof(uint8_t),
		{ 2, 2, 4, 1 }
	},
	{
		"ATTR_VPD_DRAM_WRDDR4_VREF",
		0xb7b7342,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_DRAM_WR_VREF",
		0xcd3736b,
		sizeof(uint32_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_DW_KEYWORD",
		0x7b960d8,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_VPD_GPO",
		0xc7e5d5f,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_ISDIMMTOC4DQ",
		0x92cc467,
		sizeof(uint8_t),
		{ 4, 80, 1, 1 }
	},
	{
		"ATTR_VPD_ISDIMMTOC4DQS",
		0x4e23e52,
		sizeof(uint8_t),
		{ 4, 20, 1, 1 }
	},
	{
		"ATTR_VPD_MR_DATA_CONTROL_BYTE",
		0x33e82d6,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_VPD_MR_VERSION_BYTE",
		0x59abd03,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_VPD_MT_DATA_CONTROL_BYTE",
		0x1b48d11,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_VPD_MT_VERSION_BYTE",
		0x3615228,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_VPD_ODT_RD",
		0x2794706,
		sizeof(uint8_t),
		{ 2, 2, 4, 1 }
	},
	{
		"ATTR_VPD_ODT_WR",
		0x5f960e8,
		sizeof(uint8_t),
		{ 2, 2, 4, 1 }
	},
	{
		"ATTR_VPD_PERIODIC_MEMCAL_MODE_OPTIONS",
		0x2fc41d0,
		sizeof(uint32_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_POWER_CONTROL_CAPABLE",
		0x0514729,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_VPD_RD_CTR_WINDAGE_OFFSET",
		0xd94fb8e,
		sizeof(uint32_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_RLO",
		0x9e81b79,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_TSYS_ADR",
		0x19591aa,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_TSYS_DP18",
		0xdac65dc,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VPD_VD_KEYWORD",
		0xb5665b3,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_VPD_VERSION",
		0x97bf461,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_VPD_VM_KEYWORD",
		0x3f86965,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_VPD_WLO",
		0x986be33,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 }
	},
	{
		"ATTR_VREF_DQ_TRAIN_ENABLE",
		0xa3ee234,
		sizeof(uint8_t),
		{ 2, 2, 4, 1 }
	},
	{
		"ATTR_VREF_DQ_TRAIN_RANGE",
		0x43961d5,
		sizeof(uint8_t),
		{ 2, 2, 4, 1 }
	},
	{
		"ATTR_VREF_DQ_TRAIN_VALUE",
		0x47ae8cf,
		sizeof(uint8_t),
		{ 2, 2, 4, 1 }
	},
	{
		"ATTR_WOF_ENABLED",
		0xe59852e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_X_EREPAIR_THRESHOLD_FIELD",
		0x19eb5a7,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
	{
		"ATTR_X_EREPAIR_THRESHOLD_MNFG",
		0xdc853d2,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 }
	},
};
