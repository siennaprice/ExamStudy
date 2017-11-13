/* ###################################################################
**     Filename    : main.c
**     Project     : Lab7-UIwithPWM
**     Processor   : MK20DX128VLH5
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-11-13, 22:25, # CodeGen: 0
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
#include "Term1.h"
#include "Inhr1.h"
#include "ASerialLdd1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char buffer [100];
extern unsigned int index;

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
	int redBright;
	int greenBright;
	int blueBright;


  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  //The Terminal
  Term1_SetColor(clWhite,clBlack);
  Term1_Cls();
  Term1_MoveTo(1,1);

  Term1_SendStr("CC2511 Lab 7 - Sienna-Rose Price - 12709574"); // Heading
  Term1_MoveTo(1,3);
  Term1_SetColor(clBlack,clCyan);
  Term1_SendStr("+---[ PWM STATUS ]---+ +---------[ How to Use ]--------+"); //Table Headings
  int divPos[] = {1,23,56}; //positions of table divider columns
  for(int j=0; j<3; j++){
  	for(int i = 4; i < 10; i++){
  		Term1_MoveTo(divPos[j], i);
  		Term1_SendStr(" ");
  	}
  }
  Term1_MoveTo(1,10);
  Term1_SendStr("                                                        ");

  Term1_SetColor(clWhite,clBlack);

  Term1_MoveTo(3,5);
  Term1_SendStr("Red: ");
  Term1_MoveTo(3,6);
  Term1_SendStr("Green: ");
  Term1_MoveTo(3,7);
  Term1_SendStr("Blue: ");

  Term1_MoveTo(1,11);
  Term1_SendStr("Command Prompt \n\r");
  Term1_MoveTo(1,12);





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
