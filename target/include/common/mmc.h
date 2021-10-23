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

#ifndef _MMC_H_
#define _MMC_H_

/* HSMMC defines */
#define OMAP_HSMMC_BLK_OFFSET		0x0204
#define OMAP_HSMMC_PSTATE_OFFSET	0x0224
#define MMCHS_ADMASAL_OFFSET		0x0258
#define MMCHS_ARG_OFFSET		0x0208
#define MMCHS_CMD_OFFSET		0x020C
#define MMCHS_HCTL_OFFSET		0x0228
#define MMCHS_STAT_OFFSET		0x0230
#define MMCHS_CONN_OFFSET		0x012c

/* Decriptor table defines */
#define MMCADMA_DESC_TBL_VALID		(1 << 0)
#define MMCADMA_DESC_TBL_END		(1 << 1)
#define MMCADMA_DESC_TBL_INT		(1 << 2)
#define MMCADMA_DESC_TBL_ACT1		(1 << 4)
#define MMCADMA_DESC_TBL_ACT2		(1 << 5)

/* DMA Defines */
#define MMCADMA_HCTL_DMAS_32BIT		(1 << 4)
#define MMCADMA_CONN_DMA_MNS		(1 << 20)

/* Status register */
#define MMC_STAT_TC			(1 << 1)
#define MMC_STAT_CC			(1 << 0)
#define MMC_STAT_ERR			(1 << 15)

/* PState register */
#define MMCHS_PSTATE_READ_ACT		(1 << 9)
#define MMCHS_PSTATE_CMD_LVL		(1 << 24)

#define HSMMC_BLK_NBLK_MASK	0xFFFF0000
#define HSMMC_BLK_NBLK_SHIFT	16

/* MMC sector defines */
#define MMCSD_SECTOR_SIZE_SHIFT	(9)
#define MMCSD_SECTOR_SIZE	(1 << MMSD_SECTOR_SIZE_SHIFT)

/* params to mmc_configure() function */
#define MMCSD_CONFIGID_SETCLOCK		(0)
#define MMCSD_CLOCK_DIVIDER_19_2MHZ	((96+1)*1000/19200)
#define MMCSD_CLOCK_DIVIDER_48MHz	((96+1)*1000/48000)

#define MMCSD_CONFIGID_SETBUSWIDTH	(1)
#define MMCSD_1BIT_BUS_WIDTH_SUPPORTED	(1 << 0)
#define MMCSD_4BIT_BUS_WIDTH_SUPPORTED	(1 << 1)
#define MMCSD_8BIT_BUS_WIDTH_SUPPORTED	(1 << 2)
#define MMCSD_CONFIGID_SETPARTITION	(3)
#define MMCSD_CONFIGID_SETDDRMODE	(4)
#define MMCSD_4BIT_DDR_BUS_WIDTH_SUPPORTED	(1 << 3)
#define MMCSD_8BIT_DDR_BUS_WIDTH_SUPPORTED	(1 << 4)

/* MMC Command defines */
#define SET_FIELD(VAR, FIELD)			((VAR << FIELD##__POS) & FIELD)

#define MMCHS__MMCHS_PSTATE_CMDI		0x1
#define MMCHS__MMCHS_PSTATE_CMDI__POS	0
#define MMCHS__MMCHS_PSTATE_CMDI_CHECK	0x1
#define MMCHS_MMCHS_PSTATE_CMDI_CHECK	\
				SET_FIELD(MMCHS__MMCHS_PSTATE_CMDI_CHECK, \
						MMCHS__MMCHS_PSTATE_CMDI)

#define MMCHS__MMCHS_PSTATE_DATI		0x2
#define MMCHS__MMCHS_PSTATE_DATI__POS	1
#define MMCHS__MMCHS_PSTATE_DATI_CHECK	0x1
#define MMCHS_MMCHS_PSTATE_DATI_CHECK	\
					SET_FIELD(MMCHS__MMCHS_PSTATE_DATI_CHECK, \
							MMCHS__MMCHS_PSTATE_DATI)

#define MMCHS__MMCHS_PSTATE_DLA		0x4
#define MMCHS__MMCHS_PSTATE_DLA__POS	2
#define MMCHS__MMCHS_PSTATE_DLA_CHECK	0x1
#define MMCHS_MMCHS_PSTATE_DLA_CHECK	\
					SET_FIELD(MMCHS__MMCHS_PSTATE_DLA_CHECK, \
							MMCHS__MMCHS_PSTATE_DLA)

