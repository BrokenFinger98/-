#pragma warning(disable:4996)
#include <stdio.h>

void f(int n);

int main(){
    int n;

    scanf("%d", &n);
    f(n);

    return 0;
}

void f(int n){
    if(n<10)
        printf("%d\n", n);
    else{
        f(n/10);
        printf("%d\n", n%10);
    }
}