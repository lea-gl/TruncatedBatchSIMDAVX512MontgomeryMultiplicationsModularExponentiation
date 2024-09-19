/* Schoolbook multiplication */

inline void force_inline mul512_8_SIZE(__m512i out[6], __m512i a512[3], __m512i b512[3])
{
	__m512i out0, out1;
	__m512i out2, out3;
	__m512i out4, out5;
	__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512);
	__m512i a5121 = _mm512_load_epi64(a512+1), b5121 = _mm512_load_epi64(b512+1);
	__m512i a5122 = _mm512_load_epi64(a512+2), b5122 = _mm512_load_epi64(b512+2);
	out0 = _mm512_madd52lo_epu64(zero,a5120,b5120);
	out1 = _mm512_madd52hi_epu64(zero,a5120,b5120);
	out1 = _mm512_madd52lo_epu64(out1,a5120,b5121);
	out2 = _mm512_madd52hi_epu64(zero,a5120,b5121);
	out2 = _mm512_madd52lo_epu64(out2,a5120,b5122);
	out3 = _mm512_madd52hi_epu64(zero,a5120,b5122);

	out1 = _mm512_madd52lo_epu64(out1,a5121,b5120);
	out2 = _mm512_madd52hi_epu64(out2,a5121,b5120);
	out2 = _mm512_madd52lo_epu64(out2,a5121,b5121);
	out3 = _mm512_madd52hi_epu64(out3,a5121,b5121);
	out3 = _mm512_madd52lo_epu64(out3,a5121,b5122);
	out4 = _mm512_madd52hi_epu64(zero,a5121,b5122);

	out2 = _mm512_madd52lo_epu64(out2,a5122,b5120);
	out3 = _mm512_madd52hi_epu64(out3,a5122,b5120);
	out3 = _mm512_madd52lo_epu64(out3,a5122,b5121);
	out4 = _mm512_madd52hi_epu64(out4,a5122,b5121);
	out4 = _mm512_madd52lo_epu64(out4,a5122,b5122);
	out5 = _mm512_madd52hi_epu64(zero,a5122,b5122);


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
	_mm512_store_epi64(out+0,out0);
	_mm512_store_epi64(out+1,out1);
	_mm512_store_epi64(out+2,out2);
	_mm512_store_epi64(out+3,out3);
	_mm512_store_epi64(out+4,out4);
	_mm512_store_epi64(out+5,out5);

}

/* Schoolbook squaring */

inline void force_inline square512_8_SIZE(__m512i out[6], __m512i a512[3])
{
	__m512i out0, out1;
	__m512i out2, out3;
	__m512i out4, out5;
	__m512i a5120 = _mm512_load_epi64(a512);
	__m512i a5121 = _mm512_load_epi64(a512+1);
	__m512i a5122 = _mm512_load_epi64(a512+2);
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
	out3 = _mm512_madd52lo_epu64(out3,a5121,a5122);
	out3 = _mm512_slli_epi64(out3,1);
	out3 = _mm512_madd52hi_epu64(out3,a5121,a5121);
	out3 = _mm512_add_epi64(out3,carry);
	carry  = _mm512_srli_epi64(out3,52);
	out3 = _mm512_and_si512(out3,mask52);

	out4 = _mm512_madd52hi_epu64(zero,a5121,a5122);
	out4 = _mm512_slli_epi64(out4,1);
	out4 = _mm512_madd52lo_epu64(out4,a5122,a5122);
	out4 = _mm512_add_epi64(out4,carry);
	carry  = _mm512_srli_epi64(out4,52);
	out4 = _mm512_and_si512(out4,mask52);

	out5 = _mm512_madd52hi_epu64(carry,a5122,a5122);

	_mm512_store_epi64(out+0,out0);
	_mm512_store_epi64(out+1,out1);
	_mm512_store_epi64(out+2,out2);
	_mm512_store_epi64(out+3,out3);
	_mm512_store_epi64(out+4,out4);
	_mm512_store_epi64(out+5,out5);
}

