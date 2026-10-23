#include <stdio.h>

#include "UsefulMethods.h"

int stepFunction(float n)
{
    return n >= 0 ? 1 : 0;
}

int main()
{
    int mSamples, nDimensions;
    printf("Type how many samples and how many dimensions for linear data generator, respectively.\n");
    scanf("%d%d", &mSamples, &nDimensions);
    float data[mSamples][nDimensions+1];
    float weights[nDimensions+1];
    float yReal[mSamples];

    //Data and Weights Initialization
    for (int k=0; k<mSamples; k++)
    {
        yReal[k] = 0;
        for (int i=0; i<nDimensions; i++)
        {
            data[k][i] = RandFloat()-0.5;
            yReal[k]+=data[k][i]*i;
        }
        yReal[k] = stepFunction(yReal[k]);
        data[k][nDimensions] = 1;
    }
    for (int i=0; i<nDimensions+1; i++)
    {
        weights[i] = 0;
    }

    //Essential Variables
    float sum = 0, learningRate = 0.1;
    int epochs = 50;
    int yPred[mSamples];

    //Feed Forwarding + Hebian Learning Loop

    for (int e=0; e<epochs; e++)
    {
        for (int k=0; k<mSamples; k++)
        {
            for (int i = 0; i < nDimensions+1; i++)
            {
                sum += data[k][i] * weights[i];
            }
            yPred[k] = stepFunction(sum);
            for (int i=0; i<nDimensions+1; i++)
            {
                weights[i] += data[k][i] * (yReal[k]-yPred[k]) * learningRate;
            }
        printf("Epoch - %d || yPred - %d || yReal - %f || Sum - %.2f\n", e, yPred[k], yReal[k], sum);
        }
    }

    printf("\nFinal Perceptron results:\n");
    for (int i=0; i<mSamples; i++)
    {
        printf("yReal = %f || yPred = %d\n", yReal[i], yPred[i]);
    }
}
