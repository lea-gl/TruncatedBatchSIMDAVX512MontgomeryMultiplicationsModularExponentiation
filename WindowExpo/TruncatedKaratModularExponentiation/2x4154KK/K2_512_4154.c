
#include "K512_2078.c"

	// Conversion in base 2^2077

static inline void force_inline conversion_8_r2077K(__m512i out[80], __m512i in[80])
{
	
	/*__m512i in_0 = _mm512_load_epi64(in);	__m512i in_1 = _mm512_load_epi64(in+1);
	__m512i in_2 = _mm512_load_epi64(in+2);	__m512i in_3 = _mm512_load_epi64(in+3);
	__m512i in_4 = _mm512_load_epi64(in+4);	__m512i in_5 = _mm512_load_epi64(in+5);
	__m512i in_6 = _mm512_load_epi64(in+6);	__m512i in_7 = _mm512_load_epi64(in+7);
	__m512i in_8 = _mm512_load_epi64(in+8);	__m512i in_9 = _mm512_load_epi64(in+9);
	__m512i in_10 = _mm512_load_epi64(in+10);	__m512i in_11 = _mm512_load_epi64(in+11);
	__m512i in_12 = _mm512_load_epi64(in+12);	__m512i in_13 = _mm512_load_epi64(in+13);
	__m512i in_14 = _mm512_load_epi64(in+14);	__m512i in_15 = _mm512_load_epi64(in+15);
	__m512i in_16 = _mm512_load_epi64(in+16);	__m512i in_17 = _mm512_load_epi64(in+17);
	__m512i in_18 = _mm512_load_epi64(in+18);	__m512i in_19 = _mm512_load_epi64(in+19);
	__m512i in_20 = _mm512_load_epi64(in+20);	__m512i in_21 = _mm512_load_epi64(in+21);
	__m512i in_22 = _mm512_load_epi64(in+22);	__m512i in_23 = _mm512_load_epi64(in+23);
	__m512i in_24 = _mm512_load_epi64(in+24);	__m512i in_25 = _mm512_load_epi64(in+25);
	__m512i in_26 = _mm512_load_epi64(in+26);	__m512i in_27 = _mm512_load_epi64(in+27);
	__m512i in_28 = _mm512_load_epi64(in+28);	__m512i in_29 = _mm512_load_epi64(in+29);
	__m512i in_30 = _mm512_load_epi64(in+30);	__m512i in_31 = _mm512_load_epi64(in+31);
	__m512i in_32 = _mm512_load_epi64(in+32);	__m512i in_33 = _mm512_load_epi64(in+33);
	__m512i in_34 = _mm512_load_epi64(in+34);	__m512i in_35 = _mm512_load_epi64(in+35);
	__m512i in_36 = _mm512_load_epi64(in+36);	__m512i in_37 = _mm512_load_epi64(in+37);
	__m512i in_38 = _mm512_load_epi64(in+38);	__m512i in_39 = _mm512_load_epi64(in+39);//*/
	
	__m512i in_39 = _mm512_load_epi64(in+39);
	__m512i in_40 = _mm512_load_epi64(in+40);	__m512i in_41 = _mm512_load_epi64(in+41);
	__m512i in_42 = _mm512_load_epi64(in+42);	__m512i in_43 = _mm512_load_epi64(in+43);
	__m512i in_44 = _mm512_load_epi64(in+44);	__m512i in_45 = _mm512_load_epi64(in+45);
	__m512i in_46 = _mm512_load_epi64(in+46);	__m512i in_47 = _mm512_load_epi64(in+47);
	__m512i in_48 = _mm512_load_epi64(in+48);	__m512i in_49 = _mm512_load_epi64(in+49);
	__m512i in_50 = _mm512_load_epi64(in+50);	__m512i in_51 = _mm512_load_epi64(in+51);
	__m512i in_52 = _mm512_load_epi64(in+52);	__m512i in_53 = _mm512_load_epi64(in+53);
	__m512i in_54 = _mm512_load_epi64(in+54);	__m512i in_55 = _mm512_load_epi64(in+55);
	__m512i in_56 = _mm512_load_epi64(in+56);	__m512i in_57 = _mm512_load_epi64(in+57);
	__m512i in_58 = _mm512_load_epi64(in+58);	__m512i in_59 = _mm512_load_epi64(in+59);
	__m512i in_60 = _mm512_load_epi64(in+60);	__m512i in_61 = _mm512_load_epi64(in+61);
	__m512i in_62 = _mm512_load_epi64(in+62);	__m512i in_63 = _mm512_load_epi64(in+63);
	__m512i in_64 = _mm512_load_epi64(in+64);	__m512i in_65 = _mm512_load_epi64(in+65);
	__m512i in_66 = _mm512_load_epi64(in+66);	__m512i in_67 = _mm512_load_epi64(in+67);
	__m512i in_68 = _mm512_load_epi64(in+68);	__m512i in_69 = _mm512_load_epi64(in+69);
	__m512i in_70 = _mm512_load_epi64(in+70);	__m512i in_71 = _mm512_load_epi64(in+71);
	__m512i in_72 = _mm512_load_epi64(in+72);	__m512i in_73 = _mm512_load_epi64(in+73);
	__m512i in_74 = _mm512_load_epi64(in+74);	__m512i in_75 = _mm512_load_epi64(in+75);
	__m512i in_76 = _mm512_load_epi64(in+76);	__m512i in_77 = _mm512_load_epi64(in+77);
	__m512i in_78 = _mm512_load_epi64(in+78);	__m512i in_79 = _mm512_load_epi64(in+79);
	


	__m512i carry = in_39>>50;	in_40 = (in_40<<1)+carry;// radix 2^2077
	in_39 &= mask50;	carry = in_40>>52;
	in_41 = (in_41<<1)+carry;	in_40 &= mask52;
	carry = in_41>>52;	in_42 = (in_42<<1)+carry;
	in_41 &= mask52;	carry = in_42>>52;
	in_43 = (in_43<<1)+carry;	in_42 &= mask52;
	carry = in_43>>52;	in_44 = (in_44<<1)+carry;
	in_43 &= mask52;	carry = in_44>>52;
	in_45 = (in_45<<1)+carry;	in_44 &= mask52;
	carry = in_45>>52;	in_46 = (in_46<<1)+carry;
	in_45 &= mask52;	carry = in_46>>52;
	in_47 = (in_47<<1)+carry;	in_46 &= mask52;
	carry = in_47>>52;	in_48 = (in_48<<1)+carry;
	in_47 &= mask52;	carry = in_48>>52;
	in_49 = (in_49<<1)+carry;	in_48 &= mask52;
	carry = in_49>>52;	in_50 = (in_50<<1)+carry;
	in_49 &= mask52;	carry = in_50>>52;
	in_51 = (in_51<<1)+carry;	in_50 &= mask52;
	carry = in_51>>52;	in_52 = (in_52<<1)+carry;
	in_51 &= mask52;	carry = in_52>>52;
	in_53 = (in_53<<1)+carry;	in_52 &= mask52;
	carry = in_53>>52;	in_54 = (in_54<<1)+carry;
	in_53 &= mask52;	carry = in_54>>52;
	in_55 = (in_55<<1)+carry;	in_54 &= mask52;
	carry = in_55>>52;	in_56 = (in_56<<1)+carry;
	in_55 &= mask52;	carry = in_56>>52;
	in_57 = (in_57<<1)+carry;	in_56 &= mask52;
	carry = in_57>>52;	in_58 = (in_58<<1)+carry;
	carry = in_58>>52;
	in_57 &= mask52;	in_59 = (in_59<<1)+carry;
	in_58 &= mask52;	carry = in_59>>51;// radix 2^1039
	in_60 = (in_60<<1)+carry;	in_59 &= mask51;
	carry = in_60>>52;	in_61 = (in_61<<1)+carry;
	in_60 &= mask52;	carry = in_61>>52;
	in_62 = (in_62<<1)+carry;	in_61 &= mask52;
	carry = in_62>>52;	in_63 = (in_63<<1)+carry;
	in_62 &= mask52;	carry = in_63>>52;
	in_64 = (in_64<<1)+carry;	in_63 &= mask52;
	carry = in_64>>52;	in_65 = (in_65<<1)+carry;
	in_64 &= mask52;	carry = in_65>>52;
	in_66 = (in_66<<1)+carry;	in_65 &= mask52;
	carry = in_66>>52;	in_67 = (in_67<<1)+carry;
	in_66 &= mask52;	carry = in_67>>52;
	in_68 = (in_68<<1)+carry;	in_67 &= mask52;
	carry = in_68>>52;	in_69 = (in_69<<1)+carry;
	in_68 &= mask52;	carry = in_69>>52;
	in_70 = (in_70<<1)+carry;	in_69 &= mask52;
	carry = in_70>>52;	in_71 = (in_71<<1)+carry;
	in_70 &= mask52;	carry = in_71>>52;
	in_72 = (in_72<<1)+carry;	in_71 &= mask52;
	carry = in_72>>52;	in_73 = (in_73<<1)+carry;
	in_72 &= mask52;	carry = in_73>>52;
	in_74 = (in_74<<1)+carry;	in_73 &= mask52;
	carry = in_74>>52;	in_75 = (in_75<<1)+carry;
	in_74 &= mask52;	carry = in_75>>52;
	in_76 = (in_76<<1)+carry;	in_75 &= mask52;
	carry = in_76>>52;	in_77 = (in_77<<1)+carry;
	in_76 &= mask52;	carry = in_77>>52;
	in_78 = (in_78<<1)+carry;	in_77 &= mask52;
	carry = in_78>>52;	in_79 = (in_79<<1)+carry;
	in_78 &= mask52;
			
	/*_mm512_store_epi64(out+0,in_0);	_mm512_store_epi64(out+1,in_1);
	_mm512_store_epi64(out+2,in_2);	_mm512_store_epi64(out+3,in_3);
	_mm512_store_epi64(out+4,in_4);	_mm512_store_epi64(out+5,in_5);
	_mm512_store_epi64(out+6,in_6);	_mm512_store_epi64(out+7,in_7);
	_mm512_store_epi64(out+8,in_8);	_mm512_store_epi64(out+9,in_9);
	_mm512_store_epi64(out+10,in_10);	_mm512_store_epi64(out+11,in_11);
	_mm512_store_epi64(out+12,in_12);	_mm512_store_epi64(out+13,in_13);
	_mm512_store_epi64(out+14,in_14);	_mm512_store_epi64(out+15,in_15);
	_mm512_store_epi64(out+16,in_16);	_mm512_store_epi64(out+17,in_17);
	_mm512_store_epi64(out+18,in_18);	_mm512_store_epi64(out+19,in_19);
	_mm512_store_epi64(out+20,in_20);	_mm512_store_epi64(out+21,in_21);
	_mm512_store_epi64(out+22,in_22);	_mm512_store_epi64(out+23,in_23);
	_mm512_store_epi64(out+24,in_24);	_mm512_store_epi64(out+25,in_25);
	_mm512_store_epi64(out+26,in_26);	_mm512_store_epi64(out+27,in_27);
	_mm512_store_epi64(out+28,in_28);	_mm512_store_epi64(out+29,in_29);
	_mm512_store_epi64(out+30,in_30);	_mm512_store_epi64(out+31,in_31);
	_mm512_store_epi64(out+32,in_32);	_mm512_store_epi64(out+33,in_33);
	_mm512_store_epi64(out+34,in_34);	_mm512_store_epi64(out+35,in_35);
	_mm512_store_epi64(out+36,in_36);	_mm512_store_epi64(out+37,in_37);
	_mm512_store_epi64(out+38,in_38);//*/	_mm512_store_epi64(out+39,in_39);
	_mm512_store_epi64(out+40,in_40);	_mm512_store_epi64(out+41,in_41);
	_mm512_store_epi64(out+42,in_42);	_mm512_store_epi64(out+43,in_43);
	_mm512_store_epi64(out+44,in_44);	_mm512_store_epi64(out+45,in_45);
	_mm512_store_epi64(out+46,in_46);	_mm512_store_epi64(out+47,in_47);
	_mm512_store_epi64(out+48,in_48);	_mm512_store_epi64(out+49,in_49);
	_mm512_store_epi64(out+50,in_50);	_mm512_store_epi64(out+51,in_51);
	_mm512_store_epi64(out+52,in_52);	_mm512_store_epi64(out+53,in_53);
	_mm512_store_epi64(out+54,in_54);	_mm512_store_epi64(out+55,in_55);
	_mm512_store_epi64(out+56,in_56);	_mm512_store_epi64(out+57,in_57);
	_mm512_store_epi64(out+58,in_58);	_mm512_store_epi64(out+59,in_59);
	_mm512_store_epi64(out+60,in_60);	_mm512_store_epi64(out+61,in_61);
	_mm512_store_epi64(out+62,in_62);	_mm512_store_epi64(out+63,in_63);
	_mm512_store_epi64(out+64,in_64);	_mm512_store_epi64(out+65,in_65);
	_mm512_store_epi64(out+66,in_66);	_mm512_store_epi64(out+67,in_67);
	_mm512_store_epi64(out+68,in_68);	_mm512_store_epi64(out+69,in_69);
	_mm512_store_epi64(out+70,in_70);	_mm512_store_epi64(out+71,in_71);
	_mm512_store_epi64(out+72,in_72);	_mm512_store_epi64(out+73,in_73);
	_mm512_store_epi64(out+74,in_74);	_mm512_store_epi64(out+75,in_75);
	_mm512_store_epi64(out+76,in_76);	_mm512_store_epi64(out+77,in_77);
	_mm512_store_epi64(out+78,in_78);	_mm512_store_epi64(out+79,in_79);
	
}


// addition of operands whose size is 2077 bits, and with radix 2**1039 representation, result size 2078 bits

static inline __m512i force_inline add512_8_2078K(__m512i out[40], __m512i a512[40], __m512i b512[40])
{

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

	__m512i a51220 = _mm512_load_epi64(a512+20), b51220 = _mm512_load_epi64(b512+20);
	__m512i a51221 = _mm512_load_epi64(a512+21), b51221 = _mm512_load_epi64(b512+21);
	__m512i a51222 = _mm512_load_epi64(a512+22), b51222 = _mm512_load_epi64(b512+22);
	__m512i a51223 = _mm512_load_epi64(a512+23), b51223 = _mm512_load_epi64(b512+23);
	__m512i a51224 = _mm512_load_epi64(a512+24), b51224 = _mm512_load_epi64(b512+24);
	__m512i a51225 = _mm512_load_epi64(a512+25), b51225 = _mm512_load_epi64(b512+25);
	__m512i a51226 = _mm512_load_epi64(a512+26), b51226 = _mm512_load_epi64(b512+26);
	__m512i a51227 = _mm512_load_epi64(a512+27), b51227 = _mm512_load_epi64(b512+27);
	__m512i a51228 = _mm512_load_epi64(a512+28), b51228 = _mm512_load_epi64(b512+28);
	__m512i a51229 = _mm512_load_epi64(a512+29), b51229 = _mm512_load_epi64(b512+29);
	__m512i a51230 = _mm512_load_epi64(a512+30), b51230 = _mm512_load_epi64(b512+30);
	__m512i a51231 = _mm512_load_epi64(a512+31), b51231 = _mm512_load_epi64(b512+31);
	__m512i a51232 = _mm512_load_epi64(a512+32), b51232 = _mm512_load_epi64(b512+32);
	__m512i a51233 = _mm512_load_epi64(a512+33), b51233 = _mm512_load_epi64(b512+33);
	__m512i a51234 = _mm512_load_epi64(a512+34), b51234 = _mm512_load_epi64(b512+34);
	__m512i a51235 = _mm512_load_epi64(a512+35), b51235 = _mm512_load_epi64(b512+35);
	__m512i a51236 = _mm512_load_epi64(a512+36), b51236 = _mm512_load_epi64(b512+36);
	__m512i a51237 = _mm512_load_epi64(a512+37), b51237 = _mm512_load_epi64(b512+37);
	__m512i a51238 = _mm512_load_epi64(a512+38), b51238 = _mm512_load_epi64(b512+38);
	__m512i a51239 = _mm512_load_epi64(a512+39), b51239 = _mm512_load_epi64(b512+39);
	

	
	__m512i out_0 = _mm512_add_epi64(a5120,b5120);
	__m512i carry = out_0>>52;	out_0 &= mask52;
	
	
	/*displayVect512(&a5120,"a5120");
	displayVect512(&b5120,"b5120");
	displayVect512(&out_0,"out_0");
	getchar();//*/
	
	__m512i out_1 = _mm512_add_epi64(a5121,carry);	out_1 = _mm512_add_epi64(out_1,b5121);
	carry = out_1>>52;	out_1 &= mask52;
	__m512i out_2 = _mm512_add_epi64(a5122,carry);	out_2 = _mm512_add_epi64(out_2,b5122);
	carry = out_2>>52;	out_2 &= mask52;
	__m512i out_3 = _mm512_add_epi64(a5123,carry);	out_3 = _mm512_add_epi64(out_3,b5123);
	carry = out_3>>52;	out_3 &= mask52;
	__m512i out_4 = _mm512_add_epi64(a5124,carry);	out_4 = _mm512_add_epi64(out_4,b5124);
	carry = out_4>>52;	out_4 &= mask52;
	__m512i out_5 = _mm512_add_epi64(a5125,carry);	out_5 = _mm512_add_epi64(out_5,b5125);
	carry = out_5>>52;	out_5 &= mask52;
	__m512i out_6 = _mm512_add_epi64(a5126,carry);	out_6 = _mm512_add_epi64(out_6,b5126);
	carry = out_6>>52;	out_6 &= mask52;
	__m512i out_7 = _mm512_add_epi64(a5127,carry);	out_7 = _mm512_add_epi64(out_7,b5127);
	carry = out_7>>52;	out_7 &= mask52;
	__m512i out_8 = _mm512_add_epi64(a5128,carry);	out_8 = _mm512_add_epi64(out_8,b5128);
	carry = out_8>>52;	out_8 &= mask52;
	__m512i out_9 = _mm512_add_epi64(a5129,carry);	out_9 = _mm512_add_epi64(out_9,b5129);
	carry = out_9>>52;	out_9 &= mask52;
	__m512i out_10 = _mm512_add_epi64(a51210,carry);	out_10 = _mm512_add_epi64(out_10,b51210);
	carry = out_10>>52;	out_10 &= mask52;
	__m512i out_11 = _mm512_add_epi64(a51211,carry);	out_11 = _mm512_add_epi64(out_11,b51211);
	carry = out_11>>52;	out_11 &= mask52;
	__m512i out_12 = _mm512_add_epi64(a51212,carry);	out_12 = _mm512_add_epi64(out_12,b51212);
	carry = out_12>>52;	out_12 &= mask52;
	__m512i out_13 = _mm512_add_epi64(a51213,carry);	out_13 = _mm512_add_epi64(out_13,b51213);
	carry = out_13>>52;	out_13 &= mask52;
	__m512i out_14 = _mm512_add_epi64(a51214,carry);	out_14 = _mm512_add_epi64(out_14,b51214);
	carry = out_14>>52;	out_14 &= mask52;
	__m512i out_15 = _mm512_add_epi64(a51215,carry);	out_15 = _mm512_add_epi64(out_15,b51215);
	carry = out_15>>52;	out_15 &= mask52;
	__m512i out_16 = _mm512_add_epi64(a51216,carry);	out_16 = _mm512_add_epi64(out_16,b51216);
	carry = out_16>>52;	out_16 &= mask52;
	__m512i out_17 = _mm512_add_epi64(a51217,carry);	out_17 = _mm512_add_epi64(out_17,b51217);
	carry = out_17>>52;	out_17 &= mask52;
	__m512i out_18 = _mm512_add_epi64(a51218,carry);	out_18 = _mm512_add_epi64(out_18,b51218);
	carry = out_18>>52;	out_18 &= mask52;
	__m512i out_19 = _mm512_add_epi64(a51219,carry);	out_19 = _mm512_add_epi64(out_19,b51219);
	carry = out_19>>51;// radix 2**1039
		out_19 &= mask51;



	__m512i out_20 = _mm512_add_epi64(a51220,carry);	out_20 = _mm512_add_epi64(out_20,b51220);
	carry = out_20>>52;	out_20 &= mask52;
	__m512i out_21 = _mm512_add_epi64(a51221,carry);	out_21 = _mm512_add_epi64(out_21,b51221);
	carry = out_21>>52;	out_21 &= mask52;
	__m512i out_22 = _mm512_add_epi64(a51222,carry);	out_22 = _mm512_add_epi64(out_22,b51222);
	carry = out_22>>52;	out_22 &= mask52;
	__m512i out_23 = _mm512_add_epi64(a51223,carry);	out_23 = _mm512_add_epi64(out_23,b51223);
	carry = out_23>>52;	out_23 &= mask52;
	__m512i out_24 = _mm512_add_epi64(a51224,carry);	out_24 = _mm512_add_epi64(out_24,b51224);
	carry = out_24>>52;
	out_24 &= mask52;
	__m512i out_25 = _mm512_add_epi64(a51225,carry);	out_25 = _mm512_add_epi64(out_25,b51225);
	carry = out_25>>52;	out_25 &= mask52;
	__m512i out_26 = _mm512_add_epi64(a51226,carry);	out_26 = _mm512_add_epi64(out_26,b51226);
	carry = out_26>>52;	out_26 &= mask52;
	__m512i out_27 = _mm512_add_epi64(a51227,carry);	out_27 = _mm512_add_epi64(out_27,b51227);
	carry = out_27>>52;	out_27 &= mask52;
	__m512i out_28 = _mm512_add_epi64(a51228,carry);	out_28 = _mm512_add_epi64(out_28,b51228);
	carry = out_28>>52;	out_28 &= mask52;
	__m512i out_29 = _mm512_add_epi64(a51229,carry);	out_29 = _mm512_add_epi64(out_29,b51229);
	carry = out_29>>52;	out_29 &= mask52;
	__m512i out_30 = _mm512_add_epi64(a51230,carry);	out_30 = _mm512_add_epi64(out_30,b51230);
	carry = out_30>>52;	out_30 &= mask52;
	__m512i out_31 = _mm512_add_epi64(a51231,carry);	out_31 = _mm512_add_epi64(out_31,b51231);
	carry = out_31>>52;	out_31 &= mask52;
	__m512i out_32 = _mm512_add_epi64(a51232,carry);	out_32 = _mm512_add_epi64(out_32,b51232);
	carry = out_32>>52;	out_32 &= mask52;
	__m512i out_33 = _mm512_add_epi64(a51233,carry);	out_33 = _mm512_add_epi64(out_33,b51233);
	carry = out_33>>52;	out_33 &= mask52;
	__m512i out_34 = _mm512_add_epi64(a51234,carry);	out_34 = _mm512_add_epi64(out_34,b51234);
	carry = out_34>>52;	out_34 &= mask52;
	__m512i out_35 = _mm512_add_epi64(a51235,carry);	out_35 = _mm512_add_epi64(out_35,b51235);
	carry = out_35>>52;	out_35 &= mask52;
	__m512i out_36 = _mm512_add_epi64(a51236,carry);	out_36 = _mm512_add_epi64(out_36,b51236);
	carry = out_36>>52;	out_36 &= mask52;
	__m512i out_37 = _mm512_add_epi64(a51237,carry);	out_37 = _mm512_add_epi64(out_37,b51237);
	carry = out_37>>52;	out_37 &= mask52;
	__m512i out_38 = _mm512_add_epi64(a51238,carry);	out_38 = _mm512_add_epi64(out_38,b51238);
	carry = out_38>>52;	out_38 &= mask52;
	__m512i out_39 = _mm512_add_epi64(a51239,carry);	out_39 = _mm512_add_epi64(out_39,b51239);
	//carry = out_39>>49;// radix 2**2077
	//out_39 &= mask50;
	
	

	_mm512_store_epi64(out+0,out_0);	_mm512_store_epi64(out+1,out_1);
	_mm512_store_epi64(out+2,out_2);	_mm512_store_epi64(out+3,out_3);
	_mm512_store_epi64(out+4,out_4);	_mm512_store_epi64(out+5,out_5);
	_mm512_store_epi64(out+6,out_6);	_mm512_store_epi64(out+7,out_7);
	_mm512_store_epi64(out+8,out_8);	_mm512_store_epi64(out+9,out_9);
	_mm512_store_epi64(out+10,out_10);	_mm512_store_epi64(out+11,out_11);
	_mm512_store_epi64(out+12,out_12);	_mm512_store_epi64(out+13,out_13);
	_mm512_store_epi64(out+14,out_14);	_mm512_store_epi64(out+15,out_15);
	_mm512_store_epi64(out+16,out_16);	_mm512_store_epi64(out+17,out_17);
	_mm512_store_epi64(out+18,out_18);	_mm512_store_epi64(out+19,out_19);
	_mm512_store_epi64(out+20,out_20);	_mm512_store_epi64(out+21,out_21);
	_mm512_store_epi64(out+22,out_22);	_mm512_store_epi64(out+23,out_23);
	_mm512_store_epi64(out+24,out_24);	_mm512_store_epi64(out+25,out_25);
	_mm512_store_epi64(out+26,out_26);	_mm512_store_epi64(out+27,out_27);
	_mm512_store_epi64(out+28,out_28);	_mm512_store_epi64(out+29,out_29);
	_mm512_store_epi64(out+30,out_30);	_mm512_store_epi64(out+31,out_31);
	_mm512_store_epi64(out+32,out_32);	_mm512_store_epi64(out+33,out_33);
	_mm512_store_epi64(out+34,out_34);	_mm512_store_epi64(out+35,out_35);
	_mm512_store_epi64(out+36,out_36);	_mm512_store_epi64(out+37,out_37);
	_mm512_store_epi64(out+38,out_38);	_mm512_store_epi64(out+39,out_39);
	
	
	/*displayVect512_NB(out,"out",40);
	getchar();//*/
	
	return carry;
	

}


// addition of operands whose size is 2077 bits, and with radix 2**1039 representation, result size 2078 bits
// with carry (to be placed in out[0] !)

