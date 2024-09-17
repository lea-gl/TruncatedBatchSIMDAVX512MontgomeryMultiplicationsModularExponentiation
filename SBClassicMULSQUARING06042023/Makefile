OPTIONS= -O3 -g -march=native -lgmp -lcrypto -lm 


ifdef BENCHMARK
	OPTIONS+= -DBENCHMARK
endif

ifdef SIZE
	MACROS= -DSIZE=$(SIZE)
else
	SIZE=260
	MACROS= -DSIZE=260
endif


ifdef TEST
	OPTIONS+= -DTEST
endif

OPTIONS+=$(MACROS)
CC= gcc

main : main.o fonctions.o
	$(CC) -o main main.o fonctions.o $(OPTIONS)

fonctions.o : fonctions.c fonctions.h
	./script.sh $(SIZE)
	$(CC) -c fonctions.c $(OPTIONS)

main.o : fonctions.o
	$(CC) -c main.c $(OPTIONS)

	
	
benchmarks:
	./script.sh 104
	make -B SIZE=104 FILE=1
	./main
	./script.sh 156
	make -B BENCHMARK=1 SIZE=156 FILE=1
	./main
	./script.sh 208
	make -B BENCHMARK=1 SIZE=208 FILE=1
	./main
	./script.sh 260
	make -B BENCHMARK=1 SIZE=260 FILE=1
	./main
	./script.sh 520
	make -B BENCHMARK=1 SIZE=520 FILE=1
	./main
	./script.sh 1040
	make -B BENCHMARK=1 SIZE=1040 FILE=1
	./main
	./script.sh 2080
	make -B BENCHMARK=1 SIZE=2080 FILE=1
	./main
	./script.sh 4108
	make -B BENCHMARK=1 SIZE=4108 FILE=1
	./main
	./script.sh 4160
	make -B BENCHMARK=1 SIZE=4160 FILE=1
	./main
	./script.sh 8216
	make -B BENCHMARK=1 SIZE=8216 FILE=1
	./main
	./script.sh 8320
	make -B BENCHMARK=1 SIZE=8320 FILE=1
	./main
	
benchmark:
	./script.sh $(SIZE)
	make -B BENCHMARK=1
	./main

	
tests:
	make -B TEST=1 SIZE=104 FILE=1
	./main
	make -B TEST=1 SIZE=156 FILE=1
	./main
	make -B TEST=1 SIZE=208 FILE=1
	./main
	make -B TEST=1 SIZE=260 FILE=1
	./main
	make -B TEST=1 SIZE=520 FILE=1
	./main
	make -B TEST=1 SIZE=1040 FILE=1
	./main
	make -B TEST=1 SIZE=2080 FILE=1
	./main
	make -B TEST=1 SIZE=4108 FILE=1
	./main
	make -B TEST=1 SIZE=1040 FILE=1
	./main
	make -B TEST=1 SIZE=8216 FILE=1
	./main
	make -B TEST=1 SIZE=8320 FILE=1
	./main

	
test:
	make -B TEST=1
	./main

		
all : main


clean :
	rm *.o -fv *~

cleanall : clean
	rm main -f

