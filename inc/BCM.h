#ifndef __BCM_H
#define __BCM_H


#define MMIO_BASE       0x3F000000
#define GP_BASE (MMIO_BASE + 0x200000)
#define MU_BASE (MMIO_BASE + 0x215000)

/*mini UART*/
#define AUX_ENB (*(volatile unsigned *)(MU_BASE + 0x04))
#define MU_IO   (*(volatile unsigned *)(MU_BASE + 0x40))
#define MU_LCR  (*(volatile unsigned *)(MU_BASE + 0x4c))
#define MU_LSR  (*(volatile unsigned *)(MU_BASE + 0x54))
#define MU_CNTL (*(volatile unsigned *)(MU_BASE + 0x60))
#define MU_BAUD (*(volatile unsigned *)(MU_BASE + 0x68))

/*GPIO*/
#define GPFSEL1 	(*(volatile unsigned *)(GP_BASE + 0x04))
#define GPFSEL2 	(*(volatile unsigned *)(GP_BASE + 0x08))
#define GPSET0 		(*(volatile unsigned *)(GP_BASE + 0x1C))
#define GPCLR0 		(*(volatile unsigned *)(GP_BASE + 0x28))
#define GPPUD   	(*(volatile unsigned *)(GP_BASE + 0x94))
#define GPPUDCLK0   (*(volatile unsigned *)(GP_BASE + 0x98))
#define GPPUDCLK1   ((volatile unsigned int*)(GP_BASE + 9C))

/*PL011 UART*/
#define UART0_DR        (*(volatile unsigned int*)(MMIO_BASE+0x00201000))
#define UART0_FR        (*(volatile unsigned int*)(MMIO_BASE+0x00201018))
#define UART0_IBRD      (*(volatile unsigned int*)(MMIO_BASE+0x00201024))
#define UART0_FBRD      (*(volatile unsigned int*)(MMIO_BASE+0x00201028))
#define UART0_LCRH      (*(volatile unsigned int*)(MMIO_BASE+0x0020102C))
#define UART0_CR        (*(volatile unsigned int*)(MMIO_BASE+0x00201030))
#define UART0_IMSC      (*(volatile unsigned int*)(MMIO_BASE+0x00201038))
#define UART0_ICR       (*(volatile unsigned int*)(MMIO_BASE+0x00201044))

/*mailbox*/
#define VIDEOCORE_MBOX  (MMIO_BASE+0x0000B880)
#define MBOX_READ       (*(volatile unsigned int*)(VIDEOCORE_MBOX+0x0))
#define MBOX_POLL       (*(volatile unsigned int*)(VIDEOCORE_MBOX+0x10))
#define MBOX_SENDER     (*(volatile unsigned int*)(VIDEOCORE_MBOX+0x14))
#define MBOX_STATUS     (*(volatile unsigned int*)(VIDEOCORE_MBOX+0x18))
#define MBOX_CONFIG     (*(volatile unsigned int*)(VIDEOCORE_MBOX+0x1C))
#define MBOX_WRITE      (*(volatile unsigned int*)(VIDEOCORE_MBOX+0x20))
#define MBOX_RESPONSE   0x80000000
#define MBOX_FULL       0x80000000
#define MBOX_EMPTY      0x40000000

/*BCM Timer*/
#define SYSTMR_LO        ((volatile unsigned int*)(MMIO_BASE+0x00003004))
#define SYSTMR_HI        ((volatile unsigned int*)(MMIO_BASE+0x00003008))
#endif 