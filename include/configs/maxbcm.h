/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2014 Stefan Roese <sr@denx.de>
 */

#ifndef _CONFIG_DB_MV7846MP_GP_H
#define _CONFIG_DB_MV7846MP_GP_H

#include <linux/sizes.h>

/*
 * High Level Configuration Options (easy to change)
 */

/*
 * TEXT_BASE needs to be below 16MiB, since this area is scrubbed
 * for DDR ECC byte filling in the SPL before loading the main
 * U-Boot into it.
 */

/* I2C */
#define CONFIG_I2C_MVTWSI_BASE0		MVEBU_TWSI_BASE

/* SPI NOR flash default params, used by sf commands */

/* Environment in SPI NOR flash */

#define PHY_ANEG_TIMEOUT	8000	/* PHY needs a longer aneg time */

/*
 * mv-common.h should be defined after CMD configs since it used them
 * to enable certain macros
 */
#include "mv-common.h"

/*
 * Memory layout while starting into the bin_hdr via the
 * BootROM:
 *
 * 0x4000.4000 - 0x4003.4000	headers space (192KiB)
 * 0x4000.4030			bin_hdr start address
 * 0x4003.4000 - 0x4004.7c00	BootROM memory allocations (15KiB)
 * 0x4007.fffc			BootROM stack top
 *
 * The address space between 0x4007.fffc and 0x400f.fff is not locked in
 * L2 cache thus cannot be used.
 */

/* SPL */
/* Defines for SPL */
#define CONFIG_SPL_MAX_SIZE		((128 << 10) - (CONFIG_SPL_TEXT_BASE - 0x40000000))

#define CONFIG_SPL_BSS_START_ADDR	(0x40000000 + (128 << 10))
#define CONFIG_SPL_BSS_MAX_SIZE		(16 << 10)

#ifdef CONFIG_SPL_BUILD
#define CONFIG_SYS_MALLOC_SIMPLE
#endif

#define CONFIG_SPL_STACK		(0x40000000 + ((192 - 16) << 10))
#define CONFIG_SPL_BOOTROM_SAVE		(CONFIG_SPL_STACK + 4)

/* SPL related SPI defines */

/* Enable DDR support in SPL (DDR3 training from Marvell bin_hdr) */
#define CONFIG_SYS_SDRAM_SIZE		SZ_1G
#define CONFIG_BOARD_ECC_SUPPORT	/* this board supports ECC */

#endif /* _CONFIG_DB_MV7846MP_GP_H */
