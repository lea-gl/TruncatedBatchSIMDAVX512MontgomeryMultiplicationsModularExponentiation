

__m512i zero = (__m512i){0x0UL};

__m512i mask52 = (__m512i){0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL};



inline void force_inline
fexpand_8_512_52(__m512i * output, const unsigned long int in[8][NB_COEFF64])
{
	unsigned long int *output64 = (unsigned long int *) output;
	
	
	for(int i=0;i<8;i++){
		output64[0+i] = in[i][0] & 0xfffffffffffff;// 52 bits
		
		
		for(int j=52;j<SIZE;j+=52){
			int startword = j>>6;
			int endword = (j+51)>>6;
			int jj=(j/52);
			int decl = (12*jj)&0x3f;
			int decr = (64-decl)&0x3f;
			if(decl) 
				output64[(jj<<3)+i] = (endword!=startword)?((in[i][startword] >> decr) ^ (in[i][endword] << decl)) & 0xfffffffffffff:((in[i][startword] >> decr) ^ (in[i][startword+1] << decl)) & 0xfffffffffffff;
			else output64[(jj<<3)+i] = (in[i][startword] >> decr)& 0xfffffffffffff;
		
		}
		
	}
}


void
fcontract_8_512_52(unsigned long int out[8][NB_COEFF64], __m512i * input)
{
	
	unsigned long int *input64 = (unsigned long int *) input;
	
		for(int i=0;i<8;i++){
			
			for(int j=0;j<NB_COEFF64;j++){out[i][j]=0x0UL;}
			
			for(int j=0;j<NB_COEFF;j++){
				int startbit = (j*52);
				int endbit =  ((j+1)*52)-1;
				int startword = startbit>>6;
				int endword = endbit>>6;
				if(startword==endword){
					int decl = startbit&0x3f;
					int jj = j<<3;
					out[i][startword] |=  input64[i+jj]<<decl;
				} else {
					int jj = j<<3;
					int decl = startbit&0x3f;
					int decr = (64-decl)&0x3f;
					out[i][startword] |=  input64[i+jj]<<decl;//|input64[i+jj-8]>>decr;
					out[i][endword] |=input64[i+jj]>>decr;
				
				
				}
			}
	
	}
}

void
fcontract_8_512_52_res(unsigned long int out[8][NB_COEFF64*2], __m512i * input)
{
	
	unsigned long int *input64 = (unsigned long int *) input;
			
	__m512i * out512 = (__m512i*) out;
	
		for(int i=0;i<8;i++){
			
			
			for(int j=0;j<NB_COEFF64*2;j++){out[i][j]=0x0UL;}
			
			for(int j=0;j<NB_COEFF*2;j++){
				int startbit = (j*52);
				int endbit =  ((j+1)*52)-1;
				int startword = startbit>>6;
				int endword = endbit>>6;
				if(startword==endword){
					int decl = startbit&0x3f;
					int jj = j<<3;
					out[i][startword] |=  input64[i+jj]<<decl;
				} else {
					int jj = j<<3;
					int decl = startbit&0x3f;
					int decr = (64-decl)&0x3f;
					out[i][startword] |=  input64[i+jj]<<decl;//|input64[i+jj-8]>>decr;
					out[i][endword] |=input64[i+jj]>>decr;
				}
			}
	
	}
}

	


#include "sbBlockMont512_2080.c"	

