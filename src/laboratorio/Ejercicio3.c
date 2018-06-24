#include <mpi.h>
#include <stdio.h>

#define LIMIT 5

int main(int argc, char** argv)
{
	int rank, root_process, ierr, size;
	MPI_Status status;
	int buffer = 871;

	ierr = MPI_Init(&argc, &argv);

	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	ierr = MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (rank == 0){
		ierr = MPI_Send(&buffer, 1, MPI_INT, 1, 123, MPI_COMM_WORLD);
		printf("Sending %d to %d\n", buffer, rank);
		ierr = MPI_Recv(&buffer, 1, MPI_INT, 3, 123, MPI_COMM_WORLD, &status);
		printf("Recieved %d from %d\n", buffer, size - 1);

	} 

	if (rank == 1){
		ierr = MPI_Recv(&buffer, 1, MPI_INT, 0, 123, MPI_COMM_WORLD, &status);
		printf("Recieved %d from %d\n", buffer, rank - 1);
		ierr = MPI_Send(&buffer, 1, MPI_INT, 2, 123, MPI_COMM_WORLD);
		printf("Sending %d to %d\n", buffer, rank);

	} 	

	if (rank == 2){
		ierr = MPI_Recv(&buffer, 1, MPI_INT, 1, 123, MPI_COMM_WORLD, &status);
		printf("Recieved %d from %d\n", buffer, rank - 1);
		ierr = MPI_Send(&buffer, 1, MPI_INT, 3, 123, MPI_COMM_WORLD);
		printf("Sending %d to %d\n", buffer, rank);

	}

	if (rank == 3){ 
		ierr = MPI_Recv(&buffer, 1, MPI_INT, 2, 123, MPI_COMM_WORLD, &status);
		printf("Recieved %d from %d\n", buffer, rank - 1);
		ierr = MPI_Send(&buffer, 1, MPI_INT, 0, 123, MPI_COMM_WORLD);
		printf("Sending %d to %d\n", buffer, rank);

	}

	ierr = MPI_Finalize();
	return 0;
}