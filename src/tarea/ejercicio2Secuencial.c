#include <stdio.h>
#include <time.h>

const int ciudades = 8;
int visitado[8], costo, res, rank, size, recorrido = 0;
double tiempo;
clock_t inicio, final;
/*
int distancias[8][8] = {
{0,115,8,17,167,26,83,75},
{115,0,120,129,272,92,197,100},
{8,120,0,9,160,34,78,83},
{17,129,9,0,151,43,69,91},
{167,272,160,151,0,193,98,236},
{26,92,34,43,193,0,108,55},
{8|3,197,78,69,98,108,0,141},
{75,100,83,91,236,55,141,0}
};*/
int distancias[8][8] = {
{0,	115,	8,	17,	167,	26,	83,	75},
{115,	0,	120,	129,	272,	92,	197,	100},
{8,	120,	0,	9,	160,	34,	78,	83},
{17,	129,	9,	0,	151,	43,	69,	91},
{167,	272,	160,	151,	0,	193,	98,	236},
{26,	92,	34,	43,	193,	0,	108,	55},
{83,	197,	78,	69,	98,	108,	0,	141},
{75,	100,	83,	91,	236,	55,	141,	0}
};
/*
int distancias[8][8] = {
{0,115,8,17,167,26,83,75},
{115,0,120,129,272,92,197,100},
{8,120,0,9,160,34,78,83},
{17,129,9,0,151,43,69,91},
{167,272,160,151,0,193,98,236},
{26,92,34,43,193,0,108,55},
{83,197,78,69,98,108,0,141},
{75,100,83,91,236,55,141,0}
};
*/
int recorrerFila(int fila){
	int min = 1000;
	int ciudadSiguiente;
	for(int c = 0; c < ciudades; c++){
		if(visitado[c] == 0 && distancias[fila][c] != 0){
			if(distancias[fila][c] < min){
				min = distancias[fila][c];
				ciudadSiguiente = c;
			}
		}
	}
	visitado[fila] = 1;
//	printf("Visitado: %d \n", visitado[fila]);
//	printf("La ciudad siguiente es: %d \n", ciudadSiguiente);
	if(min != 1000){
		recorrido += min;
//		printf("Recorrido: %d", min);
	}
	return ciudadSiguiente;
}

int main(int argc, char** argv)
{
	 int min = 1000, ciudadSiguiente = 0, ciudadInicial = 0, cont = 0, ciudad = 0, recorridoGlobal=1000;

for(int filas = 0; filas < 8; filas++){
	ciudadInicial = filas;
	printf("\n\n\nEmpezando por la fila: %d\n ", filas);
	ciudadSiguiente = ciudadInicial;
	while(cont < 8){
		printf("%d--->", ciudadSiguiente+1);
		ciudad = recorrerFila(ciudadSiguiente);
		ciudadSiguiente = ciudad;
		cont++;
	}
	cont = 0;
	recorrido += distancias[ciudadSiguiente][ciudadInicial];
	printf("%d", ciudadInicial+1);
	printf("\n\nLa distancia minima total es: %d\n ", recorrido);
	if(recorridoGlobal > recorrido){
		recorridoGlobal = recorrido;
	}
	for(int c = 0; c < ciudades; c++){
		visitado[c] = 0;
	}
	recorrido = 0;
	ciudad = 0;
}
printf("La distancia final más corta fue: %d", recorridoGlobal);
return 0;
}
