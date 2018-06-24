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
	
	if (rank == 0) {

		while (i < LIMIT - 1) {

			MPI_Send(&i, 1, MPI_INT, 1, 123, MPI_COMM_WORLD);
			printf("Sent %d from %d\n", i, rank);

			MPI_Recv(&i, 1, MPI_INT, 1, 123, MPI_COMM_WORLD, &status);
			printf("Recieved %d in %d\n", i, rank);
			i++; 	

		}

	}

	if (rank > 0) {

		while (i < LIMIT - 1) {

			MPI_Recv(&i, 1, MPI_INT, 0, 123, MPI_COMM_WORLD, &status);
			printf("Recieved %d in %d\n", i, rank);
			i++;

			MPI_Send(&i, 1, MPI_INT, 0, 123, MPI_COMM_WORLD);
			printf("Sent %d from %d\n", i, rank);	

		}

	}


	ierr = MPI_Finalize();
	return 0;
}