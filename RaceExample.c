#include <stdio.h>
#include <omp.h>

#define NT 8

int main() {
    long final_sum = 0;     
    long psum[NT] = {0};
    
    double start_time = omp_get_wtime(); 

    #pragma omp parallel num_threads(NT)
    {
        int myid = omp_get_thread_num();
        
        for (int i = 0; i < 1000000; i++) {
            psum[myid]++; 
        }
    }
    
    for( int j=0; j<NT; j++){
      final_sum += psum[j];
    }
    
    double end_time = omp_get_wtime(); 

    printf("Final value of shared_variable is %ld.\n", final_sum);
    printf("Runtime: %f seconds\n", end_time - start_time);

    return 0;
}
