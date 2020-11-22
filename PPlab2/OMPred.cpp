

#include "OMP_custom.h"


int OMPred(int argc, char* argv[]) {
	int threadnum = 1;
	omp_set_num_threads(threadnum);
	int i;
	double * a = (double*) malloc(sizeof(double)*NMAX);
	double sum;
	for (i = 0; i < NMAX; ++i)
		a[i] = i;
	double st_time, end_time;
	st_time = omp_get_wtime();
	sum = 0;
#pragma omp parallel reduction(+, sum)
	{
		#pragma omp for shared(a) private(i)

		for (i = 0; i < NMAX; i++) {
			sum = sum + a[i];
		}
	}
	end_time = omp_get_wtime();
	end_time = end_time - st_time;
	printf("\nTotal Sum = %10.2f", sum);
	printf("\nTIME OF WORK IS %f ", end_time);
	free(a);
	return 0;
}
