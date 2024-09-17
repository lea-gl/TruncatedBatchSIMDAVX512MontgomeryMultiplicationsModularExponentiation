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

#define NTEST 100
//~ Compilation command : gcc -Wall -O3 main.c -o main -lgmp -lcrypto
//~ Execution command : ./main

//~ Important : polynomials representations form is P(X) = a0 + ... + an.X^n = (a0, ..., an).



void init_data(mpz_t modul_p, mpz_t p_prime, mpz_t r2_gmp_512){

	printf("init_data()\n");

	mpz_inits (modul_p, p_prime, r2_gmp_512, NULL);



/*   Montgomery parameters !*/

	mpz_set_str(modul_p, "18886067802967075327280941249671742892243481993108498494415484957699078546649682485714422943821080435520329442068191917110323048028970703931779461654633909101335377395324551678438747930545797443010045842745961253827102717654670854806740037924245275310717671705104548772408419739344264507962540010349680079608238940386937735340626595669835671987802999829865146435794277306826112318005515814655474503374805566581577847670854157674381092903985398835630607796539593481446649028150423050226450180796411687822365591692283603091838550999559581173656786759351660481156617962148151765248588177553779524741032957400470591605837",10);
	mpz_set_str(p_prime, "78132136564655410989563315832634011294689049190616977313513838828444770526152691982871738277255580436790309136156762557113903029493780593120663359705642571374297050780825708688393416611087548889080492862224834203807075924037244819576628175618739496576556189608650971934780046743343826153961056419231343539747070120205682635072724138188817228187533499275476058332137796071314838779600576406545715797984914046768227918661456968412043150802977692486669686837768359684266076076736872268874248870022008763016377899433271386944372375130064197309192813014195377161682294426384149710785060167852274205786193818960534814904014136505211",10);
	mpz_set_str(r2_gmp_512, "11585684741700763470512585546340789179455558989412711626158827259176068619779549275715405029153647791622550306511258587356579814609694009111738812307678170473840070281565667493570103282293617009706955669371003117759999346987965627190746025365217719007275257643696587602188845118892047118419390766226539554769932089447532768649881440868108958464164627382465435786779073731923113613569143694573551011885242856872029558204707888636180574770502289245050721875662949729421596719060434256213817384685402580433643465948433085516133209723587314693670854803372127045685128689756531981342150880131336208600571215873611268926683",10);
}



