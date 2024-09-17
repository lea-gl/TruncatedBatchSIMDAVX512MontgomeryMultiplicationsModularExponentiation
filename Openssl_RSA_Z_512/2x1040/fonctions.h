
#ifndef FONCTIONS
#define FONCTIONS

#define CEIL_DIVIDE(a, b)  ((a/b) + (a % b == 0 ? 0 : 1)) /*!< Divide a by b and ceil the result*/


#define SIZE 1040//520//1024//2048//260//208//156//104//

#define NB_COEFF CEIL_DIVIDE(SIZE,52)

#define NB_COEFF64 CEIL_DIVIDE(SIZE,64)


#undef force_inline
#define force_inline __attribute__((always_inline))



#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <stdint.h>
#include <gmp.h>
#include <openssl/bn.h>

#include <immintrin.h>

//#include "init.h"


void afficheVect(const unsigned long int *A, char *var, int size);

void afficheVect512_NB_COEFF(const __m512i *A512, char *var);

void afficheVect512(const __m512i *A512, char *var);

void afficheVect512_NB_COEFFx2(const __m512i *A512, char *var);





void fexpand(unsigned long int *output, const unsigned long int *in);

void fcontract (unsigned long int *output, const unsigned long int * input);



#include "arith_AVX512.h"


#endif

