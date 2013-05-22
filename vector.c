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

#if TESTING
int main(int argc, const char *argv[])
{
    Vector a;
    a.length = 6;
    int aa[6] = {1, 2, 5, 23, 10, 4};
    a.value = aa;

    Vector b;
    b.length = 0;

    printVector(&a);
    printVector(&b);
    return 0;
}
#endif /* testing */
