#include "score7_registers.h"
#include "score7_constants.h"

typedef unsigned char U8;
typedef char S8;
typedef unsigned long U32;
typedef long S32;

#define SDCARD 					0
#define MMCCARD 				1
#define SDDAMSRC 				4

#define MASK_CMDSTOP			0x0040		// Stop Command
#define MASK_CMDRun				0x0080		// Initiate the SD command, will be cleared to '0' after the transaction start.
#define MASK_CMDWithData		0x0100		// 0: Command without data, 1: Command with data
#define MASK_TransData			0x0200		// !MASK_TransferData = MASK_ReceiveData
#define MASK_TransMultiBlock	0x0400		// !MASK_TransMultiBlock = MASK_TransSingleBlock
#define MASK_ClockCycle74		0x0800		// 74 Clock cycles on the clock line
#define MASK_RESPTYPE  			0x7000		// Response type R1b
#define MASK_RESPTYPE0  		0x0000		// No response
#define MASK_RESPTYPE1  		0x1000 		// Response type R1
#define MASK_RESPTYPE2  		0x2000 		// Response type R2	
#define MASK_RESPTYPE3  		0x3000		// contains OCR register R3
#define MASK_RESPTYPE6  		0x6000		// Response type R6
#define MASK_RESPTYPE1b 		0x7000		// Response type R1b

	/* Basic commands (class 0) */
#define MASK_CMD0	(0x00000000|MASK_RESPTYPE0|MASK_CMDRun)		// GO_IDLE_STATE
#define MASK_CMD1	(0x00000001|MASK_RESPTYPE3|MASK_CMDRun)		// reserved, use for MMC				
#define MASK_CMD2	(0x00000002|MASK_RESPTYPE2|MASK_CMDRun)		// ALL_SEND_CID 								
#define MASK_CMD3	(0x00000003|MASK_RESPTYPE6|MASK_CMDRun)		// SEND_RELATIVE_ADDR				
#define MASK_CMD4	(0x00000004|MASK_RESPTYPE0|MASK_CMDRun)		// SEND_RELATIVE_ADDR ?				
#define MASK_CMD5												// reserved				
#define MASK_CMD6												// reserved 
#define MASK_CMD7	(0x00000007|MASK_RESPTYPE1b|MASK_CMDRun)	// SELECT/DESELECT_CARD ?			
#define MASK_CMD8												// reserved				
#define MASK_CMD9	(0x00000009|MASK_RESPTYPE2|MASK_CMDRun)		// SEND_CSD ?				
#define MASK_CMD10	(0x0000000a|MASK_RESPTYPE2|MASK_CMDRun)		// SEND_CID ?						
#define MASK_CMD11												// reserved
//#define MASK_CMD12	(0x0000000c|MASK_RESPTYPE1b|MASK_CMDRun)	// STOP_TRANSMISSION ?
#define MASK_CMD12	(0x0000000c|MASK_RESPTYPE1|MASK_CMDRun)	// STOP_TRANSMISSION ?
#define MASK_CMD13	(0x0000000d|MASK_RESPTYPE1|MASK_CMDRun)		// SEND_STATUS ?		
#define MASK_CMD14												// reserved
#define MASK_CMD15	(0x0000000f|MASK_RESPTYPE0|MASK_CMDRun)		// GO_INACTIVE_STATE ?
								
				
	/* Block oriented read commands (class 2) */				
#define MASK_CMD16	(0x00000010|MASK_RESPTYPE1|MASK_CMDRun)		// SET_BLOCKLEN										
#define MASK_CMD17	(0x00000011|MASK_RESPTYPE1|MASK_CMDRun|MASK_CMDWithData)	
																// READ_SINGLE_BLOCK				
#define MASK_CMD18	(0x00000012|MASK_RESPTYPE1|MASK_CMDRun|MASK_CMDWithData|\
			 MASK_TransMultiBlock)							    // READ_MULTIPLE_BLOCK		
