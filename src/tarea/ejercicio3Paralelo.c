#include "mpi.h"
#include <math.h>
#include <stdio.h>

#define FIN 500000 // Cantidad limite de numeros primos a encontrar

//Funciones auxiliares

int primo(int num)
{	
	if (num % 2 == 0)
		return 0;
	for (int i = 3; i < sqrt(num); i += 2)
		if (num % i == 0)
			return 0;
	return 1;
}

int main(int argc, char *argv[]){

	int rank, ierr, size;
	MPI_Status status;

	ierr = MPI_Init(&argc, &argv);

	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	ierr = MPI_Comm_size(MPI_COMM_WORLD, &size);

	double tiempo_inicio = MPI_Wtime();
	int inicio_impar = (rank * 2) + 1;
	int step = size * 2;
	int contador = 0;
	int msg = 0;
	int numero_primo = 0;
	int aux, total, z;

	if (rank == 0) { //Proceso master

		contador = 4;
		total = 0;

		for (z = inicio_impar; total < (FIN / size); z = z + step) {			

			if (primo(z)) {
				contador = contador + 1;
				numero_primo = z;
				total++;
				printf("%d\n", numero_primo);

			}
		}

	
	}

	if (rank > 0) { //Procesos esclavos

		total = 0;

		for (z = inicio_impar; total < (FIN / size); z = z + step) {
			aux = 0;
			if (primo(z)) {
				contador = contador + 1;
				numero_primo = z;
				aux = 1;
				total++;
				printf("%d\n", numero_primo);
			}
		}

	}
	
	double tiempo_fin = MPI_Wtime();
	double t = tiempo_fin - tiempo_inicio;
	printf("Tiempo: %.2lf\n", t);
	
	MPI_Finalize();

}