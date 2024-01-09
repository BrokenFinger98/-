#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int *f(int *x, int a, int b);

int main(){
    int N, c, i, a, b;
    int *X = NULL;

    scanf("%d", &N);
    X = (int *)malloc(sizeof(int)*N);
    if(X == NULL){
        printf("Not enough memory\n");
        return -1;
    }
    for(i = 0; i < N; ++i)
        scanf("%d", &X[i]);

    scanf("%d", &c);
    for(i = 0; i < c; ++i){
        scanf("%d %d", &a, &b);
        f(X, a, b);
    }
    for(i = 0; i < N; ++i)
        printf(" %d", X[i]);
    free(X);        
        
    return 0;
}

int *f(int *x, int a, int b){
    int i = 0;
    int tmp;

    for(i=0;i<=(b-a)/2;++i){
        tmp = x[a+i];
        x[a+i] = x[b-i];
        x[b-i] = tmp;
    }

    return x;
}