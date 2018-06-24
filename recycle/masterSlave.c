#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv)
{
//hello 2
	int rank, root_process, ierr, size;
	MPI_Status status;
	ierr = MPI_Init(&argc, &argv);
	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	ierr = MPI_Comm_size(MPI_COMM_WORLD, &size);

	int num_procs = size;	
	int array1[8] = {1,2,3,4,5,6,7,8};
	int array2[8];
	int start_row;
	int num_rows_per_process = 1;
	int num_rows_to_send;

	if(rank% 2 == 0)
	{
		printf("Hello! My ID is an even number. I am %d of %d", rank,size);
	}
	else{
		printf("Hello! My ID is an odd number. I am %d of %d", rank,size);
	}

//Master-Slave
	for(int an_id = 1; an_id < num_procs; an_id++)
	{
		num_rows_to_send = start_row;
		start_row = an_id*num_rows_per_process;
		num_rows_to_send = start_row-num_rows_to_send;
		ierr = MPI_Send(&num_rows_to_send, 1, MPI_INT, an_id, an_id, MPI_COMM_WORLD);
		ierr = MPI_Send(&array1[start_row], num_rows_per_process, MPI_FLOAT, an_id, an_id, MPI_COMM_WORLD);
	}

	for(int an_id = 1; an_id < num_procs; an_id++)
	{
		ierr = MPI_Recv(&array2, num_rows_to_send, MPI_FLOAT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
		printf("Array2: ");
		printf("%d", array2[an_id-1]);
		printf("\n");
	}


	ierr = MPI_Finalize();
	return 0;

}

