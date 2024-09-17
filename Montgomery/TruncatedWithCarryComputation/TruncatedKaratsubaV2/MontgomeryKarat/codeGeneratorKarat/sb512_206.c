/* Karatsuba multiplication mod M*/

inline void force_inline mul512_8_206K_modM(__m512i out[8], __m512i a512[4], __m512i b512[4])
{

	// D0 = Al*Bl

	__m512i D0_0, D0_1;
	__m512i D0_2, D0_3;
	__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512);
	__m512i a5121 = _mm512_load_epi64(a512+1), b5121 = _mm512_load_epi64(b512+1);
	D0_0 = _mm512_madd52lo_epu64(zero,a5120,b5120);
	D0_1 = _mm512_madd52hi_epu64(zero,a5120,b5120);
	D0_1 = _mm512_madd52lo_epu64(D0_1,a5120,b5121);
	D0_2 = _mm512_madd52hi_epu64(zero,a5120,b5121);

	D0_1 = _mm512_madd52lo_epu64(D0_1,a5121,b5120);
	D0_2 = _mm512_madd52hi_epu64(D0_2,a5121,b5120);
	D0_2 = _mm512_madd52lo_epu64(D0_2,a5121,b5121);
	D0_3 = _mm512_madd52hi_epu64(zero,a5121,b5121);


	// Carry management

	__m512i carry  = _mm512_srli_epi64(D0_1,52);
	D0_2 = _mm512_add_epi64(D0_2,carry);
	D0_1 = _mm512_and_si512(D0_1,mask52);
	carry  = _mm512_srli_epi64(D0_2,52);
	D0_3 = _mm512_add_epi64(D0_3,carry);
	D0_2 = _mm512_and_si512(D0_2,mask52);

	// Conversion in base 2^103

	carry = D0_1>>51;
	D0_2 = (D0_2<<1)|carry;
	D0_1 &= mask51;
	carry = D0_2>>52;
	D0_3 = (D0_3<<1)|carry;
	D0_2 &= mask52;

	// D2 = Ah*Bh

	__m512i D2_0;
	__m512i D2_1;
	__m512i a5122 = _mm512_load_epi64(a512+2), b5122 = _mm512_load_epi64(b512+2);
	__m512i a5123 = _mm512_load_epi64(a512+3), b5123 = _mm512_load_epi64(b512+3);
	D2_0 = _mm512_madd52lo_epu64(zero,a5122,b5122);
	D2_1 = _mm512_madd52hi_epu64(zero,a5122,b5122);
	D2_1 = _mm512_madd52lo_epu64(D2_1,a5122,b5123);

	D2_1 = _mm512_madd52lo_epu64(D2_1,a5123,b5122);


	// Carry management

	carry  = _mm512_srli_epi64(D2_1,52);
	D2_2 = _mm512_add_epi64(D2_2,carry);
	D2_1 = _mm512_and_si512(D2_1,mask52);
	carry  = _mm512_srli_epi64(D2_0,52);
	D2_1 = _mm512_add_epi64(D2_1,carry);
	D2_0 = _mm512_and_si512(D2_0,mask52);

	// D1 = (Al+Ah)*(Bl+Bh)

	__m512i D1_0;
	__m512i D1_1;

	__m512i alpah0 = _mm512_add_epi64(a5120,a5122);
	carry = alpah0>>52;
	alpah0 &= mask52;
	__m512i alpah1 = _mm512_add_epi64(a5121,carry);
	alpah1 = _mm512_add_epi64(alpah1,a5123);
	carry = alpah1>>52;
	alpah1 &= mask52;
	__m512i blpbh0 = _mm512_add_epi64(b5120,b5122);
	carry = blpbh0>>52;
	blpbh0 &= mask52;
	__m512i blpbh1 = _mm512_add_epi64(b5121,carry);
	blpbh1 = _mm512_add_epi64(blpbh1,b5123);
	carry = blpbh1>>52;
	blpbh1 &= mask52;
	D1_0 = _mm512_madd52lo_epu64(D0_2,alpah0,blpbh0);
	D1_1 = _mm512_madd52hi_epu64(D0_3,alpah0,blpbh0);
	D1_1 = _mm512_madd52lo_epu64(D1_1,alpah0,blpbh1);

	D1_1 = _mm512_madd52lo_epu64(D1_1,alpah1,blpbh0);


	// Carry management

	carry  = _mm512_srli_epi64(D1_0,52);
	D1_0 = _mm512_and_si512(D1_0,mask52);
	D1_1 = _mm512_add_epi64(D1_1,carry);
	carry  = _mm512_srli_epi64(D1_0,52);
	D1_1 = _mm512_add_epi64(D1_1,carry);
	D1_0 = _mm512_and_si512(D1_0,mask52);

	// Final reconstruction


	// tmp = D0+D2, radix 2^103

	__m512i tmp0 = _mm512_add_epi64(D0_0,D2_0);
	__m512i carry_tmp  = _mm512_srli_epi64(tmp0,52);
	tmp0 = _mm512_and_si512(tmp0,mask52);

	__m512i tmp1 = _mm512_add_epi64(D0_1,carry_tmp);
	tmp1 = _mm512_add_epi64(tmp1,D2_1);
	carry_tmp  = _mm512_srli_epi64(tmp1,51);
	tmp1 = _mm512_and_si512(tmp1,mask51);// radix 2**103


	// D1 = D1 -tmp, radix 2^103

	D1_0 = _mm512_sub_epi64(D1_0,tmp0);
	__m512i borrow = _mm512_srli_epi64(D1_0,52)&un;
	D1_0 = _mm512_and_si512(D1_0,mask52);
	borrow = _mm512_add_epi64(tmp1,borrow);
	D1_1 = _mm512_sub_epi64(D1_1,borrow);
	borrow = _mm512_srli_epi64(D1_1,51)&un;
	D1_1 = _mm512_and_si512(D1_1,mask51);// radix 2**103



	_mm512_store_epi64(out+0,D0_0);
	_mm512_store_epi64(out+1,D0_1);
	_mm512_store_epi64(out+2,D1_0);
	_mm512_store_epi64(out+3,D1_1);

}

