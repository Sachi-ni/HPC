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

	omp_set_num_threads(10);
#pragma omp parallel
	{
		int myid = omp_get_thread_num();

		// Write your code here
	        for(int i = 0; i < ncols; i++)
	              result[myid] += matrix[myid][i] * vector[i];

		printf("\n Thread %d >>>>> result[%d] = %d", myid, myid, result[myid]);

	}
	return 0;
}

