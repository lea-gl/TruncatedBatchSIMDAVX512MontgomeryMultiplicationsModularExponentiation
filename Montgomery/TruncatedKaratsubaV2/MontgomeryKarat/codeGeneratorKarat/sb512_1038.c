/* Karatsuba multiplication mod M*/

inline void force_inline mul512_8_1038K_modM(__m512i out[40], __m512i a512[20], __m512i b512[20])
{

	// D0 = Al*Bl

	__m512i D0_0, D0_1;
	__m512i D0_2, D0_3;
	__m512i D0_4, D0_5;
	__m512i D0_6, D0_7;
	__m512i D0_8, D0_9;
	__m512i D0_10, D0_11;
	__m512i D0_12, D0_13;
	__m512i D0_14, D0_15;
	__m512i D0_16, D0_17;
	__m512i D0_18, D0_19;
	__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512);
	__m512i a5121 = _mm512_load_epi64(a512+1), b5121 = _mm512_load_epi64(b512+1);
	__m512i a5122 = _mm512_load_epi64(a512+2), b5122 = _mm512_load_epi64(b512+2);
	__m512i a5123 = _mm512_load_epi64(a512+3), b5123 = _mm512_load_epi64(b512+3);
	__m512i a5124 = _mm512_load_epi64(a512+4), b5124 = _mm512_load_epi64(b512+4);
	__m512i a5125 = _mm512_load_epi64(a512+5), b5125 = _mm512_load_epi64(b512+5);
	__m512i a5126 = _mm512_load_epi64(a512+6), b5126 = _mm512_load_epi64(b512+6);
	__m512i a5127 = _mm512_load_epi64(a512+7), b5127 = _mm512_load_epi64(b512+7);
	__m512i a5128 = _mm512_load_epi64(a512+8), b5128 = _mm512_load_epi64(b512+8);
	__m512i a5129 = _mm512_load_epi64(a512+9), b5129 = _mm512_load_epi64(b512+9);
	D0_0 = _mm512_madd52lo_epu64(zero,a5120,b5120);
	D0_1 = _mm512_madd52hi_epu64(zero,a5120,b5120);
	D0_1 = _mm512_madd52lo_epu64(D0_1,a5120,b5121);
	D0_2 = _mm512_madd52hi_epu64(zero,a5120,b5121);
	D0_2 = _mm512_madd52lo_epu64(D0_2,a5120,b5122);
	D0_3 = _mm512_madd52hi_epu64(zero,a5120,b5122);
	D0_3 = _mm512_madd52lo_epu64(D0_3,a5120,b5123);
	D0_4 = _mm512_madd52hi_epu64(zero,a5120,b5123);
	D0_4 = _mm512_madd52lo_epu64(D0_4,a5120,b5124);
	D0_5 = _mm512_madd52hi_epu64(zero,a5120,b5124);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5120,b5125);
	D0_6 = _mm512_madd52hi_epu64(zero,a5120,b5125);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5120,b5126);
	D0_7 = _mm512_madd52hi_epu64(zero,a5120,b5126);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5120,b5127);
	D0_8 = _mm512_madd52hi_epu64(zero,a5120,b5127);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5120,b5128);
	D0_9 = _mm512_madd52hi_epu64(zero,a5120,b5128);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5120,b5129);
	D0_10 = _mm512_madd52hi_epu64(zero,a5120,b5129);

	D0_1 = _mm512_madd52lo_epu64(D0_1,a5121,b5120);
	D0_2 = _mm512_madd52hi_epu64(D0_2,a5121,b5120);
	D0_2 = _mm512_madd52lo_epu64(D0_2,a5121,b5121);
	D0_3 = _mm512_madd52hi_epu64(D0_3,a5121,b5121);
	D0_3 = _mm512_madd52lo_epu64(D0_3,a5121,b5122);
	D0_4 = _mm512_madd52hi_epu64(D0_4,a5121,b5122);
	D0_4 = _mm512_madd52lo_epu64(D0_4,a5121,b5123);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5121,b5123);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5121,b5124);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5121,b5124);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5121,b5125);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5121,b5125);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5121,b5126);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5121,b5126);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5121,b5127);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5121,b5127);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5121,b5128);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5121,b5128);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5121,b5129);
	D0_11 = _mm512_madd52hi_epu64(zero,a5121,b5129);

	D0_2 = _mm512_madd52lo_epu64(D0_2,a5122,b5120);
	D0_3 = _mm512_madd52hi_epu64(D0_3,a5122,b5120);
	D0_3 = _mm512_madd52lo_epu64(D0_3,a5122,b5121);
	D0_4 = _mm512_madd52hi_epu64(D0_4,a5122,b5121);
	D0_4 = _mm512_madd52lo_epu64(D0_4,a5122,b5122);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5122,b5122);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5122,b5123);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5122,b5123);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5122,b5124);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5122,b5124);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5122,b5125);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5122,b5125);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5122,b5126);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5122,b5126);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5122,b5127);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5122,b5127);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5122,b5128);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5122,b5128);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5122,b5129);
	D0_12 = _mm512_madd52hi_epu64(zero,a5122,b5129);

	D0_3 = _mm512_madd52lo_epu64(D0_3,a5123,b5120);
	D0_4 = _mm512_madd52hi_epu64(D0_4,a5123,b5120);
	D0_4 = _mm512_madd52lo_epu64(D0_4,a5123,b5121);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5123,b5121);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5123,b5122);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5123,b5122);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5123,b5123);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5123,b5123);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5123,b5124);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5123,b5124);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5123,b5125);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5123,b5125);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5123,b5126);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5123,b5126);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5123,b5127);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5123,b5127);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5123,b5128);
	D0_12 = _mm512_madd52hi_epu64(D0_12,a5123,b5128);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5123,b5129);
	D0_13 = _mm512_madd52hi_epu64(zero,a5123,b5129);

	D0_4 = _mm512_madd52lo_epu64(D0_4,a5124,b5120);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5124,b5120);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5124,b5121);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5124,b5121);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5124,b5122);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5124,b5122);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5124,b5123);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5124,b5123);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5124,b5124);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5124,b5124);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5124,b5125);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5124,b5125);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5124,b5126);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5124,b5126);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5124,b5127);
	D0_12 = _mm512_madd52hi_epu64(D0_12,a5124,b5127);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5124,b5128);
	D0_13 = _mm512_madd52hi_epu64(D0_13,a5124,b5128);
	D0_13 = _mm512_madd52lo_epu64(D0_13,a5124,b5129);
	D0_14 = _mm512_madd52hi_epu64(zero,a5124,b5129);

	D0_5 = _mm512_madd52lo_epu64(D0_5,a5125,b5120);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5125,b5120);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5125,b5121);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5125,b5121);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5125,b5122);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5125,b5122);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5125,b5123);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5125,b5123);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5125,b5124);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5125,b5124);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5125,b5125);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5125,b5125);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5125,b5126);
	D0_12 = _mm512_madd52hi_epu64(D0_12,a5125,b5126);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5125,b5127);
	D0_13 = _mm512_madd52hi_epu64(D0_13,a5125,b5127);
	D0_13 = _mm512_madd52lo_epu64(D0_13,a5125,b5128);
	D0_14 = _mm512_madd52hi_epu64(D0_14,a5125,b5128);
	D0_14 = _mm512_madd52lo_epu64(D0_14,a5125,b5129);
	D0_15 = _mm512_madd52hi_epu64(zero,a5125,b5129);

	D0_6 = _mm512_madd52lo_epu64(D0_6,a5126,b5120);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5126,b5120);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5126,b5121);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5126,b5121);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5126,b5122);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5126,b5122);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5126,b5123);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5126,b5123);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5126,b5124);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5126,b5124);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5126,b5125);
	D0_12 = _mm512_madd52hi_epu64(D0_12,a5126,b5125);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5126,b5126);
	D0_13 = _mm512_madd52hi_epu64(D0_13,a5126,b5126);
	D0_13 = _mm512_madd52lo_epu64(D0_13,a5126,b5127);
	D0_14 = _mm512_madd52hi_epu64(D0_14,a5126,b5127);
	D0_14 = _mm512_madd52lo_epu64(D0_14,a5126,b5128);
	D0_15 = _mm512_madd52hi_epu64(D0_15,a5126,b5128);
	D0_15 = _mm512_madd52lo_epu64(D0_15,a5126,b5129);
	D0_16 = _mm512_madd52hi_epu64(zero,a5126,b5129);

	D0_7 = _mm512_madd52lo_epu64(D0_7,a5127,b5120);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5127,b5120);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5127,b5121);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5127,b5121);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5127,b5122);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5127,b5122);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5127,b5123);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5127,b5123);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5127,b5124);
	D0_12 = _mm512_madd52hi_epu64(D0_12,a5127,b5124);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5127,b5125);
	D0_13 = _mm512_madd52hi_epu64(D0_13,a5127,b5125);
	D0_13 = _mm512_madd52lo_epu64(D0_13,a5127,b5126);
	D0_14 = _mm512_madd52hi_epu64(D0_14,a5127,b5126);
	D0_14 = _mm512_madd52lo_epu64(D0_14,a5127,b5127);
	D0_15 = _mm512_madd52hi_epu64(D0_15,a5127,b5127);
	D0_15 = _mm512_madd52lo_epu64(D0_15,a5127,b5128);
	D0_16 = _mm512_madd52hi_epu64(D0_16,a5127,b5128);
	D0_16 = _mm512_madd52lo_epu64(D0_16,a5127,b5129);
	D0_17 = _mm512_madd52hi_epu64(zero,a5127,b5129);

	D0_8 = _mm512_madd52lo_epu64(D0_8,a5128,b5120);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5128,b5120);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5128,b5121);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5128,b5121);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5128,b5122);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5128,b5122);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5128,b5123);
	D0_12 = _mm512_madd52hi_epu64(D0_12,a5128,b5123);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5128,b5124);
	D0_13 = _mm512_madd52hi_epu64(D0_13,a5128,b5124);
	D0_13 = _mm512_madd52lo_epu64(D0_13,a5128,b5125);
	D0_14 = _mm512_madd52hi_epu64(D0_14,a5128,b5125);
	D0_14 = _mm512_madd52lo_epu64(D0_14,a5128,b5126);
	D0_15 = _mm512_madd52hi_epu64(D0_15,a5128,b5126);
	D0_15 = _mm512_madd52lo_epu64(D0_15,a5128,b5127);
	D0_16 = _mm512_madd52hi_epu64(D0_16,a5128,b5127);
	D0_16 = _mm512_madd52lo_epu64(D0_16,a5128,b5128);
	D0_17 = _mm512_madd52hi_epu64(D0_17,a5128,b5128);
	D0_17 = _mm512_madd52lo_epu64(D0_17,a5128,b5129);
	D0_18 = _mm512_madd52hi_epu64(zero,a5128,b5129);

	D0_9 = _mm512_madd52lo_epu64(D0_9,a5129,b5120);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5129,b5120);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5129,b5121);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5129,b5121);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5129,b5122);
	D0_12 = _mm512_madd52hi_epu64(D0_12,a5129,b5122);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5129,b5123);
	D0_13 = _mm512_madd52hi_epu64(D0_13,a5129,b5123);
	D0_13 = _mm512_madd52lo_epu64(D0_13,a5129,b5124);
	D0_14 = _mm512_madd52hi_epu64(D0_14,a5129,b5124);
	D0_14 = _mm512_madd52lo_epu64(D0_14,a5129,b5125);
	D0_15 = _mm512_madd52hi_epu64(D0_15,a5129,b5125);
	D0_15 = _mm512_madd52lo_epu64(D0_15,a5129,b5126);
	D0_16 = _mm512_madd52hi_epu64(D0_16,a5129,b5126);
	D0_16 = _mm512_madd52lo_epu64(D0_16,a5129,b5127);
	D0_17 = _mm512_madd52hi_epu64(D0_17,a5129,b5127);
	D0_17 = _mm512_madd52lo_epu64(D0_17,a5129,b5128);
	D0_18 = _mm512_madd52hi_epu64(D0_18,a5129,b5128);
	D0_18 = _mm512_madd52lo_epu64(D0_18,a5129,b5129);
	D0_19 = _mm512_madd52hi_epu64(zero,a5129,b5129);


	// Carry management

	__m512i carry  = _mm512_srli_epi64(D0_1,52);
	D0_2 = _mm512_add_epi64(D0_2,carry);
	D0_1 = _mm512_and_si512(D0_1,mask52);
	carry  = _mm512_srli_epi64(D0_2,52);
	D0_3 = _mm512_add_epi64(D0_3,carry);
	D0_2 = _mm512_and_si512(D0_2,mask52);
	carry  = _mm512_srli_epi64(D0_3,52);
	D0_4 = _mm512_add_epi64(D0_4,carry);
	D0_3 = _mm512_and_si512(D0_3,mask52);
	carry  = _mm512_srli_epi64(D0_4,52);
	D0_5 = _mm512_add_epi64(D0_5,carry);
	D0_4 = _mm512_and_si512(D0_4,mask52);
	carry  = _mm512_srli_epi64(D0_5,52);
	D0_6 = _mm512_add_epi64(D0_6,carry);
	D0_5 = _mm512_and_si512(D0_5,mask52);
	carry  = _mm512_srli_epi64(D0_6,52);
	D0_7 = _mm512_add_epi64(D0_7,carry);
	D0_6 = _mm512_and_si512(D0_6,mask52);
	carry  = _mm512_srli_epi64(D0_7,52);
	D0_8 = _mm512_add_epi64(D0_8,carry);
	D0_7 = _mm512_and_si512(D0_7,mask52);
	carry  = _mm512_srli_epi64(D0_8,52);
	D0_9 = _mm512_add_epi64(D0_9,carry);
	D0_8 = _mm512_and_si512(D0_8,mask52);
	carry  = _mm512_srli_epi64(D0_9,52);
	D0_10 = _mm512_add_epi64(D0_10,carry);
	D0_9 = _mm512_and_si512(D0_9,mask52);
	carry  = _mm512_srli_epi64(D0_10,52);
	D0_11 = _mm512_add_epi64(D0_11,carry);
	D0_10 = _mm512_and_si512(D0_10,mask52);
	carry  = _mm512_srli_epi64(D0_11,52);
	D0_12 = _mm512_add_epi64(D0_12,carry);
	D0_11 = _mm512_and_si512(D0_11,mask52);
	carry  = _mm512_srli_epi64(D0_12,52);
	D0_13 = _mm512_add_epi64(D0_13,carry);
	D0_12 = _mm512_and_si512(D0_12,mask52);
	carry  = _mm512_srli_epi64(D0_13,52);
	D0_14 = _mm512_add_epi64(D0_14,carry);
	D0_13 = _mm512_and_si512(D0_13,mask52);
	carry  = _mm512_srli_epi64(D0_14,52);
	D0_15 = _mm512_add_epi64(D0_15,carry);
	D0_14 = _mm512_and_si512(D0_14,mask52);
	carry  = _mm512_srli_epi64(D0_15,52);
	D0_16 = _mm512_add_epi64(D0_16,carry);
	D0_15 = _mm512_and_si512(D0_15,mask52);
	carry  = _mm512_srli_epi64(D0_16,52);
	D0_17 = _mm512_add_epi64(D0_17,carry);
	D0_16 = _mm512_and_si512(D0_16,mask52);
	carry  = _mm512_srli_epi64(D0_17,52);
	D0_18 = _mm512_add_epi64(D0_18,carry);
	D0_17 = _mm512_and_si512(D0_17,mask52);
	carry  = _mm512_srli_epi64(D0_18,52);
	D0_19 = _mm512_add_epi64(D0_19,carry);
	D0_18 = _mm512_and_si512(D0_18,mask52);

	// Conversion in base 2^519

	carry = D0_9>>51;
	D0_10 = (D0_10<<1)|carry;
	D0_9 &= mask51;
	carry = D0_10>>52;
	D0_11 = (D0_11<<1)|carry;
	D0_10 &= mask52;
	carry = D0_11>>52;
	D0_12 = (D0_12<<1)|carry;
	D0_11 &= mask52;
	carry = D0_12>>52;
	D0_13 = (D0_13<<1)|carry;
	D0_12 &= mask52;
	carry = D0_13>>52;
	D0_14 = (D0_14<<1)|carry;
	D0_13 &= mask52;
	carry = D0_14>>52;
	D0_15 = (D0_15<<1)|carry;
	D0_14 &= mask52;
	carry = D0_15>>52;
	D0_16 = (D0_16<<1)|carry;
	D0_15 &= mask52;
	carry = D0_16>>52;
	D0_17 = (D0_17<<1)|carry;
	D0_16 &= mask52;
	carry = D0_17>>52;
	D0_18 = (D0_18<<1)|carry;
	D0_17 &= mask52;
	carry = D0_18>>52;
	D0_19 = (D0_19<<1)|carry;
	D0_18 &= mask52;

	// D2 = Ah*Bh

	__m512i D2_0;
	__m512i D2_1;
	__m512i D2_2;
	__m512i D2_3;
	__m512i D2_4;
	__m512i D2_5;
	__m512i D2_6;
	__m512i D2_7;
	__m512i D2_8;
	__m512i D2_9;
	__m512i a51210 = _mm512_load_epi64(a512+10), b51210 = _mm512_load_epi64(b512+10);
	__m512i a51211 = _mm512_load_epi64(a512+11), b51211 = _mm512_load_epi64(b512+11);
	__m512i a51212 = _mm512_load_epi64(a512+12), b51212 = _mm512_load_epi64(b512+12);
	__m512i a51213 = _mm512_load_epi64(a512+13), b51213 = _mm512_load_epi64(b512+13);
	__m512i a51214 = _mm512_load_epi64(a512+14), b51214 = _mm512_load_epi64(b512+14);
	__m512i a51215 = _mm512_load_epi64(a512+15), b51215 = _mm512_load_epi64(b512+15);
	__m512i a51216 = _mm512_load_epi64(a512+16), b51216 = _mm512_load_epi64(b512+16);
	__m512i a51217 = _mm512_load_epi64(a512+17), b51217 = _mm512_load_epi64(b512+17);
	__m512i a51218 = _mm512_load_epi64(a512+18), b51218 = _mm512_load_epi64(b512+18);
	__m512i a51219 = _mm512_load_epi64(a512+19), b51219 = _mm512_load_epi64(b512+19);
	D2_0 = _mm512_madd52lo_epu64(zero,a51210,b51210);
	D2_1 = _mm512_madd52hi_epu64(zero,a51210,b51210);
	D2_1 = _mm512_madd52lo_epu64(D2_1,a51210,b51211);
	D2_2 = _mm512_madd52hi_epu64(zero,a51210,b51211);
	D2_2 = _mm512_madd52lo_epu64(D2_2,a51210,b51212);
	D2_3 = _mm512_madd52hi_epu64(zero,a51210,b51212);
	D2_3 = _mm512_madd52lo_epu64(D2_3,a51210,b51213);
	D2_4 = _mm512_madd52hi_epu64(zero,a51210,b51213);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a51210,b51214);
	D2_5 = _mm512_madd52hi_epu64(zero,a51210,b51214);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a51210,b51215);
	D2_6 = _mm512_madd52hi_epu64(zero,a51210,b51215);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a51210,b51216);
	D2_7 = _mm512_madd52hi_epu64(zero,a51210,b51216);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51210,b51217);
	D2_8 = _mm512_madd52hi_epu64(zero,a51210,b51217);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51210,b51218);
	D2_9 = _mm512_madd52hi_epu64(zero,a51210,b51218);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51210,b51219);

	D2_1 = _mm512_madd52lo_epu64(D2_1,a51211,b51210);
	D2_2 = _mm512_madd52hi_epu64(D2_2,a51211,b51210);
	D2_2 = _mm512_madd52lo_epu64(D2_2,a51211,b51211);
	D2_3 = _mm512_madd52hi_epu64(D2_3,a51211,b51211);
	D2_3 = _mm512_madd52lo_epu64(D2_3,a51211,b51212);
	D2_4 = _mm512_madd52hi_epu64(D2_4,a51211,b51212);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a51211,b51213);
	D2_5 = _mm512_madd52hi_epu64(D2_5,a51211,b51213);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a51211,b51214);
	D2_6 = _mm512_madd52hi_epu64(D2_6,a51211,b51214);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a51211,b51215);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a51211,b51215);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51211,b51216);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a51211,b51216);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51211,b51217);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51211,b51217);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51211,b51218);

	D2_2 = _mm512_madd52lo_epu64(D2_2,a51212,b51210);
	D2_3 = _mm512_madd52hi_epu64(D2_3,a51212,b51210);
	D2_3 = _mm512_madd52lo_epu64(D2_3,a51212,b51211);
	D2_4 = _mm512_madd52hi_epu64(D2_4,a51212,b51211);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a51212,b51212);
	D2_5 = _mm512_madd52hi_epu64(D2_5,a51212,b51212);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a51212,b51213);
	D2_6 = _mm512_madd52hi_epu64(D2_6,a51212,b51213);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a51212,b51214);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a51212,b51214);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51212,b51215);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a51212,b51215);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51212,b51216);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51212,b51216);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51212,b51217);

	D2_3 = _mm512_madd52lo_epu64(D2_3,a51213,b51210);
	D2_4 = _mm512_madd52hi_epu64(D2_4,a51213,b51210);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a51213,b51211);
	D2_5 = _mm512_madd52hi_epu64(D2_5,a51213,b51211);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a51213,b51212);
	D2_6 = _mm512_madd52hi_epu64(D2_6,a51213,b51212);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a51213,b51213);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a51213,b51213);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51213,b51214);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a51213,b51214);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51213,b51215);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51213,b51215);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51213,b51216);

	D2_4 = _mm512_madd52lo_epu64(D2_4,a51214,b51210);
	D2_5 = _mm512_madd52hi_epu64(D2_5,a51214,b51210);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a51214,b51211);
	D2_6 = _mm512_madd52hi_epu64(D2_6,a51214,b51211);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a51214,b51212);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a51214,b51212);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51214,b51213);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a51214,b51213);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51214,b51214);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51214,b51214);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51214,b51215);

	D2_5 = _mm512_madd52lo_epu64(D2_5,a51215,b51210);
	D2_6 = _mm512_madd52hi_epu64(D2_6,a51215,b51210);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a51215,b51211);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a51215,b51211);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51215,b51212);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a51215,b51212);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51215,b51213);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51215,b51213);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51215,b51214);

	D2_6 = _mm512_madd52lo_epu64(D2_6,a51216,b51210);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a51216,b51210);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51216,b51211);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a51216,b51211);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51216,b51212);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51216,b51212);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51216,b51213);

	D2_7 = _mm512_madd52lo_epu64(D2_7,a51217,b51210);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a51217,b51210);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51217,b51211);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51217,b51211);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51217,b51212);

	D2_8 = _mm512_madd52lo_epu64(D2_8,a51218,b51210);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51218,b51210);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51218,b51211);

	D2_9 = _mm512_madd52lo_epu64(D2_9,a51219,b51210);


	// Carry management

	carry  = _mm512_srli_epi64(D2_1,52);
	D2_2 = _mm512_add_epi64(D2_2,carry);
	D2_1 = _mm512_and_si512(D2_1,mask52);
	carry  = _mm512_srli_epi64(D2_2,52);
	D2_3 = _mm512_add_epi64(D2_3,carry);
	D2_2 = _mm512_and_si512(D2_2,mask52);
	carry  = _mm512_srli_epi64(D2_3,52);
	D2_4 = _mm512_add_epi64(D2_4,carry);
	D2_3 = _mm512_and_si512(D2_3,mask52);
	carry  = _mm512_srli_epi64(D2_4,52);
	D2_5 = _mm512_add_epi64(D2_5,carry);
	D2_4 = _mm512_and_si512(D2_4,mask52);
	carry  = _mm512_srli_epi64(D2_5,52);
	D2_6 = _mm512_add_epi64(D2_6,carry);
	D2_5 = _mm512_and_si512(D2_5,mask52);
	carry  = _mm512_srli_epi64(D2_6,52);
	D2_7 = _mm512_add_epi64(D2_7,carry);
	D2_6 = _mm512_and_si512(D2_6,mask52);
	carry  = _mm512_srli_epi64(D2_7,52);
	D2_8 = _mm512_add_epi64(D2_8,carry);
	D2_7 = _mm512_and_si512(D2_7,mask52);
	carry  = _mm512_srli_epi64(D2_8,52);
	D2_9 = _mm512_add_epi64(D2_9,carry);
	D2_8 = _mm512_and_si512(D2_8,mask52);

	// D1 = (Al+Ah)*(Bl+Bh)

	__m512i D1_0;
	__m512i D1_1;
	__m512i D1_2;
	__m512i D1_3;
	__m512i D1_4;
	__m512i D1_5;
	__m512i D1_6;
	__m512i D1_7;
	__m512i D1_8;
	__m512i D1_9;

	__m512i alpah0 = _mm512_add_epi64(a5120,a51210);
	carry = alpah0>>52;
	alpah0 &= mask52;
	__m512i alpah1 = _mm512_add_epi64(a5121,carry);
	alpah1 = _mm512_add_epi64(alpah1,a51211);
	carry = alpah1>>52;
	alpah1 &= mask52;
	__m512i alpah2 = _mm512_add_epi64(a5122,carry);
	alpah2 = _mm512_add_epi64(alpah2,a51212);
	carry = alpah2>>52;
	alpah2 &= mask52;
	__m512i alpah3 = _mm512_add_epi64(a5123,carry);
	alpah3 = _mm512_add_epi64(alpah3,a51213);
	carry = alpah3>>52;
	alpah3 &= mask52;
	__m512i alpah4 = _mm512_add_epi64(a5124,carry);
	alpah4 = _mm512_add_epi64(alpah4,a51214);
	carry = alpah4>>52;
	alpah4 &= mask52;
	__m512i alpah5 = _mm512_add_epi64(a5125,carry);
	alpah5 = _mm512_add_epi64(alpah5,a51215);
	carry = alpah5>>52;
	alpah5 &= mask52;
	__m512i alpah6 = _mm512_add_epi64(a5126,carry);
	alpah6 = _mm512_add_epi64(alpah6,a51216);
	carry = alpah6>>52;
	alpah6 &= mask52;
	__m512i alpah7 = _mm512_add_epi64(a5127,carry);
	alpah7 = _mm512_add_epi64(alpah7,a51217);
	carry = alpah7>>52;
	alpah7 &= mask52;
	__m512i alpah8 = _mm512_add_epi64(a5128,carry);
	alpah8 = _mm512_add_epi64(alpah8,a51218);
	carry = alpah8>>52;
	alpah8 &= mask52;
	__m512i alpah9 = _mm512_add_epi64(a5129,carry);
	alpah9 = _mm512_add_epi64(alpah9,a51219);
	carry = alpah9>>52;
	alpah9 &= mask52;
	__m512i blpbh0 = _mm512_add_epi64(b5120,b51210);
	carry = blpbh0>>52;
	blpbh0 &= mask52;
	__m512i blpbh1 = _mm512_add_epi64(b5121,carry);
	blpbh1 = _mm512_add_epi64(blpbh1,b51211);
	carry = blpbh1>>52;
	blpbh1 &= mask52;
	__m512i blpbh2 = _mm512_add_epi64(b5122,carry);
	blpbh2 = _mm512_add_epi64(blpbh2,b51212);
	carry = blpbh2>>52;
	blpbh2 &= mask52;
	__m512i blpbh3 = _mm512_add_epi64(b5123,carry);
	blpbh3 = _mm512_add_epi64(blpbh3,b51213);
	carry = blpbh3>>52;
	blpbh3 &= mask52;
	__m512i blpbh4 = _mm512_add_epi64(b5124,carry);
	blpbh4 = _mm512_add_epi64(blpbh4,b51214);
	carry = blpbh4>>52;
	blpbh4 &= mask52;
	__m512i blpbh5 = _mm512_add_epi64(b5125,carry);
	blpbh5 = _mm512_add_epi64(blpbh5,b51215);
	carry = blpbh5>>52;
	blpbh5 &= mask52;
	__m512i blpbh6 = _mm512_add_epi64(b5126,carry);
	blpbh6 = _mm512_add_epi64(blpbh6,b51216);
	carry = blpbh6>>52;
	blpbh6 &= mask52;
	__m512i blpbh7 = _mm512_add_epi64(b5127,carry);
	blpbh7 = _mm512_add_epi64(blpbh7,b51217);
	carry = blpbh7>>52;
	blpbh7 &= mask52;
	__m512i blpbh8 = _mm512_add_epi64(b5128,carry);
	blpbh8 = _mm512_add_epi64(blpbh8,b51218);
	carry = blpbh8>>52;
	blpbh8 &= mask52;
	__m512i blpbh9 = _mm512_add_epi64(b5129,carry);
	blpbh9 = _mm512_add_epi64(blpbh9,b51219);
	carry = blpbh9>>52;
	blpbh9 &= mask52;
	D1_0 = _mm512_madd52lo_epu64(D0_10,alpah0,blpbh0);
	D1_1 = _mm512_madd52hi_epu64(D0_11,alpah0,blpbh0);
	D1_1 = _mm512_madd52lo_epu64(D1_1,alpah0,blpbh1);
	D1_2 = _mm512_madd52hi_epu64(D0_12,alpah0,blpbh1);
	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah0,blpbh2);
	D1_3 = _mm512_madd52hi_epu64(D0_13,alpah0,blpbh2);
	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah0,blpbh3);
	D1_4 = _mm512_madd52hi_epu64(D0_14,alpah0,blpbh3);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah0,blpbh4);
	D1_5 = _mm512_madd52hi_epu64(D0_15,alpah0,blpbh4);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah0,blpbh5);
	D1_6 = _mm512_madd52hi_epu64(D0_16,alpah0,blpbh5);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah0,blpbh6);
	D1_7 = _mm512_madd52hi_epu64(D0_17,alpah0,blpbh6);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah0,blpbh7);
	D1_8 = _mm512_madd52hi_epu64(D0_18,alpah0,blpbh7);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah0,blpbh8);
	D1_9 = _mm512_madd52hi_epu64(D0_19,alpah0,blpbh8);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah0,blpbh9);

	D1_1 = _mm512_madd52lo_epu64(D1_1,alpah1,blpbh0);
	D1_2 = _mm512_madd52hi_epu64(D1_2,alpah1,blpbh0);
	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah1,blpbh1);
	D1_3 = _mm512_madd52hi_epu64(D1_3,alpah1,blpbh1);
	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah1,blpbh2);
	D1_4 = _mm512_madd52hi_epu64(D1_4,alpah1,blpbh2);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah1,blpbh3);
	D1_5 = _mm512_madd52hi_epu64(D1_5,alpah1,blpbh3);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah1,blpbh4);
	D1_6 = _mm512_madd52hi_epu64(D1_6,alpah1,blpbh4);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah1,blpbh5);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah1,blpbh5);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah1,blpbh6);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah1,blpbh6);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah1,blpbh7);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah1,blpbh7);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah1,blpbh8);

	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah2,blpbh0);
	D1_3 = _mm512_madd52hi_epu64(D1_3,alpah2,blpbh0);
	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah2,blpbh1);
	D1_4 = _mm512_madd52hi_epu64(D1_4,alpah2,blpbh1);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah2,blpbh2);
	D1_5 = _mm512_madd52hi_epu64(D1_5,alpah2,blpbh2);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah2,blpbh3);
	D1_6 = _mm512_madd52hi_epu64(D1_6,alpah2,blpbh3);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah2,blpbh4);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah2,blpbh4);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah2,blpbh5);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah2,blpbh5);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah2,blpbh6);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah2,blpbh6);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah2,blpbh7);

	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah3,blpbh0);
	D1_4 = _mm512_madd52hi_epu64(D1_4,alpah3,blpbh0);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah3,blpbh1);
	D1_5 = _mm512_madd52hi_epu64(D1_5,alpah3,blpbh1);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah3,blpbh2);
	D1_6 = _mm512_madd52hi_epu64(D1_6,alpah3,blpbh2);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah3,blpbh3);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah3,blpbh3);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah3,blpbh4);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah3,blpbh4);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah3,blpbh5);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah3,blpbh5);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah3,blpbh6);

	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah4,blpbh0);
	D1_5 = _mm512_madd52hi_epu64(D1_5,alpah4,blpbh0);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah4,blpbh1);
	D1_6 = _mm512_madd52hi_epu64(D1_6,alpah4,blpbh1);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah4,blpbh2);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah4,blpbh2);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah4,blpbh3);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah4,blpbh3);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah4,blpbh4);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah4,blpbh4);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah4,blpbh5);

	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah5,blpbh0);
	D1_6 = _mm512_madd52hi_epu64(D1_6,alpah5,blpbh0);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah5,blpbh1);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah5,blpbh1);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah5,blpbh2);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah5,blpbh2);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah5,blpbh3);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah5,blpbh3);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah5,blpbh4);

	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah6,blpbh0);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah6,blpbh0);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah6,blpbh1);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah6,blpbh1);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah6,blpbh2);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah6,blpbh2);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah6,blpbh3);

	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah7,blpbh0);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah7,blpbh0);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah7,blpbh1);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah7,blpbh1);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah7,blpbh2);

	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah8,blpbh0);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah8,blpbh0);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah8,blpbh1);

	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah9,blpbh0);


	// Carry management

	carry  = _mm512_srli_epi64(D1_0,52);
	D1_0 = _mm512_and_si512(D1_0,mask52);
	D1_1 = _mm512_add_epi64(D1_1,carry);
	carry  = _mm512_srli_epi64(D1_1,52);
	D1_2 = _mm512_add_epi64(D1_2,carry);
	D1_1 = _mm512_and_si512(D1_1,mask52);
	carry  = _mm512_srli_epi64(D1_2,52);
	D1_3 = _mm512_add_epi64(D1_3,carry);
	D1_2 = _mm512_and_si512(D1_2,mask52);
	carry  = _mm512_srli_epi64(D1_3,52);
	D1_4 = _mm512_add_epi64(D1_4,carry);
	D1_3 = _mm512_and_si512(D1_3,mask52);
	carry  = _mm512_srli_epi64(D1_4,52);
	D1_5 = _mm512_add_epi64(D1_5,carry);
	D1_4 = _mm512_and_si512(D1_4,mask52);
	carry  = _mm512_srli_epi64(D1_5,52);
	D1_6 = _mm512_add_epi64(D1_6,carry);
	D1_5 = _mm512_and_si512(D1_5,mask52);
	carry  = _mm512_srli_epi64(D1_6,52);
	D1_7 = _mm512_add_epi64(D1_7,carry);
	D1_6 = _mm512_and_si512(D1_6,mask52);
	carry  = _mm512_srli_epi64(D1_7,52);
	D1_8 = _mm512_add_epi64(D1_8,carry);
	D1_7 = _mm512_and_si512(D1_7,mask52);
	carry  = _mm512_srli_epi64(D1_8,52);
	D1_9 = _mm512_add_epi64(D1_9,carry);
	D1_8 = _mm512_and_si512(D1_8,mask52);

	// Final reconstruction


	// tmp = D0+D2, radix 2^519

	__m512i tmp0 = _mm512_add_epi64(D0_0,D2_0);
	__m512i carry_tmp  = _mm512_srli_epi64(tmp0,52);
	tmp0 = _mm512_and_si512(tmp0,mask52);

	__m512i tmp1 = _mm512_add_epi64(D0_1,carry_tmp);
	tmp1 = _mm512_add_epi64(tmp1,D2_1);
	carry_tmp  = _mm512_srli_epi64(tmp1,52);
	tmp1 = _mm512_and_si512(tmp1,mask52);

	__m512i tmp2 = _mm512_add_epi64(D0_2,carry_tmp);
	tmp2 = _mm512_add_epi64(tmp2,D2_2);
	carry_tmp  = _mm512_srli_epi64(tmp2,52);
	tmp2 = _mm512_and_si512(tmp2,mask52);

	__m512i tmp3 = _mm512_add_epi64(D0_3,carry_tmp);
	tmp3 = _mm512_add_epi64(tmp3,D2_3);
	carry_tmp  = _mm512_srli_epi64(tmp3,52);
	tmp3 = _mm512_and_si512(tmp3,mask52);

	__m512i tmp4 = _mm512_add_epi64(D0_4,carry_tmp);
	tmp4 = _mm512_add_epi64(tmp4,D2_4);
	carry_tmp  = _mm512_srli_epi64(tmp4,52);
	tmp4 = _mm512_and_si512(tmp4,mask52);

	__m512i tmp5 = _mm512_add_epi64(D0_5,carry_tmp);
	tmp5 = _mm512_add_epi64(tmp5,D2_5);
	carry_tmp  = _mm512_srli_epi64(tmp5,52);
	tmp5 = _mm512_and_si512(tmp5,mask52);

	__m512i tmp6 = _mm512_add_epi64(D0_6,carry_tmp);
	tmp6 = _mm512_add_epi64(tmp6,D2_6);
	carry_tmp  = _mm512_srli_epi64(tmp6,52);
	tmp6 = _mm512_and_si512(tmp6,mask52);

	__m512i tmp7 = _mm512_add_epi64(D0_7,carry_tmp);
	tmp7 = _mm512_add_epi64(tmp7,D2_7);
	carry_tmp  = _mm512_srli_epi64(tmp7,52);
	tmp7 = _mm512_and_si512(tmp7,mask52);

	__m512i tmp8 = _mm512_add_epi64(D0_8,carry_tmp);
	tmp8 = _mm512_add_epi64(tmp8,D2_8);
	carry_tmp  = _mm512_srli_epi64(tmp8,52);
	tmp8 = _mm512_and_si512(tmp8,mask52);

	__m512i tmp9 = _mm512_add_epi64(D0_9,carry_tmp);
	tmp9 = _mm512_add_epi64(tmp9,D2_9);
	carry_tmp  = _mm512_srli_epi64(tmp9,51);
	tmp9 = _mm512_and_si512(tmp9,mask51);// radix 2**519


	// D1 = D1 -tmp, radix 2^519

	D1_0 = _mm512_sub_epi64(D1_0,tmp0);
	__m512i borrow = _mm512_srli_epi64(D1_0,52)&un;
	D1_0 = _mm512_and_si512(D1_0,mask52);
	borrow = _mm512_add_epi64(tmp1,borrow);
	D1_1 = _mm512_sub_epi64(D1_1,borrow);
	borrow  = _mm512_srli_epi64(D1_1,52)&un;
	D1_1 = _mm512_and_si512(D1_1,mask52);

	borrow = _mm512_add_epi64(tmp2,borrow);
	D1_2 = _mm512_sub_epi64(D1_2,borrow);
	borrow  = _mm512_srli_epi64(D1_2,52)&un;
	D1_2 = _mm512_and_si512(D1_2,mask52);

	borrow = _mm512_add_epi64(tmp3,borrow);
	D1_3 = _mm512_sub_epi64(D1_3,borrow);
	borrow  = _mm512_srli_epi64(D1_3,52)&un;
	D1_3 = _mm512_and_si512(D1_3,mask52);

	borrow = _mm512_add_epi64(tmp4,borrow);
	D1_4 = _mm512_sub_epi64(D1_4,borrow);
	borrow  = _mm512_srli_epi64(D1_4,52)&un;
	D1_4 = _mm512_and_si512(D1_4,mask52);

	borrow = _mm512_add_epi64(tmp5,borrow);
	D1_5 = _mm512_sub_epi64(D1_5,borrow);
	borrow  = _mm512_srli_epi64(D1_5,52)&un;
	D1_5 = _mm512_and_si512(D1_5,mask52);

	borrow = _mm512_add_epi64(tmp6,borrow);
	D1_6 = _mm512_sub_epi64(D1_6,borrow);
	borrow  = _mm512_srli_epi64(D1_6,52)&un;
	D1_6 = _mm512_and_si512(D1_6,mask52);

	borrow = _mm512_add_epi64(tmp7,borrow);
	D1_7 = _mm512_sub_epi64(D1_7,borrow);
	borrow  = _mm512_srli_epi64(D1_7,52)&un;
	D1_7 = _mm512_and_si512(D1_7,mask52);

	borrow = _mm512_add_epi64(tmp8,borrow);
	D1_8 = _mm512_sub_epi64(D1_8,borrow);
	borrow  = _mm512_srli_epi64(D1_8,52)&un;
	D1_8 = _mm512_and_si512(D1_8,mask52);

	borrow = _mm512_add_epi64(tmp9,borrow);
	D1_9 = _mm512_sub_epi64(D1_9,borrow);
	borrow = _mm512_srli_epi64(D1_9,51)&un;
	D1_9 = _mm512_and_si512(D1_9,mask51);// radix 2**519



	_mm512_store_epi64(out+0,D0_0);
	_mm512_store_epi64(out+1,D0_1);
	_mm512_store_epi64(out+2,D0_2);
	_mm512_store_epi64(out+3,D0_3);
	_mm512_store_epi64(out+4,D0_4);
	_mm512_store_epi64(out+5,D0_5);
	_mm512_store_epi64(out+6,D0_6);
	_mm512_store_epi64(out+7,D0_7);
	_mm512_store_epi64(out+8,D0_8);
	_mm512_store_epi64(out+9,D0_9);
	_mm512_store_epi64(out+10,D1_0);
	_mm512_store_epi64(out+11,D1_1);
	_mm512_store_epi64(out+12,D1_2);
	_mm512_store_epi64(out+13,D1_3);
	_mm512_store_epi64(out+14,D1_4);
	_mm512_store_epi64(out+15,D1_5);
	_mm512_store_epi64(out+16,D1_6);
	_mm512_store_epi64(out+17,D1_7);
	_mm512_store_epi64(out+18,D1_8);
	_mm512_store_epi64(out+19,D1_9);

}

