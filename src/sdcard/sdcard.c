#include "cpu/cache.h"
#include "sdcard/sdcard.h"
#include "score7_registers.h"
#include "score7_constants.h"

// SDCard
	    #define DMA_M2P					0x00000000
		#define DMA_P2M					0x00000001
		#define DMA_AUTO				0x00000000
		#define DMA_REQ					0x00000002
		#define DMA_CON					0x00000000
		#define DMA_FIX					0x00000004
		#define DMA_SINGLE_BUF			0x00000000
		#define DMA_DOUBLE_BUF			0x00000008
		#define DMA_8BIT				0x00000000
		#define DMA_16BIT				0x00000010
		#define DMA_32BIT				0x00000020
		#define DMA_32BIT_BURST			0x00000030
		#define DMA_IRQOFF				0x00000000
		#define DMA_IRQON				0x00000040
		#define DMA_OFF					0x00000000
		#define DMA_ON					0x00000080

U32	rca;
S32 g_sd_dmabusy;
S32 cardtype;
S32 ReadSectors(U32 block, U32 blocknum, U8 *outaddr);
S32	WriteSectors(U32 block, U32 blocknum, U8 *outaddr);

S32 WaitSDStatus(U32 pollbit)
{
	S32 i;
 
	i = 0;
	do {
		i = i + 1;
	} while (((*P_SDC_Status & pollbit) == 0) && (i<600000));
	
	if (i==600000) 
		return 1;

	if ((*P_SDC_Status & (MASK_S_RespIdxError|MASK_S_RespCRCError|MASK_S_DataCRCError|MASK_S_TimeOut)) != 0) 
		return 1;
	return 0;
}	

S32 SDCommand(U32 commandset, U32 arg, U32* outaddr)
{
	// Write Argument First
	*P_SDC_Arg = arg;
	*P_SDC_Command = commandset;
	if (WaitSDStatus(MASK_S_CmdComplete)) 
	{
		*P_SDC_Status = MASK_S_ClrAllBits;
		return 1;
	}
	*outaddr = *P_SDC_Resp;
	*P_SDC_Status = MASK_S_ClrAllBits;
	return 0;
}

S32 SDCommandr2(U32 commandset, U32 arg, U32* outaddr)
{
	S32 i;
	
	// Write Argument First
	*P_SDC_Arg = arg;
	*P_SDC_Command = commandset;
	for (i=0;i<4;i++) 
	{
		WaitSDStatus(MASK_S_RespRegFull);
		*outaddr = *P_SDC_Resp;
		outaddr++;
	}
	if (WaitSDStatus(MASK_S_CmdComplete)) 
		return 1;
		
	*P_SDC_Status = MASK_S_ClrAllBits;
	return 0;
}

S32 SDDrv_ReadSector(U32 sector, U32 sector_num, U8 *buf)
{
	S32 i, ret;
	for(i=0; i<sector_num; i++)
	{		
		ret = ReadSectors(sector+i, 1, buf+i*512);
		if(ret == 1)		
			return ret;
	}		
	return 0;
}

S32 MSDCDrv_ReadSectors(U32 sector, U32 sector_num, U8 *buf)
{
	S32 i, ret;
	for(i=0; i<sector_num; i++)
	{		
		ret = ReadSectors(sector+i, 1, buf+i*512);
		if(ret == 1)		
			return ret;
	}		
	return 0;
}

