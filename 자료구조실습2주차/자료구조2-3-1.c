#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int *prefixAverages1(int *p, int n);
int *prefixAverages2(int *p, int n);

int main(){
    int n, i;
    int *p = NULL;
    int *a, *b;

    scanf("%d", &n);
    p = (int *)malloc(sizeof(int)*n);
    if(p == NULL){
        printf("Not enough memory\n");
        return -1;
    }    
    for(i = 0 ; i < n; ++i){
        scanf("%d", p+i);
    }
    a = prefixAverages1(p, n);
    b = prefixAverages2(p, n);
    for(i = 0; i < n; ++i){
        printf("%d ", a[i]);
    }
    printf("\n");
    for(i = 0; i < n; ++i){
        printf("%d ", b[i]);
    }
    printf("\n");
    free(a);
    free(b);
    free(p);

    return 0;
}

int *prefixAverages1(int *p, int n){
    int i, j;
    double sum = 0;
    int *q = NULL;
    
    q = (int *)malloc(sizeof(int)*n);
    for(i = 0; i < n; ++i){
        sum = 0;
        for(j = 0; j <= i; ++j) 
            sum = sum + p[j];
        q[i] = (int)(sum/(i+1) + 0.5);
    }
    
    return q;
}

int *prefixAverages2(int *p, int n){
    int i;
    double sum = 0;
    int *q = NULL;
    
    q = (int *)malloc(sizeof(int)*n);
    for(i = 0; i < n; ++i){
        sum = sum + p[i];
        q[i] = (int)(sum/(i+1) + 0.5);
    }
    
    return q;
}