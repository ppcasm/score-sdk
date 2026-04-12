#ifndef _SCORE7_REGISTERS_H
#define _SCORE7_REGISTERS_H

typedef volatile unsigned int UV32;
typedef volatile int SV32;

//**************************************************************//
//                        CKG & PLL                             //
//**************************************************************//
#define P_CLK_CPU_SEL                       (UV32*)0x88210004
#define P_CLK_AHB_CONF                      (UV32*)0x88210008
#define P_CLK_AHB_SEL                       (UV32*)0x8821000C
#define P_CLK_PLLV_CONF                     (UV32*)0x882100B4
#define P_CLK_PLLV_SEL                      (UV32*)0x882100B8
#define P_CLK_PLLAU_CONF                    (UV32*)0x882100bc
#define P_CLK_32K_CONF                      (UV32*)0x88210114
#define P_PLLV_STABLE_TIME                  (UV32*)0x88210104
#define P_BUFCTRL_CLK_CONF                  (UV32*)0x882100C8
//**************************************************************//
//                           GPIO                               //
//**************************************************************//
#define P_GPIO_CLK_CONF                     (UV32*)0x882100FC
#define P_IOA_GPIO_SETUP                    (UV32*)0x88200038
#define P_IOB_GPIO_SETUP                    (UV32*)0x8820004C
#define P_IOB_GPIO_INPUT                    (UV32*)0x88200070
#define P_IOA_GPIO_INPUT                    (UV32*)0x88200074
#define P_IOA_GPIO_INT                      (UV32*)0x88200090
//**************************************************************//
//                           SFTCFG                             //
//**************************************************************//
#define P_ROMCSN_INTERFACE_SEL              (UV32*)0x88200004
#define P_DRAM_INTERFACE_SEL                (UV32*)0x88200008
#define P_DRAM_GPIO_SETUP                   (UV32*)0x88200050
#define P_DRAM_GPIO_INPUT                   (UV32*)0x88200070
#define P_CLK_CPU2MPEG4_SEL                 (UV32*)0x882000C0
//**************************************************************//
//                            WDOG                              //
//**************************************************************//
#define P_WDOG_CLK_CONF                     (UV32*)0x88210084
#define P_WDOG_RESET_STATUS                 (UV32*)0x882100E8
#define P_WDOG_MODE_CTRL                    (UV32*)0x88170000
#define P_WDOG_CYCLE_SETUP                  (UV32*)0x88170004
#define P_WDOG_CLR_COMMAND                  (UV32*)0x88170008
//**************************************************************//
//                          Sleep-Wakeup                        //
//**************************************************************//
#define P_SLEEP_MODE_CTRL                   (UV32*)0x88210000
#define P_SLEEP_CLK_SEL                     (UV32*)0x882100DC
#define P_WAKEUP_KEYC_SEL                   (UV32*)0x88200008
#define P_WAKEUP_KEYC_CLR                   (UV32*)0x882100C0
//**************************************************************//
//                            INT                               //
//**************************************************************//
#define P_INT_CLK_CONF                      (UV32*)0x882100D0
#define P_INT_REQ_STATUS1                   (UV32*)0x880a0000
#define P_INT_REQ_STATUS2                   (UV32*)0x880a0004
#define P_INT_GROUP_PRI                     (UV32*)0x880a0008
#define P_INT_GROUP0_PRI                    (UV32*)0x880a0010
#define P_INT_GROUP1_PRI                    (UV32*)0x880a0014
#define P_INT_GROUP2_PRI                    (UV32*)0x880a0018
#define P_INT_GROUP3_PRI                    (UV32*)0x880a001C
#define P_INT_MASK_CTRL1                    (UV32*)0x880a0020
#define P_INT_MASK_CTRL2                    (UV32*)0x880a0024
//**************************************************************//
//                              MIU                             //
//**************************************************************//
#define P_MIU_CLK_CONF                      (UV32*)0x88210010
#define P_MIU_SDRAM_POWER                   (UV32*)0x8807005C
#define P_MIU_SDRAM_SETUP1                  (UV32*)0x88070060
#define P_MIU_SDRAM_SETUP2                  (UV32*)0x88070094
#define P_MIU_SDRAM_SETUP3                  (UV32*)0x88230060
#define P_MIU_SDRAM_STATUS                  (UV32*)0x8807006C
//**************************************************************//
//                            APBDMA                            //
//**************************************************************//
#define P_DMA_CLK_CONF                      (UV32*)0x88210058
#define P_DMA_BUSY_STATUS                   (UV32*)0x88080000
#define P_DMA_INT_STATUS                    (UV32*)0x88080004
#define P_DMA_AHB_SA0BA                     (UV32*)0x88080008
#define P_DMA_AHB_SA1BA                     (UV32*)0x8808000C
#define P_DMA_AHB_SA2BA                     (UV32*)0x88080010
#define P_DMA_AHB_SA3BA                     (UV32*)0x88080014
#define P_DMA_AHB_EA0BA                     (UV32*)0x88080018
#define P_DMA_AHB_EA1BA                     (UV32*)0x8808001C
#define P_DMA_AHB_EA2BA                     (UV32*)0x88080020
#define P_DMA_AHB_EA3BA                     (UV32*)0x88080024
#define P_DMA_APB_SA0                       (UV32*)0x88080028
#define P_DMA_APB_SA1                       (UV32*)0x8808002C
#define P_DMA_APB_SA2                       (UV32*)0x88080030
#define P_DMA_APB_SA3                       (UV32*)0x88080034
#define P_DMA_AHB_SA0BB                     (UV32*)0x8808004C
#define P_DMA_AHB_SA1BB                     (UV32*)0x88080050
#define P_DMA_AHB_SA2BB                     (UV32*)0x88080054
#define P_DMA_AHB_SA3BB                     (UV32*)0x88080058
#define P_DMA_AHB_EA0BB                     (UV32*)0x8808005C
#define P_DMA_AHB_EA1BB                     (UV32*)0x88080060
#define P_DMA_AHB_EA2BB                     (UV32*)0x88080064
#define P_DMA_AHB_EA3BB                     (UV32*)0x88080068
#define P_DMA_CHANNEL0_CTRL                 (UV32*)0x8808006C
#define P_DMA_CHANNEL1_CTRL                 (UV32*)0x88080070
#define P_DMA_CHANNEL2_CTRL                 (UV32*)0x88080074
#define P_DMA_CHANNEL3_CTRL                 (UV32*)0x88080078
#define P_DMA_CHANNEL_RESET                 (UV32*)0x8808007C
//**************************************************************//
//                           ADC                                //
//**************************************************************//
#define P_ADC_CLK_CONF                      (UV32*)0x882100AC
#define P_ADC_CLK_SEL                       (UV32*)0x882100B0
#define P_ADC_GPIO_SETUP                    (UV32*)0x88200048
#define P_ADC_GPIO_INPUT                    (UV32*)0x88200078
#define P_ADC_GPIO_INT                      (UV32*)0x8820009C
#define P_ADC_AINPUT_CTRL                   (UV32*)0x88200054
#define P_ADC_MIC_CTRL1                     (UV32*)0x881a0000
#define P_ADC_MIC_GAIN                      (UV32*)0x881a0004
#define P_ADC_SAMPLE_CLK                    (UV32*)0x881a0008
#define P_ADC_SAMPLE_HOLD                   (UV32*)0x881a000c
#define P_ADC_MIC_CTRL2                     (UV32*)0x881a0010
#define P_ADC_INT_STATUS                    (UV32*)0x881a0014
#define P_ADC_MANUAL_DATA                   (UV32*)0x881a0018
#define P_ADC_AUTO_DATA                     (UV32*)0x881a001c
#define P_ADC_MIC_DATA                      (UV32*)0x881a0020
//**************************************************************//
//                           DAC                                //
//**************************************************************//
#define P_DAC_BUFFER_SA                     (UV32*)0x88070054
#define P_DAC_CLK_CONF                      (UV32*)0x8821003C
#define P_DAC_FIFOBA_LOW                    (UV32*)0x88051080
#define P_DAC_FIFOBA_HIGH                   (UV32*)0x88051084
#define P_DAC_SAMPLE_CLK                    (UV32*)0x88051064
#define P_DAC_INT_STATUS                    (UV32*)0x88051088
#define P_DAC_MODE_CTRL1                    (UV32*)0x88051474
#define P_DAC_MODE_CTRL2                    (UV32*)0x88051034
#define P_DAC_OUTPUT_CH0                    (UV32*)0x88051040
#define P_DAC_OUTPUT_CH1                    (UV32*)0x88051044
//**************************************************************//
//                              Timer                           //
//**************************************************************//
#define P_TIMER_CLK_SEL                     (UV32*)0x882100E4
#define P_TIMER_INTERFACE_SEL               (UV32*)0x88200010
#define P_TIMER0_CLK_CONF                   (UV32*)0x8821006C
#define P_TIMER0_MODE_CTRL                  (UV32*)0x88160000
#define P_TIMER0_CCP_CTRL                   (UV32*)0x88160004
#define P_TIMER0_PRELOAD_DATA               (UV32*)0x88160008
#define P_TIMER0_CCP_DATA                   (UV32*)0x8816000C
#define P_TIMER0_COUNT_DATA                 (UV32*)0x88160010
#define P_TIMER1_CLK_CONF                   (UV32*)0x88210070
#define P_TIMER1_MODE_CTRL                  (UV32*)0x88161000
#define P_TIMER1_CCP_CTRL                   (UV32*)0x88161004
#define P_TIMER1_PRELOAD_DATA               (UV32*)0x88161008
#define P_TIMER1_CCP_DATA                   (UV32*)0x8816100C
#define P_TIMER1_COUNT_DATA                 (UV32*)0x88161010
#define P_TIMER2_CLK_CONF                   (UV32*)0x88210074
#define P_TIMER2_MODE_CTRL                  (UV32*)0x88162000
#define P_TIMER2_CCP_CTRL                   (UV32*)0x88162004
#define P_TIMER2_PRELOAD_DATA               (UV32*)0x88162008
#define P_TIMER2_CCP_DATA                   (UV32*)0x8816200C
#define P_TIMER2_COUNT_DATA                 (UV32*)0x88162010
#define P_TIMER3_CLK_CONF                   (UV32*)0x88210078
#define P_TIMER3_MODE_CTRL                  (UV32*)0x88163000
#define P_TIMER3_CCP_CTRL                   (UV32*)0x88163004
#define P_TIMER3_PRELOAD_DATA               (UV32*)0x88163008
#define P_TIMER3_CCP_DATA                   (UV32*)0x8816300C
#define P_TIMER3_COUNT_DATA                 (UV32*)0x88163010
#define P_TIMER4_CLK_CONF                   (UV32*)0x8821007C
#define P_TIMER4_MODE_CTRL                  (UV32*)0x88164000
#define P_TIMER4_CCP_CTRL                   (UV32*)0x88164004
#define P_TIMER4_PRELOAD_DATA               (UV32*)0x88164008
#define P_TIMER4_CCP_DATA                   (UV32*)0x8816400C
#define P_TIMER4_COUNT_DATA                 (UV32*)0x88164010
#define P_TIMER5_CLK_CONF                   (UV32*)0x88210080
#define P_TIMER5_MODE_CTRL                  (UV32*)0x88165000
#define P_TIMER5_CCP_CTRL                   (UV32*)0x88165004
#define P_TIMER5_PRELOAD_DATA               (UV32*)0x88165008
#define P_TIMER5_CCP_DATA                   (UV32*)0x8816500C
#define P_TIMER5_COUNT_DATA                 (UV32*)0x88165010
//**************************************************************//
//                           RTC                                //
//**************************************************************//
#define P_RTC_CLK_CONF                      (UV32*)0x88210088
#define P_RTC_TIME_SEC                      (UV32*)0x88166000
#define P_RTC_TIME_MIN                      (UV32*)0x88166004
#define P_RTC_TIME_HOUR                     (UV32*)0x88166008
#define P_RTC_ALM_SEC                       (UV32*)0x8816600C
#define P_RTC_ALM_MIN                       (UV32*)0x88166010
#define P_RTC_ALM_HOUR                      (UV32*)0x88166014
#define P_RTC_MODE_CTRL                     (UV32*)0x88166018
#define P_RTC_INT_STATUS                    (UV32*)0x8816601C
//**************************************************************//
//                           TMB                                //
//**************************************************************//
#define P_TMB_CLK_CONF                      (UV32*)0x882100E0
#define P_TMB_MODE_CTRL                     (UV32*)0x88166020
#define P_TMB_INT_STATUS                    (UV32*)0x88166024
#define P_TMB_RESET_COMMAND                 (UV32*)0x88166028
//**************************************************************//
//                           UART                               //
//**************************************************************//
#define P_UART_CLK_CONF                     (UV32*)0x8821005C
#define P_UART_INTERFACE_SEL                (UV32*)0x88200000
#define P_UART_GPIO_SETUP                   (UV32*)0x88200040
#define P_UART_GPIO_INPUT                   (UV32*)0x88200074
#define P_UART_GPIO_INT                     (UV32*)0x88200094
#define P_UART_MODE_CTRL                    (UV32*)0x88150008
#define P_UART_BAUDRATE_SETUP               (UV32*)0x8815000C
#define P_UART_TXRX_STATUS                  (UV32*)0x88150010
#define P_UART_ERR_STATUS                   (UV32*)0x88150004
#define P_UART_TXRX_DATA                    (UV32*)0x88150000
#define P_UART_WAKEUP_STATUS                (UV32*)0x88210110
//**************************************************************//
//                           SPI                                //
//**************************************************************//
#define P_SPI_CLK_CONF                      (UV32*)0x88210098
#define P_SPI_INTERFACE_SEL                 (UV32*)0x882000A4
#define P_SPI_MODE_CTRL                     (UV32*)0x88110000
#define P_SPI_TX_STATUS                     (UV32*)0x88110004
#define P_SPI_TX_DATA                       (UV32*)0x88110008
#define P_SPI_RX_STATUS                     (UV32*)0x8811000C
#define P_SPI_RX_DATA                       (UV32*)0x88110010
#define P_SPI_TXRX_STATUS                   (UV32*)0x88110014
//**************************************************************//
//                           I2C                                //
//**************************************************************//
#define P_I2C_CLK_CONF                      (UV32*)0x88210094
#define P_I2C_INTERFACE_SEL                 (UV32*)0x88200004
#define P_I2C_GPIO_SETUP                    (UV32*)0x88200044
#define P_I2C_GPIO_INPUT                    (UV32*)0x88200074
#define P_I2C_GPIO_INT                      (UV32*)0x88200098
#define P_I2C_MODE_CTRL                     (UV32*)0x88130020
#define P_I2C_INT_STATUS                    (UV32*)0x88130024
#define P_I2C_RATE_SETUP                    (UV32*)0x88130028
#define P_I2C_SLAVE_ADDR                    (UV32*)0x8813002C
#define P_I2C_DATA_ADDR                     (UV32*)0x88130030
#define P_I2C_TX_DATA                       (UV32*)0x88130034
#define P_I2C_RX_DATA                       (UV32*)0x88130038
//**************************************************************//
//                           SIO                                //
//**************************************************************//
#define P_SIO_INTERFACE_SEL                 (UV32*)0x88200004
#define P_JTAG_GPIO_SETUP                   (UV32*)0x88200034
#define P_JTAG_GPIO_INPUT                   (UV32*)0x88200070
#define P_JTAG_GPIO_INT                     (UV32*)0x8820008C
#define P_SIO_CLK_CONF                      (UV32*)0x882100A0
#define P_SIO_MODE_CTRL                     (UV32*)0x88120000
#define P_SIO_AUTO_CTRL                     (UV32*)0x88120004
#define P_SIO_DATA_ADDR                     (UV32*)0x88120008
#define P_SIO_TXRX_DATA                     (UV32*)0x8812000C
//**************************************************************//
//                           SD Card                            //
//**************************************************************//
#define P_SD_INTERFACE_SEL                  (UV32*)0x882000A4
#define P_SD_CLK_CONF                       (UV32*)0x882100A4
#define P_SD_MODE_CTRL                      (UV32*)0x88180018
#define P_SD_INT_CTRL                       (UV32*)0x8818001C
#define P_SD_INT_STATUS                     (UV32*)0x88180014
#define P_SD_COMMAND_SETUP                  (UV32*)0x88180008
#define P_SD_ARGUMENT_DATA                  (UV32*)0x8818000C
#define P_SD_RESPONSE_DATA                  (UV32*)0x88180010
#define P_SD_TX_DATA                        (UV32*)0x88180000
#define P_SD_RX_DATA                        (UV32*)0x88180004
//**************************************************************//
//                              NAND                            //
//**************************************************************//
#define P_NAND_INTERFACE_SEL                (UV32*)0x882000A4
#define P_NAND_GPIO_SETUP                   (UV32*)0x8820002C
#define P_NAND_GPIO_PULL                    (UV32*)0x88200030
#define P_NAND_GPIO_INPUT                   (UV32*)0x8820006C
#define P_NAND_GPIO_INT                     (UV32*)0x88200088
#define P_NAND_CLK_CONF                     (UV32*)0x882100A8
#define P_NAND_INT_CTRL                     (UV32*)0x88190014
#define P_NAND_MODE_CTRL                    (UV32*)0x88190000
#define P_NAND_CLE_COMMAND                  (UV32*)0x88190004
#define P_NAND_ALE_ADDR                     (UV32*)0x88190008
#define P_NAND_TX_DATA                      (UV32*)0x8819000C
#define P_NAND_RX_DATA                      (UV32*)0x88190010
#define P_NAND_INT_STATUS                   (UV32*)0x88190018
#define P_NAND_ECC_TRUELP                   (UV32*)0x8819001C
#define P_NAND_ECC_TRUECP                   (UV32*)0x88190020
#define P_NAND_ECC_CMPLP                    (UV32*)0x88190024
#define P_NAND_ECC_CMPCP                    (UV32*)0x88190028
#define P_NAND_ECC_STATUS                   (UV32*)0x8819002C
#define P_NAND_ECC_CTRL                     (UV32*)0x88190030
//**************************************************************//
//                              NOR                             //
//**************************************************************//
#define P_NOR_COMMAND_CTRL                  (UV32*)0x880700BC
#define P_NOR_BANK_SETUP                    (UV32*)0x880700C4
//**************************************************************//
//                           LCD                                //
//**************************************************************//
#define P_TFT_MODE_CTRL                     (UV32*)0x88040000
#define P_TFT_DATA_FMT                      (UV32*)0x88040004
#define P_TFT_HOR_ACT                       (UV32*)0x88040008
#define P_TFT_HOR_FRONT                     (UV32*)0x8804000C
#define P_TFT_HOR_BACK                      (UV32*)0x88040010
#define P_TFT_HOR_SYNC                      (UV32*)0x88040014
#define P_TFT_VER_ACT                       (UV32*)0x88040018
#define P_TFT_VER_FRONT                     (UV32*)0x8804001C
#define P_TFT_VER_BACK                      (UV32*)0x88040020
#define P_TFT_VER_SYNC                      (UV32*)0x88040024
#define P_TFT_FRAME_FMT1                    (UV32*)0x88040028
#define P_TFT_ROW_START                     (UV32*)0x8804002C
#define P_TFT_COL_START                     (UV32*)0x88040030
#define P_TFT_COL_WIDTH                     (UV32*)0x88040034
#define P_TFT_DUMMY_WIDTH                   (UV32*)0x88040038
#define P_TFT_BUFFER_STATUS                 (UV32*)0x8804003C
#define P_TFT_DATA_SEQ                      (UV32*)0x88040040
#define P_TFT_INT_STATUS                    (UV32*)0x88040050
#define P_TFT_FRAME_FMT2                    (UV32*)0x880400A0
#define P_LCD_CLK_CONF                      (UV32*)0x88210034
#define P_LCD_CLK_SEL                       (UV32*)0x88210038
#define P_LCD_INTERFACE_SEL                 (UV32*)0x88200000
#define P_LCD_BUFFER_SA1                    (UV32*)0x8807000C
#define P_LCD_BUFFER_SA2                    (UV32*)0x88070010
#define P_LCD_BUFFER_SA3                    (UV32*)0x88070014
#define P_LCD_BUFFER_SEL                    (UV32*)0x88090024
#define P_TFT_GPIO_DATA                     (UV32*)0x88200014
#define P_TFT_GPIO_OUTPUTEN                 (UV32*)0x88200018
#define P_TFT_GPIO_PULLUP                   (UV32*)0x8820001C
#define P_TFT_GPIO_PULLDOWN                 (UV32*)0x88200020
#define P_TFT_GPIO_INPUT                    (UV32*)0x88200064
#define P_TFT_GPIO_INT                      (UV32*)0x88200080
#define P_STN_MODE_CTRL                     (UV32*)0x88041000
#define P_STN_PIXEL_CLK                     (UV32*)0x88041004
#define P_STN_SEGMENT_NUM                   (UV32*)0x88041008
#define P_STN_COMMON_NUM                    (UV32*)0x8804100C
#define P_STN_ROW_START                     (UV32*)0x88041010
#define P_STN_COL_START                     (UV32*)0x88041014
#define P_STN_DUMMY_WIDTH                   (UV32*)0x88041018
#define P_STN_LINE_COUNT                    (UV32*)0x8804101C
#define P_STN_DATA_FMT                      (UV32*)0x88041020
#define P_STN_BUFFER_STATUS                 (UV32*)0x88041024
#define P_STN_FRAME_FMT1                    (UV32*)0x88041028
#define P_STN_DATA_SEQ                      (UV32*)0x8804102C
#define P_STN_FRAME_FMT2                    (UV32*)0x880410A0
//**************************************************************//
//                              other                           //
//**************************************************************//
#define P_LVR_RESET_CTRL                    (UV32*)0x882100C4
//**************************************************************//
//                               CSI                            //
//**************************************************************//
#define P_CSI_CLK_CONF                      (UV32*)0x88210018
#define P_CSI_CLK_SEL                       (UV32*)0x8821001C
#define P_CSI_INTERFACE_SEL                 (UV32*)0x88200000
#define P_CSI_PROBE_SEL                     (UV32*)0x88200004
#define P_CSI_GPIO_SETUP                    (UV32*)0x88200024
#define P_CSI_GPIO_PULL                     (UV32*)0x88200028
#define P_CSI_GPIO_INPUT                    (UV32*)0x88200068
#define P_CSI_GPIO_INT                      (UV32*)0x88200084
#define P_CSI_TG_CTRL                       (UV32*)0x88000000
#define P_CSI_LINE_START                    (UV32*)0x88000004
#define P_CSI_WINDOW_START                  (UV32*)0x88000008
#define P_CSI_WINDOW_END                    (UV32*)0x8800000c
#define P_CSI_BACKGROUND_COLOR              (UV32*)0x88000010
#define P_CSI_TOP_DETECT                    (UV32*)0x88000014
#define P_CSI_BOTTOM_DETECT                 (UV32*)0x88000018
#define P_CSI_TRANSPARENT_COLOR             (UV32*)0x8800001C
#define P_CSI_BUFFER_SA1                    (UV32*)0x88000020
#define P_CSI_BUFFER_SA2                    (UV32*)0x88000024
#define P_CSI_BUFFER_SA3                    (UV32*)0x88000028
#define P_CSI_BUFFER_SEL                    (UV32*)0x88090008
#define P_CSI_CAPTURE_CTRL                  (UV32*)0x8800002C
#define P_CSI_MD_CTRL                       (UV32*)0x88000030
#define P_CSI_RECOGNITION_SA                (UV32*)0x88000034
#define P_CSI_POSITION_SETUP                (UV32*)0x88000038
#define P_CSI_CLASSIFICATION_SA             (UV32*)0x8800003C
#define P_CSI_COLOR_TABLE1                  (UV32*)0x88000040
#define P_CSI_COLOR_TABLE2                  (UV32*)0x88000044
#define P_CSI_COLOR_TABLE3                  (UV32*)0x88000048
#define P_CSI_COLOR_TABLE4                  (UV32*)0x8800004C
#define P_CSI_DETECT_REGION1                (UV32*)0x88000050
#define P_CSI_DETECT_REGION2                (UV32*)0x88000054
#define P_CSI_DETECT_REGION3                (UV32*)0x88000058
#define P_CSI_THRESHOLD_SETUP               (UV32*)0x8800005C
#define P_CSI_CUT_SETUP                     (UV32*)0x88000060
#define P_CSI_CAPTURE_COLORVALUE            (UV32*)0x88000074
#define P_CSI_INT_CTRL                      (UV32*)0x88000078
#define P_CSI_INT_STATUS                    (UV32*)0x8800007C
#define P_CSI_FRAMELOSS_INT                 (UV32*)0x88090028
#define P_CSI_Y2R_FACTOR1                   (UV32*)0x880000E8
#define P_CSI_Y2R_FACTOR2                   (UV32*)0x880000EC
#define P_CSI_Y2R_FACTOR3                   (UV32*)0x880000F0
#define P_CSI_R2Y_FACTOR1                   (UV32*)0x880000F4
#define P_CSI_R2Y_FACTOR2                   (UV32*)0x880000F8
#define P_CSI_R2Y_FACTOR3                   (UV32*)0x880000FC
//**************************************************************//
//                               TV                             //
//**************************************************************//
#define P_TV_CLK_CONF                       (UV32*)0x88210030
#define P_TV_INTERFACE_SEL                  (UV32*)0x88200000
#define P_TV_MODE_CTRL                      (UV32*)0x88030000
#define P_TV_SATURATION_SETUP               (UV32*)0x88030004
#define P_TV_HUE_SETUP                      (UV32*)0x88030008
#define P_TV_FADE_SETUP                     (UV32*)0x8803000C
#define P_TV_FILTER_SEL                     (UV32*)0x88030010
#define P_TV_LINE_COUNT                     (UV32*)0x88030020
#define P_TV_LIGHTGUN_SEL                   (UV32*)0x88200010
#define P_TV_LIGHTGUN_CTRL                  (UV32*)0x8803002C
#define P_TV_LIGHTGUN0_X                    (UV32*)0x88030030
#define P_TV_LIGHTGUN0_Y                    (UV32*)0x88030034
#define P_TV_LIGHTGUN1_X                    (UV32*)0x88030038
#define P_TV_LIGHTGUN1_Y                    (UV32*)0x8803003C
#define P_TV_INT_CTRL                       (UV32*)0x88030040
#define P_TV_VIDEODAC_CTRL                  (UV32*)0x88030050
#define P_TV_BUFFER_SA1                     (UV32*)0x88070000
#define P_TV_BUFFER_SA2                     (UV32*)0x88070004
#define P_TV_BUFFER_SA3                     (UV32*)0x88070008
#define P_TV_BUFFER_SEL                     (UV32*)0x88090020
#define P_TV_FRAME_COUNT                    (UV32*)0x88090034
//**************************************************************//
//                               LDM                            //
//**************************************************************//
#define P_LDM_CLK_CONF                      (UV32*)0x882100CC
#define P_LDM_MODE_CTRL                     (UV32*)0x880C0000
#define P_LDM_INT_STATUS                    (UV32*)0x880C0004
#define P_LDM_MIU_SA                        (UV32*)0x880C0008
#define P_LDM_MIU_EA                        (UV32*)0x880C000C
#define P_LDM_START_ADDR                    (UV32*)0x880C0010
#define P_LDM_END_ADDR                      (UV32*)0x880C0014
//**************************************************************//
//                              BLNDMA                          //
//**************************************************************//
#define P_BLNDMA_CLK_CONF                   (UV32*)0x88210050
#define P_BLNDMA_SOURCEA_SA                 (UV32*)0x880D0000
#define P_BLNDMA_SOURCEB_SA                 (UV32*)0x880D0004
#define P_BLNDMA_DESTINATION_SA             (UV32*)0x880D0008
#define P_BLNDMA_WIDTH_HEIGHT               (UV32*)0x880D000C
#define P_BLNDMA_FILL_PATTERN               (UV32*)0x880D0010
#define P_BLNDMA_MODE_CTRL1                 (UV32*)0x880D0014
#define P_BLNDMA_INT_STATUS                 (UV32*)0x880D0018
#define P_BLNDMA_ALPHA_VALUE                (UV32*)0x880D001C
#define P_BLNDMA_FILTER_PATTERN             (UV32*)0x880D0020
#define P_BLNDMA_ADDR_MODE                  (UV32*)0x880D0024
#define P_BLNDMA_MODE_CTRL2                 (UV32*)0x880D0028
#define P_BLNDMA_SOURCEA_BA                 (UV32*)0x880D0030
#define P_BLNDMA_SOURCEA_OA                 (UV32*)0x880D0034
#define P_BLNDMA_SOURCEA_BACKGROUND         (UV32*)0x880D0038
#define P_BLNDMA_SOURCEB_BA                 (UV32*)0x880D0040
#define P_BLNDMA_SOURCEB_OA                 (UV32*)0x880D0044
#define P_BLNDMA_SOURCEB_BACKGROUND         (UV32*)0x880D0048
#define P_BLNDMA_DESTINATION_BA             (UV32*)0x880D0050
#define P_BLNDMA_DESTINATION_OA             (UV32*)0x880D0054
#define P_BLNDMA_DESTINATION_BACKGROUND     (UV32*)0x880D0058
//**************************************************************//
//                               I2S                            //
//**************************************************************//
#define P_I2S_CLK_CONF                      (UV32*)0x8821008C
#define P_I2S_CLK_SEL                       (UV32*)0x88210090
#define P_I2S_INTERFACE_SEL                 (UV32*)0x88200004
#define P_I2S_MODE_CTRL                     (UV32*)0x88140000
#define P_I2S_MASTER_SETUP                  (UV32*)0x88140004
#define P_I2S_INT_STATUS                    (UV32*)0x88140008
#define P_I2S_FIFO_STATUS                   (UV32*)0x8814000C
#define P_I2S_RX_DATA                       (UV32*)0x88140010
//**************************************************************//
//                               USB                            //
//**************************************************************//
#define P_USB_CLK_CONF                      (UV32*)0x88210064
#define P_USB_WAKEUP_CTRL                   (UV32*)0x882100F4
#define P_USB_WAKEUP_STATUS                 (UV32*)0x88210110
#define P_USB_INTERFACE_SEL                 (UV32*)0x8820000C
#define P_USB_GPIO_SETUP                    (UV32*)0x8820003C
#define P_USB_GPIO_INPUT                    (UV32*)0x88200074
#define P_USB_GPIO_INT                      (UV32*)0x882000A0
//**************************************************************//
//                           USB Device                         //
//**************************************************************//
#define P_USBD_MODE_CTRL1                   (UV32*)0x881B00C0
#define P_USBD_MODE_CTRL2                   (UV32*)0x881B00C4
#define P_USBD_MODE_CTRL3                   (UV32*)0x881B015C
#define P_USBD_DMAINT_STATUS                (UV32*)0x881B0164
#define P_USBD_POWER_CTRL                   (UV32*)0x881B00C8
#define P_USBD_EP0_DATA                     (UV32*)0x881B00CC
#define P_USBD_BULKIN_DATA                  (UV32*)0x881B00D0
#define P_USBD_BULKOUT_DATA                 (UV32*)0x881B00D4
#define P_USBD_INTIN_DATA                   (UV32*)0x881B00D8
#define P_USBD_NULL_PACKET                  (UV32*)0x881B0160
#define P_USBD_EP_EVENT                     (UV32*)0x881B00DC
#define P_USBD_INT_STATUS1                  (UV32*)0x881B00E0
#define P_USBD_INT_CTRL                     (UV32*)0x881B00E4
#define P_USBD_INT_STATUS2                  (UV32*)0x881B00E8
#define P_USBD_COMMANDINT_CTRL              (UV32*)0x881B00EC
#define P_USBD_COMMANDINT_STATUS            (UV32*)0x881B00F0
#define P_USBD_EP_AUTOSET                   (UV32*)0x881B00F4
#define P_USBD_EP_SETSTALL                  (UV32*)0x881B00F8
#define P_USBD_EP_BUFFERCLR                 (UV32*)0x881B00FC
#define P_USBD_EP_EVENTCLR                  (UV32*)0x881B0100
#define P_USBD_EP0_WRITECOUNT               (UV32*)0x881B0104
#define P_USBD_BULKOUT_WRITECOUNT           (UV32*)0x881B0108
#define P_USBD_EP0_BUFFERSEL                (UV32*)0x881B010C
#define P_USBD_BULKIN_BUFFERSEL             (UV32*)0x881B0110
#define P_USBD_BULKOUT_BUFFERSEL            (UV32*)0x881B0114
#define P_USBD_EP0_BMREQUESTTYPE            (UV32*)0x881B0118
#define P_USBD_EP0_BREQUEST                 (UV32*)0x881B011C
#define P_USBD_EP0_WVALUE                   (UV32*)0x881B0120
#define P_USBD_EP0_WINDEX                   (UV32*)0x881B0124
#define P_USBD_EP0_WLENGTH                  (UV32*)0x881B0128
#define P_USBD_DMA_WRITECOUNT               (UV32*)0x881B0140
#define P_USBD_DMA_ACKCOUNT                 (UV32*)0x881B0144
#define P_USBD_EP_STALL                     (UV32*)0x881B0150
//**************************************************************//
//                           USB Host                           //
//**************************************************************//
#define P_USBH_MODE_CTRL                    (UV32*)0x881C0000
#define P_USBH_TIMING_SETUP                 (UV32*)0x881C0004
#define P_USBH_TXRX_DATA                    (UV32*)0x881C0008
#define P_USBH_TRANSFER_MODE                (UV32*)0x881C000C
#define P_USBH_DEVICE_ADDR                  (UV32*)0x881C0010
#define P_USBH_DEVICE_EP                    (UV32*)0x881C0014
#define P_USBH_TX_COUNT                     (UV32*)0x881C0018
#define P_USBH_RX_COUNT                     (UV32*)0x881C001C
#define P_USBH_FIFOIN_POINTER               (UV32*)0x881C0020
#define P_USBH_FIFOOUT_POINTER              (UV32*)0x881C0024
#define P_USBH_AUTOIN_COUNT                 (UV32*)0x881C0028
#define P_USBH_AUTOOUT_COUNT                (UV32*)0x881C002C
#define P_USBH_AUTO_TRANSFER                (UV32*)0x881C0030
#define P_USBH_MODE_STATUS                  (UV32*)0x881C0034
#define P_USBH_INT_STATUS                   (UV32*)0x881C0038
#define P_USBH_INT_CTRL                     (UV32*)0x881C003C
#define P_USBH_SOFT_RESET                   (UV32*)0x881C0044
#define P_USBH_INACK_COUNT                  (UV32*)0x881C005C
#define P_USBH_OUTACK_COUNT                 (UV32*)0x881C0060
#define P_USBH_RESETACK_COUNT               (UV32*)0x881C0064
#define P_USBH_D_READBACK                   (UV32*)0x881C006C
//**************************************************************//
//                            MPEG4                             //
//**************************************************************//
#define P_MPEG4_CLK_CONF                    (UV32*)0x882100EC
#define P_MPEG4_CLK_SEL                     (UV32*)0x882100F0
#define P_MPEG4_SOFT_RESET                  (UV32*)0x88220080
#define P_MPEG4_WIDTH_LOW                   (UV32*)0x88220000
#define P_MPEG4_WIDTH_HIGH                  (UV32*)0x88220004
#define P_MPEG4_HEIGHT_LOW                  (UV32*)0x88220008
#define P_MPEG4_HEIGHT_HIGH                 (UV32*)0x8822000C
#define P_MPEG4_HOROFFSET_LOW               (UV32*)0x88220010
#define P_MPEG4_HOROFFSET_HIGH              (UV32*)0x88220014
#define P_MPEG4_VEROFFSET_LOW               (UV32*)0x88220018
#define P_MPEG4_VEROFFSET_HIGH              (UV32*)0x8822001C
#define P_MPEG4_DECWIDTH_LOW                (UV32*)0x88220100
#define P_MPEG4_DECWIDTH_HIGH               (UV32*)0x88220104
#define P_MPEG4_DECHEIGHT_LOW               (UV32*)0x88220108
#define P_MPEG4_DECHEIGHT_HIGH              (UV32*)0x8822010C
#define P_MPEG4_FRAMEBUFFER_HSIZE           (UV32*)0x88070090
#define P_MPEG4_RAWBUFFER_SA1               (UV32*)0x88070070
#define P_MPEG4_RAWBUFFER_SA2               (UV32*)0x88070074
#define P_MPEG4_RAWBUFFER_SA3               (UV32*)0x88070078
#define P_MPEG4_RAWBUFFER_SEL               (UV32*)0x88090044
#define P_MPEG4_WRITEBUFFER_SA1             (UV32*)0x8807007C
#define P_MPEG4_WRITEBUFFER_SA2             (UV32*)0x88070080
#define P_MPEG4_WRITEBUFFER_SA3             (UV32*)0x88070084
#define P_MPEG4_WRITEBUFFER_SEL             (UV32*)0x88090048
#define P_MPEG4_REFBUFFER_SEL               (UV32*)0x88090050
#define P_MPEG4_VLCBUFFER_SA1               (UV32*)0x88070088
#define P_MPEG4_VLCBUFFER_SA2               (UV32*)0x8807008C
#define P_MPEG4_VLCBUFFER_SEL               (UV32*)0x88090054
#define P_MPEG4_VLCOFFSET_SALOW             (UV32*)0x88220020
#define P_MPEG4_VLCOFFSET_SAMID             (UV32*)0x88220024
#define P_MPEG4_VLCOFFSET_SAHIGH            (UV32*)0x88220028
#define P_MPEG4_DECVLCOFFSET_SALOW          (UV32*)0x88220110
#define P_MPEG4_DECVLCOFFSET_SAMID          (UV32*)0x88220114
#define P_MPEG4_DECVLCOFFSET_SAHIGH         (UV32*)0x88220118
#define P_MPEG4_YUV_SEL                     (UV32*)0x8822004C
#define P_MPEG4_MODE_CTRL1                  (UV32*)0x88220050
#define P_MPEG4_MODE_CTRL2                  (UV32*)0x88220054
#define P_MPEG4_MODE_CTRL3                  (UV32*)0x88220064
#define P_MPEG4_COMPRESS_CTRL               (UV32*)0x882200A0
#define P_MPEG4_SRAM_EN                     (UV32*)0x882206F8
#define P_MPEG4_TSRAM_CTRL                  (UV32*)0x882207E0
#define P_MPEG4_BUFFER_CTRL                 (UV32*)0x88220084
#define P_MPEG4_YUV_MODE                    (UV32*)0x882200C8
#define P_MPEG4_INT_CTRL                    (UV32*)0x882200D0
#define P_MPEG4_INT_STATUS                  (UV32*)0x882200D4
#define P_MPEG4_MATCHCODE_CTRL              (UV32*)0x88220648
#define P_MPEG4_MATCH_CODE1                 (UV32*)0x8822064C
#define P_MPEG4_MATCH_CODE2                 (UV32*)0x88220650
#define P_MPEG4_MATCH_CODE3                 (UV32*)0x88220654
#define P_MPEG4_MATCH_CODE4                 (UV32*)0x88220658
#define P_MPEG4_MATCHCODE_OFFSET            (UV32*)0x8822065C
#define P_MPEG4_H263_CTRL                   (UV32*)0x882207C8
#define P_MPEG4_H263_STRUCTURE              (UV32*)0x882207CC
#define P_MPEG4_IFRAME_QSCALE               (UV32*)0x88220640
#define P_MPEG4_PFRAME_QSCALE               (UV32*)0x88220644
#define P_MPEG4_VLCSIZE_LOW                 (UV32*)0x882206C8
#define P_MPEG4_VLCSIZE_MID                 (UV32*)0x882206CC
#define P_MPEG4_VLCSIZE_HIGH                (UV32*)0x882206D0
#define P_MPEG4_HOR_SCALE                   (UV32*)0x88220058
#define P_MPEG4_VER_SCALE                   (UV32*)0x8822005C
#define P_MPEG4_PFRAME_NUMBER               (UV32*)0x88220060
#define P_MPEG4_FRAME_MODE                  (UV32*)0x88220088
#define P_MPEG4_PFRAME_MONITER              (UV32*)0x882200A4
#define P_MPEG4_QTABLE1_START               (UV32*)0x88220400
#define P_MPEG4_QTABLE1_END                 (UV32*)0x882204FC
#define P_MPEG4_QTABLE2_START               (UV32*)0x88220500
#define P_MPEG4_QTABLE2_END                 (UV32*)0x882205FC
#define P_MPEG4_QTABLE_INDEX                (UV32*)0x88220600
#define P_MPEG4_QTABLE_CTRL                 (UV32*)0x88220604
#define P_MPEG4_QTABLE_SRAM                 (UV32*)0x88220608
#define P_MPEG4_JFIF_COMPATIBLE             (UV32*)0x88220610
#define P_MPEG4_TRUNCATE_CTRL               (UV32*)0x88220614
#define P_MPEG4_VLC_BIT                     (UV32*)0x88220618
#define P_MPEG4_JFIF_END                    (UV32*)0x8822061C
#define P_MPEG4_RESETMCU_LOW                (UV32*)0x88220620
#define P_MPEG4_RESETMCU_HIGH               (UV32*)0x88220624
#define P_MPEG4_VOPTIMEINC_SEL              (UV32*)0x88220660
#define P_MPEG4_MS_COUNT                    (UV32*)0x88220664
#define P_MPEG4_MS_EXTRAEN                  (UV32*)0x88220668
#define P_MPEG4_VOPTIMEINC_RESLOW           (UV32*)0x88220680
#define P_MPEG4_VOPTIMEINC_RESHIGH          (UV32*)0x88220684
#define P_MPEG4_VOPTIMEINC_UNITLOW          (UV32*)0x88220688
#define P_MPEG4_VOPTIMEINC_UNITHIGH         (UV32*)0x8822068C
#define P_MPEG4_VOPTIMEINC_LENGTH           (UV32*)0x88220690
#define P_MPEG4_HUFFMAN_START               (UV32*)0x88220800
#define P_MPEG4_HUFFMAN_END                 (UV32*)0x882208FC
#define P_MPEG4_LUMDCCODE_START             (UV32*)0x88220800
#define P_MPEG4_LUMDCCODE_END               (UV32*)0x8822085C
#define P_MPEG4_LUMOFFSET_SA                (UV32*)0x88220860
#define P_MPEG4_LUMOFFSET_EA                (UV32*)0x8822087C
#define P_MPEG4_LUMHUFFMANTABLE_START       (UV32*)0x88220880
#define P_MPEG4_LUMHUFFMANTABLE_END         (UV32*)0x8822089C
#define P_MPEG4_LUMACHUFFMANTABLE_START     (UV32*)0x88220980
#define P_MPEG4_LUMACHUFFMANTABLE_END       (UV32*)0x882209DC
#define P_MPEG4_LUMACHUFFMANOFFSET_SA       (UV32*)0x882209E0
#define P_MPEG4_LUMACHUFFMANOFFSET_EA       (UV32*)0x88220A34
#define P_MPEG4_CHROMDCCODE_START           (UV32*)0x882208C0
#define P_MPEG4_CHROMDCCODE_END             (UV32*)0x8822091C
#define P_MPEG4_CHROMOFFSET_SA              (UV32*)0x88220920
#define P_MPEG4_CHROMOFFSET_EA              (UV32*)0x8822093C
#define P_MPEG4_CHROMHUFFMANTABLE_START     (UV32*)0x88220940
#define P_MPEG4_CHROMHUFFMANTABLE_END       (UV32*)0x8822095C
#define P_MPEG4_CHROMACHUFFMANTABLE_START   (UV32*)0x88220A40
#define P_MPEG4_CHROMACHUFFMANTABLE_END     (UV32*)0x88220A90
#define P_MPEG4_CHROMACHUFFMANOFFSET_SA     (UV32*)0x88220AA0
#define P_MPEG4_CHROMACHUFFMANOFFSET_EA     (UV32*)0x88220AF4
//**************************************************************//
//                            DRAM                              //
//**************************************************************//
#define P_DRAM_INTERFACE_SEL                (UV32*)0x88200008
#define P_DRAM_GPIO_SETUP                   (UV32*)0x88200050
#define P_DRAM_GPIO_INPUT                   (UV32*)0x88200070


