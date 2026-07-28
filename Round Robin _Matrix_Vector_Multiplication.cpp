#include <omp.h>
#include <stdio.h>

int main() {
	int nrows = 10;  // More rows than threads
	int ncols = 3;
	int matrix[10][3] = { {1, 0, 1}, {0, 1, 0}, {1, 1, 0}, {0, 0, 1},
						 {1, 1, 1}, {0, 1, 1}, {1, 0, 0}, {1, 1, 0},
						 {0, 0, 1}, {1, 0, 1} };
	int vector[3] = { 1, 2, 3 };
	int result[10] = { 0 };

	omp_set_num_threads(4);
#pragma omp parallel
	{
		int myid = omp_get_thread_num();
                 int nt = omp_get_num_threads();
		// Write your code here
		for(int i = myid; i < nrows; i+=nt){
	            for(int i = 0; i < ncols; i++)
	              result[myid] += matrix[myid][i] * vector[i];

		printf("\n Thread %d >>>>> result[%d] = %d", myid, myid, result[myid]);
            }
	}
	return 0;
}

/*
Thread 3 >>>>> result[3] = 3
 Thread 3 >>>>> result[3] = 6
 Thread 1 >>>>> result[1] = 2
 Thread 1 >>>>> result[1] = 4
 Thread 1 >>>>> result[1] = 6
 Thread 0 >>>>> result[0] = 4
 Thread 0 >>>>> result[0] = 8
 Thread 0 >>>>> result[0] = 12
 Thread 2 >>>>> result[2] = 3
 Thread 2 >>>>> result[2] = 6*/
