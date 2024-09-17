#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <gmp.h>
#include <openssl/bn.h>

#include "init.c"

#include "tests.c"


#include "ccount.h"
#include "fonctions.h"

#define BILLION 1000000000L


#define NSAMPLES 50

#define NTEST 1000
//~ Compilation command : gcc -Wall -O3 main.c -o main -lgmp -lcrypto
//~ Execution command : ./main

//~ Important : polynomials representations form is P(X) = a0 + ... + an.X^n = (a0, ..., an).




int main(void){

	//int nbiter;
	mpz_t A, B, C, E;
	mpz_inits (A, B, C, E, NULL);

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
	uint64_t res_gmp[NB_COEFF]={0};
	
	size_t countp;
	int flag=0, counter=0;
 
	uint64_t mini, mini1, mini2, mini3, mini4;
 	unsigned long long int timer=0, timer1=0, timer2=0, timer3=0, timer4=0;
	

	unsigned long long int start1, end1;
	unsigned long long int start2, end2;
	unsigned long long int start3, end3;
	unsigned long long int start4, end4;
	unsigned long long int start5, end5;

	unsigned long seed = time(NULL);
	gmp_randstate_t r;
	gmp_randinit_default(r);
	gmp_randseed_ui(r, seed);


	init_data();
	
	
	printf("%lu %d \n\n", mpz_sizeinbase (modul_p, 2), NB_COEFF);
	gmp_printf("modul_p  : 0x%ZX\n\n\n", modul_p);




	
	printf("\t  /*******************************/\n");
	printf("\t /   Test on 1 dataset   /\n");
	printf("\t/*******************************/\n\n");

	

		mpz_urandomm(A, r, modul_p);
		mpz_urandomm(B, r, modul_p);

		//mpz_set(E, A);
		//mpz_import(A, NB_COEFF, -1, sizeof(res_gmp[0]) ,0,0, pa);
		//mpz_import(B, NB_COEFF, -1, sizeof(res_gmp[0]) ,0,0, pb);
		
//A  : 0x8049423FD39C53E5716F050966EEF2853571269C6F3FA09EB887FA432404BD21A21C601EF7F63FBFF0A4585A01B9E5EFEACE538612B980E210A987640A34CDCD
//B  : 0x1CABB2A63DC5C5EE3293253E915A6416E079B415DD13ED08091E6249CAB0ADE7BB7A93332EB8132FA5CF1180B79DD3DDD8C1545C3F48DC76A5C0C604353A9D16
		//mpz_set_str(A,"8049423FD39C53E5716F050966EEF2853571269C6F3FA09EB887FA432404BD21A21C601EF7F63FBFF0A4585A01B9E5EFEACE538612B980E210A987640A34CDCD",16);
		//mpz_set_str(B,"1CABB2A63DC5C5EE3293253E915A6416E079B415DD13ED08091E6249CAB0ADE7BB7A93332EB8132FA5CF1180B79DD3DDD8C1545C3F48DC76A5C0C604353A9D16",16);
		
		
//A  : 0x2A71B9732FF87B2B52FDE0B1677A2C1E17D69BA3BD112533BF7DF6F2E6D50DDDFAA76BB42308927A540710A8E99BD7F79E2CDD607C6D8DE629DB7DE99D38FAA9
//B  : 0x2FF840F228B9DD042D4293752B389B16FC2DA9452477361149CDB308E7E3EEA3DABABCE990390610B722C12DAE6F1763DCA1816CCE2A931DEA13D0AF732FEF0D
		//mpz_set_str(A,"2A71B9732FF87B2B52FDE0B1677A2C1E17D69BA3BD112533BF7DF6F2E6D50DDDFAA76BB42308927A540710A8E99BD7F79E2CDD607C6D8DE629DB7DE99D38FAA9",16);
		//mpz_set_str(B,"2FF840F228B9DD042D4293752B389B16FC2DA9452477361149CDB308E7E3EEA3DABABCE990390610B722C12DAE6F1763DCA1816CCE2A931DEA13D0AF732FEF0D",16);
		
		
		gmp_printf("A  : 0x%ZX\n\n\n", A);
		gmp_printf("B  : 0x%ZX\n\n\n", B);

		mpz_mul (C, A, B);
		mpz_mod (C, C, modul_p);
		
		mpz_export(res_gmp, &countp, -1, sizeof(res_gmp[0]) ,0,0, C);


		mpz_export(pa, &countp, -1, sizeof(pa[0]) ,0,0, A);
		mpz_export(pb, &countp, -1, sizeof(pa[0]) ,0,0, B);
		displayVect(pa,"pa     ",NB_COEFF);
		
		fexpand(pa_x,pa);

		fcontract(pa,pa_x);
		displayVect(pa,"pa     ",NB_COEFF);
		
		displayVect(pb,"pb     ",NB_COEFF);
		fexpand(pb_x,pb);
		fcontract(pb,pb_x);
		
		displayVect(pb,"pb     ",NB_COEFF);

		displayVect(pa_x,"pa_x   ",NB_COEFF);
		displayVect(pb_x,"pb_x   ",NB_COEFF);
				

		multMod(res, pa_x, pb_x);
		displayVect(res,"res    ",NB_COEFF);
		
		fcontract(res,res);
		mpz_export(res, &countp, -1, sizeof(res[0]) ,0,0, E);
		

		displayVect(res,"res    ",NB_COEFF);
		displayVect(res_gmp,"res_gmp",NB_COEFF);


	printf("\t  /***********************************/\n");
	printf("\t /   Test on 1000 datasets   /\n");
	printf("\t/***********************************/\n\n");

	

	
	for(int i=0;i<NTEST;i++)
	{
		mpz_urandomm(A, r, modul_p);
		mpz_urandomm(B, r, modul_p);

		mpz_mul (C, A, B);
		mpz_mod (C, C, modul_p);
		
		mpz_export(res_gmp, &countp, -1, sizeof(res_gmp[0]) ,0,0, C);

		mpz_export(pa, &countp, -1, sizeof(pa[0]) ,0,0, A);
		mpz_export(pb, &countp, -1, sizeof(pa[0]) ,0,0, B);
		fexpand(pa_x,pa);
		fexpand(pb_x,pb);
		multMod(res, pa_x, pb_x);
		
		fcontract(res,res);
		mpz_export(res, &countp, -1, sizeof(res[0]) ,0,0, E);
		

		for(int j=0; j<6;j++)
			if(res[j]^res_gmp[j]) flag++;
		flag?counter++,flag=0:counter,flag=0;
		
	}
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;

	

	
	/********************
	//Timing !!!!!!!!!!!!!
	*********************/
	printf("\t  /***************************/\n");
	printf("\t / Timing !!!!!!!!!!!!/\n");
	printf("\t/***************************/\n\n");
	
	printf("\ngmp, BN, BN_MONT, amns_origin vs  amns\n");
	printf("-------------------------\n");

	
	for(int k=0; k<NSAMPLES;k++){
	
		mini = (uint64_t)-1L,
		mini1 = (uint64_t)-1L,
		mini2 = (uint64_t)-1L,
		mini3 = (uint64_t)-1L, 
		mini4 = (uint64_t)-1L ;
		
		mpz_urandomm(A, r, modul_p);
		mpz_urandomm(B, r, modul_p);
		
		for(int i=0;i<NTEST;i++)
		{
			mpz_mul (A, A, B);
			mpz_mod (A, A, modul_p);
			mpz_export(pa, &countp, -1, sizeof(pa[0]) ,0,0, A);
			mpz_export(pb, &countp, -1, sizeof(pa[0]) ,0,0, B);
			fexpand(pa_x,pa);
			fexpand(pb_x,pb);
			multMod(res, pa_x, pb_x);
			
			fcontract(res,res);
			mpz_export(res, &countp, -1, sizeof(res[0]) ,0,0, E);
			
			
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
		}
		
		BN_dec2bn(&opA, mpz_get_str (NULL, 10, A));
		BN_dec2bn(&opB, mpz_get_str (NULL, 10, B));
		BN_dec2bn(&opP, mpz_get_str (NULL, 10, modul_p));
		BN_copy(opAA, opA);
		BN_copy(opBB, opB);
		BN_MONT_CTX_set(mont_ctx, opP, ctx);


		
		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start1)
			mpz_mul (A, A, B);
			mpz_mod (A, A, modul_p);
			STAMPP(end1)
			
			if(mini>end1-start1) mini = end1-start1;
			
		}

			
		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start3)
			multMod(pa_x, pb_x, res);
			STAMPP(end3)
			
			if(mini2>end3-start3) mini2 = end3-start3;
			
		}


		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start4)
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			STAMPP(end4)

			if(mini3>end4-start4) mini3 = end4-start4;
			
		}
			
		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start5)
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
			STAMPP(end5)
			
			if(mini4>end5-start5) mini4 = end5-start5;
			
		}
		

		timer += mini;

		timer1 += mini1;
		
		timer2 += mini2;
		
		timer3 += mini3;

		timer4 += mini4;
		
	}
	
	printf("timer gmp                   : %llu\n",timer/NSAMPLES);	
	

	printf("timer mul25519              : %llu\n",timer2/NSAMPLES);
	
	printf("timer BN_mod_mul            : %llu\n",timer3/NSAMPLES);

	printf("timer BN_mod_mul_montgomery : %llu\n",timer4/NSAMPLES);
	
	
	
	timer=0, timer1=0, timer2=0, timer3=0, timer4=0;
	
	
	for(int k=0; k<NSAMPLES;k++){
	
		mini = (uint64_t)-1L,
		mini1 = (uint64_t)-1L,
		mini2 = (uint64_t)-1L,
		mini3 = (uint64_t)-1L, 
		mini4 = (uint64_t)-1L ;
		
		mpz_urandomm(A, r, modul_p);
		mpz_urandomm(B, r, modul_p);
		
		for(int i=0;i<NTEST;i++)
		{
			mpz_mul (A, A, B);
			mpz_mod (A, A, modul_p);
			mpz_export(pa, &countp, -1, sizeof(pa[0]) ,0,0, A);
			mpz_export(pb, &countp, -1, sizeof(pa[0]) ,0,0, B);
			fexpand(pa_x,pa);
			fexpand(pb_x,pb);
			multMod(res, pa_x, pb_x);
			squaringMod(res, pa_x);
			
			fcontract(res,res);
			mpz_export(res, &countp, -1, sizeof(res[0]) ,0,0, E);
			
			
		}
		


		
		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start1)
			fexpand(pa_x,pa);
			STAMPP(end1)
			
			if(mini>end1-start1) mini = end1-start1;
			
		}


		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start2)
			squaringMod(res, pa_x);
			STAMPP(end2)

			if(mini1>end2-start2) mini1 = end2-start2;
			
		}//*/
			
		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start3)
			multMod(res, pa_x, pb_x);
			STAMPP(end3)
			
			if(mini2>end3-start3) mini2 = end3-start3;
			
		}


		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start4)
			fcontract(res,res);
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
	
	printf("timer fexpand               : %llu\n",timer/NSAMPLES);	
	
	printf("timer squaring25519         : %llu\n",timer1/NSAMPLES);

	printf("timer mul25519              : %llu\n",timer2/NSAMPLES);
	
	printf("timer fcontract             : %llu\n",timer3/NSAMPLES);






	
	/********************
	//Timing !!!!!!!!!!!!!
	*********************/
	printf("\t  /***************************/\n");
	printf("\t / Timing rdpmc !!!!!!/\n");
	printf("\t/***************************/\n\n");
	
	printf("\ngmp, BN, BN_MONT, amns_origin vs  amns\n");
	printf("-------------------------\n");

	
	for(int k=0; k<NSAMPLES;k++){
	
		mini = (uint64_t)-1L,
		mini1 = (uint64_t)-1L,
		mini2 = (uint64_t)-1L,
		mini3 = (uint64_t)-1L, 
		mini4 = (uint64_t)-1L ;
		
		mpz_urandomm(A, r, modul_p);
		mpz_urandomm(B, r, modul_p);
		
		for(int i=0;i<NTEST;i++)
		{
			mpz_mul (A, A, B);
			mpz_mod (A, A, modul_p);
			mpz_export(pa, &countp, -1, sizeof(pa[0]) ,0,0, A);
			mpz_export(pb, &countp, -1, sizeof(pa[0]) ,0,0, B);
			fexpand(pa_x,pa);
			fexpand(pb_x,pb);
			multMod(res, pa_x, pb_x);
			
			fcontract(res,res);
			mpz_export(res, &countp, -1, sizeof(res[0]) ,0,0, E);
			
			
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
		}
		
		BN_dec2bn(&opA, mpz_get_str (NULL, 10, A));
		BN_dec2bn(&opB, mpz_get_str (NULL, 10, B));
		BN_dec2bn(&opP, mpz_get_str (NULL, 10, modul_p));
		BN_copy(opAA, opA);
		BN_copy(opBB, opB);
		BN_MONT_CTX_set(mont_ctx, opP, ctx);


		
		for(int i=0;i<NTEST;i++)
		{
			
			start1 = rdpmc_actual_cycles();
			mpz_mul (A, A, B);
			mpz_mod (A, A, modul_p);
			end1 = rdpmc_actual_cycles();
			
			if(mini>end1-start1) mini = end1-start1;
			
		}


			
		for(int i=0;i<NTEST;i++)
		{
			
			start3 = rdpmc_actual_cycles();
			multMod(pa_x, pb_x, res);
			end3 = rdpmc_actual_cycles();

			
			if(mini2>end3-start3) mini2 = end3-start3;
			
		}


		for(int i=0;i<NTEST;i++)
		{
			
			start4 = rdpmc_actual_cycles();
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			end4 = rdpmc_actual_cycles();

			if(mini3>end4-start4) mini3 = end4-start4;
			
		}
			
		for(int i=0;i<NTEST;i++)
		{
			
			start5 = rdpmc_actual_cycles();
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
			end5 = rdpmc_actual_cycles();
			
			if(mini4>end5-start5) mini4 = end5-start5;
			
		}
		

		timer += mini;

		timer1 += mini1;
		
		timer2 += mini2;
		
		timer3 += mini3;

		timer4 += mini4;
		
	}
	
	printf("RDPMC : rdpmc_actual_cycles() :\ntimer gmp                   : %llu\n",timer/NSAMPLES);	
	
	printf("timer mul25519              : %llu\n",timer2/NSAMPLES);
	
	printf("timer BN_mod_mul            : %llu\n",timer3/NSAMPLES);

	printf("timer BN_mod_mul_montgomery : %llu\n",timer4/NSAMPLES);
	
	
	
	timer=0, timer1=0, timer2=0, timer3=0, timer4=0;
	
	
	for(int k=0; k<NSAMPLES;k++){
	
		mini = (uint64_t)-1L,
		mini1 = (uint64_t)-1L,
		mini2 = (uint64_t)-1L,
		mini3 = (uint64_t)-1L, 
		mini4 = (uint64_t)-1L ;
		
		mpz_urandomm(A, r, modul_p);
		mpz_urandomm(B, r, modul_p);
		
		for(int i=0;i<NTEST;i++)
		{
			mpz_mul (A, A, B);
			mpz_mod (A, A, modul_p);
			mpz_export(pa, &countp, -1, sizeof(pa[0]) ,0,0, A);
			mpz_export(pb, &countp, -1, sizeof(pa[0]) ,0,0, B);
			fexpand(pa_x,pa);
			fexpand(pb_x,pb);
			multMod(res, pa_x, pb_x);
			squaringMod(res, pa_x);
			
			fcontract(res,res);
			mpz_export(res, &countp, -1, sizeof(res[0]) ,0,0, E);
			
			
		}
		


		
		for(int i=0;i<NTEST;i++)
		{
			
			start1 = rdpmc_actual_cycles();
			fexpand(pa_x,pa);
			end1 = rdpmc_actual_cycles();
			
			if(mini>end1-start1) mini = end1-start1;
			
		}


		for(int i=0;i<NTEST;i++)
		{
			
			start2 = rdpmc_actual_cycles();
			squaringMod(res, pa_x);
			end2 = rdpmc_actual_cycles();

			if(mini1>end2-start2) mini1 = end2-start2;
			
		}//*/
			
		for(int i=0;i<NTEST;i++)
		{
			
			
			start3 = rdpmc_actual_cycles();
			multMod(res, pa_x, pb_x);
			end3 = rdpmc_actual_cycles();
			
			if(mini2>end3-start3) mini2 = end3-start3;
			
		}


		for(int i=0;i<NTEST;i++)
		{
			
			start4 = rdpmc_actual_cycles();
			fcontract(res,res);
			end4 = rdpmc_actual_cycles();

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
	
	printf("RDPMC : rdpmc_actual_cycles() :\ntimer fexpand               : %llu\n",timer/NSAMPLES);	
	
	printf("timer squaring25519         : %llu\n",timer1/NSAMPLES);

	printf("timer mul25519              : %llu\n",timer2/NSAMPLES);
	
	printf("timer fcontract             : %llu\n",timer3/NSAMPLES);







	printf("\ngmp, BN, BN_MONT, amns_origin vs  amns\n");
	printf("-------------------------\n");


	for(int k=0; k<NSAMPLES;k++){
	
		mini = (uint64_t)-1L,
		mini1 = (uint64_t)-1L,
		mini2 = (uint64_t)-1L,
		mini3 = (uint64_t)-1L, 
		mini4 = (uint64_t)-1L ;
		
		mpz_urandomm(A, r, modul_p);
		mpz_urandomm(B, r, modul_p);
		
		for(int i=0;i<NTEST;i++)
		{
			mpz_mul (A, A, B);
			mpz_mod (A, A, modul_p);
			mpz_export(pa, &countp, -1, sizeof(pa[0]) ,0,0, A);
			mpz_export(pb, &countp, -1, sizeof(pa[0]) ,0,0, B);
			fexpand(pa_x,pa);
			fexpand(pb_x,pb);
			multMod(res, pa_x, pb_x);
			
			fcontract(res,res);
			mpz_export(res, &countp, -1, sizeof(res[0]) ,0,0, E);
			
			
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
		}
		
		BN_dec2bn(&opA, mpz_get_str (NULL, 10, A));
		BN_dec2bn(&opB, mpz_get_str (NULL, 10, B));
		BN_dec2bn(&opP, mpz_get_str (NULL, 10, modul_p));
		BN_copy(opAA, opA);
		BN_copy(opBB, opB);
		BN_MONT_CTX_set(mont_ctx, opP, ctx);


		
		for(int i=0;i<NTEST;i++)
		{
			
			start1 = rdpmc_reference_cycles();
			mpz_mul (A, A, B);
			mpz_mod (A, A, modul_p);
			end1 = rdpmc_reference_cycles();
			
			if(mini>end1-start1) mini = end1-start1;
			
		}

		for(int i=0;i<NTEST;i++)
		{
			
			start3 = rdpmc_reference_cycles();
			multMod(pa_x, pb_x, res);
			end3 = rdpmc_reference_cycles();

			
			if(mini2>end3-start3) mini2 = end3-start3;
			
		}


		for(int i=0;i<NTEST;i++)
		{
			
			start4 = rdpmc_reference_cycles();
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			end4 = rdpmc_reference_cycles();

			if(mini3>end4-start4) mini3 = end4-start4;
			
		}
			
		for(int i=0;i<NTEST;i++)
		{
			
			start5 = rdpmc_reference_cycles();
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
			end5 = rdpmc_reference_cycles();
			
			if(mini4>end5-start5) mini4 = end5-start5;
			
		}
		

		timer += mini;

		timer1 += mini1;
		
		timer2 += mini2;
		
		timer3 += mini3;

		timer4 += mini4;
		
	}
	
	printf("RDPMC : rdpmc_reference_cycles() :\ntimer gmp                   : %llu\n",timer/NSAMPLES);	
	
	printf("timer mul25519              : %llu\n",timer2/NSAMPLES);
	
	printf("timer BN_mod_mul            : %llu\n",timer3/NSAMPLES);

	printf("timer BN_mod_mul_montgomery : %llu\n",timer4/NSAMPLES);
	
	
	
	timer=0, timer1=0, timer2=0, timer3=0, timer4=0;
	
	
	for(int k=0; k<NSAMPLES;k++){
	
		mini = (uint64_t)-1L,
		mini1 = (uint64_t)-1L,
		mini2 = (uint64_t)-1L,
		mini3 = (uint64_t)-1L, 
		mini4 = (uint64_t)-1L ;
		
		mpz_urandomm(A, r, modul_p);
		mpz_urandomm(B, r, modul_p);
		
		for(int i=0;i<NTEST;i++)
		{
			mpz_mul (A, A, B);
			mpz_mod (A, A, modul_p);
			mpz_export(pa, &countp, -1, sizeof(pa[0]) ,0,0, A);
			mpz_export(pb, &countp, -1, sizeof(pa[0]) ,0,0, B);
			fexpand(pa_x,pa);
			fexpand(pb_x,pb);
			multMod(res, pa_x, pb_x);
			squaringMod(res, pa_x);
			
			fcontract(res,res);
			mpz_export(res, &countp, -1, sizeof(res[0]) ,0,0, E);
			
			
		}
		


		
		for(int i=0;i<NTEST;i++)
		{
			
			start1 = rdpmc_reference_cycles();
			fexpand(pa_x,pa);
			end1 = rdpmc_reference_cycles();
			
			if(mini>end1-start1) mini = end1-start1;
			
		}


		for(int i=0;i<NTEST;i++)
		{
			
			start2 = rdpmc_reference_cycles();
			squaringMod(res, pa_x);
			end2 = rdpmc_reference_cycles();

			if(mini1>end2-start2) mini1 = end2-start2;
			
		}//*/
			
		for(int i=0;i<NTEST;i++)
		{
			
			
			start3 = rdpmc_reference_cycles();
			multMod(res, pa_x, pb_x);
			end3 = rdpmc_reference_cycles();
			
			if(mini2>end3-start3) mini2 = end3-start3;
			
		}


		for(int i=0;i<NTEST;i++)
		{
			
			start4 = rdpmc_reference_cycles();
			fcontract(res,res);
			end4 = rdpmc_reference_cycles();

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
	
	printf("RDPMC : rdpmc_reference_cycles() :\ntimer fexpand               : %llu\n",timer/NSAMPLES);	
	
	printf("timer squaring25519         : %llu\n",timer1/NSAMPLES);

	printf("timer mul25519              : %llu\n",timer2/NSAMPLES);
	
	printf("timer fcontract             : %llu\n",timer3/NSAMPLES);











	
	/********************
	//Timing !!!!!!!!!!!!!
	*********************/
	printf("\n\t  /***************************/\n");
	printf("\t / Instructions rdpmc !!!!!!!/\n");
	printf("\t/***************************/\n\n");
	
	printf("\ngmp, BN, BN_MONT, amns_origin vs  amns\n");
	printf("-------------------------\n");

	
	for(int k=0; k<NSAMPLES;k++){
	
		mini = (uint64_t)-1L,
		mini1 = (uint64_t)-1L,
		mini2 = (uint64_t)-1L,
		mini3 = (uint64_t)-1L, 
		mini4 = (uint64_t)-1L ;
		
		mpz_urandomm(A, r, modul_p);
		mpz_urandomm(B, r, modul_p);
		
		for(int i=0;i<NTEST;i++)
		{
			mpz_mul (A, A, B);
			mpz_mod (A, A, modul_p);
			mpz_export(pa, &countp, -1, sizeof(pa[0]) ,0,0, A);
			mpz_export(pb, &countp, -1, sizeof(pa[0]) ,0,0, B);
			fexpand(pa_x,pa);
			fexpand(pb_x,pb);
			multMod(res, pa_x, pb_x);
			
			fcontract(res,res);
			mpz_export(res, &countp, -1, sizeof(res[0]) ,0,0, E);
			
			
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
		}
		
		BN_dec2bn(&opA, mpz_get_str (NULL, 10, A));
		BN_dec2bn(&opB, mpz_get_str (NULL, 10, B));
		BN_dec2bn(&opP, mpz_get_str (NULL, 10, modul_p));
		BN_copy(opAA, opA);
		BN_copy(opBB, opB);
		BN_MONT_CTX_set(mont_ctx, opP, ctx);


		
		for(int i=0;i<NTEST;i++)
		{
			
			start1 = rdpmc_instructions();
			mpz_mul (A, A, B);
			mpz_mod (A, A, modul_p);
			end1 = rdpmc_instructions();
			
			if(mini>end1-start1) mini = end1-start1;
			
		}

			
		for(int i=0;i<NTEST;i++)
		{
			
			start3 = rdpmc_instructions();
			multMod(pa_x, pb_x, res);
			end3 = rdpmc_instructions();

			
			if(mini2>end3-start3) mini2 = end3-start3;
			
		}


		for(int i=0;i<NTEST;i++)
		{
			
			start4 = rdpmc_instructions();
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			end4 = rdpmc_instructions();

			if(mini3>end4-start4) mini3 = end4-start4;
			
		}
			
		for(int i=0;i<NTEST;i++)
		{
			
			start5 = rdpmc_instructions();
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
			end5 = rdpmc_instructions();
			
			if(mini4>end5-start5) mini4 = end5-start5;
			
		}
		

		timer += mini;

		timer1 += mini1;
		
		timer2 += mini2;
		
		timer3 += mini3;

		timer4 += mini4;
		
	}
	
	printf("RDPMC : rdpmc_instructions() :\ntimer gmp                   : %llu\n",timer/NSAMPLES);	
	
	printf("timer mul25519              : %llu\n",timer2/NSAMPLES);
	
	printf("timer BN_mod_mul            : %llu\n",timer3/NSAMPLES);

	printf("timer BN_mod_mul_montgomery : %llu\n",timer4/NSAMPLES);
	
	
	
	timer=0, timer1=0, timer2=0, timer3=0, timer4=0;
	
	
	for(int k=0; k<NSAMPLES;k++){
	
		mini = (uint64_t)-1L,
		mini1 = (uint64_t)-1L,
		mini2 = (uint64_t)-1L,
		mini3 = (uint64_t)-1L, 
		mini4 = (uint64_t)-1L ;
		
		mpz_urandomm(A, r, modul_p);
		mpz_urandomm(B, r, modul_p);
		
		for(int i=0;i<NTEST;i++)
		{
			mpz_mul (A, A, B);
			mpz_mod (A, A, modul_p);
			mpz_export(pa, &countp, -1, sizeof(pa[0]) ,0,0, A);
			mpz_export(pb, &countp, -1, sizeof(pa[0]) ,0,0, B);
			fexpand(pa_x,pa);
			fexpand(pb_x,pb);
			multMod(res, pa_x, pb_x);
			squaringMod(res, pa_x);
			
			fcontract(res,res);
			mpz_export(res, &countp, -1, sizeof(res[0]) ,0,0, E);
			
			
		}
		


		
		for(int i=0;i<NTEST;i++)
		{
			
			start1 = rdpmc_instructions();
			fexpand(pa_x,pa);
			end1 = rdpmc_instructions();
			
			if(mini>end1-start1) mini = end1-start1;
			
		}


		for(int i=0;i<NTEST;i++)
		{
			
			start2 = rdpmc_instructions();
			squaringMod(res, pa_x);
			end2 = rdpmc_instructions();

			if(mini1>end2-start2) mini1 = end2-start2;
			
		}//*/
			
		for(int i=0;i<NTEST;i++)
		{
			
			
			start3 = rdpmc_instructions();
			multMod(res, pa_x, pb_x);
			end3 = rdpmc_instructions();
			
			if(mini2>end3-start3) mini2 = end3-start3;
			
		}


		for(int i=0;i<NTEST;i++)
		{
			
			start4 = rdpmc_instructions();
			fcontract(res,res);
			end4 = rdpmc_instructions();

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
	
	printf("RDPMC : rdpmc_instructions() :\ntimer fexpand               : %llu\n",timer/NSAMPLES);	
	
	printf("timer squaring25519         : %llu\n",timer1/NSAMPLES);

	printf("timer mul25519              : %llu\n",timer2/NSAMPLES);
	
	printf("timer fcontract             : %llu\n",timer3/NSAMPLES);











end:	
	
	printf("\nAu revoir and merci !\n");	

	mpz_clears (A, B, C, E, NULL);
	gmp_randclear(r);

	BN_MONT_CTX_free(mont_ctx);
	BN_CTX_end(ctx);
	BN_CTX_free(ctx);

	free_data();
	return 0;
}

