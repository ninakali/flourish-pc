#include "spi.h"

#include <avr/io.h>

void ram_on () {
    init_spi();
    PORTB = PORTB & 0b11100111; // SD off, RAM on
}

void ram_sel () {
  PORTB = PORTB & 0b11100111; // SD off, RAM on
}

void ram_unsel () {
  PORTB = PORTB & 0b11100111; // SD off, RAM on
  PORTB = PORTB | 0b01000; // SD off, RAM on
}

void mem_wr(unsigned int addr, unsigned char b) {
    ram_sel();
    xmit_spi(0b01000000); // WR command
    xmit_spi(0); // highest ADDR bits are 00
    xmit_spi(addr >> 8); // ADDR byte1
    xmit_spi(addr & 0xff); // ADDR byte0
    xmit_spi(b);
    ram_unsel();
}

unsigned char mem_rd(unsigned int addr) {
  ram_sel();
  xmit_spi(0b11000000); // WR command
  xmit_spi(0); // highest ADDR bits are 00
  xmit_spi(addr >> 8); // ADDR byte1
  xmit_spi(addr & 0xff); // ADDR byte0
  return rcv_spi();
  ram_unsel();
}
