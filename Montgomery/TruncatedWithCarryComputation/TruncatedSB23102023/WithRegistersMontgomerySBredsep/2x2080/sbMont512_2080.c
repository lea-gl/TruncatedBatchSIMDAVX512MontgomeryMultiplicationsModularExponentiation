/* Schoolbook multiplication */

#include "sb512_2080.c"

static inline void redMont512_8_2080(__m512i out[40], __m512i in512[80], __m512i n[40],  __m512i n_prime[40]);


inline void force_inline mont_mul512_8_2080(__m512i out[40], __m512i a512[40], __m512i b512[40], __m512i n[40],  __m512i n_prime[40])
{

	__m512i t512[80];
	/*displayVect512_NB_COEFF(a512,"mont_mul512_8_2080()\na512");
	
	displayVect512_NB_COEFF(b512,"b512");
	
	//displayVect512_NB_COEFF(n,"n512");
	
	//displayVect512_NB_COEFF(n_prime,"n_prime");//*/

	mul512_8_2080(t512, a512, b512);
	/*displayVect512_NB_COEFF(t512,"t512_lo");
	
	displayVect512_NB_COEFF(t512+NB_COEFF,"t512_hi");
	
	//getchar();//*/

	redMont512_8_2080(out, t512, n,  n_prime);
}







/* Schoolbook squaring */

inline void force_inline mont_square512_8_2080(__m512i out[40], __m512i a512[40], __m512i n[40],  __m512i n_prime[40])
{
	__m512i t512[80];
	
	square512_8_2080(t512, a512);
	

	redMont512_8_2080(out, t512, n,  n_prime);
	
}







static inline void redMont512_8_2080(__m512i out[40], __m512i in512[80], __m512i n[40],  __m512i n_prime[40])
{
	__m512i q512[40], t512[80];
	//printf("redMont512_8_2080()\n");
	
	//displayVect512_NB_COEFF(n,"n512");
	
	//displayVect512_NB_COEFF(n_prime,"n_prime");
	mul512_8_2080_modM(q512, in512, n_prime);
	
	//displayVect512_NB_COEFF(q512,"q512");
	
	//fma512_8_2080(t512, q512, n, in512);
	
	
	fma512_8_2080_truncated(t512, q512, n, in512);
	/*displayVect512_NB_COEFF(t512,"t512_lo");
	
	displayVect512_NB_COEFF(in512,"in512_lo");
	displayVect512_NB_COEFF(t512+NB_COEFF,"t512_hi");
	
	displayVect512_NB_COEFF(in512+NB_COEFF,"in512_hi");
	
	//getchar();
	/*t512[0] = t512[0]+in512[0];//_mm512_add_epi64(t512[0],in512[0]);
	__m512i carry  = _mm512_srli_epi64(t512[0],52);
	t512[0] = _mm512_and_si512(t512[0],mask52);
	
	displayVect512(t512,"t512[0]");//*/
	/*__m512i carry  = zero;
	
	for(int i=0;i<80;i++)
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

	for(int i=0;i<40;i++)
	{
		out[i] = t512[i+40];
	}//*/

	/*displayVect512_NB_COEFF(out,"out  ");

	getchar();//*/
	
	
	/*	
	//final subtraction
	
	
	__m512i maskSub = zero - (t512[79]>>52);
	__m512i carry = zero;
	
	for(int i=0;i<40;i++)
	{
		__m512i sub = carry + (n[i]&maskSub);
		int ii = i+40;
		t512[ii] = t512[ii]-sub;
		carry = (t512[ii]>>52)&1;
		out[i] = _mm512_and_si512(mask52,t512[ii]);
	}//*/


}






