#!/usr/bin/python3

'''

Code generator for schoolbook batch multiplications, using avx512 IFMA52.

'''

for SIZE in {4108}:#{1040,2080,4160}:#{104,156,208,260,520,1040,2080,4160,8320}:#{260}:#

	line = "sb512_"+str(SIZE)+".c"
	f=open(line,"w")

	f.write("__m512i un = (__m512i){0x1UL,0x1UL,0x1UL,0x1UL,0x1UL,0x1UL,0x1UL,0x1UL};\n\n/* Schoolbook multiplication modulo M*/\n\n")

	t=SIZE//52
	print("t =",t)
	
	
	'''
		Multiplication generation mod M
	'''


	line = "static inline void force_inline mul512_8_"+str(SIZE)+"_modM(__m512i out["+str(2*t)+"], __m512i a512["+str(t)+"], __m512i b512["+str(t)+"])\n{\n"

	print(line)
	f.write(line)
	
	for i in range(t):
		line = "\t__m512i out"+str(2*i)+", out"+str(2*i+1)+";\n"
		f.write(line)
		
	line = "\t__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512);\n"
	f.write(line)
	for i in range(1,t):
		line = "\t__m512i a512"+str(i)+" = _mm512_load_epi64(a512+"+str(i)+"), b512"+str(i)+" = _mm512_load_epi64(b512+"+str(i)+");\n"
		f.write(line)
		
	line = "\tout0 = _mm512_madd52lo_epu64(zero,a5120,b5120);\n"
	f.write(line)
	line = "\tout1 = _mm512_madd52hi_epu64(zero,a5120,b5120);\n"
	f.write(line)
	
	for j in range(1,t):
		line = "\tout"+str(j)+" = _mm512_madd52lo_epu64(out"+str(j)+",a5120,b512"+str(j)+");\n"
		f.write(line)
		if j+1<t:
			line = "\tout"+str(j+1)+" = _mm512_madd52hi_epu64(zero,a5120,b512"+str(j)+");\n"
			f.write(line)
	f.write("\n")
		
		
	for i in range(1,t):
		for j in range(t-1):
			if i+j<t:
				line="\tout"+str(i+j)+" = _mm512_madd52lo_epu64(out"+str(i+j)+",a512"+str(i)+",b512"+str(j)+");\n"
				#print(line)
				f.write(line)
			if i+j+1<t:
				line="\tout"+str(i+j+1)+" = _mm512_madd52hi_epu64(out"+str(i+j+1)+",a512"+str(i)+",b512"+str(j)+");\n"
				#print(line)
				f.write(line)
		
		if i+t-1<t:
			line="\tout"+str(i+t-1)+" = _mm512_madd52lo_epu64(out"+str(i+t-1)+",a512"+str(i)+",b512"+str(t-1)+");\n"
			#print(line)
			f.write(line)
		if i+t<t:
			line="\tout"+str(i+t)+" = _mm512_madd52hi_epu64(zero,a512"+str(i)+",b512"+str(t-1)+");\n"
			#print(line)
			f.write(line)
		f.write("\n")
	
		
	f.write("\n// Carry management\n\n")
		
	line="\t__m512i carry  = _mm512_srli_epi64(out1,52);\n"
	f.write(line)
	line="\tout2 = _mm512_add_epi64(out2,carry);\n"
	f.write(line)
	line="\tout1 = _mm512_and_si512(out1,mask52);\n"
	f.write(line)
	for i in range(3,t-1):
		line="\tcarry  = _mm512_srli_epi64(out"+str(i-1)+",52);\n"
		f.write(line)
		line="\tout"+str(i)+" = _mm512_add_epi64(out"+str(i)+",carry);\n"
		f.write(line)
		line="\tout"+str(i-1)+" = _mm512_and_si512(out"+str(i-1)+",mask52);\n"
		f.write(line)
	line="\tcarry  = _mm512_srli_epi64(out"+str(t-2)+",52);\n"
	f.write(line)
	line="\tout"+str(t-1)+" = _mm512_add_epi64(out"+str(t-1)+",carry);\n"
	f.write(line)
	line="\tout"+str(t-2)+" = _mm512_and_si512(out"+str(t-2)+",mask52);\n"
	f.write(line)

	line="\tout"+str(t-1)+" = _mm512_and_si512(out"+str(t-1)+",mask52);\n\n"
	f.write(line)
	

	for i in range(t):
		line = "\t_mm512_store_epi64(out+"+str(i)+",out"+str(i)+");\n"
		f.write(line)
	
	f.write("\n}\n\n")
		

	'''
		Multiplication generation
	'''

	f.write("/* Schoolbook multiplication*/\n\n")



	line = "static inline void force_inline mul512_8_"+str(SIZE)+"(__m512i out["+str(2*t)+"], __m512i a512["+str(t)+"], __m512i b512["+str(t)+"])\n{\n"

	print(line)
	f.write(line)
	
	for i in range(t):
		line = "\t__m512i out"+str(2*i)+", out"+str(2*i+1)+";\n"
		f.write(line)
		
	line = "\t__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512);\n"
	f.write(line)
	for i in range(1,t):
		line = "\t__m512i a512"+str(i)+" = _mm512_load_epi64(a512+"+str(i)+"), b512"+str(i)+" = _mm512_load_epi64(b512+"+str(i)+");\n"
		f.write(line)
		
	line = "\tout0 = _mm512_madd52lo_epu64(zero,a5120,b5120);\n"
	f.write(line)
	line = "\tout1 = _mm512_madd52hi_epu64(zero,a5120,b5120);\n"
	f.write(line)
	
	for j in range(1,t):
		line = "\tout"+str(j)+" = _mm512_madd52lo_epu64(out"+str(j)+",a5120,b512"+str(j)+");\n"
		f.write(line)
		line = "\tout"+str(j+1)+" = _mm512_madd52hi_epu64(zero,a5120,b512"+str(j)+");\n"
		f.write(line)
	f.write("\n")
		
		
	for i in range(1,t):
		for j in range(t-1):
			line="\tout"+str(i+j)+" = _mm512_madd52lo_epu64(out"+str(i+j)+",a512"+str(i)+",b512"+str(j)+");\n"
			#print(line)
			f.write(line)
			line="\tout"+str(i+j+1)+" = _mm512_madd52hi_epu64(out"+str(i+j+1)+",a512"+str(i)+",b512"+str(j)+");\n"
			#print(line)
			f.write(line)
		
		line="\tout"+str(i+t-1)+" = _mm512_madd52lo_epu64(out"+str(i+t-1)+",a512"+str(i)+",b512"+str(t-1)+");\n"
		#print(line)
		f.write(line)
		line="\tout"+str(i+t)+" = _mm512_madd52hi_epu64(zero,a512"+str(i)+",b512"+str(t-1)+");\n"
		#print(line)
		f.write(line)
		f.write("\n")
	
		
	f.write("\n// Carry management\n\n")
		
	line="\t__m512i carry  = _mm512_srli_epi64(out1,52);\n"
	f.write(line)
	line="\tout2 = _mm512_add_epi64(out2,carry);\n"
	f.write(line)
	line="\tout1 = _mm512_and_si512(out1,mask52);\n"
	f.write(line)
	for i in range(3,2*t-1):
		line="\tcarry  = _mm512_srli_epi64(out"+str(i-1)+",52);\n"
		f.write(line)
		line="\tout"+str(i)+" = _mm512_add_epi64(out"+str(i)+",carry);\n"
		f.write(line)
		line="\tout"+str(i-1)+" = _mm512_and_si512(out"+str(i-1)+",mask52);\n"
		f.write(line)
	line="\tcarry  = _mm512_srli_epi64(out"+str(2*t-2)+",52);\n"
	f.write(line)
	line="\tout"+str(2*t-1)+" = _mm512_add_epi64(out"+str(2*t-1)+",carry);\n"
	f.write(line)
	line="\tout"+str(2*t-2)+" = _mm512_and_si512(out"+str(2*t-2)+",mask52);\n"
	f.write(line)
	

	for i in range(t):
		line = "\t_mm512_store_epi64(out+"+str(2*i)+",out"+str(2*i)+");\n\t_mm512_store_epi64(out+"+str(2*i+1)+",out"+str(2*i+1)+");\n"
		f.write(line)
	
	f.write("\n}\n\n")
		



	'''
		Multiplication generation-addition
	'''

	f.write("/* Schoolbook multiplyer-adder : out = c + ab */\n\n")


	line = "static inline void force_inline fma512_8_"+str(SIZE)+"(__m512i out["+str(2*t)+"], __m512i a512["+str(t)+"], __m512i b512["+str(t)+"], __m512i c512["+str(2*t)+"])\n{\n"

	print(line)
	f.write(line)
	
	line = "\t__m512i out0 = _mm512_load_epi64(c512), out1 = _mm512_load_epi64(c512+1);\n"
	f.write(line)
	for i in range(1,t):
		line = "\t__m512i out"+str(2*i)+" = _mm512_load_epi64(c512+"+str(2*i)+"), out"+str(2*i+1)+" = _mm512_load_epi64(c512+"+str(2*i+1)+");\n"
		f.write(line)
		
	line = "\t__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512);\n"
	f.write(line)
	for i in range(1,t):
		line = "\t__m512i a512"+str(i)+" = _mm512_load_epi64(a512+"+str(i)+"), b512"+str(i)+" = _mm512_load_epi64(b512+"+str(i)+");\n"
		f.write(line)
		
	line = "\tout0 = _mm512_madd52lo_epu64(out0,a5120,b5120);\n"
	f.write(line)
	line = "\tout1 = _mm512_madd52hi_epu64(out1,a5120,b5120);\n"
	f.write(line)
	
	for j in range(1,t):
		line = "\tout"+str(j)+" = _mm512_madd52lo_epu64(out"+str(j)+",a5120,b512"+str(j)+");\n"
		f.write(line)
		line = "\tout"+str(j+1)+" = _mm512_madd52hi_epu64(out"+str(j+1)+",a5120,b512"+str(j)+");\n"
		f.write(line)
	f.write("\n")
		
		
	for i in range(1,t):
		for j in range(t-1):
			line="\tout"+str(i+j)+" = _mm512_madd52lo_epu64(out"+str(i+j)+",a512"+str(i)+",b512"+str(j)+");\n"
			#print(line)
			f.write(line)
			line="\tout"+str(i+j+1)+" = _mm512_madd52hi_epu64(out"+str(i+j+1)+",a512"+str(i)+",b512"+str(j)+");\n"
			#print(line)
			f.write(line)
		
		line="\tout"+str(i+t-1)+" = _mm512_madd52lo_epu64(out"+str(i+t-1)+",a512"+str(i)+",b512"+str(t-1)+");\n"
		#print(line)
		f.write(line)
		line="\tout"+str(i+t)+" = _mm512_madd52hi_epu64(out"+str(i+t)+",a512"+str(i)+",b512"+str(t-1)+");\n"
		#print(line)
		f.write(line)
		f.write("\n")
	
		
	f.write("\n// Carry management\n\n")
		
	line="\t__m512i carry  = _mm512_srli_epi64(out0,52);\n"
	f.write(line)
	line="\tout1 = _mm512_add_epi64(out1,carry);\n"
	f.write(line)
	line="\tout0 = _mm512_and_si512(out0,mask52);\n"
	f.write(line)
	for i in range(2,2*t-1):
		line="\tcarry  = _mm512_srli_epi64(out"+str(i-1)+",52);\n"
		f.write(line)
		line="\tout"+str(i)+" = _mm512_add_epi64(out"+str(i)+",carry);\n"
		f.write(line)
		line="\tout"+str(i-1)+" = _mm512_and_si512(out"+str(i-1)+",mask52);\n"
		f.write(line)
	line="\tcarry  = _mm512_srli_epi64(out"+str(2*t-2)+",52);\n"
	f.write(line)
	line="\tout"+str(2*t-1)+" = _mm512_add_epi64(out"+str(2*t-1)+",carry);\n"
	f.write(line)
	line="\tout"+str(2*t-2)+" = _mm512_and_si512(out"+str(2*t-2)+",mask52);\n"
	f.write(line)
	

	for i in range(t):
		line = "\t_mm512_store_epi64(out+"+str(2*i)+",out"+str(2*i)+");\n\t_mm512_store_epi64(out+"+str(2*i+1)+",out"+str(2*i+1)+");\n"
		f.write(line)
	
	f.write("\n}\n\n")
	
	
	
	
	
	
	
	
	
		
	f.write("/* Truncated Schoolbook multiplyer-adder : out = c + ab */\n\n")


	line = "static inline void force_inline fma512_8_"+str(SIZE)+"_truncated (__m512i out["+str(2*t)+"], __m512i a512["+str(t)+"], __m512i b512["+str(t)+"], __m512i c512["+str(2*t)+"])\n{\n"

	print(line)
	f.write(line)
	
	#line = "\t__m512i out0 = _mm512_load_epi64(c512), out1 = _mm512_load_epi64(c512+1);\n"
	#f.write(line)
	line = "\t__m512i out"+str(t-1)+" = _mm512_load_epi64(c512+"+str(t-1)+");\n"
	f.write(line)
	for i in range(t//2,t):
		line = "\t__m512i out"+str(2*i)+" = _mm512_load_epi64(c512+"+str(2*i)+"), out"+str(2*i+1)+" = _mm512_load_epi64(c512+"+str(2*i+1)+");\n"
		f.write(line)
		
	line = "\t__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512);\n"
	f.write(line)
	for i in range(1,t):
		line = "\t__m512i a512"+str(i)+" = _mm512_load_epi64(a512+"+str(i)+"), b512"+str(i)+" = _mm512_load_epi64(b512+"+str(i)+");\n\n"
		f.write(line)
		
	#line = "\tout0 = _mm512_madd52lo_epu64(out0,a5120,b5120);\n"
	#f.write(line)
	line = "\tout"+str(t-1)+" = _mm512_madd52hi_epu64(out"+str(t-1)+",a5120,b512"+str(t-2)+");\n"
	f.write(line)
	
	for j in range(t-1,t):
		line = "\tout"+str(j)+" = _mm512_madd52lo_epu64(out"+str(j)+",a5120,b512"+str(j)+");\n"
		f.write(line)
		line = "\tout"+str(j+1)+" = _mm512_madd52hi_epu64(out"+str(j+1)+",a5120,b512"+str(j)+");\n"
		f.write(line)
	f.write("\n")
		
		
	for i in range(1,t-1):
		line = "\tout"+str(t-1)+" = _mm512_madd52hi_epu64(out"+str(t-1)+",a512"+str(i)+",b512"+str(t-2-i)+");\n"
		f.write(line)
	
	
		for j in range(t-1-i,t-1):
			line="\tout"+str(i+j)+" = _mm512_madd52lo_epu64(out"+str(i+j)+",a512"+str(i)+",b512"+str(j)+");\n"
			#print(line)
			f.write(line)
			line="\tout"+str(i+j+1)+" = _mm512_madd52hi_epu64(out"+str(i+j+1)+",a512"+str(i)+",b512"+str(j)+");\n"
			#print(line)
			f.write(line)
		
		line="\tout"+str(i+t-1)+" = _mm512_madd52lo_epu64(out"+str(i+t-1)+",a512"+str(i)+",b512"+str(t-1)+");\n"
		#print(line)
		f.write(line)
		line="\tout"+str(i+t)+" = _mm512_madd52hi_epu64(out"+str(i+t)+",a512"+str(i)+",b512"+str(t-1)+");\n"
		#print(line)
		f.write(line)
		f.write("\n")
	
	'''#line = "\n\tout"+str(t-1)+" = _mm512_madd52lo_epu64(out"+str(t-1)+",a512"+str(t-1)+",b5120);\n"
	#f.write(line)
	
	line = "\tout"+str(t-1)+" = _mm512_madd52hi_epu64(out"+str(t-1)+",a512"+str(t-2)+",b5120);\n"
	f.write(line)
	
	for j in range(1,t-1):
		line="\tout"+str(t-2+j)+" = _mm512_madd52lo_epu64(out"+str(t-2+j)+",a512"+str(t-2)+",b512"+str(j)+");\n"
		#print(line)
		f.write(line)
		line="\tout"+str(t-2+j+1)+" = _mm512_madd52hi_epu64(out"+str(t-2+j+1)+",a512"+str(t-2)+",b512"+str(j)+");\n"
		#print(line)
		f.write(line)
		
	line="\tout"+str(2*t-3)+" = _mm512_madd52lo_epu64(out"+str(2*t-3)+",a512"+str(t-2)+",b512"+str(t-1)+");\n"
	#print(line)
	f.write(line)
	line="\tout"+str(2*t-2)+" = _mm512_madd52hi_epu64(out"+str(2*t-2)+",a512"+str(t-2)+",b512"+str(t-1)+");\n"
	#print(line)
	f.write(line)
	f.write("\n")
	f.write("\n")
	'''
		
	for j in range(1,t):
		line="\tout"+str(t-2+j)+" = _mm512_madd52lo_epu64(out"+str(t-2+j)+",a512"+str(t-1)+",b512"+str(j-1)+");\n"
		#print(line)
		f.write(line)
		line="\tout"+str(t-2+j+1)+" = _mm512_madd52hi_epu64(out"+str(t-2+j+1)+",a512"+str(t-1)+",b512"+str(j-1)+");\n"
		#print(line)
		f.write(line)

	
	line="\tout"+str(2*t-2)+" = _mm512_madd52lo_epu64(out"+str(2*t-2)+",a512"+str(t-1)+",b512"+str(t-1)+");\n"
	#print(line)
	f.write(line)
	line="\tout"+str(2*t-1)+" = _mm512_madd52hi_epu64(out"+str(2*t-1)+",a512"+str(t-1)+",b512"+str(t-1)+");\n"
	#print(line)
	f.write(line)
	f.write("\n")



	
	f.write("\n// Carry management\n\n")
		
	#line="\t__m512i carry  = _mm512_srli_epi64(out0,52);\n"
	#f.write(line)
	#line="\tout1 = _mm512_add_epi64(out1,carry);\n"
	#f.write(line)
	#line="\tout0 = _mm512_and_si512(out0,mask52);\n"
	#f.write(line)
	line="\t__m512i"
	f.write(line)
	for i in range(t,t+1):
		line="\tcarry  = _mm512_srli_epi64(out"+str(i-1)+",52);\n"
		f.write(line)
		line="\tout"+str(i)+" = _mm512_add_epi64(out"+str(i)+",carry);\n"
		f.write(line)
		line="\tout"+str(i-1)+" = _mm512_and_si512(out"+str(i-1)+",mask52);\n"
		f.write(line)
		
	line="\n\tout"+str(t)+" = _mm512_add_epi64(out"+str(t)+",un);\n\n"
	f.write(line)
		
		
	for i in range(t+1,2*t-1):
		line="\tcarry  = _mm512_srli_epi64(out"+str(i-1)+",52);\n"
		f.write(line)
		line="\tout"+str(i)+" = _mm512_add_epi64(out"+str(i)+",carry);\n"
		f.write(line)
		line="\tout"+str(i-1)+" = _mm512_and_si512(out"+str(i-1)+",mask52);\n"
		f.write(line)
		
		
	line="\tcarry  = _mm512_srli_epi64(out"+str(2*t-2)+",52);\n"
	f.write(line)
	line="\tout"+str(2*t-1)+" = _mm512_add_epi64(out"+str(2*t-1)+",carry);\n"
	f.write(line)
	line="\tout"+str(2*t-2)+" = _mm512_and_si512(out"+str(2*t-2)+",mask52);\n"
	f.write(line)
	
	line = "\t_mm512_store_epi64(out+"+str(t-1)+",out"+str(t-1)+");\n"
	f.write(line)

	for i in range(t//2,t):
		line = "\t_mm512_store_epi64(out+"+str(2*i)+",out"+str(2*i)+");\n\t_mm512_store_epi64(out+"+str(2*i+1)+",out"+str(2*i+1)+");\n"
		f.write(line)
	
	f.write("\n}\n\n")
		




	'''
		Square generation
	'''
		

	f.write("/* Schoolbook squaring */\n\n")
		

	line = "static inline void force_inline square512_8_"+str(SIZE)+"(__m512i out["+str(2*t)+"], __m512i a512["+str(t)+"])\n{\n"

	print(line)
	f.write(line)
	
	for i in range(t):
		line = "\t__m512i out"+str(2*i)+", out"+str(2*i+1)+";\n"
		f.write(line)
		
	line = "\t__m512i a5120 = _mm512_load_epi64(a512);\n"
	f.write(line)
	for i in range(1,t):
		line = "\t__m512i a512"+str(i)+" = _mm512_load_epi64(a512+"+str(i)+");\n"
		f.write(line)

	line = "\tout0 = _mm512_madd52lo_epu64(zero,a5120,a5120);\n\n"
	f.write(line)

	line = "\tout1 = _mm512_madd52lo_epu64(zero,a5120,a5121);\n"
	f.write(line)

	line = "\tout1 = _mm512_slli_epi64(out1,1);\n"
	f.write(line)
	line = "\tout1 = _mm512_madd52hi_epu64(out1,a5120,a5120);\n"
	f.write(line)
	line = "\t__m512i carry  = _mm512_srli_epi64(out1,52);\n\tout1 = _mm512_and_si512(out1,mask52);\n"
	f.write(line)



	for k in range(2,2*t-1):
		Lhi=[]
		Llo=[]
		for i in range(t-1,-1,-1):
			for j in range(i-1,-1,-1):
				if i+j==k-1:
					Lhi.append((i,j))
					
				if i+j==k:
					Llo.append((i,j))
		#print("Lhi =",Lhi)
		#print("Llo =",Llo)
		f.write("\n")
		
		line="\tout"+str(k)+" = _mm512_madd52hi_epu64(zero,a512"+str(Lhi[0][1])+",a512"+str(Lhi[0][0])+");\n"
		#print(line)
		f.write(line)
		
		for L in Lhi[1:]:
			line="\tout"+str(k)+" = _mm512_madd52hi_epu64(out"+str(k)+",a512"+str(L[1])+",a512"+str(L[0])+");\n"
			#print(line)
			f.write(line)

		for L in Llo:
			line="\tout"+str(k)+" = _mm512_madd52lo_epu64(out"+str(k)+",a512"+str(L[1])+",a512"+str(L[0])+");\n"
			#print(line)
			f.write(line)



		line = "\tout"+str(k)+" = _mm512_slli_epi64(out"+str(k)+",1);\n"
		f.write(line)
		ka=k//2
		if(k%2==0):
			lo = "lo"
		else:
			lo="hi"
		line="\tout"+str(k)+" = _mm512_madd52"+lo+"_epu64(out"+str(k)+",a512"+str(ka)+",a512"+str(ka)+");\n"
			#print(line)
		f.write(line)
		
		line = "\tout"+str(k)+" = _mm512_add_epi64(out"+str(k)+",carry);\n"
		f.write(line)
		
		
		line = "\tcarry  = _mm512_srli_epi64(out"+str(k)+",52);\n\tout"+str(k)+" = _mm512_and_si512(out"+str(k)+",mask52);\n"
		f.write(line)
		
		
		
	line = "\n\tout"+str(2*t-1)+" = _mm512_madd52hi_epu64(carry,a512"+str(t-1)+",a512"+str(t-1)+");\n\n"



	f.write(line)

	for i in range(t):
		line = "\t_mm512_store_epi64(out+"+str(2*i)+",out"+str(2*i)+");\n\t_mm512_store_epi64(out+"+str(2*i+1)+",out"+str(2*i+1)+");\n"
		f.write(line)
		
	f.write("}\n\n")
	'''
	
	f.write("/* Schoolbook squaring */\n\n")
		

	line = "inline void force_inline square512_8_SIZE(__m512i out["+str(2*t)+"], __m512i a512["+str(t)+"])\n{\n"

	print(line)
	f.write(line)

	line = "\tout[0] = _mm512_madd52lo_epu64(zero,a512[0],a512[0]);\n\n"
	f.write(line)

	line = "\tout[1] = _mm512_madd52lo_epu64(zero,a512[0],a512[1]);\n"
	f.write(line)

	line = "\tout[1] = _mm512_slli_epi64(out[1],1);\n"
	f.write(line)
	line = "\tout[1] = _mm512_madd52hi_epu64(out[1],a512[0],a512[0]);\n"
	f.write(line)
	line = "\t__m512i carry  = _mm512_srli_epi64(out[1],52);\n\tout[1] = _mm512_and_si512(out[1],mask52);\n"
	f.write(line)



	for k in range(2,2*t-1):
		Lhi=[]
		Llo=[]
		for i in range(t-1,-1,-1):
			for j in range(i-1,-1,-1):
				if i+j==k-1:
					Lhi.append((i,j))
					
				if i+j==k:
					Llo.append((i,j))
		#print("Lhi =",Lhi)
		#print("Llo =",Llo)
		f.write("\n")
		
		line="\tout["+str(k)+"] = _mm512_madd52hi_epu64(zero,a512["+str(Lhi[0][1])+"],a512["+str(Lhi[0][0])+"]);\n"
		#print(line)
		f.write(line)
		
		for L in Lhi[1:]:
			line="\tout["+str(k)+"] = _mm512_madd52hi_epu64(out["+str(k)+"],a512["+str(L[1])+"],a512["+str(L[0])+"]);\n"
			#print(line)
			f.write(line)

		for L in Llo:
			line="\tout["+str(k)+"] = _mm512_madd52lo_epu64(out["+str(k)+"],a512["+str(L[1])+"],a512["+str(L[0])+"]);\n"
			#print(line)
			f.write(line)



		line = "\tout["+str(k)+"] = _mm512_slli_epi64(out["+str(k)+"],1);\n"
		f.write(line)
		ka=k//2
		if(k%2==0):
			lo = "lo"
		else:
			lo="hi"
		line="\tout["+str(k)+"] = _mm512_madd52"+lo+"_epu64(out["+str(k)+"],a512["+str(ka)+"],a512["+str(ka)+"]);\n"
			#print(line)
		f.write(line)
		
		line = "\tout["+str(k)+"] = _mm512_add_epi64(out["+str(k)+"],carry);\n"
		f.write(line)
		
		
		line = "\tcarry  = _mm512_srli_epi64(out["+str(k)+"],52);\n\tout["+str(k)+"] = _mm512_and_si512(out["+str(k)+"],mask52);\n"
		f.write(line)
		
		
		
	line = "\n\tout["+str(2*t-1)+"] = _mm512_madd52hi_epu64(carry,a512["+str(t-1)+"],a512["+str(t-1)+"]);\n}\n\n"



	f.write(line)
	'''
	f.close()




