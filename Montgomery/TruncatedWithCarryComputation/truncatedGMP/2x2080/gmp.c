


// Fonction multiplication multiprécision
static inline void mult64_64_128(unsigned long int * a, unsigned long int * b, unsigned long int * res)
{
        __asm__ volatile("mov %2,%%rax\n\t"
							"mov %3,%%rdx\n\t"
							"mul %%rdx"
							: "=a" (res[0]),//output
							  "=d" (res[1])
							: "m" (a[0]), "m" (b[0]));//input


	//printf("résultat : %16.16lX*%16.16lX = %16.16lX %16.16lX\n",a[0],b[0],res[1],res[0]);
}




static inline void force_inline mulmodMGMP (uint64_t out[NB_COEFF64], uint64_t a[NB_COEFF64], uint64_t b[NB_COEFF64] )
{

	static const uint64_t mask = 0xffffffffUL;

	uint64_t t[NB_COEFF64<<1], tmp;
	
	for(int i=0;i<NB_COEFF64<<1;i++) t[i] = 0UL;

	for(int i=0;i<NB_COEFF64;i++)
	{
		

		tmp = mpn_addmul_1(t+i,b,NB_COEFF64-i,a[i]);//addition with carry !!! see GMP doc p.55
		//t[] = mpn_add_1(tmp+i+SIZE, tmp+i+SIZE,,tmp);
		/*printf("tmp = ");
		for (j=0;j<SIZE<<1;j++) printf("%16.16lX ",tmp[(SIZE<<1)-1-j]);
		printf(" ;\n\n");*/


	}



	for(int i=0;i<NB_COEFF64;i++) out[i] = t[i];
	
	out[NB_COEFF64-1]= out[NB_COEFF64-1]&mask;




}

static inline void force_inline fmaGMP (uint64_t out[NB_COEFF64<<1], uint64_t a[NB_COEFF64], uint64_t b[NB_COEFF64], uint64_t c[NB_COEFF64<<1])
{

	uint64_t t[40], tmp;
	
	for(int i=0;i<NB_COEFF64<<1;i++) t[i] = c[i];

	for(int i=0;i<NB_COEFF64;i++)
	{
		

		t[i+NB_COEFF64] += mpn_addmul_1(t+i,b,NB_COEFF64,a[i]);//addition with carry !!! see GMP doc p.55
		//t[] = mpn_add_1(tmp+i+SIZE, tmp+i+SIZE,,tmp);
		/*printf("tmp = ");
		for (j=0;j<SIZE<<1;j++) printf("%16.16lX ",tmp[(SIZE<<1)-1-j]);
		printf(" ;\n\n");

		displayVect(t,"t ",NB_COEFF64<<1);
		
		getchar();*/

	}



	for(int i=0;i<NB_COEFF64<<1;i++) out[i] = t[i];




}


#define DEC 32

inline void MontMulGMP(uint64_t out[NB_COEFF64], uint64_t a[NB_COEFF64], uint64_t b[NB_COEFF64], uint64_t N[NB_COEFF64], uint64_t N_prime[NB_COEFF64]){
	
	/*displayVect(a,"a ",NB_COEFF64);
	displayVect(b,"b ",NB_COEFF64);
	
	displayVect(N,"N       ",NB_COEFF64);
	
	displayVect(N_prime,"N_prime ",NB_COEFF64);
	
	displayVect(r,"r       ",NB_COEFF64);//*/
	
	
	uint64_t t[NB_COEFF64<<1], tn[NB_COEFF64<<1],q[NB_COEFF64], qn[NB_COEFF64<<1],tmp[NB_COEFF64<<1];
	mpn_mul_n(t,a,b,NB_COEFF64);// T = axb
	
	
	//displayVect(t,"t ",NB_COEFF64<<1);

	
	//mpn_tdiv_qr ( tmp, tn, 0, t, NB_COEFF64<<1, r,  NB_COEFF64);
	
	//mpn_mul_n(tn,t,N_prime,NB_COEFF64);
	
	//displayVect(tn,"tn ",NB_COEFF64<<1);
	
	//mpn_tdiv_qr ( tmp, q, 0, tn, NB_COEFF64<<1, r,  NB_COEFF64);// q = TxN' mod M
	
	//displayVect(q,"q ",NB_COEFF64);
	
	
	//displayVect(t,"t ",NB_COEFF64<<1);
	
	//printf("\n");//*/
	mulmodMGMP(q,t,N_prime);
	/*mpn_mul_n(qn,q,N,NB_COEFF64);
	
	//displayVect(qn,"qn ",NB_COEFF64<<1);//
	
	
	displayVect(out,"out ",NB_COEFF64<<1);
	
	displayVect(qn,"qn ",NB_COEFF64<<1);//
	
	mpn_add_n(t,t,qn,NB_COEFF64<<1);// T <- T + qN
	
	/*displayVect(t,"t ",NB_COEFF64<<1);
	//*/
	
	fmaGMP(t,q,N,t);
	
	for(int i=0;i<NB_COEFF64;i++) out[i] = (t[i+NB_COEFF64]<<(64-DEC))| (t[i+NB_COEFF64-1]>>DEC);
	

}



