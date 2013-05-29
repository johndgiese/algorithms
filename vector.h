#include "util.h"

typedef struct 
{
    int length;
    int* value;
} Vector;

void printVector(Vector* vec);
bool areEqualVectors(Vector *a, Vector *b);
void freeVector(Vector*);
Vector* newVector(int length, int initialValue);
Vector* onesVector(int length);
Vector* zerosVector(int length);
Vector* copyVector(Vector* old);

