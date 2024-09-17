/* Karatsuba multiplication mod M*/

inline void force_inline mul512_8_518K_modM(__m512i out[20], __m512i a512[10], __m512i b512[10])
{

	// D0 = Al*Bl

	__m512i D0_0, D0_1;
	__m512i D0_2, D0_3;
	__m512i D0_4, D0_5;
	__m512i D0_6, D0_7;
	__m512i D0_8, D0_9;
	__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512);
	__m512i a5121 = _mm512_load_epi64(a512+1), b5121 = _mm512_load_epi64(b512+1);
	__m512i a5122 = _mm512_load_epi64(a512+2), b5122 = _mm512_load_epi64(b512+2);
	__m512i a5123 = _mm512_load_epi64(a512+3), b5123 = _mm512_load_epi64(b512+3);
	__m512i a5124 = _mm512_load_epi64(a512+4), b5124 = _mm512_load_epi64(b512+4);
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

	D0_1 = _mm512_madd52lo_epu64(D0_1,a5121,b5120);
	D0_2 = _mm512_madd52hi_epu64(D0_2,a5121,b5120);
	D0_2 = _mm512_madd52lo_epu64(D0_2,a5121,b5121);
	D0_3 = _mm512_madd52hi_epu64(D0_3,a5121,b5121);
	D0_3 = _mm512_madd52lo_epu64(D0_3,a5121,b5122);
	D0_4 = _mm512_madd52hi_epu64(D0_4,a5121,b5122);
	D0_4 = _mm512_madd52lo_epu64(D0_4,a5121,b5123);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5121,b5123);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5121,b5124);
	D0_6 = _mm512_madd52hi_epu64(zero,a5121,b5124);

	D0_2 = _mm512_madd52lo_epu64(D0_2,a5122,b5120);
	D0_3 = _mm512_madd52hi_epu64(D0_3,a5122,b5120);
	D0_3 = _mm512_madd52lo_epu64(D0_3,a5122,b5121);
	D0_4 = _mm512_madd52hi_epu64(D0_4,a5122,b5121);
	D0_4 = _mm512_madd52lo_epu64(D0_4,a5122,b5122);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5122,b5122);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5122,b5123);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5122,b5123);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5122,b5124);
	D0_7 = _mm512_madd52hi_epu64(zero,a5122,b5124);

	D0_3 = _mm512_madd52lo_epu64(D0_3,a5123,b5120);
	D0_4 = _mm512_madd52hi_epu64(D0_4,a5123,b5120);
	D0_4 = _mm512_madd52lo_epu64(D0_4,a5123,b5121);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5123,b5121);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5123,b5122);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5123,b5122);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5123,b5123);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5123,b5123);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5123,b5124);
	D0_8 = _mm512_madd52hi_epu64(zero,a5123,b5124);

	D0_4 = _mm512_madd52lo_epu64(D0_4,a5124,b5120);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5124,b5120);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5124,b5121);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5124,b5121);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5124,b5122);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5124,b5122);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5124,b5123);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5124,b5123);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5124,b5124);
	D0_9 = _mm512_madd52hi_epu64(zero,a5124,b5124);


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

	// Conversion in base 2^259

	carry = D0_4>>51;
	D0_5 = (D0_5<<1)|carry;
	D0_4 &= mask51;
	carry = D0_5>>52;
	D0_6 = (D0_6<<1)|carry;
	D0_5 &= mask52;
	carry = D0_6>>52;
	D0_7 = (D0_7<<1)|carry;
	D0_6 &= mask52;
	carry = D0_7>>52;
	D0_8 = (D0_8<<1)|carry;
	D0_7 &= mask52;
	carry = D0_8>>52;
	D0_9 = (D0_9<<1)|carry;
	D0_8 &= mask52;

	// D2 = Ah*Bh

	__m512i D2_0;
	__m512i D2_1;
	__m512i D2_2;
	__m512i D2_3;
	__m512i D2_4;
	__m512i a5125 = _mm512_load_epi64(a512+5), b5125 = _mm512_load_epi64(b512+5);
	__m512i a5126 = _mm512_load_epi64(a512+6), b5126 = _mm512_load_epi64(b512+6);
	__m512i a5127 = _mm512_load_epi64(a512+7), b5127 = _mm512_load_epi64(b512+7);
	__m512i a5128 = _mm512_load_epi64(a512+8), b5128 = _mm512_load_epi64(b512+8);
	__m512i a5129 = _mm512_load_epi64(a512+9), b5129 = _mm512_load_epi64(b512+9);
	D2_0 = _mm512_madd52lo_epu64(zero,a5125,b5125);
	D2_1 = _mm512_madd52hi_epu64(zero,a5125,b5125);
	D2_1 = _mm512_madd52lo_epu64(D2_1,a5125,b5126);
	D2_2 = _mm512_madd52hi_epu64(zero,a5125,b5126);
	D2_2 = _mm512_madd52lo_epu64(D2_2,a5125,b5127);
	D2_3 = _mm512_madd52hi_epu64(zero,a5125,b5127);
	D2_3 = _mm512_madd52lo_epu64(D2_3,a5125,b5128);
	D2_4 = _mm512_madd52hi_epu64(zero,a5125,b5128);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a5125,b5129);

	D2_1 = _mm512_madd52lo_epu64(D2_1,a5126,b5125);
	D2_2 = _mm512_madd52hi_epu64(D2_2,a5126,b5125);
	D2_2 = _mm512_madd52lo_epu64(D2_2,a5126,b5126);
	D2_3 = _mm512_madd52hi_epu64(D2_3,a5126,b5126);
	D2_3 = _mm512_madd52lo_epu64(D2_3,a5126,b5127);
	D2_4 = _mm512_madd52hi_epu64(D2_4,a5126,b5127);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a5126,b5128);

	D2_2 = _mm512_madd52lo_epu64(D2_2,a5127,b5125);
	D2_3 = _mm512_madd52hi_epu64(D2_3,a5127,b5125);
	D2_3 = _mm512_madd52lo_epu64(D2_3,a5127,b5126);
	D2_4 = _mm512_madd52hi_epu64(D2_4,a5127,b5126);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a5127,b5127);

	D2_3 = _mm512_madd52lo_epu64(D2_3,a5128,b5125);
	D2_4 = _mm512_madd52hi_epu64(D2_4,a5128,b5125);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a5128,b5126);

	D2_4 = _mm512_madd52lo_epu64(D2_4,a5129,b5125);


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

	// D1 = (Al+Ah)*(Bl+Bh)

	__m512i D1_0;
	__m512i D1_1;
	__m512i D1_2;
	__m512i D1_3;
	__m512i D1_4;

	__m512i alpah0 = _mm512_add_epi64(a5120,a5125);
	carry = alpah0>>52;
	alpah0 &= mask52;
	__m512i alpah1 = _mm512_add_epi64(a5121,carry);
	alpah1 = _mm512_add_epi64(alpah1,a5126);
	carry = alpah1>>52;
	alpah1 &= mask52;
	__m512i alpah2 = _mm512_add_epi64(a5122,carry);
	alpah2 = _mm512_add_epi64(alpah2,a5127);
	carry = alpah2>>52;
	alpah2 &= mask52;
	__m512i alpah3 = _mm512_add_epi64(a5123,carry);
	alpah3 = _mm512_add_epi64(alpah3,a5128);
	carry = alpah3>>52;
	alpah3 &= mask52;
	__m512i alpah4 = _mm512_add_epi64(a5124,carry);
	alpah4 = _mm512_add_epi64(alpah4,a5129);
	carry = alpah4>>52;
	alpah4 &= mask52;
	__m512i blpbh0 = _mm512_add_epi64(b5120,b5125);
	carry = blpbh0>>52;
	blpbh0 &= mask52;
	__m512i blpbh1 = _mm512_add_epi64(b5121,carry);
	blpbh1 = _mm512_add_epi64(blpbh1,b5126);
	carry = blpbh1>>52;
	blpbh1 &= mask52;
	__m512i blpbh2 = _mm512_add_epi64(b5122,carry);
	blpbh2 = _mm512_add_epi64(blpbh2,b5127);
	carry = blpbh2>>52;
	blpbh2 &= mask52;
	__m512i blpbh3 = _mm512_add_epi64(b5123,carry);
	blpbh3 = _mm512_add_epi64(blpbh3,b5128);
	carry = blpbh3>>52;
	blpbh3 &= mask52;
	__m512i blpbh4 = _mm512_add_epi64(b5124,carry);
	blpbh4 = _mm512_add_epi64(blpbh4,b5129);
	carry = blpbh4>>52;
	blpbh4 &= mask52;
	D1_0 = _mm512_madd52lo_epu64(D0_5,alpah0,blpbh0);
	D1_1 = _mm512_madd52hi_epu64(D0_6,alpah0,blpbh0);
	D1_1 = _mm512_madd52lo_epu64(D1_1,alpah0,blpbh1);
	D1_2 = _mm512_madd52hi_epu64(D0_7,alpah0,blpbh1);
	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah0,blpbh2);
	D1_3 = _mm512_madd52hi_epu64(D0_8,alpah0,blpbh2);
	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah0,blpbh3);
	D1_4 = _mm512_madd52hi_epu64(D0_9,alpah0,blpbh3);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah0,blpbh4);

	D1_1 = _mm512_madd52lo_epu64(D1_1,alpah1,blpbh0);
	D1_2 = _mm512_madd52hi_epu64(D1_2,alpah1,blpbh0);
	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah1,blpbh1);
	D1_3 = _mm512_madd52hi_epu64(D1_3,alpah1,blpbh1);
	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah1,blpbh2);
	D1_4 = _mm512_madd52hi_epu64(D1_4,alpah1,blpbh2);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah1,blpbh3);

	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah2,blpbh0);
	D1_3 = _mm512_madd52hi_epu64(D1_3,alpah2,blpbh0);
	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah2,blpbh1);
	D1_4 = _mm512_madd52hi_epu64(D1_4,alpah2,blpbh1);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah2,blpbh2);

	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah3,blpbh0);
	D1_4 = _mm512_madd52hi_epu64(D1_4,alpah3,blpbh0);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah3,blpbh1);

	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah4,blpbh0);


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

	// Final reconstruction


	// tmp = D0+D2, radix 2^259

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
	carry_tmp  = _mm512_srli_epi64(tmp4,51);
	tmp4 = _mm512_and_si512(tmp4,mask51);// radix 2**259


	// D1 = D1 -tmp, radix 2^259

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
	borrow = _mm512_srli_epi64(D1_4,51)&un;
	D1_4 = _mm512_and_si512(D1_4,mask51);// radix 2**259



	_mm512_store_epi64(out+0,D0_0);
	_mm512_store_epi64(out+1,D0_1);
	_mm512_store_epi64(out+2,D0_2);
	_mm512_store_epi64(out+3,D0_3);
	_mm512_store_epi64(out+4,D0_4);
	_mm512_store_epi64(out+5,D1_0);
	_mm512_store_epi64(out+6,D1_1);
	_mm512_store_epi64(out+7,D1_2);
	_mm512_store_epi64(out+8,D1_3);
	_mm512_store_epi64(out+9,D1_4);

}

