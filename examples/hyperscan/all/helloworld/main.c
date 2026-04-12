/*

This is part of the Mattel HyperScan SDK by ppcasm (ppcasm@gmail.com)

This example was coded by hyperscandev (https://hyperscandev.glitch.me)

This is the basic Hello World! example. It contains the very barebones code necessary to show "Hello World!" on the screen.

*/

#include <stdio.h>
#include "tv/tv.h"

#include <setjmp.h>

jmp_buf env;

void jump(void)
{
    printf("Inside jump()\n");
    longjmp(env, 42);
}

// Stupid framebuffer for now
//unsigned short *fb = (unsigned short *) 0xA0400000;

int main(){
	
	    int val = setjmp(env);

    if (val == 0)
    {
        printf("First return from setjmp\n");
        jump();
    }
    else
    {
        printf("Returned via longjmp: %d\n", val);
    }

	for(;;);
    return 0;
	//int nExitCode = 0;
	/************************************************************************/
	/*   TODO: add your code here                                           */
	/************************************************************************/
	
	/*
	 Set TV output up with RGB565 color scheme and make set all framebuffers
	 to stupid framebuffer address, TV_Init will select the first framebuffer
	 as default.
	*/
	//tv_init(RESOLUTION_640_480, COLOR_RGB565, 0xA0400000, 0xA0400000, 0xA0400000);

	//int i = 0;
	//while(1){
				
		// Print text on TV
		//tv_print(fb, 28, 2, "Hello World!");
		//for(i=0;i<=10000;i++);
		//printf("NEWLIB WORKING!\n");
				
	//}
		
	//return nExitCode;
}
