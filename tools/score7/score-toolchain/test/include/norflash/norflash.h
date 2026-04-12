#ifndef __NORFLASH_H__
#define __NORFLASH_H__

#ifdef __cplusplus
extern "C" {
#endif

#define C_Flash_BaseAddr	0x9e000000

#define C_CMD1_Addr			(volatile unsigned int *)0x9e055550
#define C_CMD2_Addr			(volatile unsigned int *)0x9e02aaa0
#define C_CMD3_Addr			(volatile unsigned int *)0x9e055550
#define C_CMD4_Addr			(volatile unsigned int *)0x9e055550
#define C_CMD5_Addr			(volatile unsigned int *)0x9e02aaa0
#define C_CMD6_Addr			(volatile unsigned int *)0x9e055550

#define C_CMD_Data1			0xaa
#define C_CMD_Data2			0x55
#define C_CMD_Data3			0x80
#define C_CMD_Data4			0xaa
#define C_CMD_Data5			0x55

#define C_WORD_WRITE		0xa0
#define C_SECTOR_ERASE		0x30
#define C_BLOCK_ERASE		0x50
#define C_CHIP_ERASE		0x10

#define C_WRITE_DELAY_TIME	1000
#define C_SECTOR_ERASE_TIME	500000
#define C_BLOCK_ERASE_TIME	500000
#define C_CHIP_ERASE_TIME	500000
/**************************************************************************
 *                           C O N S T A N T S                            *
 **************************************************************************/
#define 	C_SECTOR_SIZE	2048		// 2048 words/sector, 1 word = 16 bits
#define 	C_BLOCK_SIZE 	32768		// 32768 words/block, 16 sector/block

/**************************************************************************
 *               F U N C T I O N    D E C L A R A T I O N S               *
 **************************************************************************/
void norflash_init(void);
void norflash_delay(unsigned int clk);
void norflash_wordwrite(unsigned int addr, unsigned data);
unsigned int norflash_setaddress(unsigned int addr);
extern void norflash_chiperase(void);
extern void norflash_blockerase(unsigned int addr);
extern void norflash_sectorerase(unsigned int addr);
extern void norflash_write32(unsigned int addr, unsigned int data);

#ifdef __cplusplus
}
#endif

#endif
