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

#define NTEST 1000
//~ Compilation command : gcc -Wall -O3 main.c -o main -lgmp -lcrypto
//~ Execution command : ./main

//~ Important : polynomials representations form is P(X) = a0 + ... + an.X^n = (a0, ..., an).



void init_data(mpz_t modul_p, mpz_t p_prime, mpz_t r2_gmp_512){

	printf("init_data()\n");

	mpz_inits (modul_p, p_prime, r2_gmp_512, NULL);

/*   Montgomery parameters !*/

	mpz_set_str(modul_p, "911313666316743987009906420269031298049793538650769224345225378008811558365323551934202165029224238025690447669788907146083478725392582314871949883909726524381574163251028505426225766450473344058099396013189046285858162243048739109677177476127140397358236041200179041544719544545727858488975934458089385509786425511197874243908910501950926484232755768411276169308647977169175134518862347545343174071973406334904476565494459262298841233980100102103434897895683744848509558625225013032703809342036382092389291595327905260823538433915122309565808592976669135775294610220206219670072485720698797778566581775165334459963319000169953291116219732947902294733345480531713349175888624112835533633834248919369630617903998194994539734062013991751834608073682710902957031138709917470333160985115240258944493914444195999223675840951808190028527264220291226442603355301297314527238497391733778987692747609635337252986266679420440069398404035132470469577699745077218513529931511933020673005601018499449348309286868503033132418281978462308811015420211970294573102198380565580940538718957785934787972792493363983898888983330749283808616414548114757025706043211014505911003720119363916941881401961897472201045262190440263451885670208552213615956623973",10);
	mpz_set_str(p_prime, "44696593857891871342815954072595365304384137396920076562027799024923881355917279132286799051958736023954444541842219617183911257978133471654020176044067758727676594765196087270416478798584008847209647272080666471347374882888354331475420939211264039332061742409593818041161411640377412270100907803902022855981252151669927880783337911551761765009068348289680987097583989611281917093178356383638450967915147287969678608481649462231995133822329290951883794853738164239685793225084078477396813315565108792736017481805919254902819840070363242036426564104422672375098175931872869451230047378074330241133054200387520764350705955208303724472841333657589237016995960212588798927575813594521120045906790099167339132949915537854679604835364384593664420894245742314913140404694066021125863874780654367645108040717263895836387821014402155147541554304546609384784554576343369388738873969268245438183309055121004823337799764276871622787660314232833883231499468667349721499751145855915396633038282967548543018342299327652039845197565603695802547542463283264318328882408591470554702944340273058419616121036408435208687673754335601033589367295685580415015800316695341809042845569664240476379469817250060389748130545698831762580709634806695278613905468432543629653352595",10);
	mpz_set_str(r2_gmp_512, "571802793311862797659578422018240122151248139208893885637794795176956904638248699768468091277949357774698972871551993603508886076118936373982580272060201979336553049141281252898508829434997054815319098045825052623783632342295046053674471767405908292330510750305803688254232220415008082650633178703288619187802835406553956302078217316173856029835516557380586601350884373285080678447251549539534494560702108362364597553965620117606619478367764143826602086591574853726519529931448967779179878351499529924098587630162999851177873309596858583876036114720752347191396674672706057945181001804457233019358499516273913434662066309783300069145383913673208162548627709355289018743017092497222683800524820389495902215870352331239477943394237612602951803685825677107094869636852503116455535208371513658245457542462690741566349492299670166305244427018149256564085140900572530836733986698040072808689115149330787464616260150565401846593282960281294248680266098848551391572842325292161328116261391915026876111376686988653181227542697845378164309033270479350126756327486833929501700718720220666981739041590116432228857430193886883301171890677022369848578512053488012506655157192669597773744909552770526159660799692382385393057519074830036005880810787",10);



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

	static mpz_t modul_p, p_prime, r2_gmp_512;
	mpz_t A, B, C, E, F, R2, R3, G, H, UPB;
	mpz_inits (A, B, C, E, F, R2, R3, G, H, UPB, NULL);

	//mpz_inits (A, B, C, E, F, R2, R3, G, H, UPB, modul_p, p_prime, NULL);
	init_data(modul_p, p_prime, r2_gmp_512);
	
	mpz_ui_pow_ui ( UPB, 2UL, SIZE );
	
	
	printf("%lu %d  %d\n\n", mpz_sizeinbase (UPB, 2), NB_COEFF, NB_COEFF64);
	gmp_printf("UPB  : 0x%ZX\n\n\n", UPB);

	gmp_printf("modul_p  : 0x%ZX\n\n\n", modul_p);
	gmp_printf("p_prime  : 0x%ZX\n\n\n", p_prime);
	gmp_printf("r2_512   : 0x%ZX\n\n\n", r2_gmp_512	);
	
	
	printf("\t  /*******************************/\n");
	printf("\t /   Test on 1 dataset   /\n");
	printf("\t/*******************************/\n\n");

	mp_limb_t mip0;
	
	const mp_limb_t *p_limbs;
	mp_limb_t *r2_limbs, *scratch_limbs, *mip_limbs;
	mp_limb_t *a_limbs, *b_limbs, *am1_limbs, *am2_limbs, *bm1_limbs, *bm2_limbs;
	
	//init_data(modul_p,p_prime);
	
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



	//goto end;


		
	// a512 and b512 contain 8 values in columns	
	__m512i a512[NB_COEFF], b512[NB_COEFF], res512[NB_COEFF], aMont512[NB_COEFF], bMont512[NB_COEFF], resMont512[NB_COEFF];
	
	__m512i n512[NB_COEFF], n_prime512[NB_COEFF], r2_512[NB_COEFF], un512[NB_COEFF];
	
	
		mpz_t A8[8], B8[8], C8[8], E8[8];
	for(int i=0;i<8;i++)	
		mpz_inits (A8[i], B8[i], C8[i], E8[i], NULL);
	uint64_t a64[8][NB_COEFF64], b64[8][NB_COEFF64], c64[8][NB_COEFF64], res64[8][NB_COEFF64];
	
	//mp_limb_t *r2_limbs_8[8][nb_limbs];
	mp_limb_t a_limbs_8[8][nb_limbs], b_limbs_8[8][nb_limbs], am1_limbs_8[8][nb_limbs], am2_limbs_8[8][nb_limbs], bm1_limbs_8[8][nb_limbs], bm2_limbs_8[8][nb_limbs];

	
	
	//Initialisation of Montgomery batch parameters
	
	
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

	fexpand_8_512_4154KK( n512, a64);

	displayVect512_NB_COEFF(n512,"n512");

	// p_prime = (-modul_p)^-1 mod R
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<NB_COEFF64;j++)
			a64[i][j] = 0x0UL;
	}
	
	for(int i=0;i<8;i++)
	{
		mpz_export(a64[i], &countp, -1, sizeof(a64[0][0]) ,0,0, p_prime);
	
	}

	fexpand_8_512_4154KK( n_prime512, a64);

	displayVect512_NB_COEFF(n_prime512,"n_prime512");

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

	fexpand_8_512_4154KK( r2_512, a64);

	displayVect512_NB_COEFF(r2_512,"r2_512");
	
	// 1 512 !
	for(int i=0;i<8;i++)
	{
		a64[i][0] = 0x1UL;
		for(int j=1;j<NB_COEFF64;j++)
			a64[i][j] = 0x0UL;
	}
	
	fexpand_8_512_4154KK( un512, a64);

	displayVect512_NB_COEFF(un512,"un512");
	
	//getchar();





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


	


	fexpand_8_512_4154KK( b512, b64);
	fexpand_8_512_4154KK( a512, a64);


	for(int i=0;i<8;i++)
		displayVect(a64[i],"a64[i]     ",NB_COEFF64);
	displayVect512_NB_COEFF(a512,"a512");


	for(int i=0;i<8;i++)
		displayVect(b64[i],"b64[i]     ",NB_COEFF64);
	
	displayVect512_NB_COEFF(b512,"b512");
	
	
	printf("fcontract_8_512_4154KK()\n");
	fcontract_8_512_4154KK( c64, a512);
	
	
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
	
	// conversion into Montgomery domain
	mont_mul512_8_4154KK(aMont512, a512, r2_512, n512, n_prime512);
	mont_mul512_8_4154KK(bMont512, b512, r2_512, n512, n_prime512);
	
	displayVect512_NB_COEFF(aMont512,"aMont512");
	for(int i=0;i<8;i++)
	{
		from_limbs_to_mpz_t(G, am1_limbs_8[i], nb_limbs);
		gmp_printf("am1_limbs_8 : %ZX\n", G);//*/
	}
	displayVect512_NB_COEFF(bMont512,"bMont512");
	
	//fcontract_8_512_4154KK( c64, a512);
	
	
	mont_mul512_8_4154KK(resMont512, aMont512, bMont512, n512, n_prime512);
	
	// back to standard domain
	
	mont_mul512_8_4154KK(res512, resMont512, un512, n512, n_prime512);
	
	
	
	
	displayVect512_NB_COEFF(res512,"res512_lo");
	
	//displayVect512_NB_COEFF(res512+NB_COEFF,"res512_hi");
	
	fcontract_8_512_4154KK(res64, res512);
	
	
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
		displayVect(res_gmp, "res_gmp     ",countp);//NB_COEFF64*2);
		displayVect(res64[i],"res64[i]    ",NB_COEFF64);
		for(int j=0; j<NB_COEFF64;j++)
			if(res64[i][j]^res_gmp[j]) flag++;
		flag?counter++,flag=0:counter,flag=0;//*/
		printf("\n");
		
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


		fexpand_8_512_4154KK( a512, a64);

		fexpand_8_512_4154KK( b512, b64);


		
		// conversion into Montgomery domain
		mont_mul512_8_4154KK(aMont512, a512, r2_512, n512, n_prime512);
		mont_mul512_8_4154KK(bMont512, b512, r2_512, n512, n_prime512);
		
		//displayVect512_NB_COEFF(aMont512,"aMont512");
		//displayVect512_NB_COEFF(bMont512,"bMont512");
		
		
		mont_mul512_8_4154KK(resMont512, aMont512, bMont512, n512, n_prime512);
		
		// back to standard domain
		
		mont_mul512_8_4154KK(res512, resMont512, un512, n512, n_prime512);
		
		fcontract_8_512_4154KK(res64, res512);
		
		for(int i=0;i<8;i++)
		{
			
			//gmp_printf("A8[i] : %ZX\n", A8[i]);
			//gmp_printf("B8[i] : %ZX\n", B8[i]);
			
			mpn_mont_mul_red_1(am1_limbs_8[i], am1_limbs_8[i], bm1_limbs_8[i], p_limbs, mip0, nb_limbs);
			clean_limbs(scratch_limbs, 2*nb_limbs);
			for(int j=0; j<nb_limbs; j++)
				scratch_limbs[j] = am1_limbs_8[i][j];
			mpn_redc_1 (am1_limbs_8[i], scratch_limbs, p_limbs, nb_limbs, mip0);
			from_limbs_to_mpz_t(G, am1_limbs_8[i], nb_limbs);
			//gmp_printf("r_mbgmp : %ZX\n", G);//*/


			//~ Montgomery modular multiplication (classic mont)
			mpn_mont_mul_red_n(am2_limbs_8[i], am2_limbs_8[i], bm2_limbs_8[i], p_limbs, mip_limbs, nb_limbs);
			
			clean_limbs(scratch_limbs, 2*nb_limbs);
			for(int j=0; j<nb_limbs; j++)
				scratch_limbs[j] = am2_limbs_8[i][j];
			mpn_redc_n (am2_limbs_8[i], scratch_limbs, p_limbs, nb_limbs, mip_limbs);
			from_limbs_to_mpz_t(H, am2_limbs_8[i], nb_limbs);
			//gmp_printf("r_mcgmp : %ZX\n", H);
			
			
			//~ Montgomery low level modular multiplication
			mpn_mod_mult(a_limbs_8[i], a_limbs_8[i], b_limbs_8[i], p_limbs, nb_limbs);
			from_limbs_to_mpz_t(F, a_limbs_8[i], nb_limbs);
			//gmp_printf("r_lgmp  : %ZX\n", F);


			mpz_export(res_gmp, &countp, -1, sizeof(b64[0][0]) ,0,0, G);
			//displayVect(res_gmp, "res_gmp     ",countp);//NB_COEFF64*2);
			//displayVect(res64[i],"res64[i]    ",NB_COEFF64);
			for(int j=0; j<NB_COEFF64;j++)
				if(res64[i][j]^res_gmp[j]) flag++;
			flag?counter++,flag=0:counter,flag=0;//*/
			//printf("\n");
			
		}
	}
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;



	//goto end;
	
	printf("\t  /***********************************/\n");
	printf("\t /   Test on 1000 datasets   /\n");
	printf("\t/***********************************/\n\n");

	
	printf("Montgomery Squaring\n");
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
			
			
			
			
			//b_limbs_8[i] = mpz_limbs_modify (B8[i], nb_limbs);
			copy_limbs(a_limbs_8[i], A8[i], nb_limbs);
			copy_limbs(b_limbs_8[i], B8[i], nb_limbs);
			copy_limbs(am1_limbs_8[i], A8[i], nb_limbs);
			copy_limbs(am2_limbs_8[i], A8[i], nb_limbs);
			
			
			//~ conversion to Montgomery domain (block mont)
			mpn_mont_mul_red_1(am1_limbs_8[i], am1_limbs_8[i], r2_limbs, p_limbs, mip0, nb_limbs);
		
			//~ conversion to Montgomery domain (classic mont)
			mpn_mont_mul_red_n(am2_limbs_8[i], am2_limbs_8[i], r2_limbs, p_limbs, mip_limbs, nb_limbs);
		}


		fexpand_8_512_4154KK( a512, a64);



		
		// conversion into Montgomery domain
		mont_mul512_8_4154KK(aMont512, a512, r2_512, n512, n_prime512);
		mont_mul512_8_4154KK(bMont512, b512, r2_512, n512, n_prime512);
		
		//displayVect512_NB_COEFF(aMont512,"aMont512");
		//displayVect512_NB_COEFF(bMont512,"bMont512");
		
		
		mont_square512_8_4154KK(resMont512, aMont512, n512, n_prime512);
		
		// back to standard domain
		
		mont_mul512_8_4154KK(res512, resMont512, un512, n512, n_prime512);
		
		fcontract_8_512_4154KK(res64, res512);
		
		for(int i=0;i<8;i++)
		{
			
			//gmp_printf("A8[i] : %ZX\n", A8[i]);
			//gmp_printf("B8[i] : %ZX\n", B8[i]);
			
			mpn_mont_mul_red_1(am1_limbs_8[i], am1_limbs_8[i], am1_limbs_8[i], p_limbs, mip0, nb_limbs);
			clean_limbs(scratch_limbs, 2*nb_limbs);
			for(int j=0; j<nb_limbs; j++)
				scratch_limbs[j] = am1_limbs_8[i][j];
			mpn_redc_1 (am1_limbs_8[i], scratch_limbs, p_limbs, nb_limbs, mip0);
			from_limbs_to_mpz_t(G, am1_limbs_8[i], nb_limbs);
			//gmp_printf("r_mbgmp : %ZX\n", G);//*/


			//~ Montgomery modular multiplication (classic mont)
			mpn_mont_mul_red_n(am2_limbs_8[i], am2_limbs_8[i], am2_limbs_8[i], p_limbs, mip_limbs, nb_limbs);
			
			clean_limbs(scratch_limbs, 2*nb_limbs);
			for(int j=0; j<nb_limbs; j++)
				scratch_limbs[j] = am2_limbs_8[i][j];
			mpn_redc_n (am2_limbs_8[i], scratch_limbs, p_limbs, nb_limbs, mip_limbs);
			from_limbs_to_mpz_t(H, am2_limbs_8[i], nb_limbs);
			//gmp_printf("r_mcgmp : %ZX\n", H);
			
			
			//~ Montgomery low level modular multiplication
			mpn_mod_mult(a_limbs_8[i], a_limbs_8[i], a_limbs_8[i], p_limbs, nb_limbs);
			from_limbs_to_mpz_t(F, a_limbs_8[i], nb_limbs);
			//gmp_printf("r_lgmp  : %ZX\n", F);


			mpz_export(res_gmp, &countp, -1, sizeof(b64[0][0]) ,0,0, G);
			//displayVect(res_gmp, "res_gmp     ",countp);//NB_COEFF64*2);
			//displayVect(res64[i],"res64[i]    ",NB_COEFF64);
			for(int j=0; j<NB_COEFF64;j++)
				if(res64[i][j]^res_gmp[j]) flag++;
				
			
			flag?counter++,flag=0:counter,flag=0;//*/
			//printf("\n");
			
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
	
	printf("\ngmp, BN, BN_MONT, mont_mul512_8_4154KK, mont_square512_8_4154KK\n");
	printf("-----------------------------------------------------------\n");

	BIGNUM *opA_8[8];
	BIGNUM *opB_8[8];
	BIGNUM *opAA_8[8];
	BIGNUM *opBB_8[8];



	for(int i=0;i<8;i++)
	{
		opA_8[i] = BN_CTX_get(ctx);
		opB_8[i] = BN_CTX_get(ctx);
		opAA_8[i] = BN_CTX_get(ctx);
		opBB_8[i] = BN_CTX_get(ctx);
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
		
		fexpand_8_512_4154KK( a512, a64);

		fexpand_8_512_4154KK( b512, b64);

		
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


		for(int i=0;i<NTEST;i++)
		{
			mpn_mont_mul_red_n(am2_limbs_8[i&7], am2_limbs_8[i&7], bm2_limbs_8[i&7], p_limbs, mip_limbs, nb_limbs);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start3)
			mpn_mont_mul_red_n(am2_limbs_8[0], am2_limbs_8[0], bm2_limbs_8[0], p_limbs, mip_limbs, nb_limbs);
			mpn_mont_mul_red_n(am2_limbs_8[1], am2_limbs_8[1], bm2_limbs_8[1], p_limbs, mip_limbs, nb_limbs);
			mpn_mont_mul_red_n(am2_limbs_8[2], am2_limbs_8[2], bm2_limbs_8[2], p_limbs, mip_limbs, nb_limbs);
			mpn_mont_mul_red_n(am2_limbs_8[3], am2_limbs_8[3], bm2_limbs_8[3], p_limbs, mip_limbs, nb_limbs);
			mpn_mont_mul_red_n(am2_limbs_8[4], am2_limbs_8[4], bm2_limbs_8[4], p_limbs, mip_limbs, nb_limbs);
			mpn_mont_mul_red_n(am2_limbs_8[5], am2_limbs_8[5], bm2_limbs_8[5], p_limbs, mip_limbs, nb_limbs);
			mpn_mont_mul_red_n(am2_limbs_8[6], am2_limbs_8[6], bm2_limbs_8[6], p_limbs, mip_limbs, nb_limbs);
			mpn_mont_mul_red_n(am2_limbs_8[7], am2_limbs_8[7], bm2_limbs_8[7], p_limbs, mip_limbs, nb_limbs);
			STAMPP(end3)
			
			if(mini1>end3-start3) mini1 = end3-start3;
			
		}//*/


				
	
		for(int i=0;i<NTEST;i++)
		{
			mpn_mod_mult(a_limbs_8[i&7], a_limbs_8[i&7], b_limbs_8[i&7], p_limbs, nb_limbs);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start3)
			mpn_mod_mult(a_limbs_8[0], a_limbs_8[0], b_limbs_8[0], p_limbs, nb_limbs);
			mpn_mod_mult(a_limbs_8[1], a_limbs_8[1], b_limbs_8[1], p_limbs, nb_limbs);
			mpn_mod_mult(a_limbs_8[2], a_limbs_8[2], b_limbs_8[2], p_limbs, nb_limbs);
			mpn_mod_mult(a_limbs_8[3], a_limbs_8[3], b_limbs_8[3], p_limbs, nb_limbs);
			mpn_mod_mult(a_limbs_8[4], a_limbs_8[4], b_limbs_8[4], p_limbs, nb_limbs);
			mpn_mod_mult(a_limbs_8[5], a_limbs_8[5], b_limbs_8[5], p_limbs, nb_limbs);
			mpn_mod_mult(a_limbs_8[6], a_limbs_8[6], b_limbs_8[6], p_limbs, nb_limbs);
			mpn_mod_mult(a_limbs_8[7], a_limbs_8[7], b_limbs_8[7], p_limbs, nb_limbs);
			STAMPP(end3)
			
			if(mini5>end3-start3) mini5 = end3-start3;
			
		}//*/
		
	
		for(int i=0;i<NTEST;i++)
		{
			BN_mod_mul(opAA_8[i&7], opAA_8[i&7], opBB_8[i&7], opP, ctx);
		}

		for(int i=0;i<NTEST;i++)
		{
			
			STAMP(start4)
			BN_mod_mul(opAA_8[0], opAA_8[0], opBB_8[0], opP, ctx);
			BN_mod_mul(opAA_8[1], opAA_8[1], opBB_8[1], opP, ctx);
			BN_mod_mul(opAA_8[2], opAA_8[2], opBB_8[2], opP, ctx);
			BN_mod_mul(opAA_8[3], opAA_8[3], opBB_8[3], opP, ctx);
			BN_mod_mul(opAA_8[4], opAA_8[4], opBB_8[4], opP, ctx);
			BN_mod_mul(opAA_8[5], opAA_8[5], opBB_8[5], opP, ctx);
			BN_mod_mul(opAA_8[6], opAA_8[6], opBB_8[6], opP, ctx);
			BN_mod_mul(opAA_8[7], opAA_8[7], opBB_8[7], opP, ctx);
			STAMPP(end4)

			if(mini3>end4-start4) mini3 = end4-start4;
			
		}
		
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
		
		
		
		for(int i=0;i<NTEST;i++)
		{
			mont_mul512_8_4154KK(res512, a512, b512, n512, n_prime512);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			STAMP(start3)
			mont_mul512_8_4154KK(res512, a512, b512, n512, n_prime512);
			mont_mul512_8_4154KK(res512, a512, b512, n512, n_prime512);
			mont_mul512_8_4154KK(res512, a512, b512, n512, n_prime512);
			mont_mul512_8_4154KK(res512, a512, b512, n512, n_prime512);
			mont_mul512_8_4154KK(res512, a512, b512, n512, n_prime512);
			mont_mul512_8_4154KK(res512, a512, b512, n512, n_prime512);
			mont_mul512_8_4154KK(res512, a512, b512, n512, n_prime512);
			mont_mul512_8_4154KK(res512, a512, b512, n512, n_prime512);
			mont_mul512_8_4154KK(res512, a512, b512, n512, n_prime512);
			mont_mul512_8_4154KK(res512, a512, b512, n512, n_prime512);
			STAMPP(end3)
			
			if(mini2>end3-start3) mini2 = end3-start3;
			
		}	
		
		for(int i=0;i<NTEST;i++)
		{
			mont_square512_8_4154KK(res512, a512, n512, n_prime512);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			STAMP(start3)
			mont_square512_8_4154KK(res512, a512, n512, n_prime512);
			mont_square512_8_4154KK(res512, a512, n512, n_prime512);
			mont_square512_8_4154KK(res512, a512, n512, n_prime512);
			mont_square512_8_4154KK(res512, a512, n512, n_prime512);
			mont_square512_8_4154KK(res512, a512, n512, n_prime512);
			mont_square512_8_4154KK(res512, a512, n512, n_prime512);
			mont_square512_8_4154KK(res512, a512, n512, n_prime512);
			mont_square512_8_4154KK(res512, a512, n512, n_prime512);
			mont_square512_8_4154KK(res512, a512, n512, n_prime512);
			mont_square512_8_4154KK(res512, a512, n512, n_prime512);
			STAMPP(end3)
			
			if(mini6>end3-start3) mini6 = end3-start3;
			
		}

		timer += mini;

		timer1 += mini1;
		
		timer2 += mini2;
		
		timer3 += mini3;

		timer4 += mini4;
		
		timer5 += mini5;
		
		timer6 += mini6;
	}
	
	printf("timer gmp mpn_mont_mul_red_1 (x8)  : %llu\n",timer/NSAMPLES);	
	
	printf("timer gmp mpn_mont_mul_red_n (x8)  : %llu\n",timer1/NSAMPLES);	
	
	printf("timer gmp mpn_mod_mult (x8)        : %llu\n",timer5/NSAMPLES);
	
	printf("timer BN_mod_mul (x8)              : %llu\n",timer3/NSAMPLES);

	printf("timer BN_mod_mul_montgomery (x8)   : %llu\n",timer4/NSAMPLES);

	printf("timer mont_mul512_8_4154KK          : %llu\n",timer2/(NSAMPLES*10));
	
	printf("timer mont_square512_8_4154KK       : %llu\n",timer6/(NSAMPLES*10));
	
	
	




	//goto end;
	
	
	
	/********************
	//Instructions !!!!!!!!!!!!!
	*********************/
	printf("\n\n\t  /***************************/\n");
	printf("\t / Instructions !!!!!!!!!!!!!/\n");
	printf("\t/***************************/\n\n");
	
	printf("\ngmp, BN, BN_MONT, mont_mul512_8_4154KK, mont_square512_8_4154KK\n");
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
		
		fexpand_8_512_4154KK( a512, a64);

		fexpand_8_512_4154KK( b512, b64);

		
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
			mpn_mont_mul_red_n(am2_limbs_8[0], am2_limbs_8[0], bm2_limbs_8[0], p_limbs, mip_limbs, nb_limbs);
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
			mpn_mod_mult(a_limbs_8[i&7], a_limbs_8[i&7], b_limbs_8[i&7], p_limbs, nb_limbs);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			
			start3 = rdpmc_instructions();
			mpn_mod_mult(a_limbs_8[0], a_limbs_8[0], b_limbs_8[0], p_limbs, nb_limbs);
			mpn_mod_mult(a_limbs_8[1], a_limbs_8[1], b_limbs_8[1], p_limbs, nb_limbs);
			mpn_mod_mult(a_limbs_8[2], a_limbs_8[2], b_limbs_8[2], p_limbs, nb_limbs);
			mpn_mod_mult(a_limbs_8[3], a_limbs_8[3], b_limbs_8[3], p_limbs, nb_limbs);
			mpn_mod_mult(a_limbs_8[4], a_limbs_8[4], b_limbs_8[4], p_limbs, nb_limbs);
			mpn_mod_mult(a_limbs_8[5], a_limbs_8[5], b_limbs_8[5], p_limbs, nb_limbs);
			mpn_mod_mult(a_limbs_8[6], a_limbs_8[6], b_limbs_8[6], p_limbs, nb_limbs);
			mpn_mod_mult(a_limbs_8[7], a_limbs_8[7], b_limbs_8[7], p_limbs, nb_limbs);
			end3 = rdpmc_instructions();
			
			if(mini5>end3-start3) mini5 = end3-start3;
			
		}//*/
		
	
		for(int i=0;i<NTEST;i++)
		{
			BN_mod_mul(opAA_8[i&7], opAA_8[i&7], opBB_8[i&7], opP, ctx);
		}

		for(int i=0;i<NTEST;i++)
		{
			
			start4 = rdpmc_instructions();
			BN_mod_mul(opAA_8[0], opAA_8[0], opBB_8[0], opP, ctx);
			BN_mod_mul(opAA_8[1], opAA_8[1], opBB_8[1], opP, ctx);
			BN_mod_mul(opAA_8[2], opAA_8[2], opBB_8[2], opP, ctx);
			BN_mod_mul(opAA_8[3], opAA_8[3], opBB_8[3], opP, ctx);
			BN_mod_mul(opAA_8[4], opAA_8[4], opBB_8[4], opP, ctx);
			BN_mod_mul(opAA_8[5], opAA_8[5], opBB_8[5], opP, ctx);
			BN_mod_mul(opAA_8[6], opAA_8[6], opBB_8[6], opP, ctx);
			BN_mod_mul(opAA_8[7], opAA_8[7], opBB_8[7], opP, ctx);
			end4 = rdpmc_instructions();

			if(mini3>end4-start4) mini3 = end4-start4;
			
		}
		
		for(int i=0;i<NTEST;i++)
		{
			BN_mod_mul_montgomery(opA_8[i&7], opA_8[i&7], opB_8[i&7], mont_ctx, ctx);
		}
		
			
		for(int i=0;i<NTEST;i++)
		{
			
			start5 = rdpmc_instructions();
			BN_mod_mul_montgomery(opA_8[0], opA_8[0], opB_8[0], mont_ctx, ctx);
			BN_mod_mul_montgomery(opA_8[1], opA_8[1], opB_8[1], mont_ctx, ctx);
			BN_mod_mul_montgomery(opA_8[2], opA_8[2], opB_8[2], mont_ctx, ctx);
			BN_mod_mul_montgomery(opA_8[3], opA_8[3], opB_8[3], mont_ctx, ctx);
			BN_mod_mul_montgomery(opA_8[4], opA_8[4], opB_8[4], mont_ctx, ctx);
			BN_mod_mul_montgomery(opA_8[5], opA_8[5], opB_8[5], mont_ctx, ctx);
			BN_mod_mul_montgomery(opA_8[6], opA_8[6], opB_8[6], mont_ctx, ctx);
			BN_mod_mul_montgomery(opA_8[7], opA_8[7], opB_8[7], mont_ctx, ctx);
			end5 = rdpmc_instructions();
			
			if(mini4>end5-start5) mini4 = end5-start5;
			
		}
		
		
		
		for(int i=0;i<NTEST;i++)
		{
			mont_mul512_8_4154KK(res512, a512, b512, n512, n_prime512);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			start3 = rdpmc_instructions();
			mont_mul512_8_4154KK(res512, a512, b512, n512, n_prime512);
			mont_mul512_8_4154KK(res512, a512, b512, n512, n_prime512);
			mont_mul512_8_4154KK(res512, a512, b512, n512, n_prime512);
			mont_mul512_8_4154KK(res512, a512, b512, n512, n_prime512);
			mont_mul512_8_4154KK(res512, a512, b512, n512, n_prime512);
			mont_mul512_8_4154KK(res512, a512, b512, n512, n_prime512);
			mont_mul512_8_4154KK(res512, a512, b512, n512, n_prime512);
			mont_mul512_8_4154KK(res512, a512, b512, n512, n_prime512);
			mont_mul512_8_4154KK(res512, a512, b512, n512, n_prime512);
			mont_mul512_8_4154KK(res512, a512, b512, n512, n_prime512);
			end3 = rdpmc_instructions();
			
			if(mini2>end3-start3) mini2 = end3-start3;
			
		}	
		
		for(int i=0;i<NTEST;i++)
		{
			mont_square512_8_4154KK(res512, a512, n512, n_prime512);
		}
		
		for(int i=0;i<NTEST;i++)
		{
			start3 = rdpmc_instructions();
			mont_square512_8_4154KK(res512, a512, n512, n_prime512);
			mont_square512_8_4154KK(res512, a512, n512, n_prime512);
			mont_square512_8_4154KK(res512, a512, n512, n_prime512);
			mont_square512_8_4154KK(res512, a512, n512, n_prime512);
			mont_square512_8_4154KK(res512, a512, n512, n_prime512);
			mont_square512_8_4154KK(res512, a512, n512, n_prime512);
			mont_square512_8_4154KK(res512, a512, n512, n_prime512);
			mont_square512_8_4154KK(res512, a512, n512, n_prime512);
			mont_square512_8_4154KK(res512, a512, n512, n_prime512);
			mont_square512_8_4154KK(res512, a512, n512, n_prime512);
			end3 = rdpmc_instructions();
			
			if(mini6>end3-start3) mini6 = end3-start3;
			
		}

		timer += mini;

		timer1 += mini1;
		
		timer2 += mini2;
		
		timer3 += mini3;

		timer4 += mini4;
		
		timer5 += mini5;
		
		timer6 += mini6;
	}
	
	printf("gmp mpn_mont_mul_red_1 (x8)  : %llu\n",timer/NSAMPLES);	
	
	printf("gmp mpn_mont_mul_red_n (x8)  : %llu\n",timer1/NSAMPLES);	
	
	printf("gmp mpn_mod_mult (x8)        : %llu\n",timer5/NSAMPLES);
	
	printf("BN_mod_mul (x8)              : %llu\n",timer3/NSAMPLES);

	printf("BN_mod_mul_montgomery (x8)   : %llu\n",timer4/NSAMPLES);

	printf("mont_mul512_8_4154KK          : %llu\n",timer2/(NSAMPLES*10));
	
	printf("mont_square512_8_4154KK       : %llu\n",timer6/(NSAMPLES*10));
	



















end:	
	
	printf("\nAu revoir and merci !\n");	

	mpz_clears (A, B, C, E, UPB, NULL);
	gmp_randclear(r);

	BN_MONT_CTX_free(mont_ctx);
	BN_CTX_end(ctx);
	BN_CTX_free(ctx);

	free_data(modul_p, p_prime, r2_gmp_512);
	return 0;
}

