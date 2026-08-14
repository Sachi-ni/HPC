 #include <stdio.h>
    #include <omp.h>  

    int main() {
        int i;
        #pragma omp parallel for 
        for (i = 0; i < 20; i++) {
            printf("Thread %d working on iteration %d\n", omp_get_thread_num(), i);
        }

        return 0;
    }

//Thread 12 working on iteration 12
Thread 7 working on iteration 7
Thread 0 working on iteration 0
Thread 17 working on iteration 17
Thread 3 working on iteration 3
Thread 2 working on iteration 2
Thread 4 working on iteration 4
Thread 1 working on iteration 1
Thread 6 working on iteration 6
Thread 5 working on iteration 5
Thread 10 working on iteration 10
Thread 14 working on iteration 14
Thread 9 working on iteration 9
Thread 11 working on iteration 11
Thread 18 working on iteration 18
Thread 16 working on iteration 16
Thread 13 working on iteration 13
Thread 8 working on iteration 8
Thread 19 working on iteration 19
Thread 15 working on iteration 15
//
