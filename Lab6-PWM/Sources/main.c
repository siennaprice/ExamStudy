/* ###################################################################
**     Filename    : main.c
**     Project     : Lab6-PWM
**     Processor   : MK20DX128VLH5
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-11-13, 04:19, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Blue.h"
#include "PwmLdd1.h"
#include "Red.h"
#include "PwmLdd2.h"
#include "TU1.h"
#include "Green.h"
#include "PwmLdd3.h"
#include "AS1.h"
#include "ASerialLdd1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//Variable Declaration
static byte err;
char *str;

//FUNCTION TO SEND STRINGS
void send_string(char *str)
{
	int len; //size of the string
	len = strlen(str);
	for (int i = 0; i < len; i++) {
		//Send the character
		do {
			err = AS1_SendChar(str[i]);
		} while (err != ERR_OK);
	}
}


/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
	static byte c, err;
	int rBright = 0;
	int gBright = 0;
	int bBright = 0;

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  for (;;){
	  send_string("Controls: \n\r r - Lower Red Bright \n\r R - Higher Red Bright \n\r "
			  "g,G,b,B, for green and blue \n\r");
		do {
			err = AS1_RecvChar(&c);
		} while (err != ERR_OK);

	  if (c == 'r') {
		  rBright -= 10;
	  }
	  else if (c == 'R') {
		  rBright += 10;
	  }
	  else if (c == 'g') {
		  gBright -= 10;
	  }
	  else if (c == 'G') {
		  gBright += 10;
	  }
	  else if (c == 'b') {
		  bBright -= 10;
	  }
	  else if (c == 'B') {
		  bBright += 10;
	  }
	  else {
		  send_string("Invalid Input");
	  }

	  Blue_SetRatio8(bBright);
	  Red_SetRatio8(rBright);
	  Green_SetRatio8(gBright);

  }

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
