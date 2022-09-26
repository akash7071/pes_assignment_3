/*
 * Author: Akash Patil
 * PES Assignment
 *
 */


#include "led.h"
#include "log.h"

/*Initialise required variables before use*/
int led_color=0;
int touched=0;
int touch_value=0;
int count_left=5;
int off_time=5;
int delaySequence[4]={5,10,15,20};
int index=1;


/*enum to check for next state*/
enum state{
	update,
	poll,
	changeDelay
}next_state;

/*Start of infinite sequence
 * Function:led_sequence
 * input:nothing
 * Return: nothing
 * Function description: Function top poll the touch sensor for input and change the LED state based on those values
 */

void led_sequence(){
while(1){
touch_value=Touch_Scan_LH();
LOG("-------------------------------------------------- \n");
LOG(" Positional Data :\n\n", touch_value);
LOG("-------------------------------------------------- \n");

switch(next_state){
//Condition for polling the touch sensor and sampling the data
case poll:


if(touch_value<10)
	led_color=0;

else if(touch_value>10 && touch_value<500)	//boundaries for Red color
{
led_color=1;
touched=1;

}
else if(touch_value>500 && touch_value<1000)	//boundaries for GREEN color
{
led_color=2;
touched=1;
}

else if(touch_value>1000)			//boundaries for BLUE color
{
led_color=3;
touched=1;
}


next_state=update;				//Update next_state to update for updating LED state
//break;




/*Update case where the color of the LEDs are changed and delays are called*/
case update:

	if((led_color==0) && (count_left!=0) && (touched==0))		//white color LED sequence  for 100ms
	{
	WHITE_LED_ON();
	delay(1);
	count_left--;
	}

	else if((led_color==1) && (count_left!=0))			//red color LED sequence  for 100ms
	{
		RED_LED_ON();
		delay(1);
		count_left--;
	}

	else if((led_color==2) && (count_left!=0))		//green color LED sequence  for 100ms
	{
		GREEN_LED_ON();
		delay(1);
		count_left--;
	}

	else if((led_color==3) && (count_left!=0))			//blue color LED sequence for 100ms
	{
		BLUE_LED_ON();
		delay(1);
		count_left--;
	}

	else if (count_left==0)							//If total delay>500ms, change delay sequence
	{

		next_state=changeDelay;
		break;
	}


next_state=poll;
//break;
/*Once first loop with 500ms delay is iterated through, increase sequence to 10ms and so forth*/
case changeDelay:

	LEDS_OFF();
	delay(1);
	off_time--;										//for 500ms off time
	if(count_left==0 && off_time==0)
	{
		count_left=delaySequence[index++];
		off_time=5;
		if(index>3)
			index=1;								//if index out of bounds, reset to init
		next_state=poll;
		break;



	}
}

}

}
