#include <stdio.h>
#include <omp.h>

#define NT 8

long N = 100000000;
double dx;

int main()
{
	int i;
	double pi = 0.0;
	//double sum = 0.0;
        double start_time, run_time;
	dx = 1.0 / (double)N;

	start_time = omp_get_wtime();
        
        #pragma omp parallel num_threads(NT)
        {
	 
            int myid = omp_get_thread_num();	
            double sum = 0.0;
            double x;
	    for (i = myid; i < N; i+=NT) {
		      x = (i + 0.5) * dx;
		      sum += 4.0 / (1.0 + x * x);  //this one is safe, bcz we used private variable :they have their own copy
	      }
	      
	      sum = sum*dx;
	      #pragma omp atomic
	          pi+=sum;
	       
	      //#pragma omp critical
	        //  pi += sum*dx;
        }
       
        
	run_time = omp_get_wtime() - start_time;
	printf("\n pi with %ld steps is %lf in %lf seconds\n ", N, pi, run_time);
}


//atomic is more specific and lightweight for a simple operation
//critical protects a larger block of code
