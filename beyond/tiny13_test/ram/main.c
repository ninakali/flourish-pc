/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42, by Joerg Wunsch):
 * <dinuxbg .at. gmail.com> wrote this file.  As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return.
 *                                                             Dimitar Dimitrov
 * ----------------------------------------------------------------------------
 */

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "dbg_putchar.h"

#include "mem.h"

int main(void)
{
	char c = 'A';

	dbg_tx_init();
	dbg_putchar('H');
	dbg_putchar('i');
	dbg_putchar('\n');

	ram_on();
	mem_wr(0, 0x13);
	mem_wr(1, 0x37);

	char u0 = mem_rd(0);
	char u1 = mem_rd(1);

	dbg_putchar(0x30 + ((u0 >> 4) & 0xf));
	dbg_putchar(0x30 + ((u0) & 0xf));

	dbg_putchar(0x30 + ((u1 >> 4) & 0xf));
	dbg_putchar(0x30 + ((u1) & 0xf));
	dbg_putchar('\n');

	while(1) {
		dbg_putchar(c);
		if(++c > 'Z') c = 'A';
	}

	return 0;
}
