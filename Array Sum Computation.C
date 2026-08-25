#include <omp.h>
#include <stdio.h>

#define N 10


int main() {
    int A[N] = {1,2,3,4,5,6,7,8,9,10};
    int s=0;
    
    #pragma omp parallel
    {
          #pragma omp for reduction(+:s)
          for(int i=0; i<N; i++)
                s+=A[i];
              
         
    }
    printf("Sum =%d\n",s);

    return 0;
}
