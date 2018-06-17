all8:
	mpicc NumerosPrimos.c -o NumerosPrimos -lm
	mpiexec -np 8 ./NumerosPrimos > test8.txt

all2:
	mpicc NumerosPrimos.c -o NumerosPrimos -lm
	mpiexec -np 2 ./NumerosPrimos > test2.txt