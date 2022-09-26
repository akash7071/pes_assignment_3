/*
 * delay.c
 *
 *  Created on: 26-Sep-2022
 *      Author: akash7071
 */


#include "delay.h"

// ----------------------------------------------Delay------------------------------------------------
/***********************************************************************************
 * @function : while loop to produce the delay. No of iterations are defined
 *              in delay.h
 * parameters : milliseconds
 * return : none
***********************************************************************************/
void delay(int millis)
{
    int loops = NO_OF_LOOPS * millis;

    while (loops--)
        ;
}
//--
