#include <stdio.h>

typedef struct {
    int length;
    int* value;
} Vector;

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

int main(int argc, const char *argv[])
{
    Vector a;
    a.length = 6;
    int aa[6] = {1, 2, 5, 23, 10, 4};
    a.value = aa;

    printVector(&a);
    
    return 0;
}
