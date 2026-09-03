# This section of the Manual Implementation project has relation with academic activities

The original project was made in this GitHub repository: https://github.com/MarcosVinicius-UFABC/TSP
This segment is just a reimplementation with minor corrections and changes, specially the "tsp_limpo.ipynb"

It's purpose was to evaluate the implementation of variations for the solution of the TSP. It was made to start a discussions about the relevant factors for analysis within different implementations and their real utility.

The analysis made shows that brute and purely random approaches are somewhat functional before the number of cities start to go up and beyond small values due to the exponential solutions. But even so, genetic algorithms are more efficient to find answers even in those situations in less time.

Besides that, it was made a comparison between elitism and tournament selection methods. Due to the way that the functions were coded, it was given an edge to the elitism in the speed of the algorithm, since even the tournament selection was ordered by the result in the population_fitness function. As such, with due implementation, it might have different results.