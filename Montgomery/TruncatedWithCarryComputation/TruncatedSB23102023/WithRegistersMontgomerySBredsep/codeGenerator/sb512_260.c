/* Schoolbook multiplication modulo M*/

static inline void force_inline mul512_8_260_modM(__m512i out[10], __m512i a512[5], __m512i b512[5])
{
	__m512i out0, out1;
	__m512i out2, out3;
	__m512i out4, out5;
	__m512i out6, out7;
	__m512i out8, out9;
	__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512);
	__m512i a5121 = _mm512_load_epi64(a512+1), b5121 = _mm512_load_epi64(b512+1);
	__m512i a5122 = _mm512_load_epi64(a512+2), b5122 = _mm512_load_epi64(b512+2);
	__m512i a5123 = _mm512_load_epi64(a512+3), b5123 = _mm512_load_epi64(b512+3);
	__m512i a5124 = _mm512_load_epi64(a512+4), b5124 = _mm512_load_epi64(b512+4);
	out0 = _mm512_madd52lo_epu64(zero,a5120,b5120);
	out1 = _mm512_madd52hi_epu64(zero,a5120,b5120);
	out1 = _mm512_madd52lo_epu64(out1,a5120,b5121);
	out2 = _mm512_madd52hi_epu64(zero,a5120,b5121);
	out2 = _mm512_madd52lo_epu64(out2,a5120,b5122);
	out3 = _mm512_madd52hi_epu64(zero,a5120,b5122);
	out3 = _mm512_madd52lo_epu64(out3,a5120,b5123);
	out4 = _mm512_madd52hi_epu64(zero,a5120,b5123);
	out4 = _mm512_madd52lo_epu64(out4,a5120,b5124);

	out1 = _mm512_madd52lo_epu64(out1,a5121,b5120);
	out2 = _mm512_madd52hi_epu64(out2,a5121,b5120);
	out2 = _mm512_madd52lo_epu64(out2,a5121,b5121);
	out3 = _mm512_madd52hi_epu64(out3,a5121,b5121);
	out3 = _mm512_madd52lo_epu64(out3,a5121,b5122);
	out4 = _mm512_madd52hi_epu64(out4,a5121,b5122);
	out4 = _mm512_madd52lo_epu64(out4,a5121,b5123);

	out2 = _mm512_madd52lo_epu64(out2,a5122,b5120);
	out3 = _mm512_madd52hi_epu64(out3,a5122,b5120);
	out3 = _mm512_madd52lo_epu64(out3,a5122,b5121);
	out4 = _mm512_madd52hi_epu64(out4,a5122,b5121);
	out4 = _mm512_madd52lo_epu64(out4,a5122,b5122);

	out3 = _mm512_madd52lo_epu64(out3,a5123,b5120);
	out4 = _mm512_madd52hi_epu64(out4,a5123,b5120);
	out4 = _mm512_madd52lo_epu64(out4,a5123,b5121);

	out4 = _mm512_madd52lo_epu64(out4,a5124,b5120);


// Carry management

	__m512i carry  = _mm512_srli_epi64(out1,52);
	out2 = _mm512_add_epi64(out2,carry);
	out1 = _mm512_and_si512(out1,mask52);
	carry  = _mm512_srli_epi64(out2,52);
	out3 = _mm512_add_epi64(out3,carry);
	out2 = _mm512_and_si512(out2,mask52);
	carry  = _mm512_srli_epi64(out3,52);
	out4 = _mm512_add_epi64(out4,carry);
	out3 = _mm512_and_si512(out3,mask52);
	out4 = _mm512_and_si512(out4,mask52);

	_mm512_store_epi64(out+0,out0);
	_mm512_store_epi64(out+1,out1);
	_mm512_store_epi64(out+2,out2);
	_mm512_store_epi64(out+3,out3);
	_mm512_store_epi64(out+4,out4);

}

/* Schoolbook multiplication*/

