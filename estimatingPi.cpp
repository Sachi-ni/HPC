#include <stdio.h>
#include <omp.h>

long N = 100000000;
double dx;

int main()
{
	int i;
	double x, pi = 0.0;
	double start_time, run_time;

	dx = 1.0 / (double)N;

	start_time = omp_get_wtime();

	for (i = 0; i < N; i++) {
		x = (i + 0.5) * dx;
		pi += 4.0 / (1.0 + x * x) * dx;
	}

	run_time = omp_get_wtime() - start_time;
	printf("\n pi with %ld steps is %lf in %lf seconds\n ", N, pi, run_time);
}
