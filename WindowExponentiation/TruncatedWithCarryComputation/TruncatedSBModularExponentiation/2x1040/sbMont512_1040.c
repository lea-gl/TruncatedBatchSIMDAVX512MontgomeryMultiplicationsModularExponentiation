/* Schoolbook multiplication */

#include "sb512_1040.c"

static inline void redMont512_8_1040(__m512i out[20], __m512i in512[40], __m512i n[20],  __m512i n_prime[20]);





inline void force_inline mont_mul512_8_1040(__m512i out[20], __m512i a512[20], __m512i b512[20], __m512i n[20],  __m512i n_prime[20])
{

	__m512i t512[40];
	/*displayVect512_NB_COEFF(a512,"mont_mul512_8_1040()\na512");
	
	displayVect512_NB_COEFF(b512,"b512");
	
	//displayVect512_NB_COEFF(n,"n512");
	
	//displayVect512_NB_COEFF(n_prime,"n_prime");//*/

	mul512_8_1040(t512, a512, b512);
	/*displayVect512_NB_COEFF(t512,"t512_lo");
	
	displayVect512_NB_COEFF(t512+NB_COEFF,"t512_hi");
	
	//getchar();//*/

	redMont512_8_1040(out, t512, n,  n_prime);
}





/* Schoolbook squaring */

inline void force_inline mont_square512_8_1040(__m512i out[20], __m512i a512[20], __m512i n[20],  __m512i n_prime[20])
{
	
	__m512i t512[40];
	
	square512_8_1040(t512, a512);
	
	
	redMont512_8_1040(out, t512, n,  n_prime);

}


#define WITH_FMA


static inline void redMont512_8_1040(__m512i out[20], __m512i in512[40], __m512i n[20],  __m512i n_prime[20])//with fma
{
	__m512i q512[20], t512[40];
	//printf("redMont512_8_1040()\n");
	
	//displayVect512_NB_COEFF(n,"n512");
	
	//displayVect512_NB_COEFF(n_prime,"n_prime");
	mul512_8_1040_modM(q512, in512, n_prime);
	
	//displayVect512_NB_COEFF(q512,"q512");

#ifdef WITH_FMA	

	fma512_8_1040_truncated(t512, q512, n, in512);
	/*displayVect512_NB_COEFF(t512,"t512lo");
	displayVect512_NB_COEFF(t512+20,"t512hi");

	fma512_8_1040(t512, q512, n, in512);
	displayVect512_NB_COEFF(t512,"t512lo");	
	displayVect512_NB_COEFF(t512+20,"t512hi");

	getchar();//*/

	
	/*__m512i maskSub = zero - (t512[39]>>52);
	__m512i 
	carry = zero;
	
	for(int i=0;i<20;i++)
	{
		__m512i sub = carry + (n[i]&maskSub);
		int ii = i+20;
		t512[ii] = t512[ii]-sub;
		carry = (t512[ii]>>52)&1;
		out[i] = _mm512_and_si512(mask52,t512[ii]);
	}//*/

	/*
	
	//Final subtraction
	__m512i maskSub = zero - (t512[39]>>36);
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
	
	for(int i=0;i<20;i++)
	{
		out[i] = t512[i+20];
	}//*/

	

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
	mul512_8_1040(t512, q512, n);
	__m512i carry  = zero;
	
	for(int i=0;i<40;i++)
	{
		//t512[i] = _mm512_add_epi64(t512[i],carry);
		//t512[i] = _mm512_add_epi64(t512[i],in512[i]);
		
		t512[i] += carry+in512[i];
		carry  = _mm512_srli_epi64(t512[i],52);
		t512[i] = _mm512_and_si512(t512[i],mask52);
	}//*/

	/*t512[39] = _mm512_add_epi64(t512[39],carry);
	t512[39] = _mm512_add_epi64(t512[39],in512[39]);
	//t512[0] = _mm512_and_si512(t512[0],mask52);//*/
	/*displayVect512_NB_COEFF(t512,"t512_lo");
	
	displayVect512_NB_COEFF(t512+NB_COEFF,"t512_hi");//*/

	/*for(int i=0;i<20;i++)
	{
		out[i] = t512[i+20];
	}//*/

	/*displayVect512_NB_COEFF(out,"out  ");

	getchar();//*/
	
	
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
		
	

}

#undef WITH_FMA




