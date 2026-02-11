#ifndef __TV_H__
#define __TV_H__

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************
 *                           C O N S T A N T S                            *
 **************************************************************************/
#define	COLOR_RGB565     	0
#define RESOLUTION_640_480	0
#define RESOLUTION_320_240  1

/**************************************************************************
 *                           M A C R O S                                  *
 **************************************************************************/
#define RGB565(r, g, b) (((r & 0xF8) << 8) | ((g & 0xFC) << 3) | ((b & 0xF8) >> 3))

/**************************************************************************
 *               F U N C T I O N    D E C L A R A T I O N S               *
 **************************************************************************/
void tv_clearscreen(unsigned short *fb);
void tv_init(unsigned int resolution, unsigned int colormode, unsigned int fb1_addr, unsigned int fb2_addr, unsigned int fb3_addr);
void tv_buffer_set(unsigned int fb1_addr, unsigned int fb2_addr, unsigned int fb3_addr);
void tv_buffer_sel(unsigned int sel);
void tv_saturation(unsigned int satu);
void tv_hue(unsigned int hue);
void tv_fade(unsigned int fade);
void tv_fadein(void);
void tv_fadeout(void);
void tv_print(unsigned short *fb, unsigned int x, unsigned int y, const char *text);
void tv_printcolor(unsigned short *fb, unsigned int x, unsigned int y, const char *text, unsigned short color);
void tv_printhex(unsigned short *fb, unsigned intx,  unsigned int y, unsigned long value);

#ifdef __cplusplus
}
#endif

#endif
