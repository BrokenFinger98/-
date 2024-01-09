#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int mostOnes(int **p, int n);

int main(){
    int n,i,j;
    int **p = NULL;

    scanf("%d", &n);
    p = (int **)malloc(sizeof(int *)*n); //2차원행렬 동적할당
    if(p == NULL){
        printf("Not enough memory\n");
        return -1;
    }

    for(i = 0; i < n; ++i){ //동적할당과 동시에  행렬의 값 저장
        p[i] = (int *)malloc(sizeof(int)*n);
        if(p[i] == NULL){
            printf("Not enough memory\n");
            return -1;
        }
        for(j = 0; j < n; ++j)
            scanf("%d", &p[i][j]);
    }
    printf("%d\n", mostOnes(p, n));

    for(i = 0; i < n; ++i)
        free(p[i]);
    free(p);

    return 0;
}

int mostOnes(int **p, int n){
    int i = 0, j = 0, row = 0;
    
    while (i < n && j < n)
    {
        if(p[i][j] == 0)
            ++i;
        else{
            row = i;
            ++j;
        }
    }
    return row;
}