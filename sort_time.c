#include "vector.h"
#include "sort.h"

#include <time.h>
#include <stdio.h>

int main(int argc, const char *argv[])
{
    Vector *n_vec = linear_vector(10000, 100000, 10000);
    int n;
    Vector *v;
    clock_t start, diff;
    int diff_msec;

    int i;
    printf("n, time in msec\n");
    for (i = 0; i < n_vec->length; i++) {
        n = n_vec->value[i];
        v = rand_vector(n, 1, 100);

        start = clock();

        merge_sort(v);

        diff = clock() - start;
        diff_msec = diff*1000/CLOCKS_PER_SEC;

        printf("%d, %d\n", diff_msec, n);
        free_vector(v);
    }
    free_vector(n_vec);

    return 0;
}
