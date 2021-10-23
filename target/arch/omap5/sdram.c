/*
* Copyright (C) 2012 Texas Instruments, Inc.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*  * Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*  * Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in
*    the documentation and/or other materials provided with the
*    distribution.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
* OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
* AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
* SUCH DAMAGE.
*/

#include <aboot.h>
#include <io.h>
#include <hw.h>
#include <common_proc.h>

static struct ddr_io ddr2_io_default[] = {

	{CTRL_MODULE_CORE_PAD_CONTROL_DDR3CH1_0, CTRL_DDR3CH1_0_ADJ_LPDDR2},
	{CTRL_MODULE_CORE_PAD_CONTROL_DDR3CH2_0, CTRL_DDR3CH2_0_ADJ_LPDDR2},

	{CTRL_MODULE_CORE_PAD_CONTROL_DDRCH1_0, CTRL_DDRCH1_0_ADJ_LPDDR2},
	{CTRL_MODULE_CORE_PAD_CONTROL_DDRCH1_1, CTRL_DDRCH1_1_ADJ_LPDDR2},
	{CTRL_MODULE_CORE_PAD_CONTROL_DDRCH2_0, CTRL_DDRCH2_0_ADJ_LPDDR2},
	{CTRL_MODULE_CORE_PAD_CONTROL_DDRCH2_1, CTRL_DDRCH2_1_ADJ_LPDDR2},

	{CONTROL_LPDDR2CH1_0, CTRL_LPDDR2CH1_0_ADJ_LPDDR2},
	{CONTROL_LPDDR2CH1_1, CTRL_LPDDR2CH1_1_ADJ_LPDDR2},

	{CTRL_MODULE_CORE_PAD_CONTROL_DDRIO_0, CTRL_DDRIO_0_ADJ_LPDDR2},
	{CTRL_MODULE_CORE_PAD_CONTROL_DDRIO_1, CTRL_DDRIO_1_ADJ_LPDDR2},
	{CTRL_MODULE_CORE_PAD_CONTROL_DDRIO_2, CTRL_DDRIO_2_ADJ_LPDDR2},

	{0, 0},
};

static struct ddr_io ddr3_io_default[] = {

	{CTRL_MODULE_CORE_PAD_CONTROL_DDR3CH1_0, CTRL_DDR3CH1_0_ADJ_DDR3},
	{CTRL_MODULE_CORE_PAD_CONTROL_DDR3CH2_0, CTRL_DDR3CH2_0_ADJ_DDR3},

	{CTRL_MODULE_CORE_PAD_CONTROL_DDRCH1_0, CTRL_DDRCH1_0_ADJ_DDR3},
	{CTRL_MODULE_CORE_PAD_CONTROL_DDRCH1_1, CTRL_DDRCH1_1_ADJ_DDR3},
	{CTRL_MODULE_CORE_PAD_CONTROL_DDRCH2_0, CTRL_DDRCH2_0_ADJ_DDR3},
	{CTRL_MODULE_CORE_PAD_CONTROL_DDRCH2_1, CTRL_DDRCH2_1_ADJ_DDR3},

	{CONTROL_LPDDR2CH1_0, CTRL_LPDDR2CH1_0_ADJ_DDR3},
	{CONTROL_LPDDR2CH1_1, CTRL_LPDDR2CH1_1_ADJ_DDR3},

	{CTRL_MODULE_CORE_PAD_CONTROL_DDRIO_0, CTRL_DDRIO_0_ADJ_DDR3},
	{CTRL_MODULE_CORE_PAD_CONTROL_DDRIO_1, CTRL_DDRIO_1_ADJ_DDR3},
	{CTRL_MODULE_CORE_PAD_CONTROL_DDRIO_2, CTRL_DDRIO_2_ADJ_DDR3},

	{0, 0},
};

