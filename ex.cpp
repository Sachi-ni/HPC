#include <stdio.h>
#include <omp.h>

int main() {
    long final_sum = 0;     

    double start_time = omp_get_wtime(); 

    #pragma omp parallel num_threads(8)
    {

        for (int i = 0; i < 1000000; i++) {
            final_sum++; 
        }
    }

    double end_time = omp_get_wtime(); 

    printf("Final value of shared_variable is %ld.\n", final_sum);
    printf("Runtime: %f seconds\n", end_time - start_time);

    return 0;
}

