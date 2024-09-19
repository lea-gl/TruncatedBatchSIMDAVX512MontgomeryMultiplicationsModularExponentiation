

__m512i zero = (__m512i){0x0UL};

__m512i mask52 = (__m512i){0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL};


__m512i un = (__m512i){1UL, 1UL,1UL,1UL,1UL, 1UL,1UL,1UL};


__m512i un512[NB_COEFF] = {
		(__m512i){1UL, 1UL,1UL,1UL,1UL, 1UL,1UL,1UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL},
		(__m512i){0x0UL}	
};



inline void force_inline
fexpand_8_512_64(__m512i * output, const unsigned long int in[8][NB_COEFF64])
{
	unsigned long int *output64 = (unsigned long int *) output;
	
	
	for(int j=0;j<NB_COEFF64;j++)
		for(int i=0;i<8;i++){
			int jj = j<<3;
			output64[jj+i] = in[i][j];
		}
}



inline void force_inline
fexpand_8_512_52(__m512i * output, const unsigned long int in[8][NB_COEFF64])
{
	unsigned long int *output64 = (unsigned long int *) output;
	
	
	for(int i=0;i<8;i++){
		//int ii=i<<3;
		output64[0+i] = in[i][0] & 0xfffffffffffff;// 52 bits
		
		//displayVect(in[i],"in[i]",NB_COEFF64);
		/*printf("%d, %d, %d, 0x%16.16lX\n",i,0,i,output64[i]);
		for(int j=1;j<NB_COEFF64;j++){
			int jj=j<<3;
			int decl = (12*j)&0x3f;
			int decr = (64-decl)&0x3f;
			output64[jj+i] = (in[i][j-1] >> decr) ^ (in[i][j] << decl) & 0xfffffffffffff;
			printf("%d, %d, %d, 0x%16.16lX\n",i,j,jj+i,output64[jj+i]);
		}*/
		
		for(int j=52;j<SIZE;j+=52){
			//int startbit = j;
			//int endbit =  j+51;
			int startword = j>>6;
			int endword = (j+51)>>6;
			//printf("startword = %d, endword = %d\n",startword, endword); 
			int jj=(j/52);
			int decl = (12*jj)&0x3f;
			int decr = (64-decl)&0x3f;
			//printf("decl = %d, decr = %d\n",decl,decr );
			if(decl) 
				output64[(jj<<3)+i] = (endword!=startword)?((in[i][startword] >> decr) ^ (in[i][endword] << decl)) & 0xfffffffffffff:((in[i][startword] >> decr) ^ (in[i][startword+1] << decl)) & 0xfffffffffffff;
			else output64[(jj<<3)+i] = (in[i][startword] >> decr)& 0xfffffffffffff;
			/*printf("%d, %d, %d, 0x%16.16lX ",i,j,(jj<<3)+i,output64[(jj<<3)+i]);
			printf(" 0x%16.16lX, 0x%16.16lX \n\n",in[i][endword],in[i][startword]);//*/
		
		}
		//getchar();
		
	}
}