/* Karatsuba multiplication */

inline void force_inline mul512_8_206K(__m512i out[8], __m512i a512[4], __m512i b512[4])
{

	// D0 = Al*Bl

	__m512i D0_0, D0_1;
	__m512i D0_2, D0_3;
	__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512);
	__m512i a5121 = _mm512_load_epi64(a512+1), b5121 = _mm512_load_epi64(b512+1);
	D0_0 = _mm512_madd52lo_epu64(zero,a5120,b5120);
	D0_1 = _mm512_madd52hi_epu64(zero,a5120,b5120);
	D0_1 = _mm512_madd52lo_epu64(D0_1,a5120,b5121);
	D0_2 = _mm512_madd52hi_epu64(zero,a5120,b5121);

	D0_1 = _mm512_madd52lo_epu64(D0_1,a5121,b5120);
	D0_2 = _mm512_madd52hi_epu64(D0_2,a5121,b5120);
	D0_2 = _mm512_madd52lo_epu64(D0_2,a5121,b5121);
	D0_3 = _mm512_madd52hi_epu64(zero,a5121,b5121);


	// Carry management

	__m512i carry  = _mm512_srli_epi64(D0_1,52);
	D0_2 = _mm512_add_epi64(D0_2,carry);
	D0_1 = _mm512_and_si512(D0_1,mask52);
	carry  = _mm512_srli_epi64(D0_2,52);
	D0_3 = _mm512_add_epi64(D0_3,carry);
	D0_2 = _mm512_and_si512(D0_2,mask52);

	// Conversion in base 2^103

	carry = D0_1>>51;
	D0_2 = (D0_2<<1)|carry;
	D0_1 &= mask51;
	carry = D0_2>>52;
	D0_3 = (D0_3<<1)|carry;
	D0_2 &= mask52;

	// D2 = Ah*Bh

	__m512i D2_0, D2_1;
	__m512i D2_2, D2_3;
	__m512i a5122 = _mm512_load_epi64(a512+2), b5122 = _mm512_load_epi64(b512+2);
	__m512i a5123 = _mm512_load_epi64(a512+3), b5123 = _mm512_load_epi64(b512+3);
	D2_0 = _mm512_madd52lo_epu64(zero,a5122,b5122);
	D2_1 = _mm512_madd52hi_epu64(zero,a5122,b5122);
	D2_1 = _mm512_madd52lo_epu64(D2_1,a5122,b5123);
	D2_2 = _mm512_madd52hi_epu64(zero,a5122,b5123);

	D2_1 = _mm512_madd52lo_epu64(D2_1,a5123,b5122);
	D2_2 = _mm512_madd52hi_epu64(D2_2,a5123,b5122);
	D2_2 = _mm512_madd52lo_epu64(D2_2,a5123,b5123);
	D2_3 = _mm512_madd52hi_epu64(zero,a5123,b5123);


	// Carry management

	carry  = _mm512_srli_epi64(D2_1,52);
	D2_2 = _mm512_add_epi64(D2_2,carry);
	D2_1 = _mm512_and_si512(D2_1,mask52);
	carry  = _mm512_srli_epi64(D2_2,52);
	D2_3 = _mm512_add_epi64(D2_3,carry);
	D2_2 = _mm512_and_si512(D2_2,mask52);

	// Conversion in base 2^103

	carry = D2_1>>51;
	D2_2 = (D2_2<<1)|carry;
	D2_1 &= mask51;
	carry = D2_2>>52;
	D2_3 = (D2_3<<1)|carry;
	D2_2 &= mask52;

	// D1 = (Al+Ah)*(Bl+Bh)

	__m512i D1_0, D1_1;
	__m512i D1_2, D1_3;

	__m512i alpah0 = _mm512_add_epi64(a5120,a5122);
	carry = alpah0>>52;
	alpah0 &= mask52;
	__m512i alpah1 = _mm512_add_epi64(a5121,carry);
	alpah1 = _mm512_add_epi64(alpah1,a5123);
	carry = alpah1>>52;
	alpah1 &= mask52;
	__m512i blpbh0 = _mm512_add_epi64(b5120,b5122);
	carry = blpbh0>>52;
	blpbh0 &= mask52;
	__m512i blpbh1 = _mm512_add_epi64(b5121,carry);
	blpbh1 = _mm512_add_epi64(blpbh1,b5123);
	carry = blpbh1>>52;
	blpbh1 &= mask52;
	D1_0 = _mm512_madd52lo_epu64(D0_2,alpah0,blpbh0);
	D1_1 = _mm512_madd52hi_epu64(D0_3,alpah0,blpbh0);
	D1_1 = _mm512_madd52lo_epu64(D1_1,alpah0,blpbh1);
	D1_2 = _mm512_madd52hi_epu64(zero,alpah0,blpbh1);

	D1_1 = _mm512_madd52lo_epu64(D1_1,alpah1,blpbh0);
	D1_2 = _mm512_madd52hi_epu64(D1_2,alpah1,blpbh0);
	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah1,blpbh1);
	D1_3 = _mm512_madd52hi_epu64(zero,alpah1,blpbh1);


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

	// Conversion in base 2^103

	carry  = _mm512_srli_epi64(D1_1,51);
	D1_1 = _mm512_and_si512(D1_1,mask51);// radix 2^103
	D1_2 = _mm512_add_epi64(_mm512_slli_epi64(D1_2,1),carry);
	D1_2 = _mm512_add_epi64(D1_2,D2_0);
	carry = _mm512_srli_epi64(D1_2,52);
	D1_2 = _mm512_and_si512(D1_2,mask52);
	D1_3 = _mm512_add_epi64(_mm512_slli_epi64(D1_3,1),carry);
	D1_3 = _mm512_add_epi64(D1_3,D2_1);
	carry  = _mm512_srli_epi64(D1_3,51);
	D1_3 = _mm512_and_si512(D1_3,mask51);// radix 2^103

	// Final reconstruction


	// tmp = D0+D2, radix 2^103

	__m512i tmp0 = _mm512_add_epi64(D0_0,D2_0);
	__m512i carry_tmp  = _mm512_srli_epi64(tmp0,52);
	tmp0 = _mm512_and_si512(tmp0,mask52);

	__m512i tmp1 = _mm512_add_epi64(D0_1,carry_tmp);
	tmp1 = _mm512_add_epi64(tmp1,D2_1);
	carry_tmp  = _mm512_srli_epi64(tmp1,51);
	tmp1 = _mm512_and_si512(tmp1,mask51);// radix 2**103

	__m512i tmp2 = _mm512_add_epi64(D0_2,carry_tmp);
	tmp2 = _mm512_add_epi64(tmp2,D2_2);
	carry_tmp  = _mm512_srli_epi64(tmp2,52);
	tmp2 = _mm512_and_si512(tmp2,mask52);

	__m512i tmp3 = _mm512_add_epi64(D0_3,carry_tmp);
	tmp3 = _mm512_add_epi64(tmp3,D2_3);
	carry_tmp  = _mm512_srli_epi64(tmp3,51);
	tmp3 = _mm512_and_si512(tmp3,mask51);// radix 2**103




	// D1 = D1 -tmp, radix 2^103

	D1_0 = _mm512_sub_epi64(D1_0,tmp0);
	__m512i borrow = _mm512_srli_epi64(D1_0,52)&un;
	D1_0 = _mm512_and_si512(D1_0,mask52);
	borrow = _mm512_add_epi64(tmp1,borrow);
	D1_1 = _mm512_sub_epi64(D1_1,borrow);
	borrow = _mm512_srli_epi64(D1_1,51)&un;
	D1_1 = _mm512_and_si512(D1_1,mask51);// radix 2**103

	borrow = _mm512_add_epi64(tmp2,borrow);
	D1_2 = _mm512_sub_epi64(D1_2,borrow);
	borrow  = _mm512_srli_epi64(D1_2,52)&un;
	D1_2 = _mm512_and_si512(D1_2,mask52);

	borrow = _mm512_add_epi64(tmp3,borrow);
	D1_3 = _mm512_sub_epi64(D1_3,borrow);
	borrow = _mm512_srli_epi64(D1_3,51)&un;
	D1_3 = _mm512_and_si512(D1_3,mask51);// radix 2**103


	// Final borrows

	borrow = _mm512_add_epi64(carry_tmp,borrow);
	D2_2 = _mm512_add_epi64(D2_2,carry);
	D2_2 = _mm512_sub_epi64(D2_2,borrow);
	borrow  = _mm512_srli_epi64(D2_2,52)&un;
	D2_2 = _mm512_and_si512(D2_2,mask52);

	D2_3 = _mm512_sub_epi64(D2_3,borrow);


	_mm512_store_epi64(out+0,D0_0);
	_mm512_store_epi64(out+1,D0_1);
	_mm512_store_epi64(out+2,D1_0);
	_mm512_store_epi64(out+3,D1_1);
	_mm512_store_epi64(out+4,D1_2);
	_mm512_store_epi64(out+5,D1_3);
	_mm512_store_epi64(out+6,D2_2);
	_mm512_store_epi64(out+7,D2_3);

}

