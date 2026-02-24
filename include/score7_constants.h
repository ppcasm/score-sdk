#ifndef _SCORE7_CONSTANTS_H
#define _SCORE7_CONSTANTS_H

#define COMPILER_BARRIER() __asm__ volatile("" ::: "memory")

//******************************************************************//
//                            STDINT                                //
//******************************************************************//

typedef signed char         int8_t;
typedef unsigned char       uint8_t;

typedef signed short        int16_t;
typedef unsigned short      uint16_t;

typedef signed int          int32_t;
typedef unsigned int        uint32_t;

typedef signed long long    int64_t;
typedef unsigned long long  uint64_t;

/* Pointer-sized types (32-bit CPU) */
typedef unsigned int        uintptr_t;
typedef signed int          intptr_t;

/* size_t */
#ifndef _SIZE_T_DEFINED
typedef unsigned int        size_t;
#define _SIZE_T_DEFINED
#endif

/* Boolean */
#ifndef __bool_true_false_are_defined
typedef enum { false = 0, true = 1 } bool;
#define __bool_true_false_are_defined 1
#endif

//******************************************************************//
//                      CPU Register Symbols                        //
//******************************************************************//
// General Registers Symbolic
#define    SP        r0
#define    AT        r1
#define    BP        r2
#define    LR        r3
#define    A0        r4
#define    A1        r5
#define    A2        r6
#define    A3        r7
#define    T0        r8
#define    T1        r9
#define    T2        r10
#define    T3        r11
#define    S0        r12
#define    S1        r13
#define    S2        r14
#define    S3        r15
#define    S4        r16
#define    S5        r17
#define    S6        r18
#define    S7        r19
#define    S8        r20
#define    S9        r21
#define    T4        r22
#define    T5        r23
#define    T6        r24
#define    T7        r25
#define    T8        r26
#define    T9        r27
#define    R28       r28
#define    JP        r29
#define    K0        r30
#define    K1        r31

// CP0 Registers
#define CP0_STATUS   cr0
#define CP0_COND     cr1
#define CP0_CAUSE    cr2
#define CP0_EXCPVEC  cr3
#define CP0_CCR      cr4
#define CP0_EPC      cr5
#define CP0_BADVA    cr6
#define CP0_WIRE     cr7
#define CP0_INDEX    cr8
#define CP0_CONTEXT  cr9
#define CP0_RANDOM   cr10
#define CP0_ENTRYHI  cr11
#define CP0_ENTRYLO  cr12
#define CP0_FMARLO   cr13
#define CP0_FMARHI   cr14
#define CP0_FMCR     cr15
#define CP0_FFMR     cr16
#define CP0_LLADDR   cr17
#define CP0_PREV     cr18
#define CP0_DREG     cr29
#define CP0_DEPC     cr30
#define CP0_DSAVE    cr31
#define SPR_HI	     sr1    		
#define SPR_LO	     sr2 

#define STACK_SIZE   32

//******************************************************************//
//                            CLK-PLL                               //
//******************************************************************//

#define C_CPU_CLK_PLLVDIV1        0x00000000    // P_CLK_CPU_SEL
#define C_CPU_CLK_PLLVDIV2        0x00000001    // P_CLK_CPU_SEL
#define C_CPU_CLK_PLLVDIV3        0x00000002    // P_CLK_CPU_SEL
#define C_CPU_CLK_PLLVDIV4        0x00000003    // P_CLK_CPU_SEL
#define C_CPU_CLK_PLLVDIV6        0x00000004    // P_CLK_CPU_SEL
#define C_CPU_CLK_PLLVDIV8        0x00000005    // P_CLK_CPU_SEL

#define C_CPU_CLK_PLLADIV1        0x00000006    // P_CLK_CPU_SEL
#define C_CPU_CLK_PLLADIV2        0x00000007    // P_CLK_CPU_SEL
#define C_CPU_CLK_PLLADIV3        0x00000008    // P_CLK_CPU_SEL
#define C_CPU_CLK_PLLADIV4        0x00000009    // P_CLK_CPU_SEL
#define C_CPU_CLK_PLLADIV6        0x0000000A    // P_CLK_CPU_SEL
#define C_CPU_CLK_PLLADIV8        0x0000000B    // P_CLK_CPU_SEL

#define C_AHB_CLK_EN              0x00000001    // P_CLK_AHB_CONF

#define C_AHB_CLK_CPUDIV1         0x00000000    // P_CLK_AHB_SEL
#define C_AHB_CLK_CPUDIV2         0x00000001    // P_CLK_AHB_SEL
#define C_AHB_CLK_CPUDIV3         0x00000002    // P_CLK_AHB_SEL
#define C_AHB_CLK_CPUDIV4         0x00000003    // P_CLK_AHB_SEL

#define C_PLLV_CLK_EN             0x00000001    // P_CLK_PLLV_CONF

#define C_PLLV_CLK_81M            0x00000003    // P_CLK_PLLV_SEL
#define C_PLLV_CLK_87M            0x00000004    // P_CLK_PLLV_SEL
#define C_PLLV_CLK_97M            0x00000005    // P_CLK_PLLV_SEL
#define C_PLLV_CLK_101M           0x00000006    // P_CLK_PLLV_SEL
#define C_PLLV_CLK_108M           0x00000007    // P_CLK_PLLV_SEL
#define C_PLLV_CLK_114M           0x00000008    // P_CLK_PLLV_SEL
#define C_PLLV_CLK_121M           0x00000009    // P_CLK_PLLV_SEL
#define C_PLLV_CLK_128M           0x0000000A    // P_CLK_PLLV_SEL
#define C_PLLV_CLK_135M           0x0000000B    // P_CLK_PLLV_SEL
#define C_PLLV_CLK_141M           0x0000000C    // P_CLK_PLLV_SEL
#define C_PLLV_CLK_148M           0x0000000D    // P_CLK_PLLV_SEL
#define C_PLLV_CLK_155M           0x0000000E    // P_CLK_PLLV_SEL
#define C_PLLV_CLK_162M           0x0000000F    // P_CLK_PLLV_SEL

#define C_PLLA_CLK_EN             0x00000001    // P_CLK_PLLAU_CONF
#define C_PLLA_CLK_73M            0x00000000    // P_CLK_PLLAU_CONF
#define C_PLLA_CLK_67M            0x00000002    // P_CLK_PLLAU_CONF
#define C_PLLU_CLK_EN             0x00000004    // P_CLK_PLLAU_CONF

#define C_LVR_RST_EN              0x00000001    // P_LVR_RESET_CTRL

#define C_32K_CRY_EN              0x00000001    // P_CLK_32K_CONF

//******************************************************************//
//                               GPIO                               //
//******************************************************************//

#define C_IOA0_INTRISE_EN         0x00000001    // P_GPIO_PORT_INT
#define C_IOA1_INTRISE_EN         0x00000002    // P_GPIO_PORT_INT
#define C_IOA0_INTFALL_EN         0x00000100    // P_GPIO_PORT_INT
#define C_IOA1_INTFALL_EN         0x00000200    // P_GPIO_PORT_INT
#define C_IOA0_INTRISE_FLAG       0x00010000    // P_GPIO_PORT_INT
#define C_IOA1_INTRISE_FLAG       0x00020000    // P_GPIO_PORT_INT
#define C_IOA0_INTFALL_FLAG       0x01000000    // P_GPIO_PORT_INT
#define C_IOA1_INTFALL_FLAG       0x02000000    // P_GPIO_PORT_INT

#define C_GPIO_CLK_EN             0x00000001    // P_GPIO_CLK_CONF
#define C_GPIO_RST_DIS            0x00000002    // P_GPIO_CLK_CONF

//******************************************************************//
//                              WDOG                                //
//******************************************************************//

#define C_WDOG_CLK_EN             0x00000001    // P_WDOG_CLK_CONF
#define C_WDOG_RST_DIS            0x00000002    // P_WDOG_CLK_CONF

#define C_WDOG_ERR_FLAG           0x00000001    // P_WDOG_RESET_STATUS
#define C_WDOG_RST_FLAG           0x00000002    // P_WDOG_RESET_STATUS

#define C_WDOG_CTRL_EN            0x80000000    // P_WDOG_MODE_CTRL

#define C_WDOG_CLR_COMMAND        0xa0000005    // P_WDOG_CLR_COMMAND

//******************************************************************//
//                           Sleep-Wakeup                           //
//******************************************************************//

#define C_SLEEP_WAIT_MODE         0x00000005    // P_SLEEP_MODE_CTRL
#define C_SLEEP_HALT_MODE         0x0000000B    // P_SLEEP_MODE_CTRL

#define C_SLEEP_CLK_PLLVDIV8      0x00000000    // P_SLEEP_CLK_SEL
#define C_SLEEP_CLK_32K           0x00000001    // P_SLEEP_CLK_SEL

#define C_WAKEUP_KEY_GROUP1       0x00000001    // P_WAKEUP_KEYC_SEL
#define C_WAKEUP_KEY_GROUP2       0x00000002    // P_WAKEUP_KEYC_SEL
#define C_WAKEUP_KEY_GROUP3       0x00000003    // P_WAKEUP_KEYC_SEL
#define C_WAKEUP_KEY_GROUP4       0x00000004    // P_WAKEUP_KEYC_SEL
#define C_WAKEUP_KEY_GROUP5       0x00000005    // P_WAKEUP_KEYC_SEL

#define C_WAKEUP_KEY_CLR          0x00000000    // P_WAKEUP_KEYC_CLR
#define C_WAKEUP_KEY_EN           0x00000001    // P_WAKEUP_KEYC_CLR

//******************************************************************//
//                              INT                                 //
//******************************************************************//

#define C_INT_RST_DIS             0x00000001    // P_INT_CLK_CONF

#define C_INT_DAC_REQ             0x00000001    // P_INT_REQ_STATUS1
#define C_INT_MIC_REQ             0x00000010    // P_INT_REQ_STATUS1
#define C_INT_ADC_REQ             0x00000020    // P_INT_REQ_STATUS1
#define C_INT_TMB_REQ             0x00000040    // P_INT_REQ_STATUS1
#define C_INT_TIMER_REQ           0x00000080    // P_INT_REQ_STATUS1
#define C_INT_LCDVS_REQ           0x00000200    // P_INT_REQ_STATUS1
#define C_INT_USB_REQ             0x00040000    // P_INT_REQ_STATUS1
#define C_INT_SIO_REQ             0x00080000    // P_INT_REQ_STATUS1
#define C_INT_SPI_REQ             0x00100000    // P_INT_REQ_STATUS1
#define C_INT_UART_REQ            0x00200000    // P_INT_REQ_STATUS1
#define C_INT_NAND_REQ            0x00400000    // P_INT_REQ_STATUS1
#define C_INT_SD_REQ              0x00800000    // P_INT_REQ_STATUS1
#define C_INT_I2C_REQ             0x01000000    // P_INT_REQ_STATUS1
#define C_INT_I2S_REQ             0x02000000    // P_INT_REQ_STATUS1
#define C_INT_APBCH0_REQ          0x04000000    // P_INT_REQ_STATUS1
#define C_INT_APBCH1_REQ          0x08000000    // P_INT_REQ_STATUS1
#define C_INT_LDM_REQ             0x10000000    // P_INT_REQ_STATUS1
#define C_INT_BLN_REQ             0x20000000    // P_INT_REQ_STATUS1
#define C_INT_APBCH2_REQ          0x40000000    // P_INT_REQ_STATUS1
#define C_INT_APBCH3_REQ          0x80000000    // P_INT_REQ_STATUS1

#define C_INT_RTC_REQ             0x00000001    // P_INT_REQ_STATUS2
#define C_INT_MP4_REQ             0x00000002    // P_INT_REQ_STATUS2
#define C_INT_ECC_REQ             0x00000004    // P_INT_REQ_STATUS2
#define C_INT_GPIO_REQ            0x00000008    // P_INT_REQ_STATUS2

