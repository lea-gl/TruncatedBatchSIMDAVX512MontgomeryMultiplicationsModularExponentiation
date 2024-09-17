

__m256i zero = (__m256i){0x0UL};

__m256i mask52 = (__m256i){0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL};

__m256i mask36 = (__m256i){0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL};

__m256i un = (__m256i){1UL, 1UL,1UL,1UL};


	__m256i un256[NB_COEFF] = {
		(__m256i){1UL, 1UL,1UL,1UL},
		(__m256i){0x0UL},
		(__m256i){0x0UL},
		(__m256i){0x0UL},
		(__m256i){0x0UL},
		(__m256i){0x0UL},
		(__m256i){0x0UL},
		(__m256i){0x0UL},
		(__m256i){0x0UL},
		(__m256i){0x0UL},
		(__m256i){0x0UL},
		(__m256i){0x0UL},
		(__m256i){0x0UL},
		(__m256i){0x0UL},
		(__m256i){0x0UL},
		(__m256i){0x0UL},
		(__m256i){0x0UL},
		(__m256i){0x0UL},
		(__m256i){0x0UL},
		(__m256i){0x0UL}	
	};





inline void force_inline
fexpand_4_256_64(__m256i * output, const unsigned long int in[4][NB_COEFF64])
{
	unsigned long int *output64 = (unsigned long int *) output;
	
	
	for(int j=0;j<NB_COEFF64;j++)
		for(int i=0;i<4;i++){
			int jj = j<<2;
			output64[jj+i] = in[i][j];
		}
}




inline void force_inline
fexpand_4_256_52(__m256i * output, const unsigned long int in[4][NB_COEFF64])
{
	unsigned long int *output64 = (unsigned long int *) output;
	
	
	for(int i=0;i<4;i++){
		output64[0+i] = in[i][0] & 0xfffffffffffff;// 52 bits
		
		for(int j=52;j<SIZE;j+=52){
			int startword = j>>6;
			int endword = (j+51)>>6;
			int jj=(j/52);
			int decl = (12*jj)&0x3f;
			int decr = (64-decl)&0x3f;
			if(decl) 
				output64[(jj<<2)+i] = (endword!=startword)?((in[i][startword] >> decr) ^ (in[i][endword] << decl)) & 0xfffffffffffff:((in[i][startword] >> decr) ^ (in[i][startword+1] << decl)) & 0xfffffffffffff;
			else output64[(jj<<2)+i] = (in[i][startword] >> decr)& 0xfffffffffffff;
		}
	}
}


void
fcontract_4_256_52(unsigned long int out[4][NB_COEFF64], __m256i * input)
{
	
	unsigned long int *input64 = (unsigned long int *) input;
	
	for(int i=0;i<4;i++){
		
		for(int j=0;j<NB_COEFF64;j++){out[i][j]=0x0UL;}
		
		for(int j=0;j<NB_COEFF;j++){
			int startbit = (j*52);
			int endbit =  ((j+1)*52)-1;
			int startword = startbit>>6;
			int endword = endbit>>6;
			if(startword==endword){
				int decl = startbit&0x3f;
				int jj = j<<2;
				out[i][startword] |=  input64[i+jj]<<decl;
			} else {
				int jj = j<<2;
				int decl = startbit&0x3f;
				int decr = (64-decl)&0x3f;
				out[i][startword] |=  input64[i+jj]<<decl;//|input64[i+jj-8]>>decr;
				out[i][endword] |=input64[i+jj]>>decr;
			}
		}
	}//*/
	
	/*for(int i=0;i<4;i++){
		for(int j=0;j<NB_COEFF-1;j++){
			int jj=j<<2;
			int decr = (12*j)&0xffffff;
			int decl = (52-decr)&0xffffff;
			out[i][j] =  input64[i+jj]>>decr | input64[i+jj+4]<<decl;//& 0xfffffffffffff;// 52 bits
			printf("%d, %d, %d, 0x%16.16lX\n",i,j,jj+i,out[i][j]);
		}
		int decr = (12*(NB_COEFF-1))&0xffffff;
		out[i][NB_COEFF-1] =  input64[(NB_COEFF-1)*4+i]>>decr;
	
	}//*/
	
	
}

