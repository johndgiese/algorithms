#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "vector.h"
#include "math.h"

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

Vector* emptyVector(int length) {
    Vector* vec = (Vector*)malloc(sizeof(Vector));
    vec->length = length;
    vec->value = (int*)malloc(length*sizeof(int));
    return vec;
}

Vector* newVector(int length, int initialValue) {
    Vector* vec = emptyVector(length);
    int i;
    for (i = 0; i < length; i++) {
        vec->value[i] = initialValue;
    }
    return vec;
}

void freeVector(Vector* vec) {
    free(vec->value);
    free(vec);
    return;
}

Vector* onesVector(int length) {
    return newVector(length, 1);
}

Vector* zerosVector(int length) {
    return newVector(length, 0);
}

Vector* randVector(int length, int low, int high) {
    Vector* vec = emptyVector(length);
    srand(time(NULL));
    int i;
    for (i = 0; i < length; i++) {
        vec->value[i] = low + rand() % (high - low + 1);
    }
    return vec;
}

Vector* copyVector(Vector* old) {
    Vector* new = emptyVector(old->length);
    int i;
    for (i = 0; i < old->length; i++) {
        new->value[i] = old->value[i];
    }
    return new;
}