void
fcontract_8_512_52(unsigned long int out[8][NB_COEFF64], __m512i * input)
{
	
	unsigned long int *input64 = (unsigned long int *) input;
	
		for(int i=0;i<8;i++){
			//int ii=i<<3;
			/*for(int j=0;j<NB_COEFF-1;j++){
				int jj=j<<3;
				int decr = (12*j)&0xffffff;
				int decl = (52-decr)&0xffffff;
				out[i][j] =  input64[i+jj]>>decr | input64[i+jj+8]<<decl;//& 0xfffffffffffff;// 52 bits
				//printf("%d, %d, %d, 0x%16.16lX\n",i,j,jj+i,out[i][j]);
			}
			int decr = (12*(NB_COEFF-1))&0xffffff;
			out[i][NB_COEFF-1] =  input64[(NB_COEFF-1)*8+i]>>decr;*/
			
			for(int j=0;j<NB_COEFF64;j++){out[i][j]=0x0UL;}
			
			for(int j=0;j<NB_COEFF;j++){
				int startbit = (j*52);
				int endbit =  ((j+1)*52)-1;
				int startword = startbit>>6;
				int endword = endbit>>6;
				//printf("i = %d, j = %d, startbit = %d, endbit = %d, startword = %d, endword = %d\n",i,j,startbit, endbit, startword, endword);
				if(startword==endword){
					int decl = startbit&0x3f;
					int jj = j<<3;
					out[i][startword] |=  input64[i+jj]<<decl;
					/*printf("decl = %d, input64[i+jj] = 0x%16.16lX, ",decl, input64[i+jj]);
					printf("out[%d][%d] = 0x%16.16lX\n",i,startword,out[i][startword]);//*/
				} else {
					int jj = j<<3;
					int decl = startbit&0x3f;
					int decr = (64-decl)&0x3f;
					out[i][startword] |=  input64[i+jj]<<decl;//|input64[i+jj-8]>>decr;
					out[i][endword] |=input64[i+jj]>>decr;
					/*printf("decl = %d, input64[i+jj] = 0x%16.16lX, ",decl, input64[i+jj]);
					printf("out[%d][%d] = 0x%16.16lX\n",i,startword,out[i][startword]);
					printf("out[%d][%d] = 0x%16.16lX\n",i,startword,out[i][endword]);//*/
				
				
				}
				//out[i][jj] =  input64[i+jj]>>decr | input64[i+jj+8]<<decl;//& 			
			}
	
	}
}

void
fcontract_8_512_52_res(unsigned long int out[8][NB_COEFF64*2], __m512i * input)
{
	
	unsigned long int *input64 = (unsigned long int *) input;
			
	__m512i * out512 = (__m512i*) out;
	
		for(int i=0;i<8;i++){
			/*//int ii=i<<3;
			int j=0,jjj;
			for(j=0;j<NB_COEFF*2-1;j++){
				int jj=j<<3;
				int decr = (12*j)&0x3f;
				int decl = (52-decr)&0x3f;
				jjj = ((j+1)*52)/64;
				out[i][jjj] =  input64[i+jj]>>decr | input64[i+jj+8]<<decl;//& 0xfffffffffffff;// 52 bits
				printf("%d, %d, %d,0x%16.16lX\n",i,j, jjj,out[i][jjj]);
			}
			int decr = (12*(NB_COEFF*2-1))&0x3f;
			jjj++;
			//int j = NB_COEFF*2-((NB_COEFF-1)*52)/64;
			out[i][jjj] =  input64[(NB_COEFF*2-1)*8+i]>>decr;
			printf("%d, %d, %d,0x%16.16lX\n",i,j, jjj,out[i][jjj]);
			jjj++;
			for(;jjj<NB_COEFF*2;jjj++){
				out[i][jjj] =0x0UL;
				printf("%d, %d, %d,0x%16.16lX\n",i,j, jjj,out[i][jjj]);
			}*/
			
			
			for(int j=0;j<NB_COEFF64*2;j++){out[i][j]=0x0UL;}
			
			for(int j=0;j<NB_COEFF*2;j++){
				int startbit = (j*52);
				int endbit =  ((j+1)*52)-1;
				int startword = startbit>>6;
				int endword = endbit>>6;
				//printf("i = %d, j = %d, startbit = %d, endbit = %d, startword = %d, endword = %d\n",i,j,startbit, endbit, startword, endword);
				if(startword==endword){
					int decl = startbit&0x3f;
					int jj = j<<3;
					out[i][startword] |=  input64[i+jj]<<decl;
					//printf("decl = %d, input64[i+jj] = 0x%16.16lX, ",decl, input64[i+jj]);
					//printf("out[%d][%d] = 0x%16.16lX\n",i,startword,out[i][startword]);
				} else {
					int jj = j<<3;
					int decl = startbit&0x3f;
					int decr = (64-decl)&0x3f;
					out[i][startword] |=  input64[i+jj]<<decl;//|input64[i+jj-8]>>decr;
					out[i][endword] |=input64[i+jj]>>decr;
					/*printf("decl = %d, input64[i+jj] = 0x%16.16lX, ",decl, input64[i+jj]);
					printf("out[%d][%d] = 0x%16.16lX\n",i,startword,out[i][startword]);
					printf("out[%d][%d] = 0x%16.16lX\n",i,startword,out[i][endword]);*/
				
				
				}
				//out[i][jj] =  input64[i+jj]>>decr | input64[i+jj+8]<<decl;//& 			
			}
	
	}
}

	


