#ifndef __PPU_H__
#define __PPU_H__

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************
 *                           C O N S T A N T S                            *
 **************************************************************************/
#define FLIP_HORIZ 0x01
#define FLIP_VERT 0x02

/**************************************************************************
 *               F U N C T I O N    D E C L A R A T I O N S               *
 **************************************************************************/
volatile unsigned int* ppu_getspritepaletteaddr(unsigned int bank);
unsigned int ppu_getspritexpos(unsigned int id);
unsigned int ppu_getspriteypos(unsigned int id);

#ifdef __cplusplus
}
#endif

#endif