#define C_INT_DAC_DIS             0x00000001    // P_INT_MASK_CTRL1
#define C_INT_MIC_DIS             0x00000010    // P_INT_MASK_CTRL1
#define C_INT_ADC_DIS             0x00000020    // P_INT_MASK_CTRL1
#define C_INT_TMB_DIS             0x00000040    // P_INT_MASK_CTRL1
#define C_INT_TIMER_DIS           0x00000080    // P_INT_MASK_CTRL1
#define C_INT_LCDVS_DIS           0x00000200    // P_INT_MASK_CTRL1
#define C_INT_FRAME_END           0x00001000    // P_INT_MASK_CTRL1
#define C_INT_POS_HIT             0x00002000    // P_INT_MASK_CTRL1
#define C_INT_MD_FRAME            0x00004000    // P_INT_MASK_CTRL1
#define C_INT_TG_CAPACK           0x00008000    // P_INT_MASK_CTRL1
#define C_INT_TG_OF               0x00008000    // P_INT_MASK_CTRL1
#define C_INTI_MD_UF              0x00008000    // P_INT_MASK_CTRL1
#define C_INT_FRAME_DIS           0x00008000    // P_INT_MASK_CTRL1
#define C_INT_USB_DIS             0x00040000    // P_INT_MASK_CTRL1
#define C_INT_SIO_DIS             0x00080000    // P_INT_MASK_CTRL1
#define C_INT_SPI_DIS             0x00100000    // P_INT_MASK_CTRL1
#define C_INT_UART_DIS            0x00200000    // P_INT_MASK_CTRL1
#define C_INT_NAND_DIS            0x00400000    // P_INT_MASK_CTRL1
#define C_INT_SD_DIS              0x00800000    // P_INT_MASK_CTRL1
#define C_INT_I2C_DIS             0x01000000    // P_INT_MASK_CTRL1
#define C_INT_I2S_DIS             0x02000000    // P_INT_MASK_CTRL1
#define C_INT_APBCH0_DIS          0x04000000    // P_INT_MASK_CTRL1
#define C_INT_APBCH1_DIS          0x08000000    // P_INT_MASK_CTRL1
#define C_INT_LDM_DIS             0x10000000    // P_INT_MASK_CTRL1
#define C_INT_BLN_DIS             0x20000000    // P_INT_MASK_CTRL1
#define C_INT_APBCH2_DIS          0x40000000    // P_INT_MASK_CTRL1
#define C_INT_APBCH3_DIS          0x80000000    // P_INT_MASK_CTRL1

#define C_INT_RTC_DIS             0x00000001    // P_INT_MASK_CTRL2
#define C_INT_MP4_DIS             0x00000002    // P_INT_MASK_CTRL2
#define C_INT_ECC_DIS             0x00000004    // P_INT_MASK_CTRL2
#define C_INT_GPIO_DIS            0x00000008    // P_INT_MASK_CTRL2

//******************************************************************//
//                              MIU                                 //
//******************************************************************//

#define C_MIU_RST_DIS             0x00000004    // P_MIU_CLK_CONF
#define C_MIU_CLK_EN              0x00000003    // P_MIU_CLK_CONF
#define C_MIU_REFLASH_DIS         0x00000002    // P_MIU_CLK_CONF
#define C_MIU_REFLASH_EN          0x00000001    // P_MIU_CLK_CONF

#define C_SDRAM_DEEP_DOWN         0x00000008    // P_MIU_SDRAM_POWER
#define C_SDRAM_MRS_REDO          0x00000004    // P_MIU_SDRAM_POWER
#define C_SDRAM_POWER_DOWN        0x00000002    // P_MIU_SDRAM_POWER
#define C_SDRAM_SELF_REFRESH      0x00000001    // P_MIU_SDRAM_POWER

#define C_SDRAM_TRP_1CYCLE        0x00000000    // P_MIU_SDRAM_SETUP1
#define C_SDRAM_TRP_2CYCLE        0x00000001    // P_MIU_SDRAM_SETUP1
#define C_SDRAM_TRCD_1CYCLE       0x00000000    // P_MIU_SDRAM_SETUP1
#define C_SDRAM_TRCD_2CYCLE       0x00000002    // P_MIU_SDRAM_SETUP1
#define C_SDRAM_CAS_2CYCLE        0x00000000    // P_MIU_SDRAM_SETUP1
#define C_SDRAM_CAS_3CYCLE        0x00000004    // P_MIU_SDRAM_SETUP1
#define C_SDRAM_WORD_8BIT         0x00000000    // P_MIU_SDRAM_SETUP1
#define C_SDRAM_WORD_16BIT        0x01000000    // P_MIU_SDRAM_SETUP1
#define C_SDRAM_WORD_32BIT        0x02000000    // P_MIU_SDRAM_SETUP1
#define C_SDRAM_ROW_1024          0x00000000    // P_MIU_SDRAM_SETUP1
#define C_SDRAM_ROW_2048          0x04000000    // P_MIU_SDRAM_SETUP1
#define C_SDRAM_ROW_4096          0x08000000    // P_MIU_SDRAM_SETUP1
#define C_SDRAM_ROW_8192          0x0C000000    // P_MIU_SDRAM_SETUP1
#define C_MIU_CTRL_EN             0x80000000    // P_MIU_SDRAM_SETUP1

#define C_MIU_OFF_STATUS          0x00000001    // P_MIU_SDRAM_STATUS

#define C_SDRAM_TRP_3CYCLE        0x00000001    // P_MIU_SDRAM_SETUP2
#define C_SDRAM_TRCD_3CYCLE       0x00000002    // P_MIU_SDRAM_SETUP2

//******************************************************************//
//                            APBDMA                                //
//******************************************************************//

#define C_DMA_CLK_EN              0x00000001    // P_DMA_CLK_CONF
#define C_DMA_RST_DIS             0x00000002    // P_DMA_CLK_CONF

#define C_DMA_CH0_BUSY            0x00000001    // P_DMA_BUSY_STATUS
#define C_DMA_CH1_BUSY            0x00000002    // P_DMA_BUSY_STATUS
#define C_DMA_CH2_BUSY            0x00000004    // P_DMA_BUSY_STATUS
#define C_DMA_CH3_BUSY            0x00000008    // P_DMA_BUSY_STATUS

#define C_DMA_CH0_FLAG            0x00000001    // P_DMA_INT_STATUS
#define C_DMA_CH1_FLAG            0x00000002    // P_DMA_INT_STATUS
#define C_DMA_CH2_FLAG            0x00000004    // P_DMA_INT_STATUS
#define C_DMA_CH3_FLAG            0x00000008    // P_DMA_INT_STATUS

#define C_DMA_CH0_RST             0x00000001    // P_DMA_CHANNEL_RESET
#define C_DMA_CH1_RST             0x00000002    // P_DMA_CHANNEL_RESET
#define C_DMA_CH2_RST             0x00000004    // P_DMA_CHANNEL_RESET
#define C_DMA_CH3_RST             0x00000008    // P_DMA_CHANNEL_RESET

#define C_DMA_MIU_APB             0x00000000    // P_DMA_CHANNELx_CTRL
#define C_DMA_APB_MIU             0x00000001    // P_DMA_CHANNELx_CTRL
#define C_DMA_AUTO_MODE           0x00000000    // P_DMA_CHANNELx_CTRL
#define C_DMA_POLLING_MODE        0x00000002    // P_DMA_CHANNELx_CTRL
#define C_DMA_CONTINUOUS_MODE     0x00000000    // P_DMA_CHANNELx_CTRL
#define C_DMA_REGULAR_MODE        0x00000004    // P_DMA_CHANNELx_CTRL
#define C_DMA_SINGLE_BUF          0x00000000    // P_DMA_CHANNELx_CTRL
#define C_DMA_DOUBLE_BUF          0x00000008    // P_DMA_CHANNELx_CTRL
#define C_DMA_8BIT_SINGLE         0x00000000    // P_DMA_CHANNELx_CTRL
#define C_DMA_16BIT_SINGLE        0x00000010    // P_DMA_CHANNELx_CTRL
#define C_DMA_32BIT_SINGLE        0x00000020    // P_DMA_CHANNELx_CTRL
#define C_DMA_32BIT_BURST         0x00000030    // P_DMA_CHANNELx_CTRL
#define C_DMA_INT_EN              0x00000040    // P_DMA_CHANNELx_CTRL
#define C_DMA_CH_EN               0x00000080    // P_DMA_CHANNELx_CTRL

//******************************************************************//
//                                ADC                               //
//******************************************************************//

#define C_ADC_CLK_EN              0x00000001    // P_ADC_CLK_CONF
#define C_ADC_RST_DIS             0x00000002    // P_ADC_CLK_CONF

#define C_ADC_SEL_PLLA            0x00000000    // P_ADC_CLK_SEL
#define C_ADC_SEL_PLLU            0x00000100    // P_ADC_CLK_SEL

#define C_ADC_CH0_EN              0x00000001    // P_ADC_AINPUT_CTRL
#define C_ADC_CH1_EN              0x00000002    // P_ADC_AINPUT_CTRL
#define C_ADC_CH2_EN              0x00000004    // P_ADC_AINPUT_CTRL
#define C_ADC_CH3_EN              0x00000008    // P_ADC_AINPUT_CTRL
#define C_ADC_CH4_EN              0x00000010    // P_ADC_AINPUT_CTRL
#define C_ADC_CH5_EN              0x00000020    // P_ADC_AINPUT_CTRL
#define C_ADC_CH6_EN              0x00000040    // P_ADC_AINPUT_CTRL
#define C_ADC_CH7_EN              0x00000080    // P_ADC_AINPUT_CTRL

#define C_ADC_CH0_SEL             0x00000000    // P_ADC_MIC_CTRL1
#define C_ADC_CH1_SEL             0x00000001    // P_ADC_MIC_CTRL1
#define C_ADC_CH2_SEL             0x00000002    // P_ADC_MIC_CTRL1
#define C_ADC_CH3_SEL             0x00000003    // P_ADC_MIC_CTRL1
#define C_ADC_CH4_SEL             0x00000004    // P_ADC_MIC_CTRL1
#define C_ADC_CH5_SEL             0x00000005    // P_ADC_MIC_CTRL1
#define C_ADC_CH6_SEL             0x00000006    // P_ADC_MIC_CTRL1
#define C_ADC_CH7_SEL             0x00000007    // P_ADC_MIC_CTRL1
#define C_ADC_MIC_SEL             0x00000008    // P_ADC_MIC_CTRL1

#define C_MIC_BIAS_EN             0x04000000    // P_ADC_MIC_CTRL1
#define C_MIC_BOOST_EN            0x08000000    // P_ADC_MIC_CTRL1
#define C_ADC_MODE_MIC            0x20000000    // P_ADC_MIC_CTRL1
#define C_ADC_MODE_ADC            0xC0000000    // P_ADC_MIC_CTRL1

#define C_MIC_GAIN_330            0x00000000    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_315            0x00000001    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_300            0x00000002    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_285            0x00000003    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_270            0x00000004    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_255            0x00000005    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_240            0x00000006    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_225            0x00000007    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_210            0x00000008    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_195            0x00000009    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_180            0x0000000a    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_165            0x0000000b    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_150            0x0000000c    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_135            0x0000000d    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_120            0x0000000e    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_105            0x0000000f    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_090            0x00000010    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_075            0x00000011    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_060            0x00000012    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_045            0x00000013    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_030            0x00000014    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_015            0x00000015    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_000            0x00000016    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_NEG015         0x00000017    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_NEG030         0x00000018    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_NEG045         0x00000019    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_NEG060         0x0000001a    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_NEG075         0x0000001b    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_NEG090         0x0000001c    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_NEG105         0x0000001d    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_NEG120         0x0000001e    // P_ADC_MIC_GAIN
#define C_MIC_GAIN_NEGINFINATY    0x0000001f    // P_ADC_MIC_GAIN

#define C_ADC_FIFO_ONE            0x00000000    // P_ADC_MIC_CTRL2
#define C_ADC_FIFO_TWO            0x00000001    // P_ADC_MIC_CTRL2
#define C_ADC_FIFO_THREE          0x00000002    // P_ADC_MIC_CTRL2
#define C_ADC_FIFO_FOUR           0x00000003    // P_ADC_MIC_CTRL2
#define C_ADC_FIFO_FIVE           0x00000004    // P_ADC_MIC_CTRL2
#define C_ADC_FIFO_SIX            0x00000005    // P_ADC_MIC_CTRL2
#define C_ADC_FIFO_SEVEN          0x00000006    // P_ADC_MIC_CTRL2
#define C_ADC_FIFO_EIGHT          0x00000007    // P_ADC_MIC_CTRL2

#define C_ADC_FIFOINT_ONE         0x00000000    // P_ADC_MIC_CTRL2
#define C_ADC_FIFOINT_TWO         0x00000010    // P_ADC_MIC_CTRL2
#define C_ADC_FIFOINT_THREE       0x00000020    // P_ADC_MIC_CTRL2
#define C_ADC_FIFOINT_FOUR        0x00000030    // P_ADC_MIC_CTRL2
#define C_ADC_FIFOINT_FIVE        0x00000040    // P_ADC_MIC_CTRL2
#define C_ADC_FIFOINT_SIX         0x00000050    // P_ADC_MIC_CTRL2
#define C_ADC_FIFOINT_SEVEN       0x00000060    // P_ADC_MIC_CTRL2
#define C_ADC_FIFOINT_EIGHT       0x00000070    // P_ADC_MIC_CTRL2

