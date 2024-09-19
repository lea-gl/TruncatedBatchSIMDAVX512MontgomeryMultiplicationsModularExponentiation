

void fexpand_8_512_52(__m512i * output, const unsigned long int in[8][NB_COEFF]);

void fcontract_8_512_52(unsigned long int out[8][NB_COEFF], __m512i * input);

void
fcontract_8_512_52_res(unsigned long int out[8][NB_COEFF*2], __m512i * input);

void
mul512_8_SIZE(__m512i out[NB_COEFF*2], __m512i a512[NB_COEFF], __m512i b512[NB_COEFF]);

void
square512_8_SIZE(__m512i out[NB_COEFF*2], __m512i a512[NB_COEFF]);


