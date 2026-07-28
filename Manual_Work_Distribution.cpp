#include <stdio.h> //print the output
#include <omp.h> 
#define N 16

int main()
{
        omp_set_num_threads(4);
        
        int ax[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
        
	#pragma omp parallel 
	{
	    int nt = omp_get_num_threads();
	    int myid = omp_get_thread_num();
	  
	    for(int i = myid; i < N; i+=nt){
	    ax[i] += 10;
	    printf("ax[ %d ] = %d\n", i, ax[i]);}
	}
        return 0;
}

/*
ax[ 3 ] = 13
ax[ 7 ] = 17
ax[ 11 ] = 21
ax[ 15 ] = 25
ax[ 0 ] = 10
ax[ 4 ] = 14
ax[ 8 ] = 18
ax[ 12 ] = 22
ax[ 2 ] = 12
ax[ 6 ] = 16
ax[ 10 ] = 20
ax[ 14 ] = 24
ax[ 1 ] = 11
ax[ 5 ] = 15
ax[ 9 ] = 19
ax[ 13 ] = 23*/

/*
Index :  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
Value :  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15

               ↓ Parallel Execution

Thread 0 → 0,4,8,12
Thread 1 → 1,5,9,13
Thread 2 → 2,6,10,14
Thread 3 → 3,7,11,15

Each thread adds 10.

Final Array:

10 11 12 13
14 15 16 17
18 19 20 21
22 23 24 25*/
