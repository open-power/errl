const AttributeData g_TargAttrs[] = {
	{
		"ATTR_ADC_CHANNEL_FUNC_IDS",
		0xba49a18,
		sizeof(uint8_t),
		{ 16, 1, 1, 1 } 
	},
	{
		"ATTR_ADC_CHANNEL_GAINS",
		0x0fc9882,
		sizeof(uint32_t),
		{ 16, 1, 1, 1 } 
	},
	{
		"ATTR_ADC_CHANNEL_GNDS",
		0x33234bf,
		sizeof(uint8_t),
		{ 16, 1, 1, 1 } 
	},
	{
		"ATTR_ADC_CHANNEL_OFFSETS",
		0xc789762,
		sizeof(uint32_t),
		{ 16, 1, 1, 1 } 
	},
	{
		"ATTR_ADC_CHANNEL_SENSOR_NUMBERS",
		0xab26dbf,
		sizeof(uint16_t),
		{ 16, 1, 1, 1 } 
	},
	{
		"ATTR_ALL_MCS_IN_INTERLEAVING_GROUP",
		0x06e992f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_ALTFSI_MASTER_PORT",
		0x3d7757a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_APSS_GPIO_PORT_MODES",
		0x227fe0f,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_APSS_GPIO_PORT_PINS",
		0x414575c,
		sizeof(uint8_t),
		{ 16, 1, 1, 1 } 
	},
	{
		"ATTR_AVDD_ID",
		0xc710685,
		sizeof(uint16_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_A_EREPAIR_THRESHOLD_FIELD",
		0x0ca8faf,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_A_EREPAIR_THRESHOLD_MNFG",
		0x7da144e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_BMC_FRU_ID",
		0xe3947ec,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_BOOT_FREQ_MHZ",
		0x61f8882,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_BOOT_VOLTAGE",
		0x5c5498f,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_BRAZOS_RX_FIFO_OVERRIDE",
		0x13f6c19,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_CDIMM_SENSOR_MAP_PRIMARY",
		0x28b5520,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_CDIMM_SENSOR_MAP_SECONDARY",
		0x7380824,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_CDM_POLICIES",
		0x6f11c24,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_CENTAUR_ECID_FRU_ID",
		0x957176b,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_CEN_DQ_TO_DIMM_CONN_DQ",
		0xcd7817c,
		sizeof(uint8_t),
		{ 80, 1, 1, 1 } 
	},
	{
		"ATTR_CHIP_HAS_SBE",
		0x5d1081e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_CHIP_ID",
		0x6d3696b,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_CHIP_REGIONS_TO_ENABLE",
		0x208eb9c,
		sizeof(uint64_t),
		{ 32, 1, 1, 1 } 
	},
	{
		"ATTR_CHIP_UNIT",
		0x9615865,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_CLEAR_DIMM_SPD_ENABLE",
		0x2a8e9d5,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_CPM_INFLECTION_POINTS",
		0x09d5ed7,
		sizeof(uint32_t),
		{ 16, 1, 1, 1 } 
	},
	{
		"ATTR_CPM_TURBO_BOOST_PERCENT",
		0x611e151,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_DECONFIG_GARDABLE",
		0x59253de,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_DEFAULT_PROC_MODULE_NEST_FREQ_MHZ",
		0x5f6e58a,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_DISABLE_I2C_ACCESS",
		0x5af6634,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_DISABLE_SCRUB_AFTER_PATTERN_TEST",
		0xf0ab8b0,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_DMI_DFE_OVERRIDE",
		0x1fd9f3d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_DMI_EREPAIR_THRESHOLD_FIELD",
		0xf3365af,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_DMI_EREPAIR_THRESHOLD_MNFG",
		0xfee10ad,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_DMI_REFCLOCK_SWIZZLE",
		0xbff8521,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_DO_ABUS_DECONFIG",
		0x33b0757,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_DUMMY_HEAP_ZERO_DEFAULT",
		0x9184d62,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_DUMMY_PERSISTENCY",
		0x9df5299,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_DUMMY_RO",
		0x7f95302,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_DUMMY_RW",
		0x6b5b079,
		sizeof(uint8_t),
		{ 1, 3, 5, 1 } 
	},
	{
		"ATTR_DUMMY_WO",
		0x18849c5,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EC",
		0x3fd6b69,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_ECID",
		0x522a158,
		sizeof(uint64_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFFECTIVE_EC",
		0x8ff8d9c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_BUFFER_LATENCY",
		0x4d42dc7,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CA_PARITY",
		0xc49c5d6,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CA_PARITY_ERROR_STATUS",
		0x39f6ac3,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CA_PARITY_LATENCY",
		0xe1c6e23,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_DRV_IMP_ADDR",
		0xa2d0de9,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_DRV_IMP_CLK",
		0x6daa86d,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_DRV_IMP_CLK_SCHMOO",
		0x15e70be,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_DRV_IMP_CNTL",
		0x3bc44b0,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_DRV_IMP_CNTL_SCHMOO",
		0xb754336,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_DRV_IMP_DQ_DQS",
		0xef3a38f,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_DRV_IMP_DQ_DQS_SCHMOO",
		0x601a4d0,
		sizeof(uint32_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_DRV_IMP_SPCKE",
		0x2c59739,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_DRV_IMP_SPCKE_SCHMOO",
		0x9f1e9d8,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M0_CLK_P0",
		0x1d8c588,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M0_CLK_P1",
		0x2156b07,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE0",
		0xdd3e551,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE1",
		0x2a9ce17,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE2",
		0x19f5d79,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE3",
		0xf4158a0,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN0",
		0x64217a7,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN1",
		0x00c226f,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN2",
		0x972c092,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN3",
		0x64c529c,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_ODT0",
		0xc9ad00c,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_ODT1",
		0xcf5e70b,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M1_CLK_P0",
		0x8b8c03c,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M1_CLK_P1",
		0x3c718df,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE0",
		0xec28bef,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE1",
		0xe5fb201,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE2",
		0x2bea801,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE3",
		0x6d44754,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN0",
		0x194205a,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN1",
		0x9dabdc5,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN2",
		0x0c3cf4f,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN3",
		0x55b6fff,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_ODT0",
		0x8dda1a9,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_ODT1",
		0x991be14,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M_ACTN",
		0x6b2b22a,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M_CMD_A0",
		0xe8901f3,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M_CMD_A1",
		0x0c163f2,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M_CMD_A10",
		0x4def67f,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M_CMD_A11",
		0x5e03866,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M_CMD_A12",
		0xf78d030,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M_CMD_A13",
		0x1ad95d9,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M_CMD_A14",
		0x8c36c84,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M_CMD_A15",
		0x6fa0e2f,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M_CMD_A2",
		0xdf59887,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M_CMD_A3",
		0xbcafe93,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M_CMD_A4",
		0xea77d20,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M_CMD_A5",
		0x07ca5a8,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M_CMD_A6",
		0xb3b297d,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M_CMD_A7",
		0xede8de8,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M_CMD_A8",
		0xd438677,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M_CMD_A9",
		0x6ec818e,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA0",
		0xde0daf0,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA1",
		0x501b09f,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA2",
		0x01def6d,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M_CMD_CASN",
		0xb070e8a,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M_CMD_RASN",
		0x746963d,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M_CMD_WEN",
		0x719b818,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_PHASE_ROT_M_PAR",
		0x8bc743c,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_RCV_IMP_DQ_DQS",
		0xe9b56c2,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_RCV_IMP_DQ_DQS_SCHMOO",
		0xcee20ef,
		sizeof(uint32_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_RD_VREF",
		0x66c0538,
		sizeof(uint32_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_RD_VREF_SCHMOO",
		0x6b7121d,
		sizeof(uint32_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_SLEW_RATE_ADDR",
		0xb7e69dd,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_SLEW_RATE_ADDR_SCHMOO",
		0x5bca776,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_SLEW_RATE_CLK",
		0x60806ad,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_SLEW_RATE_CLK_SCHMOO",
		0x6c13eeb,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_SLEW_RATE_CNTL",
		0xe5d694b,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_SLEW_RATE_CNTL_SCHMOO",
		0x9083929,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_SLEW_RATE_DQ_DQS",
		0xb350f87,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_SLEW_RATE_DQ_DQS_SCHMOO",
		0x0b98bfa,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_SLEW_RATE_SPCKE",
		0x14b8641,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CEN_SLEW_RATE_SPCKE_SCHMOO",
		0x0e59f80,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CKE_MAP",
		0x7fb1f18,
		sizeof(uint8_t),
		{ 2, 2, 4, 1 } 
	},
	{
		"ATTR_EFF_CKE_PRI_MAP",
		0x78f3ece,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CKE_PWR_MAP",
		0xdf2f5a8,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CRC_ERROR_CLEAR",
		0x88424ac,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CRC_WR_LATENCY",
		0x09f03dd,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CS_CMD_LATENCY",
		0xf41a79e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_CUSTOM_DIMM",
		0x6743c00,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DATA_MASK",
		0x7881e32,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC00",
		0x0dbf64a,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC01",
		0xbb8efa0,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC02",
		0xb472f05,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC03",
		0x3bdf1ae,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC04",
		0x03fc440,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC05",
		0x193adc4,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC06_07",
		0x7910db8,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC08",
		0x56acd0c,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC09",
		0xb2c0de0,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC10",
		0x7743239,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC11",
		0x55c4b62,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC12",
		0xc013663,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC13",
		0xecd2c19,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC14",
		0x6faf33c,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC15",
		0x8aa5843,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC_1x",
		0xba52471,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC_2x",
		0x11a491d,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC_3x",
		0x63718cd,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC_4x",
		0xb024826,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC_5x",
		0x2a65deb,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC_6x",
		0x316a223,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC_7x",
		0xe15f4fa,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC_8x",
		0x7838fe1,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC_9x",
		0x5b489c1,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC_Ax",
		0xadb037b,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_DDR4_RC_Bx",
		0x4e0fd63,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_RANKS_CONFIGED",
		0x092ecab,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_RCD_CNTL_WORD_0_15",
		0x41c2b82,
		sizeof(uint64_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_RCD_CNTL_WORD_X",
		0xbb6e062,
		sizeof(uint64_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_RCD_IBT",
		0x3c59155,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_RCD_MIRROR_MODE",
		0x883151c,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_SIZE",
		0xc1e40a4,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DIMM_SPARE",
		0xc624c4f,
		sizeof(uint8_t),
		{ 2, 2, 4, 1 } 
	},
	{
		"ATTR_EFF_DIMM_TYPE",
		0xe35b4c7,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DQ_WR_OFFSET",
		0xd4d3c40,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_2N_MODE_ENABLED",
		0xb4e0269,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_ADDRESS_MIRRORING",
		0xf1bdf17,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_AL",
		0x988b61c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_ASR",
		0xa8ace8e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_BANKS",
		0x192d6de,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_BL",
		0x04c77a6,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_CL",
		0x97a894d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_COLS",
		0xed0bb9d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_CWL",
		0xe66c2c2,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_DENSITY",
		0x07a9643,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_DLL_ENABLE",
		0x2ef3cf5,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_DLL_PPD",
		0xe7ac6ac,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_DLL_RESET",
		0x8a96823,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_GEN",
		0x0d33633,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_LPASR",
		0xa6f4fe9,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_OUTPUT_BUFFER",
		0x616737c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_PASR",
		0x7692ee2,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_RBT",
		0x2dd5bf0,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_RON",
		0x4ac394b,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_ROWS",
		0x39edd97,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_RTT_NOM",
		0xe2d72d1,
		sizeof(uint8_t),
		{ 2, 2, 4, 1 } 
	},
	{
		"ATTR_EFF_DRAM_RTT_WR",
		0xdfdac0f,
		sizeof(uint8_t),
		{ 2, 2, 4, 1 } 
	},
	{
		"ATTR_EFF_DRAM_SRT",
		0x12af03d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_TCCD_L",
		0x732fad3,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_TDQS",
		0x92d72b7,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_TFAW",
		0xaf91cc7,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_TM",
		0x1295a71,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_TRAS",
		0xa982f98,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_TRC",
		0x7461177,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_TRCD",
		0xc9b93c9,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_TRFC",
		0x878bcaf,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_TRFI",
		0x8d88986,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_TRP",
		0x8b78d35,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_TRRD",
		0x1f639a0,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_TRTP",
		0x9791cea,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_TWTR",
		0x398d20c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_WIDTH",
		0xbcc0968,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_WR",
		0x08e6e84,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_WRDDR4_VREF",
		0x173aa78,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_WRDDR4_VREF_SCHMOO",
		0x467b4af,
		sizeof(uint32_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_WR_LVL_ENABLE",
		0x4f7511d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_WR_VREF",
		0x6945cc9,
		sizeof(uint32_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_DRAM_WR_VREF_SCHMOO",
		0xec9685a,
		sizeof(uint32_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_FINE_REFRESH_MODE",
		0x83066e3,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_GEARDOWN_MODE",
		0xdf0a068,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_GPO",
		0x85f87ba,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_IBM_TYPE",
		0x82e6cdd,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_INT_VREF_MON",
		0x97bdbe7,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_LRDIMM_ADDITIONAL_CNTL_WORDS",
		0x064d52f,
		sizeof(uint64_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_LRDIMM_WORD_X",
		0xd77577c,
		sizeof(uint64_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_MAX_POWERDOWN_MODE",
		0x7c5012d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_MEMCAL_INTERVAL",
		0xf7a4d1e,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_MPR_LOC",
		0x9fb1838,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_MPR_MODE",
		0x6cc620b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_MPR_PAGE",
		0x4a8236c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_MPR_RD_FORMAT",
		0x49c4f61,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_NUM_DIES_PER_PACKAGE",
		0x639e764,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_NUM_DROPS_PER_PORT",
		0xcc56cd5,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM",
		0x0e715c8,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_NUM_PACKAGES_PER_RANK",
		0x42399e1,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_NUM_RANKS_PER_DIMM",
		0x88ba0c5,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_ODT_INPUT_BUFF",
		0x552f10f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_ODT_RD",
		0xf82b926,
		sizeof(uint8_t),
		{ 2, 2, 4, 1 } 
	},
	{
		"ATTR_EFF_ODT_WR",
		0x050e71b,
		sizeof(uint8_t),
		{ 2, 2, 4, 1 } 
	},
	{
		"ATTR_EFF_PER_DRAM_ACCESS",
		0xf217fea,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_PRIMARY_RANK_GROUP0",
		0x1cace70,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_PRIMARY_RANK_GROUP1",
		0x7d7de33,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_PRIMARY_RANK_GROUP2",
		0x170d276,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_PRIMARY_RANK_GROUP3",
		0x6a98e62,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_QUATERNARY_RANK_GROUP0",
		0x50e0279,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_QUATERNARY_RANK_GROUP1",
		0x8418d88,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_QUATERNARY_RANK_GROUP2",
		0xdaa39e7,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_QUATERNARY_RANK_GROUP3",
		0xd86835e,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_RDTAG",
		0x7462d7e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_RD_PREAMBLE",
		0x9285080,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_RD_PREAMBLE_TRAIN",
		0x6440e8c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_READ_DBI",
		0x0035c53,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_RLO",
		0x8e36d0d,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_RTT_PARK",
		0x88a4b7e,
		sizeof(uint8_t),
		{ 2, 2, 4, 1 } 
	},
	{
		"ATTR_EFF_SCHMOO_ADDR_CMD_MIN_MARGIN",
		0x4d7ff4b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_SCHMOO_ADDR_MODE",
		0x48f34e1,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_SCHMOO_DQS_CLK_MIN_MARGIN",
		0x76ec3b2,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_SCHMOO_MODE",
		0x049733a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_SCHMOO_PARAM_VALID",
		0x8115303,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_SCHMOO_RD_EYE_MIN_MARGIN",
		0x1cfb0ee,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_SCHMOO_RD_GATE_MIN_MARGIN",
		0x05e2bac,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_SCHMOO_TEST_VALID",
		0x1c93902,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_SCHMOO_WR_EYE_MIN_MARGIN",
		0xff97f93,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_SECONDARY_RANK_GROUP0",
		0xc65bac5,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_SECONDARY_RANK_GROUP1",
		0xf801275,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_SECONDARY_RANK_GROUP2",
		0xa55be17,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_SECONDARY_RANK_GROUP3",
		0xa65a3c4,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_SELF_REF_ABORT",
		0x33b24bf,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_SPCKE_MAP",
		0x732203a,
		sizeof(uint8_t),
		{ 2, 2, 4, 1 } 
	},
	{
		"ATTR_EFF_STACK_TYPE",
		0x0c3ce87,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_EFF_TEMP_READOUT",
		0x857908e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_TEMP_REF_MODE",
		0x1e59f41,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_TEMP_REF_RANGE",
		0x8b38b18,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_TERTIARY_RANK_GROUP0",
		0xbb83239,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_TERTIARY_RANK_GROUP1",
		0x0236762,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_TERTIARY_RANK_GROUP2",
		0xf21b04e,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_TERTIARY_RANK_GROUP3",
		0x6dabdcc,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_TSYS_ADR",
		0x502a25d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_TSYS_DP18",
		0x159e8f7,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_WLO",
		0x220f4a0,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_WRITE_CRC",
		0xd9af284,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_WRITE_DBI",
		0x8d4bb23,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_WR_PREAMBLE",
		0x5402adf,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EFF_ZQCAL_INTERVAL",
		0x629a976,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EI_BUS_TX_LANE_INVERT",
		0xf33bed0,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EI_BUS_TX_MSBSWAP",
		0xa046f56,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_ENABLED_THREADS",
		0xdf90286,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EXECUTION_PLATFORM",
		0x6134e50,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_EX_GARD_BITS",
		0x394b852,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FABRIC_CHIP_ID",
		0x34eeb58,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FABRIC_NODE_ID",
		0x4ede78d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FABRIC_TO_PHYSICAL_NODE_MAP",
		0x2d207b6,
		sizeof(uint8_t),
		{ 8, 1, 1, 1 } 
	},
	{
		"ATTR_FIELD_CORE_OVERRIDE",
		0xaff2273,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FIELD_TH_P8EX_L2_COL_REPAIRS",
		0xcb7fee2,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FIELD_TH_P8EX_L2_LINE_DELETES",
		0x71a9c51,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FIELD_TH_P8EX_L3_COL_REPAIRS",
		0x9886c55,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FIELD_TH_P8EX_L3_LINE_DELETES",
		0x81856c6,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FORCE_SKIP_SBE_MASTER_INTR_SERVICE",
		0x4baadc1,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FORCE_USE_SBE_SLAVE_SCAN_SERVICE",
		0xeb3efdd,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FREQ_A",
		0x4426c6b,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FREQ_CORE",
		0x50c85dd,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FREQ_CORE_MAX",
		0x9b7245b,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FREQ_MEM_REFCLOCK",
		0x29e287c,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FREQ_PB",
		0xb60b7d0,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FREQ_PCIE",
		0x3c189d0,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FREQ_PROC_REFCLOCK",
		0xaac24d5,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FREQ_PROC_REFCLOCK_KHZ",
		0x1b7a6ae,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FREQ_X",
		0x50a3f36,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FRU_ID",
		0x278bc56,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FSI_GP_REG_SCOM_ACCESS",
		0x5ef6998,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FSI_MASTER_PORT",
		0xf4637bc,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FSI_SLAVE_CASCADE",
		0x21c70fd,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FSP_BAR_SIZE",
		0xd8dde00,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FSP_BASE_ADDR",
		0xfcfe1a6,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_FSP_MMIO_MASK_SIZE",
		0x06d665c,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_HB_EXISTING_IMAGE",
		0xad8243a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_HB_HRMOR_NODAL_BASE",
		0x11a66f1,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_HB_PM_SPWUP_OHA_FLAG",
		0x2d130fe,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_HB_RSV_MEM_SIZE_MB",
		0xbf11ec0,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_HB_TARGET_SCOMABLE",
		0x1a96d47,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_HIDDEN_ERRLOGS_ENABLE",
		0x6adbf88,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_HOMER_PHYS_ADDR",
		0xcac816f,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_HOMER_VIRT_ADDR",
		0x1838631,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_HOSTSVC_PLID",
		0x0aa0ab1,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_HOT_PLUG_POWER_CONTROLLER_INFO",
		0x837b78a,
		sizeof(uint8_t),
		{ 8, 8, 1, 1 } 
	},
	{
		"ATTR_HTMGT_SAFEMODE",
		0x094cab6,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_HUID",
		0xf9fde6a,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_HWAS_STATE_CHANGED_FLAG",
		0x1c5c585,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_HWAS_STATE_CHANGED_SUBSCRIPTION_MASK",
		0x4a76d45,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_I2C_BUS_SPEED_ARRAY",
		0x5c75b22,
		sizeof(uint16_t),
		{ 2, 3, 1, 1 } 
	},
	{
		"ATTR_I2C_SLAVE_ADDRESS",
		0x7cd6063,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_IBSCOM_ENABLE_OVERRIDE",
		0xc88c82f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_IBSCOM_MCS_BASE_ADDR",
		0x1983e2d,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_IBSCOM_PROC_BASE_ADDR",
		0x06d3ba7,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_IBSCOM_VIRTUAL_ADDR",
		0x8516c9c,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_IMT_BAR_SIZE",
		0x6c120b2,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_IMT_BASE_ADDR",
		0xd83c2a5,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_INTP_BASE_ADDR",
		0xac49a29,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_IPMI_INSTANCE",
		0x18dd55a,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_IPMI_MAX_BUFFER_SIZE",
		0x330c475,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_IPMI_SENSORS",
		0x00bf09b,
		sizeof(uint16_t),
		{ 16, 2, 1, 1 } 
	},
	{
		"ATTR_ISDIMM_MBVPD_INDEX",
		0xed25090,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_ISDIMM_POWER_CURVE_ALGORITHM_VERSION",
		0xcbe6190,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_ISTEP_MODE",
		0x54d128f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_ISTEP_PAUSE_CONFIG",
		0x2cf6852,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_ISTEP_PAUSE_ENABLE",
		0x5171c01,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_IS_INTER_ENCLOSURE_BUS",
		0x56ef574,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_IS_MPIPL_HB",
		0xdc00d2a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_IS_SIMULATION",
		0x4367508,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_L2_FORCE_R_T2_EPS",
		0x1ccc263,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_L2_R_T0_EPS",
		0x103a329,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_L2_R_T1_EPS",
		0xf7048b9,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_L2_R_T2_EPS",
		0x620f312,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_L2_W_EPS",
		0x7bae703,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_L3_FORCE_R_T2_EPS",
		0x0044ec7,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_L3_R_T0_EPS",
		0x459bd34,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_L3_R_T1_EPS",
		0x3354357,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_L3_R_T2_EPS",
		0x6803255,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_L3_W_EPS",
		0xf8bf18e,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_LAB_USE_JTAG_MODE",
		0x5a21393,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_LRDIMM_ADDITIONAL_CNTL_WORDS",
		0x3eae089,
		sizeof(uint64_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_LRDIMM_MR12_REG",
		0xa9aecb6,
		sizeof(uint8_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_LRDIMM_RANK_MULT_MODE",
		0x5472ed9,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MAX_CHIPLETS_PER_PROC",
		0xfa1c9e6,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MAX_DIMMS_PER_MBA_PORT",
		0x9130cb8,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MAX_EXS_PER_PROC_CHIP",
		0xa59a4fa,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MAX_MBAS_PER_MEMBUF_CHIP",
		0x90ddd8e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MAX_MBA_PORTS_PER_MBA",
		0xeb1d539,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MAX_MCS_PER_SYSTEM",
		0x86e21ac,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MAX_PROC_CHIPS_PER_NODE",
		0x8dc78ef,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MBA_DIMM",
		0x80b9cd7,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MBA_PORT",
		0x5207f78,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_ADDR_BANK",
		0x190b796,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_ADDR_INTER",
		0x4b5fd99,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_ADDR_MODES",
		0xd9ca00c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_ADDR_NUM_COLS",
		0xd10e3c0,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_ADDR_NUM_ROWS",
		0x49d0fe6,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_ADDR_RAND",
		0x97e10af,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_ADDR_RANK",
		0x6d711e3,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_ADDR_SLAVE_RANK_ON",
		0x898ae31,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_ADDR_STR_MAP",
		0x1bd25b5,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_DATA_ENABLE",
		0xd6f6291,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_DATA_SEED",
		0x3ebad85,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_DDR4_PDA_ENABLE",
		0x395d734,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_END_ADDR",
		0x4a7b93f,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_ERROR_CAPTURE",
		0xdbbc7e2,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_MAX_TIMEOUT",
		0x83f9581,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_PATTERN",
		0x9b9014c,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_PRINTING_DISABLE",
		0xbc3b4dc,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_PRINT_PORT",
		0x1563492,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_RANDOM_SEED_TYPE",
		0xf9ac103,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_RANDOM_SEED_VALUE",
		0x281cb6e,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_RANK",
		0x166219d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_START_ADDR",
		0xac57f07,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_STOP_ON_ERROR",
		0xc276d65,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_TEST_TYPE",
		0xd76e7bb,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_USER_BANK",
		0x48b0ac1,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MCBIST_USER_RANK",
		0x8d4f302,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MEMB_DDR_REFCLOCK_RCVR_TERM",
		0x77fd8b5,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MEMB_DMI_REFCLOCK_RCVR_TERM",
		0x490268f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MEMB_TP_BNDY_PLL_SCAN_SELECT",
		0x88124cf,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MEM_AVDD_OFFSET_MILLIVOLTS",
		0x80161a9,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MEM_BASE",
		0x45a548d,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MEM_FILTER_PLL_SOURCE",
		0x5150470,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MEM_MIRROR_PLACEMENT_POLICY",
		0x1c0d755,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MEM_VCS_OFFSET_MILLIVOLTS",
		0xb7b1ac5,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MEM_VDDR_OFFSET_MILLIVOLTS",
		0xe390ea6,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MEM_VDD_OFFSET_MILLIVOLTS",
		0xcc28df8,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MEM_VPP_OFFSET_MILLIVOLTS",
		0xd4a475d,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MFG_TRACE_ENABLE",
		0xb257082,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MIN_FREQ_MHZ",
		0x6f08f4b,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MIRROR_BASE",
		0x686bbbc,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MIRROR_BASE_ADDRESS",
		0x6a258b6,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MNFG_ABUS_MIN_EYE_HEIGHT",
		0xeaa3fa0,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MNFG_ABUS_MIN_EYE_WIDTH",
		0x0f9d926,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MNFG_DMI_MIN_EYE_HEIGHT",
		0xccc15e8,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MNFG_DMI_MIN_EYE_WIDTH",
		0x72b7486,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MNFG_FLAGS",
		0xb7d5f9c,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MNFG_TH_CEN_L4_CACHE_CES",
		0x9b3e875,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MNFG_TH_CEN_MBA_IPL_SOFT_CE_TH_ALGO",
		0x9855215,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MNFG_TH_CEN_MBA_RT_RCE_PER_RANK",
		0x98a4f85,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MNFG_TH_CEN_MBA_RT_SOFT_CE_TH_ALGO",
		0x31f5434,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MNFG_TH_P8EX_L2_CACHE_CES",
		0x4a0eab5,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MNFG_TH_P8EX_L2_COL_REPAIRS",
		0x135e94d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MNFG_TH_P8EX_L2_DIR_CES",
		0xd9a1169,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MNFG_TH_P8EX_L2_LINE_DELETES",
		0x73a79a6,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MNFG_TH_P8EX_L3_CACHE_CES",
		0x834d343,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MNFG_TH_P8EX_L3_COL_REPAIRS",
		0xd801bd0,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MNFG_TH_P8EX_L3_DIR_CES",
		0xeca4ce3,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MNFG_TH_P8EX_L3_LINE_DELETES",
		0x00f7abf,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MNFG_XBUS_MIN_EYE_WIDTH",
		0xcbd7ed0,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRU_ID",
		0x639dd88,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRW_CDIMM_MASTER_I2C_TEMP_SENSOR_ENABLE",
		0x3a85422,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRW_CDIMM_SPARE_I2C_TEMP_SENSOR_ENABLE",
		0x9f9143c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRW_DDR3_VDDR_MAX_LIMIT",
		0x6ac0905,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRW_DDR3_VDDR_MAX_LIMIT_EFF_CONFIG",
		0x8830142,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRW_DDR3_VDDR_MAX_LIMIT_POST_DRAM_INIT",
		0xdde9311,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRW_DDR4_VDDR_MAX_LIMIT",
		0x69b9e21,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRW_DDR4_VDDR_MAX_LIMIT_EFF_CONFIG",
		0xcbf0ce6,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRW_DDR4_VDDR_MAX_LIMIT_POST_DRAM_INIT",
		0x7b5c147,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRW_DIMM_POWER_CURVE_PERCENT_UPLIFT",
		0x4345ae2,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRW_DIMM_POWER_CURVE_PERCENT_UPLIFT_IDLE",
		0x1e09d62,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRW_ENHANCED_GROUPING_NO_MIRRORING",
		0xbe5eeb2,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRW_MAX_DRAM_DATABUS_UTIL",
		0x5a57893,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRW_MAX_NUMBER_DIMMS_POSSIBLE_PER_VMEM_REGULATOR",
		0x5f1c224,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRW_MBA_CACHELINE_INTERLEAVE_MODE_CONTROL",
		0xf597255,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRW_MCS_PREFETCH_RETRY_THRESHOLD",
		0x80420b8,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRW_MEM_SENSOR_CACHE_ADDR_MAP",
		0x5b64ed1,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRW_MEM_THROTTLE_DENOMINATOR",
		0x8218c38,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRW_POWER_CONTROL_REQUESTED",
		0x5938c0f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_CHIP",
		0x5cf8e48,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_MBA",
		0x304da17,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRW_STRICT_MBA_PLUG_RULE_CHECKING",
		0x329e82d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRW_THERMAL_MEMORY_POWER_LIMIT",
		0xb6e1c9d,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRW_VMEM_REGULATOR_MEMORY_POWER_LIMIT_PER_DIMM",
		0x5c2b5f5,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MRW_VMEM_REGULATOR_POWER_LIMIT_PER_DIMM_ADJ_ENABLE",
		0x64c91aa,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_ALLOW_SINGLE_PORT",
		0xd1c0229,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_BLUEWATERFALL_BROKEN",
		0x54b70ff,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_CACHE_ENABLE",
		0xf35afa4,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_CAL_STEP_ENABLE",
		0x832191c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_CENT_AVDD_INTERCEPT",
		0xbb0ac42,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_CENT_AVDD_OFFSET_DISABLE",
		0x59735e4,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_CENT_AVDD_SLOPE_ACTIVE",
		0x0b207b3,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_CENT_AVDD_SLOPE_INACTIVE",
		0xbaa5d46,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_CENT_VCS_INTERCEPT",
		0x42b4fae,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_CENT_VCS_OFFSET_DISABLE",
		0xfd3432e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_CENT_VCS_SLOPE_ACTIVE",
		0xdfbb097,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_CENT_VCS_SLOPE_INACTIVE",
		0x0cbd3fd,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_CENT_VDD_INTERCEPT",
		0xe54617c,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_CENT_VDD_OFFSET_DISABLE",
		0xa093957,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_CENT_VDD_SLOPE_ACTIVE",
		0x9aef30c,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_CENT_VDD_SLOPE_INACTIVE",
		0x3e7ad0d,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_CHANNEL_MAXBANDWIDTH_GBS",
		0x314033a,
		sizeof(uint32_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_CHANNEL_MAXBANDWIDTH_MRS",
		0x1dc9c80,
		sizeof(uint32_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_CHANNEL_MAXPOWER",
		0x6487231,
		sizeof(uint32_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_CHANNEL_PAIR_MAXBANDWIDTH_GBS",
		0x57d7489,
		sizeof(uint32_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_CHANNEL_PAIR_MAXBANDWIDTH_MRS",
		0xa5ac06a,
		sizeof(uint32_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_CHANNEL_PAIR_MAXPOWER",
		0xc64457f,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_CLEANER_ENABLE",
		0x210448b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_CONTROL_SWITCH",
		0x68c9a51,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_DATABUS_UTIL_PER_MBA",
		0xa2f9494,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_DERIVED_MBA_ADDR_INTERLEAVE_BIT",
		0x83ec0da,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE",
		0xeb1dca3,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_DIMM_MAXBANDWIDTH_GBS",
		0xd03076a,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_MSS_DIMM_MAXBANDWIDTH_MRS",
		0xf6f5210,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_MSS_DIMM_MAXPOWER",
		0x9f616e0,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_MSS_DIMM_MFG_ID_CODE",
		0xcc9fdeb,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_MSS_DIMM_POWER_TEST_REV",
		0x887b217,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_DQS_SWIZZLE_TYPE",
		0x805352f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_DRAMINIT_RESET_DISABLE",
		0x36acfdb,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_EFF_DIMM_FUNCTIONAL_VECTOR",
		0x578c150,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_EFF_VPD_VERSION",
		0x0b098c5,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_FREQ",
		0xe88d183,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_FREQ_BIAS_PERCENTAGE",
		0xb42bb51,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_FREQ_OVERRIDE",
		0x1812aa2,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_INIT_STATE",
		0xba2a405,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_INTERLEAVE_ENABLE",
		0x54fd267,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_LAB_OVERRIDE_FOR_MEM_PLL",
		0x3a46e34,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_MBA_ADDR_INTERLEAVE_BIT",
		0x8ee2d89,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_MBA_CACHELINE_INTERLEAVE_MODE",
		0x771b18e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_MCS_GROUP",
		0xb498067,
		sizeof(uint8_t),
		{ 16, 16, 1, 1 } 
	},
	{
		"ATTR_MSS_MCS_GROUP_32",
		0xb1f7c2d,
		sizeof(uint32_t),
		{ 16, 16, 1, 1 } 
	},
	{
		"ATTR_MSS_MEM_IPL_COMPLETE",
		0x647f6d0,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_MEM_MC_IN_GROUP",
		0xc666c00,
		sizeof(uint8_t),
		{ 8, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_MEM_THROTTLE_DENOMINATOR",
		0xb131fa2,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_MEM_THROTTLE_NUMERATOR_PER_CHIP",
		0xca2df77,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA",
		0xf91fb2b,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_MEM_WATT_TARGET",
		0x2e31113,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_NEST_CAPABLE_FREQUENCIES",
		0x76b6785,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_NWELL_MISPLACEMENT",
		0xe8ca537,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_POWER_INT",
		0x5402483,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_MSS_POWER_INT2",
		0x747aefb,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_MSS_POWER_SLOPE",
		0xc72da79,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_MSS_POWER_SLOPE2",
		0xc627bb7,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_MSS_PREFETCH_ENABLE",
		0x35e6114,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_PSRO",
		0x3f96c65,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_RUNTIME_MEM_THROTTLE_DENOMINATOR",
		0x053abf8,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_CHIP",
		0x95b2eb8,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_MBA",
		0xcfd373e,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_SLEW_RATE_ADR",
		0x4ad3c3b,
		sizeof(uint8_t),
		{ 2, 4, 4, 1 } 
	},
	{
		"ATTR_MSS_SLEW_RATE_DATA",
		0x71c3bfc,
		sizeof(uint8_t),
		{ 2, 4, 4, 1 } 
	},
	{
		"ATTR_MSS_THROTTLE_CONTROL_CAS_WEIGHT",
		0xb1fec5b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_THROTTLE_CONTROL_RAS_WEIGHT",
		0x0a899a5,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_TOTAL_POWER_INT",
		0x7bc7649,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_MSS_TOTAL_POWER_INT2",
		0xe6b4858,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_MSS_TOTAL_POWER_SLOPE",
		0x2108639,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_MSS_TOTAL_POWER_SLOPE2",
		0xdea8b5d,
		sizeof(uint32_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_MSS_UTIL_N_PER_MBA",
		0xb2ffe8c,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VDDR_OVERIDE_SPD",
		0xbb01f4d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VMEM_REGULATOR_MAX_DIMM_COUNT",
		0xa6ef3db,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VOLT",
		0xbcad046,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VOLT_COMPLIANT_DIMMS",
		0x09d8b2b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VOLT_DDR3_VDDR_INTERCEPT",
		0xbdf333e,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VOLT_DDR3_VDDR_INTERCEPT_EFF_CONFIG",
		0xcc1d4bc,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VOLT_DDR3_VDDR_INTERCEPT_POST_DRAM_INIT",
		0x829fde2,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VOLT_DDR3_VDDR_SLOPE",
		0x10d2a3d,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VOLT_DDR3_VDDR_SLOPE_EFF_CONFIG",
		0x84b5044,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VOLT_DDR3_VDDR_SLOPE_POST_DRAM_INIT",
		0x420d32d,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VOLT_DDR4_VDDR_INTERCEPT",
		0x56b3514,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VOLT_DDR4_VDDR_INTERCEPT_EFF_CONFIG",
		0x4706e9e,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VOLT_DDR4_VDDR_INTERCEPT_POST_DRAM_INIT",
		0x6129fe7,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VOLT_DDR4_VDDR_SLOPE",
		0x5d56393,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VOLT_DDR4_VDDR_SLOPE_EFF_CONFIG",
		0x646bfc6,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VOLT_DDR4_VDDR_SLOPE_POST_DRAM_INIT",
		0xb11a217,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VOLT_OVERRIDE",
		0x9b6221c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VOLT_VDDR_OFFSET_DISABLE",
		0xeb1087c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VOLT_VPP_INTERCEPT",
		0x3aa234f,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VOLT_VPP_INTERCEPT_EFF_CONFIG",
		0xb165eec,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VOLT_VPP_INTERCEPT_POST_DRAM_INIT",
		0xd513657,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VOLT_VPP_OFFSET_DISABLE",
		0x34604ce,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VOLT_VPP_SLOPE",
		0x72f49a4,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VOLT_VPP_SLOPE_EFF_CONFIG",
		0x9c89449,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VOLT_VPP_SLOPE_POST_DRAM_INIT",
		0xe2c64ec,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_VREF_CAL_CNTL",
		0xac7506e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MSS_ZSERIES",
		0xdd334a9,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_MULTI_SCOM_BUFFER_MAX_SIZE",
		0xdd9da11,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_NEST_FREQ_MHZ",
		0xb77318e,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_NOMINAL_FREQ_MHZ",
		0x4e64981,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_NPU_MMIO_BAR_BASE_ADDR",
		0xff18a73,
		sizeof(uint64_t),
		{ 4, 2, 1, 1 } 
	},
	{
		"ATTR_NPU_MMIO_BAR_ENABLE",
		0xcb1c3e8,
		sizeof(uint8_t),
		{ 4, 2, 1, 1 } 
	},
	{
		"ATTR_NPU_MMIO_BAR_SIZE",
		0x77da343,
		sizeof(uint64_t),
		{ 4, 2, 1, 1 } 
	},
	{
		"ATTR_N_PLUS_ONE_N_PER_CHIP",
		0x7608aec,
		sizeof(uint16_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_N_PLUS_ONE_N_PER_MBA",
		0xb6f988e,
		sizeof(uint16_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OCC_COMMON_AREA_PHYS_ADDR",
		0xd12d8c8,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OCC_CONTROL_DATA",
		0x509d68e,
		sizeof(uint8_t),
		{ 256, 1, 1, 1 } 
	},
	{
		"ATTR_OCC_MASTER_CAPABLE",
		0xe7e15a5,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OPEN_POWER_DIMM_ERROR_TEMP_DEG_C",
		0x0a5db3f,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OPEN_POWER_DIMM_READ_TIMEOUT_SEC",
		0x67b8922,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OPEN_POWER_DIMM_THROTTLE_TEMP_DEG_C",
		0xf807c26,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OPEN_POWER_MEMCTRL_ERROR_TEMP_DEG_C",
		0xf3cfe74,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OPEN_POWER_MEMCTRL_READ_TIMEOUT_SEC",
		0x274740e,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OPEN_POWER_MEMCTRL_THROTTLE_TEMP_DEG_C",
		0xf6c06bc,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OPEN_POWER_MIN_MEM_UTILIZATION_THROTTLING",
		0xdb523f2,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OPEN_POWER_MIN_POWER_CAP_WATTS",
		0xaa6708b,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OPEN_POWER_N_BULK_POWER_LIMIT_WATTS",
		0xfc2cace,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OPEN_POWER_N_MAX_MEM_POWER_WATTS",
		0x0516ed5,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OPEN_POWER_N_PLUS_ONE_BULK_POWER_LIMIT_WATTS",
		0xafb435e,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OPEN_POWER_N_PLUS_ONE_MAX_MEM_POWER_WATTS",
		0x6255aa9,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OPEN_POWER_PROC_DVFS_TEMP_DEG_C",
		0x7bfa790,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OPEN_POWER_PROC_ERROR_TEMP_DEG_C",
		0x2e2c7e3,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OPEN_POWER_PROC_READ_TIMEOUT_SEC",
		0xe974923,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OPEN_POWER_REGULATOR_EFFICIENCY_FACTOR",
		0x78f38ad,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OPEN_POWER_TURBO_MODE_SUPPORTED",
		0x54a5bff,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OPT_MEMMAP_GROUP_POLICY",
		0xbe133c4,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OT_MIN_N_PER_MBA",
		0xf0b99dd,
		sizeof(uint16_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_FVMIN_FREQ_MHZ",
		0x6bce019,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_I_CS_FVMIN_CURRENT",
		0x9707664,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_I_CS_LAB_CURRENT",
		0x879015b,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_I_CS_NOM_CURRENT",
		0xa315afa,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_I_CS_PS_CURRENT",
		0xccb59d6,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_I_CS_TURBO_CURRENT",
		0x8f254e2,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_I_NEST_FVMIN_CURRENT",
		0x1bdb6b7,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_I_NEST_LAB_CURRENT",
		0x475571b,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_I_NEST_NOM_CURRENT",
		0xd03b86d,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_I_NEST_PS_CURRENT",
		0x7b425d9,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_I_NEST_TURBO_CURRENT",
		0x5fe5632,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_LAB_FREQ_MHZ",
		0x0a12f85,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_NOM_FREQ_MHZ",
		0xff8bd22,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_PS_FREQ_MHZ",
		0x233d892,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_TURBO_FREQ_MHZ",
		0x79811d2,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_V_CS_FVMIN_VOLTAGE",
		0x04d25dc,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_V_CS_LAB_VOLTAGE",
		0x97fbcc4,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_V_CS_NOM_VOLTAGE",
		0x1848a5c,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_V_CS_PS_VOLTAGE",
		0x51fa163,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_V_CS_TURBO_VOLTAGE",
		0x937d29d,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_V_NEST_FVMIN_VOLTAGE",
		0x1b8b1bd,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_V_NEST_LAB_VOLTAGE",
		0xee7cd69,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_V_NEST_NOM_VOLTAGE",
		0x812e723,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_V_NEST_PS_VOLTAGE",
		0xee24bf3,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERRIDE_MVPD_V_NEST_TURBO_VOLTAGE",
		0xfd264b4,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERSUB_N_PER_CHIP",
		0x654dbfc,
		sizeof(uint16_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_OVERSUB_N_PER_MBA",
		0x473cd82,
		sizeof(uint16_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PART_NUMBER",
		0x75f1df4,
		sizeof(uint8_t),
		{ 18, 1, 1, 1 } 
	},
	{
		"ATTR_PAYLOAD_BASE",
		0x020a135,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PAYLOAD_ENTRY",
		0x64b6d86,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PAYLOAD_IN_MIRROR_MEM",
		0x8c5fb5a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PCI_BASE_ADDRS_32",
		0xb3aa338,
		sizeof(uint64_t),
		{ 4, 1, 1, 1 } 
	},
	{
		"ATTR_PCI_BASE_ADDRS_64",
		0x2d4e887,
		sizeof(uint64_t),
		{ 4, 1, 1, 1 } 
	},
	{
		"ATTR_PCI_REFCLOCK_RCVR_TERM",
		0x64e7e70,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PHB_BASE_ADDRS",
		0xb6f0cd7,
		sizeof(uint64_t),
		{ 4, 1, 1, 1 } 
	},
	{
		"ATTR_PIB_I2C_NEST_PLL",
		0x19a4504,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PIB_I2C_REFCLOCK",
		0xa8b10e1,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PLCK_IPL_ATTR_OVERRIDES_EXIST",
		0xba4cb42,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_AISS_TIMEOUT",
		0x72f87ff,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_APSS_CHIP_SELECT",
		0x191dc94,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_EXTERNAL_VRM_STEPDELAY",
		0x5ca8477,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_EXTERNAL_VRM_STEPDELAY_RANGE",
		0x178be72,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_EXTERNAL_VRM_STEPDELAY_VALUE",
		0xc7f6eb0,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_EXTERNAL_VRM_STEPSIZE",
		0x6285af7,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_FIRINIT_DONE_ONCE_FLAG",
		0x4851132,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_GLOBAL_FIR_TRACE_EN",
		0xc315c52,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_HWP_ATTR_VERSION",
		0xd08f8e3,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_IVRMS_ENABLED",
		0x44436e4,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_OCC_HEARTBEAT_TIME",
		0xb4d8e68,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_OCC_LFIR_MASK",
		0x3e59e7e,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PBAX_BRDCST_ID_VECTOR",
		0xddaf529,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PBAX_CHIPID",
		0x6b9bbf8,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PBAX_NODEID",
		0x020df55,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PBAX_RCV_RESERV_TIMEOUT",
		0xd0cd905,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PBAX_SND_RESERV_TIMEOUT",
		0xca3caf0,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PBAX_SND_RETRY_COUNT_OVERCOMMIT_ENABLE",
		0xce07d4c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PBAX_SND_RETRY_THRESHOLD",
		0x8ba9bf1,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PBA_FIR_MASK",
		0xa48a901,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PCBS_FSM_TRACE_EN",
		0xc08791b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PFET_POWERDOWN_CORE_DELAY0",
		0x0f78b78,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PFET_POWERDOWN_CORE_DELAY0_VALUE",
		0xa546547,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PFET_POWERDOWN_CORE_DELAY1",
		0xd6128fa,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PFET_POWERDOWN_CORE_DELAY1_VALUE",
		0x1a476f2,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PFET_POWERDOWN_CORE_SEQUENCE_DELAY_SELECT",
		0x0eb02e0,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PFET_POWERDOWN_ECO_DELAY0",
		0x862db8e,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PFET_POWERDOWN_ECO_DELAY0_VALUE",
		0xd4a1e98,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PFET_POWERDOWN_ECO_DELAY1",
		0xaf24e2f,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PFET_POWERDOWN_ECO_DELAY1_VALUE",
		0x89263b9,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PFET_POWERDOWN_ECO_SEQUENCE_DELAY_SELECT",
		0xc69a697,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PFET_POWERUP_CORE_DELAY0",
		0xb342345,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PFET_POWERUP_CORE_DELAY0_VALUE",
		0x05b26e4,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PFET_POWERUP_CORE_DELAY1",
		0x0baa8a6,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PFET_POWERUP_CORE_DELAY1_VALUE",
		0x0c4456e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PFET_POWERUP_CORE_SEQUENCE_DELAY_SELECT",
		0x95b6c49,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PFET_POWERUP_ECO_DELAY0",
		0x8359ca3,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PFET_POWERUP_ECO_DELAY0_VALUE",
		0x4fc4d36,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PFET_POWERUP_ECO_DELAY1",
		0x1264a02,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PFET_POWERUP_ECO_DELAY1_VALUE",
		0x444360f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PFET_POWERUP_ECO_SEQUENCE_DELAY_SELECT",
		0xfc0bb85,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PFET_WORKAROUND_RUN_FLAG",
		0xdb31808,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PMC_HANGPULSE_DIVIDER",
		0xbc9ce34,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PMC_LFIR_MASK",
		0xb116a02,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_POWER_PROXY_TRACE_TIMER",
		0x8f44127,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PPT_TIMER_MATCH_VALUE",
		0x1a3cef3,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PPT_TIMER_TICK",
		0xa273548,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PSTATE0_FREQUENCY",
		0x0cfe95a,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PSTATE_STEPSIZE",
		0xed6e3be,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_PVSAFE_PSTATE",
		0x95f6329,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_RESONANT_CLOCK_ENABLE",
		0x1cd58bf,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_RESONANT_CLOCK_FULL_CLOCK_SECTOR_BUFFER_FREQUENCY",
		0x0fcef29,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_RESONANT_CLOCK_FULL_CSB_PSTATE",
		0x9e467f3,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_RESONANT_CLOCK_HFRHIGH_PSTATE",
		0x5b032ee,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_RESONANT_CLOCK_HFRLOW_PSTATE",
		0xdda59cd,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_RESONANT_CLOCK_HIGH_BAND_LOWER_FREQUENCY",
		0xe7bf9a7,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_RESONANT_CLOCK_HIGH_BAND_UPPER_FREQUENCY",
		0xb3b543a,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_RESONANT_CLOCK_LFRLOW_PSTATE",
		0xf19d417,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_RESONANT_CLOCK_LFRUPPER_PSTATE",
		0x922f13c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_RESONANT_CLOCK_LOW_BAND_LOWER_FREQUENCY",
		0xe141cc3,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_RESONANT_CLOCK_LOW_BAND_UPPER_FREQUENCY",
		0x6636810,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SAFE_FREQUENCY",
		0x74566a6,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SAFE_PSTATE",
		0x96b8428,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SLEEP_ENABLE",
		0x1c70941,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SLEEP_ENTRY",
		0x6dbe008,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SLEEP_EXIT",
		0x63850ad,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SLEEP_TYPE",
		0x82aa9cb,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SLEEP_WINKLE_REQUEST_TIMEOUT",
		0x5c534f7,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SLW_CONTROL_VECTOR_OFFSET",
		0x690c74f,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SLW_DEEP_SLEEP_EXIT_GOOD_HALT_ADDR",
		0xf4519b3,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SLW_DEEP_WINKLE_EXIT_GOOD_HALT_ADDR",
		0x10517be,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIPSS_CLOCK_DIVIDER",
		0x16824ac,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIPSS_CLOCK_PHASE",
		0x82b807e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIPSS_CLOCK_POLARITY",
		0x0241bf2,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIPSS_FRAME_SIZE",
		0xb69562d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIPSS_FREQUENCY",
		0x5cc04ad,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIPSS_INTER_FRAME_DELAY",
		0x0c042d9,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIPSS_INTER_FRAME_DELAY_SETTING",
		0x3e336e0,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIPSS_IN_COUNT",
		0x3a398b7,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIPSS_IN_DELAY",
		0xae84e31,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIPSS_OUT_COUNT",
		0x57a52ce,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIVID_CLOCK_DIVIDER",
		0x6ca3041,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIVID_CLOCK_PHASE",
		0x533115d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIVID_CLOCK_POLARITY",
		0x3ac352b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIVID_CRC_CHECK_ENABLE",
		0x30ec7ae,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIVID_CRC_GEN_ENABLE",
		0x925f149,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIVID_CRC_POLYNOMIAL_ENABLES",
		0x6d1d3d5,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIVID_FRAME_SIZE",
		0x045cd3f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIVID_FREQUENCY",
		0xb2af6a0,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS",
		0x84bd123,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS_VALUE",
		0x483efc7,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIVID_INTER_RETRY_DELAY",
		0xdc81421,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIVID_INTER_RETRY_DELAY_VALUE",
		0x84737ed,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIVID_IN_DELAY_FRAME1",
		0xca938f8,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIVID_IN_DELAY_FRAME2",
		0x811dcff,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIVID_MAJORITY_VOTE_ENABLE",
		0x66f37af,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIVID_MAX_RETRIES",
		0xe4424fb,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPIVID_PORT_ENABLE",
		0x350d093,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPWUP_FSP",
		0x00cdcc8,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPWUP_IGNORE_XSTOP_FLAG",
		0x4c1219d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPWUP_OCC",
		0x37373c5,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SPWUP_PHYP",
		0x7890710,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SYSTEM_IVRMS_ENABLED",
		0xf543c74,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_SYSTEM_IVRM_VPD_MIN_LEVEL",
		0xc8bfded,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_UNDERVOLTING_FREQ_MAXIMUM",
		0x869f8d9,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_UNDERVOLTING_FRQ_MINIMUM",
		0xea63a7d,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_WINKLE_ENTRY",
		0x4c67b3c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_WINKLE_EXIT",
		0x02418ea,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PM_WINKLE_TYPE",
		0xdfcccc7,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PNOR_I2C_ADDRESS_BYTES",
		0x6044f97,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_POSITION",
		0x90b4ba7,
		sizeof(uint16_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_AB_BNDY_PLL_CHIPLET_ID",
		0x2dc0474,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_AB_BNDY_PLL_SCAN_SELECT",
		0x2c6431c,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_ADU_UNTRUSTED_BAR_BASE_ADDR",
		0xf3f51b8,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_ADU_UNTRUSTED_BAR_SIZE",
		0xc6b877a,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_AS_MMIO_BAR_BASE_ADDR",
		0xff14fd2,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_AS_MMIO_BAR_ENABLE",
		0xd7adf67,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_AS_MMIO_BAR_SIZE",
		0x6270bcb,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_BOOT_VOLTAGE_VID",
		0x5ce94f2,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_DCM_INSTALLED",
		0x2b8d151,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_DPLL_DIVIDER",
		0xde419d0,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_EPS_GB_DIRECTION",
		0x9087eaf,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_EPS_GB_PERCENTAGE",
		0x29081fa,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_EPS_TABLE_TYPE",
		0x23c87d8,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_FABRIC_ASYNC_SAFE_MODE",
		0xd952274,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_FABRIC_PUMP_MODE",
		0xc1c2678,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_HTM_BAR_BASE_ADDR",
		0x6847eb3,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_HTM_BAR_SIZE",
		0x06f2efe,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_L3_BAR1_REG",
		0x3bc248d,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_L3_BAR2_REG",
		0x727aab0,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_L3_BAR_GROUP_MASK_REG",
		0xfd9e124,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_MASTER_TYPE",
		0x68e1db7,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_MCS_GROUPS",
		0x7adcf90,
		sizeof(uint8_t),
		{ 8, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_MEM_BASES",
		0x3849826,
		sizeof(uint64_t),
		{ 8, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_MEM_BASES_ACK",
		0x89b8414,
		sizeof(uint64_t),
		{ 8, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_MEM_SIZES",
		0x61d7f4f,
		sizeof(uint64_t),
		{ 8, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_MEM_SIZES_ACK",
		0xc3e64a1,
		sizeof(uint64_t),
		{ 8, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_MIRROR_BASES",
		0xb9ee432,
		sizeof(uint64_t),
		{ 4, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_MIRROR_BASES_ACK",
		0xb28a4f5,
		sizeof(uint64_t),
		{ 4, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_MIRROR_SIZES",
		0x18128bb,
		sizeof(uint64_t),
		{ 4, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_MIRROR_SIZES_ACK",
		0x4d787f5,
		sizeof(uint64_t),
		{ 4, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_OCC_SANDBOX_BASE_ADDR",
		0x14625e7,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_OCC_SANDBOX_SIZE",
		0x9f3cbef,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PBA_UNTRUSTED_BAR_BASE_ADDR",
		0x40359a6,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PBA_UNTRUSTED_BAR_SIZE",
		0x0076133,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PBIEX_ASYNC_SEL",
		0xc4a5b13,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PB_BNDY_DMIPLL_CHIPLET_ID",
		0x5aded9f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PB_BNDY_DMIPLL_SCAN_SELECT",
		0x6655935,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_DSMP_CAPABLE",
		0xea0b2bc,
		sizeof(uint8_t),
		{ 3, 2, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_IOP_CONFIG",
		0xeb604df,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_IOP_G2_PLL_CONTROL0",
		0x19fa125,
		sizeof(uint32_t),
		{ 3, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_IOP_G3_PLL_CONTROL0",
		0xfe7481f,
		sizeof(uint32_t),
		{ 3, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_IOP_PCS_CONTROL0",
		0x3f31bf0,
		sizeof(uint32_t),
		{ 3, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_IOP_PCS_CONTROL1",
		0xfbd81e9,
		sizeof(uint32_t),
		{ 3, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_IOP_PLL_GLOBAL_CONTROL0",
		0x06e6117,
		sizeof(uint32_t),
		{ 3, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_IOP_PLL_GLOBAL_CONTROL1",
		0x01a149e,
		sizeof(uint32_t),
		{ 3, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_IOP_REVERSAL",
		0x0d07418,
		sizeof(uint8_t),
		{ 3, 2, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_IOP_REVERSAL_BIFURCATED",
		0xecbcd69,
		sizeof(uint8_t),
		{ 3, 2, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_IOP_REVERSAL_NON_BIFURCATED",
		0x07f9a8c,
		sizeof(uint8_t),
		{ 3, 2, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_IOP_RX_PEAK",
		0xbfdd81f,
		sizeof(uint32_t),
		{ 3, 16, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_IOP_RX_SDL",
		0x4ab4ba8,
		sizeof(uint32_t),
		{ 3, 16, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_IOP_RX_VGA_CONTROL2",
		0x0b97979,
		sizeof(uint32_t),
		{ 3, 16, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_IOP_SWAP",
		0x85f1c7e,
		sizeof(uint8_t),
		{ 3, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_IOP_SWAP_BIFURCATED",
		0xbf7d7d7,
		sizeof(uint8_t),
		{ 3, 2, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_IOP_SWAP_NON_BIFURCATED",
		0xd72889f,
		sizeof(uint8_t),
		{ 3, 2, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_IOP_TX_BWLOSS1",
		0xbcb8be1,
		sizeof(uint32_t),
		{ 3, 16, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_IOP_TX_FFE_GEN1",
		0x8eef897,
		sizeof(uint32_t),
		{ 3, 16, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_IOP_TX_FFE_GEN2",
		0xe2ef85d,
		sizeof(uint32_t),
		{ 3, 16, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_IOP_TX_FIFO_OFFSET",
		0x4c0104b,
		sizeof(uint32_t),
		{ 3, 16, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_IOP_TX_RCVRDETCNTL",
		0xc1103ae,
		sizeof(uint32_t),
		{ 3, 16, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_IOP_ZCAL_CONTROL",
		0xcaeb5a9,
		sizeof(uint32_t),
		{ 3, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_IS_SLOT",
		0x69653af,
		sizeof(uint8_t),
		{ 3, 2, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_LANE_EQUALIZATION",
		0x7e09b93,
		sizeof(uint8_t),
		{ 4, 32, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_LANE_MASK",
		0x1439e9f,
		sizeof(uint16_t),
		{ 3, 2, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_LANE_MASK_BIFURCATED",
		0xdc4f1f5,
		sizeof(uint16_t),
		{ 3, 2, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_LANE_MASK_NON_BIFURCATED",
		0xe9b646f,
		sizeof(uint16_t),
		{ 3, 2, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_NOT_F_LINK",
		0xa7b5133,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_NUM_IOP",
		0x346f572,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_NUM_LANES",
		0x83c9bb5,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_NUM_PHB",
		0xe3ed39e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_PHB_ACTIVE",
		0x763e8c5,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PCIE_REFCLOCK_ENABLE",
		0xe2cfa5e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PCI_BNDY_PLL_CHIPLET_ID",
		0xb07614a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PCI_BNDY_PLL_SCAN_SELECT",
		0x9a38d08,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PERV_BNDY_PLL_CHIPLET_ID",
		0x517e15c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PERV_BNDY_PLL_SCAN_SELECT",
		0xa69fd1e,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PSI_UNTRUSTED_BAR0_BASE_ADDR",
		0x1bbcf6f,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PSI_UNTRUSTED_BAR0_SIZE",
		0xcac64a9,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PSI_UNTRUSTED_BAR1_BASE_ADDR",
		0x1b8a236,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_PSI_UNTRUSTED_BAR1_SIZE",
		0x5d73c2a,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_REFCLOCK_RCVR_TERM",
		0x5f9ce72,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_R_DISTLOSS_VCS",
		0xd0c457a,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_R_DISTLOSS_VDD",
		0xa598a78,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_R_LOADLINE_VCS",
		0xa5423c5,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_R_LOADLINE_VDD",
		0x2dd043f,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_SECURITY_SETUP_VECTOR",
		0x2f34a29,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_SELECT_BOOT_MASTER",
		0x048f69f,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_SELECT_BOOT_SEEPROM_IMAGE",
		0xdba3bba,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_SELECT_SEEPROM_IMAGE",
		0x36ac7a5,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_VRM_VOFFSET_VCS",
		0xe24f70c,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_VRM_VOFFSET_VDD",
		0xc1de22d,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PROC_X_BUS_WIDTH",
		0x999db6b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PSI_BRIDGE_BASE_ADDR",
		0x6508321,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_PSTATE_TABLE",
		0x05d02a2,
		sizeof(uint8_t),
		{ 3656, 1, 1, 1 } 
	},
	{
		"ATTR_PSTATE_TABLE_MFG",
		0xe98cfd9,
		sizeof(uint8_t),
		{ 3656, 1, 1, 1 } 
	},
	{
		"ATTR_RECONFIGURE_LOOP",
		0x1b589a0,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_RECONFIG_LOOP_TESTS",
		0x4fe6548,
		sizeof(uint64_t),
		{ 5, 1, 1, 1 } 
	},
	{
		"ATTR_RECONFIG_LOOP_TESTS_ENABLE",
		0x97d43be,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_REDUNDANT_CLOCKS",
		0x706e27b,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_RESOURCE_IS_CRITICAL",
		0xbfccf0c,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_RISK_LEVEL",
		0xb3adef2,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_RNG_BAR_SIZE",
		0xe2bf285,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_RNG_BASE_ADDR",
		0xafef4d7,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_RUN_MAX_MEM_PATTERNS",
		0x778bcbb,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_SBE_IMAGE_MINIMUM_VALID_EXS",
		0x2489e36,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_SBE_IMAGE_OFFSET",
		0x5ba77b7,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_SBE_MASTER_INTR_SERVICE_DELAY_CYCLES",
		0x07de5de,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_SBE_MASTER_INTR_SERVICE_DELAY_US",
		0x927e9d0,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_SBE_MASTER_INTR_SERVICE_ENABLED",
		0xdc20544,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_SBE_SEEPROM_I2C_ADDRESS_BYTES",
		0x152214e,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_SBE_SEEPROM_I2C_DEVICE_ADDRESS",
		0x5ac150b,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_SBE_SEEPROM_I2C_PORT",
		0xd1e416f,
		sizeof(uint8_t),
		{ 2, 1, 1, 1 } 
	},
	{
		"ATTR_SCHMOO_MULTIPLE_SETUP_CALL",
		0x12f9f97,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_SCRATCH_UINT32_1",
		0x782c053,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_SCRATCH_UINT32_2",
		0x002156b,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_SCRATCH_UINT32_ARRAY_1",
		0xe572010,
		sizeof(uint32_t),
		{ 8, 1, 1, 1 } 
	},
	{
		"ATTR_SCRATCH_UINT32_ARRAY_2",
		0xf014872,
		sizeof(uint32_t),
		{ 2, 3, 1, 1 } 
	},
	{
		"ATTR_SCRATCH_UINT64_1",
		0xeee9926,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_SCRATCH_UINT64_2",
		0x18a17a2,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_SCRATCH_UINT64_ARRAY_1",
		0x4403d2c,
		sizeof(uint64_t),
		{ 4, 1, 1, 1 } 
	},
	{
		"ATTR_SCRATCH_UINT64_ARRAY_2",
		0x24d2ff8,
		sizeof(uint64_t),
		{ 2, 2, 1, 1 } 
	},
	{
		"ATTR_SCRATCH_UINT8_1",
		0xc7bc372,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_SCRATCH_UINT8_2",
		0xe93419a,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_SCRATCH_UINT8_ARRAY_1",
		0xae204e8,
		sizeof(uint8_t),
		{ 32, 1, 1, 1 } 
	},
	{
		"ATTR_SCRATCH_UINT8_ARRAY_2",
		0xdaba3f6,
		sizeof(uint8_t),
		{ 2, 3, 4, 1 } 
	},
	{
		"ATTR_SERIAL_NUMBER",
		0xbac5402,
		sizeof(uint8_t),
		{ 18, 1, 1, 1 } 
	},
	{
		"ATTR_SLW_IMAGE_ADDR",
		0x63d25df,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_SLW_IMAGE_SIZE",
		0x559dc32,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_SYNC_BETWEEN_STEPS",
		0x3761a65,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_TCCD_L",
		0x2f3c3ee,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_TOD_ROLE",
		0x019e5ac,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_TRUSTED_SLAVE_SCAN_PATH_ACTIVE",
		0xab7f2ea,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_ULTRA_TURBO_FREQ_MHZ",
		0xca2de0a,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_VCS_ID",
		0x780a573,
		sizeof(uint16_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_VDD_ID",
		0x2a9cfd3,
		sizeof(uint16_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_VMEM_ID",
		0x1478506,
		sizeof(uint16_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_VPD_REC_NUM",
		0x03a8b72,
		sizeof(uint16_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_VPP_BASE",
		0x6894ce3,
		sizeof(uint32_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_VPP_ID",
		0xa5ccc9a,
		sizeof(uint16_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_VREF_DQ_TRAIN_ENABLE",
		0x56e27bb,
		sizeof(uint8_t),
		{ 2, 2, 4, 1 } 
	},
	{
		"ATTR_VREF_DQ_TRAIN_RANGE",
		0xdb5b392,
		sizeof(uint8_t),
		{ 2, 2, 4, 1 } 
	},
	{
		"ATTR_VREF_DQ_TRAIN_VALUE",
		0xb63ae40,
		sizeof(uint8_t),
		{ 2, 2, 4, 1 } 
	},
	{
		"ATTR_WOF_ENABLED",
		0xca00099,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_WOF_FREQUENCY_UPLIFT",
		0xbd8e129,
		sizeof(uint16_t),
		{ 4, 22, 13, 1 } 
	},
	{
		"ATTR_WOF_FREQUENCY_UPLIFT_SELECTED",
		0xc2f06b5,
		sizeof(uint16_t),
		{ 22, 13, 1, 1 } 
	},
	{
		"ATTR_WOF_PROC_SORT",
		0x739a2c3,
		sizeof(uint16_t),
		{ 4, 3, 1, 1 } 
	},
	{
		"ATTR_WOF_REGULATOR_EFFICIENCIES",
		0xeebaf3e,
		sizeof(uint16_t),
		{ 3, 14, 1, 1 } 
	},
	{
		"ATTR_XSCOM_BASE_ADDRESS",
		0x7803464,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_XSCOM_VIRTUAL_ADDR",
		0x9b947e9,
		sizeof(uint64_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_X_EREPAIR_THRESHOLD_FIELD",
		0xdc95f16,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
	{
		"ATTR_X_EREPAIR_THRESHOLD_MNFG",
		0x5035da1,
		sizeof(uint8_t),
		{ 1, 1, 1, 1 } 
	},
};
