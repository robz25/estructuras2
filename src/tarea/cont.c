#include <mpi.h>
#include <stdio.h>

#define LIMIT 8

int main(int argc, char** argv)
{
	int rank, i, ierr, size;
	MPI_Status status;

	i = 0;

	ierr = MPI_Init(&argc, &argv);

	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	ierr = MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	while (i < LIMIT){

		if (rank != 0){
		
			//printf ("%i\n", i);
			ierr = MPI_Recv(&i, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf ("Recv %i\n", i);
			i++;
			ierr = MPI_Send(&i, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
			printf ("Send %i\n", i);

		} else {
			i = i;	
		}

		i++;
		ierr = MPI_Send(&i, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		printf ("Send %i\n", i);

		if (rank == 0) {
			ierr = MPI_Recv(&i, 1, MPI_INT, size - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf ("Recv %i\n", i);
			i++;
		
		}

		//printf ("%i\n", i - 1);	

	}	


	ierr = MPI_Finalize();
	return 0;
}