#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "vector.h"
#include "math.h"

void print_vector(Vector* vec) {
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

bool are_equal_vectors(Vector *a, Vector *b) {
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

Vector* empty_vector(int length) {
    Vector* vec = (Vector*)malloc(sizeof(Vector));
    vec->length = length;
    vec->value = (int*)malloc(length*sizeof(int));
    return vec;
}

Vector* new_vector(int length, int initial_value) {
    Vector* vec = empty_vector(length);
    int i;
    for (i = 0; i < length; i++) {
        vec->value[i] = initial_value;
    }
    return vec;
}

void free_vector(Vector* vec) {
    free(vec->value);
    free(vec);
    return;
}

Vector* ones_vector(int length) {
    return new_vector(length, 1);
}

Vector* zeros_vector(int length) {
    return new_vector(length, 0);
}

Vector* linear_vector(int start, int stop_exclusive, int jump) {
    int length = (stop_exclusive - start)/jump;
    Vector* vec = empty_vector(length);

    int i;
    for (i = 0; i < length; i++) {
        vec->value[i] = start + i*jump;
    }
    return vec;
}


Vector* rand_vector(int length, int low, int high) {
    Vector* vec = empty_vector(length);
    srand(time(NULL));
    int i;
    for (i = 0; i < length; i++) {
        vec->value[i] = low + rand() % (high - low + 1);
    }
    return vec;
}

Vector* copy_vector(Vector* old) {
    Vector* new = empty_vector(old->length);
    int i;
    for (i = 0; i < old->length; i++) {
        new->value[i] = old->value[i];
    }
    return new;
}

