

#include <stdio.h>
#include <omp.h>

void doBigJob(int id) {
    long long dummy, workload = (id + 1) * 100000000LL; 
    for (long long i = 0; i < workload; i++)
        dummy = i * i; 
}

int main() {
    #pragma omp parallel num_threads(4)
    {
        int id = omp_get_thread_num();

        doBigJob(id);

        printf("First job done by %d\n", id);

        #pragma omp barrier
        doBigJob(id);

        printf("Second job done by %d\n", id);
    }

    return 0;
}
