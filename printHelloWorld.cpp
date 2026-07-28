#include <stdio.h> //print the output
#include <omp.h> 

int main()
{
	#pragma omp parallel 
	{
	    int nt = omp_get_num_threads();
	    int myid = omp_get_thread_num();
	    printf("Hello DCS --- from %d of %d\n", myid, nt);  //%d-placeholder   c-value
	}
	return 0;
}
