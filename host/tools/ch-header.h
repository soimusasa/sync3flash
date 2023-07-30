/*
 * Copyright (C) 2012, Texas Instruments, Inc.
 * Texas Instruments, <www.ti.com>
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

unsigned char basic_header[512] = {
	/* errata: bootstrap */
	0x7e, 0xff, 0x8f, 0xe2, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	/* Items CHSETTINGS : address 0x00000060 ; size 140B */
	0x80, 0x00, 0x00, 0x00, 0x8c, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x43, 0x48, 0x53, 0x45,
	0x54, 0x54, 0x49, 0x4e, 0x47, 0x53, 0x00, 0x00,
	/* Items CHRAM : address 0x000000EC ; size 204B */
	0x14, 0x01, 0x00, 0x00, 0xcc, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x43, 0x48, 0x52, 0x41,
	0x4d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	/* End of TOC */
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xc1, 0xc0, 0xc0, 0xc0, /* SectionKey */
#ifdef CONFIG_USE_CH_SETTINGS_CONFIG
	0x01, /* Valid */
#else
	0x00, /* invalid */
#endif
	0x02, /* Version */
	0x00, 0x00, /* Reserved */
	0xbd, 0x03, 0x00, 0x00, /* Flags */
	0x10, 0x01, 0x00, 0x00, /* CM_CLKSEL_CORE */
	0x00, 0x00, 0x00, 0x00, /* CM_BYPCLK_MPU */
	0x00, 0x00, 0x00, 0x00, /* CM_BYPCLK_IVA */
	0x00, 0x00, 0x00, 0x01, /* CM_MPU_CLK_CTRL */
	0x01, 0x00, 0x00, 0x00, /* CM_CLKSEL_USB */
	0x00, 0x00, 0x00, 0x00, /* CM_CLKMODE_DPLL_MPU */
	0x00, 0x00, 0x00, 0x00, /* CM_AUTOIDLE_DPLL_MPU */
	0x02, 0x7d, 0x00, 0x00, /* CM_CLKSEL_DPLL_MPU */
	0x01, 0x00, 0x00, 0x00, /* CM_DIV_M2_DPLL_MPU */
	0x00, 0x00, 0x00, 0x00, /* CM_CLKMODE_DPLL_CORE */
	0x00, 0x00, 0x00, 0x00, /* CM_AUTOIDLE_DPLL_CORE */
	0x0b, 0x99, 0x02, 0x00, /* CM_CLKSEL_DPLL_CORE */
	0x18, 0x00, 0x00, 0x00, /* CM_DIV_M2_DPLL_CORE */
	0x05, 0x00, 0x00, 0x00, /* CM_DIV_M3_DPLL_CORE */
	0x08, 0x00, 0x00, 0x00, /* CM_DIV_H11_DPLL_CORE */
	0x04, 0x00, 0x00, 0x00, /* CM_DIV_H12_DPLL_CORE */
	0x3e, 0x00, 0x00, 0x00, /* CM_DIV_H13_DPLL_CORE */
	0x05, 0x00, 0x00, 0x00, /* CM_DIV_H14_DPLL_CORE */
	0x06, 0x00, 0x00, 0x00, /* CM_DIV_H21_DPLL_CORE */
	0x05, 0x00, 0x00, 0x00, /* CM_DIV_H22_DPLL_CORE */
	0x07, 0x00, 0x00, 0x00, /* CM_DIV_H23_DPLL_CORE */
	0x06, 0x00, 0x00, 0x00, /* CM_DIV_H24_DPLL_CORE */
	0x00, 0x00, 0x00, 0x00, /* CM_CLKMODE_DPLL_PER */
	0x00, 0x00, 0x00, 0x00, /* CM_AUTOIDLE_DPLL_PER */
	0x00, 0x14, 0x00, 0x00, /* CM_CLKSEL_DPLL_PER */
	0x04, 0x00, 0x00, 0x00, /* CM_DIV_M2_DPLL_PER */
	0x03, 0x00, 0x00, 0x00, /* CM_DIV_M3_DPLL_PER */
	0x06, 0x00, 0x00, 0x00, /* CM_DIV_H11_DPLL_PER */
	0x04, 0x00, 0x00, 0x00, /* CM_DIV_H12_DPLL_PER */
	0x02, 0x00, 0x00, 0x00, /* CM_DIV_H14_DPLL_PER */
	0x00, 0x00, 0x00, 0x00, /* CM_CLKMODE_DPLL_USB */
	0x00, 0x00, 0x00, 0x00, /* CM_AUTOIDLE_DPLL_USB */
	0x07, 0x90, 0x01, 0x04, /* CM_CLKSEL_DPLL_USB */
	0x02, 0x00, 0x00, 0x00, /* CM_DIV_M2_DPLL_USB */
	0xc2, 0xc0, 0xc0, 0xc0, /* SectionKey */
