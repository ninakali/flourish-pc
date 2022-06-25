#include "defines.h"


#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "dbg_putchar.h"
#include "mem.h"

int main(void)
{
	char c = 'A';

	dbg_tx_init();
  mem_init();

	while(1) {
    mem_wr(0, 'A');
    mem_rd(0);
    mem_wr(1, 'Z');
    mem_rd(1);
    c = mem_rd(0);
    dbg_putchar('A');
		dbg_putchar(c);
	}

	return 0;
}

/*
FILE uart_str = FDEV_SETUP_STREAM(uart_putchar, uart_getchar, _FDEV_SETUP_RW);

void write_mem(){
  unsigned int addrx = 0;
  for (addrx=0;addrx<=0xfff;addrx++) {
      mem_wr(addrx, addrx & 0xff);
      if (addrx % 0x100 == 0) printf("[%x]\n", addrx);
  }
}

void read_mem(){
  unsigned int addrx = 0;
  unsigned char read=0;
  for (addrx=0;addrx<=0xfff;addrx++) {
      read = mem_rd(addrx);
      if (read != (addrx & 0xff)) {
          printf("Error reading mem at %x, got %x!\n", addrx, read);
      };
  }
}

int main(){
  uart_init();
  mem_init();


  stdout = stdin = &uart_str;

  puts("Hello, UART!\n");

    _delay_ms(2000);

  unsigned char c0,c1,c2;


  while (1) {
      puts("ACK?");
      _delay_ms(1);
      mem_wr(0, 0x5a);
      c0 = mem_rd(0);
      puts("Memory written. Let's read it back.");
      printf("Memory read done: %x\n", c0);

      _delay_ms(1);

      mem_wr(1, 0xfe);
      c1 = mem_rd(1);
      puts("Memory written. Let's read it back.");
      printf("Memory read done: %x\n", c1);

      _delay_ms(1);
      c2 = mem_rd(0);
      puts("Memory written. Let's read it back.");
      printf("Memory read done: %x\n", c2);
  }
}

*/