#define MMCHS_WAIT_CARD_BUSY_DEASSERT	(MMCHS_MMCHS_PSTATE_CMDI_CHECK | \
						MMCHS_MMCHS_PSTATE_DATI_CHECK | \
						MMCHS_MMCHS_PSTATE_DLA_CHECK)

#define MMCHS__MMCHS_CMD__INDX			0x3F000000
#define MMCHS__MMCHS_CMD__INDX__POS		24

#define MMCHS__MMCHS_CMD__CMD_TYPE		0xC00000
#define MMCHS__MMCHS_CMD__CMD_TYPE__POS		22

#define MMCHS__MMCHS_CMD__CMD_TYPE__NORMAL	0x0
#define MMCHS_MMCHS_CMD_CMD_TYPE_NORMAL		\
				SET_FIELD(MMCHS__MMCHS_CMD__CMD_TYPE__NORMAL, \
						MMCHS__MMCHS_CMD__CMD_TYPE)

#define MMCHS__MMCHS_CMD__RSP_TYPE		0x30000
#define MMCHS__MMCHS_CMD__RSP_TYPE__POS		16

#define MMCHS__MMCHS_CMD__RSP_TYPE__LGHT48	0x2
#define MMCHS_MMCHS_CMD_RSP_TYPE_LGHT48		\
				SET_FIELD(MMCHS__MMCHS_CMD__RSP_TYPE__LGHT48, \
						MMCHS__MMCHS_CMD__RSP_TYPE)

#define MMCHS__MMCHS_CMD__RSP_TYPE__BUSY48	0x3
#define MMCHS_MMCHS_CMD_RSP_TYPE_BUSY48		\
				SET_FIELD(MMCHS__MMCHS_CMD__RSP_TYPE__BUSY48, \
						MMCHS__MMCHS_CMD__RSP_TYPE)


#define MMCHS__MMCHS_CMD__CCCE			0x80000
#define MMCHS__MMCHS_CMD__CCCE__POS		19

#define MMCHS__MMCHS_CMD__CCCE__CHECK		0x1
#define MMCHS_MMCHS_CMD_CCCE_CHECK		\
				SET_FIELD(MMCHS__MMCHS_CMD__CCCE__CHECK, \
						MMCHS__MMCHS_CMD__CCCE)

#define MMCHS__MMCHS_CMD__CICE			0x100000
#define MMCHS__MMCHS_CMD__CICE__POS		20

#define MMCHS__MMCHS_CMD__CICE__CHECK		0x1
#define MMCHS_MMCHS_CMD_CICE_CHECK		\
				SET_FIELD(MMCHS__MMCHS_CMD__CICE__CHECK, \
						MMCHS__MMCHS_CMD__CICE)

#define MMCHS__MMCHS_CMD__DP			0x200000
#define MMCHS__MMCHS_CMD__DP__POS		21

#define MMCHS__MMCHS_CMD__DP__DATA		0x1
#define MMCHS_MMCHS_CMD_DP_DATA			\
				SET_FIELD(MMCHS__MMCHS_CMD__DP__DATA, \
						MMCHS__MMCHS_CMD__DP)

#define MMCHS__MMCHS_CMD__DDIR			0x10
#define MMCHS__MMCHS_CMD__DDIR__POS		4

#define MMCHS__MMCHS_CMD__DDIR__WRITE		0x0
#define MMCHS_MMCHS_CMD_DDIR_WRITE		\
				SET_FIELD(MMCHS__MMCHS_CMD__DDIR__WRITE, \
						MMCHS__MMCHS_CMD__DDIR)

#define MMCHS__MMCHS_CMD__DDIR__READ		0x1
#define MMCHS_MMCHS_CMD_DDIR_READ		\
				SET_FIELD(MMCHS__MMCHS_CMD__DDIR__READ, \
						MMCHS__MMCHS_CMD__DDIR)

#define MMCHS__MMCHS_CMD__DE			0x1
#define MMCHS__MMCHS_CMD__DE__POS		0

#define MMCHS__MMCHS_CMD__DE__ENABLE		0x1
#define MMCHS_MMCHS_CMD_DE_ENABLE		\
				SET_FIELD(MMCHS__MMCHS_CMD__DE__ENABLE, \
						MMCHS__MMCHS_CMD__DE)

#define MMCHS__MMCHS_CMD__BCE			0x2
#define MMCHS__MMCHS_CMD__BCE__POS		1

#define MMCHS__MMCHS_CMD__BCE__ENABLE		0x1
#define MMCHS_MMCHS_CMD_BCE_ENABLE		\
				SET_FIELD(MMCHS__MMCHS_CMD__BCE__ENABLE, \
						MMCHS__MMCHS_CMD__BCE)