static inline void force_inline mul512_8_260(__m512i out[10], __m512i a512[5], __m512i b512[5])
{
	__m512i out0, out1;
	__m512i out2, out3;
	__m512i out4, out5;
	__m512i out6, out7;
	__m512i out8, out9;
	__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512);
	__m512i a5121 = _mm512_load_epi64(a512+1), b5121 = _mm512_load_epi64(b512+1);
	__m512i a5122 = _mm512_load_epi64(a512+2), b5122 = _mm512_load_epi64(b512+2);
	__m512i a5123 = _mm512_load_epi64(a512+3), b5123 = _mm512_load_epi64(b512+3);
	__m512i a5124 = _mm512_load_epi64(a512+4), b5124 = _mm512_load_epi64(b512+4);
	out0 = _mm512_madd52lo_epu64(zero,a5120,b5120);
	out1 = _mm512_madd52hi_epu64(zero,a5120,b5120);
	out1 = _mm512_madd52lo_epu64(out1,a5120,b5121);
	out2 = _mm512_madd52hi_epu64(zero,a5120,b5121);
	out2 = _mm512_madd52lo_epu64(out2,a5120,b5122);
	out3 = _mm512_madd52hi_epu64(zero,a5120,b5122);
	out3 = _mm512_madd52lo_epu64(out3,a5120,b5123);
	out4 = _mm512_madd52hi_epu64(zero,a5120,b5123);
	out4 = _mm512_madd52lo_epu64(out4,a5120,b5124);
	out5 = _mm512_madd52hi_epu64(zero,a5120,b5124);

	out1 = _mm512_madd52lo_epu64(out1,a5121,b5120);
	out2 = _mm512_madd52hi_epu64(out2,a5121,b5120);
	out2 = _mm512_madd52lo_epu64(out2,a5121,b5121);
	out3 = _mm512_madd52hi_epu64(out3,a5121,b5121);
	out3 = _mm512_madd52lo_epu64(out3,a5121,b5122);
	out4 = _mm512_madd52hi_epu64(out4,a5121,b5122);
	out4 = _mm512_madd52lo_epu64(out4,a5121,b5123);
	out5 = _mm512_madd52hi_epu64(out5,a5121,b5123);
	out5 = _mm512_madd52lo_epu64(out5,a5121,b5124);
	out6 = _mm512_madd52hi_epu64(zero,a5121,b5124);

	out2 = _mm512_madd52lo_epu64(out2,a5122,b5120);
	out3 = _mm512_madd52hi_epu64(out3,a5122,b5120);
	out3 = _mm512_madd52lo_epu64(out3,a5122,b5121);
	out4 = _mm512_madd52hi_epu64(out4,a5122,b5121);
	out4 = _mm512_madd52lo_epu64(out4,a5122,b5122);
	out5 = _mm512_madd52hi_epu64(out5,a5122,b5122);
	out5 = _mm512_madd52lo_epu64(out5,a5122,b5123);
	out6 = _mm512_madd52hi_epu64(out6,a5122,b5123);
	out6 = _mm512_madd52lo_epu64(out6,a5122,b5124);
	out7 = _mm512_madd52hi_epu64(zero,a5122,b5124);

	out3 = _mm512_madd52lo_epu64(out3,a5123,b5120);
	out4 = _mm512_madd52hi_epu64(out4,a5123,b5120);
	out4 = _mm512_madd52lo_epu64(out4,a5123,b5121);
	out5 = _mm512_madd52hi_epu64(out5,a5123,b5121);
	out5 = _mm512_madd52lo_epu64(out5,a5123,b5122);
	out6 = _mm512_madd52hi_epu64(out6,a5123,b5122);
	out6 = _mm512_madd52lo_epu64(out6,a5123,b5123);
	out7 = _mm512_madd52hi_epu64(out7,a5123,b5123);
	out7 = _mm512_madd52lo_epu64(out7,a5123,b5124);
	out8 = _mm512_madd52hi_epu64(zero,a5123,b5124);

	out4 = _mm512_madd52lo_epu64(out4,a5124,b5120);
	out5 = _mm512_madd52hi_epu64(out5,a5124,b5120);
	out5 = _mm512_madd52lo_epu64(out5,a5124,b5121);
	out6 = _mm512_madd52hi_epu64(out6,a5124,b5121);
	out6 = _mm512_madd52lo_epu64(out6,a5124,b5122);
	out7 = _mm512_madd52hi_epu64(out7,a5124,b5122);
	out7 = _mm512_madd52lo_epu64(out7,a5124,b5123);
	out8 = _mm512_madd52hi_epu64(out8,a5124,b5123);
	out8 = _mm512_madd52lo_epu64(out8,a5124,b5124);
	out9 = _mm512_madd52hi_epu64(zero,a5124,b5124);


