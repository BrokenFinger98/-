#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

void f(int **p, int N, int M);

int main(){
    int N, M, i, j;
    int **p = NULL;

    scanf("%d %d", &N, &M);
    p = (int **)malloc(sizeof(int *)*N);
    if(p == NULL){
        printf("Not enough memory\n");
        return -1;
    }
    for(i = 0; i < N; ++i){
        p[i] = (int *)malloc(sizeof(int)*M);
        if(p[i] == NULL){
            printf("Not enough memory\n");
            return -1;    
        }
    }

    f(p, N, M);

    for(i = 0; i < N; ++i){
        for(j = 0; j < M; ++j)
            printf(" %d", p[i][j]);
        printf("\n");
    }

    for(i = 0; i < N; ++i)
        free(p[i]);
    free(p);
    
    return 0;
}

void f(int **p, int N, int M){
    int row = 0, col = -1, reverse = 1;
    int limit = 0;

    for (int count = 1; count <= N * M;) {
        for (int i = 0; i < M - limit; i++) {
            col += reverse;
            p[row][col] = count++;
        }
        for (int i = 0; i < N - limit - 1; i++) {
            row += reverse;
            p[row][col] = count++;
        }
        limit++;
        reverse = -reverse;
    }  
}

