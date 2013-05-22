#include <stdio.h>
#include "vector.h"

void printVector(Vector* vec) {
    int i;
    printf("[");
    for (i = 0; i < vec->length - 1; i++) {
        printf("%3d,", vec->value[i]);
    }
    if (vec->length > 0) {
        printf("%3d", vec->value[i]);
    }
    printf("]\n");
    return;
}

bool areEqualVectors(Vector *a, Vector *b) {
    if (a->length == b->length) {
        int i;
        for (i = 0; i < a->length; i++) {
            if (a->value[i] != b->value[i]) {
                return false;
            }
        }
        return true;
    }
    else {
        return false;
    }
}

#if TESTING
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

    printVector(&a);
    printVector(&b);
    printVector(&c);

    bool areEqual;
    areEqual = areEqualVectors(&a, &b);
    printf("A and B are %sequal.\n", areEqual ? "" : "not ");

    areEqual = areEqualVectors(&a, &c);
    printf("A and C are %sequal.\n", areEqual ? "" : "not ");

    areEqual = areEqualVectors(&c, &c);
    printf("C and C are %sequal.\n", areEqual ? "" : "not ");
    return 0;
}
#endif /* testing */
