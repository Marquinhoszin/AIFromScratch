#include <stdlib.h>
//#include <time.h>
//#include <math.h>

/*
    Selection Methods
        IN:
            INT - Population size
            INT - Post selection population size
            FLOAT ARRAY - Population results
            INT FUNCTION POINTER (FLOAT, FLOAT) - Comparison function

        OUT:
            POPULATION ARRAY (MATRIX) - Selected population
*/

int* TournamentSelection ( int populationSize, int selectedAmount, float* resultsVector, int (*comparisonFunction)(float, float))
{
    int* selectedPopulation = malloc(sizeof(int)*selectedAmount);
    int fen1, fen2, result;
    int currentIndex = 0;
    
    while(currentIndex < selectedAmount)
    {
        fen1 = rand()%populationSize;
        do
        {
            fen2 = rand()%populationSize;
        } while (fen2 == fen1) ;

        result = comparisonFunction(resultsVector[fen1], resultsVector[fen2]);
        if (result == 1) selectedPopulation[currentIndex] = fen1;
        else selectedPopulation[currentIndex] = fen2;
        currentIndex++;
    }
    return selectedPopulation;
}