S32 ReadSectors(U32 block, U32 blocknum, U8 *outaddr)
{
	U32 response[4];

	U32 *realaddr;
	
	g_sd_dmabusy = 1;

	SDCommand(MASK_CMD7, rca, response);
	// Write Argument First
	*P_SDC_Arg = block<<9;
	*P_SDC_Command = MASK_CMD18;
//	*P_SDC_Command = MASK_CMD17;

	*P_DMA_AHB_SA1A = (U32)outaddr;
	*P_DMA_AHB_EA1A = (U32)outaddr + (blocknum<<9) - 4;
	*P_DMA_APB_SA1 = 0x88180004;

	//*P_DMA_CR1 = DMA_P2M|DMA_REQ|DMA_FIX|DMA_SINGLE_BUF|DMA_32BIT|DMA_IRQOFF|DMA_ON;
	*P_DMA_CR1 = DMA_P2M|DMA_REQ|DMA_FIX|DMA_SINGLE_BUF|DMA_32BIT_BURST|DMA_IRQOFF|DMA_ON;

	// Loop until DMA interrupt is set
	while ((*P_DMA_INT & 0x1) == 0);

	// Clear Interrupt and Disable DMA channel
	*P_DMA_INT = 0x1;
	*P_DMA_CR1 = 0x0000;
	
	realaddr = (U32 *)((U32)outaddr & 0x8fffffff);
	dcache_invalidate_all();
	//invalid_cache((U32)realaddr);
	
	if (WaitSDStatus(MASK_S_DataComplete)) 
	{
		*P_SDC_Status = MASK_S_ClrAllBits;
		return 1;
	}
	
	// Stop the controller
	*P_SDC_Command = MASK_CMDSTOP;

	// Loop until controller idle
	while(*P_SDC_Status & MASK_S_ControllerBusy);

	*P_SDC_Status = MASK_S_ClrAllBits;
	
	// Stop the card
	SDCommand(MASK_CMD12, 0x00000000, response);

	do {
		SDCommand(MASK_CMD13, rca, response);
	} while (response[0] != 0x0900);
	SDCommand(MASK_CMD7, rca, response);
/* 	realaddr = (U32)outaddr & 0x8fffffff;
	for(i=0; i<128; i++)
	{
		readdata = *(realaddr+i);
		*(outaddr+4*i) = (readdata & 0xff000000) >> 24;
		*(outaddr+4*i+1) = (readdata & 0x00ff0000) >> 16;
		*(outaddr+4*i+2) = (readdata & 0x0000ff00) >> 8;
		*(outaddr+4*i+3) = (readdata & 0x000000ff);
	}  */
	return 0;
}

S32 SDCommandr3(U32 commandset, U32 arg, U32* outaddr)
{
	
	g_sd_dmabusy = 1;
	
	// Write Argument First
	*P_SDC_Arg = arg;
	*P_SDC_Command = commandset;

	while ((*P_SDC_Status & MASK_S_DataBufFull) == 0);
	
	*outaddr = *P_SDC_DataRx;

	while ((*P_SDC_Status & MASK_S_DataBufFull) == 0);
	
	*(outaddr+1) = *P_SDC_DataRx;
	
	if (WaitSDStatus(MASK_S_DataComplete)) 
	{
		*P_SDC_Status = MASK_S_ClrAllBits;
		return 1;
	}

	*P_SDC_Status = MASK_S_ClrAllBits;
	return 0;
}

S32 SDDrv_WriteSector(U32 block, U32 blocknum, U8 *outaddr)
{
	S32 i, ret;
	for(i=0; i<blocknum; i++)	
	{
		ret = WriteSectors(block+i, 1, outaddr+i*512);
		if(ret == 1)
			return ret;
	}		
	return 0;
	
}

S32 MSDCDrv_WriteSectors(U32 block, U32 blocknum, U8 *outaddr)
{
	S32 i, ret;
	for(i=0; i<blocknum; i++)	
	{
		ret = WriteSectors(block+i, 1, outaddr+i*512);
		if(ret == 1)
			return ret;
	}		
	return 0;
	
}

S32 WriteSectors(U32 block, U32 blocknum, U8 *outaddr)
{
	U32 	i;
	U32 	response[4];
	SDCommand(MASK_CMD7, rca, response);
	g_sd_dmabusy = 1;	
	// Write Argument First
	*P_SDC_Arg = block<<9;
	*P_SDC_Command = MASK_CMD25;
	
//	*P_SDC_Command = MASK_CMD24;
	*P_DMA_AHB_SA1A = (U32)outaddr;
	*P_DMA_AHB_EA1A = (U32)outaddr + (blocknum<<9) - 4;
	*P_DMA_APB_SA1 = 0x88180000;
	*P_DMA_CR1 = DMA_M2P|DMA_REQ|DMA_FIX|DMA_SINGLE_BUF|DMA_32BIT_BURST|DMA_IRQOFF|DMA_ON;

	// Loop until DMA interrupt is set
	while ((*P_DMA_INT & 0x1) == 0);

	// Clear Interrupt and Disable DMA channel
	*P_DMA_INT = 0x1;
	*P_DMA_CR1 = 0x0000;

	if (WaitSDStatus(MASK_S_DataComplete)) {
		*P_SDC_Status = MASK_S_ClrAllBits;
		return 1;
	}

	*P_SDC_Status = MASK_S_ClrAllBits;

	// Stop the controller
	*P_SDC_Command = MASK_CMDSTOP;

	// Loop until controller idle
	while(*P_SDC_Status & MASK_S_ControllerBusy);

	*P_SDC_Status = MASK_S_ClrAllBits;

	// Stop the card
	SDCommand(MASK_CMD12, 0x00000000, response);

	i = 0;

	do {
		SDCommand(MASK_CMD13, rca, response);
	} while (response[0] != 0x0900);
	
	SDCommand(MASK_CMD7, rca, response);
	return 0;
}

