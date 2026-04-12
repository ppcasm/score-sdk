#ifndef __DISCPU_FUNC_H__
#define __DISCPU_FUNC_H__

extern void jumpto_extrom_discpu_clk();
extern void jumpto_extrom_discpu_miu_clk();
extern void jumpto_extrom_discpu_miu_clk_pll();
extern void jumpto_extrom_cpu_poweronn();
extern void jumpto_extrom_cpu_warmrstn();
extern void jumpto_extrom_change_cpuclk();

void change_clk(int type,int close_PLLA, int close_PLLV);
void PLL_change_func(
int,
int,
int,
int,
int,
int,
int,
int,
int,
int,
int
);

#define	CPU54_SDRAM54 		0
#define	CPU162_SDRAM81 		1
#define	CPU81_SDRAM81 		2
#define	CPU108_SDRAM108 	3
#define	CPU67_SDRAM67 		4

#endif  //_DISCPU_FUNC_H

