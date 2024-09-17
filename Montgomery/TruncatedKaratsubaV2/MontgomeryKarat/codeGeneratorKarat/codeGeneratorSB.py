#!/usr/bin/python3

from math import ceil

'''

Code generator for Karatsuba batch Montgomery multiplications, using avx512 IFMA52.

'''

for SIZE in {206,518,1038,2078,4158}:#,1040,2080,4160,8320}:#{260}:#

	line = "sb512_"+str(SIZE)+".c"
	f=open(line,"w")

	f.write("/* Karatsuba multiplication mod M*/\n\n")

	t=ceil(SIZE/52)
	tk=ceil(t/2)
	split=SIZE//2
	print("t =",t,tk, split)

	'''
		Multiplication generation
	'''


	line = "inline void force_inline mul512_8_"+str(SIZE)+"K_modM(__m512i out["+str(2*t)+"], __m512i a512["+str(t)+"], __m512i b512["+str(t)+"])\n{\n"

	print(line)
	f.write(line)
	
	line = "\n\t// D0 = Al*Bl\n\n"
	f.write(line)
	
	
	for i in range(tk):
		line = "\t__m512i D0_"+str(2*i)+", D0_"+str(2*i+1)+";\n"#, D1_"+str(2*i)+", D1_"+str(2*i+1)+", D2_"+str(2*i)+", D2_"+str(2*i+1)+";\n"
		f.write(line)
		
	line = "\t__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512);\n"
	f.write(line)
	for i in range(1,tk):
		line = "\t__m512i a512"+str(i)+" = _mm512_load_epi64(a512+"+str(i)+"), b512"+str(i)+" = _mm512_load_epi64(b512+"+str(i)+");\n"
		f.write(line)
		
		
	line = "\tD0_0 = _mm512_madd52lo_epu64(zero,a5120,b5120);\n"
	f.write(line)
	line = "\tD0_1 = _mm512_madd52hi_epu64(zero,a5120,b5120);\n"
	f.write(line)
	
	for j in range(1,tk):
		line = "\tD0_"+str(j)+" = _mm512_madd52lo_epu64(D0_"+str(j)+",a5120,b512"+str(j)+");\n"
		f.write(line)
		line = "\tD0_"+str(j+1)+" = _mm512_madd52hi_epu64(zero,a5120,b512"+str(j)+");\n"
		f.write(line)
	f.write("\n")
		
		
	for i in range(1,tk):
		for j in range(tk-1):
			line="\tD0_"+str(i+j)+" = _mm512_madd52lo_epu64(D0_"+str(i+j)+",a512"+str(i)+",b512"+str(j)+");\n"
			#print(line)
			f.write(line)
			line="\tD0_"+str(i+j+1)+" = _mm512_madd52hi_epu64(D0_"+str(i+j+1)+",a512"+str(i)+",b512"+str(j)+");\n"
			#print(line)
			f.write(line)
		
		line="\tD0_"+str(i+tk-1)+" = _mm512_madd52lo_epu64(D0_"+str(i+tk-1)+",a512"+str(i)+",b512"+str(tk-1)+");\n"
		#print(line)
		f.write(line)
		line="\tD0_"+str(i+tk)+" = _mm512_madd52hi_epu64(zero,a512"+str(i)+",b512"+str(tk-1)+");\n"
		#print(line)
		f.write(line)
		f.write("\n")
	
		
	f.write("\n\t// Carry management\n\n")
		
	line="\t__m512i carry  = _mm512_srli_epi64(D0_1,52);\n"
	f.write(line)
	line="\tD0_2 = _mm512_add_epi64(D0_2,carry);\n"
	f.write(line)
	line="\tD0_1 = _mm512_and_si512(D0_1,mask52);\n"
	f.write(line)
	for i in range(3,2*tk-1):
		line="\tcarry  = _mm512_srli_epi64(D0_"+str(i-1)+",52);\n"
		f.write(line)
		line="\tD0_"+str(i)+" = _mm512_add_epi64(D0_"+str(i)+",carry);\n"
		f.write(line)
		line="\tD0_"+str(i-1)+" = _mm512_and_si512(D0_"+str(i-1)+",mask52);\n"
		f.write(line)
	line="\tcarry  = _mm512_srli_epi64(D0_"+str(2*tk-2)+",52);\n"
	f.write(line)
	line="\tD0_"+str(2*tk-1)+" = _mm512_add_epi64(D0_"+str(2*tk-1)+",carry);\n"
	f.write(line)
	line="\tD0_"+str(2*tk-2)+" = _mm512_and_si512(D0_"+str(2*tk-2)+",mask52);\n"
	f.write(line)
	
		
	f.write("\n\t// Conversion in base 2^"+str(split)+"\n\n")

	line = "\tcarry = D0_"+str(tk-1)+">>51;\n"
	f.write(line)
	line = "\tD0_"+str(tk)+" = (D0_"+str(tk)+"<<1)|carry;\n"
	f.write(line)
	line = "\tD0_"+str(tk-1)+" &= mask51;\n"
	f.write(line)
	for i in range(tk,tk*2-1):
		line = "\tcarry = D0_"+str(i)+">>52;\n"
		f.write(line)
		line = "\tD0_"+str(i+1)+" = (D0_"+str(i+1)+"<<1)|carry;\n"
		f.write(line)
		line = "\tD0_"+str(i)+" &= mask52;\n"
		f.write(line)
		

	
	line = "\n\t// D2 = Ah*Bh\n\n"
	f.write(line)
	
	
	for i in range(tk):
		line = "\t__m512i D2_"+str(i)+";\n"#, D1_"+str(2*i)+", D1_"+str(2*i+1)+", D2_"+str(2*i)+", D2_"+str(2*i+1)+";\n"
		f.write(line)
		
	line = "\t__m512i a512"+str(tk)+" = _mm512_load_epi64(a512+"+str(tk)+"), b512"+str(tk)+" = _mm512_load_epi64(b512+"+str(tk)+");\n"
	f.write(line)
	
	
	for i in range(tk+1,tk*2):
		line = "\t__m512i a512"+str(i)+" = _mm512_load_epi64(a512+"+str(i)+"), b512"+str(i)+" = _mm512_load_epi64(b512+"+str(i)+");\n"
		f.write(line)
	line = "\tD2_0 = _mm512_madd52lo_epu64(zero,a512"+str(tk)+",b512"+str(tk)+");\n"
	f.write(line)
	line = "\tD2_1 = _mm512_madd52hi_epu64(zero,a512"+str(tk)+",b512"+str(tk)+");\n"
	f.write(line)
	
	for j in range(1,tk):
		line = "\tD2_"+str(j)+" = _mm512_madd52lo_epu64(D2_"+str(j)+",a512"+str(tk)+",b512"+str(j+tk)+");\n"
		f.write(line)
		if j+1<tk:
			line = "\tD2_"+str(j+1)+" = _mm512_madd52hi_epu64(zero,a512"+str(tk)+",b512"+str(j+tk)+");\n"
			f.write(line)
	f.write("\n")
		
		
	for i in range(1,tk):
		for j in range(tk-1):
			if i+j<tk:
				line="\tD2_"+str(i+j)+" = _mm512_madd52lo_epu64(D2_"+str(i+j)+",a512"+str(i+tk)+",b512"+str(j+tk)+");\n"
				#print(line)
				f.write(line)
			if i+j+1<tk:
				line="\tD2_"+str(i+j+1)+" = _mm512_madd52hi_epu64(D2_"+str(i+j+1)+",a512"+str(i+tk)+",b512"+str(j+tk)+");\n"
				#print(line)
				f.write(line)
		

		if i+tk-1<tk:
			line="\tD2_"+str(i+tk-1)+" = _mm512_madd52lo_epu64(D2_"+str(i+tk-1)+",a512"+str(i+tk)+",b512"+str(2*tk-1)+");\n"
			#print(line)
			f.write(line)
		if i+tk<tk:
			line="\tD2_"+str(i+tk)+" = _mm512_madd52hi_epu64(zero,a512"+str(i+tk)+",b512"+str(2*tk-1)+");\n"
			#print(line)
			f.write(line)
		f.write("\n")
	
		
	f.write("\n\t// Carry management\n\n")
		
	line="\tcarry  = _mm512_srli_epi64(D2_1,52);\n"
	f.write(line)
	line="\tD2_2 = _mm512_add_epi64(D2_2,carry);\n"
	f.write(line)
	line="\tD2_1 = _mm512_and_si512(D2_1,mask52);\n"
	f.write(line)
	for i in range(3,tk-1):
		line="\tcarry  = _mm512_srli_epi64(D2_"+str(i-1)+",52);\n"
		f.write(line)
		line="\tD2_"+str(i)+" = _mm512_add_epi64(D2_"+str(i)+",carry);\n"
		f.write(line)
		line="\tD2_"+str(i-1)+" = _mm512_and_si512(D2_"+str(i-1)+",mask52);\n"
		f.write(line)
	line="\tcarry  = _mm512_srli_epi64(D2_"+str(tk-2)+",52);\n"
	f.write(line)
	line="\tD2_"+str(tk-1)+" = _mm512_add_epi64(D2_"+str(tk-1)+",carry);\n"
	f.write(line)
	line="\tD2_"+str(tk-2)+" = _mm512_and_si512(D2_"+str(tk-2)+",mask52);\n"
	f.write(line)
	'''
		
	f.write("\n\t// Conversion in base 2^"+str(split)+"\n\n")

	line = "\tcarry = D2_"+str(tk-1)+">>51;\n"
	f.write(line)
	line = "\tD2_"+str(tk)+" = (D2_"+str(tk)+"<<1)|carry;\n"
	f.write(line)
	line = "\tD2_"+str(tk-1)+" &= mask51;\n"
	f.write(line)
	for i in range(tk,tk*2-1):
		line = "\tcarry = D2_"+str(i)+">>52;\n"
		f.write(line)
		line = "\tD2_"+str(i+1)+" = (D2_"+str(i+1)+"<<1)|carry;\n"
		f.write(line)
		line = "\tD2_"+str(i)+" &= mask52;\n"
		f.write(line)
	'''


	
	line = "\n\t// D1 = (Al+Ah)*(Bl+Bh)\n\n"
	f.write(line)
	
	
	for i in range(tk):
		line = "\t__m512i D1_"+str(i)+";\n"#, D1_"+str(2*i)+", D1_"+str(2*i+1)+", D2_"+str(2*i)+", D2_"+str(2*i+1)+";\n"
		f.write(line)
		
	f.write("\n")
	line = "\t__m512i alpah0 = _mm512_add_epi64(a5120,a512"+str(tk)+");\n"
	f.write(line)
	line = "\tcarry = alpah0>>52;\n"
	f.write(line)
	line = "\talpah0 &= mask52;\n"
	f.write(line)
	for i in range(1,tk):
		line = "\t__m512i alpah"+str(i)+" = _mm512_add_epi64(a512"+str(i)+",carry);\n"
		f.write(line)
		line = "\talpah"+str(i)+" = _mm512_add_epi64(alpah"+str(i)+",a512"+str(i+tk)+");\n"
		f.write(line)
		line = "\tcarry = alpah"+str(i)+">>52;\n"
		f.write(line)
		line = "\talpah"+str(i)+" &= mask52;\n"
		f.write(line)
		
		
	line = "\t__m512i blpbh0 = _mm512_add_epi64(b5120,b512"+str(tk)+");\n"
	f.write(line)
	line = "\tcarry = blpbh0>>52;\n"
	f.write(line)
	line = "\tblpbh0 &= mask52;\n"
	f.write(line)
	for i in range(1,tk):
		line = "\t__m512i blpbh"+str(i)+" = _mm512_add_epi64(b512"+str(i)+",carry);\n"
		f.write(line)
		line = "\tblpbh"+str(i)+" = _mm512_add_epi64(blpbh"+str(i)+",b512"+str(i+tk)+");\n"
		f.write(line)
		line = "\tcarry = blpbh"+str(i)+">>52;\n"
		f.write(line)
		line = "\tblpbh"+str(i)+" &= mask52;\n"
		f.write(line)



		
	line = "\tD1_0 = _mm512_madd52lo_epu64(D0_"+str(tk)+",alpah0,blpbh0);\n"
	f.write(line)
	line = "\tD1_1 = _mm512_madd52hi_epu64(D0_"+str(tk+1)+",alpah0,blpbh0);\n"
	f.write(line)


	for j in range(1,tk-1):
		line = "\tD1_"+str(j)+" = _mm512_madd52lo_epu64(D1_"+str(j)+",alpah0,blpbh"+str(j)+");\n"
		f.write(line)
		if j+1<tk:
			line = "\tD1_"+str(j+1)+" = _mm512_madd52hi_epu64(D0_"+str(tk+1+j)+",alpah0,blpbh"+str(j)+");\n"
			f.write(line)
	line = "\tD1_"+str(tk-1)+" = _mm512_madd52lo_epu64(D1_"+str(tk-1)+",alpah0,blpbh"+str(tk-1)+");\n"
	f.write(line)
	f.write("\n")
		
		
	for i in range(1,tk):
		for j in range(tk-1):
			if j+i<tk:
				line="\tD1_"+str(i+j)+" = _mm512_madd52lo_epu64(D1_"+str(i+j)+",alpah"+str(i)+",blpbh"+str(j)+");\n"
				#print(line)
				f.write(line)
			if j+1+i<tk:
				line="\tD1_"+str(i+j+1)+" = _mm512_madd52hi_epu64(D1_"+str(i+j+1)+",alpah"+str(i)+",blpbh"+str(j)+");\n"
				#print(line)
				f.write(line)
		
		if tk+i-1<tk:
			line="\tD1_"+str(i+tk-1)+" = _mm512_madd52lo_epu64(D1_"+str(i+tk-1)+",alpah"+str(i)+",blpbh"+str(tk-1)+");\n"
			#print(line)
			f.write(line)
		if tk+i<tk:
			line="\tD1_"+str(i+tk)+" = _mm512_madd52hi_epu64(zero,alpah"+str(i)+",blpbh"+str(tk-1)+");\n"
			#print(line)
			f.write(line)
		f.write("\n")
	
		
	f.write("\n\t// Carry management\n\n")
		
	line="\tcarry  = _mm512_srli_epi64(D1_0,52);\n"
	f.write(line)
	line="\tD1_0 = _mm512_and_si512(D1_0,mask52);\n"
	f.write(line)
	line="\tD1_1 = _mm512_add_epi64(D1_1,carry);\n"
	f.write(line)
	for i in range(2,tk-1):
		line="\tcarry  = _mm512_srli_epi64(D1_"+str(i-1)+",52);\n"
		f.write(line)
		line="\tD1_"+str(i)+" = _mm512_add_epi64(D1_"+str(i)+",carry);\n"
		f.write(line)
		line="\tD1_"+str(i-1)+" = _mm512_and_si512(D1_"+str(i-1)+",mask52);\n"
		f.write(line)
	line="\tcarry  = _mm512_srli_epi64(D1_"+str(tk-2)+",52);\n"
	f.write(line)
	line="\tD1_"+str(tk-1)+" = _mm512_add_epi64(D1_"+str(tk-1)+",carry);\n"
	f.write(line)
	line="\tD1_"+str(tk-2)+" = _mm512_and_si512(D1_"+str(tk-2)+",mask52);\n"
	f.write(line)


	'''	
	f.write("\n\t// Conversion in base 2^"+str(split)+"\n\n")

	line="\tcarry  = _mm512_srli_epi64(D1_"+str(tk-1)+",51);\n"
	f.write(line)
	line="\tD1_"+str(tk-1)+" = _mm512_and_si512(D1_"+str(tk-1)+",mask51);// radix 2^"+str(split)+"\n"
	f.write(line)
	line="\tD1_"+str(tk)+" = _mm512_add_epi64(_mm512_slli_epi64(D1_"+str(tk)+",1),carry);\n"
	f.write(line)
	line="\tD1_"+str(tk)+" = _mm512_add_epi64(D1_"+str(tk)+",D2_0);\n"
	f.write(line)

	for i in range(tk,2*tk-1):
		line = "\tcarry = _mm512_srli_epi64(D1_"+str(i)+",52);\n"
		f.write(line)
		line="\tD1_"+str(i)+" = _mm512_and_si512(D1_"+str(i)+",mask52);\n"
		f.write(line)
		line="\tD1_"+str(i+1)+" = _mm512_add_epi64(_mm512_slli_epi64(D1_"+str(i+1)+",1),carry);\n"
		f.write(line)
		line="\tD1_"+str(i+1)+" = _mm512_add_epi64(D1_"+str(i+1)+",D2_"+str(i+1-tk)+");\n"
		f.write(line)
	line="\tcarry  = _mm512_srli_epi64(D1_"+str(2*tk-1)+",51);\n"
	f.write(line)
	line="\tD1_"+str(2*tk-1)+" = _mm512_and_si512(D1_"+str(2*tk-1)+",mask51);// radix 2^"+str(split)+"\n"
	f.write(line)
	'''

		
	f.write("\n\t// Final reconstruction\n\n")

	f.write("\n\t// tmp = D0+D2, radix 2^"+str(split)+"\n\n")
	
	line="\t__m512i tmp0 = _mm512_add_epi64(D0_0,D2_0);\n"
	f.write(line)
	line="\t__m512i carry_tmp  = _mm512_srli_epi64(tmp0,52);\n"
	f.write(line)
	line="\ttmp0 = _mm512_and_si512(tmp0,mask52);\n\n"
	f.write(line)

	for i in range(1,tk-1):
		line="\t__m512i tmp"+str(i)+" = _mm512_add_epi64(D0_"+str(i)+",carry_tmp);\n"
		f.write(line)
		line="\ttmp"+str(i)+" = _mm512_add_epi64(tmp"+str(i)+",D2_"+str(i)+");\n"
		f.write(line)
		line="\tcarry_tmp  = _mm512_srli_epi64(tmp"+str(i)+",52);\n"
		f.write(line)
		line="\ttmp"+str(i)+" = _mm512_and_si512(tmp"+str(i)+",mask52);\n\n"
		f.write(line)
	
	line="\t__m512i tmp"+str(tk-1)+" = _mm512_add_epi64(D0_"+str(tk-1)+",carry_tmp);\n"
	f.write(line)
	line="\ttmp"+str(tk-1)+" = _mm512_add_epi64(tmp"+str(tk-1)+",D2_"+str(tk-1)+");\n"
	f.write(line)
	line="\tcarry_tmp  = _mm512_srli_epi64(tmp"+str(tk-1)+",51);\n"
	f.write(line)
	line="\ttmp"+str(tk-1)+" = _mm512_and_si512(tmp"+str(tk-1)+",mask51);// radix 2**"+str(split)+"\n\n"
	f.write(line)

	f.write("\n\t// D1 = D1 -tmp, radix 2^"+str(split)+"\n\n")

	line="\tD1_0 = _mm512_sub_epi64(D1_0,tmp0);\n"
	f.write(line)
	line="\t__m512i borrow = _mm512_srli_epi64(D1_0,52)&un;\n"
	f.write(line)
	line="\tD1_0 = _mm512_and_si512(D1_0,mask52);\n"
	f.write(line)
	
	for i in range(1,tk-1):
		line="\tborrow = _mm512_add_epi64(tmp"+str(i)+",borrow);\n"
		f.write(line)
		line="\tD1_"+str(i)+" = _mm512_sub_epi64(D1_"+str(i)+",borrow);\n"
		f.write(line)
		line="\tborrow  = _mm512_srli_epi64(D1_"+str(i)+",52)&un;\n"
		f.write(line)
		line="\tD1_"+str(i)+" = _mm512_and_si512(D1_"+str(i)+",mask52);\n\n"
		f.write(line)
		
	line="\tborrow = _mm512_add_epi64(tmp"+str(tk-1)+",borrow);\n"
	f.write(line)
	line="\tD1_"+str(tk-1)+" = _mm512_sub_epi64(D1_"+str(tk-1)+",borrow);\n"
	f.write(line)
	line="\tborrow = _mm512_srli_epi64(D1_"+str(tk-1)+",51)&un;\n"
	f.write(line)
	line="\tD1_"+str(tk-1)+" = _mm512_and_si512(D1_"+str(tk-1)+",mask51);// radix 2**"+str(split)+"\n\n"
	f.write(line)


	f.write("\n\n")

	for i in range(tk):
		line = "\t_mm512_store_epi64(out+"+str(i)+",D0_"+str(i)+");\n"
		f.write(line)
		
	for i in range(tk):
		line = "\t_mm512_store_epi64(out+"+str(i+tk)+",D1_"+str(i)+");\n"
		f.write(line)

	f.write("\n}\n\n")
		





	f.write("/* Karatsuba multiplication */\n\n")

	t=ceil(SIZE/52)
	tk=ceil(t/2)
	split=SIZE//2
	print("t =",t,tk, split)

	'''
		Multiplication generation
	'''


	line = "inline void force_inline mul512_8_"+str(SIZE)+"K(__m512i out["+str(2*t)+"], __m512i a512["+str(t)+"], __m512i b512["+str(t)+"])\n{\n"

	print(line)
	f.write(line)
	
	line = "\n\t// D0 = Al*Bl\n\n"
	f.write(line)
	
	
	for i in range(tk):
		line = "\t__m512i D0_"+str(2*i)+", D0_"+str(2*i+1)+";\n"#, D1_"+str(2*i)+", D1_"+str(2*i+1)+", D2_"+str(2*i)+", D2_"+str(2*i+1)+";\n"
		f.write(line)
		
	line = "\t__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512);\n"
	f.write(line)
	for i in range(1,tk):
		line = "\t__m512i a512"+str(i)+" = _mm512_load_epi64(a512+"+str(i)+"), b512"+str(i)+" = _mm512_load_epi64(b512+"+str(i)+");\n"
		f.write(line)
		
		
	line = "\tD0_0 = _mm512_madd52lo_epu64(zero,a5120,b5120);\n"
	f.write(line)
	line = "\tD0_1 = _mm512_madd52hi_epu64(zero,a5120,b5120);\n"
	f.write(line)
	
	for j in range(1,tk):
		line = "\tD0_"+str(j)+" = _mm512_madd52lo_epu64(D0_"+str(j)+",a5120,b512"+str(j)+");\n"
		f.write(line)
		line = "\tD0_"+str(j+1)+" = _mm512_madd52hi_epu64(zero,a5120,b512"+str(j)+");\n"
		f.write(line)
	f.write("\n")
		
		
	for i in range(1,tk):
		for j in range(tk-1):
			line="\tD0_"+str(i+j)+" = _mm512_madd52lo_epu64(D0_"+str(i+j)+",a512"+str(i)+",b512"+str(j)+");\n"
			#print(line)
			f.write(line)
			line="\tD0_"+str(i+j+1)+" = _mm512_madd52hi_epu64(D0_"+str(i+j+1)+",a512"+str(i)+",b512"+str(j)+");\n"
			#print(line)
			f.write(line)
		
		line="\tD0_"+str(i+tk-1)+" = _mm512_madd52lo_epu64(D0_"+str(i+tk-1)+",a512"+str(i)+",b512"+str(tk-1)+");\n"
		#print(line)
		f.write(line)
		line="\tD0_"+str(i+tk)+" = _mm512_madd52hi_epu64(zero,a512"+str(i)+",b512"+str(tk-1)+");\n"
		#print(line)
		f.write(line)
		f.write("\n")
	
		
	f.write("\n\t// Carry management\n\n")
		
	line="\t__m512i carry  = _mm512_srli_epi64(D0_1,52);\n"
	f.write(line)
	line="\tD0_2 = _mm512_add_epi64(D0_2,carry);\n"
	f.write(line)
	line="\tD0_1 = _mm512_and_si512(D0_1,mask52);\n"
	f.write(line)
	for i in range(3,2*tk-1):
		line="\tcarry  = _mm512_srli_epi64(D0_"+str(i-1)+",52);\n"
		f.write(line)
		line="\tD0_"+str(i)+" = _mm512_add_epi64(D0_"+str(i)+",carry);\n"
		f.write(line)
		line="\tD0_"+str(i-1)+" = _mm512_and_si512(D0_"+str(i-1)+",mask52);\n"
		f.write(line)
	line="\tcarry  = _mm512_srli_epi64(D0_"+str(2*tk-2)+",52);\n"
	f.write(line)
	line="\tD0_"+str(2*tk-1)+" = _mm512_add_epi64(D0_"+str(2*tk-1)+",carry);\n"
	f.write(line)
	line="\tD0_"+str(2*tk-2)+" = _mm512_and_si512(D0_"+str(2*tk-2)+",mask52);\n"
	f.write(line)
	
		
	f.write("\n\t// Conversion in base 2^"+str(split)+"\n\n")

	line = "\tcarry = D0_"+str(tk-1)+">>51;\n"
	f.write(line)
	line = "\tD0_"+str(tk)+" = (D0_"+str(tk)+"<<1)|carry;\n"
	f.write(line)
	line = "\tD0_"+str(tk-1)+" &= mask51;\n"
	f.write(line)
	for i in range(tk,tk*2-1):
		line = "\tcarry = D0_"+str(i)+">>52;\n"
		f.write(line)
		line = "\tD0_"+str(i+1)+" = (D0_"+str(i+1)+"<<1)|carry;\n"
		f.write(line)
		line = "\tD0_"+str(i)+" &= mask52;\n"
		f.write(line)
		

	
	line = "\n\t// D2 = Ah*Bh\n\n"
	f.write(line)
	
	
	for i in range(tk):
		line = "\t__m512i D2_"+str(2*i)+", D2_"+str(2*i+1)+";\n"#, D1_"+str(2*i)+", D1_"+str(2*i+1)+", D2_"+str(2*i)+", D2_"+str(2*i+1)+";\n"
		f.write(line)
		
	line = "\t__m512i a512"+str(tk)+" = _mm512_load_epi64(a512+"+str(tk)+"), b512"+str(tk)+" = _mm512_load_epi64(b512+"+str(tk)+");\n"
	f.write(line)
	
	
	for i in range(tk+1,tk*2):
		line = "\t__m512i a512"+str(i)+" = _mm512_load_epi64(a512+"+str(i)+"), b512"+str(i)+" = _mm512_load_epi64(b512+"+str(i)+");\n"
		f.write(line)
	line = "\tD2_0 = _mm512_madd52lo_epu64(zero,a512"+str(tk)+",b512"+str(tk)+");\n"
	f.write(line)
	line = "\tD2_1 = _mm512_madd52hi_epu64(zero,a512"+str(tk)+",b512"+str(tk)+");\n"
	f.write(line)
	
	for j in range(1,tk):
		line = "\tD2_"+str(j)+" = _mm512_madd52lo_epu64(D2_"+str(j)+",a512"+str(tk)+",b512"+str(j+tk)+");\n"
		f.write(line)
		line = "\tD2_"+str(j+1)+" = _mm512_madd52hi_epu64(zero,a512"+str(tk)+",b512"+str(j+tk)+");\n"
		f.write(line)
	f.write("\n")
		
		
	for i in range(1,tk):
		for j in range(tk-1):
			line="\tD2_"+str(i+j)+" = _mm512_madd52lo_epu64(D2_"+str(i+j)+",a512"+str(i+tk)+",b512"+str(j+tk)+");\n"
			#print(line)
			f.write(line)
			line="\tD2_"+str(i+j+1)+" = _mm512_madd52hi_epu64(D2_"+str(i+j+1)+",a512"+str(i+tk)+",b512"+str(j+tk)+");\n"
			#print(line)
			f.write(line)
		
		line="\tD2_"+str(i+tk-1)+" = _mm512_madd52lo_epu64(D2_"+str(i+tk-1)+",a512"+str(i+tk)+",b512"+str(2*tk-1)+");\n"
		#print(line)
		f.write(line)
		line="\tD2_"+str(i+tk)+" = _mm512_madd52hi_epu64(zero,a512"+str(i+tk)+",b512"+str(2*tk-1)+");\n"
		#print(line)
		f.write(line)
		f.write("\n")
	
		
	f.write("\n\t// Carry management\n\n")
		
	line="\tcarry  = _mm512_srli_epi64(D2_1,52);\n"
	f.write(line)
	line="\tD2_2 = _mm512_add_epi64(D2_2,carry);\n"
	f.write(line)
	line="\tD2_1 = _mm512_and_si512(D2_1,mask52);\n"
	f.write(line)
	for i in range(3,2*tk-1):
		line="\tcarry  = _mm512_srli_epi64(D2_"+str(i-1)+",52);\n"
		f.write(line)
		line="\tD2_"+str(i)+" = _mm512_add_epi64(D2_"+str(i)+",carry);\n"
		f.write(line)
		line="\tD2_"+str(i-1)+" = _mm512_and_si512(D2_"+str(i-1)+",mask52);\n"
		f.write(line)
	line="\tcarry  = _mm512_srli_epi64(D2_"+str(2*tk-2)+",52);\n"
	f.write(line)
	line="\tD2_"+str(2*tk-1)+" = _mm512_add_epi64(D2_"+str(2*tk-1)+",carry);\n"
	f.write(line)
	line="\tD2_"+str(2*tk-2)+" = _mm512_and_si512(D2_"+str(2*tk-2)+",mask52);\n"
	f.write(line)
	
		
	f.write("\n\t// Conversion in base 2^"+str(split)+"\n\n")

	line = "\tcarry = D2_"+str(tk-1)+">>51;\n"
	f.write(line)
	line = "\tD2_"+str(tk)+" = (D2_"+str(tk)+"<<1)|carry;\n"
	f.write(line)
	line = "\tD2_"+str(tk-1)+" &= mask51;\n"
	f.write(line)
	for i in range(tk,tk*2-1):
		line = "\tcarry = D2_"+str(i)+">>52;\n"
		f.write(line)
		line = "\tD2_"+str(i+1)+" = (D2_"+str(i+1)+"<<1)|carry;\n"
		f.write(line)
		line = "\tD2_"+str(i)+" &= mask52;\n"
		f.write(line)



	
	line = "\n\t// D1 = (Al+Ah)*(Bl+Bh)\n\n"
	f.write(line)
	
	
	for i in range(tk):
		line = "\t__m512i D1_"+str(2*i)+", D1_"+str(2*i+1)+";\n"#, D1_"+str(2*i)+", D1_"+str(2*i+1)+", D2_"+str(2*i)+", D2_"+str(2*i+1)+";\n"
		f.write(line)
		
	f.write("\n")
	line = "\t__m512i alpah0 = _mm512_add_epi64(a5120,a512"+str(tk)+");\n"
	f.write(line)
	line = "\tcarry = alpah0>>52;\n"
	f.write(line)
	line = "\talpah0 &= mask52;\n"
	f.write(line)
	for i in range(1,tk):
		line = "\t__m512i alpah"+str(i)+" = _mm512_add_epi64(a512"+str(i)+",carry);\n"
		f.write(line)
		line = "\talpah"+str(i)+" = _mm512_add_epi64(alpah"+str(i)+",a512"+str(i+tk)+");\n"
		f.write(line)
		line = "\tcarry = alpah"+str(i)+">>52;\n"
		f.write(line)
		line = "\talpah"+str(i)+" &= mask52;\n"
		f.write(line)
		
		
	line = "\t__m512i blpbh0 = _mm512_add_epi64(b5120,b512"+str(tk)+");\n"
	f.write(line)
	line = "\tcarry = blpbh0>>52;\n"
	f.write(line)
	line = "\tblpbh0 &= mask52;\n"
	f.write(line)
	for i in range(1,tk):
		line = "\t__m512i blpbh"+str(i)+" = _mm512_add_epi64(b512"+str(i)+",carry);\n"
		f.write(line)
		line = "\tblpbh"+str(i)+" = _mm512_add_epi64(blpbh"+str(i)+",b512"+str(i+tk)+");\n"
		f.write(line)
		line = "\tcarry = blpbh"+str(i)+">>52;\n"
		f.write(line)
		line = "\tblpbh"+str(i)+" &= mask52;\n"
		f.write(line)



		
	line = "\tD1_0 = _mm512_madd52lo_epu64(D0_"+str(tk)+",alpah0,blpbh0);\n"
	f.write(line)
	line = "\tD1_1 = _mm512_madd52hi_epu64(D0_"+str(tk+1)+",alpah0,blpbh0);\n"
	f.write(line)


	for j in range(1,tk-1):
		line = "\tD1_"+str(j)+" = _mm512_madd52lo_epu64(D1_"+str(j)+",alpah0,blpbh"+str(j)+");\n"
		f.write(line)
		line = "\tD1_"+str(j+1)+" = _mm512_madd52hi_epu64(D0_"+str(tk+1+j)+",alpah0,blpbh"+str(j)+");\n"
		f.write(line)
	line = "\tD1_"+str(tk-1)+" = _mm512_madd52lo_epu64(D1_"+str(tk-1)+",alpah0,blpbh"+str(tk-1)+");\n"
	f.write(line)
	line = "\tD1_"+str(tk)+" = _mm512_madd52hi_epu64(zero,alpah0,blpbh"+str(tk-1)+");\n"
	f.write(line)
	f.write("\n")
		
		
	for i in range(1,tk):
		for j in range(tk-1):
			line="\tD1_"+str(i+j)+" = _mm512_madd52lo_epu64(D1_"+str(i+j)+",alpah"+str(i)+",blpbh"+str(j)+");\n"
			#print(line)
			f.write(line)
			line="\tD1_"+str(i+j+1)+" = _mm512_madd52hi_epu64(D1_"+str(i+j+1)+",alpah"+str(i)+",blpbh"+str(j)+");\n"
			#print(line)
			f.write(line)
		
		line="\tD1_"+str(i+tk-1)+" = _mm512_madd52lo_epu64(D1_"+str(i+tk-1)+",alpah"+str(i)+",blpbh"+str(tk-1)+");\n"
		#print(line)
		f.write(line)
		line="\tD1_"+str(i+tk)+" = _mm512_madd52hi_epu64(zero,alpah"+str(i)+",blpbh"+str(tk-1)+");\n"
		#print(line)
		f.write(line)
		f.write("\n")
	
		
	f.write("\n\t// Carry management\n\n")
		
	line="\tcarry  = _mm512_srli_epi64(D1_0,52);\n"
	f.write(line)
	line="\tD1_0 = _mm512_and_si512(D1_0,mask52);\n"
	f.write(line)
	line="\tD1_1 = _mm512_add_epi64(D1_1,carry);\n"
	f.write(line)
	for i in range(2,2*tk-1):
		line="\tcarry  = _mm512_srli_epi64(D1_"+str(i-1)+",52);\n"
		f.write(line)
		line="\tD1_"+str(i)+" = _mm512_add_epi64(D1_"+str(i)+",carry);\n"
		f.write(line)
		line="\tD1_"+str(i-1)+" = _mm512_and_si512(D1_"+str(i-1)+",mask52);\n"
		f.write(line)
	line="\tcarry  = _mm512_srli_epi64(D1_"+str(2*tk-2)+",52);\n"
	f.write(line)
	line="\tD1_"+str(2*tk-1)+" = _mm512_add_epi64(D1_"+str(2*tk-1)+",carry);\n"
	f.write(line)
	line="\tD1_"+str(2*tk-2)+" = _mm512_and_si512(D1_"+str(2*tk-2)+",mask52);\n"
	f.write(line)


		
	f.write("\n\t// Conversion in base 2^"+str(split)+"\n\n")

	line="\tcarry  = _mm512_srli_epi64(D1_"+str(tk-1)+",51);\n"
	f.write(line)
	line="\tD1_"+str(tk-1)+" = _mm512_and_si512(D1_"+str(tk-1)+",mask51);// radix 2^"+str(split)+"\n"
	f.write(line)
	line="\tD1_"+str(tk)+" = _mm512_add_epi64(_mm512_slli_epi64(D1_"+str(tk)+",1),carry);\n"
	f.write(line)
	line="\tD1_"+str(tk)+" = _mm512_add_epi64(D1_"+str(tk)+",D2_0);\n"
	f.write(line)

	for i in range(tk,2*tk-1):
		line = "\tcarry = _mm512_srli_epi64(D1_"+str(i)+",52);\n"
		f.write(line)
		line="\tD1_"+str(i)+" = _mm512_and_si512(D1_"+str(i)+",mask52);\n"
		f.write(line)
		line="\tD1_"+str(i+1)+" = _mm512_add_epi64(_mm512_slli_epi64(D1_"+str(i+1)+",1),carry);\n"
		f.write(line)
		line="\tD1_"+str(i+1)+" = _mm512_add_epi64(D1_"+str(i+1)+",D2_"+str(i+1-tk)+");\n"
		f.write(line)
	line="\tcarry  = _mm512_srli_epi64(D1_"+str(2*tk-1)+",51);\n"
	f.write(line)
	line="\tD1_"+str(2*tk-1)+" = _mm512_and_si512(D1_"+str(2*tk-1)+",mask51);// radix 2^"+str(split)+"\n"
	f.write(line)


		
	f.write("\n\t// Final reconstruction\n\n")

	f.write("\n\t// tmp = D0+D2, radix 2^"+str(split)+"\n\n")
	
	line="\t__m512i tmp0 = _mm512_add_epi64(D0_0,D2_0);\n"
	f.write(line)
	line="\t__m512i carry_tmp  = _mm512_srli_epi64(tmp0,52);\n"
	f.write(line)
	line="\ttmp0 = _mm512_and_si512(tmp0,mask52);\n\n"
	f.write(line)

	for i in range(1,tk-1):
		line="\t__m512i tmp"+str(i)+" = _mm512_add_epi64(D0_"+str(i)+",carry_tmp);\n"
		f.write(line)
		line="\ttmp"+str(i)+" = _mm512_add_epi64(tmp"+str(i)+",D2_"+str(i)+");\n"
		f.write(line)
		line="\tcarry_tmp  = _mm512_srli_epi64(tmp"+str(i)+",52);\n"
		f.write(line)
		line="\ttmp"+str(i)+" = _mm512_and_si512(tmp"+str(i)+",mask52);\n\n"
		f.write(line)
	
	line="\t__m512i tmp"+str(tk-1)+" = _mm512_add_epi64(D0_"+str(tk-1)+",carry_tmp);\n"
	f.write(line)
	line="\ttmp"+str(tk-1)+" = _mm512_add_epi64(tmp"+str(tk-1)+",D2_"+str(tk-1)+");\n"
	f.write(line)
	line="\tcarry_tmp  = _mm512_srli_epi64(tmp"+str(tk-1)+",51);\n"
	f.write(line)
	line="\ttmp"+str(tk-1)+" = _mm512_and_si512(tmp"+str(tk-1)+",mask51);// radix 2**"+str(split)+"\n\n"
	f.write(line)

	for i in range(tk,2*tk-1):
		line="\t__m512i tmp"+str(i)+" = _mm512_add_epi64(D0_"+str(i)+",carry_tmp);\n"
		f.write(line)
		line="\ttmp"+str(i)+" = _mm512_add_epi64(tmp"+str(i)+",D2_"+str(i)+");\n"
		f.write(line)
		line="\tcarry_tmp  = _mm512_srli_epi64(tmp"+str(i)+",52);\n"
		f.write(line)
		line="\ttmp"+str(i)+" = _mm512_and_si512(tmp"+str(i)+",mask52);\n\n"
		f.write(line)
	
	line="\t__m512i tmp"+str(2*tk-1)+" = _mm512_add_epi64(D0_"+str(2*tk-1)+",carry_tmp);\n"
	f.write(line)
	line="\ttmp"+str(2*tk-1)+" = _mm512_add_epi64(tmp"+str(2*tk-1)+",D2_"+str(2*tk-1)+");\n"
	f.write(line)
	line="\tcarry_tmp  = _mm512_srli_epi64(tmp"+str(2*tk-1)+",51);\n"
	f.write(line)
	line="\ttmp"+str(2*tk-1)+" = _mm512_and_si512(tmp"+str(2*tk-1)+",mask51);// radix 2**"+str(split)+"\n\n"
	f.write(line)
	f.write("\n\n")

	f.write("\n\t// D1 = D1 -tmp, radix 2^"+str(split)+"\n\n")

	line="\tD1_0 = _mm512_sub_epi64(D1_0,tmp0);\n"
	f.write(line)
	line="\t__m512i borrow = _mm512_srli_epi64(D1_0,52)&un;\n"
	f.write(line)
	line="\tD1_0 = _mm512_and_si512(D1_0,mask52);\n"
	f.write(line)
	
	for i in range(1,tk-1):
		line="\tborrow = _mm512_add_epi64(tmp"+str(i)+",borrow);\n"
		f.write(line)
		line="\tD1_"+str(i)+" = _mm512_sub_epi64(D1_"+str(i)+",borrow);\n"
		f.write(line)
		line="\tborrow  = _mm512_srli_epi64(D1_"+str(i)+",52)&un;\n"
		f.write(line)
		line="\tD1_"+str(i)+" = _mm512_and_si512(D1_"+str(i)+",mask52);\n\n"
		f.write(line)
		
	line="\tborrow = _mm512_add_epi64(tmp"+str(tk-1)+",borrow);\n"
	f.write(line)
	line="\tD1_"+str(tk-1)+" = _mm512_sub_epi64(D1_"+str(tk-1)+",borrow);\n"
	f.write(line)
	line="\tborrow = _mm512_srli_epi64(D1_"+str(tk-1)+",51)&un;\n"
	f.write(line)
	line="\tD1_"+str(tk-1)+" = _mm512_and_si512(D1_"+str(tk-1)+",mask51);// radix 2**"+str(split)+"\n\n"
	f.write(line)


	for i in range(tk,2*tk-1):
		line="\tborrow = _mm512_add_epi64(tmp"+str(i)+",borrow);\n"
		f.write(line)
		line="\tD1_"+str(i)+" = _mm512_sub_epi64(D1_"+str(i)+",borrow);\n"
		f.write(line)
		line="\tborrow  = _mm512_srli_epi64(D1_"+str(i)+",52)&un;\n"
		f.write(line)
		line="\tD1_"+str(i)+" = _mm512_and_si512(D1_"+str(i)+",mask52);\n\n"
		f.write(line)
		
	line="\tborrow = _mm512_add_epi64(tmp"+str(2*tk-1)+",borrow);\n"
	f.write(line)
	line="\tD1_"+str(2*tk-1)+" = _mm512_sub_epi64(D1_"+str(2*tk-1)+",borrow);\n"
	f.write(line)
	line="\tborrow = _mm512_srli_epi64(D1_"+str(2*tk-1)+",51)&un;\n"
	f.write(line)
	line="\tD1_"+str(2*tk-1)+" = _mm512_and_si512(D1_"+str(2*tk-1)+",mask51);// radix 2**"+str(split)+"\n\n"
	f.write(line)


	f.write("\n\t// Final borrows\n\n")

	line="\tborrow = _mm512_add_epi64(carry_tmp,borrow);\n"
	f.write(line)
	line="\tD2_"+str(tk)+" = _mm512_add_epi64(D2_"+str(tk)+",carry);\n"
	f.write(line)

	for i in range(tk,2*tk-1):
		line="\tD2_"+str(i)+" = _mm512_sub_epi64(D2_"+str(i)+",borrow);\n"
		f.write(line)
		line="\tborrow  = _mm512_srli_epi64(D2_"+str(i)+",52)&un;\n"
		f.write(line)
		line="\tD2_"+str(i)+" = _mm512_and_si512(D2_"+str(i)+",mask52);\n\n"
		f.write(line)

	line="\tD2_"+str(2*tk-1)+" = _mm512_sub_epi64(D2_"+str(2*tk-1)+",borrow);\n"
	f.write(line)



	f.write("\n\n")

	for i in range(tk):
		line = "\t_mm512_store_epi64(out+"+str(i)+",D0_"+str(i)+");\n"
		f.write(line)
		
	for i in range(2*tk):
		line = "\t_mm512_store_epi64(out+"+str(i+tk)+",D1_"+str(i)+");\n"
		f.write(line)

	for i in range(tk):
		line = "\t_mm512_store_epi64(out+"+str(i+3*tk)+",D2_"+str(i+tk)+");\n"
		f.write(line)
		
	f.write("\n}\n\n")
		



	f.write("/* Karatsuba fma, computes C+AB */\n\n")

	t=ceil(SIZE/52)
	tk=ceil(t/2)
	split=SIZE//2
	print("t =",t,tk, split)

	'''
		Multiplication generation
	'''


	line = "inline void force_inline fma512_8_"+str(SIZE)+"K(__m512i out["+str(2*t)+"], __m512i a512["+str(t)+"], __m512i b512["+str(t)+"], __m512i c512["+str(t)+"])\n{\n"

	print(line)
	f.write(line)
	
	line = "\n\t// D0 = Al*Bl\n\n"
	f.write(line)
	
	
	for i in range(tk):
		line = "\t__m512i D0_"+str(2*i)+", D0_"+str(2*i+1)+";\n"#, D1_"+str(2*i)+", D1_"+str(2*i+1)+", D2_"+str(2*i)+", D2_"+str(2*i+1)+";\n"
		f.write(line)
		
	line = "\t__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512), c5120 = _mm512_load_epi64(c512);\n"
	f.write(line)
	for i in range(1,tk):
		line = "\t__m512i a512"+str(i)+" = _mm512_load_epi64(a512+"+str(i)+"), b512"+str(i)+" = _mm512_load_epi64(b512+"+str(i)+"), c512"+str(i)+" = _mm512_load_epi64(c512+"+str(i)+");\n"
		f.write(line)
		
		
	line = "\tD0_0 = _mm512_madd52lo_epu64(c5120,a5120,b5120);\n"
	f.write(line)
	line = "\tD0_1 = _mm512_madd52hi_epu64(c5121,a5120,b5120);\n"
	f.write(line)
	
	for j in range(1,tk):
		line = "\tD0_"+str(j)+" = _mm512_madd52lo_epu64(D0_"+str(j)+",a5120,b512"+str(j)+");\n"
		f.write(line)
		line = "\tD0_"+str(j+1)+" = _mm512_madd52hi_epu64(c512"+str(j)+",a5120,b512"+str(j)+");\n"
		f.write(line)
	f.write("\n")
		
		
	for i in range(1,tk):
		for j in range(tk-1):
			line="\tD0_"+str(i+j)+" = _mm512_madd52lo_epu64(D0_"+str(i+j)+",a512"+str(i)+",b512"+str(j)+");\n"
			#print(line)
			f.write(line)
			line="\tD0_"+str(i+j+1)+" = _mm512_madd52hi_epu64(D0_"+str(i+j+1)+",a512"+str(i)+",b512"+str(j)+");\n"
			#print(line)
			f.write(line)
		
		line="\tD0_"+str(i+tk-1)+" = _mm512_madd52lo_epu64(D0_"+str(i+tk-1)+",a512"+str(i)+",b512"+str(tk-1)+");\n"
		#print(line)
		f.write(line)
		line="\tD0_"+str(i+tk)+" = _mm512_madd52hi_epu64(c512"+str(i)+",a512"+str(i)+",b512"+str(tk-1)+");\n"
		#print(line)
		f.write(line)
		f.write("\n")
	
		
	f.write("\n\t// Carry management\n\n")
		
	line="\t__m512i carry  = _mm512_srli_epi64(D0_1,52);\n"
	f.write(line)
	line="\tD0_2 = _mm512_add_epi64(D0_2,carry);\n"
	f.write(line)
	line="\tD0_1 = _mm512_and_si512(D0_1,mask52);\n"
	f.write(line)
	for i in range(3,2*tk-1):
		line="\tcarry  = _mm512_srli_epi64(D0_"+str(i-1)+",52);\n"
		f.write(line)
		line="\tD0_"+str(i)+" = _mm512_add_epi64(D0_"+str(i)+",carry);\n"
		f.write(line)
		line="\tD0_"+str(i-1)+" = _mm512_and_si512(D0_"+str(i-1)+",mask52);\n"
		f.write(line)
	line="\tcarry  = _mm512_srli_epi64(D0_"+str(2*tk-2)+",52);\n"
	f.write(line)
	line="\tD0_"+str(2*tk-1)+" = _mm512_add_epi64(D0_"+str(2*tk-1)+",carry);\n"
	f.write(line)
	line="\tD0_"+str(2*tk-2)+" = _mm512_and_si512(D0_"+str(2*tk-2)+",mask52);\n"
	f.write(line)
	
		
	f.write("\n\t// Conversion in base 2^"+str(split)+"\n\n")

	line = "\tcarry = D0_"+str(tk-1)+">>51;\n"
	f.write(line)
	line = "\tD0_"+str(tk)+" = (D0_"+str(tk)+"<<1)|carry;\n"
	f.write(line)
	line = "\tD0_"+str(tk-1)+" &= mask51;\n"
	f.write(line)
	for i in range(tk,tk*2-1):
		line = "\tcarry = D0_"+str(i)+">>52;\n"
		f.write(line)
		line = "\tD0_"+str(i+1)+" = (D0_"+str(i+1)+"<<1)|carry;\n"
		f.write(line)
		line = "\tD0_"+str(i)+" &= mask52;\n"
		f.write(line)
		

	
	line = "\n\t// D2 = Ah*Bh\n\n"
	f.write(line)
	
	
	for i in range(tk):
		line = "\t__m512i D2_"+str(2*i)+", D2_"+str(2*i+1)+";\n"#, D1_"+str(2*i)+", D1_"+str(2*i+1)+", D2_"+str(2*i)+", D2_"+str(2*i+1)+";\n"
		f.write(line)
		
	line = "\t__m512i a512"+str(tk)+" = _mm512_load_epi64(a512+"+str(tk)+"), b512"+str(tk)+" = _mm512_load_epi64(b512+"+str(tk)+");\n"
	f.write(line)
	
	
	for i in range(tk+1,tk*2):
		line = "\t__m512i a512"+str(i)+" = _mm512_load_epi64(a512+"+str(i)+"), b512"+str(i)+" = _mm512_load_epi64(b512+"+str(i)+");\n"
		f.write(line)
	line = "\tD2_0 = _mm512_madd52lo_epu64(zero,a512"+str(tk)+",b512"+str(tk)+");\n"
	f.write(line)
	line = "\tD2_1 = _mm512_madd52hi_epu64(zero,a512"+str(tk)+",b512"+str(tk)+");\n"
	f.write(line)
	
	for j in range(1,tk):
		line = "\tD2_"+str(j)+" = _mm512_madd52lo_epu64(D2_"+str(j)+",a512"+str(tk)+",b512"+str(j+tk)+");\n"
		f.write(line)
		line = "\tD2_"+str(j+1)+" = _mm512_madd52hi_epu64(zero,a512"+str(tk)+",b512"+str(j+tk)+");\n"
		f.write(line)
	f.write("\n")
		
		
	for i in range(1,tk):
		for j in range(tk-1):
			line="\tD2_"+str(i+j)+" = _mm512_madd52lo_epu64(D2_"+str(i+j)+",a512"+str(i+tk)+",b512"+str(j+tk)+");\n"
			#print(line)
			f.write(line)
			line="\tD2_"+str(i+j+1)+" = _mm512_madd52hi_epu64(D2_"+str(i+j+1)+",a512"+str(i+tk)+",b512"+str(j+tk)+");\n"
			#print(line)
			f.write(line)
		
		line="\tD2_"+str(i+tk-1)+" = _mm512_madd52lo_epu64(D2_"+str(i+tk-1)+",a512"+str(i+tk)+",b512"+str(2*tk-1)+");\n"
		#print(line)
		f.write(line)
		line="\tD2_"+str(i+tk)+" = _mm512_madd52hi_epu64(zero,a512"+str(i+tk)+",b512"+str(2*tk-1)+");\n"
		#print(line)
		f.write(line)
		f.write("\n")
	
		
	f.write("\n\t// Carry management\n\n")
		
	line="\tcarry  = _mm512_srli_epi64(D2_1,52);\n"
	f.write(line)
	line="\tD2_2 = _mm512_add_epi64(D2_2,carry);\n"
	f.write(line)
	line="\tD2_1 = _mm512_and_si512(D2_1,mask52);\n"
	f.write(line)
	for i in range(3,2*tk-1):
		line="\tcarry  = _mm512_srli_epi64(D2_"+str(i-1)+",52);\n"
		f.write(line)
		line="\tD2_"+str(i)+" = _mm512_add_epi64(D2_"+str(i)+",carry);\n"
		f.write(line)
		line="\tD2_"+str(i-1)+" = _mm512_and_si512(D2_"+str(i-1)+",mask52);\n"
		f.write(line)
	line="\tcarry  = _mm512_srli_epi64(D2_"+str(2*tk-2)+",52);\n"
	f.write(line)
	line="\tD2_"+str(2*tk-1)+" = _mm512_add_epi64(D2_"+str(2*tk-1)+",carry);\n"
	f.write(line)
	line="\tD2_"+str(2*tk-2)+" = _mm512_and_si512(D2_"+str(2*tk-2)+",mask52);\n"
	f.write(line)
	
		
	f.write("\n\t// Conversion in base 2^"+str(split)+"\n\n")

	line = "\tcarry = D2_"+str(tk-1)+">>51;\n"
	f.write(line)
	line = "\tD2_"+str(tk)+" = (D2_"+str(tk)+"<<1)|carry;\n"
	f.write(line)
	line = "\tD2_"+str(tk-1)+" &= mask51;\n"
	f.write(line)
	for i in range(tk,tk*2-1):
		line = "\tcarry = D2_"+str(i)+">>52;\n"
		f.write(line)
		line = "\tD2_"+str(i+1)+" = (D2_"+str(i+1)+"<<1)|carry;\n"
		f.write(line)
		line = "\tD2_"+str(i)+" &= mask52;\n"
		f.write(line)



	
	line = "\n\t// D1 = (Al+Ah)*(Bl+Bh)\n\n"
	f.write(line)
	
	
	for i in range(tk):
		line = "\t__m512i D1_"+str(2*i)+", D1_"+str(2*i+1)+";\n"#, D1_"+str(2*i)+", D1_"+str(2*i+1)+", D2_"+str(2*i)+", D2_"+str(2*i+1)+";\n"
		f.write(line)
		
	f.write("\n")
	line = "\t__m512i alpah0 = _mm512_add_epi64(a5120,a512"+str(tk)+");\n"
	f.write(line)
	line = "\tcarry = alpah0>>52;\n"
	f.write(line)
	line = "\talpah0 &= mask52;\n"
	f.write(line)
	for i in range(1,tk):
		line = "\t__m512i alpah"+str(i)+" = _mm512_add_epi64(a512"+str(i)+",carry);\n"
		f.write(line)
		line = "\talpah"+str(i)+" = _mm512_add_epi64(alpah"+str(i)+",a512"+str(i+tk)+");\n"
		f.write(line)
		line = "\tcarry = alpah"+str(i)+">>52;\n"
		f.write(line)
		line = "\talpah"+str(i)+" &= mask52;\n"
		f.write(line)
		
		
	line = "\t__m512i blpbh0 = _mm512_add_epi64(b5120,b512"+str(tk)+");\n"
	f.write(line)
	line = "\tcarry = blpbh0>>52;\n"
	f.write(line)
	line = "\tblpbh0 &= mask52;\n"
	f.write(line)
	for i in range(1,tk):
		line = "\t__m512i blpbh"+str(i)+" = _mm512_add_epi64(b512"+str(i)+",carry);\n"
		f.write(line)
		line = "\tblpbh"+str(i)+" = _mm512_add_epi64(blpbh"+str(i)+",b512"+str(i+tk)+");\n"
		f.write(line)
		line = "\tcarry = blpbh"+str(i)+">>52;\n"
		f.write(line)
		line = "\tblpbh"+str(i)+" &= mask52;\n"
		f.write(line)



		
	line = "\tD1_0 = _mm512_madd52lo_epu64(D0_"+str(tk)+",alpah0,blpbh0);\n"
	f.write(line)
	line = "\tD1_1 = _mm512_madd52hi_epu64(D0_"+str(tk+1)+",alpah0,blpbh0);\n"
	f.write(line)


	for j in range(1,tk-1):
		line = "\tD1_"+str(j)+" = _mm512_madd52lo_epu64(D1_"+str(j)+",alpah0,blpbh"+str(j)+");\n"
		f.write(line)
		line = "\tD1_"+str(j+1)+" = _mm512_madd52hi_epu64(D0_"+str(tk+1+j)+",alpah0,blpbh"+str(j)+");\n"
		f.write(line)
	line = "\tD1_"+str(tk-1)+" = _mm512_madd52lo_epu64(D1_"+str(tk-1)+",alpah0,blpbh"+str(tk-1)+");\n"
	f.write(line)
	line = "\tD1_"+str(tk)+" = _mm512_madd52hi_epu64(zero,alpah0,blpbh"+str(tk-1)+");\n"
	f.write(line)
	f.write("\n")
		
		
	for i in range(1,tk):
		for j in range(tk-1):
			line="\tD1_"+str(i+j)+" = _mm512_madd52lo_epu64(D1_"+str(i+j)+",alpah"+str(i)+",blpbh"+str(j)+");\n"
			#print(line)
			f.write(line)
			line="\tD1_"+str(i+j+1)+" = _mm512_madd52hi_epu64(D1_"+str(i+j+1)+",alpah"+str(i)+",blpbh"+str(j)+");\n"
			#print(line)
			f.write(line)
		
		line="\tD1_"+str(i+tk-1)+" = _mm512_madd52lo_epu64(D1_"+str(i+tk-1)+",alpah"+str(i)+",blpbh"+str(tk-1)+");\n"
		#print(line)
		f.write(line)
		line="\tD1_"+str(i+tk)+" = _mm512_madd52hi_epu64(zero,alpah"+str(i)+",blpbh"+str(tk-1)+");\n"
		#print(line)
		f.write(line)
		f.write("\n")
	
		
	f.write("\n\t// Carry management\n\n")
		
	line="\tcarry  = _mm512_srli_epi64(D1_0,52);\n"
	f.write(line)
	line="\tD1_0 = _mm512_and_si512(D1_0,mask52);\n"
	f.write(line)
	line="\tD1_1 = _mm512_add_epi64(D1_1,carry);\n"
	f.write(line)
	for i in range(2,2*tk-1):
		line="\tcarry  = _mm512_srli_epi64(D1_"+str(i-1)+",52);\n"
		f.write(line)
		line="\tD1_"+str(i)+" = _mm512_add_epi64(D1_"+str(i)+",carry);\n"
		f.write(line)
		line="\tD1_"+str(i-1)+" = _mm512_and_si512(D1_"+str(i-1)+",mask52);\n"
		f.write(line)
	line="\tcarry  = _mm512_srli_epi64(D1_"+str(2*tk-2)+",52);\n"
	f.write(line)
	line="\tD1_"+str(2*tk-1)+" = _mm512_add_epi64(D1_"+str(2*tk-1)+",carry);\n"
	f.write(line)
	line="\tD1_"+str(2*tk-2)+" = _mm512_and_si512(D1_"+str(2*tk-2)+",mask52);\n"
	f.write(line)


		
	f.write("\n\t// Conversion in base 2^"+str(split)+"\n\n")

	line="\tcarry  = _mm512_srli_epi64(D1_"+str(tk-1)+",51);\n"
	f.write(line)
	line="\tD1_"+str(tk-1)+" = _mm512_and_si512(D1_"+str(tk-1)+",mask51);// radix 2^"+str(split)+"\n"
	f.write(line)
	line="\tD1_"+str(tk)+" = _mm512_add_epi64(_mm512_slli_epi64(D1_"+str(tk)+",1),carry);\n"
	f.write(line)
	line="\tD1_"+str(tk)+" = _mm512_add_epi64(D1_"+str(tk)+",D2_0);\n"
	f.write(line)

	for i in range(tk,2*tk-1):
		line = "\tcarry = _mm512_srli_epi64(D1_"+str(i)+",52);\n"
		f.write(line)
		line="\tD1_"+str(i)+" = _mm512_and_si512(D1_"+str(i)+",mask52);\n"
		f.write(line)
		line="\tD1_"+str(i+1)+" = _mm512_add_epi64(_mm512_slli_epi64(D1_"+str(i+1)+",1),carry);\n"
		f.write(line)
		line="\tD1_"+str(i+1)+" = _mm512_add_epi64(D1_"+str(i+1)+",D2_"+str(i+1-tk)+");\n"
		f.write(line)
	line="\tcarry  = _mm512_srli_epi64(D1_"+str(2*tk-1)+",51);\n"
	f.write(line)
	line="\tD1_"+str(2*tk-1)+" = _mm512_and_si512(D1_"+str(2*tk-1)+",mask51);// radix 2^"+str(split)+"\n"
	f.write(line)


		
	f.write("\n\t// Final reconstruction\n\n")

	f.write("\n\t// tmp = D0+D2, radix 2^"+str(split)+"\n\n")
	
	line="\t__m512i tmp0 = _mm512_add_epi64(D0_0,D2_0);\n"
	f.write(line)
	line="\t__m512i carry_tmp  = _mm512_srli_epi64(tmp0,52);\n"
	f.write(line)
	line="\ttmp0 = _mm512_and_si512(tmp0,mask52);\n\n"
	f.write(line)

	for i in range(1,tk-1):
		line="\t__m512i tmp"+str(i)+" = _mm512_add_epi64(D0_"+str(i)+",carry_tmp);\n"
		f.write(line)
		line="\ttmp"+str(i)+" = _mm512_add_epi64(tmp"+str(i)+",D2_"+str(i)+");\n"
		f.write(line)
		line="\tcarry_tmp  = _mm512_srli_epi64(tmp"+str(i)+",52);\n"
		f.write(line)
		line="\ttmp"+str(i)+" = _mm512_and_si512(tmp"+str(i)+",mask52);\n\n"
		f.write(line)
	
	line="\t__m512i tmp"+str(tk-1)+" = _mm512_add_epi64(D0_"+str(tk-1)+",carry_tmp);\n"
	f.write(line)
	line="\ttmp"+str(tk-1)+" = _mm512_add_epi64(tmp"+str(tk-1)+",D2_"+str(tk-1)+");\n"
	f.write(line)
	line="\tcarry_tmp  = _mm512_srli_epi64(tmp"+str(tk-1)+",51);\n"
	f.write(line)
	line="\ttmp"+str(tk-1)+" = _mm512_and_si512(tmp"+str(tk-1)+",mask51);// radix 2**"+str(split)+"\n\n"
	f.write(line)

	for i in range(tk,2*tk-1):
		line="\t__m512i tmp"+str(i)+" = _mm512_add_epi64(D0_"+str(i)+",carry_tmp);\n"
		f.write(line)
		line="\ttmp"+str(i)+" = _mm512_add_epi64(tmp"+str(i)+",D2_"+str(i)+");\n"
		f.write(line)
		line="\tcarry_tmp  = _mm512_srli_epi64(tmp"+str(i)+",52);\n"
		f.write(line)
		line="\ttmp"+str(i)+" = _mm512_and_si512(tmp"+str(i)+",mask52);\n\n"
		f.write(line)
	
	line="\t__m512i tmp"+str(2*tk-1)+" = _mm512_add_epi64(D0_"+str(2*tk-1)+",carry_tmp);\n"
	f.write(line)
	line="\ttmp"+str(2*tk-1)+" = _mm512_add_epi64(tmp"+str(2*tk-1)+",D2_"+str(2*tk-1)+");\n"
	f.write(line)
	line="\tcarry_tmp  = _mm512_srli_epi64(tmp"+str(2*tk-1)+",51);\n"
	f.write(line)
	line="\ttmp"+str(2*tk-1)+" = _mm512_and_si512(tmp"+str(2*tk-1)+",mask51);// radix 2**"+str(split)+"\n\n"
	f.write(line)
	f.write("\n\n")

	f.write("\n\t// D1 = D1 -tmp, radix 2^"+str(split)+"\n\n")
	for i in range(tk,2*tk):
		line = "\t__m512i c512"+str(i)+" = _mm512_load_epi64(c512+"+str(i)+");\n"
		f.write(line)

	line="\tD1_0 = _mm512_add_epi64(c512"+str(tk)+",D1_0);\n"
	f.write(line)
	line="\tD1_0 = _mm512_sub_epi64(D1_0,tmp0);\n"
	f.write(line)
	line="\t__m512i borrow = _mm512_srli_epi64(D1_0,52)&un;\n"
	f.write(line)
	line="\tD1_0 = _mm512_and_si512(D1_0,mask52);\n\n"
	f.write(line)
	
	for i in range(1,tk-1):
		line="\tborrow = _mm512_add_epi64(tmp"+str(i)+",borrow);\n"
		f.write(line)
		line="\tD1_"+str(i)+" = _mm512_add_epi64(c512"+str(i+tk)+",D1_"+str(i)+");\n"
		f.write(line)
		line="\tD1_"+str(i)+" = _mm512_sub_epi64(D1_"+str(i)+",borrow);\n"
		f.write(line)
		line="\tborrow  = _mm512_srli_epi64(D1_"+str(i)+",52)&un;\n"
		f.write(line)
		line="\tD1_"+str(i)+" = _mm512_and_si512(D1_"+str(i)+",mask52);\n\n"
		f.write(line)
		
	line="\tborrow = _mm512_add_epi64(tmp"+str(tk-1)+",borrow);\n"
	f.write(line)
	line="\tD1_"+str(tk-1)+" = _mm512_add_epi64(c512"+str(2*tk-1)+",D1_"+str(tk-1)+");\n"
	f.write(line)
	line="\tD1_"+str(tk-1)+" = _mm512_sub_epi64(D1_"+str(tk-1)+",borrow);\n"
	f.write(line)
	line="\tborrow = _mm512_srli_epi64(D1_"+str(tk-1)+",51)&un;\n"
	f.write(line)
	line="\tD1_"+str(tk-1)+" = _mm512_and_si512(D1_"+str(tk-1)+",mask51);// radix 2**"+str(split)+"\n\n"
	f.write(line)


	for i in range(tk,2*tk-1):
		line="\tborrow = _mm512_add_epi64(tmp"+str(i)+",borrow);\n"
		f.write(line)
		line="\tD1_"+str(i)+" = _mm512_sub_epi64(D1_"+str(i)+",borrow);\n"
		f.write(line)
		line="\tborrow  = _mm512_srli_epi64(D1_"+str(i)+",52)&un;\n"
		f.write(line)
		line="\tD1_"+str(i)+" = _mm512_and_si512(D1_"+str(i)+",mask52);\n\n"
		f.write(line)
		
	line="\tborrow = _mm512_add_epi64(tmp"+str(2*tk-1)+",borrow);\n"
	f.write(line)
	line="\tD1_"+str(2*tk-1)+" = _mm512_sub_epi64(D1_"+str(2*tk-1)+",borrow);\n"
	f.write(line)
	line="\tborrow = _mm512_srli_epi64(D1_"+str(2*tk-1)+",51)&un;\n"
	f.write(line)
	line="\tD1_"+str(2*tk-1)+" = _mm512_and_si512(D1_"+str(2*tk-1)+",mask51);// radix 2**"+str(split)+"\n\n"
	f.write(line)


	f.write("\n\t// Final borrows\n\n")

	line="\tborrow = _mm512_add_epi64(carry_tmp,borrow);\n"
	f.write(line)
	line="\tD2_"+str(tk)+" = _mm512_add_epi64(D2_"+str(tk)+",carry);\n"
	f.write(line)

	for i in range(tk,2*tk-1):
		line="\tD2_"+str(i)+" = _mm512_sub_epi64(D2_"+str(i)+",borrow);\n"
		f.write(line)
		line="\tborrow  = _mm512_srli_epi64(D2_"+str(i)+",52)&un;\n"
		f.write(line)
		line="\tD2_"+str(i)+" = _mm512_and_si512(D2_"+str(i)+",mask52);\n\n"
		f.write(line)

	line="\tD2_"+str(2*tk-1)+" = _mm512_sub_epi64(D2_"+str(2*tk-1)+",borrow);\n"
	f.write(line)



	f.write("\n\n")

	for i in range(tk):
		line = "\t_mm512_store_epi64(out+"+str(i)+",D0_"+str(i)+");\n"
		f.write(line)
		
	for i in range(2*tk):
		line = "\t_mm512_store_epi64(out+"+str(i+tk)+",D1_"+str(i)+");\n"
		f.write(line)

	for i in range(tk):
		line = "\t_mm512_store_epi64(out+"+str(i+3*tk)+",D2_"+str(i+tk)+");\n"
		f.write(line)
		
	f.write("\n}\n\n")
		




	'''
		Square generation
	'''
		
	f.write("/* Karatsuba squaring */\n\n")
		

	line = "inline void force_inline square512_8_"+str(SIZE)+"K(__m512i out["+str(2*t)+"], __m512i a512["+str(t)+"])\n{\n"

	print(line)
	f.write(line)
	
	line = "\n\t// D0 = Al^2\n\n"
	f.write(line)
	
	
	for i in range(tk):
		line = "\t__m512i D0_"+str(2*i)+", D0_"+str(2*i+1)+";\n"#, D1_"+str(2*i)+", D1_"+str(2*i+1)+", D2_"+str(2*i)+", D2_"+str(2*i+1)+";\n"
		f.write(line)
		
	line = "\t__m512i a5120 = _mm512_load_epi64(a512);\n"
	f.write(line)
	for i in range(1,tk):
		line = "\t__m512i a512"+str(i)+" = _mm512_load_epi64(a512+"+str(i)+");\n"
		f.write(line)
		
		
	line = "\n\tD0_0 = _mm512_madd52lo_epu64(zero,a5120,a5120);\n\n"
	f.write(line)

	line = "\tD0_1 = _mm512_madd52lo_epu64(zero,a5120,a5121);\n"
	f.write(line)

	line = "\tD0_1 = _mm512_slli_epi64(D0_1,1);\n"
	f.write(line)
	line = "\tD0_1 = _mm512_madd52hi_epu64(D0_1,a5120,a5120);\n"
	f.write(line)
	line = "\t__m512i carry  = _mm512_srli_epi64(D0_1,52);\n\tD0_1 = _mm512_and_si512(D0_1,mask52);\n"
	f.write(line)



	for k in range(2,2*tk-1):
		Lhi=[]
		Llo=[]
		for i in range(tk-1,-1,-1):
			for j in range(i-1,-1,-1):
				if i+j==k-1:
					Lhi.append((i,j))
					
				if i+j==k:
					Llo.append((i,j))
		#print("Lhi =",Lhi)
		#print("Llo =",Llo)
		f.write("\n")
		
		line="\tD0_"+str(k)+" = _mm512_madd52hi_epu64(zero,a512"+str(Lhi[0][1])+",a512"+str(Lhi[0][0])+");\n"
		#print(line)
		f.write(line)
		
		for L in Lhi[1:]:
			line="\tD0_"+str(k)+" = _mm512_madd52hi_epu64(D0_"+str(k)+",a512"+str(L[1])+",a512"+str(L[0])+");\n"
			#print(line)
			f.write(line)

		for L in Llo:
			line="\tD0_"+str(k)+" = _mm512_madd52lo_epu64(D0_"+str(k)+",a512"+str(L[1])+",a512"+str(L[0])+");\n"
			#print(line)
			f.write(line)



		line = "\tD0_"+str(k)+" = _mm512_slli_epi64(D0_"+str(k)+",1);\n"
		f.write(line)
		ka=k//2
		if(k%2==0):
			lo = "lo"
		else:
			lo="hi"
		line="\tD0_"+str(k)+" = _mm512_madd52"+lo+"_epu64(D0_"+str(k)+",a512"+str(ka)+",a512"+str(ka)+");\n"
			#print(line)
		f.write(line)
		
		line = "\tD0_"+str(k)+" = _mm512_add_epi64(D0_"+str(k)+",carry);\n"
		f.write(line)
		
		
		line = "\tcarry  = _mm512_srli_epi64(D0_"+str(k)+",52);\n\tD0_"+str(k)+" = _mm512_and_si512(D0_"+str(k)+",mask52);\n"
		f.write(line)
		
		
		
	line = "\n\tD0_"+str(2*tk-1)+" = _mm512_madd52hi_epu64(carry,a512"+str(tk-1)+",a512"+str(tk-1)+");\n\n"
	f.write(line)

		
	f.write("\n\t// Conversion in base 2^"+str(split)+"\n\n")

	line = "\tcarry = D0_"+str(tk-1)+">>51;\n"
	f.write(line)
	line = "\tD0_"+str(tk)+" = (D0_"+str(tk)+"<<1)|carry;\n"
	f.write(line)
	line = "\tD0_"+str(tk-1)+" &= mask51;\n"
	f.write(line)
	for i in range(tk,tk*2-1):
		line = "\tcarry = D0_"+str(i)+">>52;\n"
		f.write(line)
		line = "\tD0_"+str(i+1)+" = (D0_"+str(i+1)+"<<1)|carry;\n"
		f.write(line)
		line = "\tD0_"+str(i)+" &= mask52;\n"
		f.write(line)
		
		
	
	line = "\n\t// D2 = Ah^2\n\n"
	f.write(line)
	
	
	for i in range(tk):
		line = "\t__m512i D2_"+str(2*i)+", D2_"+str(2*i+1)+";\n"#, D1_"+str(2*i)+", D1_"+str(2*i+1)+", D2_"+str(2*i)+", D2_"+str(2*i+1)+";\n"
		f.write(line)
		
	line = "\t__m512i a512"+str(tk)+" = _mm512_load_epi64(a512+"+str(tk)+");\n"
	f.write(line)
	
	
	for i in range(tk+1,tk*2):
		line = "\t__m512i a512"+str(i)+" = _mm512_load_epi64(a512+"+str(i)+");\n"
		f.write(line)
		
		
	line = "\n\tD2_0 = _mm512_madd52lo_epu64(zero,a512"+str(tk)+",a512"+str(tk)+");\n\n"
	f.write(line)

	line = "\tD2_1 = _mm512_madd52lo_epu64(zero,a512"+str(tk)+",a512"+str(tk+1)+");\n"
	f.write(line)

	line = "\tD2_1 = _mm512_slli_epi64(D2_1,1);\n"
	f.write(line)
	line = "\tD2_1 = _mm512_madd52hi_epu64(D2_1,a512"+str(tk)+",a512"+str(tk)+");\n"
	f.write(line)
	line = "\tcarry  = _mm512_srli_epi64(D2_1,52);\n\tD2_1 = _mm512_and_si512(D2_1,mask52);\n"
	f.write(line)



	for k in range(2,2*tk-1):
		Lhi=[]
		Llo=[]
		for i in range(tk-1,-1,-1):
			for j in range(i-1,-1,-1):
				if i+j==k-1:
					Lhi.append((i,j))
					
				if i+j==k:
					Llo.append((i,j))
		#print("Lhi =",Lhi)
		#print("Llo =",Llo)
		f.write("\n")
		
		line="\tD2_"+str(k)+" = _mm512_madd52hi_epu64(zero,a512"+str(tk+Lhi[0][1])+",a512"+str(tk+Lhi[0][0])+");\n"
		#print(line)
		f.write(line)
		
		for L in Lhi[1:]:
			line="\tD2_"+str(k)+" = _mm512_madd52hi_epu64(D2_"+str(k)+",a512"+str(tk+L[1])+",a512"+str(tk+L[0])+");\n"
			#print(line)
			f.write(line)

		for L in Llo:
			line="\tD2_"+str(k)+" = _mm512_madd52lo_epu64(D2_"+str(k)+",a512"+str(tk+L[1])+",a512"+str(tk+L[0])+");\n"
			#print(line)
			f.write(line)



		line = "\tD2_"+str(k)+" = _mm512_slli_epi64(D2_"+str(k)+",1);\n"
		f.write(line)
		ka=k//2
		if(k%2==0):
			lo = "lo"
		else:
			lo="hi"
		line="\tD2_"+str(k)+" = _mm512_madd52"+lo+"_epu64(D2_"+str(k)+",a512"+str(tk+ka)+",a512"+str(tk+ka)+");\n"
			#print(line)
		f.write(line)
		
		line = "\tD2_"+str(k)+" = _mm512_add_epi64(D2_"+str(k)+",carry);\n"
		f.write(line)
		
		
		line = "\tcarry  = _mm512_srli_epi64(D2_"+str(k)+",52);\n\tD2_"+str(k)+" = _mm512_and_si512(D2_"+str(k)+",mask52);\n"
		f.write(line)
		
		
		
	line = "\n\tD2_"+str(2*tk-1)+" = _mm512_madd52hi_epu64(carry,a512"+str(2*tk-1)+",a512"+str(2*tk-1)+");\n\n"
	f.write(line)	
		
		
		
		
		
			
	f.write("\n\t// Carry management\n\n")
		
	line="\tcarry  = _mm512_srli_epi64(D2_1,52);\n"
	f.write(line)
	line="\tD2_2 = _mm512_add_epi64(D2_2,carry);\n"
	f.write(line)
	line="\tD2_1 = _mm512_and_si512(D2_1,mask52);\n"
	f.write(line)
	for i in range(3,2*tk-1):
		line="\tcarry  = _mm512_srli_epi64(D2_"+str(i-1)+",52);\n"
		f.write(line)
		line="\tD2_"+str(i)+" = _mm512_add_epi64(D2_"+str(i)+",carry);\n"
		f.write(line)
		line="\tD2_"+str(i-1)+" = _mm512_and_si512(D2_"+str(i-1)+",mask52);\n"
		f.write(line)
	line="\tcarry  = _mm512_srli_epi64(D2_"+str(2*tk-2)+",52);\n"
	f.write(line)
	line="\tD2_"+str(2*tk-1)+" = _mm512_add_epi64(D2_"+str(2*tk-1)+",carry);\n"
	f.write(line)
	line="\tD2_"+str(2*tk-2)+" = _mm512_and_si512(D2_"+str(2*tk-2)+",mask52);\n"
	f.write(line)
	
		
	f.write("\n\t// Conversion in base 2^"+str(split)+"\n\n")

	line = "\tcarry = D2_"+str(tk-1)+">>51;\n"
	f.write(line)
	line = "\tD2_"+str(tk)+" = (D2_"+str(tk)+"<<1)|carry;\n"
	f.write(line)
	line = "\tD2_"+str(tk-1)+" &= mask51;\n"
	f.write(line)
	for i in range(tk,tk*2-1):
		line = "\tcarry = D2_"+str(i)+">>52;\n"
		f.write(line)
		line = "\tD2_"+str(i+1)+" = (D2_"+str(i+1)+"<<1)|carry;\n"
		f.write(line)
		line = "\tD2_"+str(i)+" &= mask52;\n"
		f.write(line)



	
	line = "\n\t// D1 = (Al+Ah)^2\n\n"
	f.write(line)
	
	
	for i in range(tk):
		line = "\t__m512i D1_"+str(2*i)+", D1_"+str(2*i+1)+";\n"#, D1_"+str(2*i)+", D1_"+str(2*i+1)+", D2_"+str(2*i)+", D2_"+str(2*i+1)+";\n"
		f.write(line)
		
	f.write("\n")
	line = "\t__m512i alpah0 = _mm512_add_epi64(a5120,a512"+str(tk)+");\n"
	f.write(line)
	line = "\tcarry = alpah0>>52;\n"
	f.write(line)
	line = "\talpah0 &= mask52;\n"
	f.write(line)
	for i in range(1,tk):
		line = "\t__m512i alpah"+str(i)+" = _mm512_add_epi64(a512"+str(i)+",carry);\n"
		f.write(line)
		line = "\talpah"+str(i)+" = _mm512_add_epi64(alpah"+str(i)+",a512"+str(i+tk)+");\n"
		f.write(line)
		line = "\tcarry = alpah"+str(i)+">>52;\n"
		f.write(line)
		line = "\talpah"+str(i)+" &= mask52;\n"
		f.write(line)
	
	line = "\n\tD1_0 = _mm512_madd52lo_epu64(D0_"+str(tk)+",alpah0,alpah0);\n\n"
	f.write(line)

	line = "\tD1_1 = _mm512_madd52lo_epu64(zero,alpah0,alpah1);\n"
	f.write(line)

	line = "\tD1_1 = _mm512_slli_epi64(D1_1,1);\n"
	f.write(line)
	line = "\tD1_1 = _mm512_madd52hi_epu64(D1_1,alpah0,alpah0);\n"
	f.write(line)
	line = "\tD1_1 = _mm512_add_epi64(D0_"+str(tk+1)+",D1_1);\n"
	f.write(line)
	line = "\tcarry  = _mm512_srli_epi64(D1_1,52);\n\tD1_1 = _mm512_and_si512(D1_1,mask52);\n"
	f.write(line)



	for k in range(2,2*tk-1):
		Lhi=[]
		Llo=[]
		for i in range(tk-1,-1,-1):
			for j in range(i-1,-1,-1):
				if i+j==k-1:
					Lhi.append((i,j))
					
				if i+j==k:
					Llo.append((i,j))
		#print("Lhi =",Lhi)
		#print("Llo =",Llo)
		f.write("\n")
		
		line="\tD1_"+str(k)+" = _mm512_madd52hi_epu64(zero,alpah"+str(Lhi[0][1])+",alpah"+str(Lhi[0][0])+");\n"
		#print(line)
		f.write(line)
		
		for L in Lhi[1:]:
			line="\tD1_"+str(k)+" = _mm512_madd52hi_epu64(D1_"+str(k)+",alpah"+str(L[1])+",alpah"+str(L[0])+");\n"
			#print(line)
			f.write(line)

		for L in Llo:
			line="\tD1_"+str(k)+" = _mm512_madd52lo_epu64(D1_"+str(k)+",alpah"+str(L[1])+",alpah"+str(L[0])+");\n"
			#print(line)
			f.write(line)


		line = "\tD1_"+str(k)+" = _mm512_slli_epi64(D1_"+str(k)+",1);\n"
		f.write(line)
		ka=k//2
		if(k%2==0):
			lo = "lo"
		else:
			lo="hi"
		line="\tD1_"+str(k)+" = _mm512_madd52"+lo+"_epu64(D1_"+str(k)+",alpah"+str(ka)+",alpah"+str(ka)+");\n"
			#print(line)
		f.write(line)
		

		if tk+k<2*tk:
			line="\tD1_"+str(k)+" = _mm512_add_epi64(D0_"+str(tk+k)+",D1_"+str(k)+");\n"
			f.write(line)
			
		line = "\tD1_"+str(k)+" = _mm512_add_epi64(D1_"+str(k)+",carry);\n"
		f.write(line)
		
		
		line = "\tcarry  = _mm512_srli_epi64(D1_"+str(k)+",52);\n\tD1_"+str(k)+" = _mm512_and_si512(D1_"+str(k)+",mask52);\n"
		f.write(line)
		
		
		
	line = "\n\tD1_"+str(2*tk-1)+" = _mm512_madd52hi_epu64(carry,alpah"+str(tk-1)+",alpah"+str(tk-1)+");\n\n"
	f.write(line)
		
		
		
	f.write("\n\t// Carry management\n\n")
		
	line="\tcarry  = _mm512_srli_epi64(D1_0,52);\n"
	f.write(line)
	line="\tD1_0 = _mm512_and_si512(D1_0,mask52);\n"
	f.write(line)
	line="\tD1_1 = _mm512_add_epi64(D1_1,carry);\n"
	f.write(line)
	for i in range(2,2*tk-1):
		line="\tcarry  = _mm512_srli_epi64(D1_"+str(i-1)+",52);\n"
		f.write(line)
		line="\tD1_"+str(i)+" = _mm512_add_epi64(D1_"+str(i)+",carry);\n"
		f.write(line)
		line="\tD1_"+str(i-1)+" = _mm512_and_si512(D1_"+str(i-1)+",mask52);\n"
		f.write(line)
	line="\tcarry  = _mm512_srli_epi64(D1_"+str(2*tk-2)+",52);\n"
	f.write(line)
	line="\tD1_"+str(2*tk-1)+" = _mm512_add_epi64(D1_"+str(2*tk-1)+",carry);\n"
	f.write(line)
	line="\tD1_"+str(2*tk-2)+" = _mm512_and_si512(D1_"+str(2*tk-2)+",mask52);\n"
	f.write(line)


		
	f.write("\n\t// Conversion in base 2^"+str(split)+"\n\n")

	line="\tcarry  = _mm512_srli_epi64(D1_"+str(tk-1)+",51);\n"
	f.write(line)
	line="\tD1_"+str(tk-1)+" = _mm512_and_si512(D1_"+str(tk-1)+",mask51);// radix 2^"+str(split)+"\n"
	f.write(line)
	line="\tD1_"+str(tk)+" = _mm512_add_epi64(_mm512_slli_epi64(D1_"+str(tk)+",1),carry);\n"
	f.write(line)
	line="\tD1_"+str(tk)+" = _mm512_add_epi64(D1_"+str(tk)+",D2_0);\n"
	f.write(line)

	for i in range(tk,2*tk-1):
		line = "\tcarry = _mm512_srli_epi64(D1_"+str(i)+",52);\n"
		f.write(line)
		line="\tD1_"+str(i)+" = _mm512_and_si512(D1_"+str(i)+",mask52);\n"
		f.write(line)
		line="\tD1_"+str(i+1)+" = _mm512_add_epi64(_mm512_slli_epi64(D1_"+str(i+1)+",1),carry);\n"
		f.write(line)
		line="\tD1_"+str(i+1)+" = _mm512_add_epi64(D1_"+str(i+1)+",D2_"+str(i+1-tk)+");\n"
		f.write(line)
	line="\tcarry  = _mm512_srli_epi64(D1_"+str(2*tk-1)+",51);\n"
	f.write(line)
	line="\tD1_"+str(2*tk-1)+" = _mm512_and_si512(D1_"+str(2*tk-1)+",mask51);// radix 2^"+str(split)+"\n"
	f.write(line)


		
	f.write("\n\t// Final reconstruction\n\n")

	f.write("\n\t// tmp = D0+D2, radix 2^"+str(split)+"\n\n")
	
	line="\t__m512i tmp0 = _mm512_add_epi64(D0_0,D2_0);\n"
	f.write(line)
	line="\t__m512i carry_tmp  = _mm512_srli_epi64(tmp0,52);\n"
	f.write(line)
	line="\ttmp0 = _mm512_and_si512(tmp0,mask52);\n\n"
	f.write(line)

	for i in range(1,tk-1):
		line="\t__m512i tmp"+str(i)+" = _mm512_add_epi64(D0_"+str(i)+",carry_tmp);\n"
		f.write(line)
		line="\ttmp"+str(i)+" = _mm512_add_epi64(tmp"+str(i)+",D2_"+str(i)+");\n"
		f.write(line)
		line="\tcarry_tmp  = _mm512_srli_epi64(tmp"+str(i)+",52);\n"
		f.write(line)
		line="\ttmp"+str(i)+" = _mm512_and_si512(tmp"+str(i)+",mask52);\n\n"
		f.write(line)
	
	line="\t__m512i tmp"+str(tk-1)+" = _mm512_add_epi64(D0_"+str(tk-1)+",carry_tmp);\n"
	f.write(line)
	line="\ttmp"+str(tk-1)+" = _mm512_add_epi64(tmp"+str(tk-1)+",D2_"+str(tk-1)+");\n"
	f.write(line)
	line="\tcarry_tmp  = _mm512_srli_epi64(tmp"+str(tk-1)+",51);\n"
	f.write(line)
	line="\ttmp"+str(tk-1)+" = _mm512_and_si512(tmp"+str(tk-1)+",mask51);// radix 2**"+str(split)+"\n\n"
	f.write(line)

	for i in range(tk,2*tk-1):
		line="\t__m512i tmp"+str(i)+" = _mm512_add_epi64(D0_"+str(i)+",carry_tmp);\n"
		f.write(line)
		line="\ttmp"+str(i)+" = _mm512_add_epi64(tmp"+str(i)+",D2_"+str(i)+");\n"
		f.write(line)
		line="\tcarry_tmp  = _mm512_srli_epi64(tmp"+str(i)+",52);\n"
		f.write(line)
		line="\ttmp"+str(i)+" = _mm512_and_si512(tmp"+str(i)+",mask52);\n\n"
		f.write(line)
	
	line="\t__m512i tmp"+str(2*tk-1)+" = _mm512_add_epi64(D0_"+str(2*tk-1)+",carry_tmp);\n"
	f.write(line)
	line="\ttmp"+str(2*tk-1)+" = _mm512_add_epi64(tmp"+str(2*tk-1)+",D2_"+str(2*tk-1)+");\n"
	f.write(line)
	line="\tcarry_tmp  = _mm512_srli_epi64(tmp"+str(2*tk-1)+",51);\n"
	f.write(line)
	line="\ttmp"+str(2*tk-1)+" = _mm512_and_si512(tmp"+str(2*tk-1)+",mask51);// radix 2**"+str(split)+"\n\n"
	f.write(line)
	f.write("\n\n")

	f.write("\n\t// D1 = D1 -tmp, radix 2^"+str(split)+"\n\n")

	line="\tD1_0 = _mm512_sub_epi64(D1_0,tmp0);\n"
	f.write(line)
	line="\t__m512i borrow = _mm512_srli_epi64(D1_0,52)&un;\n"
	f.write(line)
	line="\tD1_0 = _mm512_and_si512(D1_0,mask52);\n"
	f.write(line)
	
	for i in range(1,tk-1):
		line="\tborrow = _mm512_add_epi64(tmp"+str(i)+",borrow);\n"
		f.write(line)
		line="\tD1_"+str(i)+" = _mm512_sub_epi64(D1_"+str(i)+",borrow);\n"
		f.write(line)
		line="\tborrow  = _mm512_srli_epi64(D1_"+str(i)+",52)&un;\n"
		f.write(line)
		line="\tD1_"+str(i)+" = _mm512_and_si512(D1_"+str(i)+",mask52);\n\n"
		f.write(line)
		
	line="\tborrow = _mm512_add_epi64(tmp"+str(tk-1)+",borrow);\n"
	f.write(line)
	line="\tD1_"+str(tk-1)+" = _mm512_sub_epi64(D1_"+str(tk-1)+",borrow);\n"
	f.write(line)
	line="\tborrow = _mm512_srli_epi64(D1_"+str(tk-1)+",51)&un;\n"
	f.write(line)
	line="\tD1_"+str(tk-1)+" = _mm512_and_si512(D1_"+str(tk-1)+",mask51);// radix 2**"+str(split)+"\n\n"
	f.write(line)


	for i in range(tk,2*tk-1):
		line="\tborrow = _mm512_add_epi64(tmp"+str(i)+",borrow);\n"
		f.write(line)
		line="\tD1_"+str(i)+" = _mm512_sub_epi64(D1_"+str(i)+",borrow);\n"
		f.write(line)
		line="\tborrow  = _mm512_srli_epi64(D1_"+str(i)+",52)&un;\n"
		f.write(line)
		line="\tD1_"+str(i)+" = _mm512_and_si512(D1_"+str(i)+",mask52);\n\n"
		f.write(line)
		
	line="\tborrow = _mm512_add_epi64(tmp"+str(2*tk-1)+",borrow);\n"
	f.write(line)
	line="\tD1_"+str(2*tk-1)+" = _mm512_sub_epi64(D1_"+str(2*tk-1)+",borrow);\n"
	f.write(line)
	line="\tborrow = _mm512_srli_epi64(D1_"+str(2*tk-1)+",51)&un;\n"
	f.write(line)
	line="\tD1_"+str(2*tk-1)+" = _mm512_and_si512(D1_"+str(2*tk-1)+",mask51);// radix 2**"+str(split)+"\n\n"
	f.write(line)


	f.write("\n\t// Final borrows\n\n")

	line="\tborrow = _mm512_add_epi64(carry_tmp,borrow);\n"
	f.write(line)
	line="\tD2_"+str(tk)+" = _mm512_add_epi64(D2_"+str(tk)+",carry);\n"
	f.write(line)

	for i in range(tk,2*tk-1):
		line="\tD2_"+str(i)+" = _mm512_sub_epi64(D2_"+str(i)+",borrow);\n"
		f.write(line)
		line="\tborrow  = _mm512_srli_epi64(D2_"+str(i)+",52)&un;\n"
		f.write(line)
		line="\tD2_"+str(i)+" = _mm512_and_si512(D2_"+str(i)+",mask52);\n\n"
		f.write(line)

	line="\tD2_"+str(2*tk-1)+" = _mm512_sub_epi64(D2_"+str(2*tk-1)+",borrow);\n"
	f.write(line)



	f.write("\n\n")

	for i in range(tk):
		line = "\t_mm512_store_epi64(out+"+str(i)+",D0_"+str(i)+");\n"
		f.write(line)
		
	for i in range(2*tk):
		line = "\t_mm512_store_epi64(out+"+str(i+tk)+",D1_"+str(i)+");\n"
		f.write(line)

	for i in range(tk):
		line = "\t_mm512_store_epi64(out+"+str(i+3*tk)+",D2_"+str(i+tk)+");\n"
		f.write(line)
		
		
		
		
		
		
		

		
	f.write("}\n\n")


	f.close()