void setup_emif_config(void)
{
	writel(0x00000001, CM_EMIF_EMIF1_CLKCTRL);
	writel(0x00000001, CM_EMIF_EMIF2_CLKCTRL);
	if (!check_loop(0x00000700, 0x00000700, CM_EMIF_CLKSTCTRL)) {
		/* do nothing */
	}

	/* DMM/MA */
	writel(LISA_MAP0_2GBYTE_INTL128, DMM_LISA_MAP_REGISTER_0);
	writel(0x00000000, DMM_LISA_MAP_REGISTER_1);
	writel(0x00000000, DMM_LISA_MAP_REGISTER_2);
	writel(0x00000000, DMM_LISA_MAP_REGISTER_3);

	writel(LISA_MAP0_2GBYTE_INTL128, MA_LISA_MAP_REGISTER_0);
	writel(0x00000000, MA_LISA_MAP_REGISTER_1);
	writel(0x00000000, MA_LISA_MAP_REGISTER_2);
	writel(0x00000000, MA_LISA_MAP_REGISTER_3);

	set_modify(CONTROL_EMIF1_SDRAM_CONFIG_EXT, 0x0000C100, 0x0000C000);

	set_modify(EMIF1_SDRAM_CONFIG_2, 0x48000000, 0x00000000);
	writel(0x808022BA, EMIF1_SDRAM_CONFIG);

	writel(0x0A500000, EMIF1_OCP_CONFIG);

	writel(0x40000305, EMIF1_READ_WRITE_EXECUTION_THRESHOLD);

	writel(0x0E30400d, EMIF1_DDR_PHY_CONTROL_1);

	writel(0x772F6873, EMIF1_SDRAM_TIMING_1);
	writel(0x304A129A, EMIF1_SDRAM_TIMING_2);
	writel(0x02F7E45F, EMIF1_SDRAM_TIMING_3);

	writel(0x0000081A, EMIF1_SDRAM_REFRESH_CONTROL);

	writel(0x00050000, EMIF1_DLL_CALIB_CTRL);
	writel(0x100B3215, EMIF1_SDRAM_OUTPUT_Z_CONFIG);
	writel(0x08000A05, EMIF1_TEMP_ALERT_CONFIG);

	writel(0x04020080, EMIF1_EXT_PHY_CONTROL_1);
	writel(0x28C518A3, EMIF1_EXT_PHY_CONTROL_2);
	writel(0x518A3146, EMIF1_EXT_PHY_CONTROL_3);
	writel(0x0014628C, EMIF1_EXT_PHY_CONTROL_4);
	writel(0xC330CC33, EMIF1_EXT_PHY_CONTROL_5);
	writel(0x30CC330C, EMIF1_EXT_PHY_CONTROL_6);
	writel(0x00000CC3, EMIF1_EXT_PHY_CONTROL_7);
	writel(0x04010040, EMIF1_EXT_PHY_CONTROL_8);
	writel(0x01004010, EMIF1_EXT_PHY_CONTROL_9);
	writel(0x00001004, EMIF1_EXT_PHY_CONTROL_10);
	writel(0x19082019, EMIF1_EXT_PHY_CONTROL_14);
	writel(0x00190000, EMIF1_EXT_PHY_CONTROL_15);
	writel(0x08102040, EMIF1_EXT_PHY_CONTROL_16);
	writel(0x00000001, EMIF1_EXT_PHY_CONTROL_17);
	writel(0x540A8150, EMIF1_EXT_PHY_CONTROL_18);
	writel(0xA81502A0, EMIF1_EXT_PHY_CONTROL_19);
	writel(0x002A0540, EMIF1_EXT_PHY_CONTROL_20);
	writel(0x00000077, EMIF1_EXT_PHY_CONTROL_24);

	writel(0x0E30400d, EMIF1_DDR_PHY_CONTROL_1_SHADOW);
	writel(0x772F6873, EMIF1_SDRAM_TIMING_1_SHADOW);
	writel(0x304A129A, EMIF1_SDRAM_TIMING_2_SHADOW);
	writel(0x02F7E45F, EMIF1_SDRAM_TIMING_3_SHADOW);
	writel(0x0000081A, EMIF1_SDRAM_REFRESH_CONTROL_SHADOW);
	writel(0x00050000, EMIF1_DLL_CALIB_CTRL_SHADOW);
	writel(0x04020080, EMIF1_EXT_PHY_CONTROL_1_SHADOW);
	writel(0x28C518A3, EMIF1_EXT_PHY_CONTROL_2_SHADOW);
	writel(0x518A3146, EMIF1_EXT_PHY_CONTROL_3_SHADOW);
	writel(0x0014628C, EMIF1_EXT_PHY_CONTROL_4_SHADOW);
	writel(0xC330CC33, EMIF1_EXT_PHY_CONTROL_5_SHADOW);
	writel(0x30CC330C, EMIF1_EXT_PHY_CONTROL_6_SHADOW);
	writel(0x00000CC3, EMIF1_EXT_PHY_CONTROL_7_SHADOW);
	writel(0x04010040, EMIF1_EXT_PHY_CONTROL_8_SHADOW);
	writel(0x01004010, EMIF1_EXT_PHY_CONTROL_9_SHADOW);
	writel(0x00001004, EMIF1_EXT_PHY_CONTROL_10_SHADOW);
	writel(0x19082019, EMIF1_EXT_PHY_CONTROL_14_SHADOW);
	writel(0x00190000, EMIF1_EXT_PHY_CONTROL_15_SHADOW);
	writel(0x08102040, EMIF1_EXT_PHY_CONTROL_16_SHADOW);
	writel(0x00000001, EMIF1_EXT_PHY_CONTROL_17_SHADOW);
	writel(0x540A8150, EMIF1_EXT_PHY_CONTROL_18_SHADOW);
	writel(0xA81502A0, EMIF1_EXT_PHY_CONTROL_19_SHADOW);
	writel(0x002A0540, EMIF1_EXT_PHY_CONTROL_20_SHADOW);
	writel(0x00000077, EMIF1_EXT_PHY_CONTROL_24_SHADOW);

	writel(0x0000000A, EMIF1_LPDDR2_MODE_REG_CONFIG);
	writel(0x000000FF, EMIF1_LPDDR2_MODE_DATA);
	writel(0x8000000A, EMIF1_LPDDR2_MODE_REG_CONFIG);
	writel(0x000000FF, EMIF1_LPDDR2_MODE_DATA);
	writel(0x00000001, EMIF1_LPDDR2_MODE_REG_CONFIG);
	writel(0x000000C3, EMIF1_LPDDR2_MODE_DATA);
	writel(0x80000001, EMIF1_LPDDR2_MODE_REG_CONFIG);
	writel(0x000000C3, EMIF1_LPDDR2_MODE_DATA);
	writel(0x00000002, EMIF1_LPDDR2_MODE_REG_CONFIG);
	writel(0x00000006, EMIF1_LPDDR2_MODE_DATA);
	writel(0x80000002, EMIF1_LPDDR2_MODE_REG_CONFIG);
	writel(0x00000006, EMIF1_LPDDR2_MODE_DATA);
	writel(0x00000003, EMIF1_LPDDR2_MODE_REG_CONFIG);
	writel(0x00000001, EMIF1_LPDDR2_MODE_DATA);
	writel(0x80000003, EMIF1_LPDDR2_MODE_REG_CONFIG);
	writel(0x00000001, EMIF1_LPDDR2_MODE_DATA);
	writel(0x40000010, EMIF1_LPDDR2_MODE_REG_CONFIG);
	writel(0x00000000, EMIF1_LPDDR2_MODE_DATA);
	writel(0xC0000010, EMIF1_LPDDR2_MODE_REG_CONFIG);
	writel(0x00000000, EMIF1_LPDDR2_MODE_DATA);


	set_modify(CONTROL_EMIF2_SDRAM_CONFIG_EXT, 0x0000C100, 0x0000C000);
	set_modify(EMIF2_SDRAM_CONFIG_2, 0x48000000, 0x00000000);
	writel(0x808022BA, EMIF2_SDRAM_CONFIG);

	writel(0x0A500000, EMIF2_OCP_CONFIG);

	writel(0x40000305, EMIF2_READ_WRITE_EXECUTION_THRESHOLD);

	writel(0x00000000, EMIF2_DDR_PHY_CONTROL_2);
	writel(0x0E30400d, EMIF2_DDR_PHY_CONTROL_1);

	writel(0x772F6873, EMIF2_SDRAM_TIMING_1);
	writel(0x304A129A, EMIF2_SDRAM_TIMING_2);
	writel(0x02F7E45F, EMIF2_SDRAM_TIMING_3);

	writel(0x0000081A, EMIF2_SDRAM_REFRESH_CONTROL);

	writel(0x00050000, EMIF2_DLL_CALIB_CTRL);
	writel(0x100B3215, EMIF2_SDRAM_OUTPUT_Z_CONFIG);
	writel(0x08000A05, EMIF2_TEMP_ALERT_CONFIG);

	writel(0x04020080, EMIF2_EXT_PHY_CONTROL_1);
	writel(0x28C518A3, EMIF2_EXT_PHY_CONTROL_2);
	writel(0x518A3146, EMIF2_EXT_PHY_CONTROL_3);
	writel(0x0014628C, EMIF2_EXT_PHY_CONTROL_4);
	writel(0xC330CC33, EMIF2_EXT_PHY_CONTROL_5);
	writel(0x30CC330C, EMIF2_EXT_PHY_CONTROL_6);
	writel(0x00000CC3, EMIF2_EXT_PHY_CONTROL_7);
	writel(0x04010040, EMIF2_EXT_PHY_CONTROL_8);
	writel(0x01004010, EMIF2_EXT_PHY_CONTROL_9);
	writel(0x00001004, EMIF2_EXT_PHY_CONTROL_10);
	writel(0x19082019, EMIF2_EXT_PHY_CONTROL_14);
	writel(0x00190000, EMIF2_EXT_PHY_CONTROL_15);
	writel(0x08102040, EMIF2_EXT_PHY_CONTROL_16);
	writel(0x00000001, EMIF2_EXT_PHY_CONTROL_17);
	writel(0x540A8150, EMIF2_EXT_PHY_CONTROL_18);
	writel(0xA81502A0, EMIF2_EXT_PHY_CONTROL_19);
	writel(0x002A0540, EMIF2_EXT_PHY_CONTROL_20);
	writel(0x00000077, EMIF2_EXT_PHY_CONTROL_24);

	writel(0x0E30400d, EMIF2_DDR_PHY_CONTROL_1_SHADOW);
	writel(0x772F6873, EMIF2_SDRAM_TIMING_1_SHADOW);
	writel(0x304A129A, EMIF2_SDRAM_TIMING_2_SHADOW);
	writel(0x02F7E45F, EMIF2_SDRAM_TIMING_3_SHADOW);
	writel(0x0000081A, EMIF2_SDRAM_REFRESH_CONTROL_SHADOW);
	writel(0x00050000, EMIF2_DLL_CALIB_CTRL_SHADOW);

	writel(0x04020080, EMIF2_EXT_PHY_CONTROL_1_SHADOW);
	writel(0x28C518A3, EMIF2_EXT_PHY_CONTROL_2_SHADOW);
	writel(0x518A3146, EMIF2_EXT_PHY_CONTROL_3_SHADOW);
	writel(0x0014628C, EMIF2_EXT_PHY_CONTROL_4_SHADOW);
	writel(0xC330CC33, EMIF2_EXT_PHY_CONTROL_5_SHADOW);
	writel(0x30CC330C, EMIF2_EXT_PHY_CONTROL_6_SHADOW);
	writel(0x00000CC3, EMIF2_EXT_PHY_CONTROL_7_SHADOW);
	writel(0x04010040, EMIF2_EXT_PHY_CONTROL_8_SHADOW);
	writel(0x01004010, EMIF2_EXT_PHY_CONTROL_9_SHADOW);
	writel(0x00001004, EMIF2_EXT_PHY_CONTROL_10_SHADOW);
	writel(0x19082019, EMIF2_EXT_PHY_CONTROL_14_SHADOW);
	writel(0x00190000, EMIF2_EXT_PHY_CONTROL_15_SHADOW);
	writel(0x08102040, EMIF2_EXT_PHY_CONTROL_16_SHADOW);
	writel(0x00000001, EMIF2_EXT_PHY_CONTROL_17_SHADOW);
	writel(0x540A8150, EMIF2_EXT_PHY_CONTROL_18_SHADOW);
	writel(0xA81502A0, EMIF2_EXT_PHY_CONTROL_19_SHADOW);
	writel(0x002A0540, EMIF2_EXT_PHY_CONTROL_20_SHADOW);
	writel(0x00000077, EMIF2_EXT_PHY_CONTROL_24_SHADOW);

	writel(0x0000000A, EMIF2_LPDDR2_MODE_REG_CONFIG);
	writel(0x000000FF, EMIF2_LPDDR2_MODE_DATA);
	writel(0x8000000A, EMIF2_LPDDR2_MODE_REG_CONFIG);
	writel(0x000000FF, EMIF2_LPDDR2_MODE_DATA);
	writel(0x00000001, EMIF2_LPDDR2_MODE_REG_CONFIG);
	writel(0x000000C3, EMIF2_LPDDR2_MODE_DATA);
	writel(0x80000001, EMIF2_LPDDR2_MODE_REG_CONFIG);
	writel(0x000000C3, EMIF2_LPDDR2_MODE_DATA);
	writel(0x00000002, EMIF2_LPDDR2_MODE_REG_CONFIG);
	writel(0x00000006, EMIF2_LPDDR2_MODE_DATA);
	writel(0x80000002, EMIF2_LPDDR2_MODE_REG_CONFIG);
	writel(0x00000006, EMIF2_LPDDR2_MODE_DATA);
	writel(0x00000003, EMIF2_LPDDR2_MODE_REG_CONFIG);
	writel(0x00000001, EMIF2_LPDDR2_MODE_DATA);
	writel(0x80000003, EMIF2_LPDDR2_MODE_REG_CONFIG);
	writel(0x00000001, EMIF2_LPDDR2_MODE_DATA);
	writel(0x40000010, EMIF2_LPDDR2_MODE_REG_CONFIG);
	writel(0x00000000, EMIF2_LPDDR2_MODE_DATA);
	writel(0xC0000010, EMIF2_LPDDR2_MODE_REG_CONFIG);
	writel(0x00000000, EMIF2_LPDDR2_MODE_DATA);

}

