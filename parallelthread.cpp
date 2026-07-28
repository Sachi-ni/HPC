#include <stdio.h> //print the output
#include <omp.h> 

int main()
{
        omp_set_num_threads(8);
        
        int ax[8] = {0,1,2,3,4,5,6,7};
        
	#pragma omp parallel 
	{
	    int nt = omp_get_num_threads();
	    int myid = omp_get_thread_num();
	  
	    ax[myid] += 10;
	    printf("ax[ %d ] = %d\n", myid, ax[myid]);
	}
        return 0;
}
