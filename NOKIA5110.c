#include "NOKIA5110.h"
#include "SPI.h"
#include "GPIO_NOKIA5110.h"
#include "GPIO_SPI.h"
#include "SysTickDelay.h"

void NOKIA5110_Setup(MODE display){//! Start Configuration LCD.
	
//setup SPI master mode.
	  SPI_Master_init();
	
//start initializing nokia lcd registers.
	 // setup GPIO for reset/DC pins
	    NOKIA_GPIOF_Setup();
//RESET processor to clear all RAM registers 100nsec minimum.
	    NOKIA_REST(LOW);
	    SysTick_DelayNS();
	    NOKIA_REST(HIGH);
//Access register values from datasheet example.
	  //Active chip-horizental addressing-use extended instruction set.
	    NOKIA5110_CMD(0x21);
	  //set constract for  light.
	    NOKIA5110_CMD(0xb8);
	  //set temp coefficient
	    NOKIA5110_CMD(0x04);
	  // LCD bias mode 1:48
	    NOKIA5110_CMD(0x14);
	  //normal basic instruction set.
	    NOKIA5110_CMD(0x20);
	  //display configuration.
	    NOKIA5110_CMD(display);
	
}//! End of LCD setup function.


void NOKIA5110_CMD(U8_t CMD){//! start of command function.
//Active command mode.
     NOKIA_DC(COMMAND);
//send SPI byte= instruction for processor. 
	   SPI_SendData(CMD);
	
}//! End of command setup function.



void NOKIA5110_DATA(U8_t data){//! start of DATA function.
//Active DATA mode.
     NOKIA_DC(DATA);
//send SPI byte= instruction for processor. 
	   SPI_SendData(data);
		
}//! End of DATA setup function.

void Nokia5110_OutChar(U8_t data){//!start send char function.
	U8_t i;
  NOKIA5110_DATA(0x00);        // blank vertical line padding
  for(i=0; i<6; i=i+1){
    NOKIA5110_DATA(font6_8[data - 0x20][i]);
  }
  NOKIA5110_DATA(0x00);        // blank vertical line padding
}//! End send char function.

void Nokia5110_OutString(U8_t *ptr){//! send string
  while(*ptr){
    Nokia5110_OutChar((U8_t)*ptr);
    ptr++;
  }
}//!End of send string function.



void Nokia5110_Cursor(U8_t y,U8_t x){//! start cursor function.
	//set ROW number 0--->5
	NOKIA5110_CMD(0x40|y);
	//set Column number 0-->83
	NOKIA5110_CMD(0x80|x);
}//! End of cursor function.


