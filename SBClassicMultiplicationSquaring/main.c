#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <gmp.h>
#include <openssl/bn.h>

#include "ccount.h"
#include "tests.c"


#include "fonctions.h"

#define BILLION 1000000000L


#define NSAMPLES 50

#define NTEST 1000
//~ Compilation command : gcc -Wall -O3 main.c -o main -lgmp -lcrypto
//~ Execution command : ./main

//~ Important : polynomials representations form is P(X) = a0 + ... + an.X^n = (a0, ..., an).


int main(void){

	//int nbiter;
	mpz_t A, B, C, E, UPB;// UPB is used as upper bound
	mpz_inits (A, B, C, E, UPB, NULL);

	BN_CTX *ctx = BN_CTX_new();
	BN_CTX_start(ctx);

	BIGNUM *opA = BN_CTX_get(ctx);
	BIGNUM *opB = BN_CTX_get(ctx);
	BIGNUM *opP = BN_CTX_get(ctx);
	BIGNUM *opAA = BN_CTX_get(ctx);
	BIGNUM *opBB = BN_CTX_get(ctx);
	BN_MONT_CTX *mont_ctx = BN_MONT_CTX_new();


	int64_t pa[NB_COEFF];
	int64_t pb[NB_COEFF];
	
	int64_t pc[NB_COEFF];
	
	int64_t pa_x[NB_COEFF];
	int64_t pb_x[NB_COEFF];
	
	int64_t pc_x[NB_COEFF];
	
	
	uint64_t res[NB_COEFF]={0};
	uint64_t res_gmp[NB_COEFF*2]={0};
	
	size_t countp;
	int flag=0, counter=0;
 
	uint64_t mini, mini1, mini2, mini3, mini4, mini5;
 	unsigned long long int timer=0, timer1=0, timer2=0, timer3=0, timer4=0, timer5=0;
	

	unsigned long long int start1, end1;
	unsigned long long int start2, end2;
	unsigned long long int start3, end3;
	unsigned long long int start4, end4;
	unsigned long long int start5, end5;

	unsigned long seed = time(NULL);
	gmp_randstate_t r;
	gmp_randinit_default(r);
	gmp_randseed_ui(r, seed);


	mpz_ui_pow_ui ( UPB, 2UL, SIZE );
	
	
	
	printf("%lu %d %d\n\n", mpz_sizeinbase (UPB, 2), NB_COEFF, NB_COEFF64);
	gmp_printf("UPB  : 0x%ZX\n\n\n", UPB);


	mpz_t A8[8], B8[8], C8[8], E8[8];
	for(int i=0;i<8;i++)	
		mpz_inits (A8[i], B8[i], C8[i], E8[i], NULL);
	uint64_t a64[8][NB_COEFF], b64[8][NB_COEFF], c64[8][NB_COEFF], res64[8][NB_COEFF*2];
		
	// a512 and b512 contain 8 values stored in columns	
	__m512i a512[NB_COEFF], b512[NB_COEFF], res512[NB_COEFF*2];

#ifndef BENCHMARK


	printf("\t  /*******************************/\n");
	printf("\t /   Test on 1 dataset   /\n");
	printf("\t/*******************************/\n\n");


		
		//*/
		mpz_urandomm(A, r, UPB);
		mpz_urandomm(B, r, UPB);

		
		gmp_printf("A  : 0x%ZX\n\n\n", A);
		gmp_printf("B  : 0x%ZX\n\n\n", B);

		mpz_mul (C, A, B);
		gmp_printf("C  : 0x%ZX\n\n\n", C);
		gmp_printf("C  : 0x%ZX\n\n\n", C);
		
		mpz_export(res_gmp, &countp, -1, sizeof(res_gmp[0]) ,0,0, C);
		displayVect(res_gmp,"res_gmp",NB_COEFF);


		mpz_export(pa, &countp, -1, sizeof(pa[0]) ,0,0, A);
		mpz_export(pb, &countp, -1, sizeof(pa[0]) ,0,0, B);
		displayVect(pa,"pa     ",NB_COEFF);
		displayVect(pb,"pb     ",NB_COEFF);
		
		fexpand(pa_x,pa);
				
		displayVect(pa_x,"pa_x   ",NB_COEFF);
		displayVect(pb_x,"pb_x   ",NB_COEFF);


		displayVect(res,"res    ",NB_COEFF);
		displayVect(res_gmp,"res_gmp",NB_COEFF);

	printf("\nMultiplication\n");
	
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<NB_COEFF;j++){
			a64[i][j] = 0x0UL;
			b64[i][j] = 0x0UL;
		}
	
		countp = 0;
		while(countp!=NB_COEFF64)
		{
			mpz_urandomm(A8[i], r, UPB);
			mpz_export(a64[i], &countp, -1, sizeof(a64[0][0]) ,0,0, A8[i]);
		}
		
		countp = 0;
		while(countp!=NB_COEFF64)
		{
			mpz_urandomm(B8[i], r, UPB);
			mpz_export(b64[i], &countp, -1, sizeof(b64[0][0]) ,0,0, B8[i]);
		}
	}

	fexpand_8_512_52( a512, a64);

	fexpand_8_512_52( b512, b64);

	fcontract_8_512_52( c64, a512);
	

	for(int i=0;i<8;i++)
		displayVect(a64[i],"a64[i]     ",NB_COEFF);
	for(int i=0;i<8;i++)
		displayVect(c64[i],"c64[i]     ",NB_COEFF);//*/
	
	
	mul512_8_SIZE(res512, a512, b512);
	
	displayVect512_NB_COEFF(res512,"res512_lo");
	
	displayVect512_NB_COEFF(res512+NB_COEFF,"res512_hi");
	
	fcontract_8_512_52_res(res64, res512);
	
	for(int i=0;i<8;i++)
	{
		mpz_mul(C,A8[i],B8[i]);
		mpz_export(res_gmp, &countp, -1, sizeof(b64[0][0]) ,0,0, C);
		displayVect(res_gmp, "res_gmp     ",NB_COEFF64*2);
		displayVect(res64[i],"res64[i]    ",NB_COEFF64*2);
		for(int j=0; j<NB_COEFF64*2;j++)
			if(res64[i][j]^res_gmp[j]) flag++;
		flag?counter++,flag=0:counter,flag=0;


	}
	
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;
	
	printf("\nSquaring\n");
	
	square512_8_SIZE(res512, a512);
	
	fcontract_8_512_52_res(res64, res512);
	for(int i=0;i<8;i++)
	{
		mpz_mul(C,A8[i],A8[i]);
		mpz_export(res_gmp, &countp, -1, sizeof(b64[0][0]) ,0,0, C);
		displayVect(res_gmp, "res_gmp     ",NB_COEFF64*2);
		displayVect(res64[i],"res64[i]    ",NB_COEFF64*2);
		for(int j=0; j<NB_COEFF64*2;j++)
			if(res64[i][j]^res_gmp[j]) flag++;
		flag?counter++,flag=0:counter,flag=0;


	}
	
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;
	


	printf("\t  /***********************************/\n");
	printf("\t /   Test on 1000 datasets   /\n");
	printf("\t/***********************************/\n\n");

	
	printf("\nMultiplication\n");
	
	flag=0, counter=0;
	
	for(int i=0;i<NTEST;i++)
	{
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<NB_COEFF64;j++){
				a64[i][j] = 0x0UL;
				b64[i][j] = 0x0UL;
			}
			countp = 0;
			while(countp!=NB_COEFF64){
				mpz_urandomm(A8[i], r, UPB);
				mpz_export(a64[i], &countp, -1, sizeof(a64[0][0]) ,0,0, A8[i]);
			}

			countp = 0;
			while(countp!=NB_COEFF64){
				mpz_urandomm(B8[i], r, UPB);
				mpz_export(b64[i], &countp, -1, sizeof(b64[0][0]) ,0,0, B8[i]);
			}
		}

		fexpand_8_512_52( a512, a64);

		fexpand_8_512_52( b512, b64);

		
		mul512_8_SIZE(res512, a512, b512);

		
		fcontract_8_512_52_res(res64, res512);
		
		for(int i=0;i<8;i++)
		{
			mpz_mul(C,A8[i],B8[i]);
			mpz_export(res_gmp, &countp, -1, sizeof(b64[0][0]) ,0,0, C);
			
			
			for(int j=0; j<countp;j++)
				if(res64[i][j]^res_gmp[j]) flag++;
			if( (countp == NB_COEFF*2-1) && (res64[i][countp])) flag++;
			
			if(flag){
				printf("C, countp = %ld\n",countp);
				mpz_export(pa, &countp, -1, sizeof(b64[0][0]) ,0,0, A8[i]);
				printf("A8[i], countp = %ld\n",countp);
				mpz_export(pb, &countp, -1, sizeof(b64[0][0]) ,0,0, B8[i]);
				printf("B8[i], countp = %ld\n",countp);
				
				displayVect(pa,"A8[i]     ",NB_COEFF);
			
				displayVect(pb,"B8[i]     ",NB_COEFF);
				
				displayVect512_NB_COEFF(a512,"a512");
				displayVect(a64[i],"a64[i]     ",NB_COEFF);
				displayVect512_NB_COEFF(b512,"b512");
				displayVect(b64[i],"b64[i]     ",NB_COEFF);
				
				displayVect512_NB_COEFFx2(res512,"res512_lo");
				
				printf("i = %d\n",i);
				displayVect(res_gmp, "res_gmp     ",NB_COEFF*2);
				displayVect(res64[i],"res64[i]    ",NB_COEFF*2);
				
				printf("i-1 = %d\n",i-1);
				mpz_mul(C,A8[i-1],B8[i-1]);
				mpz_export(res_gmp, &countp, -1, sizeof(b64[0][0]) ,0,0, C);
				displayVect(res_gmp, "res_gmp     ",NB_COEFF*2);
				displayVect(res64[i-1],"res64[i-1]  ",NB_COEFF*2);
				
				
				getchar();
			}//*/
			flag?counter++,flag=0:counter,flag=0;


		}
	}
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;


	
	printf("\nSquaring\n");
	
	flag=0, counter=0;
	
	for(int i=0;i<NTEST;i++)
	{
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<NB_COEFF64;j++){
				a64[i][j] = 0x0UL;
			}
			countp = 0;
			while(countp!=NB_COEFF64){
				mpz_urandomm(A8[i], r, UPB);
				mpz_export(a64[i], &countp, -1, sizeof(a64[0][0]) ,0,0, A8[i]);
			}
		}

		fexpand_8_512_52( a512, a64);


		fcontract_8_512_52( c64, a512);
		

		
		square512_8_SIZE(res512, a512);
		
		
		fcontract_8_512_52_res(res64, res512);
		
		for(int i=0;i<8;i++)
		{
			mpz_mul(C,A8[i],A8[i]);
			mpz_export(res_gmp, &countp, -1, sizeof(b64[0][0]) ,0,0, C);
			
			
			for(int j=0; j<countp;j++)
				if(res64[i][j]^res_gmp[j]) flag++;
			if( (countp == NB_COEFF*2-1) && (res64[i][countp])) flag++;
			
			if(flag){
				printf("C, countp = %ld\n",countp);
				mpz_export(pa, &countp, -1, sizeof(b64[0][0]) ,0,0, A8[i]);
				printf("A8[i], countp = %ld\n",countp);
				mpz_export(pb, &countp, -1, sizeof(b64[0][0]) ,0,0, B8[i]);
				printf("B8[i], countp = %ld\n",countp);
				
				displayVect(pa,"A8[i]     ",NB_COEFF);
			
			
				displayVect512_NB_COEFF(a512,"a512");
				displayVect(a64[i],"a64[i]     ",NB_COEFF);
				displayVect512_NB_COEFF(b512,"b512");
				
				displayVect512_NB_COEFFx2(res512,"res512_lo");
				
				printf("i = %d\n",i);
				displayVect(res_gmp, "res_gmp     ",NB_COEFF*2);
				displayVect(res64[i],"res64[i]    ",NB_COEFF*2);
				
				printf("i-1 = %d\n",i-1);
				mpz_mul(C,A8[i-1],B8[i-1]);
				mpz_export(res_gmp, &countp, -1, sizeof(b64[0][0]) ,0,0, C);
				displayVect(res_gmp, "res_gmp     ",NB_COEFF*2);
				displayVect(res64[i-1],"res64[i-1]  ",NB_COEFF*2);
				
				
				getchar();
			}//*/
			flag?counter++,flag=0:counter,flag=0;


		}
	}
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;

	
#endif

