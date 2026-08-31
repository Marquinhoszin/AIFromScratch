#ifndef SYNTHETIC_DATA_GENERATORS_H
#define SYNTHETIC_DATA_GENERATORS_H

#include <stddef.h>

typedef struct syntheticData
{
    size_t nSamples;
    size_t nDimensions;
    float* minValues;
    float* scaleRange;
    float* noiseRange;
    float* data;
} syntheticData;

syntheticData* GenerateSyntheticData(size_t nSamples, size_t nDimensions, float* minValues, float* scaleRange, float* noiseRange);
void FreeData (syntheticData* sd);
syntheticData* GenerateLinearData (size_t nSamples, size_t nDimensions, float* minValues, float* scaleRange, float* noiseRange);

#endif
