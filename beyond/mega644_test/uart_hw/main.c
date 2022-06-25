#include <stdio.h>
#include <avr/io.h>

#include "uart.h"

FILE uart_str = FDEV_SETUP_STREAM(uart_putchar, uart_getchar, _FDEV_SETUP_RW);

int main(){
  uart_init();

  stdout = stdin = &uart_str;

  puts("Hello, UART!\n");

  while (1) {
      puts("ACK?\n");
  }
}
