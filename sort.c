#include <stdio.h>
#include "vector.h"

int main(int argc, const char *argv[])
{
    Vector a;
    a.length = 6;
    int aa[6] = {1, 2, 5, 23, 10, 4};
    a.value = aa;

    printVector(&a);
    
    return 0;
}
