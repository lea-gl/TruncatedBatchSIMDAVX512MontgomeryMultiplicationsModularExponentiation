

void fexpand_8_512_52(__m512i * output, const unsigned long int in[8][NB_COEFF64]);

void fexpand_8_512_51(unsigned long int *output, const unsigned long int *in[8]);


void fcontract_8_512_52(unsigned long int out[8][NB_COEFF64], __m512i * input);

void
fcontract_8_512_52_res(unsigned long int out[8][NB_COEFF64*2], __m512i * input);

//void
//mul512_8_520(__m512i out[NB_COEFF*2], __m512i a512[NB_COEFF], __m512i b512[NB_COEFF]);
void
block_mont_mul512_8_2080(__m512i out[NB_COEFF], __m512i a512[NB_COEFF], __m512i b512[NB_COEFF], __m512i n[NB_COEFF],  __m512i n_prime[1]);


