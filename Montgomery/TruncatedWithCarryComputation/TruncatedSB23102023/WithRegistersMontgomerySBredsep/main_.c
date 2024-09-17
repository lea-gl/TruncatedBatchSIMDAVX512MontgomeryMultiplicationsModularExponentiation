#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <gmp.h>
#include <openssl/bn.h>

//#include "structs_data.h"
//#include "add_mult_poly.c"
//#include "useful_functs.c"
//#include "amns_init.c"

//#include "init.c"

#include "ccount.h"
#include "tests.c"

#include "gmp_stuff.c"

#include "fonctions.h"
//#include "init.h"

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


	int64_t pa[NB_COEFF64];
	int64_t pb[NB_COEFF64];
	
	int64_t pc[NB_COEFF64];
	
	int64_t pa_x[NB_COEFF];
	int64_t pb_x[NB_COEFF];
	
	int64_t pc_x[NB_COEFF];
	
	
	uint64_t res[NB_COEFF]={0};
	uint64_t res_gmp[NB_COEFF*2]={0};
	
	size_t countp;
	int flag=0, counter=0;
 
	uint64_t mini, mini1, mini2, mini3, mini4;
 	unsigned long long int timer=0, timer1=0, timer2=0, timer3=0, timer4=0;
	

	unsigned long long int start1, end1;
	unsigned long long int start2, end2;
	unsigned long long int start3, end3;
	unsigned long long int start4, end4;
	unsigned long long int start5, end5;
	/*struct timespec start3, end3;
	struct timespec start4, end4;
	struct timespec start5, end5;
	struct timespec start6, end6;
	uint64_t diff1, diff2, diff3, diff4, diff5, diff6;//*/

	unsigned long seed = time(NULL);
	gmp_randstate_t r;
	gmp_randinit_default(r);
	gmp_randseed_ui(r, seed);


	//init_data();
	
	mpz_ui_pow_ui ( UPB, 2UL, SIZE );
	
	//mpz_set_str (modul_p, "20282409603651670423947251285999", 10);//2**104-17
	//mpz_set_str (modul_p, "91343852333181432387730302044767688728495783793", 10);//2**156-143	
	
	//mpz_set_str (modul_p, "411376139330301510538742295639337626245683966408394965837151957", 10);//2**208-299	
	
		//mpz_set_str (modul_p, "57896044618658097711785492504343953926634992332820282019728792003956564819949", 10);//2**255-19
	
	
	printf("%lu %d  %d\n\n", mpz_sizeinbase (UPB, 2), NB_COEFF, NB_COEFF64);
	gmp_printf("UPB  : 0x%ZX\n\n\n", UPB);




	
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
		mpz_mod (C, C, UPB);
		gmp_printf("C  : 0x%ZX\n\n\n", C);
		
		mpz_export(res_gmp, &countp, -1, sizeof(res_gmp[0]) ,0,0, C);
		displayVect(res_gmp,"res_gmp",NB_COEFF);


		mpz_export(pa, &countp, -1, sizeof(pa[0]) ,0,0, A);
		mpz_export(pb, &countp, -1, sizeof(pa[0]) ,0,0, B);
		displayVect(pa,"pa     ",NB_COEFF);
		displayVect(pb,"pb     ",NB_COEFF);
		
				
		displayVect(pa_x,"pa_x   ",NB_COEFF);
		displayVect(pb_x,"pb_x   ",NB_COEFF);

		//multMod(res, pa_x, pb_x);
		
		//fcontract(res,res);
		//mpz_export(res, &countp, -1, sizeof(res[0]) ,0,0, E);
		

		displayVect(res,"res    ",NB_COEFF);
		displayVect(res_gmp,"res_gmp",NB_COEFF);
		
	// a512 and b512 contain 8 values in columns	
	__m512i a512[NB_COEFF], b512[NB_COEFF], res512[NB_COEFF*2];
	
	mpz_t A8[8], B8[8], C8[8], E8[8];
	for(int i=0;i<8;i++)	
		mpz_inits (A8[i], B8[i], C8[i], E8[i], NULL);
	uint64_t a64[8][NB_COEFF64], b64[8][NB_COEFF64], c64[8][NB_COEFF64], res64[8][NB_COEFF64*2];
	
	for(int i=0;i<8;i++)
	{
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


	fexpand_8_512_52( b512, b64);
	fexpand_8_512_52( a512, a64);


	for(int i=0;i<8;i++)
		displayVect(a64[i],"a64[i]     ",NB_COEFF64);
	displayVect512_NB_COEFF(a512,"a512");


	for(int i=0;i<8;i++)
		displayVect(b64[i],"b64[i]     ",NB_COEFF64);
	
	displayVect512_NB_COEFF(b512,"b512");
	
	
	printf("fcontract_8_512_52()\n");
	fcontract_8_512_52( c64, a512);
	
	
		printf("\n");

	for(int i=0;i<8;i++){
		displayVect(a64[i],"a64[i]     ",NB_COEFF64);
		//displayVect512_NB_COEFF(a512,"a512");
		//for(int i=0;i<8;i++)
		displayVect(c64[i],"c64[i]     ",NB_COEFF64);
	}

	for(int i=0;i<8;i++){
		for(int j=0;j<NB_COEFF64;j++){
			printf("%16.16lX ",c64[i][j]^a64[i][j]);
		}
	}
	printf("\n");
	
	for(int i=0;i<8;i++){
		for(int j=0;j<NB_COEFF64;j++)
			if(c64[i][j]^a64[i][j]) flag++;
		flag?counter++,flag=0:counter,flag=0;
	}
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory fexpand-fcontract !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;

	//goto end;
	
	
	mul512_8_1040(res512, a512, b512);
	
	displayVect512_NB_COEFF(res512,"res512_lo");
	
	displayVect512_NB_COEFF(res512+NB_COEFF,"res512_hi");
	
	fcontract_8_512_52_res(res64, res512);
	
	
	flag=0, counter=0;
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
	

	//goto end;

	printf("\t  /***********************************/\n");
	printf("\t /   Test on 1000 datasets   /\n");
	printf("\t/***********************************/\n\n");

	
	flag=0, counter=0;
	
	for(int i=0;i<NTEST;i++)
	{
		for(int i=0;i<8;i++)
		{
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


		/*for(int i=0;i<8;i++)
			displayVect(a64[i],"a64[i]     ",NB_COEFF);
		displayVect512_NB_COEFF(a512,"a512");


		for(int i=0;i<8;i++)
			displayVect(b64[i],"b64[i]     ",NB_COEFF);
		
		displayVect512_NB_COEFF(b512,"b512");*/
		
		
		//printf("fcontract_8_512_52()\n");
		fcontract_8_512_52( c64, a512);
		

		/*for(int i=0;i<8;i++)
			displayVect(a64[i],"a64[i]     ",NB_COEFF);
		//displayVect512_NB_COEFF(a512,"a512");
		for(int i=0;i<8;i++)
			displayVect(c64[i],"c64[i]     ",NB_COEFF);*/
		
		mul512_8_1040(res512, a512, b512);
		
		//displayVect512_NB_COEFF(res512,"res512_lo");
		
		//displayVect512_NB_COEFF(res512+NB_COEFF,"res512_hi");
		
		fcontract_8_512_52_res(res64, res512);
		
		for(int i=0;i<8;i++)
		{
			mpz_mul(C,A8[i],B8[i]);
			mpz_export(res_gmp, &countp, -1, sizeof(b64[0][0]) ,0,0, C);
			
			
			//displayVect(res_gmp, "res_gmp     ",NB_COEFF*2);
			//displayVect(res64[i],"res64[i]    ",NB_COEFF*2);
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
				//displayVect512_NB_COEFF(res512,"res512_lo");
				
				//displayVect512_NB_COEFF(res512+NB_COEFF,"res512_hi");
				
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



	//goto end;
	

	
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
		
		mpz_urandomm(A, r, UPB);
		mpz_urandomm(B, r, UPB);
		
		mpz_export(pa, &countp, -1, sizeof(pa[0]) ,0,0, A);
		mpz_export(pb, &countp, -1, sizeof(pa[0]) ,0,0, B);

		/*for(int i=0;i<NTEST;i++)
		{
			mpz_mul (A, A, B);
			mpz_mod (A, A, UPB);
			//from_int_to_amns(pa, A);
			//from_int_to_amns(pb, B);
			//mult_mod_poly(pa, pa, pb);
			//mult_mod_poly_origin(pa, pa, pb);
			//from_amns_to_int(A, pa);
			mpz_export(pa, &countp, -1, sizeof(pa[0]) ,0,0, A);
			mpz_export(pb, &countp, -1, sizeof(pa[0]) ,0,0, B);
			fexpand(pa_x,pa);
			fexpand(pb_x,pb);
			multMod(res, pa_x, pb_x);
			
			fcontract(res,res);
			mpz_export(res, &countp, -1, sizeof(res[0]) ,0,0, E);
			
			
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
		}*/
		
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
			mpz_mul (C, A, B);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start1)
			mpz_mul (C, A, B);
			//mpz_mod (A, A, UPB);
			mpz_mul (C, A, B);
			mpz_mul (C, A, B);
			mpz_mul (C, A, B);
			mpz_mul (C, A, B);
			mpz_mul (C, A, B);
			mpz_mul (C, A, B);
			mpz_mul (C, A, B);
			STAMPP(end1)
			
			if(mini>end1-start1) mini = end1-start1;
			
		}


		/*for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start2)
			mult_mod_poly_origin(pc, pa, pb);
			STAMPP(end2)

			if(mini1>end2-start2) mini1 = end2-start2;
			
		}*/


		for(int i=0;i<NTEST;i++)
		{
			
			mpn_mul_n(pc, pa, pb, NB_COEFF);
			
		}
		
		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start3)
			mpn_mul_n(pc, pa, pb, NB_COEFF);
			mpn_mul_n(pc, pa, pb, NB_COEFF);
			mpn_mul_n(pc, pa, pb, NB_COEFF);
			mpn_mul_n(pc, pa, pb, NB_COEFF);
			mpn_mul_n(pc, pa, pb, NB_COEFF);
			mpn_mul_n(pc, pa, pb, NB_COEFF);
			mpn_mul_n(pc, pa, pb, NB_COEFF);
			mpn_mul_n(pc, pa, pb, NB_COEFF);
			//multMod(pa_x, pb_x, res);
			STAMPP(end3)
			
			if(mini1>end3-start3) mini1 = end3-start3;
			
		}//*/


		
		
		for(int i=0;i<NTEST;i++)
		{
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
		}

		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start4)
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			STAMPP(end4)

			if(mini3>end4-start4) mini3 = end4-start4;
			
		}
		
		for(int i=0;i<NTEST;i++)
		{
			mul512_8_1040(res512, a512, b512);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			STAMP(start3)
			mul512_8_1040(res512, a512, b512);
			mul512_8_1040(res512, a512, b512);
			mul512_8_1040(res512, a512, b512);
			mul512_8_1040(res512, a512, b512);
			mul512_8_1040(res512, a512, b512);
			mul512_8_1040(res512, a512, b512);
			mul512_8_1040(res512, a512, b512);
			mul512_8_1040(res512, a512, b512);
			mul512_8_1040(res512, a512, b512);
			mul512_8_1040(res512, a512, b512);
			STAMPP(end3)
			
			if(mini2>end3-start3) mini2 = end3-start3;
			
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
		

		timer += mini;

		timer1 += mini1;
		
		timer2 += mini2;
		
		timer3 += mini3;

		timer4 += mini4;
		
	}
	
	printf("timer gmp                   : %llu\n",timer/NSAMPLES);	
	
	printf("timer gmp mpn_mul_n         : %llu\n",timer1/NSAMPLES);

	printf("timer mul512_8_1040          : %llu\n",timer2/(NSAMPLES*10));
	
	printf("timer BN_mod_mul            : %llu\n",timer3/NSAMPLES);

	printf("timer BN_mod_mul_montgomery : %llu\n",timer4/NSAMPLES);
	
	
	//goto end;
	
	
		
	timer=0, timer1=0, timer2=0, timer3=0, timer4=0;
	
	
	for(int k=0; k<NSAMPLES;k++){
	
		mini = (uint64_t)-1L,
		mini1 = (uint64_t)-1L,
		mini2 = (uint64_t)-1L,
		mini3 = (uint64_t)-1L, 
		mini4 = (uint64_t)-1L ;
		
		mpz_urandomm(A, r, UPB);
		mpz_urandomm(B, r, UPB);
		
		for(int i=0;i<NTEST;i++)
		{
			mpz_mul (A, A, B);
			mpz_mod (A, A, UPB);
			//from_int_to_amns(pa, A);
			//from_int_to_amns(pb, B);
			//mult_mod_poly(pa, pa, pb);
			//mult_mod_poly_origin(pa, pa, pb);
			//from_amns_to_int(A, pa);
			mpz_export(pa, &countp, -1, sizeof(pa[0]) ,0,0, A);
			mpz_export(pb, &countp, -1, sizeof(pa[0]) ,0,0, B);

			mpz_export(res, &countp, -1, sizeof(res[0]) ,0,0, E);
			
			
		}
		

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


		/*for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start2)
			squaringMod(res, pa_x);
			STAMPP(end2)

			if(mini1>end2-start2) mini1 = end2-start2;
			
		}//*/
			
		/*for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start3)
			//mult_mod_poly(pc, pa, pb);
			multMod(res, pa_x, pb_x);
			STAMPP(end3)
			
			if(mini2>end3-start3) mini2 = end3-start3;
			
		}//*/


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
			
		/*for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start5)
			STAMPP(end5)
			
			if(mini4>end5-start5) mini4 = end5-start5;
			
		}*/
		

		timer += mini;

		timer1 += mini1;
		
		timer2 += mini2;
		
		timer3 += mini3;

		timer4 += mini4;
		
	}
	
	printf("\nautres fonction p25519 :\n");
	
	printf("------------------------\n");
	
	printf("timer fexpand_8_512_52       : %llu\n",timer/NSAMPLES/10);	
	
	//printf("timer squaring25519         : %llu\n",timer1/NSAMPLES);

	//printf("timer mul25519              : %llu\n",timer2/NSAMPLES);
	
	printf("timer fcontract_8_512_52_res : %llu\n",timer3/NSAMPLES/10);

	//printf("timer BN_mod_mul_montgomery : %llu\n",timer4/NSAMPLES);
	


	/*printf("%lu %d %lu %lu %lu %lu\n\n", mpz_sizeinbase (UPB, 2), NB_COEFF, (diff2+diff3), (diff4+diff5), diff6, diff1);

	printf("nbiter = %d\n\n", nbiter);
	gmp_printf("A       : %Zd\n", E);
	gmp_printf("B       : %Zd\n\n", B);
	gmp_printf("r_gmp   : %Zd\n", A);
	gmp_printf("r_amns  : %Zd\n", C);
	gmp_printf("r_ssld  : %s\n", BN_bn2dec(opAA));
	gmp_printf("r_sslm  : %s\n", BN_bn2dec(opA));
	printf("\ntime using gmp			= %lu nanoseconds\n", diff1);
	printf("\ntime using openssl		= %lu nanoseconds\n", diff6);
	printf("\ntime using amns prod		= %lu nanoseconds\n", diff2);
	printf("total time using amns prod	= %lu nanoseconds\n", (diff2+diff3));
	printf("\ntime using openssl mont		= %lu nanoseconds\n", diff4);
	printf("total time using openssl mont	= %lu nanoseconds\n", (diff4+diff5));*/





	//goto end;
	
	
	
	/********************
	//Instructions !!!!!!!!!!!!!
	*********************/
	printf("\n\n\t  /***************************/\n");
	printf("\t / Instructions !!!!!!!!!!!!!/\n");
	printf("\t/***************************/\n\n");
	
	printf("\ngmp, BN, BN_MONT, amns_origin vs  amns\n");
	printf("-------------------------\n");

	
	for(int k=0; k<NSAMPLES;k++){
	
		mini = (uint64_t)-1L,
		mini1 = (uint64_t)-1L,
		mini2 = (uint64_t)-1L,
		mini3 = (uint64_t)-1L, 
		mini4 = (uint64_t)-1L ;
		
		mpz_urandomm(A, r, UPB);
		mpz_urandomm(B, r, UPB);
		
		mpz_export(pa, &countp, -1, sizeof(pa[0]) ,0,0, A);
		mpz_export(pb, &countp, -1, sizeof(pa[0]) ,0,0, B);

		/*for(int i=0;i<NTEST;i++)
		{
			mpz_mul (A, A, B);
			mpz_mod (A, A, UPB);
			//from_int_to_amns(pa, A);
			//from_int_to_amns(pb, B);
			//mult_mod_poly(pa, pa, pb);
			//mult_mod_poly_origin(pa, pa, pb);
			//from_amns_to_int(A, pa);
			mpz_export(pa, &countp, -1, sizeof(pa[0]) ,0,0, A);
			mpz_export(pb, &countp, -1, sizeof(pa[0]) ,0,0, B);
			fexpand(pa_x,pa);
			fexpand(pb_x,pb);
			multMod(res, pa_x, pb_x);
			
			fcontract(res,res);
			mpz_export(res, &countp, -1, sizeof(res[0]) ,0,0, E);
			
			
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			BN_mod_mul_montgomery(opA, opA, opB, mont_ctx, ctx);
		}*/
		
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
			mpz_mul (C, A, B);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			
			start1 = rdpmc_instructions();//1)
			mpz_mul (C, A, B);
			//mpz_mod (A, A, UPB);
			mpz_mul (C, A, B);
			mpz_mul (C, A, B);
			mpz_mul (C, A, B);
			mpz_mul (C, A, B);
			mpz_mul (C, A, B);
			mpz_mul (C, A, B);
			mpz_mul (C, A, B);
			end1 = rdpmc_instructions();//1)
			
			if(mini>end1-start1) mini = end1-start1;
			
		}


		/*for(int i=0;i<NTEST;i++)
		{
			
			rdpmc_instructions();//2)
			mult_mod_poly_origin(pc, pa, pb);
			end = rdpmc_instructions();//2)

			if(mini1>end2-start2) mini1 = end2-start2;
			
		}*/


		for(int i=0;i<NTEST;i++)
		{
			
			mpn_mul_n(pc, pa, pb, NB_COEFF);
			
		}
		
		for(int i=0;i<NTEST;i++)
		{
			
			start3 = rdpmc_instructions();//3)
			mpn_mul_n(pc, pa, pb, NB_COEFF);
			mpn_mul_n(pc, pa, pb, NB_COEFF);
			mpn_mul_n(pc, pa, pb, NB_COEFF);
			mpn_mul_n(pc, pa, pb, NB_COEFF);
			mpn_mul_n(pc, pa, pb, NB_COEFF);
			mpn_mul_n(pc, pa, pb, NB_COEFF);
			mpn_mul_n(pc, pa, pb, NB_COEFF);
			mpn_mul_n(pc, pa, pb, NB_COEFF);
			//multMod(pa_x, pb_x, res);
			end3 = rdpmc_instructions();//3)
			
			if(mini1>end3-start3) mini1 = end3-start3;
			
		}//*/


		
		
		for(int i=0;i<NTEST;i++)
		{
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
		}

		for(int i=0;i<NTEST;i++)
		{
			
			start4 = rdpmc_instructions();//4)
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			BN_mod_mul(opAA, opAA, opBB, opP, ctx);
			end4 = rdpmc_instructions();//4)

			if(mini3>end4-start4) mini3 = end4-start4;
			
		}
		
		for(int i=0;i<NTEST;i++)
		{
			mul512_8_1040(res512, a512, b512);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			start3 = rdpmc_instructions();//3)
			mul512_8_1040(res512, a512, b512);
			mul512_8_1040(res512, a512, b512);
			mul512_8_1040(res512, a512, b512);
			mul512_8_1040(res512, a512, b512);
			mul512_8_1040(res512, a512, b512);
			mul512_8_1040(res512, a512, b512);
			mul512_8_1040(res512, a512, b512);
			mul512_8_1040(res512, a512, b512);
			mul512_8_1040(res512, a512, b512);
			mul512_8_1040(res512, a512, b512);
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
		

		timer += mini;

		timer1 += mini1;
		
		timer2 += mini2;
		
		timer3 += mini3;

		timer4 += mini4;
		
	}

	
	printf("gmp                   : %llu\n",timer/NSAMPLES);	
	
	printf("gmp mpn_mul_n         : %llu\n",timer1/NSAMPLES);

	printf("mul512_8_1040          : %llu\n",timer2/(NSAMPLES*10));
	
	printf("BN_mod_mul            : %llu\n",timer3/NSAMPLES);

	printf("BN_mod_mul_montgomery : %llu\n",timer4/NSAMPLES);
	
	
	//goto end;
	
	
		
	timer=0, timer1=0, timer2=0, timer3=0, timer4=0;
	
	
	for(int k=0; k<NSAMPLES;k++){
	
		mini = (uint64_t)-1L,
		mini1 = (uint64_t)-1L,
		mini2 = (uint64_t)-1L,
		mini3 = (uint64_t)-1L, 
		mini4 = (uint64_t)-1L ;
		
		mpz_urandomm(A, r, UPB);
		mpz_urandomm(B, r, UPB);
		
		for(int i=0;i<NTEST;i++)
		{
			mpz_mul (A, A, B);
			mpz_mod (A, A, UPB);
			//from_int_to_amns(pa, A);
			//from_int_to_amns(pb, B);
			//mult_mod_poly(pa, pa, pb);
			//mult_mod_poly_origin(pa, pa, pb);
			//from_amns_to_int(A, pa);
			mpz_export(pa, &countp, -1, sizeof(pa[0]) ,0,0, A);
			mpz_export(pb, &countp, -1, sizeof(pa[0]) ,0,0, B);
			
			mpz_export(res, &countp, -1, sizeof(res[0]) ,0,0, E);
			
			
		}
		

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


		/*for(int i=0;i<NTEST;i++)
		{
			
			rdpmc_instructions();//2)
			squaringMod(res, pa_x);
			end = rdpmc_instructions();//2)

			if(mini1>end2-start2) mini1 = end2-start2;
			
		}//*/
			
		/*for(int i=0;i<NTEST;i++)
		{
			
			rdpmc_instructions();//3)
			//mult_mod_poly(pc, pa, pb);
			multMod(res, pa_x, pb_x);
			end = rdpmc_instructions();//3)
			
			if(mini2>end3-start3) mini2 = end3-start3;
			
		}//*/


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
			
		/*for(int i=0;i<NTEST;i++)
		{
			
			rdpmc_instructions();//5)
			end = rdpmc_instructions();//5)
			
			if(mini4>end5-start5) mini4 = end5-start5;
			
		}*/
		

		timer += mini;

		timer1 += mini1;
		
		timer2 += mini2;
		
		timer3 += mini3;

		timer4 += mini4;
		
	}
	
	printf("\nautres fonction p25519 :\n");
	
	printf("------------------------\n");
	
	printf("fexpand_8_512_52       : %llu\n",timer/(NSAMPLES*10));	
	
	//printf("squaring25519         : %llu\n",timer1/NSAMPLES);

	//printf("mul25519              : %llu\n",timer2/NSAMPLES);
	
	printf("fcontract_8_512_52_res : %llu\n",timer3/(NSAMPLES*10));

	//printf("BN_mod_mul_montgomery : %llu\n",timer4/NSAMPLES);
	






















end:	
	
	printf("\nAu revoir and merci !\n");	

	mpz_clears (A, B, C, E, UPB, NULL);
	gmp_randclear(r);

	BN_MONT_CTX_free(mont_ctx);
	BN_CTX_end(ctx);
	BN_CTX_free(ctx);

	free_data(modul_p);
	return 0;
}