/* Karatsuba multiplication */

inline void force_inline mul512_8_518K(__m512i out[20], __m512i a512[10], __m512i b512[10])
{

	// D0 = Al*Bl

	__m512i D0_0, D0_1;
	__m512i D0_2, D0_3;
	__m512i D0_4, D0_5;
	__m512i D0_6, D0_7;
	__m512i D0_8, D0_9;
	__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512);
	__m512i a5121 = _mm512_load_epi64(a512+1), b5121 = _mm512_load_epi64(b512+1);
	__m512i a5122 = _mm512_load_epi64(a512+2), b5122 = _mm512_load_epi64(b512+2);
	__m512i a5123 = _mm512_load_epi64(a512+3), b5123 = _mm512_load_epi64(b512+3);
	__m512i a5124 = _mm512_load_epi64(a512+4), b5124 = _mm512_load_epi64(b512+4);
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

	D0_1 = _mm512_madd52lo_epu64(D0_1,a5121,b5120);
	D0_2 = _mm512_madd52hi_epu64(D0_2,a5121,b5120);
	D0_2 = _mm512_madd52lo_epu64(D0_2,a5121,b5121);
	D0_3 = _mm512_madd52hi_epu64(D0_3,a5121,b5121);
	D0_3 = _mm512_madd52lo_epu64(D0_3,a5121,b5122);
	D0_4 = _mm512_madd52hi_epu64(D0_4,a5121,b5122);
	D0_4 = _mm512_madd52lo_epu64(D0_4,a5121,b5123);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5121,b5123);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5121,b5124);
	D0_6 = _mm512_madd52hi_epu64(zero,a5121,b5124);

	D0_2 = _mm512_madd52lo_epu64(D0_2,a5122,b5120);
	D0_3 = _mm512_madd52hi_epu64(D0_3,a5122,b5120);
	D0_3 = _mm512_madd52lo_epu64(D0_3,a5122,b5121);
	D0_4 = _mm512_madd52hi_epu64(D0_4,a5122,b5121);
	D0_4 = _mm512_madd52lo_epu64(D0_4,a5122,b5122);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5122,b5122);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5122,b5123);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5122,b5123);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5122,b5124);
	D0_7 = _mm512_madd52hi_epu64(zero,a5122,b5124);

	D0_3 = _mm512_madd52lo_epu64(D0_3,a5123,b5120);
	D0_4 = _mm512_madd52hi_epu64(D0_4,a5123,b5120);
	D0_4 = _mm512_madd52lo_epu64(D0_4,a5123,b5121);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5123,b5121);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5123,b5122);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5123,b5122);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5123,b5123);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5123,b5123);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5123,b5124);
	D0_8 = _mm512_madd52hi_epu64(zero,a5123,b5124);

	D0_4 = _mm512_madd52lo_epu64(D0_4,a5124,b5120);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5124,b5120);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5124,b5121);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5124,b5121);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5124,b5122);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5124,b5122);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5124,b5123);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5124,b5123);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5124,b5124);
	D0_9 = _mm512_madd52hi_epu64(zero,a5124,b5124);


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

	// Conversion in base 2^259

	carry = D0_4>>51;
	D0_5 = (D0_5<<1)|carry;
	D0_4 &= mask51;
	carry = D0_5>>52;
	D0_6 = (D0_6<<1)|carry;
	D0_5 &= mask52;
	carry = D0_6>>52;
	D0_7 = (D0_7<<1)|carry;
	D0_6 &= mask52;
	carry = D0_7>>52;
	D0_8 = (D0_8<<1)|carry;
	D0_7 &= mask52;
	carry = D0_8>>52;
	D0_9 = (D0_9<<1)|carry;
	D0_8 &= mask52;

	// D2 = Ah*Bh

	__m512i D2_0, D2_1;
	__m512i D2_2, D2_3;
	__m512i D2_4, D2_5;
	__m512i D2_6, D2_7;
	__m512i D2_8, D2_9;
	__m512i a5125 = _mm512_load_epi64(a512+5), b5125 = _mm512_load_epi64(b512+5);
	__m512i a5126 = _mm512_load_epi64(a512+6), b5126 = _mm512_load_epi64(b512+6);
	__m512i a5127 = _mm512_load_epi64(a512+7), b5127 = _mm512_load_epi64(b512+7);
	__m512i a5128 = _mm512_load_epi64(a512+8), b5128 = _mm512_load_epi64(b512+8);
	__m512i a5129 = _mm512_load_epi64(a512+9), b5129 = _mm512_load_epi64(b512+9);
	D2_0 = _mm512_madd52lo_epu64(zero,a5125,b5125);
	D2_1 = _mm512_madd52hi_epu64(zero,a5125,b5125);
	D2_1 = _mm512_madd52lo_epu64(D2_1,a5125,b5126);
	D2_2 = _mm512_madd52hi_epu64(zero,a5125,b5126);
	D2_2 = _mm512_madd52lo_epu64(D2_2,a5125,b5127);
	D2_3 = _mm512_madd52hi_epu64(zero,a5125,b5127);
	D2_3 = _mm512_madd52lo_epu64(D2_3,a5125,b5128);
	D2_4 = _mm512_madd52hi_epu64(zero,a5125,b5128);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a5125,b5129);
	D2_5 = _mm512_madd52hi_epu64(zero,a5125,b5129);

	D2_1 = _mm512_madd52lo_epu64(D2_1,a5126,b5125);
	D2_2 = _mm512_madd52hi_epu64(D2_2,a5126,b5125);
	D2_2 = _mm512_madd52lo_epu64(D2_2,a5126,b5126);
	D2_3 = _mm512_madd52hi_epu64(D2_3,a5126,b5126);
	D2_3 = _mm512_madd52lo_epu64(D2_3,a5126,b5127);
	D2_4 = _mm512_madd52hi_epu64(D2_4,a5126,b5127);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a5126,b5128);
	D2_5 = _mm512_madd52hi_epu64(D2_5,a5126,b5128);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a5126,b5129);
	D2_6 = _mm512_madd52hi_epu64(zero,a5126,b5129);

	D2_2 = _mm512_madd52lo_epu64(D2_2,a5127,b5125);
	D2_3 = _mm512_madd52hi_epu64(D2_3,a5127,b5125);
	D2_3 = _mm512_madd52lo_epu64(D2_3,a5127,b5126);
	D2_4 = _mm512_madd52hi_epu64(D2_4,a5127,b5126);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a5127,b5127);
	D2_5 = _mm512_madd52hi_epu64(D2_5,a5127,b5127);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a5127,b5128);
	D2_6 = _mm512_madd52hi_epu64(D2_6,a5127,b5128);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a5127,b5129);
	D2_7 = _mm512_madd52hi_epu64(zero,a5127,b5129);

	D2_3 = _mm512_madd52lo_epu64(D2_3,a5128,b5125);
	D2_4 = _mm512_madd52hi_epu64(D2_4,a5128,b5125);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a5128,b5126);
	D2_5 = _mm512_madd52hi_epu64(D2_5,a5128,b5126);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a5128,b5127);
	D2_6 = _mm512_madd52hi_epu64(D2_6,a5128,b5127);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a5128,b5128);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a5128,b5128);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a5128,b5129);
	D2_8 = _mm512_madd52hi_epu64(zero,a5128,b5129);

	D2_4 = _mm512_madd52lo_epu64(D2_4,a5129,b5125);
	D2_5 = _mm512_madd52hi_epu64(D2_5,a5129,b5125);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a5129,b5126);
	D2_6 = _mm512_madd52hi_epu64(D2_6,a5129,b5126);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a5129,b5127);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a5129,b5127);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a5129,b5128);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a5129,b5128);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a5129,b5129);
	D2_9 = _mm512_madd52hi_epu64(zero,a5129,b5129);


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

	// Conversion in base 2^259

	carry = D2_4>>51;
	D2_5 = (D2_5<<1)|carry;
	D2_4 &= mask51;
	carry = D2_5>>52;
	D2_6 = (D2_6<<1)|carry;
	D2_5 &= mask52;
	carry = D2_6>>52;
	D2_7 = (D2_7<<1)|carry;
	D2_6 &= mask52;
	carry = D2_7>>52;
	D2_8 = (D2_8<<1)|carry;
	D2_7 &= mask52;
	carry = D2_8>>52;
	D2_9 = (D2_9<<1)|carry;
	D2_8 &= mask52;

	// D1 = (Al+Ah)*(Bl+Bh)

	__m512i D1_0, D1_1;
	__m512i D1_2, D1_3;
	__m512i D1_4, D1_5;
	__m512i D1_6, D1_7;
	__m512i D1_8, D1_9;

	__m512i alpah0 = _mm512_add_epi64(a5120,a5125);
	carry = alpah0>>52;
	alpah0 &= mask52;
	__m512i alpah1 = _mm512_add_epi64(a5121,carry);
	alpah1 = _mm512_add_epi64(alpah1,a5126);
	carry = alpah1>>52;
	alpah1 &= mask52;
	__m512i alpah2 = _mm512_add_epi64(a5122,carry);
	alpah2 = _mm512_add_epi64(alpah2,a5127);
	carry = alpah2>>52;
	alpah2 &= mask52;
	__m512i alpah3 = _mm512_add_epi64(a5123,carry);
	alpah3 = _mm512_add_epi64(alpah3,a5128);
	carry = alpah3>>52;
	alpah3 &= mask52;
	__m512i alpah4 = _mm512_add_epi64(a5124,carry);
	alpah4 = _mm512_add_epi64(alpah4,a5129);
	carry = alpah4>>52;
	alpah4 &= mask52;
	__m512i blpbh0 = _mm512_add_epi64(b5120,b5125);
	carry = blpbh0>>52;
	blpbh0 &= mask52;
	__m512i blpbh1 = _mm512_add_epi64(b5121,carry);
	blpbh1 = _mm512_add_epi64(blpbh1,b5126);
	carry = blpbh1>>52;
	blpbh1 &= mask52;
	__m512i blpbh2 = _mm512_add_epi64(b5122,carry);
	blpbh2 = _mm512_add_epi64(blpbh2,b5127);
	carry = blpbh2>>52;
	blpbh2 &= mask52;
	__m512i blpbh3 = _mm512_add_epi64(b5123,carry);
	blpbh3 = _mm512_add_epi64(blpbh3,b5128);
	carry = blpbh3>>52;
	blpbh3 &= mask52;
	__m512i blpbh4 = _mm512_add_epi64(b5124,carry);
	blpbh4 = _mm512_add_epi64(blpbh4,b5129);
	carry = blpbh4>>52;
	blpbh4 &= mask52;
	D1_0 = _mm512_madd52lo_epu64(D0_5,alpah0,blpbh0);
	D1_1 = _mm512_madd52hi_epu64(D0_6,alpah0,blpbh0);
	D1_1 = _mm512_madd52lo_epu64(D1_1,alpah0,blpbh1);
	D1_2 = _mm512_madd52hi_epu64(D0_7,alpah0,blpbh1);
	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah0,blpbh2);
	D1_3 = _mm512_madd52hi_epu64(D0_8,alpah0,blpbh2);
	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah0,blpbh3);
	D1_4 = _mm512_madd52hi_epu64(D0_9,alpah0,blpbh3);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah0,blpbh4);
	D1_5 = _mm512_madd52hi_epu64(zero,alpah0,blpbh4);

	D1_1 = _mm512_madd52lo_epu64(D1_1,alpah1,blpbh0);
	D1_2 = _mm512_madd52hi_epu64(D1_2,alpah1,blpbh0);
	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah1,blpbh1);
	D1_3 = _mm512_madd52hi_epu64(D1_3,alpah1,blpbh1);
	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah1,blpbh2);
	D1_4 = _mm512_madd52hi_epu64(D1_4,alpah1,blpbh2);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah1,blpbh3);
	D1_5 = _mm512_madd52hi_epu64(D1_5,alpah1,blpbh3);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah1,blpbh4);
	D1_6 = _mm512_madd52hi_epu64(zero,alpah1,blpbh4);

	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah2,blpbh0);
	D1_3 = _mm512_madd52hi_epu64(D1_3,alpah2,blpbh0);
	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah2,blpbh1);
	D1_4 = _mm512_madd52hi_epu64(D1_4,alpah2,blpbh1);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah2,blpbh2);
	D1_5 = _mm512_madd52hi_epu64(D1_5,alpah2,blpbh2);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah2,blpbh3);
	D1_6 = _mm512_madd52hi_epu64(D1_6,alpah2,blpbh3);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah2,blpbh4);
	D1_7 = _mm512_madd52hi_epu64(zero,alpah2,blpbh4);

	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah3,blpbh0);
	D1_4 = _mm512_madd52hi_epu64(D1_4,alpah3,blpbh0);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah3,blpbh1);
	D1_5 = _mm512_madd52hi_epu64(D1_5,alpah3,blpbh1);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah3,blpbh2);
	D1_6 = _mm512_madd52hi_epu64(D1_6,alpah3,blpbh2);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah3,blpbh3);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah3,blpbh3);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah3,blpbh4);
	D1_8 = _mm512_madd52hi_epu64(zero,alpah3,blpbh4);

	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah4,blpbh0);
	D1_5 = _mm512_madd52hi_epu64(D1_5,alpah4,blpbh0);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah4,blpbh1);
	D1_6 = _mm512_madd52hi_epu64(D1_6,alpah4,blpbh1);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah4,blpbh2);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah4,blpbh2);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah4,blpbh3);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah4,blpbh3);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah4,blpbh4);
	D1_9 = _mm512_madd52hi_epu64(zero,alpah4,blpbh4);


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

	// Conversion in base 2^259

	carry  = _mm512_srli_epi64(D1_4,51);
	D1_4 = _mm512_and_si512(D1_4,mask51);// radix 2^259
	D1_5 = _mm512_add_epi64(_mm512_slli_epi64(D1_5,1),carry);
	D1_5 = _mm512_add_epi64(D1_5,D2_0);
	carry = _mm512_srli_epi64(D1_5,52);
	D1_5 = _mm512_and_si512(D1_5,mask52);
	D1_6 = _mm512_add_epi64(_mm512_slli_epi64(D1_6,1),carry);
	D1_6 = _mm512_add_epi64(D1_6,D2_1);
	carry = _mm512_srli_epi64(D1_6,52);
	D1_6 = _mm512_and_si512(D1_6,mask52);
	D1_7 = _mm512_add_epi64(_mm512_slli_epi64(D1_7,1),carry);
	D1_7 = _mm512_add_epi64(D1_7,D2_2);
	carry = _mm512_srli_epi64(D1_7,52);
	D1_7 = _mm512_and_si512(D1_7,mask52);
	D1_8 = _mm512_add_epi64(_mm512_slli_epi64(D1_8,1),carry);
	D1_8 = _mm512_add_epi64(D1_8,D2_3);
	carry = _mm512_srli_epi64(D1_8,52);
	D1_8 = _mm512_and_si512(D1_8,mask52);
	D1_9 = _mm512_add_epi64(_mm512_slli_epi64(D1_9,1),carry);
	D1_9 = _mm512_add_epi64(D1_9,D2_4);
	carry  = _mm512_srli_epi64(D1_9,51);
	D1_9 = _mm512_and_si512(D1_9,mask51);// radix 2^259

	// Final reconstruction


	// tmp = D0+D2, radix 2^259

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
	carry_tmp  = _mm512_srli_epi64(tmp4,51);
	tmp4 = _mm512_and_si512(tmp4,mask51);// radix 2**259

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
	tmp9 = _mm512_and_si512(tmp9,mask51);// radix 2**259




	// D1 = D1 -tmp, radix 2^259

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
	borrow = _mm512_srli_epi64(D1_4,51)&un;
	D1_4 = _mm512_and_si512(D1_4,mask51);// radix 2**259

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
	D1_9 = _mm512_and_si512(D1_9,mask51);// radix 2**259


	// Final borrows

	borrow = _mm512_add_epi64(carry_tmp,borrow);
	D2_5 = _mm512_add_epi64(D2_5,carry);
	D2_5 = _mm512_sub_epi64(D2_5,borrow);
	borrow  = _mm512_srli_epi64(D2_5,52)&un;
	D2_5 = _mm512_and_si512(D2_5,mask52);

	D2_6 = _mm512_sub_epi64(D2_6,borrow);
	borrow  = _mm512_srli_epi64(D2_6,52)&un;
	D2_6 = _mm512_and_si512(D2_6,mask52);

	D2_7 = _mm512_sub_epi64(D2_7,borrow);
	borrow  = _mm512_srli_epi64(D2_7,52)&un;
	D2_7 = _mm512_and_si512(D2_7,mask52);

	D2_8 = _mm512_sub_epi64(D2_8,borrow);
	borrow  = _mm512_srli_epi64(D2_8,52)&un;
	D2_8 = _mm512_and_si512(D2_8,mask52);

	D2_9 = _mm512_sub_epi64(D2_9,borrow);


	_mm512_store_epi64(out+0,D0_0);
	_mm512_store_epi64(out+1,D0_1);
	_mm512_store_epi64(out+2,D0_2);
	_mm512_store_epi64(out+3,D0_3);
	_mm512_store_epi64(out+4,D0_4);
	_mm512_store_epi64(out+5,D1_0);
	_mm512_store_epi64(out+6,D1_1);
	_mm512_store_epi64(out+7,D1_2);
	_mm512_store_epi64(out+8,D1_3);
	_mm512_store_epi64(out+9,D1_4);
	_mm512_store_epi64(out+10,D1_5);
	_mm512_store_epi64(out+11,D1_6);
	_mm512_store_epi64(out+12,D1_7);
	_mm512_store_epi64(out+13,D1_8);
	_mm512_store_epi64(out+14,D1_9);
	_mm512_store_epi64(out+15,D2_5);
	_mm512_store_epi64(out+16,D2_6);
	_mm512_store_epi64(out+17,D2_7);
	_mm512_store_epi64(out+18,D2_8);
	_mm512_store_epi64(out+19,D2_9);

}

