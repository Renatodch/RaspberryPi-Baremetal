#include "string.h"
#include "Dev.h"
#include "BCM.h"
#include "delay.h"
#include "uart.h"


#define GPSET_0 		((volatile unsigned *)(GP_BASE + 0x1C))
#define GPCLR_0 		((volatile unsigned *)(GP_BASE + 0x28))
void toggle(volatile unsigned int t, unsigned int val){
	
	asm (
		"mov x4,%[val]" "\n\t"
		"cmp %[t],#0" "\n\t"
		"b.eq 1f" "\n\t"
		"b 2f" "\n\t"
		"1: mov x5,%[set]" "\n\t"
		"b 3f" 				"\n\t"
		"2: mov x5,%[clr]" "\n\t"
		"3: str x4,[x5]"   "\n\t"
		::[set]"r"(GPSET_0),
		  [clr]"r"(GPCLR_0),
		  [t]"r"(t),
		  [val]"r"(val)
		: "x4","cc"
		);	
}

int main ( void )
{
	char msg[23] = "Hola";
	char str[23] ={0};
	register unsigned long cntpct_0,cntfrq_0;
    volatile unsigned int tmp;
	
	//strcpy(str,msg);

	uart_init();
	
    tmp=GPFSEL2;
    tmp&=~(7<<27);
    tmp|=1<<27;
    GPFSEL2 = tmp;

	tmp = 0;
	asm volatile ("mrs %0, cntpct_el0" : "=r" (cntpct_0));
	asm volatile ("mrs %0, cntfrq_el0" : "=r" (cntfrq_0));
	
    while(1)
    {
		asm volatile ("mrs %0, cntpct_el0" : "=r" (cntpct_0));
		asm volatile ("mrs %0, cntfrq_el0" : "=r" (cntfrq_0));
		if(cntfrq_0!=0)
			GPSET0 = 1<<29;
		
		//tmp ^= 1;
		//toggle(tmp,1<<29);
		_printf("cntpct_0 : %d\r\n",cntpct_0);
		_printf("cntfrq_0 : %d\r\n",cntfrq_0);
		
	    wait_msec(1000000);

    }
    return(0);
}