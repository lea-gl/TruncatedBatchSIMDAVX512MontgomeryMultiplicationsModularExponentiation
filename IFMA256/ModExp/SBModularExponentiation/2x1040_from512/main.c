#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <gmp.h>
#include <openssl/bn.h>

#include "gmp_stuff.c"


#include "ccount.h"
#include "tests.c"


#include "fonctions.h"
//#include "init.h"

#define BILLION 1000000000L

#define NSAMPLES 50

#define NTEST 100//0
//~ Compilation command : gcc -Wall -O3 main.c -o main -lgmp -lcrypto
//~ Execution command : ./main

//~ Important : polynomials representations form is P(X) = a0 + ... + an.X^n = (a0, ..., an).



void init_data(mpz_t modul_p, uint64_t *p_prime, mpz_t r2_gmp_256, mpz_t p_prime_2){

	printf("init_data()\n");

	mpz_inits (modul_p, p_prime_2, r2_gmp_256, NULL);

/*   Montgomery parameters !*/

	/*mpz_set_str(modul_p, "160972723171927582036369470573692317882263962264289327436117600647933834794071866355922995136221208373337063877139397174973541404699202479287894558737716315582156334754518576793758100380299484377545065602641280293746051310251117840035811339003898374190247020819416562412661784556177781523553136791098583640319",10);
	
	// pour Blck Montgomery
	p_prime[0] = 4210284071250177 ;
	
	
	mpz_set_str(r2_gmp_256, "129029726574983125600293265280190179054841030125212095147258823631628195392710763952834434299733288858768250214710695953986760423965618353359290445465689369073756708753998572254921905182210837813747921352207030012195975380525632571076064677522059293221081865498081898052295937352312306700012279707974821163700",10);
	
	//pour Montgomery classic (le squaring) mettre les bonne valeur !!!!!!!!
	mpz_set_str(p_prime_2, "10128146358263970479146492001882820589114526678418252974434633737831878496548736873993020797980041943919117033245992197732416790320141709709431098362376722811426999481091652725256206887307984856929786762799470682955035416633122370227817810734443181741089024097330335058460414892493308167659362130467712367408474369",10);
	//mpz_set_str(r2_gmp_256, "87085549980621981927888167997724522528031331813211185098757907011779742656178148700589543223693167423566822880572189724837952442676550386713789315056572037605301894758366342417417142244057088149886639979919090541397529286993473083041699137598218299469575583695400865139891750006670614694205686683757230878249",10);//*/
	
		
	// pour Blck Montgomery
	p_prime[0] = 4210284071250177 ;


	mpz_set_str(modul_p, "103620093203496370727261360994109075262312063022575872152499885113554673369441017201090018678385632649060805706851887639888737651045820758677284193703764980638472926677224861525610954431800543852467060668774394463727482816880847671286752112301477453159067742837950551302309426870531284885478039887524041003639",10);
	mpz_set_str(p_prime_2, "3348693064131296676513132763571664680240437224210689432747966569538784307222767799089472229205358267541431281745266256932846698483440840873587206152830317519171576004798991075677689075313444267683359600245618434435068728331206373776317356879228380147562305217672011456589928119522732309523655628996918202989254841",10);
	mpz_set_str(r2_gmp_256, "87085549980621981927888167997724522528031331813211185098757907011779742656178148700589543223693167423566822880572189724837952442676550386713789315056572037605301894758366342417417142244057088149886639979919090541397529286993473083041699137598218299469575583695400865139891750006670614694205686683757230878249",10);
	
	
	
	
}



void free_data(mpz_t modul_p, mpz_t p_prime_2, mpz_t r2_256){

	mpz_clears (modul_p, p_prime_2, r2_256, NULL);
	
}

