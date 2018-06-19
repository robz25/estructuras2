all: all8 all2 primosSec

all8: compilar
	mpiexec -np 8 ./NumerosPrimos > test8.txt
	mpiexec -np 8 ./Matrix > matrix8.txt

all2: compilar
	mpiexec -np 2 ./NumerosPrimos > test2.txt
	mpiexec -np 2 ./Matrix > matrix2.txt

compilar:
	mpicc NumerosPrimos.c -o NumerosPrimos -lm
	mpicc Matrix.c -o Matrix -lm	

primosSec:
	mpicc NumerosPrimos.c -o NumerosPrimos -lm
	mpiexec -np 1 ./NumerosPrimos > primosSec.txt

primos2:
	mpicc NumerosPrimos.c -o NumerosPrimos -lm
	mpiexec -np 2 ./NumerosPrimos > primos2.txt

primos8:
	mpicc NumerosPrimos.c -o NumerosPrimos -lm
	mpiexec -np 8 ./NumerosPrimos > primos8.txt

matrix2:
	mpicc Matrix.c -o Matrix -lm
	mpiexec -np 2 ./Matrix > matrix2.txt

matrix8:
	mpicc Matrix.c -o Matrix -lm
	mpiexec -np 8 ./Matrix > matrix8.txt