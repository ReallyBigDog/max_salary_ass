#include "max_salary.h"

int is_better(int best_so_far, int current){
    int bc[] = {best_so_far, current};
    int cb[] = {current, best_so_far};
    return concat(bc, 2) < concat(cb, 2);
}

long long max_salary_greedy(int *arr, int size){
    int best_arr[size];
    long long best;
    int new_size = size;

    for (int i = 0; i < size; i++) {
        best = 0;
        for (int j = 1; j < new_size; j++) {
            if (is_better(arr[best], arr[j])) {
                best = j;
            }
        }

        best_arr[i] = arr[best];
        SWAP(arr[best], arr[new_size - 1]);
        new_size--;
    }

    return concat(best_arr, size);
}
