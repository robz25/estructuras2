#include <mpi.h>
#include <stdio.h>

#define LIMIT 5

int main(int argc, char** argv)
{
	int rank, root_process, ierr, size;
	MPI_Status status;
	int buffer;
	int i = 0;

	ierr = MPI_Init(&argc, &argv);

	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	ierr = MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	//while (i < LIMIT){

		if (rank != 0){
			ierr = MPI_Recv(&buffer, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			//printf("Hello, World. I am %d of %d\n", rank, size);

		} else {
    			buffer = 871;
		}

		ierr = MPI_Send(&buffer, 1, MPI_INT, (rank + 1) % size, 0, MPI_COMM_WORLD);		
		printf("Message sent: %i. I am %d of %d\n", buffer, rank, size);

		if (rank == 0) {
    			ierr = MPI_Recv(&buffer, 1, MPI_INT, size - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
   			//printf("Hello, World. I am %d of %d\n", size, size);
			
		//}
	}	


	ierr = MPI_Finalize();
	return 0;
}