// Carry management

	__m512i carry  = _mm512_srli_epi64(out1,52);
	out2 = _mm512_add_epi64(out2,carry);
	out1 = _mm512_and_si512(out1,mask52);
	carry  = _mm512_srli_epi64(out2,52);
	out3 = _mm512_add_epi64(out3,carry);
	out2 = _mm512_and_si512(out2,mask52);
	carry  = _mm512_srli_epi64(out3,52);
	out4 = _mm512_add_epi64(out4,carry);
	out3 = _mm512_and_si512(out3,mask52);
	carry  = _mm512_srli_epi64(out4,52);
	out5 = _mm512_add_epi64(out5,carry);
	out4 = _mm512_and_si512(out4,mask52);
	carry  = _mm512_srli_epi64(out5,52);
	out6 = _mm512_add_epi64(out6,carry);
	out5 = _mm512_and_si512(out5,mask52);
	carry  = _mm512_srli_epi64(out6,52);
	out7 = _mm512_add_epi64(out7,carry);
	out6 = _mm512_and_si512(out6,mask52);
	carry  = _mm512_srli_epi64(out7,52);
	out8 = _mm512_add_epi64(out8,carry);
	out7 = _mm512_and_si512(out7,mask52);
	carry  = _mm512_srli_epi64(out8,52);
	out9 = _mm512_add_epi64(out9,carry);
	out8 = _mm512_and_si512(out8,mask52);
	_mm512_store_epi64(out+0,out0);
	_mm512_store_epi64(out+1,out1);
	_mm512_store_epi64(out+2,out2);
	_mm512_store_epi64(out+3,out3);
	_mm512_store_epi64(out+4,out4);
	_mm512_store_epi64(out+5,out5);
	_mm512_store_epi64(out+6,out6);
	_mm512_store_epi64(out+7,out7);
	_mm512_store_epi64(out+8,out8);
	_mm512_store_epi64(out+9,out9);

}

/* Schoolbook multiplyer-adder : out = c + ab */

