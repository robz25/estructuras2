#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	int rank, root_process, ierr, size, counter;
	MPI_Status status;
	int buffer;

	ierr = MPI_Init(&argc, &argv);
	printf("Este ierr es el numero %d y da:  %d\n", counter,ierr);
	counter++;
	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	printf("Este ierr es el numero %d y da:  %d\n", counter,ierr);
	counter++;
	ierr = MPI_Comm_size(MPI_COMM_WORLD, &size);
	printf("Este ierr es el numero %d y da:  %d\n", counter,ierr);
	counter++;
	if (rank != 0){

		ierr = MPI_Recv(&buffer, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		//printf("Hello, World. I am %d of %d\n", rank, size);
	printf("Este ierr es el numero %d y da:  %d\n", counter,ierr);
	counter++;
	} else {
    		buffer = -1;
	}
	
	ierr = MPI_Send(&buffer, 1, MPI_INT, (rank + 1) % size, 0, MPI_COMM_WORLD);
	printf("Hello, World. I am %d of %d\n", rank + 1, size);
	printf("Este ierr es el numero %d y da:  %d\n", counter,ierr);
	counter++;
	if (rank == 0) {
    		ierr = MPI_Recv(&buffer, 1, MPI_INT, size - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
   		//printf("Hello, World. I am %d of %d\n", size, size);
	printf("Este ierr es el numero %d y da:  %d\n", counter,ierr);
	counter++;
	}	


	ierr = MPI_Finalize();
	printf("Este ierr es el numero %d y da:  %d\n", counter,ierr);
	counter++;
	return 0;
}
