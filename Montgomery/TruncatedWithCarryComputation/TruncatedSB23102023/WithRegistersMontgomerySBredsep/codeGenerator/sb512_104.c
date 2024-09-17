/* Schoolbook multiplication modulo M*/

static inline void force_inline mul512_8_104_modM(__m512i out[4], __m512i a512[2], __m512i b512[2])
{
	__m512i out0, out1;
	__m512i out2, out3;
	__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512);
	__m512i a5121 = _mm512_load_epi64(a512+1), b5121 = _mm512_load_epi64(b512+1);
	out0 = _mm512_madd52lo_epu64(zero,a5120,b5120);
	out1 = _mm512_madd52hi_epu64(zero,a5120,b5120);
	out1 = _mm512_madd52lo_epu64(out1,a5120,b5121);

	out1 = _mm512_madd52lo_epu64(out1,a5121,b5120);


// Carry management

	__m512i carry  = _mm512_srli_epi64(out1,52);
	out2 = _mm512_add_epi64(out2,carry);
	out1 = _mm512_and_si512(out1,mask52);
	carry  = _mm512_srli_epi64(out0,52);
	out1 = _mm512_add_epi64(out1,carry);
	out0 = _mm512_and_si512(out0,mask52);
	out1 = _mm512_and_si512(out1,mask52);

	_mm512_store_epi64(out+0,out0);
	_mm512_store_epi64(out+1,out1);

}

/* Schoolbook multiplication*/

static inline void force_inline mul512_8_104(__m512i out[4], __m512i a512[2], __m512i b512[2])
{
	__m512i out0, out1;
	__m512i out2, out3;
	__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512);
	__m512i a5121 = _mm512_load_epi64(a512+1), b5121 = _mm512_load_epi64(b512+1);
	out0 = _mm512_madd52lo_epu64(zero,a5120,b5120);
	out1 = _mm512_madd52hi_epu64(zero,a5120,b5120);
	out1 = _mm512_madd52lo_epu64(out1,a5120,b5121);
	out2 = _mm512_madd52hi_epu64(zero,a5120,b5121);

	out1 = _mm512_madd52lo_epu64(out1,a5121,b5120);
	out2 = _mm512_madd52hi_epu64(out2,a5121,b5120);
	out2 = _mm512_madd52lo_epu64(out2,a5121,b5121);
	out3 = _mm512_madd52hi_epu64(zero,a5121,b5121);


// Carry management

	__m512i carry  = _mm512_srli_epi64(out1,52);
	out2 = _mm512_add_epi64(out2,carry);
	out1 = _mm512_and_si512(out1,mask52);
	carry  = _mm512_srli_epi64(out2,52);
	out3 = _mm512_add_epi64(out3,carry);
	out2 = _mm512_and_si512(out2,mask52);
	_mm512_store_epi64(out+0,out0);
	_mm512_store_epi64(out+1,out1);
	_mm512_store_epi64(out+2,out2);
	_mm512_store_epi64(out+3,out3);

}

/* Schoolbook multiplyer-adder : out = c + ab */

static inline void force_inline fma512_8_104(__m512i out[4], __m512i a512[2], __m512i b512[2], __m512i c512[4])
{
	__m512i out0 = _mm512_load_epi64(c512), out1 = _mm512_load_epi64(c512+1);
	__m512i out2 = _mm512_load_epi64(c512+2), out3 = _mm512_load_epi64(c512+3);
	__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512);
	__m512i a5121 = _mm512_load_epi64(a512+1), b5121 = _mm512_load_epi64(b512+1);
	out0 = _mm512_madd52lo_epu64(out0,a5120,b5120);
	out1 = _mm512_madd52hi_epu64(out1,a5120,b5120);
	out1 = _mm512_madd52lo_epu64(out1,a5120,b5121);
	out2 = _mm512_madd52hi_epu64(out2,a5120,b5121);

	out1 = _mm512_madd52lo_epu64(out1,a5121,b5120);
	out2 = _mm512_madd52hi_epu64(out2,a5121,b5120);
	out2 = _mm512_madd52lo_epu64(out2,a5121,b5121);
	out3 = _mm512_madd52hi_epu64(out3,a5121,b5121);


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
	_mm512_store_epi64(out+0,out0);
	_mm512_store_epi64(out+1,out1);
	_mm512_store_epi64(out+2,out2);
	_mm512_store_epi64(out+3,out3);

}

/* Schoolbook squaring */

static inline void force_inline square512_8_104(__m512i out[4], __m512i a512[2])
{
	__m512i out0, out1;
	__m512i out2, out3;
	__m512i a5120 = _mm512_load_epi64(a512);
	__m512i a5121 = _mm512_load_epi64(a512+1);
	out0 = _mm512_madd52lo_epu64(zero,a5120,a5120);

	out1 = _mm512_madd52lo_epu64(zero,a5120,a5121);
	out1 = _mm512_slli_epi64(out1,1);
	out1 = _mm512_madd52hi_epu64(out1,a5120,a5120);
	__m512i carry  = _mm512_srli_epi64(out1,52);
	out1 = _mm512_and_si512(out1,mask52);

	out2 = _mm512_madd52hi_epu64(zero,a5120,a5121);
	out2 = _mm512_slli_epi64(out2,1);
	out2 = _mm512_madd52lo_epu64(out2,a5121,a5121);
	out2 = _mm512_add_epi64(out2,carry);
	carry  = _mm512_srli_epi64(out2,52);
	out2 = _mm512_and_si512(out2,mask52);

	out3 = _mm512_madd52hi_epu64(carry,a5121,a5121);

	_mm512_store_epi64(out+0,out0);
	_mm512_store_epi64(out+1,out1);
	_mm512_store_epi64(out+2,out2);
	_mm512_store_epi64(out+3,out3);
}