static inline void force_inline fmaGMP_truncated (uint64_t out[NB_COEFF64<<1], uint64_t a[NB_COEFF64], uint64_t b[NB_COEFF64], uint64_t c[NB_COEFF64<<1])
{

	uint64_t t[NB_COEFF64<<1], tmp;
	
	//uint64_t tv[NB_COEFF64<<1], tmpv;
	//for(int i=0;i<NB_COEFF64<<1;i++) tv[i] = c[i];
	
	
	for(int i=0;i<NB_COEFF64<<1;i++) t[i] = c[i];

	for(int i=0;i<NB_COEFF64-1;i++)
	{
		
		//printf("i=%d ;\n",i);
		//t[i+NB_COEFF64] += mpn_addmul_1(t+i,b,NB_COEFF64,a[i]);//addition with carry !!! see GMP doc p.55
		//displayVect(tv,"tv ",NB_COEFF64<<1);

		t[i+NB_COEFF64] += mpn_addmul_1(t+NB_COEFF64-2,b+NB_COEFF64-i-2,i+2,a[i]);//addition with carry !!! see GMP doc p.55
		//t[] = mpn_add_1(tmp+i+SIZE, tmp+i+SIZE,,tmp);
		/*printf("tmp = ");
		for (j=0;j<SIZE<<1;j++) printf("%16.16lX ",tmp[(SIZE<<1)-1-j]);
		printf(" ;\n\n");//*/
		//displayVect(t,"t  ",NB_COEFF64<<1);
		
		//getchar();//*/

	}

	//épilogue
	//printf("i= %d;\n",NB_COEFF64-1);
	//tv[NB_COEFF64*2-1] += mpn_addmul_1(tv+NB_COEFF64-1,b,NB_COEFF64,a[NB_COEFF64-1]);//addition with carry !!! see GMP doc p.55
	//displayVect(tv,"tv ",NB_COEFF64<<1);

	t[NB_COEFF64*2-1] += mpn_addmul_1(t+NB_COEFF64-1,b,NB_COEFF64,a[NB_COEFF64-1]);//addition with carry !!! see GMP doc p.55
	//t[] = mpn_add_1(tmp+i+SIZE, tmp+i+SIZE,,tmp);
	/*printf("tmp = ");
	for (j=0;j<SIZE<<1;j++) printf("%16.16lX ",tmp[(SIZE<<1)-1-j]);
	printf(" ;\n\n");//*/
	//displayVect(t,"t  ",NB_COEFF64<<1);
	
	//getchar();//*/


	for(int i=NB_COEFF64-1;i<NB_COEFF64<<1;i++) out[i] = t[i];




}

inline void MontMulGMP_truncated(uint64_t out[NB_COEFF64], uint64_t a[NB_COEFF64], uint64_t b[NB_COEFF64], uint64_t N[NB_COEFF64], uint64_t N_prime[NB_COEFF64]){
	
	/*displayVect(a,"a ",NB_COEFF64);
	displayVect(b,"b ",NB_COEFF64);
	
	displayVect(N,"N       ",NB_COEFF64);
	
	displayVect(N_prime,"N_prime ",NB_COEFF64);
	
	displayVect(r,"r       ",NB_COEFF64);//*/
	
	static const uint64_t mask = 0xffffffff00000000UL;
	
	uint64_t t[NB_COEFF64<<1], tn[NB_COEFF64<<1],q[NB_COEFF64], qn[NB_COEFF64<<1],tmp[NB_COEFF64<<1];
	mpn_mul_n(t,a,b,NB_COEFF64);// T = axb
	
	
	//mpn_mul_n(tn,a,b,NB_COEFF64);// T = axb
	
	//displayVect(t,"t ",NB_COEFF64<<1);

	
	//mpn_tdiv_qr ( tmp, tn, 0, t, NB_COEFF64<<1, r,  NB_COEFF64);
	
	/*mpn_mul_n(tn,t,N_prime,NB_COEFF64);
	
	//displayVect(tn,"tn ",NB_COEFF64<<1);
	
	mpn_tdiv_qr ( tmp, q, 0, tn, NB_COEFF64<<1, r,  NB_COEFF64);// q = TxN' mod M
	mpn_mul_n(qn,q,N,NB_COEFF64);
	
	//displayVect(qn,"qn ",NB_COEFF64<<1);
	
	mpn_add_n(t,t,qn,NB_COEFF64<<1);// T <- T + qN
	
	//printf("\n");//*/
	mulmodMGMP(q,t,N_prime);
	
	//displayVect(q,"q ",NB_COEFF64);
	
	
	//mpn_mul_n(qn,q,N,NB_COEFF64);
	
	uint64_t carry = 0UL;
	for(int i=0;i<NB_COEFF64-1;i++) carry |= t[i];
	
	carry = ((0-carry)&1UL)<<DEC;
	
	//printf("carry = 0x%16.16lX\n",carry);
	
	fmaGMP_truncated(t,q,N,t);
	
	//printf("fmaGMP_truncated\n");
	//displayVect(t+NB_COEFF64-1,"t ",NB_COEFF64+1);
	
	t[NB_COEFF64-1]+=carry;
	
	t[NB_COEFF64-1]&=mask;
	
	
	//mpn_add_1(t+NB_COEFF64,t+NB_COEFF64,NB_COEFF64,carry);
	
	/*
	
	displayVect(t+NB_COEFF64-1,"t ",NB_COEFF64+1);
	
	
	printf("fmaGMP\n");
	fmaGMP(tn,q,N,tn);
	
	displayVect(tn+NB_COEFF64-1,"tn",NB_COEFF64+1);
	
	
	
	getchar();
	
	displayVect(out,"out ",NB_COEFF64<<1);
	
	displayVect(qn,"qn ",NB_COEFF64<<1);
	
	mpn_add_n(t,t,qn,NB_COEFF64<<1);// T <- T + qN
	
	displayVect(t,"t ",NB_COEFF64<<1);
	//*/
	
	
	for(int i=0;i<NB_COEFF64;i++) out[i] = (t[i+NB_COEFF64]<<(64-DEC))| (t[i+NB_COEFF64-1]>>DEC);
	

}


