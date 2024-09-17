/* Schoolbook multiplication modulo M*/

inline void force_inline block_mont_mul512_8_260(__m512i out[10], __m512i a512[5], __m512i b512[5], __m512i n[5], __m512i n_prime[1])
{
	__m512i out5120, out5121;
	__m512i out5122, out5123;
	__m512i out5124, out5125;
	__m512i out5126, out5127;
	__m512i out5128, out5129;
	__m512i t5120;
	__m512i t5121;
	__m512i t5122;
	__m512i t5123;
	__m512i t5124;
	__m512i t5125;
	__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512);
	__m512i a5121 = _mm512_load_epi64(a512+1), b5121 = _mm512_load_epi64(b512+1);
	__m512i a5122 = _mm512_load_epi64(a512+2), b5122 = _mm512_load_epi64(b512+2);
	__m512i a5123 = _mm512_load_epi64(a512+3), b5123 = _mm512_load_epi64(b512+3);
	__m512i a5124 = _mm512_load_epi64(a512+4), b5124 = _mm512_load_epi64(b512+4);
	__m512i n0 = _mm512_load_epi64(n+0);
	__m512i n1 = _mm512_load_epi64(n+1);
	__m512i n2 = _mm512_load_epi64(n+2);
	__m512i n3 = _mm512_load_epi64(n+3);
	__m512i n4 = _mm512_load_epi64(n+4);

	__m512i np0 = _mm512_load_epi64(n_prime);


	out5120 = _mm512_madd52lo_epu64(zero,a5120,b5120);
	out5121 = _mm512_madd52hi_epu64(zero,a5120,b5120);
	out5121 = _mm512_madd52lo_epu64(out5121,a5120,b5121);
	out5122 = _mm512_madd52hi_epu64(zero,a5120,b5121);
	out5122 = _mm512_madd52lo_epu64(out5122,a5120,b5122);
	out5123 = _mm512_madd52hi_epu64(zero,a5120,b5122);
	out5123 = _mm512_madd52lo_epu64(out5123,a5120,b5123);
	out5124 = _mm512_madd52hi_epu64(zero,a5120,b5123);
	out5124 = _mm512_madd52lo_epu64(out5124,a5120,b5124);
	out5125 = _mm512_madd52hi_epu64(zero,a5120,b5124);

	__m512i q512 = _mm512_madd52lo_epu64(zero,out5120,np0);

	t5120 = _mm512_madd52lo_epu64(zero,q512,n0);
	t5121 = _mm512_madd52hi_epu64(zero,q512,n0);
	t5121 = _mm512_madd52lo_epu64(t5121,q512,n1);
	t5122 = _mm512_madd52hi_epu64(zero,q512,n1);
	t5122 = _mm512_madd52lo_epu64(t5122,q512,n2);
	t5123 = _mm512_madd52hi_epu64(zero,q512,n2);
	t5123 = _mm512_madd52lo_epu64(t5123,q512,n3);
	t5124 = _mm512_madd52hi_epu64(zero,q512,n3);
	t5124 = _mm512_madd52lo_epu64(t5124,q512,n4);
	t5125 = _mm512_madd52hi_epu64(zero,q512,n4);

	out5120 = _mm512_add_epi64(out5120,t5120);
	__m512i carry  = _mm512_srli_epi64(out5120,52);
	out5120 = _mm512_and_si512(out5120,mask52);
	out5121 = _mm512_add_epi64(out5121,carry);
	out5121 = _mm512_add_epi64(out5121,t5121);
	carry  = _mm512_srli_epi64(out5121,52);
	out5121 = _mm512_and_si512(out5121,mask52);
	out5122 = _mm512_add_epi64(out5122,carry);
	out5122 = _mm512_add_epi64(out5122,t5122);
	carry  = _mm512_srli_epi64(out5122,52);
	out5122 = _mm512_and_si512(out5122,mask52);
	out5123 = _mm512_add_epi64(out5123,carry);
	out5123 = _mm512_add_epi64(out5123,t5123);
	carry  = _mm512_srli_epi64(out5123,52);
	out5123 = _mm512_and_si512(out5123,mask52);
	out5124 = _mm512_add_epi64(out5124,carry);
	out5124 = _mm512_add_epi64(out5124,t5124);
	carry  = _mm512_srli_epi64(out5124,52);
	out5124 = _mm512_and_si512(out5124,mask52);
	out5125 = _mm512_add_epi64(out5125,carry);
	out5125 = _mm512_add_epi64(out5125,t5125);


	//T = a_iB

	t5120 = _mm512_madd52lo_epu64(zero,a5121,b5120);
	t5121 = _mm512_madd52hi_epu64(zero,a5121,b5120);
	t5121 = _mm512_madd52lo_epu64(t5121,a5121,b5121);
	t5122 = _mm512_madd52hi_epu64(zero,a5121,b5121);
	t5122 = _mm512_madd52lo_epu64(t5122,a5121,b5122);
	t5123 = _mm512_madd52hi_epu64(zero,a5121,b5122);
	t5123 = _mm512_madd52lo_epu64(t5123,a5121,b5123);
	t5124 = _mm512_madd52hi_epu64(zero,a5121,b5123);
	t5124 = _mm512_madd52lo_epu64(t5124,a5121,b5124);
	t5125 = _mm512_madd52hi_epu64(zero,a5121,b5124);

	out5121 = _mm512_add_epi64(out5121,t5120);
	carry  = _mm512_srli_epi64(out5121,52);
	out5121 = _mm512_and_si512(out5121,mask52);
	out5122 = _mm512_add_epi64(out5122,carry);
	out5122 = _mm512_add_epi64(out5122,t5121);
	carry  = _mm512_srli_epi64(out5122,52);
	out5122 = _mm512_and_si512(out5122,mask52);
	out5123 = _mm512_add_epi64(out5123,carry);
	out5123 = _mm512_add_epi64(out5123,t5122);
	carry  = _mm512_srli_epi64(out5123,52);
	out5123 = _mm512_and_si512(out5123,mask52);
	out5124 = _mm512_add_epi64(out5124,carry);
	out5124 = _mm512_add_epi64(out5124,t5123);
	carry  = _mm512_srli_epi64(out5124,52);
	out5124 = _mm512_and_si512(out5124,mask52);
	out5125 = _mm512_add_epi64(out5125,carry);
	out5125 = _mm512_add_epi64(out5125,t5124);
	carry  = _mm512_srli_epi64(out5125,52);
	out5125 = _mm512_and_si512(out5125,mask52);
	out5126 = _mm512_add_epi64(out5126,carry);
	out5126 = _mm512_add_epi64(out5126,t5125);

	q512 = _mm512_madd52lo_epu64(zero,out5121,np0);

	t5120 = _mm512_madd52lo_epu64(zero,q512,n0);
	t5121 = _mm512_madd52hi_epu64(zero,q512,n0);
	t5121 = _mm512_madd52lo_epu64(t5121,q512,n1);
	t5122 = _mm512_madd52hi_epu64(zero,q512,n1);
	t5122 = _mm512_madd52lo_epu64(t5122,q512,n2);
	t5123 = _mm512_madd52hi_epu64(zero,q512,n2);
	t5123 = _mm512_madd52lo_epu64(t5123,q512,n3);
	t5124 = _mm512_madd52hi_epu64(zero,q512,n3);
	t5124 = _mm512_madd52lo_epu64(t5124,q512,n4);
	t5125 = _mm512_madd52hi_epu64(zero,q512,n4);

	out5121 = _mm512_add_epi64(out5121,t5120);
	carry  = _mm512_srli_epi64(out5121,52);
	out5121 = _mm512_and_si512(out5121,mask52);
	out5122 = _mm512_add_epi64(out5122,carry);
	out5122 = _mm512_add_epi64(out5122,t5121);
	carry  = _mm512_srli_epi64(out5122,52);
	out5122 = _mm512_and_si512(out5122,mask52);
	out5123 = _mm512_add_epi64(out5123,carry);
	out5123 = _mm512_add_epi64(out5123,t5122);
	carry  = _mm512_srli_epi64(out5123,52);
	out5123 = _mm512_and_si512(out5123,mask52);
	out5124 = _mm512_add_epi64(out5124,carry);
	out5124 = _mm512_add_epi64(out5124,t5123);
	carry  = _mm512_srli_epi64(out5124,52);
	out5124 = _mm512_and_si512(out5124,mask52);
	out5125 = _mm512_add_epi64(out5125,carry);
	out5125 = _mm512_add_epi64(out5125,t5124);
	carry  = _mm512_srli_epi64(out5125,52);
	out5125 = _mm512_and_si512(out5125,mask52);
	out5126 = _mm512_add_epi64(out5126,carry);
	out5126 = _mm512_add_epi64(out5126,t5125);


	//T = a_iB

	t5120 = _mm512_madd52lo_epu64(zero,a5122,b5120);
	t5121 = _mm512_madd52hi_epu64(zero,a5122,b5120);
	t5121 = _mm512_madd52lo_epu64(t5121,a5122,b5121);
	t5122 = _mm512_madd52hi_epu64(zero,a5122,b5121);
	t5122 = _mm512_madd52lo_epu64(t5122,a5122,b5122);
	t5123 = _mm512_madd52hi_epu64(zero,a5122,b5122);
	t5123 = _mm512_madd52lo_epu64(t5123,a5122,b5123);
	t5124 = _mm512_madd52hi_epu64(zero,a5122,b5123);
	t5124 = _mm512_madd52lo_epu64(t5124,a5122,b5124);
	t5125 = _mm512_madd52hi_epu64(zero,a5122,b5124);

	out5122 = _mm512_add_epi64(out5122,t5120);
	carry  = _mm512_srli_epi64(out5122,52);
	out5122 = _mm512_and_si512(out5122,mask52);
	out5123 = _mm512_add_epi64(out5123,carry);
	out5123 = _mm512_add_epi64(out5123,t5121);
	carry  = _mm512_srli_epi64(out5123,52);
	out5123 = _mm512_and_si512(out5123,mask52);
	out5124 = _mm512_add_epi64(out5124,carry);
	out5124 = _mm512_add_epi64(out5124,t5122);
	carry  = _mm512_srli_epi64(out5124,52);
	out5124 = _mm512_and_si512(out5124,mask52);
	out5125 = _mm512_add_epi64(out5125,carry);
	out5125 = _mm512_add_epi64(out5125,t5123);
	carry  = _mm512_srli_epi64(out5125,52);
	out5125 = _mm512_and_si512(out5125,mask52);
	out5126 = _mm512_add_epi64(out5126,carry);
	out5126 = _mm512_add_epi64(out5126,t5124);
	carry  = _mm512_srli_epi64(out5126,52);
	out5126 = _mm512_and_si512(out5126,mask52);
	out5127 = _mm512_add_epi64(out5127,carry);
	out5127 = _mm512_add_epi64(out5127,t5125);

	q512 = _mm512_madd52lo_epu64(zero,out5122,np0);

	t5120 = _mm512_madd52lo_epu64(zero,q512,n0);
	t5121 = _mm512_madd52hi_epu64(zero,q512,n0);
	t5121 = _mm512_madd52lo_epu64(t5121,q512,n1);
	t5122 = _mm512_madd52hi_epu64(zero,q512,n1);
	t5122 = _mm512_madd52lo_epu64(t5122,q512,n2);
	t5123 = _mm512_madd52hi_epu64(zero,q512,n2);
	t5123 = _mm512_madd52lo_epu64(t5123,q512,n3);
	t5124 = _mm512_madd52hi_epu64(zero,q512,n3);
	t5124 = _mm512_madd52lo_epu64(t5124,q512,n4);
	t5125 = _mm512_madd52hi_epu64(zero,q512,n4);

	out5122 = _mm512_add_epi64(out5122,t5120);
	carry  = _mm512_srli_epi64(out5122,52);
	out5122 = _mm512_and_si512(out5122,mask52);
	out5123 = _mm512_add_epi64(out5123,carry);
	out5123 = _mm512_add_epi64(out5123,t5121);
	carry  = _mm512_srli_epi64(out5123,52);
	out5123 = _mm512_and_si512(out5123,mask52);
	out5124 = _mm512_add_epi64(out5124,carry);
	out5124 = _mm512_add_epi64(out5124,t5122);
	carry  = _mm512_srli_epi64(out5124,52);
	out5124 = _mm512_and_si512(out5124,mask52);
	out5125 = _mm512_add_epi64(out5125,carry);
	out5125 = _mm512_add_epi64(out5125,t5123);
	carry  = _mm512_srli_epi64(out5125,52);
	out5125 = _mm512_and_si512(out5125,mask52);
	out5126 = _mm512_add_epi64(out5126,carry);
	out5126 = _mm512_add_epi64(out5126,t5124);
	carry  = _mm512_srli_epi64(out5126,52);
	out5126 = _mm512_and_si512(out5126,mask52);
	out5127 = _mm512_add_epi64(out5127,carry);
	out5127 = _mm512_add_epi64(out5127,t5125);


	//T = a_iB

	t5120 = _mm512_madd52lo_epu64(zero,a5123,b5120);
	t5121 = _mm512_madd52hi_epu64(zero,a5123,b5120);
	t5121 = _mm512_madd52lo_epu64(t5121,a5123,b5121);
	t5122 = _mm512_madd52hi_epu64(zero,a5123,b5121);
	t5122 = _mm512_madd52lo_epu64(t5122,a5123,b5122);
	t5123 = _mm512_madd52hi_epu64(zero,a5123,b5122);
	t5123 = _mm512_madd52lo_epu64(t5123,a5123,b5123);
	t5124 = _mm512_madd52hi_epu64(zero,a5123,b5123);
	t5124 = _mm512_madd52lo_epu64(t5124,a5123,b5124);
	t5125 = _mm512_madd52hi_epu64(zero,a5123,b5124);

	out5123 = _mm512_add_epi64(out5123,t5120);
	carry  = _mm512_srli_epi64(out5123,52);
	out5123 = _mm512_and_si512(out5123,mask52);
	out5124 = _mm512_add_epi64(out5124,carry);
	out5124 = _mm512_add_epi64(out5124,t5121);
	carry  = _mm512_srli_epi64(out5124,52);
	out5124 = _mm512_and_si512(out5124,mask52);
	out5125 = _mm512_add_epi64(out5125,carry);
	out5125 = _mm512_add_epi64(out5125,t5122);
	carry  = _mm512_srli_epi64(out5125,52);
	out5125 = _mm512_and_si512(out5125,mask52);
	out5126 = _mm512_add_epi64(out5126,carry);
	out5126 = _mm512_add_epi64(out5126,t5123);
	carry  = _mm512_srli_epi64(out5126,52);
	out5126 = _mm512_and_si512(out5126,mask52);
	out5127 = _mm512_add_epi64(out5127,carry);
	out5127 = _mm512_add_epi64(out5127,t5124);
	carry  = _mm512_srli_epi64(out5127,52);
	out5127 = _mm512_and_si512(out5127,mask52);
	out5128 = _mm512_add_epi64(out5128,carry);
	out5128 = _mm512_add_epi64(out5128,t5125);

	q512 = _mm512_madd52lo_epu64(zero,out5123,np0);

	t5120 = _mm512_madd52lo_epu64(zero,q512,n0);
	t5121 = _mm512_madd52hi_epu64(zero,q512,n0);
	t5121 = _mm512_madd52lo_epu64(t5121,q512,n1);
	t5122 = _mm512_madd52hi_epu64(zero,q512,n1);
	t5122 = _mm512_madd52lo_epu64(t5122,q512,n2);
	t5123 = _mm512_madd52hi_epu64(zero,q512,n2);
	t5123 = _mm512_madd52lo_epu64(t5123,q512,n3);
	t5124 = _mm512_madd52hi_epu64(zero,q512,n3);
	t5124 = _mm512_madd52lo_epu64(t5124,q512,n4);
	t5125 = _mm512_madd52hi_epu64(zero,q512,n4);

	out5123 = _mm512_add_epi64(out5123,t5120);
	carry  = _mm512_srli_epi64(out5123,52);
	out5123 = _mm512_and_si512(out5123,mask52);
	out5124 = _mm512_add_epi64(out5124,carry);
	out5124 = _mm512_add_epi64(out5124,t5121);
	carry  = _mm512_srli_epi64(out5124,52);
	out5124 = _mm512_and_si512(out5124,mask52);
	out5125 = _mm512_add_epi64(out5125,carry);
	out5125 = _mm512_add_epi64(out5125,t5122);
	carry  = _mm512_srli_epi64(out5125,52);
	out5125 = _mm512_and_si512(out5125,mask52);
	out5126 = _mm512_add_epi64(out5126,carry);
	out5126 = _mm512_add_epi64(out5126,t5123);
	carry  = _mm512_srli_epi64(out5126,52);
	out5126 = _mm512_and_si512(out5126,mask52);
	out5127 = _mm512_add_epi64(out5127,carry);
	out5127 = _mm512_add_epi64(out5127,t5124);
	carry  = _mm512_srli_epi64(out5127,52);
	out5127 = _mm512_and_si512(out5127,mask52);
	out5128 = _mm512_add_epi64(out5128,carry);
	out5128 = _mm512_add_epi64(out5128,t5125);

	out5124 = _mm512_madd52lo_epu64(zero,a5124,b5120);
	out5125 = _mm512_madd52hi_epu64(zero,a5124,b5120);
	out5125 = _mm512_madd52lo_epu64(out5125,a5124,b5121);
	out5126 = _mm512_madd52hi_epu64(zero,a5124,b5121);
	out5126 = _mm512_madd52lo_epu64(out5126,a5124,b5122);
	out5127 = _mm512_madd52hi_epu64(zero,a5124,b5122);
	out5127 = _mm512_madd52lo_epu64(out5127,a5124,b5123);
	out5128 = _mm512_madd52hi_epu64(zero,a5124,b5123);
	out5128 = _mm512_madd52lo_epu64(out5128,a5124,b5124);
	out5129 = _mm512_madd52hi_epu64(zero,a5124,b5124);

	q512 = _mm512_madd52lo_epu64(zero,out5124,np0);

	t5120 = _mm512_madd52lo_epu64(zero,q512,n0);
	t5121 = _mm512_madd52hi_epu64(zero,q512,n0);
	t5121 = _mm512_madd52lo_epu64(t5121,q512,n1);
	t5122 = _mm512_madd52hi_epu64(zero,q512,n1);
	t5122 = _mm512_madd52lo_epu64(t5122,q512,n2);
	t5123 = _mm512_madd52hi_epu64(zero,q512,n2);
	t5123 = _mm512_madd52lo_epu64(t5123,q512,n3);
	t5124 = _mm512_madd52hi_epu64(zero,q512,n3);
	t5124 = _mm512_madd52lo_epu64(t5124,q512,n4);
	t5125 = _mm512_madd52hi_epu64(zero,q512,n4);

	out5124 = _mm512_add_epi64(out5124,t5120);
	carry  = _mm512_srli_epi64(out5124,52);
	out[0] = _mm512_add_epi64(out5125,carry);
	out[0] = _mm512_add_epi64(out[0],t5121);
	carry  = _mm512_srli_epi64(out5125,52);
	out[0] = _mm512_and_si512(out[0],mask52);
	out[1] = _mm512_add_epi64(out5126,carry);
	out[1] = _mm512_add_epi64(out[1],t5122);
	carry  = _mm512_srli_epi64(out5126,52);
	out[1] = _mm512_and_si512(out[1],mask52);
	out[2] = _mm512_add_epi64(out5127,carry);
	out[2] = _mm512_add_epi64(out[2],t5123);
	carry  = _mm512_srli_epi64(out5127,52);
	out[2] = _mm512_and_si512(out[2],mask52);
	out[3] = _mm512_add_epi64(out5128,carry);
	out[3] = _mm512_add_epi64(out[3],t5124);
	carry  = _mm512_srli_epi64(out5128,52);
	out[3] = _mm512_and_si512(out[3],mask52);
	out[4] = _mm512_add_epi64(out5129,carry);
	out[4] = _mm512_add_epi64(out[4],t5125);

}

