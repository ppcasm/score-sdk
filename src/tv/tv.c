#include "score7_registers.h"
#include "score7_constants.h"
#include "tv/tv.h"
#include "tv/font_8x16.h"

// =============================================================
//	void tv_clearscreen(unsigned short *fb)
//
//	This clears the TV screen. This needs to be fixed at some point
//	so as not to assume 640x480 resolution
// 
// 
//	void return
// =============================================================
void tv_clearscreen(unsigned short *fb){
	int i = 0;
	for(i=0;i<=640*480;i++){
		fb[i] = 0x0000;
	}
}

// =============================================================
//	void tv_init(unsigned int resolution, unsigned int colormode,
//	unsigned int fb1_addr, unsigned int fb2_addr, unsigned int fb3_addr);
//
//	This initializes basic TV output, then sets up some initial framebuffer
//	addresses (3), and sets color scheme, then selects fb1_addr as the 
//	default framebuffer.
// 
//
//	void return
// =============================================================
void tv_init(unsigned int resolution, unsigned int colormode, unsigned int fb1_addr, unsigned int fb2_addr, unsigned int fb3_addr){
	*P_TV_CLK_CONF = C_TV_CLK_EN | C_TV_RST_DIS; 	
	*P_TV_VIDEODAC_CTRL = C_TV_VIDEODAC_EN; 
	*P_TV_MODE_CTRL = C_TV_CTRL_EN 			
					| C_TV_NTSC_MODE 				
					| C_TV_INTERLACE_MODE 
					| C_TV_NTSC_TYPE 		
					| C_TV_LITTLE_ENDIAN
					| C_TV_VBLANKINGSINT_EN; 	

	*(volatile unsigned int *)0x88010000 |= 0x0001;
	if(resolution == RESOLUTION_640_480){
		*P_TV_MODE_CTRL |= C_TV_VGA_MODE;
	}
	
	if(resolution == RESOLUTION_320_240){
		*P_TV_MODE_CTRL |= C_TV_QVGA_MODE;
	}
	
	if(colormode == COLOR_RGB565){
		*P_TV_MODE_CTRL	|= 	C_TV_RGB_MODE 				
							| C_TV_RGB565_MODE;
	}

	tv_buffer_set(fb1_addr, fb2_addr, fb3_addr);
	tv_clearscreen((unsigned short *)fb1_addr);
	tv_buffer_sel(0);
}

// =============================================================
// 	void tv_buffer_set(unsigned int fb1_addr, unsigned int fb2_addr,
// 	unsigned int fb3_addr)
//
//	This sets the current framebuffer pointers (3)
//	
//
//	void return
// =============================================================
void tv_buffer_set(unsigned int fb1_addr, unsigned int fb2_addr, unsigned int fb3_addr){
	
	*P_TV_BUFFER_SA1 = fb1_addr;
	*P_TV_BUFFER_SA2 = fb2_addr;
	*P_TV_BUFFER_SA3 = fb3_addr;
}

// =============================================================
//	void tv_buffer_sel(unsigned int sel)
// 
//	This selects the current framebuffer
//
//	void return
// =============================================================
void tv_buffer_sel(unsigned int sel){
	
	*P_TV_BUFFER_SEL = sel;
}

// =============================================================
//	void tv_saturation(unsigned int satu)
// 
//	This sets TV saturation
//
//	void return
// =============================================================
void tv_saturation(unsigned int satu){
	
	*P_TV_SATURATION_SETUP = satu & 0x000000ff;
}

// =============================================================
//	void tv_hue(unsigned int hue)
// 
//	This sets TV hue
// 
//	void return
// =============================================================
void tv_hue(unsigned int hue){
	
	*P_TV_HUE_SETUP = hue & 0x000000ff;
}

// =============================================================
//	void tv_fade(unsigned int fade)
// 
//	This sets TV fade
// 
//	void return
// =============================================================
void tv_fade(unsigned int fade){
	
	*P_TV_FADE_SETUP = fade & 0x000000ff;
}