/* Karatsuba fma, computes C+AB */

inline void force_inline fma512_8_206K(__m512i out[8], __m512i a512[4], __m512i b512[4], __m512i c512[4])
{

	// D0 = Al*Bl

	__m512i D0_0, D0_1;
	__m512i D0_2, D0_3;
	__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512), c5120 = _mm512_load_epi64(c512);
	__m512i a5121 = _mm512_load_epi64(a512+1), b5121 = _mm512_load_epi64(b512+1), c5121 = _mm512_load_epi64(c512+1);
	D0_0 = _mm512_madd52lo_epu64(c5120,a5120,b5120);
	D0_1 = _mm512_madd52hi_epu64(c5121,a5120,b5120);
	D0_1 = _mm512_madd52lo_epu64(D0_1,a5120,b5121);
	D0_2 = _mm512_madd52hi_epu64(c5121,a5120,b5121);

	D0_1 = _mm512_madd52lo_epu64(D0_1,a5121,b5120);
	D0_2 = _mm512_madd52hi_epu64(D0_2,a5121,b5120);
	D0_2 = _mm512_madd52lo_epu64(D0_2,a5121,b5121);
	D0_3 = _mm512_madd52hi_epu64(c5121,a5121,b5121);


	// Carry management

	__m512i carry  = _mm512_srli_epi64(D0_1,52);
	D0_2 = _mm512_add_epi64(D0_2,carry);
	D0_1 = _mm512_and_si512(D0_1,mask52);
	carry  = _mm512_srli_epi64(D0_2,52);
	D0_3 = _mm512_add_epi64(D0_3,carry);
	D0_2 = _mm512_and_si512(D0_2,mask52);

	// Conversion in base 2^103

	carry = D0_1>>51;
	D0_2 = (D0_2<<1)|carry;
	D0_1 &= mask51;
	carry = D0_2>>52;
	D0_3 = (D0_3<<1)|carry;
	D0_2 &= mask52;

	// D2 = Ah*Bh

	__m512i D2_0, D2_1;
	__m512i D2_2, D2_3;
	__m512i a5122 = _mm512_load_epi64(a512+2), b5122 = _mm512_load_epi64(b512+2);
	__m512i a5123 = _mm512_load_epi64(a512+3), b5123 = _mm512_load_epi64(b512+3);
	D2_0 = _mm512_madd52lo_epu64(zero,a5122,b5122);
	D2_1 = _mm512_madd52hi_epu64(zero,a5122,b5122);
	D2_1 = _mm512_madd52lo_epu64(D2_1,a5122,b5123);
	D2_2 = _mm512_madd52hi_epu64(zero,a5122,b5123);

	D2_1 = _mm512_madd52lo_epu64(D2_1,a5123,b5122);
	D2_2 = _mm512_madd52hi_epu64(D2_2,a5123,b5122);
	D2_2 = _mm512_madd52lo_epu64(D2_2,a5123,b5123);
	D2_3 = _mm512_madd52hi_epu64(zero,a5123,b5123);


	// Carry management

	carry  = _mm512_srli_epi64(D2_1,52);
	D2_2 = _mm512_add_epi64(D2_2,carry);
	D2_1 = _mm512_and_si512(D2_1,mask52);
	carry  = _mm512_srli_epi64(D2_2,52);
	D2_3 = _mm512_add_epi64(D2_3,carry);
	D2_2 = _mm512_and_si512(D2_2,mask52);

	// Conversion in base 2^103

	carry = D2_1>>51;
	D2_2 = (D2_2<<1)|carry;
	D2_1 &= mask51;
	carry = D2_2>>52;
	D2_3 = (D2_3<<1)|carry;
	D2_2 &= mask52;

	// D1 = (Al+Ah)*(Bl+Bh)

	__m512i D1_0, D1_1;
	__m512i D1_2, D1_3;

	__m512i alpah0 = _mm512_add_epi64(a5120,a5122);
	carry = alpah0>>52;
	alpah0 &= mask52;
	__m512i alpah1 = _mm512_add_epi64(a5121,carry);
	alpah1 = _mm512_add_epi64(alpah1,a5123);
	carry = alpah1>>52;
	alpah1 &= mask52;
	__m512i blpbh0 = _mm512_add_epi64(b5120,b5122);
	carry = blpbh0>>52;
	blpbh0 &= mask52;
	__m512i blpbh1 = _mm512_add_epi64(b5121,carry);
	blpbh1 = _mm512_add_epi64(blpbh1,b5123);
	carry = blpbh1>>52;
	blpbh1 &= mask52;
	D1_0 = _mm512_madd52lo_epu64(D0_2,alpah0,blpbh0);
	D1_1 = _mm512_madd52hi_epu64(D0_3,alpah0,blpbh0);
	D1_1 = _mm512_madd52lo_epu64(D1_1,alpah0,blpbh1);
	D1_2 = _mm512_madd52hi_epu64(zero,alpah0,blpbh1);

	D1_1 = _mm512_madd52lo_epu64(D1_1,alpah1,blpbh0);
	D1_2 = _mm512_madd52hi_epu64(D1_2,alpah1,blpbh0);
	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah1,blpbh1);
	D1_3 = _mm512_madd52hi_epu64(zero,alpah1,blpbh1);


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

	// Conversion in base 2^103

	carry  = _mm512_srli_epi64(D1_1,51);
	D1_1 = _mm512_and_si512(D1_1,mask51);// radix 2^103
	D1_2 = _mm512_add_epi64(_mm512_slli_epi64(D1_2,1),carry);
	D1_2 = _mm512_add_epi64(D1_2,D2_0);
	carry = _mm512_srli_epi64(D1_2,52);
	D1_2 = _mm512_and_si512(D1_2,mask52);
	D1_3 = _mm512_add_epi64(_mm512_slli_epi64(D1_3,1),carry);
	D1_3 = _mm512_add_epi64(D1_3,D2_1);
	carry  = _mm512_srli_epi64(D1_3,51);
	D1_3 = _mm512_and_si512(D1_3,mask51);// radix 2^103

	// Final reconstruction


	// tmp = D0+D2, radix 2^103

	__m512i tmp0 = _mm512_add_epi64(D0_0,D2_0);
	__m512i carry_tmp  = _mm512_srli_epi64(tmp0,52);
	tmp0 = _mm512_and_si512(tmp0,mask52);

	__m512i tmp1 = _mm512_add_epi64(D0_1,carry_tmp);
	tmp1 = _mm512_add_epi64(tmp1,D2_1);
	carry_tmp  = _mm512_srli_epi64(tmp1,51);
	tmp1 = _mm512_and_si512(tmp1,mask51);// radix 2**103

	__m512i tmp2 = _mm512_add_epi64(D0_2,carry_tmp);
	tmp2 = _mm512_add_epi64(tmp2,D2_2);
	carry_tmp  = _mm512_srli_epi64(tmp2,52);
	tmp2 = _mm512_and_si512(tmp2,mask52);

	__m512i tmp3 = _mm512_add_epi64(D0_3,carry_tmp);
	tmp3 = _mm512_add_epi64(tmp3,D2_3);
	carry_tmp  = _mm512_srli_epi64(tmp3,51);
	tmp3 = _mm512_and_si512(tmp3,mask51);// radix 2**103




	// D1 = D1 -tmp, radix 2^103

	__m512i c5122 = _mm512_load_epi64(c512+2);
	__m512i c5123 = _mm512_load_epi64(c512+3);
	D1_0 = _mm512_add_epi64(c5122,D1_0);
	D1_0 = _mm512_sub_epi64(D1_0,tmp0);
	__m512i borrow = _mm512_srli_epi64(D1_0,52)&un;
	D1_0 = _mm512_and_si512(D1_0,mask52);

	borrow = _mm512_add_epi64(tmp1,borrow);
	D1_1 = _mm512_add_epi64(c5123,D1_1);
	D1_1 = _mm512_sub_epi64(D1_1,borrow);
	borrow = _mm512_srli_epi64(D1_1,51)&un;
	D1_1 = _mm512_and_si512(D1_1,mask51);// radix 2**103

	borrow = _mm512_add_epi64(tmp2,borrow);
	D1_2 = _mm512_sub_epi64(D1_2,borrow);
	borrow  = _mm512_srli_epi64(D1_2,52)&un;
	D1_2 = _mm512_and_si512(D1_2,mask52);

	borrow = _mm512_add_epi64(tmp3,borrow);
	D1_3 = _mm512_sub_epi64(D1_3,borrow);
	borrow = _mm512_srli_epi64(D1_3,51)&un;
	D1_3 = _mm512_and_si512(D1_3,mask51);// radix 2**103


	// Final borrows

	borrow = _mm512_add_epi64(carry_tmp,borrow);
	D2_2 = _mm512_add_epi64(D2_2,carry);
	D2_2 = _mm512_sub_epi64(D2_2,borrow);
	borrow  = _mm512_srli_epi64(D2_2,52)&un;
	D2_2 = _mm512_and_si512(D2_2,mask52);

	D2_3 = _mm512_sub_epi64(D2_3,borrow);


	_mm512_store_epi64(out+0,D0_0);
	_mm512_store_epi64(out+1,D0_1);
	_mm512_store_epi64(out+2,D1_0);
	_mm512_store_epi64(out+3,D1_1);
	_mm512_store_epi64(out+4,D1_2);
	_mm512_store_epi64(out+5,D1_3);
	_mm512_store_epi64(out+6,D2_2);
	_mm512_store_epi64(out+7,D2_3);

}

