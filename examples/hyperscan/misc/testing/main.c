/*

This is part of the Mattel HyperScan SDK by ppcasm (ppcasm@gmail.com)

This is just a test space. Do not use.   
 
*/

#include "score7_registers.h"
#include "score7_constants.h"
#include "hyperscan/hyperscan.h"

// This is the address where we upload the UART app for HyperScanOS
#define UPLOAD_ADDRESS 0x800901FC

// This is the standard entry point address of the uploaded OFW/CFW
#define ENTRY_ADDRESS 0xA0091000

#define BIT(n)	(1 << n)

#define SW_UART_UART	BIT(24)

#define UART_BUSY	BIT(3)
#define UART_TRANSMIT_EMPTY	BIT(7)
#define UART_TRANSMIT_FULL	BIT(5)
#define UART_RECEIVE_EMPTY	BIT(4)
#define UART_RECEIVE_FULL	BIT(6)

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef volatile u32 vu32;

static void uart_enable_interface() {
	*P_UART_INTERFACE_SEL |= SW_UART_UART;
	//*P_UART_MODE_CTRL = 0x1066;
	//0001000001100110
}

static void uart_wait_nonbusy() {
	u32 status = *P_UART_TXRX_STATUS;
	while (status & UART_BUSY || status & UART_TRANSMIT_FULL || !(status & UART_TRANSMIT_EMPTY)) {
		status = *P_UART_TXRX_STATUS;
	}
}

static void uart_write_byte(u32 c) {
	*P_UART_TXRX_DATA = c;
	uart_wait_nonbusy();
}

static void print_string(const char *str) {
	while (*str) {
		uart_write_byte(*str++);
	}
}

static u8 uart_read_byte() {
	while (*P_UART_TXRX_STATUS & UART_RECEIVE_EMPTY);
	return *P_UART_TXRX_DATA;
}

int main()
{
    void (*draw_string)(unsigned int,
                    unsigned int,
                    const char *) =
    (void (*)(unsigned int,
              unsigned int,
              const char *))0xA000D2B0;
              
    HS_LEDS(0xFF);
    
    // Save interrupt masks
    unsigned int saved_mask1 = *P_INT_MASK_CTRL1;
    //unsigned int saved_mask2 = *P_INT_MASK_CTRL2;
    
    // Mask all interrupts
    *P_INT_MASK_CTRL1 = 0xFFFFFFFFu;
    //*P_INT_MASK_CTRL2 = 0xFFFFFFFFu;
    
    draw_string(8, 4, "Upload binary through UART now");
    
	// Enable UART
	uart_enable_interface();
	
	//asm("la r15, 0xA00901FC");
		
    // invalidate D-Cache
	asm("cache 0x18, [r15, 0]");
	asm("nop");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop");
		
	//	invalidate I-Cache
	asm("cache 0x10, [r15, 0]");
	asm("nop");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop");

	// Drain write buffer
	asm("cache 0x1A, [r15, 0]");
	asm("nop");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop");
	
	// Flush UART
	//while (!(*P_UART_TXRX_STATUS & UART_RECEIVE_EMPTY));
    
    uart_wait_nonbusy();
    
	// Print over UART
	print_string("Upload binary now... ");

	int i = 0;
		
	// Define the LEDs value, and a count that we will use later
	u8 leds = 0;
		
	// Get and pack the size bytes of the binary about to be uploaded (comes from the python send script)
	u32 size = 0;
	uart_read_byte();
	size |= uart_read_byte() << 0;
	size |= uart_read_byte() << 8;
	size |= uart_read_byte() << 16;
	size |= uart_read_byte() << 24;

    //size = 72440;
	// Print "...GO!" to let us know we did receive the 4 size bytes 
	print_string("...GO!\n");
		
	// Set the destination and ending address we intend to upload to in SDRAM
	u8 *dest = (u8 *)UPLOAD_ADDRESS;
		
	// Download the binary data over UART, and "roll" the LEDs by 
	// having a count that ticks the LEDs forward by 1 for every 512
	// bytes received over UART
	for(i=0;i<size;i++){
		dest[i] = uart_read_byte();
		if(i % 512 == 0) HS_LEDS(1<<leds++);
		if(leds>=8) leds = 0;
	}

	// Function pointer to our entry address
	void (*entry_point)(void) = (void *)ENTRY_ADDRESS;
		
	// Turn off LEDs to let us know everything actually did complete
	// just in case something doesn't run, you'll have an indicator that 
	// at least let's you know everything ran proper
	HS_LEDS(0x00);

    asm("la r15, 0xA00901FC");
        
	// invalidate D-Cache
	asm("cache 0x18, [r15, 0]");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
		
	//	invalidate I-Cache
	asm("la r15, 0xA00001FC");
	asm("cache 0x10, [r15, 0]");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
		
	// Drain write buffer
	asm("la r15, 0xA00001FC");
	asm("cache 0x1A, [r15, 0]");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");

    // Restore interrupt masks
    *P_INT_MASK_CTRL1 = saved_mask1;
    //*P_INT_MASK_CTRL2 = saved_mask2;
    
	// Start executing from defined entry point
	entry_point();

return 0;		
}
