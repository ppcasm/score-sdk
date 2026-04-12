#ifndef __INTERRUPTS_H__
#define __INTERRUPTS_H__

#include "score7_registers.h"
#include "score7_constants.h"

//===================================================
// Prototypes
//===================================================

void attach_isr(unsigned int irq, void (*handler)(void));
void disable_isr(unsigned int vector);
void enable_isr(unsigned int vector);

//===================================================
// S+Core Interrupt Sources
//===================================================
#define INT_SPU_FIQ           63      // VecSrc = 0
#define INT_SPU_BEATIRQ       62      // VecSrc = 1
#define INT_SPU ENVELOPEIRQ   61      // VecSrc = 2
#define INT_CD_SERVO          60      // VecSrc = 3
#define INT_ADC_OVFLW         59      // VecSrc = 4
#define INT_ADC               58      // VecSrc = 5
#define INT_TIMER_BASE        57      // VecSrc = 6
#define INT_TIMER             56      // VecSrc = 7
#define INT_TV_VBLANK_START   55      // VecSrc = 8
#define INT_LCD_VBLANK_START  54      // VecSrc = 9
#define INT_PPU_VBLANK_START  53      // VecSrc = 10
#define INT_LIGHT_GUN         52      // VecSrc = 11
#define INT_SENSOR_FRAME_END  51      // VecSrc = 12
#define INT_SENSOR_COORD_HIT  50      // VecSrc = 13
#define INT_SENSOR_MOTION_END 49      // VecSrc = 14
#define INT_SENSOR_CAP_DONE   48      // VecSrc = 15
#define INT_TV_COORD_HIT      47      // VecSrc = 16
#define INT_PPU_COORD_HIT     46      // VecSrc = 17
#define INT_USB_HDEV          45      // VecSrc = 18
#define INT_SIO               44      // VecSrc = 19
#define INT_SPI               43      // VecSrc = 20
#define INT_UART              42      // VecSrc = 21
#define INT_NAND              41      // VecSrc = 22
#define INT_SD                40      // VecSrc = 23
#define INT_I2C_MASTER        39      // VecSrc = 24
#define INT_I2C_SLAVE         38      // VecSrc = 25
#define INT_APBDMA_CH1        37      // VecSrc = 26
#define INT_APBDMA_CH2        36      // VecSrc = 27
#define INT_LDM_DMA           35      // VecSrc = 28
#define INT_BLN_DMA           34      // VecSrc = 29
#define INT_APBDMA_CH3        33      // VecSrc = 30
#define INT_APBDMA_CH4        32      // VecSrc = 31
#define INT_ALARM             31      // VecSrc = 32
#define INT_MP4               30      // VecSrc = 33
#define INT_C3_ECC            29      // VecSrc = 34
#define INT_GPIO              28      // VecSrc = 35
#define INT_TV_VBLANK_END     27      // VecSrc = 36
#define INT_RESERVED1         26      // VecSrc = 37
#define INT_RESERVED2         25      // VecSrc = 38
#define INT_RESERVED3         24      // VecSrc = 39

//===================================================
// Unmask Ints
//===================================================
#define DAC_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_DAC_DIS)
#define MIC_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_MIC_DIS)
#define ADC_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_ADC_DIS)
#define TMB_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_TMB_DIS)
#define TIMER_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_TIMER_DIS)
#define LCDVS_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_LCDVS_DIS)
#define FRAME_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_FRAME_DIS)
#define USB_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_USB_DIS)
#define SIO_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_SIO_DIS)
#define SPI_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_SPI_DIS)
#define UART_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_UART_DIS)
#define NAND_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_NAND_DIS)
#define SD_INT_UNMASK()				(*P_INT_MASK_CTRL1 &= ~C_INT_SD_DIS)
#define I2C_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_I2C_DIS)
#define I2S_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_I2S_DIS)
#define APBCH0_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_APBCH0_DIS)
#define APBCH1_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_APBCH1_DIS)
#define LDM_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_LDM_DIS)
#define BLN_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_BLN_DIS)
#define APBCH2_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_APBCH2_DIS)
#define APBCH3_INT_UNMASK()			(*P_INT_MASK_CTRL1 &= ~C_INT_APBCH3_DIS)
// Test
#define FRAME_END_INT_UNMASK()      (*P_INT_MASK_CTRL1 &= ~C_INT_FRAME_END) 

#define RTC_INT_UNMASK()			(*P_INT_MASK_CTRL2 &= ~C_INT_RTC_DIS)
#define MP4_INT_UNMASK()			(*P_INT_MASK_CTRL2 &= ~C_INT_MP4_DIS)
#define ECC_INT_UNMASK()			(*P_INT_MASK_CTRL2 &= ~C_INT_ECC_DIS)
#define EXT_INT_UNMASK()			(*P_INT_MASK_CTRL2 &= ~C_INT_GPIO_DIS)

#define INT_UNMASK_SETUP1(INT_DIS)	(*P_INT_MASK_CTRL1 &= ~INT_DIS)		
#define INT_UNMASK_SETUP2(INT_DIS)	(*P_INT_MASK_CTRL2 &= ~INT_DIS)

#endif