void
fcontract_4_256_52_res(unsigned long int out[4][NB_COEFF64*2], __m256i * input)
{
	
	unsigned long int *input64 = (unsigned long int *) input;
			
	__m256i * out256 = (__m256i*) out;
	
	for(int i=0;i<4;i++){
		
		for(int j=0;j<NB_COEFF64*2;j++){out[i][j]=0x0UL;}
		
		for(int j=0;j<NB_COEFF*2;j++){
			int startbit = (j*52);
			int endbit =  ((j+1)*52)-1;
			int startword = startbit>>6;
			int endword = endbit>>6;
			if(startword==endword){
				int decl = startbit&0x3f;
				int jj = j<<2;
				out[i][startword] |=  input64[i+jj]<<decl;
			} else {
				int jj = j<<2;
				int decl = startbit&0x3f;
				int decr = (64-decl)&0x3f;
				out[i][startword] |=  input64[i+jj]<<decl;//|input64[i+jj-8]>>decr;
				out[i][endword] |=input64[i+jj]>>decr;
			}
		}

	}
}

	


#include "sbMont256_1040.c"	





// Window size

#ifndef TEST
#define WIN_WIDTH 5
#endif



#define W (1<<(WIN_WIDTH))



#if WIN_WIDTH==1

__m256i mask_wb = (__m256i){0x1UL,0x1UL,0x1UL,0x1UL};

#endif	

#if WIN_WIDTH==2

__m256i mask_wb = (__m256i){0x3UL,0x3UL,0x3UL,0x3UL};

#endif	
#if  WIN_WIDTH==3

__m256i mask_wb = (__m256i){0x7UL,0x7UL,0x7UL,0x7UL};

#endif	
#if  WIN_WIDTH==4

__m256i mask_wb = (__m256i){0xfUL,0xfUL,0xfUL,0xfUL};

#endif	
#if  WIN_WIDTH==5

__m256i mask_wb = (__m256i){0x1fUL,0x1fUL,0x1fUL,0x1fUL};

#endif	



inline void select_4_256(__m256i t256[NB_COEFF], __m256i wb,__m256i g256[W][NB_COEFF]){

	for(int j=0;j<NB_COEFF;j++)
		t256[j] = zero;
	for(int i=0;i<W;i++){
		__m256i i256 = _mm256_set1_epi64x((__int64_t) i);
		__mmask8 k = _mm256_cmpeq_epi64_mask (i256, wb);
		__m256i mask = _mm256_maskz_abs_epi64 (k, mask52);
		/*afficheVect256(&i256, "i256 ");
		afficheVect256(&mask, "mask ");
		getchar();//*/
		for(int j=0;j<NB_COEFF;j++)
			t256[j] |= _mm256_and_si256(g256[i][j],mask);
		//afficheVect256_NB_COEFF(t256, "t256 ");//*/
	}
}



/*************

Batch Modular Exponentiation


returns a**e mod n, using Montgomery multiplications and L-R Window algorithm

Parameters :

n_prime : for Block Montgomery


**************/

