#include "mpi.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 10 // Multiplica por cantidad de procesos LIMIT = N / size

int main(int argc, char *argv[]){

	int rank, ierr, size;
	MPI_Status status;

	ierr = MPI_Init(&argc, &argv);

	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	ierr = MPI_Comm_size(MPI_COMM_WORLD, &size);

	double tiempo_inicio = MPI_Wtime();

	int randoms[LIMIT], total, local;

	total = 0;
	local = 0;

	srand(time(NULL));

	for(int i = 0; i < LIMIT; i++) { // Llena de numeros random
		randoms[i] = rand() % 10 + 1;
	}

	for (int z = 0; z < LIMIT; z++) {
		local = local + randoms[z];
	}

	MPI_Reduce(&local, &total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

	if (rank == 0) {	
		for(int i = 0; i < LIMIT; i++) { //imprime arreglo
			printf("%d, ", randoms[i]);
		}
		printf("\nEl promedio es: %.2lf\n", (float) total / (size * LIMIT));

	}
}
