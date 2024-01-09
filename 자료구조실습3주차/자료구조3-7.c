#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int count(char a[], char b, int n);
int cmp(char a, char b);

int main(){
    char a[101], b;

    gets(a);
    scanf("%c", &b);
    printf("%d\n", count(a,b,strlen(a)-1));

    return 0;
}

int count(char a[], char b, int n){
    if(n == 0)
        return cmp(a[n],b);
    else
        return cmp(a[n],b)+count(a,b,n-1);
}

int cmp(char a, char b){
    if(a == b)
        return 1;
    return 0;
}