static inline void force_inline fma512_8_260(__m512i out[10], __m512i a512[5], __m512i b512[5], __m512i c512[10])
{
	__m512i out0 = _mm512_load_epi64(c512), out1 = _mm512_load_epi64(c512+1);
	__m512i out2 = _mm512_load_epi64(c512+2), out3 = _mm512_load_epi64(c512+3);
	__m512i out4 = _mm512_load_epi64(c512+4), out5 = _mm512_load_epi64(c512+5);
	__m512i out6 = _mm512_load_epi64(c512+6), out7 = _mm512_load_epi64(c512+7);
	__m512i out8 = _mm512_load_epi64(c512+8), out9 = _mm512_load_epi64(c512+9);
	__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512);
	__m512i a5121 = _mm512_load_epi64(a512+1), b5121 = _mm512_load_epi64(b512+1);
	__m512i a5122 = _mm512_load_epi64(a512+2), b5122 = _mm512_load_epi64(b512+2);
	__m512i a5123 = _mm512_load_epi64(a512+3), b5123 = _mm512_load_epi64(b512+3);
	__m512i a5124 = _mm512_load_epi64(a512+4), b5124 = _mm512_load_epi64(b512+4);
	out0 = _mm512_madd52lo_epu64(out0,a5120,b5120);
	out1 = _mm512_madd52hi_epu64(out1,a5120,b5120);
	out1 = _mm512_madd52lo_epu64(out1,a5120,b5121);
	out2 = _mm512_madd52hi_epu64(out2,a5120,b5121);
	out2 = _mm512_madd52lo_epu64(out2,a5120,b5122);
	out3 = _mm512_madd52hi_epu64(out3,a5120,b5122);
	out3 = _mm512_madd52lo_epu64(out3,a5120,b5123);
	out4 = _mm512_madd52hi_epu64(out4,a5120,b5123);
	out4 = _mm512_madd52lo_epu64(out4,a5120,b5124);
	out5 = _mm512_madd52hi_epu64(out5,a5120,b5124);

	out1 = _mm512_madd52lo_epu64(out1,a5121,b5120);
	out2 = _mm512_madd52hi_epu64(out2,a5121,b5120);
	out2 = _mm512_madd52lo_epu64(out2,a5121,b5121);
	out3 = _mm512_madd52hi_epu64(out3,a5121,b5121);
	out3 = _mm512_madd52lo_epu64(out3,a5121,b5122);
	out4 = _mm512_madd52hi_epu64(out4,a5121,b5122);
	out4 = _mm512_madd52lo_epu64(out4,a5121,b5123);
	out5 = _mm512_madd52hi_epu64(out5,a5121,b5123);
	out5 = _mm512_madd52lo_epu64(out5,a5121,b5124);
	out6 = _mm512_madd52hi_epu64(out6,a5121,b5124);

	out2 = _mm512_madd52lo_epu64(out2,a5122,b5120);
	out3 = _mm512_madd52hi_epu64(out3,a5122,b5120);
	out3 = _mm512_madd52lo_epu64(out3,a5122,b5121);
	out4 = _mm512_madd52hi_epu64(out4,a5122,b5121);
	out4 = _mm512_madd52lo_epu64(out4,a5122,b5122);
	out5 = _mm512_madd52hi_epu64(out5,a5122,b5122);
	out5 = _mm512_madd52lo_epu64(out5,a5122,b5123);
	out6 = _mm512_madd52hi_epu64(out6,a5122,b5123);
	out6 = _mm512_madd52lo_epu64(out6,a5122,b5124);
	out7 = _mm512_madd52hi_epu64(out7,a5122,b5124);

	out3 = _mm512_madd52lo_epu64(out3,a5123,b5120);
	out4 = _mm512_madd52hi_epu64(out4,a5123,b5120);
	out4 = _mm512_madd52lo_epu64(out4,a5123,b5121);
	out5 = _mm512_madd52hi_epu64(out5,a5123,b5121);
	out5 = _mm512_madd52lo_epu64(out5,a5123,b5122);
	out6 = _mm512_madd52hi_epu64(out6,a5123,b5122);
	out6 = _mm512_madd52lo_epu64(out6,a5123,b5123);
	out7 = _mm512_madd52hi_epu64(out7,a5123,b5123);
	out7 = _mm512_madd52lo_epu64(out7,a5123,b5124);
	out8 = _mm512_madd52hi_epu64(out8,a5123,b5124);

	out4 = _mm512_madd52lo_epu64(out4,a5124,b5120);
	out5 = _mm512_madd52hi_epu64(out5,a5124,b5120);
	out5 = _mm512_madd52lo_epu64(out5,a5124,b5121);
	out6 = _mm512_madd52hi_epu64(out6,a5124,b5121);
	out6 = _mm512_madd52lo_epu64(out6,a5124,b5122);
	out7 = _mm512_madd52hi_epu64(out7,a5124,b5122);
	out7 = _mm512_madd52lo_epu64(out7,a5124,b5123);
	out8 = _mm512_madd52hi_epu64(out8,a5124,b5123);
	out8 = _mm512_madd52lo_epu64(out8,a5124,b5124);
	out9 = _mm512_madd52hi_epu64(out9,a5124,b5124);


