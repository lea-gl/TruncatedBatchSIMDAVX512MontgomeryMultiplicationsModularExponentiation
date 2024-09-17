/* Schoolbook Block Montgomery multiplication */

inline void force_inline block_mont_mul512_8_156(__m512i out[3], __m512i a512[3], __m512i b512[3], __m512i n[3], __m512i n_prime[1])
{
	__m512i out512[6];
	out512[0] = _mm512_madd52lo_epu64(zero,a512[0],b512[0]);
	out512[1] = _mm512_madd52hi_epu64(zero,a512[0],b512[0]);
	out512[1] = _mm512_madd52lo_epu64(out512[1],a512[0],b512[1]);
	out512[2] = _mm512_madd52hi_epu64(zero,a512[0],b512[1]);
	out512[2] = _mm512_madd52lo_epu64(out512[2],a512[0],b512[2]);
	out512[3] = _mm512_madd52hi_epu64(zero,a512[0],b512[2]);

	__m512i q512 = _mm512_madd52lo_epu64(zero,out512[0],n_prime[0]);

	__m512i t512[4];
	t512[0] = _mm512_madd52lo_epu64(zero,q512,n[0]);
	t512[1] = _mm512_madd52hi_epu64(zero,q512,n[0]);
	t512[1] = _mm512_madd52lo_epu64(t512[1],q512,n[1]);
	t512[2] = _mm512_madd52hi_epu64(zero,q512,n[1]);
	t512[2] = _mm512_madd52lo_epu64(t512[2],q512,n[2]);
	t512[3] = _mm512_madd52hi_epu64(zero,q512,n[2]);

	out512[0] = _mm512_add_epi64(out512[0],t512[0]);
	__m512i carry  = _mm512_srli_epi64(out512[0],52);
	out512[0] = _mm512_and_si512(out512[0],mask52);
	out512[1] = _mm512_add_epi64(out512[1],carry);
	out512[1] = _mm512_add_epi64(out512[1],t512[1]);
	carry  = _mm512_srli_epi64(out512[1],52);
	out512[1] = _mm512_and_si512(out512[1],mask52);
	out512[2] = _mm512_add_epi64(out512[2],carry);
	out512[2] = _mm512_add_epi64(out512[2],t512[2]);
	carry  = _mm512_srli_epi64(out512[2],52);
	out512[2] = _mm512_and_si512(out512[2],mask52);
	out512[3] = _mm512_add_epi64(out512[3],carry);
	out512[3] = _mm512_add_epi64(out512[3],t512[3]);


	//Y = Y + a_iB

	out512[1] = _mm512_madd52lo_epu64(out512[1],a512[1],b512[0]);
	out512[2] = _mm512_madd52hi_epu64(out512[2],a512[1],b512[0]);
	out512[2] = _mm512_madd52lo_epu64(out512[2],a512[1],b512[1]);
	out512[3] = _mm512_madd52hi_epu64(out512[3],a512[1],b512[1]);
	out512[3] = _mm512_madd52lo_epu64(out512[3],a512[1],b512[2]);
	out512[4] = _mm512_madd52hi_epu64(zero,a512[1],b512[2]);

	q512 = _mm512_madd52lo_epu64(zero,out512[1],n_prime[0]);

	t512[0] = _mm512_madd52lo_epu64(zero,q512,n[0]);
	t512[1] = _mm512_madd52hi_epu64(zero,q512,n[0]);
	t512[1] = _mm512_madd52lo_epu64(t512[1],q512,n[1]);
	t512[2] = _mm512_madd52hi_epu64(zero,q512,n[1]);
	t512[2] = _mm512_madd52lo_epu64(t512[2],q512,n[2]);
	t512[3] = _mm512_madd52hi_epu64(zero,q512,n[2]);

	out512[1] = _mm512_add_epi64(out512[1],t512[0]);
	carry  = _mm512_srli_epi64(out512[1],52);
	out512[1] = _mm512_and_si512(out512[1],mask52);
	out512[2] = _mm512_add_epi64(out512[2],carry);
	out512[2] = _mm512_add_epi64(out512[2],t512[1]);
	carry  = _mm512_srli_epi64(out512[2],52);
	out512[2] = _mm512_and_si512(out512[2],mask52);
	out512[3] = _mm512_add_epi64(out512[3],carry);
	out512[3] = _mm512_add_epi64(out512[3],t512[2]);
	carry  = _mm512_srli_epi64(out512[3],52);
	out512[3] = _mm512_and_si512(out512[3],mask52);
	out512[4] = _mm512_add_epi64(out512[4],carry);
	out512[4] = _mm512_add_epi64(out512[4],t512[3]);

	// last loop iteration

	out512[2] = _mm512_madd52lo_epu64(out512[2],a512[2],b512[0]);
	out512[3] = _mm512_madd52hi_epu64(out512[3],a512[2],b512[0]);
	out512[3] = _mm512_madd52lo_epu64(out512[3],a512[2],b512[1]);
	out512[4] = _mm512_madd52hi_epu64(out512[4],a512[2],b512[1]);
	out512[4] = _mm512_madd52lo_epu64(out512[4],a512[2],b512[2]);
	out512[5] = _mm512_madd52hi_epu64(out512[5],a512[2],b512[2]);

	q512 = _mm512_madd52lo_epu64(zero,out512[2],n_prime[0]);

	t512[0] = _mm512_madd52lo_epu64(zero,q512,n[0]);
	t512[1] = _mm512_madd52hi_epu64(zero,q512,n[0]);
	t512[1] = _mm512_madd52lo_epu64(t512[1],q512,n[1]);
	t512[2] = _mm512_madd52hi_epu64(zero,q512,n[1]);
	t512[2] = _mm512_madd52lo_epu64(t512[2],q512,n[2]);
	t512[3] = _mm512_madd52hi_epu64(zero,q512,n[2]);

	out512[2] = _mm512_add_epi64(out512[2],t512[0]);
	carry  = _mm512_srli_epi64(out512[2],52);
	out[0] = _mm512_add_epi64(out512[3],carry);
	out[0] = _mm512_add_epi64(out[0],t512[1]);
	carry  = _mm512_srli_epi64(out[0],52);
	out[0] = _mm512_and_si512(out[0],mask52);
	out[1] = _mm512_add_epi64(out512[4],carry);
	out[1] = _mm512_add_epi64(out[1],t512[2]);
	carry  = _mm512_srli_epi64(out[1],52);
	out[1] = _mm512_and_si512(out[1],mask52);
	out[2] = _mm512_add_epi64(out512[5],carry);
	out[2] = _mm512_add_epi64(out[2],t512[3]);


}

/* Schoolbook Block Montgomery squaring */

/* Schoolbook squaring */

inline void force_inline block_mont_square512_8_156(__m512i out[3], __m512i a512[3], __m512i n[3], __m512i n_prime[1])
{

}