S32 SDDrv_GetMemSize(void)
{
	U32 response[4];
	
	U32 c_size, mult, capacity, blocklen;

	SDCommand(MASK_CMD7, 0, response);

	SDCommandr2(MASK_CMD9, rca, response);

	blocklen = ((response[1] & 0x000F0000)>>16)-8;
	c_size = ((response[1] & 0x000003FF)<<2) + (response[2]>>30);
	mult = ((response[2] & 0x00030000)>>15) + ((response[2] & 0x0000FFFF)>>15);
	
	capacity = (blocklen*(c_size+1))<<(mult + 2);

 	SDCommand(MASK_CMD7, rca, response);
	return capacity;
}

S32 MSDCDrv_Capacity(void)
{
	U32 response[4];
	
	U32 c_size, mult, capacity, blocklen;

	SDCommand(MASK_CMD7, 0, response);

	SDCommandr2(MASK_CMD9, rca, response);

	blocklen = ((response[1] & 0x000F0000)>>16)-8;
	c_size = ((response[1] & 0x000003FF)<<2) + (response[2]>>30);
	mult = ((response[2] & 0x00030000)>>15) + ((response[2] & 0x0000FFFF)>>15);
	
	capacity = (blocklen*(c_size+1))<<(mult + 2);

 	SDCommand(MASK_CMD7, rca, response);
	return capacity;
}

S32 SDDrv_GetSpeed(void)
{
	U32 response[4], tranunit, timevalue, maxspeed;

	U32 SpeedTable[]={
		0, 10, 12, 13, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 70, 80,		
	};
	
	U32 TranTable[]={
		1, 10, 100, 1000,
	};
	
	SDCommand(MASK_CMD7, 0x00000000, response);
	
	SDCommandr2(MASK_CMD9, rca, response);

	timevalue = ((response[0] & 0x00000078)>>3);
	tranunit=response[0] & 0x00000007;
	
	maxspeed = SpeedTable[timevalue] * TranTable[tranunit] / 100;
	
	if ((timevalue == 0) || (tranunit > 3)) 
		return 1;
	
	SDCommand(MASK_CMD7, rca, response);	
	return maxspeed;
}


