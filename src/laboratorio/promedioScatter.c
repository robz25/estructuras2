#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>
#include <assert.h>
#include <math.h>
float promediar(float *array, int elementos, int rank) {
  float sum = 0.f;
  int i;
  for (i = 0; i < elementos; i++) {
    sum += array[i];
  }

//	printf("\nRank: %d\n", rank);
//	printf("\nSuma: %f\n", sum);
//	printf("\nElementosa: %d\n", elementos);
  return sum / elementos;
}

float *crearRandoms(int elementos) {
  float *randoms = (float *)malloc(sizeof(float) * elementos);
  assert(randoms != NULL);
  int i;
  for (i = 0; i < elementos; i++) {
    randoms[i] = floor(rand()%100 +1);
  }
	printf("Arreglo original: \n");
	for (i = 0; i < elementos; i++) {
   	printf("%.0f, ", randoms[i]);
  }
	printf("\nCantidad de elementos: %d\n", elementos);
  return randoms;
}


int main(int argc, char** argv) {
 int nProc;

  srand(time(NULL));

  MPI_Init(NULL, NULL);

  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  int size;
  MPI_Comm_size(MPI_COMM_WORLD, &size);

    float *randoms = NULL;
    nProc = (int)(rand()%100 + 1);

  if (rank == 0) {
//    nProc = (int)(rand()%100 + 1);
    randoms = crearRandoms(nProc * size);
  }

  float *subRandoms = (float *)malloc(sizeof(float) * nProc);
  assert(subRandoms != NULL);

  MPI_Scatter(randoms, nProc, MPI_FLOAT, subRandoms, nProc, MPI_FLOAT, 0, MPI_COMM_WORLD);

  float promProc = promediar(subRandoms, nProc, rank);

  float *subPromedio = NULL;
  if (rank == 0) {
    subPromedio = (float *)malloc(sizeof(float) * size);
    assert(subPromedio != NULL);
  }

  MPI_Gather(&promProc, 1, MPI_FLOAT, subPromedio, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);

  if (rank == 0) {
    float prom = promediar(subPromedio, size, rank);
	 printf("Cantidad de procesos: %d\n",size);
	 printf("Elementos por proceso: %d\n", nProc);
	 printf("Promedio: %f\n", prom);
    }

  if (rank == 0) {
    free(randoms);
    free(subPromedio);
  }
  free(subRandoms);

  MPI_Finalize();
}

