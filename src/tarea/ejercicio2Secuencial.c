#include <stdio.h>
#include <time.h>

int completado[10], costo, res, rank, size;
double tiempo;
clock_t inicio, final;
int ciudades = 8;
int distancias[8][8] = {
{0 , 115, 8 , 17 , 167, 26 ,83, 75},
{115, 0, 120, 129, 272, 92, 197, 100},
{8, 120, 0, 9, 160, 34, 78, 83},
{17, 129, 9, 0, 151, 43, 69, 91},
{167, 272, 160, 151, 0, 193, 98, 236},
{26, 92, 34, 43, 193, 0, 108, 55 },
{83, 197, 78, 69, 98, 108, 0, 141},
{75, 100, 83, 91, 236, 55, 141, 0}
};



int least(int c)
{
    int i,nc=999;
    int min=999,kmin;
 
    for(i=0;i < ciudades;i++)
    {
        if((distancias[c][i]!=0)&&(completado[i]==0))
            if(distancias[c][i]+distancias[i][c] < min)
            {
                min=distancias[i][0]+distancias[c][i];
                kmin=distancias[c][i];
                nc=i;
            }
    }
 
    if(min!=999)
        costo+=kmin;
 
    return nc;
}

void mincosto(int city)
{
    int i,ncity;
 
    completado[city]=1;
 
    printf("%d--->",city+1);
    ncity=least(city);
 
    if(ncity==999)
    {
        ncity=0;
        printf("%d",ncity+1);
        costo+=distancias[city][ncity];
 
        return;
    }
 
    mincosto(ncity);
}

 
int main(int argc, char** argv)
{

	inicio = clock();
	printf("Inicio: %ld\n", inicio);
	printf("\n\nEl recorrido es:\n");
	mincosto(0);
	printf("\n\nLa distancia minima total es: %d\n ",costo);

	final = clock();
	tiempo = (double)((final - inicio)/CLOCKS_PER_SEC);
	printf("Tiempo de ejecución secuencial: %f\n", tiempo);

    return 0;
}
