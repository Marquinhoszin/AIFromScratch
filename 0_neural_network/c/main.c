#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "SyntheticDataGenerators.h"
#include "UsefulMethods.h"

int main()
{
    srand(time(NULL));

    int n;

    scanf("%d", &n);

    int* p1 = RandIntPermutation(n);
    int* p2 = RandIntPermutation(n);

    float* minValues = IntToFloatArray(p1, n);
    float* scaleRange = IntToFloatArray(p2, n);
    float* noiseRange = RandFloatArray(n);

    syntheticData* ld = GenerateLinearData(n,n,minValues,scaleRange,noiseRange);

    for (int i = 0; i < ld->nSamples * ld->nDimensions; i++) printf(i%ld->nDimensions == ld->nDimensions-1 ? "%f" "\n" : "%f - ", ld->data[i]);

    FreeData(ld);
    return 0;
}
