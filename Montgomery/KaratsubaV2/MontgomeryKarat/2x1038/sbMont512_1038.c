/* Schoolbook multiplication */

#include "sb512_1038.c"

static inline void redMont512_8_1038K(__m512i out[20], __m512i in512[40], __m512i n[20],  __m512i n_prime[20]);



__m512i mask36 = (__m512i){0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL};




inline void force_inline mont_mul512_8_1038K(__m512i out[20], __m512i a512[20], __m512i b512[20], __m512i n[20],  __m512i n_prime[20])
{

	__m512i t512[40];

	mul512_8_1038K(t512, a512, b512);

	redMont512_8_1038K(out, t512, n,  n_prime);
}





/* Schoolbook squaring */

inline void force_inline mont_square512_8_1038K(__m512i out[20], __m512i a512[20], __m512i n[20],  __m512i n_prime[20])
{
	
	__m512i t512[40];
	
	square512_8_1038K(t512, a512);
	
	
	redMont512_8_1038K(out, t512, n,  n_prime);

}


//#define WITH_FMA

//#define DEBUG

static inline void redMont512_8_1038K(__m512i out[20], __m512i in512[40], __m512i n[20],  __m512i n_prime[20])//with fma
{
	__m512i q512[20], t512[40];
	
	
	mul512_8_1038K_modM(q512, in512, n_prime);
	//mul512_8_1038K(q512, in512, n_prime);


#ifdef DEBUG	
	
	mpz_t A8[8], B8[8], C8[8], E8[8];
	for(int i=0;i<8;i++)	
		mpz_inits (A8[i], B8[i], C8[i], E8[i], NULL);
		
	uint64_t a64[8][NB_COEFF64], b64[8][NB_COEFF64], c64[8][NB_COEFF64], res64[8][NB_COEFF64], t64[8][NB_COEFF64*2];
	
	
	printf("redMont512_8_1038()\n");
	
	displayVect512_NB_COEFF(n,"n512");
	
	displayVect512_NB_COEFF(n_prime,"n_prime");
	
	displayVect512_NB_COEFF(q512,"q512");
	
	
	
	
	printf("fcontract_8_512_1038K()\n");
	fcontract_8_512_1038K( a64, in512);
	
	fcontract_8_512_1038K( b64, n_prime);
	
	fcontract_8_512_1038K( c64, q512);
	
	for(int i=0;i<8;i++){	
		mpz_import(A8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,a64[i]);
		mpz_import(B8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,b64[i]);
		gmp_printf("A8[i] : %ZX\n",A8[i]);
		gmp_printf("B8[i] : %ZX\n",B8[i]);
	}
		
	for(int i=0;i<8;i++){	
		mpz_mul(C8[i],A8[i],B8[i]);
		
		displayVect(c64[i],"q512[i]   ",NB_COEFF64);
		gmp_printf("C8[i] : %ZX\n",C8[i]);
	}
	
	
	
	getchar();
	
#endif	

#ifdef WITH_FMA	
	fma512_8_1038K(t512, q512, n, in512);
	

#ifdef DEBUG	
	
	
	
	
	
	printf("fcontract_8_512_1038K()\n");
	fcontract_8_512_1038K_res( t64, in512);
	
	//fcontract_8_512_1038K( t64, in512+NB_COEFF);
	fcontract_8_512_1038K( c64, n);
	
	fcontract_8_512_1038K( res64, q512);
	
	for(int i=0;i<8;i++){	
		mpz_import(A8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,c64[i]);
		mpz_import(B8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,res64[i]);
		mpz_import(C8[i],NB_COEFF64*2,-1,sizeof(c64[0][0]),0,0,t64[i]);
		gmp_printf("A8[i] : %ZX\n",A8[i]);
		gmp_printf("B8[i] : %ZX\n",B8[i]);
		gmp_printf("C8[i] : %ZX\n",C8[i]);
	}
		
	fcontract_8_512_1038K( a64, t512);
	
	fcontract_8_512_1038K( b64, t512+NB_COEFF);
	
	for(int i=0;i<8;i++){	
		mpz_mul(E8[i],A8[i],B8[i]);
		mpz_add(E8[i],E8[i],C8[i]);

		displayVect(a64[i],"t512lo[i]   ",NB_COEFF64);
		
		displayVect(b64[i],"t512hi[i]   ",NB_COEFF64);
		gmp_printf("E8[i] : %ZX\n",E8[i]);
	}
	
	
	
	getchar();//*/
	
#endif	
	__m512i maskSub = zero - (t512[39]>>35);
	__m512i carry = zero;
	
	__m512i sub = carry + (n[0]&maskSub);
	t512[20] = t512[20]-sub;
	carry = (t512[20]>>52)&1;
	
	for(int i=1;i<20;i++)
	{
		int ii = i+20;
		out[i-1] = _mm512_and_si512(mask52,t512[ii-1]);
		__m512i sub = carry + (n[i]&maskSub);
		t512[ii] = t512[ii]-sub;
		carry = (t512[ii]>>52)&1;
	}
	out[19] = _mm512_and_si512(mask36,t512[39]);//*/

#else	
	//displayVect512_NB_COEFF(t512,"t512_lo");
	
	//displayVect512_NB_COEFF(in512,"in512_lo");
	//displayVect512_NB_COEFF(t512+NB_COEFF,"t512_hi");
	
	//displayVect512_NB_COEFF(in512+NB_COEFF,"in512_hi");
	
	//getchar();
	/*t512[0] = t512[0]+in512[0];//_mm512_add_epi64(t512[0],in512[0]);
	__m512i carry  = _mm512_srli_epi64(t512[0],52);
	t512[0] = _mm512_and_si512(t512[0],mask52);
	
	displayVect512(t512,"t512[0]");//*/
	mul512_8_1038K(t512, q512, n);
	__m512i carry  = zero;
	
#ifdef DEBUG	
	
	
	
	
	
	printf("fcontract_8_512_1038K()\n");
	fcontract_8_512_1038K( a64, in512);
	
	fcontract_8_512_1038K( b64, n_prime);
	
	fcontract_8_512_1038K( c64, q512);
	
	for(int i=0;i<8;i++){	
		mpz_import(A8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,a64[i]);
		mpz_import(B8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,b64[i]);
		mpz_import(C8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,c64[i]);
		gmp_printf("A8[i] : %ZX\n",A8[i]);
		gmp_printf("B8[i] : %ZX\n",B8[i]);
		gmp_printf("C8[i] : %ZX\n",C8[i]);
	}
		
	fcontract_8_512_1038K( a64, t512);
	
	fcontract_8_512_1038K( b64, t512+NB_COEFF);
	
	for(int i=0;i<8;i++){	
		mpz_mul(E8[i],A8[i],B8[i]);
		mpz_add(E8[i],E8[i],C8[i]);

		displayVect(a64[i],"t512lo[i]   ",NB_COEFF64);
		
		displayVect(b64[i],"t512hi[i]   ",NB_COEFF64);
		gmp_printf("C8[i] : %ZX\n",C8[i]);
	}
	
	
	
	getchar();//*/
	
#endif	

	for(int i=0;i<4;i++)
	{
		for(int j=0;j<9;j++)
		{
			//t512[i] = _mm512_add_epi64(t512[i],carry);
			//t512[i] = _mm512_add_epi64(t512[i],in512[i]);
			
			t512[10*i+j] += carry+in512[10*i+j];
			carry  = _mm512_srli_epi64(t512[10*i+j],52);
			t512[10*i+j] = _mm512_and_si512(t512[10*i+j],mask52);
		}//*/

		t512[10*i+9] += carry+in512[10*i+9];
		carry  = _mm512_srli_epi64(t512[10*i+9],51);
		t512[10*i+9] = _mm512_and_si512(t512[10*i+9],mask51);


	}
	
	
	
	/*t512[39] = _mm512_add_epi64(t512[39],carry);
	t512[39] = _mm512_add_epi64(t512[39],in512[39]);
	//t512[0] = _mm512_and_si512(t512[0],mask52);//*/
	/*displayVect512_NB_COEFF(t512,"t512_lo");
	
	displayVect512_NB_COEFF(t512+NB_COEFF,"t512_hi");//*/

	for(int i=0;i<20;i++)
	{
		out[i] = t512[i+20];
	}//*/

	/*displayVect512_NB_COEFF(out,"out  ");

	getchar();//*/
	
	/*
	//final subtraction
	
	// à revoir
	__m512i maskSub = zero - (t512[39]>>52);
	//__m512i 
	carry = zero;
	
	for(int i=0;i<20;i++)
	{
		__m512i sub = carry + (n[i]&maskSub);
		int ii = i+20;
		t512[ii] = t512[ii]-sub;
		carry = (t512[ii]>>52)&1;
		out[i] = _mm512_and_si512(mask52,t512[ii]);
	}//*/
	
#endif	

#ifdef DEBUG	
		
	for(int i=0;i<8;i++){	
		mpz_clears (A8[i], B8[i], C8[i], E8[i], NULL);
	}
#endif	
	

}

#undef WITH_FMA




