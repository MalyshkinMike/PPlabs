#include <omp.h>
#define CHUNK 100
#define NMAX 1600000
#include "stdio.h"
#include <iostream>

int OMPred(int argc, char* argv[]);
int OMPatom(int argc, char* argv[]);
int OMPcrit(int argc, char* argv[]);