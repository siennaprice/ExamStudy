/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * LAB-Week3
 * Cycling through mix of colours available on LED
 */

#include "MK20D5.h"
#include "MK20D5_simple.h"

//INCLUDES
#include <stdio.h>
#include <stdbool.h>

//VARIABLE DECLARATION
static int i;
static int j;
static int k;

//USER DEFINED FUNCTION
void setLED(int i,int j,int k){
	if (i == 1){
		GPIOC_PDOR = 0;
	}
	else {
		GPIOC_PDOR = (1 << 3);
	}
	if (j == 1){
		GPIOD_PDOR = 0;
	}
	else {
		GPIOD_PDOR = (1 << 4);
	}
	if (k ==1){
		GPIOA_PDOR = 0;
	}
	else {
		GPIOA_PDOR = (1 << 2);
	}
}




int main(void)
{
	//CLOCKING PORT CONTROL MODULE
	SIM_SCGC5 |= 0x3e00;

//CODE TO BE EXECUTED

	//Initialise LED's
	PORTC_PCR3 = 0x100; //RED
	PORTD_PCR4 = 0x100; //GREEN
	PORTA_PCR2 = 0x100; //BLUE

	//Select GPIO Mode - OUTPUTS
	GPIOC_PDDR = (1 << 3);
	GPIOD_PDDR = (1 << 4);
	GPIOA_PDDR = (1 << 2);

	//Variable Declarations
	int counter;

	for(;;){
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 2; j++){
				for (int k = 0; k < 2; k++){
					//Cycling through each value in fn setLED
					setLED(i,j,k);
					for (counter = 0; counter < 5000000; counter++);
					//wait
				}
			}
		}
	}


}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////