OPTIONS= -g -march=native -lgmp -lcrypto -lm 


ifdef TEST
	OPTIONS+= -DTEST
endif

OPTIONS+=$(MACROS)
CC= gcc

main : main.o fonctions.o
	$(CC) -o main main.o fonctions.o $(OPTIONS)

main_rdpmc : main_rdpmc.o fonctions.o
	$(CC) -o main_rdpmc main_rdpmc.o fonctions.o $(OPTIONS)

fonctions.o : fonctions.c fonctions.h
	$(CC) -c -O3 -funroll-all-loops fonctions.c $(OPTIONS)

main.o : fonctions.o
	$(CC) -c main.c $(OPTIONS)

main_rdpmc.o : fonctions.o
	$(CC) -c main_rdpmc.c $(OPTIONS)
	
	
test:
	make -B TEST=1 SIZE=512
	./main
	make -B TEST=1 SIZE=1024
	./main
	make -B TEST=1 SIZE=2048
	./main
	make -B TEST=1 SIZE=4096
	./main
	make -B TEST=1 SIZE=8192
	./main
	make -B TEST=1 SIZE=16384
	./main
	make -B TEST=1 SIZE=32768
	./main
	
	
	
		
all : main


clean :
	rm *.o -fv *~

cleanall : clean
	rm main -f