/* Karatsuba multiplication */

inline void force_inline mul512_8_1038K(__m512i out[40], __m512i a512[20], __m512i b512[20])
{

	// D0 = Al*Bl

	__m512i D0_0, D0_1;
	__m512i D0_2, D0_3;
	__m512i D0_4, D0_5;
	__m512i D0_6, D0_7;
	__m512i D0_8, D0_9;
	__m512i D0_10, D0_11;
	__m512i D0_12, D0_13;
	__m512i D0_14, D0_15;
	__m512i D0_16, D0_17;
	__m512i D0_18, D0_19;
	__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512);
	__m512i a5121 = _mm512_load_epi64(a512+1), b5121 = _mm512_load_epi64(b512+1);
	__m512i a5122 = _mm512_load_epi64(a512+2), b5122 = _mm512_load_epi64(b512+2);
	__m512i a5123 = _mm512_load_epi64(a512+3), b5123 = _mm512_load_epi64(b512+3);
	__m512i a5124 = _mm512_load_epi64(a512+4), b5124 = _mm512_load_epi64(b512+4);
	__m512i a5125 = _mm512_load_epi64(a512+5), b5125 = _mm512_load_epi64(b512+5);
	__m512i a5126 = _mm512_load_epi64(a512+6), b5126 = _mm512_load_epi64(b512+6);
	__m512i a5127 = _mm512_load_epi64(a512+7), b5127 = _mm512_load_epi64(b512+7);
	__m512i a5128 = _mm512_load_epi64(a512+8), b5128 = _mm512_load_epi64(b512+8);
	__m512i a5129 = _mm512_load_epi64(a512+9), b5129 = _mm512_load_epi64(b512+9);
	D0_0 = _mm512_madd52lo_epu64(zero,a5120,b5120);
	D0_1 = _mm512_madd52hi_epu64(zero,a5120,b5120);
	D0_1 = _mm512_madd52lo_epu64(D0_1,a5120,b5121);
	D0_2 = _mm512_madd52hi_epu64(zero,a5120,b5121);
	D0_2 = _mm512_madd52lo_epu64(D0_2,a5120,b5122);
	D0_3 = _mm512_madd52hi_epu64(zero,a5120,b5122);
	D0_3 = _mm512_madd52lo_epu64(D0_3,a5120,b5123);
	D0_4 = _mm512_madd52hi_epu64(zero,a5120,b5123);
	D0_4 = _mm512_madd52lo_epu64(D0_4,a5120,b5124);
	D0_5 = _mm512_madd52hi_epu64(zero,a5120,b5124);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5120,b5125);
	D0_6 = _mm512_madd52hi_epu64(zero,a5120,b5125);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5120,b5126);
	D0_7 = _mm512_madd52hi_epu64(zero,a5120,b5126);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5120,b5127);
	D0_8 = _mm512_madd52hi_epu64(zero,a5120,b5127);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5120,b5128);
	D0_9 = _mm512_madd52hi_epu64(zero,a5120,b5128);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5120,b5129);
	D0_10 = _mm512_madd52hi_epu64(zero,a5120,b5129);

	D0_1 = _mm512_madd52lo_epu64(D0_1,a5121,b5120);
	D0_2 = _mm512_madd52hi_epu64(D0_2,a5121,b5120);
	D0_2 = _mm512_madd52lo_epu64(D0_2,a5121,b5121);
	D0_3 = _mm512_madd52hi_epu64(D0_3,a5121,b5121);
	D0_3 = _mm512_madd52lo_epu64(D0_3,a5121,b5122);
	D0_4 = _mm512_madd52hi_epu64(D0_4,a5121,b5122);
	D0_4 = _mm512_madd52lo_epu64(D0_4,a5121,b5123);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5121,b5123);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5121,b5124);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5121,b5124);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5121,b5125);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5121,b5125);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5121,b5126);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5121,b5126);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5121,b5127);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5121,b5127);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5121,b5128);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5121,b5128);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5121,b5129);
	D0_11 = _mm512_madd52hi_epu64(zero,a5121,b5129);

	D0_2 = _mm512_madd52lo_epu64(D0_2,a5122,b5120);
	D0_3 = _mm512_madd52hi_epu64(D0_3,a5122,b5120);
	D0_3 = _mm512_madd52lo_epu64(D0_3,a5122,b5121);
	D0_4 = _mm512_madd52hi_epu64(D0_4,a5122,b5121);
	D0_4 = _mm512_madd52lo_epu64(D0_4,a5122,b5122);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5122,b5122);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5122,b5123);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5122,b5123);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5122,b5124);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5122,b5124);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5122,b5125);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5122,b5125);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5122,b5126);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5122,b5126);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5122,b5127);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5122,b5127);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5122,b5128);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5122,b5128);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5122,b5129);
	D0_12 = _mm512_madd52hi_epu64(zero,a5122,b5129);

	D0_3 = _mm512_madd52lo_epu64(D0_3,a5123,b5120);
	D0_4 = _mm512_madd52hi_epu64(D0_4,a5123,b5120);
	D0_4 = _mm512_madd52lo_epu64(D0_4,a5123,b5121);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5123,b5121);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5123,b5122);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5123,b5122);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5123,b5123);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5123,b5123);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5123,b5124);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5123,b5124);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5123,b5125);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5123,b5125);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5123,b5126);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5123,b5126);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5123,b5127);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5123,b5127);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5123,b5128);
	D0_12 = _mm512_madd52hi_epu64(D0_12,a5123,b5128);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5123,b5129);
	D0_13 = _mm512_madd52hi_epu64(zero,a5123,b5129);

	D0_4 = _mm512_madd52lo_epu64(D0_4,a5124,b5120);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5124,b5120);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5124,b5121);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5124,b5121);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5124,b5122);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5124,b5122);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5124,b5123);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5124,b5123);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5124,b5124);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5124,b5124);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5124,b5125);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5124,b5125);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5124,b5126);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5124,b5126);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5124,b5127);
	D0_12 = _mm512_madd52hi_epu64(D0_12,a5124,b5127);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5124,b5128);
	D0_13 = _mm512_madd52hi_epu64(D0_13,a5124,b5128);
	D0_13 = _mm512_madd52lo_epu64(D0_13,a5124,b5129);
	D0_14 = _mm512_madd52hi_epu64(zero,a5124,b5129);

	D0_5 = _mm512_madd52lo_epu64(D0_5,a5125,b5120);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5125,b5120);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5125,b5121);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5125,b5121);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5125,b5122);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5125,b5122);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5125,b5123);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5125,b5123);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5125,b5124);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5125,b5124);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5125,b5125);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5125,b5125);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5125,b5126);
	D0_12 = _mm512_madd52hi_epu64(D0_12,a5125,b5126);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5125,b5127);
	D0_13 = _mm512_madd52hi_epu64(D0_13,a5125,b5127);
	D0_13 = _mm512_madd52lo_epu64(D0_13,a5125,b5128);
	D0_14 = _mm512_madd52hi_epu64(D0_14,a5125,b5128);
	D0_14 = _mm512_madd52lo_epu64(D0_14,a5125,b5129);
	D0_15 = _mm512_madd52hi_epu64(zero,a5125,b5129);

	D0_6 = _mm512_madd52lo_epu64(D0_6,a5126,b5120);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5126,b5120);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5126,b5121);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5126,b5121);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5126,b5122);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5126,b5122);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5126,b5123);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5126,b5123);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5126,b5124);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5126,b5124);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5126,b5125);
	D0_12 = _mm512_madd52hi_epu64(D0_12,a5126,b5125);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5126,b5126);
	D0_13 = _mm512_madd52hi_epu64(D0_13,a5126,b5126);
	D0_13 = _mm512_madd52lo_epu64(D0_13,a5126,b5127);
	D0_14 = _mm512_madd52hi_epu64(D0_14,a5126,b5127);
	D0_14 = _mm512_madd52lo_epu64(D0_14,a5126,b5128);
	D0_15 = _mm512_madd52hi_epu64(D0_15,a5126,b5128);
	D0_15 = _mm512_madd52lo_epu64(D0_15,a5126,b5129);
	D0_16 = _mm512_madd52hi_epu64(zero,a5126,b5129);

	D0_7 = _mm512_madd52lo_epu64(D0_7,a5127,b5120);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5127,b5120);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5127,b5121);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5127,b5121);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5127,b5122);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5127,b5122);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5127,b5123);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5127,b5123);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5127,b5124);
	D0_12 = _mm512_madd52hi_epu64(D0_12,a5127,b5124);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5127,b5125);
	D0_13 = _mm512_madd52hi_epu64(D0_13,a5127,b5125);
	D0_13 = _mm512_madd52lo_epu64(D0_13,a5127,b5126);
	D0_14 = _mm512_madd52hi_epu64(D0_14,a5127,b5126);
	D0_14 = _mm512_madd52lo_epu64(D0_14,a5127,b5127);
	D0_15 = _mm512_madd52hi_epu64(D0_15,a5127,b5127);
	D0_15 = _mm512_madd52lo_epu64(D0_15,a5127,b5128);
	D0_16 = _mm512_madd52hi_epu64(D0_16,a5127,b5128);
	D0_16 = _mm512_madd52lo_epu64(D0_16,a5127,b5129);
	D0_17 = _mm512_madd52hi_epu64(zero,a5127,b5129);

	D0_8 = _mm512_madd52lo_epu64(D0_8,a5128,b5120);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5128,b5120);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5128,b5121);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5128,b5121);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5128,b5122);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5128,b5122);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5128,b5123);
	D0_12 = _mm512_madd52hi_epu64(D0_12,a5128,b5123);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5128,b5124);
	D0_13 = _mm512_madd52hi_epu64(D0_13,a5128,b5124);
	D0_13 = _mm512_madd52lo_epu64(D0_13,a5128,b5125);
	D0_14 = _mm512_madd52hi_epu64(D0_14,a5128,b5125);
	D0_14 = _mm512_madd52lo_epu64(D0_14,a5128,b5126);
	D0_15 = _mm512_madd52hi_epu64(D0_15,a5128,b5126);
	D0_15 = _mm512_madd52lo_epu64(D0_15,a5128,b5127);
	D0_16 = _mm512_madd52hi_epu64(D0_16,a5128,b5127);
	D0_16 = _mm512_madd52lo_epu64(D0_16,a5128,b5128);
	D0_17 = _mm512_madd52hi_epu64(D0_17,a5128,b5128);
	D0_17 = _mm512_madd52lo_epu64(D0_17,a5128,b5129);
	D0_18 = _mm512_madd52hi_epu64(zero,a5128,b5129);

	D0_9 = _mm512_madd52lo_epu64(D0_9,a5129,b5120);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5129,b5120);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5129,b5121);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5129,b5121);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5129,b5122);
	D0_12 = _mm512_madd52hi_epu64(D0_12,a5129,b5122);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5129,b5123);
	D0_13 = _mm512_madd52hi_epu64(D0_13,a5129,b5123);
	D0_13 = _mm512_madd52lo_epu64(D0_13,a5129,b5124);
	D0_14 = _mm512_madd52hi_epu64(D0_14,a5129,b5124);
	D0_14 = _mm512_madd52lo_epu64(D0_14,a5129,b5125);
	D0_15 = _mm512_madd52hi_epu64(D0_15,a5129,b5125);
	D0_15 = _mm512_madd52lo_epu64(D0_15,a5129,b5126);
	D0_16 = _mm512_madd52hi_epu64(D0_16,a5129,b5126);
	D0_16 = _mm512_madd52lo_epu64(D0_16,a5129,b5127);
	D0_17 = _mm512_madd52hi_epu64(D0_17,a5129,b5127);
	D0_17 = _mm512_madd52lo_epu64(D0_17,a5129,b5128);
	D0_18 = _mm512_madd52hi_epu64(D0_18,a5129,b5128);
	D0_18 = _mm512_madd52lo_epu64(D0_18,a5129,b5129);
	D0_19 = _mm512_madd52hi_epu64(zero,a5129,b5129);


	// Carry management

	__m512i carry  = _mm512_srli_epi64(D0_1,52);
	D0_2 = _mm512_add_epi64(D0_2,carry);
	D0_1 = _mm512_and_si512(D0_1,mask52);
	carry  = _mm512_srli_epi64(D0_2,52);
	D0_3 = _mm512_add_epi64(D0_3,carry);
	D0_2 = _mm512_and_si512(D0_2,mask52);
	carry  = _mm512_srli_epi64(D0_3,52);
	D0_4 = _mm512_add_epi64(D0_4,carry);
	D0_3 = _mm512_and_si512(D0_3,mask52);
	carry  = _mm512_srli_epi64(D0_4,52);
	D0_5 = _mm512_add_epi64(D0_5,carry);
	D0_4 = _mm512_and_si512(D0_4,mask52);
	carry  = _mm512_srli_epi64(D0_5,52);
	D0_6 = _mm512_add_epi64(D0_6,carry);
	D0_5 = _mm512_and_si512(D0_5,mask52);
	carry  = _mm512_srli_epi64(D0_6,52);
	D0_7 = _mm512_add_epi64(D0_7,carry);
	D0_6 = _mm512_and_si512(D0_6,mask52);
	carry  = _mm512_srli_epi64(D0_7,52);
	D0_8 = _mm512_add_epi64(D0_8,carry);
	D0_7 = _mm512_and_si512(D0_7,mask52);
	carry  = _mm512_srli_epi64(D0_8,52);
	D0_9 = _mm512_add_epi64(D0_9,carry);
	D0_8 = _mm512_and_si512(D0_8,mask52);
	carry  = _mm512_srli_epi64(D0_9,52);
	D0_10 = _mm512_add_epi64(D0_10,carry);
	D0_9 = _mm512_and_si512(D0_9,mask52);
	carry  = _mm512_srli_epi64(D0_10,52);
	D0_11 = _mm512_add_epi64(D0_11,carry);
	D0_10 = _mm512_and_si512(D0_10,mask52);
	carry  = _mm512_srli_epi64(D0_11,52);
	D0_12 = _mm512_add_epi64(D0_12,carry);
	D0_11 = _mm512_and_si512(D0_11,mask52);
	carry  = _mm512_srli_epi64(D0_12,52);
	D0_13 = _mm512_add_epi64(D0_13,carry);
	D0_12 = _mm512_and_si512(D0_12,mask52);
	carry  = _mm512_srli_epi64(D0_13,52);
	D0_14 = _mm512_add_epi64(D0_14,carry);
	D0_13 = _mm512_and_si512(D0_13,mask52);
	carry  = _mm512_srli_epi64(D0_14,52);
	D0_15 = _mm512_add_epi64(D0_15,carry);
	D0_14 = _mm512_and_si512(D0_14,mask52);
	carry  = _mm512_srli_epi64(D0_15,52);
	D0_16 = _mm512_add_epi64(D0_16,carry);
	D0_15 = _mm512_and_si512(D0_15,mask52);
	carry  = _mm512_srli_epi64(D0_16,52);
	D0_17 = _mm512_add_epi64(D0_17,carry);
	D0_16 = _mm512_and_si512(D0_16,mask52);
	carry  = _mm512_srli_epi64(D0_17,52);
	D0_18 = _mm512_add_epi64(D0_18,carry);
	D0_17 = _mm512_and_si512(D0_17,mask52);
	carry  = _mm512_srli_epi64(D0_18,52);
	D0_19 = _mm512_add_epi64(D0_19,carry);
	D0_18 = _mm512_and_si512(D0_18,mask52);

	// Conversion in base 2^519

	carry = D0_9>>51;
	D0_10 = (D0_10<<1)|carry;
	D0_9 &= mask51;
	carry = D0_10>>52;
	D0_11 = (D0_11<<1)|carry;
	D0_10 &= mask52;
	carry = D0_11>>52;
	D0_12 = (D0_12<<1)|carry;
	D0_11 &= mask52;
	carry = D0_12>>52;
	D0_13 = (D0_13<<1)|carry;
	D0_12 &= mask52;
	carry = D0_13>>52;
	D0_14 = (D0_14<<1)|carry;
	D0_13 &= mask52;
	carry = D0_14>>52;
	D0_15 = (D0_15<<1)|carry;
	D0_14 &= mask52;
	carry = D0_15>>52;
	D0_16 = (D0_16<<1)|carry;
	D0_15 &= mask52;
	carry = D0_16>>52;
	D0_17 = (D0_17<<1)|carry;
	D0_16 &= mask52;
	carry = D0_17>>52;
	D0_18 = (D0_18<<1)|carry;
	D0_17 &= mask52;
	carry = D0_18>>52;
	D0_19 = (D0_19<<1)|carry;
	D0_18 &= mask52;

	// D2 = Ah*Bh

	__m512i D2_0, D2_1;
	__m512i D2_2, D2_3;
	__m512i D2_4, D2_5;
	__m512i D2_6, D2_7;
	__m512i D2_8, D2_9;
	__m512i D2_10, D2_11;
	__m512i D2_12, D2_13;
	__m512i D2_14, D2_15;
	__m512i D2_16, D2_17;
	__m512i D2_18, D2_19;
	__m512i a51210 = _mm512_load_epi64(a512+10), b51210 = _mm512_load_epi64(b512+10);
	__m512i a51211 = _mm512_load_epi64(a512+11), b51211 = _mm512_load_epi64(b512+11);
	__m512i a51212 = _mm512_load_epi64(a512+12), b51212 = _mm512_load_epi64(b512+12);
	__m512i a51213 = _mm512_load_epi64(a512+13), b51213 = _mm512_load_epi64(b512+13);
	__m512i a51214 = _mm512_load_epi64(a512+14), b51214 = _mm512_load_epi64(b512+14);
	__m512i a51215 = _mm512_load_epi64(a512+15), b51215 = _mm512_load_epi64(b512+15);
	__m512i a51216 = _mm512_load_epi64(a512+16), b51216 = _mm512_load_epi64(b512+16);
	__m512i a51217 = _mm512_load_epi64(a512+17), b51217 = _mm512_load_epi64(b512+17);
	__m512i a51218 = _mm512_load_epi64(a512+18), b51218 = _mm512_load_epi64(b512+18);
	__m512i a51219 = _mm512_load_epi64(a512+19), b51219 = _mm512_load_epi64(b512+19);
	D2_0 = _mm512_madd52lo_epu64(zero,a51210,b51210);
	D2_1 = _mm512_madd52hi_epu64(zero,a51210,b51210);
	D2_1 = _mm512_madd52lo_epu64(D2_1,a51210,b51211);
	D2_2 = _mm512_madd52hi_epu64(zero,a51210,b51211);
	D2_2 = _mm512_madd52lo_epu64(D2_2,a51210,b51212);
	D2_3 = _mm512_madd52hi_epu64(zero,a51210,b51212);
	D2_3 = _mm512_madd52lo_epu64(D2_3,a51210,b51213);
	D2_4 = _mm512_madd52hi_epu64(zero,a51210,b51213);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a51210,b51214);
	D2_5 = _mm512_madd52hi_epu64(zero,a51210,b51214);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a51210,b51215);
	D2_6 = _mm512_madd52hi_epu64(zero,a51210,b51215);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a51210,b51216);
	D2_7 = _mm512_madd52hi_epu64(zero,a51210,b51216);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51210,b51217);
	D2_8 = _mm512_madd52hi_epu64(zero,a51210,b51217);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51210,b51218);
	D2_9 = _mm512_madd52hi_epu64(zero,a51210,b51218);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51210,b51219);
	D2_10 = _mm512_madd52hi_epu64(zero,a51210,b51219);

	D2_1 = _mm512_madd52lo_epu64(D2_1,a51211,b51210);
	D2_2 = _mm512_madd52hi_epu64(D2_2,a51211,b51210);
	D2_2 = _mm512_madd52lo_epu64(D2_2,a51211,b51211);
	D2_3 = _mm512_madd52hi_epu64(D2_3,a51211,b51211);
	D2_3 = _mm512_madd52lo_epu64(D2_3,a51211,b51212);
	D2_4 = _mm512_madd52hi_epu64(D2_4,a51211,b51212);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a51211,b51213);
	D2_5 = _mm512_madd52hi_epu64(D2_5,a51211,b51213);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a51211,b51214);
	D2_6 = _mm512_madd52hi_epu64(D2_6,a51211,b51214);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a51211,b51215);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a51211,b51215);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51211,b51216);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a51211,b51216);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51211,b51217);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51211,b51217);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51211,b51218);
	D2_10 = _mm512_madd52hi_epu64(D2_10,a51211,b51218);
	D2_10 = _mm512_madd52lo_epu64(D2_10,a51211,b51219);
	D2_11 = _mm512_madd52hi_epu64(zero,a51211,b51219);

	D2_2 = _mm512_madd52lo_epu64(D2_2,a51212,b51210);
	D2_3 = _mm512_madd52hi_epu64(D2_3,a51212,b51210);
	D2_3 = _mm512_madd52lo_epu64(D2_3,a51212,b51211);
	D2_4 = _mm512_madd52hi_epu64(D2_4,a51212,b51211);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a51212,b51212);
	D2_5 = _mm512_madd52hi_epu64(D2_5,a51212,b51212);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a51212,b51213);
	D2_6 = _mm512_madd52hi_epu64(D2_6,a51212,b51213);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a51212,b51214);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a51212,b51214);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51212,b51215);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a51212,b51215);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51212,b51216);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51212,b51216);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51212,b51217);
	D2_10 = _mm512_madd52hi_epu64(D2_10,a51212,b51217);
	D2_10 = _mm512_madd52lo_epu64(D2_10,a51212,b51218);
	D2_11 = _mm512_madd52hi_epu64(D2_11,a51212,b51218);
	D2_11 = _mm512_madd52lo_epu64(D2_11,a51212,b51219);
	D2_12 = _mm512_madd52hi_epu64(zero,a51212,b51219);

	D2_3 = _mm512_madd52lo_epu64(D2_3,a51213,b51210);
	D2_4 = _mm512_madd52hi_epu64(D2_4,a51213,b51210);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a51213,b51211);
	D2_5 = _mm512_madd52hi_epu64(D2_5,a51213,b51211);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a51213,b51212);
	D2_6 = _mm512_madd52hi_epu64(D2_6,a51213,b51212);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a51213,b51213);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a51213,b51213);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51213,b51214);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a51213,b51214);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51213,b51215);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51213,b51215);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51213,b51216);
	D2_10 = _mm512_madd52hi_epu64(D2_10,a51213,b51216);
	D2_10 = _mm512_madd52lo_epu64(D2_10,a51213,b51217);
	D2_11 = _mm512_madd52hi_epu64(D2_11,a51213,b51217);
	D2_11 = _mm512_madd52lo_epu64(D2_11,a51213,b51218);
	D2_12 = _mm512_madd52hi_epu64(D2_12,a51213,b51218);
	D2_12 = _mm512_madd52lo_epu64(D2_12,a51213,b51219);
	D2_13 = _mm512_madd52hi_epu64(zero,a51213,b51219);

	D2_4 = _mm512_madd52lo_epu64(D2_4,a51214,b51210);
	D2_5 = _mm512_madd52hi_epu64(D2_5,a51214,b51210);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a51214,b51211);
	D2_6 = _mm512_madd52hi_epu64(D2_6,a51214,b51211);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a51214,b51212);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a51214,b51212);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51214,b51213);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a51214,b51213);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51214,b51214);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51214,b51214);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51214,b51215);
	D2_10 = _mm512_madd52hi_epu64(D2_10,a51214,b51215);
	D2_10 = _mm512_madd52lo_epu64(D2_10,a51214,b51216);
	D2_11 = _mm512_madd52hi_epu64(D2_11,a51214,b51216);
	D2_11 = _mm512_madd52lo_epu64(D2_11,a51214,b51217);
	D2_12 = _mm512_madd52hi_epu64(D2_12,a51214,b51217);
	D2_12 = _mm512_madd52lo_epu64(D2_12,a51214,b51218);
	D2_13 = _mm512_madd52hi_epu64(D2_13,a51214,b51218);
	D2_13 = _mm512_madd52lo_epu64(D2_13,a51214,b51219);
	D2_14 = _mm512_madd52hi_epu64(zero,a51214,b51219);

	D2_5 = _mm512_madd52lo_epu64(D2_5,a51215,b51210);
	D2_6 = _mm512_madd52hi_epu64(D2_6,a51215,b51210);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a51215,b51211);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a51215,b51211);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51215,b51212);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a51215,b51212);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51215,b51213);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51215,b51213);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51215,b51214);
	D2_10 = _mm512_madd52hi_epu64(D2_10,a51215,b51214);
	D2_10 = _mm512_madd52lo_epu64(D2_10,a51215,b51215);
	D2_11 = _mm512_madd52hi_epu64(D2_11,a51215,b51215);
	D2_11 = _mm512_madd52lo_epu64(D2_11,a51215,b51216);
	D2_12 = _mm512_madd52hi_epu64(D2_12,a51215,b51216);
	D2_12 = _mm512_madd52lo_epu64(D2_12,a51215,b51217);
	D2_13 = _mm512_madd52hi_epu64(D2_13,a51215,b51217);
	D2_13 = _mm512_madd52lo_epu64(D2_13,a51215,b51218);
	D2_14 = _mm512_madd52hi_epu64(D2_14,a51215,b51218);
	D2_14 = _mm512_madd52lo_epu64(D2_14,a51215,b51219);
	D2_15 = _mm512_madd52hi_epu64(zero,a51215,b51219);

	D2_6 = _mm512_madd52lo_epu64(D2_6,a51216,b51210);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a51216,b51210);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51216,b51211);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a51216,b51211);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51216,b51212);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51216,b51212);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51216,b51213);
	D2_10 = _mm512_madd52hi_epu64(D2_10,a51216,b51213);
	D2_10 = _mm512_madd52lo_epu64(D2_10,a51216,b51214);
	D2_11 = _mm512_madd52hi_epu64(D2_11,a51216,b51214);
	D2_11 = _mm512_madd52lo_epu64(D2_11,a51216,b51215);
	D2_12 = _mm512_madd52hi_epu64(D2_12,a51216,b51215);
	D2_12 = _mm512_madd52lo_epu64(D2_12,a51216,b51216);
	D2_13 = _mm512_madd52hi_epu64(D2_13,a51216,b51216);
	D2_13 = _mm512_madd52lo_epu64(D2_13,a51216,b51217);
	D2_14 = _mm512_madd52hi_epu64(D2_14,a51216,b51217);
	D2_14 = _mm512_madd52lo_epu64(D2_14,a51216,b51218);
	D2_15 = _mm512_madd52hi_epu64(D2_15,a51216,b51218);
	D2_15 = _mm512_madd52lo_epu64(D2_15,a51216,b51219);
	D2_16 = _mm512_madd52hi_epu64(zero,a51216,b51219);

	D2_7 = _mm512_madd52lo_epu64(D2_7,a51217,b51210);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a51217,b51210);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51217,b51211);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51217,b51211);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51217,b51212);
	D2_10 = _mm512_madd52hi_epu64(D2_10,a51217,b51212);
	D2_10 = _mm512_madd52lo_epu64(D2_10,a51217,b51213);
	D2_11 = _mm512_madd52hi_epu64(D2_11,a51217,b51213);
	D2_11 = _mm512_madd52lo_epu64(D2_11,a51217,b51214);
	D2_12 = _mm512_madd52hi_epu64(D2_12,a51217,b51214);
	D2_12 = _mm512_madd52lo_epu64(D2_12,a51217,b51215);
	D2_13 = _mm512_madd52hi_epu64(D2_13,a51217,b51215);
	D2_13 = _mm512_madd52lo_epu64(D2_13,a51217,b51216);
	D2_14 = _mm512_madd52hi_epu64(D2_14,a51217,b51216);
	D2_14 = _mm512_madd52lo_epu64(D2_14,a51217,b51217);
	D2_15 = _mm512_madd52hi_epu64(D2_15,a51217,b51217);
	D2_15 = _mm512_madd52lo_epu64(D2_15,a51217,b51218);
	D2_16 = _mm512_madd52hi_epu64(D2_16,a51217,b51218);
	D2_16 = _mm512_madd52lo_epu64(D2_16,a51217,b51219);
	D2_17 = _mm512_madd52hi_epu64(zero,a51217,b51219);

	D2_8 = _mm512_madd52lo_epu64(D2_8,a51218,b51210);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51218,b51210);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51218,b51211);
	D2_10 = _mm512_madd52hi_epu64(D2_10,a51218,b51211);
	D2_10 = _mm512_madd52lo_epu64(D2_10,a51218,b51212);
	D2_11 = _mm512_madd52hi_epu64(D2_11,a51218,b51212);
	D2_11 = _mm512_madd52lo_epu64(D2_11,a51218,b51213);
	D2_12 = _mm512_madd52hi_epu64(D2_12,a51218,b51213);
	D2_12 = _mm512_madd52lo_epu64(D2_12,a51218,b51214);
	D2_13 = _mm512_madd52hi_epu64(D2_13,a51218,b51214);
	D2_13 = _mm512_madd52lo_epu64(D2_13,a51218,b51215);
	D2_14 = _mm512_madd52hi_epu64(D2_14,a51218,b51215);
	D2_14 = _mm512_madd52lo_epu64(D2_14,a51218,b51216);
	D2_15 = _mm512_madd52hi_epu64(D2_15,a51218,b51216);
	D2_15 = _mm512_madd52lo_epu64(D2_15,a51218,b51217);
	D2_16 = _mm512_madd52hi_epu64(D2_16,a51218,b51217);
	D2_16 = _mm512_madd52lo_epu64(D2_16,a51218,b51218);
	D2_17 = _mm512_madd52hi_epu64(D2_17,a51218,b51218);
	D2_17 = _mm512_madd52lo_epu64(D2_17,a51218,b51219);
	D2_18 = _mm512_madd52hi_epu64(zero,a51218,b51219);

	D2_9 = _mm512_madd52lo_epu64(D2_9,a51219,b51210);
	D2_10 = _mm512_madd52hi_epu64(D2_10,a51219,b51210);
	D2_10 = _mm512_madd52lo_epu64(D2_10,a51219,b51211);
	D2_11 = _mm512_madd52hi_epu64(D2_11,a51219,b51211);
	D2_11 = _mm512_madd52lo_epu64(D2_11,a51219,b51212);
	D2_12 = _mm512_madd52hi_epu64(D2_12,a51219,b51212);
	D2_12 = _mm512_madd52lo_epu64(D2_12,a51219,b51213);
	D2_13 = _mm512_madd52hi_epu64(D2_13,a51219,b51213);
	D2_13 = _mm512_madd52lo_epu64(D2_13,a51219,b51214);
	D2_14 = _mm512_madd52hi_epu64(D2_14,a51219,b51214);
	D2_14 = _mm512_madd52lo_epu64(D2_14,a51219,b51215);
	D2_15 = _mm512_madd52hi_epu64(D2_15,a51219,b51215);
	D2_15 = _mm512_madd52lo_epu64(D2_15,a51219,b51216);
	D2_16 = _mm512_madd52hi_epu64(D2_16,a51219,b51216);
	D2_16 = _mm512_madd52lo_epu64(D2_16,a51219,b51217);
	D2_17 = _mm512_madd52hi_epu64(D2_17,a51219,b51217);
	D2_17 = _mm512_madd52lo_epu64(D2_17,a51219,b51218);
	D2_18 = _mm512_madd52hi_epu64(D2_18,a51219,b51218);
	D2_18 = _mm512_madd52lo_epu64(D2_18,a51219,b51219);
	D2_19 = _mm512_madd52hi_epu64(zero,a51219,b51219);


	// Carry management

	carry  = _mm512_srli_epi64(D2_1,52);
	D2_2 = _mm512_add_epi64(D2_2,carry);
	D2_1 = _mm512_and_si512(D2_1,mask52);
	carry  = _mm512_srli_epi64(D2_2,52);
	D2_3 = _mm512_add_epi64(D2_3,carry);
	D2_2 = _mm512_and_si512(D2_2,mask52);
	carry  = _mm512_srli_epi64(D2_3,52);
	D2_4 = _mm512_add_epi64(D2_4,carry);
	D2_3 = _mm512_and_si512(D2_3,mask52);
	carry  = _mm512_srli_epi64(D2_4,52);
	D2_5 = _mm512_add_epi64(D2_5,carry);
	D2_4 = _mm512_and_si512(D2_4,mask52);
	carry  = _mm512_srli_epi64(D2_5,52);
	D2_6 = _mm512_add_epi64(D2_6,carry);
	D2_5 = _mm512_and_si512(D2_5,mask52);
	carry  = _mm512_srli_epi64(D2_6,52);
	D2_7 = _mm512_add_epi64(D2_7,carry);
	D2_6 = _mm512_and_si512(D2_6,mask52);
	carry  = _mm512_srli_epi64(D2_7,52);
	D2_8 = _mm512_add_epi64(D2_8,carry);
	D2_7 = _mm512_and_si512(D2_7,mask52);
	carry  = _mm512_srli_epi64(D2_8,52);
	D2_9 = _mm512_add_epi64(D2_9,carry);
	D2_8 = _mm512_and_si512(D2_8,mask52);
	carry  = _mm512_srli_epi64(D2_9,52);
	D2_10 = _mm512_add_epi64(D2_10,carry);
	D2_9 = _mm512_and_si512(D2_9,mask52);
	carry  = _mm512_srli_epi64(D2_10,52);
	D2_11 = _mm512_add_epi64(D2_11,carry);
	D2_10 = _mm512_and_si512(D2_10,mask52);
	carry  = _mm512_srli_epi64(D2_11,52);
	D2_12 = _mm512_add_epi64(D2_12,carry);
	D2_11 = _mm512_and_si512(D2_11,mask52);
	carry  = _mm512_srli_epi64(D2_12,52);
	D2_13 = _mm512_add_epi64(D2_13,carry);
	D2_12 = _mm512_and_si512(D2_12,mask52);
	carry  = _mm512_srli_epi64(D2_13,52);
	D2_14 = _mm512_add_epi64(D2_14,carry);
	D2_13 = _mm512_and_si512(D2_13,mask52);
	carry  = _mm512_srli_epi64(D2_14,52);
	D2_15 = _mm512_add_epi64(D2_15,carry);
	D2_14 = _mm512_and_si512(D2_14,mask52);
	carry  = _mm512_srli_epi64(D2_15,52);
	D2_16 = _mm512_add_epi64(D2_16,carry);
	D2_15 = _mm512_and_si512(D2_15,mask52);
	carry  = _mm512_srli_epi64(D2_16,52);
	D2_17 = _mm512_add_epi64(D2_17,carry);
	D2_16 = _mm512_and_si512(D2_16,mask52);
	carry  = _mm512_srli_epi64(D2_17,52);
	D2_18 = _mm512_add_epi64(D2_18,carry);
	D2_17 = _mm512_and_si512(D2_17,mask52);
	carry  = _mm512_srli_epi64(D2_18,52);
	D2_19 = _mm512_add_epi64(D2_19,carry);
	D2_18 = _mm512_and_si512(D2_18,mask52);

	// Conversion in base 2^519

	carry = D2_9>>51;
	D2_10 = (D2_10<<1)|carry;
	D2_9 &= mask51;
	carry = D2_10>>52;
	D2_11 = (D2_11<<1)|carry;
	D2_10 &= mask52;
	carry = D2_11>>52;
	D2_12 = (D2_12<<1)|carry;
	D2_11 &= mask52;
	carry = D2_12>>52;
	D2_13 = (D2_13<<1)|carry;
	D2_12 &= mask52;
	carry = D2_13>>52;
	D2_14 = (D2_14<<1)|carry;
	D2_13 &= mask52;
	carry = D2_14>>52;
	D2_15 = (D2_15<<1)|carry;
	D2_14 &= mask52;
	carry = D2_15>>52;
	D2_16 = (D2_16<<1)|carry;
	D2_15 &= mask52;
	carry = D2_16>>52;
	D2_17 = (D2_17<<1)|carry;
	D2_16 &= mask52;
	carry = D2_17>>52;
	D2_18 = (D2_18<<1)|carry;
	D2_17 &= mask52;
	carry = D2_18>>52;
	D2_19 = (D2_19<<1)|carry;
	D2_18 &= mask52;

	// D1 = (Al+Ah)*(Bl+Bh)

	__m512i D1_0, D1_1;
	__m512i D1_2, D1_3;
	__m512i D1_4, D1_5;
	__m512i D1_6, D1_7;
	__m512i D1_8, D1_9;
	__m512i D1_10, D1_11;
	__m512i D1_12, D1_13;
	__m512i D1_14, D1_15;
	__m512i D1_16, D1_17;
	__m512i D1_18, D1_19;

	__m512i alpah0 = _mm512_add_epi64(a5120,a51210);
	carry = alpah0>>52;
	alpah0 &= mask52;
	__m512i alpah1 = _mm512_add_epi64(a5121,carry);
	alpah1 = _mm512_add_epi64(alpah1,a51211);
	carry = alpah1>>52;
	alpah1 &= mask52;
	__m512i alpah2 = _mm512_add_epi64(a5122,carry);
	alpah2 = _mm512_add_epi64(alpah2,a51212);
	carry = alpah2>>52;
	alpah2 &= mask52;
	__m512i alpah3 = _mm512_add_epi64(a5123,carry);
	alpah3 = _mm512_add_epi64(alpah3,a51213);
	carry = alpah3>>52;
	alpah3 &= mask52;
	__m512i alpah4 = _mm512_add_epi64(a5124,carry);
	alpah4 = _mm512_add_epi64(alpah4,a51214);
	carry = alpah4>>52;
	alpah4 &= mask52;
	__m512i alpah5 = _mm512_add_epi64(a5125,carry);
	alpah5 = _mm512_add_epi64(alpah5,a51215);
	carry = alpah5>>52;
	alpah5 &= mask52;
	__m512i alpah6 = _mm512_add_epi64(a5126,carry);
	alpah6 = _mm512_add_epi64(alpah6,a51216);
	carry = alpah6>>52;
	alpah6 &= mask52;
	__m512i alpah7 = _mm512_add_epi64(a5127,carry);
	alpah7 = _mm512_add_epi64(alpah7,a51217);
	carry = alpah7>>52;
	alpah7 &= mask52;
	__m512i alpah8 = _mm512_add_epi64(a5128,carry);
	alpah8 = _mm512_add_epi64(alpah8,a51218);
	carry = alpah8>>52;
	alpah8 &= mask52;
	__m512i alpah9 = _mm512_add_epi64(a5129,carry);
	alpah9 = _mm512_add_epi64(alpah9,a51219);
	carry = alpah9>>52;
	alpah9 &= mask52;
	__m512i blpbh0 = _mm512_add_epi64(b5120,b51210);
	carry = blpbh0>>52;
	blpbh0 &= mask52;
	__m512i blpbh1 = _mm512_add_epi64(b5121,carry);
	blpbh1 = _mm512_add_epi64(blpbh1,b51211);
	carry = blpbh1>>52;
	blpbh1 &= mask52;
	__m512i blpbh2 = _mm512_add_epi64(b5122,carry);
	blpbh2 = _mm512_add_epi64(blpbh2,b51212);
	carry = blpbh2>>52;
	blpbh2 &= mask52;
	__m512i blpbh3 = _mm512_add_epi64(b5123,carry);
	blpbh3 = _mm512_add_epi64(blpbh3,b51213);
	carry = blpbh3>>52;
	blpbh3 &= mask52;
	__m512i blpbh4 = _mm512_add_epi64(b5124,carry);
	blpbh4 = _mm512_add_epi64(blpbh4,b51214);
	carry = blpbh4>>52;
	blpbh4 &= mask52;
	__m512i blpbh5 = _mm512_add_epi64(b5125,carry);
	blpbh5 = _mm512_add_epi64(blpbh5,b51215);
	carry = blpbh5>>52;
	blpbh5 &= mask52;
	__m512i blpbh6 = _mm512_add_epi64(b5126,carry);
	blpbh6 = _mm512_add_epi64(blpbh6,b51216);
	carry = blpbh6>>52;
	blpbh6 &= mask52;
	__m512i blpbh7 = _mm512_add_epi64(b5127,carry);
	blpbh7 = _mm512_add_epi64(blpbh7,b51217);
	carry = blpbh7>>52;
	blpbh7 &= mask52;
	__m512i blpbh8 = _mm512_add_epi64(b5128,carry);
	blpbh8 = _mm512_add_epi64(blpbh8,b51218);
	carry = blpbh8>>52;
	blpbh8 &= mask52;
	__m512i blpbh9 = _mm512_add_epi64(b5129,carry);
	blpbh9 = _mm512_add_epi64(blpbh9,b51219);
	carry = blpbh9>>52;
	blpbh9 &= mask52;
	D1_0 = _mm512_madd52lo_epu64(D0_10,alpah0,blpbh0);
	D1_1 = _mm512_madd52hi_epu64(D0_11,alpah0,blpbh0);
	D1_1 = _mm512_madd52lo_epu64(D1_1,alpah0,blpbh1);
	D1_2 = _mm512_madd52hi_epu64(D0_12,alpah0,blpbh1);
	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah0,blpbh2);
	D1_3 = _mm512_madd52hi_epu64(D0_13,alpah0,blpbh2);
	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah0,blpbh3);
	D1_4 = _mm512_madd52hi_epu64(D0_14,alpah0,blpbh3);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah0,blpbh4);
	D1_5 = _mm512_madd52hi_epu64(D0_15,alpah0,blpbh4);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah0,blpbh5);
	D1_6 = _mm512_madd52hi_epu64(D0_16,alpah0,blpbh5);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah0,blpbh6);
	D1_7 = _mm512_madd52hi_epu64(D0_17,alpah0,blpbh6);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah0,blpbh7);
	D1_8 = _mm512_madd52hi_epu64(D0_18,alpah0,blpbh7);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah0,blpbh8);
	D1_9 = _mm512_madd52hi_epu64(D0_19,alpah0,blpbh8);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah0,blpbh9);
	D1_10 = _mm512_madd52hi_epu64(zero,alpah0,blpbh9);

	D1_1 = _mm512_madd52lo_epu64(D1_1,alpah1,blpbh0);
	D1_2 = _mm512_madd52hi_epu64(D1_2,alpah1,blpbh0);
	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah1,blpbh1);
	D1_3 = _mm512_madd52hi_epu64(D1_3,alpah1,blpbh1);
	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah1,blpbh2);
	D1_4 = _mm512_madd52hi_epu64(D1_4,alpah1,blpbh2);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah1,blpbh3);
	D1_5 = _mm512_madd52hi_epu64(D1_5,alpah1,blpbh3);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah1,blpbh4);
	D1_6 = _mm512_madd52hi_epu64(D1_6,alpah1,blpbh4);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah1,blpbh5);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah1,blpbh5);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah1,blpbh6);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah1,blpbh6);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah1,blpbh7);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah1,blpbh7);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah1,blpbh8);
	D1_10 = _mm512_madd52hi_epu64(D1_10,alpah1,blpbh8);
	D1_10 = _mm512_madd52lo_epu64(D1_10,alpah1,blpbh9);
	D1_11 = _mm512_madd52hi_epu64(zero,alpah1,blpbh9);

	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah2,blpbh0);
	D1_3 = _mm512_madd52hi_epu64(D1_3,alpah2,blpbh0);
	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah2,blpbh1);
	D1_4 = _mm512_madd52hi_epu64(D1_4,alpah2,blpbh1);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah2,blpbh2);
	D1_5 = _mm512_madd52hi_epu64(D1_5,alpah2,blpbh2);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah2,blpbh3);
	D1_6 = _mm512_madd52hi_epu64(D1_6,alpah2,blpbh3);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah2,blpbh4);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah2,blpbh4);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah2,blpbh5);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah2,blpbh5);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah2,blpbh6);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah2,blpbh6);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah2,blpbh7);
	D1_10 = _mm512_madd52hi_epu64(D1_10,alpah2,blpbh7);
	D1_10 = _mm512_madd52lo_epu64(D1_10,alpah2,blpbh8);
	D1_11 = _mm512_madd52hi_epu64(D1_11,alpah2,blpbh8);
	D1_11 = _mm512_madd52lo_epu64(D1_11,alpah2,blpbh9);
	D1_12 = _mm512_madd52hi_epu64(zero,alpah2,blpbh9);

	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah3,blpbh0);
	D1_4 = _mm512_madd52hi_epu64(D1_4,alpah3,blpbh0);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah3,blpbh1);
	D1_5 = _mm512_madd52hi_epu64(D1_5,alpah3,blpbh1);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah3,blpbh2);
	D1_6 = _mm512_madd52hi_epu64(D1_6,alpah3,blpbh2);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah3,blpbh3);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah3,blpbh3);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah3,blpbh4);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah3,blpbh4);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah3,blpbh5);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah3,blpbh5);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah3,blpbh6);
	D1_10 = _mm512_madd52hi_epu64(D1_10,alpah3,blpbh6);
	D1_10 = _mm512_madd52lo_epu64(D1_10,alpah3,blpbh7);
	D1_11 = _mm512_madd52hi_epu64(D1_11,alpah3,blpbh7);
	D1_11 = _mm512_madd52lo_epu64(D1_11,alpah3,blpbh8);
	D1_12 = _mm512_madd52hi_epu64(D1_12,alpah3,blpbh8);
	D1_12 = _mm512_madd52lo_epu64(D1_12,alpah3,blpbh9);
	D1_13 = _mm512_madd52hi_epu64(zero,alpah3,blpbh9);

	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah4,blpbh0);
	D1_5 = _mm512_madd52hi_epu64(D1_5,alpah4,blpbh0);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah4,blpbh1);
	D1_6 = _mm512_madd52hi_epu64(D1_6,alpah4,blpbh1);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah4,blpbh2);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah4,blpbh2);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah4,blpbh3);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah4,blpbh3);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah4,blpbh4);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah4,blpbh4);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah4,blpbh5);
	D1_10 = _mm512_madd52hi_epu64(D1_10,alpah4,blpbh5);
	D1_10 = _mm512_madd52lo_epu64(D1_10,alpah4,blpbh6);
	D1_11 = _mm512_madd52hi_epu64(D1_11,alpah4,blpbh6);
	D1_11 = _mm512_madd52lo_epu64(D1_11,alpah4,blpbh7);
	D1_12 = _mm512_madd52hi_epu64(D1_12,alpah4,blpbh7);
	D1_12 = _mm512_madd52lo_epu64(D1_12,alpah4,blpbh8);
	D1_13 = _mm512_madd52hi_epu64(D1_13,alpah4,blpbh8);
	D1_13 = _mm512_madd52lo_epu64(D1_13,alpah4,blpbh9);
	D1_14 = _mm512_madd52hi_epu64(zero,alpah4,blpbh9);

	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah5,blpbh0);
	D1_6 = _mm512_madd52hi_epu64(D1_6,alpah5,blpbh0);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah5,blpbh1);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah5,blpbh1);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah5,blpbh2);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah5,blpbh2);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah5,blpbh3);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah5,blpbh3);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah5,blpbh4);
	D1_10 = _mm512_madd52hi_epu64(D1_10,alpah5,blpbh4);
	D1_10 = _mm512_madd52lo_epu64(D1_10,alpah5,blpbh5);
	D1_11 = _mm512_madd52hi_epu64(D1_11,alpah5,blpbh5);
	D1_11 = _mm512_madd52lo_epu64(D1_11,alpah5,blpbh6);
	D1_12 = _mm512_madd52hi_epu64(D1_12,alpah5,blpbh6);
	D1_12 = _mm512_madd52lo_epu64(D1_12,alpah5,blpbh7);
	D1_13 = _mm512_madd52hi_epu64(D1_13,alpah5,blpbh7);
	D1_13 = _mm512_madd52lo_epu64(D1_13,alpah5,blpbh8);
	D1_14 = _mm512_madd52hi_epu64(D1_14,alpah5,blpbh8);
	D1_14 = _mm512_madd52lo_epu64(D1_14,alpah5,blpbh9);
	D1_15 = _mm512_madd52hi_epu64(zero,alpah5,blpbh9);

	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah6,blpbh0);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah6,blpbh0);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah6,blpbh1);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah6,blpbh1);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah6,blpbh2);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah6,blpbh2);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah6,blpbh3);
	D1_10 = _mm512_madd52hi_epu64(D1_10,alpah6,blpbh3);
	D1_10 = _mm512_madd52lo_epu64(D1_10,alpah6,blpbh4);
	D1_11 = _mm512_madd52hi_epu64(D1_11,alpah6,blpbh4);
	D1_11 = _mm512_madd52lo_epu64(D1_11,alpah6,blpbh5);
	D1_12 = _mm512_madd52hi_epu64(D1_12,alpah6,blpbh5);
	D1_12 = _mm512_madd52lo_epu64(D1_12,alpah6,blpbh6);
	D1_13 = _mm512_madd52hi_epu64(D1_13,alpah6,blpbh6);
	D1_13 = _mm512_madd52lo_epu64(D1_13,alpah6,blpbh7);
	D1_14 = _mm512_madd52hi_epu64(D1_14,alpah6,blpbh7);
	D1_14 = _mm512_madd52lo_epu64(D1_14,alpah6,blpbh8);
	D1_15 = _mm512_madd52hi_epu64(D1_15,alpah6,blpbh8);
	D1_15 = _mm512_madd52lo_epu64(D1_15,alpah6,blpbh9);
	D1_16 = _mm512_madd52hi_epu64(zero,alpah6,blpbh9);

	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah7,blpbh0);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah7,blpbh0);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah7,blpbh1);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah7,blpbh1);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah7,blpbh2);
	D1_10 = _mm512_madd52hi_epu64(D1_10,alpah7,blpbh2);
	D1_10 = _mm512_madd52lo_epu64(D1_10,alpah7,blpbh3);
	D1_11 = _mm512_madd52hi_epu64(D1_11,alpah7,blpbh3);
	D1_11 = _mm512_madd52lo_epu64(D1_11,alpah7,blpbh4);
	D1_12 = _mm512_madd52hi_epu64(D1_12,alpah7,blpbh4);
	D1_12 = _mm512_madd52lo_epu64(D1_12,alpah7,blpbh5);
	D1_13 = _mm512_madd52hi_epu64(D1_13,alpah7,blpbh5);
	D1_13 = _mm512_madd52lo_epu64(D1_13,alpah7,blpbh6);
	D1_14 = _mm512_madd52hi_epu64(D1_14,alpah7,blpbh6);
	D1_14 = _mm512_madd52lo_epu64(D1_14,alpah7,blpbh7);
	D1_15 = _mm512_madd52hi_epu64(D1_15,alpah7,blpbh7);
	D1_15 = _mm512_madd52lo_epu64(D1_15,alpah7,blpbh8);
	D1_16 = _mm512_madd52hi_epu64(D1_16,alpah7,blpbh8);
	D1_16 = _mm512_madd52lo_epu64(D1_16,alpah7,blpbh9);
	D1_17 = _mm512_madd52hi_epu64(zero,alpah7,blpbh9);

	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah8,blpbh0);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah8,blpbh0);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah8,blpbh1);
	D1_10 = _mm512_madd52hi_epu64(D1_10,alpah8,blpbh1);
	D1_10 = _mm512_madd52lo_epu64(D1_10,alpah8,blpbh2);
	D1_11 = _mm512_madd52hi_epu64(D1_11,alpah8,blpbh2);
	D1_11 = _mm512_madd52lo_epu64(D1_11,alpah8,blpbh3);
	D1_12 = _mm512_madd52hi_epu64(D1_12,alpah8,blpbh3);
	D1_12 = _mm512_madd52lo_epu64(D1_12,alpah8,blpbh4);
	D1_13 = _mm512_madd52hi_epu64(D1_13,alpah8,blpbh4);
	D1_13 = _mm512_madd52lo_epu64(D1_13,alpah8,blpbh5);
	D1_14 = _mm512_madd52hi_epu64(D1_14,alpah8,blpbh5);
	D1_14 = _mm512_madd52lo_epu64(D1_14,alpah8,blpbh6);
	D1_15 = _mm512_madd52hi_epu64(D1_15,alpah8,blpbh6);
	D1_15 = _mm512_madd52lo_epu64(D1_15,alpah8,blpbh7);
	D1_16 = _mm512_madd52hi_epu64(D1_16,alpah8,blpbh7);
	D1_16 = _mm512_madd52lo_epu64(D1_16,alpah8,blpbh8);
	D1_17 = _mm512_madd52hi_epu64(D1_17,alpah8,blpbh8);
	D1_17 = _mm512_madd52lo_epu64(D1_17,alpah8,blpbh9);
	D1_18 = _mm512_madd52hi_epu64(zero,alpah8,blpbh9);

	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah9,blpbh0);
	D1_10 = _mm512_madd52hi_epu64(D1_10,alpah9,blpbh0);
	D1_10 = _mm512_madd52lo_epu64(D1_10,alpah9,blpbh1);
	D1_11 = _mm512_madd52hi_epu64(D1_11,alpah9,blpbh1);
	D1_11 = _mm512_madd52lo_epu64(D1_11,alpah9,blpbh2);
	D1_12 = _mm512_madd52hi_epu64(D1_12,alpah9,blpbh2);
	D1_12 = _mm512_madd52lo_epu64(D1_12,alpah9,blpbh3);
	D1_13 = _mm512_madd52hi_epu64(D1_13,alpah9,blpbh3);
	D1_13 = _mm512_madd52lo_epu64(D1_13,alpah9,blpbh4);
	D1_14 = _mm512_madd52hi_epu64(D1_14,alpah9,blpbh4);
	D1_14 = _mm512_madd52lo_epu64(D1_14,alpah9,blpbh5);
	D1_15 = _mm512_madd52hi_epu64(D1_15,alpah9,blpbh5);
	D1_15 = _mm512_madd52lo_epu64(D1_15,alpah9,blpbh6);
	D1_16 = _mm512_madd52hi_epu64(D1_16,alpah9,blpbh6);
	D1_16 = _mm512_madd52lo_epu64(D1_16,alpah9,blpbh7);
	D1_17 = _mm512_madd52hi_epu64(D1_17,alpah9,blpbh7);
	D1_17 = _mm512_madd52lo_epu64(D1_17,alpah9,blpbh8);
	D1_18 = _mm512_madd52hi_epu64(D1_18,alpah9,blpbh8);
	D1_18 = _mm512_madd52lo_epu64(D1_18,alpah9,blpbh9);
	D1_19 = _mm512_madd52hi_epu64(zero,alpah9,blpbh9);


	// Carry management

	carry  = _mm512_srli_epi64(D1_0,52);
	D1_0 = _mm512_and_si512(D1_0,mask52);
	D1_1 = _mm512_add_epi64(D1_1,carry);
	carry  = _mm512_srli_epi64(D1_1,52);
	D1_2 = _mm512_add_epi64(D1_2,carry);
	D1_1 = _mm512_and_si512(D1_1,mask52);
	carry  = _mm512_srli_epi64(D1_2,52);
	D1_3 = _mm512_add_epi64(D1_3,carry);
	D1_2 = _mm512_and_si512(D1_2,mask52);
	carry  = _mm512_srli_epi64(D1_3,52);
	D1_4 = _mm512_add_epi64(D1_4,carry);
	D1_3 = _mm512_and_si512(D1_3,mask52);
	carry  = _mm512_srli_epi64(D1_4,52);
	D1_5 = _mm512_add_epi64(D1_5,carry);
	D1_4 = _mm512_and_si512(D1_4,mask52);
	carry  = _mm512_srli_epi64(D1_5,52);
	D1_6 = _mm512_add_epi64(D1_6,carry);
	D1_5 = _mm512_and_si512(D1_5,mask52);
	carry  = _mm512_srli_epi64(D1_6,52);
	D1_7 = _mm512_add_epi64(D1_7,carry);
	D1_6 = _mm512_and_si512(D1_6,mask52);
	carry  = _mm512_srli_epi64(D1_7,52);
	D1_8 = _mm512_add_epi64(D1_8,carry);
	D1_7 = _mm512_and_si512(D1_7,mask52);
	carry  = _mm512_srli_epi64(D1_8,52);
	D1_9 = _mm512_add_epi64(D1_9,carry);
	D1_8 = _mm512_and_si512(D1_8,mask52);
	carry  = _mm512_srli_epi64(D1_9,52);
	D1_10 = _mm512_add_epi64(D1_10,carry);
	D1_9 = _mm512_and_si512(D1_9,mask52);
	carry  = _mm512_srli_epi64(D1_10,52);
	D1_11 = _mm512_add_epi64(D1_11,carry);
	D1_10 = _mm512_and_si512(D1_10,mask52);
	carry  = _mm512_srli_epi64(D1_11,52);
	D1_12 = _mm512_add_epi64(D1_12,carry);
	D1_11 = _mm512_and_si512(D1_11,mask52);
	carry  = _mm512_srli_epi64(D1_12,52);
	D1_13 = _mm512_add_epi64(D1_13,carry);
	D1_12 = _mm512_and_si512(D1_12,mask52);
	carry  = _mm512_srli_epi64(D1_13,52);
	D1_14 = _mm512_add_epi64(D1_14,carry);
	D1_13 = _mm512_and_si512(D1_13,mask52);
	carry  = _mm512_srli_epi64(D1_14,52);
	D1_15 = _mm512_add_epi64(D1_15,carry);
	D1_14 = _mm512_and_si512(D1_14,mask52);
	carry  = _mm512_srli_epi64(D1_15,52);
	D1_16 = _mm512_add_epi64(D1_16,carry);
	D1_15 = _mm512_and_si512(D1_15,mask52);
	carry  = _mm512_srli_epi64(D1_16,52);
	D1_17 = _mm512_add_epi64(D1_17,carry);
	D1_16 = _mm512_and_si512(D1_16,mask52);
	carry  = _mm512_srli_epi64(D1_17,52);
	D1_18 = _mm512_add_epi64(D1_18,carry);
	D1_17 = _mm512_and_si512(D1_17,mask52);
	carry  = _mm512_srli_epi64(D1_18,52);
	D1_19 = _mm512_add_epi64(D1_19,carry);
	D1_18 = _mm512_and_si512(D1_18,mask52);

	// Conversion in base 2^519

	carry  = _mm512_srli_epi64(D1_9,51);
	D1_9 = _mm512_and_si512(D1_9,mask51);// radix 2^519
	D1_10 = _mm512_add_epi64(_mm512_slli_epi64(D1_10,1),carry);
	D1_10 = _mm512_add_epi64(D1_10,D2_0);
	carry = _mm512_srli_epi64(D1_10,52);
	D1_10 = _mm512_and_si512(D1_10,mask52);
	D1_11 = _mm512_add_epi64(_mm512_slli_epi64(D1_11,1),carry);
	D1_11 = _mm512_add_epi64(D1_11,D2_1);
	carry = _mm512_srli_epi64(D1_11,52);
	D1_11 = _mm512_and_si512(D1_11,mask52);
	D1_12 = _mm512_add_epi64(_mm512_slli_epi64(D1_12,1),carry);
	D1_12 = _mm512_add_epi64(D1_12,D2_2);
	carry = _mm512_srli_epi64(D1_12,52);
	D1_12 = _mm512_and_si512(D1_12,mask52);
	D1_13 = _mm512_add_epi64(_mm512_slli_epi64(D1_13,1),carry);
	D1_13 = _mm512_add_epi64(D1_13,D2_3);
	carry = _mm512_srli_epi64(D1_13,52);
	D1_13 = _mm512_and_si512(D1_13,mask52);
	D1_14 = _mm512_add_epi64(_mm512_slli_epi64(D1_14,1),carry);
	D1_14 = _mm512_add_epi64(D1_14,D2_4);
	carry = _mm512_srli_epi64(D1_14,52);
	D1_14 = _mm512_and_si512(D1_14,mask52);
	D1_15 = _mm512_add_epi64(_mm512_slli_epi64(D1_15,1),carry);
	D1_15 = _mm512_add_epi64(D1_15,D2_5);
	carry = _mm512_srli_epi64(D1_15,52);
	D1_15 = _mm512_and_si512(D1_15,mask52);
	D1_16 = _mm512_add_epi64(_mm512_slli_epi64(D1_16,1),carry);
	D1_16 = _mm512_add_epi64(D1_16,D2_6);
	carry = _mm512_srli_epi64(D1_16,52);
	D1_16 = _mm512_and_si512(D1_16,mask52);
	D1_17 = _mm512_add_epi64(_mm512_slli_epi64(D1_17,1),carry);
	D1_17 = _mm512_add_epi64(D1_17,D2_7);
	carry = _mm512_srli_epi64(D1_17,52);
	D1_17 = _mm512_and_si512(D1_17,mask52);
	D1_18 = _mm512_add_epi64(_mm512_slli_epi64(D1_18,1),carry);
	D1_18 = _mm512_add_epi64(D1_18,D2_8);
	carry = _mm512_srli_epi64(D1_18,52);
	D1_18 = _mm512_and_si512(D1_18,mask52);
	D1_19 = _mm512_add_epi64(_mm512_slli_epi64(D1_19,1),carry);
	D1_19 = _mm512_add_epi64(D1_19,D2_9);
	carry  = _mm512_srli_epi64(D1_19,51);
	D1_19 = _mm512_and_si512(D1_19,mask51);// radix 2^519

	// Final reconstruction


	// tmp = D0+D2, radix 2^519

	__m512i tmp0 = _mm512_add_epi64(D0_0,D2_0);
	__m512i carry_tmp  = _mm512_srli_epi64(tmp0,52);
	tmp0 = _mm512_and_si512(tmp0,mask52);

	__m512i tmp1 = _mm512_add_epi64(D0_1,carry_tmp);
	tmp1 = _mm512_add_epi64(tmp1,D2_1);
	carry_tmp  = _mm512_srli_epi64(tmp1,52);
	tmp1 = _mm512_and_si512(tmp1,mask52);

	__m512i tmp2 = _mm512_add_epi64(D0_2,carry_tmp);
	tmp2 = _mm512_add_epi64(tmp2,D2_2);
	carry_tmp  = _mm512_srli_epi64(tmp2,52);
	tmp2 = _mm512_and_si512(tmp2,mask52);

	__m512i tmp3 = _mm512_add_epi64(D0_3,carry_tmp);
	tmp3 = _mm512_add_epi64(tmp3,D2_3);
	carry_tmp  = _mm512_srli_epi64(tmp3,52);
	tmp3 = _mm512_and_si512(tmp3,mask52);

	__m512i tmp4 = _mm512_add_epi64(D0_4,carry_tmp);
	tmp4 = _mm512_add_epi64(tmp4,D2_4);
	carry_tmp  = _mm512_srli_epi64(tmp4,52);
	tmp4 = _mm512_and_si512(tmp4,mask52);

	__m512i tmp5 = _mm512_add_epi64(D0_5,carry_tmp);
	tmp5 = _mm512_add_epi64(tmp5,D2_5);
	carry_tmp  = _mm512_srli_epi64(tmp5,52);
	tmp5 = _mm512_and_si512(tmp5,mask52);

	__m512i tmp6 = _mm512_add_epi64(D0_6,carry_tmp);
	tmp6 = _mm512_add_epi64(tmp6,D2_6);
	carry_tmp  = _mm512_srli_epi64(tmp6,52);
	tmp6 = _mm512_and_si512(tmp6,mask52);

	__m512i tmp7 = _mm512_add_epi64(D0_7,carry_tmp);
	tmp7 = _mm512_add_epi64(tmp7,D2_7);
	carry_tmp  = _mm512_srli_epi64(tmp7,52);
	tmp7 = _mm512_and_si512(tmp7,mask52);

	__m512i tmp8 = _mm512_add_epi64(D0_8,carry_tmp);
	tmp8 = _mm512_add_epi64(tmp8,D2_8);
	carry_tmp  = _mm512_srli_epi64(tmp8,52);
	tmp8 = _mm512_and_si512(tmp8,mask52);

	__m512i tmp9 = _mm512_add_epi64(D0_9,carry_tmp);
	tmp9 = _mm512_add_epi64(tmp9,D2_9);
	carry_tmp  = _mm512_srli_epi64(tmp9,51);
	tmp9 = _mm512_and_si512(tmp9,mask51);// radix 2**519

	__m512i tmp10 = _mm512_add_epi64(D0_10,carry_tmp);
	tmp10 = _mm512_add_epi64(tmp10,D2_10);
	carry_tmp  = _mm512_srli_epi64(tmp10,52);
	tmp10 = _mm512_and_si512(tmp10,mask52);

	__m512i tmp11 = _mm512_add_epi64(D0_11,carry_tmp);
	tmp11 = _mm512_add_epi64(tmp11,D2_11);
	carry_tmp  = _mm512_srli_epi64(tmp11,52);
	tmp11 = _mm512_and_si512(tmp11,mask52);

	__m512i tmp12 = _mm512_add_epi64(D0_12,carry_tmp);
	tmp12 = _mm512_add_epi64(tmp12,D2_12);
	carry_tmp  = _mm512_srli_epi64(tmp12,52);
	tmp12 = _mm512_and_si512(tmp12,mask52);

	__m512i tmp13 = _mm512_add_epi64(D0_13,carry_tmp);
	tmp13 = _mm512_add_epi64(tmp13,D2_13);
	carry_tmp  = _mm512_srli_epi64(tmp13,52);
	tmp13 = _mm512_and_si512(tmp13,mask52);

	__m512i tmp14 = _mm512_add_epi64(D0_14,carry_tmp);
	tmp14 = _mm512_add_epi64(tmp14,D2_14);
	carry_tmp  = _mm512_srli_epi64(tmp14,52);
	tmp14 = _mm512_and_si512(tmp14,mask52);

	__m512i tmp15 = _mm512_add_epi64(D0_15,carry_tmp);
	tmp15 = _mm512_add_epi64(tmp15,D2_15);
	carry_tmp  = _mm512_srli_epi64(tmp15,52);
	tmp15 = _mm512_and_si512(tmp15,mask52);

	__m512i tmp16 = _mm512_add_epi64(D0_16,carry_tmp);
	tmp16 = _mm512_add_epi64(tmp16,D2_16);
	carry_tmp  = _mm512_srli_epi64(tmp16,52);
	tmp16 = _mm512_and_si512(tmp16,mask52);

	__m512i tmp17 = _mm512_add_epi64(D0_17,carry_tmp);
	tmp17 = _mm512_add_epi64(tmp17,D2_17);
	carry_tmp  = _mm512_srli_epi64(tmp17,52);
	tmp17 = _mm512_and_si512(tmp17,mask52);

	__m512i tmp18 = _mm512_add_epi64(D0_18,carry_tmp);
	tmp18 = _mm512_add_epi64(tmp18,D2_18);
	carry_tmp  = _mm512_srli_epi64(tmp18,52);
	tmp18 = _mm512_and_si512(tmp18,mask52);

	__m512i tmp19 = _mm512_add_epi64(D0_19,carry_tmp);
	tmp19 = _mm512_add_epi64(tmp19,D2_19);
	carry_tmp  = _mm512_srli_epi64(tmp19,51);
	tmp19 = _mm512_and_si512(tmp19,mask51);// radix 2**519




	// D1 = D1 -tmp, radix 2^519

	D1_0 = _mm512_sub_epi64(D1_0,tmp0);
	__m512i borrow = _mm512_srli_epi64(D1_0,52)&un;
	D1_0 = _mm512_and_si512(D1_0,mask52);
	borrow = _mm512_add_epi64(tmp1,borrow);
	D1_1 = _mm512_sub_epi64(D1_1,borrow);
	borrow  = _mm512_srli_epi64(D1_1,52)&un;
	D1_1 = _mm512_and_si512(D1_1,mask52);

	borrow = _mm512_add_epi64(tmp2,borrow);
	D1_2 = _mm512_sub_epi64(D1_2,borrow);
	borrow  = _mm512_srli_epi64(D1_2,52)&un;
	D1_2 = _mm512_and_si512(D1_2,mask52);

	borrow = _mm512_add_epi64(tmp3,borrow);
	D1_3 = _mm512_sub_epi64(D1_3,borrow);
	borrow  = _mm512_srli_epi64(D1_3,52)&un;
	D1_3 = _mm512_and_si512(D1_3,mask52);

	borrow = _mm512_add_epi64(tmp4,borrow);
	D1_4 = _mm512_sub_epi64(D1_4,borrow);
	borrow  = _mm512_srli_epi64(D1_4,52)&un;
	D1_4 = _mm512_and_si512(D1_4,mask52);

	borrow = _mm512_add_epi64(tmp5,borrow);
	D1_5 = _mm512_sub_epi64(D1_5,borrow);
	borrow  = _mm512_srli_epi64(D1_5,52)&un;
	D1_5 = _mm512_and_si512(D1_5,mask52);

	borrow = _mm512_add_epi64(tmp6,borrow);
	D1_6 = _mm512_sub_epi64(D1_6,borrow);
	borrow  = _mm512_srli_epi64(D1_6,52)&un;
	D1_6 = _mm512_and_si512(D1_6,mask52);

	borrow = _mm512_add_epi64(tmp7,borrow);
	D1_7 = _mm512_sub_epi64(D1_7,borrow);
	borrow  = _mm512_srli_epi64(D1_7,52)&un;
	D1_7 = _mm512_and_si512(D1_7,mask52);

	borrow = _mm512_add_epi64(tmp8,borrow);
	D1_8 = _mm512_sub_epi64(D1_8,borrow);
	borrow  = _mm512_srli_epi64(D1_8,52)&un;
	D1_8 = _mm512_and_si512(D1_8,mask52);

	borrow = _mm512_add_epi64(tmp9,borrow);
	D1_9 = _mm512_sub_epi64(D1_9,borrow);
	borrow = _mm512_srli_epi64(D1_9,51)&un;
	D1_9 = _mm512_and_si512(D1_9,mask51);// radix 2**519

	borrow = _mm512_add_epi64(tmp10,borrow);
	D1_10 = _mm512_sub_epi64(D1_10,borrow);
	borrow  = _mm512_srli_epi64(D1_10,52)&un;
	D1_10 = _mm512_and_si512(D1_10,mask52);

	borrow = _mm512_add_epi64(tmp11,borrow);
	D1_11 = _mm512_sub_epi64(D1_11,borrow);
	borrow  = _mm512_srli_epi64(D1_11,52)&un;
	D1_11 = _mm512_and_si512(D1_11,mask52);

	borrow = _mm512_add_epi64(tmp12,borrow);
	D1_12 = _mm512_sub_epi64(D1_12,borrow);
	borrow  = _mm512_srli_epi64(D1_12,52)&un;
	D1_12 = _mm512_and_si512(D1_12,mask52);

	borrow = _mm512_add_epi64(tmp13,borrow);
	D1_13 = _mm512_sub_epi64(D1_13,borrow);
	borrow  = _mm512_srli_epi64(D1_13,52)&un;
	D1_13 = _mm512_and_si512(D1_13,mask52);

	borrow = _mm512_add_epi64(tmp14,borrow);
	D1_14 = _mm512_sub_epi64(D1_14,borrow);
	borrow  = _mm512_srli_epi64(D1_14,52)&un;
	D1_14 = _mm512_and_si512(D1_14,mask52);

	borrow = _mm512_add_epi64(tmp15,borrow);
	D1_15 = _mm512_sub_epi64(D1_15,borrow);
	borrow  = _mm512_srli_epi64(D1_15,52)&un;
	D1_15 = _mm512_and_si512(D1_15,mask52);

	borrow = _mm512_add_epi64(tmp16,borrow);
	D1_16 = _mm512_sub_epi64(D1_16,borrow);
	borrow  = _mm512_srli_epi64(D1_16,52)&un;
	D1_16 = _mm512_and_si512(D1_16,mask52);

	borrow = _mm512_add_epi64(tmp17,borrow);
	D1_17 = _mm512_sub_epi64(D1_17,borrow);
	borrow  = _mm512_srli_epi64(D1_17,52)&un;
	D1_17 = _mm512_and_si512(D1_17,mask52);

	borrow = _mm512_add_epi64(tmp18,borrow);
	D1_18 = _mm512_sub_epi64(D1_18,borrow);
	borrow  = _mm512_srli_epi64(D1_18,52)&un;
	D1_18 = _mm512_and_si512(D1_18,mask52);

	borrow = _mm512_add_epi64(tmp19,borrow);
	D1_19 = _mm512_sub_epi64(D1_19,borrow);
	borrow = _mm512_srli_epi64(D1_19,51)&un;
	D1_19 = _mm512_and_si512(D1_19,mask51);// radix 2**519


	// Final borrows

	borrow = _mm512_add_epi64(carry_tmp,borrow);
	D2_10 = _mm512_add_epi64(D2_10,carry);
	D2_10 = _mm512_sub_epi64(D2_10,borrow);
	borrow  = _mm512_srli_epi64(D2_10,52)&un;
	D2_10 = _mm512_and_si512(D2_10,mask52);

	D2_11 = _mm512_sub_epi64(D2_11,borrow);
	borrow  = _mm512_srli_epi64(D2_11,52)&un;
	D2_11 = _mm512_and_si512(D2_11,mask52);

	D2_12 = _mm512_sub_epi64(D2_12,borrow);
	borrow  = _mm512_srli_epi64(D2_12,52)&un;
	D2_12 = _mm512_and_si512(D2_12,mask52);

	D2_13 = _mm512_sub_epi64(D2_13,borrow);
	borrow  = _mm512_srli_epi64(D2_13,52)&un;
	D2_13 = _mm512_and_si512(D2_13,mask52);

	D2_14 = _mm512_sub_epi64(D2_14,borrow);
	borrow  = _mm512_srli_epi64(D2_14,52)&un;
	D2_14 = _mm512_and_si512(D2_14,mask52);

	D2_15 = _mm512_sub_epi64(D2_15,borrow);
	borrow  = _mm512_srli_epi64(D2_15,52)&un;
	D2_15 = _mm512_and_si512(D2_15,mask52);

	D2_16 = _mm512_sub_epi64(D2_16,borrow);
	borrow  = _mm512_srli_epi64(D2_16,52)&un;
	D2_16 = _mm512_and_si512(D2_16,mask52);

	D2_17 = _mm512_sub_epi64(D2_17,borrow);
	borrow  = _mm512_srli_epi64(D2_17,52)&un;
	D2_17 = _mm512_and_si512(D2_17,mask52);

	D2_18 = _mm512_sub_epi64(D2_18,borrow);
	borrow  = _mm512_srli_epi64(D2_18,52)&un;
	D2_18 = _mm512_and_si512(D2_18,mask52);

	D2_19 = _mm512_sub_epi64(D2_19,borrow);


	_mm512_store_epi64(out+0,D0_0);
	_mm512_store_epi64(out+1,D0_1);
	_mm512_store_epi64(out+2,D0_2);
	_mm512_store_epi64(out+3,D0_3);
	_mm512_store_epi64(out+4,D0_4);
	_mm512_store_epi64(out+5,D0_5);
	_mm512_store_epi64(out+6,D0_6);
	_mm512_store_epi64(out+7,D0_7);
	_mm512_store_epi64(out+8,D0_8);
	_mm512_store_epi64(out+9,D0_9);
	_mm512_store_epi64(out+10,D1_0);
	_mm512_store_epi64(out+11,D1_1);
	_mm512_store_epi64(out+12,D1_2);
	_mm512_store_epi64(out+13,D1_3);
	_mm512_store_epi64(out+14,D1_4);
	_mm512_store_epi64(out+15,D1_5);
	_mm512_store_epi64(out+16,D1_6);
	_mm512_store_epi64(out+17,D1_7);
	_mm512_store_epi64(out+18,D1_8);
	_mm512_store_epi64(out+19,D1_9);
	_mm512_store_epi64(out+20,D1_10);
	_mm512_store_epi64(out+21,D1_11);
	_mm512_store_epi64(out+22,D1_12);
	_mm512_store_epi64(out+23,D1_13);
	_mm512_store_epi64(out+24,D1_14);
	_mm512_store_epi64(out+25,D1_15);
	_mm512_store_epi64(out+26,D1_16);
	_mm512_store_epi64(out+27,D1_17);
	_mm512_store_epi64(out+28,D1_18);
	_mm512_store_epi64(out+29,D1_19);
	_mm512_store_epi64(out+30,D2_10);
	_mm512_store_epi64(out+31,D2_11);
	_mm512_store_epi64(out+32,D2_12);
	_mm512_store_epi64(out+33,D2_13);
	_mm512_store_epi64(out+34,D2_14);
	_mm512_store_epi64(out+35,D2_15);
	_mm512_store_epi64(out+36,D2_16);
	_mm512_store_epi64(out+37,D2_17);
	_mm512_store_epi64(out+38,D2_18);
	_mm512_store_epi64(out+39,D2_19);

}

