#include <stdio.h> //print the output
#include <omp.h> 

int main()
{
        omp_set_num_threads(8);
        
        int x[8] = {0};
	#pragma omp parallel 
	{
	    int nt = omp_get_num_threads();
	    int myid = omp_get_thread_num();
	    
	    //printf("Thread %d ---> initial x = %d\n", myid, x); //reace condition
	    for(int i=0; i<1000000; i++)
	        x[myid]++;
	    printf("Thread %d ---> initial x = %d\n", myid, x[myid]);
	    
	    //printf("Hello DCS --- from %d of %d\n", myid, nt);  //%d-placeholder   c-value
	}
	
	//printf("Final x = %d\n", x);
	return 0;
	
    
}
