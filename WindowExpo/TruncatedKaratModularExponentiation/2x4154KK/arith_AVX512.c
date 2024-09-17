/**************************************************************************

		Karatsuba Multipication, Operands sizes: 4154 bits
		
Multiplication built this way :

- operands divides in two parts of 4154/2 = 2077 bits = SIZE_K

	al, ah and bl, bh

- each part of SIZE_K bits is then used for a Karatsuba multiplication :

	al * bl = D0 of size 4154 bits

	ah * bh = D2 of size 4154 bits

	(al + ah) * (bl + bh) = D1 of size 4156 bits since the sums are of size 2078 bits
	
- each elementary product of size 2077 or 2078 bits is made by a Karatsuba multiplication, this time, operands ar divides in 2 parts of de 1039 bits and multiplied through a classic "schoolbook" method.

Altogether, we perform 9 "schoolbook" multiplications of size 1039 to 1040 bits (small operands sums)

**************************************************************************/

__m512i zero = (__m512i){0x0UL};

__m512i mask52 = (__m512i){0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL};

__m512i mask51 = (__m512i){0x7ffffffffffffUL,0x7ffffffffffffUL,0x7ffffffffffffUL,0x7ffffffffffffUL,0x7ffffffffffffUL,0x7ffffffffffffUL,0x7ffffffffffffUL,0x7ffffffffffffUL};

__m512i mask50 = (__m512i){0x3ffffffffffffUL,0x3ffffffffffffUL,0x3ffffffffffffUL,0x3ffffffffffffUL,0x3ffffffffffffUL,0x3ffffffffffffUL,0x3ffffffffffffUL,0x3ffffffffffffUL};

__m512i un = (__m512i){1UL,1UL,1UL,1UL,1UL,1UL,1UL,1UL};


	__m512i un512[NB_COEFF] = {
		(__m512i){1UL, 1UL,1UL,1UL,1UL, 1UL,1UL,1UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL}	
	};


inline void force_inline
fexpand_8_512_64(__m512i * output, const unsigned long int in[8][NB_COEFF64])
{
	unsigned long int *output64 = (unsigned long int *) output;
	
	
	for(int j=0;j<NB_COEFF64;j++)
		for(int i=0;i<8;i++){
			int jj = j<<3;
			output64[jj+i] = in[i][j];
		}
}



/****
*
*	function expanding operands of 1039 bits stored on 64 bits words
*	to 52 bits words
*
*/





static inline void force_inline
fexpand_8_512_52(__m512i * output, const unsigned long int in[8][NB_COEFF64_SLICE])
{
	unsigned long int *output64 = (unsigned long int *) output;
	
	
	for(int i=0;i<8;i++){
		output64[0+i] = in[i][0] & 0xfffffffffffff;// 52 bits
		
		for(int j=52;j<SLICE;j+=52){
			int startword = j>>6;
			int endword = (j+51)>>6;
			int jj=(j/52);
			int decl = (12*jj)&0x3f;
			int decr = (64-decl)&0x3f;
			if(decl) 
				output64[(jj<<3)+i] = (endword!=startword)?((in[i][startword] >> decr) ^ (in[i][endword] << decl)) & 0xfffffffffffff:((in[i][startword] >> decr) ^ (in[i][startword+1] << decl)) & 0xfffffffffffff;
			else output64[(jj<<3)+i] = (in[i][startword] >> decr)& 0xfffffffffffff;
		
		}
		
	}
}


/****
*
*	function expanding operands of 2077 bits stored on 64 bits words
*	to 52 bits words
*
*/


