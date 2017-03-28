#include "inter_api.h"

// Replace this with the BASE address assigned to this IP by Microblaze
unsigned int BASE = 0x44A00000;

// This initializes the Interrupt Controller IP by setting the HIE, ME bits
void initialize()
{
	volatile unsigned int *  MER = (unsigned int *) (BASE + 0x0000001C);
	*MER = 0x00000003;
}

// This enables the interrupts which the processor needs to be notified about
void enable_interrupt(unsigned int enables)
{
	volatile unsigned int * const IER = (unsigned int *) (BASE + 0x00000008);
	*IER = enables;
}

// This reads the interrupts whic are yet to be handled by the processor
unsigned int read_pending()
{
	volatile unsigned int * IPR = (unsigned int *) (BASE + 0x00000004);
	return *IPR;
}

// This clears the interrupts after they have been dealt with
void acknowledge(unsigned acks)
{
	volatile unsigned int * const IAR = (unsigned int *) (BASE + 0x0000000C);
	*IAR = acks;
}

// This reads the interrupts that have occurred and registered in the IP
unsigned int status()
{
	volatile unsigned int * ISR = (unsigned int *) (BASE + 0x00000000);
	return *ISR;
}
