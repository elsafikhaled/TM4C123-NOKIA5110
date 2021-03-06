#ifndef __SYSCTRL_H__
#define __SYSCTRL_H__
#include "data_types.h"


//! coprocessor access control register 
#define SCB_CPAC (*((volatile unsigned int*)0xE000ED88))
	

//!This function is called by the startup assembly code to perform system specific
//!initialization tasks.

void SystemInit(void);

//!---------------------------------------------------------------------------------.


// BASE FOR RUN MODE CLOCK GAtING CONTROL

#define RCGC_BASE 0x400FE000

// RCGC register with offset  0x608 at PORTA
#define GPIO_RCGC_PORT  *((volatile U32_t *)0X400FE608)

//uart clock.
#define UART_RCGC       *((volatile U32_t *)0x400FE618)

//Timer clock.
#define Timer_clock     *((volatile U32_t *)0x400FE604)

//ADC clock
#define ADC_clock       *((volatile U32_t *)0x400FE638)

//SPI clock
#define SPI_clock       *((volatile U32_t *)0x400FE61c)

//!------------------------------------------------------------------------------------

// function: Enable clock for PORT is a must   
void clock_Enable_PORT(U8_t port);
/* ---------------------------------------------/
- Input: unsigned char 1 byte
-
- Description: Access clock. 
- 
- return : void.
* ---------------------------------------------*/ 
// port:: RCGC register PINS offset
#define Clock_PortA  0x01
#define Clock_PortB  0x02
#define Clock_PortC  0x04
#define Clock_PortD  0x08
#define Clock_PortE  0x10
#define Clock_PortF  0x20

/*---------------------------------------------- UART ENABLE OFFSET -----------------------------------------------------------*/
void Clock_Enable_UART(U8_t uart_n);
//UART Number ::as shown down  
/* ---------------------------------------------/
- Input: unsigned char 1 byte
-
- Description: Access clock. 
- 
- return : void.
* ---------------------------------------------*/ 
#define UART0  0X01
#define UART1  0X02
#define UART2  0X04
#define UART3  0X08
#define UART4  0X10
#define UART5  0X20
#define UART6  0X40
#define UART7  0X80



/*---------------------------------------------- Timer ENABLE OFFSET -----------------------------------------------------------*/
void Clock_Enable_Timer(U8_t timer_n);
//Timer Number ::as shown down  
/* ---------------------------------------------/
- Input: unsigned char 1 byte
-
- Description: Access clock. 
- 
- return : void.
* ---------------------------------------------*/ 
#define Timer0  0X01
#define Timer1  0X02
#define Timer2  0X04
#define Timer3  0X08
#define Timer4  0X10
#define Timer5  0X20



/*---------------------------------------------- ADC ENABLE OFFSET -----------------------------------------------------------*/
void Clock_Enable_ADC(U8_t ADC_n);
//ADC Number ::as shown down  
/* ---------------------------------------------/
- Input: unsigned char 1 byte
-
- Description: Access clock. 
- 
- return : void.
* ---------------------------------------------*/ 
#define ADC0  0X01
#define ADC1  0X02
#define ADC2  0X04
#define ADC3  0X08



/*---------------------------------------------- SPI ENABLE OFFSET -----------------------------------------------------------*/
void Clock_Enable_SPI(U8_t SPI_n);
//SPI Number ::as shown down  
/* ---------------------------------------------/
- Input: unsigned char 1 byte
-
- Description: Access clock. 
- 
- return : void.
* ---------------------------------------------*/ 
#define SPI0  0X01
#define SPI1  0X02


#endif //__SYSCTRL_H__


