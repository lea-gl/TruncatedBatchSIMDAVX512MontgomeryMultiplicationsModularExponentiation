MACROS= -funroll-all-loops -g -march=native -lgmp  -lm 

#OPTIONS= -funroll-all-loops -g -march=native -lgmp -lcrypto -lm 

ifdef TEST
	OPTIONS+= -DWIN_WIDTH=$(WIN_WIDTH) -DTEST
endif

LIBS= -L/home/anonymous/openssl3/lib64/ -lcrypto
INCLUDE=-I/home/anonymous/openssl3/include/ 


OPTIONS=$(INCLUDE)
OPTIONS+=$(LIBS)

OPTIONS+=$(MACROS)
CC= gcc

main : main.c main.o fonctions.o
	$(CC) -o main main.o fonctions.o $(OPTIONS)

fonctions.o : fonctions.c fonctions.h
	$(CC) -c -O3 fonctions.c $(OPTIONS)

main.o : main.c fonctions.o
	$(CC) -c main.c $(OPTIONS)

	
		
all : main


clean :
	rm *.o -fv *~

cleanall : clean
	rm main -f

