
void fexpand_8_512_1038K(__m512i * output, const unsigned long int in[8][NB_COEFF64]);

void fcontract_8_512_1038K(unsigned long int out[8][NB_COEFF64], __m512i * input);

void
fcontract_8_512_1038K_res(unsigned long int out[8][NB_COEFF64*2], __m512i * input);

void
mont_mul512_8_1038K(__m512i out[NB_COEFF], __m512i a512[NB_COEFF], __m512i b512[NB_COEFF], __m512i n[NB_COEFF],  __m512i n_prime[NB_COEFF]);

void
mont_square512_8_1038K(__m512i out[NB_COEFF], __m512i a512[NB_COEFF], __m512i n[NB_COEFF],  __m512i n_prime[NB_COEFF]);

