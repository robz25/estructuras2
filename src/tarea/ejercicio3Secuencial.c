#include <math.h>
#include <stdio.h>
#include <time.h>

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

	clock_t begin = clock();

	//double tiempo_inicio = MPI_Wtime();
	int numero_primo = 0;
	int aux, total, z;

	total = 0;

	for (z = 1; total < FIN; z = z + 1) {			

		if (primo(z)) {
			numero_primo = z;
			total++;
			printf("%d\n", numero_primo);
		}
	}
	
	//double tiempo_fin = MPI_Wtime();
	//double t = tiempo_fin - tiempo_inicio;
	//printf("Tiempo: %.2lf", t);

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Tiempo: %.2lf\n", time_spent);
}