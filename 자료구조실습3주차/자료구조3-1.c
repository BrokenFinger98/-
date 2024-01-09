#pragma warning(disable:4996)
#include <stdio.h>

int f(int n);

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", f(n));
    return 0;
}

int f(int n){
    if(n == 1)
        return 1;
    else{
        return n+f(n-1);
    }
}