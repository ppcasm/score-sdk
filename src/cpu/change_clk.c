#include "cpu/discpu_func.h"
#include "score7_registers.h"

void change_clk(int type, int close_PLLA, int close_PLLV){
    volatile unsigned int* p;
    unsigned int delay_time;

    delay_time=0xffff;
	
    unsigned int CPU_FREQUENCY,MIU_FREQUENCY;
	
	
    int old_PLLV_frequency;//0~15	
    int PLLV_frequency;//0~15
	
    unsigned int CPU_CLK_Select;//0~11
    unsigned int MIU_CLK_Select;//0~3	
    unsigned int MIU_SDRAM_setting;
    unsigned int MIU_run108_sel;
    unsigned int PLLV_freq_chg;
    unsigned int PLLA_enable;
    unsigned int PLLA_toPLLV_sel;
    unsigned int PLLV_enable;
	

    switch(type)
    {
    case(CPU54_SDRAM54):    
        PLLV_frequency=7;
        CPU_CLK_Select=1;//0~11
        MIU_CLK_Select=0;
        break;    
    case(CPU162_SDRAM81):
        PLLV_frequency=15;
        CPU_CLK_Select=0;//0~11
        MIU_CLK_Select=1;
        break;    
    case(CPU81_SDRAM81):
        PLLV_frequency=3;
        CPU_CLK_Select=0;//0~11
        MIU_CLK_Select=0;
        break;
    case(CPU108_SDRAM108):
        PLLV_frequency=7;
        CPU_CLK_Select=0;//0~11
        MIU_CLK_Select=0;
        break;
    case(CPU67_SDRAM67):
        PLLV_frequency=0;
        CPU_CLK_Select=6;//0~11
        MIU_CLK_Select=0;
        break;
    default:
        PLLV_frequency=3;
        CPU_CLK_Select=0;//0~11
        MIU_CLK_Select=0;
        break;
    }

    old_PLLV_frequency=*P_CLK_PLLV_SEL;

    if(old_PLLV_frequency!=PLLV_frequency)
    {
        PLLV_freq_chg=1;
    }
    else
    {
        PLLV_freq_chg=0;
    }

    PLLA_enable=*P_CLK_PLLAU_CONF;
    PLLA_enable=PLLA_enable&1;
    if(PLLA_enable)
    {
        PLLA_enable=0;
    }
    else
    {
        PLLA_enable=1;
    }

    PLLA_toPLLV_sel=*P_CLK_CPU_SEL;
    if((PLLA_toPLLV_sel>5)&&(CPU_CLK_Select<6))
    {
        PLLA_toPLLV_sel=1;
    }
    else
    {
        PLLA_toPLLV_sel=0;
    }

    PLLV_enable=*P_I2S_CLK_CONF;    
    if(PLLV_enable)
    {
        PLLV_enable=0;
    }
    else
    {
        PLLV_enable=1;
    }

    if(CPU_CLK_Select<6)
    {
        switch(PLLV_frequency)
        {
        case 3:
            CPU_FREQUENCY=81;
            break;
        case 4:
            CPU_FREQUENCY=87.7;
            break;
        case 5:
            CPU_FREQUENCY=97.5;
            break;
        case 6:
            CPU_FREQUENCY=101.25;
            break;
        case 7:
            CPU_FREQUENCY=108;
            break;
        case 8:
            CPU_FREQUENCY=114.75;
            break;
        case 9:
            CPU_FREQUENCY=121.5;
            break;
        case 10:
            CPU_FREQUENCY=128.25;
            break;
        case 11:
            CPU_FREQUENCY=135;
            break;
        case 12:
            CPU_FREQUENCY=141.75;
            break;
        case 13:
            CPU_FREQUENCY=148.5;
            break;
        case 14:
            CPU_FREQUENCY=155.25;
            break;
        case 15:
            CPU_FREQUENCY=162;
            break;
        }
        
        switch(CPU_CLK_Select)
        {
        case 1:
            CPU_FREQUENCY = CPU_FREQUENCY/2;
            break;
        case 2:
            CPU_FREQUENCY = CPU_FREQUENCY/3;
            break;
        case 3:
            CPU_FREQUENCY = CPU_FREQUENCY/4;
            break;
        case 4:
            CPU_FREQUENCY = CPU_FREQUENCY/6;
            break;
        case 5:
            CPU_FREQUENCY = CPU_FREQUENCY/8;
            break;
        }
    }
    else
    {
        CPU_FREQUENCY=67.5;
        switch(CPU_CLK_Select)
        {
        case 7:
            CPU_FREQUENCY = CPU_FREQUENCY/2;
            break;
        case 8:
            CPU_FREQUENCY = CPU_FREQUENCY/3;
            break;
        case 9:
            CPU_FREQUENCY = CPU_FREQUENCY/4;
            break;
        case 10:
            CPU_FREQUENCY = CPU_FREQUENCY/6;
            break;
        case 11:
            CPU_FREQUENCY = CPU_FREQUENCY/8;
            break;
        }
    }

    MIU_FREQUENCY=MIU_CLK_Select+1;
    MIU_FREQUENCY=CPU_FREQUENCY/MIU_FREQUENCY;

    switch(MIU_FREQUENCY)
    {
    case 108:
        MIU_run108_sel=1;
	    MIU_SDRAM_setting=0x4B04;
	    break;
    case 81:
        MIU_run108_sel=0;
	    MIU_SDRAM_setting=0x4A03;
	    break;
    case 67:
        MIU_run108_sel=0;
	    MIU_SDRAM_setting=0x4A03;
	    break;
    case 54:
        MIU_run108_sel=0;
	    MIU_SDRAM_setting=0x4983;
	    break;
    default:
        break;
    }

    PLL_change_func(
        PLLV_frequency,     //PLLV_freq_setting,
        CPU_CLK_Select,     //PLL_DIV_setting,
        MIU_CLK_Select,     //AHBSLV_SEL,
        PLLV_freq_chg,      //PLLV_freq_chg,
        PLLA_enable,        //PLLA_enable,
        PLLA_toPLLV_sel,    //PLLA_toPLLV_sel,
        PLLV_enable,        //PLLV_enable,
        MIU_SDRAM_setting,  //MIU_timing_setting,
        MIU_run108_sel,     //MIU_run108_sel,
        delay_time,         //PLLEN_delay_c,
        delay_time);        //PLLCHG_delay_c

    if(close_PLLA&&(type!=3))
    {
        p=(unsigned int *)0x882100BC;
        *p=0;
    }
    
    if(close_PLLV&&(type==3))
    {
        //close pllv
        p=(unsigned int *)0x882100B4;
        *p=0;
    }
}