/* Karatsuba fma, computes C+AB */

inline void force_inline fma512_8_1038K(__m512i out[40], __m512i a512[20], __m512i b512[20], __m512i c512[20])
{

	// D0 = Al*Bl

	__m512i D0_0, D0_1;
	__m512i D0_2, D0_3;
	__m512i D0_4, D0_5;
	__m512i D0_6, D0_7;
	__m512i D0_8, D0_9;
	__m512i D0_10, D0_11;
	__m512i D0_12, D0_13;
	__m512i D0_14, D0_15;
	__m512i D0_16, D0_17;
	__m512i D0_18, D0_19;
	__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512), c5120 = _mm512_load_epi64(c512);
	__m512i a5121 = _mm512_load_epi64(a512+1), b5121 = _mm512_load_epi64(b512+1), c5121 = _mm512_load_epi64(c512+1);
	__m512i a5122 = _mm512_load_epi64(a512+2), b5122 = _mm512_load_epi64(b512+2), c5122 = _mm512_load_epi64(c512+2);
	__m512i a5123 = _mm512_load_epi64(a512+3), b5123 = _mm512_load_epi64(b512+3), c5123 = _mm512_load_epi64(c512+3);
	__m512i a5124 = _mm512_load_epi64(a512+4), b5124 = _mm512_load_epi64(b512+4), c5124 = _mm512_load_epi64(c512+4);
	__m512i a5125 = _mm512_load_epi64(a512+5), b5125 = _mm512_load_epi64(b512+5), c5125 = _mm512_load_epi64(c512+5);
	__m512i a5126 = _mm512_load_epi64(a512+6), b5126 = _mm512_load_epi64(b512+6), c5126 = _mm512_load_epi64(c512+6);
	__m512i a5127 = _mm512_load_epi64(a512+7), b5127 = _mm512_load_epi64(b512+7), c5127 = _mm512_load_epi64(c512+7);
	__m512i a5128 = _mm512_load_epi64(a512+8), b5128 = _mm512_load_epi64(b512+8), c5128 = _mm512_load_epi64(c512+8);
	__m512i a5129 = _mm512_load_epi64(a512+9), b5129 = _mm512_load_epi64(b512+9), c5129 = _mm512_load_epi64(c512+9);
	D0_0 = _mm512_madd52lo_epu64(c5120,a5120,b5120);
	D0_1 = _mm512_madd52hi_epu64(c5121,a5120,b5120);
	D0_1 = _mm512_madd52lo_epu64(D0_1,a5120,b5121);
	D0_2 = _mm512_madd52hi_epu64(c5121,a5120,b5121);
	D0_2 = _mm512_madd52lo_epu64(D0_2,a5120,b5122);
	D0_3 = _mm512_madd52hi_epu64(c5122,a5120,b5122);
	D0_3 = _mm512_madd52lo_epu64(D0_3,a5120,b5123);
	D0_4 = _mm512_madd52hi_epu64(c5123,a5120,b5123);
	D0_4 = _mm512_madd52lo_epu64(D0_4,a5120,b5124);
	D0_5 = _mm512_madd52hi_epu64(c5124,a5120,b5124);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5120,b5125);
	D0_6 = _mm512_madd52hi_epu64(c5125,a5120,b5125);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5120,b5126);
	D0_7 = _mm512_madd52hi_epu64(c5126,a5120,b5126);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5120,b5127);
	D0_8 = _mm512_madd52hi_epu64(c5127,a5120,b5127);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5120,b5128);
	D0_9 = _mm512_madd52hi_epu64(c5128,a5120,b5128);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5120,b5129);
	D0_10 = _mm512_madd52hi_epu64(c5129,a5120,b5129);

	D0_1 = _mm512_madd52lo_epu64(D0_1,a5121,b5120);
	D0_2 = _mm512_madd52hi_epu64(D0_2,a5121,b5120);
	D0_2 = _mm512_madd52lo_epu64(D0_2,a5121,b5121);
	D0_3 = _mm512_madd52hi_epu64(D0_3,a5121,b5121);
	D0_3 = _mm512_madd52lo_epu64(D0_3,a5121,b5122);
	D0_4 = _mm512_madd52hi_epu64(D0_4,a5121,b5122);
	D0_4 = _mm512_madd52lo_epu64(D0_4,a5121,b5123);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5121,b5123);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5121,b5124);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5121,b5124);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5121,b5125);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5121,b5125);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5121,b5126);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5121,b5126);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5121,b5127);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5121,b5127);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5121,b5128);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5121,b5128);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5121,b5129);
	D0_11 = _mm512_madd52hi_epu64(c5121,a5121,b5129);

	D0_2 = _mm512_madd52lo_epu64(D0_2,a5122,b5120);
	D0_3 = _mm512_madd52hi_epu64(D0_3,a5122,b5120);
	D0_3 = _mm512_madd52lo_epu64(D0_3,a5122,b5121);
	D0_4 = _mm512_madd52hi_epu64(D0_4,a5122,b5121);
	D0_4 = _mm512_madd52lo_epu64(D0_4,a5122,b5122);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5122,b5122);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5122,b5123);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5122,b5123);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5122,b5124);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5122,b5124);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5122,b5125);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5122,b5125);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5122,b5126);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5122,b5126);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5122,b5127);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5122,b5127);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5122,b5128);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5122,b5128);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5122,b5129);
	D0_12 = _mm512_madd52hi_epu64(c5122,a5122,b5129);

	D0_3 = _mm512_madd52lo_epu64(D0_3,a5123,b5120);
	D0_4 = _mm512_madd52hi_epu64(D0_4,a5123,b5120);
	D0_4 = _mm512_madd52lo_epu64(D0_4,a5123,b5121);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5123,b5121);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5123,b5122);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5123,b5122);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5123,b5123);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5123,b5123);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5123,b5124);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5123,b5124);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5123,b5125);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5123,b5125);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5123,b5126);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5123,b5126);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5123,b5127);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5123,b5127);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5123,b5128);
	D0_12 = _mm512_madd52hi_epu64(D0_12,a5123,b5128);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5123,b5129);
	D0_13 = _mm512_madd52hi_epu64(c5123,a5123,b5129);

	D0_4 = _mm512_madd52lo_epu64(D0_4,a5124,b5120);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5124,b5120);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5124,b5121);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5124,b5121);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5124,b5122);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5124,b5122);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5124,b5123);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5124,b5123);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5124,b5124);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5124,b5124);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5124,b5125);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5124,b5125);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5124,b5126);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5124,b5126);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5124,b5127);
	D0_12 = _mm512_madd52hi_epu64(D0_12,a5124,b5127);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5124,b5128);
	D0_13 = _mm512_madd52hi_epu64(D0_13,a5124,b5128);
	D0_13 = _mm512_madd52lo_epu64(D0_13,a5124,b5129);
	D0_14 = _mm512_madd52hi_epu64(c5124,a5124,b5129);

	D0_5 = _mm512_madd52lo_epu64(D0_5,a5125,b5120);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5125,b5120);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5125,b5121);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5125,b5121);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5125,b5122);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5125,b5122);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5125,b5123);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5125,b5123);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5125,b5124);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5125,b5124);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5125,b5125);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5125,b5125);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5125,b5126);
	D0_12 = _mm512_madd52hi_epu64(D0_12,a5125,b5126);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5125,b5127);
	D0_13 = _mm512_madd52hi_epu64(D0_13,a5125,b5127);
	D0_13 = _mm512_madd52lo_epu64(D0_13,a5125,b5128);
	D0_14 = _mm512_madd52hi_epu64(D0_14,a5125,b5128);
	D0_14 = _mm512_madd52lo_epu64(D0_14,a5125,b5129);
	D0_15 = _mm512_madd52hi_epu64(c5125,a5125,b5129);

	D0_6 = _mm512_madd52lo_epu64(D0_6,a5126,b5120);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5126,b5120);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5126,b5121);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5126,b5121);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5126,b5122);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5126,b5122);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5126,b5123);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5126,b5123);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5126,b5124);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5126,b5124);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5126,b5125);
	D0_12 = _mm512_madd52hi_epu64(D0_12,a5126,b5125);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5126,b5126);
	D0_13 = _mm512_madd52hi_epu64(D0_13,a5126,b5126);
	D0_13 = _mm512_madd52lo_epu64(D0_13,a5126,b5127);
	D0_14 = _mm512_madd52hi_epu64(D0_14,a5126,b5127);
	D0_14 = _mm512_madd52lo_epu64(D0_14,a5126,b5128);
	D0_15 = _mm512_madd52hi_epu64(D0_15,a5126,b5128);
	D0_15 = _mm512_madd52lo_epu64(D0_15,a5126,b5129);
	D0_16 = _mm512_madd52hi_epu64(c5126,a5126,b5129);

	D0_7 = _mm512_madd52lo_epu64(D0_7,a5127,b5120);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5127,b5120);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5127,b5121);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5127,b5121);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5127,b5122);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5127,b5122);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5127,b5123);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5127,b5123);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5127,b5124);
	D0_12 = _mm512_madd52hi_epu64(D0_12,a5127,b5124);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5127,b5125);
	D0_13 = _mm512_madd52hi_epu64(D0_13,a5127,b5125);
	D0_13 = _mm512_madd52lo_epu64(D0_13,a5127,b5126);
	D0_14 = _mm512_madd52hi_epu64(D0_14,a5127,b5126);
	D0_14 = _mm512_madd52lo_epu64(D0_14,a5127,b5127);
	D0_15 = _mm512_madd52hi_epu64(D0_15,a5127,b5127);
	D0_15 = _mm512_madd52lo_epu64(D0_15,a5127,b5128);
	D0_16 = _mm512_madd52hi_epu64(D0_16,a5127,b5128);
	D0_16 = _mm512_madd52lo_epu64(D0_16,a5127,b5129);
	D0_17 = _mm512_madd52hi_epu64(c5127,a5127,b5129);

	D0_8 = _mm512_madd52lo_epu64(D0_8,a5128,b5120);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5128,b5120);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5128,b5121);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5128,b5121);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5128,b5122);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5128,b5122);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5128,b5123);
	D0_12 = _mm512_madd52hi_epu64(D0_12,a5128,b5123);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5128,b5124);
	D0_13 = _mm512_madd52hi_epu64(D0_13,a5128,b5124);
	D0_13 = _mm512_madd52lo_epu64(D0_13,a5128,b5125);
	D0_14 = _mm512_madd52hi_epu64(D0_14,a5128,b5125);
	D0_14 = _mm512_madd52lo_epu64(D0_14,a5128,b5126);
	D0_15 = _mm512_madd52hi_epu64(D0_15,a5128,b5126);
	D0_15 = _mm512_madd52lo_epu64(D0_15,a5128,b5127);
	D0_16 = _mm512_madd52hi_epu64(D0_16,a5128,b5127);
	D0_16 = _mm512_madd52lo_epu64(D0_16,a5128,b5128);
	D0_17 = _mm512_madd52hi_epu64(D0_17,a5128,b5128);
	D0_17 = _mm512_madd52lo_epu64(D0_17,a5128,b5129);
	D0_18 = _mm512_madd52hi_epu64(c5128,a5128,b5129);

	D0_9 = _mm512_madd52lo_epu64(D0_9,a5129,b5120);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5129,b5120);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5129,b5121);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5129,b5121);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5129,b5122);
	D0_12 = _mm512_madd52hi_epu64(D0_12,a5129,b5122);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5129,b5123);
	D0_13 = _mm512_madd52hi_epu64(D0_13,a5129,b5123);
	D0_13 = _mm512_madd52lo_epu64(D0_13,a5129,b5124);
	D0_14 = _mm512_madd52hi_epu64(D0_14,a5129,b5124);
	D0_14 = _mm512_madd52lo_epu64(D0_14,a5129,b5125);
	D0_15 = _mm512_madd52hi_epu64(D0_15,a5129,b5125);
	D0_15 = _mm512_madd52lo_epu64(D0_15,a5129,b5126);
	D0_16 = _mm512_madd52hi_epu64(D0_16,a5129,b5126);
	D0_16 = _mm512_madd52lo_epu64(D0_16,a5129,b5127);
	D0_17 = _mm512_madd52hi_epu64(D0_17,a5129,b5127);
	D0_17 = _mm512_madd52lo_epu64(D0_17,a5129,b5128);
	D0_18 = _mm512_madd52hi_epu64(D0_18,a5129,b5128);
	D0_18 = _mm512_madd52lo_epu64(D0_18,a5129,b5129);
	D0_19 = _mm512_madd52hi_epu64(c5129,a5129,b5129);


	// Carry management

	__m512i carry  = _mm512_srli_epi64(D0_1,52);
	D0_2 = _mm512_add_epi64(D0_2,carry);
	D0_1 = _mm512_and_si512(D0_1,mask52);
	carry  = _mm512_srli_epi64(D0_2,52);
	D0_3 = _mm512_add_epi64(D0_3,carry);
	D0_2 = _mm512_and_si512(D0_2,mask52);
	carry  = _mm512_srli_epi64(D0_3,52);
	D0_4 = _mm512_add_epi64(D0_4,carry);
	D0_3 = _mm512_and_si512(D0_3,mask52);
	carry  = _mm512_srli_epi64(D0_4,52);
	D0_5 = _mm512_add_epi64(D0_5,carry);
	D0_4 = _mm512_and_si512(D0_4,mask52);
	carry  = _mm512_srli_epi64(D0_5,52);
	D0_6 = _mm512_add_epi64(D0_6,carry);
	D0_5 = _mm512_and_si512(D0_5,mask52);
	carry  = _mm512_srli_epi64(D0_6,52);
	D0_7 = _mm512_add_epi64(D0_7,carry);
	D0_6 = _mm512_and_si512(D0_6,mask52);
	carry  = _mm512_srli_epi64(D0_7,52);
	D0_8 = _mm512_add_epi64(D0_8,carry);
	D0_7 = _mm512_and_si512(D0_7,mask52);
	carry  = _mm512_srli_epi64(D0_8,52);
	D0_9 = _mm512_add_epi64(D0_9,carry);
	D0_8 = _mm512_and_si512(D0_8,mask52);
	carry  = _mm512_srli_epi64(D0_9,52);
	D0_10 = _mm512_add_epi64(D0_10,carry);
	D0_9 = _mm512_and_si512(D0_9,mask52);
	carry  = _mm512_srli_epi64(D0_10,52);
	D0_11 = _mm512_add_epi64(D0_11,carry);
	D0_10 = _mm512_and_si512(D0_10,mask52);
	carry  = _mm512_srli_epi64(D0_11,52);
	D0_12 = _mm512_add_epi64(D0_12,carry);
	D0_11 = _mm512_and_si512(D0_11,mask52);
	carry  = _mm512_srli_epi64(D0_12,52);
	D0_13 = _mm512_add_epi64(D0_13,carry);
	D0_12 = _mm512_and_si512(D0_12,mask52);
	carry  = _mm512_srli_epi64(D0_13,52);
	D0_14 = _mm512_add_epi64(D0_14,carry);
	D0_13 = _mm512_and_si512(D0_13,mask52);
	carry  = _mm512_srli_epi64(D0_14,52);
	D0_15 = _mm512_add_epi64(D0_15,carry);
	D0_14 = _mm512_and_si512(D0_14,mask52);
	carry  = _mm512_srli_epi64(D0_15,52);
	D0_16 = _mm512_add_epi64(D0_16,carry);
	D0_15 = _mm512_and_si512(D0_15,mask52);
	carry  = _mm512_srli_epi64(D0_16,52);
	D0_17 = _mm512_add_epi64(D0_17,carry);
	D0_16 = _mm512_and_si512(D0_16,mask52);
	carry  = _mm512_srli_epi64(D0_17,52);
	D0_18 = _mm512_add_epi64(D0_18,carry);
	D0_17 = _mm512_and_si512(D0_17,mask52);
	carry  = _mm512_srli_epi64(D0_18,52);
	D0_19 = _mm512_add_epi64(D0_19,carry);
	D0_18 = _mm512_and_si512(D0_18,mask52);

	// Conversion in base 2^519

	carry = D0_9>>51;
	D0_10 = (D0_10<<1)|carry;
	D0_9 &= mask51;
	carry = D0_10>>52;
	D0_11 = (D0_11<<1)|carry;
	D0_10 &= mask52;
	carry = D0_11>>52;
	D0_12 = (D0_12<<1)|carry;
	D0_11 &= mask52;
	carry = D0_12>>52;
	D0_13 = (D0_13<<1)|carry;
	D0_12 &= mask52;
	carry = D0_13>>52;
	D0_14 = (D0_14<<1)|carry;
	D0_13 &= mask52;
	carry = D0_14>>52;
	D0_15 = (D0_15<<1)|carry;
	D0_14 &= mask52;
	carry = D0_15>>52;
	D0_16 = (D0_16<<1)|carry;
	D0_15 &= mask52;
	carry = D0_16>>52;
	D0_17 = (D0_17<<1)|carry;
	D0_16 &= mask52;
	carry = D0_17>>52;
	D0_18 = (D0_18<<1)|carry;
	D0_17 &= mask52;
	carry = D0_18>>52;
	D0_19 = (D0_19<<1)|carry;
	D0_18 &= mask52;

	// D2 = Ah*Bh

	__m512i D2_0, D2_1;
	__m512i D2_2, D2_3;
	__m512i D2_4, D2_5;
	__m512i D2_6, D2_7;
	__m512i D2_8, D2_9;
	__m512i D2_10, D2_11;
	__m512i D2_12, D2_13;
	__m512i D2_14, D2_15;
	__m512i D2_16, D2_17;
	__m512i D2_18, D2_19;
	__m512i a51210 = _mm512_load_epi64(a512+10), b51210 = _mm512_load_epi64(b512+10);
	__m512i a51211 = _mm512_load_epi64(a512+11), b51211 = _mm512_load_epi64(b512+11);
	__m512i a51212 = _mm512_load_epi64(a512+12), b51212 = _mm512_load_epi64(b512+12);
	__m512i a51213 = _mm512_load_epi64(a512+13), b51213 = _mm512_load_epi64(b512+13);
	__m512i a51214 = _mm512_load_epi64(a512+14), b51214 = _mm512_load_epi64(b512+14);
	__m512i a51215 = _mm512_load_epi64(a512+15), b51215 = _mm512_load_epi64(b512+15);
	__m512i a51216 = _mm512_load_epi64(a512+16), b51216 = _mm512_load_epi64(b512+16);
	__m512i a51217 = _mm512_load_epi64(a512+17), b51217 = _mm512_load_epi64(b512+17);
	__m512i a51218 = _mm512_load_epi64(a512+18), b51218 = _mm512_load_epi64(b512+18);
	__m512i a51219 = _mm512_load_epi64(a512+19), b51219 = _mm512_load_epi64(b512+19);
	D2_0 = _mm512_madd52lo_epu64(zero,a51210,b51210);
	D2_1 = _mm512_madd52hi_epu64(zero,a51210,b51210);
	D2_1 = _mm512_madd52lo_epu64(D2_1,a51210,b51211);
	D2_2 = _mm512_madd52hi_epu64(zero,a51210,b51211);
	D2_2 = _mm512_madd52lo_epu64(D2_2,a51210,b51212);
	D2_3 = _mm512_madd52hi_epu64(zero,a51210,b51212);
	D2_3 = _mm512_madd52lo_epu64(D2_3,a51210,b51213);
	D2_4 = _mm512_madd52hi_epu64(zero,a51210,b51213);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a51210,b51214);
	D2_5 = _mm512_madd52hi_epu64(zero,a51210,b51214);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a51210,b51215);
	D2_6 = _mm512_madd52hi_epu64(zero,a51210,b51215);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a51210,b51216);
	D2_7 = _mm512_madd52hi_epu64(zero,a51210,b51216);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51210,b51217);
	D2_8 = _mm512_madd52hi_epu64(zero,a51210,b51217);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51210,b51218);
	D2_9 = _mm512_madd52hi_epu64(zero,a51210,b51218);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51210,b51219);
	D2_10 = _mm512_madd52hi_epu64(zero,a51210,b51219);

	D2_1 = _mm512_madd52lo_epu64(D2_1,a51211,b51210);
	D2_2 = _mm512_madd52hi_epu64(D2_2,a51211,b51210);
	D2_2 = _mm512_madd52lo_epu64(D2_2,a51211,b51211);
	D2_3 = _mm512_madd52hi_epu64(D2_3,a51211,b51211);
	D2_3 = _mm512_madd52lo_epu64(D2_3,a51211,b51212);
	D2_4 = _mm512_madd52hi_epu64(D2_4,a51211,b51212);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a51211,b51213);
	D2_5 = _mm512_madd52hi_epu64(D2_5,a51211,b51213);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a51211,b51214);
	D2_6 = _mm512_madd52hi_epu64(D2_6,a51211,b51214);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a51211,b51215);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a51211,b51215);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51211,b51216);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a51211,b51216);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51211,b51217);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51211,b51217);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51211,b51218);
	D2_10 = _mm512_madd52hi_epu64(D2_10,a51211,b51218);
	D2_10 = _mm512_madd52lo_epu64(D2_10,a51211,b51219);
	D2_11 = _mm512_madd52hi_epu64(zero,a51211,b51219);

	D2_2 = _mm512_madd52lo_epu64(D2_2,a51212,b51210);
	D2_3 = _mm512_madd52hi_epu64(D2_3,a51212,b51210);
	D2_3 = _mm512_madd52lo_epu64(D2_3,a51212,b51211);
	D2_4 = _mm512_madd52hi_epu64(D2_4,a51212,b51211);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a51212,b51212);
	D2_5 = _mm512_madd52hi_epu64(D2_5,a51212,b51212);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a51212,b51213);
	D2_6 = _mm512_madd52hi_epu64(D2_6,a51212,b51213);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a51212,b51214);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a51212,b51214);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51212,b51215);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a51212,b51215);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51212,b51216);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51212,b51216);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51212,b51217);
	D2_10 = _mm512_madd52hi_epu64(D2_10,a51212,b51217);
	D2_10 = _mm512_madd52lo_epu64(D2_10,a51212,b51218);
	D2_11 = _mm512_madd52hi_epu64(D2_11,a51212,b51218);
	D2_11 = _mm512_madd52lo_epu64(D2_11,a51212,b51219);
	D2_12 = _mm512_madd52hi_epu64(zero,a51212,b51219);

	D2_3 = _mm512_madd52lo_epu64(D2_3,a51213,b51210);
	D2_4 = _mm512_madd52hi_epu64(D2_4,a51213,b51210);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a51213,b51211);
	D2_5 = _mm512_madd52hi_epu64(D2_5,a51213,b51211);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a51213,b51212);
	D2_6 = _mm512_madd52hi_epu64(D2_6,a51213,b51212);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a51213,b51213);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a51213,b51213);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51213,b51214);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a51213,b51214);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51213,b51215);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51213,b51215);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51213,b51216);
	D2_10 = _mm512_madd52hi_epu64(D2_10,a51213,b51216);
	D2_10 = _mm512_madd52lo_epu64(D2_10,a51213,b51217);
	D2_11 = _mm512_madd52hi_epu64(D2_11,a51213,b51217);
	D2_11 = _mm512_madd52lo_epu64(D2_11,a51213,b51218);
	D2_12 = _mm512_madd52hi_epu64(D2_12,a51213,b51218);
	D2_12 = _mm512_madd52lo_epu64(D2_12,a51213,b51219);
	D2_13 = _mm512_madd52hi_epu64(zero,a51213,b51219);

	D2_4 = _mm512_madd52lo_epu64(D2_4,a51214,b51210);
	D2_5 = _mm512_madd52hi_epu64(D2_5,a51214,b51210);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a51214,b51211);
	D2_6 = _mm512_madd52hi_epu64(D2_6,a51214,b51211);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a51214,b51212);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a51214,b51212);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51214,b51213);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a51214,b51213);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51214,b51214);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51214,b51214);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51214,b51215);
	D2_10 = _mm512_madd52hi_epu64(D2_10,a51214,b51215);
	D2_10 = _mm512_madd52lo_epu64(D2_10,a51214,b51216);
	D2_11 = _mm512_madd52hi_epu64(D2_11,a51214,b51216);
	D2_11 = _mm512_madd52lo_epu64(D2_11,a51214,b51217);
	D2_12 = _mm512_madd52hi_epu64(D2_12,a51214,b51217);
	D2_12 = _mm512_madd52lo_epu64(D2_12,a51214,b51218);
	D2_13 = _mm512_madd52hi_epu64(D2_13,a51214,b51218);
	D2_13 = _mm512_madd52lo_epu64(D2_13,a51214,b51219);
	D2_14 = _mm512_madd52hi_epu64(zero,a51214,b51219);

	D2_5 = _mm512_madd52lo_epu64(D2_5,a51215,b51210);
	D2_6 = _mm512_madd52hi_epu64(D2_6,a51215,b51210);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a51215,b51211);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a51215,b51211);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51215,b51212);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a51215,b51212);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51215,b51213);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51215,b51213);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51215,b51214);
	D2_10 = _mm512_madd52hi_epu64(D2_10,a51215,b51214);
	D2_10 = _mm512_madd52lo_epu64(D2_10,a51215,b51215);
	D2_11 = _mm512_madd52hi_epu64(D2_11,a51215,b51215);
	D2_11 = _mm512_madd52lo_epu64(D2_11,a51215,b51216);
	D2_12 = _mm512_madd52hi_epu64(D2_12,a51215,b51216);
	D2_12 = _mm512_madd52lo_epu64(D2_12,a51215,b51217);
	D2_13 = _mm512_madd52hi_epu64(D2_13,a51215,b51217);
	D2_13 = _mm512_madd52lo_epu64(D2_13,a51215,b51218);
	D2_14 = _mm512_madd52hi_epu64(D2_14,a51215,b51218);
	D2_14 = _mm512_madd52lo_epu64(D2_14,a51215,b51219);
	D2_15 = _mm512_madd52hi_epu64(zero,a51215,b51219);

	D2_6 = _mm512_madd52lo_epu64(D2_6,a51216,b51210);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a51216,b51210);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51216,b51211);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a51216,b51211);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51216,b51212);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51216,b51212);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51216,b51213);
	D2_10 = _mm512_madd52hi_epu64(D2_10,a51216,b51213);
	D2_10 = _mm512_madd52lo_epu64(D2_10,a51216,b51214);
	D2_11 = _mm512_madd52hi_epu64(D2_11,a51216,b51214);
	D2_11 = _mm512_madd52lo_epu64(D2_11,a51216,b51215);
	D2_12 = _mm512_madd52hi_epu64(D2_12,a51216,b51215);
	D2_12 = _mm512_madd52lo_epu64(D2_12,a51216,b51216);
	D2_13 = _mm512_madd52hi_epu64(D2_13,a51216,b51216);
	D2_13 = _mm512_madd52lo_epu64(D2_13,a51216,b51217);
	D2_14 = _mm512_madd52hi_epu64(D2_14,a51216,b51217);
	D2_14 = _mm512_madd52lo_epu64(D2_14,a51216,b51218);
	D2_15 = _mm512_madd52hi_epu64(D2_15,a51216,b51218);
	D2_15 = _mm512_madd52lo_epu64(D2_15,a51216,b51219);
	D2_16 = _mm512_madd52hi_epu64(zero,a51216,b51219);

	D2_7 = _mm512_madd52lo_epu64(D2_7,a51217,b51210);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a51217,b51210);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51217,b51211);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51217,b51211);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51217,b51212);
	D2_10 = _mm512_madd52hi_epu64(D2_10,a51217,b51212);
	D2_10 = _mm512_madd52lo_epu64(D2_10,a51217,b51213);
	D2_11 = _mm512_madd52hi_epu64(D2_11,a51217,b51213);
	D2_11 = _mm512_madd52lo_epu64(D2_11,a51217,b51214);
	D2_12 = _mm512_madd52hi_epu64(D2_12,a51217,b51214);
	D2_12 = _mm512_madd52lo_epu64(D2_12,a51217,b51215);
	D2_13 = _mm512_madd52hi_epu64(D2_13,a51217,b51215);
	D2_13 = _mm512_madd52lo_epu64(D2_13,a51217,b51216);
	D2_14 = _mm512_madd52hi_epu64(D2_14,a51217,b51216);
	D2_14 = _mm512_madd52lo_epu64(D2_14,a51217,b51217);
	D2_15 = _mm512_madd52hi_epu64(D2_15,a51217,b51217);
	D2_15 = _mm512_madd52lo_epu64(D2_15,a51217,b51218);
	D2_16 = _mm512_madd52hi_epu64(D2_16,a51217,b51218);
	D2_16 = _mm512_madd52lo_epu64(D2_16,a51217,b51219);
	D2_17 = _mm512_madd52hi_epu64(zero,a51217,b51219);

	D2_8 = _mm512_madd52lo_epu64(D2_8,a51218,b51210);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51218,b51210);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51218,b51211);
	D2_10 = _mm512_madd52hi_epu64(D2_10,a51218,b51211);
	D2_10 = _mm512_madd52lo_epu64(D2_10,a51218,b51212);
	D2_11 = _mm512_madd52hi_epu64(D2_11,a51218,b51212);
	D2_11 = _mm512_madd52lo_epu64(D2_11,a51218,b51213);
	D2_12 = _mm512_madd52hi_epu64(D2_12,a51218,b51213);
	D2_12 = _mm512_madd52lo_epu64(D2_12,a51218,b51214);
	D2_13 = _mm512_madd52hi_epu64(D2_13,a51218,b51214);
	D2_13 = _mm512_madd52lo_epu64(D2_13,a51218,b51215);
	D2_14 = _mm512_madd52hi_epu64(D2_14,a51218,b51215);
	D2_14 = _mm512_madd52lo_epu64(D2_14,a51218,b51216);
	D2_15 = _mm512_madd52hi_epu64(D2_15,a51218,b51216);
	D2_15 = _mm512_madd52lo_epu64(D2_15,a51218,b51217);
	D2_16 = _mm512_madd52hi_epu64(D2_16,a51218,b51217);
	D2_16 = _mm512_madd52lo_epu64(D2_16,a51218,b51218);
	D2_17 = _mm512_madd52hi_epu64(D2_17,a51218,b51218);
	D2_17 = _mm512_madd52lo_epu64(D2_17,a51218,b51219);
	D2_18 = _mm512_madd52hi_epu64(zero,a51218,b51219);

	D2_9 = _mm512_madd52lo_epu64(D2_9,a51219,b51210);
	D2_10 = _mm512_madd52hi_epu64(D2_10,a51219,b51210);
	D2_10 = _mm512_madd52lo_epu64(D2_10,a51219,b51211);
	D2_11 = _mm512_madd52hi_epu64(D2_11,a51219,b51211);
	D2_11 = _mm512_madd52lo_epu64(D2_11,a51219,b51212);
	D2_12 = _mm512_madd52hi_epu64(D2_12,a51219,b51212);
	D2_12 = _mm512_madd52lo_epu64(D2_12,a51219,b51213);
	D2_13 = _mm512_madd52hi_epu64(D2_13,a51219,b51213);
	D2_13 = _mm512_madd52lo_epu64(D2_13,a51219,b51214);
	D2_14 = _mm512_madd52hi_epu64(D2_14,a51219,b51214);
	D2_14 = _mm512_madd52lo_epu64(D2_14,a51219,b51215);
	D2_15 = _mm512_madd52hi_epu64(D2_15,a51219,b51215);
	D2_15 = _mm512_madd52lo_epu64(D2_15,a51219,b51216);
	D2_16 = _mm512_madd52hi_epu64(D2_16,a51219,b51216);
	D2_16 = _mm512_madd52lo_epu64(D2_16,a51219,b51217);
	D2_17 = _mm512_madd52hi_epu64(D2_17,a51219,b51217);
	D2_17 = _mm512_madd52lo_epu64(D2_17,a51219,b51218);
	D2_18 = _mm512_madd52hi_epu64(D2_18,a51219,b51218);
	D2_18 = _mm512_madd52lo_epu64(D2_18,a51219,b51219);
	D2_19 = _mm512_madd52hi_epu64(zero,a51219,b51219);


	// Carry management

	carry  = _mm512_srli_epi64(D2_1,52);
	D2_2 = _mm512_add_epi64(D2_2,carry);
	D2_1 = _mm512_and_si512(D2_1,mask52);
	carry  = _mm512_srli_epi64(D2_2,52);
	D2_3 = _mm512_add_epi64(D2_3,carry);
	D2_2 = _mm512_and_si512(D2_2,mask52);
	carry  = _mm512_srli_epi64(D2_3,52);
	D2_4 = _mm512_add_epi64(D2_4,carry);
	D2_3 = _mm512_and_si512(D2_3,mask52);
	carry  = _mm512_srli_epi64(D2_4,52);
	D2_5 = _mm512_add_epi64(D2_5,carry);
	D2_4 = _mm512_and_si512(D2_4,mask52);
	carry  = _mm512_srli_epi64(D2_5,52);
	D2_6 = _mm512_add_epi64(D2_6,carry);
	D2_5 = _mm512_and_si512(D2_5,mask52);
	carry  = _mm512_srli_epi64(D2_6,52);
	D2_7 = _mm512_add_epi64(D2_7,carry);
	D2_6 = _mm512_and_si512(D2_6,mask52);
	carry  = _mm512_srli_epi64(D2_7,52);
	D2_8 = _mm512_add_epi64(D2_8,carry);
	D2_7 = _mm512_and_si512(D2_7,mask52);
	carry  = _mm512_srli_epi64(D2_8,52);
	D2_9 = _mm512_add_epi64(D2_9,carry);
	D2_8 = _mm512_and_si512(D2_8,mask52);
	carry  = _mm512_srli_epi64(D2_9,52);
	D2_10 = _mm512_add_epi64(D2_10,carry);
	D2_9 = _mm512_and_si512(D2_9,mask52);
	carry  = _mm512_srli_epi64(D2_10,52);
	D2_11 = _mm512_add_epi64(D2_11,carry);
	D2_10 = _mm512_and_si512(D2_10,mask52);
	carry  = _mm512_srli_epi64(D2_11,52);
	D2_12 = _mm512_add_epi64(D2_12,carry);
	D2_11 = _mm512_and_si512(D2_11,mask52);
	carry  = _mm512_srli_epi64(D2_12,52);
	D2_13 = _mm512_add_epi64(D2_13,carry);
	D2_12 = _mm512_and_si512(D2_12,mask52);
	carry  = _mm512_srli_epi64(D2_13,52);
	D2_14 = _mm512_add_epi64(D2_14,carry);
	D2_13 = _mm512_and_si512(D2_13,mask52);
	carry  = _mm512_srli_epi64(D2_14,52);
	D2_15 = _mm512_add_epi64(D2_15,carry);
	D2_14 = _mm512_and_si512(D2_14,mask52);
	carry  = _mm512_srli_epi64(D2_15,52);
	D2_16 = _mm512_add_epi64(D2_16,carry);
	D2_15 = _mm512_and_si512(D2_15,mask52);
	carry  = _mm512_srli_epi64(D2_16,52);
	D2_17 = _mm512_add_epi64(D2_17,carry);
	D2_16 = _mm512_and_si512(D2_16,mask52);
	carry  = _mm512_srli_epi64(D2_17,52);
	D2_18 = _mm512_add_epi64(D2_18,carry);
	D2_17 = _mm512_and_si512(D2_17,mask52);
	carry  = _mm512_srli_epi64(D2_18,52);
	D2_19 = _mm512_add_epi64(D2_19,carry);
	D2_18 = _mm512_and_si512(D2_18,mask52);

	// Conversion in base 2^519

	carry = D2_9>>51;
	D2_10 = (D2_10<<1)|carry;
	D2_9 &= mask51;
	carry = D2_10>>52;
	D2_11 = (D2_11<<1)|carry;
	D2_10 &= mask52;
	carry = D2_11>>52;
	D2_12 = (D2_12<<1)|carry;
	D2_11 &= mask52;
	carry = D2_12>>52;
	D2_13 = (D2_13<<1)|carry;
	D2_12 &= mask52;
	carry = D2_13>>52;
	D2_14 = (D2_14<<1)|carry;
	D2_13 &= mask52;
	carry = D2_14>>52;
	D2_15 = (D2_15<<1)|carry;
	D2_14 &= mask52;
	carry = D2_15>>52;
	D2_16 = (D2_16<<1)|carry;
	D2_15 &= mask52;
	carry = D2_16>>52;
	D2_17 = (D2_17<<1)|carry;
	D2_16 &= mask52;
	carry = D2_17>>52;
	D2_18 = (D2_18<<1)|carry;
	D2_17 &= mask52;
	carry = D2_18>>52;
	D2_19 = (D2_19<<1)|carry;
	D2_18 &= mask52;

	// D1 = (Al+Ah)*(Bl+Bh)

	__m512i D1_0, D1_1;
	__m512i D1_2, D1_3;
	__m512i D1_4, D1_5;
	__m512i D1_6, D1_7;
	__m512i D1_8, D1_9;
	__m512i D1_10, D1_11;
	__m512i D1_12, D1_13;
	__m512i D1_14, D1_15;
	__m512i D1_16, D1_17;
	__m512i D1_18, D1_19;

	__m512i alpah0 = _mm512_add_epi64(a5120,a51210);
	carry = alpah0>>52;
	alpah0 &= mask52;
	__m512i alpah1 = _mm512_add_epi64(a5121,carry);
	alpah1 = _mm512_add_epi64(alpah1,a51211);
	carry = alpah1>>52;
	alpah1 &= mask52;
	__m512i alpah2 = _mm512_add_epi64(a5122,carry);
	alpah2 = _mm512_add_epi64(alpah2,a51212);
	carry = alpah2>>52;
	alpah2 &= mask52;
	__m512i alpah3 = _mm512_add_epi64(a5123,carry);
	alpah3 = _mm512_add_epi64(alpah3,a51213);
	carry = alpah3>>52;
	alpah3 &= mask52;
	__m512i alpah4 = _mm512_add_epi64(a5124,carry);
	alpah4 = _mm512_add_epi64(alpah4,a51214);
	carry = alpah4>>52;
	alpah4 &= mask52;
	__m512i alpah5 = _mm512_add_epi64(a5125,carry);
	alpah5 = _mm512_add_epi64(alpah5,a51215);
	carry = alpah5>>52;
	alpah5 &= mask52;
	__m512i alpah6 = _mm512_add_epi64(a5126,carry);
	alpah6 = _mm512_add_epi64(alpah6,a51216);
	carry = alpah6>>52;
	alpah6 &= mask52;
	__m512i alpah7 = _mm512_add_epi64(a5127,carry);
	alpah7 = _mm512_add_epi64(alpah7,a51217);
	carry = alpah7>>52;
	alpah7 &= mask52;
	__m512i alpah8 = _mm512_add_epi64(a5128,carry);
	alpah8 = _mm512_add_epi64(alpah8,a51218);
	carry = alpah8>>52;
	alpah8 &= mask52;
	__m512i alpah9 = _mm512_add_epi64(a5129,carry);
	alpah9 = _mm512_add_epi64(alpah9,a51219);
	carry = alpah9>>52;
	alpah9 &= mask52;
	__m512i blpbh0 = _mm512_add_epi64(b5120,b51210);
	carry = blpbh0>>52;
	blpbh0 &= mask52;
	__m512i blpbh1 = _mm512_add_epi64(b5121,carry);
	blpbh1 = _mm512_add_epi64(blpbh1,b51211);
	carry = blpbh1>>52;
	blpbh1 &= mask52;
	__m512i blpbh2 = _mm512_add_epi64(b5122,carry);
	blpbh2 = _mm512_add_epi64(blpbh2,b51212);
	carry = blpbh2>>52;
	blpbh2 &= mask52;
	__m512i blpbh3 = _mm512_add_epi64(b5123,carry);
	blpbh3 = _mm512_add_epi64(blpbh3,b51213);
	carry = blpbh3>>52;
	blpbh3 &= mask52;
	__m512i blpbh4 = _mm512_add_epi64(b5124,carry);
	blpbh4 = _mm512_add_epi64(blpbh4,b51214);
	carry = blpbh4>>52;
	blpbh4 &= mask52;
	__m512i blpbh5 = _mm512_add_epi64(b5125,carry);
	blpbh5 = _mm512_add_epi64(blpbh5,b51215);
	carry = blpbh5>>52;
	blpbh5 &= mask52;
	__m512i blpbh6 = _mm512_add_epi64(b5126,carry);
	blpbh6 = _mm512_add_epi64(blpbh6,b51216);
	carry = blpbh6>>52;
	blpbh6 &= mask52;
	__m512i blpbh7 = _mm512_add_epi64(b5127,carry);
	blpbh7 = _mm512_add_epi64(blpbh7,b51217);
	carry = blpbh7>>52;
	blpbh7 &= mask52;
	__m512i blpbh8 = _mm512_add_epi64(b5128,carry);
	blpbh8 = _mm512_add_epi64(blpbh8,b51218);
	carry = blpbh8>>52;
	blpbh8 &= mask52;
	__m512i blpbh9 = _mm512_add_epi64(b5129,carry);
	blpbh9 = _mm512_add_epi64(blpbh9,b51219);
	carry = blpbh9>>52;
	blpbh9 &= mask52;
	D1_0 = _mm512_madd52lo_epu64(D0_10,alpah0,blpbh0);
	D1_1 = _mm512_madd52hi_epu64(D0_11,alpah0,blpbh0);
	D1_1 = _mm512_madd52lo_epu64(D1_1,alpah0,blpbh1);
	D1_2 = _mm512_madd52hi_epu64(D0_12,alpah0,blpbh1);
	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah0,blpbh2);
	D1_3 = _mm512_madd52hi_epu64(D0_13,alpah0,blpbh2);
	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah0,blpbh3);
	D1_4 = _mm512_madd52hi_epu64(D0_14,alpah0,blpbh3);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah0,blpbh4);
	D1_5 = _mm512_madd52hi_epu64(D0_15,alpah0,blpbh4);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah0,blpbh5);
	D1_6 = _mm512_madd52hi_epu64(D0_16,alpah0,blpbh5);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah0,blpbh6);
	D1_7 = _mm512_madd52hi_epu64(D0_17,alpah0,blpbh6);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah0,blpbh7);
	D1_8 = _mm512_madd52hi_epu64(D0_18,alpah0,blpbh7);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah0,blpbh8);
	D1_9 = _mm512_madd52hi_epu64(D0_19,alpah0,blpbh8);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah0,blpbh9);
	D1_10 = _mm512_madd52hi_epu64(zero,alpah0,blpbh9);

	D1_1 = _mm512_madd52lo_epu64(D1_1,alpah1,blpbh0);
	D1_2 = _mm512_madd52hi_epu64(D1_2,alpah1,blpbh0);
	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah1,blpbh1);
	D1_3 = _mm512_madd52hi_epu64(D1_3,alpah1,blpbh1);
	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah1,blpbh2);
	D1_4 = _mm512_madd52hi_epu64(D1_4,alpah1,blpbh2);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah1,blpbh3);
	D1_5 = _mm512_madd52hi_epu64(D1_5,alpah1,blpbh3);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah1,blpbh4);
	D1_6 = _mm512_madd52hi_epu64(D1_6,alpah1,blpbh4);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah1,blpbh5);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah1,blpbh5);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah1,blpbh6);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah1,blpbh6);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah1,blpbh7);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah1,blpbh7);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah1,blpbh8);
	D1_10 = _mm512_madd52hi_epu64(D1_10,alpah1,blpbh8);
	D1_10 = _mm512_madd52lo_epu64(D1_10,alpah1,blpbh9);
	D1_11 = _mm512_madd52hi_epu64(zero,alpah1,blpbh9);

	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah2,blpbh0);
	D1_3 = _mm512_madd52hi_epu64(D1_3,alpah2,blpbh0);
	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah2,blpbh1);
	D1_4 = _mm512_madd52hi_epu64(D1_4,alpah2,blpbh1);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah2,blpbh2);
	D1_5 = _mm512_madd52hi_epu64(D1_5,alpah2,blpbh2);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah2,blpbh3);
	D1_6 = _mm512_madd52hi_epu64(D1_6,alpah2,blpbh3);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah2,blpbh4);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah2,blpbh4);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah2,blpbh5);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah2,blpbh5);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah2,blpbh6);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah2,blpbh6);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah2,blpbh7);
	D1_10 = _mm512_madd52hi_epu64(D1_10,alpah2,blpbh7);
	D1_10 = _mm512_madd52lo_epu64(D1_10,alpah2,blpbh8);
	D1_11 = _mm512_madd52hi_epu64(D1_11,alpah2,blpbh8);
	D1_11 = _mm512_madd52lo_epu64(D1_11,alpah2,blpbh9);
	D1_12 = _mm512_madd52hi_epu64(zero,alpah2,blpbh9);

	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah3,blpbh0);
	D1_4 = _mm512_madd52hi_epu64(D1_4,alpah3,blpbh0);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah3,blpbh1);
	D1_5 = _mm512_madd52hi_epu64(D1_5,alpah3,blpbh1);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah3,blpbh2);
	D1_6 = _mm512_madd52hi_epu64(D1_6,alpah3,blpbh2);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah3,blpbh3);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah3,blpbh3);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah3,blpbh4);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah3,blpbh4);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah3,blpbh5);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah3,blpbh5);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah3,blpbh6);
	D1_10 = _mm512_madd52hi_epu64(D1_10,alpah3,blpbh6);
	D1_10 = _mm512_madd52lo_epu64(D1_10,alpah3,blpbh7);
	D1_11 = _mm512_madd52hi_epu64(D1_11,alpah3,blpbh7);
	D1_11 = _mm512_madd52lo_epu64(D1_11,alpah3,blpbh8);
	D1_12 = _mm512_madd52hi_epu64(D1_12,alpah3,blpbh8);
	D1_12 = _mm512_madd52lo_epu64(D1_12,alpah3,blpbh9);
	D1_13 = _mm512_madd52hi_epu64(zero,alpah3,blpbh9);

	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah4,blpbh0);
	D1_5 = _mm512_madd52hi_epu64(D1_5,alpah4,blpbh0);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah4,blpbh1);
	D1_6 = _mm512_madd52hi_epu64(D1_6,alpah4,blpbh1);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah4,blpbh2);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah4,blpbh2);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah4,blpbh3);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah4,blpbh3);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah4,blpbh4);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah4,blpbh4);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah4,blpbh5);
	D1_10 = _mm512_madd52hi_epu64(D1_10,alpah4,blpbh5);
	D1_10 = _mm512_madd52lo_epu64(D1_10,alpah4,blpbh6);
	D1_11 = _mm512_madd52hi_epu64(D1_11,alpah4,blpbh6);
	D1_11 = _mm512_madd52lo_epu64(D1_11,alpah4,blpbh7);
	D1_12 = _mm512_madd52hi_epu64(D1_12,alpah4,blpbh7);
	D1_12 = _mm512_madd52lo_epu64(D1_12,alpah4,blpbh8);
	D1_13 = _mm512_madd52hi_epu64(D1_13,alpah4,blpbh8);
	D1_13 = _mm512_madd52lo_epu64(D1_13,alpah4,blpbh9);
	D1_14 = _mm512_madd52hi_epu64(zero,alpah4,blpbh9);

	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah5,blpbh0);
	D1_6 = _mm512_madd52hi_epu64(D1_6,alpah5,blpbh0);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah5,blpbh1);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah5,blpbh1);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah5,blpbh2);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah5,blpbh2);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah5,blpbh3);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah5,blpbh3);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah5,blpbh4);
	D1_10 = _mm512_madd52hi_epu64(D1_10,alpah5,blpbh4);
	D1_10 = _mm512_madd52lo_epu64(D1_10,alpah5,blpbh5);
	D1_11 = _mm512_madd52hi_epu64(D1_11,alpah5,blpbh5);
	D1_11 = _mm512_madd52lo_epu64(D1_11,alpah5,blpbh6);
	D1_12 = _mm512_madd52hi_epu64(D1_12,alpah5,blpbh6);
	D1_12 = _mm512_madd52lo_epu64(D1_12,alpah5,blpbh7);
	D1_13 = _mm512_madd52hi_epu64(D1_13,alpah5,blpbh7);
	D1_13 = _mm512_madd52lo_epu64(D1_13,alpah5,blpbh8);
	D1_14 = _mm512_madd52hi_epu64(D1_14,alpah5,blpbh8);
	D1_14 = _mm512_madd52lo_epu64(D1_14,alpah5,blpbh9);
	D1_15 = _mm512_madd52hi_epu64(zero,alpah5,blpbh9);

	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah6,blpbh0);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah6,blpbh0);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah6,blpbh1);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah6,blpbh1);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah6,blpbh2);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah6,blpbh2);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah6,blpbh3);
	D1_10 = _mm512_madd52hi_epu64(D1_10,alpah6,blpbh3);
	D1_10 = _mm512_madd52lo_epu64(D1_10,alpah6,blpbh4);
	D1_11 = _mm512_madd52hi_epu64(D1_11,alpah6,blpbh4);
	D1_11 = _mm512_madd52lo_epu64(D1_11,alpah6,blpbh5);
	D1_12 = _mm512_madd52hi_epu64(D1_12,alpah6,blpbh5);
	D1_12 = _mm512_madd52lo_epu64(D1_12,alpah6,blpbh6);
	D1_13 = _mm512_madd52hi_epu64(D1_13,alpah6,blpbh6);
	D1_13 = _mm512_madd52lo_epu64(D1_13,alpah6,blpbh7);
	D1_14 = _mm512_madd52hi_epu64(D1_14,alpah6,blpbh7);
	D1_14 = _mm512_madd52lo_epu64(D1_14,alpah6,blpbh8);
	D1_15 = _mm512_madd52hi_epu64(D1_15,alpah6,blpbh8);
	D1_15 = _mm512_madd52lo_epu64(D1_15,alpah6,blpbh9);
	D1_16 = _mm512_madd52hi_epu64(zero,alpah6,blpbh9);

	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah7,blpbh0);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah7,blpbh0);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah7,blpbh1);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah7,blpbh1);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah7,blpbh2);
	D1_10 = _mm512_madd52hi_epu64(D1_10,alpah7,blpbh2);
	D1_10 = _mm512_madd52lo_epu64(D1_10,alpah7,blpbh3);
	D1_11 = _mm512_madd52hi_epu64(D1_11,alpah7,blpbh3);
	D1_11 = _mm512_madd52lo_epu64(D1_11,alpah7,blpbh4);
	D1_12 = _mm512_madd52hi_epu64(D1_12,alpah7,blpbh4);
	D1_12 = _mm512_madd52lo_epu64(D1_12,alpah7,blpbh5);
	D1_13 = _mm512_madd52hi_epu64(D1_13,alpah7,blpbh5);
	D1_13 = _mm512_madd52lo_epu64(D1_13,alpah7,blpbh6);
	D1_14 = _mm512_madd52hi_epu64(D1_14,alpah7,blpbh6);
	D1_14 = _mm512_madd52lo_epu64(D1_14,alpah7,blpbh7);
	D1_15 = _mm512_madd52hi_epu64(D1_15,alpah7,blpbh7);
	D1_15 = _mm512_madd52lo_epu64(D1_15,alpah7,blpbh8);
	D1_16 = _mm512_madd52hi_epu64(D1_16,alpah7,blpbh8);
	D1_16 = _mm512_madd52lo_epu64(D1_16,alpah7,blpbh9);
	D1_17 = _mm512_madd52hi_epu64(zero,alpah7,blpbh9);

	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah8,blpbh0);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah8,blpbh0);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah8,blpbh1);
	D1_10 = _mm512_madd52hi_epu64(D1_10,alpah8,blpbh1);
	D1_10 = _mm512_madd52lo_epu64(D1_10,alpah8,blpbh2);
	D1_11 = _mm512_madd52hi_epu64(D1_11,alpah8,blpbh2);
	D1_11 = _mm512_madd52lo_epu64(D1_11,alpah8,blpbh3);
	D1_12 = _mm512_madd52hi_epu64(D1_12,alpah8,blpbh3);
	D1_12 = _mm512_madd52lo_epu64(D1_12,alpah8,blpbh4);
	D1_13 = _mm512_madd52hi_epu64(D1_13,alpah8,blpbh4);
	D1_13 = _mm512_madd52lo_epu64(D1_13,alpah8,blpbh5);
	D1_14 = _mm512_madd52hi_epu64(D1_14,alpah8,blpbh5);
	D1_14 = _mm512_madd52lo_epu64(D1_14,alpah8,blpbh6);
	D1_15 = _mm512_madd52hi_epu64(D1_15,alpah8,blpbh6);
	D1_15 = _mm512_madd52lo_epu64(D1_15,alpah8,blpbh7);
	D1_16 = _mm512_madd52hi_epu64(D1_16,alpah8,blpbh7);
	D1_16 = _mm512_madd52lo_epu64(D1_16,alpah8,blpbh8);
	D1_17 = _mm512_madd52hi_epu64(D1_17,alpah8,blpbh8);
	D1_17 = _mm512_madd52lo_epu64(D1_17,alpah8,blpbh9);
	D1_18 = _mm512_madd52hi_epu64(zero,alpah8,blpbh9);

	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah9,blpbh0);
	D1_10 = _mm512_madd52hi_epu64(D1_10,alpah9,blpbh0);
	D1_10 = _mm512_madd52lo_epu64(D1_10,alpah9,blpbh1);
	D1_11 = _mm512_madd52hi_epu64(D1_11,alpah9,blpbh1);
	D1_11 = _mm512_madd52lo_epu64(D1_11,alpah9,blpbh2);
	D1_12 = _mm512_madd52hi_epu64(D1_12,alpah9,blpbh2);
	D1_12 = _mm512_madd52lo_epu64(D1_12,alpah9,blpbh3);
	D1_13 = _mm512_madd52hi_epu64(D1_13,alpah9,blpbh3);
	D1_13 = _mm512_madd52lo_epu64(D1_13,alpah9,blpbh4);
	D1_14 = _mm512_madd52hi_epu64(D1_14,alpah9,blpbh4);
	D1_14 = _mm512_madd52lo_epu64(D1_14,alpah9,blpbh5);
	D1_15 = _mm512_madd52hi_epu64(D1_15,alpah9,blpbh5);
	D1_15 = _mm512_madd52lo_epu64(D1_15,alpah9,blpbh6);
	D1_16 = _mm512_madd52hi_epu64(D1_16,alpah9,blpbh6);
	D1_16 = _mm512_madd52lo_epu64(D1_16,alpah9,blpbh7);
	D1_17 = _mm512_madd52hi_epu64(D1_17,alpah9,blpbh7);
	D1_17 = _mm512_madd52lo_epu64(D1_17,alpah9,blpbh8);
	D1_18 = _mm512_madd52hi_epu64(D1_18,alpah9,blpbh8);
	D1_18 = _mm512_madd52lo_epu64(D1_18,alpah9,blpbh9);
	D1_19 = _mm512_madd52hi_epu64(zero,alpah9,blpbh9);


	// Carry management

	carry  = _mm512_srli_epi64(D1_0,52);
	D1_0 = _mm512_and_si512(D1_0,mask52);
	D1_1 = _mm512_add_epi64(D1_1,carry);
	carry  = _mm512_srli_epi64(D1_1,52);
	D1_2 = _mm512_add_epi64(D1_2,carry);
	D1_1 = _mm512_and_si512(D1_1,mask52);
	carry  = _mm512_srli_epi64(D1_2,52);
	D1_3 = _mm512_add_epi64(D1_3,carry);
	D1_2 = _mm512_and_si512(D1_2,mask52);
	carry  = _mm512_srli_epi64(D1_3,52);
	D1_4 = _mm512_add_epi64(D1_4,carry);
	D1_3 = _mm512_and_si512(D1_3,mask52);
	carry  = _mm512_srli_epi64(D1_4,52);
	D1_5 = _mm512_add_epi64(D1_5,carry);
	D1_4 = _mm512_and_si512(D1_4,mask52);
	carry  = _mm512_srli_epi64(D1_5,52);
	D1_6 = _mm512_add_epi64(D1_6,carry);
	D1_5 = _mm512_and_si512(D1_5,mask52);
	carry  = _mm512_srli_epi64(D1_6,52);
	D1_7 = _mm512_add_epi64(D1_7,carry);
	D1_6 = _mm512_and_si512(D1_6,mask52);
	carry  = _mm512_srli_epi64(D1_7,52);
	D1_8 = _mm512_add_epi64(D1_8,carry);
	D1_7 = _mm512_and_si512(D1_7,mask52);
	carry  = _mm512_srli_epi64(D1_8,52);
	D1_9 = _mm512_add_epi64(D1_9,carry);
	D1_8 = _mm512_and_si512(D1_8,mask52);
	carry  = _mm512_srli_epi64(D1_9,52);
	D1_10 = _mm512_add_epi64(D1_10,carry);
	D1_9 = _mm512_and_si512(D1_9,mask52);
	carry  = _mm512_srli_epi64(D1_10,52);
	D1_11 = _mm512_add_epi64(D1_11,carry);
	D1_10 = _mm512_and_si512(D1_10,mask52);
	carry  = _mm512_srli_epi64(D1_11,52);
	D1_12 = _mm512_add_epi64(D1_12,carry);
	D1_11 = _mm512_and_si512(D1_11,mask52);
	carry  = _mm512_srli_epi64(D1_12,52);
	D1_13 = _mm512_add_epi64(D1_13,carry);
	D1_12 = _mm512_and_si512(D1_12,mask52);
	carry  = _mm512_srli_epi64(D1_13,52);
	D1_14 = _mm512_add_epi64(D1_14,carry);
	D1_13 = _mm512_and_si512(D1_13,mask52);
	carry  = _mm512_srli_epi64(D1_14,52);
	D1_15 = _mm512_add_epi64(D1_15,carry);
	D1_14 = _mm512_and_si512(D1_14,mask52);
	carry  = _mm512_srli_epi64(D1_15,52);
	D1_16 = _mm512_add_epi64(D1_16,carry);
	D1_15 = _mm512_and_si512(D1_15,mask52);
	carry  = _mm512_srli_epi64(D1_16,52);
	D1_17 = _mm512_add_epi64(D1_17,carry);
	D1_16 = _mm512_and_si512(D1_16,mask52);
	carry  = _mm512_srli_epi64(D1_17,52);
	D1_18 = _mm512_add_epi64(D1_18,carry);
	D1_17 = _mm512_and_si512(D1_17,mask52);
	carry  = _mm512_srli_epi64(D1_18,52);
	D1_19 = _mm512_add_epi64(D1_19,carry);
	D1_18 = _mm512_and_si512(D1_18,mask52);

	// Conversion in base 2^519

	carry  = _mm512_srli_epi64(D1_9,51);
	D1_9 = _mm512_and_si512(D1_9,mask51);// radix 2^519
	D1_10 = _mm512_add_epi64(_mm512_slli_epi64(D1_10,1),carry);
	D1_10 = _mm512_add_epi64(D1_10,D2_0);
	carry = _mm512_srli_epi64(D1_10,52);
	D1_10 = _mm512_and_si512(D1_10,mask52);
	D1_11 = _mm512_add_epi64(_mm512_slli_epi64(D1_11,1),carry);
	D1_11 = _mm512_add_epi64(D1_11,D2_1);
	carry = _mm512_srli_epi64(D1_11,52);
	D1_11 = _mm512_and_si512(D1_11,mask52);
	D1_12 = _mm512_add_epi64(_mm512_slli_epi64(D1_12,1),carry);
	D1_12 = _mm512_add_epi64(D1_12,D2_2);
	carry = _mm512_srli_epi64(D1_12,52);
	D1_12 = _mm512_and_si512(D1_12,mask52);
	D1_13 = _mm512_add_epi64(_mm512_slli_epi64(D1_13,1),carry);
	D1_13 = _mm512_add_epi64(D1_13,D2_3);
	carry = _mm512_srli_epi64(D1_13,52);
	D1_13 = _mm512_and_si512(D1_13,mask52);
	D1_14 = _mm512_add_epi64(_mm512_slli_epi64(D1_14,1),carry);
	D1_14 = _mm512_add_epi64(D1_14,D2_4);
	carry = _mm512_srli_epi64(D1_14,52);
	D1_14 = _mm512_and_si512(D1_14,mask52);
	D1_15 = _mm512_add_epi64(_mm512_slli_epi64(D1_15,1),carry);
	D1_15 = _mm512_add_epi64(D1_15,D2_5);
	carry = _mm512_srli_epi64(D1_15,52);
	D1_15 = _mm512_and_si512(D1_15,mask52);
	D1_16 = _mm512_add_epi64(_mm512_slli_epi64(D1_16,1),carry);
	D1_16 = _mm512_add_epi64(D1_16,D2_6);
	carry = _mm512_srli_epi64(D1_16,52);
	D1_16 = _mm512_and_si512(D1_16,mask52);
	D1_17 = _mm512_add_epi64(_mm512_slli_epi64(D1_17,1),carry);
	D1_17 = _mm512_add_epi64(D1_17,D2_7);
	carry = _mm512_srli_epi64(D1_17,52);
	D1_17 = _mm512_and_si512(D1_17,mask52);
	D1_18 = _mm512_add_epi64(_mm512_slli_epi64(D1_18,1),carry);
	D1_18 = _mm512_add_epi64(D1_18,D2_8);
	carry = _mm512_srli_epi64(D1_18,52);
	D1_18 = _mm512_and_si512(D1_18,mask52);
	D1_19 = _mm512_add_epi64(_mm512_slli_epi64(D1_19,1),carry);
	D1_19 = _mm512_add_epi64(D1_19,D2_9);
	carry  = _mm512_srli_epi64(D1_19,51);
	D1_19 = _mm512_and_si512(D1_19,mask51);// radix 2^519

	// Final reconstruction


	// tmp = D0+D2, radix 2^519

	__m512i tmp0 = _mm512_add_epi64(D0_0,D2_0);
	__m512i carry_tmp  = _mm512_srli_epi64(tmp0,52);
	tmp0 = _mm512_and_si512(tmp0,mask52);

	__m512i tmp1 = _mm512_add_epi64(D0_1,carry_tmp);
	tmp1 = _mm512_add_epi64(tmp1,D2_1);
	carry_tmp  = _mm512_srli_epi64(tmp1,52);
	tmp1 = _mm512_and_si512(tmp1,mask52);

	__m512i tmp2 = _mm512_add_epi64(D0_2,carry_tmp);
	tmp2 = _mm512_add_epi64(tmp2,D2_2);
	carry_tmp  = _mm512_srli_epi64(tmp2,52);
	tmp2 = _mm512_and_si512(tmp2,mask52);

	__m512i tmp3 = _mm512_add_epi64(D0_3,carry_tmp);
	tmp3 = _mm512_add_epi64(tmp3,D2_3);
	carry_tmp  = _mm512_srli_epi64(tmp3,52);
	tmp3 = _mm512_and_si512(tmp3,mask52);

	__m512i tmp4 = _mm512_add_epi64(D0_4,carry_tmp);
	tmp4 = _mm512_add_epi64(tmp4,D2_4);
	carry_tmp  = _mm512_srli_epi64(tmp4,52);
	tmp4 = _mm512_and_si512(tmp4,mask52);

	__m512i tmp5 = _mm512_add_epi64(D0_5,carry_tmp);
	tmp5 = _mm512_add_epi64(tmp5,D2_5);
	carry_tmp  = _mm512_srli_epi64(tmp5,52);
	tmp5 = _mm512_and_si512(tmp5,mask52);

	__m512i tmp6 = _mm512_add_epi64(D0_6,carry_tmp);
	tmp6 = _mm512_add_epi64(tmp6,D2_6);
	carry_tmp  = _mm512_srli_epi64(tmp6,52);
	tmp6 = _mm512_and_si512(tmp6,mask52);

	__m512i tmp7 = _mm512_add_epi64(D0_7,carry_tmp);
	tmp7 = _mm512_add_epi64(tmp7,D2_7);
	carry_tmp  = _mm512_srli_epi64(tmp7,52);
	tmp7 = _mm512_and_si512(tmp7,mask52);

	__m512i tmp8 = _mm512_add_epi64(D0_8,carry_tmp);
	tmp8 = _mm512_add_epi64(tmp8,D2_8);
	carry_tmp  = _mm512_srli_epi64(tmp8,52);
	tmp8 = _mm512_and_si512(tmp8,mask52);

	__m512i tmp9 = _mm512_add_epi64(D0_9,carry_tmp);
	tmp9 = _mm512_add_epi64(tmp9,D2_9);
	carry_tmp  = _mm512_srli_epi64(tmp9,51);
	tmp9 = _mm512_and_si512(tmp9,mask51);// radix 2**519

	__m512i tmp10 = _mm512_add_epi64(D0_10,carry_tmp);
	tmp10 = _mm512_add_epi64(tmp10,D2_10);
	carry_tmp  = _mm512_srli_epi64(tmp10,52);
	tmp10 = _mm512_and_si512(tmp10,mask52);

	__m512i tmp11 = _mm512_add_epi64(D0_11,carry_tmp);
	tmp11 = _mm512_add_epi64(tmp11,D2_11);
	carry_tmp  = _mm512_srli_epi64(tmp11,52);
	tmp11 = _mm512_and_si512(tmp11,mask52);

	__m512i tmp12 = _mm512_add_epi64(D0_12,carry_tmp);
	tmp12 = _mm512_add_epi64(tmp12,D2_12);
	carry_tmp  = _mm512_srli_epi64(tmp12,52);
	tmp12 = _mm512_and_si512(tmp12,mask52);

	__m512i tmp13 = _mm512_add_epi64(D0_13,carry_tmp);
	tmp13 = _mm512_add_epi64(tmp13,D2_13);
	carry_tmp  = _mm512_srli_epi64(tmp13,52);
	tmp13 = _mm512_and_si512(tmp13,mask52);

	__m512i tmp14 = _mm512_add_epi64(D0_14,carry_tmp);
	tmp14 = _mm512_add_epi64(tmp14,D2_14);
	carry_tmp  = _mm512_srli_epi64(tmp14,52);
	tmp14 = _mm512_and_si512(tmp14,mask52);

	__m512i tmp15 = _mm512_add_epi64(D0_15,carry_tmp);
	tmp15 = _mm512_add_epi64(tmp15,D2_15);
	carry_tmp  = _mm512_srli_epi64(tmp15,52);
	tmp15 = _mm512_and_si512(tmp15,mask52);

	__m512i tmp16 = _mm512_add_epi64(D0_16,carry_tmp);
	tmp16 = _mm512_add_epi64(tmp16,D2_16);
	carry_tmp  = _mm512_srli_epi64(tmp16,52);
	tmp16 = _mm512_and_si512(tmp16,mask52);

	__m512i tmp17 = _mm512_add_epi64(D0_17,carry_tmp);
	tmp17 = _mm512_add_epi64(tmp17,D2_17);
	carry_tmp  = _mm512_srli_epi64(tmp17,52);
	tmp17 = _mm512_and_si512(tmp17,mask52);

	__m512i tmp18 = _mm512_add_epi64(D0_18,carry_tmp);
	tmp18 = _mm512_add_epi64(tmp18,D2_18);
	carry_tmp  = _mm512_srli_epi64(tmp18,52);
	tmp18 = _mm512_and_si512(tmp18,mask52);

	__m512i tmp19 = _mm512_add_epi64(D0_19,carry_tmp);
	tmp19 = _mm512_add_epi64(tmp19,D2_19);
	carry_tmp  = _mm512_srli_epi64(tmp19,51);
	tmp19 = _mm512_and_si512(tmp19,mask51);// radix 2**519




	// D1 = D1 -tmp, radix 2^519

	__m512i c51210 = _mm512_load_epi64(c512+10);
	__m512i c51211 = _mm512_load_epi64(c512+11);
	__m512i c51212 = _mm512_load_epi64(c512+12);
	__m512i c51213 = _mm512_load_epi64(c512+13);
	__m512i c51214 = _mm512_load_epi64(c512+14);
	__m512i c51215 = _mm512_load_epi64(c512+15);
	__m512i c51216 = _mm512_load_epi64(c512+16);
	__m512i c51217 = _mm512_load_epi64(c512+17);
	__m512i c51218 = _mm512_load_epi64(c512+18);
	__m512i c51219 = _mm512_load_epi64(c512+19);
	D1_0 = _mm512_add_epi64(c51210,D1_0);
	D1_0 = _mm512_sub_epi64(D1_0,tmp0);
	__m512i borrow = _mm512_srli_epi64(D1_0,52)&un;
	D1_0 = _mm512_and_si512(D1_0,mask52);

	borrow = _mm512_add_epi64(tmp1,borrow);
	D1_1 = _mm512_add_epi64(c51211,D1_1);
	D1_1 = _mm512_sub_epi64(D1_1,borrow);
	borrow  = _mm512_srli_epi64(D1_1,52)&un;
	D1_1 = _mm512_and_si512(D1_1,mask52);

	borrow = _mm512_add_epi64(tmp2,borrow);
	D1_2 = _mm512_add_epi64(c51212,D1_2);
	D1_2 = _mm512_sub_epi64(D1_2,borrow);
	borrow  = _mm512_srli_epi64(D1_2,52)&un;
	D1_2 = _mm512_and_si512(D1_2,mask52);

	borrow = _mm512_add_epi64(tmp3,borrow);
	D1_3 = _mm512_add_epi64(c51213,D1_3);
	D1_3 = _mm512_sub_epi64(D1_3,borrow);
	borrow  = _mm512_srli_epi64(D1_3,52)&un;
	D1_3 = _mm512_and_si512(D1_3,mask52);

	borrow = _mm512_add_epi64(tmp4,borrow);
	D1_4 = _mm512_add_epi64(c51214,D1_4);
	D1_4 = _mm512_sub_epi64(D1_4,borrow);
	borrow  = _mm512_srli_epi64(D1_4,52)&un;
	D1_4 = _mm512_and_si512(D1_4,mask52);

	borrow = _mm512_add_epi64(tmp5,borrow);
	D1_5 = _mm512_add_epi64(c51215,D1_5);
	D1_5 = _mm512_sub_epi64(D1_5,borrow);
	borrow  = _mm512_srli_epi64(D1_5,52)&un;
	D1_5 = _mm512_and_si512(D1_5,mask52);

	borrow = _mm512_add_epi64(tmp6,borrow);
	D1_6 = _mm512_add_epi64(c51216,D1_6);
	D1_6 = _mm512_sub_epi64(D1_6,borrow);
	borrow  = _mm512_srli_epi64(D1_6,52)&un;
	D1_6 = _mm512_and_si512(D1_6,mask52);

	borrow = _mm512_add_epi64(tmp7,borrow);
	D1_7 = _mm512_add_epi64(c51217,D1_7);
	D1_7 = _mm512_sub_epi64(D1_7,borrow);
	borrow  = _mm512_srli_epi64(D1_7,52)&un;
	D1_7 = _mm512_and_si512(D1_7,mask52);

	borrow = _mm512_add_epi64(tmp8,borrow);
	D1_8 = _mm512_add_epi64(c51218,D1_8);
	D1_8 = _mm512_sub_epi64(D1_8,borrow);
	borrow  = _mm512_srli_epi64(D1_8,52)&un;
	D1_8 = _mm512_and_si512(D1_8,mask52);

	borrow = _mm512_add_epi64(tmp9,borrow);
	D1_9 = _mm512_add_epi64(c51219,D1_9);
	D1_9 = _mm512_sub_epi64(D1_9,borrow);
	borrow = _mm512_srli_epi64(D1_9,51)&un;
	D1_9 = _mm512_and_si512(D1_9,mask51);// radix 2**519

	borrow = _mm512_add_epi64(tmp10,borrow);
	D1_10 = _mm512_sub_epi64(D1_10,borrow);
	borrow  = _mm512_srli_epi64(D1_10,52)&un;
	D1_10 = _mm512_and_si512(D1_10,mask52);

	borrow = _mm512_add_epi64(tmp11,borrow);
	D1_11 = _mm512_sub_epi64(D1_11,borrow);
	borrow  = _mm512_srli_epi64(D1_11,52)&un;
	D1_11 = _mm512_and_si512(D1_11,mask52);

	borrow = _mm512_add_epi64(tmp12,borrow);
	D1_12 = _mm512_sub_epi64(D1_12,borrow);
	borrow  = _mm512_srli_epi64(D1_12,52)&un;
	D1_12 = _mm512_and_si512(D1_12,mask52);

	borrow = _mm512_add_epi64(tmp13,borrow);
	D1_13 = _mm512_sub_epi64(D1_13,borrow);
	borrow  = _mm512_srli_epi64(D1_13,52)&un;
	D1_13 = _mm512_and_si512(D1_13,mask52);

	borrow = _mm512_add_epi64(tmp14,borrow);
	D1_14 = _mm512_sub_epi64(D1_14,borrow);
	borrow  = _mm512_srli_epi64(D1_14,52)&un;
	D1_14 = _mm512_and_si512(D1_14,mask52);

	borrow = _mm512_add_epi64(tmp15,borrow);
	D1_15 = _mm512_sub_epi64(D1_15,borrow);
	borrow  = _mm512_srli_epi64(D1_15,52)&un;
	D1_15 = _mm512_and_si512(D1_15,mask52);

	borrow = _mm512_add_epi64(tmp16,borrow);
	D1_16 = _mm512_sub_epi64(D1_16,borrow);
	borrow  = _mm512_srli_epi64(D1_16,52)&un;
	D1_16 = _mm512_and_si512(D1_16,mask52);

	borrow = _mm512_add_epi64(tmp17,borrow);
	D1_17 = _mm512_sub_epi64(D1_17,borrow);
	borrow  = _mm512_srli_epi64(D1_17,52)&un;
	D1_17 = _mm512_and_si512(D1_17,mask52);

	borrow = _mm512_add_epi64(tmp18,borrow);
	D1_18 = _mm512_sub_epi64(D1_18,borrow);
	borrow  = _mm512_srli_epi64(D1_18,52)&un;
	D1_18 = _mm512_and_si512(D1_18,mask52);

	borrow = _mm512_add_epi64(tmp19,borrow);
	D1_19 = _mm512_sub_epi64(D1_19,borrow);
	borrow = _mm512_srli_epi64(D1_19,51)&un;
	D1_19 = _mm512_and_si512(D1_19,mask51);// radix 2**519


	// Final borrows

	borrow = _mm512_add_epi64(carry_tmp,borrow);
	D2_10 = _mm512_add_epi64(D2_10,carry);
	D2_10 = _mm512_sub_epi64(D2_10,borrow);
	borrow  = _mm512_srli_epi64(D2_10,52)&un;
	D2_10 = _mm512_and_si512(D2_10,mask52);

	D2_11 = _mm512_sub_epi64(D2_11,borrow);
	borrow  = _mm512_srli_epi64(D2_11,52)&un;
	D2_11 = _mm512_and_si512(D2_11,mask52);

	D2_12 = _mm512_sub_epi64(D2_12,borrow);
	borrow  = _mm512_srli_epi64(D2_12,52)&un;
	D2_12 = _mm512_and_si512(D2_12,mask52);

	D2_13 = _mm512_sub_epi64(D2_13,borrow);
	borrow  = _mm512_srli_epi64(D2_13,52)&un;
	D2_13 = _mm512_and_si512(D2_13,mask52);

	D2_14 = _mm512_sub_epi64(D2_14,borrow);
	borrow  = _mm512_srli_epi64(D2_14,52)&un;
	D2_14 = _mm512_and_si512(D2_14,mask52);

	D2_15 = _mm512_sub_epi64(D2_15,borrow);
	borrow  = _mm512_srli_epi64(D2_15,52)&un;
	D2_15 = _mm512_and_si512(D2_15,mask52);

	D2_16 = _mm512_sub_epi64(D2_16,borrow);
	borrow  = _mm512_srli_epi64(D2_16,52)&un;
	D2_16 = _mm512_and_si512(D2_16,mask52);

	D2_17 = _mm512_sub_epi64(D2_17,borrow);
	borrow  = _mm512_srli_epi64(D2_17,52)&un;
	D2_17 = _mm512_and_si512(D2_17,mask52);

	D2_18 = _mm512_sub_epi64(D2_18,borrow);
	borrow  = _mm512_srli_epi64(D2_18,52)&un;
	D2_18 = _mm512_and_si512(D2_18,mask52);

	D2_19 = _mm512_sub_epi64(D2_19,borrow);


	_mm512_store_epi64(out+0,D0_0);
	_mm512_store_epi64(out+1,D0_1);
	_mm512_store_epi64(out+2,D0_2);
	_mm512_store_epi64(out+3,D0_3);
	_mm512_store_epi64(out+4,D0_4);
	_mm512_store_epi64(out+5,D0_5);
	_mm512_store_epi64(out+6,D0_6);
	_mm512_store_epi64(out+7,D0_7);
	_mm512_store_epi64(out+8,D0_8);
	_mm512_store_epi64(out+9,D0_9);
	_mm512_store_epi64(out+10,D1_0);
	_mm512_store_epi64(out+11,D1_1);
	_mm512_store_epi64(out+12,D1_2);
	_mm512_store_epi64(out+13,D1_3);
	_mm512_store_epi64(out+14,D1_4);
	_mm512_store_epi64(out+15,D1_5);
	_mm512_store_epi64(out+16,D1_6);
	_mm512_store_epi64(out+17,D1_7);
	_mm512_store_epi64(out+18,D1_8);
	_mm512_store_epi64(out+19,D1_9);
	_mm512_store_epi64(out+20,D1_10);
	_mm512_store_epi64(out+21,D1_11);
	_mm512_store_epi64(out+22,D1_12);
	_mm512_store_epi64(out+23,D1_13);
	_mm512_store_epi64(out+24,D1_14);
	_mm512_store_epi64(out+25,D1_15);
	_mm512_store_epi64(out+26,D1_16);
	_mm512_store_epi64(out+27,D1_17);
	_mm512_store_epi64(out+28,D1_18);
	_mm512_store_epi64(out+29,D1_19);
	_mm512_store_epi64(out+30,D2_10);
	_mm512_store_epi64(out+31,D2_11);
	_mm512_store_epi64(out+32,D2_12);
	_mm512_store_epi64(out+33,D2_13);
	_mm512_store_epi64(out+34,D2_14);
	_mm512_store_epi64(out+35,D2_15);
	_mm512_store_epi64(out+36,D2_16);
	_mm512_store_epi64(out+37,D2_17);
	_mm512_store_epi64(out+38,D2_18);
	_mm512_store_epi64(out+39,D2_19);

}

