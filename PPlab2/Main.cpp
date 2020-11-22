#include "MPI_custom.h"
#include "OMP_custom.h"


int main(int argc, char* argv[])
{
	return MPIreduce(argc, argv);
}