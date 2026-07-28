#include <stdio.h> //print the output
#include <omp.h> 

int main()
{
        omp_set_num_threads(8);
        
        int ax[8] = {0};
        
	#pragma omp parallel 
	{
	    int nt = omp_get_num_threads();
	    int myid = omp_get_thread_num();
	  
	    ax[myid] += myid * 10;
	}
	for(int j=0; j<8; j++)
	    printf("ax[ %d ] = %d\n", j, ax[j]);
	    
	return 0;
}