/* Karatsuba squaring */

inline void force_inline square512_8_1038K(__m512i out[40], __m512i a512[20])
{

	// D0 = Al^2

	__m512i D0_0, D0_1;
	__m512i D0_2, D0_3;
	__m512i D0_4, D0_5;
	__m512i D0_6, D0_7;
	__m512i D0_8, D0_9;
	__m512i D0_10, D0_11;
	__m512i D0_12, D0_13;
	__m512i D0_14, D0_15;
	__m512i D0_16, D0_17;
	__m512i D0_18, D0_19;
	__m512i a5120 = _mm512_load_epi64(a512);
	__m512i a5121 = _mm512_load_epi64(a512+1);
	__m512i a5122 = _mm512_load_epi64(a512+2);
	__m512i a5123 = _mm512_load_epi64(a512+3);
	__m512i a5124 = _mm512_load_epi64(a512+4);
	__m512i a5125 = _mm512_load_epi64(a512+5);
	__m512i a5126 = _mm512_load_epi64(a512+6);
	__m512i a5127 = _mm512_load_epi64(a512+7);
	__m512i a5128 = _mm512_load_epi64(a512+8);
	__m512i a5129 = _mm512_load_epi64(a512+9);

	D0_0 = _mm512_madd52lo_epu64(zero,a5120,a5120);

	D0_1 = _mm512_madd52lo_epu64(zero,a5120,a5121);
	D0_1 = _mm512_slli_epi64(D0_1,1);
	D0_1 = _mm512_madd52hi_epu64(D0_1,a5120,a5120);
	__m512i carry  = _mm512_srli_epi64(D0_1,52);
	D0_1 = _mm512_and_si512(D0_1,mask52);

	D0_2 = _mm512_madd52hi_epu64(zero,a5120,a5121);
	D0_2 = _mm512_madd52lo_epu64(D0_2,a5120,a5122);
	D0_2 = _mm512_slli_epi64(D0_2,1);
	D0_2 = _mm512_madd52lo_epu64(D0_2,a5121,a5121);
	D0_2 = _mm512_add_epi64(D0_2,carry);
	carry  = _mm512_srli_epi64(D0_2,52);
	D0_2 = _mm512_and_si512(D0_2,mask52);

	D0_3 = _mm512_madd52hi_epu64(zero,a5120,a5122);
	D0_3 = _mm512_madd52lo_epu64(D0_3,a5120,a5123);
	D0_3 = _mm512_madd52lo_epu64(D0_3,a5121,a5122);
	D0_3 = _mm512_slli_epi64(D0_3,1);
	D0_3 = _mm512_madd52hi_epu64(D0_3,a5121,a5121);
	D0_3 = _mm512_add_epi64(D0_3,carry);
	carry  = _mm512_srli_epi64(D0_3,52);
	D0_3 = _mm512_and_si512(D0_3,mask52);

	D0_4 = _mm512_madd52hi_epu64(zero,a5120,a5123);
	D0_4 = _mm512_madd52hi_epu64(D0_4,a5121,a5122);
	D0_4 = _mm512_madd52lo_epu64(D0_4,a5120,a5124);
	D0_4 = _mm512_madd52lo_epu64(D0_4,a5121,a5123);
	D0_4 = _mm512_slli_epi64(D0_4,1);
	D0_4 = _mm512_madd52lo_epu64(D0_4,a5122,a5122);
	D0_4 = _mm512_add_epi64(D0_4,carry);
	carry  = _mm512_srli_epi64(D0_4,52);
	D0_4 = _mm512_and_si512(D0_4,mask52);

	D0_5 = _mm512_madd52hi_epu64(zero,a5120,a5124);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5121,a5123);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5120,a5125);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5121,a5124);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5122,a5123);
	D0_5 = _mm512_slli_epi64(D0_5,1);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5122,a5122);
	D0_5 = _mm512_add_epi64(D0_5,carry);
	carry  = _mm512_srli_epi64(D0_5,52);
	D0_5 = _mm512_and_si512(D0_5,mask52);

	D0_6 = _mm512_madd52hi_epu64(zero,a5120,a5125);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5121,a5124);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5122,a5123);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5120,a5126);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5121,a5125);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5122,a5124);
	D0_6 = _mm512_slli_epi64(D0_6,1);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5123,a5123);
	D0_6 = _mm512_add_epi64(D0_6,carry);
	carry  = _mm512_srli_epi64(D0_6,52);
	D0_6 = _mm512_and_si512(D0_6,mask52);

	D0_7 = _mm512_madd52hi_epu64(zero,a5120,a5126);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5121,a5125);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5122,a5124);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5120,a5127);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5121,a5126);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5122,a5125);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5123,a5124);
	D0_7 = _mm512_slli_epi64(D0_7,1);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5123,a5123);
	D0_7 = _mm512_add_epi64(D0_7,carry);
	carry  = _mm512_srli_epi64(D0_7,52);
	D0_7 = _mm512_and_si512(D0_7,mask52);

	D0_8 = _mm512_madd52hi_epu64(zero,a5120,a5127);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5121,a5126);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5122,a5125);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5123,a5124);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5120,a5128);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5121,a5127);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5122,a5126);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5123,a5125);
	D0_8 = _mm512_slli_epi64(D0_8,1);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5124,a5124);
	D0_8 = _mm512_add_epi64(D0_8,carry);
	carry  = _mm512_srli_epi64(D0_8,52);
	D0_8 = _mm512_and_si512(D0_8,mask52);

	D0_9 = _mm512_madd52hi_epu64(zero,a5120,a5128);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5121,a5127);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5122,a5126);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5123,a5125);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5120,a5129);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5121,a5128);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5122,a5127);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5123,a5126);
	D0_9 = _mm512_madd52lo_epu64(D0_9,a5124,a5125);
	D0_9 = _mm512_slli_epi64(D0_9,1);
	D0_9 = _mm512_madd52hi_epu64(D0_9,a5124,a5124);
	D0_9 = _mm512_add_epi64(D0_9,carry);
	carry  = _mm512_srli_epi64(D0_9,52);
	D0_9 = _mm512_and_si512(D0_9,mask52);

	D0_10 = _mm512_madd52hi_epu64(zero,a5120,a5129);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5121,a5128);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5122,a5127);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5123,a5126);
	D0_10 = _mm512_madd52hi_epu64(D0_10,a5124,a5125);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5121,a5129);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5122,a5128);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5123,a5127);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5124,a5126);
	D0_10 = _mm512_slli_epi64(D0_10,1);
	D0_10 = _mm512_madd52lo_epu64(D0_10,a5125,a5125);
	D0_10 = _mm512_add_epi64(D0_10,carry);
	carry  = _mm512_srli_epi64(D0_10,52);
	D0_10 = _mm512_and_si512(D0_10,mask52);

	D0_11 = _mm512_madd52hi_epu64(zero,a5121,a5129);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5122,a5128);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5123,a5127);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5124,a5126);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5122,a5129);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5123,a5128);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5124,a5127);
	D0_11 = _mm512_madd52lo_epu64(D0_11,a5125,a5126);
	D0_11 = _mm512_slli_epi64(D0_11,1);
	D0_11 = _mm512_madd52hi_epu64(D0_11,a5125,a5125);
	D0_11 = _mm512_add_epi64(D0_11,carry);
	carry  = _mm512_srli_epi64(D0_11,52);
	D0_11 = _mm512_and_si512(D0_11,mask52);

	D0_12 = _mm512_madd52hi_epu64(zero,a5122,a5129);
	D0_12 = _mm512_madd52hi_epu64(D0_12,a5123,a5128);
	D0_12 = _mm512_madd52hi_epu64(D0_12,a5124,a5127);
	D0_12 = _mm512_madd52hi_epu64(D0_12,a5125,a5126);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5123,a5129);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5124,a5128);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5125,a5127);
	D0_12 = _mm512_slli_epi64(D0_12,1);
	D0_12 = _mm512_madd52lo_epu64(D0_12,a5126,a5126);
	D0_12 = _mm512_add_epi64(D0_12,carry);
	carry  = _mm512_srli_epi64(D0_12,52);
	D0_12 = _mm512_and_si512(D0_12,mask52);

	D0_13 = _mm512_madd52hi_epu64(zero,a5123,a5129);
	D0_13 = _mm512_madd52hi_epu64(D0_13,a5124,a5128);
	D0_13 = _mm512_madd52hi_epu64(D0_13,a5125,a5127);
	D0_13 = _mm512_madd52lo_epu64(D0_13,a5124,a5129);
	D0_13 = _mm512_madd52lo_epu64(D0_13,a5125,a5128);
	D0_13 = _mm512_madd52lo_epu64(D0_13,a5126,a5127);
	D0_13 = _mm512_slli_epi64(D0_13,1);
	D0_13 = _mm512_madd52hi_epu64(D0_13,a5126,a5126);
	D0_13 = _mm512_add_epi64(D0_13,carry);
	carry  = _mm512_srli_epi64(D0_13,52);
	D0_13 = _mm512_and_si512(D0_13,mask52);

	D0_14 = _mm512_madd52hi_epu64(zero,a5124,a5129);
	D0_14 = _mm512_madd52hi_epu64(D0_14,a5125,a5128);
	D0_14 = _mm512_madd52hi_epu64(D0_14,a5126,a5127);
	D0_14 = _mm512_madd52lo_epu64(D0_14,a5125,a5129);
	D0_14 = _mm512_madd52lo_epu64(D0_14,a5126,a5128);
	D0_14 = _mm512_slli_epi64(D0_14,1);
	D0_14 = _mm512_madd52lo_epu64(D0_14,a5127,a5127);
	D0_14 = _mm512_add_epi64(D0_14,carry);
	carry  = _mm512_srli_epi64(D0_14,52);
	D0_14 = _mm512_and_si512(D0_14,mask52);

	D0_15 = _mm512_madd52hi_epu64(zero,a5125,a5129);
	D0_15 = _mm512_madd52hi_epu64(D0_15,a5126,a5128);
	D0_15 = _mm512_madd52lo_epu64(D0_15,a5126,a5129);
	D0_15 = _mm512_madd52lo_epu64(D0_15,a5127,a5128);
	D0_15 = _mm512_slli_epi64(D0_15,1);
	D0_15 = _mm512_madd52hi_epu64(D0_15,a5127,a5127);
	D0_15 = _mm512_add_epi64(D0_15,carry);
	carry  = _mm512_srli_epi64(D0_15,52);
	D0_15 = _mm512_and_si512(D0_15,mask52);

	D0_16 = _mm512_madd52hi_epu64(zero,a5126,a5129);
	D0_16 = _mm512_madd52hi_epu64(D0_16,a5127,a5128);
	D0_16 = _mm512_madd52lo_epu64(D0_16,a5127,a5129);
	D0_16 = _mm512_slli_epi64(D0_16,1);
	D0_16 = _mm512_madd52lo_epu64(D0_16,a5128,a5128);
	D0_16 = _mm512_add_epi64(D0_16,carry);
	carry  = _mm512_srli_epi64(D0_16,52);
	D0_16 = _mm512_and_si512(D0_16,mask52);

	D0_17 = _mm512_madd52hi_epu64(zero,a5127,a5129);
	D0_17 = _mm512_madd52lo_epu64(D0_17,a5128,a5129);
	D0_17 = _mm512_slli_epi64(D0_17,1);
	D0_17 = _mm512_madd52hi_epu64(D0_17,a5128,a5128);
	D0_17 = _mm512_add_epi64(D0_17,carry);
	carry  = _mm512_srli_epi64(D0_17,52);
	D0_17 = _mm512_and_si512(D0_17,mask52);

	D0_18 = _mm512_madd52hi_epu64(zero,a5128,a5129);
	D0_18 = _mm512_slli_epi64(D0_18,1);
	D0_18 = _mm512_madd52lo_epu64(D0_18,a5129,a5129);
	D0_18 = _mm512_add_epi64(D0_18,carry);
	carry  = _mm512_srli_epi64(D0_18,52);
	D0_18 = _mm512_and_si512(D0_18,mask52);

	D0_19 = _mm512_madd52hi_epu64(carry,a5129,a5129);


	// Conversion in base 2^519

	carry = D0_9>>51;
	D0_10 = (D0_10<<1)|carry;
	D0_9 &= mask51;
	carry = D0_10>>52;
	D0_11 = (D0_11<<1)|carry;
	D0_10 &= mask52;
	carry = D0_11>>52;
	D0_12 = (D0_12<<1)|carry;
	D0_11 &= mask52;
	carry = D0_12>>52;
	D0_13 = (D0_13<<1)|carry;
	D0_12 &= mask52;
	carry = D0_13>>52;
	D0_14 = (D0_14<<1)|carry;
	D0_13 &= mask52;
	carry = D0_14>>52;
	D0_15 = (D0_15<<1)|carry;
	D0_14 &= mask52;
	carry = D0_15>>52;
	D0_16 = (D0_16<<1)|carry;
	D0_15 &= mask52;
	carry = D0_16>>52;
	D0_17 = (D0_17<<1)|carry;
	D0_16 &= mask52;
	carry = D0_17>>52;
	D0_18 = (D0_18<<1)|carry;
	D0_17 &= mask52;
	carry = D0_18>>52;
	D0_19 = (D0_19<<1)|carry;
	D0_18 &= mask52;

	// D2 = Ah^2

	__m512i D2_0, D2_1;
	__m512i D2_2, D2_3;
	__m512i D2_4, D2_5;
	__m512i D2_6, D2_7;
	__m512i D2_8, D2_9;
	__m512i D2_10, D2_11;
	__m512i D2_12, D2_13;
	__m512i D2_14, D2_15;
	__m512i D2_16, D2_17;
	__m512i D2_18, D2_19;
	__m512i a51210 = _mm512_load_epi64(a512+10);
	__m512i a51211 = _mm512_load_epi64(a512+11);
	__m512i a51212 = _mm512_load_epi64(a512+12);
	__m512i a51213 = _mm512_load_epi64(a512+13);
	__m512i a51214 = _mm512_load_epi64(a512+14);
	__m512i a51215 = _mm512_load_epi64(a512+15);
	__m512i a51216 = _mm512_load_epi64(a512+16);
	__m512i a51217 = _mm512_load_epi64(a512+17);
	__m512i a51218 = _mm512_load_epi64(a512+18);
	__m512i a51219 = _mm512_load_epi64(a512+19);

	D2_0 = _mm512_madd52lo_epu64(zero,a51210,a51210);

	D2_1 = _mm512_madd52lo_epu64(zero,a51210,a51211);
	D2_1 = _mm512_slli_epi64(D2_1,1);
	D2_1 = _mm512_madd52hi_epu64(D2_1,a51210,a51210);
	carry  = _mm512_srli_epi64(D2_1,52);
	D2_1 = _mm512_and_si512(D2_1,mask52);

	D2_2 = _mm512_madd52hi_epu64(zero,a51210,a51211);
	D2_2 = _mm512_madd52lo_epu64(D2_2,a51210,a51212);
	D2_2 = _mm512_slli_epi64(D2_2,1);
	D2_2 = _mm512_madd52lo_epu64(D2_2,a51211,a51211);
	D2_2 = _mm512_add_epi64(D2_2,carry);
	carry  = _mm512_srli_epi64(D2_2,52);
	D2_2 = _mm512_and_si512(D2_2,mask52);

	D2_3 = _mm512_madd52hi_epu64(zero,a51210,a51212);
	D2_3 = _mm512_madd52lo_epu64(D2_3,a51210,a51213);
	D2_3 = _mm512_madd52lo_epu64(D2_3,a51211,a51212);
	D2_3 = _mm512_slli_epi64(D2_3,1);
	D2_3 = _mm512_madd52hi_epu64(D2_3,a51211,a51211);
	D2_3 = _mm512_add_epi64(D2_3,carry);
	carry  = _mm512_srli_epi64(D2_3,52);
	D2_3 = _mm512_and_si512(D2_3,mask52);

	D2_4 = _mm512_madd52hi_epu64(zero,a51210,a51213);
	D2_4 = _mm512_madd52hi_epu64(D2_4,a51211,a51212);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a51210,a51214);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a51211,a51213);
	D2_4 = _mm512_slli_epi64(D2_4,1);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a51212,a51212);
	D2_4 = _mm512_add_epi64(D2_4,carry);
	carry  = _mm512_srli_epi64(D2_4,52);
	D2_4 = _mm512_and_si512(D2_4,mask52);

	D2_5 = _mm512_madd52hi_epu64(zero,a51210,a51214);
	D2_5 = _mm512_madd52hi_epu64(D2_5,a51211,a51213);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a51210,a51215);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a51211,a51214);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a51212,a51213);
	D2_5 = _mm512_slli_epi64(D2_5,1);
	D2_5 = _mm512_madd52hi_epu64(D2_5,a51212,a51212);
	D2_5 = _mm512_add_epi64(D2_5,carry);
	carry  = _mm512_srli_epi64(D2_5,52);
	D2_5 = _mm512_and_si512(D2_5,mask52);

	D2_6 = _mm512_madd52hi_epu64(zero,a51210,a51215);
	D2_6 = _mm512_madd52hi_epu64(D2_6,a51211,a51214);
	D2_6 = _mm512_madd52hi_epu64(D2_6,a51212,a51213);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a51210,a51216);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a51211,a51215);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a51212,a51214);
	D2_6 = _mm512_slli_epi64(D2_6,1);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a51213,a51213);
	D2_6 = _mm512_add_epi64(D2_6,carry);
	carry  = _mm512_srli_epi64(D2_6,52);
	D2_6 = _mm512_and_si512(D2_6,mask52);

	D2_7 = _mm512_madd52hi_epu64(zero,a51210,a51216);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a51211,a51215);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a51212,a51214);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51210,a51217);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51211,a51216);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51212,a51215);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a51213,a51214);
	D2_7 = _mm512_slli_epi64(D2_7,1);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a51213,a51213);
	D2_7 = _mm512_add_epi64(D2_7,carry);
	carry  = _mm512_srli_epi64(D2_7,52);
	D2_7 = _mm512_and_si512(D2_7,mask52);

	D2_8 = _mm512_madd52hi_epu64(zero,a51210,a51217);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a51211,a51216);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a51212,a51215);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a51213,a51214);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51210,a51218);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51211,a51217);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51212,a51216);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51213,a51215);
	D2_8 = _mm512_slli_epi64(D2_8,1);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a51214,a51214);
	D2_8 = _mm512_add_epi64(D2_8,carry);
	carry  = _mm512_srli_epi64(D2_8,52);
	D2_8 = _mm512_and_si512(D2_8,mask52);

	D2_9 = _mm512_madd52hi_epu64(zero,a51210,a51218);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51211,a51217);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51212,a51216);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51213,a51215);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51210,a51219);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51211,a51218);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51212,a51217);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51213,a51216);
	D2_9 = _mm512_madd52lo_epu64(D2_9,a51214,a51215);
	D2_9 = _mm512_slli_epi64(D2_9,1);
	D2_9 = _mm512_madd52hi_epu64(D2_9,a51214,a51214);
	D2_9 = _mm512_add_epi64(D2_9,carry);
	carry  = _mm512_srli_epi64(D2_9,52);
	D2_9 = _mm512_and_si512(D2_9,mask52);

	D2_10 = _mm512_madd52hi_epu64(zero,a51210,a51219);
	D2_10 = _mm512_madd52hi_epu64(D2_10,a51211,a51218);
	D2_10 = _mm512_madd52hi_epu64(D2_10,a51212,a51217);
	D2_10 = _mm512_madd52hi_epu64(D2_10,a51213,a51216);
	D2_10 = _mm512_madd52hi_epu64(D2_10,a51214,a51215);
	D2_10 = _mm512_madd52lo_epu64(D2_10,a51211,a51219);
	D2_10 = _mm512_madd52lo_epu64(D2_10,a51212,a51218);
	D2_10 = _mm512_madd52lo_epu64(D2_10,a51213,a51217);
	D2_10 = _mm512_madd52lo_epu64(D2_10,a51214,a51216);
	D2_10 = _mm512_slli_epi64(D2_10,1);
	D2_10 = _mm512_madd52lo_epu64(D2_10,a51215,a51215);
	D2_10 = _mm512_add_epi64(D2_10,carry);
	carry  = _mm512_srli_epi64(D2_10,52);
	D2_10 = _mm512_and_si512(D2_10,mask52);

	D2_11 = _mm512_madd52hi_epu64(zero,a51211,a51219);
	D2_11 = _mm512_madd52hi_epu64(D2_11,a51212,a51218);
	D2_11 = _mm512_madd52hi_epu64(D2_11,a51213,a51217);
	D2_11 = _mm512_madd52hi_epu64(D2_11,a51214,a51216);
	D2_11 = _mm512_madd52lo_epu64(D2_11,a51212,a51219);
	D2_11 = _mm512_madd52lo_epu64(D2_11,a51213,a51218);
	D2_11 = _mm512_madd52lo_epu64(D2_11,a51214,a51217);
	D2_11 = _mm512_madd52lo_epu64(D2_11,a51215,a51216);
	D2_11 = _mm512_slli_epi64(D2_11,1);
	D2_11 = _mm512_madd52hi_epu64(D2_11,a51215,a51215);
	D2_11 = _mm512_add_epi64(D2_11,carry);
	carry  = _mm512_srli_epi64(D2_11,52);
	D2_11 = _mm512_and_si512(D2_11,mask52);

	D2_12 = _mm512_madd52hi_epu64(zero,a51212,a51219);
	D2_12 = _mm512_madd52hi_epu64(D2_12,a51213,a51218);
	D2_12 = _mm512_madd52hi_epu64(D2_12,a51214,a51217);
	D2_12 = _mm512_madd52hi_epu64(D2_12,a51215,a51216);
	D2_12 = _mm512_madd52lo_epu64(D2_12,a51213,a51219);
	D2_12 = _mm512_madd52lo_epu64(D2_12,a51214,a51218);
	D2_12 = _mm512_madd52lo_epu64(D2_12,a51215,a51217);
	D2_12 = _mm512_slli_epi64(D2_12,1);
	D2_12 = _mm512_madd52lo_epu64(D2_12,a51216,a51216);
	D2_12 = _mm512_add_epi64(D2_12,carry);
	carry  = _mm512_srli_epi64(D2_12,52);
	D2_12 = _mm512_and_si512(D2_12,mask52);

	D2_13 = _mm512_madd52hi_epu64(zero,a51213,a51219);
	D2_13 = _mm512_madd52hi_epu64(D2_13,a51214,a51218);
	D2_13 = _mm512_madd52hi_epu64(D2_13,a51215,a51217);
	D2_13 = _mm512_madd52lo_epu64(D2_13,a51214,a51219);
	D2_13 = _mm512_madd52lo_epu64(D2_13,a51215,a51218);
	D2_13 = _mm512_madd52lo_epu64(D2_13,a51216,a51217);
	D2_13 = _mm512_slli_epi64(D2_13,1);
	D2_13 = _mm512_madd52hi_epu64(D2_13,a51216,a51216);
	D2_13 = _mm512_add_epi64(D2_13,carry);
	carry  = _mm512_srli_epi64(D2_13,52);
	D2_13 = _mm512_and_si512(D2_13,mask52);

	D2_14 = _mm512_madd52hi_epu64(zero,a51214,a51219);
	D2_14 = _mm512_madd52hi_epu64(D2_14,a51215,a51218);
	D2_14 = _mm512_madd52hi_epu64(D2_14,a51216,a51217);
	D2_14 = _mm512_madd52lo_epu64(D2_14,a51215,a51219);
	D2_14 = _mm512_madd52lo_epu64(D2_14,a51216,a51218);
	D2_14 = _mm512_slli_epi64(D2_14,1);
	D2_14 = _mm512_madd52lo_epu64(D2_14,a51217,a51217);
	D2_14 = _mm512_add_epi64(D2_14,carry);
	carry  = _mm512_srli_epi64(D2_14,52);
	D2_14 = _mm512_and_si512(D2_14,mask52);

	D2_15 = _mm512_madd52hi_epu64(zero,a51215,a51219);
	D2_15 = _mm512_madd52hi_epu64(D2_15,a51216,a51218);
	D2_15 = _mm512_madd52lo_epu64(D2_15,a51216,a51219);
	D2_15 = _mm512_madd52lo_epu64(D2_15,a51217,a51218);
	D2_15 = _mm512_slli_epi64(D2_15,1);
	D2_15 = _mm512_madd52hi_epu64(D2_15,a51217,a51217);
	D2_15 = _mm512_add_epi64(D2_15,carry);
	carry  = _mm512_srli_epi64(D2_15,52);
	D2_15 = _mm512_and_si512(D2_15,mask52);

	D2_16 = _mm512_madd52hi_epu64(zero,a51216,a51219);
	D2_16 = _mm512_madd52hi_epu64(D2_16,a51217,a51218);
	D2_16 = _mm512_madd52lo_epu64(D2_16,a51217,a51219);
	D2_16 = _mm512_slli_epi64(D2_16,1);
	D2_16 = _mm512_madd52lo_epu64(D2_16,a51218,a51218);
	D2_16 = _mm512_add_epi64(D2_16,carry);
	carry  = _mm512_srli_epi64(D2_16,52);
	D2_16 = _mm512_and_si512(D2_16,mask52);

	D2_17 = _mm512_madd52hi_epu64(zero,a51217,a51219);
	D2_17 = _mm512_madd52lo_epu64(D2_17,a51218,a51219);
	D2_17 = _mm512_slli_epi64(D2_17,1);
	D2_17 = _mm512_madd52hi_epu64(D2_17,a51218,a51218);
	D2_17 = _mm512_add_epi64(D2_17,carry);
	carry  = _mm512_srli_epi64(D2_17,52);
	D2_17 = _mm512_and_si512(D2_17,mask52);

	D2_18 = _mm512_madd52hi_epu64(zero,a51218,a51219);
	D2_18 = _mm512_slli_epi64(D2_18,1);
	D2_18 = _mm512_madd52lo_epu64(D2_18,a51219,a51219);
	D2_18 = _mm512_add_epi64(D2_18,carry);
	carry  = _mm512_srli_epi64(D2_18,52);
	D2_18 = _mm512_and_si512(D2_18,mask52);

	D2_19 = _mm512_madd52hi_epu64(carry,a51219,a51219);


	// Carry management

	carry  = _mm512_srli_epi64(D2_1,52);
	D2_2 = _mm512_add_epi64(D2_2,carry);
	D2_1 = _mm512_and_si512(D2_1,mask52);
	carry  = _mm512_srli_epi64(D2_2,52);
	D2_3 = _mm512_add_epi64(D2_3,carry);
	D2_2 = _mm512_and_si512(D2_2,mask52);
	carry  = _mm512_srli_epi64(D2_3,52);
	D2_4 = _mm512_add_epi64(D2_4,carry);
	D2_3 = _mm512_and_si512(D2_3,mask52);
	carry  = _mm512_srli_epi64(D2_4,52);
	D2_5 = _mm512_add_epi64(D2_5,carry);
	D2_4 = _mm512_and_si512(D2_4,mask52);
	carry  = _mm512_srli_epi64(D2_5,52);
	D2_6 = _mm512_add_epi64(D2_6,carry);
	D2_5 = _mm512_and_si512(D2_5,mask52);
	carry  = _mm512_srli_epi64(D2_6,52);
	D2_7 = _mm512_add_epi64(D2_7,carry);
	D2_6 = _mm512_and_si512(D2_6,mask52);
	carry  = _mm512_srli_epi64(D2_7,52);
	D2_8 = _mm512_add_epi64(D2_8,carry);
	D2_7 = _mm512_and_si512(D2_7,mask52);
	carry  = _mm512_srli_epi64(D2_8,52);
	D2_9 = _mm512_add_epi64(D2_9,carry);
	D2_8 = _mm512_and_si512(D2_8,mask52);
	carry  = _mm512_srli_epi64(D2_9,52);
	D2_10 = _mm512_add_epi64(D2_10,carry);
	D2_9 = _mm512_and_si512(D2_9,mask52);
	carry  = _mm512_srli_epi64(D2_10,52);
	D2_11 = _mm512_add_epi64(D2_11,carry);
	D2_10 = _mm512_and_si512(D2_10,mask52);
	carry  = _mm512_srli_epi64(D2_11,52);
	D2_12 = _mm512_add_epi64(D2_12,carry);
	D2_11 = _mm512_and_si512(D2_11,mask52);
	carry  = _mm512_srli_epi64(D2_12,52);
	D2_13 = _mm512_add_epi64(D2_13,carry);
	D2_12 = _mm512_and_si512(D2_12,mask52);
	carry  = _mm512_srli_epi64(D2_13,52);
	D2_14 = _mm512_add_epi64(D2_14,carry);
	D2_13 = _mm512_and_si512(D2_13,mask52);
	carry  = _mm512_srli_epi64(D2_14,52);
	D2_15 = _mm512_add_epi64(D2_15,carry);
	D2_14 = _mm512_and_si512(D2_14,mask52);
	carry  = _mm512_srli_epi64(D2_15,52);
	D2_16 = _mm512_add_epi64(D2_16,carry);
	D2_15 = _mm512_and_si512(D2_15,mask52);
	carry  = _mm512_srli_epi64(D2_16,52);
	D2_17 = _mm512_add_epi64(D2_17,carry);
	D2_16 = _mm512_and_si512(D2_16,mask52);
	carry  = _mm512_srli_epi64(D2_17,52);
	D2_18 = _mm512_add_epi64(D2_18,carry);
	D2_17 = _mm512_and_si512(D2_17,mask52);
	carry  = _mm512_srli_epi64(D2_18,52);
	D2_19 = _mm512_add_epi64(D2_19,carry);
	D2_18 = _mm512_and_si512(D2_18,mask52);

	// Conversion in base 2^519

	carry = D2_9>>51;
	D2_10 = (D2_10<<1)|carry;
	D2_9 &= mask51;
	carry = D2_10>>52;
	D2_11 = (D2_11<<1)|carry;
	D2_10 &= mask52;
	carry = D2_11>>52;
	D2_12 = (D2_12<<1)|carry;
	D2_11 &= mask52;
	carry = D2_12>>52;
	D2_13 = (D2_13<<1)|carry;
	D2_12 &= mask52;
	carry = D2_13>>52;
	D2_14 = (D2_14<<1)|carry;
	D2_13 &= mask52;
	carry = D2_14>>52;
	D2_15 = (D2_15<<1)|carry;
	D2_14 &= mask52;
	carry = D2_15>>52;
	D2_16 = (D2_16<<1)|carry;
	D2_15 &= mask52;
	carry = D2_16>>52;
	D2_17 = (D2_17<<1)|carry;
	D2_16 &= mask52;
	carry = D2_17>>52;
	D2_18 = (D2_18<<1)|carry;
	D2_17 &= mask52;
	carry = D2_18>>52;
	D2_19 = (D2_19<<1)|carry;
	D2_18 &= mask52;

	// D1 = (Al+Ah)^2

	__m512i D1_0, D1_1;
	__m512i D1_2, D1_3;
	__m512i D1_4, D1_5;
	__m512i D1_6, D1_7;
	__m512i D1_8, D1_9;
	__m512i D1_10, D1_11;
	__m512i D1_12, D1_13;
	__m512i D1_14, D1_15;
	__m512i D1_16, D1_17;
	__m512i D1_18, D1_19;

	__m512i alpah0 = _mm512_add_epi64(a5120,a51210);
	carry = alpah0>>52;
	alpah0 &= mask52;
	__m512i alpah1 = _mm512_add_epi64(a5121,carry);
	alpah1 = _mm512_add_epi64(alpah1,a51211);
	carry = alpah1>>52;
	alpah1 &= mask52;
	__m512i alpah2 = _mm512_add_epi64(a5122,carry);
	alpah2 = _mm512_add_epi64(alpah2,a51212);
	carry = alpah2>>52;
	alpah2 &= mask52;
	__m512i alpah3 = _mm512_add_epi64(a5123,carry);
	alpah3 = _mm512_add_epi64(alpah3,a51213);
	carry = alpah3>>52;
	alpah3 &= mask52;
	__m512i alpah4 = _mm512_add_epi64(a5124,carry);
	alpah4 = _mm512_add_epi64(alpah4,a51214);
	carry = alpah4>>52;
	alpah4 &= mask52;
	__m512i alpah5 = _mm512_add_epi64(a5125,carry);
	alpah5 = _mm512_add_epi64(alpah5,a51215);
	carry = alpah5>>52;
	alpah5 &= mask52;
	__m512i alpah6 = _mm512_add_epi64(a5126,carry);
	alpah6 = _mm512_add_epi64(alpah6,a51216);
	carry = alpah6>>52;
	alpah6 &= mask52;
	__m512i alpah7 = _mm512_add_epi64(a5127,carry);
	alpah7 = _mm512_add_epi64(alpah7,a51217);
	carry = alpah7>>52;
	alpah7 &= mask52;
	__m512i alpah8 = _mm512_add_epi64(a5128,carry);
	alpah8 = _mm512_add_epi64(alpah8,a51218);
	carry = alpah8>>52;
	alpah8 &= mask52;
	__m512i alpah9 = _mm512_add_epi64(a5129,carry);
	alpah9 = _mm512_add_epi64(alpah9,a51219);
	carry = alpah9>>52;
	alpah9 &= mask52;

	D1_0 = _mm512_madd52lo_epu64(D0_10,alpah0,alpah0);

	D1_1 = _mm512_madd52lo_epu64(zero,alpah0,alpah1);
	D1_1 = _mm512_slli_epi64(D1_1,1);
	D1_1 = _mm512_madd52hi_epu64(D1_1,alpah0,alpah0);
	D1_1 = _mm512_add_epi64(D0_11,D1_1);
	carry  = _mm512_srli_epi64(D1_1,52);
	D1_1 = _mm512_and_si512(D1_1,mask52);

	D1_2 = _mm512_madd52hi_epu64(zero,alpah0,alpah1);
	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah0,alpah2);
	D1_2 = _mm512_slli_epi64(D1_2,1);
	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah1,alpah1);
	D1_2 = _mm512_add_epi64(D0_12,D1_2);
	D1_2 = _mm512_add_epi64(D1_2,carry);
	carry  = _mm512_srli_epi64(D1_2,52);
	D1_2 = _mm512_and_si512(D1_2,mask52);

	D1_3 = _mm512_madd52hi_epu64(zero,alpah0,alpah2);
	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah0,alpah3);
	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah1,alpah2);
	D1_3 = _mm512_slli_epi64(D1_3,1);
	D1_3 = _mm512_madd52hi_epu64(D1_3,alpah1,alpah1);
	D1_3 = _mm512_add_epi64(D0_13,D1_3);
	D1_3 = _mm512_add_epi64(D1_3,carry);
	carry  = _mm512_srli_epi64(D1_3,52);
	D1_3 = _mm512_and_si512(D1_3,mask52);

	D1_4 = _mm512_madd52hi_epu64(zero,alpah0,alpah3);
	D1_4 = _mm512_madd52hi_epu64(D1_4,alpah1,alpah2);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah0,alpah4);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah1,alpah3);
	D1_4 = _mm512_slli_epi64(D1_4,1);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah2,alpah2);
	D1_4 = _mm512_add_epi64(D0_14,D1_4);
	D1_4 = _mm512_add_epi64(D1_4,carry);
	carry  = _mm512_srli_epi64(D1_4,52);
	D1_4 = _mm512_and_si512(D1_4,mask52);

	D1_5 = _mm512_madd52hi_epu64(zero,alpah0,alpah4);
	D1_5 = _mm512_madd52hi_epu64(D1_5,alpah1,alpah3);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah0,alpah5);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah1,alpah4);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah2,alpah3);
	D1_5 = _mm512_slli_epi64(D1_5,1);
	D1_5 = _mm512_madd52hi_epu64(D1_5,alpah2,alpah2);
	D1_5 = _mm512_add_epi64(D0_15,D1_5);
	D1_5 = _mm512_add_epi64(D1_5,carry);
	carry  = _mm512_srli_epi64(D1_5,52);
	D1_5 = _mm512_and_si512(D1_5,mask52);

	D1_6 = _mm512_madd52hi_epu64(zero,alpah0,alpah5);
	D1_6 = _mm512_madd52hi_epu64(D1_6,alpah1,alpah4);
	D1_6 = _mm512_madd52hi_epu64(D1_6,alpah2,alpah3);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah0,alpah6);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah1,alpah5);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah2,alpah4);
	D1_6 = _mm512_slli_epi64(D1_6,1);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah3,alpah3);
	D1_6 = _mm512_add_epi64(D0_16,D1_6);
	D1_6 = _mm512_add_epi64(D1_6,carry);
	carry  = _mm512_srli_epi64(D1_6,52);
	D1_6 = _mm512_and_si512(D1_6,mask52);

	D1_7 = _mm512_madd52hi_epu64(zero,alpah0,alpah6);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah1,alpah5);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah2,alpah4);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah0,alpah7);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah1,alpah6);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah2,alpah5);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah3,alpah4);
	D1_7 = _mm512_slli_epi64(D1_7,1);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah3,alpah3);
	D1_7 = _mm512_add_epi64(D0_17,D1_7);
	D1_7 = _mm512_add_epi64(D1_7,carry);
	carry  = _mm512_srli_epi64(D1_7,52);
	D1_7 = _mm512_and_si512(D1_7,mask52);

	D1_8 = _mm512_madd52hi_epu64(zero,alpah0,alpah7);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah1,alpah6);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah2,alpah5);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah3,alpah4);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah0,alpah8);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah1,alpah7);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah2,alpah6);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah3,alpah5);
	D1_8 = _mm512_slli_epi64(D1_8,1);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah4,alpah4);
	D1_8 = _mm512_add_epi64(D0_18,D1_8);
	D1_8 = _mm512_add_epi64(D1_8,carry);
	carry  = _mm512_srli_epi64(D1_8,52);
	D1_8 = _mm512_and_si512(D1_8,mask52);

	D1_9 = _mm512_madd52hi_epu64(zero,alpah0,alpah8);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah1,alpah7);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah2,alpah6);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah3,alpah5);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah0,alpah9);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah1,alpah8);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah2,alpah7);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah3,alpah6);
	D1_9 = _mm512_madd52lo_epu64(D1_9,alpah4,alpah5);
	D1_9 = _mm512_slli_epi64(D1_9,1);
	D1_9 = _mm512_madd52hi_epu64(D1_9,alpah4,alpah4);
	D1_9 = _mm512_add_epi64(D0_19,D1_9);
	D1_9 = _mm512_add_epi64(D1_9,carry);
	carry  = _mm512_srli_epi64(D1_9,52);
	D1_9 = _mm512_and_si512(D1_9,mask52);

	D1_10 = _mm512_madd52hi_epu64(zero,alpah0,alpah9);
	D1_10 = _mm512_madd52hi_epu64(D1_10,alpah1,alpah8);
	D1_10 = _mm512_madd52hi_epu64(D1_10,alpah2,alpah7);
	D1_10 = _mm512_madd52hi_epu64(D1_10,alpah3,alpah6);
	D1_10 = _mm512_madd52hi_epu64(D1_10,alpah4,alpah5);
	D1_10 = _mm512_madd52lo_epu64(D1_10,alpah1,alpah9);
	D1_10 = _mm512_madd52lo_epu64(D1_10,alpah2,alpah8);
	D1_10 = _mm512_madd52lo_epu64(D1_10,alpah3,alpah7);
	D1_10 = _mm512_madd52lo_epu64(D1_10,alpah4,alpah6);
	D1_10 = _mm512_slli_epi64(D1_10,1);
	D1_10 = _mm512_madd52lo_epu64(D1_10,alpah5,alpah5);
	D1_10 = _mm512_add_epi64(D1_10,carry);
	carry  = _mm512_srli_epi64(D1_10,52);
	D1_10 = _mm512_and_si512(D1_10,mask52);

	D1_11 = _mm512_madd52hi_epu64(zero,alpah1,alpah9);
	D1_11 = _mm512_madd52hi_epu64(D1_11,alpah2,alpah8);
	D1_11 = _mm512_madd52hi_epu64(D1_11,alpah3,alpah7);
	D1_11 = _mm512_madd52hi_epu64(D1_11,alpah4,alpah6);
	D1_11 = _mm512_madd52lo_epu64(D1_11,alpah2,alpah9);
	D1_11 = _mm512_madd52lo_epu64(D1_11,alpah3,alpah8);
	D1_11 = _mm512_madd52lo_epu64(D1_11,alpah4,alpah7);
	D1_11 = _mm512_madd52lo_epu64(D1_11,alpah5,alpah6);
	D1_11 = _mm512_slli_epi64(D1_11,1);
	D1_11 = _mm512_madd52hi_epu64(D1_11,alpah5,alpah5);
	D1_11 = _mm512_add_epi64(D1_11,carry);
	carry  = _mm512_srli_epi64(D1_11,52);
	D1_11 = _mm512_and_si512(D1_11,mask52);

	D1_12 = _mm512_madd52hi_epu64(zero,alpah2,alpah9);
	D1_12 = _mm512_madd52hi_epu64(D1_12,alpah3,alpah8);
	D1_12 = _mm512_madd52hi_epu64(D1_12,alpah4,alpah7);
	D1_12 = _mm512_madd52hi_epu64(D1_12,alpah5,alpah6);
	D1_12 = _mm512_madd52lo_epu64(D1_12,alpah3,alpah9);
	D1_12 = _mm512_madd52lo_epu64(D1_12,alpah4,alpah8);
	D1_12 = _mm512_madd52lo_epu64(D1_12,alpah5,alpah7);
	D1_12 = _mm512_slli_epi64(D1_12,1);
	D1_12 = _mm512_madd52lo_epu64(D1_12,alpah6,alpah6);
	D1_12 = _mm512_add_epi64(D1_12,carry);
	carry  = _mm512_srli_epi64(D1_12,52);
	D1_12 = _mm512_and_si512(D1_12,mask52);

	D1_13 = _mm512_madd52hi_epu64(zero,alpah3,alpah9);
	D1_13 = _mm512_madd52hi_epu64(D1_13,alpah4,alpah8);
	D1_13 = _mm512_madd52hi_epu64(D1_13,alpah5,alpah7);
	D1_13 = _mm512_madd52lo_epu64(D1_13,alpah4,alpah9);
	D1_13 = _mm512_madd52lo_epu64(D1_13,alpah5,alpah8);
	D1_13 = _mm512_madd52lo_epu64(D1_13,alpah6,alpah7);
	D1_13 = _mm512_slli_epi64(D1_13,1);
	D1_13 = _mm512_madd52hi_epu64(D1_13,alpah6,alpah6);
	D1_13 = _mm512_add_epi64(D1_13,carry);
	carry  = _mm512_srli_epi64(D1_13,52);
	D1_13 = _mm512_and_si512(D1_13,mask52);

	D1_14 = _mm512_madd52hi_epu64(zero,alpah4,alpah9);
	D1_14 = _mm512_madd52hi_epu64(D1_14,alpah5,alpah8);
	D1_14 = _mm512_madd52hi_epu64(D1_14,alpah6,alpah7);
	D1_14 = _mm512_madd52lo_epu64(D1_14,alpah5,alpah9);
	D1_14 = _mm512_madd52lo_epu64(D1_14,alpah6,alpah8);
	D1_14 = _mm512_slli_epi64(D1_14,1);
	D1_14 = _mm512_madd52lo_epu64(D1_14,alpah7,alpah7);
	D1_14 = _mm512_add_epi64(D1_14,carry);
	carry  = _mm512_srli_epi64(D1_14,52);
	D1_14 = _mm512_and_si512(D1_14,mask52);

	D1_15 = _mm512_madd52hi_epu64(zero,alpah5,alpah9);
	D1_15 = _mm512_madd52hi_epu64(D1_15,alpah6,alpah8);
	D1_15 = _mm512_madd52lo_epu64(D1_15,alpah6,alpah9);
	D1_15 = _mm512_madd52lo_epu64(D1_15,alpah7,alpah8);
	D1_15 = _mm512_slli_epi64(D1_15,1);
	D1_15 = _mm512_madd52hi_epu64(D1_15,alpah7,alpah7);
	D1_15 = _mm512_add_epi64(D1_15,carry);
	carry  = _mm512_srli_epi64(D1_15,52);
	D1_15 = _mm512_and_si512(D1_15,mask52);

	D1_16 = _mm512_madd52hi_epu64(zero,alpah6,alpah9);
	D1_16 = _mm512_madd52hi_epu64(D1_16,alpah7,alpah8);
	D1_16 = _mm512_madd52lo_epu64(D1_16,alpah7,alpah9);
	D1_16 = _mm512_slli_epi64(D1_16,1);
	D1_16 = _mm512_madd52lo_epu64(D1_16,alpah8,alpah8);
	D1_16 = _mm512_add_epi64(D1_16,carry);
	carry  = _mm512_srli_epi64(D1_16,52);
	D1_16 = _mm512_and_si512(D1_16,mask52);

	D1_17 = _mm512_madd52hi_epu64(zero,alpah7,alpah9);
	D1_17 = _mm512_madd52lo_epu64(D1_17,alpah8,alpah9);
	D1_17 = _mm512_slli_epi64(D1_17,1);
	D1_17 = _mm512_madd52hi_epu64(D1_17,alpah8,alpah8);
	D1_17 = _mm512_add_epi64(D1_17,carry);
	carry  = _mm512_srli_epi64(D1_17,52);
	D1_17 = _mm512_and_si512(D1_17,mask52);

	D1_18 = _mm512_madd52hi_epu64(zero,alpah8,alpah9);
	D1_18 = _mm512_slli_epi64(D1_18,1);
	D1_18 = _mm512_madd52lo_epu64(D1_18,alpah9,alpah9);
	D1_18 = _mm512_add_epi64(D1_18,carry);
	carry  = _mm512_srli_epi64(D1_18,52);
	D1_18 = _mm512_and_si512(D1_18,mask52);

	D1_19 = _mm512_madd52hi_epu64(carry,alpah9,alpah9);


	// Carry management

	carry  = _mm512_srli_epi64(D1_0,52);
	D1_0 = _mm512_and_si512(D1_0,mask52);
	D1_1 = _mm512_add_epi64(D1_1,carry);
	carry  = _mm512_srli_epi64(D1_1,52);
	D1_2 = _mm512_add_epi64(D1_2,carry);
	D1_1 = _mm512_and_si512(D1_1,mask52);
	carry  = _mm512_srli_epi64(D1_2,52);
	D1_3 = _mm512_add_epi64(D1_3,carry);
	D1_2 = _mm512_and_si512(D1_2,mask52);
	carry  = _mm512_srli_epi64(D1_3,52);
	D1_4 = _mm512_add_epi64(D1_4,carry);
	D1_3 = _mm512_and_si512(D1_3,mask52);
	carry  = _mm512_srli_epi64(D1_4,52);
	D1_5 = _mm512_add_epi64(D1_5,carry);
	D1_4 = _mm512_and_si512(D1_4,mask52);
	carry  = _mm512_srli_epi64(D1_5,52);
	D1_6 = _mm512_add_epi64(D1_6,carry);
	D1_5 = _mm512_and_si512(D1_5,mask52);
	carry  = _mm512_srli_epi64(D1_6,52);
	D1_7 = _mm512_add_epi64(D1_7,carry);
	D1_6 = _mm512_and_si512(D1_6,mask52);
	carry  = _mm512_srli_epi64(D1_7,52);
	D1_8 = _mm512_add_epi64(D1_8,carry);
	D1_7 = _mm512_and_si512(D1_7,mask52);
	carry  = _mm512_srli_epi64(D1_8,52);
	D1_9 = _mm512_add_epi64(D1_9,carry);
	D1_8 = _mm512_and_si512(D1_8,mask52);
	carry  = _mm512_srli_epi64(D1_9,52);
	D1_10 = _mm512_add_epi64(D1_10,carry);
	D1_9 = _mm512_and_si512(D1_9,mask52);
	carry  = _mm512_srli_epi64(D1_10,52);
	D1_11 = _mm512_add_epi64(D1_11,carry);
	D1_10 = _mm512_and_si512(D1_10,mask52);
	carry  = _mm512_srli_epi64(D1_11,52);
	D1_12 = _mm512_add_epi64(D1_12,carry);
	D1_11 = _mm512_and_si512(D1_11,mask52);
	carry  = _mm512_srli_epi64(D1_12,52);
	D1_13 = _mm512_add_epi64(D1_13,carry);
	D1_12 = _mm512_and_si512(D1_12,mask52);
	carry  = _mm512_srli_epi64(D1_13,52);
	D1_14 = _mm512_add_epi64(D1_14,carry);
	D1_13 = _mm512_and_si512(D1_13,mask52);
	carry  = _mm512_srli_epi64(D1_14,52);
	D1_15 = _mm512_add_epi64(D1_15,carry);
	D1_14 = _mm512_and_si512(D1_14,mask52);
	carry  = _mm512_srli_epi64(D1_15,52);
	D1_16 = _mm512_add_epi64(D1_16,carry);
	D1_15 = _mm512_and_si512(D1_15,mask52);
	carry  = _mm512_srli_epi64(D1_16,52);
	D1_17 = _mm512_add_epi64(D1_17,carry);
	D1_16 = _mm512_and_si512(D1_16,mask52);
	carry  = _mm512_srli_epi64(D1_17,52);
	D1_18 = _mm512_add_epi64(D1_18,carry);
	D1_17 = _mm512_and_si512(D1_17,mask52);
	carry  = _mm512_srli_epi64(D1_18,52);
	D1_19 = _mm512_add_epi64(D1_19,carry);
	D1_18 = _mm512_and_si512(D1_18,mask52);

	// Conversion in base 2^519

	carry  = _mm512_srli_epi64(D1_9,51);
	D1_9 = _mm512_and_si512(D1_9,mask51);// radix 2^519
	D1_10 = _mm512_add_epi64(_mm512_slli_epi64(D1_10,1),carry);
	D1_10 = _mm512_add_epi64(D1_10,D2_0);
	carry = _mm512_srli_epi64(D1_10,52);
	D1_10 = _mm512_and_si512(D1_10,mask52);
	D1_11 = _mm512_add_epi64(_mm512_slli_epi64(D1_11,1),carry);
	D1_11 = _mm512_add_epi64(D1_11,D2_1);
	carry = _mm512_srli_epi64(D1_11,52);
	D1_11 = _mm512_and_si512(D1_11,mask52);
	D1_12 = _mm512_add_epi64(_mm512_slli_epi64(D1_12,1),carry);
	D1_12 = _mm512_add_epi64(D1_12,D2_2);
	carry = _mm512_srli_epi64(D1_12,52);
	D1_12 = _mm512_and_si512(D1_12,mask52);
	D1_13 = _mm512_add_epi64(_mm512_slli_epi64(D1_13,1),carry);
	D1_13 = _mm512_add_epi64(D1_13,D2_3);
	carry = _mm512_srli_epi64(D1_13,52);
	D1_13 = _mm512_and_si512(D1_13,mask52);
	D1_14 = _mm512_add_epi64(_mm512_slli_epi64(D1_14,1),carry);
	D1_14 = _mm512_add_epi64(D1_14,D2_4);
	carry = _mm512_srli_epi64(D1_14,52);
	D1_14 = _mm512_and_si512(D1_14,mask52);
	D1_15 = _mm512_add_epi64(_mm512_slli_epi64(D1_15,1),carry);
	D1_15 = _mm512_add_epi64(D1_15,D2_5);
	carry = _mm512_srli_epi64(D1_15,52);
	D1_15 = _mm512_and_si512(D1_15,mask52);
	D1_16 = _mm512_add_epi64(_mm512_slli_epi64(D1_16,1),carry);
	D1_16 = _mm512_add_epi64(D1_16,D2_6);
	carry = _mm512_srli_epi64(D1_16,52);
	D1_16 = _mm512_and_si512(D1_16,mask52);
	D1_17 = _mm512_add_epi64(_mm512_slli_epi64(D1_17,1),carry);
	D1_17 = _mm512_add_epi64(D1_17,D2_7);
	carry = _mm512_srli_epi64(D1_17,52);
	D1_17 = _mm512_and_si512(D1_17,mask52);
	D1_18 = _mm512_add_epi64(_mm512_slli_epi64(D1_18,1),carry);
	D1_18 = _mm512_add_epi64(D1_18,D2_8);
	carry = _mm512_srli_epi64(D1_18,52);
	D1_18 = _mm512_and_si512(D1_18,mask52);
	D1_19 = _mm512_add_epi64(_mm512_slli_epi64(D1_19,1),carry);
	D1_19 = _mm512_add_epi64(D1_19,D2_9);
	carry  = _mm512_srli_epi64(D1_19,51);
	D1_19 = _mm512_and_si512(D1_19,mask51);// radix 2^519

	// Final reconstruction


	// tmp = D0+D2, radix 2^519

	__m512i tmp0 = _mm512_add_epi64(D0_0,D2_0);
	__m512i carry_tmp  = _mm512_srli_epi64(tmp0,52);
	tmp0 = _mm512_and_si512(tmp0,mask52);

	__m512i tmp1 = _mm512_add_epi64(D0_1,carry_tmp);
	tmp1 = _mm512_add_epi64(tmp1,D2_1);
	carry_tmp  = _mm512_srli_epi64(tmp1,52);
	tmp1 = _mm512_and_si512(tmp1,mask52);

	__m512i tmp2 = _mm512_add_epi64(D0_2,carry_tmp);
	tmp2 = _mm512_add_epi64(tmp2,D2_2);
	carry_tmp  = _mm512_srli_epi64(tmp2,52);
	tmp2 = _mm512_and_si512(tmp2,mask52);

	__m512i tmp3 = _mm512_add_epi64(D0_3,carry_tmp);
	tmp3 = _mm512_add_epi64(tmp3,D2_3);
	carry_tmp  = _mm512_srli_epi64(tmp3,52);
	tmp3 = _mm512_and_si512(tmp3,mask52);

	__m512i tmp4 = _mm512_add_epi64(D0_4,carry_tmp);
	tmp4 = _mm512_add_epi64(tmp4,D2_4);
	carry_tmp  = _mm512_srli_epi64(tmp4,52);
	tmp4 = _mm512_and_si512(tmp4,mask52);

	__m512i tmp5 = _mm512_add_epi64(D0_5,carry_tmp);
	tmp5 = _mm512_add_epi64(tmp5,D2_5);
	carry_tmp  = _mm512_srli_epi64(tmp5,52);
	tmp5 = _mm512_and_si512(tmp5,mask52);

	__m512i tmp6 = _mm512_add_epi64(D0_6,carry_tmp);
	tmp6 = _mm512_add_epi64(tmp6,D2_6);
	carry_tmp  = _mm512_srli_epi64(tmp6,52);
	tmp6 = _mm512_and_si512(tmp6,mask52);

	__m512i tmp7 = _mm512_add_epi64(D0_7,carry_tmp);
	tmp7 = _mm512_add_epi64(tmp7,D2_7);
	carry_tmp  = _mm512_srli_epi64(tmp7,52);
	tmp7 = _mm512_and_si512(tmp7,mask52);

	__m512i tmp8 = _mm512_add_epi64(D0_8,carry_tmp);
	tmp8 = _mm512_add_epi64(tmp8,D2_8);
	carry_tmp  = _mm512_srli_epi64(tmp8,52);
	tmp8 = _mm512_and_si512(tmp8,mask52);

	__m512i tmp9 = _mm512_add_epi64(D0_9,carry_tmp);
	tmp9 = _mm512_add_epi64(tmp9,D2_9);
	carry_tmp  = _mm512_srli_epi64(tmp9,51);
	tmp9 = _mm512_and_si512(tmp9,mask51);// radix 2**519

	__m512i tmp10 = _mm512_add_epi64(D0_10,carry_tmp);
	tmp10 = _mm512_add_epi64(tmp10,D2_10);
	carry_tmp  = _mm512_srli_epi64(tmp10,52);
	tmp10 = _mm512_and_si512(tmp10,mask52);

	__m512i tmp11 = _mm512_add_epi64(D0_11,carry_tmp);
	tmp11 = _mm512_add_epi64(tmp11,D2_11);
	carry_tmp  = _mm512_srli_epi64(tmp11,52);
	tmp11 = _mm512_and_si512(tmp11,mask52);

	__m512i tmp12 = _mm512_add_epi64(D0_12,carry_tmp);
	tmp12 = _mm512_add_epi64(tmp12,D2_12);
	carry_tmp  = _mm512_srli_epi64(tmp12,52);
	tmp12 = _mm512_and_si512(tmp12,mask52);

	__m512i tmp13 = _mm512_add_epi64(D0_13,carry_tmp);
	tmp13 = _mm512_add_epi64(tmp13,D2_13);
	carry_tmp  = _mm512_srli_epi64(tmp13,52);
	tmp13 = _mm512_and_si512(tmp13,mask52);

	__m512i tmp14 = _mm512_add_epi64(D0_14,carry_tmp);
	tmp14 = _mm512_add_epi64(tmp14,D2_14);
	carry_tmp  = _mm512_srli_epi64(tmp14,52);
	tmp14 = _mm512_and_si512(tmp14,mask52);

	__m512i tmp15 = _mm512_add_epi64(D0_15,carry_tmp);
	tmp15 = _mm512_add_epi64(tmp15,D2_15);
	carry_tmp  = _mm512_srli_epi64(tmp15,52);
	tmp15 = _mm512_and_si512(tmp15,mask52);

	__m512i tmp16 = _mm512_add_epi64(D0_16,carry_tmp);
	tmp16 = _mm512_add_epi64(tmp16,D2_16);
	carry_tmp  = _mm512_srli_epi64(tmp16,52);
	tmp16 = _mm512_and_si512(tmp16,mask52);

	__m512i tmp17 = _mm512_add_epi64(D0_17,carry_tmp);
	tmp17 = _mm512_add_epi64(tmp17,D2_17);
	carry_tmp  = _mm512_srli_epi64(tmp17,52);
	tmp17 = _mm512_and_si512(tmp17,mask52);

	__m512i tmp18 = _mm512_add_epi64(D0_18,carry_tmp);
	tmp18 = _mm512_add_epi64(tmp18,D2_18);
	carry_tmp  = _mm512_srli_epi64(tmp18,52);
	tmp18 = _mm512_and_si512(tmp18,mask52);

	__m512i tmp19 = _mm512_add_epi64(D0_19,carry_tmp);
	tmp19 = _mm512_add_epi64(tmp19,D2_19);
	carry_tmp  = _mm512_srli_epi64(tmp19,51);
	tmp19 = _mm512_and_si512(tmp19,mask51);// radix 2**519




	// D1 = D1 -tmp, radix 2^519

	D1_0 = _mm512_sub_epi64(D1_0,tmp0);
	__m512i borrow = _mm512_srli_epi64(D1_0,52)&un;
	D1_0 = _mm512_and_si512(D1_0,mask52);
	borrow = _mm512_add_epi64(tmp1,borrow);
	D1_1 = _mm512_sub_epi64(D1_1,borrow);
	borrow  = _mm512_srli_epi64(D1_1,52)&un;
	D1_1 = _mm512_and_si512(D1_1,mask52);

	borrow = _mm512_add_epi64(tmp2,borrow);
	D1_2 = _mm512_sub_epi64(D1_2,borrow);
	borrow  = _mm512_srli_epi64(D1_2,52)&un;
	D1_2 = _mm512_and_si512(D1_2,mask52);

	borrow = _mm512_add_epi64(tmp3,borrow);
	D1_3 = _mm512_sub_epi64(D1_3,borrow);
	borrow  = _mm512_srli_epi64(D1_3,52)&un;
	D1_3 = _mm512_and_si512(D1_3,mask52);

	borrow = _mm512_add_epi64(tmp4,borrow);
	D1_4 = _mm512_sub_epi64(D1_4,borrow);
	borrow  = _mm512_srli_epi64(D1_4,52)&un;
	D1_4 = _mm512_and_si512(D1_4,mask52);

	borrow = _mm512_add_epi64(tmp5,borrow);
	D1_5 = _mm512_sub_epi64(D1_5,borrow);
	borrow  = _mm512_srli_epi64(D1_5,52)&un;
	D1_5 = _mm512_and_si512(D1_5,mask52);

	borrow = _mm512_add_epi64(tmp6,borrow);
	D1_6 = _mm512_sub_epi64(D1_6,borrow);
	borrow  = _mm512_srli_epi64(D1_6,52)&un;
	D1_6 = _mm512_and_si512(D1_6,mask52);

	borrow = _mm512_add_epi64(tmp7,borrow);
	D1_7 = _mm512_sub_epi64(D1_7,borrow);
	borrow  = _mm512_srli_epi64(D1_7,52)&un;
	D1_7 = _mm512_and_si512(D1_7,mask52);

	borrow = _mm512_add_epi64(tmp8,borrow);
	D1_8 = _mm512_sub_epi64(D1_8,borrow);
	borrow  = _mm512_srli_epi64(D1_8,52)&un;
	D1_8 = _mm512_and_si512(D1_8,mask52);

	borrow = _mm512_add_epi64(tmp9,borrow);
	D1_9 = _mm512_sub_epi64(D1_9,borrow);
	borrow = _mm512_srli_epi64(D1_9,51)&un;
	D1_9 = _mm512_and_si512(D1_9,mask51);// radix 2**519

	borrow = _mm512_add_epi64(tmp10,borrow);
	D1_10 = _mm512_sub_epi64(D1_10,borrow);
	borrow  = _mm512_srli_epi64(D1_10,52)&un;
	D1_10 = _mm512_and_si512(D1_10,mask52);

	borrow = _mm512_add_epi64(tmp11,borrow);
	D1_11 = _mm512_sub_epi64(D1_11,borrow);
	borrow  = _mm512_srli_epi64(D1_11,52)&un;
	D1_11 = _mm512_and_si512(D1_11,mask52);

	borrow = _mm512_add_epi64(tmp12,borrow);
	D1_12 = _mm512_sub_epi64(D1_12,borrow);
	borrow  = _mm512_srli_epi64(D1_12,52)&un;
	D1_12 = _mm512_and_si512(D1_12,mask52);

	borrow = _mm512_add_epi64(tmp13,borrow);
	D1_13 = _mm512_sub_epi64(D1_13,borrow);
	borrow  = _mm512_srli_epi64(D1_13,52)&un;
	D1_13 = _mm512_and_si512(D1_13,mask52);

	borrow = _mm512_add_epi64(tmp14,borrow);
	D1_14 = _mm512_sub_epi64(D1_14,borrow);
	borrow  = _mm512_srli_epi64(D1_14,52)&un;
	D1_14 = _mm512_and_si512(D1_14,mask52);

	borrow = _mm512_add_epi64(tmp15,borrow);
	D1_15 = _mm512_sub_epi64(D1_15,borrow);
	borrow  = _mm512_srli_epi64(D1_15,52)&un;
	D1_15 = _mm512_and_si512(D1_15,mask52);

	borrow = _mm512_add_epi64(tmp16,borrow);
	D1_16 = _mm512_sub_epi64(D1_16,borrow);
	borrow  = _mm512_srli_epi64(D1_16,52)&un;
	D1_16 = _mm512_and_si512(D1_16,mask52);

	borrow = _mm512_add_epi64(tmp17,borrow);
	D1_17 = _mm512_sub_epi64(D1_17,borrow);
	borrow  = _mm512_srli_epi64(D1_17,52)&un;
	D1_17 = _mm512_and_si512(D1_17,mask52);

	borrow = _mm512_add_epi64(tmp18,borrow);
	D1_18 = _mm512_sub_epi64(D1_18,borrow);
	borrow  = _mm512_srli_epi64(D1_18,52)&un;
	D1_18 = _mm512_and_si512(D1_18,mask52);

	borrow = _mm512_add_epi64(tmp19,borrow);
	D1_19 = _mm512_sub_epi64(D1_19,borrow);
	borrow = _mm512_srli_epi64(D1_19,51)&un;
	D1_19 = _mm512_and_si512(D1_19,mask51);// radix 2**519


	// Final borrows

	borrow = _mm512_add_epi64(carry_tmp,borrow);
	D2_10 = _mm512_add_epi64(D2_10,carry);
	D2_10 = _mm512_sub_epi64(D2_10,borrow);
	borrow  = _mm512_srli_epi64(D2_10,52)&un;
	D2_10 = _mm512_and_si512(D2_10,mask52);

	D2_11 = _mm512_sub_epi64(D2_11,borrow);
	borrow  = _mm512_srli_epi64(D2_11,52)&un;
	D2_11 = _mm512_and_si512(D2_11,mask52);

	D2_12 = _mm512_sub_epi64(D2_12,borrow);
	borrow  = _mm512_srli_epi64(D2_12,52)&un;
	D2_12 = _mm512_and_si512(D2_12,mask52);

	D2_13 = _mm512_sub_epi64(D2_13,borrow);
	borrow  = _mm512_srli_epi64(D2_13,52)&un;
	D2_13 = _mm512_and_si512(D2_13,mask52);

	D2_14 = _mm512_sub_epi64(D2_14,borrow);
	borrow  = _mm512_srli_epi64(D2_14,52)&un;
	D2_14 = _mm512_and_si512(D2_14,mask52);

	D2_15 = _mm512_sub_epi64(D2_15,borrow);
	borrow  = _mm512_srli_epi64(D2_15,52)&un;
	D2_15 = _mm512_and_si512(D2_15,mask52);

	D2_16 = _mm512_sub_epi64(D2_16,borrow);
	borrow  = _mm512_srli_epi64(D2_16,52)&un;
	D2_16 = _mm512_and_si512(D2_16,mask52);

	D2_17 = _mm512_sub_epi64(D2_17,borrow);
	borrow  = _mm512_srli_epi64(D2_17,52)&un;
	D2_17 = _mm512_and_si512(D2_17,mask52);

	D2_18 = _mm512_sub_epi64(D2_18,borrow);
	borrow  = _mm512_srli_epi64(D2_18,52)&un;
	D2_18 = _mm512_and_si512(D2_18,mask52);

	D2_19 = _mm512_sub_epi64(D2_19,borrow);


	_mm512_store_epi64(out+0,D0_0);
	_mm512_store_epi64(out+1,D0_1);
	_mm512_store_epi64(out+2,D0_2);
	_mm512_store_epi64(out+3,D0_3);
	_mm512_store_epi64(out+4,D0_4);
	_mm512_store_epi64(out+5,D0_5);
	_mm512_store_epi64(out+6,D0_6);
	_mm512_store_epi64(out+7,D0_7);
	_mm512_store_epi64(out+8,D0_8);
	_mm512_store_epi64(out+9,D0_9);
	_mm512_store_epi64(out+10,D1_0);
	_mm512_store_epi64(out+11,D1_1);
	_mm512_store_epi64(out+12,D1_2);
	_mm512_store_epi64(out+13,D1_3);
	_mm512_store_epi64(out+14,D1_4);
	_mm512_store_epi64(out+15,D1_5);
	_mm512_store_epi64(out+16,D1_6);
	_mm512_store_epi64(out+17,D1_7);
	_mm512_store_epi64(out+18,D1_8);
	_mm512_store_epi64(out+19,D1_9);
	_mm512_store_epi64(out+20,D1_10);
	_mm512_store_epi64(out+21,D1_11);
	_mm512_store_epi64(out+22,D1_12);
	_mm512_store_epi64(out+23,D1_13);
	_mm512_store_epi64(out+24,D1_14);
	_mm512_store_epi64(out+25,D1_15);
	_mm512_store_epi64(out+26,D1_16);
	_mm512_store_epi64(out+27,D1_17);
	_mm512_store_epi64(out+28,D1_18);
	_mm512_store_epi64(out+29,D1_19);
	_mm512_store_epi64(out+30,D2_10);
	_mm512_store_epi64(out+31,D2_11);
	_mm512_store_epi64(out+32,D2_12);
	_mm512_store_epi64(out+33,D2_13);
	_mm512_store_epi64(out+34,D2_14);
	_mm512_store_epi64(out+35,D2_15);
	_mm512_store_epi64(out+36,D2_16);
	_mm512_store_epi64(out+37,D2_17);
	_mm512_store_epi64(out+38,D2_18);
	_mm512_store_epi64(out+39,D2_19);
}

