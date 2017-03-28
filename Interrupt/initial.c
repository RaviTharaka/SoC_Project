#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"

#include "inter_api.h"

// This is a test code file for Miroblaze
// Should be run in debug on Vivado SDK

int main()
{
    init_platform();

    initialize();
    enable_interrupt(0x00000001);

    // hardware push interrupt
    unsigned int val = read_pending();

    acknowledge(0x00000001);

    cleanup_platform();
    return 0;
}