static inline void force_inline addC512_8_2078K(__m512i out[40], __m512i a512[40], __m512i b512[40])
{

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

	__m512i a51220 = _mm512_load_epi64(a512+20), b51220 = _mm512_load_epi64(b512+20);
	__m512i a51221 = _mm512_load_epi64(a512+21), b51221 = _mm512_load_epi64(b512+21);
	__m512i a51222 = _mm512_load_epi64(a512+22), b51222 = _mm512_load_epi64(b512+22);
	__m512i a51223 = _mm512_load_epi64(a512+23), b51223 = _mm512_load_epi64(b512+23);
	__m512i a51224 = _mm512_load_epi64(a512+24), b51224 = _mm512_load_epi64(b512+24);
	__m512i a51225 = _mm512_load_epi64(a512+25), b51225 = _mm512_load_epi64(b512+25);
	__m512i a51226 = _mm512_load_epi64(a512+26), b51226 = _mm512_load_epi64(b512+26);
	__m512i a51227 = _mm512_load_epi64(a512+27), b51227 = _mm512_load_epi64(b512+27);
	__m512i a51228 = _mm512_load_epi64(a512+28), b51228 = _mm512_load_epi64(b512+28);
	__m512i a51229 = _mm512_load_epi64(a512+29), b51229 = _mm512_load_epi64(b512+29);
	__m512i a51230 = _mm512_load_epi64(a512+30), b51230 = _mm512_load_epi64(b512+30);
	__m512i a51231 = _mm512_load_epi64(a512+31), b51231 = _mm512_load_epi64(b512+31);
	__m512i a51232 = _mm512_load_epi64(a512+32), b51232 = _mm512_load_epi64(b512+32);
	__m512i a51233 = _mm512_load_epi64(a512+33), b51233 = _mm512_load_epi64(b512+33);
	__m512i a51234 = _mm512_load_epi64(a512+34), b51234 = _mm512_load_epi64(b512+34);
	__m512i a51235 = _mm512_load_epi64(a512+35), b51235 = _mm512_load_epi64(b512+35);
	__m512i a51236 = _mm512_load_epi64(a512+36), b51236 = _mm512_load_epi64(b512+36);
	__m512i a51237 = _mm512_load_epi64(a512+37), b51237 = _mm512_load_epi64(b512+37);
	__m512i a51238 = _mm512_load_epi64(a512+38), b51238 = _mm512_load_epi64(b512+38);
	__m512i a51239 = _mm512_load_epi64(a512+39), b51239 = _mm512_load_epi64(b512+39);
	

	
	__m512i out_0 = _mm512_add_epi64(out[0],a5120);	out_0 = _mm512_add_epi64(out_0,b5120);
	__m512i carry = out_0>>52;	out_0 &= mask52;
	__m512i out_1 = _mm512_add_epi64(a5121,carry);	out_1 = _mm512_add_epi64(out_1,b5121);
	carry = out_1>>52;	out_1 &= mask52;
	__m512i out_2 = _mm512_add_epi64(a5122,carry);	out_2 = _mm512_add_epi64(out_2,b5122);
	carry = out_2>>52;	out_2 &= mask52;
	__m512i out_3 = _mm512_add_epi64(a5123,carry);	out_3 = _mm512_add_epi64(out_3,b5123);
	carry = out_3>>52;	out_3 &= mask52;
	__m512i out_4 = _mm512_add_epi64(a5124,carry);	out_4 = _mm512_add_epi64(out_4,b5124);
	carry = out_4>>52;	out_4 &= mask52;
	__m512i out_5 = _mm512_add_epi64(a5125,carry);	out_5 = _mm512_add_epi64(out_5,b5125);
	carry = out_5>>52;	out_5 &= mask52;
	__m512i out_6 = _mm512_add_epi64(a5126,carry);	out_6 = _mm512_add_epi64(out_6,b5126);
	carry = out_6>>52;	out_6 &= mask52;
	__m512i out_7 = _mm512_add_epi64(a5127,carry);	out_7 = _mm512_add_epi64(out_7,b5127);
	carry = out_7>>52;	out_7 &= mask52;
	__m512i out_8 = _mm512_add_epi64(a5128,carry);	out_8 = _mm512_add_epi64(out_8,b5128);
	carry = out_8>>52;	out_8 &= mask52;
	__m512i out_9 = _mm512_add_epi64(a5129,carry);	out_9 = _mm512_add_epi64(out_9,b5129);
	carry = out_9>>52;	out_9 &= mask52;
	__m512i out_10 = _mm512_add_epi64(a51210,carry);	out_10 = _mm512_add_epi64(out_10,b51210);
	carry = out_10>>52;	out_10 &= mask52;
	__m512i out_11 = _mm512_add_epi64(a51211,carry);	out_11 = _mm512_add_epi64(out_11,b51211);
	carry = out_11>>52;	out_11 &= mask52;
	__m512i out_12 = _mm512_add_epi64(a51212,carry);	out_12 = _mm512_add_epi64(out_12,b51212);
	carry = out_12>>52;	out_12 &= mask52;
	__m512i out_13 = _mm512_add_epi64(a51213,carry);	out_13 = _mm512_add_epi64(out_13,b51213);
	carry = out_13>>52;	out_13 &= mask52;
	__m512i out_14 = _mm512_add_epi64(a51214,carry);	out_14 = _mm512_add_epi64(out_14,b51214);
	carry = out_14>>52;	out_14 &= mask52;
	__m512i out_15 = _mm512_add_epi64(a51215,carry);	out_15 = _mm512_add_epi64(out_15,b51215);
	carry = out_15>>52;	out_15 &= mask52;
	__m512i out_16 = _mm512_add_epi64(a51216,carry);	out_16 = _mm512_add_epi64(out_16,b51216);
	carry = out_16>>52;	out_16 &= mask52;
	__m512i out_17 = _mm512_add_epi64(a51217,carry);	out_17 = _mm512_add_epi64(out_17,b51217);
	carry = out_17>>52;	out_17 &= mask52;
	__m512i out_18 = _mm512_add_epi64(a51218,carry);	out_18 = _mm512_add_epi64(out_18,b51218);
	carry = out_18>>52;	out_18 &= mask52;
	__m512i out_19 = _mm512_add_epi64(a51219,carry);	out_19 = _mm512_add_epi64(out_19,b51219);
	carry = out_19>>51;// radix 2**1039
		out_19 &= mask51;



	__m512i out_20 = _mm512_add_epi64(a51220,carry);	out_20 = _mm512_add_epi64(out_20,b51220);
	carry = out_20>>52;	out_20 &= mask52;
	__m512i out_21 = _mm512_add_epi64(a51221,carry);	out_21 = _mm512_add_epi64(out_21,b51221);
	carry = out_21>>52;	out_21 &= mask52;
	__m512i out_22 = _mm512_add_epi64(a51222,carry);	out_22 = _mm512_add_epi64(out_22,b51222);
	carry = out_22>>52;	out_22 &= mask52;
	__m512i out_23 = _mm512_add_epi64(a51223,carry);	out_23 = _mm512_add_epi64(out_23,b51223);
	carry = out_23>>52;	out_23 &= mask52;
	__m512i out_24 = _mm512_add_epi64(a51224,carry);	out_24 = _mm512_add_epi64(out_24,b51224);
	carry = out_24>>52;
	out_24 &= mask52;
	__m512i out_25 = _mm512_add_epi64(a51225,carry);	out_25 = _mm512_add_epi64(out_25,b51225);
	carry = out_25>>52;	out_25 &= mask52;
	__m512i out_26 = _mm512_add_epi64(a51226,carry);	out_26 = _mm512_add_epi64(out_26,b51226);
	carry = out_26>>52;	out_26 &= mask52;
	__m512i out_27 = _mm512_add_epi64(a51227,carry);	out_27 = _mm512_add_epi64(out_27,b51227);
	carry = out_27>>52;	out_27 &= mask52;
	__m512i out_28 = _mm512_add_epi64(a51228,carry);	out_28 = _mm512_add_epi64(out_28,b51228);
	carry = out_28>>52;	out_28 &= mask52;
	__m512i out_29 = _mm512_add_epi64(a51229,carry);	out_29 = _mm512_add_epi64(out_29,b51229);
	carry = out_29>>52;	out_29 &= mask52;
	__m512i out_30 = _mm512_add_epi64(a51230,carry);	out_30 = _mm512_add_epi64(out_30,b51230);
	carry = out_30>>52;	out_30 &= mask52;
	__m512i out_31 = _mm512_add_epi64(a51231,carry);	out_31 = _mm512_add_epi64(out_31,b51231);
	carry = out_31>>52;	out_31 &= mask52;
	__m512i out_32 = _mm512_add_epi64(a51232,carry);	out_32 = _mm512_add_epi64(out_32,b51232);
	carry = out_32>>52;	out_32 &= mask52;
	__m512i out_33 = _mm512_add_epi64(a51233,carry);	out_33 = _mm512_add_epi64(out_33,b51233);
	carry = out_33>>52;	out_33 &= mask52;
	__m512i out_34 = _mm512_add_epi64(a51234,carry);	out_34 = _mm512_add_epi64(out_34,b51234);
	carry = out_34>>52;	out_34 &= mask52;
	__m512i out_35 = _mm512_add_epi64(a51235,carry);	out_35 = _mm512_add_epi64(out_35,b51235);
	carry = out_35>>52;	out_35 &= mask52;
	__m512i out_36 = _mm512_add_epi64(a51236,carry);	out_36 = _mm512_add_epi64(out_36,b51236);
	carry = out_36>>52;	out_36 &= mask52;
	__m512i out_37 = _mm512_add_epi64(a51237,carry);	out_37 = _mm512_add_epi64(out_37,b51237);
	carry = out_37>>52;	out_37 &= mask52;
	__m512i out_38 = _mm512_add_epi64(a51238,carry);	out_38 = _mm512_add_epi64(out_38,b51238);
	carry = out_38>>52;	out_38 &= mask52;
	__m512i out_39 = _mm512_add_epi64(a51239,carry);	out_39 = _mm512_add_epi64(out_39,b51239);
	//carry = out_19>>51;// radix 2**1039
	//out_19 &= mask51;
	
	

	_mm512_store_epi64(out+0,out_0);	_mm512_store_epi64(out+1,out_1);
	_mm512_store_epi64(out+2,out_2);	_mm512_store_epi64(out+3,out_3);
	_mm512_store_epi64(out+4,out_4);	_mm512_store_epi64(out+5,out_5);
	_mm512_store_epi64(out+6,out_6);	_mm512_store_epi64(out+7,out_7);
	_mm512_store_epi64(out+8,out_8);	_mm512_store_epi64(out+9,out_9);
	_mm512_store_epi64(out+10,out_10);	_mm512_store_epi64(out+11,out_11);
	_mm512_store_epi64(out+12,out_12);	_mm512_store_epi64(out+13,out_13);
	_mm512_store_epi64(out+14,out_14);	_mm512_store_epi64(out+15,out_15);
	_mm512_store_epi64(out+16,out_16);	_mm512_store_epi64(out+17,out_17);
	_mm512_store_epi64(out+18,out_18);	_mm512_store_epi64(out+19,out_19);
	_mm512_store_epi64(out+20,out_20);	_mm512_store_epi64(out+21,out_21);
	_mm512_store_epi64(out+22,out_22);	_mm512_store_epi64(out+23,out_23);
	_mm512_store_epi64(out+24,out_24);	_mm512_store_epi64(out+25,out_25);
	_mm512_store_epi64(out+26,out_26);	_mm512_store_epi64(out+27,out_27);
	_mm512_store_epi64(out+28,out_28);	_mm512_store_epi64(out+29,out_29);
	_mm512_store_epi64(out+30,out_30);	_mm512_store_epi64(out+31,out_31);
	_mm512_store_epi64(out+32,out_32);	_mm512_store_epi64(out+33,out_33);
	_mm512_store_epi64(out+34,out_34);	_mm512_store_epi64(out+35,out_35);
	_mm512_store_epi64(out+36,out_36);	_mm512_store_epi64(out+37,out_37);
	_mm512_store_epi64(out+38,out_38);	_mm512_store_epi64(out+39,out_39);

}




// subtraction of operands whose size is 4154 bits, and with radix 2**2077/2**1039 representation, result size 4154 bits
// returns borrow


static inline __m512i force_inline sub512_8_4154K(__m512i out[80], __m512i a512[80], __m512i b512[80])
{

	
	__m512i a512_0 = _mm512_load_epi64(a512);	__m512i a512_1 = _mm512_load_epi64(a512+1);
	__m512i a512_2 = _mm512_load_epi64(a512+2);	__m512i a512_3 = _mm512_load_epi64(a512+3);
	__m512i a512_4 = _mm512_load_epi64(a512+4);	__m512i a512_5 = _mm512_load_epi64(a512+5);
	__m512i a512_6 = _mm512_load_epi64(a512+6);	__m512i a512_7 = _mm512_load_epi64(a512+7);
	__m512i a512_8 = _mm512_load_epi64(a512+8);	__m512i a512_9 = _mm512_load_epi64(a512+9);
	__m512i a512_10 = _mm512_load_epi64(a512+10);	__m512i a512_11 = _mm512_load_epi64(a512+11);
	__m512i a512_12 = _mm512_load_epi64(a512+12);	__m512i a512_13 = _mm512_load_epi64(a512+13);
	__m512i a512_14 = _mm512_load_epi64(a512+14);	__m512i a512_15 = _mm512_load_epi64(a512+15);
	__m512i a512_16 = _mm512_load_epi64(a512+16);	__m512i a512_17 = _mm512_load_epi64(a512+17);
	__m512i a512_18 = _mm512_load_epi64(a512+18);	__m512i a512_19 = _mm512_load_epi64(a512+19);
	__m512i a512_20 = _mm512_load_epi64(a512+20);	__m512i a512_21 = _mm512_load_epi64(a512+21);
	__m512i a512_22 = _mm512_load_epi64(a512+22);	__m512i a512_23 = _mm512_load_epi64(a512+23);
	__m512i a512_24 = _mm512_load_epi64(a512+24);	__m512i a512_25 = _mm512_load_epi64(a512+25);
	__m512i a512_26 = _mm512_load_epi64(a512+26);	__m512i a512_27 = _mm512_load_epi64(a512+27);
	__m512i a512_28 = _mm512_load_epi64(a512+28);	__m512i a512_29 = _mm512_load_epi64(a512+29);
	__m512i a512_30 = _mm512_load_epi64(a512+30);	__m512i a512_31 = _mm512_load_epi64(a512+31);
	__m512i a512_32 = _mm512_load_epi64(a512+32);	__m512i a512_33 = _mm512_load_epi64(a512+33);
	__m512i a512_34 = _mm512_load_epi64(a512+34);	__m512i a512_35 = _mm512_load_epi64(a512+35);
	__m512i a512_36 = _mm512_load_epi64(a512+36);	__m512i a512_37 = _mm512_load_epi64(a512+37);
	__m512i a512_38 = _mm512_load_epi64(a512+38);	__m512i a512_39 = _mm512_load_epi64(a512+39);
	
	__m512i a512_40 = _mm512_load_epi64(a512+40);	__m512i a512_41 = _mm512_load_epi64(a512+41);
	__m512i a512_42 = _mm512_load_epi64(a512+42);	__m512i a512_43 = _mm512_load_epi64(a512+43);
	__m512i a512_44 = _mm512_load_epi64(a512+44);	__m512i a512_45 = _mm512_load_epi64(a512+45);
	__m512i a512_46 = _mm512_load_epi64(a512+46);	__m512i a512_47 = _mm512_load_epi64(a512+47);
	__m512i a512_48 = _mm512_load_epi64(a512+48);	__m512i a512_49 = _mm512_load_epi64(a512+49);
	__m512i a512_50 = _mm512_load_epi64(a512+50);	__m512i a512_51 = _mm512_load_epi64(a512+51);
	__m512i a512_52 = _mm512_load_epi64(a512+52);	__m512i a512_53 = _mm512_load_epi64(a512+53);
	__m512i a512_54 = _mm512_load_epi64(a512+54);	__m512i a512_55 = _mm512_load_epi64(a512+55);
	__m512i a512_56 = _mm512_load_epi64(a512+56);	__m512i a512_57 = _mm512_load_epi64(a512+57);
	__m512i a512_58 = _mm512_load_epi64(a512+58);	__m512i a512_59 = _mm512_load_epi64(a512+59);
	__m512i a512_60 = _mm512_load_epi64(a512+60);	__m512i a512_61 = _mm512_load_epi64(a512+61);
	__m512i a512_62 = _mm512_load_epi64(a512+62);	__m512i a512_63 = _mm512_load_epi64(a512+63);
	__m512i a512_64 = _mm512_load_epi64(a512+64);	__m512i a512_65 = _mm512_load_epi64(a512+65);
	__m512i a512_66 = _mm512_load_epi64(a512+66);	__m512i a512_67 = _mm512_load_epi64(a512+67);
	__m512i a512_68 = _mm512_load_epi64(a512+68);	__m512i a512_69 = _mm512_load_epi64(a512+69);
	__m512i a512_70 = _mm512_load_epi64(a512+70);	__m512i a512_71 = _mm512_load_epi64(a512+71);
	__m512i a512_72 = _mm512_load_epi64(a512+72);	__m512i a512_73 = _mm512_load_epi64(a512+73);
	__m512i a512_74 = _mm512_load_epi64(a512+74);	__m512i a512_75 = _mm512_load_epi64(a512+75);
	__m512i a512_76 = _mm512_load_epi64(a512+76);	__m512i a512_77 = _mm512_load_epi64(a512+77);
	__m512i a512_78 = _mm512_load_epi64(a512+78);	__m512i a512_79 = _mm512_load_epi64(a512+79);

	
	__m512i b512_0 = _mm512_load_epi64(b512);	__m512i b512_1 = _mm512_load_epi64(b512+1);
	__m512i b512_2 = _mm512_load_epi64(b512+2);	__m512i b512_3 = _mm512_load_epi64(b512+3);
	__m512i b512_4 = _mm512_load_epi64(b512+4);	__m512i b512_5 = _mm512_load_epi64(b512+5);
	__m512i b512_6 = _mm512_load_epi64(b512+6);	__m512i b512_7 = _mm512_load_epi64(b512+7);
	__m512i b512_8 = _mm512_load_epi64(b512+8);	__m512i b512_9 = _mm512_load_epi64(b512+9);
	__m512i b512_10 = _mm512_load_epi64(b512+10);	__m512i b512_11 = _mm512_load_epi64(b512+11);
	__m512i b512_12 = _mm512_load_epi64(b512+12);	__m512i b512_13 = _mm512_load_epi64(b512+13);
	__m512i b512_14 = _mm512_load_epi64(b512+14);	__m512i b512_15 = _mm512_load_epi64(b512+15);
	__m512i b512_16 = _mm512_load_epi64(b512+16);	__m512i b512_17 = _mm512_load_epi64(b512+17);
	__m512i b512_18 = _mm512_load_epi64(b512+18);	__m512i b512_19 = _mm512_load_epi64(b512+19);
	__m512i b512_20 = _mm512_load_epi64(b512+20);	__m512i b512_21 = _mm512_load_epi64(b512+21);
	__m512i b512_22 = _mm512_load_epi64(b512+22);	__m512i b512_23 = _mm512_load_epi64(b512+23);
	__m512i b512_24 = _mm512_load_epi64(b512+24);	__m512i b512_25 = _mm512_load_epi64(b512+25);
	__m512i b512_26 = _mm512_load_epi64(b512+26);	__m512i b512_27 = _mm512_load_epi64(b512+27);
	__m512i b512_28 = _mm512_load_epi64(b512+28);	__m512i b512_29 = _mm512_load_epi64(b512+29);
	__m512i b512_30 = _mm512_load_epi64(b512+30);	__m512i b512_31 = _mm512_load_epi64(b512+31);
	__m512i b512_32 = _mm512_load_epi64(b512+32);	__m512i b512_33 = _mm512_load_epi64(b512+33);
	__m512i b512_34 = _mm512_load_epi64(b512+34);	__m512i b512_35 = _mm512_load_epi64(b512+35);
	__m512i b512_36 = _mm512_load_epi64(b512+36);	__m512i b512_37 = _mm512_load_epi64(b512+37);
	__m512i b512_38 = _mm512_load_epi64(b512+38);	__m512i b512_39 = _mm512_load_epi64(b512+39);
	
	__m512i b512_40 = _mm512_load_epi64(b512+40);	__m512i b512_41 = _mm512_load_epi64(b512+41);
	__m512i b512_42 = _mm512_load_epi64(b512+42);	__m512i b512_43 = _mm512_load_epi64(b512+43);
	__m512i b512_44 = _mm512_load_epi64(b512+44);	__m512i b512_45 = _mm512_load_epi64(b512+45);
	__m512i b512_46 = _mm512_load_epi64(b512+46);	__m512i b512_47 = _mm512_load_epi64(b512+47);
	__m512i b512_48 = _mm512_load_epi64(b512+48);	__m512i b512_49 = _mm512_load_epi64(b512+49);
	__m512i b512_50 = _mm512_load_epi64(b512+50);	__m512i b512_51 = _mm512_load_epi64(b512+51);
	__m512i b512_52 = _mm512_load_epi64(b512+52);	__m512i b512_53 = _mm512_load_epi64(b512+53);
	__m512i b512_54 = _mm512_load_epi64(b512+54);	__m512i b512_55 = _mm512_load_epi64(b512+55);
	__m512i b512_56 = _mm512_load_epi64(b512+56);	__m512i b512_57 = _mm512_load_epi64(b512+57);
	__m512i b512_58 = _mm512_load_epi64(b512+58);	__m512i b512_59 = _mm512_load_epi64(b512+59);
	__m512i b512_60 = _mm512_load_epi64(b512+60);	__m512i b512_61 = _mm512_load_epi64(b512+61);
	__m512i b512_62 = _mm512_load_epi64(b512+62);	__m512i b512_63 = _mm512_load_epi64(b512+63);
	__m512i b512_64 = _mm512_load_epi64(b512+64);	__m512i b512_65 = _mm512_load_epi64(b512+65);
	__m512i b512_66 = _mm512_load_epi64(b512+66);	__m512i b512_67 = _mm512_load_epi64(b512+67);
	__m512i b512_68 = _mm512_load_epi64(b512+68);	__m512i b512_69 = _mm512_load_epi64(b512+69);
	__m512i b512_70 = _mm512_load_epi64(b512+70);	__m512i b512_71 = _mm512_load_epi64(b512+71);
	__m512i b512_72 = _mm512_load_epi64(b512+72);	__m512i b512_73 = _mm512_load_epi64(b512+73);
	__m512i b512_74 = _mm512_load_epi64(b512+74);	__m512i b512_75 = _mm512_load_epi64(b512+75);
	__m512i b512_76 = _mm512_load_epi64(b512+76);	__m512i b512_77 = _mm512_load_epi64(b512+77);
	__m512i b512_78 = _mm512_load_epi64(b512+78);	__m512i b512_79 = _mm512_load_epi64(b512+79);


	__m512i out_0 = _mm512_sub_epi64(a512_0,b512_0);
	__m512i borrow = _mm512_srli_epi64(out_0,52)&un;
	out_0 = _mm512_and_si512(out_0,mask52);
	
	borrow = _mm512_add_epi64(b512_1,borrow);
	__m512i out_1 = _mm512_sub_epi64(a512_1,borrow);
	borrow  = _mm512_srli_epi64(out_1,52)&un;
	out_1 = _mm512_and_si512(out_1,mask52);

	borrow = _mm512_add_epi64(b512_2,borrow);
	__m512i out_2 = _mm512_sub_epi64(a512_2,borrow);
	borrow  = _mm512_srli_epi64(out_2,52)&un;
	out_2 = _mm512_and_si512(out_2,mask52);

	borrow = _mm512_add_epi64(b512_3,borrow);
	__m512i out_3 = _mm512_sub_epi64(a512_3,borrow);
	borrow  = _mm512_srli_epi64(out_3,52)&un;
	out_3 = _mm512_and_si512(out_3,mask52);

	borrow = _mm512_add_epi64(b512_4,borrow);
	__m512i out_4 = _mm512_sub_epi64(a512_4,borrow);
	borrow  = _mm512_srli_epi64(out_4,52)&un;
	out_4 = _mm512_and_si512(out_4,mask52);

	borrow = _mm512_add_epi64(b512_5,borrow);
	__m512i out_5 = _mm512_sub_epi64(a512_5,borrow);
	borrow  = _mm512_srli_epi64(out_5,52)&un;
	out_5 = _mm512_and_si512(out_5,mask52);

	borrow = _mm512_add_epi64(b512_6,borrow);
	__m512i out_6 = _mm512_sub_epi64(a512_6,borrow);
	borrow  = _mm512_srli_epi64(out_6,52)&un;
	out_6 = _mm512_and_si512(out_6,mask52);

	borrow = _mm512_add_epi64(b512_7,borrow);
	__m512i out_7 = _mm512_sub_epi64(a512_7,borrow);
	borrow  = _mm512_srli_epi64(out_7,52)&un;
	out_7 = _mm512_and_si512(out_7,mask52);

	borrow = _mm512_add_epi64(b512_8,borrow);
	__m512i out_8 = _mm512_sub_epi64(a512_8,borrow);
	borrow  = _mm512_srli_epi64(out_8,52)&un;
	out_8 = _mm512_and_si512(out_8,mask52);

	borrow = _mm512_add_epi64(b512_9,borrow);
	__m512i out_9 = _mm512_sub_epi64(a512_9,borrow);
	borrow  = _mm512_srli_epi64(out_9,52)&un;
	out_9 = _mm512_and_si512(out_9,mask52);

	borrow = _mm512_add_epi64(b512_10,borrow);
	__m512i out_10 = _mm512_sub_epi64(a512_10,borrow);
	borrow  = _mm512_srli_epi64(out_10,52)&un;
	out_10 = _mm512_and_si512(out_10,mask52);

	borrow = _mm512_add_epi64(b512_11,borrow);
	__m512i out_11 = _mm512_sub_epi64(a512_11,borrow);
	borrow  = _mm512_srli_epi64(out_11,52)&un;
	out_11 = _mm512_and_si512(out_11,mask52);

	borrow = _mm512_add_epi64(b512_12,borrow);
	__m512i out_12 = _mm512_sub_epi64(a512_12,borrow);
	borrow  = _mm512_srli_epi64(out_12,52)&un;
	out_12 = _mm512_and_si512(out_12,mask52);

	borrow = _mm512_add_epi64(b512_13,borrow);
	__m512i out_13 = _mm512_sub_epi64(a512_13,borrow);
	borrow  = _mm512_srli_epi64(out_13,52)&un;
	out_13 = _mm512_and_si512(out_13,mask52);

	borrow = _mm512_add_epi64(b512_14,borrow);
	__m512i out_14 = _mm512_sub_epi64(a512_14,borrow);
	borrow  = _mm512_srli_epi64(out_14,52)&un;
	out_14 = _mm512_and_si512(out_14,mask52);

	borrow = _mm512_add_epi64(b512_15,borrow);
	__m512i out_15 = _mm512_sub_epi64(a512_15,borrow);
	borrow  = _mm512_srli_epi64(out_15,52)&un;
	out_15 = _mm512_and_si512(out_15,mask52);

	borrow = _mm512_add_epi64(b512_16,borrow);
	__m512i out_16 = _mm512_sub_epi64(a512_16,borrow);
	borrow  = _mm512_srli_epi64(out_16,52)&un;
	out_16 = _mm512_and_si512(out_16,mask52);

	borrow = _mm512_add_epi64(b512_17,borrow);
	__m512i out_17 = _mm512_sub_epi64(a512_17,borrow);
	borrow  = _mm512_srli_epi64(out_17,52)&un;
	out_17 = _mm512_and_si512(out_17,mask52);

	borrow = _mm512_add_epi64(b512_18,borrow);
	__m512i out_18 = _mm512_sub_epi64(a512_18,borrow);
	borrow  = _mm512_srli_epi64(out_18,52)&un;
	out_18 = _mm512_and_si512(out_18,mask52);

	borrow = _mm512_add_epi64(b512_19,borrow);
	__m512i out_19 = _mm512_sub_epi64(a512_19,borrow);
	borrow  = _mm512_srli_epi64(out_19,51)&un;
	out_19 = _mm512_and_si512(out_19,mask51);// radix 2**1039

	borrow = _mm512_add_epi64(b512_20,borrow);
	__m512i out_20 = _mm512_sub_epi64(a512_20,borrow);
	borrow  = _mm512_srli_epi64(out_20,52)&un;
	out_20 = _mm512_and_si512(out_20,mask52);

	borrow = _mm512_add_epi64(b512_21,borrow);
	__m512i out_21 = _mm512_sub_epi64(a512_21,borrow);
	borrow  = _mm512_srli_epi64(out_21,52)&un;
	out_21 = _mm512_and_si512(out_21,mask52);

	borrow = _mm512_add_epi64(b512_22,borrow);
	__m512i out_22 = _mm512_sub_epi64(a512_22,borrow);
	borrow  = _mm512_srli_epi64(out_22,52)&un;
	out_22 = _mm512_and_si512(out_22,mask52);

	borrow = _mm512_add_epi64(b512_23,borrow);
	__m512i out_23 = _mm512_sub_epi64(a512_23,borrow);
	borrow  = _mm512_srli_epi64(out_23,52)&un;
	out_23 = _mm512_and_si512(out_23,mask52);

	borrow = _mm512_add_epi64(b512_24,borrow);
	__m512i out_24 = _mm512_sub_epi64(a512_24,borrow);
	borrow  = _mm512_srli_epi64(out_24,52)&un;
	out_24 = _mm512_and_si512(out_24,mask52);

	borrow = _mm512_add_epi64(b512_25,borrow);
	__m512i out_25 = _mm512_sub_epi64(a512_25,borrow);
	borrow  = _mm512_srli_epi64(out_25,52)&un;
	out_25 = _mm512_and_si512(out_25,mask52);

	borrow = _mm512_add_epi64(b512_26,borrow);
	__m512i out_26 = _mm512_sub_epi64(a512_26,borrow);
	borrow  = _mm512_srli_epi64(out_26,52)&un;
	out_26 = _mm512_and_si512(out_26,mask52);

	borrow = _mm512_add_epi64(b512_27,borrow);
	__m512i out_27 = _mm512_sub_epi64(a512_27,borrow);
	borrow  = _mm512_srli_epi64(out_27,52)&un;
	out_27 = _mm512_and_si512(out_27,mask52);

	borrow = _mm512_add_epi64(b512_28,borrow);
	__m512i out_28 = _mm512_sub_epi64(a512_28,borrow);
	borrow  = _mm512_srli_epi64(out_28,52)&un;
	out_28 = _mm512_and_si512(out_28,mask52);

	borrow = _mm512_add_epi64(b512_29,borrow);
	__m512i out_29 = _mm512_sub_epi64(a512_29,borrow);
	borrow  = _mm512_srli_epi64(out_29,52)&un;
	out_29 = _mm512_and_si512(out_29,mask52);

	borrow = _mm512_add_epi64(b512_30,borrow);
	__m512i out_30 = _mm512_sub_epi64(a512_30,borrow);
	borrow  = _mm512_srli_epi64(out_30,52)&un;
	out_30 = _mm512_and_si512(out_30,mask52);

	borrow = _mm512_add_epi64(b512_31,borrow);
	__m512i out_31 = _mm512_sub_epi64(a512_31,borrow);
	borrow  = _mm512_srli_epi64(out_31,52)&un;
	out_31 = _mm512_and_si512(out_31,mask52);

	borrow = _mm512_add_epi64(b512_32,borrow);
	__m512i out_32 = _mm512_sub_epi64(a512_32,borrow);
	borrow  = _mm512_srli_epi64(out_32,52)&un;
	out_32 = _mm512_and_si512(out_32,mask52);

	borrow = _mm512_add_epi64(b512_33,borrow);
	__m512i out_33 = _mm512_sub_epi64(a512_33,borrow);
	borrow  = _mm512_srli_epi64(out_33,52)&un;
	out_33 = _mm512_and_si512(out_33,mask52);

	borrow = _mm512_add_epi64(b512_34,borrow);
	__m512i out_34 = _mm512_sub_epi64(a512_34,borrow);
	borrow  = _mm512_srli_epi64(out_34,52)&un;
	out_34 = _mm512_and_si512(out_34,mask52);

	borrow = _mm512_add_epi64(b512_35,borrow);
	__m512i out_35 = _mm512_sub_epi64(a512_35,borrow);
	borrow  = _mm512_srli_epi64(out_35,52)&un;
	out_35 = _mm512_and_si512(out_35,mask52);

	borrow = _mm512_add_epi64(b512_36,borrow);
	__m512i out_36 = _mm512_sub_epi64(a512_36,borrow);
	borrow  = _mm512_srli_epi64(out_36,52)&un;
	out_36 = _mm512_and_si512(out_36,mask52);

	borrow = _mm512_add_epi64(b512_37,borrow);
	__m512i out_37 = _mm512_sub_epi64(a512_37,borrow);
	borrow  = _mm512_srli_epi64(out_37,52)&un;
	out_37 = _mm512_and_si512(out_37,mask52);

	borrow = _mm512_add_epi64(b512_38,borrow);
	__m512i out_38 = _mm512_sub_epi64(a512_38,borrow);
	borrow  = _mm512_srli_epi64(out_38,52)&un;
	out_38 = _mm512_and_si512(out_38,mask52);

	borrow = _mm512_add_epi64(b512_39,borrow);
	__m512i out_39 = _mm512_sub_epi64(a512_39,borrow);
	borrow = _mm512_srli_epi64(out_39,49)&un;
	out_39 = _mm512_and_si512(out_39,mask50);// radix 2**2077

	borrow = _mm512_add_epi64(b512_40,borrow);
	__m512i out_40 = _mm512_sub_epi64(a512_40,borrow);
	borrow  = _mm512_srli_epi64(out_40,52)&un;
	out_40 = _mm512_and_si512(out_40,mask52);

	borrow = _mm512_add_epi64(b512_41,borrow);
	__m512i out_41 = _mm512_sub_epi64(a512_41,borrow);
	borrow  = _mm512_srli_epi64(out_41,52)&un;
	out_41 = _mm512_and_si512(out_41,mask52);

	borrow = _mm512_add_epi64(b512_42,borrow);
	__m512i out_42 = _mm512_sub_epi64(a512_42,borrow);
	borrow  = _mm512_srli_epi64(out_42,52)&un;
	out_42 = _mm512_and_si512(out_42,mask52);

	borrow = _mm512_add_epi64(b512_43,borrow);
	__m512i out_43 = _mm512_sub_epi64(a512_43,borrow);
	borrow  = _mm512_srli_epi64(out_43,52)&un;
	out_43 = _mm512_and_si512(out_43,mask52);

	borrow = _mm512_add_epi64(b512_44,borrow);
	__m512i out_44 = _mm512_sub_epi64(a512_44,borrow);
	borrow  = _mm512_srli_epi64(out_44,52)&un;
	out_44 = _mm512_and_si512(out_44,mask52);

	borrow = _mm512_add_epi64(b512_45,borrow);
	__m512i out_45 = _mm512_sub_epi64(a512_45,borrow);
	borrow  = _mm512_srli_epi64(out_45,52)&un;
	out_45 = _mm512_and_si512(out_45,mask52);

	borrow = _mm512_add_epi64(b512_46,borrow);
	__m512i out_46 = _mm512_sub_epi64(a512_46,borrow);
	borrow  = _mm512_srli_epi64(out_46,52)&un;
	out_46 = _mm512_and_si512(out_46,mask52);

	borrow = _mm512_add_epi64(b512_47,borrow);
	__m512i out_47 = _mm512_sub_epi64(a512_47,borrow);
	borrow  = _mm512_srli_epi64(out_47,52)&un;
	out_47 = _mm512_and_si512(out_47,mask52);

	borrow = _mm512_add_epi64(b512_48,borrow);
	__m512i out_48 = _mm512_sub_epi64(a512_48,borrow);
	borrow  = _mm512_srli_epi64(out_48,52)&un;
	out_48 = _mm512_and_si512(out_48,mask52);

	borrow = _mm512_add_epi64(b512_49,borrow);
	__m512i out_49 = _mm512_sub_epi64(a512_49,borrow);
	borrow  = _mm512_srli_epi64(out_49,52)&un;
	out_49 = _mm512_and_si512(out_49,mask52);

	borrow = _mm512_add_epi64(b512_50,borrow);
	__m512i out_50 = _mm512_sub_epi64(a512_50,borrow);
	borrow  = _mm512_srli_epi64(out_50,52)&un;
	out_50 = _mm512_and_si512(out_50,mask52);

	borrow = _mm512_add_epi64(b512_51,borrow);
	__m512i out_51 = _mm512_sub_epi64(a512_51,borrow);
	borrow  = _mm512_srli_epi64(out_51,52)&un;
	out_51 = _mm512_and_si512(out_51,mask52);

	borrow = _mm512_add_epi64(b512_52,borrow);
	__m512i out_52 = _mm512_sub_epi64(a512_52,borrow);
	borrow  = _mm512_srli_epi64(out_52,52)&un;
	out_52 = _mm512_and_si512(out_52,mask52);

	borrow = _mm512_add_epi64(b512_53,borrow);
	__m512i out_53 = _mm512_sub_epi64(a512_53,borrow);
	borrow  = _mm512_srli_epi64(out_53,52)&un;
	out_53 = _mm512_and_si512(out_53,mask52);

	borrow = _mm512_add_epi64(b512_54,borrow);
	__m512i out_54 = _mm512_sub_epi64(a512_54,borrow);
	borrow  = _mm512_srli_epi64(out_54,52)&un;
	out_54 = _mm512_and_si512(out_54,mask52);

	borrow = _mm512_add_epi64(b512_55,borrow);
	__m512i out_55 = _mm512_sub_epi64(a512_55,borrow);
	borrow  = _mm512_srli_epi64(out_55,52)&un;
	out_55 = _mm512_and_si512(out_55,mask52);

	borrow = _mm512_add_epi64(b512_56,borrow);
	__m512i out_56 = _mm512_sub_epi64(a512_56,borrow);
	borrow  = _mm512_srli_epi64(out_56,52)&un;
	out_56 = _mm512_and_si512(out_56,mask52);

	borrow = _mm512_add_epi64(b512_57,borrow);
	__m512i out_57 = _mm512_sub_epi64(a512_57,borrow);
	borrow  = _mm512_srli_epi64(out_57,52)&un;
	out_57 = _mm512_and_si512(out_57,mask52);

	borrow = _mm512_add_epi64(b512_58,borrow);
	__m512i out_58 = _mm512_sub_epi64(a512_58,borrow);
	borrow  = _mm512_srli_epi64(out_58,52)&un;
	out_58 = _mm512_and_si512(out_58,mask52);

	borrow = _mm512_add_epi64(b512_59,borrow);
	__m512i out_59 = _mm512_sub_epi64(a512_59,borrow);
	borrow  = _mm512_srli_epi64(out_59,51)&un;
	out_59 = _mm512_and_si512(out_59,mask51);// radix 2**1039

	borrow = _mm512_add_epi64(b512_60,borrow);
	__m512i out_60 = _mm512_sub_epi64(a512_60,borrow);
	borrow  = _mm512_srli_epi64(out_60,52)&un;
	out_60 = _mm512_and_si512(out_60,mask52);

	borrow = _mm512_add_epi64(b512_61,borrow);
	__m512i out_61 = _mm512_sub_epi64(a512_61,borrow);
	borrow  = _mm512_srli_epi64(out_61,52)&un;
	out_61 = _mm512_and_si512(out_61,mask52);

	borrow = _mm512_add_epi64(b512_62,borrow);
	__m512i out_62 = _mm512_sub_epi64(a512_62,borrow);
	borrow  = _mm512_srli_epi64(out_62,52)&un;
	out_62 = _mm512_and_si512(out_62,mask52);

	borrow = _mm512_add_epi64(b512_63,borrow);
	__m512i out_63 = _mm512_sub_epi64(a512_63,borrow);
	borrow  = _mm512_srli_epi64(out_63,52)&un;
	out_63 = _mm512_and_si512(out_63,mask52);

	borrow = _mm512_add_epi64(b512_64,borrow);
	__m512i out_64 = _mm512_sub_epi64(a512_64,borrow);
	borrow  = _mm512_srli_epi64(out_64,52)&un;
	out_64 = _mm512_and_si512(out_64,mask52);

	borrow = _mm512_add_epi64(b512_65,borrow);
	__m512i out_65 = _mm512_sub_epi64(a512_65,borrow);
	borrow  = _mm512_srli_epi64(out_65,52)&un;
	out_65 = _mm512_and_si512(out_65,mask52);

	borrow = _mm512_add_epi64(b512_66,borrow);
	__m512i out_66 = _mm512_sub_epi64(a512_66,borrow);
	borrow  = _mm512_srli_epi64(out_66,52)&un;
	out_66 = _mm512_and_si512(out_66,mask52);

	borrow = _mm512_add_epi64(b512_67,borrow);
	__m512i out_67 = _mm512_sub_epi64(a512_67,borrow);
	borrow  = _mm512_srli_epi64(out_67,52)&un;
	out_67 = _mm512_and_si512(out_67,mask52);

	borrow = _mm512_add_epi64(b512_68,borrow);
	__m512i out_68 = _mm512_sub_epi64(a512_68,borrow);
	borrow  = _mm512_srli_epi64(out_68,52)&un;
	out_68 = _mm512_and_si512(out_68,mask52);

	borrow = _mm512_add_epi64(b512_69,borrow);
	__m512i out_69 = _mm512_sub_epi64(a512_69,borrow);
	borrow  = _mm512_srli_epi64(out_69,52)&un;
	out_69 = _mm512_and_si512(out_69,mask52);

	borrow = _mm512_add_epi64(b512_70,borrow);
	__m512i out_70 = _mm512_sub_epi64(a512_70,borrow);
	borrow  = _mm512_srli_epi64(out_70,52)&un;
	out_70 = _mm512_and_si512(out_70,mask52);

	borrow = _mm512_add_epi64(b512_71,borrow);
	__m512i out_71 = _mm512_sub_epi64(a512_71,borrow);
	borrow  = _mm512_srli_epi64(out_71,52)&un;
	out_71 = _mm512_and_si512(out_71,mask52);

	borrow = _mm512_add_epi64(b512_72,borrow);
	__m512i out_72 = _mm512_sub_epi64(a512_72,borrow);
	borrow  = _mm512_srli_epi64(out_72,52)&un;
	out_72 = _mm512_and_si512(out_72,mask52);

	borrow = _mm512_add_epi64(b512_73,borrow);
	__m512i out_73 = _mm512_sub_epi64(a512_73,borrow);
	borrow  = _mm512_srli_epi64(out_73,52)&un;
	out_73 = _mm512_and_si512(out_73,mask52);

	borrow = _mm512_add_epi64(b512_74,borrow);
	__m512i out_74 = _mm512_sub_epi64(a512_74,borrow);
	borrow  = _mm512_srli_epi64(out_74,52)&un;
	out_74 = _mm512_and_si512(out_74,mask52);

	borrow = _mm512_add_epi64(b512_75,borrow);
	__m512i out_75 = _mm512_sub_epi64(a512_75,borrow);
	borrow  = _mm512_srli_epi64(out_75,52)&un;
	out_75 = _mm512_and_si512(out_75,mask52);

	borrow = _mm512_add_epi64(b512_76,borrow);
	__m512i out_76 = _mm512_sub_epi64(a512_76,borrow);
	borrow  = _mm512_srli_epi64(out_76,52)&un;
	out_76 = _mm512_and_si512(out_76,mask52);

	borrow = _mm512_add_epi64(b512_77,borrow);
	__m512i out_77 = _mm512_sub_epi64(a512_77,borrow);
	borrow  = _mm512_srli_epi64(out_77,52)&un;
	out_77 = _mm512_and_si512(out_77,mask52);

	borrow = _mm512_add_epi64(b512_78,borrow);
	__m512i out_78 = _mm512_sub_epi64(a512_78,borrow);
	borrow  = _mm512_srli_epi64(out_78,52)&un;
	out_78 = _mm512_and_si512(out_78,mask52);

	borrow = _mm512_add_epi64(b512_79,borrow);
	__m512i out_79 = _mm512_sub_epi64(a512_79,borrow);
	borrow = _mm512_srli_epi64(out_79,49)&un;
	out_79 = _mm512_and_si512(out_79,mask50);// radix 2**2077


			
	_mm512_store_epi64(out+0,out_0);	_mm512_store_epi64(out+1,out_1);
	_mm512_store_epi64(out+2,out_2);	_mm512_store_epi64(out+3,out_3);
	_mm512_store_epi64(out+4,out_4);	_mm512_store_epi64(out+5,out_5);
	_mm512_store_epi64(out+6,out_6);	_mm512_store_epi64(out+7,out_7);
	_mm512_store_epi64(out+8,out_8);	_mm512_store_epi64(out+9,out_9);
	_mm512_store_epi64(out+10,out_10);	_mm512_store_epi64(out+11,out_11);
	_mm512_store_epi64(out+12,out_12);	_mm512_store_epi64(out+13,out_13);
	_mm512_store_epi64(out+14,out_14);	_mm512_store_epi64(out+15,out_15);
	_mm512_store_epi64(out+16,out_16);	_mm512_store_epi64(out+17,out_17);
	_mm512_store_epi64(out+18,out_18);	_mm512_store_epi64(out+19,out_19);
	_mm512_store_epi64(out+20,out_20);	_mm512_store_epi64(out+21,out_21);
	_mm512_store_epi64(out+22,out_22);	_mm512_store_epi64(out+23,out_23);
	_mm512_store_epi64(out+24,out_24);	_mm512_store_epi64(out+25,out_25);
	_mm512_store_epi64(out+26,out_26);	_mm512_store_epi64(out+27,out_27);
	_mm512_store_epi64(out+28,out_28);	_mm512_store_epi64(out+29,out_29);
	_mm512_store_epi64(out+30,out_30);	_mm512_store_epi64(out+31,out_31);
	_mm512_store_epi64(out+32,out_32);	_mm512_store_epi64(out+33,out_33);
	_mm512_store_epi64(out+34,out_34);	_mm512_store_epi64(out+35,out_35);
	_mm512_store_epi64(out+36,out_36);	_mm512_store_epi64(out+37,out_37);
	_mm512_store_epi64(out+38,out_38);	_mm512_store_epi64(out+39,out_39);
	_mm512_store_epi64(out+40,out_40);	_mm512_store_epi64(out+41,out_41);
	_mm512_store_epi64(out+42,out_42);	_mm512_store_epi64(out+43,out_43);
	_mm512_store_epi64(out+44,out_44);	_mm512_store_epi64(out+45,out_45);
	_mm512_store_epi64(out+46,out_46);	_mm512_store_epi64(out+47,out_47);
	_mm512_store_epi64(out+48,out_48);	_mm512_store_epi64(out+49,out_49);
	_mm512_store_epi64(out+50,out_50);	_mm512_store_epi64(out+51,out_51);
	_mm512_store_epi64(out+52,out_52);	_mm512_store_epi64(out+53,out_53);
	_mm512_store_epi64(out+54,out_54);	_mm512_store_epi64(out+55,out_55);
	_mm512_store_epi64(out+56,out_56);	_mm512_store_epi64(out+57,out_57);
	_mm512_store_epi64(out+58,out_58);	_mm512_store_epi64(out+59,out_59);
	_mm512_store_epi64(out+60,out_60);	_mm512_store_epi64(out+61,out_61);
	_mm512_store_epi64(out+62,out_62);	_mm512_store_epi64(out+63,out_63);
	_mm512_store_epi64(out+64,out_64);	_mm512_store_epi64(out+65,out_65);
	_mm512_store_epi64(out+66,out_66);	_mm512_store_epi64(out+67,out_67);
	_mm512_store_epi64(out+68,out_68);	_mm512_store_epi64(out+69,out_69);
	_mm512_store_epi64(out+70,out_70);	_mm512_store_epi64(out+71,out_71);
	_mm512_store_epi64(out+72,out_72);	_mm512_store_epi64(out+73,out_73);
	_mm512_store_epi64(out+74,out_74);	_mm512_store_epi64(out+75,out_75);
	_mm512_store_epi64(out+76,out_76);	_mm512_store_epi64(out+77,out_77);
	_mm512_store_epi64(out+78,out_78);	_mm512_store_epi64(out+79,out_79);
	
	
	return borrow;
	
}



