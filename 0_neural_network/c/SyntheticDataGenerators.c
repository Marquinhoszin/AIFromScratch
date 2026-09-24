#include <stdlib.h>
#include <stddef.h>

#include "SyntheticDataGenerators.h"
#include "UsefulMethods.h"

// Struct envelopment for the data (optional but may help to organize and access information later on)

/*typedef struct syntheticData
{
    size_t nSamples;
    size_t nDimensions;
    float* minValues;
    float* scaleRange;
    float* noiseRange;
    float* data;
} syntheticData;*/

/*
 *  Data Generators
 *      IN:
 *          SIZE_T - Samples amount
 *          SIZE_T - Samples dimensions
 *          FLOAT DYNAMIC ARRAY - Linear coeficient of each dimension
 *          FLOAT DYNAMIC ARRAY - Angular coeficient of each dimension
 *          FLOAT DYNAMIC ARRAY - Noise range of each dimension
 *
 *      OUT:
 *          ARRAY (N DIMENSIONAL MATRIX) - Synthetic data
 */

syntheticData* GenerateSyntheticData(size_t nSamples, size_t nDimensions, float* minValues, float* scaleRange, float* noiseRange)
{
    syntheticData* sd = malloc(sizeof(syntheticData));
    if (sd == NULL) return NULL;
    sd->nSamples = nSamples;
    sd->nDimensions = nDimensions;
    //sd->minValues = malloc(nDimensions * sizeof(float));
    sd->minValues = minValues;
    if (sd->minValues == NULL) return NULL;
    //sd->scaleRange = malloc(nDimensions * sizeof(float));
    sd->scaleRange = scaleRange;
    if (sd->scaleRange == NULL) return NULL;
    //sd->noiseRange = malloc(nDimensions * sizeof(float));
    sd->noiseRange = noiseRange;
    if (sd->noiseRange == NULL) return NULL;
    sd->data = malloc(nSamples * nDimensions * sizeof(float));
    if (sd->data == NULL) return NULL;
    return sd;
}

void FreeData (syntheticData* sd)
{
    free(sd->minValues);
    free(sd->scaleRange);
    free(sd->noiseRange);
    free(sd->data);
    free(sd);
}

syntheticData* GenerateLinearData (size_t nSamples, size_t nDimensions, float* minValues, float* scaleRange, float* noiseRange)
{
    syntheticData* linearData = GenerateSyntheticData(nSamples, nDimensions, minValues, scaleRange, noiseRange);

    for (int i = 0; i < nSamples; i++)
    {
        for (int j = 0; j < nDimensions; j++)
        {
            linearData->data[(nDimensions*i)+j] = minValues[j] + ((float)i / (float)nDimensions * (float)scaleRange[j]) + ((RandFloat()-0.5)*noiseRange[j]);
        }
    }
    return linearData;
}
