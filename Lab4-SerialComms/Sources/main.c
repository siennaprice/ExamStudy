/* ###################################################################
**     Filename    : main.c
**     Project     : Lab4-SerialComms
**     Processor   : MK20DX128VLH5
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-11-12, 04:15, # CodeGen: 0
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
#include "AS1.h"
#include "ASerialLdd1.h"
#include "redLED.h"
#include "BitIoLdd1.h"
#include "greenLED.h"
#include "BitIoLdd2.h"
#include "blueLED.h"
#include "BitIoLdd3.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* USER INCLUDES */
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

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  for (;;) {

	  send_string("Type r, g or b \r\n");
	  do {
		  err = AS1_RecvChar(&c);
	  } while (err != ERR_OK);

	  if (c == 'r') {
		  redLED_NegVal();
		  err = AS1_SendChar(c);
		  err = AS1_SendChar('\n');
	  }
	  else if (c == 'g') {
		  greenLED_NegVal();
		  err = AS1_SendChar(c);
		  err = AS1_SendChar('\n');
	  }
	  else if (c == 'b') {
		  blueLED_NegVal();
		  err = AS1_SendChar(c);
		  err = AS1_SendChar('\n');
	  }
	  else {
		  send_string("Invalid Input \r\n");
	  }
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
