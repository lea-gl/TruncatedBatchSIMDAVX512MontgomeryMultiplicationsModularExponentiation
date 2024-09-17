/* Schoolbook multiplication */

//#include "sb512_4158_opt.c"

#include "sb512_4158.c"
//#include "sb512_4158Cheng31052023.c"

static inline void redMont512_8_4158K(__m512i out[80], __m512i in512[160], __m512i n[80],  __m512i n_prime[80]);



__m512i mask36 = (__m512i){0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL};



//#define DEBUG


inline void force_inline mont_mul512_8_4158K(__m512i out[80], __m512i a512[80], __m512i b512[80], __m512i n[80],  __m512i n_prime[80])
{

	__m512i t512[160];
	/*displayVect512_NB_COEFF(a512,"mont_mul512_8_4158()\na512");
	
	displayVect512_NB_COEFF(b512,"b512");
	
	//displayVect512_NB_COEFF(n,"n512");
	
	//displayVect512_NB_COEFF(n_prime,"n_prime");//*/

	mul512_8_4158K(t512, a512, b512);
	/*displayVect512_NB_COEFF(t512,"t512_lo");
	
	displayVect512_NB_COEFF(t512+NB_COEFF,"t512_hi");
	
	//getchar();//*/
#ifdef DEBUG	
	
	mpz_t A8[8], B8[8], C8[8], E8[8];
	for(int i=0;i<8;i++)	
		mpz_inits (A8[i], B8[i], C8[i], E8[i], NULL);
		
	uint64_t a64[8][NB_COEFF64], b64[8][NB_COEFF64], c64[8][NB_COEFF64], res64[8][NB_COEFF64], t64[8][NB_COEFF64*2], res_gmp[NB_COEFF64];
	
	int flag=0, counter=0;
	size_t countp;
	
	printf("première multiplication : fcontract_8_512_4158K()\n");
	fcontract_8_512_4158K( a64, a512);
	
	fcontract_8_512_4158K( b64, b512);
	
	fcontract_8_512_4158K_res( t64, t512);
	
	for(int i=0;i<8;i++){	
		mpz_import(A8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,a64[i]);
		mpz_import(B8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,b64[i]);
		gmp_printf("A8[i] : %ZX\n",A8[i]);
		gmp_printf("B8[i] : %ZX\n",B8[i]);
	}
		
	for(int i=0;i<8;i++){	
		mpz_mul(C8[i],A8[i],B8[i]);
		//mpz_ui_pow_ui(E8[i],2,4158);
		//mpz_mod(C8[i],C8[i], E8[i] );
		
		//displayVect(t64[i],"t512[i]   ",NB_COEFF64*2);
		gmp_printf("première multiplication :\nC8[i] : %ZX\n",C8[i]);
		mpz_export(res_gmp, &countp, -1, sizeof(b64[0][0]) ,0,0, C8[i]);
		displayVect(res_gmp, "res_gmp     ",countp);//NB_COEFF64*2);
		displayVect(t64[i],"res64[i]    ",NB_COEFF64*2);
		for(int j=0; j<countp;j++)
			if(t64[i][j]^res_gmp[j])
			{
				flag++;
				printf("j=%d : t64[i][j]^res_gmp[j] = %16.16lX",j,t64[i][j]^res_gmp[j]);
			}
		flag?counter++,flag=0:counter,flag=0;//*/
		printf("\n");
	}
	
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;
	
	getchar();//*/
	
	
#endif

	redMont512_8_4158K(out, t512, n,  n_prime);
}





/* Schoolbook squaring */

inline void force_inline mont_square512_8_4158K(__m512i out[80], __m512i a512[80], __m512i n[80],  __m512i n_prime[80])
{
	
	__m512i t512[160];
	
	square512_8_4158K(t512, a512);
	
	
	redMont512_8_4158K(out, t512, n,  n_prime);

}









#define FINAL_SUB