/* Karatsuba fma, computes C+AB */

inline void force_inline fma512_8_518K(__m512i out[20], __m512i a512[10], __m512i b512[10], __m512i c512[10])
{

	// D0 = Al*Bl

	__m512i D0_0, D0_1;
	__m512i D0_2, D0_3;
	__m512i D0_4, D0_5;
	__m512i D0_6, D0_7;
	__m512i D0_8, D0_9;
	__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512), c5120 = _mm512_load_epi64(c512);
	__m512i a5121 = _mm512_load_epi64(a512+1), b5121 = _mm512_load_epi64(b512+1), c5121 = _mm512_load_epi64(c512+1);
	__m512i a5122 = _mm512_load_epi64(a512+2), b5122 = _mm512_load_epi64(b512+2), c5122 = _mm512_load_epi64(c512+2);
	__m512i a5123 = _mm512_load_epi64(a512+3), b5123 = _mm512_load_epi64(b512+3), c5123 = _mm512_load_epi64(c512+3);
	__m512i a5124 = _mm512_load_epi64(a512+4), b5124 = _mm512_load_epi64(b512+4), c5124 = _mm512_load_epi64(c512+4);
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

	D0_1 = _mm512_madd52lo_epu64(D0_1,a5121,b5120);
	D0_2 = _mm512_madd52hi_epu64(D0_2,a5121,b5120);
	D0_2 = _mm512_madd52lo_epu64(D0_2,a5121,b5121);
	D0_3 = _mm512_madd52hi_epu64(D0_3,a5121,b5121);
	D0_3 = _mm512_madd52lo_epu64(D0_3,a5121,b5122);
	D0_4 = _mm512_madd52hi_epu64(D0_4,a5121,b5122);
	D0_4 = _mm512_madd52lo_epu64(D0_4,a5121,b5123);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5121,b5123);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5121,b5124);
	D0_6 = _mm512_madd52hi_epu64(c5121,a5121,b5124);

	D0_2 = _mm512_madd52lo_epu64(D0_2,a5122,b5120);
	D0_3 = _mm512_madd52hi_epu64(D0_3,a5122,b5120);
	D0_3 = _mm512_madd52lo_epu64(D0_3,a5122,b5121);
	D0_4 = _mm512_madd52hi_epu64(D0_4,a5122,b5121);
	D0_4 = _mm512_madd52lo_epu64(D0_4,a5122,b5122);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5122,b5122);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5122,b5123);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5122,b5123);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5122,b5124);
	D0_7 = _mm512_madd52hi_epu64(c5122,a5122,b5124);

	D0_3 = _mm512_madd52lo_epu64(D0_3,a5123,b5120);
	D0_4 = _mm512_madd52hi_epu64(D0_4,a5123,b5120);
	D0_4 = _mm512_madd52lo_epu64(D0_4,a5123,b5121);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5123,b5121);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5123,b5122);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5123,b5122);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5123,b5123);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5123,b5123);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5123,b5124);
	D0_8 = _mm512_madd52hi_epu64(c5123,a5123,b5124);

	D0_4 = _mm512_madd52lo_epu64(D0_4,a5124,b5120);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5124,b5120);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5124,b5121);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5124,b5121);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5124,b5122);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5124,b5122);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5124,b5123);
	D0_8 = _mm512_madd52hi_epu64(D0_8,a5124,b5123);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5124,b5124);
	D0_9 = _mm512_madd52hi_epu64(c5124,a5124,b5124);


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

	// Conversion in base 2^259

	carry = D0_4>>51;
	D0_5 = (D0_5<<1)|carry;
	D0_4 &= mask51;
	carry = D0_5>>52;
	D0_6 = (D0_6<<1)|carry;
	D0_5 &= mask52;
	carry = D0_6>>52;
	D0_7 = (D0_7<<1)|carry;
	D0_6 &= mask52;
	carry = D0_7>>52;
	D0_8 = (D0_8<<1)|carry;
	D0_7 &= mask52;
	carry = D0_8>>52;
	D0_9 = (D0_9<<1)|carry;
	D0_8 &= mask52;

	// D2 = Ah*Bh

	__m512i D2_0, D2_1;
	__m512i D2_2, D2_3;
	__m512i D2_4, D2_5;
	__m512i D2_6, D2_7;
	__m512i D2_8, D2_9;
	__m512i a5125 = _mm512_load_epi64(a512+5), b5125 = _mm512_load_epi64(b512+5);
	__m512i a5126 = _mm512_load_epi64(a512+6), b5126 = _mm512_load_epi64(b512+6);
	__m512i a5127 = _mm512_load_epi64(a512+7), b5127 = _mm512_load_epi64(b512+7);
	__m512i a5128 = _mm512_load_epi64(a512+8), b5128 = _mm512_load_epi64(b512+8);
	__m512i a5129 = _mm512_load_epi64(a512+9), b5129 = _mm512_load_epi64(b512+9);
	D2_0 = _mm512_madd52lo_epu64(zero,a5125,b5125);
	D2_1 = _mm512_madd52hi_epu64(zero,a5125,b5125);
	D2_1 = _mm512_madd52lo_epu64(D2_1,a5125,b5126);
	D2_2 = _mm512_madd52hi_epu64(zero,a5125,b5126);
	D2_2 = _mm512_madd52lo_epu64(D2_2,a5125,b5127);
	D2_3 = _mm512_madd52hi_epu64(zero,a5125,b5127);
	D2_3 = _mm512_madd52lo_epu64(D2_3,a5125,b5128);
	D2_4 = _mm512_madd52hi_epu64(zero,a5125,b5128);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a5125,b5129);
	D2_5 = _mm512_madd52hi_epu64(zero,a5125,b5129);

	D2_1 = _mm512_madd52lo_epu64(D2_1,a5126,b5125);
	D2_2 = _mm512_madd52hi_epu64(D2_2,a5126,b5125);
	D2_2 = _mm512_madd52lo_epu64(D2_2,a5126,b5126);
	D2_3 = _mm512_madd52hi_epu64(D2_3,a5126,b5126);
	D2_3 = _mm512_madd52lo_epu64(D2_3,a5126,b5127);
	D2_4 = _mm512_madd52hi_epu64(D2_4,a5126,b5127);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a5126,b5128);
	D2_5 = _mm512_madd52hi_epu64(D2_5,a5126,b5128);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a5126,b5129);
	D2_6 = _mm512_madd52hi_epu64(zero,a5126,b5129);

	D2_2 = _mm512_madd52lo_epu64(D2_2,a5127,b5125);
	D2_3 = _mm512_madd52hi_epu64(D2_3,a5127,b5125);
	D2_3 = _mm512_madd52lo_epu64(D2_3,a5127,b5126);
	D2_4 = _mm512_madd52hi_epu64(D2_4,a5127,b5126);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a5127,b5127);
	D2_5 = _mm512_madd52hi_epu64(D2_5,a5127,b5127);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a5127,b5128);
	D2_6 = _mm512_madd52hi_epu64(D2_6,a5127,b5128);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a5127,b5129);
	D2_7 = _mm512_madd52hi_epu64(zero,a5127,b5129);

	D2_3 = _mm512_madd52lo_epu64(D2_3,a5128,b5125);
	D2_4 = _mm512_madd52hi_epu64(D2_4,a5128,b5125);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a5128,b5126);
	D2_5 = _mm512_madd52hi_epu64(D2_5,a5128,b5126);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a5128,b5127);
	D2_6 = _mm512_madd52hi_epu64(D2_6,a5128,b5127);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a5128,b5128);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a5128,b5128);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a5128,b5129);
	D2_8 = _mm512_madd52hi_epu64(zero,a5128,b5129);

	D2_4 = _mm512_madd52lo_epu64(D2_4,a5129,b5125);
	D2_5 = _mm512_madd52hi_epu64(D2_5,a5129,b5125);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a5129,b5126);
	D2_6 = _mm512_madd52hi_epu64(D2_6,a5129,b5126);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a5129,b5127);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a5129,b5127);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a5129,b5128);
	D2_8 = _mm512_madd52hi_epu64(D2_8,a5129,b5128);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a5129,b5129);
	D2_9 = _mm512_madd52hi_epu64(zero,a5129,b5129);


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

	// Conversion in base 2^259

	carry = D2_4>>51;
	D2_5 = (D2_5<<1)|carry;
	D2_4 &= mask51;
	carry = D2_5>>52;
	D2_6 = (D2_6<<1)|carry;
	D2_5 &= mask52;
	carry = D2_6>>52;
	D2_7 = (D2_7<<1)|carry;
	D2_6 &= mask52;
	carry = D2_7>>52;
	D2_8 = (D2_8<<1)|carry;
	D2_7 &= mask52;
	carry = D2_8>>52;
	D2_9 = (D2_9<<1)|carry;
	D2_8 &= mask52;

	// D1 = (Al+Ah)*(Bl+Bh)

	__m512i D1_0, D1_1;
	__m512i D1_2, D1_3;
	__m512i D1_4, D1_5;
	__m512i D1_6, D1_7;
	__m512i D1_8, D1_9;

	__m512i alpah0 = _mm512_add_epi64(a5120,a5125);
	carry = alpah0>>52;
	alpah0 &= mask52;
	__m512i alpah1 = _mm512_add_epi64(a5121,carry);
	alpah1 = _mm512_add_epi64(alpah1,a5126);
	carry = alpah1>>52;
	alpah1 &= mask52;
	__m512i alpah2 = _mm512_add_epi64(a5122,carry);
	alpah2 = _mm512_add_epi64(alpah2,a5127);
	carry = alpah2>>52;
	alpah2 &= mask52;
	__m512i alpah3 = _mm512_add_epi64(a5123,carry);
	alpah3 = _mm512_add_epi64(alpah3,a5128);
	carry = alpah3>>52;
	alpah3 &= mask52;
	__m512i alpah4 = _mm512_add_epi64(a5124,carry);
	alpah4 = _mm512_add_epi64(alpah4,a5129);
	carry = alpah4>>52;
	alpah4 &= mask52;
	__m512i blpbh0 = _mm512_add_epi64(b5120,b5125);
	carry = blpbh0>>52;
	blpbh0 &= mask52;
	__m512i blpbh1 = _mm512_add_epi64(b5121,carry);
	blpbh1 = _mm512_add_epi64(blpbh1,b5126);
	carry = blpbh1>>52;
	blpbh1 &= mask52;
	__m512i blpbh2 = _mm512_add_epi64(b5122,carry);
	blpbh2 = _mm512_add_epi64(blpbh2,b5127);
	carry = blpbh2>>52;
	blpbh2 &= mask52;
	__m512i blpbh3 = _mm512_add_epi64(b5123,carry);
	blpbh3 = _mm512_add_epi64(blpbh3,b5128);
	carry = blpbh3>>52;
	blpbh3 &= mask52;
	__m512i blpbh4 = _mm512_add_epi64(b5124,carry);
	blpbh4 = _mm512_add_epi64(blpbh4,b5129);
	carry = blpbh4>>52;
	blpbh4 &= mask52;
	D1_0 = _mm512_madd52lo_epu64(D0_5,alpah0,blpbh0);
	D1_1 = _mm512_madd52hi_epu64(D0_6,alpah0,blpbh0);
	D1_1 = _mm512_madd52lo_epu64(D1_1,alpah0,blpbh1);
	D1_2 = _mm512_madd52hi_epu64(D0_7,alpah0,blpbh1);
	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah0,blpbh2);
	D1_3 = _mm512_madd52hi_epu64(D0_8,alpah0,blpbh2);
	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah0,blpbh3);
	D1_4 = _mm512_madd52hi_epu64(D0_9,alpah0,blpbh3);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah0,blpbh4);
	D1_5 = _mm512_madd52hi_epu64(zero,alpah0,blpbh4);

	D1_1 = _mm512_madd52lo_epu64(D1_1,alpah1,blpbh0);
	D1_2 = _mm512_madd52hi_epu64(D1_2,alpah1,blpbh0);
	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah1,blpbh1);
	D1_3 = _mm512_madd52hi_epu64(D1_3,alpah1,blpbh1);
	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah1,blpbh2);
	D1_4 = _mm512_madd52hi_epu64(D1_4,alpah1,blpbh2);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah1,blpbh3);
	D1_5 = _mm512_madd52hi_epu64(D1_5,alpah1,blpbh3);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah1,blpbh4);
	D1_6 = _mm512_madd52hi_epu64(zero,alpah1,blpbh4);

	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah2,blpbh0);
	D1_3 = _mm512_madd52hi_epu64(D1_3,alpah2,blpbh0);
	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah2,blpbh1);
	D1_4 = _mm512_madd52hi_epu64(D1_4,alpah2,blpbh1);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah2,blpbh2);
	D1_5 = _mm512_madd52hi_epu64(D1_5,alpah2,blpbh2);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah2,blpbh3);
	D1_6 = _mm512_madd52hi_epu64(D1_6,alpah2,blpbh3);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah2,blpbh4);
	D1_7 = _mm512_madd52hi_epu64(zero,alpah2,blpbh4);

	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah3,blpbh0);
	D1_4 = _mm512_madd52hi_epu64(D1_4,alpah3,blpbh0);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah3,blpbh1);
	D1_5 = _mm512_madd52hi_epu64(D1_5,alpah3,blpbh1);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah3,blpbh2);
	D1_6 = _mm512_madd52hi_epu64(D1_6,alpah3,blpbh2);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah3,blpbh3);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah3,blpbh3);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah3,blpbh4);
	D1_8 = _mm512_madd52hi_epu64(zero,alpah3,blpbh4);

	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah4,blpbh0);
	D1_5 = _mm512_madd52hi_epu64(D1_5,alpah4,blpbh0);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah4,blpbh1);
	D1_6 = _mm512_madd52hi_epu64(D1_6,alpah4,blpbh1);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah4,blpbh2);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah4,blpbh2);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah4,blpbh3);
	D1_8 = _mm512_madd52hi_epu64(D1_8,alpah4,blpbh3);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah4,blpbh4);
	D1_9 = _mm512_madd52hi_epu64(zero,alpah4,blpbh4);


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

	// Conversion in base 2^259

	carry  = _mm512_srli_epi64(D1_4,51);
	D1_4 = _mm512_and_si512(D1_4,mask51);// radix 2^259
	D1_5 = _mm512_add_epi64(_mm512_slli_epi64(D1_5,1),carry);
	D1_5 = _mm512_add_epi64(D1_5,D2_0);
	carry = _mm512_srli_epi64(D1_5,52);
	D1_5 = _mm512_and_si512(D1_5,mask52);
	D1_6 = _mm512_add_epi64(_mm512_slli_epi64(D1_6,1),carry);
	D1_6 = _mm512_add_epi64(D1_6,D2_1);
	carry = _mm512_srli_epi64(D1_6,52);
	D1_6 = _mm512_and_si512(D1_6,mask52);
	D1_7 = _mm512_add_epi64(_mm512_slli_epi64(D1_7,1),carry);
	D1_7 = _mm512_add_epi64(D1_7,D2_2);
	carry = _mm512_srli_epi64(D1_7,52);
	D1_7 = _mm512_and_si512(D1_7,mask52);
	D1_8 = _mm512_add_epi64(_mm512_slli_epi64(D1_8,1),carry);
	D1_8 = _mm512_add_epi64(D1_8,D2_3);
	carry = _mm512_srli_epi64(D1_8,52);
	D1_8 = _mm512_and_si512(D1_8,mask52);
	D1_9 = _mm512_add_epi64(_mm512_slli_epi64(D1_9,1),carry);
	D1_9 = _mm512_add_epi64(D1_9,D2_4);
	carry  = _mm512_srli_epi64(D1_9,51);
	D1_9 = _mm512_and_si512(D1_9,mask51);// radix 2^259

	// Final reconstruction


	// tmp = D0+D2, radix 2^259

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
	carry_tmp  = _mm512_srli_epi64(tmp4,51);
	tmp4 = _mm512_and_si512(tmp4,mask51);// radix 2**259

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
	tmp9 = _mm512_and_si512(tmp9,mask51);// radix 2**259




	// D1 = D1 -tmp, radix 2^259

	__m512i c5125 = _mm512_load_epi64(c512+5);
	__m512i c5126 = _mm512_load_epi64(c512+6);
	__m512i c5127 = _mm512_load_epi64(c512+7);
	__m512i c5128 = _mm512_load_epi64(c512+8);
	__m512i c5129 = _mm512_load_epi64(c512+9);
	D1_0 = _mm512_add_epi64(c5125,D1_0);
	D1_0 = _mm512_sub_epi64(D1_0,tmp0);
	__m512i borrow = _mm512_srli_epi64(D1_0,52)&un;
	D1_0 = _mm512_and_si512(D1_0,mask52);

	borrow = _mm512_add_epi64(tmp1,borrow);
	D1_1 = _mm512_add_epi64(c5126,D1_1);
	D1_1 = _mm512_sub_epi64(D1_1,borrow);
	borrow  = _mm512_srli_epi64(D1_1,52)&un;
	D1_1 = _mm512_and_si512(D1_1,mask52);

	borrow = _mm512_add_epi64(tmp2,borrow);
	D1_2 = _mm512_add_epi64(c5127,D1_2);
	D1_2 = _mm512_sub_epi64(D1_2,borrow);
	borrow  = _mm512_srli_epi64(D1_2,52)&un;
	D1_2 = _mm512_and_si512(D1_2,mask52);

	borrow = _mm512_add_epi64(tmp3,borrow);
	D1_3 = _mm512_add_epi64(c5128,D1_3);
	D1_3 = _mm512_sub_epi64(D1_3,borrow);
	borrow  = _mm512_srli_epi64(D1_3,52)&un;
	D1_3 = _mm512_and_si512(D1_3,mask52);

	borrow = _mm512_add_epi64(tmp4,borrow);
	D1_4 = _mm512_add_epi64(c5129,D1_4);
	D1_4 = _mm512_sub_epi64(D1_4,borrow);
	borrow = _mm512_srli_epi64(D1_4,51)&un;
	D1_4 = _mm512_and_si512(D1_4,mask51);// radix 2**259

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
	D1_9 = _mm512_and_si512(D1_9,mask51);// radix 2**259


	// Final borrows

	borrow = _mm512_add_epi64(carry_tmp,borrow);
	D2_5 = _mm512_add_epi64(D2_5,carry);
	D2_5 = _mm512_sub_epi64(D2_5,borrow);
	borrow  = _mm512_srli_epi64(D2_5,52)&un;
	D2_5 = _mm512_and_si512(D2_5,mask52);

	D2_6 = _mm512_sub_epi64(D2_6,borrow);
	borrow  = _mm512_srli_epi64(D2_6,52)&un;
	D2_6 = _mm512_and_si512(D2_6,mask52);

	D2_7 = _mm512_sub_epi64(D2_7,borrow);
	borrow  = _mm512_srli_epi64(D2_7,52)&un;
	D2_7 = _mm512_and_si512(D2_7,mask52);

	D2_8 = _mm512_sub_epi64(D2_8,borrow);
	borrow  = _mm512_srli_epi64(D2_8,52)&un;
	D2_8 = _mm512_and_si512(D2_8,mask52);

	D2_9 = _mm512_sub_epi64(D2_9,borrow);


	_mm512_store_epi64(out+0,D0_0);
	_mm512_store_epi64(out+1,D0_1);
	_mm512_store_epi64(out+2,D0_2);
	_mm512_store_epi64(out+3,D0_3);
	_mm512_store_epi64(out+4,D0_4);
	_mm512_store_epi64(out+5,D1_0);
	_mm512_store_epi64(out+6,D1_1);
	_mm512_store_epi64(out+7,D1_2);
	_mm512_store_epi64(out+8,D1_3);
	_mm512_store_epi64(out+9,D1_4);
	_mm512_store_epi64(out+10,D1_5);
	_mm512_store_epi64(out+11,D1_6);
	_mm512_store_epi64(out+12,D1_7);
	_mm512_store_epi64(out+13,D1_8);
	_mm512_store_epi64(out+14,D1_9);
	_mm512_store_epi64(out+15,D2_5);
	_mm512_store_epi64(out+16,D2_6);
	_mm512_store_epi64(out+17,D2_7);
	_mm512_store_epi64(out+18,D2_8);
	_mm512_store_epi64(out+19,D2_9);

}