/* Karatsuba squaring */

inline void force_inline square512_8_206K(__m512i out[8], __m512i a512[4])
{

	// D0 = Al^2

	__m512i D0_0, D0_1;
	__m512i D0_2, D0_3;
	__m512i a5120 = _mm512_load_epi64(a512);
	__m512i a5121 = _mm512_load_epi64(a512+1);

	D0_0 = _mm512_madd52lo_epu64(zero,a5120,a5120);

	D0_1 = _mm512_madd52lo_epu64(zero,a5120,a5121);
	D0_1 = _mm512_slli_epi64(D0_1,1);
	D0_1 = _mm512_madd52hi_epu64(D0_1,a5120,a5120);
	__m512i carry  = _mm512_srli_epi64(D0_1,52);
	D0_1 = _mm512_and_si512(D0_1,mask52);

	D0_2 = _mm512_madd52hi_epu64(zero,a5120,a5121);
	D0_2 = _mm512_slli_epi64(D0_2,1);
	D0_2 = _mm512_madd52lo_epu64(D0_2,a5121,a5121);
	D0_2 = _mm512_add_epi64(D0_2,carry);
	carry  = _mm512_srli_epi64(D0_2,52);
	D0_2 = _mm512_and_si512(D0_2,mask52);

	D0_3 = _mm512_madd52hi_epu64(carry,a5121,a5121);


	// Conversion in base 2^103

	carry = D0_1>>51;
	D0_2 = (D0_2<<1)|carry;
	D0_1 &= mask51;
	carry = D0_2>>52;
	D0_3 = (D0_3<<1)|carry;
	D0_2 &= mask52;

	// D2 = Ah^2

	__m512i D2_0, D2_1;
	__m512i D2_2, D2_3;
	__m512i a5122 = _mm512_load_epi64(a512+2);
	__m512i a5123 = _mm512_load_epi64(a512+3);

	D2_0 = _mm512_madd52lo_epu64(zero,a5122,a5122);

	D2_1 = _mm512_madd52lo_epu64(zero,a5122,a5123);
	D2_1 = _mm512_slli_epi64(D2_1,1);
	D2_1 = _mm512_madd52hi_epu64(D2_1,a5122,a5122);
	carry  = _mm512_srli_epi64(D2_1,52);
	D2_1 = _mm512_and_si512(D2_1,mask52);

	D2_2 = _mm512_madd52hi_epu64(zero,a5122,a5123);
	D2_2 = _mm512_slli_epi64(D2_2,1);
	D2_2 = _mm512_madd52lo_epu64(D2_2,a5123,a5123);
	D2_2 = _mm512_add_epi64(D2_2,carry);
	carry  = _mm512_srli_epi64(D2_2,52);
	D2_2 = _mm512_and_si512(D2_2,mask52);

	D2_3 = _mm512_madd52hi_epu64(carry,a5123,a5123);


	// Carry management

	carry  = _mm512_srli_epi64(D2_1,52);
	D2_2 = _mm512_add_epi64(D2_2,carry);
	D2_1 = _mm512_and_si512(D2_1,mask52);
	carry  = _mm512_srli_epi64(D2_2,52);
	D2_3 = _mm512_add_epi64(D2_3,carry);
	D2_2 = _mm512_and_si512(D2_2,mask52);

	// Conversion in base 2^103

	carry = D2_1>>51;
	D2_2 = (D2_2<<1)|carry;
	D2_1 &= mask51;
	carry = D2_2>>52;
	D2_3 = (D2_3<<1)|carry;
	D2_2 &= mask52;

	// D1 = (Al+Ah)^2

	__m512i D1_0, D1_1;
	__m512i D1_2, D1_3;

	__m512i alpah0 = _mm512_add_epi64(a5120,a5122);
	carry = alpah0>>52;
	alpah0 &= mask52;
	__m512i alpah1 = _mm512_add_epi64(a5121,carry);
	alpah1 = _mm512_add_epi64(alpah1,a5123);
	carry = alpah1>>52;
	alpah1 &= mask52;

	D1_0 = _mm512_madd52lo_epu64(D0_2,alpah0,alpah0);

	D1_1 = _mm512_madd52lo_epu64(zero,alpah0,alpah1);
	D1_1 = _mm512_slli_epi64(D1_1,1);
	D1_1 = _mm512_madd52hi_epu64(D1_1,alpah0,alpah0);
	D1_1 = _mm512_add_epi64(D0_3,D1_1);
	carry  = _mm512_srli_epi64(D1_1,52);
	D1_1 = _mm512_and_si512(D1_1,mask52);

	D1_2 = _mm512_madd52hi_epu64(zero,alpah0,alpah1);
	D1_2 = _mm512_slli_epi64(D1_2,1);
	D1_2 = _mm512_madd52lo_epu64(D1_2,alpah1,alpah1);
	D1_2 = _mm512_add_epi64(D1_2,carry);
	carry  = _mm512_srli_epi64(D1_2,52);
	D1_2 = _mm512_and_si512(D1_2,mask52);

	D1_3 = _mm512_madd52hi_epu64(carry,alpah1,alpah1);


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

	// Conversion in base 2^103

	carry  = _mm512_srli_epi64(D1_1,51);
	D1_1 = _mm512_and_si512(D1_1,mask51);// radix 2^103
	D1_2 = _mm512_add_epi64(_mm512_slli_epi64(D1_2,1),carry);
	D1_2 = _mm512_add_epi64(D1_2,D2_0);
	carry = _mm512_srli_epi64(D1_2,52);
	D1_2 = _mm512_and_si512(D1_2,mask52);
	D1_3 = _mm512_add_epi64(_mm512_slli_epi64(D1_3,1),carry);
	D1_3 = _mm512_add_epi64(D1_3,D2_1);
	carry  = _mm512_srli_epi64(D1_3,51);
	D1_3 = _mm512_and_si512(D1_3,mask51);// radix 2^103

	// Final reconstruction


	// tmp = D0+D2, radix 2^103

	__m512i tmp0 = _mm512_add_epi64(D0_0,D2_0);
	__m512i carry_tmp  = _mm512_srli_epi64(tmp0,52);
	tmp0 = _mm512_and_si512(tmp0,mask52);

	__m512i tmp1 = _mm512_add_epi64(D0_1,carry_tmp);
	tmp1 = _mm512_add_epi64(tmp1,D2_1);
	carry_tmp  = _mm512_srli_epi64(tmp1,51);
	tmp1 = _mm512_and_si512(tmp1,mask51);// radix 2**103

	__m512i tmp2 = _mm512_add_epi64(D0_2,carry_tmp);
	tmp2 = _mm512_add_epi64(tmp2,D2_2);
	carry_tmp  = _mm512_srli_epi64(tmp2,52);
	tmp2 = _mm512_and_si512(tmp2,mask52);

	__m512i tmp3 = _mm512_add_epi64(D0_3,carry_tmp);
	tmp3 = _mm512_add_epi64(tmp3,D2_3);
	carry_tmp  = _mm512_srli_epi64(tmp3,51);
	tmp3 = _mm512_and_si512(tmp3,mask51);// radix 2**103




	// D1 = D1 -tmp, radix 2^103

	D1_0 = _mm512_sub_epi64(D1_0,tmp0);
	__m512i borrow = _mm512_srli_epi64(D1_0,52)&un;
	D1_0 = _mm512_and_si512(D1_0,mask52);
	borrow = _mm512_add_epi64(tmp1,borrow);
	D1_1 = _mm512_sub_epi64(D1_1,borrow);
	borrow = _mm512_srli_epi64(D1_1,51)&un;
	D1_1 = _mm512_and_si512(D1_1,mask51);// radix 2**103

	borrow = _mm512_add_epi64(tmp2,borrow);
	D1_2 = _mm512_sub_epi64(D1_2,borrow);
	borrow  = _mm512_srli_epi64(D1_2,52)&un;
	D1_2 = _mm512_and_si512(D1_2,mask52);

	borrow = _mm512_add_epi64(tmp3,borrow);
	D1_3 = _mm512_sub_epi64(D1_3,borrow);
	borrow = _mm512_srli_epi64(D1_3,51)&un;
	D1_3 = _mm512_and_si512(D1_3,mask51);// radix 2**103


	// Final borrows

	borrow = _mm512_add_epi64(carry_tmp,borrow);
	D2_2 = _mm512_add_epi64(D2_2,carry);
	D2_2 = _mm512_sub_epi64(D2_2,borrow);
	borrow  = _mm512_srli_epi64(D2_2,52)&un;
	D2_2 = _mm512_and_si512(D2_2,mask52);

	D2_3 = _mm512_sub_epi64(D2_3,borrow);


	_mm512_store_epi64(out+0,D0_0);
	_mm512_store_epi64(out+1,D0_1);
	_mm512_store_epi64(out+2,D1_0);
	_mm512_store_epi64(out+3,D1_1);
	_mm512_store_epi64(out+4,D1_2);
	_mm512_store_epi64(out+5,D1_3);
	_mm512_store_epi64(out+6,D2_2);
	_mm512_store_epi64(out+7,D2_3);
}