#define C_ADC_AUTO_CLR            0x00800000    // P_ADC_MIC_CTRL2
#define C_ADC_MANUAL_CLR          0x00000000    // P_ADC_MIC_CTRL2
#define C_ADC_DMA_32BIT           0x00000000    // P_ADC_MIC_CTRL2
#define C_ADC_DMA_16BIT           0x01000000    // P_ADC_MIC_CTRL2
#define C_MIC_MUTE_MODE           0x02000000    // P_ADC_MIC_CTRL2
#define C_MIC_NORMAL_MODE         0x00000000    // P_ADC_MIC_CTRL2
#define C_MIC_SIGNED_FMT          0x00000000    // P_ADC_MIC_CTRL2
#define C_MIC_UNSIGNED_FMT        0x04000000    // P_ADC_MIC_CTRL2
#define C_ADC_AUTO_MODE           0x08000000    // P_ADC_MIC_CTRL2
#define C_ADC_MANUAL_MODE         0x00000000    // P_ADC_MIC_CTRL2
#define C_ADC_CTRL_EN             0x80000000    // P_ADC_MIC_CTRL2

#define C_ADC_MANUAL_START        0x00008000    // P_ADC_INT_STATUS
#define C_ADC_FIFO_EMPTY          0x00200000    // P_ADC_INT_STATUS
#define C_ADC_FIFO_FULL           0x00400000    // P_ADC_INT_STATUS
#define C_ADC_FIFOOV_FLAG         0x00800000    // P_ADC_INT_STATUS
#define C_ADC_MICOV_INTEN         0x04000000    // P_ADC_INT_STATUS
#define C_ADC_MICOV_FLAG          0x08000000    // P_ADC_INT_STATUS
#define C_ADC_AUTO_INTEN          0x10000000    // P_ADC_INT_STATUS
#define C_ADC_AUTO_FLAG           0x20000000    // P_ADC_INT_STATUS
#define C_ADC_MANUAL_INTEN        0x40000000    // P_ADC_INT_STATUS
#define C_ADC_MANUAL_FLAG         0x80000000    // P_ADC_INT_STATUS

//******************************************************************//
//                               Timer                              //
//******************************************************************//
#define C_TIMER_CLK_EN            0x00000001    // P_TIMERx_CLK_CONF    x 0~5
#define C_TIMER_RST_DIS           0x00000002    // P_TIMERx_CLK_CONF    x 0~5

#define C_TIMER0_CLK_27M          0x00000000    // P_TIMER_CLK_SEL
#define C_TIMER0_CLK_32K          0x00000100    // P_TIMER_CLK_SEL
#define C_TIMER1_CLK_27M          0x00000000    // P_TIMER_CLK_SEL
#define C_TIMER1_CLK_32K          0x00000200    // P_TIMER_CLK_SEL
#define C_TIMER2_CLK_27M          0x00000000    // P_TIMER_CLK_SEL
#define C_TIMER2_CLK_32K          0x00000400    // P_TIMER_CLK_SEL
#define C_TIMER3_CLK_27M          0x00000000    // P_TIMER_CLK_SEL
#define C_TIMER3_CLK_32K          0x00000800    // P_TIMER_CLK_SEL
#define C_TIMER4_CLK_27M          0x00000000    // P_TIMER_CLK_SEL
#define C_TIMER4_CLK_32K          0x00001000    // P_TIMER_CLK_SEL
#define C_TIMER5_CLK_27M          0x00000000    // P_TIMER_CLK_SEL
#define C_TIMER5_CLK_32K          0x00002000    // P_TIMER_CLK_SEL

#define C_TIMER_INT_FLAG          0x04000000    // P_TIMERx_MODE_CTRL    x 0~5
#define C_TIMER_INT_EN            0x08000000    // P_TIMERx_MODE_CTRL
#define C_TIMER_CTRL_EN           0x80000000    // P_TIMERx_MODE_CTRL

#define C_TIMER_PWM_NRO           0x00000000    // P_TIMERx_CCP_CTRL
#define C_TIMER_PWM_NRZ           0x02000000    // P_TIMERx_CCP_CTRL
#define C_TIMER_CMP_HIGH          0x00000000    // P_TIMERx_CCP_CTRL
#define C_TIMER_CMP_LOW           0x04000000    // P_TIMERx_CCP_CTRL
#define C_TIMER_CAP_FALL          0x00000000    // P_TIMERx_CCP_CTRL
#define C_TIMER_CAP_RISE          0x08000000    // P_TIMERx_CCP_CTRL
#define C_TIMER_NOR_MODE          0x00000000    // P_TIMERx_CCP_CTRL
#define C_TIMER_CAP_MODE          0x40000000    // P_TIMERx_CCP_CTRL
#define C_TIMER_CMP_MODE          0x80000000    // P_TIMERx_CCP_CTRL
#define C_TIMER_PWM_MODE          0xC0000000    // P_TIMERx_CCP_CTRL

#define C_TIMER0_PORT_SEL         0x00010000    // P_TIMER_INTERFACE_SEL
#define C_TIMER1_PORT_SEL         0x00020000    // P_TIMER_INTERFACE_SEL
#define C_TIMER2_PORT_SEL         0x00040000    // P_TIMER_INTERFACE_SEL
#define C_TIMER3_PORT_SEL         0x00080000    // P_TIMER_INTERFACE_SEL
#define C_TIMER4_PORT_SEL         0x00100000    // P_TIMER_INTERFACE_SEL
#define C_TIMER5_PORT_SEL         0x00200000    // P_TIMER_INTERFACE_SEL

//******************************************************************//
//                             RTC-TMB                              //
//******************************************************************//
#define C_RTC_RST_DIS             0x00000002    // P_RTC_CLK_CONF
#define C_RTC_CLK_EN              0x00000001    // P_RTC_CLK_CONF
#define C_RTC_CTRL_EN             0x80000000    // P_RTC_MODE_CTRL

#define C_RTC_HSEC_INTEN          0x00004000    // P_RTC_INT_STATUS
#define C_RTC_HSEC_FLAG           0x00008000    // P_RTC_INT_STATUS
#define C_RTC_SEC_INTEN           0x00040000    // P_RTC_INT_STATUS
#define C_RTC_SEC_FLAG            0x00080000    // P_RTC_INT_STATUS
#define C_RTC_MIN_INTEN           0x00400000    // P_RTC_INT_STATUS
#define C_RTC_MIN_FLAG            0x00800000    // P_RTC_INT_STATUS
#define C_RTC_HOUR_INTEN          0x04000000    // P_RTC_INT_STATUS
#define C_RTC_HOUR_FLAG           0x08000000    // P_RTC_INT_STATUS
#define C_RTC_ALM_INTEN           0x40000000    // P_RTC_INT_STATUS
#define C_RTC_ALM_FLAG            0x80000000    // P_RTC_INT_STATUS

#define C_TMB_RST_DIS             0x00000004    // P_TMB_CLK_CONF
#define C_TMB_CLK_EN              0x00000001    // P_TMB_CLK_CONF

#define C_TMB_TMB2_1HZ            0x00000000    // P_TMB_MODE_CTRL
#define C_TMB_TMB2_2HZ            0x00000100    // P_TMB_MODE_CTRL
#define C_TMB_TMB2_4Hz            0x00000200    // P_TMB_MODE_CTRL
#define C_TMB_TMB2_8HZ            0x00000300    // P_TMB_MODE_CTRL
#define C_TMB_TMB2_16HZ           0x00000400    // P_TMB_MODE_CTRL
#define C_TMB_TMB2_32HZ           0x00000500    // P_TMB_MODE_CTRL
#define C_TMB_TMB2_64HZ           0x00000600    // P_TMB_MODE_CTRL
#define C_TMB_TMB2_128HZ          0x00000700    // P_TMB_MODE_CTRL
#define C_TMB_TMB2_256HZ          0x00000800    // P_TMB_MODE_CTRL
#define C_TMB_TMB2_512HZ          0x00000900    // P_TMB_MODE_CTRL
#define C_TMB_TMB2_1024HZ         0x00000a00    // P_TMB_MODE_CTRL
#define C_TMB_TMB2_2048HZ         0x00000b00    // P_TMB_MODE_CTRL
#define C_TMB_TMB2_EN             0x00008000    // P_TMB_MODE_CTRL

#define C_TMB_TMB1_1HZ            0x00000000    // P_TMB_MODE_CTRL
#define C_TMB_TMB1_2HZ            0x00010000    // P_TMB_MODE_CTRL
#define C_TMB_TMB1_4HZ            0x00020000    // P_TMB_MODE_CTRL
#define C_TMB_TMB1_8HZ            0x00030000    // P_TMB_MODE_CTRL
#define C_TMB_TMB1_16HZ           0x00040000    // P_TMB_MODE_CTRL
#define C_TMB_TMB1_32HZ           0x00050000    // P_TMB_MODE_CTRL
#define C_TMB_TMB1_64HZ           0x00060000    // P_TMB_MODE_CTRL
#define C_TMB_TMB1_128HZ          0x00070000    // P_TMB_MODE_CTRL
#define C_TMB_TMB1_256HZ          0x00080000    // P_TMB_MODE_CTRL
#define C_TMB_TMB1_512HZ          0x00090000    // P_TMB_MODE_CTRL
#define C_TMB_TMB1_1024HZ         0x000a0000    // P_TMB_MODE_CTRL
#define C_TMB_TMB1_2048HZ         0x000b0000    // P_TMB_MODE_CTRL
#define C_TMB_TMB1_EN             0x00800000    // P_TMB_MODE_CTRL

#define C_TMB_TMB0_1HZ            0x00000000    // P_TMB_MODE_CTRL
#define C_TMB_TMB0_2HZ            0x01000000    // P_TMB_MODE_CTRL
#define C_TMB_TMB0_4HZ            0x02000000    // P_TMB_MODE_CTRL
#define C_TMB_TMB0_8HZ            0x03000000    // P_TMB_MODE_CTRL
#define C_TMB_TMB0_16HZ           0x04000000    // P_TMB_MODE_CTRL
#define C_TMB_TMB0_32HZ           0x05000000    // P_TMB_MODE_CTRL
#define C_TMB_TMB0_64HZ           0x06000000    // P_TMB_MODE_CTRL
#define C_TMB_TMB0_128HZ          0x07000000    // P_TMB_MODE_CTRL
#define C_TMB_TMB0_256HZ          0x08000000    // P_TMB_MODE_CTRL
#define C_TMB_TMB0_512HZ          0x09000000    // P_TMB_MODE_CTRL
#define C_TMB_TMB0_1024HZ         0x0a000000    // P_TMB_MODE_CTRL
#define C_TMB_TMB0_2048HZ         0x0b000000    // P_TMB_MODE_CTRL
#define C_TMB_TMB0_EN             0x80000000    // P_TMB_MODE_CTRL

#define C_TMB_TMB2_INTEN          0x00400000    // P_TMB_INT_STATUS
#define C_TMB_TMB2_FLAG           0x00800000    // P_TMB_INT_STATUS
#define C_TMB_TMB1_INTEN          0x04000000    // P_TMB_INT_STATUS
#define C_TMB_TMB1_FLAG           0x08000000    // P_TMB_INT_STATUS
#define C_TMB_TMB0_INTEN          0x40000000    // P_TMB_INT_STATUS
#define C_TMB_TMB0_FLAG           0x80000000    // P_TMB_INT_STATUS

#define C_TMB_RST_COMMAND         0x50000005    // P_TMB_RESET_COMMAND

//******************************************************************//
//                              UART                                //
//******************************************************************//

#define C_UART_CLK_EN             0x00000001    // P_UART_CLK_CONF
#define C_UART_RST_DIS            0x00000002    // P_UART_CLK_CONF

#define C_UART_PORT_SEL           0x01000000    // P_UART_INTERFACE_SEL

#define C_UART_SEND_BREAK         0x00000001    // P_UART_MODE_CTRL
#define C_UART_NO_PARITY          0x00000000    // P_UART_MODE_CTRL
#define C_UART_ODD_PARITY         0x00000002    // P_UART_MODE_CTRL
#define C_UART_EVEN_PARITY        0x00000006    // P_UART_MODE_CTRL
#define C_UART_STOP_1BIT          0x00000000    // P_UART_MODE_CTRL
#define C_UART_STOP_2BIT          0x00000008    // P_UART_MODE_CTRL
#define C_UART_FIFO_EN            0x00000010    // P_UART_MODE_CTRL
#define C_UART_DATA_5BIT          0x00000000    // P_UART_MODE_CTRL
#define C_UART_DATA_6BIT          0x00000020    // P_UART_MODE_CTRL
#define C_UART_DATA_7BIT          0x00000040    // P_UART_MODE_CTRL
#define C_UART_DATA_8BIT          0x00000060    // P_UART_MODE_CTRL
#define C_UART_CTRL_EN            0x00001000    // P_UART_MODE_CTRL
#define C_UART_TIMEOUT_INTEN      0x00002000    // P_UART_MODE_CTRL
#define C_UART_TX_INTEN           0x00004000    // P_UART_MODE_CTRL
#define C_UART_RX_INTEN           0x00008000    // P_UART_MODE_CTRL

