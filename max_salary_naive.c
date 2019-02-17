#include "max_salary.h"

void print_array(int *arr, int size){
  for (int i=0; i<size; i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}

long long concat(int *arr, int size){
    long long catted = arr[size - 1];
    int x;

    for (int i = size - 2; i >= 0; i--){
        x = 10;
        while (x <= catted) {
            x *= 10;
        }

        catted += (long long)(arr[i] * x);
    }
    return catted;
}

long long max_salary_naive(int *arr, int size, int n, long long best_sal){
    // if size becomes 1 then do something with the obtained permutation
    if (size == 1) {
        //TO DO - instead of printing, insert your code for evaluating the next candidate array
        int new_sal = concat(arr, n);
        //printf("%d\n", new_sal);
        if (new_sal > best_sal) {
            //print_array(arr, n);
            //printf("%d\n", new_sal);
            return new_sal;
        }
        return best_sal;
    }

    for (int i=0; i<size; i++)
    {
        best_sal = max_salary_naive(arr,size-1,n, best_sal);

        // if size is odd, swap first and last element
        if (size%2 == 1) {
            SWAP(arr[0], arr[size-1]);
		}
        // If size is even, swap ith and last element
        else{
            SWAP(arr[i], arr[size-1]);
		}
    }

    //printf("best sal %d\n", best_sal);
    return best_sal;
}

// Generating permutation using Heap Algorithm

/*void heap_permutation(int a[], int size, int n)
{
    // if size becomes 1 then do something with the obtained permutation
    if (size == 1)
    {
        //TO DO - instead of printing, insert your code for evaluating the next candidate array
        print_array(a, n);
        return;
    }

    for (int i=0; i<size; i++)
    {
        heap_permutation(a,size-1,n);

        // if size is odd, swap first and last element
        if (size%2==1) {
            SWAP(a[0], a[size-1]);
		}
        // If size is even, swap ith and last element
        else{
            SWAP(a[i], a[size-1]);
		}
    }
}

// Code to test permutations
int main() {
    int a[] = {53, 535, 535, 535};
    int n = sizeof a/sizeof a[0];
    printf("%d\n", max_salary_naive(a, n, n, 0));
    return 0;
}*/
