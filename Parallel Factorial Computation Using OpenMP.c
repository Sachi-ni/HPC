#include <omp.h>
#include <stdio.h>

#define N 8

// Function to compute factorial
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int workload[N] = { 100000, 10000, 20000, 800000, 1000, 400000, 5000, 25000 }; // Example workload sizes
    
    #pragma omp parallel num_threads(N)
    {
        double local_start, local_end;

        #pragma omp for nowait
        for (int i = 0; i < N; i++) {

            local_start = omp_get_wtime();
            unsigned long long result = factorial(workload[i]);
            local_end = omp_get_wtime();

            printf("Thread %d finished factorial(%d) in %f seconds\n",
                omp_get_thread_num(), workload[i], local_end - local_start);
        }

        printf("Thread %d exits loop in %f seconds\n", omp_get_thread_num(), omp_get_wtime() - local_start);
    }

    return 0;
}
