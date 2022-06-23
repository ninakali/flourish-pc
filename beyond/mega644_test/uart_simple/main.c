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


int main(void)
{
	char c = 'A';

	dbg_tx_init();

	while(1) {
		dbg_putchar(c);
		if(++c > 'Z') c = 'A';
	}

	return 0;
}

