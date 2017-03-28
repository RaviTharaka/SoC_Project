#ifndef __INTER_API_H_
#define __INTER_API_H_

void initialize();

void enable_interrupt(unsigned int enables);

unsigned int read_pending();

void acknowledge(unsigned acks);

unsigned int status();

#endif