#define C_UART_BUSY_FLAG          0x00000008    // P_UART_TXRX_STATUS
#define C_UART_RXFIFO_EMPTY       0x00000010    // P_UART_TXRX_STATUS
#define C_UART_TXFIFO_FULL        0x00000020    // P_UART_TXRX_STATUS
#define C_UART_RXFIFO_FULL        0x00000040    // P_UART_TXRX_STATUS
#define C_UART_TXFIFO_EMPTY       0x00000080    // P_UART_TXRX_STATUS
#define C_UART_TIMEOUT_FLAG       0x00002000    // P_UART_TXRX_STATUS
#define C_UART_TX_FLAG            0x00004000    // P_UART_TXRX_STATUS
#define C_UART_RX_FLAG            0x00008000    // P_UART_TXRX_STATUS

#define C_UART_FRAME_ERR          0x00000001    // P_UART_ERR_STATUS
#define C_UART_PARITY_ERR         0x00000002    // P_UART_ERR_STATUS
#define C_UART_BREAK_ERR          0x00000004    // P_UART_ERR_STATUS
#define C_UART_RXFIFOOV_ERR       0x00000008    // P_UART_ERR_STATUS
#define C_UART_RX_SIGNAL          0x00008000    // P_UART_ERR_STATUS

#define C_UART_WAKEUP_FLAG        0x00000002    // P_UART_WAKEUP_STATUS

//******************************************************************//
//                              SPI                                 //
//******************************************************************//

#define C_SPI_CLK_EN              0x00000001    // P_SPI_CLK_CONF
#define C_SPI_RST_DIS             0x00000002    // P_SPI_CLK_CONF

#define C_SPI_PORT_SEL            0x00000100    // P_SPI_INTERFACE_SEL

#define C_SPI_CLK_27MDIV2         0x00000000    // P_SPI_MODE_CTRL
#define C_SPI_CLK_27MDIV4         0x00000001    // P_SPI_MODE_CTRL
#define C_SPI_CLK_27MDIV8         0x00000002    // P_SPI_MODE_CTRL
#define C_SPI_CLK_27MDIV16        0x00000003    // P_SPI_MODE_CTRL
#define C_SPI_CLK_27MDIV32        0x00000004    // P_SPI_MODE_CTRL
#define C_SPI_CLK_27MDIV64        0x00000005    // P_SPI_MODE_CTRL
#define C_SPI_CLK_27MDIV128       0x00000006    // P_SPI_MODE_CTRL

#define C_SPI_SPO_HIGH            0x00000000    // P_SPI_MODE_CTRL
#define C_SPI_SPO_LOW             0x00000040    // P_SPI_MODE_CTRL
#define C_SPI_SPH_0               0x00000000    // P_SPI_MODE_CTRL
#define C_SPI_SPH_180             0x00000080    // P_SPI_MODE_CTRL
#define C_SPI_MASTER_MODE         0x00000000    // P_SPI_MODE_CTRL
#define C_SPI_SLAVE_MODE          0x02000000    // P_SPI_MODE_CTRL
#define C_SPI_SOFT_RST            0x04000000    // P_SPI_MODE_CTRL
#define C_SPI_TEST_MODE           0x08000000    // P_SPI_MODE_CTRL
#define C_SPI_NORMAL_MODE         0x00000000    // P_SPI_MODE_CTRL
#define C_SPI_CTRL_EN             0x80000000    // P_SPI_MODE_CTRL

#define C_SPI_TX_INTEN            0x40000000    // P_SPI_TX_STATUS
#define C_SPI_TX_FLAG             0x80000000    // P_SPI_TX_STATUS

#define C_SPI_RXOV_FLAG           0x04000000    // P_SPI_RX_STATUS
#define C_SPI_RX_INTEN            0x40000000    // P_SPI_RX_STATUS
#define C_SPI_RX_FLAG             0x80000000    // P_SPI_RX_STATUS

#define C_SPI_TXFIFO_EMPTY        0x00000001    // P_SPI_TXRX_STATUS
#define C_SPI_TXFIFO_NOTFULL      0x00000002    // P_SPI_TXRX_STATUS
#define C_SPI_RXFIFO_NOTEMPTY     0x00000004    // P_SPI_TXRX_STATUS
#define C_SPI_RXFIFO_FULL         0x00000008    // P_SPI_TXRX_STATUS
#define C_SPI_BUSY_FLAG           0x00000010    // P_SPI_TXRX_STATUS
#define C_SPI_AUTO_CLR            0x40000000    // P_SPI_TXRX_STATUS
#define C_SPI_MANNUAL_CLR         0x00000000    // P_SPI_TXRX_STATUS
#define C_SPI_OV_SKIP             0x00000000    // P_SPI_TXRX_STATUS
#define C_SPI_OV_OVERWRITE        0x80000000    // P_SPI_TXRX_STATUS

//******************************************************************//
//                              I2C                                 //
//******************************************************************//

#define C_I2C_CLK_EN              0x00000001    // P_I2C_CLK_CONF
#define C_I2C_RST_DIS             0x00000002    // P_I2C_CLK_CONF

#define C_I2C_PORT_SEL            0x00000001    // P_I2C_INTERFACE_SEL

#define C_I2C_8BIT_START          0x00000001    // P_I2C_MODE_CTRL
#define C_I2C_16BIT_START         0x00000002    // P_I2C_MODE_CTRL
#define C_I2C_8NBIT_START         0x00000004    // P_I2C_MODE_CTRL
#define C_I2C_8BIT_ACK            0x00000008    // P_I2C_MODE_CTRL
#define C_I2C_16BIT_ACK           0x00000010    // P_I2C_MODE_CTRL
#define C_I2C_8NBIT_ACK           0x00000020    // P_I2C_MODE_CTRL
#define C_I2C_TX_MODE             0x00000000    // P_I2C_MODE_CTRL
#define C_I2C_RX_MODE             0x00000040    // P_I2C_MODE_CTRL
#define C_I2C_END_NAK             0x00000000    // P_I2C_MODE_CTRL
#define C_I2C_END_ACK             0x00000080    // P_I2C_MODE_CTRL
#define C_I2C_8NBIT_STOP          0x00000100    // P_I2C_MODE_CTRL

#define C_I2C_INT_EN              0x00000002    // P_I2C_INT_STATUS
#define C_I2C_INT_FLAG            0x00000001    // P_I2C_INT_STATUS

//******************************************************************//
//                                SIO                               //
//******************************************************************//

#define C_JTAG_PORT_SEL           0x00000000    // P_SIO_INTERFACE_SEL
#define C_SIO_PORT_SEL            0x00000100    // P_SIO_INTERFACE_SEL

#define C_SIO_CLK_EN              0x00000001    // P_SIO_CLK_CONF
#define C_SIO_RST_DIS             0x00000002    // P_SIO_CLK_CONF

#define C_SIO_TXRX_STOP           0x00000000    // P_SIO_MODE_CTRL
#define C_SIO_TXRX_START          0x00000001    // P_SIO_MODE_CTRL
#define C_SIO_READ_MODE           0x00000000    // P_SIO_MODE_CTRL
#define C_SIO_WRITE_MODE          0x00000002    // P_SIO_MODE_CTRL
#define C_SIO_MSB_FIRST           0x00000000    // P_SIO_MODE_CTRL
#define C_SIO_LSB_FIRST           0x00000004    // P_SIO_MODE_CTRL
#define C_SIO_INT_CLR             0x00000080    // P_SIO_MODE_CTRL
#define C_SIO_ADDR_16BIT          0x00000000    // P_SIO_MODE_CTRL
#define C_SIO_ADDR_NONE           0x00000100    // P_SIO_MODE_CTRL
#define C_SIO_ADDR_8BIT           0x00000200    // P_SIO_MODE_CTRL
#define C_SIO_ADDR_24BIT          0x00000300    // P_SIO_MODE_CTRL
#define C_SIO_CLK_27MDIV16        0x00000000    // P_SIO_MODE_CTRL
#define C_SIO_CLK_27MDIV4         0x00000400    // P_SIO_MODE_CTRL
#define C_SIO_CLK_27MDIV8         0x00000800    // P_SIO_MODE_CTRL
#define C_SIO_CLK_27MDIV32        0x00000C00    // P_SIO_MODE_CTRL
#define C_SIO_RWBIT_NORMAL        0x00000000    // P_SIO_MODE_CTRL
#define C_SIO_RWBIT_LOW           0x00001000    // P_SIO_MODE_CTRL
#define C_SIO_INT_EN              0x00002000    // P_SIO_MODE_CTRL
#define C_SIO_DMA_EN              0x00004000    // P_SIO_MODE_CTRL
#define C_SIO_DATA_8BIT           0x00000000    // P_SIO_MODE_CTRL
#define C_SIO_DATA_16BIT          0x00008000    // P_SIO_MODE_CTRL
#define C_SIO_INT_FLAG            0x40000000    // P_SIO_MODE_CTRL
#define C_SIO_DATA_REQ            0x80000000    // P_SIO_MODE_CTRL

#define C_SIO_TX_MANUAL           0x00000000    // P_SIO_AUTO_CTRL
#define C_SIO_TX_AUTO             0x00000001    // P_SIO_AUTO_CTRL
#define C_SIO_RDYPIN_DETECT       0x00000002    // P_SIO_AUTO_CTRL

//******************************************************************//
//                             NAND                                 //
//******************************************************************//

#define C_NAND_PORT_SEL           0x00000001    // P_NAND_INTERFACE_SEL

#define C_NAND_CLK_EN             0x00000001    // P_NAND_CLK_CONF
#define C_NAND_RST_DIS            0x00000002    // P_NAND_CLK_CONF

#define C_NAND_PORT_EN            0x00000001    // P_NAND_MODE_CTRL
#define C_NAND_CEN_LOW            0x00000000    // P_NAND_MODE_CTRL
#define C_NAND_CEN_HIGH           0x00000002    // P_NAND_MODE_CTRL
#define C_NAND_WPN_LOW            0x00000000    // P_NAND_MODE_CTRL
#define C_NAND_WPN_HIGH           0x00000004    // P_NAND_MODE_CTRL
#define C_NAND_CMD_READ           0x00000000    // P_NAND_MODE_CTRL
#define C_NAND_CMD_WRITE          0x00000008    // P_NAND_MODE_CTRL
#define C_NAND_RDY_RISE           0x00000000    // P_NAND_MODE_CTRL
#define C_NAND_CLE_FALL           0x00000010    // P_NAND_MODE_CTRL
#define C_NAND_ALE_FALL           0x00000020    // P_NAND_MODE_CTRL
#define C_NAND_RD_RESV            0x00000030    // P_NAND_MODE_CTRL
#define C_NAND_ALE_1CYCLE         0x00000000    // P_NAND_MODE_CTRL
#define C_NAND_ALE_2CYCLE         0x00000040    // P_NAND_MODE_CTRL
#define C_NAND_ALE_3CYCLE         0x00000080    // P_NAND_MODE_CTRL
#define C_NAND_ALE_4CYCLE         0x000000C0    // P_NAND_MODE_CTRL
#define C_NAND_WENLOW_1CYCLE      0x00000000    // P_NAND_MODE_CTRL
#define C_NAND_WENLOW_2CYCLE      0x00000100    // P_NAND_MODE_CTRL
#define C_NAND_WENLOW_3CYCLE      0x00000200    // P_NAND_MODE_CTRL
#define C_NAND_WENLOW_4CYCLE      0x00000300    // P_NAND_MODE_CTRL
#define C_NAND_WENHIGH_1CYCLE     0x00000000    // P_NAND_MODE_CTRL
#define C_NAND_WENHIGH_2CYCLE     0x00000400    // P_NAND_MODE_CTRL
#define C_NAND_WENHIGH_3CYCLE     0x00000800    // P_NAND_MODE_CTRL
#define C_NAND_WENHIGH_4CYCLE     0x00000C00    // P_NAND_MODE_CTRL
#define C_NAND_RENLOW_1CYCLE      0x00000000    // P_NAND_MODE_CTRL
#define C_NAND_RENLOW_2CYCLE      0x00001000    // P_NAND_MODE_CTRL
#define C_NAND_RENLOW_3CYCLE      0x00002000    // P_NAND_MODE_CTRL
#define C_NAND_RENLOW_4CYCLE      0x00003000    // P_NAND_MODE_CTRL
#define C_NAND_RENHIGH_1CYCLE     0x00000000    // P_NAND_MODE_CTRL
#define C_NAND_RENHIGH_2CYCLE     0x00004000    // P_NAND_MODE_CTRL
#define C_NAND_RENHIGH_3CYCLE     0x00008000    // P_NAND_MODE_CTRL
#define C_NAND_RENHIGH_4CYCLE     0x0000C000    // P_NAND_MODE_CTRL