#define MMCHS__MMCHS_CMD__ACEN			0xC
#define MMCHS__MMCHS_CMD__ACEN__POS		2

#define MMCHS__MMCHS_CMD__ACEN__ENABLECMD12	0x1
#define MMCHS_MMCHS_CMD_ACEN_ENABLECMD12 \
				SET_FIELD(MMCHS__MMCHS_CMD__ACEN__ENABLECMD12, \
						MMCHS__MMCHS_CMD__ACEN)

#define MMCHS__MMCHS_CMD__MSBS			0x20
#define MMCHS__MMCHS_CMD__MSBS__POS		5

#define MMCHS__MMCHS_CMD__MSBS__MULTIBLK	0x1
#define MMCHS_MMCHS_CMD_MSBS_MULTIBLK \
				SET_FIELD(MMCHS__MMCHS_CMD__MSBS__MULTIBLK, \
						MMCHS__MMCHS_CMD__MSBS)

#define MMCSD_CMDINDEX(i)		SET_FIELD(i, MMCHS__MMCHS_CMD__INDX)

#define MMCSD_CMDTYPE_NORMAL		(MMCHS_MMCHS_CMD_CMD_TYPE_NORMAL)

#define MMCSD_CMDRSP_TYPE_R1		(MMCHS_MMCHS_CMD_RSP_TYPE_LGHT48 | \
					MMCHS_MMCHS_CMD_CCCE_CHECK | \
					MMCHS_MMCHS_CMD_CICE_CHECK)

#define MMCSD_CMDRSP_TYPE_R3		(MMCHS_MMCHS_CMD_RSP_TYPE_BUSY48 | \
					MMCHS_MMCHS_CMD_CCCE_CHECK | \
					MMCHS_MMCHS_CMD_CICE_CHECK)

#define MMCSD_CMDDP_DATA		(MMCHS_MMCHS_CMD_DP_DATA)

#define MMCSD_CMDDDIR_WRITE		(MMCHS_MMCHS_CMD_DDIR_WRITE)
#define MMCSD_CMDDIR_READ		(MMCHS_MMCHS_CMD_DDIR_READ)

#define MMCSD_CMD18			(MMCSD_CMDINDEX(18) |	\
					MMCSD_CMDTYPE_NORMAL | \
					MMCSD_CMDRSP_TYPE_R1 | \
					MMCSD_CMDDP_DATA     | \
					MMCSD_CMDDIR_READ)

#define MMCSD_CMD24			(MMCSD_CMDINDEX(24) |	\
					MMCSD_CMDTYPE_NORMAL |	\
					MMCSD_CMDRSP_TYPE_R1 |	\
					MMCSD_CMDDP_DATA |	\
					MMCSD_CMDDDIR_WRITE)

#define MMCSD_CMD25			(MMCSD_CMDINDEX(25) |	\
					MMCSD_CMDTYPE_NORMAL |	\
					MMCSD_CMDRSP_TYPE_R3 |	\
					MMCSD_CMDDP_DATA |	\
					MMCSD_CMDDDIR_WRITE)

#define MMCSD_CMD32			(MMCSD_CMDINDEX(32) |	\
						MMCSD_CMDTYPE_NORMAL |	\
						MMCSD_CMDRSP_TYPE_R1 |	\
						MMCSD_CMDDDIR_WRITE)

#define MMCSD_CMD33			(MMCSD_CMDINDEX(33) |	\
						MMCSD_CMDTYPE_NORMAL |	\
						MMCSD_CMDRSP_TYPE_R1 |	\
						MMCSD_CMDDDIR_WRITE)

#define MMCSD_CMD35			(MMCSD_CMDINDEX(35) |	\
					MMCSD_CMDTYPE_NORMAL |	\
					MMCSD_CMDRSP_TYPE_R1 |	\
					MMCSD_CMDDDIR_WRITE)

#define MMCSD_CMD36			(MMCSD_CMDINDEX(36) |	\
					MMCSD_CMDTYPE_NORMAL |	\
					MMCSD_CMDRSP_TYPE_R1 |	\
					MMCSD_CMDDDIR_WRITE)

#define MMCSD_CMD38			(MMCSD_CMDINDEX(38) |	\
					MMCSD_CMDTYPE_NORMAL |	\
					MMCSD_CMDRSP_TYPE_R3 |	\
					MMCSD_CMDDDIR_WRITE)

#define MAX_SECTORS_PER_XFER		0xFFFF

#endif /* MMC_H */