void free_data(mpz_t modul_p, mpz_t p_prime, mpz_t r2_512){

	mpz_clears (modul_p, p_prime, r2_512, NULL);
	
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

	//uint64_t p_prime[1];// Block Montgomery
	static mpz_t modul_p, r2_gmp_512, p_prime;// Classic Montgomery
	mpz_t A, B, C, E, F, R2, R3, G, H, UPB;
	mpz_inits (A, B, C, E, F, R2, R3, G, H, UPB, NULL);

	//mpz_inits (A, B, C, E, F, R2, R3, G, H, UPB, modul_p, p_prime, NULL);
	init_data(modul_p, p_prime, r2_gmp_512);
	
	mpz_ui_pow_ui ( UPB, 2UL, SIZE );
	
	
	printf("%lu %d  %d\n\n", mpz_sizeinbase (UPB, 2), NB_COEFF, NB_COEFF64);
	gmp_printf("UPB  : 0x%ZX\n\n\n", UPB);

	gmp_printf("modul_p  : 0x%ZX\n\n\n", modul_p);
	//printf("p_prime  : 0x%lX\n\n\n", p_prime[0]);
	gmp_printf("r2_512   : 0x%ZX\n\n\n", r2_gmp_512	);
	
	
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


		
	// a512 et b512 contiennent 8 valeurs en colonnes	
	__m512i a512[NB_COEFF], b512[NB_COEFF], res512[NB_COEFF], aMont512[NB_COEFF], bMont512[NB_COEFF], resMont512[NB_COEFF];
	
	__m512i n512[NB_COEFF], r2_512[NB_COEFF], un512[NB_COEFF], n_prime_512[NB_COEFF];
	
	
		mpz_t A8[8], B8[8], C8[8], E8[8];
	for(int i=0;i<8;i++)	
		mpz_inits (A8[i], B8[i], C8[i], E8[i], NULL);
	uint64_t a64[8][NB_COEFF64], b64[8][NB_COEFF64], c64[8][NB_COEFF64], res64[8][NB_COEFF64];
	
	//mp_limb_t *r2_limbs_8[8][nb_limbs];
	mp_limb_t a_limbs_8[8][nb_limbs], b_limbs_8[8][nb_limbs], am1_limbs_8[8][nb_limbs], am2_limbs_8[8][nb_limbs], bm1_limbs_8[8][nb_limbs], bm2_limbs_8[8][nb_limbs];

	
	
	//Initialisation des paramètres Montgomery batch
	
	
	// modul_p
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<NB_COEFF64;j++)
			a64[i][j] = 0x0UL;
	}
	
	for(int i=0;i<8;i++)
	{
		countp = 0;
		mpz_export(a64[i], &countp, -1, sizeof(a64[0][0]) ,0,0, modul_p);
	
	}

	fexpand_8_512_52( n512, a64);

	afficheVect512_NB_COEFF(n512,"n512");

	// p_prime = (-modul_p)^-1 mod R
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<NB_COEFF64;j++)
			a64[i][j] = 0x0UL;
	}
	
	/*for(int i=0;i<8;i++)
	{
		a64[i] = p_prime;
	
	}*/
	
	//n_prime512[0] = _mm512_set1_epi64(p_prime[0]);
	
	//fexpand_8_512_52( n_prime512, a64);

	//afficheVect512(n_prime512,"n_prime512");

	
	
	// N' pour classic Montgomery

	for(int i=0;i<8;i++)
	{
		mpz_export(a64[i], &countp, -1, sizeof(a64[0][0]) ,0,0, p_prime);
	
	}

	fexpand_8_512_52( n_prime_512, a64);

	afficheVect512_NB_COEFF(n_prime_512,"n_prime_512");
	// R^2 mod modul_p
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<NB_COEFF64;j++)
			a64[i][j] = 0x0UL;
	}
	
	for(int i=0;i<8;i++)
	{
		mpz_export(a64[i], &countp, -1, sizeof(a64[0][0]) ,0,0, r2_gmp_512);
	
	}

	fexpand_8_512_52( r2_512, a64);

	afficheVect512_NB_COEFF(r2_512,"r2_512");
	
	// 1 512 !
	for(int i=0;i<8;i++)
	{
		a64[i][0] = 0x1UL;
		for(int j=1;j<NB_COEFF64;j++)
			a64[i][j] = 0x0UL;
	}
	
	fexpand_8_512_52( un512, a64);

	afficheVect512_NB_COEFF(un512,"un512");
	
	//getchar();

	fflush(stdout);



	for(int i=0;i<8;i++)
	{
		countp = 0;
		mpz_urandomm(A8[i], r, modul_p);
		mpz_export(a64[i], &countp, -1, sizeof(a64[0][0]) ,0,0, A8[i]);
		
		
		
		countp = 0;
		mpz_urandomm(B8[i], r, modul_p);
		mpz_export(b64[i], &countp, -1, sizeof(b64[0][0]) ,0,0, B8[i]);
	
	
	
		a64[i][NB_COEFF64-1] = 0x0UL;
		b64[i][NB_COEFF64-1] = 0x0UL;
		
		
		
		
		//b_limbs_8[i] = mpz_limbs_modify (B8[i], nb_limbs);
		copy_limbs(a_limbs_8[i], A8[i], nb_limbs);
		copy_limbs(b_limbs_8[i], B8[i], nb_limbs);
		copy_limbs(am1_limbs_8[i], A8[i], nb_limbs);
		copy_limbs(am2_limbs_8[i], A8[i], nb_limbs);
		copy_limbs(bm1_limbs_8[i], B8[i], nb_limbs);
		copy_limbs(bm2_limbs_8[i], B8[i], nb_limbs);
		
		
		//~ conversion to Montgomery domain (block mont)
		mpn_mont_mul_red_1(am1_limbs_8[i], am1_limbs_8[i], r2_limbs, p_limbs, mip0, nb_limbs);
		mpn_mont_mul_red_1(bm1_limbs_8[i], bm1_limbs_8[i], r2_limbs, p_limbs, mip0, nb_limbs);
	
		//~ conversion to Montgomery domain (classic mont)
		mpn_mont_mul_red_n(am2_limbs_8[i], am2_limbs_8[i], r2_limbs, p_limbs, mip_limbs, nb_limbs);
		mpn_mont_mul_red_n(bm2_limbs_8[i], bm2_limbs_8[i], r2_limbs, p_limbs, mip_limbs, nb_limbs);
	}


	


	fexpand_8_512_52( b512, b64);
	fexpand_8_512_52( a512, a64);


	for(int i=0;i<8;i++)
		afficheVect(a64[i],"a64[i]     ",NB_COEFF64);
	afficheVect512_NB_COEFF(a512,"a512");


	for(int i=0;i<8;i++)
		afficheVect(b64[i],"b64[i]     ",NB_COEFF64);
	
	afficheVect512_NB_COEFF(b512,"b512");
	
	
	printf("fcontract_8_512_52()\n");
	fcontract_8_512_52( c64, a512);
	
	
		printf("\n");

	for(int i=0;i<8;i++){
		afficheVect(a64[i],"a64[i]     ",NB_COEFF64);
		//afficheVect512_NB_COEFF(a512,"a512");
		//for(int i=0;i<8;i++)
		afficheVect(c64[i],"c64[i]     ",NB_COEFF64);
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

	//goto fin;
	
	// conversion dans le domaine de Montgomery
	//block_mont_mul512_8_2080(aMont512, a512, r2_512, n512, n_prime512);
	//block_mont_mul512_8_2080(bMont512, b512, r2_512, n512, n_prime512);
	
	mont_mul512_8_2080(aMont512, a512, r2_512, n512, n_prime_512);
	mont_mul512_8_2080(bMont512, b512, r2_512, n512, n_prime_512);
	
	
	afficheVect512_NB_COEFF(aMont512,"\n\naMont512");
	afficheVect512_NB_COEFF(bMont512,"bMont512");
	
	
	
	
	
	
	
	mont_mul512_8_2080(resMont512, aMont512, bMont512, n512, n_prime_512);
	
	
	
	
	afficheVect512_NB_COEFF(resMont512,"resMont512_lo");
	
	
	//getchar();
	
	
	
	// retour dans le domaine de standard
	
	//block_mont_mul512_8_2080(res512, resMont512, un512, n512, n_prime512);
	
	mont_mul512_8_2080(res512, resMont512, un512, n512, n_prime_512);
	
	
	
	afficheVect512_NB_COEFF(res512,"res512_lo");
	
	//afficheVect512_NB_COEFF(res512+NB_COEFF,"res512_hi");
	
	fcontract_8_512_52(res64, res512);
	
	
	flag=0, counter=0;
	for(int i=0;i<8;i++)
	{
		
		gmp_printf("A8[i] : %ZX\n", A8[i]);
		gmp_printf("B8[i] : %ZX\n", B8[i]);
		
		mpn_mont_mul_red_1(am1_limbs_8[i], am1_limbs_8[i], bm1_limbs_8[i], p_limbs, mip0, nb_limbs);
		clean_limbs(scratch_limbs, 2*nb_limbs);
		for(int j=0; j<nb_limbs; j++)
			scratch_limbs[j] = am1_limbs_8[i][j];
		mpn_redc_1 (am1_limbs_8[i], scratch_limbs, p_limbs, nb_limbs, mip0);
		from_limbs_to_mpz_t(G, am1_limbs_8[i], nb_limbs);
		gmp_printf("r_mbgmp : %ZX\n", G);//*/


		//~ Montgomery modular multiplication (classic mont)
		mpn_mont_mul_red_n(am2_limbs_8[i], am2_limbs_8[i], bm2_limbs_8[i], p_limbs, mip_limbs, nb_limbs);
		
		clean_limbs(scratch_limbs, 2*nb_limbs);
		for(int j=0; j<nb_limbs; j++)
			scratch_limbs[j] = am2_limbs_8[i][j];
		mpn_redc_n (am2_limbs_8[i], scratch_limbs, p_limbs, nb_limbs, mip_limbs);
		from_limbs_to_mpz_t(H, am2_limbs_8[i], nb_limbs);
		gmp_printf("r_mcgmp : %ZX\n", H);
		
		
		//~ Montgomery low level modular multiplication
		mpn_mod_mult(a_limbs_8[i], a_limbs_8[i], b_limbs_8[i], p_limbs, nb_limbs);
		from_limbs_to_mpz_t(F, a_limbs_8[i], nb_limbs);
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
	
	
	/*for(int i=0;i<8;i++)
	{
		mpz_set_ui(B8[i], 2UL);
		mpz_pow_ui(B8[i],B8[i],1023);
		if(i%2) mpz_add_ui(B8[i],B8[i],45611233);
		countp = 0;
		mpz_export(b64[i], &countp, -1, sizeof(a64[0][0]) ,0,0, B8[i]);
		printf("countp = %ld\n", countp);
	
	}//*/

	for(int i=0;i<8;i++){
		afficheVect(a64[i],"a64[i]     ",NB_COEFF64);
		gmp_printf("A8[i] : %ZX\n", A8[i]);
		printf("\n");
	}
	printf("\n");

	for(int i=0;i<8;i++){
		afficheVect(b64[i],"b64[i]     ",NB_COEFF64);
		gmp_printf("B8[i] : %ZX\n", B8[i]);
		printf("\n");
	}
	
	printf("\n");


	
	modExp_8_512(res64, a64, b64, n512, n_prime_512, r2_512);
	
	
	
	flag=0, counter=0;
	for(int i=0;i<8;i++)
	{
		
		gmp_printf("A8[i] : %ZX\n", A8[i]);
		gmp_printf("B8[i] : %ZX\n", B8[i]);
		
		mpz_powm_sec(G,A8[i],B8[i],modul_p);
		gmp_printf("r_gmp   : %ZX\n", G);
		
		//~ Montgomery low level modular exponentiation
		mpn_sec_powm(am2_limbs_8[0], a_limbs_8[0], nb_limbs, b_limbs_8[0], 2048, p_limbs, nb_limbs, scratch_powm);
		from_limbs_to_mpz_t(F, am2_limbs_8[i], nb_limbs);
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
	
	
	
	

	printf("\t  /***************************************************/\n");
	printf("\t /   Test sur 1000 jeux de données : batch mod exp   /\n");
	printf("\t/***************************************************/\n\n");

	
	flag=0, counter=0;
	
	for(int i=0;i<NTEST;i++)
	{
		for(int i=0;i<8;i++)
		{
			countp = 0;
			mpz_urandomm(A8[i], r, modul_p);
			mpz_export(a64[i], &countp, -1, sizeof(a64[0][0]) ,0,0, A8[i]);
			
			
			
			countp = 0;
			mpz_urandomm(B8[i], r, modul_p);
			mpz_export(b64[i], &countp, -1, sizeof(b64[0][0]) ,0,0, B8[i]);
		
		
		
			a64[i][NB_COEFF64-1] = 0x0UL;
			b64[i][NB_COEFF64-1] = 0x0UL;
			
			
			
		}


	
		modExp_8_512(res64, a64, b64, n512, n_prime_512, r2_512);
	

		
		
		for(int i=0;i<8;i++)
		{
			
			//gmp_printf("A8[i] : %ZX\n", A8[i]);
			//gmp_printf("B8[i] : %ZX\n", B8[i]);
			
			mpz_powm_sec(G,A8[i],B8[i],modul_p);
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
	
	printf("\ngmp, BN, BN_MONT, //block_mont_mul512_8_2080\n");
	printf("-----------------------------------------------------------\n");

	BIGNUM *opA_8[8];
	BIGNUM *opB_8[8];
	BIGNUM *opAA_8[8];
	BIGNUM *opBB_8[8];

	printf("BIGNUM\n");


	for(int i=0;i<8;i++)
	{
		opA_8[i] = BN_CTX_get(ctx);
		opB_8[i] = BN_CTX_get(ctx);
		opAA_8[i] = BN_CTX_get(ctx);
		opBB_8[i] = BN_CTX_get(ctx);
		printf("i=%d\n",i);

	}	
	printf("BN_CTX_get\n");
	BN_dec2bn(&opP, mpz_get_str (NULL, 10, modul_p));
	printf("BN_dec2bn\n");


	BN_MONT_CTX_set(mont_ctx, opP, ctx);
	printf("BN_MONT_CTX_set\n");

	fflush(stdout);

	for(int k=0; k<NSAMPLES;k++){
	
		mini = (uint64_t)-1L;
		mini1 = (uint64_t)-1L;
		mini2 = (uint64_t)-1L;
		mini3 = (uint64_t)-1L; 
		mini4 = (uint64_t)-1L;
		mini5 = (uint64_t)-1L;
		mini6 = (uint64_t)-1L;
		

		printf("k=%d\n",k);
		
		
		for(int i=0;i<8;i++)
		{
			countp = 0;
			mpz_urandomm(A8[i], r, modul_p);
			mpz_export(a64[i], &countp, -1, sizeof(a64[0][0]) ,0,0, A8[i]);
			
			
			
			countp = 0;
			mpz_urandomm(B8[i], r, modul_p);
			mpz_export(b64[i], &countp, -1, sizeof(b64[0][0]) ,0,0, B8[i]);
		
		
		
			a64[i][NB_COEFF64-1] = 0x0UL;
			b64[i][NB_COEFF64-1] = 0x0UL;
			
			
			
			
			copy_limbs(a_limbs_8[i], A8[i], nb_limbs);
			copy_limbs(b_limbs_8[i], B8[i], nb_limbs);
			copy_limbs(am1_limbs_8[i], A8[i], nb_limbs);
			copy_limbs(am2_limbs_8[i], A8[i], nb_limbs);
			copy_limbs(bm1_limbs_8[i], B8[i], nb_limbs);
			copy_limbs(bm2_limbs_8[i], B8[i], nb_limbs);
			
			
			BN_dec2bn(&opA_8[i], mpz_get_str (NULL, 10, A8[i]));
			BN_dec2bn(&opB_8[i], mpz_get_str (NULL, 10, B8[i]));
			BN_copy(opAA_8[i], opA_8[i]);
			BN_copy(opBB_8[i], opB_8[i]);

			printf("copy_limbs, i=%d\n",i);


		}
		
		fexpand_8_512_52( a512, a64);

		fexpand_8_512_52( b512, b64);


		printf("fexpand_8_512_52\n");
		
		for(int i=0;i<NTEST;i++)
		{
			mpn_mont_mul_red_1(am1_limbs_8[i&7], am1_limbs_8[i&7], bm1_limbs_8[i&7], p_limbs, mip0, nb_limbs);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start1)
			mpn_mont_mul_red_1(am1_limbs_8[0], am1_limbs_8[0], bm1_limbs_8[0], p_limbs, mip0, nb_limbs);
			mpn_mont_mul_red_1(am1_limbs_8[1], am1_limbs_8[1], bm1_limbs_8[1], p_limbs, mip0, nb_limbs);
			mpn_mont_mul_red_1(am1_limbs_8[2], am1_limbs_8[2], bm1_limbs_8[2], p_limbs, mip0, nb_limbs);
			mpn_mont_mul_red_1(am1_limbs_8[3], am1_limbs_8[3], bm1_limbs_8[3], p_limbs, mip0, nb_limbs);
			mpn_mont_mul_red_1(am1_limbs_8[4], am1_limbs_8[4], bm1_limbs_8[4], p_limbs, mip0, nb_limbs);
			mpn_mont_mul_red_1(am1_limbs_8[5], am1_limbs_8[5], bm1_limbs_8[5], p_limbs, mip0, nb_limbs);
			mpn_mont_mul_red_1(am1_limbs_8[6], am1_limbs_8[6], bm1_limbs_8[6], p_limbs, mip0, nb_limbs);
			mpn_mont_mul_red_1(am1_limbs_8[7], am1_limbs_8[7], bm1_limbs_8[7], p_limbs, mip0, nb_limbs);
			STAMPP(end1)
			
			if(mini>end1-start1) mini = end1-start1;
			
		}

		printf("mpn_mont_mul_red_1\n");
		

		
		
		for(int i=0;i<NTEST;i++)
		{
			BN_mod_mul_montgomery(opA_8[i&7], opA_8[i&7], opB_8[i&7], mont_ctx, ctx);
		}
		
			
		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start5)
			BN_mod_mul_montgomery(opA_8[0], opA_8[0], opB_8[0], mont_ctx, ctx);
			BN_mod_mul_montgomery(opA_8[1], opA_8[1], opB_8[1], mont_ctx, ctx);
			BN_mod_mul_montgomery(opA_8[2], opA_8[2], opB_8[2], mont_ctx, ctx);
			BN_mod_mul_montgomery(opA_8[3], opA_8[3], opB_8[3], mont_ctx, ctx);
			BN_mod_mul_montgomery(opA_8[4], opA_8[4], opB_8[4], mont_ctx, ctx);
			BN_mod_mul_montgomery(opA_8[5], opA_8[5], opB_8[5], mont_ctx, ctx);
			BN_mod_mul_montgomery(opA_8[6], opA_8[6], opB_8[6], mont_ctx, ctx);
			BN_mod_mul_montgomery(opA_8[7], opA_8[7], opB_8[7], mont_ctx, ctx);
			STAMPP(end5)
			
			if(mini4>end5-start5) mini4 = end5-start5;
			
		}

		printf("BN_mod_mul_montgomery\n");
		
		
		
		/*for(int i=0;i<NTEST;i++)
		{
			//block_mont_mul512_8_1040(res512, a512, b512, n512, n_prime512);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			STAMP(start3)
			//block_mont_mul512_8_1040(res512, a512, b512, n512, n_prime512);
			//block_mont_mul512_8_1040(res512, a512, b512, n512, n_prime512);
			//block_mont_mul512_8_1040(res512, a512, b512, n512, n_prime512);
			//block_mont_mul512_8_1040(res512, a512, b512, n512, n_prime512);
			//block_mont_mul512_8_1040(res512, a512, b512, n512, n_prime512);
			//block_mont_mul512_8_1040(res512, a512, b512, n512, n_prime512);
			//block_mont_mul512_8_1040(res512, a512, b512, n512, n_prime512);
			//block_mont_mul512_8_1040(res512, a512, b512, n512, n_prime512);
			//block_mont_mul512_8_1040(res512, a512, b512, n512, n_prime512);
			//block_mont_mul512_8_1040(res512, a512, b512, n512, n_prime512);
			STAMPP(end3)
			
			if(mini2>end3-start3) mini2 = end3-start3;
			
		}	//*/
		

				
	
		for(int i=0;i<NTEST;i++)
		{
			mpn_sec_powm(am2_limbs_8[i&7], a_limbs_8[i&7], nb_limbs, b_limbs_8[i&7], 2048, p_limbs, nb_limbs, bm2_limbs_8[i&7]);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			STAMP(start3)
			mpn_sec_powm(am2_limbs_8[0], a_limbs_8[0], nb_limbs, b_limbs_8[0], 2048, p_limbs, nb_limbs, scratch_powm);
			mpn_sec_powm(am2_limbs_8[1], a_limbs_8[1], nb_limbs, b_limbs_8[1], 2048, p_limbs, nb_limbs, scratch_powm);
			mpn_sec_powm(am2_limbs_8[2], a_limbs_8[2], nb_limbs, b_limbs_8[2], 2048, p_limbs, nb_limbs, scratch_powm);
			mpn_sec_powm(am2_limbs_8[3], a_limbs_8[3], nb_limbs, b_limbs_8[3], 2048, p_limbs, nb_limbs, scratch_powm);
			mpn_sec_powm(am2_limbs_8[4], a_limbs_8[4], nb_limbs, b_limbs_8[4], 2048, p_limbs, nb_limbs, scratch_powm);
			mpn_sec_powm(am2_limbs_8[5], a_limbs_8[5], nb_limbs, b_limbs_8[5], 2048, p_limbs, nb_limbs, scratch_powm);
			mpn_sec_powm(am2_limbs_8[6], a_limbs_8[6], nb_limbs, b_limbs_8[6], 2048, p_limbs, nb_limbs, scratch_powm);
			mpn_sec_powm(am2_limbs_8[7], a_limbs_8[7], nb_limbs, b_limbs_8[7], 2048, p_limbs, nb_limbs, scratch_powm);
			STAMPP(end3)
			
			if(mini5>end3-start3) mini5 = end3-start3;
			
		}//*/
		

		printf("mpn_sec_powm\n");
		
		
		for(int i=0;i<NTEST;i++)
		{
			BN_mod_exp_mont_consttime(opA_8[i&7], opA_8[i&7], opB_8[i&7], opP, ctx, mont_ctx);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start3)
			BN_mod_exp_mont_consttime(opA_8[0], opA_8[0], opB_8[0], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_8[1], opA_8[1], opB_8[1], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_8[2], opA_8[2], opB_8[2], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_8[3], opA_8[3], opB_8[3], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_8[4], opA_8[4], opB_8[4], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_8[5], opA_8[5], opB_8[5], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_8[6], opA_8[6], opB_8[6], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_8[7], opA_8[7], opB_8[7], opP, ctx, mont_ctx);
			STAMPP(end3)
			
			if(mini2>end3-start3) mini2 = end3-start3;
			
		}//*/

		printf("BN_mod_exp_mont_consttime\n");
		

modexpcc:

		for(int i=0;i<NTEST;i++)
		{
			BN_mod_exp_mont_consttime_x2(opA_8[i&7], opA_8[i&7], opB_8[i&7], opP, mont_ctx,
						opA_8[i&7], opA_8[i&7], opB_8[i&7], opP, mont_ctx,
						ctx);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start3)
			BN_mod_exp_mont_consttime_x2(opA_8[0], opA_8[0], opB_8[0], opP, mont_ctx,
						opA_8[1], opA_8[1], opB_8[1], opP, mont_ctx,
						ctx);
			BN_mod_exp_mont_consttime_x2(opA_8[1], opA_8[1], opB_8[1], opP, mont_ctx,
						opA_8[2], opA_8[2], opB_8[2], opP, mont_ctx,
						ctx);
						
			BN_mod_exp_mont_consttime_x2(opA_8[2], opA_8[2], opB_8[2], opP, mont_ctx,
						opA_8[3], opA_8[3], opB_8[3], opP, mont_ctx,
						ctx);
			BN_mod_exp_mont_consttime_x2(opA_8[3], opA_8[3], opB_8[3], opP, mont_ctx,
						opA_8[4], opA_8[4], opB_8[4], opP, mont_ctx,
						ctx);
			/*BN_mod_exp_mont_consttime_x2(opA_8[4], opA_8[4], opB_8[4], opP, mont_ctx,
						opA_8[5], opA_8[5], opB_8[5], opP, mont_ctx,
						ctx);
			BN_mod_exp_mont_consttime_x2(opA_8[5], opA_8[5], opB_8[5], opP, mont_ctx,
						opA_8[6], opA_8[6], opB_8[6], opP, mont_ctx,
						ctx);
			BN_mod_exp_mont_consttime_x2(opA_8[6], opA_8[6], opB_8[6], opP, mont_ctx,
						opA_8[7], opA_8[7], opB_8[7], opP, mont_ctx,
						ctx);
			BN_mod_exp_mont_consttime_x2(opA_8[7], opA_8[7], opB_8[7], opP, mont_ctx,
						opA_8[0], opA_8[0], opB_8[0], opP, mont_ctx,
						ctx);//*/
			STAMPP(end3)
			
			if(mini1>end3-start3) mini1 = end3-start3;
			
		}//*/
		printf("BN_mod_exp_mont_consttime_x2\n");
		


		
	
		for(int i=0;i<NTEST;i++)
		{
			modExp_8_512(res64, a64, b64, n512, n_prime_512, r2_512);
		}

		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start4)
			modExp_8_512(res64, a64, b64, n512, n_prime_512, r2_512);
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
	
	printf("timer gmp mpn_mont_mul_red_1 (x8)      : %llu\n",timer/NSAMPLES);	

	printf("timer BN_mod_mul_montgomery (x8)       : %llu\n",timer4/NSAMPLES);
	
	printf("timer BN_mod_exp_mont_consttime (x8)   : %llu\n",timer2/(NSAMPLES));
	
	printf("timer gmp mpn_sec_powm (x8)            : %llu\n",timer5/NSAMPLES);

	printf("timer BN_mod_exp_mont_consttimex2 (x4) : %llu\n",timer1/NSAMPLES);	
	
	printf("timer modExp_8_512                     : %llu\n",timer3/NSAMPLES);
	
	
	
	




	//goto fin;
	
	
	
	/********************
	//Instructions !!!!!!!!!!!!!
	*********************/
	printf("\n\n\t  /***************************/\n");
	printf("\t / Instructions !!!!!!!!!!!!!/\n");
	printf("\t/***************************/\n\n");
	
	printf("\ngmp, BN, BN_MONT, //block_mont_mul512_8_2080\n");
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
		
		for(int i=0;i<8;i++)
		{
			countp = 0;
			mpz_urandomm(A8[i], r, modul_p);
			mpz_export(a64[i], &countp, -1, sizeof(a64[0][0]) ,0,0, A8[i]);
			
			
			
			countp = 0;
			mpz_urandomm(B8[i], r, modul_p);
			mpz_export(b64[i], &countp, -1, sizeof(b64[0][0]) ,0,0, B8[i]);
		
		
		
			a64[i][NB_COEFF64-1] = 0x0UL;
			b64[i][NB_COEFF64-1] = 0x0UL;
			
			
			
			
			copy_limbs(a_limbs_8[i], A8[i], nb_limbs);
			copy_limbs(b_limbs_8[i], B8[i], nb_limbs);
			copy_limbs(am1_limbs_8[i], A8[i], nb_limbs);
			copy_limbs(am2_limbs_8[i], A8[i], nb_limbs);
			copy_limbs(bm1_limbs_8[i], B8[i], nb_limbs);
			copy_limbs(bm2_limbs_8[i], B8[i], nb_limbs);
			
			
			BN_dec2bn(&opA_8[i], mpz_get_str (NULL, 10, A8[i]));
			BN_dec2bn(&opB_8[i], mpz_get_str (NULL, 10, B8[i]));
			BN_copy(opAA_8[i], opA_8[i]);
			BN_copy(opBB_8[i], opB_8[i]);



		}
		
		fexpand_8_512_52( a512, a64);

		fexpand_8_512_52( b512, b64);

		
		for(int i=0;i<NTEST;i++)
		{
			mpn_mont_mul_red_1(am1_limbs_8[i&7], am1_limbs_8[i&7], bm1_limbs_8[i&7], p_limbs, mip0, nb_limbs);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			
			start1 = rdpmc_instructions();
			mpn_mont_mul_red_1(am1_limbs_8[0], am1_limbs_8[0], bm1_limbs_8[0], p_limbs, mip0, nb_limbs);
			mpn_mont_mul_red_1(am1_limbs_8[1], am1_limbs_8[1], bm1_limbs_8[1], p_limbs, mip0, nb_limbs);
			mpn_mont_mul_red_1(am1_limbs_8[2], am1_limbs_8[2], bm1_limbs_8[2], p_limbs, mip0, nb_limbs);
			mpn_mont_mul_red_1(am1_limbs_8[3], am1_limbs_8[3], bm1_limbs_8[3], p_limbs, mip0, nb_limbs);
			mpn_mont_mul_red_1(am1_limbs_8[4], am1_limbs_8[4], bm1_limbs_8[4], p_limbs, mip0, nb_limbs);
			mpn_mont_mul_red_1(am1_limbs_8[5], am1_limbs_8[5], bm1_limbs_8[5], p_limbs, mip0, nb_limbs);
			mpn_mont_mul_red_1(am1_limbs_8[6], am1_limbs_8[6], bm1_limbs_8[6], p_limbs, mip0, nb_limbs);
			mpn_mont_mul_red_1(am1_limbs_8[7], am1_limbs_8[7], bm1_limbs_8[7], p_limbs, mip0, nb_limbs);
			end1 = rdpmc_instructions();
			
			if(mini>end1-start1) mini = end1-start1;
			
		}


		for(int i=0;i<NTEST;i++)
		{
			mpn_mont_mul_red_n(am2_limbs_8[i&7], am2_limbs_8[i&7], bm2_limbs_8[i&7], p_limbs, mip_limbs, nb_limbs);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			
			start3 = rdpmc_instructions();
			mpn_mont_mul_red_n(am2_limbs_8[0], am2_limbs_8[0], scratch_powm, p_limbs, mip_limbs, nb_limbs);
			mpn_mont_mul_red_n(am2_limbs_8[1], am2_limbs_8[1], bm2_limbs_8[1], p_limbs, mip_limbs, nb_limbs);
			mpn_mont_mul_red_n(am2_limbs_8[2], am2_limbs_8[2], bm2_limbs_8[2], p_limbs, mip_limbs, nb_limbs);
			mpn_mont_mul_red_n(am2_limbs_8[3], am2_limbs_8[3], bm2_limbs_8[3], p_limbs, mip_limbs, nb_limbs);
			mpn_mont_mul_red_n(am2_limbs_8[4], am2_limbs_8[4], bm2_limbs_8[4], p_limbs, mip_limbs, nb_limbs);
			mpn_mont_mul_red_n(am2_limbs_8[5], am2_limbs_8[5], bm2_limbs_8[5], p_limbs, mip_limbs, nb_limbs);
			mpn_mont_mul_red_n(am2_limbs_8[6], am2_limbs_8[6], bm2_limbs_8[6], p_limbs, mip_limbs, nb_limbs);
			mpn_mont_mul_red_n(am2_limbs_8[7], am2_limbs_8[7], bm2_limbs_8[7], p_limbs, mip_limbs, nb_limbs);
			end3 = rdpmc_instructions();
			
			if(mini1>end3-start3) mini1 = end3-start3;
			
		}//*/



				
	
		for(int i=0;i<NTEST;i++)
		{
			mpn_sec_powm(am2_limbs_8[i&7], a_limbs_8[i&7], nb_limbs, b_limbs_8[i&7], 2048, p_limbs, nb_limbs, bm2_limbs_8[i&7]);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			
			start3 = rdpmc_instructions();
			mpn_sec_powm(am2_limbs_8[0], a_limbs_8[0], nb_limbs, b_limbs_8[0], 2048, p_limbs, nb_limbs, scratch_powm);
			mpn_sec_powm(am2_limbs_8[1], a_limbs_8[1], nb_limbs, b_limbs_8[1], 2048, p_limbs, nb_limbs, scratch_powm);
			mpn_sec_powm(am2_limbs_8[2], a_limbs_8[2], nb_limbs, b_limbs_8[2], 2048, p_limbs, nb_limbs, scratch_powm);
			mpn_sec_powm(am2_limbs_8[3], a_limbs_8[3], nb_limbs, b_limbs_8[3], 2048, p_limbs, nb_limbs, scratch_powm);
			mpn_sec_powm(am2_limbs_8[4], a_limbs_8[4], nb_limbs, b_limbs_8[4], 2048, p_limbs, nb_limbs, scratch_powm);
			mpn_sec_powm(am2_limbs_8[5], a_limbs_8[5], nb_limbs, b_limbs_8[5], 2048, p_limbs, nb_limbs, scratch_powm);
			mpn_sec_powm(am2_limbs_8[6], a_limbs_8[6], nb_limbs, b_limbs_8[6], 2048, p_limbs, nb_limbs, scratch_powm);
			mpn_sec_powm(am2_limbs_8[7], a_limbs_8[7], nb_limbs, b_limbs_8[7], 2048, p_limbs, nb_limbs, scratch_powm);
			end3 = rdpmc_instructions();
			
			if(mini5>end3-start3) mini5 = end3-start3;
			
		}//*/
		
		for(int i=0;i<NTEST;i++)
		{
			BN_mod_exp_mont_consttime_x2(opA_8[i&7], opA_8[i&7], opB_8[i&7], opP, mont_ctx,
						opA_8[i&7], opA_8[i&7], opB_8[i&7], opP, mont_ctx,
						ctx);
		}

		for(int i=0;i<NTEST;i++)
		{
			
			start4 = rdpmc_instructions();
			BN_mod_exp_mont_consttime_x2(opA_8[0], opA_8[0], opB_8[0], opP, mont_ctx,
						opA_8[1], opA_8[1], opB_8[1], opP, mont_ctx,
						ctx);
			BN_mod_exp_mont_consttime_x2(opA_8[1], opA_8[1], opB_8[1], opP, mont_ctx,
						opA_8[2], opA_8[2], opB_8[2], opP, mont_ctx,
						ctx);
						
			BN_mod_exp_mont_consttime_x2(opA_8[2], opA_8[2], opB_8[2], opP, mont_ctx,
						opA_8[3], opA_8[3], opB_8[3], opP, mont_ctx,
						ctx);
			BN_mod_exp_mont_consttime_x2(opA_8[3], opA_8[3], opB_8[3], opP, mont_ctx,
						opA_8[4], opA_8[4], opB_8[4], opP, mont_ctx,
						ctx);
			/*BN_mod_exp_mont_consttime_x2(opA_8[4], opA_8[4], opB_8[4], opP, mont_ctx,
						opA_8[5], opA_8[5], opB_8[5], opP, mont_ctx,
						ctx);
			BN_mod_exp_mont_consttime_x2(opA_8[5], opA_8[5], opB_8[5], opP, mont_ctx,
						opA_8[6], opA_8[6], opB_8[6], opP, mont_ctx,
						ctx);
			BN_mod_exp_mont_consttime_x2(opA_8[6], opA_8[6], opB_8[6], opP, mont_ctx,
						opA_8[7], opA_8[7], opB_8[7], opP, mont_ctx,
						ctx);
			BN_mod_exp_mont_consttime_x2(opA_8[7], opA_8[7], opB_8[7], opP, mont_ctx,
						opA_8[0], opA_8[0], opB_8[0], opP, mont_ctx,
						ctx);//*/
			end4 = rdpmc_instructions();

			if(mini3>end4-start4) mini3 = end4-start4;
			
		}
		
		for(int i=0;i<NTEST;i++)
		{
			BN_mod_exp_mont_consttime(opA_8[i&7], opA_8[i&7], opB_8[i&7], opP, ctx, mont_ctx);
		}
		
			
		for(int i=0;i<NTEST;i++)
		{
			
			start5 = rdpmc_instructions();
			BN_mod_exp_mont_consttime(opA_8[0], opA_8[0], opB_8[0], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_8[1], opA_8[1], opB_8[1], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_8[2], opA_8[2], opB_8[2], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_8[3], opA_8[3], opB_8[3], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_8[4], opA_8[4], opB_8[4], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_8[5], opA_8[5], opB_8[5], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_8[6], opA_8[6], opB_8[6], opP, ctx, mont_ctx);
			BN_mod_exp_mont_consttime(opA_8[7], opA_8[7], opB_8[7], opP, ctx, mont_ctx);
			end5 = rdpmc_instructions();
			
			if(mini4>end5-start5) mini4 = end5-start5;
			
		}
		