#define C_NAND_TXBUF_EMPTY        0x00000001    // P_NAND_INT_CTRL, P_NAND_INT_STATUS
#define C_NAND_RXBUF_FULL         0x00000002    // P_NAND_INT_CTRL, P_NAND_INT_STATUS
#define C_NAND_RDY_INT            0x00000004    // P_NAND_INT_CTRL, P_NAND_INT_STATUS
#define C_NAND_TX_MISS            0x00000008    // P_NAND_INT_CTRL, P_NAND_INT_STATUS
#define C_NAND_RX_MISS            0x00000010    // P_NAND_INT_CTRL, P_NAND_INT_STATUS
#define C_NAND_CMD_MISS           0x00000020    // P_NAND_INT_CTRL, P_NAND_INT_STATUS
#define C_NAND_CTRL_BUSY          0x00000040    // P_NAND_INT_STATUS
#define C_NAND_FLASH_RDY          0x00000080    // P_NAND_INT_STATUS

#define C_NAND_ECC_START          0x00000001    // P_NAND_ECC_CTRL
#define C_NAND_ECC0_RST           0x00000002    // P_NAND_ECC_CTRL
#define C_NAND_ECC1_RST           0x00000004    // P_NAND_ECC_CTRL

#define C_NAND_ECC0_NOERR         0x00000000    // P_NAND_ECC_STATUS
#define C_NAND_ECC0_1ERR          0x00004000    // P_NAND_ECC_STATUS
#define C_NAND_ECC0_2ERR          0x0000C000    // P_NAND_ECC_STATUS
#define C_NAND_ECC1_NOERR         0x00000000    // P_NAND_ECC_STATUS
#define C_NAND_ECC1_1ERR          0x40000000    // P_NAND_ECC_STATUS
#define C_NAND_ECC1_2ERR          0xC0000000    // P_NAND_ECC_STATUS

//******************************************************************//
//                              SD-Card                             //
//******************************************************************//

#define C_SD_PORT_SEL             0x00010000    // P_SD_INTERFACE_SEL

#define C_SD_CLK_EN               0x00000001    // P_SD_CLK_CONF
#define C_SD_RST_DIS              0x00000002    // P_SD_CLK_CONF

#define C_SD_BUS_1BIT             0x00000000    // P_SD_MODE_CTRL
#define C_SD_BUS_4BIT             0x00000100    // P_SD_MODE_CTRL
#define C_SD_DMA_EN               0x00000200    // P_SD_MODE_CTRL
#define C_SD_IOINT_DETECT         0x00000400    // P_SD_MODE_CTRL
#define C_SD_PORT_EN              0x00000800    // P_SD_MODE_CTRL

#define C_SD_CMDCOMPLETE_INTEN    0x00000001    // P_SD_INT_CTRL
#define C_SD_DATACOMPLETE_INTEN   0x00000002    // P_SD_INT_CTRL
#define C_SD_CMDBUFFULL_INTEN     0x00000004    // P_SD_INT_CTRL
#define C_SD_DATABUFFULL_INTEN    0x00000008    // P_SD_INT_CTRL
#define C_SD_DATABUFEMPTY_INTEN   0x00000010    // P_SD_INT_CTRL
#define C_SD_CARDDETECT_INTEN     0x00000020    // P_SD_INT_CTRL
#define C_SD_IO_INTEN             0x00000040    // P_SD_INT_CTRL

#define C_SD_CTRL_BUSY            0x00000001    // P_SD_INT_STATUS
#define C_SD_CARD_BUSY            0x00000002    // P_SD_INT_STATUS
#define C_SD_CMD_COMPLETE         0x00000004    // P_SD_INT_STATUS
#define C_SD_DATA_COMPLETE        0x00000008    // P_SD_INT_STATUS
#define C_SD_RSPINDEX_ERR         0x00000010    // P_SD_INT_STATUS
#define C_SD_RSPCRC_ERR           0x00000020    // P_SD_INT_STATUS
#define C_SD_CMDBUF_FULL          0x00000040    // P_SD_INT_STATUS
#define C_SD_DATABUF_FULL         0x00000080    // P_SD_INT_STATUS
#define C_SD_DATABUF_EMPTY        0x00000100    // P_SD_INT_STATUS
#define C_SD_TIME_OUT             0x00000200    // P_SD_INT_STATUS
#define C_SD_DATACRC_ERR          0x00000400    // P_SD_INT_STATUS
#define C_SD_CARD_PRESENT         0x00001000    // P_SD_INT_STATUS
#define C_SD_IO_INT               0x00002000    // P_SD_INT_STATUS

#define C_SD_CTRL_IDLE            0x00000040    // P_SD_COMMAND_SETUP
#define C_SD_CMD_START            0x00000080    // P_SD_COMMAND_SETUP
#define C_SD_CMD_WITHOUTDATA      0x00000000    // P_SD_COMMAND_SETUP
#define C_SD_CMD_WITHDATA         0x00000100    // P_SD_COMMAND_SETUP
#define C_SD_DATA_RECEIVE         0x00000000    // P_SD_COMMAND_SETUP
#define C_SD_DATA_TRANFER         0x00000200    // P_SD_COMMAND_SETUP
#define C_SD_SIGLE_BLOCK          0x00000000    // P_SD_COMMAND_SETUP
#define C_SD_MULTI_BLOCK          0x00000400    // P_SD_COMMAND_SETUP
#define C_SD_74CLK_START          0x00000800    // P_SD_COMMAND_SETUP
#define C_SD_RSP_R0               0x00000000    // P_SD_COMMAND_SETUP
#define C_SD_RSP_R1               0x00001000    // P_SD_COMMAND_SETUP
#define C_SD_RSP_R2               0x00002000    // P_SD_COMMAND_SETUP
#define C_SD_RSP_R3               0x00003000    // P_SD_COMMAND_SETUP
#define C_SD_RSP_R6               0x00006000    // P_SD_COMMAND_SETUP
#define C_SD_RSP_R1B              0x00007000    // P_SD_COMMAND_SETUP

//******************************************************************//
//                               LCD                                //
//******************************************************************//

#define C_LCD_PORT_AUO            0x00000001    // P_LCD_INTERFACE_SEL
#define C_LCD_PORT_TOPPOLY        0x00000002    // P_LCD_INTERFACE_SEL
#define C_LCD_PORT_STN            0x00000003    // P_LCD_INTERFACE_SEL

#define C_LCD_BUF0_SEL            0x00000000    // P_LCD_BUFFER_SEL
#define C_LCD_BUF1_SEL            0x00000001    // P_LCD_BUFFER_SEL
#define C_LCD_BUF2_SEL            0x00000002    // P_LCD_BUFFER_SEL

#define C_LCD_RST_DIS             0x00000002    // P_LCD_CLK_CONF
#define C_LCD_CLK_EN              0x00000001    // P_LCD_CLK_CONF

#define C_TFT_CLK_27M             0x00000000    // P_LCD_CLK_SEL
#define C_TFT_CLK_PLLUDIV2        0x00000008    // P_LCD_CLK_SEL
#define C_TFT_CLK_PLLUDIV3        0x00000010    // P_LCD_CLK_SEL
#define C_TFT_CLK_PLLUDIV4        0x00000018    // P_LCD_CLK_SEL
#define C_TFT_CLK_PLLUDIV6        0x00000020    // P_LCD_CLK_SEL
#define C_TFT_CLK_PLLUDIV8        0x00000028    // P_LCD_CLK_SEL

#define C_TFT_CTRL_EN             0x01000000    // P_TFT_MODE_CTRL
#define C_TFT_VER_DOUBLE          0x00000400    // P_TFT_MODE_CTRL
#define C_TFT_VER_HALF            0x00000800    // P_TFT_MODE_CTRL
#define C_TFT_HOR_DOUBLE          0x00000100    // P_TFT_MODE_CTRL
#define C_TFT_HOR_HALF            0x00000200    // P_TFT_MODE_CTRL
#define C_TFT_CLK_27MDIV1         0x00000000    // P_TFT_MODE_CTRL
#define C_TFT_CLK_27MDIV2         0x00000001    // P_TFT_MODE_CTRL
#define C_TFT_CLK_27MDIV4         0x00000002    // P_TFT_MODE_CTRL
#define C_TFT_CLK_27MDIV8         0x00000003    // P_TFT_MODE_CTRL

#define C_TFT_CCIR656_640         0x00000000    // P_TFT_DATA_FMT
#define C_TFT_CCIR656_720         0x00000100    // P_TFT_DATA_FMT
#define C_TFT_PARALLEL_RGB        0x00000000    // P_TFT_DATA_FMT
#define C_TFT_SERIAL_RGB          0x00000001    // P_TFT_DATA_FMT
#define C_TFT_SERIAL_RGBDM        0x00000002    // P_TFT_DATA_FMT
#define C_TFT_OUTPUT_CCIR601      0x00000003    // P_TFT_DATA_FMT
#define C_TFT_OUTPUT_CCIR656      0x00000004    // P_TFT_DATA_FMT

#define C_TFT_HOR_NEGATIVE        0x00000000    // P_TFT_HOR_SYNC
#define C_TFT_HOR_POSITIVE        0x01000000    // P_TFT_HOR_SYNC

#define C_TFT_VER_NEGATIVE        0x00000000    // P_TFT_VER_SYNC
#define C_TFT_VER_POSITIVE        0x01000000    // P_TFT_VER_SYNC

#define C_TFT_BUF_RGB565          0x00000000    // P_TFT_FRAME_FMT1
#define C_TFT_BUF_RGB1555         0x00000001    // P_TFT_FRAME_FMT1
#define C_TFT_BUF_YUYV            0x00000002    // P_TFT_FRAME_FMT1
#define C_TFT_BUF_4Y4U4Y4V        0x00000003    // P_TFT_FRAME_FMT1

#define C_TFT_BUFFER_ERR          0x01000000    // P_TFT_STATUS_SEL
#define C_TFT_FINISH_FLAG         0x00010000    // P_TFT_STATUS_SEL

#define C_TFT_OUTPUT_YCBCR        0x00000000    // P_TFT_DATA_SEQ
#define C_TFT_OUTPUT_YUV          0x01000000    // P_TFT_DATA_SEQ
#define C_TFT_SEQ_Y0U0Y1V0        0x00000000    // P_TFT_DATA_SEQ    for CCIR601
#define C_TFT_SEQ_Y0V0Y1U0        0x00010000    // P_TFT_DATA_SEQ    for CCIR601
#define C_TFT_SEQ_U0Y0V0Y1        0x00020000    // P_TFT_DATA_SEQ    for CCIR601
#define C_TFT_SEQ_V0Y0U0Y1        0x00030000    // P_TFT_DATA_SEQ    for CCIR601
#define C_TFT_SEQ_Y1U0Y0V0        0x00040000    // P_TFT_DATA_SEQ    for CCIR601
#define C_TFT_SEQ_Y1V0Y0U0        0x00050000    // P_TFT_DATA_SEQ    for CCIR601
#define C_TFT_SEQ_U0Y1V0Y0        0x00060000    // P_TFT_DATA_SEQ    for CCIR601
#define C_TFT_SEQ_V0Y1U0Y0        0x00070000    // P_TFT_DATA_SEQ    for CCIR601

#define C_TFT_SEQ_Y0CB0Y1CR0      0x00000000    // P_TFT_DATA_SEQ    for CCIR656
#define C_TFT_SEQ_Y0CR0Y1CB0      0x00010000    // P_TFT_DATA_SEQ    for CCIR656
#define C_TFT_SEQ_CB0Y0CR0Y1      0x00020000    // P_TFT_DATA_SEQ    for CCIR656
#define C_TFT_SEQ_CR0Y0CB0Y1      0x00030000    // P_TFT_DATA_SEQ    for CCIR656
#define C_TFT_SEQ_Y1CB0Y0CR0      0x00040000    // P_TFT_DATA_SEQ    for CCIR656
#define C_TFT_SEQ_Y1CR0Y0CB0      0x00050000    // P_TFT_DATA_SEQ    for CCIR656
#define C_TFT_SEQ_CB0Y1CR0Y0      0x00060000    // P_TFT_DATA_SEQ    for CCIR656
#define C_TFT_SEQ_CR0Y1CB0Y0      0x00070000    // P_TFT_DATA_SEQ    for CCIR656

#define C_TFT_ODD_RGB             0x00000000    // P_TFT_DATA_SEQ    for serial RGB and serial RGBDm odd line
#define C_TFT_ODD_GBR             0x00000100    // P_TFT_DATA_SEQ    for serial RGB and serial RGBDm odd line
#define C_TFT_ODD_BRG             0x00000200    // P_TFT_DATA_SEQ    for serial RGB and serial RGBDm odd line
#define C_TFT_ODD_RBG             0x00000300    // P_TFT_DATA_SEQ    for serial RGB and serial RGBDm odd line
#define C_TFT_ODD_BGR             0x00000400    // P_TFT_DATA_SEQ    for serial RGB and serial RGBDm odd line
#define C_TFT_ODD_GRB             0x00000500    // P_TFT_DATA_SEQ    for serial RGB and serial RGBDm odd line

