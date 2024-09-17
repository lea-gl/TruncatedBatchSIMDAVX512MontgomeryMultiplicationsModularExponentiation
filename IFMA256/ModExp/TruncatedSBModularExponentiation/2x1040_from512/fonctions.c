#include "fonctions.h"

//#include "init.c"

void afficheVect(const unsigned long int *A, char *var, int size)
{
	int i;
	printf("%s := ",var);
	
	for(i=0;i<size;i++){
		printf("%16.16lX ",A[size-1-i]);
	}
	printf("\n");
}


void afficheVect256_NB_COEFF(const __m256i *A256, char *var)
{
	
	uint64_t * A = (uint64_t *) A256;
	
	for(int j=0;j<4;j++)
	{
		printf("%s[%d] := ",var,j);
		for(int i=0;i<NB_COEFF;i++){
			printf("%16.16lX ",A[j+(NB_COEFF-1-i)*4]);
		}
		printf("\n");
	}
}

void afficheVect256(const __m256i *A256, char *var)
{
	
	uint64_t * A = (uint64_t *) A256;
	
	printf("%s := ",var);
	for(int j=0;j<4;j++)
	{
		printf("%16.16lX ",A[3-j]);
	}
	printf("\n");
}


void afficheVect256_NB_COEFFx2(const __m256i *A256, char *var)
{
	
	uint64_t * A = (uint64_t *) A256;
	
	for(int j=0;j<4;j++)
	{
		printf("%s[%d] := ",var,j);
		for(int i=0;i<NB_COEFF*2;i++){
			printf("%16.16lX ",A[j+(NB_COEFF*2-1-i)*4]);
		}
		printf("\n");
	}
}



#include "arith_AVX256.c"