void	PLL_change_func(
int PLLV_freq_setting,
//3			81	MHz
//7			108	MHz
//11			135	MHz
//15			162	MHz
int PLL_DIV_setting,
//PLL_DIV_setting	CPU clock in	
//0			from PLLV	div 1
//1			from PLLV	div 2
//2			from PLLV	div 3
//3			from PLLV	div 4
//4			from PLLV	div 6
//5			from PLLV	div 8
//6			from PLLA	div 1
//7			from PLLA	div 2
//8			from PLLA	div 3
//9			from PLLA	div 4
//10			from PLLA	div 6
//11			from PLLA	div 8
int AHBSLV_SEL,
//AHBSLV_SEL		SYSTEM_BUS clock (MIU clock)  (It's not CPU clock)
//00			CPU : MIU = 1 : 1
//01			CPU : MIU = 2 : 1
//10			CPU : MIU = 3 : 1	(In general, it's reserved!!!!!)
//11			CPU : MIU = 3 : 1	(In general, it's reserved!!!!!)
int PLLV_freq_chg,	//If it is 1, it means needing change PLLV frequency 
//the PLLV frequency is PLLV_freq_setting (see the first parameter)
int PLLA_enable,	//In general, when the changing flow is from PLLV to PLLA
//This parameter may be useful
int PLLA_toPLLV_sel,	//The changing flow is from PLLA to PLLV
int PLLV_enable,	//It is useful only if PLLA_toPLLV_sel is 1	
int MIU_timing_setting,	//when changing CPU clock or MIU clock, 
//the timing_setting is necessary
int MIU_run108_sel,	//if the final (changed) MIU clock is 108, this parameter must be 1
int PLLEN_delay_c,	//if PLLV or PLLA is enable, the delay time is necessary
//the real delay time = PLLEN_delay_c * 3 !!!!!!!!!
int PLLCHG_delay_c	//if PLLVs' freq is changed, the delay time is necessary
//the real delay time = PLLCHG_delay_c * 3 !!!!!!!!!
)
{
    //pll_type(r4):
    //		r4[3:0]		PLLV frequency setting
    //		r4[7:4]		PLLV DIV setting (cpu clock is pllv /2 /3 /4 ...etc)
    //				if r4 >= 6, it means system clock will be assigned 
    //				to PLLA (force to 67MHz) (the original PLL source is from PLLV)
    //		r4[9:8]		AHBSLV (MIU) clock sel (1:1 or 2:1 or 3:1 or 4:1)
    //		r4[10]		1 means need change PLLV frequency setting (r4[3:0])
    //		r4[11]		enable PLLA
    //		r4[12]		from PLLA to PLLV
    //		r4[13]		enable PLLV (only useful if r4[12] is 1)

    //miu_type(r5):	
    //		r5[15:0]	timing_setting
    //		r5[16]		1 (run 108MHz), 0 (run <108MHz)

    //	pllen_delay_c(r6)		
    //pllchg_delay_c(r7)

    unsigned int r4,r5,r6,r7;
	
    r4=	PLLV_freq_setting + (PLL_DIV_setting<<4) + (AHBSLV_SEL<<8) + 
    (PLLV_freq_chg<<10) + (PLLA_enable<<11) + (PLLA_toPLLV_sel<<12) + (PLLV_enable<<13);
    r5=	(MIU_run108_sel<<16) + MIU_timing_setting;

    r6=	PLLEN_delay_c;
    r7=	PLLCHG_delay_c;
    
    jumpto_extrom_change_cpuclk(r4,r5,r6,r7);
    //*(volatile unsigned int *)0x88210000 = 0;
}

