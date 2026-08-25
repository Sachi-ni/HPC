#include <omp.h>
#include <stdio.h>

#define N 10


int main() {
    int A[N] = {1,2,3,4,5,6,7,8,9,10};
    int mx=0;
    
    #pragma omp parallel
   {
          #pragma omp for reduction(max:mx)
          for(int i=0; i<N; i++)
              if(mx<A[i])
                  mx=A[i];
              
         
    }
    printf("Max =%d\n",mx);

    return 0;
}