static inline void force_inline
fexpand_8_512_2078K(__m512i * output, const unsigned long int in[8][NB_COEFF64])
{
	uint64_t tmp[8][NB_COEFF64_SLICE];

	for(int i=0;i<NB_SLICES;i++){
	
		int startbit = i*SLICE;
		int endbit =  (i+1)*SLICE-1;
		int startword = startbit>>6;
		int endword = endbit>>6;
		int diff = endword-startword; 
		if (endword>NB_COEFF64_SIZE_K) endword= NB_COEFF64_SIZE_K-1;
		int decr = (startbit)&0x3f;
		int decl = (64-decr)&0x3f;

		for(int k=0;k<8;k++){
			for(int j=0;j<diff;j++){
				if(decl) {
					tmp[k][j] = ((in[k][j+startword] >> decr) ^ (in[k][j+startword+1] << decl))  ;
				}	
				else tmp[k][j] = in[k][j+startword];
			}
			if(decl) 
				tmp[k][diff] = (((in[k][endword] >> decr) ^ (in[k][endword+1] << decl)))&0x7fffUL  ;//mask : 1039-1024 = 15 bits
			else tmp[k][diff] = in[k][endword]&0x7fffUL;
			
			
		}
		fexpand_8_512_52( output + (NB_COEFF_SLICE*i), tmp);
	}


}



static inline void force_inline
fexpand_8_512_2077K(__m512i * output, const unsigned long int in[8][NB_COEFF64_SIZE_K])
{
	uint64_t tmp[8][NB_COEFF64_SLICE];

	for(int i=0;i<NB_SLICES;i++){
	
		int startbit = i*SLICE;
		int endbit =  (i+1)*SLICE-1;
		int startword = startbit>>6;
		int endword = endbit>>6;
		int diff = endword-startword; 
		if (endword>NB_COEFF64_SIZE_K) endword= NB_COEFF64_SIZE_K-1;
		int decr = (startbit)&0x3f;
		int decl = (64-decr)&0x3f;

		for(int k=0;k<8;k++){
			for(int j=0;j<diff;j++){
				if(decl) {
					tmp[k][j] = ((in[k][j+startword] >> decr) ^ (in[k][j+startword+1] << decl))  ;
				}	
				else tmp[k][j] = in[k][j+startword];
			}
			if(decl) 
				tmp[k][diff] = (((in[k][endword] >> decr) ^ (in[k][endword+1] << decl)))&0x7fffUL  ;//mask : 1039-1024 = 15 bits
			else tmp[k][diff] = in[k][endword]&0x7fffUL;
			
			
		}
		fexpand_8_512_52( output + (NB_COEFF_SLICE*i), tmp);
	}


}


/****
*
*	function expanding operands of 4154 bits stored on 64 bits words
*	to 52 bits words
*
*/


inline void force_inline
fexpand_8_512_4154KK(__m512i * output, const unsigned long int in[8][NB_COEFF64])
{
	uint64_t tmp[8][NB_COEFF64_SIZE_K];

	for(int i=0;i<NB_SIZE_K;i++){
	
		int startbit = i*SIZE_K;
		int endbit =  (i+1)*SIZE_K-1;
		int startword = startbit>>6;
		int endword = endbit>>6;
		int diff = endword-startword; 
		int decr = (startbit)&0x3f;
		int decl = (64-decr)&0x3f;

		for(int k=0;k<8;k++){
			for(int j=0;j<diff;j++){
				if(decl) {
					tmp[k][j] = ((in[k][j+startword] >> decr) ^ (in[k][j+startword+1] << decl))  ;
				}	
				else tmp[k][j] = in[k][j+startword];
			}
			if(decl) 
				tmp[k][diff] = (((in[k][endword] >> decr) ^ (in[k][endword+1] << decl)))&0x1fffffffUL  ;//mask : 2077-2048 = 29 bits
			else tmp[k][diff] = in[k][endword]&0x1fffffffUL;
			
			
		}
		fexpand_8_512_2077K( output + (NB_COEFF_SIZE_K*i), tmp);
	}


}








/****
*
*	CONTRACT FUNCTIONS
*
*/







