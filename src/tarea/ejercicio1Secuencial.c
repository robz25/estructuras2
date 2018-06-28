#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define filas_A 62
#define columnas_A 15
#define columnas_B 7

int printMatrixC(double matrix[filas_A][columnas_B]) {

	for (int i = 0; i < filas_A; i++) {// Imprime MatrixC
        	printf("\n"); 
         	for (int j = 0; j < columnas_B; j++) 
            		printf("%6.2f   ", matrix[i][j]);
      	}

}

int main (int argc, char *argv[]) {

	double MatrixA[filas_A][columnas_A];
	double MatrixB[columnas_A][columnas_B];
	double MatrixC[filas_A][columnas_B];

	int offset, filas, aux;

	// Llena la matriz de numeros
	for (int i = 0; i < filas_A; i++)
        	 for (int j = 0; j < columnas_A; j++)
            		MatrixA[i][j]= i + j;

      	for (int r = 0; r < columnas_A; r++)
         	for (int q = 0; q < columnas_B; q++)
            		MatrixB[r][q]= r + q;	
	
	for (int x = 0; x < filas_A; x++) {
		for (int z = 0; z < columnas_B; z++) {

			double temp = 0.0;

			for (int w = 0; w < columnas_A; w++) { 

				temp += MatrixA[x][w] * MatrixB[z][w];

			}
			MatrixC[x][z] = temp;
		}

	}
		printMatrixC(MatrixC);

	return 0;

}