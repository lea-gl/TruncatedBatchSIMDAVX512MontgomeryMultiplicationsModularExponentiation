

__m512i zero = (__m512i){0x0UL};

__m512i mask52 = (__m512i){0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL,0xfffffffffffffUL};

__m512i mask51 = (__m512i){0x7ffffffffffffUL,0x7ffffffffffffUL,0x7ffffffffffffUL,0x7ffffffffffffUL,0x7ffffffffffffUL,0x7ffffffffffffUL,0x7ffffffffffffUL,0x7ffffffffffffUL};

__m512i un = (__m512i){1UL,1UL,1UL,1UL,1UL,1UL,1UL,1UL};






static inline void force_inline
fexpand_8_512_52(__m512i * output, const unsigned long int in[8][NB_COEFF64_SLICE])
{
	unsigned long int *output64 = (unsigned long int *) output;
	
	
	for(int i=0;i<8;i++){
		output64[0+i] = in[i][0] & 0xfffffffffffff;// 52 bits
		
		for(int j=52;j<SLICE;j+=52){
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




inline void force_inline
fexpand_8_512_2078K(__m512i * output, const unsigned long int in[8][NB_COEFF64])
{
	uint64_t tmp[8][NB_COEFF64_SLICE];

	for(int i=0;i<NB_SLICES;i++){
	
		int startbit = i*SLICE;
		int endbit =  (i+1)*SLICE-1;
		int startword = startbit>>6;
		int endword = endbit>>6;
		int diff = endword-startword; 
		if (endword>NB_COEFF64) endword= NB_COEFF64-1;
		int decr = (startbit)&0x3f;
		int decl = (64-decr)&0x3f;

		for(int k=0;k<8;k++){
			for(int j=0;j<diff;j++){
				if(decl) {
					tmp[k][j] = ((in[k][j+startword] >> decr) ^ (in[k][j+startword+1] << decl))  ;
				}	
				else tmp[k][j] = in[k][j+startword];
			}
			if(decl) 
				tmp[k][diff] = (((in[k][endword] >> decr) ^ (in[k][endword+1] << decl)))&0x7fffUL  ;//mask : 1039-1024 = 15 bits
			else tmp[k][diff] = in[k][endword]&0x7fffUL;
			
			
		}
		fexpand_8_512_52( output + (NB_COEFF_SLICE*i), tmp);
	}


}























void
fcontract_8_512_52_res(unsigned long int out[8][NB_COEFF64*2], __m512i * input)
{
	
	unsigned long int *input64 = (unsigned long int *) input;
			
	
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


static inline void
fcontract_8_512_52(unsigned long int out[8][NB_COEFF64_SLICE], __m512i * input)
{
	
	unsigned long int *input64 = (unsigned long int *) input;
	
		for(int i=0;i<8;i++){
			
			for(int j=0;j<NB_COEFF64_SLICE;j++){out[i][j]=0x0UL;}
			
			for(int j=0;j<NB_COEFF_SLICE;j++){
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
fcontract_8_512_2078K(unsigned long int out[8][NB_COEFF64], __m512i * input)
{
	

	
	unsigned long int *input64 = (unsigned long int *) input;
			
	
	for(int i=0;i<8;i++)
		for(int j=0;j<NB_COEFF64;j++){out[i][j]=0x0UL;}


	uint64_t tmp[8][NB_COEFF64_SLICE];

	for(int i=0;i<NB_SLICES;i++){
		fcontract_8_512_52(tmp, input + (NB_COEFF_SLICE*i));

		int startbit = i*SLICE;
		int endbit =  (i+1)*SLICE-1;
		int startword = startbit>>6;
		int endword = endbit>>6;
		int diff = endword-startword; 
		if (endword>NB_COEFF64) endword= NB_COEFF64-1;
		int decl = (startbit)&0x3f;
		int decr = (64-decl)&0x3f;

		for(int k=0;k<8;k++){
			if(decl) {
				out[k][startword] |= tmp[k][0] << decl  ;
			}
			else out[k][startword] |= tmp[k][0];
			for(int j=1;j<NB_COEFF64_SLICE;j++){
				if(decl) {
					out[k][j+startword] |= ((tmp[k][j] << decl) | (tmp[k][j-1]>> decr ))  ;
				}	
				else out[k][j+startword] |= tmp[k][j];
			}
		}
	}


}

void
fcontract_8_512_2078K_res(unsigned long int out[8][NB_COEFF64*2], __m512i * input)
{


	
	unsigned long int *input64 = (unsigned long int *) input;
			
	
	for(int i=0;i<8;i++)
		for(int j=0;j<NB_COEFF64*2;j++){out[i][j]=0x0UL;}


	uint64_t tmp[8][NB_COEFF64_SLICE];

	for(int i=0;i<NB_SLICES*2;i++){
		fcontract_8_512_52(tmp, input + (NB_COEFF_SLICE*i));

		int startbit = i*SLICE;
		int endbit =  (i+1)*SLICE-1;
		int startword = startbit>>6;
		int endword = endbit>>6;
		int diff = endword-startword; 
		if (endword>NB_COEFF64) endword= NB_COEFF64-1;
		int decl = (startbit)&0x3f;
		int decr = (64-decl)&0x3f;

		for(int k=0;k<8;k++){
			if(decl) {
				out[k][startword] |= tmp[k][0] << decl  ;
			}
			else out[k][startword] |= tmp[k][0];
			for(int j=1;j<NB_COEFF64_SLICE;j++){
				if(decl) {
					out[k][j+startword] |= ((tmp[k][j] << decl) | (tmp[k][j-1]>> decr ))  ;
				}	
				else out[k][j+startword] |= tmp[k][j];
			}
		}
	}

}








//////////////////////////////////


//		KARATSUBA 2078


//////////////////////////////////

#include "sbMont512_2078.c"















