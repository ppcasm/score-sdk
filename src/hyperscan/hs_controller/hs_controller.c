#ifdef hyperscan

#include "score7_registers.h"
#include "score7_constants.h"
#include "i2c/i2c.h"
#include "hyperscan/hs_controller/hs_controller.h"

controllerunion controller[1];

//=============================================================
// void hs_controller_init(void);
//
// This initializes the Mattel HyperScan controller interface
//
// void return
//=============================================================
void hs_controller_init(void)
{
	i2c_init();
	
	*P_TFT_GPIO_OUTPUTEN = 0x000FFFFF;
	*P_TFT_GPIO_PULLUP = 0x000FFFFF;
	*P_TFT_GPIO_PULLDOWN = 0x00000000;
	
	//	Flush initial controller inputs
	hs_controller_read();
}

//=============================================================
// void hs_controller_read(unsigned int controller_port);
//
// This reads the data from controller (controller_port) and returns
// the value
//
// void return, the controller data gets stored in the controller union/struct
// for the specific controller (hs_controller_1, or hs_controller_2)
//=============================================================
void hs_controller_read(void){
	/*
		The Mattel HyperScan controllers are selected by the
		TFT_GPIO port
	*/
	
	unsigned int read_count = 0;
	unsigned int controller_count = 0;
	
	//	HyperScan controller I2C device address
	*P_I2C_SLAVE_ADDR = 0x54;
	
	for(controller_count=0;controller_count<=1;controller_count++){
		//	Make controller active
		*P_TFT_GPIO_DATA |= (1 << controller_count);

		for(read_count=0;read_count<=4;read_count++){
			controller[controller_count].bytes[read_count] = i2c_read8(read_count);
		}
		
		//	Disable controller
		*P_TFT_GPIO_DATA &= ~(1 << controller_count);
	}
	
	return;
}

#endif

