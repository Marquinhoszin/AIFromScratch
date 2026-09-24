#include <stdio.h>

#include "UsefulMethods.h"

int stepFunction(float n)
{
    return n >= 0 ? 1 : 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    float data[n+1];
    float weights[n+1];

    //Data and Weights Initialization

    for (int i=0; i<n; i++)
    {
        data[i] = RandFloat()-0.5;
        weights[i] = 0;
    }

    int yReal = 0;
    for (int i=0; i<n; i++)
    {
        yReal+=data[i]*i;
    }
    yReal = yReal >= 0 ? 1 : 0;

    //Bias

    data[n] = 1;
    weights[n] = RandFloat()-0.5;

    //Essential Variables
    float sum = 0, learningRate = 0.1;
    int epochs = 50;
    int yPred;

    //Feed Forwarding + Hebian Learning Loop

    for (int e=0; e<epochs; e++)
    {
        for (int i = 0; i < n+1; i++)
        {
            sum += data[i] * weights[i];
        }
        yPred = stepFunction(sum);
        for (int i=0; i<n+1; i++)
        {
            weights[i] += data[i] * (yReal-yPred) * learningRate;
        }

        printf("Epoch - %d || yPred - %d || yReal - %d || Sum - %.2f", e, yPred, yReal, sum);
    }
}
