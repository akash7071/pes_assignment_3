/*
 * led.c
 *
 *  Created on: 26-Sep-2022
 *      Author: akash7071
 */


#include "led.h"
#include "log.h"
#include "board.h"
#include "MKL25Z4.h"
#include "delay.h"




/* Masks for LEDS. */
#define MASK(x) (1UL << (x))
#define RED_LED_SHIFT   (18)	// on port B
#define GREEN_LED_SHIFT (19)	// on port B
#define BLUE_LED_SHIFT  (1)		// on port D
/*To initlisze all LED pins to output, provide them clock and use them as GPIO*/
void led_init()
{
// Enable clock to Port B and Port D
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTD_MASK;

	// Make 3 pins GPIO
	PORTB->PCR[RED_LED_SHIFT] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[RED_LED_SHIFT] |= PORT_PCR_MUX(1);
	PORTB->PCR[GREEN_LED_SHIFT] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[GREEN_LED_SHIFT] |= PORT_PCR_MUX(1);
	PORTD->PCR[BLUE_LED_SHIFT] &= ~PORT_PCR_MUX_MASK;
	PORTD->PCR[BLUE_LED_SHIFT] |= PORT_PCR_MUX(1);

	// Set ports to outputs
	PTB->PDDR |= MASK(RED_LED_SHIFT) | MASK(GREEN_LED_SHIFT);
	PTD->PDDR |= MASK(BLUE_LED_SHIFT);

	//Set all LEDs On
	PTB->PCOR |= MASK(RED_LED_SHIFT) | MASK(GREEN_LED_SHIFT);
	PTD->PCOR |= MASK(BLUE_LED_SHIFT);

}
/* Init sequence as provided in the requirements*/
void new_init()
{
	RED_LED_ON();
	delay(5);
	LEDS_OFF();
	delay(1);

	GREEN_LED_ON();
	delay(5);
	LEDS_OFF();
	delay(1);

	BLUE_LED_ON();
	delay(5);
	LEDS_OFF();
	delay(1);

	WHITE_LED_ON();
	delay(1);
	LEDS_OFF();
	delay(1);

	WHITE_LED_ON();
	delay(1);
	LEDS_OFF();
	delay(1);

}




/*Function : to turn on only the RED LED
 * Input: none
 * Output:None
 */
void RED_LED_ON(){
	GPIOB->PSOR |= (1 << GREEN_LED_SHIFT);
	GPIOB->PCOR |= (1 << RED_LED_SHIFT);
	GPIOD->PSOR |= (1 << BLUE_LED_SHIFT);
	LOG("-------------------------------------------------- \n");
	LOG(" RED LED turned on");
	LOG("-------------------------------------------------- \n");
}
/*Function : to turn on only the BLUE LED only
 * Input: none
 * Output:None
 */
void BLUE_LED_ON()
{
	GPIOB->PSOR |= (1 << GREEN_LED_SHIFT);
	GPIOB->PSOR |= (1 << RED_LED_SHIFT);
	GPIOD->PCOR |= (1 << BLUE_LED_SHIFT);
}
/*Function : to turn on only the GREEN LED only
 * Input: none
 * Output:None
 */
void GREEN_LED_ON()
{
	GPIOB->PCOR |= (1 << GREEN_LED_SHIFT);
	GPIOB->PSOR |= (1 << RED_LED_SHIFT);
	GPIOD->PSOR |= (1 << BLUE_LED_SHIFT);
}
/*Function : to turn off all LEDs
 * Input: none
 * Output:None
 */
void LEDS_OFF()
{
	GPIOB->PSOR |= (1 << GREEN_LED_SHIFT);
	GPIOB->PSOR |= (1 << RED_LED_SHIFT);
	GPIOD->PSOR |= (1 << BLUE_LED_SHIFT);
}

/*Function : to turn on the WHITE color of the LED
 * Input: none
 * Output:None
 */
void WHITE_LED_ON(){
	GPIOB->PCOR |= (1 << GREEN_LED_SHIFT);
	GPIOB->PCOR |= (1 << RED_LED_SHIFT);
	GPIOD->PCOR |= (1 << BLUE_LED_SHIFT);
}
