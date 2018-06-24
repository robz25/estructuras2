#include <mpi.h>
#include <stdio.h>

#define LIMIT 21
//2 procesos
//f

int counter, message;

int main(int argc, char** argv)
{
	int rank, i, ierr, size;
	MPI_Status status;

	ierr = MPI_Init(&argc, &argv);

	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	ierr = MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0)ierr = MPI_Send(&counter,i, MPI_INT, 1, 0, MPI_COMM_WORLD);

	while (message < LIMIT){

		if(rank == 0) {
			ierr = MPI_Recv(&message, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("Soy el proceso %d y estoy recibiendo el número: %d\n", rank,message);
			printf("Voy a enviar: %d + %d = %d\n", message,1, message+1);
			message++;
			ierr = MPI_Send(&message,1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		}
		else{
			ierr = MPI_Recv(&message, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("Soy el proceso %d y estoy recibiendo el número: %d\n", rank,message);
			printf("Voy a enviar: %d + %d = %d\n", message,1, message+1);
			message++;
			ierr = MPI_Send(&message,1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		}
	}

//	ierr = MPI_Finalize();
	ierr = MPI_Abort(MPI_COMM_WORLD, 0);
	return 0;
}

//¿Qué hacer con procesos no usados?