#ifdef CONFIG_USE_CH_RAM_CONFIG
	0x01, /* Valid */
#else
	0x00, /* invalid */
#endif
	0x02, /* Version */
	0x00, 0x00, /* Reserved */
	0x32, 0x1b, 0x85, 0x61, /* SdramConfig */
	0x00, 0x00, 0x00, 0x08, /* SdramConfig2 */
	0x0d, 0x04, 0x00, 0x20, /* SdramRefresh */
	0x0d, 0x04, 0x00, 0x20, /* SdramRefreshShdw */
	0x6b, 0x26, 0xef, 0xce, /* SdramTim1 */
	0xda, 0x7f, 0x8f, 0x30, /* SdramTim2 */
	0xa8, 0x88, 0x7f, 0x02, /* SdramTim3 */
	0x6b, 0x26, 0xef, 0xce, /* SdramTim1Shdw */
	0xda, 0x7f, 0x8f, 0x30, /* SdramTim2Shdw */
	0xa8, 0x88, 0x7f, 0x02, /* SdramTim3Shdw */
	0x00, 0x00, 0x00, 0x00, /* PwrMgtCtrl */
	0x00, 0x00, 0x00, 0x00, /* PwrMgtCtrlShdw */
	0x0a, 0x40, 0x24, 0x00, /* DdrPhyCtrl1 */
	0x00, 0x00, 0x00, 0x00, /* DdrPhyCtrl2 */
	0x0a, 0x40, 0x24, 0x00, /* DdrPhyCtrl1Shdw */
	0x00, 0x01, 0x04, 0x04, /* ExtPhyCtrl1 */
	0x00, 0x00, 0x00, 0x00, /* ExtPhyCtrl2 */
	0x00, 0x00, 0x00, 0x00, /* ExtPhyCtrl3 */
	0x00, 0x00, 0x00, 0x00, /* ExtPhyCtrl4 */
	0x40, 0x00, 0x01, 0x04, /* ExtPhyCtrl5 */
	0x10, 0x40, 0x00, 0x01, /* ExtPhyCtrl6 */
	0x04, 0x10, 0x00, 0x00, /* ExtPhyCtrl7 */
	0x40, 0x00, 0x01, 0x04, /* ExtPhyCtrl8 */
	0x10, 0x40, 0x00, 0x01, /* ExtPhyCtrl9 */
	0x04, 0x10, 0x00, 0x00, /* ExtPhyCtrl10 */
	0x00, 0x00, 0x00, 0x00, /* ExtPhyCtrl11 */
	0x00, 0x00, 0x00, 0x00, /* ExtPhyCtrl12 */
	0x00, 0x00, 0x00, 0x00, /* ExtPhyCtrl13 */
	0x80, 0x00, 0x08, 0x80, /* ExtPhyCtrl14 */
	0x00, 0x08, 0x80, 0x00, /* ExtPhyCtrl15 */
	0x40, 0x20, 0x10, 0x08, /* ExtPhyCtrl16 */
	0x02, 0x00, 0x00, 0x00, /* ExtPhyCtrl17 */
	0x00, 0x00, 0x00, 0x00, /* ExtPhyCtrl18 */
	0x00, 0x00, 0x00, 0x00, /* ExtPhyCtrl19 */
	0x00, 0x00, 0x00, 0x00, /* ExtPhyCtrl20 */
	0x00, 0x00, 0x00, 0x00, /* ExtPhyCtrl21 */
	0x00, 0x00, 0x00, 0x00, /* ExtPhyCtrl22 */
	0x00, 0x00, 0x00, 0x00, /* ExtPhyCtrl23 */
	0x57, 0x00, 0x00, 0x00, /* ExtPhyCtrl24 */

	0x6c, 0x7c, 0x7c, 0x7c, /* ExtPhyCtrl25 */
	0x65, 0x64, 0x64, 0x64, /* ExtPhyCtrl26 */
	0x65, 0x64, 0x64, 0x64, /* ExtPhyCtrl27 */
	0xa7, 0x41, 0x00, 0x00, /* ExtPhyCtrl28 */
	0x00, 0x00, 0x00, 0x00, /* ExtPhyCtrl29 */
	0x00, 0x00, 0x00, 0x00, /* ExtPhyCtrl30 */
	0x00, 0x00, 0x00, 0x00, /* ModeReg */
	0x02, 0x00, 0x00, 0x00, /* CoreFreqConfigM2Div */
	0x00, 0x01, 0x74, 0x80, /* DMMLisaMap0 */
	0x05, 0x00, 0x00, 0x00, /* Flags */
};