void
fcontract_8_512_52_res(unsigned long int out[8][NB_COEFF64*2], __m512i * input)
{
	
	unsigned long int *input64 = (unsigned long int *) input;
			
	
		for(int i=0;i<8;i++){
			
			
			for(int j=0;j<NB_COEFF64*2;j++){out[i][j]=0x0UL;}
			
			for(int j=0;j<NB_COEFF*2;j++){
				int startbit = (j*52);
				int endbit =  ((j+1)*52)-1;
				int startword = startbit>>6;
				int endword = endbit>>6;
				if(startword==endword){
					int decl = startbit&0x3f;
					int jj = j<<3;
					out[i][startword] |=  input64[i+jj]<<decl;
				} else {
					int jj = j<<3;
					int decl = startbit&0x3f;
					int decr = (64-decl)&0x3f;
					out[i][startword] |=  input64[i+jj]<<decl;//|input64[i+jj-8]>>decr;
					out[i][endword] |=input64[i+jj]>>decr;
				
				
				}
			}
	
	}
}


static inline void
fcontract_8_512_52(unsigned long int out[8][NB_COEFF64_SLICE], __m512i * input)
{
	
	unsigned long int *input64 = (unsigned long int *) input;
	
		for(int i=0;i<8;i++){
			
			for(int j=0;j<NB_COEFF64_SLICE;j++){out[i][j]=0x0UL;}
			
			for(int j=0;j<NB_COEFF_SLICE;j++){
				int startbit = (j*52);
				int endbit =  ((j+1)*52)-1;
				int startword = startbit>>6;
				int endword = endbit>>6;
				if(startword==endword){
					int decl = startbit&0x3f;
					int jj = j<<3;
					out[i][startword] |=  input64[i+jj]<<decl;
				} else {
					int jj = j<<3;
					int decl = startbit&0x3f;
					int decr = (64-decl)&0x3f;
					out[i][startword] |=  input64[i+jj]<<decl;//|input64[i+jj-8]>>decr;
					out[i][endword] |=input64[i+jj]>>decr;
				
				
				}
			}
	
	}
}

void
fcontract_8_512_2078K(unsigned long int out[8][NB_COEFF64], __m512i * input)
{
	

	
	unsigned long int *input64 = (unsigned long int *) input;
			
	
	for(int i=0;i<8;i++)
		for(int j=0;j<NB_COEFF64_SIZE_K;j++){out[i][j]=0x0UL;}


	uint64_t tmp[8][NB_COEFF64_SLICE];

	for(int i=0;i<NB_SLICES;i++){
		fcontract_8_512_52(tmp, input + (NB_COEFF_SLICE*i));

		int startbit = i*SLICE;
		int endbit =  (i+1)*SLICE-1;
		int startword = startbit>>6;
		int endword = endbit>>6;
		int diff = endword-startword; 
		if (endword>NB_COEFF64_SIZE_K) endword= NB_COEFF64_SIZE_K-1;
		int decl = (startbit)&0x3f;
		int decr = (64-decl)&0x3f;

		for(int k=0;k<8;k++){
			if(decl) {
				out[k][startword] |= tmp[k][0] << decl  ;
			}
			else out[k][startword] |= tmp[k][0];
			for(int j=1;j<NB_COEFF64_SLICE;j++){
				if(decl) {
					out[k][j+startword] |= ((tmp[k][j] << decl) | (tmp[k][j-1]>> decr ))  ;
				}	
				else out[k][j+startword] |= tmp[k][j];
			}
			
			
		}
	}


}

void
fcontract_8_512_2078K_res(unsigned long int out[8][NB_COEFF64*2], __m512i * input)
{


	
	unsigned long int *input64 = (unsigned long int *) input;
			
	
	for(int i=0;i<8;i++)
		for(int j=0;j<NB_COEFF64*2;j++){out[i][j]=0x0UL;}


	uint64_t tmp[8][NB_COEFF64_SLICE];

	for(int i=0;i<NB_SLICES*2;i++){
		fcontract_8_512_52(tmp, input + (NB_COEFF_SLICE*i));

		int startbit = i*SLICE;
		int endbit =  (i+1)*SLICE-1;
		int startword = startbit>>6;
		int endword = endbit>>6;
		int diff = endword-startword; 
		if (endword>NB_COEFF64_SIZE_K) endword= NB_COEFF64_SIZE_K-1;
		int decl = (startbit)&0x3f;
		int decr = (64-decl)&0x3f;

		for(int k=0;k<8;k++){
			if(decl) {
				out[k][startword] |= tmp[k][0] << decl  ;
			}
			else out[k][startword] |= tmp[k][0];
			for(int j=1;j<NB_COEFF64_SLICE;j++){
				if(decl) {
					out[k][j+startword] |= ((tmp[k][j] << decl) | (tmp[k][j-1]>> decr ))  ;
				}	
				else out[k][j+startword] |= tmp[k][j];
			}
			
		}
	}

}