//////////////////////////////////////////////////////////////////
//						New register map                        //
//////////////////////////////////////////////////////////////////

/**
 * CSI:	0x0800_0000 ~ 0x0800_FFFF
 */
#define CSIBASE					0x88000000
	#define P_CSI_TG_CR				(UV32*)(CSIBASE + 0x00000000)
	#define P_CSI_TG_LSTART			(UV32*)(CSIBASE + 0x00000004)
	#define P_CSI_TG_START			(UV32*)(CSIBASE + 0x00000008)
	#define P_CSI_TG_END			(UV32*)(CSIBASE + 0x0000000C)
	#define P_CSI_TG_BLACK			(UV32*)(CSIBASE + 0x00000010)
	#define P_CSI_TG_BSUPPER		(UV32*)(CSIBASE + 0x00000014)
	#define P_CSI_TG_BSLOWER		(UV32*)(CSIBASE + 0x00000018)
	#define P_CSI_TG_TRANSP			(UV32*)(CSIBASE + 0x0000001C)
	#define P_CSI_TG_FBSADDR0     	(UV32*)(CSIBASE + 0x00000020)
	#define P_CSI_TG_FBSADDR1     	(UV32*)(CSIBASE + 0x00000024)
	#define P_CSI_TG_FBSADDR2     	(UV32*)(CSIBASE + 0x00000028)
	#define P_CSI_TG_CAP          	(UV32*)(CSIBASE + 0x0000002C)
	#define P_CSI_MD_CR           	(UV32*)(CSIBASE + 0x00000030)
	#define P_CSI_MD_SADDR        	(UV32*)(CSIBASE + 0x00000034)
	#define P_CSI_MD_POS          	(UV32*)(CSIBASE + 0x00000038)
	#define P_CSI_MD_SADDR1       	(UV32*)(CSIBASE + 0x0000003C)
	#define P_CSI_MD_CTABLE0      	(UV32*)(CSIBASE + 0x00000040)
	#define P_CSI_MD_CTABLE1      	(UV32*)(CSIBASE + 0x00000044)
	#define P_CSI_MD_CTABLE2      	(UV32*)(CSIBASE + 0x00000048)
	#define P_CSI_MD_CTABLE3      	(UV32*)(CSIBASE + 0x0000004C)
	#define P_CSI_MD_REG1         	(UV32*)(CSIBASE + 0x00000050)
	#define P_CSI_MD_REG2         	(UV32*)(CSIBASE + 0x00000054)
	#define P_CSI_MD_REG3         	(UV32*)(CSIBASE + 0x00000058)
	#define P_CSI_MD_TH           	(UV32*)(CSIBASE + 0x0000005C)
	#define P_CSI_MD_YUV          	(UV32*)(CSIBASE + 0x00000070)
	#define P_CSI_MD_RGB          	(UV32*)(CSIBASE + 0x00000074)
	#define P_CSI_IRQEN      	  	(UV32*)(CSIBASE + 0x00000078)
	#define P_CSI_IRQSTS          	(UV32*)(CSIBASE + 0x0000007C)
	#define P_CSI_Y2R_A1          	(UV32*)(CSIBASE + 0x000000E8)
	#define P_CSI_Y2R_A2          	(UV32*)(CSIBASE + 0x000000EC)
	#define P_CSI_Y2R_A3          	(UV32*)(CSIBASE + 0x000000F0)
	#define P_CSI_R2Y_A1          	(UV32*)(CSIBASE + 0x000000F4)
	#define P_CSI_R2Y_A2          	(UV32*)(CSIBASE + 0x000000F8)
	#define P_CSI_R2Y_A3          	(UV32*)(CSIBASE + 0x000000FC)

