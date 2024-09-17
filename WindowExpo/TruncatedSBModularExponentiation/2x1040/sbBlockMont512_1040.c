/* Schoolbook Block Montgomery multiplication */


#include "sb512_1040.c"


#include "truncated_fma512_1040.c"


//#define FINAL_SUB

static inline void redMont512_8_1040(__m512i out[20], __m512i in512[40], __m512i n[20],  __m512i n_prime[20]);





inline void force_inline mont_mul512_8_1040(__m512i out[20], __m512i a512[20], __m512i b512[20], __m512i n[20],  __m512i n_prime[20])
{

	__m512i t512[40];

	mul512_8_1040(t512, a512, b512);

	redMont512_8_1040(out, t512, n,  n_prime);
}





/* Schoolbook squaring */

inline void force_inline mont_square512_8_1040(__m512i out[20], __m512i a512[20], __m512i n[20],  __m512i n_prime[20])
{
	
	__m512i t512[40];
	
	square512_8_1040(t512, a512);
	
	
	redMont512_8_1040(out, t512, n,  n_prime);

}



static inline void redMont512_8_1040(__m512i out[20], __m512i in512[40], __m512i n[20],  __m512i n_prime[20])//with fma
{
	__m512i q512[20], t512[40];

	mul512_8_1040_modM(q512, in512, n_prime);

	//fma512_8_1040(t512, q512, n, in512);
	
	truncated_fma512_8_1040(t512, q512, n, in512);
	
#ifdef FINAL_SUB
	//final subtraction
	
	// à revoir
	__m512i maskSub = zero - (t512[39]>>52);
	__m512i carry = zero;
	
	for(int i=0;i<20;i++)
	{
		__m512i sub = carry + (n[i]&maskSub);
		int ii = i+20;
		t512[ii] = t512[ii]-sub;
		carry = (t512[ii]>>52)&1;
		out[i] = _mm512_and_si512(mask52,t512[ii]);
	}//*/
	
#else
	
	for(int i=0;i<20;i++)
	{
		int ii = i+20;
		out[i] = t512[ii];
	}
	
	
#endif	


	

}

