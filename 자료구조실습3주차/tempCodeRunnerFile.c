#pragma warning(disable:4996)
#include <stdio.h>

int f(int a[], int N);

int main(){
    int N, i;
    int a[20];

    scanf("%d", &N);
    for(i = 0; i < N; ++i)
        scanf("%d", &a[i]);
    printf("%d\n", f(a,N-1));

    return 0;
}

int f(int a[], int N){
    if(N == 1){
        if(a[N]>a[N-1])
            return a[N];
        else
            return a[N-1];
    }
    else{
        if(a[N]>f(a,N-1))
            return a[N];
        else
            return f(a,N-1);
    }
}