/**
 * PPU:	0x0801_0000 ~ 0x0801_FFFF
 */
#define PPUBASE					0x88010000
	#define P_PPU_CONTROL           (UV32*)(PPUBASE + 0x00000000)
	#define P_SP_Control			((volatile P_Sp_Control_DEF *)		(PPUBASE + 0x00000004))
	#define P_SP_MAX				(UV32*)(PPUBASE + 0x00000008)	
	#define P_BLN_FORMULA			(UV32*)(PPUBASE + 0x0000000C)	
	#define P_TRANS_RGB				(UV32*)(PPUBASE + 0x00000010)		
	#define P_PPU_TX1_X             (UV32*)(PPUBASE + 0x00000020)
	#define P_PPU_TX1_Y             (UV32*)(PPUBASE + 0x00000024)
	#define P_PPU_TX1_Attribute		(UV32*)(PPUBASE + 0x00000028) 	
	#define P_PPU_TX1_Control       (UV32*)(PPUBASE + 0x0000002C)
	#define P_PPU_TX1_N_PTR         (UV32*)(PPUBASE + 0x00000030)
	#define P_PPU_TX1_Blending      (UV32*)(PPUBASE + 0x00000038)
	#define P_PPU_TX2_X             (UV32*)(PPUBASE + 0x0000003C)
	#define P_PPU_TX2_Y             (UV32*)(PPUBASE + 0x00000040)
	#define P_PPU_TX2_Attribute		(UV32*)(PPUBASE + 0x00000044) 	
	#define P_PPU_TX2_Control       (UV32*)(PPUBASE + 0x00000048)
	#define P_PPU_TX2_N_PTR         (UV32*)(PPUBASE + 0x0000004C)
	#define P_PPU_TX2_Blending      (UV32*)(PPUBASE + 0x00000054)
	#define P_PPU_TX3_X             (UV32*)(PPUBASE + 0x00000058)
	#define P_PPU_TX3_Y             (UV32*)(PPUBASE + 0x0000005C)
	#define P_PPU_TX3_Attribute		(UV32*)(PPUBASE + 0x00000060) 	
	#define P_PPU_TX3_Control       (UV32*)(PPUBASE + 0x00000064)
	#define P_PPU_TX3_N_PTR         (UV32*)(PPUBASE + 0x00000068)
	#define P_PPU_TX3_Blending      (UV32*)(PPUBASE + 0x00000070)
	#define P_PPU_VComp_Value		(UV32*)(PPUBASE + 0x00000074)
	#define P_PPU_VComp_Offset		(UV32*)(PPUBASE + 0x00000078)
	#define P_PPU_VComp_Step		(UV32*)(PPUBASE + 0x0000007C)
	#define P_IRQ_CONTROL			(UV32*)(PPUBASE + 0x00000080)
	#define P_IRQ_STATUS			(UV32*)(PPUBASE + 0x00000084)
	#define P_IRQ_TMV				(UV32*)(PPUBASE + 0x00000088)
	#define P_IRQ_TMH				(UV32*)(PPUBASE + 0x0000008C)
	#define P_VBLK_TIME				(UV32*)(PPUBASE + 0x00000090)
	#define P_LINE_COUNTER			(UV32*)(PPUBASE + 0x00000094)
	#define P_PPU_TX1_START_ADR1    (UV32*)(PPUBASE + 0x000000A0)
	#define P_PPU_TX1_START_ADR2    (UV32*)(PPUBASE + 0x000000A4)
	#define P_PPU_TX1_START_ADR3    (UV32*)(PPUBASE + 0x000000A8)
	#define P_PPU_TX2_START_ADR1    (UV32*)(PPUBASE + 0x000000AC)
	#define P_PPU_TX2_START_ADR2    (UV32*)(PPUBASE + 0x000000B0)
	#define P_PPU_TX2_START_ADR3    (UV32*)(PPUBASE + 0x000000B4)
	#define P_PPU_TX3_START_ADR1    (UV32*)(PPUBASE + 0x000000B8)
	#define P_PPU_TX3_START_ADR2    (UV32*)(PPUBASE + 0x000000BC)
	#define P_PPU_TX3_START_ADR3    (UV32*)(PPUBASE + 0x000000C0)
	#define P_PPU_FB_START_ADR1     (UV32*)(PPUBASE + 0x000000C4)
	#define P_PPU_FB_START_ADR2     (UV32*)(PPUBASE + 0x000000C8)
	#define P_PPU_FB_START_ADR3     (UV32*)(PPUBASE + 0x000000CC)	
	#define P_SP_BUF_SA				((volatile GEN_REG_DEF *)		(PPUBASE + 0x000000D0))
	#define P_BG_COLOR_PALETTE		(UV32*)(PPUBASE + 0x00001000)	
	#define P_SP_COLOR_PALETTE		(UV32*)(PPUBASE + 0x00001800)
	#define P_PPU_Tx_HOffset_ADR	(UV32*)(PPUBASE + 0x00002000)		
	#define P_PPU_Tx1_HCmp_ADR	    (UV32*)(PPUBASE + 0x00003000)
	#define P_PPU_Sprite			(UV32*)(PPUBASE + 0x00004000)
	// - Added by Hyperscandev merged on 6/9/25
	#define P_SPRITE_ATTRIBUTE_BASE (UV32*)(PPUBASE + 0x00004004)
	#define P_SPRITE_X_BASE         (UV32*)(PPUBASE + 0x00004002)
	#define P_SPRITE_Y_BASE         (UV32*)(PPUBASE + 0x00004006)

