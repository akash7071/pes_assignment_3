/*
 * Author: Akash Patil
 *
 * Copyright 2016-2022 NXP
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
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
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

/**
 * @file    Assignment3.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"

#include "delay.h"
#include "log.h"
#include "led.h"
#include "sequence.h"



#define TOUCH_OFFSET 590  // offset value to be subtracted
#define TOUCH_DATA (TSI0->DATA & 0xFFFF)//macro for extracting the count from data register



/* Function to initialise the drivers of the touch*/
void Touch_Init()
{
	SIM->SCGC5 |= SIM_SCGC5_TSI_MASK; // enabling the clock


	TSI0->GENCS = TSI_GENCS_MODE(0u) | //operating in non-noise mode
								TSI_GENCS_REFCHRG(0u) | //reference oscillator charge and discharge value 500nA
								TSI_GENCS_DVOLT(0u) | //oscillator voltage rails set to default
								TSI_GENCS_EXTCHRG(0u) | //electrode oscillator charge and discharge value 500nA
								TSI_GENCS_PS(0u) |  // frequency clock divided by one
								TSI_GENCS_NSCN(31u) | //scanning the electrode 32 times
								TSI_GENCS_TSIEN_MASK | //enabling the TSI module
								TSI_GENCS_EOSF_MASK; // writing one to clear the end of scan flag


}





/* Function to poll the touch sensor for tense sensitive information*/
int Touch_Scan_LH(void)
{
	unsigned int scan = 0;
	TSI0->DATA = 	TSI_DATA_TSICH(10u);
	TSI0->DATA |= TSI_DATA_SWTS_MASK; //software trigger to start the scan
	while (!(TSI0->GENCS & TSI_GENCS_EOSF_MASK )) // waiting for the scan to complete 32 times
	;
	scan = TOUCH_DATA;
	TSI0->GENCS |= TSI_GENCS_EOSF_MASK ; //writing one to clear the end of scan flag
	return scan- TOUCH_OFFSET;
}




volatile uint32_t touch_val = 0 ;

int main(void)
{


	Touch_Init();//Initialise touch input
    led_init(); //call the init led to load all the registers
    new_init(); 	//	init sequence as provided in the requirement



    led_sequence();  //infinite loop to poll and update LEDs

    return 0 ;
}
