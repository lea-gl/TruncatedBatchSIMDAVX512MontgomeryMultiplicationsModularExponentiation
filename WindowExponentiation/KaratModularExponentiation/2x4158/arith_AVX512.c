

__m512i zero = (__m512i){0x0UL};

__m512i mask52 = (__m512i){0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL};

//__m512i mask36 = (__m512i){0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL,0xfffffffffUL};

__m512i mask51 = (__m512i){0x7ffffffffffffUL,0x7ffffffffffffUL,0x7ffffffffffffUL,0x7ffffffffffffUL,0x7ffffffffffffUL,0x7ffffffffffffUL,0x7ffffffffffffUL,0x7ffffffffffffUL};

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



static inline void force_inline
fexpand_8_512_52(__m512i * output, const unsigned long int in[8][NB_COEFF64_SLICE])
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
		
		//for(int j=52;j<SIZE;j+=52){
		for(int j=52;j<SLICE;j+=52){
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




inline void force_inline
fexpand_8_512_4158K(__m512i * output, const unsigned long int in[8][NB_COEFF64])
{
	uint64_t tmp[8][NB_COEFF64_SLICE];

	for(int i=0;i<NB_SLICES;i++){
	
		int startbit = i*SLICE;
		int endbit =  (i+1)*SLICE-1;
		int startword = startbit>>6;
		int endword = endbit>>6;
			//printf("startword = %d, endword = %d\n",startword, endword);
		int diff = endword-startword; 
		if (endword>NB_COEFF64) endword= NB_COEFF64-1;
		int decr = (startbit)&0x3f;
		int decl = (64-decr)&0x3f;
			//printf("decl = %d, decr = %d\n",decl,decr );

		for(int k=0;k<8;k++){
			//printf(" 0x%16.16lX, 0x%16.16lX \n\n",in[k][endword],in[k][startword]);//*/
			for(int j=0;j<diff;j++){
				if(decl) {
					tmp[k][j] = ((in[k][j+startword] >> decr) ^ (in[k][j+startword+1] << decl))  ;
					//printf("in[k][%d] = 0x%16.16lX, in[k][%d] = 0x%16.16lX\n",j,in[k][j+startword] >> decr,j+1,in[k][j+startword+1]<< decl);
				}	
				else tmp[k][j] = in[k][j+startword];
				//printf("tmp[k][%d] = 0x%16.16lX\n",j,tmp[k][j+startword]);
			}
			if(decl) 
				tmp[k][diff] = (((in[k][endword] >> decr) ^ (in[k][endword+1] << decl)))&0x7fffffffUL  ;//mask : 2079-2048 = 15 bits
			else tmp[k][diff] = in[k][endword]&0x7fffffffUL;
			
			//displayVect(tmp[k],"tmp",NB_COEFF64_SLICE);
			//getchar();
			
			
		}
		fexpand_8_512_52( output + (NB_COEFF_SLICE*i), tmp);
	}


}




static inline void
fcontract_8_512_52(unsigned long int out[8][NB_COEFF64_SLICE], __m512i * input)
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
			
			for(int j=0;j<NB_COEFF64_SLICE;j++){out[i][j]=0x0UL;}
			
			for(int j=0;j<NB_COEFF_SLICE;j++){
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
fcontract_8_512_4158K(unsigned long int out[8][NB_COEFF64], __m512i * input)
{
	

	
	unsigned long int *input64 = (unsigned long int *) input;
			
	//__m512i * out512 = (__m512i*) out;
	
	for(int i=0;i<8;i++)
		for(int j=0;j<NB_COEFF64;j++){out[i][j]=0x0UL;}


	uint64_t tmp[8][NB_COEFF64_SLICE];

	for(int i=0;i<NB_SLICES;i++){
		fcontract_8_512_52(tmp, input + (NB_COEFF_SLICE*i));
		/*for(int k=0;k<8;k++)
			displayVect(tmp[k],"tmp[i]     ",NB_COEFF64_SLICE);*/

		int startbit = i*SLICE;
		int endbit =  (i+1)*SLICE-1;
		int startword = startbit>>6;
		int endword = endbit>>6;
			//printf("startword = %d, endword = %d\n",startword, endword);
		int diff = endword-startword; 
		if (endword>NB_COEFF64) endword= NB_COEFF64-1;
		int decl = (startbit)&0x3f;
		int decr = (64-decl)&0x3f;
			//printf("decl = %d, decr = %d\n",decl,decr );

		for(int k=0;k<8;k++){
			//printf(" 0x%16.16lX, 0x%16.16lX \n\n",tmp[k][endword],tmp[k][startword]);//*/
			if(decl) {
				out[k][startword] |= tmp[k][0] << decl  ;
				//printf("tmp[k][0] = 0x%16.16lX\n",tmp[k][0] << decl);
			}
			else out[k][startword] |= tmp[k][0];
			//printf("tmp[k][0] = 0x%16.16lX\n",tmp[k][0]);
			for(int j=1;j<NB_COEFF64_SLICE;j++){
				if(decl) {
					out[k][j+startword] |= ((tmp[k][j] << decl) | (tmp[k][j-1]>> decr ))  ;
					//printf("tmp[k][%d] = 0x%16.16lX, tmp[k][%d] = 0x%16.16lX\n",j,tmp[k][j] << decl,j+1,tmp[k][j-1]>> decr);
				}	
				else out[k][j+startword] |= tmp[k][j];
				//printf("tmp[k][%d] = 0x%16.16lX\n",j,tmp[k][j]);
			}
			/*if(decl) 
				out[k][diff+startword] |= ((tmp[k][NB_COEFF64_SLICE] << decl) )&0xfUL  ;
			else out[k][diff+startword] |= tmp[k][NB_COEFF64_SLICE]&0xfUL;//*/
			
			//displayVect(out[k]+startword,"out",NB_COEFF64_SLICE);
			//getchar();
			
			
		}
	}
}










	


#include "sbMont512_4158.c"	


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
modExp_8_512(unsigned long int out[8][NB_COEFF64], unsigned long int a[8][NB_COEFF64], unsigned long int e[8][NB_COEFF64], __m512i n[NB_COEFF], __m512i n_prime[NB_COEFF], __m512i r2[NB_COEFF])
{

	__m512i e512[NB_COEFF], a0_512[NB_COEFF], a1_512[NB_COEFF], out512[NB_COEFF];
	


	fexpand_8_512_4158K(a1_512, a);
	
	fexpand_8_512_64(e512, e);
	
	
	
	// conversion to the Montgomery domain :
	
	mont_mul512_8_4158K(a0_512, un512, r2, n, n_prime);// a0 = a x R
	
	mont_mul512_8_4158K(a1_512, a1_512, r2, n, n_prime);// a0 = a x R
	//mont_square512_8_4158K(a1_512, a1_512, n, n_prime2);// a1 = a^2 x R
	
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

		
		mont_mul512_8_4158K(a1_512, a0_512, a1_512, n, n_prime);// a1 = a1 x a0 x R

		mont_square512_8_4158K(a0_512, a0_512, n, n_prime);// a1 = a^2 x R
		
			
		/*displayVect512_NB_COEFF(a0_512, "a0_512 ");
		displayVect512_NB_COEFF(a1_512, "a1_512 ");*/

		swap_8_512(b512,a0_512,a1_512);
		
		/*displayVect512_NB_COEFF(a0_512, "après swap\na0_512 ");
		displayVect512_NB_COEFF(a1_512, "a1_512 ");*/
	
		//getchar();//*/
	
	}

	// back to standard domain
	
	mont_mul512_8_4158K(a1_512, a0_512, un512, n, n_prime);
	
	
	fcontract_8_512_4158K(out, a1_512);


}