static inline void redMont512_8_4158K(__m512i out[80], __m512i in512[160], __m512i n[80],  __m512i n_prime[80])
{
	__m512i q512[160], t512[160];
	
	
	mul512_8_4158K_modM(q512, in512, n_prime);
	//mul512_8_4158K(q512, in512, n_prime);


#ifdef DEBUG	
	
	mpz_t A8[8], B8[8], C8[8], E8[8];
	for(int i=0;i<8;i++)	
		mpz_inits (A8[i], B8[i], C8[i], E8[i], NULL);
		
	uint64_t a64[8][NB_COEFF64], b64[8][NB_COEFF64], c64[8][NB_COEFF64], res64[8][NB_COEFF64], t64[8][NB_COEFF64*2], res_gmp[NB_COEFF64];
	
	int flag=0, counter=0;
	size_t countp;
	
	printf("redMont512_8_4158()\n");
	
	displayVect512_NB_COEFF(n,"n512");
	
	displayVect512_NB_COEFF(n_prime,"n_prime");
	
	displayVect512_NB_COEFF(q512,"q512");
	
	
	
	
	printf("fcontract_8_512_4158K()\n");
	fcontract_8_512_4158K( a64, in512);
	
	fcontract_8_512_4158K( b64, n_prime);
	
	fcontract_8_512_4158K( c64, q512);
	
	for(int i=0;i<8;i++){	
		mpz_import(A8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,a64[i]);
		mpz_import(B8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,b64[i]);
		gmp_printf("A8[i] : %ZX\n",A8[i]);
		gmp_printf("B8[i] : %ZX\n",B8[i]);
	}
		
	for(int i=0;i<8;i++){	
		mpz_mul(C8[i],A8[i],B8[i]);
		mpz_tdiv_r_2exp(C8[i],C8[i],4158);
		
		displayVect(c64[i],"q512[i]   ",NB_COEFF64);
		gmp_printf("C8[i] : %ZX\n",C8[i]);
		mpz_export(res_gmp, &countp, -1, sizeof(b64[0][0]) ,0,0, C8[i]);
		displayVect(res_gmp, "res_gmp     ",countp);//NB_COEFF64*2);
		displayVect(c64[i],"res64[i]    ",NB_COEFF64);
		for(int j=0; j<countp;j++)
			if(c64[i][j]^res_gmp[j]) flag++;
			
			
		if(flag)
		{
			printf("xor = ");
			for(int j=0; j<NB_COEFF64;j++)
				printf("%16.16lX ",c64[i][NB_COEFF64-j-1]^res_gmp[NB_COEFF64-j-1]);
			printf("\n");
		
		
		}	
	
			
			
			
		flag?counter++,flag=0:counter,flag=0;//*/
		printf("\n");
	}
	
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;

	
	
	
	getchar();
	
#endif	


	//displayVect512_NB_COEFF(t512,"t512_lo");
	
	//displayVect512_NB_COEFF(in512,"in512_lo");
	//displayVect512_NB_COEFF(t512+NB_COEFF,"t512_hi");
	
	//displayVect512_NB_COEFF(in512+NB_COEFF,"in512_hi");
	
	//getchar();
	/*t512[0] = t512[0]+in512[0];//_mm512_add_epi64(t512[0],in512[0]);
	__m512i carry  = _mm512_srli_epi64(t512[0],52);
	t512[0] = _mm512_and_si512(t512[0],mask52);
	
	displayVect512(t512,"t512[0]");//*/
	mul512_8_4158K(t512, q512, n);
	
#ifdef DEBUG	
	
	
	
	
	
	printf("fcontract_8_512_4158K()\n");
	fcontract_8_512_4158K_res( t64, in512);
	
	fcontract_8_512_4158K( res64, q512);
	
	fcontract_8_512_4158K( c64, n);
	
	for(int i=0;i<8;i++){	
		mpz_import(A8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,c64[i]);
		mpz_import(B8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,res64[i]);
		mpz_import(C8[i],NB_COEFF64*2,-1,sizeof(c64[0][0]),0,0,t64[i]);
		gmp_printf("A8[i] : %ZX\n",A8[i]);
		gmp_printf("B8[i] : %ZX\n",B8[i]);
		gmp_printf("C8[i] : %ZX\n",C8[i]);
	}
		
	fcontract_8_512_4158K( a64, t512);
	
	fcontract_8_512_4158K( b64, t512+NB_COEFF);
	
	fcontract_8_512_4158K_res( t64, t512);
	
	for(int i=0;i<8;i++){	
		displayVect(t64[i],"t512lo[i]   ",NB_COEFF64*2);
		
		mpz_mul(C8[i],A8[i],B8[i]);
		//mpz_ui_pow_ui(E8[i],2,2078);
		//mpz_mod(C8[i],C8[i], E8[i] );
		
		//displayVect(t64[i],"t512[i]   ",NB_COEFF64*2);
		gmp_printf("C8[i] : %ZX\n",C8[i]);
		mpz_export(res_gmp, &countp, -1, sizeof(b64[0][0]) ,0,0, C8[i]);
		displayVect(res_gmp, "res_gmp     ",countp);//NB_COEFF64*2);
		displayVect(t64[i],"res64[i]    ",NB_COEFF64*2);
		for(int j=0; j<countp;j++)
			if(t64[i][j]^res_gmp[j]) flag++;
			
		if(flag)
		{
			printf("xor = ");
			for(int j=0; j<NB_COEFF64;j++)
				printf("%16.16lX ",res64[i][j]^res_gmp[j]);
			printf("\n");
		
		
		}	
	
			
		
		flag?counter++,flag=0:counter,flag=0;//*/
		printf("\n");
	}
	
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;

	
	
	getchar();//*/
	
#endif	

	__m512i carry  = zero;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<39;j++)
		{
			//t512[i] = _mm512_add_epi64(t512[i],carry);
			//t512[i] = _mm512_add_epi64(t512[i],in512[i]);
			
			t512[40*i+j] += carry+in512[40*i+j];
			carry  = _mm512_srli_epi64(t512[40*i+j],52);
			t512[40*i+j] = _mm512_and_si512(t512[40*i+j],mask52);
		}//*/

		t512[40*i+39] += carry+in512[40*i+39];
		carry  = _mm512_srli_epi64(t512[40*i+39],51);
		t512[40*i+39] = _mm512_and_si512(t512[40*i+39],mask51);


	}
	
	
