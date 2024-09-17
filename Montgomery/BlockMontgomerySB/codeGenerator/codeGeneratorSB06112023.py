#!/usr/bin/python3

'''

Code generator for schoolbook batch multiplications, using avx512 IFMA52.

'''

for SIZE in {4108}:#{260,1040,2080,4160}:#fma style

	line = "sbBlockMont512_"+str(SIZE)+".c"
	f=open(line,"w")

	f.write("/* Schoolbook Block Montgomery multiplication */\n\n")

	t=SIZE//52
	print("t =",t)

	'''
		Multiplication generation
	'''


	line = "inline void force_inline block_mont_mul512_8_"+str(SIZE)+"(__m512i out["+str(t)+"], __m512i a512["+str(t)+"], __m512i b512["+str(t)+"], __m512i n["+str(t)+"], __m512i n_prime[1])\n{\n"

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




	line = "\tout5120 = _mm512_madd52lo_epu64(zero,a5120,b5120);\n"
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

	line = "\t__m512i t512"+str(t+1)+";\n"
	f.write(line)

	line = "\tt5120 = _mm512_madd52lo_epu64(out5120,q512,n0);\n"
	f.write(line)
	line = "\tt5121 = _mm512_madd52hi_epu64(out5121,q512,n0);\n"
	f.write(line)
	
	for j in range(1,t):
		line = "\tt512"+str(j)+" = _mm512_madd52lo_epu64(t512"+str(j)+",q512,n"+str(j)+");\n"
		f.write(line)
		line = "\tt512"+str(j+1)+" = _mm512_madd52hi_epu64(out512"+str(j+1)+",q512,n"+str(j)+");\n"
		f.write(line)
	f.write("\n")
	
	
	line="\t__m512i carry  = _mm512_srli_epi64(t5120,52);\n"
	f.write(line)
	line="\tout5120 = _mm512_and_si512(t5120,mask52);\n"
	f.write(line)
	for j in range(1,t):
		line = "\tt512"+str(j)+" = _mm512_add_epi64(t512"+str(j)+",carry);\n"
		f.write(line)
		line="\tcarry  = _mm512_srli_epi64(t512"+str(j)+",52);\n"
		f.write(line)
		line="\tout512"+str(j)+" = _mm512_and_si512(t512"+str(j)+",mask52);\n"
		f.write(line)

	



	line = "\tout512"+str(t)+" = _mm512_add_epi64(t512"+str(t)+",carry);\n"
	f.write(line)
	f.write("\n")


	
	for i in range(1,t-1):
	
		# T = a_iB
		# Y = Y + a_iB
	
		line = "\n\t//Y = Y + a_iB\n\n\tout512"+str(i)+" = _mm512_madd52lo_epu64(out512"+str(i)+",a512"+str(i)+",b5120);\n"
		f.write(line)
		line = "\tout512"+str(i+1)+" = _mm512_madd52hi_epu64(out512"+str(i+1)+",a512"+str(i)+",b5120);\n"
		f.write(line)
		
		for j in range(1,t-1):
			line = "\tout512"+str(i+j)+" = _mm512_madd52lo_epu64(out512"+str(i+j)+",a512"+str(i)+",b512"+str(j)+");\n"
			f.write(line)
			line = "\tout512"+str(i+j+1)+" = _mm512_madd52hi_epu64(out512"+str(i+j+1)+",a512"+str(i)+",b512"+str(j)+");\n"
			f.write(line)
			
		line = "\tout512"+str(i+t-1)+" = _mm512_madd52lo_epu64(out512"+str(i+t-1)+",a512"+str(i)+",b512"+str(t-1)+");\n"
		f.write(line)
		line = "\tout512"+str(i+t)+" = _mm512_madd52hi_epu64(zero,a512"+str(i)+",b512"+str(t-1)+");\n"
		f.write(line)
			
			
		f.write("\n")
		
		
		
		# q = Y*n_prime mod 2^w
		
		line = "\tq512 = _mm512_madd52lo_epu64(zero,out512"+str(i)+",np0);\n"
		f.write(line)
		f.write("\n")


		# T = q*n
		line = "\tt5120 = _mm512_madd52lo_epu64(out512"+str(i)+",q512,n0);\n"
		f.write(line)
		line = "\tt5121 = _mm512_madd52hi_epu64(out512"+str(i+1)+",q512,n0);\n"
		f.write(line)
		
		for j in range(1,t-1):
			line = "\tt512"+str(j)+" = _mm512_madd52lo_epu64(t512"+str(j)+",q512,n"+str(j)+");\n"
			f.write(line)
			line = "\tt512"+str(j+1)+" = _mm512_madd52hi_epu64(out512"+str(i+j+1)+",q512,n"+str(j)+");\n"
			f.write(line)
		line = "\tt512"+str(t-1)+" = _mm512_madd52lo_epu64(t512"+str(t-1)+",q512,n"+str(t-1)+");\n"
		f.write(line)
		line = "\tt512"+str(t)+" = _mm512_madd52hi_epu64(out512"+str(i+t)+",q512,n"+str(t-1)+");\n"
		f.write(line)
			
			
		f.write("\n")
		
		
		
		line="\tcarry  = _mm512_srli_epi64(t5120,52);\n"
		f.write(line)
		line="\tout512"+str(i)+" = _mm512_and_si512(t5120,mask52);\n"
		f.write(line)
		for j in range(1,t):
			line = "\tt512"+str(j)+" = _mm512_add_epi64(carry,t512"+str(j)+");\n"
			f.write(line)
			line="\tcarry  = _mm512_srli_epi64(t512"+str(j)+",52);\n"
			f.write(line)
			line="\tout512"+str(j+i)+" = _mm512_and_si512(t512"+str(j)+",mask52);\n"
			f.write(line)

		line = "\tout512"+str(t+i)+" = _mm512_add_epi64(t512"+str(t)+",carry);\n"
		f.write(line)
		f.write("\n")




	

	# last loop iteration

	line = "\tout512"+str(t-1)+" = _mm512_madd52lo_epu64(out512"+str(t-1)+",a512"+str(t-1)+",b5120);\n"
	f.write(line)
	line = "\tout512"+str(t)+" = _mm512_madd52hi_epu64(out512"+str(t)+",a512"+str(t-1)+",b5120);\n"
	f.write(line)
	
	for j in range(1,t-1):
		line = "\tout512"+str(j+t-1)+" = _mm512_madd52lo_epu64(out512"+str(j+t-1)+",a512"+str(t-1)+",b512"+str(j)+");\n"
		f.write(line)
		line = "\tout512"+str(j+t)+" = _mm512_madd52hi_epu64(out512"+str(j+t)+",a512"+str(t-1)+",b512"+str(j)+");\n"
		f.write(line)
	line = "\tout512"+str(2*t-2)+" = _mm512_madd52lo_epu64(out512"+str(2*t-2)+",a512"+str(t-1)+",b512"+str(t-1)+");\n"
	f.write(line)
	line = "\tout512"+str(2*t-1)+" = _mm512_madd52hi_epu64(zero,a512"+str(t-1)+",b512"+str(t-1)+");\n"
	f.write(line)
	f.write("\n")
	
	line = "\tq512 = _mm512_madd52lo_epu64(zero,out512"+str(t-1)+",np0);\n"
	f.write(line)
	f.write("\n")


	line = "\tt5120 = _mm512_madd52lo_epu64(out512"+str(t-1)+",q512,n0);\n"
	f.write(line)
	line = "\tt5121 = _mm512_madd52hi_epu64(out512"+str(t)+",q512,n0);\n"
	f.write(line)
	
	for j in range(1,t):
		line = "\tt512"+str(j)+" = _mm512_madd52lo_epu64(t512"+str(j)+",q512,n"+str(j)+");\n"
		f.write(line)
		line = "\tt512"+str(j+1)+" = _mm512_madd52hi_epu64(out512"+str(t+j)+",q512,n"+str(j)+");\n"
		f.write(line)
	f.write("\n")

	
	line="\tcarry  = _mm512_srli_epi64(t5120,52);\n"
	f.write(line)

	for j in range(1,t):
		line = "\tt512"+str(j)+" = _mm512_add_epi64(carry,t512"+str(j)+");\n"
		f.write(line)
		line="\tcarry  = _mm512_srli_epi64(t512"+str(j)+",52);\n"
		f.write(line)
		line="\tout["+str(j-1)+"] = _mm512_and_si512(t512"+str(j)+",mask52);\n"
		f.write(line)

	line = "\tout["+str(t-1)+"] = _mm512_add_epi64(t512"+str(t)+",carry);\n"
	f.write(line)
	f.write("\n")
	
	
	
	f.write("\n}\n\n")

	
	'''
		Square generation
	'''
		
	f.write("/* Schoolbook Block Montgomery squaring */\n\n")


	'''
		Square generation
	'''


	f.write("/* Schoolbook squaring */\n\n")
		

	line = "inline void force_inline block_mont_square512_8_"+str(SIZE)+"(__m512i out["+str(t)+"], __m512i a512["+str(t)+"], __m512i n["+str(t)+"], __m512i n_prime[1])\n{\n"


	f.write(line)

		
	line = "\n}\n\n"


	f.write(line)
	f.close()




