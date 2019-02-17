#include <stdio.h>
#include <stdlib.h>
#include "max_salary.h"

void stress_test(int max_len, int up_to){
    int i;
    srand(time(NULL));

    while (1) {
        int size = rand() % (max_len) + 1;
        int *arr = malloc(size);
        for(i = 0; i < size; i ++) {
            arr[i] = rand() % (up_to + 1);
        }

        printf("list of nums ");
        print_array(arr, size);
        int result1 = max_salary_naive(arr, size, size, 0);
        int result2 = max_salary_greedy(arr, size);

        if (result1==result2) {
          	printf("OK\n");
        }
        else {
          	printf("Wrong answer: correct=%d, got instead=%d\n", result1, result2);
            printf("Please note that if large values are used for max_len and up_to, the system will produce unreliable results due to type storage limitations\n");
    	    exit(0);
        }

        free(arr);
    }
}

int main(int argc, char **argv){
    if (argc < 2) {
        printf("To run stress_test, enter test <max_len> <max_val>\n");
        return 0;
    }
    int max_len = atoi(argv[1]);
    int up_to = atoi(argv[2]);

    stress_test(max_len, up_to);

    return 0;
}
