#include "init.h"


void init_data(){

	printf("init_data()\n");

	mpz_init (modul_p);


	mpz_set_str (modul_p, "20282409603651670423947251285999", 10);//2**104-17
	gmp_printf("modul_p  : 0x%ZX\n\n\n", modul_p);

	//~ Note : lambda = 2 (see : modular multiplication in 'add_mult_poly.c').

}



void free_data(mpz_t in){

	mpz_clear (in);
}

