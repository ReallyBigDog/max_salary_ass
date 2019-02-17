#ifndef MAX_SALARY_H
#define MAX_SALARY_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SWAP(a,b) {int temp; temp=a; a=b; b=temp;}

void print_array(int *arr, int size);
long long max_salary_naive(int *arr, int size, int n, long long max_sal);
long long concat(int *arr, int size);
int is_better(int best_so_far, int current);
long long max_salary_greedy(int *arr, int size);

#endif
