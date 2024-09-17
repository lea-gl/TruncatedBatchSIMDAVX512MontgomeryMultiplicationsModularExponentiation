/* Schoolbook multiplication */

#include "sb512_2078.c"

static inline void redMont512_8_2078K(__m512i out[40], __m512i in512[80], __m512i n[40],  __m512i n_prime[40]);



__m512i mask36 = (__m512i){0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL};


//#define DEBUG



inline void force_inline mont_mul512_8_2078K(__m512i out[40], __m512i a512[40], __m512i b512[40], __m512i n[40],  __m512i n_prime[40])
{

	__m512i t512[80];

	mul512_8_2078K(t512, a512, b512);
#ifdef DEBUG	
	
	mpz_t A8[8], B8[8], C8[8], E8[8];
	for(int i=0;i<8;i++)	
		mpz_inits (A8[i], B8[i], C8[i], E8[i], NULL);
		
	uint64_t a64[8][NB_COEFF64], b64[8][NB_COEFF64], c64[8][NB_COEFF64], res64[8][NB_COEFF64], t64[8][NB_COEFF64*2], res_gmp[NB_COEFF64];
	
	int flag=0, counter=0;
	size_t countp;
	
	printf("fcontract_8_512_2078K()\n");
	fcontract_8_512_2078K( a64, a512);
	
	fcontract_8_512_2078K( b64, b512);
	
	fcontract_8_512_2078K_res( t64, t512);
	
	for(int i=0;i<8;i++){	
		mpz_import(A8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,a64[i]);
		mpz_import(B8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,b64[i]);
		gmp_printf("A8[i] : %ZX\n",A8[i]);
		gmp_printf("B8[i] : %ZX\n",B8[i]);
	}
		
	for(int i=0;i<8;i++){	
		mpz_mul(C8[i],A8[i],B8[i]);

		gmp_printf("C8[i] : %ZX\n",C8[i]);
		mpz_export(res_gmp, &countp, -1, sizeof(b64[0][0]) ,0,0, C8[i]);
		displayVect(res_gmp, "res_gmp     ",countp);//NB_COEFF64*2);
		displayVect(t64[i],"res64[i]    ",NB_COEFF64*2);
		for(int j=0; j<countp;j++)
			if(t64[i][j]^res_gmp[j]) flag++;
		flag?counter++,flag=0:counter,flag=0;//*/
		printf("\n");
	}
	
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;
	
	getchar();//*/
	
	
#endif

	redMont512_8_2078K(out, t512, n,  n_prime);
}





/* Schoolbook squaring */

inline void force_inline mont_square512_8_2078K(__m512i out[40], __m512i a512[40], __m512i n[40],  __m512i n_prime[40])
{
	
	__m512i t512[80];
	
	square512_8_2078K(t512, a512);
	
	
	redMont512_8_2078K(out, t512, n,  n_prime);

}


//#define WITH_FMA

