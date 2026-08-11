#include <stdio.h>
#include <omp.h>

#define NT 8

long N = 100000000;
double dx;

int main()
{
	int i;
	double pi = 0.0;
	double start_time, run_time;

	dx = 1.0 / (double)N;

	start_time = omp_get_wtime();
        
        #pragma omp paralell num_threads(NT)
        {
            double x;
            int myid = omp_get_thread_num();
	    for (i = myid; i < N; i+=NT) {
		    x = (i + 0.5) * dx;
		    sum += 4.0 / (1.0 + x * x);
	    }
        }
      

	run_time = omp_get_wtime() - start_time;
	printf("\n pi with %ld steps is %lf in %lf seconds\n ", N, pi, run_time);
}
