
#ifndef FONCTIONS
#define FONCTIONS

#define CEIL_DIVIDE(a, b)  ((a/b) + (a % b == 0 ? 0 : 1)) /*!< Divide a by b and ceil the result*/


#define SIZE 2080//520//1024//2048//260//208//156//104//

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

//#include <immintrin.h>

//#include "init.h"


void displayVect(const unsigned long int *A, char *var, int size);

/*void displayVect512_NB_COEFF(const __m512i *A512, char *var);

void displayVect512(const __m512i *A512, char *var);

void displayVect512_NB_COEFFx2(const __m512i *A512, char *var);






#include "arith_AVX512.h"//*/


#endif