static inline void redMont512_8_2078K(__m512i out[40], __m512i in512[80], __m512i n[40],  __m512i n_prime[40])//with fma
{
	__m512i q512[40], t512[80];
	
	
	mul512_8_2078K_modM(q512, in512, n_prime);


#ifdef DEBUG	
	
	mpz_t A8[8], B8[8], C8[8], E8[8];
	for(int i=0;i<8;i++)	
		mpz_inits (A8[i], B8[i], C8[i], E8[i], NULL);
		
	uint64_t a64[8][NB_COEFF64], b64[8][NB_COEFF64], c64[8][NB_COEFF64], res64[8][NB_COEFF64], t64[8][NB_COEFF64*2], res_gmp[NB_COEFF64];
	
	int flag=0, counter=0;
	size_t countp;
	
	
	printf("redMont512_8_2078()\n");
	
	displayVect512_NB_COEFF(n,"n512");
	
	displayVect512_NB_COEFF(n_prime,"n_prime");
	
	displayVect512_NB_COEFF(q512,"q512");
	
	
	
	
	printf("fcontract_8_512_2078K()\n");
	fcontract_8_512_2078K( a64, in512);
	
	fcontract_8_512_2078K( b64, n_prime);
	
	fcontract_8_512_2078K( c64, q512);
	
	for(int i=0;i<8;i++){	
		mpz_import(A8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,a64[i]);
		mpz_import(B8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,b64[i]);
		gmp_printf("A8[i] : %ZX\n",A8[i]);
		gmp_printf("B8[i] : %ZX\n",B8[i]);
	}
		
	for(int i=0;i<8;i++){	
		mpz_mul(C8[i],A8[i],B8[i]);
		mpz_tdiv_r_2exp(C8[i],C8[i],2078);
		
		displayVect(c64[i],"q512[i]   ",NB_COEFF64);
		gmp_printf("C8[i] : %ZX\n",C8[i]);
		mpz_export(res_gmp, &countp, -1, sizeof(b64[0][0]) ,0,0, C8[i]);
		displayVect(res_gmp, "res_gmp     ",countp);//NB_COEFF64*2);
		displayVect(c64[i],"res64[i]    ",NB_COEFF64);
		for(int j=0; j<countp;j++)
			if(c64[i][j]^res_gmp[j]) flag++;
		flag?counter++,flag=0:counter,flag=0;//*/
		printf("\n");
	}
	
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;

	
	
	
	getchar();
	
#endif	

#ifdef WITH_FMA	
	fma512_8_2078K(t512, q512, n, in512);
	

#ifdef DEBUG	
	
	
	
	
	
	printf("fcontract_8_512_2078K()\n");
	fcontract_8_512_2078K_res( t64, in512);
	
	//fcontract_8_512_2078K( t64, in512+NB_COEFF);
	fcontract_8_512_2078K( c64, n);
	
	fcontract_8_512_2078K( res64, q512);
	
	for(int i=0;i<8;i++){	
		mpz_import(A8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,c64[i]);
		mpz_import(B8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,res64[i]);
		mpz_import(C8[i],NB_COEFF64*2,-1,sizeof(c64[0][0]),0,0,t64[i]);
		gmp_printf("A8[i] : %ZX\n",A8[i]);
		gmp_printf("B8[i] : %ZX\n",B8[i]);
		gmp_printf("C8[i] : %ZX\n",C8[i]);
	}
		
	fcontract_8_512_2078K( a64, t512);
	
	fcontract_8_512_2078K( b64, t512+NB_COEFF);
	
	fcontract_8_512_2078K_res( t64, t512);
	
	for(int i=0;i<8;i++){	
		mpz_mul(E8[i],A8[i],B8[i]);
		mpz_add(E8[i],E8[i],C8[i]);

		displayVect(a64[i],"t512lo[i]   ",NB_COEFF64);
		
		displayVect(b64[i],"t512hi[i]   ",NB_COEFF64);
		
		displayVect(t64[i],"t512lo[i]   ",NB_COEFF64*2);
		
		gmp_printf("E8[i] : %ZX\n",E8[i]);
	}
	
	
	
	getchar();//*/
	
#endif	
	__m512i maskSub = zero - (t512[79]>>35);
	__m512i carry = zero;
	
	__m512i sub = carry + (n[0]&maskSub);
	t512[40] = t512[40]-sub;
	carry = (t512[40]>>52)&1;
	
	for(int i=1;i<40;i++)
	{
		int ii = i+40;
		out[i-1] = _mm512_and_si512(mask52,t512[ii-1]);
		__m512i sub = carry + (n[i]&maskSub);
		t512[ii] = t512[ii]-sub;
		carry = (t512[ii]>>52)&1;
	}
	out[39] = _mm512_and_si512(mask36,t512[79]);//*/





























#else	
	mul512_8_2078K(t512, q512, n);
	__m512i carry  = zero;
	
#ifdef DEBUG	
	
	displayVect512_NB_COEFF(t512,"t512_lo");
	
	displayVect512_NB_COEFF(in512,"in512_lo");

	
	
	
	printf("fcontract_8_512_2078K()\n");
	fcontract_8_512_2078K_res( t64, in512);
	
	//fcontract_8_512_2078K( t64, in512+NB_COEFF);
	fcontract_8_512_2078K( c64, n);
	
	fcontract_8_512_2078K( res64, q512);
	
	for(int i=0;i<8;i++){	
		mpz_import(A8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,c64[i]);
		mpz_import(B8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,res64[i]);
		mpz_import(C8[i],NB_COEFF64*2,-1,sizeof(c64[0][0]),0,0,t64[i]);
		gmp_printf("A8[i] : %ZX\n",A8[i]);
		gmp_printf("B8[i] : %ZX\n",B8[i]);
		gmp_printf("C8[i] : %ZX\n",C8[i]);
	}
		
	fcontract_8_512_2078K( a64, t512);
	
	fcontract_8_512_2078K( b64, t512+NB_COEFF);
	
	fcontract_8_512_2078K_res( t64, t512);
	
	for(int i=0;i<8;i++){	
		displayVect(t64[i],"t512lo[i]   ",NB_COEFF64*2);
		
		mpz_mul(C8[i],A8[i],B8[i]);

		gmp_printf("C8[i] : %ZX\n",C8[i]);
		mpz_export(res_gmp, &countp, -1, sizeof(b64[0][0]) ,0,0, C8[i]);
		displayVect(res_gmp, "res_gmp     ",countp);//NB_COEFF64*2);
		displayVect(t64[i],"res64[i]    ",NB_COEFF64*2);
		for(int j=0; j<countp;j++)
			if(t64[i][j]^res_gmp[j]) flag++;
		flag?counter++,flag=0:counter,flag=0;//*/
		printf("\n");
	}
	
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;

	
	
	
	
	getchar();//*/
	
#endif	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<19;j++)
		{
			
			t512[20*i+j] += carry+in512[20*i+j];
			carry  = _mm512_srli_epi64(t512[20*i+j],52);
			t512[20*i+j] = _mm512_and_si512(t512[20*i+j],mask52);
		}//*/

		t512[20*i+19] += carry+in512[20*i+19];
		carry  = _mm512_srli_epi64(t512[20*i+19],51);
		t512[20*i+19] = _mm512_and_si512(t512[20*i+19],mask51);


	}
	
