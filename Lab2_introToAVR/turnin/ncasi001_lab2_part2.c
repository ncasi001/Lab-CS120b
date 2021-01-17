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

int main(void) {
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s

    unsigned char cntavail = 0x00; // Temporary variable to hold the value of B 
    unsigned char tmpA0 = 0x00; // Temporary variable to hold the value of A0
    unsigned char tmpA1 = 0x00;	// temp variable to hold the value of A1
    unsigned char tmpA2 = 0x00;
    unsigned char tmpA3 = 0x00;

while(1) {
      
        tmpA0 = PINA & 0x01;	// getting each value
	tmpA1 = PINA & 0x02;
	tmpA2 = PINA & 0x04;
	tmpA3 = PINA & 0x08;

	tmpA1 = tmpA1 >> 1;	// shift to bit 0
	tmpA2 = tmpA2 >> 2;
	tmpA3 = tmpA3 >> 3;
      
	cntavail = tmpA0 + tmpA1 + tmpA2 + tmpA3;	// sum it up
	cntavail = 0x04 - cntavail;

    	PORTC = cntavail;
    }
    return 0;
}