static void configure_efuse(void)
{
	u32 reg;

	reg = readl(CONTROL_WKUP_STD_FUSE_DIE_ID1);
	switch (reg) {

	case 0x014E74EB: /* lead-lot (KFW7F) */
	case 0x014E74E8: /* 2nd lot  (KFW7C) */
	case 0x014FAE9A: /* 3rd lot  (KGH0A) */
	case 0x014E74EC: /* 4th lot  (KFW7G) */
		/*
		*  Adjust e-fuse settings because first samples are non-trimmed
		*/
		writel(EFUSE_COMPENSATION, CONTROL_EFUSE_1);
		writel(EFUSE_COMPENSATION, CONTROL_EFUSE_2);
		writel(EFUSE_COMPENSATION, CONTROL_EFUSE_3);
		writel(EFUSE_COMPENSATION, CONTROL_EFUSE_4);
		break;

	default:
		break;
	}
}


/* Note for omap5_ddr_init() :
	ES1.0 : This function is required for 5430 and 5432
	ES2.0 : This function is required for 5430 and 5432
		if CH is not used.
*/
void omap5_ddrio_init(struct ddr_io *ddrio_config)
{
	u32 reg;
	struct ddr_io *ddr_io;

	configure_efuse();

	/* DDR configuration : Adjust IOs for LPDDR2 */

	if (ddrio_config != NULL) {
		for (ddr_io = &ddrio_config[0]; ddr_io->reg > 0; ddr_io++)
			writel(ddr_io->value, ddr_io->reg);
	} else {
		/* Get external RAM interface type */
		reg = readl(EMIF1_SDRAM_CONFIG);
		if ((reg & SDRAM_TYPE_MASK) == SDRAM_TYPE_LPDDR2_S4) {
			/* DDR2 settings */
			for (ddr_io = &ddr2_io_default[0]; ddr_io->reg > 0;
								ddr_io++)
				writel(ddr_io->value, ddr_io->reg);
		} else if ((reg & SDRAM_TYPE_MASK) == SDRAM_TYPE_DDR3) {
			/* DDR3 settings */
			for (ddr_io = &ddr3_io_default[0]; ddr_io->reg > 0;
								ddr_io++)
				writel(ddr_io->value, ddr_io->reg);
		}
	}

	/* Wait some time for IOs to be configured */
	ldelay(100);
}
