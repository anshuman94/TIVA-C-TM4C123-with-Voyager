/*
 * Objective : 	To blink an LED connected to a GPIO
 * Date: 		August 16, 2016
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


/**************** MAIN FUNCTION ********************/

int main(void) {
	
	SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);		//Configures the clock of the controller
	SysCtlPeripheralEnable(LED_SYSPERIPH);													//Enables the GPIO Port

	GPIOPinTypeGPIOOutput(LED_BASE,LED_PIN);												//Configures the selected pin as GPIO Output

	GPIOPinWrite(LED_BASE,LED_PIN,0);														//Sets the Selected pin to be low

	while(1){																				//This segment toggles the LED on and off
		SysCtlDelay(SysCtlClockGet()/3);													//Delay of 1 second
		GPIOPinWrite(LED_BASE,LED_PIN,LED_PIN);
		SysCtlDelay(SysCtlClockGet()/3);
		GPIOPinWrite(LED_BASE,LED_PIN,0);
	}
	return 0;
}

