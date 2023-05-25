;extern void PUT32 ( unsigned int, unsigned int );
;extern unsigned int GET32 ( unsigned int );
;extern void dummy ( unsigned int );

#define IO_BASE 0x3f000000
#define GP_BASE (IO_BASE + 0x200000)
#define MU_BASE (IO_BASE + 0x215000)

#define AUX_ENB (*(volatile unsigned *)(MU_BASE + 0x04))
#define MU_IO   (*(volatile unsigned *)(MU_BASE + 0x40))
#define MU_LCR  (*(volatile unsigned *)(MU_BASE + 0x4c))
#define MU_LSR  (*(volatile unsigned *)(MU_BASE + 0x54))
#define MU_CNTL (*(volatile unsigned *)(MU_BASE + 0x60))
#define MU_BAUD (*(volatile unsigned *)(MU_BASE + 0x68))

#define GPFSEL1 (*(volatile unsigned *)(GP_BASE + 0x04))
#define GPFSEL2 (*(volatile unsigned *)(GP_BASE + 0x08))
#define GPSET0 (*(volatile unsigned *)(GP_BASE + 0x1C))
#define GPCLR0 (*(volatile unsigned *)(GP_BASE + 0x28))
#define GPPUD   (*(volatile unsigned *)(GP_BASE + 0x94))
#define GPPUDCLK0   (*(volatile unsigned *)(GP_BASE + 0x98))
//-------------------------------------------------------------------------
int main ( void )
{
    volatile unsigned int ra;

    ra=GPFSEL2;
    ra&=~(7<<27);
    ra|=1<<27;
    GPFSEL2 = ra;

    while(1)
    {
        GPSET0 = 1<<29;
      
	   for(ra=0;ra<0x50000;ra++){
			asm volatile("nop");
		}
		
        GPCLR0 = 1<<29;
		
        for(ra=0;ra<0x50000;ra++) {
			asm volatile("nop");
		}
		
    }
    return(0);
}