/**
 * JPG:	0x0802_0000 ~ 0x0802_FFFF
 */
#define JPGBASE					0x88020000

/**
 * TV:	0x0803_0000 ~ 0x0803_FFFF
 */
#define TVEBASE					0x88030000
	#define P_TV_CONTROL          	(UV32*)(TVEBASE + 0x00000000)
	#define P_TV_SAT              	(UV32*)(TVEBASE + 0x00000004)
	#define P_TV_HUE              	(UV32*)(TVEBASE + 0x00000008)
	#define P_TV_FADE             	(UV32*)(TVEBASE + 0x0000000C)
	#define P_TV_ACT_START        	(UV32*)(TVEBASE + 0x00000010)
	#define P_TV_ACT_END          	(UV32*)(TVEBASE + 0x00000014)
	#define P_TV_IRQTMV           	(UV32*)(TVEBASE + 0x00000018)
	#define P_TV_IRQTMH           	(UV32*)(TVEBASE + 0x0000001C)
	#define P_TV_LINECON          	(UV32*)(TVEBASE + 0x00000020)
	#define P_TV_TEST	          	(UV32*)(TVEBASE + 0x0000003C)
	#define P_TV_LPCON	          	(UV32*)(TVEBASE + 0x00000040)
	#define P_TV_LPV	          	(UV32*)(TVEBASE + 0x00000044)
	#define P_TV_LPH	          	(UV32*)(TVEBASE + 0x00000048)