/* Karatsuba multiplication */

static inline void force_inline mul512_8_4154KK(__m512i out[160], __m512i a512[80], __m512i b512[80])
{

	__m512i D0[80], D1[80], D2[80], alpah[40], blpbh[40], alpahbis[40], blpbhbis[40];


	// al*bl, radix 2^1039 result
	
	mul512_8_2078K(D0, a512, b512);

	

	// ah*bh, radix 2^1039 result
	
	mul512_8_2078K(D2, a512+40, b512+40);




	// ah*bh, radix 2^1039 result
	
	add512_8_2078K(alpah, a512, a512+40);
	
	add512_8_2078K(blpbh, b512, b512+40);
	
	mul512_8_2078K(D1, alpah, blpbh);
	
	/*displayVect512_NB(a512,"a512",80);
	displayVect512_NB(b512,"b512",80);
	
	
	displayVect512_NB(alpah,"alpah",40);
	displayVect512_NB(blpbh,"blpbh",40);
	

	displayVect512_NB_COEFF(D1,"D1");
	
	//getchar();//*/
	
	/*unsigned long int a64[8][NB_COEFF64_SIZE_K], b64[8][NB_COEFF64_SIZE_K], res64[8][NB_COEFF64_SIZE_K*2], res_gmp[NB_COEFF64_SIZE_K*2];
	size_t countp;
	
	int counter=0,flag=0;
	
	fcontract_8_512_2077K(a64,alpah);
	fcontract_8_512_2077K(b64,blpbh);
	
	fexpand_8_512_2077K(alpahbis,a64);
	
	fexpand_8_512_2077K(blpbhbis,b64);
	
	displayVect512_NB(alpah,"alpah   ",40);
	displayVect512_NB(alpahbis,"alpahbis",40);
	getchar();
	displayVect512_NB(blpbh,"blpbh   ",40);
	displayVect512_NB(blpbhbis,"blpbhbis",40);
	//getchar();//*/
	
	
	
	/*mpz_t A, B, C;// UPB is used as upper bound
	
	mpz_inits (A, B, C, NULL);
	//conversion_8_r2077K(D1,D1);
	
	fcontract_8_512_2077K_res( res64, D1);
	for(int i=0;i<8;i++)
	{

		mpz_import(A, NB_COEFF64_SIZE_K, -1, sizeof(b64[0][0]) ,0,0, a64[i]);

		mpz_import(B, NB_COEFF64_SIZE_K, -1, sizeof(b64[0][0]) ,0,0, b64[i]);
		
		gmp_printf("A  : 0x%ZX\n\n\n", A);

		displayVect(a64[i],"a64",33);
		gmp_printf("B  : 0x%ZX\n\n\n", B);
		displayVect(b64[i],"b64",33);
		
		
	
	
		mpz_mul(C,A,B);
		mpz_export(res_gmp, &countp, -1, sizeof(b64[0][0]) ,0,0, C);
		displayVect(res_gmp, "res_gmp     ",NB_COEFF64_SIZE_K*2);
		displayVect(res64[i],"res64[i]    ",NB_COEFF64_SIZE_K*2);
		
		
		printf("xor = ");
		for(int j=0;j<NB_COEFF64_SIZE_K*2;j++){
			printf("%16.16lX ",res64[i][NB_COEFF64_SIZE_K*2-1-j]^res_gmp[NB_COEFF64_SIZE_K*2-1-j]);
		}
		printf("\n");

	//}
	//printf("\n");
	
	//for(int i=0;i<8;i++){//
		for(int j=0;j<NB_COEFF64_SIZE_K*2;j++)
			if(res64[i][j]^res_gmp[j]) flag++;
		flag?counter++,flag=0:counter,flag=0;
		printf("\n");
	}
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory alpah*blbph !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;

	//}
	
	// conversion in radix 2^2077 conversion
	
	//displayVect512_NB_COEFF(D0,"D0");
	/*displayVect512_NB_COEFF(D0,"D0");

	getchar();//*/
	
	
	conversion_8_r2077K(D0,D0);
	conversion_8_r2077K(D1,D1);
	conversion_8_r2077K(D2,D2);//*/
	
	
	//__m512i c = 
	/*displayVect512_NB(D1,"D1",40);
	add512_8_2078K(D1, D1, D0+40);
	//D1[40] = _mm512_add_epi64(D1[40],c);
	displayVect512_NB(D0+40,"D0+40",40);
	displayVect512_NB(D1,"D1",40);
	
	// 	retenue
	__m512i c = _mm512_srli_epi64(D1[39],49);
	displayVect512(&c,"c");
	
	//getchar();
	
	D1[39] = _mm512_and_si512(D1[39],mask50);
	displayVect512_NB(D1,"D1",40);
	
	
	D1[40] = _mm512_add_epi64(D1[40],c);
	
	
	add512_8_2078K(D1+40, D1+40, D2);
	c = _mm512_srli_epi64(D1[79],49);
	D1[79] = _mm512_and_si512(D1[79],mask50);//*/
	
	
	__m512i D0_0 = _mm512_load_epi64(D0), D2_0 = _mm512_load_epi64(D2);
	__m512i D0_1 = _mm512_load_epi64(D0+1), D2_1 = _mm512_load_epi64(D2+1);
	__m512i D0_2 = _mm512_load_epi64(D0+2), D2_2 = _mm512_load_epi64(D2+2);
	__m512i D0_3 = _mm512_load_epi64(D0+3), D2_3 = _mm512_load_epi64(D2+3);
	__m512i D0_4 = _mm512_load_epi64(D0+4), D2_4 = _mm512_load_epi64(D2+4);
	__m512i D0_5 = _mm512_load_epi64(D0+5), D2_5 = _mm512_load_epi64(D2+5);
	__m512i D0_6 = _mm512_load_epi64(D0+6), D2_6 = _mm512_load_epi64(D2+6);
	__m512i D0_7 = _mm512_load_epi64(D0+7), D2_7 = _mm512_load_epi64(D2+7);
	__m512i D0_8 = _mm512_load_epi64(D0+8), D2_8 = _mm512_load_epi64(D2+8);
	__m512i D0_9 = _mm512_load_epi64(D0+9), D2_9 = _mm512_load_epi64(D2+9);
	__m512i D0_10 = _mm512_load_epi64(D0+10), D2_10 = _mm512_load_epi64(D2+10);
	__m512i D0_11 = _mm512_load_epi64(D0+11), D2_11 = _mm512_load_epi64(D2+11);
	__m512i D0_12 = _mm512_load_epi64(D0+12), D2_12 = _mm512_load_epi64(D2+12);
	__m512i D0_13 = _mm512_load_epi64(D0+13), D2_13 = _mm512_load_epi64(D2+13);
	__m512i D0_14 = _mm512_load_epi64(D0+14), D2_14 = _mm512_load_epi64(D2+14);
	__m512i D0_15 = _mm512_load_epi64(D0+15), D2_15 = _mm512_load_epi64(D2+15);
	__m512i D0_16 = _mm512_load_epi64(D0+16), D2_16 = _mm512_load_epi64(D2+16);
	__m512i D0_17 = _mm512_load_epi64(D0+17), D2_17 = _mm512_load_epi64(D2+17);
	__m512i D0_18 = _mm512_load_epi64(D0+18), D2_18 = _mm512_load_epi64(D2+18);
	__m512i D0_19 = _mm512_load_epi64(D0+19), D2_19 = _mm512_load_epi64(D2+19);
	__m512i D0_20 = _mm512_load_epi64(D0+20), D2_20 = _mm512_load_epi64(D2+20);
	__m512i D0_21 = _mm512_load_epi64(D0+21), D2_21 = _mm512_load_epi64(D2+21);
	__m512i D0_22 = _mm512_load_epi64(D0+22), D2_22 = _mm512_load_epi64(D2+22);
	__m512i D0_23 = _mm512_load_epi64(D0+23), D2_23 = _mm512_load_epi64(D2+23);
	__m512i D0_24 = _mm512_load_epi64(D0+24), D2_24 = _mm512_load_epi64(D2+24);
	__m512i D0_25 = _mm512_load_epi64(D0+25), D2_25 = _mm512_load_epi64(D2+25);
	__m512i D0_26 = _mm512_load_epi64(D0+26), D2_26 = _mm512_load_epi64(D2+26);
	__m512i D0_27 = _mm512_load_epi64(D0+27), D2_27 = _mm512_load_epi64(D2+27);
	__m512i D0_28 = _mm512_load_epi64(D0+28), D2_28 = _mm512_load_epi64(D2+28);
	__m512i D0_29 = _mm512_load_epi64(D0+29), D2_29 = _mm512_load_epi64(D2+29);
	__m512i D0_30 = _mm512_load_epi64(D0+30), D2_30 = _mm512_load_epi64(D2+30);
	__m512i D0_31 = _mm512_load_epi64(D0+31), D2_31 = _mm512_load_epi64(D2+31);
	__m512i D0_32 = _mm512_load_epi64(D0+32), D2_32 = _mm512_load_epi64(D2+32);
	__m512i D0_33 = _mm512_load_epi64(D0+33), D2_33 = _mm512_load_epi64(D2+33);
	__m512i D0_34 = _mm512_load_epi64(D0+34), D2_34 = _mm512_load_epi64(D2+34);
	__m512i D0_35 = _mm512_load_epi64(D0+35), D2_35 = _mm512_load_epi64(D2+35);
	__m512i D0_36 = _mm512_load_epi64(D0+36), D2_36 = _mm512_load_epi64(D2+36);
	__m512i D0_37 = _mm512_load_epi64(D0+37), D2_37 = _mm512_load_epi64(D2+37);
	__m512i D0_38 = _mm512_load_epi64(D0+38), D2_38 = _mm512_load_epi64(D2+38);
	__m512i D0_39 = _mm512_load_epi64(D0+39), D2_39 = _mm512_load_epi64(D2+39);
	
	
	__m512i D0_40 = _mm512_load_epi64(D0+40), D2_40 = _mm512_load_epi64(D2+40);
	__m512i D0_41 = _mm512_load_epi64(D0+41), D2_41 = _mm512_load_epi64(D2+41);
	__m512i D0_42 = _mm512_load_epi64(D0+42), D2_42 = _mm512_load_epi64(D2+42);
	__m512i D0_43 = _mm512_load_epi64(D0+43), D2_43 = _mm512_load_epi64(D2+43);
	__m512i D0_44 = _mm512_load_epi64(D0+44), D2_44 = _mm512_load_epi64(D2+44);
	__m512i D0_45 = _mm512_load_epi64(D0+45), D2_45 = _mm512_load_epi64(D2+45);
	__m512i D0_46 = _mm512_load_epi64(D0+46), D2_46 = _mm512_load_epi64(D2+46);
	__m512i D0_47 = _mm512_load_epi64(D0+47), D2_47 = _mm512_load_epi64(D2+47);
	__m512i D0_48 = _mm512_load_epi64(D0+48), D2_48 = _mm512_load_epi64(D2+48);
	__m512i D0_49 = _mm512_load_epi64(D0+49), D2_49 = _mm512_load_epi64(D2+49);
	__m512i D0_50 = _mm512_load_epi64(D0+50), D2_50 = _mm512_load_epi64(D2+50);
	__m512i D0_51 = _mm512_load_epi64(D0+51), D2_51 = _mm512_load_epi64(D2+51);
	__m512i D0_52 = _mm512_load_epi64(D0+52), D2_52 = _mm512_load_epi64(D2+52);
	__m512i D0_53 = _mm512_load_epi64(D0+53), D2_53 = _mm512_load_epi64(D2+53);
	__m512i D0_54 = _mm512_load_epi64(D0+54), D2_54 = _mm512_load_epi64(D2+54);
	__m512i D0_55 = _mm512_load_epi64(D0+55), D2_55 = _mm512_load_epi64(D2+55);
	__m512i D0_56 = _mm512_load_epi64(D0+56), D2_56 = _mm512_load_epi64(D2+56);
	__m512i D0_57 = _mm512_load_epi64(D0+57), D2_57 = _mm512_load_epi64(D2+57);
	__m512i D0_58 = _mm512_load_epi64(D0+58), D2_58 = _mm512_load_epi64(D2+58);
	__m512i D0_59 = _mm512_load_epi64(D0+59), D2_59 = _mm512_load_epi64(D2+59);
	__m512i D0_60 = _mm512_load_epi64(D0+60), D2_60 = _mm512_load_epi64(D2+60);
	__m512i D0_61 = _mm512_load_epi64(D0+61), D2_61 = _mm512_load_epi64(D2+61);
	__m512i D0_62 = _mm512_load_epi64(D0+62), D2_62 = _mm512_load_epi64(D2+62);
	__m512i D0_63 = _mm512_load_epi64(D0+63), D2_63 = _mm512_load_epi64(D2+63);
	__m512i D0_64 = _mm512_load_epi64(D0+64), D2_64 = _mm512_load_epi64(D2+64);
	__m512i D0_65 = _mm512_load_epi64(D0+65), D2_65 = _mm512_load_epi64(D2+65);
	__m512i D0_66 = _mm512_load_epi64(D0+66), D2_66 = _mm512_load_epi64(D2+66);
	__m512i D0_67 = _mm512_load_epi64(D0+67), D2_67 = _mm512_load_epi64(D2+67);
	__m512i D0_68 = _mm512_load_epi64(D0+68), D2_68 = _mm512_load_epi64(D2+68);
	__m512i D0_69 = _mm512_load_epi64(D0+69), D2_69 = _mm512_load_epi64(D2+69);
	__m512i D0_70 = _mm512_load_epi64(D0+70), D2_70 = _mm512_load_epi64(D2+70);
	__m512i D0_71 = _mm512_load_epi64(D0+71), D2_71 = _mm512_load_epi64(D2+71);
	__m512i D0_72 = _mm512_load_epi64(D0+72), D2_72 = _mm512_load_epi64(D2+72);
	__m512i D0_73 = _mm512_load_epi64(D0+73), D2_73 = _mm512_load_epi64(D2+73);
	__m512i D0_74 = _mm512_load_epi64(D0+74), D2_74 = _mm512_load_epi64(D2+74);
	__m512i D0_75 = _mm512_load_epi64(D0+75), D2_75 = _mm512_load_epi64(D2+75);
	__m512i D0_76 = _mm512_load_epi64(D0+76), D2_76 = _mm512_load_epi64(D2+76);
	__m512i D0_77 = _mm512_load_epi64(D0+77), D2_77 = _mm512_load_epi64(D2+77);
	__m512i D0_78 = _mm512_load_epi64(D0+78), D2_78 = _mm512_load_epi64(D2+78);
	__m512i D0_79 = _mm512_load_epi64(D0+79), D2_79 = _mm512_load_epi64(D2+79);
	
	/*
	//conversion D0 in radix 2^2077
	
	__m512i carry = D0_39>>49;	D0_40 = (D0_40<<1)+carry;
	D0_39 &= mask50;	carry = D0_40>>52;
	D0_41 = (D0_41<<1)+carry;	D0_40 &= mask52;
	carry = D0_41>>52;	D0_42 = (D0_42<<1)+carry;
	D0_41 &= mask52;	carry = D0_42>>52;
	D0_43 = (D0_43<<1)+carry;	D0_42 &= mask52;
	carry = D0_43>>52;	D0_44 = (D0_44<<1)+carry;
	D0_43 &= mask52;	carry = D0_44>>52;
	D0_45 = (D0_45<<1)+carry;	D0_44 &= mask52;
	carry = D0_45>>52;	D0_46 = (D0_46<<1)+carry;
	D0_45 &= mask52;	carry = D0_46>>52;
	D0_47 = (D0_47<<1)+carry;	D0_46 &= mask52;
	carry = D0_47>>52;	D0_48 = (D0_48<<1)+carry;
	D0_47 &= mask52;	carry = D0_48>>52;
	D0_49 = (D0_49<<1)+carry;	D0_48 &= mask52;
	carry = D0_49>>52;	D0_50 = (D0_50<<1)+carry;
	D0_49 &= mask52;	carry = D0_50>>52;
	D0_51 = (D0_51<<1)+carry;	D0_50 &= mask52;
	carry = D0_51>>52;	D0_52 = (D0_52<<1)+carry;
	D0_51 &= mask52;	carry = D0_52>>52;
	D0_53 = (D0_53<<1)+carry;	D0_52 &= mask52;
	carry = D0_53>>52;	D0_54 = (D0_54<<1)+carry;
	D0_53 &= mask52;	carry = D0_54>>52;
	D0_55 = (D0_55<<1)+carry;	D0_54 &= mask52;
	carry = D0_55>>52;	D0_56 = (D0_56<<1)+carry;
	D0_55 &= mask52;	carry = D0_56>>52;
	D0_57 = (D0_57<<1)+carry;
	D0_56 &= mask52;	carry = D0_57>>52;
	D0_58 = (D0_58<<1)+carry;	D0_57 &= mask52;
	carry = D0_58>>52;	D0_59 = (D0_59<<1)+carry;
	D0_58 &= mask52;	carry = D0_59>>52;
	D0_60 = (D0_60<<1)+carry;	D0_59 &= mask52;
	carry = D0_60>>52;	D0_61 = (D0_61<<1)+carry;
	D0_60 &= mask52;	carry = D0_61>>52;
	D0_62 = (D0_62<<1)+carry;	D0_61 &= mask52;
	carry = D0_62>>52;	D0_63 = (D0_63<<1)+carry;
	D0_62 &= mask52;	carry = D0_63>>52;
	D0_64 = (D0_64<<1)+carry;	D0_63 &= mask52;
	carry = D0_64>>52;	D0_65 = (D0_65<<1)+carry;
	D0_64 &= mask52;	carry = D0_65>>52;
	D0_66 = (D0_66<<1)+carry;	D0_65 &= mask52;
	carry = D0_66>>52;	D0_67 = (D0_67<<1)+carry;
	D0_66 &= mask52;	carry = D0_67>>52;
	D0_68 = (D0_68<<1)+carry;	D0_67 &= mask52;
	carry = D0_68>>52;	D0_69 = (D0_69<<1)+carry;
	D0_68 &= mask52;	carry = D0_69>>52;
	D0_70 = (D0_70<<1)+carry;	D0_69 &= mask52;
	carry = D0_70>>52;	D0_71 = (D0_71<<1)+carry;
	D0_70 &= mask52;	carry = D0_71>>52;
	D0_72 = (D0_72<<1)+carry;	D0_71 &= mask52;
	carry = D0_72>>52;	D0_73 = (D0_73<<1)+carry;
	D0_72 &= mask52;	carry = D0_73>>52;
	D0_74 = (D0_74<<1)+carry;	D0_73 &= mask52;
	carry = D0_74>>52;	D0_75 = (D0_75<<1)+carry;
	D0_74 &= mask52;	carry = D0_75>>52;
	D0_76 = (D0_76<<1)+carry;	D0_75 &= mask52;
	carry = D0_76>>52;	D0_77 = (D0_77<<1)+carry;
	D0_76 &= mask52;	carry = D0_77>>52;
	D0_78 = (D0_78<<1)+carry;	D0_77 &= mask52;
	carry = D0_78>>52;	D0_79 = (D0_79<<1)+carry;
	D0_78 &= mask52;
	

	//conversion D2 in radix 2^2077
	
	carry = D2_39>>49;	D2_40 = (D2_40<<1)+carry;
	D2_39 &= mask50;	carry = D2_40>>52;
	D2_41 = (D2_41<<1)+carry;	D2_40 &= mask52;
	carry = D2_41>>52;	D2_42 = (D2_42<<1)+carry;
	D2_41 &= mask52;	carry = D2_42>>52;
	D2_43 = (D2_43<<1)+carry;	D2_42 &= mask52;
	carry = D2_43>>52;	D2_44 = (D2_44<<1)+carry;
	D2_43 &= mask52;	carry = D2_44>>52;
	D2_45 = (D2_45<<1)+carry;	D2_44 &= mask52;
	carry = D2_45>>52;	D2_46 = (D2_46<<1)+carry;
	D2_45 &= mask52;	carry = D2_46>>52;
	D2_47 = (D2_47<<1)+carry;	D2_46 &= mask52;
	carry = D2_47>>52;	D2_48 = (D2_48<<1)+carry;
	D2_47 &= mask52;	carry = D2_48>>52;
	D2_49 = (D2_49<<1)+carry;	D2_48 &= mask52;
	carry = D2_49>>52;	D2_50 = (D2_50<<1)+carry;
	D2_49 &= mask52;	carry = D2_50>>52;
	D2_51 = (D2_51<<1)+carry;	D2_50 &= mask52;
	carry = D2_51>>52;	D2_52 = (D2_52<<1)+carry;
	D2_51 &= mask52;	carry = D2_52>>52;
	D2_53 = (D2_53<<1)+carry;	D2_52 &= mask52;
	carry = D2_53>>52;	D2_54 = (D2_54<<1)+carry;
	D2_53 &= mask52;	carry = D2_54>>52;
	D2_55 = (D2_55<<1)+carry;	D2_54 &= mask52;
	carry = D2_55>>52;	D2_56 = (D2_56<<1)+carry;
	D2_55 &= mask52;	carry = D2_56>>52;
	D2_57 = (D2_57<<1)+carry;
	D2_56 &= mask52;	carry = D2_57>>52;
	D2_58 = (D2_58<<1)+carry;	D2_57 &= mask52;
	carry = D2_58>>52;	D2_59 = (D2_59<<1)+carry;
	D2_58 &= mask52;	carry = D2_59>>52;
	D2_60 = (D2_60<<1)+carry;	D2_59 &= mask52;
	carry = D2_60>>52;	D2_61 = (D2_61<<1)+carry;
	D2_60 &= mask52;	carry = D2_61>>52;
	D2_62 = (D2_62<<1)+carry;	D2_61 &= mask52;
	carry = D2_62>>52;	D2_63 = (D2_63<<1)+carry;
	D2_62 &= mask52;	carry = D2_63>>52;
	D2_64 = (D2_64<<1)+carry;	D2_63 &= mask52;
	carry = D2_64>>52;	D2_65 = (D2_65<<1)+carry;
	D2_64 &= mask52;	carry = D2_65>>52;
	D2_66 = (D2_66<<1)+carry;	D2_65 &= mask52;
	carry = D2_66>>52;	D2_67 = (D2_67<<1)+carry;
	D2_66 &= mask52;	carry = D2_67>>52;
	D2_68 = (D2_68<<1)+carry;	D2_67 &= mask52;
	carry = D2_68>>52;	D2_69 = (D2_69<<1)+carry;
	D2_68 &= mask52;	carry = D2_69>>52;
	D2_70 = (D2_70<<1)+carry;	D2_69 &= mask52;
	carry = D2_70>>52;	D2_71 = (D2_71<<1)+carry;
	D2_70 &= mask52;	carry = D2_71>>52;
	D2_72 = (D2_72<<1)+carry;	D2_71 &= mask52;
	carry = D2_72>>52;	D2_73 = (D2_73<<1)+carry;
	D2_72 &= mask52;	carry = D2_73>>52;
	D2_74 = (D2_74<<1)+carry;	D2_73 &= mask52;
	carry = D2_74>>52;	D2_75 = (D2_75<<1)+carry;
	D2_74 &= mask52;	carry = D2_75>>52;
	D2_76 = (D2_76<<1)+carry;	D2_75 &= mask52;
	carry = D2_76>>52;	D2_77 = (D2_77<<1)+carry;
	D2_76 &= mask52;	carry = D2_77>>52;
	D2_78 = (D2_78<<1)+carry;	D2_77 &= mask52;
	carry = D2_78>>52;	D2_79 = (D2_79<<1)+carry;
	D2_78 &= mask52;//*/


	
	
	// Final Reconstruction
	

	// tmp = D0+D2, radix 2^2077/radix 2^1039
	/*__m512i tmp[160];
	
	add512_8_2078K(tmp, D0, D2);
	
	// Carry radix 2^2077
	tmp[40] = _mm512_srli_epi64(tmp[39],49);
	tmp[39] = _mm512_and_si512(tmp[39],mask50);
	
	addC512_8_2078K(tmp+40, D0+40, D2+40);//*/
	

	// D1 = D1 -tmp, radix 2^2079/radix 2^1039
	
	/*add512_8_2078K(D1, D1, D0+40);
	
	add512_8_2078K(D1+40, D1+40, D2);
	
	__m512i borrow = sub512_8_4154K(D1, D1, tmp);
	
	//last borrow
	
	__m512i borrow = _mm512_srli_epi64(tmp[79],49);
	tmp[79] = _mm512_and_si512(tmp[79],mask50);//*/
	
	
	
	
	__m512i D1_0 = _mm512_load_epi64(D1), D1_40 = _mm512_load_epi64(D1+40);
	__m512i D1_1 = _mm512_load_epi64(D1+1), D1_41 = _mm512_load_epi64(D1+41);
	__m512i D1_2 = _mm512_load_epi64(D1+2), D1_42 = _mm512_load_epi64(D1+42);
	__m512i D1_3 = _mm512_load_epi64(D1+3), D1_43 = _mm512_load_epi64(D1+43);
	__m512i D1_4 = _mm512_load_epi64(D1+4), D1_44 = _mm512_load_epi64(D1+44);
	__m512i D1_5 = _mm512_load_epi64(D1+5), D1_45 = _mm512_load_epi64(D1+45);
	__m512i D1_6 = _mm512_load_epi64(D1+6), D1_46 = _mm512_load_epi64(D1+46);
	__m512i D1_7 = _mm512_load_epi64(D1+7), D1_47 = _mm512_load_epi64(D1+47);
	__m512i D1_8 = _mm512_load_epi64(D1+8), D1_48 = _mm512_load_epi64(D1+48);
	__m512i D1_9 = _mm512_load_epi64(D1+9), D1_49 = _mm512_load_epi64(D1+49);
	__m512i D1_10 = _mm512_load_epi64(D1+10), D1_50 = _mm512_load_epi64(D1+50);
	__m512i D1_11 = _mm512_load_epi64(D1+11), D1_51 = _mm512_load_epi64(D1+51);
	__m512i D1_12 = _mm512_load_epi64(D1+12), D1_52 = _mm512_load_epi64(D1+52);
	__m512i D1_13 = _mm512_load_epi64(D1+13), D1_53 = _mm512_load_epi64(D1+53);
	__m512i D1_14 = _mm512_load_epi64(D1+14), D1_54 = _mm512_load_epi64(D1+54);
	__m512i D1_15 = _mm512_load_epi64(D1+15), D1_55 = _mm512_load_epi64(D1+55);
	__m512i D1_16 = _mm512_load_epi64(D1+16), D1_56 = _mm512_load_epi64(D1+56);
	__m512i D1_17 = _mm512_load_epi64(D1+17), D1_57 = _mm512_load_epi64(D1+57);
	__m512i D1_18 = _mm512_load_epi64(D1+18), D1_58 = _mm512_load_epi64(D1+58);
	__m512i D1_19 = _mm512_load_epi64(D1+19), D1_59 = _mm512_load_epi64(D1+59);
	__m512i D1_20 = _mm512_load_epi64(D1+20), D1_60 = _mm512_load_epi64(D1+60);
	__m512i D1_21 = _mm512_load_epi64(D1+21), D1_61 = _mm512_load_epi64(D1+61);
	__m512i D1_22 = _mm512_load_epi64(D1+22), D1_62 = _mm512_load_epi64(D1+62);
	__m512i D1_23 = _mm512_load_epi64(D1+23), D1_63 = _mm512_load_epi64(D1+63);
	__m512i D1_24 = _mm512_load_epi64(D1+24), D1_64 = _mm512_load_epi64(D1+64);
	__m512i D1_25 = _mm512_load_epi64(D1+25), D1_65 = _mm512_load_epi64(D1+65);
	__m512i D1_26 = _mm512_load_epi64(D1+26), D1_66 = _mm512_load_epi64(D1+66);
	__m512i D1_27 = _mm512_load_epi64(D1+27), D1_67 = _mm512_load_epi64(D1+67);
	__m512i D1_28 = _mm512_load_epi64(D1+28), D1_68 = _mm512_load_epi64(D1+68);
	__m512i D1_29 = _mm512_load_epi64(D1+29), D1_69 = _mm512_load_epi64(D1+69);
	__m512i D1_30 = _mm512_load_epi64(D1+30), D1_70 = _mm512_load_epi64(D1+70);
	__m512i D1_31 = _mm512_load_epi64(D1+31), D1_71 = _mm512_load_epi64(D1+71);
	__m512i D1_32 = _mm512_load_epi64(D1+32), D1_72 = _mm512_load_epi64(D1+72);
	__m512i D1_33 = _mm512_load_epi64(D1+33), D1_73 = _mm512_load_epi64(D1+73);
	__m512i D1_34 = _mm512_load_epi64(D1+34), D1_74 = _mm512_load_epi64(D1+74);
	__m512i D1_35 = _mm512_load_epi64(D1+35), D1_75 = _mm512_load_epi64(D1+75);
	__m512i D1_36 = _mm512_load_epi64(D1+36), D1_76 = _mm512_load_epi64(D1+76);
	__m512i D1_37 = _mm512_load_epi64(D1+37), D1_77 = _mm512_load_epi64(D1+77);
	__m512i D1_38 = _mm512_load_epi64(D1+38), D1_78 = _mm512_load_epi64(D1+78);
	__m512i D1_39 = _mm512_load_epi64(D1+39), D1_79 = _mm512_load_epi64(D1+79);//*/


	/*
	//conversion D2 in radix 2^2077
	
	carry = D1_39>>49;	D1_40 = (D1_40<<1)+carry;
	D1_39 &= mask50;	carry = D1_40>>52;
	D1_41 = (D1_41<<1)+carry;	D1_40 &= mask52;
	carry = D1_41>>52;	D1_42 = (D1_42<<1)+carry;
	D1_41 &= mask52;	carry = D1_42>>52;
	D1_43 = (D1_43<<1)+carry;	D1_42 &= mask52;
	carry = D1_43>>52;	D1_44 = (D1_44<<1)+carry;
	D1_43 &= mask52;	carry = D1_44>>52;
	D1_45 = (D1_45<<1)+carry;	D1_44 &= mask52;
	carry = D1_45>>52;	D1_46 = (D1_46<<1)+carry;
	D1_45 &= mask52;	carry = D1_46>>52;
	D1_47 = (D1_47<<1)+carry;	D1_46 &= mask52;
	carry = D1_47>>52;	D1_48 = (D1_48<<1)+carry;
	D1_47 &= mask52;	carry = D1_48>>52;
	D1_49 = (D1_49<<1)+carry;	D1_48 &= mask52;
	carry = D1_49>>52;	D1_50 = (D1_50<<1)+carry;
	D1_49 &= mask52;	carry = D1_50>>52;
	D1_51 = (D1_51<<1)+carry;	D1_50 &= mask52;
	carry = D1_51>>52;	D1_52 = (D1_52<<1)+carry;
	D1_51 &= mask52;	carry = D1_52>>52;
	D1_53 = (D1_53<<1)+carry;	D1_52 &= mask52;
	carry = D1_53>>52;	D1_54 = (D1_54<<1)+carry;
	D1_53 &= mask52;	carry = D1_54>>52;
	D1_55 = (D1_55<<1)+carry;	D1_54 &= mask52;
	carry = D1_55>>52;	D1_56 = (D1_56<<1)+carry;
	D1_55 &= mask52;	carry = D1_56>>52;
	D1_57 = (D1_57<<1)+carry;
	D1_56 &= mask52;	carry = D1_57>>52;
	D1_58 = (D1_58<<1)+carry;	D1_57 &= mask52;
	carry = D1_58>>52;	D1_59 = (D1_59<<1)+carry;
	D1_58 &= mask52;	carry = D1_59>>52;
	D1_60 = (D1_60<<1)+carry;	D1_59 &= mask52;
	carry = D1_60>>52;	D1_61 = (D1_61<<1)+carry;
	D1_60 &= mask52;	carry = D1_61>>52;
	D1_62 = (D1_62<<1)+carry;	D1_61 &= mask52;
	carry = D1_62>>52;	D1_63 = (D1_63<<1)+carry;
	D1_62 &= mask52;	carry = D1_63>>52;
	D1_64 = (D1_64<<1)+carry;	D1_63 &= mask52;
	carry = D1_64>>52;	D1_65 = (D1_65<<1)+carry;
	D1_64 &= mask52;	carry = D1_65>>52;
	D1_66 = (D1_66<<1)+carry;	D1_65 &= mask52;
	carry = D1_66>>52;	D1_67 = (D1_67<<1)+carry;
	D1_66 &= mask52;	carry = D1_67>>52;
	D1_68 = (D1_68<<1)+carry;	D1_67 &= mask52;
	carry = D1_68>>52;	D1_69 = (D1_69<<1)+carry;
	D1_68 &= mask52;	carry = D1_69>>52;
	D1_70 = (D1_70<<1)+carry;	D1_69 &= mask52;
	carry = D1_70>>52;	D1_71 = (D1_71<<1)+carry;
	D1_70 &= mask52;	carry = D1_71>>52;
	D1_72 = (D1_72<<1)+carry;	D1_71 &= mask52;
	carry = D1_72>>52;	D1_73 = (D1_73<<1)+carry;
	D1_72 &= mask52;	carry = D1_73>>52;
	D1_74 = (D1_74<<1)+carry;	D1_73 &= mask52;
	carry = D1_74>>52;	D1_75 = (D1_75<<1)+carry;
	D1_74 &= mask52;	carry = D1_75>>52;
	D1_76 = (D1_76<<1)+carry;	D1_75 &= mask52;
	carry = D1_76>>52;	D1_77 = (D1_77<<1)+carry;
	D1_76 &= mask52;	carry = D1_77>>52;
	D1_78 = (D1_78<<1)+carry;	D1_77 &= mask52;
	carry = D1_78>>52;	D1_79 = (D1_79<<1)+carry;
	D1_78 &= mask52;//*/


	__m512i borrow, carry, carry_D1;
	borrow = _mm512_add_epi64(D0_0,D2_0);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_0 = _mm512_add_epi64(D1_0,D0_40);
	carry_D1 = _mm512_srli_epi64(D1_0,52);
	D1_0 = _mm512_and_si512(D1_0,mask52);
	D1_0 = _mm512_sub_epi64(D1_0,borrow);
	borrow  = _mm512_srli_epi64(D1_0,52)&un;
	D1_0 = _mm512_and_si512(D1_0,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_1);
	borrow = _mm512_add_epi64(borrow,D0_1);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_1 = _mm512_add_epi64(D1_1,carry_D1);
	D1_1 = _mm512_add_epi64(D1_1,D0_41);
	carry_D1 = _mm512_srli_epi64(D1_1,52);
	D1_1 = _mm512_and_si512(D1_1,mask52);
	D1_1 = _mm512_sub_epi64(D1_1,borrow);
	borrow  = _mm512_srli_epi64(D1_1,52)&un;
	D1_1 = _mm512_and_si512(D1_1,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_2);
	borrow = _mm512_add_epi64(borrow,D0_2);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_2 = _mm512_add_epi64(D1_2,carry_D1);
	D1_2 = _mm512_add_epi64(D1_2,D0_42);
	carry_D1 = _mm512_srli_epi64(D1_2,52);
	D1_2 = _mm512_and_si512(D1_2,mask52);
	D1_2 = _mm512_sub_epi64(D1_2,borrow);
	borrow  = _mm512_srli_epi64(D1_2,52)&un;
	D1_2 = _mm512_and_si512(D1_2,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_3);
	borrow = _mm512_add_epi64(borrow,D0_3);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_3 = _mm512_add_epi64(D1_3,carry_D1);
	D1_3 = _mm512_add_epi64(D1_3,D0_43);
	carry_D1 = _mm512_srli_epi64(D1_3,52);
	D1_3 = _mm512_and_si512(D1_3,mask52);
	D1_3 = _mm512_sub_epi64(D1_3,borrow);
	borrow  = _mm512_srli_epi64(D1_3,52)&un;
	D1_3 = _mm512_and_si512(D1_3,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_4);
	borrow = _mm512_add_epi64(borrow,D0_4);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_4 = _mm512_add_epi64(D1_4,carry_D1);
	D1_4 = _mm512_add_epi64(D1_4,D0_44);
	carry_D1 = _mm512_srli_epi64(D1_4,52);
	D1_4 = _mm512_and_si512(D1_4,mask52);
	D1_4 = _mm512_sub_epi64(D1_4,borrow);
	borrow  = _mm512_srli_epi64(D1_4,52)&un;
	D1_4 = _mm512_and_si512(D1_4,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_5);
	borrow = _mm512_add_epi64(borrow,D0_5);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_5 = _mm512_add_epi64(D1_5,carry_D1);
	D1_5 = _mm512_add_epi64(D1_5,D0_45);
	carry_D1 = _mm512_srli_epi64(D1_5,52);
	D1_5 = _mm512_and_si512(D1_5,mask52);
	D1_5 = _mm512_sub_epi64(D1_5,borrow);
	borrow  = _mm512_srli_epi64(D1_5,52)&un;
	D1_5 = _mm512_and_si512(D1_5,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_6);
	borrow = _mm512_add_epi64(borrow,D0_6);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_6 = _mm512_add_epi64(D1_6,carry_D1);
	D1_6 = _mm512_add_epi64(D1_6,D0_46);
	carry_D1 = _mm512_srli_epi64(D1_6,52);
	D1_6 = _mm512_and_si512(D1_6,mask52);
	D1_6 = _mm512_sub_epi64(D1_6,borrow);
	borrow  = _mm512_srli_epi64(D1_6,52)&un;
	D1_6 = _mm512_and_si512(D1_6,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_7);
	borrow = _mm512_add_epi64(borrow,D0_7);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_7 = _mm512_add_epi64(D1_7,carry_D1);
	D1_7 = _mm512_add_epi64(D1_7,D0_47);
	carry_D1 = _mm512_srli_epi64(D1_7,52);
	D1_7 = _mm512_and_si512(D1_7,mask52);
	D1_7 = _mm512_sub_epi64(D1_7,borrow);
	borrow  = _mm512_srli_epi64(D1_7,52)&un;
	D1_7 = _mm512_and_si512(D1_7,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_8);
	borrow = _mm512_add_epi64(borrow,D0_8);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_8 = _mm512_add_epi64(D1_8,carry_D1);
	D1_8 = _mm512_add_epi64(D1_8,D0_48);
	carry_D1 = _mm512_srli_epi64(D1_8,52);
	D1_8 = _mm512_and_si512(D1_8,mask52);
	D1_8 = _mm512_sub_epi64(D1_8,borrow);
	borrow  = _mm512_srli_epi64(D1_8,52)&un;
	D1_8 = _mm512_and_si512(D1_8,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_9);
	borrow = _mm512_add_epi64(borrow,D0_9);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_9 = _mm512_add_epi64(D1_9,carry_D1);
	D1_9 = _mm512_add_epi64(D1_9,D0_49);
	carry_D1 = _mm512_srli_epi64(D1_9,52);
	D1_9 = _mm512_and_si512(D1_9,mask52);
	D1_9 = _mm512_sub_epi64(D1_9,borrow);
	borrow  = _mm512_srli_epi64(D1_9,52)&un;
	D1_9 = _mm512_and_si512(D1_9,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_10);
	borrow = _mm512_add_epi64(borrow,D0_10);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_10 = _mm512_add_epi64(D1_10,carry_D1);
	D1_10 = _mm512_add_epi64(D1_10,D0_50);
	carry_D1 = _mm512_srli_epi64(D1_10,52);
	D1_10 = _mm512_and_si512(D1_10,mask52);
	D1_10 = _mm512_sub_epi64(D1_10,borrow);
	borrow  = _mm512_srli_epi64(D1_10,52)&un;
	D1_10 = _mm512_and_si512(D1_10,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_11);
	borrow = _mm512_add_epi64(borrow,D0_11);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_11 = _mm512_add_epi64(D1_11,carry_D1);
	D1_11 = _mm512_add_epi64(D1_11,D0_51);
	carry_D1 = _mm512_srli_epi64(D1_11,52);
	D1_11 = _mm512_and_si512(D1_11,mask52);
	D1_11 = _mm512_sub_epi64(D1_11,borrow);
	borrow  = _mm512_srli_epi64(D1_11,52)&un;
	D1_11 = _mm512_and_si512(D1_11,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_12);
	borrow = _mm512_add_epi64(borrow,D0_12);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_12 = _mm512_add_epi64(D1_12,carry_D1);
	D1_12 = _mm512_add_epi64(D1_12,D0_52);
	carry_D1 = _mm512_srli_epi64(D1_12,52);
	D1_12 = _mm512_and_si512(D1_12,mask52);
	D1_12 = _mm512_sub_epi64(D1_12,borrow);
	borrow  = _mm512_srli_epi64(D1_12,52)&un;
	D1_12 = _mm512_and_si512(D1_12,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_13);
	borrow = _mm512_add_epi64(borrow,D0_13);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_13 = _mm512_add_epi64(D1_13,carry_D1);
	D1_13 = _mm512_add_epi64(D1_13,D0_53);
	carry_D1 = _mm512_srli_epi64(D1_13,52);
	D1_13 = _mm512_and_si512(D1_13,mask52);
	D1_13 = _mm512_sub_epi64(D1_13,borrow);
	borrow  = _mm512_srli_epi64(D1_13,52)&un;
	D1_13 = _mm512_and_si512(D1_13,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_14);
	borrow = _mm512_add_epi64(borrow,D0_14);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_14 = _mm512_add_epi64(D1_14,carry_D1);
	D1_14 = _mm512_add_epi64(D1_14,D0_54);
	carry_D1 = _mm512_srli_epi64(D1_14,52);
	D1_14 = _mm512_and_si512(D1_14,mask52);
	D1_14 = _mm512_sub_epi64(D1_14,borrow);
	borrow  = _mm512_srli_epi64(D1_14,52)&un;
	D1_14 = _mm512_and_si512(D1_14,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_15);
	borrow = _mm512_add_epi64(borrow,D0_15);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_15 = _mm512_add_epi64(D1_15,carry_D1);
	D1_15 = _mm512_add_epi64(D1_15,D0_55);
	carry_D1 = _mm512_srli_epi64(D1_15,52);
	D1_15 = _mm512_and_si512(D1_15,mask52);
	D1_15 = _mm512_sub_epi64(D1_15,borrow);
	borrow  = _mm512_srli_epi64(D1_15,52)&un;
	D1_15 = _mm512_and_si512(D1_15,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_16);
	borrow = _mm512_add_epi64(borrow,D0_16);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_16 = _mm512_add_epi64(D1_16,carry_D1);
	D1_16 = _mm512_add_epi64(D1_16,D0_56);
	carry_D1 = _mm512_srli_epi64(D1_16,52);
	D1_16 = _mm512_and_si512(D1_16,mask52);
	D1_16 = _mm512_sub_epi64(D1_16,borrow);
	borrow  = _mm512_srli_epi64(D1_16,52)&un;
	D1_16 = _mm512_and_si512(D1_16,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_17);
	borrow = _mm512_add_epi64(borrow,D0_17);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_17 = _mm512_add_epi64(D1_17,carry_D1);
	D1_17 = _mm512_add_epi64(D1_17,D0_57);
	carry_D1 = _mm512_srli_epi64(D1_17,52);
	D1_17 = _mm512_and_si512(D1_17,mask52);
	D1_17 = _mm512_sub_epi64(D1_17,borrow);
	borrow  = _mm512_srli_epi64(D1_17,52)&un;
	D1_17 = _mm512_and_si512(D1_17,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_18);
	borrow = _mm512_add_epi64(borrow,D0_18);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_18 = _mm512_add_epi64(D1_18,carry_D1);
	D1_18 = _mm512_add_epi64(D1_18,D0_58);
	carry_D1 = _mm512_srli_epi64(D1_18,52);
	D1_18 = _mm512_and_si512(D1_18,mask52);
	D1_18 = _mm512_sub_epi64(D1_18,borrow);
	borrow  = _mm512_srli_epi64(D1_18,52)&un;
	D1_18 = _mm512_and_si512(D1_18,mask52);

	borrow = _mm512_add_epi64(carry,borrow); // radix 2^1039
	borrow = _mm512_add_epi64(borrow,D2_19);
	borrow = _mm512_add_epi64(borrow,D0_19);
	carry = _mm512_srli_epi64(borrow,51);
	borrow = _mm512_and_si512(borrow,mask51);
	D1_19 = _mm512_add_epi64(D1_19,carry_D1);
	D1_19 = _mm512_add_epi64(D1_19,D0_59);
	carry_D1 = _mm512_srli_epi64(D1_19,51);
	D1_19 = _mm512_and_si512(D1_19,mask51);
	D1_19 = _mm512_sub_epi64(D1_19,borrow);
	borrow  = _mm512_srli_epi64(D1_19,51)&un;
	D1_19 = _mm512_and_si512(D1_19,mask51);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_20);
	borrow = _mm512_add_epi64(borrow,D0_20);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_20 = _mm512_add_epi64(D1_20,carry_D1);
	D1_20 = _mm512_add_epi64(D1_20,D0_60);
	carry_D1 = _mm512_srli_epi64(D1_20,52);
	D1_20 = _mm512_and_si512(D1_20,mask52);
	D1_20 = _mm512_sub_epi64(D1_20,borrow);
	borrow  = _mm512_srli_epi64(D1_20,52)&un;
	D1_20 = _mm512_and_si512(D1_20,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_21);
	borrow = _mm512_add_epi64(borrow,D0_21);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_21 = _mm512_add_epi64(D1_21,carry_D1);
	D1_21 = _mm512_add_epi64(D1_21,D0_61);
	carry_D1 = _mm512_srli_epi64(D1_21,52);
	D1_21 = _mm512_and_si512(D1_21,mask52);
	D1_21 = _mm512_sub_epi64(D1_21,borrow);
	borrow  = _mm512_srli_epi64(D1_21,52)&un;
	D1_21 = _mm512_and_si512(D1_21,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_22);
	borrow = _mm512_add_epi64(borrow,D0_22);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_22 = _mm512_add_epi64(D1_22,carry_D1);
	D1_22 = _mm512_add_epi64(D1_22,D0_62);
	carry_D1 = _mm512_srli_epi64(D1_22,52);
	D1_22 = _mm512_and_si512(D1_22,mask52);
	D1_22 = _mm512_sub_epi64(D1_22,borrow);
	borrow  = _mm512_srli_epi64(D1_22,52)&un;
	D1_22 = _mm512_and_si512(D1_22,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_23);
	borrow = _mm512_add_epi64(borrow,D0_23);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_23 = _mm512_add_epi64(D1_23,carry_D1);
	D1_23 = _mm512_add_epi64(D1_23,D0_63);
	carry_D1 = _mm512_srli_epi64(D1_23,52);
	D1_23 = _mm512_and_si512(D1_23,mask52);
	D1_23 = _mm512_sub_epi64(D1_23,borrow);
	borrow  = _mm512_srli_epi64(D1_23,52)&un;
	D1_23 = _mm512_and_si512(D1_23,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_24);
	borrow = _mm512_add_epi64(borrow,D0_24);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_24 = _mm512_add_epi64(D1_24,carry_D1);
	D1_24 = _mm512_add_epi64(D1_24,D0_64);
	carry_D1 = _mm512_srli_epi64(D1_24,52);
	D1_24 = _mm512_and_si512(D1_24,mask52);
	D1_24 = _mm512_sub_epi64(D1_24,borrow);
	borrow  = _mm512_srli_epi64(D1_24,52)&un;
	D1_24 = _mm512_and_si512(D1_24,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_25);
	borrow = _mm512_add_epi64(borrow,D0_25);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_25 = _mm512_add_epi64(D1_25,carry_D1);
	D1_25 = _mm512_add_epi64(D1_25,D0_65);
	carry_D1 = _mm512_srli_epi64(D1_25,52);
	D1_25 = _mm512_and_si512(D1_25,mask52);
	D1_25 = _mm512_sub_epi64(D1_25,borrow);
	borrow  = _mm512_srli_epi64(D1_25,52)&un;
	D1_25 = _mm512_and_si512(D1_25,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_26);
	borrow = _mm512_add_epi64(borrow,D0_26);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_26 = _mm512_add_epi64(D1_26,carry_D1);
	D1_26 = _mm512_add_epi64(D1_26,D0_66);
	carry_D1 = _mm512_srli_epi64(D1_26,52);
	D1_26 = _mm512_and_si512(D1_26,mask52);
	D1_26 = _mm512_sub_epi64(D1_26,borrow);
	borrow  = _mm512_srli_epi64(D1_26,52)&un;
	D1_26 = _mm512_and_si512(D1_26,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_27);
	borrow = _mm512_add_epi64(borrow,D0_27);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_27 = _mm512_add_epi64(D1_27,carry_D1);
	D1_27 = _mm512_add_epi64(D1_27,D0_67);
	carry_D1 = _mm512_srli_epi64(D1_27,52);
	D1_27 = _mm512_and_si512(D1_27,mask52);
	D1_27 = _mm512_sub_epi64(D1_27,borrow);
	borrow  = _mm512_srli_epi64(D1_27,52)&un;
	D1_27 = _mm512_and_si512(D1_27,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_28);
	borrow = _mm512_add_epi64(borrow,D0_28);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_28 = _mm512_add_epi64(D1_28,carry_D1);
	D1_28 = _mm512_add_epi64(D1_28,D0_68);
	carry_D1 = _mm512_srli_epi64(D1_28,52);
	D1_28 = _mm512_and_si512(D1_28,mask52);
	D1_28 = _mm512_sub_epi64(D1_28,borrow);
	borrow  = _mm512_srli_epi64(D1_28,52)&un;
	D1_28 = _mm512_and_si512(D1_28,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_29);
	borrow = _mm512_add_epi64(borrow,D0_29);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_29 = _mm512_add_epi64(D1_29,carry_D1);
	D1_29 = _mm512_add_epi64(D1_29,D0_69);
	carry_D1 = _mm512_srli_epi64(D1_29,52);
	D1_29 = _mm512_and_si512(D1_29,mask52);
	D1_29 = _mm512_sub_epi64(D1_29,borrow);
	borrow  = _mm512_srli_epi64(D1_29,52)&un;
	D1_29 = _mm512_and_si512(D1_29,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_30);
	borrow = _mm512_add_epi64(borrow,D0_30);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_30 = _mm512_add_epi64(D1_30,carry_D1);
	D1_30 = _mm512_add_epi64(D1_30,D0_70);
	carry_D1 = _mm512_srli_epi64(D1_30,52);
	D1_30 = _mm512_and_si512(D1_30,mask52);
	D1_30 = _mm512_sub_epi64(D1_30,borrow);
	borrow  = _mm512_srli_epi64(D1_30,52)&un;
	D1_30 = _mm512_and_si512(D1_30,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_31);
	borrow = _mm512_add_epi64(borrow,D0_31);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_31 = _mm512_add_epi64(D1_31,carry_D1);
	D1_31 = _mm512_add_epi64(D1_31,D0_71);
	carry_D1 = _mm512_srli_epi64(D1_31,52);
	D1_31 = _mm512_and_si512(D1_31,mask52);
	D1_31 = _mm512_sub_epi64(D1_31,borrow);
	borrow  = _mm512_srli_epi64(D1_31,52)&un;
	D1_31 = _mm512_and_si512(D1_31,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_32);
	borrow = _mm512_add_epi64(borrow,D0_32);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_32 = _mm512_add_epi64(D1_32,carry_D1);
	D1_32 = _mm512_add_epi64(D1_32,D0_72);
	carry_D1 = _mm512_srli_epi64(D1_32,52);
	D1_32 = _mm512_and_si512(D1_32,mask52);
	D1_32 = _mm512_sub_epi64(D1_32,borrow);
	borrow  = _mm512_srli_epi64(D1_32,52)&un;
	D1_32 = _mm512_and_si512(D1_32,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_33);
	borrow = _mm512_add_epi64(borrow,D0_33);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_33 = _mm512_add_epi64(D1_33,carry_D1);
	D1_33 = _mm512_add_epi64(D1_33,D0_73);
	carry_D1 = _mm512_srli_epi64(D1_33,52);
	D1_33 = _mm512_and_si512(D1_33,mask52);
	D1_33 = _mm512_sub_epi64(D1_33,borrow);
	borrow  = _mm512_srli_epi64(D1_33,52)&un;
	D1_33 = _mm512_and_si512(D1_33,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_34);
	borrow = _mm512_add_epi64(borrow,D0_34);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_34 = _mm512_add_epi64(D1_34,carry_D1);
	D1_34 = _mm512_add_epi64(D1_34,D0_74);
	carry_D1 = _mm512_srli_epi64(D1_34,52);
	D1_34 = _mm512_and_si512(D1_34,mask52);
	D1_34 = _mm512_sub_epi64(D1_34,borrow);
	borrow  = _mm512_srli_epi64(D1_34,52)&un;
	D1_34 = _mm512_and_si512(D1_34,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_35);
	borrow = _mm512_add_epi64(borrow,D0_35);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_35 = _mm512_add_epi64(D1_35,carry_D1);
	D1_35 = _mm512_add_epi64(D1_35,D0_75);
	carry_D1 = _mm512_srli_epi64(D1_35,52);
	D1_35 = _mm512_and_si512(D1_35,mask52);
	D1_35 = _mm512_sub_epi64(D1_35,borrow);
	borrow  = _mm512_srli_epi64(D1_35,52)&un;
	D1_35 = _mm512_and_si512(D1_35,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_36);
	borrow = _mm512_add_epi64(borrow,D0_36);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_36 = _mm512_add_epi64(D1_36,carry_D1);
	D1_36 = _mm512_add_epi64(D1_36,D0_76);
	carry_D1 = _mm512_srli_epi64(D1_36,52);
	D1_36 = _mm512_and_si512(D1_36,mask52);
	D1_36 = _mm512_sub_epi64(D1_36,borrow);
	borrow  = _mm512_srli_epi64(D1_36,52)&un;
	D1_36 = _mm512_and_si512(D1_36,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_37);
	borrow = _mm512_add_epi64(borrow,D0_37);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_37 = _mm512_add_epi64(D1_37,carry_D1);
	D1_37 = _mm512_add_epi64(D1_37,D0_77);
	carry_D1 = _mm512_srli_epi64(D1_37,52);
	D1_37 = _mm512_and_si512(D1_37,mask52);
	D1_37 = _mm512_sub_epi64(D1_37,borrow);
	borrow  = _mm512_srli_epi64(D1_37,52)&un;
	D1_37 = _mm512_and_si512(D1_37,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_38);
	borrow = _mm512_add_epi64(borrow,D0_38);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_38 = _mm512_add_epi64(D1_38,carry_D1);
	D1_38 = _mm512_add_epi64(D1_38,D0_78);
	carry_D1 = _mm512_srli_epi64(D1_38,52);
	D1_38 = _mm512_and_si512(D1_38,mask52);
	D1_38 = _mm512_sub_epi64(D1_38,borrow);
	borrow  = _mm512_srli_epi64(D1_38,52)&un;
	D1_38 = _mm512_and_si512(D1_38,mask52);

	borrow = _mm512_add_epi64(carry,borrow); // radix 2^2077
	borrow = _mm512_add_epi64(borrow,D2_39);
	borrow = _mm512_add_epi64(borrow,D0_39);
	carry = _mm512_srli_epi64(borrow,50);
	borrow = _mm512_and_si512(borrow,mask50);
	D1_39 = _mm512_add_epi64(D1_39,carry_D1);
	D1_39 = _mm512_add_epi64(D1_39,D0_79);
	carry_D1 = _mm512_srli_epi64(D1_39,50);
	D1_39 = _mm512_and_si512(D1_39,mask50);
	D1_39 = _mm512_sub_epi64(D1_39,borrow);
	borrow  = _mm512_srli_epi64(D1_39,50)&un;
	D1_39 = _mm512_and_si512(D1_39,mask50);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_40);
	borrow = _mm512_add_epi64(borrow,D0_40);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_40 = _mm512_add_epi64(D1_40,carry_D1);
	D1_40 = _mm512_add_epi64(D1_40,D2_0);
	carry_D1 = _mm512_srli_epi64(D1_40,52);
	D1_40 = _mm512_and_si512(D1_40,mask52);
	D1_40 = _mm512_sub_epi64(D1_40,borrow);
	borrow  = _mm512_srli_epi64(D1_40,52)&un;
	D1_40 = _mm512_and_si512(D1_40,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_41);
	borrow = _mm512_add_epi64(borrow,D0_41);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_41 = _mm512_add_epi64(D1_41,carry_D1);
	D1_41 = _mm512_add_epi64(D1_41,D2_1);
	carry_D1 = _mm512_srli_epi64(D1_41,52);
	D1_41 = _mm512_and_si512(D1_41,mask52);
	D1_41 = _mm512_sub_epi64(D1_41,borrow);
	borrow  = _mm512_srli_epi64(D1_41,52)&un;
	D1_41 = _mm512_and_si512(D1_41,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_42);
	borrow = _mm512_add_epi64(borrow,D0_42);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_42 = _mm512_add_epi64(D1_42,carry_D1);
	D1_42 = _mm512_add_epi64(D1_42,D2_2);
	carry_D1 = _mm512_srli_epi64(D1_42,52);
	D1_42 = _mm512_and_si512(D1_42,mask52);
	D1_42 = _mm512_sub_epi64(D1_42,borrow);
	borrow  = _mm512_srli_epi64(D1_42,52)&un;
	D1_42 = _mm512_and_si512(D1_42,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_43);
	borrow = _mm512_add_epi64(borrow,D0_43);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_43 = _mm512_add_epi64(D1_43,carry_D1);
	D1_43 = _mm512_add_epi64(D1_43,D2_3);
	carry_D1 = _mm512_srli_epi64(D1_43,52);
	D1_43 = _mm512_and_si512(D1_43,mask52);
	D1_43 = _mm512_sub_epi64(D1_43,borrow);
	borrow  = _mm512_srli_epi64(D1_43,52)&un;
	D1_43 = _mm512_and_si512(D1_43,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_44);
	borrow = _mm512_add_epi64(borrow,D0_44);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_44 = _mm512_add_epi64(D1_44,carry_D1);
	D1_44 = _mm512_add_epi64(D1_44,D2_4);
	carry_D1 = _mm512_srli_epi64(D1_44,52);
	D1_44 = _mm512_and_si512(D1_44,mask52);
	D1_44 = _mm512_sub_epi64(D1_44,borrow);
	borrow  = _mm512_srli_epi64(D1_44,52)&un;
	D1_44 = _mm512_and_si512(D1_44,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_45);
	borrow = _mm512_add_epi64(borrow,D0_45);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_45 = _mm512_add_epi64(D1_45,carry_D1);
	D1_45 = _mm512_add_epi64(D1_45,D2_5);
	carry_D1 = _mm512_srli_epi64(D1_45,52);
	D1_45 = _mm512_and_si512(D1_45,mask52);
	D1_45 = _mm512_sub_epi64(D1_45,borrow);
	borrow  = _mm512_srli_epi64(D1_45,52)&un;
	D1_45 = _mm512_and_si512(D1_45,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_46);
	borrow = _mm512_add_epi64(borrow,D0_46);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_46 = _mm512_add_epi64(D1_46,carry_D1);
	D1_46 = _mm512_add_epi64(D1_46,D2_6);
	carry_D1 = _mm512_srli_epi64(D1_46,52);
	D1_46 = _mm512_and_si512(D1_46,mask52);
	D1_46 = _mm512_sub_epi64(D1_46,borrow);
	borrow  = _mm512_srli_epi64(D1_46,52)&un;
	D1_46 = _mm512_and_si512(D1_46,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_47);
	borrow = _mm512_add_epi64(borrow,D0_47);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_47 = _mm512_add_epi64(D1_47,carry_D1);
	D1_47 = _mm512_add_epi64(D1_47,D2_7);
	carry_D1 = _mm512_srli_epi64(D1_47,52);
	D1_47 = _mm512_and_si512(D1_47,mask52);
	D1_47 = _mm512_sub_epi64(D1_47,borrow);
	borrow  = _mm512_srli_epi64(D1_47,52)&un;
	D1_47 = _mm512_and_si512(D1_47,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_48);
	borrow = _mm512_add_epi64(borrow,D0_48);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_48 = _mm512_add_epi64(D1_48,carry_D1);
	D1_48 = _mm512_add_epi64(D1_48,D2_8);
	carry_D1 = _mm512_srli_epi64(D1_48,52);
	D1_48 = _mm512_and_si512(D1_48,mask52);
	D1_48 = _mm512_sub_epi64(D1_48,borrow);
	borrow  = _mm512_srli_epi64(D1_48,52)&un;
	D1_48 = _mm512_and_si512(D1_48,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_49);
	borrow = _mm512_add_epi64(borrow,D0_49);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_49 = _mm512_add_epi64(D1_49,carry_D1);
	D1_49 = _mm512_add_epi64(D1_49,D2_9);
	carry_D1 = _mm512_srli_epi64(D1_49,52);
	D1_49 = _mm512_and_si512(D1_49,mask52);
	D1_49 = _mm512_sub_epi64(D1_49,borrow);
	borrow  = _mm512_srli_epi64(D1_49,52)&un;
	D1_49 = _mm512_and_si512(D1_49,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_50);
	borrow = _mm512_add_epi64(borrow,D0_50);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_50 = _mm512_add_epi64(D1_50,carry_D1);
	D1_50 = _mm512_add_epi64(D1_50,D2_10);
	carry_D1 = _mm512_srli_epi64(D1_50,52);
	D1_50 = _mm512_and_si512(D1_50,mask52);
	D1_50 = _mm512_sub_epi64(D1_50,borrow);
	borrow  = _mm512_srli_epi64(D1_50,52)&un;
	D1_50 = _mm512_and_si512(D1_50,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_51);
	borrow = _mm512_add_epi64(borrow,D0_51);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_51 = _mm512_add_epi64(D1_51,carry_D1);
	D1_51 = _mm512_add_epi64(D1_51,D2_11);
	carry_D1 = _mm512_srli_epi64(D1_51,52);
	D1_51 = _mm512_and_si512(D1_51,mask52);
	D1_51 = _mm512_sub_epi64(D1_51,borrow);
	borrow  = _mm512_srli_epi64(D1_51,52)&un;
	D1_51 = _mm512_and_si512(D1_51,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_52);
	borrow = _mm512_add_epi64(borrow,D0_52);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_52 = _mm512_add_epi64(D1_52,carry_D1);
	D1_52 = _mm512_add_epi64(D1_52,D2_12);
	carry_D1 = _mm512_srli_epi64(D1_52,52);
	D1_52 = _mm512_and_si512(D1_52,mask52);
	D1_52 = _mm512_sub_epi64(D1_52,borrow);
	borrow  = _mm512_srli_epi64(D1_52,52)&un;
	D1_52 = _mm512_and_si512(D1_52,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_53);
	borrow = _mm512_add_epi64(borrow,D0_53);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_53 = _mm512_add_epi64(D1_53,carry_D1);
	D1_53 = _mm512_add_epi64(D1_53,D2_13);
	carry_D1 = _mm512_srli_epi64(D1_53,52);
	D1_53 = _mm512_and_si512(D1_53,mask52);
	D1_53 = _mm512_sub_epi64(D1_53,borrow);
	borrow  = _mm512_srli_epi64(D1_53,52)&un;
	D1_53 = _mm512_and_si512(D1_53,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_54);
	borrow = _mm512_add_epi64(borrow,D0_54);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_54 = _mm512_add_epi64(D1_54,carry_D1);
	D1_54 = _mm512_add_epi64(D1_54,D2_14);
	carry_D1 = _mm512_srli_epi64(D1_54,52);
	D1_54 = _mm512_and_si512(D1_54,mask52);
	D1_54 = _mm512_sub_epi64(D1_54,borrow);
	borrow  = _mm512_srli_epi64(D1_54,52)&un;
	D1_54 = _mm512_and_si512(D1_54,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_55);
	borrow = _mm512_add_epi64(borrow,D0_55);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_55 = _mm512_add_epi64(D1_55,carry_D1);
	D1_55 = _mm512_add_epi64(D1_55,D2_15);
	carry_D1 = _mm512_srli_epi64(D1_55,52);
	D1_55 = _mm512_and_si512(D1_55,mask52);
	D1_55 = _mm512_sub_epi64(D1_55,borrow);
	borrow  = _mm512_srli_epi64(D1_55,52)&un;
	D1_55 = _mm512_and_si512(D1_55,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_56);
	borrow = _mm512_add_epi64(borrow,D0_56);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_56 = _mm512_add_epi64(D1_56,carry_D1);
	D1_56 = _mm512_add_epi64(D1_56,D2_16);
	carry_D1 = _mm512_srli_epi64(D1_56,52);
	D1_56 = _mm512_and_si512(D1_56,mask52);
	D1_56 = _mm512_sub_epi64(D1_56,borrow);
	borrow  = _mm512_srli_epi64(D1_56,52)&un;
	D1_56 = _mm512_and_si512(D1_56,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_57);
	borrow = _mm512_add_epi64(borrow,D0_57);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_57 = _mm512_add_epi64(D1_57,carry_D1);
	D1_57 = _mm512_add_epi64(D1_57,D2_17);
	carry_D1 = _mm512_srli_epi64(D1_57,52);
	D1_57 = _mm512_and_si512(D1_57,mask52);
	D1_57 = _mm512_sub_epi64(D1_57,borrow);
	borrow  = _mm512_srli_epi64(D1_57,52)&un;
	D1_57 = _mm512_and_si512(D1_57,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_58);
	borrow = _mm512_add_epi64(borrow,D0_58);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_58 = _mm512_add_epi64(D1_58,carry_D1);
	D1_58 = _mm512_add_epi64(D1_58,D2_18);
	carry_D1 = _mm512_srli_epi64(D1_58,52);
	D1_58 = _mm512_and_si512(D1_58,mask52);
	D1_58 = _mm512_sub_epi64(D1_58,borrow);
	borrow  = _mm512_srli_epi64(D1_58,52)&un;
	D1_58 = _mm512_and_si512(D1_58,mask52);

	borrow = _mm512_add_epi64(carry,borrow); // radix 2^1039
	borrow = _mm512_add_epi64(borrow,D2_59);
	borrow = _mm512_add_epi64(borrow,D0_59);
	carry = _mm512_srli_epi64(borrow,51);
	borrow = _mm512_and_si512(borrow,mask51);
	D1_59 = _mm512_add_epi64(D1_59,carry_D1);
	D1_59 = _mm512_add_epi64(D1_59,D2_19);
	carry_D1 = _mm512_srli_epi64(D1_59,51);
	D1_59 = _mm512_and_si512(D1_59,mask51);
	D1_59 = _mm512_sub_epi64(D1_59,borrow);
	borrow  = _mm512_srli_epi64(D1_59,51)&un;
	D1_59 = _mm512_and_si512(D1_59,mask51);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_60);
	borrow = _mm512_add_epi64(borrow,D0_60);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_60 = _mm512_add_epi64(D1_60,carry_D1);
	D1_60 = _mm512_add_epi64(D1_60,D2_20);
	carry_D1 = _mm512_srli_epi64(D1_60,52);
	D1_60 = _mm512_and_si512(D1_60,mask52);
	D1_60 = _mm512_sub_epi64(D1_60,borrow);
	borrow  = _mm512_srli_epi64(D1_60,52)&un;
	D1_60 = _mm512_and_si512(D1_60,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_61);
	borrow = _mm512_add_epi64(borrow,D0_61);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_61 = _mm512_add_epi64(D1_61,carry_D1);
	D1_61 = _mm512_add_epi64(D1_61,D2_21);
	carry_D1 = _mm512_srli_epi64(D1_61,52);
	D1_61 = _mm512_and_si512(D1_61,mask52);
	D1_61 = _mm512_sub_epi64(D1_61,borrow);
	borrow  = _mm512_srli_epi64(D1_61,52)&un;
	D1_61 = _mm512_and_si512(D1_61,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_62);
	borrow = _mm512_add_epi64(borrow,D0_62);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_62 = _mm512_add_epi64(D1_62,carry_D1);
	D1_62 = _mm512_add_epi64(D1_62,D2_22);
	carry_D1 = _mm512_srli_epi64(D1_62,52);
	D1_62 = _mm512_and_si512(D1_62,mask52);
	D1_62 = _mm512_sub_epi64(D1_62,borrow);
	borrow  = _mm512_srli_epi64(D1_62,52)&un;
	D1_62 = _mm512_and_si512(D1_62,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_63);
	borrow = _mm512_add_epi64(borrow,D0_63);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_63 = _mm512_add_epi64(D1_63,carry_D1);
	D1_63 = _mm512_add_epi64(D1_63,D2_23);
	carry_D1 = _mm512_srli_epi64(D1_63,52);
	D1_63 = _mm512_and_si512(D1_63,mask52);
	D1_63 = _mm512_sub_epi64(D1_63,borrow);
	borrow  = _mm512_srli_epi64(D1_63,52)&un;
	D1_63 = _mm512_and_si512(D1_63,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_64);
	borrow = _mm512_add_epi64(borrow,D0_64);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_64 = _mm512_add_epi64(D1_64,carry_D1);
	D1_64 = _mm512_add_epi64(D1_64,D2_24);
	carry_D1 = _mm512_srli_epi64(D1_64,52);
	D1_64 = _mm512_and_si512(D1_64,mask52);
	D1_64 = _mm512_sub_epi64(D1_64,borrow);
	borrow  = _mm512_srli_epi64(D1_64,52)&un;
	D1_64 = _mm512_and_si512(D1_64,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_65);
	borrow = _mm512_add_epi64(borrow,D0_65);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_65 = _mm512_add_epi64(D1_65,carry_D1);
	D1_65 = _mm512_add_epi64(D1_65,D2_25);
	carry_D1 = _mm512_srli_epi64(D1_65,52);
	D1_65 = _mm512_and_si512(D1_65,mask52);
	D1_65 = _mm512_sub_epi64(D1_65,borrow);
	borrow  = _mm512_srli_epi64(D1_65,52)&un;
	D1_65 = _mm512_and_si512(D1_65,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_66);
	borrow = _mm512_add_epi64(borrow,D0_66);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_66 = _mm512_add_epi64(D1_66,carry_D1);
	D1_66 = _mm512_add_epi64(D1_66,D2_26);
	carry_D1 = _mm512_srli_epi64(D1_66,52);
	D1_66 = _mm512_and_si512(D1_66,mask52);
	D1_66 = _mm512_sub_epi64(D1_66,borrow);
	borrow  = _mm512_srli_epi64(D1_66,52)&un;
	D1_66 = _mm512_and_si512(D1_66,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_67);
	borrow = _mm512_add_epi64(borrow,D0_67);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_67 = _mm512_add_epi64(D1_67,carry_D1);
	D1_67 = _mm512_add_epi64(D1_67,D2_27);
	carry_D1 = _mm512_srli_epi64(D1_67,52);
	D1_67 = _mm512_and_si512(D1_67,mask52);
	D1_67 = _mm512_sub_epi64(D1_67,borrow);
	borrow  = _mm512_srli_epi64(D1_67,52)&un;
	D1_67 = _mm512_and_si512(D1_67,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_68);
	borrow = _mm512_add_epi64(borrow,D0_68);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_68 = _mm512_add_epi64(D1_68,carry_D1);
	D1_68 = _mm512_add_epi64(D1_68,D2_28);
	carry_D1 = _mm512_srli_epi64(D1_68,52);
	D1_68 = _mm512_and_si512(D1_68,mask52);
	D1_68 = _mm512_sub_epi64(D1_68,borrow);
	borrow  = _mm512_srli_epi64(D1_68,52)&un;
	D1_68 = _mm512_and_si512(D1_68,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_69);
	borrow = _mm512_add_epi64(borrow,D0_69);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_69 = _mm512_add_epi64(D1_69,carry_D1);
	D1_69 = _mm512_add_epi64(D1_69,D2_29);
	carry_D1 = _mm512_srli_epi64(D1_69,52);
	D1_69 = _mm512_and_si512(D1_69,mask52);
	D1_69 = _mm512_sub_epi64(D1_69,borrow);
	borrow  = _mm512_srli_epi64(D1_69,52)&un;
	D1_69 = _mm512_and_si512(D1_69,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_70);
	borrow = _mm512_add_epi64(borrow,D0_70);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_70 = _mm512_add_epi64(D1_70,carry_D1);
	D1_70 = _mm512_add_epi64(D1_70,D2_30);
	carry_D1 = _mm512_srli_epi64(D1_70,52);
	D1_70 = _mm512_and_si512(D1_70,mask52);
	D1_70 = _mm512_sub_epi64(D1_70,borrow);
	borrow  = _mm512_srli_epi64(D1_70,52)&un;
	D1_70 = _mm512_and_si512(D1_70,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_71);
	borrow = _mm512_add_epi64(borrow,D0_71);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_71 = _mm512_add_epi64(D1_71,carry_D1);
	D1_71 = _mm512_add_epi64(D1_71,D2_31);
	carry_D1 = _mm512_srli_epi64(D1_71,52);
	D1_71 = _mm512_and_si512(D1_71,mask52);
	D1_71 = _mm512_sub_epi64(D1_71,borrow);
	borrow  = _mm512_srli_epi64(D1_71,52)&un;
	D1_71 = _mm512_and_si512(D1_71,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_72);
	borrow = _mm512_add_epi64(borrow,D0_72);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_72 = _mm512_add_epi64(D1_72,carry_D1);
	D1_72 = _mm512_add_epi64(D1_72,D2_32);
	carry_D1 = _mm512_srli_epi64(D1_72,52);
	D1_72 = _mm512_and_si512(D1_72,mask52);
	D1_72 = _mm512_sub_epi64(D1_72,borrow);
	borrow  = _mm512_srli_epi64(D1_72,52)&un;
	D1_72 = _mm512_and_si512(D1_72,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_73);
	borrow = _mm512_add_epi64(borrow,D0_73);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_73 = _mm512_add_epi64(D1_73,carry_D1);
	D1_73 = _mm512_add_epi64(D1_73,D2_33);
	carry_D1 = _mm512_srli_epi64(D1_73,52);
	D1_73 = _mm512_and_si512(D1_73,mask52);
	D1_73 = _mm512_sub_epi64(D1_73,borrow);
	borrow  = _mm512_srli_epi64(D1_73,52)&un;
	D1_73 = _mm512_and_si512(D1_73,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_74);
	borrow = _mm512_add_epi64(borrow,D0_74);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_74 = _mm512_add_epi64(D1_74,carry_D1);
	D1_74 = _mm512_add_epi64(D1_74,D2_34);
	carry_D1 = _mm512_srli_epi64(D1_74,52);
	D1_74 = _mm512_and_si512(D1_74,mask52);
	D1_74 = _mm512_sub_epi64(D1_74,borrow);
	borrow  = _mm512_srli_epi64(D1_74,52)&un;
	D1_74 = _mm512_and_si512(D1_74,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_75);
	borrow = _mm512_add_epi64(borrow,D0_75);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_75 = _mm512_add_epi64(D1_75,carry_D1);
	D1_75 = _mm512_add_epi64(D1_75,D2_35);
	carry_D1 = _mm512_srli_epi64(D1_75,52);
	D1_75 = _mm512_and_si512(D1_75,mask52);
	D1_75 = _mm512_sub_epi64(D1_75,borrow);
	borrow  = _mm512_srli_epi64(D1_75,52)&un;
	D1_75 = _mm512_and_si512(D1_75,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_76);
	borrow = _mm512_add_epi64(borrow,D0_76);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_76 = _mm512_add_epi64(D1_76,carry_D1);
	D1_76 = _mm512_add_epi64(D1_76,D2_36);
	carry_D1 = _mm512_srli_epi64(D1_76,52);
	D1_76 = _mm512_and_si512(D1_76,mask52);
	D1_76 = _mm512_sub_epi64(D1_76,borrow);
	borrow  = _mm512_srli_epi64(D1_76,52)&un;
	D1_76 = _mm512_and_si512(D1_76,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_77);
	borrow = _mm512_add_epi64(borrow,D0_77);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_77 = _mm512_add_epi64(D1_77,carry_D1);
	D1_77 = _mm512_add_epi64(D1_77,D2_37);
	carry_D1 = _mm512_srli_epi64(D1_77,52);
	D1_77 = _mm512_and_si512(D1_77,mask52);
	D1_77 = _mm512_sub_epi64(D1_77,borrow);
	borrow  = _mm512_srli_epi64(D1_77,52)&un;
	D1_77 = _mm512_and_si512(D1_77,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_78);
	borrow = _mm512_add_epi64(borrow,D0_78);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_78 = _mm512_add_epi64(D1_78,carry_D1);
	D1_78 = _mm512_add_epi64(D1_78,D2_38);
	carry_D1 = _mm512_srli_epi64(D1_78,52);
	D1_78 = _mm512_and_si512(D1_78,mask52);
	D1_78 = _mm512_sub_epi64(D1_78,borrow);
	borrow  = _mm512_srli_epi64(D1_78,52)&un;
	D1_78 = _mm512_and_si512(D1_78,mask52);

	borrow = _mm512_add_epi64(carry,borrow); // radix 2^2077
	borrow = _mm512_add_epi64(borrow,D2_79);
	borrow = _mm512_add_epi64(borrow,D0_79);
	carry = _mm512_srli_epi64(borrow,50);
	borrow = _mm512_and_si512(borrow,mask50);
	D1_79 = _mm512_add_epi64(D1_79,carry_D1);
	D1_79 = _mm512_add_epi64(D1_79,D2_39);
	carry_D1 = _mm512_srli_epi64(D1_79,50);
	D1_79 = _mm512_and_si512(D1_79,mask50);
	D1_79 = _mm512_sub_epi64(D1_79,borrow);
	borrow  = _mm512_srli_epi64(D1_79,50)&un;
	D1_79 = _mm512_and_si512(D1_79,mask50);


	// Final borrows
	D2_40 = _mm512_add_epi64(D2_40,carry_D1);
	
	borrow = _mm512_add_epi64(carry,borrow);
	D2_40 = _mm512_sub_epi64(D2_40,borrow);
	//borrow  = _mm512_srli_epi64(D2_40,52)&un;
	D2_40 = _mm512_and_si512(D2_40,mask52);//*/
	
	
	

	/*borrow = _mm512_add_epi64(carry_tmp,borrow);
	D2_40 = _mm512_add_epi64(D2_40,carry);
	D2_40 = _mm512_sub_epi64(D2_40,borrow);
	borrow  = _mm512_srli_epi64(D2_40,52)&un;
	D2_40 = _mm512_and_si512(D2_40,mask52);*/







	
	//borrow  = _mm512_srli_epi64(out_44,52)&un;
	//out_44 = _mm512_and_si512(out_44,mask52);
	
	
	

	
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
	_mm512_store_epi64(out+10,D0_10);
	_mm512_store_epi64(out+11,D0_11);
	_mm512_store_epi64(out+12,D0_12);
	_mm512_store_epi64(out+13,D0_13);
	_mm512_store_epi64(out+14,D0_14);
	_mm512_store_epi64(out+15,D0_15);
	_mm512_store_epi64(out+16,D0_16);
	_mm512_store_epi64(out+17,D0_17);
	_mm512_store_epi64(out+18,D0_18);
	_mm512_store_epi64(out+19,D0_19);
	_mm512_store_epi64(out+20,D0_20);
	_mm512_store_epi64(out+21,D0_21);
	_mm512_store_epi64(out+22,D0_22);
	_mm512_store_epi64(out+23,D0_23);
	_mm512_store_epi64(out+24,D0_24);
	_mm512_store_epi64(out+25,D0_25);
	_mm512_store_epi64(out+26,D0_26);
	_mm512_store_epi64(out+27,D0_27);
	_mm512_store_epi64(out+28,D0_28);
	_mm512_store_epi64(out+29,D0_29);
	_mm512_store_epi64(out+30,D0_30);
	_mm512_store_epi64(out+31,D0_31);
	_mm512_store_epi64(out+32,D0_32);
	_mm512_store_epi64(out+33,D0_33);
	_mm512_store_epi64(out+34,D0_34);
	_mm512_store_epi64(out+35,D0_35);
	_mm512_store_epi64(out+36,D0_36);
	_mm512_store_epi64(out+37,D0_37);
	_mm512_store_epi64(out+38,D0_38);
	_mm512_store_epi64(out+39,D0_39);
	_mm512_store_epi64(out+40,D1_0);
	_mm512_store_epi64(out+41,D1_1);
	_mm512_store_epi64(out+42,D1_2);
	_mm512_store_epi64(out+43,D1_3);
	_mm512_store_epi64(out+44,D1_4);
	_mm512_store_epi64(out+45,D1_5);
	_mm512_store_epi64(out+46,D1_6);
	_mm512_store_epi64(out+47,D1_7);
	_mm512_store_epi64(out+48,D1_8);
	_mm512_store_epi64(out+49,D1_9);
	_mm512_store_epi64(out+50,D1_10);
	_mm512_store_epi64(out+51,D1_11);
	_mm512_store_epi64(out+52,D1_12);
	_mm512_store_epi64(out+53,D1_13);
	_mm512_store_epi64(out+54,D1_14);
	_mm512_store_epi64(out+55,D1_15);
	_mm512_store_epi64(out+56,D1_16);
	_mm512_store_epi64(out+57,D1_17);
	_mm512_store_epi64(out+58,D1_18);
	_mm512_store_epi64(out+59,D1_19);
	_mm512_store_epi64(out+60,D1_20);
	_mm512_store_epi64(out+61,D1_21);
	_mm512_store_epi64(out+62,D1_22);
	_mm512_store_epi64(out+63,D1_23);
	_mm512_store_epi64(out+64,D1_24);
	_mm512_store_epi64(out+65,D1_25);
	_mm512_store_epi64(out+66,D1_26);
	_mm512_store_epi64(out+67,D1_27);
	_mm512_store_epi64(out+68,D1_28);
	_mm512_store_epi64(out+69,D1_29);
	_mm512_store_epi64(out+70,D1_30);
	_mm512_store_epi64(out+71,D1_31);
	_mm512_store_epi64(out+72,D1_32);
	_mm512_store_epi64(out+73,D1_33);
	_mm512_store_epi64(out+74,D1_34);
	_mm512_store_epi64(out+75,D1_35);
	_mm512_store_epi64(out+76,D1_36);
	_mm512_store_epi64(out+77,D1_37);
	_mm512_store_epi64(out+78,D1_38);
	_mm512_store_epi64(out+79,D1_39);





	_mm512_store_epi64(out+80,D1_40);
	_mm512_store_epi64(out+81,D1_41);
	_mm512_store_epi64(out+82,D1_42);
	_mm512_store_epi64(out+83,D1_43);
	_mm512_store_epi64(out+84,D1_44);
	_mm512_store_epi64(out+85,D1_45);
	_mm512_store_epi64(out+86,D1_46);
	_mm512_store_epi64(out+87,D1_47);
	_mm512_store_epi64(out+88,D1_48);
	_mm512_store_epi64(out+89,D1_49);
	_mm512_store_epi64(out+90,D1_50);
	_mm512_store_epi64(out+91,D1_51);
	_mm512_store_epi64(out+92,D1_52);
	_mm512_store_epi64(out+93,D1_53);
	_mm512_store_epi64(out+94,D1_54);
	_mm512_store_epi64(out+95,D1_55);
	_mm512_store_epi64(out+96,D1_56);
	_mm512_store_epi64(out+97,D1_57);
	_mm512_store_epi64(out+98,D1_58);
	_mm512_store_epi64(out+99,D1_59);
	_mm512_store_epi64(out+100,D1_60);
	_mm512_store_epi64(out+101,D1_61);
	_mm512_store_epi64(out+102,D1_62);
	_mm512_store_epi64(out+103,D1_63);
	_mm512_store_epi64(out+104,D1_64);
	_mm512_store_epi64(out+105,D1_65);
	_mm512_store_epi64(out+106,D1_66);
	_mm512_store_epi64(out+107,D1_67);
	_mm512_store_epi64(out+108,D1_68);
	_mm512_store_epi64(out+109,D1_69);
	_mm512_store_epi64(out+110,D1_70);
	_mm512_store_epi64(out+111,D1_71);
	_mm512_store_epi64(out+112,D1_72);
	_mm512_store_epi64(out+113,D1_73);
	_mm512_store_epi64(out+114,D1_74);
	_mm512_store_epi64(out+115,D1_75);
	_mm512_store_epi64(out+116,D1_76);
	_mm512_store_epi64(out+117,D1_77);
	_mm512_store_epi64(out+118,D1_78);
	_mm512_store_epi64(out+119,D1_79);//*/
	_mm512_store_epi64(out+120,D2_40);
	_mm512_store_epi64(out+121,D2_41);
	_mm512_store_epi64(out+122,D2_42);
	_mm512_store_epi64(out+123,D2_43);
	_mm512_store_epi64(out+124,D2_44);
	_mm512_store_epi64(out+125,D2_45);
	_mm512_store_epi64(out+126,D2_46);
	_mm512_store_epi64(out+127,D2_47);
	_mm512_store_epi64(out+128,D2_48);
	_mm512_store_epi64(out+129,D2_49);
	_mm512_store_epi64(out+130,D2_50);
	_mm512_store_epi64(out+131,D2_51);
	_mm512_store_epi64(out+132,D2_52);
	_mm512_store_epi64(out+133,D2_53);
	_mm512_store_epi64(out+134,D2_54);
	_mm512_store_epi64(out+135,D2_55);
	_mm512_store_epi64(out+136,D2_56);
	_mm512_store_epi64(out+137,D2_57);
	_mm512_store_epi64(out+138,D2_58);
	_mm512_store_epi64(out+139,D2_59);
	_mm512_store_epi64(out+140,D2_60);
	_mm512_store_epi64(out+141,D2_61);
	_mm512_store_epi64(out+142,D2_62);
	_mm512_store_epi64(out+143,D2_63);
	_mm512_store_epi64(out+144,D2_64);
	_mm512_store_epi64(out+145,D2_65);
	_mm512_store_epi64(out+146,D2_66);
	_mm512_store_epi64(out+147,D2_67);
	_mm512_store_epi64(out+148,D2_68);
	_mm512_store_epi64(out+149,D2_69);
	_mm512_store_epi64(out+150,D2_70);
	_mm512_store_epi64(out+151,D2_71);
	_mm512_store_epi64(out+152,D2_72);
	_mm512_store_epi64(out+153,D2_73);
	_mm512_store_epi64(out+154,D2_74);
	_mm512_store_epi64(out+155,D2_75);
	_mm512_store_epi64(out+156,D2_76);
	_mm512_store_epi64(out+157,D2_77);
	_mm512_store_epi64(out+158,D2_78);
	_mm512_store_epi64(out+159,D2_79);

	/*
	unsigned long int a64_full[8][NB_COEFF64], b64_full[8][NB_COEFF64], res64_full[8][NB_COEFF64*2], res_gmp_full[NB_COEFF64*2];
	fcontract_8_512_4154KK_res(res64_full, out);
	//for(int i=0;i<8;i++)
	//		displayVect(res64_full[i],"res64[i]    ",NB_COEFF64*2);

	fcontract_8_512_4154KK(a64_full, a512);
	
	fcontract_8_512_4154KK(b64_full, b512);
	
	
	
	for(int i=0;i<8;i++)
	{

		mpz_import(A, NB_COEFF64, -1, sizeof(b64[0][0]) ,0,0, a64_full[i]);

		mpz_import(B, NB_COEFF64, -1, sizeof(b64[0][0]) ,0,0, b64_full[i]);
		
		gmp_printf("A  : 0x%ZX\n", A);

		displayVect(a64_full[i],"a64",65);
		printf("\n\n");
		
		gmp_printf("B  : 0x%ZX\n", B);
		displayVect(b64_full[i],"b64",65);
		printf("\n\n");
		
		
	
	
		mpz_mul(C,A,B);
		mpz_export(res_gmp_full, &countp, -1, sizeof(b64[0][0]) ,0,0, C);
		displayVect(res_gmp_full, "res_gmp     ",NB_COEFF64*2);
		displayVect(res64_full[i],"res64[i]    ",NB_COEFF64*2);
		
		
		printf("xor = ");
		for(int j=0;j<NB_COEFF64*2;j++){
			printf("%16.16lX ",res64_full[i][NB_COEFF64*2-1-j]^res_gmp_full[NB_COEFF64*2-1-j]);
		}
		printf("\n");

	//}
	//printf("\n");
	
	//for(int i=0;i<8;i++){//
		for(int j=0;j<NB_COEFF64*2;j++)
			if(res64_full[i][j]^res_gmp_full[j]) flag++;
		flag?counter++,flag=0:counter,flag=0;
		printf("\n");
	}
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory a*b !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;

	mpz_clears (A, B, C, NULL);

	//getchar();//*/
	



}



