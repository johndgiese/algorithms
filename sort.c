#include <stdio.h>
#include "vector.h"

void insertionSort(Vector* vec) {
    int i;
    for (i = 1; i < vec->length; i++) {
        int key = vec->value[i];

        // Find where in the sorted portion the key needs to go
        int j;
        for (j = 0; j < i; j++) {
            if (vec->value[j] > key) {
                break;
            }
        } 

        // Shift values over to make room
        int k;
        for (k = i; k > j; k--) {
            vec->value[k] = vec->value[k-1];
        }
        vec->value[j] = key;
    }
}

int main(int argc, const char *argv[]) {

    Vector a;
    a.length = 6;
    int aa[6] = {11, 2, 5, 23, 10, 4};
    a.value = aa;

    Vector b;
    b.length = 6;
    int bb[6] = {2, 4, 5, 10, 11, 23};
    b.value = bb;

    printf("initial vector a:\n");
    printVector(&a);
    printf("after sorting:\n");
    insertionSort(&a);
    printVector(&a);

    bool equal;
    equal = areEqualVectors(&a, &b);
    printf("%s\n", equal ? "equal" : "not equal");
    
    return 0;
}
