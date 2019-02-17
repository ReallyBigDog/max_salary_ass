#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "max_salary.h"

int main() {
    srand(time(NULL));

    //reducing the # of tries for each value of n decreases
    //running time of test but also decreases accuracy
    int tries = 1;
    //when the test arrays contain large values
    //the test only finishes for small values of n
    int max_val = 10;

    double total_naive;
    double total_greedy;

    //setting the ceiling of n higher than around 10 means that the test will not finish
    //further, if n is small, then higher values for tries and max_val can be used
    for (int n = 1; n < 20; n++){
        for (int i = 0; i < tries; i++){
            int arr[n];
            for (int j = 0; j < n; j++) {
                arr[j] = abs(rand() % (max_val + 2) - 1);
            }

            clock_t t1 = clock();
            //comment out the next line to only see performance test for greedy
            //algorithm: the values of n and tries can then be larger
            max_salary_naive(arr, n, n, 0);
            clock_t t2 = clock();
            total_naive += (double)(t2 - t1) / CLOCKS_PER_SEC;

            clock_t t3 = clock();
            max_salary_greedy(arr, n);
            clock_t t4 = clock();
            total_greedy += (double)(t4 - t3) / CLOCKS_PER_SEC;
        }

        printf("n=%d, avg naive: %f, avg greedy: %f\n", n, total_naive / tries, total_greedy / tries);
        total_naive = 0;
        total_greedy = 0;
    }

    return 0;
}