void
modExp_4_256(unsigned long int out[4][NB_COEFF64], unsigned long int a[4][NB_COEFF64], unsigned long int e[4][NB_COEFF64], __m256i n[NB_COEFF], __m256i n_prime[1], __m256i r2[NB_COEFF], __m256i n_prime2[NB_COEFF])
{

	__m256i e256[NB_COEFF], g256[W][NB_COEFF], out256[NB_COEFF], a0_256[NB_COEFF];
	
	
	
	fexpand_4_256_52(g256[1], a);
	
	fexpand_4_256_64(e256, e);
	
	
	/*afficheVect256_NB_COEFF(e256, "e256 ");
	getchar();//*/
	
	// génération des puissances de g
	
	
	// conversion to the Montgomery domain :
	
	mont_mul256_4_1040(g256[0], un256, r2, n, n_prime2);// a0 = a x R
	mont_mul256_4_1040(g256[1], g256[1], r2, n, n_prime2);// a0 = a x R
	
#if WIN_WIDTH>=2
	
	mont_square256_4_1040(g256[2], g256[1], n, n_prime2);// g^2
	mont_mul256_4_1040(g256[3], g256[1],g256[2] , n, n_prime2);// g^3

#endif	
#if  WIN_WIDTH>=3
	
	mont_square256_4_1040(g256[4], g256[2], n, n_prime2);// g^4
	mont_mul256_4_1040(g256[5], g256[1],g256[4] , n, n_prime2);// g^5
	mont_square256_4_1040(g256[6], g256[3], n, n_prime2);// g^6
	mont_mul256_4_1040(g256[7], g256[1],g256[6] , n, n_prime2);// g^7

#endif	
#if  WIN_WIDTH>=4

	mont_square256_4_1040(g256[8], g256[4], n, n_prime2);// g^8
	mont_mul256_4_1040(g256[9], g256[1],g256[8] , n, n_prime2);// g^9
	mont_square256_4_1040(g256[10], g256[5], n, n_prime2);// g^10
	mont_mul256_4_1040(g256[11], g256[1],g256[10] , n, n_prime2);// g^11
	mont_square256_4_1040(g256[12], g256[6], n, n_prime2);// g^12
	mont_mul256_4_1040(g256[13], g256[1],g256[12] , n, n_prime2);// g^13
	mont_square256_4_1040(g256[14], g256[7], n, n_prime2);// g^14
	mont_mul256_4_1040(g256[15], g256[1],g256[14] , n, n_prime2);// g^15



#endif	
#if  WIN_WIDTH>=5

	mont_square256_4_1040(g256[16], g256[8], n, n_prime2);// g^16
	mont_mul256_4_1040(g256[17], g256[1],g256[16] , n, n_prime2);// g^17
	mont_square256_4_1040(g256[18], g256[9], n, n_prime2);// g^18
	mont_mul256_4_1040(g256[19], g256[1],g256[18] , n, n_prime2);// g^19
	mont_square256_4_1040(g256[20], g256[10], n, n_prime2);// g^20
	mont_mul256_4_1040(g256[21], g256[1],g256[20] , n, n_prime2);// g^21
	mont_square256_4_1040(g256[22], g256[11], n, n_prime2);// g^22
	mont_mul256_4_1040(g256[23], g256[1],g256[22] , n, n_prime2);// g^23
	mont_square256_4_1040(g256[24], g256[12], n, n_prime2);// g^24
	mont_mul256_4_1040(g256[25], g256[1],g256[24] , n, n_prime2);// g^25
	mont_square256_4_1040(g256[26], g256[13], n, n_prime2);// g^26
	mont_mul256_4_1040(g256[27], g256[1],g256[26] , n, n_prime2);// g^27
	mont_square256_4_1040(g256[28], g256[14], n, n_prime2);// g^28
	mont_mul256_4_1040(g256[29], g256[1],g256[28] , n, n_prime2);// g^29
	mont_square256_4_1040(g256[30], g256[15], n, n_prime2);// g^30
	mont_mul256_4_1040(g256[31], g256[1],g256[30] , n, n_prime2);// g^31

#endif	

	/*for(int j=0;j<W;j++){
		char str[10];
		sprintf(str,"g256[%d]",j);
		afficheVect256_NB_COEFF(g256[j], str);

	}//*/
	
	
	
	//mont_mul256_4_1040(out256, un256, r2, n, n_prime2);// a0 = a x R
	
	for(int j=0;j<NB_COEFF;j++)
		out256[j] = g256[0][j];
	
		
	__m256i	b256 = _mm256_and_si256(_mm256_srli_epi64(e256[(1024-WIN_WIDTH)>>6],(1024-WIN_WIDTH)&0x3f),mask_wb);
		
	select_4_256(a0_256,b256,g256);
	
	
	//afficheVect256_NB_COEFF(a0_256, "après swap\na0_256 ");//*/

	
	//block_mont_mul256_4_1040(a1_256, a0_256, a1_256, n, n_prime);// a1 = a1 x a0 x R
	
	
	mont_mul256_4_1040(out256, a0_256, out256, n, n_prime2);// a1 = a1 x a0 x R
	
	
	
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
		b256 = _mm256_and_si256(_mm256_srli_epi64(e256[w_start],i&0x3f),mask_wb);
		
		/*printf("64 mod WIN_WIDTH==%d\n",64%WIN_WIDTH);
		
		afficheVect256(&mask_wb, "mask_wb ");//*/
		
#else		// extraction des bits
		int w_end = (i+WIN_WIDTH-1)>>6;
		//printf("i_end = %d, w_end = %d\n",i+WIN_WIDTH-1,w_end);
		if(w_start==w_end)
			b256 = _mm256_and_si256(_mm256_srli_epi64(e256[w_start],i&0x3f),mask_wb);
		else{
			//int b_start = i&0x3f;	
			//int b_end = (i-W)&0x3f;
			b256=zero;
			for(int j=0;j<WIN_WIDTH;j++){
				int ind = (i+j);
				int w = ind>>6;
				int b = ind&0x3f;
				//printf("ind = %d,w = %d, b = %d\n",ind, w,b);
				//b256 |= _mm256_and_si256(_mm256_srli_epi64(e256[w],b),un);
				b256 |= ((e256[w]>>b)&un)<<j;
				/*afficheVect256(e256+w, "e256 ");
				afficheVect256(&b256, "b256 ");
				getchar();//*/
				
			}
		}
		/*printf("64 mod WIN_WIDTH==%d\n",64%WIN_WIDTH);
		
		afficheVect256(&mask_wb, "mask_wb ");
		
		getchar();//*/
#endif//*/


		/*afficheVect256(&b256, "b256 ");
		getchar();
	
		
		
		afficheVect256_NB_COEFF(a0_256, "a0_256 ");//*/
		
		
		select_4_256(a0_256,b256,g256);
		
		
		//afficheVect256_NB_COEFF(a0_256, "après swap\na0_256 ");//*/

		
		//block_mont_mul256_4_1040(a1_256, a0_256, a1_256, n, n_prime);// a1 = a1 x a0 x R
		
		
		for(int i=0;i<WIN_WIDTH;i++)
			mont_square256_4_1040(out256, out256, n, n_prime2);// a1 = a^2 x R
		mont_mul256_4_1040(out256, a0_256, out256, n, n_prime2);// a1 = a1 x a0 x R
		
		
		

		//block_mont_mul256_4_1040(a0_256, a0_256, a0_256, n, n_prime);// a0 = a0^2 x R
		
			
		/*afficheVect256_NB_COEFF(a0_256, "a0_256 ");
		afficheVect256_NB_COEFF(a1_256, "a1_256 ");*/

		//swap_4_256(b256,a0_256,a1_256);
		
		/*afficheVect256_NB_COEFF(a0_256, "après swap\na0_256 ");
		afficheVect256_NB_COEFF(a1_256, "a1_256 ");*/
	
		//getchar();//*/
	
	}

	
