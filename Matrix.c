#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"

#define filas_A 3
#define columnas_A 5
#define columnas_B 4

int printMatrixC(double matrix[filas_A][columnas_B]) {

	for (int i = 0; i < filas_A; i++) {// Imprime MatrixC
        	printf("\n"); 
         	for (int j = 0; j < columnas_B; j++) 
            		printf("%6.2f   ", matrix[i][j]);
      	}

}

int main (int argc, char *argv[]) {

	int rank, size, ierr;

	MPI_Status status;

	ierr = MPI_Init(&argc,&argv);
	ierr = MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	ierr = MPI_Comm_size(MPI_COMM_WORLD,&size);

	double MatrixA[filas_A][columnas_A];
	double MatrixB[columnas_A][columnas_B];
	double MatrixC[filas_A][columnas_B];

	int offset, filas;
	
	if (rank == 0) {// Proceso Principal

		for (int i = 0; i < filas_A; i++)
        	 	for (int j = 0; j < columnas_A; j++)
            			MatrixA[i][j]= i + j;
      		for (int i = 0; i < columnas_A; i++)
         		for (int j = 0; j < columnas_A; j++)
            			MatrixB[i][j]= i + j;	

		printMatrixC(MatrixC);

	}

	if (rank > 0) {// Procesos esclavos

		MPI_Recv(&offset, 1, MPI_INT, 123, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(&filas, 1, MPI_INT, 321, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(&MatrixA, filas * columnas_A, MPI_DOUBLE, 456, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(&MatrixB, columnas_A * columnas_B, MPI_DOUBLE, 654, 0, MPI_COMM_WORLD, &status);

		

	}

	MPI_Finalize();
	return 0;

}