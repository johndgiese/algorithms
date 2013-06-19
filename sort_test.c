#include <stdio.h>
#include <string.h>

#include "vector.h"
#include "sort.h"

int main(int argc, const char *argv[]) {

    Vector a;
    a.length = 6;
    int aa[6] = {11, 2, 5, 23, 10, 4};
    a.value = aa;

    Vector b;
    b.length = 6;
    int bb[6] = {2, 4, 5, 10, 11, 23};
    b.value = bb;

    bool equal;
    equal = are_equal_vectors(&a, &b);
    printf("%s\n", equal ? "equal" : "not equal");

    Vector c = *rand_vector(10, 3, 7);

    printf("initial vector:\n");
    print_vector(&c);
    printf("after sorting:\n");
    merge_sort(&c);
    print_vector(&c);

    return 0;
}
