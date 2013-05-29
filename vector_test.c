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

    Vector* d = onesVector(4);
    printVector(d);

    Vector* e = zerosVector(1);
    printVector(e);

    Vector* f = zerosVector(2);
    printVector(f);

    Vector* g = copyVector(&a);
    printVector(g);

    freeVector(d);
    freeVector(g);
    freeVector(f);
    freeVector(e);

    return 0;
}
