/*	Author: nicholas casillas
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif   

#include <stdio.h>
#include <stdlib.h> 

int main(void) {
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
    DDRC = 0x00; PORTC = 0xFF; // input

    DDRD = 0xFF; PORTD = 0x00; // output

    unsigned char A = 0x00;  
    unsigned char B = 0x00; 
    unsigned char C = 0x00;	
    unsigned short weight = 0x00;
    unsigned char tmp = 0x00;

    while(1) {
      
        A = PINA;	
	B = PINB;
	C = PINC;
	
	weight = A + B + C;

	if(weight >= 0x8C) {	// greater than 140kg, set PD0 to 1
		tmp = 0x01;
	}
	else {
		tmp = 0x00;
	}

	if((abs(A - C)) > 0x50) {   //diff. of A,C greater than 80kg, set PD1 to 1
		tmp = tmp | 0x02;
	}

	tmp = (weight & 0xFC) | tmp;
	PORTD = tmp;
    }
    return 0;
}