// Carry management

	__m512i carry  = _mm512_srli_epi64(out0,52);
	out1 = _mm512_add_epi64(out1,carry);
	out0 = _mm512_and_si512(out0,mask52);
	carry  = _mm512_srli_epi64(out1,52);
	out2 = _mm512_add_epi64(out2,carry);
	out1 = _mm512_and_si512(out1,mask52);
	carry  = _mm512_srli_epi64(out2,52);
	out3 = _mm512_add_epi64(out3,carry);
	out2 = _mm512_and_si512(out2,mask52);
	carry  = _mm512_srli_epi64(out3,52);
	out4 = _mm512_add_epi64(out4,carry);
	out3 = _mm512_and_si512(out3,mask52);
	carry  = _mm512_srli_epi64(out4,52);
	out5 = _mm512_add_epi64(out5,carry);
	out4 = _mm512_and_si512(out4,mask52);
	carry  = _mm512_srli_epi64(out5,52);
	out6 = _mm512_add_epi64(out6,carry);
	out5 = _mm512_and_si512(out5,mask52);
	carry  = _mm512_srli_epi64(out6,52);
	out7 = _mm512_add_epi64(out7,carry);
	out6 = _mm512_and_si512(out6,mask52);
	carry  = _mm512_srli_epi64(out7,52);
	out8 = _mm512_add_epi64(out8,carry);
	out7 = _mm512_and_si512(out7,mask52);
	carry  = _mm512_srli_epi64(out8,52);
	out9 = _mm512_add_epi64(out9,carry);
	out8 = _mm512_and_si512(out8,mask52);
	_mm512_store_epi64(out+0,out0);
	_mm512_store_epi64(out+1,out1);
	_mm512_store_epi64(out+2,out2);
	_mm512_store_epi64(out+3,out3);
	_mm512_store_epi64(out+4,out4);
	_mm512_store_epi64(out+5,out5);
	_mm512_store_epi64(out+6,out6);
	_mm512_store_epi64(out+7,out7);
	_mm512_store_epi64(out+8,out8);
	_mm512_store_epi64(out+9,out9);

}

/* Schoolbook squaring */

