#!/usr/bin/python3

'''

Code generator for schoolbook batch multiplications, using avx512 IFMA52.

'''

for SIZE in {1040,2080,4160}:#{156}:#

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
	
	line = "\t__m512i out512["+str(2*t)+"];\n"
	f.write(line)
	
	line = "\tout512[0] = _mm512_madd52lo_epu64(zero,a512[0],b512[0]);\n"
	f.write(line)
	line = "\tout512[1] = _mm512_madd52hi_epu64(zero,a512[0],b512[0]);\n"
	f.write(line)
	
	for j in range(1,t):
		line = "\tout512["+str(j)+"] = _mm512_madd52lo_epu64(out512["+str(j)+"],a512[0],b512["+str(j)+"]);\n"
		f.write(line)
		line = "\tout512["+str(j+1)+"] = _mm512_madd52hi_epu64(zero,a512[0],b512["+str(j)+"]);\n"
		f.write(line)
	f.write("\n")
	
	line = "\t__m512i q512 = _mm512_madd52lo_epu64(zero,out512[0],n_prime[0]);\n"
	f.write(line)
	f.write("\n")

	line = "\t__m512i t512["+str(t+1)+"];\n"
	f.write(line)

	line = "\tt512[0] = _mm512_madd52lo_epu64(zero,q512,n[0]);\n"
	f.write(line)
	line = "\tt512[1] = _mm512_madd52hi_epu64(zero,q512,n[0]);\n"
	f.write(line)
	
	for j in range(1,t):
		line = "\tt512["+str(j)+"] = _mm512_madd52lo_epu64(t512["+str(j)+"],q512,n["+str(j)+"]);\n"
		f.write(line)
		line = "\tt512["+str(j+1)+"] = _mm512_madd52hi_epu64(zero,q512,n["+str(j)+"]);\n"
		f.write(line)
	f.write("\n")
	
	line = "\tout512[0] = _mm512_add_epi64(out512[0],t512[0]);\n"
	f.write(line)
	line="\t__m512i carry  = _mm512_srli_epi64(out512[0],52);\n"
	f.write(line)
	line="\tout512[0] = _mm512_and_si512(out512[0],mask52);\n"
	f.write(line)
	for j in range(1,t):
		line = "\tout512["+str(j)+"] = _mm512_add_epi64(out512["+str(j)+"],carry);\n"
		f.write(line)
		line = "\tout512["+str(j)+"] = _mm512_add_epi64(out512["+str(j)+"],t512["+str(j)+"]);\n"
		f.write(line)
		line="\tcarry  = _mm512_srli_epi64(out512["+str(j)+"],52);\n"
		f.write(line)
		line="\tout512["+str(j)+"] = _mm512_and_si512(out512["+str(j)+"],mask52);\n"
		f.write(line)





	line = "\tout512["+str(t)+"] = _mm512_add_epi64(out512["+str(t)+"],carry);\n"
	f.write(line)
	line = "\tout512["+str(t)+"] = _mm512_add_epi64(out512["+str(t)+"],t512["+str(t)+"]);\n"
	f.write(line)
	f.write("\n")



	# main loop
	
	for i in range(1,t-1):
	
		# T = a_iB
		
		# Y = Y + a_iB
		
	
		line = "\n\t//Y = Y + a_iB\n\n\tout512["+str(i)+"] = _mm512_madd52lo_epu64(out512["+str(i)+"],a512["+str(i)+"],b512[0]);\n"
		f.write(line)
		line = "\tout512["+str(i+1)+"] = _mm512_madd52hi_epu64(out512["+str(i+1)+"],a512["+str(i)+"],b512[0]);\n"
		f.write(line)
		
		for j in range(1,t-1):
			line = "\tout512["+str(j+i)+"] = _mm512_madd52lo_epu64(out512["+str(j+i)+"],a512["+str(i)+"],b512["+str(j)+"]);\n"
			f.write(line)
			line = "\tout512["+str(j+i+1)+"] = _mm512_madd52hi_epu64(out512["+str(j+i+1)+"],a512["+str(i)+"],b512["+str(j)+"]);\n"
			f.write(line)
			
		line = "\tout512["+str(i+t-1)+"] = _mm512_madd52lo_epu64(out512["+str(i+t-1)+"],a512["+str(i)+"],b512["+str(t-1)+"]);\n"
		f.write(line)
		line = "\tout512["+str(i+t)+"] = _mm512_madd52hi_epu64(zero,a512["+str(i)+"],b512["+str(t-1)+"]);\n"
		f.write(line)
			
			
		f.write("\n")
		
		
		
		
		# q = Y*n_prime mod 2^w
		
		line = "\tq512 = _mm512_madd52lo_epu64(zero,out512["+str(i)+"],n_prime[0]);\n"
		f.write(line)
		f.write("\n")


		# T = q*n
		line = "\tt512[0] = _mm512_madd52lo_epu64(zero,q512,n[0]);\n"
		f.write(line)
		line = "\tt512[1] = _mm512_madd52hi_epu64(zero,q512,n[0]);\n"
		f.write(line)
		
		for j in range(1,t):
			line = "\tt512["+str(j)+"] = _mm512_madd52lo_epu64(t512["+str(j)+"],q512,n["+str(j)+"]);\n"
			f.write(line)
			line = "\tt512["+str(j+1)+"] = _mm512_madd52hi_epu64(zero,q512,n["+str(j)+"]);\n"
			f.write(line)
		f.write("\n")
		
		line = "\tout512["+str(i)+"] = _mm512_add_epi64(out512["+str(i)+"],t512[0]);\n"
		f.write(line)
		line="\tcarry  = _mm512_srli_epi64(out512["+str(i)+"],52);\n"
		f.write(line)
		line="\tout512["+str(i)+"] = _mm512_and_si512(out512["+str(i)+"],mask52);\n"
		f.write(line)
		for j in range(1,t):
			line = "\tout512["+str(j+i)+"] = _mm512_add_epi64(out512["+str(j+i)+"],carry);\n"
			f.write(line)
			line = "\tout512["+str(j+i)+"] = _mm512_add_epi64(out512["+str(j+i)+"],t512["+str(j)+"]);\n"
			f.write(line)
			line="\tcarry  = _mm512_srli_epi64(out512["+str(j+i)+"],52);\n"
			f.write(line)
			line="\tout512["+str(j+i)+"] = _mm512_and_si512(out512["+str(j+i)+"],mask52);\n"
			f.write(line)

		line = "\tout512["+str(t+i)+"] = _mm512_add_epi64(out512["+str(t+i)+"],carry);\n"
		f.write(line)
		line = "\tout512["+str(t+i)+"] = _mm512_add_epi64(out512["+str(t+i)+"],t512["+str(t)+"]);\n"
		f.write(line)
		f.write("\n")




	

	# last loop iteration

	line = "\t// last loop iteration\n\n\tout512["+str(t-1)+"] = _mm512_madd52lo_epu64(out512["+str(t-1)+"],a512["+str(t-1)+"],b512[0]);\n"
	f.write(line)
	line = "\tout512["+str(t)+"] = _mm512_madd52hi_epu64(out512["+str(t)+"],a512["+str(t-1)+"],b512[0]);\n"
	f.write(line)
	
	for j in range(1,t):
		line = "\tout512["+str(j+t-1)+"] = _mm512_madd52lo_epu64(out512["+str(j+t-1)+"],a512["+str(t-1)+"],b512["+str(j)+"]);\n"
		f.write(line)
		line = "\tout512["+str(j+t)+"] = _mm512_madd52hi_epu64(out512["+str(j+t)+"],a512["+str(t-1)+"],b512["+str(j)+"]);\n"
		f.write(line)
	f.write("\n")
	
	line = "\tq512 = _mm512_madd52lo_epu64(zero,out512["+str(t-1)+"],n_prime[0]);\n"
	f.write(line)
	f.write("\n")


	line = "\tt512[0] = _mm512_madd52lo_epu64(zero,q512,n[0]);\n"
	f.write(line)
	line = "\tt512[1] = _mm512_madd52hi_epu64(zero,q512,n[0]);\n"
	f.write(line)
	
	for j in range(1,t):
		line = "\tt512["+str(j)+"] = _mm512_madd52lo_epu64(t512["+str(j)+"],q512,n["+str(j)+"]);\n"
		f.write(line)
		line = "\tt512["+str(j+1)+"] = _mm512_madd52hi_epu64(zero,q512,n["+str(j)+"]);\n"
		f.write(line)
	f.write("\n")

	
	line = "\tout512["+str(t-1)+"] = _mm512_add_epi64(out512["+str(t-1)+"],t512[0]);\n"
	f.write(line)
	line="\tcarry  = _mm512_srli_epi64(out512["+str(t-1)+"],52);\n"
	f.write(line)

	for j in range(0,t-1):
		line = "\tout["+str(j)+"] = _mm512_add_epi64(out512["+str(j+t)+"],carry);\n"
		f.write(line)
		line = "\tout["+str(j)+"] = _mm512_add_epi64(out["+str(j)+"],t512["+str(j+1)+"]);\n"
		f.write(line)
		line="\tcarry  = _mm512_srli_epi64(out["+str(j)+"],52);\n"
		f.write(line)
		line="\tout["+str(j)+"] = _mm512_and_si512(out["+str(j)+"],mask52);\n"
		f.write(line)

	line = "\tout["+str(t-1)+"] = _mm512_add_epi64(out512["+str(2*t-1)+"],carry);\n"
	f.write(line)
	line = "\tout["+str(t-1)+"] = _mm512_add_epi64(out["+str(t-1)+"],t512["+str(t)+"]);\n"
	f.write(line)
	f.write("\n")
	
	
	line = "\t//final subtraction\n\n"
	f.write(line)
	
	
	line = "\t__m512i maskSub = zero - (out["+str(t-1)+"]>>52);\n"
	f.write(line)
	line = "\tcarry = zero;\n\n"
	f.write(line)
	
	line = "\tfor(int i=0;i<"+str(t)+";i++)\n"
	f.write(line)
	line = "\t{\n"
	f.write(line)
	line = "\t\t__m512i sub = carry + (n[i]&maskSub);\n"
	f.write(line)
	line = "\t\tout[i] = out[i]-sub;\n"
	f.write(line)
	line = "\t\tcarry = (out[i]>>52)&1;\n"
	f.write(line)
	line = "\t\tout[i]&=mask52;\n"
	f.write(line)
	line = "\t}\n"
	f.write(line)

	
	
	f.write("\n}\n\n")
	