/**
 * LCD:	0x0804_0000 ~ 0x0804_FFFF
 */
#define LCDBASE					0x88040000

/**
 * SPU:	0x0805_0000 ~ 0x0805_FFFF
 */
#define SPUBASE					0x88050000

/**
 * CD:	0x0806_0000 ~ 0x0806_FFFF
 */
#define CDBASE					0x88060000

/**
 * MIU1: 0x0807_0000 ~ 0x0807_FFFF
 */
#define MIU1BASE					0x88070000
	#define P_CSI_START_ADR1        (UV32*)(MIU1BASE + 0x00000000)
	#define P_CSI_START_ADR2        (UV32*)(MIU1BASE + 0x00000004)
	#define P_CSI_START_ADR3        (UV32*)(MIU1BASE + 0x00000008)
	#define P_PPU_TEXT1_START_ADR1  (UV32*)(MIU1BASE + 0x0000000C)
	#define P_PPU_TEXT1_START_ADR2  (UV32*)(MIU1BASE + 0x00000010)
	#define P_PPU_TEXT1_START_ADR3  (UV32*)(MIU1BASE + 0x00000014)
	#define P_PPU_TEXT2_START_ADR1  (UV32*)(MIU1BASE + 0x00000018)
	#define P_PPU_TEXT2_START_ADR2  (UV32*)(MIU1BASE + 0x0000001C)
	#define P_PPU_TEXT2_START_ADR3  (UV32*)(MIU1BASE + 0x00000020)
	#define P_PPU_TEXT3_START_ADR1  (UV32*)(MIU1BASE + 0x00000024)
	#define P_PPU_TEXT3_START_ADR2  (UV32*)(MIU1BASE + 0x00000028)
	#define P_PPU_TEXT3_START_ADR3  (UV32*)(MIU1BASE + 0x0000002C)
	#define P_PPU_START_ADR1        (UV32*)(MIU1BASE + 0x00000030)
	#define P_PPU_START_ADR2        (UV32*)(MIU1BASE + 0x00000034)
	#define P_JPG_START_ADR1        (UV32*)(MIU1BASE + 0x00000038)
	#define P_JPG_START_ADR2        (UV32*)(MIU1BASE + 0x0000003C)
	#define P_JPGB_START_ADR        (UV32*)(MIU1BASE + 0x00000040)
	#define P_TV_START_ADR1         (UV32*)(MIU1BASE + 0x00000044)
	#define P_TV_START_ADR2         (UV32*)(MIU1BASE + 0x00000048)
	#define P_LCD_START_ADR1        (UV32*)(MIU1BASE + 0x0000004C)
	#define P_LCD_START_ADR2        (UV32*)(MIU1BASE + 0x00000050)
	#define P_SPU_START_ADR         (UV32*)(MIU1BASE + 0x00000054)
	#define P_CD_START_ADR          (UV32*)(MIU1BASE + 0x00000058)
	#define P_SDRAM_POWER_DOWN      (UV32*)(MIU1BASE + 0x0000005C)
	#define P_MIU1_SDRAM_SETTING    (UV32*)(MIU1BASE + 0x00000060)
	#define P_TV_START_ADR3         (UV32*)(MIU1BASE + 0x00000064)
	#define P_LCD_START_ADR3        (UV32*)(MIU1BASE + 0x00000068)
		
	#define P_SET_FLASH_CTL         (UV32*)(MIU1BASE + 0x00000100)
	#define P_SET_BT_BTC            (UV32*)(MIU1BASE + 0x00000104)

	#define P_MP4RAW_START_ADR1 	(UV32*)(MIU1BASE + 0x00000070)
	#define P_MP4RAW_START_ADR2 	(UV32*)(MIU1BASE + 0x00000074)
	#define P_MP4RAW_START_ADR3 	(UV32*)(MIU1BASE + 0x00000078)
	#define P_MP4W_START_ADR1  	 	(UV32*)(MIU1BASE + 0x0000007c)
	#define P_MP4W_START_ADR2   	(UV32*)(MIU1BASE + 0x00000080)
	#define P_MP4W_START_ADR3  	 	(UV32*)(MIU1BASE + 0x00000084)
	#define P_MP4V_START_ADR1 		(UV32*)(MIU1BASE + 0x00000088)
	#define P_MP4V_START_ADR2   	(UV32*)(MIU1BASE + 0x0000008c)
	#define P_MP4_FRAME_BUF_HSIZE	(UV32*)(MIU1BASE + 0x00000090)
		

/**
 * APBDMA: 0x0808_0000 ~ 0x0808_FFFF
 */
#define DMABASE					0x88080000
	#define P_DMA_BSY				(UV32*)(DMABASE + 0x00000000)
	#define P_DMA_INT				(UV32*)(DMABASE + 0x00000004)
	#define P_DMA_AHB_SA1A			(UV32*)(DMABASE + 0x00000008)
	#define P_DMA_AHB_SA2A			(UV32*)(DMABASE + 0x0000000c)
	#define P_DMA_AHB_SA3A			(UV32*)(DMABASE + 0x00000010)
	#define P_DMA_AHB_SA4A			(UV32*)(DMABASE + 0x00000014)
	#define P_DMA_AHB_EA1A			(UV32*)(DMABASE + 0x00000018)
	#define P_DMA_AHB_EA2A			(UV32*)(DMABASE + 0x0000001c)
	#define P_DMA_AHB_EA3A			(UV32*)(DMABASE + 0x00000020)
	#define P_DMA_AHB_EA4A			(UV32*)(DMABASE + 0x00000024)
	#define P_DMA_APB_SA4			(UV32*)(DMABASE + 0x00000034)
	#define P_DMA_AHB_SA1B			(UV32*)(DMABASE + 0x0000004C)
	#define P_DMA_AHB_SA2B			(UV32*)(DMABASE + 0x00000050)
	#define P_DMA_AHB_SA3B			(UV32*)(DMABASE + 0x00000054)
	#define P_DMA_AHB_SA4B			(UV32*)(DMABASE + 0x00000058)
	#define P_DMA_AHB_EA1B			(UV32*)(DMABASE + 0x0000005C)
	#define P_DMA_AHB_EA2B			(UV32*)(DMABASE + 0x00000060)
	#define P_DMA_AHB_EA3B			(UV32*)(DMABASE + 0x00000064)
	#define P_DMA_AHB_EA4B			(UV32*)(DMABASE + 0x00000068)
	#define P_DMA_CR1				(UV32*)(DMABASE + 0x0000006C)
	#define P_DMA_CR2				(UV32*)(DMABASE + 0x00000070)
	#define P_DMA_CR3				(UV32*)(DMABASE + 0x00000074)
	#define P_DMA_CR4				(UV32*)(DMABASE + 0x00000078)

/**
 * BUFCTL: 0x0809_0000 ~ 0x0809_FFFF
 */
