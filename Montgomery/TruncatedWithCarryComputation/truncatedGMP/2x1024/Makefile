OPTIONS= -funroll-all-loops -g -march=native -lgmp -lcrypto -lm 


ifdef TEST
	OPTIONS+= -DTEST
endif

OPTIONS+=$(MACROS)
CC= gcc

main : main.o fonctions.o main.c gmp.c
	$(CC) -o main main.o fonctions.o $(OPTIONS)

main_rdpmc : main_rdpmc.o fonctions.o
	$(CC) -o main_rdpmc main_rdpmc.o fonctions.o $(OPTIONS)

fonctions.o : fonctions.c fonctions.h
	$(CC) -c -O3 fonctions.c $(OPTIONS)

main.o : fonctions.o main.c gmp.c
	$(CC) -c main.c $(OPTIONS)

	
		
all : main


clean :
	rm *.o -fv *~

cleanall : clean
	rm main -f

