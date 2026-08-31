#ifndef USEFUL_METHODS_H
#define USEFUL_METHODS_H

#include <stddef.h>

float RandFloat(void);
float* RandFloatArray(size_t n);
int* RandIntPermutation(size_t n);
float* IntToFloatArray(int* a, size_t n);

#endif
