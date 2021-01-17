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

    //unsigned char tmpB = 0x00; // Temporary variable to hold the value of B 
    unsigned char tmpA0 = 0x00; // Temporary variable to hold the value of A0
    unsigned char tmpA1 = 0x00;	// temp variable to hold the value of A1
while(1) {
        // 1) Read input of A0 and A1
        tmpA0 = PINA & 0x01;
	tmpA1 = PINA & 0x02;
        
	// 2) Perform computation
        // Determine what enables PB0 to 1 (PA1 == 0 && PA0 == 1)
        if ((tmpA1 == 0x00) && (tmpA0 == 0x01)) { 
            PORTB = 0x01;         
        } else {
            PORTB = 0x00;
        }    
    
    }
    return 0;
}