#define MASK_CMD19												// reserved				
#define MASK_CMD20												// reserved	
#define MASK_CMD21												// reserved	
#define MASK_CMD22												// reserved	
#define MASK_CMD23												// reserved	

	/* Block oriented write commands (class 4) */
#define MASK_CMD24	(0x00000018|MASK_RESPTYPE1|MASK_CMDRun|MASK_CMDWithData|MASK_TransData)
																// WRITE_BLOCK				
#define MASK_CMD25	(0x00000019|MASK_RESPTYPE1|MASK_CMDRun|MASK_CMDWithData|MASK_TransData|\
			 MASK_TransMultiBlock)								// WRITE_MULTIPLE_BLOCK					
#define MASK_CMD26												// reserved for Manfacturer
#define MASK_CMD27	(0x0000001b|MASK_RESPTYPE1|MASK_CMDRun|MASK_CMDWithData|\
			 MASK_TransData)									// PROGRAM_CSD



	/* Block oriented write protection commands (class 6) */				
#define MASK_CMD28	(0x0000001c|MASK_RESPTYPE1b|MASK_CMDRun)	// SET_WRITE_PROT					
#define MASK_CMD29	(0x0000001d|MASK_RESPTYPE1b|MASK_CMDRun)	// CLR_WRITE_PROT				
#define MASK_CMD30	(0x0000001e|MASK_RESPTYPE1|MASK_CMDRun|MASK_CMDWithData|\
			 |MASK_TransData)									// SEND_WRITE_PROT	
#define MASK_CMD31												// reserved



	/* Erase commands (class 5) */
#define MASK_CMD32	(0x00000020|MASK_RESPTYPE1|MASK_CMDRun)		// ERASE_WR_BLK_START					
#define MASK_CMD33	(0x00000021|MASK_RESPTYPE1|MASK_CMDRun)		// ERASE_WR_BLK_END
#define MASK_CMD34												// reserved
#define MASK_CMD35												// reserved
#define MASK_CMD36												// reserved
#define MASK_CMD37												// reserved				
#define MASK_CMD38	(0x00000026|MASK_RESPTYPE1|MASK_CMDRun)		// ERASE
#define MASK_CMD39												// reserved
#define MASK_CMD40												// reserved				
#define MASK_CMD41												// reserved



	/* Lock card (class 7) */
#define MASK_CMD42	(0x0000002a|MASK_RESPTYPE1|MASK_CMDRun|MASK_CMDWithData|\
			 MASK_TransData)									// LOCK_UNLOCK
#define MASK_CMD43												// reserved
#define MASK_CMD44												// reserved				
#define MASK_CMD45												// reserved
#define MASK_CMD46												// reserved
#define MASK_CMD47												// reserved				
#define MASK_CMD48												// reserved				
#define MASK_CMD49												// reserved
#define MASK_CMD50												// reserved				
#define MASK_CMD51												// reserved
#define MASK_CMD52												// reserved
#define MASK_CMD53												// reserved				
#define MASK_CMD54												// reserved

				

	/* Application specific commands (class 8) */
#define MASK_CMD55	(0x00000037|MASK_RESPTYPE1|MASK_CMDRun)		// APP_CMD
#define MASK_CMD56	(0x00000038|MASK_RESPTYPE1|MASK_CMDRun|MASK_CMDWithData|\
			 MASK_TransData										// GEN_CMD ?
#define MASK_CMD57												// reserved				
#define MASK_CMD58												// reserved				
#define MASK_CMD59												// reserved
#define MASK_CMD60												// reserved for manfacturer				
#define MASK_CMD61												// reserved for manfacturer
#define MASK_CMD62												// reserved for manfacturer
#define MASK_CMD63												// reserved for manfacturer		
				
				
	/* Application specific commands used/reserved only by SD memory card, 
	 * but not by MultiMediaCard.
 	 * All the following ACMDs shall be preceded with APP_CMD command (CMD55).
 	 */				
 