S32 SDDrv_Initial(void)
{	
	S32 	i, loopcnt=0;
	U32 	response[4];
	
	U32 	tranunit, timevalue;
	U32 	maxspeed;
	U32 	SpeedTable[]={
		0, 10, 12, 13, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 70, 80,		
	};
	U32 	TranTable[]={
		1, 10, 100, 1000,
	};

	// Disable All SD Interrupt
	*P_SDC_IntEn = 0x0000;

	// Step 1, Reset SD Controller
	*P_SDC_Control = MASK_C_BlockLen_512bytes|INIT_ClockSpeedFactor1|MASK_C_ENSDBus|MASK_C_DMAMode;
  
	// Clear All Command
	*P_SDC_Command = MASK_CMDSTOP;
	while (*P_SDC_Status & 0x1);
	   
	// Clear All Status
	*P_SDC_Status = MASK_S_ClrAllBits;
	   
	loopcnt = 0;

	// Step 2, Start 64 cycles on SD Clk Bus
	*P_SDC_Command = MASK_ClockCycle74;
       
	if (WaitSDStatus(MASK_S_CmdComplete)) 
		return 1;
    
	*P_SDC_Status = MASK_S_ClrAllBits;

	// Step 3, Reset Command, Should be no response
	SDCommand(MASK_CMD0, 0x00000000, response);

	//////////////////////////////////////////////////////////////////
	//		SECTION 2.  CARD IDEN									//
	//////////////////////////////////////////////////////////////////

	loopcnt = 0;
	cardtype = SDCARD;
    
	// Step 4, Run ACMD 41 until card finish power up sequence
	do
	{
		if (cardtype == SDCARD) 
		{
			if (SDCommand(MASK_CMD55, 0x00000000, response)) 
				cardtype = MMCCARD;
		}
			
		if (cardtype == SDCARD) 
			// ACMD 41
			SDCommand(MASK_ACMD41, 0x00200000, response);	// SD Card
		else
			SDCommand(MASK_CMD1, 0x00200000, response);	// MMC Card
	
		// Check until Bit 31 in OCR register is set
		loopcnt = loopcnt + 1;
	} while (((response[0] & 0x80000000) == 0) && loopcnt < 20000);

	if (loopcnt == 20000) 
		return 0;

	// Step 5, CMD 2 Read CID Register
	SDCommandr2(MASK_CMD2, 0x00000000, response);
	
	if (cardtype == SDCARD)
	{
		// Step 6, CMD 3 Read New RCA, SD will generate RCA itself
		SDCommand(MASK_CMD3, 0x00000000, response);	
		rca = response[0];
	} else {
		// Step 6, CMD 3 Set New RCA, MMC need to be assigned a new RCA
		SDCommand(MASK_CMD3, 0xFFFF0000, response);	
		rca = 0xFFFF0000;
	}

	SDCommand(MASK_CMD13, rca, response);

	if (response[0] != 0x0700) 
		return 1;

	//////////////////////////////////////////////////////////////////
	//		SECTION 3.  SET BUSWIDTH AND CLOCK SPEED				//
	//////////////////////////////////////////////////////////////////

	// Step 7, CMD 9 Read CSD Register
	for (i=0;i<4;i++) 
		response[i] = 0;
	SDCommandr2(MASK_CMD9, rca, response);

	timevalue 	= ((response[0] & 0x00000078)>>3);
	tranunit	= response[0] & 0x00000007;
	
	maxspeed 	= SpeedTable[timevalue] * TranTable[tranunit] / 100;
	
	if((timevalue == 0) || (tranunit > 3))
		return 1;

	if (maxspeed > 24)
		//Increase Clock Speed
		*P_SDC_Control = MASK_C_BlockLen_512bytes|MIN_ClockSpeedFactor|MASK_C_ENSDBus|MASK_C_DMAMode;
	else 
		//Increase Clock Speed
		*P_SDC_Control = MASK_C_BlockLen_512bytes|MMC_ClockSpeedFactor|MASK_C_ENSDBus|MASK_C_DMAMode;
	
	SDCommand(MASK_CMD13, rca, response);
	SDCommand(MASK_CMD7, rca, response);

	// Only SD has 4 bits mode
	if (cardtype == SDCARD)
	{
		//Short block size to 8 bytes
	    *P_SDC_Control = MASK_C_BlockLen_8bytes|(*P_SDC_Control&0xffff);
		
		//ACMD 51
		SDCommand(MASK_CMD55, rca, response);
		SDCommandr3(MASK_ACMD51, rca, response);
		
		if (response[0] == 0xa500)
		{
			//Set Bus width to 4 bits
			SDCommand(MASK_CMD55, rca, response);
			SDCommand(MASK_ACMD6, 0x00000002, response);
			*P_SDC_Control = MASK_C_BlockLen_512bytes|MIN_ClockSpeedFactor|MASK_C_ENSDBus|MASK_C_DMAMode|MASK_C_BUSWIDTH_4;
		}
	}
	else
		*P_SDC_Control = MASK_C_BlockLen_512bytes|MIN_ClockSpeedFactor|MASK_C_ENSDBus|MASK_C_DMAMode;

	SDCommand(MASK_CMD13, rca, response);

	*P_SDC_Control = MASK_C_BlockLen_512bytes|(*P_SDC_Control&0xffff);
	return 0;
}

