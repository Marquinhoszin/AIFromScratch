#include <stddef.h>
#include <stdlib.h>

#include "UsefulMethods.h"

// Random float between 0 and 1

float RandFloat()
{
    return (float)rand()/(float)RAND_MAX;
}

float* RandFloatArray (size_t n)
{
    float* floatArray = malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) floatArray[i] = RandFloat();
    return floatArray;
}

int* RandIntPermutation (size_t n)
{
    int* permutation = malloc(n * sizeof(int));
    for (size_t i = 0; i < n; i++) permutation[i] = i;
    for (size_t i = n; i > 1; i--)
    {
        size_t r = rand()%i;
        int temp = permutation[r];
        permutation[r] = permutation[i];
        permutation[i] = temp;
    }
    return permutation;
}

float* IntToFloatArray(int* a, size_t n)
{
    float* f = malloc(n * sizeof *f);

    if (f == NULL)
        return NULL;

    for (size_t i = 0; i < n; i++)
        f[i] = (float)a[i];

    free(a);

    return f;
}