#ifdef DEBUG	
	
	/*displayVect512_NB_COEFF(t512,"t512_lo");
	
	displayVect512_NB_COEFF(in512,"in512_lo");
	displayVect512_NB_COEFF(t512+NB_COEFF,"t512_hi");
	
	displayVect512_NB_COEFF(in512+NB_COEFF,"in512_hi");
	
	//getchar();
	t512[0] = t512[0]+in512[0];//_mm512_add_epi64(t512[0],in512[0]);
	__m512i carry  = _mm512_srli_epi64(t512[0],52);
	t512[0] = _mm512_and_si512(t512[0],mask52);
	
	displayVect512(t512,"t512[0]");//*/

	
	
	
	printf("fcontract_8_512_4158K()\n");
	fcontract_8_512_4158K_res( t64, in512);
	
	fcontract_8_512_4158K( b64, n);
	
	fcontract_8_512_4158K( c64, q512);
	
	for(int i=0;i<8;i++){	
		mpz_import(A8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,c64[i]);
		mpz_import(B8[i],NB_COEFF64,-1,sizeof(c64[0][0]),0,0,b64[i]);
		mpz_import(C8[i],NB_COEFF64*2,-1,sizeof(c64[0][0]),0,0,t64[i]);
		//gmp_printf("A8[i] : %ZX\n",A8[i]);
		//gmp_printf("B8[i] : %ZX\n",B8[i]);
		//gmp_printf("C8[i] : %ZX\n",C8[i]);
	}
		
	fcontract_8_512_4158K( a64, t512);
	
	fcontract_8_512_4158K( b64, t512+NB_COEFF);
	
	fcontract_8_512_4158K_res( t64, t512);
	
	for(int i=0;i<8;i++){	
		mpz_mul(E8[i],A8[i],B8[i]);
		mpz_add(C8[i],E8[i],C8[i]);

		displayVect(a64[i],"t512lo[i]   ",NB_COEFF64);
		
		displayVect(t64[i],"t512lo[i]   ",NB_COEFF64*2);
		
		//mpz_ui_pow_ui(E8[i],2,2078);
		//mpz_mod(C8[i],C8[i], E8[i] );
		
		//displayVect(t64[i],"t512[i]   ",NB_COEFF64*2);
		gmp_printf("C8[i] : %ZX\n",C8[i]);
		mpz_export(res_gmp, &countp, -1, sizeof(b64[0][0]) ,0,0, C8[i]);
		displayVect(res_gmp, "res_gmp     ",countp);//NB_COEFF64*2);
		displayVect(t64[i],"res64[i]    ",NB_COEFF64*2);
		for(int j=0; j<countp;j++)
			if(t64[i][j]^res_gmp[j]) flag++;
		if(flag)
		{
			printf("xor = ");
			for(int j=0; j<NB_COEFF64;j++)
				printf("%16.16lX ",t64[i][NB_COEFF64-j-1]^res_gmp[NB_COEFF64-j-1]);
			printf("\n");
		
		
		}	
		flag?counter++,flag=0:counter,flag=0;//*/
			
	
		printf("\n");
	}
	
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;

	
	
	
	
	getchar();//*/
	
#endif	
	
	
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
	
	
#ifdef FINAL_SUB
	//final subtraction
	
	// à revoir
	__m512i maskSub = zero - (t512[159]>>52);
	//__m512i 
	carry = zero;
	
	for(int i=0;i<80;i++)
	{
		__m512i sub = carry + (n[i]&maskSub);
		int ii = i+80;
		t512[ii] = t512[ii]-sub;
		carry = (t512[ii]>>52)&1;
		out[i] = _mm512_and_si512(mask52,t512[ii]);
	}
	
	
	
#else
	
	for(int i=0;i<80;i++)
	{
		int ii = i+80;
		out[i] = t512[ii];
	}
	
	
#endif	


#ifdef DEBUG	


	fcontract_8_512_4158K( b64, out);
	
	fcontract_8_512_4158K_res( t64, t512);
	
	for(int i=0;i<8;i++){	
	
		displayVect(b64[i],"t512hi[i]   ",NB_COEFF64);
		
		displayVect(t64[i],"t512lo[i]   ",NB_COEFF64*2);
		
		gmp_printf("(t+qn)      : %ZX\n",C8[i]);
		
		mpz_tdiv_q_2exp(C8[i],C8[i],4158);
		
		gmp_printf("(t+qn)/M[i] : %ZX\n",C8[i]);
	}
	
	
	getchar();
		
	for(int i=0;i<8;i++){	
		mpz_clears (A8[i], B8[i], C8[i], E8[i], NULL);
	}
#endif	
	

}