int main(void){

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
 
	uint64_t mini, mini1, mini2, mini3, mini4, mini5, mini6;
 	unsigned long long int timer=0, timer1=0, timer2=0, timer3=0, timer4=0, timer5=0, timer6=0;
	

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

	
	int nb_limbs;

	uint64_t p_prime[1];// Block Montgomery
	static mpz_t modul_p, r2_gmp_256, p_prime2;// Classic Montgomery
	mpz_t A, B, C, E, F, R2, R3, G, H, UPB;
	mpz_inits (A, B, C, E, F, R2, R3, G, H, UPB, NULL);

	//mpz_inits (A, B, C, E, F, R2, R3, G, H, UPB, modul_p, p_prime, NULL);
	init_data(modul_p, p_prime, r2_gmp_256, p_prime2);
	
	mpz_ui_pow_ui ( UPB, 2UL, SIZE );
	
	
	printf("%lu %d  %d\n\n", mpz_sizeinbase (UPB, 2), NB_COEFF, NB_COEFF64);
	gmp_printf("UPB  : 0x%ZX\n\n\n", UPB);

	gmp_printf("modul_p  : 0x%ZX\n\n\n", modul_p);
	printf("p_prime  : 0x%lX\n\n\n", p_prime[0]);
	gmp_printf("r2_256   : 0x%ZX\n\n\n", r2_gmp_256	);
	
	
	printf("\t  /*******************************/\n");
	printf("\t /   Test sur 1 jeu de données   /\n");
	printf("\t/*******************************/\n\n");

	mp_limb_t mip0;
	
	const mp_limb_t *p_limbs;
	mp_limb_t *r2_limbs, *scratch_limbs, *mip_limbs;
	mp_limb_t *a_limbs, *b_limbs, *am1_limbs, *am2_limbs, *bm1_limbs, *bm2_limbs;
	
	mpz_urandomm(A, r, modul_p);
	mpz_urandomm(B, r, modul_p);
	mpz_set(E, A);

	
	nb_limbs = mpz_size (modul_p);
	
	printf("nb_limbs = %d\n",nb_limbs);
	
	p_limbs = mpz_limbs_read (modul_p);   
	
	binvert_limb (mip0, p_limbs[0]);
	mip0 = -mip0;
	
	mpz_setbit (R2, 2*nb_limbs*8*sizeof(mp_limb_t)); 
	mpz_mod(R2, R2, modul_p);
	r2_limbs = mpz_limbs_modify (R2, nb_limbs); 
	
	a_limbs = (mp_limb_t*) calloc (nb_limbs, sizeof(mp_limb_t));
	am1_limbs = (mp_limb_t*) calloc (nb_limbs, sizeof(mp_limb_t));
	am2_limbs = (mp_limb_t*) calloc (nb_limbs, sizeof(mp_limb_t));
	bm1_limbs = (mp_limb_t*) calloc (nb_limbs, sizeof(mp_limb_t));
	bm2_limbs = (mp_limb_t*) calloc (nb_limbs, sizeof(mp_limb_t));
	mip_limbs = (mp_limb_t*) calloc (nb_limbs, sizeof(mp_limb_t));
	scratch_limbs = (mp_limb_t*) calloc (2*nb_limbs, sizeof(mp_limb_t));

	b_limbs = mpz_limbs_modify (B, nb_limbs);
	copy_limbs(a_limbs, A, nb_limbs);
	copy_limbs(am1_limbs, A, nb_limbs);
	copy_limbs(am2_limbs, A, nb_limbs);
	copy_limbs(bm1_limbs, B, nb_limbs);
	copy_limbs(bm2_limbs, B, nb_limbs);
	
	mpn_binvert (mip_limbs, p_limbs, nb_limbs, scratch_limbs);
	

	/***********************************************/
	printf("\nGMP mult_mod :\n----------\n");
	gmp_printf("p       : %Zd\n\n", modul_p);
	gmp_printf("A       : %Zd\n", E);
	gmp_printf("B       : %Zd\n\n", B);

	//~ conversion to Montgomery domain (block mont)
	mpn_mont_mul_red_1(am1_limbs, am1_limbs, r2_limbs, p_limbs, mip0, nb_limbs);
	mpn_mont_mul_red_1(bm1_limbs, bm1_limbs, r2_limbs, p_limbs, mip0, nb_limbs);
	
	//~ Montgomery modular multiplication (block mont)
	mpn_mont_mul_red_1(am1_limbs, am1_limbs, bm1_limbs, p_limbs, mip0, nb_limbs);
	clean_limbs(scratch_limbs, 2*nb_limbs);
	for(int i=0; i<nb_limbs; i++)
		scratch_limbs[i] = am1_limbs[i];
	mpn_redc_1 (am1_limbs, scratch_limbs, p_limbs, nb_limbs, mip0);
	from_limbs_to_mpz_t(G, am1_limbs, nb_limbs);
	gmp_printf("r_mbgmp : %Zd\n", G);
	
	//~ conversion to Montgomery domain (classic mont)
	mpn_mont_mul_red_n(am2_limbs, am2_limbs, r2_limbs, p_limbs, mip_limbs, nb_limbs);
	mpn_mont_mul_red_n(bm2_limbs, bm2_limbs, r2_limbs, p_limbs, mip_limbs, nb_limbs);
	
	//~ Montgomery modular multiplication (classic mont)
	mpn_mont_mul_red_n(am2_limbs, am2_limbs, bm2_limbs, p_limbs, mip_limbs, nb_limbs);
	
	clean_limbs(scratch_limbs, 2*nb_limbs);
	for(int i=0; i<nb_limbs; i++)
		scratch_limbs[i] = am2_limbs[i];
	mpn_redc_n (am2_limbs, scratch_limbs, p_limbs, nb_limbs, mip_limbs);
	from_limbs_to_mpz_t(H, am2_limbs, nb_limbs);
	gmp_printf("r_mcgmp : %Zd\n", H);
	
	
	//~ Montgomery low level modular multiplication
	mpn_mod_mult(a_limbs, a_limbs, b_limbs, p_limbs, nb_limbs);
	from_limbs_to_mpz_t(F, a_limbs, nb_limbs);
	gmp_printf("r_lgmp  : %Zd\n", F);



	//goto fin;


		
	// a256 et b256 contiennent 8 valeurs en colonnes	
	__m256i a256[NB_COEFF], b256[NB_COEFF], res256[NB_COEFF], aMont256[NB_COEFF], bMont256[NB_COEFF], resMont256[NB_COEFF];
	
	__m256i n256[NB_COEFF], n_prime256[1], r2_256[NB_COEFF], un256[NB_COEFF], n_prime2_256[NB_COEFF];
	
	
		mpz_t A4[4], B4[4], C4[4], E4[4];
	for(int i=0;i<4;i++)	
		mpz_inits (A4[i], B4[i], C4[i], E4[i], NULL);
	uint64_t a64[4][NB_COEFF64], b64[4][NB_COEFF64], c64[4][NB_COEFF64], res64[4][NB_COEFF64];
	
	//mp_limb_t *r2_limbs_4[4][nb_limbs];
	mp_limb_t a_limbs_4[4][nb_limbs], b_limbs_4[4][nb_limbs], am1_limbs_4[4][nb_limbs], am2_limbs_4[4][nb_limbs], bm1_limbs_4[4][nb_limbs], bm2_limbs_4[4][nb_limbs*2];

	
	
	//Initialisation des paramètres Montgomery batch
	
	
	// modul_p
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<NB_COEFF64;j++)
			a64[i][j] = 0x0UL;
	}
	
	for(int i=0;i<4;i++)
	{
		countp = 0;
		mpz_export(a64[i], &countp, -1, sizeof(a64[0][0]) ,0,0, modul_p);
	
	}

	fexpand_4_256_52( n256, a64);

	afficheVect256_NB_COEFF(n256,"n256");

	// p_prime = (-modul_p)^-1 mod R
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<NB_COEFF64;j++)
			a64[i][j] = 0x0UL;
	}
	
	/*for(int i=0;i<4;i++)
	{
		a64[i] = p_prime;
	
	}*/
	
	n_prime256[0] = _mm256_set1_epi64x(p_prime[0]);
	
	//fexpand_4_256_52( n_prime256, a64);

	afficheVect256(n_prime256,"n_prime256");

	
	
	// N' pour classic Montgomery

	for(int i=0;i<4;i++)
	{
		mpz_export(a64[i], &countp, -1, sizeof(a64[0][0]) ,0,0, p_prime2);
	
	}

	fexpand_4_256_52( n_prime2_256, a64);

	afficheVect256_NB_COEFF(n_prime2_256,"n_prime2_256");
	// R^2 mod modul_p
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<NB_COEFF64;j++)
			a64[i][j] = 0x0UL;
	}
	
	for(int i=0;i<4;i++)
	{
		mpz_export(a64[i], &countp, -1, sizeof(a64[0][0]) ,0,0, r2_gmp_256);
	
	}

	fexpand_4_256_52( r2_256, a64);

	afficheVect256_NB_COEFF(r2_256,"r2_256");
	
	// 1 256 !
	for(int i=0;i<4;i++)
	{
		a64[i][0] = 0x1UL;
		for(int j=1;j<NB_COEFF64;j++)
			a64[i][j] = 0x0UL;
	}
	
	fexpand_4_256_52( un256, a64);

	afficheVect256_NB_COEFF(un256,"un256");
	
	//getchar();

	fflush(stdout);



	for(int i=0;i<4;i++)
	{
		countp = 0;
		mpz_urandomm(A4[i], r, modul_p);
		mpz_export(a64[i], &countp, -1, sizeof(a64[0][0]) ,0,0, A4[i]);
		
		
		
		countp = 0;
		mpz_urandomm(B4[i], r, modul_p);
		mpz_export(b64[i], &countp, -1, sizeof(b64[0][0]) ,0,0, B4[i]);
	
	
	
		a64[i][NB_COEFF64-1] = 0x0UL;
		b64[i][NB_COEFF64-1] = 0x0UL;
		
		
		
		
		//b_limbs_4[i] = mpz_limbs_modify (B4[i], nb_limbs);
		copy_limbs(a_limbs_4[i], A4[i], nb_limbs);
		copy_limbs(b_limbs_4[i], B4[i], nb_limbs);
		copy_limbs(am1_limbs_4[i], A4[i], nb_limbs);
		copy_limbs(am2_limbs_4[i], A4[i], nb_limbs);
		copy_limbs(bm1_limbs_4[i], B4[i], nb_limbs);
		copy_limbs(bm2_limbs_4[i], B4[i], nb_limbs);
		
		
		//~ conversion to Montgomery domain (block mont)
		mpn_mont_mul_red_1(am1_limbs_4[i], am1_limbs_4[i], r2_limbs, p_limbs, mip0, nb_limbs);
		mpn_mont_mul_red_1(bm1_limbs_4[i], bm1_limbs_4[i], r2_limbs, p_limbs, mip0, nb_limbs);
	
		//~ conversion to Montgomery domain (classic mont)
		mpn_mont_mul_red_n(am2_limbs_4[i], am2_limbs_4[i], r2_limbs, p_limbs, mip_limbs, nb_limbs);
		mpn_mont_mul_red_n(bm2_limbs_4[i], bm2_limbs_4[i], r2_limbs, p_limbs, mip_limbs, nb_limbs);
	}


	


	fexpand_4_256_52( b256, b64);
	fexpand_4_256_52( a256, a64);


	for(int i=0;i<4;i++)
		afficheVect(a64[i],"a64[i]     ",NB_COEFF64);
	afficheVect256_NB_COEFF(a256,"a256");


	for(int i=0;i<4;i++)
		afficheVect(b64[i],"b64[i]     ",NB_COEFF64);
	
	afficheVect256_NB_COEFF(b256,"b256");
	
	
	printf("fcontract_4_256_52()\n");
	fcontract_4_256_52( c64, a256);
	
	
		printf("\n");

	for(int i=0;i<4;i++){
		afficheVect(a64[i],"a64[i]     ",NB_COEFF64);
		//afficheVect256_NB_COEFF(a256,"a256");
		//for(int i=0;i<4;i++)
		afficheVect(c64[i],"c64[i]     ",NB_COEFF64);
	}

	for(int i=0;i<4;i++){
		for(int j=0;j<NB_COEFF64;j++){
			printf("%16.16lX ",c64[i][j]^a64[i][j]);
		}
	}
	printf("\n");
	
	for(int i=0;i<4;i++){
		for(int j=0;j<NB_COEFF64;j++)
			if(c64[i][j]^a64[i][j]) flag++;
		flag?counter++,flag=0:counter,flag=0;
	}
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory fexpand-fcontract !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;

	//goto fin;
	
	// conversion dans le domaine de Montgomery
	////block_mont_mul256_4_1040(aMont256, a256, r2_256, n256, n_prime256);
	////block_mont_mul256_4_1040(bMont256, b256, r2_256, n256, n_prime256);
	
	mont_mul256_4_1040(aMont256, a256, r2_256, n256, n_prime2_256);
	mont_mul256_4_1040(bMont256, b256, r2_256, n256, n_prime2_256);
	
	
	afficheVect256_NB_COEFF(aMont256,"\n\naMont256");
	afficheVect256_NB_COEFF(bMont256,"bMont256");
	
	
	
	
	
	
	
	mont_mul256_4_1040(resMont256, aMont256, bMont256, n256, n_prime2_256);
	
	
	
	
	afficheVect256_NB_COEFF(resMont256,"resMont256_lo");
	
	
	//block_mont_mul256_4_1040(resMont256, aMont256, bMont256, n256, n_prime256);
	
	
	
	
	afficheVect256_NB_COEFF(resMont256,"resMont256_lo");
	
	//getchar();
	
	
	
	// retour dans le domaine de standard
	
	////block_mont_mul256_4_1040(res256, resMont256, un256, n256, n_prime256);
	
	mont_mul256_4_1040(res256, resMont256, un256, n256, n_prime2_256);
	
	
	
	afficheVect256_NB_COEFF(res256,"res256_lo");
	
	//afficheVect256_NB_COEFF(res256+NB_COEFF,"res256_hi");
	
	fcontract_4_256_52(res64, res256);
	
	
	flag=0, counter=0;
	for(int i=0;i<4;i++)
	{
		
		gmp_printf("A4[i] : %ZX\n", A4[i]);
		gmp_printf("B4[i] : %ZX\n", B4[i]);
		
		mpn_mont_mul_red_1(am1_limbs_4[i], am1_limbs_4[i], bm1_limbs_4[i], p_limbs, mip0, nb_limbs);
		clean_limbs(scratch_limbs, 2*nb_limbs);
		for(int j=0; j<nb_limbs; j++)
			scratch_limbs[j] = am1_limbs_4[i][j];
		mpn_redc_1 (am1_limbs_4[i], scratch_limbs, p_limbs, nb_limbs, mip0);
		from_limbs_to_mpz_t(G, am1_limbs_4[i], nb_limbs);
		gmp_printf("r_mbgmp : %ZX\n", G);//*/


		//~ Montgomery modular multiplication (classic mont)
		mpn_mont_mul_red_n(am2_limbs_4[i], am2_limbs_4[i], bm2_limbs_4[i], p_limbs, mip_limbs, nb_limbs);
		
		clean_limbs(scratch_limbs, 2*nb_limbs);
		for(int j=0; j<nb_limbs; j++)
			scratch_limbs[j] = am2_limbs_4[i][j];
		mpn_redc_n (am2_limbs_4[i], scratch_limbs, p_limbs, nb_limbs, mip_limbs);
		from_limbs_to_mpz_t(H, am2_limbs_4[i], nb_limbs);
		gmp_printf("r_mcgmp : %ZX\n", H);
		
		
		//~ Montgomery low level modular multiplication
		mpn_mod_mult(a_limbs_4[i], a_limbs_4[i], b_limbs_4[i], p_limbs, nb_limbs);
		from_limbs_to_mpz_t(F, a_limbs_4[i], nb_limbs);
		gmp_printf("r_lgmp  : %ZX\n", F);


		mpz_export(res_gmp, &countp, -1, sizeof(b64[0][0]) ,0,0, G);
		afficheVect(res_gmp, "res_gmp     ",countp);//NB_COEFF64*2);
		afficheVect(res64[i],"res64[i]    ",NB_COEFF64);
		for(int j=0; j<NB_COEFF64;j++)
			if(res64[i][j]^res_gmp[j]) flag++;
		flag?counter++,flag=0:counter,flag=0;//*/
		printf("\n");
		
	}
	
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;
	

	//goto fin;
	
	
	
	
	
	
	
	
	
	printf("\t  /***********************************************/\n");
	printf("\t /   Test sur 1 jeu de données : batch mod exp   /\n");
	printf("\t/***********************************************/\n\n");

	

	int n_itch = mpn_sec_powm_itch(nb_limbs,1024,nb_limbs);
	
	printf("n_itch = %d, nb_limbs = %d\n",n_itch, nb_limbs);
	
	mp_limb_t * scratch_powm;
		
	scratch_powm = (mp_limb_t*) calloc (n_itch, sizeof(mp_limb_t));
	
	
	/*for(int i=0;i<4;i++)
	{
		mpz_set_ui(B4[i], 2UL);
		mpz_pow_ui(B4[i],B4[i],1023);
		if(i%2) mpz_add_ui(B4[i],B4[i],45611233);
		countp = 0;
		mpz_export(b64[i], &countp, -1, sizeof(a64[0][0]) ,0,0, B4[i]);
		printf("countp = %ld\n", countp);
	
	}//*/

	for(int i=0;i<4;i++){
		afficheVect(a64[i],"a64[i]     ",NB_COEFF64);
		gmp_printf("A4[i] : %ZX\n", A4[i]);
		printf("\n");
	}
	printf("\n");

	for(int i=0;i<4;i++){
		afficheVect(b64[i],"b64[i]     ",NB_COEFF64);
		gmp_printf("B4[i] : %ZX\n", B4[i]);
		printf("\n");
	}
	
	printf("\n");


	
	modExp_4_256(res64, a64, b64, n256, n_prime256, r2_256, n_prime2_256);
	
	
	
	flag=0, counter=0;
	for(int i=0;i<4;i++)
	{
		
		gmp_printf("A4[i] : %ZX\n", A4[i]);
		gmp_printf("B4[i] : %ZX\n", B4[i]);
		
		mpz_powm_sec(G,A4[i],B4[i],modul_p);
		gmp_printf("r_gmp   : %ZX\n", G);
		
		//~ Montgomery low level modular exponentiation
		mpn_sec_powm(am2_limbs_4[i], a_limbs_4[i], nb_limbs, b_limbs_4[i], 1024, p_limbs, nb_limbs, scratch_powm);
		from_limbs_to_mpz_t(F, am2_limbs_4[i], nb_limbs);
		gmp_printf("r_lgmp  : %ZX\n", F);//*/


		mpz_export(res_gmp, &countp, -1, sizeof(b64[0][0]) ,0,0, G);
		afficheVect(res_gmp, "res_gmp     ",countp);//NB_COEFF64*2);
		afficheVect(res64[i],"res64[i]    ",NB_COEFF64);
		for(int j=0; j<NB_COEFF64;j++)
			if(res64[i][j]^res_gmp[j]) flag++;
		flag?counter++,flag=0:counter,flag=0;//*/
		printf("\n");
		
	}
	
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;
	
	
	
	//goto fin;
	
	
	
	

	printf("\t  /***************************************************/\n");
	printf("\t /   Test sur 1000 jeux de données : batch mod exp   /\n");
	printf("\t/***************************************************/\n\n");

	
	flag=0, counter=0;
	
	for(int i=0;i<NTEST;i++)
	{
		for(int i=0;i<4;i++)
		{
			countp = 0;
			mpz_urandomm(A4[i], r, modul_p);
			mpz_export(a64[i], &countp, -1, sizeof(a64[0][0]) ,0,0, A4[i]);
			
			
			
			countp = 0;
			mpz_urandomm(B4[i], r, modul_p);
			mpz_export(b64[i], &countp, -1, sizeof(b64[0][0]) ,0,0, B4[i]);
		
		
		
			a64[i][NB_COEFF64-1] = 0x0UL;
			b64[i][NB_COEFF64-1] = 0x0UL;
			
			
			
		}


	
		modExp_4_256(res64, a64, b64, n256, n_prime256, r2_256, n_prime2_256);
	

		
		
		for(int i=0;i<4;i++)
		{
			
			//gmp_printf("A4[i] : %ZX\n", A4[i]);
			//gmp_printf("B4[i] : %ZX\n", B4[i]);
			
			mpz_powm_sec(G,A4[i],B4[i],modul_p);
			//gmp_printf("r_gmp   : %ZX\n", G);



			mpz_export(res_gmp, &countp, -1, sizeof(b64[0][0]) ,0,0, G);
			//afficheVect(res_gmp, "res_gmp     ",countp);//NB_COEFF64*2);
			//afficheVect(res64[i],"res64[i]    ",NB_COEFF64);
			for(int j=0; j<NB_COEFF64;j++)
				if(res64[i][j]^res_gmp[j]) flag++;
			flag?counter++,flag=0:counter,flag=0;//*/
			//printf("\n");
			
		}
	}
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;


	//goto fin;

	
	/********************
	//Chronométrage !!!!!!!!!!!!!
	*********************/
	printf("\t  /***************************/\n");
	printf("\t / Chronométrage !!!!!!!!!!!!/\n");
	printf("\t/***************************/\n\n");
	
	printf("\ngmp, BN, BN_MONT, //block_mont_mul256_4_1040\n");
	printf("-----------------------------------------------------------\n");

	BIGNUM *opA_4[4];
	BIGNUM *opB_4[4];
	BIGNUM *opAA_4[4];
	BIGNUM *opBB_4[4];



	for(int i=0;i<4;i++)
	{
		opA_4[i] = BN_CTX_get(ctx);
		opB_4[i] = BN_CTX_get(ctx);
		opAA_4[i] = BN_CTX_get(ctx);
		opBB_4[i] = BN_CTX_get(ctx);
	}	
	BN_dec2bn(&opP, mpz_get_str (NULL, 10, modul_p));
	BN_MONT_CTX_set(mont_ctx, opP, ctx);


	for(int k=0; k<NSAMPLES;k++){
	
		mini = (uint64_t)-1L;
		mini1 = (uint64_t)-1L;
		mini2 = (uint64_t)-1L;
		mini3 = (uint64_t)-1L; 
		mini4 = (uint64_t)-1L;
		mini5 = (uint64_t)-1L;
		mini6 = (uint64_t)-1L;
		

		for(int i=0;i<4;i++)
		{
			countp = 0;
			mpz_urandomm(A4[i], r, modul_p);
			mpz_export(a64[i], &countp, -1, sizeof(a64[0][0]) ,0,0, A4[i]);
			
			
			
			countp = 0;
			mpz_urandomm(B4[i], r, modul_p);
			mpz_export(b64[i], &countp, -1, sizeof(b64[0][0]) ,0,0, B4[i]);
		
		
		
			a64[i][NB_COEFF64-1] = 0x0UL;
			b64[i][NB_COEFF64-1] = 0x0UL;
			
			
			
			
			copy_limbs(a_limbs_4[i], A4[i], nb_limbs);
			copy_limbs(b_limbs_4[i], B4[i], nb_limbs);
			copy_limbs(am1_limbs_4[i], A4[i], nb_limbs);
			copy_limbs(am2_limbs_4[i], A4[i], nb_limbs);
			copy_limbs(bm1_limbs_4[i], B4[i], nb_limbs);
			copy_limbs(bm2_limbs_4[i], B4[i], nb_limbs);
			
			
			BN_dec2bn(&opA_4[i], mpz_get_str (NULL, 10, A4[i]));
			BN_dec2bn(&opB_4[i], mpz_get_str (NULL, 10, B4[i]));
			BN_copy(opAA_4[i], opA_4[i]);
			BN_copy(opBB_4[i], opB_4[i]);



		}
		
		fexpand_4_256_52( a256, a64);

		fexpand_4_256_52( b256, b64);

		
		for(int i=0;i<NTEST;i++)
		{
			mpn_mont_mul_red_1(am1_limbs_4[i&3], am1_limbs_4[i&3], bm1_limbs_4[i&3], p_limbs, mip0, nb_limbs);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start1)
			mpn_mont_mul_red_1(am1_limbs_4[0], am1_limbs_4[0], bm1_limbs_4[0], p_limbs, mip0, nb_limbs);
			mpn_mont_mul_red_1(am1_limbs_4[1], am1_limbs_4[1], bm1_limbs_4[1], p_limbs, mip0, nb_limbs);
			mpn_mont_mul_red_1(am1_limbs_4[2], am1_limbs_4[2], bm1_limbs_4[2], p_limbs, mip0, nb_limbs);
			mpn_mont_mul_red_1(am1_limbs_4[3], am1_limbs_4[3], bm1_limbs_4[3], p_limbs, mip0, nb_limbs);
			STAMPP(end1)
			
			if(mini>end1-start1) mini = end1-start1;
			
		}



		
		
		for(int i=0;i<NTEST;i++)
		{
			BN_mod_mul_montgomery(opA_4[i&3], opA_4[i&3], opB_4[i&3], mont_ctx, ctx);
		}
		
			
		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start5)
			BN_mod_mul_montgomery(opA_4[0], opA_4[0], opB_4[0], mont_ctx, ctx);
			BN_mod_mul_montgomery(opA_4[1], opA_4[1], opB_4[1], mont_ctx, ctx);
			BN_mod_mul_montgomery(opA_4[2], opA_4[2], opB_4[2], mont_ctx, ctx);
			BN_mod_mul_montgomery(opA_4[3], opA_4[3], opB_4[3], mont_ctx, ctx);
			STAMPP(end5)
			
			if(mini4>end5-start5) mini4 = end5-start5;
			
		}
		
		
		
		for(int i=0;i<NTEST;i++)
		{
			//block_mont_mul256_4_1040(res256, a256, b256, n256, n_prime256);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			STAMP(start3)
			//block_mont_mul256_4_1040(res256, a256, b256, n256, n_prime256);
			//block_mont_mul256_4_1040(res256, a256, b256, n256, n_prime256);
			//block_mont_mul256_4_1040(res256, a256, b256, n256, n_prime256);
			//block_mont_mul256_4_1040(res256, a256, b256, n256, n_prime256);
			//block_mont_mul256_4_1040(res256, a256, b256, n256, n_prime256);
			//block_mont_mul256_4_1040(res256, a256, b256, n256, n_prime256);
			//block_mont_mul256_4_1040(res256, a256, b256, n256, n_prime256);
			//block_mont_mul256_4_1040(res256, a256, b256, n256, n_prime256);
			//block_mont_mul256_4_1040(res256, a256, b256, n256, n_prime256);
			//block_mont_mul256_4_1040(res256, a256, b256, n256, n_prime256);
			STAMPP(end3)
			
			if(mini2>end3-start3) mini2 = end3-start3;
			
		}	
		

				
	
		for(int i=0;i<NTEST;i++)
		{
			mpn_sec_powm(am2_limbs_4[i&3], a_limbs_4[i&3], nb_limbs, b_limbs_4[i&3], 1024, p_limbs, nb_limbs, scratch_powm);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			STAMP(start3)
			mpn_sec_powm(am2_limbs_4[0], a_limbs_4[0], nb_limbs, b_limbs_4[0], 1024, p_limbs, nb_limbs, scratch_powm);
			mpn_sec_powm(am2_limbs_4[1], a_limbs_4[1], nb_limbs, b_limbs_4[1], 1024, p_limbs, nb_limbs, scratch_powm);
			mpn_sec_powm(am2_limbs_4[2], a_limbs_4[2], nb_limbs, b_limbs_4[2], 1024, p_limbs, nb_limbs, scratch_powm);
			mpn_sec_powm(am2_limbs_4[3], a_limbs_4[3], nb_limbs, b_limbs_4[3], 1024, p_limbs, nb_limbs, scratch_powm);
			STAMPP(end3)
			
			if(mini5>end3-start3) mini5 = end3-start3;
			
		}//*/
		for(int i=0;i<NTEST;i++)
		{
			BN_mod_exp_mont_consttime(opA_4[i&3], opA_4[i&3], opB_4[i&3], opP, ctx, mont_ctx);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start3)
			BN_mod_exp_mont_consttime(opA_4[0], opA_4[0], opB_4[0], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_4[1], opA_4[1], opB_4[1], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_4[2], opA_4[2], opB_4[2], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_4[3], opA_4[3], opB_4[3], opP, ctx, mont_ctx);
			STAMPP(end3)
			
			if(mini1>end3-start3) mini1 = end3-start3;
			
		}//*/