#define BUFBASE					0x88090000
	#define P_C2P_SETTING           (UV32*)(BUFBASE + 0x00000000)
	#define P_PTR_SETTING           (UV32*)(BUFBASE + 0x00000004)
	#define P_CSI_BUF_PTR_REG       (UV32*)(BUFBASE + 0x00000008)
	#define P_PPUT1_BUF_PTR_REG     (UV32*)(BUFBASE + 0x0000000C)
	#define P_PPUT2_BUF_PTR_REG     (UV32*)(BUFBASE + 0x00000010)
	#define P_PPUT3_BUF_PTR_REG     (UV32*)(BUFBASE + 0x00000014)
	#define P_PPU_BUF_PTR_REG       (UV32*)(BUFBASE + 0x00000018)
	#define P_JPG_BUF_PTR_REG       (UV32*)(BUFBASE + 0x0000001C)
	#define P_TVE_BUF_PTR_REG       (UV32*)(BUFBASE + 0x00000020)
	#define P_LCD_BUF_PTR_REG       (UV32*)(BUFBASE + 0x00000024)
	#define P_BUFCTL_STATUS			(UV32*)(BUFBASE + 0x00000028)				
	#define P_PPU_FRAME_CNT			(UV32*)(BUFBASE + 0x0000002C)				
	#define P_PPU_FCNT_INC			(UV32*)(BUFBASE + 0x00000030)				
	#define P_TVE_FRAME_CNT			(UV32*)(BUFBASE + 0x00000034)				
	#define P_GPU_FRAME_END			(UV32*)(BUFBASE + 0x00000038)				
	#define P_P2T_SETTING         	(UV32*)(BUFBASE + 0x0000003C)
	#define P_P2L_SETTING			(UV32*)(BUFBASE + 0x00000040)				
	#define P_MP4RAW_BUF_PTR_REG	(UV32*)(BUFBASE + 0x00000044)				
	#define P_MP4W_BUF_PTR_REG		(UV32*)(BUFBASE + 0x00000048)				
	#define P_BUFCTL_SETTING		(UV32*)(BUFBASE + 0x0000004C)				
	#define P_MP4R_BUF_PTR_REG		(UV32*)(BUFBASE + 0x00000050)		
	#define P_MP4V_BUF_PTR_REG		(UV32*)(BUFBASE + 0x00000054)			
	#define P_HW4_SETTING			(UV32*)(BUFBASE + 0x00000058)

/**
 * IRQCTL: 0x080A_0000 ~ 0x080A_FFFF
 */
#define IRQBASE					0x880A0000

/**
 * GPUBUF: 0x080B_0000 ~ 0x080B_FFFF
 */
#define GPUBASE					0x880B0000

/**
 * LDMDMA: 0x080C_0000 ~ 0x080C_FFFF
 */
#define LDMBASE					0x880c0000
	#define P_LDM_CTRL              (UV32*)(LDMBASE + 0x00000000)
	#define P_LDM_STATUS            (UV32*)(LDMBASE + 0x00000004)
	#define P_LDM_MIU_START         (UV32*)(LDMBASE + 0x00000008)
	#define P_LDM_MIU_END           (UV32*)(LDMBASE + 0x0000000C)
	#define P_LDM_START             (UV32*)(LDMBASE + 0x00000010)
	#define P_LDM_END               (UV32*)(LDMBASE + 0x00000014)

/**
 * BLNDMA: 0x080D_0000 ~ 0x080D_FFFF
 */
#define BLNDMABASE				0x880D0000
    #define P_BLNDMA_SRCA_ADDR		(UV32*)(BLNDMABASE + 0x00000000)
	#define P_BLNDMA_SRCB_ADDR		(UV32*)(BLNDMABASE + 0x00000004)
	#define P_BLNDMA_DEST_ADDR		(UV32*)(BLNDMABASE + 0x00000008)
	#define P_BLNDMA_WIDTH_HEIGH	(UV32*)(BLNDMABASE + 0x0000000C)
	#define P_BLNDMA_FILL_PAT		(UV32*)(BLNDMABASE + 0x00000010)
	#define P_BLNDMA_CONTROL_1		(UV32*)(BLNDMABASE + 0x00000014)
	#define P_BLNDMA_IRQ_CONTROL	(UV32*)(BLNDMABASE + 0x00000018)
	#define P_BLNDMA_BLEND_FACTOR	(UV32*)(BLNDMABASE + 0x0000001C)
	#define P_BLNDMA_TRANSPARENT	(UV32*)(BLNDMABASE + 0x00000020)
	#define P_BLNDMA_CONTROL_2		(UV32*)(BLNDMABASE + 0x00000028)
	#define P_BLNDMA_ABASE_ADDR		(UV32*)(BLNDMABASE + 0x00000030)
	#define P_BLNDMA_AOFFSET_XY		(UV32*)(BLNDMABASE + 0x00000034)
	#define P_BLNDMA_A_BG			(UV32*)(BLNDMABASE + 0x00000038)
	#define P_BLNDMA_BBASE_ADDR		(UV32*)(BLNDMABASE + 0x00000040)
	#define P_BLNDMA_BOFFSET_XY		(UV32*)(BLNDMABASE + 0x00000044)
	#define P_BLNDMA_B_BG			(UV32*)(BLNDMABASE + 0x00000048)
	#define P_BLNDMA_DBASE_ADDR		(UV32*)(BLNDMABASE + 0x00000050)
	#define P_BLNDMA_DOFFSET_XY		(UV32*)(BLNDMABASE + 0x00000054)
	#define P_BLNDMA_D_BG			(UV32*)(BLNDMABASE + 0x00000058)

/**
 * TPGBUF: 0x080E_0000 ~ 0x080E_FFFF
 */
#define TPGBASE					0x880E0000

/**
 * AHBDEC: 0x080F_0000 ~ 0x080F_FFFF
 */
#define AHBDECBASE				0x880F0000

/**
 * GPIO: 0x0810_0000 ~ 0x0810_FFFF
 */
#define GPIOBASE				0x88100000
	#define	P_GPIO_TDR				(UV32*)(GPIOBASE + 0x00000000)

/**
 * SPI: 0x0811_0000 ~ 0x0811_FFFF
 */
#define SPIBASE					0x88110000
	#define P_SPI_CTRL				(UV32*)(SPIBASE + 0x00000000)
	#define P_SPI_TXSTS				(UV32*)(SPIBASE + 0x00000004)
	#define P_SPI_TXDATA			(UV32*)(SPIBASE + 0x00000008)
	#define P_SPI_RXSTS				(UV32*)(SPIBASE + 0x0000000c)
	#define P_SPI_RXDATA			(UV32*)(SPIBASE + 0x00000010)
	#define P_SPI_MISC				(UV32*)(SPIBASE + 0x00000014)

/**
 * SIO: 0x0812_0000 ~ 0x0812_FFFF
 */
#define SIOBASE				0x88120000

/**
 * I2C: 0x0813_0000 ~ 0x0813_FFFF
 */
#define I2CBASE					0x88130000
	#define P_I2CCR					(UV32*)(I2CBASE + 0x00000020)
	#define P_I2CINTR				(UV32*)(I2CBASE + 0x00000024)
	#define P_I2CCVR				(UV32*)(I2CBASE + 0x00000028)
	#define P_I2CID					(UV32*)(I2CBASE + 0x0000002C)
	#define P_I2CADDR				(UV32*)(I2CBASE + 0x00000030)
	#define P_I2CWDATA				(UV32*)(I2CBASE + 0x00000034)
	#define P_I2CRDATA				(UV32*)(I2CBASE + 0x00000038)
	#define	P_I2CPR					(UV32*)(I2CBASE + 0x0000003C)

/**
 * I2S: 0x0814_0000 ~ 0x0814_FFFF
 */
#define I2SBASE					0x88140000
	#define P_I2S_CTRL				(UV32*)(I2SBASE + 0x00000000)
	#define P_I2S_STAT				(UV32*)(I2SBASE + 0x00000004)
	#define P_I2S_FIFO				(UV32*)(I2SBASE + 0x00000008)
	#define P_I2S_DATA				(UV32*)(I2SBASE + 0x0000000c)

/**
 * UART: 0x0815_0000 ~ 0x0815_FFFF
 */
#define UARTBASE				0x88150000
	#define P_UARTDR				(UV32*)(UARTBASE+(0x00<<2))
	#define P_UARTRSR				(UV32*)(UARTBASE+(0x01<<2))
	#define P_UARTCR				(UV32*)(UARTBASE+(0x02<<2))
	#define P_UARTBUD				(UV32*)(UARTBASE+(0x03<<2))
	#define P_UARTFR				(UV32*)(UARTBASE+(0x04<<2))
	#define P_IRDACR				(UV32*)(UARTBASE+(0x08<<2))
	#define P_UARTBMR				(UV32*)(UARTBASE+(0x07<<2))
	#define P_TUBEDR				(UV32*)(UARTBASE + 0x7ffc)

/**
 * TIMER1: 0x0816_0000 ~ 0x0816_0FFF
 */
#define TM0BASE					0x88160000
	#define P_TM0_CTRL				(UV32*)(TM0BASE + 0x00000000)
	#define P_TM0_CCP_CTRL			(UV32*)(TM0BASE + 0x00000004)
	#define P_TM0_PRELOAD			(UV32*)(TM0BASE + 0x00000008)
	#define P_TM0_CCP_REG			(UV32*)(TM0BASE + 0x0000000c)
	#define P_TM0_UPCNT				(UV32*)(TM0BASE + 0x00000010)

/**
 * TIMER2: 0x0816_1000 ~ 0x0816_1FFF
 */
#define TM1BASE					0x88161000
	#define P_TM1_CTRL				(UV32*)(TM1BASE + 0x00000000)
	#define P_TM1_CCP_CTRL			(UV32*)(TM1BASE + 0x00000004)
	#define P_TM1_PRELOAD			(UV32*)(TM1BASE + 0x00000008)
	#define P_TM1_CCP_REG			(UV32*)(TM1BASE + 0x0000000c)
	#define P_TM1_UPCNT				(UV32*)(TM1BASE + 0x00000010)

/**
 * TIMER3: 0x0816_2000 ~ 0x0816_2FFF
 */
#define TM2BASE					0x88162000
	#define P_TM2_CTRL				(UV32*)(TM2BASE + 0x00000000)
	#define P_TM2_CCP_CTRL			(UV32*)(TM2BASE + 0x00000004)
	#define P_TM2_PRELOAD			(UV32*)(TM2BASE + 0x00000008)
	#define P_TM2_CCP_REG			(UV32*)(TM2BASE + 0x0000000c)
	#define P_TM2_UPCNT				(UV32*)(TM2BASE + 0x00000010)

/**
 * TIMER4: 0x0816_3000 ~ 0x0816_3FFF
 */
#define TM3BASE					0x88163000
	#define P_TM3_CTRL				(UV32*)(TM3BASE + 0x00000000)
	#define P_TM3_CCP_CTRL			(UV32*)(TM3BASE + 0x00000004)
	#define P_TM3_PRELOAD			(UV32*)(TM3BASE + 0x00000008)
	#define P_TM3_CCP_REG			(UV32*)(TM3BASE + 0x0000000c)
	#define P_TM3_UPCNT				(UV32*)(TM3BASE + 0x00000010)

/**
 * TIMER5: 0x0816_4000 ~ 0x0816_4FFF
 */
#define TM4BASE					0x88164000
	#define P_TM4_CTRL				(UV32*)(TM4BASE + 0x00000000)
	#define P_TM4_CCP_CTRL			(UV32*)(TM4BASE + 0x00000004)
	#define P_TM4_PRELOAD			(UV32*)(TM4BASE + 0x00000008)
	#define P_TM4_CCP_REG			(UV32*)(TM4BASE + 0x0000000c)
	#define P_TM4_UPCNT				(UV32*)(TM4BASE + 0x00000010)

/**
 * TIMER6: 0x0816_5000 ~ 0x0816_5FFF
 */
#define TM5BASE					0x88165000
	#define P_TM5_CTRL				(UV32*)(TM5BASE + 0x00000000)
	#define P_TM5_CCP_CTRL			(UV32*)(TM5BASE + 0x00000004)
	#define P_TM5_PRELOAD			(UV32*)(TM5BASE + 0x00000008)
	#define P_TM5_CCP_REG			(UV32*)(TM5BASE + 0x0000000c)
	#define P_TM5_UPCNT				(UV32*)(TM5BASE + 0x00000010)

/**
 * RTC: 0x0816_6000 ~ 0x0816_6FFF
 */