static inline void force_inline square512_8_260(__m512i out[10], __m512i a512[5])
{
	__m512i out0, out1;
	__m512i out2, out3;
	__m512i out4, out5;
	__m512i out6, out7;
	__m512i out8, out9;
	__m512i a5120 = _mm512_load_epi64(a512);
	__m512i a5121 = _mm512_load_epi64(a512+1);
	__m512i a5122 = _mm512_load_epi64(a512+2);
	__m512i a5123 = _mm512_load_epi64(a512+3);
	__m512i a5124 = _mm512_load_epi64(a512+4);
	out0 = _mm512_madd52lo_epu64(zero,a5120,a5120);

	out1 = _mm512_madd52lo_epu64(zero,a5120,a5121);
	out1 = _mm512_slli_epi64(out1,1);
	out1 = _mm512_madd52hi_epu64(out1,a5120,a5120);
	__m512i carry  = _mm512_srli_epi64(out1,52);
	out1 = _mm512_and_si512(out1,mask52);

	out2 = _mm512_madd52hi_epu64(zero,a5120,a5121);
	out2 = _mm512_madd52lo_epu64(out2,a5120,a5122);
	out2 = _mm512_slli_epi64(out2,1);
	out2 = _mm512_madd52lo_epu64(out2,a5121,a5121);
	out2 = _mm512_add_epi64(out2,carry);
	carry  = _mm512_srli_epi64(out2,52);
	out2 = _mm512_and_si512(out2,mask52);

	out3 = _mm512_madd52hi_epu64(zero,a5120,a5122);
	out3 = _mm512_madd52lo_epu64(out3,a5120,a5123);
	out3 = _mm512_madd52lo_epu64(out3,a5121,a5122);
	out3 = _mm512_slli_epi64(out3,1);
	out3 = _mm512_madd52hi_epu64(out3,a5121,a5121);
	out3 = _mm512_add_epi64(out3,carry);
	carry  = _mm512_srli_epi64(out3,52);
	out3 = _mm512_and_si512(out3,mask52);

	out4 = _mm512_madd52hi_epu64(zero,a5120,a5123);
	out4 = _mm512_madd52hi_epu64(out4,a5121,a5122);
	out4 = _mm512_madd52lo_epu64(out4,a5120,a5124);
	out4 = _mm512_madd52lo_epu64(out4,a5121,a5123);
	out4 = _mm512_slli_epi64(out4,1);
	out4 = _mm512_madd52lo_epu64(out4,a5122,a5122);
	out4 = _mm512_add_epi64(out4,carry);
	carry  = _mm512_srli_epi64(out4,52);
	out4 = _mm512_and_si512(out4,mask52);

	out5 = _mm512_madd52hi_epu64(zero,a5120,a5124);
	out5 = _mm512_madd52hi_epu64(out5,a5121,a5123);
	out5 = _mm512_madd52lo_epu64(out5,a5121,a5124);
	out5 = _mm512_madd52lo_epu64(out5,a5122,a5123);
	out5 = _mm512_slli_epi64(out5,1);
	out5 = _mm512_madd52hi_epu64(out5,a5122,a5122);
	out5 = _mm512_add_epi64(out5,carry);
	carry  = _mm512_srli_epi64(out5,52);
	out5 = _mm512_and_si512(out5,mask52);

	out6 = _mm512_madd52hi_epu64(zero,a5121,a5124);
	out6 = _mm512_madd52hi_epu64(out6,a5122,a5123);
	out6 = _mm512_madd52lo_epu64(out6,a5122,a5124);
	out6 = _mm512_slli_epi64(out6,1);
	out6 = _mm512_madd52lo_epu64(out6,a5123,a5123);
	out6 = _mm512_add_epi64(out6,carry);
	carry  = _mm512_srli_epi64(out6,52);
	out6 = _mm512_and_si512(out6,mask52);

	out7 = _mm512_madd52hi_epu64(zero,a5122,a5124);
	out7 = _mm512_madd52lo_epu64(out7,a5123,a5124);
	out7 = _mm512_slli_epi64(out7,1);
	out7 = _mm512_madd52hi_epu64(out7,a5123,a5123);
	out7 = _mm512_add_epi64(out7,carry);
	carry  = _mm512_srli_epi64(out7,52);
	out7 = _mm512_and_si512(out7,mask52);

	out8 = _mm512_madd52hi_epu64(zero,a5123,a5124);
	out8 = _mm512_slli_epi64(out8,1);
	out8 = _mm512_madd52lo_epu64(out8,a5124,a5124);
	out8 = _mm512_add_epi64(out8,carry);
	carry  = _mm512_srli_epi64(out8,52);
	out8 = _mm512_and_si512(out8,mask52);

	out9 = _mm512_madd52hi_epu64(carry,a5124,a5124);

	_mm512_store_epi64(out+0,out0);
	_mm512_store_epi64(out+1,out1);
	_mm512_store_epi64(out+2,out2);
	_mm512_store_epi64(out+3,out3);
	_mm512_store_epi64(out+4,out4);
	_mm512_store_epi64(out+5,out5);
	_mm512_store_epi64(out+6,out6);
	_mm512_store_epi64(out+7,out7);
	_mm512_store_epi64(out+8,out8);
	_mm512_store_epi64(out+9,out9);
}

