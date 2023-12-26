#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Alocando uma matriz dinamica
    
    vetor de vetores -> int* -> 10 37 43
                        int* -> 11 43 41
                        int* -> 22 44 23
                        int* -> 12 45 34
*/

int main(){
    int **mat, i, j;

    mat = malloc(4 * sizeof(int*));

    for(i = 0; i < 4; i++)
        mat[i] = malloc(3 * sizeof(int));

    srand(time(NULL));

    for(i = 0; i < 4; i++){
        for(j = 0; j < 3; j++)
            mat[i][j] = rand() % 100;
    }
    
    for(i = 0; i < 4; i++){
        for(j = 0; j < 3; j++)
           printf("%d ", mat[i][j]);
        printf("\n");
    }

    return 0;
}