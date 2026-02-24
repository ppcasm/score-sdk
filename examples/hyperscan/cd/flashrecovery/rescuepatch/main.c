/*

This is part of the Mattel HyperScan SDK by ppcasm (ppcasm@gmail.com)

This example is part of the FlashRescue project. It's the logic for the recovery mode, please see the FlashRescue example to
better understand what this is.   
 
*/

#include "score7_registers.h"
#include "score7_constants.h"
#include "hyperscan/hyperscan.h"

// HyperScan firmware callback functions
#define drvusbh_initial() ((int (*)(void))0xA0001460)()

// This is the address where to go to reach the embedded USB loader code
// if it exists in the firmware
#define USB_LOADER_ADDRESS 0xA00F5D00

// This is the address that stores the OFW/CFW revision string
#define FW_REV_STRING_ADDRESS 0xA00383E4

// This is the address where we upload the OFW/CFW firmware to
// when using UART recovery
#define FW_UPLOAD_ADDRESS 0x800001FC

// This is the standard entry point address of the uploaded OFW/CFW
#define FW_ENTRY_ADDRESS 0xA0001000

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

//typedef enum {
//	false = 0, true = 1
//} bool;

static void uart_enable_interface() {
	*P_UART_INTERFACE_SEL |= SW_UART_UART;
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

void USB_Boot(void){

	// We must do some interrupt and GP setup with the firmware
	// that should already be loaded into mem prior to doing
	// anything USB related.
	asm("la r28, 0xA0045140");
	asm("ldi r4, 0x1");
	asm("mtcr r4, cr0");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop!");
	asm("nop");
	asm("la r4, 0xA0000000");
	asm("mtcr r4, cr3");
	
	// Now do USB init	
	*P_CLK_PLLAU_CONF |= C_PLLU_CLK_EN;
	*P_INT_MASK_CTRL1 &= ~C_INT_USB_DIS;

	// This firmware callback *SHOULD* return 0 if a USB device is plugged
	// in and has adequate power and properly initializes.
	if(!drvusbh_initial()){
		HS_LEDS(0xFF);
		print_string("USB Boot...\n");
		void (*usb_boot)(void) = (void *)USB_LOADER_ADDRESS;
		usb_boot();		
	}
	else{
		print_string("Default Boot...\n");
		void (*resume_boot)(void) = (void *)FW_ENTRY_ADDRESS;
		resume_boot();
	}
	
	// Should never happen...
	return;
}

int main()
{
	// Setup IOB port for correct port direction to get the CD door status
	*P_IOB_GPIO_SETUP = 0x3F3F3302;

	// Read CD door status
	if(*P_IOB_GPIO_INPUT&(1<<9)){
		// This is the address of the installed firmware revision string so that if
		// the CD door is CLOSED on boot we can check to see if it's been modified
		// to support USB loading
		unsigned int *rev_string = (unsigned int *)FW_REV_STRING_ADDRESS;
		
		// Simple check for "UMOD" firmware rev string, signaling CFW with USB loading support
		if(rev_string[0] == 0x444F4D55) USB_Boot();
		
		// If the CD door is CLOSED on boot and there's no CFW USB loader, then boot as normal
		print_string("Default Boot...\n");
		void (*resume_boot)(void) = (void *)FW_ENTRY_ADDRESS;
		resume_boot();
	}
	else{
		
		// Do this stuff if the CD door is OPENED on boot
		
		// Turn all LEDs ON
		HS_LEDS(0xFF);
		
		// Setup SDRAM for copying
		*P_MIU_SDRAM_SETUP1 = (*P_MIU_SDRAM_SETUP1 & 0xFFFF0000) | 0x4834; 
		
		// Enable UART
		uart_enable_interface();

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
		while (!(*P_UART_TXRX_STATUS & UART_RECEIVE_EMPTY));

		// Print "Ready! " over UART
		print_string("Recovery Boot...");

		int i = 0;
		
		// Define the LEDs value, and a count that we will use later
		u8 leds = 0;
		
		// Get and pack the size bytes of the binary about to be uploaded (comes from the python send script)
		u32 size = 0;
		size |= uart_read_byte() << 0;
		size |= uart_read_byte() << 8;
		size |= uart_read_byte() << 16;
		size |= uart_read_byte() << 24;

		// Print "...GO!" to let us know we did receive the 4 size bytes 
		print_string("...GO!\n");
		
		// Set the destination and ending address we intend to upload to in SDRAM
		u8 *dest = (u8 *)FW_UPLOAD_ADDRESS;
		
		// Download the binary data over UART, and "roll" the LEDs by 
		// having a count that ticks the LEDs forward by 1 for every 512
		// bytes received over UART
		for(i=0;i<size;i++){
			dest[i] = uart_read_byte();
			if(i % 512 == 0) HS_LEDS(1<<leds++);
			if(leds>=8) leds = 0;
		}

		*P_MIU_SDRAM_SETUP1 = (*P_MIU_SDRAM_SETUP1 & 0xFFFF0000) | 0x4B04;
		
		// Function pointer to our entry address
		void (*entry_point)(void) = (void *)FW_ENTRY_ADDRESS;
		
		// Turn off LEDs to let us know everything actually did complete
		// just in case something doesn't run, you'll have an indicator that 
		// at least let's you know everything ran proper
		HS_LEDS(0x00);

		// invalidate D-Cache
		asm("la r15, 0xA00001FC");
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

		// Start executing from defined entry point
		entry_point();
	}

return 0;		
}
