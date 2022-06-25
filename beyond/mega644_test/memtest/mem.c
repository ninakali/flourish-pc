/* Memory access routines */
/* terribly inefficient lol */
/* ADDR: PA0-7, PD2-7, PB0-1, PB4 */
/* DATA: PC0-7 */
/* PB3 - OE~ */
/* PB2 - WE~ */

#include "defines.h"

#include <avr/io.h>
#include <util/delay.h>

void mem_init() {
    DDRA = 0xff; // ALL port A is address, hence output
    DDRD = DDRD | 0b11111100; // All but two lower bits are address
    DDRB = DDRB | 0b00011111; // 5 lowest bits of PB are used by memory
    PORTB = PORTB | 0b00001100; // We don't read, we don't write at first
    PORTB = PORTB & 0b11101111; // turn off A16 line - it's for banking
}

inline void set_addr(unsigned int addr) {
    unsigned int pd, pb;
    PORTA = (addr & 0xff); // low 8 bits
    addr = addr >> 8;
    // let's hope the compiler will optimise this :3
    pd = (addr & 0b11111100); // highest 6 bits
    pb = addr & 0b11; // 2 bits in the middle
    PORTD = (PORTD & 0b11) | pd;
    PORTB = (PORTB & 0b11111100) | pb;
}

void mem_wr(unsigned int addr, unsigned char data) {
    set_addr(addr);
    _delay_ms(50);
    DDRC = 0xff; // write cycle
    PORTC = data;
    _delay_ms(50);
    PORTB = PORTB & 0b11111011; // write
    _delay_ms(50);
    PORTB = PORTB | 0b00001100; // reset mem state
    _delay_ms(50);
}

unsigned char mem_rd(unsigned int addr) {
    unsigned char data = 0;
    set_addr(addr);
    _delay_ms(50);
    DDRC = 0x00; // read cycle
    //PORTC = 0xff; // pull-up on
    PORTB = PORTB & 0b11110111; // read
    _delay_ms(50);
    data = PINC; // read read read
    _delay_ms(50);
    PORTB = PORTB | 0b00001100; // reset mem state
    return data;
    _delay_ms(50);
}