#define C_TFT_EVEN_RGB            0x00000000    // P_TFT_DATA_SEQ    for serial RGB and serial RGBDm even line
#define C_TFT_EVEN_GBR            0x00000001    // P_TFT_DATA_SEQ    for serial RGB and serial RGBDm even line
#define C_TFT_EVEN_BRG            0x00000002    // P_TFT_DATA_SEQ    for serial RGB and serial RGBDm even line
#define C_TFT_EVEN_RBG            0x00000003    // P_TFT_DATA_SEQ    for serial RGB and serial RGBDm even line
#define C_TFT_EVEN_BGR            0x00000004    // P_TFT_DATA_SEQ    for serial RGB and serial RGBDm even line
#define C_TFT_EVEN_GRB            0x00000005    // P_TFT_DATA_SEQ    for serial RGB and serial RGBDm even line

#define C_TFT_INT_EN              0x01000000    // P_TFT_INT_STATUS
#define C_TFT_INT_FLAG            0x00010000    // P_TFT_INT_STATUS

#define C_TFT_BUF_YUV             0x00000000    // P_TFT_FRAME_FMT2
#define C_TFT_BUF_YCBCR           0x00000001    // P_TFT-FRAME_FMT2

//******************************************************************//
//                               TV                                 //
//******************************************************************//

#define C_TV_CLK_EN               0x00000001    // P_TV_CLK_CONF
#define C_TV_RST_DIS              0x00000002    // P_TV_CLK_CONF

#define C_TV_VBLANKINGSINT_EN     0x00000001    // P_TV_INT_CTRL
#define C_TV_VBLANKINGEINT_EN     0x00000002    // P_TV_INT_CTRL
#define C_TV_HVHITINT_EN          0x00000004    // P_TV_INT_CTRL
#define C_TV_LIGHTGUN0INT_EN      0x00000008    // P_TV_INT_CTRL
#define C_TV_LIGHTGUN1INT_EN      0x00000010    // P_TV_INT_CTRL

#define C_TV_VIDEODAC_EN          0x00000000    // P_TV_VIDEODAC_CTRL

#define C_TV_CTRL_EN              0x00001000    // P_TV_MODE_CTRL
#define C_TV_YCBCR422_MODE        0x00000000    // P_TV_MODE_CTRL
#define C_TV_4Y4U4Y4V_MODE        0x00000800    // P_TV_MODE_CTRL
#define C_TV_RGB565_MODE          0x00000000    // P_TV_MODE_CTRL
#define C_TV_ARGB1555_MODE        0x00000400    // P_TV_MODE_CTRL
#define C_TV_LITTLE_ENDIAN        0x00000000    // P_TV_MODE_CTRL
#define C_TV_BIG_ENDIAN           0x00000200    // P_TV_MODE_CTRL
#define C_TV_YCBCR_MODE           0x00000000    // P_TV_MODE_CTRL
#define C_TV_RGB_MODE             0x00000100    // P_TV_MODE_CTRL
#define C_TV_NTSC_TYPE            0x00000000    // P_TV_MODE_CTRL
#define C_TV_NTSCJ_TYPE           0x00000040    // P_TV_MODE_CTRL
#define C_TV_NTSC443_TYPE         0x00000080    // P_TV_MODE_CTRL
#define C_TV_NTSCX_TYPE           0x000000C0    // P_TV_MODE_CTRL
#define C_TV_QVGA_MODE            0x00000000    // P_TV_MODE_CTRL
#define C_TV_VGA_MODE             0x00000004    // P_TV_MODE_CTRL
#define C_TV_HVGA_MODE            0x00000008    // P_TV_MODE_CTRL
#define C_TV_QVGAX_MODE           0x0000000C    // P_TV_MODE_CTRL
#define C_TV_NTSC_MODE            0x00000000    // P_TV_MODE_CTRL
#define C_TV_PAL_MODE             0x00000002    // P_TV_MODE_CTRL
#define C_TV_NOINTERLACE_MODE     0x00000000    // P_TV_MODE_CTRL
#define C_TV_INTERLACE_MODE       0x00000001    // P_TV_MODE_CTRL

#define C_TV_SEL_BUFFER1          0x00000000    // P_TV_BUFFER_SEL
#define C_TV_SEL_BUFFER2          0x00000001    // P_TV_BUFFER_SEL
#define C_TV_SEL_BUFFER3          0x00000002    // P_TV_BUFFER_SEL

#define C_TV_Y_NOFILTER           0x00000000    // P_TV_FILTER_SEL
#define C_TV_Y_9TAP               0x00000001    // P_TV_FILTER_SEL
#define C_TV_YUPS_2TAP            0x00000000    // P_TV_FILTER_SEL
#define C_TV_YUPS_3TAP            0x00000004    // P_TV_FILTER_SEL
#define C_TV_YUPS_7TAP            0x00000008    // P_TV_FILTER_SEL
#define C_TV_UV_NOFILTER          0x00000000    // P_TV_FILTER_SEL
#define C_TV_UV_9TAP              0x00000010    // P_TV_FILTER_SEL
#define C_TV_UVUPS_2TAP           0x00000000    // P_TV_FILTER_SEL
#define C_TV_UVUPS_3TAP           0x00000040    // P_TV_FILTER_SEL
#define C_TV_UVUPS_7TAP           0x00000080    // P_TV_FILTER_SEL

#define C_TV_LIGHTGUN0_SEL        0x00000100    // P_TV_LIGHTGUN_SEL
#define C_TV_LIGHTGUN1_SEL        0x00000200    // P_TV_LIGHTGUN_SEL

//******************************************************************//
//                               DAC                                //
//******************************************************************//

#define C_DAC_CLK_EN              0x00000001    // P_DAC_CLK_CONF
#define C_DAC_RST_DIS             0x00000002    // P_DAC_CLK_CONF

#define C_DAC_CTRL_DIS            0x00000001    // P_DAC_MODE_CTRL1
#define C_DAC_OUTPUT_DIS          0x00000002    // P_DAC_MODE_CTRL1

#define C_DAC_FIFO_EN             0x00001000    // P_DAC_MODE_CTRL2
#define C_DAC_VOLUME_MAXDIV24     0x00000000    // P_DAC_MODE_CTRL2
#define C_DAC_VOLUME_MAXDIV8      0x00000040    // P_DAC_MODE_CTRL2
#define C_DAC_VOLUME_MAXDIV2      0x00000080    // P_DAC_MODE_CTRL2
#define C_DAC_VOLUME_MAXDIV1      0x000000C0    // P_DAC_MODE_CTRL2
#define C_DAC_FIFOOV_FLAG         0x00000020    // P_DAC_MODE_CTRL2
#define C_DAC_CHANNAL0_EN         0x00000002    // P_DAC_MODE_CTRL2
#define C_DAC_CHANNAL1_EN         0x00000001    // P_DAC_MODE_CTRL2 

#define C_DAC_INT_FLAG            0x00008000    // P_DAC_INT_STATUS
#define C_DAC_INT_EN              0x00004000    // P_DAC_INT_STATUS
#define C_DAC_MONO_MODE           0x00000000    // P_DAC_INT_STATUS
#define C_DAC_STEREO_MODE         0x00000004    // P_DAC_INT_STATUS
#define C_DAC_BUFFER_1K           0x00000000    // P_DAC_INT_STATUS
#define C_DAC_BUFFER_2K           0x00000001    // P_DAC_INT_STATUS
#define C_DAC_BUFFER_4K           0x00000002    // P_DAC_INT_STATUS
#define C_DAC_BUFFER_8K           0x00000003    // P_DAC_INT_STATUS

//******************************************************************//
//                              CSI                                 //
//******************************************************************//

#define C_CSI_CLK_EN              0x00000001    // P_CSI_CLK_CONF
#define C_CSI_RST_DIS             0x00000002    // P_CSI_CLK_CONF

#define C_CSI_PORT_GPIO           0x00000000    // P_CSI_PORT_SEL
#define C_CSI_PORT_CCIR601        0x00000100    // P_CSI_PORT_SEL
#define C_CSI_PORT_SUNPLUS        0x00000200    // P_CSI_PORT_SEL
#define C_CSI_PORT_CCIR656        0x00000300    // P_CSI_PORT_SEL

#define C_CSI_PIXELCLK_SRC        0x00000008    // P_CSI_CLK_SEL
#define C_CSI_PIXELCLK_INV        0x00000000    // P_CSI_CLK_SEL
#define C_CSI_CLK_27M             0x00000000    // P_CSI_CLK_SEL
#define C_CSI_CLK_24M             0x00000004    // P_CSI_CLK_SEL
#define C_CSI_CLK_DIV1            0x00000000    // P_CSI_CLK_SEL
#define C_CSI_CLK_DIV2            0x00000001    // P_CSI_CLK_SEL
#define C_CSI_CLK_DIV4            0x00000002    // P_CSI_CLK_SEL
#define C_CSI_CLK_DIV8            0x00000003    // P_CSI_CLK_SEL

#define C_CSI_PROBE_EN            0x00010000    // P_CSI_PROBE_SEL

#define C_CSI_CSI_EN              0x00000001    // P_CSI_TG_CTRL
#define C_CSI_CLKINV_SRC          0x00000000    // P_CSI_TG_CTRL
#define C_CSI_CLKINV_INV          0x00000010    // P_CSI_TG_CTRL
#define C_CSI_TG_VGA              0x00000004    // P_CSI_TG_CTRL
#define C_CSI_TG_QVGA             0x00000000    // P_CSI_TG_CTRL
#define C_CSI_TG_S202             0x00000002    // P_CSI_TG_CTRL
#define C_CSI_TG_S201             0x00000006    // P_CSI_TG_CTRL
#define C_CSI_IN_RGB888           0x00000000    // P_CSI_TG_CTRL
#define C_CSI_IN_RGB565           0x00000008    // P_CSI_TG_CTRL
#define C_CSI_IN_YUV              0x00000020    // P_CSI_TG_CTRL
#define C_CSI_OUT_RGB             0x00000000    // P_CSI_TG_CTRL
#define C_CSI_OUT_YUV422          0x00000040    // P_CSI_TG_CTRL
#define C_CSI_OUT_RGB             0x00000000    // P_CSI_TG_CTRL
#define C_CSI_TG_BSEN             0x00000080    // P_CSI_TG_CTRL
#define C_CSI_TG_CCIR601          0x00000000    // P_CSI_TG_CTRL
#define C_CSI_TG_CCIR656          0x00000100    // P_CSI_TG_CTRL
#define C_CSI_FGET_VSYHCUP        0x00000200    // P_CSI_TG_CTRL
#define C_CSI_FGET_VSYHCDOWN      0x00000000    // P_CSI_TG_CTRL
#define C_CSI_HRST_HSYHCUP        0x00000400    // P_CSI_TG_CTRL
#define C_CSI_HRST_HSYHCDOWN      0x00000000    // P_CSI_TG_CTRL
#define C_CSI_VADD_HSYHCUP        0x00000800    // P_CSI_TG_CTRL
#define C_CSI_VADD_HSYHCDOWN      0x00000000    // P_CSI_TG_CTRL
#define C_CSI_VRST_VSYHCUP        0x00001000    // P_CSI_TG_CTRL
#define C_CSI_VRST_VSYHCDOWN      0x00000000    // P_CSI_TG_CTRL
#define C_CSI_YUV_UYUV            0x00000000    // P_CSI_TG_CTRL
#define C_CSI_YUV_YUYV            0x00002000    // P_CSI_TG_CTRL
#define C_CSI_FIELDSEL_SRC        0x00000000    // P_CSI_TG_CTRL
#define C_CSI_FIELDSEL_INV        0x00004000    // P_CSI_TG_CTRL
#define C_CSI_INTERLACE_EN        0x00008000    // P_CSI_TG_CTRL
#define C_CSI_INTERLACE_DIS       0x00000000    // P_CSI_TG_CTRL
#define C_CSI_DATA_TYPE0          0x00000000    // P_CSI_TG_CTRL
#define C_CSI_DATA_TYPE1          0x00010000    // P_CSI_TG_CTRL
#define C_CSI_DATA_TYPE2          0x00020000    // P_CSI_TG_CTRL
#define C_CSI_DATA_TYPE3          0x00030000    // P_CSI_TG_CTRL
#define C_CSI_DATA_TYPE4          0x00040000    // P_CSI_TG_CTRL
#define C_CSI_DATA_TYPE5          0x00050000    // P_CSI_TG_CTRL
#define C_CSI_DATA_TYPE6          0x00060000    // P_CSI_TG_CTRL
#define C_CSI_DATA_TYPE7          0x00070000    // P_CSI_TG_CTRL
#define C_CSI_RESIZE_EN           0x00080000    // P_CSI_TG_CTRL
#define C_CSI_CSICLKOINV_EN       0x00100000    // P_CSI_TG_CTRL
#define C_CSI_QVGA27_EN           0x00200000    // P_CSI_TG_CTRL
#define C_CSI_RGB1555_EN          0x00400000    // P_CSI_TG_CTRL
#define C_CSI_BIGED_EN            0x01000000    // P_CSI_TG_CTRL
#define C_CSI_SMALLED_EN          0x00000000    // P_CSI_TG_CTRL
#define C_CSI_MP4OUT_YUV          0x00000000    // P_CSI_TG_CTRL
#define C_CSI_MP4OUT_4Y4U4V       0x02000000    // P_CSI_TG_CTRL
#define C_CSI_INV_UV_YUV          0x04000000    // P_CSI_TG_CTRL
#define C_CSI_INV_UV_YCBCR        0x00000000    // P_CSI_TG_CTRL
#define C_CSI_HALF_VGA_EN         0x10000000    // P_CSI_TG_CTRL
#define C_CSI_CUT_EN              0x20000000    // P_CSI_TG_CTRL

