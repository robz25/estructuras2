#include "mpi.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n;

int main(int argc, char *argv[]){

	int rank, papaya, size;
	MPI_Status status;

	papaya = MPI_Init(&argc, &argv);

	papaya = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	papaya = MPI_Comm_size(MPI_COMM_WORLD, &size);

	int total, local, base, excedente, numeros[size], total0;

	srand(time(NULL));
	n = rand()%100 + 1;
	int randoms[n];
	base = (int)floor(n/size);
	excedente = n%size;
	for(int i = 0; i < n; i++) { // Llena de numeros random
		numeros[i] = base;
	}
	
	for(int i = 0; i < excedente; i++) { // Llena de numeros random
		numeros[i] += 1;
	}
	for(int i = 0; i < size; i++) { //imprime arreglo
		printf("%d, ", numeros[i]);
	}

	for(int i = 0; i < n; i++) { // Llena de numeros random
		randoms[i] = rand() % 100 + 1;
	}
	
	for (int z = 0; z < numeros[rank]; z++){
		local = local + randoms[z];
		printf("\nlocal: %d", local);
	}
//	local = local/numeros[rank];

	MPI_Scatter(&local, numeros[rank], MPI_INT, &total, numeros[rank], MPI_INT, 0, MPI_COMM_WORLD);

	if (rank == 0) {	
		total0 += total;
		printf("\n Total0: %d", total0);
		printf("\nEl total es: %d \n", total);
		printf("La cantidad de entradas es: %d \n", n);
		for(int i = 0; i < n; i++) { //imprime arreglo
			printf("%d, ", randoms[i]);
		}
		printf("\nEl promedio es: %.2lf\n", (float)total / n);

	}
}
