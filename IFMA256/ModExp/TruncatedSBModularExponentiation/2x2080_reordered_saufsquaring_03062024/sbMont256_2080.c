/* Schoolbook multiplication */


#define TRUNCATED

/*#ifndef TRUNCATED

#include "sb256_2080.c"

#else

#include "sb256_2080_truncated.c"

#endif*/

#include "sb256_2080.c"

static inline void redMont256_4_2080(__m256i out[40], __m256i in256[80], __m256i n[40],  __m256i n_prime[40]);


inline void force_inline mont_mul256_4_2080(__m256i out[40], __m256i a256[40], __m256i b256[40], __m256i n[40],  __m256i n_prime[40])
{

	__m256i t256[80];
	/*afficheVect256_NB_COEFF(a256,"mont_mul256_4_2080()\na256");
	
	afficheVect256_NB_COEFF(b256,"b256");
	
	//afficheVect256_NB_COEFF(n,"n256");
	
	//afficheVect256_NB_COEFF(n_prime,"n_prime");//*/

	mul256_4_2080(t256, a256, b256);
	/*afficheVect256_NB_COEFF(t256,"t256_lo");
	
	afficheVect256_NB_COEFF(t256+NB_COEFF,"t256_hi");
	
	//getchar();//*/

	redMont256_4_2080(out, t256, n,  n_prime);
}







/* Schoolbook squaring */

inline void force_inline mont_square256_4_2080(__m256i out[40], __m256i a256[40], __m256i n[40],  __m256i n_prime[40])
{
	__m256i t256[80];
	
	square256_4_2080(t256, a256);
	

	redMont256_4_2080(out, t256, n,  n_prime);
	
}







static inline void redMont256_4_2080(__m256i out[40], __m256i in256[80], __m256i n[40],  __m256i n_prime[40])
{
	__m256i q256[40], t256[80];
	//printf("redMont256_4_2080()\n");
	
	//afficheVect256_NB_COEFF(n,"n256");
	
	//afficheVect256_NB_COEFF(n_prime,"n_prime");
	mul256_4_2080_modM(q256, in256, n_prime);
	
	//afficheVect256_NB_COEFF(q256,"q256");
	

#ifndef TRUNCATED
	fma256_4_2080(t256, q256, n, in256);
	
#else	
	fma256_4_2080_truncated(t256, q256, n, in256);
#endif
	/*afficheVect256_NB_COEFF(t256,"t256_lo");
	
	afficheVect256_NB_COEFF(in256,"in256_lo");
	afficheVect256_NB_COEFF(t256+NB_COEFF,"t256_hi");
	
	afficheVect256_NB_COEFF(in256+NB_COEFF,"in256_hi");
	
	//getchar();
	/*t256[0] = t256[0]+in256[0];//_mm256_add_epi64(t256[0],in256[0]);
	__m256i carry  = _mm256_srli_epi64(t256[0],52);
	t256[0] = _mm256_and_si256(t256[0],mask52);
	
	afficheVect256(t256,"t256[0]");//*/
	/*__m256i carry  = zero;
	
	for(int i=0;i<80;i++)
	{
		//t256[i] = _mm256_add_epi64(t256[i],carry);
		//t256[i] = _mm256_add_epi64(t256[i],in256[i]);
		
		t256[i] += carry+in256[i];
		carry  = _mm256_srli_epi64(t256[i],52);
		t256[i] = _mm256_and_si256(t256[i],mask52);
	}//*/

	/*t256[39] = _mm256_add_epi64(t256[39],carry);
	t256[39] = _mm256_add_epi64(t256[39],in256[39]);
	//t256[0] = _mm256_and_si256(t256[0],mask52);//*/
	/*afficheVect256_NB_COEFF(t256,"t256_lo");
	
	afficheVect256_NB_COEFF(t256+NB_COEFF,"t256_hi");//*/

	for(int i=0;i<40;i++)
	{
		out[i] = t256[i+40];
	}//*/

	/*afficheVect256_NB_COEFF(out,"out  ");

	getchar();//*/
	
	
		
	//final subtraction
	
	
	/*__m256i maskSub = zero - (t256[79]>>52);
	__m256i carry = zero;
	
	for(int i=0;i<40;i++)
	{
		__m256i sub = carry + (n[i]&maskSub);
		int ii = i+40;
		t256[ii] = t256[ii]-sub;
		carry = (t256[ii]>>52)&1;
		out[i] = _mm256_and_si256(mask52,t256[ii]);
	}//*/


}






