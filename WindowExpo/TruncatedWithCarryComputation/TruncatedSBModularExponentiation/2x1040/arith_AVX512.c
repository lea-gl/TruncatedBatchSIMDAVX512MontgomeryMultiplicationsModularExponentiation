

__m512i zero = (__m512i){0x0UL};

__m512i mask52 = (__m512i){0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL};

__m512i mask36 = (__m512i){0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL};

__m512i un = (__m512i){1UL, 1UL,1UL,1UL,1UL, 1UL,1UL,1UL};


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




inline void force_inline
fexpand_8_512_52(__m512i * output, const unsigned long int in[8][NB_COEFF64])
{
	unsigned long int *output64 = (unsigned long int *) output;
	
	
	for(int i=0;i<8;i++){
		output64[0+i] = in[i][0] & 0xfffffffffffff;// 52 bits
		
		for(int j=52;j<SIZE;j+=52){
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


void
fcontract_8_512_52(unsigned long int out[8][NB_COEFF64], __m512i * input)
{
	
	unsigned long int *input64 = (unsigned long int *) input;
	
	for(int i=0;i<8;i++){
		
		for(int j=0;j<NB_COEFF64;j++){out[i][j]=0x0UL;}
		
		for(int j=0;j<NB_COEFF;j++){
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
fcontract_8_512_52_res(unsigned long int out[8][NB_COEFF64*2], __m512i * input)
{
	
	unsigned long int *input64 = (unsigned long int *) input;
			
	__m512i * out512 = (__m512i*) out;
	
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

	


#include "sbMont512_1040.c"	





// Window size

#ifndef TEST
#define WIN_WIDTH 5
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
		/*displayVect512(&i512, "i512 ");
		displayVect512(&mask, "mask ");
		getchar();//*/
		for(int j=0;j<NB_COEFF;j++)
			t512[j] |= _mm512_and_si512(g512[i][j],mask);
		//displayVect512_NB_COEFF(t512, "t512 ");//*/
	}
}



/*************

Batch Modular Exponentiation


returns a**e mod n, using Montgomery multiplications and L-R Window algorithm

Parameters :

n_prime : for Block Montgomery


**************/

void
modExp_8_512(unsigned long int out[8][NB_COEFF64], unsigned long int a[8][NB_COEFF64], unsigned long int e[8][NB_COEFF64], __m512i n[NB_COEFF], __m512i n_prime[1], __m512i r2[NB_COEFF], __m512i n_prime2[NB_COEFF])
{

	__m512i e512[NB_COEFF], g512[W][NB_COEFF], out512[NB_COEFF], a0_512[NB_COEFF];
	
	
	
	fexpand_8_512_52(g512[1], a);
	
	fexpand_8_512_64(e512, e);
	
	
	/*displayVect512_NB_COEFF(e512, "e512 ");
	getchar();//*/
	
	// generating power of g
	
	
	// conversion to the Montgomery domain :
	
	mont_mul512_8_1040(g512[0], un512, r2, n, n_prime2);// a0 = a x R
	mont_mul512_8_1040(g512[1], g512[1], r2, n, n_prime2);// a0 = a x R
	
#if WIN_WIDTH>=2
	
	mont_square512_8_1040(g512[2], g512[1], n, n_prime2);// g^2
	mont_mul512_8_1040(g512[3], g512[1],g512[2] , n, n_prime2);// g^3

#endif	
#if  WIN_WIDTH>=3
	
	mont_square512_8_1040(g512[4], g512[2], n, n_prime2);// g^4
	mont_mul512_8_1040(g512[5], g512[1],g512[4] , n, n_prime2);// g^5
	mont_square512_8_1040(g512[6], g512[3], n, n_prime2);// g^6
	mont_mul512_8_1040(g512[7], g512[1],g512[6] , n, n_prime2);// g^7

#endif	
#if  WIN_WIDTH>=4

	mont_square512_8_1040(g512[8], g512[4], n, n_prime2);// g^8
	mont_mul512_8_1040(g512[9], g512[1],g512[8] , n, n_prime2);// g^9
	mont_square512_8_1040(g512[10], g512[5], n, n_prime2);// g^10
	mont_mul512_8_1040(g512[11], g512[1],g512[10] , n, n_prime2);// g^11
	mont_square512_8_1040(g512[12], g512[6], n, n_prime2);// g^12
	mont_mul512_8_1040(g512[13], g512[1],g512[12] , n, n_prime2);// g^13
	mont_square512_8_1040(g512[14], g512[7], n, n_prime2);// g^14
	mont_mul512_8_1040(g512[15], g512[1],g512[14] , n, n_prime2);// g^15



#endif	
#if  WIN_WIDTH>=5

	mont_square512_8_1040(g512[16], g512[8], n, n_prime2);// g^16
	mont_mul512_8_1040(g512[17], g512[1],g512[16] , n, n_prime2);// g^17
	mont_square512_8_1040(g512[18], g512[9], n, n_prime2);// g^18
	mont_mul512_8_1040(g512[19], g512[1],g512[18] , n, n_prime2);// g^19
	mont_square512_8_1040(g512[20], g512[10], n, n_prime2);// g^20
	mont_mul512_8_1040(g512[21], g512[1],g512[20] , n, n_prime2);// g^21
	mont_square512_8_1040(g512[22], g512[11], n, n_prime2);// g^22
	mont_mul512_8_1040(g512[23], g512[1],g512[22] , n, n_prime2);// g^23
	mont_square512_8_1040(g512[24], g512[12], n, n_prime2);// g^24
	mont_mul512_8_1040(g512[25], g512[1],g512[24] , n, n_prime2);// g^25
	mont_square512_8_1040(g512[26], g512[13], n, n_prime2);// g^26
	mont_mul512_8_1040(g512[27], g512[1],g512[26] , n, n_prime2);// g^27
	mont_square512_8_1040(g512[28], g512[14], n, n_prime2);// g^28
	mont_mul512_8_1040(g512[29], g512[1],g512[28] , n, n_prime2);// g^29
	mont_square512_8_1040(g512[30], g512[15], n, n_prime2);// g^30
	mont_mul512_8_1040(g512[31], g512[1],g512[30] , n, n_prime2);// g^31

#endif	

	/*for(int j=0;j<W;j++){
		char str[10];
		sprintf(str,"g512[%d]",j);
		displayVect512_NB_COEFF(g512[j], str);

	}//*/
	
	
	
	//mont_mul512_8_1040(out512, un512, r2, n, n_prime2);// a0 = a x R
	
	for(int j=0;j<NB_COEFF;j++)
		out512[j] = g512[0][j];
	
		
	__m512i	b512 = _mm512_and_si512(_mm512_srli_epi64(e512[(1024-WIN_WIDTH)>>6],(1024-WIN_WIDTH)&0x3f),mask_wb);
		
	select_8_512(a0_512,b512,g512);
	
	
	//displayVect512_NB_COEFF(a0_512, "après swap\na0_512 ");//*/

	
	//block_mont_mul512_8_1040(a1_512, a0_512, a1_512, n, n_prime);// a1 = a1 x a0 x R
	
	
	mont_mul512_8_1040(out512, a0_512, out512, n, n_prime2);// a1 = a1 x a0 x R
	
	
	
#if 64%WIN_WIDTH==0
	for(int i = 1024-2*WIN_WIDTH; i>=0;i-=WIN_WIDTH)
#else
	for(int i = 1024-2*WIN_WIDTH; i>0;i-=WIN_WIDTH)
#endif//*/
	{
		//scan bits
		int w_start = i>>6;
		
		//printf("i = %d, w_start = %d\n",i,w_start);
		

#if 64%WIN_WIDTH==0
		b512 = _mm512_and_si512(_mm512_srli_epi64(e512[w_start],i&0x3f),mask_wb);
		
		/*printf("64 mod WIN_WIDTH==%d\n",64%WIN_WIDTH);
		
		displayVect512(&mask_wb, "mask_wb ");//*/
		
#else		// extraction des bits
		int w_end = (i+WIN_WIDTH-1)>>6;
		//printf("i_end = %d, w_end = %d\n",i+WIN_WIDTH-1,w_end);
		if(w_start==w_end)
			b512 = _mm512_and_si512(_mm512_srli_epi64(e512[w_start],i&0x3f),mask_wb);
		else{
			//int b_start = i&0x3f;	
			//int b_end = (i-W)&0x3f;
			b512=zero;
			for(int j=0;j<WIN_WIDTH;j++){
				int ind = (i+j);
				int w = ind>>6;
				int b = ind&0x3f;
				//printf("ind = %d,w = %d, b = %d\n",ind, w,b);
				//b512 |= _mm512_and_si512(_mm512_srli_epi64(e512[w],b),un);
				b512 |= ((e512[w]>>b)&un)<<j;
				/*displayVect512(e512+w, "e512 ");
				displayVect512(&b512, "b512 ");
				getchar();//*/
				
			}
		}
		/*printf("64 mod WIN_WIDTH==%d\n",64%WIN_WIDTH);
		
		displayVect512(&mask_wb, "mask_wb ");
		
		getchar();//*/
#endif//*/


		/*displayVect512(&b512, "b512 ");
		getchar();
	
		
		
		//displayVect512_NB_COEFF(a0_512, "a0_512 ");//*/
		
		
		select_8_512(a0_512,b512,g512);
		
		
		//displayVect512_NB_COEFF(a0_512, "après swap\na0_512 ");//*/

		
		//block_mont_mul512_8_1040(a1_512, a0_512, a1_512, n, n_prime);// a1 = a1 x a0 x R
		
		
		for(int i=0;i<WIN_WIDTH;i++)
			mont_square512_8_1040(out512, out512, n, n_prime2);// a1 = a^2 x R
		mont_mul512_8_1040(out512, a0_512, out512, n, n_prime2);// a1 = a1 x a0 x R
		
		
		

		//block_mont_mul512_8_1040(a0_512, a0_512, a0_512, n, n_prime);// a0 = a0^2 x R
		
			
		/*displayVect512_NB_COEFF(a0_512, "a0_512 ");
		displayVect512_NB_COEFF(a1_512, "a1_512 ");*/

		//swap_8_512(b512,a0_512,a1_512);
		
		/*displayVect512_NB_COEFF(a0_512, "après swap\na0_512 ");
		displayVect512_NB_COEFF(a1_512, "a1_512 ");*/
	
		//getchar();//*/
	
	}

	
#if WIN_WIDTH==3
	b512 = _mm512_and_si512(e512[0],un);
	select_8_512(a0_512,b512,g512);
	mont_square512_8_1040(out512, out512, n, n_prime2);// a1 = a^2 x R
	mont_mul512_8_1040(out512, a0_512, out512, n, n_prime2);// a1 = a1 x a0 x R
#endif//*/
	
#if WIN_WIDTH==5
	__m512i final_mask_wb = (__m512i){0xfUL,0xfUL,0xfUL,0xfUL,0xfUL,0xfUL,0xfUL,0xfUL};
	b512 = _mm512_and_si512(e512[0],final_mask_wb);
	select_8_512(a0_512,b512,g512);
	for(int i=0;i<4;i++)
		mont_square512_8_1040(out512, out512, n, n_prime2);// a1 = a^2 x R
	mont_mul512_8_1040(out512, a0_512, out512, n, n_prime2);// a1 = a1 x a0 x R
#endif//*/
	
	
	//displayVect512_NB_COEFF(a0_512, "après swap\na0_512 ");//*/

	
	//block_mont_mul512_8_1040(a1_512, a0_512, a1_512, n, n_prime);// a1 = a1 x a0 x R
	
	
	// back to standard domain
	
	//block_mont_mul512_8_1040(a1_512, a0_512, un512, n, n_prime);
	
	
	mont_mul512_8_1040(out512, out512, un512, n, n_prime2);
	
	fcontract_8_512_52(out, out512);


}




















