#include "GPIO_NOKIA5110.h"
#include "HW_gpio.h"
#include "SysCtrl.h"

/* ************************************************************************ */
void NOKIA_GPIOF_Setup(void){//! start function.
	//enable clock for PORTF
	clock_Enable_PORT(Clock_PortF);
	//Select alternating Function for GPIO.
	GPIO_PORTF_AFSEL=0x00;
	//Enable digital function for PORTF pins
	GPIO_PORTF_DEN|=(1<<0)|(1<<4);
	//Turn off Analog function
  GPIO_PORTF_AMSEL=0x00;
	//set PF2/PF3 AS OUTPUT
	GPIO_PORTF_DIR|=(1<<0)|(1<<4);
}//! end of GPIO function.

/* *********************************************************************** */
void NOKIA_REST(Const_m value){//!start reset function.
	
	switch(value){//start switch cases.
		case HIGH:
			GPIO_PORTF_DATA|=(1<<0);break;
		case LOW:
			GPIO_PORTF_DATA&=~(1<<0);break;
	}//end of switch
	
	
}//! end of reset function.

/* *********************************************************************** */

void NOKIA_DC(Const_m data_CMD){//1 start DC function.
	
	switch(data_CMD){//start switch cases.
		case DATA:
			GPIO_PORTF_DATA|=(1<<4);break;
		case COMMAND:
			GPIO_PORTF_DATA&=~(1<<4);break;
	}//end of switch


}//! end of DC function.