modexpinstr:		
		
		
		
		for(int i=0;i<NTEST;i++)
		{
			modExp_8_512(res64, a64, b64, n512, n_prime_512, r2_512);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			start3 = rdpmc_instructions();
			modExp_8_512(res64, a64, b64, n512, n_prime_512, r2_512);
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
	
	printf("gmp mpn_mont_mul_red_1 (x8)      : %llu\n",timer/NSAMPLES);	
	
	printf("gmp mpn_mont_mul_red_n (x8)      : %llu\n",timer1/NSAMPLES);	
	
	printf("gmp mpn_sec_powm (x8)            : %llu\n",timer5/NSAMPLES);
	
	printf("BN_mod_exp_mont_consttimex2 (x4) : %llu\n",timer3/NSAMPLES);

	printf("BN_mod_exp_mont_consttime (x8)   : %llu\n",timer4/NSAMPLES);

	printf("modExp_8_512                     : %llu\n",timer2/NSAMPLES);
	

















fin:	
	
	printf("\nAu revoir et merci !\n");	

	mpz_clears (A, B, C, E, UPB, NULL);
	gmp_randclear(r);

	BN_MONT_CTX_free(mont_ctx);
	BN_CTX_end(ctx);
	BN_CTX_free(ctx);

	free_data(modul_p, p_prime,r2_gmp_512);
	return 0;
}


