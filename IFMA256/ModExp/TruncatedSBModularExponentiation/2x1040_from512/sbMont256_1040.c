/* Schoolbook multiplication */

#include "sb256_1040.c"

static inline void redMont256_4_1040(__m256i out[20], __m256i in256[40], __m256i n[20],  __m256i n_prime[20]);





inline void force_inline mont_mul256_4_1040(__m256i out[20], __m256i a256[20], __m256i b256[20], __m256i n[20],  __m256i n_prime[20])
{

	__m256i t256[40];
	/*afficheVect256_NB_COEFF(a256,"mont_mul256_4_1040()\na256");
	
	afficheVect256_NB_COEFF(b256,"b256");
	
	//afficheVect256_NB_COEFF(n,"n256");
	
	//afficheVect256_NB_COEFF(n_prime,"n_prime");//*/

	mul256_4_1040(t256, a256, b256);
	/*afficheVect256_NB_COEFF(t256,"t256_lo");
	
	afficheVect256_NB_COEFF(t256+NB_COEFF,"t256_hi");
	
	//getchar();//*/

	redMont256_4_1040(out, t256, n,  n_prime);
}





/* Schoolbook squaring */

inline void force_inline mont_square256_4_1040(__m256i out[20], __m256i a256[20], __m256i n[20],  __m256i n_prime[20])
{
	
	__m256i t256[40];
	
	square256_4_1040(t256, a256);
	
	
	redMont256_4_1040(out, t256, n,  n_prime);

}


#define WITH_FMA

//#define TRUNCATED

static inline void redMont256_4_1040(__m256i out[20], __m256i in256[40], __m256i n[20],  __m256i n_prime[20])//with fma
{
	__m256i q256[20], t256[40];
	//printf("redMont256_4_1040()\n");
	
	//afficheVect256_NB_COEFF(n,"n256");
	
	//afficheVect256_NB_COEFF(n_prime,"n_prime");
	mul256_4_1040_modM(q256, in256, n_prime);
	
	//afficheVect256_NB_COEFF(q256,"q256");

#ifdef WITH_FMA	


#ifdef TRUNCATED
	fma256_4_1040_truncated(t256, q256, n, in256);
	/*afficheVect256_NB_COEFF(t256,"t256lo");
	afficheVect256_NB_COEFF(t256+20,"t256hi");//*/


#else
	fma256_4_1040(t256, q256, n, in256);
	/*afficheVect256_NB_COEFF(t256,"t256lo");	
	afficheVect256_NB_COEFF(t256+20,"t256hi");

	getchar();//*/

#endif

	
	/*__m256i maskSub = zero - (t256[39]>>52);
	__m256i 
	carry = zero;
	
	for(int i=0;i<20;i++)
	{
		__m256i sub = carry + (n[i]&maskSub);
		int ii = i+20;
		t256[ii] = t256[ii]-sub;
		carry = (t256[ii]>>52)&1;
		out[i] = _mm256_and_si256(mask52,t256[ii]);
	}//*/

	/*
	
	//Final subtraction
	__m256i maskSub = zero - (t256[39]>>36);
	__m256i carry = zero;
	
	__m256i sub = carry + (n[0]&maskSub);
	t256[20] = t256[20]-sub;
	carry = (t256[20]>>52)&1;
	
	for(int i=1;i<20;i++)
	{
		int ii = i+20;
		out[i-1] = _mm256_and_si256(mask52,t256[ii-1]);
		__m256i sub = carry + (n[i]&maskSub);
		t256[ii] = t256[ii]-sub;
		carry = (t256[ii]>>52)&1;
	}
	out[19] = _mm256_and_si256(mask36,t256[39]);//*/
	
	for(int i=0;i<20;i++)
	{
		out[i] = t256[i+20];
	}//*/

	

#else	
	//afficheVect256_NB_COEFF(t256,"t256_lo");
	
	//afficheVect256_NB_COEFF(in256,"in256_lo");
	//afficheVect256_NB_COEFF(t256+NB_COEFF,"t256_hi");
	
	//afficheVect256_NB_COEFF(in256+NB_COEFF,"in256_hi");
	
	//getchar();
	/*t256[0] = t256[0]+in256[0];//_mm256_add_epi64(t256[0],in256[0]);
	__m256i carry  = _mm256_srli_epi64(t256[0],52);
	t256[0] = _mm256_and_si256(t256[0],mask52);
	
	afficheVect256(t256,"t256[0]");//*/
	mul256_4_1040(t256, q256, n);
	__m256i carry  = zero;
	
	for(int i=0;i<40;i++)
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

	/*for(int i=0;i<20;i++)
	{
		out[i] = t256[i+20];
	}//*/

	/*afficheVect256_NB_COEFF(out,"out  ");

	getchar();//*/
	
	
	//final subtraction
	
	// à revoir
	__m256i maskSub = zero - (t256[39]>>52);
	//__m256i 
	carry = zero;
	
	for(int i=0;i<20;i++)
	{
		__m256i sub = carry + (n[i]&maskSub);
		int ii = i+20;
		t256[ii] = t256[ii]-sub;
		carry = (t256[ii]>>52)&1;
		out[i] = _mm256_and_si256(mask52,t256[ii]);
	}//*/
	
#endif	
		
	

}

#undef WITH_FMA