S32 MSDCDrv_Initial(void)
{
	S32 	i, loopcnt=0;
	U32 	response[4];
	
	U32 	tranunit, timevalue;
	U32 	maxspeed;
	U32 	SpeedTable[]={
		0, 10, 12, 13, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 70, 80,		
	};
	U32 	TranTable[]={
		1, 10, 100, 1000,
	};

	// Disable All SD Interrupt
	*P_SDC_IntEn = 0x0000;
   
	// Step 1, Reset SD Controller
	*P_SDC_Control = MASK_C_BlockLen_512bytes|INIT_ClockSpeedFactor1|MASK_C_ENSDBus|MASK_C_DMAMode;
    
	// Clear All Command
	*P_SDC_Command = MASK_CMDSTOP;
	while (*P_SDC_Status & 0x1);
	
	// Clear All Status
	*P_SDC_Status = MASK_S_ClrAllBits;
	
	loopcnt = 0;

	// Step 2, Start 64 cycles on SD Clk Bus
	*P_SDC_Command = MASK_ClockCycle74;

	if (WaitSDStatus(MASK_S_CmdComplete)) 
		return 1;

	*P_SDC_Status = MASK_S_ClrAllBits;

	// Step 3, Reset Command, Should be no response
	SDCommand(MASK_CMD0, 0x00000000, response);

	//////////////////////////////////////////////////////////////////
	//		SECTION 2.  CARD IDEN									//
	//////////////////////////////////////////////////////////////////

	loopcnt = 0;
	cardtype = SDCARD;

	// Step 4, Run ACMD 41 until card finish power up sequence
	do
	{
		if (cardtype == SDCARD) 
		{
			if (SDCommand(MASK_CMD55, 0x00000000, response)) 
				cardtype = MMCCARD;
		}
			
		if (cardtype == SDCARD) 
			// ACMD 41
			SDCommand(MASK_ACMD41, 0x00200000, response);	// SD Card
		else
			SDCommand(MASK_CMD1, 0x00200000, response);	// MMC Card
	
		// Check until Bit 31 in OCR register is set
		loopcnt = loopcnt + 1;
	} while (((response[0] & 0x80000000) == 0) && loopcnt < 20000);

	if (loopcnt == 20000) 
		return 0;

	// Step 5, CMD 2 Read CID Register
	SDCommandr2(MASK_CMD2, 0x00000000, response);
	
	if (cardtype == SDCARD)
	{
		// Step 6, CMD 3 Read New RCA, SD will generate RCA itself
		SDCommand(MASK_CMD3, 0x00000000, response);	
		rca = response[0];
	} else {
		// Step 6, CMD 3 Set New RCA, MMC need to be assigned a new RCA
		SDCommand(MASK_CMD3, 0xFFFF0000, response);	
		rca = 0xFFFF0000;
	}

	SDCommand(MASK_CMD13, rca, response);

	if (response[0] != 0x0700) 
		return 1;

	//////////////////////////////////////////////////////////////////
	//		SECTION 3.  SET BUSWIDTH AND CLOCK SPEED				//
	//////////////////////////////////////////////////////////////////

	// Step 7, CMD 9 Read CSD Register
	for (i=0;i<4;i++) 
		response[i] = 0;
	SDCommandr2(MASK_CMD9, rca, response);

	timevalue 	= ((response[0] & 0x00000078)>>3);
	tranunit	= response[0] & 0x00000007;
	
	maxspeed 	= SpeedTable[timevalue] * TranTable[tranunit] / 100;
	
	if((timevalue == 0) || (tranunit > 3))
		return 1;

	if (maxspeed > 24)
		//Increase Clock Speed
		*P_SDC_Control = MASK_C_BlockLen_512bytes|MIN_ClockSpeedFactor|MASK_C_ENSDBus|MASK_C_DMAMode;
	else 
		//Increase Clock Speed
		*P_SDC_Control = MASK_C_BlockLen_512bytes|MMC_ClockSpeedFactor|MASK_C_ENSDBus|MASK_C_DMAMode;
	
	SDCommand(MASK_CMD13, rca, response);
	SDCommand(MASK_CMD7, rca, response);

	// Only SD has 4 bits mode
	if (cardtype == SDCARD)
	{
		//Short block size to 8 bytes
	    *P_SDC_Control = MASK_C_BlockLen_8bytes|(*P_SDC_Control&0xffff);
		
		//ACMD 51
		SDCommand(MASK_CMD55, rca, response);
		SDCommandr3(MASK_ACMD51, rca, response);
		
		if (response[0] == 0xa500)
		{
			//Set Bus width to 4 bits
			SDCommand(MASK_CMD55, rca, response);
			SDCommand(MASK_ACMD6, 0x00000002, response);
			*P_SDC_Control = MASK_C_BlockLen_512bytes|MIN_ClockSpeedFactor|MASK_C_ENSDBus|MASK_C_DMAMode|MASK_C_BUSWIDTH_4;
		}
	}
	else
		*P_SDC_Control = MASK_C_BlockLen_512bytes|MIN_ClockSpeedFactor|MASK_C_ENSDBus|MASK_C_DMAMode;

	SDCommand(MASK_CMD13, rca, response);

	*P_SDC_Control = MASK_C_BlockLen_512bytes|(*P_SDC_Control&0xffff);
	return 0;
}

