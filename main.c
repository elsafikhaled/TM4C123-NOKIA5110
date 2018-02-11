#include "data_types.h"
#include "NOKIA5110.h"
#include "SPI.h"
#include "SysTickDelay.h"




int main(void){
	//strings methods.
	 U8_t * str =(U8_t*)"ALLAH";
	 U8_t * strArr[5]={(U8_t*)"ELSAFI",(U8_t*)"KHALED",(U8_t*)"23",(U8_t*)"SOFTWARE",(U8_t*)"ENGINEER"};
	 U8_t arrayStr[10]={"hello"};
	 U8_t arrOfstr[2][8]={{"ALLAH"},{"MERCY"}};
	 //array of pointers to just chars.
	 U8_t x=0,y=2;
  U8_t z[2]={0,1};
	 U8_t * arr_ptrs[2]={&x,&y};
	   *arr_ptrs[0]=3;
	   strArr[2]=(U8_t*)"AHMED";
	 //pointer to array one dimension.
		U8_t (*ptrToarr)[2]=&z;
	  U8_t *ptr=z;
	 //system initialization.
	 NOKIA5110_Setup(NORMAL);
	 Nokia5110_Cursor(0,0);
	 Nokia5110_OutString((U8_t*)"************");
	while(1){
		for(char i=1;i<3;i++){
	  	 Nokia5110_Cursor(i,5);
		   Nokia5110_OutString(arrOfstr[i-1]);
		}
	}
}