#ifndef TEST


	/********************
	//Timing !!!!!!!!!!!!!
	*********************/
	printf("\t  /***************************/\n");
	printf("\t / Timing !!!!!!!!!!!!/\n");
	printf("\t/***************************/\n\n");
	
	printf("\ngmp, BN, BN_MONT, mul512_8_SIZE and square512_8_SIZE\n");
	printf("-----------------------------------------------------\n");

	
	for(int k=0; k<NSAMPLES;k++){
	
		mini = (uint64_t)-1L;
		mini1 = (uint64_t)-1L;
		mini2 = (uint64_t)-1L;
		mini3 = (uint64_t)-1L; 
		mini4 = (uint64_t)-1L;
		mini5 = (uint64_t)-1L;
		
		
		
		BN_dec2bn(&opA, mpz_get_str (NULL, 10, A));
		BN_dec2bn(&opB, mpz_get_str (NULL, 10, B));
		BN_dec2bn(&opP, mpz_get_str (NULL, 10, UPB));
		BN_copy(opAA, opA);
		BN_copy(opBB, opB);
		BN_MONT_CTX_set(mont_ctx, opP, ctx);

		for(int i=0;i<8;i++)
		{
			mpz_urandomm(A8[i], r, UPB);
			mpz_export(a64[i], &countp, -1, sizeof(a64[0][0]) ,0,0, A8[i]);
			
			mpz_urandomm(B8[i], r, UPB);
			mpz_export(b64[i], &countp, -1, sizeof(b64[0][0]) ,0,0, B8[i]);
		}

		fexpand_8_512_52( a512, a64);

		fexpand_8_512_52( b512, b64);
		
		fexpand(pa_x,pa);
		fexpand(pb_x,pb);
		
		for(int i=0;i<NTEST;i++)
		{
			mul512_8_SIZE(res512, a512, b512);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			STAMP(start3)
			mul512_8_SIZE(res512, a512, b512);
			mul512_8_SIZE(res512, a512, b512);
			mul512_8_SIZE(res512, a512, b512);
			mul512_8_SIZE(res512, a512, b512);
			mul512_8_SIZE(res512, a512, b512);
			mul512_8_SIZE(res512, a512, b512);
			mul512_8_SIZE(res512, a512, b512);
			mul512_8_SIZE(res512, a512, b512);
			mul512_8_SIZE(res512, a512, b512);
			mul512_8_SIZE(res512, a512, b512);
			STAMPP(end3)
			
			if(mini2>end3-start3) mini2 = end3-start3;
			
		}
		
		
		for(int i=0;i<NTEST;i++)
		{
			mpz_mul (C, A8[0], B8[0]);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start1)
			mpz_mul (C, A8[0], B8[0]);
			mpz_mul (C, A8[1], B8[1]);
			mpz_mul (C, A8[2], B8[2]);
			mpz_mul (C, A8[3], B8[3]);
			mpz_mul (C, A8[4], B8[4]);
			mpz_mul (C, A8[5], B8[5]);
			mpz_mul (C, A8[6], B8[6]);
			mpz_mul (C, A8[7], B8[7]);
			STAMPP(end1)
			
			if(mini>end1-start1) mini = end1-start1;
			
		}



		for(int i=0;i<NTEST;i++)
		{
			
			mpn_mul_n(pc, a64[0], b64[0], NB_COEFF);
			
		}
		
		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start3)
			mpn_mul_n(pc, a64[0], b64[0], NB_COEFF64);
			mpn_mul_n(pc, a64[1], b64[1], NB_COEFF64);
			mpn_mul_n(pc, a64[2], b64[2], NB_COEFF64);
			mpn_mul_n(pc, a64[3], b64[3], NB_COEFF64);
			mpn_mul_n(pc, a64[4], b64[4], NB_COEFF64);
			mpn_mul_n(pc, a64[5], b64[5], NB_COEFF64);
			mpn_mul_n(pc, a64[6], b64[6], NB_COEFF64);
			mpn_mul_n(pc, a64[7], b64[7], NB_COEFF64);
			STAMPP(end3)
			
			if(mini1>end3-start3) mini1 = end3-start3;
			
		}

		
		
		
	for(int i=0;i<NTEST;i++)
		{
			mpn_sqr(pc, a64[0], NB_COEFF64);
		}

		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start4)
			mpn_sqr(pc, a64[0], NB_COEFF64);
			mpn_sqr(pc, a64[0], NB_COEFF64);
			mpn_sqr(pc, a64[0], NB_COEFF64);
			mpn_sqr(pc, a64[0], NB_COEFF64);
			mpn_sqr(pc, a64[0], NB_COEFF64);
			mpn_sqr(pc, a64[0], NB_COEFF64);
			mpn_sqr(pc, a64[0], NB_COEFF64);
			mpn_sqr(pc, a64[0], NB_COEFF64);
			STAMPP(end4)

			if(mini3>end4-start4) mini3 = end4-start4;
			
		}
		
		
		
		for(int i=0;i<NTEST;i++)
		{
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
		}
		
			
		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start5)
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
			STAMPP(end5)
			
			if(mini4>end5-start5) mini4 = end5-start5;
			
		}
		

		for(int i=0;i<NTEST;i++)
		{
			square512_8_SIZE(res512, a512);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			STAMP(start3)
			square512_8_SIZE(res512, a512);
			square512_8_SIZE(res512, a512);
			square512_8_SIZE(res512, a512);
			square512_8_SIZE(res512, a512);
			square512_8_SIZE(res512, a512);
			square512_8_SIZE(res512, a512);
			square512_8_SIZE(res512, a512);
			square512_8_SIZE(res512, a512);
			square512_8_SIZE(res512, a512);
			square512_8_SIZE(res512, a512);
			STAMPP(end3)
			
			if(mini5>end3-start3) mini5 = end3-start3;
		}
	
		
		timer += mini;

		timer1 += mini1;
		
		timer2 += mini2;
		
		timer3 += mini3;

		timer4 += mini4;
		
		timer5 += mini5;
		
	}
	
	printf("timer gmp (x8)             : %llu\n",timer/NSAMPLES);	
	
	printf("timer gmp mpn_mul_n (x8)   : %llu\n",timer1/NSAMPLES);
	
	printf("timer gmp mpn_sqr (x8)     : %llu\n",timer3/NSAMPLES);

	printf("timer mul512_8_SIZE        : %llu\n",timer2/(NSAMPLES*10));

	printf("timer square512_8_SIZE     : %llu\n",timer5/(NSAMPLES*10));

	printf("timer BN_mod_mul_mont (x8) : %llu\n",timer4/NSAMPLES);

	
	
		
	timer=0, timer1=0, timer2=0, timer3=0, timer4=0;
	
	
	for(int k=0; k<NSAMPLES;k++){
	
		mini = (uint64_t)-1L,
		mini1 = (uint64_t)-1L,
		mini2 = (uint64_t)-1L,
		mini3 = (uint64_t)-1L, 
		mini4 = (uint64_t)-1L ;
		
		mpz_urandomm(A, r, UPB);
		mpz_urandomm(B, r, UPB);

		

		for(int i=0;i<8;i++)
		{
			mpz_urandomm(A8[i], r, UPB);
			mpz_export(a64[i], &countp, -1, sizeof(a64[0][0]) ,0,0, A8[i]);
			
			mpz_urandomm(B8[i], r, UPB);
			mpz_export(b64[i], &countp, -1, sizeof(b64[0][0]) ,0,0, B8[i]);
		}


		fexpand_8_512_52( b512, b64);


		
		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start1)
			fexpand_8_512_52( a512, a64);
			fexpand_8_512_52( a512, a64);
			fexpand_8_512_52( a512, a64);
			fexpand_8_512_52( a512, a64);
			fexpand_8_512_52( a512, a64);
			fexpand_8_512_52( a512, a64);
			fexpand_8_512_52( a512, a64);
			fexpand_8_512_52( a512, a64);
			fexpand_8_512_52( a512, a64);
			fexpand_8_512_52( a512, a64);
			STAMPP(end1)
			
			if(mini>end1-start1) mini = end1-start1;
			
		}




		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start4)
			fcontract_8_512_52_res(res64, res512);
			fcontract_8_512_52_res(res64, res512);
			fcontract_8_512_52_res(res64, res512);
			fcontract_8_512_52_res(res64, res512);
			fcontract_8_512_52_res(res64, res512);
			fcontract_8_512_52_res(res64, res512);
			fcontract_8_512_52_res(res64, res512);
			fcontract_8_512_52_res(res64, res512);
			fcontract_8_512_52_res(res64, res512);
			fcontract_8_512_52_res(res64, res512);
			STAMPP(end4)

			if(mini3>end4-start4) mini3 = end4-start4;
			
		}

		

		timer += mini;

		timer1 += mini1;
		
		timer2 += mini2;
		
		timer3 += mini3;

		timer4 += mini4;
		
	}
	
	printf("\nautres fonction p25519 :\n");
	
	printf("------------------------\n");
	
	printf("timer fexpand_8_512_52       : %llu\n",timer/NSAMPLES/10);	
	
	printf("timer fcontract_8_512_52_res : %llu\n",timer3/NSAMPLES/10);





	/********************
	//Instructions !!!!!!!!!!!!!
	*********************/
	printf("\n\n\t  /***************************/\n");
	printf("\t / Instructions !!!!!!!!!!!!!/\n");
	printf("\t/***************************/\n\n");
	
	printf("\ngmp, BN, BN_MONT, amns_origin vs  amns\n");
	printf("-------------------------\n");

		
	timer=0, timer1=0, timer2=0, timer3=0, timer4=0;
	
	for(int k=0; k<NSAMPLES;k++){
	
		mini = (uint64_t)-1L;
		mini1 = (uint64_t)-1L;
		mini2 = (uint64_t)-1L;
		mini3 = (uint64_t)-1L; 
		mini4 = (uint64_t)-1L;
		mini5 = (uint64_t)-1L; 
		
		
		BN_dec2bn(&opA, mpz_get_str (NULL, 10, A));
		BN_dec2bn(&opB, mpz_get_str (NULL, 10, B));
		BN_dec2bn(&opP, mpz_get_str (NULL, 10, UPB));
		BN_copy(opAA, opA);
		BN_copy(opBB, opB);
		BN_MONT_CTX_set(mont_ctx, opP, ctx);

		for(int i=0;i<8;i++)
		{
			mpz_urandomm(A8[i], r, UPB);
			mpz_export(a64[i], &countp, -1, sizeof(a64[0][0]) ,0,0, A8[i]);
			
			mpz_urandomm(B8[i], r, UPB);
			mpz_export(b64[i], &countp, -1, sizeof(b64[0][0]) ,0,0, B8[i]);
		}

		fexpand_8_512_52( a512, a64);

		fexpand_8_512_52( b512, b64);
		
		

		for(int i=0;i<NTEST;i++)
		{
			mpz_mul (C, A8[0], B8[0]);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			
			start1 = rdpmc_instructions();//4)
			mpz_mul (C, A8[0], B8[0]);
			mpz_mul (C, A8[1], B8[1]);
			mpz_mul (C, A8[2], B8[2]);
			mpz_mul (C, A8[3], B8[3]);
			mpz_mul (C, A8[4], B8[4]);
			mpz_mul (C, A8[5], B8[5]);
			mpz_mul (C, A8[6], B8[6]);
			mpz_mul (C, A8[7], B8[7]);
			end1 = rdpmc_instructions();//4)
			
			if(mini>end1-start1) mini = end1-start1;
			
		}



		for(int i=0;i<NTEST;i++)
		{
			
			mpn_mul_n(pc, a64[0], b64[0], NB_COEFF);
			
		}
		
		for(int i=0;i<NTEST;i++)
		{
			
			start3 = rdpmc_instructions();//4)
			mpn_mul_n(pc, a64[0], b64[0], NB_COEFF64);
			mpn_mul_n(pc, a64[1], b64[1], NB_COEFF64);
			mpn_mul_n(pc, a64[2], b64[2], NB_COEFF64);
			mpn_mul_n(pc, a64[3], b64[3], NB_COEFF64);
			mpn_mul_n(pc, a64[4], b64[4], NB_COEFF64);
			mpn_mul_n(pc, a64[5], b64[5], NB_COEFF64);
			mpn_mul_n(pc, a64[6], b64[6], NB_COEFF64);
			mpn_mul_n(pc, a64[7], b64[7], NB_COEFF64);
			end3 = rdpmc_instructions();//4)
			
			if(mini1>end3-start3) mini1 = end3-start3;
			
		}

		
		
		for(int i=0;i<NTEST;i++)
		{
			mpn_sqr(pc, a64[0], NB_COEFF64);
		}

		for(int i=0;i<NTEST;i++)
		{
			
			start4 = rdpmc_instructions();//4)
			mpn_sqr(pc, a64[0], NB_COEFF64);
			mpn_sqr(pc, a64[0], NB_COEFF64);
			mpn_sqr(pc, a64[0], NB_COEFF64);
			mpn_sqr(pc, a64[0], NB_COEFF64);
			mpn_sqr(pc, a64[0], NB_COEFF64);
			mpn_sqr(pc, a64[0], NB_COEFF64);
			mpn_sqr(pc, a64[0], NB_COEFF64);
			mpn_sqr(pc, a64[0], NB_COEFF64);
			end4 = rdpmc_instructions();//4)

			if(mini3>end4-start4) mini3 = end4-start4;
			
		}
		
		for(int i=0;i<NTEST;i++)
		{
			mul512_8_SIZE(res512, a512, b512);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			start3 = rdpmc_instructions();//3)
			mul512_8_SIZE(res512, a512, b512);
			mul512_8_SIZE(res512, a512, b512);
			mul512_8_SIZE(res512, a512, b512);
			mul512_8_SIZE(res512, a512, b512);
			mul512_8_SIZE(res512, a512, b512);
			mul512_8_SIZE(res512, a512, b512);
			mul512_8_SIZE(res512, a512, b512);
			mul512_8_SIZE(res512, a512, b512);
			mul512_8_SIZE(res512, a512, b512);
			mul512_8_SIZE(res512, a512, b512);
			end3 = rdpmc_instructions();//3)
			
			if(mini2>end3-start3) mini2 = end3-start3;
			
		}	
		for(int i=0;i<NTEST;i++)
		{
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
		}
		
			
		for(int i=0;i<NTEST;i++)
		{
			
			start5 = rdpmc_instructions();//5)
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
			end5 = rdpmc_instructions();//5)
			
			if(mini4>end5-start5) mini4 = end5-start5;
			
		}
		

		for(int i=0;i<NTEST;i++)
		{
			square512_8_SIZE(res512, a512);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			start3 = rdpmc_instructions();//5)
			square512_8_SIZE(res512, a512);
			square512_8_SIZE(res512, a512);
			square512_8_SIZE(res512, a512);
			square512_8_SIZE(res512, a512);
			square512_8_SIZE(res512, a512);
			square512_8_SIZE(res512, a512);
			square512_8_SIZE(res512, a512);
			square512_8_SIZE(res512, a512);
			square512_8_SIZE(res512, a512);
			square512_8_SIZE(res512, a512);
			end3 = rdpmc_instructions();//5)
			
			if(mini5>end3-start3) mini5 = end3-start3;
		}

		timer += mini;

		timer1 += mini1;
		
		timer2 += mini2;
		
		timer3 += mini3;

		timer4 += mini4;
		
		timer5 += mini5;
	}

	
	printf("gmp (x8)             : %llu\n",timer/NSAMPLES);	
	
	printf("gmp mpn_mul_n (x8)   : %llu\n",timer1/NSAMPLES);
	
	printf("gmp mpn_sqr (x8)     : %llu\n",timer3/NSAMPLES);

	printf("mul512_8_SIZE        : %llu\n",timer2/(NSAMPLES*10));

	printf("square512_8_SIZE     : %llu\n",timer5/(NSAMPLES*10));

	printf("BN_mod_mul_mont (x8) : %llu\n",timer4/NSAMPLES);
	
	
	
		
	timer=0, timer1=0, timer2=0, timer3=0, timer4=0;
	
	
	for(int k=0; k<NSAMPLES;k++){
	
		mini = (uint64_t)-1L,
		mini1 = (uint64_t)-1L,
		mini2 = (uint64_t)-1L,
		mini3 = (uint64_t)-1L, 
		mini4 = (uint64_t)-1L ;
		
		mpz_urandomm(A, r, UPB);
		mpz_urandomm(B, r, UPB);
		


		for(int i=0;i<8;i++)
		{
			mpz_urandomm(A8[i], r, UPB);
			mpz_export(a64[i], &countp, -1, sizeof(a64[0][0]) ,0,0, A8[i]);
			
			mpz_urandomm(B8[i], r, UPB);
			mpz_export(b64[i], &countp, -1, sizeof(b64[0][0]) ,0,0, B8[i]);
		}


		fexpand_8_512_52( b512, b64);


		
		for(int i=0;i<NTEST;i++)
		{
			
			start1 = rdpmc_instructions();//1)
			fexpand_8_512_52( a512, a64);
			fexpand_8_512_52( a512, a64);
			fexpand_8_512_52( a512, a64);
			fexpand_8_512_52( a512, a64);
			fexpand_8_512_52( a512, a64);
			fexpand_8_512_52( a512, a64);
			fexpand_8_512_52( a512, a64);
			fexpand_8_512_52( a512, a64);
			fexpand_8_512_52( a512, a64);
			fexpand_8_512_52( a512, a64);
			end1 = rdpmc_instructions();//1)
			
			if(mini>end1-start1) mini = end1-start1;
			
		}





		for(int i=0;i<NTEST;i++)
		{
			
			start4 = rdpmc_instructions();//4)
			fcontract_8_512_52_res(res64, res512);
			fcontract_8_512_52_res(res64, res512);
			fcontract_8_512_52_res(res64, res512);
			fcontract_8_512_52_res(res64, res512);
			fcontract_8_512_52_res(res64, res512);
			fcontract_8_512_52_res(res64, res512);
			fcontract_8_512_52_res(res64, res512);
			fcontract_8_512_52_res(res64, res512);
			fcontract_8_512_52_res(res64, res512);
			fcontract_8_512_52_res(res64, res512);
			end4 = rdpmc_instructions();//4)

			if(mini3>end4-start4) mini3 = end4-start4;
			
		}
			
		


		timer += mini;

		timer1 += mini1;
		
		timer2 += mini2;
		
		timer3 += mini3;

		timer4 += mini4;
		
	}
	
	printf("\nautres fonction p25519 :\n");
	
	printf("------------------------\n");
	
	printf("fexpand_8_512_52       : %llu\n",timer/(NSAMPLES*10));	
	
	printf("fcontract_8_512_52_res : %llu\n",timer3/(NSAMPLES*10));


#endif















end:	
	
	printf("\nAu revoir and merci !\n");	

	mpz_clears (A, B, C, E, UPB, NULL);
	gmp_randclear(r);

	BN_MONT_CTX_free(mont_ctx);
	BN_CTX_end(ctx);
	BN_CTX_free(ctx);

	return 0;
}

