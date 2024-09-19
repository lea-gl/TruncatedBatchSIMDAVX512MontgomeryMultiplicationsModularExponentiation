#include "fonctions.h"


void displayVect(const unsigned long int *A, char *var, int size)
{
	int i;
	printf("%s := ",var);
	
	for(i=0;i<size;i++){
		printf("%16.16lX ",A[size-1-i]);
	}
	printf("\n");
}


void displayVect512_NB_COEFF(const __m512i *A512, char *var)
{
	
	uint64_t * A = (uint64_t *) A512;
	
	for(int j=0;j<8;j++)
	{
		printf("%s[%d] := ",var,j);
		for(int i=0;i<NB_COEFF;i++){
			printf("%16.16lX ",A[j+(NB_COEFF-1-i)*8]);
		}
		printf("\n");
	}
}

void displayVect512(const __m512i *A512, char *var)
{
	
	uint64_t * A = (uint64_t *) A512;
	
	printf("%s := ",var);
	for(int j=0;j<8;j++)
	{
		printf("%16.16lX ",A[7-j]);
	}
	printf("\n");
}


void displayVect512_NB_COEFFx2(const __m512i *A512, char *var)
{
	
	uint64_t * A = (uint64_t *) A512;
	
	for(int j=0;j<8;j++)
	{
		printf("%s[%d] := ",var,j);
		for(int i=0;i<NB_COEFF*2;i++){
			printf("%16.16lX ",A[j+(NB_COEFF*2-1-i)*8]);
		}
		printf("\n");
	}
}



#include "arith_AVX512.c"