#define RTCBASE					0x88166000
	#define P_RTC_RTCSEC			(UV32*)(RTCBASE + 0x00000000)
	#define P_RTC_RTCMIN			(UV32*)(RTCBASE + 0x00000004)
	#define P_RTC_RTCHOU			(UV32*)(RTCBASE + 0x00000008)
	#define P_RTC_ALMSEC			(UV32*)(RTCBASE + 0x0000000c)
	#define P_RTC_ALMMIN			(UV32*)(RTCBASE + 0x00000010)
	#define P_RTC_ALMHOU			(UV32*)(RTCBASE + 0x00000014)
	#define P_RTC_CTRL1				(UV32*)(RTCBASE + 0x00000018)
	#define P_RTC_STST1				(UV32*)(RTCBASE + 0x0000001c)
	#define P_RTC_CTRL2				(UV32*)(RTCBASE + 0x00000020)
	#define P_RTC_STST2				(UV32*)(RTCBASE + 0x00000024)
	#define P_RTC_RESET				(UV32*)(RTCBASE + 0x00000028)

/**
 * WDOG: 0x0817_0000 ~ 0x0817_FFFF
 */
#define WDGBASE					0x88170000
	#define P_WDG_CTRL				(UV32*)(WDGBASE + 0x00000000)
	#define P_WDG_CYC				(UV32*)(WDGBASE + 0x00000004)
	#define P_WDG_CLR				(UV32*)(WDGBASE + 0x00000008)

/**
 * SD: 0x0818_0000 ~ 0x0818_FFFF
 */
#define SDCBASE					0x88180000
	#define P_SDC_DataTx           	(UV32*)(SDCBASE + 0x00000000)
	#define P_SDC_DataRx           	(UV32*)(SDCBASE + 0x00000004)
	#define P_SDC_Command          	(UV32*)(SDCBASE + 0x00000008)
	#define P_SDC_Arg              	(UV32*)(SDCBASE + 0x0000000C)
	#define P_SDC_Resp             	(UV32*)(SDCBASE + 0x00000010)
	#define P_SDC_Status           	(UV32*)(SDCBASE + 0x00000014)
	#define P_SDC_Control          	(UV32*)(SDCBASE + 0x00000018)
	#define P_SDC_IntEn            	(UV32*)(SDCBASE + 0x0000001C)

/**
 * FLASH: 0x0819_0000 ~ 0x0819_FFFF
 */
#define FLCBASE					0x88190000
	#define P_FL_CR					(UV32*)(FLCBASE + 0x00000000)
	#define P_FL_CLE				(UV32*)(FLCBASE + 0x00000004)
	#define P_FL_ALE				(UV32*)(FLCBASE + 0x00000008)
	#define P_FL_WD					(UV32*)(FLCBASE + 0x0000000C)
	#define P_FL_RD					(UV32*)(FLCBASE + 0x00000010)
	#define P_FL_INTEN				(UV32*)(FLCBASE + 0x00000014)
	#define P_FL_INTSTS				(UV32*)(FLCBASE + 0x00000018)
	#define P_FL_TRUELP				(UV32*)(FLCBASE + 0x0000001C)
	#define P_FL_TRUECP				(UV32*)(FLCBASE + 0x00000020)
	#define P_FL_CALLP				(UV32*)(FLCBASE + 0x00000024)
	#define P_FL_CALCP				(UV32*)(FLCBASE + 0x00000028)
	#define P_FL_ECCSTS				(UV32*)(FLCBASE + 0x0000002C)
	#define P_FL_CALECC				(UV32*)(FLCBASE + 0x00000030)

/**
 * ADC: 0x081A_0000 ~ 0x081A_FFFF
 */
#define ADCBASE					0x881a0000
	#define P_ADC_SETUP				(UV32*)(ADCBASE + 0x00000000)
	#define P_MIC_GAIN				(UV32*)(ADCBASE + 0x00000004)
	#define P_MCLK_SETUP			(UV32*)(ADCBASE + 0x00000008)
	#define P_SH_SETUP				(UV32*)(ADCBASE + 0x0000000c)
	#define P_AM_CTRL1				(UV32*)(ADCBASE + 0x00000010)
	#define P_AM_CTRL2				(UV32*)(ADCBASE + 0x00000014)
	#define P_ADC_DATA				(UV32*)(ADCBASE + 0x00000018)
	#define P_ASP_DATA				(UV32*)(ADCBASE + 0x0000001c)
	#define P_MIC_DATA				(UV32*)(ADCBASE + 0x00000020)
	#define P_ADC_TEST				(UV32*)(ADCBASE + 0x00000024)

/**
 * USB device: 0x081B_0000 ~ 0x081B_FFFF
 */
#define USBDEVBASE				0x881B0000

/**
 * USB host: 0x081C_0000 ~ 0x081C_FFFF
 */
#define USBHOSTBASE				0x881C0000

/**
 * Reserved: 0x081D_0000 ~ 0x081D_FFFF
 */
 

/**
 * Reserved: 0x081E_0000 ~ 0x081E_FFFF
 */


/**
 * Reserved: 0x081F_0000 ~ 0x081F_FFFF
 */


/**
 * SFTCFG: 0x0820_0000 ~ 0x0820_FFFF
 */
#define SFTCFGBASE				0x88200000
	#define P_TFT_GPIO_OUT			(UV32*)(SFTCFGBASE + 0x00000014)
	#define P_TFT_GPIO_OE			(UV32*)(SFTCFGBASE + 0x00000018)	
	#define P_TFT_GPIO_IN			(UV32*)(SFTCFGBASE + 0x00000064)
	#define P_ADC_GPIO_OE			(UV32*)(SFTCFGBASE + 0x00000048)
	#define P_ADC_GPIO_AEN			(UV32*)(SFTCFGBASE + 0x00000054)	
	#define P_ADC_GPIO_IN			(UV32*)(SFTCFGBASE + 0x00000078)
	#define P_SYS_C2M_STBLENG    	(UV32*)(SFTCFGBASE + 0x000000c0)

/**
 * CKG: 0x0821_0000 ~ 0x0821_FFFF
 */
#define CKGBASE					0x88210000
	#define P_CKG_CFG_APBDMA		(UV32*)(CKGBASE + (22 << 2))		
	#define P_CKG_CFG_UART			(UV32*)(CKGBASE + (23 << 2))
	#define P_CKG_CFG_TIMER0		(UV32*)(CKGBASE + (27 << 2))
	#define P_CKG_CFG_TIMER1		(UV32*)(CKGBASE + (28 << 2))
	#define P_CKG_CFG_TIMER2		(UV32*)(CKGBASE + (29 << 2))
	#define P_CKG_CFG_TIMER3		(UV32*)(CKGBASE + (30 << 2))
	#define P_CKG_CFG_TIMER4		(UV32*)(CKGBASE + (31 << 2))
	#define P_CKG_CFG_TIMER5		(UV32*)(CKGBASE + (32 << 2))
	#define P_CKG_CFG_WDOG			(UV32*)(CKGBASE + (33 << 2))		
	#define P_CKG_CFG_RTC			(UV32*)(CKGBASE + (34 << 2))	
	#define P_CKG_CFG_I2S			(UV32*)(CKGBASE + (35 << 2))
	#define P_CKG_SEL_I2S			(UV32*)(CKGBASE + (36 << 2))
	#define P_CKG_CFG_SPI			(UV32*)(CKGBASE + (38 << 2))
	#define P_CKG_SEL_SPI			(UV32*)(CKGBASE + (39 << 2))
	#define P_CKG_CFG_ADC			(UV32*)(CKGBASE + (43 << 2))
	#define P_CKG_SEL_ADC			(UV32*)(CKGBASE + (44 << 2))
	#define P_CKG_CFG_PLLA		    (UV32*)(CKGBASE + (47 << 2))	// added by Bruce
	#define P_CKG_CFG_TMB			(UV32*)(CKGBASE + (56 << 2))
	#define P_CKG_SEL_TIMER			(UV32*)(CKGBASE + (57 << 2))
	#define P_CKG_STS_WDOG			(UV32*)(CKGBASE + (58 << 2))
	#define P_CKG_CFG_SFT			(UV32*)(CKGBASE + (63 << 2))	// added by Bruce		

/**
 * MP4: 0x0822_0000 ~ 0x0822_FFFF
 */
#define MPEG4BASE			0x88220000

