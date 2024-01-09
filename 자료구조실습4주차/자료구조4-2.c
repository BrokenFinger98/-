#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int *f(int *X, int c);

int main(){
    int *X;
    int N, a, b, c, i;

    scanf("%d", &N);
    X = (int *)malloc(sizeof(int)*N);
    if(X == NULL){
        printf("Not enough memory\n");
        return -1;
    }
    for(i = 0; i < N; ++i)
        scanf("%d", &X[i]);

    scanf("%d", &c);
    f(X,c);

    for(i=0;i<N;++i)
        printf(" %d", X[i]);
    printf("\n");

    return 0;
}

int *f(int *X, int c){
    int tmp1, tmp2;
    int i, a, b;

    for(i=0;i<c;++i){
        if(i == 0){
            scanf("%d", &a);
            tmp1 = X[a];
        }
        else{
            scanf("%d", &a);
            tmp2 = X[a];
            X[a] = tmp1;
            tmp1 = tmp2;
        }
    }
    return X;
}