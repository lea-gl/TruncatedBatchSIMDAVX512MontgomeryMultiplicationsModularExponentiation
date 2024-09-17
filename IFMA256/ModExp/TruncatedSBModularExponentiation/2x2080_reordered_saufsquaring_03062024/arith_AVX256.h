

void fexpand_4_256_52(__m256i * output, const unsigned long int in[8][NB_COEFF64]);

void fexpand_4_256_51(unsigned long int *output, const unsigned long int *in[8]);


void fcontract_4_256_52(unsigned long int out[8][NB_COEFF64], __m256i * input);

void
fcontract_4_256_52_res(unsigned long int out[8][NB_COEFF64*2], __m256i * input);

//void
//mul256_4_520(__m256i out[NB_COEFF*2], __m256i a256[NB_COEFF], __m256i b256[NB_COEFF]);
void
mont_mul256_4_2080(__m256i out[NB_COEFF], __m256i a256[NB_COEFF], __m256i b256[NB_COEFF], __m256i n[NB_COEFF],  __m256i n_prime[NB_COEFF]);

void
mont_square256_4_2080(__m256i out[NB_COEFF], __m256i a256[NB_COEFF], __m256i n[NB_COEFF],  __m256i n_prime[NB_COEFF]);

void
modExp_4_256(unsigned long int out[8][NB_COEFF64], unsigned long int a[8][NB_COEFF64], unsigned long int e[8][NB_COEFF64], __m256i n[NB_COEFF], __m256i n_prime[1], __m256i r2[NB_COEFF]);

