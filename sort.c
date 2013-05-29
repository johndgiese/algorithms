#include <stdio.h>
#include "vector.h"
#include <string.h>

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

Vector* _mergeSort(Vector* vec) {
    if (vec->length <= 1) {
        return vec;
    }
    else {
        // divide into two subvectors
        int division = vec->length/2;
        Vector a;
        a.length = division;
        a.value = vec->value;
        Vector b;
        b.length = vec->length - division;
        b.value = vec->value + division;
        Vector* aa = copyVector(&a);
        Vector* bb = copyVector(&b);

        // sort each half
        aa = _mergeSort(aa);
        bb = _mergeSort(bb);

        // combine halfs (linear time)
        int i, ib = 0, ia = 0;
        int* iv;
        for (i = 0, iv = vec->value; i < vec->length; i++, iv++) {
            if (ib >= bb->length) {
                memcpy(iv, aa->value + ia, sizeof(int)*(aa->length - ia));
                break;
            }
            if (ia >= aa->length) {
                memcpy(iv, bb->value + ib, sizeof(int)*(bb->length - ib));
                break;
            }
            if (aa->value[ia] < bb->value[ib]) {
                *iv = aa->value[ia++];
            }
            else {
                *iv = bb->value[ib++];
            }
        }
        
        return vec;
    }
}

void mergeSort(Vector* vec) {
    vec = _mergeSort(vec);
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

    bool equal;
    equal = areEqualVectors(&a, &b);
    printf("%s\n", equal ? "equal" : "not equal");

    Vector c = *randVector(10, 3, 7);

    printf("initial vector:\n");
    printVector(&c);
    printf("after sorting:\n");
    mergeSort(&c);
    printVector(&c);

    return 0;
}
