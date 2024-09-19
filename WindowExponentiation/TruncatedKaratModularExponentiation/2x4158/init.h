#ifndef INIT
#define INIT

#define NB_COEFF CEIL_DIVIDE(SIZE,52)

void init_data();

void free_data(mpz_t modul_p);

static mpz_t modul_p;

#endif