#ifdef DEBUG	
	
	
	
	printf("fcontract_8_512_2078K()\n");
	fcontract_8_512_2078K_res( t64, in512);
	
	fcontract_8_512_2078K( b64, n);
	
	fcontract_8_512_2078K( c64, q512);
	
	for(int i=0;i<8;i++){	
		mpz_import(A8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,c64[i]);
		mpz_import(B8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,b64[i]);
		mpz_import(C8[i],NB_COEFF64*2,-1,sizeof(c64[0][0]),0,0,t64[i]);
		gmp_printf("A8[i] : %ZX\n",A8[i]);
		gmp_printf("B8[i] : %ZX\n",B8[i]);
		gmp_printf("C8[i] : %ZX\n",C8[i]);
	}
		
	fcontract_8_512_2078K( a64, t512);
	
	fcontract_8_512_2078K( b64, t512+NB_COEFF);
	
	fcontract_8_512_2078K_res( t64, t512);
	
	for(int i=0;i<8;i++){	
		mpz_mul(E8[i],A8[i],B8[i]);
		mpz_add(C8[i],E8[i],C8[i]);

		displayVect(a64[i],"t512lo[i]   ",NB_COEFF64);
		
		displayVect(b64[i],"t512hi[i]   ",NB_COEFF64);
		
		displayVect(t64[i],"t512lo[i]   ",NB_COEFF64*2);
		
		gmp_printf("C8[i] : %ZX\n",C8[i]);
	}
	
	for(int i=0;i<8;i++){	
		displayVect(t64[i],"t512lo[i]   ",NB_COEFF64*2);
		
		gmp_printf("C8[i] : %ZX\n",C8[i]);
		mpz_export(res_gmp, &countp, -1, sizeof(b64[0][0]) ,0,0, C8[i]);
		displayVect(res_gmp, "res_gmp     ",countp);//NB_COEFF64*2);
		displayVect(t64[i],"res64[i]    ",NB_COEFF64*2);
		for(int j=0; j<countp;j++)
			if(t64[i][j]^res_gmp[j]) flag++;
		flag?counter++,flag=0:counter,flag=0;//*/
		printf("\n");
	}
	
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;

	
	
	
	
	getchar();//*/
	
#endif	
	

	for(int i=0;i<40;i++)
	{
		out[i] = t512[i+40];
	}//*/

	
#endif	

#ifdef DEBUG	


	fcontract_8_512_2078K( b64, out);
	
	fcontract_8_512_2078K_res( t64, t512);
	
	for(int i=0;i<8;i++){	
	
		displayVect(b64[i],"t512hi[i]   ",NB_COEFF64);
		
		displayVect(t64[i],"t512lo[i]   ",NB_COEFF64*2);
		
		gmp_printf("(t+qn)      : %ZX\n",C8[i]);
		
		mpz_tdiv_q_2exp(C8[i],C8[i],2078);
		
		gmp_printf("(t+qn)/M[i] : %ZX\n",C8[i]);
	}
	
	
	getchar();
	
	
	for(int i=0;i<8;i++){	
		mpz_clears (A8[i], B8[i], C8[i], E8[i], NULL);
	}
#endif	
	

}

#undef WITH_FMA




