/* Schoolbook multiplication modulo M*/

inline void force_inline block_mont_mul512_8_104(__m512i out[4], __m512i a512[2], __m512i b512[2], __m512i n[2], __m512i n_prime[1])
{
	__m512i out5120, out5121;
	__m512i out5122, out5123;
	__m512i t5120;
	__m512i t5121;
	__m512i t5122;
	__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512);
	__m512i a5121 = _mm512_load_epi64(a512+1), b5121 = _mm512_load_epi64(b512+1);
	__m512i n0 = _mm512_load_epi64(n+0);
	__m512i n1 = _mm512_load_epi64(n+1);

	__m512i np0 = _mm512_load_epi64(n_prime);


	out5120 = _mm512_madd52lo_epu64(zero,a5120,b5120);
	out5121 = _mm512_madd52hi_epu64(zero,a5120,b5120);
	out5121 = _mm512_madd52lo_epu64(out5121,a5120,b5121);
	out5122 = _mm512_madd52hi_epu64(zero,a5120,b5121);

	__m512i q512 = _mm512_madd52lo_epu64(zero,out5120,np0);

	t5120 = _mm512_madd52lo_epu64(zero,q512,n0);
	t5121 = _mm512_madd52hi_epu64(zero,q512,n0);
	t5121 = _mm512_madd52lo_epu64(t5121,q512,n1);
	t5122 = _mm512_madd52hi_epu64(zero,q512,n1);

	out5120 = _mm512_add_epi64(out5120,t5120);
	__m512i carry  = _mm512_srli_epi64(out5120,52);
	out5120 = _mm512_and_si512(out5120,mask52);
	out5121 = _mm512_add_epi64(out5121,carry);
	out5121 = _mm512_add_epi64(out5121,t5121);
	carry  = _mm512_srli_epi64(out5121,52);
	out5121 = _mm512_and_si512(out5121,mask52);
	out5122 = _mm512_add_epi64(out5122,carry);
	out5122 = _mm512_add_epi64(out5122,t5122);

	out5121 = _mm512_madd52lo_epu64(zero,a5121,b5120);
	out5122 = _mm512_madd52hi_epu64(zero,a5121,b5120);
	out5122 = _mm512_madd52lo_epu64(out5122,a5121,b5121);
	out5123 = _mm512_madd52hi_epu64(zero,a5121,b5121);

	q512 = _mm512_madd52lo_epu64(zero,out5121,np0);

	t5120 = _mm512_madd52lo_epu64(zero,q512,n0);
	t5121 = _mm512_madd52hi_epu64(zero,q512,n0);
	t5121 = _mm512_madd52lo_epu64(t5121,q512,n1);
	t5122 = _mm512_madd52hi_epu64(zero,q512,n1);

	out5121 = _mm512_add_epi64(out5121,t5120);
	carry  = _mm512_srli_epi64(out5121,52);
	out[0] = _mm512_add_epi64(out5122,carry);
	out[0] = _mm512_add_epi64(out[0],t5121);
	carry  = _mm512_srli_epi64(out5122,52);
	out[0] = _mm512_and_si512(out[0],mask52);
	out[1] = _mm512_add_epi64(out5123,carry);
	out[1] = _mm512_add_epi64(out[1],t5122);

}

