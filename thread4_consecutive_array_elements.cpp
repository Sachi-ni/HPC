#include <stdio.h> //print the output
#include <omp.h> 

int main()
{
        omp_set_num_threads(4);
        
        int ax[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
        
	#pragma omp parallel 
	{
	    int nt = omp_get_num_threads();
	    int myid = omp_get_thread_num();
	  
	    for(int i = myid * nt; i < (myid+1) * nt; i++){
	    ax[i] += 10;
	    printf("ax[ %d ] = %d\n", i, ax[i]);}
	}
        return 0;
}
/*ax[ 12 ] = 22
ax[ 13 ] = 23
ax[ 14 ] = 24
ax[ 4 ] = 14
ax[ 5 ] = 15
ax[ 6 ] = 16
ax[ 7 ] = 17
ax[ 8 ] = 18
ax[ 9 ] = 19
ax[ 10 ] = 20
ax[ 11 ] = 21
ax[ 15 ] = 25
ax[ 0 ] = 10
ax[ 1 ] = 11
ax[ 2 ] = 12
ax[ 3 ] = 13*/