/****
*
*	function contracting operands of 2077 bits stored on 64 bits words
*	to 52 bits words, represented in base 2^1039
*
*/



static void
fcontract_8_512_2077K(unsigned long int out[8][NB_COEFF64_SIZE_K], __m512i * input)
{
	

	
	unsigned long int *input64 = (unsigned long int *) input;
			
	
	for(int i=0;i<8;i++)
		for(int j=0;j<NB_COEFF64_SIZE_K;j++){out[i][j]=0x0UL;}


	uint64_t tmp[8][NB_COEFF64_SLICE];

	for(int i=0;i<NB_SLICES;i++){
		fcontract_8_512_52(tmp, input + (NB_COEFF_SLICE*i));

		int startbit = i*SLICE;
		int endbit =  (i+1)*SLICE-1;
		int startword = startbit>>6;
		int endword = endbit>>6;
		int diff = endword-startword; 
		if (endword>NB_COEFF64_SIZE_K) endword= NB_COEFF64_SIZE_K-1;
		int decl = (startbit)&0x3f;
		int decr = (64-decl)&0x3f;

		for(int k=0;k<8;k++){
			if(decl) {
				out[k][startword] |= tmp[k][0] << decl  ;
			}
			else out[k][startword] |= tmp[k][0];
			for(int j=1;j<NB_COEFF64_SLICE;j++){
				if(decl) {
					out[k][j+startword] |= ((tmp[k][j] << decl) | (tmp[k][j-1]>> decr ))  ;
				}	
				else out[k][j+startword] |= tmp[k][j];
			}
			
			
		}
	}


}

static void
fcontract_8_512_2077K_res(unsigned long int out[8][NB_COEFF64_SIZE_K*2], __m512i * input)
{
	

	
	unsigned long int *input64 = (unsigned long int *) input;
			
	
	for(int i=0;i<8;i++)
		for(int j=0;j<NB_COEFF64_SIZE_K*2;j++){out[i][j]=0x0UL;}


	uint64_t tmp[8][NB_COEFF64_SLICE];

	for(int i=0;i<NB_SLICES*2;i++){
		fcontract_8_512_52(tmp, input + (NB_COEFF_SLICE*i));

		int startbit = i*SLICE;
		int endbit =  (i+1)*SLICE-1;
		int startword = startbit>>6;
		int endword = endbit>>6;
		int diff = endword-startword; 
		if (endword>NB_COEFF64_SIZE_K) endword= NB_COEFF64_SIZE_K-1;
		int decl = (startbit)&0x3f;
		int decr = (64-decl)&0x3f;

		for(int k=0;k<8;k++){
			if(decl) {
				out[k][startword] |= tmp[k][0] << decl  ;
			}
			else out[k][startword] |= tmp[k][0];
			for(int j=1;j<NB_COEFF64_SLICE;j++){
				if(decl) {
					out[k][j+startword] |= ((tmp[k][j] << decl) | (tmp[k][j-1]>> decr ))  ;
				}	
				else out[k][j+startword] |= tmp[k][j];
			}
			
			
		}
	}


}


/****
*
*	function contracting operands of 4154 bits stored on 64 bits words
*	to 52 bits words, represented in base 2^2077
*
*/





