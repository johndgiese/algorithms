#ifndef VECTOR_H
#define VECTOR_H

#include "util.h"

typedef struct 
{
    int length;
    int* value;
} Vector;

Vector* empty_vector(int length);
Vector* new_vector(int length, int initial_value);
Vector* ones_vector(int length);
Vector* zeros_vector(int length);
Vector* rand_vector(int length, int low, int high);
Vector* linear_vector(int start, int stop_exclusive, int jump);

void print_vector(Vector *vec);
bool are_equal_vectors(Vector *a, Vector *b);

Vector* copy_vector(Vector *old);
void free_vector(Vector*);

#endif /* !VECTOR_H */
