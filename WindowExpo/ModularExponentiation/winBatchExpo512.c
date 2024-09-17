



// Window size
#define W 4

#if W>=2

__m512i mask_wb = (__m512i){0x3UL,0x3UL,0x3UL,0x3UL,0x3UL,0x3UL,0x3UL,0x3UL};

#endif	
#if  W>=3

__m512i mask_wb = (__m512i){0x7UL,0x7UL,0x7UL,0x7UL,0x7UL,0x7UL,0x7UL,0x7UL};

#endif	
#if  W>=4

__m512i mask_wb = (__m512i){0xfUL,0xfUL,0xfUL,0xfUL,0xfUL,0xfUL,0xfUL,0xfUL};

#endif	
#if  W>=5

__m512i mask_wb = (__m512i){0x1fUL,0x1fUL,0x1fUL,0x1fUL,0x1fUL,0x1fUL,0x1fUL,0x1fUL};

#endif	



inline void select(__m512i t512[NB_COEFF],__m512i **g512, __m512i wb){

	for(int i=0;i<W;i++){
		__m512i i512 = _mm512_set1_epi64((__int64) i);
		__mmask8 k = _mm512_cmpeq_epi64_mask (i512, wb);
		__m512i mask = _mm512_maskz_abs_epi64 (k, __m512i a);
		for(int j=0;j<NB_COEFF;j++)
			t512[j] = _mm512_and_si512(g512[i],mask);
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

	// generating power of g
	
	
	// conversion to the Montgomery domain :
	
	mont_mul512_8_1040(g512[0], un512, r2, n, n_prime2);// a0 = a x R
	mont_mul512_8_1040(g512[1], g512[1], r2, n, n_prime2);// a0 = a x R
	
#if W>=2
	
	mont_square512_8_1040(g512[2], g512[1], n, n_prime2);// g^2
	mont_mul512_8_1040(g512[3], g512[1],g512[2] , n, n_prime2);// g^3

#endif	
#if  W>=3
	
	mont_square512_8_1040(g512[4], g512[2], n, n_prime2);// g^4
	mont_mul512_8_1040(g512[5], g512[1],g512[4] , n, n_prime2);// g^5
	mont_square512_8_1040(g512[6], g512[3], n, n_prime2);// g^6
	mont_mul512_8_1040(g512[7], g512[1],g512[6] , n, n_prime2);// g^7

#endif	
#if  W>=4

	mont_square512_8_1040(g512[8], g512[4], n, n_prime2);// g^8
	mont_mul512_8_1040(g512[9], g512[1],g512[8] , n, n_prime2);// g^9
	mont_square512_8_1040(g512[10], g512[3], n, n_prime2);// g^10
	mont_mul512_8_1040(g512[11], g512[1],g512[10] , n, n_prime2);// g^11
	mont_square512_8_1040(g512[12], g512[6], n, n_prime2);// g^12
	mont_mul512_8_1040(g512[13], g512[1],g512[12] , n, n_prime2);// g^13
	mont_square512_8_1040(g512[14], g512[7], n, n_prime2);// g^14
	mont_mul512_8_1040(g512[15], g512[1],g512[14] , n, n_prime2);// g^15



#endif	
#if  W>=5

	mont_square512_8_1040(g512[16], g512[8], n, n_prime2);// g^16
	mont_mul512_8_1040(g512[17], g512[1],g512[16] , n, n_prime2);// g^17
	mont_square512_8_1040(g512[18], g512[9], n, n_prime2);// g^18
	mont_mul512_8_1040(g512[19], g512[1],g512[18] , n, n_prime2);// g^19
	mont_square512_8_1040(g512[20], g512[10], n, n_prime2);// g^20
	mont_mul512_8_1040(g512[21], g512[1],g512[20] , n, n_prime2);// g^21
	mont_square512_8_1040(g512[22], g512[11], n, n_prime2);// g^22
	mont_mul512_8_1040(g512[23], g512[1],g512[22] , n, n_prime2);// g^23
	mont_square512_8_1040(g512[24], g512[12], n, n_prime2);// g^24
	mont_mul512_8_1040(g512[25], g512[1],g512[25] , n, n_prime2);// g^25
	mont_square512_8_1040(g512[26], g512[13], n, n_prime2);// g^26
	mont_mul512_8_1040(g512[27], g512[1],g512[26] , n, n_prime2);// g^27
	mont_square512_8_1040(g512[28], g512[14], n, n_prime2);// g^28
	mont_mul512_8_1040(g512[29], g512[1],g512[28] , n, n_prime2);// g^29
	mont_square512_8_1040(g512[30], g512[15], n, n_prime2);// g^30
	mont_mul512_8_1040(g512[31], g512[1],g512[30] , n, n_prime2);// g^31

#endif	

	
	
	
	//mont_square512_8_1040(a1_512, a1_512, n, n_prime2);// a1 = a^2 x R
	
	for(int i = 1024; i>=0;i-=W)
	{
		//scan bits
		int w_start = (i-W)>>6;
		__m512i b512;

#if 64%W==0
	b512 = _mm512_and_si512(_mm512_srli_epi64(e512[w_start],i&0x3f),mask_wb);
#endif	

		
#if 64%W!=0
		// extraction des bits
		int w_end = (i-1)>>6;
		if(w_start==w_end)
			b512 = _mm512_and_si512(_mm512_srli_epi64(e512[w_start],i&0x3f),mask_wb);
		else{
			//int b_start = i&0x3f;	
			//int b_end = (i-W)&0x3f;
			b512=zero;
			for(int j=0;j<W;j++){
				int ind = (i-1-j);
				w = ind>>6;
				int b = ind&0x3f;
				//b512 |= _mm512_and_si512(_mm512_srli_epi64(e512[w],b),un);
				b512 |= ((e512[w]>>b)&un)<<j;
			}
		}
#endif


		/*displayVect512(&b512, "b512 ");
		
		
		displayVect512_NB_COEFF(a0_512, "a0_512 ");
		displayVect512_NB_COEFF(a1_512, "a1_512 ");//*/
		
		
		select_8_512(a0_512,b512,g512);
		
		
		/*displayVect512_NB_COEFF(a0_512, "après swap\na0_512 ");
		displayVect512_NB_COEFF(a1_512, "a1_512 ");*/

		
		//block_mont_mul512_8_1040(a1_512, a0_512, a1_512, n, n_prime);// a1 = a1 x a0 x R
		
		mont_mul512_8_1040(out512, a0_512, out512, n, n_prime2);// a1 = a1 x a0 x R
		

		//block_mont_mul512_8_1040(a0_512, a0_512, a0_512, n, n_prime);// a0 = a0^2 x R
		
		for(int i=0;i<W;i++)
			mont_square512_8_1040(out512, out512, n, n_prime2);// a1 = a^2 x R
		
	}

	// back to standard domain
	
	//block_mont_mul512_8_1040(a1_512, a0_512, un512, n, n_prime);
	
	
	mont_mul512_8_1040(out512, out512, un512, n, n_prime2);
	
	fcontract_8_512_52(out, out_512);


}






