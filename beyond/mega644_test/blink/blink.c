#define F_CPU 8000000L // built-in XTAL is 8MHz

#include <avr/io.h>
#include <util/delay.h>


int main()
{

    DDRB = 1; // DDRB - Port B direction set to 0000 0001
    while(1)
    {
        PORTB ^= 1; // flip the lowest bit of PORT B
        _delay_ms(500);
    }
}
