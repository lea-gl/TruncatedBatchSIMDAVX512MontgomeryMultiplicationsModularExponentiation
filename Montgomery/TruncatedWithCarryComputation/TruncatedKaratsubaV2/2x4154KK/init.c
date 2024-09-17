#include "init.h"


void init_data(){

	printf("init_data()\n");

	mpz_init (modul_p);



	// modul_p = 2^342+15
	//mpz_set_str (modul_p, "8958978968711216842229769122273777112486581988938598139599956403855167484720643781523509973086428463119", 10);

	// modul_p = 2^255-19
	// mpz_set_str (modul_p, "57896044618658097711785492504343953926634992332820282019728792003956564819949", 10);

	mpz_set_str (modul_p, "20282409603651670423947251285999", 10);//2**104-17
	gmp_printf("modul_p  : 0x%ZX\n\n\n", modul_p);

	//~ Note : lambda = 2 (see : modular multiplication in 'add_mult_poly.c').

}



void free_data(mpz_t in){

	mpz_clear (in);
}

