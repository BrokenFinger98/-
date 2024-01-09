#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main(){
    int N,M;
    int i, j, k, a, b, c;
    int **p = NULL;

    scanf("%d %d", &N, &M);
    p = (int **)malloc(N*sizeof(int *));

    if(p == NULL){
        printf("Not enough memory!\n");
        return -1;
    }

    for(i = 0; i < N; ++i){
        p[i] = (int *)malloc(M*sizeof(int));

        if(p[i] == NULL){
        printf("Not enough memory!\n");
        return -1;
        }
    }
    
    i = 0, j = 0 ,k = 0;
    b = 1, c = 1;
    
    for(k = 0; k < M; ++k){
        for(i = 0, j = k; i < N && j >= 0; ++i, --j){
            p[i][j] = c;
            ++c;
        }
    }
    for(k = 1; k < N; ++k){
        for(i = k, j = M-1; i < N && j >= 0; ++i, --j){
            p[i][j] = c;
            ++c;
        }
    }
    
    for(i = 0; i < N; ++i){
        for(j = 0; j < M; ++j){
            printf(" %d", p[i][j]);
        }
        printf("\n");
    }    

    for(i = 0; i < N; ++i){
        free(p[i]);
    }
    free(p);
    
    return 0;
}
