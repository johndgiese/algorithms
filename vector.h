#include "util.h"

typedef struct 
{
    int length;
    int* value;
} Vector;

void printVector(Vector* vec);
bool areEqualVectors(Vector *a, Vector *b);

