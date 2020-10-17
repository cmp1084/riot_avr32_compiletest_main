#include <avr32/io.h>

//~ #if __STDC_VERSION__ >= 201112L
//~ # ifdef __STDC_NO_ATOMICS__
//~ #  error Your C11 compiler is not required to provide stdatomic.h
//~ # else
//~ #  include <stdatomic.h>
//~ # endif
//~ #else
//~ # error Your C compiler isnt providing C11.
//~ #endif

int main(void)
{

	puts("Hello World!");

	printf("You are running RIOT on a(n) %s board.\n", RIOT_BOARD);
	printf("This board features a(n) %s MCU.\n", RIOT_MCU);
	while (1);
	return 0;	//Will not execute.
}