#define C_CSI_BUF0_SEL            0x00000000    // P_CSI_BUFFER_SEL
#define C_CSI_BUF1_SEL            0x00000001    // P_CSI_BUFFER_SEL
#define C_CSI_BUF2_SEL            0x00000002    // P_CSI_BUFFER_SEL
#define C_CSI_BUF3_SEL            0x00000003    // P_CSI_BUFFER_SEL

#define C_CSI_CAP_EN              0x00000001    // P_CSI_CAPTURE_CTRL

#define C_CSI_MD_UF               0x00000040    // P_CSI_INT_STATUS, P_CSI_INT_CTRL
#define C_CSI_FRAME_DIS           0x00000020    // P_CSI_INT_STATUS, P_CSI_INT_CTRL
#define C_CSI_POS_HIT             0x00000010    // P_CSI_INT_STATUS, P_CSI_INT_CTRL
#define C_CSI_MD_FRAME            0x00000008    // P_CSI_INT_STATUS, P_CSI_INT_CTRL
#define C_CSI_FRAME_END           0x00000004    // P_CSI_INT_STATUS, P_CSI_INT_CTRL
#define C_CSI_TG_CAPACK           0x00000002    // P_CSI_INT_STATUS, P_CSI_INT_CTRL
#define C_CSI_TG_OF               0x00000001    // P_CSI_INT_STATUS, P_CSI_INT_CTRL

#define C_CSI_MD_DIS              0x00000000    // P_CSI_MD_CTRL
#define C_CSI_MD_DIFF             0x00000002    // P_CSI_MD_CTRL
#define C_CSI_MD_COLOR            0x00000003    // P_CSI_MD_CTRL
#define C_CSI_FRAME_1             0x00000000    // P_CSI_MD_CTRL
#define C_CSI_FRAME_2             0x00000004    // P_CSI_MD_CTRL
#define C_CSI_FRAME_4             0x00000008    // P_CSI_MD_CTRL
#define C_CSI_FRAME_8             0x0000000C    // P_CSI_MD_CTRL
#define C_CSI_BLACK_0             0x00000000    // P_CSI_MD_CTRL
#define C_CSI_BLACK_1             0x00000010    // P_CSI_MD_CTRL
#define C_CSI_BLACK_2             0x00000020    // P_CSI_MD_CTRL
#define C_CSI_BLACK_3             0x00000030    // P_CSI_MD_CTRL
#define C_CSI_WHITE_0             0x00000000    // P_CSI_MD_CTRL
#define C_CSI_WHITE_1             0x00000040    // P_CSI_MD_CTRL
#define C_CSI_WHITE_2             0x00000080    // P_CSI_MD_CTRL
#define C_CSI_WHITE_3             0x000000C0    // P_CSI_MD_CTRL
#define C_CSI_SAMP_TYPE16         0x00000000    // P_CSI_MD_CTRL
#define C_CSI_SAMP_TYPE8          0x00000001    // P_CSI_MD_CTRL


//******************************************************************//
//                              LDM                                 //
//******************************************************************//

#define C_LDM_CTRL_EN             0x80000000    // P_LDM_MODE_CTRL
#define C_LDM_INT_EN              0x40000000    // P_LDM_MODE_CTRL
#define C_LDM_MIU_LDM             0x00000000    // P_LDM_MODE_CTRL
#define C_LDM_LDM_MIU             0x20000000    // P_LDM_MODE_CTRL
#define C_LDM_8BIT_MODE           0x00000000    // P_LDM_MODE_CTRL
#define C_LDM_16BIT_MODE          0x04000000    // P_LDM_MODE_CTRL
#define C_LDM_32BIT_MODE          0x08000000    // P_LDM_MODE_CTRL
#define C_LDM_32BIT_BURST         0x0C000000    // P_LDM_MODE_CTRL

#define C_LDM_CLK_EN              0x00000001    // P_LDM_CLK_CONF
#define C_LDM_RST_DIS             0x00000002    // P_LDM_CLK_CONF

#define C_LDM_INT_CLEAR           0x80000000    // C_LDM_INT_STATUS

//******************************************************************//
//                             BLNDMA                               //
//******************************************************************//

#define C_BLNDMA_CLK_EN           0x00000001    // P_BLNDMA_CLK_CONF
#define C_BLNDMA_RST_DIS          0x00000002    // P_BLNDMA_CLK_CONF

#define C_BLNDMA_A_DEST           0x00000001    // P_BLNDMA_MODE_CTRL1
#define C_BLNDMA_AB_DEST          0x00000002    // P_BLNDMA_MODE_CTRL1
#define C_BLNDMA_FILL_DEST        0x00000003    // P_BLNDMA_MODE_CTRL1
#define C_BLNDMA_YUV_RGB          0x00000004    // P_BLNDMA_MODE_CTRL1
#define C_BLNDMA_SUB_BLEND        0x00000000    // P_BLNDMA_MODE_CTRL1
#define C_BLNDMA_ADD_BLEND        0x00000100    // P_BLNDMA_MODE_CTRL1
#define C_BLNDMA_FILTER_MODE      0x00010000    // P_BLNDMA_MODE_CTRL1
#define C_BLNDMA_TRANSFER_START   0x01000000    // P_BLNDMA_MODE_CTRL1

#define C_BLNDMA_INT_FLAG         0x00000001    // P_BLNDMA_INT_STATUS
#define C_BLNDMA_BUSY_FLAG        0x00000100    // P_BLNDMA_INT_STATUS
#define C_BLNDMA_INT_EN           0x00010000    // P_BLNDMA_INT_STATUS
#define C_BLNDMA_INT_CLR          0x01000000    // P_BLNDMA_INT_STATUS

#define C_BLNDMA_A_LINEAR         0x00000000    // P_BLNDMA_ADDR_MODE
#define C_BLNDMA_A_BLOCK          0x00000001    // P_BLNDMA_ADDR_MODE
#define C_BLNDMA_B_LINEAR         0x00000000    // P_BLNDMA_ADDR_MODE
#define C_BLNDMA_B_BLOCK          0x00000100    // P_BLNDMA_ADDR_MODE
#define C_BLNDMA_DEST_LINEAR      0x00000000    // P_BLNDMA_ADDR_MODE
#define C_BLNDMA_DEST_BLOCK       0x00010000    // P_BLNDMA_ADDR_MODE

#define C_BLNDMA_ALPHA_BIT        0x00000001    // P_BLNDMA_MODE_CTRL2
#define C_BLNDMA_RGB565_MODE      0x00000000    // P_BLNDMA_MODE_CTRL2
#define C_BLNDMA_ARGB1555_MODE    0x00000100    // P_BLNDMA_MODE_CTRL2
#define C_BLNDMA_STATE_MASK       0x00070000    // P_BLNDMA_MODE_CTRL2
#define C_BLNDMA_IDLE_STATE       0x00000000    // P_BLNDMA_MODE_CTRL2
#define C_BLNDMA_READA_STATE      0x00010000    // P_BLNDMA_MODE_CTRL2
#define C_BLNDMA_READB_STATE      0x00020000    // P_BLNDMA_MODE_CTRL2
#define C_BLNDMA_BLEND_STATE      0x00030000    // P_BLNDMA_MODE_CTRL2
#define C_BLNDMA_WRITE_STATE      0x00040000    // P_BLNDMA_MODE_CTRL2

#define C_BLNDMA_WIDTH_256        0x00000000    // P_BLNDMA_SOURCEA_BACKGROUND, P_BLNDMA_SOURCEB_BACKGROUND,P_BLNDMA_DESTINATION_BACKGROUND
#define C_BLNDMA_WIDTH_320        0x00000001    // P_BLNDMA_SOURCEA_BACKGROUND, P_BLNDMA_SOURCEB_BACKGROUND,P_BLNDMA_DESTINATION_BACKGROUND
#define C_BLNDMA_WIDTH_512        0x00000002    // P_BLNDMA_SOURCEA_BACKGROUND, P_BLNDMA_SOURCEB_BACKGROUND,P_BLNDMA_DESTINATION_BACKGROUND
#define C_BLNDMA_WIDTH_640        0x00000003    // P_BLNDMA_SOURCEA_BACKGROUND, P_BLNDMA_SOURCEB_BACKGROUND,P_BLNDMA_DESTINATION_BACKGROUND
#define C_BLNDMA_WIDTH_1024       0x00000004    // P_BLNDMA_SOURCEA_BACKGROUND, P_BLNDMA_SOURCEB_BACKGROUND,P_BLNDMA_DESTINATION_BACKGROUND
#define C_BLNDMA_WIDTH_2048       0x00000005    // P_BLNDMA_SOURCEA_BACKGROUND, P_BLNDMA_SOURCEB_BACKGROUND,P_BLNDMA_DESTINATION_BACKGROUND
#define C_BLNDMA_HEIGHT_240       0x00000000    // P_BLNDMA_SOURCEA_BACKGROUND, P_BLNDMA_SOURCEB_BACKGROUND,P_BLNDMA_DESTINATION_BACKGROUND
#define C_BLNDMA_HEIGHT_256       0x00000100    // P_BLNDMA_SOURCEA_BACKGROUND, P_BLNDMA_SOURCEB_BACKGROUND,P_BLNDMA_DESTINATION_BACKGROUND
#define C_BLNDMA_HEIGHT_480       0x00000200    // P_BLNDMA_SOURCEA_BACKGROUND, P_BLNDMA_SOURCEB_BACKGROUND,P_BLNDMA_DESTINATION_BACKGROUND
#define C_BLNDMA_HEIGHT_512       0x00000300    // P_BLNDMA_SOURCEA_BACKGROUND, P_BLNDMA_SOURCEB_BACKGROUND,P_BLNDMA_DESTINATION_BACKGROUND
#define C_BLNDMA_HEIGHT_1024      0x00000400    // P_BLNDMA_SOURCEA_BACKGROUND, P_BLNDMA_SOURCEB_BACKGROUND,P_BLNDMA_DESTINATION_BACKGROUND
#define C_BLNDMA_HEIGHT_2048      0x00000500    // P_BLNDMA_SOURCEA_BACKGROUND, P_BLNDMA_SOURCEB_BACKGROUND,P_BLNDMA_DESTINATION_BACKGROUND

//******************************************************************//
//                               USB                                //
//******************************************************************//
#define C_USB_RST_DIS             0x00000004	// P_USB_CLK_CONF
#define C_USBH_CLK_EN             0x00000002	// P_USB_CLK_CONF
#define C_USBD_CLK_EN             0x00000001	// P_USB_CLK_CONF

//******************************************************************//
//                              MEPG4                               //
//******************************************************************//

#define C_MPEG4_EXTRACLK_EN       0x00000001    // P_MPEG4_CLK_CONF
#define C_MPEG4_MASTERCLK_EN      0x00000002    // P_MPEG4_CLK_CONF
#define C_MPEG4_RST_DIS           0x00000004    // P_MPEG4_CLK_CONF

#define C_MPEG4_CLK_AHBDIV1       0x00000000    // P_MPEG4_CLK_SEL
#define C_MPEG4_CLK_AHBDIV2       0x00000001    // P_MPEG4_CLK_SEL
#define C_MPEG4_CLK_AHBDIV3       0x00000002    // P_MPEG4_CLK_SEL
#define C_MPEG4_CLK_AHBDIV4       0x00000003    // P_MPEG4_CLK_SEL

