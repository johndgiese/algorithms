#include <stdio.h>
#include "vector.h"

int main(int argc, const char *argv[]) {
    Vector a;
    a.length = 6;
    int aa[6] = {1, 2, 5, 23, 10, 4};
    a.value = aa;

    Vector b;
    b.length = 2;
    int bb[2] = {3, 5};
    b.value = bb;

    Vector c;
    c.length = 6;
    int cc[6] = {1, 2, 5, 24, 10, 4};
    c.value = cc;

    print_vector(&a);
    print_vector(&b);
    print_vector(&c);

    bool are_equal;
    are_equal = are_equal_vectors(&a, &b);
    printf("A and B are %sequal.\n", are_equal ? "" : "not ");

    are_equal = are_equal_vectors(&a, &c);
    printf("A and C are %sequal.\n", are_equal ? "" : "not ");

    are_equal = are_equal_vectors(&c, &c);
    printf("C and C are %sequal.\n", are_equal ? "" : "not ");

    Vector* d = ones_vector(4);
    print_vector(d);
    free_vector(d);

    Vector* e = zeros_vector(1);
    print_vector(e);
    free_vector(e);

    Vector* f = zeros_vector(2);
    print_vector(f);
    free_vector(f);

    Vector* g = copy_vector(&a);
    print_vector(g);
    free_vector(g);

    Vector* h = linear_vector(4, 10, 2);
    print_vector(h);
    free_vector(h);

    return 0;
}