#if WIN_WIDTH==3
	b256 = _mm256_and_si256(e256[0],un);
	select_4_256(a0_256,b256,g256);
	mont_square256_4_1040(out256, out256, n, n_prime2);// a1 = a^2 x R
	mont_mul256_4_1040(out256, a0_256, out256, n, n_prime2);// a1 = a1 x a0 x R
#endif//*/
	
#if WIN_WIDTH==5
	__m256i final_mask_wb = (__m256i){0xfUL,0xfUL,0xfUL,0xfUL};
	b256 = _mm256_and_si256(e256[0],final_mask_wb);
	select_4_256(a0_256,b256,g256);
	for(int i=0;i<4;i++)
		mont_square256_4_1040(out256, out256, n, n_prime2);// a1 = a^2 x R
	mont_mul256_4_1040(out256, a0_256, out256, n, n_prime2);// a1 = a1 x a0 x R
#endif//*/
	
	
	//afficheVect256_NB_COEFF(a0_256, "après swap\na0_256 ");//*/

	
	//block_mont_mul256_4_1040(a1_256, a0_256, a1_256, n, n_prime);// a1 = a1 x a0 x R
	
	
	// retour dans le domaine de standard
	
	//block_mont_mul256_4_1040(a1_256, a0_256, un256, n, n_prime);
	
	
	mont_mul256_4_1040(out256, out256, un256, n, n_prime2);
	
	fcontract_4_256_52(out, out256);

	//printf("sortie modExp_4_256()\n");

}




