void
fcontract_8_512_4154KK(unsigned long int out[8][NB_COEFF64], __m512i * input)
{
	

	
	unsigned long int *input64 = (unsigned long int *) input;
			
	
	for(int i=0;i<8;i++)
		for(int j=0;j<NB_COEFF64;j++){out[i][j]=0x0UL;}


	uint64_t tmp[8][NB_COEFF64_SIZE_K];

	for(int i=0;i<NB_SIZE_K;i++){
		fcontract_8_512_2077K(tmp, input + (NB_COEFF_SIZE_K*i));

		int startbit = i*SIZE_K;
		int endbit =  (i+1)*SIZE_K-1;
		int startword = startbit>>6;
		int endword = endbit>>6;
		int diff = endword-startword; 
		int decl = (startbit)&0x3f;
		int decr = (64-decl)&0x3f;

		for(int k=0;k<8;k++){
			if(decl) {
				out[k][startword] |= tmp[k][0] << decl  ;
			}
			else out[k][startword] |= tmp[k][0];
			for(int j=1;j<NB_COEFF64_SIZE_K;j++){
				if(decl) {
					out[k][j+startword] |= ((tmp[k][j] << decl) | (tmp[k][j-1]>> decr ))  ;
				}	
				else out[k][j+startword] |= tmp[k][j];
			}
			
			
		}
	}


}



void
fcontract_8_512_4154KK_res(unsigned long int out[8][NB_COEFF64*2], __m512i * input)
{
	

	
	unsigned long int *input64 = (unsigned long int *) input;
			
	
	for(int i=0;i<8;i++)
		for(int j=0;j<NB_COEFF64*2;j++){out[i][j]=0x0UL;}


	uint64_t tmp[8][NB_COEFF64_SIZE_K];

	for(int i=0;i<NB_SIZE_K*2;i++){
		fcontract_8_512_2077K(tmp, input + (NB_COEFF_SIZE_K*i));

		int startbit = i*SIZE_K;
		int endbit =  (i+1)*SIZE_K-1;
		int startword = startbit>>6;
		int endword = endbit>>6;
		int diff = endword-startword; 
		int decl = (startbit)&0x3f;
		int decr = (64-decl)&0x3f;

		for(int k=0;k<8;k++){
			if(decl) {
				out[k][startword] |= tmp[k][0] << decl  ;
			}
			else out[k][startword] |= tmp[k][0];
			for(int j=1;j<NB_COEFF64_SIZE_K;j++){
				if(decl) {
					out[k][j+startword] |= ((tmp[k][j] << decl) | (tmp[k][j-1]>> decr ))  ;
				}	
				else out[k][j+startword] |= tmp[k][j];
			}
			if(diff=NB_COEFF64_SIZE_K)
				out[k][endword] |= tmp[k][NB_COEFF64_SIZE_K-1] >> decr;

			
			
		}
	}


}



//////////////////////////////////


//		KARATSUBA 2078


//////////////////////////////////





#include "Mont512_4154KK.c"





/*****************************************************************************************************************/





// Window size

#ifndef TEST
#define WIN_WIDTH 1
#endif



#define W (1<<(WIN_WIDTH))



#if WIN_WIDTH==1

__m512i mask_wb = (__m512i){0x1UL,0x1UL,0x1UL,0x1UL,0x1UL,0x1UL,0x1UL,0x1UL};

#endif	

#if WIN_WIDTH==2

__m512i mask_wb = (__m512i){0x3UL,0x3UL,0x3UL,0x3UL,0x3UL,0x3UL,0x3UL,0x3UL};

#endif	
#if  WIN_WIDTH==3

__m512i mask_wb = (__m512i){0x7UL,0x7UL,0x7UL,0x7UL,0x7UL,0x7UL,0x7UL,0x7UL};

#endif	
#if  WIN_WIDTH==4

__m512i mask_wb = (__m512i){0xfUL,0xfUL,0xfUL,0xfUL,0xfUL,0xfUL,0xfUL,0xfUL};

#endif	
#if  WIN_WIDTH==5