#define C_MPEG4_YUV420_SEL        0x00000000    // P_MPEG4_YUV_SEL
#define C_MPEG4_YUV422_SEL        0x00000000    // P_MPEG4_YUV_SEL
#define C_MPEG4_YUV411_SEL        0x00000001    // P_MPEG4_YUV_SEL
#define C_MPEG4_YUV444_SEL        0x00000001    // P_MPEG4_YUV_SEL

#define C_MPEG4_JPEG_ENC          0x00000000    // P_MPEG4_MODE_CTRL1
#define C_MPEG4_JPEG_DEC          0x00000001    // P_MPEG4_MODE_CTRL1
#define C_MPEG4_MPEG1_ENC         0x00000002    // P_MPEG4_MODE_CTRL1
#define C_MPEG4_MPEG1_DEC         0x00000003    // P_MPEG4_MODE_CTRL1
#define C_MPEG4_MPEG4_ENC         0x00000006    // P_MPEG4_MODE_CTRL1
#define C_MPEG4_MPEG4_DEC         0x00000007    // P_MPEG4_MODE_CTRL1

#define C_MPEG4_YUV420_MODE       0x00000000    // P_MPEG4_MODE_CTRL1  if YUV_TYPE=0
#define C_MPEG4_YUV422_MODE       0x00000008    // P_MPEG4_MODE_CTRL1  if YUV_TYPE=0
#define C_MPEG4_YUV411_MODE       0x00000000    // P_MPEG4_MODE_CTRL1  if YUV_TYPE=1
#define C_MPEG4_YUV444_MODE       0x00000008    // P_MPEG4_MODE_CTRL1  if YUV_TYPE=1

#define C_MPEG4_COLOR_MODE        0x00000000    // P_MPEG4_MODE_CTRL1
#define C_MPEG4_BLACKWHITE_MODE   0x00000010    // P_MPEG4_MODE_CTRL1

#define C_MPEG4_BW_STANDARD       0x00000000    // P_MPEG4_MODE_CTRL1
#define C_MPEG4_BW_UVZERO         0x00000020    // P_MPEG4_MODE_CTRL1

#define C_MPEG4_Y_FULLRANGE       0x00000000    // P_MPEG4_MODE_CTRL1
#define C_MPEG4_Y_SUBRANGE        0x00000040    // P_MPEG4_MODE_CTRL1

#define C_MPEG4_UV_FULLRANGE      0x00000000    // P_MEPG4_MODE_CTRL1
#define C_MPEG4_UV_SUBRANGE       0x00000080    // P_MPEG4_MODE_CTRL1

#define C_MPEG4_JPEGDEC_8DIV8     0x00000000    // P_MPEG4_MODE_CTRL2
#define C_MPEG4_JPEGDEC_1DIV8     0x00000001    // P_MPEG4_MODE_CTRL2
#define C_MPEG4_JPEGDEC_2DIV8     0x00000002    // P_MPEG4_MODE_CTRL2
#define C_MPEG4_JPEGDEC_3DIV8     0x00000003    // P_MPEG4_MODE_CTRL2
#define C_MPEG4_JPEGDEC_4DIV8     0x00000004    // P_MPEG4_MODE_CTRL2
#define C_MPEG4_JPEGDEC_5DIV8     0x00000005    // P_MPEG4_MODE_CTRL2
#define C_MPEG4_JPEGDEC_6DIV8     0x00000006    // P_MPEG4_MODE_CTRL2
#define C_MPEG4_JPEGDEC_7DIV8     0x00000007    // P_MPEG4_MODE_CTRL2

#define C_MPEG4_ROTATE_EN         0x00000010    // P_MPEG4_MODE_CTRL2
#define C_MPEG4_X_MIRROR          0x00000020    // P_MPEG4_MODE_CTRL2
#define C_MPEG4_Y_MIRROR          0x00000040    // P_MPEG4_MODE_CTRL2
#define C_MPEG4_NO_ROTATE         0x00000000    // P_MPEG4_MODE_CTRL2
#define C_MPEG4_90_ROTATE         C_MPEG4_ROTATE_EN + C_MPEG4_Y_MIRROR
#define C_MPEG4_180_ROTATE        C_MPEG4_X_MIRROR + C_MPEG4_Y_MIRROR
#define C_MPEG4_270_ROTATE        C_MPEG4_ROTATE_EN + C_MPEG4_X_MIRROR
#define C_MPEG4_XY_MIRROR         C_MPEG4_X_MIRROR + C_MPEG4_Y_MIRROR

#define C_MPEG4_YUV_RANGESAT      0x0000080     // P_MPEG4_MODE_CTRL2

#define C_MPEG4_GOP_RST           0x00000001    // P_MPEG4_MODE_CTRL3
#define C_MPEG4_HALFPIXEL_EN      0x00000002    // P_MPEG4_MODE_CTRL3
#define C_MPEG4_SOFTWARE_RATECTRL 0x00000000    // P_MPEG4_MODE_CTRL3
#define C_MPEG4_HARDWARE_RATECTRL 0x00000004    // P_MPEG4_MODE_CTRL3
#define C_MPEG4_RATEINIT_SET      0x00000008    // P_MPEG4_MODE_CTRL3

#define C_MPEG4_SOPTRIG_EXT       0x00000000    // P_MPEG4_MODE_CTRL3
#define C_MPEG4_SOPTRIG_CPU       0x00000010    // P_MPEG4_MODE_CTRL3
#define C_MPEG4_UNRESTRICT_EN     0x00000020    // P_MPEG4_MODE_CTRL3
#define C_MPEG4_FRAME_HARDCTRL    0x00000000    // P_MPEG4_MODE_CTRL3
#define C_MPEG4_FRAME_SOFTCTRL    0x00000040    // P_MPEG4_MODE_CTRL3

#define C_MPEG4_ENCODE_START      0x00000001    // P_MPEG4_COMPRESS_CTRL
#define C_MPEG4_ENCODE_EOF        0x00000002    // P_MPEG4_COMPRESS_CTRL
#define C_MPEG4_SKIPFRAME_STATUS  0x00000004    // P_MPGE4_COMPRESS_CTRL
#define C_MPEG4_SOF_INFO          0x00000008    // P_MPEG4_COMPRESS_CTRL
#define C_MPEG4_DECODE_START      0x00000010    // P_MPEG4_COMPRESS_CTRL
#define C_MPEG4_DECODE_STATUS     0x00000010    // P_MPEG4_COMPRESS_CTRL

#define C_MPEG4_SRAM_EN           0x00000001    // P_MPEG4_SRAM_EN

#define C_MEPG4_MCWRITE_MODE      0x00000008    // P_MPEG4_YUV_MODE
#define C_MPEG4_YUV420TO422_START 0x00000010    // P_MPEG4_YUV_MODE
#define C_MPEG4_YUV420TO422_EN    0x00000020    // P_MPEG4_YUV_MODE

#define C_MPEG4_PFRAME_MODE       0x00000000    // P_MPEG4_FRAME_MODE
#define C_MPEG4_IFRAME_MODE       0x00000001    // P_MPEG4_FRAME_MODE

#define C_MPEG4_NORMAL_MODE       0x00000000    // P_MPEG4_BUFFER_CTRL
#define C_MPEG4_VC_MODE           0x00000080    // P_MPEG4_BUFFER_CTRL

#define C_MPEG4_MC_INT            0x00000001    // P_MPEG4_INT_CTRL, P_MPEG4_INT_STATUS
#define C_MPEG4_JPEG_INT          0x00000002    // P_MPEG4_INT_CTRL
#define C_MPEG4_EOF_INT           0x00000004    // P_MPEG4_INT_CTRL, P_MPEG4_INT_STATUS
#define C_MPEG4_SOF_INT           0x00000008    // P_MPEG4_INT_CTRL, P_MPEG4_INT_STATUS
#define C_MPEG4_DECERR_INT        0x00000010    // P_MPEG4_INT_CTRL, P_MPEG4_INT_STATUS
#define C_MPEG4_VLDLAST_INT       0x00000020    // P_MPEG4_INT_CTRL, P_MPEG4_INT_STATUS

#define C_MPEG4_QVALUE_ORIGIN     0x00000000    // P_MPEG4_QTABLE_CTRL
#define C_MPEG4_QVALUE_ONE        0x00000001    // P_MPEG4_QTABLE_CTRL
#define C_MPEG4_QSCALE_QTABLE     0x00000000    // P_MPEG4_QTABLE_CTRL
#define C_MPEG4_QSCALE_HARDWARE   0x00000002    // P_MPEG4_QTABLE_CTRL
#define C_MPEG4_SKIP_LUMZERO      0x00000000    // P_MPEG4_QTABLE_CTRL
#define C_MPEG4_SKIP_ALLZERO      0x00000004    // P_MPEG4_QTABLE_CTRL
#define C_MPEG4_EXTRDATA_EN       0x00000008    // P_MPEG4_QTABLE_CTRL

#define C_MPEG4_QTABLESRAM_DIS    0x00000000    // P_MPEG4_QTABLE_SRAM
#define C_MPEG4_QTABLESRAM_EN     0x00000001    // P_MPEG4_QTABLE_SRAM

#define C_MPEG4_JFIF_MODE         0x00000001    // P_MPEG4_JFIF_COMPATIBLE
#define C_MPEG4_JFIF_DIS          0x00000000    // P_MPEG4_JFIF_COMPATIBLE
#define C_MPEG4_JFIF_EN           0x00000001    // P_MPEG4_JFIF_COMPATIBLE

#define C_MPEG4_JFIFEND_FLAG      0x00000001    // P_MPEG4_JFIF_END

#define C_MPEG4_HIGH_PRECISION    0x00000000    // P_MPEG4_TRUNCATE_CTRL
#define C_MPEG4_LOW_PRECISION     0x00000001    // P_MPEG4_TRUNCATE_CTRL
#define C_MPEG4_ROUND_MODE        0x00000000    // P_MPEG4_TRUNCATE_CTRL
#define C_MPEG4_TRUNCATE_MODE     0x00000002    // P_MPEG4_TRUNCATE_CTRL

#define C_MPEG4_QUANTIFY_ROUND    0x00000000    // P_MPEG4_TRUNCATE_CTRL
#define C_MPEG4_QUANTIFY_TRUNCATE 0x00000001    // P_MPEG4_TRUNCATE_CTRL
#define C_MPEG4_DCT_9BIT          0x00000000    // P_MPEG4_TRUNCATE_CTRL
#define C_MPEG4_DCT_2BIT          0x00000002    // P_MPEG4_TRUNCATE_CTRL

#define C_MPEG4_NO_MATCHCODE      0x00000000    // P_MPEG4_MATCHCODE_CTRL
#define C_MPEG4_TWO_MATCHCODE     0x00000001    // P_MPEG4_MATCHCODE_CTRL
#define C_MPEG4_FOUR_MATCHCODE    0x00000002    // P_MPEG4_MATCHCODE_CTRL

#define C_MPEG4_H263_EN           0x00000001    // P_MPEG4_H263_CTRL
#define C_MPEG4_H263_SUBQCIF      0x00000002    // P_MPEG4_H263_CTRL
#define C_MPEG4_H263_QCIF         0x00000004    // P_MPEG4_H263_CTRL
#define C_MPEG4_H263_CIF          0x00000006    // P_MPEG4_H263_CTRL
#define C_MPEG4_H263_4CIF         0x00000008    // P_MPEG4_H263_CTRL
#define C_MPEG4_4MV_EN            0x00000040    // P_MPEG4_H263_CTRL
#define C_MPEG4_ACPREDEC_EN       0x00000080    // P_MPEG4_H263_CTRL

#define C_MPEG4_H263_GOBEN        0x00000001    // P_MPEG4_H263_STRUCTURE

#define C_MPEG4_CPU_TSRAM         0x00000001    // P_MPEG4_TSRAM_CTRL
#define C_MPEG4_CPU_REG           0x00000002    // P_MPEG4_TSRAM_CTRL
#define C_MPEG4_TSRAM_PAGE0       0x00000000    // P_MPEG4_TSRAM_CTRL
#define C_MPEG4_TSRAM_PAGE1       0x00000004    // P_MPEG4_TSRAM_CTRL
#define C_MPEG4_TSRAM_PAGE2       0x00000008    // P_MPEG4_TSRAM_CTRL
#define C_MPEG4_TSRAM_PAGE3       0x0000000C    // P_MPEG4_TSRAM_CTRL
#define C_MPEG4_TSRAM_PAGE4       0x00000010    // P_MPEG4_TSRAM_CTRL
#define C_MPEG4_TSRAM_PAGE5       0x00000014    // P_MPEG4_TSRAM_CTRL
#define C_MPEG4_TSRAM_PAGE6       0x00000018    // P_MPEG4_TSRAM_CTRL
#define C_MPEG4_TSRAM_PAGE7       0x0000001C    // P_MPEG4_TSRAM_CTRL


#endif  //_SCORE7_CONSTANTS_H
