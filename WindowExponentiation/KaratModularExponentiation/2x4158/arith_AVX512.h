


void fexpand_8_512_4158K(__m512i * output, const unsigned long int in[8][NB_COEFF64]);

void fcontract_8_512_4158K(unsigned long int out[8][NB_COEFF64], __m512i * input);


void
mont_square512_8_4158K(__m512i out[NB_COEFF], __m512i a512[NB_COEFF], __m512i n[NB_COEFF],  __m512i n_prime[1]);

void
mont_mul512_8_4158K(__m512i out[NB_COEFF], __m512i a512[NB_COEFF], __m512i b512[NB_COEFF], __m512i n[NB_COEFF],  __m512i n_prime[1]);

void
modExp_8_512(unsigned long int out[8][NB_COEFF64], unsigned long int a[8][NB_COEFF64], unsigned long int e[8][NB_COEFF64], __m512i* n, __m512i* n_prime, __m512i* r2);

