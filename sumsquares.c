#include <mpi.h>
#include <stdio.h>
 
int main(int argc, char *argv[]) {
    int rank, size;
    int n = 0;
    long long local_result, total_sum = 0;
 
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
 
    /* 1. Root reads n from the user */
    if (rank == 0) {
        printf("Enter an integer value n: ");
        fflush(stdout);
        scanf("%d", &n);
    }
 
    /* 2. Broadcast n to all processes */
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
 
    /* 3. Each process computes (rank * n)^2 */
    local_result = (long long)rank * n;
    local_result = local_result * local_result;
 
    printf("Process %d: (%d * %d)^2 = %lld\n", rank, rank, n, local_result);
 
    /* 4. Reduce with MPI_SUM to the root */
    MPI_Reduce(&local_result, &total_sum, 1, MPI_LONG_LONG, MPI_SUM, 0, MPI_COMM_WORLD);
 
    /* 5. Root displays the total */
    if (rank == 0) {
        printf("Total sum of squares = %lld\n", total_sum);
    }
 
    MPI_Finalize();
    return 0;
}
