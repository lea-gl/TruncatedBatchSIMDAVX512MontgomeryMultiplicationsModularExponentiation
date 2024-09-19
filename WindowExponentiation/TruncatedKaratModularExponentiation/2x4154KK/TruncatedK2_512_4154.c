#include "TruncatedK512_2078_2W.c"
/* Karatsuba multiplication */


//#define DEBUG

static inline void force_inline truncatedMul512_8_4154KK(__m512i out[160], __m512i a512[80], __m512i b512[80])
{

	__m512i D0[80], D1[80], D2[80], alpah[40], blpbh[40], alpahbis[40], blpbhbis[40];


	// al*bl, radix 2^1039 result
	
	//mul512_8_2078K(D0, a512, b512);

	truncatedMul512_8_2078K(D0, a512, b512);
	

	// ah*bh, radix 2^1039 result
	
	mul512_8_2078K(D2, a512+40, b512+40);




	// ah*bh, radix 2^1039 result
	
	add512_8_2078K(alpah, a512, a512+40);
	
	add512_8_2078K(blpbh, b512, b512+40);
	
	truncatedMul512_8_2078K(D1, alpah, blpbh);	
	//mul512_8_2078K(D1, alpah, blpbh);
	
	
#ifdef	DEBUG
	

	displayVect512_NB(a512,"a512",80);
	displayVect512_NB(b512,"b512",80);
	
	
	displayVect512_NB(alpah,"alpah",40);
	displayVect512_NB(blpbh,"blpbh",40);
	

	displayVect512_NB_COEFF(D1,"D1");
	
	displayVect512_NB_COEFF(D1,"D1");
	
	//getchar();//*/
	
	unsigned long int a64[8][NB_COEFF64_SIZE_K], b64[8][NB_COEFF64_SIZE_K], res64[8][NB_COEFF64_SIZE_K*2], res_gmp[NB_COEFF64_SIZE_K*2];
	size_t countp;
	
	int counter=0,flag=0;
	
	fcontract_8_512_2077K(a64,alpah);
	fcontract_8_512_2077K(b64,blpbh);
	
	fexpand_8_512_2077K(alpahbis,a64);
	
	fexpand_8_512_2077K(blpbhbis,b64);
	
	displayVect512_NB(alpah,"alpah   ",40);
	displayVect512_NB(alpahbis,"alpahbis",40);
	getchar();
	displayVect512_NB(blpbh,"blpbh   ",40);
	displayVect512_NB(blpbhbis,"blpbhbis",40);
	//getchar();//*/
	
	
	
	mpz_t A, B, C;// UPB is used as upper bound
	
	mpz_inits (A, B, C, NULL);
	//conversion_8_r2077K(D1,D1);
	
	fcontract_8_512_2077K_res( res64, D1);
	for(int i=0;i<8;i++)
	{

		mpz_import(A, NB_COEFF64_SIZE_K, -1, sizeof(b64[0][0]) ,0,0, a64[i]);

		mpz_import(B, NB_COEFF64_SIZE_K, -1, sizeof(b64[0][0]) ,0,0, b64[i]);
		
		gmp_printf("A  : 0x%ZX\n\n\n", A);

		displayVect(a64[i],"a64",33);
		gmp_printf("B  : 0x%ZX\n\n\n", B);
		displayVect(b64[i],"b64",33);
		
		
	
	
		mpz_mul(C,A,B);
		mpz_export(res_gmp, &countp, -1, sizeof(b64[0][0]) ,0,0, C);
		//displayVect(res_gmp, "res_gmp     ",NB_COEFF64_SIZE_K*2);
		//displayVect(res64[i],"res64[i]    ",NB_COEFF64_SIZE_K*2);
		
		
		displayVect(res_gmp+NB_COEFF64_SIZE_K, "res_gmp     ",NB_COEFF64_SIZE_K);
		displayVect(res64[i]+NB_COEFF64_SIZE_K,"res64[i]    ",NB_COEFF64_SIZE_K);
		
		printf("xor = ");
		for(int j=0;j<NB_COEFF64_SIZE_K;j++){
			printf("%16.16lX ",res64[i][NB_COEFF64_SIZE_K*2-1-j]^res_gmp[NB_COEFF64_SIZE_K*2-1-j]);
		}
		printf("\n");

	//}
	//printf("\n");
	
	//for(int i=0;i<8;i++){//
		for(int j=NB_COEFF64_SIZE_K;j<NB_COEFF64_SIZE_K*2;j++)
			if(res64[i][j]^res_gmp[j]) flag++;
		flag?counter++,flag=0:counter,flag=0;
		printf("\n");
	}
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory alpah*blbph !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;
	
	getchar();

#endif

	
#ifdef	DEBUG__

	//truncatedMul512_8_2078K(D1, alpah, blpbh);
	
	mul512_8_2078K(D1, alpah, blpbh);
	

	displayVect512_NB_COEFF(D1,"D1");
	
	//getchar();//*/
	
	//unsigned long int a64[8][NB_COEFF64_SIZE_K], b64[8][NB_COEFF64_SIZE_K], res64[8][NB_COEFF64_SIZE_K*2], res_gmp[NB_COEFF64_SIZE_K*2];
	//size_t countp;
	
	//int counter=0,flag=0;
	
	fcontract_8_512_2077K(a64,alpah);
	fcontract_8_512_2077K(b64,blpbh);
	
	fexpand_8_512_2077K(alpahbis,a64);
	
	fexpand_8_512_2077K(blpbhbis,b64);
	
	displayVect512_NB(alpah,"alpah   ",40);
	displayVect512_NB(alpahbis,"alpahbis",40);
	getchar();
	displayVect512_NB(blpbh,"blpbh   ",40);
	displayVect512_NB(blpbhbis,"blpbhbis",40);
	//getchar();//*/
	
	
	
	//mpz_t A, B, C;// UPB is used as upper bound
	
	//mpz_inits (A, B, C, NULL);
	//conversion_8_r2077K(D1,D1);
	
	fcontract_8_512_2077K_res( res64, D1);
	for(int i=0;i<8;i++)
	{

		mpz_import(A, NB_COEFF64_SIZE_K, -1, sizeof(b64[0][0]) ,0,0, a64[i]);

		mpz_import(B, NB_COEFF64_SIZE_K, -1, sizeof(b64[0][0]) ,0,0, b64[i]);
		
		gmp_printf("A  : 0x%ZX\n\n\n", A);

		displayVect(a64[i],"a64",33);
		gmp_printf("B  : 0x%ZX\n\n\n", B);
		displayVect(b64[i],"b64",33);
		
		
	
	
		mpz_mul(C,A,B);
		mpz_export(res_gmp, &countp, -1, sizeof(b64[0][0]) ,0,0, C);
		//displayVect(res_gmp, "res_gmp     ",NB_COEFF64_SIZE_K*2);
		//displayVect(res64[i],"res64[i]    ",NB_COEFF64_SIZE_K*2);
		
		displayVect(res_gmp+NB_COEFF64_SIZE_K, "res_gmp     ",NB_COEFF64_SIZE_K);
		displayVect(res64[i]+NB_COEFF64_SIZE_K,"res64[i]    ",NB_COEFF64_SIZE_K);
		
		printf("xor = ");
		for(int j=NB_COEFF64_SIZE_K;j<NB_COEFF64_SIZE_K*2;j++){
			printf("%16.16lX ",res64[i][NB_COEFF64_SIZE_K*2-1-j]^res_gmp[NB_COEFF64_SIZE_K*2-1-j]);
		}
		printf("\n");

	//}
	//printf("\n");
	
	//for(int i=0;i<8;i++){//
		for(int j=NB_COEFF64_SIZE_K;j<NB_COEFF64_SIZE_K*2;j++)
			if(res64[i][j]^res_gmp[j]) flag++;
		flag?counter++,flag=0:counter,flag=0;
		printf("\n");
	}
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory alpah*blbph !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;

	//}
	
	getchar();

#endif
	
	// conversion in radix 2^2077 conversion
	
	//displayVect512_NB_COEFF(D0,"D0");
	/*displayVect512_NB_COEFF(D0,"D0");

	getchar();//*/
	
	
	conversion_8_r2077K(D0,D0);
	conversion_8_r2077K(D1,D1);
	conversion_8_r2077K(D2,D2);//*/
	
	
	//__m512i c = 
	/*displayVect512_NB(D1,"D1",40);
	add512_8_2078K(D1, D1, D0+40);
	//D1[40] = _mm512_add_epi64(D1[40],c);
	displayVect512_NB(D0+40,"D0+40",40);
	displayVect512_NB(D1,"D1",40);
	
	// 	retenue
	__m512i c = _mm512_srli_epi64(D1[39],49);
	displayVect512(&c,"c");
	
	//getchar();
	
	D1[39] = _mm512_and_si512(D1[39],mask50);
	displayVect512_NB(D1,"D1",40);
	
	
	D1[40] = _mm512_add_epi64(D1[40],c);
	
	
	add512_8_2078K(D1+40, D1+40, D2);
	c = _mm512_srli_epi64(D1[79],49);
	D1[79] = _mm512_and_si512(D1[79],mask50);//*/
	
	
	/*__m512i D0_0 = _mm512_load_epi64(D0), D2_0 = _mm512_load_epi64(D2);
	__m512i D0_1 = _mm512_load_epi64(D0+1), D2_1 = _mm512_load_epi64(D2+1);
	__m512i D0_2 = _mm512_load_epi64(D0+2), D2_2 = _mm512_load_epi64(D2+2);
	__m512i D0_3 = _mm512_load_epi64(D0+3), D2_3 = _mm512_load_epi64(D2+3);
	__m512i D0_4 = _mm512_load_epi64(D0+4), D2_4 = _mm512_load_epi64(D2+4);
	__m512i D0_5 = _mm512_load_epi64(D0+5), D2_5 = _mm512_load_epi64(D2+5);
	__m512i D0_6 = _mm512_load_epi64(D0+6), D2_6 = _mm512_load_epi64(D2+6);
	__m512i D0_7 = _mm512_load_epi64(D0+7), D2_7 = _mm512_load_epi64(D2+7);
	__m512i D0_8 = _mm512_load_epi64(D0+8), D2_8 = _mm512_load_epi64(D2+8);
	__m512i D0_9 = _mm512_load_epi64(D0+9), D2_9 = _mm512_load_epi64(D2+9);
	__m512i D0_10 = _mm512_load_epi64(D0+10), D2_10 = _mm512_load_epi64(D2+10);
	__m512i D0_11 = _mm512_load_epi64(D0+11), D2_11 = _mm512_load_epi64(D2+11);
	__m512i D0_12 = _mm512_load_epi64(D0+12), D2_12 = _mm512_load_epi64(D2+12);
	__m512i D0_13 = _mm512_load_epi64(D0+13), D2_13 = _mm512_load_epi64(D2+13);
	__m512i D0_14 = _mm512_load_epi64(D0+14), D2_14 = _mm512_load_epi64(D2+14);
	__m512i D0_15 = _mm512_load_epi64(D0+15), D2_15 = _mm512_load_epi64(D2+15);
	__m512i D0_16 = _mm512_load_epi64(D0+16), D2_16 = _mm512_load_epi64(D2+16);
	__m512i D0_17 = _mm512_load_epi64(D0+17), D2_17 = _mm512_load_epi64(D2+17);*/
	
	
	
	__m512i D2_0 = _mm512_load_epi64(D2);
	__m512i D2_1 = _mm512_load_epi64(D2+1);
	__m512i D2_2 = _mm512_load_epi64(D2+2);
	__m512i D2_3 = _mm512_load_epi64(D2+3);
	__m512i D2_4 = _mm512_load_epi64(D2+4);
	__m512i D2_5 = _mm512_load_epi64(D2+5);
	__m512i D2_6 = _mm512_load_epi64(D2+6);
	__m512i D2_7 = _mm512_load_epi64(D2+7);
	__m512i D2_8 = _mm512_load_epi64(D2+8);
	__m512i D2_9 = _mm512_load_epi64(D2+9);
	__m512i D2_10 = _mm512_load_epi64(D2+10);
	__m512i D2_11 = _mm512_load_epi64(D2+11);
	__m512i D2_12 = _mm512_load_epi64(D2+12);
	__m512i D2_13 = _mm512_load_epi64(D2+13);
	__m512i D2_14 = _mm512_load_epi64(D2+14);
	__m512i D2_15 = _mm512_load_epi64(D2+15);
	__m512i D2_16 = _mm512_load_epi64(D2+16);
	__m512i D2_17 = _mm512_load_epi64(D2+17);	
	
	
	
	__m512i D0_18 = _mm512_load_epi64(D0+18), D2_18 = _mm512_load_epi64(D2+18);
	__m512i D0_19 = _mm512_load_epi64(D0+19), D2_19 = _mm512_load_epi64(D2+19);
	__m512i D0_20 = _mm512_load_epi64(D0+20), D2_20 = _mm512_load_epi64(D2+20);
	__m512i D0_21 = _mm512_load_epi64(D0+21), D2_21 = _mm512_load_epi64(D2+21);
	__m512i D0_22 = _mm512_load_epi64(D0+22), D2_22 = _mm512_load_epi64(D2+22);
	__m512i D0_23 = _mm512_load_epi64(D0+23), D2_23 = _mm512_load_epi64(D2+23);
	__m512i D0_24 = _mm512_load_epi64(D0+24), D2_24 = _mm512_load_epi64(D2+24);
	__m512i D0_25 = _mm512_load_epi64(D0+25), D2_25 = _mm512_load_epi64(D2+25);
	__m512i D0_26 = _mm512_load_epi64(D0+26), D2_26 = _mm512_load_epi64(D2+26);
	__m512i D0_27 = _mm512_load_epi64(D0+27), D2_27 = _mm512_load_epi64(D2+27);
	__m512i D0_28 = _mm512_load_epi64(D0+28), D2_28 = _mm512_load_epi64(D2+28);
	__m512i D0_29 = _mm512_load_epi64(D0+29), D2_29 = _mm512_load_epi64(D2+29);
	__m512i D0_30 = _mm512_load_epi64(D0+30), D2_30 = _mm512_load_epi64(D2+30);
	__m512i D0_31 = _mm512_load_epi64(D0+31), D2_31 = _mm512_load_epi64(D2+31);
	__m512i D0_32 = _mm512_load_epi64(D0+32), D2_32 = _mm512_load_epi64(D2+32);
	__m512i D0_33 = _mm512_load_epi64(D0+33), D2_33 = _mm512_load_epi64(D2+33);
	__m512i D0_34 = _mm512_load_epi64(D0+34), D2_34 = _mm512_load_epi64(D2+34);
	__m512i D0_35 = _mm512_load_epi64(D0+35), D2_35 = _mm512_load_epi64(D2+35);
	__m512i D0_36 = _mm512_load_epi64(D0+36), D2_36 = _mm512_load_epi64(D2+36);
	__m512i D0_37 = _mm512_load_epi64(D0+37), D2_37 = _mm512_load_epi64(D2+37);
	__m512i D0_38 = _mm512_load_epi64(D0+38), D2_38 = _mm512_load_epi64(D2+38);//*/
	__m512i D0_39 = _mm512_load_epi64(D0+39), D2_39 = _mm512_load_epi64(D2+39);
	
	
	__m512i D0_40 = _mm512_load_epi64(D0+40), D2_40 = _mm512_load_epi64(D2+40);
	__m512i D0_41 = _mm512_load_epi64(D0+41), D2_41 = _mm512_load_epi64(D2+41);
	__m512i D0_42 = _mm512_load_epi64(D0+42), D2_42 = _mm512_load_epi64(D2+42);
	__m512i D0_43 = _mm512_load_epi64(D0+43), D2_43 = _mm512_load_epi64(D2+43);
	__m512i D0_44 = _mm512_load_epi64(D0+44), D2_44 = _mm512_load_epi64(D2+44);
	__m512i D0_45 = _mm512_load_epi64(D0+45), D2_45 = _mm512_load_epi64(D2+45);
	__m512i D0_46 = _mm512_load_epi64(D0+46), D2_46 = _mm512_load_epi64(D2+46);
	__m512i D0_47 = _mm512_load_epi64(D0+47), D2_47 = _mm512_load_epi64(D2+47);
	__m512i D0_48 = _mm512_load_epi64(D0+48), D2_48 = _mm512_load_epi64(D2+48);
	__m512i D0_49 = _mm512_load_epi64(D0+49), D2_49 = _mm512_load_epi64(D2+49);
	__m512i D0_50 = _mm512_load_epi64(D0+50), D2_50 = _mm512_load_epi64(D2+50);
	__m512i D0_51 = _mm512_load_epi64(D0+51), D2_51 = _mm512_load_epi64(D2+51);
	__m512i D0_52 = _mm512_load_epi64(D0+52), D2_52 = _mm512_load_epi64(D2+52);
	__m512i D0_53 = _mm512_load_epi64(D0+53), D2_53 = _mm512_load_epi64(D2+53);
	__m512i D0_54 = _mm512_load_epi64(D0+54), D2_54 = _mm512_load_epi64(D2+54);
	__m512i D0_55 = _mm512_load_epi64(D0+55), D2_55 = _mm512_load_epi64(D2+55);
	__m512i D0_56 = _mm512_load_epi64(D0+56), D2_56 = _mm512_load_epi64(D2+56);
	__m512i D0_57 = _mm512_load_epi64(D0+57), D2_57 = _mm512_load_epi64(D2+57);
	__m512i D0_58 = _mm512_load_epi64(D0+58), D2_58 = _mm512_load_epi64(D2+58);
	__m512i D0_59 = _mm512_load_epi64(D0+59), D2_59 = _mm512_load_epi64(D2+59);
	__m512i D0_60 = _mm512_load_epi64(D0+60), D2_60 = _mm512_load_epi64(D2+60);
	__m512i D0_61 = _mm512_load_epi64(D0+61), D2_61 = _mm512_load_epi64(D2+61);
	__m512i D0_62 = _mm512_load_epi64(D0+62), D2_62 = _mm512_load_epi64(D2+62);
	__m512i D0_63 = _mm512_load_epi64(D0+63), D2_63 = _mm512_load_epi64(D2+63);
	__m512i D0_64 = _mm512_load_epi64(D0+64), D2_64 = _mm512_load_epi64(D2+64);
	__m512i D0_65 = _mm512_load_epi64(D0+65), D2_65 = _mm512_load_epi64(D2+65);
	__m512i D0_66 = _mm512_load_epi64(D0+66), D2_66 = _mm512_load_epi64(D2+66);
	__m512i D0_67 = _mm512_load_epi64(D0+67), D2_67 = _mm512_load_epi64(D2+67);
	__m512i D0_68 = _mm512_load_epi64(D0+68), D2_68 = _mm512_load_epi64(D2+68);
	__m512i D0_69 = _mm512_load_epi64(D0+69), D2_69 = _mm512_load_epi64(D2+69);
	__m512i D0_70 = _mm512_load_epi64(D0+70), D2_70 = _mm512_load_epi64(D2+70);
	__m512i D0_71 = _mm512_load_epi64(D0+71), D2_71 = _mm512_load_epi64(D2+71);
	__m512i D0_72 = _mm512_load_epi64(D0+72), D2_72 = _mm512_load_epi64(D2+72);
	__m512i D0_73 = _mm512_load_epi64(D0+73), D2_73 = _mm512_load_epi64(D2+73);
	__m512i D0_74 = _mm512_load_epi64(D0+74), D2_74 = _mm512_load_epi64(D2+74);
	__m512i D0_75 = _mm512_load_epi64(D0+75), D2_75 = _mm512_load_epi64(D2+75);
	__m512i D0_76 = _mm512_load_epi64(D0+76), D2_76 = _mm512_load_epi64(D2+76);
	__m512i D0_77 = _mm512_load_epi64(D0+77), D2_77 = _mm512_load_epi64(D2+77);
	__m512i D0_78 = _mm512_load_epi64(D0+78), D2_78 = _mm512_load_epi64(D2+78);
	__m512i D0_79 = _mm512_load_epi64(D0+79), D2_79 = _mm512_load_epi64(D2+79);
	
	/*
	//conversion D0 in radix 2^2077
	
	__m512i carry = D0_39>>49;	D0_40 = (D0_40<<1)+carry;
	D0_39 &= mask50;	carry = D0_40>>52;
	D0_41 = (D0_41<<1)+carry;	D0_40 &= mask52;
	carry = D0_41>>52;	D0_42 = (D0_42<<1)+carry;
	D0_41 &= mask52;	carry = D0_42>>52;
	D0_43 = (D0_43<<1)+carry;	D0_42 &= mask52;
	carry = D0_43>>52;	D0_44 = (D0_44<<1)+carry;
	D0_43 &= mask52;	carry = D0_44>>52;
	D0_45 = (D0_45<<1)+carry;	D0_44 &= mask52;
	carry = D0_45>>52;	D0_46 = (D0_46<<1)+carry;
	D0_45 &= mask52;	carry = D0_46>>52;
	D0_47 = (D0_47<<1)+carry;	D0_46 &= mask52;
	carry = D0_47>>52;	D0_48 = (D0_48<<1)+carry;
	D0_47 &= mask52;	carry = D0_48>>52;
	D0_49 = (D0_49<<1)+carry;	D0_48 &= mask52;
	carry = D0_49>>52;	D0_50 = (D0_50<<1)+carry;
	D0_49 &= mask52;	carry = D0_50>>52;
	D0_51 = (D0_51<<1)+carry;	D0_50 &= mask52;
	carry = D0_51>>52;	D0_52 = (D0_52<<1)+carry;
	D0_51 &= mask52;	carry = D0_52>>52;
	D0_53 = (D0_53<<1)+carry;	D0_52 &= mask52;
	carry = D0_53>>52;	D0_54 = (D0_54<<1)+carry;
	D0_53 &= mask52;	carry = D0_54>>52;
	D0_55 = (D0_55<<1)+carry;	D0_54 &= mask52;
	carry = D0_55>>52;	D0_56 = (D0_56<<1)+carry;
	D0_55 &= mask52;	carry = D0_56>>52;
	D0_57 = (D0_57<<1)+carry;
	D0_56 &= mask52;	carry = D0_57>>52;
	D0_58 = (D0_58<<1)+carry;	D0_57 &= mask52;
	carry = D0_58>>52;	D0_59 = (D0_59<<1)+carry;
	D0_58 &= mask52;	carry = D0_59>>52;
	D0_60 = (D0_60<<1)+carry;	D0_59 &= mask52;
	carry = D0_60>>52;	D0_61 = (D0_61<<1)+carry;
	D0_60 &= mask52;	carry = D0_61>>52;
	D0_62 = (D0_62<<1)+carry;	D0_61 &= mask52;
	carry = D0_62>>52;	D0_63 = (D0_63<<1)+carry;
	D0_62 &= mask52;	carry = D0_63>>52;
	D0_64 = (D0_64<<1)+carry;	D0_63 &= mask52;
	carry = D0_64>>52;	D0_65 = (D0_65<<1)+carry;
	D0_64 &= mask52;	carry = D0_65>>52;
	D0_66 = (D0_66<<1)+carry;	D0_65 &= mask52;
	carry = D0_66>>52;	D0_67 = (D0_67<<1)+carry;
	D0_66 &= mask52;	carry = D0_67>>52;
	D0_68 = (D0_68<<1)+carry;	D0_67 &= mask52;
	carry = D0_68>>52;	D0_69 = (D0_69<<1)+carry;
	D0_68 &= mask52;	carry = D0_69>>52;
	D0_70 = (D0_70<<1)+carry;	D0_69 &= mask52;
	carry = D0_70>>52;	D0_71 = (D0_71<<1)+carry;
	D0_70 &= mask52;	carry = D0_71>>52;
	D0_72 = (D0_72<<1)+carry;	D0_71 &= mask52;
	carry = D0_72>>52;	D0_73 = (D0_73<<1)+carry;
	D0_72 &= mask52;	carry = D0_73>>52;
	D0_74 = (D0_74<<1)+carry;	D0_73 &= mask52;
	carry = D0_74>>52;	D0_75 = (D0_75<<1)+carry;
	D0_74 &= mask52;	carry = D0_75>>52;
	D0_76 = (D0_76<<1)+carry;	D0_75 &= mask52;
	carry = D0_76>>52;	D0_77 = (D0_77<<1)+carry;
	D0_76 &= mask52;	carry = D0_77>>52;
	D0_78 = (D0_78<<1)+carry;	D0_77 &= mask52;
	carry = D0_78>>52;	D0_79 = (D0_79<<1)+carry;
	D0_78 &= mask52;
	

	//conversion D2 in radix 2^2077
	
	carry = D2_39>>49;	D2_40 = (D2_40<<1)+carry;
	D2_39 &= mask50;	carry = D2_40>>52;
	D2_41 = (D2_41<<1)+carry;	D2_40 &= mask52;
	carry = D2_41>>52;	D2_42 = (D2_42<<1)+carry;
	D2_41 &= mask52;	carry = D2_42>>52;
	D2_43 = (D2_43<<1)+carry;	D2_42 &= mask52;
	carry = D2_43>>52;	D2_44 = (D2_44<<1)+carry;
	D2_43 &= mask52;	carry = D2_44>>52;
	D2_45 = (D2_45<<1)+carry;	D2_44 &= mask52;
	carry = D2_45>>52;	D2_46 = (D2_46<<1)+carry;
	D2_45 &= mask52;	carry = D2_46>>52;
	D2_47 = (D2_47<<1)+carry;	D2_46 &= mask52;
	carry = D2_47>>52;	D2_48 = (D2_48<<1)+carry;
	D2_47 &= mask52;	carry = D2_48>>52;
	D2_49 = (D2_49<<1)+carry;	D2_48 &= mask52;
	carry = D2_49>>52;	D2_50 = (D2_50<<1)+carry;
	D2_49 &= mask52;	carry = D2_50>>52;
	D2_51 = (D2_51<<1)+carry;	D2_50 &= mask52;
	carry = D2_51>>52;	D2_52 = (D2_52<<1)+carry;
	D2_51 &= mask52;	carry = D2_52>>52;
	D2_53 = (D2_53<<1)+carry;	D2_52 &= mask52;
	carry = D2_53>>52;	D2_54 = (D2_54<<1)+carry;
	D2_53 &= mask52;	carry = D2_54>>52;
	D2_55 = (D2_55<<1)+carry;	D2_54 &= mask52;
	carry = D2_55>>52;	D2_56 = (D2_56<<1)+carry;
	D2_55 &= mask52;	carry = D2_56>>52;
	D2_57 = (D2_57<<1)+carry;
	D2_56 &= mask52;	carry = D2_57>>52;
	D2_58 = (D2_58<<1)+carry;	D2_57 &= mask52;
	carry = D2_58>>52;	D2_59 = (D2_59<<1)+carry;
	D2_58 &= mask52;	carry = D2_59>>52;
	D2_60 = (D2_60<<1)+carry;	D2_59 &= mask52;
	carry = D2_60>>52;	D2_61 = (D2_61<<1)+carry;
	D2_60 &= mask52;	carry = D2_61>>52;
	D2_62 = (D2_62<<1)+carry;	D2_61 &= mask52;
	carry = D2_62>>52;	D2_63 = (D2_63<<1)+carry;
	D2_62 &= mask52;	carry = D2_63>>52;
	D2_64 = (D2_64<<1)+carry;	D2_63 &= mask52;
	carry = D2_64>>52;	D2_65 = (D2_65<<1)+carry;
	D2_64 &= mask52;	carry = D2_65>>52;
	D2_66 = (D2_66<<1)+carry;	D2_65 &= mask52;
	carry = D2_66>>52;	D2_67 = (D2_67<<1)+carry;
	D2_66 &= mask52;	carry = D2_67>>52;
	D2_68 = (D2_68<<1)+carry;	D2_67 &= mask52;
	carry = D2_68>>52;	D2_69 = (D2_69<<1)+carry;
	D2_68 &= mask52;	carry = D2_69>>52;
	D2_70 = (D2_70<<1)+carry;	D2_69 &= mask52;
	carry = D2_70>>52;	D2_71 = (D2_71<<1)+carry;
	D2_70 &= mask52;	carry = D2_71>>52;
	D2_72 = (D2_72<<1)+carry;	D2_71 &= mask52;
	carry = D2_72>>52;	D2_73 = (D2_73<<1)+carry;
	D2_72 &= mask52;	carry = D2_73>>52;
	D2_74 = (D2_74<<1)+carry;	D2_73 &= mask52;
	carry = D2_74>>52;	D2_75 = (D2_75<<1)+carry;
	D2_74 &= mask52;	carry = D2_75>>52;
	D2_76 = (D2_76<<1)+carry;	D2_75 &= mask52;
	carry = D2_76>>52;	D2_77 = (D2_77<<1)+carry;
	D2_76 &= mask52;	carry = D2_77>>52;
	D2_78 = (D2_78<<1)+carry;	D2_77 &= mask52;
	carry = D2_78>>52;	D2_79 = (D2_79<<1)+carry;
	D2_78 &= mask52;//*/


	
	
	// Final Reconstruction
	

	// tmp = D0+D2, radix 2^2077/radix 2^1039
	/*__m512i tmp[160];
	
	add512_8_2078K(tmp, D0, D2);
	
	// Carry radix 2^2077
	tmp[40] = _mm512_srli_epi64(tmp[39],49);
	tmp[39] = _mm512_and_si512(tmp[39],mask50);
	
	addC512_8_2078K(tmp+40, D0+40, D2+40);//*/
	

	// D1 = D1 -tmp, radix 2^2079/radix 2^1039
	
	/*add512_8_2078K(D1, D1, D0+40);
	
	add512_8_2078K(D1+40, D1+40, D2);
	
	__m512i borrow = sub512_8_4154K(D1, D1, tmp);
	
	//last borrow
	
	__m512i borrow = _mm512_srli_epi64(tmp[79],49);
	tmp[79] = _mm512_and_si512(tmp[79],mask50);//*/
	
	
	
	
	/*__m512i D1_0 = _mm512_load_epi64(D1), D1_40 = _mm512_load_epi64(D1+40);
	__m512i D1_1 = _mm512_load_epi64(D1+1), D1_41 = _mm512_load_epi64(D1+41);
	__m512i D1_2 = _mm512_load_epi64(D1+2), D1_42 = _mm512_load_epi64(D1+42);
	__m512i D1_3 = _mm512_load_epi64(D1+3), D1_43 = _mm512_load_epi64(D1+43);
	__m512i D1_4 = _mm512_load_epi64(D1+4), D1_44 = _mm512_load_epi64(D1+44);
	__m512i D1_5 = _mm512_load_epi64(D1+5), D1_45 = _mm512_load_epi64(D1+45);
	__m512i D1_6 = _mm512_load_epi64(D1+6), D1_46 = _mm512_load_epi64(D1+46);
	__m512i D1_7 = _mm512_load_epi64(D1+7), D1_47 = _mm512_load_epi64(D1+47);
	__m512i D1_8 = _mm512_load_epi64(D1+8), D1_48 = _mm512_load_epi64(D1+48);
	__m512i D1_9 = _mm512_load_epi64(D1+9), D1_49 = _mm512_load_epi64(D1+49);
	__m512i D1_10 = _mm512_load_epi64(D1+10), D1_50 = _mm512_load_epi64(D1+50);
	__m512i D1_11 = _mm512_load_epi64(D1+11), D1_51 = _mm512_load_epi64(D1+51);
	__m512i D1_12 = _mm512_load_epi64(D1+12), D1_52 = _mm512_load_epi64(D1+52);
	__m512i D1_13 = _mm512_load_epi64(D1+13), D1_53 = _mm512_load_epi64(D1+53);
	__m512i D1_14 = _mm512_load_epi64(D1+14), D1_54 = _mm512_load_epi64(D1+54);
	__m512i D1_15 = _mm512_load_epi64(D1+15), D1_55 = _mm512_load_epi64(D1+55);
	__m512i D1_16 = _mm512_load_epi64(D1+16), D1_56 = _mm512_load_epi64(D1+56);
	__m512i D1_17 = _mm512_load_epi64(D1+17), D1_57 = _mm512_load_epi64(D1+57);//*/
	
	
	
	
	__m512i D1_40 = _mm512_load_epi64(D1+40);
	__m512i D1_41 = _mm512_load_epi64(D1+41);
	__m512i D1_42 = _mm512_load_epi64(D1+42);
	__m512i D1_43 = _mm512_load_epi64(D1+43);
	__m512i D1_44 = _mm512_load_epi64(D1+44);
	__m512i D1_45 = _mm512_load_epi64(D1+45);
	__m512i D1_46 = _mm512_load_epi64(D1+46);
	__m512i D1_47 = _mm512_load_epi64(D1+47);
	__m512i D1_48 = _mm512_load_epi64(D1+48);
	__m512i D1_49 = _mm512_load_epi64(D1+49);
	__m512i D1_50 = _mm512_load_epi64(D1+50);
	__m512i D1_51 = _mm512_load_epi64(D1+51);
	__m512i D1_52 = _mm512_load_epi64(D1+52);
	__m512i D1_53 = _mm512_load_epi64(D1+53);
	__m512i D1_54 = _mm512_load_epi64(D1+54);
	__m512i D1_55 = _mm512_load_epi64(D1+55);
	__m512i D1_56 = _mm512_load_epi64(D1+56);
	__m512i D1_57 = _mm512_load_epi64(D1+57);//*/
	
	
	

	__m512i D1_18 = _mm512_load_epi64(D1+18), D1_58 = _mm512_load_epi64(D1+58);
	__m512i D1_19 = _mm512_load_epi64(D1+19), D1_59 = _mm512_load_epi64(D1+59);
	__m512i D1_20 = _mm512_load_epi64(D1+20), D1_60 = _mm512_load_epi64(D1+60);
	__m512i D1_21 = _mm512_load_epi64(D1+21), D1_61 = _mm512_load_epi64(D1+61);
	__m512i D1_22 = _mm512_load_epi64(D1+22), D1_62 = _mm512_load_epi64(D1+62);
	__m512i D1_23 = _mm512_load_epi64(D1+23), D1_63 = _mm512_load_epi64(D1+63);
	__m512i D1_24 = _mm512_load_epi64(D1+24), D1_64 = _mm512_load_epi64(D1+64);
	__m512i D1_25 = _mm512_load_epi64(D1+25), D1_65 = _mm512_load_epi64(D1+65);
	__m512i D1_26 = _mm512_load_epi64(D1+26), D1_66 = _mm512_load_epi64(D1+66);
	__m512i D1_27 = _mm512_load_epi64(D1+27), D1_67 = _mm512_load_epi64(D1+67);
	__m512i D1_28 = _mm512_load_epi64(D1+28), D1_68 = _mm512_load_epi64(D1+68);
	__m512i D1_29 = _mm512_load_epi64(D1+29), D1_69 = _mm512_load_epi64(D1+69);
	__m512i D1_30 = _mm512_load_epi64(D1+30), D1_70 = _mm512_load_epi64(D1+70);
	__m512i D1_31 = _mm512_load_epi64(D1+31), D1_71 = _mm512_load_epi64(D1+71);
	__m512i D1_32 = _mm512_load_epi64(D1+32), D1_72 = _mm512_load_epi64(D1+72);
	__m512i D1_33 = _mm512_load_epi64(D1+33), D1_73 = _mm512_load_epi64(D1+73);
	__m512i D1_34 = _mm512_load_epi64(D1+34), D1_74 = _mm512_load_epi64(D1+74);
	__m512i D1_35 = _mm512_load_epi64(D1+35), D1_75 = _mm512_load_epi64(D1+75);
	__m512i D1_36 = _mm512_load_epi64(D1+36), D1_76 = _mm512_load_epi64(D1+76);
	__m512i D1_37 = _mm512_load_epi64(D1+37), D1_77 = _mm512_load_epi64(D1+77);
	__m512i D1_38 = _mm512_load_epi64(D1+38), D1_78 = _mm512_load_epi64(D1+78);
	__m512i D1_39 = _mm512_load_epi64(D1+39), D1_79 = _mm512_load_epi64(D1+79);//*/


	/*
	//conversion D2 in radix 2^2077
	
	carry = D1_39>>49;	D1_40 = (D1_40<<1)+carry;
	D1_39 &= mask50;	carry = D1_40>>52;
	D1_41 = (D1_41<<1)+carry;	D1_40 &= mask52;
	carry = D1_41>>52;	D1_42 = (D1_42<<1)+carry;
	D1_41 &= mask52;	carry = D1_42>>52;
	D1_43 = (D1_43<<1)+carry;	D1_42 &= mask52;
	carry = D1_43>>52;	D1_44 = (D1_44<<1)+carry;
	D1_43 &= mask52;	carry = D1_44>>52;
	D1_45 = (D1_45<<1)+carry;	D1_44 &= mask52;
	carry = D1_45>>52;	D1_46 = (D1_46<<1)+carry;
	D1_45 &= mask52;	carry = D1_46>>52;
	D1_47 = (D1_47<<1)+carry;	D1_46 &= mask52;
	carry = D1_47>>52;	D1_48 = (D1_48<<1)+carry;
	D1_47 &= mask52;	carry = D1_48>>52;
	D1_49 = (D1_49<<1)+carry;	D1_48 &= mask52;
	carry = D1_49>>52;	D1_50 = (D1_50<<1)+carry;
	D1_49 &= mask52;	carry = D1_50>>52;
	D1_51 = (D1_51<<1)+carry;	D1_50 &= mask52;
	carry = D1_51>>52;	D1_52 = (D1_52<<1)+carry;
	D1_51 &= mask52;	carry = D1_52>>52;
	D1_53 = (D1_53<<1)+carry;	D1_52 &= mask52;
	carry = D1_53>>52;	D1_54 = (D1_54<<1)+carry;
	D1_53 &= mask52;	carry = D1_54>>52;
	D1_55 = (D1_55<<1)+carry;	D1_54 &= mask52;
	carry = D1_55>>52;	D1_56 = (D1_56<<1)+carry;
	D1_55 &= mask52;	carry = D1_56>>52;
	D1_57 = (D1_57<<1)+carry;
	D1_56 &= mask52;	carry = D1_57>>52;
	D1_58 = (D1_58<<1)+carry;	D1_57 &= mask52;
	carry = D1_58>>52;	D1_59 = (D1_59<<1)+carry;
	D1_58 &= mask52;	carry = D1_59>>52;
	D1_60 = (D1_60<<1)+carry;	D1_59 &= mask52;
	carry = D1_60>>52;	D1_61 = (D1_61<<1)+carry;
	D1_60 &= mask52;	carry = D1_61>>52;
	D1_62 = (D1_62<<1)+carry;	D1_61 &= mask52;
	carry = D1_62>>52;	D1_63 = (D1_63<<1)+carry;
	D1_62 &= mask52;	carry = D1_63>>52;
	D1_64 = (D1_64<<1)+carry;	D1_63 &= mask52;
	carry = D1_64>>52;	D1_65 = (D1_65<<1)+carry;
	D1_64 &= mask52;	carry = D1_65>>52;
	D1_66 = (D1_66<<1)+carry;	D1_65 &= mask52;
	carry = D1_66>>52;	D1_67 = (D1_67<<1)+carry;
	D1_66 &= mask52;	carry = D1_67>>52;
	D1_68 = (D1_68<<1)+carry;	D1_67 &= mask52;
	carry = D1_68>>52;	D1_69 = (D1_69<<1)+carry;
	D1_68 &= mask52;	carry = D1_69>>52;
	D1_70 = (D1_70<<1)+carry;	D1_69 &= mask52;
	carry = D1_70>>52;	D1_71 = (D1_71<<1)+carry;
	D1_70 &= mask52;	carry = D1_71>>52;
	D1_72 = (D1_72<<1)+carry;	D1_71 &= mask52;
	carry = D1_72>>52;	D1_73 = (D1_73<<1)+carry;
	D1_72 &= mask52;	carry = D1_73>>52;
	D1_74 = (D1_74<<1)+carry;	D1_73 &= mask52;
	carry = D1_74>>52;	D1_75 = (D1_75<<1)+carry;
	D1_74 &= mask52;	carry = D1_75>>52;
	D1_76 = (D1_76<<1)+carry;	D1_75 &= mask52;
	carry = D1_76>>52;	D1_77 = (D1_77<<1)+carry;
	D1_76 &= mask52;	carry = D1_77>>52;
	D1_78 = (D1_78<<1)+carry;	D1_77 &= mask52;
	carry = D1_78>>52;	D1_79 = (D1_79<<1)+carry;
	D1_78 &= mask52;//*/


	__m512i borrow, carry, carry_D1;

	/*borrow = _mm512_add_epi64(D0_0,D2_0);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_0 = _mm512_add_epi64(D1_0,D0_40);
	carry_D1 = _mm512_srli_epi64(D1_0,52);
	D1_0 = _mm512_and_si512(D1_0,mask52);
	D1_0 = _mm512_sub_epi64(D1_0,borrow);
	borrow  = _mm512_srli_epi64(D1_0,52)&un;
	D1_0 = _mm512_and_si512(D1_0,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_1);
	borrow = _mm512_add_epi64(borrow,D0_1);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_1 = _mm512_add_epi64(D1_1,carry_D1);
	D1_1 = _mm512_add_epi64(D1_1,D0_41);
	carry_D1 = _mm512_srli_epi64(D1_1,52);
	D1_1 = _mm512_and_si512(D1_1,mask52);
	D1_1 = _mm512_sub_epi64(D1_1,borrow);
	borrow  = _mm512_srli_epi64(D1_1,52)&un;
	D1_1 = _mm512_and_si512(D1_1,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_2);
	borrow = _mm512_add_epi64(borrow,D0_2);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_2 = _mm512_add_epi64(D1_2,carry_D1);
	D1_2 = _mm512_add_epi64(D1_2,D0_42);
	carry_D1 = _mm512_srli_epi64(D1_2,52);
	D1_2 = _mm512_and_si512(D1_2,mask52);
	D1_2 = _mm512_sub_epi64(D1_2,borrow);
	borrow  = _mm512_srli_epi64(D1_2,52)&un;
	D1_2 = _mm512_and_si512(D1_2,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_3);
	borrow = _mm512_add_epi64(borrow,D0_3);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_3 = _mm512_add_epi64(D1_3,carry_D1);
	D1_3 = _mm512_add_epi64(D1_3,D0_43);
	carry_D1 = _mm512_srli_epi64(D1_3,52);
	D1_3 = _mm512_and_si512(D1_3,mask52);
	D1_3 = _mm512_sub_epi64(D1_3,borrow);
	borrow  = _mm512_srli_epi64(D1_3,52)&un;
	D1_3 = _mm512_and_si512(D1_3,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_4);
	borrow = _mm512_add_epi64(borrow,D0_4);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_4 = _mm512_add_epi64(D1_4,carry_D1);
	D1_4 = _mm512_add_epi64(D1_4,D0_44);
	carry_D1 = _mm512_srli_epi64(D1_4,52);
	D1_4 = _mm512_and_si512(D1_4,mask52);
	D1_4 = _mm512_sub_epi64(D1_4,borrow);
	borrow  = _mm512_srli_epi64(D1_4,52)&un;
	D1_4 = _mm512_and_si512(D1_4,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_5);
	borrow = _mm512_add_epi64(borrow,D0_5);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_5 = _mm512_add_epi64(D1_5,carry_D1);
	D1_5 = _mm512_add_epi64(D1_5,D0_45);
	carry_D1 = _mm512_srli_epi64(D1_5,52);
	D1_5 = _mm512_and_si512(D1_5,mask52);
	D1_5 = _mm512_sub_epi64(D1_5,borrow);
	borrow  = _mm512_srli_epi64(D1_5,52)&un;
	D1_5 = _mm512_and_si512(D1_5,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_6);
	borrow = _mm512_add_epi64(borrow,D0_6);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_6 = _mm512_add_epi64(D1_6,carry_D1);
	D1_6 = _mm512_add_epi64(D1_6,D0_46);
	carry_D1 = _mm512_srli_epi64(D1_6,52);
	D1_6 = _mm512_and_si512(D1_6,mask52);
	D1_6 = _mm512_sub_epi64(D1_6,borrow);
	borrow  = _mm512_srli_epi64(D1_6,52)&un;
	D1_6 = _mm512_and_si512(D1_6,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_7);
	borrow = _mm512_add_epi64(borrow,D0_7);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_7 = _mm512_add_epi64(D1_7,carry_D1);
	D1_7 = _mm512_add_epi64(D1_7,D0_47);
	carry_D1 = _mm512_srli_epi64(D1_7,52);
	D1_7 = _mm512_and_si512(D1_7,mask52);
	D1_7 = _mm512_sub_epi64(D1_7,borrow);
	borrow  = _mm512_srli_epi64(D1_7,52)&un;
	D1_7 = _mm512_and_si512(D1_7,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_8);
	borrow = _mm512_add_epi64(borrow,D0_8);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_8 = _mm512_add_epi64(D1_8,carry_D1);
	D1_8 = _mm512_add_epi64(D1_8,D0_48);
	carry_D1 = _mm512_srli_epi64(D1_8,52);
	D1_8 = _mm512_and_si512(D1_8,mask52);
	D1_8 = _mm512_sub_epi64(D1_8,borrow);
	borrow  = _mm512_srli_epi64(D1_8,52)&un;
	D1_8 = _mm512_and_si512(D1_8,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_9);
	borrow = _mm512_add_epi64(borrow,D0_9);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_9 = _mm512_add_epi64(D1_9,carry_D1);
	D1_9 = _mm512_add_epi64(D1_9,D0_49);
	carry_D1 = _mm512_srli_epi64(D1_9,52);
	D1_9 = _mm512_and_si512(D1_9,mask52);
	D1_9 = _mm512_sub_epi64(D1_9,borrow);
	borrow  = _mm512_srli_epi64(D1_9,52)&un;
	D1_9 = _mm512_and_si512(D1_9,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_10);
	borrow = _mm512_add_epi64(borrow,D0_10);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_10 = _mm512_add_epi64(D1_10,carry_D1);
	D1_10 = _mm512_add_epi64(D1_10,D0_50);
	carry_D1 = _mm512_srli_epi64(D1_10,52);
	D1_10 = _mm512_and_si512(D1_10,mask52);
	D1_10 = _mm512_sub_epi64(D1_10,borrow);
	borrow  = _mm512_srli_epi64(D1_10,52)&un;
	D1_10 = _mm512_and_si512(D1_10,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_11);
	borrow = _mm512_add_epi64(borrow,D0_11);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_11 = _mm512_add_epi64(D1_11,carry_D1);
	D1_11 = _mm512_add_epi64(D1_11,D0_51);
	carry_D1 = _mm512_srli_epi64(D1_11,52);
	D1_11 = _mm512_and_si512(D1_11,mask52);
	D1_11 = _mm512_sub_epi64(D1_11,borrow);
	borrow  = _mm512_srli_epi64(D1_11,52)&un;
	D1_11 = _mm512_and_si512(D1_11,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_12);
	borrow = _mm512_add_epi64(borrow,D0_12);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_12 = _mm512_add_epi64(D1_12,carry_D1);
	D1_12 = _mm512_add_epi64(D1_12,D0_52);
	carry_D1 = _mm512_srli_epi64(D1_12,52);
	D1_12 = _mm512_and_si512(D1_12,mask52);
	D1_12 = _mm512_sub_epi64(D1_12,borrow);
	borrow  = _mm512_srli_epi64(D1_12,52)&un;
	D1_12 = _mm512_and_si512(D1_12,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_13);
	borrow = _mm512_add_epi64(borrow,D0_13);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_13 = _mm512_add_epi64(D1_13,carry_D1);
	D1_13 = _mm512_add_epi64(D1_13,D0_53);
	carry_D1 = _mm512_srli_epi64(D1_13,52);
	D1_13 = _mm512_and_si512(D1_13,mask52);
	D1_13 = _mm512_sub_epi64(D1_13,borrow);
	borrow  = _mm512_srli_epi64(D1_13,52)&un;
	D1_13 = _mm512_and_si512(D1_13,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_14);
	borrow = _mm512_add_epi64(borrow,D0_14);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_14 = _mm512_add_epi64(D1_14,carry_D1);
	D1_14 = _mm512_add_epi64(D1_14,D0_54);
	carry_D1 = _mm512_srli_epi64(D1_14,52);
	D1_14 = _mm512_and_si512(D1_14,mask52);
	D1_14 = _mm512_sub_epi64(D1_14,borrow);
	borrow  = _mm512_srli_epi64(D1_14,52)&un;
	D1_14 = _mm512_and_si512(D1_14,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_15);
	borrow = _mm512_add_epi64(borrow,D0_15);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_15 = _mm512_add_epi64(D1_15,carry_D1);
	D1_15 = _mm512_add_epi64(D1_15,D0_55);
	carry_D1 = _mm512_srli_epi64(D1_15,52);
	D1_15 = _mm512_and_si512(D1_15,mask52);
	D1_15 = _mm512_sub_epi64(D1_15,borrow);
	borrow  = _mm512_srli_epi64(D1_15,52)&un;
	D1_15 = _mm512_and_si512(D1_15,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_16);
	borrow = _mm512_add_epi64(borrow,D0_16);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_16 = _mm512_add_epi64(D1_16,carry_D1);
	D1_16 = _mm512_add_epi64(D1_16,D0_56);
	carry_D1 = _mm512_srli_epi64(D1_16,52);
	D1_16 = _mm512_and_si512(D1_16,mask52);
	D1_16 = _mm512_sub_epi64(D1_16,borrow);
	borrow  = _mm512_srli_epi64(D1_16,52)&un;
	D1_16 = _mm512_and_si512(D1_16,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_17);
	borrow = _mm512_add_epi64(borrow,D0_17);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_17 = _mm512_add_epi64(D1_17,carry_D1);
	D1_17 = _mm512_add_epi64(D1_17,D0_57);
	carry_D1 = _mm512_srli_epi64(D1_17,52);
	D1_17 = _mm512_and_si512(D1_17,mask52);
	D1_17 = _mm512_sub_epi64(D1_17,borrow);
	borrow  = _mm512_srli_epi64(D1_17,52)&un;
	D1_17 = _mm512_and_si512(D1_17,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_18);
	borrow = _mm512_add_epi64(borrow,D0_18);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_18 = _mm512_add_epi64(D1_18,carry_D1);
	D1_18 = _mm512_add_epi64(D1_18,D0_58);
	carry_D1 = _mm512_srli_epi64(D1_18,52);
	D1_18 = _mm512_and_si512(D1_18,mask52);
	D1_18 = _mm512_sub_epi64(D1_18,borrow);
	borrow  = _mm512_srli_epi64(D1_18,52)&un;
	D1_18 = _mm512_and_si512(D1_18,mask52);

	borrow = _mm512_add_epi64(carry,borrow); // radix 2^1039
	borrow = _mm512_add_epi64(borrow,D2_19);
	borrow = _mm512_add_epi64(borrow,D0_19);
	carry = _mm512_srli_epi64(borrow,51);
	borrow = _mm512_and_si512(borrow,mask51);
	D1_19 = _mm512_add_epi64(D1_19,carry_D1);
	D1_19 = _mm512_add_epi64(D1_19,D0_59);
	carry_D1 = _mm512_srli_epi64(D1_19,51);
	D1_19 = _mm512_and_si512(D1_19,mask51);
	D1_19 = _mm512_sub_epi64(D1_19,borrow);
	borrow  = _mm512_srli_epi64(D1_19,51)&un;
	D1_19 = _mm512_and_si512(D1_19,mask51);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_20);
	borrow = _mm512_add_epi64(borrow,D0_20);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_20 = _mm512_add_epi64(D1_20,carry_D1);
	D1_20 = _mm512_add_epi64(D1_20,D0_60);
	carry_D1 = _mm512_srli_epi64(D1_20,52);
	D1_20 = _mm512_and_si512(D1_20,mask52);
	D1_20 = _mm512_sub_epi64(D1_20,borrow);
	borrow  = _mm512_srli_epi64(D1_20,52)&un;
	D1_20 = _mm512_and_si512(D1_20,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_21);
	borrow = _mm512_add_epi64(borrow,D0_21);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_21 = _mm512_add_epi64(D1_21,carry_D1);
	D1_21 = _mm512_add_epi64(D1_21,D0_61);
	carry_D1 = _mm512_srli_epi64(D1_21,52);
	D1_21 = _mm512_and_si512(D1_21,mask52);
	D1_21 = _mm512_sub_epi64(D1_21,borrow);
	borrow  = _mm512_srli_epi64(D1_21,52)&un;
	D1_21 = _mm512_and_si512(D1_21,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_22);
	borrow = _mm512_add_epi64(borrow,D0_22);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_22 = _mm512_add_epi64(D1_22,carry_D1);
	D1_22 = _mm512_add_epi64(D1_22,D0_62);
	carry_D1 = _mm512_srli_epi64(D1_22,52);
	D1_22 = _mm512_and_si512(D1_22,mask52);
	D1_22 = _mm512_sub_epi64(D1_22,borrow);
	borrow  = _mm512_srli_epi64(D1_22,52)&un;
	D1_22 = _mm512_and_si512(D1_22,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_23);
	borrow = _mm512_add_epi64(borrow,D0_23);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_23 = _mm512_add_epi64(D1_23,carry_D1);
	D1_23 = _mm512_add_epi64(D1_23,D0_63);
	carry_D1 = _mm512_srli_epi64(D1_23,52);
	D1_23 = _mm512_and_si512(D1_23,mask52);
	D1_23 = _mm512_sub_epi64(D1_23,borrow);
	borrow  = _mm512_srli_epi64(D1_23,52)&un;
	D1_23 = _mm512_and_si512(D1_23,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_24);
	borrow = _mm512_add_epi64(borrow,D0_24);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_24 = _mm512_add_epi64(D1_24,carry_D1);
	D1_24 = _mm512_add_epi64(D1_24,D0_64);
	carry_D1 = _mm512_srli_epi64(D1_24,52);
	D1_24 = _mm512_and_si512(D1_24,mask52);
	D1_24 = _mm512_sub_epi64(D1_24,borrow);
	borrow  = _mm512_srli_epi64(D1_24,52)&un;
	D1_24 = _mm512_and_si512(D1_24,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_25);
	borrow = _mm512_add_epi64(borrow,D0_25);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_25 = _mm512_add_epi64(D1_25,carry_D1);
	D1_25 = _mm512_add_epi64(D1_25,D0_65);
	carry_D1 = _mm512_srli_epi64(D1_25,52);
	D1_25 = _mm512_and_si512(D1_25,mask52);
	D1_25 = _mm512_sub_epi64(D1_25,borrow);
	borrow  = _mm512_srli_epi64(D1_25,52)&un;
	D1_25 = _mm512_and_si512(D1_25,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_26);
	borrow = _mm512_add_epi64(borrow,D0_26);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_26 = _mm512_add_epi64(D1_26,carry_D1);
	D1_26 = _mm512_add_epi64(D1_26,D0_66);
	carry_D1 = _mm512_srli_epi64(D1_26,52);
	D1_26 = _mm512_and_si512(D1_26,mask52);
	D1_26 = _mm512_sub_epi64(D1_26,borrow);
	borrow  = _mm512_srli_epi64(D1_26,52)&un;
	D1_26 = _mm512_and_si512(D1_26,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_27);
	borrow = _mm512_add_epi64(borrow,D0_27);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_27 = _mm512_add_epi64(D1_27,carry_D1);
	D1_27 = _mm512_add_epi64(D1_27,D0_67);
	carry_D1 = _mm512_srli_epi64(D1_27,52);
	D1_27 = _mm512_and_si512(D1_27,mask52);
	D1_27 = _mm512_sub_epi64(D1_27,borrow);
	borrow  = _mm512_srli_epi64(D1_27,52)&un;
	D1_27 = _mm512_and_si512(D1_27,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_28);
	borrow = _mm512_add_epi64(borrow,D0_28);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_28 = _mm512_add_epi64(D1_28,carry_D1);
	D1_28 = _mm512_add_epi64(D1_28,D0_68);
	carry_D1 = _mm512_srli_epi64(D1_28,52);
	D1_28 = _mm512_and_si512(D1_28,mask52);
	D1_28 = _mm512_sub_epi64(D1_28,borrow);
	borrow  = _mm512_srli_epi64(D1_28,52)&un;
	D1_28 = _mm512_and_si512(D1_28,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_29);
	borrow = _mm512_add_epi64(borrow,D0_29);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_29 = _mm512_add_epi64(D1_29,carry_D1);
	D1_29 = _mm512_add_epi64(D1_29,D0_69);
	carry_D1 = _mm512_srli_epi64(D1_29,52);
	D1_29 = _mm512_and_si512(D1_29,mask52);
	D1_29 = _mm512_sub_epi64(D1_29,borrow);
	borrow  = _mm512_srli_epi64(D1_29,52)&un;
	D1_29 = _mm512_and_si512(D1_29,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_30);
	borrow = _mm512_add_epi64(borrow,D0_30);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_30 = _mm512_add_epi64(D1_30,carry_D1);
	D1_30 = _mm512_add_epi64(D1_30,D0_70);
	carry_D1 = _mm512_srli_epi64(D1_30,52);
	D1_30 = _mm512_and_si512(D1_30,mask52);
	D1_30 = _mm512_sub_epi64(D1_30,borrow);
	borrow  = _mm512_srli_epi64(D1_30,52)&un;
	D1_30 = _mm512_and_si512(D1_30,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_31);
	borrow = _mm512_add_epi64(borrow,D0_31);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_31 = _mm512_add_epi64(D1_31,carry_D1);
	D1_31 = _mm512_add_epi64(D1_31,D0_71);
	carry_D1 = _mm512_srli_epi64(D1_31,52);
	D1_31 = _mm512_and_si512(D1_31,mask52);
	D1_31 = _mm512_sub_epi64(D1_31,borrow);
	borrow  = _mm512_srli_epi64(D1_31,52)&un;
	D1_31 = _mm512_and_si512(D1_31,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_32);
	borrow = _mm512_add_epi64(borrow,D0_32);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_32 = _mm512_add_epi64(D1_32,carry_D1);
	D1_32 = _mm512_add_epi64(D1_32,D0_72);
	carry_D1 = _mm512_srli_epi64(D1_32,52);
	D1_32 = _mm512_and_si512(D1_32,mask52);
	D1_32 = _mm512_sub_epi64(D1_32,borrow);
	borrow  = _mm512_srli_epi64(D1_32,52)&un;
	D1_32 = _mm512_and_si512(D1_32,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_33);
	borrow = _mm512_add_epi64(borrow,D0_33);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_33 = _mm512_add_epi64(D1_33,carry_D1);
	D1_33 = _mm512_add_epi64(D1_33,D0_73);
	carry_D1 = _mm512_srli_epi64(D1_33,52);
	D1_33 = _mm512_and_si512(D1_33,mask52);
	D1_33 = _mm512_sub_epi64(D1_33,borrow);
	borrow  = _mm512_srli_epi64(D1_33,52)&un;
	D1_33 = _mm512_and_si512(D1_33,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_34);
	borrow = _mm512_add_epi64(borrow,D0_34);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_34 = _mm512_add_epi64(D1_34,carry_D1);
	D1_34 = _mm512_add_epi64(D1_34,D0_74);
	carry_D1 = _mm512_srli_epi64(D1_34,52);
	D1_34 = _mm512_and_si512(D1_34,mask52);
	D1_34 = _mm512_sub_epi64(D1_34,borrow);
	borrow  = _mm512_srli_epi64(D1_34,52)&un;
	D1_34 = _mm512_and_si512(D1_34,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_35);
	borrow = _mm512_add_epi64(borrow,D0_35);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_35 = _mm512_add_epi64(D1_35,carry_D1);
	D1_35 = _mm512_add_epi64(D1_35,D0_75);
	carry_D1 = _mm512_srli_epi64(D1_35,52);
	D1_35 = _mm512_and_si512(D1_35,mask52);
	D1_35 = _mm512_sub_epi64(D1_35,borrow);
	borrow  = _mm512_srli_epi64(D1_35,52)&un;
	D1_35 = _mm512_and_si512(D1_35,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_36);
	borrow = _mm512_add_epi64(borrow,D0_36);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_36 = _mm512_add_epi64(D1_36,carry_D1);
	D1_36 = _mm512_add_epi64(D1_36,D0_76);
	carry_D1 = _mm512_srli_epi64(D1_36,52);
	D1_36 = _mm512_and_si512(D1_36,mask52);
	D1_36 = _mm512_sub_epi64(D1_36,borrow);
	borrow  = _mm512_srli_epi64(D1_36,52)&un;
	D1_36 = _mm512_and_si512(D1_36,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_37);
	borrow = _mm512_add_epi64(borrow,D0_37);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_37 = _mm512_add_epi64(D1_37,carry_D1);
	D1_37 = _mm512_add_epi64(D1_37,D0_77);
	carry_D1 = _mm512_srli_epi64(D1_37,52);
	D1_37 = _mm512_and_si512(D1_37,mask52);
	D1_37 = _mm512_sub_epi64(D1_37,borrow);
	borrow  = _mm512_srli_epi64(D1_37,52)&un;
	D1_37 = _mm512_and_si512(D1_37,mask52);//*/

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_38);
	borrow = _mm512_add_epi64(borrow,D0_38);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_38 = _mm512_add_epi64(D1_38,carry_D1);
	D1_38 = _mm512_add_epi64(D1_38,D0_78);
	carry_D1 = _mm512_srli_epi64(D1_38,52);
	D1_38 = _mm512_and_si512(D1_38,mask52);
	D1_38 = _mm512_sub_epi64(D1_38,borrow);
	borrow  = _mm512_srli_epi64(D1_38,52)&un;
	D1_38 = _mm512_and_si512(D1_38,mask52);

	borrow = _mm512_add_epi64(carry,borrow); // radix 2^2077
	borrow = _mm512_add_epi64(borrow,D2_39);
	borrow = _mm512_add_epi64(borrow,D0_39);
	carry = _mm512_srli_epi64(borrow,50);
	borrow = _mm512_and_si512(borrow,mask50);
	D1_39 = _mm512_add_epi64(D1_39,carry_D1);
	D1_39 = _mm512_add_epi64(D1_39,D0_79);
	carry_D1 = _mm512_srli_epi64(D1_39,50);
	D1_39 = _mm512_and_si512(D1_39,mask50);
	D1_39 = _mm512_sub_epi64(D1_39,borrow);
	borrow  = _mm512_srli_epi64(D1_39,50)&un;
	D1_39 = _mm512_and_si512(D1_39,mask50);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_40);
	borrow = _mm512_add_epi64(borrow,D0_40);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_40 = _mm512_add_epi64(D1_40,carry_D1);
	D1_40 = _mm512_add_epi64(D1_40,D2_0);
	carry_D1 = _mm512_srli_epi64(D1_40,52);
	D1_40 = _mm512_and_si512(D1_40,mask52);
	D1_40 = _mm512_sub_epi64(D1_40,borrow);
	borrow  = _mm512_srli_epi64(D1_40,52)&un;
	D1_40 = _mm512_and_si512(D1_40,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_41);
	borrow = _mm512_add_epi64(borrow,D0_41);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_41 = _mm512_add_epi64(D1_41,carry_D1);
	D1_41 = _mm512_add_epi64(D1_41,D2_1);
	carry_D1 = _mm512_srli_epi64(D1_41,52);
	D1_41 = _mm512_and_si512(D1_41,mask52);
	D1_41 = _mm512_sub_epi64(D1_41,borrow);
	borrow  = _mm512_srli_epi64(D1_41,52)&un;
	D1_41 = _mm512_and_si512(D1_41,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_42);
	borrow = _mm512_add_epi64(borrow,D0_42);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_42 = _mm512_add_epi64(D1_42,carry_D1);
	D1_42 = _mm512_add_epi64(D1_42,D2_2);
	carry_D1 = _mm512_srli_epi64(D1_42,52);
	D1_42 = _mm512_and_si512(D1_42,mask52);
	D1_42 = _mm512_sub_epi64(D1_42,borrow);
	borrow  = _mm512_srli_epi64(D1_42,52)&un;
	D1_42 = _mm512_and_si512(D1_42,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_43);
	borrow = _mm512_add_epi64(borrow,D0_43);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_43 = _mm512_add_epi64(D1_43,carry_D1);
	D1_43 = _mm512_add_epi64(D1_43,D2_3);
	carry_D1 = _mm512_srli_epi64(D1_43,52);
	D1_43 = _mm512_and_si512(D1_43,mask52);
	D1_43 = _mm512_sub_epi64(D1_43,borrow);
	borrow  = _mm512_srli_epi64(D1_43,52)&un;
	D1_43 = _mm512_and_si512(D1_43,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_44);
	borrow = _mm512_add_epi64(borrow,D0_44);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_44 = _mm512_add_epi64(D1_44,carry_D1);
	D1_44 = _mm512_add_epi64(D1_44,D2_4);
	carry_D1 = _mm512_srli_epi64(D1_44,52);
	D1_44 = _mm512_and_si512(D1_44,mask52);
	D1_44 = _mm512_sub_epi64(D1_44,borrow);
	borrow  = _mm512_srli_epi64(D1_44,52)&un;
	D1_44 = _mm512_and_si512(D1_44,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_45);
	borrow = _mm512_add_epi64(borrow,D0_45);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_45 = _mm512_add_epi64(D1_45,carry_D1);
	D1_45 = _mm512_add_epi64(D1_45,D2_5);
	carry_D1 = _mm512_srli_epi64(D1_45,52);
	D1_45 = _mm512_and_si512(D1_45,mask52);
	D1_45 = _mm512_sub_epi64(D1_45,borrow);
	borrow  = _mm512_srli_epi64(D1_45,52)&un;
	D1_45 = _mm512_and_si512(D1_45,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_46);
	borrow = _mm512_add_epi64(borrow,D0_46);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_46 = _mm512_add_epi64(D1_46,carry_D1);
	D1_46 = _mm512_add_epi64(D1_46,D2_6);
	carry_D1 = _mm512_srli_epi64(D1_46,52);
	D1_46 = _mm512_and_si512(D1_46,mask52);
	D1_46 = _mm512_sub_epi64(D1_46,borrow);
	borrow  = _mm512_srli_epi64(D1_46,52)&un;
	D1_46 = _mm512_and_si512(D1_46,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_47);
	borrow = _mm512_add_epi64(borrow,D0_47);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_47 = _mm512_add_epi64(D1_47,carry_D1);
	D1_47 = _mm512_add_epi64(D1_47,D2_7);
	carry_D1 = _mm512_srli_epi64(D1_47,52);
	D1_47 = _mm512_and_si512(D1_47,mask52);
	D1_47 = _mm512_sub_epi64(D1_47,borrow);
	borrow  = _mm512_srli_epi64(D1_47,52)&un;
	D1_47 = _mm512_and_si512(D1_47,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_48);
	borrow = _mm512_add_epi64(borrow,D0_48);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_48 = _mm512_add_epi64(D1_48,carry_D1);
	D1_48 = _mm512_add_epi64(D1_48,D2_8);
	carry_D1 = _mm512_srli_epi64(D1_48,52);
	D1_48 = _mm512_and_si512(D1_48,mask52);
	D1_48 = _mm512_sub_epi64(D1_48,borrow);
	borrow  = _mm512_srli_epi64(D1_48,52)&un;
	D1_48 = _mm512_and_si512(D1_48,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_49);
	borrow = _mm512_add_epi64(borrow,D0_49);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_49 = _mm512_add_epi64(D1_49,carry_D1);
	D1_49 = _mm512_add_epi64(D1_49,D2_9);
	carry_D1 = _mm512_srli_epi64(D1_49,52);
	D1_49 = _mm512_and_si512(D1_49,mask52);
	D1_49 = _mm512_sub_epi64(D1_49,borrow);
	borrow  = _mm512_srli_epi64(D1_49,52)&un;
	D1_49 = _mm512_and_si512(D1_49,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_50);
	borrow = _mm512_add_epi64(borrow,D0_50);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_50 = _mm512_add_epi64(D1_50,carry_D1);
	D1_50 = _mm512_add_epi64(D1_50,D2_10);
	carry_D1 = _mm512_srli_epi64(D1_50,52);
	D1_50 = _mm512_and_si512(D1_50,mask52);
	D1_50 = _mm512_sub_epi64(D1_50,borrow);
	borrow  = _mm512_srli_epi64(D1_50,52)&un;
	D1_50 = _mm512_and_si512(D1_50,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_51);
	borrow = _mm512_add_epi64(borrow,D0_51);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_51 = _mm512_add_epi64(D1_51,carry_D1);
	D1_51 = _mm512_add_epi64(D1_51,D2_11);
	carry_D1 = _mm512_srli_epi64(D1_51,52);
	D1_51 = _mm512_and_si512(D1_51,mask52);
	D1_51 = _mm512_sub_epi64(D1_51,borrow);
	borrow  = _mm512_srli_epi64(D1_51,52)&un;
	D1_51 = _mm512_and_si512(D1_51,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_52);
	borrow = _mm512_add_epi64(borrow,D0_52);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_52 = _mm512_add_epi64(D1_52,carry_D1);
	D1_52 = _mm512_add_epi64(D1_52,D2_12);
	carry_D1 = _mm512_srli_epi64(D1_52,52);
	D1_52 = _mm512_and_si512(D1_52,mask52);
	D1_52 = _mm512_sub_epi64(D1_52,borrow);
	borrow  = _mm512_srli_epi64(D1_52,52)&un;
	D1_52 = _mm512_and_si512(D1_52,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_53);
	borrow = _mm512_add_epi64(borrow,D0_53);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_53 = _mm512_add_epi64(D1_53,carry_D1);
	D1_53 = _mm512_add_epi64(D1_53,D2_13);
	carry_D1 = _mm512_srli_epi64(D1_53,52);
	D1_53 = _mm512_and_si512(D1_53,mask52);
	D1_53 = _mm512_sub_epi64(D1_53,borrow);
	borrow  = _mm512_srli_epi64(D1_53,52)&un;
	D1_53 = _mm512_and_si512(D1_53,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_54);
	borrow = _mm512_add_epi64(borrow,D0_54);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_54 = _mm512_add_epi64(D1_54,carry_D1);
	D1_54 = _mm512_add_epi64(D1_54,D2_14);
	carry_D1 = _mm512_srli_epi64(D1_54,52);
	D1_54 = _mm512_and_si512(D1_54,mask52);
	D1_54 = _mm512_sub_epi64(D1_54,borrow);
	borrow  = _mm512_srli_epi64(D1_54,52)&un;
	D1_54 = _mm512_and_si512(D1_54,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_55);
	borrow = _mm512_add_epi64(borrow,D0_55);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_55 = _mm512_add_epi64(D1_55,carry_D1);
	D1_55 = _mm512_add_epi64(D1_55,D2_15);
	carry_D1 = _mm512_srli_epi64(D1_55,52);
	D1_55 = _mm512_and_si512(D1_55,mask52);
	D1_55 = _mm512_sub_epi64(D1_55,borrow);
	borrow  = _mm512_srli_epi64(D1_55,52)&un;
	D1_55 = _mm512_and_si512(D1_55,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_56);
	borrow = _mm512_add_epi64(borrow,D0_56);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_56 = _mm512_add_epi64(D1_56,carry_D1);
	D1_56 = _mm512_add_epi64(D1_56,D2_16);
	carry_D1 = _mm512_srli_epi64(D1_56,52);
	D1_56 = _mm512_and_si512(D1_56,mask52);
	D1_56 = _mm512_sub_epi64(D1_56,borrow);
	borrow  = _mm512_srli_epi64(D1_56,52)&un;
	D1_56 = _mm512_and_si512(D1_56,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_57);
	borrow = _mm512_add_epi64(borrow,D0_57);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_57 = _mm512_add_epi64(D1_57,carry_D1);
	D1_57 = _mm512_add_epi64(D1_57,D2_17);
	carry_D1 = _mm512_srli_epi64(D1_57,52);
	D1_57 = _mm512_and_si512(D1_57,mask52);
	D1_57 = _mm512_sub_epi64(D1_57,borrow);
	borrow  = _mm512_srli_epi64(D1_57,52)&un;
	D1_57 = _mm512_and_si512(D1_57,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_58);
	borrow = _mm512_add_epi64(borrow,D0_58);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_58 = _mm512_add_epi64(D1_58,carry_D1);
	D1_58 = _mm512_add_epi64(D1_58,D2_18);
	carry_D1 = _mm512_srli_epi64(D1_58,52);
	D1_58 = _mm512_and_si512(D1_58,mask52);
	D1_58 = _mm512_sub_epi64(D1_58,borrow);
	borrow  = _mm512_srli_epi64(D1_58,52)&un;
	D1_58 = _mm512_and_si512(D1_58,mask52);

	borrow = _mm512_add_epi64(carry,borrow); // radix 2^1039
	borrow = _mm512_add_epi64(borrow,D2_59);
	borrow = _mm512_add_epi64(borrow,D0_59);
	carry = _mm512_srli_epi64(borrow,51);
	borrow = _mm512_and_si512(borrow,mask51);
	D1_59 = _mm512_add_epi64(D1_59,carry_D1);
	D1_59 = _mm512_add_epi64(D1_59,D2_19);
	carry_D1 = _mm512_srli_epi64(D1_59,51);
	D1_59 = _mm512_and_si512(D1_59,mask51);
	D1_59 = _mm512_sub_epi64(D1_59,borrow);
	borrow  = _mm512_srli_epi64(D1_59,51)&un;
	D1_59 = _mm512_and_si512(D1_59,mask51);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_60);
	borrow = _mm512_add_epi64(borrow,D0_60);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_60 = _mm512_add_epi64(D1_60,carry_D1);
	D1_60 = _mm512_add_epi64(D1_60,D2_20);
	carry_D1 = _mm512_srli_epi64(D1_60,52);
	D1_60 = _mm512_and_si512(D1_60,mask52);
	D1_60 = _mm512_sub_epi64(D1_60,borrow);
	borrow  = _mm512_srli_epi64(D1_60,52)&un;
	D1_60 = _mm512_and_si512(D1_60,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_61);
	borrow = _mm512_add_epi64(borrow,D0_61);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_61 = _mm512_add_epi64(D1_61,carry_D1);
	D1_61 = _mm512_add_epi64(D1_61,D2_21);
	carry_D1 = _mm512_srli_epi64(D1_61,52);
	D1_61 = _mm512_and_si512(D1_61,mask52);
	D1_61 = _mm512_sub_epi64(D1_61,borrow);
	borrow  = _mm512_srli_epi64(D1_61,52)&un;
	D1_61 = _mm512_and_si512(D1_61,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_62);
	borrow = _mm512_add_epi64(borrow,D0_62);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_62 = _mm512_add_epi64(D1_62,carry_D1);
	D1_62 = _mm512_add_epi64(D1_62,D2_22);
	carry_D1 = _mm512_srli_epi64(D1_62,52);
	D1_62 = _mm512_and_si512(D1_62,mask52);
	D1_62 = _mm512_sub_epi64(D1_62,borrow);
	borrow  = _mm512_srli_epi64(D1_62,52)&un;
	D1_62 = _mm512_and_si512(D1_62,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_63);
	borrow = _mm512_add_epi64(borrow,D0_63);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_63 = _mm512_add_epi64(D1_63,carry_D1);
	D1_63 = _mm512_add_epi64(D1_63,D2_23);
	carry_D1 = _mm512_srli_epi64(D1_63,52);
	D1_63 = _mm512_and_si512(D1_63,mask52);
	D1_63 = _mm512_sub_epi64(D1_63,borrow);
	borrow  = _mm512_srli_epi64(D1_63,52)&un;
	D1_63 = _mm512_and_si512(D1_63,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_64);
	borrow = _mm512_add_epi64(borrow,D0_64);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_64 = _mm512_add_epi64(D1_64,carry_D1);
	D1_64 = _mm512_add_epi64(D1_64,D2_24);
	carry_D1 = _mm512_srli_epi64(D1_64,52);
	D1_64 = _mm512_and_si512(D1_64,mask52);
	D1_64 = _mm512_sub_epi64(D1_64,borrow);
	borrow  = _mm512_srli_epi64(D1_64,52)&un;
	D1_64 = _mm512_and_si512(D1_64,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_65);
	borrow = _mm512_add_epi64(borrow,D0_65);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_65 = _mm512_add_epi64(D1_65,carry_D1);
	D1_65 = _mm512_add_epi64(D1_65,D2_25);
	carry_D1 = _mm512_srli_epi64(D1_65,52);
	D1_65 = _mm512_and_si512(D1_65,mask52);
	D1_65 = _mm512_sub_epi64(D1_65,borrow);
	borrow  = _mm512_srli_epi64(D1_65,52)&un;
	D1_65 = _mm512_and_si512(D1_65,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_66);
	borrow = _mm512_add_epi64(borrow,D0_66);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_66 = _mm512_add_epi64(D1_66,carry_D1);
	D1_66 = _mm512_add_epi64(D1_66,D2_26);
	carry_D1 = _mm512_srli_epi64(D1_66,52);
	D1_66 = _mm512_and_si512(D1_66,mask52);
	D1_66 = _mm512_sub_epi64(D1_66,borrow);
	borrow  = _mm512_srli_epi64(D1_66,52)&un;
	D1_66 = _mm512_and_si512(D1_66,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_67);
	borrow = _mm512_add_epi64(borrow,D0_67);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_67 = _mm512_add_epi64(D1_67,carry_D1);
	D1_67 = _mm512_add_epi64(D1_67,D2_27);
	carry_D1 = _mm512_srli_epi64(D1_67,52);
	D1_67 = _mm512_and_si512(D1_67,mask52);
	D1_67 = _mm512_sub_epi64(D1_67,borrow);
	borrow  = _mm512_srli_epi64(D1_67,52)&un;
	D1_67 = _mm512_and_si512(D1_67,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_68);
	borrow = _mm512_add_epi64(borrow,D0_68);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_68 = _mm512_add_epi64(D1_68,carry_D1);
	D1_68 = _mm512_add_epi64(D1_68,D2_28);
	carry_D1 = _mm512_srli_epi64(D1_68,52);
	D1_68 = _mm512_and_si512(D1_68,mask52);
	D1_68 = _mm512_sub_epi64(D1_68,borrow);
	borrow  = _mm512_srli_epi64(D1_68,52)&un;
	D1_68 = _mm512_and_si512(D1_68,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_69);
	borrow = _mm512_add_epi64(borrow,D0_69);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_69 = _mm512_add_epi64(D1_69,carry_D1);
	D1_69 = _mm512_add_epi64(D1_69,D2_29);
	carry_D1 = _mm512_srli_epi64(D1_69,52);
	D1_69 = _mm512_and_si512(D1_69,mask52);
	D1_69 = _mm512_sub_epi64(D1_69,borrow);
	borrow  = _mm512_srli_epi64(D1_69,52)&un;
	D1_69 = _mm512_and_si512(D1_69,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_70);
	borrow = _mm512_add_epi64(borrow,D0_70);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_70 = _mm512_add_epi64(D1_70,carry_D1);
	D1_70 = _mm512_add_epi64(D1_70,D2_30);
	carry_D1 = _mm512_srli_epi64(D1_70,52);
	D1_70 = _mm512_and_si512(D1_70,mask52);
	D1_70 = _mm512_sub_epi64(D1_70,borrow);
	borrow  = _mm512_srli_epi64(D1_70,52)&un;
	D1_70 = _mm512_and_si512(D1_70,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_71);
	borrow = _mm512_add_epi64(borrow,D0_71);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_71 = _mm512_add_epi64(D1_71,carry_D1);
	D1_71 = _mm512_add_epi64(D1_71,D2_31);
	carry_D1 = _mm512_srli_epi64(D1_71,52);
	D1_71 = _mm512_and_si512(D1_71,mask52);
	D1_71 = _mm512_sub_epi64(D1_71,borrow);
	borrow  = _mm512_srli_epi64(D1_71,52)&un;
	D1_71 = _mm512_and_si512(D1_71,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_72);
	borrow = _mm512_add_epi64(borrow,D0_72);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_72 = _mm512_add_epi64(D1_72,carry_D1);
	D1_72 = _mm512_add_epi64(D1_72,D2_32);
	carry_D1 = _mm512_srli_epi64(D1_72,52);
	D1_72 = _mm512_and_si512(D1_72,mask52);
	D1_72 = _mm512_sub_epi64(D1_72,borrow);
	borrow  = _mm512_srli_epi64(D1_72,52)&un;
	D1_72 = _mm512_and_si512(D1_72,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_73);
	borrow = _mm512_add_epi64(borrow,D0_73);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_73 = _mm512_add_epi64(D1_73,carry_D1);
	D1_73 = _mm512_add_epi64(D1_73,D2_33);
	carry_D1 = _mm512_srli_epi64(D1_73,52);
	D1_73 = _mm512_and_si512(D1_73,mask52);
	D1_73 = _mm512_sub_epi64(D1_73,borrow);
	borrow  = _mm512_srli_epi64(D1_73,52)&un;
	D1_73 = _mm512_and_si512(D1_73,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_74);
	borrow = _mm512_add_epi64(borrow,D0_74);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_74 = _mm512_add_epi64(D1_74,carry_D1);
	D1_74 = _mm512_add_epi64(D1_74,D2_34);
	carry_D1 = _mm512_srli_epi64(D1_74,52);
	D1_74 = _mm512_and_si512(D1_74,mask52);
	D1_74 = _mm512_sub_epi64(D1_74,borrow);
	borrow  = _mm512_srli_epi64(D1_74,52)&un;
	D1_74 = _mm512_and_si512(D1_74,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_75);
	borrow = _mm512_add_epi64(borrow,D0_75);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_75 = _mm512_add_epi64(D1_75,carry_D1);
	D1_75 = _mm512_add_epi64(D1_75,D2_35);
	carry_D1 = _mm512_srli_epi64(D1_75,52);
	D1_75 = _mm512_and_si512(D1_75,mask52);
	D1_75 = _mm512_sub_epi64(D1_75,borrow);
	borrow  = _mm512_srli_epi64(D1_75,52)&un;
	D1_75 = _mm512_and_si512(D1_75,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_76);
	borrow = _mm512_add_epi64(borrow,D0_76);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_76 = _mm512_add_epi64(D1_76,carry_D1);
	D1_76 = _mm512_add_epi64(D1_76,D2_36);
	carry_D1 = _mm512_srli_epi64(D1_76,52);
	D1_76 = _mm512_and_si512(D1_76,mask52);
	D1_76 = _mm512_sub_epi64(D1_76,borrow);
	borrow  = _mm512_srli_epi64(D1_76,52)&un;
	D1_76 = _mm512_and_si512(D1_76,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_77);
	borrow = _mm512_add_epi64(borrow,D0_77);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_77 = _mm512_add_epi64(D1_77,carry_D1);
	D1_77 = _mm512_add_epi64(D1_77,D2_37);
	carry_D1 = _mm512_srli_epi64(D1_77,52);
	D1_77 = _mm512_and_si512(D1_77,mask52);
	D1_77 = _mm512_sub_epi64(D1_77,borrow);
	borrow  = _mm512_srli_epi64(D1_77,52)&un;
	D1_77 = _mm512_and_si512(D1_77,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_78);
	borrow = _mm512_add_epi64(borrow,D0_78);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_78 = _mm512_add_epi64(D1_78,carry_D1);
	D1_78 = _mm512_add_epi64(D1_78,D2_38);
	carry_D1 = _mm512_srli_epi64(D1_78,52);
	D1_78 = _mm512_and_si512(D1_78,mask52);
	D1_78 = _mm512_sub_epi64(D1_78,borrow);
	borrow  = _mm512_srli_epi64(D1_78,52)&un;
	D1_78 = _mm512_and_si512(D1_78,mask52);

	borrow = _mm512_add_epi64(carry,borrow); // radix 2^2077
	borrow = _mm512_add_epi64(borrow,D2_79);
	borrow = _mm512_add_epi64(borrow,D0_79);
	carry = _mm512_srli_epi64(borrow,50);
	borrow = _mm512_and_si512(borrow,mask50);
	D1_79 = _mm512_add_epi64(D1_79,carry_D1);
	D1_79 = _mm512_add_epi64(D1_79,D2_39);
	carry_D1 = _mm512_srli_epi64(D1_79,50);
	D1_79 = _mm512_and_si512(D1_79,mask50);
	D1_79 = _mm512_sub_epi64(D1_79,borrow);
	borrow  = _mm512_srli_epi64(D1_79,50)&un;
	D1_79 = _mm512_and_si512(D1_79,mask50);


	// Final borrows
	D2_40 = _mm512_add_epi64(D2_40,carry_D1);
	
	borrow = _mm512_add_epi64(carry,borrow);
	D2_40 = _mm512_sub_epi64(D2_40,borrow);
	//borrow  = _mm512_srli_epi64(D2_40,52)&un;
	D2_40 = _mm512_and_si512(D2_40,mask52);//*/
	
	
	

	/*borrow = _mm512_add_epi64(carry_tmp,borrow);
	D2_40 = _mm512_add_epi64(D2_40,carry);
	D2_40 = _mm512_sub_epi64(D2_40,borrow);
	borrow  = _mm512_srli_epi64(D2_40,52)&un;
	D2_40 = _mm512_and_si512(D2_40,mask52);*/







	
	//borrow  = _mm512_srli_epi64(out_44,52)&un;
	//out_44 = _mm512_and_si512(out_44,mask52);
	
	
	

	
	/*_mm512_store_epi64(out+0,D0_0);
	_mm512_store_epi64(out+1,D0_1);
	_mm512_store_epi64(out+2,D0_2);
	_mm512_store_epi64(out+3,D0_3);
	_mm512_store_epi64(out+4,D0_4);
	_mm512_store_epi64(out+5,D0_5);
	_mm512_store_epi64(out+6,D0_6);
	_mm512_store_epi64(out+7,D0_7);
	_mm512_store_epi64(out+8,D0_8);
	_mm512_store_epi64(out+9,D0_9);
	_mm512_store_epi64(out+10,D0_10);
	_mm512_store_epi64(out+11,D0_11);
	_mm512_store_epi64(out+12,D0_12);
	_mm512_store_epi64(out+13,D0_13);
	_mm512_store_epi64(out+14,D0_14);
	_mm512_store_epi64(out+15,D0_15);
	_mm512_store_epi64(out+16,D0_16);
	_mm512_store_epi64(out+17,D0_17);
	_mm512_store_epi64(out+18,D0_18);
	_mm512_store_epi64(out+19,D0_19);
	_mm512_store_epi64(out+20,D0_20);
	_mm512_store_epi64(out+21,D0_21);
	_mm512_store_epi64(out+22,D0_22);
	_mm512_store_epi64(out+23,D0_23);
	_mm512_store_epi64(out+24,D0_24);
	_mm512_store_epi64(out+25,D0_25);
	_mm512_store_epi64(out+26,D0_26);
	_mm512_store_epi64(out+27,D0_27);
	_mm512_store_epi64(out+28,D0_28);
	_mm512_store_epi64(out+29,D0_29);
	_mm512_store_epi64(out+30,D0_30);
	_mm512_store_epi64(out+31,D0_31);
	_mm512_store_epi64(out+32,D0_32);
	_mm512_store_epi64(out+33,D0_33);
	_mm512_store_epi64(out+34,D0_34);
	_mm512_store_epi64(out+35,D0_35);
	_mm512_store_epi64(out+36,D0_36);
	_mm512_store_epi64(out+37,D0_37);
	_mm512_store_epi64(out+38,D0_38);
	_mm512_store_epi64(out+39,D0_39);
	_mm512_store_epi64(out+40,D1_0);
	_mm512_store_epi64(out+41,D1_1);
	_mm512_store_epi64(out+42,D1_2);
	_mm512_store_epi64(out+43,D1_3);
	_mm512_store_epi64(out+44,D1_4);
	_mm512_store_epi64(out+45,D1_5);
	_mm512_store_epi64(out+46,D1_6);
	_mm512_store_epi64(out+47,D1_7);
	_mm512_store_epi64(out+48,D1_8);
	_mm512_store_epi64(out+49,D1_9);
	_mm512_store_epi64(out+50,D1_10);
	_mm512_store_epi64(out+51,D1_11);
	_mm512_store_epi64(out+52,D1_12);
	_mm512_store_epi64(out+53,D1_13);
	_mm512_store_epi64(out+54,D1_14);
	_mm512_store_epi64(out+55,D1_15);
	_mm512_store_epi64(out+56,D1_16);
	_mm512_store_epi64(out+57,D1_17);
	_mm512_store_epi64(out+58,D1_18);
	_mm512_store_epi64(out+59,D1_19);
	_mm512_store_epi64(out+60,D1_20);
	_mm512_store_epi64(out+61,D1_21);
	_mm512_store_epi64(out+62,D1_22);
	_mm512_store_epi64(out+63,D1_23);
	_mm512_store_epi64(out+64,D1_24);
	_mm512_store_epi64(out+65,D1_25);
	_mm512_store_epi64(out+66,D1_26);
	_mm512_store_epi64(out+67,D1_27);
	_mm512_store_epi64(out+68,D1_28);
	_mm512_store_epi64(out+69,D1_29);
	_mm512_store_epi64(out+70,D1_30);
	_mm512_store_epi64(out+71,D1_31);
	_mm512_store_epi64(out+72,D1_32);
	_mm512_store_epi64(out+73,D1_33);
	_mm512_store_epi64(out+74,D1_34);
	_mm512_store_epi64(out+75,D1_35);
	_mm512_store_epi64(out+76,D1_36);
	_mm512_store_epi64(out+77,D1_37);//*/
	_mm512_store_epi64(out+78,D1_38);
	_mm512_store_epi64(out+79,D1_39);





	_mm512_store_epi64(out+80,D1_40);
	_mm512_store_epi64(out+81,D1_41);
	_mm512_store_epi64(out+82,D1_42);
	_mm512_store_epi64(out+83,D1_43);
	_mm512_store_epi64(out+84,D1_44);
	_mm512_store_epi64(out+85,D1_45);
	_mm512_store_epi64(out+86,D1_46);
	_mm512_store_epi64(out+87,D1_47);
	_mm512_store_epi64(out+88,D1_48);
	_mm512_store_epi64(out+89,D1_49);
	_mm512_store_epi64(out+90,D1_50);
	_mm512_store_epi64(out+91,D1_51);
	_mm512_store_epi64(out+92,D1_52);
	_mm512_store_epi64(out+93,D1_53);
	_mm512_store_epi64(out+94,D1_54);
	_mm512_store_epi64(out+95,D1_55);
	_mm512_store_epi64(out+96,D1_56);
	_mm512_store_epi64(out+97,D1_57);
	_mm512_store_epi64(out+98,D1_58);
	_mm512_store_epi64(out+99,D1_59);
	_mm512_store_epi64(out+100,D1_60);
	_mm512_store_epi64(out+101,D1_61);
	_mm512_store_epi64(out+102,D1_62);
	_mm512_store_epi64(out+103,D1_63);
	_mm512_store_epi64(out+104,D1_64);
	_mm512_store_epi64(out+105,D1_65);
	_mm512_store_epi64(out+106,D1_66);
	_mm512_store_epi64(out+107,D1_67);
	_mm512_store_epi64(out+108,D1_68);
	_mm512_store_epi64(out+109,D1_69);
	_mm512_store_epi64(out+110,D1_70);
	_mm512_store_epi64(out+111,D1_71);
	_mm512_store_epi64(out+112,D1_72);
	_mm512_store_epi64(out+113,D1_73);
	_mm512_store_epi64(out+114,D1_74);
	_mm512_store_epi64(out+115,D1_75);
	_mm512_store_epi64(out+116,D1_76);
	_mm512_store_epi64(out+117,D1_77);
	_mm512_store_epi64(out+118,D1_78);
	_mm512_store_epi64(out+119,D1_79);//*/
	_mm512_store_epi64(out+120,D2_40);
	_mm512_store_epi64(out+121,D2_41);
	_mm512_store_epi64(out+122,D2_42);
	_mm512_store_epi64(out+123,D2_43);
	_mm512_store_epi64(out+124,D2_44);
	_mm512_store_epi64(out+125,D2_45);
	_mm512_store_epi64(out+126,D2_46);
	_mm512_store_epi64(out+127,D2_47);
	_mm512_store_epi64(out+128,D2_48);
	_mm512_store_epi64(out+129,D2_49);
	_mm512_store_epi64(out+130,D2_50);
	_mm512_store_epi64(out+131,D2_51);
	_mm512_store_epi64(out+132,D2_52);
	_mm512_store_epi64(out+133,D2_53);
	_mm512_store_epi64(out+134,D2_54);
	_mm512_store_epi64(out+135,D2_55);
	_mm512_store_epi64(out+136,D2_56);
	_mm512_store_epi64(out+137,D2_57);
	_mm512_store_epi64(out+138,D2_58);
	_mm512_store_epi64(out+139,D2_59);
	_mm512_store_epi64(out+140,D2_60);
	_mm512_store_epi64(out+141,D2_61);
	_mm512_store_epi64(out+142,D2_62);
	_mm512_store_epi64(out+143,D2_63);
	_mm512_store_epi64(out+144,D2_64);
	_mm512_store_epi64(out+145,D2_65);
	_mm512_store_epi64(out+146,D2_66);
	_mm512_store_epi64(out+147,D2_67);
	_mm512_store_epi64(out+148,D2_68);
	_mm512_store_epi64(out+149,D2_69);
	_mm512_store_epi64(out+150,D2_70);
	_mm512_store_epi64(out+151,D2_71);
	_mm512_store_epi64(out+152,D2_72);
	_mm512_store_epi64(out+153,D2_73);
	_mm512_store_epi64(out+154,D2_74);
	_mm512_store_epi64(out+155,D2_75);
	_mm512_store_epi64(out+156,D2_76);
	_mm512_store_epi64(out+157,D2_77);
	_mm512_store_epi64(out+158,D2_78);
	_mm512_store_epi64(out+159,D2_79);

	/*
	unsigned long int a64_full[8][NB_COEFF64], b64_full[8][NB_COEFF64], res64_full[8][NB_COEFF64*2], res_gmp_full[NB_COEFF64*2];
	fcontract_8_512_4154KK_res(res64_full, out);
	//for(int i=0;i<8;i++)
	//		displayVect(res64_full[i],"res64[i]    ",NB_COEFF64*2);

	fcontract_8_512_4154KK(a64_full, a512);
	
	fcontract_8_512_4154KK(b64_full, b512);
	
	
	
	for(int i=0;i<8;i++)
	{

		mpz_import(A, NB_COEFF64, -1, sizeof(b64[0][0]) ,0,0, a64_full[i]);

		mpz_import(B, NB_COEFF64, -1, sizeof(b64[0][0]) ,0,0, b64_full[i]);
		
		gmp_printf("A  : 0x%ZX\n", A);

		displayVect(a64_full[i],"a64",65);
		printf("\n\n");
		
		gmp_printf("B  : 0x%ZX\n", B);
		displayVect(b64_full[i],"b64",65);
		printf("\n\n");
		
		
	
	
		mpz_mul(C,A,B);
		mpz_export(res_gmp_full, &countp, -1, sizeof(b64[0][0]) ,0,0, C);
		displayVect(res_gmp_full, "res_gmp     ",NB_COEFF64*2);
		displayVect(res64_full[i],"res64[i]    ",NB_COEFF64*2);
		
		
		printf("xor = ");
		for(int j=0;j<NB_COEFF64*2;j++){
			printf("%16.16lX ",res64_full[i][NB_COEFF64*2-1-j]^res_gmp_full[NB_COEFF64*2-1-j]);
		}
		printf("\n");

	//}
	//printf("\n");
	
	//for(int i=0;i<8;i++){//
		for(int j=0;j<NB_COEFF64*2;j++)
			if(res64_full[i][j]^res_gmp_full[j]) flag++;
		flag?counter++,flag=0:counter,flag=0;
		printf("\n");
	}
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory a*b !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;

	mpz_clears (A, B, C, NULL);

	//getchar();//*/
	
#undef DEBUG



}

