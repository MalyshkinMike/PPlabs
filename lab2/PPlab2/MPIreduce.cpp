
#include "MPI_custom.h"

int MPIreduce(int argc, char* argv[])
{
	int N = 1600000;
	double* x = (double*)malloc(sizeof(double) * N); 
	double TotalSum, ProcSum = 0.0;
	int ProcRank, ProcNum;
	MPI_Status Status;

	double st_time, end_time;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &ProcNum);
	MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);
	if (ProcRank == 0)
	{
		
		for (int i = 0; i < N; ++i)
		{
			x[i] = i;
		}

	}
	

	st_time = MPI_Wtime();

	int k = N / ProcNum;
	double* buf = (double*)malloc(sizeof(double) * k);

	MPI_Scatter(x, k, MPI_DOUBLE, buf, k, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	
	for (int i = 0; i < k; i++)
		ProcSum = ProcSum + buf[i];

	MPI_Reduce(&ProcSum, &TotalSum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

	MPI_Barrier(MPI_COMM_WORLD);

	end_time = MPI_Wtime();
	end_time = end_time - st_time;

	if (ProcRank == 0)
	{
		printf("\nTotal Sum = %f", TotalSum);
		printf("\nTIME OF WORK IS %f ", end_time);
	}
	free(x);
	MPI_Finalize();
	return 0;
}
