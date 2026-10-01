#include <mpi.h>
#include <stdio.h>
 
int main(int argc, char *argv[]) {
    int rank, size;
    int value, left, right;
    int from_left, from_right, sum;
 
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
 
    /* 1. Starting value is the process rank */
    value = rank;
 
    /* 2. Identify neighbours (wrap around to form a ring) */
    left  = (rank - 1 + size) % size;
    right = (rank + 1) % size;
 
    /* 3. Exchange values with both neighbours.
       MPI_Sendrecv does the send and receive together, so it cannot deadlock. */
 
    /* Send my value to the right neighbour, receive the left neighbour's value */
    MPI_Sendrecv(&value,     1, MPI_INT, right, 0,
                 &from_left, 1, MPI_INT, left,  0,
                 MPI_COMM_WORLD, MPI_STATUS_IGNORE);
 
    /* Send my value to the left neighbour, receive the right neighbour's value */
    MPI_Sendrecv(&value,      1, MPI_INT, left,  1,
                 &from_right, 1, MPI_INT, right, 1,
                 MPI_COMM_WORLD, MPI_STATUS_IGNORE);
 
    /* 4. Sum own value and the two received values */
    sum = value + from_left + from_right;
 
    /* 5. Display results */
    printf("Rank %d: received %d from left (rank %d), %d from right (rank %d), sum = %d\n",
           rank, from_left, left, from_right, right, sum);
 
    MPI_Finalize();
    return 0;
}
 