/* Karatsuba squaring */

static inline void force_inline square512_8_4154KK(__m512i out[160], __m512i a512[80])
{

	__m512i D0[80], D1[80], D2[80], alpah[40], blpbh[40], alpahbis[40], blpbhbis[40];


	// al*bl, radix 2^1039 result
	
	square512_8_2078K(D0, a512);

	

	// ah*bh, radix 2^1039 result
	
	square512_8_2078K(D2, a512+40);




	// ah*bh, radix 2^1039 result
	
	add512_8_2078K(alpah, a512, a512+40);
	
	square512_8_2078K(D1, alpah);
	
	/*displayVect512_NB(a512,"a512",80);
	displayVect512_NB(b512,"b512",80);
	
	
	displayVect512_NB(alpah,"alpah",40);
	displayVect512_NB(blpbh,"blpbh",40);
	

	displayVect512_NB_COEFF(D1,"D1");
	
	//getchar();//*/
	
	/*unsigned long int a64[8][NB_COEFF64_SIZE_K], b64[8][NB_COEFF64_SIZE_K], res64[8][NB_COEFF64_SIZE_K*2], res_gmp[NB_COEFF64_SIZE_K*2];
	size_t countp;
	
	int counter=0,flag=0;
	
	fcontract_8_512_2077K(a64,alpah);
	fcontract_8_512_2077K(b64,blpbh);
	
	fexpand_8_512_2077K(alpahbis,a64);
	
	fexpand_8_512_2077K(blpbhbis,b64);
	
	displayVect512_NB(alpah,"alpah   ",40);
	displayVect512_NB(alpahbis,"alpahbis",40);
	getchar();
	displayVect512_NB(blpbh,"blpbh   ",40);
	displayVect512_NB(blpbhbis,"blpbhbis",40);
	//getchar();//*/
	
	
	
	/*mpz_t A, B, C;// UPB is used as upper bound
	
	mpz_inits (A, B, C, NULL);
	//conversion_8_r2077K(D1,D1);
	
	fcontract_8_512_2077K_res( res64, D1);
	for(int i=0;i<8;i++)
	{

		mpz_import(A, NB_COEFF64_SIZE_K, -1, sizeof(b64[0][0]) ,0,0, a64[i]);

		mpz_import(B, NB_COEFF64_SIZE_K, -1, sizeof(b64[0][0]) ,0,0, b64[i]);
		
		gmp_printf("A  : 0x%ZX\n\n\n", A);

		displayVect(a64[i],"a64",33);
		gmp_printf("B  : 0x%ZX\n\n\n", B);
		displayVect(b64[i],"b64",33);
		
		
	
	
		mpz_mul(C,A,B);
		mpz_export(res_gmp, &countp, -1, sizeof(b64[0][0]) ,0,0, C);
		displayVect(res_gmp, "res_gmp     ",NB_COEFF64_SIZE_K*2);
		displayVect(res64[i],"res64[i]    ",NB_COEFF64_SIZE_K*2);
		
		
		printf("xor = ");
		for(int j=0;j<NB_COEFF64_SIZE_K*2;j++){
			printf("%16.16lX ",res64[i][NB_COEFF64_SIZE_K*2-1-j]^res_gmp[NB_COEFF64_SIZE_K*2-1-j]);
		}
		printf("\n");

	//}
	//printf("\n");
	
	//for(int i=0;i<8;i++){//
		for(int j=0;j<NB_COEFF64_SIZE_K*2;j++)
			if(res64[i][j]^res_gmp[j]) flag++;
		flag?counter++,flag=0:counter,flag=0;
		printf("\n");
	}
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory alpah*blbph !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;

	//}
	
	// conversion in radix 2^2077 conversion
	
	//displayVect512_NB_COEFF(D0,"D0");
	/*displayVect512_NB_COEFF(D0,"D0");

	getchar();//*/
	
	
	conversion_8_r2077K(D0,D0);
	conversion_8_r2077K(D1,D1);
	conversion_8_r2077K(D2,D2);//*/
	
	
	//__m512i c = 
	/*displayVect512_NB(D1,"D1",40);
	add512_8_2078K(D1, D1, D0+40);
	//D1[40] = _mm512_add_epi64(D1[40],c);
	displayVect512_NB(D0+40,"D0+40",40);
	displayVect512_NB(D1,"D1",40);
	
	// 	retenue
	__m512i c = _mm512_srli_epi64(D1[39],49);
	displayVect512(&c,"c");
	
	//getchar();
	
	D1[39] = _mm512_and_si512(D1[39],mask50);
	displayVect512_NB(D1,"D1",40);
	
	
	D1[40] = _mm512_add_epi64(D1[40],c);
	
	
	add512_8_2078K(D1+40, D1+40, D2);
	c = _mm512_srli_epi64(D1[79],49);
	D1[79] = _mm512_and_si512(D1[79],mask50);//*/
	
	
	__m512i D0_0 = _mm512_load_epi64(D0), D2_0 = _mm512_load_epi64(D2);
	__m512i D0_1 = _mm512_load_epi64(D0+1), D2_1 = _mm512_load_epi64(D2+1);
	__m512i D0_2 = _mm512_load_epi64(D0+2), D2_2 = _mm512_load_epi64(D2+2);
	__m512i D0_3 = _mm512_load_epi64(D0+3), D2_3 = _mm512_load_epi64(D2+3);
	__m512i D0_4 = _mm512_load_epi64(D0+4), D2_4 = _mm512_load_epi64(D2+4);
	__m512i D0_5 = _mm512_load_epi64(D0+5), D2_5 = _mm512_load_epi64(D2+5);
	__m512i D0_6 = _mm512_load_epi64(D0+6), D2_6 = _mm512_load_epi64(D2+6);
	__m512i D0_7 = _mm512_load_epi64(D0+7), D2_7 = _mm512_load_epi64(D2+7);
	__m512i D0_8 = _mm512_load_epi64(D0+8), D2_8 = _mm512_load_epi64(D2+8);
	__m512i D0_9 = _mm512_load_epi64(D0+9), D2_9 = _mm512_load_epi64(D2+9);
	__m512i D0_10 = _mm512_load_epi64(D0+10), D2_10 = _mm512_load_epi64(D2+10);
	__m512i D0_11 = _mm512_load_epi64(D0+11), D2_11 = _mm512_load_epi64(D2+11);
	__m512i D0_12 = _mm512_load_epi64(D0+12), D2_12 = _mm512_load_epi64(D2+12);
	__m512i D0_13 = _mm512_load_epi64(D0+13), D2_13 = _mm512_load_epi64(D2+13);
	__m512i D0_14 = _mm512_load_epi64(D0+14), D2_14 = _mm512_load_epi64(D2+14);
	__m512i D0_15 = _mm512_load_epi64(D0+15), D2_15 = _mm512_load_epi64(D2+15);
	__m512i D0_16 = _mm512_load_epi64(D0+16), D2_16 = _mm512_load_epi64(D2+16);
	__m512i D0_17 = _mm512_load_epi64(D0+17), D2_17 = _mm512_load_epi64(D2+17);
	__m512i D0_18 = _mm512_load_epi64(D0+18), D2_18 = _mm512_load_epi64(D2+18);
	__m512i D0_19 = _mm512_load_epi64(D0+19), D2_19 = _mm512_load_epi64(D2+19);
	__m512i D0_20 = _mm512_load_epi64(D0+20), D2_20 = _mm512_load_epi64(D2+20);
	__m512i D0_21 = _mm512_load_epi64(D0+21), D2_21 = _mm512_load_epi64(D2+21);
	__m512i D0_22 = _mm512_load_epi64(D0+22), D2_22 = _mm512_load_epi64(D2+22);
	__m512i D0_23 = _mm512_load_epi64(D0+23), D2_23 = _mm512_load_epi64(D2+23);
	__m512i D0_24 = _mm512_load_epi64(D0+24), D2_24 = _mm512_load_epi64(D2+24);
	__m512i D0_25 = _mm512_load_epi64(D0+25), D2_25 = _mm512_load_epi64(D2+25);
	__m512i D0_26 = _mm512_load_epi64(D0+26), D2_26 = _mm512_load_epi64(D2+26);
	__m512i D0_27 = _mm512_load_epi64(D0+27), D2_27 = _mm512_load_epi64(D2+27);
	__m512i D0_28 = _mm512_load_epi64(D0+28), D2_28 = _mm512_load_epi64(D2+28);
	__m512i D0_29 = _mm512_load_epi64(D0+29), D2_29 = _mm512_load_epi64(D2+29);
	__m512i D0_30 = _mm512_load_epi64(D0+30), D2_30 = _mm512_load_epi64(D2+30);
	__m512i D0_31 = _mm512_load_epi64(D0+31), D2_31 = _mm512_load_epi64(D2+31);
	__m512i D0_32 = _mm512_load_epi64(D0+32), D2_32 = _mm512_load_epi64(D2+32);
	__m512i D0_33 = _mm512_load_epi64(D0+33), D2_33 = _mm512_load_epi64(D2+33);
	__m512i D0_34 = _mm512_load_epi64(D0+34), D2_34 = _mm512_load_epi64(D2+34);
	__m512i D0_35 = _mm512_load_epi64(D0+35), D2_35 = _mm512_load_epi64(D2+35);
	__m512i D0_36 = _mm512_load_epi64(D0+36), D2_36 = _mm512_load_epi64(D2+36);
	__m512i D0_37 = _mm512_load_epi64(D0+37), D2_37 = _mm512_load_epi64(D2+37);
	__m512i D0_38 = _mm512_load_epi64(D0+38), D2_38 = _mm512_load_epi64(D2+38);
	__m512i D0_39 = _mm512_load_epi64(D0+39), D2_39 = _mm512_load_epi64(D2+39);
	
	
	__m512i D0_40 = _mm512_load_epi64(D0+40), D2_40 = _mm512_load_epi64(D2+40);
	__m512i D0_41 = _mm512_load_epi64(D0+41), D2_41 = _mm512_load_epi64(D2+41);
	__m512i D0_42 = _mm512_load_epi64(D0+42), D2_42 = _mm512_load_epi64(D2+42);
	__m512i D0_43 = _mm512_load_epi64(D0+43), D2_43 = _mm512_load_epi64(D2+43);
	__m512i D0_44 = _mm512_load_epi64(D0+44), D2_44 = _mm512_load_epi64(D2+44);
	__m512i D0_45 = _mm512_load_epi64(D0+45), D2_45 = _mm512_load_epi64(D2+45);
	__m512i D0_46 = _mm512_load_epi64(D0+46), D2_46 = _mm512_load_epi64(D2+46);
	__m512i D0_47 = _mm512_load_epi64(D0+47), D2_47 = _mm512_load_epi64(D2+47);
	__m512i D0_48 = _mm512_load_epi64(D0+48), D2_48 = _mm512_load_epi64(D2+48);
	__m512i D0_49 = _mm512_load_epi64(D0+49), D2_49 = _mm512_load_epi64(D2+49);
	__m512i D0_50 = _mm512_load_epi64(D0+50), D2_50 = _mm512_load_epi64(D2+50);
	__m512i D0_51 = _mm512_load_epi64(D0+51), D2_51 = _mm512_load_epi64(D2+51);
	__m512i D0_52 = _mm512_load_epi64(D0+52), D2_52 = _mm512_load_epi64(D2+52);
	__m512i D0_53 = _mm512_load_epi64(D0+53), D2_53 = _mm512_load_epi64(D2+53);
	__m512i D0_54 = _mm512_load_epi64(D0+54), D2_54 = _mm512_load_epi64(D2+54);
	__m512i D0_55 = _mm512_load_epi64(D0+55), D2_55 = _mm512_load_epi64(D2+55);
	__m512i D0_56 = _mm512_load_epi64(D0+56), D2_56 = _mm512_load_epi64(D2+56);
	__m512i D0_57 = _mm512_load_epi64(D0+57), D2_57 = _mm512_load_epi64(D2+57);
	__m512i D0_58 = _mm512_load_epi64(D0+58), D2_58 = _mm512_load_epi64(D2+58);
	__m512i D0_59 = _mm512_load_epi64(D0+59), D2_59 = _mm512_load_epi64(D2+59);
	__m512i D0_60 = _mm512_load_epi64(D0+60), D2_60 = _mm512_load_epi64(D2+60);
	__m512i D0_61 = _mm512_load_epi64(D0+61), D2_61 = _mm512_load_epi64(D2+61);
	__m512i D0_62 = _mm512_load_epi64(D0+62), D2_62 = _mm512_load_epi64(D2+62);
	__m512i D0_63 = _mm512_load_epi64(D0+63), D2_63 = _mm512_load_epi64(D2+63);
	__m512i D0_64 = _mm512_load_epi64(D0+64), D2_64 = _mm512_load_epi64(D2+64);
	__m512i D0_65 = _mm512_load_epi64(D0+65), D2_65 = _mm512_load_epi64(D2+65);
	__m512i D0_66 = _mm512_load_epi64(D0+66), D2_66 = _mm512_load_epi64(D2+66);
	__m512i D0_67 = _mm512_load_epi64(D0+67), D2_67 = _mm512_load_epi64(D2+67);
	__m512i D0_68 = _mm512_load_epi64(D0+68), D2_68 = _mm512_load_epi64(D2+68);
	__m512i D0_69 = _mm512_load_epi64(D0+69), D2_69 = _mm512_load_epi64(D2+69);
	__m512i D0_70 = _mm512_load_epi64(D0+70), D2_70 = _mm512_load_epi64(D2+70);
	__m512i D0_71 = _mm512_load_epi64(D0+71), D2_71 = _mm512_load_epi64(D2+71);
	__m512i D0_72 = _mm512_load_epi64(D0+72), D2_72 = _mm512_load_epi64(D2+72);
	__m512i D0_73 = _mm512_load_epi64(D0+73), D2_73 = _mm512_load_epi64(D2+73);
	__m512i D0_74 = _mm512_load_epi64(D0+74), D2_74 = _mm512_load_epi64(D2+74);
	__m512i D0_75 = _mm512_load_epi64(D0+75), D2_75 = _mm512_load_epi64(D2+75);
	__m512i D0_76 = _mm512_load_epi64(D0+76), D2_76 = _mm512_load_epi64(D2+76);
	__m512i D0_77 = _mm512_load_epi64(D0+77), D2_77 = _mm512_load_epi64(D2+77);
	__m512i D0_78 = _mm512_load_epi64(D0+78), D2_78 = _mm512_load_epi64(D2+78);
	__m512i D0_79 = _mm512_load_epi64(D0+79), D2_79 = _mm512_load_epi64(D2+79);
	
	/*
	//conversion D0 in radix 2^2077
	
	__m512i carry = D0_39>>49;	D0_40 = (D0_40<<1)+carry;
	D0_39 &= mask50;	carry = D0_40>>52;
	D0_41 = (D0_41<<1)+carry;	D0_40 &= mask52;
	carry = D0_41>>52;	D0_42 = (D0_42<<1)+carry;
	D0_41 &= mask52;	carry = D0_42>>52;
	D0_43 = (D0_43<<1)+carry;	D0_42 &= mask52;
	carry = D0_43>>52;	D0_44 = (D0_44<<1)+carry;
	D0_43 &= mask52;	carry = D0_44>>52;
	D0_45 = (D0_45<<1)+carry;	D0_44 &= mask52;
	carry = D0_45>>52;	D0_46 = (D0_46<<1)+carry;
	D0_45 &= mask52;	carry = D0_46>>52;
	D0_47 = (D0_47<<1)+carry;	D0_46 &= mask52;
	carry = D0_47>>52;	D0_48 = (D0_48<<1)+carry;
	D0_47 &= mask52;	carry = D0_48>>52;
	D0_49 = (D0_49<<1)+carry;	D0_48 &= mask52;
	carry = D0_49>>52;	D0_50 = (D0_50<<1)+carry;
	D0_49 &= mask52;	carry = D0_50>>52;
	D0_51 = (D0_51<<1)+carry;	D0_50 &= mask52;
	carry = D0_51>>52;	D0_52 = (D0_52<<1)+carry;
	D0_51 &= mask52;	carry = D0_52>>52;
	D0_53 = (D0_53<<1)+carry;	D0_52 &= mask52;
	carry = D0_53>>52;	D0_54 = (D0_54<<1)+carry;
	D0_53 &= mask52;	carry = D0_54>>52;
	D0_55 = (D0_55<<1)+carry;	D0_54 &= mask52;
	carry = D0_55>>52;	D0_56 = (D0_56<<1)+carry;
	D0_55 &= mask52;	carry = D0_56>>52;
	D0_57 = (D0_57<<1)+carry;
	D0_56 &= mask52;	carry = D0_57>>52;
	D0_58 = (D0_58<<1)+carry;	D0_57 &= mask52;
	carry = D0_58>>52;	D0_59 = (D0_59<<1)+carry;
	D0_58 &= mask52;	carry = D0_59>>52;
	D0_60 = (D0_60<<1)+carry;	D0_59 &= mask52;
	carry = D0_60>>52;	D0_61 = (D0_61<<1)+carry;
	D0_60 &= mask52;	carry = D0_61>>52;
	D0_62 = (D0_62<<1)+carry;	D0_61 &= mask52;
	carry = D0_62>>52;	D0_63 = (D0_63<<1)+carry;
	D0_62 &= mask52;	carry = D0_63>>52;
	D0_64 = (D0_64<<1)+carry;	D0_63 &= mask52;
	carry = D0_64>>52;	D0_65 = (D0_65<<1)+carry;
	D0_64 &= mask52;	carry = D0_65>>52;
	D0_66 = (D0_66<<1)+carry;	D0_65 &= mask52;
	carry = D0_66>>52;	D0_67 = (D0_67<<1)+carry;
	D0_66 &= mask52;	carry = D0_67>>52;
	D0_68 = (D0_68<<1)+carry;	D0_67 &= mask52;
	carry = D0_68>>52;	D0_69 = (D0_69<<1)+carry;
	D0_68 &= mask52;	carry = D0_69>>52;
	D0_70 = (D0_70<<1)+carry;	D0_69 &= mask52;
	carry = D0_70>>52;	D0_71 = (D0_71<<1)+carry;
	D0_70 &= mask52;	carry = D0_71>>52;
	D0_72 = (D0_72<<1)+carry;	D0_71 &= mask52;
	carry = D0_72>>52;	D0_73 = (D0_73<<1)+carry;
	D0_72 &= mask52;	carry = D0_73>>52;
	D0_74 = (D0_74<<1)+carry;	D0_73 &= mask52;
	carry = D0_74>>52;	D0_75 = (D0_75<<1)+carry;
	D0_74 &= mask52;	carry = D0_75>>52;
	D0_76 = (D0_76<<1)+carry;	D0_75 &= mask52;
	carry = D0_76>>52;	D0_77 = (D0_77<<1)+carry;
	D0_76 &= mask52;	carry = D0_77>>52;
	D0_78 = (D0_78<<1)+carry;	D0_77 &= mask52;
	carry = D0_78>>52;	D0_79 = (D0_79<<1)+carry;
	D0_78 &= mask52;
	

	//conversion D2 in radix 2^2077
	
	carry = D2_39>>49;	D2_40 = (D2_40<<1)+carry;
	D2_39 &= mask50;	carry = D2_40>>52;
	D2_41 = (D2_41<<1)+carry;	D2_40 &= mask52;
	carry = D2_41>>52;	D2_42 = (D2_42<<1)+carry;
	D2_41 &= mask52;	carry = D2_42>>52;
	D2_43 = (D2_43<<1)+carry;	D2_42 &= mask52;
	carry = D2_43>>52;	D2_44 = (D2_44<<1)+carry;
	D2_43 &= mask52;	carry = D2_44>>52;
	D2_45 = (D2_45<<1)+carry;	D2_44 &= mask52;
	carry = D2_45>>52;	D2_46 = (D2_46<<1)+carry;
	D2_45 &= mask52;	carry = D2_46>>52;
	D2_47 = (D2_47<<1)+carry;	D2_46 &= mask52;
	carry = D2_47>>52;	D2_48 = (D2_48<<1)+carry;
	D2_47 &= mask52;	carry = D2_48>>52;
	D2_49 = (D2_49<<1)+carry;	D2_48 &= mask52;
	carry = D2_49>>52;	D2_50 = (D2_50<<1)+carry;
	D2_49 &= mask52;	carry = D2_50>>52;
	D2_51 = (D2_51<<1)+carry;	D2_50 &= mask52;
	carry = D2_51>>52;	D2_52 = (D2_52<<1)+carry;
	D2_51 &= mask52;	carry = D2_52>>52;
	D2_53 = (D2_53<<1)+carry;	D2_52 &= mask52;
	carry = D2_53>>52;	D2_54 = (D2_54<<1)+carry;
	D2_53 &= mask52;	carry = D2_54>>52;
	D2_55 = (D2_55<<1)+carry;	D2_54 &= mask52;
	carry = D2_55>>52;	D2_56 = (D2_56<<1)+carry;
	D2_55 &= mask52;	carry = D2_56>>52;
	D2_57 = (D2_57<<1)+carry;
	D2_56 &= mask52;	carry = D2_57>>52;
	D2_58 = (D2_58<<1)+carry;	D2_57 &= mask52;
	carry = D2_58>>52;	D2_59 = (D2_59<<1)+carry;
	D2_58 &= mask52;	carry = D2_59>>52;
	D2_60 = (D2_60<<1)+carry;	D2_59 &= mask52;
	carry = D2_60>>52;	D2_61 = (D2_61<<1)+carry;
	D2_60 &= mask52;	carry = D2_61>>52;
	D2_62 = (D2_62<<1)+carry;	D2_61 &= mask52;
	carry = D2_62>>52;	D2_63 = (D2_63<<1)+carry;
	D2_62 &= mask52;	carry = D2_63>>52;
	D2_64 = (D2_64<<1)+carry;	D2_63 &= mask52;
	carry = D2_64>>52;	D2_65 = (D2_65<<1)+carry;
	D2_64 &= mask52;	carry = D2_65>>52;
	D2_66 = (D2_66<<1)+carry;	D2_65 &= mask52;
	carry = D2_66>>52;	D2_67 = (D2_67<<1)+carry;
	D2_66 &= mask52;	carry = D2_67>>52;
	D2_68 = (D2_68<<1)+carry;	D2_67 &= mask52;
	carry = D2_68>>52;	D2_69 = (D2_69<<1)+carry;
	D2_68 &= mask52;	carry = D2_69>>52;
	D2_70 = (D2_70<<1)+carry;	D2_69 &= mask52;
	carry = D2_70>>52;	D2_71 = (D2_71<<1)+carry;
	D2_70 &= mask52;	carry = D2_71>>52;
	D2_72 = (D2_72<<1)+carry;	D2_71 &= mask52;
	carry = D2_72>>52;	D2_73 = (D2_73<<1)+carry;
	D2_72 &= mask52;	carry = D2_73>>52;
	D2_74 = (D2_74<<1)+carry;	D2_73 &= mask52;
	carry = D2_74>>52;	D2_75 = (D2_75<<1)+carry;
	D2_74 &= mask52;	carry = D2_75>>52;
	D2_76 = (D2_76<<1)+carry;	D2_75 &= mask52;
	carry = D2_76>>52;	D2_77 = (D2_77<<1)+carry;
	D2_76 &= mask52;	carry = D2_77>>52;
	D2_78 = (D2_78<<1)+carry;	D2_77 &= mask52;
	carry = D2_78>>52;	D2_79 = (D2_79<<1)+carry;
	D2_78 &= mask52;//*/


	
	
	// Final Reconstruction
	

	// tmp = D0+D2, radix 2^2077/radix 2^1039
	/*__m512i tmp[160];
	
	add512_8_2078K(tmp, D0, D2);
	
	// Carry radix 2^2077
	tmp[40] = _mm512_srli_epi64(tmp[39],49);
	tmp[39] = _mm512_and_si512(tmp[39],mask50);
	
	addC512_8_2078K(tmp+40, D0+40, D2+40);//*/
	

	// D1 = D1 -tmp, radix 2^2079/radix 2^1039
	
	/*add512_8_2078K(D1, D1, D0+40);
	
	add512_8_2078K(D1+40, D1+40, D2);
	
	__m512i borrow = sub512_8_4154K(D1, D1, tmp);
	
	//last borrow
	
	__m512i borrow = _mm512_srli_epi64(tmp[79],49);
	tmp[79] = _mm512_and_si512(tmp[79],mask50);//*/
	
	
	
	
	__m512i D1_0 = _mm512_load_epi64(D1), D1_40 = _mm512_load_epi64(D1+40);
	__m512i D1_1 = _mm512_load_epi64(D1+1), D1_41 = _mm512_load_epi64(D1+41);
	__m512i D1_2 = _mm512_load_epi64(D1+2), D1_42 = _mm512_load_epi64(D1+42);
	__m512i D1_3 = _mm512_load_epi64(D1+3), D1_43 = _mm512_load_epi64(D1+43);
	__m512i D1_4 = _mm512_load_epi64(D1+4), D1_44 = _mm512_load_epi64(D1+44);
	__m512i D1_5 = _mm512_load_epi64(D1+5), D1_45 = _mm512_load_epi64(D1+45);
	__m512i D1_6 = _mm512_load_epi64(D1+6), D1_46 = _mm512_load_epi64(D1+46);
	__m512i D1_7 = _mm512_load_epi64(D1+7), D1_47 = _mm512_load_epi64(D1+47);
	__m512i D1_8 = _mm512_load_epi64(D1+8), D1_48 = _mm512_load_epi64(D1+48);
	__m512i D1_9 = _mm512_load_epi64(D1+9), D1_49 = _mm512_load_epi64(D1+49);
	__m512i D1_10 = _mm512_load_epi64(D1+10), D1_50 = _mm512_load_epi64(D1+50);
	__m512i D1_11 = _mm512_load_epi64(D1+11), D1_51 = _mm512_load_epi64(D1+51);
	__m512i D1_12 = _mm512_load_epi64(D1+12), D1_52 = _mm512_load_epi64(D1+52);
	__m512i D1_13 = _mm512_load_epi64(D1+13), D1_53 = _mm512_load_epi64(D1+53);
	__m512i D1_14 = _mm512_load_epi64(D1+14), D1_54 = _mm512_load_epi64(D1+54);
	__m512i D1_15 = _mm512_load_epi64(D1+15), D1_55 = _mm512_load_epi64(D1+55);
	__m512i D1_16 = _mm512_load_epi64(D1+16), D1_56 = _mm512_load_epi64(D1+56);
	__m512i D1_17 = _mm512_load_epi64(D1+17), D1_57 = _mm512_load_epi64(D1+57);
	__m512i D1_18 = _mm512_load_epi64(D1+18), D1_58 = _mm512_load_epi64(D1+58);
	__m512i D1_19 = _mm512_load_epi64(D1+19), D1_59 = _mm512_load_epi64(D1+59);
	__m512i D1_20 = _mm512_load_epi64(D1+20), D1_60 = _mm512_load_epi64(D1+60);
	__m512i D1_21 = _mm512_load_epi64(D1+21), D1_61 = _mm512_load_epi64(D1+61);
	__m512i D1_22 = _mm512_load_epi64(D1+22), D1_62 = _mm512_load_epi64(D1+62);
	__m512i D1_23 = _mm512_load_epi64(D1+23), D1_63 = _mm512_load_epi64(D1+63);
	__m512i D1_24 = _mm512_load_epi64(D1+24), D1_64 = _mm512_load_epi64(D1+64);
	__m512i D1_25 = _mm512_load_epi64(D1+25), D1_65 = _mm512_load_epi64(D1+65);
	__m512i D1_26 = _mm512_load_epi64(D1+26), D1_66 = _mm512_load_epi64(D1+66);
	__m512i D1_27 = _mm512_load_epi64(D1+27), D1_67 = _mm512_load_epi64(D1+67);
	__m512i D1_28 = _mm512_load_epi64(D1+28), D1_68 = _mm512_load_epi64(D1+68);
	__m512i D1_29 = _mm512_load_epi64(D1+29), D1_69 = _mm512_load_epi64(D1+69);
	__m512i D1_30 = _mm512_load_epi64(D1+30), D1_70 = _mm512_load_epi64(D1+70);
	__m512i D1_31 = _mm512_load_epi64(D1+31), D1_71 = _mm512_load_epi64(D1+71);
	__m512i D1_32 = _mm512_load_epi64(D1+32), D1_72 = _mm512_load_epi64(D1+72);
	__m512i D1_33 = _mm512_load_epi64(D1+33), D1_73 = _mm512_load_epi64(D1+73);
	__m512i D1_34 = _mm512_load_epi64(D1+34), D1_74 = _mm512_load_epi64(D1+74);
	__m512i D1_35 = _mm512_load_epi64(D1+35), D1_75 = _mm512_load_epi64(D1+75);
	__m512i D1_36 = _mm512_load_epi64(D1+36), D1_76 = _mm512_load_epi64(D1+76);
	__m512i D1_37 = _mm512_load_epi64(D1+37), D1_77 = _mm512_load_epi64(D1+77);
	__m512i D1_38 = _mm512_load_epi64(D1+38), D1_78 = _mm512_load_epi64(D1+78);
	__m512i D1_39 = _mm512_load_epi64(D1+39), D1_79 = _mm512_load_epi64(D1+79);//*/


	/*
	//conversion D2 in radix 2^2077
	
	carry = D1_39>>49;	D1_40 = (D1_40<<1)+carry;
	D1_39 &= mask50;	carry = D1_40>>52;
	D1_41 = (D1_41<<1)+carry;	D1_40 &= mask52;
	carry = D1_41>>52;	D1_42 = (D1_42<<1)+carry;
	D1_41 &= mask52;	carry = D1_42>>52;
	D1_43 = (D1_43<<1)+carry;	D1_42 &= mask52;
	carry = D1_43>>52;	D1_44 = (D1_44<<1)+carry;
	D1_43 &= mask52;	carry = D1_44>>52;
	D1_45 = (D1_45<<1)+carry;	D1_44 &= mask52;
	carry = D1_45>>52;	D1_46 = (D1_46<<1)+carry;
	D1_45 &= mask52;	carry = D1_46>>52;
	D1_47 = (D1_47<<1)+carry;	D1_46 &= mask52;
	carry = D1_47>>52;	D1_48 = (D1_48<<1)+carry;
	D1_47 &= mask52;	carry = D1_48>>52;
	D1_49 = (D1_49<<1)+carry;	D1_48 &= mask52;
	carry = D1_49>>52;	D1_50 = (D1_50<<1)+carry;
	D1_49 &= mask52;	carry = D1_50>>52;
	D1_51 = (D1_51<<1)+carry;	D1_50 &= mask52;
	carry = D1_51>>52;	D1_52 = (D1_52<<1)+carry;
	D1_51 &= mask52;	carry = D1_52>>52;
	D1_53 = (D1_53<<1)+carry;	D1_52 &= mask52;
	carry = D1_53>>52;	D1_54 = (D1_54<<1)+carry;
	D1_53 &= mask52;	carry = D1_54>>52;
	D1_55 = (D1_55<<1)+carry;	D1_54 &= mask52;
	carry = D1_55>>52;	D1_56 = (D1_56<<1)+carry;
	D1_55 &= mask52;	carry = D1_56>>52;
	D1_57 = (D1_57<<1)+carry;
	D1_56 &= mask52;	carry = D1_57>>52;
	D1_58 = (D1_58<<1)+carry;	D1_57 &= mask52;
	carry = D1_58>>52;	D1_59 = (D1_59<<1)+carry;
	D1_58 &= mask52;	carry = D1_59>>52;
	D1_60 = (D1_60<<1)+carry;	D1_59 &= mask52;
	carry = D1_60>>52;	D1_61 = (D1_61<<1)+carry;
	D1_60 &= mask52;	carry = D1_61>>52;
	D1_62 = (D1_62<<1)+carry;	D1_61 &= mask52;
	carry = D1_62>>52;	D1_63 = (D1_63<<1)+carry;
	D1_62 &= mask52;	carry = D1_63>>52;
	D1_64 = (D1_64<<1)+carry;	D1_63 &= mask52;
	carry = D1_64>>52;	D1_65 = (D1_65<<1)+carry;
	D1_64 &= mask52;	carry = D1_65>>52;
	D1_66 = (D1_66<<1)+carry;	D1_65 &= mask52;
	carry = D1_66>>52;	D1_67 = (D1_67<<1)+carry;
	D1_66 &= mask52;	carry = D1_67>>52;
	D1_68 = (D1_68<<1)+carry;	D1_67 &= mask52;
	carry = D1_68>>52;	D1_69 = (D1_69<<1)+carry;
	D1_68 &= mask52;	carry = D1_69>>52;
	D1_70 = (D1_70<<1)+carry;	D1_69 &= mask52;
	carry = D1_70>>52;	D1_71 = (D1_71<<1)+carry;
	D1_70 &= mask52;	carry = D1_71>>52;
	D1_72 = (D1_72<<1)+carry;	D1_71 &= mask52;
	carry = D1_72>>52;	D1_73 = (D1_73<<1)+carry;
	D1_72 &= mask52;	carry = D1_73>>52;
	D1_74 = (D1_74<<1)+carry;	D1_73 &= mask52;
	carry = D1_74>>52;	D1_75 = (D1_75<<1)+carry;
	D1_74 &= mask52;	carry = D1_75>>52;
	D1_76 = (D1_76<<1)+carry;	D1_75 &= mask52;
	carry = D1_76>>52;	D1_77 = (D1_77<<1)+carry;
	D1_76 &= mask52;	carry = D1_77>>52;
	D1_78 = (D1_78<<1)+carry;	D1_77 &= mask52;
	carry = D1_78>>52;	D1_79 = (D1_79<<1)+carry;
	D1_78 &= mask52;//*/


	__m512i borrow, carry, carry_D1;
	borrow = _mm512_add_epi64(D0_0,D2_0);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_0 = _mm512_add_epi64(D1_0,D0_40);
	carry_D1 = _mm512_srli_epi64(D1_0,52);
	D1_0 = _mm512_and_si512(D1_0,mask52);
	D1_0 = _mm512_sub_epi64(D1_0,borrow);
	borrow  = _mm512_srli_epi64(D1_0,52)&un;
	D1_0 = _mm512_and_si512(D1_0,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_1);
	borrow = _mm512_add_epi64(borrow,D0_1);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_1 = _mm512_add_epi64(D1_1,carry_D1);
	D1_1 = _mm512_add_epi64(D1_1,D0_41);
	carry_D1 = _mm512_srli_epi64(D1_1,52);
	D1_1 = _mm512_and_si512(D1_1,mask52);
	D1_1 = _mm512_sub_epi64(D1_1,borrow);
	borrow  = _mm512_srli_epi64(D1_1,52)&un;
	D1_1 = _mm512_and_si512(D1_1,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_2);
	borrow = _mm512_add_epi64(borrow,D0_2);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_2 = _mm512_add_epi64(D1_2,carry_D1);
	D1_2 = _mm512_add_epi64(D1_2,D0_42);
	carry_D1 = _mm512_srli_epi64(D1_2,52);
	D1_2 = _mm512_and_si512(D1_2,mask52);
	D1_2 = _mm512_sub_epi64(D1_2,borrow);
	borrow  = _mm512_srli_epi64(D1_2,52)&un;
	D1_2 = _mm512_and_si512(D1_2,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_3);
	borrow = _mm512_add_epi64(borrow,D0_3);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_3 = _mm512_add_epi64(D1_3,carry_D1);
	D1_3 = _mm512_add_epi64(D1_3,D0_43);
	carry_D1 = _mm512_srli_epi64(D1_3,52);
	D1_3 = _mm512_and_si512(D1_3,mask52);
	D1_3 = _mm512_sub_epi64(D1_3,borrow);
	borrow  = _mm512_srli_epi64(D1_3,52)&un;
	D1_3 = _mm512_and_si512(D1_3,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_4);
	borrow = _mm512_add_epi64(borrow,D0_4);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_4 = _mm512_add_epi64(D1_4,carry_D1);
	D1_4 = _mm512_add_epi64(D1_4,D0_44);
	carry_D1 = _mm512_srli_epi64(D1_4,52);
	D1_4 = _mm512_and_si512(D1_4,mask52);
	D1_4 = _mm512_sub_epi64(D1_4,borrow);
	borrow  = _mm512_srli_epi64(D1_4,52)&un;
	D1_4 = _mm512_and_si512(D1_4,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_5);
	borrow = _mm512_add_epi64(borrow,D0_5);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_5 = _mm512_add_epi64(D1_5,carry_D1);
	D1_5 = _mm512_add_epi64(D1_5,D0_45);
	carry_D1 = _mm512_srli_epi64(D1_5,52);
	D1_5 = _mm512_and_si512(D1_5,mask52);
	D1_5 = _mm512_sub_epi64(D1_5,borrow);
	borrow  = _mm512_srli_epi64(D1_5,52)&un;
	D1_5 = _mm512_and_si512(D1_5,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_6);
	borrow = _mm512_add_epi64(borrow,D0_6);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_6 = _mm512_add_epi64(D1_6,carry_D1);
	D1_6 = _mm512_add_epi64(D1_6,D0_46);
	carry_D1 = _mm512_srli_epi64(D1_6,52);
	D1_6 = _mm512_and_si512(D1_6,mask52);
	D1_6 = _mm512_sub_epi64(D1_6,borrow);
	borrow  = _mm512_srli_epi64(D1_6,52)&un;
	D1_6 = _mm512_and_si512(D1_6,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_7);
	borrow = _mm512_add_epi64(borrow,D0_7);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_7 = _mm512_add_epi64(D1_7,carry_D1);
	D1_7 = _mm512_add_epi64(D1_7,D0_47);
	carry_D1 = _mm512_srli_epi64(D1_7,52);
	D1_7 = _mm512_and_si512(D1_7,mask52);
	D1_7 = _mm512_sub_epi64(D1_7,borrow);
	borrow  = _mm512_srli_epi64(D1_7,52)&un;
	D1_7 = _mm512_and_si512(D1_7,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_8);
	borrow = _mm512_add_epi64(borrow,D0_8);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_8 = _mm512_add_epi64(D1_8,carry_D1);
	D1_8 = _mm512_add_epi64(D1_8,D0_48);
	carry_D1 = _mm512_srli_epi64(D1_8,52);
	D1_8 = _mm512_and_si512(D1_8,mask52);
	D1_8 = _mm512_sub_epi64(D1_8,borrow);
	borrow  = _mm512_srli_epi64(D1_8,52)&un;
	D1_8 = _mm512_and_si512(D1_8,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_9);
	borrow = _mm512_add_epi64(borrow,D0_9);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_9 = _mm512_add_epi64(D1_9,carry_D1);
	D1_9 = _mm512_add_epi64(D1_9,D0_49);
	carry_D1 = _mm512_srli_epi64(D1_9,52);
	D1_9 = _mm512_and_si512(D1_9,mask52);
	D1_9 = _mm512_sub_epi64(D1_9,borrow);
	borrow  = _mm512_srli_epi64(D1_9,52)&un;
	D1_9 = _mm512_and_si512(D1_9,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_10);
	borrow = _mm512_add_epi64(borrow,D0_10);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_10 = _mm512_add_epi64(D1_10,carry_D1);
	D1_10 = _mm512_add_epi64(D1_10,D0_50);
	carry_D1 = _mm512_srli_epi64(D1_10,52);
	D1_10 = _mm512_and_si512(D1_10,mask52);
	D1_10 = _mm512_sub_epi64(D1_10,borrow);
	borrow  = _mm512_srli_epi64(D1_10,52)&un;
	D1_10 = _mm512_and_si512(D1_10,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_11);
	borrow = _mm512_add_epi64(borrow,D0_11);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_11 = _mm512_add_epi64(D1_11,carry_D1);
	D1_11 = _mm512_add_epi64(D1_11,D0_51);
	carry_D1 = _mm512_srli_epi64(D1_11,52);
	D1_11 = _mm512_and_si512(D1_11,mask52);
	D1_11 = _mm512_sub_epi64(D1_11,borrow);
	borrow  = _mm512_srli_epi64(D1_11,52)&un;
	D1_11 = _mm512_and_si512(D1_11,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_12);
	borrow = _mm512_add_epi64(borrow,D0_12);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_12 = _mm512_add_epi64(D1_12,carry_D1);
	D1_12 = _mm512_add_epi64(D1_12,D0_52);
	carry_D1 = _mm512_srli_epi64(D1_12,52);
	D1_12 = _mm512_and_si512(D1_12,mask52);
	D1_12 = _mm512_sub_epi64(D1_12,borrow);
	borrow  = _mm512_srli_epi64(D1_12,52)&un;
	D1_12 = _mm512_and_si512(D1_12,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_13);
	borrow = _mm512_add_epi64(borrow,D0_13);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_13 = _mm512_add_epi64(D1_13,carry_D1);
	D1_13 = _mm512_add_epi64(D1_13,D0_53);
	carry_D1 = _mm512_srli_epi64(D1_13,52);
	D1_13 = _mm512_and_si512(D1_13,mask52);
	D1_13 = _mm512_sub_epi64(D1_13,borrow);
	borrow  = _mm512_srli_epi64(D1_13,52)&un;
	D1_13 = _mm512_and_si512(D1_13,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_14);
	borrow = _mm512_add_epi64(borrow,D0_14);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_14 = _mm512_add_epi64(D1_14,carry_D1);
	D1_14 = _mm512_add_epi64(D1_14,D0_54);
	carry_D1 = _mm512_srli_epi64(D1_14,52);
	D1_14 = _mm512_and_si512(D1_14,mask52);
	D1_14 = _mm512_sub_epi64(D1_14,borrow);
	borrow  = _mm512_srli_epi64(D1_14,52)&un;
	D1_14 = _mm512_and_si512(D1_14,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_15);
	borrow = _mm512_add_epi64(borrow,D0_15);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_15 = _mm512_add_epi64(D1_15,carry_D1);
	D1_15 = _mm512_add_epi64(D1_15,D0_55);
	carry_D1 = _mm512_srli_epi64(D1_15,52);
	D1_15 = _mm512_and_si512(D1_15,mask52);
	D1_15 = _mm512_sub_epi64(D1_15,borrow);
	borrow  = _mm512_srli_epi64(D1_15,52)&un;
	D1_15 = _mm512_and_si512(D1_15,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_16);
	borrow = _mm512_add_epi64(borrow,D0_16);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_16 = _mm512_add_epi64(D1_16,carry_D1);
	D1_16 = _mm512_add_epi64(D1_16,D0_56);
	carry_D1 = _mm512_srli_epi64(D1_16,52);
	D1_16 = _mm512_and_si512(D1_16,mask52);
	D1_16 = _mm512_sub_epi64(D1_16,borrow);
	borrow  = _mm512_srli_epi64(D1_16,52)&un;
	D1_16 = _mm512_and_si512(D1_16,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_17);
	borrow = _mm512_add_epi64(borrow,D0_17);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_17 = _mm512_add_epi64(D1_17,carry_D1);
	D1_17 = _mm512_add_epi64(D1_17,D0_57);
	carry_D1 = _mm512_srli_epi64(D1_17,52);
	D1_17 = _mm512_and_si512(D1_17,mask52);
	D1_17 = _mm512_sub_epi64(D1_17,borrow);
	borrow  = _mm512_srli_epi64(D1_17,52)&un;
	D1_17 = _mm512_and_si512(D1_17,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_18);
	borrow = _mm512_add_epi64(borrow,D0_18);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_18 = _mm512_add_epi64(D1_18,carry_D1);
	D1_18 = _mm512_add_epi64(D1_18,D0_58);
	carry_D1 = _mm512_srli_epi64(D1_18,52);
	D1_18 = _mm512_and_si512(D1_18,mask52);
	D1_18 = _mm512_sub_epi64(D1_18,borrow);
	borrow  = _mm512_srli_epi64(D1_18,52)&un;
	D1_18 = _mm512_and_si512(D1_18,mask52);

	borrow = _mm512_add_epi64(carry,borrow); // radix 2^1039
	borrow = _mm512_add_epi64(borrow,D2_19);
	borrow = _mm512_add_epi64(borrow,D0_19);
	carry = _mm512_srli_epi64(borrow,51);
	borrow = _mm512_and_si512(borrow,mask51);
	D1_19 = _mm512_add_epi64(D1_19,carry_D1);
	D1_19 = _mm512_add_epi64(D1_19,D0_59);
	carry_D1 = _mm512_srli_epi64(D1_19,51);
	D1_19 = _mm512_and_si512(D1_19,mask51);
	D1_19 = _mm512_sub_epi64(D1_19,borrow);
	borrow  = _mm512_srli_epi64(D1_19,51)&un;
	D1_19 = _mm512_and_si512(D1_19,mask51);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_20);
	borrow = _mm512_add_epi64(borrow,D0_20);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_20 = _mm512_add_epi64(D1_20,carry_D1);
	D1_20 = _mm512_add_epi64(D1_20,D0_60);
	carry_D1 = _mm512_srli_epi64(D1_20,52);
	D1_20 = _mm512_and_si512(D1_20,mask52);
	D1_20 = _mm512_sub_epi64(D1_20,borrow);
	borrow  = _mm512_srli_epi64(D1_20,52)&un;
	D1_20 = _mm512_and_si512(D1_20,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_21);
	borrow = _mm512_add_epi64(borrow,D0_21);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_21 = _mm512_add_epi64(D1_21,carry_D1);
	D1_21 = _mm512_add_epi64(D1_21,D0_61);
	carry_D1 = _mm512_srli_epi64(D1_21,52);
	D1_21 = _mm512_and_si512(D1_21,mask52);
	D1_21 = _mm512_sub_epi64(D1_21,borrow);
	borrow  = _mm512_srli_epi64(D1_21,52)&un;
	D1_21 = _mm512_and_si512(D1_21,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_22);
	borrow = _mm512_add_epi64(borrow,D0_22);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_22 = _mm512_add_epi64(D1_22,carry_D1);
	D1_22 = _mm512_add_epi64(D1_22,D0_62);
	carry_D1 = _mm512_srli_epi64(D1_22,52);
	D1_22 = _mm512_and_si512(D1_22,mask52);
	D1_22 = _mm512_sub_epi64(D1_22,borrow);
	borrow  = _mm512_srli_epi64(D1_22,52)&un;
	D1_22 = _mm512_and_si512(D1_22,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_23);
	borrow = _mm512_add_epi64(borrow,D0_23);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_23 = _mm512_add_epi64(D1_23,carry_D1);
	D1_23 = _mm512_add_epi64(D1_23,D0_63);
	carry_D1 = _mm512_srli_epi64(D1_23,52);
	D1_23 = _mm512_and_si512(D1_23,mask52);
	D1_23 = _mm512_sub_epi64(D1_23,borrow);
	borrow  = _mm512_srli_epi64(D1_23,52)&un;
	D1_23 = _mm512_and_si512(D1_23,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_24);
	borrow = _mm512_add_epi64(borrow,D0_24);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_24 = _mm512_add_epi64(D1_24,carry_D1);
	D1_24 = _mm512_add_epi64(D1_24,D0_64);
	carry_D1 = _mm512_srli_epi64(D1_24,52);
	D1_24 = _mm512_and_si512(D1_24,mask52);
	D1_24 = _mm512_sub_epi64(D1_24,borrow);
	borrow  = _mm512_srli_epi64(D1_24,52)&un;
	D1_24 = _mm512_and_si512(D1_24,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_25);
	borrow = _mm512_add_epi64(borrow,D0_25);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_25 = _mm512_add_epi64(D1_25,carry_D1);
	D1_25 = _mm512_add_epi64(D1_25,D0_65);
	carry_D1 = _mm512_srli_epi64(D1_25,52);
	D1_25 = _mm512_and_si512(D1_25,mask52);
	D1_25 = _mm512_sub_epi64(D1_25,borrow);
	borrow  = _mm512_srli_epi64(D1_25,52)&un;
	D1_25 = _mm512_and_si512(D1_25,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_26);
	borrow = _mm512_add_epi64(borrow,D0_26);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_26 = _mm512_add_epi64(D1_26,carry_D1);
	D1_26 = _mm512_add_epi64(D1_26,D0_66);
	carry_D1 = _mm512_srli_epi64(D1_26,52);
	D1_26 = _mm512_and_si512(D1_26,mask52);
	D1_26 = _mm512_sub_epi64(D1_26,borrow);
	borrow  = _mm512_srli_epi64(D1_26,52)&un;
	D1_26 = _mm512_and_si512(D1_26,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_27);
	borrow = _mm512_add_epi64(borrow,D0_27);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_27 = _mm512_add_epi64(D1_27,carry_D1);
	D1_27 = _mm512_add_epi64(D1_27,D0_67);
	carry_D1 = _mm512_srli_epi64(D1_27,52);
	D1_27 = _mm512_and_si512(D1_27,mask52);
	D1_27 = _mm512_sub_epi64(D1_27,borrow);
	borrow  = _mm512_srli_epi64(D1_27,52)&un;
	D1_27 = _mm512_and_si512(D1_27,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_28);
	borrow = _mm512_add_epi64(borrow,D0_28);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_28 = _mm512_add_epi64(D1_28,carry_D1);
	D1_28 = _mm512_add_epi64(D1_28,D0_68);
	carry_D1 = _mm512_srli_epi64(D1_28,52);
	D1_28 = _mm512_and_si512(D1_28,mask52);
	D1_28 = _mm512_sub_epi64(D1_28,borrow);
	borrow  = _mm512_srli_epi64(D1_28,52)&un;
	D1_28 = _mm512_and_si512(D1_28,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_29);
	borrow = _mm512_add_epi64(borrow,D0_29);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_29 = _mm512_add_epi64(D1_29,carry_D1);
	D1_29 = _mm512_add_epi64(D1_29,D0_69);
	carry_D1 = _mm512_srli_epi64(D1_29,52);
	D1_29 = _mm512_and_si512(D1_29,mask52);
	D1_29 = _mm512_sub_epi64(D1_29,borrow);
	borrow  = _mm512_srli_epi64(D1_29,52)&un;
	D1_29 = _mm512_and_si512(D1_29,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_30);
	borrow = _mm512_add_epi64(borrow,D0_30);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_30 = _mm512_add_epi64(D1_30,carry_D1);
	D1_30 = _mm512_add_epi64(D1_30,D0_70);
	carry_D1 = _mm512_srli_epi64(D1_30,52);
	D1_30 = _mm512_and_si512(D1_30,mask52);
	D1_30 = _mm512_sub_epi64(D1_30,borrow);
	borrow  = _mm512_srli_epi64(D1_30,52)&un;
	D1_30 = _mm512_and_si512(D1_30,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_31);
	borrow = _mm512_add_epi64(borrow,D0_31);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_31 = _mm512_add_epi64(D1_31,carry_D1);
	D1_31 = _mm512_add_epi64(D1_31,D0_71);
	carry_D1 = _mm512_srli_epi64(D1_31,52);
	D1_31 = _mm512_and_si512(D1_31,mask52);
	D1_31 = _mm512_sub_epi64(D1_31,borrow);
	borrow  = _mm512_srli_epi64(D1_31,52)&un;
	D1_31 = _mm512_and_si512(D1_31,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_32);
	borrow = _mm512_add_epi64(borrow,D0_32);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_32 = _mm512_add_epi64(D1_32,carry_D1);
	D1_32 = _mm512_add_epi64(D1_32,D0_72);
	carry_D1 = _mm512_srli_epi64(D1_32,52);
	D1_32 = _mm512_and_si512(D1_32,mask52);
	D1_32 = _mm512_sub_epi64(D1_32,borrow);
	borrow  = _mm512_srli_epi64(D1_32,52)&un;
	D1_32 = _mm512_and_si512(D1_32,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_33);
	borrow = _mm512_add_epi64(borrow,D0_33);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_33 = _mm512_add_epi64(D1_33,carry_D1);
	D1_33 = _mm512_add_epi64(D1_33,D0_73);
	carry_D1 = _mm512_srli_epi64(D1_33,52);
	D1_33 = _mm512_and_si512(D1_33,mask52);
	D1_33 = _mm512_sub_epi64(D1_33,borrow);
	borrow  = _mm512_srli_epi64(D1_33,52)&un;
	D1_33 = _mm512_and_si512(D1_33,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_34);
	borrow = _mm512_add_epi64(borrow,D0_34);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_34 = _mm512_add_epi64(D1_34,carry_D1);
	D1_34 = _mm512_add_epi64(D1_34,D0_74);
	carry_D1 = _mm512_srli_epi64(D1_34,52);
	D1_34 = _mm512_and_si512(D1_34,mask52);
	D1_34 = _mm512_sub_epi64(D1_34,borrow);
	borrow  = _mm512_srli_epi64(D1_34,52)&un;
	D1_34 = _mm512_and_si512(D1_34,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_35);
	borrow = _mm512_add_epi64(borrow,D0_35);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_35 = _mm512_add_epi64(D1_35,carry_D1);
	D1_35 = _mm512_add_epi64(D1_35,D0_75);
	carry_D1 = _mm512_srli_epi64(D1_35,52);
	D1_35 = _mm512_and_si512(D1_35,mask52);
	D1_35 = _mm512_sub_epi64(D1_35,borrow);
	borrow  = _mm512_srli_epi64(D1_35,52)&un;
	D1_35 = _mm512_and_si512(D1_35,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_36);
	borrow = _mm512_add_epi64(borrow,D0_36);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_36 = _mm512_add_epi64(D1_36,carry_D1);
	D1_36 = _mm512_add_epi64(D1_36,D0_76);
	carry_D1 = _mm512_srli_epi64(D1_36,52);
	D1_36 = _mm512_and_si512(D1_36,mask52);
	D1_36 = _mm512_sub_epi64(D1_36,borrow);
	borrow  = _mm512_srli_epi64(D1_36,52)&un;
	D1_36 = _mm512_and_si512(D1_36,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_37);
	borrow = _mm512_add_epi64(borrow,D0_37);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_37 = _mm512_add_epi64(D1_37,carry_D1);
	D1_37 = _mm512_add_epi64(D1_37,D0_77);
	carry_D1 = _mm512_srli_epi64(D1_37,52);
	D1_37 = _mm512_and_si512(D1_37,mask52);
	D1_37 = _mm512_sub_epi64(D1_37,borrow);
	borrow  = _mm512_srli_epi64(D1_37,52)&un;
	D1_37 = _mm512_and_si512(D1_37,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_38);
	borrow = _mm512_add_epi64(borrow,D0_38);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_38 = _mm512_add_epi64(D1_38,carry_D1);
	D1_38 = _mm512_add_epi64(D1_38,D0_78);
	carry_D1 = _mm512_srli_epi64(D1_38,52);
	D1_38 = _mm512_and_si512(D1_38,mask52);
	D1_38 = _mm512_sub_epi64(D1_38,borrow);
	borrow  = _mm512_srli_epi64(D1_38,52)&un;
	D1_38 = _mm512_and_si512(D1_38,mask52);

	borrow = _mm512_add_epi64(carry,borrow); // radix 2^2077
	borrow = _mm512_add_epi64(borrow,D2_39);
	borrow = _mm512_add_epi64(borrow,D0_39);
	carry = _mm512_srli_epi64(borrow,50);
	borrow = _mm512_and_si512(borrow,mask50);
	D1_39 = _mm512_add_epi64(D1_39,carry_D1);
	D1_39 = _mm512_add_epi64(D1_39,D0_79);
	carry_D1 = _mm512_srli_epi64(D1_39,50);
	D1_39 = _mm512_and_si512(D1_39,mask50);
	D1_39 = _mm512_sub_epi64(D1_39,borrow);
	borrow  = _mm512_srli_epi64(D1_39,50)&un;
	D1_39 = _mm512_and_si512(D1_39,mask50);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_40);
	borrow = _mm512_add_epi64(borrow,D0_40);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_40 = _mm512_add_epi64(D1_40,carry_D1);
	D1_40 = _mm512_add_epi64(D1_40,D2_0);
	carry_D1 = _mm512_srli_epi64(D1_40,52);
	D1_40 = _mm512_and_si512(D1_40,mask52);
	D1_40 = _mm512_sub_epi64(D1_40,borrow);
	borrow  = _mm512_srli_epi64(D1_40,52)&un;
	D1_40 = _mm512_and_si512(D1_40,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_41);
	borrow = _mm512_add_epi64(borrow,D0_41);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_41 = _mm512_add_epi64(D1_41,carry_D1);
	D1_41 = _mm512_add_epi64(D1_41,D2_1);
	carry_D1 = _mm512_srli_epi64(D1_41,52);
	D1_41 = _mm512_and_si512(D1_41,mask52);
	D1_41 = _mm512_sub_epi64(D1_41,borrow);
	borrow  = _mm512_srli_epi64(D1_41,52)&un;
	D1_41 = _mm512_and_si512(D1_41,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_42);
	borrow = _mm512_add_epi64(borrow,D0_42);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_42 = _mm512_add_epi64(D1_42,carry_D1);
	D1_42 = _mm512_add_epi64(D1_42,D2_2);
	carry_D1 = _mm512_srli_epi64(D1_42,52);
	D1_42 = _mm512_and_si512(D1_42,mask52);
	D1_42 = _mm512_sub_epi64(D1_42,borrow);
	borrow  = _mm512_srli_epi64(D1_42,52)&un;
	D1_42 = _mm512_and_si512(D1_42,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_43);
	borrow = _mm512_add_epi64(borrow,D0_43);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_43 = _mm512_add_epi64(D1_43,carry_D1);
	D1_43 = _mm512_add_epi64(D1_43,D2_3);
	carry_D1 = _mm512_srli_epi64(D1_43,52);
	D1_43 = _mm512_and_si512(D1_43,mask52);
	D1_43 = _mm512_sub_epi64(D1_43,borrow);
	borrow  = _mm512_srli_epi64(D1_43,52)&un;
	D1_43 = _mm512_and_si512(D1_43,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_44);
	borrow = _mm512_add_epi64(borrow,D0_44);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_44 = _mm512_add_epi64(D1_44,carry_D1);
	D1_44 = _mm512_add_epi64(D1_44,D2_4);
	carry_D1 = _mm512_srli_epi64(D1_44,52);
	D1_44 = _mm512_and_si512(D1_44,mask52);
	D1_44 = _mm512_sub_epi64(D1_44,borrow);
	borrow  = _mm512_srli_epi64(D1_44,52)&un;
	D1_44 = _mm512_and_si512(D1_44,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_45);
	borrow = _mm512_add_epi64(borrow,D0_45);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_45 = _mm512_add_epi64(D1_45,carry_D1);
	D1_45 = _mm512_add_epi64(D1_45,D2_5);
	carry_D1 = _mm512_srli_epi64(D1_45,52);
	D1_45 = _mm512_and_si512(D1_45,mask52);
	D1_45 = _mm512_sub_epi64(D1_45,borrow);
	borrow  = _mm512_srli_epi64(D1_45,52)&un;
	D1_45 = _mm512_and_si512(D1_45,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_46);
	borrow = _mm512_add_epi64(borrow,D0_46);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_46 = _mm512_add_epi64(D1_46,carry_D1);
	D1_46 = _mm512_add_epi64(D1_46,D2_6);
	carry_D1 = _mm512_srli_epi64(D1_46,52);
	D1_46 = _mm512_and_si512(D1_46,mask52);
	D1_46 = _mm512_sub_epi64(D1_46,borrow);
	borrow  = _mm512_srli_epi64(D1_46,52)&un;
	D1_46 = _mm512_and_si512(D1_46,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_47);
	borrow = _mm512_add_epi64(borrow,D0_47);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_47 = _mm512_add_epi64(D1_47,carry_D1);
	D1_47 = _mm512_add_epi64(D1_47,D2_7);
	carry_D1 = _mm512_srli_epi64(D1_47,52);
	D1_47 = _mm512_and_si512(D1_47,mask52);
	D1_47 = _mm512_sub_epi64(D1_47,borrow);
	borrow  = _mm512_srli_epi64(D1_47,52)&un;
	D1_47 = _mm512_and_si512(D1_47,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_48);
	borrow = _mm512_add_epi64(borrow,D0_48);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_48 = _mm512_add_epi64(D1_48,carry_D1);
	D1_48 = _mm512_add_epi64(D1_48,D2_8);
	carry_D1 = _mm512_srli_epi64(D1_48,52);
	D1_48 = _mm512_and_si512(D1_48,mask52);
	D1_48 = _mm512_sub_epi64(D1_48,borrow);
	borrow  = _mm512_srli_epi64(D1_48,52)&un;
	D1_48 = _mm512_and_si512(D1_48,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_49);
	borrow = _mm512_add_epi64(borrow,D0_49);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_49 = _mm512_add_epi64(D1_49,carry_D1);
	D1_49 = _mm512_add_epi64(D1_49,D2_9);
	carry_D1 = _mm512_srli_epi64(D1_49,52);
	D1_49 = _mm512_and_si512(D1_49,mask52);
	D1_49 = _mm512_sub_epi64(D1_49,borrow);
	borrow  = _mm512_srli_epi64(D1_49,52)&un;
	D1_49 = _mm512_and_si512(D1_49,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_50);
	borrow = _mm512_add_epi64(borrow,D0_50);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_50 = _mm512_add_epi64(D1_50,carry_D1);
	D1_50 = _mm512_add_epi64(D1_50,D2_10);
	carry_D1 = _mm512_srli_epi64(D1_50,52);
	D1_50 = _mm512_and_si512(D1_50,mask52);
	D1_50 = _mm512_sub_epi64(D1_50,borrow);
	borrow  = _mm512_srli_epi64(D1_50,52)&un;
	D1_50 = _mm512_and_si512(D1_50,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_51);
	borrow = _mm512_add_epi64(borrow,D0_51);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_51 = _mm512_add_epi64(D1_51,carry_D1);
	D1_51 = _mm512_add_epi64(D1_51,D2_11);
	carry_D1 = _mm512_srli_epi64(D1_51,52);
	D1_51 = _mm512_and_si512(D1_51,mask52);
	D1_51 = _mm512_sub_epi64(D1_51,borrow);
	borrow  = _mm512_srli_epi64(D1_51,52)&un;
	D1_51 = _mm512_and_si512(D1_51,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_52);
	borrow = _mm512_add_epi64(borrow,D0_52);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_52 = _mm512_add_epi64(D1_52,carry_D1);
	D1_52 = _mm512_add_epi64(D1_52,D2_12);
	carry_D1 = _mm512_srli_epi64(D1_52,52);
	D1_52 = _mm512_and_si512(D1_52,mask52);
	D1_52 = _mm512_sub_epi64(D1_52,borrow);
	borrow  = _mm512_srli_epi64(D1_52,52)&un;
	D1_52 = _mm512_and_si512(D1_52,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_53);
	borrow = _mm512_add_epi64(borrow,D0_53);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_53 = _mm512_add_epi64(D1_53,carry_D1);
	D1_53 = _mm512_add_epi64(D1_53,D2_13);
	carry_D1 = _mm512_srli_epi64(D1_53,52);
	D1_53 = _mm512_and_si512(D1_53,mask52);
	D1_53 = _mm512_sub_epi64(D1_53,borrow);
	borrow  = _mm512_srli_epi64(D1_53,52)&un;
	D1_53 = _mm512_and_si512(D1_53,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_54);
	borrow = _mm512_add_epi64(borrow,D0_54);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_54 = _mm512_add_epi64(D1_54,carry_D1);
	D1_54 = _mm512_add_epi64(D1_54,D2_14);
	carry_D1 = _mm512_srli_epi64(D1_54,52);
	D1_54 = _mm512_and_si512(D1_54,mask52);
	D1_54 = _mm512_sub_epi64(D1_54,borrow);
	borrow  = _mm512_srli_epi64(D1_54,52)&un;
	D1_54 = _mm512_and_si512(D1_54,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_55);
	borrow = _mm512_add_epi64(borrow,D0_55);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_55 = _mm512_add_epi64(D1_55,carry_D1);
	D1_55 = _mm512_add_epi64(D1_55,D2_15);
	carry_D1 = _mm512_srli_epi64(D1_55,52);
	D1_55 = _mm512_and_si512(D1_55,mask52);
	D1_55 = _mm512_sub_epi64(D1_55,borrow);
	borrow  = _mm512_srli_epi64(D1_55,52)&un;
	D1_55 = _mm512_and_si512(D1_55,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_56);
	borrow = _mm512_add_epi64(borrow,D0_56);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_56 = _mm512_add_epi64(D1_56,carry_D1);
	D1_56 = _mm512_add_epi64(D1_56,D2_16);
	carry_D1 = _mm512_srli_epi64(D1_56,52);
	D1_56 = _mm512_and_si512(D1_56,mask52);
	D1_56 = _mm512_sub_epi64(D1_56,borrow);
	borrow  = _mm512_srli_epi64(D1_56,52)&un;
	D1_56 = _mm512_and_si512(D1_56,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_57);
	borrow = _mm512_add_epi64(borrow,D0_57);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_57 = _mm512_add_epi64(D1_57,carry_D1);
	D1_57 = _mm512_add_epi64(D1_57,D2_17);
	carry_D1 = _mm512_srli_epi64(D1_57,52);
	D1_57 = _mm512_and_si512(D1_57,mask52);
	D1_57 = _mm512_sub_epi64(D1_57,borrow);
	borrow  = _mm512_srli_epi64(D1_57,52)&un;
	D1_57 = _mm512_and_si512(D1_57,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_58);
	borrow = _mm512_add_epi64(borrow,D0_58);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_58 = _mm512_add_epi64(D1_58,carry_D1);
	D1_58 = _mm512_add_epi64(D1_58,D2_18);
	carry_D1 = _mm512_srli_epi64(D1_58,52);
	D1_58 = _mm512_and_si512(D1_58,mask52);
	D1_58 = _mm512_sub_epi64(D1_58,borrow);
	borrow  = _mm512_srli_epi64(D1_58,52)&un;
	D1_58 = _mm512_and_si512(D1_58,mask52);

	borrow = _mm512_add_epi64(carry,borrow); // radix 2^1039
	borrow = _mm512_add_epi64(borrow,D2_59);
	borrow = _mm512_add_epi64(borrow,D0_59);
	carry = _mm512_srli_epi64(borrow,51);
	borrow = _mm512_and_si512(borrow,mask51);
	D1_59 = _mm512_add_epi64(D1_59,carry_D1);
	D1_59 = _mm512_add_epi64(D1_59,D2_19);
	carry_D1 = _mm512_srli_epi64(D1_59,51);
	D1_59 = _mm512_and_si512(D1_59,mask51);
	D1_59 = _mm512_sub_epi64(D1_59,borrow);
	borrow  = _mm512_srli_epi64(D1_59,51)&un;
	D1_59 = _mm512_and_si512(D1_59,mask51);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_60);
	borrow = _mm512_add_epi64(borrow,D0_60);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_60 = _mm512_add_epi64(D1_60,carry_D1);
	D1_60 = _mm512_add_epi64(D1_60,D2_20);
	carry_D1 = _mm512_srli_epi64(D1_60,52);
	D1_60 = _mm512_and_si512(D1_60,mask52);
	D1_60 = _mm512_sub_epi64(D1_60,borrow);
	borrow  = _mm512_srli_epi64(D1_60,52)&un;
	D1_60 = _mm512_and_si512(D1_60,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_61);
	borrow = _mm512_add_epi64(borrow,D0_61);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_61 = _mm512_add_epi64(D1_61,carry_D1);
	D1_61 = _mm512_add_epi64(D1_61,D2_21);
	carry_D1 = _mm512_srli_epi64(D1_61,52);
	D1_61 = _mm512_and_si512(D1_61,mask52);
	D1_61 = _mm512_sub_epi64(D1_61,borrow);
	borrow  = _mm512_srli_epi64(D1_61,52)&un;
	D1_61 = _mm512_and_si512(D1_61,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_62);
	borrow = _mm512_add_epi64(borrow,D0_62);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_62 = _mm512_add_epi64(D1_62,carry_D1);
	D1_62 = _mm512_add_epi64(D1_62,D2_22);
	carry_D1 = _mm512_srli_epi64(D1_62,52);
	D1_62 = _mm512_and_si512(D1_62,mask52);
	D1_62 = _mm512_sub_epi64(D1_62,borrow);
	borrow  = _mm512_srli_epi64(D1_62,52)&un;
	D1_62 = _mm512_and_si512(D1_62,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_63);
	borrow = _mm512_add_epi64(borrow,D0_63);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_63 = _mm512_add_epi64(D1_63,carry_D1);
	D1_63 = _mm512_add_epi64(D1_63,D2_23);
	carry_D1 = _mm512_srli_epi64(D1_63,52);
	D1_63 = _mm512_and_si512(D1_63,mask52);
	D1_63 = _mm512_sub_epi64(D1_63,borrow);
	borrow  = _mm512_srli_epi64(D1_63,52)&un;
	D1_63 = _mm512_and_si512(D1_63,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_64);
	borrow = _mm512_add_epi64(borrow,D0_64);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_64 = _mm512_add_epi64(D1_64,carry_D1);
	D1_64 = _mm512_add_epi64(D1_64,D2_24);
	carry_D1 = _mm512_srli_epi64(D1_64,52);
	D1_64 = _mm512_and_si512(D1_64,mask52);
	D1_64 = _mm512_sub_epi64(D1_64,borrow);
	borrow  = _mm512_srli_epi64(D1_64,52)&un;
	D1_64 = _mm512_and_si512(D1_64,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_65);
	borrow = _mm512_add_epi64(borrow,D0_65);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_65 = _mm512_add_epi64(D1_65,carry_D1);
	D1_65 = _mm512_add_epi64(D1_65,D2_25);
	carry_D1 = _mm512_srli_epi64(D1_65,52);
	D1_65 = _mm512_and_si512(D1_65,mask52);
	D1_65 = _mm512_sub_epi64(D1_65,borrow);
	borrow  = _mm512_srli_epi64(D1_65,52)&un;
	D1_65 = _mm512_and_si512(D1_65,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_66);
	borrow = _mm512_add_epi64(borrow,D0_66);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_66 = _mm512_add_epi64(D1_66,carry_D1);
	D1_66 = _mm512_add_epi64(D1_66,D2_26);
	carry_D1 = _mm512_srli_epi64(D1_66,52);
	D1_66 = _mm512_and_si512(D1_66,mask52);
	D1_66 = _mm512_sub_epi64(D1_66,borrow);
	borrow  = _mm512_srli_epi64(D1_66,52)&un;
	D1_66 = _mm512_and_si512(D1_66,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_67);
	borrow = _mm512_add_epi64(borrow,D0_67);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_67 = _mm512_add_epi64(D1_67,carry_D1);
	D1_67 = _mm512_add_epi64(D1_67,D2_27);
	carry_D1 = _mm512_srli_epi64(D1_67,52);
	D1_67 = _mm512_and_si512(D1_67,mask52);
	D1_67 = _mm512_sub_epi64(D1_67,borrow);
	borrow  = _mm512_srli_epi64(D1_67,52)&un;
	D1_67 = _mm512_and_si512(D1_67,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_68);
	borrow = _mm512_add_epi64(borrow,D0_68);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_68 = _mm512_add_epi64(D1_68,carry_D1);
	D1_68 = _mm512_add_epi64(D1_68,D2_28);
	carry_D1 = _mm512_srli_epi64(D1_68,52);
	D1_68 = _mm512_and_si512(D1_68,mask52);
	D1_68 = _mm512_sub_epi64(D1_68,borrow);
	borrow  = _mm512_srli_epi64(D1_68,52)&un;
	D1_68 = _mm512_and_si512(D1_68,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_69);
	borrow = _mm512_add_epi64(borrow,D0_69);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_69 = _mm512_add_epi64(D1_69,carry_D1);
	D1_69 = _mm512_add_epi64(D1_69,D2_29);
	carry_D1 = _mm512_srli_epi64(D1_69,52);
	D1_69 = _mm512_and_si512(D1_69,mask52);
	D1_69 = _mm512_sub_epi64(D1_69,borrow);
	borrow  = _mm512_srli_epi64(D1_69,52)&un;
	D1_69 = _mm512_and_si512(D1_69,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_70);
	borrow = _mm512_add_epi64(borrow,D0_70);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_70 = _mm512_add_epi64(D1_70,carry_D1);
	D1_70 = _mm512_add_epi64(D1_70,D2_30);
	carry_D1 = _mm512_srli_epi64(D1_70,52);
	D1_70 = _mm512_and_si512(D1_70,mask52);
	D1_70 = _mm512_sub_epi64(D1_70,borrow);
	borrow  = _mm512_srli_epi64(D1_70,52)&un;
	D1_70 = _mm512_and_si512(D1_70,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_71);
	borrow = _mm512_add_epi64(borrow,D0_71);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_71 = _mm512_add_epi64(D1_71,carry_D1);
	D1_71 = _mm512_add_epi64(D1_71,D2_31);
	carry_D1 = _mm512_srli_epi64(D1_71,52);
	D1_71 = _mm512_and_si512(D1_71,mask52);
	D1_71 = _mm512_sub_epi64(D1_71,borrow);
	borrow  = _mm512_srli_epi64(D1_71,52)&un;
	D1_71 = _mm512_and_si512(D1_71,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_72);
	borrow = _mm512_add_epi64(borrow,D0_72);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_72 = _mm512_add_epi64(D1_72,carry_D1);
	D1_72 = _mm512_add_epi64(D1_72,D2_32);
	carry_D1 = _mm512_srli_epi64(D1_72,52);
	D1_72 = _mm512_and_si512(D1_72,mask52);
	D1_72 = _mm512_sub_epi64(D1_72,borrow);
	borrow  = _mm512_srli_epi64(D1_72,52)&un;
	D1_72 = _mm512_and_si512(D1_72,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_73);
	borrow = _mm512_add_epi64(borrow,D0_73);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_73 = _mm512_add_epi64(D1_73,carry_D1);
	D1_73 = _mm512_add_epi64(D1_73,D2_33);
	carry_D1 = _mm512_srli_epi64(D1_73,52);
	D1_73 = _mm512_and_si512(D1_73,mask52);
	D1_73 = _mm512_sub_epi64(D1_73,borrow);
	borrow  = _mm512_srli_epi64(D1_73,52)&un;
	D1_73 = _mm512_and_si512(D1_73,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_74);
	borrow = _mm512_add_epi64(borrow,D0_74);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_74 = _mm512_add_epi64(D1_74,carry_D1);
	D1_74 = _mm512_add_epi64(D1_74,D2_34);
	carry_D1 = _mm512_srli_epi64(D1_74,52);
	D1_74 = _mm512_and_si512(D1_74,mask52);
	D1_74 = _mm512_sub_epi64(D1_74,borrow);
	borrow  = _mm512_srli_epi64(D1_74,52)&un;
	D1_74 = _mm512_and_si512(D1_74,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_75);
	borrow = _mm512_add_epi64(borrow,D0_75);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_75 = _mm512_add_epi64(D1_75,carry_D1);
	D1_75 = _mm512_add_epi64(D1_75,D2_35);
	carry_D1 = _mm512_srli_epi64(D1_75,52);
	D1_75 = _mm512_and_si512(D1_75,mask52);
	D1_75 = _mm512_sub_epi64(D1_75,borrow);
	borrow  = _mm512_srli_epi64(D1_75,52)&un;
	D1_75 = _mm512_and_si512(D1_75,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_76);
	borrow = _mm512_add_epi64(borrow,D0_76);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_76 = _mm512_add_epi64(D1_76,carry_D1);
	D1_76 = _mm512_add_epi64(D1_76,D2_36);
	carry_D1 = _mm512_srli_epi64(D1_76,52);
	D1_76 = _mm512_and_si512(D1_76,mask52);
	D1_76 = _mm512_sub_epi64(D1_76,borrow);
	borrow  = _mm512_srli_epi64(D1_76,52)&un;
	D1_76 = _mm512_and_si512(D1_76,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_77);
	borrow = _mm512_add_epi64(borrow,D0_77);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_77 = _mm512_add_epi64(D1_77,carry_D1);
	D1_77 = _mm512_add_epi64(D1_77,D2_37);
	carry_D1 = _mm512_srli_epi64(D1_77,52);
	D1_77 = _mm512_and_si512(D1_77,mask52);
	D1_77 = _mm512_sub_epi64(D1_77,borrow);
	borrow  = _mm512_srli_epi64(D1_77,52)&un;
	D1_77 = _mm512_and_si512(D1_77,mask52);

	borrow = _mm512_add_epi64(carry,borrow);
	borrow = _mm512_add_epi64(borrow,D2_78);
	borrow = _mm512_add_epi64(borrow,D0_78);
	carry = _mm512_srli_epi64(borrow,52);
	borrow = _mm512_and_si512(borrow,mask52);
	D1_78 = _mm512_add_epi64(D1_78,carry_D1);
	D1_78 = _mm512_add_epi64(D1_78,D2_38);
	carry_D1 = _mm512_srli_epi64(D1_78,52);
	D1_78 = _mm512_and_si512(D1_78,mask52);
	D1_78 = _mm512_sub_epi64(D1_78,borrow);
	borrow  = _mm512_srli_epi64(D1_78,52)&un;
	D1_78 = _mm512_and_si512(D1_78,mask52);

	borrow = _mm512_add_epi64(carry,borrow); // radix 2^2077
	borrow = _mm512_add_epi64(borrow,D2_79);
	borrow = _mm512_add_epi64(borrow,D0_79);
	carry = _mm512_srli_epi64(borrow,50);
	borrow = _mm512_and_si512(borrow,mask50);
	D1_79 = _mm512_add_epi64(D1_79,carry_D1);
	D1_79 = _mm512_add_epi64(D1_79,D2_39);
	carry_D1 = _mm512_srli_epi64(D1_79,50);
	D1_79 = _mm512_and_si512(D1_79,mask50);
	D1_79 = _mm512_sub_epi64(D1_79,borrow);
	borrow  = _mm512_srli_epi64(D1_79,50)&un;
	D1_79 = _mm512_and_si512(D1_79,mask50);


	// Final borrows
	D2_40 = _mm512_add_epi64(D2_40,carry_D1);
	
	borrow = _mm512_add_epi64(carry,borrow);
	D2_40 = _mm512_sub_epi64(D2_40,borrow);
	//borrow  = _mm512_srli_epi64(D2_40,52)&un;
	D2_40 = _mm512_and_si512(D2_40,mask52);//*/
	
	
	

	/*borrow = _mm512_add_epi64(carry_tmp,borrow);
	D2_40 = _mm512_add_epi64(D2_40,carry);
	D2_40 = _mm512_sub_epi64(D2_40,borrow);
	borrow  = _mm512_srli_epi64(D2_40,52)&un;
	D2_40 = _mm512_and_si512(D2_40,mask52);*/







	
	//borrow  = _mm512_srli_epi64(out_44,52)&un;
	//out_44 = _mm512_and_si512(out_44,mask52);
	
	
	

	
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
	_mm512_store_epi64(out+10,D0_10);
	_mm512_store_epi64(out+11,D0_11);
	_mm512_store_epi64(out+12,D0_12);
	_mm512_store_epi64(out+13,D0_13);
	_mm512_store_epi64(out+14,D0_14);
	_mm512_store_epi64(out+15,D0_15);
	_mm512_store_epi64(out+16,D0_16);
	_mm512_store_epi64(out+17,D0_17);
	_mm512_store_epi64(out+18,D0_18);
	_mm512_store_epi64(out+19,D0_19);
	_mm512_store_epi64(out+20,D0_20);
	_mm512_store_epi64(out+21,D0_21);
	_mm512_store_epi64(out+22,D0_22);
	_mm512_store_epi64(out+23,D0_23);
	_mm512_store_epi64(out+24,D0_24);
	_mm512_store_epi64(out+25,D0_25);
	_mm512_store_epi64(out+26,D0_26);
	_mm512_store_epi64(out+27,D0_27);
	_mm512_store_epi64(out+28,D0_28);
	_mm512_store_epi64(out+29,D0_29);
	_mm512_store_epi64(out+30,D0_30);
	_mm512_store_epi64(out+31,D0_31);
	_mm512_store_epi64(out+32,D0_32);
	_mm512_store_epi64(out+33,D0_33);
	_mm512_store_epi64(out+34,D0_34);
	_mm512_store_epi64(out+35,D0_35);
	_mm512_store_epi64(out+36,D0_36);
	_mm512_store_epi64(out+37,D0_37);
	_mm512_store_epi64(out+38,D0_38);
	_mm512_store_epi64(out+39,D0_39);
	_mm512_store_epi64(out+40,D1_0);
	_mm512_store_epi64(out+41,D1_1);
	_mm512_store_epi64(out+42,D1_2);
	_mm512_store_epi64(out+43,D1_3);
	_mm512_store_epi64(out+44,D1_4);
	_mm512_store_epi64(out+45,D1_5);
	_mm512_store_epi64(out+46,D1_6);
	_mm512_store_epi64(out+47,D1_7);
	_mm512_store_epi64(out+48,D1_8);
	_mm512_store_epi64(out+49,D1_9);
	_mm512_store_epi64(out+50,D1_10);
	_mm512_store_epi64(out+51,D1_11);
	_mm512_store_epi64(out+52,D1_12);
	_mm512_store_epi64(out+53,D1_13);
	_mm512_store_epi64(out+54,D1_14);
	_mm512_store_epi64(out+55,D1_15);
	_mm512_store_epi64(out+56,D1_16);
	_mm512_store_epi64(out+57,D1_17);
	_mm512_store_epi64(out+58,D1_18);
	_mm512_store_epi64(out+59,D1_19);
	_mm512_store_epi64(out+60,D1_20);
	_mm512_store_epi64(out+61,D1_21);
	_mm512_store_epi64(out+62,D1_22);
	_mm512_store_epi64(out+63,D1_23);
	_mm512_store_epi64(out+64,D1_24);
	_mm512_store_epi64(out+65,D1_25);
	_mm512_store_epi64(out+66,D1_26);
	_mm512_store_epi64(out+67,D1_27);
	_mm512_store_epi64(out+68,D1_28);
	_mm512_store_epi64(out+69,D1_29);
	_mm512_store_epi64(out+70,D1_30);
	_mm512_store_epi64(out+71,D1_31);
	_mm512_store_epi64(out+72,D1_32);
	_mm512_store_epi64(out+73,D1_33);
	_mm512_store_epi64(out+74,D1_34);
	_mm512_store_epi64(out+75,D1_35);
	_mm512_store_epi64(out+76,D1_36);
	_mm512_store_epi64(out+77,D1_37);
	_mm512_store_epi64(out+78,D1_38);
	_mm512_store_epi64(out+79,D1_39);





	_mm512_store_epi64(out+80,D1_40);
	_mm512_store_epi64(out+81,D1_41);
	_mm512_store_epi64(out+82,D1_42);
	_mm512_store_epi64(out+83,D1_43);
	_mm512_store_epi64(out+84,D1_44);
	_mm512_store_epi64(out+85,D1_45);
	_mm512_store_epi64(out+86,D1_46);
	_mm512_store_epi64(out+87,D1_47);
	_mm512_store_epi64(out+88,D1_48);
	_mm512_store_epi64(out+89,D1_49);
	_mm512_store_epi64(out+90,D1_50);
	_mm512_store_epi64(out+91,D1_51);
	_mm512_store_epi64(out+92,D1_52);
	_mm512_store_epi64(out+93,D1_53);
	_mm512_store_epi64(out+94,D1_54);
	_mm512_store_epi64(out+95,D1_55);
	_mm512_store_epi64(out+96,D1_56);
	_mm512_store_epi64(out+97,D1_57);
	_mm512_store_epi64(out+98,D1_58);
	_mm512_store_epi64(out+99,D1_59);
	_mm512_store_epi64(out+100,D1_60);
	_mm512_store_epi64(out+101,D1_61);
	_mm512_store_epi64(out+102,D1_62);
	_mm512_store_epi64(out+103,D1_63);
	_mm512_store_epi64(out+104,D1_64);
	_mm512_store_epi64(out+105,D1_65);
	_mm512_store_epi64(out+106,D1_66);
	_mm512_store_epi64(out+107,D1_67);
	_mm512_store_epi64(out+108,D1_68);
	_mm512_store_epi64(out+109,D1_69);
	_mm512_store_epi64(out+110,D1_70);
	_mm512_store_epi64(out+111,D1_71);
	_mm512_store_epi64(out+112,D1_72);
	_mm512_store_epi64(out+113,D1_73);
	_mm512_store_epi64(out+114,D1_74);
	_mm512_store_epi64(out+115,D1_75);
	_mm512_store_epi64(out+116,D1_76);
	_mm512_store_epi64(out+117,D1_77);
	_mm512_store_epi64(out+118,D1_78);
	_mm512_store_epi64(out+119,D1_79);//*/
	_mm512_store_epi64(out+120,D2_40);
	_mm512_store_epi64(out+121,D2_41);
	_mm512_store_epi64(out+122,D2_42);
	_mm512_store_epi64(out+123,D2_43);
	_mm512_store_epi64(out+124,D2_44);
	_mm512_store_epi64(out+125,D2_45);
	_mm512_store_epi64(out+126,D2_46);
	_mm512_store_epi64(out+127,D2_47);
	_mm512_store_epi64(out+128,D2_48);
	_mm512_store_epi64(out+129,D2_49);
	_mm512_store_epi64(out+130,D2_50);
	_mm512_store_epi64(out+131,D2_51);
	_mm512_store_epi64(out+132,D2_52);
	_mm512_store_epi64(out+133,D2_53);
	_mm512_store_epi64(out+134,D2_54);
	_mm512_store_epi64(out+135,D2_55);
	_mm512_store_epi64(out+136,D2_56);
	_mm512_store_epi64(out+137,D2_57);
	_mm512_store_epi64(out+138,D2_58);
	_mm512_store_epi64(out+139,D2_59);
	_mm512_store_epi64(out+140,D2_60);
	_mm512_store_epi64(out+141,D2_61);
	_mm512_store_epi64(out+142,D2_62);
	_mm512_store_epi64(out+143,D2_63);
	_mm512_store_epi64(out+144,D2_64);
	_mm512_store_epi64(out+145,D2_65);
	_mm512_store_epi64(out+146,D2_66);
	_mm512_store_epi64(out+147,D2_67);
	_mm512_store_epi64(out+148,D2_68);
	_mm512_store_epi64(out+149,D2_69);
	_mm512_store_epi64(out+150,D2_70);
	_mm512_store_epi64(out+151,D2_71);
	_mm512_store_epi64(out+152,D2_72);
	_mm512_store_epi64(out+153,D2_73);
	_mm512_store_epi64(out+154,D2_74);
	_mm512_store_epi64(out+155,D2_75);
	_mm512_store_epi64(out+156,D2_76);
	_mm512_store_epi64(out+157,D2_77);
	_mm512_store_epi64(out+158,D2_78);
	_mm512_store_epi64(out+159,D2_79);

	/*
	unsigned long int a64_full[8][NB_COEFF64], b64_full[8][NB_COEFF64], res64_full[8][NB_COEFF64*2], res_gmp_full[NB_COEFF64*2];
	fcontract_8_512_4154KK_res(res64_full, out);
	//for(int i=0;i<8;i++)
	//		displayVect(res64_full[i],"res64[i]    ",NB_COEFF64*2);

	fcontract_8_512_4154KK(a64_full, a512);
	
	fcontract_8_512_4154KK(b64_full, b512);
	
	
	
	for(int i=0;i<8;i++)
	{

		mpz_import(A, NB_COEFF64, -1, sizeof(b64[0][0]) ,0,0, a64_full[i]);

		mpz_import(B, NB_COEFF64, -1, sizeof(b64[0][0]) ,0,0, b64_full[i]);
		
		gmp_printf("A  : 0x%ZX\n", A);

		displayVect(a64_full[i],"a64",65);
		printf("\n\n");
		
		gmp_printf("B  : 0x%ZX\n", B);
		displayVect(b64_full[i],"b64",65);
		printf("\n\n");
		
		
	
	
		mpz_mul(C,A,B);
		mpz_export(res_gmp_full, &countp, -1, sizeof(b64[0][0]) ,0,0, C);
		displayVect(res_gmp_full, "res_gmp     ",NB_COEFF64*2);
		displayVect(res64_full[i],"res64[i]    ",NB_COEFF64*2);
		
		
		printf("xor = ");
		for(int j=0;j<NB_COEFF64*2;j++){
			printf("%16.16lX ",res64_full[i][NB_COEFF64*2-1-j]^res_gmp_full[NB_COEFF64*2-1-j]);
		}
		printf("\n");

	//}
	//printf("\n");
	
	//for(int i=0;i<8;i++){//
		for(int j=0;j<NB_COEFF64*2;j++)
			if(res64_full[i][j]^res_gmp_full[j]) flag++;
		flag?counter++,flag=0:counter,flag=0;
		printf("\n");
	}
	if(counter) printf("%d erreurs !\nToo bad !!!!!!!!!!!!!!!!!!!\n\n",counter),counter=0;
	else printf("Victory a*b !!!!!!!!!!!!!!!!!!!\n\n");
	counter=0;

	mpz_clears (A, B, C, NULL);

	//getchar();//*/
	



}

#include "K2_512_4154_modM.c"

#include "TruncatedK2_512_4154.c"


