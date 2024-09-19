
#ifndef FONCTIONS
#define FONCTIONS

#define CEIL_DIVIDE(a, b)  ((a/b) + (a % b == 0 ? 0 : 1)) /*!< Divide a by b and ceil the result*/







#define SIZE_K 2077

#define NB_COEFF_SIZE_K CEIL_DIVIDE(SIZE_K,52)

#define NB_COEFF64_SIZE_K CEIL_DIVIDE(SIZE_K,64)




#define SLICE 1039

#define NB_COEFF_SLICE CEIL_DIVIDE(SLICE,52)

#define NB_SLICES CEIL_DIVIDE(SIZE_K,SLICE)

#define NB_COEFF64_SLICE CEIL_DIVIDE(SLICE,64)







#define SIZE 4154

#define NB_SIZE_K CEIL_DIVIDE(SIZE,SIZE_K)

#define NB_COEFF (NB_SIZE_K*NB_SLICES*NB_COEFF_SLICE)

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



void displayVect(const unsigned long int *A, char *var, int size);

void displayVect512_NB_COEFF(const __m512i *A512, char *var);

void displayVect512(const __m512i *A512, char *var);

void displayVect512_NB_COEFFx2(const __m512i *A512, char *var);





void multMod(unsigned long int  * output, unsigned long int * in, unsigned long int * in2);

void squaringMod(unsigned long int * output, unsigned long int * in);

#include "arith_AVX512.h"


#endif

