#!/usr/bin/sage


import random

SIZE = 4096#2048#1024

SIZE_M_GMP = 4096#2048#1024

SIZE_M_512 = 4154#4158#2078#1038

M_GMP = 2**SIZE_M_GMP

M_512 = 2**SIZE_M_512



n = random.randint(2**SIZE_M_GMP//2,2**SIZE_M_GMP-1)



print("M_GMP =",hex(M_GMP), hex(2**SIZE//2))

#print("n =",n)

n=next_prime(n)
	

F = IntegerModRing(M_GMP)


F2 = IntegerModRing(M_512)

n512=F2(n)
n_gmp=F(n)


print("n =",n,"; is_prime()", is_prime(n))

n_prime_gmp = (-n_gmp%M_GMP)**(-1)%M_GMP

print("n_prime =",n_prime_gmp)

print("check",(-n_gmp*n_prime_gmp)%M_GMP)

n_prime_512 = (-n512)**(-1)%M_512

print("n_prime =",n_prime_512)

print("check",(-n512*n_prime_512)%M_512)

r2_512 = (M_512*M_512)%n

print("r2_512 =",r2_512)


A= randint(2**SIZE_M_GMP//2,2**SIZE_M_GMP-1)

print("A     =",hex(A))

r2_gmp = (M_GMP*M_GMP)%n

T = A*int(r2_gmp)

Q = (T*int(n_prime_gmp))%int(M_GMP)

C = T+Q*n

print("C_gmp =",hex(C))

C=C>>SIZE_M_GMP
print("C_gmp =",hex(C))

T = C

Q = (T*int(n_prime_gmp))%int(M_GMP)
C = T+Q*n

print("C_gmp =",hex(C))

C=C>>SIZE_M_GMP
print("C_gmp =",hex(C))

print()

T = A*int(r2_512)

Q = (T*int(n_prime_512))%int(M_512)

C = T+Q*n
print("C_512 =",hex(C))
C=C>>SIZE_M_512

print("C_512 =",hex(C))

T = C

Q = (T*int(n_prime_512))%int(M_512)
C = T+Q*n

print("C_512 =",hex(C))
C=C>>SIZE_M_512

print("C_512 =",hex(C))


f= open("montParam.c","w")

f.write("/*   Montgomery parameters !*/\n\n")

line = "\tmpz_set_str(modul_p, \""+str(n)+"\",10);\n"
f.write(line)

line = "\tmpz_set_str(p_prime, \""+str(n_prime_512)+"\",10);\n"
f.write(line)


line = "\tmpz_set_str(r2_gmp_512, \""+str(r2_512)+"\",10);\n"
f.write(line)



f.close()

