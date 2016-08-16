/*
 * Objective :	To control an LED using a Switch
 * Date:		August 16,2016
 * Author :		Anshuman Mishra
 * 				Nikhilesh Prasannakumar
 * 				Sachin Demla
 */

/******************* INCLUDES **********************/
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"


/************ CONSTANTS AND DEFINES ****************/
#define LED_SYSPERIPH SYSCTL_PERIPH_GPIOF				//Sets the SYSCTL Peripheral to be enabled
#define LED_BASE GPIO_PORTF_BASE						//Selects the Port of the pin on which the LED is connected
#define LED_PIN GPIO_PIN_3								//Selects the pin on which the LED is connected

#define SWITCH_SYSPERIPH SYSCTL_PERIPH_GPIOF				//Sets the SYSCTL Peripheral to be enabled
#define SWITCH_BASE GPIO_PORTF_BASE						//Selects the Port of the pin on which the LED is connected
#define SWITCH_PIN GPIO_PIN_4								//Selects the pin on which the LED is connected



/**************** MAIN FUNCTION ********************/

int main(void) {
	
	SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);		//Configure the clock settings of the controller
	SysCtlPeripheralEnable(LED_SYSPERIPH|SWITCH_SYSPERIPH);									//Enable the Peripherals

	GPIOPinTypeGPIOOutput(LED_BASE,LED_PIN);												//Setting the Pin Modes
	GPIOPinTypeGPIOInput(SWITCH_BASE,SWITCH_PIN);

	GPIOPadConfigSet(SWITCH_BASE,SWITCH_PIN,GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);		//Setting the Pad Settings*
	GPIOPinWrite(LED_BASE,LED_PIN,0);

	while(1){																				//This segmemt polls the switch and replicates its state on to the LED
		if(GPIOPinRead(SWITCH_BASE,SWITCH_PIN)==0)
			GPIOPinWrite(LED_BASE,LED_PIN,LED_PIN);
		else
			GPIOPinWrite(LED_BASE,LED_PIN,0);

	}
	return 0;
}

/************ FUNCTION DEFINITIONS ****************/