#define MASK_ACMD6	(0x00000006|MASK_RESPTYPE1|MASK_CMDRun)		// SET_BUS_WIDTH
 				
#define MASK_ACMD13	(0x0000000d|MASK_RESPTYPE1|MASK_CMDRun|MASK_CMDWithData)
																// SD_STATUS				
#define MASK_ACMD17												// reserved
#define MASK_ACMD18												// reserved for SD security application
#define MASK_ACMD19 											// reserved
#define MASK_ACMD20												// reserved	
#define MASK_ACMD21												// reserved
#define MASK_ACMD22	(0x00000016|MASK_RESPTYPE1|MASK_CMDRun|MASK_CMDWithData|\
 			 MASK_TransData)									// SEND_NUM_WR_BLOCKS
 				
#define MASK_ACMD23	(0x00000017|MASK_RESPTYPE1|MASK_CMDRun|MASK_CMDWithData)
																// SET_WR_BLK_ERASE_COUNT
 		
#define MASK_ACMD24												// reserved 			
#define MASK_ACMD25												// reserved for SD security application
#define MASK_ACMD26												// reserved for SD security application
#define MASK_ACMD38 											// reserved for SD security application
#define MASK_ACMD39												// reserved 	
#define MASK_ACMD40												// reserved
#define MASK_ACMD41	(0x00000029|MASK_RESPTYPE3|MASK_CMDRun)		// SD_APP_OP_COND
 			
#define MASK_ACMD42  	(0x0000002a|MASK_RESPTYPE1|MASK_CMDRun)	// SET_CLR_CARD_DETECT
#define MASK_ACMD43												// reserved for SD security application					
#define MASK_ACMD49												// reserved for SD security application
#define MASK_ACMD51 	(0x00000033|MASK_RESPTYPE1|MASK_CMDRun|MASK_CMDWithData)
																//SEND_SCR

#define MASK_S_ControllerBusy	0x0001
#define MASK_S_CardBusy			0x0002
#define MASK_S_CmdComplete		0x0004
#define MASK_S_DataComplete		0x0008
#define MASK_S_RespIdxError		0x0010
#define MASK_S_RespCRCError		0x0020
#define MASK_S_RespRegFull		0x0040
#define MASK_S_DataBufFull		0x0080
#define MASK_S_DataBufEmpty		0x0100
#define MASK_S_TimeOut			0x0200
#define MASK_S_DataCRCError		0x0400
#define MASK_S_CardWProtect		0x0800
#define MASK_S_CardIsPresent	0x1000
#define MASK_S_ClrAllBits		0xffff

#define MASK_C_ClockSpeedFactor	0x00ff
#define INIT_ClockSpeedFactor0	0x000F
#define INIT_ClockSpeedFactor1	0x0020
//#define MIN_ClockSpeedFactor	0x0000
#define MIN_ClockSpeedFactor	0x0001
#define MMC_ClockSpeedFactor	0x0001
#define MASK_C_BUSWIDTH_1		0x0000	
#define MASK_C_BUSWIDTH_4		0x0100 
#define MASK_C_DMAMode			0x0200
#define MASK_C_IOMode			0x0400
#define MASK_C_ENSDBus			0x0800

#define MASK_C_BlockLen_256bytes	0x01000000
#define MASK_C_BlockLen_512bytes	0x02000000 				
#define MASK_C_BlockLen_8bytes		0x00080000


extern U32 SDSize, SDSpeed;
extern U32 rca;
extern S32 g_sd_dmabusy;

S32 SDDrv_ReadSector(U32 addr, U32 blocknum, U8 *outaddr);
S32 SDDrv_WriteSector(U32 addr, U32 blocknum, U8 *outaddr);
S32 SDDrv_Initial(void);
S32 SDDrv_GetMemSize(void);
S32 SDDrv_GetSpeed(void);

