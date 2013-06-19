#include <string.h>

#include "vector.h"
#include "sort.h"

void insertion_sort(Vector* vec) {
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

Vector* _merge_sort(Vector* vec) {
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
        Vector* aa = copy_vector(&a);
        Vector* bb = copy_vector(&b);

        // sort each half
        aa = _merge_sort(aa);
        bb = _merge_sort(bb);

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

void merge_sort(Vector* vec) {
    vec = _merge_sort(vec);
}