// =============================================================
//	void tv_print(unsigned int x, unsigned int y, unsigned char *text)
// 
//	Print to TV screen via low level framebuffer access
// 
//	void return
// =============================================================
void tv_print(unsigned short *fb, unsigned int x, unsigned int y, const char *text){
	
    short xx, yy;
    unsigned short colorz;
    while (*text) 
    {
        for (yy = 0; yy < 16; yy++) 
        {
	      for (xx = 0; xx < 8; xx++)
	      {
            if(font[(*text)*16+yy] & (1<<(8-xx))) colorz = 0xFFFF; else colorz = 0x0000; //fb[(y*16+yy)*640+(x*8+xx)];
	        fb[(y*16+yy)*640+(x*8+xx)] = colorz;
	      }
	}
	x++;
	text++;
    }
    
  return;
}

// =============================================================
//	void tv_printcolor(unsigned int x, unsigned int y, unsigned char *text, unsigned short color)
// 
//	Print to TV screen via low level framebuffer access, but with color
// 
//	void return
// =============================================================
void tv_printcolor(unsigned short *fb, unsigned int x, unsigned int y, const char *text, unsigned short color){
	
    short xx, yy;
    while (*text) 
    {
        for (yy = 0; yy < 16; yy++) 
        {
	      for (xx = 0; xx < 8; xx++)
	      {
            if(font[(*text)*16+yy] & (1<<(8-xx))) fb[(y*16+yy)*640+(x*8+xx)] = color; //fb[(y*16+yy)*640+(x*8+xx)];
	        
	      }
	}
	x++;
	text++;
    }
    
  return;
}

// =============================================================
//  void tv_printcolor(unsigned short *fb, unsigned int x, unsigned int y, 
//                     const char *text, unsigned short fgcolor, unsigned short bgcolor)
//
//  Print to TV screen via low level framebuffer access, with foreground
//  and background color
// =============================================================
void tv_printcolor(unsigned short *fb, unsigned int x, unsigned int y, 
                   const char *text, unsigned short fgcolor, unsigned short bgcolor) 
{
    short xx, yy;

    while (*text) 
    {
        for (yy = 0; yy < 16; yy++) 
        {
            for (xx = 0; xx < 8; xx++)
            {
                // Check the bit in the font
                if (font[(*text) * 16 + yy] & (1 << (8 - xx))) {
                    // Foreground pixel
                    fb[(y * 16 + yy) * 640 + (x * 8 + xx)] = fgcolor;
                } else {
                    // Background pixel
                    fb[(y * 16 + yy) * 640 + (x * 8 + xx)] = bgcolor;
                }
            }
        }
        x++;
        text++;
    }
}

// =============================================================
// void tv_printhex(unsigned int x, unsigned int y, unsigned char *text)
// 
// Print hex value to TV screen via low level framebuffer access
// 
// void return
// =============================================================
void tv_printhex(unsigned short *fb, unsigned int x, unsigned int y, unsigned long value){
	
	unsigned long i;
	unsigned long digit;
	char s[9];
	for(i=0;i<8;i++)
	{
		digit=value>>28;
	    value<<=4;
	    s[i] = digit+'0'+(digit<10?0:'a'-10-'0');
	}
	
	s[8]=0x00;
	tv_print(fb, x, y, "0x");
	x++;
	x++;
	tv_print(fb, x, y, s);
}

//==============================================================
//	void tv_fadeout(void)
//
//	This will perform a predefined fade-out using the "tv_fade" primative
//
//	void return
//==============================================================
void tv_fadeout(void)    
{
	unsigned int i, j;
	for(i=0; i<256; i++)
	{
		tv_fade(i);
		for(j=0; j<1024*6; j++);
	}
}

//==============================================================
//	void tv_fadein(void)
//
//	This will perform a predefined fade-in using the "tv_fade" primative
//
//	void return
//==============================================================
void tv_fadein(void)     
{
	unsigned int i, j;
	for(i=0; i<256; i++)
	{
		tv_fade(255-i);
		for(j=0; j<1024*8; j++);
	}
}
