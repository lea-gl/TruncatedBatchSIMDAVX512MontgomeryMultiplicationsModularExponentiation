#!/usr/bin/python3

'''

Code generator for schoolbook batch multiplications, using avx512 IFMA52.

'''

for SIZE in {104,156,208,260,520,1040,2080,4160,8320}:#	{260}:#

	line = "sb512_"+str(SIZE)+".c"
	f=open(line,"w")

	f.write("/* Schoolbook multiplication modulo M*/\n\n")

	t=SIZE//52
	print("t =",t)
	
	
	'''
		Multiplication generation mod M
	'''


	line = "inline void force_inline block_mont_mul512_8_"+str(SIZE)+"(__m512i out["+str(2*t)+"], __m512i a512["+str(t)+"], __m512i b512["+str(t)+"], __m512i n["+str(t)+"], __m512i n_prime[1])\n{\n"

	print(line)
	f.write(line)
	
	for i in range(t):
		line = "\t__m512i out512"+str(2*i)+", out512"+str(2*i+1)+";\n"
		f.write(line)
		
	for i in range(t+1):
		line = "\t__m512i t512"+str(i)+";\n"
		f.write(line)
	line = "\t__m512i a5120 = _mm512_load_epi64(a512), b5120 = _mm512_load_epi64(b512);\n"
	f.write(line)
	for i in range(1,t):
		line = "\t__m512i a512"+str(i)+" = _mm512_load_epi64(a512+"+str(i)+"), b512"+str(i)+" = _mm512_load_epi64(b512+"+str(i)+");\n"
		f.write(line)
		
	for i in range(t):
		line = "\t__m512i n"+str(i)+" = _mm512_load_epi64(n+"+str(i)+");\n"
		f.write(line)
	
	line = "\n\t__m512i np0 = _mm512_load_epi64(n_prime);\n\n"
	f.write(line)
		
		
	line = "\n\tout5120 = _mm512_madd52lo_epu64(zero,a5120,b5120);\n"
	f.write(line)
	line = "\tout5121 = _mm512_madd52hi_epu64(zero,a5120,b5120);\n"
	f.write(line)
	
	for j in range(1,t):
		line = "\tout512"+str(j)+" = _mm512_madd52lo_epu64(out512"+str(j)+",a5120,b512"+str(j)+");\n"
		f.write(line)
		line = "\tout512"+str(j+1)+" = _mm512_madd52hi_epu64(zero,a5120,b512"+str(j)+");\n"
		f.write(line)
	f.write("\n")
	
	line = "\t__m512i q512 = _mm512_madd52lo_epu64(zero,out5120,np0);\n"
	f.write(line)
	f.write("\n")


	line = "\tt5120 = _mm512_madd52lo_epu64(zero,q512,n0);\n"
	f.write(line)
	line = "\tt5121 = _mm512_madd52hi_epu64(zero,q512,n0);\n"
	f.write(line)
	
	for j in range(1,t):
		line = "\tt512"+str(j)+" = _mm512_madd52lo_epu64(t512"+str(j)+",q512,n"+str(j)+");\n"
		f.write(line)
		line = "\tt512"+str(j+1)+" = _mm512_madd52hi_epu64(zero,q512,n"+str(j)+");\n"
		f.write(line)
	f.write("\n")
	
	line = "\tout5120 = _mm512_add_epi64(out5120,t5120);\n"
	f.write(line)
	line="\t__m512i carry  = _mm512_srli_epi64(out5120,52);\n"
	f.write(line)
	line="\tout5120 = _mm512_and_si512(out5120,mask52);\n"
	f.write(line)
	for j in range(1,t):
		line = "\tout512"+str(j)+" = _mm512_add_epi64(out512"+str(j)+",carry);\n"
		f.write(line)
		line = "\tout512"+str(j)+" = _mm512_add_epi64(out512"+str(j)+",t512"+str(j)+");\n"
		f.write(line)
		line="\tcarry  = _mm512_srli_epi64(out512"+str(j)+",52);\n"
		f.write(line)
		line="\tout512"+str(j)+" = _mm512_and_si512(out512"+str(j)+",mask52);\n"
		f.write(line)





	line = "\tout512"+str(t)+" = _mm512_add_epi64(out512"+str(t)+",carry);\n"
	f.write(line)
	line = "\tout512"+str(t)+" = _mm512_add_epi64(out512"+str(t)+",t512"+str(t)+");\n"
	f.write(line)
	f.write("\n")


	
	for i in range(1,t-1):
	
		# T = a_iB
	
		line = "\n\t//T = a_iB\n\n\tt5120 = _mm512_madd52lo_epu64(zero,a512"+str(i)+",b5120);\n"
		f.write(line)
		line = "\tt5121 = _mm512_madd52hi_epu64(zero,a512"+str(i)+",b5120);\n"
		f.write(line)
		
		for j in range(1,t):
			line = "\tt512"+str(j)+" = _mm512_madd52lo_epu64(t512"+str(j)+",a512"+str(i)+",b512"+str(j)+");\n"
			f.write(line)
			line = "\tt512"+str(j+1)+" = _mm512_madd52hi_epu64(zero,a512"+str(i)+",b512"+str(j)+");\n"
			f.write(line)
		f.write("\n")
		
		
		# Y = Y + a_iB
		
		line = "\tout512"+str(i)+" = _mm512_add_epi64(out512"+str(i)+",t5120);\n"
		f.write(line)
		line="\tcarry  = _mm512_srli_epi64(out512"+str(i)+",52);\n"
		f.write(line)
		line="\tout512"+str(i)+" = _mm512_and_si512(out512"+str(i)+",mask52);\n"
		f.write(line)

		for j in range(1,t):
			line = "\tout512"+str(j+i)+" = _mm512_add_epi64(out512"+str(j+i)+",carry);\n"
			f.write(line)
			line = "\tout512"+str(j+i)+" = _mm512_add_epi64(out512"+str(j+i)+",t512"+str(j)+");\n"
			f.write(line)
			line="\tcarry  = _mm512_srli_epi64(out512"+str(j+i)+",52);\n"
			f.write(line)
			line="\tout512"+str(j+i)+" = _mm512_and_si512(out512"+str(j+i)+",mask52);\n"
			f.write(line)

		line = "\tout512"+str(t+i)+" = _mm512_add_epi64(out512"+str(t+i)+",carry);\n"
		f.write(line)
		line = "\tout512"+str(t+i)+" = _mm512_add_epi64(out512"+str(t+i)+",t512"+str(t)+");\n"
		f.write(line)
		f.write("\n")
		
		
		
		# q = Y*n_prime mod 2^w
		
		line = "\tq512 = _mm512_madd52lo_epu64(zero,out512"+str(i)+",np0);\n"
		f.write(line)
		f.write("\n")


		# T = q*n
		line = "\tt5120 = _mm512_madd52lo_epu64(zero,q512,n0);\n"
		f.write(line)
		line = "\tt5121 = _mm512_madd52hi_epu64(zero,q512,n0);\n"
		f.write(line)
		
		for j in range(1,t):
			line = "\tt512"+str(j)+" = _mm512_madd52lo_epu64(t512"+str(j)+",q512,n"+str(j)+");\n"
			f.write(line)
			line = "\tt512"+str(j+1)+" = _mm512_madd52hi_epu64(zero,q512,n"+str(j)+");\n"
			f.write(line)
		f.write("\n")
		
		line = "\tout512"+str(i)+" = _mm512_add_epi64(out512"+str(i)+",t5120);\n"
		f.write(line)
		line="\tcarry  = _mm512_srli_epi64(out512"+str(i)+",52);\n"
		f.write(line)
		line="\tout512"+str(i)+" = _mm512_and_si512(out512"+str(i)+",mask52);\n"
		f.write(line)
		for j in range(1,t):
			line = "\tout512"+str(j+i)+" = _mm512_add_epi64(out512"+str(j+i)+",carry);\n"
			f.write(line)
			line = "\tout512"+str(j+i)+" = _mm512_add_epi64(out512"+str(j+i)+",t512"+str(j)+");\n"
			f.write(line)
			line="\tcarry  = _mm512_srli_epi64(out512"+str(j+i)+",52);\n"
			f.write(line)
			line="\tout512"+str(j+i)+" = _mm512_and_si512(out512"+str(j+i)+",mask52);\n"
			f.write(line)

		line = "\tout512"+str(t+i)+" = _mm512_add_epi64(out512"+str(t+i)+",carry);\n"
		f.write(line)
		line = "\tout512"+str(t+i)+" = _mm512_add_epi64(out512"+str(t+i)+",t512"+str(t)+");\n"
		f.write(line)
		f.write("\n")




	

	# last loop iteration

	line = "\tout512"+str(t-1)+" = _mm512_madd52lo_epu64(zero,a512"+str(t-1)+",b5120);\n"
	f.write(line)
	line = "\tout512"+str(t)+" = _mm512_madd52hi_epu64(zero,a512"+str(t-1)+",b5120);\n"
	f.write(line)
	
	for j in range(1,t):
		line = "\tout512"+str(j+t-1)+" = _mm512_madd52lo_epu64(out512"+str(j+t-1)+",a512"+str(t-1)+",b512"+str(j)+");\n"
		f.write(line)
		line = "\tout512"+str(j+t)+" = _mm512_madd52hi_epu64(zero,a512"+str(t-1)+",b512"+str(j)+");\n"
		f.write(line)
	f.write("\n")
	
	line = "\tq512 = _mm512_madd52lo_epu64(zero,out512"+str(t-1)+",np0);\n"
	f.write(line)
	f.write("\n")


	line = "\tt5120 = _mm512_madd52lo_epu64(zero,q512,n0);\n"
	f.write(line)
	line = "\tt5121 = _mm512_madd52hi_epu64(zero,q512,n0);\n"
	f.write(line)
	
	for j in range(1,t):
		line = "\tt512"+str(j)+" = _mm512_madd52lo_epu64(t512"+str(j)+",q512,n"+str(j)+");\n"
		f.write(line)
		line = "\tt512"+str(j+1)+" = _mm512_madd52hi_epu64(zero,q512,n"+str(j)+");\n"
		f.write(line)
	f.write("\n")

	
	line = "\tout512"+str(t-1)+" = _mm512_add_epi64(out512"+str(t-1)+",t5120);\n"
	f.write(line)
	line="\tcarry  = _mm512_srli_epi64(out512"+str(t-1)+",52);\n"
	f.write(line)

	for j in range(t,2*t-1):
		line = "\tout["+str(j-t)+"] = _mm512_add_epi64(out512"+str(j)+",carry);\n"
		f.write(line)
		line = "\tout["+str(j-t)+"] = _mm512_add_epi64(out["+str(j-t)+"],t512"+str(j+1-t)+");\n"
		f.write(line)
		line="\tcarry  = _mm512_srli_epi64(out512"+str(j)+",52);\n"
		f.write(line)
		line="\tout["+str(j-t)+"] = _mm512_and_si512(out["+str(j-t)+"],mask52);\n"
		f.write(line)

	line = "\tout["+str(t-1)+"] = _mm512_add_epi64(out512"+str(2*t-1)+",carry);\n"
	f.write(line)
	line = "\tout["+str(t-1)+"] = _mm512_add_epi64(out["+str(t-1)+"],t512"+str(t)+");\n"
	f.write(line)
	f.write("\n")
	

	'''for i in range(t):
		line = "\t_mm512_store_epi64(out+"+str(i)+",out512"+str(t+i)+");\n"
		f.write(line)'''
		
	f.write("}\n\n")
	
	

