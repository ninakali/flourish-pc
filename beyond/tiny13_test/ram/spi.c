// PB0 - DATA OUT
// PB1 - DATA IN
// PB2 - SCK
// PB3 - RAM ~CS
// PB4 - SD CS

#include <avr/io.h>

void init_spi() {
    DDRB = DDRB | 0b11101; // PB0 and PB2-PB4 are outs
    DDRB = DDRB & 0b11111101; // PB1 is IN
}

void xmit_spi(unsigned char b) {
    for (int i=0; i<8; i++) {
        PORTB = (PORTB & 0b11111110) | (b & 0b1);
        b = b >> 1;
        // pulse on CLK
        PORTB = PORTB | 0b100;
        PORTB = PORTB & 0b11111011;
    }
}

unsigned char rcv_spi(){
  unsigned char d;
  d = 0;
  for (int i=0; i<8; i++) {
      PORTB = PORTB | 0b1; // send FF
      d = (d << 1) + ((PINB & 0b10) >> 1); //get the next bit
      // pulse on CLK
      PORTB = PORTB | 0b100;
      PORTB = PORTB & 0b11111011;
  }
  return d;
}