/////////////////////////////////////////////////////////////////////////////////
// MPEG Engine Register Definition 
/////////////////////////////////////////////////////////////////////////////////
	#define P_mjwidth_low	        (UV32*)(MPEG4BASE + (0x0000<<2))
	#define P_mjwidth_high	        (UV32*)(MPEG4BASE + (0x0001<<2))
	#define P_mjheight_low	        (UV32*)(MPEG4BASE + (0x0002<<2))
	#define P_mjheight_high	        (UV32*)(MPEG4BASE + (0x0003<<2))
	#define P_Mjhoffset_low	        (UV32*)(MPEG4BASE + (0x0004<<2))
	#define P_Mjhoffset_high	    (UV32*)(MPEG4BASE + (0x0005<<2))
	#define P_Mjvoffset_low	        (UV32*)(MPEG4BASE + (0x0006<<2))
	#define P_Mjvoffset_high	    (UV32*)(MPEG4BASE + (0x0007<<2))
	#define P_VlcOffaddr_low	    (UV32*)(MPEG4BASE + (0x0008<<2))
	#define P_VlcOffaddr_mid	    (UV32*)(MPEG4BASE + (0x0009<<2))
	#define P_VlcOffaddr_high	    (UV32*)(MPEG4BASE + (0x000a<<2))
	#define P_tmbOffaddr_low	    (UV32*)(MPEG4BASE + (0x0010<<2))
	#define P_tmbOffaddr_mid	    (UV32*)(MPEG4BASE + (0x0011<<2))
	#define P_tmbOffaddr_high	    (UV32*)(MPEG4BASE + (0x0012<<2))
	#define P_Yuvsel	            (UV32*)(MPEG4BASE + (0x0013<<2))
	#define P_setting_reg0014	    (UV32*)(MPEG4BASE + (0x0014<<2))
	#define P_setting_reg0015	    (UV32*)(MPEG4BASE + (0x0015<<2))
	#define P_Hsf	                (UV32*)(MPEG4BASE + (0x0016<<2))
	#define P_Vsf	                (UV32*)(MPEG4BASE + (0x0017<<2))
	#define P_Gopval	            (UV32*)(MPEG4BASE + (0x0018<<2))
	#define P_setting_reg0019	    (UV32*)(MPEG4BASE + (0x0019<<2))
	#define P_Vardthr_low	        (UV32*)(MPEG4BASE + (0x001a<<2))
	#define P_Vardthr_high	        (UV32*)(MPEG4BASE + (0x001b<<2))
	#define P_iniavgact	            (UV32*)(MPEG4BASE + (0x001c<<2))
	#define P_Avgactwei_low	        (UV32*)(MPEG4BASE + (0x001e<<2))
	#define P_Avgactwei_high	    (UV32*)(MPEG4BASE + (0x001f<<2))
	#define P_mjpgrst	            (UV32*)(MPEG4BASE + (0x0020<<2))
	#define P_setting_reg0021	    (UV32*)(MPEG4BASE + (0x0021<<2))
	#define P_iframe	            (UV32*)(MPEG4BASE + (0x0022<<2))
	#define P_Thumb_ctrl	        (UV32*)(MPEG4BASE + (0x0023<<2))
	#define P_memcsram_ctrl	        (UV32*)(MPEG4BASE + (0x0024<<2))
	#define P_probemode	            (UV32*)(MPEG4BASE + (0x0025<<2))
	#define P_Bist_ctrl_mpeg	    (UV32*)(MPEG4BASE + (0x0026<<2))
	#define P_sofeof_ctrl	        (UV32*)(MPEG4BASE + (0x0028<<2))
	#define P_Ifrme	                (UV32*)(MPEG4BASE + (0x0029<<2))
	#define P_AVGact	            (UV32*)(MPEG4BASE + (0x002a<<2))
	#define P_avgvard	            (UV32*)(MPEG4BASE + (0x002b<<2))
	#define P_meBistFail	        (UV32*)(MPEG4BASE + (0x002c<<2))
	#define P_mcBistFail	        (UV32*)(MPEG4BASE + (0x002d<<2))
	#define P_BistFinish	        (UV32*)(MPEG4BASE + (0x002e<<2))
	#define P_Hsfini	            (UV32*)(MPEG4BASE + (0x0030<<2))
	#define P_Vsfini	            (UV32*)(MPEG4BASE + (0x0031<<2))
	#define P_setting_reg0032	    (UV32*)(MPEG4BASE + (0x0032<<2))
	#define P_McMehsfl	            (UV32*)(MPEG4BASE + (0x0033<<2))
	#define P_Int_Mask	            (UV32*)(MPEG4BASE + (0x0034<<2))
	#define P_Int_clr	            (UV32*)(MPEG4BASE + (0x0035<<2))
	#define P_setting_reg0036	    (UV32*)(MPEG4BASE + (0x0036<<2))
	#define P_Vlcbufasize_low	    (UV32*)(MPEG4BASE + (0x0037<<2))
	#define P_Vlcbufasize_mid	    (UV32*)(MPEG4BASE + (0x0038<<2))
	#define P_Vlcbufasize_high	    (UV32*)(MPEG4BASE + (0x0039<<2))
	#define P_Vlcbufbsize_low	    (UV32*)(MPEG4BASE + (0x003a<<2))
	#define P_Vlcbufbsize_mid	    (UV32*)(MPEG4BASE + (0x003b<<2))
	#define P_Vlcbufbsize_high	    (UV32*)(MPEG4BASE + (0x003c<<2))
	#define P_decmjwidth_low	    (UV32*)(MPEG4BASE + (0x0040<<2))
	#define P_decmjwidth_high	    (UV32*)(MPEG4BASE + (0x0041<<2))
	#define P_decmjheight_low	    (UV32*)(MPEG4BASE + (0x0042<<2))
	#define P_decmjheight_high	    (UV32*)(MPEG4BASE + (0x0043<<2))
	#define P_decVlcOffaddr_low	    (UV32*)(MPEG4BASE + (0x0044<<2))
	#define P_decVlcOffaddr_mid	    (UV32*)(MPEG4BASE + (0x0045<<2))
	#define P_decVlcOffaddr_high	(UV32*)(MPEG4BASE + (0x0046<<2))
	#define P_lastmemaddr_low	    (UV32*)(MPEG4BASE + (0x0047<<2))
	#define P_lastmemaddr_mid	    (UV32*)(MPEG4BASE + (0x0048<<2))
	#define P_lastmemaddr_high	    (UV32*)(MPEG4BASE + (0x0049<<2))
	#define P_Lastlength	        (UV32*)(MPEG4BASE + (0x004a<<2))
	/////////////////////////////////////////////////////////////////////////////////
	// Texture Engine Register Definition
	/////////////////////////////////////////////////////////////////////////////////
	// reg0100 ~ reg013f for Qtable1
	// reg0140 ~ reg017f for Qtable2
	#define P_Qtable1_str	        (UV32*)(MPEG4BASE + (0x0100<<2))
	#define P_Qtable1_end	        (UV32*)(MPEG4BASE + (0x013f<<2))
	#define P_Qtable2_str	        (UV32*)(MPEG4BASE + (0x0140<<2))
	#define P_Qtable2_end	        (UV32*)(MPEG4BASE + (0x017f<<2))
	#define P_Noqtbl	            (UV32*)(MPEG4BASE + (0x0180<<2))
	#define P_setting_reg0181	    (UV32*)(MPEG4BASE + (0x0181<<2))
	#define P_QSramEn	            (UV32*)(MPEG4BASE + (0x0182<<2))
	#define P_setting_reg0183	    (UV32*)(MPEG4BASE + (0x0183<<2))
	#define P_JFIF	                (UV32*)(MPEG4BASE + (0x0184<<2))
	#define P_setting_reg0185	    (UV32*)(MPEG4BASE + (0x0185<<2))
	#define P_Vlcbit	            (UV32*)(MPEG4BASE + (0x0186<<2))
	#define P_JFIFend	            (UV32*)(MPEG4BASE + (0x0187<<2))
	#define P_Restartmcu_low	    (UV32*)(MPEG4BASE + (0x0188<<2))
	#define P_Restartmcu_high	    (UV32*)(MPEG4BASE + (0x0189<<2))
	#define P_IframeQscale	        (UV32*)(MPEG4BASE + (0x0190<<2))
	#define P_PframeQscale	        (UV32*)(MPEG4BASE + (0x0191<<2))
	#define P_MatchCnt	            (UV32*)(MPEG4BASE + (0x0192<<2))
	#define P_MatchCode0	        (UV32*)(MPEG4BASE + (0x0193<<2))
	#define P_MatchCode1	        (UV32*)(MPEG4BASE + (0x0194<<2))
	#define P_MatchCode2	        (UV32*)(MPEG4BASE + (0x0195<<2))
	#define P_MatchCode3	        (UV32*)(MPEG4BASE + (0x0196<<2))
	#define P_Offset	            (UV32*)(MPEG4BASE + (0x0197<<2))
	#define P_VOPTimeIncMode	    (UV32*)(MPEG4BASE + (0x0198<<2))
	#define P_MSCnt	                (UV32*)(MPEG4BASE + (0x0199<<2))
	#define P_MSPlus_ctrl	        (UV32*)(MPEG4BASE + (0x019a<<2))
	#define P_VOPTimeIncRes_low	    (UV32*)(MPEG4BASE + (0x01a0<<2))
	#define P_VOPTimeIncRes_high	(UV32*)(MPEG4BASE + (0x01a1<<2))
	#define P_VOPTimeInc_low	    (UV32*)(MPEG4BASE + (0x01a2<<2))
	#define P_VOPTimeInc_high	    (UV32*)(MPEG4BASE + (0x01a3<<2))
	#define P_VOPTimeIncLen	        (UV32*)(MPEG4BASE + (0x01a4<<2))
	#define P_React_low	            (UV32*)(MPEG4BASE + (0x01a6<<2))
	#define P_React_high	        (UV32*)(MPEG4BASE + (0x01a7<<2))
	#define P_D0_Iframe_low	        (UV32*)(MPEG4BASE + (0x01a8<<2))
	#define P_D0_Iframe_high	    (UV32*)(MPEG4BASE + (0x01a9<<2))
	#define P_PreIframeMBByte_low	(UV32*)(MPEG4BASE + (0x01aa<<2))
	#define P_PreIframeMBByte_high	(UV32*)(MPEG4BASE + (0x01ab<<2))
	#define P_PrePframeMBByte_low	(UV32*)(MPEG4BASE + (0x01ac<<2))
	#define P_PrePframeMBByte_high	(UV32*)(MPEG4BASE + (0x01ad<<2))
	#define P_QscaleUpperB	        (UV32*)(MPEG4BASE + (0x01ae<<2))
	#define P_QscaleLowerB	        (UV32*)(MPEG4BASE + (0x01af<<2))
	#define P_D0_Pframe_low	        (UV32*)(MPEG4BASE + (0x01b0<<2))
	#define P_D0_Pframe_high	    (UV32*)(MPEG4BASE + (0x01b1<<2))
	#define P_VLCSize_low	        (UV32*)(MPEG4BASE + (0x01b2<<2))
	#define P_VLCSize_mid	        (UV32*)(MPEG4BASE + (0x01b3<<2))
	#define P_VLCSize_high	        (UV32*)(MPEG4BASE + (0x01b4<<2))
	#define P_Qsum_low	            (UV32*)(MPEG4BASE + (0x01b5<<2))
	#define P_Qsum_high	            (UV32*)(MPEG4BASE + (0x01b6<<2))
	#define P_SRAM_CS_N	            (UV32*)(MPEG4BASE + (0x01be<<2))
	#define P_auto_rst_dec	        (UV32*)(MPEG4BASE + (0x01bf<<2))
	#define P_SRAM_test_ctrl	    (UV32*)(MPEG4BASE + (0x01e0<<2))
	#define P_Tselect	            (UV32*)(MPEG4BASE + (0x01e1<<2))
	#define P_Bist_ctrl_jpeg	    (UV32*)(MPEG4BASE + (0x01e2<<2))
	#define P_jpegBistFail	        (UV32*)(MPEG4BASE + (0x01e3<<2))
	#define P_Blockend	            (UV32*)(MPEG4BASE + (0x01e4<<2))
	#define P_DeHuffmanen	        (UV32*)(MPEG4BASE + (0x01e6<<2))
	#define P_DeHuffmanrdy	        (UV32*)(MPEG4BASE + (0x01e7<<2))
	#define P_Vlddata_low	        (UV32*)(MPEG4BASE + (0x01e8<<2))
	#define P_Vlddata_high	        (UV32*)(MPEG4BASE + (0x01e9<<2))
	#define P_VideoRstMode	        (UV32*)(MPEG4BASE + (0x01ea<<2))
	#define P_nacten	            (UV32*)(MPEG4BASE + (0x01eb<<2))
	#define P_Imcucnt_low	        (UV32*)(MPEG4BASE + (0x01ec<<2))
	#define P_Imcucnt_high	        (UV32*)(MPEG4BASE + (0x01ed<<2))
	#define P_Pmcucnt_low	        (UV32*)(MPEG4BASE + (0x01ee<<2))
	#define P_Pmcucnt_high	        (UV32*)(MPEG4BASE + (0x01ef<<2))
	#define P_Skipmcucnt_low        (UV32*)(MPEG4BASE + (0x01f0<<2))
	#define P_Skipmcucnt_high       (UV32*)(MPEG4BASE + (0x01f1<<2))
	#define P_H263_ctrl	            (UV32*)(MPEG4BASE + (0x01f2<<2))
	#define P_setting_reg01f3       (UV32*)(MPEG4BASE + (0x01f3<<2))
	#define P_HmvSum_low	        (UV32*)(MPEG4BASE + (0x01f4<<2))
	#define P_HmvSum_high	        (UV32*)(MPEG4BASE + (0x01f5<<2))
	#define P_VmvSum_low	        (UV32*)(MPEG4BASE + (0x01f6<<2))
	#define P_VmvSum_high	        (UV32*)(MPEG4BASE + (0x01f7<<2))
	#define P_TSram_ctrl	        (UV32*)(MPEG4BASE + (0x01f8<<2))
	#define P_setting_reg01f9       (UV32*)(MPEG4BASE + (0x01f9<<2))
	#define P_setting_reg01fa       (UV32*)(MPEG4BASE + (0x01fa<<2))
	#define P_ROIMBXOffsetLSB       (UV32*)(MPEG4BASE + (0x01fb<<2))
	#define P_ROIMBXDestLSB	        (UV32*)(MPEG4BASE + (0x01fc<<2))
	#define P_ROIMBYOffsetLSB       (UV32*)(MPEG4BASE + (0x01fd<<2))
	#define P_ROIMBYDestLSB	        (UV32*)(MPEG4BASE + (0x01fe<<2))
	#define P_ROIMBMSB	            (UV32*)(MPEG4BASE + (0x01ff<<2))
	// reg0200 ~ reg023f for HuffmanTable
	#define P_HuffmanTable_str	    (UV32*)(MPEG4BASE + (0x0200<<2))
	#define P_HuffmanTable_end	    (UV32*)(MPEG4BASE + (0x023f<<2))
	// reg0200 ~ reg023f for HuffmanTable
	//////////////////////////////////////////////////////////////////////////////
	#define P_HUFF_YDCW_REG	    	(UV32*)(MPEG4BASE + (0x0200<<2))
	#define P_HUFF_YDCS_REG	    	(UV32*)(MPEG4BASE + (0x0218<<2))
	#define P_HUFF_YDCV_REG	    	(UV32*)(MPEG4BASE + (0x0220<<2))
	
	#define P_HUFF_CDCW_REG	    	(UV32*)(MPEG4BASE + (0x0230<<2))
	#define P_HUFF_CDCS_REG	    	(UV32*)(MPEG4BASE + (0x0248<<2))
	#define P_HUFF_CDCV_REG	    	(UV32*)(MPEG4BASE + (0x0250<<2))
	
	#define P_HUFF_YACW_REG	    	(UV32*)(MPEG4BASE + (0x0260<<2))
	#define P_HUFF_YACS_REG	    	(UV32*)(MPEG4BASE + (0x0278<<2))
	
	#define P_HUFF_CACW_REG	    	(UV32*)(MPEG4BASE + (0x0290<<2))
	#define P_HUFF_CACS_REG	    	(UV32*)(MPEG4BASE + (0x02a8<<2))

/**
 * MIU2: 0x0823_0000 ~ 0x0823_FFFF
 */
#define MIU2BASE				0x88230000
	#define P_MIU2_SDRAM_SETTING    (UV32*)(MIU2BASE + 0x00000060)
	#define P_MIU2_TV_START_ADR1    (UV32*)(MIU2BASE + 0x00000044)
	#define P_MIU2_TV_START_ADR2    (UV32*)(MIU2BASE + 0x00000048)
	#define P_MIU2_TV_START_ADR3    (UV32*)(MIU2BASE + 0x00000064)
	
/**
 * ECC: 0x0824_0000 ~ 0x0824_FFFF
 */
#define ECCBASE					0x88240000

#endif  //_SCORE7_REGISTERS_H
