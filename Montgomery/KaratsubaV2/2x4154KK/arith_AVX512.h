
void fexpand_8_512_2078K(__m512i * output, const unsigned long int in[8][NB_COEFF64]);

void fexpand_8_512_4154KK(__m512i * output, const unsigned long int in[8][NB_COEFF64]);

void fcontract_8_512_2078K(unsigned long int out[8][NB_COEFF64], __m512i * input);

void fcontract_8_512_4154KK(unsigned long int out[8][NB_COEFF64], __m512i * input);

void fcontract_8_512_4154KK_res(unsigned long int out[8][NB_COEFF64*2], __m512i * input);







void
fcontract_8_512_2078K_res(unsigned long int out[8][NB_COEFF64*2], __m512i * input);

void
mul512_8_2078K(__m512i out[NB_COEFF_SIZE_K*2], __m512i a512[NB_COEFF_SIZE_K], __m512i b512[NB_COEFF_SIZE_K]);

void
square512_8_2078K(__m512i out[NB_COEFF_SIZE_K*2], __m512i a512[NB_COEFF_SIZE_K]);



void
mont_mul512_8_4154KK(__m512i out[NB_COEFF], __m512i a512[NB_COEFF], __m512i b512[NB_COEFF], __m512i n[NB_COEFF],  __m512i n_prime[NB_COEFF]);

void
mont_square512_8_4154KK(__m512i out[NB_COEFF], __m512i a512[NB_COEFF], __m512i n[NB_COEFF],  __m512i n_prime[NB_COEFF]);