__m512i mask_wb = (__m512i){0x1fUL,0x1fUL,0x1fUL,0x1fUL,0x1fUL,0x1fUL,0x1fUL,0x1fUL};

#endif	



inline void select_8_512(__m512i t512[NB_COEFF], __m512i wb,__m512i g512[W][NB_COEFF]){

	for(int j=0;j<NB_COEFF;j++)
		t512[j] = zero;
	for(int i=0;i<W;i++){
		__m512i i512 = _mm512_set1_epi64((__int64_t) i);
		__mmask8 k = _mm512_cmpeq_epi64_mask (i512, wb);
		__m512i mask = _mm512_maskz_abs_epi64 (k, mask52);

		for(int j=0;j<NB_COEFF;j++)
			t512[j] |= _mm512_and_si512(g512[i][j],mask);

	}
}



/*************

Batch Modular Exponentiation


returns a**e mod n, using Montgomery multiplications and L-R Window algorithm

Parameters :

n_prime : for Block Montgomery


**************/

void
modExp_8_512(unsigned long int out[8][NB_COEFF64], unsigned long int a[8][NB_COEFF64], unsigned long int e[8][NB_COEFF64], __m512i n[NB_COEFF], __m512i n_prime[NB_COEFF],  __m512i r2[NB_COEFF])
{

	__m512i e512[NB_COEFF], g512[W][NB_COEFF], out512[NB_COEFF], a0_512[NB_COEFF];
	
	
	
	fexpand_8_512_4154KK(g512[1], a);
	
	fexpand_8_512_64(e512, e);
	
	
	// generating power of g
	
	
	// conversion to the Montgomery domain :
	
	mont_mul512_8_4154KK(g512[0], un512, r2, n, n_prime);// a0 = a x R
	mont_mul512_8_4154KK(g512[1], g512[1], r2, n, n_prime);// a0 = a x R
	
#if WIN_WIDTH>=2
	
	mont_square512_8_4154KK(g512[2], g512[1], n, n_prime);// g^2
	mont_mul512_8_4154KK(g512[3], g512[1],g512[2] , n, n_prime);// g^3

#endif	
#if  WIN_WIDTH>=3
	
	mont_square512_8_4154KK(g512[4], g512[2], n, n_prime);// g^4
	mont_mul512_8_4154KK(g512[5], g512[1],g512[4] , n, n_prime);// g^5
	mont_square512_8_4154KK(g512[6], g512[3], n, n_prime);// g^6
	mont_mul512_8_4154KK(g512[7], g512[1],g512[6] , n, n_prime);// g^7

#endif	
#if  WIN_WIDTH>=4

	mont_square512_8_4154KK(g512[8], g512[4], n, n_prime);// g^8
	mont_mul512_8_4154KK(g512[9], g512[1],g512[8] , n, n_prime);// g^9
	mont_square512_8_4154KK(g512[10], g512[5], n, n_prime);// g^10
	mont_mul512_8_4154KK(g512[11], g512[1],g512[10] , n, n_prime);// g^11
	mont_square512_8_4154KK(g512[12], g512[6], n, n_prime);// g^12
	mont_mul512_8_4154KK(g512[13], g512[1],g512[12] , n, n_prime);// g^13
	mont_square512_8_4154KK(g512[14], g512[7], n, n_prime);// g^14
	mont_mul512_8_4154KK(g512[15], g512[1],g512[14] , n, n_prime);// g^15



#endif	
#if  WIN_WIDTH>=5

	mont_square512_8_4154KK(g512[16], g512[8], n, n_prime);// g^16
	mont_mul512_8_4154KK(g512[17], g512[1],g512[16] , n, n_prime);// g^17
	mont_square512_8_4154KK(g512[18], g512[9], n, n_prime);// g^18
	mont_mul512_8_4154KK(g512[19], g512[1],g512[18] , n, n_prime);// g^19
	mont_square512_8_4154KK(g512[20], g512[10], n, n_prime);// g^20
	mont_mul512_8_4154KK(g512[21], g512[1],g512[20] , n, n_prime);// g^21
	mont_square512_8_4154KK(g512[22], g512[11], n, n_prime);// g^22
	mont_mul512_8_4154KK(g512[23], g512[1],g512[22] , n, n_prime);// g^23
	mont_square512_8_4154KK(g512[24], g512[12], n, n_prime);// g^24
	mont_mul512_8_4154KK(g512[25], g512[1],g512[24] , n, n_prime);// g^25
	mont_square512_8_4154KK(g512[26], g512[13], n, n_prime);// g^26
	mont_mul512_8_4154KK(g512[27], g512[1],g512[26] , n, n_prime);// g^27
	mont_square512_8_4154KK(g512[28], g512[14], n, n_prime);// g^28
	mont_mul512_8_4154KK(g512[29], g512[1],g512[28] , n, n_prime);// g^29
	mont_square512_8_4154KK(g512[30], g512[15], n, n_prime);// g^30
	mont_mul512_8_4154KK(g512[31], g512[1],g512[30] , n, n_prime);// g^31

#endif	

	
	for(int j=0;j<NB_COEFF;j++)
		out512[j] = g512[0][j];
	
		
	__m512i	b512 = _mm512_and_si512(_mm512_srli_epi64(e512[(4096-WIN_WIDTH)>>6],(4096-WIN_WIDTH)&0x3f),mask_wb);
		
	select_8_512(a0_512,b512,g512);
	
	
	mont_mul512_8_4154KK(out512, a0_512, out512, n, n_prime);// a1 = a1 x a0 x R
	
	
	
#if 64%WIN_WIDTH==0
	for(int i = 4096-2*WIN_WIDTH; i>=0;i-=WIN_WIDTH)
#else
	for(int i = 4096-2*WIN_WIDTH; i>0;i-=WIN_WIDTH)
#endif//*/
	{
		//scan bits
		int w_start = i>>6;
		
		

#if 64%WIN_WIDTH==0
		b512 = _mm512_and_si512(_mm512_srli_epi64(e512[w_start],i&0x3f),mask_wb);
		
		
#else		// bits extraction
		int w_end = (i+WIN_WIDTH-1)>>6;
		if(w_start==w_end)
			b512 = _mm512_and_si512(_mm512_srli_epi64(e512[w_start],i&0x3f),mask_wb);
		else{
			b512=zero;
			for(int j=0;j<WIN_WIDTH;j++){
				int ind = (i+j);
				int w = ind>>6;
				int b = ind&0x3f;
				b512 |= ((e512[w]>>b)&un)<<j;
				
				
			}
		}
#endif//*/


		
		
		select_8_512(a0_512,b512,g512);
		
		for(int i=0;i<WIN_WIDTH;i++)
			mont_square512_8_4154KK(out512, out512, n, n_prime);// a1 = a^2 x R
		mont_mul512_8_4154KK(out512, a0_512, out512, n, n_prime);// a1 = a1 x a0 x R
		
		
	
	}

	
#if WIN_WIDTH==3
	b512 = _mm512_and_si512(e512[0],un);
	select_8_512(a0_512,b512,g512);
	mont_square512_8_4154KK(out512, out512, n, n_prime);// a1 = a^2 x R
	mont_mul512_8_4154KK(out512, a0_512, out512, n, n_prime);// a1 = a1 x a0 x R
#endif//*/
	
#if WIN_WIDTH==5
	b512 = _mm512_and_si512(e512[0],un);
	select_8_512(a0_512,b512,g512);
	mont_square512_8_4154KK(out512, out512, n, n_prime);// a1 = a^2 x R
	mont_mul512_8_4154KK(out512, a0_512, out512, n, n_prime);// a1 = a1 x a0 x R
#endif//*/

	
	// back to standard domain
	
	
	
	mont_mul512_8_4154KK(out512, out512, un512, n, n_prime);
	
	fcontract_8_512_4154KK(out, out512);


}