modexpcc:

		/*for(int i=0;i<NTEST;i++)
		{
			BN_mod_exp_mont_consttime_x2(opA_4[i&3], opA_4[i&3], opB_4[i&3], opP, mont_ctx,
						opA_4[i&3], opA_4[i&3], opB_4[i&3], opP, mont_ctx,
						ctx);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start3)
			BN_mod_exp_mont_consttime(opA_4[0], opA_4[0], opB_4[0], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_4[1], opA_4[1], opB_4[1], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_4[2], opA_4[2], opB_4[2], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_4[3], opA_4[3], opB_4[3], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_4[4], opA_4[4], opB_4[4], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_4[5], opA_4[5], opB_4[5], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_4[6], opA_4[6], opB_4[6], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_4[7], opA_4[7], opB_4[7], opP, ctx, mont_ctx);
			STAMPP(end3)
			
			if(mini1>end3-start3) mini1 = end3-start3;
			
		}//*/
		//printf("BN_mod_exp_mont_consttime\n");
		



		for(int i=0;i<NTEST;i++)
		{
			modExp_4_256(res64, a64, b64, n256, n_prime256, r2_256, n_prime2_256);
		}

		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start4)
			modExp_4_256(res64, a64, b64, n256, n_prime256, r2_256, n_prime2_256);
			STAMPP(end4)

			if(mini3>end4-start4) mini3 = end4-start4;
			
		}
		
		
		
		

		timer += mini;

		timer1 += mini1;
		
		timer2 += mini2;
		
		timer3 += mini3;

		timer4 += mini4;
		
		timer5 += mini5;
		
	}
	
	printf("timer gmp mpn_mont_mul_red_1 (x4)    : %llu\n",timer/NSAMPLES);	

	printf("timer BN_mod_mul_montgomery (x4)     : %llu\n",timer4/NSAMPLES);
	
	printf("timer //block_mont_mul256_4_1040       : %llu\n",timer2/(NSAMPLES*10));
	
	printf("timer gmp mpn_sec_powm (x4)          : %llu\n",timer5/NSAMPLES);

	printf("timer BN_mod_exp_mont_consttime (x4) : %llu\n",timer1/NSAMPLES);	
	
	printf("timer modExp_4_256                   : %llu\n",timer3/NSAMPLES);
	
	
	
	




	//goto fin;
	
	
	
	/********************
	//Instructions !!!!!!!!!!!!!
	*********************/
	printf("\n\n\t  /***************************/\n");
	printf("\t / Instructions !!!!!!!!!!!!!/\n");
	printf("\t/***************************/\n\n");
	
	printf("\ngmp, BN, BN_MONT, //block_mont_mul256_4_1040\n");
	printf("-----------------------------------------------------------\n");

	timer=0, timer1=0, timer2=0, timer3=0, timer4=0, timer5=0, timer6=0;
	
	for(int k=0; k<NSAMPLES;k++){
	
		mini = (uint64_t)-1L;
		mini1 = (uint64_t)-1L;
		mini2 = (uint64_t)-1L;
		mini3 = (uint64_t)-1L; 
		mini4 = (uint64_t)-1L;
		mini5 = (uint64_t)-1L;
		mini6 = (uint64_t)-1L;
		
		for(int i=0;i<4;i++)
		{
			countp = 0;
			mpz_urandomm(A4[i], r, modul_p);
			mpz_export(a64[i], &countp, -1, sizeof(a64[0][0]) ,0,0, A4[i]);
			
			
			
			countp = 0;
			mpz_urandomm(B4[i], r, modul_p);
			mpz_export(b64[i], &countp, -1, sizeof(b64[0][0]) ,0,0, B4[i]);
		
		
		
			a64[i][NB_COEFF64-1] = 0x0UL;
			b64[i][NB_COEFF64-1] = 0x0UL;
			
			
			
			
			copy_limbs(a_limbs_4[i], A4[i], nb_limbs);
			copy_limbs(b_limbs_4[i], B4[i], nb_limbs);
			copy_limbs(am1_limbs_4[i], A4[i], nb_limbs);
			copy_limbs(am2_limbs_4[i], A4[i], nb_limbs);
			copy_limbs(bm1_limbs_4[i], B4[i], nb_limbs);
			copy_limbs(bm2_limbs_4[i], B4[i], nb_limbs);
			
			
			BN_dec2bn(&opA_4[i], mpz_get_str (NULL, 10, A4[i]));
			BN_dec2bn(&opB_4[i], mpz_get_str (NULL, 10, B4[i]));
			BN_copy(opAA_4[i], opA_4[i]);
			BN_copy(opBB_4[i], opB_4[i]);



		}
		
		fexpand_4_256_52( a256, a64);

		fexpand_4_256_52( b256, b64);

		
		for(int i=0;i<NTEST;i++)
		{
			mpn_mont_mul_red_1(am1_limbs_4[i&3], am1_limbs_4[i&3], bm1_limbs_4[i&3], p_limbs, mip0, nb_limbs);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			
			start1 = rdpmc_instructions();
			mpn_mont_mul_red_1(am1_limbs_4[0], am1_limbs_4[0], bm1_limbs_4[0], p_limbs, mip0, nb_limbs);
			mpn_mont_mul_red_1(am1_limbs_4[1], am1_limbs_4[1], bm1_limbs_4[1], p_limbs, mip0, nb_limbs);
			mpn_mont_mul_red_1(am1_limbs_4[2], am1_limbs_4[2], bm1_limbs_4[2], p_limbs, mip0, nb_limbs);
			mpn_mont_mul_red_1(am1_limbs_4[3], am1_limbs_4[3], bm1_limbs_4[3], p_limbs, mip0, nb_limbs);
			end1 = rdpmc_instructions();
			
			if(mini>end1-start1) mini = end1-start1;
			
		}


		for(int i=0;i<NTEST;i++)
		{
			mpn_mont_mul_red_n(am2_limbs_4[i&3], am2_limbs_4[i&3], bm2_limbs_4[i&3], p_limbs, mip_limbs, nb_limbs);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			
			start3 = rdpmc_instructions();
			mpn_mont_mul_red_n(am2_limbs_4[0], am2_limbs_4[0], bm2_limbs_4[0], p_limbs, mip_limbs, nb_limbs);
			mpn_mont_mul_red_n(am2_limbs_4[1], am2_limbs_4[1], bm2_limbs_4[1], p_limbs, mip_limbs, nb_limbs);
			mpn_mont_mul_red_n(am2_limbs_4[2], am2_limbs_4[2], bm2_limbs_4[2], p_limbs, mip_limbs, nb_limbs);
			mpn_mont_mul_red_n(am2_limbs_4[3], am2_limbs_4[3], bm2_limbs_4[3], p_limbs, mip_limbs, nb_limbs);
			end3 = rdpmc_instructions();
			
			if(mini1>end3-start3) mini1 = end3-start3;
			
		}//*/



				
	
		for(int i=0;i<NTEST;i++)
		{
			mpn_sec_powm(am2_limbs_4[i&3], a_limbs_4[i&3], nb_limbs, b_limbs_4[i&3], 1024, p_limbs, nb_limbs, scratch_powm);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			
			start3 = rdpmc_instructions();
			mpn_sec_powm(am2_limbs_4[0], a_limbs_4[0], nb_limbs, b_limbs_4[0], 1024, p_limbs, nb_limbs, scratch_powm);
			mpn_sec_powm(am2_limbs_4[1], a_limbs_4[1], nb_limbs, b_limbs_4[1], 1024, p_limbs, nb_limbs, scratch_powm);
			mpn_sec_powm(am2_limbs_4[2], a_limbs_4[2], nb_limbs, b_limbs_4[2], 1024, p_limbs, nb_limbs, scratch_powm);
			mpn_sec_powm(am2_limbs_4[3], a_limbs_4[3], nb_limbs, b_limbs_4[3], 1024, p_limbs, nb_limbs, scratch_powm);
			end3 = rdpmc_instructions();
			
			if(mini5>end3-start3) mini5 = end3-start3;
			
		}//*/
		
		for(int i=0;i<NTEST;i++)
		{
			BN_mod_mul(opAA_4[i&3], opAA_4[i&3], opBB_4[i&3], opP, ctx);
		}

		for(int i=0;i<NTEST;i++)
		{
			
			start4 = rdpmc_instructions();
			BN_mod_mul(opAA_4[0], opAA_4[0], opBB_4[0], opP, ctx);
			BN_mod_mul(opAA_4[1], opAA_4[1], opBB_4[1], opP, ctx);
			BN_mod_mul(opAA_4[2], opAA_4[2], opBB_4[2], opP, ctx);
			BN_mod_mul(opAA_4[3], opAA_4[3], opBB_4[3], opP, ctx);
			end4 = rdpmc_instructions();

			if(mini3>end4-start4) mini3 = end4-start4;
			
		}
		
		for(int i=0;i<NTEST;i++)
		{
			BN_mod_exp_mont_consttime(opA_4[i&3], opA_4[i&3], opB_4[i&3], opP, ctx, mont_ctx);
		}
		
			
		for(int i=0;i<NTEST;i++)
		{
			
			start5 = rdpmc_instructions();
			BN_mod_exp_mont_consttime(opA_4[0], opA_4[0], opB_4[0], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_4[1], opA_4[1], opB_4[1], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_4[2], opA_4[2], opB_4[2], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_4[3], opA_4[3], opB_4[3], opP, ctx, mont_ctx);
			end5 = rdpmc_instructions();
			
			if(mini4>end5-start5) mini4 = end5-start5;
			
		}
		
modexpinstr:		
		
		for(int i=0;i<NTEST;i++)
		{
			modExp_4_256(res64, a64, b64, n256, n_prime256, r2_256, n_prime2_256);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			start3 = rdpmc_instructions();
			modExp_4_256(res64, a64, b64, n256, n_prime256, r2_256, n_prime2_256);
			end3 = rdpmc_instructions();
			
			if(mini2>end3-start3) mini2 = end3-start3;
			
		}	
		
		timer += mini;

		timer1 += mini1;
		
		timer2 += mini2;
		
		timer3 += mini3;

		timer4 += mini4;
		
		timer5 += mini5;
		
	}
	
	printf("gmp mpn_mont_mul_red_1 (x4)      : %llu\n",timer/NSAMPLES);	
	
	printf("gmp mpn_mont_mul_red_n (x4)      : %llu\n",timer1/NSAMPLES);	
	
	printf("gmp mpn_sec_powm (x4)            : %llu\n",timer5/NSAMPLES);
	
	printf("BN_mod_mul (x4)                  : %llu\n",timer3/NSAMPLES);

	printf("BN_ mod_exp_mont_consttime(x4)   : %llu\n",timer4/NSAMPLES);

	printf("modExp_4_256                     : %llu\n",timer2/NSAMPLES);
	

















fin:	
	
	printf("\nAu revoir et merci !\n");	

	mpz_clears (A, B, C, E, UPB, NULL);
	gmp_randclear(r);

	BN_MONT_CTX_free(mont_ctx);
	BN_CTX_end(ctx);
	BN_CTX_free(ctx);

	free_data(modul_p, p_prime2,r2_gmp_256);
	return 0;
}

