/* Enable to make ^Z dump the inode table for debug */
#undef CONFIG_IDUMP
/* Enable to make ^A drop back into the monitor */
#undef CONFIG_MONITOR
/* Profil syscall support (not yet complete) */
#undef CONFIG_PROFIL
/* Multiple processes in memory at once */
#define CONFIG_MULTI
/* Single tasking - for now while we get it booting */
#undef CONFIG_SINGLETASK
/* Use C helpers for usermem */
#undef CONFIG_USERMEM_C

/* We use flexible 16K banks so use the helper */
#define CONFIG_BANK16
#define CONFIG_BANKS	4
#define MAX_MAPS 32-3
#define MAPBASE 0x0000
/* And swapping */
/* #define SWAPDEV  2051	 */
#define SWAP_SIZE   0x62
/* FIXME */
#define SWAPBASE    0x0000	/* We swap the lot in one, include the */
#define SWAPTOP	    0xC300	/* uarea so its a round number of sectors */
#define UDATA_BLOCKS	0	/* We swap the uarea in the data */
#define UDATA_SWAPSIZE	0
#define MAX_SWAPS	32
#define swap_map(x)  ((uint8_t *)(x & 0x3fff ))

/* The Drivewire block dev rawmode=1 doesn't work just now
   with the bank16k.c memory layout (yet), so we have to
   use legacy binary loading... */
#define CONFIG_LEGACY_EXEC


/* Video terminal, not a serial tty */
#define CONFIG_VT
#define CONFIG_VT_MULTI
/* We want the 8x8 font */
// #define CONFIG_VT_SIMPLE
/* Vt definitions */
#define VT_BASE      (uint8_t *)0xb400
#define VT_WIDTH	curpty->width
#define VT_HEIGHT	curpty->height
#define VT_RIGHT	curpty->right
#define VT_BOTTOM	curpty->bottom
#define VT_INITIAL_LINE 0

extern unsigned char vt_map( unsigned char c );
#define VT_MAP_CHAR(x)  vt_map(x)

#define TICKSPERSEC 60      /* Ticks per second */
#define PROGBASE    0x0100  /* also data base */
#define PROGTOP     0xe000  /* Top of program, base of U_DATA */
#define PROGLOAD    0x0100  /* ??? */

#define BOOT_TTY (512 + 1)   /* Set this to default device for stdio, stderr */
                          /* In this case, the default is the first TTY device */
                            /* Temp FIXME set to serial port for debug ease */

/* Boot devices */
#define BOOTDEVICENAMES "hd#,,,,,,,,dw"



/* We need a tidier way to do this from the loader */
#define CMDLINE	0x88	  /* Location of root dev name */

/* Device parameters */
#define NUM_DEV_TTY 10
#define TTYDEV   BOOT_TTY /* Device used by kernel for messages, panics */
#define NBUFS    6       /* Number of block buffers */
#define NMOUNTS	 4	  /* Number of mounts at a time - nothing mountable! */

#define CONFIG_COCO_KBD   /* Use CoCo key maps rather than Dragon */


/* Drivewire Defines */

#define DW_VSER_NUM 4     /* No of Virtual Serial Ports */
#define DW_VWIN_NUM 4     /* No of Virtual Window Ports */
#define DW_MIN_OFF  3     /* Minor number offset */

/* Block device define */
#define MAX_BLKDEV  4     /* 2 IDE + 2 SDC */
#define DEVICE_IDE        /* enable if IDE interface present */

#define platform_discard()