#include "sbMont512_4160.c"	

// batch conditional swap

void swap_8_512(__m512i b, __m512i in1[NB_COEFF], __m512i in2[NB_COEFF]){

		
	__m512i mask = _mm512_sub_epi64(zero,b);
	
	for(int i=0;i<NB_COEFF;i++){
		__m512i in = _mm512_xor_si512(in1[i],in2[i]);
		
		in = _mm512_and_si512(in,mask);
		
		in1[i] = _mm512_xor_si512(in1[i],in);
	
		in2[i] = _mm512_xor_si512(in2[i],in);
	
	}


}


/*************

Batch Modular Exponentiation


returns a**e mod n, using Montgomery multiplications and Montgomery ladder

Parameters :

n_prime : for Block Montgomery


**************/

void
modExp_8_512(unsigned long int out[8][NB_COEFF64], unsigned long int a[8][NB_COEFF64], unsigned long int e[8][NB_COEFF64], __m512i n[NB_COEFF], __m512i n_prime[1], __m512i r2[NB_COEFF])
{

	__m512i e512[NB_COEFF], a0_512[NB_COEFF], a1_512[NB_COEFF], out512[NB_COEFF];
	


	fexpand_8_512_52(a1_512, a);
	
	fexpand_8_512_64(e512, e);
	
	
	
	// conversion to the Montgomery domain :
	
	mont_mul512_8_4160(a0_512, un512, r2, n, n_prime);// a0 = a x R
	
	mont_mul512_8_4160(a1_512, a1_512, r2, n, n_prime);// a0 = a x R
	//mont_square512_8_4160(a1_512, a1_512, n, n_prime2);// a1 = a^2 x R
	
	for(int i = 4095; i>=0;i--)
	{
		//scan bits
		int w = i>>6;
		int b = i&0x3f;
		__m512i b512 = _mm512_and_si512(_mm512_srli_epi64(e512[w],b),un);
		
		/*displayVect512(&b512, "b512 ");
		
		
		displayVect512_NB_COEFF(a0_512, "a0_512 ");
		displayVect512_NB_COEFF(a1_512, "a1_512 ");//*/
		
		
		swap_8_512(b512,a0_512,a1_512);
		
		
		/*displayVect512_NB_COEFF(a0_512, "après swap\na0_512 ");
		displayVect512_NB_COEFF(a1_512, "a1_512 ");*/

		
		mont_mul512_8_4160(a1_512, a0_512, a1_512, n, n_prime);// a1 = a1 x a0 x R

		//block_mont_mul512_8_1040(a0_512, a0_512, a0_512, n, n_prime);// a0 = a0^2 x R
		mont_square512_8_4160(a0_512, a0_512, n, n_prime);// a1 = a^2 x R
		
			
		/*displayVect512_NB_COEFF(a0_512, "a0_512 ");
		displayVect512_NB_COEFF(a1_512, "a1_512 ");*/

		swap_8_512(b512,a0_512,a1_512);
		
		/*displayVect512_NB_COEFF(a0_512, "après swap\na0_512 ");
		displayVect512_NB_COEFF(a1_512, "a1_512 ");*/
	
		//getchar();//*/
	
	}

	// back to standard domain
	
	mont_mul512_8_4160(a1_512, a0_512, un512, n, n_prime);
	
	
	fcontract_8_512_52(out, a1_512);


}






