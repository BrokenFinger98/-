#pragma warning(disable:4996)
#include <stdio.h>
void gcd(int a, int b);

int main(){
    int a,b;

    scanf("%d %d", &a, &b);
    a > b ? gcd(a,b) : gcd(b,a);

    return 0;
}

void gcd(int a, int b){
    if(b == 0)
        printf("%d\n", a);
    else
        return gcd(b, a%b);
}