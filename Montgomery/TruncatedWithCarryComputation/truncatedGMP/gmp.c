


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

	uint64_t t[40], tmp;
	
	for(int i=0;i<NB_COEFF64;i++) t[i] = 0UL;

	for(int i=0;i<NB_COEFF64;i++)
	{
		

		tmp = mpn_addmul_1(t+i,b,NB_COEFF64-i,a[i]);//addition with carry !!! see GMP doc p.55
		//t[] = mpn_add_1(tmp+i+SIZE, tmp+i+SIZE,,tmp);
		/*printf("tmp = ");
		for (j=0;j<SIZE<<1;j++) printf("%16.16lX ",tmp[(SIZE<<1)-1-j]);
		printf(" ;\n\n");*/


	}



	for(int i=0;i<NB_COEFF64;i++) out[i] = t[i];




}


static inline void force_inline fmaGMP_truncated (uint64_t out[NB_COEFF64], uint64_t a[NB_COEFF64], uint64_t b[NB_COEFF64], uint64_t c[NB_COEFF64<<1])
{

	uint64_t t[40], tmp;
	
	for(int i=0;i<NB_COEFF64<<1;i++) t[i] = c[i];

	for(int i=0;i<NB_COEFF64;i++)
	{
		

		t[i] = mpn_addmul_1(t+i,b,NB_COEFF64,a[i]);//addition with carry !!! see GMP doc p.55
		//t[] = mpn_add_1(tmp+i+SIZE, tmp+i+SIZE,,tmp);
		/*printf("tmp = ");
		for (j=0;j<SIZE<<1;j++) printf("%16.16lX ",tmp[(SIZE<<1)-1-j]);
		printf(" ;\n\n");*/


	}



	for(int i=0;i<NB_COEFF64;i++) out[i] = t[i];




}


inline void MontMulGMP(uint64_t out[NB_COEFF64], uint64_t a[NB_COEFF64], uint64_t b[NB_COEFF64], uint64_t upb[NB_COEFF64], uint64_t N[NB_COEFF64], uint64_t N_prime[NB_COEFF64]){
	
	uint64_t t[NB_COEFF64<<1], tn[NB_COEFF64<<1],q[NB_COEFF64],tmp;
	mpn_mul_n(t,a,b,NB_COEFF64);
	
	/*mulmodMGMP(q,t,N_prime);
	
	fmaGMP_truncated(out,q,N,t);*/
	
	mpn_mul_n(tn,t,N_prime,NB_COEFF64);
	
	mpn_tdiv_qr ( tn, q, 0, tn, NB_COEFF64<<1, upb64,  NB_COEFF64)
	mpn_mul_n(q,tn,N,NB_COEFF64);
	
	
	mpn_add_n(t,t,q,NB_COEFF64<<1);
	
	
	for(int i=0;i<NB_COEFF64;i++) out[i] = t[i+NB_COEFF64];
	

}





