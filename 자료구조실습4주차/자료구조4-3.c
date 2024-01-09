#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

void f(int **p, int N);

int main(){
    int N, i;
    int **p = NULL;

    scanf("%d", &N);
    p = (int **)malloc(sizeof(int *)*N);
    if(p == NULL){
        printf("Not enough memory\n");
        return -1;
    }
    for(i = 0; i < N; ++i){
        p[i] = (int *)malloc(sizeof(int)*N);
        if(p[i] == NULL){
            printf("Not enough memory\n");
            return -1;    
        }
    }
    f(p, N);

    return 0;
}

void f(int **p, int N){
    int i,j;

    for(i = 0; i < N; ++i){
        if(i % 2 == 0){
            for(j = 0; j < N; ++j)
                p[i][j] = i*N+j+1;
        }
        else{
            for(j = 0; j < N; ++j)
                p[i][j] = (i+1)*N-j;
        }
    }
    for(i = 0; i < N; ++i){
        for(j = 0; j < N; ++j)
            printf(" %d", p[i][j]);
        printf("\n");
    }
    
    for(i = 0; i < N; ++i)
        free(p[i]);
    free(p);
}