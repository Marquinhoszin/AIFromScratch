#include <stdlib.h>

int** InitializeBinaryPopulation(int populationSize, int nIndividualParameters)
{
    int **population = malloc(populationSize * nIndividualParameters * sizeof(int));
    for (int i = 0; i < populationSize; i++)
    {
        for (int j = 0; j < nIndividualParameters; j++)
        {
            population[i][j] = rand()%2;
        }
    }
    return population;
}

int** InitializePermutationPopulation(int populationSize, int nIndividualParameters)
{
    int **population = malloc(populationSize * nIndividualParameters * sizeof(int));
    for (int i = 0; i < populationSize; i++)
    {
        for (int j = 0; j < nIndividualParameters; j++)
        {
            population[i][j] = j;
        }
        for (int j = nIndividualParameters; j > 0; j--)
        {
            int temp0 = rand()%j;
            int temp1 = rand();
            population[i][j] = j;
        }
    }
    return population;
}
float** InitializeRealPopulation(int populationSize, int nIndividualParameters)
{
    float **population = malloc(populationSize * nIndividualParameters * sizeof(int));
    for (int i = 0; i < populationSize; i++)
    {
        for (int j = 0; j < nIndividualParameters; j++)
        {
            population[i][j] = (float) (rand()-RAND_MAX/2)/RAND_MAX;
        }
    }
    return population;
}
