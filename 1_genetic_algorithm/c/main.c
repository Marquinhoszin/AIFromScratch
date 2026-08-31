#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 5;

    int *vetor = malloc(n * sizeof(int));

    // Cria 1, 2, 3, 4, 5
    for (int i = 0; i < n; i++) {
        vetor[i] = i + 1;
    }

    srand(time(NULL));

    // Embaralha
    for (int i = n - 1; i > 0; i--)
    {
        for (int k = 0; k < n; k++)
        {
            printf("%d ", vetor[k]);
        }
        printf("\n");
        int j = rand() % (i + 1);

        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }

    // Mostra
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    free(vetor);

    return 0;
}