/* Karatsuba squaring */

inline void force_inline square512_8_518K(__m512i out[20], __m512i a512[10])
{

	// D0 = Al^2

	__m512i D0_0, D0_1;
	__m512i D0_2, D0_3;
	__m512i D0_4, D0_5;
	__m512i D0_6, D0_7;
	__m512i D0_8, D0_9;
	__m512i a5120 = _mm512_load_epi64(a512);
	__m512i a5121 = _mm512_load_epi64(a512+1);
	__m512i a5122 = _mm512_load_epi64(a512+2);
	__m512i a5123 = _mm512_load_epi64(a512+3);
	__m512i a5124 = _mm512_load_epi64(a512+4);

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
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5121,a5124);
	D0_5 = _mm512_madd52lo_epu64(D0_5,a5122,a5123);
	D0_5 = _mm512_slli_epi64(D0_5,1);
	D0_5 = _mm512_madd52hi_epu64(D0_5,a5122,a5122);
	D0_5 = _mm512_add_epi64(D0_5,carry);
	carry  = _mm512_srli_epi64(D0_5,52);
	D0_5 = _mm512_and_si512(D0_5,mask52);

	D0_6 = _mm512_madd52hi_epu64(zero,a5121,a5124);
	D0_6 = _mm512_madd52hi_epu64(D0_6,a5122,a5123);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5122,a5124);
	D0_6 = _mm512_slli_epi64(D0_6,1);
	D0_6 = _mm512_madd52lo_epu64(D0_6,a5123,a5123);
	D0_6 = _mm512_add_epi64(D0_6,carry);
	carry  = _mm512_srli_epi64(D0_6,52);
	D0_6 = _mm512_and_si512(D0_6,mask52);

	D0_7 = _mm512_madd52hi_epu64(zero,a5122,a5124);
	D0_7 = _mm512_madd52lo_epu64(D0_7,a5123,a5124);
	D0_7 = _mm512_slli_epi64(D0_7,1);
	D0_7 = _mm512_madd52hi_epu64(D0_7,a5123,a5123);
	D0_7 = _mm512_add_epi64(D0_7,carry);
	carry  = _mm512_srli_epi64(D0_7,52);
	D0_7 = _mm512_and_si512(D0_7,mask52);

	D0_8 = _mm512_madd52hi_epu64(zero,a5123,a5124);
	D0_8 = _mm512_slli_epi64(D0_8,1);
	D0_8 = _mm512_madd52lo_epu64(D0_8,a5124,a5124);
	D0_8 = _mm512_add_epi64(D0_8,carry);
	carry  = _mm512_srli_epi64(D0_8,52);
	D0_8 = _mm512_and_si512(D0_8,mask52);

	D0_9 = _mm512_madd52hi_epu64(carry,a5124,a5124);


	// Conversion in base 2^259

	carry = D0_4>>51;
	D0_5 = (D0_5<<1)|carry;
	D0_4 &= mask51;
	carry = D0_5>>52;
	D0_6 = (D0_6<<1)|carry;
	D0_5 &= mask52;
	carry = D0_6>>52;
	D0_7 = (D0_7<<1)|carry;
	D0_6 &= mask52;
	carry = D0_7>>52;
	D0_8 = (D0_8<<1)|carry;
	D0_7 &= mask52;
	carry = D0_8>>52;
	D0_9 = (D0_9<<1)|carry;
	D0_8 &= mask52;

	// D2 = Ah^2

	__m512i D2_0, D2_1;
	__m512i D2_2, D2_3;
	__m512i D2_4, D2_5;
	__m512i D2_6, D2_7;
	__m512i D2_8, D2_9;
	__m512i a5125 = _mm512_load_epi64(a512+5);
	__m512i a5126 = _mm512_load_epi64(a512+6);
	__m512i a5127 = _mm512_load_epi64(a512+7);
	__m512i a5128 = _mm512_load_epi64(a512+8);
	__m512i a5129 = _mm512_load_epi64(a512+9);

	D2_0 = _mm512_madd52lo_epu64(zero,a5125,a5125);

	D2_1 = _mm512_madd52lo_epu64(zero,a5125,a5126);
	D2_1 = _mm512_slli_epi64(D2_1,1);
	D2_1 = _mm512_madd52hi_epu64(D2_1,a5125,a5125);
	carry  = _mm512_srli_epi64(D2_1,52);
	D2_1 = _mm512_and_si512(D2_1,mask52);

	D2_2 = _mm512_madd52hi_epu64(zero,a5125,a5126);
	D2_2 = _mm512_madd52lo_epu64(D2_2,a5125,a5127);
	D2_2 = _mm512_slli_epi64(D2_2,1);
	D2_2 = _mm512_madd52lo_epu64(D2_2,a5126,a5126);
	D2_2 = _mm512_add_epi64(D2_2,carry);
	carry  = _mm512_srli_epi64(D2_2,52);
	D2_2 = _mm512_and_si512(D2_2,mask52);

	D2_3 = _mm512_madd52hi_epu64(zero,a5125,a5127);
	D2_3 = _mm512_madd52lo_epu64(D2_3,a5125,a5128);
	D2_3 = _mm512_madd52lo_epu64(D2_3,a5126,a5127);
	D2_3 = _mm512_slli_epi64(D2_3,1);
	D2_3 = _mm512_madd52hi_epu64(D2_3,a5126,a5126);
	D2_3 = _mm512_add_epi64(D2_3,carry);
	carry  = _mm512_srli_epi64(D2_3,52);
	D2_3 = _mm512_and_si512(D2_3,mask52);

	D2_4 = _mm512_madd52hi_epu64(zero,a5125,a5128);
	D2_4 = _mm512_madd52hi_epu64(D2_4,a5126,a5127);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a5125,a5129);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a5126,a5128);
	D2_4 = _mm512_slli_epi64(D2_4,1);
	D2_4 = _mm512_madd52lo_epu64(D2_4,a5127,a5127);
	D2_4 = _mm512_add_epi64(D2_4,carry);
	carry  = _mm512_srli_epi64(D2_4,52);
	D2_4 = _mm512_and_si512(D2_4,mask52);

	D2_5 = _mm512_madd52hi_epu64(zero,a5125,a5129);
	D2_5 = _mm512_madd52hi_epu64(D2_5,a5126,a5128);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a5126,a5129);
	D2_5 = _mm512_madd52lo_epu64(D2_5,a5127,a5128);
	D2_5 = _mm512_slli_epi64(D2_5,1);
	D2_5 = _mm512_madd52hi_epu64(D2_5,a5127,a5127);
	D2_5 = _mm512_add_epi64(D2_5,carry);
	carry  = _mm512_srli_epi64(D2_5,52);
	D2_5 = _mm512_and_si512(D2_5,mask52);

	D2_6 = _mm512_madd52hi_epu64(zero,a5126,a5129);
	D2_6 = _mm512_madd52hi_epu64(D2_6,a5127,a5128);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a5127,a5129);
	D2_6 = _mm512_slli_epi64(D2_6,1);
	D2_6 = _mm512_madd52lo_epu64(D2_6,a5128,a5128);
	D2_6 = _mm512_add_epi64(D2_6,carry);
	carry  = _mm512_srli_epi64(D2_6,52);
	D2_6 = _mm512_and_si512(D2_6,mask52);

	D2_7 = _mm512_madd52hi_epu64(zero,a5127,a5129);
	D2_7 = _mm512_madd52lo_epu64(D2_7,a5128,a5129);
	D2_7 = _mm512_slli_epi64(D2_7,1);
	D2_7 = _mm512_madd52hi_epu64(D2_7,a5128,a5128);
	D2_7 = _mm512_add_epi64(D2_7,carry);
	carry  = _mm512_srli_epi64(D2_7,52);
	D2_7 = _mm512_and_si512(D2_7,mask52);

	D2_8 = _mm512_madd52hi_epu64(zero,a5128,a5129);
	D2_8 = _mm512_slli_epi64(D2_8,1);
	D2_8 = _mm512_madd52lo_epu64(D2_8,a5129,a5129);
	D2_8 = _mm512_add_epi64(D2_8,carry);
	carry  = _mm512_srli_epi64(D2_8,52);
	D2_8 = _mm512_and_si512(D2_8,mask52);

	D2_9 = _mm512_madd52hi_epu64(carry,a5129,a5129);


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

	// Conversion in base 2^259

	carry = D2_4>>51;
	D2_5 = (D2_5<<1)|carry;
	D2_4 &= mask51;
	carry = D2_5>>52;
	D2_6 = (D2_6<<1)|carry;
	D2_5 &= mask52;
	carry = D2_6>>52;
	D2_7 = (D2_7<<1)|carry;
	D2_6 &= mask52;
	carry = D2_7>>52;
	D2_8 = (D2_8<<1)|carry;
	D2_7 &= mask52;
	carry = D2_8>>52;
	D2_9 = (D2_9<<1)|carry;
	D2_8 &= mask52;

	// D1 = (Al+Ah)^2

	__m512i D1_0, D1_1;
	__m512i D1_2, D1_3;
	__m512i D1_4, D1_5;
	__m512i D1_6, D1_7;
	__m512i D1_8, D1_9;

	__m512i alpah0 = _mm512_add_epi64(a5120,a5125);
	carry = alpah0>>52;
	alpah0 &= mask52;
	__m512i alpah1 = _mm512_add_epi64(a5121,carry);
	alpah1 = _mm512_add_epi64(alpah1,a5126);
	carry = alpah1>>52;
	alpah1 &= mask52;
	__m512i alpah2 = _mm512_add_epi64(a5122,carry);
	alpah2 = _mm512_add_epi64(alpah2,a5127);
	carry = alpah2>>52;
	alpah2 &= mask52;
	__m512i alpah3 = _mm512_add_epi64(a5123,carry);
	alpah3 = _mm512_add_epi64(alpah3,a5128);
	carry = alpah3>>52;
	alpah3 &= mask52;
	__m512i alpah4 = _mm512_add_epi64(a5124,carry);
	alpah4 = _mm512_add_epi64(alpah4,a5129);
	carry = alpah4>>52;
	alpah4 &= mask52;

	D1_0 = _mm512_madd52lo_epu64(D0_5,alpah0,alpah0);

	D1_1 = _mm512_madd52lo_epu64(zero,alpah0,alpah1);
	D1_1 = _mm512_slli_epi64(D1_1,1);
	D1_1 = _mm512_madd52hi_epu64(D1_1,alpah0,alpah0);
	D1_1 = _mm512_add_epi64(D0_6,D1_1);
	carry  = _mm512_srli_epi64(D1_1,52);
	D1_1 = _mm512_and_si512(D1_1,mask52);

	D1_2 = _mm512_madd52hi_epu64(zero,alpah0,alpah1);
	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah0,alpah2);
	D1_2 = _mm512_slli_epi64(D1_2,1);
	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah1,alpah1);
	D1_2 = _mm512_add_epi64(D0_7,D1_2);
	D1_2 = _mm512_add_epi64(D1_2,carry);
	carry  = _mm512_srli_epi64(D1_2,52);
	D1_2 = _mm512_and_si512(D1_2,mask52);

	D1_3 = _mm512_madd52hi_epu64(zero,alpah0,alpah2);
	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah0,alpah3);
	D1_3 = _mm512_madd52lo_epu64(D1_3,alpah1,alpah2);
	D1_3 = _mm512_slli_epi64(D1_3,1);
	D1_3 = _mm512_madd52hi_epu64(D1_3,alpah1,alpah1);
	D1_3 = _mm512_add_epi64(D0_8,D1_3);
	D1_3 = _mm512_add_epi64(D1_3,carry);
	carry  = _mm512_srli_epi64(D1_3,52);
	D1_3 = _mm512_and_si512(D1_3,mask52);

	D1_4 = _mm512_madd52hi_epu64(zero,alpah0,alpah3);
	D1_4 = _mm512_madd52hi_epu64(D1_4,alpah1,alpah2);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah0,alpah4);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah1,alpah3);
	D1_4 = _mm512_slli_epi64(D1_4,1);
	D1_4 = _mm512_madd52lo_epu64(D1_4,alpah2,alpah2);
	D1_4 = _mm512_add_epi64(D0_9,D1_4);
	D1_4 = _mm512_add_epi64(D1_4,carry);
	carry  = _mm512_srli_epi64(D1_4,52);
	D1_4 = _mm512_and_si512(D1_4,mask52);

	D1_5 = _mm512_madd52hi_epu64(zero,alpah0,alpah4);
	D1_5 = _mm512_madd52hi_epu64(D1_5,alpah1,alpah3);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah1,alpah4);
	D1_5 = _mm512_madd52lo_epu64(D1_5,alpah2,alpah3);
	D1_5 = _mm512_slli_epi64(D1_5,1);
	D1_5 = _mm512_madd52hi_epu64(D1_5,alpah2,alpah2);
	D1_5 = _mm512_add_epi64(D1_5,carry);
	carry  = _mm512_srli_epi64(D1_5,52);
	D1_5 = _mm512_and_si512(D1_5,mask52);

	D1_6 = _mm512_madd52hi_epu64(zero,alpah1,alpah4);
	D1_6 = _mm512_madd52hi_epu64(D1_6,alpah2,alpah3);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah2,alpah4);
	D1_6 = _mm512_slli_epi64(D1_6,1);
	D1_6 = _mm512_madd52lo_epu64(D1_6,alpah3,alpah3);
	D1_6 = _mm512_add_epi64(D1_6,carry);
	carry  = _mm512_srli_epi64(D1_6,52);
	D1_6 = _mm512_and_si512(D1_6,mask52);

	D1_7 = _mm512_madd52hi_epu64(zero,alpah2,alpah4);
	D1_7 = _mm512_madd52lo_epu64(D1_7,alpah3,alpah4);
	D1_7 = _mm512_slli_epi64(D1_7,1);
	D1_7 = _mm512_madd52hi_epu64(D1_7,alpah3,alpah3);
	D1_7 = _mm512_add_epi64(D1_7,carry);
	carry  = _mm512_srli_epi64(D1_7,52);
	D1_7 = _mm512_and_si512(D1_7,mask52);

	D1_8 = _mm512_madd52hi_epu64(zero,alpah3,alpah4);
	D1_8 = _mm512_slli_epi64(D1_8,1);
	D1_8 = _mm512_madd52lo_epu64(D1_8,alpah4,alpah4);
	D1_8 = _mm512_add_epi64(D1_8,carry);
	carry  = _mm512_srli_epi64(D1_8,52);
	D1_8 = _mm512_and_si512(D1_8,mask52);

	D1_9 = _mm512_madd52hi_epu64(carry,alpah4,alpah4);


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

	// Conversion in base 2^259

	carry  = _mm512_srli_epi64(D1_4,51);
	D1_4 = _mm512_and_si512(D1_4,mask51);// radix 2^259
	D1_5 = _mm512_add_epi64(_mm512_slli_epi64(D1_5,1),carry);
	D1_5 = _mm512_add_epi64(D1_5,D2_0);
	carry = _mm512_srli_epi64(D1_5,52);
	D1_5 = _mm512_and_si512(D1_5,mask52);
	D1_6 = _mm512_add_epi64(_mm512_slli_epi64(D1_6,1),carry);
	D1_6 = _mm512_add_epi64(D1_6,D2_1);
	carry = _mm512_srli_epi64(D1_6,52);
	D1_6 = _mm512_and_si512(D1_6,mask52);
	D1_7 = _mm512_add_epi64(_mm512_slli_epi64(D1_7,1),carry);
	D1_7 = _mm512_add_epi64(D1_7,D2_2);
	carry = _mm512_srli_epi64(D1_7,52);
	D1_7 = _mm512_and_si512(D1_7,mask52);
	D1_8 = _mm512_add_epi64(_mm512_slli_epi64(D1_8,1),carry);
	D1_8 = _mm512_add_epi64(D1_8,D2_3);
	carry = _mm512_srli_epi64(D1_8,52);
	D1_8 = _mm512_and_si512(D1_8,mask52);
	D1_9 = _mm512_add_epi64(_mm512_slli_epi64(D1_9,1),carry);
	D1_9 = _mm512_add_epi64(D1_9,D2_4);
	carry  = _mm512_srli_epi64(D1_9,51);
	D1_9 = _mm512_and_si512(D1_9,mask51);// radix 2^259

	// Final reconstruction


	// tmp = D0+D2, radix 2^259

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
	carry_tmp  = _mm512_srli_epi64(tmp4,51);
	tmp4 = _mm512_and_si512(tmp4,mask51);// radix 2**259

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
	tmp9 = _mm512_and_si512(tmp9,mask51);// radix 2**259




	// D1 = D1 -tmp, radix 2^259

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
	borrow = _mm512_srli_epi64(D1_4,51)&un;
	D1_4 = _mm512_and_si512(D1_4,mask51);// radix 2**259

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
	D1_9 = _mm512_and_si512(D1_9,mask51);// radix 2**259


	// Final borrows

	borrow = _mm512_add_epi64(carry_tmp,borrow);
	D2_5 = _mm512_add_epi64(D2_5,carry);
	D2_5 = _mm512_sub_epi64(D2_5,borrow);
	borrow  = _mm512_srli_epi64(D2_5,52)&un;
	D2_5 = _mm512_and_si512(D2_5,mask52);

	D2_6 = _mm512_sub_epi64(D2_6,borrow);
	borrow  = _mm512_srli_epi64(D2_6,52)&un;
	D2_6 = _mm512_and_si512(D2_6,mask52);

	D2_7 = _mm512_sub_epi64(D2_7,borrow);
	borrow  = _mm512_srli_epi64(D2_7,52)&un;
	D2_7 = _mm512_and_si512(D2_7,mask52);

	D2_8 = _mm512_sub_epi64(D2_8,borrow);
	borrow  = _mm512_srli_epi64(D2_8,52)&un;
	D2_8 = _mm512_and_si512(D2_8,mask52);

	D2_9 = _mm512_sub_epi64(D2_9,borrow);


	_mm512_store_epi64(out+0,D0_0);
	_mm512_store_epi64(out+1,D0_1);
	_mm512_store_epi64(out+2,D0_2);
	_mm512_store_epi64(out+3,D0_3);
	_mm512_store_epi64(out+4,D0_4);
	_mm512_store_epi64(out+5,D1_0);
	_mm512_store_epi64(out+6,D1_1);
	_mm512_store_epi64(out+7,D1_2);
	_mm512_store_epi64(out+8,D1_3);
	_mm512_store_epi64(out+9,D1_4);
	_mm512_store_epi64(out+10,D1_5);
	_mm512_store_epi64(out+11,D1_6);
	_mm512_store_epi64(out+12,D1_7);
	_mm512_store_epi64(out+13,D1_8);
	_mm512_store_epi64(out+14,D1_9);
	_mm512_store_epi64(out+15,D2_5);
	_mm512_store_epi64(out+16,D2_6);
	_mm512_store_epi64(out+17,D2_7);
	_mm512_store_epi64(out+18,D2_8);
	_mm512_store_epi64(out+19,D2_9);
}

