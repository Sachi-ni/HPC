#include <stdio.h> //print the output
#include <omp.h> 

int main()
{
        omp_set_num_threads(8);
        
        int x = 0;
        int ax[8] = {0};
        
	#pragma omp parallel 
	{
	    int nt = omp_get_num_threads();
	    int myid = omp_get_thread_num();
	  
	    for(int i=0; i<1000000; i++)
	        ax[myid]++;
	}
	for(int j=0; j<8; j++)
	    x += ax[j];
	    
	printf("x = %d\n", x);
	return 0;
}
